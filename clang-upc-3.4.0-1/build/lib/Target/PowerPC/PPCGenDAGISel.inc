/*===- TableGen'erated file -------------------------------------*- C++ -*-===*\
|*                                                                            *|
|*DAG Instruction Selector for the PPC target                                 *|
|*                                                                            *|
|* Automatically generated file, do not edit!                                 *|
|*                                                                            *|
\*===----------------------------------------------------------------------===*/

// *** NOTE: This file is #included into the middle of the target
// *** instruction selector class.  These functions are really methods.

// The main instruction selector code.
SDNode *SelectCode(SDNode *N) {
  // Some target values are emitted as 2 bytes, TARGET_VAL handles
  // this.
  #define TARGET_VAL(X) X & 255, unsigned(X) >> 8
  static const unsigned char MatcherTable[] = {
/*0*/     OPC_SwitchOpcode /*129 cases */, 33,  TARGET_VAL(ISD::PREFETCH),// ->37
/*4*/       OPC_RecordMemRef,
/*5*/       OPC_RecordNode,   // #0 = 'prefetch' chained node
/*6*/       OPC_RecordChild1, // #1 = $dst
/*7*/       OPC_MoveChild, 2,
/*9*/       OPC_CheckInteger, 0, 
/*11*/      OPC_CheckType, MVT::i32,
/*13*/      OPC_MoveParent,
/*14*/      OPC_MoveChild, 3,
/*16*/      OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*19*/      OPC_MoveParent,
/*20*/      OPC_MoveChild, 4,
/*22*/      OPC_CheckInteger, 1, 
/*24*/      OPC_MoveParent,
/*25*/      OPC_CheckComplexPat, /*CP*/0, /*#*/1, // SelectAddrIdxOnly:$dst #2 #3
/*28*/      OPC_EmitMergeInputChains1_0,
/*29*/      OPC_MorphNodeTo, TARGET_VAL(PPC::DCBT), 0|OPFL_Chain|OPFL_MemRefs,
                0/*#VTs*/, 2/*#Ops*/, 2, 3, 
            // Src: (prefetch xoaddr:iPTR:$dst, 0:i32, (imm:i32), 1:i32) - Complexity = 25
            // Dst: (DCBT xoaddr:iPTR:$dst)
/*37*/    /*SwitchOpcode*/ 13|128,5/*653*/,  TARGET_VAL(ISD::INTRINSIC_VOID),// ->694
/*41*/      OPC_RecordNode,   // #0 = 'intrinsic_void' chained node
/*42*/      OPC_MoveChild, 1,
/*44*/      OPC_Scope, 17, /*->63*/ // 22 children in Scope
/*46*/        OPC_CheckInteger, 2|128,18/*2306*/, 
/*49*/        OPC_MoveParent,
/*50*/        OPC_RecordChild2, // #1 = $dst
/*51*/        OPC_CheckComplexPat, /*CP*/0, /*#*/1, // SelectAddrIdxOnly:$dst #2 #3
/*54*/        OPC_EmitMergeInputChains1_0,
/*55*/        OPC_MorphNodeTo, TARGET_VAL(PPC::DCBA), 0|OPFL_Chain,
                  0/*#VTs*/, 2/*#Ops*/, 2, 3, 
              // Src: (intrinsic_void 2306:iPTR, xoaddr:iPTR:$dst) - Complexity = 17
              // Dst: (DCBA xoaddr:iPTR:$dst)
/*63*/      /*Scope*/ 17, /*->81*/
/*64*/        OPC_CheckInteger, 3|128,18/*2307*/, 
/*67*/        OPC_MoveParent,
/*68*/        OPC_RecordChild2, // #1 = $dst
/*69*/        OPC_CheckComplexPat, /*CP*/0, /*#*/1, // SelectAddrIdxOnly:$dst #2 #3
/*72*/        OPC_EmitMergeInputChains1_0,
/*73*/        OPC_MorphNodeTo, TARGET_VAL(PPC::DCBF), 0|OPFL_Chain,
                  0/*#VTs*/, 2/*#Ops*/, 2, 3, 
              // Src: (intrinsic_void 2307:iPTR, xoaddr:iPTR:$dst) - Complexity = 17
              // Dst: (DCBF xoaddr:iPTR:$dst)
/*81*/      /*Scope*/ 17, /*->99*/
/*82*/        OPC_CheckInteger, 4|128,18/*2308*/, 
/*85*/        OPC_MoveParent,
/*86*/        OPC_RecordChild2, // #1 = $dst
/*87*/        OPC_CheckComplexPat, /*CP*/0, /*#*/1, // SelectAddrIdxOnly:$dst #2 #3
/*90*/        OPC_EmitMergeInputChains1_0,
/*91*/        OPC_MorphNodeTo, TARGET_VAL(PPC::DCBI), 0|OPFL_Chain,
                  0/*#VTs*/, 2/*#Ops*/, 2, 3, 
              // Src: (intrinsic_void 2308:iPTR, xoaddr:iPTR:$dst) - Complexity = 17
              // Dst: (DCBI xoaddr:iPTR:$dst)
/*99*/      /*Scope*/ 17, /*->117*/
/*100*/       OPC_CheckInteger, 5|128,18/*2309*/, 
/*103*/       OPC_MoveParent,
/*104*/       OPC_RecordChild2, // #1 = $dst
/*105*/       OPC_CheckComplexPat, /*CP*/0, /*#*/1, // SelectAddrIdxOnly:$dst #2 #3
/*108*/       OPC_EmitMergeInputChains1_0,
/*109*/       OPC_MorphNodeTo, TARGET_VAL(PPC::DCBST), 0|OPFL_Chain,
                  0/*#VTs*/, 2/*#Ops*/, 2, 3, 
              // Src: (intrinsic_void 2309:iPTR, xoaddr:iPTR:$dst) - Complexity = 17
              // Dst: (DCBST xoaddr:iPTR:$dst)
/*117*/     /*Scope*/ 17, /*->135*/
/*118*/       OPC_CheckInteger, 6|128,18/*2310*/, 
/*121*/       OPC_MoveParent,
/*122*/       OPC_RecordChild2, // #1 = $dst
/*123*/       OPC_CheckComplexPat, /*CP*/0, /*#*/1, // SelectAddrIdxOnly:$dst #2 #3
/*126*/       OPC_EmitMergeInputChains1_0,
/*127*/       OPC_MorphNodeTo, TARGET_VAL(PPC::DCBT), 0|OPFL_Chain,
                  0/*#VTs*/, 2/*#Ops*/, 2, 3, 
              // Src: (intrinsic_void 2310:iPTR, xoaddr:iPTR:$dst) - Complexity = 17
              // Dst: (DCBT xoaddr:iPTR:$dst)
/*135*/     /*Scope*/ 17, /*->153*/
/*136*/       OPC_CheckInteger, 7|128,18/*2311*/, 
/*139*/       OPC_MoveParent,
/*140*/       OPC_RecordChild2, // #1 = $dst
/*141*/       OPC_CheckComplexPat, /*CP*/0, /*#*/1, // SelectAddrIdxOnly:$dst #2 #3
/*144*/       OPC_EmitMergeInputChains1_0,
/*145*/       OPC_MorphNodeTo, TARGET_VAL(PPC::DCBTST), 0|OPFL_Chain,
                  0/*#VTs*/, 2/*#Ops*/, 2, 3, 
              // Src: (intrinsic_void 2311:iPTR, xoaddr:iPTR:$dst) - Complexity = 17
              // Dst: (DCBTST xoaddr:iPTR:$dst)
/*153*/     /*Scope*/ 17, /*->171*/
/*154*/       OPC_CheckInteger, 8|128,18/*2312*/, 
/*157*/       OPC_MoveParent,
/*158*/       OPC_RecordChild2, // #1 = $dst
/*159*/       OPC_CheckComplexPat, /*CP*/0, /*#*/1, // SelectAddrIdxOnly:$dst #2 #3
/*162*/       OPC_EmitMergeInputChains1_0,
/*163*/       OPC_MorphNodeTo, TARGET_VAL(PPC::DCBZ), 0|OPFL_Chain,
                  0/*#VTs*/, 2/*#Ops*/, 2, 3, 
              // Src: (intrinsic_void 2312:iPTR, xoaddr:iPTR:$dst) - Complexity = 17
              // Dst: (DCBZ xoaddr:iPTR:$dst)
/*171*/     /*Scope*/ 17, /*->189*/
/*172*/       OPC_CheckInteger, 9|128,18/*2313*/, 
/*175*/       OPC_MoveParent,
/*176*/       OPC_RecordChild2, // #1 = $dst
/*177*/       OPC_CheckComplexPat, /*CP*/0, /*#*/1, // SelectAddrIdxOnly:$dst #2 #3
/*180*/       OPC_EmitMergeInputChains1_0,
/*181*/       OPC_MorphNodeTo, TARGET_VAL(PPC::DCBZL), 0|OPFL_Chain,
                  0/*#VTs*/, 2/*#Ops*/, 2, 3, 
              // Src: (intrinsic_void 2313:iPTR, xoaddr:iPTR:$dst) - Complexity = 17
              // Dst: (DCBZL xoaddr:iPTR:$dst)
/*189*/     /*Scope*/ 21, /*->211*/
/*190*/       OPC_CheckInteger, 126|128,16/*2174*/, 
/*193*/       OPC_MoveParent,
/*194*/       OPC_RecordChild2, // #1 = $rS
/*195*/       OPC_RecordChild3, // #2 = $dst
/*196*/       OPC_CheckPatternPredicate, 0, // (PPCSubTarget.hasAltivec())
/*198*/       OPC_CheckComplexPat, /*CP*/0, /*#*/2, // SelectAddrIdxOnly:$dst #3 #4
/*201*/       OPC_EmitMergeInputChains1_0,
/*202*/       OPC_MorphNodeTo, TARGET_VAL(PPC::STVEBX), 0|OPFL_Chain,
                  0/*#VTs*/, 3/*#Ops*/, 1, 3, 4, 
              // Src: (intrinsic_void 2174:iPTR, v16i8:v16i8:$rS, xoaddr:iPTR:$dst) - Complexity = 17
              // Dst: (STVEBX v16i8:v16i8:$rS, xoaddr:iPTR:$dst)
/*211*/     /*Scope*/ 21, /*->233*/
/*212*/       OPC_CheckInteger, 127|128,16/*2175*/, 
/*215*/       OPC_MoveParent,
/*216*/       OPC_RecordChild2, // #1 = $rS
/*217*/       OPC_RecordChild3, // #2 = $dst
/*218*/       OPC_CheckPatternPredicate, 0, // (PPCSubTarget.hasAltivec())
/*220*/       OPC_CheckComplexPat, /*CP*/0, /*#*/2, // SelectAddrIdxOnly:$dst #3 #4
/*223*/       OPC_EmitMergeInputChains1_0,
/*224*/       OPC_MorphNodeTo, TARGET_VAL(PPC::STVEHX), 0|OPFL_Chain,
                  0/*#VTs*/, 3/*#Ops*/, 1, 3, 4, 
              // Src: (intrinsic_void 2175:iPTR, v8i16:v8i16:$rS, xoaddr:iPTR:$dst) - Complexity = 17
              // Dst: (STVEHX v8i16:v8i16:$rS, xoaddr:iPTR:$dst)
/*233*/     /*Scope*/ 21, /*->255*/
/*234*/       OPC_CheckInteger, 0|128,17/*2176*/, 
/*237*/       OPC_MoveParent,
/*238*/       OPC_RecordChild2, // #1 = $rS
/*239*/       OPC_RecordChild3, // #2 = $dst
/*240*/       OPC_CheckPatternPredicate, 0, // (PPCSubTarget.hasAltivec())
/*242*/       OPC_CheckComplexPat, /*CP*/0, /*#*/2, // SelectAddrIdxOnly:$dst #3 #4
/*245*/       OPC_EmitMergeInputChains1_0,
/*246*/       OPC_MorphNodeTo, TARGET_VAL(PPC::STVEWX), 0|OPFL_Chain,
                  0/*#VTs*/, 3/*#Ops*/, 1, 3, 4, 
              // Src: (intrinsic_void 2176:iPTR, v4i32:v4i32:$rS, xoaddr:iPTR:$dst) - Complexity = 17
              // Dst: (STVEWX v4i32:v4i32:$rS, xoaddr:iPTR:$dst)
/*255*/     /*Scope*/ 21, /*->277*/
/*256*/       OPC_CheckInteger, 1|128,17/*2177*/, 
/*259*/       OPC_MoveParent,
/*260*/       OPC_RecordChild2, // #1 = $rS
/*261*/       OPC_RecordChild3, // #2 = $dst
/*262*/       OPC_CheckPatternPredicate, 0, // (PPCSubTarget.hasAltivec())
/*264*/       OPC_CheckComplexPat, /*CP*/0, /*#*/2, // SelectAddrIdxOnly:$dst #3 #4
/*267*/       OPC_EmitMergeInputChains1_0,
/*268*/       OPC_MorphNodeTo, TARGET_VAL(PPC::STVX), 0|OPFL_Chain,
                  0/*#VTs*/, 3/*#Ops*/, 1, 3, 4, 
              // Src: (intrinsic_void 2177:iPTR, v4i32:v4i32:$rS, xoaddr:iPTR:$dst) - Complexity = 17
              // Dst: (STVX v4i32:v4i32:$rS, xoaddr:iPTR:$dst)
/*277*/     /*Scope*/ 21, /*->299*/
/*278*/       OPC_CheckInteger, 2|128,17/*2178*/, 
/*281*/       OPC_MoveParent,
/*282*/       OPC_RecordChild2, // #1 = $rS
/*283*/       OPC_RecordChild3, // #2 = $dst
/*284*/       OPC_CheckPatternPredicate, 0, // (PPCSubTarget.hasAltivec())
/*286*/       OPC_CheckComplexPat, /*CP*/0, /*#*/2, // SelectAddrIdxOnly:$dst #3 #4
/*289*/       OPC_EmitMergeInputChains1_0,
/*290*/       OPC_MorphNodeTo, TARGET_VAL(PPC::STVXL), 0|OPFL_Chain,
                  0/*#VTs*/, 3/*#Ops*/, 1, 3, 4, 
              // Src: (intrinsic_void 2178:iPTR, v4i32:v4i32:$rS, xoaddr:iPTR:$dst) - Complexity = 17
              // Dst: (STVXL v4i32:v4i32:$rS, xoaddr:iPTR:$dst)
/*299*/     /*Scope*/ 35, /*->335*/
/*300*/       OPC_CheckInteger, 111|128,16/*2159*/, 
/*303*/       OPC_MoveParent,
/*304*/       OPC_RecordChild2, // #1 = $STRM
/*305*/       OPC_MoveChild, 2,
/*307*/       OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*310*/       OPC_MoveParent,
/*311*/       OPC_CheckPatternPredicate, 0, // (PPCSubTarget.hasAltivec())
/*313*/       OPC_EmitMergeInputChains1_0,
/*314*/       OPC_EmitInteger, MVT::i32, 0, 
/*317*/       OPC_EmitConvertToTarget, 1,
/*319*/       OPC_EmitInteger, MVT::i32, 0, 
/*322*/       OPC_EmitInteger, MVT::i32, 0, 
/*325*/       OPC_MorphNodeTo, TARGET_VAL(PPC::DSS), 0|OPFL_Chain,
                  0/*#VTs*/, 4/*#Ops*/, 2, 3, 4, 5, 
              // Src: (intrinsic_void 2159:iPTR, (imm:i32):$STRM) - Complexity = 11
              // Dst: (DSS 0:i32, (imm:i32):$STRM, 0:i32, 0:i32)
/*335*/     /*Scope*/ 65, /*->401*/
/*336*/       OPC_CheckInteger, 113|128,16/*2161*/, 
/*339*/       OPC_MoveParent,
/*340*/       OPC_RecordChild2, // #1 = $rA
/*341*/       OPC_Scope, 28, /*->371*/ // 2 children in Scope
/*343*/         OPC_CheckChild2Type, MVT::i32,
/*345*/         OPC_RecordChild3, // #2 = $rB
/*346*/         OPC_RecordChild4, // #3 = $STRM
/*347*/         OPC_MoveChild, 4,
/*349*/         OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*352*/         OPC_MoveParent,
/*353*/         OPC_CheckPatternPredicate, 0, // (PPCSubTarget.hasAltivec())
/*355*/         OPC_EmitMergeInputChains1_0,
/*356*/         OPC_EmitInteger, MVT::i32, 0, 
/*359*/         OPC_EmitConvertToTarget, 3,
/*361*/         OPC_MorphNodeTo, TARGET_VAL(PPC::DST), 0|OPFL_Chain,
                    0/*#VTs*/, 4/*#Ops*/, 4, 5, 1, 2, 
                // Src: (intrinsic_void 2161:iPTR, i32:i32:$rA, i32:i32:$rB, (imm:i32):$STRM) - Complexity = 11
                // Dst: (DST 0:i32, (imm:i32):$STRM, ?:i32:$rA, ?:i32:$rB)
/*371*/       /*Scope*/ 28, /*->400*/
/*372*/         OPC_CheckChild2Type, MVT::i64,
/*374*/         OPC_RecordChild3, // #2 = $rB
/*375*/         OPC_RecordChild4, // #3 = $STRM
/*376*/         OPC_MoveChild, 4,
/*378*/         OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*381*/         OPC_MoveParent,
/*382*/         OPC_CheckPatternPredicate, 0, // (PPCSubTarget.hasAltivec())
/*384*/         OPC_EmitMergeInputChains1_0,
/*385*/         OPC_EmitInteger, MVT::i32, 0, 
/*388*/         OPC_EmitConvertToTarget, 3,
/*390*/         OPC_MorphNodeTo, TARGET_VAL(PPC::DST64), 0|OPFL_Chain,
                    0/*#VTs*/, 4/*#Ops*/, 4, 5, 1, 2, 
                // Src: (intrinsic_void 2161:iPTR, i64:i64:$rA, i32:i32:$rB, (imm:i32):$STRM) - Complexity = 11
                // Dst: (DST64 0:i32, (imm:i32):$STRM, ?:i64:$rA, ?:i32:$rB)
/*400*/       0, /*End of Scope*/
/*401*/     /*Scope*/ 65, /*->467*/
/*402*/       OPC_CheckInteger, 116|128,16/*2164*/, 
/*405*/       OPC_MoveParent,
/*406*/       OPC_RecordChild2, // #1 = $rA
/*407*/       OPC_Scope, 28, /*->437*/ // 2 children in Scope
/*409*/         OPC_CheckChild2Type, MVT::i32,
/*411*/         OPC_RecordChild3, // #2 = $rB
/*412*/         OPC_RecordChild4, // #3 = $STRM
/*413*/         OPC_MoveChild, 4,
/*415*/         OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*418*/         OPC_MoveParent,
/*419*/         OPC_CheckPatternPredicate, 0, // (PPCSubTarget.hasAltivec())
/*421*/         OPC_EmitMergeInputChains1_0,
/*422*/         OPC_EmitInteger, MVT::i32, 1, 
/*425*/         OPC_EmitConvertToTarget, 3,
/*427*/         OPC_MorphNodeTo, TARGET_VAL(PPC::DSTT), 0|OPFL_Chain,
                    0/*#VTs*/, 4/*#Ops*/, 4, 5, 1, 2, 
                // Src: (intrinsic_void 2164:iPTR, i32:i32:$rA, i32:i32:$rB, (imm:i32):$STRM) - Complexity = 11
                // Dst: (DSTT 1:i32, (imm:i32):$STRM, ?:i32:$rA, ?:i32:$rB)
/*437*/       /*Scope*/ 28, /*->466*/
/*438*/         OPC_CheckChild2Type, MVT::i64,
/*440*/         OPC_RecordChild3, // #2 = $rB
/*441*/         OPC_RecordChild4, // #3 = $STRM
/*442*/         OPC_MoveChild, 4,
/*444*/         OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*447*/         OPC_MoveParent,
/*448*/         OPC_CheckPatternPredicate, 0, // (PPCSubTarget.hasAltivec())
/*450*/         OPC_EmitMergeInputChains1_0,
/*451*/         OPC_EmitInteger, MVT::i32, 1, 
/*454*/         OPC_EmitConvertToTarget, 3,
/*456*/         OPC_MorphNodeTo, TARGET_VAL(PPC::DSTT64), 0|OPFL_Chain,
                    0/*#VTs*/, 4/*#Ops*/, 4, 5, 1, 2, 
                // Src: (intrinsic_void 2164:iPTR, i64:i64:$rA, i32:i32:$rB, (imm:i32):$STRM) - Complexity = 11
                // Dst: (DSTT64 1:i32, (imm:i32):$STRM, ?:i64:$rA, ?:i32:$rB)
/*466*/       0, /*End of Scope*/
/*467*/     /*Scope*/ 65, /*->533*/
/*468*/       OPC_CheckInteger, 114|128,16/*2162*/, 
/*471*/       OPC_MoveParent,
/*472*/       OPC_RecordChild2, // #1 = $rA
/*473*/       OPC_Scope, 28, /*->503*/ // 2 children in Scope
/*475*/         OPC_CheckChild2Type, MVT::i32,
/*477*/         OPC_RecordChild3, // #2 = $rB
/*478*/         OPC_RecordChild4, // #3 = $STRM
/*479*/         OPC_MoveChild, 4,
/*481*/         OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*484*/         OPC_MoveParent,
/*485*/         OPC_CheckPatternPredicate, 0, // (PPCSubTarget.hasAltivec())
/*487*/         OPC_EmitMergeInputChains1_0,
/*488*/         OPC_EmitInteger, MVT::i32, 0, 
/*491*/         OPC_EmitConvertToTarget, 3,
/*493*/         OPC_MorphNodeTo, TARGET_VAL(PPC::DSTST), 0|OPFL_Chain,
                    0/*#VTs*/, 4/*#Ops*/, 4, 5, 1, 2, 
                // Src: (intrinsic_void 2162:iPTR, i32:i32:$rA, i32:i32:$rB, (imm:i32):$STRM) - Complexity = 11
                // Dst: (DSTST 0:i32, (imm:i32):$STRM, ?:i32:$rA, ?:i32:$rB)
/*503*/       /*Scope*/ 28, /*->532*/
/*504*/         OPC_CheckChild2Type, MVT::i64,
/*506*/         OPC_RecordChild3, // #2 = $rB
/*507*/         OPC_RecordChild4, // #3 = $STRM
/*508*/         OPC_MoveChild, 4,
/*510*/         OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*513*/         OPC_MoveParent,
/*514*/         OPC_CheckPatternPredicate, 0, // (PPCSubTarget.hasAltivec())
/*516*/         OPC_EmitMergeInputChains1_0,
/*517*/         OPC_EmitInteger, MVT::i32, 0, 
/*520*/         OPC_EmitConvertToTarget, 3,
/*522*/         OPC_MorphNodeTo, TARGET_VAL(PPC::DSTST64), 0|OPFL_Chain,
                    0/*#VTs*/, 4/*#Ops*/, 4, 5, 1, 2, 
                // Src: (intrinsic_void 2162:iPTR, i64:i64:$rA, i32:i32:$rB, (imm:i32):$STRM) - Complexity = 11
                // Dst: (DSTST64 0:i32, (imm:i32):$STRM, ?:i64:$rA, ?:i32:$rB)
/*532*/       0, /*End of Scope*/
/*533*/     /*Scope*/ 65, /*->599*/
/*534*/       OPC_CheckInteger, 115|128,16/*2163*/, 
/*537*/       OPC_MoveParent,
/*538*/       OPC_RecordChild2, // #1 = $rA
/*539*/       OPC_Scope, 28, /*->569*/ // 2 children in Scope
/*541*/         OPC_CheckChild2Type, MVT::i32,
/*543*/         OPC_RecordChild3, // #2 = $rB
/*544*/         OPC_RecordChild4, // #3 = $STRM
/*545*/         OPC_MoveChild, 4,
/*547*/         OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*550*/         OPC_MoveParent,
/*551*/         OPC_CheckPatternPredicate, 0, // (PPCSubTarget.hasAltivec())
/*553*/         OPC_EmitMergeInputChains1_0,
/*554*/         OPC_EmitInteger, MVT::i32, 1, 
/*557*/         OPC_EmitConvertToTarget, 3,
/*559*/         OPC_MorphNodeTo, TARGET_VAL(PPC::DSTSTT), 0|OPFL_Chain,
                    0/*#VTs*/, 4/*#Ops*/, 4, 5, 1, 2, 
                // Src: (intrinsic_void 2163:iPTR, i32:i32:$rA, i32:i32:$rB, (imm:i32):$STRM) - Complexity = 11
                // Dst: (DSTSTT 1:i32, (imm:i32):$STRM, ?:i32:$rA, ?:i32:$rB)
/*569*/       /*Scope*/ 28, /*->598*/
/*570*/         OPC_CheckChild2Type, MVT::i64,
/*572*/         OPC_RecordChild3, // #2 = $rB
/*573*/         OPC_RecordChild4, // #3 = $STRM
/*574*/         OPC_MoveChild, 4,
/*576*/         OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*579*/         OPC_MoveParent,
/*580*/         OPC_CheckPatternPredicate, 0, // (PPCSubTarget.hasAltivec())
/*582*/         OPC_EmitMergeInputChains1_0,
/*583*/         OPC_EmitInteger, MVT::i32, 1, 
/*586*/         OPC_EmitConvertToTarget, 3,
/*588*/         OPC_MorphNodeTo, TARGET_VAL(PPC::DSTSTT64), 0|OPFL_Chain,
                    0/*#VTs*/, 4/*#Ops*/, 4, 5, 1, 2, 
                // Src: (intrinsic_void 2163:iPTR, i64:i64:$rA, i32:i32:$rB, (imm:i32):$STRM) - Complexity = 11
                // Dst: (DSTSTT64 1:i32, (imm:i32):$STRM, ?:i64:$rA, ?:i32:$rB)
/*598*/       0, /*End of Scope*/
/*599*/     /*Scope*/ 15, /*->615*/
/*600*/       OPC_CheckInteger, 12|128,18/*2316*/, 
/*603*/       OPC_MoveParent,
/*604*/       OPC_EmitMergeInputChains1_0,
/*605*/       OPC_EmitInteger, MVT::i32, 0, 
/*608*/       OPC_MorphNodeTo, TARGET_VAL(PPC::SYNC), 0|OPFL_Chain,
                  0/*#VTs*/, 1/*#Ops*/, 1, 
              // Src: (intrinsic_void 2316:iPTR) - Complexity = 8
              // Dst: (SYNC 0:i32)
/*615*/     /*Scope*/ 31, /*->647*/
/*616*/       OPC_CheckInteger, 11|128,18/*2315*/, 
/*619*/       OPC_MoveParent,
/*620*/       OPC_RecordChild2, // #1 = $rS
/*621*/       OPC_Scope, 11, /*->634*/ // 2 children in Scope
/*623*/         OPC_CheckChild2Type, MVT::i32,
/*625*/         OPC_EmitMergeInputChains1_0,
/*626*/         OPC_MorphNodeTo, TARGET_VAL(PPC::MTCTRloop), 0|OPFL_Chain,
                    1/*#VTs*/, MVT::i32, 1/*#Ops*/, 1, 
                // Src: (intrinsic_void 2315:iPTR, i32:i32:$rS) - Complexity = 8
                // Dst: (MTCTRloop:i32 i32:i32:$rS)
/*634*/       /*Scope*/ 11, /*->646*/
/*635*/         OPC_CheckChild2Type, MVT::i64,
/*637*/         OPC_EmitMergeInputChains1_0,
/*638*/         OPC_MorphNodeTo, TARGET_VAL(PPC::MTCTR8loop), 0|OPFL_Chain,
                    1/*#VTs*/, MVT::i64, 1/*#Ops*/, 1, 
                // Src: (intrinsic_void 2315:iPTR, i64:i64:$rS) - Complexity = 8
                // Dst: (MTCTR8loop:i64 i64:i64:$rS)
/*646*/       0, /*End of Scope*/
/*647*/     /*Scope*/ 15, /*->663*/
/*648*/       OPC_CheckInteger, 125|128,16/*2173*/, 
/*651*/       OPC_MoveParent,
/*652*/       OPC_RecordChild2, // #1 = $vB
/*653*/       OPC_CheckPatternPredicate, 0, // (PPCSubTarget.hasAltivec())
/*655*/       OPC_EmitMergeInputChains1_0,
/*656*/       OPC_MorphNodeTo, TARGET_VAL(PPC::MTVSCR), 0|OPFL_Chain,
                  0/*#VTs*/, 1/*#Ops*/, 1, 
              // Src: (intrinsic_void 2173:iPTR, v4i32:v4i32:$vB) - Complexity = 8
              // Dst: (MTVSCR v4i32:v4i32:$vB)
/*663*/     /*Scope*/ 29, /*->693*/
/*664*/       OPC_CheckInteger, 112|128,16/*2160*/, 
/*667*/       OPC_MoveParent,
/*668*/       OPC_CheckPatternPredicate, 0, // (PPCSubTarget.hasAltivec())
/*670*/       OPC_EmitMergeInputChains1_0,
/*671*/       OPC_EmitInteger, MVT::i32, 1, 
/*674*/       OPC_EmitInteger, MVT::i32, 0, 
/*677*/       OPC_EmitInteger, MVT::i32, 0, 
/*680*/       OPC_EmitInteger, MVT::i32, 0, 
/*683*/       OPC_MorphNodeTo, TARGET_VAL(PPC::DSSALL), 0|OPFL_Chain,
                  0/*#VTs*/, 4/*#Ops*/, 1, 2, 3, 4, 
              // Src: (intrinsic_void 2160:iPTR) - Complexity = 8
              // Dst: (DSSALL 1:i32, 0:i32, 0:i32, 0:i32)
/*693*/     0, /*End of Scope*/
/*694*/   /*SwitchOpcode*/ 83|128,4/*595*/,  TARGET_VAL(ISD::ADD),// ->1293
/*698*/     OPC_Scope, 49|128,1/*177*/, /*->878*/ // 3 children in Scope
/*701*/       OPC_RecordChild0, // #0 = $rA
/*702*/       OPC_MoveChild, 1,
/*704*/       OPC_SwitchOpcode /*2 cases */, 24,  TARGET_VAL(PPCISD::Lo),// ->732
/*708*/         OPC_RecordChild0, // #1 = $sym
/*709*/         OPC_MoveChild, 0,
/*711*/         OPC_CheckOpcode, TARGET_VAL(ISD::TargetGlobalAddress),
/*714*/         OPC_MoveParent,
/*715*/         OPC_MoveChild, 1,
/*717*/         OPC_CheckInteger, 0, 
/*719*/         OPC_MoveParent,
/*720*/         OPC_MoveParent,
/*721*/         OPC_CheckType, MVT::i32,
/*723*/         OPC_MorphNodeTo, TARGET_VAL(PPC::LA), 0,
                    1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1, 
                // Src: (add:i32 i32:i32:$rA, (PPClo:i32 (tglobaladdr:i32):$sym, 0:i32)) - Complexity = 14
                // Dst: (LA:i32 i32:i32:$rA, (tglobaladdr:i32):$sym)
/*732*/       /*SwitchOpcode*/ 13|128,1/*141*/,  TARGET_VAL(PPCISD::Hi),// ->877
/*736*/         OPC_RecordChild0, // #1 = $g
/*737*/         OPC_MoveChild, 0,
/*739*/         OPC_SwitchOpcode /*4 cases */, 31,  TARGET_VAL(ISD::TargetGlobalAddress),// ->774
/*743*/           OPC_MoveParent,
/*744*/           OPC_MoveChild, 1,
/*746*/           OPC_CheckInteger, 0, 
/*748*/           OPC_MoveParent,
/*749*/           OPC_MoveParent,
/*750*/           OPC_SwitchType /*2 cases */, 9,  MVT::i32,// ->762
/*753*/             OPC_MorphNodeTo, TARGET_VAL(PPC::ADDIS), 0,
                        1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1, 
                    // Src: (add:i32 i32:i32:$in, (PPChi:i32 (tglobaladdr:i32):$g, 0:i32)) - Complexity = 14
                    // Dst: (ADDIS:i32 ?:i32:$in, (tglobaladdr:i32):$g)
/*762*/           /*SwitchType*/ 9,  MVT::i64,// ->773
/*764*/             OPC_MorphNodeTo, TARGET_VAL(PPC::ADDIS8), 0,
                        1/*#VTs*/, MVT::i64, 2/*#Ops*/, 0, 1, 
                    // Src: (add:i64 i64:i64:$in, (PPChi:i64 (tglobaladdr:i64):$g, 0:i64)) - Complexity = 14
                    // Dst: (ADDIS8:i64 ?:i64:$in, (tglobaladdr:i64):$g)
/*773*/           0, // EndSwitchType
/*774*/         /*SwitchOpcode*/ 31,  TARGET_VAL(ISD::TargetConstantPool),// ->808
/*777*/           OPC_MoveParent,
/*778*/           OPC_MoveChild, 1,
/*780*/           OPC_CheckInteger, 0, 
/*782*/           OPC_MoveParent,
/*783*/           OPC_MoveParent,
/*784*/           OPC_SwitchType /*2 cases */, 9,  MVT::i32,// ->796
/*787*/             OPC_MorphNodeTo, TARGET_VAL(PPC::ADDIS), 0,
                        1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1, 
                    // Src: (add:i32 i32:i32:$in, (PPChi:i32 (tconstpool:i32):$g, 0:i32)) - Complexity = 14
                    // Dst: (ADDIS:i32 ?:i32:$in, (tconstpool:i32):$g)
/*796*/           /*SwitchType*/ 9,  MVT::i64,// ->807
/*798*/             OPC_MorphNodeTo, TARGET_VAL(PPC::ADDIS8), 0,
                        1/*#VTs*/, MVT::i64, 2/*#Ops*/, 0, 1, 
                    // Src: (add:i64 i64:i64:$in, (PPChi:i64 (tconstpool:i64):$g, 0:i64)) - Complexity = 14
                    // Dst: (ADDIS8:i64 ?:i64:$in, (tconstpool:i64):$g)
/*807*/           0, // EndSwitchType
/*808*/         /*SwitchOpcode*/ 31,  TARGET_VAL(ISD::TargetJumpTable),// ->842
/*811*/           OPC_MoveParent,
/*812*/           OPC_MoveChild, 1,
/*814*/           OPC_CheckInteger, 0, 
/*816*/           OPC_MoveParent,
/*817*/           OPC_MoveParent,
/*818*/           OPC_SwitchType /*2 cases */, 9,  MVT::i32,// ->830
/*821*/             OPC_MorphNodeTo, TARGET_VAL(PPC::ADDIS), 0,
                        1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1, 
                    // Src: (add:i32 i32:i32:$in, (PPChi:i32 (tjumptable:i32):$g, 0:i32)) - Complexity = 14
                    // Dst: (ADDIS:i32 ?:i32:$in, (tjumptable:i32):$g)
/*830*/           /*SwitchType*/ 9,  MVT::i64,// ->841
/*832*/             OPC_MorphNodeTo, TARGET_VAL(PPC::ADDIS8), 0,
                        1/*#VTs*/, MVT::i64, 2/*#Ops*/, 0, 1, 
                    // Src: (add:i64 i64:i64:$in, (PPChi:i64 (tjumptable:i64):$g, 0:i64)) - Complexity = 14
                    // Dst: (ADDIS8:i64 ?:i64:$in, (tjumptable:i64):$g)
/*841*/           0, // EndSwitchType
/*842*/         /*SwitchOpcode*/ 31,  TARGET_VAL(ISD::TargetBlockAddress),// ->876
/*845*/           OPC_MoveParent,
/*846*/           OPC_MoveChild, 1,
/*848*/           OPC_CheckInteger, 0, 
/*850*/           OPC_MoveParent,
/*851*/           OPC_MoveParent,
/*852*/           OPC_SwitchType /*2 cases */, 9,  MVT::i32,// ->864
/*855*/             OPC_MorphNodeTo, TARGET_VAL(PPC::ADDIS), 0,
                        1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1, 
                    // Src: (add:i32 i32:i32:$in, (PPChi:i32 (tblockaddress:i32):$g, 0:i32)) - Complexity = 14
                    // Dst: (ADDIS:i32 ?:i32:$in, (tblockaddress:i32):$g)
/*864*/           /*SwitchType*/ 9,  MVT::i64,// ->875
/*866*/             OPC_MorphNodeTo, TARGET_VAL(PPC::ADDIS8), 0,
                        1/*#VTs*/, MVT::i64, 2/*#Ops*/, 0, 1, 
                    // Src: (add:i64 i64:i64:$in, (PPChi:i64 (tblockaddress:i64):$g, 0:i64)) - Complexity = 14
                    // Dst: (ADDIS8:i64 ?:i64:$in, (tblockaddress:i64):$g)
/*875*/           0, // EndSwitchType
/*876*/         0, // EndSwitchOpcode
/*877*/       0, // EndSwitchOpcode
/*878*/     /*Scope*/ 53|128,1/*181*/, /*->1061*/
/*880*/       OPC_MoveChild, 0,
/*882*/       OPC_SwitchOpcode /*2 cases */, 25,  TARGET_VAL(PPCISD::Lo),// ->911
/*886*/         OPC_RecordChild0, // #0 = $sym
/*887*/         OPC_MoveChild, 0,
/*889*/         OPC_CheckOpcode, TARGET_VAL(ISD::TargetGlobalAddress),
/*892*/         OPC_MoveParent,
/*893*/         OPC_MoveChild, 1,
/*895*/         OPC_CheckInteger, 0, 
/*897*/         OPC_MoveParent,
/*898*/         OPC_MoveParent,
/*899*/         OPC_RecordChild1, // #1 = $rA
/*900*/         OPC_CheckType, MVT::i32,
/*902*/         OPC_MorphNodeTo, TARGET_VAL(PPC::LA), 0,
                    1/*#VTs*/, MVT::i32, 2/*#Ops*/, 1, 0, 
                // Src: (add:i32 (PPClo:i32 (tglobaladdr:i32):$sym, 0:i32), i32:i32:$rA) - Complexity = 14
                // Dst: (LA:i32 i32:i32:$rA, (tglobaladdr:i32):$sym)
/*911*/       /*SwitchOpcode*/ 17|128,1/*145*/,  TARGET_VAL(PPCISD::Hi),// ->1060
/*915*/         OPC_RecordChild0, // #0 = $g
/*916*/         OPC_MoveChild, 0,
/*918*/         OPC_SwitchOpcode /*4 cases */, 32,  TARGET_VAL(ISD::TargetGlobalAddress),// ->954
/*922*/           OPC_MoveParent,
/*923*/           OPC_MoveChild, 1,
/*925*/           OPC_CheckInteger, 0, 
/*927*/           OPC_MoveParent,
/*928*/           OPC_MoveParent,
/*929*/           OPC_RecordChild1, // #1 = $in
/*930*/           OPC_SwitchType /*2 cases */, 9,  MVT::i64,// ->942
/*933*/             OPC_MorphNodeTo, TARGET_VAL(PPC::ADDIS8), 0,
                        1/*#VTs*/, MVT::i64, 2/*#Ops*/, 1, 0, 
                    // Src: (add:i64 (PPChi:i64 (tglobaladdr:i64):$g, 0:i64), i64:i64:$in) - Complexity = 14
                    // Dst: (ADDIS8:i64 ?:i64:$in, (tglobaladdr:i64):$g)
/*942*/           /*SwitchType*/ 9,  MVT::i32,// ->953
/*944*/             OPC_MorphNodeTo, TARGET_VAL(PPC::ADDIS), 0,
                        1/*#VTs*/, MVT::i32, 2/*#Ops*/, 1, 0, 
                    // Src: (add:i32 (PPChi:i32 (tglobaladdr:i32):$g, 0:i32), i32:i32:$in) - Complexity = 14
                    // Dst: (ADDIS:i32 ?:i32:$in, (tglobaladdr:i32):$g)
/*953*/           0, // EndSwitchType
/*954*/         /*SwitchOpcode*/ 32,  TARGET_VAL(ISD::TargetConstantPool),// ->989
/*957*/           OPC_MoveParent,
/*958*/           OPC_MoveChild, 1,
/*960*/           OPC_CheckInteger, 0, 
/*962*/           OPC_MoveParent,
/*963*/           OPC_MoveParent,
/*964*/           OPC_RecordChild1, // #1 = $in
/*965*/           OPC_SwitchType /*2 cases */, 9,  MVT::i64,// ->977
/*968*/             OPC_MorphNodeTo, TARGET_VAL(PPC::ADDIS8), 0,
                        1/*#VTs*/, MVT::i64, 2/*#Ops*/, 1, 0, 
                    // Src: (add:i64 (PPChi:i64 (tconstpool:i64):$g, 0:i64), i64:i64:$in) - Complexity = 14
                    // Dst: (ADDIS8:i64 ?:i64:$in, (tconstpool:i64):$g)
/*977*/           /*SwitchType*/ 9,  MVT::i32,// ->988
/*979*/             OPC_MorphNodeTo, TARGET_VAL(PPC::ADDIS), 0,
                        1/*#VTs*/, MVT::i32, 2/*#Ops*/, 1, 0, 
                    // Src: (add:i32 (PPChi:i32 (tconstpool:i32):$g, 0:i32), i32:i32:$in) - Complexity = 14
                    // Dst: (ADDIS:i32 ?:i32:$in, (tconstpool:i32):$g)
/*988*/           0, // EndSwitchType
/*989*/         /*SwitchOpcode*/ 32,  TARGET_VAL(ISD::TargetJumpTable),// ->1024
/*992*/           OPC_MoveParent,
/*993*/           OPC_MoveChild, 1,
/*995*/           OPC_CheckInteger, 0, 
/*997*/           OPC_MoveParent,
/*998*/           OPC_MoveParent,
/*999*/           OPC_RecordChild1, // #1 = $in
/*1000*/          OPC_SwitchType /*2 cases */, 9,  MVT::i64,// ->1012
/*1003*/            OPC_MorphNodeTo, TARGET_VAL(PPC::ADDIS8), 0,
                        1/*#VTs*/, MVT::i64, 2/*#Ops*/, 1, 0, 
                    // Src: (add:i64 (PPChi:i64 (tjumptable:i64):$g, 0:i64), i64:i64:$in) - Complexity = 14
                    // Dst: (ADDIS8:i64 ?:i64:$in, (tjumptable:i64):$g)
/*1012*/          /*SwitchType*/ 9,  MVT::i32,// ->1023
/*1014*/            OPC_MorphNodeTo, TARGET_VAL(PPC::ADDIS), 0,
                        1/*#VTs*/, MVT::i32, 2/*#Ops*/, 1, 0, 
                    // Src: (add:i32 (PPChi:i32 (tjumptable:i32):$g, 0:i32), i32:i32:$in) - Complexity = 14
                    // Dst: (ADDIS:i32 ?:i32:$in, (tjumptable:i32):$g)
/*1023*/          0, // EndSwitchType
/*1024*/        /*SwitchOpcode*/ 32,  TARGET_VAL(ISD::TargetBlockAddress),// ->1059
/*1027*/          OPC_MoveParent,
/*1028*/          OPC_MoveChild, 1,
/*1030*/          OPC_CheckInteger, 0, 
/*1032*/          OPC_MoveParent,
/*1033*/          OPC_MoveParent,
/*1034*/          OPC_RecordChild1, // #1 = $in
/*1035*/          OPC_SwitchType /*2 cases */, 9,  MVT::i64,// ->1047
/*1038*/            OPC_MorphNodeTo, TARGET_VAL(PPC::ADDIS8), 0,
                        1/*#VTs*/, MVT::i64, 2/*#Ops*/, 1, 0, 
                    // Src: (add:i64 (PPChi:i64 (tblockaddress:i64):$g, 0:i64), i64:i64:$in) - Complexity = 14
                    // Dst: (ADDIS8:i64 ?:i64:$in, (tblockaddress:i64):$g)
/*1047*/          /*SwitchType*/ 9,  MVT::i32,// ->1058
/*1049*/            OPC_MorphNodeTo, TARGET_VAL(PPC::ADDIS), 0,
                        1/*#VTs*/, MVT::i32, 2/*#Ops*/, 1, 0, 
                    // Src: (add:i32 (PPChi:i32 (tblockaddress:i32):$g, 0:i32), i32:i32:$in) - Complexity = 14
                    // Dst: (ADDIS:i32 ?:i32:$in, (tblockaddress:i32):$g)
/*1058*/          0, // EndSwitchType
/*1059*/        0, // EndSwitchOpcode
/*1060*/      0, // EndSwitchOpcode
/*1061*/    /*Scope*/ 101|128,1/*229*/, /*->1292*/
/*1063*/      OPC_RecordChild0, // #0 = $rA
/*1064*/      OPC_Scope, 99, /*->1165*/ // 3 children in Scope
/*1066*/        OPC_RecordChild1, // #1 = $imm
/*1067*/        OPC_MoveChild, 1,
/*1069*/        OPC_SwitchOpcode /*2 cases */, 76,  TARGET_VAL(ISD::Constant),// ->1149
/*1073*/          OPC_Scope, 16, /*->1091*/ // 4 children in Scope
/*1075*/            OPC_CheckPredicate, 0, // Predicate_imm32SExt16
/*1077*/            OPC_MoveParent,
/*1078*/            OPC_CheckType, MVT::i32,
/*1080*/            OPC_EmitConvertToTarget, 1,
/*1082*/            OPC_MorphNodeTo, TARGET_VAL(PPC::ADDI), 0,
                        1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 2, 
                    // Src: (add:i32 i32:i32:$rA, (imm:i32)<<P:Predicate_imm32SExt16>>:$imm) - Complexity = 7
                    // Dst: (ADDI:i32 i32:i32:$rA, (imm:i32):$imm)
/*1091*/          /*Scope*/ 19, /*->1111*/
/*1092*/            OPC_CheckPredicate, 1, // Predicate_imm16ShiftedSExt
/*1094*/            OPC_MoveParent,
/*1095*/            OPC_CheckType, MVT::i32,
/*1097*/            OPC_EmitConvertToTarget, 1,
/*1099*/            OPC_EmitNodeXForm, 0, 2, // HI16
/*1102*/            OPC_MorphNodeTo, TARGET_VAL(PPC::ADDIS), 0,
                        1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 3, 
                    // Src: (add:i32 i32:i32:$rA, (imm:i32)<<P:Predicate_imm16ShiftedSExt>><<X:HI16>>:$imm) - Complexity = 7
                    // Dst: (ADDIS:i32 i32:i32:$rA, (HI16:i32 (imm:i32):$imm))
/*1111*/          /*Scope*/ 16, /*->1128*/
/*1112*/            OPC_CheckPredicate, 2, // Predicate_imm64SExt16
/*1114*/            OPC_MoveParent,
/*1115*/            OPC_CheckType, MVT::i64,
/*1117*/            OPC_EmitConvertToTarget, 1,
/*1119*/            OPC_MorphNodeTo, TARGET_VAL(PPC::ADDI8), 0,
                        1/*#VTs*/, MVT::i64, 2/*#Ops*/, 0, 2, 
                    // Src: (add:i64 i64:i64:$rA, (imm:i64)<<P:Predicate_imm64SExt16>>:$imm) - Complexity = 7
                    // Dst: (ADDI8:i64 i64:i64:$rA, (imm:i64):$imm)
/*1128*/          /*Scope*/ 19, /*->1148*/
/*1129*/            OPC_CheckPredicate, 1, // Predicate_imm16ShiftedSExt
/*1131*/            OPC_MoveParent,
/*1132*/            OPC_CheckType, MVT::i64,
/*1134*/            OPC_EmitConvertToTarget, 1,
/*1136*/            OPC_EmitNodeXForm, 0, 2, // HI16
/*1139*/            OPC_MorphNodeTo, TARGET_VAL(PPC::ADDIS8), 0,
                        1/*#VTs*/, MVT::i64, 2/*#Ops*/, 0, 3, 
                    // Src: (add:i64 i64:i64:$rA, (imm:i64)<<P:Predicate_imm16ShiftedSExt>><<X:HI16>>:$imm) - Complexity = 7
                    // Dst: (ADDIS8:i64 i64:i64:$rA, (HI16:i64 (imm:i64):$imm))
/*1148*/          0, /*End of Scope*/
/*1149*/        /*SwitchOpcode*/ 12,  TARGET_VAL(ISD::TargetGlobalTLSAddress),// ->1164
/*1152*/          OPC_MoveParent,
/*1153*/          OPC_CheckType, MVT::i64,
/*1155*/          OPC_MorphNodeTo, TARGET_VAL(PPC::ADD8TLS), 0,
                      1/*#VTs*/, MVT::i64, 2/*#Ops*/, 0, 1, 
                  // Src: (add:i64 i64:i64:$rA, (tglobaltlsaddr:i64):$rB) - Complexity = 6
                  // Dst: (ADD8TLS:i64 i64:i64:$rA, (tglobaltlsaddr:i64):$rB)
/*1164*/        0, // EndSwitchOpcode
/*1165*/      /*Scope*/ 18, /*->1184*/
/*1166*/        OPC_MoveChild, 0,
/*1168*/        OPC_CheckOpcode, TARGET_VAL(ISD::TargetGlobalTLSAddress),
/*1171*/        OPC_MoveParent,
/*1172*/        OPC_RecordChild1, // #1 = $rA
/*1173*/        OPC_CheckType, MVT::i64,
/*1175*/        OPC_MorphNodeTo, TARGET_VAL(PPC::ADD8TLS), 0,
                    1/*#VTs*/, MVT::i64, 2/*#Ops*/, 1, 0, 
                // Src: (add:i64 (tglobaltlsaddr:i64):$rB, i64:i64:$rA) - Complexity = 6
                // Dst: (ADD8TLS:i64 i64:i64:$rA, (tglobaltlsaddr:i64):$rB)
/*1184*/      /*Scope*/ 106, /*->1291*/
/*1185*/        OPC_RecordChild1, // #1 = $imm
/*1186*/        OPC_Scope, 36, /*->1224*/ // 6 children in Scope
/*1188*/          OPC_MoveChild, 1,
/*1190*/          OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*1193*/          OPC_MoveParent,
/*1194*/          OPC_CheckType, MVT::i32,
/*1196*/          OPC_EmitConvertToTarget, 1,
/*1198*/          OPC_EmitNodeXForm, 1, 2, // LO16
/*1201*/          OPC_EmitNode, TARGET_VAL(PPC::ADDI), 0,
                      1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 3,  // Results = #4
/*1210*/          OPC_EmitConvertToTarget, 1,
/*1212*/          OPC_EmitNodeXForm, 2, 5, // HA16
/*1215*/          OPC_MorphNodeTo, TARGET_VAL(PPC::ADDIS), 0,
                      1/*#VTs*/, MVT::i32, 2/*#Ops*/, 4, 6, 
                  // Src: (add:i32 i32:i32:$in, (imm:i32):$imm) - Complexity = 6
                  // Dst: (ADDIS:i32 (ADDI:i32 ?:i32:$in, (LO16:i32 (imm:i32):$imm)), (HA16:i32 (imm:i32):$imm))
/*1224*/        /*Scope*/ 11, /*->1236*/
/*1225*/          OPC_CheckType, MVT::i32,
/*1227*/          OPC_MorphNodeTo, TARGET_VAL(PPC::ADD4), 0,
                      1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1, 
                  // Src: (add:i32 i32:i32:$rA, i32:i32:$rB) - Complexity = 3
                  // Dst: (ADD4:i32 i32:i32:$rA, i32:i32:$rB)
/*1236*/        /*Scope*/ 11, /*->1248*/
/*1237*/          OPC_CheckType, MVT::i64,
/*1239*/          OPC_MorphNodeTo, TARGET_VAL(PPC::ADD8), 0,
                      1/*#VTs*/, MVT::i64, 2/*#Ops*/, 0, 1, 
                  // Src: (add:i64 i64:i64:$rA, i64:i64:$rB) - Complexity = 3
                  // Dst: (ADD8:i64 i64:i64:$rA, i64:i64:$rB)
/*1248*/        /*Scope*/ 13, /*->1262*/
/*1249*/          OPC_CheckType, MVT::v16i8,
/*1251*/          OPC_CheckPatternPredicate, 0, // (PPCSubTarget.hasAltivec())
/*1253*/          OPC_MorphNodeTo, TARGET_VAL(PPC::VADDUBM), 0,
                      1/*#VTs*/, MVT::v16i8, 2/*#Ops*/, 0, 1, 
                  // Src: (add:v16i8 v16i8:v16i8:$vA, v16i8:v16i8:$vB) - Complexity = 3
                  // Dst: (VADDUBM:v16i8 v16i8:v16i8:$vA, v16i8:v16i8:$vB)
/*1262*/        /*Scope*/ 13, /*->1276*/
/*1263*/          OPC_CheckType, MVT::v8i16,
/*1265*/          OPC_CheckPatternPredicate, 0, // (PPCSubTarget.hasAltivec())
/*1267*/          OPC_MorphNodeTo, TARGET_VAL(PPC::VADDUHM), 0,
                      1/*#VTs*/, MVT::v8i16, 2/*#Ops*/, 0, 1, 
                  // Src: (add:v8i16 v8i16:v8i16:$vA, v8i16:v8i16:$vB) - Complexity = 3
                  // Dst: (VADDUHM:v8i16 v8i16:v8i16:$vA, v8i16:v8i16:$vB)
/*1276*/        /*Scope*/ 13, /*->1290*/
/*1277*/          OPC_CheckType, MVT::v4i32,
/*1279*/          OPC_CheckPatternPredicate, 0, // (PPCSubTarget.hasAltivec())
/*1281*/          OPC_MorphNodeTo, TARGET_VAL(PPC::VADDUWM), 0,
                      1/*#VTs*/, MVT::v4i32, 2/*#Ops*/, 0, 1, 
                  // Src: (add:v4i32 v4i32:v4i32:$vA, v4i32:v4i32:$vB) - Complexity = 3
                  // Dst: (VADDUWM:v4i32 v4i32:v4i32:$vA, v4i32:v4i32:$vB)
/*1290*/        0, /*End of Scope*/
/*1291*/      0, /*End of Scope*/
/*1292*/    0, /*End of Scope*/
/*1293*/  /*SwitchOpcode*/ 117|128,6/*885*/,  TARGET_VAL(ISD::LOAD),// ->2182
/*1297*/    OPC_RecordMemRef,
/*1298*/    OPC_RecordNode,   // #0 = 'ld' chained node
/*1299*/    OPC_RecordChild1, // #1 = $src
/*1300*/    OPC_CheckPredicate, 3, // Predicate_unindexedload
/*1302*/    OPC_Scope, 19, /*->1323*/ // 19 children in Scope
/*1304*/      OPC_CheckPredicate, 4, // Predicate_zextload
/*1306*/      OPC_CheckPredicate, 5, // Predicate_zextloadi8
/*1308*/      OPC_CheckType, MVT::i32,
/*1310*/      OPC_CheckComplexPat, /*CP*/1, /*#*/1, // SelectAddrImm:$src #2 #3
/*1313*/      OPC_EmitMergeInputChains1_0,
/*1314*/      OPC_MorphNodeTo, TARGET_VAL(PPC::LBZ), 0|OPFL_Chain|OPFL_MemRefs,
                  1/*#VTs*/, MVT::i32, 2/*#Ops*/, 2, 3, 
              // Src: (ld:i32 iaddr:iPTR:$src)<<P:Predicate_unindexedload>><<P:Predicate_zextload>><<P:Predicate_zextloadi8>> - Complexity = 13
              // Dst: (LBZ:i32 iaddr:iPTR:$src)
/*1323*/    /*Scope*/ 19, /*->1343*/
/*1324*/      OPC_CheckPredicate, 6, // Predicate_sextload
/*1326*/      OPC_CheckPredicate, 7, // Predicate_sextloadi16
/*1328*/      OPC_CheckType, MVT::i32,
/*1330*/      OPC_CheckComplexPat, /*CP*/1, /*#*/1, // SelectAddrImm:$src #2 #3
/*1333*/      OPC_EmitMergeInputChains1_0,
/*1334*/      OPC_MorphNodeTo, TARGET_VAL(PPC::LHA), 0|OPFL_Chain|OPFL_MemRefs,
                  1/*#VTs*/, MVT::i32, 2/*#Ops*/, 2, 3, 
              // Src: (ld:i32 iaddr:iPTR:$src)<<P:Predicate_unindexedload>><<P:Predicate_sextload>><<P:Predicate_sextloadi16>> - Complexity = 13
              // Dst: (LHA:i32 iaddr:iPTR:$src)
/*1343*/    /*Scope*/ 19, /*->1363*/
/*1344*/      OPC_CheckPredicate, 4, // Predicate_zextload
/*1346*/      OPC_CheckPredicate, 8, // Predicate_zextloadi16
/*1348*/      OPC_CheckType, MVT::i32,
/*1350*/      OPC_CheckComplexPat, /*CP*/1, /*#*/1, // SelectAddrImm:$src #2 #3
/*1353*/      OPC_EmitMergeInputChains1_0,
/*1354*/      OPC_MorphNodeTo, TARGET_VAL(PPC::LHZ), 0|OPFL_Chain|OPFL_MemRefs,
                  1/*#VTs*/, MVT::i32, 2/*#Ops*/, 2, 3, 
              // Src: (ld:i32 iaddr:iPTR:$src)<<P:Predicate_unindexedload>><<P:Predicate_zextload>><<P:Predicate_zextloadi16>> - Complexity = 13
              // Dst: (LHZ:i32 iaddr:iPTR:$src)
/*1363*/    /*Scope*/ 17, /*->1381*/
/*1364*/      OPC_CheckPredicate, 9, // Predicate_load
/*1366*/      OPC_CheckType, MVT::i32,
/*1368*/      OPC_CheckComplexPat, /*CP*/1, /*#*/1, // SelectAddrImm:$src #2 #3
/*1371*/      OPC_EmitMergeInputChains1_0,
/*1372*/      OPC_MorphNodeTo, TARGET_VAL(PPC::LWZ), 0|OPFL_Chain|OPFL_MemRefs,
                  1/*#VTs*/, MVT::i32, 2/*#Ops*/, 2, 3, 
              // Src: (ld:i32 iaddr:iPTR:$src)<<P:Predicate_unindexedload>><<P:Predicate_load>> - Complexity = 13
              // Dst: (LWZ:i32 iaddr:iPTR:$src)
/*1381*/    /*Scope*/ 19, /*->1401*/
/*1382*/      OPC_CheckPredicate, 4, // Predicate_zextload
/*1384*/      OPC_CheckPredicate, 5, // Predicate_zextloadi8
/*1386*/      OPC_CheckType, MVT::i32,
/*1388*/      OPC_CheckComplexPat, /*CP*/2, /*#*/1, // SelectAddrIdx:$src #2 #3
/*1391*/      OPC_EmitMergeInputChains1_0,
/*1392*/      OPC_MorphNodeTo, TARGET_VAL(PPC::LBZX), 0|OPFL_Chain|OPFL_MemRefs,
                  1/*#VTs*/, MVT::i32, 2/*#Ops*/, 2, 3, 
              // Src: (ld:i32 xaddr:iPTR:$src)<<P:Predicate_unindexedload>><<P:Predicate_zextload>><<P:Predicate_zextloadi8>> - Complexity = 13
              // Dst: (LBZX:i32 xaddr:iPTR:$src)
/*1401*/    /*Scope*/ 19, /*->1421*/
/*1402*/      OPC_CheckPredicate, 6, // Predicate_sextload
/*1404*/      OPC_CheckPredicate, 7, // Predicate_sextloadi16
/*1406*/      OPC_CheckType, MVT::i32,
/*1408*/      OPC_CheckComplexPat, /*CP*/2, /*#*/1, // SelectAddrIdx:$src #2 #3
/*1411*/      OPC_EmitMergeInputChains1_0,
/*1412*/      OPC_MorphNodeTo, TARGET_VAL(PPC::LHAX), 0|OPFL_Chain|OPFL_MemRefs,
                  1/*#VTs*/, MVT::i32, 2/*#Ops*/, 2, 3, 
              // Src: (ld:i32 xaddr:iPTR:$src)<<P:Predicate_unindexedload>><<P:Predicate_sextload>><<P:Predicate_sextloadi16>> - Complexity = 13
              // Dst: (LHAX:i32 xaddr:iPTR:$src)
/*1421*/    /*Scope*/ 19, /*->1441*/
/*1422*/      OPC_CheckPredicate, 4, // Predicate_zextload
/*1424*/      OPC_CheckPredicate, 8, // Predicate_zextloadi16
/*1426*/      OPC_CheckType, MVT::i32,
/*1428*/      OPC_CheckComplexPat, /*CP*/2, /*#*/1, // SelectAddrIdx:$src #2 #3
/*1431*/      OPC_EmitMergeInputChains1_0,
/*1432*/      OPC_MorphNodeTo, TARGET_VAL(PPC::LHZX), 0|OPFL_Chain|OPFL_MemRefs,
                  1/*#VTs*/, MVT::i32, 2/*#Ops*/, 2, 3, 
              // Src: (ld:i32 xaddr:iPTR:$src)<<P:Predicate_unindexedload>><<P:Predicate_zextload>><<P:Predicate_zextloadi16>> - Complexity = 13
              // Dst: (LHZX:i32 xaddr:iPTR:$src)
/*1441*/    /*Scope*/ 17, /*->1459*/
/*1442*/      OPC_CheckPredicate, 9, // Predicate_load
/*1444*/      OPC_CheckType, MVT::i32,
/*1446*/      OPC_CheckComplexPat, /*CP*/2, /*#*/1, // SelectAddrIdx:$src #2 #3
/*1449*/      OPC_EmitMergeInputChains1_0,
/*1450*/      OPC_MorphNodeTo, TARGET_VAL(PPC::LWZX), 0|OPFL_Chain|OPFL_MemRefs,
                  1/*#VTs*/, MVT::i32, 2/*#Ops*/, 2, 3, 
              // Src: (ld:i32 xaddr:iPTR:$src)<<P:Predicate_unindexedload>><<P:Predicate_load>> - Complexity = 13
              // Dst: (LWZX:i32 xaddr:iPTR:$src)
/*1459*/    /*Scope*/ 36, /*->1496*/
/*1460*/      OPC_CheckPredicate, 4, // Predicate_zextload
/*1462*/      OPC_CheckPredicate, 10, // Predicate_zextloadi1
/*1464*/      OPC_CheckType, MVT::i32,
/*1466*/      OPC_Scope, 13, /*->1481*/ // 2 children in Scope
/*1468*/        OPC_CheckComplexPat, /*CP*/1, /*#*/1, // SelectAddrImm:$src #2 #3
/*1471*/        OPC_EmitMergeInputChains1_0,
/*1472*/        OPC_MorphNodeTo, TARGET_VAL(PPC::LBZ), 0|OPFL_Chain|OPFL_MemRefs,
                    1/*#VTs*/, MVT::i32, 2/*#Ops*/, 2, 3, 
                // Src: (ld:i32 iaddr:iPTR:$src)<<P:Predicate_unindexedload>><<P:Predicate_zextload>><<P:Predicate_zextloadi1>> - Complexity = 13
                // Dst: (LBZ:i32 iaddr:iPTR:$src)
/*1481*/      /*Scope*/ 13, /*->1495*/
/*1482*/        OPC_CheckComplexPat, /*CP*/2, /*#*/1, // SelectAddrIdx:$src #2 #3
/*1485*/        OPC_EmitMergeInputChains1_0,
/*1486*/        OPC_MorphNodeTo, TARGET_VAL(PPC::LBZX), 0|OPFL_Chain|OPFL_MemRefs,
                    1/*#VTs*/, MVT::i32, 2/*#Ops*/, 2, 3, 
                // Src: (ld:i32 xaddr:iPTR:$src)<<P:Predicate_unindexedload>><<P:Predicate_zextload>><<P:Predicate_zextloadi1>> - Complexity = 13
                // Dst: (LBZX:i32 xaddr:iPTR:$src)
/*1495*/      0, /*End of Scope*/
/*1496*/    /*Scope*/ 105, /*->1602*/
/*1497*/      OPC_CheckPredicate, 11, // Predicate_extload
/*1499*/      OPC_CheckType, MVT::i32,
/*1501*/      OPC_Scope, 32, /*->1535*/ // 3 children in Scope
/*1503*/        OPC_CheckPredicate, 12, // Predicate_extloadi1
/*1505*/        OPC_Scope, 13, /*->1520*/ // 2 children in Scope
/*1507*/          OPC_CheckComplexPat, /*CP*/1, /*#*/1, // SelectAddrImm:$src #2 #3
/*1510*/          OPC_EmitMergeInputChains1_0,
/*1511*/          OPC_MorphNodeTo, TARGET_VAL(PPC::LBZ), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i32, 2/*#Ops*/, 2, 3, 
                  // Src: (ld:i32 iaddr:iPTR:$src)<<P:Predicate_unindexedload>><<P:Predicate_extload>><<P:Predicate_extloadi1>> - Complexity = 13
                  // Dst: (LBZ:i32 iaddr:iPTR:$src)
/*1520*/        /*Scope*/ 13, /*->1534*/
/*1521*/          OPC_CheckComplexPat, /*CP*/2, /*#*/1, // SelectAddrIdx:$src #2 #3
/*1524*/          OPC_EmitMergeInputChains1_0,
/*1525*/          OPC_MorphNodeTo, TARGET_VAL(PPC::LBZX), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i32, 2/*#Ops*/, 2, 3, 
                  // Src: (ld:i32 xaddr:iPTR:$src)<<P:Predicate_unindexedload>><<P:Predicate_extload>><<P:Predicate_extloadi1>> - Complexity = 13
                  // Dst: (LBZX:i32 xaddr:iPTR:$src)
/*1534*/        0, /*End of Scope*/
/*1535*/      /*Scope*/ 32, /*->1568*/
/*1536*/        OPC_CheckPredicate, 13, // Predicate_extloadi8
/*1538*/        OPC_Scope, 13, /*->1553*/ // 2 children in Scope
/*1540*/          OPC_CheckComplexPat, /*CP*/1, /*#*/1, // SelectAddrImm:$src #2 #3
/*1543*/          OPC_EmitMergeInputChains1_0,
/*1544*/          OPC_MorphNodeTo, TARGET_VAL(PPC::LBZ), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i32, 2/*#Ops*/, 2, 3, 
                  // Src: (ld:i32 iaddr:iPTR:$src)<<P:Predicate_unindexedload>><<P:Predicate_extload>><<P:Predicate_extloadi8>> - Complexity = 13
                  // Dst: (LBZ:i32 iaddr:iPTR:$src)
/*1553*/        /*Scope*/ 13, /*->1567*/
/*1554*/          OPC_CheckComplexPat, /*CP*/2, /*#*/1, // SelectAddrIdx:$src #2 #3
/*1557*/          OPC_EmitMergeInputChains1_0,
/*1558*/          OPC_MorphNodeTo, TARGET_VAL(PPC::LBZX), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i32, 2/*#Ops*/, 2, 3, 
                  // Src: (ld:i32 xaddr:iPTR:$src)<<P:Predicate_unindexedload>><<P:Predicate_extload>><<P:Predicate_extloadi8>> - Complexity = 13
                  // Dst: (LBZX:i32 xaddr:iPTR:$src)
/*1567*/        0, /*End of Scope*/
/*1568*/      /*Scope*/ 32, /*->1601*/
/*1569*/        OPC_CheckPredicate, 14, // Predicate_extloadi16
/*1571*/        OPC_Scope, 13, /*->1586*/ // 2 children in Scope
/*1573*/          OPC_CheckComplexPat, /*CP*/1, /*#*/1, // SelectAddrImm:$src #2 #3
/*1576*/          OPC_EmitMergeInputChains1_0,
/*1577*/          OPC_MorphNodeTo, TARGET_VAL(PPC::LHZ), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i32, 2/*#Ops*/, 2, 3, 
                  // Src: (ld:i32 iaddr:iPTR:$src)<<P:Predicate_unindexedload>><<P:Predicate_extload>><<P:Predicate_extloadi16>> - Complexity = 13
                  // Dst: (LHZ:i32 iaddr:iPTR:$src)
/*1586*/        /*Scope*/ 13, /*->1600*/
/*1587*/          OPC_CheckComplexPat, /*CP*/2, /*#*/1, // SelectAddrIdx:$src #2 #3
/*1590*/          OPC_EmitMergeInputChains1_0,
/*1591*/          OPC_MorphNodeTo, TARGET_VAL(PPC::LHZX), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i32, 2/*#Ops*/, 2, 3, 
                  // Src: (ld:i32 xaddr:iPTR:$src)<<P:Predicate_unindexedload>><<P:Predicate_extload>><<P:Predicate_extloadi16>> - Complexity = 13
                  // Dst: (LHZX:i32 xaddr:iPTR:$src)
/*1600*/        0, /*End of Scope*/
/*1601*/      0, /*End of Scope*/
/*1602*/    /*Scope*/ 72, /*->1675*/
/*1603*/      OPC_CheckPredicate, 6, // Predicate_sextload
/*1605*/      OPC_CheckType, MVT::i64,
/*1607*/      OPC_Scope, 15, /*->1624*/ // 4 children in Scope
/*1609*/        OPC_CheckPredicate, 7, // Predicate_sextloadi16
/*1611*/        OPC_CheckComplexPat, /*CP*/1, /*#*/1, // SelectAddrImm:$src #2 #3
/*1614*/        OPC_EmitMergeInputChains1_0,
/*1615*/        OPC_MorphNodeTo, TARGET_VAL(PPC::LHA8), 0|OPFL_Chain|OPFL_MemRefs,
                    1/*#VTs*/, MVT::i64, 2/*#Ops*/, 2, 3, 
                // Src: (ld:i64 iaddr:iPTR:$src)<<P:Predicate_unindexedload>><<P:Predicate_sextload>><<P:Predicate_sextloadi16>> - Complexity = 13
                // Dst: (LHA8:i64 iaddr:iPTR:$src)
/*1624*/      /*Scope*/ 17, /*->1642*/
/*1625*/        OPC_CheckPredicate, 15, // Predicate_sextloadi32
/*1627*/        OPC_CheckPredicate, 16, // Predicate_aligned4sextloadi32
/*1629*/        OPC_CheckComplexPat, /*CP*/3, /*#*/1, // SelectAddrImmX4:$src #2 #3
/*1632*/        OPC_EmitMergeInputChains1_0,
/*1633*/        OPC_MorphNodeTo, TARGET_VAL(PPC::LWA), 0|OPFL_Chain|OPFL_MemRefs,
                    1/*#VTs*/, MVT::i64, 2/*#Ops*/, 2, 3, 
                // Src: (ld:i64 ixaddr:iPTR:$src)<<P:Predicate_unindexedload>><<P:Predicate_sextload>><<P:Predicate_sextloadi32>><<P:Predicate_aligned4sextloadi32>> - Complexity = 13
                // Dst: (LWA:i64 ixaddr:iPTR:$src)
/*1642*/      /*Scope*/ 15, /*->1658*/
/*1643*/        OPC_CheckPredicate, 7, // Predicate_sextloadi16
/*1645*/        OPC_CheckComplexPat, /*CP*/2, /*#*/1, // SelectAddrIdx:$src #2 #3
/*1648*/        OPC_EmitMergeInputChains1_0,
/*1649*/        OPC_MorphNodeTo, TARGET_VAL(PPC::LHAX8), 0|OPFL_Chain|OPFL_MemRefs,
                    1/*#VTs*/, MVT::i64, 2/*#Ops*/, 2, 3, 
                // Src: (ld:i64 xaddr:iPTR:$src)<<P:Predicate_unindexedload>><<P:Predicate_sextload>><<P:Predicate_sextloadi16>> - Complexity = 13
                // Dst: (LHAX8:i64 xaddr:iPTR:$src)
/*1658*/      /*Scope*/ 15, /*->1674*/
/*1659*/        OPC_CheckPredicate, 15, // Predicate_sextloadi32
/*1661*/        OPC_CheckComplexPat, /*CP*/2, /*#*/1, // SelectAddrIdx:$src #2 #3
/*1664*/        OPC_EmitMergeInputChains1_0,
/*1665*/        OPC_MorphNodeTo, TARGET_VAL(PPC::LWAX), 0|OPFL_Chain|OPFL_MemRefs,
                    1/*#VTs*/, MVT::i64, 2/*#Ops*/, 2, 3, 
                // Src: (ld:i64 xaddr:iPTR:$src)<<P:Predicate_unindexedload>><<P:Predicate_sextload>><<P:Predicate_sextloadi32>> - Complexity = 13
                // Dst: (LWAX:i64 xaddr:iPTR:$src)
/*1674*/      0, /*End of Scope*/
/*1675*/    /*Scope*/ 102, /*->1778*/
/*1676*/      OPC_CheckPredicate, 4, // Predicate_zextload
/*1678*/      OPC_CheckType, MVT::i64,
/*1680*/      OPC_Scope, 15, /*->1697*/ // 6 children in Scope
/*1682*/        OPC_CheckPredicate, 5, // Predicate_zextloadi8
/*1684*/        OPC_CheckComplexPat, /*CP*/1, /*#*/1, // SelectAddrImm:$src #2 #3
/*1687*/        OPC_EmitMergeInputChains1_0,
/*1688*/        OPC_MorphNodeTo, TARGET_VAL(PPC::LBZ8), 0|OPFL_Chain|OPFL_MemRefs,
                    1/*#VTs*/, MVT::i64, 2/*#Ops*/, 2, 3, 
                // Src: (ld:i64 iaddr:iPTR:$src)<<P:Predicate_unindexedload>><<P:Predicate_zextload>><<P:Predicate_zextloadi8>> - Complexity = 13
                // Dst: (LBZ8:i64 iaddr:iPTR:$src)
/*1697*/      /*Scope*/ 15, /*->1713*/
/*1698*/        OPC_CheckPredicate, 8, // Predicate_zextloadi16
/*1700*/        OPC_CheckComplexPat, /*CP*/1, /*#*/1, // SelectAddrImm:$src #2 #3
/*1703*/        OPC_EmitMergeInputChains1_0,
/*1704*/        OPC_MorphNodeTo, TARGET_VAL(PPC::LHZ8), 0|OPFL_Chain|OPFL_MemRefs,
                    1/*#VTs*/, MVT::i64, 2/*#Ops*/, 2, 3, 
                // Src: (ld:i64 iaddr:iPTR:$src)<<P:Predicate_unindexedload>><<P:Predicate_zextload>><<P:Predicate_zextloadi16>> - Complexity = 13
                // Dst: (LHZ8:i64 iaddr:iPTR:$src)
/*1713*/      /*Scope*/ 15, /*->1729*/
/*1714*/        OPC_CheckPredicate, 17, // Predicate_zextloadi32
/*1716*/        OPC_CheckComplexPat, /*CP*/1, /*#*/1, // SelectAddrImm:$src #2 #3
/*1719*/        OPC_EmitMergeInputChains1_0,
/*1720*/        OPC_MorphNodeTo, TARGET_VAL(PPC::LWZ8), 0|OPFL_Chain|OPFL_MemRefs,
                    1/*#VTs*/, MVT::i64, 2/*#Ops*/, 2, 3, 
                // Src: (ld:i64 iaddr:iPTR:$src)<<P:Predicate_unindexedload>><<P:Predicate_zextload>><<P:Predicate_zextloadi32>> - Complexity = 13
                // Dst: (LWZ8:i64 iaddr:iPTR:$src)
/*1729*/      /*Scope*/ 15, /*->1745*/
/*1730*/        OPC_CheckPredicate, 5, // Predicate_zextloadi8
/*1732*/        OPC_CheckComplexPat, /*CP*/2, /*#*/1, // SelectAddrIdx:$src #2 #3
/*1735*/        OPC_EmitMergeInputChains1_0,
/*1736*/        OPC_MorphNodeTo, TARGET_VAL(PPC::LBZX8), 0|OPFL_Chain|OPFL_MemRefs,
                    1/*#VTs*/, MVT::i64, 2/*#Ops*/, 2, 3, 
                // Src: (ld:i64 xaddr:iPTR:$src)<<P:Predicate_unindexedload>><<P:Predicate_zextload>><<P:Predicate_zextloadi8>> - Complexity = 13
                // Dst: (LBZX8:i64 xaddr:iPTR:$src)
/*1745*/      /*Scope*/ 15, /*->1761*/
/*1746*/        OPC_CheckPredicate, 8, // Predicate_zextloadi16
/*1748*/        OPC_CheckComplexPat, /*CP*/2, /*#*/1, // SelectAddrIdx:$src #2 #3
/*1751*/        OPC_EmitMergeInputChains1_0,
/*1752*/        OPC_MorphNodeTo, TARGET_VAL(PPC::LHZX8), 0|OPFL_Chain|OPFL_MemRefs,
                    1/*#VTs*/, MVT::i64, 2/*#Ops*/, 2, 3, 
                // Src: (ld:i64 xaddr:iPTR:$src)<<P:Predicate_unindexedload>><<P:Predicate_zextload>><<P:Predicate_zextloadi16>> - Complexity = 13
                // Dst: (LHZX8:i64 xaddr:iPTR:$src)
/*1761*/      /*Scope*/ 15, /*->1777*/
/*1762*/        OPC_CheckPredicate, 17, // Predicate_zextloadi32
/*1764*/        OPC_CheckComplexPat, /*CP*/2, /*#*/1, // SelectAddrIdx:$src #2 #3
/*1767*/        OPC_EmitMergeInputChains1_0,
/*1768*/        OPC_MorphNodeTo, TARGET_VAL(PPC::LWZX8), 0|OPFL_Chain|OPFL_MemRefs,
                    1/*#VTs*/, MVT::i64, 2/*#Ops*/, 2, 3, 
                // Src: (ld:i64 xaddr:iPTR:$src)<<P:Predicate_unindexedload>><<P:Predicate_zextload>><<P:Predicate_zextloadi32>> - Complexity = 13
                // Dst: (LWZX8:i64 xaddr:iPTR:$src)
/*1777*/      0, /*End of Scope*/
/*1778*/    /*Scope*/ 36, /*->1815*/
/*1779*/      OPC_CheckPredicate, 9, // Predicate_load
/*1781*/      OPC_CheckType, MVT::i64,
/*1783*/      OPC_Scope, 15, /*->1800*/ // 2 children in Scope
/*1785*/        OPC_CheckPredicate, 18, // Predicate_aligned4load
/*1787*/        OPC_CheckComplexPat, /*CP*/3, /*#*/1, // SelectAddrImmX4:$src #2 #3
/*1790*/        OPC_EmitMergeInputChains1_0,
/*1791*/        OPC_MorphNodeTo, TARGET_VAL(PPC::LD), 0|OPFL_Chain|OPFL_MemRefs,
                    1/*#VTs*/, MVT::i64, 2/*#Ops*/, 2, 3, 
                // Src: (ld:i64 ixaddr:iPTR:$src)<<P:Predicate_unindexedload>><<P:Predicate_load>><<P:Predicate_aligned4load>> - Complexity = 13
                // Dst: (LD:i64 ixaddr:iPTR:$src)
/*1800*/      /*Scope*/ 13, /*->1814*/
/*1801*/        OPC_CheckComplexPat, /*CP*/2, /*#*/1, // SelectAddrIdx:$src #2 #3
/*1804*/        OPC_EmitMergeInputChains1_0,
/*1805*/        OPC_MorphNodeTo, TARGET_VAL(PPC::LDX), 0|OPFL_Chain|OPFL_MemRefs,
                    1/*#VTs*/, MVT::i64, 2/*#Ops*/, 2, 3, 
                // Src: (ld:i64 xaddr:iPTR:$src)<<P:Predicate_unindexedload>><<P:Predicate_load>> - Complexity = 13
                // Dst: (LDX:i64 xaddr:iPTR:$src)
/*1814*/      0, /*End of Scope*/
/*1815*/    /*Scope*/ 36, /*->1852*/
/*1816*/      OPC_CheckPredicate, 4, // Predicate_zextload
/*1818*/      OPC_CheckPredicate, 10, // Predicate_zextloadi1
/*1820*/      OPC_CheckType, MVT::i64,
/*1822*/      OPC_Scope, 13, /*->1837*/ // 2 children in Scope
/*1824*/        OPC_CheckComplexPat, /*CP*/1, /*#*/1, // SelectAddrImm:$src #2 #3
/*1827*/        OPC_EmitMergeInputChains1_0,
/*1828*/        OPC_MorphNodeTo, TARGET_VAL(PPC::LBZ8), 0|OPFL_Chain|OPFL_MemRefs,
                    1/*#VTs*/, MVT::i64, 2/*#Ops*/, 2, 3, 
                // Src: (ld:i64 iaddr:iPTR:$src)<<P:Predicate_unindexedload>><<P:Predicate_zextload>><<P:Predicate_zextloadi1>> - Complexity = 13
                // Dst: (LBZ8:i64 iaddr:iPTR:$src)
/*1837*/      /*Scope*/ 13, /*->1851*/
/*1838*/        OPC_CheckComplexPat, /*CP*/2, /*#*/1, // SelectAddrIdx:$src #2 #3
/*1841*/        OPC_EmitMergeInputChains1_0,
/*1842*/        OPC_MorphNodeTo, TARGET_VAL(PPC::LBZX8), 0|OPFL_Chain|OPFL_MemRefs,
                    1/*#VTs*/, MVT::i64, 2/*#Ops*/, 2, 3, 
                // Src: (ld:i64 xaddr:iPTR:$src)<<P:Predicate_unindexedload>><<P:Predicate_zextload>><<P:Predicate_zextloadi1>> - Complexity = 13
                // Dst: (LBZX8:i64 xaddr:iPTR:$src)
/*1851*/      0, /*End of Scope*/
/*1852*/    /*Scope*/ 10|128,1/*138*/, /*->1992*/
/*1854*/      OPC_CheckPredicate, 11, // Predicate_extload
/*1856*/      OPC_CheckType, MVT::i64,
/*1858*/      OPC_Scope, 32, /*->1892*/ // 4 children in Scope
/*1860*/        OPC_CheckPredicate, 12, // Predicate_extloadi1
/*1862*/        OPC_Scope, 13, /*->1877*/ // 2 children in Scope
/*1864*/          OPC_CheckComplexPat, /*CP*/1, /*#*/1, // SelectAddrImm:$src #2 #3
/*1867*/          OPC_EmitMergeInputChains1_0,
/*1868*/          OPC_MorphNodeTo, TARGET_VAL(PPC::LBZ8), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i64, 2/*#Ops*/, 2, 3, 
                  // Src: (ld:i64 iaddr:iPTR:$src)<<P:Predicate_unindexedload>><<P:Predicate_extload>><<P:Predicate_extloadi1>> - Complexity = 13
                  // Dst: (LBZ8:i64 iaddr:iPTR:$src)
/*1877*/        /*Scope*/ 13, /*->1891*/
/*1878*/          OPC_CheckComplexPat, /*CP*/2, /*#*/1, // SelectAddrIdx:$src #2 #3
/*1881*/          OPC_EmitMergeInputChains1_0,
/*1882*/          OPC_MorphNodeTo, TARGET_VAL(PPC::LBZX8), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i64, 2/*#Ops*/, 2, 3, 
                  // Src: (ld:i64 xaddr:iPTR:$src)<<P:Predicate_unindexedload>><<P:Predicate_extload>><<P:Predicate_extloadi1>> - Complexity = 13
                  // Dst: (LBZX8:i64 xaddr:iPTR:$src)
/*1891*/        0, /*End of Scope*/
/*1892*/      /*Scope*/ 32, /*->1925*/
/*1893*/        OPC_CheckPredicate, 13, // Predicate_extloadi8
/*1895*/        OPC_Scope, 13, /*->1910*/ // 2 children in Scope
/*1897*/          OPC_CheckComplexPat, /*CP*/1, /*#*/1, // SelectAddrImm:$src #2 #3
/*1900*/          OPC_EmitMergeInputChains1_0,
/*1901*/          OPC_MorphNodeTo, TARGET_VAL(PPC::LBZ8), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i64, 2/*#Ops*/, 2, 3, 
                  // Src: (ld:i64 iaddr:iPTR:$src)<<P:Predicate_unindexedload>><<P:Predicate_extload>><<P:Predicate_extloadi8>> - Complexity = 13
                  // Dst: (LBZ8:i64 iaddr:iPTR:$src)
/*1910*/        /*Scope*/ 13, /*->1924*/
/*1911*/          OPC_CheckComplexPat, /*CP*/2, /*#*/1, // SelectAddrIdx:$src #2 #3
/*1914*/          OPC_EmitMergeInputChains1_0,
/*1915*/          OPC_MorphNodeTo, TARGET_VAL(PPC::LBZX8), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i64, 2/*#Ops*/, 2, 3, 
                  // Src: (ld:i64 xaddr:iPTR:$src)<<P:Predicate_unindexedload>><<P:Predicate_extload>><<P:Predicate_extloadi8>> - Complexity = 13
                  // Dst: (LBZX8:i64 xaddr:iPTR:$src)
/*1924*/        0, /*End of Scope*/
/*1925*/      /*Scope*/ 32, /*->1958*/
/*1926*/        OPC_CheckPredicate, 14, // Predicate_extloadi16
/*1928*/        OPC_Scope, 13, /*->1943*/ // 2 children in Scope
/*1930*/          OPC_CheckComplexPat, /*CP*/1, /*#*/1, // SelectAddrImm:$src #2 #3
/*1933*/          OPC_EmitMergeInputChains1_0,
/*1934*/          OPC_MorphNodeTo, TARGET_VAL(PPC::LHZ8), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i64, 2/*#Ops*/, 2, 3, 
                  // Src: (ld:i64 iaddr:iPTR:$src)<<P:Predicate_unindexedload>><<P:Predicate_extload>><<P:Predicate_extloadi16>> - Complexity = 13
                  // Dst: (LHZ8:i64 iaddr:iPTR:$src)
/*1943*/        /*Scope*/ 13, /*->1957*/
/*1944*/          OPC_CheckComplexPat, /*CP*/2, /*#*/1, // SelectAddrIdx:$src #2 #3
/*1947*/          OPC_EmitMergeInputChains1_0,
/*1948*/          OPC_MorphNodeTo, TARGET_VAL(PPC::LHZX8), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i64, 2/*#Ops*/, 2, 3, 
                  // Src: (ld:i64 xaddr:iPTR:$src)<<P:Predicate_unindexedload>><<P:Predicate_extload>><<P:Predicate_extloadi16>> - Complexity = 13
                  // Dst: (LHZX8:i64 xaddr:iPTR:$src)
/*1957*/        0, /*End of Scope*/
/*1958*/      /*Scope*/ 32, /*->1991*/
/*1959*/        OPC_CheckPredicate, 19, // Predicate_extloadi32
/*1961*/        OPC_Scope, 13, /*->1976*/ // 2 children in Scope
/*1963*/          OPC_CheckComplexPat, /*CP*/1, /*#*/1, // SelectAddrImm:$src #2 #3
/*1966*/          OPC_EmitMergeInputChains1_0,
/*1967*/          OPC_MorphNodeTo, TARGET_VAL(PPC::LWZ8), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i64, 2/*#Ops*/, 2, 3, 
                  // Src: (ld:i64 iaddr:iPTR:$src)<<P:Predicate_unindexedload>><<P:Predicate_extload>><<P:Predicate_extloadi32>> - Complexity = 13
                  // Dst: (LWZ8:i64 iaddr:iPTR:$src)
/*1976*/        /*Scope*/ 13, /*->1990*/
/*1977*/          OPC_CheckComplexPat, /*CP*/2, /*#*/1, // SelectAddrIdx:$src #2 #3
/*1980*/          OPC_EmitMergeInputChains1_0,
/*1981*/          OPC_MorphNodeTo, TARGET_VAL(PPC::LWZX8), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i64, 2/*#Ops*/, 2, 3, 
                  // Src: (ld:i64 xaddr:iPTR:$src)<<P:Predicate_unindexedload>><<P:Predicate_extload>><<P:Predicate_extloadi32>> - Complexity = 13
                  // Dst: (LWZX8:i64 xaddr:iPTR:$src)
/*1990*/        0, /*End of Scope*/
/*1991*/      0, /*End of Scope*/
/*1992*/    /*Scope*/ 21, /*->2014*/
/*1993*/      OPC_CheckPredicate, 6, // Predicate_sextload
/*1995*/      OPC_CheckPredicate, 15, // Predicate_sextloadi32
/*1997*/      OPC_CheckPredicate, 20, // Predicate_unaligned4sextloadi32
/*1999*/      OPC_CheckType, MVT::i64,
/*2001*/      OPC_CheckComplexPat, /*CP*/0, /*#*/1, // SelectAddrIdxOnly:$src #2 #3
/*2004*/      OPC_EmitMergeInputChains1_0,
/*2005*/      OPC_MorphNodeTo, TARGET_VAL(PPC::LWAX), 0|OPFL_Chain|OPFL_MemRefs,
                  1/*#VTs*/, MVT::i64, 2/*#Ops*/, 2, 3, 
              // Src: (ld:i64 xoaddr:iPTR:$src)<<P:Predicate_unindexedload>><<P:Predicate_sextload>><<P:Predicate_sextloadi32>><<P:Predicate_unaligned4sextloadi32>> - Complexity = 13
              // Dst: (LWAX:i64 xoaddr:iPTR:$src)
/*2014*/    /*Scope*/ 85, /*->2100*/
/*2015*/      OPC_CheckPredicate, 9, // Predicate_load
/*2017*/      OPC_SwitchType /*3 cases */, 15,  MVT::i64,// ->2035
/*2020*/        OPC_CheckPredicate, 21, // Predicate_unaligned4load
/*2022*/        OPC_CheckComplexPat, /*CP*/0, /*#*/1, // SelectAddrIdxOnly:$src #2 #3
/*2025*/        OPC_EmitMergeInputChains1_0,
/*2026*/        OPC_MorphNodeTo, TARGET_VAL(PPC::LDX), 0|OPFL_Chain|OPFL_MemRefs,
                    1/*#VTs*/, MVT::i64, 2/*#Ops*/, 2, 3, 
                // Src: (ld:i64 xoaddr:iPTR:$src)<<P:Predicate_unindexedload>><<P:Predicate_load>><<P:Predicate_unaligned4load>> - Complexity = 13
                // Dst: (LDX:i64 xoaddr:iPTR:$src)
/*2035*/      /*SwitchType*/ 30,  MVT::f32,// ->2067
/*2037*/        OPC_Scope, 13, /*->2052*/ // 2 children in Scope
/*2039*/          OPC_CheckComplexPat, /*CP*/1, /*#*/1, // SelectAddrImm:$src #2 #3
/*2042*/          OPC_EmitMergeInputChains1_0,
/*2043*/          OPC_MorphNodeTo, TARGET_VAL(PPC::LFS), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::f32, 2/*#Ops*/, 2, 3, 
                  // Src: (ld:f32 iaddr:iPTR:$src)<<P:Predicate_unindexedload>><<P:Predicate_load>> - Complexity = 13
                  // Dst: (LFS:f32 iaddr:iPTR:$src)
/*2052*/        /*Scope*/ 13, /*->2066*/
/*2053*/          OPC_CheckComplexPat, /*CP*/2, /*#*/1, // SelectAddrIdx:$src #2 #3
/*2056*/          OPC_EmitMergeInputChains1_0,
/*2057*/          OPC_MorphNodeTo, TARGET_VAL(PPC::LFSX), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::f32, 2/*#Ops*/, 2, 3, 
                  // Src: (ld:f32 xaddr:iPTR:$src)<<P:Predicate_unindexedload>><<P:Predicate_load>> - Complexity = 13
                  // Dst: (LFSX:f32 xaddr:iPTR:$src)
/*2066*/        0, /*End of Scope*/
/*2067*/      /*SwitchType*/ 30,  MVT::f64,// ->2099
/*2069*/        OPC_Scope, 13, /*->2084*/ // 2 children in Scope
/*2071*/          OPC_CheckComplexPat, /*CP*/1, /*#*/1, // SelectAddrImm:$src #2 #3
/*2074*/          OPC_EmitMergeInputChains1_0,
/*2075*/          OPC_MorphNodeTo, TARGET_VAL(PPC::LFD), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::f64, 2/*#Ops*/, 2, 3, 
                  // Src: (ld:f64 iaddr:iPTR:$src)<<P:Predicate_unindexedload>><<P:Predicate_load>> - Complexity = 13
                  // Dst: (LFD:f64 iaddr:iPTR:$src)
/*2084*/        /*Scope*/ 13, /*->2098*/
/*2085*/          OPC_CheckComplexPat, /*CP*/2, /*#*/1, // SelectAddrIdx:$src #2 #3
/*2088*/          OPC_EmitMergeInputChains1_0,
/*2089*/          OPC_MorphNodeTo, TARGET_VAL(PPC::LFDX), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::f64, 2/*#Ops*/, 2, 3, 
                  // Src: (ld:f64 xaddr:iPTR:$src)<<P:Predicate_unindexedload>><<P:Predicate_load>> - Complexity = 13
                  // Dst: (LFDX:f64 xaddr:iPTR:$src)
/*2098*/        0, /*End of Scope*/
/*2099*/      0, // EndSwitchType
/*2100*/    /*Scope*/ 60, /*->2161*/
/*2101*/      OPC_CheckPredicate, 11, // Predicate_extload
/*2103*/      OPC_CheckPredicate, 22, // Predicate_extloadf32
/*2105*/      OPC_CheckType, MVT::f64,
/*2107*/      OPC_Scope, 25, /*->2134*/ // 2 children in Scope
/*2109*/        OPC_CheckComplexPat, /*CP*/1, /*#*/1, // SelectAddrImm:$src #2 #3
/*2112*/        OPC_EmitMergeInputChains1_0,
/*2113*/        OPC_EmitNode, TARGET_VAL(PPC::LFS), 0|OPFL_Chain|OPFL_MemRefs,
                    1/*#VTs*/, MVT::f32, 2/*#Ops*/, 2, 3,  // Results = #4
/*2122*/        OPC_EmitInteger, MVT::i32, PPC::F8RCRegClassID,
/*2125*/        OPC_MorphNodeTo, TARGET_VAL(TargetOpcode::COPY_TO_REGCLASS), 0|OPFL_Chain,
                    1/*#VTs*/, MVT::f64, 2/*#Ops*/, 4, 5, 
                // Src: (ld:f64 iaddr:iPTR:$src)<<P:Predicate_unindexedload>><<P:Predicate_extload>><<P:Predicate_extloadf32>> - Complexity = 13
                // Dst: (COPY_TO_REGCLASS:f64 (LFS:f32 iaddr:iPTR:$src), F8RC:i32)
/*2134*/      /*Scope*/ 25, /*->2160*/
/*2135*/        OPC_CheckComplexPat, /*CP*/2, /*#*/1, // SelectAddrIdx:$src #2 #3
/*2138*/        OPC_EmitMergeInputChains1_0,
/*2139*/        OPC_EmitNode, TARGET_VAL(PPC::LFSX), 0|OPFL_Chain|OPFL_MemRefs,
                    1/*#VTs*/, MVT::f32, 2/*#Ops*/, 2, 3,  // Results = #4
/*2148*/        OPC_EmitInteger, MVT::i32, PPC::F8RCRegClassID,
/*2151*/        OPC_MorphNodeTo, TARGET_VAL(TargetOpcode::COPY_TO_REGCLASS), 0|OPFL_Chain,
                    1/*#VTs*/, MVT::f64, 2/*#Ops*/, 4, 5, 
                // Src: (ld:f64 xaddr:iPTR:$src)<<P:Predicate_unindexedload>><<P:Predicate_extload>><<P:Predicate_extloadf32>> - Complexity = 13
                // Dst: (COPY_TO_REGCLASS:f64 (LFSX:f32 xaddr:iPTR:$src), F8RC:i32)
/*2160*/      0, /*End of Scope*/
/*2161*/    /*Scope*/ 19, /*->2181*/
/*2162*/      OPC_CheckPredicate, 9, // Predicate_load
/*2164*/      OPC_CheckType, MVT::v4i32,
/*2166*/      OPC_CheckPatternPredicate, 0, // (PPCSubTarget.hasAltivec())
/*2168*/      OPC_CheckComplexPat, /*CP*/0, /*#*/1, // SelectAddrIdxOnly:$src #2 #3
/*2171*/      OPC_EmitMergeInputChains1_0,
/*2172*/      OPC_MorphNodeTo, TARGET_VAL(PPC::LVX), 0|OPFL_Chain|OPFL_MemRefs,
                  1/*#VTs*/, MVT::v4i32, 2/*#Ops*/, 2, 3, 
              // Src: (ld:v4i32 xoaddr:iPTR:$src)<<P:Predicate_unindexedload>><<P:Predicate_load>> - Complexity = 13
              // Dst: (LVX:v4i32 xoaddr:iPTR:$src)
/*2181*/    0, /*End of Scope*/
/*2182*/  /*SwitchOpcode*/ 87|128,5/*727*/,  TARGET_VAL(ISD::STORE),// ->2913
/*2186*/    OPC_RecordMemRef,
/*2187*/    OPC_RecordNode,   // #0 = 'st' chained node
/*2188*/    OPC_RecordChild1, // #1 = $rS
/*2189*/    OPC_Scope, 103|128,1/*231*/, /*->2423*/ // 5 children in Scope
/*2192*/      OPC_CheckChild1Type, MVT::i32,
/*2194*/      OPC_RecordChild2, // #2 = $src
/*2195*/      OPC_Scope, 110, /*->2307*/ // 2 children in Scope
/*2197*/        OPC_CheckPredicate, 23, // Predicate_unindexedstore
/*2199*/        OPC_Scope, 36, /*->2237*/ // 4 children in Scope
/*2201*/          OPC_CheckPredicate, 24, // Predicate_truncstore
/*2203*/          OPC_Scope, 15, /*->2220*/ // 2 children in Scope
/*2205*/            OPC_CheckPredicate, 25, // Predicate_truncstorei8
/*2207*/            OPC_CheckComplexPat, /*CP*/1, /*#*/2, // SelectAddrImm:$src #3 #4
/*2210*/            OPC_EmitMergeInputChains1_0,
/*2211*/            OPC_MorphNodeTo, TARGET_VAL(PPC::STB), 0|OPFL_Chain|OPFL_MemRefs,
                        0/*#VTs*/, 3/*#Ops*/, 1, 3, 4, 
                    // Src: (st i32:i32:$rS, iaddr:iPTR:$src)<<P:Predicate_unindexedstore>><<P:Predicate_truncstore>><<P:Predicate_truncstorei8>> - Complexity = 13
                    // Dst: (STB i32:i32:$rS, iaddr:iPTR:$src)
/*2220*/          /*Scope*/ 15, /*->2236*/
/*2221*/            OPC_CheckPredicate, 26, // Predicate_truncstorei16
/*2223*/            OPC_CheckComplexPat, /*CP*/1, /*#*/2, // SelectAddrImm:$src #3 #4
/*2226*/            OPC_EmitMergeInputChains1_0,
/*2227*/            OPC_MorphNodeTo, TARGET_VAL(PPC::STH), 0|OPFL_Chain|OPFL_MemRefs,
                        0/*#VTs*/, 3/*#Ops*/, 1, 3, 4, 
                    // Src: (st i32:i32:$rS, iaddr:iPTR:$src)<<P:Predicate_unindexedstore>><<P:Predicate_truncstore>><<P:Predicate_truncstorei16>> - Complexity = 13
                    // Dst: (STH i32:i32:$rS, iaddr:iPTR:$src)
/*2236*/          0, /*End of Scope*/
/*2237*/        /*Scope*/ 15, /*->2253*/
/*2238*/          OPC_CheckPredicate, 27, // Predicate_store
/*2240*/          OPC_CheckComplexPat, /*CP*/1, /*#*/2, // SelectAddrImm:$src #3 #4
/*2243*/          OPC_EmitMergeInputChains1_0,
/*2244*/          OPC_MorphNodeTo, TARGET_VAL(PPC::STW), 0|OPFL_Chain|OPFL_MemRefs,
                      0/*#VTs*/, 3/*#Ops*/, 1, 3, 4, 
                  // Src: (st i32:i32:$rS, iaddr:iPTR:$src)<<P:Predicate_unindexedstore>><<P:Predicate_store>> - Complexity = 13
                  // Dst: (STW i32:i32:$rS, iaddr:iPTR:$src)
/*2253*/        /*Scope*/ 36, /*->2290*/
/*2254*/          OPC_CheckPredicate, 24, // Predicate_truncstore
/*2256*/          OPC_Scope, 15, /*->2273*/ // 2 children in Scope
/*2258*/            OPC_CheckPredicate, 25, // Predicate_truncstorei8
/*2260*/            OPC_CheckComplexPat, /*CP*/2, /*#*/2, // SelectAddrIdx:$dst #3 #4
/*2263*/            OPC_EmitMergeInputChains1_0,
/*2264*/            OPC_MorphNodeTo, TARGET_VAL(PPC::STBX), 0|OPFL_Chain|OPFL_MemRefs,
                        0/*#VTs*/, 3/*#Ops*/, 1, 3, 4, 
                    // Src: (st i32:i32:$rS, xaddr:iPTR:$dst)<<P:Predicate_unindexedstore>><<P:Predicate_truncstore>><<P:Predicate_truncstorei8>> - Complexity = 13
                    // Dst: (STBX i32:i32:$rS, xaddr:iPTR:$dst)
/*2273*/          /*Scope*/ 15, /*->2289*/
/*2274*/            OPC_CheckPredicate, 26, // Predicate_truncstorei16
/*2276*/            OPC_CheckComplexPat, /*CP*/2, /*#*/2, // SelectAddrIdx:$dst #3 #4
/*2279*/            OPC_EmitMergeInputChains1_0,
/*2280*/            OPC_MorphNodeTo, TARGET_VAL(PPC::STHX), 0|OPFL_Chain|OPFL_MemRefs,
                        0/*#VTs*/, 3/*#Ops*/, 1, 3, 4, 
                    // Src: (st i32:i32:$rS, xaddr:iPTR:$dst)<<P:Predicate_unindexedstore>><<P:Predicate_truncstore>><<P:Predicate_truncstorei16>> - Complexity = 13
                    // Dst: (STHX i32:i32:$rS, xaddr:iPTR:$dst)
/*2289*/          0, /*End of Scope*/
/*2290*/        /*Scope*/ 15, /*->2306*/
/*2291*/          OPC_CheckPredicate, 27, // Predicate_store
/*2293*/          OPC_CheckComplexPat, /*CP*/2, /*#*/2, // SelectAddrIdx:$dst #3 #4
/*2296*/          OPC_EmitMergeInputChains1_0,
/*2297*/          OPC_MorphNodeTo, TARGET_VAL(PPC::STWX), 0|OPFL_Chain|OPFL_MemRefs,
                      0/*#VTs*/, 3/*#Ops*/, 1, 3, 4, 
                  // Src: (st i32:i32:$rS, xaddr:iPTR:$dst)<<P:Predicate_unindexedstore>><<P:Predicate_store>> - Complexity = 13
                  // Dst: (STWX i32:i32:$rS, xaddr:iPTR:$dst)
/*2306*/        0, /*End of Scope*/
/*2307*/      /*Scope*/ 114, /*->2422*/
/*2308*/        OPC_RecordChild3, // #3 = $ptroff
/*2309*/        OPC_Scope, 40, /*->2351*/ // 4 children in Scope
/*2311*/          OPC_CheckPredicate, 28, // Predicate_itruncstore
/*2313*/          OPC_CheckPredicate, 29, // Predicate_pre_truncst
/*2315*/          OPC_Scope, 16, /*->2333*/ // 2 children in Scope
/*2317*/            OPC_CheckPredicate, 30, // Predicate_pre_truncsti8
/*2319*/            OPC_CheckComplexPat, /*CP*/4, /*#*/3, // SelectAddrImmOffs:$ptroff #4
/*2322*/            OPC_EmitMergeInputChains1_0,
/*2323*/            OPC_MorphNodeTo, TARGET_VAL(PPC::STBU), 0|OPFL_Chain|OPFL_MemRefs,
                        1/*#VTs*/, MVT::iPTR, 3/*#Ops*/, 1, 4, 2, 
                    // Src: (ist:iPTR i32:i32:$rS, iPTR:iPTR:$ptrreg, iaddroff:iPTR:$ptroff)<<P:Predicate_itruncstore>><<P:Predicate_pre_truncst>><<P:Predicate_pre_truncsti8>> - Complexity = 10
                    // Dst: (STBU:iPTR ?:i32:$rS, iaddroff:iPTR:$ptroff, ?:iPTR:$ptrreg)
/*2333*/          /*Scope*/ 16, /*->2350*/
/*2334*/            OPC_CheckPredicate, 31, // Predicate_pre_truncsti16
/*2336*/            OPC_CheckComplexPat, /*CP*/4, /*#*/3, // SelectAddrImmOffs:$ptroff #4
/*2339*/            OPC_EmitMergeInputChains1_0,
/*2340*/            OPC_MorphNodeTo, TARGET_VAL(PPC::STHU), 0|OPFL_Chain|OPFL_MemRefs,
                        1/*#VTs*/, MVT::iPTR, 3/*#Ops*/, 1, 4, 2, 
                    // Src: (ist:iPTR i32:i32:$rS, iPTR:iPTR:$ptrreg, iaddroff:iPTR:$ptroff)<<P:Predicate_itruncstore>><<P:Predicate_pre_truncst>><<P:Predicate_pre_truncsti16>> - Complexity = 10
                    // Dst: (STHU:iPTR ?:i32:$rS, iaddroff:iPTR:$ptroff, ?:iPTR:$ptrreg)
/*2350*/          0, /*End of Scope*/
/*2351*/        /*Scope*/ 18, /*->2370*/
/*2352*/          OPC_CheckPredicate, 32, // Predicate_istore
/*2354*/          OPC_CheckPredicate, 33, // Predicate_pre_store
/*2356*/          OPC_CheckComplexPat, /*CP*/4, /*#*/3, // SelectAddrImmOffs:$ptroff #4
/*2359*/          OPC_EmitMergeInputChains1_0,
/*2360*/          OPC_MorphNodeTo, TARGET_VAL(PPC::STWU), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::iPTR, 3/*#Ops*/, 1, 4, 2, 
                  // Src: (ist:iPTR i32:i32:$rS, iPTR:iPTR:$ptrreg, iaddroff:iPTR:$ptroff)<<P:Predicate_istore>><<P:Predicate_pre_store>> - Complexity = 10
                  // Dst: (STWU:iPTR ?:i32:$rS, iaddroff:iPTR:$ptroff, ?:iPTR:$ptrreg)
/*2370*/        /*Scope*/ 34, /*->2405*/
/*2371*/          OPC_CheckPredicate, 28, // Predicate_itruncstore
/*2373*/          OPC_CheckPredicate, 29, // Predicate_pre_truncst
/*2375*/          OPC_Scope, 13, /*->2390*/ // 2 children in Scope
/*2377*/            OPC_CheckPredicate, 30, // Predicate_pre_truncsti8
/*2379*/            OPC_EmitMergeInputChains1_0,
/*2380*/            OPC_MorphNodeTo, TARGET_VAL(PPC::STBUX), 0|OPFL_Chain|OPFL_MemRefs,
                        1/*#VTs*/, MVT::iPTR, 3/*#Ops*/, 1, 2, 3, 
                    // Src: (ist:iPTR i32:i32:$rS, iPTR:iPTR:$ptrreg, iPTR:iPTR:$ptroff)<<P:Predicate_itruncstore>><<P:Predicate_pre_truncst>><<P:Predicate_pre_truncsti8>> - Complexity = 4
                    // Dst: (STBUX:iPTR ?:i32:$rS, ?:iPTR:$ptrreg, ?:iPTR:$ptroff)
/*2390*/          /*Scope*/ 13, /*->2404*/
/*2391*/            OPC_CheckPredicate, 31, // Predicate_pre_truncsti16
/*2393*/            OPC_EmitMergeInputChains1_0,
/*2394*/            OPC_MorphNodeTo, TARGET_VAL(PPC::STHUX), 0|OPFL_Chain|OPFL_MemRefs,
                        1/*#VTs*/, MVT::iPTR, 3/*#Ops*/, 1, 2, 3, 
                    // Src: (ist:iPTR i32:i32:$rS, iPTR:iPTR:$ptrreg, iPTR:iPTR:$ptroff)<<P:Predicate_itruncstore>><<P:Predicate_pre_truncst>><<P:Predicate_pre_truncsti16>> - Complexity = 4
                    // Dst: (STHUX:iPTR ?:i32:$rS, ?:iPTR:$ptrreg, ?:iPTR:$ptroff)
/*2404*/          0, /*End of Scope*/
/*2405*/        /*Scope*/ 15, /*->2421*/
/*2406*/          OPC_CheckPredicate, 32, // Predicate_istore
/*2408*/          OPC_CheckPredicate, 33, // Predicate_pre_store
/*2410*/          OPC_EmitMergeInputChains1_0,
/*2411*/          OPC_MorphNodeTo, TARGET_VAL(PPC::STWUX), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::iPTR, 3/*#Ops*/, 1, 2, 3, 
                  // Src: (ist:iPTR i32:i32:$rS, iPTR:iPTR:$ptrreg, iPTR:iPTR:$ptroff)<<P:Predicate_istore>><<P:Predicate_pre_store>> - Complexity = 4
                  // Dst: (STWUX:iPTR ?:i32:$rS, ?:iPTR:$ptrreg, ?:iPTR:$ptroff)
/*2421*/        0, /*End of Scope*/
/*2422*/      0, /*End of Scope*/
/*2423*/    /*Scope*/ 75, /*->2499*/
/*2424*/      OPC_CheckChild1Type, MVT::f32,
/*2426*/      OPC_RecordChild2, // #2 = $dst
/*2427*/      OPC_Scope, 34, /*->2463*/ // 2 children in Scope
/*2429*/        OPC_CheckPredicate, 23, // Predicate_unindexedstore
/*2431*/        OPC_CheckPredicate, 27, // Predicate_store
/*2433*/        OPC_Scope, 13, /*->2448*/ // 2 children in Scope
/*2435*/          OPC_CheckComplexPat, /*CP*/1, /*#*/2, // SelectAddrImm:$dst #3 #4
/*2438*/          OPC_EmitMergeInputChains1_0,
/*2439*/          OPC_MorphNodeTo, TARGET_VAL(PPC::STFS), 0|OPFL_Chain|OPFL_MemRefs,
                      0/*#VTs*/, 3/*#Ops*/, 1, 3, 4, 
                  // Src: (st f32:f32:$rS, iaddr:iPTR:$dst)<<P:Predicate_unindexedstore>><<P:Predicate_store>> - Complexity = 13
                  // Dst: (STFS f32:f32:$rS, iaddr:iPTR:$dst)
/*2448*/        /*Scope*/ 13, /*->2462*/
/*2449*/          OPC_CheckComplexPat, /*CP*/2, /*#*/2, // SelectAddrIdx:$dst #3 #4
/*2452*/          OPC_EmitMergeInputChains1_0,
/*2453*/          OPC_MorphNodeTo, TARGET_VAL(PPC::STFSX), 0|OPFL_Chain|OPFL_MemRefs,
                      0/*#VTs*/, 3/*#Ops*/, 1, 3, 4, 
                  // Src: (st f32:f32:$frS, xaddr:iPTR:$dst)<<P:Predicate_unindexedstore>><<P:Predicate_store>> - Complexity = 13
                  // Dst: (STFSX f32:f32:$frS, xaddr:iPTR:$dst)
/*2462*/        0, /*End of Scope*/
/*2463*/      /*Scope*/ 34, /*->2498*/
/*2464*/        OPC_RecordChild3, // #3 = $ptroff
/*2465*/        OPC_CheckPredicate, 32, // Predicate_istore
/*2467*/        OPC_CheckPredicate, 33, // Predicate_pre_store
/*2469*/        OPC_Scope, 14, /*->2485*/ // 2 children in Scope
/*2471*/          OPC_CheckComplexPat, /*CP*/4, /*#*/3, // SelectAddrImmOffs:$ptroff #4
/*2474*/          OPC_EmitMergeInputChains1_0,
/*2475*/          OPC_MorphNodeTo, TARGET_VAL(PPC::STFSU), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::iPTR, 3/*#Ops*/, 1, 4, 2, 
                  // Src: (ist:iPTR f32:f32:$rS, iPTR:iPTR:$ptrreg, iaddroff:iPTR:$ptroff)<<P:Predicate_istore>><<P:Predicate_pre_store>> - Complexity = 10
                  // Dst: (STFSU:iPTR ?:f32:$rS, iaddroff:iPTR:$ptroff, ?:iPTR:$ptrreg)
/*2485*/        /*Scope*/ 11, /*->2497*/
/*2486*/          OPC_EmitMergeInputChains1_0,
/*2487*/          OPC_MorphNodeTo, TARGET_VAL(PPC::STFSUX), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::iPTR, 3/*#Ops*/, 1, 2, 3, 
                  // Src: (ist:iPTR f32:f32:$rS, iPTR:iPTR:$ptrreg, iPTR:iPTR:$ptroff)<<P:Predicate_istore>><<P:Predicate_pre_store>> - Complexity = 4
                  // Dst: (STFSUX:iPTR ?:f32:$rS, ?:iPTR:$ptrreg, ?:iPTR:$ptroff)
/*2497*/        0, /*End of Scope*/
/*2498*/      0, /*End of Scope*/
/*2499*/    /*Scope*/ 75, /*->2575*/
/*2500*/      OPC_CheckChild1Type, MVT::f64,
/*2502*/      OPC_RecordChild2, // #2 = $dst
/*2503*/      OPC_Scope, 34, /*->2539*/ // 2 children in Scope
/*2505*/        OPC_CheckPredicate, 23, // Predicate_unindexedstore
/*2507*/        OPC_CheckPredicate, 27, // Predicate_store
/*2509*/        OPC_Scope, 13, /*->2524*/ // 2 children in Scope
/*2511*/          OPC_CheckComplexPat, /*CP*/1, /*#*/2, // SelectAddrImm:$dst #3 #4
/*2514*/          OPC_EmitMergeInputChains1_0,
/*2515*/          OPC_MorphNodeTo, TARGET_VAL(PPC::STFD), 0|OPFL_Chain|OPFL_MemRefs,
                      0/*#VTs*/, 3/*#Ops*/, 1, 3, 4, 
                  // Src: (st f64:f64:$rS, iaddr:iPTR:$dst)<<P:Predicate_unindexedstore>><<P:Predicate_store>> - Complexity = 13
                  // Dst: (STFD f64:f64:$rS, iaddr:iPTR:$dst)
/*2524*/        /*Scope*/ 13, /*->2538*/
/*2525*/          OPC_CheckComplexPat, /*CP*/2, /*#*/2, // SelectAddrIdx:$dst #3 #4
/*2528*/          OPC_EmitMergeInputChains1_0,
/*2529*/          OPC_MorphNodeTo, TARGET_VAL(PPC::STFDX), 0|OPFL_Chain|OPFL_MemRefs,
                      0/*#VTs*/, 3/*#Ops*/, 1, 3, 4, 
                  // Src: (st f64:f64:$frS, xaddr:iPTR:$dst)<<P:Predicate_unindexedstore>><<P:Predicate_store>> - Complexity = 13
                  // Dst: (STFDX f64:f64:$frS, xaddr:iPTR:$dst)
/*2538*/        0, /*End of Scope*/
/*2539*/      /*Scope*/ 34, /*->2574*/
/*2540*/        OPC_RecordChild3, // #3 = $ptroff
/*2541*/        OPC_CheckPredicate, 32, // Predicate_istore
/*2543*/        OPC_CheckPredicate, 33, // Predicate_pre_store
/*2545*/        OPC_Scope, 14, /*->2561*/ // 2 children in Scope
/*2547*/          OPC_CheckComplexPat, /*CP*/4, /*#*/3, // SelectAddrImmOffs:$ptroff #4
/*2550*/          OPC_EmitMergeInputChains1_0,
/*2551*/          OPC_MorphNodeTo, TARGET_VAL(PPC::STFDU), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::iPTR, 3/*#Ops*/, 1, 4, 2, 
                  // Src: (ist:iPTR f64:f64:$rS, iPTR:iPTR:$ptrreg, iaddroff:iPTR:$ptroff)<<P:Predicate_istore>><<P:Predicate_pre_store>> - Complexity = 10
                  // Dst: (STFDU:iPTR ?:f64:$rS, iaddroff:iPTR:$ptroff, ?:iPTR:$ptrreg)
/*2561*/        /*Scope*/ 11, /*->2573*/
/*2562*/          OPC_EmitMergeInputChains1_0,
/*2563*/          OPC_MorphNodeTo, TARGET_VAL(PPC::STFDUX), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::iPTR, 3/*#Ops*/, 1, 2, 3, 
                  // Src: (ist:iPTR f64:f64:$rS, iPTR:iPTR:$ptrreg, iPTR:iPTR:$ptroff)<<P:Predicate_istore>><<P:Predicate_pre_store>> - Complexity = 4
                  // Dst: (STFDUX:iPTR ?:f64:$rS, ?:iPTR:$ptrreg, ?:iPTR:$ptroff)
/*2573*/        0, /*End of Scope*/
/*2574*/      0, /*End of Scope*/
/*2575*/    /*Scope*/ 22, /*->2598*/
/*2576*/      OPC_CheckChild1Type, MVT::v4i32,
/*2578*/      OPC_RecordChild2, // #2 = $dst
/*2579*/      OPC_CheckPredicate, 23, // Predicate_unindexedstore
/*2581*/      OPC_CheckPredicate, 27, // Predicate_store
/*2583*/      OPC_CheckPatternPredicate, 0, // (PPCSubTarget.hasAltivec())
/*2585*/      OPC_CheckComplexPat, /*CP*/0, /*#*/2, // SelectAddrIdxOnly:$dst #3 #4
/*2588*/      OPC_EmitMergeInputChains1_0,
/*2589*/      OPC_MorphNodeTo, TARGET_VAL(PPC::STVX), 0|OPFL_Chain|OPFL_MemRefs,
                  0/*#VTs*/, 3/*#Ops*/, 1, 3, 4, 
              // Src: (st v4i32:v4i32:$rS, xoaddr:iPTR:$dst)<<P:Predicate_unindexedstore>><<P:Predicate_store>> - Complexity = 13
              // Dst: (STVX ?:v4i32:$rS, xoaddr:iPTR:$dst)
/*2598*/    /*Scope*/ 56|128,2/*312*/, /*->2912*/
/*2600*/      OPC_CheckChild1Type, MVT::i64,
/*2602*/      OPC_RecordChild2, // #2 = $src
/*2603*/      OPC_Scope, 28|128,1/*156*/, /*->2762*/ // 2 children in Scope
/*2606*/        OPC_CheckPredicate, 23, // Predicate_unindexedstore
/*2608*/        OPC_Scope, 100, /*->2710*/ // 2 children in Scope
/*2610*/          OPC_CheckPredicate, 24, // Predicate_truncstore
/*2612*/          OPC_Scope, 15, /*->2629*/ // 6 children in Scope
/*2614*/            OPC_CheckPredicate, 25, // Predicate_truncstorei8
/*2616*/            OPC_CheckComplexPat, /*CP*/1, /*#*/2, // SelectAddrImm:$src #3 #4
/*2619*/            OPC_EmitMergeInputChains1_0,
/*2620*/            OPC_MorphNodeTo, TARGET_VAL(PPC::STB8), 0|OPFL_Chain|OPFL_MemRefs,
                        0/*#VTs*/, 3/*#Ops*/, 1, 3, 4, 
                    // Src: (st i64:i64:$rS, iaddr:iPTR:$src)<<P:Predicate_unindexedstore>><<P:Predicate_truncstore>><<P:Predicate_truncstorei8>> - Complexity = 13
                    // Dst: (STB8 i64:i64:$rS, iaddr:iPTR:$src)
/*2629*/          /*Scope*/ 15, /*->2645*/
/*2630*/            OPC_CheckPredicate, 26, // Predicate_truncstorei16
/*2632*/            OPC_CheckComplexPat, /*CP*/1, /*#*/2, // SelectAddrImm:$src #3 #4
/*2635*/            OPC_EmitMergeInputChains1_0,
/*2636*/            OPC_MorphNodeTo, TARGET_VAL(PPC::STH8), 0|OPFL_Chain|OPFL_MemRefs,
                        0/*#VTs*/, 3/*#Ops*/, 1, 3, 4, 
                    // Src: (st i64:i64:$rS, iaddr:iPTR:$src)<<P:Predicate_unindexedstore>><<P:Predicate_truncstore>><<P:Predicate_truncstorei16>> - Complexity = 13
                    // Dst: (STH8 i64:i64:$rS, iaddr:iPTR:$src)
/*2645*/          /*Scope*/ 15, /*->2661*/
/*2646*/            OPC_CheckPredicate, 34, // Predicate_truncstorei32
/*2648*/            OPC_CheckComplexPat, /*CP*/1, /*#*/2, // SelectAddrImm:$src #3 #4
/*2651*/            OPC_EmitMergeInputChains1_0,
/*2652*/            OPC_MorphNodeTo, TARGET_VAL(PPC::STW8), 0|OPFL_Chain|OPFL_MemRefs,
                        0/*#VTs*/, 3/*#Ops*/, 1, 3, 4, 
                    // Src: (st i64:i64:$rS, iaddr:iPTR:$src)<<P:Predicate_unindexedstore>><<P:Predicate_truncstore>><<P:Predicate_truncstorei32>> - Complexity = 13
                    // Dst: (STW8 i64:i64:$rS, iaddr:iPTR:$src)
/*2661*/          /*Scope*/ 15, /*->2677*/
/*2662*/            OPC_CheckPredicate, 25, // Predicate_truncstorei8
/*2664*/            OPC_CheckComplexPat, /*CP*/2, /*#*/2, // SelectAddrIdx:$dst #3 #4
/*2667*/            OPC_EmitMergeInputChains1_0,
/*2668*/            OPC_MorphNodeTo, TARGET_VAL(PPC::STBX8), 0|OPFL_Chain|OPFL_MemRefs,
                        0/*#VTs*/, 3/*#Ops*/, 1, 3, 4, 
                    // Src: (st i64:i64:$rS, xaddr:iPTR:$dst)<<P:Predicate_unindexedstore>><<P:Predicate_truncstore>><<P:Predicate_truncstorei8>> - Complexity = 13
                    // Dst: (STBX8 i64:i64:$rS, xaddr:iPTR:$dst)
/*2677*/          /*Scope*/ 15, /*->2693*/
/*2678*/            OPC_CheckPredicate, 26, // Predicate_truncstorei16
/*2680*/            OPC_CheckComplexPat, /*CP*/2, /*#*/2, // SelectAddrIdx:$dst #3 #4
/*2683*/            OPC_EmitMergeInputChains1_0,
/*2684*/            OPC_MorphNodeTo, TARGET_VAL(PPC::STHX8), 0|OPFL_Chain|OPFL_MemRefs,
                        0/*#VTs*/, 3/*#Ops*/, 1, 3, 4, 
                    // Src: (st i64:i64:$rS, xaddr:iPTR:$dst)<<P:Predicate_unindexedstore>><<P:Predicate_truncstore>><<P:Predicate_truncstorei16>> - Complexity = 13
                    // Dst: (STHX8 i64:i64:$rS, xaddr:iPTR:$dst)
/*2693*/          /*Scope*/ 15, /*->2709*/
/*2694*/            OPC_CheckPredicate, 34, // Predicate_truncstorei32
/*2696*/            OPC_CheckComplexPat, /*CP*/2, /*#*/2, // SelectAddrIdx:$dst #3 #4
/*2699*/            OPC_EmitMergeInputChains1_0,
/*2700*/            OPC_MorphNodeTo, TARGET_VAL(PPC::STWX8), 0|OPFL_Chain|OPFL_MemRefs,
                        0/*#VTs*/, 3/*#Ops*/, 1, 3, 4, 
                    // Src: (st i64:i64:$rS, xaddr:iPTR:$dst)<<P:Predicate_unindexedstore>><<P:Predicate_truncstore>><<P:Predicate_truncstorei32>> - Complexity = 13
                    // Dst: (STWX8 i64:i64:$rS, xaddr:iPTR:$dst)
/*2709*/          0, /*End of Scope*/
/*2710*/        /*Scope*/ 50, /*->2761*/
/*2711*/          OPC_CheckPredicate, 27, // Predicate_store
/*2713*/          OPC_Scope, 15, /*->2730*/ // 3 children in Scope
/*2715*/            OPC_CheckPredicate, 35, // Predicate_aligned4store
/*2717*/            OPC_CheckComplexPat, /*CP*/3, /*#*/2, // SelectAddrImmX4:$dst #3 #4
/*2720*/            OPC_EmitMergeInputChains1_0,
/*2721*/            OPC_MorphNodeTo, TARGET_VAL(PPC::STD), 0|OPFL_Chain|OPFL_MemRefs,
                        0/*#VTs*/, 3/*#Ops*/, 1, 3, 4, 
                    // Src: (st i64:i64:$rS, ixaddr:iPTR:$dst)<<P:Predicate_unindexedstore>><<P:Predicate_store>><<P:Predicate_aligned4store>> - Complexity = 13
                    // Dst: (STD i64:i64:$rS, ixaddr:iPTR:$dst)
/*2730*/          /*Scope*/ 13, /*->2744*/
/*2731*/            OPC_CheckComplexPat, /*CP*/2, /*#*/2, // SelectAddrIdx:$dst #3 #4
/*2734*/            OPC_EmitMergeInputChains1_0,
/*2735*/            OPC_MorphNodeTo, TARGET_VAL(PPC::STDX), 0|OPFL_Chain|OPFL_MemRefs,
                        0/*#VTs*/, 3/*#Ops*/, 1, 3, 4, 
                    // Src: (st i64:i64:$rS, xaddr:iPTR:$dst)<<P:Predicate_unindexedstore>><<P:Predicate_store>> - Complexity = 13
                    // Dst: (STDX i64:i64:$rS, xaddr:iPTR:$dst)
/*2744*/          /*Scope*/ 15, /*->2760*/
/*2745*/            OPC_CheckPredicate, 36, // Predicate_unaligned4store
/*2747*/            OPC_CheckComplexPat, /*CP*/0, /*#*/2, // SelectAddrIdxOnly:$dst #3 #4
/*2750*/            OPC_EmitMergeInputChains1_0,
/*2751*/            OPC_MorphNodeTo, TARGET_VAL(PPC::STDX), 0|OPFL_Chain|OPFL_MemRefs,
                        0/*#VTs*/, 3/*#Ops*/, 1, 3, 4, 
                    // Src: (st i64:i64:$rS, xoaddr:iPTR:$dst)<<P:Predicate_unindexedstore>><<P:Predicate_store>><<P:Predicate_unaligned4store>> - Complexity = 13
                    // Dst: (STDX ?:i64:$rS, xoaddr:iPTR:$dst)
/*2760*/          0, /*End of Scope*/
/*2761*/        0, /*End of Scope*/
/*2762*/      /*Scope*/ 19|128,1/*147*/, /*->2911*/
/*2764*/        OPC_RecordChild3, // #3 = $ptroff
/*2765*/        OPC_Scope, 57, /*->2824*/ // 4 children in Scope
/*2767*/          OPC_CheckPredicate, 28, // Predicate_itruncstore
/*2769*/          OPC_CheckPredicate, 29, // Predicate_pre_truncst
/*2771*/          OPC_Scope, 16, /*->2789*/ // 3 children in Scope
/*2773*/            OPC_CheckPredicate, 30, // Predicate_pre_truncsti8
/*2775*/            OPC_CheckComplexPat, /*CP*/4, /*#*/3, // SelectAddrImmOffs:$ptroff #4
/*2778*/            OPC_EmitMergeInputChains1_0,
/*2779*/            OPC_MorphNodeTo, TARGET_VAL(PPC::STBU8), 0|OPFL_Chain|OPFL_MemRefs,
                        1/*#VTs*/, MVT::iPTR, 3/*#Ops*/, 1, 4, 2, 
                    // Src: (ist:iPTR i64:i64:$rS, iPTR:iPTR:$ptrreg, iaddroff:iPTR:$ptroff)<<P:Predicate_itruncstore>><<P:Predicate_pre_truncst>><<P:Predicate_pre_truncsti8>> - Complexity = 10
                    // Dst: (STBU8:iPTR ?:i64:$rS, iaddroff:iPTR:$ptroff, ?:iPTR:$ptrreg)
/*2789*/          /*Scope*/ 16, /*->2806*/
/*2790*/            OPC_CheckPredicate, 31, // Predicate_pre_truncsti16
/*2792*/            OPC_CheckComplexPat, /*CP*/4, /*#*/3, // SelectAddrImmOffs:$ptroff #4
/*2795*/            OPC_EmitMergeInputChains1_0,
/*2796*/            OPC_MorphNodeTo, TARGET_VAL(PPC::STHU8), 0|OPFL_Chain|OPFL_MemRefs,
                        1/*#VTs*/, MVT::iPTR, 3/*#Ops*/, 1, 4, 2, 
                    // Src: (ist:iPTR i64:i64:$rS, iPTR:iPTR:$ptrreg, iaddroff:iPTR:$ptroff)<<P:Predicate_itruncstore>><<P:Predicate_pre_truncst>><<P:Predicate_pre_truncsti16>> - Complexity = 10
                    // Dst: (STHU8:iPTR ?:i64:$rS, iaddroff:iPTR:$ptroff, ?:iPTR:$ptrreg)
/*2806*/          /*Scope*/ 16, /*->2823*/
/*2807*/            OPC_CheckPredicate, 37, // Predicate_pre_truncsti32
/*2809*/            OPC_CheckComplexPat, /*CP*/4, /*#*/3, // SelectAddrImmOffs:$ptroff #4
/*2812*/            OPC_EmitMergeInputChains1_0,
/*2813*/            OPC_MorphNodeTo, TARGET_VAL(PPC::STWU8), 0|OPFL_Chain|OPFL_MemRefs,
                        1/*#VTs*/, MVT::iPTR, 3/*#Ops*/, 1, 4, 2, 
                    // Src: (ist:iPTR i64:i64:$rS, iPTR:iPTR:$ptrreg, iaddroff:iPTR:$ptroff)<<P:Predicate_itruncstore>><<P:Predicate_pre_truncst>><<P:Predicate_pre_truncsti32>> - Complexity = 10
                    // Dst: (STWU8:iPTR ?:i64:$rS, iaddroff:iPTR:$ptroff, ?:iPTR:$ptrreg)
/*2823*/          0, /*End of Scope*/
/*2824*/        /*Scope*/ 20, /*->2845*/
/*2825*/          OPC_CheckPredicate, 32, // Predicate_istore
/*2827*/          OPC_CheckPredicate, 33, // Predicate_pre_store
/*2829*/          OPC_CheckPredicate, 38, // Predicate_aligned4pre_store
/*2831*/          OPC_CheckComplexPat, /*CP*/4, /*#*/3, // SelectAddrImmOffs:$ptroff #4
/*2834*/          OPC_EmitMergeInputChains1_0,
/*2835*/          OPC_MorphNodeTo, TARGET_VAL(PPC::STDU), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::iPTR, 3/*#Ops*/, 1, 4, 2, 
                  // Src: (ist:iPTR i64:i64:$rS, iPTR:iPTR:$ptrreg, iaddroff:iPTR:$ptroff)<<P:Predicate_istore>><<P:Predicate_pre_store>><<P:Predicate_aligned4pre_store>> - Complexity = 10
                  // Dst: (STDU:iPTR ?:i64:$rS, iaddroff:iPTR:$ptroff, ?:iPTR:$ptrreg)
/*2845*/        /*Scope*/ 48, /*->2894*/
/*2846*/          OPC_CheckPredicate, 28, // Predicate_itruncstore
/*2848*/          OPC_CheckPredicate, 29, // Predicate_pre_truncst
/*2850*/          OPC_Scope, 13, /*->2865*/ // 3 children in Scope
/*2852*/            OPC_CheckPredicate, 30, // Predicate_pre_truncsti8
/*2854*/            OPC_EmitMergeInputChains1_0,
/*2855*/            OPC_MorphNodeTo, TARGET_VAL(PPC::STBUX8), 0|OPFL_Chain|OPFL_MemRefs,
                        1/*#VTs*/, MVT::iPTR, 3/*#Ops*/, 1, 2, 3, 
                    // Src: (ist:iPTR i64:i64:$rS, iPTR:iPTR:$ptrreg, iPTR:iPTR:$ptroff)<<P:Predicate_itruncstore>><<P:Predicate_pre_truncst>><<P:Predicate_pre_truncsti8>> - Complexity = 4
                    // Dst: (STBUX8:iPTR ?:i64:$rS, ?:iPTR:$ptrreg, ?:iPTR:$ptroff)
/*2865*/          /*Scope*/ 13, /*->2879*/
/*2866*/            OPC_CheckPredicate, 31, // Predicate_pre_truncsti16
/*2868*/            OPC_EmitMergeInputChains1_0,
/*2869*/            OPC_MorphNodeTo, TARGET_VAL(PPC::STHUX8), 0|OPFL_Chain|OPFL_MemRefs,
                        1/*#VTs*/, MVT::iPTR, 3/*#Ops*/, 1, 2, 3, 
                    // Src: (ist:iPTR i64:i64:$rS, iPTR:iPTR:$ptrreg, iPTR:iPTR:$ptroff)<<P:Predicate_itruncstore>><<P:Predicate_pre_truncst>><<P:Predicate_pre_truncsti16>> - Complexity = 4
                    // Dst: (STHUX8:iPTR ?:i64:$rS, ?:iPTR:$ptrreg, ?:iPTR:$ptroff)
/*2879*/          /*Scope*/ 13, /*->2893*/
/*2880*/            OPC_CheckPredicate, 37, // Predicate_pre_truncsti32
/*2882*/            OPC_EmitMergeInputChains1_0,
/*2883*/            OPC_MorphNodeTo, TARGET_VAL(PPC::STWUX8), 0|OPFL_Chain|OPFL_MemRefs,
                        1/*#VTs*/, MVT::iPTR, 3/*#Ops*/, 1, 2, 3, 
                    // Src: (ist:iPTR i64:i64:$rS, iPTR:iPTR:$ptrreg, iPTR:iPTR:$ptroff)<<P:Predicate_itruncstore>><<P:Predicate_pre_truncst>><<P:Predicate_pre_truncsti32>> - Complexity = 4
                    // Dst: (STWUX8:iPTR ?:i64:$rS, ?:iPTR:$ptrreg, ?:iPTR:$ptroff)
/*2893*/          0, /*End of Scope*/
/*2894*/        /*Scope*/ 15, /*->2910*/
/*2895*/          OPC_CheckPredicate, 32, // Predicate_istore
/*2897*/          OPC_CheckPredicate, 33, // Predicate_pre_store
/*2899*/          OPC_EmitMergeInputChains1_0,
/*2900*/          OPC_MorphNodeTo, TARGET_VAL(PPC::STDUX), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::iPTR, 3/*#Ops*/, 1, 2, 3, 
                  // Src: (ist:iPTR i64:i64:$rS, iPTR:iPTR:$ptrreg, iPTR:iPTR:$ptroff)<<P:Predicate_istore>><<P:Predicate_pre_store>> - Complexity = 4
                  // Dst: (STDUX:iPTR ?:i64:$rS, ?:iPTR:$ptrreg, ?:iPTR:$ptroff)
/*2910*/        0, /*End of Scope*/
/*2911*/      0, /*End of Scope*/
/*2912*/    0, /*End of Scope*/
/*2913*/  /*SwitchOpcode*/ 83,  TARGET_VAL(ISD::ATOMIC_LOAD_ADD),// ->2999
/*2916*/    OPC_RecordMemRef,
/*2917*/    OPC_RecordNode,   // #0 = 'atomic_load_add' chained node
/*2918*/    OPC_RecordChild1, // #1 = $ptr
/*2919*/    OPC_RecordChild2, // #2 = $incr
/*2920*/    OPC_SwitchType /*2 cases */, 56,  MVT::i32,// ->2979
/*2923*/      OPC_Scope, 17, /*->2942*/ // 3 children in Scope
/*2925*/        OPC_CheckPredicate, 39, // Predicate_atomic_load_add_8
/*2927*/        OPC_CheckComplexPat, /*CP*/0, /*#*/1, // SelectAddrIdxOnly:$ptr #3 #4
/*2930*/        OPC_EmitMergeInputChains1_0,
/*2931*/        OPC_MorphNodeTo, TARGET_VAL(PPC::ATOMIC_LOAD_ADD_I8), 0|OPFL_Chain|OPFL_MemRefs,
                    2/*#VTs*/, MVT::i32, MVT::i32, 3/*#Ops*/, 3, 4, 2, 
                // Src: (atomic_load_add:i32 xoaddr:iPTR:$ptr, i32:i32:$incr)<<P:Predicate_atomic_load_add_8>> - Complexity = 13
                // Dst: (ATOMIC_LOAD_ADD_I8:i32:i32 xoaddr:iPTR:$ptr, i32:i32:$incr)
/*2942*/      /*Scope*/ 17, /*->2960*/
/*2943*/        OPC_CheckPredicate, 40, // Predicate_atomic_load_add_16
/*2945*/        OPC_CheckComplexPat, /*CP*/0, /*#*/1, // SelectAddrIdxOnly:$ptr #3 #4
/*2948*/        OPC_EmitMergeInputChains1_0,
/*2949*/        OPC_MorphNodeTo, TARGET_VAL(PPC::ATOMIC_LOAD_ADD_I16), 0|OPFL_Chain|OPFL_MemRefs,
                    2/*#VTs*/, MVT::i32, MVT::i32, 3/*#Ops*/, 3, 4, 2, 
                // Src: (atomic_load_add:i32 xoaddr:iPTR:$ptr, i32:i32:$incr)<<P:Predicate_atomic_load_add_16>> - Complexity = 13
                // Dst: (ATOMIC_LOAD_ADD_I16:i32:i32 xoaddr:iPTR:$ptr, i32:i32:$incr)
/*2960*/      /*Scope*/ 17, /*->2978*/
/*2961*/        OPC_CheckPredicate, 41, // Predicate_atomic_load_add_32
/*2963*/        OPC_CheckComplexPat, /*CP*/0, /*#*/1, // SelectAddrIdxOnly:$ptr #3 #4
/*2966*/        OPC_EmitMergeInputChains1_0,
/*2967*/        OPC_MorphNodeTo, TARGET_VAL(PPC::ATOMIC_LOAD_ADD_I32), 0|OPFL_Chain|OPFL_MemRefs,
                    2/*#VTs*/, MVT::i32, MVT::i32, 3/*#Ops*/, 3, 4, 2, 
                // Src: (atomic_load_add:i32 xoaddr:iPTR:$ptr, i32:i32:$incr)<<P:Predicate_atomic_load_add_32>> - Complexity = 13
                // Dst: (ATOMIC_LOAD_ADD_I32:i32:i32 xoaddr:iPTR:$ptr, i32:i32:$incr)
/*2978*/      0, /*End of Scope*/
/*2979*/    /*SwitchType*/ 17,  MVT::i64,// ->2998
/*2981*/      OPC_CheckPredicate, 42, // Predicate_atomic_load_add_64
/*2983*/      OPC_CheckComplexPat, /*CP*/0, /*#*/1, // SelectAddrIdxOnly:$ptr #3 #4
/*2986*/      OPC_EmitMergeInputChains1_0,
/*2987*/      OPC_MorphNodeTo, TARGET_VAL(PPC::ATOMIC_LOAD_ADD_I64), 0|OPFL_Chain|OPFL_MemRefs,
                  2/*#VTs*/, MVT::i64, MVT::i32, 3/*#Ops*/, 3, 4, 2, 
              // Src: (atomic_load_add:i64 xoaddr:iPTR:$ptr, i64:i64:$incr)<<P:Predicate_atomic_load_add_64>> - Complexity = 13
              // Dst: (ATOMIC_LOAD_ADD_I64:i64:i32 xoaddr:iPTR:$ptr, i64:i64:$incr)
/*2998*/    0, // EndSwitchType
/*2999*/  /*SwitchOpcode*/ 83,  TARGET_VAL(ISD::ATOMIC_LOAD_SUB),// ->3085
/*3002*/    OPC_RecordMemRef,
/*3003*/    OPC_RecordNode,   // #0 = 'atomic_load_sub' chained node
/*3004*/    OPC_RecordChild1, // #1 = $ptr
/*3005*/    OPC_RecordChild2, // #2 = $incr
/*3006*/    OPC_SwitchType /*2 cases */, 56,  MVT::i32,// ->3065
/*3009*/      OPC_Scope, 17, /*->3028*/ // 3 children in Scope
/*3011*/        OPC_CheckPredicate, 43, // Predicate_atomic_load_sub_8
/*3013*/        OPC_CheckComplexPat, /*CP*/0, /*#*/1, // SelectAddrIdxOnly:$ptr #3 #4
/*3016*/        OPC_EmitMergeInputChains1_0,
/*3017*/        OPC_MorphNodeTo, TARGET_VAL(PPC::ATOMIC_LOAD_SUB_I8), 0|OPFL_Chain|OPFL_MemRefs,
                    2/*#VTs*/, MVT::i32, MVT::i32, 3/*#Ops*/, 3, 4, 2, 
                // Src: (atomic_load_sub:i32 xoaddr:iPTR:$ptr, i32:i32:$incr)<<P:Predicate_atomic_load_sub_8>> - Complexity = 13
                // Dst: (ATOMIC_LOAD_SUB_I8:i32:i32 xoaddr:iPTR:$ptr, i32:i32:$incr)
/*3028*/      /*Scope*/ 17, /*->3046*/
/*3029*/        OPC_CheckPredicate, 44, // Predicate_atomic_load_sub_16
/*3031*/        OPC_CheckComplexPat, /*CP*/0, /*#*/1, // SelectAddrIdxOnly:$ptr #3 #4
/*3034*/        OPC_EmitMergeInputChains1_0,
/*3035*/        OPC_MorphNodeTo, TARGET_VAL(PPC::ATOMIC_LOAD_SUB_I16), 0|OPFL_Chain|OPFL_MemRefs,
                    2/*#VTs*/, MVT::i32, MVT::i32, 3/*#Ops*/, 3, 4, 2, 
                // Src: (atomic_load_sub:i32 xoaddr:iPTR:$ptr, i32:i32:$incr)<<P:Predicate_atomic_load_sub_16>> - Complexity = 13
                // Dst: (ATOMIC_LOAD_SUB_I16:i32:i32 xoaddr:iPTR:$ptr, i32:i32:$incr)
/*3046*/      /*Scope*/ 17, /*->3064*/
/*3047*/        OPC_CheckPredicate, 45, // Predicate_atomic_load_sub_32
/*3049*/        OPC_CheckComplexPat, /*CP*/0, /*#*/1, // SelectAddrIdxOnly:$ptr #3 #4
/*3052*/        OPC_EmitMergeInputChains1_0,
/*3053*/        OPC_MorphNodeTo, TARGET_VAL(PPC::ATOMIC_LOAD_SUB_I32), 0|OPFL_Chain|OPFL_MemRefs,
                    2/*#VTs*/, MVT::i32, MVT::i32, 3/*#Ops*/, 3, 4, 2, 
                // Src: (atomic_load_sub:i32 xoaddr:iPTR:$ptr, i32:i32:$incr)<<P:Predicate_atomic_load_sub_32>> - Complexity = 13
                // Dst: (ATOMIC_LOAD_SUB_I32:i32:i32 xoaddr:iPTR:$ptr, i32:i32:$incr)
/*3064*/      0, /*End of Scope*/
/*3065*/    /*SwitchType*/ 17,  MVT::i64,// ->3084
/*3067*/      OPC_CheckPredicate, 46, // Predicate_atomic_load_sub_64
/*3069*/      OPC_CheckComplexPat, /*CP*/0, /*#*/1, // SelectAddrIdxOnly:$ptr #3 #4
/*3072*/      OPC_EmitMergeInputChains1_0,
/*3073*/      OPC_MorphNodeTo, TARGET_VAL(PPC::ATOMIC_LOAD_SUB_I64), 0|OPFL_Chain|OPFL_MemRefs,
                  2/*#VTs*/, MVT::i64, MVT::i32, 3/*#Ops*/, 3, 4, 2, 
              // Src: (atomic_load_sub:i64 xoaddr:iPTR:$ptr, i64:i64:$incr)<<P:Predicate_atomic_load_sub_64>> - Complexity = 13
              // Dst: (ATOMIC_LOAD_SUB_I64:i64:i32 xoaddr:iPTR:$ptr, i64:i64:$incr)
/*3084*/    0, // EndSwitchType
/*3085*/  /*SwitchOpcode*/ 83,  TARGET_VAL(ISD::ATOMIC_LOAD_AND),// ->3171
/*3088*/    OPC_RecordMemRef,
/*3089*/    OPC_RecordNode,   // #0 = 'atomic_load_and' chained node
/*3090*/    OPC_RecordChild1, // #1 = $ptr
/*3091*/    OPC_RecordChild2, // #2 = $incr
/*3092*/    OPC_SwitchType /*2 cases */, 56,  MVT::i32,// ->3151
/*3095*/      OPC_Scope, 17, /*->3114*/ // 3 children in Scope
/*3097*/        OPC_CheckPredicate, 47, // Predicate_atomic_load_and_8
/*3099*/        OPC_CheckComplexPat, /*CP*/0, /*#*/1, // SelectAddrIdxOnly:$ptr #3 #4
/*3102*/        OPC_EmitMergeInputChains1_0,
/*3103*/        OPC_MorphNodeTo, TARGET_VAL(PPC::ATOMIC_LOAD_AND_I8), 0|OPFL_Chain|OPFL_MemRefs,
                    2/*#VTs*/, MVT::i32, MVT::i32, 3/*#Ops*/, 3, 4, 2, 
                // Src: (atomic_load_and:i32 xoaddr:iPTR:$ptr, i32:i32:$incr)<<P:Predicate_atomic_load_and_8>> - Complexity = 13
                // Dst: (ATOMIC_LOAD_AND_I8:i32:i32 xoaddr:iPTR:$ptr, i32:i32:$incr)
/*3114*/      /*Scope*/ 17, /*->3132*/
/*3115*/        OPC_CheckPredicate, 48, // Predicate_atomic_load_and_16
/*3117*/        OPC_CheckComplexPat, /*CP*/0, /*#*/1, // SelectAddrIdxOnly:$ptr #3 #4
/*3120*/        OPC_EmitMergeInputChains1_0,
/*3121*/        OPC_MorphNodeTo, TARGET_VAL(PPC::ATOMIC_LOAD_AND_I16), 0|OPFL_Chain|OPFL_MemRefs,
                    2/*#VTs*/, MVT::i32, MVT::i32, 3/*#Ops*/, 3, 4, 2, 
                // Src: (atomic_load_and:i32 xoaddr:iPTR:$ptr, i32:i32:$incr)<<P:Predicate_atomic_load_and_16>> - Complexity = 13
                // Dst: (ATOMIC_LOAD_AND_I16:i32:i32 xoaddr:iPTR:$ptr, i32:i32:$incr)
/*3132*/      /*Scope*/ 17, /*->3150*/
/*3133*/        OPC_CheckPredicate, 49, // Predicate_atomic_load_and_32
/*3135*/        OPC_CheckComplexPat, /*CP*/0, /*#*/1, // SelectAddrIdxOnly:$ptr #3 #4
/*3138*/        OPC_EmitMergeInputChains1_0,
/*3139*/        OPC_MorphNodeTo, TARGET_VAL(PPC::ATOMIC_LOAD_AND_I32), 0|OPFL_Chain|OPFL_MemRefs,
                    2/*#VTs*/, MVT::i32, MVT::i32, 3/*#Ops*/, 3, 4, 2, 
                // Src: (atomic_load_and:i32 xoaddr:iPTR:$ptr, i32:i32:$incr)<<P:Predicate_atomic_load_and_32>> - Complexity = 13
                // Dst: (ATOMIC_LOAD_AND_I32:i32:i32 xoaddr:iPTR:$ptr, i32:i32:$incr)
/*3150*/      0, /*End of Scope*/
/*3151*/    /*SwitchType*/ 17,  MVT::i64,// ->3170
/*3153*/      OPC_CheckPredicate, 50, // Predicate_atomic_load_and_64
/*3155*/      OPC_CheckComplexPat, /*CP*/0, /*#*/1, // SelectAddrIdxOnly:$ptr #3 #4
/*3158*/      OPC_EmitMergeInputChains1_0,
/*3159*/      OPC_MorphNodeTo, TARGET_VAL(PPC::ATOMIC_LOAD_AND_I64), 0|OPFL_Chain|OPFL_MemRefs,
                  2/*#VTs*/, MVT::i64, MVT::i32, 3/*#Ops*/, 3, 4, 2, 
              // Src: (atomic_load_and:i64 xoaddr:iPTR:$ptr, i64:i64:$incr)<<P:Predicate_atomic_load_and_64>> - Complexity = 13
              // Dst: (ATOMIC_LOAD_AND_I64:i64:i32 xoaddr:iPTR:$ptr, i64:i64:$incr)
/*3170*/    0, // EndSwitchType
/*3171*/  /*SwitchOpcode*/ 83,  TARGET_VAL(ISD::ATOMIC_LOAD_OR),// ->3257
/*3174*/    OPC_RecordMemRef,
/*3175*/    OPC_RecordNode,   // #0 = 'atomic_load_or' chained node
/*3176*/    OPC_RecordChild1, // #1 = $ptr
/*3177*/    OPC_RecordChild2, // #2 = $incr
/*3178*/    OPC_SwitchType /*2 cases */, 56,  MVT::i32,// ->3237
/*3181*/      OPC_Scope, 17, /*->3200*/ // 3 children in Scope
/*3183*/        OPC_CheckPredicate, 51, // Predicate_atomic_load_or_8
/*3185*/        OPC_CheckComplexPat, /*CP*/0, /*#*/1, // SelectAddrIdxOnly:$ptr #3 #4
/*3188*/        OPC_EmitMergeInputChains1_0,
/*3189*/        OPC_MorphNodeTo, TARGET_VAL(PPC::ATOMIC_LOAD_OR_I8), 0|OPFL_Chain|OPFL_MemRefs,
                    2/*#VTs*/, MVT::i32, MVT::i32, 3/*#Ops*/, 3, 4, 2, 
                // Src: (atomic_load_or:i32 xoaddr:iPTR:$ptr, i32:i32:$incr)<<P:Predicate_atomic_load_or_8>> - Complexity = 13
                // Dst: (ATOMIC_LOAD_OR_I8:i32:i32 xoaddr:iPTR:$ptr, i32:i32:$incr)
/*3200*/      /*Scope*/ 17, /*->3218*/
/*3201*/        OPC_CheckPredicate, 52, // Predicate_atomic_load_or_16
/*3203*/        OPC_CheckComplexPat, /*CP*/0, /*#*/1, // SelectAddrIdxOnly:$ptr #3 #4
/*3206*/        OPC_EmitMergeInputChains1_0,
/*3207*/        OPC_MorphNodeTo, TARGET_VAL(PPC::ATOMIC_LOAD_OR_I16), 0|OPFL_Chain|OPFL_MemRefs,
                    2/*#VTs*/, MVT::i32, MVT::i32, 3/*#Ops*/, 3, 4, 2, 
                // Src: (atomic_load_or:i32 xoaddr:iPTR:$ptr, i32:i32:$incr)<<P:Predicate_atomic_load_or_16>> - Complexity = 13
                // Dst: (ATOMIC_LOAD_OR_I16:i32:i32 xoaddr:iPTR:$ptr, i32:i32:$incr)
/*3218*/      /*Scope*/ 17, /*->3236*/
/*3219*/        OPC_CheckPredicate, 53, // Predicate_atomic_load_or_32
/*3221*/        OPC_CheckComplexPat, /*CP*/0, /*#*/1, // SelectAddrIdxOnly:$ptr #3 #4
/*3224*/        OPC_EmitMergeInputChains1_0,
/*3225*/        OPC_MorphNodeTo, TARGET_VAL(PPC::ATOMIC_LOAD_OR_I32), 0|OPFL_Chain|OPFL_MemRefs,
                    2/*#VTs*/, MVT::i32, MVT::i32, 3/*#Ops*/, 3, 4, 2, 
                // Src: (atomic_load_or:i32 xoaddr:iPTR:$ptr, i32:i32:$incr)<<P:Predicate_atomic_load_or_32>> - Complexity = 13
                // Dst: (ATOMIC_LOAD_OR_I32:i32:i32 xoaddr:iPTR:$ptr, i32:i32:$incr)
/*3236*/      0, /*End of Scope*/
/*3237*/    /*SwitchType*/ 17,  MVT::i64,// ->3256
/*3239*/      OPC_CheckPredicate, 54, // Predicate_atomic_load_or_64
/*3241*/      OPC_CheckComplexPat, /*CP*/0, /*#*/1, // SelectAddrIdxOnly:$ptr #3 #4
/*3244*/      OPC_EmitMergeInputChains1_0,
/*3245*/      OPC_MorphNodeTo, TARGET_VAL(PPC::ATOMIC_LOAD_OR_I64), 0|OPFL_Chain|OPFL_MemRefs,
                  2/*#VTs*/, MVT::i64, MVT::i32, 3/*#Ops*/, 3, 4, 2, 
              // Src: (atomic_load_or:i64 xoaddr:iPTR:$ptr, i64:i64:$incr)<<P:Predicate_atomic_load_or_64>> - Complexity = 13
              // Dst: (ATOMIC_LOAD_OR_I64:i64:i32 xoaddr:iPTR:$ptr, i64:i64:$incr)
/*3256*/    0, // EndSwitchType
/*3257*/  /*SwitchOpcode*/ 83,  TARGET_VAL(ISD::ATOMIC_LOAD_XOR),// ->3343
/*3260*/    OPC_RecordMemRef,
/*3261*/    OPC_RecordNode,   // #0 = 'atomic_load_xor' chained node
/*3262*/    OPC_RecordChild1, // #1 = $ptr
/*3263*/    OPC_RecordChild2, // #2 = $incr
/*3264*/    OPC_SwitchType /*2 cases */, 56,  MVT::i32,// ->3323
/*3267*/      OPC_Scope, 17, /*->3286*/ // 3 children in Scope
/*3269*/        OPC_CheckPredicate, 55, // Predicate_atomic_load_xor_8
/*3271*/        OPC_CheckComplexPat, /*CP*/0, /*#*/1, // SelectAddrIdxOnly:$ptr #3 #4
/*3274*/        OPC_EmitMergeInputChains1_0,
/*3275*/        OPC_MorphNodeTo, TARGET_VAL(PPC::ATOMIC_LOAD_XOR_I8), 0|OPFL_Chain|OPFL_MemRefs,
                    2/*#VTs*/, MVT::i32, MVT::i32, 3/*#Ops*/, 3, 4, 2, 
                // Src: (atomic_load_xor:i32 xoaddr:iPTR:$ptr, i32:i32:$incr)<<P:Predicate_atomic_load_xor_8>> - Complexity = 13
                // Dst: (ATOMIC_LOAD_XOR_I8:i32:i32 xoaddr:iPTR:$ptr, i32:i32:$incr)
/*3286*/      /*Scope*/ 17, /*->3304*/
/*3287*/        OPC_CheckPredicate, 56, // Predicate_atomic_load_xor_16
/*3289*/        OPC_CheckComplexPat, /*CP*/0, /*#*/1, // SelectAddrIdxOnly:$ptr #3 #4
/*3292*/        OPC_EmitMergeInputChains1_0,
/*3293*/        OPC_MorphNodeTo, TARGET_VAL(PPC::ATOMIC_LOAD_XOR_I16), 0|OPFL_Chain|OPFL_MemRefs,
                    2/*#VTs*/, MVT::i32, MVT::i32, 3/*#Ops*/, 3, 4, 2, 
                // Src: (atomic_load_xor:i32 xoaddr:iPTR:$ptr, i32:i32:$incr)<<P:Predicate_atomic_load_xor_16>> - Complexity = 13
                // Dst: (ATOMIC_LOAD_XOR_I16:i32:i32 xoaddr:iPTR:$ptr, i32:i32:$incr)
/*3304*/      /*Scope*/ 17, /*->3322*/
/*3305*/        OPC_CheckPredicate, 57, // Predicate_atomic_load_xor_32
/*3307*/        OPC_CheckComplexPat, /*CP*/0, /*#*/1, // SelectAddrIdxOnly:$ptr #3 #4
/*3310*/        OPC_EmitMergeInputChains1_0,
/*3311*/        OPC_MorphNodeTo, TARGET_VAL(PPC::ATOMIC_LOAD_XOR_I32), 0|OPFL_Chain|OPFL_MemRefs,
                    2/*#VTs*/, MVT::i32, MVT::i32, 3/*#Ops*/, 3, 4, 2, 
                // Src: (atomic_load_xor:i32 xoaddr:iPTR:$ptr, i32:i32:$incr)<<P:Predicate_atomic_load_xor_32>> - Complexity = 13
                // Dst: (ATOMIC_LOAD_XOR_I32:i32:i32 xoaddr:iPTR:$ptr, i32:i32:$incr)
/*3322*/      0, /*End of Scope*/
/*3323*/    /*SwitchType*/ 17,  MVT::i64,// ->3342
/*3325*/      OPC_CheckPredicate, 58, // Predicate_atomic_load_xor_64
/*3327*/      OPC_CheckComplexPat, /*CP*/0, /*#*/1, // SelectAddrIdxOnly:$ptr #3 #4
/*3330*/      OPC_EmitMergeInputChains1_0,
/*3331*/      OPC_MorphNodeTo, TARGET_VAL(PPC::ATOMIC_LOAD_XOR_I64), 0|OPFL_Chain|OPFL_MemRefs,
                  2/*#VTs*/, MVT::i64, MVT::i32, 3/*#Ops*/, 3, 4, 2, 
              // Src: (atomic_load_xor:i64 xoaddr:iPTR:$ptr, i64:i64:$incr)<<P:Predicate_atomic_load_xor_64>> - Complexity = 13
              // Dst: (ATOMIC_LOAD_XOR_I64:i64:i32 xoaddr:iPTR:$ptr, i64:i64:$incr)
/*3342*/    0, // EndSwitchType
/*3343*/  /*SwitchOpcode*/ 83,  TARGET_VAL(ISD::ATOMIC_LOAD_NAND),// ->3429
/*3346*/    OPC_RecordMemRef,
/*3347*/    OPC_RecordNode,   // #0 = 'atomic_load_nand' chained node
/*3348*/    OPC_RecordChild1, // #1 = $ptr
/*3349*/    OPC_RecordChild2, // #2 = $incr
/*3350*/    OPC_SwitchType /*2 cases */, 56,  MVT::i32,// ->3409
/*3353*/      OPC_Scope, 17, /*->3372*/ // 3 children in Scope
/*3355*/        OPC_CheckPredicate, 59, // Predicate_atomic_load_nand_8
/*3357*/        OPC_CheckComplexPat, /*CP*/0, /*#*/1, // SelectAddrIdxOnly:$ptr #3 #4
/*3360*/        OPC_EmitMergeInputChains1_0,
/*3361*/        OPC_MorphNodeTo, TARGET_VAL(PPC::ATOMIC_LOAD_NAND_I8), 0|OPFL_Chain|OPFL_MemRefs,
                    2/*#VTs*/, MVT::i32, MVT::i32, 3/*#Ops*/, 3, 4, 2, 
                // Src: (atomic_load_nand:i32 xoaddr:iPTR:$ptr, i32:i32:$incr)<<P:Predicate_atomic_load_nand_8>> - Complexity = 13
                // Dst: (ATOMIC_LOAD_NAND_I8:i32:i32 xoaddr:iPTR:$ptr, i32:i32:$incr)
/*3372*/      /*Scope*/ 17, /*->3390*/
/*3373*/        OPC_CheckPredicate, 60, // Predicate_atomic_load_nand_16
/*3375*/        OPC_CheckComplexPat, /*CP*/0, /*#*/1, // SelectAddrIdxOnly:$ptr #3 #4
/*3378*/        OPC_EmitMergeInputChains1_0,
/*3379*/        OPC_MorphNodeTo, TARGET_VAL(PPC::ATOMIC_LOAD_NAND_I16), 0|OPFL_Chain|OPFL_MemRefs,
                    2/*#VTs*/, MVT::i32, MVT::i32, 3/*#Ops*/, 3, 4, 2, 
                // Src: (atomic_load_nand:i32 xoaddr:iPTR:$ptr, i32:i32:$incr)<<P:Predicate_atomic_load_nand_16>> - Complexity = 13
                // Dst: (ATOMIC_LOAD_NAND_I16:i32:i32 xoaddr:iPTR:$ptr, i32:i32:$incr)
/*3390*/      /*Scope*/ 17, /*->3408*/
/*3391*/        OPC_CheckPredicate, 61, // Predicate_atomic_load_nand_32
/*3393*/        OPC_CheckComplexPat, /*CP*/0, /*#*/1, // SelectAddrIdxOnly:$ptr #3 #4
/*3396*/        OPC_EmitMergeInputChains1_0,
/*3397*/        OPC_MorphNodeTo, TARGET_VAL(PPC::ATOMIC_LOAD_NAND_I32), 0|OPFL_Chain|OPFL_MemRefs,
                    2/*#VTs*/, MVT::i32, MVT::i32, 3/*#Ops*/, 3, 4, 2, 
                // Src: (atomic_load_nand:i32 xoaddr:iPTR:$ptr, i32:i32:$incr)<<P:Predicate_atomic_load_nand_32>> - Complexity = 13
                // Dst: (ATOMIC_LOAD_NAND_I32:i32:i32 xoaddr:iPTR:$ptr, i32:i32:$incr)
/*3408*/      0, /*End of Scope*/
/*3409*/    /*SwitchType*/ 17,  MVT::i64,// ->3428
/*3411*/      OPC_CheckPredicate, 62, // Predicate_atomic_load_nand_64
/*3413*/      OPC_CheckComplexPat, /*CP*/0, /*#*/1, // SelectAddrIdxOnly:$ptr #3 #4
/*3416*/      OPC_EmitMergeInputChains1_0,
/*3417*/      OPC_MorphNodeTo, TARGET_VAL(PPC::ATOMIC_LOAD_NAND_I64), 0|OPFL_Chain|OPFL_MemRefs,
                  2/*#VTs*/, MVT::i64, MVT::i32, 3/*#Ops*/, 3, 4, 2, 
              // Src: (atomic_load_nand:i64 xoaddr:iPTR:$ptr, i64:i64:$incr)<<P:Predicate_atomic_load_nand_64>> - Complexity = 13
              // Dst: (ATOMIC_LOAD_NAND_I64:i64:i32 xoaddr:iPTR:$ptr, i64:i64:$incr)
/*3428*/    0, // EndSwitchType
/*3429*/  /*SwitchOpcode*/ 88,  TARGET_VAL(ISD::ATOMIC_CMP_SWAP),// ->3520
/*3432*/    OPC_RecordMemRef,
/*3433*/    OPC_RecordNode,   // #0 = 'atomic_cmp_swap' chained node
/*3434*/    OPC_RecordChild1, // #1 = $ptr
/*3435*/    OPC_RecordChild2, // #2 = $old
/*3436*/    OPC_RecordChild3, // #3 = $new
/*3437*/    OPC_SwitchType /*2 cases */, 59,  MVT::i32,// ->3499
/*3440*/      OPC_Scope, 18, /*->3460*/ // 3 children in Scope
/*3442*/        OPC_CheckPredicate, 63, // Predicate_atomic_cmp_swap_8
/*3444*/        OPC_CheckComplexPat, /*CP*/0, /*#*/1, // SelectAddrIdxOnly:$ptr #4 #5
/*3447*/        OPC_EmitMergeInputChains1_0,
/*3448*/        OPC_MorphNodeTo, TARGET_VAL(PPC::ATOMIC_CMP_SWAP_I8), 0|OPFL_Chain|OPFL_MemRefs,
                    2/*#VTs*/, MVT::i32, MVT::i32, 4/*#Ops*/, 4, 5, 2, 3, 
                // Src: (atomic_cmp_swap:i32 xoaddr:iPTR:$ptr, i32:i32:$old, i32:i32:$new)<<P:Predicate_atomic_cmp_swap_8>> - Complexity = 13
                // Dst: (ATOMIC_CMP_SWAP_I8:i32:i32 xoaddr:iPTR:$ptr, i32:i32:$old, i32:i32:$new)
/*3460*/      /*Scope*/ 18, /*->3479*/
/*3461*/        OPC_CheckPredicate, 64, // Predicate_atomic_cmp_swap_16
/*3463*/        OPC_CheckComplexPat, /*CP*/0, /*#*/1, // SelectAddrIdxOnly:$ptr #4 #5
/*3466*/        OPC_EmitMergeInputChains1_0,
/*3467*/        OPC_MorphNodeTo, TARGET_VAL(PPC::ATOMIC_CMP_SWAP_I16), 0|OPFL_Chain|OPFL_MemRefs,
                    2/*#VTs*/, MVT::i32, MVT::i32, 4/*#Ops*/, 4, 5, 2, 3, 
                // Src: (atomic_cmp_swap:i32 xoaddr:iPTR:$ptr, i32:i32:$old, i32:i32:$new)<<P:Predicate_atomic_cmp_swap_16>> - Complexity = 13
                // Dst: (ATOMIC_CMP_SWAP_I16:i32:i32 xoaddr:iPTR:$ptr, i32:i32:$old, i32:i32:$new)
/*3479*/      /*Scope*/ 18, /*->3498*/
/*3480*/        OPC_CheckPredicate, 65, // Predicate_atomic_cmp_swap_32
/*3482*/        OPC_CheckComplexPat, /*CP*/0, /*#*/1, // SelectAddrIdxOnly:$ptr #4 #5
/*3485*/        OPC_EmitMergeInputChains1_0,
/*3486*/        OPC_MorphNodeTo, TARGET_VAL(PPC::ATOMIC_CMP_SWAP_I32), 0|OPFL_Chain|OPFL_MemRefs,
                    2/*#VTs*/, MVT::i32, MVT::i32, 4/*#Ops*/, 4, 5, 2, 3, 
                // Src: (atomic_cmp_swap:i32 xoaddr:iPTR:$ptr, i32:i32:$old, i32:i32:$new)<<P:Predicate_atomic_cmp_swap_32>> - Complexity = 13
                // Dst: (ATOMIC_CMP_SWAP_I32:i32:i32 xoaddr:iPTR:$ptr, i32:i32:$old, i32:i32:$new)
/*3498*/      0, /*End of Scope*/
/*3499*/    /*SwitchType*/ 18,  MVT::i64,// ->3519
/*3501*/      OPC_CheckPredicate, 66, // Predicate_atomic_cmp_swap_64
/*3503*/      OPC_CheckComplexPat, /*CP*/0, /*#*/1, // SelectAddrIdxOnly:$ptr #4 #5
/*3506*/      OPC_EmitMergeInputChains1_0,
/*3507*/      OPC_MorphNodeTo, TARGET_VAL(PPC::ATOMIC_CMP_SWAP_I64), 0|OPFL_Chain|OPFL_MemRefs,
                  2/*#VTs*/, MVT::i64, MVT::i32, 4/*#Ops*/, 4, 5, 2, 3, 
              // Src: (atomic_cmp_swap:i64 xoaddr:iPTR:$ptr, i64:i64:$old, i64:i64:$new)<<P:Predicate_atomic_cmp_swap_64>> - Complexity = 13
              // Dst: (ATOMIC_CMP_SWAP_I64:i64:i32 xoaddr:iPTR:$ptr, i64:i64:$old, i64:i64:$new)
/*3519*/    0, // EndSwitchType
/*3520*/  /*SwitchOpcode*/ 83,  TARGET_VAL(ISD::ATOMIC_SWAP),// ->3606
/*3523*/    OPC_RecordMemRef,
/*3524*/    OPC_RecordNode,   // #0 = 'atomic_swap' chained node
/*3525*/    OPC_RecordChild1, // #1 = $ptr
/*3526*/    OPC_RecordChild2, // #2 = $new
/*3527*/    OPC_SwitchType /*2 cases */, 56,  MVT::i32,// ->3586
/*3530*/      OPC_Scope, 17, /*->3549*/ // 3 children in Scope
/*3532*/        OPC_CheckPredicate, 67, // Predicate_atomic_swap_8
/*3534*/        OPC_CheckComplexPat, /*CP*/0, /*#*/1, // SelectAddrIdxOnly:$ptr #3 #4
/*3537*/        OPC_EmitMergeInputChains1_0,
/*3538*/        OPC_MorphNodeTo, TARGET_VAL(PPC::ATOMIC_SWAP_I8), 0|OPFL_Chain|OPFL_MemRefs,
                    2/*#VTs*/, MVT::i32, MVT::i32, 3/*#Ops*/, 3, 4, 2, 
                // Src: (atomic_swap:i32 xoaddr:iPTR:$ptr, i32:i32:$new)<<P:Predicate_atomic_swap_8>> - Complexity = 13
                // Dst: (ATOMIC_SWAP_I8:i32:i32 xoaddr:iPTR:$ptr, i32:i32:$new)
/*3549*/      /*Scope*/ 17, /*->3567*/
/*3550*/        OPC_CheckPredicate, 68, // Predicate_atomic_swap_16
/*3552*/        OPC_CheckComplexPat, /*CP*/0, /*#*/1, // SelectAddrIdxOnly:$ptr #3 #4
/*3555*/        OPC_EmitMergeInputChains1_0,
/*3556*/        OPC_MorphNodeTo, TARGET_VAL(PPC::ATOMIC_SWAP_I16), 0|OPFL_Chain|OPFL_MemRefs,
                    2/*#VTs*/, MVT::i32, MVT::i32, 3/*#Ops*/, 3, 4, 2, 
                // Src: (atomic_swap:i32 xoaddr:iPTR:$ptr, i32:i32:$new)<<P:Predicate_atomic_swap_16>> - Complexity = 13
                // Dst: (ATOMIC_SWAP_I16:i32:i32 xoaddr:iPTR:$ptr, i32:i32:$new)
/*3567*/      /*Scope*/ 17, /*->3585*/
/*3568*/        OPC_CheckPredicate, 69, // Predicate_atomic_swap_32
/*3570*/        OPC_CheckComplexPat, /*CP*/0, /*#*/1, // SelectAddrIdxOnly:$ptr #3 #4
/*3573*/        OPC_EmitMergeInputChains1_0,
/*3574*/        OPC_MorphNodeTo, TARGET_VAL(PPC::ATOMIC_SWAP_I32), 0|OPFL_Chain|OPFL_MemRefs,
                    2/*#VTs*/, MVT::i32, MVT::i32, 3/*#Ops*/, 3, 4, 2, 
                // Src: (atomic_swap:i32 xoaddr:iPTR:$ptr, i32:i32:$new)<<P:Predicate_atomic_swap_32>> - Complexity = 13
                // Dst: (ATOMIC_SWAP_I32:i32:i32 xoaddr:iPTR:$ptr, i32:i32:$new)
/*3585*/      0, /*End of Scope*/
/*3586*/    /*SwitchType*/ 17,  MVT::i64,// ->3605
/*3588*/      OPC_CheckPredicate, 70, // Predicate_atomic_swap_64
/*3590*/      OPC_CheckComplexPat, /*CP*/0, /*#*/1, // SelectAddrIdxOnly:$ptr #3 #4
/*3593*/      OPC_EmitMergeInputChains1_0,
/*3594*/      OPC_MorphNodeTo, TARGET_VAL(PPC::ATOMIC_SWAP_I64), 0|OPFL_Chain|OPFL_MemRefs,
                  2/*#VTs*/, MVT::i64, MVT::i32, 3/*#Ops*/, 3, 4, 2, 
              // Src: (atomic_swap:i64 xoaddr:iPTR:$ptr, i64:i64:$new)<<P:Predicate_atomic_swap_64>> - Complexity = 13
              // Dst: (ATOMIC_SWAP_I64:i64:i32 xoaddr:iPTR:$ptr, i64:i64:$new)
/*3605*/    0, // EndSwitchType
/*3606*/  /*SwitchOpcode*/ 48,  TARGET_VAL(PPCISD::DYNALLOC),// ->3657
/*3609*/    OPC_RecordNode,   // #0 = 'PPCdynalloc' chained node
/*3610*/    OPC_RecordChild1, // #1 = $negsize
/*3611*/    OPC_SwitchType /*2 cases */, 20,  MVT::i32,// ->3634
/*3614*/      OPC_CheckChild1Type, MVT::i32,
/*3616*/      OPC_RecordChild2, // #2 = $fpsi
/*3617*/      OPC_CheckChild2Type, MVT::iPTR,
/*3619*/      OPC_CheckComplexPat, /*CP*/1, /*#*/2, // SelectAddrImm:$fpsi #3 #4
/*3622*/      OPC_EmitMergeInputChains1_0,
/*3623*/      OPC_MorphNodeTo, TARGET_VAL(PPC::DYNALLOC), 0|OPFL_Chain,
                  2/*#VTs*/, MVT::i32, MVT::i32, 3/*#Ops*/, 1, 3, 4, 
              // Src: (PPCdynalloc:i32 i32:i32:$negsize, iaddr:iPTR:$fpsi) - Complexity = 12
              // Dst: (DYNALLOC:i32:i32 i32:i32:$negsize, iaddr:iPTR:$fpsi)
/*3634*/    /*SwitchType*/ 20,  MVT::i64,// ->3656
/*3636*/      OPC_CheckChild1Type, MVT::i64,
/*3638*/      OPC_RecordChild2, // #2 = $fpsi
/*3639*/      OPC_CheckChild2Type, MVT::iPTR,
/*3641*/      OPC_CheckComplexPat, /*CP*/1, /*#*/2, // SelectAddrImm:$fpsi #3 #4
/*3644*/      OPC_EmitMergeInputChains1_0,
/*3645*/      OPC_MorphNodeTo, TARGET_VAL(PPC::DYNALLOC8), 0|OPFL_Chain,
                  2/*#VTs*/, MVT::i64, MVT::i64, 3/*#Ops*/, 1, 3, 4, 
              // Src: (PPCdynalloc:i64 i64:i64:$negsize, iaddr:iPTR:$fpsi) - Complexity = 12
              // Dst: (DYNALLOC8:i64:i64 i64:i64:$negsize, iaddr:iPTR:$fpsi)
/*3656*/    0, // EndSwitchType
/*3657*/  /*SwitchOpcode*/ 34,  TARGET_VAL(PPCISD::LARX),// ->3694
/*3660*/    OPC_RecordNode,   // #0 = 'PPClarx' chained node
/*3661*/    OPC_RecordChild1, // #1 = $src
/*3662*/    OPC_SwitchType /*2 cases */, 13,  MVT::i32,// ->3678
/*3665*/      OPC_CheckComplexPat, /*CP*/0, /*#*/1, // SelectAddrIdxOnly:$src #2 #3
/*3668*/      OPC_EmitMergeInputChains1_0,
/*3669*/      OPC_MorphNodeTo, TARGET_VAL(PPC::LWARX), 0|OPFL_Chain,
                  1/*#VTs*/, MVT::i32, 2/*#Ops*/, 2, 3, 
              // Src: (PPClarx:i32 xoaddr:iPTR:$src) - Complexity = 12
              // Dst: (LWARX:i32 xoaddr:iPTR:$src)
/*3678*/    /*SwitchType*/ 13,  MVT::i64,// ->3693
/*3680*/      OPC_CheckComplexPat, /*CP*/0, /*#*/1, // SelectAddrIdxOnly:$ptr #2 #3
/*3683*/      OPC_EmitMergeInputChains1_0,
/*3684*/      OPC_MorphNodeTo, TARGET_VAL(PPC::LDARX), 0|OPFL_Chain,
                  1/*#VTs*/, MVT::i64, 2/*#Ops*/, 2, 3, 
              // Src: (PPClarx:i64 xoaddr:iPTR:$ptr) - Complexity = 12
              // Dst: (LDARX:i64 xoaddr:iPTR:$ptr)
/*3693*/    0, // EndSwitchType
/*3694*/  /*SwitchOpcode*/ 40,  TARGET_VAL(PPCISD::STCX),// ->3737
/*3697*/    OPC_RecordNode,   // #0 = 'PPCstcx' chained node
/*3698*/    OPC_RecordChild1, // #1 = $rS
/*3699*/    OPC_Scope, 17, /*->3718*/ // 2 children in Scope
/*3701*/      OPC_CheckChild1Type, MVT::i32,
/*3703*/      OPC_RecordChild2, // #2 = $dst
/*3704*/      OPC_CheckComplexPat, /*CP*/0, /*#*/2, // SelectAddrIdxOnly:$dst #3 #4
/*3707*/      OPC_EmitMergeInputChains1_0,
/*3708*/      OPC_MorphNodeTo, TARGET_VAL(PPC::STWCX), 0|OPFL_Chain,
                  1/*#VTs*/, MVT::i32, 3/*#Ops*/, 1, 3, 4, 
              // Src: (PPCstcx i32:i32:$rS, xoaddr:iPTR:$dst) - Complexity = 12
              // Dst: (STWCX:i32 i32:i32:$rS, xoaddr:iPTR:$dst)
/*3718*/    /*Scope*/ 17, /*->3736*/
/*3719*/      OPC_CheckChild1Type, MVT::i64,
/*3721*/      OPC_RecordChild2, // #2 = $dst
/*3722*/      OPC_CheckComplexPat, /*CP*/0, /*#*/2, // SelectAddrIdxOnly:$dst #3 #4
/*3725*/      OPC_EmitMergeInputChains1_0,
/*3726*/      OPC_MorphNodeTo, TARGET_VAL(PPC::STDCX), 0|OPFL_Chain,
                  1/*#VTs*/, MVT::i32, 3/*#Ops*/, 1, 3, 4, 
              // Src: (PPCstcx i64:i64:$rS, xoaddr:iPTR:$dst) - Complexity = 12
              // Dst: (STDCX:i32 i64:i64:$rS, xoaddr:iPTR:$dst)
/*3736*/    0, /*End of Scope*/
/*3737*/  /*SwitchOpcode*/ 63,  TARGET_VAL(PPCISD::LBRX),// ->3803
/*3740*/    OPC_RecordNode,   // #0 = 'PPClbrx' chained node
/*3741*/    OPC_RecordChild1, // #1 = $src
/*3742*/    OPC_MoveChild, 2,
/*3744*/    OPC_Scope, 18, /*->3764*/ // 3 children in Scope
/*3746*/      OPC_CheckValueType, MVT::i16,
/*3748*/      OPC_MoveParent,
/*3749*/      OPC_CheckType, MVT::i32,
/*3751*/      OPC_CheckComplexPat, /*CP*/0, /*#*/1, // SelectAddrIdxOnly:$src #2 #3
/*3754*/      OPC_EmitMergeInputChains1_0,
/*3755*/      OPC_MorphNodeTo, TARGET_VAL(PPC::LHBRX), 0|OPFL_Chain,
                  1/*#VTs*/, MVT::i32, 2/*#Ops*/, 2, 3, 
              // Src: (PPClbrx:i32 xoaddr:iPTR:$src, i16:Other) - Complexity = 12
              // Dst: (LHBRX:i32 xoaddr:iPTR:$src)
/*3764*/    /*Scope*/ 18, /*->3783*/
/*3765*/      OPC_CheckValueType, MVT::i32,
/*3767*/      OPC_MoveParent,
/*3768*/      OPC_CheckType, MVT::i32,
/*3770*/      OPC_CheckComplexPat, /*CP*/0, /*#*/1, // SelectAddrIdxOnly:$src #2 #3
/*3773*/      OPC_EmitMergeInputChains1_0,
/*3774*/      OPC_MorphNodeTo, TARGET_VAL(PPC::LWBRX), 0|OPFL_Chain,
                  1/*#VTs*/, MVT::i32, 2/*#Ops*/, 2, 3, 
              // Src: (PPClbrx:i32 xoaddr:iPTR:$src, i32:Other) - Complexity = 12
              // Dst: (LWBRX:i32 xoaddr:iPTR:$src)
/*3783*/    /*Scope*/ 18, /*->3802*/
/*3784*/      OPC_CheckValueType, MVT::i64,
/*3786*/      OPC_MoveParent,
/*3787*/      OPC_CheckType, MVT::i64,
/*3789*/      OPC_CheckComplexPat, /*CP*/0, /*#*/1, // SelectAddrIdxOnly:$src #2 #3
/*3792*/      OPC_EmitMergeInputChains1_0,
/*3793*/      OPC_MorphNodeTo, TARGET_VAL(PPC::LDBRX), 0|OPFL_Chain,
                  1/*#VTs*/, MVT::i64, 2/*#Ops*/, 2, 3, 
              // Src: (PPClbrx:i64 xoaddr:iPTR:$src, i64:Other) - Complexity = 12
              // Dst: (LDBRX:i64 xoaddr:iPTR:$src)
/*3802*/    0, /*End of Scope*/
/*3803*/  /*SwitchOpcode*/ 68,  TARGET_VAL(PPCISD::STBRX),// ->3874
/*3806*/    OPC_RecordNode,   // #0 = 'PPCstbrx' chained node
/*3807*/    OPC_RecordChild1, // #1 = $rS
/*3808*/    OPC_Scope, 41, /*->3851*/ // 2 children in Scope
/*3810*/      OPC_CheckChild1Type, MVT::i32,
/*3812*/      OPC_RecordChild2, // #2 = $dst
/*3813*/      OPC_MoveChild, 3,
/*3815*/      OPC_Scope, 16, /*->3833*/ // 2 children in Scope
/*3817*/        OPC_CheckValueType, MVT::i16,
/*3819*/        OPC_MoveParent,
/*3820*/        OPC_CheckComplexPat, /*CP*/0, /*#*/2, // SelectAddrIdxOnly:$dst #3 #4
/*3823*/        OPC_EmitMergeInputChains1_0,
/*3824*/        OPC_MorphNodeTo, TARGET_VAL(PPC::STHBRX), 0|OPFL_Chain,
                    0/*#VTs*/, 3/*#Ops*/, 1, 3, 4, 
                // Src: (PPCstbrx i32:i32:$rS, xoaddr:iPTR:$dst, i16:Other) - Complexity = 12
                // Dst: (STHBRX i32:i32:$rS, xoaddr:iPTR:$dst)
/*3833*/      /*Scope*/ 16, /*->3850*/
/*3834*/        OPC_CheckValueType, MVT::i32,
/*3836*/        OPC_MoveParent,
/*3837*/        OPC_CheckComplexPat, /*CP*/0, /*#*/2, // SelectAddrIdxOnly:$dst #3 #4
/*3840*/        OPC_EmitMergeInputChains1_0,
/*3841*/        OPC_MorphNodeTo, TARGET_VAL(PPC::STWBRX), 0|OPFL_Chain,
                    0/*#VTs*/, 3/*#Ops*/, 1, 3, 4, 
                // Src: (PPCstbrx i32:i32:$rS, xoaddr:iPTR:$dst, i32:Other) - Complexity = 12
                // Dst: (STWBRX i32:i32:$rS, xoaddr:iPTR:$dst)
/*3850*/      0, /*End of Scope*/
/*3851*/    /*Scope*/ 21, /*->3873*/
/*3852*/      OPC_CheckChild1Type, MVT::i64,
/*3854*/      OPC_RecordChild2, // #2 = $dst
/*3855*/      OPC_MoveChild, 3,
/*3857*/      OPC_CheckValueType, MVT::i64,
/*3859*/      OPC_MoveParent,
/*3860*/      OPC_CheckComplexPat, /*CP*/0, /*#*/2, // SelectAddrIdxOnly:$dst #3 #4
/*3863*/      OPC_EmitMergeInputChains1_0,
/*3864*/      OPC_MorphNodeTo, TARGET_VAL(PPC::STDBRX), 0|OPFL_Chain,
                  0/*#VTs*/, 3/*#Ops*/, 1, 3, 4, 
              // Src: (PPCstbrx i64:i64:$rS, xoaddr:iPTR:$dst, i64:Other) - Complexity = 12
              // Dst: (STDBRX i64:i64:$rS, xoaddr:iPTR:$dst)
/*3873*/    0, /*End of Scope*/
/*3874*/  /*SwitchOpcode*/ 16,  TARGET_VAL(PPCISD::STFIWX),// ->3893
/*3877*/    OPC_RecordNode,   // #0 = 'PPCstfiwx' chained node
/*3878*/    OPC_RecordChild1, // #1 = $frS
/*3879*/    OPC_RecordChild2, // #2 = $dst
/*3880*/    OPC_CheckComplexPat, /*CP*/0, /*#*/2, // SelectAddrIdxOnly:$dst #3 #4
/*3883*/    OPC_EmitMergeInputChains1_0,
/*3884*/    OPC_MorphNodeTo, TARGET_VAL(PPC::STFIWX), 0|OPFL_Chain,
                0/*#VTs*/, 3/*#Ops*/, 1, 3, 4, 
            // Src: (PPCstfiwx f64:f64:$frS, xoaddr:iPTR:$dst) - Complexity = 12
            // Dst: (STFIWX f64:f64:$frS, xoaddr:iPTR:$dst)
/*3893*/  /*SwitchOpcode*/ 37,  TARGET_VAL(PPCISD::LOAD),// ->3933
/*3896*/    OPC_RecordNode,   // #0 = 'PPCload' chained node
/*3897*/    OPC_CaptureGlueInput,
/*3898*/    OPC_RecordChild1, // #1 = $src
/*3899*/    OPC_CheckChild1Type, MVT::iPTR,
/*3901*/    OPC_CheckType, MVT::i64,
/*3903*/    OPC_Scope, 13, /*->3918*/ // 2 children in Scope
/*3905*/      OPC_CheckComplexPat, /*CP*/3, /*#*/1, // SelectAddrImmX4:$src #2 #3
/*3908*/      OPC_EmitMergeInputChains1_0,
/*3909*/      OPC_MorphNodeTo, TARGET_VAL(PPC::LD), 0|OPFL_Chain|OPFL_GlueInput|OPFL_GlueOutput,
                  1/*#VTs*/, MVT::i64, 2/*#Ops*/, 2, 3, 
              // Src: (PPCload:i64 ixaddr:iPTR:$src) - Complexity = 12
              // Dst: (LD:i64 ixaddr:iPTR:$src)
/*3918*/    /*Scope*/ 13, /*->3932*/
/*3919*/      OPC_CheckComplexPat, /*CP*/2, /*#*/1, // SelectAddrIdx:$src #2 #3
/*3922*/      OPC_EmitMergeInputChains1_0,
/*3923*/      OPC_MorphNodeTo, TARGET_VAL(PPC::LDX), 0|OPFL_Chain|OPFL_GlueInput|OPFL_GlueOutput,
                  1/*#VTs*/, MVT::i64, 2/*#Ops*/, 2, 3, 
              // Src: (PPCload:i64 xaddr:iPTR:$src) - Complexity = 12
              // Dst: (LDX:i64 xaddr:iPTR:$src)
/*3932*/    0, /*End of Scope*/
/*3933*/  /*SwitchOpcode*/ 94|128,4/*606*/,  TARGET_VAL(ISD::XOR),// ->4543
/*3937*/    OPC_Scope, 39|128,1/*167*/, /*->4107*/ // 8 children in Scope
/*3940*/      OPC_MoveChild, 0,
/*3942*/      OPC_SwitchOpcode /*3 cases */, 41,  TARGET_VAL(ISD::AND),// ->3987
/*3946*/        OPC_RecordChild0, // #0 = $rS
/*3947*/        OPC_RecordChild1, // #1 = $rB
/*3948*/        OPC_MoveParent,
/*3949*/        OPC_MoveChild, 1,
/*3951*/        OPC_CheckInteger, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*3962*/        OPC_MoveParent,
/*3963*/        OPC_SwitchType /*2 cases */, 9,  MVT::i32,// ->3975
/*3966*/          OPC_MorphNodeTo, TARGET_VAL(PPC::NAND), 0,
                      1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1, 
                  // Src: (xor:i32 (and:i32 i32:i32:$rS, i32:i32:$rB), -1:i32) - Complexity = 11
                  // Dst: (NAND:i32 i32:i32:$rS, i32:i32:$rB)
/*3975*/        /*SwitchType*/ 9,  MVT::i64,// ->3986
/*3977*/          OPC_MorphNodeTo, TARGET_VAL(PPC::NAND8), 0,
                      1/*#VTs*/, MVT::i64, 2/*#Ops*/, 0, 1, 
                  // Src: (xor:i64 (and:i64 i64:i64:$rS, i64:i64:$rB), -1:i64) - Complexity = 11
                  // Dst: (NAND8:i64 i64:i64:$rS, i64:i64:$rB)
/*3986*/        0, // EndSwitchType
/*3987*/      /*SwitchOpcode*/ 41,  TARGET_VAL(ISD::OR),// ->4031
/*3990*/        OPC_RecordChild0, // #0 = $rS
/*3991*/        OPC_RecordChild1, // #1 = $rB
/*3992*/        OPC_MoveParent,
/*3993*/        OPC_MoveChild, 1,
/*3995*/        OPC_CheckInteger, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*4006*/        OPC_MoveParent,
/*4007*/        OPC_SwitchType /*2 cases */, 9,  MVT::i32,// ->4019
/*4010*/          OPC_MorphNodeTo, TARGET_VAL(PPC::NOR), 0,
                      1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1, 
                  // Src: (xor:i32 (or:i32 i32:i32:$rS, i32:i32:$rB), -1:i32) - Complexity = 11
                  // Dst: (NOR:i32 i32:i32:$rS, i32:i32:$rB)
/*4019*/        /*SwitchType*/ 9,  MVT::i64,// ->4030
/*4021*/          OPC_MorphNodeTo, TARGET_VAL(PPC::NOR8), 0,
                      1/*#VTs*/, MVT::i64, 2/*#Ops*/, 0, 1, 
                  // Src: (xor:i64 (or:i64 i64:i64:$rS, i64:i64:$rB), -1:i64) - Complexity = 11
                  // Dst: (NOR8:i64 i64:i64:$rS, i64:i64:$rB)
/*4030*/        0, // EndSwitchType
/*4031*/      /*SwitchOpcode*/ 72,  TARGET_VAL(ISD::XOR),// ->4106
/*4034*/        OPC_RecordChild0, // #0 = $rS
/*4035*/        OPC_Scope, 40, /*->4077*/ // 2 children in Scope
/*4037*/          OPC_RecordChild1, // #1 = $rB
/*4038*/          OPC_MoveParent,
/*4039*/          OPC_MoveChild, 1,
/*4041*/          OPC_CheckInteger, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*4052*/          OPC_MoveParent,
/*4053*/          OPC_SwitchType /*2 cases */, 9,  MVT::i32,// ->4065
/*4056*/            OPC_MorphNodeTo, TARGET_VAL(PPC::EQV), 0,
                        1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1, 
                    // Src: (xor:i32 (xor:i32 i32:i32:$rS, i32:i32:$rB), -1:i32) - Complexity = 11
                    // Dst: (EQV:i32 i32:i32:$rS, i32:i32:$rB)
/*4065*/          /*SwitchType*/ 9,  MVT::i64,// ->4076
/*4067*/            OPC_MorphNodeTo, TARGET_VAL(PPC::EQV8), 0,
                        1/*#VTs*/, MVT::i64, 2/*#Ops*/, 0, 1, 
                    // Src: (xor:i64 (xor:i64 i64:i64:$rS, i64:i64:$rB), -1:i64) - Complexity = 11
                    // Dst: (EQV8:i64 i64:i64:$rS, i64:i64:$rB)
/*4076*/          0, // EndSwitchType
/*4077*/        /*Scope*/ 27, /*->4105*/
/*4078*/          OPC_MoveChild, 1,
/*4080*/          OPC_CheckInteger, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*4091*/          OPC_MoveParent,
/*4092*/          OPC_MoveParent,
/*4093*/          OPC_RecordChild1, // #1 = $rB
/*4094*/          OPC_CheckType, MVT::i32,
/*4096*/          OPC_MorphNodeTo, TARGET_VAL(PPC::EQV), 0,
                      1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1, 
                  // Src: (xor:i32 (xor:i32 i32:i32:$rS, -1:i32), i32:i32:$rB) - Complexity = 11
                  // Dst: (EQV:i32 i32:i32:$rS, i32:i32:$rB)
/*4105*/        0, /*End of Scope*/
/*4106*/      0, // EndSwitchOpcode
/*4107*/    /*Scope*/ 33, /*->4141*/
/*4108*/      OPC_RecordChild0, // #0 = $rB
/*4109*/      OPC_MoveChild, 1,
/*4111*/      OPC_CheckOpcode, TARGET_VAL(ISD::XOR),
/*4114*/      OPC_RecordChild0, // #1 = $rS
/*4115*/      OPC_MoveChild, 1,
/*4117*/      OPC_CheckInteger, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*4128*/      OPC_MoveParent,
/*4129*/      OPC_MoveParent,
/*4130*/      OPC_CheckType, MVT::i32,
/*4132*/      OPC_MorphNodeTo, TARGET_VAL(PPC::EQV), 0,
                  1/*#VTs*/, MVT::i32, 2/*#Ops*/, 1, 0, 
              // Src: (xor:i32 i32:i32:$rB, (xor:i32 i32:i32:$rS, -1:i32)) - Complexity = 11
              // Dst: (EQV:i32 i32:i32:$rS, i32:i32:$rB)
/*4141*/    /*Scope*/ 33, /*->4175*/
/*4142*/      OPC_MoveChild, 0,
/*4144*/      OPC_CheckOpcode, TARGET_VAL(ISD::XOR),
/*4147*/      OPC_RecordChild0, // #0 = $rS
/*4148*/      OPC_MoveChild, 1,
/*4150*/      OPC_CheckInteger, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*4161*/      OPC_MoveParent,
/*4162*/      OPC_MoveParent,
/*4163*/      OPC_RecordChild1, // #1 = $rB
/*4164*/      OPC_CheckType, MVT::i64,
/*4166*/      OPC_MorphNodeTo, TARGET_VAL(PPC::EQV8), 0,
                  1/*#VTs*/, MVT::i64, 2/*#Ops*/, 0, 1, 
              // Src: (xor:i64 (xor:i64 i64:i64:$rS, -1:i64), i64:i64:$rB) - Complexity = 11
              // Dst: (EQV8:i64 i64:i64:$rS, i64:i64:$rB)
/*4175*/    /*Scope*/ 84|128,1/*212*/, /*->4389*/
/*4177*/      OPC_RecordChild0, // #0 = $rB
/*4178*/      OPC_Scope, 59, /*->4239*/ // 2 children in Scope
/*4180*/        OPC_MoveChild, 1,
/*4182*/        OPC_Scope, 30, /*->4214*/ // 2 children in Scope
/*4184*/          OPC_CheckOpcode, TARGET_VAL(ISD::XOR),
/*4187*/          OPC_RecordChild0, // #1 = $rS
/*4188*/          OPC_MoveChild, 1,
/*4190*/          OPC_CheckInteger, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*4201*/          OPC_MoveParent,
/*4202*/          OPC_MoveParent,
/*4203*/          OPC_CheckType, MVT::i64,
/*4205*/          OPC_MorphNodeTo, TARGET_VAL(PPC::EQV8), 0,
                      1/*#VTs*/, MVT::i64, 2/*#Ops*/, 1, 0, 
                  // Src: (xor:i64 i64:i64:$rB, (xor:i64 i64:i64:$rS, -1:i64)) - Complexity = 11
                  // Dst: (EQV8:i64 i64:i64:$rS, i64:i64:$rB)
/*4214*/        /*Scope*/ 23, /*->4238*/
/*4215*/          OPC_CheckInteger, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*4226*/          OPC_MoveParent,
/*4227*/          OPC_CheckType, MVT::i32,
/*4229*/          OPC_MorphNodeTo, TARGET_VAL(PPC::NOR), 0,
                      1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 0, 
                  // Src: (xor:i32 i32:i32:$in, -1:i32) - Complexity = 8
                  // Dst: (NOR:i32 ?:i32:$in, ?:i32:$in)
/*4238*/        0, /*End of Scope*/
/*4239*/      /*Scope*/ 19|128,1/*147*/, /*->4388*/
/*4241*/        OPC_RecordChild1, // #1 = $src2
/*4242*/        OPC_Scope, 119, /*->4363*/ // 3 children in Scope
/*4244*/          OPC_MoveChild, 1,
/*4246*/          OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*4249*/          OPC_Scope, 19, /*->4270*/ // 5 children in Scope
/*4251*/            OPC_CheckPredicate, 71, // Predicate_immZExt16
/*4253*/            OPC_MoveParent,
/*4254*/            OPC_CheckType, MVT::i32,
/*4256*/            OPC_EmitConvertToTarget, 1,
/*4258*/            OPC_EmitNodeXForm, 1, 2, // LO16
/*4261*/            OPC_MorphNodeTo, TARGET_VAL(PPC::XORI), 0,
                        1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 3, 
                    // Src: (xor:i32 i32:i32:$src1, (imm:i32)<<P:Predicate_immZExt16>><<X:LO16>>:$src2) - Complexity = 7
                    // Dst: (XORI:i32 i32:i32:$src1, (LO16:i32 (imm:i32):$src2))
/*4270*/          /*Scope*/ 19, /*->4290*/
/*4271*/            OPC_CheckPredicate, 72, // Predicate_imm16ShiftedZExt
/*4273*/            OPC_MoveParent,
/*4274*/            OPC_CheckType, MVT::i32,
/*4276*/            OPC_EmitConvertToTarget, 1,
/*4278*/            OPC_EmitNodeXForm, 0, 2, // HI16
/*4281*/            OPC_MorphNodeTo, TARGET_VAL(PPC::XORIS), 0,
                        1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 3, 
                    // Src: (xor:i32 i32:i32:$src1, (imm:i32)<<P:Predicate_imm16ShiftedZExt>><<X:HI16>>:$src2) - Complexity = 7
                    // Dst: (XORIS:i32 i32:i32:$src1, (HI16:i32 (imm:i32):$src2))
/*4290*/          /*Scope*/ 19, /*->4310*/
/*4291*/            OPC_CheckPredicate, 71, // Predicate_immZExt16
/*4293*/            OPC_MoveParent,
/*4294*/            OPC_CheckType, MVT::i64,
/*4296*/            OPC_EmitConvertToTarget, 1,
/*4298*/            OPC_EmitNodeXForm, 1, 2, // LO16
/*4301*/            OPC_MorphNodeTo, TARGET_VAL(PPC::XORI8), 0,
                        1/*#VTs*/, MVT::i64, 2/*#Ops*/, 0, 3, 
                    // Src: (xor:i64 i64:i64:$src1, (imm:i64)<<P:Predicate_immZExt16>><<X:LO16>>:$src2) - Complexity = 7
                    // Dst: (XORI8:i64 i64:i64:$src1, (LO16:i32 (imm:i64):$src2))
/*4310*/          /*Scope*/ 19, /*->4330*/
/*4311*/            OPC_CheckPredicate, 72, // Predicate_imm16ShiftedZExt
/*4313*/            OPC_MoveParent,
/*4314*/            OPC_CheckType, MVT::i64,
/*4316*/            OPC_EmitConvertToTarget, 1,
/*4318*/            OPC_EmitNodeXForm, 0, 2, // HI16
/*4321*/            OPC_MorphNodeTo, TARGET_VAL(PPC::XORIS8), 0,
                        1/*#VTs*/, MVT::i64, 2/*#Ops*/, 0, 3, 
                    // Src: (xor:i64 i64:i64:$src1, (imm:i64)<<P:Predicate_imm16ShiftedZExt>><<X:HI16>>:$src2) - Complexity = 7
                    // Dst: (XORIS8:i64 i64:i64:$src1, (HI16:i32 (imm:i64):$src2))
/*4330*/          /*Scope*/ 31, /*->4362*/
/*4331*/            OPC_MoveParent,
/*4332*/            OPC_CheckType, MVT::i32,
/*4334*/            OPC_EmitConvertToTarget, 1,
/*4336*/            OPC_EmitNodeXForm, 1, 2, // LO16
/*4339*/            OPC_EmitNode, TARGET_VAL(PPC::XORI), 0,
                        1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 3,  // Results = #4
/*4348*/            OPC_EmitConvertToTarget, 1,
/*4350*/            OPC_EmitNodeXForm, 0, 5, // HI16
/*4353*/            OPC_MorphNodeTo, TARGET_VAL(PPC::XORIS), 0,
                        1/*#VTs*/, MVT::i32, 2/*#Ops*/, 4, 6, 
                    // Src: (xor:i32 i32:i32:$in, (imm:i32):$imm) - Complexity = 6
                    // Dst: (XORIS:i32 (XORI:i32 ?:i32:$in, (LO16:i32 (imm:i32):$imm)), (HI16:i32 (imm:i32):$imm))
/*4362*/          0, /*End of Scope*/
/*4363*/        /*Scope*/ 11, /*->4375*/
/*4364*/          OPC_CheckType, MVT::i32,
/*4366*/          OPC_MorphNodeTo, TARGET_VAL(PPC::XOR), 0,
                      1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1, 
                  // Src: (xor:i32 i32:i32:$rS, i32:i32:$rB) - Complexity = 3
                  // Dst: (XOR:i32 i32:i32:$rS, i32:i32:$rB)
/*4375*/        /*Scope*/ 11, /*->4387*/
/*4376*/          OPC_CheckType, MVT::i64,
/*4378*/          OPC_MorphNodeTo, TARGET_VAL(PPC::XOR8), 0,
                      1/*#VTs*/, MVT::i64, 2/*#Ops*/, 0, 1, 
                  // Src: (xor:i64 i64:i64:$rS, i64:i64:$rB) - Complexity = 3
                  // Dst: (XOR8:i64 i64:i64:$rS, i64:i64:$rB)
/*4387*/        0, /*End of Scope*/
/*4388*/      0, /*End of Scope*/
/*4389*/    /*Scope*/ 74, /*->4464*/
/*4390*/      OPC_MoveChild, 0,
/*4392*/      OPC_SwitchOpcode /*2 cases */, 32,  TARGET_VAL(ISD::OR),// ->4428
/*4396*/        OPC_RecordChild0, // #0 = $vA
/*4397*/        OPC_RecordChild1, // #1 = $vB
/*4398*/        OPC_MoveParent,
/*4399*/        OPC_MoveChild, 1,
/*4401*/        OPC_CheckOpcode, TARGET_VAL(ISD::BITCAST),
/*4404*/        OPC_MoveChild, 0,
/*4406*/        OPC_CheckOpcode, TARGET_VAL(ISD::BUILD_VECTOR),
/*4409*/        OPC_CheckPredicate, 73, // Predicate_immAllOnesV
/*4411*/        OPC_CheckType, MVT::v16i8,
/*4413*/        OPC_MoveParent,
/*4414*/        OPC_MoveParent,
/*4415*/        OPC_CheckType, MVT::v4i32,
/*4417*/        OPC_CheckPatternPredicate, 0, // (PPCSubTarget.hasAltivec())
/*4419*/        OPC_MorphNodeTo, TARGET_VAL(PPC::VNOR), 0,
                    1/*#VTs*/, MVT::v4i32, 2/*#Ops*/, 0, 1, 
                // Src: (xor:v4i32 (or:v4i32 v4i32:v4i32:$vA, v4i32:v4i32:$vB), (bitconvert:v4i32 (build_vector:v16i8)<<P:Predicate_immAllOnesV>>)) - Complexity = 13
                // Dst: (VNOR:v4i32 v4i32:v4i32:$vA, v4i32:v4i32:$vB)
/*4428*/      /*SwitchOpcode*/ 32,  TARGET_VAL(ISD::BITCAST),// ->4463
/*4431*/        OPC_MoveChild, 0,
/*4433*/        OPC_CheckOpcode, TARGET_VAL(ISD::BUILD_VECTOR),
/*4436*/        OPC_CheckPredicate, 73, // Predicate_immAllOnesV
/*4438*/        OPC_CheckType, MVT::v16i8,
/*4440*/        OPC_MoveParent,
/*4441*/        OPC_MoveParent,
/*4442*/        OPC_MoveChild, 1,
/*4444*/        OPC_CheckOpcode, TARGET_VAL(ISD::OR),
/*4447*/        OPC_RecordChild0, // #0 = $vA
/*4448*/        OPC_RecordChild1, // #1 = $vB
/*4449*/        OPC_MoveParent,
/*4450*/        OPC_CheckType, MVT::v4i32,
/*4452*/        OPC_CheckPatternPredicate, 0, // (PPCSubTarget.hasAltivec())
/*4454*/        OPC_MorphNodeTo, TARGET_VAL(PPC::VNOR), 0,
                    1/*#VTs*/, MVT::v4i32, 2/*#Ops*/, 0, 1, 
                // Src: (xor:v4i32 (bitconvert:v4i32 (build_vector:v16i8)<<P:Predicate_immAllOnesV>>), (or:v4i32 v4i32:v4i32:$vA, v4i32:v4i32:$vB)) - Complexity = 13
                // Dst: (VNOR:v4i32 v4i32:v4i32:$vA, v4i32:v4i32:$vB)
/*4463*/      0, // EndSwitchOpcode
/*4464*/    /*Scope*/ 30, /*->4495*/
/*4465*/      OPC_RecordChild0, // #0 = $vA
/*4466*/      OPC_MoveChild, 1,
/*4468*/      OPC_CheckOpcode, TARGET_VAL(ISD::BITCAST),
/*4471*/      OPC_MoveChild, 0,
/*4473*/      OPC_CheckOpcode, TARGET_VAL(ISD::BUILD_VECTOR),
/*4476*/      OPC_CheckPredicate, 73, // Predicate_immAllOnesV
/*4478*/      OPC_CheckType, MVT::v16i8,
/*4480*/      OPC_MoveParent,
/*4481*/      OPC_MoveParent,
/*4482*/      OPC_CheckType, MVT::v4i32,
/*4484*/      OPC_CheckPatternPredicate, 0, // (PPCSubTarget.hasAltivec())
/*4486*/      OPC_MorphNodeTo, TARGET_VAL(PPC::VNOR), 0,
                  1/*#VTs*/, MVT::v4i32, 2/*#Ops*/, 0, 0, 
              // Src: (xor:v4i32 v4i32:v4i32:$vA, (bitconvert:v4i32 (build_vector:v16i8)<<P:Predicate_immAllOnesV>>)) - Complexity = 10
              // Dst: (VNOR:v4i32 ?:v4i32:$vA, ?:v4i32:$vA)
/*4495*/    /*Scope*/ 30, /*->4526*/
/*4496*/      OPC_MoveChild, 0,
/*4498*/      OPC_CheckOpcode, TARGET_VAL(ISD::BITCAST),
/*4501*/      OPC_MoveChild, 0,
/*4503*/      OPC_CheckOpcode, TARGET_VAL(ISD::BUILD_VECTOR),
/*4506*/      OPC_CheckPredicate, 73, // Predicate_immAllOnesV
/*4508*/      OPC_CheckType, MVT::v16i8,
/*4510*/      OPC_MoveParent,
/*4511*/      OPC_MoveParent,
/*4512*/      OPC_RecordChild1, // #0 = $vA
/*4513*/      OPC_CheckType, MVT::v4i32,
/*4515*/      OPC_CheckPatternPredicate, 0, // (PPCSubTarget.hasAltivec())
/*4517*/      OPC_MorphNodeTo, TARGET_VAL(PPC::VNOR), 0,
                  1/*#VTs*/, MVT::v4i32, 2/*#Ops*/, 0, 0, 
              // Src: (xor:v4i32 (bitconvert:v4i32 (build_vector:v16i8)<<P:Predicate_immAllOnesV>>), v4i32:v4i32:$vA) - Complexity = 10
              // Dst: (VNOR:v4i32 ?:v4i32:$vA, ?:v4i32:$vA)
/*4526*/    /*Scope*/ 15, /*->4542*/
/*4527*/      OPC_RecordChild0, // #0 = $vA
/*4528*/      OPC_RecordChild1, // #1 = $vB
/*4529*/      OPC_CheckType, MVT::v4i32,
/*4531*/      OPC_CheckPatternPredicate, 0, // (PPCSubTarget.hasAltivec())
/*4533*/      OPC_MorphNodeTo, TARGET_VAL(PPC::VXOR), 0,
                  1/*#VTs*/, MVT::v4i32, 2/*#Ops*/, 0, 1, 
              // Src: (xor:v4i32 v4i32:v4i32:$vA, v4i32:v4i32:$vB) - Complexity = 3
              // Dst: (VXOR:v4i32 v4i32:v4i32:$vA, v4i32:v4i32:$vB)
/*4542*/    0, /*End of Scope*/
/*4543*/  /*SwitchOpcode*/ 41|128,3/*425*/,  TARGET_VAL(ISD::AND),// ->4972
/*4547*/    OPC_Scope, 46, /*->4595*/ // 5 children in Scope
/*4549*/      OPC_RecordChild0, // #0 = $rS
/*4550*/      OPC_MoveChild, 1,
/*4552*/      OPC_CheckOpcode, TARGET_VAL(ISD::XOR),
/*4555*/      OPC_RecordChild0, // #1 = $rB
/*4556*/      OPC_MoveChild, 1,
/*4558*/      OPC_CheckInteger, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*4569*/      OPC_MoveParent,
/*4570*/      OPC_MoveParent,
/*4571*/      OPC_SwitchType /*2 cases */, 9,  MVT::i32,// ->4583
/*4574*/        OPC_MorphNodeTo, TARGET_VAL(PPC::ANDC), 0,
                    1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1, 
                // Src: (and:i32 i32:i32:$rS, (xor:i32 i32:i32:$rB, -1:i32)) - Complexity = 11
                // Dst: (ANDC:i32 i32:i32:$rS, i32:i32:$rB)
/*4583*/      /*SwitchType*/ 9,  MVT::i64,// ->4594
/*4585*/        OPC_MorphNodeTo, TARGET_VAL(PPC::ANDC8), 0,
                    1/*#VTs*/, MVT::i64, 2/*#Ops*/, 0, 1, 
                // Src: (and:i64 i64:i64:$rS, (xor:i64 i64:i64:$rB, -1:i64)) - Complexity = 11
                // Dst: (ANDC8:i64 i64:i64:$rS, i64:i64:$rB)
/*4594*/      0, // EndSwitchType
/*4595*/    /*Scope*/ 88, /*->4684*/
/*4596*/      OPC_MoveChild, 0,
/*4598*/      OPC_SwitchOpcode /*2 cases */, 41,  TARGET_VAL(ISD::XOR),// ->4643
/*4602*/        OPC_RecordChild0, // #0 = $rB
/*4603*/        OPC_MoveChild, 1,
/*4605*/        OPC_CheckInteger, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*4616*/        OPC_MoveParent,
/*4617*/        OPC_MoveParent,
/*4618*/        OPC_RecordChild1, // #1 = $rS
/*4619*/        OPC_SwitchType /*2 cases */, 9,  MVT::i32,// ->4631
/*4622*/          OPC_MorphNodeTo, TARGET_VAL(PPC::ANDC), 0,
                      1/*#VTs*/, MVT::i32, 2/*#Ops*/, 1, 0, 
                  // Src: (and:i32 (xor:i32 i32:i32:$rB, -1:i32), i32:i32:$rS) - Complexity = 11
                  // Dst: (ANDC:i32 i32:i32:$rS, i32:i32:$rB)
/*4631*/        /*SwitchType*/ 9,  MVT::i64,// ->4642
/*4633*/          OPC_MorphNodeTo, TARGET_VAL(PPC::ANDC8), 0,
                      1/*#VTs*/, MVT::i64, 2/*#Ops*/, 1, 0, 
                  // Src: (and:i64 (xor:i64 i64:i64:$rB, -1:i64), i64:i64:$rS) - Complexity = 11
                  // Dst: (ANDC8:i64 i64:i64:$rS, i64:i64:$rB)
/*4642*/        0, // EndSwitchType
/*4643*/      /*SwitchOpcode*/ 37,  TARGET_VAL(ISD::ROTL),// ->4683
/*4646*/        OPC_RecordChild0, // #0 = $in
/*4647*/        OPC_RecordChild1, // #1 = $sh
/*4648*/        OPC_CheckChild1Type, MVT::i32,
/*4650*/        OPC_MoveParent,
/*4651*/        OPC_RecordChild1, // #2 = $imm
/*4652*/        OPC_MoveChild, 1,
/*4654*/        OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*4657*/        OPC_CheckPredicate, 74, // Predicate_maskimm32
/*4659*/        OPC_MoveParent,
/*4660*/        OPC_CheckType, MVT::i32,
/*4662*/        OPC_EmitConvertToTarget, 2,
/*4664*/        OPC_EmitNodeXForm, 3, 3, // MB
/*4667*/        OPC_EmitConvertToTarget, 2,
/*4669*/        OPC_EmitNodeXForm, 4, 5, // ME
/*4672*/        OPC_MorphNodeTo, TARGET_VAL(PPC::RLWNM), 0,
                    1/*#VTs*/, MVT::i32, 4/*#Ops*/, 0, 1, 4, 6, 
                // Src: (and:i32 (rotl:i32 i32:i32:$in, i32:i32:$sh), (imm:i32)<<P:Predicate_maskimm32>>:$imm) - Complexity = 10
                // Dst: (RLWNM:i32 ?:i32:$in, ?:i32:$sh, (MB:i32 (imm:i32)<<P:Predicate_maskimm32>>:$imm), (ME:i32 (imm:i32)<<P:Predicate_maskimm32>>:$imm))
/*4683*/      0, // EndSwitchOpcode
/*4684*/    /*Scope*/ 67|128,1/*195*/, /*->4881*/
/*4686*/      OPC_RecordChild0, // #0 = $src1
/*4687*/      OPC_Scope, 119, /*->4808*/ // 2 children in Scope
/*4689*/        OPC_RecordChild1, // #1 = $src2
/*4690*/        OPC_Scope, 91, /*->4783*/ // 3 children in Scope
/*4692*/          OPC_MoveChild, 1,
/*4694*/          OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*4697*/          OPC_Scope, 20, /*->4719*/ // 4 children in Scope
/*4699*/            OPC_CheckPredicate, 71, // Predicate_immZExt16
/*4701*/            OPC_MoveParent,
/*4702*/            OPC_CheckType, MVT::i32,
/*4704*/            OPC_EmitConvertToTarget, 1,
/*4706*/            OPC_EmitNodeXForm, 1, 2, // LO16
/*4709*/            OPC_MorphNodeTo, TARGET_VAL(PPC::ANDIo), 0,
                        2/*#VTs*/, MVT::i32, MVT::i32, 2/*#Ops*/, 0, 3, 
                    // Src: (and:i32 i32:i32:$src1, (imm:i32)<<P:Predicate_immZExt16>><<X:LO16>>:$src2) - Complexity = 7
                    // Dst: (ANDIo:i32:i32 i32:i32:$src1, (LO16:i32 (imm:i32):$src2))
/*4719*/          /*Scope*/ 20, /*->4740*/
/*4720*/            OPC_CheckPredicate, 72, // Predicate_imm16ShiftedZExt
/*4722*/            OPC_MoveParent,
/*4723*/            OPC_CheckType, MVT::i32,
/*4725*/            OPC_EmitConvertToTarget, 1,
/*4727*/            OPC_EmitNodeXForm, 0, 2, // HI16
/*4730*/            OPC_MorphNodeTo, TARGET_VAL(PPC::ANDISo), 0,
                        2/*#VTs*/, MVT::i32, MVT::i32, 2/*#Ops*/, 0, 3, 
                    // Src: (and:i32 i32:i32:$src1, (imm:i32)<<P:Predicate_imm16ShiftedZExt>><<X:HI16>>:$src2) - Complexity = 7
                    // Dst: (ANDISo:i32:i32 i32:i32:$src1, (HI16:i32 (imm:i32):$src2))
/*4740*/          /*Scope*/ 20, /*->4761*/
/*4741*/            OPC_CheckPredicate, 71, // Predicate_immZExt16
/*4743*/            OPC_MoveParent,
/*4744*/            OPC_CheckType, MVT::i64,
/*4746*/            OPC_EmitConvertToTarget, 1,
/*4748*/            OPC_EmitNodeXForm, 1, 2, // LO16
/*4751*/            OPC_MorphNodeTo, TARGET_VAL(PPC::ANDIo8), 0,
                        2/*#VTs*/, MVT::i64, MVT::i32, 2/*#Ops*/, 0, 3, 
                    // Src: (and:i64 i64:i64:$src1, (imm:i64)<<P:Predicate_immZExt16>><<X:LO16>>:$src2) - Complexity = 7
                    // Dst: (ANDIo8:i64:i32 i64:i64:$src1, (LO16:i32 (imm:i64):$src2))
/*4761*/          /*Scope*/ 20, /*->4782*/
/*4762*/            OPC_CheckPredicate, 72, // Predicate_imm16ShiftedZExt
/*4764*/            OPC_MoveParent,
/*4765*/            OPC_CheckType, MVT::i64,
/*4767*/            OPC_EmitConvertToTarget, 1,
/*4769*/            OPC_EmitNodeXForm, 0, 2, // HI16
/*4772*/            OPC_MorphNodeTo, TARGET_VAL(PPC::ANDISo8), 0,
                        2/*#VTs*/, MVT::i64, MVT::i32, 2/*#Ops*/, 0, 3, 
                    // Src: (and:i64 i64:i64:$src1, (imm:i64)<<P:Predicate_imm16ShiftedZExt>><<X:HI16>>:$src2) - Complexity = 7
                    // Dst: (ANDISo8:i64:i32 i64:i64:$src1, (HI16:i32 (imm:i64):$src2))
/*4782*/          0, /*End of Scope*/
/*4783*/        /*Scope*/ 11, /*->4795*/
/*4784*/          OPC_CheckType, MVT::i32,
/*4786*/          OPC_MorphNodeTo, TARGET_VAL(PPC::AND), 0,
                      1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1, 
                  // Src: (and:i32 i32:i32:$rS, i32:i32:$rB) - Complexity = 3
                  // Dst: (AND:i32 i32:i32:$rS, i32:i32:$rB)
/*4795*/        /*Scope*/ 11, /*->4807*/
/*4796*/          OPC_CheckType, MVT::i64,
/*4798*/          OPC_MorphNodeTo, TARGET_VAL(PPC::AND8), 0,
                      1/*#VTs*/, MVT::i64, 2/*#Ops*/, 0, 1, 
                  // Src: (and:i64 i64:i64:$rS, i64:i64:$rB) - Complexity = 3
                  // Dst: (AND8:i64 i64:i64:$rS, i64:i64:$rB)
/*4807*/        0, /*End of Scope*/
/*4808*/      /*Scope*/ 71, /*->4880*/
/*4809*/        OPC_MoveChild, 1,
/*4811*/        OPC_CheckOpcode, TARGET_VAL(ISD::XOR),
/*4814*/        OPC_Scope, 31, /*->4847*/ // 2 children in Scope
/*4816*/          OPC_RecordChild0, // #1 = $vB
/*4817*/          OPC_MoveChild, 1,
/*4819*/          OPC_CheckOpcode, TARGET_VAL(ISD::BITCAST),
/*4822*/          OPC_MoveChild, 0,
/*4824*/          OPC_CheckOpcode, TARGET_VAL(ISD::BUILD_VECTOR),
/*4827*/          OPC_CheckPredicate, 73, // Predicate_immAllOnesV
/*4829*/          OPC_CheckType, MVT::v16i8,
/*4831*/          OPC_MoveParent,
/*4832*/          OPC_MoveParent,
/*4833*/          OPC_MoveParent,
/*4834*/          OPC_CheckType, MVT::v4i32,
/*4836*/          OPC_CheckPatternPredicate, 0, // (PPCSubTarget.hasAltivec())
/*4838*/          OPC_MorphNodeTo, TARGET_VAL(PPC::VANDC), 0,
                      1/*#VTs*/, MVT::v4i32, 2/*#Ops*/, 0, 1, 
                  // Src: (and:v4i32 v4i32:v4i32:$vA, (xor:v4i32 v4i32:v4i32:$vB, (bitconvert:v4i32 (build_vector:v16i8)<<P:Predicate_immAllOnesV>>))) - Complexity = 13
                  // Dst: (VANDC:v4i32 v4i32:v4i32:$vA, v4i32:v4i32:$vB)
/*4847*/        /*Scope*/ 31, /*->4879*/
/*4848*/          OPC_MoveChild, 0,
/*4850*/          OPC_CheckOpcode, TARGET_VAL(ISD::BITCAST),
/*4853*/          OPC_MoveChild, 0,
/*4855*/          OPC_CheckOpcode, TARGET_VAL(ISD::BUILD_VECTOR),
/*4858*/          OPC_CheckPredicate, 73, // Predicate_immAllOnesV
/*4860*/          OPC_CheckType, MVT::v16i8,
/*4862*/          OPC_MoveParent,
/*4863*/          OPC_MoveParent,
/*4864*/          OPC_RecordChild1, // #1 = $vB
/*4865*/          OPC_MoveParent,
/*4866*/          OPC_CheckType, MVT::v4i32,
/*4868*/          OPC_CheckPatternPredicate, 0, // (PPCSubTarget.hasAltivec())
/*4870*/          OPC_MorphNodeTo, TARGET_VAL(PPC::VANDC), 0,
                      1/*#VTs*/, MVT::v4i32, 2/*#Ops*/, 0, 1, 
                  // Src: (and:v4i32 v4i32:v4i32:$vA, (xor:v4i32 (bitconvert:v4i32 (build_vector:v16i8)<<P:Predicate_immAllOnesV>>), v4i32:v4i32:$vB)) - Complexity = 13
                  // Dst: (VANDC:v4i32 v4i32:v4i32:$vA, v4i32:v4i32:$vB)
/*4879*/        0, /*End of Scope*/
/*4880*/      0, /*End of Scope*/
/*4881*/    /*Scope*/ 73, /*->4955*/
/*4882*/      OPC_MoveChild, 0,
/*4884*/      OPC_CheckOpcode, TARGET_VAL(ISD::XOR),
/*4887*/      OPC_Scope, 32, /*->4921*/ // 2 children in Scope
/*4889*/        OPC_RecordChild0, // #0 = $vB
/*4890*/        OPC_MoveChild, 1,
/*4892*/        OPC_CheckOpcode, TARGET_VAL(ISD::BITCAST),
/*4895*/        OPC_MoveChild, 0,
/*4897*/        OPC_CheckOpcode, TARGET_VAL(ISD::BUILD_VECTOR),
/*4900*/        OPC_CheckPredicate, 73, // Predicate_immAllOnesV
/*4902*/        OPC_CheckType, MVT::v16i8,
/*4904*/        OPC_MoveParent,
/*4905*/        OPC_MoveParent,
/*4906*/        OPC_MoveParent,
/*4907*/        OPC_RecordChild1, // #1 = $vA
/*4908*/        OPC_CheckType, MVT::v4i32,
/*4910*/        OPC_CheckPatternPredicate, 0, // (PPCSubTarget.hasAltivec())
/*4912*/        OPC_MorphNodeTo, TARGET_VAL(PPC::VANDC), 0,
                    1/*#VTs*/, MVT::v4i32, 2/*#Ops*/, 1, 0, 
                // Src: (and:v4i32 (xor:v4i32 v4i32:v4i32:$vB, (bitconvert:v4i32 (build_vector:v16i8)<<P:Predicate_immAllOnesV>>)), v4i32:v4i32:$vA) - Complexity = 13
                // Dst: (VANDC:v4i32 v4i32:v4i32:$vA, v4i32:v4i32:$vB)
/*4921*/      /*Scope*/ 32, /*->4954*/
/*4922*/        OPC_MoveChild, 0,
/*4924*/        OPC_CheckOpcode, TARGET_VAL(ISD::BITCAST),
/*4927*/        OPC_MoveChild, 0,
/*4929*/        OPC_CheckOpcode, TARGET_VAL(ISD::BUILD_VECTOR),
/*4932*/        OPC_CheckPredicate, 73, // Predicate_immAllOnesV
/*4934*/        OPC_CheckType, MVT::v16i8,
/*4936*/        OPC_MoveParent,
/*4937*/        OPC_MoveParent,
/*4938*/        OPC_RecordChild1, // #0 = $vB
/*4939*/        OPC_MoveParent,
/*4940*/        OPC_RecordChild1, // #1 = $vA
/*4941*/        OPC_CheckType, MVT::v4i32,
/*4943*/        OPC_CheckPatternPredicate, 0, // (PPCSubTarget.hasAltivec())
/*4945*/        OPC_MorphNodeTo, TARGET_VAL(PPC::VANDC), 0,
                    1/*#VTs*/, MVT::v4i32, 2/*#Ops*/, 1, 0, 
                // Src: (and:v4i32 (xor:v4i32 (bitconvert:v4i32 (build_vector:v16i8)<<P:Predicate_immAllOnesV>>), v4i32:v4i32:$vB), v4i32:v4i32:$vA) - Complexity = 13
                // Dst: (VANDC:v4i32 v4i32:v4i32:$vA, v4i32:v4i32:$vB)
/*4954*/      0, /*End of Scope*/
/*4955*/    /*Scope*/ 15, /*->4971*/
/*4956*/      OPC_RecordChild0, // #0 = $vA
/*4957*/      OPC_RecordChild1, // #1 = $vB
/*4958*/      OPC_CheckType, MVT::v4i32,
/*4960*/      OPC_CheckPatternPredicate, 0, // (PPCSubTarget.hasAltivec())
/*4962*/      OPC_MorphNodeTo, TARGET_VAL(PPC::VAND), 0,
                  1/*#VTs*/, MVT::v4i32, 2/*#Ops*/, 0, 1, 
              // Src: (and:v4i32 v4i32:v4i32:$vA, v4i32:v4i32:$vB) - Complexity = 3
              // Dst: (VAND:v4i32 v4i32:v4i32:$vA, v4i32:v4i32:$vB)
/*4971*/    0, /*End of Scope*/
/*4972*/  /*SwitchOpcode*/ 4|128,2/*260*/,  TARGET_VAL(ISD::OR),// ->5236
/*4976*/    OPC_Scope, 46, /*->5024*/ // 3 children in Scope
/*4978*/      OPC_RecordChild0, // #0 = $rS
/*4979*/      OPC_MoveChild, 1,
/*4981*/      OPC_CheckOpcode, TARGET_VAL(ISD::XOR),
/*4984*/      OPC_RecordChild0, // #1 = $rB
/*4985*/      OPC_MoveChild, 1,
/*4987*/      OPC_CheckInteger, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*4998*/      OPC_MoveParent,
/*4999*/      OPC_MoveParent,
/*5000*/      OPC_SwitchType /*2 cases */, 9,  MVT::i32,// ->5012
/*5003*/        OPC_MorphNodeTo, TARGET_VAL(PPC::ORC), 0,
                    1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1, 
                // Src: (or:i32 i32:i32:$rS, (xor:i32 i32:i32:$rB, -1:i32)) - Complexity = 11
                // Dst: (ORC:i32 i32:i32:$rS, i32:i32:$rB)
/*5012*/      /*SwitchType*/ 9,  MVT::i64,// ->5023
/*5014*/        OPC_MorphNodeTo, TARGET_VAL(PPC::ORC8), 0,
                    1/*#VTs*/, MVT::i64, 2/*#Ops*/, 0, 1, 
                // Src: (or:i64 i64:i64:$rS, (xor:i64 i64:i64:$rB, -1:i64)) - Complexity = 11
                // Dst: (ORC8:i64 i64:i64:$rS, i64:i64:$rB)
/*5023*/      0, // EndSwitchType
/*5024*/    /*Scope*/ 46, /*->5071*/
/*5025*/      OPC_MoveChild, 0,
/*5027*/      OPC_CheckOpcode, TARGET_VAL(ISD::XOR),
/*5030*/      OPC_RecordChild0, // #0 = $rB
/*5031*/      OPC_MoveChild, 1,
/*5033*/      OPC_CheckInteger, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*5044*/      OPC_MoveParent,
/*5045*/      OPC_MoveParent,
/*5046*/      OPC_RecordChild1, // #1 = $rS
/*5047*/      OPC_SwitchType /*2 cases */, 9,  MVT::i32,// ->5059
/*5050*/        OPC_MorphNodeTo, TARGET_VAL(PPC::ORC), 0,
                    1/*#VTs*/, MVT::i32, 2/*#Ops*/, 1, 0, 
                // Src: (or:i32 (xor:i32 i32:i32:$rB, -1:i32), i32:i32:$rS) - Complexity = 11
                // Dst: (ORC:i32 i32:i32:$rS, i32:i32:$rB)
/*5059*/      /*SwitchType*/ 9,  MVT::i64,// ->5070
/*5061*/        OPC_MorphNodeTo, TARGET_VAL(PPC::ORC8), 0,
                    1/*#VTs*/, MVT::i64, 2/*#Ops*/, 1, 0, 
                // Src: (or:i64 (xor:i64 i64:i64:$rB, -1:i64), i64:i64:$rS) - Complexity = 11
                // Dst: (ORC8:i64 i64:i64:$rS, i64:i64:$rB)
/*5070*/      0, // EndSwitchType
/*5071*/    /*Scope*/ 34|128,1/*162*/, /*->5235*/
/*5073*/      OPC_RecordChild0, // #0 = $src1
/*5074*/      OPC_RecordChild1, // #1 = $src2
/*5075*/      OPC_Scope, 119, /*->5196*/ // 4 children in Scope
/*5077*/        OPC_MoveChild, 1,
/*5079*/        OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*5082*/        OPC_Scope, 19, /*->5103*/ // 5 children in Scope
/*5084*/          OPC_CheckPredicate, 71, // Predicate_immZExt16
/*5086*/          OPC_MoveParent,
/*5087*/          OPC_CheckType, MVT::i32,
/*5089*/          OPC_EmitConvertToTarget, 1,
/*5091*/          OPC_EmitNodeXForm, 1, 2, // LO16
/*5094*/          OPC_MorphNodeTo, TARGET_VAL(PPC::ORI), 0,
                      1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 3, 
                  // Src: (or:i32 i32:i32:$src1, (imm:i32)<<P:Predicate_immZExt16>><<X:LO16>>:$src2) - Complexity = 7
                  // Dst: (ORI:i32 i32:i32:$src1, (LO16:i32 (imm:i32):$src2))
/*5103*/        /*Scope*/ 19, /*->5123*/
/*5104*/          OPC_CheckPredicate, 72, // Predicate_imm16ShiftedZExt
/*5106*/          OPC_MoveParent,
/*5107*/          OPC_CheckType, MVT::i32,
/*5109*/          OPC_EmitConvertToTarget, 1,
/*5111*/          OPC_EmitNodeXForm, 0, 2, // HI16
/*5114*/          OPC_MorphNodeTo, TARGET_VAL(PPC::ORIS), 0,
                      1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 3, 
                  // Src: (or:i32 i32:i32:$src1, (imm:i32)<<P:Predicate_imm16ShiftedZExt>><<X:HI16>>:$src2) - Complexity = 7
                  // Dst: (ORIS:i32 i32:i32:$src1, (HI16:i32 (imm:i32):$src2))
/*5123*/        /*Scope*/ 19, /*->5143*/
/*5124*/          OPC_CheckPredicate, 71, // Predicate_immZExt16
/*5126*/          OPC_MoveParent,
/*5127*/          OPC_CheckType, MVT::i64,
/*5129*/          OPC_EmitConvertToTarget, 1,
/*5131*/          OPC_EmitNodeXForm, 1, 2, // LO16
/*5134*/          OPC_MorphNodeTo, TARGET_VAL(PPC::ORI8), 0,
                      1/*#VTs*/, MVT::i64, 2/*#Ops*/, 0, 3, 
                  // Src: (or:i64 i64:i64:$src1, (imm:i64)<<P:Predicate_immZExt16>><<X:LO16>>:$src2) - Complexity = 7
                  // Dst: (ORI8:i64 i64:i64:$src1, (LO16:i32 (imm:i64):$src2))
/*5143*/        /*Scope*/ 19, /*->5163*/
/*5144*/          OPC_CheckPredicate, 72, // Predicate_imm16ShiftedZExt
/*5146*/          OPC_MoveParent,
/*5147*/          OPC_CheckType, MVT::i64,
/*5149*/          OPC_EmitConvertToTarget, 1,
/*5151*/          OPC_EmitNodeXForm, 0, 2, // HI16
/*5154*/          OPC_MorphNodeTo, TARGET_VAL(PPC::ORIS8), 0,
                      1/*#VTs*/, MVT::i64, 2/*#Ops*/, 0, 3, 
                  // Src: (or:i64 i64:i64:$src1, (imm:i64)<<P:Predicate_imm16ShiftedZExt>><<X:HI16>>:$src2) - Complexity = 7
                  // Dst: (ORIS8:i64 i64:i64:$src1, (HI16:i32 (imm:i64):$src2))
/*5163*/        /*Scope*/ 31, /*->5195*/
/*5164*/          OPC_MoveParent,
/*5165*/          OPC_CheckType, MVT::i32,
/*5167*/          OPC_EmitConvertToTarget, 1,
/*5169*/          OPC_EmitNodeXForm, 1, 2, // LO16
/*5172*/          OPC_EmitNode, TARGET_VAL(PPC::ORI), 0,
                      1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 3,  // Results = #4
/*5181*/          OPC_EmitConvertToTarget, 1,
/*5183*/          OPC_EmitNodeXForm, 0, 5, // HI16
/*5186*/          OPC_MorphNodeTo, TARGET_VAL(PPC::ORIS), 0,
                      1/*#VTs*/, MVT::i32, 2/*#Ops*/, 4, 6, 
                  // Src: (or:i32 i32:i32:$in, (imm:i32):$imm) - Complexity = 6
                  // Dst: (ORIS:i32 (ORI:i32 ?:i32:$in, (LO16:i32 (imm:i32):$imm)), (HI16:i32 (imm:i32):$imm))
/*5195*/        0, /*End of Scope*/
/*5196*/      /*Scope*/ 11, /*->5208*/
/*5197*/        OPC_CheckType, MVT::i32,
/*5199*/        OPC_MorphNodeTo, TARGET_VAL(PPC::OR), 0,
                    1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1, 
                // Src: (or:i32 i32:i32:$rS, i32:i32:$rB) - Complexity = 3
                // Dst: (OR:i32 i32:i32:$rS, i32:i32:$rB)
/*5208*/      /*Scope*/ 11, /*->5220*/
/*5209*/        OPC_CheckType, MVT::i64,
/*5211*/        OPC_MorphNodeTo, TARGET_VAL(PPC::OR8), 0,
                    1/*#VTs*/, MVT::i64, 2/*#Ops*/, 0, 1, 
                // Src: (or:i64 i64:i64:$rS, i64:i64:$rB) - Complexity = 3
                // Dst: (OR8:i64 i64:i64:$rS, i64:i64:$rB)
/*5220*/      /*Scope*/ 13, /*->5234*/
/*5221*/        OPC_CheckType, MVT::v4i32,
/*5223*/        OPC_CheckPatternPredicate, 0, // (PPCSubTarget.hasAltivec())
/*5225*/        OPC_MorphNodeTo, TARGET_VAL(PPC::VOR), 0,
                    1/*#VTs*/, MVT::v4i32, 2/*#Ops*/, 0, 1, 
                // Src: (or:v4i32 v4i32:v4i32:$vA, v4i32:v4i32:$vB) - Complexity = 3
                // Dst: (VOR:v4i32 v4i32:v4i32:$vA, v4i32:v4i32:$vB)
/*5234*/      0, /*End of Scope*/
/*5235*/    0, /*End of Scope*/
/*5236*/  /*SwitchOpcode*/ 30|128,1/*158*/,  TARGET_VAL(PPCISD::Hi),// ->5398
/*5240*/    OPC_RecordChild0, // #0 = $in
/*5241*/    OPC_MoveChild, 0,
/*5243*/    OPC_SwitchOpcode /*5 cases */, 28,  TARGET_VAL(ISD::TargetGlobalAddress),// ->5275
/*5247*/      OPC_MoveParent,
/*5248*/      OPC_MoveChild, 1,
/*5250*/      OPC_CheckInteger, 0, 
/*5252*/      OPC_MoveParent,
/*5253*/      OPC_SwitchType /*2 cases */, 8,  MVT::i32,// ->5264
/*5256*/        OPC_MorphNodeTo, TARGET_VAL(PPC::LIS), 0,
                    1/*#VTs*/, MVT::i32, 1/*#Ops*/, 0, 
                // Src: (PPChi:i32 (tglobaladdr:i32):$in, 0:i32) - Complexity = 11
                // Dst: (LIS:i32 (tglobaladdr:i32):$in)
/*5264*/      /*SwitchType*/ 8,  MVT::i64,// ->5274
/*5266*/        OPC_MorphNodeTo, TARGET_VAL(PPC::LIS8), 0,
                    1/*#VTs*/, MVT::i64, 1/*#Ops*/, 0, 
                // Src: (PPChi:i64 (tglobaladdr:i64):$in, 0:i64) - Complexity = 11
                // Dst: (LIS8:i64 (tglobaladdr:i64):$in)
/*5274*/      0, // EndSwitchType
/*5275*/    /*SwitchOpcode*/ 28,  TARGET_VAL(ISD::TargetConstantPool),// ->5306
/*5278*/      OPC_MoveParent,
/*5279*/      OPC_MoveChild, 1,
/*5281*/      OPC_CheckInteger, 0, 
/*5283*/      OPC_MoveParent,
/*5284*/      OPC_SwitchType /*2 cases */, 8,  MVT::i32,// ->5295
/*5287*/        OPC_MorphNodeTo, TARGET_VAL(PPC::LIS), 0,
                    1/*#VTs*/, MVT::i32, 1/*#Ops*/, 0, 
                // Src: (PPChi:i32 (tconstpool:i32):$in, 0:i32) - Complexity = 11
                // Dst: (LIS:i32 (tconstpool:i32):$in)
/*5295*/      /*SwitchType*/ 8,  MVT::i64,// ->5305
/*5297*/        OPC_MorphNodeTo, TARGET_VAL(PPC::LIS8), 0,
                    1/*#VTs*/, MVT::i64, 1/*#Ops*/, 0, 
                // Src: (PPChi:i64 (tconstpool:i64):$in, 0:i64) - Complexity = 11
                // Dst: (LIS8:i64 (tconstpool:i64):$in)
/*5305*/      0, // EndSwitchType
/*5306*/    /*SwitchOpcode*/ 28,  TARGET_VAL(ISD::TargetJumpTable),// ->5337
/*5309*/      OPC_MoveParent,
/*5310*/      OPC_MoveChild, 1,
/*5312*/      OPC_CheckInteger, 0, 
/*5314*/      OPC_MoveParent,
/*5315*/      OPC_SwitchType /*2 cases */, 8,  MVT::i32,// ->5326
/*5318*/        OPC_MorphNodeTo, TARGET_VAL(PPC::LIS), 0,
                    1/*#VTs*/, MVT::i32, 1/*#Ops*/, 0, 
                // Src: (PPChi:i32 (tjumptable:i32):$in, 0:i32) - Complexity = 11
                // Dst: (LIS:i32 (tjumptable:i32):$in)
/*5326*/      /*SwitchType*/ 8,  MVT::i64,// ->5336
/*5328*/        OPC_MorphNodeTo, TARGET_VAL(PPC::LIS8), 0,
                    1/*#VTs*/, MVT::i64, 1/*#Ops*/, 0, 
                // Src: (PPChi:i64 (tjumptable:i64):$in, 0:i64) - Complexity = 11
                // Dst: (LIS8:i64 (tjumptable:i64):$in)
/*5336*/      0, // EndSwitchType
/*5337*/    /*SwitchOpcode*/ 28,  TARGET_VAL(ISD::TargetBlockAddress),// ->5368
/*5340*/      OPC_MoveParent,
/*5341*/      OPC_MoveChild, 1,
/*5343*/      OPC_CheckInteger, 0, 
/*5345*/      OPC_MoveParent,
/*5346*/      OPC_SwitchType /*2 cases */, 8,  MVT::i32,// ->5357
/*5349*/        OPC_MorphNodeTo, TARGET_VAL(PPC::LIS), 0,
                    1/*#VTs*/, MVT::i32, 1/*#Ops*/, 0, 
                // Src: (PPChi:i32 (tblockaddress:i32):$in, 0:i32) - Complexity = 11
                // Dst: (LIS:i32 (tblockaddress:i32):$in)
/*5357*/      /*SwitchType*/ 8,  MVT::i64,// ->5367
/*5359*/        OPC_MorphNodeTo, TARGET_VAL(PPC::LIS8), 0,
                    1/*#VTs*/, MVT::i64, 1/*#Ops*/, 0, 
                // Src: (PPChi:i64 (tblockaddress:i64):$in, 0:i64) - Complexity = 11
                // Dst: (LIS8:i64 (tblockaddress:i64):$in)
/*5367*/      0, // EndSwitchType
/*5368*/    /*SwitchOpcode*/ 26,  TARGET_VAL(ISD::TargetGlobalTLSAddress),// ->5397
/*5371*/      OPC_MoveParent,
/*5372*/      OPC_RecordChild1, // #1 = $in
/*5373*/      OPC_SwitchType /*2 cases */, 9,  MVT::i32,// ->5385
/*5376*/        OPC_MorphNodeTo, TARGET_VAL(PPC::ADDIS), 0,
                    1/*#VTs*/, MVT::i32, 2/*#Ops*/, 1, 0, 
                // Src: (PPChi:i32 (tglobaltlsaddr:i32):$g, i32:i32:$in) - Complexity = 6
                // Dst: (ADDIS:i32 ?:i32:$in, (tglobaltlsaddr:i32):$g)
/*5385*/      /*SwitchType*/ 9,  MVT::i64,// ->5396
/*5387*/        OPC_MorphNodeTo, TARGET_VAL(PPC::ADDIS8), 0,
                    1/*#VTs*/, MVT::i64, 2/*#Ops*/, 1, 0, 
                // Src: (PPChi:i64 (tglobaltlsaddr:i64):$g, i64:i64:$in) - Complexity = 6
                // Dst: (ADDIS8:i64 ?:i64:$in, (tglobaltlsaddr:i64):$g)
/*5396*/      0, // EndSwitchType
/*5397*/    0, // EndSwitchOpcode
/*5398*/  /*SwitchOpcode*/ 30|128,1/*158*/,  TARGET_VAL(PPCISD::Lo),// ->5560
/*5402*/    OPC_RecordChild0, // #0 = $in
/*5403*/    OPC_MoveChild, 0,
/*5405*/    OPC_SwitchOpcode /*5 cases */, 28,  TARGET_VAL(ISD::TargetGlobalAddress),// ->5437
/*5409*/      OPC_MoveParent,
/*5410*/      OPC_MoveChild, 1,
/*5412*/      OPC_CheckInteger, 0, 
/*5414*/      OPC_MoveParent,
/*5415*/      OPC_SwitchType /*2 cases */, 8,  MVT::i32,// ->5426
/*5418*/        OPC_MorphNodeTo, TARGET_VAL(PPC::LI), 0,
                    1/*#VTs*/, MVT::i32, 1/*#Ops*/, 0, 
                // Src: (PPClo:i32 (tglobaladdr:i32):$in, 0:i32) - Complexity = 11
                // Dst: (LI:i32 (tglobaladdr:i32):$in)
/*5426*/      /*SwitchType*/ 8,  MVT::i64,// ->5436
/*5428*/        OPC_MorphNodeTo, TARGET_VAL(PPC::LI8), 0,
                    1/*#VTs*/, MVT::i64, 1/*#Ops*/, 0, 
                // Src: (PPClo:i64 (tglobaladdr:i64):$in, 0:i64) - Complexity = 11
                // Dst: (LI8:i64 (tglobaladdr:i64):$in)
/*5436*/      0, // EndSwitchType
/*5437*/    /*SwitchOpcode*/ 28,  TARGET_VAL(ISD::TargetConstantPool),// ->5468
/*5440*/      OPC_MoveParent,
/*5441*/      OPC_MoveChild, 1,
/*5443*/      OPC_CheckInteger, 0, 
/*5445*/      OPC_MoveParent,
/*5446*/      OPC_SwitchType /*2 cases */, 8,  MVT::i32,// ->5457
/*5449*/        OPC_MorphNodeTo, TARGET_VAL(PPC::LI), 0,
                    1/*#VTs*/, MVT::i32, 1/*#Ops*/, 0, 
                // Src: (PPClo:i32 (tconstpool:i32):$in, 0:i32) - Complexity = 11
                // Dst: (LI:i32 (tconstpool:i32):$in)
/*5457*/      /*SwitchType*/ 8,  MVT::i64,// ->5467
/*5459*/        OPC_MorphNodeTo, TARGET_VAL(PPC::LI8), 0,
                    1/*#VTs*/, MVT::i64, 1/*#Ops*/, 0, 
                // Src: (PPClo:i64 (tconstpool:i64):$in, 0:i64) - Complexity = 11
                // Dst: (LI8:i64 (tconstpool:i64):$in)
/*5467*/      0, // EndSwitchType
/*5468*/    /*SwitchOpcode*/ 28,  TARGET_VAL(ISD::TargetJumpTable),// ->5499
/*5471*/      OPC_MoveParent,
/*5472*/      OPC_MoveChild, 1,
/*5474*/      OPC_CheckInteger, 0, 
/*5476*/      OPC_MoveParent,
/*5477*/      OPC_SwitchType /*2 cases */, 8,  MVT::i32,// ->5488
/*5480*/        OPC_MorphNodeTo, TARGET_VAL(PPC::LI), 0,
                    1/*#VTs*/, MVT::i32, 1/*#Ops*/, 0, 
                // Src: (PPClo:i32 (tjumptable:i32):$in, 0:i32) - Complexity = 11
                // Dst: (LI:i32 (tjumptable:i32):$in)
/*5488*/      /*SwitchType*/ 8,  MVT::i64,// ->5498
/*5490*/        OPC_MorphNodeTo, TARGET_VAL(PPC::LI8), 0,
                    1/*#VTs*/, MVT::i64, 1/*#Ops*/, 0, 
                // Src: (PPClo:i64 (tjumptable:i64):$in, 0:i64) - Complexity = 11
                // Dst: (LI8:i64 (tjumptable:i64):$in)
/*5498*/      0, // EndSwitchType
/*5499*/    /*SwitchOpcode*/ 28,  TARGET_VAL(ISD::TargetBlockAddress),// ->5530
/*5502*/      OPC_MoveParent,
/*5503*/      OPC_MoveChild, 1,
/*5505*/      OPC_CheckInteger, 0, 
/*5507*/      OPC_MoveParent,
/*5508*/      OPC_SwitchType /*2 cases */, 8,  MVT::i32,// ->5519
/*5511*/        OPC_MorphNodeTo, TARGET_VAL(PPC::LI), 0,
                    1/*#VTs*/, MVT::i32, 1/*#Ops*/, 0, 
                // Src: (PPClo:i32 (tblockaddress:i32):$in, 0:i32) - Complexity = 11
                // Dst: (LI:i32 (tblockaddress:i32):$in)
/*5519*/      /*SwitchType*/ 8,  MVT::i64,// ->5529
/*5521*/        OPC_MorphNodeTo, TARGET_VAL(PPC::LI8), 0,
                    1/*#VTs*/, MVT::i64, 1/*#Ops*/, 0, 
                // Src: (PPClo:i64 (tblockaddress:i64):$in, 0:i64) - Complexity = 11
                // Dst: (LI8:i64 (tblockaddress:i64):$in)
/*5529*/      0, // EndSwitchType
/*5530*/    /*SwitchOpcode*/ 26,  TARGET_VAL(ISD::TargetGlobalTLSAddress),// ->5559
/*5533*/      OPC_MoveParent,
/*5534*/      OPC_RecordChild1, // #1 = $in
/*5535*/      OPC_SwitchType /*2 cases */, 9,  MVT::i32,// ->5547
/*5538*/        OPC_MorphNodeTo, TARGET_VAL(PPC::ADDI), 0,
                    1/*#VTs*/, MVT::i32, 2/*#Ops*/, 1, 0, 
                // Src: (PPClo:i32 (tglobaltlsaddr:i32):$g, i32:i32:$in) - Complexity = 6
                // Dst: (ADDI:i32 ?:i32:$in, (tglobaltlsaddr:i32):$g)
/*5547*/      /*SwitchType*/ 9,  MVT::i64,// ->5558
/*5549*/        OPC_MorphNodeTo, TARGET_VAL(PPC::ADDI8), 0,
                    1/*#VTs*/, MVT::i64, 2/*#Ops*/, 1, 0, 
                // Src: (PPClo:i64 (tglobaltlsaddr:i64):$g, i64:i64:$in) - Complexity = 6
                // Dst: (ADDI8:i64 ?:i64:$in, (tglobaltlsaddr:i64):$g)
/*5558*/      0, // EndSwitchType
/*5559*/    0, // EndSwitchOpcode
/*5560*/  /*SwitchOpcode*/ 26,  TARGET_VAL(ISD::CALLSEQ_END),// ->5589
/*5563*/    OPC_RecordNode,   // #0 = 'callseq_end' chained node
/*5564*/    OPC_CaptureGlueInput,
/*5565*/    OPC_RecordChild1, // #1 = $amt1
/*5566*/    OPC_MoveChild, 1,
/*5568*/    OPC_CheckOpcode, TARGET_VAL(ISD::TargetConstant),
/*5571*/    OPC_MoveParent,
/*5572*/    OPC_RecordChild2, // #2 = $amt2
/*5573*/    OPC_MoveChild, 2,
/*5575*/    OPC_CheckOpcode, TARGET_VAL(ISD::TargetConstant),
/*5578*/    OPC_MoveParent,
/*5579*/    OPC_EmitMergeInputChains1_0,
/*5580*/    OPC_MorphNodeTo, TARGET_VAL(PPC::ADJCALLSTACKUP), 0|OPFL_Chain|OPFL_GlueInput|OPFL_GlueOutput,
                1/*#VTs*/, MVT::i32, 2/*#Ops*/, 1, 2, 
            // Src: (callseq_end (timm:i32):$amt1, (timm:i32):$amt2) - Complexity = 9
            // Dst: (ADJCALLSTACKUP:i32 (timm:i32):$amt1, (timm:i32):$amt2)
/*5589*/  /*SwitchOpcode*/ 70|128,1/*198*/,  TARGET_VAL(PPCISD::TC_RETURN),// ->5791
/*5593*/    OPC_RecordNode,   // #0 = 'PPCtc_return' chained node
/*5594*/    OPC_CaptureGlueInput,
/*5595*/    OPC_RecordChild1, // #1 = $func
/*5596*/    OPC_Scope, 21|128,1/*149*/, /*->5748*/ // 3 children in Scope
/*5599*/      OPC_MoveChild, 1,
/*5601*/      OPC_SwitchOpcode /*3 cases */, 48,  TARGET_VAL(ISD::Constant),// ->5653
/*5605*/        OPC_SwitchType /*2 cases */, 21,  MVT::i32,// ->5629
/*5608*/          OPC_MoveParent,
/*5609*/          OPC_RecordChild2, // #2 = $offset
/*5610*/          OPC_MoveChild, 2,
/*5612*/          OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*5615*/          OPC_MoveParent,
/*5616*/          OPC_EmitMergeInputChains1_0,
/*5617*/          OPC_EmitConvertToTarget, 1,
/*5619*/          OPC_EmitConvertToTarget, 2,
/*5621*/          OPC_MorphNodeTo, TARGET_VAL(PPC::TCRETURNai), 0|OPFL_Chain|OPFL_GlueInput|OPFL_Variadic2,
                      0/*#VTs*/, 2/*#Ops*/, 3, 4, 
                  // Src: (PPCtc_return (imm:i32):$func, (imm:i32):$offset) - Complexity = 9
                  // Dst: (TCRETURNai (imm:i32):$func, (imm:i32):$offset)
/*5629*/        /*SwitchType*/ 21,  MVT::i64,// ->5652
/*5631*/          OPC_MoveParent,
/*5632*/          OPC_RecordChild2, // #2 = $offset
/*5633*/          OPC_MoveChild, 2,
/*5635*/          OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*5638*/          OPC_MoveParent,
/*5639*/          OPC_EmitMergeInputChains1_0,
/*5640*/          OPC_EmitConvertToTarget, 1,
/*5642*/          OPC_EmitConvertToTarget, 2,
/*5644*/          OPC_MorphNodeTo, TARGET_VAL(PPC::TCRETURNai8), 0|OPFL_Chain|OPFL_GlueInput|OPFL_Variadic2,
                      0/*#VTs*/, 2/*#Ops*/, 3, 4, 
                  // Src: (PPCtc_return (imm:i64):$func, (imm:i32):$offset) - Complexity = 9
                  // Dst: (TCRETURNai8 (imm:i64):$func, (imm:i32):$offset)
/*5652*/        0, // EndSwitchType
/*5653*/      /*SwitchOpcode*/ 44,  TARGET_VAL(ISD::TargetGlobalAddress),// ->5700
/*5656*/        OPC_SwitchType /*2 cases */, 19,  MVT::i32,// ->5678
/*5659*/          OPC_MoveParent,
/*5660*/          OPC_RecordChild2, // #2 = $imm
/*5661*/          OPC_MoveChild, 2,
/*5663*/          OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*5666*/          OPC_MoveParent,
/*5667*/          OPC_EmitMergeInputChains1_0,
/*5668*/          OPC_EmitConvertToTarget, 2,
/*5670*/          OPC_MorphNodeTo, TARGET_VAL(PPC::TCRETURNdi), 0|OPFL_Chain|OPFL_GlueInput|OPFL_Variadic2,
                      0/*#VTs*/, 2/*#Ops*/, 1, 3, 
                  // Src: (PPCtc_return (tglobaladdr:i32):$dst, (imm:i32):$imm) - Complexity = 9
                  // Dst: (TCRETURNdi (tglobaladdr:i32):$dst, (imm:i32):$imm)
/*5678*/        /*SwitchType*/ 19,  MVT::i64,// ->5699
/*5680*/          OPC_MoveParent,
/*5681*/          OPC_RecordChild2, // #2 = $imm
/*5682*/          OPC_MoveChild, 2,
/*5684*/          OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*5687*/          OPC_MoveParent,
/*5688*/          OPC_EmitMergeInputChains1_0,
/*5689*/          OPC_EmitConvertToTarget, 2,
/*5691*/          OPC_MorphNodeTo, TARGET_VAL(PPC::TCRETURNdi8), 0|OPFL_Chain|OPFL_GlueInput|OPFL_Variadic2,
                      0/*#VTs*/, 2/*#Ops*/, 1, 3, 
                  // Src: (PPCtc_return (tglobaladdr:i64):$dst, (imm:i32):$imm) - Complexity = 9
                  // Dst: (TCRETURNdi8 (tglobaladdr:i64):$dst, (imm:i32):$imm)
/*5699*/        0, // EndSwitchType
/*5700*/      /*SwitchOpcode*/ 44,  TARGET_VAL(ISD::TargetExternalSymbol),// ->5747
/*5703*/        OPC_SwitchType /*2 cases */, 19,  MVT::i32,// ->5725
/*5706*/          OPC_MoveParent,
/*5707*/          OPC_RecordChild2, // #2 = $imm
/*5708*/          OPC_MoveChild, 2,
/*5710*/          OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*5713*/          OPC_MoveParent,
/*5714*/          OPC_EmitMergeInputChains1_0,
/*5715*/          OPC_EmitConvertToTarget, 2,
/*5717*/          OPC_MorphNodeTo, TARGET_VAL(PPC::TCRETURNdi), 0|OPFL_Chain|OPFL_GlueInput|OPFL_Variadic2,
                      0/*#VTs*/, 2/*#Ops*/, 1, 3, 
                  // Src: (PPCtc_return (texternalsym:i32):$dst, (imm:i32):$imm) - Complexity = 9
                  // Dst: (TCRETURNdi (texternalsym:i32):$dst, (imm:i32):$imm)
/*5725*/        /*SwitchType*/ 19,  MVT::i64,// ->5746
/*5727*/          OPC_MoveParent,
/*5728*/          OPC_RecordChild2, // #2 = $imm
/*5729*/          OPC_MoveChild, 2,
/*5731*/          OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*5734*/          OPC_MoveParent,
/*5735*/          OPC_EmitMergeInputChains1_0,
/*5736*/          OPC_EmitConvertToTarget, 2,
/*5738*/          OPC_MorphNodeTo, TARGET_VAL(PPC::TCRETURNdi8), 0|OPFL_Chain|OPFL_GlueInput|OPFL_Variadic2,
                      0/*#VTs*/, 2/*#Ops*/, 1, 3, 
                  // Src: (PPCtc_return (texternalsym:i64):$dst, (imm:i32):$imm) - Complexity = 9
                  // Dst: (TCRETURNdi8 (texternalsym:i64):$dst, (imm:i32):$imm)
/*5746*/        0, // EndSwitchType
/*5747*/      0, // EndSwitchOpcode
/*5748*/    /*Scope*/ 20, /*->5769*/
/*5749*/      OPC_CheckChild1Type, MVT::i32,
/*5751*/      OPC_RecordChild2, // #2 = $imm
/*5752*/      OPC_MoveChild, 2,
/*5754*/      OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*5757*/      OPC_MoveParent,
/*5758*/      OPC_EmitMergeInputChains1_0,
/*5759*/      OPC_EmitConvertToTarget, 2,
/*5761*/      OPC_MorphNodeTo, TARGET_VAL(PPC::TCRETURNri), 0|OPFL_Chain|OPFL_GlueInput|OPFL_Variadic2,
                  0/*#VTs*/, 2/*#Ops*/, 1, 3, 
              // Src: (PPCtc_return CTRRC:i32:$dst, (imm:i32):$imm) - Complexity = 6
              // Dst: (TCRETURNri CTRRC:i32:$dst, (imm:i32):$imm)
/*5769*/    /*Scope*/ 20, /*->5790*/
/*5770*/      OPC_CheckChild1Type, MVT::i64,
/*5772*/      OPC_RecordChild2, // #2 = $imm
/*5773*/      OPC_MoveChild, 2,
/*5775*/      OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*5778*/      OPC_MoveParent,
/*5779*/      OPC_EmitMergeInputChains1_0,
/*5780*/      OPC_EmitConvertToTarget, 2,
/*5782*/      OPC_MorphNodeTo, TARGET_VAL(PPC::TCRETURNri8), 0|OPFL_Chain|OPFL_GlueInput|OPFL_Variadic2,
                  0/*#VTs*/, 2/*#Ops*/, 1, 3, 
              // Src: (PPCtc_return CTRRC8:i64:$dst, (imm:i32):$imm) - Complexity = 6
              // Dst: (TCRETURNri8 CTRRC8:i64:$dst, (imm:i32):$imm)
/*5790*/    0, /*End of Scope*/
/*5791*/  /*SwitchOpcode*/ 24,  TARGET_VAL(ISD::ATOMIC_FENCE),// ->5818
/*5794*/    OPC_RecordNode,   // #0 = 'atomic_fence' chained node
/*5795*/    OPC_MoveChild, 1,
/*5797*/    OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*5800*/    OPC_MoveParent,
/*5801*/    OPC_MoveChild, 2,
/*5803*/    OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*5806*/    OPC_MoveParent,
/*5807*/    OPC_EmitMergeInputChains1_0,
/*5808*/    OPC_EmitInteger, MVT::i32, 0, 
/*5811*/    OPC_MorphNodeTo, TARGET_VAL(PPC::SYNC), 0|OPFL_Chain,
                0/*#VTs*/, 1/*#Ops*/, 1, 
            // Src: (atomic_fence (imm:iPTR), (imm:iPTR)) - Complexity = 9
            // Dst: (SYNC 0:i32)
/*5818*/  /*SwitchOpcode*/ 38,  TARGET_VAL(PPCISD::EH_SJLJ_SETJMP),// ->5859
/*5821*/    OPC_RecordNode,   // #0 = 'PPCeh_sjlj_setjmp' chained node
/*5822*/    OPC_RecordChild1, // #1 = $buf
/*5823*/    OPC_CheckType, MVT::i32,
/*5825*/    OPC_Scope, 15, /*->5842*/ // 2 children in Scope
/*5827*/      OPC_CheckPatternPredicate, 1, // (!PPCSubTarget.isPPC64())
/*5829*/      OPC_CheckComplexPat, /*CP*/5, /*#*/1, // SelectAddr:$buf #2
/*5832*/      OPC_EmitMergeInputChains1_0,
/*5833*/      OPC_MorphNodeTo, TARGET_VAL(PPC::EH_SjLj_SetJmp32), 0|OPFL_Chain,
                  2/*#VTs*/, MVT::i32, MVT::i32, 1/*#Ops*/, 2, 
              // Src: (PPCeh_sjlj_setjmp:i32 addr:iPTR:$buf) - Complexity = 9
              // Dst: (EH_SjLj_SetJmp32:i32:i32 addr:iPTR:$buf)
/*5842*/    /*Scope*/ 15, /*->5858*/
/*5843*/      OPC_CheckPatternPredicate, 2, // (PPCSubTarget.isPPC64())
/*5845*/      OPC_CheckComplexPat, /*CP*/5, /*#*/1, // SelectAddr:$buf #2
/*5848*/      OPC_EmitMergeInputChains1_0,
/*5849*/      OPC_MorphNodeTo, TARGET_VAL(PPC::EH_SjLj_SetJmp64), 0|OPFL_Chain,
                  2/*#VTs*/, MVT::i32, MVT::i64, 1/*#Ops*/, 2, 
              // Src: (PPCeh_sjlj_setjmp:i32 addr:iPTR:$buf) - Complexity = 9
              // Dst: (EH_SjLj_SetJmp64:i32:i64 addr:iPTR:$buf)
/*5858*/    0, /*End of Scope*/
/*5859*/  /*SwitchOpcode*/ 32,  TARGET_VAL(PPCISD::EH_SJLJ_LONGJMP),// ->5894
/*5862*/    OPC_RecordNode,   // #0 = 'PPCeh_sjlj_longjmp' chained node
/*5863*/    OPC_RecordChild1, // #1 = $buf
/*5864*/    OPC_Scope, 13, /*->5879*/ // 2 children in Scope
/*5866*/      OPC_CheckPatternPredicate, 1, // (!PPCSubTarget.isPPC64())
/*5868*/      OPC_CheckComplexPat, /*CP*/5, /*#*/1, // SelectAddr:$buf #2
/*5871*/      OPC_EmitMergeInputChains1_0,
/*5872*/      OPC_MorphNodeTo, TARGET_VAL(PPC::EH_SjLj_LongJmp32), 0|OPFL_Chain,
                  0/*#VTs*/, 1/*#Ops*/, 2, 
              // Src: (PPCeh_sjlj_longjmp addr:iPTR:$buf) - Complexity = 9
              // Dst: (EH_SjLj_LongJmp32 addr:iPTR:$buf)
/*5879*/    /*Scope*/ 13, /*->5893*/
/*5880*/      OPC_CheckPatternPredicate, 2, // (PPCSubTarget.isPPC64())
/*5882*/      OPC_CheckComplexPat, /*CP*/5, /*#*/1, // SelectAddr:$buf #2
/*5885*/      OPC_EmitMergeInputChains1_0,
/*5886*/      OPC_MorphNodeTo, TARGET_VAL(PPC::EH_SjLj_LongJmp64), 0|OPFL_Chain,
                  0/*#VTs*/, 1/*#Ops*/, 2, 
              // Src: (PPCeh_sjlj_longjmp addr:iPTR:$buf) - Complexity = 9
              // Dst: (EH_SjLj_LongJmp64 addr:iPTR:$buf)
/*5893*/    0, /*End of Scope*/
/*5894*/  /*SwitchOpcode*/ 124,  TARGET_VAL(ISD::SUB),// ->6021
/*5897*/    OPC_Scope, 28, /*->5927*/ // 2 children in Scope
/*5899*/      OPC_MoveChild, 0,
/*5901*/      OPC_CheckInteger, 0, 
/*5903*/      OPC_MoveParent,
/*5904*/      OPC_RecordChild1, // #0 = $rA
/*5905*/      OPC_SwitchType /*2 cases */, 8,  MVT::i32,// ->5916
/*5908*/        OPC_MorphNodeTo, TARGET_VAL(PPC::NEG), 0,
                    1/*#VTs*/, MVT::i32, 1/*#Ops*/, 0, 
                // Src: (sub:i32 0:i32, i32:i32:$rA) - Complexity = 8
                // Dst: (NEG:i32 i32:i32:$rA)
/*5916*/      /*SwitchType*/ 8,  MVT::i64,// ->5926
/*5918*/        OPC_MorphNodeTo, TARGET_VAL(PPC::NEG8), 0,
                    1/*#VTs*/, MVT::i64, 1/*#Ops*/, 0, 
                // Src: (sub:i64 0:i64, i64:i64:$rA) - Complexity = 8
                // Dst: (NEG8:i64 i64:i64:$rA)
/*5926*/      0, // EndSwitchType
/*5927*/    /*Scope*/ 92, /*->6020*/
/*5928*/      OPC_RecordChild0, // #0 = $imm
/*5929*/      OPC_Scope, 23, /*->5954*/ // 2 children in Scope
/*5931*/        OPC_MoveChild, 0,
/*5933*/        OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*5936*/        OPC_CheckPredicate, 0, // Predicate_imm32SExt16
/*5938*/        OPC_MoveParent,
/*5939*/        OPC_RecordChild1, // #1 = $in
/*5940*/        OPC_CheckType, MVT::i32,
/*5942*/        OPC_EmitConvertToTarget, 0,
/*5944*/        OPC_MorphNodeTo, TARGET_VAL(PPC::SUBFIC), 0,
                    2/*#VTs*/, MVT::i32, MVT::i32, 2/*#Ops*/, 1, 2, 
                // Src: (sub:i32 (imm:i32)<<P:Predicate_imm32SExt16>>:$imm, i32:i32:$in) - Complexity = 7
                // Dst: (SUBFIC:i32:i32 ?:i32:$in, (imm:i32):$imm)
/*5954*/      /*Scope*/ 64, /*->6019*/
/*5955*/        OPC_RecordChild1, // #1 = $rA
/*5956*/        OPC_SwitchType /*5 cases */, 9,  MVT::i32,// ->5968
/*5959*/          OPC_MorphNodeTo, TARGET_VAL(PPC::SUBF), 0,
                      1/*#VTs*/, MVT::i32, 2/*#Ops*/, 1, 0, 
                  // Src: (sub:i32 i32:i32:$rB, i32:i32:$rA) - Complexity = 3
                  // Dst: (SUBF:i32 i32:i32:$rA, i32:i32:$rB)
/*5968*/        /*SwitchType*/ 9,  MVT::i64,// ->5979
/*5970*/          OPC_MorphNodeTo, TARGET_VAL(PPC::SUBF8), 0,
                      1/*#VTs*/, MVT::i64, 2/*#Ops*/, 1, 0, 
                  // Src: (sub:i64 i64:i64:$rB, i64:i64:$rA) - Complexity = 3
                  // Dst: (SUBF8:i64 i64:i64:$rA, i64:i64:$rB)
/*5979*/        /*SwitchType*/ 11,  MVT::v16i8,// ->5992
/*5981*/          OPC_CheckPatternPredicate, 0, // (PPCSubTarget.hasAltivec())
/*5983*/          OPC_MorphNodeTo, TARGET_VAL(PPC::VSUBUBM), 0,
                      1/*#VTs*/, MVT::v16i8, 2/*#Ops*/, 0, 1, 
                  // Src: (sub:v16i8 v16i8:v16i8:$vA, v16i8:v16i8:$vB) - Complexity = 3
                  // Dst: (VSUBUBM:v16i8 v16i8:v16i8:$vA, v16i8:v16i8:$vB)
/*5992*/        /*SwitchType*/ 11,  MVT::v8i16,// ->6005
/*5994*/          OPC_CheckPatternPredicate, 0, // (PPCSubTarget.hasAltivec())
/*5996*/          OPC_MorphNodeTo, TARGET_VAL(PPC::VSUBUHM), 0,
                      1/*#VTs*/, MVT::v8i16, 2/*#Ops*/, 0, 1, 
                  // Src: (sub:v8i16 v8i16:v8i16:$vA, v8i16:v8i16:$vB) - Complexity = 3
                  // Dst: (VSUBUHM:v8i16 v8i16:v8i16:$vA, v8i16:v8i16:$vB)
/*6005*/        /*SwitchType*/ 11,  MVT::v4i32,// ->6018
/*6007*/          OPC_CheckPatternPredicate, 0, // (PPCSubTarget.hasAltivec())
/*6009*/          OPC_MorphNodeTo, TARGET_VAL(PPC::VSUBUWM), 0,
                      1/*#VTs*/, MVT::v4i32, 2/*#Ops*/, 0, 1, 
                  // Src: (sub:v4i32 v4i32:v4i32:$vA, v4i32:v4i32:$vB) - Complexity = 3
                  // Dst: (VSUBUWM:v4i32 v4i32:v4i32:$vA, v4i32:v4i32:$vB)
/*6018*/        0, // EndSwitchType
/*6019*/      0, /*End of Scope*/
/*6020*/    0, /*End of Scope*/
/*6021*/  /*SwitchOpcode*/ 102,  TARGET_VAL(ISD::ADDE),// ->6126
/*6024*/    OPC_CaptureGlueInput,
/*6025*/    OPC_RecordChild0, // #0 = $rA
/*6026*/    OPC_Scope, 69, /*->6097*/ // 2 children in Scope
/*6028*/      OPC_MoveChild, 1,
/*6030*/      OPC_Scope, 36, /*->6068*/ // 2 children in Scope
/*6032*/        OPC_CheckInteger, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*6043*/        OPC_MoveParent,
/*6044*/        OPC_SwitchType /*2 cases */, 9,  MVT::i32,// ->6056
/*6047*/          OPC_MorphNodeTo, TARGET_VAL(PPC::ADDME), 0|OPFL_GlueInput|OPFL_GlueOutput,
                      2/*#VTs*/, MVT::i32, MVT::i32, 1/*#Ops*/, 0, 
                  // Src: (adde:i32 i32:i32:$rA, -1:i32) - Complexity = 8
                  // Dst: (ADDME:i32:i32 i32:i32:$rA)
/*6056*/        /*SwitchType*/ 9,  MVT::i64,// ->6067
/*6058*/          OPC_MorphNodeTo, TARGET_VAL(PPC::ADDME8), 0|OPFL_GlueInput|OPFL_GlueOutput,
                      2/*#VTs*/, MVT::i64, MVT::i32, 1/*#Ops*/, 0, 
                  // Src: (adde:i64 i64:i64:$rA, -1:i64) - Complexity = 8
                  // Dst: (ADDME8:i64:i32 i64:i64:$rA)
/*6067*/        0, // EndSwitchType
/*6068*/      /*Scope*/ 27, /*->6096*/
/*6069*/        OPC_CheckInteger, 0, 
/*6071*/        OPC_MoveParent,
/*6072*/        OPC_SwitchType /*2 cases */, 9,  MVT::i32,// ->6084
/*6075*/          OPC_MorphNodeTo, TARGET_VAL(PPC::ADDZE), 0|OPFL_GlueInput|OPFL_GlueOutput,
                      2/*#VTs*/, MVT::i32, MVT::i32, 1/*#Ops*/, 0, 
                  // Src: (adde:i32 i32:i32:$rA, 0:i32) - Complexity = 8
                  // Dst: (ADDZE:i32:i32 i32:i32:$rA)
/*6084*/        /*SwitchType*/ 9,  MVT::i64,// ->6095
/*6086*/          OPC_MorphNodeTo, TARGET_VAL(PPC::ADDZE8), 0|OPFL_GlueInput|OPFL_GlueOutput,
                      2/*#VTs*/, MVT::i64, MVT::i32, 1/*#Ops*/, 0, 
                  // Src: (adde:i64 i64:i64:$rA, 0:i64) - Complexity = 8
                  // Dst: (ADDZE8:i64:i32 i64:i64:$rA)
/*6095*/        0, // EndSwitchType
/*6096*/      0, /*End of Scope*/
/*6097*/    /*Scope*/ 27, /*->6125*/
/*6098*/      OPC_RecordChild1, // #1 = $rB
/*6099*/      OPC_SwitchType /*2 cases */, 10,  MVT::i32,// ->6112
/*6102*/        OPC_MorphNodeTo, TARGET_VAL(PPC::ADDE), 0|OPFL_GlueInput|OPFL_GlueOutput,
                    2/*#VTs*/, MVT::i32, MVT::i32, 2/*#Ops*/, 0, 1, 
                // Src: (adde:i32 i32:i32:$rA, i32:i32:$rB) - Complexity = 3
                // Dst: (ADDE:i32:i32 i32:i32:$rA, i32:i32:$rB)
/*6112*/      /*SwitchType*/ 10,  MVT::i64,// ->6124
/*6114*/        OPC_MorphNodeTo, TARGET_VAL(PPC::ADDE8), 0|OPFL_GlueInput|OPFL_GlueOutput,
                    2/*#VTs*/, MVT::i64, MVT::i32, 2/*#Ops*/, 0, 1, 
                // Src: (adde:i64 i64:i64:$rA, i64:i64:$rB) - Complexity = 3
                // Dst: (ADDE8:i64:i32 i64:i64:$rA, i64:i64:$rB)
/*6124*/      0, // EndSwitchType
/*6125*/    0, /*End of Scope*/
/*6126*/  /*SwitchOpcode*/ 104,  TARGET_VAL(ISD::SUBE),// ->6233
/*6129*/    OPC_CaptureGlueInput,
/*6130*/    OPC_Scope, 71, /*->6203*/ // 2 children in Scope
/*6132*/      OPC_MoveChild, 0,
/*6134*/      OPC_Scope, 37, /*->6173*/ // 2 children in Scope
/*6136*/        OPC_CheckInteger, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*6147*/        OPC_MoveParent,
/*6148*/        OPC_RecordChild1, // #0 = $rA
/*6149*/        OPC_SwitchType /*2 cases */, 9,  MVT::i32,// ->6161
/*6152*/          OPC_MorphNodeTo, TARGET_VAL(PPC::SUBFME), 0|OPFL_GlueInput|OPFL_GlueOutput,
                      2/*#VTs*/, MVT::i32, MVT::i32, 1/*#Ops*/, 0, 
                  // Src: (sube:i32 -1:i32, i32:i32:$rA) - Complexity = 8
                  // Dst: (SUBFME:i32:i32 i32:i32:$rA)
/*6161*/        /*SwitchType*/ 9,  MVT::i64,// ->6172
/*6163*/          OPC_MorphNodeTo, TARGET_VAL(PPC::SUBFME8), 0|OPFL_GlueInput|OPFL_GlueOutput,
                      2/*#VTs*/, MVT::i64, MVT::i32, 1/*#Ops*/, 0, 
                  // Src: (sube:i64 -1:i64, i64:i64:$rA) - Complexity = 8
                  // Dst: (SUBFME8:i64:i32 i64:i64:$rA)
/*6172*/        0, // EndSwitchType
/*6173*/      /*Scope*/ 28, /*->6202*/
/*6174*/        OPC_CheckInteger, 0, 
/*6176*/        OPC_MoveParent,
/*6177*/        OPC_RecordChild1, // #0 = $rA
/*6178*/        OPC_SwitchType /*2 cases */, 9,  MVT::i32,// ->6190
/*6181*/          OPC_MorphNodeTo, TARGET_VAL(PPC::SUBFZE), 0|OPFL_GlueInput|OPFL_GlueOutput,
                      2/*#VTs*/, MVT::i32, MVT::i32, 1/*#Ops*/, 0, 
                  // Src: (sube:i32 0:i32, i32:i32:$rA) - Complexity = 8
                  // Dst: (SUBFZE:i32:i32 i32:i32:$rA)
/*6190*/        /*SwitchType*/ 9,  MVT::i64,// ->6201
/*6192*/          OPC_MorphNodeTo, TARGET_VAL(PPC::SUBFZE8), 0|OPFL_GlueInput|OPFL_GlueOutput,
                      2/*#VTs*/, MVT::i64, MVT::i32, 1/*#Ops*/, 0, 
                  // Src: (sube:i64 0:i64, i64:i64:$rA) - Complexity = 8
                  // Dst: (SUBFZE8:i64:i32 i64:i64:$rA)
/*6201*/        0, // EndSwitchType
/*6202*/      0, /*End of Scope*/
/*6203*/    /*Scope*/ 28, /*->6232*/
/*6204*/      OPC_RecordChild0, // #0 = $rB
/*6205*/      OPC_RecordChild1, // #1 = $rA
/*6206*/      OPC_SwitchType /*2 cases */, 10,  MVT::i32,// ->6219
/*6209*/        OPC_MorphNodeTo, TARGET_VAL(PPC::SUBFE), 0|OPFL_GlueInput|OPFL_GlueOutput,
                    2/*#VTs*/, MVT::i32, MVT::i32, 2/*#Ops*/, 1, 0, 
                // Src: (sube:i32 i32:i32:$rB, i32:i32:$rA) - Complexity = 3
                // Dst: (SUBFE:i32:i32 i32:i32:$rA, i32:i32:$rB)
/*6219*/      /*SwitchType*/ 10,  MVT::i64,// ->6231
/*6221*/        OPC_MorphNodeTo, TARGET_VAL(PPC::SUBFE8), 0|OPFL_GlueInput|OPFL_GlueOutput,
                    2/*#VTs*/, MVT::i64, MVT::i32, 2/*#Ops*/, 1, 0, 
                // Src: (sube:i64 i64:i64:$rB, i64:i64:$rA) - Complexity = 3
                // Dst: (SUBFE8:i64:i32 i64:i64:$rA, i64:i64:$rB)
/*6231*/      0, // EndSwitchType
/*6232*/    0, /*End of Scope*/
/*6233*/  /*SwitchOpcode*/ 74,  TARGET_VAL(ISD::ADDC),// ->6310
/*6236*/    OPC_RecordChild0, // #0 = $rA
/*6237*/    OPC_RecordChild1, // #1 = $imm
/*6238*/    OPC_Scope, 43, /*->6283*/ // 3 children in Scope
/*6240*/      OPC_MoveChild, 1,
/*6242*/      OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*6245*/      OPC_Scope, 17, /*->6264*/ // 2 children in Scope
/*6247*/        OPC_CheckPredicate, 0, // Predicate_imm32SExt16
/*6249*/        OPC_MoveParent,
/*6250*/        OPC_CheckType, MVT::i32,
/*6252*/        OPC_EmitConvertToTarget, 1,
/*6254*/        OPC_MorphNodeTo, TARGET_VAL(PPC::ADDIC), 0|OPFL_GlueOutput,
                    2/*#VTs*/, MVT::i32, MVT::i32, 2/*#Ops*/, 0, 2, 
                // Src: (addc:i32 i32:i32:$rA, (imm:i32)<<P:Predicate_imm32SExt16>>:$imm) - Complexity = 7
                // Dst: (ADDIC:i32:i32 i32:i32:$rA, (imm:i32):$imm)
/*6264*/      /*Scope*/ 17, /*->6282*/
/*6265*/        OPC_CheckPredicate, 2, // Predicate_imm64SExt16
/*6267*/        OPC_MoveParent,
/*6268*/        OPC_CheckType, MVT::i64,
/*6270*/        OPC_EmitConvertToTarget, 1,
/*6272*/        OPC_MorphNodeTo, TARGET_VAL(PPC::ADDIC8), 0|OPFL_GlueOutput,
                    2/*#VTs*/, MVT::i64, MVT::i32, 2/*#Ops*/, 0, 2, 
                // Src: (addc:i64 i64:i64:$rA, (imm:i64)<<P:Predicate_imm64SExt16>>:$imm) - Complexity = 7
                // Dst: (ADDIC8:i64:i32 i64:i64:$rA, (imm:i64):$imm)
/*6282*/      0, /*End of Scope*/
/*6283*/    /*Scope*/ 12, /*->6296*/
/*6284*/      OPC_CheckType, MVT::i32,
/*6286*/      OPC_MorphNodeTo, TARGET_VAL(PPC::ADDC), 0|OPFL_GlueOutput,
                  2/*#VTs*/, MVT::i32, MVT::i32, 2/*#Ops*/, 0, 1, 
              // Src: (addc:i32 i32:i32:$rA, i32:i32:$rB) - Complexity = 3
              // Dst: (ADDC:i32:i32 i32:i32:$rA, i32:i32:$rB)
/*6296*/    /*Scope*/ 12, /*->6309*/
/*6297*/      OPC_CheckType, MVT::i64,
/*6299*/      OPC_MorphNodeTo, TARGET_VAL(PPC::ADDC8), 0|OPFL_GlueOutput,
                  2/*#VTs*/, MVT::i64, MVT::i32, 2/*#Ops*/, 0, 1, 
              // Src: (addc:i64 i64:i64:$rA, i64:i64:$rB) - Complexity = 3
              // Dst: (ADDC8:i64:i32 i64:i64:$rA, i64:i64:$rB)
/*6309*/    0, /*End of Scope*/
/*6310*/  /*SwitchOpcode*/ 70,  TARGET_VAL(ISD::MUL),// ->6383
/*6313*/    OPC_RecordChild0, // #0 = $rA
/*6314*/    OPC_RecordChild1, // #1 = $imm
/*6315*/    OPC_Scope, 41, /*->6358*/ // 3 children in Scope
/*6317*/      OPC_MoveChild, 1,
/*6319*/      OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*6322*/      OPC_Scope, 16, /*->6340*/ // 2 children in Scope
/*6324*/        OPC_CheckPredicate, 0, // Predicate_imm32SExt16
/*6326*/        OPC_MoveParent,
/*6327*/        OPC_CheckType, MVT::i32,
/*6329*/        OPC_EmitConvertToTarget, 1,
/*6331*/        OPC_MorphNodeTo, TARGET_VAL(PPC::MULLI), 0,
                    1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 2, 
                // Src: (mul:i32 i32:i32:$rA, (imm:i32)<<P:Predicate_imm32SExt16>>:$imm) - Complexity = 7
                // Dst: (MULLI:i32 i32:i32:$rA, (imm:i32):$imm)
/*6340*/      /*Scope*/ 16, /*->6357*/
/*6341*/        OPC_CheckPredicate, 2, // Predicate_imm64SExt16
/*6343*/        OPC_MoveParent,
/*6344*/        OPC_CheckType, MVT::i64,
/*6346*/        OPC_EmitConvertToTarget, 1,
/*6348*/        OPC_MorphNodeTo, TARGET_VAL(PPC::MULLI8), 0,
                    1/*#VTs*/, MVT::i64, 2/*#Ops*/, 0, 2, 
                // Src: (mul:i64 i64:i64:$rA, (imm:i64)<<P:Predicate_imm64SExt16>>:$imm) - Complexity = 7
                // Dst: (MULLI8:i64 i64:i64:$rA, (imm:i64):$imm)
/*6357*/      0, /*End of Scope*/
/*6358*/    /*Scope*/ 11, /*->6370*/
/*6359*/      OPC_CheckType, MVT::i32,
/*6361*/      OPC_MorphNodeTo, TARGET_VAL(PPC::MULLW), 0,
                  1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1, 
              // Src: (mul:i32 i32:i32:$rA, i32:i32:$rB) - Complexity = 3
              // Dst: (MULLW:i32 i32:i32:$rA, i32:i32:$rB)
/*6370*/    /*Scope*/ 11, /*->6382*/
/*6371*/      OPC_CheckType, MVT::i64,
/*6373*/      OPC_MorphNodeTo, TARGET_VAL(PPC::MULLD), 0,
                  1/*#VTs*/, MVT::i64, 2/*#Ops*/, 0, 1, 
              // Src: (mul:i64 i64:i64:$rA, i64:i64:$rB) - Complexity = 3
              // Dst: (MULLD:i64 i64:i64:$rA, i64:i64:$rB)
/*6382*/    0, /*End of Scope*/
/*6383*/  /*SwitchOpcode*/ 77,  TARGET_VAL(ISD::SUBC),// ->6463
/*6386*/    OPC_RecordChild0, // #0 = $imm
/*6387*/    OPC_Scope, 45, /*->6434*/ // 2 children in Scope
/*6389*/      OPC_MoveChild, 0,
/*6391*/      OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*6394*/      OPC_Scope, 18, /*->6414*/ // 2 children in Scope
/*6396*/        OPC_CheckPredicate, 0, // Predicate_imm32SExt16
/*6398*/        OPC_MoveParent,
/*6399*/        OPC_RecordChild1, // #1 = $rA
/*6400*/        OPC_CheckType, MVT::i32,
/*6402*/        OPC_EmitConvertToTarget, 0,
/*6404*/        OPC_MorphNodeTo, TARGET_VAL(PPC::SUBFIC), 0|OPFL_GlueOutput,
                    2/*#VTs*/, MVT::i32, MVT::i32, 2/*#Ops*/, 1, 2, 
                // Src: (subc:i32 (imm:i32)<<P:Predicate_imm32SExt16>>:$imm, i32:i32:$rA) - Complexity = 7
                // Dst: (SUBFIC:i32:i32 i32:i32:$rA, (imm:i32):$imm)
/*6414*/      /*Scope*/ 18, /*->6433*/
/*6415*/        OPC_CheckPredicate, 2, // Predicate_imm64SExt16
/*6417*/        OPC_MoveParent,
/*6418*/        OPC_RecordChild1, // #1 = $rA
/*6419*/        OPC_CheckType, MVT::i64,
/*6421*/        OPC_EmitConvertToTarget, 0,
/*6423*/        OPC_MorphNodeTo, TARGET_VAL(PPC::SUBFIC8), 0|OPFL_GlueOutput,
                    2/*#VTs*/, MVT::i64, MVT::i32, 2/*#Ops*/, 1, 2, 
                // Src: (subc:i64 (imm:i64)<<P:Predicate_imm64SExt16>>:$imm, i64:i64:$rA) - Complexity = 7
                // Dst: (SUBFIC8:i64:i32 i64:i64:$rA, (imm:i64):$imm)
/*6433*/      0, /*End of Scope*/
/*6434*/    /*Scope*/ 27, /*->6462*/
/*6435*/      OPC_RecordChild1, // #1 = $rA
/*6436*/      OPC_SwitchType /*2 cases */, 10,  MVT::i32,// ->6449
/*6439*/        OPC_MorphNodeTo, TARGET_VAL(PPC::SUBFC), 0|OPFL_GlueOutput,
                    2/*#VTs*/, MVT::i32, MVT::i32, 2/*#Ops*/, 1, 0, 
                // Src: (subc:i32 i32:i32:$rB, i32:i32:$rA) - Complexity = 3
                // Dst: (SUBFC:i32:i32 i32:i32:$rA, i32:i32:$rB)
/*6449*/      /*SwitchType*/ 10,  MVT::i64,// ->6461
/*6451*/        OPC_MorphNodeTo, TARGET_VAL(PPC::SUBFC8), 0|OPFL_GlueOutput,
                    2/*#VTs*/, MVT::i64, MVT::i32, 2/*#Ops*/, 1, 0, 
                // Src: (subc:i64 i64:i64:$rB, i64:i64:$rA) - Complexity = 3
                // Dst: (SUBFC8:i64:i32 i64:i64:$rA, i64:i64:$rB)
/*6461*/      0, // EndSwitchType
/*6462*/    0, /*End of Scope*/
/*6463*/  /*SwitchOpcode*/ 17,  TARGET_VAL(ISD::CALLSEQ_START),// ->6483
/*6466*/    OPC_RecordNode,   // #0 = 'callseq_start' chained node
/*6467*/    OPC_RecordChild1, // #1 = $amt
/*6468*/    OPC_MoveChild, 1,
/*6470*/    OPC_CheckOpcode, TARGET_VAL(ISD::TargetConstant),
/*6473*/    OPC_MoveParent,
/*6474*/    OPC_EmitMergeInputChains1_0,
/*6475*/    OPC_MorphNodeTo, TARGET_VAL(PPC::ADJCALLSTACKDOWN), 0|OPFL_Chain|OPFL_GlueOutput,
                1/*#VTs*/, MVT::i32, 1/*#Ops*/, 1, 
            // Src: (callseq_start (timm:i32):$amt) - Complexity = 6
            // Dst: (ADJCALLSTACKDOWN:i32 (timm:i32):$amt)
/*6483*/  /*SwitchOpcode*/ 92,  TARGET_VAL(PPCISD::CALL),// ->6578
/*6486*/    OPC_RecordNode,   // #0 = 'PPCcall' chained node
/*6487*/    OPC_CaptureGlueInput,
/*6488*/    OPC_RecordChild1, // #1 = $func
/*6489*/    OPC_MoveChild, 1,
/*6491*/    OPC_SwitchOpcode /*3 cases */, 28,  TARGET_VAL(ISD::Constant),// ->6523
/*6495*/      OPC_SwitchType /*2 cases */, 11,  MVT::i32,// ->6509
/*6498*/        OPC_MoveParent,
/*6499*/        OPC_EmitMergeInputChains1_0,
/*6500*/        OPC_EmitConvertToTarget, 1,
/*6502*/        OPC_MorphNodeTo, TARGET_VAL(PPC::BLA), 0|OPFL_Chain|OPFL_GlueInput|OPFL_GlueOutput|OPFL_Variadic1,
                    0/*#VTs*/, 1/*#Ops*/, 2, 
                // Src: (PPCcall (imm:i32):$func) - Complexity = 6
                // Dst: (BLA (imm:i32):$func)
/*6509*/      /*SwitchType*/ 11,  MVT::i64,// ->6522
/*6511*/        OPC_MoveParent,
/*6512*/        OPC_EmitMergeInputChains1_0,
/*6513*/        OPC_EmitConvertToTarget, 1,
/*6515*/        OPC_MorphNodeTo, TARGET_VAL(PPC::BLA8), 0|OPFL_Chain|OPFL_GlueInput|OPFL_GlueOutput|OPFL_Variadic1,
                    0/*#VTs*/, 1/*#Ops*/, 2, 
                // Src: (PPCcall (imm:i64):$func) - Complexity = 6
                // Dst: (BLA8 (imm:i64):$func)
/*6522*/      0, // EndSwitchType
/*6523*/    /*SwitchOpcode*/ 24,  TARGET_VAL(ISD::TargetGlobalAddress),// ->6550
/*6526*/      OPC_SwitchType /*2 cases */, 9,  MVT::i32,// ->6538
/*6529*/        OPC_MoveParent,
/*6530*/        OPC_EmitMergeInputChains1_0,
/*6531*/        OPC_MorphNodeTo, TARGET_VAL(PPC::BL), 0|OPFL_Chain|OPFL_GlueInput|OPFL_GlueOutput|OPFL_Variadic1,
                    0/*#VTs*/, 1/*#Ops*/, 1, 
                // Src: (PPCcall (tglobaladdr:i32):$dst) - Complexity = 6
                // Dst: (BL (tglobaladdr:i32):$dst)
/*6538*/      /*SwitchType*/ 9,  MVT::i64,// ->6549
/*6540*/        OPC_MoveParent,
/*6541*/        OPC_EmitMergeInputChains1_0,
/*6542*/        OPC_MorphNodeTo, TARGET_VAL(PPC::BL8), 0|OPFL_Chain|OPFL_GlueInput|OPFL_GlueOutput|OPFL_Variadic1,
                    0/*#VTs*/, 1/*#Ops*/, 1, 
                // Src: (PPCcall (tglobaladdr:i64):$dst) - Complexity = 6
                // Dst: (BL8 (tglobaladdr:i64):$dst)
/*6549*/      0, // EndSwitchType
/*6550*/    /*SwitchOpcode*/ 24,  TARGET_VAL(ISD::TargetExternalSymbol),// ->6577
/*6553*/      OPC_SwitchType /*2 cases */, 9,  MVT::i32,// ->6565
/*6556*/        OPC_MoveParent,
/*6557*/        OPC_EmitMergeInputChains1_0,
/*6558*/        OPC_MorphNodeTo, TARGET_VAL(PPC::BL), 0|OPFL_Chain|OPFL_GlueInput|OPFL_GlueOutput|OPFL_Variadic1,
                    0/*#VTs*/, 1/*#Ops*/, 1, 
                // Src: (PPCcall (texternalsym:i32):$dst) - Complexity = 6
                // Dst: (BL (texternalsym:i32):$dst)
/*6565*/      /*SwitchType*/ 9,  MVT::i64,// ->6576
/*6567*/        OPC_MoveParent,
/*6568*/        OPC_EmitMergeInputChains1_0,
/*6569*/        OPC_MorphNodeTo, TARGET_VAL(PPC::BL8), 0|OPFL_Chain|OPFL_GlueInput|OPFL_GlueOutput|OPFL_Variadic1,
                    0/*#VTs*/, 1/*#Ops*/, 1, 
                // Src: (PPCcall (texternalsym:i64):$dst) - Complexity = 6
                // Dst: (BL8 (texternalsym:i64):$dst)
/*6576*/      0, // EndSwitchType
/*6577*/    0, // EndSwitchOpcode
/*6578*/  /*SwitchOpcode*/ 20,  TARGET_VAL(PPCISD::SC),// ->6601
/*6581*/    OPC_RecordNode,   // #0 = 'PPCsc' chained node
/*6582*/    OPC_RecordChild1, // #1 = $lev
/*6583*/    OPC_MoveChild, 1,
/*6585*/    OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*6588*/    OPC_CheckType, MVT::i32,
/*6590*/    OPC_MoveParent,
/*6591*/    OPC_EmitMergeInputChains1_0,
/*6592*/    OPC_EmitConvertToTarget, 1,
/*6594*/    OPC_MorphNodeTo, TARGET_VAL(PPC::SC), 0|OPFL_Chain,
                0/*#VTs*/, 1/*#Ops*/, 2, 
            // Src: (PPCsc (imm:i32):$lev) - Complexity = 6
            // Dst: (SC (imm:i32):$lev)
/*6601*/  /*SwitchOpcode*/ 120,  TARGET_VAL(ISD::SRA),// ->6724
/*6604*/    OPC_RecordChild0, // #0 = $rS
/*6605*/    OPC_RecordChild1, // #1 = $SH
/*6606*/    OPC_Scope, 38, /*->6646*/ // 5 children in Scope
/*6608*/      OPC_MoveChild, 1,
/*6610*/      OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*6613*/      OPC_CheckType, MVT::i32,
/*6615*/      OPC_MoveParent,
/*6616*/      OPC_SwitchType /*2 cases */, 12,  MVT::i32,// ->6631
/*6619*/        OPC_EmitConvertToTarget, 1,
/*6621*/        OPC_MorphNodeTo, TARGET_VAL(PPC::SRAWI), 0,
                    2/*#VTs*/, MVT::i32, MVT::i32, 2/*#Ops*/, 0, 2, 
                // Src: (sra:i32 i32:i32:$rS, (imm:i32):$SH) - Complexity = 6
                // Dst: (SRAWI:i32:i32 i32:i32:$rS, (imm:i32):$SH)
/*6631*/      /*SwitchType*/ 12,  MVT::i64,// ->6645
/*6633*/        OPC_EmitConvertToTarget, 1,
/*6635*/        OPC_MorphNodeTo, TARGET_VAL(PPC::SRADI), 0,
                    2/*#VTs*/, MVT::i64, MVT::i32, 2/*#Ops*/, 0, 2, 
                // Src: (sra:i64 i64:i64:$rS, (imm:i32):$SH) - Complexity = 6
                // Dst: (SRADI:i64:i32 i64:i64:$rS, (imm:i32):$SH)
/*6645*/      0, // EndSwitchType
/*6646*/    /*Scope*/ 28, /*->6675*/
/*6647*/      OPC_CheckChild1Type, MVT::i32,
/*6649*/      OPC_SwitchType /*2 cases */, 10,  MVT::i32,// ->6662
/*6652*/        OPC_MorphNodeTo, TARGET_VAL(PPC::SRAW), 0,
                    2/*#VTs*/, MVT::i32, MVT::i32, 2/*#Ops*/, 0, 1, 
                // Src: (sra:i32 i32:i32:$rS, i32:i32:$rB) - Complexity = 3
                // Dst: (SRAW:i32:i32 ?:i32:$rS, ?:i32:$rB)
/*6662*/      /*SwitchType*/ 10,  MVT::i64,// ->6674
/*6664*/        OPC_MorphNodeTo, TARGET_VAL(PPC::SRAD), 0,
                    2/*#VTs*/, MVT::i64, MVT::i32, 2/*#Ops*/, 0, 1, 
                // Src: (sra:i64 i64:i64:$rS, i32:i32:$rB) - Complexity = 3
                // Dst: (SRAD:i64:i32 ?:i64:$rS, ?:i32:$rB)
/*6674*/      0, // EndSwitchType
/*6675*/    /*Scope*/ 15, /*->6691*/
/*6676*/      OPC_CheckChild1Type, MVT::v16i8,
/*6678*/      OPC_CheckType, MVT::v16i8,
/*6680*/      OPC_CheckPatternPredicate, 0, // (PPCSubTarget.hasAltivec())
/*6682*/      OPC_MorphNodeTo, TARGET_VAL(PPC::VSRAB), 0,
                  1/*#VTs*/, MVT::v16i8, 2/*#Ops*/, 0, 1, 
              // Src: (sra:v16i8 v16i8:v16i8:$vA, v16i8:v16i8:$vB) - Complexity = 3
              // Dst: (VSRAB:v16i8 ?:v16i8:$vA, ?:v16i8:$vB)
/*6691*/    /*Scope*/ 15, /*->6707*/
/*6692*/      OPC_CheckChild1Type, MVT::v8i16,
/*6694*/      OPC_CheckType, MVT::v8i16,
/*6696*/      OPC_CheckPatternPredicate, 0, // (PPCSubTarget.hasAltivec())
/*6698*/      OPC_MorphNodeTo, TARGET_VAL(PPC::VSRAH), 0,
                  1/*#VTs*/, MVT::v8i16, 2/*#Ops*/, 0, 1, 
              // Src: (sra:v8i16 v8i16:v8i16:$vA, v8i16:v8i16:$vB) - Complexity = 3
              // Dst: (VSRAH:v8i16 ?:v8i16:$vA, ?:v8i16:$vB)
/*6707*/    /*Scope*/ 15, /*->6723*/
/*6708*/      OPC_CheckChild1Type, MVT::v4i32,
/*6710*/      OPC_CheckType, MVT::v4i32,
/*6712*/      OPC_CheckPatternPredicate, 0, // (PPCSubTarget.hasAltivec())
/*6714*/      OPC_MorphNodeTo, TARGET_VAL(PPC::VSRAW), 0,
                  1/*#VTs*/, MVT::v4i32, 2/*#Ops*/, 0, 1, 
              // Src: (sra:v4i32 v4i32:v4i32:$vA, v4i32:v4i32:$vB) - Complexity = 3
              // Dst: (VSRAW:v4i32 ?:v4i32:$vA, ?:v4i32:$vB)
/*6723*/    0, /*End of Scope*/
/*6724*/  /*SwitchOpcode*/ 4|128,1/*132*/,  TARGET_VAL(ISD::SHL),// ->6860
/*6728*/    OPC_RecordChild0, // #0 = $in
/*6729*/    OPC_RecordChild1, // #1 = $imm
/*6730*/    OPC_Scope, 52, /*->6784*/ // 5 children in Scope
/*6732*/      OPC_MoveChild, 1,
/*6734*/      OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*6737*/      OPC_CheckType, MVT::i32,
/*6739*/      OPC_MoveParent,
/*6740*/      OPC_SwitchType /*2 cases */, 21,  MVT::i32,// ->6764
/*6743*/        OPC_EmitConvertToTarget, 1,
/*6745*/        OPC_EmitInteger, MVT::i32, 0, 
/*6748*/        OPC_EmitConvertToTarget, 1,
/*6750*/        OPC_EmitNodeXForm, 5, 4, // SHL32
/*6753*/        OPC_MorphNodeTo, TARGET_VAL(PPC::RLWINM), 0,
                    1/*#VTs*/, MVT::i32, 4/*#Ops*/, 0, 2, 3, 5, 
                // Src: (shl:i32 i32:i32:$in, (imm:i32):$imm) - Complexity = 6
                // Dst: (RLWINM:i32 ?:i32:$in, (imm:i32):$imm, 0:i32, (SHL32:i32 (imm:i32):$imm))
/*6764*/      /*SwitchType*/ 17,  MVT::i64,// ->6783
/*6766*/        OPC_EmitConvertToTarget, 1,
/*6768*/        OPC_EmitConvertToTarget, 1,
/*6770*/        OPC_EmitNodeXForm, 6, 3, // SHL64
/*6773*/        OPC_MorphNodeTo, TARGET_VAL(PPC::RLDICR), 0,
                    1/*#VTs*/, MVT::i64, 3/*#Ops*/, 0, 2, 4, 
                // Src: (shl:i64 i64:i64:$in, (imm:i32):$imm) - Complexity = 6
                // Dst: (RLDICR:i64 ?:i64:$in, (imm:i32):$imm, (SHL64:i32 (imm:i32):$imm))
/*6783*/      0, // EndSwitchType
/*6784*/    /*Scope*/ 26, /*->6811*/
/*6785*/      OPC_CheckChild1Type, MVT::i32,
/*6787*/      OPC_SwitchType /*2 cases */, 9,  MVT::i32,// ->6799
/*6790*/        OPC_MorphNodeTo, TARGET_VAL(PPC::SLW), 0,
                    1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1, 
                // Src: (shl:i32 i32:i32:$rS, i32:i32:$rB) - Complexity = 3
                // Dst: (SLW:i32 ?:i32:$rS, ?:i32:$rB)
/*6799*/      /*SwitchType*/ 9,  MVT::i64,// ->6810
/*6801*/        OPC_MorphNodeTo, TARGET_VAL(PPC::SLD), 0,
                    1/*#VTs*/, MVT::i64, 2/*#Ops*/, 0, 1, 
                // Src: (shl:i64 i64:i64:$rS, i32:i32:$rB) - Complexity = 3
                // Dst: (SLD:i64 ?:i64:$rS, ?:i32:$rB)
/*6810*/      0, // EndSwitchType
/*6811*/    /*Scope*/ 15, /*->6827*/
/*6812*/      OPC_CheckChild1Type, MVT::v16i8,
/*6814*/      OPC_CheckType, MVT::v16i8,
/*6816*/      OPC_CheckPatternPredicate, 0, // (PPCSubTarget.hasAltivec())
/*6818*/      OPC_MorphNodeTo, TARGET_VAL(PPC::VSLB), 0,
                  1/*#VTs*/, MVT::v16i8, 2/*#Ops*/, 0, 1, 
              // Src: (shl:v16i8 v16i8:v16i8:$vA, v16i8:v16i8:$vB) - Complexity = 3
              // Dst: (VSLB:v16i8 ?:v16i8:$vA, ?:v16i8:$vB)
/*6827*/    /*Scope*/ 15, /*->6843*/
/*6828*/      OPC_CheckChild1Type, MVT::v8i16,
/*6830*/      OPC_CheckType, MVT::v8i16,
/*6832*/      OPC_CheckPatternPredicate, 0, // (PPCSubTarget.hasAltivec())
/*6834*/      OPC_MorphNodeTo, TARGET_VAL(PPC::VSLH), 0,
                  1/*#VTs*/, MVT::v8i16, 2/*#Ops*/, 0, 1, 
              // Src: (shl:v8i16 v8i16:v8i16:$vA, v8i16:v8i16:$vB) - Complexity = 3
              // Dst: (VSLH:v8i16 ?:v8i16:$vA, ?:v8i16:$vB)
/*6843*/    /*Scope*/ 15, /*->6859*/
/*6844*/      OPC_CheckChild1Type, MVT::v4i32,
/*6846*/      OPC_CheckType, MVT::v4i32,
/*6848*/      OPC_CheckPatternPredicate, 0, // (PPCSubTarget.hasAltivec())
/*6850*/      OPC_MorphNodeTo, TARGET_VAL(PPC::VSLW), 0,
                  1/*#VTs*/, MVT::v4i32, 2/*#Ops*/, 0, 1, 
              // Src: (shl:v4i32 v4i32:v4i32:$vA, v4i32:v4i32:$vB) - Complexity = 3
              // Dst: (VSLW:v4i32 ?:v4i32:$vA, ?:v4i32:$vB)
/*6859*/    0, /*End of Scope*/
/*6860*/  /*SwitchOpcode*/ 4|128,1/*132*/,  TARGET_VAL(ISD::SRL),// ->6996
/*6864*/    OPC_RecordChild0, // #0 = $in
/*6865*/    OPC_RecordChild1, // #1 = $imm
/*6866*/    OPC_Scope, 52, /*->6920*/ // 5 children in Scope
/*6868*/      OPC_MoveChild, 1,
/*6870*/      OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*6873*/      OPC_CheckType, MVT::i32,
/*6875*/      OPC_MoveParent,
/*6876*/      OPC_SwitchType /*2 cases */, 21,  MVT::i32,// ->6900
/*6879*/        OPC_EmitConvertToTarget, 1,
/*6881*/        OPC_EmitNodeXForm, 7, 2, // SRL32
/*6884*/        OPC_EmitConvertToTarget, 1,
/*6886*/        OPC_EmitInteger, MVT::i32, 31, 
/*6889*/        OPC_MorphNodeTo, TARGET_VAL(PPC::RLWINM), 0,
                    1/*#VTs*/, MVT::i32, 4/*#Ops*/, 0, 3, 4, 5, 
                // Src: (srl:i32 i32:i32:$in, (imm:i32):$imm) - Complexity = 6
                // Dst: (RLWINM:i32 ?:i32:$in, (SRL32:i32 (imm:i32):$imm), (imm:i32):$imm, 31:i32)
/*6900*/      /*SwitchType*/ 17,  MVT::i64,// ->6919
/*6902*/        OPC_EmitConvertToTarget, 1,
/*6904*/        OPC_EmitNodeXForm, 8, 2, // SRL64
/*6907*/        OPC_EmitConvertToTarget, 1,
/*6909*/        OPC_MorphNodeTo, TARGET_VAL(PPC::RLDICL), 0,
                    1/*#VTs*/, MVT::i64, 3/*#Ops*/, 0, 3, 4, 
                // Src: (srl:i64 i64:i64:$in, (imm:i32):$imm) - Complexity = 6
                // Dst: (RLDICL:i64 ?:i64:$in, (SRL64:i32 (imm:i32):$imm), (imm:i32):$imm)
/*6919*/      0, // EndSwitchType
/*6920*/    /*Scope*/ 26, /*->6947*/
/*6921*/      OPC_CheckChild1Type, MVT::i32,
/*6923*/      OPC_SwitchType /*2 cases */, 9,  MVT::i32,// ->6935
/*6926*/        OPC_MorphNodeTo, TARGET_VAL(PPC::SRW), 0,
                    1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1, 
                // Src: (srl:i32 i32:i32:$rS, i32:i32:$rB) - Complexity = 3
                // Dst: (SRW:i32 ?:i32:$rS, ?:i32:$rB)
/*6935*/      /*SwitchType*/ 9,  MVT::i64,// ->6946
/*6937*/        OPC_MorphNodeTo, TARGET_VAL(PPC::SRD), 0,
                    1/*#VTs*/, MVT::i64, 2/*#Ops*/, 0, 1, 
                // Src: (srl:i64 i64:i64:$rS, i32:i32:$rB) - Complexity = 3
                // Dst: (SRD:i64 ?:i64:$rS, ?:i32:$rB)
/*6946*/      0, // EndSwitchType
/*6947*/    /*Scope*/ 15, /*->6963*/
/*6948*/      OPC_CheckChild1Type, MVT::v16i8,
/*6950*/      OPC_CheckType, MVT::v16i8,
/*6952*/      OPC_CheckPatternPredicate, 0, // (PPCSubTarget.hasAltivec())
/*6954*/      OPC_MorphNodeTo, TARGET_VAL(PPC::VSRB), 0,
                  1/*#VTs*/, MVT::v16i8, 2/*#Ops*/, 0, 1, 
              // Src: (srl:v16i8 v16i8:v16i8:$vA, v16i8:v16i8:$vB) - Complexity = 3
              // Dst: (VSRB:v16i8 ?:v16i8:$vA, ?:v16i8:$vB)
/*6963*/    /*Scope*/ 15, /*->6979*/
/*6964*/      OPC_CheckChild1Type, MVT::v8i16,
/*6966*/      OPC_CheckType, MVT::v8i16,
/*6968*/      OPC_CheckPatternPredicate, 0, // (PPCSubTarget.hasAltivec())
/*6970*/      OPC_MorphNodeTo, TARGET_VAL(PPC::VSRH), 0,
                  1/*#VTs*/, MVT::v8i16, 2/*#Ops*/, 0, 1, 
              // Src: (srl:v8i16 v8i16:v8i16:$vA, v8i16:v8i16:$vB) - Complexity = 3
              // Dst: (VSRH:v8i16 ?:v8i16:$vA, ?:v8i16:$vB)
/*6979*/    /*Scope*/ 15, /*->6995*/
/*6980*/      OPC_CheckChild1Type, MVT::v4i32,
/*6982*/      OPC_CheckType, MVT::v4i32,
/*6984*/      OPC_CheckPatternPredicate, 0, // (PPCSubTarget.hasAltivec())
/*6986*/      OPC_MorphNodeTo, TARGET_VAL(PPC::VSRW), 0,
                  1/*#VTs*/, MVT::v4i32, 2/*#Ops*/, 0, 1, 
              // Src: (srl:v4i32 v4i32:v4i32:$vA, v4i32:v4i32:$vB) - Complexity = 3
              // Dst: (VSRW:v4i32 ?:v4i32:$vA, ?:v4i32:$vB)
/*6995*/    0, /*End of Scope*/
/*6996*/  /*SwitchOpcode*/ 92,  TARGET_VAL(ISD::ROTL),// ->7091
/*6999*/    OPC_RecordChild0, // #0 = $in
/*7000*/    OPC_RecordChild1, // #1 = $imm
/*7001*/    OPC_Scope, 48, /*->7051*/ // 2 children in Scope
/*7003*/      OPC_MoveChild, 1,
/*7005*/      OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*7008*/      OPC_CheckType, MVT::i32,
/*7010*/      OPC_MoveParent,
/*7011*/      OPC_SwitchType /*2 cases */, 19,  MVT::i32,// ->7033
/*7014*/        OPC_EmitConvertToTarget, 1,
/*7016*/        OPC_EmitInteger, MVT::i32, 0, 
/*7019*/        OPC_EmitInteger, MVT::i32, 31, 
/*7022*/        OPC_MorphNodeTo, TARGET_VAL(PPC::RLWINM), 0,
                    1/*#VTs*/, MVT::i32, 4/*#Ops*/, 0, 2, 3, 4, 
                // Src: (rotl:i32 i32:i32:$in, (imm:i32):$imm) - Complexity = 6
                // Dst: (RLWINM:i32 ?:i32:$in, (imm:i32):$imm, 0:i32, 31:i32)
/*7033*/      /*SwitchType*/ 15,  MVT::i64,// ->7050
/*7035*/        OPC_EmitConvertToTarget, 1,
/*7037*/        OPC_EmitInteger, MVT::i32, 0, 
/*7040*/        OPC_MorphNodeTo, TARGET_VAL(PPC::RLDICL), 0,
                    1/*#VTs*/, MVT::i64, 3/*#Ops*/, 0, 2, 3, 
                // Src: (rotl:i64 i64:i64:$in, (imm:i32):$imm) - Complexity = 6
                // Dst: (RLDICL:i64 ?:i64:$in, (imm:i32):$imm, 0:i32)
/*7050*/      0, // EndSwitchType
/*7051*/    /*Scope*/ 38, /*->7090*/
/*7052*/      OPC_CheckChild1Type, MVT::i32,
/*7054*/      OPC_SwitchType /*2 cases */, 17,  MVT::i32,// ->7074
/*7057*/        OPC_EmitInteger, MVT::i32, 0, 
/*7060*/        OPC_EmitInteger, MVT::i32, 31, 
/*7063*/        OPC_MorphNodeTo, TARGET_VAL(PPC::RLWNM), 0,
                    1/*#VTs*/, MVT::i32, 4/*#Ops*/, 0, 1, 2, 3, 
                // Src: (rotl:i32 i32:i32:$in, i32:i32:$sh) - Complexity = 3
                // Dst: (RLWNM:i32 ?:i32:$in, ?:i32:$sh, 0:i32, 31:i32)
/*7074*/      /*SwitchType*/ 13,  MVT::i64,// ->7089
/*7076*/        OPC_EmitInteger, MVT::i32, 0, 
/*7079*/        OPC_MorphNodeTo, TARGET_VAL(PPC::RLDCL), 0,
                    1/*#VTs*/, MVT::i64, 3/*#Ops*/, 0, 1, 2, 
                // Src: (rotl:i64 i64:i64:$in, i32:i32:$sh) - Complexity = 3
                // Dst: (RLDCL:i64 ?:i64:$in, ?:i32:$sh, 0:i32)
/*7089*/      0, // EndSwitchType
/*7090*/    0, /*End of Scope*/
/*7091*/  /*SwitchOpcode*/ 51,  TARGET_VAL(PPCISD::CALL_NOP),// ->7145
/*7094*/    OPC_RecordNode,   // #0 = 'PPCcall_nop' chained node
/*7095*/    OPC_CaptureGlueInput,
/*7096*/    OPC_RecordChild1, // #1 = $func
/*7097*/    OPC_MoveChild, 1,
/*7099*/    OPC_SwitchOpcode /*3 cases */, 13,  TARGET_VAL(ISD::Constant),// ->7116
/*7103*/      OPC_CheckType, MVT::i64,
/*7105*/      OPC_MoveParent,
/*7106*/      OPC_EmitMergeInputChains1_0,
/*7107*/      OPC_EmitConvertToTarget, 1,
/*7109*/      OPC_MorphNodeTo, TARGET_VAL(PPC::BLA8_NOP), 0|OPFL_Chain|OPFL_GlueInput|OPFL_GlueOutput|OPFL_Variadic1,
                  0/*#VTs*/, 1/*#Ops*/, 2, 
              // Src: (PPCcall_nop (imm:i64):$func) - Complexity = 6
              // Dst: (BLA8_NOP (imm:i64):$func)
/*7116*/    /*SwitchOpcode*/ 11,  TARGET_VAL(ISD::TargetGlobalAddress),// ->7130
/*7119*/      OPC_CheckType, MVT::i64,
/*7121*/      OPC_MoveParent,
/*7122*/      OPC_EmitMergeInputChains1_0,
/*7123*/      OPC_MorphNodeTo, TARGET_VAL(PPC::BL8_NOP), 0|OPFL_Chain|OPFL_GlueInput|OPFL_GlueOutput|OPFL_Variadic1,
                  0/*#VTs*/, 1/*#Ops*/, 1, 
              // Src: (PPCcall_nop (tglobaladdr:i64):$dst) - Complexity = 6
              // Dst: (BL8_NOP (tglobaladdr:i64):$dst)
/*7130*/    /*SwitchOpcode*/ 11,  TARGET_VAL(ISD::TargetExternalSymbol),// ->7144
/*7133*/      OPC_CheckType, MVT::i64,
/*7135*/      OPC_MoveParent,
/*7136*/      OPC_EmitMergeInputChains1_0,
/*7137*/      OPC_MorphNodeTo, TARGET_VAL(PPC::BL8_NOP), 0|OPFL_Chain|OPFL_GlueInput|OPFL_GlueOutput|OPFL_Variadic1,
                  0/*#VTs*/, 1/*#Ops*/, 1, 
              // Src: (PPCcall_nop (texternalsym:i64):$dst) - Complexity = 6
              // Dst: (BL8_NOP (texternalsym:i64):$dst)
/*7144*/    0, // EndSwitchOpcode
/*7145*/  /*SwitchOpcode*/ 53,  TARGET_VAL(PPCISD::TOC_ENTRY),// ->7201
/*7148*/    OPC_RecordChild0, // #0 = $disp
/*7149*/    OPC_MoveChild, 0,
/*7151*/    OPC_SwitchOpcode /*3 cases */, 13,  TARGET_VAL(ISD::TargetGlobalAddress),// ->7168
/*7155*/      OPC_MoveParent,
/*7156*/      OPC_RecordChild1, // #1 = $reg
/*7157*/      OPC_CheckType, MVT::i64,
/*7159*/      OPC_MorphNodeTo, TARGET_VAL(PPC::LDtoc), 0,
                  1/*#VTs*/, MVT::i64, 2/*#Ops*/, 0, 1, 
              // Src: (PPCtoc_entry:i64 (tglobaladdr:i64):$disp, i64:i64:$reg) - Complexity = 6
              // Dst: (LDtoc:i64 (tglobaladdr:i64):$disp, i64:i64:$reg)
/*7168*/    /*SwitchOpcode*/ 13,  TARGET_VAL(ISD::TargetJumpTable),// ->7184
/*7171*/      OPC_MoveParent,
/*7172*/      OPC_RecordChild1, // #1 = $reg
/*7173*/      OPC_CheckType, MVT::i64,
/*7175*/      OPC_MorphNodeTo, TARGET_VAL(PPC::LDtocJTI), 0,
                  1/*#VTs*/, MVT::i64, 2/*#Ops*/, 0, 1, 
              // Src: (PPCtoc_entry:i64 (tjumptable:i64):$disp, i64:i64:$reg) - Complexity = 6
              // Dst: (LDtocJTI:i64 (tjumptable:i64):$disp, i64:i64:$reg)
/*7184*/    /*SwitchOpcode*/ 13,  TARGET_VAL(ISD::TargetConstantPool),// ->7200
/*7187*/      OPC_MoveParent,
/*7188*/      OPC_RecordChild1, // #1 = $reg
/*7189*/      OPC_CheckType, MVT::i64,
/*7191*/      OPC_MorphNodeTo, TARGET_VAL(PPC::LDtocCPT), 0,
                  1/*#VTs*/, MVT::i64, 2/*#Ops*/, 0, 1, 
              // Src: (PPCtoc_entry:i64 (tconstpool:i64):$disp, i64:i64:$reg) - Complexity = 6
              // Dst: (LDtocCPT:i64 (tconstpool:i64):$disp, i64:i64:$reg)
/*7200*/    0, // EndSwitchOpcode
/*7201*/  /*SwitchOpcode*/ 19,  TARGET_VAL(PPCISD::ADDIS_TOC_HA),// ->7223
/*7204*/    OPC_RecordChild0, // #0 = $reg
/*7205*/    OPC_RecordChild1, // #1 = $disp
/*7206*/    OPC_MoveChild, 1,
/*7208*/    OPC_CheckOpcode, TARGET_VAL(ISD::TargetGlobalAddress),
/*7211*/    OPC_MoveParent,
/*7212*/    OPC_CheckType, MVT::i64,
/*7214*/    OPC_MorphNodeTo, TARGET_VAL(PPC::ADDIStocHA), 0,
                1/*#VTs*/, MVT::i64, 2/*#Ops*/, 0, 1, 
            // Src: (PPCaddisTocHA:i64 i64:i64:$reg, (tglobaladdr:i64):$disp) - Complexity = 6
            // Dst: (ADDIStocHA:i64 i64:i64:$reg, (tglobaladdr:i64):$disp)
/*7223*/  /*SwitchOpcode*/ 19,  TARGET_VAL(PPCISD::LD_TOC_L),// ->7245
/*7226*/    OPC_RecordChild0, // #0 = $disp
/*7227*/    OPC_MoveChild, 0,
/*7229*/    OPC_CheckOpcode, TARGET_VAL(ISD::TargetGlobalAddress),
/*7232*/    OPC_MoveParent,
/*7233*/    OPC_RecordChild1, // #1 = $reg
/*7234*/    OPC_CheckType, MVT::i64,
/*7236*/    OPC_MorphNodeTo, TARGET_VAL(PPC::LDtocL), 0,
                1/*#VTs*/, MVT::i64, 2/*#Ops*/, 0, 1, 
            // Src: (PPCldTocL:i64 (tglobaladdr:i64):$disp, i64:i64:$reg) - Complexity = 6
            // Dst: (LDtocL:i64 (tglobaladdr:i64):$disp, i64:i64:$reg)
/*7245*/  /*SwitchOpcode*/ 19,  TARGET_VAL(PPCISD::ADDI_TOC_L),// ->7267
/*7248*/    OPC_RecordChild0, // #0 = $reg
/*7249*/    OPC_RecordChild1, // #1 = $disp
/*7250*/    OPC_MoveChild, 1,
/*7252*/    OPC_CheckOpcode, TARGET_VAL(ISD::TargetGlobalAddress),
/*7255*/    OPC_MoveParent,
/*7256*/    OPC_CheckType, MVT::i64,
/*7258*/    OPC_MorphNodeTo, TARGET_VAL(PPC::ADDItocL), 0,
                1/*#VTs*/, MVT::i64, 2/*#Ops*/, 0, 1, 
            // Src: (PPCaddiTocL:i64 i64:i64:$reg, (tglobaladdr:i64):$disp) - Complexity = 6
            // Dst: (ADDItocL:i64 i64:i64:$reg, (tglobaladdr:i64):$disp)
/*7267*/  /*SwitchOpcode*/ 19,  TARGET_VAL(PPCISD::ADDIS_GOT_TPREL_HA),// ->7289
/*7270*/    OPC_RecordChild0, // #0 = $reg
/*7271*/    OPC_RecordChild1, // #1 = $disp
/*7272*/    OPC_MoveChild, 1,
/*7274*/    OPC_CheckOpcode, TARGET_VAL(ISD::TargetGlobalTLSAddress),
/*7277*/    OPC_MoveParent,
/*7278*/    OPC_CheckType, MVT::i64,
/*7280*/    OPC_MorphNodeTo, TARGET_VAL(PPC::ADDISgotTprelHA), 0,
                1/*#VTs*/, MVT::i64, 2/*#Ops*/, 0, 1, 
            // Src: (PPCaddisGotTprelHA:i64 i64:i64:$reg, (tglobaltlsaddr:i64):$disp) - Complexity = 6
            // Dst: (ADDISgotTprelHA:i64 i64:i64:$reg, (tglobaltlsaddr:i64):$disp)
/*7289*/  /*SwitchOpcode*/ 19,  TARGET_VAL(PPCISD::LD_GOT_TPREL_L),// ->7311
/*7292*/    OPC_RecordChild0, // #0 = $disp
/*7293*/    OPC_MoveChild, 0,
/*7295*/    OPC_CheckOpcode, TARGET_VAL(ISD::TargetGlobalTLSAddress),
/*7298*/    OPC_MoveParent,
/*7299*/    OPC_RecordChild1, // #1 = $reg
/*7300*/    OPC_CheckType, MVT::i64,
/*7302*/    OPC_MorphNodeTo, TARGET_VAL(PPC::LDgotTprelL), 0,
                1/*#VTs*/, MVT::i64, 2/*#Ops*/, 0, 1, 
            // Src: (PPCldGotTprelL:i64 (tglobaltlsaddr:i64):$disp, i64:i64:$reg) - Complexity = 6
            // Dst: (LDgotTprelL:i64 (tglobaltlsaddr:i64):$disp, i64:i64:$reg)
/*7311*/  /*SwitchOpcode*/ 19,  TARGET_VAL(PPCISD::ADD_TLS),// ->7333
/*7314*/    OPC_RecordChild0, // #0 = $in
/*7315*/    OPC_RecordChild1, // #1 = $g
/*7316*/    OPC_MoveChild, 1,
/*7318*/    OPC_CheckOpcode, TARGET_VAL(ISD::TargetGlobalTLSAddress),
/*7321*/    OPC_MoveParent,
/*7322*/    OPC_CheckType, MVT::i64,
/*7324*/    OPC_MorphNodeTo, TARGET_VAL(PPC::ADD8TLS), 0,
                1/*#VTs*/, MVT::i64, 2/*#Ops*/, 0, 1, 
            // Src: (PPCaddTls:i64 i64:i64:$in, (tglobaltlsaddr:i64):$g) - Complexity = 6
            // Dst: (ADD8TLS:i64 ?:i64:$in, (tglobaltlsaddr:i64):$g)
/*7333*/  /*SwitchOpcode*/ 19,  TARGET_VAL(PPCISD::ADDIS_TLSGD_HA),// ->7355
/*7336*/    OPC_RecordChild0, // #0 = $reg
/*7337*/    OPC_RecordChild1, // #1 = $disp
/*7338*/    OPC_MoveChild, 1,
/*7340*/    OPC_CheckOpcode, TARGET_VAL(ISD::TargetGlobalTLSAddress),
/*7343*/    OPC_MoveParent,
/*7344*/    OPC_CheckType, MVT::i64,
/*7346*/    OPC_MorphNodeTo, TARGET_VAL(PPC::ADDIStlsgdHA), 0,
                1/*#VTs*/, MVT::i64, 2/*#Ops*/, 0, 1, 
            // Src: (PPCaddisTlsgdHA:i64 i64:i64:$reg, (tglobaltlsaddr:i64):$disp) - Complexity = 6
            // Dst: (ADDIStlsgdHA:i64 i64:i64:$reg, (tglobaltlsaddr:i64):$disp)
/*7355*/  /*SwitchOpcode*/ 19,  TARGET_VAL(PPCISD::ADDI_TLSGD_L),// ->7377
/*7358*/    OPC_RecordChild0, // #0 = $reg
/*7359*/    OPC_RecordChild1, // #1 = $disp
/*7360*/    OPC_MoveChild, 1,
/*7362*/    OPC_CheckOpcode, TARGET_VAL(ISD::TargetGlobalTLSAddress),
/*7365*/    OPC_MoveParent,
/*7366*/    OPC_CheckType, MVT::i64,
/*7368*/    OPC_MorphNodeTo, TARGET_VAL(PPC::ADDItlsgdL), 0,
                1/*#VTs*/, MVT::i64, 2/*#Ops*/, 0, 1, 
            // Src: (PPCaddiTlsgdL:i64 i64:i64:$reg, (tglobaltlsaddr:i64):$disp) - Complexity = 6
            // Dst: (ADDItlsgdL:i64 i64:i64:$reg, (tglobaltlsaddr:i64):$disp)
/*7377*/  /*SwitchOpcode*/ 19,  TARGET_VAL(PPCISD::GET_TLS_ADDR),// ->7399
/*7380*/    OPC_RecordChild0, // #0 = $reg
/*7381*/    OPC_RecordChild1, // #1 = $sym
/*7382*/    OPC_MoveChild, 1,
/*7384*/    OPC_CheckOpcode, TARGET_VAL(ISD::TargetGlobalTLSAddress),
/*7387*/    OPC_MoveParent,
/*7388*/    OPC_CheckType, MVT::i64,
/*7390*/    OPC_MorphNodeTo, TARGET_VAL(PPC::GETtlsADDR), 0,
                1/*#VTs*/, MVT::i64, 2/*#Ops*/, 0, 1, 
            // Src: (PPCgetTlsAddr:i64 i64:i64:$reg, (tglobaltlsaddr:i64):$sym) - Complexity = 6
            // Dst: (GETtlsADDR:i64 i64:i64:$reg, (tglobaltlsaddr:i64):$sym)
/*7399*/  /*SwitchOpcode*/ 19,  TARGET_VAL(PPCISD::ADDIS_TLSLD_HA),// ->7421
/*7402*/    OPC_RecordChild0, // #0 = $reg
/*7403*/    OPC_RecordChild1, // #1 = $disp
/*7404*/    OPC_MoveChild, 1,
/*7406*/    OPC_CheckOpcode, TARGET_VAL(ISD::TargetGlobalTLSAddress),
/*7409*/    OPC_MoveParent,
/*7410*/    OPC_CheckType, MVT::i64,
/*7412*/    OPC_MorphNodeTo, TARGET_VAL(PPC::ADDIStlsldHA), 0,
                1/*#VTs*/, MVT::i64, 2/*#Ops*/, 0, 1, 
            // Src: (PPCaddisTlsldHA:i64 i64:i64:$reg, (tglobaltlsaddr:i64):$disp) - Complexity = 6
            // Dst: (ADDIStlsldHA:i64 i64:i64:$reg, (tglobaltlsaddr:i64):$disp)
/*7421*/  /*SwitchOpcode*/ 19,  TARGET_VAL(PPCISD::ADDI_TLSLD_L),// ->7443
/*7424*/    OPC_RecordChild0, // #0 = $reg
/*7425*/    OPC_RecordChild1, // #1 = $disp
/*7426*/    OPC_MoveChild, 1,
/*7428*/    OPC_CheckOpcode, TARGET_VAL(ISD::TargetGlobalTLSAddress),
/*7431*/    OPC_MoveParent,
/*7432*/    OPC_CheckType, MVT::i64,
/*7434*/    OPC_MorphNodeTo, TARGET_VAL(PPC::ADDItlsldL), 0,
                1/*#VTs*/, MVT::i64, 2/*#Ops*/, 0, 1, 
            // Src: (PPCaddiTlsldL:i64 i64:i64:$reg, (tglobaltlsaddr:i64):$disp) - Complexity = 6
            // Dst: (ADDItlsldL:i64 i64:i64:$reg, (tglobaltlsaddr:i64):$disp)
/*7443*/  /*SwitchOpcode*/ 19,  TARGET_VAL(PPCISD::GET_TLSLD_ADDR),// ->7465
/*7446*/    OPC_RecordChild0, // #0 = $reg
/*7447*/    OPC_RecordChild1, // #1 = $sym
/*7448*/    OPC_MoveChild, 1,
/*7450*/    OPC_CheckOpcode, TARGET_VAL(ISD::TargetGlobalTLSAddress),
/*7453*/    OPC_MoveParent,
/*7454*/    OPC_CheckType, MVT::i64,
/*7456*/    OPC_MorphNodeTo, TARGET_VAL(PPC::GETtlsldADDR), 0,
                1/*#VTs*/, MVT::i64, 2/*#Ops*/, 0, 1, 
            // Src: (PPCgetTlsldAddr:i64 i64:i64:$reg, (tglobaltlsaddr:i64):$sym) - Complexity = 6
            // Dst: (GETtlsldADDR:i64 i64:i64:$reg, (tglobaltlsaddr:i64):$sym)
/*7465*/  /*SwitchOpcode*/ 21,  TARGET_VAL(PPCISD::ADDIS_DTPREL_HA),// ->7489
/*7468*/    OPC_RecordNode,   // #0 = 'PPCaddisDtprelHA' chained node
/*7469*/    OPC_RecordChild1, // #1 = $reg
/*7470*/    OPC_RecordChild2, // #2 = $disp
/*7471*/    OPC_MoveChild, 2,
/*7473*/    OPC_CheckOpcode, TARGET_VAL(ISD::TargetGlobalTLSAddress),
/*7476*/    OPC_MoveParent,
/*7477*/    OPC_CheckType, MVT::i64,
/*7479*/    OPC_EmitMergeInputChains1_0,
/*7480*/    OPC_MorphNodeTo, TARGET_VAL(PPC::ADDISdtprelHA), 0|OPFL_Chain,
                1/*#VTs*/, MVT::i64, 2/*#Ops*/, 1, 2, 
            // Src: (PPCaddisDtprelHA:i64 i64:i64:$reg, (tglobaltlsaddr:i64):$disp) - Complexity = 6
            // Dst: (ADDISdtprelHA:i64 i64:i64:$reg, (tglobaltlsaddr:i64):$disp)
/*7489*/  /*SwitchOpcode*/ 19,  TARGET_VAL(PPCISD::ADDI_DTPREL_L),// ->7511
/*7492*/    OPC_RecordChild0, // #0 = $reg
/*7493*/    OPC_RecordChild1, // #1 = $disp
/*7494*/    OPC_MoveChild, 1,
/*7496*/    OPC_CheckOpcode, TARGET_VAL(ISD::TargetGlobalTLSAddress),
/*7499*/    OPC_MoveParent,
/*7500*/    OPC_CheckType, MVT::i64,
/*7502*/    OPC_MorphNodeTo, TARGET_VAL(PPC::ADDIdtprelL), 0,
                1/*#VTs*/, MVT::i64, 2/*#Ops*/, 0, 1, 
            // Src: (PPCaddiDtprelL:i64 i64:i64:$reg, (tglobaltlsaddr:i64):$disp) - Complexity = 6
            // Dst: (ADDIdtprelL:i64 i64:i64:$reg, (tglobaltlsaddr:i64):$disp)
/*7511*/  /*SwitchOpcode*/ 97,  TARGET_VAL(ISD::Constant),// ->7611
/*7514*/    OPC_RecordNode,   // #0 = $imm
/*7515*/    OPC_SwitchType /*2 cases */, 59,  MVT::i32,// ->7577
/*7518*/      OPC_Scope, 12, /*->7532*/ // 3 children in Scope
/*7520*/        OPC_CheckPredicate, 0, // Predicate_imm32SExt16
/*7522*/        OPC_EmitConvertToTarget, 0,
/*7524*/        OPC_MorphNodeTo, TARGET_VAL(PPC::LI), 0,
                    1/*#VTs*/, MVT::i32, 1/*#Ops*/, 1, 
                // Src: (imm:i32)<<P:Predicate_imm32SExt16>>:$imm - Complexity = 4
                // Dst: (LI:i32 (imm:i32):$imm)
/*7532*/      /*Scope*/ 15, /*->7548*/
/*7533*/        OPC_CheckPredicate, 1, // Predicate_imm16ShiftedSExt
/*7535*/        OPC_EmitConvertToTarget, 0,
/*7537*/        OPC_EmitNodeXForm, 0, 1, // HI16
/*7540*/        OPC_MorphNodeTo, TARGET_VAL(PPC::LIS), 0,
                    1/*#VTs*/, MVT::i32, 1/*#Ops*/, 2, 
                // Src: (imm:i32)<<P:Predicate_imm16ShiftedSExt>><<X:HI16>>:$imm - Complexity = 4
                // Dst: (LIS:i32 (HI16:i32 (imm:i32):$imm))
/*7548*/      /*Scope*/ 27, /*->7576*/
/*7549*/        OPC_EmitConvertToTarget, 0,
/*7551*/        OPC_EmitNodeXForm, 0, 1, // HI16
/*7554*/        OPC_EmitNode, TARGET_VAL(PPC::LIS), 0,
                    1/*#VTs*/, MVT::i32, 1/*#Ops*/, 2,  // Results = #3
/*7562*/        OPC_EmitConvertToTarget, 0,
/*7564*/        OPC_EmitNodeXForm, 1, 4, // LO16
/*7567*/        OPC_MorphNodeTo, TARGET_VAL(PPC::ORI), 0,
                    1/*#VTs*/, MVT::i32, 2/*#Ops*/, 3, 5, 
                // Src: (imm:i32):$imm - Complexity = 3
                // Dst: (ORI:i32 (LIS:i32 (HI16:i32 (imm:i32):$imm)), (LO16:i32 (imm:i32):$imm))
/*7576*/      0, /*End of Scope*/
/*7577*/    /*SwitchType*/ 31,  MVT::i64,// ->7610
/*7579*/      OPC_Scope, 12, /*->7593*/ // 2 children in Scope
/*7581*/        OPC_CheckPredicate, 2, // Predicate_imm64SExt16
/*7583*/        OPC_EmitConvertToTarget, 0,
/*7585*/        OPC_MorphNodeTo, TARGET_VAL(PPC::LI8), 0,
                    1/*#VTs*/, MVT::i64, 1/*#Ops*/, 1, 
                // Src: (imm:i64)<<P:Predicate_imm64SExt16>>:$imm - Complexity = 4
                // Dst: (LI8:i64 (imm:i64):$imm)
/*7593*/      /*Scope*/ 15, /*->7609*/
/*7594*/        OPC_CheckPredicate, 1, // Predicate_imm16ShiftedSExt
/*7596*/        OPC_EmitConvertToTarget, 0,
/*7598*/        OPC_EmitNodeXForm, 0, 1, // HI16
/*7601*/        OPC_MorphNodeTo, TARGET_VAL(PPC::LIS8), 0,
                    1/*#VTs*/, MVT::i64, 1/*#Ops*/, 2, 
                // Src: (imm:i64)<<P:Predicate_imm16ShiftedSExt>><<X:HI16>>:$imm - Complexity = 4
                // Dst: (LIS8:i64 (HI16:i64 (imm:i64):$imm))
/*7609*/      0, /*End of Scope*/
/*7610*/    0, // EndSwitchType
/*7611*/  /*SwitchOpcode*/ 9,  TARGET_VAL(PPCISD::RET_FLAG),// ->7623
/*7614*/    OPC_RecordNode,   // #0 = 'retflag' chained node
/*7615*/    OPC_CaptureGlueInput,
/*7616*/    OPC_EmitMergeInputChains1_0,
/*7617*/    OPC_MorphNodeTo, TARGET_VAL(PPC::BLR), 0|OPFL_Chain|OPFL_GlueInput|OPFL_Variadic0,
                0/*#VTs*/, 0/*#Ops*/, 
            // Src: (retflag) - Complexity = 3
            // Dst: (BLR)
/*7623*/  /*SwitchOpcode*/ 16,  TARGET_VAL(ISD::BR),// ->7642
/*7626*/    OPC_RecordNode,   // #0 = 'br' chained node
/*7627*/    OPC_RecordChild1, // #1 = $dst
/*7628*/    OPC_MoveChild, 1,
/*7630*/    OPC_CheckOpcode, TARGET_VAL(ISD::BasicBlock),
/*7633*/    OPC_MoveParent,
/*7634*/    OPC_EmitMergeInputChains1_0,
/*7635*/    OPC_MorphNodeTo, TARGET_VAL(PPC::B), 0|OPFL_Chain,
                0/*#VTs*/, 1/*#Ops*/, 1, 
            // Src: (br (bb:Other):$dst) - Complexity = 3
            // Dst: (B (bb:Other):$dst)
/*7642*/  /*SwitchOpcode*/ 24,  TARGET_VAL(PPCISD::BCTRL),// ->7669
/*7645*/    OPC_RecordNode,   // #0 = 'PPCbctrl' chained node
/*7646*/    OPC_CaptureGlueInput,
/*7647*/    OPC_Scope, 9, /*->7658*/ // 2 children in Scope
/*7649*/      OPC_CheckPatternPredicate, 1, // (!PPCSubTarget.isPPC64())
/*7651*/      OPC_EmitMergeInputChains1_0,
/*7652*/      OPC_MorphNodeTo, TARGET_VAL(PPC::BCTRL), 0|OPFL_Chain|OPFL_GlueInput|OPFL_GlueOutput|OPFL_Variadic0,
                  0/*#VTs*/, 0/*#Ops*/, 
              // Src: (PPCbctrl) - Complexity = 3
              // Dst: (BCTRL)
/*7658*/    /*Scope*/ 9, /*->7668*/
/*7659*/      OPC_CheckPatternPredicate, 2, // (PPCSubTarget.isPPC64())
/*7661*/      OPC_EmitMergeInputChains1_0,
/*7662*/      OPC_MorphNodeTo, TARGET_VAL(PPC::BCTRL8), 0|OPFL_Chain|OPFL_GlueInput|OPFL_GlueOutput|OPFL_Variadic0,
                  0/*#VTs*/, 0/*#Ops*/, 
              // Src: (PPCbctrl) - Complexity = 3
              // Dst: (BCTRL8)
/*7668*/    0, /*End of Scope*/
/*7669*/  /*SwitchOpcode*/ 8,  TARGET_VAL(ISD::TRAP),// ->7680
/*7672*/    OPC_RecordNode,   // #0 = 'trap' chained node
/*7673*/    OPC_EmitMergeInputChains1_0,
/*7674*/    OPC_MorphNodeTo, TARGET_VAL(PPC::TRAP), 0|OPFL_Chain,
                0/*#VTs*/, 0/*#Ops*/, 
            // Src: (trap) - Complexity = 3
            // Dst: (TRAP)
/*7680*/  /*SwitchOpcode*/ 28,  TARGET_VAL(PPCISD::SHL),// ->7711
/*7683*/    OPC_RecordChild0, // #0 = $rS
/*7684*/    OPC_RecordChild1, // #1 = $rB
/*7685*/    OPC_CheckChild1Type, MVT::i32,
/*7687*/    OPC_SwitchType /*2 cases */, 9,  MVT::i32,// ->7699
/*7690*/      OPC_MorphNodeTo, TARGET_VAL(PPC::SLW), 0,
                  1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1, 
              // Src: (PPCshl:i32 i32:i32:$rS, i32:i32:$rB) - Complexity = 3
              // Dst: (SLW:i32 i32:i32:$rS, i32:i32:$rB)
/*7699*/    /*SwitchType*/ 9,  MVT::i64,// ->7710
/*7701*/      OPC_MorphNodeTo, TARGET_VAL(PPC::SLD), 0,
                  1/*#VTs*/, MVT::i64, 2/*#Ops*/, 0, 1, 
              // Src: (PPCshl:i64 i64:i64:$rS, i32:i32:$rB) - Complexity = 3
              // Dst: (SLD:i64 i64:i64:$rS, i32:i32:$rB)
/*7710*/    0, // EndSwitchType
/*7711*/  /*SwitchOpcode*/ 28,  TARGET_VAL(PPCISD::SRL),// ->7742
/*7714*/    OPC_RecordChild0, // #0 = $rS
/*7715*/    OPC_RecordChild1, // #1 = $rB
/*7716*/    OPC_CheckChild1Type, MVT::i32,
/*7718*/    OPC_SwitchType /*2 cases */, 9,  MVT::i32,// ->7730
/*7721*/      OPC_MorphNodeTo, TARGET_VAL(PPC::SRW), 0,
                  1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1, 
              // Src: (PPCsrl:i32 i32:i32:$rS, i32:i32:$rB) - Complexity = 3
              // Dst: (SRW:i32 i32:i32:$rS, i32:i32:$rB)
/*7730*/    /*SwitchType*/ 9,  MVT::i64,// ->7741
/*7732*/      OPC_MorphNodeTo, TARGET_VAL(PPC::SRD), 0,
                  1/*#VTs*/, MVT::i64, 2/*#Ops*/, 0, 1, 
              // Src: (PPCsrl:i64 i64:i64:$rS, i32:i32:$rB) - Complexity = 3
              // Dst: (SRD:i64 i64:i64:$rS, i32:i32:$rB)
/*7741*/    0, // EndSwitchType
/*7742*/  /*SwitchOpcode*/ 30,  TARGET_VAL(PPCISD::SRA),// ->7775
/*7745*/    OPC_RecordChild0, // #0 = $rS
/*7746*/    OPC_RecordChild1, // #1 = $rB
/*7747*/    OPC_CheckChild1Type, MVT::i32,
/*7749*/    OPC_SwitchType /*2 cases */, 10,  MVT::i32,// ->7762
/*7752*/      OPC_MorphNodeTo, TARGET_VAL(PPC::SRAW), 0,
                  2/*#VTs*/, MVT::i32, MVT::i32, 2/*#Ops*/, 0, 1, 
              // Src: (PPCsra:i32 i32:i32:$rS, i32:i32:$rB) - Complexity = 3
              // Dst: (SRAW:i32:i32 i32:i32:$rS, i32:i32:$rB)
/*7762*/    /*SwitchType*/ 10,  MVT::i64,// ->7774
/*7764*/      OPC_MorphNodeTo, TARGET_VAL(PPC::SRAD), 0,
                  2/*#VTs*/, MVT::i64, MVT::i32, 2/*#Ops*/, 0, 1, 
              // Src: (PPCsra:i64 i64:i64:$rS, i32:i32:$rB) - Complexity = 3
              // Dst: (SRAD:i64:i32 i64:i64:$rS, i32:i32:$rB)
/*7774*/    0, // EndSwitchType
/*7775*/  /*SwitchOpcode*/ 23,  TARGET_VAL(ISD::CTLZ),// ->7801
/*7778*/    OPC_RecordChild0, // #0 = $rS
/*7779*/    OPC_SwitchType /*2 cases */, 8,  MVT::i32,// ->7790
/*7782*/      OPC_MorphNodeTo, TARGET_VAL(PPC::CNTLZW), 0,
                  1/*#VTs*/, MVT::i32, 1/*#Ops*/, 0, 
              // Src: (ctlz:i32 i32:i32:$rS) - Complexity = 3
              // Dst: (CNTLZW:i32 i32:i32:$rS)
/*7790*/    /*SwitchType*/ 8,  MVT::i64,// ->7800
/*7792*/      OPC_MorphNodeTo, TARGET_VAL(PPC::CNTLZD), 0,
                  1/*#VTs*/, MVT::i64, 1/*#Ops*/, 0, 
              // Src: (ctlz:i64 i64:i64:$rS) - Complexity = 3
              // Dst: (CNTLZD:i64 i64:i64:$rS)
/*7800*/    0, // EndSwitchType
/*7801*/  /*SwitchOpcode*/ 69,  TARGET_VAL(ISD::SIGN_EXTEND_INREG),// ->7873
/*7804*/    OPC_RecordChild0, // #0 = $rS
/*7805*/    OPC_MoveChild, 1,
/*7807*/    OPC_Scope, 25, /*->7834*/ // 3 children in Scope
/*7809*/      OPC_CheckValueType, MVT::i8,
/*7811*/      OPC_MoveParent,
/*7812*/      OPC_SwitchType /*2 cases */, 8,  MVT::i32,// ->7823
/*7815*/        OPC_MorphNodeTo, TARGET_VAL(PPC::EXTSB), 0,
                    1/*#VTs*/, MVT::i32, 1/*#Ops*/, 0, 
                // Src: (sext_inreg:i32 i32:i32:$rS, i8:Other) - Complexity = 3
                // Dst: (EXTSB:i32 i32:i32:$rS)
/*7823*/      /*SwitchType*/ 8,  MVT::i64,// ->7833
/*7825*/        OPC_MorphNodeTo, TARGET_VAL(PPC::EXTSB8), 0,
                    1/*#VTs*/, MVT::i64, 1/*#Ops*/, 0, 
                // Src: (sext_inreg:i64 i64:i64:$rS, i8:Other) - Complexity = 3
                // Dst: (EXTSB8:i64 i64:i64:$rS)
/*7833*/      0, // EndSwitchType
/*7834*/    /*Scope*/ 25, /*->7860*/
/*7835*/      OPC_CheckValueType, MVT::i16,
/*7837*/      OPC_MoveParent,
/*7838*/      OPC_SwitchType /*2 cases */, 8,  MVT::i32,// ->7849
/*7841*/        OPC_MorphNodeTo, TARGET_VAL(PPC::EXTSH), 0,
                    1/*#VTs*/, MVT::i32, 1/*#Ops*/, 0, 
                // Src: (sext_inreg:i32 i32:i32:$rS, i16:Other) - Complexity = 3
                // Dst: (EXTSH:i32 i32:i32:$rS)
/*7849*/      /*SwitchType*/ 8,  MVT::i64,// ->7859
/*7851*/        OPC_MorphNodeTo, TARGET_VAL(PPC::EXTSH8), 0,
                    1/*#VTs*/, MVT::i64, 1/*#Ops*/, 0, 
                // Src: (sext_inreg:i64 i64:i64:$rS, i16:Other) - Complexity = 3
                // Dst: (EXTSH8:i64 i64:i64:$rS)
/*7859*/      0, // EndSwitchType
/*7860*/    /*Scope*/ 11, /*->7872*/
/*7861*/      OPC_CheckValueType, MVT::i32,
/*7863*/      OPC_MoveParent,
/*7864*/      OPC_MorphNodeTo, TARGET_VAL(PPC::EXTSW), 0,
                  1/*#VTs*/, MVT::i64, 1/*#Ops*/, 0, 
              // Src: (sext_inreg:i64 i64:i64:$rS, i32:Other) - Complexity = 3
              // Dst: (EXTSW:i64 i64:i64:$rS)
/*7872*/    0, /*End of Scope*/
/*7873*/  /*SwitchOpcode*/ 10,  TARGET_VAL(PPCISD::CR6SET),// ->7886
/*7876*/    OPC_RecordNode,   // #0 = 'PPCcr6set' chained node
/*7877*/    OPC_CaptureGlueInput,
/*7878*/    OPC_EmitMergeInputChains1_0,
/*7879*/    OPC_MorphNodeTo, TARGET_VAL(PPC::CR6SET), 0|OPFL_Chain|OPFL_GlueInput|OPFL_GlueOutput,
                1/*#VTs*/, MVT::i32, 0/*#Ops*/, 
            // Src: (PPCcr6set) - Complexity = 3
            // Dst: (CR6SET:i32)
/*7886*/  /*SwitchOpcode*/ 10,  TARGET_VAL(PPCISD::CR6UNSET),// ->7899
/*7889*/    OPC_RecordNode,   // #0 = 'PPCcr6unset' chained node
/*7890*/    OPC_CaptureGlueInput,
/*7891*/    OPC_EmitMergeInputChains1_0,
/*7892*/    OPC_MorphNodeTo, TARGET_VAL(PPC::CR6UNSET), 0|OPFL_Chain|OPFL_GlueInput|OPFL_GlueOutput,
                1/*#VTs*/, MVT::i32, 0/*#Ops*/, 
            // Src: (PPCcr6unset) - Complexity = 3
            // Dst: (CR6UNSET:i32)
/*7899*/  /*SwitchOpcode*/ 29,  TARGET_VAL(PPCISD::MTCTR),// ->7931
/*7902*/    OPC_RecordNode,   // #0 = 'PPCmtctr' chained node
/*7903*/    OPC_CaptureGlueInput,
/*7904*/    OPC_RecordChild1, // #1 = $rS
/*7905*/    OPC_Scope, 11, /*->7918*/ // 2 children in Scope
/*7907*/      OPC_CheckChild1Type, MVT::i32,
/*7909*/      OPC_EmitMergeInputChains1_0,
/*7910*/      OPC_MorphNodeTo, TARGET_VAL(PPC::MTCTR), 0|OPFL_Chain|OPFL_GlueInput|OPFL_GlueOutput,
                  1/*#VTs*/, MVT::i32, 1/*#Ops*/, 1, 
              // Src: (PPCmtctr i32:i32:$rS) - Complexity = 3
              // Dst: (MTCTR:i32 i32:i32:$rS)
/*7918*/    /*Scope*/ 11, /*->7930*/
/*7919*/      OPC_CheckChild1Type, MVT::i64,
/*7921*/      OPC_EmitMergeInputChains1_0,
/*7922*/      OPC_MorphNodeTo, TARGET_VAL(PPC::MTCTR8), 0|OPFL_Chain|OPFL_GlueInput|OPFL_GlueOutput,
                  1/*#VTs*/, MVT::i64, 1/*#Ops*/, 1, 
              // Src: (PPCmtctr i64:i64:$rS) - Complexity = 3
              // Dst: (MTCTR8:i64 i64:i64:$rS)
/*7930*/    0, /*End of Scope*/
/*7931*/  /*SwitchOpcode*/ 26,  TARGET_VAL(ISD::SDIV),// ->7960
/*7934*/    OPC_RecordChild0, // #0 = $rA
/*7935*/    OPC_RecordChild1, // #1 = $rB
/*7936*/    OPC_SwitchType /*2 cases */, 9,  MVT::i32,// ->7948
/*7939*/      OPC_MorphNodeTo, TARGET_VAL(PPC::DIVW), 0,
                  1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1, 
              // Src: (sdiv:i32 i32:i32:$rA, i32:i32:$rB) - Complexity = 3
              // Dst: (DIVW:i32 i32:i32:$rA, i32:i32:$rB)
/*7948*/    /*SwitchType*/ 9,  MVT::i64,// ->7959
/*7950*/      OPC_MorphNodeTo, TARGET_VAL(PPC::DIVD), 0,
                  1/*#VTs*/, MVT::i64, 2/*#Ops*/, 0, 1, 
              // Src: (sdiv:i64 i64:i64:$rA, i64:i64:$rB) - Complexity = 3
              // Dst: (DIVD:i64 i64:i64:$rA, i64:i64:$rB)
/*7959*/    0, // EndSwitchType
/*7960*/  /*SwitchOpcode*/ 26,  TARGET_VAL(ISD::UDIV),// ->7989
/*7963*/    OPC_RecordChild0, // #0 = $rA
/*7964*/    OPC_RecordChild1, // #1 = $rB
/*7965*/    OPC_SwitchType /*2 cases */, 9,  MVT::i32,// ->7977
/*7968*/      OPC_MorphNodeTo, TARGET_VAL(PPC::DIVWU), 0,
                  1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1, 
              // Src: (udiv:i32 i32:i32:$rA, i32:i32:$rB) - Complexity = 3
              // Dst: (DIVWU:i32 i32:i32:$rA, i32:i32:$rB)
/*7977*/    /*SwitchType*/ 9,  MVT::i64,// ->7988
/*7979*/      OPC_MorphNodeTo, TARGET_VAL(PPC::DIVDU), 0,
                  1/*#VTs*/, MVT::i64, 2/*#Ops*/, 0, 1, 
              // Src: (udiv:i64 i64:i64:$rA, i64:i64:$rB) - Complexity = 3
              // Dst: (DIVDU:i64 i64:i64:$rA, i64:i64:$rB)
/*7988*/    0, // EndSwitchType
/*7989*/  /*SwitchOpcode*/ 26,  TARGET_VAL(ISD::MULHS),// ->8018
/*7992*/    OPC_RecordChild0, // #0 = $rA
/*7993*/    OPC_RecordChild1, // #1 = $rB
/*7994*/    OPC_SwitchType /*2 cases */, 9,  MVT::i32,// ->8006
/*7997*/      OPC_MorphNodeTo, TARGET_VAL(PPC::MULHW), 0,
                  1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1, 
              // Src: (mulhs:i32 i32:i32:$rA, i32:i32:$rB) - Complexity = 3
              // Dst: (MULHW:i32 i32:i32:$rA, i32:i32:$rB)
/*8006*/    /*SwitchType*/ 9,  MVT::i64,// ->8017
/*8008*/      OPC_MorphNodeTo, TARGET_VAL(PPC::MULHD), 0,
                  1/*#VTs*/, MVT::i64, 2/*#Ops*/, 0, 1, 
              // Src: (mulhs:i64 i64:i64:$rA, i64:i64:$rB) - Complexity = 3
              // Dst: (MULHD:i64 i64:i64:$rA, i64:i64:$rB)
/*8017*/    0, // EndSwitchType
/*8018*/  /*SwitchOpcode*/ 26,  TARGET_VAL(ISD::MULHU),// ->8047
/*8021*/    OPC_RecordChild0, // #0 = $rA
/*8022*/    OPC_RecordChild1, // #1 = $rB
/*8023*/    OPC_SwitchType /*2 cases */, 9,  MVT::i32,// ->8035
/*8026*/      OPC_MorphNodeTo, TARGET_VAL(PPC::MULHWU), 0,
                  1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1, 
              // Src: (mulhu:i32 i32:i32:$rA, i32:i32:$rB) - Complexity = 3
              // Dst: (MULHWU:i32 i32:i32:$rA, i32:i32:$rB)
/*8035*/    /*SwitchType*/ 9,  MVT::i64,// ->8046
/*8037*/      OPC_MorphNodeTo, TARGET_VAL(PPC::MULHDU), 0,
                  1/*#VTs*/, MVT::i64, 2/*#Ops*/, 0, 1, 
              // Src: (mulhu:i64 i64:i64:$rA, i64:i64:$rB) - Complexity = 3
              // Dst: (MULHDU:i64 i64:i64:$rA, i64:i64:$rB)
/*8046*/    0, // EndSwitchType
/*8047*/  /*SwitchOpcode*/ 11,  TARGET_VAL(ISD::READCYCLECOUNTER),// ->8061
/*8050*/    OPC_RecordNode,   // #0 = 'readcyclecounter' chained node
/*8051*/    OPC_CheckType, MVT::i64,
/*8053*/    OPC_EmitMergeInputChains1_0,
/*8054*/    OPC_MorphNodeTo, TARGET_VAL(PPC::MFTB8), 0|OPFL_Chain,
                1/*#VTs*/, MVT::i64, 0/*#Ops*/, 
            // Src: (readcyclecounter:i64) - Complexity = 3
            // Dst: (MFTB8:i64)
/*8061*/  /*SwitchOpcode*/ 13,  TARGET_VAL(ISD::SIGN_EXTEND),// ->8077
/*8064*/    OPC_RecordChild0, // #0 = $rS
/*8065*/    OPC_CheckChild0Type, MVT::i32,
/*8067*/    OPC_CheckType, MVT::i64,
/*8069*/    OPC_MorphNodeTo, TARGET_VAL(PPC::EXTSW_32_64), 0,
                1/*#VTs*/, MVT::i64, 1/*#Ops*/, 0, 
            // Src: (sext:i64 i32:i32:$rS) - Complexity = 3
            // Dst: (EXTSW_32_64:i64 i32:i32:$rS)
/*8077*/  /*SwitchOpcode*/ 23,  TARGET_VAL(ISD::CTPOP),// ->8103
/*8080*/    OPC_RecordChild0, // #0 = $rS
/*8081*/    OPC_SwitchType /*2 cases */, 8,  MVT::i64,// ->8092
/*8084*/      OPC_MorphNodeTo, TARGET_VAL(PPC::POPCNTD), 0,
                  1/*#VTs*/, MVT::i64, 1/*#Ops*/, 0, 
              // Src: (ctpop:i64 i64:i64:$rS) - Complexity = 3
              // Dst: (POPCNTD:i64 i64:i64:$rS)
/*8092*/    /*SwitchType*/ 8,  MVT::i32,// ->8102
/*8094*/      OPC_MorphNodeTo, TARGET_VAL(PPC::POPCNTW), 0,
                  1/*#VTs*/, MVT::i32, 1/*#Ops*/, 0, 
              // Src: (ctpop:i32 i32:i32:$rS) - Complexity = 3
              // Dst: (POPCNTW:i32 i32:i32:$rS)
/*8102*/    0, // EndSwitchType
/*8103*/  /*SwitchOpcode*/ 13,  TARGET_VAL(PPCISD::LOAD_TOC),// ->8119
/*8106*/    OPC_RecordNode,   // #0 = 'PPCload_toc' chained node
/*8107*/    OPC_CaptureGlueInput,
/*8108*/    OPC_RecordChild1, // #1 = $reg
/*8109*/    OPC_CheckChild1Type, MVT::i64,
/*8111*/    OPC_EmitMergeInputChains1_0,
/*8112*/    OPC_MorphNodeTo, TARGET_VAL(PPC::LDinto_toc), 0|OPFL_Chain|OPFL_GlueInput|OPFL_GlueOutput,
                0/*#VTs*/, 1/*#Ops*/, 1, 
            // Src: (PPCload_toc i64:i64:$reg) - Complexity = 3
            // Dst: (LDinto_toc i64:i64:$reg)
/*8119*/  /*SwitchOpcode*/ 9,  TARGET_VAL(PPCISD::TOC_RESTORE),// ->8131
/*8122*/    OPC_RecordNode,   // #0 = 'PPCtoc_restore' chained node
/*8123*/    OPC_CaptureGlueInput,
/*8124*/    OPC_EmitMergeInputChains1_0,
/*8125*/    OPC_MorphNodeTo, TARGET_VAL(PPC::LDtoc_restore), 0|OPFL_Chain|OPFL_GlueInput|OPFL_GlueOutput,
                0/*#VTs*/, 0/*#Ops*/, 
            // Src: (PPCtoc_restore) - Complexity = 3
            // Dst: (LDtoc_restore)
/*8131*/  /*SwitchOpcode*/ 15,  TARGET_VAL(ISD::TRUNCATE),// ->8149
/*8134*/    OPC_RecordChild0, // #0 = $in
/*8135*/    OPC_CheckType, MVT::i32,
/*8137*/    OPC_EmitInteger, MVT::i32, PPC::sub_32,
/*8140*/    OPC_MorphNodeTo, TARGET_VAL(TargetOpcode::EXTRACT_SUBREG), 0,
                1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1, 
            // Src: (trunc:i32 i64:i64:$in) - Complexity = 3
            // Dst: (EXTRACT_SUBREG:i32 ?:i64:$in, sub_32:i32)
/*8149*/  /*SwitchOpcode*/ 25,  TARGET_VAL(ISD::ANY_EXTEND),// ->8177
/*8152*/    OPC_RecordChild0, // #0 = $in
/*8153*/    OPC_CheckChild0Type, MVT::i32,
/*8155*/    OPC_CheckType, MVT::i64,
/*8157*/    OPC_EmitNode, TARGET_VAL(TargetOpcode::IMPLICIT_DEF), 0,
                1/*#VTs*/, MVT::i64, 0/*#Ops*/,  // Results = #1
/*8164*/    OPC_EmitInteger, MVT::i32, PPC::sub_32,
/*8167*/    OPC_MorphNodeTo, TARGET_VAL(TargetOpcode::INSERT_SUBREG), 0,
                1/*#VTs*/, MVT::i64, 3/*#Ops*/, 1, 0, 2, 
            // Src: (anyext:i64 i32:i32:$in) - Complexity = 3
            // Dst: (INSERT_SUBREG:i64 (IMPLICIT_DEF:i64), ?:i32:$in, sub_32:i32)
/*8177*/  /*SwitchOpcode*/ 41,  TARGET_VAL(ISD::ZERO_EXTEND),// ->8221
/*8180*/    OPC_RecordChild0, // #0 = $in
/*8181*/    OPC_CheckChild0Type, MVT::i32,
/*8183*/    OPC_CheckType, MVT::i64,
/*8185*/    OPC_EmitNode, TARGET_VAL(TargetOpcode::IMPLICIT_DEF), 0,
                1/*#VTs*/, MVT::i64, 0/*#Ops*/,  // Results = #1
/*8192*/    OPC_EmitInteger, MVT::i32, PPC::sub_32,
/*8195*/    OPC_EmitNode, TARGET_VAL(TargetOpcode::INSERT_SUBREG), 0,
                1/*#VTs*/, MVT::i64, 3/*#Ops*/, 1, 0, 2,  // Results = #3
/*8205*/    OPC_EmitInteger, MVT::i32, 0, 
/*8208*/    OPC_EmitInteger, MVT::i32, 32, 
/*8211*/    OPC_MorphNodeTo, TARGET_VAL(PPC::RLDICL), 0,
                1/*#VTs*/, MVT::i64, 3/*#Ops*/, 3, 4, 5, 
            // Src: (zext:i64 i32:i32:$in) - Complexity = 3
            // Dst: (RLDICL:i64 (INSERT_SUBREG:i64 (IMPLICIT_DEF:i64), ?:i32:$in, sub_32:i32), 0:i32, 32:i32)
/*8221*/  /*SwitchOpcode*/ 15,  TARGET_VAL(PPCISD::LFIWAX),// ->8239
/*8224*/    OPC_RecordNode,   // #0 = 'PPClfiwax' chained node
/*8225*/    OPC_RecordChild1, // #1 = $src
/*8226*/    OPC_CheckComplexPat, /*CP*/0, /*#*/1, // SelectAddrIdxOnly:$src #2 #3
/*8229*/    OPC_EmitMergeInputChains1_0,
/*8230*/    OPC_MorphNodeTo, TARGET_VAL(PPC::LFIWAX), 0|OPFL_Chain,
                1/*#VTs*/, MVT::f64, 2/*#Ops*/, 2, 3, 
            // Src: (PPClfiwax:f64 xoaddr:iPTR:$src) - Complexity = 12
            // Dst: (LFIWAX:f64 xoaddr:iPTR:$src)
/*8239*/  /*SwitchOpcode*/ 15,  TARGET_VAL(PPCISD::LFIWZX),// ->8257
/*8242*/    OPC_RecordNode,   // #0 = 'PPClfiwzx' chained node
/*8243*/    OPC_RecordChild1, // #1 = $src
/*8244*/    OPC_CheckComplexPat, /*CP*/0, /*#*/1, // SelectAddrIdxOnly:$src #2 #3
/*8247*/    OPC_EmitMergeInputChains1_0,
/*8248*/    OPC_MorphNodeTo, TARGET_VAL(PPC::LFIWZX), 0|OPFL_Chain,
                1/*#VTs*/, MVT::f64, 2/*#Ops*/, 2, 3, 
            // Src: (PPClfiwzx:f64 xoaddr:iPTR:$src) - Complexity = 12
            // Dst: (LFIWZX:f64 xoaddr:iPTR:$src)
/*8257*/  /*SwitchOpcode*/ 31|128,1/*159*/,  TARGET_VAL(ISD::FNEG),// ->8420
/*8261*/    OPC_Scope, 102, /*->8365*/ // 3 children in Scope
/*8263*/      OPC_MoveChild, 0,
/*8265*/      OPC_SwitchOpcode /*2 cases */, 68,  TARGET_VAL(ISD::FMA),// ->8337
/*8269*/        OPC_RecordChild0, // #0 = $FRA
/*8270*/        OPC_RecordChild1, // #1 = $FRC
/*8271*/        OPC_Scope, 34, /*->8307*/ // 2 children in Scope
/*8273*/          OPC_MoveChild, 2,
/*8275*/          OPC_CheckOpcode, TARGET_VAL(ISD::FNEG),
/*8278*/          OPC_RecordChild0, // #2 = $FRB
/*8279*/          OPC_MoveParent,
/*8280*/          OPC_MoveParent,
/*8281*/          OPC_SwitchType /*2 cases */, 10,  MVT::f64,// ->8294
/*8284*/            OPC_MorphNodeTo, TARGET_VAL(PPC::FNMSUB), 0,
                        1/*#VTs*/, MVT::f64, 3/*#Ops*/, 0, 1, 2, 
                    // Src: (fneg:f64 (fma:f64 f64:f64:$FRA, f64:f64:$FRC, (fneg:f64 f64:f64:$FRB))) - Complexity = 9
                    // Dst: (FNMSUB:f64 f64:f64:$FRA, f64:f64:$FRC, f64:f64:$FRB)
/*8294*/          /*SwitchType*/ 10,  MVT::f32,// ->8306
/*8296*/            OPC_MorphNodeTo, TARGET_VAL(PPC::FNMSUBS), 0,
                        1/*#VTs*/, MVT::f32, 3/*#Ops*/, 0, 1, 2, 
                    // Src: (fneg:f32 (fma:f32 f32:f32:$FRA, f32:f32:$FRC, (fneg:f32 f32:f32:$FRB))) - Complexity = 9
                    // Dst: (FNMSUBS:f32 f32:f32:$FRA, f32:f32:$FRC, f32:f32:$FRB)
/*8306*/          0, // EndSwitchType
/*8307*/        /*Scope*/ 28, /*->8336*/
/*8308*/          OPC_RecordChild2, // #2 = $FRB
/*8309*/          OPC_MoveParent,
/*8310*/          OPC_SwitchType /*2 cases */, 10,  MVT::f64,// ->8323
/*8313*/            OPC_MorphNodeTo, TARGET_VAL(PPC::FNMADD), 0,
                        1/*#VTs*/, MVT::f64, 3/*#Ops*/, 0, 1, 2, 
                    // Src: (fneg:f64 (fma:f64 f64:f64:$FRA, f64:f64:$FRC, f64:f64:$FRB)) - Complexity = 6
                    // Dst: (FNMADD:f64 f64:f64:$FRA, f64:f64:$FRC, f64:f64:$FRB)
/*8323*/          /*SwitchType*/ 10,  MVT::f32,// ->8335
/*8325*/            OPC_MorphNodeTo, TARGET_VAL(PPC::FNMADDS), 0,
                        1/*#VTs*/, MVT::f32, 3/*#Ops*/, 0, 1, 2, 
                    // Src: (fneg:f32 (fma:f32 f32:f32:$FRA, f32:f32:$FRC, f32:f32:$FRB)) - Complexity = 6
                    // Dst: (FNMADDS:f32 f32:f32:$FRA, f32:f32:$FRC, f32:f32:$FRB)
/*8335*/          0, // EndSwitchType
/*8336*/        0, /*End of Scope*/
/*8337*/      /*SwitchOpcode*/ 24,  TARGET_VAL(ISD::FABS),// ->8364
/*8340*/        OPC_RecordChild0, // #0 = $frB
/*8341*/        OPC_MoveParent,
/*8342*/        OPC_SwitchType /*2 cases */, 8,  MVT::f32,// ->8353
/*8345*/          OPC_MorphNodeTo, TARGET_VAL(PPC::FNABSS), 0,
                      1/*#VTs*/, MVT::f32, 1/*#Ops*/, 0, 
                  // Src: (fneg:f32 (fabs:f32 f32:f32:$frB)) - Complexity = 6
                  // Dst: (FNABSS:f32 f32:f32:$frB)
/*8353*/        /*SwitchType*/ 8,  MVT::f64,// ->8363
/*8355*/          OPC_MorphNodeTo, TARGET_VAL(PPC::FNABSD), 0,
                      1/*#VTs*/, MVT::f64, 1/*#Ops*/, 0, 
                  // Src: (fneg:f64 (fabs:f64 f64:f64:$frB)) - Complexity = 6
                  // Dst: (FNABSD:f64 f64:f64:$frB)
/*8363*/        0, // EndSwitchType
/*8364*/      0, // EndSwitchOpcode
/*8365*/    /*Scope*/ 23, /*->8389*/
/*8366*/      OPC_RecordChild0, // #0 = $frB
/*8367*/      OPC_SwitchType /*2 cases */, 8,  MVT::f32,// ->8378
/*8370*/        OPC_MorphNodeTo, TARGET_VAL(PPC::FNEGS), 0,
                    1/*#VTs*/, MVT::f32, 1/*#Ops*/, 0, 
                // Src: (fneg:f32 f32:f32:$frB) - Complexity = 3
                // Dst: (FNEGS:f32 f32:f32:$frB)
/*8378*/      /*SwitchType*/ 8,  MVT::f64,// ->8388
/*8380*/        OPC_MorphNodeTo, TARGET_VAL(PPC::FNEGD), 0,
                    1/*#VTs*/, MVT::f64, 1/*#Ops*/, 0, 
                // Src: (fneg:f64 f64:f64:$frB) - Complexity = 3
                // Dst: (FNEGD:f64 f64:f64:$frB)
/*8388*/      0, // EndSwitchType
/*8389*/    /*Scope*/ 29, /*->8419*/
/*8390*/      OPC_MoveChild, 0,
/*8392*/      OPC_CheckOpcode, TARGET_VAL(ISD::FMA),
/*8395*/      OPC_RecordChild0, // #0 = $vA
/*8396*/      OPC_RecordChild1, // #1 = $vC
/*8397*/      OPC_MoveChild, 2,
/*8399*/      OPC_CheckOpcode, TARGET_VAL(ISD::FNEG),
/*8402*/      OPC_RecordChild0, // #2 = $vB
/*8403*/      OPC_MoveParent,
/*8404*/      OPC_MoveParent,
/*8405*/      OPC_CheckType, MVT::v4f32,
/*8407*/      OPC_CheckPatternPredicate, 0, // (PPCSubTarget.hasAltivec())
/*8409*/      OPC_MorphNodeTo, TARGET_VAL(PPC::VNMSUBFP), 0,
                  1/*#VTs*/, MVT::v4f32, 3/*#Ops*/, 0, 1, 2, 
              // Src: (fneg:v4f32 (fma:v4f32 v4f32:v4f32:$vA, v4f32:v4f32:$vC, (fneg:v4f32 v4f32:v4f32:$vB))) - Complexity = 9
              // Dst: (VNMSUBFP:v4f32 v4f32:v4f32:$vA, v4f32:v4f32:$vC, v4f32:v4f32:$vB)
/*8419*/    0, /*End of Scope*/
/*8420*/  /*SwitchOpcode*/ 44|128,1/*172*/,  TARGET_VAL(ISD::FMA),// ->8596
/*8424*/    OPC_Scope, 35, /*->8461*/ // 5 children in Scope
/*8426*/      OPC_RecordChild0, // #0 = $FRA
/*8427*/      OPC_RecordChild1, // #1 = $FRC
/*8428*/      OPC_MoveChild, 2,
/*8430*/      OPC_CheckOpcode, TARGET_VAL(ISD::FNEG),
/*8433*/      OPC_RecordChild0, // #2 = $FRB
/*8434*/      OPC_MoveParent,
/*8435*/      OPC_SwitchType /*2 cases */, 10,  MVT::f64,// ->8448
/*8438*/        OPC_MorphNodeTo, TARGET_VAL(PPC::FMSUB), 0,
                    1/*#VTs*/, MVT::f64, 3/*#Ops*/, 0, 1, 2, 
                // Src: (fma:f64 f64:f64:$FRA, f64:f64:$FRC, (fneg:f64 f64:f64:$FRB)) - Complexity = 6
                // Dst: (FMSUB:f64 f64:f64:$FRA, f64:f64:$FRC, f64:f64:$FRB)
/*8448*/      /*SwitchType*/ 10,  MVT::f32,// ->8460
/*8450*/        OPC_MorphNodeTo, TARGET_VAL(PPC::FMSUBS), 0,
                    1/*#VTs*/, MVT::f32, 3/*#Ops*/, 0, 1, 2, 
                // Src: (fma:f32 f32:f32:$FRA, f32:f32:$FRC, (fneg:f32 f32:f32:$FRB)) - Complexity = 6
                // Dst: (FMSUBS:f32 f32:f32:$FRA, f32:f32:$FRC, f32:f32:$FRB)
/*8460*/      0, // EndSwitchType
/*8461*/    /*Scope*/ 21, /*->8483*/
/*8462*/      OPC_MoveChild, 0,
/*8464*/      OPC_CheckOpcode, TARGET_VAL(ISD::FNEG),
/*8467*/      OPC_RecordChild0, // #0 = $A
/*8468*/      OPC_MoveParent,
/*8469*/      OPC_RecordChild1, // #1 = $C
/*8470*/      OPC_RecordChild2, // #2 = $B
/*8471*/      OPC_CheckType, MVT::f64,
/*8473*/      OPC_MorphNodeTo, TARGET_VAL(PPC::FNMSUB), 0,
                  1/*#VTs*/, MVT::f64, 3/*#Ops*/, 0, 1, 2, 
              // Src: (fma:f64 (fneg:f64 f64:f64:$A), f64:f64:$C, f64:f64:$B) - Complexity = 6
              // Dst: (FNMSUB:f64 ?:f64:$A, ?:f64:$C, ?:f64:$B)
/*8483*/    /*Scope*/ 21, /*->8505*/
/*8484*/      OPC_RecordChild0, // #0 = $A
/*8485*/      OPC_MoveChild, 1,
/*8487*/      OPC_CheckOpcode, TARGET_VAL(ISD::FNEG),
/*8490*/      OPC_RecordChild0, // #1 = $C
/*8491*/      OPC_MoveParent,
/*8492*/      OPC_RecordChild2, // #2 = $B
/*8493*/      OPC_CheckType, MVT::f64,
/*8495*/      OPC_MorphNodeTo, TARGET_VAL(PPC::FNMSUB), 0,
                  1/*#VTs*/, MVT::f64, 3/*#Ops*/, 0, 1, 2, 
              // Src: (fma:f64 f64:f64:$A, (fneg:f64 f64:f64:$C), f64:f64:$B) - Complexity = 6
              // Dst: (FNMSUB:f64 ?:f64:$A, ?:f64:$C, ?:f64:$B)
/*8505*/    /*Scope*/ 21, /*->8527*/
/*8506*/      OPC_MoveChild, 0,
/*8508*/      OPC_CheckOpcode, TARGET_VAL(ISD::FNEG),
/*8511*/      OPC_RecordChild0, // #0 = $A
/*8512*/      OPC_MoveParent,
/*8513*/      OPC_RecordChild1, // #1 = $C
/*8514*/      OPC_RecordChild2, // #2 = $B
/*8515*/      OPC_CheckType, MVT::f32,
/*8517*/      OPC_MorphNodeTo, TARGET_VAL(PPC::FNMSUBS), 0,
                  1/*#VTs*/, MVT::f32, 3/*#Ops*/, 0, 1, 2, 
              // Src: (fma:f32 (fneg:f32 f32:f32:$A), f32:f32:$C, f32:f32:$B) - Complexity = 6
              // Dst: (FNMSUBS:f32 ?:f32:$A, ?:f32:$C, ?:f32:$B)
/*8527*/    /*Scope*/ 67, /*->8595*/
/*8528*/      OPC_RecordChild0, // #0 = $A
/*8529*/      OPC_Scope, 20, /*->8551*/ // 2 children in Scope
/*8531*/        OPC_MoveChild, 1,
/*8533*/        OPC_CheckOpcode, TARGET_VAL(ISD::FNEG),
/*8536*/        OPC_RecordChild0, // #1 = $C
/*8537*/        OPC_MoveParent,
/*8538*/        OPC_RecordChild2, // #2 = $B
/*8539*/        OPC_CheckType, MVT::f32,
/*8541*/        OPC_MorphNodeTo, TARGET_VAL(PPC::FNMSUBS), 0,
                    1/*#VTs*/, MVT::f32, 3/*#Ops*/, 0, 1, 2, 
                // Src: (fma:f32 f32:f32:$A, (fneg:f32 f32:f32:$C), f32:f32:$B) - Complexity = 6
                // Dst: (FNMSUBS:f32 ?:f32:$A, ?:f32:$C, ?:f32:$B)
/*8551*/      /*Scope*/ 42, /*->8594*/
/*8552*/        OPC_RecordChild1, // #1 = $FRC
/*8553*/        OPC_RecordChild2, // #2 = $FRB
/*8554*/        OPC_SwitchType /*3 cases */, 10,  MVT::f64,// ->8567
/*8557*/          OPC_MorphNodeTo, TARGET_VAL(PPC::FMADD), 0,
                      1/*#VTs*/, MVT::f64, 3/*#Ops*/, 0, 1, 2, 
                  // Src: (fma:f64 f64:f64:$FRA, f64:f64:$FRC, f64:f64:$FRB) - Complexity = 3
                  // Dst: (FMADD:f64 f64:f64:$FRA, f64:f64:$FRC, f64:f64:$FRB)
/*8567*/        /*SwitchType*/ 10,  MVT::f32,// ->8579
/*8569*/          OPC_MorphNodeTo, TARGET_VAL(PPC::FMADDS), 0,
                      1/*#VTs*/, MVT::f32, 3/*#Ops*/, 0, 1, 2, 
                  // Src: (fma:f32 f32:f32:$FRA, f32:f32:$FRC, f32:f32:$FRB) - Complexity = 3
                  // Dst: (FMADDS:f32 f32:f32:$FRA, f32:f32:$FRC, f32:f32:$FRB)
/*8579*/        /*SwitchType*/ 12,  MVT::v4f32,// ->8593
/*8581*/          OPC_CheckPatternPredicate, 0, // (PPCSubTarget.hasAltivec())
/*8583*/          OPC_MorphNodeTo, TARGET_VAL(PPC::VMADDFP), 0,
                      1/*#VTs*/, MVT::v4f32, 3/*#Ops*/, 0, 1, 2, 
                  // Src: (fma:v4f32 v4f32:v4f32:$vA, v4f32:v4f32:$vC, v4f32:v4f32:$vB) - Complexity = 3
                  // Dst: (VMADDFP:v4f32 v4f32:v4f32:$vA, v4f32:v4f32:$vC, v4f32:v4f32:$vB)
/*8593*/        0, // EndSwitchType
/*8594*/      0, /*End of Scope*/
/*8595*/    0, /*End of Scope*/
/*8596*/  /*SwitchOpcode*/ 11,  TARGET_VAL(PPCISD::FCTIWZ),// ->8610
/*8599*/    OPC_RecordChild0, // #0 = $frB
/*8600*/    OPC_CheckType, MVT::f64,
/*8602*/    OPC_MorphNodeTo, TARGET_VAL(PPC::FCTIWZ), 0,
                1/*#VTs*/, MVT::f64, 1/*#Ops*/, 0, 
            // Src: (PPCfctiwz:f64 f64:f64:$frB) - Complexity = 3
            // Dst: (FCTIWZ:f64 f64:f64:$frB)
/*8610*/  /*SwitchOpcode*/ 9,  TARGET_VAL(ISD::FP_ROUND),// ->8622
/*8613*/    OPC_RecordChild0, // #0 = $frB
/*8614*/    OPC_MorphNodeTo, TARGET_VAL(PPC::FRSP), 0,
                1/*#VTs*/, MVT::f32, 1/*#Ops*/, 0, 
            // Src: (fround:f32 f64:f64:$frB) - Complexity = 3
            // Dst: (FRSP:f32 f64:f64:$frB)
/*8622*/  /*SwitchOpcode*/ 23,  TARGET_VAL(ISD::FROUND),// ->8648
/*8625*/    OPC_RecordChild0, // #0 = $frB
/*8626*/    OPC_SwitchType /*2 cases */, 8,  MVT::f64,// ->8637
/*8629*/      OPC_MorphNodeTo, TARGET_VAL(PPC::FRIND), 0,
                  1/*#VTs*/, MVT::f64, 1/*#Ops*/, 0, 
              // Src: (frnd:f64 f64:f64:$frB) - Complexity = 3
              // Dst: (FRIND:f64 f64:f64:$frB)
/*8637*/    /*SwitchType*/ 8,  MVT::f32,// ->8647
/*8639*/      OPC_MorphNodeTo, TARGET_VAL(PPC::FRINS), 0,
                  1/*#VTs*/, MVT::f32, 1/*#Ops*/, 0, 
              // Src: (frnd:f32 f32:f32:$frB) - Complexity = 3
              // Dst: (FRINS:f32 f32:f32:$frB)
/*8647*/    0, // EndSwitchType
/*8648*/  /*SwitchOpcode*/ 35,  TARGET_VAL(ISD::FCEIL),// ->8686
/*8651*/    OPC_RecordChild0, // #0 = $frB
/*8652*/    OPC_SwitchType /*3 cases */, 8,  MVT::f64,// ->8663
/*8655*/      OPC_MorphNodeTo, TARGET_VAL(PPC::FRIPD), 0,
                  1/*#VTs*/, MVT::f64, 1/*#Ops*/, 0, 
              // Src: (fceil:f64 f64:f64:$frB) - Complexity = 3
              // Dst: (FRIPD:f64 f64:f64:$frB)
/*8663*/    /*SwitchType*/ 8,  MVT::f32,// ->8673
/*8665*/      OPC_MorphNodeTo, TARGET_VAL(PPC::FRIPS), 0,
                  1/*#VTs*/, MVT::f32, 1/*#Ops*/, 0, 
              // Src: (fceil:f32 f32:f32:$frB) - Complexity = 3
              // Dst: (FRIPS:f32 f32:f32:$frB)
/*8673*/    /*SwitchType*/ 10,  MVT::v4f32,// ->8685
/*8675*/      OPC_CheckPatternPredicate, 0, // (PPCSubTarget.hasAltivec())
/*8677*/      OPC_MorphNodeTo, TARGET_VAL(PPC::VRFIP), 0,
                  1/*#VTs*/, MVT::v4f32, 1/*#Ops*/, 0, 
              // Src: (fceil:v4f32 v4f32:v4f32:$vA) - Complexity = 3
              // Dst: (VRFIP:v4f32 ?:v4f32:$vA)
/*8685*/    0, // EndSwitchType
/*8686*/  /*SwitchOpcode*/ 35,  TARGET_VAL(ISD::FTRUNC),// ->8724
/*8689*/    OPC_RecordChild0, // #0 = $frB
/*8690*/    OPC_SwitchType /*3 cases */, 8,  MVT::f64,// ->8701
/*8693*/      OPC_MorphNodeTo, TARGET_VAL(PPC::FRIZD), 0,
                  1/*#VTs*/, MVT::f64, 1/*#Ops*/, 0, 
              // Src: (ftrunc:f64 f64:f64:$frB) - Complexity = 3
              // Dst: (FRIZD:f64 f64:f64:$frB)
/*8701*/    /*SwitchType*/ 8,  MVT::f32,// ->8711
/*8703*/      OPC_MorphNodeTo, TARGET_VAL(PPC::FRIZS), 0,
                  1/*#VTs*/, MVT::f32, 1/*#Ops*/, 0, 
              // Src: (ftrunc:f32 f32:f32:$frB) - Complexity = 3
              // Dst: (FRIZS:f32 f32:f32:$frB)
/*8711*/    /*SwitchType*/ 10,  MVT::v4f32,// ->8723
/*8713*/      OPC_CheckPatternPredicate, 0, // (PPCSubTarget.hasAltivec())
/*8715*/      OPC_MorphNodeTo, TARGET_VAL(PPC::VRFIZ), 0,
                  1/*#VTs*/, MVT::v4f32, 1/*#Ops*/, 0, 
              // Src: (ftrunc:v4f32 v4f32:v4f32:$vA) - Complexity = 3
              // Dst: (VRFIZ:v4f32 ?:v4f32:$vA)
/*8723*/    0, // EndSwitchType
/*8724*/  /*SwitchOpcode*/ 35,  TARGET_VAL(ISD::FFLOOR),// ->8762
/*8727*/    OPC_RecordChild0, // #0 = $frB
/*8728*/    OPC_SwitchType /*3 cases */, 8,  MVT::f64,// ->8739
/*8731*/      OPC_MorphNodeTo, TARGET_VAL(PPC::FRIMD), 0,
                  1/*#VTs*/, MVT::f64, 1/*#Ops*/, 0, 
              // Src: (ffloor:f64 f64:f64:$frB) - Complexity = 3
              // Dst: (FRIMD:f64 f64:f64:$frB)
/*8739*/    /*SwitchType*/ 8,  MVT::f32,// ->8749
/*8741*/      OPC_MorphNodeTo, TARGET_VAL(PPC::FRIMS), 0,
                  1/*#VTs*/, MVT::f32, 1/*#Ops*/, 0, 
              // Src: (ffloor:f32 f32:f32:$frB) - Complexity = 3
              // Dst: (FRIMS:f32 f32:f32:$frB)
/*8749*/    /*SwitchType*/ 10,  MVT::v4f32,// ->8761
/*8751*/      OPC_CheckPatternPredicate, 0, // (PPCSubTarget.hasAltivec())
/*8753*/      OPC_MorphNodeTo, TARGET_VAL(PPC::VRFIM), 0,
                  1/*#VTs*/, MVT::v4f32, 1/*#Ops*/, 0, 
              // Src: (ffloor:v4f32 v4f32:v4f32:$vA) - Complexity = 3
              // Dst: (VRFIM:v4f32 ?:v4f32:$vA)
/*8761*/    0, // EndSwitchType
/*8762*/  /*SwitchOpcode*/ 23,  TARGET_VAL(ISD::FSQRT),// ->8788
/*8765*/    OPC_RecordChild0, // #0 = $frB
/*8766*/    OPC_SwitchType /*2 cases */, 8,  MVT::f64,// ->8777
/*8769*/      OPC_MorphNodeTo, TARGET_VAL(PPC::FSQRT), 0,
                  1/*#VTs*/, MVT::f64, 1/*#Ops*/, 0, 
              // Src: (fsqrt:f64 f64:f64:$frB) - Complexity = 3
              // Dst: (FSQRT:f64 f64:f64:$frB)
/*8777*/    /*SwitchType*/ 8,  MVT::f32,// ->8787
/*8779*/      OPC_MorphNodeTo, TARGET_VAL(PPC::FSQRTS), 0,
                  1/*#VTs*/, MVT::f32, 1/*#Ops*/, 0, 
              // Src: (fsqrt:f32 f32:f32:$frB) - Complexity = 3
              // Dst: (FSQRTS:f32 f32:f32:$frB)
/*8787*/    0, // EndSwitchType
/*8788*/  /*SwitchOpcode*/ 23,  TARGET_VAL(ISD::FABS),// ->8814
/*8791*/    OPC_RecordChild0, // #0 = $frB
/*8792*/    OPC_SwitchType /*2 cases */, 8,  MVT::f32,// ->8803
/*8795*/      OPC_MorphNodeTo, TARGET_VAL(PPC::FABSS), 0,
                  1/*#VTs*/, MVT::f32, 1/*#Ops*/, 0, 
              // Src: (fabs:f32 f32:f32:$frB) - Complexity = 3
              // Dst: (FABSS:f32 f32:f32:$frB)
/*8803*/    /*SwitchType*/ 8,  MVT::f64,// ->8813
/*8805*/      OPC_MorphNodeTo, TARGET_VAL(PPC::FABSD), 0,
                  1/*#VTs*/, MVT::f64, 1/*#Ops*/, 0, 
              // Src: (fabs:f64 f64:f64:$frB) - Complexity = 3
              // Dst: (FABSD:f64 f64:f64:$frB)
/*8813*/    0, // EndSwitchType
/*8814*/  /*SwitchOpcode*/ 82,  TARGET_VAL(ISD::FCOPYSIGN),// ->8899
/*8817*/    OPC_RecordChild0, // #0 = $frB
/*8818*/    OPC_RecordChild1, // #1 = $frA
/*8819*/    OPC_Scope, 38, /*->8859*/ // 2 children in Scope
/*8821*/      OPC_CheckChild1Type, MVT::f32,
/*8823*/      OPC_SwitchType /*2 cases */, 9,  MVT::f32,// ->8835
/*8826*/        OPC_MorphNodeTo, TARGET_VAL(PPC::FCPSGNS), 0,
                    1/*#VTs*/, MVT::f32, 2/*#Ops*/, 1, 0, 
                // Src: (fcopysign:f32 f32:f32:$frB, f32:f32:$frA) - Complexity = 3
                // Dst: (FCPSGNS:f32 f32:f32:$frA, f32:f32:$frB)
/*8835*/      /*SwitchType*/ 21,  MVT::f64,// ->8858
/*8837*/        OPC_EmitInteger, MVT::i32, PPC::F8RCRegClassID,
/*8840*/        OPC_EmitNode, TARGET_VAL(TargetOpcode::COPY_TO_REGCLASS), 0,
                    1/*#VTs*/, MVT::f64, 2/*#Ops*/, 1, 2,  // Results = #3
/*8849*/        OPC_MorphNodeTo, TARGET_VAL(PPC::FCPSGND), 0,
                    1/*#VTs*/, MVT::f64, 2/*#Ops*/, 3, 0, 
                // Src: (fcopysign:f64 f64:f64:$frB, f32:f32:$frA) - Complexity = 3
                // Dst: (FCPSGND:f64 (COPY_TO_REGCLASS:f64 ?:f32:$frA, F8RC:i32), ?:f64:$frB)
/*8858*/      0, // EndSwitchType
/*8859*/    /*Scope*/ 38, /*->8898*/
/*8860*/      OPC_CheckChild1Type, MVT::f64,
/*8862*/      OPC_SwitchType /*2 cases */, 9,  MVT::f64,// ->8874
/*8865*/        OPC_MorphNodeTo, TARGET_VAL(PPC::FCPSGND), 0,
                    1/*#VTs*/, MVT::f64, 2/*#Ops*/, 1, 0, 
                // Src: (fcopysign:f64 f64:f64:$frB, f64:f64:$frA) - Complexity = 3
                // Dst: (FCPSGND:f64 f64:f64:$frA, f64:f64:$frB)
/*8874*/      /*SwitchType*/ 21,  MVT::f32,// ->8897
/*8876*/        OPC_EmitInteger, MVT::i32, PPC::F4RCRegClassID,
/*8879*/        OPC_EmitNode, TARGET_VAL(TargetOpcode::COPY_TO_REGCLASS), 0,
                    1/*#VTs*/, MVT::f32, 2/*#Ops*/, 1, 2,  // Results = #3
/*8888*/        OPC_MorphNodeTo, TARGET_VAL(PPC::FCPSGNS), 0,
                    1/*#VTs*/, MVT::f32, 2/*#Ops*/, 3, 0, 
                // Src: (fcopysign:f32 f32:f32:$frB, f64:f64:$frA) - Complexity = 3
                // Dst: (FCPSGNS:f32 (COPY_TO_REGCLASS:f32 ?:f64:$frA, F4RC:i32), ?:f32:$frB)
/*8897*/      0, // EndSwitchType
/*8898*/    0, /*End of Scope*/
/*8899*/  /*SwitchOpcode*/ 35,  TARGET_VAL(PPCISD::FRE),// ->8937
/*8902*/    OPC_RecordChild0, // #0 = $frB
/*8903*/    OPC_SwitchType /*3 cases */, 8,  MVT::f64,// ->8914
/*8906*/      OPC_MorphNodeTo, TARGET_VAL(PPC::FRE), 0,
                  1/*#VTs*/, MVT::f64, 1/*#Ops*/, 0, 
              // Src: (PPCfre:f64 f64:f64:$frB) - Complexity = 3
              // Dst: (FRE:f64 f64:f64:$frB)
/*8914*/    /*SwitchType*/ 8,  MVT::f32,// ->8924
/*8916*/      OPC_MorphNodeTo, TARGET_VAL(PPC::FRES), 0,
                  1/*#VTs*/, MVT::f32, 1/*#Ops*/, 0, 
              // Src: (PPCfre:f32 f32:f32:$frB) - Complexity = 3
              // Dst: (FRES:f32 f32:f32:$frB)
/*8924*/    /*SwitchType*/ 10,  MVT::v4f32,// ->8936
/*8926*/      OPC_CheckPatternPredicate, 0, // (PPCSubTarget.hasAltivec())
/*8928*/      OPC_MorphNodeTo, TARGET_VAL(PPC::VREFP), 0,
                  1/*#VTs*/, MVT::v4f32, 1/*#Ops*/, 0, 
              // Src: (PPCfre:v4f32 v4f32:v4f32:$A) - Complexity = 3
              // Dst: (VREFP:v4f32 ?:v4f32:$A)
/*8936*/    0, // EndSwitchType
/*8937*/  /*SwitchOpcode*/ 35,  TARGET_VAL(PPCISD::FRSQRTE),// ->8975
/*8940*/    OPC_RecordChild0, // #0 = $frB
/*8941*/    OPC_SwitchType /*3 cases */, 8,  MVT::f64,// ->8952
/*8944*/      OPC_MorphNodeTo, TARGET_VAL(PPC::FRSQRTE), 0,
                  1/*#VTs*/, MVT::f64, 1/*#Ops*/, 0, 
              // Src: (PPCfrsqrte:f64 f64:f64:$frB) - Complexity = 3
              // Dst: (FRSQRTE:f64 f64:f64:$frB)
/*8952*/    /*SwitchType*/ 8,  MVT::f32,// ->8962
/*8954*/      OPC_MorphNodeTo, TARGET_VAL(PPC::FRSQRTES), 0,
                  1/*#VTs*/, MVT::f32, 1/*#Ops*/, 0, 
              // Src: (PPCfrsqrte:f32 f32:f32:$frB) - Complexity = 3
              // Dst: (FRSQRTES:f32 f32:f32:$frB)
/*8962*/    /*SwitchType*/ 10,  MVT::v4f32,// ->8974
/*8964*/      OPC_CheckPatternPredicate, 0, // (PPCSubTarget.hasAltivec())
/*8966*/      OPC_MorphNodeTo, TARGET_VAL(PPC::VRSQRTEFP), 0,
                  1/*#VTs*/, MVT::v4f32, 1/*#Ops*/, 0, 
              // Src: (PPCfrsqrte:v4f32 v4f32:v4f32:$A) - Complexity = 3
              // Dst: (VRSQRTEFP:v4f32 ?:v4f32:$A)
/*8974*/    0, // EndSwitchType
/*8975*/  /*SwitchOpcode*/ 7,  TARGET_VAL(PPCISD::MFFS),// ->8985
/*8978*/    OPC_MorphNodeTo, TARGET_VAL(PPC::MFFS), 0,
                1/*#VTs*/, MVT::f64, 0/*#Ops*/, 
            // Src: (PPCmffs:f64) - Complexity = 3
            // Dst: (MFFS:f64)
/*8985*/  /*SwitchOpcode*/ 29,  TARGET_VAL(PPCISD::FSEL),// ->9017
/*8988*/    OPC_RecordChild0, // #0 = $FRA
/*8989*/    OPC_RecordChild1, // #1 = $FRC
/*8990*/    OPC_RecordChild2, // #2 = $FRB
/*8991*/    OPC_SwitchType /*2 cases */, 10,  MVT::f64,// ->9004
/*8994*/      OPC_MorphNodeTo, TARGET_VAL(PPC::FSELD), 0,
                  1/*#VTs*/, MVT::f64, 3/*#Ops*/, 0, 1, 2, 
              // Src: (PPCfsel:f64 f64:f64:$FRA, f64:f64:$FRC, f64:f64:$FRB) - Complexity = 3
              // Dst: (FSELD:f64 f64:f64:$FRA, f64:f64:$FRC, f64:f64:$FRB)
/*9004*/    /*SwitchType*/ 10,  MVT::f32,// ->9016
/*9006*/      OPC_MorphNodeTo, TARGET_VAL(PPC::FSELS), 0,
                  1/*#VTs*/, MVT::f32, 3/*#Ops*/, 0, 1, 2, 
              // Src: (PPCfsel:f32 f64:f64:$FRA, f32:f32:$FRC, f32:f32:$FRB) - Complexity = 3
              // Dst: (FSELS:f32 f64:f64:$FRA, f32:f32:$FRC, f32:f32:$FRB)
/*9016*/    0, // EndSwitchType
/*9017*/  /*SwitchOpcode*/ 39,  TARGET_VAL(ISD::FADD),// ->9059
/*9020*/    OPC_RecordChild0, // #0 = $FRA
/*9021*/    OPC_RecordChild1, // #1 = $FRB
/*9022*/    OPC_SwitchType /*3 cases */, 9,  MVT::f64,// ->9034
/*9025*/      OPC_MorphNodeTo, TARGET_VAL(PPC::FADD), 0,
                  1/*#VTs*/, MVT::f64, 2/*#Ops*/, 0, 1, 
              // Src: (fadd:f64 f64:f64:$FRA, f64:f64:$FRB) - Complexity = 3
              // Dst: (FADD:f64 f64:f64:$FRA, f64:f64:$FRB)
/*9034*/    /*SwitchType*/ 9,  MVT::f32,// ->9045
/*9036*/      OPC_MorphNodeTo, TARGET_VAL(PPC::FADDS), 0,
                  1/*#VTs*/, MVT::f32, 2/*#Ops*/, 0, 1, 
              // Src: (fadd:f32 f32:f32:$FRA, f32:f32:$FRB) - Complexity = 3
              // Dst: (FADDS:f32 f32:f32:$FRA, f32:f32:$FRB)
/*9045*/    /*SwitchType*/ 11,  MVT::v4f32,// ->9058
/*9047*/      OPC_CheckPatternPredicate, 0, // (PPCSubTarget.hasAltivec())
/*9049*/      OPC_MorphNodeTo, TARGET_VAL(PPC::VADDFP), 0,
                  1/*#VTs*/, MVT::v4f32, 2/*#Ops*/, 0, 1, 
              // Src: (fadd:v4f32 v4f32:v4f32:$vA, v4f32:v4f32:$vB) - Complexity = 3
              // Dst: (VADDFP:v4f32 v4f32:v4f32:$vA, v4f32:v4f32:$vB)
/*9058*/    0, // EndSwitchType
/*9059*/  /*SwitchOpcode*/ 26,  TARGET_VAL(ISD::FDIV),// ->9088
/*9062*/    OPC_RecordChild0, // #0 = $FRA
/*9063*/    OPC_RecordChild1, // #1 = $FRB
/*9064*/    OPC_SwitchType /*2 cases */, 9,  MVT::f64,// ->9076
/*9067*/      OPC_MorphNodeTo, TARGET_VAL(PPC::FDIV), 0,
                  1/*#VTs*/, MVT::f64, 2/*#Ops*/, 0, 1, 
              // Src: (fdiv:f64 f64:f64:$FRA, f64:f64:$FRB) - Complexity = 3
              // Dst: (FDIV:f64 f64:f64:$FRA, f64:f64:$FRB)
/*9076*/    /*SwitchType*/ 9,  MVT::f32,// ->9087
/*9078*/      OPC_MorphNodeTo, TARGET_VAL(PPC::FDIVS), 0,
                  1/*#VTs*/, MVT::f32, 2/*#Ops*/, 0, 1, 
              // Src: (fdiv:f32 f32:f32:$FRA, f32:f32:$FRB) - Complexity = 3
              // Dst: (FDIVS:f32 f32:f32:$FRA, f32:f32:$FRB)
/*9087*/    0, // EndSwitchType
/*9088*/  /*SwitchOpcode*/ 63,  TARGET_VAL(ISD::FMUL),// ->9154
/*9091*/    OPC_RecordChild0, // #0 = $FRA
/*9092*/    OPC_RecordChild1, // #1 = $FRC
/*9093*/    OPC_SwitchType /*3 cases */, 9,  MVT::f64,// ->9105
/*9096*/      OPC_MorphNodeTo, TARGET_VAL(PPC::FMUL), 0,
                  1/*#VTs*/, MVT::f64, 2/*#Ops*/, 0, 1, 
              // Src: (fmul:f64 f64:f64:$FRA, f64:f64:$FRC) - Complexity = 3
              // Dst: (FMUL:f64 f64:f64:$FRA, f64:f64:$FRC)
/*9105*/    /*SwitchType*/ 9,  MVT::f32,// ->9116
/*9107*/      OPC_MorphNodeTo, TARGET_VAL(PPC::FMULS), 0,
                  1/*#VTs*/, MVT::f32, 2/*#Ops*/, 0, 1, 
              // Src: (fmul:f32 f32:f32:$FRA, f32:f32:$FRC) - Complexity = 3
              // Dst: (FMULS:f32 f32:f32:$FRA, f32:f32:$FRC)
/*9116*/    /*SwitchType*/ 35,  MVT::v4f32,// ->9153
/*9118*/      OPC_CheckPatternPredicate, 0, // (PPCSubTarget.hasAltivec())
/*9120*/      OPC_EmitNode, TARGET_VAL(PPC::V_SETALLONES), 0,
                  1/*#VTs*/, MVT::v16i8, 0/*#Ops*/,  // Results = #2
/*9127*/      OPC_EmitNode, TARGET_VAL(PPC::V_SETALLONES), 0,
                  1/*#VTs*/, MVT::v16i8, 0/*#Ops*/,  // Results = #3
/*9134*/      OPC_EmitNode, TARGET_VAL(PPC::VSLW), 0,
                  1/*#VTs*/, MVT::v4i32, 2/*#Ops*/, 2, 3,  // Results = #4
/*9143*/      OPC_MorphNodeTo, TARGET_VAL(PPC::VMADDFP), 0,
                  1/*#VTs*/, MVT::v4f32, 3/*#Ops*/, 0, 1, 4, 
              // Src: (fmul:v4f32 v4f32:v4f32:$vA, v4f32:v4f32:$vB) - Complexity = 3
              // Dst: (VMADDFP:v4f32 ?:v4f32:$vA, ?:v4f32:$vB, (VSLW:v4i32 (V_SETALLONES:v16i8), (V_SETALLONES:v16i8)))
/*9153*/    0, // EndSwitchType
/*9154*/  /*SwitchOpcode*/ 39,  TARGET_VAL(ISD::FSUB),// ->9196
/*9157*/    OPC_RecordChild0, // #0 = $FRA
/*9158*/    OPC_RecordChild1, // #1 = $FRB
/*9159*/    OPC_SwitchType /*3 cases */, 9,  MVT::f64,// ->9171
/*9162*/      OPC_MorphNodeTo, TARGET_VAL(PPC::FSUB), 0,
                  1/*#VTs*/, MVT::f64, 2/*#Ops*/, 0, 1, 
              // Src: (fsub:f64 f64:f64:$FRA, f64:f64:$FRB) - Complexity = 3
              // Dst: (FSUB:f64 f64:f64:$FRA, f64:f64:$FRB)
/*9171*/    /*SwitchType*/ 9,  MVT::f32,// ->9182
/*9173*/      OPC_MorphNodeTo, TARGET_VAL(PPC::FSUBS), 0,
                  1/*#VTs*/, MVT::f32, 2/*#Ops*/, 0, 1, 
              // Src: (fsub:f32 f32:f32:$FRA, f32:f32:$FRB) - Complexity = 3
              // Dst: (FSUBS:f32 f32:f32:$FRA, f32:f32:$FRB)
/*9182*/    /*SwitchType*/ 11,  MVT::v4f32,// ->9195
/*9184*/      OPC_CheckPatternPredicate, 0, // (PPCSubTarget.hasAltivec())
/*9186*/      OPC_MorphNodeTo, TARGET_VAL(PPC::VSUBFP), 0,
                  1/*#VTs*/, MVT::v4f32, 2/*#Ops*/, 0, 1, 
              // Src: (fsub:v4f32 v4f32:v4f32:$vA, v4f32:v4f32:$vB) - Complexity = 3
              // Dst: (VSUBFP:v4f32 v4f32:v4f32:$vA, v4f32:v4f32:$vB)
/*9195*/    0, // EndSwitchType
/*9196*/  /*SwitchOpcode*/ 13,  TARGET_VAL(ISD::FP_EXTEND),// ->9212
/*9199*/    OPC_RecordChild0, // #0 = $src
/*9200*/    OPC_EmitInteger, MVT::i32, PPC::F8RCRegClassID,
/*9203*/    OPC_MorphNodeTo, TARGET_VAL(TargetOpcode::COPY_TO_REGCLASS), 0,
                1/*#VTs*/, MVT::f64, 2/*#Ops*/, 0, 1, 
            // Src: (fextend:f64 f32:f32:$src) - Complexity = 3
            // Dst: (COPY_TO_REGCLASS:f64 ?:f32:$src, F8RC:i32)
/*9212*/  /*SwitchOpcode*/ 11,  TARGET_VAL(PPCISD::FCFID),// ->9226
/*9215*/    OPC_RecordChild0, // #0 = $frB
/*9216*/    OPC_CheckType, MVT::f64,
/*9218*/    OPC_MorphNodeTo, TARGET_VAL(PPC::FCFID), 0,
                1/*#VTs*/, MVT::f64, 1/*#Ops*/, 0, 
            // Src: (PPCfcfid:f64 f64:f64:$frB) - Complexity = 3
            // Dst: (FCFID:f64 f64:f64:$frB)
/*9226*/  /*SwitchOpcode*/ 11,  TARGET_VAL(PPCISD::FCTIDZ),// ->9240
/*9229*/    OPC_RecordChild0, // #0 = $frB
/*9230*/    OPC_CheckType, MVT::f64,
/*9232*/    OPC_MorphNodeTo, TARGET_VAL(PPC::FCTIDZ), 0,
                1/*#VTs*/, MVT::f64, 1/*#Ops*/, 0, 
            // Src: (PPCfctidz:f64 f64:f64:$frB) - Complexity = 3
            // Dst: (FCTIDZ:f64 f64:f64:$frB)
/*9240*/  /*SwitchOpcode*/ 11,  TARGET_VAL(PPCISD::FCFIDU),// ->9254
/*9243*/    OPC_RecordChild0, // #0 = $frB
/*9244*/    OPC_CheckType, MVT::f64,
/*9246*/    OPC_MorphNodeTo, TARGET_VAL(PPC::FCFIDU), 0,
                1/*#VTs*/, MVT::f64, 1/*#Ops*/, 0, 
            // Src: (PPCfcfidu:f64 f64:f64:$frB) - Complexity = 3
            // Dst: (FCFIDU:f64 f64:f64:$frB)
/*9254*/  /*SwitchOpcode*/ 9,  TARGET_VAL(PPCISD::FCFIDS),// ->9266
/*9257*/    OPC_RecordChild0, // #0 = $frB
/*9258*/    OPC_MorphNodeTo, TARGET_VAL(PPC::FCFIDS), 0,
                1/*#VTs*/, MVT::f32, 1/*#Ops*/, 0, 
            // Src: (PPCfcfids:f32 f64:f64:$frB) - Complexity = 3
            // Dst: (FCFIDS:f32 f64:f64:$frB)
/*9266*/  /*SwitchOpcode*/ 9,  TARGET_VAL(PPCISD::FCFIDUS),// ->9278
/*9269*/    OPC_RecordChild0, // #0 = $frB
/*9270*/    OPC_MorphNodeTo, TARGET_VAL(PPC::FCFIDUS), 0,
                1/*#VTs*/, MVT::f32, 1/*#Ops*/, 0, 
            // Src: (PPCfcfidus:f32 f64:f64:$frB) - Complexity = 3
            // Dst: (FCFIDUS:f32 f64:f64:$frB)
/*9278*/  /*SwitchOpcode*/ 11,  TARGET_VAL(PPCISD::FCTIDUZ),// ->9292
/*9281*/    OPC_RecordChild0, // #0 = $frB
/*9282*/    OPC_CheckType, MVT::f64,
/*9284*/    OPC_MorphNodeTo, TARGET_VAL(PPC::FCTIDUZ), 0,
                1/*#VTs*/, MVT::f64, 1/*#Ops*/, 0, 
            // Src: (PPCfctiduz:f64 f64:f64:$frB) - Complexity = 3
            // Dst: (FCTIDUZ:f64 f64:f64:$frB)
/*9292*/  /*SwitchOpcode*/ 11,  TARGET_VAL(PPCISD::FCTIWUZ),// ->9306
/*9295*/    OPC_RecordChild0, // #0 = $frB
/*9296*/    OPC_CheckType, MVT::f64,
/*9298*/    OPC_MorphNodeTo, TARGET_VAL(PPC::FCTIWUZ), 0,
                1/*#VTs*/, MVT::f64, 1/*#Ops*/, 0, 
            // Src: (PPCfctiwuz:f64 f64:f64:$frB) - Complexity = 3
            // Dst: (FCTIWUZ:f64 f64:f64:$frB)
/*9306*/  /*SwitchOpcode*/ 13,  TARGET_VAL(PPCISD::FADDRTZ),// ->9322
/*9309*/    OPC_RecordChild0, // #0 = $FRA
/*9310*/    OPC_RecordChild1, // #1 = $FRB
/*9311*/    OPC_CheckType, MVT::f64,
/*9313*/    OPC_MorphNodeTo, TARGET_VAL(PPC::FADDrtz), 0,
                1/*#VTs*/, MVT::f64, 2/*#Ops*/, 0, 1, 
            // Src: (PPCfaddrtz:f64 f64:f64:$FRA, f64:f64:$FRB) - Complexity = 3
            // Dst: (FADDrtz:f64 f64:f64:$FRA, f64:f64:$FRB)
/*9322*/  /*SwitchOpcode*/ 125,  TARGET_VAL(ISD::INTRINSIC_W_CHAIN),// ->9450
/*9325*/    OPC_RecordNode,   // #0 = 'intrinsic_w_chain' chained node
/*9326*/    OPC_MoveChild, 1,
/*9328*/    OPC_Scope, 20, /*->9350*/ // 6 children in Scope
/*9330*/      OPC_CheckInteger, 117|128,16/*2165*/, 
/*9333*/      OPC_MoveParent,
/*9334*/      OPC_RecordChild2, // #1 = $src
/*9335*/      OPC_CheckPatternPredicate, 0, // (PPCSubTarget.hasAltivec())
/*9337*/      OPC_CheckComplexPat, /*CP*/0, /*#*/1, // SelectAddrIdxOnly:$src #2 #3
/*9340*/      OPC_EmitMergeInputChains1_0,
/*9341*/      OPC_MorphNodeTo, TARGET_VAL(PPC::LVEBX), 0|OPFL_Chain,
                  1/*#VTs*/, MVT::v16i8, 2/*#Ops*/, 2, 3, 
              // Src: (intrinsic_w_chain:v16i8 2165:iPTR, xoaddr:iPTR:$src) - Complexity = 17
              // Dst: (LVEBX:v16i8 xoaddr:iPTR:$src)
/*9350*/    /*Scope*/ 20, /*->9371*/
/*9351*/      OPC_CheckInteger, 118|128,16/*2166*/, 
/*9354*/      OPC_MoveParent,
/*9355*/      OPC_RecordChild2, // #1 = $src
/*9356*/      OPC_CheckPatternPredicate, 0, // (PPCSubTarget.hasAltivec())
/*9358*/      OPC_CheckComplexPat, /*CP*/0, /*#*/1, // SelectAddrIdxOnly:$src #2 #3
/*9361*/      OPC_EmitMergeInputChains1_0,
/*9362*/      OPC_MorphNodeTo, TARGET_VAL(PPC::LVEHX), 0|OPFL_Chain,
                  1/*#VTs*/, MVT::v8i16, 2/*#Ops*/, 2, 3, 
              // Src: (intrinsic_w_chain:v8i16 2166:iPTR, xoaddr:iPTR:$src) - Complexity = 17
              // Dst: (LVEHX:v8i16 xoaddr:iPTR:$src)
/*9371*/    /*Scope*/ 20, /*->9392*/
/*9372*/      OPC_CheckInteger, 119|128,16/*2167*/, 
/*9375*/      OPC_MoveParent,
/*9376*/      OPC_RecordChild2, // #1 = $src
/*9377*/      OPC_CheckPatternPredicate, 0, // (PPCSubTarget.hasAltivec())
/*9379*/      OPC_CheckComplexPat, /*CP*/0, /*#*/1, // SelectAddrIdxOnly:$src #2 #3
/*9382*/      OPC_EmitMergeInputChains1_0,
/*9383*/      OPC_MorphNodeTo, TARGET_VAL(PPC::LVEWX), 0|OPFL_Chain,
                  1/*#VTs*/, MVT::v4i32, 2/*#Ops*/, 2, 3, 
              // Src: (intrinsic_w_chain:v4i32 2167:iPTR, xoaddr:iPTR:$src) - Complexity = 17
              // Dst: (LVEWX:v4i32 xoaddr:iPTR:$src)
/*9392*/    /*Scope*/ 20, /*->9413*/
/*9393*/      OPC_CheckInteger, 122|128,16/*2170*/, 
/*9396*/      OPC_MoveParent,
/*9397*/      OPC_RecordChild2, // #1 = $src
/*9398*/      OPC_CheckPatternPredicate, 0, // (PPCSubTarget.hasAltivec())
/*9400*/      OPC_CheckComplexPat, /*CP*/0, /*#*/1, // SelectAddrIdxOnly:$src #2 #3
/*9403*/      OPC_EmitMergeInputChains1_0,
/*9404*/      OPC_MorphNodeTo, TARGET_VAL(PPC::LVX), 0|OPFL_Chain,
                  1/*#VTs*/, MVT::v4i32, 2/*#Ops*/, 2, 3, 
              // Src: (intrinsic_w_chain:v4i32 2170:iPTR, xoaddr:iPTR:$src) - Complexity = 17
              // Dst: (LVX:v4i32 xoaddr:iPTR:$src)
/*9413*/    /*Scope*/ 20, /*->9434*/
/*9414*/      OPC_CheckInteger, 123|128,16/*2171*/, 
/*9417*/      OPC_MoveParent,
/*9418*/      OPC_RecordChild2, // #1 = $src
/*9419*/      OPC_CheckPatternPredicate, 0, // (PPCSubTarget.hasAltivec())
/*9421*/      OPC_CheckComplexPat, /*CP*/0, /*#*/1, // SelectAddrIdxOnly:$src #2 #3
/*9424*/      OPC_EmitMergeInputChains1_0,
/*9425*/      OPC_MorphNodeTo, TARGET_VAL(PPC::LVXL), 0|OPFL_Chain,
                  1/*#VTs*/, MVT::v4i32, 2/*#Ops*/, 2, 3, 
              // Src: (intrinsic_w_chain:v4i32 2171:iPTR, xoaddr:iPTR:$src) - Complexity = 17
              // Dst: (LVXL:v4i32 xoaddr:iPTR:$src)
/*9434*/    /*Scope*/ 14, /*->9449*/
/*9435*/      OPC_CheckInteger, 124|128,16/*2172*/, 
/*9438*/      OPC_MoveParent,
/*9439*/      OPC_CheckPatternPredicate, 0, // (PPCSubTarget.hasAltivec())
/*9441*/      OPC_EmitMergeInputChains1_0,
/*9442*/      OPC_MorphNodeTo, TARGET_VAL(PPC::MFVSCR), 0|OPFL_Chain,
                  1/*#VTs*/, MVT::v8i16, 0/*#Ops*/, 
              // Src: (intrinsic_w_chain:v8i16 2172:iPTR) - Complexity = 8
              // Dst: (MFVSCR:v8i16)
/*9449*/    0, /*End of Scope*/
/*9450*/  /*SwitchOpcode*/ 48|128,15/*1968*/,  TARGET_VAL(ISD::INTRINSIC_WO_CHAIN),// ->11422
/*9454*/    OPC_MoveChild, 0,
/*9456*/    OPC_Scope, 19, /*->9477*/ // 103 children in Scope
/*9458*/      OPC_CheckInteger, 120|128,16/*2168*/, 
/*9461*/      OPC_MoveParent,
/*9462*/      OPC_RecordChild1, // #0 = $src
/*9463*/      OPC_CheckPatternPredicate, 0, // (PPCSubTarget.hasAltivec())
/*9465*/      OPC_CheckComplexPat, /*CP*/0, /*#*/0, // SelectAddrIdxOnly:$src #1 #2
/*9468*/      OPC_MorphNodeTo, TARGET_VAL(PPC::LVSL), 0,
                  1/*#VTs*/, MVT::v16i8, 2/*#Ops*/, 1, 2, 
              // Src: (intrinsic_wo_chain:v16i8 2168:iPTR, xoaddr:iPTR:$src) - Complexity = 17
              // Dst: (LVSL:v16i8 xoaddr:iPTR:$src)
/*9477*/    /*Scope*/ 19, /*->9497*/
/*9478*/      OPC_CheckInteger, 121|128,16/*2169*/, 
/*9481*/      OPC_MoveParent,
/*9482*/      OPC_RecordChild1, // #0 = $src
/*9483*/      OPC_CheckPatternPredicate, 0, // (PPCSubTarget.hasAltivec())
/*9485*/      OPC_CheckComplexPat, /*CP*/0, /*#*/0, // SelectAddrIdxOnly:$src #1 #2
/*9488*/      OPC_MorphNodeTo, TARGET_VAL(PPC::LVSR), 0,
                  1/*#VTs*/, MVT::v16i8, 2/*#Ops*/, 1, 2, 
              // Src: (intrinsic_wo_chain:v16i8 2169:iPTR, xoaddr:iPTR:$src) - Complexity = 17
              // Dst: (LVSR:v16i8 xoaddr:iPTR:$src)
/*9497*/    /*Scope*/ 44, /*->9542*/
/*9498*/      OPC_CheckInteger, 45|128,17/*2221*/, 
/*9501*/      OPC_MoveParent,
/*9502*/      OPC_RecordChild1, // #0 = $vB
/*9503*/      OPC_Scope, 15, /*->9520*/ // 2 children in Scope
/*9505*/        OPC_MoveChild, 2,
/*9507*/        OPC_CheckInteger, 0, 
/*9509*/        OPC_MoveParent,
/*9510*/        OPC_CheckPatternPredicate, 0, // (PPCSubTarget.hasAltivec())
/*9512*/        OPC_MorphNodeTo, TARGET_VAL(PPC::VCTUXS_0), 0,
                    1/*#VTs*/, MVT::v4i32, 1/*#Ops*/, 0, 
                // Src: (intrinsic_wo_chain:v4i32 2221:iPTR, v4f32:v4f32:$vB, 0:i32) - Complexity = 13
                // Dst: (VCTUXS_0:v4i32 v4f32:v4f32:$vB)
/*9520*/      /*Scope*/ 20, /*->9541*/
/*9521*/        OPC_RecordChild2, // #1 = $UIMM
/*9522*/        OPC_MoveChild, 2,
/*9524*/        OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*9527*/        OPC_MoveParent,
/*9528*/        OPC_CheckPatternPredicate, 0, // (PPCSubTarget.hasAltivec())
/*9530*/        OPC_EmitConvertToTarget, 1,
/*9532*/        OPC_MorphNodeTo, TARGET_VAL(PPC::VCTUXS), 0,
                    1/*#VTs*/, MVT::v4i32, 2/*#Ops*/, 2, 0, 
                // Src: (intrinsic_wo_chain:v4i32 2221:iPTR, v4f32:v4f32:$vB, (imm:i32):$UIMM) - Complexity = 11
                // Dst: (VCTUXS:v4i32 (imm:i32):$UIMM, v4f32:v4f32:$vB)
/*9541*/      0, /*End of Scope*/
/*9542*/    /*Scope*/ 44, /*->9587*/
/*9543*/      OPC_CheckInteger, 44|128,17/*2220*/, 
/*9546*/      OPC_MoveParent,
/*9547*/      OPC_RecordChild1, // #0 = $vB
/*9548*/      OPC_Scope, 15, /*->9565*/ // 2 children in Scope
/*9550*/        OPC_MoveChild, 2,
/*9552*/        OPC_CheckInteger, 0, 
/*9554*/        OPC_MoveParent,
/*9555*/        OPC_CheckPatternPredicate, 0, // (PPCSubTarget.hasAltivec())
/*9557*/        OPC_MorphNodeTo, TARGET_VAL(PPC::VCTSXS_0), 0,
                    1/*#VTs*/, MVT::v4i32, 1/*#Ops*/, 0, 
                // Src: (intrinsic_wo_chain:v4i32 2220:iPTR, v4f32:v4f32:$vB, 0:i32) - Complexity = 13
                // Dst: (VCTSXS_0:v4i32 v4f32:v4f32:$vB)
/*9565*/      /*Scope*/ 20, /*->9586*/
/*9566*/        OPC_RecordChild2, // #1 = $UIMM
/*9567*/        OPC_MoveChild, 2,
/*9569*/        OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*9572*/        OPC_MoveParent,
/*9573*/        OPC_CheckPatternPredicate, 0, // (PPCSubTarget.hasAltivec())
/*9575*/        OPC_EmitConvertToTarget, 1,
/*9577*/        OPC_MorphNodeTo, TARGET_VAL(PPC::VCTSXS), 0,
                    1/*#VTs*/, MVT::v4i32, 2/*#Ops*/, 2, 0, 
                // Src: (intrinsic_wo_chain:v4i32 2220:iPTR, v4f32:v4f32:$vB, (imm:i32):$UIMM) - Complexity = 11
                // Dst: (VCTSXS:v4i32 (imm:i32):$UIMM, v4f32:v4f32:$vB)
/*9586*/      0, /*End of Scope*/
/*9587*/    /*Scope*/ 19, /*->9607*/
/*9588*/      OPC_CheckInteger, 56|128,17/*2232*/, 
/*9591*/      OPC_MoveParent,
/*9592*/      OPC_RecordChild1, // #0 = $vA
/*9593*/      OPC_RecordChild2, // #1 = $vB
/*9594*/      OPC_RecordChild3, // #2 = $vC
/*9595*/      OPC_CheckPatternPredicate, 0, // (PPCSubTarget.hasAltivec())
/*9597*/      OPC_MorphNodeTo, TARGET_VAL(PPC::VMHADDSHS), 0,
                  1/*#VTs*/, MVT::v8i16, 3/*#Ops*/, 0, 1, 2, 
              // Src: (intrinsic_wo_chain:v8i16 2232:iPTR, v8i16:v8i16:$vA, v8i16:v8i16:$vB, v8i16:v8i16:$vC) - Complexity = 8
              // Dst: (VMHADDSHS:v8i16 v8i16:v8i16:$vA, v8i16:v8i16:$vB, v8i16:v8i16:$vC)
/*9607*/    /*Scope*/ 19, /*->9627*/
/*9608*/      OPC_CheckInteger, 57|128,17/*2233*/, 
/*9611*/      OPC_MoveParent,
/*9612*/      OPC_RecordChild1, // #0 = $vA
/*9613*/      OPC_RecordChild2, // #1 = $vB
/*9614*/      OPC_RecordChild3, // #2 = $vC
/*9615*/      OPC_CheckPatternPredicate, 0, // (PPCSubTarget.hasAltivec())
/*9617*/      OPC_MorphNodeTo, TARGET_VAL(PPC::VMHRADDSHS), 0,
                  1/*#VTs*/, MVT::v8i16, 3/*#Ops*/, 0, 1, 2, 
              // Src: (intrinsic_wo_chain:v8i16 2233:iPTR, v8i16:v8i16:$vA, v8i16:v8i16:$vB, v8i16:v8i16:$vC) - Complexity = 8
              // Dst: (VMHRADDSHS:v8i16 v8i16:v8i16:$vA, v8i16:v8i16:$vB, v8i16:v8i16:$vC)
/*9627*/    /*Scope*/ 19, /*->9647*/
/*9628*/      OPC_CheckInteger, 65|128,17/*2241*/, 
/*9631*/      OPC_MoveParent,
/*9632*/      OPC_RecordChild1, // #0 = $vA
/*9633*/      OPC_RecordChild2, // #1 = $vB
/*9634*/      OPC_RecordChild3, // #2 = $vC
/*9635*/      OPC_CheckPatternPredicate, 0, // (PPCSubTarget.hasAltivec())
/*9637*/      OPC_MorphNodeTo, TARGET_VAL(PPC::VMLADDUHM), 0,
                  1/*#VTs*/, MVT::v8i16, 3/*#Ops*/, 0, 1, 2, 
              // Src: (intrinsic_wo_chain:v8i16 2241:iPTR, v8i16:v8i16:$vA, v8i16:v8i16:$vB, v8i16:v8i16:$vC) - Complexity = 8
              // Dst: (VMLADDUHM:v8i16 v8i16:v8i16:$vA, v8i16:v8i16:$vB, v8i16:v8i16:$vC)
/*9647*/    /*Scope*/ 19, /*->9667*/
/*9648*/      OPC_CheckInteger, 81|128,17/*2257*/, 
/*9651*/      OPC_MoveParent,
/*9652*/      OPC_RecordChild1, // #0 = $vA
/*9653*/      OPC_RecordChild2, // #1 = $vB
/*9654*/      OPC_RecordChild3, // #2 = $vC
/*9655*/      OPC_CheckPatternPredicate, 0, // (PPCSubTarget.hasAltivec())
/*9657*/      OPC_MorphNodeTo, TARGET_VAL(PPC::VPERM), 0,
                  1/*#VTs*/, MVT::v4i32, 3/*#Ops*/, 0, 1, 2, 
              // Src: (intrinsic_wo_chain:v4i32 2257:iPTR, v4i32:v4i32:$vA, v4i32:v4i32:$vB, v16i8:v16i8:$vC) - Complexity = 8
              // Dst: (VPERM:v4i32 v4i32:v4i32:$vA, v4i32:v4i32:$vB, v16i8:v16i8:$vC)
/*9667*/    /*Scope*/ 19, /*->9687*/
/*9668*/      OPC_CheckInteger, 98|128,17/*2274*/, 
/*9671*/      OPC_MoveParent,
/*9672*/      OPC_RecordChild1, // #0 = $vA
/*9673*/      OPC_RecordChild2, // #1 = $vB
/*9674*/      OPC_RecordChild3, // #2 = $vC
/*9675*/      OPC_CheckPatternPredicate, 0, // (PPCSubTarget.hasAltivec())
/*9677*/      OPC_MorphNodeTo, TARGET_VAL(PPC::VSEL), 0,
                  1/*#VTs*/, MVT::v4i32, 3/*#Ops*/, 0, 1, 2, 
              // Src: (intrinsic_wo_chain:v4i32 2274:iPTR, v4i32:v4i32:$vA, v4i32:v4i32:$vB, v4i32:v4i32:$vC) - Complexity = 8
              // Dst: (VSEL:v4i32 v4i32:v4i32:$vA, v4i32:v4i32:$vB, v4i32:v4i32:$vC)
/*9687*/    /*Scope*/ 17, /*->9705*/
/*9688*/      OPC_CheckInteger, 3|128,17/*2179*/, 
/*9691*/      OPC_MoveParent,
/*9692*/      OPC_RecordChild1, // #0 = $vA
/*9693*/      OPC_RecordChild2, // #1 = $vB
/*9694*/      OPC_CheckPatternPredicate, 0, // (PPCSubTarget.hasAltivec())
/*9696*/      OPC_MorphNodeTo, TARGET_VAL(PPC::VADDCUW), 0,
                  1/*#VTs*/, MVT::v4i32, 2/*#Ops*/, 0, 1, 
              // Src: (intrinsic_wo_chain:v4i32 2179:iPTR, v4i32:v4i32:$vA, v4i32:v4i32:$vB) - Complexity = 8
              // Dst: (VADDCUW:v4i32 v4i32:v4i32:$vA, v4i32:v4i32:$vB)
/*9705*/    /*Scope*/ 17, /*->9723*/
/*9706*/      OPC_CheckInteger, 4|128,17/*2180*/, 
/*9709*/      OPC_MoveParent,
/*9710*/      OPC_RecordChild1, // #0 = $vA
/*9711*/      OPC_RecordChild2, // #1 = $vB
/*9712*/      OPC_CheckPatternPredicate, 0, // (PPCSubTarget.hasAltivec())
/*9714*/      OPC_MorphNodeTo, TARGET_VAL(PPC::VADDSBS), 0,
                  1/*#VTs*/, MVT::v16i8, 2/*#Ops*/, 0, 1, 
              // Src: (intrinsic_wo_chain:v16i8 2180:iPTR, v16i8:v16i8:$vA, v16i8:v16i8:$vB) - Complexity = 8
              // Dst: (VADDSBS:v16i8 v16i8:v16i8:$vA, v16i8:v16i8:$vB)
/*9723*/    /*Scope*/ 17, /*->9741*/
/*9724*/      OPC_CheckInteger, 5|128,17/*2181*/, 
/*9727*/      OPC_MoveParent,
/*9728*/      OPC_RecordChild1, // #0 = $vA
/*9729*/      OPC_RecordChild2, // #1 = $vB
/*9730*/      OPC_CheckPatternPredicate, 0, // (PPCSubTarget.hasAltivec())
/*9732*/      OPC_MorphNodeTo, TARGET_VAL(PPC::VADDSHS), 0,
                  1/*#VTs*/, MVT::v8i16, 2/*#Ops*/, 0, 1, 
              // Src: (intrinsic_wo_chain:v8i16 2181:iPTR, v8i16:v8i16:$vA, v8i16:v8i16:$vB) - Complexity = 8
              // Dst: (VADDSHS:v8i16 v8i16:v8i16:$vA, v8i16:v8i16:$vB)
/*9741*/    /*Scope*/ 17, /*->9759*/
/*9742*/      OPC_CheckInteger, 6|128,17/*2182*/, 
/*9745*/      OPC_MoveParent,
/*9746*/      OPC_RecordChild1, // #0 = $vA
/*9747*/      OPC_RecordChild2, // #1 = $vB
/*9748*/      OPC_CheckPatternPredicate, 0, // (PPCSubTarget.hasAltivec())
/*9750*/      OPC_MorphNodeTo, TARGET_VAL(PPC::VADDSWS), 0,
                  1/*#VTs*/, MVT::v4i32, 2/*#Ops*/, 0, 1, 
              // Src: (intrinsic_wo_chain:v4i32 2182:iPTR, v4i32:v4i32:$vA, v4i32:v4i32:$vB) - Complexity = 8
              // Dst: (VADDSWS:v4i32 v4i32:v4i32:$vA, v4i32:v4i32:$vB)
/*9759*/    /*Scope*/ 17, /*->9777*/
/*9760*/      OPC_CheckInteger, 7|128,17/*2183*/, 
/*9763*/      OPC_MoveParent,
/*9764*/      OPC_RecordChild1, // #0 = $vA
/*9765*/      OPC_RecordChild2, // #1 = $vB
/*9766*/      OPC_CheckPatternPredicate, 0, // (PPCSubTarget.hasAltivec())
/*9768*/      OPC_MorphNodeTo, TARGET_VAL(PPC::VADDUBS), 0,
                  1/*#VTs*/, MVT::v16i8, 2/*#Ops*/, 0, 1, 
              // Src: (intrinsic_wo_chain:v16i8 2183:iPTR, v16i8:v16i8:$vA, v16i8:v16i8:$vB) - Complexity = 8
              // Dst: (VADDUBS:v16i8 v16i8:v16i8:$vA, v16i8:v16i8:$vB)
/*9777*/    /*Scope*/ 17, /*->9795*/
/*9778*/      OPC_CheckInteger, 8|128,17/*2184*/, 
/*9781*/      OPC_MoveParent,
/*9782*/      OPC_RecordChild1, // #0 = $vA
/*9783*/      OPC_RecordChild2, // #1 = $vB
/*9784*/      OPC_CheckPatternPredicate, 0, // (PPCSubTarget.hasAltivec())
/*9786*/      OPC_MorphNodeTo, TARGET_VAL(PPC::VADDUHS), 0,
                  1/*#VTs*/, MVT::v8i16, 2/*#Ops*/, 0, 1, 
              // Src: (intrinsic_wo_chain:v8i16 2184:iPTR, v8i16:v8i16:$vA, v8i16:v8i16:$vB) - Complexity = 8
              // Dst: (VADDUHS:v8i16 v8i16:v8i16:$vA, v8i16:v8i16:$vB)
/*9795*/    /*Scope*/ 17, /*->9813*/
/*9796*/      OPC_CheckInteger, 9|128,17/*2185*/, 
/*9799*/      OPC_MoveParent,
/*9800*/      OPC_RecordChild1, // #0 = $vA
/*9801*/      OPC_RecordChild2, // #1 = $vB
/*9802*/      OPC_CheckPatternPredicate, 0, // (PPCSubTarget.hasAltivec())
/*9804*/      OPC_MorphNodeTo, TARGET_VAL(PPC::VADDUWS), 0,
                  1/*#VTs*/, MVT::v4i32, 2/*#Ops*/, 0, 1, 
              // Src: (intrinsic_wo_chain:v4i32 2185:iPTR, v4i32:v4i32:$vA, v4i32:v4i32:$vB) - Complexity = 8
              // Dst: (VADDUWS:v4i32 v4i32:v4i32:$vA, v4i32:v4i32:$vB)
/*9813*/    /*Scope*/ 17, /*->9831*/
/*9814*/      OPC_CheckInteger, 10|128,17/*2186*/, 
/*9817*/      OPC_MoveParent,
/*9818*/      OPC_RecordChild1, // #0 = $vA
/*9819*/      OPC_RecordChild2, // #1 = $vB
/*9820*/      OPC_CheckPatternPredicate, 0, // (PPCSubTarget.hasAltivec())
/*9822*/      OPC_MorphNodeTo, TARGET_VAL(PPC::VAVGSB), 0,
                  1/*#VTs*/, MVT::v16i8, 2/*#Ops*/, 0, 1, 
              // Src: (intrinsic_wo_chain:v16i8 2186:iPTR, v16i8:v16i8:$vA, v16i8:v16i8:$vB) - Complexity = 8
              // Dst: (VAVGSB:v16i8 v16i8:v16i8:$vA, v16i8:v16i8:$vB)
/*9831*/    /*Scope*/ 17, /*->9849*/
/*9832*/      OPC_CheckInteger, 11|128,17/*2187*/, 
/*9835*/      OPC_MoveParent,
/*9836*/      OPC_RecordChild1, // #0 = $vA
/*9837*/      OPC_RecordChild2, // #1 = $vB
/*9838*/      OPC_CheckPatternPredicate, 0, // (PPCSubTarget.hasAltivec())
/*9840*/      OPC_MorphNodeTo, TARGET_VAL(PPC::VAVGSH), 0,
                  1/*#VTs*/, MVT::v8i16, 2/*#Ops*/, 0, 1, 
              // Src: (intrinsic_wo_chain:v8i16 2187:iPTR, v8i16:v8i16:$vA, v8i16:v8i16:$vB) - Complexity = 8
              // Dst: (VAVGSH:v8i16 v8i16:v8i16:$vA, v8i16:v8i16:$vB)
/*9849*/    /*Scope*/ 17, /*->9867*/
/*9850*/      OPC_CheckInteger, 12|128,17/*2188*/, 
/*9853*/      OPC_MoveParent,
/*9854*/      OPC_RecordChild1, // #0 = $vA
/*9855*/      OPC_RecordChild2, // #1 = $vB
/*9856*/      OPC_CheckPatternPredicate, 0, // (PPCSubTarget.hasAltivec())
/*9858*/      OPC_MorphNodeTo, TARGET_VAL(PPC::VAVGSW), 0,
                  1/*#VTs*/, MVT::v4i32, 2/*#Ops*/, 0, 1, 
              // Src: (intrinsic_wo_chain:v4i32 2188:iPTR, v4i32:v4i32:$vA, v4i32:v4i32:$vB) - Complexity = 8
              // Dst: (VAVGSW:v4i32 v4i32:v4i32:$vA, v4i32:v4i32:$vB)
/*9867*/    /*Scope*/ 17, /*->9885*/
/*9868*/      OPC_CheckInteger, 13|128,17/*2189*/, 
/*9871*/      OPC_MoveParent,
/*9872*/      OPC_RecordChild1, // #0 = $vA
/*9873*/      OPC_RecordChild2, // #1 = $vB
/*9874*/      OPC_CheckPatternPredicate, 0, // (PPCSubTarget.hasAltivec())
/*9876*/      OPC_MorphNodeTo, TARGET_VAL(PPC::VAVGUB), 0,
                  1/*#VTs*/, MVT::v16i8, 2/*#Ops*/, 0, 1, 
              // Src: (intrinsic_wo_chain:v16i8 2189:iPTR, v16i8:v16i8:$vA, v16i8:v16i8:$vB) - Complexity = 8
              // Dst: (VAVGUB:v16i8 v16i8:v16i8:$vA, v16i8:v16i8:$vB)
/*9885*/    /*Scope*/ 17, /*->9903*/
/*9886*/      OPC_CheckInteger, 14|128,17/*2190*/, 
/*9889*/      OPC_MoveParent,
/*9890*/      OPC_RecordChild1, // #0 = $vA
/*9891*/      OPC_RecordChild2, // #1 = $vB
/*9892*/      OPC_CheckPatternPredicate, 0, // (PPCSubTarget.hasAltivec())
/*9894*/      OPC_MorphNodeTo, TARGET_VAL(PPC::VAVGUH), 0,
                  1/*#VTs*/, MVT::v8i16, 2/*#Ops*/, 0, 1, 
              // Src: (intrinsic_wo_chain:v8i16 2190:iPTR, v8i16:v8i16:$vA, v8i16:v8i16:$vB) - Complexity = 8
              // Dst: (VAVGUH:v8i16 v8i16:v8i16:$vA, v8i16:v8i16:$vB)
/*9903*/    /*Scope*/ 17, /*->9921*/
/*9904*/      OPC_CheckInteger, 15|128,17/*2191*/, 
/*9907*/      OPC_MoveParent,
/*9908*/      OPC_RecordChild1, // #0 = $vA
/*9909*/      OPC_RecordChild2, // #1 = $vB
/*9910*/      OPC_CheckPatternPredicate, 0, // (PPCSubTarget.hasAltivec())
/*9912*/      OPC_MorphNodeTo, TARGET_VAL(PPC::VAVGUW), 0,
                  1/*#VTs*/, MVT::v4i32, 2/*#Ops*/, 0, 1, 
              // Src: (intrinsic_wo_chain:v4i32 2191:iPTR, v4i32:v4i32:$vA, v4i32:v4i32:$vB) - Complexity = 8
              // Dst: (VAVGUW:v4i32 v4i32:v4i32:$vA, v4i32:v4i32:$vB)
/*9921*/    /*Scope*/ 17, /*->9939*/
/*9922*/      OPC_CheckInteger, 50|128,17/*2226*/, 
/*9925*/      OPC_MoveParent,
/*9926*/      OPC_RecordChild1, // #0 = $vA
/*9927*/      OPC_RecordChild2, // #1 = $vB
/*9928*/      OPC_CheckPatternPredicate, 0, // (PPCSubTarget.hasAltivec())
/*9930*/      OPC_MorphNodeTo, TARGET_VAL(PPC::VMAXSB), 0,
                  1/*#VTs*/, MVT::v16i8, 2/*#Ops*/, 0, 1, 
              // Src: (intrinsic_wo_chain:v16i8 2226:iPTR, v16i8:v16i8:$vA, v16i8:v16i8:$vB) - Complexity = 8
              // Dst: (VMAXSB:v16i8 v16i8:v16i8:$vA, v16i8:v16i8:$vB)
/*9939*/    /*Scope*/ 17, /*->9957*/
/*9940*/      OPC_CheckInteger, 51|128,17/*2227*/, 
/*9943*/      OPC_MoveParent,
/*9944*/      OPC_RecordChild1, // #0 = $vA
/*9945*/      OPC_RecordChild2, // #1 = $vB
/*9946*/      OPC_CheckPatternPredicate, 0, // (PPCSubTarget.hasAltivec())
/*9948*/      OPC_MorphNodeTo, TARGET_VAL(PPC::VMAXSH), 0,
                  1/*#VTs*/, MVT::v8i16, 2/*#Ops*/, 0, 1, 
              // Src: (intrinsic_wo_chain:v8i16 2227:iPTR, v8i16:v8i16:$vA, v8i16:v8i16:$vB) - Complexity = 8
              // Dst: (VMAXSH:v8i16 v8i16:v8i16:$vA, v8i16:v8i16:$vB)
/*9957*/    /*Scope*/ 17, /*->9975*/
/*9958*/      OPC_CheckInteger, 52|128,17/*2228*/, 
/*9961*/      OPC_MoveParent,
/*9962*/      OPC_RecordChild1, // #0 = $vA
/*9963*/      OPC_RecordChild2, // #1 = $vB
/*9964*/      OPC_CheckPatternPredicate, 0, // (PPCSubTarget.hasAltivec())
/*9966*/      OPC_MorphNodeTo, TARGET_VAL(PPC::VMAXSW), 0,
                  1/*#VTs*/, MVT::v4i32, 2/*#Ops*/, 0, 1, 
              // Src: (intrinsic_wo_chain:v4i32 2228:iPTR, v4i32:v4i32:$vA, v4i32:v4i32:$vB) - Complexity = 8
              // Dst: (VMAXSW:v4i32 v4i32:v4i32:$vA, v4i32:v4i32:$vB)
/*9975*/    /*Scope*/ 17, /*->9993*/
/*9976*/      OPC_CheckInteger, 53|128,17/*2229*/, 
/*9979*/      OPC_MoveParent,
/*9980*/      OPC_RecordChild1, // #0 = $vA
/*9981*/      OPC_RecordChild2, // #1 = $vB
/*9982*/      OPC_CheckPatternPredicate, 0, // (PPCSubTarget.hasAltivec())
/*9984*/      OPC_MorphNodeTo, TARGET_VAL(PPC::VMAXUB), 0,
                  1/*#VTs*/, MVT::v16i8, 2/*#Ops*/, 0, 1, 
              // Src: (intrinsic_wo_chain:v16i8 2229:iPTR, v16i8:v16i8:$vA, v16i8:v16i8:$vB) - Complexity = 8
              // Dst: (VMAXUB:v16i8 v16i8:v16i8:$vA, v16i8:v16i8:$vB)
/*9993*/    /*Scope*/ 17, /*->10011*/
/*9994*/      OPC_CheckInteger, 54|128,17/*2230*/, 
/*9997*/      OPC_MoveParent,
/*9998*/      OPC_RecordChild1, // #0 = $vA
/*9999*/      OPC_RecordChild2, // #1 = $vB
/*10000*/     OPC_CheckPatternPredicate, 0, // (PPCSubTarget.hasAltivec())
/*10002*/     OPC_MorphNodeTo, TARGET_VAL(PPC::VMAXUH), 0,
                  1/*#VTs*/, MVT::v8i16, 2/*#Ops*/, 0, 1, 
              // Src: (intrinsic_wo_chain:v8i16 2230:iPTR, v8i16:v8i16:$vA, v8i16:v8i16:$vB) - Complexity = 8
              // Dst: (VMAXUH:v8i16 v8i16:v8i16:$vA, v8i16:v8i16:$vB)
/*10011*/   /*Scope*/ 17, /*->10029*/
/*10012*/     OPC_CheckInteger, 55|128,17/*2231*/, 
/*10015*/     OPC_MoveParent,
/*10016*/     OPC_RecordChild1, // #0 = $vA
/*10017*/     OPC_RecordChild2, // #1 = $vB
/*10018*/     OPC_CheckPatternPredicate, 0, // (PPCSubTarget.hasAltivec())
/*10020*/     OPC_MorphNodeTo, TARGET_VAL(PPC::VMAXUW), 0,
                  1/*#VTs*/, MVT::v4i32, 2/*#Ops*/, 0, 1, 
              // Src: (intrinsic_wo_chain:v4i32 2231:iPTR, v4i32:v4i32:$vA, v4i32:v4i32:$vB) - Complexity = 8
              // Dst: (VMAXUW:v4i32 v4i32:v4i32:$vA, v4i32:v4i32:$vB)
/*10029*/   /*Scope*/ 17, /*->10047*/
/*10030*/     OPC_CheckInteger, 59|128,17/*2235*/, 
/*10033*/     OPC_MoveParent,
/*10034*/     OPC_RecordChild1, // #0 = $vA
/*10035*/     OPC_RecordChild2, // #1 = $vB
/*10036*/     OPC_CheckPatternPredicate, 0, // (PPCSubTarget.hasAltivec())
/*10038*/     OPC_MorphNodeTo, TARGET_VAL(PPC::VMINSB), 0,
                  1/*#VTs*/, MVT::v16i8, 2/*#Ops*/, 0, 1, 
              // Src: (intrinsic_wo_chain:v16i8 2235:iPTR, v16i8:v16i8:$vA, v16i8:v16i8:$vB) - Complexity = 8
              // Dst: (VMINSB:v16i8 v16i8:v16i8:$vA, v16i8:v16i8:$vB)
/*10047*/   /*Scope*/ 17, /*->10065*/
/*10048*/     OPC_CheckInteger, 60|128,17/*2236*/, 
/*10051*/     OPC_MoveParent,
/*10052*/     OPC_RecordChild1, // #0 = $vA
/*10053*/     OPC_RecordChild2, // #1 = $vB
/*10054*/     OPC_CheckPatternPredicate, 0, // (PPCSubTarget.hasAltivec())
/*10056*/     OPC_MorphNodeTo, TARGET_VAL(PPC::VMINSH), 0,
                  1/*#VTs*/, MVT::v8i16, 2/*#Ops*/, 0, 1, 
              // Src: (intrinsic_wo_chain:v8i16 2236:iPTR, v8i16:v8i16:$vA, v8i16:v8i16:$vB) - Complexity = 8
              // Dst: (VMINSH:v8i16 v8i16:v8i16:$vA, v8i16:v8i16:$vB)
/*10065*/   /*Scope*/ 17, /*->10083*/
/*10066*/     OPC_CheckInteger, 61|128,17/*2237*/, 
/*10069*/     OPC_MoveParent,
/*10070*/     OPC_RecordChild1, // #0 = $vA
/*10071*/     OPC_RecordChild2, // #1 = $vB
/*10072*/     OPC_CheckPatternPredicate, 0, // (PPCSubTarget.hasAltivec())
/*10074*/     OPC_MorphNodeTo, TARGET_VAL(PPC::VMINSW), 0,
                  1/*#VTs*/, MVT::v4i32, 2/*#Ops*/, 0, 1, 
              // Src: (intrinsic_wo_chain:v4i32 2237:iPTR, v4i32:v4i32:$vA, v4i32:v4i32:$vB) - Complexity = 8
              // Dst: (VMINSW:v4i32 v4i32:v4i32:$vA, v4i32:v4i32:$vB)
/*10083*/   /*Scope*/ 17, /*->10101*/
/*10084*/     OPC_CheckInteger, 62|128,17/*2238*/, 
/*10087*/     OPC_MoveParent,
/*10088*/     OPC_RecordChild1, // #0 = $vA
/*10089*/     OPC_RecordChild2, // #1 = $vB
/*10090*/     OPC_CheckPatternPredicate, 0, // (PPCSubTarget.hasAltivec())
/*10092*/     OPC_MorphNodeTo, TARGET_VAL(PPC::VMINUB), 0,
                  1/*#VTs*/, MVT::v16i8, 2/*#Ops*/, 0, 1, 
              // Src: (intrinsic_wo_chain:v16i8 2238:iPTR, v16i8:v16i8:$vA, v16i8:v16i8:$vB) - Complexity = 8
              // Dst: (VMINUB:v16i8 v16i8:v16i8:$vA, v16i8:v16i8:$vB)
/*10101*/   /*Scope*/ 17, /*->10119*/
/*10102*/     OPC_CheckInteger, 63|128,17/*2239*/, 
/*10105*/     OPC_MoveParent,
/*10106*/     OPC_RecordChild1, // #0 = $vA
/*10107*/     OPC_RecordChild2, // #1 = $vB
/*10108*/     OPC_CheckPatternPredicate, 0, // (PPCSubTarget.hasAltivec())
/*10110*/     OPC_MorphNodeTo, TARGET_VAL(PPC::VMINUH), 0,
                  1/*#VTs*/, MVT::v8i16, 2/*#Ops*/, 0, 1, 
              // Src: (intrinsic_wo_chain:v8i16 2239:iPTR, v8i16:v8i16:$vA, v8i16:v8i16:$vB) - Complexity = 8
              // Dst: (VMINUH:v8i16 v8i16:v8i16:$vA, v8i16:v8i16:$vB)
/*10119*/   /*Scope*/ 17, /*->10137*/
/*10120*/     OPC_CheckInteger, 64|128,17/*2240*/, 
/*10123*/     OPC_MoveParent,
/*10124*/     OPC_RecordChild1, // #0 = $vA
/*10125*/     OPC_RecordChild2, // #1 = $vB
/*10126*/     OPC_CheckPatternPredicate, 0, // (PPCSubTarget.hasAltivec())
/*10128*/     OPC_MorphNodeTo, TARGET_VAL(PPC::VMINUW), 0,
                  1/*#VTs*/, MVT::v4i32, 2/*#Ops*/, 0, 1, 
              // Src: (intrinsic_wo_chain:v4i32 2240:iPTR, v4i32:v4i32:$vA, v4i32:v4i32:$vB) - Complexity = 8
              // Dst: (VMINUW:v4i32 v4i32:v4i32:$vA, v4i32:v4i32:$vB)
/*10137*/   /*Scope*/ 19, /*->10157*/
/*10138*/     OPC_CheckInteger, 66|128,17/*2242*/, 
/*10141*/     OPC_MoveParent,
/*10142*/     OPC_RecordChild1, // #0 = $vA
/*10143*/     OPC_RecordChild2, // #1 = $vB
/*10144*/     OPC_RecordChild3, // #2 = $vC
/*10145*/     OPC_CheckPatternPredicate, 0, // (PPCSubTarget.hasAltivec())
/*10147*/     OPC_MorphNodeTo, TARGET_VAL(PPC::VMSUMMBM), 0,
                  1/*#VTs*/, MVT::v4i32, 3/*#Ops*/, 0, 1, 2, 
              // Src: (intrinsic_wo_chain:v4i32 2242:iPTR, v16i8:v16i8:$vA, v16i8:v16i8:$vB, v4i32:v4i32:$vC) - Complexity = 8
              // Dst: (VMSUMMBM:v4i32 v16i8:v16i8:$vA, v16i8:v16i8:$vB, v4i32:v4i32:$vC)
/*10157*/   /*Scope*/ 19, /*->10177*/
/*10158*/     OPC_CheckInteger, 67|128,17/*2243*/, 
/*10161*/     OPC_MoveParent,
/*10162*/     OPC_RecordChild1, // #0 = $vA
/*10163*/     OPC_RecordChild2, // #1 = $vB
/*10164*/     OPC_RecordChild3, // #2 = $vC
/*10165*/     OPC_CheckPatternPredicate, 0, // (PPCSubTarget.hasAltivec())
/*10167*/     OPC_MorphNodeTo, TARGET_VAL(PPC::VMSUMSHM), 0,
                  1/*#VTs*/, MVT::v4i32, 3/*#Ops*/, 0, 1, 2, 
              // Src: (intrinsic_wo_chain:v4i32 2243:iPTR, v8i16:v8i16:$vA, v8i16:v8i16:$vB, v4i32:v4i32:$vC) - Complexity = 8
              // Dst: (VMSUMSHM:v4i32 v8i16:v8i16:$vA, v8i16:v8i16:$vB, v4i32:v4i32:$vC)
/*10177*/   /*Scope*/ 19, /*->10197*/
/*10178*/     OPC_CheckInteger, 68|128,17/*2244*/, 
/*10181*/     OPC_MoveParent,
/*10182*/     OPC_RecordChild1, // #0 = $vA
/*10183*/     OPC_RecordChild2, // #1 = $vB
/*10184*/     OPC_RecordChild3, // #2 = $vC
/*10185*/     OPC_CheckPatternPredicate, 0, // (PPCSubTarget.hasAltivec())
/*10187*/     OPC_MorphNodeTo, TARGET_VAL(PPC::VMSUMSHS), 0,
                  1/*#VTs*/, MVT::v4i32, 3/*#Ops*/, 0, 1, 2, 
              // Src: (intrinsic_wo_chain:v4i32 2244:iPTR, v8i16:v8i16:$vA, v8i16:v8i16:$vB, v4i32:v4i32:$vC) - Complexity = 8
              // Dst: (VMSUMSHS:v4i32 v8i16:v8i16:$vA, v8i16:v8i16:$vB, v4i32:v4i32:$vC)
/*10197*/   /*Scope*/ 19, /*->10217*/
/*10198*/     OPC_CheckInteger, 69|128,17/*2245*/, 
/*10201*/     OPC_MoveParent,
/*10202*/     OPC_RecordChild1, // #0 = $vA
/*10203*/     OPC_RecordChild2, // #1 = $vB
/*10204*/     OPC_RecordChild3, // #2 = $vC
/*10205*/     OPC_CheckPatternPredicate, 0, // (PPCSubTarget.hasAltivec())
/*10207*/     OPC_MorphNodeTo, TARGET_VAL(PPC::VMSUMUBM), 0,
                  1/*#VTs*/, MVT::v4i32, 3/*#Ops*/, 0, 1, 2, 
              // Src: (intrinsic_wo_chain:v4i32 2245:iPTR, v16i8:v16i8:$vA, v16i8:v16i8:$vB, v4i32:v4i32:$vC) - Complexity = 8
              // Dst: (VMSUMUBM:v4i32 v16i8:v16i8:$vA, v16i8:v16i8:$vB, v4i32:v4i32:$vC)
/*10217*/   /*Scope*/ 19, /*->10237*/
/*10218*/     OPC_CheckInteger, 70|128,17/*2246*/, 
/*10221*/     OPC_MoveParent,
/*10222*/     OPC_RecordChild1, // #0 = $vA
/*10223*/     OPC_RecordChild2, // #1 = $vB
/*10224*/     OPC_RecordChild3, // #2 = $vC
/*10225*/     OPC_CheckPatternPredicate, 0, // (PPCSubTarget.hasAltivec())
/*10227*/     OPC_MorphNodeTo, TARGET_VAL(PPC::VMSUMUHM), 0,
                  1/*#VTs*/, MVT::v4i32, 3/*#Ops*/, 0, 1, 2, 
              // Src: (intrinsic_wo_chain:v4i32 2246:iPTR, v8i16:v8i16:$vA, v8i16:v8i16:$vB, v4i32:v4i32:$vC) - Complexity = 8
              // Dst: (VMSUMUHM:v4i32 v8i16:v8i16:$vA, v8i16:v8i16:$vB, v4i32:v4i32:$vC)
/*10237*/   /*Scope*/ 19, /*->10257*/
/*10238*/     OPC_CheckInteger, 71|128,17/*2247*/, 
/*10241*/     OPC_MoveParent,
/*10242*/     OPC_RecordChild1, // #0 = $vA
/*10243*/     OPC_RecordChild2, // #1 = $vB
/*10244*/     OPC_RecordChild3, // #2 = $vC
/*10245*/     OPC_CheckPatternPredicate, 0, // (PPCSubTarget.hasAltivec())
/*10247*/     OPC_MorphNodeTo, TARGET_VAL(PPC::VMSUMUHS), 0,
                  1/*#VTs*/, MVT::v4i32, 3/*#Ops*/, 0, 1, 2, 
              // Src: (intrinsic_wo_chain:v4i32 2247:iPTR, v8i16:v8i16:$vA, v8i16:v8i16:$vB, v4i32:v4i32:$vC) - Complexity = 8
              // Dst: (VMSUMUHS:v4i32 v8i16:v8i16:$vA, v8i16:v8i16:$vB, v4i32:v4i32:$vC)
/*10257*/   /*Scope*/ 17, /*->10275*/
/*10258*/     OPC_CheckInteger, 72|128,17/*2248*/, 
/*10261*/     OPC_MoveParent,
/*10262*/     OPC_RecordChild1, // #0 = $vA
/*10263*/     OPC_RecordChild2, // #1 = $vB
/*10264*/     OPC_CheckPatternPredicate, 0, // (PPCSubTarget.hasAltivec())
/*10266*/     OPC_MorphNodeTo, TARGET_VAL(PPC::VMULESB), 0,
                  1/*#VTs*/, MVT::v8i16, 2/*#Ops*/, 0, 1, 
              // Src: (intrinsic_wo_chain:v8i16 2248:iPTR, v16i8:v16i8:$vA, v16i8:v16i8:$vB) - Complexity = 8
              // Dst: (VMULESB:v8i16 v16i8:v16i8:$vA, v16i8:v16i8:$vB)
/*10275*/   /*Scope*/ 17, /*->10293*/
/*10276*/     OPC_CheckInteger, 73|128,17/*2249*/, 
/*10279*/     OPC_MoveParent,
/*10280*/     OPC_RecordChild1, // #0 = $vA
/*10281*/     OPC_RecordChild2, // #1 = $vB
/*10282*/     OPC_CheckPatternPredicate, 0, // (PPCSubTarget.hasAltivec())
/*10284*/     OPC_MorphNodeTo, TARGET_VAL(PPC::VMULESH), 0,
                  1/*#VTs*/, MVT::v4i32, 2/*#Ops*/, 0, 1, 
              // Src: (intrinsic_wo_chain:v4i32 2249:iPTR, v8i16:v8i16:$vA, v8i16:v8i16:$vB) - Complexity = 8
              // Dst: (VMULESH:v4i32 v8i16:v8i16:$vA, v8i16:v8i16:$vB)
/*10293*/   /*Scope*/ 17, /*->10311*/
/*10294*/     OPC_CheckInteger, 74|128,17/*2250*/, 
/*10297*/     OPC_MoveParent,
/*10298*/     OPC_RecordChild1, // #0 = $vA
/*10299*/     OPC_RecordChild2, // #1 = $vB
/*10300*/     OPC_CheckPatternPredicate, 0, // (PPCSubTarget.hasAltivec())
/*10302*/     OPC_MorphNodeTo, TARGET_VAL(PPC::VMULEUB), 0,
                  1/*#VTs*/, MVT::v8i16, 2/*#Ops*/, 0, 1, 
              // Src: (intrinsic_wo_chain:v8i16 2250:iPTR, v16i8:v16i8:$vA, v16i8:v16i8:$vB) - Complexity = 8
              // Dst: (VMULEUB:v8i16 v16i8:v16i8:$vA, v16i8:v16i8:$vB)
/*10311*/   /*Scope*/ 17, /*->10329*/
/*10312*/     OPC_CheckInteger, 75|128,17/*2251*/, 
/*10315*/     OPC_MoveParent,
/*10316*/     OPC_RecordChild1, // #0 = $vA
/*10317*/     OPC_RecordChild2, // #1 = $vB
/*10318*/     OPC_CheckPatternPredicate, 0, // (PPCSubTarget.hasAltivec())
/*10320*/     OPC_MorphNodeTo, TARGET_VAL(PPC::VMULEUH), 0,
                  1/*#VTs*/, MVT::v4i32, 2/*#Ops*/, 0, 1, 
              // Src: (intrinsic_wo_chain:v4i32 2251:iPTR, v8i16:v8i16:$vA, v8i16:v8i16:$vB) - Complexity = 8
              // Dst: (VMULEUH:v4i32 v8i16:v8i16:$vA, v8i16:v8i16:$vB)
/*10329*/   /*Scope*/ 17, /*->10347*/
/*10330*/     OPC_CheckInteger, 76|128,17/*2252*/, 
/*10333*/     OPC_MoveParent,
/*10334*/     OPC_RecordChild1, // #0 = $vA
/*10335*/     OPC_RecordChild2, // #1 = $vB
/*10336*/     OPC_CheckPatternPredicate, 0, // (PPCSubTarget.hasAltivec())
/*10338*/     OPC_MorphNodeTo, TARGET_VAL(PPC::VMULOSB), 0,
                  1/*#VTs*/, MVT::v8i16, 2/*#Ops*/, 0, 1, 
              // Src: (intrinsic_wo_chain:v8i16 2252:iPTR, v16i8:v16i8:$vA, v16i8:v16i8:$vB) - Complexity = 8
              // Dst: (VMULOSB:v8i16 v16i8:v16i8:$vA, v16i8:v16i8:$vB)
/*10347*/   /*Scope*/ 17, /*->10365*/
/*10348*/     OPC_CheckInteger, 77|128,17/*2253*/, 
/*10351*/     OPC_MoveParent,
/*10352*/     OPC_RecordChild1, // #0 = $vA
/*10353*/     OPC_RecordChild2, // #1 = $vB
/*10354*/     OPC_CheckPatternPredicate, 0, // (PPCSubTarget.hasAltivec())
/*10356*/     OPC_MorphNodeTo, TARGET_VAL(PPC::VMULOSH), 0,
                  1/*#VTs*/, MVT::v4i32, 2/*#Ops*/, 0, 1, 
              // Src: (intrinsic_wo_chain:v4i32 2253:iPTR, v8i16:v8i16:$vA, v8i16:v8i16:$vB) - Complexity = 8
              // Dst: (VMULOSH:v4i32 v8i16:v8i16:$vA, v8i16:v8i16:$vB)
/*10365*/   /*Scope*/ 17, /*->10383*/
/*10366*/     OPC_CheckInteger, 78|128,17/*2254*/, 
/*10369*/     OPC_MoveParent,
/*10370*/     OPC_RecordChild1, // #0 = $vA
/*10371*/     OPC_RecordChild2, // #1 = $vB
/*10372*/     OPC_CheckPatternPredicate, 0, // (PPCSubTarget.hasAltivec())
/*10374*/     OPC_MorphNodeTo, TARGET_VAL(PPC::VMULOUB), 0,
                  1/*#VTs*/, MVT::v8i16, 2/*#Ops*/, 0, 1, 
              // Src: (intrinsic_wo_chain:v8i16 2254:iPTR, v16i8:v16i8:$vA, v16i8:v16i8:$vB) - Complexity = 8
              // Dst: (VMULOUB:v8i16 v16i8:v16i8:$vA, v16i8:v16i8:$vB)
/*10383*/   /*Scope*/ 17, /*->10401*/
/*10384*/     OPC_CheckInteger, 79|128,17/*2255*/, 
/*10387*/     OPC_MoveParent,
/*10388*/     OPC_RecordChild1, // #0 = $vA
/*10389*/     OPC_RecordChild2, // #1 = $vB
/*10390*/     OPC_CheckPatternPredicate, 0, // (PPCSubTarget.hasAltivec())
/*10392*/     OPC_MorphNodeTo, TARGET_VAL(PPC::VMULOUH), 0,
                  1/*#VTs*/, MVT::v4i32, 2/*#Ops*/, 0, 1, 
              // Src: (intrinsic_wo_chain:v4i32 2255:iPTR, v8i16:v8i16:$vA, v8i16:v8i16:$vB) - Complexity = 8
              // Dst: (VMULOUH:v4i32 v8i16:v8i16:$vA, v8i16:v8i16:$vB)
/*10401*/   /*Scope*/ 17, /*->10419*/
/*10402*/     OPC_CheckInteger, 112|128,17/*2288*/, 
/*10405*/     OPC_MoveParent,
/*10406*/     OPC_RecordChild1, // #0 = $vA
/*10407*/     OPC_RecordChild2, // #1 = $vB
/*10408*/     OPC_CheckPatternPredicate, 0, // (PPCSubTarget.hasAltivec())
/*10410*/     OPC_MorphNodeTo, TARGET_VAL(PPC::VSUBCUW), 0,
                  1/*#VTs*/, MVT::v4i32, 2/*#Ops*/, 0, 1, 
              // Src: (intrinsic_wo_chain:v4i32 2288:iPTR, v4i32:v4i32:$vA, v4i32:v4i32:$vB) - Complexity = 8
              // Dst: (VSUBCUW:v4i32 v4i32:v4i32:$vA, v4i32:v4i32:$vB)
/*10419*/   /*Scope*/ 17, /*->10437*/
/*10420*/     OPC_CheckInteger, 113|128,17/*2289*/, 
/*10423*/     OPC_MoveParent,
/*10424*/     OPC_RecordChild1, // #0 = $vA
/*10425*/     OPC_RecordChild2, // #1 = $vB
/*10426*/     OPC_CheckPatternPredicate, 0, // (PPCSubTarget.hasAltivec())
/*10428*/     OPC_MorphNodeTo, TARGET_VAL(PPC::VSUBSBS), 0,
                  1/*#VTs*/, MVT::v16i8, 2/*#Ops*/, 0, 1, 
              // Src: (intrinsic_wo_chain:v16i8 2289:iPTR, v16i8:v16i8:$vA, v16i8:v16i8:$vB) - Complexity = 8
              // Dst: (VSUBSBS:v16i8 v16i8:v16i8:$vA, v16i8:v16i8:$vB)
/*10437*/   /*Scope*/ 17, /*->10455*/
/*10438*/     OPC_CheckInteger, 114|128,17/*2290*/, 
/*10441*/     OPC_MoveParent,
/*10442*/     OPC_RecordChild1, // #0 = $vA
/*10443*/     OPC_RecordChild2, // #1 = $vB
/*10444*/     OPC_CheckPatternPredicate, 0, // (PPCSubTarget.hasAltivec())
/*10446*/     OPC_MorphNodeTo, TARGET_VAL(PPC::VSUBSHS), 0,
                  1/*#VTs*/, MVT::v8i16, 2/*#Ops*/, 0, 1, 
              // Src: (intrinsic_wo_chain:v8i16 2290:iPTR, v8i16:v8i16:$vA, v8i16:v8i16:$vB) - Complexity = 8
              // Dst: (VSUBSHS:v8i16 v8i16:v8i16:$vA, v8i16:v8i16:$vB)
/*10455*/   /*Scope*/ 17, /*->10473*/
/*10456*/     OPC_CheckInteger, 115|128,17/*2291*/, 
/*10459*/     OPC_MoveParent,
/*10460*/     OPC_RecordChild1, // #0 = $vA
/*10461*/     OPC_RecordChild2, // #1 = $vB
/*10462*/     OPC_CheckPatternPredicate, 0, // (PPCSubTarget.hasAltivec())
/*10464*/     OPC_MorphNodeTo, TARGET_VAL(PPC::VSUBSWS), 0,
                  1/*#VTs*/, MVT::v4i32, 2/*#Ops*/, 0, 1, 
              // Src: (intrinsic_wo_chain:v4i32 2291:iPTR, v4i32:v4i32:$vA, v4i32:v4i32:$vB) - Complexity = 8
              // Dst: (VSUBSWS:v4i32 v4i32:v4i32:$vA, v4i32:v4i32:$vB)
/*10473*/   /*Scope*/ 17, /*->10491*/
/*10474*/     OPC_CheckInteger, 116|128,17/*2292*/, 
/*10477*/     OPC_MoveParent,
/*10478*/     OPC_RecordChild1, // #0 = $vA
/*10479*/     OPC_RecordChild2, // #1 = $vB
/*10480*/     OPC_CheckPatternPredicate, 0, // (PPCSubTarget.hasAltivec())
/*10482*/     OPC_MorphNodeTo, TARGET_VAL(PPC::VSUBUBS), 0,
                  1/*#VTs*/, MVT::v16i8, 2/*#Ops*/, 0, 1, 
              // Src: (intrinsic_wo_chain:v16i8 2292:iPTR, v16i8:v16i8:$vA, v16i8:v16i8:$vB) - Complexity = 8
              // Dst: (VSUBUBS:v16i8 v16i8:v16i8:$vA, v16i8:v16i8:$vB)
/*10491*/   /*Scope*/ 17, /*->10509*/
/*10492*/     OPC_CheckInteger, 117|128,17/*2293*/, 
/*10495*/     OPC_MoveParent,
/*10496*/     OPC_RecordChild1, // #0 = $vA
/*10497*/     OPC_RecordChild2, // #1 = $vB
/*10498*/     OPC_CheckPatternPredicate, 0, // (PPCSubTarget.hasAltivec())
/*10500*/     OPC_MorphNodeTo, TARGET_VAL(PPC::VSUBUHS), 0,
                  1/*#VTs*/, MVT::v8i16, 2/*#Ops*/, 0, 1, 
              // Src: (intrinsic_wo_chain:v8i16 2293:iPTR, v8i16:v8i16:$vA, v8i16:v8i16:$vB) - Complexity = 8
              // Dst: (VSUBUHS:v8i16 v8i16:v8i16:$vA, v8i16:v8i16:$vB)
/*10509*/   /*Scope*/ 17, /*->10527*/
/*10510*/     OPC_CheckInteger, 118|128,17/*2294*/, 
/*10513*/     OPC_MoveParent,
/*10514*/     OPC_RecordChild1, // #0 = $vA
/*10515*/     OPC_RecordChild2, // #1 = $vB
/*10516*/     OPC_CheckPatternPredicate, 0, // (PPCSubTarget.hasAltivec())
/*10518*/     OPC_MorphNodeTo, TARGET_VAL(PPC::VSUBUWS), 0,
                  1/*#VTs*/, MVT::v4i32, 2/*#Ops*/, 0, 1, 
              // Src: (intrinsic_wo_chain:v4i32 2294:iPTR, v4i32:v4i32:$vA, v4i32:v4i32:$vB) - Complexity = 8
              // Dst: (VSUBUWS:v4i32 v4i32:v4i32:$vA, v4i32:v4i32:$vB)
/*10527*/   /*Scope*/ 17, /*->10545*/
/*10528*/     OPC_CheckInteger, 123|128,17/*2299*/, 
/*10531*/     OPC_MoveParent,
/*10532*/     OPC_RecordChild1, // #0 = $vA
/*10533*/     OPC_RecordChild2, // #1 = $vB
/*10534*/     OPC_CheckPatternPredicate, 0, // (PPCSubTarget.hasAltivec())
/*10536*/     OPC_MorphNodeTo, TARGET_VAL(PPC::VSUMSWS), 0,
                  1/*#VTs*/, MVT::v4i32, 2/*#Ops*/, 0, 1, 
              // Src: (intrinsic_wo_chain:v4i32 2299:iPTR, v4i32:v4i32:$vA, v4i32:v4i32:$vB) - Complexity = 8
              // Dst: (VSUMSWS:v4i32 v4i32:v4i32:$vA, v4i32:v4i32:$vB)
/*10545*/   /*Scope*/ 17, /*->10563*/
/*10546*/     OPC_CheckInteger, 119|128,17/*2295*/, 
/*10549*/     OPC_MoveParent,
/*10550*/     OPC_RecordChild1, // #0 = $vA
/*10551*/     OPC_RecordChild2, // #1 = $vB
/*10552*/     OPC_CheckPatternPredicate, 0, // (PPCSubTarget.hasAltivec())
/*10554*/     OPC_MorphNodeTo, TARGET_VAL(PPC::VSUM2SWS), 0,
                  1/*#VTs*/, MVT::v4i32, 2/*#Ops*/, 0, 1, 
              // Src: (intrinsic_wo_chain:v4i32 2295:iPTR, v4i32:v4i32:$vA, v4i32:v4i32:$vB) - Complexity = 8
              // Dst: (VSUM2SWS:v4i32 v4i32:v4i32:$vA, v4i32:v4i32:$vB)
/*10563*/   /*Scope*/ 17, /*->10581*/
/*10564*/     OPC_CheckInteger, 120|128,17/*2296*/, 
/*10567*/     OPC_MoveParent,
/*10568*/     OPC_RecordChild1, // #0 = $vA
/*10569*/     OPC_RecordChild2, // #1 = $vB
/*10570*/     OPC_CheckPatternPredicate, 0, // (PPCSubTarget.hasAltivec())
/*10572*/     OPC_MorphNodeTo, TARGET_VAL(PPC::VSUM4SBS), 0,
                  1/*#VTs*/, MVT::v4i32, 2/*#Ops*/, 0, 1, 
              // Src: (intrinsic_wo_chain:v4i32 2296:iPTR, v16i8:v16i8:$vA, v4i32:v4i32:$vB) - Complexity = 8
              // Dst: (VSUM4SBS:v4i32 v16i8:v16i8:$vA, v4i32:v4i32:$vB)
/*10581*/   /*Scope*/ 17, /*->10599*/
/*10582*/     OPC_CheckInteger, 121|128,17/*2297*/, 
/*10585*/     OPC_MoveParent,
/*10586*/     OPC_RecordChild1, // #0 = $vA
/*10587*/     OPC_RecordChild2, // #1 = $vB
/*10588*/     OPC_CheckPatternPredicate, 0, // (PPCSubTarget.hasAltivec())
/*10590*/     OPC_MorphNodeTo, TARGET_VAL(PPC::VSUM4SHS), 0,
                  1/*#VTs*/, MVT::v4i32, 2/*#Ops*/, 0, 1, 
              // Src: (intrinsic_wo_chain:v4i32 2297:iPTR, v8i16:v8i16:$vA, v4i32:v4i32:$vB) - Complexity = 8
              // Dst: (VSUM4SHS:v4i32 v8i16:v8i16:$vA, v4i32:v4i32:$vB)
/*10599*/   /*Scope*/ 17, /*->10617*/
/*10600*/     OPC_CheckInteger, 122|128,17/*2298*/, 
/*10603*/     OPC_MoveParent,
/*10604*/     OPC_RecordChild1, // #0 = $vA
/*10605*/     OPC_RecordChild2, // #1 = $vB
/*10606*/     OPC_CheckPatternPredicate, 0, // (PPCSubTarget.hasAltivec())
/*10608*/     OPC_MorphNodeTo, TARGET_VAL(PPC::VSUM4UBS), 0,
                  1/*#VTs*/, MVT::v4i32, 2/*#Ops*/, 0, 1, 
              // Src: (intrinsic_wo_chain:v4i32 2298:iPTR, v16i8:v16i8:$vA, v4i32:v4i32:$vB) - Complexity = 8
              // Dst: (VSUM4UBS:v4i32 v16i8:v16i8:$vA, v4i32:v4i32:$vB)
/*10617*/   /*Scope*/ 17, /*->10635*/
/*10618*/     OPC_CheckInteger, 94|128,17/*2270*/, 
/*10621*/     OPC_MoveParent,
/*10622*/     OPC_RecordChild1, // #0 = $vA
/*10623*/     OPC_RecordChild2, // #1 = $vB
/*10624*/     OPC_CheckPatternPredicate, 0, // (PPCSubTarget.hasAltivec())
/*10626*/     OPC_MorphNodeTo, TARGET_VAL(PPC::VRLB), 0,
                  1/*#VTs*/, MVT::v16i8, 2/*#Ops*/, 0, 1, 
              // Src: (intrinsic_wo_chain:v16i8 2270:iPTR, v16i8:v16i8:$vA, v16i8:v16i8:$vB) - Complexity = 8
              // Dst: (VRLB:v16i8 v16i8:v16i8:$vA, v16i8:v16i8:$vB)
/*10635*/   /*Scope*/ 17, /*->10653*/
/*10636*/     OPC_CheckInteger, 95|128,17/*2271*/, 
/*10639*/     OPC_MoveParent,
/*10640*/     OPC_RecordChild1, // #0 = $vA
/*10641*/     OPC_RecordChild2, // #1 = $vB
/*10642*/     OPC_CheckPatternPredicate, 0, // (PPCSubTarget.hasAltivec())
/*10644*/     OPC_MorphNodeTo, TARGET_VAL(PPC::VRLH), 0,
                  1/*#VTs*/, MVT::v8i16, 2/*#Ops*/, 0, 1, 
              // Src: (intrinsic_wo_chain:v8i16 2271:iPTR, v8i16:v8i16:$vA, v8i16:v8i16:$vB) - Complexity = 8
              // Dst: (VRLH:v8i16 v8i16:v8i16:$vA, v8i16:v8i16:$vB)
/*10653*/   /*Scope*/ 17, /*->10671*/
/*10654*/     OPC_CheckInteger, 96|128,17/*2272*/, 
/*10657*/     OPC_MoveParent,
/*10658*/     OPC_RecordChild1, // #0 = $vA
/*10659*/     OPC_RecordChild2, // #1 = $vB
/*10660*/     OPC_CheckPatternPredicate, 0, // (PPCSubTarget.hasAltivec())
/*10662*/     OPC_MorphNodeTo, TARGET_VAL(PPC::VRLW), 0,
                  1/*#VTs*/, MVT::v4i32, 2/*#Ops*/, 0, 1, 
              // Src: (intrinsic_wo_chain:v4i32 2272:iPTR, v4i32:v4i32:$vA, v4i32:v4i32:$vB) - Complexity = 8
              // Dst: (VRLW:v4i32 v4i32:v4i32:$vA, v4i32:v4i32:$vB)
/*10671*/   /*Scope*/ 17, /*->10689*/
/*10672*/     OPC_CheckInteger, 99|128,17/*2275*/, 
/*10675*/     OPC_MoveParent,
/*10676*/     OPC_RecordChild1, // #0 = $vA
/*10677*/     OPC_RecordChild2, // #1 = $vB
/*10678*/     OPC_CheckPatternPredicate, 0, // (PPCSubTarget.hasAltivec())
/*10680*/     OPC_MorphNodeTo, TARGET_VAL(PPC::VSL), 0,
                  1/*#VTs*/, MVT::v4i32, 2/*#Ops*/, 0, 1, 
              // Src: (intrinsic_wo_chain:v4i32 2275:iPTR, v4i32:v4i32:$vA, v4i32:v4i32:$vB) - Complexity = 8
              // Dst: (VSL:v4i32 v4i32:v4i32:$vA, v4i32:v4i32:$vB)
/*10689*/   /*Scope*/ 17, /*->10707*/
/*10690*/     OPC_CheckInteger, 102|128,17/*2278*/, 
/*10693*/     OPC_MoveParent,
/*10694*/     OPC_RecordChild1, // #0 = $vA
/*10695*/     OPC_RecordChild2, // #1 = $vB
/*10696*/     OPC_CheckPatternPredicate, 0, // (PPCSubTarget.hasAltivec())
/*10698*/     OPC_MorphNodeTo, TARGET_VAL(PPC::VSLO), 0,
                  1/*#VTs*/, MVT::v4i32, 2/*#Ops*/, 0, 1, 
              // Src: (intrinsic_wo_chain:v4i32 2278:iPTR, v4i32:v4i32:$vA, v4i32:v4i32:$vB) - Complexity = 8
              // Dst: (VSLO:v4i32 v4i32:v4i32:$vA, v4i32:v4i32:$vB)
/*10707*/   /*Scope*/ 17, /*->10725*/
/*10708*/     OPC_CheckInteger, 100|128,17/*2276*/, 
/*10711*/     OPC_MoveParent,
/*10712*/     OPC_RecordChild1, // #0 = $vA
/*10713*/     OPC_RecordChild2, // #1 = $vB
/*10714*/     OPC_CheckPatternPredicate, 0, // (PPCSubTarget.hasAltivec())
/*10716*/     OPC_MorphNodeTo, TARGET_VAL(PPC::VSLB), 0,
                  1/*#VTs*/, MVT::v16i8, 2/*#Ops*/, 0, 1, 
              // Src: (intrinsic_wo_chain:v16i8 2276:iPTR, v16i8:v16i8:$vA, v16i8:v16i8:$vB) - Complexity = 8
              // Dst: (VSLB:v16i8 v16i8:v16i8:$vA, v16i8:v16i8:$vB)
/*10725*/   /*Scope*/ 17, /*->10743*/
/*10726*/     OPC_CheckInteger, 101|128,17/*2277*/, 
/*10729*/     OPC_MoveParent,
/*10730*/     OPC_RecordChild1, // #0 = $vA
/*10731*/     OPC_RecordChild2, // #1 = $vB
/*10732*/     OPC_CheckPatternPredicate, 0, // (PPCSubTarget.hasAltivec())
/*10734*/     OPC_MorphNodeTo, TARGET_VAL(PPC::VSLH), 0,
                  1/*#VTs*/, MVT::v8i16, 2/*#Ops*/, 0, 1, 
              // Src: (intrinsic_wo_chain:v8i16 2277:iPTR, v8i16:v8i16:$vA, v8i16:v8i16:$vB) - Complexity = 8
              // Dst: (VSLH:v8i16 v8i16:v8i16:$vA, v8i16:v8i16:$vB)
/*10743*/   /*Scope*/ 17, /*->10761*/
/*10744*/     OPC_CheckInteger, 103|128,17/*2279*/, 
/*10747*/     OPC_MoveParent,
/*10748*/     OPC_RecordChild1, // #0 = $vA
/*10749*/     OPC_RecordChild2, // #1 = $vB
/*10750*/     OPC_CheckPatternPredicate, 0, // (PPCSubTarget.hasAltivec())
/*10752*/     OPC_MorphNodeTo, TARGET_VAL(PPC::VSLW), 0,
                  1/*#VTs*/, MVT::v4i32, 2/*#Ops*/, 0, 1, 
              // Src: (intrinsic_wo_chain:v4i32 2279:iPTR, v4i32:v4i32:$vA, v4i32:v4i32:$vB) - Complexity = 8
              // Dst: (VSLW:v4i32 v4i32:v4i32:$vA, v4i32:v4i32:$vB)
/*10761*/   /*Scope*/ 17, /*->10779*/
/*10762*/     OPC_CheckInteger, 104|128,17/*2280*/, 
/*10765*/     OPC_MoveParent,
/*10766*/     OPC_RecordChild1, // #0 = $vA
/*10767*/     OPC_RecordChild2, // #1 = $vB
/*10768*/     OPC_CheckPatternPredicate, 0, // (PPCSubTarget.hasAltivec())
/*10770*/     OPC_MorphNodeTo, TARGET_VAL(PPC::VSR), 0,
                  1/*#VTs*/, MVT::v4i32, 2/*#Ops*/, 0, 1, 
              // Src: (intrinsic_wo_chain:v4i32 2280:iPTR, v4i32:v4i32:$vA, v4i32:v4i32:$vB) - Complexity = 8
              // Dst: (VSR:v4i32 v4i32:v4i32:$vA, v4i32:v4i32:$vB)
/*10779*/   /*Scope*/ 17, /*->10797*/
/*10780*/     OPC_CheckInteger, 110|128,17/*2286*/, 
/*10783*/     OPC_MoveParent,
/*10784*/     OPC_RecordChild1, // #0 = $vA
/*10785*/     OPC_RecordChild2, // #1 = $vB
/*10786*/     OPC_CheckPatternPredicate, 0, // (PPCSubTarget.hasAltivec())
/*10788*/     OPC_MorphNodeTo, TARGET_VAL(PPC::VSRO), 0,
                  1/*#VTs*/, MVT::v4i32, 2/*#Ops*/, 0, 1, 
              // Src: (intrinsic_wo_chain:v4i32 2286:iPTR, v4i32:v4i32:$vA, v4i32:v4i32:$vB) - Complexity = 8
              // Dst: (VSRO:v4i32 v4i32:v4i32:$vA, v4i32:v4i32:$vB)
/*10797*/   /*Scope*/ 17, /*->10815*/
/*10798*/     OPC_CheckInteger, 105|128,17/*2281*/, 
/*10801*/     OPC_MoveParent,
/*10802*/     OPC_RecordChild1, // #0 = $vA
/*10803*/     OPC_RecordChild2, // #1 = $vB
/*10804*/     OPC_CheckPatternPredicate, 0, // (PPCSubTarget.hasAltivec())
/*10806*/     OPC_MorphNodeTo, TARGET_VAL(PPC::VSRAB), 0,
                  1/*#VTs*/, MVT::v16i8, 2/*#Ops*/, 0, 1, 
              // Src: (intrinsic_wo_chain:v16i8 2281:iPTR, v16i8:v16i8:$vA, v16i8:v16i8:$vB) - Complexity = 8
              // Dst: (VSRAB:v16i8 v16i8:v16i8:$vA, v16i8:v16i8:$vB)
/*10815*/   /*Scope*/ 17, /*->10833*/
/*10816*/     OPC_CheckInteger, 106|128,17/*2282*/, 
/*10819*/     OPC_MoveParent,
/*10820*/     OPC_RecordChild1, // #0 = $vA
/*10821*/     OPC_RecordChild2, // #1 = $vB
/*10822*/     OPC_CheckPatternPredicate, 0, // (PPCSubTarget.hasAltivec())
/*10824*/     OPC_MorphNodeTo, TARGET_VAL(PPC::VSRAH), 0,
                  1/*#VTs*/, MVT::v8i16, 2/*#Ops*/, 0, 1, 
              // Src: (intrinsic_wo_chain:v8i16 2282:iPTR, v8i16:v8i16:$vA, v8i16:v8i16:$vB) - Complexity = 8
              // Dst: (VSRAH:v8i16 v8i16:v8i16:$vA, v8i16:v8i16:$vB)
/*10833*/   /*Scope*/ 17, /*->10851*/
/*10834*/     OPC_CheckInteger, 107|128,17/*2283*/, 
/*10837*/     OPC_MoveParent,
/*10838*/     OPC_RecordChild1, // #0 = $vA
/*10839*/     OPC_RecordChild2, // #1 = $vB
/*10840*/     OPC_CheckPatternPredicate, 0, // (PPCSubTarget.hasAltivec())
/*10842*/     OPC_MorphNodeTo, TARGET_VAL(PPC::VSRAW), 0,
                  1/*#VTs*/, MVT::v4i32, 2/*#Ops*/, 0, 1, 
              // Src: (intrinsic_wo_chain:v4i32 2283:iPTR, v4i32:v4i32:$vA, v4i32:v4i32:$vB) - Complexity = 8
              // Dst: (VSRAW:v4i32 v4i32:v4i32:$vA, v4i32:v4i32:$vB)
/*10851*/   /*Scope*/ 17, /*->10869*/
/*10852*/     OPC_CheckInteger, 108|128,17/*2284*/, 
/*10855*/     OPC_MoveParent,
/*10856*/     OPC_RecordChild1, // #0 = $vA
/*10857*/     OPC_RecordChild2, // #1 = $vB
/*10858*/     OPC_CheckPatternPredicate, 0, // (PPCSubTarget.hasAltivec())
/*10860*/     OPC_MorphNodeTo, TARGET_VAL(PPC::VSRB), 0,
                  1/*#VTs*/, MVT::v16i8, 2/*#Ops*/, 0, 1, 
              // Src: (intrinsic_wo_chain:v16i8 2284:iPTR, v16i8:v16i8:$vA, v16i8:v16i8:$vB) - Complexity = 8
              // Dst: (VSRB:v16i8 v16i8:v16i8:$vA, v16i8:v16i8:$vB)
/*10869*/   /*Scope*/ 17, /*->10887*/
/*10870*/     OPC_CheckInteger, 109|128,17/*2285*/, 
/*10873*/     OPC_MoveParent,
/*10874*/     OPC_RecordChild1, // #0 = $vA
/*10875*/     OPC_RecordChild2, // #1 = $vB
/*10876*/     OPC_CheckPatternPredicate, 0, // (PPCSubTarget.hasAltivec())
/*10878*/     OPC_MorphNodeTo, TARGET_VAL(PPC::VSRH), 0,
                  1/*#VTs*/, MVT::v8i16, 2/*#Ops*/, 0, 1, 
              // Src: (intrinsic_wo_chain:v8i16 2285:iPTR, v8i16:v8i16:$vA, v8i16:v8i16:$vB) - Complexity = 8
              // Dst: (VSRH:v8i16 v8i16:v8i16:$vA, v8i16:v8i16:$vB)
/*10887*/   /*Scope*/ 17, /*->10905*/
/*10888*/     OPC_CheckInteger, 111|128,17/*2287*/, 
/*10891*/     OPC_MoveParent,
/*10892*/     OPC_RecordChild1, // #0 = $vA
/*10893*/     OPC_RecordChild2, // #1 = $vB
/*10894*/     OPC_CheckPatternPredicate, 0, // (PPCSubTarget.hasAltivec())
/*10896*/     OPC_MorphNodeTo, TARGET_VAL(PPC::VSRW), 0,
                  1/*#VTs*/, MVT::v4i32, 2/*#Ops*/, 0, 1, 
              // Src: (intrinsic_wo_chain:v4i32 2287:iPTR, v4i32:v4i32:$vA, v4i32:v4i32:$vB) - Complexity = 8
              // Dst: (VSRW:v4i32 v4i32:v4i32:$vA, v4i32:v4i32:$vB)
/*10905*/   /*Scope*/ 17, /*->10923*/
/*10906*/     OPC_CheckInteger, 82|128,17/*2258*/, 
/*10909*/     OPC_MoveParent,
/*10910*/     OPC_RecordChild1, // #0 = $vA
/*10911*/     OPC_RecordChild2, // #1 = $vB
/*10912*/     OPC_CheckPatternPredicate, 0, // (PPCSubTarget.hasAltivec())
/*10914*/     OPC_MorphNodeTo, TARGET_VAL(PPC::VPKPX), 0,
                  1/*#VTs*/, MVT::v8i16, 2/*#Ops*/, 0, 1, 
              // Src: (intrinsic_wo_chain:v8i16 2258:iPTR, v4i32:v4i32:$vA, v4i32:v4i32:$vB) - Complexity = 8
              // Dst: (VPKPX:v8i16 v4i32:v4i32:$vA, v4i32:v4i32:$vB)
/*10923*/   /*Scope*/ 17, /*->10941*/
/*10924*/     OPC_CheckInteger, 83|128,17/*2259*/, 
/*10927*/     OPC_MoveParent,
/*10928*/     OPC_RecordChild1, // #0 = $vA
/*10929*/     OPC_RecordChild2, // #1 = $vB
/*10930*/     OPC_CheckPatternPredicate, 0, // (PPCSubTarget.hasAltivec())
/*10932*/     OPC_MorphNodeTo, TARGET_VAL(PPC::VPKSHSS), 0,
                  1/*#VTs*/, MVT::v16i8, 2/*#Ops*/, 0, 1, 
              // Src: (intrinsic_wo_chain:v16i8 2259:iPTR, v8i16:v8i16:$vA, v8i16:v8i16:$vB) - Complexity = 8
              // Dst: (VPKSHSS:v16i8 v8i16:v8i16:$vA, v8i16:v8i16:$vB)
/*10941*/   /*Scope*/ 17, /*->10959*/
/*10942*/     OPC_CheckInteger, 84|128,17/*2260*/, 
/*10945*/     OPC_MoveParent,
/*10946*/     OPC_RecordChild1, // #0 = $vA
/*10947*/     OPC_RecordChild2, // #1 = $vB
/*10948*/     OPC_CheckPatternPredicate, 0, // (PPCSubTarget.hasAltivec())
/*10950*/     OPC_MorphNodeTo, TARGET_VAL(PPC::VPKSHUS), 0,
                  1/*#VTs*/, MVT::v16i8, 2/*#Ops*/, 0, 1, 
              // Src: (intrinsic_wo_chain:v16i8 2260:iPTR, v8i16:v8i16:$vA, v8i16:v8i16:$vB) - Complexity = 8
              // Dst: (VPKSHUS:v16i8 v8i16:v8i16:$vA, v8i16:v8i16:$vB)
/*10959*/   /*Scope*/ 17, /*->10977*/
/*10960*/     OPC_CheckInteger, 85|128,17/*2261*/, 
/*10963*/     OPC_MoveParent,
/*10964*/     OPC_RecordChild1, // #0 = $vA
/*10965*/     OPC_RecordChild2, // #1 = $vB
/*10966*/     OPC_CheckPatternPredicate, 0, // (PPCSubTarget.hasAltivec())
/*10968*/     OPC_MorphNodeTo, TARGET_VAL(PPC::VPKSWSS), 0,
                  1/*#VTs*/, MVT::v16i8, 2/*#Ops*/, 0, 1, 
              // Src: (intrinsic_wo_chain:v16i8 2261:iPTR, v4i32:v4i32:$vA, v4i32:v4i32:$vB) - Complexity = 8
              // Dst: (VPKSWSS:v16i8 v4i32:v4i32:$vA, v4i32:v4i32:$vB)
/*10977*/   /*Scope*/ 17, /*->10995*/
/*10978*/     OPC_CheckInteger, 86|128,17/*2262*/, 
/*10981*/     OPC_MoveParent,
/*10982*/     OPC_RecordChild1, // #0 = $vA
/*10983*/     OPC_RecordChild2, // #1 = $vB
/*10984*/     OPC_CheckPatternPredicate, 0, // (PPCSubTarget.hasAltivec())
/*10986*/     OPC_MorphNodeTo, TARGET_VAL(PPC::VPKSWUS), 0,
                  1/*#VTs*/, MVT::v8i16, 2/*#Ops*/, 0, 1, 
              // Src: (intrinsic_wo_chain:v8i16 2262:iPTR, v4i32:v4i32:$vA, v4i32:v4i32:$vB) - Complexity = 8
              // Dst: (VPKSWUS:v8i16 v4i32:v4i32:$vA, v4i32:v4i32:$vB)
/*10995*/   /*Scope*/ 17, /*->11013*/
/*10996*/     OPC_CheckInteger, 87|128,17/*2263*/, 
/*10999*/     OPC_MoveParent,
/*11000*/     OPC_RecordChild1, // #0 = $vA
/*11001*/     OPC_RecordChild2, // #1 = $vB
/*11002*/     OPC_CheckPatternPredicate, 0, // (PPCSubTarget.hasAltivec())
/*11004*/     OPC_MorphNodeTo, TARGET_VAL(PPC::VPKUHUS), 0,
                  1/*#VTs*/, MVT::v16i8, 2/*#Ops*/, 0, 1, 
              // Src: (intrinsic_wo_chain:v16i8 2263:iPTR, v8i16:v8i16:$vA, v8i16:v8i16:$vB) - Complexity = 8
              // Dst: (VPKUHUS:v16i8 v8i16:v8i16:$vA, v8i16:v8i16:$vB)
/*11013*/   /*Scope*/ 17, /*->11031*/
/*11014*/     OPC_CheckInteger, 88|128,17/*2264*/, 
/*11017*/     OPC_MoveParent,
/*11018*/     OPC_RecordChild1, // #0 = $vA
/*11019*/     OPC_RecordChild2, // #1 = $vB
/*11020*/     OPC_CheckPatternPredicate, 0, // (PPCSubTarget.hasAltivec())
/*11022*/     OPC_MorphNodeTo, TARGET_VAL(PPC::VPKUWUS), 0,
                  1/*#VTs*/, MVT::v8i16, 2/*#Ops*/, 0, 1, 
              // Src: (intrinsic_wo_chain:v8i16 2264:iPTR, v4i32:v4i32:$vA, v4i32:v4i32:$vB) - Complexity = 8
              // Dst: (VPKUWUS:v8i16 v4i32:v4i32:$vA, v4i32:v4i32:$vB)
/*11031*/   /*Scope*/ 15, /*->11047*/
/*11032*/     OPC_CheckInteger, 124|128,17/*2300*/, 
/*11035*/     OPC_MoveParent,
/*11036*/     OPC_RecordChild1, // #0 = $vB
/*11037*/     OPC_CheckPatternPredicate, 0, // (PPCSubTarget.hasAltivec())
/*11039*/     OPC_MorphNodeTo, TARGET_VAL(PPC::VUPKHPX), 0,
                  1/*#VTs*/, MVT::v4i32, 1/*#Ops*/, 0, 
              // Src: (intrinsic_wo_chain:v4i32 2300:iPTR, v8i16:v8i16:$vB) - Complexity = 8
              // Dst: (VUPKHPX:v4i32 v8i16:v8i16:$vB)
/*11047*/   /*Scope*/ 15, /*->11063*/
/*11048*/     OPC_CheckInteger, 125|128,17/*2301*/, 
/*11051*/     OPC_MoveParent,
/*11052*/     OPC_RecordChild1, // #0 = $vB
/*11053*/     OPC_CheckPatternPredicate, 0, // (PPCSubTarget.hasAltivec())
/*11055*/     OPC_MorphNodeTo, TARGET_VAL(PPC::VUPKHSB), 0,
                  1/*#VTs*/, MVT::v8i16, 1/*#Ops*/, 0, 
              // Src: (intrinsic_wo_chain:v8i16 2301:iPTR, v16i8:v16i8:$vB) - Complexity = 8
              // Dst: (VUPKHSB:v8i16 v16i8:v16i8:$vB)
/*11063*/   /*Scope*/ 15, /*->11079*/
/*11064*/     OPC_CheckInteger, 126|128,17/*2302*/, 
/*11067*/     OPC_MoveParent,
/*11068*/     OPC_RecordChild1, // #0 = $vB
/*11069*/     OPC_CheckPatternPredicate, 0, // (PPCSubTarget.hasAltivec())
/*11071*/     OPC_MorphNodeTo, TARGET_VAL(PPC::VUPKHSH), 0,
                  1/*#VTs*/, MVT::v4i32, 1/*#Ops*/, 0, 
              // Src: (intrinsic_wo_chain:v4i32 2302:iPTR, v8i16:v8i16:$vB) - Complexity = 8
              // Dst: (VUPKHSH:v4i32 v8i16:v8i16:$vB)
/*11079*/   /*Scope*/ 15, /*->11095*/
/*11080*/     OPC_CheckInteger, 127|128,17/*2303*/, 
/*11083*/     OPC_MoveParent,
/*11084*/     OPC_RecordChild1, // #0 = $vB
/*11085*/     OPC_CheckPatternPredicate, 0, // (PPCSubTarget.hasAltivec())
/*11087*/     OPC_MorphNodeTo, TARGET_VAL(PPC::VUPKLPX), 0,
                  1/*#VTs*/, MVT::v4i32, 1/*#Ops*/, 0, 
              // Src: (intrinsic_wo_chain:v4i32 2303:iPTR, v8i16:v8i16:$vB) - Complexity = 8
              // Dst: (VUPKLPX:v4i32 v8i16:v8i16:$vB)
/*11095*/   /*Scope*/ 15, /*->11111*/
/*11096*/     OPC_CheckInteger, 0|128,18/*2304*/, 
/*11099*/     OPC_MoveParent,
/*11100*/     OPC_RecordChild1, // #0 = $vB
/*11101*/     OPC_CheckPatternPredicate, 0, // (PPCSubTarget.hasAltivec())
/*11103*/     OPC_MorphNodeTo, TARGET_VAL(PPC::VUPKLSB), 0,
                  1/*#VTs*/, MVT::v8i16, 1/*#Ops*/, 0, 
              // Src: (intrinsic_wo_chain:v8i16 2304:iPTR, v16i8:v16i8:$vB) - Complexity = 8
              // Dst: (VUPKLSB:v8i16 v16i8:v16i8:$vB)
/*11111*/   /*Scope*/ 15, /*->11127*/
/*11112*/     OPC_CheckInteger, 1|128,18/*2305*/, 
/*11115*/     OPC_MoveParent,
/*11116*/     OPC_RecordChild1, // #0 = $vB
/*11117*/     OPC_CheckPatternPredicate, 0, // (PPCSubTarget.hasAltivec())
/*11119*/     OPC_MorphNodeTo, TARGET_VAL(PPC::VUPKLSH), 0,
                  1/*#VTs*/, MVT::v4i32, 1/*#Ops*/, 0, 
              // Src: (intrinsic_wo_chain:v4i32 2305:iPTR, v8i16:v8i16:$vB) - Complexity = 8
              // Dst: (VUPKLSH:v4i32 v8i16:v8i16:$vB)
/*11127*/   /*Scope*/ 44, /*->11172*/
/*11128*/     OPC_CheckInteger, 16|128,17/*2192*/, 
/*11131*/     OPC_MoveParent,
/*11132*/     OPC_RecordChild1, // #0 = $vB
/*11133*/     OPC_Scope, 15, /*->11150*/ // 2 children in Scope
/*11135*/       OPC_MoveChild, 2,
/*11137*/       OPC_CheckInteger, 0, 
/*11139*/       OPC_MoveParent,
/*11140*/       OPC_CheckPatternPredicate, 0, // (PPCSubTarget.hasAltivec())
/*11142*/       OPC_MorphNodeTo, TARGET_VAL(PPC::VCFSX_0), 0,
                    1/*#VTs*/, MVT::v4f32, 1/*#Ops*/, 0, 
                // Src: (intrinsic_wo_chain:v4f32 2192:iPTR, v4i32:v4i32:$vB, 0:i32) - Complexity = 13
                // Dst: (VCFSX_0:v4f32 v4i32:v4i32:$vB)
/*11150*/     /*Scope*/ 20, /*->11171*/
/*11151*/       OPC_RecordChild2, // #1 = $UIMM
/*11152*/       OPC_MoveChild, 2,
/*11154*/       OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*11157*/       OPC_MoveParent,
/*11158*/       OPC_CheckPatternPredicate, 0, // (PPCSubTarget.hasAltivec())
/*11160*/       OPC_EmitConvertToTarget, 1,
/*11162*/       OPC_MorphNodeTo, TARGET_VAL(PPC::VCFSX), 0,
                    1/*#VTs*/, MVT::v4f32, 2/*#Ops*/, 2, 0, 
                // Src: (intrinsic_wo_chain:v4f32 2192:iPTR, v4i32:v4i32:$vB, (imm:i32):$UIMM) - Complexity = 11
                // Dst: (VCFSX:v4f32 (imm:i32):$UIMM, v4i32:v4i32:$vB)
/*11171*/     0, /*End of Scope*/
/*11172*/   /*Scope*/ 44, /*->11217*/
/*11173*/     OPC_CheckInteger, 17|128,17/*2193*/, 
/*11176*/     OPC_MoveParent,
/*11177*/     OPC_RecordChild1, // #0 = $vB
/*11178*/     OPC_Scope, 15, /*->11195*/ // 2 children in Scope
/*11180*/       OPC_MoveChild, 2,
/*11182*/       OPC_CheckInteger, 0, 
/*11184*/       OPC_MoveParent,
/*11185*/       OPC_CheckPatternPredicate, 0, // (PPCSubTarget.hasAltivec())
/*11187*/       OPC_MorphNodeTo, TARGET_VAL(PPC::VCFUX_0), 0,
                    1/*#VTs*/, MVT::v4f32, 1/*#Ops*/, 0, 
                // Src: (intrinsic_wo_chain:v4f32 2193:iPTR, v4i32:v4i32:$vB, 0:i32) - Complexity = 13
                // Dst: (VCFUX_0:v4f32 v4i32:v4i32:$vB)
/*11195*/     /*Scope*/ 20, /*->11216*/
/*11196*/       OPC_RecordChild2, // #1 = $UIMM
/*11197*/       OPC_MoveChild, 2,
/*11199*/       OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*11202*/       OPC_MoveParent,
/*11203*/       OPC_CheckPatternPredicate, 0, // (PPCSubTarget.hasAltivec())
/*11205*/       OPC_EmitConvertToTarget, 1,
/*11207*/       OPC_MorphNodeTo, TARGET_VAL(PPC::VCFUX), 0,
                    1/*#VTs*/, MVT::v4f32, 2/*#Ops*/, 2, 0, 
                // Src: (intrinsic_wo_chain:v4f32 2193:iPTR, v4i32:v4i32:$vB, (imm:i32):$UIMM) - Complexity = 11
                // Dst: (VCFUX:v4f32 (imm:i32):$UIMM, v4i32:v4i32:$vB)
/*11216*/     0, /*End of Scope*/
/*11217*/   /*Scope*/ 15, /*->11233*/
/*11218*/     OPC_CheckInteger, 46|128,17/*2222*/, 
/*11221*/     OPC_MoveParent,
/*11222*/     OPC_RecordChild1, // #0 = $vB
/*11223*/     OPC_CheckPatternPredicate, 0, // (PPCSubTarget.hasAltivec())
/*11225*/     OPC_MorphNodeTo, TARGET_VAL(PPC::VEXPTEFP), 0,
                  1/*#VTs*/, MVT::v4f32, 1/*#Ops*/, 0, 
              // Src: (intrinsic_wo_chain:v4f32 2222:iPTR, v4f32:v4f32:$vB) - Complexity = 8
              // Dst: (VEXPTEFP:v4f32 v4f32:v4f32:$vB)
/*11233*/   /*Scope*/ 15, /*->11249*/
/*11234*/     OPC_CheckInteger, 47|128,17/*2223*/, 
/*11237*/     OPC_MoveParent,
/*11238*/     OPC_RecordChild1, // #0 = $vB
/*11239*/     OPC_CheckPatternPredicate, 0, // (PPCSubTarget.hasAltivec())
/*11241*/     OPC_MorphNodeTo, TARGET_VAL(PPC::VLOGEFP), 0,
                  1/*#VTs*/, MVT::v4f32, 1/*#Ops*/, 0, 
              // Src: (intrinsic_wo_chain:v4f32 2223:iPTR, v4f32:v4f32:$vB) - Complexity = 8
              // Dst: (VLOGEFP:v4f32 v4f32:v4f32:$vB)
/*11249*/   /*Scope*/ 17, /*->11267*/
/*11250*/     OPC_CheckInteger, 49|128,17/*2225*/, 
/*11253*/     OPC_MoveParent,
/*11254*/     OPC_RecordChild1, // #0 = $vA
/*11255*/     OPC_RecordChild2, // #1 = $vB
/*11256*/     OPC_CheckPatternPredicate, 0, // (PPCSubTarget.hasAltivec())
/*11258*/     OPC_MorphNodeTo, TARGET_VAL(PPC::VMAXFP), 0,
                  1/*#VTs*/, MVT::v4f32, 2/*#Ops*/, 0, 1, 
              // Src: (intrinsic_wo_chain:v4f32 2225:iPTR, v4f32:v4f32:$vA, v4f32:v4f32:$vB) - Complexity = 8
              // Dst: (VMAXFP:v4f32 v4f32:v4f32:$vA, v4f32:v4f32:$vB)
/*11267*/   /*Scope*/ 17, /*->11285*/
/*11268*/     OPC_CheckInteger, 58|128,17/*2234*/, 
/*11271*/     OPC_MoveParent,
/*11272*/     OPC_RecordChild1, // #0 = $vA
/*11273*/     OPC_RecordChild2, // #1 = $vB
/*11274*/     OPC_CheckPatternPredicate, 0, // (PPCSubTarget.hasAltivec())
/*11276*/     OPC_MorphNodeTo, TARGET_VAL(PPC::VMINFP), 0,
                  1/*#VTs*/, MVT::v4f32, 2/*#Ops*/, 0, 1, 
              // Src: (intrinsic_wo_chain:v4f32 2234:iPTR, v4f32:v4f32:$vA, v4f32:v4f32:$vB) - Complexity = 8
              // Dst: (VMINFP:v4f32 v4f32:v4f32:$vA, v4f32:v4f32:$vB)
/*11285*/   /*Scope*/ 15, /*->11301*/
/*11286*/     OPC_CheckInteger, 89|128,17/*2265*/, 
/*11289*/     OPC_MoveParent,
/*11290*/     OPC_RecordChild1, // #0 = $vB
/*11291*/     OPC_CheckPatternPredicate, 0, // (PPCSubTarget.hasAltivec())
/*11293*/     OPC_MorphNodeTo, TARGET_VAL(PPC::VREFP), 0,
                  1/*#VTs*/, MVT::v4f32, 1/*#Ops*/, 0, 
              // Src: (intrinsic_wo_chain:v4f32 2265:iPTR, v4f32:v4f32:$vB) - Complexity = 8
              // Dst: (VREFP:v4f32 v4f32:v4f32:$vB)
/*11301*/   /*Scope*/ 15, /*->11317*/
/*11302*/     OPC_CheckInteger, 90|128,17/*2266*/, 
/*11305*/     OPC_MoveParent,
/*11306*/     OPC_RecordChild1, // #0 = $vB
/*11307*/     OPC_CheckPatternPredicate, 0, // (PPCSubTarget.hasAltivec())
/*11309*/     OPC_MorphNodeTo, TARGET_VAL(PPC::VRFIM), 0,
                  1/*#VTs*/, MVT::v4f32, 1/*#Ops*/, 0, 
              // Src: (intrinsic_wo_chain:v4f32 2266:iPTR, v4f32:v4f32:$vB) - Complexity = 8
              // Dst: (VRFIM:v4f32 v4f32:v4f32:$vB)
/*11317*/   /*Scope*/ 15, /*->11333*/
/*11318*/     OPC_CheckInteger, 91|128,17/*2267*/, 
/*11321*/     OPC_MoveParent,
/*11322*/     OPC_RecordChild1, // #0 = $vB
/*11323*/     OPC_CheckPatternPredicate, 0, // (PPCSubTarget.hasAltivec())
/*11325*/     OPC_MorphNodeTo, TARGET_VAL(PPC::VRFIN), 0,
                  1/*#VTs*/, MVT::v4f32, 1/*#Ops*/, 0, 
              // Src: (intrinsic_wo_chain:v4f32 2267:iPTR, v4f32:v4f32:$vB) - Complexity = 8
              // Dst: (VRFIN:v4f32 v4f32:v4f32:$vB)
/*11333*/   /*Scope*/ 15, /*->11349*/
/*11334*/     OPC_CheckInteger, 92|128,17/*2268*/, 
/*11337*/     OPC_MoveParent,
/*11338*/     OPC_RecordChild1, // #0 = $vB
/*11339*/     OPC_CheckPatternPredicate, 0, // (PPCSubTarget.hasAltivec())
/*11341*/     OPC_MorphNodeTo, TARGET_VAL(PPC::VRFIP), 0,
                  1/*#VTs*/, MVT::v4f32, 1/*#Ops*/, 0, 
              // Src: (intrinsic_wo_chain:v4f32 2268:iPTR, v4f32:v4f32:$vB) - Complexity = 8
              // Dst: (VRFIP:v4f32 v4f32:v4f32:$vB)
/*11349*/   /*Scope*/ 15, /*->11365*/
/*11350*/     OPC_CheckInteger, 93|128,17/*2269*/, 
/*11353*/     OPC_MoveParent,
/*11354*/     OPC_RecordChild1, // #0 = $vB
/*11355*/     OPC_CheckPatternPredicate, 0, // (PPCSubTarget.hasAltivec())
/*11357*/     OPC_MorphNodeTo, TARGET_VAL(PPC::VRFIZ), 0,
                  1/*#VTs*/, MVT::v4f32, 1/*#Ops*/, 0, 
              // Src: (intrinsic_wo_chain:v4f32 2269:iPTR, v4f32:v4f32:$vB) - Complexity = 8
              // Dst: (VRFIZ:v4f32 v4f32:v4f32:$vB)
/*11365*/   /*Scope*/ 15, /*->11381*/
/*11366*/     OPC_CheckInteger, 97|128,17/*2273*/, 
/*11369*/     OPC_MoveParent,
/*11370*/     OPC_RecordChild1, // #0 = $vB
/*11371*/     OPC_CheckPatternPredicate, 0, // (PPCSubTarget.hasAltivec())
/*11373*/     OPC_MorphNodeTo, TARGET_VAL(PPC::VRSQRTEFP), 0,
                  1/*#VTs*/, MVT::v4f32, 1/*#Ops*/, 0, 
              // Src: (intrinsic_wo_chain:v4f32 2273:iPTR, v4f32:v4f32:$vB) - Complexity = 8
              // Dst: (VRSQRTEFP:v4f32 v4f32:v4f32:$vB)
/*11381*/   /*Scope*/ 19, /*->11401*/
/*11382*/     OPC_CheckInteger, 48|128,17/*2224*/, 
/*11385*/     OPC_MoveParent,
/*11386*/     OPC_RecordChild1, // #0 = $A
/*11387*/     OPC_RecordChild2, // #1 = $B
/*11388*/     OPC_RecordChild3, // #2 = $C
/*11389*/     OPC_CheckPatternPredicate, 0, // (PPCSubTarget.hasAltivec())
/*11391*/     OPC_MorphNodeTo, TARGET_VAL(PPC::VMADDFP), 0,
                  1/*#VTs*/, MVT::v4f32, 3/*#Ops*/, 0, 1, 2, 
              // Src: (intrinsic_wo_chain:v4f32 2224:iPTR, v4f32:v4f32:$A, v4f32:v4f32:$B, v4f32:v4f32:$C) - Complexity = 8
              // Dst: (VMADDFP:v4f32 ?:v4f32:$A, ?:v4f32:$B, ?:v4f32:$C)
/*11401*/   /*Scope*/ 19, /*->11421*/
/*11402*/     OPC_CheckInteger, 80|128,17/*2256*/, 
/*11405*/     OPC_MoveParent,
/*11406*/     OPC_RecordChild1, // #0 = $A
/*11407*/     OPC_RecordChild2, // #1 = $B
/*11408*/     OPC_RecordChild3, // #2 = $C
/*11409*/     OPC_CheckPatternPredicate, 0, // (PPCSubTarget.hasAltivec())
/*11411*/     OPC_MorphNodeTo, TARGET_VAL(PPC::VNMSUBFP), 0,
                  1/*#VTs*/, MVT::v4f32, 3/*#Ops*/, 0, 1, 2, 
              // Src: (intrinsic_wo_chain:v4f32 2256:iPTR, v4f32:v4f32:$A, v4f32:v4f32:$B, v4f32:v4f32:$C) - Complexity = 8
              // Dst: (VNMSUBFP:v4f32 ?:v4f32:$A, ?:v4f32:$B, ?:v4f32:$C)
/*11421*/   0, /*End of Scope*/
/*11422*/ /*SwitchOpcode*/ 110|128,1/*238*/,  TARGET_VAL(PPCISD::VCMP),// ->11664
/*11426*/   OPC_RecordChild0, // #0 = $vA
/*11427*/   OPC_RecordChild1, // #1 = $vB
/*11428*/   OPC_MoveChild, 2,
/*11430*/   OPC_Scope, 16, /*->11448*/ // 13 children in Scope
/*11432*/     OPC_CheckInteger, 6, 
/*11434*/     OPC_MoveParent,
/*11435*/     OPC_CheckType, MVT::v16i8,
/*11437*/     OPC_CheckPatternPredicate, 0, // (PPCSubTarget.hasAltivec())
/*11439*/     OPC_MorphNodeTo, TARGET_VAL(PPC::VCMPEQUB), 0,
                  1/*#VTs*/, MVT::v16i8, 2/*#Ops*/, 0, 1, 
              // Src: (PPCvcmp:v16i8 v16i8:v16i8:$vA, v16i8:v16i8:$vB, 6:i32) - Complexity = 8
              // Dst: (VCMPEQUB:v16i8 v16i8:v16i8:$vA, v16i8:v16i8:$vB)
/*11448*/   /*Scope*/ 17, /*->11466*/
/*11449*/     OPC_CheckInteger, 6|128,6/*774*/, 
/*11452*/     OPC_MoveParent,
/*11453*/     OPC_CheckType, MVT::v16i8,
/*11455*/     OPC_CheckPatternPredicate, 0, // (PPCSubTarget.hasAltivec())
/*11457*/     OPC_MorphNodeTo, TARGET_VAL(PPC::VCMPGTSB), 0,
                  1/*#VTs*/, MVT::v16i8, 2/*#Ops*/, 0, 1, 
              // Src: (PPCvcmp:v16i8 v16i8:v16i8:$vA, v16i8:v16i8:$vB, 774:i32) - Complexity = 8
              // Dst: (VCMPGTSB:v16i8 v16i8:v16i8:$vA, v16i8:v16i8:$vB)
/*11466*/   /*Scope*/ 17, /*->11484*/
/*11467*/     OPC_CheckInteger, 6|128,4/*518*/, 
/*11470*/     OPC_MoveParent,
/*11471*/     OPC_CheckType, MVT::v16i8,
/*11473*/     OPC_CheckPatternPredicate, 0, // (PPCSubTarget.hasAltivec())
/*11475*/     OPC_MorphNodeTo, TARGET_VAL(PPC::VCMPGTUB), 0,
                  1/*#VTs*/, MVT::v16i8, 2/*#Ops*/, 0, 1, 
              // Src: (PPCvcmp:v16i8 v16i8:v16i8:$vA, v16i8:v16i8:$vB, 518:i32) - Complexity = 8
              // Dst: (VCMPGTUB:v16i8 v16i8:v16i8:$vA, v16i8:v16i8:$vB)
/*11484*/   /*Scope*/ 16, /*->11501*/
/*11485*/     OPC_CheckInteger, 70, 
/*11487*/     OPC_MoveParent,
/*11488*/     OPC_CheckType, MVT::v8i16,
/*11490*/     OPC_CheckPatternPredicate, 0, // (PPCSubTarget.hasAltivec())
/*11492*/     OPC_MorphNodeTo, TARGET_VAL(PPC::VCMPEQUH), 0,
                  1/*#VTs*/, MVT::v8i16, 2/*#Ops*/, 0, 1, 
              // Src: (PPCvcmp:v8i16 v8i16:v8i16:$vA, v8i16:v8i16:$vB, 70:i32) - Complexity = 8
              // Dst: (VCMPEQUH:v8i16 v8i16:v8i16:$vA, v8i16:v8i16:$vB)
/*11501*/   /*Scope*/ 17, /*->11519*/
/*11502*/     OPC_CheckInteger, 70|128,6/*838*/, 
/*11505*/     OPC_MoveParent,
/*11506*/     OPC_CheckType, MVT::v8i16,
/*11508*/     OPC_CheckPatternPredicate, 0, // (PPCSubTarget.hasAltivec())
/*11510*/     OPC_MorphNodeTo, TARGET_VAL(PPC::VCMPGTSH), 0,
                  1/*#VTs*/, MVT::v8i16, 2/*#Ops*/, 0, 1, 
              // Src: (PPCvcmp:v8i16 v8i16:v8i16:$vA, v8i16:v8i16:$vB, 838:i32) - Complexity = 8
              // Dst: (VCMPGTSH:v8i16 v8i16:v8i16:$vA, v8i16:v8i16:$vB)
/*11519*/   /*Scope*/ 17, /*->11537*/
/*11520*/     OPC_CheckInteger, 70|128,4/*582*/, 
/*11523*/     OPC_MoveParent,
/*11524*/     OPC_CheckType, MVT::v8i16,
/*11526*/     OPC_CheckPatternPredicate, 0, // (PPCSubTarget.hasAltivec())
/*11528*/     OPC_MorphNodeTo, TARGET_VAL(PPC::VCMPGTUH), 0,
                  1/*#VTs*/, MVT::v8i16, 2/*#Ops*/, 0, 1, 
              // Src: (PPCvcmp:v8i16 v8i16:v8i16:$vA, v8i16:v8i16:$vB, 582:i32) - Complexity = 8
              // Dst: (VCMPGTUH:v8i16 v8i16:v8i16:$vA, v8i16:v8i16:$vB)
/*11537*/   /*Scope*/ 17, /*->11555*/
/*11538*/     OPC_CheckInteger, 6|128,1/*134*/, 
/*11541*/     OPC_MoveParent,
/*11542*/     OPC_CheckType, MVT::v4i32,
/*11544*/     OPC_CheckPatternPredicate, 0, // (PPCSubTarget.hasAltivec())
/*11546*/     OPC_MorphNodeTo, TARGET_VAL(PPC::VCMPEQUW), 0,
                  1/*#VTs*/, MVT::v4i32, 2/*#Ops*/, 0, 1, 
              // Src: (PPCvcmp:v4i32 v4i32:v4i32:$vA, v4i32:v4i32:$vB, 134:i32) - Complexity = 8
              // Dst: (VCMPEQUW:v4i32 v4i32:v4i32:$vA, v4i32:v4i32:$vB)
/*11555*/   /*Scope*/ 17, /*->11573*/
/*11556*/     OPC_CheckInteger, 6|128,7/*902*/, 
/*11559*/     OPC_MoveParent,
/*11560*/     OPC_CheckType, MVT::v4i32,
/*11562*/     OPC_CheckPatternPredicate, 0, // (PPCSubTarget.hasAltivec())
/*11564*/     OPC_MorphNodeTo, TARGET_VAL(PPC::VCMPGTSW), 0,
                  1/*#VTs*/, MVT::v4i32, 2/*#Ops*/, 0, 1, 
              // Src: (PPCvcmp:v4i32 v4i32:v4i32:$vA, v4i32:v4i32:$vB, 902:i32) - Complexity = 8
              // Dst: (VCMPGTSW:v4i32 v4i32:v4i32:$vA, v4i32:v4i32:$vB)
/*11573*/   /*Scope*/ 17, /*->11591*/
/*11574*/     OPC_CheckInteger, 6|128,5/*646*/, 
/*11577*/     OPC_MoveParent,
/*11578*/     OPC_CheckType, MVT::v4i32,
/*11580*/     OPC_CheckPatternPredicate, 0, // (PPCSubTarget.hasAltivec())
/*11582*/     OPC_MorphNodeTo, TARGET_VAL(PPC::VCMPGTUW), 0,
                  1/*#VTs*/, MVT::v4i32, 2/*#Ops*/, 0, 1, 
              // Src: (PPCvcmp:v4i32 v4i32:v4i32:$vA, v4i32:v4i32:$vB, 646:i32) - Complexity = 8
              // Dst: (VCMPGTUW:v4i32 v4i32:v4i32:$vA, v4i32:v4i32:$vB)
/*11591*/   /*Scope*/ 17, /*->11609*/
/*11592*/     OPC_CheckInteger, 70|128,7/*966*/, 
/*11595*/     OPC_MoveParent,
/*11596*/     OPC_CheckType, MVT::v4f32,
/*11598*/     OPC_CheckPatternPredicate, 0, // (PPCSubTarget.hasAltivec())
/*11600*/     OPC_MorphNodeTo, TARGET_VAL(PPC::VCMPBFP), 0,
                  1/*#VTs*/, MVT::v4f32, 2/*#Ops*/, 0, 1, 
              // Src: (PPCvcmp:v4f32 v4f32:v4f32:$vA, v4f32:v4f32:$vB, 966:i32) - Complexity = 8
              // Dst: (VCMPBFP:v4f32 v4f32:v4f32:$vA, v4f32:v4f32:$vB)
/*11609*/   /*Scope*/ 17, /*->11627*/
/*11610*/     OPC_CheckInteger, 70|128,1/*198*/, 
/*11613*/     OPC_MoveParent,
/*11614*/     OPC_CheckType, MVT::v4f32,
/*11616*/     OPC_CheckPatternPredicate, 0, // (PPCSubTarget.hasAltivec())
/*11618*/     OPC_MorphNodeTo, TARGET_VAL(PPC::VCMPEQFP), 0,
                  1/*#VTs*/, MVT::v4f32, 2/*#Ops*/, 0, 1, 
              // Src: (PPCvcmp:v4f32 v4f32:v4f32:$vA, v4f32:v4f32:$vB, 198:i32) - Complexity = 8
              // Dst: (VCMPEQFP:v4f32 v4f32:v4f32:$vA, v4f32:v4f32:$vB)
/*11627*/   /*Scope*/ 17, /*->11645*/
/*11628*/     OPC_CheckInteger, 70|128,3/*454*/, 
/*11631*/     OPC_MoveParent,
/*11632*/     OPC_CheckType, MVT::v4f32,
/*11634*/     OPC_CheckPatternPredicate, 0, // (PPCSubTarget.hasAltivec())
/*11636*/     OPC_MorphNodeTo, TARGET_VAL(PPC::VCMPGEFP), 0,
                  1/*#VTs*/, MVT::v4f32, 2/*#Ops*/, 0, 1, 
              // Src: (PPCvcmp:v4f32 v4f32:v4f32:$vA, v4f32:v4f32:$vB, 454:i32) - Complexity = 8
              // Dst: (VCMPGEFP:v4f32 v4f32:v4f32:$vA, v4f32:v4f32:$vB)
/*11645*/   /*Scope*/ 17, /*->11663*/
/*11646*/     OPC_CheckInteger, 70|128,5/*710*/, 
/*11649*/     OPC_MoveParent,
/*11650*/     OPC_CheckType, MVT::v4f32,
/*11652*/     OPC_CheckPatternPredicate, 0, // (PPCSubTarget.hasAltivec())
/*11654*/     OPC_MorphNodeTo, TARGET_VAL(PPC::VCMPGTFP), 0,
                  1/*#VTs*/, MVT::v4f32, 2/*#Ops*/, 0, 1, 
              // Src: (PPCvcmp:v4f32 v4f32:v4f32:$vA, v4f32:v4f32:$vB, 710:i32) - Complexity = 8
              // Dst: (VCMPGTFP:v4f32 v4f32:v4f32:$vA, v4f32:v4f32:$vB)
/*11663*/   0, /*End of Scope*/
/*11664*/ /*SwitchOpcode*/ 123|128,1/*251*/,  TARGET_VAL(PPCISD::VCMPo),// ->11919
/*11668*/   OPC_RecordChild0, // #0 = $vA
/*11669*/   OPC_RecordChild1, // #1 = $vB
/*11670*/   OPC_MoveChild, 2,
/*11672*/   OPC_Scope, 17, /*->11691*/ // 13 children in Scope
/*11674*/     OPC_CheckInteger, 6, 
/*11676*/     OPC_MoveParent,
/*11677*/     OPC_CheckType, MVT::v16i8,
/*11679*/     OPC_CheckPatternPredicate, 0, // (PPCSubTarget.hasAltivec())
/*11681*/     OPC_MorphNodeTo, TARGET_VAL(PPC::VCMPEQUBo), 0|OPFL_GlueOutput,
                  2/*#VTs*/, MVT::v16i8, MVT::i32, 2/*#Ops*/, 0, 1, 
              // Src: (PPCvcmp_o:v16i8 v16i8:v16i8:$vA, v16i8:v16i8:$vB, 6:i32) - Complexity = 8
              // Dst: (VCMPEQUBo:v16i8:i32 v16i8:v16i8:$vA, v16i8:v16i8:$vB)
/*11691*/   /*Scope*/ 18, /*->11710*/
/*11692*/     OPC_CheckInteger, 6|128,6/*774*/, 
/*11695*/     OPC_MoveParent,
/*11696*/     OPC_CheckType, MVT::v16i8,
/*11698*/     OPC_CheckPatternPredicate, 0, // (PPCSubTarget.hasAltivec())
/*11700*/     OPC_MorphNodeTo, TARGET_VAL(PPC::VCMPGTSBo), 0|OPFL_GlueOutput,
                  2/*#VTs*/, MVT::v16i8, MVT::i32, 2/*#Ops*/, 0, 1, 
              // Src: (PPCvcmp_o:v16i8 v16i8:v16i8:$vA, v16i8:v16i8:$vB, 774:i32) - Complexity = 8
              // Dst: (VCMPGTSBo:v16i8:i32 v16i8:v16i8:$vA, v16i8:v16i8:$vB)
/*11710*/   /*Scope*/ 18, /*->11729*/
/*11711*/     OPC_CheckInteger, 6|128,4/*518*/, 
/*11714*/     OPC_MoveParent,
/*11715*/     OPC_CheckType, MVT::v16i8,
/*11717*/     OPC_CheckPatternPredicate, 0, // (PPCSubTarget.hasAltivec())
/*11719*/     OPC_MorphNodeTo, TARGET_VAL(PPC::VCMPGTUBo), 0|OPFL_GlueOutput,
                  2/*#VTs*/, MVT::v16i8, MVT::i32, 2/*#Ops*/, 0, 1, 
              // Src: (PPCvcmp_o:v16i8 v16i8:v16i8:$vA, v16i8:v16i8:$vB, 518:i32) - Complexity = 8
              // Dst: (VCMPGTUBo:v16i8:i32 v16i8:v16i8:$vA, v16i8:v16i8:$vB)
/*11729*/   /*Scope*/ 17, /*->11747*/
/*11730*/     OPC_CheckInteger, 70, 
/*11732*/     OPC_MoveParent,
/*11733*/     OPC_CheckType, MVT::v8i16,
/*11735*/     OPC_CheckPatternPredicate, 0, // (PPCSubTarget.hasAltivec())
/*11737*/     OPC_MorphNodeTo, TARGET_VAL(PPC::VCMPEQUHo), 0|OPFL_GlueOutput,
                  2/*#VTs*/, MVT::v8i16, MVT::i32, 2/*#Ops*/, 0, 1, 
              // Src: (PPCvcmp_o:v8i16 v8i16:v8i16:$vA, v8i16:v8i16:$vB, 70:i32) - Complexity = 8
              // Dst: (VCMPEQUHo:v8i16:i32 v8i16:v8i16:$vA, v8i16:v8i16:$vB)
/*11747*/   /*Scope*/ 18, /*->11766*/
/*11748*/     OPC_CheckInteger, 70|128,6/*838*/, 
/*11751*/     OPC_MoveParent,
/*11752*/     OPC_CheckType, MVT::v8i16,
/*11754*/     OPC_CheckPatternPredicate, 0, // (PPCSubTarget.hasAltivec())
/*11756*/     OPC_MorphNodeTo, TARGET_VAL(PPC::VCMPGTSHo), 0|OPFL_GlueOutput,
                  2/*#VTs*/, MVT::v8i16, MVT::i32, 2/*#Ops*/, 0, 1, 
              // Src: (PPCvcmp_o:v8i16 v8i16:v8i16:$vA, v8i16:v8i16:$vB, 838:i32) - Complexity = 8
              // Dst: (VCMPGTSHo:v8i16:i32 v8i16:v8i16:$vA, v8i16:v8i16:$vB)
/*11766*/   /*Scope*/ 18, /*->11785*/
/*11767*/     OPC_CheckInteger, 70|128,4/*582*/, 
/*11770*/     OPC_MoveParent,
/*11771*/     OPC_CheckType, MVT::v8i16,
/*11773*/     OPC_CheckPatternPredicate, 0, // (PPCSubTarget.hasAltivec())
/*11775*/     OPC_MorphNodeTo, TARGET_VAL(PPC::VCMPGTUHo), 0|OPFL_GlueOutput,
                  2/*#VTs*/, MVT::v8i16, MVT::i32, 2/*#Ops*/, 0, 1, 
              // Src: (PPCvcmp_o:v8i16 v8i16:v8i16:$vA, v8i16:v8i16:$vB, 582:i32) - Complexity = 8
              // Dst: (VCMPGTUHo:v8i16:i32 v8i16:v8i16:$vA, v8i16:v8i16:$vB)
/*11785*/   /*Scope*/ 18, /*->11804*/
/*11786*/     OPC_CheckInteger, 6|128,1/*134*/, 
/*11789*/     OPC_MoveParent,
/*11790*/     OPC_CheckType, MVT::v4i32,
/*11792*/     OPC_CheckPatternPredicate, 0, // (PPCSubTarget.hasAltivec())
/*11794*/     OPC_MorphNodeTo, TARGET_VAL(PPC::VCMPEQUWo), 0|OPFL_GlueOutput,
                  2/*#VTs*/, MVT::v4i32, MVT::i32, 2/*#Ops*/, 0, 1, 
              // Src: (PPCvcmp_o:v4i32 v4i32:v4i32:$vA, v4i32:v4i32:$vB, 134:i32) - Complexity = 8
              // Dst: (VCMPEQUWo:v4i32:i32 v4i32:v4i32:$vA, v4i32:v4i32:$vB)
/*11804*/   /*Scope*/ 18, /*->11823*/
/*11805*/     OPC_CheckInteger, 6|128,7/*902*/, 
/*11808*/     OPC_MoveParent,
/*11809*/     OPC_CheckType, MVT::v4i32,
/*11811*/     OPC_CheckPatternPredicate, 0, // (PPCSubTarget.hasAltivec())
/*11813*/     OPC_MorphNodeTo, TARGET_VAL(PPC::VCMPGTSWo), 0|OPFL_GlueOutput,
                  2/*#VTs*/, MVT::v4i32, MVT::i32, 2/*#Ops*/, 0, 1, 
              // Src: (PPCvcmp_o:v4i32 v4i32:v4i32:$vA, v4i32:v4i32:$vB, 902:i32) - Complexity = 8
              // Dst: (VCMPGTSWo:v4i32:i32 v4i32:v4i32:$vA, v4i32:v4i32:$vB)
/*11823*/   /*Scope*/ 18, /*->11842*/
/*11824*/     OPC_CheckInteger, 6|128,5/*646*/, 
/*11827*/     OPC_MoveParent,
/*11828*/     OPC_CheckType, MVT::v4i32,
/*11830*/     OPC_CheckPatternPredicate, 0, // (PPCSubTarget.hasAltivec())
/*11832*/     OPC_MorphNodeTo, TARGET_VAL(PPC::VCMPGTUWo), 0|OPFL_GlueOutput,
                  2/*#VTs*/, MVT::v4i32, MVT::i32, 2/*#Ops*/, 0, 1, 
              // Src: (PPCvcmp_o:v4i32 v4i32:v4i32:$vA, v4i32:v4i32:$vB, 646:i32) - Complexity = 8
              // Dst: (VCMPGTUWo:v4i32:i32 v4i32:v4i32:$vA, v4i32:v4i32:$vB)
/*11842*/   /*Scope*/ 18, /*->11861*/
/*11843*/     OPC_CheckInteger, 70|128,7/*966*/, 
/*11846*/     OPC_MoveParent,
/*11847*/     OPC_CheckType, MVT::v4f32,
/*11849*/     OPC_CheckPatternPredicate, 0, // (PPCSubTarget.hasAltivec())
/*11851*/     OPC_MorphNodeTo, TARGET_VAL(PPC::VCMPBFPo), 0|OPFL_GlueOutput,
                  2/*#VTs*/, MVT::v4f32, MVT::i32, 2/*#Ops*/, 0, 1, 
              // Src: (PPCvcmp_o:v4f32 v4f32:v4f32:$vA, v4f32:v4f32:$vB, 966:i32) - Complexity = 8
              // Dst: (VCMPBFPo:v4f32:i32 v4f32:v4f32:$vA, v4f32:v4f32:$vB)
/*11861*/   /*Scope*/ 18, /*->11880*/
/*11862*/     OPC_CheckInteger, 70|128,1/*198*/, 
/*11865*/     OPC_MoveParent,
/*11866*/     OPC_CheckType, MVT::v4f32,
/*11868*/     OPC_CheckPatternPredicate, 0, // (PPCSubTarget.hasAltivec())
/*11870*/     OPC_MorphNodeTo, TARGET_VAL(PPC::VCMPEQFPo), 0|OPFL_GlueOutput,
                  2/*#VTs*/, MVT::v4f32, MVT::i32, 2/*#Ops*/, 0, 1, 
              // Src: (PPCvcmp_o:v4f32 v4f32:v4f32:$vA, v4f32:v4f32:$vB, 198:i32) - Complexity = 8
              // Dst: (VCMPEQFPo:v4f32:i32 v4f32:v4f32:$vA, v4f32:v4f32:$vB)
/*11880*/   /*Scope*/ 18, /*->11899*/
/*11881*/     OPC_CheckInteger, 70|128,3/*454*/, 
/*11884*/     OPC_MoveParent,
/*11885*/     OPC_CheckType, MVT::v4f32,
/*11887*/     OPC_CheckPatternPredicate, 0, // (PPCSubTarget.hasAltivec())
/*11889*/     OPC_MorphNodeTo, TARGET_VAL(PPC::VCMPGEFPo), 0|OPFL_GlueOutput,
                  2/*#VTs*/, MVT::v4f32, MVT::i32, 2/*#Ops*/, 0, 1, 
              // Src: (PPCvcmp_o:v4f32 v4f32:v4f32:$vA, v4f32:v4f32:$vB, 454:i32) - Complexity = 8
              // Dst: (VCMPGEFPo:v4f32:i32 v4f32:v4f32:$vA, v4f32:v4f32:$vB)
/*11899*/   /*Scope*/ 18, /*->11918*/
/*11900*/     OPC_CheckInteger, 70|128,5/*710*/, 
/*11903*/     OPC_MoveParent,
/*11904*/     OPC_CheckType, MVT::v4f32,
/*11906*/     OPC_CheckPatternPredicate, 0, // (PPCSubTarget.hasAltivec())
/*11908*/     OPC_MorphNodeTo, TARGET_VAL(PPC::VCMPGTFPo), 0|OPFL_GlueOutput,
                  2/*#VTs*/, MVT::v4f32, MVT::i32, 2/*#Ops*/, 0, 1, 
              // Src: (PPCvcmp_o:v4f32 v4f32:v4f32:$vA, v4f32:v4f32:$vB, 710:i32) - Complexity = 8
              // Dst: (VCMPGTFPo:v4f32:i32 v4f32:v4f32:$vA, v4f32:v4f32:$vB)
/*11918*/   0, /*End of Scope*/
/*11919*/ /*SwitchOpcode*/ 94|128,2/*350*/,  TARGET_VAL(ISD::VECTOR_SHUFFLE),// ->12273
/*11923*/   OPC_Scope, 81, /*->12006*/ // 4 children in Scope
/*11925*/     OPC_RecordNode, // #0 = $UIMM
/*11926*/     OPC_RecordChild0, // #1 = $vB
/*11927*/     OPC_MoveChild, 1,
/*11929*/     OPC_CheckOpcode, TARGET_VAL(ISD::UNDEF),
/*11932*/     OPC_MoveParent,
/*11933*/     OPC_CheckType, MVT::v16i8,
/*11935*/     OPC_Scope, 16, /*->11953*/ // 4 children in Scope
/*11937*/       OPC_CheckPredicate, 75, // Predicate_vspltb_shuffle
/*11939*/       OPC_CheckPatternPredicate, 0, // (PPCSubTarget.hasAltivec())
/*11941*/       OPC_EmitNodeXForm, 9, 0, // VSPLTB_get_imm
/*11944*/       OPC_MorphNodeTo, TARGET_VAL(PPC::VSPLTB), 0,
                    1/*#VTs*/, MVT::v16i8, 2/*#Ops*/, 2, 1, 
                // Src: (vector_shuffle:v16i8 v16i8:v16i8:$vB, (undef:v16i8))<<P:Predicate_vspltb_shuffle>><<X:VSPLTB_get_imm>>:$UIMM - Complexity = 7
                // Dst: (VSPLTB:v16i8 (VSPLTB_get_imm:i32 (vector_shuffle:v16i8 v16i8:v16i8:$vB, (undef:v16i8)):$UIMM), v16i8:v16i8:$vB)
/*11953*/     /*Scope*/ 16, /*->11970*/
/*11954*/       OPC_CheckPredicate, 76, // Predicate_vsplth_shuffle
/*11956*/       OPC_CheckPatternPredicate, 0, // (PPCSubTarget.hasAltivec())
/*11958*/       OPC_EmitNodeXForm, 10, 0, // VSPLTH_get_imm
/*11961*/       OPC_MorphNodeTo, TARGET_VAL(PPC::VSPLTH), 0,
                    1/*#VTs*/, MVT::v16i8, 2/*#Ops*/, 2, 1, 
                // Src: (vector_shuffle:v16i8 v16i8:v16i8:$vB, (undef:v16i8))<<P:Predicate_vsplth_shuffle>><<X:VSPLTH_get_imm>>:$UIMM - Complexity = 7
                // Dst: (VSPLTH:v16i8 (VSPLTH_get_imm:i32 (vector_shuffle:v16i8 v16i8:v16i8:$vB, (undef:v16i8)):$UIMM), v16i8:v16i8:$vB)
/*11970*/     /*Scope*/ 16, /*->11987*/
/*11971*/       OPC_CheckPredicate, 77, // Predicate_vspltw_shuffle
/*11973*/       OPC_CheckPatternPredicate, 0, // (PPCSubTarget.hasAltivec())
/*11975*/       OPC_EmitNodeXForm, 11, 0, // VSPLTW_get_imm
/*11978*/       OPC_MorphNodeTo, TARGET_VAL(PPC::VSPLTW), 0,
                    1/*#VTs*/, MVT::v16i8, 2/*#Ops*/, 2, 1, 
                // Src: (vector_shuffle:v16i8 v16i8:v16i8:$vB, (undef:v16i8))<<P:Predicate_vspltw_shuffle>><<X:VSPLTW_get_imm>>:$UIMM - Complexity = 7
                // Dst: (VSPLTW:v16i8 (VSPLTW_get_imm:i32 (vector_shuffle:v16i8 v16i8:v16i8:$vB, (undef:v16i8)):$UIMM), v16i8:v16i8:$vB)
/*11987*/     /*Scope*/ 17, /*->12005*/
/*11988*/       OPC_CheckPredicate, 78, // Predicate_vsldoi_unary_shuffle
/*11990*/       OPC_CheckPatternPredicate, 0, // (PPCSubTarget.hasAltivec())
/*11992*/       OPC_EmitNodeXForm, 12, 0, // VSLDOI_unary_get_imm
/*11995*/       OPC_MorphNodeTo, TARGET_VAL(PPC::VSLDOI), 0,
                    1/*#VTs*/, MVT::v16i8, 3/*#Ops*/, 1, 1, 2, 
                // Src: (vector_shuffle:v16i8 v16i8:v16i8:$vA, (undef:v16i8))<<P:Predicate_vsldoi_unary_shuffle>><<X:VSLDOI_unary_get_imm>>:$in - Complexity = 7
                // Dst: (VSLDOI:v16i8 ?:v16i8:$vA, ?:v16i8:$vA, (VSLDOI_unary_get_imm:i32 ?:v16i8:$in))
/*12005*/     0, /*End of Scope*/
/*12006*/   /*Scope*/ 123, /*->12130*/
/*12007*/     OPC_RecordChild0, // #0 = $vA
/*12008*/     OPC_MoveChild, 1,
/*12010*/     OPC_CheckOpcode, TARGET_VAL(ISD::UNDEF),
/*12013*/     OPC_MoveParent,
/*12014*/     OPC_CheckType, MVT::v16i8,
/*12016*/     OPC_Scope, 13, /*->12031*/ // 8 children in Scope
/*12018*/       OPC_CheckPredicate, 79, // Predicate_vpkuwum_unary_shuffle
/*12020*/       OPC_CheckPatternPredicate, 0, // (PPCSubTarget.hasAltivec())
/*12022*/       OPC_MorphNodeTo, TARGET_VAL(PPC::VPKUWUM), 0,
                    1/*#VTs*/, MVT::v16i8, 2/*#Ops*/, 0, 0, 
                // Src: (vector_shuffle:v16i8 v16i8:v16i8:$vA, (undef:v16i8))<<P:Predicate_vpkuwum_unary_shuffle>> - Complexity = 7
                // Dst: (VPKUWUM:v16i8 ?:v16i8:$vA, ?:v16i8:$vA)
/*12031*/     /*Scope*/ 13, /*->12045*/
/*12032*/       OPC_CheckPredicate, 80, // Predicate_vpkuhum_unary_shuffle
/*12034*/       OPC_CheckPatternPredicate, 0, // (PPCSubTarget.hasAltivec())
/*12036*/       OPC_MorphNodeTo, TARGET_VAL(PPC::VPKUHUM), 0,
                    1/*#VTs*/, MVT::v16i8, 2/*#Ops*/, 0, 0, 
                // Src: (vector_shuffle:v16i8 v16i8:v16i8:$vA, (undef:v16i8))<<P:Predicate_vpkuhum_unary_shuffle>> - Complexity = 7
                // Dst: (VPKUHUM:v16i8 ?:v16i8:$vA, ?:v16i8:$vA)
/*12045*/     /*Scope*/ 13, /*->12059*/
/*12046*/       OPC_CheckPredicate, 81, // Predicate_vmrglb_unary_shuffle
/*12048*/       OPC_CheckPatternPredicate, 0, // (PPCSubTarget.hasAltivec())
/*12050*/       OPC_MorphNodeTo, TARGET_VAL(PPC::VMRGLB), 0,
                    1/*#VTs*/, MVT::v16i8, 2/*#Ops*/, 0, 0, 
                // Src: (vector_shuffle:v16i8 v16i8:v16i8:$vA, (undef:v16i8))<<P:Predicate_vmrglb_unary_shuffle>> - Complexity = 7
                // Dst: (VMRGLB:v16i8 ?:v16i8:$vA, ?:v16i8:$vA)
/*12059*/     /*Scope*/ 13, /*->12073*/
/*12060*/       OPC_CheckPredicate, 82, // Predicate_vmrglh_unary_shuffle
/*12062*/       OPC_CheckPatternPredicate, 0, // (PPCSubTarget.hasAltivec())
/*12064*/       OPC_MorphNodeTo, TARGET_VAL(PPC::VMRGLH), 0,
                    1/*#VTs*/, MVT::v16i8, 2/*#Ops*/, 0, 0, 
                // Src: (vector_shuffle:v16i8 v16i8:v16i8:$vA, (undef:v16i8))<<P:Predicate_vmrglh_unary_shuffle>> - Complexity = 7
                // Dst: (VMRGLH:v16i8 ?:v16i8:$vA, ?:v16i8:$vA)
/*12073*/     /*Scope*/ 13, /*->12087*/
/*12074*/       OPC_CheckPredicate, 83, // Predicate_vmrglw_unary_shuffle
/*12076*/       OPC_CheckPatternPredicate, 0, // (PPCSubTarget.hasAltivec())
/*12078*/       OPC_MorphNodeTo, TARGET_VAL(PPC::VMRGLW), 0,
                    1/*#VTs*/, MVT::v16i8, 2/*#Ops*/, 0, 0, 
                // Src: (vector_shuffle:v16i8 v16i8:v16i8:$vA, (undef:v16i8))<<P:Predicate_vmrglw_unary_shuffle>> - Complexity = 7
                // Dst: (VMRGLW:v16i8 ?:v16i8:$vA, ?:v16i8:$vA)
/*12087*/     /*Scope*/ 13, /*->12101*/
/*12088*/       OPC_CheckPredicate, 84, // Predicate_vmrghb_unary_shuffle
/*12090*/       OPC_CheckPatternPredicate, 0, // (PPCSubTarget.hasAltivec())
/*12092*/       OPC_MorphNodeTo, TARGET_VAL(PPC::VMRGHB), 0,
                    1/*#VTs*/, MVT::v16i8, 2/*#Ops*/, 0, 0, 
                // Src: (vector_shuffle:v16i8 v16i8:v16i8:$vA, (undef:v16i8))<<P:Predicate_vmrghb_unary_shuffle>> - Complexity = 7
                // Dst: (VMRGHB:v16i8 ?:v16i8:$vA, ?:v16i8:$vA)
/*12101*/     /*Scope*/ 13, /*->12115*/
/*12102*/       OPC_CheckPredicate, 85, // Predicate_vmrghh_unary_shuffle
/*12104*/       OPC_CheckPatternPredicate, 0, // (PPCSubTarget.hasAltivec())
/*12106*/       OPC_MorphNodeTo, TARGET_VAL(PPC::VMRGHH), 0,
                    1/*#VTs*/, MVT::v16i8, 2/*#Ops*/, 0, 0, 
                // Src: (vector_shuffle:v16i8 v16i8:v16i8:$vA, (undef:v16i8))<<P:Predicate_vmrghh_unary_shuffle>> - Complexity = 7
                // Dst: (VMRGHH:v16i8 ?:v16i8:$vA, ?:v16i8:$vA)
/*12115*/     /*Scope*/ 13, /*->12129*/
/*12116*/       OPC_CheckPredicate, 86, // Predicate_vmrghw_unary_shuffle
/*12118*/       OPC_CheckPatternPredicate, 0, // (PPCSubTarget.hasAltivec())
/*12120*/       OPC_MorphNodeTo, TARGET_VAL(PPC::VMRGHW), 0,
                    1/*#VTs*/, MVT::v16i8, 2/*#Ops*/, 0, 0, 
                // Src: (vector_shuffle:v16i8 v16i8:v16i8:$vA, (undef:v16i8))<<P:Predicate_vmrghw_unary_shuffle>> - Complexity = 7
                // Dst: (VMRGHW:v16i8 ?:v16i8:$vA, ?:v16i8:$vA)
/*12129*/     0, /*End of Scope*/
/*12130*/   /*Scope*/ 22, /*->12153*/
/*12131*/     OPC_RecordNode, // #0 = $SH
/*12132*/     OPC_RecordChild0, // #1 = $vA
/*12133*/     OPC_RecordChild1, // #2 = $vB
/*12134*/     OPC_CheckPredicate, 87, // Predicate_vsldoi_shuffle
/*12136*/     OPC_CheckType, MVT::v16i8,
/*12138*/     OPC_CheckPatternPredicate, 0, // (PPCSubTarget.hasAltivec())
/*12140*/     OPC_EmitNodeXForm, 13, 0, // VSLDOI_get_imm
/*12143*/     OPC_MorphNodeTo, TARGET_VAL(PPC::VSLDOI), 0,
                  1/*#VTs*/, MVT::v16i8, 3/*#Ops*/, 1, 2, 3, 
              // Src: (vector_shuffle:v16i8 v16i8:v16i8:$vA, v16i8:v16i8:$vB)<<P:Predicate_vsldoi_shuffle>><<X:VSLDOI_get_imm>>:$SH - Complexity = 4
              // Dst: (VSLDOI:v16i8 v16i8:v16i8:$vA, v16i8:v16i8:$vB, (VSLDOI_get_imm:i32 (vector_shuffle:v16i8 v16i8:v16i8:$vA, v16i8:v16i8:$vB):$SH))
/*12153*/   /*Scope*/ 118, /*->12272*/
/*12154*/     OPC_RecordChild0, // #0 = $vA
/*12155*/     OPC_RecordChild1, // #1 = $vB
/*12156*/     OPC_CheckType, MVT::v16i8,
/*12158*/     OPC_Scope, 13, /*->12173*/ // 8 children in Scope
/*12160*/       OPC_CheckPredicate, 88, // Predicate_vmrghb_shuffle
/*12162*/       OPC_CheckPatternPredicate, 0, // (PPCSubTarget.hasAltivec())
/*12164*/       OPC_MorphNodeTo, TARGET_VAL(PPC::VMRGHB), 0,
                    1/*#VTs*/, MVT::v16i8, 2/*#Ops*/, 0, 1, 
                // Src: (vector_shuffle:v16i8 v16i8:v16i8:$vA, v16i8:v16i8:$vB)<<P:Predicate_vmrghb_shuffle>> - Complexity = 4
                // Dst: (VMRGHB:v16i8 v16i8:v16i8:$vA, v16i8:v16i8:$vB)
/*12173*/     /*Scope*/ 13, /*->12187*/
/*12174*/       OPC_CheckPredicate, 89, // Predicate_vmrghh_shuffle
/*12176*/       OPC_CheckPatternPredicate, 0, // (PPCSubTarget.hasAltivec())
/*12178*/       OPC_MorphNodeTo, TARGET_VAL(PPC::VMRGHH), 0,
                    1/*#VTs*/, MVT::v16i8, 2/*#Ops*/, 0, 1, 
                // Src: (vector_shuffle:v16i8 v16i8:v16i8:$vA, v16i8:v16i8:$vB)<<P:Predicate_vmrghh_shuffle>> - Complexity = 4
                // Dst: (VMRGHH:v16i8 v16i8:v16i8:$vA, v16i8:v16i8:$vB)
/*12187*/     /*Scope*/ 13, /*->12201*/
/*12188*/       OPC_CheckPredicate, 90, // Predicate_vmrghw_shuffle
/*12190*/       OPC_CheckPatternPredicate, 0, // (PPCSubTarget.hasAltivec())
/*12192*/       OPC_MorphNodeTo, TARGET_VAL(PPC::VMRGHW), 0,
                    1/*#VTs*/, MVT::v16i8, 2/*#Ops*/, 0, 1, 
                // Src: (vector_shuffle:v16i8 v16i8:v16i8:$vA, v16i8:v16i8:$vB)<<P:Predicate_vmrghw_shuffle>> - Complexity = 4
                // Dst: (VMRGHW:v16i8 v16i8:v16i8:$vA, v16i8:v16i8:$vB)
/*12201*/     /*Scope*/ 13, /*->12215*/
/*12202*/       OPC_CheckPredicate, 91, // Predicate_vmrglb_shuffle
/*12204*/       OPC_CheckPatternPredicate, 0, // (PPCSubTarget.hasAltivec())
/*12206*/       OPC_MorphNodeTo, TARGET_VAL(PPC::VMRGLB), 0,
                    1/*#VTs*/, MVT::v16i8, 2/*#Ops*/, 0, 1, 
                // Src: (vector_shuffle:v16i8 v16i8:v16i8:$vA, v16i8:v16i8:$vB)<<P:Predicate_vmrglb_shuffle>> - Complexity = 4
                // Dst: (VMRGLB:v16i8 v16i8:v16i8:$vA, v16i8:v16i8:$vB)
/*12215*/     /*Scope*/ 13, /*->12229*/
/*12216*/       OPC_CheckPredicate, 92, // Predicate_vmrglh_shuffle
/*12218*/       OPC_CheckPatternPredicate, 0, // (PPCSubTarget.hasAltivec())
/*12220*/       OPC_MorphNodeTo, TARGET_VAL(PPC::VMRGLH), 0,
                    1/*#VTs*/, MVT::v16i8, 2/*#Ops*/, 0, 1, 
                // Src: (vector_shuffle:v16i8 v16i8:v16i8:$vA, v16i8:v16i8:$vB)<<P:Predicate_vmrglh_shuffle>> - Complexity = 4
                // Dst: (VMRGLH:v16i8 v16i8:v16i8:$vA, v16i8:v16i8:$vB)
/*12229*/     /*Scope*/ 13, /*->12243*/
/*12230*/       OPC_CheckPredicate, 93, // Predicate_vmrglw_shuffle
/*12232*/       OPC_CheckPatternPredicate, 0, // (PPCSubTarget.hasAltivec())
/*12234*/       OPC_MorphNodeTo, TARGET_VAL(PPC::VMRGLW), 0,
                    1/*#VTs*/, MVT::v16i8, 2/*#Ops*/, 0, 1, 
                // Src: (vector_shuffle:v16i8 v16i8:v16i8:$vA, v16i8:v16i8:$vB)<<P:Predicate_vmrglw_shuffle>> - Complexity = 4
                // Dst: (VMRGLW:v16i8 v16i8:v16i8:$vA, v16i8:v16i8:$vB)
/*12243*/     /*Scope*/ 13, /*->12257*/
/*12244*/       OPC_CheckPredicate, 94, // Predicate_vpkuhum_shuffle
/*12246*/       OPC_CheckPatternPredicate, 0, // (PPCSubTarget.hasAltivec())
/*12248*/       OPC_MorphNodeTo, TARGET_VAL(PPC::VPKUHUM), 0,
                    1/*#VTs*/, MVT::v16i8, 2/*#Ops*/, 0, 1, 
                // Src: (vector_shuffle:v16i8 v16i8:v16i8:$vA, v16i8:v16i8:$vB)<<P:Predicate_vpkuhum_shuffle>> - Complexity = 4
                // Dst: (VPKUHUM:v16i8 v16i8:v16i8:$vA, v16i8:v16i8:$vB)
/*12257*/     /*Scope*/ 13, /*->12271*/
/*12258*/       OPC_CheckPredicate, 95, // Predicate_vpkuwum_shuffle
/*12260*/       OPC_CheckPatternPredicate, 0, // (PPCSubTarget.hasAltivec())
/*12262*/       OPC_MorphNodeTo, TARGET_VAL(PPC::VPKUWUM), 0,
                    1/*#VTs*/, MVT::v16i8, 2/*#Ops*/, 0, 1, 
                // Src: (vector_shuffle:v16i8 v16i8:v16i8:$vA, v16i8:v16i8:$vB)<<P:Predicate_vpkuwum_shuffle>> - Complexity = 4
                // Dst: (VPKUWUM:v16i8 v16i8:v16i8:$vA, v16i8:v16i8:$vB)
/*12271*/     0, /*End of Scope*/
/*12272*/   0, /*End of Scope*/
/*12273*/ /*SwitchOpcode*/ 5|128,1/*133*/,  TARGET_VAL(ISD::BUILD_VECTOR),// ->12410
/*12277*/   OPC_Scope, 54, /*->12333*/ // 3 children in Scope
/*12279*/     OPC_RecordNode, // #0 = $SIMM
/*12280*/     OPC_SwitchType /*3 cases */, 15,  MVT::v16i8,// ->12298
/*12283*/       OPC_CheckPredicate, 96, // Predicate_vecspltisb
/*12285*/       OPC_CheckPatternPredicate, 0, // (PPCSubTarget.hasAltivec())
/*12287*/       OPC_EmitNodeXForm, 14, 0, // VSPLTISB_get_imm
/*12290*/       OPC_MorphNodeTo, TARGET_VAL(PPC::VSPLTISB), 0,
                    1/*#VTs*/, MVT::v16i8, 1/*#Ops*/, 1, 
                // Src: (build_vector:v16i8)<<P:Predicate_vecspltisb>><<X:VSPLTISB_get_imm>>:$SIMM - Complexity = 4
                // Dst: (VSPLTISB:v16i8 (VSPLTISB_get_imm:i32 (build_vector:v16i8):$SIMM))
/*12298*/     /*SwitchType*/ 15,  MVT::v8i16,// ->12315
/*12300*/       OPC_CheckPredicate, 97, // Predicate_vecspltish
/*12302*/       OPC_CheckPatternPredicate, 0, // (PPCSubTarget.hasAltivec())
/*12304*/       OPC_EmitNodeXForm, 15, 0, // VSPLTISH_get_imm
/*12307*/       OPC_MorphNodeTo, TARGET_VAL(PPC::VSPLTISH), 0,
                    1/*#VTs*/, MVT::v8i16, 1/*#Ops*/, 1, 
                // Src: (build_vector:v8i16)<<P:Predicate_vecspltish>><<X:VSPLTISH_get_imm>>:$SIMM - Complexity = 4
                // Dst: (VSPLTISH:v8i16 (VSPLTISH_get_imm:i32 (build_vector:v8i16):$SIMM))
/*12315*/     /*SwitchType*/ 15,  MVT::v4i32,// ->12332
/*12317*/       OPC_CheckPredicate, 98, // Predicate_vecspltisw
/*12319*/       OPC_CheckPatternPredicate, 0, // (PPCSubTarget.hasAltivec())
/*12321*/       OPC_EmitNodeXForm, 16, 0, // VSPLTISW_get_imm
/*12324*/       OPC_MorphNodeTo, TARGET_VAL(PPC::VSPLTISW), 0,
                    1/*#VTs*/, MVT::v4i32, 1/*#Ops*/, 1, 
                // Src: (build_vector:v4i32)<<P:Predicate_vecspltisw>><<X:VSPLTISW_get_imm>>:$SIMM - Complexity = 4
                // Dst: (VSPLTISW:v4i32 (VSPLTISW_get_imm:i32 (build_vector:v4i32):$SIMM))
/*12332*/     0, // EndSwitchType
/*12333*/   /*Scope*/ 37, /*->12371*/
/*12334*/     OPC_CheckPredicate, 99, // Predicate_immAllZerosV
/*12336*/     OPC_SwitchType /*3 cases */, 9,  MVT::v16i8,// ->12348
/*12339*/       OPC_CheckPatternPredicate, 0, // (PPCSubTarget.hasAltivec())
/*12341*/       OPC_MorphNodeTo, TARGET_VAL(PPC::V_SET0B), 0,
                    1/*#VTs*/, MVT::v16i8, 0/*#Ops*/, 
                // Src: (build_vector:v16i8)<<P:Predicate_immAllZerosV>> - Complexity = 4
                // Dst: (V_SET0B:v16i8)
/*12348*/     /*SwitchType*/ 9,  MVT::v8i16,// ->12359
/*12350*/       OPC_CheckPatternPredicate, 0, // (PPCSubTarget.hasAltivec())
/*12352*/       OPC_MorphNodeTo, TARGET_VAL(PPC::V_SET0H), 0,
                    1/*#VTs*/, MVT::v8i16, 0/*#Ops*/, 
                // Src: (build_vector:v8i16)<<P:Predicate_immAllZerosV>> - Complexity = 4
                // Dst: (V_SET0H:v8i16)
/*12359*/     /*SwitchType*/ 9,  MVT::v4i32,// ->12370
/*12361*/       OPC_CheckPatternPredicate, 0, // (PPCSubTarget.hasAltivec())
/*12363*/       OPC_MorphNodeTo, TARGET_VAL(PPC::V_SET0), 0,
                    1/*#VTs*/, MVT::v4i32, 0/*#Ops*/, 
                // Src: (build_vector:v4i32)<<P:Predicate_immAllZerosV>> - Complexity = 4
                // Dst: (V_SET0:v4i32)
/*12370*/     0, // EndSwitchType
/*12371*/   /*Scope*/ 37, /*->12409*/
/*12372*/     OPC_CheckPredicate, 73, // Predicate_immAllOnesV
/*12374*/     OPC_SwitchType /*3 cases */, 9,  MVT::v16i8,// ->12386
/*12377*/       OPC_CheckPatternPredicate, 0, // (PPCSubTarget.hasAltivec())
/*12379*/       OPC_MorphNodeTo, TARGET_VAL(PPC::V_SETALLONESB), 0,
                    1/*#VTs*/, MVT::v16i8, 0/*#Ops*/, 
                // Src: (build_vector:v16i8)<<P:Predicate_immAllOnesV>> - Complexity = 4
                // Dst: (V_SETALLONESB:v16i8)
/*12386*/     /*SwitchType*/ 9,  MVT::v8i16,// ->12397
/*12388*/       OPC_CheckPatternPredicate, 0, // (PPCSubTarget.hasAltivec())
/*12390*/       OPC_MorphNodeTo, TARGET_VAL(PPC::V_SETALLONESH), 0,
                    1/*#VTs*/, MVT::v8i16, 0/*#Ops*/, 
                // Src: (build_vector:v8i16)<<P:Predicate_immAllOnesV>> - Complexity = 4
                // Dst: (V_SETALLONESH:v8i16)
/*12397*/     /*SwitchType*/ 9,  MVT::v4i32,// ->12408
/*12399*/       OPC_CheckPatternPredicate, 0, // (PPCSubTarget.hasAltivec())
/*12401*/       OPC_MorphNodeTo, TARGET_VAL(PPC::V_SETALLONES), 0,
                    1/*#VTs*/, MVT::v4i32, 0/*#Ops*/, 
                // Src: (build_vector:v4i32)<<P:Predicate_immAllOnesV>> - Complexity = 4
                // Dst: (V_SETALLONES:v4i32)
/*12408*/     0, // EndSwitchType
/*12409*/   0, /*End of Scope*/
/*12410*/ /*SwitchOpcode*/ 107,  TARGET_VAL(ISD::BITCAST),// ->12520
/*12413*/   OPC_RecordChild0, // #0 = $src
/*12414*/   OPC_Scope, 25, /*->12441*/ // 4 children in Scope
/*12416*/     OPC_CheckChild0Type, MVT::v8i16,
/*12418*/     OPC_SwitchType /*3 cases */, 5,  MVT::v16i8,// ->12426
/*12421*/       OPC_CheckPatternPredicate, 0, // (PPCSubTarget.hasAltivec())
/*12423*/       OPC_CompleteMatch, 1, 0, 
                // Src: (bitconvert:v16i8 VRRC:v8i16:$src) - Complexity = 3
                // Dst: VRRC:v16i8:$src
/*12426*/     /*SwitchType*/ 5,  MVT::v4i32,// ->12433
/*12428*/       OPC_CheckPatternPredicate, 0, // (PPCSubTarget.hasAltivec())
/*12430*/       OPC_CompleteMatch, 1, 0, 
                // Src: (bitconvert:v4i32 VRRC:v8i16:$src) - Complexity = 3
                // Dst: VRRC:v4i32:$src
/*12433*/     /*SwitchType*/ 5,  MVT::v4f32,// ->12440
/*12435*/       OPC_CheckPatternPredicate, 0, // (PPCSubTarget.hasAltivec())
/*12437*/       OPC_CompleteMatch, 1, 0, 
                // Src: (bitconvert:v4f32 VRRC:v8i16:$src) - Complexity = 3
                // Dst: VRRC:v4f32:$src
/*12440*/     0, // EndSwitchType
/*12441*/   /*Scope*/ 25, /*->12467*/
/*12442*/     OPC_CheckChild0Type, MVT::v4i32,
/*12444*/     OPC_SwitchType /*3 cases */, 5,  MVT::v16i8,// ->12452
/*12447*/       OPC_CheckPatternPredicate, 0, // (PPCSubTarget.hasAltivec())
/*12449*/       OPC_CompleteMatch, 1, 0, 
                // Src: (bitconvert:v16i8 VRRC:v4i32:$src) - Complexity = 3
                // Dst: VRRC:v16i8:$src
/*12452*/     /*SwitchType*/ 5,  MVT::v8i16,// ->12459
/*12454*/       OPC_CheckPatternPredicate, 0, // (PPCSubTarget.hasAltivec())
/*12456*/       OPC_CompleteMatch, 1, 0, 
                // Src: (bitconvert:v8i16 VRRC:v4i32:$src) - Complexity = 3
                // Dst: VRRC:v8i16:$src
/*12459*/     /*SwitchType*/ 5,  MVT::v4f32,// ->12466
/*12461*/       OPC_CheckPatternPredicate, 0, // (PPCSubTarget.hasAltivec())
/*12463*/       OPC_CompleteMatch, 1, 0, 
                // Src: (bitconvert:v4f32 VRRC:v4i32:$src) - Complexity = 3
                // Dst: VRRC:v4f32:$src
/*12466*/     0, // EndSwitchType
/*12467*/   /*Scope*/ 25, /*->12493*/
/*12468*/     OPC_CheckChild0Type, MVT::v4f32,
/*12470*/     OPC_SwitchType /*3 cases */, 5,  MVT::v16i8,// ->12478
/*12473*/       OPC_CheckPatternPredicate, 0, // (PPCSubTarget.hasAltivec())
/*12475*/       OPC_CompleteMatch, 1, 0, 
                // Src: (bitconvert:v16i8 VRRC:v4f32:$src) - Complexity = 3
                // Dst: VRRC:v16i8:$src
/*12478*/     /*SwitchType*/ 5,  MVT::v8i16,// ->12485
/*12480*/       OPC_CheckPatternPredicate, 0, // (PPCSubTarget.hasAltivec())
/*12482*/       OPC_CompleteMatch, 1, 0, 
                // Src: (bitconvert:v8i16 VRRC:v4f32:$src) - Complexity = 3
                // Dst: VRRC:v8i16:$src
/*12485*/     /*SwitchType*/ 5,  MVT::v4i32,// ->12492
/*12487*/       OPC_CheckPatternPredicate, 0, // (PPCSubTarget.hasAltivec())
/*12489*/       OPC_CompleteMatch, 1, 0, 
                // Src: (bitconvert:v4i32 VRRC:v4f32:$src) - Complexity = 3
                // Dst: VRRC:v4i32:$src
/*12492*/     0, // EndSwitchType
/*12493*/   /*Scope*/ 25, /*->12519*/
/*12494*/     OPC_CheckChild0Type, MVT::v16i8,
/*12496*/     OPC_SwitchType /*3 cases */, 5,  MVT::v8i16,// ->12504
/*12499*/       OPC_CheckPatternPredicate, 0, // (PPCSubTarget.hasAltivec())
/*12501*/       OPC_CompleteMatch, 1, 0, 
                // Src: (bitconvert:v8i16 VRRC:v16i8:$src) - Complexity = 3
                // Dst: VRRC:v8i16:$src
/*12504*/     /*SwitchType*/ 5,  MVT::v4i32,// ->12511
/*12506*/       OPC_CheckPatternPredicate, 0, // (PPCSubTarget.hasAltivec())
/*12508*/       OPC_CompleteMatch, 1, 0, 
                // Src: (bitconvert:v4i32 VRRC:v16i8:$src) - Complexity = 3
                // Dst: VRRC:v4i32:$src
/*12511*/     /*SwitchType*/ 5,  MVT::v4f32,// ->12518
/*12513*/       OPC_CheckPatternPredicate, 0, // (PPCSubTarget.hasAltivec())
/*12515*/       OPC_CompleteMatch, 1, 0, 
                // Src: (bitconvert:v4f32 VRRC:v16i8:$src) - Complexity = 3
                // Dst: VRRC:v4f32:$src
/*12518*/     0, // EndSwitchType
/*12519*/   0, /*End of Scope*/
/*12520*/ /*SwitchOpcode*/ 17,  TARGET_VAL(PPCISD::VPERM),// ->12540
/*12523*/   OPC_RecordChild0, // #0 = $vA
/*12524*/   OPC_RecordChild1, // #1 = $vB
/*12525*/   OPC_RecordChild2, // #2 = $vC
/*12526*/   OPC_CheckType, MVT::v16i8,
/*12528*/   OPC_CheckPatternPredicate, 0, // (PPCSubTarget.hasAltivec())
/*12530*/   OPC_MorphNodeTo, TARGET_VAL(PPC::VPERM), 0,
                1/*#VTs*/, MVT::v16i8, 3/*#Ops*/, 0, 1, 2, 
            // Src: (PPCvperm:v16i8 v16i8:v16i8:$vA, v16i8:v16i8:$vB, v16i8:v16i8:$vC) - Complexity = 3
            // Dst: (VPERM:v16i8 ?:v16i8:$vA, ?:v16i8:$vB, ?:v16i8:$vC)
/*12540*/ /*SwitchOpcode*/ 15,  TARGET_VAL(ISD::FP_TO_SINT),// ->12558
/*12543*/   OPC_RecordChild0, // #0 = $vA
/*12544*/   OPC_CheckChild0Type, MVT::v4f32,
/*12546*/   OPC_CheckType, MVT::v4i32,
/*12548*/   OPC_CheckPatternPredicate, 0, // (PPCSubTarget.hasAltivec())
/*12550*/   OPC_MorphNodeTo, TARGET_VAL(PPC::VCTSXS_0), 0,
                1/*#VTs*/, MVT::v4i32, 1/*#Ops*/, 0, 
            // Src: (fp_to_sint:v4i32 v4f32:v4f32:$vA) - Complexity = 3
            // Dst: (VCTSXS_0:v4i32 ?:v4f32:$vA)
/*12558*/ /*SwitchOpcode*/ 15,  TARGET_VAL(ISD::FP_TO_UINT),// ->12576
/*12561*/   OPC_RecordChild0, // #0 = $vA
/*12562*/   OPC_CheckChild0Type, MVT::v4f32,
/*12564*/   OPC_CheckType, MVT::v4i32,
/*12566*/   OPC_CheckPatternPredicate, 0, // (PPCSubTarget.hasAltivec())
/*12568*/   OPC_MorphNodeTo, TARGET_VAL(PPC::VCTUXS_0), 0,
                1/*#VTs*/, MVT::v4i32, 1/*#Ops*/, 0, 
            // Src: (fp_to_uint:v4i32 v4f32:v4f32:$vA) - Complexity = 3
            // Dst: (VCTUXS_0:v4i32 ?:v4f32:$vA)
/*12576*/ /*SwitchOpcode*/ 17,  TARGET_VAL(PPCISD::VMADDFP),// ->12596
/*12579*/   OPC_RecordChild0, // #0 = $A
/*12580*/   OPC_RecordChild1, // #1 = $B
/*12581*/   OPC_RecordChild2, // #2 = $C
/*12582*/   OPC_CheckType, MVT::v4f32,
/*12584*/   OPC_CheckPatternPredicate, 0, // (PPCSubTarget.hasAltivec())
/*12586*/   OPC_MorphNodeTo, TARGET_VAL(PPC::VMADDFP), 0,
                1/*#VTs*/, MVT::v4f32, 3/*#Ops*/, 0, 1, 2, 
            // Src: (PPCvmaddfp:v4f32 v4f32:v4f32:$A, v4f32:v4f32:$B, v4f32:v4f32:$C) - Complexity = 3
            // Dst: (VMADDFP:v4f32 ?:v4f32:$A, ?:v4f32:$B, ?:v4f32:$C)
/*12596*/ /*SwitchOpcode*/ 17,  TARGET_VAL(PPCISD::VNMSUBFP),// ->12616
/*12599*/   OPC_RecordChild0, // #0 = $A
/*12600*/   OPC_RecordChild1, // #1 = $B
/*12601*/   OPC_RecordChild2, // #2 = $C
/*12602*/   OPC_CheckType, MVT::v4f32,
/*12604*/   OPC_CheckPatternPredicate, 0, // (PPCSubTarget.hasAltivec())
/*12606*/   OPC_MorphNodeTo, TARGET_VAL(PPC::VNMSUBFP), 0,
                1/*#VTs*/, MVT::v4f32, 3/*#Ops*/, 0, 1, 2, 
            // Src: (PPCvnmsubfp:v4f32 v4f32:v4f32:$A, v4f32:v4f32:$B, v4f32:v4f32:$C) - Complexity = 3
            // Dst: (VNMSUBFP:v4f32 ?:v4f32:$A, ?:v4f32:$B, ?:v4f32:$C)
/*12616*/ /*SwitchOpcode*/ 15,  TARGET_VAL(ISD::SINT_TO_FP),// ->12634
/*12619*/   OPC_RecordChild0, // #0 = $vA
/*12620*/   OPC_CheckChild0Type, MVT::v4i32,
/*12622*/   OPC_CheckType, MVT::v4f32,
/*12624*/   OPC_CheckPatternPredicate, 0, // (PPCSubTarget.hasAltivec())
/*12626*/   OPC_MorphNodeTo, TARGET_VAL(PPC::VCFSX_0), 0,
                1/*#VTs*/, MVT::v4f32, 1/*#Ops*/, 0, 
            // Src: (sint_to_fp:v4f32 v4i32:v4i32:$vA) - Complexity = 3
            // Dst: (VCFSX_0:v4f32 ?:v4i32:$vA)
/*12634*/ /*SwitchOpcode*/ 15,  TARGET_VAL(ISD::UINT_TO_FP),// ->12652
/*12637*/   OPC_RecordChild0, // #0 = $vA
/*12638*/   OPC_CheckChild0Type, MVT::v4i32,
/*12640*/   OPC_CheckType, MVT::v4f32,
/*12642*/   OPC_CheckPatternPredicate, 0, // (PPCSubTarget.hasAltivec())
/*12644*/   OPC_MorphNodeTo, TARGET_VAL(PPC::VCFUX_0), 0,
                1/*#VTs*/, MVT::v4f32, 1/*#Ops*/, 0, 
            // Src: (uint_to_fp:v4f32 v4i32:v4i32:$vA) - Complexity = 3
            // Dst: (VCFUX_0:v4f32 ?:v4i32:$vA)
/*12652*/ /*SwitchOpcode*/ 13,  TARGET_VAL(ISD::FNEARBYINT),// ->12668
/*12655*/   OPC_RecordChild0, // #0 = $vA
/*12656*/   OPC_CheckType, MVT::v4f32,
/*12658*/   OPC_CheckPatternPredicate, 0, // (PPCSubTarget.hasAltivec())
/*12660*/   OPC_MorphNodeTo, TARGET_VAL(PPC::VRFIN), 0,
                1/*#VTs*/, MVT::v4f32, 1/*#Ops*/, 0, 
            // Src: (fnearbyint:v4f32 v4f32:v4f32:$vA) - Complexity = 3
            // Dst: (VRFIN:v4f32 ?:v4f32:$vA)
/*12668*/ 0, // EndSwitchOpcode
    0
  }; // Total Array size is 12670 bytes

  // Opcode Histogram:
  // #OPC_Scope                          = 120
  // #OPC_RecordNode                     = 46
  // #OPC_RecordChild                    = 540
  // #OPC_RecordMemRef                   = 11
  // #OPC_CaptureGlueInput               = 14
  // #OPC_MoveChild                      = 155
  // #OPC_MoveParent                     = 378
  // #OPC_CheckSame                      = 0
  // #OPC_CheckChildSame                 = 0
  // #OPC_CheckPatternPredicate          = 249
  // #OPC_CheckPredicate                 = 202
  // #OPC_CheckOpcode                    = 93
  // #OPC_SwitchOpcode                   = 16
  // #OPC_CheckType                      = 183
  // #OPC_SwitchType                     = 99
  // #OPC_CheckChildType                 = 59
  // #OPC_CheckInteger                   = 198
  // #OPC_CheckCondCode                  = 0
  // #OPC_CheckValueType                 = 9
  // #OPC_CheckComplexPat                = 150
  // #OPC_CheckAndImm                    = 0
  // #OPC_CheckOrImm                     = 0
  // #OPC_CheckFoldableChainNode         = 0
  // #OPC_EmitInteger                    = 27
  // #OPC_EmitStringInteger              = 8
  // #OPC_EmitRegister                   = 0
  // #OPC_EmitConvertToTarget            = 76
  // #OPC_EmitMergeInputChains           = 206
  // #OPC_EmitCopyToReg                  = 0
  // #OPC_EmitNode                       = 14
  // #OPC_EmitNodeXForm                  = 38
  // #OPC_MarkGlueResults                = 0
  // #OPC_CompleteMatch                  = 12
  // #OPC_MorphNodeTo                    = 651

  #undef TARGET_VAL
  return SelectCodeCommon(N, MatcherTable,sizeof(MatcherTable));
}

virtual bool CheckPatternPredicate(unsigned PredNo) const {
  switch (PredNo) {
  default: llvm_unreachable("Invalid predicate in table?");
  case 0: return (PPCSubTarget.hasAltivec());
  case 1: return (!PPCSubTarget.isPPC64());
  case 2: return (PPCSubTarget.isPPC64());
  }
}

virtual bool CheckNodePredicate(SDNode *Node,
                                unsigned PredNo) const {
  switch (PredNo) {
  default: llvm_unreachable("Invalid predicate in table?");
  case 0: { // Predicate_imm32SExt16
    int64_t Imm = cast<ConstantSDNode>(Node)->getSExtValue();

  // imm32SExt16 predicate - True if the i32 immediate fits in a 16-bit
  // sign extended field.  Used by instructions like 'addi'.
  return (int32_t)Imm == (short)Imm;

  }
  case 1: { // Predicate_imm16ShiftedSExt
    ConstantSDNode*N = cast<ConstantSDNode>(Node);

  // imm16ShiftedSExt predicate - True if only bits in the top 16-bits of the
  // immediate are set.  Used by instructions like 'addis'.  Identical to 
  // imm16ShiftedZExt in 32-bit mode.
  if (N->getZExtValue() & 0xFFFF) return false;
  if (N->getValueType(0) == MVT::i32)
    return true;
  // For 64-bit, make sure it is sext right.
  return N->getZExtValue() == (uint64_t)(int)N->getZExtValue();

  }
  case 2: { // Predicate_imm64SExt16
    int64_t Imm = cast<ConstantSDNode>(Node)->getSExtValue();

  // imm64SExt16 predicate - True if the i64 immediate fits in a 16-bit
  // sign extended field.  Used by instructions like 'addi'.
  return (int64_t)Imm == (short)Imm;

  }
  case 3: { // Predicate_unindexedload
    SDNode *N = Node;

  return cast<LoadSDNode>(N)->getAddressingMode() == ISD::UNINDEXED;

  }
  case 4: { // Predicate_zextload
    SDNode *N = Node;

  return cast<LoadSDNode>(N)->getExtensionType() == ISD::ZEXTLOAD;

  }
  case 5: { // Predicate_zextloadi8
    SDNode *N = Node;

  return cast<LoadSDNode>(N)->getMemoryVT() == MVT::i8;

  }
  case 6: { // Predicate_sextload
    SDNode *N = Node;

  return cast<LoadSDNode>(N)->getExtensionType() == ISD::SEXTLOAD;

  }
  case 7: { // Predicate_sextloadi16
    SDNode *N = Node;

  return cast<LoadSDNode>(N)->getMemoryVT() == MVT::i16;

  }
  case 8: { // Predicate_zextloadi16
    SDNode *N = Node;

  return cast<LoadSDNode>(N)->getMemoryVT() == MVT::i16;

  }
  case 9: { // Predicate_load
    SDNode *N = Node;

  return cast<LoadSDNode>(N)->getExtensionType() == ISD::NON_EXTLOAD;

  }
  case 10: { // Predicate_zextloadi1
    SDNode *N = Node;

  return cast<LoadSDNode>(N)->getMemoryVT() == MVT::i1;

  }
  case 11: { // Predicate_extload
    SDNode *N = Node;

  return cast<LoadSDNode>(N)->getExtensionType() == ISD::EXTLOAD;

  }
  case 12: { // Predicate_extloadi1
    SDNode *N = Node;

  return cast<LoadSDNode>(N)->getMemoryVT() == MVT::i1;

  }
  case 13: { // Predicate_extloadi8
    SDNode *N = Node;

  return cast<LoadSDNode>(N)->getMemoryVT() == MVT::i8;

  }
  case 14: { // Predicate_extloadi16
    SDNode *N = Node;

  return cast<LoadSDNode>(N)->getMemoryVT() == MVT::i16;

  }
  case 15: { // Predicate_sextloadi32
    SDNode *N = Node;

  return cast<LoadSDNode>(N)->getMemoryVT() == MVT::i32;

  }
  case 16: { // Predicate_aligned4sextloadi32
    SDNode *N = Node;

  return cast<LoadSDNode>(N)->getAlignment() >= 4;

  }
  case 17: { // Predicate_zextloadi32
    SDNode *N = Node;

  return cast<LoadSDNode>(N)->getMemoryVT() == MVT::i32;

  }
  case 18: { // Predicate_aligned4load
    SDNode *N = Node;

  return cast<LoadSDNode>(N)->getAlignment() >= 4;

  }
  case 19: { // Predicate_extloadi32
    SDNode *N = Node;

  return cast<LoadSDNode>(N)->getMemoryVT() == MVT::i32;

  }
  case 20: { // Predicate_unaligned4sextloadi32
    SDNode *N = Node;

  return cast<LoadSDNode>(N)->getAlignment() < 4;

  }
  case 21: { // Predicate_unaligned4load
    SDNode *N = Node;

  return cast<LoadSDNode>(N)->getAlignment() < 4;

  }
  case 22: { // Predicate_extloadf32
    SDNode *N = Node;

  return cast<LoadSDNode>(N)->getMemoryVT() == MVT::f32;

  }
  case 23: { // Predicate_unindexedstore
    SDNode *N = Node;

  return cast<StoreSDNode>(N)->getAddressingMode() == ISD::UNINDEXED;

  }
  case 24: { // Predicate_truncstore
    SDNode *N = Node;

  return cast<StoreSDNode>(N)->isTruncatingStore();

  }
  case 25: { // Predicate_truncstorei8
    SDNode *N = Node;

  return cast<StoreSDNode>(N)->getMemoryVT() == MVT::i8;

  }
  case 26: { // Predicate_truncstorei16
    SDNode *N = Node;

  return cast<StoreSDNode>(N)->getMemoryVT() == MVT::i16;

  }
  case 27: { // Predicate_store
    SDNode *N = Node;

  return !cast<StoreSDNode>(N)->isTruncatingStore();

  }
  case 28: { // Predicate_itruncstore
    SDNode *N = Node;

  return cast<StoreSDNode>(N)->isTruncatingStore();

  }
  case 29: { // Predicate_pre_truncst
    SDNode *N = Node;

  ISD::MemIndexedMode AM = cast<StoreSDNode>(N)->getAddressingMode();
  return AM == ISD::PRE_INC || AM == ISD::PRE_DEC;

  }
  case 30: { // Predicate_pre_truncsti8
    SDNode *N = Node;

  return cast<StoreSDNode>(N)->getMemoryVT() == MVT::i8;

  }
  case 31: { // Predicate_pre_truncsti16
    SDNode *N = Node;

  return cast<StoreSDNode>(N)->getMemoryVT() == MVT::i16;

  }
  case 32: { // Predicate_istore
    SDNode *N = Node;

  return !cast<StoreSDNode>(N)->isTruncatingStore();

  }
  case 33: { // Predicate_pre_store
    SDNode *N = Node;

  ISD::MemIndexedMode AM = cast<StoreSDNode>(N)->getAddressingMode();
  return AM == ISD::PRE_INC || AM == ISD::PRE_DEC;

  }
  case 34: { // Predicate_truncstorei32
    SDNode *N = Node;

  return cast<StoreSDNode>(N)->getMemoryVT() == MVT::i32;

  }
  case 35: { // Predicate_aligned4store
    SDNode *N = Node;

  return cast<StoreSDNode>(N)->getAlignment() >= 4;

  }
  case 36: { // Predicate_unaligned4store
    SDNode *N = Node;

  return cast<StoreSDNode>(N)->getAlignment() < 4;

  }
  case 37: { // Predicate_pre_truncsti32
    SDNode *N = Node;

  return cast<StoreSDNode>(N)->getMemoryVT() == MVT::i32;

  }
  case 38: { // Predicate_aligned4pre_store
    SDNode *N = Node;

  return cast<StoreSDNode>(N)->getAlignment() >= 4;

  }
  case 39: { // Predicate_atomic_load_add_8
    SDNode *N = Node;

    return cast<AtomicSDNode>(N)->getMemoryVT() == MVT::i8;
  
  }
  case 40: { // Predicate_atomic_load_add_16
    SDNode *N = Node;

    return cast<AtomicSDNode>(N)->getMemoryVT() == MVT::i16;
  
  }
  case 41: { // Predicate_atomic_load_add_32
    SDNode *N = Node;

    return cast<AtomicSDNode>(N)->getMemoryVT() == MVT::i32;
  
  }
  case 42: { // Predicate_atomic_load_add_64
    SDNode *N = Node;

    return cast<AtomicSDNode>(N)->getMemoryVT() == MVT::i64;
  
  }
  case 43: { // Predicate_atomic_load_sub_8
    SDNode *N = Node;

    return cast<AtomicSDNode>(N)->getMemoryVT() == MVT::i8;
  
  }
  case 44: { // Predicate_atomic_load_sub_16
    SDNode *N = Node;

    return cast<AtomicSDNode>(N)->getMemoryVT() == MVT::i16;
  
  }
  case 45: { // Predicate_atomic_load_sub_32
    SDNode *N = Node;

    return cast<AtomicSDNode>(N)->getMemoryVT() == MVT::i32;
  
  }
  case 46: { // Predicate_atomic_load_sub_64
    SDNode *N = Node;

    return cast<AtomicSDNode>(N)->getMemoryVT() == MVT::i64;
  
  }
  case 47: { // Predicate_atomic_load_and_8
    SDNode *N = Node;

    return cast<AtomicSDNode>(N)->getMemoryVT() == MVT::i8;
  
  }
  case 48: { // Predicate_atomic_load_and_16
    SDNode *N = Node;

    return cast<AtomicSDNode>(N)->getMemoryVT() == MVT::i16;
  
  }
  case 49: { // Predicate_atomic_load_and_32
    SDNode *N = Node;

    return cast<AtomicSDNode>(N)->getMemoryVT() == MVT::i32;
  
  }
  case 50: { // Predicate_atomic_load_and_64
    SDNode *N = Node;

    return cast<AtomicSDNode>(N)->getMemoryVT() == MVT::i64;
  
  }
  case 51: { // Predicate_atomic_load_or_8
    SDNode *N = Node;

    return cast<AtomicSDNode>(N)->getMemoryVT() == MVT::i8;
  
  }
  case 52: { // Predicate_atomic_load_or_16
    SDNode *N = Node;

    return cast<AtomicSDNode>(N)->getMemoryVT() == MVT::i16;
  
  }
  case 53: { // Predicate_atomic_load_or_32
    SDNode *N = Node;

    return cast<AtomicSDNode>(N)->getMemoryVT() == MVT::i32;
  
  }
  case 54: { // Predicate_atomic_load_or_64
    SDNode *N = Node;

    return cast<AtomicSDNode>(N)->getMemoryVT() == MVT::i64;
  
  }
  case 55: { // Predicate_atomic_load_xor_8
    SDNode *N = Node;

    return cast<AtomicSDNode>(N)->getMemoryVT() == MVT::i8;
  
  }
  case 56: { // Predicate_atomic_load_xor_16
    SDNode *N = Node;

    return cast<AtomicSDNode>(N)->getMemoryVT() == MVT::i16;
  
  }
  case 57: { // Predicate_atomic_load_xor_32
    SDNode *N = Node;

    return cast<AtomicSDNode>(N)->getMemoryVT() == MVT::i32;
  
  }
  case 58: { // Predicate_atomic_load_xor_64
    SDNode *N = Node;

    return cast<AtomicSDNode>(N)->getMemoryVT() == MVT::i64;
  
  }
  case 59: { // Predicate_atomic_load_nand_8
    SDNode *N = Node;

    return cast<AtomicSDNode>(N)->getMemoryVT() == MVT::i8;
  
  }
  case 60: { // Predicate_atomic_load_nand_16
    SDNode *N = Node;

    return cast<AtomicSDNode>(N)->getMemoryVT() == MVT::i16;
  
  }
  case 61: { // Predicate_atomic_load_nand_32
    SDNode *N = Node;

    return cast<AtomicSDNode>(N)->getMemoryVT() == MVT::i32;
  
  }
  case 62: { // Predicate_atomic_load_nand_64
    SDNode *N = Node;

    return cast<AtomicSDNode>(N)->getMemoryVT() == MVT::i64;
  
  }
  case 63: { // Predicate_atomic_cmp_swap_8
    SDNode *N = Node;

  return cast<AtomicSDNode>(N)->getMemoryVT() == MVT::i8;

  }
  case 64: { // Predicate_atomic_cmp_swap_16
    SDNode *N = Node;

  return cast<AtomicSDNode>(N)->getMemoryVT() == MVT::i16;

  }
  case 65: { // Predicate_atomic_cmp_swap_32
    SDNode *N = Node;

  return cast<AtomicSDNode>(N)->getMemoryVT() == MVT::i32;

  }
  case 66: { // Predicate_atomic_cmp_swap_64
    SDNode *N = Node;

  return cast<AtomicSDNode>(N)->getMemoryVT() == MVT::i64;

  }
  case 67: { // Predicate_atomic_swap_8
    SDNode *N = Node;

    return cast<AtomicSDNode>(N)->getMemoryVT() == MVT::i8;
  
  }
  case 68: { // Predicate_atomic_swap_16
    SDNode *N = Node;

    return cast<AtomicSDNode>(N)->getMemoryVT() == MVT::i16;
  
  }
  case 69: { // Predicate_atomic_swap_32
    SDNode *N = Node;

    return cast<AtomicSDNode>(N)->getMemoryVT() == MVT::i32;
  
  }
  case 70: { // Predicate_atomic_swap_64
    SDNode *N = Node;

    return cast<AtomicSDNode>(N)->getMemoryVT() == MVT::i64;
  
  }
  case 71: { // Predicate_immZExt16
    ConstantSDNode*N = cast<ConstantSDNode>(Node);

  // immZExt16 predicate - True if the immediate fits in a 16-bit zero extended
  // field.  Used by instructions like 'ori'.
  return (uint64_t)N->getZExtValue() == (unsigned short)N->getZExtValue();

  }
  case 72: { // Predicate_imm16ShiftedZExt
    ConstantSDNode*N = cast<ConstantSDNode>(Node);

  // imm16ShiftedZExt predicate - True if only bits in the top 16-bits of the
  // immediate are set.  Used by instructions like 'xoris'.
  return (N->getZExtValue() & ~uint64_t(0xFFFF0000)) == 0;

  }
  case 73: { // Predicate_immAllOnesV
    SDNode *N = Node;

  return ISD::isBuildVectorAllOnes(N);

  }
  case 74: { // Predicate_maskimm32
    ConstantSDNode*N = cast<ConstantSDNode>(Node);

  // maskImm predicate - True if immediate is a run of ones.
  unsigned mb, me;
  if (N->getValueType(0) == MVT::i32)
    return isRunOfOnes((unsigned)N->getZExtValue(), mb, me);
  else
    return false;

  }
  case 75: { // Predicate_vspltb_shuffle
    SDNode *N = Node;

  return PPC::isSplatShuffleMask(cast<ShuffleVectorSDNode>(N), 1);

  }
  case 76: { // Predicate_vsplth_shuffle
    SDNode *N = Node;

  return PPC::isSplatShuffleMask(cast<ShuffleVectorSDNode>(N), 2);

  }
  case 77: { // Predicate_vspltw_shuffle
    SDNode *N = Node;

  return PPC::isSplatShuffleMask(cast<ShuffleVectorSDNode>(N), 4);

  }
  case 78: { // Predicate_vsldoi_unary_shuffle
    SDNode *N = Node;

  return PPC::isVSLDOIShuffleMask(N, true) != -1;

  }
  case 79: { // Predicate_vpkuwum_unary_shuffle
    SDNode *N = Node;

  return PPC::isVPKUWUMShuffleMask(cast<ShuffleVectorSDNode>(N), true);

  }
  case 80: { // Predicate_vpkuhum_unary_shuffle
    SDNode *N = Node;

  return PPC::isVPKUHUMShuffleMask(cast<ShuffleVectorSDNode>(N), true);

  }
  case 81: { // Predicate_vmrglb_unary_shuffle
    SDNode *N = Node;

  return PPC::isVMRGLShuffleMask(cast<ShuffleVectorSDNode>(N), 1, true);

  }
  case 82: { // Predicate_vmrglh_unary_shuffle
    SDNode *N = Node;

  return PPC::isVMRGLShuffleMask(cast<ShuffleVectorSDNode>(N), 2, true);

  }
  case 83: { // Predicate_vmrglw_unary_shuffle
    SDNode *N = Node;

  return PPC::isVMRGLShuffleMask(cast<ShuffleVectorSDNode>(N), 4, true);

  }
  case 84: { // Predicate_vmrghb_unary_shuffle
    SDNode *N = Node;

  return PPC::isVMRGHShuffleMask(cast<ShuffleVectorSDNode>(N), 1, true);

  }
  case 85: { // Predicate_vmrghh_unary_shuffle
    SDNode *N = Node;

  return PPC::isVMRGHShuffleMask(cast<ShuffleVectorSDNode>(N), 2, true);

  }
  case 86: { // Predicate_vmrghw_unary_shuffle
    SDNode *N = Node;

  return PPC::isVMRGHShuffleMask(cast<ShuffleVectorSDNode>(N), 4, true);

  }
  case 87: { // Predicate_vsldoi_shuffle
    SDNode *N = Node;

  return PPC::isVSLDOIShuffleMask(N, false) != -1;

  }
  case 88: { // Predicate_vmrghb_shuffle
    SDNode *N = Node;

  return PPC::isVMRGHShuffleMask(cast<ShuffleVectorSDNode>(N), 1, false);

  }
  case 89: { // Predicate_vmrghh_shuffle
    SDNode *N = Node;

  return PPC::isVMRGHShuffleMask(cast<ShuffleVectorSDNode>(N), 2, false);

  }
  case 90: { // Predicate_vmrghw_shuffle
    SDNode *N = Node;

  return PPC::isVMRGHShuffleMask(cast<ShuffleVectorSDNode>(N), 4, false);

  }
  case 91: { // Predicate_vmrglb_shuffle
    SDNode *N = Node;

  return PPC::isVMRGLShuffleMask(cast<ShuffleVectorSDNode>(N), 1, false);

  }
  case 92: { // Predicate_vmrglh_shuffle
    SDNode *N = Node;

  return PPC::isVMRGLShuffleMask(cast<ShuffleVectorSDNode>(N), 2, false);

  }
  case 93: { // Predicate_vmrglw_shuffle
    SDNode *N = Node;

  return PPC::isVMRGLShuffleMask(cast<ShuffleVectorSDNode>(N), 4, false);

  }
  case 94: { // Predicate_vpkuhum_shuffle
    SDNode *N = Node;

  return PPC::isVPKUHUMShuffleMask(cast<ShuffleVectorSDNode>(N), false);

  }
  case 95: { // Predicate_vpkuwum_shuffle
    SDNode *N = Node;

  return PPC::isVPKUWUMShuffleMask(cast<ShuffleVectorSDNode>(N), false);

  }
  case 96: { // Predicate_vecspltisb
    SDNode *N = Node;

  return PPC::get_VSPLTI_elt(N, 1, *CurDAG).getNode() != 0;

  }
  case 97: { // Predicate_vecspltish
    SDNode *N = Node;

  return PPC::get_VSPLTI_elt(N, 2, *CurDAG).getNode() != 0;

  }
  case 98: { // Predicate_vecspltisw
    SDNode *N = Node;

  return PPC::get_VSPLTI_elt(N, 4, *CurDAG).getNode() != 0;

  }
  case 99: { // Predicate_immAllZerosV
    SDNode *N = Node;

  return ISD::isBuildVectorAllZeros(N);

  }
  }
}

virtual bool CheckComplexPattern(SDNode *Root, SDNode *Parent,
                                 SDValue N, unsigned PatternNo,
         SmallVectorImpl<std::pair<SDValue, SDNode*> > &Result) {
  unsigned NextRes = Result.size();
  switch (PatternNo) {
  default: llvm_unreachable("Invalid pattern # in table?");
  case 0:
    Result.resize(NextRes+2);
    return SelectAddrIdxOnly(N, Result[NextRes+0].first, Result[NextRes+1].first);
  case 1:
    Result.resize(NextRes+2);
    return SelectAddrImm(N, Result[NextRes+0].first, Result[NextRes+1].first);
  case 2:
    Result.resize(NextRes+2);
    return SelectAddrIdx(N, Result[NextRes+0].first, Result[NextRes+1].first);
  case 3:
    Result.resize(NextRes+2);
    return SelectAddrImmX4(N, Result[NextRes+0].first, Result[NextRes+1].first);
  case 4:
    Result.resize(NextRes+1);
    return SelectAddrImmOffs(N, Result[NextRes+0].first);
  case 5:
    Result.resize(NextRes+1);
    return SelectAddr(N, Result[NextRes+0].first);
  }
}

virtual SDValue RunSDNodeXForm(SDValue V, unsigned XFormNo) {
  switch (XFormNo) {
  default: llvm_unreachable("Invalid xform # in table?");
  case 0: {  // HI16
    ConstantSDNode *N = cast<ConstantSDNode>(V.getNode());

  // Transformation function: shift the immediate value down into the low bits.
  return getI32Imm((unsigned)N->getZExtValue() >> 16);

  }
  case 1: {  // LO16
    ConstantSDNode *N = cast<ConstantSDNode>(V.getNode());

  // Transformation function: get the low 16 bits.
  return getI32Imm((unsigned short)N->getZExtValue());

  }
  case 2: {  // HA16
    ConstantSDNode *N = cast<ConstantSDNode>(V.getNode());

  // Transformation function: shift the immediate value down into the low bits.
  signed int Val = N->getZExtValue();
  return getI32Imm((Val - (signed short)Val) >> 16);

  }
  case 3: {  // MB
    ConstantSDNode *N = cast<ConstantSDNode>(V.getNode());

  // Transformation function: get the start bit of a mask
  unsigned mb = 0, me;
  (void)isRunOfOnes((unsigned)N->getZExtValue(), mb, me);
  return getI32Imm(mb);

  }
  case 4: {  // ME
    ConstantSDNode *N = cast<ConstantSDNode>(V.getNode());

  // Transformation function: get the end bit of a mask
  unsigned mb, me = 0;
  (void)isRunOfOnes((unsigned)N->getZExtValue(), mb, me);
  return getI32Imm(me);

  }
  case 5: {  // SHL32
    ConstantSDNode *N = cast<ConstantSDNode>(V.getNode());

  // Transformation function: 31 - imm
  return getI32Imm(31 - N->getZExtValue());

  }
  case 6: {  // SHL64
    ConstantSDNode *N = cast<ConstantSDNode>(V.getNode());

  // Transformation function: 63 - imm
  return getI32Imm(63 - N->getZExtValue());

  }
  case 7: {  // SRL32
    ConstantSDNode *N = cast<ConstantSDNode>(V.getNode());

  // Transformation function: 32 - imm
  return N->getZExtValue() ? getI32Imm(32 - N->getZExtValue()) : getI32Imm(0);

  }
  case 8: {  // SRL64
    ConstantSDNode *N = cast<ConstantSDNode>(V.getNode());

  // Transformation function: 64 - imm
  return N->getZExtValue() ? getI32Imm(64 - N->getZExtValue()) : getI32Imm(0);

  }
  case 9: {  // VSPLTB_get_imm
    SDNode *N = V.getNode();

  return getI32Imm(PPC::getVSPLTImmediate(N, 1));

  }
  case 10: {  // VSPLTH_get_imm
    SDNode *N = V.getNode();

  return getI32Imm(PPC::getVSPLTImmediate(N, 2));

  }
  case 11: {  // VSPLTW_get_imm
    SDNode *N = V.getNode();

  return getI32Imm(PPC::getVSPLTImmediate(N, 4));

  }
  case 12: {  // VSLDOI_unary_get_imm
    SDNode *N = V.getNode();

  return getI32Imm(PPC::isVSLDOIShuffleMask(N, true));

  }
  case 13: {  // VSLDOI_get_imm
    SDNode *N = V.getNode();

  return getI32Imm(PPC::isVSLDOIShuffleMask(N, false));

  }
  case 14: {  // VSPLTISB_get_imm
    SDNode *N = V.getNode();

  return PPC::get_VSPLTI_elt(N, 1, *CurDAG);

  }
  case 15: {  // VSPLTISH_get_imm
    SDNode *N = V.getNode();

  return PPC::get_VSPLTI_elt(N, 2, *CurDAG);

  }
  case 16: {  // VSPLTISW_get_imm
    SDNode *N = V.getNode();

  return PPC::get_VSPLTI_elt(N, 4, *CurDAG);

  }
  }
}


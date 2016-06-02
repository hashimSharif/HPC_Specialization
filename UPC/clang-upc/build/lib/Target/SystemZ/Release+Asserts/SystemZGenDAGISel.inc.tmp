/*===- TableGen'erated file -------------------------------------*- C++ -*-===*\
|*                                                                            *|
|*DAG Instruction Selector for the SystemZ target                             *|
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
/*0*/     OPC_SwitchOpcode /*106 cases */, 92|128,63/*8156*/,  TARGET_VAL(ISD::STORE),// ->8161
/*5*/       OPC_RecordMemRef,
/*6*/       OPC_RecordNode,   // #0 = 'st' chained node
/*7*/       OPC_Scope, 118|128,56/*7286*/, /*->7296*/ // 2 children in Scope
/*10*/        OPC_MoveChild, 1,
/*12*/        OPC_SwitchOpcode /*7 cases */, 81|128,13/*1745*/,  TARGET_VAL(SystemZISD::SELECT_CCMASK),// ->1762
/*17*/          OPC_CaptureGlueInput,
/*18*/          OPC_Scope, 78, /*->98*/ // 22 children in Scope
/*20*/            OPC_RecordChild0, // #1 = $new
/*21*/            OPC_MoveChild, 1,
/*23*/            OPC_CheckOpcode, TARGET_VAL(ISD::LOAD),
/*26*/            OPC_RecordMemRef,
/*27*/            OPC_RecordNode, // #2 = 'ld' chained node
/*28*/            OPC_CheckFoldableChainNode,
/*29*/            OPC_RecordChild1, // #3 = $addr
/*30*/            OPC_CheckChild1Type, MVT::i64,
/*32*/            OPC_CheckPredicate, 0, // Predicate_unindexedload
/*34*/            OPC_CheckPredicate, 1, // Predicate_anyextload
/*36*/            OPC_CheckPredicate, 2, // Predicate_anyextloadi8
/*38*/            OPC_CheckPredicate, 3, // Predicate_nonvolatile_anyextloadi8
/*40*/            OPC_MoveParent,
/*41*/            OPC_RecordChild2, // #4 = $valid
/*42*/            OPC_MoveChild, 2,
/*44*/            OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*47*/            OPC_CheckPredicate, 4, // Predicate_uimm8zx4
/*49*/            OPC_MoveParent,
/*50*/            OPC_RecordChild3, // #5 = $cc
/*51*/            OPC_MoveChild, 3,
/*53*/            OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*56*/            OPC_CheckPredicate, 4, // Predicate_uimm8zx4
/*58*/            OPC_MoveParent,
/*59*/            OPC_CheckType, MVT::i32,
/*61*/            OPC_MoveParent,
/*62*/            OPC_CheckChild2Same, 3,
/*64*/            OPC_CheckPredicate, 5, // Predicate_unindexedstore
/*66*/            OPC_CheckPredicate, 6, // Predicate_truncstore
/*68*/            OPC_CheckPredicate, 7, // Predicate_truncstorei8
/*70*/            OPC_CheckPredicate, 8, // Predicate_nonvolatile_truncstorei8
/*72*/            OPC_CheckPatternPredicate, 0, // (Subtarget.hasHighWord())
/*74*/            OPC_CheckComplexPat, /*CP*/0, /*#*/3, // selectBDXAddr20Only:$addr #6 #7 #8
/*77*/            OPC_EmitMergeInputChains, 2, 0, 2, 
/*81*/            OPC_EmitConvertToTarget, 4,
/*83*/            OPC_EmitConvertToTarget, 5,
/*85*/            OPC_MorphNodeTo, TARGET_VAL(SystemZ::CondStore8Mux), 0|OPFL_Chain|OPFL_GlueInput|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i32, 6/*#Ops*/, 1, 6, 7, 8, 9, 10, 
                  // Src: (st (z_select_ccmask:i32 GRX32:i32:$new, (ld:i32 bdxaddr20only:i64:$addr)<<P:Predicate_unindexedload>><<P:Predicate_anyextload>><<P:Predicate_anyextloadi8>><<P:Predicate_nonvolatile_anyextloadi8>>, (imm:i8)<<P:Predicate_uimm8zx4>>:$valid, (imm:i8)<<P:Predicate_uimm8zx4>>:$cc), bdxaddr20only:i64:$addr)<<P:Predicate_unindexedstore>><<P:Predicate_truncstore>><<P:Predicate_truncstorei8>><<P:Predicate_nonvolatile_truncstorei8>> - Complexity = 43
                  // Dst: (CondStore8Mux:i32 GRX32:i32:$new, bdxaddr20only:i64:$addr, (imm:i8):$valid, (imm:i8):$cc)
/*98*/          /*Scope*/ 78, /*->177*/
/*99*/            OPC_MoveChild, 0,
/*101*/           OPC_CheckOpcode, TARGET_VAL(ISD::LOAD),
/*104*/           OPC_RecordMemRef,
/*105*/           OPC_RecordNode, // #1 = 'ld' chained node
/*106*/           OPC_CheckFoldableChainNode,
/*107*/           OPC_RecordChild1, // #2 = $addr
/*108*/           OPC_CheckChild1Type, MVT::i64,
/*110*/           OPC_CheckPredicate, 0, // Predicate_unindexedload
/*112*/           OPC_CheckPredicate, 1, // Predicate_anyextload
/*114*/           OPC_CheckPredicate, 2, // Predicate_anyextloadi8
/*116*/           OPC_CheckPredicate, 3, // Predicate_nonvolatile_anyextloadi8
/*118*/           OPC_MoveParent,
/*119*/           OPC_RecordChild1, // #3 = $new
/*120*/           OPC_RecordChild2, // #4 = $valid
/*121*/           OPC_MoveChild, 2,
/*123*/           OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*126*/           OPC_CheckPredicate, 4, // Predicate_uimm8zx4
/*128*/           OPC_MoveParent,
/*129*/           OPC_RecordChild3, // #5 = $cc
/*130*/           OPC_MoveChild, 3,
/*132*/           OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*135*/           OPC_CheckPredicate, 4, // Predicate_uimm8zx4
/*137*/           OPC_MoveParent,
/*138*/           OPC_CheckType, MVT::i32,
/*140*/           OPC_MoveParent,
/*141*/           OPC_CheckChild2Same, 2,
/*143*/           OPC_CheckPredicate, 5, // Predicate_unindexedstore
/*145*/           OPC_CheckPredicate, 6, // Predicate_truncstore
/*147*/           OPC_CheckPredicate, 7, // Predicate_truncstorei8
/*149*/           OPC_CheckPredicate, 8, // Predicate_nonvolatile_truncstorei8
/*151*/           OPC_CheckPatternPredicate, 0, // (Subtarget.hasHighWord())
/*153*/           OPC_CheckComplexPat, /*CP*/0, /*#*/2, // selectBDXAddr20Only:$addr #6 #7 #8
/*156*/           OPC_EmitMergeInputChains, 2, 0, 1, 
/*160*/           OPC_EmitConvertToTarget, 4,
/*162*/           OPC_EmitConvertToTarget, 5,
/*164*/           OPC_MorphNodeTo, TARGET_VAL(SystemZ::CondStore8MuxInv), 0|OPFL_Chain|OPFL_GlueInput|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i32, 6/*#Ops*/, 3, 6, 7, 8, 9, 10, 
                  // Src: (st (z_select_ccmask:i32 (ld:i32 bdxaddr20only:i64:$addr)<<P:Predicate_unindexedload>><<P:Predicate_anyextload>><<P:Predicate_anyextloadi8>><<P:Predicate_nonvolatile_anyextloadi8>>, GRX32:i32:$new, (imm:i8)<<P:Predicate_uimm8zx4>>:$valid, (imm:i8)<<P:Predicate_uimm8zx4>>:$cc), bdxaddr20only:i64:$addr)<<P:Predicate_unindexedstore>><<P:Predicate_truncstore>><<P:Predicate_truncstorei8>><<P:Predicate_nonvolatile_truncstorei8>> - Complexity = 43
                  // Dst: (CondStore8MuxInv:i32 GRX32:i32:$new, bdxaddr20only:i64:$addr, (imm:i8):$valid, (imm:i8):$cc)
/*177*/         /*Scope*/ 78, /*->256*/
/*178*/           OPC_RecordChild0, // #1 = $new
/*179*/           OPC_MoveChild, 1,
/*181*/           OPC_CheckOpcode, TARGET_VAL(ISD::LOAD),
/*184*/           OPC_RecordMemRef,
/*185*/           OPC_RecordNode, // #2 = 'ld' chained node
/*186*/           OPC_CheckFoldableChainNode,
/*187*/           OPC_RecordChild1, // #3 = $addr
/*188*/           OPC_CheckChild1Type, MVT::i64,
/*190*/           OPC_CheckPredicate, 0, // Predicate_unindexedload
/*192*/           OPC_CheckPredicate, 1, // Predicate_anyextload
/*194*/           OPC_CheckPredicate, 9, // Predicate_anyextloadi16
/*196*/           OPC_CheckPredicate, 10, // Predicate_nonvolatile_anyextloadi16
/*198*/           OPC_MoveParent,
/*199*/           OPC_RecordChild2, // #4 = $valid
/*200*/           OPC_MoveChild, 2,
/*202*/           OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*205*/           OPC_CheckPredicate, 4, // Predicate_uimm8zx4
/*207*/           OPC_MoveParent,
/*208*/           OPC_RecordChild3, // #5 = $cc
/*209*/           OPC_MoveChild, 3,
/*211*/           OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*214*/           OPC_CheckPredicate, 4, // Predicate_uimm8zx4
/*216*/           OPC_MoveParent,
/*217*/           OPC_CheckType, MVT::i32,
/*219*/           OPC_MoveParent,
/*220*/           OPC_CheckChild2Same, 3,
/*222*/           OPC_CheckPredicate, 5, // Predicate_unindexedstore
/*224*/           OPC_CheckPredicate, 6, // Predicate_truncstore
/*226*/           OPC_CheckPredicate, 11, // Predicate_truncstorei16
/*228*/           OPC_CheckPredicate, 12, // Predicate_nonvolatile_truncstorei16
/*230*/           OPC_CheckPatternPredicate, 0, // (Subtarget.hasHighWord())
/*232*/           OPC_CheckComplexPat, /*CP*/0, /*#*/3, // selectBDXAddr20Only:$addr #6 #7 #8
/*235*/           OPC_EmitMergeInputChains, 2, 0, 2, 
/*239*/           OPC_EmitConvertToTarget, 4,
/*241*/           OPC_EmitConvertToTarget, 5,
/*243*/           OPC_MorphNodeTo, TARGET_VAL(SystemZ::CondStore16Mux), 0|OPFL_Chain|OPFL_GlueInput|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i32, 6/*#Ops*/, 1, 6, 7, 8, 9, 10, 
                  // Src: (st (z_select_ccmask:i32 GRX32:i32:$new, (ld:i32 bdxaddr20only:i64:$addr)<<P:Predicate_unindexedload>><<P:Predicate_anyextload>><<P:Predicate_anyextloadi16>><<P:Predicate_nonvolatile_anyextloadi16>>, (imm:i8)<<P:Predicate_uimm8zx4>>:$valid, (imm:i8)<<P:Predicate_uimm8zx4>>:$cc), bdxaddr20only:i64:$addr)<<P:Predicate_unindexedstore>><<P:Predicate_truncstore>><<P:Predicate_truncstorei16>><<P:Predicate_nonvolatile_truncstorei16>> - Complexity = 43
                  // Dst: (CondStore16Mux:i32 GRX32:i32:$new, bdxaddr20only:i64:$addr, (imm:i8):$valid, (imm:i8):$cc)
/*256*/         /*Scope*/ 78, /*->335*/
/*257*/           OPC_MoveChild, 0,
/*259*/           OPC_CheckOpcode, TARGET_VAL(ISD::LOAD),
/*262*/           OPC_RecordMemRef,
/*263*/           OPC_RecordNode, // #1 = 'ld' chained node
/*264*/           OPC_CheckFoldableChainNode,
/*265*/           OPC_RecordChild1, // #2 = $addr
/*266*/           OPC_CheckChild1Type, MVT::i64,
/*268*/           OPC_CheckPredicate, 0, // Predicate_unindexedload
/*270*/           OPC_CheckPredicate, 1, // Predicate_anyextload
/*272*/           OPC_CheckPredicate, 9, // Predicate_anyextloadi16
/*274*/           OPC_CheckPredicate, 10, // Predicate_nonvolatile_anyextloadi16
/*276*/           OPC_MoveParent,
/*277*/           OPC_RecordChild1, // #3 = $new
/*278*/           OPC_RecordChild2, // #4 = $valid
/*279*/           OPC_MoveChild, 2,
/*281*/           OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*284*/           OPC_CheckPredicate, 4, // Predicate_uimm8zx4
/*286*/           OPC_MoveParent,
/*287*/           OPC_RecordChild3, // #5 = $cc
/*288*/           OPC_MoveChild, 3,
/*290*/           OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*293*/           OPC_CheckPredicate, 4, // Predicate_uimm8zx4
/*295*/           OPC_MoveParent,
/*296*/           OPC_CheckType, MVT::i32,
/*298*/           OPC_MoveParent,
/*299*/           OPC_CheckChild2Same, 2,
/*301*/           OPC_CheckPredicate, 5, // Predicate_unindexedstore
/*303*/           OPC_CheckPredicate, 6, // Predicate_truncstore
/*305*/           OPC_CheckPredicate, 11, // Predicate_truncstorei16
/*307*/           OPC_CheckPredicate, 12, // Predicate_nonvolatile_truncstorei16
/*309*/           OPC_CheckPatternPredicate, 0, // (Subtarget.hasHighWord())
/*311*/           OPC_CheckComplexPat, /*CP*/0, /*#*/2, // selectBDXAddr20Only:$addr #6 #7 #8
/*314*/           OPC_EmitMergeInputChains, 2, 0, 1, 
/*318*/           OPC_EmitConvertToTarget, 4,
/*320*/           OPC_EmitConvertToTarget, 5,
/*322*/           OPC_MorphNodeTo, TARGET_VAL(SystemZ::CondStore16MuxInv), 0|OPFL_Chain|OPFL_GlueInput|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i32, 6/*#Ops*/, 3, 6, 7, 8, 9, 10, 
                  // Src: (st (z_select_ccmask:i32 (ld:i32 bdxaddr20only:i64:$addr)<<P:Predicate_unindexedload>><<P:Predicate_anyextload>><<P:Predicate_anyextloadi16>><<P:Predicate_nonvolatile_anyextloadi16>>, GRX32:i32:$new, (imm:i8)<<P:Predicate_uimm8zx4>>:$valid, (imm:i8)<<P:Predicate_uimm8zx4>>:$cc), bdxaddr20only:i64:$addr)<<P:Predicate_unindexedstore>><<P:Predicate_truncstore>><<P:Predicate_truncstorei16>><<P:Predicate_nonvolatile_truncstorei16>> - Complexity = 43
                  // Dst: (CondStore16MuxInv:i32 GRX32:i32:$new, bdxaddr20only:i64:$addr, (imm:i8):$valid, (imm:i8):$cc)
/*335*/         /*Scope*/ 76, /*->412*/
/*336*/           OPC_RecordChild0, // #1 = $new
/*337*/           OPC_MoveChild, 1,
/*339*/           OPC_CheckOpcode, TARGET_VAL(ISD::LOAD),
/*342*/           OPC_RecordMemRef,
/*343*/           OPC_RecordNode, // #2 = 'ld' chained node
/*344*/           OPC_CheckFoldableChainNode,
/*345*/           OPC_RecordChild1, // #3 = $addr
/*346*/           OPC_CheckChild1Type, MVT::i64,
/*348*/           OPC_CheckPredicate, 0, // Predicate_unindexedload
/*350*/           OPC_CheckPredicate, 1, // Predicate_anyextload
/*352*/           OPC_CheckPredicate, 2, // Predicate_anyextloadi8
/*354*/           OPC_CheckPredicate, 3, // Predicate_nonvolatile_anyextloadi8
/*356*/           OPC_MoveParent,
/*357*/           OPC_RecordChild2, // #4 = $valid
/*358*/           OPC_MoveChild, 2,
/*360*/           OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*363*/           OPC_CheckPredicate, 4, // Predicate_uimm8zx4
/*365*/           OPC_MoveParent,
/*366*/           OPC_RecordChild3, // #5 = $cc
/*367*/           OPC_MoveChild, 3,
/*369*/           OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*372*/           OPC_CheckPredicate, 4, // Predicate_uimm8zx4
/*374*/           OPC_MoveParent,
/*375*/           OPC_CheckType, MVT::i32,
/*377*/           OPC_MoveParent,
/*378*/           OPC_CheckChild2Same, 3,
/*380*/           OPC_CheckPredicate, 5, // Predicate_unindexedstore
/*382*/           OPC_CheckPredicate, 6, // Predicate_truncstore
/*384*/           OPC_CheckPredicate, 7, // Predicate_truncstorei8
/*386*/           OPC_CheckPredicate, 8, // Predicate_nonvolatile_truncstorei8
/*388*/           OPC_CheckComplexPat, /*CP*/0, /*#*/3, // selectBDXAddr20Only:$addr #6 #7 #8
/*391*/           OPC_EmitMergeInputChains, 2, 0, 2, 
/*395*/           OPC_EmitConvertToTarget, 4,
/*397*/           OPC_EmitConvertToTarget, 5,
/*399*/           OPC_MorphNodeTo, TARGET_VAL(SystemZ::CondStore8), 0|OPFL_Chain|OPFL_GlueInput|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i32, 6/*#Ops*/, 1, 6, 7, 8, 9, 10, 
                  // Src: (st (z_select_ccmask:i32 GR32:i32:$new, (ld:i32 bdxaddr20only:i64:$addr)<<P:Predicate_unindexedload>><<P:Predicate_anyextload>><<P:Predicate_anyextloadi8>><<P:Predicate_nonvolatile_anyextloadi8>>, (imm:i8)<<P:Predicate_uimm8zx4>>:$valid, (imm:i8)<<P:Predicate_uimm8zx4>>:$cc), bdxaddr20only:i64:$addr)<<P:Predicate_unindexedstore>><<P:Predicate_truncstore>><<P:Predicate_truncstorei8>><<P:Predicate_nonvolatile_truncstorei8>> - Complexity = 43
                  // Dst: (CondStore8:i32 GR32:i32:$new, bdxaddr20only:i64:$addr, (imm:i8):$valid, (imm:i8):$cc)
/*412*/         /*Scope*/ 76, /*->489*/
/*413*/           OPC_MoveChild, 0,
/*415*/           OPC_CheckOpcode, TARGET_VAL(ISD::LOAD),
/*418*/           OPC_RecordMemRef,
/*419*/           OPC_RecordNode, // #1 = 'ld' chained node
/*420*/           OPC_CheckFoldableChainNode,
/*421*/           OPC_RecordChild1, // #2 = $addr
/*422*/           OPC_CheckChild1Type, MVT::i64,
/*424*/           OPC_CheckPredicate, 0, // Predicate_unindexedload
/*426*/           OPC_CheckPredicate, 1, // Predicate_anyextload
/*428*/           OPC_CheckPredicate, 2, // Predicate_anyextloadi8
/*430*/           OPC_CheckPredicate, 3, // Predicate_nonvolatile_anyextloadi8
/*432*/           OPC_MoveParent,
/*433*/           OPC_RecordChild1, // #3 = $new
/*434*/           OPC_RecordChild2, // #4 = $valid
/*435*/           OPC_MoveChild, 2,
/*437*/           OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*440*/           OPC_CheckPredicate, 4, // Predicate_uimm8zx4
/*442*/           OPC_MoveParent,
/*443*/           OPC_RecordChild3, // #5 = $cc
/*444*/           OPC_MoveChild, 3,
/*446*/           OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*449*/           OPC_CheckPredicate, 4, // Predicate_uimm8zx4
/*451*/           OPC_MoveParent,
/*452*/           OPC_CheckType, MVT::i32,
/*454*/           OPC_MoveParent,
/*455*/           OPC_CheckChild2Same, 2,
/*457*/           OPC_CheckPredicate, 5, // Predicate_unindexedstore
/*459*/           OPC_CheckPredicate, 6, // Predicate_truncstore
/*461*/           OPC_CheckPredicate, 7, // Predicate_truncstorei8
/*463*/           OPC_CheckPredicate, 8, // Predicate_nonvolatile_truncstorei8
/*465*/           OPC_CheckComplexPat, /*CP*/0, /*#*/2, // selectBDXAddr20Only:$addr #6 #7 #8
/*468*/           OPC_EmitMergeInputChains, 2, 0, 1, 
/*472*/           OPC_EmitConvertToTarget, 4,
/*474*/           OPC_EmitConvertToTarget, 5,
/*476*/           OPC_MorphNodeTo, TARGET_VAL(SystemZ::CondStore8Inv), 0|OPFL_Chain|OPFL_GlueInput|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i32, 6/*#Ops*/, 3, 6, 7, 8, 9, 10, 
                  // Src: (st (z_select_ccmask:i32 (ld:i32 bdxaddr20only:i64:$addr)<<P:Predicate_unindexedload>><<P:Predicate_anyextload>><<P:Predicate_anyextloadi8>><<P:Predicate_nonvolatile_anyextloadi8>>, GR32:i32:$new, (imm:i8)<<P:Predicate_uimm8zx4>>:$valid, (imm:i8)<<P:Predicate_uimm8zx4>>:$cc), bdxaddr20only:i64:$addr)<<P:Predicate_unindexedstore>><<P:Predicate_truncstore>><<P:Predicate_truncstorei8>><<P:Predicate_nonvolatile_truncstorei8>> - Complexity = 43
                  // Dst: (CondStore8Inv:i32 GR32:i32:$new, bdxaddr20only:i64:$addr, (imm:i8):$valid, (imm:i8):$cc)
/*489*/         /*Scope*/ 76, /*->566*/
/*490*/           OPC_RecordChild0, // #1 = $new
/*491*/           OPC_MoveChild, 1,
/*493*/           OPC_CheckOpcode, TARGET_VAL(ISD::LOAD),
/*496*/           OPC_RecordMemRef,
/*497*/           OPC_RecordNode, // #2 = 'ld' chained node
/*498*/           OPC_CheckFoldableChainNode,
/*499*/           OPC_RecordChild1, // #3 = $addr
/*500*/           OPC_CheckChild1Type, MVT::i64,
/*502*/           OPC_CheckPredicate, 0, // Predicate_unindexedload
/*504*/           OPC_CheckPredicate, 1, // Predicate_anyextload
/*506*/           OPC_CheckPredicate, 9, // Predicate_anyextloadi16
/*508*/           OPC_CheckPredicate, 10, // Predicate_nonvolatile_anyextloadi16
/*510*/           OPC_MoveParent,
/*511*/           OPC_RecordChild2, // #4 = $valid
/*512*/           OPC_MoveChild, 2,
/*514*/           OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*517*/           OPC_CheckPredicate, 4, // Predicate_uimm8zx4
/*519*/           OPC_MoveParent,
/*520*/           OPC_RecordChild3, // #5 = $cc
/*521*/           OPC_MoveChild, 3,
/*523*/           OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*526*/           OPC_CheckPredicate, 4, // Predicate_uimm8zx4
/*528*/           OPC_MoveParent,
/*529*/           OPC_CheckType, MVT::i32,
/*531*/           OPC_MoveParent,
/*532*/           OPC_CheckChild2Same, 3,
/*534*/           OPC_CheckPredicate, 5, // Predicate_unindexedstore
/*536*/           OPC_CheckPredicate, 6, // Predicate_truncstore
/*538*/           OPC_CheckPredicate, 11, // Predicate_truncstorei16
/*540*/           OPC_CheckPredicate, 12, // Predicate_nonvolatile_truncstorei16
/*542*/           OPC_CheckComplexPat, /*CP*/0, /*#*/3, // selectBDXAddr20Only:$addr #6 #7 #8
/*545*/           OPC_EmitMergeInputChains, 2, 0, 2, 
/*549*/           OPC_EmitConvertToTarget, 4,
/*551*/           OPC_EmitConvertToTarget, 5,
/*553*/           OPC_MorphNodeTo, TARGET_VAL(SystemZ::CondStore16), 0|OPFL_Chain|OPFL_GlueInput|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i32, 6/*#Ops*/, 1, 6, 7, 8, 9, 10, 
                  // Src: (st (z_select_ccmask:i32 GR32:i32:$new, (ld:i32 bdxaddr20only:i64:$addr)<<P:Predicate_unindexedload>><<P:Predicate_anyextload>><<P:Predicate_anyextloadi16>><<P:Predicate_nonvolatile_anyextloadi16>>, (imm:i8)<<P:Predicate_uimm8zx4>>:$valid, (imm:i8)<<P:Predicate_uimm8zx4>>:$cc), bdxaddr20only:i64:$addr)<<P:Predicate_unindexedstore>><<P:Predicate_truncstore>><<P:Predicate_truncstorei16>><<P:Predicate_nonvolatile_truncstorei16>> - Complexity = 43
                  // Dst: (CondStore16:i32 GR32:i32:$new, bdxaddr20only:i64:$addr, (imm:i8):$valid, (imm:i8):$cc)
/*566*/         /*Scope*/ 76, /*->643*/
/*567*/           OPC_MoveChild, 0,
/*569*/           OPC_CheckOpcode, TARGET_VAL(ISD::LOAD),
/*572*/           OPC_RecordMemRef,
/*573*/           OPC_RecordNode, // #1 = 'ld' chained node
/*574*/           OPC_CheckFoldableChainNode,
/*575*/           OPC_RecordChild1, // #2 = $addr
/*576*/           OPC_CheckChild1Type, MVT::i64,
/*578*/           OPC_CheckPredicate, 0, // Predicate_unindexedload
/*580*/           OPC_CheckPredicate, 1, // Predicate_anyextload
/*582*/           OPC_CheckPredicate, 9, // Predicate_anyextloadi16
/*584*/           OPC_CheckPredicate, 10, // Predicate_nonvolatile_anyextloadi16
/*586*/           OPC_MoveParent,
/*587*/           OPC_RecordChild1, // #3 = $new
/*588*/           OPC_RecordChild2, // #4 = $valid
/*589*/           OPC_MoveChild, 2,
/*591*/           OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*594*/           OPC_CheckPredicate, 4, // Predicate_uimm8zx4
/*596*/           OPC_MoveParent,
/*597*/           OPC_RecordChild3, // #5 = $cc
/*598*/           OPC_MoveChild, 3,
/*600*/           OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*603*/           OPC_CheckPredicate, 4, // Predicate_uimm8zx4
/*605*/           OPC_MoveParent,
/*606*/           OPC_CheckType, MVT::i32,
/*608*/           OPC_MoveParent,
/*609*/           OPC_CheckChild2Same, 2,
/*611*/           OPC_CheckPredicate, 5, // Predicate_unindexedstore
/*613*/           OPC_CheckPredicate, 6, // Predicate_truncstore
/*615*/           OPC_CheckPredicate, 11, // Predicate_truncstorei16
/*617*/           OPC_CheckPredicate, 12, // Predicate_nonvolatile_truncstorei16
/*619*/           OPC_CheckComplexPat, /*CP*/0, /*#*/2, // selectBDXAddr20Only:$addr #6 #7 #8
/*622*/           OPC_EmitMergeInputChains, 2, 0, 1, 
/*626*/           OPC_EmitConvertToTarget, 4,
/*628*/           OPC_EmitConvertToTarget, 5,
/*630*/           OPC_MorphNodeTo, TARGET_VAL(SystemZ::CondStore16Inv), 0|OPFL_Chain|OPFL_GlueInput|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i32, 6/*#Ops*/, 3, 6, 7, 8, 9, 10, 
                  // Src: (st (z_select_ccmask:i32 (ld:i32 bdxaddr20only:i64:$addr)<<P:Predicate_unindexedload>><<P:Predicate_anyextload>><<P:Predicate_anyextloadi16>><<P:Predicate_nonvolatile_anyextloadi16>>, GR32:i32:$new, (imm:i8)<<P:Predicate_uimm8zx4>>:$valid, (imm:i8)<<P:Predicate_uimm8zx4>>:$cc), bdxaddr20only:i64:$addr)<<P:Predicate_unindexedstore>><<P:Predicate_truncstore>><<P:Predicate_truncstorei16>><<P:Predicate_nonvolatile_truncstorei16>> - Complexity = 43
                  // Dst: (CondStore16Inv:i32 GR32:i32:$new, bdxaddr20only:i64:$addr, (imm:i8):$valid, (imm:i8):$cc)
/*643*/         /*Scope*/ 72, /*->716*/
/*644*/           OPC_RecordChild0, // #1 = $new
/*645*/           OPC_MoveChild, 1,
/*647*/           OPC_CheckOpcode, TARGET_VAL(ISD::LOAD),
/*650*/           OPC_RecordMemRef,
/*651*/           OPC_RecordNode, // #2 = 'ld' chained node
/*652*/           OPC_CheckFoldableChainNode,
/*653*/           OPC_RecordChild1, // #3 = $addr
/*654*/           OPC_CheckChild1Type, MVT::i64,
/*656*/           OPC_CheckPredicate, 0, // Predicate_unindexedload
/*658*/           OPC_CheckPredicate, 13, // Predicate_load
/*660*/           OPC_CheckPredicate, 14, // Predicate_nonvolatile_load
/*662*/           OPC_MoveParent,
/*663*/           OPC_RecordChild2, // #4 = $valid
/*664*/           OPC_MoveChild, 2,
/*666*/           OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*669*/           OPC_CheckPredicate, 4, // Predicate_uimm8zx4
/*671*/           OPC_MoveParent,
/*672*/           OPC_RecordChild3, // #5 = $cc
/*673*/           OPC_MoveChild, 3,
/*675*/           OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*678*/           OPC_CheckPredicate, 4, // Predicate_uimm8zx4
/*680*/           OPC_MoveParent,
/*681*/           OPC_CheckType, MVT::i32,
/*683*/           OPC_MoveParent,
/*684*/           OPC_CheckChild2Same, 3,
/*686*/           OPC_CheckPredicate, 5, // Predicate_unindexedstore
/*688*/           OPC_CheckPredicate, 15, // Predicate_store
/*690*/           OPC_CheckPredicate, 16, // Predicate_nonvolatile_store
/*692*/           OPC_CheckComplexPat, /*CP*/0, /*#*/3, // selectBDXAddr20Only:$addr #6 #7 #8
/*695*/           OPC_EmitMergeInputChains, 2, 0, 2, 
/*699*/           OPC_EmitConvertToTarget, 4,
/*701*/           OPC_EmitConvertToTarget, 5,
/*703*/           OPC_MorphNodeTo, TARGET_VAL(SystemZ::CondStore32), 0|OPFL_Chain|OPFL_GlueInput|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i32, 6/*#Ops*/, 1, 6, 7, 8, 9, 10, 
                  // Src: (st (z_select_ccmask:i32 GR32:i32:$new, (ld:i32 bdxaddr20only:i64:$addr)<<P:Predicate_unindexedload>><<P:Predicate_load>><<P:Predicate_nonvolatile_load>>, (imm:i8)<<P:Predicate_uimm8zx4>>:$valid, (imm:i8)<<P:Predicate_uimm8zx4>>:$cc), bdxaddr20only:i64:$addr)<<P:Predicate_unindexedstore>><<P:Predicate_store>><<P:Predicate_nonvolatile_store>> - Complexity = 43
                  // Dst: (CondStore32:i32 GR32:i32:$new, bdxaddr20only:i64:$addr, (imm:i8):$valid, (imm:i8):$cc)
/*716*/         /*Scope*/ 72, /*->789*/
/*717*/           OPC_MoveChild, 0,
/*719*/           OPC_CheckOpcode, TARGET_VAL(ISD::LOAD),
/*722*/           OPC_RecordMemRef,
/*723*/           OPC_RecordNode, // #1 = 'ld' chained node
/*724*/           OPC_CheckFoldableChainNode,
/*725*/           OPC_RecordChild1, // #2 = $addr
/*726*/           OPC_CheckChild1Type, MVT::i64,
/*728*/           OPC_CheckPredicate, 0, // Predicate_unindexedload
/*730*/           OPC_CheckPredicate, 13, // Predicate_load
/*732*/           OPC_CheckPredicate, 14, // Predicate_nonvolatile_load
/*734*/           OPC_MoveParent,
/*735*/           OPC_RecordChild1, // #3 = $new
/*736*/           OPC_RecordChild2, // #4 = $valid
/*737*/           OPC_MoveChild, 2,
/*739*/           OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*742*/           OPC_CheckPredicate, 4, // Predicate_uimm8zx4
/*744*/           OPC_MoveParent,
/*745*/           OPC_RecordChild3, // #5 = $cc
/*746*/           OPC_MoveChild, 3,
/*748*/           OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*751*/           OPC_CheckPredicate, 4, // Predicate_uimm8zx4
/*753*/           OPC_MoveParent,
/*754*/           OPC_CheckType, MVT::i32,
/*756*/           OPC_MoveParent,
/*757*/           OPC_CheckChild2Same, 2,
/*759*/           OPC_CheckPredicate, 5, // Predicate_unindexedstore
/*761*/           OPC_CheckPredicate, 15, // Predicate_store
/*763*/           OPC_CheckPredicate, 16, // Predicate_nonvolatile_store
/*765*/           OPC_CheckComplexPat, /*CP*/0, /*#*/2, // selectBDXAddr20Only:$addr #6 #7 #8
/*768*/           OPC_EmitMergeInputChains, 2, 0, 1, 
/*772*/           OPC_EmitConvertToTarget, 4,
/*774*/           OPC_EmitConvertToTarget, 5,
/*776*/           OPC_MorphNodeTo, TARGET_VAL(SystemZ::CondStore32Inv), 0|OPFL_Chain|OPFL_GlueInput|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i32, 6/*#Ops*/, 3, 6, 7, 8, 9, 10, 
                  // Src: (st (z_select_ccmask:i32 (ld:i32 bdxaddr20only:i64:$addr)<<P:Predicate_unindexedload>><<P:Predicate_load>><<P:Predicate_nonvolatile_load>>, GR32:i32:$new, (imm:i8)<<P:Predicate_uimm8zx4>>:$valid, (imm:i8)<<P:Predicate_uimm8zx4>>:$cc), bdxaddr20only:i64:$addr)<<P:Predicate_unindexedstore>><<P:Predicate_store>><<P:Predicate_nonvolatile_store>> - Complexity = 43
                  // Dst: (CondStore32Inv:i32 GR32:i32:$new, bdxaddr20only:i64:$addr, (imm:i8):$valid, (imm:i8):$cc)
/*789*/         /*Scope*/ 72, /*->862*/
/*790*/           OPC_RecordChild0, // #1 = $new
/*791*/           OPC_MoveChild, 1,
/*793*/           OPC_CheckOpcode, TARGET_VAL(ISD::LOAD),
/*796*/           OPC_RecordMemRef,
/*797*/           OPC_RecordNode, // #2 = 'ld' chained node
/*798*/           OPC_CheckFoldableChainNode,
/*799*/           OPC_RecordChild1, // #3 = $addr
/*800*/           OPC_CheckChild1Type, MVT::i64,
/*802*/           OPC_CheckPredicate, 0, // Predicate_unindexedload
/*804*/           OPC_CheckPredicate, 13, // Predicate_load
/*806*/           OPC_CheckPredicate, 14, // Predicate_nonvolatile_load
/*808*/           OPC_MoveParent,
/*809*/           OPC_RecordChild2, // #4 = $valid
/*810*/           OPC_MoveChild, 2,
/*812*/           OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*815*/           OPC_CheckPredicate, 4, // Predicate_uimm8zx4
/*817*/           OPC_MoveParent,
/*818*/           OPC_RecordChild3, // #5 = $cc
/*819*/           OPC_MoveChild, 3,
/*821*/           OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*824*/           OPC_CheckPredicate, 4, // Predicate_uimm8zx4
/*826*/           OPC_MoveParent,
/*827*/           OPC_CheckType, MVT::i64,
/*829*/           OPC_MoveParent,
/*830*/           OPC_CheckChild2Same, 3,
/*832*/           OPC_CheckPredicate, 5, // Predicate_unindexedstore
/*834*/           OPC_CheckPredicate, 15, // Predicate_store
/*836*/           OPC_CheckPredicate, 16, // Predicate_nonvolatile_store
/*838*/           OPC_CheckComplexPat, /*CP*/0, /*#*/3, // selectBDXAddr20Only:$addr #6 #7 #8
/*841*/           OPC_EmitMergeInputChains, 2, 0, 2, 
/*845*/           OPC_EmitConvertToTarget, 4,
/*847*/           OPC_EmitConvertToTarget, 5,
/*849*/           OPC_MorphNodeTo, TARGET_VAL(SystemZ::CondStore64), 0|OPFL_Chain|OPFL_GlueInput|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i32, 6/*#Ops*/, 1, 6, 7, 8, 9, 10, 
                  // Src: (st (z_select_ccmask:i64 GR64:i64:$new, (ld:i64 bdxaddr20only:i64:$addr)<<P:Predicate_unindexedload>><<P:Predicate_load>><<P:Predicate_nonvolatile_load>>, (imm:i8)<<P:Predicate_uimm8zx4>>:$valid, (imm:i8)<<P:Predicate_uimm8zx4>>:$cc), bdxaddr20only:i64:$addr)<<P:Predicate_unindexedstore>><<P:Predicate_store>><<P:Predicate_nonvolatile_store>> - Complexity = 43
                  // Dst: (CondStore64:i32 GR64:i64:$new, bdxaddr20only:i64:$addr, (imm:i8):$valid, (imm:i8):$cc)
/*862*/         /*Scope*/ 72, /*->935*/
/*863*/           OPC_MoveChild, 0,
/*865*/           OPC_CheckOpcode, TARGET_VAL(ISD::LOAD),
/*868*/           OPC_RecordMemRef,
/*869*/           OPC_RecordNode, // #1 = 'ld' chained node
/*870*/           OPC_CheckFoldableChainNode,
/*871*/           OPC_RecordChild1, // #2 = $addr
/*872*/           OPC_CheckChild1Type, MVT::i64,
/*874*/           OPC_CheckPredicate, 0, // Predicate_unindexedload
/*876*/           OPC_CheckPredicate, 13, // Predicate_load
/*878*/           OPC_CheckPredicate, 14, // Predicate_nonvolatile_load
/*880*/           OPC_MoveParent,
/*881*/           OPC_RecordChild1, // #3 = $new
/*882*/           OPC_RecordChild2, // #4 = $valid
/*883*/           OPC_MoveChild, 2,
/*885*/           OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*888*/           OPC_CheckPredicate, 4, // Predicate_uimm8zx4
/*890*/           OPC_MoveParent,
/*891*/           OPC_RecordChild3, // #5 = $cc
/*892*/           OPC_MoveChild, 3,
/*894*/           OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*897*/           OPC_CheckPredicate, 4, // Predicate_uimm8zx4
/*899*/           OPC_MoveParent,
/*900*/           OPC_CheckType, MVT::i64,
/*902*/           OPC_MoveParent,
/*903*/           OPC_CheckChild2Same, 2,
/*905*/           OPC_CheckPredicate, 5, // Predicate_unindexedstore
/*907*/           OPC_CheckPredicate, 15, // Predicate_store
/*909*/           OPC_CheckPredicate, 16, // Predicate_nonvolatile_store
/*911*/           OPC_CheckComplexPat, /*CP*/0, /*#*/2, // selectBDXAddr20Only:$addr #6 #7 #8
/*914*/           OPC_EmitMergeInputChains, 2, 0, 1, 
/*918*/           OPC_EmitConvertToTarget, 4,
/*920*/           OPC_EmitConvertToTarget, 5,
/*922*/           OPC_MorphNodeTo, TARGET_VAL(SystemZ::CondStore64Inv), 0|OPFL_Chain|OPFL_GlueInput|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i32, 6/*#Ops*/, 3, 6, 7, 8, 9, 10, 
                  // Src: (st (z_select_ccmask:i64 (ld:i64 bdxaddr20only:i64:$addr)<<P:Predicate_unindexedload>><<P:Predicate_load>><<P:Predicate_nonvolatile_load>>, GR64:i64:$new, (imm:i8)<<P:Predicate_uimm8zx4>>:$valid, (imm:i8)<<P:Predicate_uimm8zx4>>:$cc), bdxaddr20only:i64:$addr)<<P:Predicate_unindexedstore>><<P:Predicate_store>><<P:Predicate_nonvolatile_store>> - Complexity = 43
                  // Dst: (CondStore64Inv:i32 GR64:i64:$new, bdxaddr20only:i64:$addr, (imm:i8):$valid, (imm:i8):$cc)
/*935*/         /*Scope*/ 72, /*->1008*/
/*936*/           OPC_RecordChild0, // #1 = $new
/*937*/           OPC_MoveChild, 1,
/*939*/           OPC_CheckOpcode, TARGET_VAL(ISD::LOAD),
/*942*/           OPC_RecordMemRef,
/*943*/           OPC_RecordNode, // #2 = 'ld' chained node
/*944*/           OPC_CheckFoldableChainNode,
/*945*/           OPC_RecordChild1, // #3 = $addr
/*946*/           OPC_CheckChild1Type, MVT::i64,
/*948*/           OPC_CheckPredicate, 0, // Predicate_unindexedload
/*950*/           OPC_CheckPredicate, 13, // Predicate_load
/*952*/           OPC_CheckPredicate, 14, // Predicate_nonvolatile_load
/*954*/           OPC_MoveParent,
/*955*/           OPC_RecordChild2, // #4 = $valid
/*956*/           OPC_MoveChild, 2,
/*958*/           OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*961*/           OPC_CheckPredicate, 4, // Predicate_uimm8zx4
/*963*/           OPC_MoveParent,
/*964*/           OPC_RecordChild3, // #5 = $cc
/*965*/           OPC_MoveChild, 3,
/*967*/           OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*970*/           OPC_CheckPredicate, 4, // Predicate_uimm8zx4
/*972*/           OPC_MoveParent,
/*973*/           OPC_CheckType, MVT::f32,
/*975*/           OPC_MoveParent,
/*976*/           OPC_CheckChild2Same, 3,
/*978*/           OPC_CheckPredicate, 5, // Predicate_unindexedstore
/*980*/           OPC_CheckPredicate, 15, // Predicate_store
/*982*/           OPC_CheckPredicate, 16, // Predicate_nonvolatile_store
/*984*/           OPC_CheckComplexPat, /*CP*/0, /*#*/3, // selectBDXAddr20Only:$addr #6 #7 #8
/*987*/           OPC_EmitMergeInputChains, 2, 0, 2, 
/*991*/           OPC_EmitConvertToTarget, 4,
/*993*/           OPC_EmitConvertToTarget, 5,
/*995*/           OPC_MorphNodeTo, TARGET_VAL(SystemZ::CondStoreF32), 0|OPFL_Chain|OPFL_GlueInput|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i32, 6/*#Ops*/, 1, 6, 7, 8, 9, 10, 
                  // Src: (st (z_select_ccmask:f32 FP32:f32:$new, (ld:f32 bdxaddr20only:i64:$addr)<<P:Predicate_unindexedload>><<P:Predicate_load>><<P:Predicate_nonvolatile_load>>, (imm:i8)<<P:Predicate_uimm8zx4>>:$valid, (imm:i8)<<P:Predicate_uimm8zx4>>:$cc), bdxaddr20only:i64:$addr)<<P:Predicate_unindexedstore>><<P:Predicate_store>><<P:Predicate_nonvolatile_store>> - Complexity = 43
                  // Dst: (CondStoreF32:i32 FP32:f32:$new, bdxaddr20only:i64:$addr, (imm:i8):$valid, (imm:i8):$cc)
/*1008*/        /*Scope*/ 72, /*->1081*/
/*1009*/          OPC_MoveChild, 0,
/*1011*/          OPC_CheckOpcode, TARGET_VAL(ISD::LOAD),
/*1014*/          OPC_RecordMemRef,
/*1015*/          OPC_RecordNode, // #1 = 'ld' chained node
/*1016*/          OPC_CheckFoldableChainNode,
/*1017*/          OPC_RecordChild1, // #2 = $addr
/*1018*/          OPC_CheckChild1Type, MVT::i64,
/*1020*/          OPC_CheckPredicate, 0, // Predicate_unindexedload
/*1022*/          OPC_CheckPredicate, 13, // Predicate_load
/*1024*/          OPC_CheckPredicate, 14, // Predicate_nonvolatile_load
/*1026*/          OPC_MoveParent,
/*1027*/          OPC_RecordChild1, // #3 = $new
/*1028*/          OPC_RecordChild2, // #4 = $valid
/*1029*/          OPC_MoveChild, 2,
/*1031*/          OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*1034*/          OPC_CheckPredicate, 4, // Predicate_uimm8zx4
/*1036*/          OPC_MoveParent,
/*1037*/          OPC_RecordChild3, // #5 = $cc
/*1038*/          OPC_MoveChild, 3,
/*1040*/          OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*1043*/          OPC_CheckPredicate, 4, // Predicate_uimm8zx4
/*1045*/          OPC_MoveParent,
/*1046*/          OPC_CheckType, MVT::f32,
/*1048*/          OPC_MoveParent,
/*1049*/          OPC_CheckChild2Same, 2,
/*1051*/          OPC_CheckPredicate, 5, // Predicate_unindexedstore
/*1053*/          OPC_CheckPredicate, 15, // Predicate_store
/*1055*/          OPC_CheckPredicate, 16, // Predicate_nonvolatile_store
/*1057*/          OPC_CheckComplexPat, /*CP*/0, /*#*/2, // selectBDXAddr20Only:$addr #6 #7 #8
/*1060*/          OPC_EmitMergeInputChains, 2, 0, 1, 
/*1064*/          OPC_EmitConvertToTarget, 4,
/*1066*/          OPC_EmitConvertToTarget, 5,
/*1068*/          OPC_MorphNodeTo, TARGET_VAL(SystemZ::CondStoreF32Inv), 0|OPFL_Chain|OPFL_GlueInput|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i32, 6/*#Ops*/, 3, 6, 7, 8, 9, 10, 
                  // Src: (st (z_select_ccmask:f32 (ld:f32 bdxaddr20only:i64:$addr)<<P:Predicate_unindexedload>><<P:Predicate_load>><<P:Predicate_nonvolatile_load>>, FP32:f32:$new, (imm:i8)<<P:Predicate_uimm8zx4>>:$valid, (imm:i8)<<P:Predicate_uimm8zx4>>:$cc), bdxaddr20only:i64:$addr)<<P:Predicate_unindexedstore>><<P:Predicate_store>><<P:Predicate_nonvolatile_store>> - Complexity = 43
                  // Dst: (CondStoreF32Inv:i32 FP32:f32:$new, bdxaddr20only:i64:$addr, (imm:i8):$valid, (imm:i8):$cc)
/*1081*/        /*Scope*/ 72, /*->1154*/
/*1082*/          OPC_RecordChild0, // #1 = $new
/*1083*/          OPC_MoveChild, 1,
/*1085*/          OPC_CheckOpcode, TARGET_VAL(ISD::LOAD),
/*1088*/          OPC_RecordMemRef,
/*1089*/          OPC_RecordNode, // #2 = 'ld' chained node
/*1090*/          OPC_CheckFoldableChainNode,
/*1091*/          OPC_RecordChild1, // #3 = $addr
/*1092*/          OPC_CheckChild1Type, MVT::i64,
/*1094*/          OPC_CheckPredicate, 0, // Predicate_unindexedload
/*1096*/          OPC_CheckPredicate, 13, // Predicate_load
/*1098*/          OPC_CheckPredicate, 14, // Predicate_nonvolatile_load
/*1100*/          OPC_MoveParent,
/*1101*/          OPC_RecordChild2, // #4 = $valid
/*1102*/          OPC_MoveChild, 2,
/*1104*/          OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*1107*/          OPC_CheckPredicate, 4, // Predicate_uimm8zx4
/*1109*/          OPC_MoveParent,
/*1110*/          OPC_RecordChild3, // #5 = $cc
/*1111*/          OPC_MoveChild, 3,
/*1113*/          OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*1116*/          OPC_CheckPredicate, 4, // Predicate_uimm8zx4
/*1118*/          OPC_MoveParent,
/*1119*/          OPC_CheckType, MVT::f64,
/*1121*/          OPC_MoveParent,
/*1122*/          OPC_CheckChild2Same, 3,
/*1124*/          OPC_CheckPredicate, 5, // Predicate_unindexedstore
/*1126*/          OPC_CheckPredicate, 15, // Predicate_store
/*1128*/          OPC_CheckPredicate, 16, // Predicate_nonvolatile_store
/*1130*/          OPC_CheckComplexPat, /*CP*/0, /*#*/3, // selectBDXAddr20Only:$addr #6 #7 #8
/*1133*/          OPC_EmitMergeInputChains, 2, 0, 2, 
/*1137*/          OPC_EmitConvertToTarget, 4,
/*1139*/          OPC_EmitConvertToTarget, 5,
/*1141*/          OPC_MorphNodeTo, TARGET_VAL(SystemZ::CondStoreF64), 0|OPFL_Chain|OPFL_GlueInput|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i32, 6/*#Ops*/, 1, 6, 7, 8, 9, 10, 
                  // Src: (st (z_select_ccmask:f64 FP64:f64:$new, (ld:f64 bdxaddr20only:i64:$addr)<<P:Predicate_unindexedload>><<P:Predicate_load>><<P:Predicate_nonvolatile_load>>, (imm:i8)<<P:Predicate_uimm8zx4>>:$valid, (imm:i8)<<P:Predicate_uimm8zx4>>:$cc), bdxaddr20only:i64:$addr)<<P:Predicate_unindexedstore>><<P:Predicate_store>><<P:Predicate_nonvolatile_store>> - Complexity = 43
                  // Dst: (CondStoreF64:i32 FP64:f64:$new, bdxaddr20only:i64:$addr, (imm:i8):$valid, (imm:i8):$cc)
/*1154*/        /*Scope*/ 72, /*->1227*/
/*1155*/          OPC_MoveChild, 0,
/*1157*/          OPC_CheckOpcode, TARGET_VAL(ISD::LOAD),
/*1160*/          OPC_RecordMemRef,
/*1161*/          OPC_RecordNode, // #1 = 'ld' chained node
/*1162*/          OPC_CheckFoldableChainNode,
/*1163*/          OPC_RecordChild1, // #2 = $addr
/*1164*/          OPC_CheckChild1Type, MVT::i64,
/*1166*/          OPC_CheckPredicate, 0, // Predicate_unindexedload
/*1168*/          OPC_CheckPredicate, 13, // Predicate_load
/*1170*/          OPC_CheckPredicate, 14, // Predicate_nonvolatile_load
/*1172*/          OPC_MoveParent,
/*1173*/          OPC_RecordChild1, // #3 = $new
/*1174*/          OPC_RecordChild2, // #4 = $valid
/*1175*/          OPC_MoveChild, 2,
/*1177*/          OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*1180*/          OPC_CheckPredicate, 4, // Predicate_uimm8zx4
/*1182*/          OPC_MoveParent,
/*1183*/          OPC_RecordChild3, // #5 = $cc
/*1184*/          OPC_MoveChild, 3,
/*1186*/          OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*1189*/          OPC_CheckPredicate, 4, // Predicate_uimm8zx4
/*1191*/          OPC_MoveParent,
/*1192*/          OPC_CheckType, MVT::f64,
/*1194*/          OPC_MoveParent,
/*1195*/          OPC_CheckChild2Same, 2,
/*1197*/          OPC_CheckPredicate, 5, // Predicate_unindexedstore
/*1199*/          OPC_CheckPredicate, 15, // Predicate_store
/*1201*/          OPC_CheckPredicate, 16, // Predicate_nonvolatile_store
/*1203*/          OPC_CheckComplexPat, /*CP*/0, /*#*/2, // selectBDXAddr20Only:$addr #6 #7 #8
/*1206*/          OPC_EmitMergeInputChains, 2, 0, 1, 
/*1210*/          OPC_EmitConvertToTarget, 4,
/*1212*/          OPC_EmitConvertToTarget, 5,
/*1214*/          OPC_MorphNodeTo, TARGET_VAL(SystemZ::CondStoreF64Inv), 0|OPFL_Chain|OPFL_GlueInput|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i32, 6/*#Ops*/, 3, 6, 7, 8, 9, 10, 
                  // Src: (st (z_select_ccmask:f64 (ld:f64 bdxaddr20only:i64:$addr)<<P:Predicate_unindexedload>><<P:Predicate_load>><<P:Predicate_nonvolatile_load>>, FP64:f64:$new, (imm:i8)<<P:Predicate_uimm8zx4>>:$valid, (imm:i8)<<P:Predicate_uimm8zx4>>:$cc), bdxaddr20only:i64:$addr)<<P:Predicate_unindexedstore>><<P:Predicate_store>><<P:Predicate_nonvolatile_store>> - Complexity = 43
                  // Dst: (CondStoreF64Inv:i32 FP64:f64:$new, bdxaddr20only:i64:$addr, (imm:i8):$valid, (imm:i8):$cc)
/*1227*/        /*Scope*/ 88, /*->1316*/
/*1228*/          OPC_RecordChild0, // #1 = $new
/*1229*/          OPC_MoveChild, 1,
/*1231*/          OPC_CheckOpcode, TARGET_VAL(ISD::LOAD),
/*1234*/          OPC_RecordMemRef,
/*1235*/          OPC_RecordNode, // #2 = 'ld' chained node
/*1236*/          OPC_CheckFoldableChainNode,
/*1237*/          OPC_RecordChild1, // #3 = $addr
/*1238*/          OPC_CheckChild1Type, MVT::i64,
/*1240*/          OPC_CheckPredicate, 0, // Predicate_unindexedload
/*1242*/          OPC_CheckPredicate, 1, // Predicate_anyextload
/*1244*/          OPC_CheckPredicate, 2, // Predicate_anyextloadi8
/*1246*/          OPC_CheckPredicate, 3, // Predicate_nonvolatile_anyextloadi8
/*1248*/          OPC_MoveParent,
/*1249*/          OPC_RecordChild2, // #4 = $valid
/*1250*/          OPC_MoveChild, 2,
/*1252*/          OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*1255*/          OPC_CheckPredicate, 4, // Predicate_uimm8zx4
/*1257*/          OPC_MoveParent,
/*1258*/          OPC_RecordChild3, // #5 = $cc
/*1259*/          OPC_MoveChild, 3,
/*1261*/          OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*1264*/          OPC_CheckPredicate, 4, // Predicate_uimm8zx4
/*1266*/          OPC_MoveParent,
/*1267*/          OPC_CheckType, MVT::i64,
/*1269*/          OPC_MoveParent,
/*1270*/          OPC_CheckChild2Same, 3,
/*1272*/          OPC_CheckPredicate, 5, // Predicate_unindexedstore
/*1274*/          OPC_CheckPredicate, 6, // Predicate_truncstore
/*1276*/          OPC_CheckPredicate, 7, // Predicate_truncstorei8
/*1278*/          OPC_CheckPredicate, 8, // Predicate_nonvolatile_truncstorei8
/*1280*/          OPC_CheckComplexPat, /*CP*/0, /*#*/3, // selectBDXAddr20Only:$addr #6 #7 #8
/*1283*/          OPC_EmitMergeInputChains, 2, 0, 2, 
/*1287*/          OPC_EmitInteger, MVT::i32, SystemZ::subreg_l32,
/*1290*/          OPC_EmitNode, TARGET_VAL(TargetOpcode::EXTRACT_SUBREG), 0,
                      1/*#VTs*/, MVT::i32, 2/*#Ops*/, 1, 9,  // Results = #10
/*1299*/          OPC_EmitConvertToTarget, 4,
/*1301*/          OPC_EmitConvertToTarget, 5,
/*1303*/          OPC_MorphNodeTo, TARGET_VAL(SystemZ::CondStore8), 0|OPFL_Chain|OPFL_GlueInput|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i32, 6/*#Ops*/, 10, 6, 7, 8, 11, 12, 
                  // Src: (st (z_select_ccmask:i64 GR64:i64:$new, (ld:i64 bdxaddr20only:i64:$addr)<<P:Predicate_unindexedload>><<P:Predicate_anyextload>><<P:Predicate_anyextloadi8>><<P:Predicate_nonvolatile_anyextloadi8>>, (imm:i8)<<P:Predicate_uimm8zx4>>:$valid, (imm:i8)<<P:Predicate_uimm8zx4>>:$cc), bdxaddr20only:i64:$addr)<<P:Predicate_unindexedstore>><<P:Predicate_truncstore>><<P:Predicate_truncstorei8>><<P:Predicate_nonvolatile_truncstorei8>> - Complexity = 43
                  // Dst: (CondStore8:i32 (EXTRACT_SUBREG:i32 GR64:i64:$new, subreg_l32:i32), bdxaddr20only:i64:$addr, (imm:i8)<<P:Predicate_uimm8zx4>>:$valid, (imm:i8)<<P:Predicate_uimm8zx4>>:$cc)
/*1316*/        /*Scope*/ 88, /*->1405*/
/*1317*/          OPC_MoveChild, 0,
/*1319*/          OPC_CheckOpcode, TARGET_VAL(ISD::LOAD),
/*1322*/          OPC_RecordMemRef,
/*1323*/          OPC_RecordNode, // #1 = 'ld' chained node
/*1324*/          OPC_CheckFoldableChainNode,
/*1325*/          OPC_RecordChild1, // #2 = $addr
/*1326*/          OPC_CheckChild1Type, MVT::i64,
/*1328*/          OPC_CheckPredicate, 0, // Predicate_unindexedload
/*1330*/          OPC_CheckPredicate, 1, // Predicate_anyextload
/*1332*/          OPC_CheckPredicate, 2, // Predicate_anyextloadi8
/*1334*/          OPC_CheckPredicate, 3, // Predicate_nonvolatile_anyextloadi8
/*1336*/          OPC_MoveParent,
/*1337*/          OPC_RecordChild1, // #3 = $new
/*1338*/          OPC_RecordChild2, // #4 = $valid
/*1339*/          OPC_MoveChild, 2,
/*1341*/          OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*1344*/          OPC_CheckPredicate, 4, // Predicate_uimm8zx4
/*1346*/          OPC_MoveParent,
/*1347*/          OPC_RecordChild3, // #5 = $cc
/*1348*/          OPC_MoveChild, 3,
/*1350*/          OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*1353*/          OPC_CheckPredicate, 4, // Predicate_uimm8zx4
/*1355*/          OPC_MoveParent,
/*1356*/          OPC_CheckType, MVT::i64,
/*1358*/          OPC_MoveParent,
/*1359*/          OPC_CheckChild2Same, 2,
/*1361*/          OPC_CheckPredicate, 5, // Predicate_unindexedstore
/*1363*/          OPC_CheckPredicate, 6, // Predicate_truncstore
/*1365*/          OPC_CheckPredicate, 7, // Predicate_truncstorei8
/*1367*/          OPC_CheckPredicate, 8, // Predicate_nonvolatile_truncstorei8
/*1369*/          OPC_CheckComplexPat, /*CP*/0, /*#*/2, // selectBDXAddr20Only:$addr #6 #7 #8
/*1372*/          OPC_EmitMergeInputChains, 2, 0, 1, 
/*1376*/          OPC_EmitInteger, MVT::i32, SystemZ::subreg_l32,
/*1379*/          OPC_EmitNode, TARGET_VAL(TargetOpcode::EXTRACT_SUBREG), 0,
                      1/*#VTs*/, MVT::i32, 2/*#Ops*/, 3, 9,  // Results = #10
/*1388*/          OPC_EmitConvertToTarget, 4,
/*1390*/          OPC_EmitConvertToTarget, 5,
/*1392*/          OPC_MorphNodeTo, TARGET_VAL(SystemZ::CondStore8Inv), 0|OPFL_Chain|OPFL_GlueInput|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i32, 6/*#Ops*/, 10, 6, 7, 8, 11, 12, 
                  // Src: (st (z_select_ccmask:i64 (ld:i64 bdxaddr20only:i64:$addr)<<P:Predicate_unindexedload>><<P:Predicate_anyextload>><<P:Predicate_anyextloadi8>><<P:Predicate_nonvolatile_anyextloadi8>>, GR64:i64:$new, (imm:i8)<<P:Predicate_uimm8zx4>>:$valid, (imm:i8)<<P:Predicate_uimm8zx4>>:$cc), bdxaddr20only:i64:$addr)<<P:Predicate_unindexedstore>><<P:Predicate_truncstore>><<P:Predicate_truncstorei8>><<P:Predicate_nonvolatile_truncstorei8>> - Complexity = 43
                  // Dst: (CondStore8Inv:i32 (EXTRACT_SUBREG:i32 GR64:i64:$new, subreg_l32:i32), bdxaddr20only:i64:$addr, (imm:i8)<<P:Predicate_uimm8zx4>>:$valid, (imm:i8)<<P:Predicate_uimm8zx4>>:$cc)
/*1405*/        /*Scope*/ 88, /*->1494*/
/*1406*/          OPC_RecordChild0, // #1 = $new
/*1407*/          OPC_MoveChild, 1,
/*1409*/          OPC_CheckOpcode, TARGET_VAL(ISD::LOAD),
/*1412*/          OPC_RecordMemRef,
/*1413*/          OPC_RecordNode, // #2 = 'ld' chained node
/*1414*/          OPC_CheckFoldableChainNode,
/*1415*/          OPC_RecordChild1, // #3 = $addr
/*1416*/          OPC_CheckChild1Type, MVT::i64,
/*1418*/          OPC_CheckPredicate, 0, // Predicate_unindexedload
/*1420*/          OPC_CheckPredicate, 1, // Predicate_anyextload
/*1422*/          OPC_CheckPredicate, 9, // Predicate_anyextloadi16
/*1424*/          OPC_CheckPredicate, 10, // Predicate_nonvolatile_anyextloadi16
/*1426*/          OPC_MoveParent,
/*1427*/          OPC_RecordChild2, // #4 = $valid
/*1428*/          OPC_MoveChild, 2,
/*1430*/          OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*1433*/          OPC_CheckPredicate, 4, // Predicate_uimm8zx4
/*1435*/          OPC_MoveParent,
/*1436*/          OPC_RecordChild3, // #5 = $cc
/*1437*/          OPC_MoveChild, 3,
/*1439*/          OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*1442*/          OPC_CheckPredicate, 4, // Predicate_uimm8zx4
/*1444*/          OPC_MoveParent,
/*1445*/          OPC_CheckType, MVT::i64,
/*1447*/          OPC_MoveParent,
/*1448*/          OPC_CheckChild2Same, 3,
/*1450*/          OPC_CheckPredicate, 5, // Predicate_unindexedstore
/*1452*/          OPC_CheckPredicate, 6, // Predicate_truncstore
/*1454*/          OPC_CheckPredicate, 11, // Predicate_truncstorei16
/*1456*/          OPC_CheckPredicate, 12, // Predicate_nonvolatile_truncstorei16
/*1458*/          OPC_CheckComplexPat, /*CP*/0, /*#*/3, // selectBDXAddr20Only:$addr #6 #7 #8
/*1461*/          OPC_EmitMergeInputChains, 2, 0, 2, 
/*1465*/          OPC_EmitInteger, MVT::i32, SystemZ::subreg_l32,
/*1468*/          OPC_EmitNode, TARGET_VAL(TargetOpcode::EXTRACT_SUBREG), 0,
                      1/*#VTs*/, MVT::i32, 2/*#Ops*/, 1, 9,  // Results = #10
/*1477*/          OPC_EmitConvertToTarget, 4,
/*1479*/          OPC_EmitConvertToTarget, 5,
/*1481*/          OPC_MorphNodeTo, TARGET_VAL(SystemZ::CondStore16), 0|OPFL_Chain|OPFL_GlueInput|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i32, 6/*#Ops*/, 10, 6, 7, 8, 11, 12, 
                  // Src: (st (z_select_ccmask:i64 GR64:i64:$new, (ld:i64 bdxaddr20only:i64:$addr)<<P:Predicate_unindexedload>><<P:Predicate_anyextload>><<P:Predicate_anyextloadi16>><<P:Predicate_nonvolatile_anyextloadi16>>, (imm:i8)<<P:Predicate_uimm8zx4>>:$valid, (imm:i8)<<P:Predicate_uimm8zx4>>:$cc), bdxaddr20only:i64:$addr)<<P:Predicate_unindexedstore>><<P:Predicate_truncstore>><<P:Predicate_truncstorei16>><<P:Predicate_nonvolatile_truncstorei16>> - Complexity = 43
                  // Dst: (CondStore16:i32 (EXTRACT_SUBREG:i32 GR64:i64:$new, subreg_l32:i32), bdxaddr20only:i64:$addr, (imm:i8)<<P:Predicate_uimm8zx4>>:$valid, (imm:i8)<<P:Predicate_uimm8zx4>>:$cc)
/*1494*/        /*Scope*/ 88, /*->1583*/
/*1495*/          OPC_MoveChild, 0,
/*1497*/          OPC_CheckOpcode, TARGET_VAL(ISD::LOAD),
/*1500*/          OPC_RecordMemRef,
/*1501*/          OPC_RecordNode, // #1 = 'ld' chained node
/*1502*/          OPC_CheckFoldableChainNode,
/*1503*/          OPC_RecordChild1, // #2 = $addr
/*1504*/          OPC_CheckChild1Type, MVT::i64,
/*1506*/          OPC_CheckPredicate, 0, // Predicate_unindexedload
/*1508*/          OPC_CheckPredicate, 1, // Predicate_anyextload
/*1510*/          OPC_CheckPredicate, 9, // Predicate_anyextloadi16
/*1512*/          OPC_CheckPredicate, 10, // Predicate_nonvolatile_anyextloadi16
/*1514*/          OPC_MoveParent,
/*1515*/          OPC_RecordChild1, // #3 = $new
/*1516*/          OPC_RecordChild2, // #4 = $valid
/*1517*/          OPC_MoveChild, 2,
/*1519*/          OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*1522*/          OPC_CheckPredicate, 4, // Predicate_uimm8zx4
/*1524*/          OPC_MoveParent,
/*1525*/          OPC_RecordChild3, // #5 = $cc
/*1526*/          OPC_MoveChild, 3,
/*1528*/          OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*1531*/          OPC_CheckPredicate, 4, // Predicate_uimm8zx4
/*1533*/          OPC_MoveParent,
/*1534*/          OPC_CheckType, MVT::i64,
/*1536*/          OPC_MoveParent,
/*1537*/          OPC_CheckChild2Same, 2,
/*1539*/          OPC_CheckPredicate, 5, // Predicate_unindexedstore
/*1541*/          OPC_CheckPredicate, 6, // Predicate_truncstore
/*1543*/          OPC_CheckPredicate, 11, // Predicate_truncstorei16
/*1545*/          OPC_CheckPredicate, 12, // Predicate_nonvolatile_truncstorei16
/*1547*/          OPC_CheckComplexPat, /*CP*/0, /*#*/2, // selectBDXAddr20Only:$addr #6 #7 #8
/*1550*/          OPC_EmitMergeInputChains, 2, 0, 1, 
/*1554*/          OPC_EmitInteger, MVT::i32, SystemZ::subreg_l32,
/*1557*/          OPC_EmitNode, TARGET_VAL(TargetOpcode::EXTRACT_SUBREG), 0,
                      1/*#VTs*/, MVT::i32, 2/*#Ops*/, 3, 9,  // Results = #10
/*1566*/          OPC_EmitConvertToTarget, 4,
/*1568*/          OPC_EmitConvertToTarget, 5,
/*1570*/          OPC_MorphNodeTo, TARGET_VAL(SystemZ::CondStore16Inv), 0|OPFL_Chain|OPFL_GlueInput|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i32, 6/*#Ops*/, 10, 6, 7, 8, 11, 12, 
                  // Src: (st (z_select_ccmask:i64 (ld:i64 bdxaddr20only:i64:$addr)<<P:Predicate_unindexedload>><<P:Predicate_anyextload>><<P:Predicate_anyextloadi16>><<P:Predicate_nonvolatile_anyextloadi16>>, GR64:i64:$new, (imm:i8)<<P:Predicate_uimm8zx4>>:$valid, (imm:i8)<<P:Predicate_uimm8zx4>>:$cc), bdxaddr20only:i64:$addr)<<P:Predicate_unindexedstore>><<P:Predicate_truncstore>><<P:Predicate_truncstorei16>><<P:Predicate_nonvolatile_truncstorei16>> - Complexity = 43
                  // Dst: (CondStore16Inv:i32 (EXTRACT_SUBREG:i32 GR64:i64:$new, subreg_l32:i32), bdxaddr20only:i64:$addr, (imm:i8)<<P:Predicate_uimm8zx4>>:$valid, (imm:i8)<<P:Predicate_uimm8zx4>>:$cc)
/*1583*/        /*Scope*/ 88, /*->1672*/
/*1584*/          OPC_RecordChild0, // #1 = $new
/*1585*/          OPC_MoveChild, 1,
/*1587*/          OPC_CheckOpcode, TARGET_VAL(ISD::LOAD),
/*1590*/          OPC_RecordMemRef,
/*1591*/          OPC_RecordNode, // #2 = 'ld' chained node
/*1592*/          OPC_CheckFoldableChainNode,
/*1593*/          OPC_RecordChild1, // #3 = $addr
/*1594*/          OPC_CheckChild1Type, MVT::i64,
/*1596*/          OPC_CheckPredicate, 0, // Predicate_unindexedload
/*1598*/          OPC_CheckPredicate, 1, // Predicate_anyextload
/*1600*/          OPC_CheckPredicate, 17, // Predicate_anyextloadi32
/*1602*/          OPC_CheckPredicate, 18, // Predicate_nonvolatile_anyextloadi32
/*1604*/          OPC_MoveParent,
/*1605*/          OPC_RecordChild2, // #4 = $valid
/*1606*/          OPC_MoveChild, 2,
/*1608*/          OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*1611*/          OPC_CheckPredicate, 4, // Predicate_uimm8zx4
/*1613*/          OPC_MoveParent,
/*1614*/          OPC_RecordChild3, // #5 = $cc
/*1615*/          OPC_MoveChild, 3,
/*1617*/          OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*1620*/          OPC_CheckPredicate, 4, // Predicate_uimm8zx4
/*1622*/          OPC_MoveParent,
/*1623*/          OPC_CheckType, MVT::i64,
/*1625*/          OPC_MoveParent,
/*1626*/          OPC_CheckChild2Same, 3,
/*1628*/          OPC_CheckPredicate, 5, // Predicate_unindexedstore
/*1630*/          OPC_CheckPredicate, 6, // Predicate_truncstore
/*1632*/          OPC_CheckPredicate, 19, // Predicate_truncstorei32
/*1634*/          OPC_CheckPredicate, 20, // Predicate_nonvolatile_truncstorei32
/*1636*/          OPC_CheckComplexPat, /*CP*/0, /*#*/3, // selectBDXAddr20Only:$addr #6 #7 #8
/*1639*/          OPC_EmitMergeInputChains, 2, 0, 2, 
/*1643*/          OPC_EmitInteger, MVT::i32, SystemZ::subreg_l32,
/*1646*/          OPC_EmitNode, TARGET_VAL(TargetOpcode::EXTRACT_SUBREG), 0,
                      1/*#VTs*/, MVT::i32, 2/*#Ops*/, 1, 9,  // Results = #10
/*1655*/          OPC_EmitConvertToTarget, 4,
/*1657*/          OPC_EmitConvertToTarget, 5,
/*1659*/          OPC_MorphNodeTo, TARGET_VAL(SystemZ::CondStore32), 0|OPFL_Chain|OPFL_GlueInput|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i32, 6/*#Ops*/, 10, 6, 7, 8, 11, 12, 
                  // Src: (st (z_select_ccmask:i64 GR64:i64:$new, (ld:i64 bdxaddr20only:i64:$addr)<<P:Predicate_unindexedload>><<P:Predicate_anyextload>><<P:Predicate_anyextloadi32>><<P:Predicate_nonvolatile_anyextloadi32>>, (imm:i8)<<P:Predicate_uimm8zx4>>:$valid, (imm:i8)<<P:Predicate_uimm8zx4>>:$cc), bdxaddr20only:i64:$addr)<<P:Predicate_unindexedstore>><<P:Predicate_truncstore>><<P:Predicate_truncstorei32>><<P:Predicate_nonvolatile_truncstorei32>> - Complexity = 43
                  // Dst: (CondStore32:i32 (EXTRACT_SUBREG:i32 GR64:i64:$new, subreg_l32:i32), bdxaddr20only:i64:$addr, (imm:i8)<<P:Predicate_uimm8zx4>>:$valid, (imm:i8)<<P:Predicate_uimm8zx4>>:$cc)
/*1672*/        /*Scope*/ 88, /*->1761*/
/*1673*/          OPC_MoveChild, 0,
/*1675*/          OPC_CheckOpcode, TARGET_VAL(ISD::LOAD),
/*1678*/          OPC_RecordMemRef,
/*1679*/          OPC_RecordNode, // #1 = 'ld' chained node
/*1680*/          OPC_CheckFoldableChainNode,
/*1681*/          OPC_RecordChild1, // #2 = $addr
/*1682*/          OPC_CheckChild1Type, MVT::i64,
/*1684*/          OPC_CheckPredicate, 0, // Predicate_unindexedload
/*1686*/          OPC_CheckPredicate, 1, // Predicate_anyextload
/*1688*/          OPC_CheckPredicate, 17, // Predicate_anyextloadi32
/*1690*/          OPC_CheckPredicate, 18, // Predicate_nonvolatile_anyextloadi32
/*1692*/          OPC_MoveParent,
/*1693*/          OPC_RecordChild1, // #3 = $new
/*1694*/          OPC_RecordChild2, // #4 = $valid
/*1695*/          OPC_MoveChild, 2,
/*1697*/          OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*1700*/          OPC_CheckPredicate, 4, // Predicate_uimm8zx4
/*1702*/          OPC_MoveParent,
/*1703*/          OPC_RecordChild3, // #5 = $cc
/*1704*/          OPC_MoveChild, 3,
/*1706*/          OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*1709*/          OPC_CheckPredicate, 4, // Predicate_uimm8zx4
/*1711*/          OPC_MoveParent,
/*1712*/          OPC_CheckType, MVT::i64,
/*1714*/          OPC_MoveParent,
/*1715*/          OPC_CheckChild2Same, 2,
/*1717*/          OPC_CheckPredicate, 5, // Predicate_unindexedstore
/*1719*/          OPC_CheckPredicate, 6, // Predicate_truncstore
/*1721*/          OPC_CheckPredicate, 19, // Predicate_truncstorei32
/*1723*/          OPC_CheckPredicate, 20, // Predicate_nonvolatile_truncstorei32
/*1725*/          OPC_CheckComplexPat, /*CP*/0, /*#*/2, // selectBDXAddr20Only:$addr #6 #7 #8
/*1728*/          OPC_EmitMergeInputChains, 2, 0, 1, 
/*1732*/          OPC_EmitInteger, MVT::i32, SystemZ::subreg_l32,
/*1735*/          OPC_EmitNode, TARGET_VAL(TargetOpcode::EXTRACT_SUBREG), 0,
                      1/*#VTs*/, MVT::i32, 2/*#Ops*/, 3, 9,  // Results = #10
/*1744*/          OPC_EmitConvertToTarget, 4,
/*1746*/          OPC_EmitConvertToTarget, 5,
/*1748*/          OPC_MorphNodeTo, TARGET_VAL(SystemZ::CondStore32Inv), 0|OPFL_Chain|OPFL_GlueInput|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i32, 6/*#Ops*/, 10, 6, 7, 8, 11, 12, 
                  // Src: (st (z_select_ccmask:i64 (ld:i64 bdxaddr20only:i64:$addr)<<P:Predicate_unindexedload>><<P:Predicate_anyextload>><<P:Predicate_anyextloadi32>><<P:Predicate_nonvolatile_anyextloadi32>>, GR64:i64:$new, (imm:i8)<<P:Predicate_uimm8zx4>>:$valid, (imm:i8)<<P:Predicate_uimm8zx4>>:$cc), bdxaddr20only:i64:$addr)<<P:Predicate_unindexedstore>><<P:Predicate_truncstore>><<P:Predicate_truncstorei32>><<P:Predicate_nonvolatile_truncstorei32>> - Complexity = 43
                  // Dst: (CondStore32Inv:i32 (EXTRACT_SUBREG:i32 GR64:i64:$new, subreg_l32:i32), bdxaddr20only:i64:$addr, (imm:i8)<<P:Predicate_uimm8zx4>>:$valid, (imm:i8)<<P:Predicate_uimm8zx4>>:$cc)
/*1761*/        0, /*End of Scope*/
/*1762*/      /*SwitchOpcode*/ 124|128,12/*1660*/,  TARGET_VAL(ISD::AND),// ->3426
/*1766*/        OPC_MoveChild, 0,
/*1768*/        OPC_CheckOpcode, TARGET_VAL(ISD::LOAD),
/*1771*/        OPC_RecordMemRef,
/*1772*/        OPC_RecordNode, // #1 = 'ld' chained node
/*1773*/        OPC_CheckFoldableChainNode,
/*1774*/        OPC_RecordChild1, // #2 = $src
/*1775*/        OPC_CheckChild1Type, MVT::i64,
/*1777*/        OPC_CheckPredicate, 0, // Predicate_unindexedload
/*1779*/        OPC_Scope, 54, /*->1835*/ // 27 children in Scope
/*1781*/          OPC_CheckPredicate, 1, // Predicate_anyextload
/*1783*/          OPC_CheckPredicate, 2, // Predicate_anyextloadi8
/*1785*/          OPC_MoveParent,
/*1786*/          OPC_MoveChild, 1,
/*1788*/          OPC_CheckOpcode, TARGET_VAL(ISD::LOAD),
/*1791*/          OPC_RecordMemRef,
/*1792*/          OPC_RecordNode, // #3 = 'ld' chained node
/*1793*/          OPC_CheckFoldableChainNode,
/*1794*/          OPC_RecordChild1, // #4 = $dest
/*1795*/          OPC_CheckChild1Type, MVT::i64,
/*1797*/          OPC_CheckPredicate, 0, // Predicate_unindexedload
/*1799*/          OPC_MoveParent,
/*1800*/          OPC_CheckType, MVT::i32,
/*1802*/          OPC_MoveParent,
/*1803*/          OPC_CheckChild2Same, 4,
/*1805*/          OPC_CheckPredicate, 5, // Predicate_unindexedstore
/*1807*/          OPC_CheckPredicate, 21, // Predicate_block_and1
/*1809*/          OPC_CheckComplexPat, /*CP*/1, /*#*/2, // selectBDAddr12Only:$src #5 #6
/*1812*/          OPC_CheckComplexPat, /*CP*/1, /*#*/4, // selectBDAddr12Only:$dest #7 #8
/*1815*/          OPC_EmitMergeInputChains, 3, 0, 1, 3, 
/*1820*/          OPC_EmitInteger, MVT::i64, 1, 
/*1823*/          OPC_MorphNodeTo, TARGET_VAL(SystemZ::NCSequence), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i32, 5/*#Ops*/, 7, 8, 5, 6, 9, 
                  // Src: (st (and:i32 (ld:i32 bdaddr12only:i64:$src)<<P:Predicate_unindexedload>><<P:Predicate_anyextload>><<P:Predicate_anyextloadi8>>, (ld:i32 bdaddr12only:i64:$dest)<<P:Predicate_unindexedload>>), bdaddr12only:i64:$dest)<<P:Predicate_unindexedstore>><<P:Predicate_block_and1>> - Complexity = 42
                  // Dst: (NCSequence:i32 bdaddr12only:i64:$dest, bdaddr12only:i64:$src, 1:i64)
/*1835*/        /*Scope*/ 54, /*->1890*/
/*1836*/          OPC_MoveParent,
/*1837*/          OPC_MoveChild, 1,
/*1839*/          OPC_CheckOpcode, TARGET_VAL(ISD::LOAD),
/*1842*/          OPC_RecordMemRef,
/*1843*/          OPC_RecordNode, // #3 = 'ld' chained node
/*1844*/          OPC_CheckFoldableChainNode,
/*1845*/          OPC_RecordChild1, // #4 = $src
/*1846*/          OPC_CheckChild1Type, MVT::i64,
/*1848*/          OPC_CheckPredicate, 0, // Predicate_unindexedload
/*1850*/          OPC_CheckPredicate, 1, // Predicate_anyextload
/*1852*/          OPC_CheckPredicate, 2, // Predicate_anyextloadi8
/*1854*/          OPC_MoveParent,
/*1855*/          OPC_CheckType, MVT::i32,
/*1857*/          OPC_MoveParent,
/*1858*/          OPC_CheckChild2Same, 2,
/*1860*/          OPC_CheckPredicate, 5, // Predicate_unindexedstore
/*1862*/          OPC_CheckPredicate, 22, // Predicate_block_and2
/*1864*/          OPC_CheckComplexPat, /*CP*/1, /*#*/2, // selectBDAddr12Only:$dest #5 #6
/*1867*/          OPC_CheckComplexPat, /*CP*/1, /*#*/4, // selectBDAddr12Only:$src #7 #8
/*1870*/          OPC_EmitMergeInputChains, 3, 0, 1, 3, 
/*1875*/          OPC_EmitInteger, MVT::i64, 1, 
/*1878*/          OPC_MorphNodeTo, TARGET_VAL(SystemZ::NCSequence), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i32, 5/*#Ops*/, 5, 6, 7, 8, 9, 
                  // Src: (st (and:i32 (ld:i32 bdaddr12only:i64:$dest)<<P:Predicate_unindexedload>>, (ld:i32 bdaddr12only:i64:$src)<<P:Predicate_unindexedload>><<P:Predicate_anyextload>><<P:Predicate_anyextloadi8>>), bdaddr12only:i64:$dest)<<P:Predicate_unindexedstore>><<P:Predicate_block_and2>> - Complexity = 42
                  // Dst: (NCSequence:i32 bdaddr12only:i64:$dest, bdaddr12only:i64:$src, 1:i64)
/*1890*/        /*Scope*/ 54, /*->1945*/
/*1891*/          OPC_CheckPredicate, 1, // Predicate_anyextload
/*1893*/          OPC_CheckPredicate, 9, // Predicate_anyextloadi16
/*1895*/          OPC_MoveParent,
/*1896*/          OPC_MoveChild, 1,
/*1898*/          OPC_CheckOpcode, TARGET_VAL(ISD::LOAD),
/*1901*/          OPC_RecordMemRef,
/*1902*/          OPC_RecordNode, // #3 = 'ld' chained node
/*1903*/          OPC_CheckFoldableChainNode,
/*1904*/          OPC_RecordChild1, // #4 = $dest
/*1905*/          OPC_CheckChild1Type, MVT::i64,
/*1907*/          OPC_CheckPredicate, 0, // Predicate_unindexedload
/*1909*/          OPC_MoveParent,
/*1910*/          OPC_CheckType, MVT::i32,
/*1912*/          OPC_MoveParent,
/*1913*/          OPC_CheckChild2Same, 4,
/*1915*/          OPC_CheckPredicate, 5, // Predicate_unindexedstore
/*1917*/          OPC_CheckPredicate, 21, // Predicate_block_and1
/*1919*/          OPC_CheckComplexPat, /*CP*/1, /*#*/2, // selectBDAddr12Only:$src #5 #6
/*1922*/          OPC_CheckComplexPat, /*CP*/1, /*#*/4, // selectBDAddr12Only:$dest #7 #8
/*1925*/          OPC_EmitMergeInputChains, 3, 0, 1, 3, 
/*1930*/          OPC_EmitInteger, MVT::i64, 2, 
/*1933*/          OPC_MorphNodeTo, TARGET_VAL(SystemZ::NCSequence), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i32, 5/*#Ops*/, 7, 8, 5, 6, 9, 
                  // Src: (st (and:i32 (ld:i32 bdaddr12only:i64:$src)<<P:Predicate_unindexedload>><<P:Predicate_anyextload>><<P:Predicate_anyextloadi16>>, (ld:i32 bdaddr12only:i64:$dest)<<P:Predicate_unindexedload>>), bdaddr12only:i64:$dest)<<P:Predicate_unindexedstore>><<P:Predicate_block_and1>> - Complexity = 42
                  // Dst: (NCSequence:i32 bdaddr12only:i64:$dest, bdaddr12only:i64:$src, 2:i64)
/*1945*/        /*Scope*/ 54, /*->2000*/
/*1946*/          OPC_MoveParent,
/*1947*/          OPC_MoveChild, 1,
/*1949*/          OPC_CheckOpcode, TARGET_VAL(ISD::LOAD),
/*1952*/          OPC_RecordMemRef,
/*1953*/          OPC_RecordNode, // #3 = 'ld' chained node
/*1954*/          OPC_CheckFoldableChainNode,
/*1955*/          OPC_RecordChild1, // #4 = $src
/*1956*/          OPC_CheckChild1Type, MVT::i64,
/*1958*/          OPC_CheckPredicate, 0, // Predicate_unindexedload
/*1960*/          OPC_CheckPredicate, 1, // Predicate_anyextload
/*1962*/          OPC_CheckPredicate, 9, // Predicate_anyextloadi16
/*1964*/          OPC_MoveParent,
/*1965*/          OPC_CheckType, MVT::i32,
/*1967*/          OPC_MoveParent,
/*1968*/          OPC_CheckChild2Same, 2,
/*1970*/          OPC_CheckPredicate, 5, // Predicate_unindexedstore
/*1972*/          OPC_CheckPredicate, 22, // Predicate_block_and2
/*1974*/          OPC_CheckComplexPat, /*CP*/1, /*#*/2, // selectBDAddr12Only:$dest #5 #6
/*1977*/          OPC_CheckComplexPat, /*CP*/1, /*#*/4, // selectBDAddr12Only:$src #7 #8
/*1980*/          OPC_EmitMergeInputChains, 3, 0, 1, 3, 
/*1985*/          OPC_EmitInteger, MVT::i64, 2, 
/*1988*/          OPC_MorphNodeTo, TARGET_VAL(SystemZ::NCSequence), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i32, 5/*#Ops*/, 5, 6, 7, 8, 9, 
                  // Src: (st (and:i32 (ld:i32 bdaddr12only:i64:$dest)<<P:Predicate_unindexedload>>, (ld:i32 bdaddr12only:i64:$src)<<P:Predicate_unindexedload>><<P:Predicate_anyextload>><<P:Predicate_anyextloadi16>>), bdaddr12only:i64:$dest)<<P:Predicate_unindexedstore>><<P:Predicate_block_and2>> - Complexity = 42
                  // Dst: (NCSequence:i32 bdaddr12only:i64:$dest, bdaddr12only:i64:$src, 2:i64)
/*2000*/        /*Scope*/ 52, /*->2053*/
/*2001*/          OPC_CheckPredicate, 13, // Predicate_load
/*2003*/          OPC_MoveParent,
/*2004*/          OPC_MoveChild, 1,
/*2006*/          OPC_CheckOpcode, TARGET_VAL(ISD::LOAD),
/*2009*/          OPC_RecordMemRef,
/*2010*/          OPC_RecordNode, // #3 = 'ld' chained node
/*2011*/          OPC_CheckFoldableChainNode,
/*2012*/          OPC_RecordChild1, // #4 = $dest
/*2013*/          OPC_CheckChild1Type, MVT::i64,
/*2015*/          OPC_CheckPredicate, 0, // Predicate_unindexedload
/*2017*/          OPC_MoveParent,
/*2018*/          OPC_CheckType, MVT::i32,
/*2020*/          OPC_MoveParent,
/*2021*/          OPC_CheckChild2Same, 4,
/*2023*/          OPC_CheckPredicate, 5, // Predicate_unindexedstore
/*2025*/          OPC_CheckPredicate, 21, // Predicate_block_and1
/*2027*/          OPC_CheckComplexPat, /*CP*/1, /*#*/2, // selectBDAddr12Only:$src #5 #6
/*2030*/          OPC_CheckComplexPat, /*CP*/1, /*#*/4, // selectBDAddr12Only:$dest #7 #8
/*2033*/          OPC_EmitMergeInputChains, 3, 0, 1, 3, 
/*2038*/          OPC_EmitInteger, MVT::i64, 4, 
/*2041*/          OPC_MorphNodeTo, TARGET_VAL(SystemZ::NCSequence), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i32, 5/*#Ops*/, 7, 8, 5, 6, 9, 
                  // Src: (st (and:i32 (ld:i32 bdaddr12only:i64:$src)<<P:Predicate_unindexedload>><<P:Predicate_load>>, (ld:i32 bdaddr12only:i64:$dest)<<P:Predicate_unindexedload>>), bdaddr12only:i64:$dest)<<P:Predicate_unindexedstore>><<P:Predicate_block_and1>> - Complexity = 42
                  // Dst: (NCSequence:i32 bdaddr12only:i64:$dest, bdaddr12only:i64:$src, 4:i64)
/*2053*/        /*Scope*/ 52, /*->2106*/
/*2054*/          OPC_MoveParent,
/*2055*/          OPC_MoveChild, 1,
/*2057*/          OPC_CheckOpcode, TARGET_VAL(ISD::LOAD),
/*2060*/          OPC_RecordMemRef,
/*2061*/          OPC_RecordNode, // #3 = 'ld' chained node
/*2062*/          OPC_CheckFoldableChainNode,
/*2063*/          OPC_RecordChild1, // #4 = $src
/*2064*/          OPC_CheckChild1Type, MVT::i64,
/*2066*/          OPC_CheckPredicate, 0, // Predicate_unindexedload
/*2068*/          OPC_CheckPredicate, 13, // Predicate_load
/*2070*/          OPC_MoveParent,
/*2071*/          OPC_CheckType, MVT::i32,
/*2073*/          OPC_MoveParent,
/*2074*/          OPC_CheckChild2Same, 2,
/*2076*/          OPC_CheckPredicate, 5, // Predicate_unindexedstore
/*2078*/          OPC_CheckPredicate, 22, // Predicate_block_and2
/*2080*/          OPC_CheckComplexPat, /*CP*/1, /*#*/2, // selectBDAddr12Only:$dest #5 #6
/*2083*/          OPC_CheckComplexPat, /*CP*/1, /*#*/4, // selectBDAddr12Only:$src #7 #8
/*2086*/          OPC_EmitMergeInputChains, 3, 0, 1, 3, 
/*2091*/          OPC_EmitInteger, MVT::i64, 4, 
/*2094*/          OPC_MorphNodeTo, TARGET_VAL(SystemZ::NCSequence), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i32, 5/*#Ops*/, 5, 6, 7, 8, 9, 
                  // Src: (st (and:i32 (ld:i32 bdaddr12only:i64:$dest)<<P:Predicate_unindexedload>>, (ld:i32 bdaddr12only:i64:$src)<<P:Predicate_unindexedload>><<P:Predicate_load>>), bdaddr12only:i64:$dest)<<P:Predicate_unindexedstore>><<P:Predicate_block_and2>> - Complexity = 42
                  // Dst: (NCSequence:i32 bdaddr12only:i64:$dest, bdaddr12only:i64:$src, 4:i64)
/*2106*/        /*Scope*/ 54, /*->2161*/
/*2107*/          OPC_CheckPredicate, 1, // Predicate_anyextload
/*2109*/          OPC_CheckPredicate, 2, // Predicate_anyextloadi8
/*2111*/          OPC_MoveParent,
/*2112*/          OPC_MoveChild, 1,
/*2114*/          OPC_CheckOpcode, TARGET_VAL(ISD::LOAD),
/*2117*/          OPC_RecordMemRef,
/*2118*/          OPC_RecordNode, // #3 = 'ld' chained node
/*2119*/          OPC_CheckFoldableChainNode,
/*2120*/          OPC_RecordChild1, // #4 = $dest
/*2121*/          OPC_CheckChild1Type, MVT::i64,
/*2123*/          OPC_CheckPredicate, 0, // Predicate_unindexedload
/*2125*/          OPC_MoveParent,
/*2126*/          OPC_CheckType, MVT::i64,
/*2128*/          OPC_MoveParent,
/*2129*/          OPC_CheckChild2Same, 4,
/*2131*/          OPC_CheckPredicate, 5, // Predicate_unindexedstore
/*2133*/          OPC_CheckPredicate, 21, // Predicate_block_and1
/*2135*/          OPC_CheckComplexPat, /*CP*/1, /*#*/2, // selectBDAddr12Only:$src #5 #6
/*2138*/          OPC_CheckComplexPat, /*CP*/1, /*#*/4, // selectBDAddr12Only:$dest #7 #8
/*2141*/          OPC_EmitMergeInputChains, 3, 0, 1, 3, 
/*2146*/          OPC_EmitInteger, MVT::i64, 1, 
/*2149*/          OPC_MorphNodeTo, TARGET_VAL(SystemZ::NCSequence), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i32, 5/*#Ops*/, 7, 8, 5, 6, 9, 
                  // Src: (st (and:i64 (ld:i64 bdaddr12only:i64:$src)<<P:Predicate_unindexedload>><<P:Predicate_anyextload>><<P:Predicate_anyextloadi8>>, (ld:i64 bdaddr12only:i64:$dest)<<P:Predicate_unindexedload>>), bdaddr12only:i64:$dest)<<P:Predicate_unindexedstore>><<P:Predicate_block_and1>> - Complexity = 42
                  // Dst: (NCSequence:i32 bdaddr12only:i64:$dest, bdaddr12only:i64:$src, 1:i64)
/*2161*/        /*Scope*/ 54, /*->2216*/
/*2162*/          OPC_MoveParent,
/*2163*/          OPC_MoveChild, 1,
/*2165*/          OPC_CheckOpcode, TARGET_VAL(ISD::LOAD),
/*2168*/          OPC_RecordMemRef,
/*2169*/          OPC_RecordNode, // #3 = 'ld' chained node
/*2170*/          OPC_CheckFoldableChainNode,
/*2171*/          OPC_RecordChild1, // #4 = $src
/*2172*/          OPC_CheckChild1Type, MVT::i64,
/*2174*/          OPC_CheckPredicate, 0, // Predicate_unindexedload
/*2176*/          OPC_CheckPredicate, 1, // Predicate_anyextload
/*2178*/          OPC_CheckPredicate, 2, // Predicate_anyextloadi8
/*2180*/          OPC_MoveParent,
/*2181*/          OPC_CheckType, MVT::i64,
/*2183*/          OPC_MoveParent,
/*2184*/          OPC_CheckChild2Same, 2,
/*2186*/          OPC_CheckPredicate, 5, // Predicate_unindexedstore
/*2188*/          OPC_CheckPredicate, 22, // Predicate_block_and2
/*2190*/          OPC_CheckComplexPat, /*CP*/1, /*#*/2, // selectBDAddr12Only:$dest #5 #6
/*2193*/          OPC_CheckComplexPat, /*CP*/1, /*#*/4, // selectBDAddr12Only:$src #7 #8
/*2196*/          OPC_EmitMergeInputChains, 3, 0, 1, 3, 
/*2201*/          OPC_EmitInteger, MVT::i64, 1, 
/*2204*/          OPC_MorphNodeTo, TARGET_VAL(SystemZ::NCSequence), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i32, 5/*#Ops*/, 5, 6, 7, 8, 9, 
                  // Src: (st (and:i64 (ld:i64 bdaddr12only:i64:$dest)<<P:Predicate_unindexedload>>, (ld:i64 bdaddr12only:i64:$src)<<P:Predicate_unindexedload>><<P:Predicate_anyextload>><<P:Predicate_anyextloadi8>>), bdaddr12only:i64:$dest)<<P:Predicate_unindexedstore>><<P:Predicate_block_and2>> - Complexity = 42
                  // Dst: (NCSequence:i32 bdaddr12only:i64:$dest, bdaddr12only:i64:$src, 1:i64)
/*2216*/        /*Scope*/ 54, /*->2271*/
/*2217*/          OPC_CheckPredicate, 1, // Predicate_anyextload
/*2219*/          OPC_CheckPredicate, 9, // Predicate_anyextloadi16
/*2221*/          OPC_MoveParent,
/*2222*/          OPC_MoveChild, 1,
/*2224*/          OPC_CheckOpcode, TARGET_VAL(ISD::LOAD),
/*2227*/          OPC_RecordMemRef,
/*2228*/          OPC_RecordNode, // #3 = 'ld' chained node
/*2229*/          OPC_CheckFoldableChainNode,
/*2230*/          OPC_RecordChild1, // #4 = $dest
/*2231*/          OPC_CheckChild1Type, MVT::i64,
/*2233*/          OPC_CheckPredicate, 0, // Predicate_unindexedload
/*2235*/          OPC_MoveParent,
/*2236*/          OPC_CheckType, MVT::i64,
/*2238*/          OPC_MoveParent,
/*2239*/          OPC_CheckChild2Same, 4,
/*2241*/          OPC_CheckPredicate, 5, // Predicate_unindexedstore
/*2243*/          OPC_CheckPredicate, 21, // Predicate_block_and1
/*2245*/          OPC_CheckComplexPat, /*CP*/1, /*#*/2, // selectBDAddr12Only:$src #5 #6
/*2248*/          OPC_CheckComplexPat, /*CP*/1, /*#*/4, // selectBDAddr12Only:$dest #7 #8
/*2251*/          OPC_EmitMergeInputChains, 3, 0, 1, 3, 
/*2256*/          OPC_EmitInteger, MVT::i64, 2, 
/*2259*/          OPC_MorphNodeTo, TARGET_VAL(SystemZ::NCSequence), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i32, 5/*#Ops*/, 7, 8, 5, 6, 9, 
                  // Src: (st (and:i64 (ld:i64 bdaddr12only:i64:$src)<<P:Predicate_unindexedload>><<P:Predicate_anyextload>><<P:Predicate_anyextloadi16>>, (ld:i64 bdaddr12only:i64:$dest)<<P:Predicate_unindexedload>>), bdaddr12only:i64:$dest)<<P:Predicate_unindexedstore>><<P:Predicate_block_and1>> - Complexity = 42
                  // Dst: (NCSequence:i32 bdaddr12only:i64:$dest, bdaddr12only:i64:$src, 2:i64)
/*2271*/        /*Scope*/ 54, /*->2326*/
/*2272*/          OPC_MoveParent,
/*2273*/          OPC_MoveChild, 1,
/*2275*/          OPC_CheckOpcode, TARGET_VAL(ISD::LOAD),
/*2278*/          OPC_RecordMemRef,
/*2279*/          OPC_RecordNode, // #3 = 'ld' chained node
/*2280*/          OPC_CheckFoldableChainNode,
/*2281*/          OPC_RecordChild1, // #4 = $src
/*2282*/          OPC_CheckChild1Type, MVT::i64,
/*2284*/          OPC_CheckPredicate, 0, // Predicate_unindexedload
/*2286*/          OPC_CheckPredicate, 1, // Predicate_anyextload
/*2288*/          OPC_CheckPredicate, 9, // Predicate_anyextloadi16
/*2290*/          OPC_MoveParent,
/*2291*/          OPC_CheckType, MVT::i64,
/*2293*/          OPC_MoveParent,
/*2294*/          OPC_CheckChild2Same, 2,
/*2296*/          OPC_CheckPredicate, 5, // Predicate_unindexedstore
/*2298*/          OPC_CheckPredicate, 22, // Predicate_block_and2
/*2300*/          OPC_CheckComplexPat, /*CP*/1, /*#*/2, // selectBDAddr12Only:$dest #5 #6
/*2303*/          OPC_CheckComplexPat, /*CP*/1, /*#*/4, // selectBDAddr12Only:$src #7 #8
/*2306*/          OPC_EmitMergeInputChains, 3, 0, 1, 3, 
/*2311*/          OPC_EmitInteger, MVT::i64, 2, 
/*2314*/          OPC_MorphNodeTo, TARGET_VAL(SystemZ::NCSequence), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i32, 5/*#Ops*/, 5, 6, 7, 8, 9, 
                  // Src: (st (and:i64 (ld:i64 bdaddr12only:i64:$dest)<<P:Predicate_unindexedload>>, (ld:i64 bdaddr12only:i64:$src)<<P:Predicate_unindexedload>><<P:Predicate_anyextload>><<P:Predicate_anyextloadi16>>), bdaddr12only:i64:$dest)<<P:Predicate_unindexedstore>><<P:Predicate_block_and2>> - Complexity = 42
                  // Dst: (NCSequence:i32 bdaddr12only:i64:$dest, bdaddr12only:i64:$src, 2:i64)
/*2326*/        /*Scope*/ 54, /*->2381*/
/*2327*/          OPC_CheckPredicate, 1, // Predicate_anyextload
/*2329*/          OPC_CheckPredicate, 17, // Predicate_anyextloadi32
/*2331*/          OPC_MoveParent,
/*2332*/          OPC_MoveChild, 1,
/*2334*/          OPC_CheckOpcode, TARGET_VAL(ISD::LOAD),
/*2337*/          OPC_RecordMemRef,
/*2338*/          OPC_RecordNode, // #3 = 'ld' chained node
/*2339*/          OPC_CheckFoldableChainNode,
/*2340*/          OPC_RecordChild1, // #4 = $dest
/*2341*/          OPC_CheckChild1Type, MVT::i64,
/*2343*/          OPC_CheckPredicate, 0, // Predicate_unindexedload
/*2345*/          OPC_MoveParent,
/*2346*/          OPC_CheckType, MVT::i64,
/*2348*/          OPC_MoveParent,
/*2349*/          OPC_CheckChild2Same, 4,
/*2351*/          OPC_CheckPredicate, 5, // Predicate_unindexedstore
/*2353*/          OPC_CheckPredicate, 21, // Predicate_block_and1
/*2355*/          OPC_CheckComplexPat, /*CP*/1, /*#*/2, // selectBDAddr12Only:$src #5 #6
/*2358*/          OPC_CheckComplexPat, /*CP*/1, /*#*/4, // selectBDAddr12Only:$dest #7 #8
/*2361*/          OPC_EmitMergeInputChains, 3, 0, 1, 3, 
/*2366*/          OPC_EmitInteger, MVT::i64, 4, 
/*2369*/          OPC_MorphNodeTo, TARGET_VAL(SystemZ::NCSequence), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i32, 5/*#Ops*/, 7, 8, 5, 6, 9, 
                  // Src: (st (and:i64 (ld:i64 bdaddr12only:i64:$src)<<P:Predicate_unindexedload>><<P:Predicate_anyextload>><<P:Predicate_anyextloadi32>>, (ld:i64 bdaddr12only:i64:$dest)<<P:Predicate_unindexedload>>), bdaddr12only:i64:$dest)<<P:Predicate_unindexedstore>><<P:Predicate_block_and1>> - Complexity = 42
                  // Dst: (NCSequence:i32 bdaddr12only:i64:$dest, bdaddr12only:i64:$src, 4:i64)
/*2381*/        /*Scope*/ 54, /*->2436*/
/*2382*/          OPC_MoveParent,
/*2383*/          OPC_MoveChild, 1,
/*2385*/          OPC_CheckOpcode, TARGET_VAL(ISD::LOAD),
/*2388*/          OPC_RecordMemRef,
/*2389*/          OPC_RecordNode, // #3 = 'ld' chained node
/*2390*/          OPC_CheckFoldableChainNode,
/*2391*/          OPC_RecordChild1, // #4 = $src
/*2392*/          OPC_CheckChild1Type, MVT::i64,
/*2394*/          OPC_CheckPredicate, 0, // Predicate_unindexedload
/*2396*/          OPC_CheckPredicate, 1, // Predicate_anyextload
/*2398*/          OPC_CheckPredicate, 17, // Predicate_anyextloadi32
/*2400*/          OPC_MoveParent,
/*2401*/          OPC_CheckType, MVT::i64,
/*2403*/          OPC_MoveParent,
/*2404*/          OPC_CheckChild2Same, 2,
/*2406*/          OPC_CheckPredicate, 5, // Predicate_unindexedstore
/*2408*/          OPC_CheckPredicate, 22, // Predicate_block_and2
/*2410*/          OPC_CheckComplexPat, /*CP*/1, /*#*/2, // selectBDAddr12Only:$dest #5 #6
/*2413*/          OPC_CheckComplexPat, /*CP*/1, /*#*/4, // selectBDAddr12Only:$src #7 #8
/*2416*/          OPC_EmitMergeInputChains, 3, 0, 1, 3, 
/*2421*/          OPC_EmitInteger, MVT::i64, 4, 
/*2424*/          OPC_MorphNodeTo, TARGET_VAL(SystemZ::NCSequence), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i32, 5/*#Ops*/, 5, 6, 7, 8, 9, 
                  // Src: (st (and:i64 (ld:i64 bdaddr12only:i64:$dest)<<P:Predicate_unindexedload>>, (ld:i64 bdaddr12only:i64:$src)<<P:Predicate_unindexedload>><<P:Predicate_anyextload>><<P:Predicate_anyextloadi32>>), bdaddr12only:i64:$dest)<<P:Predicate_unindexedstore>><<P:Predicate_block_and2>> - Complexity = 42
                  // Dst: (NCSequence:i32 bdaddr12only:i64:$dest, bdaddr12only:i64:$src, 4:i64)
/*2436*/        /*Scope*/ 52, /*->2489*/
/*2437*/          OPC_CheckPredicate, 13, // Predicate_load
/*2439*/          OPC_MoveParent,
/*2440*/          OPC_MoveChild, 1,
/*2442*/          OPC_CheckOpcode, TARGET_VAL(ISD::LOAD),
/*2445*/          OPC_RecordMemRef,
/*2446*/          OPC_RecordNode, // #3 = 'ld' chained node
/*2447*/          OPC_CheckFoldableChainNode,
/*2448*/          OPC_RecordChild1, // #4 = $dest
/*2449*/          OPC_CheckChild1Type, MVT::i64,
/*2451*/          OPC_CheckPredicate, 0, // Predicate_unindexedload
/*2453*/          OPC_MoveParent,
/*2454*/          OPC_CheckType, MVT::i64,
/*2456*/          OPC_MoveParent,
/*2457*/          OPC_CheckChild2Same, 4,
/*2459*/          OPC_CheckPredicate, 5, // Predicate_unindexedstore
/*2461*/          OPC_CheckPredicate, 21, // Predicate_block_and1
/*2463*/          OPC_CheckComplexPat, /*CP*/1, /*#*/2, // selectBDAddr12Only:$src #5 #6
/*2466*/          OPC_CheckComplexPat, /*CP*/1, /*#*/4, // selectBDAddr12Only:$dest #7 #8
/*2469*/          OPC_EmitMergeInputChains, 3, 0, 1, 3, 
/*2474*/          OPC_EmitInteger, MVT::i64, 8, 
/*2477*/          OPC_MorphNodeTo, TARGET_VAL(SystemZ::NCSequence), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i32, 5/*#Ops*/, 7, 8, 5, 6, 9, 
                  // Src: (st (and:i64 (ld:i64 bdaddr12only:i64:$src)<<P:Predicate_unindexedload>><<P:Predicate_load>>, (ld:i64 bdaddr12only:i64:$dest)<<P:Predicate_unindexedload>>), bdaddr12only:i64:$dest)<<P:Predicate_unindexedstore>><<P:Predicate_block_and1>> - Complexity = 42
                  // Dst: (NCSequence:i32 bdaddr12only:i64:$dest, bdaddr12only:i64:$src, 8:i64)
/*2489*/        /*Scope*/ 96, /*->2586*/
/*2490*/          OPC_MoveParent,
/*2491*/          OPC_MoveChild, 1,
/*2493*/          OPC_CheckOpcode, TARGET_VAL(ISD::LOAD),
/*2496*/          OPC_RecordMemRef,
/*2497*/          OPC_RecordNode, // #3 = 'ld' chained node
/*2498*/          OPC_CheckFoldableChainNode,
/*2499*/          OPC_RecordChild1, // #4 = $src
/*2500*/          OPC_CheckChild1Type, MVT::i64,
/*2502*/          OPC_CheckPredicate, 0, // Predicate_unindexedload
/*2504*/          OPC_Scope, 38, /*->2544*/ // 2 children in Scope
/*2506*/            OPC_CheckPredicate, 13, // Predicate_load
/*2508*/            OPC_MoveParent,
/*2509*/            OPC_CheckType, MVT::i64,
/*2511*/            OPC_MoveParent,
/*2512*/            OPC_CheckChild2Same, 2,
/*2514*/            OPC_CheckPredicate, 5, // Predicate_unindexedstore
/*2516*/            OPC_CheckPredicate, 22, // Predicate_block_and2
/*2518*/            OPC_CheckComplexPat, /*CP*/1, /*#*/2, // selectBDAddr12Only:$dest #5 #6
/*2521*/            OPC_CheckComplexPat, /*CP*/1, /*#*/4, // selectBDAddr12Only:$src #7 #8
/*2524*/            OPC_EmitMergeInputChains, 3, 0, 1, 3, 
/*2529*/            OPC_EmitInteger, MVT::i64, 8, 
/*2532*/            OPC_MorphNodeTo, TARGET_VAL(SystemZ::NCSequence), 0|OPFL_Chain|OPFL_MemRefs,
                        1/*#VTs*/, MVT::i32, 5/*#Ops*/, 5, 6, 7, 8, 9, 
                    // Src: (st (and:i64 (ld:i64 bdaddr12only:i64:$dest)<<P:Predicate_unindexedload>>, (ld:i64 bdaddr12only:i64:$src)<<P:Predicate_unindexedload>><<P:Predicate_load>>), bdaddr12only:i64:$dest)<<P:Predicate_unindexedstore>><<P:Predicate_block_and2>> - Complexity = 42
                    // Dst: (NCSequence:i32 bdaddr12only:i64:$dest, bdaddr12only:i64:$src, 8:i64)
/*2544*/          /*Scope*/ 40, /*->2585*/
/*2545*/            OPC_CheckPredicate, 1, // Predicate_anyextload
/*2547*/            OPC_CheckPredicate, 9, // Predicate_anyextloadi16
/*2549*/            OPC_MoveParent,
/*2550*/            OPC_CheckType, MVT::i32,
/*2552*/            OPC_MoveParent,
/*2553*/            OPC_CheckChild2Same, 2,
/*2555*/            OPC_CheckPredicate, 5, // Predicate_unindexedstore
/*2557*/            OPC_CheckPredicate, 21, // Predicate_block_and1
/*2559*/            OPC_CheckComplexPat, /*CP*/1, /*#*/2, // selectBDAddr12Only:$dest #5 #6
/*2562*/            OPC_CheckComplexPat, /*CP*/1, /*#*/4, // selectBDAddr12Only:$src #7 #8
/*2565*/            OPC_EmitMergeInputChains, 3, 0, 1, 3, 
/*2570*/            OPC_EmitInteger, MVT::i64, 2, 
/*2573*/            OPC_MorphNodeTo, TARGET_VAL(SystemZ::NCSequence), 0|OPFL_Chain|OPFL_MemRefs,
                        1/*#VTs*/, MVT::i32, 5/*#Ops*/, 5, 6, 7, 8, 9, 
                    // Src: (st (and:i32 (ld:i32 bdaddr12only:i64:$dest)<<P:Predicate_unindexedload>>, (ld:i32 bdaddr12only:i64:$src)<<P:Predicate_unindexedload>><<P:Predicate_anyextload>><<P:Predicate_anyextloadi16>>), bdaddr12only:i64:$dest)<<P:Predicate_unindexedstore>><<P:Predicate_block_and1>> - Complexity = 42
                    // Dst: (NCSequence:i32 bdaddr12only:i64:$dest, bdaddr12only:i64:$src, 2:i64)
/*2585*/          0, /*End of Scope*/
/*2586*/        /*Scope*/ 54, /*->2641*/
/*2587*/          OPC_CheckPredicate, 1, // Predicate_anyextload
/*2589*/          OPC_CheckPredicate, 9, // Predicate_anyextloadi16
/*2591*/          OPC_MoveParent,
/*2592*/          OPC_MoveChild, 1,
/*2594*/          OPC_CheckOpcode, TARGET_VAL(ISD::LOAD),
/*2597*/          OPC_RecordMemRef,
/*2598*/          OPC_RecordNode, // #3 = 'ld' chained node
/*2599*/          OPC_CheckFoldableChainNode,
/*2600*/          OPC_RecordChild1, // #4 = $dest
/*2601*/          OPC_CheckChild1Type, MVT::i64,
/*2603*/          OPC_CheckPredicate, 0, // Predicate_unindexedload
/*2605*/          OPC_MoveParent,
/*2606*/          OPC_CheckType, MVT::i32,
/*2608*/          OPC_MoveParent,
/*2609*/          OPC_CheckChild2Same, 4,
/*2611*/          OPC_CheckPredicate, 5, // Predicate_unindexedstore
/*2613*/          OPC_CheckPredicate, 22, // Predicate_block_and2
/*2615*/          OPC_CheckComplexPat, /*CP*/1, /*#*/2, // selectBDAddr12Only:$src #5 #6
/*2618*/          OPC_CheckComplexPat, /*CP*/1, /*#*/4, // selectBDAddr12Only:$dest #7 #8
/*2621*/          OPC_EmitMergeInputChains, 3, 0, 1, 3, 
/*2626*/          OPC_EmitInteger, MVT::i64, 2, 
/*2629*/          OPC_MorphNodeTo, TARGET_VAL(SystemZ::NCSequence), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i32, 5/*#Ops*/, 7, 8, 5, 6, 9, 
                  // Src: (st (and:i32 (ld:i32 bdaddr12only:i64:$src)<<P:Predicate_unindexedload>><<P:Predicate_anyextload>><<P:Predicate_anyextloadi16>>, (ld:i32 bdaddr12only:i64:$dest)<<P:Predicate_unindexedload>>), bdaddr12only:i64:$dest)<<P:Predicate_unindexedstore>><<P:Predicate_block_and2>> - Complexity = 42
                  // Dst: (NCSequence:i32 bdaddr12only:i64:$dest, bdaddr12only:i64:$src, 2:i64)
/*2641*/        /*Scope*/ 52, /*->2694*/
/*2642*/          OPC_MoveParent,
/*2643*/          OPC_MoveChild, 1,
/*2645*/          OPC_CheckOpcode, TARGET_VAL(ISD::LOAD),
/*2648*/          OPC_RecordMemRef,
/*2649*/          OPC_RecordNode, // #3 = 'ld' chained node
/*2650*/          OPC_CheckFoldableChainNode,
/*2651*/          OPC_RecordChild1, // #4 = $src
/*2652*/          OPC_CheckChild1Type, MVT::i64,
/*2654*/          OPC_CheckPredicate, 0, // Predicate_unindexedload
/*2656*/          OPC_CheckPredicate, 13, // Predicate_load
/*2658*/          OPC_MoveParent,
/*2659*/          OPC_CheckType, MVT::i32,
/*2661*/          OPC_MoveParent,
/*2662*/          OPC_CheckChild2Same, 2,
/*2664*/          OPC_CheckPredicate, 5, // Predicate_unindexedstore
/*2666*/          OPC_CheckPredicate, 21, // Predicate_block_and1
/*2668*/          OPC_CheckComplexPat, /*CP*/1, /*#*/2, // selectBDAddr12Only:$dest #5 #6
/*2671*/          OPC_CheckComplexPat, /*CP*/1, /*#*/4, // selectBDAddr12Only:$src #7 #8
/*2674*/          OPC_EmitMergeInputChains, 3, 0, 1, 3, 
/*2679*/          OPC_EmitInteger, MVT::i64, 4, 
/*2682*/          OPC_MorphNodeTo, TARGET_VAL(SystemZ::NCSequence), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i32, 5/*#Ops*/, 5, 6, 7, 8, 9, 
                  // Src: (st (and:i32 (ld:i32 bdaddr12only:i64:$dest)<<P:Predicate_unindexedload>>, (ld:i32 bdaddr12only:i64:$src)<<P:Predicate_unindexedload>><<P:Predicate_load>>), bdaddr12only:i64:$dest)<<P:Predicate_unindexedstore>><<P:Predicate_block_and1>> - Complexity = 42
                  // Dst: (NCSequence:i32 bdaddr12only:i64:$dest, bdaddr12only:i64:$src, 4:i64)
/*2694*/        /*Scope*/ 52, /*->2747*/
/*2695*/          OPC_CheckPredicate, 13, // Predicate_load
/*2697*/          OPC_MoveParent,
/*2698*/          OPC_MoveChild, 1,
/*2700*/          OPC_CheckOpcode, TARGET_VAL(ISD::LOAD),
/*2703*/          OPC_RecordMemRef,
/*2704*/          OPC_RecordNode, // #3 = 'ld' chained node
/*2705*/          OPC_CheckFoldableChainNode,
/*2706*/          OPC_RecordChild1, // #4 = $dest
/*2707*/          OPC_CheckChild1Type, MVT::i64,
/*2709*/          OPC_CheckPredicate, 0, // Predicate_unindexedload
/*2711*/          OPC_MoveParent,
/*2712*/          OPC_CheckType, MVT::i32,
/*2714*/          OPC_MoveParent,
/*2715*/          OPC_CheckChild2Same, 4,
/*2717*/          OPC_CheckPredicate, 5, // Predicate_unindexedstore
/*2719*/          OPC_CheckPredicate, 22, // Predicate_block_and2
/*2721*/          OPC_CheckComplexPat, /*CP*/1, /*#*/2, // selectBDAddr12Only:$src #5 #6
/*2724*/          OPC_CheckComplexPat, /*CP*/1, /*#*/4, // selectBDAddr12Only:$dest #7 #8
/*2727*/          OPC_EmitMergeInputChains, 3, 0, 1, 3, 
/*2732*/          OPC_EmitInteger, MVT::i64, 4, 
/*2735*/          OPC_MorphNodeTo, TARGET_VAL(SystemZ::NCSequence), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i32, 5/*#Ops*/, 7, 8, 5, 6, 9, 
                  // Src: (st (and:i32 (ld:i32 bdaddr12only:i64:$src)<<P:Predicate_unindexedload>><<P:Predicate_load>>, (ld:i32 bdaddr12only:i64:$dest)<<P:Predicate_unindexedload>>), bdaddr12only:i64:$dest)<<P:Predicate_unindexedstore>><<P:Predicate_block_and2>> - Complexity = 42
                  // Dst: (NCSequence:i32 bdaddr12only:i64:$dest, bdaddr12only:i64:$src, 4:i64)
/*2747*/        /*Scope*/ 54, /*->2802*/
/*2748*/          OPC_MoveParent,
/*2749*/          OPC_MoveChild, 1,
/*2751*/          OPC_CheckOpcode, TARGET_VAL(ISD::LOAD),
/*2754*/          OPC_RecordMemRef,
/*2755*/          OPC_RecordNode, // #3 = 'ld' chained node
/*2756*/          OPC_CheckFoldableChainNode,
/*2757*/          OPC_RecordChild1, // #4 = $src
/*2758*/          OPC_CheckChild1Type, MVT::i64,
/*2760*/          OPC_CheckPredicate, 0, // Predicate_unindexedload
/*2762*/          OPC_CheckPredicate, 1, // Predicate_anyextload
/*2764*/          OPC_CheckPredicate, 2, // Predicate_anyextloadi8
/*2766*/          OPC_MoveParent,
/*2767*/          OPC_CheckType, MVT::i64,
/*2769*/          OPC_MoveParent,
/*2770*/          OPC_CheckChild2Same, 2,
/*2772*/          OPC_CheckPredicate, 5, // Predicate_unindexedstore
/*2774*/          OPC_CheckPredicate, 21, // Predicate_block_and1
/*2776*/          OPC_CheckComplexPat, /*CP*/1, /*#*/2, // selectBDAddr12Only:$dest #5 #6
/*2779*/          OPC_CheckComplexPat, /*CP*/1, /*#*/4, // selectBDAddr12Only:$src #7 #8
/*2782*/          OPC_EmitMergeInputChains, 3, 0, 1, 3, 
/*2787*/          OPC_EmitInteger, MVT::i64, 1, 
/*2790*/          OPC_MorphNodeTo, TARGET_VAL(SystemZ::NCSequence), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i32, 5/*#Ops*/, 5, 6, 7, 8, 9, 
                  // Src: (st (and:i64 (ld:i64 bdaddr12only:i64:$dest)<<P:Predicate_unindexedload>>, (ld:i64 bdaddr12only:i64:$src)<<P:Predicate_unindexedload>><<P:Predicate_anyextload>><<P:Predicate_anyextloadi8>>), bdaddr12only:i64:$dest)<<P:Predicate_unindexedstore>><<P:Predicate_block_and1>> - Complexity = 42
                  // Dst: (NCSequence:i32 bdaddr12only:i64:$dest, bdaddr12only:i64:$src, 1:i64)
/*2802*/        /*Scope*/ 54, /*->2857*/
/*2803*/          OPC_CheckPredicate, 1, // Predicate_anyextload
/*2805*/          OPC_CheckPredicate, 2, // Predicate_anyextloadi8
/*2807*/          OPC_MoveParent,
/*2808*/          OPC_MoveChild, 1,
/*2810*/          OPC_CheckOpcode, TARGET_VAL(ISD::LOAD),
/*2813*/          OPC_RecordMemRef,
/*2814*/          OPC_RecordNode, // #3 = 'ld' chained node
/*2815*/          OPC_CheckFoldableChainNode,
/*2816*/          OPC_RecordChild1, // #4 = $dest
/*2817*/          OPC_CheckChild1Type, MVT::i64,
/*2819*/          OPC_CheckPredicate, 0, // Predicate_unindexedload
/*2821*/          OPC_MoveParent,
/*2822*/          OPC_CheckType, MVT::i64,
/*2824*/          OPC_MoveParent,
/*2825*/          OPC_CheckChild2Same, 4,
/*2827*/          OPC_CheckPredicate, 5, // Predicate_unindexedstore
/*2829*/          OPC_CheckPredicate, 22, // Predicate_block_and2
/*2831*/          OPC_CheckComplexPat, /*CP*/1, /*#*/2, // selectBDAddr12Only:$src #5 #6
/*2834*/          OPC_CheckComplexPat, /*CP*/1, /*#*/4, // selectBDAddr12Only:$dest #7 #8
/*2837*/          OPC_EmitMergeInputChains, 3, 0, 1, 3, 
/*2842*/          OPC_EmitInteger, MVT::i64, 1, 
/*2845*/          OPC_MorphNodeTo, TARGET_VAL(SystemZ::NCSequence), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i32, 5/*#Ops*/, 7, 8, 5, 6, 9, 
                  // Src: (st (and:i64 (ld:i64 bdaddr12only:i64:$src)<<P:Predicate_unindexedload>><<P:Predicate_anyextload>><<P:Predicate_anyextloadi8>>, (ld:i64 bdaddr12only:i64:$dest)<<P:Predicate_unindexedload>>), bdaddr12only:i64:$dest)<<P:Predicate_unindexedstore>><<P:Predicate_block_and2>> - Complexity = 42
                  // Dst: (NCSequence:i32 bdaddr12only:i64:$dest, bdaddr12only:i64:$src, 1:i64)
/*2857*/        /*Scope*/ 54, /*->2912*/
/*2858*/          OPC_MoveParent,
/*2859*/          OPC_MoveChild, 1,
/*2861*/          OPC_CheckOpcode, TARGET_VAL(ISD::LOAD),
/*2864*/          OPC_RecordMemRef,
/*2865*/          OPC_RecordNode, // #3 = 'ld' chained node
/*2866*/          OPC_CheckFoldableChainNode,
/*2867*/          OPC_RecordChild1, // #4 = $src
/*2868*/          OPC_CheckChild1Type, MVT::i64,
/*2870*/          OPC_CheckPredicate, 0, // Predicate_unindexedload
/*2872*/          OPC_CheckPredicate, 1, // Predicate_anyextload
/*2874*/          OPC_CheckPredicate, 9, // Predicate_anyextloadi16
/*2876*/          OPC_MoveParent,
/*2877*/          OPC_CheckType, MVT::i64,
/*2879*/          OPC_MoveParent,
/*2880*/          OPC_CheckChild2Same, 2,
/*2882*/          OPC_CheckPredicate, 5, // Predicate_unindexedstore
/*2884*/          OPC_CheckPredicate, 21, // Predicate_block_and1
/*2886*/          OPC_CheckComplexPat, /*CP*/1, /*#*/2, // selectBDAddr12Only:$dest #5 #6
/*2889*/          OPC_CheckComplexPat, /*CP*/1, /*#*/4, // selectBDAddr12Only:$src #7 #8
/*2892*/          OPC_EmitMergeInputChains, 3, 0, 1, 3, 
/*2897*/          OPC_EmitInteger, MVT::i64, 2, 
/*2900*/          OPC_MorphNodeTo, TARGET_VAL(SystemZ::NCSequence), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i32, 5/*#Ops*/, 5, 6, 7, 8, 9, 
                  // Src: (st (and:i64 (ld:i64 bdaddr12only:i64:$dest)<<P:Predicate_unindexedload>>, (ld:i64 bdaddr12only:i64:$src)<<P:Predicate_unindexedload>><<P:Predicate_anyextload>><<P:Predicate_anyextloadi16>>), bdaddr12only:i64:$dest)<<P:Predicate_unindexedstore>><<P:Predicate_block_and1>> - Complexity = 42
                  // Dst: (NCSequence:i32 bdaddr12only:i64:$dest, bdaddr12only:i64:$src, 2:i64)
/*2912*/        /*Scope*/ 54, /*->2967*/
/*2913*/          OPC_CheckPredicate, 1, // Predicate_anyextload
/*2915*/          OPC_CheckPredicate, 9, // Predicate_anyextloadi16
/*2917*/          OPC_MoveParent,
/*2918*/          OPC_MoveChild, 1,
/*2920*/          OPC_CheckOpcode, TARGET_VAL(ISD::LOAD),
/*2923*/          OPC_RecordMemRef,
/*2924*/          OPC_RecordNode, // #3 = 'ld' chained node
/*2925*/          OPC_CheckFoldableChainNode,
/*2926*/          OPC_RecordChild1, // #4 = $dest
/*2927*/          OPC_CheckChild1Type, MVT::i64,
/*2929*/          OPC_CheckPredicate, 0, // Predicate_unindexedload
/*2931*/          OPC_MoveParent,
/*2932*/          OPC_CheckType, MVT::i64,
/*2934*/          OPC_MoveParent,
/*2935*/          OPC_CheckChild2Same, 4,
/*2937*/          OPC_CheckPredicate, 5, // Predicate_unindexedstore
/*2939*/          OPC_CheckPredicate, 22, // Predicate_block_and2
/*2941*/          OPC_CheckComplexPat, /*CP*/1, /*#*/2, // selectBDAddr12Only:$src #5 #6
/*2944*/          OPC_CheckComplexPat, /*CP*/1, /*#*/4, // selectBDAddr12Only:$dest #7 #8
/*2947*/          OPC_EmitMergeInputChains, 3, 0, 1, 3, 
/*2952*/          OPC_EmitInteger, MVT::i64, 2, 
/*2955*/          OPC_MorphNodeTo, TARGET_VAL(SystemZ::NCSequence), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i32, 5/*#Ops*/, 7, 8, 5, 6, 9, 
                  // Src: (st (and:i64 (ld:i64 bdaddr12only:i64:$src)<<P:Predicate_unindexedload>><<P:Predicate_anyextload>><<P:Predicate_anyextloadi16>>, (ld:i64 bdaddr12only:i64:$dest)<<P:Predicate_unindexedload>>), bdaddr12only:i64:$dest)<<P:Predicate_unindexedstore>><<P:Predicate_block_and2>> - Complexity = 42
                  // Dst: (NCSequence:i32 bdaddr12only:i64:$dest, bdaddr12only:i64:$src, 2:i64)
/*2967*/        /*Scope*/ 54, /*->3022*/
/*2968*/          OPC_MoveParent,
/*2969*/          OPC_MoveChild, 1,
/*2971*/          OPC_CheckOpcode, TARGET_VAL(ISD::LOAD),
/*2974*/          OPC_RecordMemRef,
/*2975*/          OPC_RecordNode, // #3 = 'ld' chained node
/*2976*/          OPC_CheckFoldableChainNode,
/*2977*/          OPC_RecordChild1, // #4 = $src
/*2978*/          OPC_CheckChild1Type, MVT::i64,
/*2980*/          OPC_CheckPredicate, 0, // Predicate_unindexedload
/*2982*/          OPC_CheckPredicate, 1, // Predicate_anyextload
/*2984*/          OPC_CheckPredicate, 17, // Predicate_anyextloadi32
/*2986*/          OPC_MoveParent,
/*2987*/          OPC_CheckType, MVT::i64,
/*2989*/          OPC_MoveParent,
/*2990*/          OPC_CheckChild2Same, 2,
/*2992*/          OPC_CheckPredicate, 5, // Predicate_unindexedstore
/*2994*/          OPC_CheckPredicate, 21, // Predicate_block_and1
/*2996*/          OPC_CheckComplexPat, /*CP*/1, /*#*/2, // selectBDAddr12Only:$dest #5 #6
/*2999*/          OPC_CheckComplexPat, /*CP*/1, /*#*/4, // selectBDAddr12Only:$src #7 #8
/*3002*/          OPC_EmitMergeInputChains, 3, 0, 1, 3, 
/*3007*/          OPC_EmitInteger, MVT::i64, 4, 
/*3010*/          OPC_MorphNodeTo, TARGET_VAL(SystemZ::NCSequence), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i32, 5/*#Ops*/, 5, 6, 7, 8, 9, 
                  // Src: (st (and:i64 (ld:i64 bdaddr12only:i64:$dest)<<P:Predicate_unindexedload>>, (ld:i64 bdaddr12only:i64:$src)<<P:Predicate_unindexedload>><<P:Predicate_anyextload>><<P:Predicate_anyextloadi32>>), bdaddr12only:i64:$dest)<<P:Predicate_unindexedstore>><<P:Predicate_block_and1>> - Complexity = 42
                  // Dst: (NCSequence:i32 bdaddr12only:i64:$dest, bdaddr12only:i64:$src, 4:i64)
/*3022*/        /*Scope*/ 54, /*->3077*/
/*3023*/          OPC_CheckPredicate, 1, // Predicate_anyextload
/*3025*/          OPC_CheckPredicate, 17, // Predicate_anyextloadi32
/*3027*/          OPC_MoveParent,
/*3028*/          OPC_MoveChild, 1,
/*3030*/          OPC_CheckOpcode, TARGET_VAL(ISD::LOAD),
/*3033*/          OPC_RecordMemRef,
/*3034*/          OPC_RecordNode, // #3 = 'ld' chained node
/*3035*/          OPC_CheckFoldableChainNode,
/*3036*/          OPC_RecordChild1, // #4 = $dest
/*3037*/          OPC_CheckChild1Type, MVT::i64,
/*3039*/          OPC_CheckPredicate, 0, // Predicate_unindexedload
/*3041*/          OPC_MoveParent,
/*3042*/          OPC_CheckType, MVT::i64,
/*3044*/          OPC_MoveParent,
/*3045*/          OPC_CheckChild2Same, 4,
/*3047*/          OPC_CheckPredicate, 5, // Predicate_unindexedstore
/*3049*/          OPC_CheckPredicate, 22, // Predicate_block_and2
/*3051*/          OPC_CheckComplexPat, /*CP*/1, /*#*/2, // selectBDAddr12Only:$src #5 #6
/*3054*/          OPC_CheckComplexPat, /*CP*/1, /*#*/4, // selectBDAddr12Only:$dest #7 #8
/*3057*/          OPC_EmitMergeInputChains, 3, 0, 1, 3, 
/*3062*/          OPC_EmitInteger, MVT::i64, 4, 
/*3065*/          OPC_MorphNodeTo, TARGET_VAL(SystemZ::NCSequence), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i32, 5/*#Ops*/, 7, 8, 5, 6, 9, 
                  // Src: (st (and:i64 (ld:i64 bdaddr12only:i64:$src)<<P:Predicate_unindexedload>><<P:Predicate_anyextload>><<P:Predicate_anyextloadi32>>, (ld:i64 bdaddr12only:i64:$dest)<<P:Predicate_unindexedload>>), bdaddr12only:i64:$dest)<<P:Predicate_unindexedstore>><<P:Predicate_block_and2>> - Complexity = 42
                  // Dst: (NCSequence:i32 bdaddr12only:i64:$dest, bdaddr12only:i64:$src, 4:i64)
/*3077*/        /*Scope*/ 52, /*->3130*/
/*3078*/          OPC_MoveParent,
/*3079*/          OPC_MoveChild, 1,
/*3081*/          OPC_CheckOpcode, TARGET_VAL(ISD::LOAD),
/*3084*/          OPC_RecordMemRef,
/*3085*/          OPC_RecordNode, // #3 = 'ld' chained node
/*3086*/          OPC_CheckFoldableChainNode,
/*3087*/          OPC_RecordChild1, // #4 = $src
/*3088*/          OPC_CheckChild1Type, MVT::i64,
/*3090*/          OPC_CheckPredicate, 0, // Predicate_unindexedload
/*3092*/          OPC_CheckPredicate, 13, // Predicate_load
/*3094*/          OPC_MoveParent,
/*3095*/          OPC_CheckType, MVT::i64,
/*3097*/          OPC_MoveParent,
/*3098*/          OPC_CheckChild2Same, 2,
/*3100*/          OPC_CheckPredicate, 5, // Predicate_unindexedstore
/*3102*/          OPC_CheckPredicate, 21, // Predicate_block_and1
/*3104*/          OPC_CheckComplexPat, /*CP*/1, /*#*/2, // selectBDAddr12Only:$dest #5 #6
/*3107*/          OPC_CheckComplexPat, /*CP*/1, /*#*/4, // selectBDAddr12Only:$src #7 #8
/*3110*/          OPC_EmitMergeInputChains, 3, 0, 1, 3, 
/*3115*/          OPC_EmitInteger, MVT::i64, 8, 
/*3118*/          OPC_MorphNodeTo, TARGET_VAL(SystemZ::NCSequence), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i32, 5/*#Ops*/, 5, 6, 7, 8, 9, 
                  // Src: (st (and:i64 (ld:i64 bdaddr12only:i64:$dest)<<P:Predicate_unindexedload>>, (ld:i64 bdaddr12only:i64:$src)<<P:Predicate_unindexedload>><<P:Predicate_load>>), bdaddr12only:i64:$dest)<<P:Predicate_unindexedstore>><<P:Predicate_block_and1>> - Complexity = 42
                  // Dst: (NCSequence:i32 bdaddr12only:i64:$dest, bdaddr12only:i64:$src, 8:i64)
/*3130*/        /*Scope*/ 52, /*->3183*/
/*3131*/          OPC_CheckPredicate, 13, // Predicate_load
/*3133*/          OPC_MoveParent,
/*3134*/          OPC_MoveChild, 1,
/*3136*/          OPC_CheckOpcode, TARGET_VAL(ISD::LOAD),
/*3139*/          OPC_RecordMemRef,
/*3140*/          OPC_RecordNode, // #3 = 'ld' chained node
/*3141*/          OPC_CheckFoldableChainNode,
/*3142*/          OPC_RecordChild1, // #4 = $dest
/*3143*/          OPC_CheckChild1Type, MVT::i64,
/*3145*/          OPC_CheckPredicate, 0, // Predicate_unindexedload
/*3147*/          OPC_MoveParent,
/*3148*/          OPC_CheckType, MVT::i64,
/*3150*/          OPC_MoveParent,
/*3151*/          OPC_CheckChild2Same, 4,
/*3153*/          OPC_CheckPredicate, 5, // Predicate_unindexedstore
/*3155*/          OPC_CheckPredicate, 22, // Predicate_block_and2
/*3157*/          OPC_CheckComplexPat, /*CP*/1, /*#*/2, // selectBDAddr12Only:$src #5 #6
/*3160*/          OPC_CheckComplexPat, /*CP*/1, /*#*/4, // selectBDAddr12Only:$dest #7 #8
/*3163*/          OPC_EmitMergeInputChains, 3, 0, 1, 3, 
/*3168*/          OPC_EmitInteger, MVT::i64, 8, 
/*3171*/          OPC_MorphNodeTo, TARGET_VAL(SystemZ::NCSequence), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i32, 5/*#Ops*/, 7, 8, 5, 6, 9, 
                  // Src: (st (and:i64 (ld:i64 bdaddr12only:i64:$src)<<P:Predicate_unindexedload>><<P:Predicate_load>>, (ld:i64 bdaddr12only:i64:$dest)<<P:Predicate_unindexedload>>), bdaddr12only:i64:$dest)<<P:Predicate_unindexedstore>><<P:Predicate_block_and2>> - Complexity = 42
                  // Dst: (NCSequence:i32 bdaddr12only:i64:$dest, bdaddr12only:i64:$src, 8:i64)
/*3183*/        /*Scope*/ 54, /*->3238*/
/*3184*/          OPC_MoveParent,
/*3185*/          OPC_MoveChild, 1,
/*3187*/          OPC_CheckOpcode, TARGET_VAL(ISD::LOAD),
/*3190*/          OPC_RecordMemRef,
/*3191*/          OPC_RecordNode, // #3 = 'ld' chained node
/*3192*/          OPC_CheckFoldableChainNode,
/*3193*/          OPC_RecordChild1, // #4 = $src
/*3194*/          OPC_CheckChild1Type, MVT::i64,
/*3196*/          OPC_CheckPredicate, 0, // Predicate_unindexedload
/*3198*/          OPC_CheckPredicate, 1, // Predicate_anyextload
/*3200*/          OPC_CheckPredicate, 2, // Predicate_anyextloadi8
/*3202*/          OPC_MoveParent,
/*3203*/          OPC_CheckType, MVT::i32,
/*3205*/          OPC_MoveParent,
/*3206*/          OPC_CheckChild2Same, 2,
/*3208*/          OPC_CheckPredicate, 5, // Predicate_unindexedstore
/*3210*/          OPC_CheckPredicate, 21, // Predicate_block_and1
/*3212*/          OPC_CheckComplexPat, /*CP*/1, /*#*/2, // selectBDAddr12Only:$dest #5 #6
/*3215*/          OPC_CheckComplexPat, /*CP*/1, /*#*/4, // selectBDAddr12Only:$src #7 #8
/*3218*/          OPC_EmitMergeInputChains, 3, 0, 1, 3, 
/*3223*/          OPC_EmitInteger, MVT::i64, 1, 
/*3226*/          OPC_MorphNodeTo, TARGET_VAL(SystemZ::NCSequence), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i32, 5/*#Ops*/, 5, 6, 7, 8, 9, 
                  // Src: (st (and:i32 (ld:i32 bdaddr12only:i64:$dest)<<P:Predicate_unindexedload>>, (ld:i32 bdaddr12only:i64:$src)<<P:Predicate_unindexedload>><<P:Predicate_anyextload>><<P:Predicate_anyextloadi8>>), bdaddr12only:i64:$dest)<<P:Predicate_unindexedstore>><<P:Predicate_block_and1>> - Complexity = 42
                  // Dst: (NCSequence:i32 bdaddr12only:i64:$dest, bdaddr12only:i64:$src, 1:i64)
/*3238*/        /*Scope*/ 57|128,1/*185*/, /*->3425*/
/*3240*/          OPC_CheckPredicate, 1, // Predicate_anyextload
/*3242*/          OPC_CheckPredicate, 2, // Predicate_anyextloadi8
/*3244*/          OPC_MoveParent,
/*3245*/          OPC_Scope, 49, /*->3296*/ // 2 children in Scope
/*3247*/            OPC_MoveChild, 1,
/*3249*/            OPC_CheckOpcode, TARGET_VAL(ISD::LOAD),
/*3252*/            OPC_RecordMemRef,
/*3253*/            OPC_RecordNode, // #3 = 'ld' chained node
/*3254*/            OPC_CheckFoldableChainNode,
/*3255*/            OPC_RecordChild1, // #4 = $dest
/*3256*/            OPC_CheckChild1Type, MVT::i64,
/*3258*/            OPC_CheckPredicate, 0, // Predicate_unindexedload
/*3260*/            OPC_MoveParent,
/*3261*/            OPC_CheckType, MVT::i32,
/*3263*/            OPC_MoveParent,
/*3264*/            OPC_CheckChild2Same, 4,
/*3266*/            OPC_CheckPredicate, 5, // Predicate_unindexedstore
/*3268*/            OPC_CheckPredicate, 22, // Predicate_block_and2
/*3270*/            OPC_CheckComplexPat, /*CP*/1, /*#*/2, // selectBDAddr12Only:$src #5 #6
/*3273*/            OPC_CheckComplexPat, /*CP*/1, /*#*/4, // selectBDAddr12Only:$dest #7 #8
/*3276*/            OPC_EmitMergeInputChains, 3, 0, 1, 3, 
/*3281*/            OPC_EmitInteger, MVT::i64, 1, 
/*3284*/            OPC_MorphNodeTo, TARGET_VAL(SystemZ::NCSequence), 0|OPFL_Chain|OPFL_MemRefs,
                        1/*#VTs*/, MVT::i32, 5/*#Ops*/, 7, 8, 5, 6, 9, 
                    // Src: (st (and:i32 (ld:i32 bdaddr12only:i64:$src)<<P:Predicate_unindexedload>><<P:Predicate_anyextload>><<P:Predicate_anyextloadi8>>, (ld:i32 bdaddr12only:i64:$dest)<<P:Predicate_unindexedload>>), bdaddr12only:i64:$dest)<<P:Predicate_unindexedstore>><<P:Predicate_block_and2>> - Complexity = 42
                    // Dst: (NCSequence:i32 bdaddr12only:i64:$dest, bdaddr12only:i64:$src, 1:i64)
/*3296*/          /*Scope*/ 127, /*->3424*/
/*3297*/            OPC_RecordChild1, // #3 = $src
/*3298*/            OPC_MoveChild, 1,
/*3300*/            OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*3303*/            OPC_MoveParent,
/*3304*/            OPC_SwitchType /*2 cases */, 57,  MVT::i32,// ->3364
/*3307*/              OPC_MoveParent,
/*3308*/              OPC_CheckChild2Same, 2,
/*3310*/              OPC_CheckPredicate, 5, // Predicate_unindexedstore
/*3312*/              OPC_CheckPredicate, 6, // Predicate_truncstore
/*3314*/              OPC_CheckPredicate, 7, // Predicate_truncstorei8
/*3316*/              OPC_Scope, 22, /*->3340*/ // 2 children in Scope
/*3318*/                OPC_CheckComplexPat, /*CP*/2, /*#*/2, // selectBDAddr12Pair:$addr #4 #5
/*3321*/                OPC_EmitMergeInputChains, 2, 0, 1, 
/*3325*/                OPC_EmitConvertToTarget, 3,
/*3327*/                OPC_EmitNodeXForm, 0, 6, // UIMM8
/*3330*/                OPC_MorphNodeTo, TARGET_VAL(SystemZ::NI), 0|OPFL_Chain|OPFL_MemRefs,
                            1/*#VTs*/, MVT::i32, 3/*#Ops*/, 4, 5, 7, 
                        // Src: (st (and:i32 (ld:i32 bdaddr12pair:i64:$addr)<<P:Predicate_unindexedload>><<P:Predicate_anyextload>><<P:Predicate_anyextloadi8>>, (imm:i32):$src), bdaddr12pair:i64:$addr)<<P:Predicate_unindexedstore>><<P:Predicate_truncstore>><<P:Predicate_truncstorei8>> - Complexity = 32
                        // Dst: (NI:i32 bdaddr12pair:i64:$addr, (UIMM8:i8 (imm:i32):$src))
/*3340*/              /*Scope*/ 22, /*->3363*/
/*3341*/                OPC_CheckComplexPat, /*CP*/3, /*#*/2, // selectBDAddr20Pair:$addr #4 #5
/*3344*/                OPC_EmitMergeInputChains, 2, 0, 1, 
/*3348*/                OPC_EmitConvertToTarget, 3,
/*3350*/                OPC_EmitNodeXForm, 0, 6, // UIMM8
/*3353*/                OPC_MorphNodeTo, TARGET_VAL(SystemZ::NIY), 0|OPFL_Chain|OPFL_MemRefs,
                            1/*#VTs*/, MVT::i32, 3/*#Ops*/, 4, 5, 7, 
                        // Src: (st (and:i32 (ld:i32 bdaddr20pair:i64:$addr)<<P:Predicate_unindexedload>><<P:Predicate_anyextload>><<P:Predicate_anyextloadi8>>, (imm:i32):$src), bdaddr20pair:i64:$addr)<<P:Predicate_unindexedstore>><<P:Predicate_truncstore>><<P:Predicate_truncstorei8>> - Complexity = 32
                        // Dst: (NIY:i32 bdaddr20pair:i64:$addr, (UIMM8:i8 (imm:i32):$src))
/*3363*/              0, /*End of Scope*/
/*3364*/            /*SwitchType*/ 57,  MVT::i64,// ->3423
/*3366*/              OPC_MoveParent,
/*3367*/              OPC_CheckChild2Same, 2,
/*3369*/              OPC_CheckPredicate, 5, // Predicate_unindexedstore
/*3371*/              OPC_CheckPredicate, 6, // Predicate_truncstore
/*3373*/              OPC_CheckPredicate, 7, // Predicate_truncstorei8
/*3375*/              OPC_Scope, 22, /*->3399*/ // 2 children in Scope
/*3377*/                OPC_CheckComplexPat, /*CP*/2, /*#*/2, // selectBDAddr12Pair:$addr #4 #5
/*3380*/                OPC_EmitMergeInputChains, 2, 0, 1, 
/*3384*/                OPC_EmitConvertToTarget, 3,
/*3386*/                OPC_EmitNodeXForm, 0, 6, // UIMM8
/*3389*/                OPC_MorphNodeTo, TARGET_VAL(SystemZ::NI), 0|OPFL_Chain|OPFL_MemRefs,
                            1/*#VTs*/, MVT::i32, 3/*#Ops*/, 4, 5, 7, 
                        // Src: (st (and:i64 (ld:i64 bdaddr12pair:i64:$addr)<<P:Predicate_unindexedload>><<P:Predicate_anyextload>><<P:Predicate_anyextloadi8>>, (imm:i64):$src), bdaddr12pair:i64:$addr)<<P:Predicate_unindexedstore>><<P:Predicate_truncstore>><<P:Predicate_truncstorei8>> - Complexity = 32
                        // Dst: (NI:i32 bdaddr12pair:i64:$addr, (UIMM8:i8 (imm:i64):$src))
/*3399*/              /*Scope*/ 22, /*->3422*/
/*3400*/                OPC_CheckComplexPat, /*CP*/3, /*#*/2, // selectBDAddr20Pair:$addr #4 #5
/*3403*/                OPC_EmitMergeInputChains, 2, 0, 1, 
/*3407*/                OPC_EmitConvertToTarget, 3,
/*3409*/                OPC_EmitNodeXForm, 0, 6, // UIMM8
/*3412*/                OPC_MorphNodeTo, TARGET_VAL(SystemZ::NIY), 0|OPFL_Chain|OPFL_MemRefs,
                            1/*#VTs*/, MVT::i32, 3/*#Ops*/, 4, 5, 7, 
                        // Src: (st (and:i64 (ld:i64 bdaddr20pair:i64:$addr)<<P:Predicate_unindexedload>><<P:Predicate_anyextload>><<P:Predicate_anyextloadi8>>, (imm:i64):$src), bdaddr20pair:i64:$addr)<<P:Predicate_unindexedstore>><<P:Predicate_truncstore>><<P:Predicate_truncstorei8>> - Complexity = 32
                        // Dst: (NIY:i32 bdaddr20pair:i64:$addr, (UIMM8:i8 (imm:i64):$src))
/*3422*/              0, /*End of Scope*/
/*3423*/            0, // EndSwitchType
/*3424*/          0, /*End of Scope*/
/*3425*/        0, /*End of Scope*/
/*3426*/      /*SwitchOpcode*/ 126|128,12/*1662*/,  TARGET_VAL(ISD::OR),// ->5092
/*3430*/        OPC_MoveChild, 0,
/*3432*/        OPC_CheckOpcode, TARGET_VAL(ISD::LOAD),
/*3435*/        OPC_RecordMemRef,
/*3436*/        OPC_RecordNode, // #1 = 'ld' chained node
/*3437*/        OPC_CheckFoldableChainNode,
/*3438*/        OPC_RecordChild1, // #2 = $src
/*3439*/        OPC_CheckChild1Type, MVT::i64,
/*3441*/        OPC_CheckPredicate, 0, // Predicate_unindexedload
/*3443*/        OPC_Scope, 54, /*->3499*/ // 28 children in Scope
/*3445*/          OPC_CheckPredicate, 1, // Predicate_anyextload
/*3447*/          OPC_CheckPredicate, 2, // Predicate_anyextloadi8
/*3449*/          OPC_MoveParent,
/*3450*/          OPC_MoveChild, 1,
/*3452*/          OPC_CheckOpcode, TARGET_VAL(ISD::LOAD),
/*3455*/          OPC_RecordMemRef,
/*3456*/          OPC_RecordNode, // #3 = 'ld' chained node
/*3457*/          OPC_CheckFoldableChainNode,
/*3458*/          OPC_RecordChild1, // #4 = $dest
/*3459*/          OPC_CheckChild1Type, MVT::i64,
/*3461*/          OPC_CheckPredicate, 0, // Predicate_unindexedload
/*3463*/          OPC_MoveParent,
/*3464*/          OPC_CheckType, MVT::i32,
/*3466*/          OPC_MoveParent,
/*3467*/          OPC_CheckChild2Same, 4,
/*3469*/          OPC_CheckPredicate, 5, // Predicate_unindexedstore
/*3471*/          OPC_CheckPredicate, 23, // Predicate_block_or1
/*3473*/          OPC_CheckComplexPat, /*CP*/1, /*#*/2, // selectBDAddr12Only:$src #5 #6
/*3476*/          OPC_CheckComplexPat, /*CP*/1, /*#*/4, // selectBDAddr12Only:$dest #7 #8
/*3479*/          OPC_EmitMergeInputChains, 3, 0, 1, 3, 
/*3484*/          OPC_EmitInteger, MVT::i64, 1, 
/*3487*/          OPC_MorphNodeTo, TARGET_VAL(SystemZ::OCSequence), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i32, 5/*#Ops*/, 7, 8, 5, 6, 9, 
                  // Src: (st (or:i32 (ld:i32 bdaddr12only:i64:$src)<<P:Predicate_unindexedload>><<P:Predicate_anyextload>><<P:Predicate_anyextloadi8>>, (ld:i32 bdaddr12only:i64:$dest)<<P:Predicate_unindexedload>>), bdaddr12only:i64:$dest)<<P:Predicate_unindexedstore>><<P:Predicate_block_or1>> - Complexity = 42
                  // Dst: (OCSequence:i32 bdaddr12only:i64:$dest, bdaddr12only:i64:$src, 1:i64)
/*3499*/        /*Scope*/ 54, /*->3554*/
/*3500*/          OPC_MoveParent,
/*3501*/          OPC_MoveChild, 1,
/*3503*/          OPC_CheckOpcode, TARGET_VAL(ISD::LOAD),
/*3506*/          OPC_RecordMemRef,
/*3507*/          OPC_RecordNode, // #3 = 'ld' chained node
/*3508*/          OPC_CheckFoldableChainNode,
/*3509*/          OPC_RecordChild1, // #4 = $src
/*3510*/          OPC_CheckChild1Type, MVT::i64,
/*3512*/          OPC_CheckPredicate, 0, // Predicate_unindexedload
/*3514*/          OPC_CheckPredicate, 1, // Predicate_anyextload
/*3516*/          OPC_CheckPredicate, 2, // Predicate_anyextloadi8
/*3518*/          OPC_MoveParent,
/*3519*/          OPC_CheckType, MVT::i32,
/*3521*/          OPC_MoveParent,
/*3522*/          OPC_CheckChild2Same, 2,
/*3524*/          OPC_CheckPredicate, 5, // Predicate_unindexedstore
/*3526*/          OPC_CheckPredicate, 24, // Predicate_block_or2
/*3528*/          OPC_CheckComplexPat, /*CP*/1, /*#*/2, // selectBDAddr12Only:$dest #5 #6
/*3531*/          OPC_CheckComplexPat, /*CP*/1, /*#*/4, // selectBDAddr12Only:$src #7 #8
/*3534*/          OPC_EmitMergeInputChains, 3, 0, 1, 3, 
/*3539*/          OPC_EmitInteger, MVT::i64, 1, 
/*3542*/          OPC_MorphNodeTo, TARGET_VAL(SystemZ::OCSequence), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i32, 5/*#Ops*/, 5, 6, 7, 8, 9, 
                  // Src: (st (or:i32 (ld:i32 bdaddr12only:i64:$dest)<<P:Predicate_unindexedload>>, (ld:i32 bdaddr12only:i64:$src)<<P:Predicate_unindexedload>><<P:Predicate_anyextload>><<P:Predicate_anyextloadi8>>), bdaddr12only:i64:$dest)<<P:Predicate_unindexedstore>><<P:Predicate_block_or2>> - Complexity = 42
                  // Dst: (OCSequence:i32 bdaddr12only:i64:$dest, bdaddr12only:i64:$src, 1:i64)
/*3554*/        /*Scope*/ 54, /*->3609*/
/*3555*/          OPC_CheckPredicate, 1, // Predicate_anyextload
/*3557*/          OPC_CheckPredicate, 9, // Predicate_anyextloadi16
/*3559*/          OPC_MoveParent,
/*3560*/          OPC_MoveChild, 1,
/*3562*/          OPC_CheckOpcode, TARGET_VAL(ISD::LOAD),
/*3565*/          OPC_RecordMemRef,
/*3566*/          OPC_RecordNode, // #3 = 'ld' chained node
/*3567*/          OPC_CheckFoldableChainNode,
/*3568*/          OPC_RecordChild1, // #4 = $dest
/*3569*/          OPC_CheckChild1Type, MVT::i64,
/*3571*/          OPC_CheckPredicate, 0, // Predicate_unindexedload
/*3573*/          OPC_MoveParent,
/*3574*/          OPC_CheckType, MVT::i32,
/*3576*/          OPC_MoveParent,
/*3577*/          OPC_CheckChild2Same, 4,
/*3579*/          OPC_CheckPredicate, 5, // Predicate_unindexedstore
/*3581*/          OPC_CheckPredicate, 23, // Predicate_block_or1
/*3583*/          OPC_CheckComplexPat, /*CP*/1, /*#*/2, // selectBDAddr12Only:$src #5 #6
/*3586*/          OPC_CheckComplexPat, /*CP*/1, /*#*/4, // selectBDAddr12Only:$dest #7 #8
/*3589*/          OPC_EmitMergeInputChains, 3, 0, 1, 3, 
/*3594*/          OPC_EmitInteger, MVT::i64, 2, 
/*3597*/          OPC_MorphNodeTo, TARGET_VAL(SystemZ::OCSequence), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i32, 5/*#Ops*/, 7, 8, 5, 6, 9, 
                  // Src: (st (or:i32 (ld:i32 bdaddr12only:i64:$src)<<P:Predicate_unindexedload>><<P:Predicate_anyextload>><<P:Predicate_anyextloadi16>>, (ld:i32 bdaddr12only:i64:$dest)<<P:Predicate_unindexedload>>), bdaddr12only:i64:$dest)<<P:Predicate_unindexedstore>><<P:Predicate_block_or1>> - Complexity = 42
                  // Dst: (OCSequence:i32 bdaddr12only:i64:$dest, bdaddr12only:i64:$src, 2:i64)
/*3609*/        /*Scope*/ 54, /*->3664*/
/*3610*/          OPC_MoveParent,
/*3611*/          OPC_MoveChild, 1,
/*3613*/          OPC_CheckOpcode, TARGET_VAL(ISD::LOAD),
/*3616*/          OPC_RecordMemRef,
/*3617*/          OPC_RecordNode, // #3 = 'ld' chained node
/*3618*/          OPC_CheckFoldableChainNode,
/*3619*/          OPC_RecordChild1, // #4 = $src
/*3620*/          OPC_CheckChild1Type, MVT::i64,
/*3622*/          OPC_CheckPredicate, 0, // Predicate_unindexedload
/*3624*/          OPC_CheckPredicate, 1, // Predicate_anyextload
/*3626*/          OPC_CheckPredicate, 9, // Predicate_anyextloadi16
/*3628*/          OPC_MoveParent,
/*3629*/          OPC_CheckType, MVT::i32,
/*3631*/          OPC_MoveParent,
/*3632*/          OPC_CheckChild2Same, 2,
/*3634*/          OPC_CheckPredicate, 5, // Predicate_unindexedstore
/*3636*/          OPC_CheckPredicate, 24, // Predicate_block_or2
/*3638*/          OPC_CheckComplexPat, /*CP*/1, /*#*/2, // selectBDAddr12Only:$dest #5 #6
/*3641*/          OPC_CheckComplexPat, /*CP*/1, /*#*/4, // selectBDAddr12Only:$src #7 #8
/*3644*/          OPC_EmitMergeInputChains, 3, 0, 1, 3, 
/*3649*/          OPC_EmitInteger, MVT::i64, 2, 
/*3652*/          OPC_MorphNodeTo, TARGET_VAL(SystemZ::OCSequence), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i32, 5/*#Ops*/, 5, 6, 7, 8, 9, 
                  // Src: (st (or:i32 (ld:i32 bdaddr12only:i64:$dest)<<P:Predicate_unindexedload>>, (ld:i32 bdaddr12only:i64:$src)<<P:Predicate_unindexedload>><<P:Predicate_anyextload>><<P:Predicate_anyextloadi16>>), bdaddr12only:i64:$dest)<<P:Predicate_unindexedstore>><<P:Predicate_block_or2>> - Complexity = 42
                  // Dst: (OCSequence:i32 bdaddr12only:i64:$dest, bdaddr12only:i64:$src, 2:i64)
/*3664*/        /*Scope*/ 52, /*->3717*/
/*3665*/          OPC_CheckPredicate, 13, // Predicate_load
/*3667*/          OPC_MoveParent,
/*3668*/          OPC_MoveChild, 1,
/*3670*/          OPC_CheckOpcode, TARGET_VAL(ISD::LOAD),
/*3673*/          OPC_RecordMemRef,
/*3674*/          OPC_RecordNode, // #3 = 'ld' chained node
/*3675*/          OPC_CheckFoldableChainNode,
/*3676*/          OPC_RecordChild1, // #4 = $dest
/*3677*/          OPC_CheckChild1Type, MVT::i64,
/*3679*/          OPC_CheckPredicate, 0, // Predicate_unindexedload
/*3681*/          OPC_MoveParent,
/*3682*/          OPC_CheckType, MVT::i32,
/*3684*/          OPC_MoveParent,
/*3685*/          OPC_CheckChild2Same, 4,
/*3687*/          OPC_CheckPredicate, 5, // Predicate_unindexedstore
/*3689*/          OPC_CheckPredicate, 23, // Predicate_block_or1
/*3691*/          OPC_CheckComplexPat, /*CP*/1, /*#*/2, // selectBDAddr12Only:$src #5 #6
/*3694*/          OPC_CheckComplexPat, /*CP*/1, /*#*/4, // selectBDAddr12Only:$dest #7 #8
/*3697*/          OPC_EmitMergeInputChains, 3, 0, 1, 3, 
/*3702*/          OPC_EmitInteger, MVT::i64, 4, 
/*3705*/          OPC_MorphNodeTo, TARGET_VAL(SystemZ::OCSequence), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i32, 5/*#Ops*/, 7, 8, 5, 6, 9, 
                  // Src: (st (or:i32 (ld:i32 bdaddr12only:i64:$src)<<P:Predicate_unindexedload>><<P:Predicate_load>>, (ld:i32 bdaddr12only:i64:$dest)<<P:Predicate_unindexedload>>), bdaddr12only:i64:$dest)<<P:Predicate_unindexedstore>><<P:Predicate_block_or1>> - Complexity = 42
                  // Dst: (OCSequence:i32 bdaddr12only:i64:$dest, bdaddr12only:i64:$src, 4:i64)
/*3717*/        /*Scope*/ 52, /*->3770*/
/*3718*/          OPC_MoveParent,
/*3719*/          OPC_MoveChild, 1,
/*3721*/          OPC_CheckOpcode, TARGET_VAL(ISD::LOAD),
/*3724*/          OPC_RecordMemRef,
/*3725*/          OPC_RecordNode, // #3 = 'ld' chained node
/*3726*/          OPC_CheckFoldableChainNode,
/*3727*/          OPC_RecordChild1, // #4 = $src
/*3728*/          OPC_CheckChild1Type, MVT::i64,
/*3730*/          OPC_CheckPredicate, 0, // Predicate_unindexedload
/*3732*/          OPC_CheckPredicate, 13, // Predicate_load
/*3734*/          OPC_MoveParent,
/*3735*/          OPC_CheckType, MVT::i32,
/*3737*/          OPC_MoveParent,
/*3738*/          OPC_CheckChild2Same, 2,
/*3740*/          OPC_CheckPredicate, 5, // Predicate_unindexedstore
/*3742*/          OPC_CheckPredicate, 24, // Predicate_block_or2
/*3744*/          OPC_CheckComplexPat, /*CP*/1, /*#*/2, // selectBDAddr12Only:$dest #5 #6
/*3747*/          OPC_CheckComplexPat, /*CP*/1, /*#*/4, // selectBDAddr12Only:$src #7 #8
/*3750*/          OPC_EmitMergeInputChains, 3, 0, 1, 3, 
/*3755*/          OPC_EmitInteger, MVT::i64, 4, 
/*3758*/          OPC_MorphNodeTo, TARGET_VAL(SystemZ::OCSequence), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i32, 5/*#Ops*/, 5, 6, 7, 8, 9, 
                  // Src: (st (or:i32 (ld:i32 bdaddr12only:i64:$dest)<<P:Predicate_unindexedload>>, (ld:i32 bdaddr12only:i64:$src)<<P:Predicate_unindexedload>><<P:Predicate_load>>), bdaddr12only:i64:$dest)<<P:Predicate_unindexedstore>><<P:Predicate_block_or2>> - Complexity = 42
                  // Dst: (OCSequence:i32 bdaddr12only:i64:$dest, bdaddr12only:i64:$src, 4:i64)
/*3770*/        /*Scope*/ 54, /*->3825*/
/*3771*/          OPC_CheckPredicate, 1, // Predicate_anyextload
/*3773*/          OPC_CheckPredicate, 2, // Predicate_anyextloadi8
/*3775*/          OPC_MoveParent,
/*3776*/          OPC_MoveChild, 1,
/*3778*/          OPC_CheckOpcode, TARGET_VAL(ISD::LOAD),
/*3781*/          OPC_RecordMemRef,
/*3782*/          OPC_RecordNode, // #3 = 'ld' chained node
/*3783*/          OPC_CheckFoldableChainNode,
/*3784*/          OPC_RecordChild1, // #4 = $dest
/*3785*/          OPC_CheckChild1Type, MVT::i64,
/*3787*/          OPC_CheckPredicate, 0, // Predicate_unindexedload
/*3789*/          OPC_MoveParent,
/*3790*/          OPC_CheckType, MVT::i64,
/*3792*/          OPC_MoveParent,
/*3793*/          OPC_CheckChild2Same, 4,
/*3795*/          OPC_CheckPredicate, 5, // Predicate_unindexedstore
/*3797*/          OPC_CheckPredicate, 23, // Predicate_block_or1
/*3799*/          OPC_CheckComplexPat, /*CP*/1, /*#*/2, // selectBDAddr12Only:$src #5 #6
/*3802*/          OPC_CheckComplexPat, /*CP*/1, /*#*/4, // selectBDAddr12Only:$dest #7 #8
/*3805*/          OPC_EmitMergeInputChains, 3, 0, 1, 3, 
/*3810*/          OPC_EmitInteger, MVT::i64, 1, 
/*3813*/          OPC_MorphNodeTo, TARGET_VAL(SystemZ::OCSequence), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i32, 5/*#Ops*/, 7, 8, 5, 6, 9, 
                  // Src: (st (or:i64 (ld:i64 bdaddr12only:i64:$src)<<P:Predicate_unindexedload>><<P:Predicate_anyextload>><<P:Predicate_anyextloadi8>>, (ld:i64 bdaddr12only:i64:$dest)<<P:Predicate_unindexedload>>), bdaddr12only:i64:$dest)<<P:Predicate_unindexedstore>><<P:Predicate_block_or1>> - Complexity = 42
                  // Dst: (OCSequence:i32 bdaddr12only:i64:$dest, bdaddr12only:i64:$src, 1:i64)
/*3825*/        /*Scope*/ 54, /*->3880*/
/*3826*/          OPC_MoveParent,
/*3827*/          OPC_MoveChild, 1,
/*3829*/          OPC_CheckOpcode, TARGET_VAL(ISD::LOAD),
/*3832*/          OPC_RecordMemRef,
/*3833*/          OPC_RecordNode, // #3 = 'ld' chained node
/*3834*/          OPC_CheckFoldableChainNode,
/*3835*/          OPC_RecordChild1, // #4 = $src
/*3836*/          OPC_CheckChild1Type, MVT::i64,
/*3838*/          OPC_CheckPredicate, 0, // Predicate_unindexedload
/*3840*/          OPC_CheckPredicate, 1, // Predicate_anyextload
/*3842*/          OPC_CheckPredicate, 2, // Predicate_anyextloadi8
/*3844*/          OPC_MoveParent,
/*3845*/          OPC_CheckType, MVT::i64,
/*3847*/          OPC_MoveParent,
/*3848*/          OPC_CheckChild2Same, 2,
/*3850*/          OPC_CheckPredicate, 5, // Predicate_unindexedstore
/*3852*/          OPC_CheckPredicate, 24, // Predicate_block_or2
/*3854*/          OPC_CheckComplexPat, /*CP*/1, /*#*/2, // selectBDAddr12Only:$dest #5 #6
/*3857*/          OPC_CheckComplexPat, /*CP*/1, /*#*/4, // selectBDAddr12Only:$src #7 #8
/*3860*/          OPC_EmitMergeInputChains, 3, 0, 1, 3, 
/*3865*/          OPC_EmitInteger, MVT::i64, 1, 
/*3868*/          OPC_MorphNodeTo, TARGET_VAL(SystemZ::OCSequence), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i32, 5/*#Ops*/, 5, 6, 7, 8, 9, 
                  // Src: (st (or:i64 (ld:i64 bdaddr12only:i64:$dest)<<P:Predicate_unindexedload>>, (ld:i64 bdaddr12only:i64:$src)<<P:Predicate_unindexedload>><<P:Predicate_anyextload>><<P:Predicate_anyextloadi8>>), bdaddr12only:i64:$dest)<<P:Predicate_unindexedstore>><<P:Predicate_block_or2>> - Complexity = 42
                  // Dst: (OCSequence:i32 bdaddr12only:i64:$dest, bdaddr12only:i64:$src, 1:i64)
/*3880*/        /*Scope*/ 54, /*->3935*/
/*3881*/          OPC_CheckPredicate, 1, // Predicate_anyextload
/*3883*/          OPC_CheckPredicate, 9, // Predicate_anyextloadi16
/*3885*/          OPC_MoveParent,
/*3886*/          OPC_MoveChild, 1,
/*3888*/          OPC_CheckOpcode, TARGET_VAL(ISD::LOAD),
/*3891*/          OPC_RecordMemRef,
/*3892*/          OPC_RecordNode, // #3 = 'ld' chained node
/*3893*/          OPC_CheckFoldableChainNode,
/*3894*/          OPC_RecordChild1, // #4 = $dest
/*3895*/          OPC_CheckChild1Type, MVT::i64,
/*3897*/          OPC_CheckPredicate, 0, // Predicate_unindexedload
/*3899*/          OPC_MoveParent,
/*3900*/          OPC_CheckType, MVT::i64,
/*3902*/          OPC_MoveParent,
/*3903*/          OPC_CheckChild2Same, 4,
/*3905*/          OPC_CheckPredicate, 5, // Predicate_unindexedstore
/*3907*/          OPC_CheckPredicate, 23, // Predicate_block_or1
/*3909*/          OPC_CheckComplexPat, /*CP*/1, /*#*/2, // selectBDAddr12Only:$src #5 #6
/*3912*/          OPC_CheckComplexPat, /*CP*/1, /*#*/4, // selectBDAddr12Only:$dest #7 #8
/*3915*/          OPC_EmitMergeInputChains, 3, 0, 1, 3, 
/*3920*/          OPC_EmitInteger, MVT::i64, 2, 
/*3923*/          OPC_MorphNodeTo, TARGET_VAL(SystemZ::OCSequence), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i32, 5/*#Ops*/, 7, 8, 5, 6, 9, 
                  // Src: (st (or:i64 (ld:i64 bdaddr12only:i64:$src)<<P:Predicate_unindexedload>><<P:Predicate_anyextload>><<P:Predicate_anyextloadi16>>, (ld:i64 bdaddr12only:i64:$dest)<<P:Predicate_unindexedload>>), bdaddr12only:i64:$dest)<<P:Predicate_unindexedstore>><<P:Predicate_block_or1>> - Complexity = 42
                  // Dst: (OCSequence:i32 bdaddr12only:i64:$dest, bdaddr12only:i64:$src, 2:i64)
/*3935*/        /*Scope*/ 54, /*->3990*/
/*3936*/          OPC_MoveParent,
/*3937*/          OPC_MoveChild, 1,
/*3939*/          OPC_CheckOpcode, TARGET_VAL(ISD::LOAD),
/*3942*/          OPC_RecordMemRef,
/*3943*/          OPC_RecordNode, // #3 = 'ld' chained node
/*3944*/          OPC_CheckFoldableChainNode,
/*3945*/          OPC_RecordChild1, // #4 = $src
/*3946*/          OPC_CheckChild1Type, MVT::i64,
/*3948*/          OPC_CheckPredicate, 0, // Predicate_unindexedload
/*3950*/          OPC_CheckPredicate, 1, // Predicate_anyextload
/*3952*/          OPC_CheckPredicate, 9, // Predicate_anyextloadi16
/*3954*/          OPC_MoveParent,
/*3955*/          OPC_CheckType, MVT::i64,
/*3957*/          OPC_MoveParent,
/*3958*/          OPC_CheckChild2Same, 2,
/*3960*/          OPC_CheckPredicate, 5, // Predicate_unindexedstore
/*3962*/          OPC_CheckPredicate, 24, // Predicate_block_or2
/*3964*/          OPC_CheckComplexPat, /*CP*/1, /*#*/2, // selectBDAddr12Only:$dest #5 #6
/*3967*/          OPC_CheckComplexPat, /*CP*/1, /*#*/4, // selectBDAddr12Only:$src #7 #8
/*3970*/          OPC_EmitMergeInputChains, 3, 0, 1, 3, 
/*3975*/          OPC_EmitInteger, MVT::i64, 2, 
/*3978*/          OPC_MorphNodeTo, TARGET_VAL(SystemZ::OCSequence), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i32, 5/*#Ops*/, 5, 6, 7, 8, 9, 
                  // Src: (st (or:i64 (ld:i64 bdaddr12only:i64:$dest)<<P:Predicate_unindexedload>>, (ld:i64 bdaddr12only:i64:$src)<<P:Predicate_unindexedload>><<P:Predicate_anyextload>><<P:Predicate_anyextloadi16>>), bdaddr12only:i64:$dest)<<P:Predicate_unindexedstore>><<P:Predicate_block_or2>> - Complexity = 42
                  // Dst: (OCSequence:i32 bdaddr12only:i64:$dest, bdaddr12only:i64:$src, 2:i64)
/*3990*/        /*Scope*/ 54, /*->4045*/
/*3991*/          OPC_CheckPredicate, 1, // Predicate_anyextload
/*3993*/          OPC_CheckPredicate, 17, // Predicate_anyextloadi32
/*3995*/          OPC_MoveParent,
/*3996*/          OPC_MoveChild, 1,
/*3998*/          OPC_CheckOpcode, TARGET_VAL(ISD::LOAD),
/*4001*/          OPC_RecordMemRef,
/*4002*/          OPC_RecordNode, // #3 = 'ld' chained node
/*4003*/          OPC_CheckFoldableChainNode,
/*4004*/          OPC_RecordChild1, // #4 = $dest
/*4005*/          OPC_CheckChild1Type, MVT::i64,
/*4007*/          OPC_CheckPredicate, 0, // Predicate_unindexedload
/*4009*/          OPC_MoveParent,
/*4010*/          OPC_CheckType, MVT::i64,
/*4012*/          OPC_MoveParent,
/*4013*/          OPC_CheckChild2Same, 4,
/*4015*/          OPC_CheckPredicate, 5, // Predicate_unindexedstore
/*4017*/          OPC_CheckPredicate, 23, // Predicate_block_or1
/*4019*/          OPC_CheckComplexPat, /*CP*/1, /*#*/2, // selectBDAddr12Only:$src #5 #6
/*4022*/          OPC_CheckComplexPat, /*CP*/1, /*#*/4, // selectBDAddr12Only:$dest #7 #8
/*4025*/          OPC_EmitMergeInputChains, 3, 0, 1, 3, 
/*4030*/          OPC_EmitInteger, MVT::i64, 4, 
/*4033*/          OPC_MorphNodeTo, TARGET_VAL(SystemZ::OCSequence), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i32, 5/*#Ops*/, 7, 8, 5, 6, 9, 
                  // Src: (st (or:i64 (ld:i64 bdaddr12only:i64:$src)<<P:Predicate_unindexedload>><<P:Predicate_anyextload>><<P:Predicate_anyextloadi32>>, (ld:i64 bdaddr12only:i64:$dest)<<P:Predicate_unindexedload>>), bdaddr12only:i64:$dest)<<P:Predicate_unindexedstore>><<P:Predicate_block_or1>> - Complexity = 42
                  // Dst: (OCSequence:i32 bdaddr12only:i64:$dest, bdaddr12only:i64:$src, 4:i64)
/*4045*/        /*Scope*/ 54, /*->4100*/
/*4046*/          OPC_MoveParent,
/*4047*/          OPC_MoveChild, 1,
/*4049*/          OPC_CheckOpcode, TARGET_VAL(ISD::LOAD),
/*4052*/          OPC_RecordMemRef,
/*4053*/          OPC_RecordNode, // #3 = 'ld' chained node
/*4054*/          OPC_CheckFoldableChainNode,
/*4055*/          OPC_RecordChild1, // #4 = $src
/*4056*/          OPC_CheckChild1Type, MVT::i64,
/*4058*/          OPC_CheckPredicate, 0, // Predicate_unindexedload
/*4060*/          OPC_CheckPredicate, 1, // Predicate_anyextload
/*4062*/          OPC_CheckPredicate, 17, // Predicate_anyextloadi32
/*4064*/          OPC_MoveParent,
/*4065*/          OPC_CheckType, MVT::i64,
/*4067*/          OPC_MoveParent,
/*4068*/          OPC_CheckChild2Same, 2,
/*4070*/          OPC_CheckPredicate, 5, // Predicate_unindexedstore
/*4072*/          OPC_CheckPredicate, 24, // Predicate_block_or2
/*4074*/          OPC_CheckComplexPat, /*CP*/1, /*#*/2, // selectBDAddr12Only:$dest #5 #6
/*4077*/          OPC_CheckComplexPat, /*CP*/1, /*#*/4, // selectBDAddr12Only:$src #7 #8
/*4080*/          OPC_EmitMergeInputChains, 3, 0, 1, 3, 
/*4085*/          OPC_EmitInteger, MVT::i64, 4, 
/*4088*/          OPC_MorphNodeTo, TARGET_VAL(SystemZ::OCSequence), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i32, 5/*#Ops*/, 5, 6, 7, 8, 9, 
                  // Src: (st (or:i64 (ld:i64 bdaddr12only:i64:$dest)<<P:Predicate_unindexedload>>, (ld:i64 bdaddr12only:i64:$src)<<P:Predicate_unindexedload>><<P:Predicate_anyextload>><<P:Predicate_anyextloadi32>>), bdaddr12only:i64:$dest)<<P:Predicate_unindexedstore>><<P:Predicate_block_or2>> - Complexity = 42
                  // Dst: (OCSequence:i32 bdaddr12only:i64:$dest, bdaddr12only:i64:$src, 4:i64)
/*4100*/        /*Scope*/ 52, /*->4153*/
/*4101*/          OPC_CheckPredicate, 13, // Predicate_load
/*4103*/          OPC_MoveParent,
/*4104*/          OPC_MoveChild, 1,
/*4106*/          OPC_CheckOpcode, TARGET_VAL(ISD::LOAD),
/*4109*/          OPC_RecordMemRef,
/*4110*/          OPC_RecordNode, // #3 = 'ld' chained node
/*4111*/          OPC_CheckFoldableChainNode,
/*4112*/          OPC_RecordChild1, // #4 = $dest
/*4113*/          OPC_CheckChild1Type, MVT::i64,
/*4115*/          OPC_CheckPredicate, 0, // Predicate_unindexedload
/*4117*/          OPC_MoveParent,
/*4118*/          OPC_CheckType, MVT::i64,
/*4120*/          OPC_MoveParent,
/*4121*/          OPC_CheckChild2Same, 4,
/*4123*/          OPC_CheckPredicate, 5, // Predicate_unindexedstore
/*4125*/          OPC_CheckPredicate, 23, // Predicate_block_or1
/*4127*/          OPC_CheckComplexPat, /*CP*/1, /*#*/2, // selectBDAddr12Only:$src #5 #6
/*4130*/          OPC_CheckComplexPat, /*CP*/1, /*#*/4, // selectBDAddr12Only:$dest #7 #8
/*4133*/          OPC_EmitMergeInputChains, 3, 0, 1, 3, 
/*4138*/          OPC_EmitInteger, MVT::i64, 8, 
/*4141*/          OPC_MorphNodeTo, TARGET_VAL(SystemZ::OCSequence), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i32, 5/*#Ops*/, 7, 8, 5, 6, 9, 
                  // Src: (st (or:i64 (ld:i64 bdaddr12only:i64:$src)<<P:Predicate_unindexedload>><<P:Predicate_load>>, (ld:i64 bdaddr12only:i64:$dest)<<P:Predicate_unindexedload>>), bdaddr12only:i64:$dest)<<P:Predicate_unindexedstore>><<P:Predicate_block_or1>> - Complexity = 42
                  // Dst: (OCSequence:i32 bdaddr12only:i64:$dest, bdaddr12only:i64:$src, 8:i64)
/*4153*/        /*Scope*/ 96, /*->4250*/
/*4154*/          OPC_MoveParent,
/*4155*/          OPC_MoveChild, 1,
/*4157*/          OPC_CheckOpcode, TARGET_VAL(ISD::LOAD),
/*4160*/          OPC_RecordMemRef,
/*4161*/          OPC_RecordNode, // #3 = 'ld' chained node
/*4162*/          OPC_CheckFoldableChainNode,
/*4163*/          OPC_RecordChild1, // #4 = $src
/*4164*/          OPC_CheckChild1Type, MVT::i64,
/*4166*/          OPC_CheckPredicate, 0, // Predicate_unindexedload
/*4168*/          OPC_Scope, 38, /*->4208*/ // 2 children in Scope
/*4170*/            OPC_CheckPredicate, 13, // Predicate_load
/*4172*/            OPC_MoveParent,
/*4173*/            OPC_CheckType, MVT::i64,
/*4175*/            OPC_MoveParent,
/*4176*/            OPC_CheckChild2Same, 2,
/*4178*/            OPC_CheckPredicate, 5, // Predicate_unindexedstore
/*4180*/            OPC_CheckPredicate, 24, // Predicate_block_or2
/*4182*/            OPC_CheckComplexPat, /*CP*/1, /*#*/2, // selectBDAddr12Only:$dest #5 #6
/*4185*/            OPC_CheckComplexPat, /*CP*/1, /*#*/4, // selectBDAddr12Only:$src #7 #8
/*4188*/            OPC_EmitMergeInputChains, 3, 0, 1, 3, 
/*4193*/            OPC_EmitInteger, MVT::i64, 8, 
/*4196*/            OPC_MorphNodeTo, TARGET_VAL(SystemZ::OCSequence), 0|OPFL_Chain|OPFL_MemRefs,
                        1/*#VTs*/, MVT::i32, 5/*#Ops*/, 5, 6, 7, 8, 9, 
                    // Src: (st (or:i64 (ld:i64 bdaddr12only:i64:$dest)<<P:Predicate_unindexedload>>, (ld:i64 bdaddr12only:i64:$src)<<P:Predicate_unindexedload>><<P:Predicate_load>>), bdaddr12only:i64:$dest)<<P:Predicate_unindexedstore>><<P:Predicate_block_or2>> - Complexity = 42
                    // Dst: (OCSequence:i32 bdaddr12only:i64:$dest, bdaddr12only:i64:$src, 8:i64)
/*4208*/          /*Scope*/ 40, /*->4249*/
/*4209*/            OPC_CheckPredicate, 1, // Predicate_anyextload
/*4211*/            OPC_CheckPredicate, 2, // Predicate_anyextloadi8
/*4213*/            OPC_MoveParent,
/*4214*/            OPC_CheckType, MVT::i32,
/*4216*/            OPC_MoveParent,
/*4217*/            OPC_CheckChild2Same, 2,
/*4219*/            OPC_CheckPredicate, 5, // Predicate_unindexedstore
/*4221*/            OPC_CheckPredicate, 23, // Predicate_block_or1
/*4223*/            OPC_CheckComplexPat, /*CP*/1, /*#*/2, // selectBDAddr12Only:$dest #5 #6
/*4226*/            OPC_CheckComplexPat, /*CP*/1, /*#*/4, // selectBDAddr12Only:$src #7 #8
/*4229*/            OPC_EmitMergeInputChains, 3, 0, 1, 3, 
/*4234*/            OPC_EmitInteger, MVT::i64, 1, 
/*4237*/            OPC_MorphNodeTo, TARGET_VAL(SystemZ::OCSequence), 0|OPFL_Chain|OPFL_MemRefs,
                        1/*#VTs*/, MVT::i32, 5/*#Ops*/, 5, 6, 7, 8, 9, 
                    // Src: (st (or:i32 (ld:i32 bdaddr12only:i64:$dest)<<P:Predicate_unindexedload>>, (ld:i32 bdaddr12only:i64:$src)<<P:Predicate_unindexedload>><<P:Predicate_anyextload>><<P:Predicate_anyextloadi8>>), bdaddr12only:i64:$dest)<<P:Predicate_unindexedstore>><<P:Predicate_block_or1>> - Complexity = 42
                    // Dst: (OCSequence:i32 bdaddr12only:i64:$dest, bdaddr12only:i64:$src, 1:i64)
/*4249*/          0, /*End of Scope*/
/*4250*/        /*Scope*/ 54, /*->4305*/
/*4251*/          OPC_CheckPredicate, 1, // Predicate_anyextload
/*4253*/          OPC_CheckPredicate, 2, // Predicate_anyextloadi8
/*4255*/          OPC_MoveParent,
/*4256*/          OPC_MoveChild, 1,
/*4258*/          OPC_CheckOpcode, TARGET_VAL(ISD::LOAD),
/*4261*/          OPC_RecordMemRef,
/*4262*/          OPC_RecordNode, // #3 = 'ld' chained node
/*4263*/          OPC_CheckFoldableChainNode,
/*4264*/          OPC_RecordChild1, // #4 = $dest
/*4265*/          OPC_CheckChild1Type, MVT::i64,
/*4267*/          OPC_CheckPredicate, 0, // Predicate_unindexedload
/*4269*/          OPC_MoveParent,
/*4270*/          OPC_CheckType, MVT::i32,
/*4272*/          OPC_MoveParent,
/*4273*/          OPC_CheckChild2Same, 4,
/*4275*/          OPC_CheckPredicate, 5, // Predicate_unindexedstore
/*4277*/          OPC_CheckPredicate, 24, // Predicate_block_or2
/*4279*/          OPC_CheckComplexPat, /*CP*/1, /*#*/2, // selectBDAddr12Only:$src #5 #6
/*4282*/          OPC_CheckComplexPat, /*CP*/1, /*#*/4, // selectBDAddr12Only:$dest #7 #8
/*4285*/          OPC_EmitMergeInputChains, 3, 0, 1, 3, 
/*4290*/          OPC_EmitInteger, MVT::i64, 1, 
/*4293*/          OPC_MorphNodeTo, TARGET_VAL(SystemZ::OCSequence), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i32, 5/*#Ops*/, 7, 8, 5, 6, 9, 
                  // Src: (st (or:i32 (ld:i32 bdaddr12only:i64:$src)<<P:Predicate_unindexedload>><<P:Predicate_anyextload>><<P:Predicate_anyextloadi8>>, (ld:i32 bdaddr12only:i64:$dest)<<P:Predicate_unindexedload>>), bdaddr12only:i64:$dest)<<P:Predicate_unindexedstore>><<P:Predicate_block_or2>> - Complexity = 42
                  // Dst: (OCSequence:i32 bdaddr12only:i64:$dest, bdaddr12only:i64:$src, 1:i64)
/*4305*/        /*Scope*/ 54, /*->4360*/
/*4306*/          OPC_MoveParent,
/*4307*/          OPC_MoveChild, 1,
/*4309*/          OPC_CheckOpcode, TARGET_VAL(ISD::LOAD),
/*4312*/          OPC_RecordMemRef,
/*4313*/          OPC_RecordNode, // #3 = 'ld' chained node
/*4314*/          OPC_CheckFoldableChainNode,
/*4315*/          OPC_RecordChild1, // #4 = $src
/*4316*/          OPC_CheckChild1Type, MVT::i64,
/*4318*/          OPC_CheckPredicate, 0, // Predicate_unindexedload
/*4320*/          OPC_CheckPredicate, 1, // Predicate_anyextload
/*4322*/          OPC_CheckPredicate, 9, // Predicate_anyextloadi16
/*4324*/          OPC_MoveParent,
/*4325*/          OPC_CheckType, MVT::i32,
/*4327*/          OPC_MoveParent,
/*4328*/          OPC_CheckChild2Same, 2,
/*4330*/          OPC_CheckPredicate, 5, // Predicate_unindexedstore
/*4332*/          OPC_CheckPredicate, 23, // Predicate_block_or1
/*4334*/          OPC_CheckComplexPat, /*CP*/1, /*#*/2, // selectBDAddr12Only:$dest #5 #6
/*4337*/          OPC_CheckComplexPat, /*CP*/1, /*#*/4, // selectBDAddr12Only:$src #7 #8
/*4340*/          OPC_EmitMergeInputChains, 3, 0, 1, 3, 
/*4345*/          OPC_EmitInteger, MVT::i64, 2, 
/*4348*/          OPC_MorphNodeTo, TARGET_VAL(SystemZ::OCSequence), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i32, 5/*#Ops*/, 5, 6, 7, 8, 9, 
                  // Src: (st (or:i32 (ld:i32 bdaddr12only:i64:$dest)<<P:Predicate_unindexedload>>, (ld:i32 bdaddr12only:i64:$src)<<P:Predicate_unindexedload>><<P:Predicate_anyextload>><<P:Predicate_anyextloadi16>>), bdaddr12only:i64:$dest)<<P:Predicate_unindexedstore>><<P:Predicate_block_or1>> - Complexity = 42
                  // Dst: (OCSequence:i32 bdaddr12only:i64:$dest, bdaddr12only:i64:$src, 2:i64)
/*4360*/        /*Scope*/ 54, /*->4415*/
/*4361*/          OPC_CheckPredicate, 1, // Predicate_anyextload
/*4363*/          OPC_CheckPredicate, 9, // Predicate_anyextloadi16
/*4365*/          OPC_MoveParent,
/*4366*/          OPC_MoveChild, 1,
/*4368*/          OPC_CheckOpcode, TARGET_VAL(ISD::LOAD),
/*4371*/          OPC_RecordMemRef,
/*4372*/          OPC_RecordNode, // #3 = 'ld' chained node
/*4373*/          OPC_CheckFoldableChainNode,
/*4374*/          OPC_RecordChild1, // #4 = $dest
/*4375*/          OPC_CheckChild1Type, MVT::i64,
/*4377*/          OPC_CheckPredicate, 0, // Predicate_unindexedload
/*4379*/          OPC_MoveParent,
/*4380*/          OPC_CheckType, MVT::i32,
/*4382*/          OPC_MoveParent,
/*4383*/          OPC_CheckChild2Same, 4,
/*4385*/          OPC_CheckPredicate, 5, // Predicate_unindexedstore
/*4387*/          OPC_CheckPredicate, 24, // Predicate_block_or2
/*4389*/          OPC_CheckComplexPat, /*CP*/1, /*#*/2, // selectBDAddr12Only:$src #5 #6
/*4392*/          OPC_CheckComplexPat, /*CP*/1, /*#*/4, // selectBDAddr12Only:$dest #7 #8
/*4395*/          OPC_EmitMergeInputChains, 3, 0, 1, 3, 
/*4400*/          OPC_EmitInteger, MVT::i64, 2, 
/*4403*/          OPC_MorphNodeTo, TARGET_VAL(SystemZ::OCSequence), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i32, 5/*#Ops*/, 7, 8, 5, 6, 9, 
                  // Src: (st (or:i32 (ld:i32 bdaddr12only:i64:$src)<<P:Predicate_unindexedload>><<P:Predicate_anyextload>><<P:Predicate_anyextloadi16>>, (ld:i32 bdaddr12only:i64:$dest)<<P:Predicate_unindexedload>>), bdaddr12only:i64:$dest)<<P:Predicate_unindexedstore>><<P:Predicate_block_or2>> - Complexity = 42
                  // Dst: (OCSequence:i32 bdaddr12only:i64:$dest, bdaddr12only:i64:$src, 2:i64)
/*4415*/        /*Scope*/ 52, /*->4468*/
/*4416*/          OPC_MoveParent,
/*4417*/          OPC_MoveChild, 1,
/*4419*/          OPC_CheckOpcode, TARGET_VAL(ISD::LOAD),
/*4422*/          OPC_RecordMemRef,
/*4423*/          OPC_RecordNode, // #3 = 'ld' chained node
/*4424*/          OPC_CheckFoldableChainNode,
/*4425*/          OPC_RecordChild1, // #4 = $src
/*4426*/          OPC_CheckChild1Type, MVT::i64,
/*4428*/          OPC_CheckPredicate, 0, // Predicate_unindexedload
/*4430*/          OPC_CheckPredicate, 13, // Predicate_load
/*4432*/          OPC_MoveParent,
/*4433*/          OPC_CheckType, MVT::i32,
/*4435*/          OPC_MoveParent,
/*4436*/          OPC_CheckChild2Same, 2,
/*4438*/          OPC_CheckPredicate, 5, // Predicate_unindexedstore
/*4440*/          OPC_CheckPredicate, 23, // Predicate_block_or1
/*4442*/          OPC_CheckComplexPat, /*CP*/1, /*#*/2, // selectBDAddr12Only:$dest #5 #6
/*4445*/          OPC_CheckComplexPat, /*CP*/1, /*#*/4, // selectBDAddr12Only:$src #7 #8
/*4448*/          OPC_EmitMergeInputChains, 3, 0, 1, 3, 
/*4453*/          OPC_EmitInteger, MVT::i64, 4, 
/*4456*/          OPC_MorphNodeTo, TARGET_VAL(SystemZ::OCSequence), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i32, 5/*#Ops*/, 5, 6, 7, 8, 9, 
                  // Src: (st (or:i32 (ld:i32 bdaddr12only:i64:$dest)<<P:Predicate_unindexedload>>, (ld:i32 bdaddr12only:i64:$src)<<P:Predicate_unindexedload>><<P:Predicate_load>>), bdaddr12only:i64:$dest)<<P:Predicate_unindexedstore>><<P:Predicate_block_or1>> - Complexity = 42
                  // Dst: (OCSequence:i32 bdaddr12only:i64:$dest, bdaddr12only:i64:$src, 4:i64)
/*4468*/        /*Scope*/ 52, /*->4521*/
/*4469*/          OPC_CheckPredicate, 13, // Predicate_load
/*4471*/          OPC_MoveParent,
/*4472*/          OPC_MoveChild, 1,
/*4474*/          OPC_CheckOpcode, TARGET_VAL(ISD::LOAD),
/*4477*/          OPC_RecordMemRef,
/*4478*/          OPC_RecordNode, // #3 = 'ld' chained node
/*4479*/          OPC_CheckFoldableChainNode,
/*4480*/          OPC_RecordChild1, // #4 = $dest
/*4481*/          OPC_CheckChild1Type, MVT::i64,
/*4483*/          OPC_CheckPredicate, 0, // Predicate_unindexedload
/*4485*/          OPC_MoveParent,
/*4486*/          OPC_CheckType, MVT::i32,
/*4488*/          OPC_MoveParent,
/*4489*/          OPC_CheckChild2Same, 4,
/*4491*/          OPC_CheckPredicate, 5, // Predicate_unindexedstore
/*4493*/          OPC_CheckPredicate, 24, // Predicate_block_or2
/*4495*/          OPC_CheckComplexPat, /*CP*/1, /*#*/2, // selectBDAddr12Only:$src #5 #6
/*4498*/          OPC_CheckComplexPat, /*CP*/1, /*#*/4, // selectBDAddr12Only:$dest #7 #8
/*4501*/          OPC_EmitMergeInputChains, 3, 0, 1, 3, 
/*4506*/          OPC_EmitInteger, MVT::i64, 4, 
/*4509*/          OPC_MorphNodeTo, TARGET_VAL(SystemZ::OCSequence), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i32, 5/*#Ops*/, 7, 8, 5, 6, 9, 
                  // Src: (st (or:i32 (ld:i32 bdaddr12only:i64:$src)<<P:Predicate_unindexedload>><<P:Predicate_load>>, (ld:i32 bdaddr12only:i64:$dest)<<P:Predicate_unindexedload>>), bdaddr12only:i64:$dest)<<P:Predicate_unindexedstore>><<P:Predicate_block_or2>> - Complexity = 42
                  // Dst: (OCSequence:i32 bdaddr12only:i64:$dest, bdaddr12only:i64:$src, 4:i64)
/*4521*/        /*Scope*/ 54, /*->4576*/
/*4522*/          OPC_MoveParent,
/*4523*/          OPC_MoveChild, 1,
/*4525*/          OPC_CheckOpcode, TARGET_VAL(ISD::LOAD),
/*4528*/          OPC_RecordMemRef,
/*4529*/          OPC_RecordNode, // #3 = 'ld' chained node
/*4530*/          OPC_CheckFoldableChainNode,
/*4531*/          OPC_RecordChild1, // #4 = $src
/*4532*/          OPC_CheckChild1Type, MVT::i64,
/*4534*/          OPC_CheckPredicate, 0, // Predicate_unindexedload
/*4536*/          OPC_CheckPredicate, 1, // Predicate_anyextload
/*4538*/          OPC_CheckPredicate, 2, // Predicate_anyextloadi8
/*4540*/          OPC_MoveParent,
/*4541*/          OPC_CheckType, MVT::i64,
/*4543*/          OPC_MoveParent,
/*4544*/          OPC_CheckChild2Same, 2,
/*4546*/          OPC_CheckPredicate, 5, // Predicate_unindexedstore
/*4548*/          OPC_CheckPredicate, 23, // Predicate_block_or1
/*4550*/          OPC_CheckComplexPat, /*CP*/1, /*#*/2, // selectBDAddr12Only:$dest #5 #6
/*4553*/          OPC_CheckComplexPat, /*CP*/1, /*#*/4, // selectBDAddr12Only:$src #7 #8
/*4556*/          OPC_EmitMergeInputChains, 3, 0, 1, 3, 
/*4561*/          OPC_EmitInteger, MVT::i64, 1, 
/*4564*/          OPC_MorphNodeTo, TARGET_VAL(SystemZ::OCSequence), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i32, 5/*#Ops*/, 5, 6, 7, 8, 9, 
                  // Src: (st (or:i64 (ld:i64 bdaddr12only:i64:$dest)<<P:Predicate_unindexedload>>, (ld:i64 bdaddr12only:i64:$src)<<P:Predicate_unindexedload>><<P:Predicate_anyextload>><<P:Predicate_anyextloadi8>>), bdaddr12only:i64:$dest)<<P:Predicate_unindexedstore>><<P:Predicate_block_or1>> - Complexity = 42
                  // Dst: (OCSequence:i32 bdaddr12only:i64:$dest, bdaddr12only:i64:$src, 1:i64)
/*4576*/        /*Scope*/ 54, /*->4631*/
/*4577*/          OPC_CheckPredicate, 1, // Predicate_anyextload
/*4579*/          OPC_CheckPredicate, 2, // Predicate_anyextloadi8
/*4581*/          OPC_MoveParent,
/*4582*/          OPC_MoveChild, 1,
/*4584*/          OPC_CheckOpcode, TARGET_VAL(ISD::LOAD),
/*4587*/          OPC_RecordMemRef,
/*4588*/          OPC_RecordNode, // #3 = 'ld' chained node
/*4589*/          OPC_CheckFoldableChainNode,
/*4590*/          OPC_RecordChild1, // #4 = $dest
/*4591*/          OPC_CheckChild1Type, MVT::i64,
/*4593*/          OPC_CheckPredicate, 0, // Predicate_unindexedload
/*4595*/          OPC_MoveParent,
/*4596*/          OPC_CheckType, MVT::i64,
/*4598*/          OPC_MoveParent,
/*4599*/          OPC_CheckChild2Same, 4,
/*4601*/          OPC_CheckPredicate, 5, // Predicate_unindexedstore
/*4603*/          OPC_CheckPredicate, 24, // Predicate_block_or2
/*4605*/          OPC_CheckComplexPat, /*CP*/1, /*#*/2, // selectBDAddr12Only:$src #5 #6
/*4608*/          OPC_CheckComplexPat, /*CP*/1, /*#*/4, // selectBDAddr12Only:$dest #7 #8
/*4611*/          OPC_EmitMergeInputChains, 3, 0, 1, 3, 
/*4616*/          OPC_EmitInteger, MVT::i64, 1, 
/*4619*/          OPC_MorphNodeTo, TARGET_VAL(SystemZ::OCSequence), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i32, 5/*#Ops*/, 7, 8, 5, 6, 9, 
                  // Src: (st (or:i64 (ld:i64 bdaddr12only:i64:$src)<<P:Predicate_unindexedload>><<P:Predicate_anyextload>><<P:Predicate_anyextloadi8>>, (ld:i64 bdaddr12only:i64:$dest)<<P:Predicate_unindexedload>>), bdaddr12only:i64:$dest)<<P:Predicate_unindexedstore>><<P:Predicate_block_or2>> - Complexity = 42
                  // Dst: (OCSequence:i32 bdaddr12only:i64:$dest, bdaddr12only:i64:$src, 1:i64)
/*4631*/        /*Scope*/ 54, /*->4686*/
/*4632*/          OPC_MoveParent,
/*4633*/          OPC_MoveChild, 1,
/*4635*/          OPC_CheckOpcode, TARGET_VAL(ISD::LOAD),
/*4638*/          OPC_RecordMemRef,
/*4639*/          OPC_RecordNode, // #3 = 'ld' chained node
/*4640*/          OPC_CheckFoldableChainNode,
/*4641*/          OPC_RecordChild1, // #4 = $src
/*4642*/          OPC_CheckChild1Type, MVT::i64,
/*4644*/          OPC_CheckPredicate, 0, // Predicate_unindexedload
/*4646*/          OPC_CheckPredicate, 1, // Predicate_anyextload
/*4648*/          OPC_CheckPredicate, 9, // Predicate_anyextloadi16
/*4650*/          OPC_MoveParent,
/*4651*/          OPC_CheckType, MVT::i64,
/*4653*/          OPC_MoveParent,
/*4654*/          OPC_CheckChild2Same, 2,
/*4656*/          OPC_CheckPredicate, 5, // Predicate_unindexedstore
/*4658*/          OPC_CheckPredicate, 23, // Predicate_block_or1
/*4660*/          OPC_CheckComplexPat, /*CP*/1, /*#*/2, // selectBDAddr12Only:$dest #5 #6
/*4663*/          OPC_CheckComplexPat, /*CP*/1, /*#*/4, // selectBDAddr12Only:$src #7 #8
/*4666*/          OPC_EmitMergeInputChains, 3, 0, 1, 3, 
/*4671*/          OPC_EmitInteger, MVT::i64, 2, 
/*4674*/          OPC_MorphNodeTo, TARGET_VAL(SystemZ::OCSequence), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i32, 5/*#Ops*/, 5, 6, 7, 8, 9, 
                  // Src: (st (or:i64 (ld:i64 bdaddr12only:i64:$dest)<<P:Predicate_unindexedload>>, (ld:i64 bdaddr12only:i64:$src)<<P:Predicate_unindexedload>><<P:Predicate_anyextload>><<P:Predicate_anyextloadi16>>), bdaddr12only:i64:$dest)<<P:Predicate_unindexedstore>><<P:Predicate_block_or1>> - Complexity = 42
                  // Dst: (OCSequence:i32 bdaddr12only:i64:$dest, bdaddr12only:i64:$src, 2:i64)
/*4686*/        /*Scope*/ 54, /*->4741*/
/*4687*/          OPC_CheckPredicate, 1, // Predicate_anyextload
/*4689*/          OPC_CheckPredicate, 9, // Predicate_anyextloadi16
/*4691*/          OPC_MoveParent,
/*4692*/          OPC_MoveChild, 1,
/*4694*/          OPC_CheckOpcode, TARGET_VAL(ISD::LOAD),
/*4697*/          OPC_RecordMemRef,
/*4698*/          OPC_RecordNode, // #3 = 'ld' chained node
/*4699*/          OPC_CheckFoldableChainNode,
/*4700*/          OPC_RecordChild1, // #4 = $dest
/*4701*/          OPC_CheckChild1Type, MVT::i64,
/*4703*/          OPC_CheckPredicate, 0, // Predicate_unindexedload
/*4705*/          OPC_MoveParent,
/*4706*/          OPC_CheckType, MVT::i64,
/*4708*/          OPC_MoveParent,
/*4709*/          OPC_CheckChild2Same, 4,
/*4711*/          OPC_CheckPredicate, 5, // Predicate_unindexedstore
/*4713*/          OPC_CheckPredicate, 24, // Predicate_block_or2
/*4715*/          OPC_CheckComplexPat, /*CP*/1, /*#*/2, // selectBDAddr12Only:$src #5 #6
/*4718*/          OPC_CheckComplexPat, /*CP*/1, /*#*/4, // selectBDAddr12Only:$dest #7 #8
/*4721*/          OPC_EmitMergeInputChains, 3, 0, 1, 3, 
/*4726*/          OPC_EmitInteger, MVT::i64, 2, 
/*4729*/          OPC_MorphNodeTo, TARGET_VAL(SystemZ::OCSequence), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i32, 5/*#Ops*/, 7, 8, 5, 6, 9, 
                  // Src: (st (or:i64 (ld:i64 bdaddr12only:i64:$src)<<P:Predicate_unindexedload>><<P:Predicate_anyextload>><<P:Predicate_anyextloadi16>>, (ld:i64 bdaddr12only:i64:$dest)<<P:Predicate_unindexedload>>), bdaddr12only:i64:$dest)<<P:Predicate_unindexedstore>><<P:Predicate_block_or2>> - Complexity = 42
                  // Dst: (OCSequence:i32 bdaddr12only:i64:$dest, bdaddr12only:i64:$src, 2:i64)
/*4741*/        /*Scope*/ 54, /*->4796*/
/*4742*/          OPC_MoveParent,
/*4743*/          OPC_MoveChild, 1,
/*4745*/          OPC_CheckOpcode, TARGET_VAL(ISD::LOAD),
/*4748*/          OPC_RecordMemRef,
/*4749*/          OPC_RecordNode, // #3 = 'ld' chained node
/*4750*/          OPC_CheckFoldableChainNode,
/*4751*/          OPC_RecordChild1, // #4 = $src
/*4752*/          OPC_CheckChild1Type, MVT::i64,
/*4754*/          OPC_CheckPredicate, 0, // Predicate_unindexedload
/*4756*/          OPC_CheckPredicate, 1, // Predicate_anyextload
/*4758*/          OPC_CheckPredicate, 17, // Predicate_anyextloadi32
/*4760*/          OPC_MoveParent,
/*4761*/          OPC_CheckType, MVT::i64,
/*4763*/          OPC_MoveParent,
/*4764*/          OPC_CheckChild2Same, 2,
/*4766*/          OPC_CheckPredicate, 5, // Predicate_unindexedstore
/*4768*/          OPC_CheckPredicate, 23, // Predicate_block_or1
/*4770*/          OPC_CheckComplexPat, /*CP*/1, /*#*/2, // selectBDAddr12Only:$dest #5 #6
/*4773*/          OPC_CheckComplexPat, /*CP*/1, /*#*/4, // selectBDAddr12Only:$src #7 #8
/*4776*/          OPC_EmitMergeInputChains, 3, 0, 1, 3, 
/*4781*/          OPC_EmitInteger, MVT::i64, 4, 
/*4784*/          OPC_MorphNodeTo, TARGET_VAL(SystemZ::OCSequence), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i32, 5/*#Ops*/, 5, 6, 7, 8, 9, 
                  // Src: (st (or:i64 (ld:i64 bdaddr12only:i64:$dest)<<P:Predicate_unindexedload>>, (ld:i64 bdaddr12only:i64:$src)<<P:Predicate_unindexedload>><<P:Predicate_anyextload>><<P:Predicate_anyextloadi32>>), bdaddr12only:i64:$dest)<<P:Predicate_unindexedstore>><<P:Predicate_block_or1>> - Complexity = 42
                  // Dst: (OCSequence:i32 bdaddr12only:i64:$dest, bdaddr12only:i64:$src, 4:i64)
/*4796*/        /*Scope*/ 54, /*->4851*/
/*4797*/          OPC_CheckPredicate, 1, // Predicate_anyextload
/*4799*/          OPC_CheckPredicate, 17, // Predicate_anyextloadi32
/*4801*/          OPC_MoveParent,
/*4802*/          OPC_MoveChild, 1,
/*4804*/          OPC_CheckOpcode, TARGET_VAL(ISD::LOAD),
/*4807*/          OPC_RecordMemRef,
/*4808*/          OPC_RecordNode, // #3 = 'ld' chained node
/*4809*/          OPC_CheckFoldableChainNode,
/*4810*/          OPC_RecordChild1, // #4 = $dest
/*4811*/          OPC_CheckChild1Type, MVT::i64,
/*4813*/          OPC_CheckPredicate, 0, // Predicate_unindexedload
/*4815*/          OPC_MoveParent,
/*4816*/          OPC_CheckType, MVT::i64,
/*4818*/          OPC_MoveParent,
/*4819*/          OPC_CheckChild2Same, 4,
/*4821*/          OPC_CheckPredicate, 5, // Predicate_unindexedstore
/*4823*/          OPC_CheckPredicate, 24, // Predicate_block_or2
/*4825*/          OPC_CheckComplexPat, /*CP*/1, /*#*/2, // selectBDAddr12Only:$src #5 #6
/*4828*/          OPC_CheckComplexPat, /*CP*/1, /*#*/4, // selectBDAddr12Only:$dest #7 #8
/*4831*/          OPC_EmitMergeInputChains, 3, 0, 1, 3, 
/*4836*/          OPC_EmitInteger, MVT::i64, 4, 
/*4839*/          OPC_MorphNodeTo, TARGET_VAL(SystemZ::OCSequence), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i32, 5/*#Ops*/, 7, 8, 5, 6, 9, 
                  // Src: (st (or:i64 (ld:i64 bdaddr12only:i64:$src)<<P:Predicate_unindexedload>><<P:Predicate_anyextload>><<P:Predicate_anyextloadi32>>, (ld:i64 bdaddr12only:i64:$dest)<<P:Predicate_unindexedload>>), bdaddr12only:i64:$dest)<<P:Predicate_unindexedstore>><<P:Predicate_block_or2>> - Complexity = 42
                  // Dst: (OCSequence:i32 bdaddr12only:i64:$dest, bdaddr12only:i64:$src, 4:i64)
/*4851*/        /*Scope*/ 52, /*->4904*/
/*4852*/          OPC_MoveParent,
/*4853*/          OPC_MoveChild, 1,
/*4855*/          OPC_CheckOpcode, TARGET_VAL(ISD::LOAD),
/*4858*/          OPC_RecordMemRef,
/*4859*/          OPC_RecordNode, // #3 = 'ld' chained node
/*4860*/          OPC_CheckFoldableChainNode,
/*4861*/          OPC_RecordChild1, // #4 = $src
/*4862*/          OPC_CheckChild1Type, MVT::i64,
/*4864*/          OPC_CheckPredicate, 0, // Predicate_unindexedload
/*4866*/          OPC_CheckPredicate, 13, // Predicate_load
/*4868*/          OPC_MoveParent,
/*4869*/          OPC_CheckType, MVT::i64,
/*4871*/          OPC_MoveParent,
/*4872*/          OPC_CheckChild2Same, 2,
/*4874*/          OPC_CheckPredicate, 5, // Predicate_unindexedstore
/*4876*/          OPC_CheckPredicate, 23, // Predicate_block_or1
/*4878*/          OPC_CheckComplexPat, /*CP*/1, /*#*/2, // selectBDAddr12Only:$dest #5 #6
/*4881*/          OPC_CheckComplexPat, /*CP*/1, /*#*/4, // selectBDAddr12Only:$src #7 #8
/*4884*/          OPC_EmitMergeInputChains, 3, 0, 1, 3, 
/*4889*/          OPC_EmitInteger, MVT::i64, 8, 
/*4892*/          OPC_MorphNodeTo, TARGET_VAL(SystemZ::OCSequence), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i32, 5/*#Ops*/, 5, 6, 7, 8, 9, 
                  // Src: (st (or:i64 (ld:i64 bdaddr12only:i64:$dest)<<P:Predicate_unindexedload>>, (ld:i64 bdaddr12only:i64:$src)<<P:Predicate_unindexedload>><<P:Predicate_load>>), bdaddr12only:i64:$dest)<<P:Predicate_unindexedstore>><<P:Predicate_block_or1>> - Complexity = 42
                  // Dst: (OCSequence:i32 bdaddr12only:i64:$dest, bdaddr12only:i64:$src, 8:i64)
/*4904*/        /*Scope*/ 52, /*->4957*/
/*4905*/          OPC_CheckPredicate, 13, // Predicate_load
/*4907*/          OPC_MoveParent,
/*4908*/          OPC_MoveChild, 1,
/*4910*/          OPC_CheckOpcode, TARGET_VAL(ISD::LOAD),
/*4913*/          OPC_RecordMemRef,
/*4914*/          OPC_RecordNode, // #3 = 'ld' chained node
/*4915*/          OPC_CheckFoldableChainNode,
/*4916*/          OPC_RecordChild1, // #4 = $dest
/*4917*/          OPC_CheckChild1Type, MVT::i64,
/*4919*/          OPC_CheckPredicate, 0, // Predicate_unindexedload
/*4921*/          OPC_MoveParent,
/*4922*/          OPC_CheckType, MVT::i64,
/*4924*/          OPC_MoveParent,
/*4925*/          OPC_CheckChild2Same, 4,
/*4927*/          OPC_CheckPredicate, 5, // Predicate_unindexedstore
/*4929*/          OPC_CheckPredicate, 24, // Predicate_block_or2
/*4931*/          OPC_CheckComplexPat, /*CP*/1, /*#*/2, // selectBDAddr12Only:$src #5 #6
/*4934*/          OPC_CheckComplexPat, /*CP*/1, /*#*/4, // selectBDAddr12Only:$dest #7 #8
/*4937*/          OPC_EmitMergeInputChains, 3, 0, 1, 3, 
/*4942*/          OPC_EmitInteger, MVT::i64, 8, 
/*4945*/          OPC_MorphNodeTo, TARGET_VAL(SystemZ::OCSequence), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i32, 5/*#Ops*/, 7, 8, 5, 6, 9, 
                  // Src: (st (or:i64 (ld:i64 bdaddr12only:i64:$src)<<P:Predicate_unindexedload>><<P:Predicate_load>>, (ld:i64 bdaddr12only:i64:$dest)<<P:Predicate_unindexedload>>), bdaddr12only:i64:$dest)<<P:Predicate_unindexedstore>><<P:Predicate_block_or2>> - Complexity = 42
                  // Dst: (OCSequence:i32 bdaddr12only:i64:$dest, bdaddr12only:i64:$src, 8:i64)
/*4957*/        /*Scope*/ 4|128,1/*132*/, /*->5091*/
/*4959*/          OPC_CheckPredicate, 1, // Predicate_anyextload
/*4961*/          OPC_CheckPredicate, 2, // Predicate_anyextloadi8
/*4963*/          OPC_MoveParent,
/*4964*/          OPC_RecordChild1, // #3 = $src
/*4965*/          OPC_MoveChild, 1,
/*4967*/          OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*4970*/          OPC_MoveParent,
/*4971*/          OPC_SwitchType /*2 cases */, 57,  MVT::i32,// ->5031
/*4974*/            OPC_MoveParent,
/*4975*/            OPC_CheckChild2Same, 2,
/*4977*/            OPC_CheckPredicate, 5, // Predicate_unindexedstore
/*4979*/            OPC_CheckPredicate, 6, // Predicate_truncstore
/*4981*/            OPC_CheckPredicate, 7, // Predicate_truncstorei8
/*4983*/            OPC_Scope, 22, /*->5007*/ // 2 children in Scope
/*4985*/              OPC_CheckComplexPat, /*CP*/2, /*#*/2, // selectBDAddr12Pair:$addr #4 #5
/*4988*/              OPC_EmitMergeInputChains, 2, 0, 1, 
/*4992*/              OPC_EmitConvertToTarget, 3,
/*4994*/              OPC_EmitNodeXForm, 0, 6, // UIMM8
/*4997*/              OPC_MorphNodeTo, TARGET_VAL(SystemZ::OI), 0|OPFL_Chain|OPFL_MemRefs,
                          1/*#VTs*/, MVT::i32, 3/*#Ops*/, 4, 5, 7, 
                      // Src: (st (or:i32 (ld:i32 bdaddr12pair:i64:$addr)<<P:Predicate_unindexedload>><<P:Predicate_anyextload>><<P:Predicate_anyextloadi8>>, (imm:i32):$src), bdaddr12pair:i64:$addr)<<P:Predicate_unindexedstore>><<P:Predicate_truncstore>><<P:Predicate_truncstorei8>> - Complexity = 32
                      // Dst: (OI:i32 bdaddr12pair:i64:$addr, (UIMM8:i8 (imm:i32):$src))
/*5007*/            /*Scope*/ 22, /*->5030*/
/*5008*/              OPC_CheckComplexPat, /*CP*/3, /*#*/2, // selectBDAddr20Pair:$addr #4 #5
/*5011*/              OPC_EmitMergeInputChains, 2, 0, 1, 
/*5015*/              OPC_EmitConvertToTarget, 3,
/*5017*/              OPC_EmitNodeXForm, 0, 6, // UIMM8
/*5020*/              OPC_MorphNodeTo, TARGET_VAL(SystemZ::OIY), 0|OPFL_Chain|OPFL_MemRefs,
                          1/*#VTs*/, MVT::i32, 3/*#Ops*/, 4, 5, 7, 
                      // Src: (st (or:i32 (ld:i32 bdaddr20pair:i64:$addr)<<P:Predicate_unindexedload>><<P:Predicate_anyextload>><<P:Predicate_anyextloadi8>>, (imm:i32):$src), bdaddr20pair:i64:$addr)<<P:Predicate_unindexedstore>><<P:Predicate_truncstore>><<P:Predicate_truncstorei8>> - Complexity = 32
                      // Dst: (OIY:i32 bdaddr20pair:i64:$addr, (UIMM8:i8 (imm:i32):$src))
/*5030*/            0, /*End of Scope*/
/*5031*/          /*SwitchType*/ 57,  MVT::i64,// ->5090
/*5033*/            OPC_MoveParent,
/*5034*/            OPC_CheckChild2Same, 2,
/*5036*/            OPC_CheckPredicate, 5, // Predicate_unindexedstore
/*5038*/            OPC_CheckPredicate, 6, // Predicate_truncstore
/*5040*/            OPC_CheckPredicate, 7, // Predicate_truncstorei8
/*5042*/            OPC_Scope, 22, /*->5066*/ // 2 children in Scope
/*5044*/              OPC_CheckComplexPat, /*CP*/2, /*#*/2, // selectBDAddr12Pair:$addr #4 #5
/*5047*/              OPC_EmitMergeInputChains, 2, 0, 1, 
/*5051*/              OPC_EmitConvertToTarget, 3,
/*5053*/              OPC_EmitNodeXForm, 0, 6, // UIMM8
/*5056*/              OPC_MorphNodeTo, TARGET_VAL(SystemZ::OI), 0|OPFL_Chain|OPFL_MemRefs,
                          1/*#VTs*/, MVT::i32, 3/*#Ops*/, 4, 5, 7, 
                      // Src: (st (or:i64 (ld:i64 bdaddr12pair:i64:$addr)<<P:Predicate_unindexedload>><<P:Predicate_anyextload>><<P:Predicate_anyextloadi8>>, (imm:i64):$src), bdaddr12pair:i64:$addr)<<P:Predicate_unindexedstore>><<P:Predicate_truncstore>><<P:Predicate_truncstorei8>> - Complexity = 32
                      // Dst: (OI:i32 bdaddr12pair:i64:$addr, (UIMM8:i8 (imm:i64):$src))
/*5066*/            /*Scope*/ 22, /*->5089*/
/*5067*/              OPC_CheckComplexPat, /*CP*/3, /*#*/2, // selectBDAddr20Pair:$addr #4 #5
/*5070*/              OPC_EmitMergeInputChains, 2, 0, 1, 
/*5074*/              OPC_EmitConvertToTarget, 3,
/*5076*/              OPC_EmitNodeXForm, 0, 6, // UIMM8
/*5079*/              OPC_MorphNodeTo, TARGET_VAL(SystemZ::OIY), 0|OPFL_Chain|OPFL_MemRefs,
                          1/*#VTs*/, MVT::i32, 3/*#Ops*/, 4, 5, 7, 
                      // Src: (st (or:i64 (ld:i64 bdaddr20pair:i64:$addr)<<P:Predicate_unindexedload>><<P:Predicate_anyextload>><<P:Predicate_anyextloadi8>>, (imm:i64):$src), bdaddr20pair:i64:$addr)<<P:Predicate_unindexedstore>><<P:Predicate_truncstore>><<P:Predicate_truncstorei8>> - Complexity = 32
                      // Dst: (OIY:i32 bdaddr20pair:i64:$addr, (UIMM8:i8 (imm:i64):$src))
/*5089*/            0, /*End of Scope*/
/*5090*/          0, // EndSwitchType
/*5091*/        0, /*End of Scope*/
/*5092*/      /*SwitchOpcode*/ 126|128,12/*1662*/,  TARGET_VAL(ISD::XOR),// ->6758
/*5096*/        OPC_MoveChild, 0,
/*5098*/        OPC_CheckOpcode, TARGET_VAL(ISD::LOAD),
/*5101*/        OPC_RecordMemRef,
/*5102*/        OPC_RecordNode, // #1 = 'ld' chained node
/*5103*/        OPC_CheckFoldableChainNode,
/*5104*/        OPC_RecordChild1, // #2 = $src
/*5105*/        OPC_CheckChild1Type, MVT::i64,
/*5107*/        OPC_CheckPredicate, 0, // Predicate_unindexedload
/*5109*/        OPC_Scope, 54, /*->5165*/ // 28 children in Scope
/*5111*/          OPC_CheckPredicate, 1, // Predicate_anyextload
/*5113*/          OPC_CheckPredicate, 2, // Predicate_anyextloadi8
/*5115*/          OPC_MoveParent,
/*5116*/          OPC_MoveChild, 1,
/*5118*/          OPC_CheckOpcode, TARGET_VAL(ISD::LOAD),
/*5121*/          OPC_RecordMemRef,
/*5122*/          OPC_RecordNode, // #3 = 'ld' chained node
/*5123*/          OPC_CheckFoldableChainNode,
/*5124*/          OPC_RecordChild1, // #4 = $dest
/*5125*/          OPC_CheckChild1Type, MVT::i64,
/*5127*/          OPC_CheckPredicate, 0, // Predicate_unindexedload
/*5129*/          OPC_MoveParent,
/*5130*/          OPC_CheckType, MVT::i32,
/*5132*/          OPC_MoveParent,
/*5133*/          OPC_CheckChild2Same, 4,
/*5135*/          OPC_CheckPredicate, 5, // Predicate_unindexedstore
/*5137*/          OPC_CheckPredicate, 25, // Predicate_block_xor1
/*5139*/          OPC_CheckComplexPat, /*CP*/1, /*#*/2, // selectBDAddr12Only:$src #5 #6
/*5142*/          OPC_CheckComplexPat, /*CP*/1, /*#*/4, // selectBDAddr12Only:$dest #7 #8
/*5145*/          OPC_EmitMergeInputChains, 3, 0, 1, 3, 
/*5150*/          OPC_EmitInteger, MVT::i64, 1, 
/*5153*/          OPC_MorphNodeTo, TARGET_VAL(SystemZ::XCSequence), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i32, 5/*#Ops*/, 7, 8, 5, 6, 9, 
                  // Src: (st (xor:i32 (ld:i32 bdaddr12only:i64:$src)<<P:Predicate_unindexedload>><<P:Predicate_anyextload>><<P:Predicate_anyextloadi8>>, (ld:i32 bdaddr12only:i64:$dest)<<P:Predicate_unindexedload>>), bdaddr12only:i64:$dest)<<P:Predicate_unindexedstore>><<P:Predicate_block_xor1>> - Complexity = 42
                  // Dst: (XCSequence:i32 bdaddr12only:i64:$dest, bdaddr12only:i64:$src, 1:i64)
/*5165*/        /*Scope*/ 54, /*->5220*/
/*5166*/          OPC_MoveParent,
/*5167*/          OPC_MoveChild, 1,
/*5169*/          OPC_CheckOpcode, TARGET_VAL(ISD::LOAD),
/*5172*/          OPC_RecordMemRef,
/*5173*/          OPC_RecordNode, // #3 = 'ld' chained node
/*5174*/          OPC_CheckFoldableChainNode,
/*5175*/          OPC_RecordChild1, // #4 = $src
/*5176*/          OPC_CheckChild1Type, MVT::i64,
/*5178*/          OPC_CheckPredicate, 0, // Predicate_unindexedload
/*5180*/          OPC_CheckPredicate, 1, // Predicate_anyextload
/*5182*/          OPC_CheckPredicate, 2, // Predicate_anyextloadi8
/*5184*/          OPC_MoveParent,
/*5185*/          OPC_CheckType, MVT::i32,
/*5187*/          OPC_MoveParent,
/*5188*/          OPC_CheckChild2Same, 2,
/*5190*/          OPC_CheckPredicate, 5, // Predicate_unindexedstore
/*5192*/          OPC_CheckPredicate, 26, // Predicate_block_xor2
/*5194*/          OPC_CheckComplexPat, /*CP*/1, /*#*/2, // selectBDAddr12Only:$dest #5 #6
/*5197*/          OPC_CheckComplexPat, /*CP*/1, /*#*/4, // selectBDAddr12Only:$src #7 #8
/*5200*/          OPC_EmitMergeInputChains, 3, 0, 1, 3, 
/*5205*/          OPC_EmitInteger, MVT::i64, 1, 
/*5208*/          OPC_MorphNodeTo, TARGET_VAL(SystemZ::XCSequence), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i32, 5/*#Ops*/, 5, 6, 7, 8, 9, 
                  // Src: (st (xor:i32 (ld:i32 bdaddr12only:i64:$dest)<<P:Predicate_unindexedload>>, (ld:i32 bdaddr12only:i64:$src)<<P:Predicate_unindexedload>><<P:Predicate_anyextload>><<P:Predicate_anyextloadi8>>), bdaddr12only:i64:$dest)<<P:Predicate_unindexedstore>><<P:Predicate_block_xor2>> - Complexity = 42
                  // Dst: (XCSequence:i32 bdaddr12only:i64:$dest, bdaddr12only:i64:$src, 1:i64)
/*5220*/        /*Scope*/ 54, /*->5275*/
/*5221*/          OPC_CheckPredicate, 1, // Predicate_anyextload
/*5223*/          OPC_CheckPredicate, 9, // Predicate_anyextloadi16
/*5225*/          OPC_MoveParent,
/*5226*/          OPC_MoveChild, 1,
/*5228*/          OPC_CheckOpcode, TARGET_VAL(ISD::LOAD),
/*5231*/          OPC_RecordMemRef,
/*5232*/          OPC_RecordNode, // #3 = 'ld' chained node
/*5233*/          OPC_CheckFoldableChainNode,
/*5234*/          OPC_RecordChild1, // #4 = $dest
/*5235*/          OPC_CheckChild1Type, MVT::i64,
/*5237*/          OPC_CheckPredicate, 0, // Predicate_unindexedload
/*5239*/          OPC_MoveParent,
/*5240*/          OPC_CheckType, MVT::i32,
/*5242*/          OPC_MoveParent,
/*5243*/          OPC_CheckChild2Same, 4,
/*5245*/          OPC_CheckPredicate, 5, // Predicate_unindexedstore
/*5247*/          OPC_CheckPredicate, 25, // Predicate_block_xor1
/*5249*/          OPC_CheckComplexPat, /*CP*/1, /*#*/2, // selectBDAddr12Only:$src #5 #6
/*5252*/          OPC_CheckComplexPat, /*CP*/1, /*#*/4, // selectBDAddr12Only:$dest #7 #8
/*5255*/          OPC_EmitMergeInputChains, 3, 0, 1, 3, 
/*5260*/          OPC_EmitInteger, MVT::i64, 2, 
/*5263*/          OPC_MorphNodeTo, TARGET_VAL(SystemZ::XCSequence), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i32, 5/*#Ops*/, 7, 8, 5, 6, 9, 
                  // Src: (st (xor:i32 (ld:i32 bdaddr12only:i64:$src)<<P:Predicate_unindexedload>><<P:Predicate_anyextload>><<P:Predicate_anyextloadi16>>, (ld:i32 bdaddr12only:i64:$dest)<<P:Predicate_unindexedload>>), bdaddr12only:i64:$dest)<<P:Predicate_unindexedstore>><<P:Predicate_block_xor1>> - Complexity = 42
                  // Dst: (XCSequence:i32 bdaddr12only:i64:$dest, bdaddr12only:i64:$src, 2:i64)
/*5275*/        /*Scope*/ 54, /*->5330*/
/*5276*/          OPC_MoveParent,
/*5277*/          OPC_MoveChild, 1,
/*5279*/          OPC_CheckOpcode, TARGET_VAL(ISD::LOAD),
/*5282*/          OPC_RecordMemRef,
/*5283*/          OPC_RecordNode, // #3 = 'ld' chained node
/*5284*/          OPC_CheckFoldableChainNode,
/*5285*/          OPC_RecordChild1, // #4 = $src
/*5286*/          OPC_CheckChild1Type, MVT::i64,
/*5288*/          OPC_CheckPredicate, 0, // Predicate_unindexedload
/*5290*/          OPC_CheckPredicate, 1, // Predicate_anyextload
/*5292*/          OPC_CheckPredicate, 9, // Predicate_anyextloadi16
/*5294*/          OPC_MoveParent,
/*5295*/          OPC_CheckType, MVT::i32,
/*5297*/          OPC_MoveParent,
/*5298*/          OPC_CheckChild2Same, 2,
/*5300*/          OPC_CheckPredicate, 5, // Predicate_unindexedstore
/*5302*/          OPC_CheckPredicate, 26, // Predicate_block_xor2
/*5304*/          OPC_CheckComplexPat, /*CP*/1, /*#*/2, // selectBDAddr12Only:$dest #5 #6
/*5307*/          OPC_CheckComplexPat, /*CP*/1, /*#*/4, // selectBDAddr12Only:$src #7 #8
/*5310*/          OPC_EmitMergeInputChains, 3, 0, 1, 3, 
/*5315*/          OPC_EmitInteger, MVT::i64, 2, 
/*5318*/          OPC_MorphNodeTo, TARGET_VAL(SystemZ::XCSequence), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i32, 5/*#Ops*/, 5, 6, 7, 8, 9, 
                  // Src: (st (xor:i32 (ld:i32 bdaddr12only:i64:$dest)<<P:Predicate_unindexedload>>, (ld:i32 bdaddr12only:i64:$src)<<P:Predicate_unindexedload>><<P:Predicate_anyextload>><<P:Predicate_anyextloadi16>>), bdaddr12only:i64:$dest)<<P:Predicate_unindexedstore>><<P:Predicate_block_xor2>> - Complexity = 42
                  // Dst: (XCSequence:i32 bdaddr12only:i64:$dest, bdaddr12only:i64:$src, 2:i64)
/*5330*/        /*Scope*/ 52, /*->5383*/
/*5331*/          OPC_CheckPredicate, 13, // Predicate_load
/*5333*/          OPC_MoveParent,
/*5334*/          OPC_MoveChild, 1,
/*5336*/          OPC_CheckOpcode, TARGET_VAL(ISD::LOAD),
/*5339*/          OPC_RecordMemRef,
/*5340*/          OPC_RecordNode, // #3 = 'ld' chained node
/*5341*/          OPC_CheckFoldableChainNode,
/*5342*/          OPC_RecordChild1, // #4 = $dest
/*5343*/          OPC_CheckChild1Type, MVT::i64,
/*5345*/          OPC_CheckPredicate, 0, // Predicate_unindexedload
/*5347*/          OPC_MoveParent,
/*5348*/          OPC_CheckType, MVT::i32,
/*5350*/          OPC_MoveParent,
/*5351*/          OPC_CheckChild2Same, 4,
/*5353*/          OPC_CheckPredicate, 5, // Predicate_unindexedstore
/*5355*/          OPC_CheckPredicate, 25, // Predicate_block_xor1
/*5357*/          OPC_CheckComplexPat, /*CP*/1, /*#*/2, // selectBDAddr12Only:$src #5 #6
/*5360*/          OPC_CheckComplexPat, /*CP*/1, /*#*/4, // selectBDAddr12Only:$dest #7 #8
/*5363*/          OPC_EmitMergeInputChains, 3, 0, 1, 3, 
/*5368*/          OPC_EmitInteger, MVT::i64, 4, 
/*5371*/          OPC_MorphNodeTo, TARGET_VAL(SystemZ::XCSequence), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i32, 5/*#Ops*/, 7, 8, 5, 6, 9, 
                  // Src: (st (xor:i32 (ld:i32 bdaddr12only:i64:$src)<<P:Predicate_unindexedload>><<P:Predicate_load>>, (ld:i32 bdaddr12only:i64:$dest)<<P:Predicate_unindexedload>>), bdaddr12only:i64:$dest)<<P:Predicate_unindexedstore>><<P:Predicate_block_xor1>> - Complexity = 42
                  // Dst: (XCSequence:i32 bdaddr12only:i64:$dest, bdaddr12only:i64:$src, 4:i64)
/*5383*/        /*Scope*/ 52, /*->5436*/
/*5384*/          OPC_MoveParent,
/*5385*/          OPC_MoveChild, 1,
/*5387*/          OPC_CheckOpcode, TARGET_VAL(ISD::LOAD),
/*5390*/          OPC_RecordMemRef,
/*5391*/          OPC_RecordNode, // #3 = 'ld' chained node
/*5392*/          OPC_CheckFoldableChainNode,
/*5393*/          OPC_RecordChild1, // #4 = $src
/*5394*/          OPC_CheckChild1Type, MVT::i64,
/*5396*/          OPC_CheckPredicate, 0, // Predicate_unindexedload
/*5398*/          OPC_CheckPredicate, 13, // Predicate_load
/*5400*/          OPC_MoveParent,
/*5401*/          OPC_CheckType, MVT::i32,
/*5403*/          OPC_MoveParent,
/*5404*/          OPC_CheckChild2Same, 2,
/*5406*/          OPC_CheckPredicate, 5, // Predicate_unindexedstore
/*5408*/          OPC_CheckPredicate, 26, // Predicate_block_xor2
/*5410*/          OPC_CheckComplexPat, /*CP*/1, /*#*/2, // selectBDAddr12Only:$dest #5 #6
/*5413*/          OPC_CheckComplexPat, /*CP*/1, /*#*/4, // selectBDAddr12Only:$src #7 #8
/*5416*/          OPC_EmitMergeInputChains, 3, 0, 1, 3, 
/*5421*/          OPC_EmitInteger, MVT::i64, 4, 
/*5424*/          OPC_MorphNodeTo, TARGET_VAL(SystemZ::XCSequence), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i32, 5/*#Ops*/, 5, 6, 7, 8, 9, 
                  // Src: (st (xor:i32 (ld:i32 bdaddr12only:i64:$dest)<<P:Predicate_unindexedload>>, (ld:i32 bdaddr12only:i64:$src)<<P:Predicate_unindexedload>><<P:Predicate_load>>), bdaddr12only:i64:$dest)<<P:Predicate_unindexedstore>><<P:Predicate_block_xor2>> - Complexity = 42
                  // Dst: (XCSequence:i32 bdaddr12only:i64:$dest, bdaddr12only:i64:$src, 4:i64)
/*5436*/        /*Scope*/ 54, /*->5491*/
/*5437*/          OPC_CheckPredicate, 1, // Predicate_anyextload
/*5439*/          OPC_CheckPredicate, 2, // Predicate_anyextloadi8
/*5441*/          OPC_MoveParent,
/*5442*/          OPC_MoveChild, 1,
/*5444*/          OPC_CheckOpcode, TARGET_VAL(ISD::LOAD),
/*5447*/          OPC_RecordMemRef,
/*5448*/          OPC_RecordNode, // #3 = 'ld' chained node
/*5449*/          OPC_CheckFoldableChainNode,
/*5450*/          OPC_RecordChild1, // #4 = $dest
/*5451*/          OPC_CheckChild1Type, MVT::i64,
/*5453*/          OPC_CheckPredicate, 0, // Predicate_unindexedload
/*5455*/          OPC_MoveParent,
/*5456*/          OPC_CheckType, MVT::i64,
/*5458*/          OPC_MoveParent,
/*5459*/          OPC_CheckChild2Same, 4,
/*5461*/          OPC_CheckPredicate, 5, // Predicate_unindexedstore
/*5463*/          OPC_CheckPredicate, 25, // Predicate_block_xor1
/*5465*/          OPC_CheckComplexPat, /*CP*/1, /*#*/2, // selectBDAddr12Only:$src #5 #6
/*5468*/          OPC_CheckComplexPat, /*CP*/1, /*#*/4, // selectBDAddr12Only:$dest #7 #8
/*5471*/          OPC_EmitMergeInputChains, 3, 0, 1, 3, 
/*5476*/          OPC_EmitInteger, MVT::i64, 1, 
/*5479*/          OPC_MorphNodeTo, TARGET_VAL(SystemZ::XCSequence), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i32, 5/*#Ops*/, 7, 8, 5, 6, 9, 
                  // Src: (st (xor:i64 (ld:i64 bdaddr12only:i64:$src)<<P:Predicate_unindexedload>><<P:Predicate_anyextload>><<P:Predicate_anyextloadi8>>, (ld:i64 bdaddr12only:i64:$dest)<<P:Predicate_unindexedload>>), bdaddr12only:i64:$dest)<<P:Predicate_unindexedstore>><<P:Predicate_block_xor1>> - Complexity = 42
                  // Dst: (XCSequence:i32 bdaddr12only:i64:$dest, bdaddr12only:i64:$src, 1:i64)
/*5491*/        /*Scope*/ 54, /*->5546*/
/*5492*/          OPC_MoveParent,
/*5493*/          OPC_MoveChild, 1,
/*5495*/          OPC_CheckOpcode, TARGET_VAL(ISD::LOAD),
/*5498*/          OPC_RecordMemRef,
/*5499*/          OPC_RecordNode, // #3 = 'ld' chained node
/*5500*/          OPC_CheckFoldableChainNode,
/*5501*/          OPC_RecordChild1, // #4 = $src
/*5502*/          OPC_CheckChild1Type, MVT::i64,
/*5504*/          OPC_CheckPredicate, 0, // Predicate_unindexedload
/*5506*/          OPC_CheckPredicate, 1, // Predicate_anyextload
/*5508*/          OPC_CheckPredicate, 2, // Predicate_anyextloadi8
/*5510*/          OPC_MoveParent,
/*5511*/          OPC_CheckType, MVT::i64,
/*5513*/          OPC_MoveParent,
/*5514*/          OPC_CheckChild2Same, 2,
/*5516*/          OPC_CheckPredicate, 5, // Predicate_unindexedstore
/*5518*/          OPC_CheckPredicate, 26, // Predicate_block_xor2
/*5520*/          OPC_CheckComplexPat, /*CP*/1, /*#*/2, // selectBDAddr12Only:$dest #5 #6
/*5523*/          OPC_CheckComplexPat, /*CP*/1, /*#*/4, // selectBDAddr12Only:$src #7 #8
/*5526*/          OPC_EmitMergeInputChains, 3, 0, 1, 3, 
/*5531*/          OPC_EmitInteger, MVT::i64, 1, 
/*5534*/          OPC_MorphNodeTo, TARGET_VAL(SystemZ::XCSequence), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i32, 5/*#Ops*/, 5, 6, 7, 8, 9, 
                  // Src: (st (xor:i64 (ld:i64 bdaddr12only:i64:$dest)<<P:Predicate_unindexedload>>, (ld:i64 bdaddr12only:i64:$src)<<P:Predicate_unindexedload>><<P:Predicate_anyextload>><<P:Predicate_anyextloadi8>>), bdaddr12only:i64:$dest)<<P:Predicate_unindexedstore>><<P:Predicate_block_xor2>> - Complexity = 42
                  // Dst: (XCSequence:i32 bdaddr12only:i64:$dest, bdaddr12only:i64:$src, 1:i64)
/*5546*/        /*Scope*/ 54, /*->5601*/
/*5547*/          OPC_CheckPredicate, 1, // Predicate_anyextload
/*5549*/          OPC_CheckPredicate, 9, // Predicate_anyextloadi16
/*5551*/          OPC_MoveParent,
/*5552*/          OPC_MoveChild, 1,
/*5554*/          OPC_CheckOpcode, TARGET_VAL(ISD::LOAD),
/*5557*/          OPC_RecordMemRef,
/*5558*/          OPC_RecordNode, // #3 = 'ld' chained node
/*5559*/          OPC_CheckFoldableChainNode,
/*5560*/          OPC_RecordChild1, // #4 = $dest
/*5561*/          OPC_CheckChild1Type, MVT::i64,
/*5563*/          OPC_CheckPredicate, 0, // Predicate_unindexedload
/*5565*/          OPC_MoveParent,
/*5566*/          OPC_CheckType, MVT::i64,
/*5568*/          OPC_MoveParent,
/*5569*/          OPC_CheckChild2Same, 4,
/*5571*/          OPC_CheckPredicate, 5, // Predicate_unindexedstore
/*5573*/          OPC_CheckPredicate, 25, // Predicate_block_xor1
/*5575*/          OPC_CheckComplexPat, /*CP*/1, /*#*/2, // selectBDAddr12Only:$src #5 #6
/*5578*/          OPC_CheckComplexPat, /*CP*/1, /*#*/4, // selectBDAddr12Only:$dest #7 #8
/*5581*/          OPC_EmitMergeInputChains, 3, 0, 1, 3, 
/*5586*/          OPC_EmitInteger, MVT::i64, 2, 
/*5589*/          OPC_MorphNodeTo, TARGET_VAL(SystemZ::XCSequence), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i32, 5/*#Ops*/, 7, 8, 5, 6, 9, 
                  // Src: (st (xor:i64 (ld:i64 bdaddr12only:i64:$src)<<P:Predicate_unindexedload>><<P:Predicate_anyextload>><<P:Predicate_anyextloadi16>>, (ld:i64 bdaddr12only:i64:$dest)<<P:Predicate_unindexedload>>), bdaddr12only:i64:$dest)<<P:Predicate_unindexedstore>><<P:Predicate_block_xor1>> - Complexity = 42
                  // Dst: (XCSequence:i32 bdaddr12only:i64:$dest, bdaddr12only:i64:$src, 2:i64)
/*5601*/        /*Scope*/ 54, /*->5656*/
/*5602*/          OPC_MoveParent,
/*5603*/          OPC_MoveChild, 1,
/*5605*/          OPC_CheckOpcode, TARGET_VAL(ISD::LOAD),
/*5608*/          OPC_RecordMemRef,
/*5609*/          OPC_RecordNode, // #3 = 'ld' chained node
/*5610*/          OPC_CheckFoldableChainNode,
/*5611*/          OPC_RecordChild1, // #4 = $src
/*5612*/          OPC_CheckChild1Type, MVT::i64,
/*5614*/          OPC_CheckPredicate, 0, // Predicate_unindexedload
/*5616*/          OPC_CheckPredicate, 1, // Predicate_anyextload
/*5618*/          OPC_CheckPredicate, 9, // Predicate_anyextloadi16
/*5620*/          OPC_MoveParent,
/*5621*/          OPC_CheckType, MVT::i64,
/*5623*/          OPC_MoveParent,
/*5624*/          OPC_CheckChild2Same, 2,
/*5626*/          OPC_CheckPredicate, 5, // Predicate_unindexedstore
/*5628*/          OPC_CheckPredicate, 26, // Predicate_block_xor2
/*5630*/          OPC_CheckComplexPat, /*CP*/1, /*#*/2, // selectBDAddr12Only:$dest #5 #6
/*5633*/          OPC_CheckComplexPat, /*CP*/1, /*#*/4, // selectBDAddr12Only:$src #7 #8
/*5636*/          OPC_EmitMergeInputChains, 3, 0, 1, 3, 
/*5641*/          OPC_EmitInteger, MVT::i64, 2, 
/*5644*/          OPC_MorphNodeTo, TARGET_VAL(SystemZ::XCSequence), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i32, 5/*#Ops*/, 5, 6, 7, 8, 9, 
                  // Src: (st (xor:i64 (ld:i64 bdaddr12only:i64:$dest)<<P:Predicate_unindexedload>>, (ld:i64 bdaddr12only:i64:$src)<<P:Predicate_unindexedload>><<P:Predicate_anyextload>><<P:Predicate_anyextloadi16>>), bdaddr12only:i64:$dest)<<P:Predicate_unindexedstore>><<P:Predicate_block_xor2>> - Complexity = 42
                  // Dst: (XCSequence:i32 bdaddr12only:i64:$dest, bdaddr12only:i64:$src, 2:i64)
/*5656*/        /*Scope*/ 54, /*->5711*/
/*5657*/          OPC_CheckPredicate, 1, // Predicate_anyextload
/*5659*/          OPC_CheckPredicate, 17, // Predicate_anyextloadi32
/*5661*/          OPC_MoveParent,
/*5662*/          OPC_MoveChild, 1,
/*5664*/          OPC_CheckOpcode, TARGET_VAL(ISD::LOAD),
/*5667*/          OPC_RecordMemRef,
/*5668*/          OPC_RecordNode, // #3 = 'ld' chained node
/*5669*/          OPC_CheckFoldableChainNode,
/*5670*/          OPC_RecordChild1, // #4 = $dest
/*5671*/          OPC_CheckChild1Type, MVT::i64,
/*5673*/          OPC_CheckPredicate, 0, // Predicate_unindexedload
/*5675*/          OPC_MoveParent,
/*5676*/          OPC_CheckType, MVT::i64,
/*5678*/          OPC_MoveParent,
/*5679*/          OPC_CheckChild2Same, 4,
/*5681*/          OPC_CheckPredicate, 5, // Predicate_unindexedstore
/*5683*/          OPC_CheckPredicate, 25, // Predicate_block_xor1
/*5685*/          OPC_CheckComplexPat, /*CP*/1, /*#*/2, // selectBDAddr12Only:$src #5 #6
/*5688*/          OPC_CheckComplexPat, /*CP*/1, /*#*/4, // selectBDAddr12Only:$dest #7 #8
/*5691*/          OPC_EmitMergeInputChains, 3, 0, 1, 3, 
/*5696*/          OPC_EmitInteger, MVT::i64, 4, 
/*5699*/          OPC_MorphNodeTo, TARGET_VAL(SystemZ::XCSequence), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i32, 5/*#Ops*/, 7, 8, 5, 6, 9, 
                  // Src: (st (xor:i64 (ld:i64 bdaddr12only:i64:$src)<<P:Predicate_unindexedload>><<P:Predicate_anyextload>><<P:Predicate_anyextloadi32>>, (ld:i64 bdaddr12only:i64:$dest)<<P:Predicate_unindexedload>>), bdaddr12only:i64:$dest)<<P:Predicate_unindexedstore>><<P:Predicate_block_xor1>> - Complexity = 42
                  // Dst: (XCSequence:i32 bdaddr12only:i64:$dest, bdaddr12only:i64:$src, 4:i64)
/*5711*/        /*Scope*/ 54, /*->5766*/
/*5712*/          OPC_MoveParent,
/*5713*/          OPC_MoveChild, 1,
/*5715*/          OPC_CheckOpcode, TARGET_VAL(ISD::LOAD),
/*5718*/          OPC_RecordMemRef,
/*5719*/          OPC_RecordNode, // #3 = 'ld' chained node
/*5720*/          OPC_CheckFoldableChainNode,
/*5721*/          OPC_RecordChild1, // #4 = $src
/*5722*/          OPC_CheckChild1Type, MVT::i64,
/*5724*/          OPC_CheckPredicate, 0, // Predicate_unindexedload
/*5726*/          OPC_CheckPredicate, 1, // Predicate_anyextload
/*5728*/          OPC_CheckPredicate, 17, // Predicate_anyextloadi32
/*5730*/          OPC_MoveParent,
/*5731*/          OPC_CheckType, MVT::i64,
/*5733*/          OPC_MoveParent,
/*5734*/          OPC_CheckChild2Same, 2,
/*5736*/          OPC_CheckPredicate, 5, // Predicate_unindexedstore
/*5738*/          OPC_CheckPredicate, 26, // Predicate_block_xor2
/*5740*/          OPC_CheckComplexPat, /*CP*/1, /*#*/2, // selectBDAddr12Only:$dest #5 #6
/*5743*/          OPC_CheckComplexPat, /*CP*/1, /*#*/4, // selectBDAddr12Only:$src #7 #8
/*5746*/          OPC_EmitMergeInputChains, 3, 0, 1, 3, 
/*5751*/          OPC_EmitInteger, MVT::i64, 4, 
/*5754*/          OPC_MorphNodeTo, TARGET_VAL(SystemZ::XCSequence), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i32, 5/*#Ops*/, 5, 6, 7, 8, 9, 
                  // Src: (st (xor:i64 (ld:i64 bdaddr12only:i64:$dest)<<P:Predicate_unindexedload>>, (ld:i64 bdaddr12only:i64:$src)<<P:Predicate_unindexedload>><<P:Predicate_anyextload>><<P:Predicate_anyextloadi32>>), bdaddr12only:i64:$dest)<<P:Predicate_unindexedstore>><<P:Predicate_block_xor2>> - Complexity = 42
                  // Dst: (XCSequence:i32 bdaddr12only:i64:$dest, bdaddr12only:i64:$src, 4:i64)
/*5766*/        /*Scope*/ 52, /*->5819*/
/*5767*/          OPC_CheckPredicate, 13, // Predicate_load
/*5769*/          OPC_MoveParent,
/*5770*/          OPC_MoveChild, 1,
/*5772*/          OPC_CheckOpcode, TARGET_VAL(ISD::LOAD),
/*5775*/          OPC_RecordMemRef,
/*5776*/          OPC_RecordNode, // #3 = 'ld' chained node
/*5777*/          OPC_CheckFoldableChainNode,
/*5778*/          OPC_RecordChild1, // #4 = $dest
/*5779*/          OPC_CheckChild1Type, MVT::i64,
/*5781*/          OPC_CheckPredicate, 0, // Predicate_unindexedload
/*5783*/          OPC_MoveParent,
/*5784*/          OPC_CheckType, MVT::i64,
/*5786*/          OPC_MoveParent,
/*5787*/          OPC_CheckChild2Same, 4,
/*5789*/          OPC_CheckPredicate, 5, // Predicate_unindexedstore
/*5791*/          OPC_CheckPredicate, 25, // Predicate_block_xor1
/*5793*/          OPC_CheckComplexPat, /*CP*/1, /*#*/2, // selectBDAddr12Only:$src #5 #6
/*5796*/          OPC_CheckComplexPat, /*CP*/1, /*#*/4, // selectBDAddr12Only:$dest #7 #8
/*5799*/          OPC_EmitMergeInputChains, 3, 0, 1, 3, 
/*5804*/          OPC_EmitInteger, MVT::i64, 8, 
/*5807*/          OPC_MorphNodeTo, TARGET_VAL(SystemZ::XCSequence), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i32, 5/*#Ops*/, 7, 8, 5, 6, 9, 
                  // Src: (st (xor:i64 (ld:i64 bdaddr12only:i64:$src)<<P:Predicate_unindexedload>><<P:Predicate_load>>, (ld:i64 bdaddr12only:i64:$dest)<<P:Predicate_unindexedload>>), bdaddr12only:i64:$dest)<<P:Predicate_unindexedstore>><<P:Predicate_block_xor1>> - Complexity = 42
                  // Dst: (XCSequence:i32 bdaddr12only:i64:$dest, bdaddr12only:i64:$src, 8:i64)
/*5819*/        /*Scope*/ 96, /*->5916*/
/*5820*/          OPC_MoveParent,
/*5821*/          OPC_MoveChild, 1,
/*5823*/          OPC_CheckOpcode, TARGET_VAL(ISD::LOAD),
/*5826*/          OPC_RecordMemRef,
/*5827*/          OPC_RecordNode, // #3 = 'ld' chained node
/*5828*/          OPC_CheckFoldableChainNode,
/*5829*/          OPC_RecordChild1, // #4 = $src
/*5830*/          OPC_CheckChild1Type, MVT::i64,
/*5832*/          OPC_CheckPredicate, 0, // Predicate_unindexedload
/*5834*/          OPC_Scope, 38, /*->5874*/ // 2 children in Scope
/*5836*/            OPC_CheckPredicate, 13, // Predicate_load
/*5838*/            OPC_MoveParent,
/*5839*/            OPC_CheckType, MVT::i64,
/*5841*/            OPC_MoveParent,
/*5842*/            OPC_CheckChild2Same, 2,
/*5844*/            OPC_CheckPredicate, 5, // Predicate_unindexedstore
/*5846*/            OPC_CheckPredicate, 26, // Predicate_block_xor2
/*5848*/            OPC_CheckComplexPat, /*CP*/1, /*#*/2, // selectBDAddr12Only:$dest #5 #6
/*5851*/            OPC_CheckComplexPat, /*CP*/1, /*#*/4, // selectBDAddr12Only:$src #7 #8
/*5854*/            OPC_EmitMergeInputChains, 3, 0, 1, 3, 
/*5859*/            OPC_EmitInteger, MVT::i64, 8, 
/*5862*/            OPC_MorphNodeTo, TARGET_VAL(SystemZ::XCSequence), 0|OPFL_Chain|OPFL_MemRefs,
                        1/*#VTs*/, MVT::i32, 5/*#Ops*/, 5, 6, 7, 8, 9, 
                    // Src: (st (xor:i64 (ld:i64 bdaddr12only:i64:$dest)<<P:Predicate_unindexedload>>, (ld:i64 bdaddr12only:i64:$src)<<P:Predicate_unindexedload>><<P:Predicate_load>>), bdaddr12only:i64:$dest)<<P:Predicate_unindexedstore>><<P:Predicate_block_xor2>> - Complexity = 42
                    // Dst: (XCSequence:i32 bdaddr12only:i64:$dest, bdaddr12only:i64:$src, 8:i64)
/*5874*/          /*Scope*/ 40, /*->5915*/
/*5875*/            OPC_CheckPredicate, 1, // Predicate_anyextload
/*5877*/            OPC_CheckPredicate, 2, // Predicate_anyextloadi8
/*5879*/            OPC_MoveParent,
/*5880*/            OPC_CheckType, MVT::i32,
/*5882*/            OPC_MoveParent,
/*5883*/            OPC_CheckChild2Same, 2,
/*5885*/            OPC_CheckPredicate, 5, // Predicate_unindexedstore
/*5887*/            OPC_CheckPredicate, 25, // Predicate_block_xor1
/*5889*/            OPC_CheckComplexPat, /*CP*/1, /*#*/2, // selectBDAddr12Only:$dest #5 #6
/*5892*/            OPC_CheckComplexPat, /*CP*/1, /*#*/4, // selectBDAddr12Only:$src #7 #8
/*5895*/            OPC_EmitMergeInputChains, 3, 0, 1, 3, 
/*5900*/            OPC_EmitInteger, MVT::i64, 1, 
/*5903*/            OPC_MorphNodeTo, TARGET_VAL(SystemZ::XCSequence), 0|OPFL_Chain|OPFL_MemRefs,
                        1/*#VTs*/, MVT::i32, 5/*#Ops*/, 5, 6, 7, 8, 9, 
                    // Src: (st (xor:i32 (ld:i32 bdaddr12only:i64:$dest)<<P:Predicate_unindexedload>>, (ld:i32 bdaddr12only:i64:$src)<<P:Predicate_unindexedload>><<P:Predicate_anyextload>><<P:Predicate_anyextloadi8>>), bdaddr12only:i64:$dest)<<P:Predicate_unindexedstore>><<P:Predicate_block_xor1>> - Complexity = 42
                    // Dst: (XCSequence:i32 bdaddr12only:i64:$dest, bdaddr12only:i64:$src, 1:i64)
/*5915*/          0, /*End of Scope*/
/*5916*/        /*Scope*/ 54, /*->5971*/
/*5917*/          OPC_CheckPredicate, 1, // Predicate_anyextload
/*5919*/          OPC_CheckPredicate, 2, // Predicate_anyextloadi8
/*5921*/          OPC_MoveParent,
/*5922*/          OPC_MoveChild, 1,
/*5924*/          OPC_CheckOpcode, TARGET_VAL(ISD::LOAD),
/*5927*/          OPC_RecordMemRef,
/*5928*/          OPC_RecordNode, // #3 = 'ld' chained node
/*5929*/          OPC_CheckFoldableChainNode,
/*5930*/          OPC_RecordChild1, // #4 = $dest
/*5931*/          OPC_CheckChild1Type, MVT::i64,
/*5933*/          OPC_CheckPredicate, 0, // Predicate_unindexedload
/*5935*/          OPC_MoveParent,
/*5936*/          OPC_CheckType, MVT::i32,
/*5938*/          OPC_MoveParent,
/*5939*/          OPC_CheckChild2Same, 4,
/*5941*/          OPC_CheckPredicate, 5, // Predicate_unindexedstore
/*5943*/          OPC_CheckPredicate, 26, // Predicate_block_xor2
/*5945*/          OPC_CheckComplexPat, /*CP*/1, /*#*/2, // selectBDAddr12Only:$src #5 #6
/*5948*/          OPC_CheckComplexPat, /*CP*/1, /*#*/4, // selectBDAddr12Only:$dest #7 #8
/*5951*/          OPC_EmitMergeInputChains, 3, 0, 1, 3, 
/*5956*/          OPC_EmitInteger, MVT::i64, 1, 
/*5959*/          OPC_MorphNodeTo, TARGET_VAL(SystemZ::XCSequence), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i32, 5/*#Ops*/, 7, 8, 5, 6, 9, 
                  // Src: (st (xor:i32 (ld:i32 bdaddr12only:i64:$src)<<P:Predicate_unindexedload>><<P:Predicate_anyextload>><<P:Predicate_anyextloadi8>>, (ld:i32 bdaddr12only:i64:$dest)<<P:Predicate_unindexedload>>), bdaddr12only:i64:$dest)<<P:Predicate_unindexedstore>><<P:Predicate_block_xor2>> - Complexity = 42
                  // Dst: (XCSequence:i32 bdaddr12only:i64:$dest, bdaddr12only:i64:$src, 1:i64)
/*5971*/        /*Scope*/ 54, /*->6026*/
/*5972*/          OPC_MoveParent,
/*5973*/          OPC_MoveChild, 1,
/*5975*/          OPC_CheckOpcode, TARGET_VAL(ISD::LOAD),
/*5978*/          OPC_RecordMemRef,
/*5979*/          OPC_RecordNode, // #3 = 'ld' chained node
/*5980*/          OPC_CheckFoldableChainNode,
/*5981*/          OPC_RecordChild1, // #4 = $src
/*5982*/          OPC_CheckChild1Type, MVT::i64,
/*5984*/          OPC_CheckPredicate, 0, // Predicate_unindexedload
/*5986*/          OPC_CheckPredicate, 1, // Predicate_anyextload
/*5988*/          OPC_CheckPredicate, 9, // Predicate_anyextloadi16
/*5990*/          OPC_MoveParent,
/*5991*/          OPC_CheckType, MVT::i32,
/*5993*/          OPC_MoveParent,
/*5994*/          OPC_CheckChild2Same, 2,
/*5996*/          OPC_CheckPredicate, 5, // Predicate_unindexedstore
/*5998*/          OPC_CheckPredicate, 25, // Predicate_block_xor1
/*6000*/          OPC_CheckComplexPat, /*CP*/1, /*#*/2, // selectBDAddr12Only:$dest #5 #6
/*6003*/          OPC_CheckComplexPat, /*CP*/1, /*#*/4, // selectBDAddr12Only:$src #7 #8
/*6006*/          OPC_EmitMergeInputChains, 3, 0, 1, 3, 
/*6011*/          OPC_EmitInteger, MVT::i64, 2, 
/*6014*/          OPC_MorphNodeTo, TARGET_VAL(SystemZ::XCSequence), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i32, 5/*#Ops*/, 5, 6, 7, 8, 9, 
                  // Src: (st (xor:i32 (ld:i32 bdaddr12only:i64:$dest)<<P:Predicate_unindexedload>>, (ld:i32 bdaddr12only:i64:$src)<<P:Predicate_unindexedload>><<P:Predicate_anyextload>><<P:Predicate_anyextloadi16>>), bdaddr12only:i64:$dest)<<P:Predicate_unindexedstore>><<P:Predicate_block_xor1>> - Complexity = 42
                  // Dst: (XCSequence:i32 bdaddr12only:i64:$dest, bdaddr12only:i64:$src, 2:i64)
/*6026*/        /*Scope*/ 54, /*->6081*/
/*6027*/          OPC_CheckPredicate, 1, // Predicate_anyextload
/*6029*/          OPC_CheckPredicate, 9, // Predicate_anyextloadi16
/*6031*/          OPC_MoveParent,
/*6032*/          OPC_MoveChild, 1,
/*6034*/          OPC_CheckOpcode, TARGET_VAL(ISD::LOAD),
/*6037*/          OPC_RecordMemRef,
/*6038*/          OPC_RecordNode, // #3 = 'ld' chained node
/*6039*/          OPC_CheckFoldableChainNode,
/*6040*/          OPC_RecordChild1, // #4 = $dest
/*6041*/          OPC_CheckChild1Type, MVT::i64,
/*6043*/          OPC_CheckPredicate, 0, // Predicate_unindexedload
/*6045*/          OPC_MoveParent,
/*6046*/          OPC_CheckType, MVT::i32,
/*6048*/          OPC_MoveParent,
/*6049*/          OPC_CheckChild2Same, 4,
/*6051*/          OPC_CheckPredicate, 5, // Predicate_unindexedstore
/*6053*/          OPC_CheckPredicate, 26, // Predicate_block_xor2
/*6055*/          OPC_CheckComplexPat, /*CP*/1, /*#*/2, // selectBDAddr12Only:$src #5 #6
/*6058*/          OPC_CheckComplexPat, /*CP*/1, /*#*/4, // selectBDAddr12Only:$dest #7 #8
/*6061*/          OPC_EmitMergeInputChains, 3, 0, 1, 3, 
/*6066*/          OPC_EmitInteger, MVT::i64, 2, 
/*6069*/          OPC_MorphNodeTo, TARGET_VAL(SystemZ::XCSequence), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i32, 5/*#Ops*/, 7, 8, 5, 6, 9, 
                  // Src: (st (xor:i32 (ld:i32 bdaddr12only:i64:$src)<<P:Predicate_unindexedload>><<P:Predicate_anyextload>><<P:Predicate_anyextloadi16>>, (ld:i32 bdaddr12only:i64:$dest)<<P:Predicate_unindexedload>>), bdaddr12only:i64:$dest)<<P:Predicate_unindexedstore>><<P:Predicate_block_xor2>> - Complexity = 42
                  // Dst: (XCSequence:i32 bdaddr12only:i64:$dest, bdaddr12only:i64:$src, 2:i64)
/*6081*/        /*Scope*/ 52, /*->6134*/
/*6082*/          OPC_MoveParent,
/*6083*/          OPC_MoveChild, 1,
/*6085*/          OPC_CheckOpcode, TARGET_VAL(ISD::LOAD),
/*6088*/          OPC_RecordMemRef,
/*6089*/          OPC_RecordNode, // #3 = 'ld' chained node
/*6090*/          OPC_CheckFoldableChainNode,
/*6091*/          OPC_RecordChild1, // #4 = $src
/*6092*/          OPC_CheckChild1Type, MVT::i64,
/*6094*/          OPC_CheckPredicate, 0, // Predicate_unindexedload
/*6096*/          OPC_CheckPredicate, 13, // Predicate_load
/*6098*/          OPC_MoveParent,
/*6099*/          OPC_CheckType, MVT::i32,
/*6101*/          OPC_MoveParent,
/*6102*/          OPC_CheckChild2Same, 2,
/*6104*/          OPC_CheckPredicate, 5, // Predicate_unindexedstore
/*6106*/          OPC_CheckPredicate, 25, // Predicate_block_xor1
/*6108*/          OPC_CheckComplexPat, /*CP*/1, /*#*/2, // selectBDAddr12Only:$dest #5 #6
/*6111*/          OPC_CheckComplexPat, /*CP*/1, /*#*/4, // selectBDAddr12Only:$src #7 #8
/*6114*/          OPC_EmitMergeInputChains, 3, 0, 1, 3, 
/*6119*/          OPC_EmitInteger, MVT::i64, 4, 
/*6122*/          OPC_MorphNodeTo, TARGET_VAL(SystemZ::XCSequence), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i32, 5/*#Ops*/, 5, 6, 7, 8, 9, 
                  // Src: (st (xor:i32 (ld:i32 bdaddr12only:i64:$dest)<<P:Predicate_unindexedload>>, (ld:i32 bdaddr12only:i64:$src)<<P:Predicate_unindexedload>><<P:Predicate_load>>), bdaddr12only:i64:$dest)<<P:Predicate_unindexedstore>><<P:Predicate_block_xor1>> - Complexity = 42
                  // Dst: (XCSequence:i32 bdaddr12only:i64:$dest, bdaddr12only:i64:$src, 4:i64)
/*6134*/        /*Scope*/ 52, /*->6187*/
/*6135*/          OPC_CheckPredicate, 13, // Predicate_load
/*6137*/          OPC_MoveParent,
/*6138*/          OPC_MoveChild, 1,
/*6140*/          OPC_CheckOpcode, TARGET_VAL(ISD::LOAD),
/*6143*/          OPC_RecordMemRef,
/*6144*/          OPC_RecordNode, // #3 = 'ld' chained node
/*6145*/          OPC_CheckFoldableChainNode,
/*6146*/          OPC_RecordChild1, // #4 = $dest
/*6147*/          OPC_CheckChild1Type, MVT::i64,
/*6149*/          OPC_CheckPredicate, 0, // Predicate_unindexedload
/*6151*/          OPC_MoveParent,
/*6152*/          OPC_CheckType, MVT::i32,
/*6154*/          OPC_MoveParent,
/*6155*/          OPC_CheckChild2Same, 4,
/*6157*/          OPC_CheckPredicate, 5, // Predicate_unindexedstore
/*6159*/          OPC_CheckPredicate, 26, // Predicate_block_xor2
/*6161*/          OPC_CheckComplexPat, /*CP*/1, /*#*/2, // selectBDAddr12Only:$src #5 #6
/*6164*/          OPC_CheckComplexPat, /*CP*/1, /*#*/4, // selectBDAddr12Only:$dest #7 #8
/*6167*/          OPC_EmitMergeInputChains, 3, 0, 1, 3, 
/*6172*/          OPC_EmitInteger, MVT::i64, 4, 
/*6175*/          OPC_MorphNodeTo, TARGET_VAL(SystemZ::XCSequence), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i32, 5/*#Ops*/, 7, 8, 5, 6, 9, 
                  // Src: (st (xor:i32 (ld:i32 bdaddr12only:i64:$src)<<P:Predicate_unindexedload>><<P:Predicate_load>>, (ld:i32 bdaddr12only:i64:$dest)<<P:Predicate_unindexedload>>), bdaddr12only:i64:$dest)<<P:Predicate_unindexedstore>><<P:Predicate_block_xor2>> - Complexity = 42
                  // Dst: (XCSequence:i32 bdaddr12only:i64:$dest, bdaddr12only:i64:$src, 4:i64)
/*6187*/        /*Scope*/ 54, /*->6242*/
/*6188*/          OPC_MoveParent,
/*6189*/          OPC_MoveChild, 1,
/*6191*/          OPC_CheckOpcode, TARGET_VAL(ISD::LOAD),
/*6194*/          OPC_RecordMemRef,
/*6195*/          OPC_RecordNode, // #3 = 'ld' chained node
/*6196*/          OPC_CheckFoldableChainNode,
/*6197*/          OPC_RecordChild1, // #4 = $src
/*6198*/          OPC_CheckChild1Type, MVT::i64,
/*6200*/          OPC_CheckPredicate, 0, // Predicate_unindexedload
/*6202*/          OPC_CheckPredicate, 1, // Predicate_anyextload
/*6204*/          OPC_CheckPredicate, 2, // Predicate_anyextloadi8
/*6206*/          OPC_MoveParent,
/*6207*/          OPC_CheckType, MVT::i64,
/*6209*/          OPC_MoveParent,
/*6210*/          OPC_CheckChild2Same, 2,
/*6212*/          OPC_CheckPredicate, 5, // Predicate_unindexedstore
/*6214*/          OPC_CheckPredicate, 25, // Predicate_block_xor1
/*6216*/          OPC_CheckComplexPat, /*CP*/1, /*#*/2, // selectBDAddr12Only:$dest #5 #6
/*6219*/          OPC_CheckComplexPat, /*CP*/1, /*#*/4, // selectBDAddr12Only:$src #7 #8
/*6222*/          OPC_EmitMergeInputChains, 3, 0, 1, 3, 
/*6227*/          OPC_EmitInteger, MVT::i64, 1, 
/*6230*/          OPC_MorphNodeTo, TARGET_VAL(SystemZ::XCSequence), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i32, 5/*#Ops*/, 5, 6, 7, 8, 9, 
                  // Src: (st (xor:i64 (ld:i64 bdaddr12only:i64:$dest)<<P:Predicate_unindexedload>>, (ld:i64 bdaddr12only:i64:$src)<<P:Predicate_unindexedload>><<P:Predicate_anyextload>><<P:Predicate_anyextloadi8>>), bdaddr12only:i64:$dest)<<P:Predicate_unindexedstore>><<P:Predicate_block_xor1>> - Complexity = 42
                  // Dst: (XCSequence:i32 bdaddr12only:i64:$dest, bdaddr12only:i64:$src, 1:i64)
/*6242*/        /*Scope*/ 54, /*->6297*/
/*6243*/          OPC_CheckPredicate, 1, // Predicate_anyextload
/*6245*/          OPC_CheckPredicate, 2, // Predicate_anyextloadi8
/*6247*/          OPC_MoveParent,
/*6248*/          OPC_MoveChild, 1,
/*6250*/          OPC_CheckOpcode, TARGET_VAL(ISD::LOAD),
/*6253*/          OPC_RecordMemRef,
/*6254*/          OPC_RecordNode, // #3 = 'ld' chained node
/*6255*/          OPC_CheckFoldableChainNode,
/*6256*/          OPC_RecordChild1, // #4 = $dest
/*6257*/          OPC_CheckChild1Type, MVT::i64,
/*6259*/          OPC_CheckPredicate, 0, // Predicate_unindexedload
/*6261*/          OPC_MoveParent,
/*6262*/          OPC_CheckType, MVT::i64,
/*6264*/          OPC_MoveParent,
/*6265*/          OPC_CheckChild2Same, 4,
/*6267*/          OPC_CheckPredicate, 5, // Predicate_unindexedstore
/*6269*/          OPC_CheckPredicate, 26, // Predicate_block_xor2
/*6271*/          OPC_CheckComplexPat, /*CP*/1, /*#*/2, // selectBDAddr12Only:$src #5 #6
/*6274*/          OPC_CheckComplexPat, /*CP*/1, /*#*/4, // selectBDAddr12Only:$dest #7 #8
/*6277*/          OPC_EmitMergeInputChains, 3, 0, 1, 3, 
/*6282*/          OPC_EmitInteger, MVT::i64, 1, 
/*6285*/          OPC_MorphNodeTo, TARGET_VAL(SystemZ::XCSequence), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i32, 5/*#Ops*/, 7, 8, 5, 6, 9, 
                  // Src: (st (xor:i64 (ld:i64 bdaddr12only:i64:$src)<<P:Predicate_unindexedload>><<P:Predicate_anyextload>><<P:Predicate_anyextloadi8>>, (ld:i64 bdaddr12only:i64:$dest)<<P:Predicate_unindexedload>>), bdaddr12only:i64:$dest)<<P:Predicate_unindexedstore>><<P:Predicate_block_xor2>> - Complexity = 42
                  // Dst: (XCSequence:i32 bdaddr12only:i64:$dest, bdaddr12only:i64:$src, 1:i64)
/*6297*/        /*Scope*/ 54, /*->6352*/
/*6298*/          OPC_MoveParent,
/*6299*/          OPC_MoveChild, 1,
/*6301*/          OPC_CheckOpcode, TARGET_VAL(ISD::LOAD),
/*6304*/          OPC_RecordMemRef,
/*6305*/          OPC_RecordNode, // #3 = 'ld' chained node
/*6306*/          OPC_CheckFoldableChainNode,
/*6307*/          OPC_RecordChild1, // #4 = $src
/*6308*/          OPC_CheckChild1Type, MVT::i64,
/*6310*/          OPC_CheckPredicate, 0, // Predicate_unindexedload
/*6312*/          OPC_CheckPredicate, 1, // Predicate_anyextload
/*6314*/          OPC_CheckPredicate, 9, // Predicate_anyextloadi16
/*6316*/          OPC_MoveParent,
/*6317*/          OPC_CheckType, MVT::i64,
/*6319*/          OPC_MoveParent,
/*6320*/          OPC_CheckChild2Same, 2,
/*6322*/          OPC_CheckPredicate, 5, // Predicate_unindexedstore
/*6324*/          OPC_CheckPredicate, 25, // Predicate_block_xor1
/*6326*/          OPC_CheckComplexPat, /*CP*/1, /*#*/2, // selectBDAddr12Only:$dest #5 #6
/*6329*/          OPC_CheckComplexPat, /*CP*/1, /*#*/4, // selectBDAddr12Only:$src #7 #8
/*6332*/          OPC_EmitMergeInputChains, 3, 0, 1, 3, 
/*6337*/          OPC_EmitInteger, MVT::i64, 2, 
/*6340*/          OPC_MorphNodeTo, TARGET_VAL(SystemZ::XCSequence), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i32, 5/*#Ops*/, 5, 6, 7, 8, 9, 
                  // Src: (st (xor:i64 (ld:i64 bdaddr12only:i64:$dest)<<P:Predicate_unindexedload>>, (ld:i64 bdaddr12only:i64:$src)<<P:Predicate_unindexedload>><<P:Predicate_anyextload>><<P:Predicate_anyextloadi16>>), bdaddr12only:i64:$dest)<<P:Predicate_unindexedstore>><<P:Predicate_block_xor1>> - Complexity = 42
                  // Dst: (XCSequence:i32 bdaddr12only:i64:$dest, bdaddr12only:i64:$src, 2:i64)
/*6352*/        /*Scope*/ 54, /*->6407*/
/*6353*/          OPC_CheckPredicate, 1, // Predicate_anyextload
/*6355*/          OPC_CheckPredicate, 9, // Predicate_anyextloadi16
/*6357*/          OPC_MoveParent,
/*6358*/          OPC_MoveChild, 1,
/*6360*/          OPC_CheckOpcode, TARGET_VAL(ISD::LOAD),
/*6363*/          OPC_RecordMemRef,
/*6364*/          OPC_RecordNode, // #3 = 'ld' chained node
/*6365*/          OPC_CheckFoldableChainNode,
/*6366*/          OPC_RecordChild1, // #4 = $dest
/*6367*/          OPC_CheckChild1Type, MVT::i64,
/*6369*/          OPC_CheckPredicate, 0, // Predicate_unindexedload
/*6371*/          OPC_MoveParent,
/*6372*/          OPC_CheckType, MVT::i64,
/*6374*/          OPC_MoveParent,
/*6375*/          OPC_CheckChild2Same, 4,
/*6377*/          OPC_CheckPredicate, 5, // Predicate_unindexedstore
/*6379*/          OPC_CheckPredicate, 26, // Predicate_block_xor2
/*6381*/          OPC_CheckComplexPat, /*CP*/1, /*#*/2, // selectBDAddr12Only:$src #5 #6
/*6384*/          OPC_CheckComplexPat, /*CP*/1, /*#*/4, // selectBDAddr12Only:$dest #7 #8
/*6387*/          OPC_EmitMergeInputChains, 3, 0, 1, 3, 
/*6392*/          OPC_EmitInteger, MVT::i64, 2, 
/*6395*/          OPC_MorphNodeTo, TARGET_VAL(SystemZ::XCSequence), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i32, 5/*#Ops*/, 7, 8, 5, 6, 9, 
                  // Src: (st (xor:i64 (ld:i64 bdaddr12only:i64:$src)<<P:Predicate_unindexedload>><<P:Predicate_anyextload>><<P:Predicate_anyextloadi16>>, (ld:i64 bdaddr12only:i64:$dest)<<P:Predicate_unindexedload>>), bdaddr12only:i64:$dest)<<P:Predicate_unindexedstore>><<P:Predicate_block_xor2>> - Complexity = 42
                  // Dst: (XCSequence:i32 bdaddr12only:i64:$dest, bdaddr12only:i64:$src, 2:i64)
/*6407*/        /*Scope*/ 54, /*->6462*/
/*6408*/          OPC_MoveParent,
/*6409*/          OPC_MoveChild, 1,
/*6411*/          OPC_CheckOpcode, TARGET_VAL(ISD::LOAD),
/*6414*/          OPC_RecordMemRef,
/*6415*/          OPC_RecordNode, // #3 = 'ld' chained node
/*6416*/          OPC_CheckFoldableChainNode,
/*6417*/          OPC_RecordChild1, // #4 = $src
/*6418*/          OPC_CheckChild1Type, MVT::i64,
/*6420*/          OPC_CheckPredicate, 0, // Predicate_unindexedload
/*6422*/          OPC_CheckPredicate, 1, // Predicate_anyextload
/*6424*/          OPC_CheckPredicate, 17, // Predicate_anyextloadi32
/*6426*/          OPC_MoveParent,
/*6427*/          OPC_CheckType, MVT::i64,
/*6429*/          OPC_MoveParent,
/*6430*/          OPC_CheckChild2Same, 2,
/*6432*/          OPC_CheckPredicate, 5, // Predicate_unindexedstore
/*6434*/          OPC_CheckPredicate, 25, // Predicate_block_xor1
/*6436*/          OPC_CheckComplexPat, /*CP*/1, /*#*/2, // selectBDAddr12Only:$dest #5 #6
/*6439*/          OPC_CheckComplexPat, /*CP*/1, /*#*/4, // selectBDAddr12Only:$src #7 #8
/*6442*/          OPC_EmitMergeInputChains, 3, 0, 1, 3, 
/*6447*/          OPC_EmitInteger, MVT::i64, 4, 
/*6450*/          OPC_MorphNodeTo, TARGET_VAL(SystemZ::XCSequence), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i32, 5/*#Ops*/, 5, 6, 7, 8, 9, 
                  // Src: (st (xor:i64 (ld:i64 bdaddr12only:i64:$dest)<<P:Predicate_unindexedload>>, (ld:i64 bdaddr12only:i64:$src)<<P:Predicate_unindexedload>><<P:Predicate_anyextload>><<P:Predicate_anyextloadi32>>), bdaddr12only:i64:$dest)<<P:Predicate_unindexedstore>><<P:Predicate_block_xor1>> - Complexity = 42
                  // Dst: (XCSequence:i32 bdaddr12only:i64:$dest, bdaddr12only:i64:$src, 4:i64)
/*6462*/        /*Scope*/ 54, /*->6517*/
/*6463*/          OPC_CheckPredicate, 1, // Predicate_anyextload
/*6465*/          OPC_CheckPredicate, 17, // Predicate_anyextloadi32
/*6467*/          OPC_MoveParent,
/*6468*/          OPC_MoveChild, 1,
/*6470*/          OPC_CheckOpcode, TARGET_VAL(ISD::LOAD),
/*6473*/          OPC_RecordMemRef,
/*6474*/          OPC_RecordNode, // #3 = 'ld' chained node
/*6475*/          OPC_CheckFoldableChainNode,
/*6476*/          OPC_RecordChild1, // #4 = $dest
/*6477*/          OPC_CheckChild1Type, MVT::i64,
/*6479*/          OPC_CheckPredicate, 0, // Predicate_unindexedload
/*6481*/          OPC_MoveParent,
/*6482*/          OPC_CheckType, MVT::i64,
/*6484*/          OPC_MoveParent,
/*6485*/          OPC_CheckChild2Same, 4,
/*6487*/          OPC_CheckPredicate, 5, // Predicate_unindexedstore
/*6489*/          OPC_CheckPredicate, 26, // Predicate_block_xor2
/*6491*/          OPC_CheckComplexPat, /*CP*/1, /*#*/2, // selectBDAddr12Only:$src #5 #6
/*6494*/          OPC_CheckComplexPat, /*CP*/1, /*#*/4, // selectBDAddr12Only:$dest #7 #8
/*6497*/          OPC_EmitMergeInputChains, 3, 0, 1, 3, 
/*6502*/          OPC_EmitInteger, MVT::i64, 4, 
/*6505*/          OPC_MorphNodeTo, TARGET_VAL(SystemZ::XCSequence), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i32, 5/*#Ops*/, 7, 8, 5, 6, 9, 
                  // Src: (st (xor:i64 (ld:i64 bdaddr12only:i64:$src)<<P:Predicate_unindexedload>><<P:Predicate_anyextload>><<P:Predicate_anyextloadi32>>, (ld:i64 bdaddr12only:i64:$dest)<<P:Predicate_unindexedload>>), bdaddr12only:i64:$dest)<<P:Predicate_unindexedstore>><<P:Predicate_block_xor2>> - Complexity = 42
                  // Dst: (XCSequence:i32 bdaddr12only:i64:$dest, bdaddr12only:i64:$src, 4:i64)
/*6517*/        /*Scope*/ 52, /*->6570*/
/*6518*/          OPC_MoveParent,
/*6519*/          OPC_MoveChild, 1,
/*6521*/          OPC_CheckOpcode, TARGET_VAL(ISD::LOAD),
/*6524*/          OPC_RecordMemRef,
/*6525*/          OPC_RecordNode, // #3 = 'ld' chained node
/*6526*/          OPC_CheckFoldableChainNode,
/*6527*/          OPC_RecordChild1, // #4 = $src
/*6528*/          OPC_CheckChild1Type, MVT::i64,
/*6530*/          OPC_CheckPredicate, 0, // Predicate_unindexedload
/*6532*/          OPC_CheckPredicate, 13, // Predicate_load
/*6534*/          OPC_MoveParent,
/*6535*/          OPC_CheckType, MVT::i64,
/*6537*/          OPC_MoveParent,
/*6538*/          OPC_CheckChild2Same, 2,
/*6540*/          OPC_CheckPredicate, 5, // Predicate_unindexedstore
/*6542*/          OPC_CheckPredicate, 25, // Predicate_block_xor1
/*6544*/          OPC_CheckComplexPat, /*CP*/1, /*#*/2, // selectBDAddr12Only:$dest #5 #6
/*6547*/          OPC_CheckComplexPat, /*CP*/1, /*#*/4, // selectBDAddr12Only:$src #7 #8
/*6550*/          OPC_EmitMergeInputChains, 3, 0, 1, 3, 
/*6555*/          OPC_EmitInteger, MVT::i64, 8, 
/*6558*/          OPC_MorphNodeTo, TARGET_VAL(SystemZ::XCSequence), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i32, 5/*#Ops*/, 5, 6, 7, 8, 9, 
                  // Src: (st (xor:i64 (ld:i64 bdaddr12only:i64:$dest)<<P:Predicate_unindexedload>>, (ld:i64 bdaddr12only:i64:$src)<<P:Predicate_unindexedload>><<P:Predicate_load>>), bdaddr12only:i64:$dest)<<P:Predicate_unindexedstore>><<P:Predicate_block_xor1>> - Complexity = 42
                  // Dst: (XCSequence:i32 bdaddr12only:i64:$dest, bdaddr12only:i64:$src, 8:i64)
/*6570*/        /*Scope*/ 52, /*->6623*/
/*6571*/          OPC_CheckPredicate, 13, // Predicate_load
/*6573*/          OPC_MoveParent,
/*6574*/          OPC_MoveChild, 1,
/*6576*/          OPC_CheckOpcode, TARGET_VAL(ISD::LOAD),
/*6579*/          OPC_RecordMemRef,
/*6580*/          OPC_RecordNode, // #3 = 'ld' chained node
/*6581*/          OPC_CheckFoldableChainNode,
/*6582*/          OPC_RecordChild1, // #4 = $dest
/*6583*/          OPC_CheckChild1Type, MVT::i64,
/*6585*/          OPC_CheckPredicate, 0, // Predicate_unindexedload
/*6587*/          OPC_MoveParent,
/*6588*/          OPC_CheckType, MVT::i64,
/*6590*/          OPC_MoveParent,
/*6591*/          OPC_CheckChild2Same, 4,
/*6593*/          OPC_CheckPredicate, 5, // Predicate_unindexedstore
/*6595*/          OPC_CheckPredicate, 26, // Predicate_block_xor2
/*6597*/          OPC_CheckComplexPat, /*CP*/1, /*#*/2, // selectBDAddr12Only:$src #5 #6
/*6600*/          OPC_CheckComplexPat, /*CP*/1, /*#*/4, // selectBDAddr12Only:$dest #7 #8
/*6603*/          OPC_EmitMergeInputChains, 3, 0, 1, 3, 
/*6608*/          OPC_EmitInteger, MVT::i64, 8, 
/*6611*/          OPC_MorphNodeTo, TARGET_VAL(SystemZ::XCSequence), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i32, 5/*#Ops*/, 7, 8, 5, 6, 9, 
                  // Src: (st (xor:i64 (ld:i64 bdaddr12only:i64:$src)<<P:Predicate_unindexedload>><<P:Predicate_load>>, (ld:i64 bdaddr12only:i64:$dest)<<P:Predicate_unindexedload>>), bdaddr12only:i64:$dest)<<P:Predicate_unindexedstore>><<P:Predicate_block_xor2>> - Complexity = 42
                  // Dst: (XCSequence:i32 bdaddr12only:i64:$dest, bdaddr12only:i64:$src, 8:i64)
/*6623*/        /*Scope*/ 4|128,1/*132*/, /*->6757*/
/*6625*/          OPC_CheckPredicate, 1, // Predicate_anyextload
/*6627*/          OPC_CheckPredicate, 2, // Predicate_anyextloadi8
/*6629*/          OPC_MoveParent,
/*6630*/          OPC_RecordChild1, // #3 = $src
/*6631*/          OPC_MoveChild, 1,
/*6633*/          OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*6636*/          OPC_MoveParent,
/*6637*/          OPC_SwitchType /*2 cases */, 57,  MVT::i32,// ->6697
/*6640*/            OPC_MoveParent,
/*6641*/            OPC_CheckChild2Same, 2,
/*6643*/            OPC_CheckPredicate, 5, // Predicate_unindexedstore
/*6645*/            OPC_CheckPredicate, 6, // Predicate_truncstore
/*6647*/            OPC_CheckPredicate, 7, // Predicate_truncstorei8
/*6649*/            OPC_Scope, 22, /*->6673*/ // 2 children in Scope
/*6651*/              OPC_CheckComplexPat, /*CP*/2, /*#*/2, // selectBDAddr12Pair:$addr #4 #5
/*6654*/              OPC_EmitMergeInputChains, 2, 0, 1, 
/*6658*/              OPC_EmitConvertToTarget, 3,
/*6660*/              OPC_EmitNodeXForm, 0, 6, // UIMM8
/*6663*/              OPC_MorphNodeTo, TARGET_VAL(SystemZ::XI), 0|OPFL_Chain|OPFL_MemRefs,
                          1/*#VTs*/, MVT::i32, 3/*#Ops*/, 4, 5, 7, 
                      // Src: (st (xor:i32 (ld:i32 bdaddr12pair:i64:$addr)<<P:Predicate_unindexedload>><<P:Predicate_anyextload>><<P:Predicate_anyextloadi8>>, (imm:i32):$src), bdaddr12pair:i64:$addr)<<P:Predicate_unindexedstore>><<P:Predicate_truncstore>><<P:Predicate_truncstorei8>> - Complexity = 32
                      // Dst: (XI:i32 bdaddr12pair:i64:$addr, (UIMM8:i8 (imm:i32):$src))
/*6673*/            /*Scope*/ 22, /*->6696*/
/*6674*/              OPC_CheckComplexPat, /*CP*/3, /*#*/2, // selectBDAddr20Pair:$addr #4 #5
/*6677*/              OPC_EmitMergeInputChains, 2, 0, 1, 
/*6681*/              OPC_EmitConvertToTarget, 3,
/*6683*/              OPC_EmitNodeXForm, 0, 6, // UIMM8
/*6686*/              OPC_MorphNodeTo, TARGET_VAL(SystemZ::XIY), 0|OPFL_Chain|OPFL_MemRefs,
                          1/*#VTs*/, MVT::i32, 3/*#Ops*/, 4, 5, 7, 
                      // Src: (st (xor:i32 (ld:i32 bdaddr20pair:i64:$addr)<<P:Predicate_unindexedload>><<P:Predicate_anyextload>><<P:Predicate_anyextloadi8>>, (imm:i32):$src), bdaddr20pair:i64:$addr)<<P:Predicate_unindexedstore>><<P:Predicate_truncstore>><<P:Predicate_truncstorei8>> - Complexity = 32
                      // Dst: (XIY:i32 bdaddr20pair:i64:$addr, (UIMM8:i8 (imm:i32):$src))
/*6696*/            0, /*End of Scope*/
/*6697*/          /*SwitchType*/ 57,  MVT::i64,// ->6756
/*6699*/            OPC_MoveParent,
/*6700*/            OPC_CheckChild2Same, 2,
/*6702*/            OPC_CheckPredicate, 5, // Predicate_unindexedstore
/*6704*/            OPC_CheckPredicate, 6, // Predicate_truncstore
/*6706*/            OPC_CheckPredicate, 7, // Predicate_truncstorei8
/*6708*/            OPC_Scope, 22, /*->6732*/ // 2 children in Scope
/*6710*/              OPC_CheckComplexPat, /*CP*/2, /*#*/2, // selectBDAddr12Pair:$addr #4 #5
/*6713*/              OPC_EmitMergeInputChains, 2, 0, 1, 
/*6717*/              OPC_EmitConvertToTarget, 3,
/*6719*/              OPC_EmitNodeXForm, 0, 6, // UIMM8
/*6722*/              OPC_MorphNodeTo, TARGET_VAL(SystemZ::XI), 0|OPFL_Chain|OPFL_MemRefs,
                          1/*#VTs*/, MVT::i32, 3/*#Ops*/, 4, 5, 7, 
                      // Src: (st (xor:i64 (ld:i64 bdaddr12pair:i64:$addr)<<P:Predicate_unindexedload>><<P:Predicate_anyextload>><<P:Predicate_anyextloadi8>>, (imm:i64):$src), bdaddr12pair:i64:$addr)<<P:Predicate_unindexedstore>><<P:Predicate_truncstore>><<P:Predicate_truncstorei8>> - Complexity = 32
                      // Dst: (XI:i32 bdaddr12pair:i64:$addr, (UIMM8:i8 (imm:i64):$src))
/*6732*/            /*Scope*/ 22, /*->6755*/
/*6733*/              OPC_CheckComplexPat, /*CP*/3, /*#*/2, // selectBDAddr20Pair:$addr #4 #5
/*6736*/              OPC_EmitMergeInputChains, 2, 0, 1, 
/*6740*/              OPC_EmitConvertToTarget, 3,
/*6742*/              OPC_EmitNodeXForm, 0, 6, // UIMM8
/*6745*/              OPC_MorphNodeTo, TARGET_VAL(SystemZ::XIY), 0|OPFL_Chain|OPFL_MemRefs,
                          1/*#VTs*/, MVT::i32, 3/*#Ops*/, 4, 5, 7, 
                      // Src: (st (xor:i64 (ld:i64 bdaddr20pair:i64:$addr)<<P:Predicate_unindexedload>><<P:Predicate_anyextload>><<P:Predicate_anyextloadi8>>, (imm:i64):$src), bdaddr20pair:i64:$addr)<<P:Predicate_unindexedstore>><<P:Predicate_truncstore>><<P:Predicate_truncstorei8>> - Complexity = 32
                      // Dst: (XIY:i32 bdaddr20pair:i64:$addr, (UIMM8:i8 (imm:i64):$src))
/*6755*/            0, /*End of Scope*/
/*6756*/          0, // EndSwitchType
/*6757*/        0, /*End of Scope*/
/*6758*/      /*SwitchOpcode*/ 94,  TARGET_VAL(ISD::ADD),// ->6855
/*6761*/        OPC_MoveChild, 0,
/*6763*/        OPC_CheckOpcode, TARGET_VAL(ISD::LOAD),
/*6766*/        OPC_RecordMemRef,
/*6767*/        OPC_RecordNode, // #1 = 'ld' chained node
/*6768*/        OPC_CheckFoldableChainNode,
/*6769*/        OPC_RecordChild1, // #2 = $BD1
/*6770*/        OPC_CheckChild1Type, MVT::i64,
/*6772*/        OPC_CheckPredicate, 0, // Predicate_unindexedload
/*6774*/        OPC_CheckPredicate, 13, // Predicate_load
/*6776*/        OPC_MoveParent,
/*6777*/        OPC_RecordChild1, // #3 = $I2
/*6778*/        OPC_MoveChild, 1,
/*6780*/        OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*6783*/        OPC_Scope, 34, /*->6819*/ // 2 children in Scope
/*6785*/          OPC_CheckPredicate, 27, // Predicate_imm32sx8
/*6787*/          OPC_MoveParent,
/*6788*/          OPC_CheckType, MVT::i32,
/*6790*/          OPC_MoveParent,
/*6791*/          OPC_CheckChild2Same, 2,
/*6793*/          OPC_CheckPredicate, 5, // Predicate_unindexedstore
/*6795*/          OPC_CheckPredicate, 15, // Predicate_store
/*6797*/          OPC_CheckComplexPat, /*CP*/4, /*#*/2, // selectBDAddr20Only:$BD1 #4 #5
/*6800*/          OPC_EmitMergeInputChains, 2, 0, 1, 
/*6804*/          OPC_EmitConvertToTarget, 3,
/*6806*/          OPC_EmitNodeXForm, 1, 6, // SIMM8
/*6809*/          OPC_MorphNodeTo, TARGET_VAL(SystemZ::ASI), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i32, 3/*#Ops*/, 4, 5, 7, 
                  // Src: (st (add:i32 (ld:i32 bdaddr20only:i64:$BD1)<<P:Predicate_unindexedload>><<P:Predicate_load>>, (imm:i32)<<P:Predicate_imm32sx8>><<X:SIMM8>>:$I2), bdaddr20only:i64:$BD1)<<P:Predicate_unindexedstore>><<P:Predicate_store>> - Complexity = 33
                  // Dst: (ASI:i32 bdaddr20only:i64:$BD1, (SIMM8:i32 (imm:i32):$I2))
/*6819*/        /*Scope*/ 34, /*->6854*/
/*6820*/          OPC_CheckPredicate, 28, // Predicate_imm64sx8
/*6822*/          OPC_MoveParent,
/*6823*/          OPC_CheckType, MVT::i64,
/*6825*/          OPC_MoveParent,
/*6826*/          OPC_CheckChild2Same, 2,
/*6828*/          OPC_CheckPredicate, 5, // Predicate_unindexedstore
/*6830*/          OPC_CheckPredicate, 15, // Predicate_store
/*6832*/          OPC_CheckComplexPat, /*CP*/4, /*#*/2, // selectBDAddr20Only:$BD1 #4 #5
/*6835*/          OPC_EmitMergeInputChains, 2, 0, 1, 
/*6839*/          OPC_EmitConvertToTarget, 3,
/*6841*/          OPC_EmitNodeXForm, 1, 6, // SIMM8
/*6844*/          OPC_MorphNodeTo, TARGET_VAL(SystemZ::AGSI), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i32, 3/*#Ops*/, 4, 5, 7, 
                  // Src: (st (add:i64 (ld:i64 bdaddr20only:i64:$BD1)<<P:Predicate_unindexedload>><<P:Predicate_load>>, (imm:i64)<<P:Predicate_imm64sx8>><<X:SIMM8>>:$I2), bdaddr20only:i64:$BD1)<<P:Predicate_unindexedstore>><<P:Predicate_store>> - Complexity = 33
                  // Dst: (AGSI:i32 bdaddr20only:i64:$BD1, (SIMM8:i64 (imm:i64):$I2))
/*6854*/        0, /*End of Scope*/
/*6855*/      /*SwitchOpcode*/ 122|128,2/*378*/,  TARGET_VAL(ISD::LOAD),// ->7237
/*6859*/        OPC_RecordMemRef,
/*6860*/        OPC_RecordNode, // #1 = 'ld' chained node
/*6861*/        OPC_CheckFoldableChainNode,
/*6862*/        OPC_RecordChild1, // #2 = $src
/*6863*/        OPC_CheckChild1Type, MVT::i64,
/*6865*/        OPC_CheckPredicate, 0, // Predicate_unindexedload
/*6867*/        OPC_Scope, 76, /*->6945*/ // 4 children in Scope
/*6869*/          OPC_CheckPredicate, 1, // Predicate_anyextload
/*6871*/          OPC_CheckType, MVT::i32,
/*6873*/          OPC_Scope, 34, /*->6909*/ // 2 children in Scope
/*6875*/            OPC_CheckPredicate, 2, // Predicate_anyextloadi8
/*6877*/            OPC_MoveParent,
/*6878*/            OPC_RecordChild2, // #3 = $dest
/*6879*/            OPC_CheckChild2Type, MVT::i64,
/*6881*/            OPC_CheckPredicate, 5, // Predicate_unindexedstore
/*6883*/            OPC_CheckPredicate, 29, // Predicate_mvc_store
/*6885*/            OPC_CheckComplexPat, /*CP*/1, /*#*/2, // selectBDAddr12Only:$src #4 #5
/*6888*/            OPC_CheckComplexPat, /*CP*/1, /*#*/3, // selectBDAddr12Only:$dest #6 #7
/*6891*/            OPC_EmitMergeInputChains, 2, 0, 1, 
/*6895*/            OPC_EmitInteger, MVT::i64, 1, 
/*6898*/            OPC_MorphNodeTo, TARGET_VAL(SystemZ::MVCSequence), 0|OPFL_Chain|OPFL_MemRefs,
                        0/*#VTs*/, 5/*#Ops*/, 6, 7, 4, 5, 8, 
                    // Src: (st (ld:i32 bdaddr12only:i64:$src)<<P:Predicate_unindexedload>><<P:Predicate_anyextload>><<P:Predicate_anyextloadi8>>, bdaddr12only:i64:$dest)<<P:Predicate_unindexedstore>><<P:Predicate_mvc_store>> - Complexity = 26
                    // Dst: (MVCSequence bdaddr12only:i64:$dest, bdaddr12only:i64:$src, 1:i64)
/*6909*/          /*Scope*/ 34, /*->6944*/
/*6910*/            OPC_CheckPredicate, 9, // Predicate_anyextloadi16
/*6912*/            OPC_MoveParent,
/*6913*/            OPC_RecordChild2, // #3 = $dest
/*6914*/            OPC_CheckChild2Type, MVT::i64,
/*6916*/            OPC_CheckPredicate, 5, // Predicate_unindexedstore
/*6918*/            OPC_CheckPredicate, 29, // Predicate_mvc_store
/*6920*/            OPC_CheckComplexPat, /*CP*/1, /*#*/2, // selectBDAddr12Only:$src #4 #5
/*6923*/            OPC_CheckComplexPat, /*CP*/1, /*#*/3, // selectBDAddr12Only:$dest #6 #7
/*6926*/            OPC_EmitMergeInputChains, 2, 0, 1, 
/*6930*/            OPC_EmitInteger, MVT::i64, 2, 
/*6933*/            OPC_MorphNodeTo, TARGET_VAL(SystemZ::MVCSequence), 0|OPFL_Chain|OPFL_MemRefs,
                        0/*#VTs*/, 5/*#Ops*/, 6, 7, 4, 5, 8, 
                    // Src: (st (ld:i32 bdaddr12only:i64:$src)<<P:Predicate_unindexedload>><<P:Predicate_anyextload>><<P:Predicate_anyextloadi16>>, bdaddr12only:i64:$dest)<<P:Predicate_unindexedstore>><<P:Predicate_mvc_store>> - Complexity = 26
                    // Dst: (MVCSequence bdaddr12only:i64:$dest, bdaddr12only:i64:$src, 2:i64)
/*6944*/          0, /*End of Scope*/
/*6945*/        /*Scope*/ 36, /*->6982*/
/*6946*/          OPC_CheckPredicate, 13, // Predicate_load
/*6948*/          OPC_CheckType, MVT::i32,
/*6950*/          OPC_MoveParent,
/*6951*/          OPC_RecordChild2, // #3 = $dest
/*6952*/          OPC_CheckChild2Type, MVT::i64,
/*6954*/          OPC_CheckPredicate, 5, // Predicate_unindexedstore
/*6956*/          OPC_CheckPredicate, 29, // Predicate_mvc_store
/*6958*/          OPC_CheckComplexPat, /*CP*/1, /*#*/2, // selectBDAddr12Only:$src #4 #5
/*6961*/          OPC_CheckComplexPat, /*CP*/1, /*#*/3, // selectBDAddr12Only:$dest #6 #7
/*6964*/          OPC_EmitMergeInputChains, 2, 0, 1, 
/*6968*/          OPC_EmitInteger, MVT::i64, 4, 
/*6971*/          OPC_MorphNodeTo, TARGET_VAL(SystemZ::MVCSequence), 0|OPFL_Chain|OPFL_MemRefs,
                      0/*#VTs*/, 5/*#Ops*/, 6, 7, 4, 5, 8, 
                  // Src: (st (ld:i32 bdaddr12only:i64:$src)<<P:Predicate_unindexedload>><<P:Predicate_load>>, bdaddr12only:i64:$dest)<<P:Predicate_unindexedstore>><<P:Predicate_mvc_store>> - Complexity = 26
                  // Dst: (MVCSequence bdaddr12only:i64:$dest, bdaddr12only:i64:$src, 4:i64)
/*6982*/        /*Scope*/ 111, /*->7094*/
/*6983*/          OPC_CheckPredicate, 1, // Predicate_anyextload
/*6985*/          OPC_CheckType, MVT::i64,
/*6987*/          OPC_Scope, 34, /*->7023*/ // 3 children in Scope
/*6989*/            OPC_CheckPredicate, 2, // Predicate_anyextloadi8
/*6991*/            OPC_MoveParent,
/*6992*/            OPC_RecordChild2, // #3 = $dest
/*6993*/            OPC_CheckChild2Type, MVT::i64,
/*6995*/            OPC_CheckPredicate, 5, // Predicate_unindexedstore
/*6997*/            OPC_CheckPredicate, 29, // Predicate_mvc_store
/*6999*/            OPC_CheckComplexPat, /*CP*/1, /*#*/2, // selectBDAddr12Only:$src #4 #5
/*7002*/            OPC_CheckComplexPat, /*CP*/1, /*#*/3, // selectBDAddr12Only:$dest #6 #7
/*7005*/            OPC_EmitMergeInputChains, 2, 0, 1, 
/*7009*/            OPC_EmitInteger, MVT::i64, 1, 
/*7012*/            OPC_MorphNodeTo, TARGET_VAL(SystemZ::MVCSequence), 0|OPFL_Chain|OPFL_MemRefs,
                        0/*#VTs*/, 5/*#Ops*/, 6, 7, 4, 5, 8, 
                    // Src: (st (ld:i64 bdaddr12only:i64:$src)<<P:Predicate_unindexedload>><<P:Predicate_anyextload>><<P:Predicate_anyextloadi8>>, bdaddr12only:i64:$dest)<<P:Predicate_unindexedstore>><<P:Predicate_mvc_store>> - Complexity = 26
                    // Dst: (MVCSequence bdaddr12only:i64:$dest, bdaddr12only:i64:$src, 1:i64)
/*7023*/          /*Scope*/ 34, /*->7058*/
/*7024*/            OPC_CheckPredicate, 9, // Predicate_anyextloadi16
/*7026*/            OPC_MoveParent,
/*7027*/            OPC_RecordChild2, // #3 = $dest
/*7028*/            OPC_CheckChild2Type, MVT::i64,
/*7030*/            OPC_CheckPredicate, 5, // Predicate_unindexedstore
/*7032*/            OPC_CheckPredicate, 29, // Predicate_mvc_store
/*7034*/            OPC_CheckComplexPat, /*CP*/1, /*#*/2, // selectBDAddr12Only:$src #4 #5
/*7037*/            OPC_CheckComplexPat, /*CP*/1, /*#*/3, // selectBDAddr12Only:$dest #6 #7
/*7040*/            OPC_EmitMergeInputChains, 2, 0, 1, 
/*7044*/            OPC_EmitInteger, MVT::i64, 2, 
/*7047*/            OPC_MorphNodeTo, TARGET_VAL(SystemZ::MVCSequence), 0|OPFL_Chain|OPFL_MemRefs,
                        0/*#VTs*/, 5/*#Ops*/, 6, 7, 4, 5, 8, 
                    // Src: (st (ld:i64 bdaddr12only:i64:$src)<<P:Predicate_unindexedload>><<P:Predicate_anyextload>><<P:Predicate_anyextloadi16>>, bdaddr12only:i64:$dest)<<P:Predicate_unindexedstore>><<P:Predicate_mvc_store>> - Complexity = 26
                    // Dst: (MVCSequence bdaddr12only:i64:$dest, bdaddr12only:i64:$src, 2:i64)
/*7058*/          /*Scope*/ 34, /*->7093*/
/*7059*/            OPC_CheckPredicate, 17, // Predicate_anyextloadi32
/*7061*/            OPC_MoveParent,
/*7062*/            OPC_RecordChild2, // #3 = $dest
/*7063*/            OPC_CheckChild2Type, MVT::i64,
/*7065*/            OPC_CheckPredicate, 5, // Predicate_unindexedstore
/*7067*/            OPC_CheckPredicate, 29, // Predicate_mvc_store
/*7069*/            OPC_CheckComplexPat, /*CP*/1, /*#*/2, // selectBDAddr12Only:$src #4 #5
/*7072*/            OPC_CheckComplexPat, /*CP*/1, /*#*/3, // selectBDAddr12Only:$dest #6 #7
/*7075*/            OPC_EmitMergeInputChains, 2, 0, 1, 
/*7079*/            OPC_EmitInteger, MVT::i64, 4, 
/*7082*/            OPC_MorphNodeTo, TARGET_VAL(SystemZ::MVCSequence), 0|OPFL_Chain|OPFL_MemRefs,
                        0/*#VTs*/, 5/*#Ops*/, 6, 7, 4, 5, 8, 
                    // Src: (st (ld:i64 bdaddr12only:i64:$src)<<P:Predicate_unindexedload>><<P:Predicate_anyextload>><<P:Predicate_anyextloadi32>>, bdaddr12only:i64:$dest)<<P:Predicate_unindexedstore>><<P:Predicate_mvc_store>> - Complexity = 26
                    // Dst: (MVCSequence bdaddr12only:i64:$dest, bdaddr12only:i64:$src, 4:i64)
/*7093*/          0, /*End of Scope*/
/*7094*/        /*Scope*/ 12|128,1/*140*/, /*->7236*/
/*7096*/          OPC_CheckPredicate, 13, // Predicate_load
/*7098*/          OPC_SwitchType /*4 cases */, 32,  MVT::i64,// ->7133
/*7101*/            OPC_MoveParent,
/*7102*/            OPC_RecordChild2, // #3 = $dest
/*7103*/            OPC_CheckChild2Type, MVT::i64,
/*7105*/            OPC_CheckPredicate, 5, // Predicate_unindexedstore
/*7107*/            OPC_CheckPredicate, 29, // Predicate_mvc_store
/*7109*/            OPC_CheckComplexPat, /*CP*/1, /*#*/2, // selectBDAddr12Only:$src #4 #5
/*7112*/            OPC_CheckComplexPat, /*CP*/1, /*#*/3, // selectBDAddr12Only:$dest #6 #7
/*7115*/            OPC_EmitMergeInputChains, 2, 0, 1, 
/*7119*/            OPC_EmitInteger, MVT::i64, 8, 
/*7122*/            OPC_MorphNodeTo, TARGET_VAL(SystemZ::MVCSequence), 0|OPFL_Chain|OPFL_MemRefs,
                        0/*#VTs*/, 5/*#Ops*/, 6, 7, 4, 5, 8, 
                    // Src: (st (ld:i64 bdaddr12only:i64:$src)<<P:Predicate_unindexedload>><<P:Predicate_load>>, bdaddr12only:i64:$dest)<<P:Predicate_unindexedstore>><<P:Predicate_mvc_store>> - Complexity = 26
                    // Dst: (MVCSequence bdaddr12only:i64:$dest, bdaddr12only:i64:$src, 8:i64)
/*7133*/          /*SwitchType*/ 32,  MVT::f32,// ->7167
/*7135*/            OPC_MoveParent,
/*7136*/            OPC_RecordChild2, // #3 = $dest
/*7137*/            OPC_CheckChild2Type, MVT::i64,
/*7139*/            OPC_CheckPredicate, 5, // Predicate_unindexedstore
/*7141*/            OPC_CheckPredicate, 29, // Predicate_mvc_store
/*7143*/            OPC_CheckComplexPat, /*CP*/1, /*#*/2, // selectBDAddr12Only:$src #4 #5
/*7146*/            OPC_CheckComplexPat, /*CP*/1, /*#*/3, // selectBDAddr12Only:$dest #6 #7
/*7149*/            OPC_EmitMergeInputChains, 2, 0, 1, 
/*7153*/            OPC_EmitInteger, MVT::i64, 4, 
/*7156*/            OPC_MorphNodeTo, TARGET_VAL(SystemZ::MVCSequence), 0|OPFL_Chain|OPFL_MemRefs,
                        0/*#VTs*/, 5/*#Ops*/, 6, 7, 4, 5, 8, 
                    // Src: (st (ld:f32 bdaddr12only:i64:$src)<<P:Predicate_unindexedload>><<P:Predicate_load>>, bdaddr12only:i64:$dest)<<P:Predicate_unindexedstore>><<P:Predicate_mvc_store>> - Complexity = 26
                    // Dst: (MVCSequence bdaddr12only:i64:$dest, bdaddr12only:i64:$src, 4:i64)
/*7167*/          /*SwitchType*/ 32,  MVT::f64,// ->7201
/*7169*/            OPC_MoveParent,
/*7170*/            OPC_RecordChild2, // #3 = $dest
/*7171*/            OPC_CheckChild2Type, MVT::i64,
/*7173*/            OPC_CheckPredicate, 5, // Predicate_unindexedstore
/*7175*/            OPC_CheckPredicate, 29, // Predicate_mvc_store
/*7177*/            OPC_CheckComplexPat, /*CP*/1, /*#*/2, // selectBDAddr12Only:$src #4 #5
/*7180*/            OPC_CheckComplexPat, /*CP*/1, /*#*/3, // selectBDAddr12Only:$dest #6 #7
/*7183*/            OPC_EmitMergeInputChains, 2, 0, 1, 
/*7187*/            OPC_EmitInteger, MVT::i64, 8, 
/*7190*/            OPC_MorphNodeTo, TARGET_VAL(SystemZ::MVCSequence), 0|OPFL_Chain|OPFL_MemRefs,
                        0/*#VTs*/, 5/*#Ops*/, 6, 7, 4, 5, 8, 
                    // Src: (st (ld:f64 bdaddr12only:i64:$src)<<P:Predicate_unindexedload>><<P:Predicate_load>>, bdaddr12only:i64:$dest)<<P:Predicate_unindexedstore>><<P:Predicate_mvc_store>> - Complexity = 26
                    // Dst: (MVCSequence bdaddr12only:i64:$dest, bdaddr12only:i64:$src, 8:i64)
/*7201*/          /*SwitchType*/ 32,  MVT::f128,// ->7235
/*7203*/            OPC_MoveParent,
/*7204*/            OPC_RecordChild2, // #3 = $dest
/*7205*/            OPC_CheckChild2Type, MVT::i64,
/*7207*/            OPC_CheckPredicate, 5, // Predicate_unindexedstore
/*7209*/            OPC_CheckPredicate, 29, // Predicate_mvc_store
/*7211*/            OPC_CheckComplexPat, /*CP*/1, /*#*/2, // selectBDAddr12Only:$src #4 #5
/*7214*/            OPC_CheckComplexPat, /*CP*/1, /*#*/3, // selectBDAddr12Only:$dest #6 #7
/*7217*/            OPC_EmitMergeInputChains, 2, 0, 1, 
/*7221*/            OPC_EmitInteger, MVT::i64, 16, 
/*7224*/            OPC_MorphNodeTo, TARGET_VAL(SystemZ::MVCSequence), 0|OPFL_Chain|OPFL_MemRefs,
                        0/*#VTs*/, 5/*#Ops*/, 6, 7, 4, 5, 8, 
                    // Src: (st (ld:f128 bdaddr12only:i64:$src)<<P:Predicate_unindexedload>><<P:Predicate_load>>, bdaddr12only:i64:$dest)<<P:Predicate_unindexedstore>><<P:Predicate_mvc_store>> - Complexity = 26
                    // Dst: (MVCSequence bdaddr12only:i64:$dest, bdaddr12only:i64:$src, 16:i64)
/*7235*/          0, // EndSwitchType
/*7236*/        0, /*End of Scope*/
/*7237*/      /*SwitchOpcode*/ 55,  TARGET_VAL(ISD::BSWAP),// ->7295
/*7240*/        OPC_RecordChild0, // #1 = $R1
/*7241*/        OPC_SwitchType /*2 cases */, 24,  MVT::i32,// ->7268
/*7244*/          OPC_MoveParent,
/*7245*/          OPC_RecordChild2, // #2 = $XBD2
/*7246*/          OPC_CheckChild2Type, MVT::i64,
/*7248*/          OPC_CheckPredicate, 5, // Predicate_unindexedstore
/*7250*/          OPC_CheckPredicate, 15, // Predicate_store
/*7252*/          OPC_CheckPredicate, 16, // Predicate_nonvolatile_store
/*7254*/          OPC_CheckComplexPat, /*CP*/0, /*#*/2, // selectBDXAddr20Only:$XBD2 #3 #4 #5
/*7257*/          OPC_EmitMergeInputChains1_0,
/*7258*/          OPC_MorphNodeTo, TARGET_VAL(SystemZ::STRV), 0|OPFL_Chain|OPFL_MemRefs,
                      0/*#VTs*/, 4/*#Ops*/, 1, 3, 4, 5, 
                  // Src: (st (bswap:i32 GR32:i32:$R1), bdxaddr20only:i64:$XBD2)<<P:Predicate_unindexedstore>><<P:Predicate_store>><<P:Predicate_nonvolatile_store>> - Complexity = 19
                  // Dst: (STRV GR32:i32:$R1, bdxaddr20only:i64:$XBD2)
/*7268*/        /*SwitchType*/ 24,  MVT::i64,// ->7294
/*7270*/          OPC_MoveParent,
/*7271*/          OPC_RecordChild2, // #2 = $XBD2
/*7272*/          OPC_CheckChild2Type, MVT::i64,
/*7274*/          OPC_CheckPredicate, 5, // Predicate_unindexedstore
/*7276*/          OPC_CheckPredicate, 15, // Predicate_store
/*7278*/          OPC_CheckPredicate, 16, // Predicate_nonvolatile_store
/*7280*/          OPC_CheckComplexPat, /*CP*/0, /*#*/2, // selectBDXAddr20Only:$XBD2 #3 #4 #5
/*7283*/          OPC_EmitMergeInputChains1_0,
/*7284*/          OPC_MorphNodeTo, TARGET_VAL(SystemZ::STRVG), 0|OPFL_Chain|OPFL_MemRefs,
                      0/*#VTs*/, 4/*#Ops*/, 1, 3, 4, 5, 
                  // Src: (st (bswap:i64 GR64:i64:$R1), bdxaddr20only:i64:$XBD2)<<P:Predicate_unindexedstore>><<P:Predicate_store>><<P:Predicate_nonvolatile_store>> - Complexity = 19
                  // Dst: (STRVG GR64:i64:$R1, bdxaddr20only:i64:$XBD2)
/*7294*/        0, // EndSwitchType
/*7295*/      0, // EndSwitchOpcode
/*7296*/    /*Scope*/ 94|128,6/*862*/, /*->8160*/
/*7298*/      OPC_RecordChild1, // #1 = $R1
/*7299*/      OPC_Scope, 23, /*->7324*/ // 12 children in Scope
/*7301*/        OPC_CheckChild1Type, MVT::i32,
/*7303*/        OPC_RecordChild2, // #2 = $I2
/*7304*/        OPC_CheckChild2Type, MVT::i64,
/*7306*/        OPC_CheckPredicate, 5, // Predicate_unindexedstore
/*7308*/        OPC_CheckPredicate, 15, // Predicate_store
/*7310*/        OPC_CheckPredicate, 30, // Predicate_aligned_store
/*7312*/        OPC_CheckComplexPat, /*CP*/5, /*#*/2, // selectPCRelAddress:$I2 #3
/*7315*/        OPC_EmitMergeInputChains1_0,
/*7316*/        OPC_MorphNodeTo, TARGET_VAL(SystemZ::STRL), 0|OPFL_Chain|OPFL_MemRefs,
                    0/*#VTs*/, 2/*#Ops*/, 1, 3, 
                // Src: (st GR32:i32:$R1, pcrel32:i64:$I2)<<P:Predicate_unindexedstore>><<P:Predicate_store>><<P:Predicate_aligned_store>> - Complexity = 17
                // Dst: (STRL GR32:i32:$R1, pcrel32:i64:$I2)
/*7324*/      /*Scope*/ 23, /*->7348*/
/*7325*/        OPC_CheckChild1Type, MVT::i64,
/*7327*/        OPC_RecordChild2, // #2 = $I2
/*7328*/        OPC_CheckChild2Type, MVT::i64,
/*7330*/        OPC_CheckPredicate, 5, // Predicate_unindexedstore
/*7332*/        OPC_CheckPredicate, 15, // Predicate_store
/*7334*/        OPC_CheckPredicate, 30, // Predicate_aligned_store
/*7336*/        OPC_CheckComplexPat, /*CP*/5, /*#*/2, // selectPCRelAddress:$I2 #3
/*7339*/        OPC_EmitMergeInputChains1_0,
/*7340*/        OPC_MorphNodeTo, TARGET_VAL(SystemZ::STGRL), 0|OPFL_Chain|OPFL_MemRefs,
                    0/*#VTs*/, 2/*#Ops*/, 1, 3, 
                // Src: (st GR64:i64:$R1, pcrel32:i64:$I2)<<P:Predicate_unindexedstore>><<P:Predicate_store>><<P:Predicate_aligned_store>> - Complexity = 17
                // Dst: (STGRL GR64:i64:$R1, pcrel32:i64:$I2)
/*7348*/      /*Scope*/ 67, /*->7416*/
/*7349*/        OPC_MoveChild, 1,
/*7351*/        OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*7354*/        OPC_SwitchType /*2 cases */, 28,  MVT::i32,// ->7385
/*7357*/          OPC_CheckPredicate, 31, // Predicate_imm32sx16
/*7359*/          OPC_MoveParent,
/*7360*/          OPC_RecordChild2, // #2 = $BD1
/*7361*/          OPC_CheckChild2Type, MVT::i64,
/*7363*/          OPC_CheckPredicate, 5, // Predicate_unindexedstore
/*7365*/          OPC_CheckPredicate, 15, // Predicate_store
/*7367*/          OPC_CheckComplexPat, /*CP*/6, /*#*/2, // selectMVIAddr12Pair:$BD1 #3 #4
/*7370*/          OPC_EmitMergeInputChains1_0,
/*7371*/          OPC_EmitConvertToTarget, 1,
/*7373*/          OPC_EmitNodeXForm, 2, 5, // SIMM16
/*7376*/          OPC_MorphNodeTo, TARGET_VAL(SystemZ::MVHI), 0|OPFL_Chain|OPFL_MemRefs,
                      0/*#VTs*/, 3/*#Ops*/, 3, 4, 6, 
                  // Src: (st (imm:i32)<<P:Predicate_imm32sx16>><<X:SIMM16>>:$I2, mviaddr12pair:i64:$BD1)<<P:Predicate_unindexedstore>><<P:Predicate_store>> - Complexity = 17
                  // Dst: (MVHI mviaddr12pair:i64:$BD1, (SIMM16:i32 (imm:i32):$I2))
/*7385*/        /*SwitchType*/ 28,  MVT::i64,// ->7415
/*7387*/          OPC_CheckPredicate, 32, // Predicate_imm64sx16
/*7389*/          OPC_MoveParent,
/*7390*/          OPC_RecordChild2, // #2 = $BD1
/*7391*/          OPC_CheckChild2Type, MVT::i64,
/*7393*/          OPC_CheckPredicate, 5, // Predicate_unindexedstore
/*7395*/          OPC_CheckPredicate, 15, // Predicate_store
/*7397*/          OPC_CheckComplexPat, /*CP*/6, /*#*/2, // selectMVIAddr12Pair:$BD1 #3 #4
/*7400*/          OPC_EmitMergeInputChains1_0,
/*7401*/          OPC_EmitConvertToTarget, 1,
/*7403*/          OPC_EmitNodeXForm, 2, 5, // SIMM16
/*7406*/          OPC_MorphNodeTo, TARGET_VAL(SystemZ::MVGHI), 0|OPFL_Chain|OPFL_MemRefs,
                      0/*#VTs*/, 3/*#Ops*/, 3, 4, 6, 
                  // Src: (st (imm:i64)<<P:Predicate_imm64sx16>><<X:SIMM16>>:$I2, mviaddr12pair:i64:$BD1)<<P:Predicate_unindexedstore>><<P:Predicate_store>> - Complexity = 17
                  // Dst: (MVGHI mviaddr12pair:i64:$BD1, (SIMM16:i64 (imm:i64):$I2))
/*7415*/        0, // EndSwitchType
/*7416*/      /*Scope*/ 97, /*->7514*/
/*7417*/        OPC_CheckChild1Type, MVT::i32,
/*7419*/        OPC_RecordChild2, // #2 = $I2
/*7420*/        OPC_CheckChild2Type, MVT::i64,
/*7422*/        OPC_CheckPredicate, 5, // Predicate_unindexedstore
/*7424*/        OPC_Scope, 18, /*->7444*/ // 2 children in Scope
/*7426*/          OPC_CheckPredicate, 6, // Predicate_truncstore
/*7428*/          OPC_CheckPredicate, 11, // Predicate_truncstorei16
/*7430*/          OPC_CheckPredicate, 33, // Predicate_aligned_truncstorei16
/*7432*/          OPC_CheckComplexPat, /*CP*/5, /*#*/2, // selectPCRelAddress:$I2 #3
/*7435*/          OPC_EmitMergeInputChains1_0,
/*7436*/          OPC_MorphNodeTo, TARGET_VAL(SystemZ::STHRL), 0|OPFL_Chain|OPFL_MemRefs,
                      0/*#VTs*/, 2/*#Ops*/, 1, 3, 
                  // Src: (st GR32:i32:$R1, pcrel32:i64:$I2)<<P:Predicate_unindexedstore>><<P:Predicate_truncstore>><<P:Predicate_truncstorei16>><<P:Predicate_aligned_truncstorei16>> - Complexity = 17
                  // Dst: (STHRL GR32:i32:$R1, pcrel32:i64:$I2)
/*7444*/        /*Scope*/ 68, /*->7513*/
/*7445*/          OPC_CheckPredicate, 15, // Predicate_store
/*7447*/          OPC_Scope, 16, /*->7465*/ // 4 children in Scope
/*7449*/            OPC_CheckPatternPredicate, 0, // (Subtarget.hasHighWord())
/*7451*/            OPC_CheckComplexPat, /*CP*/0, /*#*/2, // selectBDXAddr20Only:$XBD2 #3 #4 #5
/*7454*/            OPC_EmitMergeInputChains1_0,
/*7455*/            OPC_MorphNodeTo, TARGET_VAL(SystemZ::STMux), 0|OPFL_Chain|OPFL_MemRefs,
                        0/*#VTs*/, 4/*#Ops*/, 1, 3, 4, 5, 
                    // Src: (st GRX32:i32:$R1, bdxaddr20only:i64:$XBD2)<<P:Predicate_unindexedstore>><<P:Predicate_store>> - Complexity = 16
                    // Dst: (STMux GRX32:i32:$R1, bdxaddr20only:i64:$XBD2)
/*7465*/          /*Scope*/ 14, /*->7480*/
/*7466*/            OPC_CheckComplexPat, /*CP*/7, /*#*/2, // selectBDXAddr12Pair:$XBD2 #3 #4 #5
/*7469*/            OPC_EmitMergeInputChains1_0,
/*7470*/            OPC_MorphNodeTo, TARGET_VAL(SystemZ::ST), 0|OPFL_Chain|OPFL_MemRefs,
                        0/*#VTs*/, 4/*#Ops*/, 1, 3, 4, 5, 
                    // Src: (st GR32:i32:$R1, bdxaddr12pair:i64:$XBD2)<<P:Predicate_unindexedstore>><<P:Predicate_store>> - Complexity = 16
                    // Dst: (ST GR32:i32:$R1, bdxaddr12pair:i64:$XBD2)
/*7480*/          /*Scope*/ 14, /*->7495*/
/*7481*/            OPC_CheckComplexPat, /*CP*/8, /*#*/2, // selectBDXAddr20Pair:$XBD2 #3 #4 #5
/*7484*/            OPC_EmitMergeInputChains1_0,
/*7485*/            OPC_MorphNodeTo, TARGET_VAL(SystemZ::STY), 0|OPFL_Chain|OPFL_MemRefs,
                        0/*#VTs*/, 4/*#Ops*/, 1, 3, 4, 5, 
                    // Src: (st GR32:i32:$R1, bdxaddr20pair:i64:$XBD2)<<P:Predicate_unindexedstore>><<P:Predicate_store>> - Complexity = 16
                    // Dst: (STY GR32:i32:$R1, bdxaddr20pair:i64:$XBD2)
/*7495*/          /*Scope*/ 16, /*->7512*/
/*7496*/            OPC_CheckPatternPredicate, 0, // (Subtarget.hasHighWord())
/*7498*/            OPC_CheckComplexPat, /*CP*/0, /*#*/2, // selectBDXAddr20Only:$XBD2 #3 #4 #5
/*7501*/            OPC_EmitMergeInputChains1_0,
/*7502*/            OPC_MorphNodeTo, TARGET_VAL(SystemZ::STFH), 0|OPFL_Chain|OPFL_MemRefs,
                        0/*#VTs*/, 4/*#Ops*/, 1, 3, 4, 5, 
                    // Src: (st GRH32:i32:$R1, bdxaddr20only:i64:$XBD2)<<P:Predicate_unindexedstore>><<P:Predicate_store>> - Complexity = 16
                    // Dst: (STFH GRH32:i32:$R1, bdxaddr20only:i64:$XBD2)
/*7512*/          0, /*End of Scope*/
/*7513*/        0, /*End of Scope*/
/*7514*/      /*Scope*/ 89, /*->7604*/
/*7515*/        OPC_CheckChild1Type, MVT::i64,
/*7517*/        OPC_RecordChild2, // #2 = $XBD2
/*7518*/        OPC_CheckChild2Type, MVT::i64,
/*7520*/        OPC_CheckPredicate, 5, // Predicate_unindexedstore
/*7522*/        OPC_Scope, 62, /*->7586*/ // 2 children in Scope
/*7524*/          OPC_CheckPredicate, 6, // Predicate_truncstore
/*7526*/          OPC_Scope, 28, /*->7556*/ // 2 children in Scope
/*7528*/            OPC_CheckPredicate, 11, // Predicate_truncstorei16
/*7530*/            OPC_CheckPredicate, 33, // Predicate_aligned_truncstorei16
/*7532*/            OPC_CheckComplexPat, /*CP*/5, /*#*/2, // selectPCRelAddress:$XBD2 #3
/*7535*/            OPC_EmitMergeInputChains1_0,
/*7536*/            OPC_EmitInteger, MVT::i32, SystemZ::subreg_l32,
/*7539*/            OPC_EmitNode, TARGET_VAL(TargetOpcode::EXTRACT_SUBREG), 0,
                        1/*#VTs*/, MVT::i32, 2/*#Ops*/, 1, 4,  // Results = #5
/*7548*/            OPC_MorphNodeTo, TARGET_VAL(SystemZ::STHRL), 0|OPFL_Chain|OPFL_MemRefs,
                        0/*#VTs*/, 2/*#Ops*/, 5, 3, 
                    // Src: (st GR64:i64:$R1, pcrel32:i64:$XBD2)<<P:Predicate_unindexedstore>><<P:Predicate_truncstore>><<P:Predicate_truncstorei16>><<P:Predicate_aligned_truncstorei16>> - Complexity = 17
                    // Dst: (STHRL (EXTRACT_SUBREG:i32 GR64:i64:$R1, subreg_l32:i32), pcrel32:i64:$XBD2)
/*7556*/          /*Scope*/ 28, /*->7585*/
/*7557*/            OPC_CheckPredicate, 19, // Predicate_truncstorei32
/*7559*/            OPC_CheckPredicate, 34, // Predicate_aligned_truncstorei32
/*7561*/            OPC_CheckComplexPat, /*CP*/5, /*#*/2, // selectPCRelAddress:$XBD2 #3
/*7564*/            OPC_EmitMergeInputChains1_0,
/*7565*/            OPC_EmitInteger, MVT::i32, SystemZ::subreg_l32,
/*7568*/            OPC_EmitNode, TARGET_VAL(TargetOpcode::EXTRACT_SUBREG), 0,
                        1/*#VTs*/, MVT::i32, 2/*#Ops*/, 1, 4,  // Results = #5
/*7577*/            OPC_MorphNodeTo, TARGET_VAL(SystemZ::STRL), 0|OPFL_Chain|OPFL_MemRefs,
                        0/*#VTs*/, 2/*#Ops*/, 5, 3, 
                    // Src: (st GR64:i64:$R1, pcrel32:i64:$XBD2)<<P:Predicate_unindexedstore>><<P:Predicate_truncstore>><<P:Predicate_truncstorei32>><<P:Predicate_aligned_truncstorei32>> - Complexity = 17
                    // Dst: (STRL (EXTRACT_SUBREG:i32 GR64:i64:$R1, subreg_l32:i32), pcrel32:i64:$XBD2)
/*7585*/          0, /*End of Scope*/
/*7586*/        /*Scope*/ 16, /*->7603*/
/*7587*/          OPC_CheckPredicate, 15, // Predicate_store
/*7589*/          OPC_CheckComplexPat, /*CP*/0, /*#*/2, // selectBDXAddr20Only:$XBD2 #3 #4 #5
/*7592*/          OPC_EmitMergeInputChains1_0,
/*7593*/          OPC_MorphNodeTo, TARGET_VAL(SystemZ::STG), 0|OPFL_Chain|OPFL_MemRefs,
                      0/*#VTs*/, 4/*#Ops*/, 1, 3, 4, 5, 
                  // Src: (st GR64:i64:$R1, bdxaddr20only:i64:$XBD2)<<P:Predicate_unindexedstore>><<P:Predicate_store>> - Complexity = 16
                  // Dst: (STG GR64:i64:$R1, bdxaddr20only:i64:$XBD2)
/*7603*/        0, /*End of Scope*/
/*7604*/      /*Scope*/ 23, /*->7628*/
/*7605*/        OPC_CheckChild1Type, MVT::Untyped,
/*7607*/        OPC_RecordChild2, // #2 = $dst
/*7608*/        OPC_CheckChild2Type, MVT::i64,
/*7610*/        OPC_CheckPredicate, 5, // Predicate_unindexedstore
/*7612*/        OPC_CheckPredicate, 15, // Predicate_store
/*7614*/        OPC_CheckComplexPat, /*CP*/9, /*#*/2, // selectBDXAddr20Only128:$dst #3 #4 #5
/*7617*/        OPC_EmitMergeInputChains1_0,
/*7618*/        OPC_MorphNodeTo, TARGET_VAL(SystemZ::ST128), 0|OPFL_Chain|OPFL_MemRefs,
                    0/*#VTs*/, 4/*#Ops*/, 1, 3, 4, 5, 
                // Src: (st GR128:Untyped:$src, bdxaddr20only128:i64:$dst)<<P:Predicate_unindexedstore>><<P:Predicate_store>> - Complexity = 16
                // Dst: (ST128 GR128:Untyped:$src, bdxaddr20only128:i64:$dst)
/*7628*/      /*Scope*/ 81, /*->7710*/
/*7629*/        OPC_MoveChild, 1,
/*7631*/        OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*7634*/        OPC_CheckType, MVT::i32,
/*7636*/        OPC_MoveParent,
/*7637*/        OPC_RecordChild2, // #2 = $BD1
/*7638*/        OPC_CheckChild2Type, MVT::i64,
/*7640*/        OPC_CheckPredicate, 5, // Predicate_unindexedstore
/*7642*/        OPC_CheckPredicate, 6, // Predicate_truncstore
/*7644*/        OPC_Scope, 42, /*->7688*/ // 2 children in Scope
/*7646*/          OPC_CheckPredicate, 7, // Predicate_truncstorei8
/*7648*/          OPC_Scope, 18, /*->7668*/ // 2 children in Scope
/*7650*/            OPC_CheckComplexPat, /*CP*/6, /*#*/2, // selectMVIAddr12Pair:$BD1 #3 #4
/*7653*/            OPC_EmitMergeInputChains1_0,
/*7654*/            OPC_EmitConvertToTarget, 1,
/*7656*/            OPC_EmitNodeXForm, 0, 5, // UIMM8
/*7659*/            OPC_MorphNodeTo, TARGET_VAL(SystemZ::MVI), 0|OPFL_Chain|OPFL_MemRefs,
                        0/*#VTs*/, 3/*#Ops*/, 3, 4, 6, 
                    // Src: (st (imm:i32)<<X:UIMM8>>:$I2, mviaddr12pair:i64:$BD1)<<P:Predicate_unindexedstore>><<P:Predicate_truncstore>><<P:Predicate_truncstorei8>> - Complexity = 16
                    // Dst: (MVI mviaddr12pair:i64:$BD1, (UIMM8:i32 (imm:i32):$I2))
/*7668*/          /*Scope*/ 18, /*->7687*/
/*7669*/            OPC_CheckComplexPat, /*CP*/10, /*#*/2, // selectMVIAddr20Pair:$BD1 #3 #4
/*7672*/            OPC_EmitMergeInputChains1_0,
/*7673*/            OPC_EmitConvertToTarget, 1,
/*7675*/            OPC_EmitNodeXForm, 0, 5, // UIMM8
/*7678*/            OPC_MorphNodeTo, TARGET_VAL(SystemZ::MVIY), 0|OPFL_Chain|OPFL_MemRefs,
                        0/*#VTs*/, 3/*#Ops*/, 3, 4, 6, 
                    // Src: (st (imm:i32)<<X:UIMM8>>:$I2, mviaddr20pair:i64:$BD1)<<P:Predicate_unindexedstore>><<P:Predicate_truncstore>><<P:Predicate_truncstorei8>> - Complexity = 16
                    // Dst: (MVIY mviaddr20pair:i64:$BD1, (UIMM8:i32 (imm:i32):$I2))
/*7687*/          0, /*End of Scope*/
/*7688*/        /*Scope*/ 20, /*->7709*/
/*7689*/          OPC_CheckPredicate, 11, // Predicate_truncstorei16
/*7691*/          OPC_CheckComplexPat, /*CP*/6, /*#*/2, // selectMVIAddr12Pair:$BD1 #3 #4
/*7694*/          OPC_EmitMergeInputChains1_0,
/*7695*/          OPC_EmitConvertToTarget, 1,
/*7697*/          OPC_EmitNodeXForm, 2, 5, // SIMM16
/*7700*/          OPC_MorphNodeTo, TARGET_VAL(SystemZ::MVHHI), 0|OPFL_Chain|OPFL_MemRefs,
                      0/*#VTs*/, 3/*#Ops*/, 3, 4, 6, 
                  // Src: (st (imm:i32)<<X:SIMM16>>:$I2, mviaddr12pair:i64:$BD1)<<P:Predicate_unindexedstore>><<P:Predicate_truncstore>><<P:Predicate_truncstorei16>> - Complexity = 16
                  // Dst: (MVHHI mviaddr12pair:i64:$BD1, (SIMM16:i32 (imm:i32):$I2))
/*7709*/        0, /*End of Scope*/
/*7710*/      /*Scope*/ 21|128,1/*149*/, /*->7861*/
/*7712*/        OPC_CheckChild1Type, MVT::i32,
/*7714*/        OPC_RecordChild2, // #2 = $XBD2
/*7715*/        OPC_CheckChild2Type, MVT::i64,
/*7717*/        OPC_CheckPredicate, 5, // Predicate_unindexedstore
/*7719*/        OPC_CheckPredicate, 6, // Predicate_truncstore
/*7721*/        OPC_Scope, 68, /*->7791*/ // 2 children in Scope
/*7723*/          OPC_CheckPredicate, 7, // Predicate_truncstorei8
/*7725*/          OPC_Scope, 16, /*->7743*/ // 4 children in Scope
/*7727*/            OPC_CheckPatternPredicate, 0, // (Subtarget.hasHighWord())
/*7729*/            OPC_CheckComplexPat, /*CP*/0, /*#*/2, // selectBDXAddr20Only:$XBD2 #3 #4 #5
/*7732*/            OPC_EmitMergeInputChains1_0,
/*7733*/            OPC_MorphNodeTo, TARGET_VAL(SystemZ::STCMux), 0|OPFL_Chain|OPFL_MemRefs,
                        0/*#VTs*/, 4/*#Ops*/, 1, 3, 4, 5, 
                    // Src: (st GRX32:i32:$R1, bdxaddr20only:i64:$XBD2)<<P:Predicate_unindexedstore>><<P:Predicate_truncstore>><<P:Predicate_truncstorei8>> - Complexity = 16
                    // Dst: (STCMux GRX32:i32:$R1, bdxaddr20only:i64:$XBD2)
/*7743*/          /*Scope*/ 14, /*->7758*/
/*7744*/            OPC_CheckComplexPat, /*CP*/7, /*#*/2, // selectBDXAddr12Pair:$XBD2 #3 #4 #5
/*7747*/            OPC_EmitMergeInputChains1_0,
/*7748*/            OPC_MorphNodeTo, TARGET_VAL(SystemZ::STC), 0|OPFL_Chain|OPFL_MemRefs,
                        0/*#VTs*/, 4/*#Ops*/, 1, 3, 4, 5, 
                    // Src: (st GR32:i32:$R1, bdxaddr12pair:i64:$XBD2)<<P:Predicate_unindexedstore>><<P:Predicate_truncstore>><<P:Predicate_truncstorei8>> - Complexity = 16
                    // Dst: (STC GR32:i32:$R1, bdxaddr12pair:i64:$XBD2)
/*7758*/          /*Scope*/ 14, /*->7773*/
/*7759*/            OPC_CheckComplexPat, /*CP*/8, /*#*/2, // selectBDXAddr20Pair:$XBD2 #3 #4 #5
/*7762*/            OPC_EmitMergeInputChains1_0,
/*7763*/            OPC_MorphNodeTo, TARGET_VAL(SystemZ::STCY), 0|OPFL_Chain|OPFL_MemRefs,
                        0/*#VTs*/, 4/*#Ops*/, 1, 3, 4, 5, 
                    // Src: (st GR32:i32:$R1, bdxaddr20pair:i64:$XBD2)<<P:Predicate_unindexedstore>><<P:Predicate_truncstore>><<P:Predicate_truncstorei8>> - Complexity = 16
                    // Dst: (STCY GR32:i32:$R1, bdxaddr20pair:i64:$XBD2)
/*7773*/          /*Scope*/ 16, /*->7790*/
/*7774*/            OPC_CheckPatternPredicate, 0, // (Subtarget.hasHighWord())
/*7776*/            OPC_CheckComplexPat, /*CP*/0, /*#*/2, // selectBDXAddr20Only:$XBD2 #3 #4 #5
/*7779*/            OPC_EmitMergeInputChains1_0,
/*7780*/            OPC_MorphNodeTo, TARGET_VAL(SystemZ::STCH), 0|OPFL_Chain|OPFL_MemRefs,
                        0/*#VTs*/, 4/*#Ops*/, 1, 3, 4, 5, 
                    // Src: (st GRH32:i32:$R1, bdxaddr20only:i64:$XBD2)<<P:Predicate_unindexedstore>><<P:Predicate_truncstore>><<P:Predicate_truncstorei8>> - Complexity = 16
                    // Dst: (STCH GRH32:i32:$R1, bdxaddr20only:i64:$XBD2)
/*7790*/          0, /*End of Scope*/
/*7791*/        /*Scope*/ 68, /*->7860*/
/*7792*/          OPC_CheckPredicate, 11, // Predicate_truncstorei16
/*7794*/          OPC_Scope, 16, /*->7812*/ // 4 children in Scope
/*7796*/            OPC_CheckPatternPredicate, 0, // (Subtarget.hasHighWord())
/*7798*/            OPC_CheckComplexPat, /*CP*/0, /*#*/2, // selectBDXAddr20Only:$XBD2 #3 #4 #5
/*7801*/            OPC_EmitMergeInputChains1_0,
/*7802*/            OPC_MorphNodeTo, TARGET_VAL(SystemZ::STHMux), 0|OPFL_Chain|OPFL_MemRefs,
                        0/*#VTs*/, 4/*#Ops*/, 1, 3, 4, 5, 
                    // Src: (st GRX32:i32:$R1, bdxaddr20only:i64:$XBD2)<<P:Predicate_unindexedstore>><<P:Predicate_truncstore>><<P:Predicate_truncstorei16>> - Complexity = 16
                    // Dst: (STHMux GRX32:i32:$R1, bdxaddr20only:i64:$XBD2)
/*7812*/          /*Scope*/ 14, /*->7827*/
/*7813*/            OPC_CheckComplexPat, /*CP*/7, /*#*/2, // selectBDXAddr12Pair:$XBD2 #3 #4 #5
/*7816*/            OPC_EmitMergeInputChains1_0,
/*7817*/            OPC_MorphNodeTo, TARGET_VAL(SystemZ::STH), 0|OPFL_Chain|OPFL_MemRefs,
                        0/*#VTs*/, 4/*#Ops*/, 1, 3, 4, 5, 
                    // Src: (st GR32:i32:$R1, bdxaddr12pair:i64:$XBD2)<<P:Predicate_unindexedstore>><<P:Predicate_truncstore>><<P:Predicate_truncstorei16>> - Complexity = 16
                    // Dst: (STH GR32:i32:$R1, bdxaddr12pair:i64:$XBD2)
/*7827*/          /*Scope*/ 14, /*->7842*/
/*7828*/            OPC_CheckComplexPat, /*CP*/8, /*#*/2, // selectBDXAddr20Pair:$XBD2 #3 #4 #5
/*7831*/            OPC_EmitMergeInputChains1_0,
/*7832*/            OPC_MorphNodeTo, TARGET_VAL(SystemZ::STHY), 0|OPFL_Chain|OPFL_MemRefs,
                        0/*#VTs*/, 4/*#Ops*/, 1, 3, 4, 5, 
                    // Src: (st GR32:i32:$R1, bdxaddr20pair:i64:$XBD2)<<P:Predicate_unindexedstore>><<P:Predicate_truncstore>><<P:Predicate_truncstorei16>> - Complexity = 16
                    // Dst: (STHY GR32:i32:$R1, bdxaddr20pair:i64:$XBD2)
/*7842*/          /*Scope*/ 16, /*->7859*/
/*7843*/            OPC_CheckPatternPredicate, 0, // (Subtarget.hasHighWord())
/*7845*/            OPC_CheckComplexPat, /*CP*/0, /*#*/2, // selectBDXAddr20Only:$XBD2 #3 #4 #5
/*7848*/            OPC_EmitMergeInputChains1_0,
/*7849*/            OPC_MorphNodeTo, TARGET_VAL(SystemZ::STHH), 0|OPFL_Chain|OPFL_MemRefs,
                        0/*#VTs*/, 4/*#Ops*/, 1, 3, 4, 5, 
                    // Src: (st GRH32:i32:$R1, bdxaddr20only:i64:$XBD2)<<P:Predicate_unindexedstore>><<P:Predicate_truncstore>><<P:Predicate_truncstorei16>> - Complexity = 16
                    // Dst: (STHH GRH32:i32:$R1, bdxaddr20only:i64:$XBD2)
/*7859*/          0, /*End of Scope*/
/*7860*/        0, /*End of Scope*/
/*7861*/      /*Scope*/ 41, /*->7903*/
/*7862*/        OPC_CheckChild1Type, MVT::f32,
/*7864*/        OPC_RecordChild2, // #2 = $XBD2
/*7865*/        OPC_CheckChild2Type, MVT::i64,
/*7867*/        OPC_CheckPredicate, 5, // Predicate_unindexedstore
/*7869*/        OPC_CheckPredicate, 15, // Predicate_store
/*7871*/        OPC_Scope, 14, /*->7887*/ // 2 children in Scope
/*7873*/          OPC_CheckComplexPat, /*CP*/7, /*#*/2, // selectBDXAddr12Pair:$XBD2 #3 #4 #5
/*7876*/          OPC_EmitMergeInputChains1_0,
/*7877*/          OPC_MorphNodeTo, TARGET_VAL(SystemZ::STE), 0|OPFL_Chain|OPFL_MemRefs,
                      0/*#VTs*/, 4/*#Ops*/, 1, 3, 4, 5, 
                  // Src: (st FP32:f32:$R1, bdxaddr12pair:i64:$XBD2)<<P:Predicate_unindexedstore>><<P:Predicate_store>> - Complexity = 16
                  // Dst: (STE FP32:f32:$R1, bdxaddr12pair:i64:$XBD2)
/*7887*/        /*Scope*/ 14, /*->7902*/
/*7888*/          OPC_CheckComplexPat, /*CP*/8, /*#*/2, // selectBDXAddr20Pair:$XBD2 #3 #4 #5
/*7891*/          OPC_EmitMergeInputChains1_0,
/*7892*/          OPC_MorphNodeTo, TARGET_VAL(SystemZ::STEY), 0|OPFL_Chain|OPFL_MemRefs,
                      0/*#VTs*/, 4/*#Ops*/, 1, 3, 4, 5, 
                  // Src: (st FP32:f32:$R1, bdxaddr20pair:i64:$XBD2)<<P:Predicate_unindexedstore>><<P:Predicate_store>> - Complexity = 16
                  // Dst: (STEY FP32:f32:$R1, bdxaddr20pair:i64:$XBD2)
/*7902*/        0, /*End of Scope*/
/*7903*/      /*Scope*/ 41, /*->7945*/
/*7904*/        OPC_CheckChild1Type, MVT::f64,
/*7906*/        OPC_RecordChild2, // #2 = $XBD2
/*7907*/        OPC_CheckChild2Type, MVT::i64,
/*7909*/        OPC_CheckPredicate, 5, // Predicate_unindexedstore
/*7911*/        OPC_CheckPredicate, 15, // Predicate_store
/*7913*/        OPC_Scope, 14, /*->7929*/ // 2 children in Scope
/*7915*/          OPC_CheckComplexPat, /*CP*/7, /*#*/2, // selectBDXAddr12Pair:$XBD2 #3 #4 #5
/*7918*/          OPC_EmitMergeInputChains1_0,
/*7919*/          OPC_MorphNodeTo, TARGET_VAL(SystemZ::STD), 0|OPFL_Chain|OPFL_MemRefs,
                      0/*#VTs*/, 4/*#Ops*/, 1, 3, 4, 5, 
                  // Src: (st FP64:f64:$R1, bdxaddr12pair:i64:$XBD2)<<P:Predicate_unindexedstore>><<P:Predicate_store>> - Complexity = 16
                  // Dst: (STD FP64:f64:$R1, bdxaddr12pair:i64:$XBD2)
/*7929*/        /*Scope*/ 14, /*->7944*/
/*7930*/          OPC_CheckComplexPat, /*CP*/8, /*#*/2, // selectBDXAddr20Pair:$XBD2 #3 #4 #5
/*7933*/          OPC_EmitMergeInputChains1_0,
/*7934*/          OPC_MorphNodeTo, TARGET_VAL(SystemZ::STDY), 0|OPFL_Chain|OPFL_MemRefs,
                      0/*#VTs*/, 4/*#Ops*/, 1, 3, 4, 5, 
                  // Src: (st FP64:f64:$R1, bdxaddr20pair:i64:$XBD2)<<P:Predicate_unindexedstore>><<P:Predicate_store>> - Complexity = 16
                  // Dst: (STDY FP64:f64:$R1, bdxaddr20pair:i64:$XBD2)
/*7944*/        0, /*End of Scope*/
/*7945*/      /*Scope*/ 23, /*->7969*/
/*7946*/        OPC_CheckChild1Type, MVT::f128,
/*7948*/        OPC_RecordChild2, // #2 = $dst
/*7949*/        OPC_CheckChild2Type, MVT::i64,
/*7951*/        OPC_CheckPredicate, 5, // Predicate_unindexedstore
/*7953*/        OPC_CheckPredicate, 15, // Predicate_store
/*7955*/        OPC_CheckComplexPat, /*CP*/9, /*#*/2, // selectBDXAddr20Only128:$dst #3 #4 #5
/*7958*/        OPC_EmitMergeInputChains1_0,
/*7959*/        OPC_MorphNodeTo, TARGET_VAL(SystemZ::STX), 0|OPFL_Chain|OPFL_MemRefs,
                    0/*#VTs*/, 4/*#Ops*/, 1, 3, 4, 5, 
                // Src: (st FP128:f128:$src, bdxaddr20only128:i64:$dst)<<P:Predicate_unindexedstore>><<P:Predicate_store>> - Complexity = 16
                // Dst: (STX FP128:f128:$src, bdxaddr20only128:i64:$dst)
/*7969*/      /*Scope*/ 60|128,1/*188*/, /*->8159*/
/*7971*/        OPC_CheckChild1Type, MVT::i64,
/*7973*/        OPC_RecordChild2, // #2 = $XBD2
/*7974*/        OPC_CheckChild2Type, MVT::i64,
/*7976*/        OPC_CheckPredicate, 5, // Predicate_unindexedstore
/*7978*/        OPC_CheckPredicate, 6, // Predicate_truncstore
/*7980*/        OPC_Scope, 58, /*->8040*/ // 3 children in Scope
/*7982*/          OPC_CheckPredicate, 7, // Predicate_truncstorei8
/*7984*/          OPC_Scope, 26, /*->8012*/ // 2 children in Scope
/*7986*/            OPC_CheckComplexPat, /*CP*/7, /*#*/2, // selectBDXAddr12Pair:$XBD2 #3 #4 #5
/*7989*/            OPC_EmitMergeInputChains1_0,
/*7990*/            OPC_EmitInteger, MVT::i32, SystemZ::subreg_l32,
/*7993*/            OPC_EmitNode, TARGET_VAL(TargetOpcode::EXTRACT_SUBREG), 0,
                        1/*#VTs*/, MVT::i32, 2/*#Ops*/, 1, 6,  // Results = #7
/*8002*/            OPC_MorphNodeTo, TARGET_VAL(SystemZ::STC), 0|OPFL_Chain|OPFL_MemRefs,
                        0/*#VTs*/, 4/*#Ops*/, 7, 3, 4, 5, 
                    // Src: (st GR64:i64:$R1, bdxaddr12pair:i64:$XBD2)<<P:Predicate_unindexedstore>><<P:Predicate_truncstore>><<P:Predicate_truncstorei8>> - Complexity = 16
                    // Dst: (STC (EXTRACT_SUBREG:i32 GR64:i64:$R1, subreg_l32:i32), bdxaddr12pair:i64:$XBD2)
/*8012*/          /*Scope*/ 26, /*->8039*/
/*8013*/            OPC_CheckComplexPat, /*CP*/8, /*#*/2, // selectBDXAddr20Pair:$XBD2 #3 #4 #5
/*8016*/            OPC_EmitMergeInputChains1_0,
/*8017*/            OPC_EmitInteger, MVT::i32, SystemZ::subreg_l32,
/*8020*/            OPC_EmitNode, TARGET_VAL(TargetOpcode::EXTRACT_SUBREG), 0,
                        1/*#VTs*/, MVT::i32, 2/*#Ops*/, 1, 6,  // Results = #7
/*8029*/            OPC_MorphNodeTo, TARGET_VAL(SystemZ::STCY), 0|OPFL_Chain|OPFL_MemRefs,
                        0/*#VTs*/, 4/*#Ops*/, 7, 3, 4, 5, 
                    // Src: (st GR64:i64:$R1, bdxaddr20pair:i64:$XBD2)<<P:Predicate_unindexedstore>><<P:Predicate_truncstore>><<P:Predicate_truncstorei8>> - Complexity = 16
                    // Dst: (STCY (EXTRACT_SUBREG:i32 GR64:i64:$R1, subreg_l32:i32), bdxaddr20pair:i64:$XBD2)
/*8039*/          0, /*End of Scope*/
/*8040*/        /*Scope*/ 58, /*->8099*/
/*8041*/          OPC_CheckPredicate, 11, // Predicate_truncstorei16
/*8043*/          OPC_Scope, 26, /*->8071*/ // 2 children in Scope
/*8045*/            OPC_CheckComplexPat, /*CP*/7, /*#*/2, // selectBDXAddr12Pair:$XBD2 #3 #4 #5
/*8048*/            OPC_EmitMergeInputChains1_0,
/*8049*/            OPC_EmitInteger, MVT::i32, SystemZ::subreg_l32,
/*8052*/            OPC_EmitNode, TARGET_VAL(TargetOpcode::EXTRACT_SUBREG), 0,
                        1/*#VTs*/, MVT::i32, 2/*#Ops*/, 1, 6,  // Results = #7
/*8061*/            OPC_MorphNodeTo, TARGET_VAL(SystemZ::STH), 0|OPFL_Chain|OPFL_MemRefs,
                        0/*#VTs*/, 4/*#Ops*/, 7, 3, 4, 5, 
                    // Src: (st GR64:i64:$R1, bdxaddr12pair:i64:$XBD2)<<P:Predicate_unindexedstore>><<P:Predicate_truncstore>><<P:Predicate_truncstorei16>> - Complexity = 16
                    // Dst: (STH (EXTRACT_SUBREG:i32 GR64:i64:$R1, subreg_l32:i32), bdxaddr12pair:i64:$XBD2)
/*8071*/          /*Scope*/ 26, /*->8098*/
/*8072*/            OPC_CheckComplexPat, /*CP*/8, /*#*/2, // selectBDXAddr20Pair:$XBD2 #3 #4 #5
/*8075*/            OPC_EmitMergeInputChains1_0,
/*8076*/            OPC_EmitInteger, MVT::i32, SystemZ::subreg_l32,
/*8079*/            OPC_EmitNode, TARGET_VAL(TargetOpcode::EXTRACT_SUBREG), 0,
                        1/*#VTs*/, MVT::i32, 2/*#Ops*/, 1, 6,  // Results = #7
/*8088*/            OPC_MorphNodeTo, TARGET_VAL(SystemZ::STHY), 0|OPFL_Chain|OPFL_MemRefs,
                        0/*#VTs*/, 4/*#Ops*/, 7, 3, 4, 5, 
                    // Src: (st GR64:i64:$R1, bdxaddr20pair:i64:$XBD2)<<P:Predicate_unindexedstore>><<P:Predicate_truncstore>><<P:Predicate_truncstorei16>> - Complexity = 16
                    // Dst: (STHY (EXTRACT_SUBREG:i32 GR64:i64:$R1, subreg_l32:i32), bdxaddr20pair:i64:$XBD2)
/*8098*/          0, /*End of Scope*/
/*8099*/        /*Scope*/ 58, /*->8158*/
/*8100*/          OPC_CheckPredicate, 19, // Predicate_truncstorei32
/*8102*/          OPC_Scope, 26, /*->8130*/ // 2 children in Scope
/*8104*/            OPC_CheckComplexPat, /*CP*/7, /*#*/2, // selectBDXAddr12Pair:$XBD2 #3 #4 #5
/*8107*/            OPC_EmitMergeInputChains1_0,
/*8108*/            OPC_EmitInteger, MVT::i32, SystemZ::subreg_l32,
/*8111*/            OPC_EmitNode, TARGET_VAL(TargetOpcode::EXTRACT_SUBREG), 0,
                        1/*#VTs*/, MVT::i32, 2/*#Ops*/, 1, 6,  // Results = #7
/*8120*/            OPC_MorphNodeTo, TARGET_VAL(SystemZ::ST), 0|OPFL_Chain|OPFL_MemRefs,
                        0/*#VTs*/, 4/*#Ops*/, 7, 3, 4, 5, 
                    // Src: (st GR64:i64:$R1, bdxaddr12pair:i64:$XBD2)<<P:Predicate_unindexedstore>><<P:Predicate_truncstore>><<P:Predicate_truncstorei32>> - Complexity = 16
                    // Dst: (ST (EXTRACT_SUBREG:i32 GR64:i64:$R1, subreg_l32:i32), bdxaddr12pair:i64:$XBD2)
/*8130*/          /*Scope*/ 26, /*->8157*/
/*8131*/            OPC_CheckComplexPat, /*CP*/8, /*#*/2, // selectBDXAddr20Pair:$XBD2 #3 #4 #5
/*8134*/            OPC_EmitMergeInputChains1_0,
/*8135*/            OPC_EmitInteger, MVT::i32, SystemZ::subreg_l32,
/*8138*/            OPC_EmitNode, TARGET_VAL(TargetOpcode::EXTRACT_SUBREG), 0,
                        1/*#VTs*/, MVT::i32, 2/*#Ops*/, 1, 6,  // Results = #7
/*8147*/            OPC_MorphNodeTo, TARGET_VAL(SystemZ::STY), 0|OPFL_Chain|OPFL_MemRefs,
                        0/*#VTs*/, 4/*#Ops*/, 7, 3, 4, 5, 
                    // Src: (st GR64:i64:$R1, bdxaddr20pair:i64:$XBD2)<<P:Predicate_unindexedstore>><<P:Predicate_truncstore>><<P:Predicate_truncstorei32>> - Complexity = 16
                    // Dst: (STY (EXTRACT_SUBREG:i32 GR64:i64:$R1, subreg_l32:i32), bdxaddr20pair:i64:$XBD2)
/*8157*/          0, /*End of Scope*/
/*8158*/        0, /*End of Scope*/
/*8159*/      0, /*End of Scope*/
/*8160*/    0, /*End of Scope*/
/*8161*/  /*SwitchOpcode*/ 122|128,1/*250*/,  TARGET_VAL(ISD::SRA),// ->8415
/*8165*/    OPC_Scope, 79|128,1/*207*/, /*->8375*/ // 2 children in Scope
/*8168*/      OPC_MoveChild, 0,
/*8170*/      OPC_CheckOpcode, TARGET_VAL(ISD::SHL),
/*8173*/      OPC_MoveChild, 0,
/*8175*/      OPC_SwitchOpcode /*2 cases */, 98,  TARGET_VAL(ISD::ANY_EXTEND),// ->8277
/*8179*/        OPC_MoveChild, 0,
/*8181*/        OPC_CheckOpcode, TARGET_VAL(SystemZISD::SELECT_CCMASK),
/*8184*/        OPC_CaptureGlueInput,
/*8185*/        OPC_MoveChild, 0,
/*8187*/        OPC_CheckInteger, 1, 
/*8189*/        OPC_MoveParent,
/*8190*/        OPC_MoveChild, 1,
/*8192*/        OPC_CheckInteger, 0, 
/*8194*/        OPC_MoveParent,
/*8195*/        OPC_RecordChild2, // #0 = $valid
/*8196*/        OPC_MoveChild, 2,
/*8198*/        OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*8201*/        OPC_CheckPredicate, 4, // Predicate_uimm8zx4
/*8203*/        OPC_MoveParent,
/*8204*/        OPC_RecordChild3, // #1 = $cc
/*8205*/        OPC_MoveChild, 3,
/*8207*/        OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*8210*/        OPC_CheckPredicate, 4, // Predicate_uimm8zx4
/*8212*/        OPC_MoveParent,
/*8213*/        OPC_MoveParent,
/*8214*/        OPC_MoveParent,
/*8215*/        OPC_MoveChild, 1,
/*8217*/        OPC_CheckInteger, 63, 
/*8219*/        OPC_CheckType, MVT::i32,
/*8221*/        OPC_MoveParent,
/*8222*/        OPC_MoveParent,
/*8223*/        OPC_MoveChild, 1,
/*8225*/        OPC_CheckInteger, 63, 
/*8227*/        OPC_CheckType, MVT::i32,
/*8229*/        OPC_MoveParent,
/*8230*/        OPC_EmitInteger, MVT::i64, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*8242*/        OPC_EmitNode, TARGET_VAL(SystemZ::LGHI), 0,
                    1/*#VTs*/, MVT::i64, 1/*#Ops*/, 2,  // Results = #3
/*8250*/        OPC_EmitInteger, MVT::i64, 0, 
/*8253*/        OPC_EmitNode, TARGET_VAL(SystemZ::LGHI), 0,
                    1/*#VTs*/, MVT::i64, 1/*#Ops*/, 4,  // Results = #5
/*8261*/        OPC_EmitConvertToTarget, 0,
/*8263*/        OPC_EmitConvertToTarget, 1,
/*8265*/        OPC_MorphNodeTo, TARGET_VAL(SystemZ::Select64), 0|OPFL_GlueInput,
                    2/*#VTs*/, MVT::i64, MVT::i32, 4/*#Ops*/, 3, 5, 6, 7, 
                // Src: (sra:i64 (shl:i64 (anyext:i64 (z_select_ccmask:i32 1:i32, 0:i32, (imm:i8)<<P:Predicate_uimm8zx4>>:$valid, (imm:i8)<<P:Predicate_uimm8zx4>>:$cc)), 63:i32), 63:i32) - Complexity = 40
                // Dst: (Select64:i64:i32 (LGHI:i64 -1:i64), (LGHI:i64 0:i64), (imm:i8)<<P:Predicate_uimm8zx4>>:$valid, (imm:i8)<<P:Predicate_uimm8zx4>>:$cc)
/*8277*/      /*SwitchOpcode*/ 94,  TARGET_VAL(SystemZISD::SELECT_CCMASK),// ->8374
/*8280*/        OPC_CaptureGlueInput,
/*8281*/        OPC_MoveChild, 0,
/*8283*/        OPC_CheckInteger, 1, 
/*8285*/        OPC_MoveParent,
/*8286*/        OPC_MoveChild, 1,
/*8288*/        OPC_CheckInteger, 0, 
/*8290*/        OPC_MoveParent,
/*8291*/        OPC_RecordChild2, // #0 = $valid
/*8292*/        OPC_MoveChild, 2,
/*8294*/        OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*8297*/        OPC_CheckPredicate, 4, // Predicate_uimm8zx4
/*8299*/        OPC_MoveParent,
/*8300*/        OPC_RecordChild3, // #1 = $cc
/*8301*/        OPC_MoveChild, 3,
/*8303*/        OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*8306*/        OPC_CheckPredicate, 4, // Predicate_uimm8zx4
/*8308*/        OPC_MoveParent,
/*8309*/        OPC_MoveParent,
/*8310*/        OPC_MoveChild, 1,
/*8312*/        OPC_CheckInteger, 31, 
/*8314*/        OPC_CheckType, MVT::i32,
/*8316*/        OPC_MoveParent,
/*8317*/        OPC_MoveParent,
/*8318*/        OPC_MoveChild, 1,
/*8320*/        OPC_CheckInteger, 31, 
/*8322*/        OPC_CheckType, MVT::i32,
/*8324*/        OPC_MoveParent,
/*8325*/        OPC_CheckType, MVT::i32,
/*8327*/        OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*8339*/        OPC_EmitNode, TARGET_VAL(SystemZ::LHI), 0,
                    1/*#VTs*/, MVT::i32, 1/*#Ops*/, 2,  // Results = #3
/*8347*/        OPC_EmitInteger, MVT::i32, 0, 
/*8350*/        OPC_EmitNode, TARGET_VAL(SystemZ::LHI), 0,
                    1/*#VTs*/, MVT::i32, 1/*#Ops*/, 4,  // Results = #5
/*8358*/        OPC_EmitConvertToTarget, 0,
/*8360*/        OPC_EmitConvertToTarget, 1,
/*8362*/        OPC_MorphNodeTo, TARGET_VAL(SystemZ::Select32), 0|OPFL_GlueInput,
                    2/*#VTs*/, MVT::i32, MVT::i32, 4/*#Ops*/, 3, 5, 6, 7, 
                // Src: (sra:i32 (shl:i32 (z_select_ccmask:i32 1:i32, 0:i32, (imm:i8)<<P:Predicate_uimm8zx4>>:$valid, (imm:i8)<<P:Predicate_uimm8zx4>>:$cc), 31:i32), 31:i32) - Complexity = 37
                // Dst: (Select32:i32:i32 (LHI:i32 -1:i32), (LHI:i32 0:i32), (imm:i8)<<P:Predicate_uimm8zx4>>:$valid, (imm:i8)<<P:Predicate_uimm8zx4>>:$cc)
/*8374*/      0, // EndSwitchOpcode
/*8375*/    /*Scope*/ 38, /*->8414*/
/*8376*/      OPC_RecordChild0, // #0 = $R1src
/*8377*/      OPC_RecordChild1, // #1 = $BD2
/*8378*/      OPC_CheckChild1Type, MVT::i32,
/*8380*/      OPC_SwitchType /*2 cases */, 14,  MVT::i32,// ->8397
/*8383*/        OPC_CheckComplexPat, /*CP*/11, /*#*/1, // selectBDAddr12Only:$BD2 #2 #3
/*8386*/        OPC_MorphNodeTo, TARGET_VAL(SystemZ::SRA), 0,
                    2/*#VTs*/, MVT::i32, MVT::i32, 3/*#Ops*/, 0, 2, 3, 
                // Src: (sra:i32 GR32:i32:$R1src, shift12only:i32:$BD2) - Complexity = 12
                // Dst: (SRA:i32:i32 GR32:i32:$R1src, shift12only:i32:$BD2)
/*8397*/      /*SwitchType*/ 14,  MVT::i64,// ->8413
/*8399*/        OPC_CheckComplexPat, /*CP*/12, /*#*/1, // selectBDAddr20Only:$BD2 #2 #3
/*8402*/        OPC_MorphNodeTo, TARGET_VAL(SystemZ::SRAG), 0,
                    2/*#VTs*/, MVT::i64, MVT::i32, 3/*#Ops*/, 0, 2, 3, 
                // Src: (sra:i64 GR64:i64:$R3, shift20only:i32:$BD2) - Complexity = 12
                // Dst: (SRAG:i64:i32 GR64:i64:$R3, shift20only:i32:$BD2)
/*8413*/      0, // EndSwitchType
/*8414*/    0, /*End of Scope*/
/*8415*/  /*SwitchOpcode*/ 56|128,10/*1336*/,  TARGET_VAL(ISD::SUB),// ->9755
/*8419*/    OPC_Scope, 121|128,6/*889*/, /*->9311*/ // 7 children in Scope
/*8422*/      OPC_MoveChild, 0,
/*8424*/      OPC_CheckInteger, 0, 
/*8426*/      OPC_MoveParent,
/*8427*/      OPC_MoveChild, 1,
/*8429*/      OPC_CheckOpcode, TARGET_VAL(ISD::XOR),
/*8432*/      OPC_MoveChild, 0,
/*8434*/      OPC_SwitchOpcode /*2 cases */, 72|128,3/*456*/,  TARGET_VAL(ISD::ADD),// ->8895
/*8439*/        OPC_Scope, 32|128,2/*288*/, /*->8730*/ // 3 children in Scope
/*8442*/          OPC_MoveChild, 0,
/*8444*/          OPC_SwitchOpcode /*3 cases */, 55,  TARGET_VAL(ISD::SIGN_EXTEND),// ->8503
/*8448*/            OPC_RecordChild0, // #0 = $src
/*8449*/            OPC_MoveParent,
/*8450*/            OPC_MoveChild, 1,
/*8452*/            OPC_CheckOpcode, TARGET_VAL(ISD::SRA),
/*8455*/            OPC_MoveChild, 0,
/*8457*/            OPC_CheckOpcode, TARGET_VAL(ISD::SIGN_EXTEND),
/*8460*/            OPC_CheckChild0Same, 0,
/*8462*/            OPC_MoveParent,
/*8463*/            OPC_MoveChild, 1,
/*8465*/            OPC_CheckInteger, 63, 
/*8467*/            OPC_CheckType, MVT::i32,
/*8469*/            OPC_MoveParent,
/*8470*/            OPC_MoveParent,
/*8471*/            OPC_MoveParent,
/*8472*/            OPC_MoveChild, 1,
/*8474*/            OPC_CheckOpcode, TARGET_VAL(ISD::SRA),
/*8477*/            OPC_MoveChild, 0,
/*8479*/            OPC_CheckOpcode, TARGET_VAL(ISD::SIGN_EXTEND),
/*8482*/            OPC_CheckChild0Same, 0,
/*8484*/            OPC_MoveParent,
/*8485*/            OPC_MoveChild, 1,
/*8487*/            OPC_CheckInteger, 63, 
/*8489*/            OPC_CheckType, MVT::i32,
/*8491*/            OPC_MoveParent,
/*8492*/            OPC_MoveParent,
/*8493*/            OPC_MoveParent,
/*8494*/            OPC_MorphNodeTo, TARGET_VAL(SystemZ::LNGFR), 0,
                        2/*#VTs*/, MVT::i64, MVT::i32, 1/*#Ops*/, 0, 
                    // Src: (sub:i64 0:i64, (xor:i64 (add:i64 (sext:i64 GR32:i32:$src), (sra:i64 (sext:i64 GR32:i32:$src), 63:i32)), (sra:i64 (sext:i64 GR32:i32:$src), 63:i32))) - Complexity = 39
                    // Dst: (LNGFR:i64:i32 GR32:i32:$src)
/*8503*/          /*SwitchOpcode*/ 9|128,1/*137*/,  TARGET_VAL(ISD::SRA),// ->8644
/*8507*/            OPC_MoveChild, 0,
/*8509*/            OPC_SwitchOpcode /*2 cases */, 50,  TARGET_VAL(ISD::SIGN_EXTEND),// ->8563
/*8513*/              OPC_RecordChild0, // #0 = $src
/*8514*/              OPC_MoveParent,
/*8515*/              OPC_MoveChild, 1,
/*8517*/              OPC_CheckInteger, 63, 
/*8519*/              OPC_CheckType, MVT::i32,
/*8521*/              OPC_MoveParent,
/*8522*/              OPC_MoveParent,
/*8523*/              OPC_MoveChild, 1,
/*8525*/              OPC_CheckOpcode, TARGET_VAL(ISD::SIGN_EXTEND),
/*8528*/              OPC_CheckChild0Same, 0,
/*8530*/              OPC_MoveParent,
/*8531*/              OPC_MoveParent,
/*8532*/              OPC_MoveChild, 1,
/*8534*/              OPC_CheckOpcode, TARGET_VAL(ISD::SRA),
/*8537*/              OPC_MoveChild, 0,
/*8539*/              OPC_CheckOpcode, TARGET_VAL(ISD::SIGN_EXTEND),
/*8542*/              OPC_CheckChild0Same, 0,
/*8544*/              OPC_MoveParent,
/*8545*/              OPC_MoveChild, 1,
/*8547*/              OPC_CheckInteger, 63, 
/*8549*/              OPC_CheckType, MVT::i32,
/*8551*/              OPC_MoveParent,
/*8552*/              OPC_MoveParent,
/*8553*/              OPC_MoveParent,
/*8554*/              OPC_MorphNodeTo, TARGET_VAL(SystemZ::LNGFR), 0,
                          2/*#VTs*/, MVT::i64, MVT::i32, 1/*#Ops*/, 0, 
                      // Src: (sub:i64 0:i64, (xor:i64 (add:i64 (sra:i64 (sext:i64 GR32:i32:$src), 63:i32), (sext:i64 GR32:i32:$src)), (sra:i64 (sext:i64 GR32:i32:$src), 63:i32))) - Complexity = 39
                      // Dst: (LNGFR:i64:i32 GR32:i32:$src)
/*8563*/            /*SwitchOpcode*/ 77,  TARGET_VAL(ISD::SIGN_EXTEND_INREG),// ->8643
/*8566*/              OPC_RecordChild0, // #0 = $src
/*8567*/              OPC_MoveChild, 1,
/*8569*/              OPC_CheckValueType, MVT::i32,
/*8571*/              OPC_MoveParent,
/*8572*/              OPC_MoveParent,
/*8573*/              OPC_MoveChild, 1,
/*8575*/              OPC_CheckInteger, 63, 
/*8577*/              OPC_CheckType, MVT::i32,
/*8579*/              OPC_MoveParent,
/*8580*/              OPC_MoveParent,
/*8581*/              OPC_MoveChild, 1,
/*8583*/              OPC_CheckOpcode, TARGET_VAL(ISD::SIGN_EXTEND_INREG),
/*8586*/              OPC_CheckChild0Same, 0,
/*8588*/              OPC_MoveChild, 1,
/*8590*/              OPC_CheckValueType, MVT::i32,
/*8592*/              OPC_MoveParent,
/*8593*/              OPC_MoveParent,
/*8594*/              OPC_MoveParent,
/*8595*/              OPC_MoveChild, 1,
/*8597*/              OPC_CheckOpcode, TARGET_VAL(ISD::SRA),
/*8600*/              OPC_MoveChild, 0,
/*8602*/              OPC_CheckOpcode, TARGET_VAL(ISD::SIGN_EXTEND_INREG),
/*8605*/              OPC_CheckChild0Same, 0,
/*8607*/              OPC_MoveChild, 1,
/*8609*/              OPC_CheckValueType, MVT::i32,
/*8611*/              OPC_MoveParent,
/*8612*/              OPC_MoveParent,
/*8613*/              OPC_MoveChild, 1,
/*8615*/              OPC_CheckInteger, 63, 
/*8617*/              OPC_CheckType, MVT::i32,
/*8619*/              OPC_MoveParent,
/*8620*/              OPC_MoveParent,
/*8621*/              OPC_MoveParent,
/*8622*/              OPC_EmitInteger, MVT::i32, SystemZ::subreg_l32,
/*8625*/              OPC_EmitNode, TARGET_VAL(TargetOpcode::EXTRACT_SUBREG), 0,
                          1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1,  // Results = #2
/*8634*/              OPC_MorphNodeTo, TARGET_VAL(SystemZ::LNGFR), 0,
                          2/*#VTs*/, MVT::i64, MVT::i32, 1/*#Ops*/, 2, 
                      // Src: (sub:i64 0:i64, (xor:i64 (add:i64 (sra:i64 (sext_inreg:i64 GR64:i64:$src, i32:Other), 63:i32), (sext_inreg:i64 GR64:i64:$src, i32:Other)), (sra:i64 (sext_inreg:i64 GR64:i64:$src, i32:Other), 63:i32))) - Complexity = 39
                      // Dst: (LNGFR:i64:i32 (EXTRACT_SUBREG:i32 GR64:i64:$src, subreg_l32:i32))
/*8643*/            0, // EndSwitchOpcode
/*8644*/          /*SwitchOpcode*/ 82,  TARGET_VAL(ISD::SIGN_EXTEND_INREG),// ->8729
/*8647*/            OPC_RecordChild0, // #0 = $src
/*8648*/            OPC_MoveChild, 1,
/*8650*/            OPC_CheckValueType, MVT::i32,
/*8652*/            OPC_MoveParent,
/*8653*/            OPC_MoveParent,
/*8654*/            OPC_MoveChild, 1,
/*8656*/            OPC_CheckOpcode, TARGET_VAL(ISD::SRA),
/*8659*/            OPC_MoveChild, 0,
/*8661*/            OPC_CheckOpcode, TARGET_VAL(ISD::SIGN_EXTEND_INREG),
/*8664*/            OPC_CheckChild0Same, 0,
/*8666*/            OPC_MoveChild, 1,
/*8668*/            OPC_CheckValueType, MVT::i32,
/*8670*/            OPC_MoveParent,
/*8671*/            OPC_MoveParent,
/*8672*/            OPC_MoveChild, 1,
/*8674*/            OPC_CheckInteger, 63, 
/*8676*/            OPC_CheckType, MVT::i32,
/*8678*/            OPC_MoveParent,
/*8679*/            OPC_MoveParent,
/*8680*/            OPC_MoveParent,
/*8681*/            OPC_MoveChild, 1,
/*8683*/            OPC_CheckOpcode, TARGET_VAL(ISD::SRA),
/*8686*/            OPC_MoveChild, 0,
/*8688*/            OPC_CheckOpcode, TARGET_VAL(ISD::SIGN_EXTEND_INREG),
/*8691*/            OPC_CheckChild0Same, 0,
/*8693*/            OPC_MoveChild, 1,
/*8695*/            OPC_CheckValueType, MVT::i32,
/*8697*/            OPC_MoveParent,
/*8698*/            OPC_MoveParent,
/*8699*/            OPC_MoveChild, 1,
/*8701*/            OPC_CheckInteger, 63, 
/*8703*/            OPC_CheckType, MVT::i32,
/*8705*/            OPC_MoveParent,
/*8706*/            OPC_MoveParent,
/*8707*/            OPC_MoveParent,
/*8708*/            OPC_EmitInteger, MVT::i32, SystemZ::subreg_l32,
/*8711*/            OPC_EmitNode, TARGET_VAL(TargetOpcode::EXTRACT_SUBREG), 0,
                        1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1,  // Results = #2
/*8720*/            OPC_MorphNodeTo, TARGET_VAL(SystemZ::LNGFR), 0,
                        2/*#VTs*/, MVT::i64, MVT::i32, 1/*#Ops*/, 2, 
                    // Src: (sub:i64 0:i64, (xor:i64 (add:i64 (sext_inreg:i64 GR64:i64:$src, i32:Other), (sra:i64 (sext_inreg:i64 GR64:i64:$src, i32:Other), 63:i32)), (sra:i64 (sext_inreg:i64 GR64:i64:$src, i32:Other), 63:i32))) - Complexity = 39
                    // Dst: (LNGFR:i64:i32 (EXTRACT_SUBREG:i32 GR64:i64:$src, subreg_l32:i32))
/*8729*/          0, // EndSwitchOpcode
/*8730*/        /*Scope*/ 80, /*->8811*/
/*8731*/          OPC_RecordChild0, // #0 = $R2
/*8732*/          OPC_MoveChild, 1,
/*8734*/          OPC_CheckOpcode, TARGET_VAL(ISD::SRA),
/*8737*/          OPC_CheckChild0Same, 0,
/*8739*/          OPC_MoveChild, 1,
/*8741*/          OPC_CheckType, MVT::i32,
/*8743*/          OPC_Scope, 32, /*->8777*/ // 2 children in Scope
/*8745*/            OPC_CheckInteger, 31, 
/*8747*/            OPC_MoveParent,
/*8748*/            OPC_MoveParent,
/*8749*/            OPC_MoveParent,
/*8750*/            OPC_MoveChild, 1,
/*8752*/            OPC_CheckOpcode, TARGET_VAL(ISD::SRA),
/*8755*/            OPC_CheckChild0Same, 0,
/*8757*/            OPC_MoveChild, 1,
/*8759*/            OPC_CheckInteger, 31, 
/*8761*/            OPC_CheckType, MVT::i32,
/*8763*/            OPC_MoveParent,
/*8764*/            OPC_MoveParent,
/*8765*/            OPC_MoveParent,
/*8766*/            OPC_CheckType, MVT::i32,
/*8768*/            OPC_MorphNodeTo, TARGET_VAL(SystemZ::LNR), 0,
                        2/*#VTs*/, MVT::i32, MVT::i32, 1/*#Ops*/, 0, 
                    // Src: (sub:i32 0:i32, (xor:i32 (add:i32 GR32:i32:$R2, (sra:i32 GR32:i32:$R2, 31:i32)), (sra:i32 GR32:i32:$R2, 31:i32))) - Complexity = 30
                    // Dst: (LNR:i32:i32 GR32:i32:$R2)
/*8777*/          /*Scope*/ 32, /*->8810*/
/*8778*/            OPC_CheckInteger, 63, 
/*8780*/            OPC_MoveParent,
/*8781*/            OPC_MoveParent,
/*8782*/            OPC_MoveParent,
/*8783*/            OPC_MoveChild, 1,
/*8785*/            OPC_CheckOpcode, TARGET_VAL(ISD::SRA),
/*8788*/            OPC_CheckChild0Same, 0,
/*8790*/            OPC_MoveChild, 1,
/*8792*/            OPC_CheckInteger, 63, 
/*8794*/            OPC_CheckType, MVT::i32,
/*8796*/            OPC_MoveParent,
/*8797*/            OPC_MoveParent,
/*8798*/            OPC_MoveParent,
/*8799*/            OPC_CheckType, MVT::i64,
/*8801*/            OPC_MorphNodeTo, TARGET_VAL(SystemZ::LNGR), 0,
                        2/*#VTs*/, MVT::i64, MVT::i32, 1/*#Ops*/, 0, 
                    // Src: (sub:i64 0:i64, (xor:i64 (add:i64 GR64:i64:$R2, (sra:i64 GR64:i64:$R2, 63:i32)), (sra:i64 GR64:i64:$R2, 63:i32))) - Complexity = 30
                    // Dst: (LNGR:i64:i32 GR64:i64:$R2)
/*8810*/          0, /*End of Scope*/
/*8811*/        /*Scope*/ 82, /*->8894*/
/*8812*/          OPC_MoveChild, 0,
/*8814*/          OPC_CheckOpcode, TARGET_VAL(ISD::SRA),
/*8817*/          OPC_RecordChild0, // #0 = $R2
/*8818*/          OPC_MoveChild, 1,
/*8820*/          OPC_CheckType, MVT::i32,
/*8822*/          OPC_Scope, 34, /*->8858*/ // 2 children in Scope
/*8824*/            OPC_CheckInteger, 31, 
/*8826*/            OPC_MoveParent,
/*8827*/            OPC_MoveParent,
/*8828*/            OPC_CheckChild1Same, 0,
/*8830*/            OPC_MoveParent,
/*8831*/            OPC_MoveChild, 1,
/*8833*/            OPC_CheckOpcode, TARGET_VAL(ISD::SRA),
/*8836*/            OPC_CheckChild0Same, 0,
/*8838*/            OPC_MoveChild, 1,
/*8840*/            OPC_CheckInteger, 31, 
/*8842*/            OPC_CheckType, MVT::i32,
/*8844*/            OPC_MoveParent,
/*8845*/            OPC_MoveParent,
/*8846*/            OPC_MoveParent,
/*8847*/            OPC_CheckType, MVT::i32,
/*8849*/            OPC_MorphNodeTo, TARGET_VAL(SystemZ::LNR), 0,
                        2/*#VTs*/, MVT::i32, MVT::i32, 1/*#Ops*/, 0, 
                    // Src: (sub:i32 0:i32, (xor:i32 (add:i32 (sra:i32 GR32:i32:$R2, 31:i32), GR32:i32:$R2), (sra:i32 GR32:i32:$R2, 31:i32))) - Complexity = 30
                    // Dst: (LNR:i32:i32 GR32:i32:$R2)
/*8858*/          /*Scope*/ 34, /*->8893*/
/*8859*/            OPC_CheckInteger, 63, 
/*8861*/            OPC_MoveParent,
/*8862*/            OPC_MoveParent,
/*8863*/            OPC_CheckChild1Same, 0,
/*8865*/            OPC_MoveParent,
/*8866*/            OPC_MoveChild, 1,
/*8868*/            OPC_CheckOpcode, TARGET_VAL(ISD::SRA),
/*8871*/            OPC_CheckChild0Same, 0,
/*8873*/            OPC_MoveChild, 1,
/*8875*/            OPC_CheckInteger, 63, 
/*8877*/            OPC_CheckType, MVT::i32,
/*8879*/            OPC_MoveParent,
/*8880*/            OPC_MoveParent,
/*8881*/            OPC_MoveParent,
/*8882*/            OPC_CheckType, MVT::i64,
/*8884*/            OPC_MorphNodeTo, TARGET_VAL(SystemZ::LNGR), 0,
                        2/*#VTs*/, MVT::i64, MVT::i32, 1/*#Ops*/, 0, 
                    // Src: (sub:i64 0:i64, (xor:i64 (add:i64 (sra:i64 GR64:i64:$R2, 63:i32), GR64:i64:$R2), (sra:i64 GR64:i64:$R2, 63:i32))) - Complexity = 30
                    // Dst: (LNGR:i64:i32 GR64:i64:$R2)
/*8893*/          0, /*End of Scope*/
/*8894*/        0, /*End of Scope*/
/*8895*/      /*SwitchOpcode*/ 27|128,3/*411*/,  TARGET_VAL(ISD::SRA),// ->9310
/*8899*/        OPC_Scope, 122|128,1/*250*/, /*->9152*/ // 2 children in Scope
/*8902*/          OPC_MoveChild, 0,
/*8904*/          OPC_SwitchOpcode /*2 cases */, 95,  TARGET_VAL(ISD::SIGN_EXTEND),// ->9003
/*8908*/            OPC_RecordChild0, // #0 = $src
/*8909*/            OPC_MoveParent,
/*8910*/            OPC_MoveChild, 1,
/*8912*/            OPC_CheckInteger, 63, 
/*8914*/            OPC_CheckType, MVT::i32,
/*8916*/            OPC_MoveParent,
/*8917*/            OPC_MoveParent,
/*8918*/            OPC_MoveChild, 1,
/*8920*/            OPC_CheckOpcode, TARGET_VAL(ISD::ADD),
/*8923*/            OPC_MoveChild, 0,
/*8925*/            OPC_SwitchOpcode /*2 cases */, 35,  TARGET_VAL(ISD::SIGN_EXTEND),// ->8964
/*8929*/              OPC_CheckChild0Same, 0,
/*8931*/              OPC_MoveParent,
/*8932*/              OPC_MoveChild, 1,
/*8934*/              OPC_CheckOpcode, TARGET_VAL(ISD::SRA),
/*8937*/              OPC_MoveChild, 0,
/*8939*/              OPC_CheckOpcode, TARGET_VAL(ISD::SIGN_EXTEND),
/*8942*/              OPC_CheckChild0Same, 0,
/*8944*/              OPC_MoveParent,
/*8945*/              OPC_MoveChild, 1,
/*8947*/              OPC_CheckInteger, 63, 
/*8949*/              OPC_CheckType, MVT::i32,
/*8951*/              OPC_MoveParent,
/*8952*/              OPC_MoveParent,
/*8953*/              OPC_MoveParent,
/*8954*/              OPC_MoveParent,
/*8955*/              OPC_MorphNodeTo, TARGET_VAL(SystemZ::LNGFR), 0,
                          2/*#VTs*/, MVT::i64, MVT::i32, 1/*#Ops*/, 0, 
                      // Src: (sub:i64 0:i64, (xor:i64 (sra:i64 (sext:i64 GR32:i32:$src), 63:i32), (add:i64 (sext:i64 GR32:i32:$src), (sra:i64 (sext:i64 GR32:i32:$src), 63:i32)))) - Complexity = 39
                      // Dst: (LNGFR:i64:i32 GR32:i32:$src)
/*8964*/            /*SwitchOpcode*/ 35,  TARGET_VAL(ISD::SRA),// ->9002
/*8967*/              OPC_MoveChild, 0,
/*8969*/              OPC_CheckOpcode, TARGET_VAL(ISD::SIGN_EXTEND),
/*8972*/              OPC_CheckChild0Same, 0,
/*8974*/              OPC_MoveParent,
/*8975*/              OPC_MoveChild, 1,
/*8977*/              OPC_CheckInteger, 63, 
/*8979*/              OPC_CheckType, MVT::i32,
/*8981*/              OPC_MoveParent,
/*8982*/              OPC_MoveParent,
/*8983*/              OPC_MoveChild, 1,
/*8985*/              OPC_CheckOpcode, TARGET_VAL(ISD::SIGN_EXTEND),
/*8988*/              OPC_CheckChild0Same, 0,
/*8990*/              OPC_MoveParent,
/*8991*/              OPC_MoveParent,
/*8992*/              OPC_MoveParent,
/*8993*/              OPC_MorphNodeTo, TARGET_VAL(SystemZ::LNGFR), 0,
                          2/*#VTs*/, MVT::i64, MVT::i32, 1/*#Ops*/, 0, 
                      // Src: (sub:i64 0:i64, (xor:i64 (sra:i64 (sext:i64 GR32:i32:$src), 63:i32), (add:i64 (sra:i64 (sext:i64 GR32:i32:$src), 63:i32), (sext:i64 GR32:i32:$src)))) - Complexity = 39
                      // Dst: (LNGFR:i64:i32 GR32:i32:$src)
/*9002*/            0, // EndSwitchOpcode
/*9003*/          /*SwitchOpcode*/ 16|128,1/*144*/,  TARGET_VAL(ISD::SIGN_EXTEND_INREG),// ->9151
/*9007*/            OPC_RecordChild0, // #0 = $src
/*9008*/            OPC_MoveChild, 1,
/*9010*/            OPC_CheckValueType, MVT::i32,
/*9012*/            OPC_MoveParent,
/*9013*/            OPC_MoveParent,
/*9014*/            OPC_MoveChild, 1,
/*9016*/            OPC_CheckInteger, 63, 
/*9018*/            OPC_CheckType, MVT::i32,
/*9020*/            OPC_MoveParent,
/*9021*/            OPC_MoveParent,
/*9022*/            OPC_MoveChild, 1,
/*9024*/            OPC_CheckOpcode, TARGET_VAL(ISD::ADD),
/*9027*/            OPC_MoveChild, 0,
/*9029*/            OPC_SwitchOpcode /*2 cases */, 57,  TARGET_VAL(ISD::SIGN_EXTEND_INREG),// ->9090
/*9033*/              OPC_CheckChild0Same, 0,
/*9035*/              OPC_MoveChild, 1,
/*9037*/              OPC_CheckValueType, MVT::i32,
/*9039*/              OPC_MoveParent,
/*9040*/              OPC_MoveParent,
/*9041*/              OPC_MoveChild, 1,
/*9043*/              OPC_CheckOpcode, TARGET_VAL(ISD::SRA),
/*9046*/              OPC_MoveChild, 0,
/*9048*/              OPC_CheckOpcode, TARGET_VAL(ISD::SIGN_EXTEND_INREG),
/*9051*/              OPC_CheckChild0Same, 0,
/*9053*/              OPC_MoveChild, 1,
/*9055*/              OPC_CheckValueType, MVT::i32,
/*9057*/              OPC_MoveParent,
/*9058*/              OPC_MoveParent,
/*9059*/              OPC_MoveChild, 1,
/*9061*/              OPC_CheckInteger, 63, 
/*9063*/              OPC_CheckType, MVT::i32,
/*9065*/              OPC_MoveParent,
/*9066*/              OPC_MoveParent,
/*9067*/              OPC_MoveParent,
/*9068*/              OPC_MoveParent,
/*9069*/              OPC_EmitInteger, MVT::i32, SystemZ::subreg_l32,
/*9072*/              OPC_EmitNode, TARGET_VAL(TargetOpcode::EXTRACT_SUBREG), 0,
                          1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1,  // Results = #2
/*9081*/              OPC_MorphNodeTo, TARGET_VAL(SystemZ::LNGFR), 0,
                          2/*#VTs*/, MVT::i64, MVT::i32, 1/*#Ops*/, 2, 
                      // Src: (sub:i64 0:i64, (xor:i64 (sra:i64 (sext_inreg:i64 GR64:i64:$src, i32:Other), 63:i32), (add:i64 (sext_inreg:i64 GR64:i64:$src, i32:Other), (sra:i64 (sext_inreg:i64 GR64:i64:$src, i32:Other), 63:i32)))) - Complexity = 39
                      // Dst: (LNGFR:i64:i32 (EXTRACT_SUBREG:i32 GR64:i64:$src, subreg_l32:i32))
/*9090*/            /*SwitchOpcode*/ 57,  TARGET_VAL(ISD::SRA),// ->9150
/*9093*/              OPC_MoveChild, 0,
/*9095*/              OPC_CheckOpcode, TARGET_VAL(ISD::SIGN_EXTEND_INREG),
/*9098*/              OPC_CheckChild0Same, 0,
/*9100*/              OPC_MoveChild, 1,
/*9102*/              OPC_CheckValueType, MVT::i32,
/*9104*/              OPC_MoveParent,
/*9105*/              OPC_MoveParent,
/*9106*/              OPC_MoveChild, 1,
/*9108*/              OPC_CheckInteger, 63, 
/*9110*/              OPC_CheckType, MVT::i32,
/*9112*/              OPC_MoveParent,
/*9113*/              OPC_MoveParent,
/*9114*/              OPC_MoveChild, 1,
/*9116*/              OPC_CheckOpcode, TARGET_VAL(ISD::SIGN_EXTEND_INREG),
/*9119*/              OPC_CheckChild0Same, 0,
/*9121*/              OPC_MoveChild, 1,
/*9123*/              OPC_CheckValueType, MVT::i32,
/*9125*/              OPC_MoveParent,
/*9126*/              OPC_MoveParent,
/*9127*/              OPC_MoveParent,
/*9128*/              OPC_MoveParent,
/*9129*/              OPC_EmitInteger, MVT::i32, SystemZ::subreg_l32,
/*9132*/              OPC_EmitNode, TARGET_VAL(TargetOpcode::EXTRACT_SUBREG), 0,
                          1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1,  // Results = #2
/*9141*/              OPC_MorphNodeTo, TARGET_VAL(SystemZ::LNGFR), 0,
                          2/*#VTs*/, MVT::i64, MVT::i32, 1/*#Ops*/, 2, 
                      // Src: (sub:i64 0:i64, (xor:i64 (sra:i64 (sext_inreg:i64 GR64:i64:$src, i32:Other), 63:i32), (add:i64 (sra:i64 (sext_inreg:i64 GR64:i64:$src, i32:Other), 63:i32), (sext_inreg:i64 GR64:i64:$src, i32:Other)))) - Complexity = 39
                      // Dst: (LNGFR:i64:i32 (EXTRACT_SUBREG:i32 GR64:i64:$src, subreg_l32:i32))
/*9150*/            0, // EndSwitchOpcode
/*9151*/          0, // EndSwitchOpcode
/*9152*/        /*Scope*/ 27|128,1/*155*/, /*->9309*/
/*9154*/          OPC_RecordChild0, // #0 = $R2
/*9155*/          OPC_MoveChild, 1,
/*9157*/          OPC_CheckType, MVT::i32,
/*9159*/          OPC_Scope, 73, /*->9234*/ // 2 children in Scope
/*9161*/            OPC_CheckInteger, 31, 
/*9163*/            OPC_MoveParent,
/*9164*/            OPC_MoveParent,
/*9165*/            OPC_MoveChild, 1,
/*9167*/            OPC_CheckOpcode, TARGET_VAL(ISD::ADD),
/*9170*/            OPC_Scope, 30, /*->9202*/ // 2 children in Scope
/*9172*/              OPC_CheckChild0Same, 0,
/*9174*/              OPC_MoveChild, 1,
/*9176*/              OPC_CheckOpcode, TARGET_VAL(ISD::SRA),
/*9179*/              OPC_CheckChild0Same, 0,
/*9181*/              OPC_MoveChild, 1,
/*9183*/              OPC_CheckInteger, 31, 
/*9185*/              OPC_CheckType, MVT::i32,
/*9187*/              OPC_MoveParent,
/*9188*/              OPC_MoveParent,
/*9189*/              OPC_MoveParent,
/*9190*/              OPC_MoveParent,
/*9191*/              OPC_CheckType, MVT::i32,
/*9193*/              OPC_MorphNodeTo, TARGET_VAL(SystemZ::LNR), 0,
                          2/*#VTs*/, MVT::i32, MVT::i32, 1/*#Ops*/, 0, 
                      // Src: (sub:i32 0:i32, (xor:i32 (sra:i32 GR32:i32:$R2, 31:i32), (add:i32 GR32:i32:$R2, (sra:i32 GR32:i32:$R2, 31:i32)))) - Complexity = 30
                      // Dst: (LNR:i32:i32 GR32:i32:$R2)
/*9202*/            /*Scope*/ 30, /*->9233*/
/*9203*/              OPC_MoveChild, 0,
/*9205*/              OPC_CheckOpcode, TARGET_VAL(ISD::SRA),
/*9208*/              OPC_CheckChild0Same, 0,
/*9210*/              OPC_MoveChild, 1,
/*9212*/              OPC_CheckInteger, 31, 
/*9214*/              OPC_CheckType, MVT::i32,
/*9216*/              OPC_MoveParent,
/*9217*/              OPC_MoveParent,
/*9218*/              OPC_CheckChild1Same, 0,
/*9220*/              OPC_MoveParent,
/*9221*/              OPC_MoveParent,
/*9222*/              OPC_CheckType, MVT::i32,
/*9224*/              OPC_MorphNodeTo, TARGET_VAL(SystemZ::LNR), 0,
                          2/*#VTs*/, MVT::i32, MVT::i32, 1/*#Ops*/, 0, 
                      // Src: (sub:i32 0:i32, (xor:i32 (sra:i32 GR32:i32:$R2, 31:i32), (add:i32 (sra:i32 GR32:i32:$R2, 31:i32), GR32:i32:$R2))) - Complexity = 30
                      // Dst: (LNR:i32:i32 GR32:i32:$R2)
/*9233*/            0, /*End of Scope*/
/*9234*/          /*Scope*/ 73, /*->9308*/
/*9235*/            OPC_CheckInteger, 63, 
/*9237*/            OPC_MoveParent,
/*9238*/            OPC_MoveParent,
/*9239*/            OPC_MoveChild, 1,
/*9241*/            OPC_CheckOpcode, TARGET_VAL(ISD::ADD),
/*9244*/            OPC_Scope, 30, /*->9276*/ // 2 children in Scope
/*9246*/              OPC_CheckChild0Same, 0,
/*9248*/              OPC_MoveChild, 1,
/*9250*/              OPC_CheckOpcode, TARGET_VAL(ISD::SRA),
/*9253*/              OPC_CheckChild0Same, 0,
/*9255*/              OPC_MoveChild, 1,
/*9257*/              OPC_CheckInteger, 63, 
/*9259*/              OPC_CheckType, MVT::i32,
/*9261*/              OPC_MoveParent,
/*9262*/              OPC_MoveParent,
/*9263*/              OPC_MoveParent,
/*9264*/              OPC_MoveParent,
/*9265*/              OPC_CheckType, MVT::i64,
/*9267*/              OPC_MorphNodeTo, TARGET_VAL(SystemZ::LNGR), 0,
                          2/*#VTs*/, MVT::i64, MVT::i32, 1/*#Ops*/, 0, 
                      // Src: (sub:i64 0:i64, (xor:i64 (sra:i64 GR64:i64:$R2, 63:i32), (add:i64 GR64:i64:$R2, (sra:i64 GR64:i64:$R2, 63:i32)))) - Complexity = 30
                      // Dst: (LNGR:i64:i32 GR64:i64:$R2)
/*9276*/            /*Scope*/ 30, /*->9307*/
/*9277*/              OPC_MoveChild, 0,
/*9279*/              OPC_CheckOpcode, TARGET_VAL(ISD::SRA),
/*9282*/              OPC_CheckChild0Same, 0,
/*9284*/              OPC_MoveChild, 1,
/*9286*/              OPC_CheckInteger, 63, 
/*9288*/              OPC_CheckType, MVT::i32,
/*9290*/              OPC_MoveParent,
/*9291*/              OPC_MoveParent,
/*9292*/              OPC_CheckChild1Same, 0,
/*9294*/              OPC_MoveParent,
/*9295*/              OPC_MoveParent,
/*9296*/              OPC_CheckType, MVT::i64,
/*9298*/              OPC_MorphNodeTo, TARGET_VAL(SystemZ::LNGR), 0,
                          2/*#VTs*/, MVT::i64, MVT::i32, 1/*#Ops*/, 0, 
                      // Src: (sub:i64 0:i64, (xor:i64 (sra:i64 GR64:i64:$R2, 63:i32), (add:i64 (sra:i64 GR64:i64:$R2, 63:i32), GR64:i64:$R2))) - Complexity = 30
                      // Dst: (LNGR:i64:i32 GR64:i64:$R2)
/*9307*/            0, /*End of Scope*/
/*9308*/          0, /*End of Scope*/
/*9309*/        0, /*End of Scope*/
/*9310*/      0, // EndSwitchOpcode
/*9311*/    /*Scope*/ 44|128,1/*172*/, /*->9485*/
/*9313*/      OPC_RecordChild0, // #0 = $R1src
/*9314*/      OPC_MoveChild, 1,
/*9316*/      OPC_CheckOpcode, TARGET_VAL(ISD::LOAD),
/*9319*/      OPC_RecordMemRef,
/*9320*/      OPC_RecordNode, // #1 = 'ld' chained node
/*9321*/      OPC_CheckFoldableChainNode,
/*9322*/      OPC_RecordChild1, // #2 = $XBD2
/*9323*/      OPC_CheckChild1Type, MVT::i64,
/*9325*/      OPC_CheckPredicate, 0, // Predicate_unindexedload
/*9327*/      OPC_Scope, 43, /*->9372*/ // 5 children in Scope
/*9329*/        OPC_CheckPredicate, 35, // Predicate_asextload
/*9331*/        OPC_CheckPredicate, 36, // Predicate_asextloadi16
/*9333*/        OPC_MoveParent,
/*9334*/        OPC_CheckType, MVT::i32,
/*9336*/        OPC_Scope, 16, /*->9354*/ // 2 children in Scope
/*9338*/          OPC_CheckComplexPat, /*CP*/7, /*#*/2, // selectBDXAddr12Pair:$XBD2 #3 #4 #5
/*9341*/          OPC_EmitMergeInputChains1_1,
/*9342*/          OPC_MorphNodeTo, TARGET_VAL(SystemZ::SH), 0|OPFL_Chain|OPFL_MemRefs,
                      2/*#VTs*/, MVT::i32, MVT::i32, 4/*#Ops*/, 0, 3, 4, 5, 
                  // Src: (sub:i32 GR32:i32:$R1src, (ld:i32 bdxaddr12pair:i64:$XBD2)<<P:Predicate_unindexedload>><<P:Predicate_asextload>><<P:Predicate_asextloadi16>>) - Complexity = 19
                  // Dst: (SH:i32:i32 GR32:i32:$R1src, bdxaddr12pair:i64:$XBD2)
/*9354*/        /*Scope*/ 16, /*->9371*/
/*9355*/          OPC_CheckComplexPat, /*CP*/8, /*#*/2, // selectBDXAddr20Pair:$XBD2 #3 #4 #5
/*9358*/          OPC_EmitMergeInputChains1_1,
/*9359*/          OPC_MorphNodeTo, TARGET_VAL(SystemZ::SHY), 0|OPFL_Chain|OPFL_MemRefs,
                      2/*#VTs*/, MVT::i32, MVT::i32, 4/*#Ops*/, 0, 3, 4, 5, 
                  // Src: (sub:i32 GR32:i32:$R1src, (ld:i32 bdxaddr20pair:i64:$XBD2)<<P:Predicate_unindexedload>><<P:Predicate_asextload>><<P:Predicate_asextloadi16>>) - Complexity = 19
                  // Dst: (SHY:i32:i32 GR32:i32:$R1src, bdxaddr20pair:i64:$XBD2)
/*9371*/        0, /*End of Scope*/
/*9372*/      /*Scope*/ 41, /*->9414*/
/*9373*/        OPC_CheckPredicate, 13, // Predicate_load
/*9375*/        OPC_MoveParent,
/*9376*/        OPC_CheckType, MVT::i32,
/*9378*/        OPC_Scope, 16, /*->9396*/ // 2 children in Scope
/*9380*/          OPC_CheckComplexPat, /*CP*/7, /*#*/2, // selectBDXAddr12Pair:$XBD2 #3 #4 #5
/*9383*/          OPC_EmitMergeInputChains1_1,
/*9384*/          OPC_MorphNodeTo, TARGET_VAL(SystemZ::S), 0|OPFL_Chain|OPFL_MemRefs,
                      2/*#VTs*/, MVT::i32, MVT::i32, 4/*#Ops*/, 0, 3, 4, 5, 
                  // Src: (sub:i32 GR32:i32:$R1src, (ld:i32 bdxaddr12pair:i64:$XBD2)<<P:Predicate_unindexedload>><<P:Predicate_load>>) - Complexity = 19
                  // Dst: (S:i32:i32 GR32:i32:$R1src, bdxaddr12pair:i64:$XBD2)
/*9396*/        /*Scope*/ 16, /*->9413*/
/*9397*/          OPC_CheckComplexPat, /*CP*/8, /*#*/2, // selectBDXAddr20Pair:$XBD2 #3 #4 #5
/*9400*/          OPC_EmitMergeInputChains1_1,
/*9401*/          OPC_MorphNodeTo, TARGET_VAL(SystemZ::SY), 0|OPFL_Chain|OPFL_MemRefs,
                      2/*#VTs*/, MVT::i32, MVT::i32, 4/*#Ops*/, 0, 3, 4, 5, 
                  // Src: (sub:i32 GR32:i32:$R1src, (ld:i32 bdxaddr20pair:i64:$XBD2)<<P:Predicate_unindexedload>><<P:Predicate_load>>) - Complexity = 19
                  // Dst: (SY:i32:i32 GR32:i32:$R1src, bdxaddr20pair:i64:$XBD2)
/*9413*/        0, /*End of Scope*/
/*9414*/      /*Scope*/ 23, /*->9438*/
/*9415*/        OPC_CheckPredicate, 35, // Predicate_asextload
/*9417*/        OPC_CheckPredicate, 37, // Predicate_asextloadi32
/*9419*/        OPC_MoveParent,
/*9420*/        OPC_CheckType, MVT::i64,
/*9422*/        OPC_CheckComplexPat, /*CP*/0, /*#*/2, // selectBDXAddr20Only:$XBD2 #3 #4 #5
/*9425*/        OPC_EmitMergeInputChains1_1,
/*9426*/        OPC_MorphNodeTo, TARGET_VAL(SystemZ::SGF), 0|OPFL_Chain|OPFL_MemRefs,
                    2/*#VTs*/, MVT::i64, MVT::i32, 4/*#Ops*/, 0, 3, 4, 5, 
                // Src: (sub:i64 GR64:i64:$R1src, (ld:i64 bdxaddr20only:i64:$XBD2)<<P:Predicate_unindexedload>><<P:Predicate_asextload>><<P:Predicate_asextloadi32>>) - Complexity = 19
                // Dst: (SGF:i64:i32 GR64:i64:$R1src, bdxaddr20only:i64:$XBD2)
/*9438*/      /*Scope*/ 21, /*->9460*/
/*9439*/        OPC_CheckPredicate, 13, // Predicate_load
/*9441*/        OPC_MoveParent,
/*9442*/        OPC_CheckType, MVT::i64,
/*9444*/        OPC_CheckComplexPat, /*CP*/0, /*#*/2, // selectBDXAddr20Only:$XBD2 #3 #4 #5
/*9447*/        OPC_EmitMergeInputChains1_1,
/*9448*/        OPC_MorphNodeTo, TARGET_VAL(SystemZ::SG), 0|OPFL_Chain|OPFL_MemRefs,
                    2/*#VTs*/, MVT::i64, MVT::i32, 4/*#Ops*/, 0, 3, 4, 5, 
                // Src: (sub:i64 GR64:i64:$R1src, (ld:i64 bdxaddr20only:i64:$XBD2)<<P:Predicate_unindexedload>><<P:Predicate_load>>) - Complexity = 19
                // Dst: (SG:i64:i32 GR64:i64:$R1src, bdxaddr20only:i64:$XBD2)
/*9460*/      /*Scope*/ 23, /*->9484*/
/*9461*/        OPC_CheckPredicate, 38, // Predicate_azextload
/*9463*/        OPC_CheckPredicate, 39, // Predicate_azextloadi32
/*9465*/        OPC_MoveParent,
/*9466*/        OPC_CheckType, MVT::i64,
/*9468*/        OPC_CheckComplexPat, /*CP*/0, /*#*/2, // selectBDXAddr20Only:$addr #3 #4 #5
/*9471*/        OPC_EmitMergeInputChains1_1,
/*9472*/        OPC_MorphNodeTo, TARGET_VAL(SystemZ::SLGF), 0|OPFL_Chain|OPFL_MemRefs,
                    2/*#VTs*/, MVT::i64, MVT::i32, 4/*#Ops*/, 0, 3, 4, 5, 
                // Src: (sub:i64 GR64:i64:$src1, (ld:i64 bdxaddr20only:i64:$addr)<<P:Predicate_unindexedload>><<P:Predicate_azextload>><<P:Predicate_azextloadi32>>) - Complexity = 19
                // Dst: (SLGF:i64:i32 GR64:i64:$src1, bdxaddr20only:i64:$addr)
/*9484*/      0, /*End of Scope*/
/*9485*/    /*Scope*/ 47, /*->9533*/
/*9486*/      OPC_RecordNode, // #0 = $src
/*9487*/      OPC_CheckType, MVT::i64,
/*9489*/      OPC_Scope, 13, /*->9504*/ // 3 children in Scope
/*9491*/        OPC_CheckComplexPat, /*CP*/13, /*#*/0, // selectDynAlloc12Only:$src #1 #2 #3
/*9494*/        OPC_MorphNodeTo, TARGET_VAL(SystemZ::ADJDYNALLOC), 0,
                    1/*#VTs*/, MVT::i64, 3/*#Ops*/, 1, 2, 3, 
                // Src: dynalloc12only:i64:$src - Complexity = 12
                // Dst: (ADJDYNALLOC:i64 dynalloc12only:i64:$src)
/*9504*/      /*Scope*/ 13, /*->9518*/
/*9505*/        OPC_CheckComplexPat, /*CP*/14, /*#*/0, // selectLAAddr12Pair:$XBD2 #1 #2 #3
/*9508*/        OPC_MorphNodeTo, TARGET_VAL(SystemZ::LA), 0,
                    1/*#VTs*/, MVT::i64, 3/*#Ops*/, 1, 2, 3, 
                // Src: laaddr12pair:i64:$XBD2 - Complexity = 12
                // Dst: (LA:i64 laaddr12pair:i64:$XBD2)
/*9518*/      /*Scope*/ 13, /*->9532*/
/*9519*/        OPC_CheckComplexPat, /*CP*/15, /*#*/0, // selectLAAddr20Pair:$XBD2 #1 #2 #3
/*9522*/        OPC_MorphNodeTo, TARGET_VAL(SystemZ::LAY), 0,
                    1/*#VTs*/, MVT::i64, 3/*#Ops*/, 1, 2, 3, 
                // Src: laaddr20pair:i64:$XBD2 - Complexity = 12
                // Dst: (LAY:i64 laaddr20pair:i64:$XBD2)
/*9532*/      0, /*End of Scope*/
/*9533*/    /*Scope*/ 54, /*->9588*/
/*9534*/      OPC_MoveChild, 0,
/*9536*/      OPC_CheckInteger, 0, 
/*9538*/      OPC_MoveParent,
/*9539*/      OPC_MoveChild, 1,
/*9541*/      OPC_SwitchOpcode /*2 cases */, 11,  TARGET_VAL(ISD::SIGN_EXTEND),// ->9556
/*9545*/        OPC_RecordChild0, // #0 = $src
/*9546*/        OPC_MoveParent,
/*9547*/        OPC_MorphNodeTo, TARGET_VAL(SystemZ::LCGFR), 0,
                    2/*#VTs*/, MVT::i64, MVT::i32, 1/*#Ops*/, 0, 
                // Src: (sub:i64 0:i64, (sext:i64 GR32:i32:$src)) - Complexity = 11
                // Dst: (LCGFR:i64:i32 GR32:i32:$src)
/*9556*/      /*SwitchOpcode*/ 28,  TARGET_VAL(ISD::SIGN_EXTEND_INREG),// ->9587
/*9559*/        OPC_RecordChild0, // #0 = $src
/*9560*/        OPC_MoveChild, 1,
/*9562*/        OPC_CheckValueType, MVT::i32,
/*9564*/        OPC_MoveParent,
/*9565*/        OPC_MoveParent,
/*9566*/        OPC_EmitInteger, MVT::i32, SystemZ::subreg_l32,
/*9569*/        OPC_EmitNode, TARGET_VAL(TargetOpcode::EXTRACT_SUBREG), 0,
                    1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1,  // Results = #2
/*9578*/        OPC_MorphNodeTo, TARGET_VAL(SystemZ::LCGFR), 0,
                    2/*#VTs*/, MVT::i64, MVT::i32, 1/*#Ops*/, 2, 
                // Src: (sub:i64 0:i64, (sext_inreg:i64 GR64:i64:$src, i32:Other)) - Complexity = 11
                // Dst: (LCGFR:i64:i32 (EXTRACT_SUBREG:i32 GR64:i64:$src, subreg_l32:i32))
/*9587*/      0, // EndSwitchOpcode
/*9588*/    /*Scope*/ 35, /*->9624*/
/*9589*/      OPC_RecordChild0, // #0 = $src1
/*9590*/      OPC_MoveChild, 1,
/*9592*/      OPC_CheckAndImm, 127|128,127|128,127|128,127|128,15/*4294967295*/, 
/*9598*/      OPC_RecordChild0, // #1 = $src2
/*9599*/      OPC_MoveParent,
/*9600*/      OPC_CheckType, MVT::i64,
/*9602*/      OPC_EmitInteger, MVT::i32, SystemZ::subreg_l32,
/*9605*/      OPC_EmitNode, TARGET_VAL(TargetOpcode::EXTRACT_SUBREG), 0,
                  1/*#VTs*/, MVT::i32, 2/*#Ops*/, 1, 2,  // Results = #3
/*9614*/      OPC_MorphNodeTo, TARGET_VAL(SystemZ::SLGFR), 0,
                  2/*#VTs*/, MVT::i64, MVT::i32, 2/*#Ops*/, 0, 3, 
              // Src: (sub:i64 GR64:i64:$src1, (and:i64 GR64:i64:$src2, 4294967295:i64)) - Complexity = 11
              // Dst: (SLGFR:i64:i32 GR64:i64:$src1, (EXTRACT_SUBREG:i32 GR64:i64:$src2, subreg_l32:i32))
/*9624*/    /*Scope*/ 30, /*->9655*/
/*9625*/      OPC_MoveChild, 0,
/*9627*/      OPC_CheckInteger, 0, 
/*9629*/      OPC_MoveParent,
/*9630*/      OPC_RecordChild1, // #0 = $R2
/*9631*/      OPC_SwitchType /*2 cases */, 9,  MVT::i32,// ->9643
/*9634*/        OPC_MorphNodeTo, TARGET_VAL(SystemZ::LCR), 0,
                    2/*#VTs*/, MVT::i32, MVT::i32, 1/*#Ops*/, 0, 
                // Src: (sub:i32 0:i32, GR32:i32:$R2) - Complexity = 8
                // Dst: (LCR:i32:i32 GR32:i32:$R2)
/*9643*/      /*SwitchType*/ 9,  MVT::i64,// ->9654
/*9645*/        OPC_MorphNodeTo, TARGET_VAL(SystemZ::LCGR), 0,
                    2/*#VTs*/, MVT::i64, MVT::i32, 1/*#Ops*/, 0, 
                // Src: (sub:i64 0:i64, GR64:i64:$R2) - Complexity = 8
                // Dst: (LCGR:i64:i32 GR64:i64:$R2)
/*9654*/      0, // EndSwitchType
/*9655*/    /*Scope*/ 98, /*->9754*/
/*9656*/      OPC_RecordChild0, // #0 = $src1
/*9657*/      OPC_Scope, 66, /*->9725*/ // 2 children in Scope
/*9659*/        OPC_MoveChild, 1,
/*9661*/        OPC_SwitchOpcode /*3 cases */, 12,  TARGET_VAL(ISD::SIGN_EXTEND),// ->9677
/*9665*/          OPC_RecordChild0, // #1 = $src2
/*9666*/          OPC_MoveParent,
/*9667*/          OPC_MorphNodeTo, TARGET_VAL(SystemZ::SGFR), 0,
                      2/*#VTs*/, MVT::i64, MVT::i32, 2/*#Ops*/, 0, 1, 
                  // Src: (sub:i64 GR64:i64:$src1, (sext:i64 GR32:i32:$src2)) - Complexity = 6
                  // Dst: (SGFR:i64:i32 GR64:i64:$src1, GR32:i32:$src2)
/*9677*/        /*SwitchOpcode*/ 12,  TARGET_VAL(ISD::ZERO_EXTEND),// ->9692
/*9680*/          OPC_RecordChild0, // #1 = $src2
/*9681*/          OPC_MoveParent,
/*9682*/          OPC_MorphNodeTo, TARGET_VAL(SystemZ::SLGFR), 0,
                      2/*#VTs*/, MVT::i64, MVT::i32, 2/*#Ops*/, 0, 1, 
                  // Src: (sub:i64 GR64:i64:$src1, (zext:i64 GR32:i32:$src2)) - Complexity = 6
                  // Dst: (SLGFR:i64:i32 GR64:i64:$src1, GR32:i32:$src2)
/*9692*/        /*SwitchOpcode*/ 29,  TARGET_VAL(ISD::SIGN_EXTEND_INREG),// ->9724
/*9695*/          OPC_RecordChild0, // #1 = $src2
/*9696*/          OPC_MoveChild, 1,
/*9698*/          OPC_CheckValueType, MVT::i32,
/*9700*/          OPC_MoveParent,
/*9701*/          OPC_MoveParent,
/*9702*/          OPC_EmitInteger, MVT::i32, SystemZ::subreg_l32,
/*9705*/          OPC_EmitNode, TARGET_VAL(TargetOpcode::EXTRACT_SUBREG), 0,
                      1/*#VTs*/, MVT::i32, 2/*#Ops*/, 1, 2,  // Results = #3
/*9714*/          OPC_MorphNodeTo, TARGET_VAL(SystemZ::SGFR), 0,
                      2/*#VTs*/, MVT::i64, MVT::i32, 2/*#Ops*/, 0, 3, 
                  // Src: (sub:i64 GR64:i64:$src1, (sext_inreg:i64 GR64:i64:$src2, i32:Other)) - Complexity = 6
                  // Dst: (SGFR:i64:i32 GR64:i64:$src1, (EXTRACT_SUBREG:i32 GR64:i64:$src2, subreg_l32:i32))
/*9724*/        0, // EndSwitchOpcode
/*9725*/      /*Scope*/ 27, /*->9753*/
/*9726*/        OPC_RecordChild1, // #1 = $R2
/*9727*/        OPC_SwitchType /*2 cases */, 10,  MVT::i32,// ->9740
/*9730*/          OPC_MorphNodeTo, TARGET_VAL(SystemZ::SR), 0,
                      2/*#VTs*/, MVT::i32, MVT::i32, 2/*#Ops*/, 0, 1, 
                  // Src: (sub:i32 GR32:i32:$R1src, GR32:i32:$R2) - Complexity = 3
                  // Dst: (SR:i32:i32 GR32:i32:$R1src, GR32:i32:$R2)
/*9740*/        /*SwitchType*/ 10,  MVT::i64,// ->9752
/*9742*/          OPC_MorphNodeTo, TARGET_VAL(SystemZ::SGR), 0,
                      2/*#VTs*/, MVT::i64, MVT::i32, 2/*#Ops*/, 0, 1, 
                  // Src: (sub:i64 GR64:i64:$R1src, GR64:i64:$R2) - Complexity = 3
                  // Dst: (SGR:i64:i32 GR64:i64:$R1src, GR64:i64:$R2)
/*9752*/        0, // EndSwitchType
/*9753*/      0, /*End of Scope*/
/*9754*/    0, /*End of Scope*/
/*9755*/  /*SwitchOpcode*/ 3|128,9/*1155*/,  TARGET_VAL(ISD::XOR),// ->10914
/*9759*/    OPC_Scope, 95|128,6/*863*/, /*->10625*/ // 4 children in Scope
/*9762*/      OPC_MoveChild, 0,
/*9764*/      OPC_SwitchOpcode /*2 cases */, 64|128,3/*448*/,  TARGET_VAL(ISD::ADD),// ->10217
/*9769*/        OPC_Scope, 28|128,2/*284*/, /*->10056*/ // 3 children in Scope
/*9772*/          OPC_MoveChild, 0,
/*9774*/          OPC_SwitchOpcode /*3 cases */, 54,  TARGET_VAL(ISD::SIGN_EXTEND),// ->9832
/*9778*/            OPC_RecordChild0, // #0 = $src
/*9779*/            OPC_MoveParent,
/*9780*/            OPC_MoveChild, 1,
/*9782*/            OPC_CheckOpcode, TARGET_VAL(ISD::SRA),
/*9785*/            OPC_MoveChild, 0,
/*9787*/            OPC_CheckOpcode, TARGET_VAL(ISD::SIGN_EXTEND),
/*9790*/            OPC_CheckChild0Same, 0,
/*9792*/            OPC_MoveParent,
/*9793*/            OPC_MoveChild, 1,
/*9795*/            OPC_CheckInteger, 63, 
/*9797*/            OPC_CheckType, MVT::i32,
/*9799*/            OPC_MoveParent,
/*9800*/            OPC_MoveParent,
/*9801*/            OPC_MoveParent,
/*9802*/            OPC_MoveChild, 1,
/*9804*/            OPC_CheckOpcode, TARGET_VAL(ISD::SRA),
/*9807*/            OPC_MoveChild, 0,
/*9809*/            OPC_CheckOpcode, TARGET_VAL(ISD::SIGN_EXTEND),
/*9812*/            OPC_CheckChild0Same, 0,
/*9814*/            OPC_MoveParent,
/*9815*/            OPC_MoveChild, 1,
/*9817*/            OPC_CheckInteger, 63, 
/*9819*/            OPC_CheckType, MVT::i32,
/*9821*/            OPC_MoveParent,
/*9822*/            OPC_MoveParent,
/*9823*/            OPC_MorphNodeTo, TARGET_VAL(SystemZ::LPGFR), 0,
                        2/*#VTs*/, MVT::i64, MVT::i32, 1/*#Ops*/, 0, 
                    // Src: (xor:i64 (add:i64 (sext:i64 GR32:i32:$src), (sra:i64 (sext:i64 GR32:i32:$src), 63:i32)), (sra:i64 (sext:i64 GR32:i32:$src), 63:i32)) - Complexity = 31
                    // Dst: (LPGFR:i64:i32 GR32:i32:$src)
/*9832*/          /*SwitchOpcode*/ 7|128,1/*135*/,  TARGET_VAL(ISD::SRA),// ->9971
/*9836*/            OPC_MoveChild, 0,
/*9838*/            OPC_SwitchOpcode /*2 cases */, 49,  TARGET_VAL(ISD::SIGN_EXTEND),// ->9891
/*9842*/              OPC_RecordChild0, // #0 = $src
/*9843*/              OPC_MoveParent,
/*9844*/              OPC_MoveChild, 1,
/*9846*/              OPC_CheckInteger, 63, 
/*9848*/              OPC_CheckType, MVT::i32,
/*9850*/              OPC_MoveParent,
/*9851*/              OPC_MoveParent,
/*9852*/              OPC_MoveChild, 1,
/*9854*/              OPC_CheckOpcode, TARGET_VAL(ISD::SIGN_EXTEND),
/*9857*/              OPC_CheckChild0Same, 0,
/*9859*/              OPC_MoveParent,
/*9860*/              OPC_MoveParent,
/*9861*/              OPC_MoveChild, 1,
/*9863*/              OPC_CheckOpcode, TARGET_VAL(ISD::SRA),
/*9866*/              OPC_MoveChild, 0,
/*9868*/              OPC_CheckOpcode, TARGET_VAL(ISD::SIGN_EXTEND),
/*9871*/              OPC_CheckChild0Same, 0,
/*9873*/              OPC_MoveParent,
/*9874*/              OPC_MoveChild, 1,
/*9876*/              OPC_CheckInteger, 63, 
/*9878*/              OPC_CheckType, MVT::i32,
/*9880*/              OPC_MoveParent,
/*9881*/              OPC_MoveParent,
/*9882*/              OPC_MorphNodeTo, TARGET_VAL(SystemZ::LPGFR), 0,
                          2/*#VTs*/, MVT::i64, MVT::i32, 1/*#Ops*/, 0, 
                      // Src: (xor:i64 (add:i64 (sra:i64 (sext:i64 GR32:i32:$src), 63:i32), (sext:i64 GR32:i32:$src)), (sra:i64 (sext:i64 GR32:i32:$src), 63:i32)) - Complexity = 31
                      // Dst: (LPGFR:i64:i32 GR32:i32:$src)
/*9891*/            /*SwitchOpcode*/ 76,  TARGET_VAL(ISD::SIGN_EXTEND_INREG),// ->9970
/*9894*/              OPC_RecordChild0, // #0 = $src
/*9895*/              OPC_MoveChild, 1,
/*9897*/              OPC_CheckValueType, MVT::i32,
/*9899*/              OPC_MoveParent,
/*9900*/              OPC_MoveParent,
/*9901*/              OPC_MoveChild, 1,
/*9903*/              OPC_CheckInteger, 63, 
/*9905*/              OPC_CheckType, MVT::i32,
/*9907*/              OPC_MoveParent,
/*9908*/              OPC_MoveParent,
/*9909*/              OPC_MoveChild, 1,
/*9911*/              OPC_CheckOpcode, TARGET_VAL(ISD::SIGN_EXTEND_INREG),
/*9914*/              OPC_CheckChild0Same, 0,
/*9916*/              OPC_MoveChild, 1,
/*9918*/              OPC_CheckValueType, MVT::i32,
/*9920*/              OPC_MoveParent,
/*9921*/              OPC_MoveParent,
/*9922*/              OPC_MoveParent,
/*9923*/              OPC_MoveChild, 1,
/*9925*/              OPC_CheckOpcode, TARGET_VAL(ISD::SRA),
/*9928*/              OPC_MoveChild, 0,
/*9930*/              OPC_CheckOpcode, TARGET_VAL(ISD::SIGN_EXTEND_INREG),
/*9933*/              OPC_CheckChild0Same, 0,
/*9935*/              OPC_MoveChild, 1,
/*9937*/              OPC_CheckValueType, MVT::i32,
/*9939*/              OPC_MoveParent,
/*9940*/              OPC_MoveParent,
/*9941*/              OPC_MoveChild, 1,
/*9943*/              OPC_CheckInteger, 63, 
/*9945*/              OPC_CheckType, MVT::i32,
/*9947*/              OPC_MoveParent,
/*9948*/              OPC_MoveParent,
/*9949*/              OPC_EmitInteger, MVT::i32, SystemZ::subreg_l32,
/*9952*/              OPC_EmitNode, TARGET_VAL(TargetOpcode::EXTRACT_SUBREG), 0,
                          1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1,  // Results = #2
/*9961*/              OPC_MorphNodeTo, TARGET_VAL(SystemZ::LPGFR), 0,
                          2/*#VTs*/, MVT::i64, MVT::i32, 1/*#Ops*/, 2, 
                      // Src: (xor:i64 (add:i64 (sra:i64 (sext_inreg:i64 GR64:i64:$src, i32:Other), 63:i32), (sext_inreg:i64 GR64:i64:$src, i32:Other)), (sra:i64 (sext_inreg:i64 GR64:i64:$src, i32:Other), 63:i32)) - Complexity = 31
                      // Dst: (LPGFR:i64:i32 (EXTRACT_SUBREG:i32 GR64:i64:$src, subreg_l32:i32))
/*9970*/            0, // EndSwitchOpcode
/*9971*/          /*SwitchOpcode*/ 81,  TARGET_VAL(ISD::SIGN_EXTEND_INREG),// ->10055
/*9974*/            OPC_RecordChild0, // #0 = $src
/*9975*/            OPC_MoveChild, 1,
/*9977*/            OPC_CheckValueType, MVT::i32,
/*9979*/            OPC_MoveParent,
/*9980*/            OPC_MoveParent,
/*9981*/            OPC_MoveChild, 1,
/*9983*/            OPC_CheckOpcode, TARGET_VAL(ISD::SRA),
/*9986*/            OPC_MoveChild, 0,
/*9988*/            OPC_CheckOpcode, TARGET_VAL(ISD::SIGN_EXTEND_INREG),
/*9991*/            OPC_CheckChild0Same, 0,
/*9993*/            OPC_MoveChild, 1,
/*9995*/            OPC_CheckValueType, MVT::i32,
/*9997*/            OPC_MoveParent,
/*9998*/            OPC_MoveParent,
/*9999*/            OPC_MoveChild, 1,
/*10001*/           OPC_CheckInteger, 63, 
/*10003*/           OPC_CheckType, MVT::i32,
/*10005*/           OPC_MoveParent,
/*10006*/           OPC_MoveParent,
/*10007*/           OPC_MoveParent,
/*10008*/           OPC_MoveChild, 1,
/*10010*/           OPC_CheckOpcode, TARGET_VAL(ISD::SRA),
/*10013*/           OPC_MoveChild, 0,
/*10015*/           OPC_CheckOpcode, TARGET_VAL(ISD::SIGN_EXTEND_INREG),
/*10018*/           OPC_CheckChild0Same, 0,
/*10020*/           OPC_MoveChild, 1,
/*10022*/           OPC_CheckValueType, MVT::i32,
/*10024*/           OPC_MoveParent,
/*10025*/           OPC_MoveParent,
/*10026*/           OPC_MoveChild, 1,
/*10028*/           OPC_CheckInteger, 63, 
/*10030*/           OPC_CheckType, MVT::i32,
/*10032*/           OPC_MoveParent,
/*10033*/           OPC_MoveParent,
/*10034*/           OPC_EmitInteger, MVT::i32, SystemZ::subreg_l32,
/*10037*/           OPC_EmitNode, TARGET_VAL(TargetOpcode::EXTRACT_SUBREG), 0,
                        1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1,  // Results = #2
/*10046*/           OPC_MorphNodeTo, TARGET_VAL(SystemZ::LPGFR), 0,
                        2/*#VTs*/, MVT::i64, MVT::i32, 1/*#Ops*/, 2, 
                    // Src: (xor:i64 (add:i64 (sext_inreg:i64 GR64:i64:$src, i32:Other), (sra:i64 (sext_inreg:i64 GR64:i64:$src, i32:Other), 63:i32)), (sra:i64 (sext_inreg:i64 GR64:i64:$src, i32:Other), 63:i32)) - Complexity = 31
                    // Dst: (LPGFR:i64:i32 (EXTRACT_SUBREG:i32 GR64:i64:$src, subreg_l32:i32))
/*10055*/         0, // EndSwitchOpcode
/*10056*/       /*Scope*/ 78, /*->10135*/
/*10057*/         OPC_RecordChild0, // #0 = $R2
/*10058*/         OPC_MoveChild, 1,
/*10060*/         OPC_CheckOpcode, TARGET_VAL(ISD::SRA),
/*10063*/         OPC_CheckChild0Same, 0,
/*10065*/         OPC_MoveChild, 1,
/*10067*/         OPC_CheckType, MVT::i32,
/*10069*/         OPC_Scope, 31, /*->10102*/ // 2 children in Scope
/*10071*/           OPC_CheckInteger, 31, 
/*10073*/           OPC_MoveParent,
/*10074*/           OPC_MoveParent,
/*10075*/           OPC_MoveParent,
/*10076*/           OPC_MoveChild, 1,
/*10078*/           OPC_CheckOpcode, TARGET_VAL(ISD::SRA),
/*10081*/           OPC_CheckChild0Same, 0,
/*10083*/           OPC_MoveChild, 1,
/*10085*/           OPC_CheckInteger, 31, 
/*10087*/           OPC_CheckType, MVT::i32,
/*10089*/           OPC_MoveParent,
/*10090*/           OPC_MoveParent,
/*10091*/           OPC_CheckType, MVT::i32,
/*10093*/           OPC_MorphNodeTo, TARGET_VAL(SystemZ::LPR), 0,
                        2/*#VTs*/, MVT::i32, MVT::i32, 1/*#Ops*/, 0, 
                    // Src: (xor:i32 (add:i32 GR32:i32:$R2, (sra:i32 GR32:i32:$R2, 31:i32)), (sra:i32 GR32:i32:$R2, 31:i32)) - Complexity = 22
                    // Dst: (LPR:i32:i32 GR32:i32:$R2)
/*10102*/         /*Scope*/ 31, /*->10134*/
/*10103*/           OPC_CheckInteger, 63, 
/*10105*/           OPC_MoveParent,
/*10106*/           OPC_MoveParent,
/*10107*/           OPC_MoveParent,
/*10108*/           OPC_MoveChild, 1,
/*10110*/           OPC_CheckOpcode, TARGET_VAL(ISD::SRA),
/*10113*/           OPC_CheckChild0Same, 0,
/*10115*/           OPC_MoveChild, 1,
/*10117*/           OPC_CheckInteger, 63, 
/*10119*/           OPC_CheckType, MVT::i32,
/*10121*/           OPC_MoveParent,
/*10122*/           OPC_MoveParent,
/*10123*/           OPC_CheckType, MVT::i64,
/*10125*/           OPC_MorphNodeTo, TARGET_VAL(SystemZ::LPGR), 0,
                        2/*#VTs*/, MVT::i64, MVT::i32, 1/*#Ops*/, 0, 
                    // Src: (xor:i64 (add:i64 GR64:i64:$R2, (sra:i64 GR64:i64:$R2, 63:i32)), (sra:i64 GR64:i64:$R2, 63:i32)) - Complexity = 22
                    // Dst: (LPGR:i64:i32 GR64:i64:$R2)
/*10134*/         0, /*End of Scope*/
/*10135*/       /*Scope*/ 80, /*->10216*/
/*10136*/         OPC_MoveChild, 0,
/*10138*/         OPC_CheckOpcode, TARGET_VAL(ISD::SRA),
/*10141*/         OPC_RecordChild0, // #0 = $R2
/*10142*/         OPC_MoveChild, 1,
/*10144*/         OPC_CheckType, MVT::i32,
/*10146*/         OPC_Scope, 33, /*->10181*/ // 2 children in Scope
/*10148*/           OPC_CheckInteger, 31, 
/*10150*/           OPC_MoveParent,
/*10151*/           OPC_MoveParent,
/*10152*/           OPC_CheckChild1Same, 0,
/*10154*/           OPC_MoveParent,
/*10155*/           OPC_MoveChild, 1,
/*10157*/           OPC_CheckOpcode, TARGET_VAL(ISD::SRA),
/*10160*/           OPC_CheckChild0Same, 0,
/*10162*/           OPC_MoveChild, 1,
/*10164*/           OPC_CheckInteger, 31, 
/*10166*/           OPC_CheckType, MVT::i32,
/*10168*/           OPC_MoveParent,
/*10169*/           OPC_MoveParent,
/*10170*/           OPC_CheckType, MVT::i32,
/*10172*/           OPC_MorphNodeTo, TARGET_VAL(SystemZ::LPR), 0,
                        2/*#VTs*/, MVT::i32, MVT::i32, 1/*#Ops*/, 0, 
                    // Src: (xor:i32 (add:i32 (sra:i32 GR32:i32:$R2, 31:i32), GR32:i32:$R2), (sra:i32 GR32:i32:$R2, 31:i32)) - Complexity = 22
                    // Dst: (LPR:i32:i32 GR32:i32:$R2)
/*10181*/         /*Scope*/ 33, /*->10215*/
/*10182*/           OPC_CheckInteger, 63, 
/*10184*/           OPC_MoveParent,
/*10185*/           OPC_MoveParent,
/*10186*/           OPC_CheckChild1Same, 0,
/*10188*/           OPC_MoveParent,
/*10189*/           OPC_MoveChild, 1,
/*10191*/           OPC_CheckOpcode, TARGET_VAL(ISD::SRA),
/*10194*/           OPC_CheckChild0Same, 0,
/*10196*/           OPC_MoveChild, 1,
/*10198*/           OPC_CheckInteger, 63, 
/*10200*/           OPC_CheckType, MVT::i32,
/*10202*/           OPC_MoveParent,
/*10203*/           OPC_MoveParent,
/*10204*/           OPC_CheckType, MVT::i64,
/*10206*/           OPC_MorphNodeTo, TARGET_VAL(SystemZ::LPGR), 0,
                        2/*#VTs*/, MVT::i64, MVT::i32, 1/*#Ops*/, 0, 
                    // Src: (xor:i64 (add:i64 (sra:i64 GR64:i64:$R2, 63:i32), GR64:i64:$R2), (sra:i64 GR64:i64:$R2, 63:i32)) - Complexity = 22
                    // Dst: (LPGR:i64:i32 GR64:i64:$R2)
/*10215*/         0, /*End of Scope*/
/*10216*/       0, /*End of Scope*/
/*10217*/     /*SwitchOpcode*/ 19|128,3/*403*/,  TARGET_VAL(ISD::SRA),// ->10624
/*10221*/       OPC_Scope, 118|128,1/*246*/, /*->10470*/ // 2 children in Scope
/*10224*/         OPC_MoveChild, 0,
/*10226*/         OPC_SwitchOpcode /*2 cases */, 93,  TARGET_VAL(ISD::SIGN_EXTEND),// ->10323
/*10230*/           OPC_RecordChild0, // #0 = $src
/*10231*/           OPC_MoveParent,
/*10232*/           OPC_MoveChild, 1,
/*10234*/           OPC_CheckInteger, 63, 
/*10236*/           OPC_CheckType, MVT::i32,
/*10238*/           OPC_MoveParent,
/*10239*/           OPC_MoveParent,
/*10240*/           OPC_MoveChild, 1,
/*10242*/           OPC_CheckOpcode, TARGET_VAL(ISD::ADD),
/*10245*/           OPC_MoveChild, 0,
/*10247*/           OPC_SwitchOpcode /*2 cases */, 34,  TARGET_VAL(ISD::SIGN_EXTEND),// ->10285
/*10251*/             OPC_CheckChild0Same, 0,
/*10253*/             OPC_MoveParent,
/*10254*/             OPC_MoveChild, 1,
/*10256*/             OPC_CheckOpcode, TARGET_VAL(ISD::SRA),
/*10259*/             OPC_MoveChild, 0,
/*10261*/             OPC_CheckOpcode, TARGET_VAL(ISD::SIGN_EXTEND),
/*10264*/             OPC_CheckChild0Same, 0,
/*10266*/             OPC_MoveParent,
/*10267*/             OPC_MoveChild, 1,
/*10269*/             OPC_CheckInteger, 63, 
/*10271*/             OPC_CheckType, MVT::i32,
/*10273*/             OPC_MoveParent,
/*10274*/             OPC_MoveParent,
/*10275*/             OPC_MoveParent,
/*10276*/             OPC_MorphNodeTo, TARGET_VAL(SystemZ::LPGFR), 0,
                          2/*#VTs*/, MVT::i64, MVT::i32, 1/*#Ops*/, 0, 
                      // Src: (xor:i64 (sra:i64 (sext:i64 GR32:i32:$src), 63:i32), (add:i64 (sext:i64 GR32:i32:$src), (sra:i64 (sext:i64 GR32:i32:$src), 63:i32))) - Complexity = 31
                      // Dst: (LPGFR:i64:i32 GR32:i32:$src)
/*10285*/           /*SwitchOpcode*/ 34,  TARGET_VAL(ISD::SRA),// ->10322
/*10288*/             OPC_MoveChild, 0,
/*10290*/             OPC_CheckOpcode, TARGET_VAL(ISD::SIGN_EXTEND),
/*10293*/             OPC_CheckChild0Same, 0,
/*10295*/             OPC_MoveParent,
/*10296*/             OPC_MoveChild, 1,
/*10298*/             OPC_CheckInteger, 63, 
/*10300*/             OPC_CheckType, MVT::i32,
/*10302*/             OPC_MoveParent,
/*10303*/             OPC_MoveParent,
/*10304*/             OPC_MoveChild, 1,
/*10306*/             OPC_CheckOpcode, TARGET_VAL(ISD::SIGN_EXTEND),
/*10309*/             OPC_CheckChild0Same, 0,
/*10311*/             OPC_MoveParent,
/*10312*/             OPC_MoveParent,
/*10313*/             OPC_MorphNodeTo, TARGET_VAL(SystemZ::LPGFR), 0,
                          2/*#VTs*/, MVT::i64, MVT::i32, 1/*#Ops*/, 0, 
                      // Src: (xor:i64 (sra:i64 (sext:i64 GR32:i32:$src), 63:i32), (add:i64 (sra:i64 (sext:i64 GR32:i32:$src), 63:i32), (sext:i64 GR32:i32:$src))) - Complexity = 31
                      // Dst: (LPGFR:i64:i32 GR32:i32:$src)
/*10322*/           0, // EndSwitchOpcode
/*10323*/         /*SwitchOpcode*/ 14|128,1/*142*/,  TARGET_VAL(ISD::SIGN_EXTEND_INREG),// ->10469
/*10327*/           OPC_RecordChild0, // #0 = $src
/*10328*/           OPC_MoveChild, 1,
/*10330*/           OPC_CheckValueType, MVT::i32,
/*10332*/           OPC_MoveParent,
/*10333*/           OPC_MoveParent,
/*10334*/           OPC_MoveChild, 1,
/*10336*/           OPC_CheckInteger, 63, 
/*10338*/           OPC_CheckType, MVT::i32,
/*10340*/           OPC_MoveParent,
/*10341*/           OPC_MoveParent,
/*10342*/           OPC_MoveChild, 1,
/*10344*/           OPC_CheckOpcode, TARGET_VAL(ISD::ADD),
/*10347*/           OPC_MoveChild, 0,
/*10349*/           OPC_SwitchOpcode /*2 cases */, 56,  TARGET_VAL(ISD::SIGN_EXTEND_INREG),// ->10409
/*10353*/             OPC_CheckChild0Same, 0,
/*10355*/             OPC_MoveChild, 1,
/*10357*/             OPC_CheckValueType, MVT::i32,
/*10359*/             OPC_MoveParent,
/*10360*/             OPC_MoveParent,
/*10361*/             OPC_MoveChild, 1,
/*10363*/             OPC_CheckOpcode, TARGET_VAL(ISD::SRA),
/*10366*/             OPC_MoveChild, 0,
/*10368*/             OPC_CheckOpcode, TARGET_VAL(ISD::SIGN_EXTEND_INREG),
/*10371*/             OPC_CheckChild0Same, 0,
/*10373*/             OPC_MoveChild, 1,
/*10375*/             OPC_CheckValueType, MVT::i32,
/*10377*/             OPC_MoveParent,
/*10378*/             OPC_MoveParent,
/*10379*/             OPC_MoveChild, 1,
/*10381*/             OPC_CheckInteger, 63, 
/*10383*/             OPC_CheckType, MVT::i32,
/*10385*/             OPC_MoveParent,
/*10386*/             OPC_MoveParent,
/*10387*/             OPC_MoveParent,
/*10388*/             OPC_EmitInteger, MVT::i32, SystemZ::subreg_l32,
/*10391*/             OPC_EmitNode, TARGET_VAL(TargetOpcode::EXTRACT_SUBREG), 0,
                          1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1,  // Results = #2
/*10400*/             OPC_MorphNodeTo, TARGET_VAL(SystemZ::LPGFR), 0,
                          2/*#VTs*/, MVT::i64, MVT::i32, 1/*#Ops*/, 2, 
                      // Src: (xor:i64 (sra:i64 (sext_inreg:i64 GR64:i64:$src, i32:Other), 63:i32), (add:i64 (sext_inreg:i64 GR64:i64:$src, i32:Other), (sra:i64 (sext_inreg:i64 GR64:i64:$src, i32:Other), 63:i32))) - Complexity = 31
                      // Dst: (LPGFR:i64:i32 (EXTRACT_SUBREG:i32 GR64:i64:$src, subreg_l32:i32))
/*10409*/           /*SwitchOpcode*/ 56,  TARGET_VAL(ISD::SRA),// ->10468
/*10412*/             OPC_MoveChild, 0,
/*10414*/             OPC_CheckOpcode, TARGET_VAL(ISD::SIGN_EXTEND_INREG),
/*10417*/             OPC_CheckChild0Same, 0,
/*10419*/             OPC_MoveChild, 1,
/*10421*/             OPC_CheckValueType, MVT::i32,
/*10423*/             OPC_MoveParent,
/*10424*/             OPC_MoveParent,
/*10425*/             OPC_MoveChild, 1,
/*10427*/             OPC_CheckInteger, 63, 
/*10429*/             OPC_CheckType, MVT::i32,
/*10431*/             OPC_MoveParent,
/*10432*/             OPC_MoveParent,
/*10433*/             OPC_MoveChild, 1,
/*10435*/             OPC_CheckOpcode, TARGET_VAL(ISD::SIGN_EXTEND_INREG),
/*10438*/             OPC_CheckChild0Same, 0,
/*10440*/             OPC_MoveChild, 1,
/*10442*/             OPC_CheckValueType, MVT::i32,
/*10444*/             OPC_MoveParent,
/*10445*/             OPC_MoveParent,
/*10446*/             OPC_MoveParent,
/*10447*/             OPC_EmitInteger, MVT::i32, SystemZ::subreg_l32,
/*10450*/             OPC_EmitNode, TARGET_VAL(TargetOpcode::EXTRACT_SUBREG), 0,
                          1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1,  // Results = #2
/*10459*/             OPC_MorphNodeTo, TARGET_VAL(SystemZ::LPGFR), 0,
                          2/*#VTs*/, MVT::i64, MVT::i32, 1/*#Ops*/, 2, 
                      // Src: (xor:i64 (sra:i64 (sext_inreg:i64 GR64:i64:$src, i32:Other), 63:i32), (add:i64 (sra:i64 (sext_inreg:i64 GR64:i64:$src, i32:Other), 63:i32), (sext_inreg:i64 GR64:i64:$src, i32:Other))) - Complexity = 31
                      // Dst: (LPGFR:i64:i32 (EXTRACT_SUBREG:i32 GR64:i64:$src, subreg_l32:i32))
/*10468*/           0, // EndSwitchOpcode
/*10469*/         0, // EndSwitchOpcode
/*10470*/       /*Scope*/ 23|128,1/*151*/, /*->10623*/
/*10472*/         OPC_RecordChild0, // #0 = $R2
/*10473*/         OPC_MoveChild, 1,
/*10475*/         OPC_CheckType, MVT::i32,
/*10477*/         OPC_Scope, 71, /*->10550*/ // 2 children in Scope
/*10479*/           OPC_CheckInteger, 31, 
/*10481*/           OPC_MoveParent,
/*10482*/           OPC_MoveParent,
/*10483*/           OPC_MoveChild, 1,
/*10485*/           OPC_CheckOpcode, TARGET_VAL(ISD::ADD),
/*10488*/           OPC_Scope, 29, /*->10519*/ // 2 children in Scope
/*10490*/             OPC_CheckChild0Same, 0,
/*10492*/             OPC_MoveChild, 1,
/*10494*/             OPC_CheckOpcode, TARGET_VAL(ISD::SRA),
/*10497*/             OPC_CheckChild0Same, 0,
/*10499*/             OPC_MoveChild, 1,
/*10501*/             OPC_CheckInteger, 31, 
/*10503*/             OPC_CheckType, MVT::i32,
/*10505*/             OPC_MoveParent,
/*10506*/             OPC_MoveParent,
/*10507*/             OPC_MoveParent,
/*10508*/             OPC_CheckType, MVT::i32,
/*10510*/             OPC_MorphNodeTo, TARGET_VAL(SystemZ::LPR), 0,
                          2/*#VTs*/, MVT::i32, MVT::i32, 1/*#Ops*/, 0, 
                      // Src: (xor:i32 (sra:i32 GR32:i32:$R2, 31:i32), (add:i32 GR32:i32:$R2, (sra:i32 GR32:i32:$R2, 31:i32))) - Complexity = 22
                      // Dst: (LPR:i32:i32 GR32:i32:$R2)
/*10519*/           /*Scope*/ 29, /*->10549*/
/*10520*/             OPC_MoveChild, 0,
/*10522*/             OPC_CheckOpcode, TARGET_VAL(ISD::SRA),
/*10525*/             OPC_CheckChild0Same, 0,
/*10527*/             OPC_MoveChild, 1,
/*10529*/             OPC_CheckInteger, 31, 
/*10531*/             OPC_CheckType, MVT::i32,
/*10533*/             OPC_MoveParent,
/*10534*/             OPC_MoveParent,
/*10535*/             OPC_CheckChild1Same, 0,
/*10537*/             OPC_MoveParent,
/*10538*/             OPC_CheckType, MVT::i32,
/*10540*/             OPC_MorphNodeTo, TARGET_VAL(SystemZ::LPR), 0,
                          2/*#VTs*/, MVT::i32, MVT::i32, 1/*#Ops*/, 0, 
                      // Src: (xor:i32 (sra:i32 GR32:i32:$R2, 31:i32), (add:i32 (sra:i32 GR32:i32:$R2, 31:i32), GR32:i32:$R2)) - Complexity = 22
                      // Dst: (LPR:i32:i32 GR32:i32:$R2)
/*10549*/           0, /*End of Scope*/
/*10550*/         /*Scope*/ 71, /*->10622*/
/*10551*/           OPC_CheckInteger, 63, 
/*10553*/           OPC_MoveParent,
/*10554*/           OPC_MoveParent,
/*10555*/           OPC_MoveChild, 1,
/*10557*/           OPC_CheckOpcode, TARGET_VAL(ISD::ADD),
/*10560*/           OPC_Scope, 29, /*->10591*/ // 2 children in Scope
/*10562*/             OPC_CheckChild0Same, 0,
/*10564*/             OPC_MoveChild, 1,
/*10566*/             OPC_CheckOpcode, TARGET_VAL(ISD::SRA),
/*10569*/             OPC_CheckChild0Same, 0,
/*10571*/             OPC_MoveChild, 1,
/*10573*/             OPC_CheckInteger, 63, 
/*10575*/             OPC_CheckType, MVT::i32,
/*10577*/             OPC_MoveParent,
/*10578*/             OPC_MoveParent,
/*10579*/             OPC_MoveParent,
/*10580*/             OPC_CheckType, MVT::i64,
/*10582*/             OPC_MorphNodeTo, TARGET_VAL(SystemZ::LPGR), 0,
                          2/*#VTs*/, MVT::i64, MVT::i32, 1/*#Ops*/, 0, 
                      // Src: (xor:i64 (sra:i64 GR64:i64:$R2, 63:i32), (add:i64 GR64:i64:$R2, (sra:i64 GR64:i64:$R2, 63:i32))) - Complexity = 22
                      // Dst: (LPGR:i64:i32 GR64:i64:$R2)
/*10591*/           /*Scope*/ 29, /*->10621*/
/*10592*/             OPC_MoveChild, 0,
/*10594*/             OPC_CheckOpcode, TARGET_VAL(ISD::SRA),
/*10597*/             OPC_CheckChild0Same, 0,
/*10599*/             OPC_MoveChild, 1,
/*10601*/             OPC_CheckInteger, 63, 
/*10603*/             OPC_CheckType, MVT::i32,
/*10605*/             OPC_MoveParent,
/*10606*/             OPC_MoveParent,
/*10607*/             OPC_CheckChild1Same, 0,
/*10609*/             OPC_MoveParent,
/*10610*/             OPC_CheckType, MVT::i64,
/*10612*/             OPC_MorphNodeTo, TARGET_VAL(SystemZ::LPGR), 0,
                          2/*#VTs*/, MVT::i64, MVT::i32, 1/*#Ops*/, 0, 
                      // Src: (xor:i64 (sra:i64 GR64:i64:$R2, 63:i32), (add:i64 (sra:i64 GR64:i64:$R2, 63:i32), GR64:i64:$R2)) - Complexity = 22
                      // Dst: (LPGR:i64:i32 GR64:i64:$R2)
/*10621*/           0, /*End of Scope*/
/*10622*/         0, /*End of Scope*/
/*10623*/       0, /*End of Scope*/
/*10624*/     0, // EndSwitchOpcode
/*10625*/   /*Scope*/ 75, /*->10701*/
/*10626*/     OPC_RecordChild0, // #0 = $R1src
/*10627*/     OPC_MoveChild, 1,
/*10629*/     OPC_CheckOpcode, TARGET_VAL(ISD::LOAD),
/*10632*/     OPC_RecordMemRef,
/*10633*/     OPC_RecordNode, // #1 = 'ld' chained node
/*10634*/     OPC_CheckFoldableChainNode,
/*10635*/     OPC_RecordChild1, // #2 = $XBD2
/*10636*/     OPC_CheckChild1Type, MVT::i64,
/*10638*/     OPC_CheckPredicate, 0, // Predicate_unindexedload
/*10640*/     OPC_CheckPredicate, 13, // Predicate_load
/*10642*/     OPC_MoveParent,
/*10643*/     OPC_SwitchType /*2 cases */, 36,  MVT::i32,// ->10682
/*10646*/       OPC_Scope, 16, /*->10664*/ // 2 children in Scope
/*10648*/         OPC_CheckComplexPat, /*CP*/7, /*#*/2, // selectBDXAddr12Pair:$XBD2 #3 #4 #5
/*10651*/         OPC_EmitMergeInputChains1_1,
/*10652*/         OPC_MorphNodeTo, TARGET_VAL(SystemZ::X), 0|OPFL_Chain|OPFL_MemRefs,
                      2/*#VTs*/, MVT::i32, MVT::i32, 4/*#Ops*/, 0, 3, 4, 5, 
                  // Src: (xor:i32 GR32:i32:$R1src, (ld:i32 bdxaddr12pair:i64:$XBD2)<<P:Predicate_unindexedload>><<P:Predicate_load>>) - Complexity = 19
                  // Dst: (X:i32:i32 GR32:i32:$R1src, bdxaddr12pair:i64:$XBD2)
/*10664*/       /*Scope*/ 16, /*->10681*/
/*10665*/         OPC_CheckComplexPat, /*CP*/8, /*#*/2, // selectBDXAddr20Pair:$XBD2 #3 #4 #5
/*10668*/         OPC_EmitMergeInputChains1_1,
/*10669*/         OPC_MorphNodeTo, TARGET_VAL(SystemZ::XY), 0|OPFL_Chain|OPFL_MemRefs,
                      2/*#VTs*/, MVT::i32, MVT::i32, 4/*#Ops*/, 0, 3, 4, 5, 
                  // Src: (xor:i32 GR32:i32:$R1src, (ld:i32 bdxaddr20pair:i64:$XBD2)<<P:Predicate_unindexedload>><<P:Predicate_load>>) - Complexity = 19
                  // Dst: (XY:i32:i32 GR32:i32:$R1src, bdxaddr20pair:i64:$XBD2)
/*10681*/       0, /*End of Scope*/
/*10682*/     /*SwitchType*/ 16,  MVT::i64,// ->10700
/*10684*/       OPC_CheckComplexPat, /*CP*/0, /*#*/2, // selectBDXAddr20Only:$XBD2 #3 #4 #5
/*10687*/       OPC_EmitMergeInputChains1_1,
/*10688*/       OPC_MorphNodeTo, TARGET_VAL(SystemZ::XG), 0|OPFL_Chain|OPFL_MemRefs,
                    2/*#VTs*/, MVT::i64, MVT::i32, 4/*#Ops*/, 0, 3, 4, 5, 
                // Src: (xor:i64 GR64:i64:$R1src, (ld:i64 bdxaddr20only:i64:$XBD2)<<P:Predicate_unindexedload>><<P:Predicate_load>>) - Complexity = 19
                // Dst: (XG:i64:i32 GR64:i64:$R1src, bdxaddr20only:i64:$XBD2)
/*10700*/     0, // EndSwitchType
/*10701*/   /*Scope*/ 75, /*->10777*/
/*10702*/     OPC_MoveChild, 0,
/*10704*/     OPC_CheckOpcode, TARGET_VAL(ISD::LOAD),
/*10707*/     OPC_RecordMemRef,
/*10708*/     OPC_RecordNode, // #0 = 'ld' chained node
/*10709*/     OPC_CheckFoldableChainNode,
/*10710*/     OPC_RecordChild1, // #1 = $XBD2
/*10711*/     OPC_CheckChild1Type, MVT::i64,
/*10713*/     OPC_CheckPredicate, 0, // Predicate_unindexedload
/*10715*/     OPC_CheckPredicate, 13, // Predicate_load
/*10717*/     OPC_MoveParent,
/*10718*/     OPC_RecordChild1, // #2 = $R1src
/*10719*/     OPC_SwitchType /*2 cases */, 36,  MVT::i32,// ->10758
/*10722*/       OPC_Scope, 16, /*->10740*/ // 2 children in Scope
/*10724*/         OPC_CheckComplexPat, /*CP*/7, /*#*/1, // selectBDXAddr12Pair:$XBD2 #3 #4 #5
/*10727*/         OPC_EmitMergeInputChains1_0,
/*10728*/         OPC_MorphNodeTo, TARGET_VAL(SystemZ::X), 0|OPFL_Chain|OPFL_MemRefs,
                      2/*#VTs*/, MVT::i32, MVT::i32, 4/*#Ops*/, 2, 3, 4, 5, 
                  // Src: (xor:i32 (ld:i32 bdxaddr12pair:i64:$XBD2)<<P:Predicate_unindexedload>><<P:Predicate_load>>, GR32:i32:$R1src) - Complexity = 19
                  // Dst: (X:i32:i32 GR32:i32:$R1src, bdxaddr12pair:i64:$XBD2)
/*10740*/       /*Scope*/ 16, /*->10757*/
/*10741*/         OPC_CheckComplexPat, /*CP*/8, /*#*/1, // selectBDXAddr20Pair:$XBD2 #3 #4 #5
/*10744*/         OPC_EmitMergeInputChains1_0,
/*10745*/         OPC_MorphNodeTo, TARGET_VAL(SystemZ::XY), 0|OPFL_Chain|OPFL_MemRefs,
                      2/*#VTs*/, MVT::i32, MVT::i32, 4/*#Ops*/, 2, 3, 4, 5, 
                  // Src: (xor:i32 (ld:i32 bdxaddr20pair:i64:$XBD2)<<P:Predicate_unindexedload>><<P:Predicate_load>>, GR32:i32:$R1src) - Complexity = 19
                  // Dst: (XY:i32:i32 GR32:i32:$R1src, bdxaddr20pair:i64:$XBD2)
/*10757*/       0, /*End of Scope*/
/*10758*/     /*SwitchType*/ 16,  MVT::i64,// ->10776
/*10760*/       OPC_CheckComplexPat, /*CP*/0, /*#*/1, // selectBDXAddr20Only:$XBD2 #3 #4 #5
/*10763*/       OPC_EmitMergeInputChains1_0,
/*10764*/       OPC_MorphNodeTo, TARGET_VAL(SystemZ::XG), 0|OPFL_Chain|OPFL_MemRefs,
                    2/*#VTs*/, MVT::i64, MVT::i32, 4/*#Ops*/, 2, 3, 4, 5, 
                // Src: (xor:i64 (ld:i64 bdxaddr20only:i64:$XBD2)<<P:Predicate_unindexedload>><<P:Predicate_load>>, GR64:i64:$R1src) - Complexity = 19
                // Dst: (XG:i64:i32 GR64:i64:$R1src, bdxaddr20only:i64:$XBD2)
/*10776*/     0, // EndSwitchType
/*10777*/   /*Scope*/ 6|128,1/*134*/, /*->10913*/
/*10779*/     OPC_RecordChild0, // #0 = $R1src
/*10780*/     OPC_RecordChild1, // #1 = $I2
/*10781*/     OPC_Scope, 103, /*->10886*/ // 3 children in Scope
/*10783*/       OPC_MoveChild, 1,
/*10785*/       OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*10788*/       OPC_Scope, 20, /*->10810*/ // 3 children in Scope
/*10790*/         OPC_CheckPredicate, 40, // Predicate_imm64lf32
/*10792*/         OPC_MoveParent,
/*10793*/         OPC_CheckType, MVT::i64,
/*10795*/         OPC_EmitConvertToTarget, 1,
/*10797*/         OPC_EmitNodeXForm, 3, 2, // LF32
/*10800*/         OPC_MorphNodeTo, TARGET_VAL(SystemZ::XILF64), 0,
                      2/*#VTs*/, MVT::i64, MVT::i32, 2/*#Ops*/, 0, 3, 
                  // Src: (xor:i64 GR64:i64:$R1src, (imm:i64)<<P:Predicate_imm64lf32>><<X:LF32>>:$I2) - Complexity = 7
                  // Dst: (XILF64:i64:i32 GR64:i64:$R1src, (LF32:i64 (imm:i64):$I2))
/*10810*/       /*Scope*/ 20, /*->10831*/
/*10811*/         OPC_CheckPredicate, 41, // Predicate_imm64hf32
/*10813*/         OPC_MoveParent,
/*10814*/         OPC_CheckType, MVT::i64,
/*10816*/         OPC_EmitConvertToTarget, 1,
/*10818*/         OPC_EmitNodeXForm, 4, 2, // HF32
/*10821*/         OPC_MorphNodeTo, TARGET_VAL(SystemZ::XIHF64), 0,
                      2/*#VTs*/, MVT::i64, MVT::i32, 2/*#Ops*/, 0, 3, 
                  // Src: (xor:i64 GR64:i64:$R1src, (imm:i64)<<P:Predicate_imm64hf32>><<X:HF32>>:$I2) - Complexity = 7
                  // Dst: (XIHF64:i64:i32 GR64:i64:$R1src, (HF32:i64 (imm:i64):$I2))
/*10831*/       /*Scope*/ 53, /*->10885*/
/*10832*/         OPC_MoveParent,
/*10833*/         OPC_CheckType, MVT::i32,
/*10835*/         OPC_Scope, 17, /*->10854*/ // 2 children in Scope
/*10837*/           OPC_CheckPatternPredicate, 0, // (Subtarget.hasHighWord())
/*10839*/           OPC_EmitConvertToTarget, 1,
/*10841*/           OPC_EmitNodeXForm, 5, 2, // UIMM32
/*10844*/           OPC_MorphNodeTo, TARGET_VAL(SystemZ::XIFMux), 0,
                        2/*#VTs*/, MVT::i32, MVT::i32, 2/*#Ops*/, 0, 3, 
                    // Src: (xor:i32 GRX32:i32:$R1src, (imm:i32)<<X:UIMM32>>:$I2) - Complexity = 6
                    // Dst: (XIFMux:i32:i32 GRX32:i32:$R1src, (UIMM32:i32 (imm:i32):$I2))
/*10854*/         /*Scope*/ 29, /*->10884*/
/*10855*/           OPC_EmitConvertToTarget, 1,
/*10857*/           OPC_EmitNodeXForm, 5, 2, // UIMM32
/*10860*/           OPC_Scope, 10, /*->10872*/ // 2 children in Scope
/*10862*/             OPC_MorphNodeTo, TARGET_VAL(SystemZ::XILF), 0,
                          2/*#VTs*/, MVT::i32, MVT::i32, 2/*#Ops*/, 0, 3, 
                      // Src: (xor:i32 GR32:i32:$R1src, (imm:i32)<<X:UIMM32>>:$I2) - Complexity = 6
                      // Dst: (XILF:i32:i32 GR32:i32:$R1src, (UIMM32:i32 (imm:i32):$I2))
/*10872*/           /*Scope*/ 10, /*->10883*/
/*10873*/             OPC_MorphNodeTo, TARGET_VAL(SystemZ::XIHF), 0,
                          2/*#VTs*/, MVT::i32, MVT::i32, 2/*#Ops*/, 0, 3, 
                      // Src: (xor:i32 GRH32:i32:$R1src, (imm:i32)<<X:UIMM32>>:$I2) - Complexity = 6
                      // Dst: (XIHF:i32:i32 GRH32:i32:$R1src, (UIMM32:i32 (imm:i32):$I2))
/*10883*/           0, /*End of Scope*/
/*10884*/         0, /*End of Scope*/
/*10885*/       0, /*End of Scope*/
/*10886*/     /*Scope*/ 12, /*->10899*/
/*10887*/       OPC_CheckType, MVT::i32,
/*10889*/       OPC_MorphNodeTo, TARGET_VAL(SystemZ::XR), 0,
                    2/*#VTs*/, MVT::i32, MVT::i32, 2/*#Ops*/, 0, 1, 
                // Src: (xor:i32 GR32:i32:$R1src, GR32:i32:$R2) - Complexity = 3
                // Dst: (XR:i32:i32 GR32:i32:$R1src, GR32:i32:$R2)
/*10899*/     /*Scope*/ 12, /*->10912*/
/*10900*/       OPC_CheckType, MVT::i64,
/*10902*/       OPC_MorphNodeTo, TARGET_VAL(SystemZ::XGR), 0,
                    2/*#VTs*/, MVT::i64, MVT::i32, 2/*#Ops*/, 0, 1, 
                // Src: (xor:i64 GR64:i64:$R1src, GR64:i64:$R2) - Complexity = 3
                // Dst: (XGR:i64:i32 GR64:i64:$R1src, GR64:i64:$R2)
/*10912*/     0, /*End of Scope*/
/*10913*/   0, /*End of Scope*/
/*10914*/ /*SwitchOpcode*/ 93|128,14/*1885*/,  TARGET_VAL(ISD::OR),// ->12803
/*10918*/   OPC_Scope, 88|128,1/*216*/, /*->11137*/ // 20 children in Scope
/*10921*/     OPC_MoveChild, 0,
/*10923*/     OPC_Scope, 105, /*->11030*/ // 2 children in Scope
/*10925*/       OPC_CheckAndImm, 0|128,126|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551360*/, 
/*10936*/       OPC_RecordChild0, // #0 = $R1src
/*10937*/       OPC_MoveParent,
/*10938*/       OPC_MoveChild, 1,
/*10940*/       OPC_CheckOpcode, TARGET_VAL(ISD::LOAD),
/*10943*/       OPC_RecordMemRef,
/*10944*/       OPC_RecordNode, // #1 = 'ld' chained node
/*10945*/       OPC_CheckFoldableChainNode,
/*10946*/       OPC_RecordChild1, // #2 = $XBD2
/*10947*/       OPC_CheckChild1Type, MVT::i64,
/*10949*/       OPC_CheckPredicate, 0, // Predicate_unindexedload
/*10951*/       OPC_CheckPredicate, 38, // Predicate_azextload
/*10953*/       OPC_CheckPredicate, 42, // Predicate_azextloadi8
/*10955*/       OPC_MoveParent,
/*10956*/       OPC_SwitchType /*2 cases */, 34,  MVT::i32,// ->10993
/*10959*/         OPC_Scope, 15, /*->10976*/ // 2 children in Scope
/*10961*/           OPC_CheckComplexPat, /*CP*/7, /*#*/2, // selectBDXAddr12Pair:$XBD2 #3 #4 #5
/*10964*/           OPC_EmitMergeInputChains1_1,
/*10965*/           OPC_MorphNodeTo, TARGET_VAL(SystemZ::IC32), 0|OPFL_Chain|OPFL_MemRefs,
                        1/*#VTs*/, MVT::i32, 4/*#Ops*/, 0, 3, 4, 5, 
                    // Src: (or:i32 (and:i32 GR32:i32:$R1src, -256:i32), (ld:i32 bdxaddr12pair:i64:$XBD2)<<P:Predicate_unindexedload>><<P:Predicate_azextload>><<P:Predicate_azextloadi8>>) - Complexity = 27
                    // Dst: (IC32:i32 GR32:i32:$R1src, bdxaddr12pair:i64:$XBD2)
/*10976*/         /*Scope*/ 15, /*->10992*/
/*10977*/           OPC_CheckComplexPat, /*CP*/8, /*#*/2, // selectBDXAddr20Pair:$XBD2 #3 #4 #5
/*10980*/           OPC_EmitMergeInputChains1_1,
/*10981*/           OPC_MorphNodeTo, TARGET_VAL(SystemZ::IC32Y), 0|OPFL_Chain|OPFL_MemRefs,
                        1/*#VTs*/, MVT::i32, 4/*#Ops*/, 0, 3, 4, 5, 
                    // Src: (or:i32 (and:i32 GR32:i32:$R1src, -256:i32), (ld:i32 bdxaddr20pair:i64:$XBD2)<<P:Predicate_unindexedload>><<P:Predicate_azextload>><<P:Predicate_azextloadi8>>) - Complexity = 27
                    // Dst: (IC32Y:i32 GR32:i32:$R1src, bdxaddr20pair:i64:$XBD2)
/*10992*/         0, /*End of Scope*/
/*10993*/       /*SwitchType*/ 34,  MVT::i64,// ->11029
/*10995*/         OPC_Scope, 15, /*->11012*/ // 2 children in Scope
/*10997*/           OPC_CheckComplexPat, /*CP*/7, /*#*/2, // selectBDXAddr12Pair:$XBD2 #3 #4 #5
/*11000*/           OPC_EmitMergeInputChains1_1,
/*11001*/           OPC_MorphNodeTo, TARGET_VAL(SystemZ::IC), 0|OPFL_Chain|OPFL_MemRefs,
                        1/*#VTs*/, MVT::i64, 4/*#Ops*/, 0, 3, 4, 5, 
                    // Src: (or:i64 (and:i64 GR64:i64:$R1src, -256:i64), (ld:i64 bdxaddr12pair:i64:$XBD2)<<P:Predicate_unindexedload>><<P:Predicate_azextload>><<P:Predicate_azextloadi8>>) - Complexity = 27
                    // Dst: (IC:i64 GR64:i64:$R1src, bdxaddr12pair:i64:$XBD2)
/*11012*/         /*Scope*/ 15, /*->11028*/
/*11013*/           OPC_CheckComplexPat, /*CP*/8, /*#*/2, // selectBDXAddr20Pair:$XBD2 #3 #4 #5
/*11016*/           OPC_EmitMergeInputChains1_1,
/*11017*/           OPC_MorphNodeTo, TARGET_VAL(SystemZ::ICY), 0|OPFL_Chain|OPFL_MemRefs,
                        1/*#VTs*/, MVT::i64, 4/*#Ops*/, 0, 3, 4, 5, 
                    // Src: (or:i64 (and:i64 GR64:i64:$R1src, -256:i64), (ld:i64 bdxaddr20pair:i64:$XBD2)<<P:Predicate_unindexedload>><<P:Predicate_azextload>><<P:Predicate_azextloadi8>>) - Complexity = 27
                    // Dst: (ICY:i64 GR64:i64:$R1src, bdxaddr20pair:i64:$XBD2)
/*11028*/         0, /*End of Scope*/
/*11029*/       0, // EndSwitchType
/*11030*/     /*Scope*/ 105, /*->11136*/
/*11031*/       OPC_CheckOpcode, TARGET_VAL(ISD::LOAD),
/*11034*/       OPC_RecordMemRef,
/*11035*/       OPC_RecordNode, // #0 = 'ld' chained node
/*11036*/       OPC_CheckFoldableChainNode,
/*11037*/       OPC_RecordChild1, // #1 = $XBD2
/*11038*/       OPC_CheckChild1Type, MVT::i64,
/*11040*/       OPC_CheckPredicate, 0, // Predicate_unindexedload
/*11042*/       OPC_CheckPredicate, 38, // Predicate_azextload
/*11044*/       OPC_CheckPredicate, 42, // Predicate_azextloadi8
/*11046*/       OPC_MoveParent,
/*11047*/       OPC_MoveChild, 1,
/*11049*/       OPC_CheckAndImm, 0|128,126|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551360*/, 
/*11060*/       OPC_RecordChild0, // #2 = $R1src
/*11061*/       OPC_MoveParent,
/*11062*/       OPC_SwitchType /*2 cases */, 34,  MVT::i32,// ->11099
/*11065*/         OPC_Scope, 15, /*->11082*/ // 2 children in Scope
/*11067*/           OPC_CheckComplexPat, /*CP*/7, /*#*/1, // selectBDXAddr12Pair:$XBD2 #3 #4 #5
/*11070*/           OPC_EmitMergeInputChains1_0,
/*11071*/           OPC_MorphNodeTo, TARGET_VAL(SystemZ::IC32), 0|OPFL_Chain|OPFL_MemRefs,
                        1/*#VTs*/, MVT::i32, 4/*#Ops*/, 2, 3, 4, 5, 
                    // Src: (or:i32 (ld:i32 bdxaddr12pair:i64:$XBD2)<<P:Predicate_unindexedload>><<P:Predicate_azextload>><<P:Predicate_azextloadi8>>, (and:i32 GR32:i32:$R1src, -256:i32)) - Complexity = 27
                    // Dst: (IC32:i32 GR32:i32:$R1src, bdxaddr12pair:i64:$XBD2)
/*11082*/         /*Scope*/ 15, /*->11098*/
/*11083*/           OPC_CheckComplexPat, /*CP*/8, /*#*/1, // selectBDXAddr20Pair:$XBD2 #3 #4 #5
/*11086*/           OPC_EmitMergeInputChains1_0,
/*11087*/           OPC_MorphNodeTo, TARGET_VAL(SystemZ::IC32Y), 0|OPFL_Chain|OPFL_MemRefs,
                        1/*#VTs*/, MVT::i32, 4/*#Ops*/, 2, 3, 4, 5, 
                    // Src: (or:i32 (ld:i32 bdxaddr20pair:i64:$XBD2)<<P:Predicate_unindexedload>><<P:Predicate_azextload>><<P:Predicate_azextloadi8>>, (and:i32 GR32:i32:$R1src, -256:i32)) - Complexity = 27
                    // Dst: (IC32Y:i32 GR32:i32:$R1src, bdxaddr20pair:i64:$XBD2)
/*11098*/         0, /*End of Scope*/
/*11099*/       /*SwitchType*/ 34,  MVT::i64,// ->11135
/*11101*/         OPC_Scope, 15, /*->11118*/ // 2 children in Scope
/*11103*/           OPC_CheckComplexPat, /*CP*/7, /*#*/1, // selectBDXAddr12Pair:$XBD2 #3 #4 #5
/*11106*/           OPC_EmitMergeInputChains1_0,
/*11107*/           OPC_MorphNodeTo, TARGET_VAL(SystemZ::IC), 0|OPFL_Chain|OPFL_MemRefs,
                        1/*#VTs*/, MVT::i64, 4/*#Ops*/, 2, 3, 4, 5, 
                    // Src: (or:i64 (ld:i64 bdxaddr12pair:i64:$XBD2)<<P:Predicate_unindexedload>><<P:Predicate_azextload>><<P:Predicate_azextloadi8>>, (and:i64 GR64:i64:$R1src, -256:i64)) - Complexity = 27
                    // Dst: (IC:i64 GR64:i64:$R1src, bdxaddr12pair:i64:$XBD2)
/*11118*/         /*Scope*/ 15, /*->11134*/
/*11119*/           OPC_CheckComplexPat, /*CP*/8, /*#*/1, // selectBDXAddr20Pair:$XBD2 #3 #4 #5
/*11122*/           OPC_EmitMergeInputChains1_0,
/*11123*/           OPC_MorphNodeTo, TARGET_VAL(SystemZ::ICY), 0|OPFL_Chain|OPFL_MemRefs,
                        1/*#VTs*/, MVT::i64, 4/*#Ops*/, 2, 3, 4, 5, 
                    // Src: (or:i64 (ld:i64 bdxaddr20pair:i64:$XBD2)<<P:Predicate_unindexedload>><<P:Predicate_azextload>><<P:Predicate_azextloadi8>>, (and:i64 GR64:i64:$R1src, -256:i64)) - Complexity = 27
                    // Dst: (ICY:i64 GR64:i64:$R1src, bdxaddr20pair:i64:$XBD2)
/*11134*/         0, /*End of Scope*/
/*11135*/       0, // EndSwitchType
/*11136*/     0, /*End of Scope*/
/*11137*/   /*Scope*/ 38, /*->11176*/
/*11138*/     OPC_RecordChild0, // #0 = $src1
/*11139*/     OPC_MoveChild, 1,
/*11141*/     OPC_CheckOpcode, TARGET_VAL(ISD::LOAD),
/*11144*/     OPC_RecordMemRef,
/*11145*/     OPC_RecordNode, // #1 = 'ld' chained node
/*11146*/     OPC_CheckFoldableChainNode,
/*11147*/     OPC_RecordChild1, // #2 = $src2
/*11148*/     OPC_CheckChild1Type, MVT::i64,
/*11150*/     OPC_CheckPredicate, 0, // Predicate_unindexedload
/*11152*/     OPC_CheckPredicate, 38, // Predicate_azextload
/*11154*/     OPC_CheckPredicate, 42, // Predicate_azextloadi8
/*11156*/     OPC_MoveParent,
/*11157*/     OPC_CheckPredicate, 43, // Predicate_or_as_inserti8
/*11159*/     OPC_CheckType, MVT::i32,
/*11161*/     OPC_CheckComplexPat, /*CP*/7, /*#*/2, // selectBDXAddr12Pair:$src2 #3 #4 #5
/*11164*/     OPC_EmitMergeInputChains1_1,
/*11165*/     OPC_MorphNodeTo, TARGET_VAL(SystemZ::IC32), 0|OPFL_Chain|OPFL_MemRefs,
                  1/*#VTs*/, MVT::i32, 4/*#Ops*/, 0, 3, 4, 5, 
              // Src: (or:i32 GR32:i32:$src1, (ld:i32 bdxaddr12pair:i64:$src2)<<P:Predicate_unindexedload>><<P:Predicate_azextload>><<P:Predicate_azextloadi8>>)<<P:Predicate_or_as_inserti8>> - Complexity = 20
              // Dst: (IC32:i32 GR32:i32:$src1, bdxaddr12pair:i64:$src2)
/*11176*/   /*Scope*/ 38, /*->11215*/
/*11177*/     OPC_MoveChild, 0,
/*11179*/     OPC_CheckOpcode, TARGET_VAL(ISD::LOAD),
/*11182*/     OPC_RecordMemRef,
/*11183*/     OPC_RecordNode, // #0 = 'ld' chained node
/*11184*/     OPC_CheckFoldableChainNode,
/*11185*/     OPC_RecordChild1, // #1 = $src2
/*11186*/     OPC_CheckChild1Type, MVT::i64,
/*11188*/     OPC_CheckPredicate, 0, // Predicate_unindexedload
/*11190*/     OPC_CheckPredicate, 38, // Predicate_azextload
/*11192*/     OPC_CheckPredicate, 42, // Predicate_azextloadi8
/*11194*/     OPC_MoveParent,
/*11195*/     OPC_RecordChild1, // #2 = $src1
/*11196*/     OPC_CheckPredicate, 44, // Predicate_or_as_revinserti8
/*11198*/     OPC_CheckType, MVT::i32,
/*11200*/     OPC_CheckComplexPat, /*CP*/7, /*#*/1, // selectBDXAddr12Pair:$src2 #3 #4 #5
/*11203*/     OPC_EmitMergeInputChains1_0,
/*11204*/     OPC_MorphNodeTo, TARGET_VAL(SystemZ::IC32), 0|OPFL_Chain|OPFL_MemRefs,
                  1/*#VTs*/, MVT::i32, 4/*#Ops*/, 2, 3, 4, 5, 
              // Src: (or:i32 (ld:i32 bdxaddr12pair:i64:$src2)<<P:Predicate_unindexedload>><<P:Predicate_azextload>><<P:Predicate_azextloadi8>>, GR32:i32:$src1)<<P:Predicate_or_as_revinserti8>> - Complexity = 20
              // Dst: (IC32:i32 GR32:i32:$src1, bdxaddr12pair:i64:$src2)
/*11215*/   /*Scope*/ 38, /*->11254*/
/*11216*/     OPC_RecordChild0, // #0 = $src1
/*11217*/     OPC_MoveChild, 1,
/*11219*/     OPC_CheckOpcode, TARGET_VAL(ISD::LOAD),
/*11222*/     OPC_RecordMemRef,
/*11223*/     OPC_RecordNode, // #1 = 'ld' chained node
/*11224*/     OPC_CheckFoldableChainNode,
/*11225*/     OPC_RecordChild1, // #2 = $src2
/*11226*/     OPC_CheckChild1Type, MVT::i64,
/*11228*/     OPC_CheckPredicate, 0, // Predicate_unindexedload
/*11230*/     OPC_CheckPredicate, 38, // Predicate_azextload
/*11232*/     OPC_CheckPredicate, 42, // Predicate_azextloadi8
/*11234*/     OPC_MoveParent,
/*11235*/     OPC_CheckPredicate, 43, // Predicate_or_as_inserti8
/*11237*/     OPC_CheckType, MVT::i32,
/*11239*/     OPC_CheckComplexPat, /*CP*/8, /*#*/2, // selectBDXAddr20Pair:$src2 #3 #4 #5
/*11242*/     OPC_EmitMergeInputChains1_1,
/*11243*/     OPC_MorphNodeTo, TARGET_VAL(SystemZ::IC32Y), 0|OPFL_Chain|OPFL_MemRefs,
                  1/*#VTs*/, MVT::i32, 4/*#Ops*/, 0, 3, 4, 5, 
              // Src: (or:i32 GR32:i32:$src1, (ld:i32 bdxaddr20pair:i64:$src2)<<P:Predicate_unindexedload>><<P:Predicate_azextload>><<P:Predicate_azextloadi8>>)<<P:Predicate_or_as_inserti8>> - Complexity = 20
              // Dst: (IC32Y:i32 GR32:i32:$src1, bdxaddr20pair:i64:$src2)
/*11254*/   /*Scope*/ 38, /*->11293*/
/*11255*/     OPC_MoveChild, 0,
/*11257*/     OPC_CheckOpcode, TARGET_VAL(ISD::LOAD),
/*11260*/     OPC_RecordMemRef,
/*11261*/     OPC_RecordNode, // #0 = 'ld' chained node
/*11262*/     OPC_CheckFoldableChainNode,
/*11263*/     OPC_RecordChild1, // #1 = $src2
/*11264*/     OPC_CheckChild1Type, MVT::i64,
/*11266*/     OPC_CheckPredicate, 0, // Predicate_unindexedload
/*11268*/     OPC_CheckPredicate, 38, // Predicate_azextload
/*11270*/     OPC_CheckPredicate, 42, // Predicate_azextloadi8
/*11272*/     OPC_MoveParent,
/*11273*/     OPC_RecordChild1, // #2 = $src1
/*11274*/     OPC_CheckPredicate, 44, // Predicate_or_as_revinserti8
/*11276*/     OPC_CheckType, MVT::i32,
/*11278*/     OPC_CheckComplexPat, /*CP*/8, /*#*/1, // selectBDXAddr20Pair:$src2 #3 #4 #5
/*11281*/     OPC_EmitMergeInputChains1_0,
/*11282*/     OPC_MorphNodeTo, TARGET_VAL(SystemZ::IC32Y), 0|OPFL_Chain|OPFL_MemRefs,
                  1/*#VTs*/, MVT::i32, 4/*#Ops*/, 2, 3, 4, 5, 
              // Src: (or:i32 (ld:i32 bdxaddr20pair:i64:$src2)<<P:Predicate_unindexedload>><<P:Predicate_azextload>><<P:Predicate_azextloadi8>>, GR32:i32:$src1)<<P:Predicate_or_as_revinserti8>> - Complexity = 20
              // Dst: (IC32Y:i32 GR32:i32:$src1, bdxaddr20pair:i64:$src2)
/*11293*/   /*Scope*/ 38, /*->11332*/
/*11294*/     OPC_RecordChild0, // #0 = $src1
/*11295*/     OPC_MoveChild, 1,
/*11297*/     OPC_CheckOpcode, TARGET_VAL(ISD::LOAD),
/*11300*/     OPC_RecordMemRef,
/*11301*/     OPC_RecordNode, // #1 = 'ld' chained node
/*11302*/     OPC_CheckFoldableChainNode,
/*11303*/     OPC_RecordChild1, // #2 = $src2
/*11304*/     OPC_CheckChild1Type, MVT::i64,
/*11306*/     OPC_CheckPredicate, 0, // Predicate_unindexedload
/*11308*/     OPC_CheckPredicate, 38, // Predicate_azextload
/*11310*/     OPC_CheckPredicate, 42, // Predicate_azextloadi8
/*11312*/     OPC_MoveParent,
/*11313*/     OPC_CheckPredicate, 43, // Predicate_or_as_inserti8
/*11315*/     OPC_CheckType, MVT::i64,
/*11317*/     OPC_CheckComplexPat, /*CP*/7, /*#*/2, // selectBDXAddr12Pair:$src2 #3 #4 #5
/*11320*/     OPC_EmitMergeInputChains1_1,
/*11321*/     OPC_MorphNodeTo, TARGET_VAL(SystemZ::IC), 0|OPFL_Chain|OPFL_MemRefs,
                  1/*#VTs*/, MVT::i64, 4/*#Ops*/, 0, 3, 4, 5, 
              // Src: (or:i64 GR64:i64:$src1, (ld:i64 bdxaddr12pair:i64:$src2)<<P:Predicate_unindexedload>><<P:Predicate_azextload>><<P:Predicate_azextloadi8>>)<<P:Predicate_or_as_inserti8>> - Complexity = 20
              // Dst: (IC:i64 GR64:i64:$src1, bdxaddr12pair:i64:$src2)
/*11332*/   /*Scope*/ 38, /*->11371*/
/*11333*/     OPC_MoveChild, 0,
/*11335*/     OPC_CheckOpcode, TARGET_VAL(ISD::LOAD),
/*11338*/     OPC_RecordMemRef,
/*11339*/     OPC_RecordNode, // #0 = 'ld' chained node
/*11340*/     OPC_CheckFoldableChainNode,
/*11341*/     OPC_RecordChild1, // #1 = $src2
/*11342*/     OPC_CheckChild1Type, MVT::i64,
/*11344*/     OPC_CheckPredicate, 0, // Predicate_unindexedload
/*11346*/     OPC_CheckPredicate, 38, // Predicate_azextload
/*11348*/     OPC_CheckPredicate, 42, // Predicate_azextloadi8
/*11350*/     OPC_MoveParent,
/*11351*/     OPC_RecordChild1, // #2 = $src1
/*11352*/     OPC_CheckPredicate, 44, // Predicate_or_as_revinserti8
/*11354*/     OPC_CheckType, MVT::i64,
/*11356*/     OPC_CheckComplexPat, /*CP*/7, /*#*/1, // selectBDXAddr12Pair:$src2 #3 #4 #5
/*11359*/     OPC_EmitMergeInputChains1_0,
/*11360*/     OPC_MorphNodeTo, TARGET_VAL(SystemZ::IC), 0|OPFL_Chain|OPFL_MemRefs,
                  1/*#VTs*/, MVT::i64, 4/*#Ops*/, 2, 3, 4, 5, 
              // Src: (or:i64 (ld:i64 bdxaddr12pair:i64:$src2)<<P:Predicate_unindexedload>><<P:Predicate_azextload>><<P:Predicate_azextloadi8>>, GR64:i64:$src1)<<P:Predicate_or_as_revinserti8>> - Complexity = 20
              // Dst: (IC:i64 GR64:i64:$src1, bdxaddr12pair:i64:$src2)
/*11371*/   /*Scope*/ 38, /*->11410*/
/*11372*/     OPC_RecordChild0, // #0 = $src1
/*11373*/     OPC_MoveChild, 1,
/*11375*/     OPC_CheckOpcode, TARGET_VAL(ISD::LOAD),
/*11378*/     OPC_RecordMemRef,
/*11379*/     OPC_RecordNode, // #1 = 'ld' chained node
/*11380*/     OPC_CheckFoldableChainNode,
/*11381*/     OPC_RecordChild1, // #2 = $src2
/*11382*/     OPC_CheckChild1Type, MVT::i64,
/*11384*/     OPC_CheckPredicate, 0, // Predicate_unindexedload
/*11386*/     OPC_CheckPredicate, 38, // Predicate_azextload
/*11388*/     OPC_CheckPredicate, 42, // Predicate_azextloadi8
/*11390*/     OPC_MoveParent,
/*11391*/     OPC_CheckPredicate, 43, // Predicate_or_as_inserti8
/*11393*/     OPC_CheckType, MVT::i64,
/*11395*/     OPC_CheckComplexPat, /*CP*/8, /*#*/2, // selectBDXAddr20Pair:$src2 #3 #4 #5
/*11398*/     OPC_EmitMergeInputChains1_1,
/*11399*/     OPC_MorphNodeTo, TARGET_VAL(SystemZ::ICY), 0|OPFL_Chain|OPFL_MemRefs,
                  1/*#VTs*/, MVT::i64, 4/*#Ops*/, 0, 3, 4, 5, 
              // Src: (or:i64 GR64:i64:$src1, (ld:i64 bdxaddr20pair:i64:$src2)<<P:Predicate_unindexedload>><<P:Predicate_azextload>><<P:Predicate_azextloadi8>>)<<P:Predicate_or_as_inserti8>> - Complexity = 20
              // Dst: (ICY:i64 GR64:i64:$src1, bdxaddr20pair:i64:$src2)
/*11410*/   /*Scope*/ 59, /*->11470*/
/*11411*/     OPC_MoveChild, 0,
/*11413*/     OPC_CheckOpcode, TARGET_VAL(ISD::LOAD),
/*11416*/     OPC_RecordMemRef,
/*11417*/     OPC_RecordNode, // #0 = 'ld' chained node
/*11418*/     OPC_CheckFoldableChainNode,
/*11419*/     OPC_RecordChild1, // #1 = $src2
/*11420*/     OPC_CheckChild1Type, MVT::i64,
/*11422*/     OPC_CheckPredicate, 0, // Predicate_unindexedload
/*11424*/     OPC_CheckPredicate, 38, // Predicate_azextload
/*11426*/     OPC_CheckPredicate, 42, // Predicate_azextloadi8
/*11428*/     OPC_MoveParent,
/*11429*/     OPC_RecordChild1, // #2 = $src1
/*11430*/     OPC_SwitchType /*2 cases */, 17,  MVT::i64,// ->11450
/*11433*/       OPC_CheckPredicate, 44, // Predicate_or_as_revinserti8
/*11435*/       OPC_CheckComplexPat, /*CP*/8, /*#*/1, // selectBDXAddr20Pair:$src2 #3 #4 #5
/*11438*/       OPC_EmitMergeInputChains1_0,
/*11439*/       OPC_MorphNodeTo, TARGET_VAL(SystemZ::ICY), 0|OPFL_Chain|OPFL_MemRefs,
                    1/*#VTs*/, MVT::i64, 4/*#Ops*/, 2, 3, 4, 5, 
                // Src: (or:i64 (ld:i64 bdxaddr20pair:i64:$src2)<<P:Predicate_unindexedload>><<P:Predicate_azextload>><<P:Predicate_azextloadi8>>, GR64:i64:$src1)<<P:Predicate_or_as_revinserti8>> - Complexity = 20
                // Dst: (ICY:i64 GR64:i64:$src1, bdxaddr20pair:i64:$src2)
/*11450*/     /*SwitchType*/ 17,  MVT::i32,// ->11469
/*11452*/       OPC_CheckPredicate, 43, // Predicate_or_as_inserti8
/*11454*/       OPC_CheckComplexPat, /*CP*/7, /*#*/1, // selectBDXAddr12Pair:$src2 #3 #4 #5
/*11457*/       OPC_EmitMergeInputChains1_0,
/*11458*/       OPC_MorphNodeTo, TARGET_VAL(SystemZ::IC32), 0|OPFL_Chain|OPFL_MemRefs,
                    1/*#VTs*/, MVT::i32, 4/*#Ops*/, 2, 3, 4, 5, 
                // Src: (or:i32 (ld:i32 bdxaddr12pair:i64:$src2)<<P:Predicate_unindexedload>><<P:Predicate_azextload>><<P:Predicate_azextloadi8>>, GR32:i32:$src1)<<P:Predicate_or_as_inserti8>> - Complexity = 20
                // Dst: (IC32:i32 GR32:i32:$src1, bdxaddr12pair:i64:$src2)
/*11469*/     0, // EndSwitchType
/*11470*/   /*Scope*/ 38, /*->11509*/
/*11471*/     OPC_RecordChild0, // #0 = $src1
/*11472*/     OPC_MoveChild, 1,
/*11474*/     OPC_CheckOpcode, TARGET_VAL(ISD::LOAD),
/*11477*/     OPC_RecordMemRef,
/*11478*/     OPC_RecordNode, // #1 = 'ld' chained node
/*11479*/     OPC_CheckFoldableChainNode,
/*11480*/     OPC_RecordChild1, // #2 = $src2
/*11481*/     OPC_CheckChild1Type, MVT::i64,
/*11483*/     OPC_CheckPredicate, 0, // Predicate_unindexedload
/*11485*/     OPC_CheckPredicate, 38, // Predicate_azextload
/*11487*/     OPC_CheckPredicate, 42, // Predicate_azextloadi8
/*11489*/     OPC_MoveParent,
/*11490*/     OPC_CheckPredicate, 44, // Predicate_or_as_revinserti8
/*11492*/     OPC_CheckType, MVT::i32,
/*11494*/     OPC_CheckComplexPat, /*CP*/7, /*#*/2, // selectBDXAddr12Pair:$src2 #3 #4 #5
/*11497*/     OPC_EmitMergeInputChains1_1,
/*11498*/     OPC_MorphNodeTo, TARGET_VAL(SystemZ::IC32), 0|OPFL_Chain|OPFL_MemRefs,
                  1/*#VTs*/, MVT::i32, 4/*#Ops*/, 0, 3, 4, 5, 
              // Src: (or:i32 GR32:i32:$src1, (ld:i32 bdxaddr12pair:i64:$src2)<<P:Predicate_unindexedload>><<P:Predicate_azextload>><<P:Predicate_azextloadi8>>)<<P:Predicate_or_as_revinserti8>> - Complexity = 20
              // Dst: (IC32:i32 GR32:i32:$src1, bdxaddr12pair:i64:$src2)
/*11509*/   /*Scope*/ 38, /*->11548*/
/*11510*/     OPC_MoveChild, 0,
/*11512*/     OPC_CheckOpcode, TARGET_VAL(ISD::LOAD),
/*11515*/     OPC_RecordMemRef,
/*11516*/     OPC_RecordNode, // #0 = 'ld' chained node
/*11517*/     OPC_CheckFoldableChainNode,
/*11518*/     OPC_RecordChild1, // #1 = $src2
/*11519*/     OPC_CheckChild1Type, MVT::i64,
/*11521*/     OPC_CheckPredicate, 0, // Predicate_unindexedload
/*11523*/     OPC_CheckPredicate, 38, // Predicate_azextload
/*11525*/     OPC_CheckPredicate, 42, // Predicate_azextloadi8
/*11527*/     OPC_MoveParent,
/*11528*/     OPC_RecordChild1, // #2 = $src1
/*11529*/     OPC_CheckPredicate, 43, // Predicate_or_as_inserti8
/*11531*/     OPC_CheckType, MVT::i32,
/*11533*/     OPC_CheckComplexPat, /*CP*/8, /*#*/1, // selectBDXAddr20Pair:$src2 #3 #4 #5
/*11536*/     OPC_EmitMergeInputChains1_0,
/*11537*/     OPC_MorphNodeTo, TARGET_VAL(SystemZ::IC32Y), 0|OPFL_Chain|OPFL_MemRefs,
                  1/*#VTs*/, MVT::i32, 4/*#Ops*/, 2, 3, 4, 5, 
              // Src: (or:i32 (ld:i32 bdxaddr20pair:i64:$src2)<<P:Predicate_unindexedload>><<P:Predicate_azextload>><<P:Predicate_azextloadi8>>, GR32:i32:$src1)<<P:Predicate_or_as_inserti8>> - Complexity = 20
              // Dst: (IC32Y:i32 GR32:i32:$src1, bdxaddr20pair:i64:$src2)
/*11548*/   /*Scope*/ 38, /*->11587*/
/*11549*/     OPC_RecordChild0, // #0 = $src1
/*11550*/     OPC_MoveChild, 1,
/*11552*/     OPC_CheckOpcode, TARGET_VAL(ISD::LOAD),
/*11555*/     OPC_RecordMemRef,
/*11556*/     OPC_RecordNode, // #1 = 'ld' chained node
/*11557*/     OPC_CheckFoldableChainNode,
/*11558*/     OPC_RecordChild1, // #2 = $src2
/*11559*/     OPC_CheckChild1Type, MVT::i64,
/*11561*/     OPC_CheckPredicate, 0, // Predicate_unindexedload
/*11563*/     OPC_CheckPredicate, 38, // Predicate_azextload
/*11565*/     OPC_CheckPredicate, 42, // Predicate_azextloadi8
/*11567*/     OPC_MoveParent,
/*11568*/     OPC_CheckPredicate, 44, // Predicate_or_as_revinserti8
/*11570*/     OPC_CheckType, MVT::i32,
/*11572*/     OPC_CheckComplexPat, /*CP*/8, /*#*/2, // selectBDXAddr20Pair:$src2 #3 #4 #5
/*11575*/     OPC_EmitMergeInputChains1_1,
/*11576*/     OPC_MorphNodeTo, TARGET_VAL(SystemZ::IC32Y), 0|OPFL_Chain|OPFL_MemRefs,
                  1/*#VTs*/, MVT::i32, 4/*#Ops*/, 0, 3, 4, 5, 
              // Src: (or:i32 GR32:i32:$src1, (ld:i32 bdxaddr20pair:i64:$src2)<<P:Predicate_unindexedload>><<P:Predicate_azextload>><<P:Predicate_azextloadi8>>)<<P:Predicate_or_as_revinserti8>> - Complexity = 20
              // Dst: (IC32Y:i32 GR32:i32:$src1, bdxaddr20pair:i64:$src2)
/*11587*/   /*Scope*/ 38, /*->11626*/
/*11588*/     OPC_MoveChild, 0,
/*11590*/     OPC_CheckOpcode, TARGET_VAL(ISD::LOAD),
/*11593*/     OPC_RecordMemRef,
/*11594*/     OPC_RecordNode, // #0 = 'ld' chained node
/*11595*/     OPC_CheckFoldableChainNode,
/*11596*/     OPC_RecordChild1, // #1 = $src2
/*11597*/     OPC_CheckChild1Type, MVT::i64,
/*11599*/     OPC_CheckPredicate, 0, // Predicate_unindexedload
/*11601*/     OPC_CheckPredicate, 38, // Predicate_azextload
/*11603*/     OPC_CheckPredicate, 42, // Predicate_azextloadi8
/*11605*/     OPC_MoveParent,
/*11606*/     OPC_RecordChild1, // #2 = $src1
/*11607*/     OPC_CheckPredicate, 43, // Predicate_or_as_inserti8
/*11609*/     OPC_CheckType, MVT::i64,
/*11611*/     OPC_CheckComplexPat, /*CP*/7, /*#*/1, // selectBDXAddr12Pair:$src2 #3 #4 #5
/*11614*/     OPC_EmitMergeInputChains1_0,
/*11615*/     OPC_MorphNodeTo, TARGET_VAL(SystemZ::IC), 0|OPFL_Chain|OPFL_MemRefs,
                  1/*#VTs*/, MVT::i64, 4/*#Ops*/, 2, 3, 4, 5, 
              // Src: (or:i64 (ld:i64 bdxaddr12pair:i64:$src2)<<P:Predicate_unindexedload>><<P:Predicate_azextload>><<P:Predicate_azextloadi8>>, GR64:i64:$src1)<<P:Predicate_or_as_inserti8>> - Complexity = 20
              // Dst: (IC:i64 GR64:i64:$src1, bdxaddr12pair:i64:$src2)
/*11626*/   /*Scope*/ 38, /*->11665*/
/*11627*/     OPC_RecordChild0, // #0 = $src1
/*11628*/     OPC_MoveChild, 1,
/*11630*/     OPC_CheckOpcode, TARGET_VAL(ISD::LOAD),
/*11633*/     OPC_RecordMemRef,
/*11634*/     OPC_RecordNode, // #1 = 'ld' chained node
/*11635*/     OPC_CheckFoldableChainNode,
/*11636*/     OPC_RecordChild1, // #2 = $src2
/*11637*/     OPC_CheckChild1Type, MVT::i64,
/*11639*/     OPC_CheckPredicate, 0, // Predicate_unindexedload
/*11641*/     OPC_CheckPredicate, 38, // Predicate_azextload
/*11643*/     OPC_CheckPredicate, 42, // Predicate_azextloadi8
/*11645*/     OPC_MoveParent,
/*11646*/     OPC_CheckPredicate, 44, // Predicate_or_as_revinserti8
/*11648*/     OPC_CheckType, MVT::i64,
/*11650*/     OPC_CheckComplexPat, /*CP*/7, /*#*/2, // selectBDXAddr12Pair:$src2 #3 #4 #5
/*11653*/     OPC_EmitMergeInputChains1_1,
/*11654*/     OPC_MorphNodeTo, TARGET_VAL(SystemZ::IC), 0|OPFL_Chain|OPFL_MemRefs,
                  1/*#VTs*/, MVT::i64, 4/*#Ops*/, 0, 3, 4, 5, 
              // Src: (or:i64 GR64:i64:$src1, (ld:i64 bdxaddr12pair:i64:$src2)<<P:Predicate_unindexedload>><<P:Predicate_azextload>><<P:Predicate_azextloadi8>>)<<P:Predicate_or_as_revinserti8>> - Complexity = 20
              // Dst: (IC:i64 GR64:i64:$src1, bdxaddr12pair:i64:$src2)
/*11665*/   /*Scope*/ 38, /*->11704*/
/*11666*/     OPC_MoveChild, 0,
/*11668*/     OPC_CheckOpcode, TARGET_VAL(ISD::LOAD),
/*11671*/     OPC_RecordMemRef,
/*11672*/     OPC_RecordNode, // #0 = 'ld' chained node
/*11673*/     OPC_CheckFoldableChainNode,
/*11674*/     OPC_RecordChild1, // #1 = $src2
/*11675*/     OPC_CheckChild1Type, MVT::i64,
/*11677*/     OPC_CheckPredicate, 0, // Predicate_unindexedload
/*11679*/     OPC_CheckPredicate, 38, // Predicate_azextload
/*11681*/     OPC_CheckPredicate, 42, // Predicate_azextloadi8
/*11683*/     OPC_MoveParent,
/*11684*/     OPC_RecordChild1, // #2 = $src1
/*11685*/     OPC_CheckPredicate, 43, // Predicate_or_as_inserti8
/*11687*/     OPC_CheckType, MVT::i64,
/*11689*/     OPC_CheckComplexPat, /*CP*/8, /*#*/1, // selectBDXAddr20Pair:$src2 #3 #4 #5
/*11692*/     OPC_EmitMergeInputChains1_0,
/*11693*/     OPC_MorphNodeTo, TARGET_VAL(SystemZ::ICY), 0|OPFL_Chain|OPFL_MemRefs,
                  1/*#VTs*/, MVT::i64, 4/*#Ops*/, 2, 3, 4, 5, 
              // Src: (or:i64 (ld:i64 bdxaddr20pair:i64:$src2)<<P:Predicate_unindexedload>><<P:Predicate_azextload>><<P:Predicate_azextloadi8>>, GR64:i64:$src1)<<P:Predicate_or_as_inserti8>> - Complexity = 20
              // Dst: (ICY:i64 GR64:i64:$src1, bdxaddr20pair:i64:$src2)
/*11704*/   /*Scope*/ 103, /*->11808*/
/*11705*/     OPC_RecordChild0, // #0 = $src1
/*11706*/     OPC_MoveChild, 1,
/*11708*/     OPC_CheckOpcode, TARGET_VAL(ISD::LOAD),
/*11711*/     OPC_RecordMemRef,
/*11712*/     OPC_RecordNode, // #1 = 'ld' chained node
/*11713*/     OPC_CheckFoldableChainNode,
/*11714*/     OPC_RecordChild1, // #2 = $src2
/*11715*/     OPC_CheckChild1Type, MVT::i64,
/*11717*/     OPC_CheckPredicate, 0, // Predicate_unindexedload
/*11719*/     OPC_Scope, 24, /*->11745*/ // 2 children in Scope
/*11721*/       OPC_CheckPredicate, 38, // Predicate_azextload
/*11723*/       OPC_CheckPredicate, 42, // Predicate_azextloadi8
/*11725*/       OPC_MoveParent,
/*11726*/       OPC_CheckPredicate, 44, // Predicate_or_as_revinserti8
/*11728*/       OPC_CheckType, MVT::i64,
/*11730*/       OPC_CheckComplexPat, /*CP*/8, /*#*/2, // selectBDXAddr20Pair:$src2 #3 #4 #5
/*11733*/       OPC_EmitMergeInputChains1_1,
/*11734*/       OPC_MorphNodeTo, TARGET_VAL(SystemZ::ICY), 0|OPFL_Chain|OPFL_MemRefs,
                    1/*#VTs*/, MVT::i64, 4/*#Ops*/, 0, 3, 4, 5, 
                // Src: (or:i64 GR64:i64:$src1, (ld:i64 bdxaddr20pair:i64:$src2)<<P:Predicate_unindexedload>><<P:Predicate_azextload>><<P:Predicate_azextloadi8>>)<<P:Predicate_or_as_revinserti8>> - Complexity = 20
                // Dst: (ICY:i64 GR64:i64:$src1, bdxaddr20pair:i64:$src2)
/*11745*/     /*Scope*/ 61, /*->11807*/
/*11746*/       OPC_CheckPredicate, 13, // Predicate_load
/*11748*/       OPC_MoveParent,
/*11749*/       OPC_SwitchType /*2 cases */, 36,  MVT::i32,// ->11788
/*11752*/         OPC_Scope, 16, /*->11770*/ // 2 children in Scope
/*11754*/           OPC_CheckComplexPat, /*CP*/7, /*#*/2, // selectBDXAddr12Pair:$XBD2 #3 #4 #5
/*11757*/           OPC_EmitMergeInputChains1_1,
/*11758*/           OPC_MorphNodeTo, TARGET_VAL(SystemZ::O), 0|OPFL_Chain|OPFL_MemRefs,
                        2/*#VTs*/, MVT::i32, MVT::i32, 4/*#Ops*/, 0, 3, 4, 5, 
                    // Src: (or:i32 GR32:i32:$R1src, (ld:i32 bdxaddr12pair:i64:$XBD2)<<P:Predicate_unindexedload>><<P:Predicate_load>>) - Complexity = 19
                    // Dst: (O:i32:i32 GR32:i32:$R1src, bdxaddr12pair:i64:$XBD2)
/*11770*/         /*Scope*/ 16, /*->11787*/
/*11771*/           OPC_CheckComplexPat, /*CP*/8, /*#*/2, // selectBDXAddr20Pair:$XBD2 #3 #4 #5
/*11774*/           OPC_EmitMergeInputChains1_1,
/*11775*/           OPC_MorphNodeTo, TARGET_VAL(SystemZ::OY), 0|OPFL_Chain|OPFL_MemRefs,
                        2/*#VTs*/, MVT::i32, MVT::i32, 4/*#Ops*/, 0, 3, 4, 5, 
                    // Src: (or:i32 GR32:i32:$R1src, (ld:i32 bdxaddr20pair:i64:$XBD2)<<P:Predicate_unindexedload>><<P:Predicate_load>>) - Complexity = 19
                    // Dst: (OY:i32:i32 GR32:i32:$R1src, bdxaddr20pair:i64:$XBD2)
/*11787*/         0, /*End of Scope*/
/*11788*/       /*SwitchType*/ 16,  MVT::i64,// ->11806
/*11790*/         OPC_CheckComplexPat, /*CP*/0, /*#*/2, // selectBDXAddr20Only:$XBD2 #3 #4 #5
/*11793*/         OPC_EmitMergeInputChains1_1,
/*11794*/         OPC_MorphNodeTo, TARGET_VAL(SystemZ::OG), 0|OPFL_Chain|OPFL_MemRefs,
                      2/*#VTs*/, MVT::i64, MVT::i32, 4/*#Ops*/, 0, 3, 4, 5, 
                  // Src: (or:i64 GR64:i64:$R1src, (ld:i64 bdxaddr20only:i64:$XBD2)<<P:Predicate_unindexedload>><<P:Predicate_load>>) - Complexity = 19
                  // Dst: (OG:i64:i32 GR64:i64:$R1src, bdxaddr20only:i64:$XBD2)
/*11806*/       0, // EndSwitchType
/*11807*/     0, /*End of Scope*/
/*11808*/   /*Scope*/ 30|128,4/*542*/, /*->12352*/
/*11810*/     OPC_MoveChild, 0,
/*11812*/     OPC_Scope, 73, /*->11887*/ // 13 children in Scope
/*11814*/       OPC_CheckOpcode, TARGET_VAL(ISD::LOAD),
/*11817*/       OPC_RecordMemRef,
/*11818*/       OPC_RecordNode, // #0 = 'ld' chained node
/*11819*/       OPC_CheckFoldableChainNode,
/*11820*/       OPC_RecordChild1, // #1 = $XBD2
/*11821*/       OPC_CheckChild1Type, MVT::i64,
/*11823*/       OPC_CheckPredicate, 0, // Predicate_unindexedload
/*11825*/       OPC_CheckPredicate, 13, // Predicate_load
/*11827*/       OPC_MoveParent,
/*11828*/       OPC_RecordChild1, // #2 = $R1src
/*11829*/       OPC_SwitchType /*2 cases */, 36,  MVT::i32,// ->11868
/*11832*/         OPC_Scope, 16, /*->11850*/ // 2 children in Scope
/*11834*/           OPC_CheckComplexPat, /*CP*/7, /*#*/1, // selectBDXAddr12Pair:$XBD2 #3 #4 #5
/*11837*/           OPC_EmitMergeInputChains1_0,
/*11838*/           OPC_MorphNodeTo, TARGET_VAL(SystemZ::O), 0|OPFL_Chain|OPFL_MemRefs,
                        2/*#VTs*/, MVT::i32, MVT::i32, 4/*#Ops*/, 2, 3, 4, 5, 
                    // Src: (or:i32 (ld:i32 bdxaddr12pair:i64:$XBD2)<<P:Predicate_unindexedload>><<P:Predicate_load>>, GR32:i32:$R1src) - Complexity = 19
                    // Dst: (O:i32:i32 GR32:i32:$R1src, bdxaddr12pair:i64:$XBD2)
/*11850*/         /*Scope*/ 16, /*->11867*/
/*11851*/           OPC_CheckComplexPat, /*CP*/8, /*#*/1, // selectBDXAddr20Pair:$XBD2 #3 #4 #5
/*11854*/           OPC_EmitMergeInputChains1_0,
/*11855*/           OPC_MorphNodeTo, TARGET_VAL(SystemZ::OY), 0|OPFL_Chain|OPFL_MemRefs,
                        2/*#VTs*/, MVT::i32, MVT::i32, 4/*#Ops*/, 2, 3, 4, 5, 
                    // Src: (or:i32 (ld:i32 bdxaddr20pair:i64:$XBD2)<<P:Predicate_unindexedload>><<P:Predicate_load>>, GR32:i32:$R1src) - Complexity = 19
                    // Dst: (OY:i32:i32 GR32:i32:$R1src, bdxaddr20pair:i64:$XBD2)
/*11867*/         0, /*End of Scope*/
/*11868*/       /*SwitchType*/ 16,  MVT::i64,// ->11886
/*11870*/         OPC_CheckComplexPat, /*CP*/0, /*#*/1, // selectBDXAddr20Only:$XBD2 #3 #4 #5
/*11873*/         OPC_EmitMergeInputChains1_0,
/*11874*/         OPC_MorphNodeTo, TARGET_VAL(SystemZ::OG), 0|OPFL_Chain|OPFL_MemRefs,
                      2/*#VTs*/, MVT::i64, MVT::i32, 4/*#Ops*/, 2, 3, 4, 5, 
                  // Src: (or:i64 (ld:i64 bdxaddr20only:i64:$XBD2)<<P:Predicate_unindexedload>><<P:Predicate_load>>, GR64:i64:$R1src) - Complexity = 19
                  // Dst: (OG:i64:i32 GR64:i64:$R1src, bdxaddr20only:i64:$XBD2)
/*11886*/       0, // EndSwitchType
/*11887*/     /*Scope*/ 40, /*->11928*/
/*11888*/       OPC_CheckAndImm, 0|128,0|128,124|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709486080*/, 
/*11899*/       OPC_RecordChild0, // #0 = $R1src
/*11900*/       OPC_MoveParent,
/*11901*/       OPC_RecordChild1, // #1 = $I2
/*11902*/       OPC_MoveChild, 1,
/*11904*/       OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*11907*/       OPC_CheckPredicate, 45, // Predicate_imm32ll16
/*11909*/       OPC_MoveParent,
/*11910*/       OPC_CheckType, MVT::i32,
/*11912*/       OPC_CheckPatternPredicate, 0, // (Subtarget.hasHighWord())
/*11914*/       OPC_EmitConvertToTarget, 1,
/*11916*/       OPC_EmitNodeXForm, 6, 2, // LL16
/*11919*/       OPC_MorphNodeTo, TARGET_VAL(SystemZ::IILMux), 0,
                    1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 3, 
                // Src: (or:i32 (and:i32 GRX32:i32:$R1src, -65536:i32), (imm:i32)<<P:Predicate_imm32ll16>><<X:LL16>>:$I2) - Complexity = 15
                // Dst: (IILMux:i32 GRX32:i32:$R1src, (LL16:i32 (imm:i32):$I2))
/*11928*/     /*Scope*/ 40, /*->11969*/
/*11929*/       OPC_CheckAndImm, 127|128,127|128,3|128,0|128,112|128,127|128,127|128,127|128,127|128,1/*18446744069414649855*/, 
/*11940*/       OPC_RecordChild0, // #0 = $R1src
/*11941*/       OPC_MoveParent,
/*11942*/       OPC_RecordChild1, // #1 = $I2
/*11943*/       OPC_MoveChild, 1,
/*11945*/       OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*11948*/       OPC_CheckPredicate, 46, // Predicate_imm32lh16
/*11950*/       OPC_MoveParent,
/*11951*/       OPC_CheckType, MVT::i32,
/*11953*/       OPC_CheckPatternPredicate, 0, // (Subtarget.hasHighWord())
/*11955*/       OPC_EmitConvertToTarget, 1,
/*11957*/       OPC_EmitNodeXForm, 7, 2, // LH16
/*11960*/       OPC_MorphNodeTo, TARGET_VAL(SystemZ::IIHMux), 0,
                    1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 3, 
                // Src: (or:i32 (and:i32 GRX32:i32:$R1src, -4294901761:i32), (imm:i32)<<P:Predicate_imm32lh16>><<X:LH16>>:$I2) - Complexity = 15
                // Dst: (IIHMux:i32 GRX32:i32:$R1src, (LH16:i32 (imm:i32):$I2))
/*11969*/     /*Scope*/ 38, /*->12008*/
/*11970*/       OPC_CheckAndImm, 0|128,0|128,124|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709486080*/, 
/*11981*/       OPC_RecordChild0, // #0 = $R1src
/*11982*/       OPC_MoveParent,
/*11983*/       OPC_RecordChild1, // #1 = $I2
/*11984*/       OPC_MoveChild, 1,
/*11986*/       OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*11989*/       OPC_CheckPredicate, 45, // Predicate_imm32ll16
/*11991*/       OPC_MoveParent,
/*11992*/       OPC_CheckType, MVT::i32,
/*11994*/       OPC_EmitConvertToTarget, 1,
/*11996*/       OPC_EmitNodeXForm, 6, 2, // LL16
/*11999*/       OPC_MorphNodeTo, TARGET_VAL(SystemZ::IILL), 0,
                    1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 3, 
                // Src: (or:i32 (and:i32 GR32:i32:$R1src, -65536:i32), (imm:i32)<<P:Predicate_imm32ll16>><<X:LL16>>:$I2) - Complexity = 15
                // Dst: (IILL:i32 GR32:i32:$R1src, (LL16:i32 (imm:i32):$I2))
/*12008*/     /*Scope*/ 38, /*->12047*/
/*12009*/       OPC_CheckAndImm, 127|128,127|128,3|128,0|128,112|128,127|128,127|128,127|128,127|128,1/*18446744069414649855*/, 
/*12020*/       OPC_RecordChild0, // #0 = $R1src
/*12021*/       OPC_MoveParent,
/*12022*/       OPC_RecordChild1, // #1 = $I2
/*12023*/       OPC_MoveChild, 1,
/*12025*/       OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*12028*/       OPC_CheckPredicate, 46, // Predicate_imm32lh16
/*12030*/       OPC_MoveParent,
/*12031*/       OPC_CheckType, MVT::i32,
/*12033*/       OPC_EmitConvertToTarget, 1,
/*12035*/       OPC_EmitNodeXForm, 7, 2, // LH16
/*12038*/       OPC_MorphNodeTo, TARGET_VAL(SystemZ::IILH), 0,
                    1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 3, 
                // Src: (or:i32 (and:i32 GR32:i32:$R1src, -4294901761:i32), (imm:i32)<<P:Predicate_imm32lh16>><<X:LH16>>:$I2) - Complexity = 15
                // Dst: (IILH:i32 GR32:i32:$R1src, (LH16:i32 (imm:i32):$I2))
/*12047*/     /*Scope*/ 38, /*->12086*/
/*12048*/       OPC_CheckAndImm, 0|128,0|128,124|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709486080*/, 
/*12059*/       OPC_RecordChild0, // #0 = $R1src
/*12060*/       OPC_MoveParent,
/*12061*/       OPC_RecordChild1, // #1 = $I2
/*12062*/       OPC_MoveChild, 1,
/*12064*/       OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*12067*/       OPC_CheckPredicate, 45, // Predicate_imm32ll16
/*12069*/       OPC_MoveParent,
/*12070*/       OPC_CheckType, MVT::i32,
/*12072*/       OPC_EmitConvertToTarget, 1,
/*12074*/       OPC_EmitNodeXForm, 6, 2, // LL16
/*12077*/       OPC_MorphNodeTo, TARGET_VAL(SystemZ::IIHL), 0,
                    1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 3, 
                // Src: (or:i32 (and:i32 GRH32:i32:$R1src, -65536:i32), (imm:i32)<<P:Predicate_imm32ll16>><<X:LL16>>:$I2) - Complexity = 15
                // Dst: (IIHL:i32 GRH32:i32:$R1src, (LL16:i32 (imm:i32):$I2))
/*12086*/     /*Scope*/ 38, /*->12125*/
/*12087*/       OPC_CheckAndImm, 127|128,127|128,3|128,0|128,112|128,127|128,127|128,127|128,127|128,1/*18446744069414649855*/, 
/*12098*/       OPC_RecordChild0, // #0 = $R1src
/*12099*/       OPC_MoveParent,
/*12100*/       OPC_RecordChild1, // #1 = $I2
/*12101*/       OPC_MoveChild, 1,
/*12103*/       OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*12106*/       OPC_CheckPredicate, 46, // Predicate_imm32lh16
/*12108*/       OPC_MoveParent,
/*12109*/       OPC_CheckType, MVT::i32,
/*12111*/       OPC_EmitConvertToTarget, 1,
/*12113*/       OPC_EmitNodeXForm, 7, 2, // LH16
/*12116*/       OPC_MorphNodeTo, TARGET_VAL(SystemZ::IIHH), 0,
                    1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 3, 
                // Src: (or:i32 (and:i32 GRH32:i32:$R1src, -4294901761:i32), (imm:i32)<<P:Predicate_imm32lh16>><<X:LH16>>:$I2) - Complexity = 15
                // Dst: (IIHH:i32 GRH32:i32:$R1src, (LH16:i32 (imm:i32):$I2))
/*12125*/     /*Scope*/ 38, /*->12164*/
/*12126*/       OPC_CheckAndImm, 0|128,0|128,124|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709486080*/, 
/*12137*/       OPC_RecordChild0, // #0 = $R1src
/*12138*/       OPC_MoveParent,
/*12139*/       OPC_RecordChild1, // #1 = $I2
/*12140*/       OPC_MoveChild, 1,
/*12142*/       OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*12145*/       OPC_CheckPredicate, 47, // Predicate_imm64ll16
/*12147*/       OPC_MoveParent,
/*12148*/       OPC_CheckType, MVT::i64,
/*12150*/       OPC_EmitConvertToTarget, 1,
/*12152*/       OPC_EmitNodeXForm, 6, 2, // LL16
/*12155*/       OPC_MorphNodeTo, TARGET_VAL(SystemZ::IILL64), 0,
                    1/*#VTs*/, MVT::i64, 2/*#Ops*/, 0, 3, 
                // Src: (or:i64 (and:i64 GR64:i64:$R1src, -65536:i64), (imm:i64)<<P:Predicate_imm64ll16>><<X:LL16>>:$I2) - Complexity = 15
                // Dst: (IILL64:i64 GR64:i64:$R1src, (LL16:i64 (imm:i64):$I2))
/*12164*/     /*Scope*/ 38, /*->12203*/
/*12165*/       OPC_CheckAndImm, 127|128,127|128,3|128,0|128,112|128,127|128,127|128,127|128,127|128,1/*18446744069414649855*/, 
/*12176*/       OPC_RecordChild0, // #0 = $R1src
/*12177*/       OPC_MoveParent,
/*12178*/       OPC_RecordChild1, // #1 = $I2
/*12179*/       OPC_MoveChild, 1,
/*12181*/       OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*12184*/       OPC_CheckPredicate, 48, // Predicate_imm64lh16
/*12186*/       OPC_MoveParent,
/*12187*/       OPC_CheckType, MVT::i64,
/*12189*/       OPC_EmitConvertToTarget, 1,
/*12191*/       OPC_EmitNodeXForm, 7, 2, // LH16
/*12194*/       OPC_MorphNodeTo, TARGET_VAL(SystemZ::IILH64), 0,
                    1/*#VTs*/, MVT::i64, 2/*#Ops*/, 0, 3, 
                // Src: (or:i64 (and:i64 GR64:i64:$R1src, -4294901761:i64), (imm:i64)<<P:Predicate_imm64lh16>><<X:LH16>>:$I2) - Complexity = 15
                // Dst: (IILH64:i64 GR64:i64:$R1src, (LH16:i64 (imm:i64):$I2))
/*12203*/     /*Scope*/ 38, /*->12242*/
/*12204*/       OPC_CheckAndImm, 127|128,127|128,127|128,127|128,15|128,0|128,64|128,127|128,127|128,1/*18446462603027808255*/, 
/*12215*/       OPC_RecordChild0, // #0 = $R1src
/*12216*/       OPC_MoveParent,
/*12217*/       OPC_RecordChild1, // #1 = $I2
/*12218*/       OPC_MoveChild, 1,
/*12220*/       OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*12223*/       OPC_CheckPredicate, 49, // Predicate_imm64hl16
/*12225*/       OPC_MoveParent,
/*12226*/       OPC_CheckType, MVT::i64,
/*12228*/       OPC_EmitConvertToTarget, 1,
/*12230*/       OPC_EmitNodeXForm, 8, 2, // HL16
/*12233*/       OPC_MorphNodeTo, TARGET_VAL(SystemZ::IIHL64), 0,
                    1/*#VTs*/, MVT::i64, 2/*#Ops*/, 0, 3, 
                // Src: (or:i64 (and:i64 GR64:i64:$R1src, -281470681743361:i64), (imm:i64)<<P:Predicate_imm64hl16>><<X:HL16>>:$I2) - Complexity = 15
                // Dst: (IIHL64:i64 GR64:i64:$R1src, (HL16:i64 (imm:i64):$I2))
/*12242*/     /*Scope*/ 35, /*->12278*/
/*12243*/       OPC_CheckAndImm, 127|128,127|128,127|128,127|128,127|128,127|128,63/*281474976710655*/, 
/*12251*/       OPC_RecordChild0, // #0 = $R1src
/*12252*/       OPC_MoveParent,
/*12253*/       OPC_RecordChild1, // #1 = $I2
/*12254*/       OPC_MoveChild, 1,
/*12256*/       OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*12259*/       OPC_CheckPredicate, 50, // Predicate_imm64hh16
/*12261*/       OPC_MoveParent,
/*12262*/       OPC_CheckType, MVT::i64,
/*12264*/       OPC_EmitConvertToTarget, 1,
/*12266*/       OPC_EmitNodeXForm, 9, 2, // HH16
/*12269*/       OPC_MorphNodeTo, TARGET_VAL(SystemZ::IIHH64), 0,
                    1/*#VTs*/, MVT::i64, 2/*#Ops*/, 0, 3, 
                // Src: (or:i64 (and:i64 GR64:i64:$R1src, 281474976710655:i64), (imm:i64)<<P:Predicate_imm64hh16>><<X:HH16>>:$I2) - Complexity = 15
                // Dst: (IIHH64:i64 GR64:i64:$R1src, (HH16:i64 (imm:i64):$I2))
/*12278*/     /*Scope*/ 38, /*->12317*/
/*12279*/       OPC_CheckAndImm, 0|128,0|128,0|128,0|128,112|128,127|128,127|128,127|128,127|128,1/*18446744069414584320*/, 
/*12290*/       OPC_RecordChild0, // #0 = $R1src
/*12291*/       OPC_MoveParent,
/*12292*/       OPC_RecordChild1, // #1 = $I2
/*12293*/       OPC_MoveChild, 1,
/*12295*/       OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*12298*/       OPC_CheckPredicate, 40, // Predicate_imm64lf32
/*12300*/       OPC_MoveParent,
/*12301*/       OPC_CheckType, MVT::i64,
/*12303*/       OPC_EmitConvertToTarget, 1,
/*12305*/       OPC_EmitNodeXForm, 3, 2, // LF32
/*12308*/       OPC_MorphNodeTo, TARGET_VAL(SystemZ::IILF64), 0,
                    1/*#VTs*/, MVT::i64, 2/*#Ops*/, 0, 3, 
                // Src: (or:i64 (and:i64 GR64:i64:$R1src, -4294967296:i64), (imm:i64)<<P:Predicate_imm64lf32>><<X:LF32>>:$I2) - Complexity = 15
                // Dst: (IILF64:i64 GR64:i64:$R1src, (LF32:i64 (imm:i64):$I2))
/*12317*/     /*Scope*/ 33, /*->12351*/
/*12318*/       OPC_CheckAndImm, 127|128,127|128,127|128,127|128,15/*4294967295*/, 
/*12324*/       OPC_RecordChild0, // #0 = $R1src
/*12325*/       OPC_MoveParent,
/*12326*/       OPC_RecordChild1, // #1 = $I2
/*12327*/       OPC_MoveChild, 1,
/*12329*/       OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*12332*/       OPC_CheckPredicate, 41, // Predicate_imm64hf32
/*12334*/       OPC_MoveParent,
/*12335*/       OPC_CheckType, MVT::i64,
/*12337*/       OPC_EmitConvertToTarget, 1,
/*12339*/       OPC_EmitNodeXForm, 4, 2, // HF32
/*12342*/       OPC_MorphNodeTo, TARGET_VAL(SystemZ::IIHF64), 0,
                    1/*#VTs*/, MVT::i64, 2/*#Ops*/, 0, 3, 
                // Src: (or:i64 (and:i64 GR64:i64:$R1src, 4294967295:i64), (imm:i64)<<P:Predicate_imm64hf32>><<X:HF32>>:$I2) - Complexity = 15
                // Dst: (IIHF64:i64 GR64:i64:$R1src, (HF32:i64 (imm:i64):$I2))
/*12351*/     0, /*End of Scope*/
/*12352*/   /*Scope*/ 47, /*->12400*/
/*12353*/     OPC_RecordNode, // #0 = $src
/*12354*/     OPC_CheckType, MVT::i64,
/*12356*/     OPC_Scope, 13, /*->12371*/ // 3 children in Scope
/*12358*/       OPC_CheckComplexPat, /*CP*/13, /*#*/0, // selectDynAlloc12Only:$src #1 #2 #3
/*12361*/       OPC_MorphNodeTo, TARGET_VAL(SystemZ::ADJDYNALLOC), 0,
                    1/*#VTs*/, MVT::i64, 3/*#Ops*/, 1, 2, 3, 
                // Src: dynalloc12only:i64:$src - Complexity = 12
                // Dst: (ADJDYNALLOC:i64 dynalloc12only:i64:$src)
/*12371*/     /*Scope*/ 13, /*->12385*/
/*12372*/       OPC_CheckComplexPat, /*CP*/14, /*#*/0, // selectLAAddr12Pair:$XBD2 #1 #2 #3
/*12375*/       OPC_MorphNodeTo, TARGET_VAL(SystemZ::LA), 0,
                    1/*#VTs*/, MVT::i64, 3/*#Ops*/, 1, 2, 3, 
                // Src: laaddr12pair:i64:$XBD2 - Complexity = 12
                // Dst: (LA:i64 laaddr12pair:i64:$XBD2)
/*12385*/     /*Scope*/ 13, /*->12399*/
/*12386*/       OPC_CheckComplexPat, /*CP*/15, /*#*/0, // selectLAAddr20Pair:$XBD2 #1 #2 #3
/*12389*/       OPC_MorphNodeTo, TARGET_VAL(SystemZ::LAY), 0,
                    1/*#VTs*/, MVT::i64, 3/*#Ops*/, 1, 2, 3, 
                // Src: laaddr20pair:i64:$XBD2 - Complexity = 12
                // Dst: (LAY:i64 laaddr20pair:i64:$XBD2)
/*12399*/     0, /*End of Scope*/
/*12400*/   /*Scope*/ 50, /*->12451*/
/*12401*/     OPC_MoveChild, 0,
/*12403*/     OPC_CheckOpcode, TARGET_VAL(ISD::ZERO_EXTEND),
/*12406*/     OPC_RecordChild0, // #0 = $src
/*12407*/     OPC_MoveParent,
/*12408*/     OPC_RecordChild1, // #1 = $imm
/*12409*/     OPC_MoveChild, 1,
/*12411*/     OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*12414*/     OPC_CheckPredicate, 41, // Predicate_imm64hf32
/*12416*/     OPC_MoveParent,
/*12417*/     OPC_EmitNode, TARGET_VAL(TargetOpcode::IMPLICIT_DEF), 0,
                  1/*#VTs*/, MVT::i64, 0/*#Ops*/,  // Results = #2
/*12424*/     OPC_EmitInteger, MVT::i32, SystemZ::subreg_l32,
/*12427*/     OPC_EmitNode, TARGET_VAL(TargetOpcode::INSERT_SUBREG), 0,
                  1/*#VTs*/, MVT::i64, 3/*#Ops*/, 2, 0, 3,  // Results = #4
/*12437*/     OPC_EmitConvertToTarget, 1,
/*12439*/     OPC_EmitNodeXForm, 4, 5, // HF32
/*12442*/     OPC_MorphNodeTo, TARGET_VAL(SystemZ::IIHF64), 0,
                  1/*#VTs*/, MVT::i64, 2/*#Ops*/, 4, 6, 
              // Src: (or:i64 (zext:i64 GR32:i32:$src), (imm:i64)<<P:Predicate_imm64hf32>><<X:HF32>>:$imm) - Complexity = 10
              // Dst: (IIHF64:i64 (INSERT_SUBREG:i64 (IMPLICIT_DEF:i64), GR32:i32:$src, subreg_l32:i32), (HF32:i64 (imm:i64)<<P:Predicate_imm64hf32>>:$imm))
/*12451*/   /*Scope*/ 93|128,2/*349*/, /*->12802*/
/*12453*/     OPC_RecordChild0, // #0 = $R1src
/*12454*/     OPC_RecordChild1, // #1 = $I2
/*12455*/     OPC_Scope, 61|128,2/*317*/, /*->12775*/ // 3 children in Scope
/*12458*/       OPC_MoveChild, 1,
/*12460*/       OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*12463*/       OPC_Scope, 22, /*->12487*/ // 13 children in Scope
/*12465*/         OPC_CheckPredicate, 45, // Predicate_imm32ll16
/*12467*/         OPC_MoveParent,
/*12468*/         OPC_CheckType, MVT::i32,
/*12470*/         OPC_CheckPatternPredicate, 0, // (Subtarget.hasHighWord())
/*12472*/         OPC_EmitConvertToTarget, 1,
/*12474*/         OPC_EmitNodeXForm, 6, 2, // LL16
/*12477*/         OPC_MorphNodeTo, TARGET_VAL(SystemZ::OILMux), 0,
                      2/*#VTs*/, MVT::i32, MVT::i32, 2/*#Ops*/, 0, 3, 
                  // Src: (or:i32 GRX32:i32:$R1src, (imm:i32)<<P:Predicate_imm32ll16>><<X:LL16>>:$I2) - Complexity = 7
                  // Dst: (OILMux:i32:i32 GRX32:i32:$R1src, (LL16:i32 (imm:i32):$I2))
/*12487*/       /*Scope*/ 22, /*->12510*/
/*12488*/         OPC_CheckPredicate, 46, // Predicate_imm32lh16
/*12490*/         OPC_MoveParent,
/*12491*/         OPC_CheckType, MVT::i32,
/*12493*/         OPC_CheckPatternPredicate, 0, // (Subtarget.hasHighWord())
/*12495*/         OPC_EmitConvertToTarget, 1,
/*12497*/         OPC_EmitNodeXForm, 7, 2, // LH16
/*12500*/         OPC_MorphNodeTo, TARGET_VAL(SystemZ::OIHMux), 0,
                      2/*#VTs*/, MVT::i32, MVT::i32, 2/*#Ops*/, 0, 3, 
                  // Src: (or:i32 GRX32:i32:$R1src, (imm:i32)<<P:Predicate_imm32lh16>><<X:LH16>>:$I2) - Complexity = 7
                  // Dst: (OIHMux:i32:i32 GRX32:i32:$R1src, (LH16:i32 (imm:i32):$I2))
/*12510*/       /*Scope*/ 20, /*->12531*/
/*12511*/         OPC_CheckPredicate, 45, // Predicate_imm32ll16
/*12513*/         OPC_MoveParent,
/*12514*/         OPC_CheckType, MVT::i32,
/*12516*/         OPC_EmitConvertToTarget, 1,
/*12518*/         OPC_EmitNodeXForm, 6, 2, // LL16
/*12521*/         OPC_MorphNodeTo, TARGET_VAL(SystemZ::OILL), 0,
                      2/*#VTs*/, MVT::i32, MVT::i32, 2/*#Ops*/, 0, 3, 
                  // Src: (or:i32 GR32:i32:$R1src, (imm:i32)<<P:Predicate_imm32ll16>><<X:LL16>>:$I2) - Complexity = 7
                  // Dst: (OILL:i32:i32 GR32:i32:$R1src, (LL16:i32 (imm:i32):$I2))
/*12531*/       /*Scope*/ 20, /*->12552*/
/*12532*/         OPC_CheckPredicate, 46, // Predicate_imm32lh16
/*12534*/         OPC_MoveParent,
/*12535*/         OPC_CheckType, MVT::i32,
/*12537*/         OPC_EmitConvertToTarget, 1,
/*12539*/         OPC_EmitNodeXForm, 7, 2, // LH16
/*12542*/         OPC_MorphNodeTo, TARGET_VAL(SystemZ::OILH), 0,
                      2/*#VTs*/, MVT::i32, MVT::i32, 2/*#Ops*/, 0, 3, 
                  // Src: (or:i32 GR32:i32:$R1src, (imm:i32)<<P:Predicate_imm32lh16>><<X:LH16>>:$I2) - Complexity = 7
                  // Dst: (OILH:i32:i32 GR32:i32:$R1src, (LH16:i32 (imm:i32):$I2))
/*12552*/       /*Scope*/ 20, /*->12573*/
/*12553*/         OPC_CheckPredicate, 45, // Predicate_imm32ll16
/*12555*/         OPC_MoveParent,
/*12556*/         OPC_CheckType, MVT::i32,
/*12558*/         OPC_EmitConvertToTarget, 1,
/*12560*/         OPC_EmitNodeXForm, 6, 2, // LL16
/*12563*/         OPC_MorphNodeTo, TARGET_VAL(SystemZ::OIHL), 0,
                      2/*#VTs*/, MVT::i32, MVT::i32, 2/*#Ops*/, 0, 3, 
                  // Src: (or:i32 GRH32:i32:$R1src, (imm:i32)<<P:Predicate_imm32ll16>><<X:LL16>>:$I2) - Complexity = 7
                  // Dst: (OIHL:i32:i32 GRH32:i32:$R1src, (LL16:i32 (imm:i32):$I2))
/*12573*/       /*Scope*/ 20, /*->12594*/
/*12574*/         OPC_CheckPredicate, 46, // Predicate_imm32lh16
/*12576*/         OPC_MoveParent,
/*12577*/         OPC_CheckType, MVT::i32,
/*12579*/         OPC_EmitConvertToTarget, 1,
/*12581*/         OPC_EmitNodeXForm, 7, 2, // LH16
/*12584*/         OPC_MorphNodeTo, TARGET_VAL(SystemZ::OIHH), 0,
                      2/*#VTs*/, MVT::i32, MVT::i32, 2/*#Ops*/, 0, 3, 
                  // Src: (or:i32 GRH32:i32:$R1src, (imm:i32)<<P:Predicate_imm32lh16>><<X:LH16>>:$I2) - Complexity = 7
                  // Dst: (OIHH:i32:i32 GRH32:i32:$R1src, (LH16:i32 (imm:i32):$I2))
/*12594*/       /*Scope*/ 20, /*->12615*/
/*12595*/         OPC_CheckPredicate, 47, // Predicate_imm64ll16
/*12597*/         OPC_MoveParent,
/*12598*/         OPC_CheckType, MVT::i64,
/*12600*/         OPC_EmitConvertToTarget, 1,
/*12602*/         OPC_EmitNodeXForm, 6, 2, // LL16
/*12605*/         OPC_MorphNodeTo, TARGET_VAL(SystemZ::OILL64), 0,
                      2/*#VTs*/, MVT::i64, MVT::i32, 2/*#Ops*/, 0, 3, 
                  // Src: (or:i64 GR64:i64:$R1src, (imm:i64)<<P:Predicate_imm64ll16>><<X:LL16>>:$I2) - Complexity = 7
                  // Dst: (OILL64:i64:i32 GR64:i64:$R1src, (LL16:i64 (imm:i64):$I2))
/*12615*/       /*Scope*/ 20, /*->12636*/
/*12616*/         OPC_CheckPredicate, 48, // Predicate_imm64lh16
/*12618*/         OPC_MoveParent,
/*12619*/         OPC_CheckType, MVT::i64,
/*12621*/         OPC_EmitConvertToTarget, 1,
/*12623*/         OPC_EmitNodeXForm, 7, 2, // LH16
/*12626*/         OPC_MorphNodeTo, TARGET_VAL(SystemZ::OILH64), 0,
                      2/*#VTs*/, MVT::i64, MVT::i32, 2/*#Ops*/, 0, 3, 
                  // Src: (or:i64 GR64:i64:$R1src, (imm:i64)<<P:Predicate_imm64lh16>><<X:LH16>>:$I2) - Complexity = 7
                  // Dst: (OILH64:i64:i32 GR64:i64:$R1src, (LH16:i64 (imm:i64):$I2))
/*12636*/       /*Scope*/ 20, /*->12657*/
/*12637*/         OPC_CheckPredicate, 49, // Predicate_imm64hl16
/*12639*/         OPC_MoveParent,
/*12640*/         OPC_CheckType, MVT::i64,
/*12642*/         OPC_EmitConvertToTarget, 1,
/*12644*/         OPC_EmitNodeXForm, 8, 2, // HL16
/*12647*/         OPC_MorphNodeTo, TARGET_VAL(SystemZ::OIHL64), 0,
                      2/*#VTs*/, MVT::i64, MVT::i32, 2/*#Ops*/, 0, 3, 
                  // Src: (or:i64 GR64:i64:$R1src, (imm:i64)<<P:Predicate_imm64hl16>><<X:HL16>>:$I2) - Complexity = 7
                  // Dst: (OIHL64:i64:i32 GR64:i64:$R1src, (HL16:i64 (imm:i64):$I2))
/*12657*/       /*Scope*/ 20, /*->12678*/
/*12658*/         OPC_CheckPredicate, 50, // Predicate_imm64hh16
/*12660*/         OPC_MoveParent,
/*12661*/         OPC_CheckType, MVT::i64,
/*12663*/         OPC_EmitConvertToTarget, 1,
/*12665*/         OPC_EmitNodeXForm, 9, 2, // HH16
/*12668*/         OPC_MorphNodeTo, TARGET_VAL(SystemZ::OIHH64), 0,
                      2/*#VTs*/, MVT::i64, MVT::i32, 2/*#Ops*/, 0, 3, 
                  // Src: (or:i64 GR64:i64:$R1src, (imm:i64)<<P:Predicate_imm64hh16>><<X:HH16>>:$I2) - Complexity = 7
                  // Dst: (OIHH64:i64:i32 GR64:i64:$R1src, (HH16:i64 (imm:i64):$I2))
/*12678*/       /*Scope*/ 20, /*->12699*/
/*12679*/         OPC_CheckPredicate, 40, // Predicate_imm64lf32
/*12681*/         OPC_MoveParent,
/*12682*/         OPC_CheckType, MVT::i64,
/*12684*/         OPC_EmitConvertToTarget, 1,
/*12686*/         OPC_EmitNodeXForm, 3, 2, // LF32
/*12689*/         OPC_MorphNodeTo, TARGET_VAL(SystemZ::OILF64), 0,
                      2/*#VTs*/, MVT::i64, MVT::i32, 2/*#Ops*/, 0, 3, 
                  // Src: (or:i64 GR64:i64:$R1src, (imm:i64)<<P:Predicate_imm64lf32>><<X:LF32>>:$I2) - Complexity = 7
                  // Dst: (OILF64:i64:i32 GR64:i64:$R1src, (LF32:i64 (imm:i64):$I2))
/*12699*/       /*Scope*/ 20, /*->12720*/
/*12700*/         OPC_CheckPredicate, 41, // Predicate_imm64hf32
/*12702*/         OPC_MoveParent,
/*12703*/         OPC_CheckType, MVT::i64,
/*12705*/         OPC_EmitConvertToTarget, 1,
/*12707*/         OPC_EmitNodeXForm, 4, 2, // HF32
/*12710*/         OPC_MorphNodeTo, TARGET_VAL(SystemZ::OIHF64), 0,
                      2/*#VTs*/, MVT::i64, MVT::i32, 2/*#Ops*/, 0, 3, 
                  // Src: (or:i64 GR64:i64:$R1src, (imm:i64)<<P:Predicate_imm64hf32>><<X:HF32>>:$I2) - Complexity = 7
                  // Dst: (OIHF64:i64:i32 GR64:i64:$R1src, (HF32:i64 (imm:i64):$I2))
/*12720*/       /*Scope*/ 53, /*->12774*/
/*12721*/         OPC_MoveParent,
/*12722*/         OPC_CheckType, MVT::i32,
/*12724*/         OPC_Scope, 17, /*->12743*/ // 2 children in Scope
/*12726*/           OPC_CheckPatternPredicate, 0, // (Subtarget.hasHighWord())
/*12728*/           OPC_EmitConvertToTarget, 1,
/*12730*/           OPC_EmitNodeXForm, 5, 2, // UIMM32
/*12733*/           OPC_MorphNodeTo, TARGET_VAL(SystemZ::OIFMux), 0,
                        2/*#VTs*/, MVT::i32, MVT::i32, 2/*#Ops*/, 0, 3, 
                    // Src: (or:i32 GRX32:i32:$R1src, (imm:i32)<<X:UIMM32>>:$I2) - Complexity = 6
                    // Dst: (OIFMux:i32:i32 GRX32:i32:$R1src, (UIMM32:i32 (imm:i32):$I2))
/*12743*/         /*Scope*/ 29, /*->12773*/
/*12744*/           OPC_EmitConvertToTarget, 1,
/*12746*/           OPC_EmitNodeXForm, 5, 2, // UIMM32
/*12749*/           OPC_Scope, 10, /*->12761*/ // 2 children in Scope
/*12751*/             OPC_MorphNodeTo, TARGET_VAL(SystemZ::OILF), 0,
                          2/*#VTs*/, MVT::i32, MVT::i32, 2/*#Ops*/, 0, 3, 
                      // Src: (or:i32 GR32:i32:$R1src, (imm:i32)<<X:UIMM32>>:$I2) - Complexity = 6
                      // Dst: (OILF:i32:i32 GR32:i32:$R1src, (UIMM32:i32 (imm:i32):$I2))
/*12761*/           /*Scope*/ 10, /*->12772*/
/*12762*/             OPC_MorphNodeTo, TARGET_VAL(SystemZ::OIHF), 0,
                          2/*#VTs*/, MVT::i32, MVT::i32, 2/*#Ops*/, 0, 3, 
                      // Src: (or:i32 GRH32:i32:$R1src, (imm:i32)<<X:UIMM32>>:$I2) - Complexity = 6
                      // Dst: (OIHF:i32:i32 GRH32:i32:$R1src, (UIMM32:i32 (imm:i32):$I2))
/*12772*/           0, /*End of Scope*/
/*12773*/         0, /*End of Scope*/
/*12774*/       0, /*End of Scope*/
/*12775*/     /*Scope*/ 12, /*->12788*/
/*12776*/       OPC_CheckType, MVT::i32,
/*12778*/       OPC_MorphNodeTo, TARGET_VAL(SystemZ::OR), 0,
                    2/*#VTs*/, MVT::i32, MVT::i32, 2/*#Ops*/, 0, 1, 
                // Src: (or:i32 GR32:i32:$R1src, GR32:i32:$R2) - Complexity = 3
                // Dst: (OR:i32:i32 GR32:i32:$R1src, GR32:i32:$R2)
/*12788*/     /*Scope*/ 12, /*->12801*/
/*12789*/       OPC_CheckType, MVT::i64,
/*12791*/       OPC_MorphNodeTo, TARGET_VAL(SystemZ::OGR), 0,
                    2/*#VTs*/, MVT::i64, MVT::i32, 2/*#Ops*/, 0, 1, 
                // Src: (or:i64 GR64:i64:$R1src, GR64:i64:$R2) - Complexity = 3
                // Dst: (OGR:i64:i32 GR64:i64:$R1src, GR64:i64:$R2)
/*12801*/     0, /*End of Scope*/
/*12802*/   0, /*End of Scope*/
/*12803*/ /*SwitchOpcode*/ 95|128,2/*351*/,  TARGET_VAL(SystemZISD::TM),// ->13158
/*12807*/   OPC_Scope, 76, /*->12885*/ // 2 children in Scope
/*12809*/     OPC_MoveChild, 0,
/*12811*/     OPC_CheckOpcode, TARGET_VAL(ISD::LOAD),
/*12814*/     OPC_RecordMemRef,
/*12815*/     OPC_RecordNode, // #0 = 'ld' chained node
/*12816*/     OPC_CheckFoldableChainNode,
/*12817*/     OPC_RecordChild1, // #1 = $BD1
/*12818*/     OPC_CheckChild1Type, MVT::i64,
/*12820*/     OPC_CheckPredicate, 0, // Predicate_unindexedload
/*12822*/     OPC_CheckPredicate, 1, // Predicate_anyextload
/*12824*/     OPC_CheckPredicate, 2, // Predicate_anyextloadi8
/*12826*/     OPC_CheckType, MVT::i32,
/*12828*/     OPC_MoveParent,
/*12829*/     OPC_RecordChild1, // #2 = $I2
/*12830*/     OPC_MoveChild, 1,
/*12832*/     OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*12835*/     OPC_CheckPredicate, 51, // Predicate_imm32zx8
/*12837*/     OPC_MoveParent,
/*12838*/     OPC_MoveChild, 2,
/*12840*/     OPC_CheckInteger, 0, 
/*12842*/     OPC_MoveParent,
/*12843*/     OPC_Scope, 19, /*->12864*/ // 2 children in Scope
/*12845*/       OPC_CheckComplexPat, /*CP*/2, /*#*/1, // selectBDAddr12Pair:$BD1 #3 #4
/*12848*/       OPC_EmitMergeInputChains1_0,
/*12849*/       OPC_EmitConvertToTarget, 2,
/*12851*/       OPC_EmitNodeXForm, 0, 5, // UIMM8
/*12854*/       OPC_MorphNodeTo, TARGET_VAL(SystemZ::TM), 0|OPFL_Chain|OPFL_GlueOutput|OPFL_MemRefs,
                    1/*#VTs*/, MVT::i32, 3/*#Ops*/, 3, 4, 6, 
                // Src: (z_tm (ld:i32 bdaddr12pair:i64:$BD1)<<P:Predicate_unindexedload>><<P:Predicate_anyextload>><<P:Predicate_anyextloadi8>>, (imm:i32)<<P:Predicate_imm32zx8>><<X:UIMM8>>:$I2, 0:i32) - Complexity = 25
                // Dst: (TM:i32 bdaddr12pair:i64:$BD1, (UIMM8:i32 (imm:i32):$I2))
/*12864*/     /*Scope*/ 19, /*->12884*/
/*12865*/       OPC_CheckComplexPat, /*CP*/3, /*#*/1, // selectBDAddr20Pair:$BD1 #3 #4
/*12868*/       OPC_EmitMergeInputChains1_0,
/*12869*/       OPC_EmitConvertToTarget, 2,
/*12871*/       OPC_EmitNodeXForm, 0, 5, // UIMM8
/*12874*/       OPC_MorphNodeTo, TARGET_VAL(SystemZ::TMY), 0|OPFL_Chain|OPFL_GlueOutput|OPFL_MemRefs,
                    1/*#VTs*/, MVT::i32, 3/*#Ops*/, 3, 4, 6, 
                // Src: (z_tm (ld:i32 bdaddr20pair:i64:$BD1)<<P:Predicate_unindexedload>><<P:Predicate_anyextload>><<P:Predicate_anyextloadi8>>, (imm:i32)<<P:Predicate_imm32zx8>><<X:UIMM8>>:$I2, 0:i32) - Complexity = 25
                // Dst: (TMY:i32 bdaddr20pair:i64:$BD1, (UIMM8:i32 (imm:i32):$I2))
/*12884*/     0, /*End of Scope*/
/*12885*/   /*Scope*/ 14|128,2/*270*/, /*->13157*/
/*12887*/     OPC_RecordChild0, // #0 = $R1
/*12888*/     OPC_Scope, 30|128,1/*158*/, /*->13049*/ // 2 children in Scope
/*12891*/       OPC_CheckChild0Type, MVT::i32,
/*12893*/       OPC_RecordChild1, // #1 = $I2
/*12894*/       OPC_MoveChild, 1,
/*12896*/       OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*12899*/       OPC_Scope, 25, /*->12926*/ // 6 children in Scope
/*12901*/         OPC_CheckPredicate, 45, // Predicate_imm32ll16
/*12903*/         OPC_MoveParent,
/*12904*/         OPC_MoveChild, 2,
/*12906*/         OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*12909*/         OPC_MoveParent,
/*12910*/         OPC_CheckPatternPredicate, 0, // (Subtarget.hasHighWord())
/*12912*/         OPC_EmitConvertToTarget, 1,
/*12914*/         OPC_EmitNodeXForm, 6, 2, // LL16
/*12917*/         OPC_MorphNodeTo, TARGET_VAL(SystemZ::TMLMux), 0|OPFL_GlueOutput,
                      1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 3, 
                  // Src: (z_tm GRX32:i32:$R1, (imm:i32)<<P:Predicate_imm32ll16>><<X:LL16>>:$I2, (imm:i32)) - Complexity = 10
                  // Dst: (TMLMux:i32 GRX32:i32:$R1, (LL16:i32 (imm:i32):$I2))
/*12926*/       /*Scope*/ 25, /*->12952*/
/*12927*/         OPC_CheckPredicate, 46, // Predicate_imm32lh16
/*12929*/         OPC_MoveParent,
/*12930*/         OPC_MoveChild, 2,
/*12932*/         OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*12935*/         OPC_MoveParent,
/*12936*/         OPC_CheckPatternPredicate, 0, // (Subtarget.hasHighWord())
/*12938*/         OPC_EmitConvertToTarget, 1,
/*12940*/         OPC_EmitNodeXForm, 7, 2, // LH16
/*12943*/         OPC_MorphNodeTo, TARGET_VAL(SystemZ::TMHMux), 0|OPFL_GlueOutput,
                      1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 3, 
                  // Src: (z_tm GRX32:i32:$R1, (imm:i32)<<P:Predicate_imm32lh16>><<X:LH16>>:$I2, (imm:i32)) - Complexity = 10
                  // Dst: (TMHMux:i32 GRX32:i32:$R1, (LH16:i32 (imm:i32):$I2))
/*12952*/       /*Scope*/ 23, /*->12976*/
/*12953*/         OPC_CheckPredicate, 45, // Predicate_imm32ll16
/*12955*/         OPC_MoveParent,
/*12956*/         OPC_MoveChild, 2,
/*12958*/         OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*12961*/         OPC_MoveParent,
/*12962*/         OPC_EmitConvertToTarget, 1,
/*12964*/         OPC_EmitNodeXForm, 6, 2, // LL16
/*12967*/         OPC_MorphNodeTo, TARGET_VAL(SystemZ::TMLL), 0|OPFL_GlueOutput,
                      1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 3, 
                  // Src: (z_tm GR32:i32:$R1, (imm:i32)<<P:Predicate_imm32ll16>><<X:LL16>>:$I2, (imm:i32)) - Complexity = 10
                  // Dst: (TMLL:i32 GR32:i32:$R1, (LL16:i32 (imm:i32):$I2))
/*12976*/       /*Scope*/ 23, /*->13000*/
/*12977*/         OPC_CheckPredicate, 46, // Predicate_imm32lh16
/*12979*/         OPC_MoveParent,
/*12980*/         OPC_MoveChild, 2,
/*12982*/         OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*12985*/         OPC_MoveParent,
/*12986*/         OPC_EmitConvertToTarget, 1,
/*12988*/         OPC_EmitNodeXForm, 7, 2, // LH16
/*12991*/         OPC_MorphNodeTo, TARGET_VAL(SystemZ::TMLH), 0|OPFL_GlueOutput,
                      1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 3, 
                  // Src: (z_tm GR32:i32:$R1, (imm:i32)<<P:Predicate_imm32lh16>><<X:LH16>>:$I2, (imm:i32)) - Complexity = 10
                  // Dst: (TMLH:i32 GR32:i32:$R1, (LH16:i32 (imm:i32):$I2))
/*13000*/       /*Scope*/ 23, /*->13024*/
/*13001*/         OPC_CheckPredicate, 45, // Predicate_imm32ll16
/*13003*/         OPC_MoveParent,
/*13004*/         OPC_MoveChild, 2,
/*13006*/         OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*13009*/         OPC_MoveParent,
/*13010*/         OPC_EmitConvertToTarget, 1,
/*13012*/         OPC_EmitNodeXForm, 6, 2, // LL16
/*13015*/         OPC_MorphNodeTo, TARGET_VAL(SystemZ::TMHL), 0|OPFL_GlueOutput,
                      1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 3, 
                  // Src: (z_tm GRH32:i32:$R1, (imm:i32)<<P:Predicate_imm32ll16>><<X:LL16>>:$I2, (imm:i32)) - Complexity = 10
                  // Dst: (TMHL:i32 GRH32:i32:$R1, (LL16:i32 (imm:i32):$I2))
/*13024*/       /*Scope*/ 23, /*->13048*/
/*13025*/         OPC_CheckPredicate, 46, // Predicate_imm32lh16
/*13027*/         OPC_MoveParent,
/*13028*/         OPC_MoveChild, 2,
/*13030*/         OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*13033*/         OPC_MoveParent,
/*13034*/         OPC_EmitConvertToTarget, 1,
/*13036*/         OPC_EmitNodeXForm, 7, 2, // LH16
/*13039*/         OPC_MorphNodeTo, TARGET_VAL(SystemZ::TMHH), 0|OPFL_GlueOutput,
                      1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 3, 
                  // Src: (z_tm GRH32:i32:$R1, (imm:i32)<<P:Predicate_imm32lh16>><<X:LH16>>:$I2, (imm:i32)) - Complexity = 10
                  // Dst: (TMHH:i32 GRH32:i32:$R1, (LH16:i32 (imm:i32):$I2))
/*13048*/       0, /*End of Scope*/
/*13049*/     /*Scope*/ 106, /*->13156*/
/*13050*/       OPC_CheckChild0Type, MVT::i64,
/*13052*/       OPC_RecordChild1, // #1 = $I2
/*13053*/       OPC_MoveChild, 1,
/*13055*/       OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*13058*/       OPC_Scope, 23, /*->13083*/ // 4 children in Scope
/*13060*/         OPC_CheckPredicate, 47, // Predicate_imm64ll16
/*13062*/         OPC_MoveParent,
/*13063*/         OPC_MoveChild, 2,
/*13065*/         OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*13068*/         OPC_MoveParent,
/*13069*/         OPC_EmitConvertToTarget, 1,
/*13071*/         OPC_EmitNodeXForm, 6, 2, // LL16
/*13074*/         OPC_MorphNodeTo, TARGET_VAL(SystemZ::TMLL64), 0|OPFL_GlueOutput,
                      1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 3, 
                  // Src: (z_tm GR64:i64:$R1, (imm:i64)<<P:Predicate_imm64ll16>><<X:LL16>>:$I2, (imm:i32)) - Complexity = 10
                  // Dst: (TMLL64:i32 GR64:i64:$R1, (LL16:i64 (imm:i64):$I2))
/*13083*/       /*Scope*/ 23, /*->13107*/
/*13084*/         OPC_CheckPredicate, 48, // Predicate_imm64lh16
/*13086*/         OPC_MoveParent,
/*13087*/         OPC_MoveChild, 2,
/*13089*/         OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*13092*/         OPC_MoveParent,
/*13093*/         OPC_EmitConvertToTarget, 1,
/*13095*/         OPC_EmitNodeXForm, 7, 2, // LH16
/*13098*/         OPC_MorphNodeTo, TARGET_VAL(SystemZ::TMLH64), 0|OPFL_GlueOutput,
                      1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 3, 
                  // Src: (z_tm GR64:i64:$R1, (imm:i64)<<P:Predicate_imm64lh16>><<X:LH16>>:$I2, (imm:i32)) - Complexity = 10
                  // Dst: (TMLH64:i32 GR64:i64:$R1, (LH16:i64 (imm:i64):$I2))
/*13107*/       /*Scope*/ 23, /*->13131*/
/*13108*/         OPC_CheckPredicate, 49, // Predicate_imm64hl16
/*13110*/         OPC_MoveParent,
/*13111*/         OPC_MoveChild, 2,
/*13113*/         OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*13116*/         OPC_MoveParent,
/*13117*/         OPC_EmitConvertToTarget, 1,
/*13119*/         OPC_EmitNodeXForm, 8, 2, // HL16
/*13122*/         OPC_MorphNodeTo, TARGET_VAL(SystemZ::TMHL64), 0|OPFL_GlueOutput,
                      1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 3, 
                  // Src: (z_tm GR64:i64:$R1, (imm:i64)<<P:Predicate_imm64hl16>><<X:HL16>>:$I2, (imm:i32)) - Complexity = 10
                  // Dst: (TMHL64:i32 GR64:i64:$R1, (HL16:i64 (imm:i64):$I2))
/*13131*/       /*Scope*/ 23, /*->13155*/
/*13132*/         OPC_CheckPredicate, 50, // Predicate_imm64hh16
/*13134*/         OPC_MoveParent,
/*13135*/         OPC_MoveChild, 2,
/*13137*/         OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*13140*/         OPC_MoveParent,
/*13141*/         OPC_EmitConvertToTarget, 1,
/*13143*/         OPC_EmitNodeXForm, 9, 2, // HH16
/*13146*/         OPC_MorphNodeTo, TARGET_VAL(SystemZ::TMHH64), 0|OPFL_GlueOutput,
                      1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 3, 
                  // Src: (z_tm GR64:i64:$R1, (imm:i64)<<P:Predicate_imm64hh16>><<X:HH16>>:$I2, (imm:i32)) - Complexity = 10
                  // Dst: (TMHH64:i32 GR64:i64:$R1, (HH16:i64 (imm:i64):$I2))
/*13155*/       0, /*End of Scope*/
/*13156*/     0, /*End of Scope*/
/*13157*/   0, /*End of Scope*/
/*13158*/ /*SwitchOpcode*/ 97|128,1/*225*/,  TARGET_VAL(SystemZISD::SELECT_CCMASK),// ->13387
/*13162*/   OPC_CaptureGlueInput,
/*13163*/   OPC_Scope, 85, /*->13250*/ // 2 children in Scope
/*13165*/     OPC_MoveChild, 0,
/*13167*/     OPC_CheckOpcode, TARGET_VAL(ISD::LOAD),
/*13170*/     OPC_RecordMemRef,
/*13171*/     OPC_RecordNode, // #0 = 'ld' chained node
/*13172*/     OPC_CheckFoldableChainNode,
/*13173*/     OPC_RecordChild1, // #1 = $BD2
/*13174*/     OPC_CheckChild1Type, MVT::i64,
/*13176*/     OPC_CheckPredicate, 0, // Predicate_unindexedload
/*13178*/     OPC_CheckPredicate, 13, // Predicate_load
/*13180*/     OPC_MoveParent,
/*13181*/     OPC_RecordChild1, // #2 = $R1src
/*13182*/     OPC_RecordChild2, // #3 = $valid
/*13183*/     OPC_MoveChild, 2,
/*13185*/     OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*13188*/     OPC_CheckPredicate, 52, // Predicate_cond4
/*13190*/     OPC_MoveParent,
/*13191*/     OPC_RecordChild3, // #4 = $R3
/*13192*/     OPC_MoveChild, 3,
/*13194*/     OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*13197*/     OPC_CheckPredicate, 52, // Predicate_cond4
/*13199*/     OPC_MoveParent,
/*13200*/     OPC_SwitchType /*2 cases */, 22,  MVT::i32,// ->13225
/*13203*/       OPC_CheckPatternPredicate, 1, // (Subtarget.hasLoadStoreOnCond())
/*13205*/       OPC_CheckComplexPat, /*CP*/4, /*#*/1, // selectBDAddr20Only:$BD2 #5 #6
/*13208*/       OPC_EmitMergeInputChains1_0,
/*13209*/       OPC_EmitConvertToTarget, 3,
/*13211*/       OPC_EmitConvertToTarget, 4,
/*13213*/       OPC_MorphNodeTo, TARGET_VAL(SystemZ::LOC), 0|OPFL_Chain|OPFL_GlueInput|OPFL_MemRefs,
                    1/*#VTs*/, MVT::i32, 5/*#Ops*/, 2, 5, 6, 7, 8, 
                // Src: (z_select_ccmask:i32 (ld:i32 bdaddr20only:i64:$BD2)<<P:Predicate_unindexedload>><<P:Predicate_load>>, GR32:i32:$R1src, (imm:i8)<<P:Predicate_cond4>>:$valid, (imm:i8)<<P:Predicate_cond4>>:$R3) - Complexity = 24
                // Dst: (LOC:i32 GR32:i32:$R1src, bdaddr20only:i64:$BD2, (imm:i8):$valid, (imm:i8):$R3)
/*13225*/     /*SwitchType*/ 22,  MVT::i64,// ->13249
/*13227*/       OPC_CheckPatternPredicate, 1, // (Subtarget.hasLoadStoreOnCond())
/*13229*/       OPC_CheckComplexPat, /*CP*/4, /*#*/1, // selectBDAddr20Only:$BD2 #5 #6
/*13232*/       OPC_EmitMergeInputChains1_0,
/*13233*/       OPC_EmitConvertToTarget, 3,
/*13235*/       OPC_EmitConvertToTarget, 4,
/*13237*/       OPC_MorphNodeTo, TARGET_VAL(SystemZ::LOCG), 0|OPFL_Chain|OPFL_GlueInput|OPFL_MemRefs,
                    1/*#VTs*/, MVT::i64, 5/*#Ops*/, 2, 5, 6, 7, 8, 
                // Src: (z_select_ccmask:i64 (ld:i64 bdaddr20only:i64:$BD2)<<P:Predicate_unindexedload>><<P:Predicate_load>>, GR64:i64:$R1src, (imm:i8)<<P:Predicate_cond4>>:$valid, (imm:i8)<<P:Predicate_cond4>>:$R3) - Complexity = 24
                // Dst: (LOCG:i64 GR64:i64:$R1src, bdaddr20only:i64:$BD2, (imm:i8):$valid, (imm:i8):$R3)
/*13249*/     0, // EndSwitchType
/*13250*/   /*Scope*/ 6|128,1/*134*/, /*->13386*/
/*13252*/     OPC_RecordChild0, // #0 = $src1
/*13253*/     OPC_RecordChild1, // #1 = $src2
/*13254*/     OPC_RecordChild2, // #2 = $valid
/*13255*/     OPC_MoveChild, 2,
/*13257*/     OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*13260*/     OPC_CheckPredicate, 4, // Predicate_uimm8zx4
/*13262*/     OPC_MoveParent,
/*13263*/     OPC_RecordChild3, // #3 = $cc
/*13264*/     OPC_MoveChild, 3,
/*13266*/     OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*13269*/     OPC_CheckPredicate, 4, // Predicate_uimm8zx4
/*13271*/     OPC_MoveParent,
/*13272*/     OPC_SwitchType /*5 cases */, 38,  MVT::i32,// ->13313
/*13275*/       OPC_Scope, 18, /*->13295*/ // 2 children in Scope
/*13277*/         OPC_CheckPatternPredicate, 0, // (Subtarget.hasHighWord())
/*13279*/         OPC_EmitConvertToTarget, 2,
/*13281*/         OPC_EmitConvertToTarget, 3,
/*13283*/         OPC_MorphNodeTo, TARGET_VAL(SystemZ::Select32Mux), 0|OPFL_GlueInput,
                      2/*#VTs*/, MVT::i32, MVT::i32, 4/*#Ops*/, 0, 1, 4, 5, 
                  // Src: (z_select_ccmask:i32 GRX32:i32:$src1, GRX32:i32:$src2, (imm:i8)<<P:Predicate_uimm8zx4>>:$valid, (imm:i8)<<P:Predicate_uimm8zx4>>:$cc) - Complexity = 11
                  // Dst: (Select32Mux:i32:i32 GRX32:i32:$src1, GRX32:i32:$src2, (imm:i8):$valid, (imm:i8):$cc)
/*13295*/       /*Scope*/ 16, /*->13312*/
/*13296*/         OPC_EmitConvertToTarget, 2,
/*13298*/         OPC_EmitConvertToTarget, 3,
/*13300*/         OPC_MorphNodeTo, TARGET_VAL(SystemZ::Select32), 0|OPFL_GlueInput,
                      2/*#VTs*/, MVT::i32, MVT::i32, 4/*#Ops*/, 0, 1, 4, 5, 
                  // Src: (z_select_ccmask:i32 GR32:i32:$src1, GR32:i32:$src2, (imm:i8)<<P:Predicate_uimm8zx4>>:$valid, (imm:i8)<<P:Predicate_uimm8zx4>>:$cc) - Complexity = 11
                  // Dst: (Select32:i32:i32 GR32:i32:$src1, GR32:i32:$src2, (imm:i8):$valid, (imm:i8):$cc)
/*13312*/       0, /*End of Scope*/
/*13313*/     /*SwitchType*/ 16,  MVT::i64,// ->13331
/*13315*/       OPC_EmitConvertToTarget, 2,
/*13317*/       OPC_EmitConvertToTarget, 3,
/*13319*/       OPC_MorphNodeTo, TARGET_VAL(SystemZ::Select64), 0|OPFL_GlueInput,
                    2/*#VTs*/, MVT::i64, MVT::i32, 4/*#Ops*/, 0, 1, 4, 5, 
                // Src: (z_select_ccmask:i64 GR64:i64:$src1, GR64:i64:$src2, (imm:i8)<<P:Predicate_uimm8zx4>>:$valid, (imm:i8)<<P:Predicate_uimm8zx4>>:$cc) - Complexity = 11
                // Dst: (Select64:i64:i32 GR64:i64:$src1, GR64:i64:$src2, (imm:i8):$valid, (imm:i8):$cc)
/*13331*/     /*SwitchType*/ 16,  MVT::f32,// ->13349
/*13333*/       OPC_EmitConvertToTarget, 2,
/*13335*/       OPC_EmitConvertToTarget, 3,
/*13337*/       OPC_MorphNodeTo, TARGET_VAL(SystemZ::SelectF32), 0|OPFL_GlueInput,
                    2/*#VTs*/, MVT::f32, MVT::i32, 4/*#Ops*/, 0, 1, 4, 5, 
                // Src: (z_select_ccmask:f32 FP32:f32:$src1, FP32:f32:$src2, (imm:i8)<<P:Predicate_uimm8zx4>>:$valid, (imm:i8)<<P:Predicate_uimm8zx4>>:$cc) - Complexity = 11
                // Dst: (SelectF32:f32:i32 FP32:f32:$src1, FP32:f32:$src2, (imm:i8):$valid, (imm:i8):$cc)
/*13349*/     /*SwitchType*/ 16,  MVT::f64,// ->13367
/*13351*/       OPC_EmitConvertToTarget, 2,
/*13353*/       OPC_EmitConvertToTarget, 3,
/*13355*/       OPC_MorphNodeTo, TARGET_VAL(SystemZ::SelectF64), 0|OPFL_GlueInput,
                    2/*#VTs*/, MVT::f64, MVT::i32, 4/*#Ops*/, 0, 1, 4, 5, 
                // Src: (z_select_ccmask:f64 FP64:f64:$src1, FP64:f64:$src2, (imm:i8)<<P:Predicate_uimm8zx4>>:$valid, (imm:i8)<<P:Predicate_uimm8zx4>>:$cc) - Complexity = 11
                // Dst: (SelectF64:f64:i32 FP64:f64:$src1, FP64:f64:$src2, (imm:i8):$valid, (imm:i8):$cc)
/*13367*/     /*SwitchType*/ 16,  MVT::f128,// ->13385
/*13369*/       OPC_EmitConvertToTarget, 2,
/*13371*/       OPC_EmitConvertToTarget, 3,
/*13373*/       OPC_MorphNodeTo, TARGET_VAL(SystemZ::SelectF128), 0|OPFL_GlueInput,
                    2/*#VTs*/, MVT::f128, MVT::i32, 4/*#Ops*/, 0, 1, 4, 5, 
                // Src: (z_select_ccmask:f128 FP128:f128:$src1, FP128:f128:$src2, (imm:i8)<<P:Predicate_uimm8zx4>>:$valid, (imm:i8)<<P:Predicate_uimm8zx4>>:$cc) - Complexity = 11
                // Dst: (SelectF128:f128:i32 FP128:f128:$src1, FP128:f128:$src2, (imm:i8):$valid, (imm:i8):$cc)
/*13385*/     0, // EndSwitchType
/*13386*/   0, /*End of Scope*/
/*13387*/ /*SwitchOpcode*/ 43|128,12/*1579*/,  TARGET_VAL(SystemZISD::ICMP),// ->14970
/*13391*/   OPC_Scope, 53|128,1/*181*/, /*->13575*/ // 5 children in Scope
/*13394*/     OPC_RecordChild0, // #0 = $R1
/*13395*/     OPC_Scope, 73, /*->13470*/ // 2 children in Scope
/*13397*/       OPC_CheckChild0Type, MVT::i32,
/*13399*/       OPC_MoveChild, 1,
/*13401*/       OPC_CheckOpcode, TARGET_VAL(ISD::LOAD),
/*13404*/       OPC_RecordMemRef,
/*13405*/       OPC_RecordNode, // #1 = 'ld' chained node
/*13406*/       OPC_CheckFoldableChainNode,
/*13407*/       OPC_RecordChild1, // #2 = $I2
/*13408*/       OPC_CheckChild1Type, MVT::i64,
/*13410*/       OPC_CheckPredicate, 0, // Predicate_unindexedload
/*13412*/       OPC_Scope, 28, /*->13442*/ // 2 children in Scope
/*13414*/         OPC_CheckPredicate, 35, // Predicate_asextload
/*13416*/         OPC_CheckPredicate, 36, // Predicate_asextloadi16
/*13418*/         OPC_CheckPredicate, 53, // Predicate_aligned_asextloadi16
/*13420*/         OPC_MoveParent,
/*13421*/         OPC_MoveChild, 2,
/*13423*/         OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*13426*/         OPC_MoveParent,
/*13427*/         OPC_CheckPredicate, 54, // Predicate_z_scmp
/*13429*/         OPC_CheckComplexPat, /*CP*/5, /*#*/2, // selectPCRelAddress:$I2 #3
/*13432*/         OPC_EmitMergeInputChains1_1,
/*13433*/         OPC_MorphNodeTo, TARGET_VAL(SystemZ::CHRL), 0|OPFL_Chain|OPFL_GlueOutput|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 3, 
                  // Src: (z_icmp GR32:i32:$R1, (ld:i32 pcrel32:i64:$I2)<<P:Predicate_unindexedload>><<P:Predicate_asextload>><<P:Predicate_asextloadi16>><<P:Predicate_aligned_asextloadi16>>, (imm:i32))<<P:Predicate_z_scmp>> - Complexity = 24
                  // Dst: (CHRL:i32 GR32:i32:$R1, pcrel32:i64:$I2)
/*13442*/       /*Scope*/ 26, /*->13469*/
/*13443*/         OPC_CheckPredicate, 13, // Predicate_load
/*13445*/         OPC_CheckPredicate, 55, // Predicate_aligned_load
/*13447*/         OPC_MoveParent,
/*13448*/         OPC_MoveChild, 2,
/*13450*/         OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*13453*/         OPC_MoveParent,
/*13454*/         OPC_CheckPredicate, 54, // Predicate_z_scmp
/*13456*/         OPC_CheckComplexPat, /*CP*/5, /*#*/2, // selectPCRelAddress:$I2 #3
/*13459*/         OPC_EmitMergeInputChains1_1,
/*13460*/         OPC_MorphNodeTo, TARGET_VAL(SystemZ::CRL), 0|OPFL_Chain|OPFL_GlueOutput|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 3, 
                  // Src: (z_icmp GR32:i32:$R1, (ld:i32 pcrel32:i64:$I2)<<P:Predicate_unindexedload>><<P:Predicate_load>><<P:Predicate_aligned_load>>, (imm:i32))<<P:Predicate_z_scmp>> - Complexity = 24
                  // Dst: (CRL:i32 GR32:i32:$R1, pcrel32:i64:$I2)
/*13469*/       0, /*End of Scope*/
/*13470*/     /*Scope*/ 103, /*->13574*/
/*13471*/       OPC_CheckChild0Type, MVT::i64,
/*13473*/       OPC_MoveChild, 1,
/*13475*/       OPC_CheckOpcode, TARGET_VAL(ISD::LOAD),
/*13478*/       OPC_RecordMemRef,
/*13479*/       OPC_RecordNode, // #1 = 'ld' chained node
/*13480*/       OPC_CheckFoldableChainNode,
/*13481*/       OPC_RecordChild1, // #2 = $I2
/*13482*/       OPC_CheckChild1Type, MVT::i64,
/*13484*/       OPC_CheckPredicate, 0, // Predicate_unindexedload
/*13486*/       OPC_Scope, 58, /*->13546*/ // 2 children in Scope
/*13488*/         OPC_CheckPredicate, 35, // Predicate_asextload
/*13490*/         OPC_Scope, 26, /*->13518*/ // 2 children in Scope
/*13492*/           OPC_CheckPredicate, 36, // Predicate_asextloadi16
/*13494*/           OPC_CheckPredicate, 53, // Predicate_aligned_asextloadi16
/*13496*/           OPC_MoveParent,
/*13497*/           OPC_MoveChild, 2,
/*13499*/           OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*13502*/           OPC_MoveParent,
/*13503*/           OPC_CheckPredicate, 54, // Predicate_z_scmp
/*13505*/           OPC_CheckComplexPat, /*CP*/5, /*#*/2, // selectPCRelAddress:$I2 #3
/*13508*/           OPC_EmitMergeInputChains1_1,
/*13509*/           OPC_MorphNodeTo, TARGET_VAL(SystemZ::CGHRL), 0|OPFL_Chain|OPFL_GlueOutput|OPFL_MemRefs,
                        1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 3, 
                    // Src: (z_icmp GR64:i64:$R1, (ld:i64 pcrel32:i64:$I2)<<P:Predicate_unindexedload>><<P:Predicate_asextload>><<P:Predicate_asextloadi16>><<P:Predicate_aligned_asextloadi16>>, (imm:i32))<<P:Predicate_z_scmp>> - Complexity = 24
                    // Dst: (CGHRL:i32 GR64:i64:$R1, pcrel32:i64:$I2)
/*13518*/         /*Scope*/ 26, /*->13545*/
/*13519*/           OPC_CheckPredicate, 37, // Predicate_asextloadi32
/*13521*/           OPC_CheckPredicate, 56, // Predicate_aligned_asextloadi32
/*13523*/           OPC_MoveParent,
/*13524*/           OPC_MoveChild, 2,
/*13526*/           OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*13529*/           OPC_MoveParent,
/*13530*/           OPC_CheckPredicate, 54, // Predicate_z_scmp
/*13532*/           OPC_CheckComplexPat, /*CP*/5, /*#*/2, // selectPCRelAddress:$I2 #3
/*13535*/           OPC_EmitMergeInputChains1_1,
/*13536*/           OPC_MorphNodeTo, TARGET_VAL(SystemZ::CGFRL), 0|OPFL_Chain|OPFL_GlueOutput|OPFL_MemRefs,
                        1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 3, 
                    // Src: (z_icmp GR64:i64:$R1, (ld:i64 pcrel32:i64:$I2)<<P:Predicate_unindexedload>><<P:Predicate_asextload>><<P:Predicate_asextloadi32>><<P:Predicate_aligned_asextloadi32>>, (imm:i32))<<P:Predicate_z_scmp>> - Complexity = 24
                    // Dst: (CGFRL:i32 GR64:i64:$R1, pcrel32:i64:$I2)
/*13545*/         0, /*End of Scope*/
/*13546*/       /*Scope*/ 26, /*->13573*/
/*13547*/         OPC_CheckPredicate, 13, // Predicate_load
/*13549*/         OPC_CheckPredicate, 55, // Predicate_aligned_load
/*13551*/         OPC_MoveParent,
/*13552*/         OPC_MoveChild, 2,
/*13554*/         OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*13557*/         OPC_MoveParent,
/*13558*/         OPC_CheckPredicate, 54, // Predicate_z_scmp
/*13560*/         OPC_CheckComplexPat, /*CP*/5, /*#*/2, // selectPCRelAddress:$I2 #3
/*13563*/         OPC_EmitMergeInputChains1_1,
/*13564*/         OPC_MorphNodeTo, TARGET_VAL(SystemZ::CGRL), 0|OPFL_Chain|OPFL_GlueOutput|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 3, 
                  // Src: (z_icmp GR64:i64:$R1, (ld:i64 pcrel32:i64:$I2)<<P:Predicate_unindexedload>><<P:Predicate_load>><<P:Predicate_aligned_load>>, (imm:i32))<<P:Predicate_z_scmp>> - Complexity = 24
                  // Dst: (CGRL:i32 GR64:i64:$R1, pcrel32:i64:$I2)
/*13573*/       0, /*End of Scope*/
/*13574*/     0, /*End of Scope*/
/*13575*/   /*Scope*/ 14|128,1/*142*/, /*->13719*/
/*13577*/     OPC_MoveChild, 0,
/*13579*/     OPC_CheckOpcode, TARGET_VAL(ISD::LOAD),
/*13582*/     OPC_RecordMemRef,
/*13583*/     OPC_RecordNode, // #0 = 'ld' chained node
/*13584*/     OPC_CheckFoldableChainNode,
/*13585*/     OPC_RecordChild1, // #1 = $BD1
/*13586*/     OPC_CheckChild1Type, MVT::i64,
/*13588*/     OPC_CheckPredicate, 0, // Predicate_unindexedload
/*13590*/     OPC_Scope, 43, /*->13635*/ // 2 children in Scope
/*13592*/       OPC_CheckPredicate, 35, // Predicate_asextload
/*13594*/       OPC_CheckPredicate, 36, // Predicate_asextloadi16
/*13596*/       OPC_CheckType, MVT::i32,
/*13598*/       OPC_MoveParent,
/*13599*/       OPC_RecordChild1, // #2 = $I2
/*13600*/       OPC_MoveChild, 1,
/*13602*/       OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*13605*/       OPC_CheckPredicate, 31, // Predicate_imm32sx16
/*13607*/       OPC_MoveParent,
/*13608*/       OPC_MoveChild, 2,
/*13610*/       OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*13613*/       OPC_MoveParent,
/*13614*/       OPC_CheckPredicate, 54, // Predicate_z_scmp
/*13616*/       OPC_CheckComplexPat, /*CP*/1, /*#*/1, // selectBDAddr12Only:$BD1 #3 #4
/*13619*/       OPC_EmitMergeInputChains1_0,
/*13620*/       OPC_EmitConvertToTarget, 2,
/*13622*/       OPC_EmitNodeXForm, 2, 5, // SIMM16
/*13625*/       OPC_MorphNodeTo, TARGET_VAL(SystemZ::CHHSI), 0|OPFL_Chain|OPFL_GlueOutput|OPFL_MemRefs,
                    1/*#VTs*/, MVT::i32, 3/*#Ops*/, 3, 4, 6, 
                // Src: (z_icmp (ld:i32 bdaddr12only:i64:$BD1)<<P:Predicate_unindexedload>><<P:Predicate_asextload>><<P:Predicate_asextloadi16>>, (imm:i32)<<P:Predicate_imm32sx16>><<X:SIMM16>>:$I2, (imm:i32))<<P:Predicate_z_scmp>> - Complexity = 24
                // Dst: (CHHSI:i32 bdaddr12only:i64:$BD1, (SIMM16:i32 (imm:i32):$I2))
/*13635*/     /*Scope*/ 82, /*->13718*/
/*13636*/       OPC_CheckPredicate, 13, // Predicate_load
/*13638*/       OPC_SwitchType /*2 cases */, 37,  MVT::i32,// ->13678
/*13641*/         OPC_MoveParent,
/*13642*/         OPC_RecordChild1, // #2 = $I2
/*13643*/         OPC_MoveChild, 1,
/*13645*/         OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*13648*/         OPC_CheckPredicate, 31, // Predicate_imm32sx16
/*13650*/         OPC_MoveParent,
/*13651*/         OPC_MoveChild, 2,
/*13653*/         OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*13656*/         OPC_MoveParent,
/*13657*/         OPC_CheckPredicate, 54, // Predicate_z_scmp
/*13659*/         OPC_CheckComplexPat, /*CP*/1, /*#*/1, // selectBDAddr12Only:$BD1 #3 #4
/*13662*/         OPC_EmitMergeInputChains1_0,
/*13663*/         OPC_EmitConvertToTarget, 2,
/*13665*/         OPC_EmitNodeXForm, 2, 5, // SIMM16
/*13668*/         OPC_MorphNodeTo, TARGET_VAL(SystemZ::CHSI), 0|OPFL_Chain|OPFL_GlueOutput|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i32, 3/*#Ops*/, 3, 4, 6, 
                  // Src: (z_icmp (ld:i32 bdaddr12only:i64:$BD1)<<P:Predicate_unindexedload>><<P:Predicate_load>>, (imm:i32)<<P:Predicate_imm32sx16>><<X:SIMM16>>:$I2, (imm:i32))<<P:Predicate_z_scmp>> - Complexity = 24
                  // Dst: (CHSI:i32 bdaddr12only:i64:$BD1, (SIMM16:i32 (imm:i32):$I2))
/*13678*/       /*SwitchType*/ 37,  MVT::i64,// ->13717
/*13680*/         OPC_MoveParent,
/*13681*/         OPC_RecordChild1, // #2 = $I2
/*13682*/         OPC_MoveChild, 1,
/*13684*/         OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*13687*/         OPC_CheckPredicate, 32, // Predicate_imm64sx16
/*13689*/         OPC_MoveParent,
/*13690*/         OPC_MoveChild, 2,
/*13692*/         OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*13695*/         OPC_MoveParent,
/*13696*/         OPC_CheckPredicate, 54, // Predicate_z_scmp
/*13698*/         OPC_CheckComplexPat, /*CP*/1, /*#*/1, // selectBDAddr12Only:$BD1 #3 #4
/*13701*/         OPC_EmitMergeInputChains1_0,
/*13702*/         OPC_EmitConvertToTarget, 2,
/*13704*/         OPC_EmitNodeXForm, 2, 5, // SIMM16
/*13707*/         OPC_MorphNodeTo, TARGET_VAL(SystemZ::CGHSI), 0|OPFL_Chain|OPFL_GlueOutput|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i32, 3/*#Ops*/, 3, 4, 6, 
                  // Src: (z_icmp (ld:i64 bdaddr12only:i64:$BD1)<<P:Predicate_unindexedload>><<P:Predicate_load>>, (imm:i64)<<P:Predicate_imm64sx16>><<X:SIMM16>>:$I2, (imm:i32))<<P:Predicate_z_scmp>> - Complexity = 24
                  // Dst: (CGHSI:i32 bdaddr12only:i64:$BD1, (SIMM16:i64 (imm:i64):$I2))
/*13717*/       0, // EndSwitchType
/*13718*/     0, /*End of Scope*/
/*13719*/   /*Scope*/ 53|128,1/*181*/, /*->13902*/
/*13721*/     OPC_RecordChild0, // #0 = $R1
/*13722*/     OPC_Scope, 73, /*->13797*/ // 2 children in Scope
/*13724*/       OPC_CheckChild0Type, MVT::i32,
/*13726*/       OPC_MoveChild, 1,
/*13728*/       OPC_CheckOpcode, TARGET_VAL(ISD::LOAD),
/*13731*/       OPC_RecordMemRef,
/*13732*/       OPC_RecordNode, // #1 = 'ld' chained node
/*13733*/       OPC_CheckFoldableChainNode,
/*13734*/       OPC_RecordChild1, // #2 = $I2
/*13735*/       OPC_CheckChild1Type, MVT::i64,
/*13737*/       OPC_CheckPredicate, 0, // Predicate_unindexedload
/*13739*/       OPC_Scope, 28, /*->13769*/ // 2 children in Scope
/*13741*/         OPC_CheckPredicate, 38, // Predicate_azextload
/*13743*/         OPC_CheckPredicate, 57, // Predicate_azextloadi16
/*13745*/         OPC_CheckPredicate, 58, // Predicate_aligned_azextloadi16
/*13747*/         OPC_MoveParent,
/*13748*/         OPC_MoveChild, 2,
/*13750*/         OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*13753*/         OPC_MoveParent,
/*13754*/         OPC_CheckPredicate, 59, // Predicate_z_ucmp
/*13756*/         OPC_CheckComplexPat, /*CP*/5, /*#*/2, // selectPCRelAddress:$I2 #3
/*13759*/         OPC_EmitMergeInputChains1_1,
/*13760*/         OPC_MorphNodeTo, TARGET_VAL(SystemZ::CLHRL), 0|OPFL_Chain|OPFL_GlueOutput|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 3, 
                  // Src: (z_icmp GR32:i32:$R1, (ld:i32 pcrel32:i64:$I2)<<P:Predicate_unindexedload>><<P:Predicate_azextload>><<P:Predicate_azextloadi16>><<P:Predicate_aligned_azextloadi16>>, (imm:i32))<<P:Predicate_z_ucmp>> - Complexity = 24
                  // Dst: (CLHRL:i32 GR32:i32:$R1, pcrel32:i64:$I2)
/*13769*/       /*Scope*/ 26, /*->13796*/
/*13770*/         OPC_CheckPredicate, 13, // Predicate_load
/*13772*/         OPC_CheckPredicate, 55, // Predicate_aligned_load
/*13774*/         OPC_MoveParent,
/*13775*/         OPC_MoveChild, 2,
/*13777*/         OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*13780*/         OPC_MoveParent,
/*13781*/         OPC_CheckPredicate, 59, // Predicate_z_ucmp
/*13783*/         OPC_CheckComplexPat, /*CP*/5, /*#*/2, // selectPCRelAddress:$I2 #3
/*13786*/         OPC_EmitMergeInputChains1_1,
/*13787*/         OPC_MorphNodeTo, TARGET_VAL(SystemZ::CLRL), 0|OPFL_Chain|OPFL_GlueOutput|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 3, 
                  // Src: (z_icmp GR32:i32:$R1, (ld:i32 pcrel32:i64:$I2)<<P:Predicate_unindexedload>><<P:Predicate_load>><<P:Predicate_aligned_load>>, (imm:i32))<<P:Predicate_z_ucmp>> - Complexity = 24
                  // Dst: (CLRL:i32 GR32:i32:$R1, pcrel32:i64:$I2)
/*13796*/       0, /*End of Scope*/
/*13797*/     /*Scope*/ 103, /*->13901*/
/*13798*/       OPC_CheckChild0Type, MVT::i64,
/*13800*/       OPC_MoveChild, 1,
/*13802*/       OPC_CheckOpcode, TARGET_VAL(ISD::LOAD),
/*13805*/       OPC_RecordMemRef,
/*13806*/       OPC_RecordNode, // #1 = 'ld' chained node
/*13807*/       OPC_CheckFoldableChainNode,
/*13808*/       OPC_RecordChild1, // #2 = $I2
/*13809*/       OPC_CheckChild1Type, MVT::i64,
/*13811*/       OPC_CheckPredicate, 0, // Predicate_unindexedload
/*13813*/       OPC_Scope, 58, /*->13873*/ // 2 children in Scope
/*13815*/         OPC_CheckPredicate, 38, // Predicate_azextload
/*13817*/         OPC_Scope, 26, /*->13845*/ // 2 children in Scope
/*13819*/           OPC_CheckPredicate, 57, // Predicate_azextloadi16
/*13821*/           OPC_CheckPredicate, 58, // Predicate_aligned_azextloadi16
/*13823*/           OPC_MoveParent,
/*13824*/           OPC_MoveChild, 2,
/*13826*/           OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*13829*/           OPC_MoveParent,
/*13830*/           OPC_CheckPredicate, 59, // Predicate_z_ucmp
/*13832*/           OPC_CheckComplexPat, /*CP*/5, /*#*/2, // selectPCRelAddress:$I2 #3
/*13835*/           OPC_EmitMergeInputChains1_1,
/*13836*/           OPC_MorphNodeTo, TARGET_VAL(SystemZ::CLGHRL), 0|OPFL_Chain|OPFL_GlueOutput|OPFL_MemRefs,
                        1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 3, 
                    // Src: (z_icmp GR64:i64:$R1, (ld:i64 pcrel32:i64:$I2)<<P:Predicate_unindexedload>><<P:Predicate_azextload>><<P:Predicate_azextloadi16>><<P:Predicate_aligned_azextloadi16>>, (imm:i32))<<P:Predicate_z_ucmp>> - Complexity = 24
                    // Dst: (CLGHRL:i32 GR64:i64:$R1, pcrel32:i64:$I2)
/*13845*/         /*Scope*/ 26, /*->13872*/
/*13846*/           OPC_CheckPredicate, 39, // Predicate_azextloadi32
/*13848*/           OPC_CheckPredicate, 60, // Predicate_aligned_azextloadi32
/*13850*/           OPC_MoveParent,
/*13851*/           OPC_MoveChild, 2,
/*13853*/           OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*13856*/           OPC_MoveParent,
/*13857*/           OPC_CheckPredicate, 59, // Predicate_z_ucmp
/*13859*/           OPC_CheckComplexPat, /*CP*/5, /*#*/2, // selectPCRelAddress:$I2 #3
/*13862*/           OPC_EmitMergeInputChains1_1,
/*13863*/           OPC_MorphNodeTo, TARGET_VAL(SystemZ::CLGFRL), 0|OPFL_Chain|OPFL_GlueOutput|OPFL_MemRefs,
                        1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 3, 
                    // Src: (z_icmp GR64:i64:$R1, (ld:i64 pcrel32:i64:$I2)<<P:Predicate_unindexedload>><<P:Predicate_azextload>><<P:Predicate_azextloadi32>><<P:Predicate_aligned_azextloadi32>>, (imm:i32))<<P:Predicate_z_ucmp>> - Complexity = 24
                    // Dst: (CLGFRL:i32 GR64:i64:$R1, pcrel32:i64:$I2)
/*13872*/         0, /*End of Scope*/
/*13873*/       /*Scope*/ 26, /*->13900*/
/*13874*/         OPC_CheckPredicate, 13, // Predicate_load
/*13876*/         OPC_CheckPredicate, 55, // Predicate_aligned_load
/*13878*/         OPC_MoveParent,
/*13879*/         OPC_MoveChild, 2,
/*13881*/         OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*13884*/         OPC_MoveParent,
/*13885*/         OPC_CheckPredicate, 59, // Predicate_z_ucmp
/*13887*/         OPC_CheckComplexPat, /*CP*/5, /*#*/2, // selectPCRelAddress:$I2 #3
/*13890*/         OPC_EmitMergeInputChains1_1,
/*13891*/         OPC_MorphNodeTo, TARGET_VAL(SystemZ::CLGRL), 0|OPFL_Chain|OPFL_GlueOutput|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 3, 
                  // Src: (z_icmp GR64:i64:$R1, (ld:i64 pcrel32:i64:$I2)<<P:Predicate_unindexedload>><<P:Predicate_load>><<P:Predicate_aligned_load>>, (imm:i32))<<P:Predicate_z_ucmp>> - Complexity = 24
                  // Dst: (CLGRL:i32 GR64:i64:$R1, pcrel32:i64:$I2)
/*13900*/       0, /*End of Scope*/
/*13901*/     0, /*End of Scope*/
/*13902*/   /*Scope*/ 80|128,1/*208*/, /*->14112*/
/*13904*/     OPC_MoveChild, 0,
/*13906*/     OPC_CheckOpcode, TARGET_VAL(ISD::LOAD),
/*13909*/     OPC_RecordMemRef,
/*13910*/     OPC_RecordNode, // #0 = 'ld' chained node
/*13911*/     OPC_CheckFoldableChainNode,
/*13912*/     OPC_RecordChild1, // #1 = $BD1
/*13913*/     OPC_CheckChild1Type, MVT::i64,
/*13915*/     OPC_CheckPredicate, 0, // Predicate_unindexedload
/*13917*/     OPC_Scope, 109, /*->14028*/ // 2 children in Scope
/*13919*/       OPC_CheckPredicate, 38, // Predicate_azextload
/*13921*/       OPC_CheckType, MVT::i32,
/*13923*/       OPC_Scope, 62, /*->13987*/ // 2 children in Scope
/*13925*/         OPC_CheckPredicate, 42, // Predicate_azextloadi8
/*13927*/         OPC_MoveParent,
/*13928*/         OPC_RecordChild1, // #2 = $I2
/*13929*/         OPC_MoveChild, 1,
/*13931*/         OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*13934*/         OPC_CheckPredicate, 51, // Predicate_imm32zx8
/*13936*/         OPC_MoveParent,
/*13937*/         OPC_MoveChild, 2,
/*13939*/         OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*13942*/         OPC_MoveParent,
/*13943*/         OPC_CheckPredicate, 59, // Predicate_z_ucmp
/*13945*/         OPC_Scope, 19, /*->13966*/ // 2 children in Scope
/*13947*/           OPC_CheckComplexPat, /*CP*/2, /*#*/1, // selectBDAddr12Pair:$BD1 #3 #4
/*13950*/           OPC_EmitMergeInputChains1_0,
/*13951*/           OPC_EmitConvertToTarget, 2,
/*13953*/           OPC_EmitNodeXForm, 0, 5, // UIMM8
/*13956*/           OPC_MorphNodeTo, TARGET_VAL(SystemZ::CLI), 0|OPFL_Chain|OPFL_GlueOutput|OPFL_MemRefs,
                        1/*#VTs*/, MVT::i32, 3/*#Ops*/, 3, 4, 6, 
                    // Src: (z_icmp (ld:i32 bdaddr12pair:i64:$BD1)<<P:Predicate_unindexedload>><<P:Predicate_azextload>><<P:Predicate_azextloadi8>>, (imm:i32)<<P:Predicate_imm32zx8>><<X:UIMM8>>:$I2, (imm:i32))<<P:Predicate_z_ucmp>> - Complexity = 24
                    // Dst: (CLI:i32 bdaddr12pair:i64:$BD1, (UIMM8:i32 (imm:i32):$I2))
/*13966*/         /*Scope*/ 19, /*->13986*/
/*13967*/           OPC_CheckComplexPat, /*CP*/3, /*#*/1, // selectBDAddr20Pair:$BD1 #3 #4
/*13970*/           OPC_EmitMergeInputChains1_0,
/*13971*/           OPC_EmitConvertToTarget, 2,
/*13973*/           OPC_EmitNodeXForm, 0, 5, // UIMM8
/*13976*/           OPC_MorphNodeTo, TARGET_VAL(SystemZ::CLIY), 0|OPFL_Chain|OPFL_GlueOutput|OPFL_MemRefs,
                        1/*#VTs*/, MVT::i32, 3/*#Ops*/, 3, 4, 6, 
                    // Src: (z_icmp (ld:i32 bdaddr20pair:i64:$BD1)<<P:Predicate_unindexedload>><<P:Predicate_azextload>><<P:Predicate_azextloadi8>>, (imm:i32)<<P:Predicate_imm32zx8>><<X:UIMM8>>:$I2, (imm:i32))<<P:Predicate_z_ucmp>> - Complexity = 24
                    // Dst: (CLIY:i32 bdaddr20pair:i64:$BD1, (UIMM8:i32 (imm:i32):$I2))
/*13986*/         0, /*End of Scope*/
/*13987*/       /*Scope*/ 39, /*->14027*/
/*13988*/         OPC_CheckPredicate, 57, // Predicate_azextloadi16
/*13990*/         OPC_MoveParent,
/*13991*/         OPC_RecordChild1, // #2 = $I2
/*13992*/         OPC_MoveChild, 1,
/*13994*/         OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*13997*/         OPC_CheckPredicate, 61, // Predicate_imm32zx16
/*13999*/         OPC_MoveParent,
/*14000*/         OPC_MoveChild, 2,
/*14002*/         OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*14005*/         OPC_MoveParent,
/*14006*/         OPC_CheckPredicate, 59, // Predicate_z_ucmp
/*14008*/         OPC_CheckComplexPat, /*CP*/1, /*#*/1, // selectBDAddr12Only:$BD1 #3 #4
/*14011*/         OPC_EmitMergeInputChains1_0,
/*14012*/         OPC_EmitConvertToTarget, 2,
/*14014*/         OPC_EmitNodeXForm, 10, 5, // UIMM16
/*14017*/         OPC_MorphNodeTo, TARGET_VAL(SystemZ::CLHHSI), 0|OPFL_Chain|OPFL_GlueOutput|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i32, 3/*#Ops*/, 3, 4, 6, 
                  // Src: (z_icmp (ld:i32 bdaddr12only:i64:$BD1)<<P:Predicate_unindexedload>><<P:Predicate_azextload>><<P:Predicate_azextloadi16>>, (imm:i32)<<P:Predicate_imm32zx16>><<X:UIMM16>>:$I2, (imm:i32))<<P:Predicate_z_ucmp>> - Complexity = 24
                  // Dst: (CLHHSI:i32 bdaddr12only:i64:$BD1, (UIMM16:i32 (imm:i32):$I2))
/*14027*/       0, /*End of Scope*/
/*14028*/     /*Scope*/ 82, /*->14111*/
/*14029*/       OPC_CheckPredicate, 13, // Predicate_load
/*14031*/       OPC_SwitchType /*2 cases */, 37,  MVT::i32,// ->14071
/*14034*/         OPC_MoveParent,
/*14035*/         OPC_RecordChild1, // #2 = $I2
/*14036*/         OPC_MoveChild, 1,
/*14038*/         OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*14041*/         OPC_CheckPredicate, 61, // Predicate_imm32zx16
/*14043*/         OPC_MoveParent,
/*14044*/         OPC_MoveChild, 2,
/*14046*/         OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*14049*/         OPC_MoveParent,
/*14050*/         OPC_CheckPredicate, 59, // Predicate_z_ucmp
/*14052*/         OPC_CheckComplexPat, /*CP*/1, /*#*/1, // selectBDAddr12Only:$BD1 #3 #4
/*14055*/         OPC_EmitMergeInputChains1_0,
/*14056*/         OPC_EmitConvertToTarget, 2,
/*14058*/         OPC_EmitNodeXForm, 10, 5, // UIMM16
/*14061*/         OPC_MorphNodeTo, TARGET_VAL(SystemZ::CLFHSI), 0|OPFL_Chain|OPFL_GlueOutput|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i32, 3/*#Ops*/, 3, 4, 6, 
                  // Src: (z_icmp (ld:i32 bdaddr12only:i64:$BD1)<<P:Predicate_unindexedload>><<P:Predicate_load>>, (imm:i32)<<P:Predicate_imm32zx16>><<X:UIMM16>>:$I2, (imm:i32))<<P:Predicate_z_ucmp>> - Complexity = 24
                  // Dst: (CLFHSI:i32 bdaddr12only:i64:$BD1, (UIMM16:i32 (imm:i32):$I2))
/*14071*/       /*SwitchType*/ 37,  MVT::i64,// ->14110
/*14073*/         OPC_MoveParent,
/*14074*/         OPC_RecordChild1, // #2 = $I2
/*14075*/         OPC_MoveChild, 1,
/*14077*/         OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*14080*/         OPC_CheckPredicate, 62, // Predicate_imm64zx16
/*14082*/         OPC_MoveParent,
/*14083*/         OPC_MoveChild, 2,
/*14085*/         OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*14088*/         OPC_MoveParent,
/*14089*/         OPC_CheckPredicate, 59, // Predicate_z_ucmp
/*14091*/         OPC_CheckComplexPat, /*CP*/1, /*#*/1, // selectBDAddr12Only:$BD1 #3 #4
/*14094*/         OPC_EmitMergeInputChains1_0,
/*14095*/         OPC_EmitConvertToTarget, 2,
/*14097*/         OPC_EmitNodeXForm, 10, 5, // UIMM16
/*14100*/         OPC_MorphNodeTo, TARGET_VAL(SystemZ::CLGHSI), 0|OPFL_Chain|OPFL_GlueOutput|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i32, 3/*#Ops*/, 3, 4, 6, 
                  // Src: (z_icmp (ld:i64 bdaddr12only:i64:$BD1)<<P:Predicate_unindexedload>><<P:Predicate_load>>, (imm:i64)<<P:Predicate_imm64zx16>><<X:UIMM16>>:$I2, (imm:i32))<<P:Predicate_z_ucmp>> - Complexity = 24
                  // Dst: (CLGHSI:i32 bdaddr12only:i64:$BD1, (UIMM16:i64 (imm:i64):$I2))
/*14110*/       0, // EndSwitchType
/*14111*/     0, /*End of Scope*/
/*14112*/   /*Scope*/ 87|128,6/*855*/, /*->14969*/
/*14114*/     OPC_RecordChild0, // #0 = $R1
/*14115*/     OPC_Scope, 68|128,2/*324*/, /*->14442*/ // 7 children in Scope
/*14118*/       OPC_CheckChild0Type, MVT::i32,
/*14120*/       OPC_Scope, 94|128,1/*222*/, /*->14345*/ // 2 children in Scope
/*14123*/         OPC_MoveChild, 1,
/*14125*/         OPC_CheckOpcode, TARGET_VAL(ISD::LOAD),
/*14128*/         OPC_RecordMemRef,
/*14129*/         OPC_RecordNode, // #1 = 'ld' chained node
/*14130*/         OPC_CheckFoldableChainNode,
/*14131*/         OPC_RecordChild1, // #2 = $XBD2
/*14132*/         OPC_CheckChild1Type, MVT::i64,
/*14134*/         OPC_CheckPredicate, 0, // Predicate_unindexedload
/*14136*/         OPC_Scope, 47, /*->14185*/ // 2 children in Scope
/*14138*/           OPC_CheckPredicate, 35, // Predicate_asextload
/*14140*/           OPC_CheckPredicate, 36, // Predicate_asextloadi16
/*14142*/           OPC_MoveParent,
/*14143*/           OPC_MoveChild, 2,
/*14145*/           OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*14148*/           OPC_MoveParent,
/*14149*/           OPC_CheckPredicate, 54, // Predicate_z_scmp
/*14151*/           OPC_Scope, 15, /*->14168*/ // 2 children in Scope
/*14153*/             OPC_CheckComplexPat, /*CP*/7, /*#*/2, // selectBDXAddr12Pair:$XBD2 #3 #4 #5
/*14156*/             OPC_EmitMergeInputChains1_1,
/*14157*/             OPC_MorphNodeTo, TARGET_VAL(SystemZ::CH), 0|OPFL_Chain|OPFL_GlueOutput|OPFL_MemRefs,
                          1/*#VTs*/, MVT::i32, 4/*#Ops*/, 0, 3, 4, 5, 
                      // Src: (z_icmp GR32:i32:$R1, (ld:i32 bdxaddr12pair:i64:$XBD2)<<P:Predicate_unindexedload>><<P:Predicate_asextload>><<P:Predicate_asextloadi16>>, (imm:i32))<<P:Predicate_z_scmp>> - Complexity = 23
                      // Dst: (CH:i32 GR32:i32:$R1, bdxaddr12pair:i64:$XBD2)
/*14168*/           /*Scope*/ 15, /*->14184*/
/*14169*/             OPC_CheckComplexPat, /*CP*/8, /*#*/2, // selectBDXAddr20Pair:$XBD2 #3 #4 #5
/*14172*/             OPC_EmitMergeInputChains1_1,
/*14173*/             OPC_MorphNodeTo, TARGET_VAL(SystemZ::CHY), 0|OPFL_Chain|OPFL_GlueOutput|OPFL_MemRefs,
                          1/*#VTs*/, MVT::i32, 4/*#Ops*/, 0, 3, 4, 5, 
                      // Src: (z_icmp GR32:i32:$R1, (ld:i32 bdxaddr20pair:i64:$XBD2)<<P:Predicate_unindexedload>><<P:Predicate_asextload>><<P:Predicate_asextloadi16>>, (imm:i32))<<P:Predicate_z_scmp>> - Complexity = 23
                      // Dst: (CHY:i32 GR32:i32:$R1, bdxaddr20pair:i64:$XBD2)
/*14184*/           0, /*End of Scope*/
/*14185*/         /*Scope*/ 29|128,1/*157*/, /*->14344*/
/*14187*/           OPC_CheckPredicate, 13, // Predicate_load
/*14189*/           OPC_MoveParent,
/*14190*/           OPC_MoveChild, 2,
/*14192*/           OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*14195*/           OPC_MoveParent,
/*14196*/           OPC_Scope, 72, /*->14270*/ // 2 children in Scope
/*14198*/             OPC_CheckPredicate, 54, // Predicate_z_scmp
/*14200*/             OPC_Scope, 17, /*->14219*/ // 4 children in Scope
/*14202*/               OPC_CheckPatternPredicate, 0, // (Subtarget.hasHighWord())
/*14204*/               OPC_CheckComplexPat, /*CP*/0, /*#*/2, // selectBDXAddr20Only:$XBD2 #3 #4 #5
/*14207*/               OPC_EmitMergeInputChains1_1,
/*14208*/               OPC_MorphNodeTo, TARGET_VAL(SystemZ::CMux), 0|OPFL_Chain|OPFL_GlueOutput|OPFL_MemRefs,
                            1/*#VTs*/, MVT::i32, 4/*#Ops*/, 0, 3, 4, 5, 
                        // Src: (z_icmp GRX32:i32:$R1, (ld:i32 bdxaddr20only:i64:$XBD2)<<P:Predicate_unindexedload>><<P:Predicate_load>>, (imm:i32))<<P:Predicate_z_scmp>> - Complexity = 23
                        // Dst: (CMux:i32 GRX32:i32:$R1, bdxaddr20only:i64:$XBD2)
/*14219*/             /*Scope*/ 15, /*->14235*/
/*14220*/               OPC_CheckComplexPat, /*CP*/7, /*#*/2, // selectBDXAddr12Pair:$XBD2 #3 #4 #5
/*14223*/               OPC_EmitMergeInputChains1_1,
/*14224*/               OPC_MorphNodeTo, TARGET_VAL(SystemZ::C), 0|OPFL_Chain|OPFL_GlueOutput|OPFL_MemRefs,
                            1/*#VTs*/, MVT::i32, 4/*#Ops*/, 0, 3, 4, 5, 
                        // Src: (z_icmp GR32:i32:$R1, (ld:i32 bdxaddr12pair:i64:$XBD2)<<P:Predicate_unindexedload>><<P:Predicate_load>>, (imm:i32))<<P:Predicate_z_scmp>> - Complexity = 23
                        // Dst: (C:i32 GR32:i32:$R1, bdxaddr12pair:i64:$XBD2)
/*14235*/             /*Scope*/ 15, /*->14251*/
/*14236*/               OPC_CheckComplexPat, /*CP*/8, /*#*/2, // selectBDXAddr20Pair:$XBD2 #3 #4 #5
/*14239*/               OPC_EmitMergeInputChains1_1,
/*14240*/               OPC_MorphNodeTo, TARGET_VAL(SystemZ::CY), 0|OPFL_Chain|OPFL_GlueOutput|OPFL_MemRefs,
                            1/*#VTs*/, MVT::i32, 4/*#Ops*/, 0, 3, 4, 5, 
                        // Src: (z_icmp GR32:i32:$R1, (ld:i32 bdxaddr20pair:i64:$XBD2)<<P:Predicate_unindexedload>><<P:Predicate_load>>, (imm:i32))<<P:Predicate_z_scmp>> - Complexity = 23
                        // Dst: (CY:i32 GR32:i32:$R1, bdxaddr20pair:i64:$XBD2)
/*14251*/             /*Scope*/ 17, /*->14269*/
/*14252*/               OPC_CheckPatternPredicate, 0, // (Subtarget.hasHighWord())
/*14254*/               OPC_CheckComplexPat, /*CP*/0, /*#*/2, // selectBDXAddr20Only:$XBD2 #3 #4 #5
/*14257*/               OPC_EmitMergeInputChains1_1,
/*14258*/               OPC_MorphNodeTo, TARGET_VAL(SystemZ::CHF), 0|OPFL_Chain|OPFL_GlueOutput|OPFL_MemRefs,
                            1/*#VTs*/, MVT::i32, 4/*#Ops*/, 0, 3, 4, 5, 
                        // Src: (z_icmp GRH32:i32:$R1, (ld:i32 bdxaddr20only:i64:$XBD2)<<P:Predicate_unindexedload>><<P:Predicate_load>>, (imm:i32))<<P:Predicate_z_scmp>> - Complexity = 23
                        // Dst: (CHF:i32 GRH32:i32:$R1, bdxaddr20only:i64:$XBD2)
/*14269*/             0, /*End of Scope*/
/*14270*/           /*Scope*/ 72, /*->14343*/
/*14271*/             OPC_CheckPredicate, 59, // Predicate_z_ucmp
/*14273*/             OPC_Scope, 17, /*->14292*/ // 4 children in Scope
/*14275*/               OPC_CheckPatternPredicate, 0, // (Subtarget.hasHighWord())
/*14277*/               OPC_CheckComplexPat, /*CP*/0, /*#*/2, // selectBDXAddr20Only:$XBD2 #3 #4 #5
/*14280*/               OPC_EmitMergeInputChains1_1,
/*14281*/               OPC_MorphNodeTo, TARGET_VAL(SystemZ::CLMux), 0|OPFL_Chain|OPFL_GlueOutput|OPFL_MemRefs,
                            1/*#VTs*/, MVT::i32, 4/*#Ops*/, 0, 3, 4, 5, 
                        // Src: (z_icmp GRX32:i32:$R1, (ld:i32 bdxaddr20only:i64:$XBD2)<<P:Predicate_unindexedload>><<P:Predicate_load>>, (imm:i32))<<P:Predicate_z_ucmp>> - Complexity = 23
                        // Dst: (CLMux:i32 GRX32:i32:$R1, bdxaddr20only:i64:$XBD2)
/*14292*/             /*Scope*/ 15, /*->14308*/
/*14293*/               OPC_CheckComplexPat, /*CP*/7, /*#*/2, // selectBDXAddr12Pair:$XBD2 #3 #4 #5
/*14296*/               OPC_EmitMergeInputChains1_1,
/*14297*/               OPC_MorphNodeTo, TARGET_VAL(SystemZ::CL), 0|OPFL_Chain|OPFL_GlueOutput|OPFL_MemRefs,
                            1/*#VTs*/, MVT::i32, 4/*#Ops*/, 0, 3, 4, 5, 
                        // Src: (z_icmp GR32:i32:$R1, (ld:i32 bdxaddr12pair:i64:$XBD2)<<P:Predicate_unindexedload>><<P:Predicate_load>>, (imm:i32))<<P:Predicate_z_ucmp>> - Complexity = 23
                        // Dst: (CL:i32 GR32:i32:$R1, bdxaddr12pair:i64:$XBD2)
/*14308*/             /*Scope*/ 15, /*->14324*/
/*14309*/               OPC_CheckComplexPat, /*CP*/8, /*#*/2, // selectBDXAddr20Pair:$XBD2 #3 #4 #5
/*14312*/               OPC_EmitMergeInputChains1_1,
/*14313*/               OPC_MorphNodeTo, TARGET_VAL(SystemZ::CLY), 0|OPFL_Chain|OPFL_GlueOutput|OPFL_MemRefs,
                            1/*#VTs*/, MVT::i32, 4/*#Ops*/, 0, 3, 4, 5, 
                        // Src: (z_icmp GR32:i32:$R1, (ld:i32 bdxaddr20pair:i64:$XBD2)<<P:Predicate_unindexedload>><<P:Predicate_load>>, (imm:i32))<<P:Predicate_z_ucmp>> - Complexity = 23
                        // Dst: (CLY:i32 GR32:i32:$R1, bdxaddr20pair:i64:$XBD2)
/*14324*/             /*Scope*/ 17, /*->14342*/
/*14325*/               OPC_CheckPatternPredicate, 0, // (Subtarget.hasHighWord())
/*14327*/               OPC_CheckComplexPat, /*CP*/0, /*#*/2, // selectBDXAddr20Only:$XBD2 #3 #4 #5
/*14330*/               OPC_EmitMergeInputChains1_1,
/*14331*/               OPC_MorphNodeTo, TARGET_VAL(SystemZ::CLHF), 0|OPFL_Chain|OPFL_GlueOutput|OPFL_MemRefs,
                            1/*#VTs*/, MVT::i32, 4/*#Ops*/, 0, 3, 4, 5, 
                        // Src: (z_icmp GRH32:i32:$R1, (ld:i32 bdxaddr20only:i64:$XBD2)<<P:Predicate_unindexedload>><<P:Predicate_load>>, (imm:i32))<<P:Predicate_z_ucmp>> - Complexity = 23
                        // Dst: (CLHF:i32 GRH32:i32:$R1, bdxaddr20only:i64:$XBD2)
/*14342*/             0, /*End of Scope*/
/*14343*/           0, /*End of Scope*/
/*14344*/         0, /*End of Scope*/
/*14345*/       /*Scope*/ 95, /*->14441*/
/*14346*/         OPC_RecordChild1, // #1 = $I2
/*14347*/         OPC_MoveChild, 1,
/*14349*/         OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*14352*/         OPC_Scope, 25, /*->14379*/ // 2 children in Scope
/*14354*/           OPC_CheckPredicate, 31, // Predicate_imm32sx16
/*14356*/           OPC_MoveParent,
/*14357*/           OPC_MoveChild, 2,
/*14359*/           OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*14362*/           OPC_MoveParent,
/*14363*/           OPC_CheckPredicate, 54, // Predicate_z_scmp
/*14365*/           OPC_EmitConvertToTarget, 1,
/*14367*/           OPC_EmitNodeXForm, 2, 2, // SIMM16
/*14370*/           OPC_MorphNodeTo, TARGET_VAL(SystemZ::CHI), 0|OPFL_GlueOutput,
                        1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 3, 
                    // Src: (z_icmp GR32:i32:$R1, (imm:i32)<<P:Predicate_imm32sx16>><<X:SIMM16>>:$I2, (imm:i32))<<P:Predicate_z_scmp>> - Complexity = 11
                    // Dst: (CHI:i32 GR32:i32:$R1, (SIMM16:i32 (imm:i32):$I2))
/*14379*/         /*Scope*/ 60, /*->14440*/
/*14380*/           OPC_MoveParent,
/*14381*/           OPC_MoveChild, 2,
/*14383*/           OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*14386*/           OPC_MoveParent,
/*14387*/           OPC_CheckPredicate, 54, // Predicate_z_scmp
/*14389*/           OPC_Scope, 16, /*->14407*/ // 3 children in Scope
/*14391*/             OPC_CheckPatternPredicate, 0, // (Subtarget.hasHighWord())
/*14393*/             OPC_EmitConvertToTarget, 1,
/*14395*/             OPC_EmitNodeXForm, 11, 2, // SIMM32
/*14398*/             OPC_MorphNodeTo, TARGET_VAL(SystemZ::CFIMux), 0|OPFL_GlueOutput,
                          1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 3, 
                      // Src: (z_icmp GRX32:i32:$R1, (imm:i32)<<X:SIMM32>>:$I2, (imm:i32))<<P:Predicate_z_scmp>> - Complexity = 10
                      // Dst: (CFIMux:i32 GRX32:i32:$R1, (SIMM32:i32 (imm:i32):$I2))
/*14407*/           /*Scope*/ 14, /*->14422*/
/*14408*/             OPC_EmitConvertToTarget, 1,
/*14410*/             OPC_EmitNodeXForm, 11, 2, // SIMM32
/*14413*/             OPC_MorphNodeTo, TARGET_VAL(SystemZ::CFI), 0|OPFL_GlueOutput,
                          1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 3, 
                      // Src: (z_icmp GR32:i32:$R1, (imm:i32)<<X:SIMM32>>:$I2, (imm:i32))<<P:Predicate_z_scmp>> - Complexity = 10
                      // Dst: (CFI:i32 GR32:i32:$R1, (SIMM32:i32 (imm:i32):$I2))
/*14422*/           /*Scope*/ 16, /*->14439*/
/*14423*/             OPC_CheckPatternPredicate, 0, // (Subtarget.hasHighWord())
/*14425*/             OPC_EmitConvertToTarget, 1,
/*14427*/             OPC_EmitNodeXForm, 11, 2, // SIMM32
/*14430*/             OPC_MorphNodeTo, TARGET_VAL(SystemZ::CIH), 0|OPFL_GlueOutput,
                          1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 3, 
                      // Src: (z_icmp GRH32:i32:$R1, (imm:i32)<<X:SIMM32>>:$I2, (imm:i32))<<P:Predicate_z_scmp>> - Complexity = 10
                      // Dst: (CIH:i32 GRH32:i32:$R1, (SIMM32:i32 (imm:i32):$I2))
/*14439*/           0, /*End of Scope*/
/*14440*/         0, /*End of Scope*/
/*14441*/       0, /*End of Scope*/
/*14442*/     /*Scope*/ 36|128,2/*292*/, /*->14736*/
/*14444*/       OPC_CheckChild0Type, MVT::i64,
/*14446*/       OPC_Scope, 71|128,1/*199*/, /*->14648*/ // 2 children in Scope
/*14449*/         OPC_MoveChild, 1,
/*14451*/         OPC_Scope, 27|128,1/*155*/, /*->14609*/ // 2 children in Scope
/*14454*/           OPC_CheckOpcode, TARGET_VAL(ISD::LOAD),
/*14457*/           OPC_RecordMemRef,
/*14458*/           OPC_RecordNode, // #1 = 'ld' chained node
/*14459*/           OPC_CheckFoldableChainNode,
/*14460*/           OPC_RecordChild1, // #2 = $XBD2
/*14461*/           OPC_CheckChild1Type, MVT::i64,
/*14463*/           OPC_CheckPredicate, 0, // Predicate_unindexedload
/*14465*/           OPC_Scope, 58, /*->14525*/ // 4 children in Scope
/*14467*/             OPC_CheckPredicate, 35, // Predicate_asextload
/*14469*/             OPC_Scope, 26, /*->14497*/ // 2 children in Scope
/*14471*/               OPC_CheckPredicate, 36, // Predicate_asextloadi16
/*14473*/               OPC_MoveParent,
/*14474*/               OPC_MoveChild, 2,
/*14476*/               OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*14479*/               OPC_MoveParent,
/*14480*/               OPC_CheckPredicate, 54, // Predicate_z_scmp
/*14482*/               OPC_CheckComplexPat, /*CP*/0, /*#*/2, // selectBDXAddr20Only:$XBD2 #3 #4 #5
/*14485*/               OPC_EmitMergeInputChains1_1,
/*14486*/               OPC_MorphNodeTo, TARGET_VAL(SystemZ::CGH), 0|OPFL_Chain|OPFL_GlueOutput|OPFL_MemRefs,
                            1/*#VTs*/, MVT::i32, 4/*#Ops*/, 0, 3, 4, 5, 
                        // Src: (z_icmp GR64:i64:$R1, (ld:i64 bdxaddr20only:i64:$XBD2)<<P:Predicate_unindexedload>><<P:Predicate_asextload>><<P:Predicate_asextloadi16>>, (imm:i32))<<P:Predicate_z_scmp>> - Complexity = 23
                        // Dst: (CGH:i32 GR64:i64:$R1, bdxaddr20only:i64:$XBD2)
/*14497*/             /*Scope*/ 26, /*->14524*/
/*14498*/               OPC_CheckPredicate, 37, // Predicate_asextloadi32
/*14500*/               OPC_MoveParent,
/*14501*/               OPC_MoveChild, 2,
/*14503*/               OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*14506*/               OPC_MoveParent,
/*14507*/               OPC_CheckPredicate, 54, // Predicate_z_scmp
/*14509*/               OPC_CheckComplexPat, /*CP*/0, /*#*/2, // selectBDXAddr20Only:$XBD2 #3 #4 #5
/*14512*/               OPC_EmitMergeInputChains1_1,
/*14513*/               OPC_MorphNodeTo, TARGET_VAL(SystemZ::CGF), 0|OPFL_Chain|OPFL_GlueOutput|OPFL_MemRefs,
                            1/*#VTs*/, MVT::i32, 4/*#Ops*/, 0, 3, 4, 5, 
                        // Src: (z_icmp GR64:i64:$R1, (ld:i64 bdxaddr20only:i64:$XBD2)<<P:Predicate_unindexedload>><<P:Predicate_asextload>><<P:Predicate_asextloadi32>>, (imm:i32))<<P:Predicate_z_scmp>> - Complexity = 23
                        // Dst: (CGF:i32 GR64:i64:$R1, bdxaddr20only:i64:$XBD2)
/*14524*/             0, /*End of Scope*/
/*14525*/           /*Scope*/ 26, /*->14552*/
/*14526*/             OPC_CheckPredicate, 13, // Predicate_load
/*14528*/             OPC_MoveParent,
/*14529*/             OPC_MoveChild, 2,
/*14531*/             OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*14534*/             OPC_MoveParent,
/*14535*/             OPC_CheckPredicate, 54, // Predicate_z_scmp
/*14537*/             OPC_CheckComplexPat, /*CP*/0, /*#*/2, // selectBDXAddr20Only:$XBD2 #3 #4 #5
/*14540*/             OPC_EmitMergeInputChains1_1,
/*14541*/             OPC_MorphNodeTo, TARGET_VAL(SystemZ::CG), 0|OPFL_Chain|OPFL_GlueOutput|OPFL_MemRefs,
                          1/*#VTs*/, MVT::i32, 4/*#Ops*/, 0, 3, 4, 5, 
                      // Src: (z_icmp GR64:i64:$R1, (ld:i64 bdxaddr20only:i64:$XBD2)<<P:Predicate_unindexedload>><<P:Predicate_load>>, (imm:i32))<<P:Predicate_z_scmp>> - Complexity = 23
                      // Dst: (CG:i32 GR64:i64:$R1, bdxaddr20only:i64:$XBD2)
/*14552*/           /*Scope*/ 28, /*->14581*/
/*14553*/             OPC_CheckPredicate, 38, // Predicate_azextload
/*14555*/             OPC_CheckPredicate, 39, // Predicate_azextloadi32
/*14557*/             OPC_MoveParent,
/*14558*/             OPC_MoveChild, 2,
/*14560*/             OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*14563*/             OPC_MoveParent,
/*14564*/             OPC_CheckPredicate, 59, // Predicate_z_ucmp
/*14566*/             OPC_CheckComplexPat, /*CP*/0, /*#*/2, // selectBDXAddr20Only:$XBD2 #3 #4 #5
/*14569*/             OPC_EmitMergeInputChains1_1,
/*14570*/             OPC_MorphNodeTo, TARGET_VAL(SystemZ::CLGF), 0|OPFL_Chain|OPFL_GlueOutput|OPFL_MemRefs,
                          1/*#VTs*/, MVT::i32, 4/*#Ops*/, 0, 3, 4, 5, 
                      // Src: (z_icmp GR64:i64:$R1, (ld:i64 bdxaddr20only:i64:$XBD2)<<P:Predicate_unindexedload>><<P:Predicate_azextload>><<P:Predicate_azextloadi32>>, (imm:i32))<<P:Predicate_z_ucmp>> - Complexity = 23
                      // Dst: (CLGF:i32 GR64:i64:$R1, bdxaddr20only:i64:$XBD2)
/*14581*/           /*Scope*/ 26, /*->14608*/
/*14582*/             OPC_CheckPredicate, 13, // Predicate_load
/*14584*/             OPC_MoveParent,
/*14585*/             OPC_MoveChild, 2,
/*14587*/             OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*14590*/             OPC_MoveParent,
/*14591*/             OPC_CheckPredicate, 59, // Predicate_z_ucmp
/*14593*/             OPC_CheckComplexPat, /*CP*/0, /*#*/2, // selectBDXAddr20Only:$XBD2 #3 #4 #5
/*14596*/             OPC_EmitMergeInputChains1_1,
/*14597*/             OPC_MorphNodeTo, TARGET_VAL(SystemZ::CLG), 0|OPFL_Chain|OPFL_GlueOutput|OPFL_MemRefs,
                          1/*#VTs*/, MVT::i32, 4/*#Ops*/, 0, 3, 4, 5, 
                      // Src: (z_icmp GR64:i64:$R1, (ld:i64 bdxaddr20only:i64:$XBD2)<<P:Predicate_unindexedload>><<P:Predicate_load>>, (imm:i32))<<P:Predicate_z_ucmp>> - Complexity = 23
                      // Dst: (CLG:i32 GR64:i64:$R1, bdxaddr20only:i64:$XBD2)
/*14608*/           0, /*End of Scope*/
/*14609*/         /*Scope*/ 37, /*->14647*/
/*14610*/           OPC_CheckAndImm, 127|128,127|128,127|128,127|128,15/*4294967295*/, 
/*14616*/           OPC_RecordChild0, // #1 = $src2
/*14617*/           OPC_MoveParent,
/*14618*/           OPC_MoveChild, 2,
/*14620*/           OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*14623*/           OPC_MoveParent,
/*14624*/           OPC_CheckPredicate, 59, // Predicate_z_ucmp
/*14626*/           OPC_EmitInteger, MVT::i32, SystemZ::subreg_l32,
/*14629*/           OPC_EmitNode, TARGET_VAL(TargetOpcode::EXTRACT_SUBREG), 0,
                        1/*#VTs*/, MVT::i32, 2/*#Ops*/, 1, 2,  // Results = #3
/*14638*/           OPC_MorphNodeTo, TARGET_VAL(SystemZ::CLGFR), 0|OPFL_GlueOutput,
                        1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 3, 
                    // Src: (z_icmp GR64:i64:$src1, (and:i64 GR64:i64:$src2, 4294967295:i64), (imm:i32))<<P:Predicate_z_ucmp>> - Complexity = 15
                    // Dst: (CLGFR:i32 GR64:i64:$src1, (EXTRACT_SUBREG:i32 GR64:i64:$src2, subreg_l32:i32))
/*14647*/         0, /*End of Scope*/
/*14648*/       /*Scope*/ 86, /*->14735*/
/*14649*/         OPC_RecordChild1, // #1 = $I2
/*14650*/         OPC_MoveChild, 1,
/*14652*/         OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*14655*/         OPC_Scope, 25, /*->14682*/ // 3 children in Scope
/*14657*/           OPC_CheckPredicate, 32, // Predicate_imm64sx16
/*14659*/           OPC_MoveParent,
/*14660*/           OPC_MoveChild, 2,
/*14662*/           OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*14665*/           OPC_MoveParent,
/*14666*/           OPC_CheckPredicate, 54, // Predicate_z_scmp
/*14668*/           OPC_EmitConvertToTarget, 1,
/*14670*/           OPC_EmitNodeXForm, 2, 2, // SIMM16
/*14673*/           OPC_MorphNodeTo, TARGET_VAL(SystemZ::CGHI), 0|OPFL_GlueOutput,
                        1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 3, 
                    // Src: (z_icmp GR64:i64:$R1, (imm:i64)<<P:Predicate_imm64sx16>><<X:SIMM16>>:$I2, (imm:i32))<<P:Predicate_z_scmp>> - Complexity = 11
                    // Dst: (CGHI:i32 GR64:i64:$R1, (SIMM16:i64 (imm:i64):$I2))
/*14682*/         /*Scope*/ 25, /*->14708*/
/*14683*/           OPC_CheckPredicate, 63, // Predicate_imm64sx32
/*14685*/           OPC_MoveParent,
/*14686*/           OPC_MoveChild, 2,
/*14688*/           OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*14691*/           OPC_MoveParent,
/*14692*/           OPC_CheckPredicate, 54, // Predicate_z_scmp
/*14694*/           OPC_EmitConvertToTarget, 1,
/*14696*/           OPC_EmitNodeXForm, 11, 2, // SIMM32
/*14699*/           OPC_MorphNodeTo, TARGET_VAL(SystemZ::CGFI), 0|OPFL_GlueOutput,
                        1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 3, 
                    // Src: (z_icmp GR64:i64:$R1, (imm:i64)<<P:Predicate_imm64sx32>><<X:SIMM32>>:$I2, (imm:i32))<<P:Predicate_z_scmp>> - Complexity = 11
                    // Dst: (CGFI:i32 GR64:i64:$R1, (SIMM32:i64 (imm:i64):$I2))
/*14708*/         /*Scope*/ 25, /*->14734*/
/*14709*/           OPC_CheckPredicate, 64, // Predicate_imm64zx32
/*14711*/           OPC_MoveParent,
/*14712*/           OPC_MoveChild, 2,
/*14714*/           OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*14717*/           OPC_MoveParent,
/*14718*/           OPC_CheckPredicate, 59, // Predicate_z_ucmp
/*14720*/           OPC_EmitConvertToTarget, 1,
/*14722*/           OPC_EmitNodeXForm, 5, 2, // UIMM32
/*14725*/           OPC_MorphNodeTo, TARGET_VAL(SystemZ::CLGFI), 0|OPFL_GlueOutput,
                        1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 3, 
                    // Src: (z_icmp GR64:i64:$R1, (imm:i64)<<P:Predicate_imm64zx32>><<X:UIMM32>>:$I2, (imm:i32))<<P:Predicate_z_ucmp>> - Complexity = 11
                    // Dst: (CLGFI:i32 GR64:i64:$R1, (UIMM32:i64 (imm:i64):$I2))
/*14734*/         0, /*End of Scope*/
/*14735*/       0, /*End of Scope*/
/*14736*/     /*Scope*/ 24, /*->14761*/
/*14737*/       OPC_MoveChild, 1,
/*14739*/       OPC_CheckOpcode, TARGET_VAL(ISD::SIGN_EXTEND),
/*14742*/       OPC_RecordChild0, // #1 = $src2
/*14743*/       OPC_MoveParent,
/*14744*/       OPC_MoveChild, 2,
/*14746*/       OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*14749*/       OPC_MoveParent,
/*14750*/       OPC_CheckPredicate, 54, // Predicate_z_scmp
/*14752*/       OPC_MorphNodeTo, TARGET_VAL(SystemZ::CGFR), 0|OPFL_GlueOutput,
                    1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1, 
                // Src: (z_icmp GR64:i64:$src1, (sext:i64 GR32:i32:$src2), (imm:i32))<<P:Predicate_z_scmp>> - Complexity = 10
                // Dst: (CGFR:i32 GR64:i64:$src1, GR32:i32:$src2)
/*14761*/     /*Scope*/ 68, /*->14830*/
/*14762*/       OPC_CheckChild0Type, MVT::i32,
/*14764*/       OPC_RecordChild1, // #1 = $I2
/*14765*/       OPC_MoveChild, 1,
/*14767*/       OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*14770*/       OPC_MoveParent,
/*14771*/       OPC_MoveChild, 2,
/*14773*/       OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*14776*/       OPC_MoveParent,
/*14777*/       OPC_CheckPredicate, 59, // Predicate_z_ucmp
/*14779*/       OPC_Scope, 16, /*->14797*/ // 3 children in Scope
/*14781*/         OPC_CheckPatternPredicate, 0, // (Subtarget.hasHighWord())
/*14783*/         OPC_EmitConvertToTarget, 1,
/*14785*/         OPC_EmitNodeXForm, 5, 2, // UIMM32
/*14788*/         OPC_MorphNodeTo, TARGET_VAL(SystemZ::CLFIMux), 0|OPFL_GlueOutput,
                      1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 3, 
                  // Src: (z_icmp GRX32:i32:$R1, (imm:i32)<<X:UIMM32>>:$I2, (imm:i32))<<P:Predicate_z_ucmp>> - Complexity = 10
                  // Dst: (CLFIMux:i32 GRX32:i32:$R1, (UIMM32:i32 (imm:i32):$I2))
/*14797*/       /*Scope*/ 14, /*->14812*/
/*14798*/         OPC_EmitConvertToTarget, 1,
/*14800*/         OPC_EmitNodeXForm, 5, 2, // UIMM32
/*14803*/         OPC_MorphNodeTo, TARGET_VAL(SystemZ::CLFI), 0|OPFL_GlueOutput,
                      1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 3, 
                  // Src: (z_icmp GR32:i32:$R1, (imm:i32)<<X:UIMM32>>:$I2, (imm:i32))<<P:Predicate_z_ucmp>> - Complexity = 10
                  // Dst: (CLFI:i32 GR32:i32:$R1, (UIMM32:i32 (imm:i32):$I2))
/*14812*/       /*Scope*/ 16, /*->14829*/
/*14813*/         OPC_CheckPatternPredicate, 0, // (Subtarget.hasHighWord())
/*14815*/         OPC_EmitConvertToTarget, 1,
/*14817*/         OPC_EmitNodeXForm, 5, 2, // UIMM32
/*14820*/         OPC_MorphNodeTo, TARGET_VAL(SystemZ::CLIH), 0|OPFL_GlueOutput,
                      1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 3, 
                  // Src: (z_icmp GR32:i32:$R1, (imm:i32)<<X:UIMM32>>:$I2, (imm:i32))<<P:Predicate_z_ucmp>> - Complexity = 10
                  // Dst: (CLIH:i32 GR32:i32:$R1, (UIMM32:i32 (imm:i32):$I2))
/*14829*/       0, /*End of Scope*/
/*14830*/     /*Scope*/ 65, /*->14896*/
/*14831*/       OPC_MoveChild, 1,
/*14833*/       OPC_SwitchOpcode /*2 cases */, 19,  TARGET_VAL(ISD::ZERO_EXTEND),// ->14856
/*14837*/         OPC_RecordChild0, // #1 = $src2
/*14838*/         OPC_MoveParent,
/*14839*/         OPC_MoveChild, 2,
/*14841*/         OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*14844*/         OPC_MoveParent,
/*14845*/         OPC_CheckPredicate, 59, // Predicate_z_ucmp
/*14847*/         OPC_MorphNodeTo, TARGET_VAL(SystemZ::CLGFR), 0|OPFL_GlueOutput,
                      1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1, 
                  // Src: (z_icmp GR64:i64:$src1, (zext:i64 GR32:i32:$src2), (imm:i32))<<P:Predicate_z_ucmp>> - Complexity = 10
                  // Dst: (CLGFR:i32 GR64:i64:$src1, GR32:i32:$src2)
/*14856*/       /*SwitchOpcode*/ 36,  TARGET_VAL(ISD::SIGN_EXTEND_INREG),// ->14895
/*14859*/         OPC_RecordChild0, // #1 = $src2
/*14860*/         OPC_MoveChild, 1,
/*14862*/         OPC_CheckValueType, MVT::i32,
/*14864*/         OPC_MoveParent,
/*14865*/         OPC_MoveParent,
/*14866*/         OPC_MoveChild, 2,
/*14868*/         OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*14871*/         OPC_MoveParent,
/*14872*/         OPC_CheckPredicate, 54, // Predicate_z_scmp
/*14874*/         OPC_EmitInteger, MVT::i32, SystemZ::subreg_l32,
/*14877*/         OPC_EmitNode, TARGET_VAL(TargetOpcode::EXTRACT_SUBREG), 0,
                      1/*#VTs*/, MVT::i32, 2/*#Ops*/, 1, 2,  // Results = #3
/*14886*/         OPC_MorphNodeTo, TARGET_VAL(SystemZ::CGFR), 0|OPFL_GlueOutput,
                      1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 3, 
                  // Src: (z_icmp GR64:i64:$src1, (sext_inreg:i64 GR64:i64:$src2, i32:Other), (imm:i32))<<P:Predicate_z_scmp>> - Complexity = 10
                  // Dst: (CGFR:i32 GR64:i64:$src1, (EXTRACT_SUBREG:i32 GR64:i64:$src2, subreg_l32:i32))
/*14895*/       0, // EndSwitchOpcode
/*14896*/     /*Scope*/ 35, /*->14932*/
/*14897*/       OPC_CheckChild0Type, MVT::i32,
/*14899*/       OPC_RecordChild1, // #1 = $R2
/*14900*/       OPC_MoveChild, 2,
/*14902*/       OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*14905*/       OPC_MoveParent,
/*14906*/       OPC_Scope, 11, /*->14919*/ // 2 children in Scope
/*14908*/         OPC_CheckPredicate, 54, // Predicate_z_scmp
/*14910*/         OPC_MorphNodeTo, TARGET_VAL(SystemZ::CR), 0|OPFL_GlueOutput,
                      1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1, 
                  // Src: (z_icmp GR32:i32:$R1, GR32:i32:$R2, (imm:i32))<<P:Predicate_z_scmp>> - Complexity = 7
                  // Dst: (CR:i32 GR32:i32:$R1, GR32:i32:$R2)
/*14919*/       /*Scope*/ 11, /*->14931*/
/*14920*/         OPC_CheckPredicate, 59, // Predicate_z_ucmp
/*14922*/         OPC_MorphNodeTo, TARGET_VAL(SystemZ::CLR), 0|OPFL_GlueOutput,
                      1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1, 
                  // Src: (z_icmp GR32:i32:$R1, GR32:i32:$R2, (imm:i32))<<P:Predicate_z_ucmp>> - Complexity = 7
                  // Dst: (CLR:i32 GR32:i32:$R1, GR32:i32:$R2)
/*14931*/       0, /*End of Scope*/
/*14932*/     /*Scope*/ 35, /*->14968*/
/*14933*/       OPC_CheckChild0Type, MVT::i64,
/*14935*/       OPC_RecordChild1, // #1 = $R2
/*14936*/       OPC_MoveChild, 2,
/*14938*/       OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*14941*/       OPC_MoveParent,
/*14942*/       OPC_Scope, 11, /*->14955*/ // 2 children in Scope
/*14944*/         OPC_CheckPredicate, 54, // Predicate_z_scmp
/*14946*/         OPC_MorphNodeTo, TARGET_VAL(SystemZ::CGR), 0|OPFL_GlueOutput,
                      1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1, 
                  // Src: (z_icmp GR64:i64:$R1, GR64:i64:$R2, (imm:i32))<<P:Predicate_z_scmp>> - Complexity = 7
                  // Dst: (CGR:i32 GR64:i64:$R1, GR64:i64:$R2)
/*14955*/       /*Scope*/ 11, /*->14967*/
/*14956*/         OPC_CheckPredicate, 59, // Predicate_z_ucmp
/*14958*/         OPC_MorphNodeTo, TARGET_VAL(SystemZ::CLGR), 0|OPFL_GlueOutput,
                      1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1, 
                  // Src: (z_icmp GR64:i64:$R1, GR64:i64:$R2, (imm:i32))<<P:Predicate_z_ucmp>> - Complexity = 7
                  // Dst: (CLGR:i32 GR64:i64:$R1, GR64:i64:$R2)
/*14967*/       0, /*End of Scope*/
/*14968*/     0, /*End of Scope*/
/*14969*/   0, /*End of Scope*/
/*14970*/ /*SwitchOpcode*/ 34,  TARGET_VAL(SystemZISD::MVC),// ->15007
/*14973*/   OPC_RecordNode,   // #0 = 'z_mvc' chained node
/*14974*/   OPC_RecordChild1, // #1 = $dest
/*14975*/   OPC_CheckChild1Type, MVT::i64,
/*14977*/   OPC_RecordChild2, // #2 = $src
/*14978*/   OPC_CheckChild2Type, MVT::i64,
/*14980*/   OPC_RecordChild3, // #3 = $length
/*14981*/   OPC_MoveChild, 3,
/*14983*/   OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*14986*/   OPC_MoveParent,
/*14987*/   OPC_CheckComplexPat, /*CP*/1, /*#*/1, // selectBDAddr12Only:$dest #4 #5
/*14990*/   OPC_CheckComplexPat, /*CP*/1, /*#*/2, // selectBDAddr12Only:$src #6 #7
/*14993*/   OPC_EmitMergeInputChains1_0,
/*14994*/   OPC_EmitConvertToTarget, 3,
/*14996*/   OPC_MorphNodeTo, TARGET_VAL(SystemZ::MVCSequence), 0|OPFL_Chain,
                0/*#VTs*/, 5/*#Ops*/, 4, 5, 6, 7, 8, 
            // Src: (z_mvc bdaddr12only:i64:$dest, bdaddr12only:i64:$src, (imm:i64):$length) - Complexity = 24
            // Dst: (MVCSequence bdaddr12only:i64:$dest, bdaddr12only:i64:$src, (imm:i64):$length)
/*15007*/ /*SwitchOpcode*/ 36,  TARGET_VAL(SystemZISD::MVC_LOOP),// ->15046
/*15010*/   OPC_RecordNode,   // #0 = 'z_mvc_loop' chained node
/*15011*/   OPC_RecordChild1, // #1 = $dest
/*15012*/   OPC_CheckChild1Type, MVT::i64,
/*15014*/   OPC_RecordChild2, // #2 = $src
/*15015*/   OPC_CheckChild2Type, MVT::i64,
/*15017*/   OPC_RecordChild3, // #3 = $length
/*15018*/   OPC_MoveChild, 3,
/*15020*/   OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*15023*/   OPC_MoveParent,
/*15024*/   OPC_RecordChild4, // #4 = $count256
/*15025*/   OPC_CheckComplexPat, /*CP*/1, /*#*/1, // selectBDAddr12Only:$dest #5 #6
/*15028*/   OPC_CheckComplexPat, /*CP*/1, /*#*/2, // selectBDAddr12Only:$src #7 #8
/*15031*/   OPC_EmitMergeInputChains1_0,
/*15032*/   OPC_EmitConvertToTarget, 3,
/*15034*/   OPC_MorphNodeTo, TARGET_VAL(SystemZ::MVCLoop), 0|OPFL_Chain,
                0/*#VTs*/, 6/*#Ops*/, 5, 6, 7, 8, 9, 4, 
            // Src: (z_mvc_loop bdaddr12only:i64:$dest, bdaddr12only:i64:$src, (imm:i64):$length, GR64:i64:$count256) - Complexity = 24
            // Dst: (MVCLoop bdaddr12only:i64:$dest, bdaddr12only:i64:$src, (imm:i64):$length, GR64:i64:$count256)
/*15046*/ /*SwitchOpcode*/ 35,  TARGET_VAL(SystemZISD::NC),// ->15084
/*15049*/   OPC_RecordNode,   // #0 = 'z_nc' chained node
/*15050*/   OPC_RecordChild1, // #1 = $dest
/*15051*/   OPC_CheckChild1Type, MVT::i64,
/*15053*/   OPC_RecordChild2, // #2 = $src
/*15054*/   OPC_CheckChild2Type, MVT::i64,
/*15056*/   OPC_RecordChild3, // #3 = $length
/*15057*/   OPC_MoveChild, 3,
/*15059*/   OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*15062*/   OPC_MoveParent,
/*15063*/   OPC_CheckComplexPat, /*CP*/1, /*#*/1, // selectBDAddr12Only:$dest #4 #5
/*15066*/   OPC_CheckComplexPat, /*CP*/1, /*#*/2, // selectBDAddr12Only:$src #6 #7
/*15069*/   OPC_EmitMergeInputChains1_0,
/*15070*/   OPC_EmitConvertToTarget, 3,
/*15072*/   OPC_MorphNodeTo, TARGET_VAL(SystemZ::NCSequence), 0|OPFL_Chain,
                1/*#VTs*/, MVT::i32, 5/*#Ops*/, 4, 5, 6, 7, 8, 
            // Src: (z_nc bdaddr12only:i64:$dest, bdaddr12only:i64:$src, (imm:i64):$length) - Complexity = 24
            // Dst: (NCSequence:i32 bdaddr12only:i64:$dest, bdaddr12only:i64:$src, (imm:i64):$length)
/*15084*/ /*SwitchOpcode*/ 37,  TARGET_VAL(SystemZISD::NC_LOOP),// ->15124
/*15087*/   OPC_RecordNode,   // #0 = 'z_nc_loop' chained node
/*15088*/   OPC_RecordChild1, // #1 = $dest
/*15089*/   OPC_CheckChild1Type, MVT::i64,
/*15091*/   OPC_RecordChild2, // #2 = $src
/*15092*/   OPC_CheckChild2Type, MVT::i64,
/*15094*/   OPC_RecordChild3, // #3 = $length
/*15095*/   OPC_MoveChild, 3,
/*15097*/   OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*15100*/   OPC_MoveParent,
/*15101*/   OPC_RecordChild4, // #4 = $count256
/*15102*/   OPC_CheckComplexPat, /*CP*/1, /*#*/1, // selectBDAddr12Only:$dest #5 #6
/*15105*/   OPC_CheckComplexPat, /*CP*/1, /*#*/2, // selectBDAddr12Only:$src #7 #8
/*15108*/   OPC_EmitMergeInputChains1_0,
/*15109*/   OPC_EmitConvertToTarget, 3,
/*15111*/   OPC_MorphNodeTo, TARGET_VAL(SystemZ::NCLoop), 0|OPFL_Chain,
                1/*#VTs*/, MVT::i32, 6/*#Ops*/, 5, 6, 7, 8, 9, 4, 
            // Src: (z_nc_loop bdaddr12only:i64:$dest, bdaddr12only:i64:$src, (imm:i64):$length, GR64:i64:$count256) - Complexity = 24
            // Dst: (NCLoop:i32 bdaddr12only:i64:$dest, bdaddr12only:i64:$src, (imm:i64):$length, GR64:i64:$count256)
/*15124*/ /*SwitchOpcode*/ 35,  TARGET_VAL(SystemZISD::OC),// ->15162
/*15127*/   OPC_RecordNode,   // #0 = 'z_oc' chained node
/*15128*/   OPC_RecordChild1, // #1 = $dest
/*15129*/   OPC_CheckChild1Type, MVT::i64,
/*15131*/   OPC_RecordChild2, // #2 = $src
/*15132*/   OPC_CheckChild2Type, MVT::i64,
/*15134*/   OPC_RecordChild3, // #3 = $length
/*15135*/   OPC_MoveChild, 3,
/*15137*/   OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*15140*/   OPC_MoveParent,
/*15141*/   OPC_CheckComplexPat, /*CP*/1, /*#*/1, // selectBDAddr12Only:$dest #4 #5
/*15144*/   OPC_CheckComplexPat, /*CP*/1, /*#*/2, // selectBDAddr12Only:$src #6 #7
/*15147*/   OPC_EmitMergeInputChains1_0,
/*15148*/   OPC_EmitConvertToTarget, 3,
/*15150*/   OPC_MorphNodeTo, TARGET_VAL(SystemZ::OCSequence), 0|OPFL_Chain,
                1/*#VTs*/, MVT::i32, 5/*#Ops*/, 4, 5, 6, 7, 8, 
            // Src: (z_oc bdaddr12only:i64:$dest, bdaddr12only:i64:$src, (imm:i64):$length) - Complexity = 24
            // Dst: (OCSequence:i32 bdaddr12only:i64:$dest, bdaddr12only:i64:$src, (imm:i64):$length)
/*15162*/ /*SwitchOpcode*/ 37,  TARGET_VAL(SystemZISD::OC_LOOP),// ->15202
/*15165*/   OPC_RecordNode,   // #0 = 'z_oc_loop' chained node
/*15166*/   OPC_RecordChild1, // #1 = $dest
/*15167*/   OPC_CheckChild1Type, MVT::i64,
/*15169*/   OPC_RecordChild2, // #2 = $src
/*15170*/   OPC_CheckChild2Type, MVT::i64,
/*15172*/   OPC_RecordChild3, // #3 = $length
/*15173*/   OPC_MoveChild, 3,
/*15175*/   OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*15178*/   OPC_MoveParent,
/*15179*/   OPC_RecordChild4, // #4 = $count256
/*15180*/   OPC_CheckComplexPat, /*CP*/1, /*#*/1, // selectBDAddr12Only:$dest #5 #6
/*15183*/   OPC_CheckComplexPat, /*CP*/1, /*#*/2, // selectBDAddr12Only:$src #7 #8
/*15186*/   OPC_EmitMergeInputChains1_0,
/*15187*/   OPC_EmitConvertToTarget, 3,
/*15189*/   OPC_MorphNodeTo, TARGET_VAL(SystemZ::OCLoop), 0|OPFL_Chain,
                1/*#VTs*/, MVT::i32, 6/*#Ops*/, 5, 6, 7, 8, 9, 4, 
            // Src: (z_oc_loop bdaddr12only:i64:$dest, bdaddr12only:i64:$src, (imm:i64):$length, GR64:i64:$count256) - Complexity = 24
            // Dst: (OCLoop:i32 bdaddr12only:i64:$dest, bdaddr12only:i64:$src, (imm:i64):$length, GR64:i64:$count256)
/*15202*/ /*SwitchOpcode*/ 35,  TARGET_VAL(SystemZISD::XC),// ->15240
/*15205*/   OPC_RecordNode,   // #0 = 'z_xc' chained node
/*15206*/   OPC_RecordChild1, // #1 = $dest
/*15207*/   OPC_CheckChild1Type, MVT::i64,
/*15209*/   OPC_RecordChild2, // #2 = $src
/*15210*/   OPC_CheckChild2Type, MVT::i64,
/*15212*/   OPC_RecordChild3, // #3 = $length
/*15213*/   OPC_MoveChild, 3,
/*15215*/   OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*15218*/   OPC_MoveParent,
/*15219*/   OPC_CheckComplexPat, /*CP*/1, /*#*/1, // selectBDAddr12Only:$dest #4 #5
/*15222*/   OPC_CheckComplexPat, /*CP*/1, /*#*/2, // selectBDAddr12Only:$src #6 #7
/*15225*/   OPC_EmitMergeInputChains1_0,
/*15226*/   OPC_EmitConvertToTarget, 3,
/*15228*/   OPC_MorphNodeTo, TARGET_VAL(SystemZ::XCSequence), 0|OPFL_Chain,
                1/*#VTs*/, MVT::i32, 5/*#Ops*/, 4, 5, 6, 7, 8, 
            // Src: (z_xc bdaddr12only:i64:$dest, bdaddr12only:i64:$src, (imm:i64):$length) - Complexity = 24
            // Dst: (XCSequence:i32 bdaddr12only:i64:$dest, bdaddr12only:i64:$src, (imm:i64):$length)
/*15240*/ /*SwitchOpcode*/ 37,  TARGET_VAL(SystemZISD::XC_LOOP),// ->15280
/*15243*/   OPC_RecordNode,   // #0 = 'z_xc_loop' chained node
/*15244*/   OPC_RecordChild1, // #1 = $dest
/*15245*/   OPC_CheckChild1Type, MVT::i64,
/*15247*/   OPC_RecordChild2, // #2 = $src
/*15248*/   OPC_CheckChild2Type, MVT::i64,
/*15250*/   OPC_RecordChild3, // #3 = $length
/*15251*/   OPC_MoveChild, 3,
/*15253*/   OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*15256*/   OPC_MoveParent,
/*15257*/   OPC_RecordChild4, // #4 = $count256
/*15258*/   OPC_CheckComplexPat, /*CP*/1, /*#*/1, // selectBDAddr12Only:$dest #5 #6
/*15261*/   OPC_CheckComplexPat, /*CP*/1, /*#*/2, // selectBDAddr12Only:$src #7 #8
/*15264*/   OPC_EmitMergeInputChains1_0,
/*15265*/   OPC_EmitConvertToTarget, 3,
/*15267*/   OPC_MorphNodeTo, TARGET_VAL(SystemZ::XCLoop), 0|OPFL_Chain,
                1/*#VTs*/, MVT::i32, 6/*#Ops*/, 5, 6, 7, 8, 9, 4, 
            // Src: (z_xc_loop bdaddr12only:i64:$dest, bdaddr12only:i64:$src, (imm:i64):$length, GR64:i64:$count256) - Complexity = 24
            // Dst: (XCLoop:i32 bdaddr12only:i64:$dest, bdaddr12only:i64:$src, (imm:i64):$length, GR64:i64:$count256)
/*15280*/ /*SwitchOpcode*/ 35,  TARGET_VAL(SystemZISD::CLC),// ->15318
/*15283*/   OPC_RecordNode,   // #0 = 'z_clc' chained node
/*15284*/   OPC_RecordChild1, // #1 = $dest
/*15285*/   OPC_CheckChild1Type, MVT::i64,
/*15287*/   OPC_RecordChild2, // #2 = $src
/*15288*/   OPC_CheckChild2Type, MVT::i64,
/*15290*/   OPC_RecordChild3, // #3 = $length
/*15291*/   OPC_MoveChild, 3,
/*15293*/   OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*15296*/   OPC_MoveParent,
/*15297*/   OPC_CheckComplexPat, /*CP*/1, /*#*/1, // selectBDAddr12Only:$dest #4 #5
/*15300*/   OPC_CheckComplexPat, /*CP*/1, /*#*/2, // selectBDAddr12Only:$src #6 #7
/*15303*/   OPC_EmitMergeInputChains1_0,
/*15304*/   OPC_EmitConvertToTarget, 3,
/*15306*/   OPC_MorphNodeTo, TARGET_VAL(SystemZ::CLCSequence), 0|OPFL_Chain|OPFL_GlueOutput,
                1/*#VTs*/, MVT::i32, 5/*#Ops*/, 4, 5, 6, 7, 8, 
            // Src: (z_clc bdaddr12only:i64:$dest, bdaddr12only:i64:$src, (imm:i64):$length) - Complexity = 24
            // Dst: (CLCSequence:i32 bdaddr12only:i64:$dest, bdaddr12only:i64:$src, (imm:i64):$length)
/*15318*/ /*SwitchOpcode*/ 37,  TARGET_VAL(SystemZISD::CLC_LOOP),// ->15358
/*15321*/   OPC_RecordNode,   // #0 = 'z_clc_loop' chained node
/*15322*/   OPC_RecordChild1, // #1 = $dest
/*15323*/   OPC_CheckChild1Type, MVT::i64,
/*15325*/   OPC_RecordChild2, // #2 = $src
/*15326*/   OPC_CheckChild2Type, MVT::i64,
/*15328*/   OPC_RecordChild3, // #3 = $length
/*15329*/   OPC_MoveChild, 3,
/*15331*/   OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*15334*/   OPC_MoveParent,
/*15335*/   OPC_RecordChild4, // #4 = $count256
/*15336*/   OPC_CheckComplexPat, /*CP*/1, /*#*/1, // selectBDAddr12Only:$dest #5 #6
/*15339*/   OPC_CheckComplexPat, /*CP*/1, /*#*/2, // selectBDAddr12Only:$src #7 #8
/*15342*/   OPC_EmitMergeInputChains1_0,
/*15343*/   OPC_EmitConvertToTarget, 3,
/*15345*/   OPC_MorphNodeTo, TARGET_VAL(SystemZ::CLCLoop), 0|OPFL_Chain|OPFL_GlueOutput,
                1/*#VTs*/, MVT::i32, 6/*#Ops*/, 5, 6, 7, 8, 9, 4, 
            // Src: (z_clc_loop bdaddr12only:i64:$dest, bdaddr12only:i64:$src, (imm:i64):$length, GR64:i64:$count256) - Complexity = 24
            // Dst: (CLCLoop:i32 bdaddr12only:i64:$dest, bdaddr12only:i64:$src, (imm:i64):$length, GR64:i64:$count256)
/*15358*/ /*SwitchOpcode*/ 48,  TARGET_VAL(SystemZISD::PREFETCH),// ->15409
/*15361*/   OPC_RecordMemRef,
/*15362*/   OPC_RecordNode,   // #0 = 'z_prefetch' chained node
/*15363*/   OPC_RecordChild1, // #1 = $R1
/*15364*/   OPC_MoveChild, 1,
/*15366*/   OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*15369*/   OPC_CheckPredicate, 4, // Predicate_uimm8zx4
/*15371*/   OPC_MoveParent,
/*15372*/   OPC_RecordChild2, // #2 = $I2
/*15373*/   OPC_CheckChild2Type, MVT::i64,
/*15375*/   OPC_Scope, 14, /*->15391*/ // 2 children in Scope
/*15377*/     OPC_CheckComplexPat, /*CP*/5, /*#*/2, // selectPCRelAddress:$I2 #3
/*15380*/     OPC_EmitMergeInputChains1_0,
/*15381*/     OPC_EmitConvertToTarget, 1,
/*15383*/     OPC_MorphNodeTo, TARGET_VAL(SystemZ::PFDRL), 0|OPFL_Chain|OPFL_MemRefs,
                  0/*#VTs*/, 2/*#Ops*/, 4, 3, 
              // Src: (z_prefetch (imm:i8)<<P:Predicate_uimm8zx4>>:$R1, pcrel32:i64:$I2) - Complexity = 20
              // Dst: (PFDRL (imm:i8):$R1, pcrel32:i64:$I2)
/*15391*/   /*Scope*/ 16, /*->15408*/
/*15392*/     OPC_CheckComplexPat, /*CP*/0, /*#*/2, // selectBDXAddr20Only:$XBD2 #3 #4 #5
/*15395*/     OPC_EmitMergeInputChains1_0,
/*15396*/     OPC_EmitConvertToTarget, 1,
/*15398*/     OPC_MorphNodeTo, TARGET_VAL(SystemZ::PFD), 0|OPFL_Chain|OPFL_MemRefs,
                  0/*#VTs*/, 4/*#Ops*/, 6, 3, 4, 5, 
              // Src: (z_prefetch (imm:i8)<<P:Predicate_uimm8zx4>>:$R1, bdxaddr20only:i64:$XBD2) - Complexity = 19
              // Dst: (PFD (imm:i8):$R1, bdxaddr20only:i64:$XBD2)
/*15408*/   0, /*End of Scope*/
/*15409*/ /*SwitchOpcode*/ 78,  TARGET_VAL(ISD::BSWAP),// ->15490
/*15412*/   OPC_Scope, 51, /*->15465*/ // 2 children in Scope
/*15414*/     OPC_MoveChild, 0,
/*15416*/     OPC_CheckOpcode, TARGET_VAL(ISD::LOAD),
/*15419*/     OPC_RecordMemRef,
/*15420*/     OPC_RecordNode, // #0 = 'ld' chained node
/*15421*/     OPC_RecordChild1, // #1 = $XBD2
/*15422*/     OPC_CheckChild1Type, MVT::i64,
/*15424*/     OPC_CheckPredicate, 0, // Predicate_unindexedload
/*15426*/     OPC_CheckPredicate, 13, // Predicate_load
/*15428*/     OPC_CheckPredicate, 14, // Predicate_nonvolatile_load
/*15430*/     OPC_MoveParent,
/*15431*/     OPC_SwitchType /*2 cases */, 14,  MVT::i32,// ->15448
/*15434*/       OPC_CheckComplexPat, /*CP*/0, /*#*/1, // selectBDXAddr20Only:$XBD2 #2 #3 #4
/*15437*/       OPC_EmitMergeInputChains1_0,
/*15438*/       OPC_MorphNodeTo, TARGET_VAL(SystemZ::LRV), 0|OPFL_Chain|OPFL_MemRefs,
                    1/*#VTs*/, MVT::i32, 3/*#Ops*/, 2, 3, 4, 
                // Src: (bswap:i32 (ld:i32 bdxaddr20only:i64:$XBD2)<<P:Predicate_unindexedload>><<P:Predicate_load>><<P:Predicate_nonvolatile_load>>) - Complexity = 19
                // Dst: (LRV:i32 bdxaddr20only:i64:$XBD2)
/*15448*/     /*SwitchType*/ 14,  MVT::i64,// ->15464
/*15450*/       OPC_CheckComplexPat, /*CP*/0, /*#*/1, // selectBDXAddr20Only:$XBD2 #2 #3 #4
/*15453*/       OPC_EmitMergeInputChains1_0,
/*15454*/       OPC_MorphNodeTo, TARGET_VAL(SystemZ::LRVG), 0|OPFL_Chain|OPFL_MemRefs,
                    1/*#VTs*/, MVT::i64, 3/*#Ops*/, 2, 3, 4, 
                // Src: (bswap:i64 (ld:i64 bdxaddr20only:i64:$XBD2)<<P:Predicate_unindexedload>><<P:Predicate_load>><<P:Predicate_nonvolatile_load>>) - Complexity = 19
                // Dst: (LRVG:i64 bdxaddr20only:i64:$XBD2)
/*15464*/     0, // EndSwitchType
/*15465*/   /*Scope*/ 23, /*->15489*/
/*15466*/     OPC_RecordChild0, // #0 = $R2
/*15467*/     OPC_SwitchType /*2 cases */, 8,  MVT::i32,// ->15478
/*15470*/       OPC_MorphNodeTo, TARGET_VAL(SystemZ::LRVR), 0,
                    1/*#VTs*/, MVT::i32, 1/*#Ops*/, 0, 
                // Src: (bswap:i32 GR32:i32:$R2) - Complexity = 3
                // Dst: (LRVR:i32 GR32:i32:$R2)
/*15478*/     /*SwitchType*/ 8,  MVT::i64,// ->15488
/*15480*/       OPC_MorphNodeTo, TARGET_VAL(SystemZ::LRVGR), 0,
                    1/*#VTs*/, MVT::i64, 1/*#Ops*/, 0, 
                // Src: (bswap:i64 GR64:i64:$R2) - Complexity = 3
                // Dst: (LRVGR:i64 GR64:i64:$R2)
/*15488*/     0, // EndSwitchType
/*15489*/   0, /*End of Scope*/
/*15490*/ /*SwitchOpcode*/ 78|128,6/*846*/,  TARGET_VAL(ISD::ADD),// ->16340
/*15494*/   OPC_Scope, 44|128,1/*172*/, /*->15669*/ // 10 children in Scope
/*15497*/     OPC_RecordChild0, // #0 = $R1src
/*15498*/     OPC_MoveChild, 1,
/*15500*/     OPC_CheckOpcode, TARGET_VAL(ISD::LOAD),
/*15503*/     OPC_RecordMemRef,
/*15504*/     OPC_RecordNode, // #1 = 'ld' chained node
/*15505*/     OPC_CheckFoldableChainNode,
/*15506*/     OPC_RecordChild1, // #2 = $XBD2
/*15507*/     OPC_CheckChild1Type, MVT::i64,
/*15509*/     OPC_CheckPredicate, 0, // Predicate_unindexedload
/*15511*/     OPC_Scope, 43, /*->15556*/ // 5 children in Scope
/*15513*/       OPC_CheckPredicate, 35, // Predicate_asextload
/*15515*/       OPC_CheckPredicate, 36, // Predicate_asextloadi16
/*15517*/       OPC_MoveParent,
/*15518*/       OPC_CheckType, MVT::i32,
/*15520*/       OPC_Scope, 16, /*->15538*/ // 2 children in Scope
/*15522*/         OPC_CheckComplexPat, /*CP*/7, /*#*/2, // selectBDXAddr12Pair:$XBD2 #3 #4 #5
/*15525*/         OPC_EmitMergeInputChains1_1,
/*15526*/         OPC_MorphNodeTo, TARGET_VAL(SystemZ::AH), 0|OPFL_Chain|OPFL_MemRefs,
                      2/*#VTs*/, MVT::i32, MVT::i32, 4/*#Ops*/, 0, 3, 4, 5, 
                  // Src: (add:i32 GR32:i32:$R1src, (ld:i32 bdxaddr12pair:i64:$XBD2)<<P:Predicate_unindexedload>><<P:Predicate_asextload>><<P:Predicate_asextloadi16>>) - Complexity = 19
                  // Dst: (AH:i32:i32 GR32:i32:$R1src, bdxaddr12pair:i64:$XBD2)
/*15538*/       /*Scope*/ 16, /*->15555*/
/*15539*/         OPC_CheckComplexPat, /*CP*/8, /*#*/2, // selectBDXAddr20Pair:$XBD2 #3 #4 #5
/*15542*/         OPC_EmitMergeInputChains1_1,
/*15543*/         OPC_MorphNodeTo, TARGET_VAL(SystemZ::AHY), 0|OPFL_Chain|OPFL_MemRefs,
                      2/*#VTs*/, MVT::i32, MVT::i32, 4/*#Ops*/, 0, 3, 4, 5, 
                  // Src: (add:i32 GR32:i32:$R1src, (ld:i32 bdxaddr20pair:i64:$XBD2)<<P:Predicate_unindexedload>><<P:Predicate_asextload>><<P:Predicate_asextloadi16>>) - Complexity = 19
                  // Dst: (AHY:i32:i32 GR32:i32:$R1src, bdxaddr20pair:i64:$XBD2)
/*15555*/       0, /*End of Scope*/
/*15556*/     /*Scope*/ 41, /*->15598*/
/*15557*/       OPC_CheckPredicate, 13, // Predicate_load
/*15559*/       OPC_MoveParent,
/*15560*/       OPC_CheckType, MVT::i32,
/*15562*/       OPC_Scope, 16, /*->15580*/ // 2 children in Scope
/*15564*/         OPC_CheckComplexPat, /*CP*/7, /*#*/2, // selectBDXAddr12Pair:$XBD2 #3 #4 #5
/*15567*/         OPC_EmitMergeInputChains1_1,
/*15568*/         OPC_MorphNodeTo, TARGET_VAL(SystemZ::A), 0|OPFL_Chain|OPFL_MemRefs,
                      2/*#VTs*/, MVT::i32, MVT::i32, 4/*#Ops*/, 0, 3, 4, 5, 
                  // Src: (add:i32 GR32:i32:$R1src, (ld:i32 bdxaddr12pair:i64:$XBD2)<<P:Predicate_unindexedload>><<P:Predicate_load>>) - Complexity = 19
                  // Dst: (A:i32:i32 GR32:i32:$R1src, bdxaddr12pair:i64:$XBD2)
/*15580*/       /*Scope*/ 16, /*->15597*/
/*15581*/         OPC_CheckComplexPat, /*CP*/8, /*#*/2, // selectBDXAddr20Pair:$XBD2 #3 #4 #5
/*15584*/         OPC_EmitMergeInputChains1_1,
/*15585*/         OPC_MorphNodeTo, TARGET_VAL(SystemZ::AY), 0|OPFL_Chain|OPFL_MemRefs,
                      2/*#VTs*/, MVT::i32, MVT::i32, 4/*#Ops*/, 0, 3, 4, 5, 
                  // Src: (add:i32 GR32:i32:$R1src, (ld:i32 bdxaddr20pair:i64:$XBD2)<<P:Predicate_unindexedload>><<P:Predicate_load>>) - Complexity = 19
                  // Dst: (AY:i32:i32 GR32:i32:$R1src, bdxaddr20pair:i64:$XBD2)
/*15597*/       0, /*End of Scope*/
/*15598*/     /*Scope*/ 23, /*->15622*/
/*15599*/       OPC_CheckPredicate, 35, // Predicate_asextload
/*15601*/       OPC_CheckPredicate, 37, // Predicate_asextloadi32
/*15603*/       OPC_MoveParent,
/*15604*/       OPC_CheckType, MVT::i64,
/*15606*/       OPC_CheckComplexPat, /*CP*/0, /*#*/2, // selectBDXAddr20Only:$XBD2 #3 #4 #5
/*15609*/       OPC_EmitMergeInputChains1_1,
/*15610*/       OPC_MorphNodeTo, TARGET_VAL(SystemZ::AGF), 0|OPFL_Chain|OPFL_MemRefs,
                    2/*#VTs*/, MVT::i64, MVT::i32, 4/*#Ops*/, 0, 3, 4, 5, 
                // Src: (add:i64 GR64:i64:$R1src, (ld:i64 bdxaddr20only:i64:$XBD2)<<P:Predicate_unindexedload>><<P:Predicate_asextload>><<P:Predicate_asextloadi32>>) - Complexity = 19
                // Dst: (AGF:i64:i32 GR64:i64:$R1src, bdxaddr20only:i64:$XBD2)
/*15622*/     /*Scope*/ 21, /*->15644*/
/*15623*/       OPC_CheckPredicate, 13, // Predicate_load
/*15625*/       OPC_MoveParent,
/*15626*/       OPC_CheckType, MVT::i64,
/*15628*/       OPC_CheckComplexPat, /*CP*/0, /*#*/2, // selectBDXAddr20Only:$XBD2 #3 #4 #5
/*15631*/       OPC_EmitMergeInputChains1_1,
/*15632*/       OPC_MorphNodeTo, TARGET_VAL(SystemZ::AG), 0|OPFL_Chain|OPFL_MemRefs,
                    2/*#VTs*/, MVT::i64, MVT::i32, 4/*#Ops*/, 0, 3, 4, 5, 
                // Src: (add:i64 GR64:i64:$R1src, (ld:i64 bdxaddr20only:i64:$XBD2)<<P:Predicate_unindexedload>><<P:Predicate_load>>) - Complexity = 19
                // Dst: (AG:i64:i32 GR64:i64:$R1src, bdxaddr20only:i64:$XBD2)
/*15644*/     /*Scope*/ 23, /*->15668*/
/*15645*/       OPC_CheckPredicate, 38, // Predicate_azextload
/*15647*/       OPC_CheckPredicate, 39, // Predicate_azextloadi32
/*15649*/       OPC_MoveParent,
/*15650*/       OPC_CheckType, MVT::i64,
/*15652*/       OPC_CheckComplexPat, /*CP*/0, /*#*/2, // selectBDXAddr20Only:$addr #3 #4 #5
/*15655*/       OPC_EmitMergeInputChains1_1,
/*15656*/       OPC_MorphNodeTo, TARGET_VAL(SystemZ::ALGF), 0|OPFL_Chain|OPFL_MemRefs,
                    2/*#VTs*/, MVT::i64, MVT::i32, 4/*#Ops*/, 0, 3, 4, 5, 
                // Src: (add:i64 GR64:i64:$src1, (ld:i64 bdxaddr20only:i64:$addr)<<P:Predicate_unindexedload>><<P:Predicate_azextload>><<P:Predicate_azextloadi32>>) - Complexity = 19
                // Dst: (ALGF:i64:i32 GR64:i64:$src1, bdxaddr20only:i64:$addr)
/*15668*/     0, /*End of Scope*/
/*15669*/   /*Scope*/ 48|128,1/*176*/, /*->15847*/
/*15671*/     OPC_MoveChild, 0,
/*15673*/     OPC_CheckOpcode, TARGET_VAL(ISD::LOAD),
/*15676*/     OPC_RecordMemRef,
/*15677*/     OPC_RecordNode, // #0 = 'ld' chained node
/*15678*/     OPC_CheckFoldableChainNode,
/*15679*/     OPC_RecordChild1, // #1 = $XBD2
/*15680*/     OPC_CheckChild1Type, MVT::i64,
/*15682*/     OPC_CheckPredicate, 0, // Predicate_unindexedload
/*15684*/     OPC_Scope, 44, /*->15730*/ // 5 children in Scope
/*15686*/       OPC_CheckPredicate, 35, // Predicate_asextload
/*15688*/       OPC_CheckPredicate, 36, // Predicate_asextloadi16
/*15690*/       OPC_MoveParent,
/*15691*/       OPC_RecordChild1, // #2 = $R1src
/*15692*/       OPC_CheckType, MVT::i32,
/*15694*/       OPC_Scope, 16, /*->15712*/ // 2 children in Scope
/*15696*/         OPC_CheckComplexPat, /*CP*/7, /*#*/1, // selectBDXAddr12Pair:$XBD2 #3 #4 #5
/*15699*/         OPC_EmitMergeInputChains1_0,
/*15700*/         OPC_MorphNodeTo, TARGET_VAL(SystemZ::AH), 0|OPFL_Chain|OPFL_MemRefs,
                      2/*#VTs*/, MVT::i32, MVT::i32, 4/*#Ops*/, 2, 3, 4, 5, 
                  // Src: (add:i32 (ld:i32 bdxaddr12pair:i64:$XBD2)<<P:Predicate_unindexedload>><<P:Predicate_asextload>><<P:Predicate_asextloadi16>>, GR32:i32:$R1src) - Complexity = 19
                  // Dst: (AH:i32:i32 GR32:i32:$R1src, bdxaddr12pair:i64:$XBD2)
/*15712*/       /*Scope*/ 16, /*->15729*/
/*15713*/         OPC_CheckComplexPat, /*CP*/8, /*#*/1, // selectBDXAddr20Pair:$XBD2 #3 #4 #5
/*15716*/         OPC_EmitMergeInputChains1_0,
/*15717*/         OPC_MorphNodeTo, TARGET_VAL(SystemZ::AHY), 0|OPFL_Chain|OPFL_MemRefs,
                      2/*#VTs*/, MVT::i32, MVT::i32, 4/*#Ops*/, 2, 3, 4, 5, 
                  // Src: (add:i32 (ld:i32 bdxaddr20pair:i64:$XBD2)<<P:Predicate_unindexedload>><<P:Predicate_asextload>><<P:Predicate_asextloadi16>>, GR32:i32:$R1src) - Complexity = 19
                  // Dst: (AHY:i32:i32 GR32:i32:$R1src, bdxaddr20pair:i64:$XBD2)
/*15729*/       0, /*End of Scope*/
/*15730*/     /*Scope*/ 42, /*->15773*/
/*15731*/       OPC_CheckPredicate, 13, // Predicate_load
/*15733*/       OPC_MoveParent,
/*15734*/       OPC_RecordChild1, // #2 = $R1src
/*15735*/       OPC_CheckType, MVT::i32,
/*15737*/       OPC_Scope, 16, /*->15755*/ // 2 children in Scope
/*15739*/         OPC_CheckComplexPat, /*CP*/7, /*#*/1, // selectBDXAddr12Pair:$XBD2 #3 #4 #5
/*15742*/         OPC_EmitMergeInputChains1_0,
/*15743*/         OPC_MorphNodeTo, TARGET_VAL(SystemZ::A), 0|OPFL_Chain|OPFL_MemRefs,
                      2/*#VTs*/, MVT::i32, MVT::i32, 4/*#Ops*/, 2, 3, 4, 5, 
                  // Src: (add:i32 (ld:i32 bdxaddr12pair:i64:$XBD2)<<P:Predicate_unindexedload>><<P:Predicate_load>>, GR32:i32:$R1src) - Complexity = 19
                  // Dst: (A:i32:i32 GR32:i32:$R1src, bdxaddr12pair:i64:$XBD2)
/*15755*/       /*Scope*/ 16, /*->15772*/
/*15756*/         OPC_CheckComplexPat, /*CP*/8, /*#*/1, // selectBDXAddr20Pair:$XBD2 #3 #4 #5
/*15759*/         OPC_EmitMergeInputChains1_0,
/*15760*/         OPC_MorphNodeTo, TARGET_VAL(SystemZ::AY), 0|OPFL_Chain|OPFL_MemRefs,
                      2/*#VTs*/, MVT::i32, MVT::i32, 4/*#Ops*/, 2, 3, 4, 5, 
                  // Src: (add:i32 (ld:i32 bdxaddr20pair:i64:$XBD2)<<P:Predicate_unindexedload>><<P:Predicate_load>>, GR32:i32:$R1src) - Complexity = 19
                  // Dst: (AY:i32:i32 GR32:i32:$R1src, bdxaddr20pair:i64:$XBD2)
/*15772*/       0, /*End of Scope*/
/*15773*/     /*Scope*/ 24, /*->15798*/
/*15774*/       OPC_CheckPredicate, 35, // Predicate_asextload
/*15776*/       OPC_CheckPredicate, 37, // Predicate_asextloadi32
/*15778*/       OPC_MoveParent,
/*15779*/       OPC_RecordChild1, // #2 = $R1src
/*15780*/       OPC_CheckType, MVT::i64,
/*15782*/       OPC_CheckComplexPat, /*CP*/0, /*#*/1, // selectBDXAddr20Only:$XBD2 #3 #4 #5
/*15785*/       OPC_EmitMergeInputChains1_0,
/*15786*/       OPC_MorphNodeTo, TARGET_VAL(SystemZ::AGF), 0|OPFL_Chain|OPFL_MemRefs,
                    2/*#VTs*/, MVT::i64, MVT::i32, 4/*#Ops*/, 2, 3, 4, 5, 
                // Src: (add:i64 (ld:i64 bdxaddr20only:i64:$XBD2)<<P:Predicate_unindexedload>><<P:Predicate_asextload>><<P:Predicate_asextloadi32>>, GR64:i64:$R1src) - Complexity = 19
                // Dst: (AGF:i64:i32 GR64:i64:$R1src, bdxaddr20only:i64:$XBD2)
/*15798*/     /*Scope*/ 22, /*->15821*/
/*15799*/       OPC_CheckPredicate, 13, // Predicate_load
/*15801*/       OPC_MoveParent,
/*15802*/       OPC_RecordChild1, // #2 = $R1src
/*15803*/       OPC_CheckType, MVT::i64,
/*15805*/       OPC_CheckComplexPat, /*CP*/0, /*#*/1, // selectBDXAddr20Only:$XBD2 #3 #4 #5
/*15808*/       OPC_EmitMergeInputChains1_0,
/*15809*/       OPC_MorphNodeTo, TARGET_VAL(SystemZ::AG), 0|OPFL_Chain|OPFL_MemRefs,
                    2/*#VTs*/, MVT::i64, MVT::i32, 4/*#Ops*/, 2, 3, 4, 5, 
                // Src: (add:i64 (ld:i64 bdxaddr20only:i64:$XBD2)<<P:Predicate_unindexedload>><<P:Predicate_load>>, GR64:i64:$R1src) - Complexity = 19
                // Dst: (AG:i64:i32 GR64:i64:$R1src, bdxaddr20only:i64:$XBD2)
/*15821*/     /*Scope*/ 24, /*->15846*/
/*15822*/       OPC_CheckPredicate, 38, // Predicate_azextload
/*15824*/       OPC_CheckPredicate, 39, // Predicate_azextloadi32
/*15826*/       OPC_MoveParent,
/*15827*/       OPC_RecordChild1, // #2 = $src1
/*15828*/       OPC_CheckType, MVT::i64,
/*15830*/       OPC_CheckComplexPat, /*CP*/0, /*#*/1, // selectBDXAddr20Only:$addr #3 #4 #5
/*15833*/       OPC_EmitMergeInputChains1_0,
/*15834*/       OPC_MorphNodeTo, TARGET_VAL(SystemZ::ALGF), 0|OPFL_Chain|OPFL_MemRefs,
                    2/*#VTs*/, MVT::i64, MVT::i32, 4/*#Ops*/, 2, 3, 4, 5, 
                // Src: (add:i64 (ld:i64 bdxaddr20only:i64:$addr)<<P:Predicate_unindexedload>><<P:Predicate_azextload>><<P:Predicate_azextloadi32>>, GR64:i64:$src1) - Complexity = 19
                // Dst: (ALGF:i64:i32 GR64:i64:$src1, bdxaddr20only:i64:$addr)
/*15846*/     0, /*End of Scope*/
/*15847*/   /*Scope*/ 47, /*->15895*/
/*15848*/     OPC_RecordNode, // #0 = $src
/*15849*/     OPC_CheckType, MVT::i64,
/*15851*/     OPC_Scope, 13, /*->15866*/ // 3 children in Scope
/*15853*/       OPC_CheckComplexPat, /*CP*/13, /*#*/0, // selectDynAlloc12Only:$src #1 #2 #3
/*15856*/       OPC_MorphNodeTo, TARGET_VAL(SystemZ::ADJDYNALLOC), 0,
                    1/*#VTs*/, MVT::i64, 3/*#Ops*/, 1, 2, 3, 
                // Src: dynalloc12only:i64:$src - Complexity = 12
                // Dst: (ADJDYNALLOC:i64 dynalloc12only:i64:$src)
/*15866*/     /*Scope*/ 13, /*->15880*/
/*15867*/       OPC_CheckComplexPat, /*CP*/14, /*#*/0, // selectLAAddr12Pair:$XBD2 #1 #2 #3
/*15870*/       OPC_MorphNodeTo, TARGET_VAL(SystemZ::LA), 0,
                    1/*#VTs*/, MVT::i64, 3/*#Ops*/, 1, 2, 3, 
                // Src: laaddr12pair:i64:$XBD2 - Complexity = 12
                // Dst: (LA:i64 laaddr12pair:i64:$XBD2)
/*15880*/     /*Scope*/ 13, /*->15894*/
/*15881*/       OPC_CheckComplexPat, /*CP*/15, /*#*/0, // selectLAAddr20Pair:$XBD2 #1 #2 #3
/*15884*/       OPC_MorphNodeTo, TARGET_VAL(SystemZ::LAY), 0,
                    1/*#VTs*/, MVT::i64, 3/*#Ops*/, 1, 2, 3, 
                // Src: laaddr20pair:i64:$XBD2 - Complexity = 12
                // Dst: (LAY:i64 laaddr20pair:i64:$XBD2)
/*15894*/     0, /*End of Scope*/
/*15895*/   /*Scope*/ 35, /*->15931*/
/*15896*/     OPC_RecordChild0, // #0 = $src1
/*15897*/     OPC_MoveChild, 1,
/*15899*/     OPC_CheckAndImm, 127|128,127|128,127|128,127|128,15/*4294967295*/, 
/*15905*/     OPC_RecordChild0, // #1 = $src2
/*15906*/     OPC_MoveParent,
/*15907*/     OPC_CheckType, MVT::i64,
/*15909*/     OPC_EmitInteger, MVT::i32, SystemZ::subreg_l32,
/*15912*/     OPC_EmitNode, TARGET_VAL(TargetOpcode::EXTRACT_SUBREG), 0,
                  1/*#VTs*/, MVT::i32, 2/*#Ops*/, 1, 2,  // Results = #3
/*15921*/     OPC_MorphNodeTo, TARGET_VAL(SystemZ::ALGFR), 0,
                  2/*#VTs*/, MVT::i64, MVT::i32, 2/*#Ops*/, 0, 3, 
              // Src: (add:i64 GR64:i64:$src1, (and:i64 GR64:i64:$src2, 4294967295:i64)) - Complexity = 11
              // Dst: (ALGFR:i64:i32 GR64:i64:$src1, (EXTRACT_SUBREG:i32 GR64:i64:$src2, subreg_l32:i32))
/*15931*/   /*Scope*/ 35, /*->15967*/
/*15932*/     OPC_MoveChild, 0,
/*15934*/     OPC_CheckAndImm, 127|128,127|128,127|128,127|128,15/*4294967295*/, 
/*15940*/     OPC_RecordChild0, // #0 = $src2
/*15941*/     OPC_MoveParent,
/*15942*/     OPC_RecordChild1, // #1 = $src1
/*15943*/     OPC_CheckType, MVT::i64,
/*15945*/     OPC_EmitInteger, MVT::i32, SystemZ::subreg_l32,
/*15948*/     OPC_EmitNode, TARGET_VAL(TargetOpcode::EXTRACT_SUBREG), 0,
                  1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 2,  // Results = #3
/*15957*/     OPC_MorphNodeTo, TARGET_VAL(SystemZ::ALGFR), 0,
                  2/*#VTs*/, MVT::i64, MVT::i32, 2/*#Ops*/, 1, 3, 
              // Src: (add:i64 (and:i64 GR64:i64:$src2, 4294967295:i64), GR64:i64:$src1) - Complexity = 11
              // Dst: (ALGFR:i64:i32 GR64:i64:$src1, (EXTRACT_SUBREG:i32 GR64:i64:$src2, subreg_l32:i32))
/*15967*/   /*Scope*/ 104|128,1/*232*/, /*->16201*/
/*15969*/     OPC_RecordChild0, // #0 = $R1src
/*15970*/     OPC_Scope, 64|128,1/*192*/, /*->16165*/ // 2 children in Scope
/*15973*/       OPC_RecordChild1, // #1 = $I2
/*15974*/       OPC_MoveChild, 1,
/*15976*/       OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*15979*/       OPC_Scope, 41, /*->16022*/ // 6 children in Scope
/*15981*/         OPC_CheckPredicate, 31, // Predicate_imm32sx16
/*15983*/         OPC_MoveParent,
/*15984*/         OPC_CheckType, MVT::i32,
/*15986*/         OPC_Scope, 17, /*->16005*/ // 2 children in Scope
/*15988*/           OPC_CheckPatternPredicate, 0, // (Subtarget.hasHighWord())
/*15990*/           OPC_EmitConvertToTarget, 1,
/*15992*/           OPC_EmitNodeXForm, 2, 2, // SIMM16
/*15995*/           OPC_MorphNodeTo, TARGET_VAL(SystemZ::AHIMux), 0,
                        2/*#VTs*/, MVT::i32, MVT::i32, 2/*#Ops*/, 0, 3, 
                    // Src: (add:i32 GRX32:i32:$R1src, (imm:i32)<<P:Predicate_imm32sx16>><<X:SIMM16>>:$I2) - Complexity = 7
                    // Dst: (AHIMux:i32:i32 GRX32:i32:$R1src, (SIMM16:i32 (imm:i32):$I2))
/*16005*/         /*Scope*/ 15, /*->16021*/
/*16006*/           OPC_EmitConvertToTarget, 1,
/*16008*/           OPC_EmitNodeXForm, 2, 2, // SIMM16
/*16011*/           OPC_MorphNodeTo, TARGET_VAL(SystemZ::AHI), 0,
                        2/*#VTs*/, MVT::i32, MVT::i32, 2/*#Ops*/, 0, 3, 
                    // Src: (add:i32 GR32:i32:$R1src, (imm:i32)<<P:Predicate_imm32sx16>><<X:SIMM16>>:$I2) - Complexity = 7
                    // Dst: (AHI:i32:i32 GR32:i32:$R1src, (SIMM16:i32 (imm:i32):$I2))
/*16021*/         0, /*End of Scope*/
/*16022*/       /*Scope*/ 20, /*->16043*/
/*16023*/         OPC_CheckPredicate, 32, // Predicate_imm64sx16
/*16025*/         OPC_MoveParent,
/*16026*/         OPC_CheckType, MVT::i64,
/*16028*/         OPC_EmitConvertToTarget, 1,
/*16030*/         OPC_EmitNodeXForm, 2, 2, // SIMM16
/*16033*/         OPC_MorphNodeTo, TARGET_VAL(SystemZ::AGHI), 0,
                      2/*#VTs*/, MVT::i64, MVT::i32, 2/*#Ops*/, 0, 3, 
                  // Src: (add:i64 GR64:i64:$R1src, (imm:i64)<<P:Predicate_imm64sx16>><<X:SIMM16>>:$I2) - Complexity = 7
                  // Dst: (AGHI:i64:i32 GR64:i64:$R1src, (SIMM16:i64 (imm:i64):$I2))
/*16043*/       /*Scope*/ 20, /*->16064*/
/*16044*/         OPC_CheckPredicate, 63, // Predicate_imm64sx32
/*16046*/         OPC_MoveParent,
/*16047*/         OPC_CheckType, MVT::i64,
/*16049*/         OPC_EmitConvertToTarget, 1,
/*16051*/         OPC_EmitNodeXForm, 11, 2, // SIMM32
/*16054*/         OPC_MorphNodeTo, TARGET_VAL(SystemZ::AGFI), 0,
                      2/*#VTs*/, MVT::i64, MVT::i32, 2/*#Ops*/, 0, 3, 
                  // Src: (add:i64 GR64:i64:$R1src, (imm:i64)<<P:Predicate_imm64sx32>><<X:SIMM32>>:$I2) - Complexity = 7
                  // Dst: (AGFI:i64:i32 GR64:i64:$R1src, (SIMM32:i64 (imm:i64):$I2))
/*16064*/       /*Scope*/ 20, /*->16085*/
/*16065*/         OPC_CheckPredicate, 64, // Predicate_imm64zx32
/*16067*/         OPC_MoveParent,
/*16068*/         OPC_CheckType, MVT::i64,
/*16070*/         OPC_EmitConvertToTarget, 1,
/*16072*/         OPC_EmitNodeXForm, 5, 2, // UIMM32
/*16075*/         OPC_MorphNodeTo, TARGET_VAL(SystemZ::ALGFI), 0,
                      2/*#VTs*/, MVT::i64, MVT::i32, 2/*#Ops*/, 0, 3, 
                  // Src: (add:i64 GR64:i64:$src1, (imm:i64)<<P:Predicate_imm64zx32>><<X:UIMM32>>:$src2) - Complexity = 7
                  // Dst: (ALGFI:i64:i32 GR64:i64:$src1, (UIMM32:i64 (imm:i64)<<P:Predicate_imm64zx32>>:$src2))
/*16085*/       /*Scope*/ 20, /*->16106*/
/*16086*/         OPC_CheckPredicate, 65, // Predicate_imm64zx32n
/*16088*/         OPC_MoveParent,
/*16089*/         OPC_CheckType, MVT::i64,
/*16091*/         OPC_EmitConvertToTarget, 1,
/*16093*/         OPC_EmitNodeXForm, 12, 2, // NEGIMM32
/*16096*/         OPC_MorphNodeTo, TARGET_VAL(SystemZ::SLGFI), 0,
                      2/*#VTs*/, MVT::i64, MVT::i32, 2/*#Ops*/, 0, 3, 
                  // Src: (add:i64 GR64:i64:$src1, (imm:i64)<<P:Predicate_imm64zx32n>><<X:NEGIMM32>>:$src2) - Complexity = 7
                  // Dst: (SLGFI:i64:i32 GR64:i64:$src1, (NEGIMM32:i64 (imm:i64)<<P:Predicate_imm64zx32n>>:$src2))
/*16106*/       /*Scope*/ 57, /*->16164*/
/*16107*/         OPC_MoveParent,
/*16108*/         OPC_CheckType, MVT::i32,
/*16110*/         OPC_Scope, 17, /*->16129*/ // 3 children in Scope
/*16112*/           OPC_CheckPatternPredicate, 0, // (Subtarget.hasHighWord())
/*16114*/           OPC_EmitConvertToTarget, 1,
/*16116*/           OPC_EmitNodeXForm, 11, 2, // SIMM32
/*16119*/           OPC_MorphNodeTo, TARGET_VAL(SystemZ::AFIMux), 0,
                        2/*#VTs*/, MVT::i32, MVT::i32, 2/*#Ops*/, 0, 3, 
                    // Src: (add:i32 GRX32:i32:$R1src, (imm:i32)<<X:SIMM32>>:$I2) - Complexity = 6
                    // Dst: (AFIMux:i32:i32 GRX32:i32:$R1src, (SIMM32:i32 (imm:i32):$I2))
/*16129*/         /*Scope*/ 15, /*->16145*/
/*16130*/           OPC_EmitConvertToTarget, 1,
/*16132*/           OPC_EmitNodeXForm, 11, 2, // SIMM32
/*16135*/           OPC_MorphNodeTo, TARGET_VAL(SystemZ::AFI), 0,
                        2/*#VTs*/, MVT::i32, MVT::i32, 2/*#Ops*/, 0, 3, 
                    // Src: (add:i32 GR32:i32:$R1src, (imm:i32)<<X:SIMM32>>:$I2) - Complexity = 6
                    // Dst: (AFI:i32:i32 GR32:i32:$R1src, (SIMM32:i32 (imm:i32):$I2))
/*16145*/         /*Scope*/ 17, /*->16163*/
/*16146*/           OPC_CheckPatternPredicate, 0, // (Subtarget.hasHighWord())
/*16148*/           OPC_EmitConvertToTarget, 1,
/*16150*/           OPC_EmitNodeXForm, 11, 2, // SIMM32
/*16153*/           OPC_MorphNodeTo, TARGET_VAL(SystemZ::AIH), 0,
                        2/*#VTs*/, MVT::i32, MVT::i32, 2/*#Ops*/, 0, 3, 
                    // Src: (add:i32 GRH32:i32:$R1src, (imm:i32)<<X:SIMM32>>:$I2) - Complexity = 6
                    // Dst: (AIH:i32:i32 GRH32:i32:$R1src, (SIMM32:i32 (imm:i32):$I2))
/*16163*/         0, /*End of Scope*/
/*16164*/       0, /*End of Scope*/
/*16165*/     /*Scope*/ 34, /*->16200*/
/*16166*/       OPC_MoveChild, 1,
/*16168*/       OPC_SwitchOpcode /*2 cases */, 12,  TARGET_VAL(ISD::SIGN_EXTEND),// ->16184
/*16172*/         OPC_RecordChild0, // #1 = $src2
/*16173*/         OPC_MoveParent,
/*16174*/         OPC_MorphNodeTo, TARGET_VAL(SystemZ::AGFR), 0,
                      2/*#VTs*/, MVT::i64, MVT::i32, 2/*#Ops*/, 0, 1, 
                  // Src: (add:i64 GR64:i64:$src1, (sext:i64 GR32:i32:$src2)) - Complexity = 6
                  // Dst: (AGFR:i64:i32 GR64:i64:$src1, GR32:i32:$src2)
/*16184*/       /*SwitchOpcode*/ 12,  TARGET_VAL(ISD::ZERO_EXTEND),// ->16199
/*16187*/         OPC_RecordChild0, // #1 = $src2
/*16188*/         OPC_MoveParent,
/*16189*/         OPC_MorphNodeTo, TARGET_VAL(SystemZ::ALGFR), 0,
                      2/*#VTs*/, MVT::i64, MVT::i32, 2/*#Ops*/, 0, 1, 
                  // Src: (add:i64 GR64:i64:$src1, (zext:i64 GR32:i32:$src2)) - Complexity = 6
                  // Dst: (ALGFR:i64:i32 GR64:i64:$src1, GR32:i32:$src2)
/*16199*/       0, // EndSwitchOpcode
/*16200*/     0, /*End of Scope*/
/*16201*/   /*Scope*/ 36, /*->16238*/
/*16202*/     OPC_MoveChild, 0,
/*16204*/     OPC_SwitchOpcode /*2 cases */, 13,  TARGET_VAL(ISD::SIGN_EXTEND),// ->16221
/*16208*/       OPC_RecordChild0, // #0 = $src2
/*16209*/       OPC_MoveParent,
/*16210*/       OPC_RecordChild1, // #1 = $src1
/*16211*/       OPC_MorphNodeTo, TARGET_VAL(SystemZ::AGFR), 0,
                    2/*#VTs*/, MVT::i64, MVT::i32, 2/*#Ops*/, 1, 0, 
                // Src: (add:i64 (sext:i64 GR32:i32:$src2), GR64:i64:$src1) - Complexity = 6
                // Dst: (AGFR:i64:i32 GR64:i64:$src1, GR32:i32:$src2)
/*16221*/     /*SwitchOpcode*/ 13,  TARGET_VAL(ISD::ZERO_EXTEND),// ->16237
/*16224*/       OPC_RecordChild0, // #0 = $src2
/*16225*/       OPC_MoveParent,
/*16226*/       OPC_RecordChild1, // #1 = $src1
/*16227*/       OPC_MorphNodeTo, TARGET_VAL(SystemZ::ALGFR), 0,
                    2/*#VTs*/, MVT::i64, MVT::i32, 2/*#Ops*/, 1, 0, 
                // Src: (add:i64 (zext:i64 GR32:i32:$src2), GR64:i64:$src1) - Complexity = 6
                // Dst: (ALGFR:i64:i32 GR64:i64:$src1, GR32:i32:$src2)
/*16237*/     0, // EndSwitchOpcode
/*16238*/   /*Scope*/ 35, /*->16274*/
/*16239*/     OPC_RecordChild0, // #0 = $src1
/*16240*/     OPC_MoveChild, 1,
/*16242*/     OPC_CheckOpcode, TARGET_VAL(ISD::SIGN_EXTEND_INREG),
/*16245*/     OPC_RecordChild0, // #1 = $src2
/*16246*/     OPC_MoveChild, 1,
/*16248*/     OPC_CheckValueType, MVT::i32,
/*16250*/     OPC_MoveParent,
/*16251*/     OPC_MoveParent,
/*16252*/     OPC_EmitInteger, MVT::i32, SystemZ::subreg_l32,
/*16255*/     OPC_EmitNode, TARGET_VAL(TargetOpcode::EXTRACT_SUBREG), 0,
                  1/*#VTs*/, MVT::i32, 2/*#Ops*/, 1, 2,  // Results = #3
/*16264*/     OPC_MorphNodeTo, TARGET_VAL(SystemZ::AGFR), 0,
                  2/*#VTs*/, MVT::i64, MVT::i32, 2/*#Ops*/, 0, 3, 
              // Src: (add:i64 GR64:i64:$src1, (sext_inreg:i64 GR64:i64:$src2, i32:Other)) - Complexity = 6
              // Dst: (AGFR:i64:i32 GR64:i64:$src1, (EXTRACT_SUBREG:i32 GR64:i64:$src2, subreg_l32:i32))
/*16274*/   /*Scope*/ 35, /*->16310*/
/*16275*/     OPC_MoveChild, 0,
/*16277*/     OPC_CheckOpcode, TARGET_VAL(ISD::SIGN_EXTEND_INREG),
/*16280*/     OPC_RecordChild0, // #0 = $src2
/*16281*/     OPC_MoveChild, 1,
/*16283*/     OPC_CheckValueType, MVT::i32,
/*16285*/     OPC_MoveParent,
/*16286*/     OPC_MoveParent,
/*16287*/     OPC_RecordChild1, // #1 = $src1
/*16288*/     OPC_EmitInteger, MVT::i32, SystemZ::subreg_l32,
/*16291*/     OPC_EmitNode, TARGET_VAL(TargetOpcode::EXTRACT_SUBREG), 0,
                  1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 2,  // Results = #3
/*16300*/     OPC_MorphNodeTo, TARGET_VAL(SystemZ::AGFR), 0,
                  2/*#VTs*/, MVT::i64, MVT::i32, 2/*#Ops*/, 1, 3, 
              // Src: (add:i64 (sext_inreg:i64 GR64:i64:$src2, i32:Other), GR64:i64:$src1) - Complexity = 6
              // Dst: (AGFR:i64:i32 GR64:i64:$src1, (EXTRACT_SUBREG:i32 GR64:i64:$src2, subreg_l32:i32))
/*16310*/   /*Scope*/ 28, /*->16339*/
/*16311*/     OPC_RecordChild0, // #0 = $R1src
/*16312*/     OPC_RecordChild1, // #1 = $R2
/*16313*/     OPC_SwitchType /*2 cases */, 10,  MVT::i32,// ->16326
/*16316*/       OPC_MorphNodeTo, TARGET_VAL(SystemZ::AR), 0,
                    2/*#VTs*/, MVT::i32, MVT::i32, 2/*#Ops*/, 0, 1, 
                // Src: (add:i32 GR32:i32:$R1src, GR32:i32:$R2) - Complexity = 3
                // Dst: (AR:i32:i32 GR32:i32:$R1src, GR32:i32:$R2)
/*16326*/     /*SwitchType*/ 10,  MVT::i64,// ->16338
/*16328*/       OPC_MorphNodeTo, TARGET_VAL(SystemZ::AGR), 0,
                    2/*#VTs*/, MVT::i64, MVT::i32, 2/*#Ops*/, 0, 1, 
                // Src: (add:i64 GR64:i64:$R1src, GR64:i64:$R2) - Complexity = 3
                // Dst: (AGR:i64:i32 GR64:i64:$R1src, GR64:i64:$R2)
/*16338*/     0, // EndSwitchType
/*16339*/   0, /*End of Scope*/
/*16340*/ /*SwitchOpcode*/ 67|128,3/*451*/,  TARGET_VAL(ISD::ADDC),// ->16795
/*16344*/   OPC_Scope, 104, /*->16450*/ // 7 children in Scope
/*16346*/     OPC_RecordChild0, // #0 = $R1src
/*16347*/     OPC_MoveChild, 1,
/*16349*/     OPC_CheckOpcode, TARGET_VAL(ISD::LOAD),
/*16352*/     OPC_RecordMemRef,
/*16353*/     OPC_RecordNode, // #1 = 'ld' chained node
/*16354*/     OPC_CheckFoldableChainNode,
/*16355*/     OPC_RecordChild1, // #2 = $XBD2
/*16356*/     OPC_CheckChild1Type, MVT::i64,
/*16358*/     OPC_CheckPredicate, 0, // Predicate_unindexedload
/*16360*/     OPC_Scope, 41, /*->16403*/ // 3 children in Scope
/*16362*/       OPC_CheckPredicate, 13, // Predicate_load
/*16364*/       OPC_MoveParent,
/*16365*/       OPC_CheckType, MVT::i32,
/*16367*/       OPC_Scope, 16, /*->16385*/ // 2 children in Scope
/*16369*/         OPC_CheckComplexPat, /*CP*/7, /*#*/2, // selectBDXAddr12Pair:$XBD2 #3 #4 #5
/*16372*/         OPC_EmitMergeInputChains1_1,
/*16373*/         OPC_MorphNodeTo, TARGET_VAL(SystemZ::AL), 0|OPFL_Chain|OPFL_GlueOutput|OPFL_MemRefs,
                      2/*#VTs*/, MVT::i32, MVT::i32, 4/*#Ops*/, 0, 3, 4, 5, 
                  // Src: (addc:i32 GR32:i32:$R1src, (ld:i32 bdxaddr12pair:i64:$XBD2)<<P:Predicate_unindexedload>><<P:Predicate_load>>) - Complexity = 19
                  // Dst: (AL:i32:i32 GR32:i32:$R1src, bdxaddr12pair:i64:$XBD2)
/*16385*/       /*Scope*/ 16, /*->16402*/
/*16386*/         OPC_CheckComplexPat, /*CP*/8, /*#*/2, // selectBDXAddr20Pair:$XBD2 #3 #4 #5
/*16389*/         OPC_EmitMergeInputChains1_1,
/*16390*/         OPC_MorphNodeTo, TARGET_VAL(SystemZ::ALY), 0|OPFL_Chain|OPFL_GlueOutput|OPFL_MemRefs,
                      2/*#VTs*/, MVT::i32, MVT::i32, 4/*#Ops*/, 0, 3, 4, 5, 
                  // Src: (addc:i32 GR32:i32:$R1src, (ld:i32 bdxaddr20pair:i64:$XBD2)<<P:Predicate_unindexedload>><<P:Predicate_load>>) - Complexity = 19
                  // Dst: (ALY:i32:i32 GR32:i32:$R1src, bdxaddr20pair:i64:$XBD2)
/*16402*/       0, /*End of Scope*/
/*16403*/     /*Scope*/ 23, /*->16427*/
/*16404*/       OPC_CheckPredicate, 38, // Predicate_azextload
/*16406*/       OPC_CheckPredicate, 39, // Predicate_azextloadi32
/*16408*/       OPC_MoveParent,
/*16409*/       OPC_CheckType, MVT::i64,
/*16411*/       OPC_CheckComplexPat, /*CP*/0, /*#*/2, // selectBDXAddr20Only:$XBD2 #3 #4 #5
/*16414*/       OPC_EmitMergeInputChains1_1,
/*16415*/       OPC_MorphNodeTo, TARGET_VAL(SystemZ::ALGF), 0|OPFL_Chain|OPFL_GlueOutput|OPFL_MemRefs,
                    2/*#VTs*/, MVT::i64, MVT::i32, 4/*#Ops*/, 0, 3, 4, 5, 
                // Src: (addc:i64 GR64:i64:$R1src, (ld:i64 bdxaddr20only:i64:$XBD2)<<P:Predicate_unindexedload>><<P:Predicate_azextload>><<P:Predicate_azextloadi32>>) - Complexity = 19
                // Dst: (ALGF:i64:i32 GR64:i64:$R1src, bdxaddr20only:i64:$XBD2)
/*16427*/     /*Scope*/ 21, /*->16449*/
/*16428*/       OPC_CheckPredicate, 13, // Predicate_load
/*16430*/       OPC_MoveParent,
/*16431*/       OPC_CheckType, MVT::i64,
/*16433*/       OPC_CheckComplexPat, /*CP*/0, /*#*/2, // selectBDXAddr20Only:$XBD2 #3 #4 #5
/*16436*/       OPC_EmitMergeInputChains1_1,
/*16437*/       OPC_MorphNodeTo, TARGET_VAL(SystemZ::ALG), 0|OPFL_Chain|OPFL_GlueOutput|OPFL_MemRefs,
                    2/*#VTs*/, MVT::i64, MVT::i32, 4/*#Ops*/, 0, 3, 4, 5, 
                // Src: (addc:i64 GR64:i64:$R1src, (ld:i64 bdxaddr20only:i64:$XBD2)<<P:Predicate_unindexedload>><<P:Predicate_load>>) - Complexity = 19
                // Dst: (ALG:i64:i32 GR64:i64:$R1src, bdxaddr20only:i64:$XBD2)
/*16449*/     0, /*End of Scope*/
/*16450*/   /*Scope*/ 106, /*->16557*/
/*16451*/     OPC_MoveChild, 0,
/*16453*/     OPC_CheckOpcode, TARGET_VAL(ISD::LOAD),
/*16456*/     OPC_RecordMemRef,
/*16457*/     OPC_RecordNode, // #0 = 'ld' chained node
/*16458*/     OPC_CheckFoldableChainNode,
/*16459*/     OPC_RecordChild1, // #1 = $XBD2
/*16460*/     OPC_CheckChild1Type, MVT::i64,
/*16462*/     OPC_CheckPredicate, 0, // Predicate_unindexedload
/*16464*/     OPC_Scope, 42, /*->16508*/ // 3 children in Scope
/*16466*/       OPC_CheckPredicate, 13, // Predicate_load
/*16468*/       OPC_MoveParent,
/*16469*/       OPC_RecordChild1, // #2 = $R1src
/*16470*/       OPC_CheckType, MVT::i32,
/*16472*/       OPC_Scope, 16, /*->16490*/ // 2 children in Scope
/*16474*/         OPC_CheckComplexPat, /*CP*/7, /*#*/1, // selectBDXAddr12Pair:$XBD2 #3 #4 #5
/*16477*/         OPC_EmitMergeInputChains1_0,
/*16478*/         OPC_MorphNodeTo, TARGET_VAL(SystemZ::AL), 0|OPFL_Chain|OPFL_GlueOutput|OPFL_MemRefs,
                      2/*#VTs*/, MVT::i32, MVT::i32, 4/*#Ops*/, 2, 3, 4, 5, 
                  // Src: (addc:i32 (ld:i32 bdxaddr12pair:i64:$XBD2)<<P:Predicate_unindexedload>><<P:Predicate_load>>, GR32:i32:$R1src) - Complexity = 19
                  // Dst: (AL:i32:i32 GR32:i32:$R1src, bdxaddr12pair:i64:$XBD2)
/*16490*/       /*Scope*/ 16, /*->16507*/
/*16491*/         OPC_CheckComplexPat, /*CP*/8, /*#*/1, // selectBDXAddr20Pair:$XBD2 #3 #4 #5
/*16494*/         OPC_EmitMergeInputChains1_0,
/*16495*/         OPC_MorphNodeTo, TARGET_VAL(SystemZ::ALY), 0|OPFL_Chain|OPFL_GlueOutput|OPFL_MemRefs,
                      2/*#VTs*/, MVT::i32, MVT::i32, 4/*#Ops*/, 2, 3, 4, 5, 
                  // Src: (addc:i32 (ld:i32 bdxaddr20pair:i64:$XBD2)<<P:Predicate_unindexedload>><<P:Predicate_load>>, GR32:i32:$R1src) - Complexity = 19
                  // Dst: (ALY:i32:i32 GR32:i32:$R1src, bdxaddr20pair:i64:$XBD2)
/*16507*/       0, /*End of Scope*/
/*16508*/     /*Scope*/ 24, /*->16533*/
/*16509*/       OPC_CheckPredicate, 38, // Predicate_azextload
/*16511*/       OPC_CheckPredicate, 39, // Predicate_azextloadi32
/*16513*/       OPC_MoveParent,
/*16514*/       OPC_RecordChild1, // #2 = $R1src
/*16515*/       OPC_CheckType, MVT::i64,
/*16517*/       OPC_CheckComplexPat, /*CP*/0, /*#*/1, // selectBDXAddr20Only:$XBD2 #3 #4 #5
/*16520*/       OPC_EmitMergeInputChains1_0,
/*16521*/       OPC_MorphNodeTo, TARGET_VAL(SystemZ::ALGF), 0|OPFL_Chain|OPFL_GlueOutput|OPFL_MemRefs,
                    2/*#VTs*/, MVT::i64, MVT::i32, 4/*#Ops*/, 2, 3, 4, 5, 
                // Src: (addc:i64 (ld:i64 bdxaddr20only:i64:$XBD2)<<P:Predicate_unindexedload>><<P:Predicate_azextload>><<P:Predicate_azextloadi32>>, GR64:i64:$R1src) - Complexity = 19
                // Dst: (ALGF:i64:i32 GR64:i64:$R1src, bdxaddr20only:i64:$XBD2)
/*16533*/     /*Scope*/ 22, /*->16556*/
/*16534*/       OPC_CheckPredicate, 13, // Predicate_load
/*16536*/       OPC_MoveParent,
/*16537*/       OPC_RecordChild1, // #2 = $R1src
/*16538*/       OPC_CheckType, MVT::i64,
/*16540*/       OPC_CheckComplexPat, /*CP*/0, /*#*/1, // selectBDXAddr20Only:$XBD2 #3 #4 #5
/*16543*/       OPC_EmitMergeInputChains1_0,
/*16544*/       OPC_MorphNodeTo, TARGET_VAL(SystemZ::ALG), 0|OPFL_Chain|OPFL_GlueOutput|OPFL_MemRefs,
                    2/*#VTs*/, MVT::i64, MVT::i32, 4/*#Ops*/, 2, 3, 4, 5, 
                // Src: (addc:i64 (ld:i64 bdxaddr20only:i64:$XBD2)<<P:Predicate_unindexedload>><<P:Predicate_load>>, GR64:i64:$R1src) - Complexity = 19
                // Dst: (ALG:i64:i32 GR64:i64:$R1src, bdxaddr20only:i64:$XBD2)
/*16556*/     0, /*End of Scope*/
/*16557*/   /*Scope*/ 35, /*->16593*/
/*16558*/     OPC_RecordChild0, // #0 = $src1
/*16559*/     OPC_MoveChild, 1,
/*16561*/     OPC_CheckAndImm, 127|128,127|128,127|128,127|128,15/*4294967295*/, 
/*16567*/     OPC_RecordChild0, // #1 = $src2
/*16568*/     OPC_MoveParent,
/*16569*/     OPC_CheckType, MVT::i64,
/*16571*/     OPC_EmitInteger, MVT::i32, SystemZ::subreg_l32,
/*16574*/     OPC_EmitNode, TARGET_VAL(TargetOpcode::EXTRACT_SUBREG), 0,
                  1/*#VTs*/, MVT::i32, 2/*#Ops*/, 1, 2,  // Results = #3
/*16583*/     OPC_MorphNodeTo, TARGET_VAL(SystemZ::ALGFR), 0|OPFL_GlueOutput,
                  2/*#VTs*/, MVT::i64, MVT::i32, 2/*#Ops*/, 0, 3, 
              // Src: (addc:i64 GR64:i64:$src1, (and:i64 GR64:i64:$src2, 4294967295:i64)) - Complexity = 11
              // Dst: (ALGFR:i64:i32 GR64:i64:$src1, (EXTRACT_SUBREG:i32 GR64:i64:$src2, subreg_l32:i32))
/*16593*/   /*Scope*/ 35, /*->16629*/
/*16594*/     OPC_MoveChild, 0,
/*16596*/     OPC_CheckAndImm, 127|128,127|128,127|128,127|128,15/*4294967295*/, 
/*16602*/     OPC_RecordChild0, // #0 = $src2
/*16603*/     OPC_MoveParent,
/*16604*/     OPC_RecordChild1, // #1 = $src1
/*16605*/     OPC_CheckType, MVT::i64,
/*16607*/     OPC_EmitInteger, MVT::i32, SystemZ::subreg_l32,
/*16610*/     OPC_EmitNode, TARGET_VAL(TargetOpcode::EXTRACT_SUBREG), 0,
                  1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 2,  // Results = #3
/*16619*/     OPC_MorphNodeTo, TARGET_VAL(SystemZ::ALGFR), 0|OPFL_GlueOutput,
                  2/*#VTs*/, MVT::i64, MVT::i32, 2/*#Ops*/, 1, 3, 
              // Src: (addc:i64 (and:i64 GR64:i64:$src2, 4294967295:i64), GR64:i64:$src1) - Complexity = 11
              // Dst: (ALGFR:i64:i32 GR64:i64:$src1, (EXTRACT_SUBREG:i32 GR64:i64:$src2, subreg_l32:i32))
/*16629*/   /*Scope*/ 116, /*->16746*/
/*16630*/     OPC_RecordChild0, // #0 = $R3
/*16631*/     OPC_Scope, 94, /*->16727*/ // 2 children in Scope
/*16633*/       OPC_RecordChild1, // #1 = $I2
/*16634*/       OPC_MoveChild, 1,
/*16636*/       OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*16639*/       OPC_Scope, 22, /*->16663*/ // 4 children in Scope
/*16641*/         OPC_CheckPredicate, 31, // Predicate_imm32sx16
/*16643*/         OPC_MoveParent,
/*16644*/         OPC_CheckType, MVT::i32,
/*16646*/         OPC_CheckPatternPredicate, 2, // (Subtarget.hasDistinctOps())
/*16648*/         OPC_EmitConvertToTarget, 1,
/*16650*/         OPC_EmitNodeXForm, 2, 2, // SIMM16
/*16653*/         OPC_MorphNodeTo, TARGET_VAL(SystemZ::ALHSIK), 0|OPFL_GlueOutput,
                      2/*#VTs*/, MVT::i32, MVT::i32, 2/*#Ops*/, 0, 3, 
                  // Src: (addc:i32 GR32:i32:$R3, (imm:i32)<<P:Predicate_imm32sx16>><<X:SIMM16>>:$I2) - Complexity = 7
                  // Dst: (ALHSIK:i32:i32 GR32:i32:$R3, (SIMM16:i32 (imm:i32):$I2))
/*16663*/       /*Scope*/ 22, /*->16686*/
/*16664*/         OPC_CheckPredicate, 32, // Predicate_imm64sx16
/*16666*/         OPC_MoveParent,
/*16667*/         OPC_CheckType, MVT::i64,
/*16669*/         OPC_CheckPatternPredicate, 2, // (Subtarget.hasDistinctOps())
/*16671*/         OPC_EmitConvertToTarget, 1,
/*16673*/         OPC_EmitNodeXForm, 2, 2, // SIMM16
/*16676*/         OPC_MorphNodeTo, TARGET_VAL(SystemZ::ALGHSIK), 0|OPFL_GlueOutput,
                      2/*#VTs*/, MVT::i64, MVT::i32, 2/*#Ops*/, 0, 3, 
                  // Src: (addc:i64 GR64:i64:$R3, (imm:i64)<<P:Predicate_imm64sx16>><<X:SIMM16>>:$I2) - Complexity = 7
                  // Dst: (ALGHSIK:i64:i32 GR64:i64:$R3, (SIMM16:i64 (imm:i64):$I2))
/*16686*/       /*Scope*/ 20, /*->16707*/
/*16687*/         OPC_CheckPredicate, 64, // Predicate_imm64zx32
/*16689*/         OPC_MoveParent,
/*16690*/         OPC_CheckType, MVT::i64,
/*16692*/         OPC_EmitConvertToTarget, 1,
/*16694*/         OPC_EmitNodeXForm, 5, 2, // UIMM32
/*16697*/         OPC_MorphNodeTo, TARGET_VAL(SystemZ::ALGFI), 0|OPFL_GlueOutput,
                      2/*#VTs*/, MVT::i64, MVT::i32, 2/*#Ops*/, 0, 3, 
                  // Src: (addc:i64 GR64:i64:$R1src, (imm:i64)<<P:Predicate_imm64zx32>><<X:UIMM32>>:$I2) - Complexity = 7
                  // Dst: (ALGFI:i64:i32 GR64:i64:$R1src, (UIMM32:i64 (imm:i64):$I2))
/*16707*/       /*Scope*/ 18, /*->16726*/
/*16708*/         OPC_MoveParent,
/*16709*/         OPC_CheckType, MVT::i32,
/*16711*/         OPC_EmitConvertToTarget, 1,
/*16713*/         OPC_EmitNodeXForm, 5, 2, // UIMM32
/*16716*/         OPC_MorphNodeTo, TARGET_VAL(SystemZ::ALFI), 0|OPFL_GlueOutput,
                      2/*#VTs*/, MVT::i32, MVT::i32, 2/*#Ops*/, 0, 3, 
                  // Src: (addc:i32 GR32:i32:$R1src, (imm:i32)<<X:UIMM32>>:$I2) - Complexity = 6
                  // Dst: (ALFI:i32:i32 GR32:i32:$R1src, (UIMM32:i32 (imm:i32):$I2))
/*16726*/       0, /*End of Scope*/
/*16727*/     /*Scope*/ 17, /*->16745*/
/*16728*/       OPC_MoveChild, 1,
/*16730*/       OPC_CheckOpcode, TARGET_VAL(ISD::ZERO_EXTEND),
/*16733*/       OPC_RecordChild0, // #1 = $src2
/*16734*/       OPC_MoveParent,
/*16735*/       OPC_MorphNodeTo, TARGET_VAL(SystemZ::ALGFR), 0|OPFL_GlueOutput,
                    2/*#VTs*/, MVT::i64, MVT::i32, 2/*#Ops*/, 0, 1, 
                // Src: (addc:i64 GR64:i64:$src1, (zext:i64 GR32:i32:$src2)) - Complexity = 6
                // Dst: (ALGFR:i64:i32 GR64:i64:$src1, GR32:i32:$src2)
/*16745*/     0, /*End of Scope*/
/*16746*/   /*Scope*/ 18, /*->16765*/
/*16747*/     OPC_MoveChild, 0,
/*16749*/     OPC_CheckOpcode, TARGET_VAL(ISD::ZERO_EXTEND),
/*16752*/     OPC_RecordChild0, // #0 = $src2
/*16753*/     OPC_MoveParent,
/*16754*/     OPC_RecordChild1, // #1 = $src1
/*16755*/     OPC_MorphNodeTo, TARGET_VAL(SystemZ::ALGFR), 0|OPFL_GlueOutput,
                  2/*#VTs*/, MVT::i64, MVT::i32, 2/*#Ops*/, 1, 0, 
              // Src: (addc:i64 (zext:i64 GR32:i32:$src2), GR64:i64:$src1) - Complexity = 6
              // Dst: (ALGFR:i64:i32 GR64:i64:$src1, GR32:i32:$src2)
/*16765*/   /*Scope*/ 28, /*->16794*/
/*16766*/     OPC_RecordChild0, // #0 = $R1src
/*16767*/     OPC_RecordChild1, // #1 = $R2
/*16768*/     OPC_SwitchType /*2 cases */, 10,  MVT::i32,// ->16781
/*16771*/       OPC_MorphNodeTo, TARGET_VAL(SystemZ::ALR), 0|OPFL_GlueOutput,
                    2/*#VTs*/, MVT::i32, MVT::i32, 2/*#Ops*/, 0, 1, 
                // Src: (addc:i32 GR32:i32:$R1src, GR32:i32:$R2) - Complexity = 3
                // Dst: (ALR:i32:i32 GR32:i32:$R1src, GR32:i32:$R2)
/*16781*/     /*SwitchType*/ 10,  MVT::i64,// ->16793
/*16783*/       OPC_MorphNodeTo, TARGET_VAL(SystemZ::ALGR), 0|OPFL_GlueOutput,
                    2/*#VTs*/, MVT::i64, MVT::i32, 2/*#Ops*/, 0, 1, 
                // Src: (addc:i64 GR64:i64:$R1src, GR64:i64:$R2) - Complexity = 3
                // Dst: (ALGR:i64:i32 GR64:i64:$R1src, GR64:i64:$R2)
/*16793*/     0, // EndSwitchType
/*16794*/   0, /*End of Scope*/
/*16795*/ /*SwitchOpcode*/ 16|128,1/*144*/,  TARGET_VAL(ISD::ADDE),// ->16943
/*16799*/   OPC_CaptureGlueInput,
/*16800*/   OPC_Scope, 55, /*->16857*/ // 3 children in Scope
/*16802*/     OPC_RecordChild0, // #0 = $R1src
/*16803*/     OPC_MoveChild, 1,
/*16805*/     OPC_CheckOpcode, TARGET_VAL(ISD::LOAD),
/*16808*/     OPC_RecordMemRef,
/*16809*/     OPC_RecordNode, // #1 = 'ld' chained node
/*16810*/     OPC_CheckFoldableChainNode,
/*16811*/     OPC_RecordChild1, // #2 = $XBD2
/*16812*/     OPC_CheckChild1Type, MVT::i64,
/*16814*/     OPC_CheckPredicate, 0, // Predicate_unindexedload
/*16816*/     OPC_CheckPredicate, 13, // Predicate_load
/*16818*/     OPC_MoveParent,
/*16819*/     OPC_SwitchType /*2 cases */, 16,  MVT::i32,// ->16838
/*16822*/       OPC_CheckComplexPat, /*CP*/0, /*#*/2, // selectBDXAddr20Only:$XBD2 #3 #4 #5
/*16825*/       OPC_EmitMergeInputChains1_1,
/*16826*/       OPC_MorphNodeTo, TARGET_VAL(SystemZ::ALC), 0|OPFL_Chain|OPFL_GlueInput|OPFL_GlueOutput|OPFL_MemRefs,
                    2/*#VTs*/, MVT::i32, MVT::i32, 4/*#Ops*/, 0, 3, 4, 5, 
                // Src: (adde:i32 GR32:i32:$R1src, (ld:i32 bdxaddr20only:i64:$XBD2)<<P:Predicate_unindexedload>><<P:Predicate_load>>) - Complexity = 19
                // Dst: (ALC:i32:i32 GR32:i32:$R1src, bdxaddr20only:i64:$XBD2)
/*16838*/     /*SwitchType*/ 16,  MVT::i64,// ->16856
/*16840*/       OPC_CheckComplexPat, /*CP*/0, /*#*/2, // selectBDXAddr20Only:$XBD2 #3 #4 #5
/*16843*/       OPC_EmitMergeInputChains1_1,
/*16844*/       OPC_MorphNodeTo, TARGET_VAL(SystemZ::ALCG), 0|OPFL_Chain|OPFL_GlueInput|OPFL_GlueOutput|OPFL_MemRefs,
                    2/*#VTs*/, MVT::i64, MVT::i32, 4/*#Ops*/, 0, 3, 4, 5, 
                // Src: (adde:i64 GR64:i64:$R1src, (ld:i64 bdxaddr20only:i64:$XBD2)<<P:Predicate_unindexedload>><<P:Predicate_load>>) - Complexity = 19
                // Dst: (ALCG:i64:i32 GR64:i64:$R1src, bdxaddr20only:i64:$XBD2)
/*16856*/     0, // EndSwitchType
/*16857*/   /*Scope*/ 55, /*->16913*/
/*16858*/     OPC_MoveChild, 0,
/*16860*/     OPC_CheckOpcode, TARGET_VAL(ISD::LOAD),
/*16863*/     OPC_RecordMemRef,
/*16864*/     OPC_RecordNode, // #0 = 'ld' chained node
/*16865*/     OPC_CheckFoldableChainNode,
/*16866*/     OPC_RecordChild1, // #1 = $XBD2
/*16867*/     OPC_CheckChild1Type, MVT::i64,
/*16869*/     OPC_CheckPredicate, 0, // Predicate_unindexedload
/*16871*/     OPC_CheckPredicate, 13, // Predicate_load
/*16873*/     OPC_MoveParent,
/*16874*/     OPC_RecordChild1, // #2 = $R1src
/*16875*/     OPC_SwitchType /*2 cases */, 16,  MVT::i32,// ->16894
/*16878*/       OPC_CheckComplexPat, /*CP*/0, /*#*/1, // selectBDXAddr20Only:$XBD2 #3 #4 #5
/*16881*/       OPC_EmitMergeInputChains1_0,
/*16882*/       OPC_MorphNodeTo, TARGET_VAL(SystemZ::ALC), 0|OPFL_Chain|OPFL_GlueInput|OPFL_GlueOutput|OPFL_MemRefs,
                    2/*#VTs*/, MVT::i32, MVT::i32, 4/*#Ops*/, 2, 3, 4, 5, 
                // Src: (adde:i32 (ld:i32 bdxaddr20only:i64:$XBD2)<<P:Predicate_unindexedload>><<P:Predicate_load>>, GR32:i32:$R1src) - Complexity = 19
                // Dst: (ALC:i32:i32 GR32:i32:$R1src, bdxaddr20only:i64:$XBD2)
/*16894*/     /*SwitchType*/ 16,  MVT::i64,// ->16912
/*16896*/       OPC_CheckComplexPat, /*CP*/0, /*#*/1, // selectBDXAddr20Only:$XBD2 #3 #4 #5
/*16899*/       OPC_EmitMergeInputChains1_0,
/*16900*/       OPC_MorphNodeTo, TARGET_VAL(SystemZ::ALCG), 0|OPFL_Chain|OPFL_GlueInput|OPFL_GlueOutput|OPFL_MemRefs,
                    2/*#VTs*/, MVT::i64, MVT::i32, 4/*#Ops*/, 2, 3, 4, 5, 
                // Src: (adde:i64 (ld:i64 bdxaddr20only:i64:$XBD2)<<P:Predicate_unindexedload>><<P:Predicate_load>>, GR64:i64:$R1src) - Complexity = 19
                // Dst: (ALCG:i64:i32 GR64:i64:$R1src, bdxaddr20only:i64:$XBD2)
/*16912*/     0, // EndSwitchType
/*16913*/   /*Scope*/ 28, /*->16942*/
/*16914*/     OPC_RecordChild0, // #0 = $R1src
/*16915*/     OPC_RecordChild1, // #1 = $R2
/*16916*/     OPC_SwitchType /*2 cases */, 10,  MVT::i32,// ->16929
/*16919*/       OPC_MorphNodeTo, TARGET_VAL(SystemZ::ALCR), 0|OPFL_GlueInput|OPFL_GlueOutput,
                    2/*#VTs*/, MVT::i32, MVT::i32, 2/*#Ops*/, 0, 1, 
                // Src: (adde:i32 GR32:i32:$R1src, GR32:i32:$R2) - Complexity = 3
                // Dst: (ALCR:i32:i32 GR32:i32:$R1src, GR32:i32:$R2)
/*16929*/     /*SwitchType*/ 10,  MVT::i64,// ->16941
/*16931*/       OPC_MorphNodeTo, TARGET_VAL(SystemZ::ALCGR), 0|OPFL_GlueInput|OPFL_GlueOutput,
                    2/*#VTs*/, MVT::i64, MVT::i32, 2/*#Ops*/, 0, 1, 
                // Src: (adde:i64 GR64:i64:$R1src, GR64:i64:$R2) - Complexity = 3
                // Dst: (ALCGR:i64:i32 GR64:i64:$R1src, GR64:i64:$R2)
/*16941*/     0, // EndSwitchType
/*16942*/   0, /*End of Scope*/
/*16943*/ /*SwitchOpcode*/ 60|128,1/*188*/,  TARGET_VAL(ISD::SUBC),// ->17135
/*16947*/   OPC_RecordChild0, // #0 = $R1src
/*16948*/   OPC_Scope, 27|128,1/*155*/, /*->17106*/ // 2 children in Scope
/*16951*/     OPC_MoveChild, 1,
/*16953*/     OPC_Scope, 101, /*->17056*/ // 3 children in Scope
/*16955*/       OPC_CheckOpcode, TARGET_VAL(ISD::LOAD),
/*16958*/       OPC_RecordMemRef,
/*16959*/       OPC_RecordNode, // #1 = 'ld' chained node
/*16960*/       OPC_CheckFoldableChainNode,
/*16961*/       OPC_RecordChild1, // #2 = $XBD2
/*16962*/       OPC_CheckChild1Type, MVT::i64,
/*16964*/       OPC_CheckPredicate, 0, // Predicate_unindexedload
/*16966*/       OPC_Scope, 41, /*->17009*/ // 3 children in Scope
/*16968*/         OPC_CheckPredicate, 13, // Predicate_load
/*16970*/         OPC_MoveParent,
/*16971*/         OPC_CheckType, MVT::i32,
/*16973*/         OPC_Scope, 16, /*->16991*/ // 2 children in Scope
/*16975*/           OPC_CheckComplexPat, /*CP*/7, /*#*/2, // selectBDXAddr12Pair:$XBD2 #3 #4 #5
/*16978*/           OPC_EmitMergeInputChains1_1,
/*16979*/           OPC_MorphNodeTo, TARGET_VAL(SystemZ::SL), 0|OPFL_Chain|OPFL_GlueOutput|OPFL_MemRefs,
                        2/*#VTs*/, MVT::i32, MVT::i32, 4/*#Ops*/, 0, 3, 4, 5, 
                    // Src: (subc:i32 GR32:i32:$R1src, (ld:i32 bdxaddr12pair:i64:$XBD2)<<P:Predicate_unindexedload>><<P:Predicate_load>>) - Complexity = 19
                    // Dst: (SL:i32:i32 GR32:i32:$R1src, bdxaddr12pair:i64:$XBD2)
/*16991*/         /*Scope*/ 16, /*->17008*/
/*16992*/           OPC_CheckComplexPat, /*CP*/8, /*#*/2, // selectBDXAddr20Pair:$XBD2 #3 #4 #5
/*16995*/           OPC_EmitMergeInputChains1_1,
/*16996*/           OPC_MorphNodeTo, TARGET_VAL(SystemZ::SLY), 0|OPFL_Chain|OPFL_GlueOutput|OPFL_MemRefs,
                        2/*#VTs*/, MVT::i32, MVT::i32, 4/*#Ops*/, 0, 3, 4, 5, 
                    // Src: (subc:i32 GR32:i32:$R1src, (ld:i32 bdxaddr20pair:i64:$XBD2)<<P:Predicate_unindexedload>><<P:Predicate_load>>) - Complexity = 19
                    // Dst: (SLY:i32:i32 GR32:i32:$R1src, bdxaddr20pair:i64:$XBD2)
/*17008*/         0, /*End of Scope*/
/*17009*/       /*Scope*/ 23, /*->17033*/
/*17010*/         OPC_CheckPredicate, 38, // Predicate_azextload
/*17012*/         OPC_CheckPredicate, 39, // Predicate_azextloadi32
/*17014*/         OPC_MoveParent,
/*17015*/         OPC_CheckType, MVT::i64,
/*17017*/         OPC_CheckComplexPat, /*CP*/0, /*#*/2, // selectBDXAddr20Only:$XBD2 #3 #4 #5
/*17020*/         OPC_EmitMergeInputChains1_1,
/*17021*/         OPC_MorphNodeTo, TARGET_VAL(SystemZ::SLGF), 0|OPFL_Chain|OPFL_GlueOutput|OPFL_MemRefs,
                      2/*#VTs*/, MVT::i64, MVT::i32, 4/*#Ops*/, 0, 3, 4, 5, 
                  // Src: (subc:i64 GR64:i64:$R1src, (ld:i64 bdxaddr20only:i64:$XBD2)<<P:Predicate_unindexedload>><<P:Predicate_azextload>><<P:Predicate_azextloadi32>>) - Complexity = 19
                  // Dst: (SLGF:i64:i32 GR64:i64:$R1src, bdxaddr20only:i64:$XBD2)
/*17033*/       /*Scope*/ 21, /*->17055*/
/*17034*/         OPC_CheckPredicate, 13, // Predicate_load
/*17036*/         OPC_MoveParent,
/*17037*/         OPC_CheckType, MVT::i64,
/*17039*/         OPC_CheckComplexPat, /*CP*/0, /*#*/2, // selectBDXAddr20Only:$XBD2 #3 #4 #5
/*17042*/         OPC_EmitMergeInputChains1_1,
/*17043*/         OPC_MorphNodeTo, TARGET_VAL(SystemZ::SLG), 0|OPFL_Chain|OPFL_GlueOutput|OPFL_MemRefs,
                      2/*#VTs*/, MVT::i64, MVT::i32, 4/*#Ops*/, 0, 3, 4, 5, 
                  // Src: (subc:i64 GR64:i64:$R1src, (ld:i64 bdxaddr20only:i64:$XBD2)<<P:Predicate_unindexedload>><<P:Predicate_load>>) - Complexity = 19
                  // Dst: (SLG:i64:i32 GR64:i64:$R1src, bdxaddr20only:i64:$XBD2)
/*17055*/       0, /*End of Scope*/
/*17056*/     /*Scope*/ 32, /*->17089*/
/*17057*/       OPC_CheckAndImm, 127|128,127|128,127|128,127|128,15/*4294967295*/, 
/*17063*/       OPC_RecordChild0, // #1 = $src2
/*17064*/       OPC_MoveParent,
/*17065*/       OPC_CheckType, MVT::i64,
/*17067*/       OPC_EmitInteger, MVT::i32, SystemZ::subreg_l32,
/*17070*/       OPC_EmitNode, TARGET_VAL(TargetOpcode::EXTRACT_SUBREG), 0,
                    1/*#VTs*/, MVT::i32, 2/*#Ops*/, 1, 2,  // Results = #3
/*17079*/       OPC_MorphNodeTo, TARGET_VAL(SystemZ::SLGFR), 0|OPFL_GlueOutput,
                    2/*#VTs*/, MVT::i64, MVT::i32, 2/*#Ops*/, 0, 3, 
                // Src: (subc:i64 GR64:i64:$src1, (and:i64 GR64:i64:$src2, 4294967295:i64)) - Complexity = 11
                // Dst: (SLGFR:i64:i32 GR64:i64:$src1, (EXTRACT_SUBREG:i32 GR64:i64:$src2, subreg_l32:i32))
/*17089*/     /*Scope*/ 15, /*->17105*/
/*17090*/       OPC_CheckOpcode, TARGET_VAL(ISD::ZERO_EXTEND),
/*17093*/       OPC_RecordChild0, // #1 = $src2
/*17094*/       OPC_MoveParent,
/*17095*/       OPC_MorphNodeTo, TARGET_VAL(SystemZ::SLGFR), 0|OPFL_GlueOutput,
                    2/*#VTs*/, MVT::i64, MVT::i32, 2/*#Ops*/, 0, 1, 
                // Src: (subc:i64 GR64:i64:$src1, (zext:i64 GR32:i32:$src2)) - Complexity = 6
                // Dst: (SLGFR:i64:i32 GR64:i64:$src1, GR32:i32:$src2)
/*17105*/     0, /*End of Scope*/
/*17106*/   /*Scope*/ 27, /*->17134*/
/*17107*/     OPC_RecordChild1, // #1 = $R2
/*17108*/     OPC_SwitchType /*2 cases */, 10,  MVT::i32,// ->17121
/*17111*/       OPC_MorphNodeTo, TARGET_VAL(SystemZ::SLR), 0|OPFL_GlueOutput,
                    2/*#VTs*/, MVT::i32, MVT::i32, 2/*#Ops*/, 0, 1, 
                // Src: (subc:i32 GR32:i32:$R1src, GR32:i32:$R2) - Complexity = 3
                // Dst: (SLR:i32:i32 GR32:i32:$R1src, GR32:i32:$R2)
/*17121*/     /*SwitchType*/ 10,  MVT::i64,// ->17133
/*17123*/       OPC_MorphNodeTo, TARGET_VAL(SystemZ::SLGR), 0|OPFL_GlueOutput,
                    2/*#VTs*/, MVT::i64, MVT::i32, 2/*#Ops*/, 0, 1, 
                // Src: (subc:i64 GR64:i64:$R1src, GR64:i64:$R2) - Complexity = 3
                // Dst: (SLGR:i64:i32 GR64:i64:$R1src, GR64:i64:$R2)
/*17133*/     0, // EndSwitchType
/*17134*/   0, /*End of Scope*/
/*17135*/ /*SwitchOpcode*/ 87,  TARGET_VAL(ISD::SUBE),// ->17225
/*17138*/   OPC_CaptureGlueInput,
/*17139*/   OPC_RecordChild0, // #0 = $R1src
/*17140*/   OPC_Scope, 54, /*->17196*/ // 2 children in Scope
/*17142*/     OPC_MoveChild, 1,
/*17144*/     OPC_CheckOpcode, TARGET_VAL(ISD::LOAD),
/*17147*/     OPC_RecordMemRef,
/*17148*/     OPC_RecordNode, // #1 = 'ld' chained node
/*17149*/     OPC_CheckFoldableChainNode,
/*17150*/     OPC_RecordChild1, // #2 = $XBD2
/*17151*/     OPC_CheckChild1Type, MVT::i64,
/*17153*/     OPC_CheckPredicate, 0, // Predicate_unindexedload
/*17155*/     OPC_CheckPredicate, 13, // Predicate_load
/*17157*/     OPC_MoveParent,
/*17158*/     OPC_SwitchType /*2 cases */, 16,  MVT::i32,// ->17177
/*17161*/       OPC_CheckComplexPat, /*CP*/0, /*#*/2, // selectBDXAddr20Only:$XBD2 #3 #4 #5
/*17164*/       OPC_EmitMergeInputChains1_1,
/*17165*/       OPC_MorphNodeTo, TARGET_VAL(SystemZ::SLB), 0|OPFL_Chain|OPFL_GlueInput|OPFL_GlueOutput|OPFL_MemRefs,
                    2/*#VTs*/, MVT::i32, MVT::i32, 4/*#Ops*/, 0, 3, 4, 5, 
                // Src: (sube:i32 GR32:i32:$R1src, (ld:i32 bdxaddr20only:i64:$XBD2)<<P:Predicate_unindexedload>><<P:Predicate_load>>) - Complexity = 19
                // Dst: (SLB:i32:i32 GR32:i32:$R1src, bdxaddr20only:i64:$XBD2)
/*17177*/     /*SwitchType*/ 16,  MVT::i64,// ->17195
/*17179*/       OPC_CheckComplexPat, /*CP*/0, /*#*/2, // selectBDXAddr20Only:$XBD2 #3 #4 #5
/*17182*/       OPC_EmitMergeInputChains1_1,
/*17183*/       OPC_MorphNodeTo, TARGET_VAL(SystemZ::SLBG), 0|OPFL_Chain|OPFL_GlueInput|OPFL_GlueOutput|OPFL_MemRefs,
                    2/*#VTs*/, MVT::i64, MVT::i32, 4/*#Ops*/, 0, 3, 4, 5, 
                // Src: (sube:i64 GR64:i64:$R1src, (ld:i64 bdxaddr20only:i64:$XBD2)<<P:Predicate_unindexedload>><<P:Predicate_load>>) - Complexity = 19
                // Dst: (SLBG:i64:i32 GR64:i64:$R1src, bdxaddr20only:i64:$XBD2)
/*17195*/     0, // EndSwitchType
/*17196*/   /*Scope*/ 27, /*->17224*/
/*17197*/     OPC_RecordChild1, // #1 = $R2
/*17198*/     OPC_SwitchType /*2 cases */, 10,  MVT::i32,// ->17211
/*17201*/       OPC_MorphNodeTo, TARGET_VAL(SystemZ::SLBR), 0|OPFL_GlueInput|OPFL_GlueOutput,
                    2/*#VTs*/, MVT::i32, MVT::i32, 2/*#Ops*/, 0, 1, 
                // Src: (sube:i32 GR32:i32:$R1src, GR32:i32:$R2) - Complexity = 3
                // Dst: (SLBR:i32:i32 GR32:i32:$R1src, GR32:i32:$R2)
/*17211*/     /*SwitchType*/ 10,  MVT::i64,// ->17223
/*17213*/       OPC_MorphNodeTo, TARGET_VAL(SystemZ::SLGBR), 0|OPFL_GlueInput|OPFL_GlueOutput,
                    2/*#VTs*/, MVT::i64, MVT::i32, 2/*#Ops*/, 0, 1, 
                // Src: (sube:i64 GR64:i64:$R1src, GR64:i64:$R2) - Complexity = 3
                // Dst: (SLGBR:i64:i32 GR64:i64:$R1src, GR64:i64:$R2)
/*17223*/     0, // EndSwitchType
/*17224*/   0, /*End of Scope*/
/*17225*/ /*SwitchOpcode*/ 113|128,4/*625*/,  TARGET_VAL(ISD::AND),// ->17854
/*17229*/   OPC_Scope, 75, /*->17306*/ // 8 children in Scope
/*17231*/     OPC_RecordChild0, // #0 = $R1src
/*17232*/     OPC_MoveChild, 1,
/*17234*/     OPC_CheckOpcode, TARGET_VAL(ISD::LOAD),
/*17237*/     OPC_RecordMemRef,
/*17238*/     OPC_RecordNode, // #1 = 'ld' chained node
/*17239*/     OPC_CheckFoldableChainNode,
/*17240*/     OPC_RecordChild1, // #2 = $XBD2
/*17241*/     OPC_CheckChild1Type, MVT::i64,
/*17243*/     OPC_CheckPredicate, 0, // Predicate_unindexedload
/*17245*/     OPC_CheckPredicate, 13, // Predicate_load
/*17247*/     OPC_MoveParent,
/*17248*/     OPC_SwitchType /*2 cases */, 36,  MVT::i32,// ->17287
/*17251*/       OPC_Scope, 16, /*->17269*/ // 2 children in Scope
/*17253*/         OPC_CheckComplexPat, /*CP*/7, /*#*/2, // selectBDXAddr12Pair:$XBD2 #3 #4 #5
/*17256*/         OPC_EmitMergeInputChains1_1,
/*17257*/         OPC_MorphNodeTo, TARGET_VAL(SystemZ::N), 0|OPFL_Chain|OPFL_MemRefs,
                      2/*#VTs*/, MVT::i32, MVT::i32, 4/*#Ops*/, 0, 3, 4, 5, 
                  // Src: (and:i32 GR32:i32:$R1src, (ld:i32 bdxaddr12pair:i64:$XBD2)<<P:Predicate_unindexedload>><<P:Predicate_load>>) - Complexity = 19
                  // Dst: (N:i32:i32 GR32:i32:$R1src, bdxaddr12pair:i64:$XBD2)
/*17269*/       /*Scope*/ 16, /*->17286*/
/*17270*/         OPC_CheckComplexPat, /*CP*/8, /*#*/2, // selectBDXAddr20Pair:$XBD2 #3 #4 #5
/*17273*/         OPC_EmitMergeInputChains1_1,
/*17274*/         OPC_MorphNodeTo, TARGET_VAL(SystemZ::NY), 0|OPFL_Chain|OPFL_MemRefs,
                      2/*#VTs*/, MVT::i32, MVT::i32, 4/*#Ops*/, 0, 3, 4, 5, 
                  // Src: (and:i32 GR32:i32:$R1src, (ld:i32 bdxaddr20pair:i64:$XBD2)<<P:Predicate_unindexedload>><<P:Predicate_load>>) - Complexity = 19
                  // Dst: (NY:i32:i32 GR32:i32:$R1src, bdxaddr20pair:i64:$XBD2)
/*17286*/       0, /*End of Scope*/
/*17287*/     /*SwitchType*/ 16,  MVT::i64,// ->17305
/*17289*/       OPC_CheckComplexPat, /*CP*/0, /*#*/2, // selectBDXAddr20Only:$XBD2 #3 #4 #5
/*17292*/       OPC_EmitMergeInputChains1_1,
/*17293*/       OPC_MorphNodeTo, TARGET_VAL(SystemZ::NG), 0|OPFL_Chain|OPFL_MemRefs,
                    2/*#VTs*/, MVT::i64, MVT::i32, 4/*#Ops*/, 0, 3, 4, 5, 
                // Src: (and:i64 GR64:i64:$R1src, (ld:i64 bdxaddr20only:i64:$XBD2)<<P:Predicate_unindexedload>><<P:Predicate_load>>) - Complexity = 19
                // Dst: (NG:i64:i32 GR64:i64:$R1src, bdxaddr20only:i64:$XBD2)
/*17305*/     0, // EndSwitchType
/*17306*/   /*Scope*/ 75, /*->17382*/
/*17307*/     OPC_MoveChild, 0,
/*17309*/     OPC_CheckOpcode, TARGET_VAL(ISD::LOAD),
/*17312*/     OPC_RecordMemRef,
/*17313*/     OPC_RecordNode, // #0 = 'ld' chained node
/*17314*/     OPC_CheckFoldableChainNode,
/*17315*/     OPC_RecordChild1, // #1 = $XBD2
/*17316*/     OPC_CheckChild1Type, MVT::i64,
/*17318*/     OPC_CheckPredicate, 0, // Predicate_unindexedload
/*17320*/     OPC_CheckPredicate, 13, // Predicate_load
/*17322*/     OPC_MoveParent,
/*17323*/     OPC_RecordChild1, // #2 = $R1src
/*17324*/     OPC_SwitchType /*2 cases */, 36,  MVT::i32,// ->17363
/*17327*/       OPC_Scope, 16, /*->17345*/ // 2 children in Scope
/*17329*/         OPC_CheckComplexPat, /*CP*/7, /*#*/1, // selectBDXAddr12Pair:$XBD2 #3 #4 #5
/*17332*/         OPC_EmitMergeInputChains1_0,
/*17333*/         OPC_MorphNodeTo, TARGET_VAL(SystemZ::N), 0|OPFL_Chain|OPFL_MemRefs,
                      2/*#VTs*/, MVT::i32, MVT::i32, 4/*#Ops*/, 2, 3, 4, 5, 
                  // Src: (and:i32 (ld:i32 bdxaddr12pair:i64:$XBD2)<<P:Predicate_unindexedload>><<P:Predicate_load>>, GR32:i32:$R1src) - Complexity = 19
                  // Dst: (N:i32:i32 GR32:i32:$R1src, bdxaddr12pair:i64:$XBD2)
/*17345*/       /*Scope*/ 16, /*->17362*/
/*17346*/         OPC_CheckComplexPat, /*CP*/8, /*#*/1, // selectBDXAddr20Pair:$XBD2 #3 #4 #5
/*17349*/         OPC_EmitMergeInputChains1_0,
/*17350*/         OPC_MorphNodeTo, TARGET_VAL(SystemZ::NY), 0|OPFL_Chain|OPFL_MemRefs,
                      2/*#VTs*/, MVT::i32, MVT::i32, 4/*#Ops*/, 2, 3, 4, 5, 
                  // Src: (and:i32 (ld:i32 bdxaddr20pair:i64:$XBD2)<<P:Predicate_unindexedload>><<P:Predicate_load>>, GR32:i32:$R1src) - Complexity = 19
                  // Dst: (NY:i32:i32 GR32:i32:$R1src, bdxaddr20pair:i64:$XBD2)
/*17362*/       0, /*End of Scope*/
/*17363*/     /*SwitchType*/ 16,  MVT::i64,// ->17381
/*17365*/       OPC_CheckComplexPat, /*CP*/0, /*#*/1, // selectBDXAddr20Only:$XBD2 #3 #4 #5
/*17368*/       OPC_EmitMergeInputChains1_0,
/*17369*/       OPC_MorphNodeTo, TARGET_VAL(SystemZ::NG), 0|OPFL_Chain|OPFL_MemRefs,
                    2/*#VTs*/, MVT::i64, MVT::i32, 4/*#Ops*/, 2, 3, 4, 5, 
                // Src: (and:i64 (ld:i64 bdxaddr20only:i64:$XBD2)<<P:Predicate_unindexedload>><<P:Predicate_load>>, GR64:i64:$R1src) - Complexity = 19
                // Dst: (NG:i64:i32 GR64:i64:$R1src, bdxaddr20only:i64:$XBD2)
/*17381*/     0, // EndSwitchType
/*17382*/   /*Scope*/ 28, /*->17411*/
/*17383*/     OPC_CheckAndImm, 127|128,1/*255*/, 
/*17386*/     OPC_RecordChild0, // #0 = $R2
/*17387*/     OPC_CheckType, MVT::i32,
/*17389*/     OPC_Scope, 10, /*->17401*/ // 2 children in Scope
/*17391*/       OPC_CheckPatternPredicate, 0, // (Subtarget.hasHighWord())
/*17393*/       OPC_MorphNodeTo, TARGET_VAL(SystemZ::LLCRMux), 0,
                    1/*#VTs*/, MVT::i32, 1/*#Ops*/, 0, 
                // Src: (and:i32 GRX32:i32:$R2, 255:i32) - Complexity = 8
                // Dst: (LLCRMux:i32 GRX32:i32:$R2)
/*17401*/     /*Scope*/ 8, /*->17410*/
/*17402*/       OPC_MorphNodeTo, TARGET_VAL(SystemZ::LLCR), 0,
                    1/*#VTs*/, MVT::i32, 1/*#Ops*/, 0, 
                // Src: (and:i32 GR32:i32:$R2, 255:i32) - Complexity = 8
                // Dst: (LLCR:i32 GR32:i32:$R2)
/*17410*/     0, /*End of Scope*/
/*17411*/   /*Scope*/ 29, /*->17441*/
/*17412*/     OPC_CheckAndImm, 127|128,127|128,3/*65535*/, 
/*17416*/     OPC_RecordChild0, // #0 = $R2
/*17417*/     OPC_CheckType, MVT::i32,
/*17419*/     OPC_Scope, 10, /*->17431*/ // 2 children in Scope
/*17421*/       OPC_CheckPatternPredicate, 0, // (Subtarget.hasHighWord())
/*17423*/       OPC_MorphNodeTo, TARGET_VAL(SystemZ::LLHRMux), 0,
                    1/*#VTs*/, MVT::i32, 1/*#Ops*/, 0, 
                // Src: (and:i32 GRX32:i32:$R2, 65535:i32) - Complexity = 8
                // Dst: (LLHRMux:i32 GRX32:i32:$R2)
/*17431*/     /*Scope*/ 8, /*->17440*/
/*17432*/       OPC_MorphNodeTo, TARGET_VAL(SystemZ::LLHR), 0,
                    1/*#VTs*/, MVT::i32, 1/*#Ops*/, 0, 
                // Src: (and:i32 GR32:i32:$R2, 65535:i32) - Complexity = 8
                // Dst: (LLHR:i32 GR32:i32:$R2)
/*17440*/     0, /*End of Scope*/
/*17441*/   /*Scope*/ 14, /*->17456*/
/*17442*/     OPC_CheckAndImm, 127|128,1/*255*/, 
/*17445*/     OPC_RecordChild0, // #0 = $R2
/*17446*/     OPC_CheckType, MVT::i64,
/*17448*/     OPC_MorphNodeTo, TARGET_VAL(SystemZ::LLGCR), 0,
                  1/*#VTs*/, MVT::i64, 1/*#Ops*/, 0, 
              // Src: (and:i64 GR64:i64:$R2, 255:i64) - Complexity = 8
              // Dst: (LLGCR:i64 GR64:i64:$R2)
/*17456*/   /*Scope*/ 15, /*->17472*/
/*17457*/     OPC_CheckAndImm, 127|128,127|128,3/*65535*/, 
/*17461*/     OPC_RecordChild0, // #0 = $R2
/*17462*/     OPC_CheckType, MVT::i64,
/*17464*/     OPC_MorphNodeTo, TARGET_VAL(SystemZ::LLGHR), 0,
                  1/*#VTs*/, MVT::i64, 1/*#Ops*/, 0, 
              // Src: (and:i64 GR64:i64:$R2, 65535:i64) - Complexity = 8
              // Dst: (LLGHR:i64 GR64:i64:$R2)
/*17472*/   /*Scope*/ 29, /*->17502*/
/*17473*/     OPC_CheckAndImm, 127|128,127|128,127|128,127|128,15/*4294967295*/, 
/*17479*/     OPC_RecordChild0, // #0 = $src
/*17480*/     OPC_CheckType, MVT::i64,
/*17482*/     OPC_EmitInteger, MVT::i32, SystemZ::subreg_l32,
/*17485*/     OPC_EmitNode, TARGET_VAL(TargetOpcode::EXTRACT_SUBREG), 0,
                  1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1,  // Results = #2
/*17494*/     OPC_MorphNodeTo, TARGET_VAL(SystemZ::LLGFR), 0,
                  1/*#VTs*/, MVT::i64, 1/*#Ops*/, 2, 
              // Src: (and:i64 GR64:i64:$src, 4294967295:i64) - Complexity = 8
              // Dst: (LLGFR:i64 (EXTRACT_SUBREG:i32 GR64:i64:$src, subreg_l32:i32))
/*17502*/   /*Scope*/ 93|128,2/*349*/, /*->17853*/
/*17504*/     OPC_RecordChild0, // #0 = $R1src
/*17505*/     OPC_RecordChild1, // #1 = $I2
/*17506*/     OPC_Scope, 61|128,2/*317*/, /*->17826*/ // 3 children in Scope
/*17509*/       OPC_MoveChild, 1,
/*17511*/       OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*17514*/       OPC_Scope, 22, /*->17538*/ // 13 children in Scope
/*17516*/         OPC_CheckPredicate, 66, // Predicate_imm32ll16c
/*17518*/         OPC_MoveParent,
/*17519*/         OPC_CheckType, MVT::i32,
/*17521*/         OPC_CheckPatternPredicate, 0, // (Subtarget.hasHighWord())
/*17523*/         OPC_EmitConvertToTarget, 1,
/*17525*/         OPC_EmitNodeXForm, 6, 2, // LL16
/*17528*/         OPC_MorphNodeTo, TARGET_VAL(SystemZ::NILMux), 0,
                      2/*#VTs*/, MVT::i32, MVT::i32, 2/*#Ops*/, 0, 3, 
                  // Src: (and:i32 GRX32:i32:$R1src, (imm:i32)<<P:Predicate_imm32ll16c>><<X:LL16>>:$I2) - Complexity = 7
                  // Dst: (NILMux:i32:i32 GRX32:i32:$R1src, (LL16:i32 (imm:i32):$I2))
/*17538*/       /*Scope*/ 22, /*->17561*/
/*17539*/         OPC_CheckPredicate, 67, // Predicate_imm32lh16c
/*17541*/         OPC_MoveParent,
/*17542*/         OPC_CheckType, MVT::i32,
/*17544*/         OPC_CheckPatternPredicate, 0, // (Subtarget.hasHighWord())
/*17546*/         OPC_EmitConvertToTarget, 1,
/*17548*/         OPC_EmitNodeXForm, 7, 2, // LH16
/*17551*/         OPC_MorphNodeTo, TARGET_VAL(SystemZ::NIHMux), 0,
                      2/*#VTs*/, MVT::i32, MVT::i32, 2/*#Ops*/, 0, 3, 
                  // Src: (and:i32 GRX32:i32:$R1src, (imm:i32)<<P:Predicate_imm32lh16c>><<X:LH16>>:$I2) - Complexity = 7
                  // Dst: (NIHMux:i32:i32 GRX32:i32:$R1src, (LH16:i32 (imm:i32):$I2))
/*17561*/       /*Scope*/ 20, /*->17582*/
/*17562*/         OPC_CheckPredicate, 66, // Predicate_imm32ll16c
/*17564*/         OPC_MoveParent,
/*17565*/         OPC_CheckType, MVT::i32,
/*17567*/         OPC_EmitConvertToTarget, 1,
/*17569*/         OPC_EmitNodeXForm, 6, 2, // LL16
/*17572*/         OPC_MorphNodeTo, TARGET_VAL(SystemZ::NILL), 0,
                      2/*#VTs*/, MVT::i32, MVT::i32, 2/*#Ops*/, 0, 3, 
                  // Src: (and:i32 GR32:i32:$R1src, (imm:i32)<<P:Predicate_imm32ll16c>><<X:LL16>>:$I2) - Complexity = 7
                  // Dst: (NILL:i32:i32 GR32:i32:$R1src, (LL16:i32 (imm:i32):$I2))
/*17582*/       /*Scope*/ 20, /*->17603*/
/*17583*/         OPC_CheckPredicate, 67, // Predicate_imm32lh16c
/*17585*/         OPC_MoveParent,
/*17586*/         OPC_CheckType, MVT::i32,
/*17588*/         OPC_EmitConvertToTarget, 1,
/*17590*/         OPC_EmitNodeXForm, 7, 2, // LH16
/*17593*/         OPC_MorphNodeTo, TARGET_VAL(SystemZ::NILH), 0,
                      2/*#VTs*/, MVT::i32, MVT::i32, 2/*#Ops*/, 0, 3, 
                  // Src: (and:i32 GR32:i32:$R1src, (imm:i32)<<P:Predicate_imm32lh16c>><<X:LH16>>:$I2) - Complexity = 7
                  // Dst: (NILH:i32:i32 GR32:i32:$R1src, (LH16:i32 (imm:i32):$I2))
/*17603*/       /*Scope*/ 20, /*->17624*/
/*17604*/         OPC_CheckPredicate, 66, // Predicate_imm32ll16c
/*17606*/         OPC_MoveParent,
/*17607*/         OPC_CheckType, MVT::i32,
/*17609*/         OPC_EmitConvertToTarget, 1,
/*17611*/         OPC_EmitNodeXForm, 6, 2, // LL16
/*17614*/         OPC_MorphNodeTo, TARGET_VAL(SystemZ::NIHL), 0,
                      2/*#VTs*/, MVT::i32, MVT::i32, 2/*#Ops*/, 0, 3, 
                  // Src: (and:i32 GRH32:i32:$R1src, (imm:i32)<<P:Predicate_imm32ll16c>><<X:LL16>>:$I2) - Complexity = 7
                  // Dst: (NIHL:i32:i32 GRH32:i32:$R1src, (LL16:i32 (imm:i32):$I2))
/*17624*/       /*Scope*/ 20, /*->17645*/
/*17625*/         OPC_CheckPredicate, 67, // Predicate_imm32lh16c
/*17627*/         OPC_MoveParent,
/*17628*/         OPC_CheckType, MVT::i32,
/*17630*/         OPC_EmitConvertToTarget, 1,
/*17632*/         OPC_EmitNodeXForm, 7, 2, // LH16
/*17635*/         OPC_MorphNodeTo, TARGET_VAL(SystemZ::NIHH), 0,
                      2/*#VTs*/, MVT::i32, MVT::i32, 2/*#Ops*/, 0, 3, 
                  // Src: (and:i32 GRH32:i32:$R1src, (imm:i32)<<P:Predicate_imm32lh16c>><<X:LH16>>:$I2) - Complexity = 7
                  // Dst: (NIHH:i32:i32 GRH32:i32:$R1src, (LH16:i32 (imm:i32):$I2))
/*17645*/       /*Scope*/ 20, /*->17666*/
/*17646*/         OPC_CheckPredicate, 68, // Predicate_imm64ll16c
/*17648*/         OPC_MoveParent,
/*17649*/         OPC_CheckType, MVT::i64,
/*17651*/         OPC_EmitConvertToTarget, 1,
/*17653*/         OPC_EmitNodeXForm, 6, 2, // LL16
/*17656*/         OPC_MorphNodeTo, TARGET_VAL(SystemZ::NILL64), 0,
                      2/*#VTs*/, MVT::i64, MVT::i32, 2/*#Ops*/, 0, 3, 
                  // Src: (and:i64 GR64:i64:$R1src, (imm:i64)<<P:Predicate_imm64ll16c>><<X:LL16>>:$I2) - Complexity = 7
                  // Dst: (NILL64:i64:i32 GR64:i64:$R1src, (LL16:i64 (imm:i64):$I2))
/*17666*/       /*Scope*/ 20, /*->17687*/
/*17667*/         OPC_CheckPredicate, 69, // Predicate_imm64lh16c
/*17669*/         OPC_MoveParent,
/*17670*/         OPC_CheckType, MVT::i64,
/*17672*/         OPC_EmitConvertToTarget, 1,
/*17674*/         OPC_EmitNodeXForm, 7, 2, // LH16
/*17677*/         OPC_MorphNodeTo, TARGET_VAL(SystemZ::NILH64), 0,
                      2/*#VTs*/, MVT::i64, MVT::i32, 2/*#Ops*/, 0, 3, 
                  // Src: (and:i64 GR64:i64:$R1src, (imm:i64)<<P:Predicate_imm64lh16c>><<X:LH16>>:$I2) - Complexity = 7
                  // Dst: (NILH64:i64:i32 GR64:i64:$R1src, (LH16:i64 (imm:i64):$I2))
/*17687*/       /*Scope*/ 20, /*->17708*/
/*17688*/         OPC_CheckPredicate, 70, // Predicate_imm64hl16c
/*17690*/         OPC_MoveParent,
/*17691*/         OPC_CheckType, MVT::i64,
/*17693*/         OPC_EmitConvertToTarget, 1,
/*17695*/         OPC_EmitNodeXForm, 8, 2, // HL16
/*17698*/         OPC_MorphNodeTo, TARGET_VAL(SystemZ::NIHL64), 0,
                      2/*#VTs*/, MVT::i64, MVT::i32, 2/*#Ops*/, 0, 3, 
                  // Src: (and:i64 GR64:i64:$R1src, (imm:i64)<<P:Predicate_imm64hl16c>><<X:HL16>>:$I2) - Complexity = 7
                  // Dst: (NIHL64:i64:i32 GR64:i64:$R1src, (HL16:i64 (imm:i64):$I2))
/*17708*/       /*Scope*/ 20, /*->17729*/
/*17709*/         OPC_CheckPredicate, 71, // Predicate_imm64hh16c
/*17711*/         OPC_MoveParent,
/*17712*/         OPC_CheckType, MVT::i64,
/*17714*/         OPC_EmitConvertToTarget, 1,
/*17716*/         OPC_EmitNodeXForm, 9, 2, // HH16
/*17719*/         OPC_MorphNodeTo, TARGET_VAL(SystemZ::NIHH64), 0,
                      2/*#VTs*/, MVT::i64, MVT::i32, 2/*#Ops*/, 0, 3, 
                  // Src: (and:i64 GR64:i64:$R1src, (imm:i64)<<P:Predicate_imm64hh16c>><<X:HH16>>:$I2) - Complexity = 7
                  // Dst: (NIHH64:i64:i32 GR64:i64:$R1src, (HH16:i64 (imm:i64):$I2))
/*17729*/       /*Scope*/ 20, /*->17750*/
/*17730*/         OPC_CheckPredicate, 72, // Predicate_imm64lf32c
/*17732*/         OPC_MoveParent,
/*17733*/         OPC_CheckType, MVT::i64,
/*17735*/         OPC_EmitConvertToTarget, 1,
/*17737*/         OPC_EmitNodeXForm, 3, 2, // LF32
/*17740*/         OPC_MorphNodeTo, TARGET_VAL(SystemZ::NILF64), 0,
                      2/*#VTs*/, MVT::i64, MVT::i32, 2/*#Ops*/, 0, 3, 
                  // Src: (and:i64 GR64:i64:$R1src, (imm:i64)<<P:Predicate_imm64lf32c>><<X:LF32>>:$I2) - Complexity = 7
                  // Dst: (NILF64:i64:i32 GR64:i64:$R1src, (LF32:i64 (imm:i64):$I2))
/*17750*/       /*Scope*/ 20, /*->17771*/
/*17751*/         OPC_CheckPredicate, 73, // Predicate_imm64hf32c
/*17753*/         OPC_MoveParent,
/*17754*/         OPC_CheckType, MVT::i64,
/*17756*/         OPC_EmitConvertToTarget, 1,
/*17758*/         OPC_EmitNodeXForm, 4, 2, // HF32
/*17761*/         OPC_MorphNodeTo, TARGET_VAL(SystemZ::NIHF64), 0,
                      2/*#VTs*/, MVT::i64, MVT::i32, 2/*#Ops*/, 0, 3, 
                  // Src: (and:i64 GR64:i64:$R1src, (imm:i64)<<P:Predicate_imm64hf32c>><<X:HF32>>:$I2) - Complexity = 7
                  // Dst: (NIHF64:i64:i32 GR64:i64:$R1src, (HF32:i64 (imm:i64):$I2))
/*17771*/       /*Scope*/ 53, /*->17825*/
/*17772*/         OPC_MoveParent,
/*17773*/         OPC_CheckType, MVT::i32,
/*17775*/         OPC_Scope, 17, /*->17794*/ // 2 children in Scope
/*17777*/           OPC_CheckPatternPredicate, 0, // (Subtarget.hasHighWord())
/*17779*/           OPC_EmitConvertToTarget, 1,
/*17781*/           OPC_EmitNodeXForm, 5, 2, // UIMM32
/*17784*/           OPC_MorphNodeTo, TARGET_VAL(SystemZ::NIFMux), 0,
                        2/*#VTs*/, MVT::i32, MVT::i32, 2/*#Ops*/, 0, 3, 
                    // Src: (and:i32 GRX32:i32:$R1src, (imm:i32)<<X:UIMM32>>:$I2) - Complexity = 6
                    // Dst: (NIFMux:i32:i32 GRX32:i32:$R1src, (UIMM32:i32 (imm:i32):$I2))
/*17794*/         /*Scope*/ 29, /*->17824*/
/*17795*/           OPC_EmitConvertToTarget, 1,
/*17797*/           OPC_EmitNodeXForm, 5, 2, // UIMM32
/*17800*/           OPC_Scope, 10, /*->17812*/ // 2 children in Scope
/*17802*/             OPC_MorphNodeTo, TARGET_VAL(SystemZ::NILF), 0,
                          2/*#VTs*/, MVT::i32, MVT::i32, 2/*#Ops*/, 0, 3, 
                      // Src: (and:i32 GR32:i32:$R1src, (imm:i32)<<X:UIMM32>>:$I2) - Complexity = 6
                      // Dst: (NILF:i32:i32 GR32:i32:$R1src, (UIMM32:i32 (imm:i32):$I2))
/*17812*/           /*Scope*/ 10, /*->17823*/
/*17813*/             OPC_MorphNodeTo, TARGET_VAL(SystemZ::NIHF), 0,
                          2/*#VTs*/, MVT::i32, MVT::i32, 2/*#Ops*/, 0, 3, 
                      // Src: (and:i32 GRH32:i32:$R1src, (imm:i32)<<X:UIMM32>>:$I2) - Complexity = 6
                      // Dst: (NIHF:i32:i32 GRH32:i32:$R1src, (UIMM32:i32 (imm:i32):$I2))
/*17823*/           0, /*End of Scope*/
/*17824*/         0, /*End of Scope*/
/*17825*/       0, /*End of Scope*/
/*17826*/     /*Scope*/ 12, /*->17839*/
/*17827*/       OPC_CheckType, MVT::i32,
/*17829*/       OPC_MorphNodeTo, TARGET_VAL(SystemZ::NR), 0,
                    2/*#VTs*/, MVT::i32, MVT::i32, 2/*#Ops*/, 0, 1, 
                // Src: (and:i32 GR32:i32:$R1src, GR32:i32:$R2) - Complexity = 3
                // Dst: (NR:i32:i32 GR32:i32:$R1src, GR32:i32:$R2)
/*17839*/     /*Scope*/ 12, /*->17852*/
/*17840*/       OPC_CheckType, MVT::i64,
/*17842*/       OPC_MorphNodeTo, TARGET_VAL(SystemZ::NGR), 0,
                    2/*#VTs*/, MVT::i64, MVT::i32, 2/*#Ops*/, 0, 1, 
                // Src: (and:i64 GR64:i64:$R1src, GR64:i64:$R2) - Complexity = 3
                // Dst: (NGR:i64:i32 GR64:i64:$R1src, GR64:i64:$R2)
/*17852*/     0, /*End of Scope*/
/*17853*/   0, /*End of Scope*/
/*17854*/ /*SwitchOpcode*/ 10|128,4/*522*/,  TARGET_VAL(ISD::MUL),// ->18380
/*17858*/   OPC_Scope, 14|128,1/*142*/, /*->18003*/ // 7 children in Scope
/*17861*/     OPC_RecordChild0, // #0 = $R1src
/*17862*/     OPC_MoveChild, 1,
/*17864*/     OPC_CheckOpcode, TARGET_VAL(ISD::LOAD),
/*17867*/     OPC_RecordMemRef,
/*17868*/     OPC_RecordNode, // #1 = 'ld' chained node
/*17869*/     OPC_CheckFoldableChainNode,
/*17870*/     OPC_RecordChild1, // #2 = $XBD2
/*17871*/     OPC_CheckChild1Type, MVT::i64,
/*17873*/     OPC_CheckPredicate, 0, // Predicate_unindexedload
/*17875*/     OPC_Scope, 41, /*->17918*/ // 4 children in Scope
/*17877*/       OPC_CheckPredicate, 35, // Predicate_asextload
/*17879*/       OPC_CheckPredicate, 36, // Predicate_asextloadi16
/*17881*/       OPC_MoveParent,
/*17882*/       OPC_CheckType, MVT::i32,
/*17884*/       OPC_Scope, 15, /*->17901*/ // 2 children in Scope
/*17886*/         OPC_CheckComplexPat, /*CP*/7, /*#*/2, // selectBDXAddr12Pair:$XBD2 #3 #4 #5
/*17889*/         OPC_EmitMergeInputChains1_1,
/*17890*/         OPC_MorphNodeTo, TARGET_VAL(SystemZ::MH), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i32, 4/*#Ops*/, 0, 3, 4, 5, 
                  // Src: (mul:i32 GR32:i32:$R1src, (ld:i32 bdxaddr12pair:i64:$XBD2)<<P:Predicate_unindexedload>><<P:Predicate_asextload>><<P:Predicate_asextloadi16>>) - Complexity = 19
                  // Dst: (MH:i32 GR32:i32:$R1src, bdxaddr12pair:i64:$XBD2)
/*17901*/       /*Scope*/ 15, /*->17917*/
/*17902*/         OPC_CheckComplexPat, /*CP*/8, /*#*/2, // selectBDXAddr20Pair:$XBD2 #3 #4 #5
/*17905*/         OPC_EmitMergeInputChains1_1,
/*17906*/         OPC_MorphNodeTo, TARGET_VAL(SystemZ::MHY), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i32, 4/*#Ops*/, 0, 3, 4, 5, 
                  // Src: (mul:i32 GR32:i32:$R1src, (ld:i32 bdxaddr20pair:i64:$XBD2)<<P:Predicate_unindexedload>><<P:Predicate_asextload>><<P:Predicate_asextloadi16>>) - Complexity = 19
                  // Dst: (MHY:i32 GR32:i32:$R1src, bdxaddr20pair:i64:$XBD2)
/*17917*/       0, /*End of Scope*/
/*17918*/     /*Scope*/ 39, /*->17958*/
/*17919*/       OPC_CheckPredicate, 13, // Predicate_load
/*17921*/       OPC_MoveParent,
/*17922*/       OPC_CheckType, MVT::i32,
/*17924*/       OPC_Scope, 15, /*->17941*/ // 2 children in Scope
/*17926*/         OPC_CheckComplexPat, /*CP*/7, /*#*/2, // selectBDXAddr12Pair:$XBD2 #3 #4 #5
/*17929*/         OPC_EmitMergeInputChains1_1,
/*17930*/         OPC_MorphNodeTo, TARGET_VAL(SystemZ::MS), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i32, 4/*#Ops*/, 0, 3, 4, 5, 
                  // Src: (mul:i32 GR32:i32:$R1src, (ld:i32 bdxaddr12pair:i64:$XBD2)<<P:Predicate_unindexedload>><<P:Predicate_load>>) - Complexity = 19
                  // Dst: (MS:i32 GR32:i32:$R1src, bdxaddr12pair:i64:$XBD2)
/*17941*/       /*Scope*/ 15, /*->17957*/
/*17942*/         OPC_CheckComplexPat, /*CP*/8, /*#*/2, // selectBDXAddr20Pair:$XBD2 #3 #4 #5
/*17945*/         OPC_EmitMergeInputChains1_1,
/*17946*/         OPC_MorphNodeTo, TARGET_VAL(SystemZ::MSY), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i32, 4/*#Ops*/, 0, 3, 4, 5, 
                  // Src: (mul:i32 GR32:i32:$R1src, (ld:i32 bdxaddr20pair:i64:$XBD2)<<P:Predicate_unindexedload>><<P:Predicate_load>>) - Complexity = 19
                  // Dst: (MSY:i32 GR32:i32:$R1src, bdxaddr20pair:i64:$XBD2)
/*17957*/       0, /*End of Scope*/
/*17958*/     /*Scope*/ 22, /*->17981*/
/*17959*/       OPC_CheckPredicate, 35, // Predicate_asextload
/*17961*/       OPC_CheckPredicate, 37, // Predicate_asextloadi32
/*17963*/       OPC_MoveParent,
/*17964*/       OPC_CheckType, MVT::i64,
/*17966*/       OPC_CheckComplexPat, /*CP*/0, /*#*/2, // selectBDXAddr20Only:$XBD2 #3 #4 #5
/*17969*/       OPC_EmitMergeInputChains1_1,
/*17970*/       OPC_MorphNodeTo, TARGET_VAL(SystemZ::MSGF), 0|OPFL_Chain|OPFL_MemRefs,
                    1/*#VTs*/, MVT::i64, 4/*#Ops*/, 0, 3, 4, 5, 
                // Src: (mul:i64 GR64:i64:$R1src, (ld:i64 bdxaddr20only:i64:$XBD2)<<P:Predicate_unindexedload>><<P:Predicate_asextload>><<P:Predicate_asextloadi32>>) - Complexity = 19
                // Dst: (MSGF:i64 GR64:i64:$R1src, bdxaddr20only:i64:$XBD2)
/*17981*/     /*Scope*/ 20, /*->18002*/
/*17982*/       OPC_CheckPredicate, 13, // Predicate_load
/*17984*/       OPC_MoveParent,
/*17985*/       OPC_CheckType, MVT::i64,
/*17987*/       OPC_CheckComplexPat, /*CP*/0, /*#*/2, // selectBDXAddr20Only:$XBD2 #3 #4 #5
/*17990*/       OPC_EmitMergeInputChains1_1,
/*17991*/       OPC_MorphNodeTo, TARGET_VAL(SystemZ::MSG), 0|OPFL_Chain|OPFL_MemRefs,
                    1/*#VTs*/, MVT::i64, 4/*#Ops*/, 0, 3, 4, 5, 
                // Src: (mul:i64 GR64:i64:$R1src, (ld:i64 bdxaddr20only:i64:$XBD2)<<P:Predicate_unindexedload>><<P:Predicate_load>>) - Complexity = 19
                // Dst: (MSG:i64 GR64:i64:$R1src, bdxaddr20only:i64:$XBD2)
/*18002*/     0, /*End of Scope*/
/*18003*/   /*Scope*/ 17|128,1/*145*/, /*->18150*/
/*18005*/     OPC_MoveChild, 0,
/*18007*/     OPC_CheckOpcode, TARGET_VAL(ISD::LOAD),
/*18010*/     OPC_RecordMemRef,
/*18011*/     OPC_RecordNode, // #0 = 'ld' chained node
/*18012*/     OPC_CheckFoldableChainNode,
/*18013*/     OPC_RecordChild1, // #1 = $XBD2
/*18014*/     OPC_CheckChild1Type, MVT::i64,
/*18016*/     OPC_CheckPredicate, 0, // Predicate_unindexedload
/*18018*/     OPC_Scope, 42, /*->18062*/ // 4 children in Scope
/*18020*/       OPC_CheckPredicate, 35, // Predicate_asextload
/*18022*/       OPC_CheckPredicate, 36, // Predicate_asextloadi16
/*18024*/       OPC_MoveParent,
/*18025*/       OPC_RecordChild1, // #2 = $R1src
/*18026*/       OPC_CheckType, MVT::i32,
/*18028*/       OPC_Scope, 15, /*->18045*/ // 2 children in Scope
/*18030*/         OPC_CheckComplexPat, /*CP*/7, /*#*/1, // selectBDXAddr12Pair:$XBD2 #3 #4 #5
/*18033*/         OPC_EmitMergeInputChains1_0,
/*18034*/         OPC_MorphNodeTo, TARGET_VAL(SystemZ::MH), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i32, 4/*#Ops*/, 2, 3, 4, 5, 
                  // Src: (mul:i32 (ld:i32 bdxaddr12pair:i64:$XBD2)<<P:Predicate_unindexedload>><<P:Predicate_asextload>><<P:Predicate_asextloadi16>>, GR32:i32:$R1src) - Complexity = 19
                  // Dst: (MH:i32 GR32:i32:$R1src, bdxaddr12pair:i64:$XBD2)
/*18045*/       /*Scope*/ 15, /*->18061*/
/*18046*/         OPC_CheckComplexPat, /*CP*/8, /*#*/1, // selectBDXAddr20Pair:$XBD2 #3 #4 #5
/*18049*/         OPC_EmitMergeInputChains1_0,
/*18050*/         OPC_MorphNodeTo, TARGET_VAL(SystemZ::MHY), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i32, 4/*#Ops*/, 2, 3, 4, 5, 
                  // Src: (mul:i32 (ld:i32 bdxaddr20pair:i64:$XBD2)<<P:Predicate_unindexedload>><<P:Predicate_asextload>><<P:Predicate_asextloadi16>>, GR32:i32:$R1src) - Complexity = 19
                  // Dst: (MHY:i32 GR32:i32:$R1src, bdxaddr20pair:i64:$XBD2)
/*18061*/       0, /*End of Scope*/
/*18062*/     /*Scope*/ 40, /*->18103*/
/*18063*/       OPC_CheckPredicate, 13, // Predicate_load
/*18065*/       OPC_MoveParent,
/*18066*/       OPC_RecordChild1, // #2 = $R1src
/*18067*/       OPC_CheckType, MVT::i32,
/*18069*/       OPC_Scope, 15, /*->18086*/ // 2 children in Scope
/*18071*/         OPC_CheckComplexPat, /*CP*/7, /*#*/1, // selectBDXAddr12Pair:$XBD2 #3 #4 #5
/*18074*/         OPC_EmitMergeInputChains1_0,
/*18075*/         OPC_MorphNodeTo, TARGET_VAL(SystemZ::MS), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i32, 4/*#Ops*/, 2, 3, 4, 5, 
                  // Src: (mul:i32 (ld:i32 bdxaddr12pair:i64:$XBD2)<<P:Predicate_unindexedload>><<P:Predicate_load>>, GR32:i32:$R1src) - Complexity = 19
                  // Dst: (MS:i32 GR32:i32:$R1src, bdxaddr12pair:i64:$XBD2)
/*18086*/       /*Scope*/ 15, /*->18102*/
/*18087*/         OPC_CheckComplexPat, /*CP*/8, /*#*/1, // selectBDXAddr20Pair:$XBD2 #3 #4 #5
/*18090*/         OPC_EmitMergeInputChains1_0,
/*18091*/         OPC_MorphNodeTo, TARGET_VAL(SystemZ::MSY), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i32, 4/*#Ops*/, 2, 3, 4, 5, 
                  // Src: (mul:i32 (ld:i32 bdxaddr20pair:i64:$XBD2)<<P:Predicate_unindexedload>><<P:Predicate_load>>, GR32:i32:$R1src) - Complexity = 19
                  // Dst: (MSY:i32 GR32:i32:$R1src, bdxaddr20pair:i64:$XBD2)
/*18102*/       0, /*End of Scope*/
/*18103*/     /*Scope*/ 23, /*->18127*/
/*18104*/       OPC_CheckPredicate, 35, // Predicate_asextload
/*18106*/       OPC_CheckPredicate, 37, // Predicate_asextloadi32
/*18108*/       OPC_MoveParent,
/*18109*/       OPC_RecordChild1, // #2 = $R1src
/*18110*/       OPC_CheckType, MVT::i64,
/*18112*/       OPC_CheckComplexPat, /*CP*/0, /*#*/1, // selectBDXAddr20Only:$XBD2 #3 #4 #5
/*18115*/       OPC_EmitMergeInputChains1_0,
/*18116*/       OPC_MorphNodeTo, TARGET_VAL(SystemZ::MSGF), 0|OPFL_Chain|OPFL_MemRefs,
                    1/*#VTs*/, MVT::i64, 4/*#Ops*/, 2, 3, 4, 5, 
                // Src: (mul:i64 (ld:i64 bdxaddr20only:i64:$XBD2)<<P:Predicate_unindexedload>><<P:Predicate_asextload>><<P:Predicate_asextloadi32>>, GR64:i64:$R1src) - Complexity = 19
                // Dst: (MSGF:i64 GR64:i64:$R1src, bdxaddr20only:i64:$XBD2)
/*18127*/     /*Scope*/ 21, /*->18149*/
/*18128*/       OPC_CheckPredicate, 13, // Predicate_load
/*18130*/       OPC_MoveParent,
/*18131*/       OPC_RecordChild1, // #2 = $R1src
/*18132*/       OPC_CheckType, MVT::i64,
/*18134*/       OPC_CheckComplexPat, /*CP*/0, /*#*/1, // selectBDXAddr20Only:$XBD2 #3 #4 #5
/*18137*/       OPC_EmitMergeInputChains1_0,
/*18138*/       OPC_MorphNodeTo, TARGET_VAL(SystemZ::MSG), 0|OPFL_Chain|OPFL_MemRefs,
                    1/*#VTs*/, MVT::i64, 4/*#Ops*/, 2, 3, 4, 5, 
                // Src: (mul:i64 (ld:i64 bdxaddr20only:i64:$XBD2)<<P:Predicate_unindexedload>><<P:Predicate_load>>, GR64:i64:$R1src) - Complexity = 19
                // Dst: (MSG:i64 GR64:i64:$R1src, bdxaddr20only:i64:$XBD2)
/*18149*/     0, /*End of Scope*/
/*18150*/   /*Scope*/ 113, /*->18264*/
/*18151*/     OPC_RecordChild0, // #0 = $R1src
/*18152*/     OPC_Scope, 68, /*->18222*/ // 3 children in Scope
/*18154*/       OPC_RecordChild1, // #1 = $I2
/*18155*/       OPC_MoveChild, 1,
/*18157*/       OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*18160*/       OPC_Scope, 19, /*->18181*/ // 3 children in Scope
/*18162*/         OPC_CheckPredicate, 31, // Predicate_imm32sx16
/*18164*/         OPC_MoveParent,
/*18165*/         OPC_CheckType, MVT::i32,
/*18167*/         OPC_EmitConvertToTarget, 1,
/*18169*/         OPC_EmitNodeXForm, 2, 2, // SIMM16
/*18172*/         OPC_MorphNodeTo, TARGET_VAL(SystemZ::MHI), 0,
                      1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 3, 
                  // Src: (mul:i32 GR32:i32:$R1src, (imm:i32)<<P:Predicate_imm32sx16>><<X:SIMM16>>:$I2) - Complexity = 7
                  // Dst: (MHI:i32 GR32:i32:$R1src, (SIMM16:i32 (imm:i32):$I2))
/*18181*/       /*Scope*/ 19, /*->18201*/
/*18182*/         OPC_CheckPredicate, 32, // Predicate_imm64sx16
/*18184*/         OPC_MoveParent,
/*18185*/         OPC_CheckType, MVT::i64,
/*18187*/         OPC_EmitConvertToTarget, 1,
/*18189*/         OPC_EmitNodeXForm, 2, 2, // SIMM16
/*18192*/         OPC_MorphNodeTo, TARGET_VAL(SystemZ::MGHI), 0,
                      1/*#VTs*/, MVT::i64, 2/*#Ops*/, 0, 3, 
                  // Src: (mul:i64 GR64:i64:$R1src, (imm:i64)<<P:Predicate_imm64sx16>><<X:SIMM16>>:$I2) - Complexity = 7
                  // Dst: (MGHI:i64 GR64:i64:$R1src, (SIMM16:i64 (imm:i64):$I2))
/*18201*/       /*Scope*/ 19, /*->18221*/
/*18202*/         OPC_CheckPredicate, 63, // Predicate_imm64sx32
/*18204*/         OPC_MoveParent,
/*18205*/         OPC_CheckType, MVT::i64,
/*18207*/         OPC_EmitConvertToTarget, 1,
/*18209*/         OPC_EmitNodeXForm, 11, 2, // SIMM32
/*18212*/         OPC_MorphNodeTo, TARGET_VAL(SystemZ::MSGFI), 0,
                      1/*#VTs*/, MVT::i64, 2/*#Ops*/, 0, 3, 
                  // Src: (mul:i64 GR64:i64:$R1src, (imm:i64)<<P:Predicate_imm64sx32>><<X:SIMM32>>:$I2) - Complexity = 7
                  // Dst: (MSGFI:i64 GR64:i64:$R1src, (SIMM32:i64 (imm:i64):$I2))
/*18221*/       0, /*End of Scope*/
/*18222*/     /*Scope*/ 16, /*->18239*/
/*18223*/       OPC_MoveChild, 1,
/*18225*/       OPC_CheckOpcode, TARGET_VAL(ISD::SIGN_EXTEND),
/*18228*/       OPC_RecordChild0, // #1 = $src2
/*18229*/       OPC_MoveParent,
/*18230*/       OPC_MorphNodeTo, TARGET_VAL(SystemZ::MSGFR), 0,
                    1/*#VTs*/, MVT::i64, 2/*#Ops*/, 0, 1, 
                // Src: (mul:i64 GR64:i64:$src1, (sext:i64 GR32:i32:$src2)) - Complexity = 6
                // Dst: (MSGFR:i64 GR64:i64:$src1, GR32:i32:$src2)
/*18239*/     /*Scope*/ 23, /*->18263*/
/*18240*/       OPC_RecordChild1, // #1 = $I2
/*18241*/       OPC_MoveChild, 1,
/*18243*/       OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*18246*/       OPC_MoveParent,
/*18247*/       OPC_CheckType, MVT::i32,
/*18249*/       OPC_EmitConvertToTarget, 1,
/*18251*/       OPC_EmitNodeXForm, 11, 2, // SIMM32
/*18254*/       OPC_MorphNodeTo, TARGET_VAL(SystemZ::MSFI), 0,
                    1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 3, 
                // Src: (mul:i32 GR32:i32:$R1src, (imm:i32)<<X:SIMM32>>:$I2) - Complexity = 6
                // Dst: (MSFI:i32 GR32:i32:$R1src, (SIMM32:i32 (imm:i32):$I2))
/*18263*/     0, /*End of Scope*/
/*18264*/   /*Scope*/ 17, /*->18282*/
/*18265*/     OPC_MoveChild, 0,
/*18267*/     OPC_CheckOpcode, TARGET_VAL(ISD::SIGN_EXTEND),
/*18270*/     OPC_RecordChild0, // #0 = $src2
/*18271*/     OPC_MoveParent,
/*18272*/     OPC_RecordChild1, // #1 = $src1
/*18273*/     OPC_MorphNodeTo, TARGET_VAL(SystemZ::MSGFR), 0,
                  1/*#VTs*/, MVT::i64, 2/*#Ops*/, 1, 0, 
              // Src: (mul:i64 (sext:i64 GR32:i32:$src2), GR64:i64:$src1) - Complexity = 6
              // Dst: (MSGFR:i64 GR64:i64:$src1, GR32:i32:$src2)
/*18282*/   /*Scope*/ 34, /*->18317*/
/*18283*/     OPC_RecordChild0, // #0 = $src1
/*18284*/     OPC_MoveChild, 1,
/*18286*/     OPC_CheckOpcode, TARGET_VAL(ISD::SIGN_EXTEND_INREG),
/*18289*/     OPC_RecordChild0, // #1 = $src2
/*18290*/     OPC_MoveChild, 1,
/*18292*/     OPC_CheckValueType, MVT::i32,
/*18294*/     OPC_MoveParent,
/*18295*/     OPC_MoveParent,
/*18296*/     OPC_EmitInteger, MVT::i32, SystemZ::subreg_l32,
/*18299*/     OPC_EmitNode, TARGET_VAL(TargetOpcode::EXTRACT_SUBREG), 0,
                  1/*#VTs*/, MVT::i32, 2/*#Ops*/, 1, 2,  // Results = #3
/*18308*/     OPC_MorphNodeTo, TARGET_VAL(SystemZ::MSGFR), 0,
                  1/*#VTs*/, MVT::i64, 2/*#Ops*/, 0, 3, 
              // Src: (mul:i64 GR64:i64:$src1, (sext_inreg:i64 GR64:i64:$src2, i32:Other)) - Complexity = 6
              // Dst: (MSGFR:i64 GR64:i64:$src1, (EXTRACT_SUBREG:i32 GR64:i64:$src2, subreg_l32:i32))
/*18317*/   /*Scope*/ 34, /*->18352*/
/*18318*/     OPC_MoveChild, 0,
/*18320*/     OPC_CheckOpcode, TARGET_VAL(ISD::SIGN_EXTEND_INREG),
/*18323*/     OPC_RecordChild0, // #0 = $src2
/*18324*/     OPC_MoveChild, 1,
/*18326*/     OPC_CheckValueType, MVT::i32,
/*18328*/     OPC_MoveParent,
/*18329*/     OPC_MoveParent,
/*18330*/     OPC_RecordChild1, // #1 = $src1
/*18331*/     OPC_EmitInteger, MVT::i32, SystemZ::subreg_l32,
/*18334*/     OPC_EmitNode, TARGET_VAL(TargetOpcode::EXTRACT_SUBREG), 0,
                  1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 2,  // Results = #3
/*18343*/     OPC_MorphNodeTo, TARGET_VAL(SystemZ::MSGFR), 0,
                  1/*#VTs*/, MVT::i64, 2/*#Ops*/, 1, 3, 
              // Src: (mul:i64 (sext_inreg:i64 GR64:i64:$src2, i32:Other), GR64:i64:$src1) - Complexity = 6
              // Dst: (MSGFR:i64 GR64:i64:$src1, (EXTRACT_SUBREG:i32 GR64:i64:$src2, subreg_l32:i32))
/*18352*/   /*Scope*/ 26, /*->18379*/
/*18353*/     OPC_RecordChild0, // #0 = $R1src
/*18354*/     OPC_RecordChild1, // #1 = $R2
/*18355*/     OPC_SwitchType /*2 cases */, 9,  MVT::i32,// ->18367
/*18358*/       OPC_MorphNodeTo, TARGET_VAL(SystemZ::MSR), 0,
                    1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1, 
                // Src: (mul:i32 GR32:i32:$R1src, GR32:i32:$R2) - Complexity = 3
                // Dst: (MSR:i32 GR32:i32:$R1src, GR32:i32:$R2)
/*18367*/     /*SwitchType*/ 9,  MVT::i64,// ->18378
/*18369*/       OPC_MorphNodeTo, TARGET_VAL(SystemZ::MSGR), 0,
                    1/*#VTs*/, MVT::i64, 2/*#Ops*/, 0, 1, 
                // Src: (mul:i64 GR64:i64:$R1src, GR64:i64:$R2) - Complexity = 3
                // Dst: (MSGR:i64 GR64:i64:$R1src, GR64:i64:$R2)
/*18378*/     0, // EndSwitchType
/*18379*/   0, /*End of Scope*/
/*18380*/ /*SwitchOpcode*/ 46,  TARGET_VAL(SystemZISD::UMUL_LOHI64),// ->18429
/*18383*/   OPC_RecordChild0, // #0 = $R1src
/*18384*/   OPC_Scope, 31, /*->18417*/ // 2 children in Scope
/*18386*/     OPC_MoveChild, 1,
/*18388*/     OPC_CheckOpcode, TARGET_VAL(ISD::LOAD),
/*18391*/     OPC_RecordMemRef,
/*18392*/     OPC_RecordNode, // #1 = 'ld' chained node
/*18393*/     OPC_CheckFoldableChainNode,
/*18394*/     OPC_RecordChild1, // #2 = $XBD2
/*18395*/     OPC_CheckChild1Type, MVT::i64,
/*18397*/     OPC_CheckPredicate, 0, // Predicate_unindexedload
/*18399*/     OPC_CheckPredicate, 13, // Predicate_load
/*18401*/     OPC_MoveParent,
/*18402*/     OPC_CheckComplexPat, /*CP*/0, /*#*/2, // selectBDXAddr20Only:$XBD2 #3 #4 #5
/*18405*/     OPC_EmitMergeInputChains1_1,
/*18406*/     OPC_MorphNodeTo, TARGET_VAL(SystemZ::MLG), 0|OPFL_Chain|OPFL_MemRefs,
                  1/*#VTs*/, MVT::Untyped, 4/*#Ops*/, 0, 3, 4, 5, 
              // Src: (z_umul_lohi64:Untyped GR128:Untyped:$R1src, (ld:i64 bdxaddr20only:i64:$XBD2)<<P:Predicate_unindexedload>><<P:Predicate_load>>) - Complexity = 19
              // Dst: (MLG:Untyped GR128:Untyped:$R1src, bdxaddr20only:i64:$XBD2)
/*18417*/   /*Scope*/ 10, /*->18428*/
/*18418*/     OPC_RecordChild1, // #1 = $R2
/*18419*/     OPC_MorphNodeTo, TARGET_VAL(SystemZ::MLGR), 0,
                  1/*#VTs*/, MVT::Untyped, 2/*#Ops*/, 0, 1, 
              // Src: (z_umul_lohi64:Untyped GR128:Untyped:$R1src, GR64:i64:$R2) - Complexity = 3
              // Dst: (MLGR:Untyped GR128:Untyped:$R1src, GR64:i64:$R2)
/*18428*/   0, /*End of Scope*/
/*18429*/ /*SwitchOpcode*/ 46,  TARGET_VAL(SystemZISD::SDIVREM32),// ->18478
/*18432*/   OPC_RecordChild0, // #0 = $R1src
/*18433*/   OPC_Scope, 31, /*->18466*/ // 2 children in Scope
/*18435*/     OPC_MoveChild, 1,
/*18437*/     OPC_CheckOpcode, TARGET_VAL(ISD::LOAD),
/*18440*/     OPC_RecordMemRef,
/*18441*/     OPC_RecordNode, // #1 = 'ld' chained node
/*18442*/     OPC_CheckFoldableChainNode,
/*18443*/     OPC_RecordChild1, // #2 = $XBD2
/*18444*/     OPC_CheckChild1Type, MVT::i64,
/*18446*/     OPC_CheckPredicate, 0, // Predicate_unindexedload
/*18448*/     OPC_CheckPredicate, 13, // Predicate_load
/*18450*/     OPC_MoveParent,
/*18451*/     OPC_CheckComplexPat, /*CP*/0, /*#*/2, // selectBDXAddr20Only:$XBD2 #3 #4 #5
/*18454*/     OPC_EmitMergeInputChains1_1,
/*18455*/     OPC_MorphNodeTo, TARGET_VAL(SystemZ::DSGF), 0|OPFL_Chain|OPFL_MemRefs,
                  1/*#VTs*/, MVT::Untyped, 4/*#Ops*/, 0, 3, 4, 5, 
              // Src: (z_sdivrem32:Untyped GR128:Untyped:$R1src, (ld:i32 bdxaddr20only:i64:$XBD2)<<P:Predicate_unindexedload>><<P:Predicate_load>>) - Complexity = 19
              // Dst: (DSGF:Untyped GR128:Untyped:$R1src, bdxaddr20only:i64:$XBD2)
/*18466*/   /*Scope*/ 10, /*->18477*/
/*18467*/     OPC_RecordChild1, // #1 = $R2
/*18468*/     OPC_MorphNodeTo, TARGET_VAL(SystemZ::DSGFR), 0,
                  1/*#VTs*/, MVT::Untyped, 2/*#Ops*/, 0, 1, 
              // Src: (z_sdivrem32:Untyped GR128:Untyped:$R1src, GR32:i32:$R2) - Complexity = 3
              // Dst: (DSGFR:Untyped GR128:Untyped:$R1src, GR32:i32:$R2)
/*18477*/   0, /*End of Scope*/
/*18478*/ /*SwitchOpcode*/ 46,  TARGET_VAL(SystemZISD::SDIVREM64),// ->18527
/*18481*/   OPC_RecordChild0, // #0 = $R1src
/*18482*/   OPC_Scope, 31, /*->18515*/ // 2 children in Scope
/*18484*/     OPC_MoveChild, 1,
/*18486*/     OPC_CheckOpcode, TARGET_VAL(ISD::LOAD),
/*18489*/     OPC_RecordMemRef,
/*18490*/     OPC_RecordNode, // #1 = 'ld' chained node
/*18491*/     OPC_CheckFoldableChainNode,
/*18492*/     OPC_RecordChild1, // #2 = $XBD2
/*18493*/     OPC_CheckChild1Type, MVT::i64,
/*18495*/     OPC_CheckPredicate, 0, // Predicate_unindexedload
/*18497*/     OPC_CheckPredicate, 13, // Predicate_load
/*18499*/     OPC_MoveParent,
/*18500*/     OPC_CheckComplexPat, /*CP*/0, /*#*/2, // selectBDXAddr20Only:$XBD2 #3 #4 #5
/*18503*/     OPC_EmitMergeInputChains1_1,
/*18504*/     OPC_MorphNodeTo, TARGET_VAL(SystemZ::DSG), 0|OPFL_Chain|OPFL_MemRefs,
                  1/*#VTs*/, MVT::Untyped, 4/*#Ops*/, 0, 3, 4, 5, 
              // Src: (z_sdivrem64:Untyped GR128:Untyped:$R1src, (ld:i64 bdxaddr20only:i64:$XBD2)<<P:Predicate_unindexedload>><<P:Predicate_load>>) - Complexity = 19
              // Dst: (DSG:Untyped GR128:Untyped:$R1src, bdxaddr20only:i64:$XBD2)
/*18515*/   /*Scope*/ 10, /*->18526*/
/*18516*/     OPC_RecordChild1, // #1 = $R2
/*18517*/     OPC_MorphNodeTo, TARGET_VAL(SystemZ::DSGR), 0,
                  1/*#VTs*/, MVT::Untyped, 2/*#Ops*/, 0, 1, 
              // Src: (z_sdivrem64:Untyped GR128:Untyped:$R1src, GR64:i64:$R2) - Complexity = 3
              // Dst: (DSGR:Untyped GR128:Untyped:$R1src, GR64:i64:$R2)
/*18526*/   0, /*End of Scope*/
/*18527*/ /*SwitchOpcode*/ 46,  TARGET_VAL(SystemZISD::UDIVREM32),// ->18576
/*18530*/   OPC_RecordChild0, // #0 = $R1src
/*18531*/   OPC_Scope, 31, /*->18564*/ // 2 children in Scope
/*18533*/     OPC_MoveChild, 1,
/*18535*/     OPC_CheckOpcode, TARGET_VAL(ISD::LOAD),
/*18538*/     OPC_RecordMemRef,
/*18539*/     OPC_RecordNode, // #1 = 'ld' chained node
/*18540*/     OPC_CheckFoldableChainNode,
/*18541*/     OPC_RecordChild1, // #2 = $XBD2
/*18542*/     OPC_CheckChild1Type, MVT::i64,
/*18544*/     OPC_CheckPredicate, 0, // Predicate_unindexedload
/*18546*/     OPC_CheckPredicate, 13, // Predicate_load
/*18548*/     OPC_MoveParent,
/*18549*/     OPC_CheckComplexPat, /*CP*/0, /*#*/2, // selectBDXAddr20Only:$XBD2 #3 #4 #5
/*18552*/     OPC_EmitMergeInputChains1_1,
/*18553*/     OPC_MorphNodeTo, TARGET_VAL(SystemZ::DL), 0|OPFL_Chain|OPFL_MemRefs,
                  1/*#VTs*/, MVT::Untyped, 4/*#Ops*/, 0, 3, 4, 5, 
              // Src: (z_udivrem32:Untyped GR128:Untyped:$R1src, (ld:i32 bdxaddr20only:i64:$XBD2)<<P:Predicate_unindexedload>><<P:Predicate_load>>) - Complexity = 19
              // Dst: (DL:Untyped GR128:Untyped:$R1src, bdxaddr20only:i64:$XBD2)
/*18564*/   /*Scope*/ 10, /*->18575*/
/*18565*/     OPC_RecordChild1, // #1 = $R2
/*18566*/     OPC_MorphNodeTo, TARGET_VAL(SystemZ::DLR), 0,
                  1/*#VTs*/, MVT::Untyped, 2/*#Ops*/, 0, 1, 
              // Src: (z_udivrem32:Untyped GR128:Untyped:$R1src, GR32:i32:$R2) - Complexity = 3
              // Dst: (DLR:Untyped GR128:Untyped:$R1src, GR32:i32:$R2)
/*18575*/   0, /*End of Scope*/
/*18576*/ /*SwitchOpcode*/ 46,  TARGET_VAL(SystemZISD::UDIVREM64),// ->18625
/*18579*/   OPC_RecordChild0, // #0 = $R1src
/*18580*/   OPC_Scope, 31, /*->18613*/ // 2 children in Scope
/*18582*/     OPC_MoveChild, 1,
/*18584*/     OPC_CheckOpcode, TARGET_VAL(ISD::LOAD),
/*18587*/     OPC_RecordMemRef,
/*18588*/     OPC_RecordNode, // #1 = 'ld' chained node
/*18589*/     OPC_CheckFoldableChainNode,
/*18590*/     OPC_RecordChild1, // #2 = $XBD2
/*18591*/     OPC_CheckChild1Type, MVT::i64,
/*18593*/     OPC_CheckPredicate, 0, // Predicate_unindexedload
/*18595*/     OPC_CheckPredicate, 13, // Predicate_load
/*18597*/     OPC_MoveParent,
/*18598*/     OPC_CheckComplexPat, /*CP*/0, /*#*/2, // selectBDXAddr20Only:$XBD2 #3 #4 #5
/*18601*/     OPC_EmitMergeInputChains1_1,
/*18602*/     OPC_MorphNodeTo, TARGET_VAL(SystemZ::DLG), 0|OPFL_Chain|OPFL_MemRefs,
                  1/*#VTs*/, MVT::Untyped, 4/*#Ops*/, 0, 3, 4, 5, 
              // Src: (z_udivrem64:Untyped GR128:Untyped:$R1src, (ld:i64 bdxaddr20only:i64:$XBD2)<<P:Predicate_unindexedload>><<P:Predicate_load>>) - Complexity = 19
              // Dst: (DLG:Untyped GR128:Untyped:$R1src, bdxaddr20only:i64:$XBD2)
/*18613*/   /*Scope*/ 10, /*->18624*/
/*18614*/     OPC_RecordChild1, // #1 = $R2
/*18615*/     OPC_MorphNodeTo, TARGET_VAL(SystemZ::DLGR), 0,
                  1/*#VTs*/, MVT::Untyped, 2/*#Ops*/, 0, 1, 
              // Src: (z_udivrem64:Untyped GR128:Untyped:$R1src, GR64:i64:$R2) - Complexity = 3
              // Dst: (DLGR:Untyped GR128:Untyped:$R1src, GR64:i64:$R2)
/*18624*/   0, /*End of Scope*/
/*18625*/ /*SwitchOpcode*/ 39|128,1/*167*/,  TARGET_VAL(SystemZISD::FCMP),// ->18796
/*18629*/   OPC_RecordChild0, // #0 = $R1
/*18630*/   OPC_Scope, 64, /*->18696*/ // 3 children in Scope
/*18632*/     OPC_CheckChild0Type, MVT::f32,
/*18634*/     OPC_Scope, 48, /*->18684*/ // 2 children in Scope
/*18636*/       OPC_MoveChild, 1,
/*18638*/       OPC_SwitchOpcode /*2 cases */, 26,  TARGET_VAL(ISD::LOAD),// ->18668
/*18642*/         OPC_RecordMemRef,
/*18643*/         OPC_RecordNode, // #1 = 'ld' chained node
/*18644*/         OPC_CheckFoldableChainNode,
/*18645*/         OPC_RecordChild1, // #2 = $XBD2
/*18646*/         OPC_CheckChild1Type, MVT::i64,
/*18648*/         OPC_CheckPredicate, 0, // Predicate_unindexedload
/*18650*/         OPC_CheckPredicate, 13, // Predicate_load
/*18652*/         OPC_MoveParent,
/*18653*/         OPC_CheckComplexPat, /*CP*/16, /*#*/2, // selectBDXAddr12Only:$XBD2 #3 #4 #5
/*18656*/         OPC_EmitMergeInputChains1_1,
/*18657*/         OPC_MorphNodeTo, TARGET_VAL(SystemZ::CEB), 0|OPFL_Chain|OPFL_GlueOutput|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i32, 4/*#Ops*/, 0, 3, 4, 5, 
                  // Src: (z_fcmp FP32:f32:$R1, (ld:f32 bdxaddr12only:i64:$XBD2)<<P:Predicate_unindexedload>><<P:Predicate_load>>) - Complexity = 19
                  // Dst: (CEB:i32 FP32:f32:$R1, bdxaddr12only:i64:$XBD2)
/*18668*/       /*SwitchOpcode*/ 12,  TARGET_VAL(ISD::ConstantFP),// ->18683
/*18671*/         OPC_CheckPredicate, 74, // Predicate_fpimm0
/*18673*/         OPC_MoveParent,
/*18674*/         OPC_MorphNodeTo, TARGET_VAL(SystemZ::LTEBRCompare), 0|OPFL_GlueOutput,
                      1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 0, 
                  // Src: (z_fcmp FP32:f32:$reg, (fpimm:f32)<<P:Predicate_fpimm0>>) - Complexity = 7
                  // Dst: (LTEBRCompare:i32 FP32:f32:$reg, FP32:f32:$reg)
/*18683*/       0, // EndSwitchOpcode
/*18684*/     /*Scope*/ 10, /*->18695*/
/*18685*/       OPC_RecordChild1, // #1 = $R2
/*18686*/       OPC_MorphNodeTo, TARGET_VAL(SystemZ::CEBR), 0|OPFL_GlueOutput,
                    1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1, 
                // Src: (z_fcmp FP32:f32:$R1, FP32:f32:$R2) - Complexity = 3
                // Dst: (CEBR:i32 FP32:f32:$R1, FP32:f32:$R2)
/*18695*/     0, /*End of Scope*/
/*18696*/   /*Scope*/ 64, /*->18761*/
/*18697*/     OPC_CheckChild0Type, MVT::f64,
/*18699*/     OPC_Scope, 48, /*->18749*/ // 2 children in Scope
/*18701*/       OPC_MoveChild, 1,
/*18703*/       OPC_SwitchOpcode /*2 cases */, 26,  TARGET_VAL(ISD::LOAD),// ->18733
/*18707*/         OPC_RecordMemRef,
/*18708*/         OPC_RecordNode, // #1 = 'ld' chained node
/*18709*/         OPC_CheckFoldableChainNode,
/*18710*/         OPC_RecordChild1, // #2 = $XBD2
/*18711*/         OPC_CheckChild1Type, MVT::i64,
/*18713*/         OPC_CheckPredicate, 0, // Predicate_unindexedload
/*18715*/         OPC_CheckPredicate, 13, // Predicate_load
/*18717*/         OPC_MoveParent,
/*18718*/         OPC_CheckComplexPat, /*CP*/16, /*#*/2, // selectBDXAddr12Only:$XBD2 #3 #4 #5
/*18721*/         OPC_EmitMergeInputChains1_1,
/*18722*/         OPC_MorphNodeTo, TARGET_VAL(SystemZ::CDB), 0|OPFL_Chain|OPFL_GlueOutput|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i32, 4/*#Ops*/, 0, 3, 4, 5, 
                  // Src: (z_fcmp FP64:f64:$R1, (ld:f64 bdxaddr12only:i64:$XBD2)<<P:Predicate_unindexedload>><<P:Predicate_load>>) - Complexity = 19
                  // Dst: (CDB:i32 FP64:f64:$R1, bdxaddr12only:i64:$XBD2)
/*18733*/       /*SwitchOpcode*/ 12,  TARGET_VAL(ISD::ConstantFP),// ->18748
/*18736*/         OPC_CheckPredicate, 74, // Predicate_fpimm0
/*18738*/         OPC_MoveParent,
/*18739*/         OPC_MorphNodeTo, TARGET_VAL(SystemZ::LTDBRCompare), 0|OPFL_GlueOutput,
                      1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 0, 
                  // Src: (z_fcmp FP64:f64:$reg, (fpimm:f64)<<P:Predicate_fpimm0>>) - Complexity = 7
                  // Dst: (LTDBRCompare:i32 FP64:f64:$reg, FP64:f64:$reg)
/*18748*/       0, // EndSwitchOpcode
/*18749*/     /*Scope*/ 10, /*->18760*/
/*18750*/       OPC_RecordChild1, // #1 = $R2
/*18751*/       OPC_MorphNodeTo, TARGET_VAL(SystemZ::CDBR), 0|OPFL_GlueOutput,
                    1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1, 
                // Src: (z_fcmp FP64:f64:$R1, FP64:f64:$R2) - Complexity = 3
                // Dst: (CDBR:i32 FP64:f64:$R1, FP64:f64:$R2)
/*18760*/     0, /*End of Scope*/
/*18761*/   /*Scope*/ 33, /*->18795*/
/*18762*/     OPC_CheckChild0Type, MVT::f128,
/*18764*/     OPC_Scope, 17, /*->18783*/ // 2 children in Scope
/*18766*/       OPC_MoveChild, 1,
/*18768*/       OPC_CheckOpcode, TARGET_VAL(ISD::ConstantFP),
/*18771*/       OPC_CheckPredicate, 74, // Predicate_fpimm0
/*18773*/       OPC_MoveParent,
/*18774*/       OPC_MorphNodeTo, TARGET_VAL(SystemZ::LTXBRCompare), 0|OPFL_GlueOutput,
                    1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 0, 
                // Src: (z_fcmp FP128:f128:$reg, (fpimm:f128)<<P:Predicate_fpimm0>>) - Complexity = 7
                // Dst: (LTXBRCompare:i32 FP128:f128:$reg, FP128:f128:$reg)
/*18783*/     /*Scope*/ 10, /*->18794*/
/*18784*/       OPC_RecordChild1, // #1 = $R2
/*18785*/       OPC_MorphNodeTo, TARGET_VAL(SystemZ::CXBR), 0|OPFL_GlueOutput,
                    1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1, 
                // Src: (z_fcmp FP128:f128:$R1, FP128:f128:$R2) - Complexity = 3
                // Dst: (CXBR:i32 FP128:f128:$R1, FP128:f128:$R2)
/*18794*/     0, /*End of Scope*/
/*18795*/   0, /*End of Scope*/
/*18796*/ /*SwitchOpcode*/ 87,  TARGET_VAL(SystemZISD::ATOMIC_LOADW_AND),// ->18886
/*18799*/   OPC_RecordMemRef,
/*18800*/   OPC_RecordNode,   // #0 = 'z_atomic_loadw_and' chained node
/*18801*/   OPC_RecordChild1, // #1 = $ptr
/*18802*/   OPC_CheckChild1Type, MVT::i64,
/*18804*/   OPC_RecordChild2, // #2 = $src2
/*18805*/   OPC_Scope, 45, /*->18852*/ // 2 children in Scope
/*18807*/     OPC_MoveChild, 2,
/*18809*/     OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*18812*/     OPC_CheckPredicate, 67, // Predicate_imm32lh16c
/*18814*/     OPC_MoveParent,
/*18815*/     OPC_RecordChild3, // #3 = $bitshift
/*18816*/     OPC_RecordChild4, // #4 = $negbitshift
/*18817*/     OPC_RecordChild5, // #5 = $bitsize
/*18818*/     OPC_MoveChild, 5,
/*18820*/     OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*18823*/     OPC_MoveParent,
/*18824*/     OPC_CheckComplexPat, /*CP*/4, /*#*/1, // selectBDAddr20Only:$ptr #6 #7
/*18827*/     OPC_EmitMergeInputChains1_0,
/*18828*/     OPC_EmitConvertToTarget, 2,
/*18830*/     OPC_EmitNodeXForm, 7, 8, // LH16
/*18833*/     OPC_EmitConvertToTarget, 5,
/*18835*/     OPC_EmitNodeXForm, 5, 10, // UIMM32
/*18838*/     OPC_MorphNodeTo, TARGET_VAL(SystemZ::ATOMIC_LOADW_NILH), 0|OPFL_Chain|OPFL_MemRefs,
                  2/*#VTs*/, MVT::i32, MVT::i32, 6/*#Ops*/, 6, 7, 9, 3, 4, 11, 
              // Src: (z_atomic_loadw_and:i32 bdaddr20only:i64:$ptr, (imm:i32)<<P:Predicate_imm32lh16c>><<X:LH16>>:$src2, ADDR32:i32:$bitshift, ADDR32:i32:$negbitshift, (imm:i32)<<X:UIMM32>>:$bitsize) - Complexity = 19
              // Dst: (ATOMIC_LOADW_NILH:i32:i32 bdaddr20only:i64:$ptr, (LH16:i32 (imm:i32):$src2), ADDR32:i32:$bitshift, ADDR32:i32:$negbitshift, (UIMM32:i32 (imm:i32):$bitsize))
/*18852*/   /*Scope*/ 32, /*->18885*/
/*18853*/     OPC_RecordChild3, // #3 = $bitshift
/*18854*/     OPC_RecordChild4, // #4 = $negbitshift
/*18855*/     OPC_RecordChild5, // #5 = $bitsize
/*18856*/     OPC_MoveChild, 5,
/*18858*/     OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*18861*/     OPC_MoveParent,
/*18862*/     OPC_CheckComplexPat, /*CP*/4, /*#*/1, // selectBDAddr20Only:$ptr #6 #7
/*18865*/     OPC_EmitMergeInputChains1_0,
/*18866*/     OPC_EmitConvertToTarget, 5,
/*18868*/     OPC_EmitNodeXForm, 5, 8, // UIMM32
/*18871*/     OPC_MorphNodeTo, TARGET_VAL(SystemZ::ATOMIC_LOADW_NR), 0|OPFL_Chain|OPFL_MemRefs,
                  2/*#VTs*/, MVT::i32, MVT::i32, 6/*#Ops*/, 6, 7, 2, 3, 4, 9, 
              // Src: (z_atomic_loadw_and:i32 bdaddr20only:i64:$ptr, GR32:i32:$src2, ADDR32:i32:$bitshift, ADDR32:i32:$negbitshift, (imm:i32)<<X:UIMM32>>:$bitsize) - Complexity = 15
              // Dst: (ATOMIC_LOADW_NR:i32:i32 bdaddr20only:i64:$ptr, GR32:i32:$src2, ADDR32:i32:$bitshift, ADDR32:i32:$negbitshift, (UIMM32:i32 (imm:i32):$bitsize))
/*18885*/   0, /*End of Scope*/
/*18886*/ /*SwitchOpcode*/ 87,  TARGET_VAL(SystemZISD::ATOMIC_LOADW_OR),// ->18976
/*18889*/   OPC_RecordMemRef,
/*18890*/   OPC_RecordNode,   // #0 = 'z_atomic_loadw_or' chained node
/*18891*/   OPC_RecordChild1, // #1 = $ptr
/*18892*/   OPC_CheckChild1Type, MVT::i64,
/*18894*/   OPC_RecordChild2, // #2 = $src2
/*18895*/   OPC_Scope, 45, /*->18942*/ // 2 children in Scope
/*18897*/     OPC_MoveChild, 2,
/*18899*/     OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*18902*/     OPC_CheckPredicate, 46, // Predicate_imm32lh16
/*18904*/     OPC_MoveParent,
/*18905*/     OPC_RecordChild3, // #3 = $bitshift
/*18906*/     OPC_RecordChild4, // #4 = $negbitshift
/*18907*/     OPC_RecordChild5, // #5 = $bitsize
/*18908*/     OPC_MoveChild, 5,
/*18910*/     OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*18913*/     OPC_MoveParent,
/*18914*/     OPC_CheckComplexPat, /*CP*/4, /*#*/1, // selectBDAddr20Only:$ptr #6 #7
/*18917*/     OPC_EmitMergeInputChains1_0,
/*18918*/     OPC_EmitConvertToTarget, 2,
/*18920*/     OPC_EmitNodeXForm, 7, 8, // LH16
/*18923*/     OPC_EmitConvertToTarget, 5,
/*18925*/     OPC_EmitNodeXForm, 5, 10, // UIMM32
/*18928*/     OPC_MorphNodeTo, TARGET_VAL(SystemZ::ATOMIC_LOADW_OILH), 0|OPFL_Chain|OPFL_MemRefs,
                  2/*#VTs*/, MVT::i32, MVT::i32, 6/*#Ops*/, 6, 7, 9, 3, 4, 11, 
              // Src: (z_atomic_loadw_or:i32 bdaddr20only:i64:$ptr, (imm:i32)<<P:Predicate_imm32lh16>><<X:LH16>>:$src2, ADDR32:i32:$bitshift, ADDR32:i32:$negbitshift, (imm:i32)<<X:UIMM32>>:$bitsize) - Complexity = 19
              // Dst: (ATOMIC_LOADW_OILH:i32:i32 bdaddr20only:i64:$ptr, (LH16:i32 (imm:i32):$src2), ADDR32:i32:$bitshift, ADDR32:i32:$negbitshift, (UIMM32:i32 (imm:i32):$bitsize))
/*18942*/   /*Scope*/ 32, /*->18975*/
/*18943*/     OPC_RecordChild3, // #3 = $bitshift
/*18944*/     OPC_RecordChild4, // #4 = $negbitshift
/*18945*/     OPC_RecordChild5, // #5 = $bitsize
/*18946*/     OPC_MoveChild, 5,
/*18948*/     OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*18951*/     OPC_MoveParent,
/*18952*/     OPC_CheckComplexPat, /*CP*/4, /*#*/1, // selectBDAddr20Only:$ptr #6 #7
/*18955*/     OPC_EmitMergeInputChains1_0,
/*18956*/     OPC_EmitConvertToTarget, 5,
/*18958*/     OPC_EmitNodeXForm, 5, 8, // UIMM32
/*18961*/     OPC_MorphNodeTo, TARGET_VAL(SystemZ::ATOMIC_LOADW_OR), 0|OPFL_Chain|OPFL_MemRefs,
                  2/*#VTs*/, MVT::i32, MVT::i32, 6/*#Ops*/, 6, 7, 2, 3, 4, 9, 
              // Src: (z_atomic_loadw_or:i32 bdaddr20only:i64:$ptr, GR32:i32:$src2, ADDR32:i32:$bitshift, ADDR32:i32:$negbitshift, (imm:i32)<<X:UIMM32>>:$bitsize) - Complexity = 15
              // Dst: (ATOMIC_LOADW_OR:i32:i32 bdaddr20only:i64:$ptr, GR32:i32:$src2, ADDR32:i32:$bitshift, ADDR32:i32:$negbitshift, (UIMM32:i32 (imm:i32):$bitsize))
/*18975*/   0, /*End of Scope*/
/*18976*/ /*SwitchOpcode*/ 87,  TARGET_VAL(SystemZISD::ATOMIC_LOADW_NAND),// ->19066
/*18979*/   OPC_RecordMemRef,
/*18980*/   OPC_RecordNode,   // #0 = 'z_atomic_loadw_nand' chained node
/*18981*/   OPC_RecordChild1, // #1 = $ptr
/*18982*/   OPC_CheckChild1Type, MVT::i64,
/*18984*/   OPC_RecordChild2, // #2 = $src2
/*18985*/   OPC_Scope, 45, /*->19032*/ // 2 children in Scope
/*18987*/     OPC_MoveChild, 2,
/*18989*/     OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*18992*/     OPC_CheckPredicate, 67, // Predicate_imm32lh16c
/*18994*/     OPC_MoveParent,
/*18995*/     OPC_RecordChild3, // #3 = $bitshift
/*18996*/     OPC_RecordChild4, // #4 = $negbitshift
/*18997*/     OPC_RecordChild5, // #5 = $bitsize
/*18998*/     OPC_MoveChild, 5,
/*19000*/     OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*19003*/     OPC_MoveParent,
/*19004*/     OPC_CheckComplexPat, /*CP*/4, /*#*/1, // selectBDAddr20Only:$ptr #6 #7
/*19007*/     OPC_EmitMergeInputChains1_0,
/*19008*/     OPC_EmitConvertToTarget, 2,
/*19010*/     OPC_EmitNodeXForm, 7, 8, // LH16
/*19013*/     OPC_EmitConvertToTarget, 5,
/*19015*/     OPC_EmitNodeXForm, 5, 10, // UIMM32
/*19018*/     OPC_MorphNodeTo, TARGET_VAL(SystemZ::ATOMIC_LOADW_NILHi), 0|OPFL_Chain|OPFL_MemRefs,
                  2/*#VTs*/, MVT::i32, MVT::i32, 6/*#Ops*/, 6, 7, 9, 3, 4, 11, 
              // Src: (z_atomic_loadw_nand:i32 bdaddr20only:i64:$ptr, (imm:i32)<<P:Predicate_imm32lh16c>><<X:LH16>>:$src2, ADDR32:i32:$bitshift, ADDR32:i32:$negbitshift, (imm:i32)<<X:UIMM32>>:$bitsize) - Complexity = 19
              // Dst: (ATOMIC_LOADW_NILHi:i32:i32 bdaddr20only:i64:$ptr, (LH16:i32 (imm:i32):$src2), ADDR32:i32:$bitshift, ADDR32:i32:$negbitshift, (UIMM32:i32 (imm:i32):$bitsize))
/*19032*/   /*Scope*/ 32, /*->19065*/
/*19033*/     OPC_RecordChild3, // #3 = $bitshift
/*19034*/     OPC_RecordChild4, // #4 = $negbitshift
/*19035*/     OPC_RecordChild5, // #5 = $bitsize
/*19036*/     OPC_MoveChild, 5,
/*19038*/     OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*19041*/     OPC_MoveParent,
/*19042*/     OPC_CheckComplexPat, /*CP*/4, /*#*/1, // selectBDAddr20Only:$ptr #6 #7
/*19045*/     OPC_EmitMergeInputChains1_0,
/*19046*/     OPC_EmitConvertToTarget, 5,
/*19048*/     OPC_EmitNodeXForm, 5, 8, // UIMM32
/*19051*/     OPC_MorphNodeTo, TARGET_VAL(SystemZ::ATOMIC_LOADW_NRi), 0|OPFL_Chain|OPFL_MemRefs,
                  2/*#VTs*/, MVT::i32, MVT::i32, 6/*#Ops*/, 6, 7, 2, 3, 4, 9, 
              // Src: (z_atomic_loadw_nand:i32 bdaddr20only:i64:$ptr, GR32:i32:$src2, ADDR32:i32:$bitshift, ADDR32:i32:$negbitshift, (imm:i32)<<X:UIMM32>>:$bitsize) - Complexity = 15
              // Dst: (ATOMIC_LOADW_NRi:i32:i32 bdaddr20only:i64:$ptr, GR32:i32:$src2, ADDR32:i32:$bitshift, ADDR32:i32:$negbitshift, (UIMM32:i32 (imm:i32):$bitsize))
/*19065*/   0, /*End of Scope*/
/*19066*/ /*SwitchOpcode*/ 85,  TARGET_VAL(SystemZISD::ATOMIC_LOADW_ADD),// ->19154
/*19069*/   OPC_RecordMemRef,
/*19070*/   OPC_RecordNode,   // #0 = 'z_atomic_loadw_add' chained node
/*19071*/   OPC_RecordChild1, // #1 = $ptr
/*19072*/   OPC_CheckChild1Type, MVT::i64,
/*19074*/   OPC_RecordChild2, // #2 = $src2
/*19075*/   OPC_Scope, 43, /*->19120*/ // 2 children in Scope
/*19077*/     OPC_MoveChild, 2,
/*19079*/     OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*19082*/     OPC_MoveParent,
/*19083*/     OPC_RecordChild3, // #3 = $bitshift
/*19084*/     OPC_RecordChild4, // #4 = $negbitshift
/*19085*/     OPC_RecordChild5, // #5 = $bitsize
/*19086*/     OPC_MoveChild, 5,
/*19088*/     OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*19091*/     OPC_MoveParent,
/*19092*/     OPC_CheckComplexPat, /*CP*/4, /*#*/1, // selectBDAddr20Only:$ptr #6 #7
/*19095*/     OPC_EmitMergeInputChains1_0,
/*19096*/     OPC_EmitConvertToTarget, 2,
/*19098*/     OPC_EmitNodeXForm, 11, 8, // SIMM32
/*19101*/     OPC_EmitConvertToTarget, 5,
/*19103*/     OPC_EmitNodeXForm, 5, 10, // UIMM32
/*19106*/     OPC_MorphNodeTo, TARGET_VAL(SystemZ::ATOMIC_LOADW_AFI), 0|OPFL_Chain|OPFL_MemRefs,
                  2/*#VTs*/, MVT::i32, MVT::i32, 6/*#Ops*/, 6, 7, 9, 3, 4, 11, 
              // Src: (z_atomic_loadw_add:i32 bdaddr20only:i64:$ptr, (imm:i32)<<X:SIMM32>>:$src2, ADDR32:i32:$bitshift, ADDR32:i32:$negbitshift, (imm:i32)<<X:UIMM32>>:$bitsize) - Complexity = 18
              // Dst: (ATOMIC_LOADW_AFI:i32:i32 bdaddr20only:i64:$ptr, (SIMM32:i32 (imm:i32):$src2), ADDR32:i32:$bitshift, ADDR32:i32:$negbitshift, (UIMM32:i32 (imm:i32):$bitsize))
/*19120*/   /*Scope*/ 32, /*->19153*/
/*19121*/     OPC_RecordChild3, // #3 = $bitshift
/*19122*/     OPC_RecordChild4, // #4 = $negbitshift
/*19123*/     OPC_RecordChild5, // #5 = $bitsize
/*19124*/     OPC_MoveChild, 5,
/*19126*/     OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*19129*/     OPC_MoveParent,
/*19130*/     OPC_CheckComplexPat, /*CP*/4, /*#*/1, // selectBDAddr20Only:$ptr #6 #7
/*19133*/     OPC_EmitMergeInputChains1_0,
/*19134*/     OPC_EmitConvertToTarget, 5,
/*19136*/     OPC_EmitNodeXForm, 5, 8, // UIMM32
/*19139*/     OPC_MorphNodeTo, TARGET_VAL(SystemZ::ATOMIC_LOADW_AR), 0|OPFL_Chain|OPFL_MemRefs,
                  2/*#VTs*/, MVT::i32, MVT::i32, 6/*#Ops*/, 6, 7, 2, 3, 4, 9, 
              // Src: (z_atomic_loadw_add:i32 bdaddr20only:i64:$ptr, GR32:i32:$src2, ADDR32:i32:$bitshift, ADDR32:i32:$negbitshift, (imm:i32)<<X:UIMM32>>:$bitsize) - Complexity = 15
              // Dst: (ATOMIC_LOADW_AR:i32:i32 bdaddr20only:i64:$ptr, GR32:i32:$src2, ADDR32:i32:$bitshift, ADDR32:i32:$negbitshift, (UIMM32:i32 (imm:i32):$bitsize))
/*19153*/   0, /*End of Scope*/
/*19154*/ /*SwitchOpcode*/ 85,  TARGET_VAL(SystemZISD::ATOMIC_LOADW_XOR),// ->19242
/*19157*/   OPC_RecordMemRef,
/*19158*/   OPC_RecordNode,   // #0 = 'z_atomic_loadw_xor' chained node
/*19159*/   OPC_RecordChild1, // #1 = $ptr
/*19160*/   OPC_CheckChild1Type, MVT::i64,
/*19162*/   OPC_RecordChild2, // #2 = $src2
/*19163*/   OPC_Scope, 43, /*->19208*/ // 2 children in Scope
/*19165*/     OPC_MoveChild, 2,
/*19167*/     OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*19170*/     OPC_MoveParent,
/*19171*/     OPC_RecordChild3, // #3 = $bitshift
/*19172*/     OPC_RecordChild4, // #4 = $negbitshift
/*19173*/     OPC_RecordChild5, // #5 = $bitsize
/*19174*/     OPC_MoveChild, 5,
/*19176*/     OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*19179*/     OPC_MoveParent,
/*19180*/     OPC_CheckComplexPat, /*CP*/4, /*#*/1, // selectBDAddr20Only:$ptr #6 #7
/*19183*/     OPC_EmitMergeInputChains1_0,
/*19184*/     OPC_EmitConvertToTarget, 2,
/*19186*/     OPC_EmitNodeXForm, 5, 8, // UIMM32
/*19189*/     OPC_EmitConvertToTarget, 5,
/*19191*/     OPC_EmitNodeXForm, 5, 10, // UIMM32
/*19194*/     OPC_MorphNodeTo, TARGET_VAL(SystemZ::ATOMIC_LOADW_XILF), 0|OPFL_Chain|OPFL_MemRefs,
                  2/*#VTs*/, MVT::i32, MVT::i32, 6/*#Ops*/, 6, 7, 9, 3, 4, 11, 
              // Src: (z_atomic_loadw_xor:i32 bdaddr20only:i64:$ptr, (imm:i32)<<X:UIMM32>>:$src2, ADDR32:i32:$bitshift, ADDR32:i32:$negbitshift, (imm:i32)<<X:UIMM32>>:$bitsize) - Complexity = 18
              // Dst: (ATOMIC_LOADW_XILF:i32:i32 bdaddr20only:i64:$ptr, (UIMM32:i32 (imm:i32):$src2), ADDR32:i32:$bitshift, ADDR32:i32:$negbitshift, (UIMM32:i32 (imm:i32):$bitsize))
/*19208*/   /*Scope*/ 32, /*->19241*/
/*19209*/     OPC_RecordChild3, // #3 = $bitshift
/*19210*/     OPC_RecordChild4, // #4 = $negbitshift
/*19211*/     OPC_RecordChild5, // #5 = $bitsize
/*19212*/     OPC_MoveChild, 5,
/*19214*/     OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*19217*/     OPC_MoveParent,
/*19218*/     OPC_CheckComplexPat, /*CP*/4, /*#*/1, // selectBDAddr20Only:$ptr #6 #7
/*19221*/     OPC_EmitMergeInputChains1_0,
/*19222*/     OPC_EmitConvertToTarget, 5,
/*19224*/     OPC_EmitNodeXForm, 5, 8, // UIMM32
/*19227*/     OPC_MorphNodeTo, TARGET_VAL(SystemZ::ATOMIC_LOADW_XR), 0|OPFL_Chain|OPFL_MemRefs,
                  2/*#VTs*/, MVT::i32, MVT::i32, 6/*#Ops*/, 6, 7, 2, 3, 4, 9, 
              // Src: (z_atomic_loadw_xor:i32 bdaddr20only:i64:$ptr, GR32:i32:$src2, ADDR32:i32:$bitshift, ADDR32:i32:$negbitshift, (imm:i32)<<X:UIMM32>>:$bitsize) - Complexity = 15
              // Dst: (ATOMIC_LOADW_XR:i32:i32 bdaddr20only:i64:$ptr, GR32:i32:$src2, ADDR32:i32:$bitshift, ADDR32:i32:$negbitshift, (UIMM32:i32 (imm:i32):$bitsize))
/*19241*/   0, /*End of Scope*/
/*19242*/ /*SwitchOpcode*/ 57|128,6/*825*/,  TARGET_VAL(ISD::LOAD),// ->20071
/*19246*/   OPC_RecordMemRef,
/*19247*/   OPC_RecordNode,   // #0 = 'ld' chained node
/*19248*/   OPC_RecordChild1, // #1 = $I2
/*19249*/   OPC_CheckChild1Type, MVT::i64,
/*19251*/   OPC_CheckPredicate, 0, // Predicate_unindexedload
/*19253*/   OPC_Scope, 34, /*->19289*/ // 8 children in Scope
/*19255*/     OPC_CheckPredicate, 13, // Predicate_load
/*19257*/     OPC_CheckPredicate, 55, // Predicate_aligned_load
/*19259*/     OPC_SwitchType /*2 cases */, 12,  MVT::i32,// ->19274
/*19262*/       OPC_CheckComplexPat, /*CP*/5, /*#*/1, // selectPCRelAddress:$I2 #2
/*19265*/       OPC_EmitMergeInputChains1_0,
/*19266*/       OPC_MorphNodeTo, TARGET_VAL(SystemZ::LRL), 0|OPFL_Chain|OPFL_MemRefs,
                    1/*#VTs*/, MVT::i32, 1/*#Ops*/, 2, 
                // Src: (ld:i32 pcrel32:i64:$I2)<<P:Predicate_unindexedload>><<P:Predicate_load>><<P:Predicate_aligned_load>> - Complexity = 17
                // Dst: (LRL:i32 pcrel32:i64:$I2)
/*19274*/     /*SwitchType*/ 12,  MVT::i64,// ->19288
/*19276*/       OPC_CheckComplexPat, /*CP*/5, /*#*/1, // selectPCRelAddress:$I2 #2
/*19279*/       OPC_EmitMergeInputChains1_0,
/*19280*/       OPC_MorphNodeTo, TARGET_VAL(SystemZ::LGRL), 0|OPFL_Chain|OPFL_MemRefs,
                    1/*#VTs*/, MVT::i64, 1/*#Ops*/, 2, 
                // Src: (ld:i64 pcrel32:i64:$I2)<<P:Predicate_unindexedload>><<P:Predicate_load>><<P:Predicate_aligned_load>> - Complexity = 17
                // Dst: (LGRL:i64 pcrel32:i64:$I2)
/*19288*/     0, // EndSwitchType
/*19289*/   /*Scope*/ 58, /*->19348*/
/*19290*/     OPC_CheckPredicate, 35, // Predicate_asextload
/*19292*/     OPC_Scope, 34, /*->19328*/ // 2 children in Scope
/*19294*/       OPC_CheckPredicate, 36, // Predicate_asextloadi16
/*19296*/       OPC_CheckPredicate, 53, // Predicate_aligned_asextloadi16
/*19298*/       OPC_SwitchType /*2 cases */, 12,  MVT::i32,// ->19313
/*19301*/         OPC_CheckComplexPat, /*CP*/5, /*#*/1, // selectPCRelAddress:$I2 #2
/*19304*/         OPC_EmitMergeInputChains1_0,
/*19305*/         OPC_MorphNodeTo, TARGET_VAL(SystemZ::LHRL), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i32, 1/*#Ops*/, 2, 
                  // Src: (ld:i32 pcrel32:i64:$I2)<<P:Predicate_unindexedload>><<P:Predicate_asextload>><<P:Predicate_asextloadi16>><<P:Predicate_aligned_asextloadi16>> - Complexity = 17
                  // Dst: (LHRL:i32 pcrel32:i64:$I2)
/*19313*/       /*SwitchType*/ 12,  MVT::i64,// ->19327
/*19315*/         OPC_CheckComplexPat, /*CP*/5, /*#*/1, // selectPCRelAddress:$I2 #2
/*19318*/         OPC_EmitMergeInputChains1_0,
/*19319*/         OPC_MorphNodeTo, TARGET_VAL(SystemZ::LGHRL), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i64, 1/*#Ops*/, 2, 
                  // Src: (ld:i64 pcrel32:i64:$I2)<<P:Predicate_unindexedload>><<P:Predicate_asextload>><<P:Predicate_asextloadi16>><<P:Predicate_aligned_asextloadi16>> - Complexity = 17
                  // Dst: (LGHRL:i64 pcrel32:i64:$I2)
/*19327*/       0, // EndSwitchType
/*19328*/     /*Scope*/ 18, /*->19347*/
/*19329*/       OPC_CheckPredicate, 37, // Predicate_asextloadi32
/*19331*/       OPC_CheckPredicate, 56, // Predicate_aligned_asextloadi32
/*19333*/       OPC_CheckType, MVT::i64,
/*19335*/       OPC_CheckComplexPat, /*CP*/5, /*#*/1, // selectPCRelAddress:$I2 #2
/*19338*/       OPC_EmitMergeInputChains1_0,
/*19339*/       OPC_MorphNodeTo, TARGET_VAL(SystemZ::LGFRL), 0|OPFL_Chain|OPFL_MemRefs,
                    1/*#VTs*/, MVT::i64, 1/*#Ops*/, 2, 
                // Src: (ld:i64 pcrel32:i64:$I2)<<P:Predicate_unindexedload>><<P:Predicate_asextload>><<P:Predicate_asextloadi32>><<P:Predicate_aligned_asextloadi32>> - Complexity = 17
                // Dst: (LGFRL:i64 pcrel32:i64:$I2)
/*19347*/     0, /*End of Scope*/
/*19348*/   /*Scope*/ 58, /*->19407*/
/*19349*/     OPC_CheckPredicate, 38, // Predicate_azextload
/*19351*/     OPC_Scope, 34, /*->19387*/ // 2 children in Scope
/*19353*/       OPC_CheckPredicate, 57, // Predicate_azextloadi16
/*19355*/       OPC_CheckPredicate, 58, // Predicate_aligned_azextloadi16
/*19357*/       OPC_SwitchType /*2 cases */, 12,  MVT::i32,// ->19372
/*19360*/         OPC_CheckComplexPat, /*CP*/5, /*#*/1, // selectPCRelAddress:$I2 #2
/*19363*/         OPC_EmitMergeInputChains1_0,
/*19364*/         OPC_MorphNodeTo, TARGET_VAL(SystemZ::LLHRL), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i32, 1/*#Ops*/, 2, 
                  // Src: (ld:i32 pcrel32:i64:$I2)<<P:Predicate_unindexedload>><<P:Predicate_azextload>><<P:Predicate_azextloadi16>><<P:Predicate_aligned_azextloadi16>> - Complexity = 17
                  // Dst: (LLHRL:i32 pcrel32:i64:$I2)
/*19372*/       /*SwitchType*/ 12,  MVT::i64,// ->19386
/*19374*/         OPC_CheckComplexPat, /*CP*/5, /*#*/1, // selectPCRelAddress:$I2 #2
/*19377*/         OPC_EmitMergeInputChains1_0,
/*19378*/         OPC_MorphNodeTo, TARGET_VAL(SystemZ::LLGHRL), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i64, 1/*#Ops*/, 2, 
                  // Src: (ld:i64 pcrel32:i64:$I2)<<P:Predicate_unindexedload>><<P:Predicate_azextload>><<P:Predicate_azextloadi16>><<P:Predicate_aligned_azextloadi16>> - Complexity = 17
                  // Dst: (LLGHRL:i64 pcrel32:i64:$I2)
/*19386*/       0, // EndSwitchType
/*19387*/     /*Scope*/ 18, /*->19406*/
/*19388*/       OPC_CheckPredicate, 39, // Predicate_azextloadi32
/*19390*/       OPC_CheckPredicate, 60, // Predicate_aligned_azextloadi32
/*19392*/       OPC_CheckType, MVT::i64,
/*19394*/       OPC_CheckComplexPat, /*CP*/5, /*#*/1, // selectPCRelAddress:$I2 #2
/*19397*/       OPC_EmitMergeInputChains1_0,
/*19398*/       OPC_MorphNodeTo, TARGET_VAL(SystemZ::LLGFRL), 0|OPFL_Chain|OPFL_MemRefs,
                    1/*#VTs*/, MVT::i64, 1/*#Ops*/, 2, 
                // Src: (ld:i64 pcrel32:i64:$I2)<<P:Predicate_unindexedload>><<P:Predicate_azextload>><<P:Predicate_azextloadi32>><<P:Predicate_aligned_azextloadi32>> - Complexity = 17
                // Dst: (LLGFRL:i64 pcrel32:i64:$I2)
/*19406*/     0, /*End of Scope*/
/*19407*/   /*Scope*/ 7|128,1/*135*/, /*->19544*/
/*19409*/     OPC_CheckPredicate, 13, // Predicate_load
/*19411*/     OPC_SwitchType /*3 cases */, 82,  MVT::i32,// ->19496
/*19414*/       OPC_Scope, 16, /*->19432*/ // 5 children in Scope
/*19416*/         OPC_CheckPatternPredicate, 0, // (Subtarget.hasHighWord())
/*19418*/         OPC_CheckComplexPat, /*CP*/0, /*#*/1, // selectBDXAddr20Only:$XBD2 #2 #3 #4
/*19421*/         OPC_EmitMergeInputChains1_0,
/*19422*/         OPC_MorphNodeTo, TARGET_VAL(SystemZ::LMux), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i32, 3/*#Ops*/, 2, 3, 4, 
                  // Src: (ld:i32 bdxaddr20only:i64:$XBD2)<<P:Predicate_unindexedload>><<P:Predicate_load>> - Complexity = 16
                  // Dst: (LMux:i32 bdxaddr20only:i64:$XBD2)
/*19432*/       /*Scope*/ 14, /*->19447*/
/*19433*/         OPC_CheckComplexPat, /*CP*/7, /*#*/1, // selectBDXAddr12Pair:$XBD2 #2 #3 #4
/*19436*/         OPC_EmitMergeInputChains1_0,
/*19437*/         OPC_MorphNodeTo, TARGET_VAL(SystemZ::L), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i32, 3/*#Ops*/, 2, 3, 4, 
                  // Src: (ld:i32 bdxaddr12pair:i64:$XBD2)<<P:Predicate_unindexedload>><<P:Predicate_load>> - Complexity = 16
                  // Dst: (L:i32 bdxaddr12pair:i64:$XBD2)
/*19447*/       /*Scope*/ 14, /*->19462*/
/*19448*/         OPC_CheckComplexPat, /*CP*/8, /*#*/1, // selectBDXAddr20Pair:$XBD2 #2 #3 #4
/*19451*/         OPC_EmitMergeInputChains1_0,
/*19452*/         OPC_MorphNodeTo, TARGET_VAL(SystemZ::LY), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i32, 3/*#Ops*/, 2, 3, 4, 
                  // Src: (ld:i32 bdxaddr20pair:i64:$XBD2)<<P:Predicate_unindexedload>><<P:Predicate_load>> - Complexity = 16
                  // Dst: (LY:i32 bdxaddr20pair:i64:$XBD2)
/*19462*/       /*Scope*/ 16, /*->19479*/
/*19463*/         OPC_CheckPatternPredicate, 0, // (Subtarget.hasHighWord())
/*19465*/         OPC_CheckComplexPat, /*CP*/0, /*#*/1, // selectBDXAddr20Only:$XBD2 #2 #3 #4
/*19468*/         OPC_EmitMergeInputChains1_0,
/*19469*/         OPC_MorphNodeTo, TARGET_VAL(SystemZ::LFH), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i32, 3/*#Ops*/, 2, 3, 4, 
                  // Src: (ld:i32 bdxaddr20only:i64:$XBD2)<<P:Predicate_unindexedload>><<P:Predicate_load>> - Complexity = 16
                  // Dst: (LFH:i32 bdxaddr20only:i64:$XBD2)
/*19479*/       /*Scope*/ 15, /*->19495*/
/*19480*/         OPC_CheckComplexPat, /*CP*/0, /*#*/1, // selectBDXAddr20Only:$XBD2 #2 #3 #4
/*19483*/         OPC_EmitMergeInputChains1_0,
/*19484*/         OPC_MorphNodeTo, TARGET_VAL(SystemZ::LT), 0|OPFL_Chain|OPFL_MemRefs,
                      2/*#VTs*/, MVT::i32, MVT::i32, 3/*#Ops*/, 2, 3, 4, 
                  // Src: (ld:i32 bdxaddr20only:i64:$XBD2)<<P:Predicate_unindexedload>><<P:Predicate_load>> - Complexity = 16
                  // Dst: (LT:i32:i32 bdxaddr20only:i64:$XBD2)
/*19495*/       0, /*End of Scope*/
/*19496*/     /*SwitchType*/ 29,  MVT::i64,// ->19527
/*19498*/       OPC_CheckComplexPat, /*CP*/0, /*#*/1, // selectBDXAddr20Only:$XBD2 #2 #3 #4
/*19501*/       OPC_EmitMergeInputChains1_0,
/*19502*/       OPC_Scope, 10, /*->19514*/ // 2 children in Scope
/*19504*/         OPC_MorphNodeTo, TARGET_VAL(SystemZ::LG), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i64, 3/*#Ops*/, 2, 3, 4, 
                  // Src: (ld:i64 bdxaddr20only:i64:$XBD2)<<P:Predicate_unindexedload>><<P:Predicate_load>> - Complexity = 16
                  // Dst: (LG:i64 bdxaddr20only:i64:$XBD2)
/*19514*/       /*Scope*/ 11, /*->19526*/
/*19515*/         OPC_MorphNodeTo, TARGET_VAL(SystemZ::LTG), 0|OPFL_Chain|OPFL_MemRefs,
                      2/*#VTs*/, MVT::i64, MVT::i32, 3/*#Ops*/, 2, 3, 4, 
                  // Src: (ld:i64 bdxaddr20only:i64:$XBD2)<<P:Predicate_unindexedload>><<P:Predicate_load>> - Complexity = 16
                  // Dst: (LTG:i64:i32 bdxaddr20only:i64:$XBD2)
/*19526*/       0, /*End of Scope*/
/*19527*/     /*SwitchType*/ 14,  MVT::Untyped,// ->19543
/*19529*/       OPC_CheckComplexPat, /*CP*/9, /*#*/1, // selectBDXAddr20Only128:$src #2 #3 #4
/*19532*/       OPC_EmitMergeInputChains1_0,
/*19533*/       OPC_MorphNodeTo, TARGET_VAL(SystemZ::L128), 0|OPFL_Chain|OPFL_MemRefs,
                    1/*#VTs*/, MVT::Untyped, 3/*#Ops*/, 2, 3, 4, 
                // Src: (ld:Untyped bdxaddr20only128:i64:$src)<<P:Predicate_unindexedload>><<P:Predicate_load>> - Complexity = 16
                // Dst: (L128:Untyped bdxaddr20only128:i64:$src)
/*19543*/     0, // EndSwitchType
/*19544*/   /*Scope*/ 73|128,1/*201*/, /*->19747*/
/*19546*/     OPC_CheckPredicate, 35, // Predicate_asextload
/*19548*/     OPC_SwitchType /*2 cases */, 125,  MVT::i32,// ->19676
/*19551*/       OPC_Scope, 53, /*->19606*/ // 2 children in Scope
/*19553*/         OPC_CheckPredicate, 75, // Predicate_asextloadi8
/*19555*/         OPC_Scope, 16, /*->19573*/ // 3 children in Scope
/*19557*/           OPC_CheckPatternPredicate, 0, // (Subtarget.hasHighWord())
/*19559*/           OPC_CheckComplexPat, /*CP*/0, /*#*/1, // selectBDXAddr20Only:$XBD2 #2 #3 #4
/*19562*/           OPC_EmitMergeInputChains1_0,
/*19563*/           OPC_MorphNodeTo, TARGET_VAL(SystemZ::LBMux), 0|OPFL_Chain|OPFL_MemRefs,
                        1/*#VTs*/, MVT::i32, 3/*#Ops*/, 2, 3, 4, 
                    // Src: (ld:i32 bdxaddr20only:i64:$XBD2)<<P:Predicate_unindexedload>><<P:Predicate_asextload>><<P:Predicate_asextloadi8>> - Complexity = 16
                    // Dst: (LBMux:i32 bdxaddr20only:i64:$XBD2)
/*19573*/         /*Scope*/ 14, /*->19588*/
/*19574*/           OPC_CheckComplexPat, /*CP*/0, /*#*/1, // selectBDXAddr20Only:$XBD2 #2 #3 #4
/*19577*/           OPC_EmitMergeInputChains1_0,
/*19578*/           OPC_MorphNodeTo, TARGET_VAL(SystemZ::LB), 0|OPFL_Chain|OPFL_MemRefs,
                        1/*#VTs*/, MVT::i32, 3/*#Ops*/, 2, 3, 4, 
                    // Src: (ld:i32 bdxaddr20only:i64:$XBD2)<<P:Predicate_unindexedload>><<P:Predicate_asextload>><<P:Predicate_asextloadi8>> - Complexity = 16
                    // Dst: (LB:i32 bdxaddr20only:i64:$XBD2)
/*19588*/         /*Scope*/ 16, /*->19605*/
/*19589*/           OPC_CheckPatternPredicate, 0, // (Subtarget.hasHighWord())
/*19591*/           OPC_CheckComplexPat, /*CP*/0, /*#*/1, // selectBDXAddr20Only:$XBD2 #2 #3 #4
/*19594*/           OPC_EmitMergeInputChains1_0,
/*19595*/           OPC_MorphNodeTo, TARGET_VAL(SystemZ::LBH), 0|OPFL_Chain|OPFL_MemRefs,
                        1/*#VTs*/, MVT::i32, 3/*#Ops*/, 2, 3, 4, 
                    // Src: (ld:i32 bdxaddr20only:i64:$XBD2)<<P:Predicate_unindexedload>><<P:Predicate_asextload>><<P:Predicate_asextloadi8>> - Complexity = 16
                    // Dst: (LBH:i32 bdxaddr20only:i64:$XBD2)
/*19605*/         0, /*End of Scope*/
/*19606*/       /*Scope*/ 68, /*->19675*/
/*19607*/         OPC_CheckPredicate, 36, // Predicate_asextloadi16
/*19609*/         OPC_Scope, 16, /*->19627*/ // 4 children in Scope
/*19611*/           OPC_CheckPatternPredicate, 0, // (Subtarget.hasHighWord())
/*19613*/           OPC_CheckComplexPat, /*CP*/0, /*#*/1, // selectBDXAddr20Only:$XBD2 #2 #3 #4
/*19616*/           OPC_EmitMergeInputChains1_0,
/*19617*/           OPC_MorphNodeTo, TARGET_VAL(SystemZ::LHMux), 0|OPFL_Chain|OPFL_MemRefs,
                        1/*#VTs*/, MVT::i32, 3/*#Ops*/, 2, 3, 4, 
                    // Src: (ld:i32 bdxaddr20only:i64:$XBD2)<<P:Predicate_unindexedload>><<P:Predicate_asextload>><<P:Predicate_asextloadi16>> - Complexity = 16
                    // Dst: (LHMux:i32 bdxaddr20only:i64:$XBD2)
/*19627*/         /*Scope*/ 14, /*->19642*/
/*19628*/           OPC_CheckComplexPat, /*CP*/7, /*#*/1, // selectBDXAddr12Pair:$XBD2 #2 #3 #4
/*19631*/           OPC_EmitMergeInputChains1_0,
/*19632*/           OPC_MorphNodeTo, TARGET_VAL(SystemZ::LH), 0|OPFL_Chain|OPFL_MemRefs,
                        1/*#VTs*/, MVT::i32, 3/*#Ops*/, 2, 3, 4, 
                    // Src: (ld:i32 bdxaddr12pair:i64:$XBD2)<<P:Predicate_unindexedload>><<P:Predicate_asextload>><<P:Predicate_asextloadi16>> - Complexity = 16
                    // Dst: (LH:i32 bdxaddr12pair:i64:$XBD2)
/*19642*/         /*Scope*/ 14, /*->19657*/
/*19643*/           OPC_CheckComplexPat, /*CP*/8, /*#*/1, // selectBDXAddr20Pair:$XBD2 #2 #3 #4
/*19646*/           OPC_EmitMergeInputChains1_0,
/*19647*/           OPC_MorphNodeTo, TARGET_VAL(SystemZ::LHY), 0|OPFL_Chain|OPFL_MemRefs,
                        1/*#VTs*/, MVT::i32, 3/*#Ops*/, 2, 3, 4, 
                    // Src: (ld:i32 bdxaddr20pair:i64:$XBD2)<<P:Predicate_unindexedload>><<P:Predicate_asextload>><<P:Predicate_asextloadi16>> - Complexity = 16
                    // Dst: (LHY:i32 bdxaddr20pair:i64:$XBD2)
/*19657*/         /*Scope*/ 16, /*->19674*/
/*19658*/           OPC_CheckPatternPredicate, 0, // (Subtarget.hasHighWord())
/*19660*/           OPC_CheckComplexPat, /*CP*/0, /*#*/1, // selectBDXAddr20Only:$XBD2 #2 #3 #4
/*19663*/           OPC_EmitMergeInputChains1_0,
/*19664*/           OPC_MorphNodeTo, TARGET_VAL(SystemZ::LHH), 0|OPFL_Chain|OPFL_MemRefs,
                        1/*#VTs*/, MVT::i32, 3/*#Ops*/, 2, 3, 4, 
                    // Src: (ld:i32 bdxaddr20only:i64:$XBD2)<<P:Predicate_unindexedload>><<P:Predicate_asextload>><<P:Predicate_asextloadi16>> - Complexity = 16
                    // Dst: (LHH:i32 bdxaddr20only:i64:$XBD2)
/*19674*/         0, /*End of Scope*/
/*19675*/       0, /*End of Scope*/
/*19676*/     /*SwitchType*/ 68,  MVT::i64,// ->19746
/*19678*/       OPC_Scope, 16, /*->19696*/ // 3 children in Scope
/*19680*/         OPC_CheckPredicate, 75, // Predicate_asextloadi8
/*19682*/         OPC_CheckComplexPat, /*CP*/0, /*#*/1, // selectBDXAddr20Only:$XBD2 #2 #3 #4
/*19685*/         OPC_EmitMergeInputChains1_0,
/*19686*/         OPC_MorphNodeTo, TARGET_VAL(SystemZ::LGB), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i64, 3/*#Ops*/, 2, 3, 4, 
                  // Src: (ld:i64 bdxaddr20only:i64:$XBD2)<<P:Predicate_unindexedload>><<P:Predicate_asextload>><<P:Predicate_asextloadi8>> - Complexity = 16
                  // Dst: (LGB:i64 bdxaddr20only:i64:$XBD2)
/*19696*/       /*Scope*/ 16, /*->19713*/
/*19697*/         OPC_CheckPredicate, 36, // Predicate_asextloadi16
/*19699*/         OPC_CheckComplexPat, /*CP*/0, /*#*/1, // selectBDXAddr20Only:$XBD2 #2 #3 #4
/*19702*/         OPC_EmitMergeInputChains1_0,
/*19703*/         OPC_MorphNodeTo, TARGET_VAL(SystemZ::LGH), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i64, 3/*#Ops*/, 2, 3, 4, 
                  // Src: (ld:i64 bdxaddr20only:i64:$XBD2)<<P:Predicate_unindexedload>><<P:Predicate_asextload>><<P:Predicate_asextloadi16>> - Complexity = 16
                  // Dst: (LGH:i64 bdxaddr20only:i64:$XBD2)
/*19713*/       /*Scope*/ 31, /*->19745*/
/*19714*/         OPC_CheckPredicate, 37, // Predicate_asextloadi32
/*19716*/         OPC_CheckComplexPat, /*CP*/0, /*#*/1, // selectBDXAddr20Only:$XBD2 #2 #3 #4
/*19719*/         OPC_EmitMergeInputChains1_0,
/*19720*/         OPC_Scope, 10, /*->19732*/ // 2 children in Scope
/*19722*/           OPC_MorphNodeTo, TARGET_VAL(SystemZ::LGF), 0|OPFL_Chain|OPFL_MemRefs,
                        1/*#VTs*/, MVT::i64, 3/*#Ops*/, 2, 3, 4, 
                    // Src: (ld:i64 bdxaddr20only:i64:$XBD2)<<P:Predicate_unindexedload>><<P:Predicate_asextload>><<P:Predicate_asextloadi32>> - Complexity = 16
                    // Dst: (LGF:i64 bdxaddr20only:i64:$XBD2)
/*19732*/         /*Scope*/ 11, /*->19744*/
/*19733*/           OPC_MorphNodeTo, TARGET_VAL(SystemZ::LTGF), 0|OPFL_Chain|OPFL_MemRefs,
                        2/*#VTs*/, MVT::i64, MVT::i32, 3/*#Ops*/, 2, 3, 4, 
                    // Src: (ld:i64 bdxaddr20only:i64:$XBD2)<<P:Predicate_unindexedload>><<P:Predicate_asextload>><<P:Predicate_asextloadi32>> - Complexity = 16
                    // Dst: (LTGF:i64:i32 bdxaddr20only:i64:$XBD2)
/*19744*/         0, /*End of Scope*/
/*19745*/       0, /*End of Scope*/
/*19746*/     0, // EndSwitchType
/*19747*/   /*Scope*/ 43|128,1/*171*/, /*->19920*/
/*19749*/     OPC_CheckPredicate, 38, // Predicate_azextload
/*19751*/     OPC_SwitchType /*2 cases */, 110,  MVT::i32,// ->19864
/*19754*/       OPC_Scope, 53, /*->19809*/ // 2 children in Scope
/*19756*/         OPC_CheckPredicate, 42, // Predicate_azextloadi8
/*19758*/         OPC_Scope, 16, /*->19776*/ // 3 children in Scope
/*19760*/           OPC_CheckPatternPredicate, 0, // (Subtarget.hasHighWord())
/*19762*/           OPC_CheckComplexPat, /*CP*/0, /*#*/1, // selectBDXAddr20Only:$XBD2 #2 #3 #4
/*19765*/           OPC_EmitMergeInputChains1_0,
/*19766*/           OPC_MorphNodeTo, TARGET_VAL(SystemZ::LLCMux), 0|OPFL_Chain|OPFL_MemRefs,
                        1/*#VTs*/, MVT::i32, 3/*#Ops*/, 2, 3, 4, 
                    // Src: (ld:i32 bdxaddr20only:i64:$XBD2)<<P:Predicate_unindexedload>><<P:Predicate_azextload>><<P:Predicate_azextloadi8>> - Complexity = 16
                    // Dst: (LLCMux:i32 bdxaddr20only:i64:$XBD2)
/*19776*/         /*Scope*/ 14, /*->19791*/
/*19777*/           OPC_CheckComplexPat, /*CP*/0, /*#*/1, // selectBDXAddr20Only:$XBD2 #2 #3 #4
/*19780*/           OPC_EmitMergeInputChains1_0,
/*19781*/           OPC_MorphNodeTo, TARGET_VAL(SystemZ::LLC), 0|OPFL_Chain|OPFL_MemRefs,
                        1/*#VTs*/, MVT::i32, 3/*#Ops*/, 2, 3, 4, 
                    // Src: (ld:i32 bdxaddr20only:i64:$XBD2)<<P:Predicate_unindexedload>><<P:Predicate_azextload>><<P:Predicate_azextloadi8>> - Complexity = 16
                    // Dst: (LLC:i32 bdxaddr20only:i64:$XBD2)
/*19791*/         /*Scope*/ 16, /*->19808*/
/*19792*/           OPC_CheckPatternPredicate, 0, // (Subtarget.hasHighWord())
/*19794*/           OPC_CheckComplexPat, /*CP*/0, /*#*/1, // selectBDXAddr20Only:$XBD2 #2 #3 #4
/*19797*/           OPC_EmitMergeInputChains1_0,
/*19798*/           OPC_MorphNodeTo, TARGET_VAL(SystemZ::LLCH), 0|OPFL_Chain|OPFL_MemRefs,
                        1/*#VTs*/, MVT::i32, 3/*#Ops*/, 2, 3, 4, 
                    // Src: (ld:i32 bdxaddr20only:i64:$XBD2)<<P:Predicate_unindexedload>><<P:Predicate_azextload>><<P:Predicate_azextloadi8>> - Complexity = 16
                    // Dst: (LLCH:i32 bdxaddr20only:i64:$XBD2)
/*19808*/         0, /*End of Scope*/
/*19809*/       /*Scope*/ 53, /*->19863*/
/*19810*/         OPC_CheckPredicate, 57, // Predicate_azextloadi16
/*19812*/         OPC_Scope, 16, /*->19830*/ // 3 children in Scope
/*19814*/           OPC_CheckPatternPredicate, 0, // (Subtarget.hasHighWord())
/*19816*/           OPC_CheckComplexPat, /*CP*/0, /*#*/1, // selectBDXAddr20Only:$XBD2 #2 #3 #4
/*19819*/           OPC_EmitMergeInputChains1_0,
/*19820*/           OPC_MorphNodeTo, TARGET_VAL(SystemZ::LLHMux), 0|OPFL_Chain|OPFL_MemRefs,
                        1/*#VTs*/, MVT::i32, 3/*#Ops*/, 2, 3, 4, 
                    // Src: (ld:i32 bdxaddr20only:i64:$XBD2)<<P:Predicate_unindexedload>><<P:Predicate_azextload>><<P:Predicate_azextloadi16>> - Complexity = 16
                    // Dst: (LLHMux:i32 bdxaddr20only:i64:$XBD2)
/*19830*/         /*Scope*/ 14, /*->19845*/
/*19831*/           OPC_CheckComplexPat, /*CP*/0, /*#*/1, // selectBDXAddr20Only:$XBD2 #2 #3 #4
/*19834*/           OPC_EmitMergeInputChains1_0,
/*19835*/           OPC_MorphNodeTo, TARGET_VAL(SystemZ::LLH), 0|OPFL_Chain|OPFL_MemRefs,
                        1/*#VTs*/, MVT::i32, 3/*#Ops*/, 2, 3, 4, 
                    // Src: (ld:i32 bdxaddr20only:i64:$XBD2)<<P:Predicate_unindexedload>><<P:Predicate_azextload>><<P:Predicate_azextloadi16>> - Complexity = 16
                    // Dst: (LLH:i32 bdxaddr20only:i64:$XBD2)
/*19845*/         /*Scope*/ 16, /*->19862*/
/*19846*/           OPC_CheckPatternPredicate, 0, // (Subtarget.hasHighWord())
/*19848*/           OPC_CheckComplexPat, /*CP*/0, /*#*/1, // selectBDXAddr20Only:$XBD2 #2 #3 #4
/*19851*/           OPC_EmitMergeInputChains1_0,
/*19852*/           OPC_MorphNodeTo, TARGET_VAL(SystemZ::LLHH), 0|OPFL_Chain|OPFL_MemRefs,
                        1/*#VTs*/, MVT::i32, 3/*#Ops*/, 2, 3, 4, 
                    // Src: (ld:i32 bdxaddr20only:i64:$XBD2)<<P:Predicate_unindexedload>><<P:Predicate_azextload>><<P:Predicate_azextloadi16>> - Complexity = 16
                    // Dst: (LLHH:i32 bdxaddr20only:i64:$XBD2)
/*19862*/         0, /*End of Scope*/
/*19863*/       0, /*End of Scope*/
/*19864*/     /*SwitchType*/ 53,  MVT::i64,// ->19919
/*19866*/       OPC_Scope, 16, /*->19884*/ // 3 children in Scope
/*19868*/         OPC_CheckPredicate, 42, // Predicate_azextloadi8
/*19870*/         OPC_CheckComplexPat, /*CP*/0, /*#*/1, // selectBDXAddr20Only:$XBD2 #2 #3 #4
/*19873*/         OPC_EmitMergeInputChains1_0,
/*19874*/         OPC_MorphNodeTo, TARGET_VAL(SystemZ::LLGC), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i64, 3/*#Ops*/, 2, 3, 4, 
                  // Src: (ld:i64 bdxaddr20only:i64:$XBD2)<<P:Predicate_unindexedload>><<P:Predicate_azextload>><<P:Predicate_azextloadi8>> - Complexity = 16
                  // Dst: (LLGC:i64 bdxaddr20only:i64:$XBD2)
/*19884*/       /*Scope*/ 16, /*->19901*/
/*19885*/         OPC_CheckPredicate, 57, // Predicate_azextloadi16
/*19887*/         OPC_CheckComplexPat, /*CP*/0, /*#*/1, // selectBDXAddr20Only:$XBD2 #2 #3 #4
/*19890*/         OPC_EmitMergeInputChains1_0,
/*19891*/         OPC_MorphNodeTo, TARGET_VAL(SystemZ::LLGH), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i64, 3/*#Ops*/, 2, 3, 4, 
                  // Src: (ld:i64 bdxaddr20only:i64:$XBD2)<<P:Predicate_unindexedload>><<P:Predicate_azextload>><<P:Predicate_azextloadi16>> - Complexity = 16
                  // Dst: (LLGH:i64 bdxaddr20only:i64:$XBD2)
/*19901*/       /*Scope*/ 16, /*->19918*/
/*19902*/         OPC_CheckPredicate, 39, // Predicate_azextloadi32
/*19904*/         OPC_CheckComplexPat, /*CP*/0, /*#*/1, // selectBDXAddr20Only:$XBD2 #2 #3 #4
/*19907*/         OPC_EmitMergeInputChains1_0,
/*19908*/         OPC_MorphNodeTo, TARGET_VAL(SystemZ::LLGF), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i64, 3/*#Ops*/, 2, 3, 4, 
                  // Src: (ld:i64 bdxaddr20only:i64:$XBD2)<<P:Predicate_unindexedload>><<P:Predicate_azextload>><<P:Predicate_azextloadi32>> - Complexity = 16
                  // Dst: (LLGF:i64 bdxaddr20only:i64:$XBD2)
/*19918*/       0, /*End of Scope*/
/*19919*/     0, // EndSwitchType
/*19920*/   /*Scope*/ 88, /*->20009*/
/*19921*/     OPC_CheckPredicate, 13, // Predicate_load
/*19923*/     OPC_SwitchType /*3 cases */, 32,  MVT::f32,// ->19958
/*19926*/       OPC_Scope, 14, /*->19942*/ // 2 children in Scope
/*19928*/         OPC_CheckComplexPat, /*CP*/7, /*#*/1, // selectBDXAddr12Pair:$XBD2 #2 #3 #4
/*19931*/         OPC_EmitMergeInputChains1_0,
/*19932*/         OPC_MorphNodeTo, TARGET_VAL(SystemZ::LE), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::f32, 3/*#Ops*/, 2, 3, 4, 
                  // Src: (ld:f32 bdxaddr12pair:i64:$XBD2)<<P:Predicate_unindexedload>><<P:Predicate_load>> - Complexity = 16
                  // Dst: (LE:f32 bdxaddr12pair:i64:$XBD2)
/*19942*/       /*Scope*/ 14, /*->19957*/
/*19943*/         OPC_CheckComplexPat, /*CP*/8, /*#*/1, // selectBDXAddr20Pair:$XBD2 #2 #3 #4
/*19946*/         OPC_EmitMergeInputChains1_0,
/*19947*/         OPC_MorphNodeTo, TARGET_VAL(SystemZ::LEY), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::f32, 3/*#Ops*/, 2, 3, 4, 
                  // Src: (ld:f32 bdxaddr20pair:i64:$XBD2)<<P:Predicate_unindexedload>><<P:Predicate_load>> - Complexity = 16
                  // Dst: (LEY:f32 bdxaddr20pair:i64:$XBD2)
/*19957*/       0, /*End of Scope*/
/*19958*/     /*SwitchType*/ 32,  MVT::f64,// ->19992
/*19960*/       OPC_Scope, 14, /*->19976*/ // 2 children in Scope
/*19962*/         OPC_CheckComplexPat, /*CP*/7, /*#*/1, // selectBDXAddr12Pair:$XBD2 #2 #3 #4
/*19965*/         OPC_EmitMergeInputChains1_0,
/*19966*/         OPC_MorphNodeTo, TARGET_VAL(SystemZ::LD), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::f64, 3/*#Ops*/, 2, 3, 4, 
                  // Src: (ld:f64 bdxaddr12pair:i64:$XBD2)<<P:Predicate_unindexedload>><<P:Predicate_load>> - Complexity = 16
                  // Dst: (LD:f64 bdxaddr12pair:i64:$XBD2)
/*19976*/       /*Scope*/ 14, /*->19991*/
/*19977*/         OPC_CheckComplexPat, /*CP*/8, /*#*/1, // selectBDXAddr20Pair:$XBD2 #2 #3 #4
/*19980*/         OPC_EmitMergeInputChains1_0,
/*19981*/         OPC_MorphNodeTo, TARGET_VAL(SystemZ::LDY), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::f64, 3/*#Ops*/, 2, 3, 4, 
                  // Src: (ld:f64 bdxaddr20pair:i64:$XBD2)<<P:Predicate_unindexedload>><<P:Predicate_load>> - Complexity = 16
                  // Dst: (LDY:f64 bdxaddr20pair:i64:$XBD2)
/*19991*/       0, /*End of Scope*/
/*19992*/     /*SwitchType*/ 14,  MVT::f128,// ->20008
/*19994*/       OPC_CheckComplexPat, /*CP*/9, /*#*/1, // selectBDXAddr20Only128:$src #2 #3 #4
/*19997*/       OPC_EmitMergeInputChains1_0,
/*19998*/       OPC_MorphNodeTo, TARGET_VAL(SystemZ::LX), 0|OPFL_Chain|OPFL_MemRefs,
                    1/*#VTs*/, MVT::f128, 3/*#Ops*/, 2, 3, 4, 
                // Src: (ld:f128 bdxaddr20only128:i64:$src)<<P:Predicate_unindexedload>><<P:Predicate_load>> - Complexity = 16
                // Dst: (LX:f128 bdxaddr20only128:i64:$src)
/*20008*/     0, // EndSwitchType
/*20009*/   /*Scope*/ 60, /*->20070*/
/*20010*/     OPC_CheckPredicate, 76, // Predicate_extload
/*20012*/     OPC_Scope, 36, /*->20050*/ // 2 children in Scope
/*20014*/       OPC_CheckPredicate, 77, // Predicate_extloadf32
/*20016*/       OPC_SwitchType /*2 cases */, 14,  MVT::f64,// ->20033
/*20019*/         OPC_CheckComplexPat, /*CP*/16, /*#*/1, // selectBDXAddr12Only:$XBD2 #2 #3 #4
/*20022*/         OPC_EmitMergeInputChains1_0,
/*20023*/         OPC_MorphNodeTo, TARGET_VAL(SystemZ::LDEB), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::f64, 3/*#Ops*/, 2, 3, 4, 
                  // Src: (ld:f64 bdxaddr12only:i64:$XBD2)<<P:Predicate_unindexedload>><<P:Predicate_extload>><<P:Predicate_extloadf32>> - Complexity = 16
                  // Dst: (LDEB:f64 bdxaddr12only:i64:$XBD2)
/*20033*/       /*SwitchType*/ 14,  MVT::f128,// ->20049
/*20035*/         OPC_CheckComplexPat, /*CP*/16, /*#*/1, // selectBDXAddr12Only:$XBD2 #2 #3 #4
/*20038*/         OPC_EmitMergeInputChains1_0,
/*20039*/         OPC_MorphNodeTo, TARGET_VAL(SystemZ::LXEB), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::f128, 3/*#Ops*/, 2, 3, 4, 
                  // Src: (ld:f128 bdxaddr12only:i64:$XBD2)<<P:Predicate_unindexedload>><<P:Predicate_extload>><<P:Predicate_extloadf32>> - Complexity = 16
                  // Dst: (LXEB:f128 bdxaddr12only:i64:$XBD2)
/*20049*/       0, // EndSwitchType
/*20050*/     /*Scope*/ 18, /*->20069*/
/*20051*/       OPC_CheckPredicate, 78, // Predicate_extloadf64
/*20053*/       OPC_CheckType, MVT::f128,
/*20055*/       OPC_CheckComplexPat, /*CP*/16, /*#*/1, // selectBDXAddr12Only:$XBD2 #2 #3 #4
/*20058*/       OPC_EmitMergeInputChains1_0,
/*20059*/       OPC_MorphNodeTo, TARGET_VAL(SystemZ::LXDB), 0|OPFL_Chain|OPFL_MemRefs,
                    1/*#VTs*/, MVT::f128, 3/*#Ops*/, 2, 3, 4, 
                // Src: (ld:f128 bdxaddr12only:i64:$XBD2)<<P:Predicate_unindexedload>><<P:Predicate_extload>><<P:Predicate_extloadf64>> - Complexity = 16
                // Dst: (LXDB:f128 bdxaddr12only:i64:$XBD2)
/*20069*/     0, /*End of Scope*/
/*20070*/   0, /*End of Scope*/
/*20071*/ /*SwitchOpcode*/ 38|128,1/*166*/,  TARGET_VAL(ISD::ATOMIC_LOAD_ADD),// ->20241
/*20075*/   OPC_RecordMemRef,
/*20076*/   OPC_RecordNode,   // #0 = 'atomic_load_add' chained node
/*20077*/   OPC_RecordChild1, // #1 = $ptr
/*20078*/   OPC_CheckChild1Type, MVT::i64,
/*20080*/   OPC_RecordChild2, // #2 = $src2
/*20081*/   OPC_Scope, 117, /*->20200*/ // 3 children in Scope
/*20083*/     OPC_MoveChild, 2,
/*20085*/     OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*20088*/     OPC_Scope, 27, /*->20117*/ // 4 children in Scope
/*20090*/       OPC_CheckPredicate, 31, // Predicate_imm32sx16
/*20092*/       OPC_MoveParent,
/*20093*/       OPC_CheckPredicate, 79, // Predicate_atomic_load_add_32
/*20095*/       OPC_CheckType, MVT::i32,
/*20097*/       OPC_CheckComplexPat, /*CP*/4, /*#*/1, // selectBDAddr20Only:$ptr #3 #4
/*20100*/       OPC_EmitMergeInputChains1_0,
/*20101*/       OPC_EmitConvertToTarget, 2,
/*20103*/       OPC_EmitNodeXForm, 2, 5, // SIMM16
/*20106*/       OPC_MorphNodeTo, TARGET_VAL(SystemZ::ATOMIC_LOAD_AHI), 0|OPFL_Chain|OPFL_MemRefs,
                    2/*#VTs*/, MVT::i32, MVT::i32, 3/*#Ops*/, 3, 4, 6, 
                // Src: (atomic_load_add:i32 bdaddr20only:i64:$ptr, (imm:i32)<<P:Predicate_imm32sx16>><<X:SIMM16>>:$src2)<<P:Predicate_atomic_load_add_32>> - Complexity = 17
                // Dst: (ATOMIC_LOAD_AHI:i32:i32 bdaddr20only:i64:$ptr, (SIMM16:i32 (imm:i32):$src2))
/*20117*/     /*Scope*/ 27, /*->20145*/
/*20118*/       OPC_CheckPredicate, 32, // Predicate_imm64sx16
/*20120*/       OPC_MoveParent,
/*20121*/       OPC_CheckPredicate, 80, // Predicate_atomic_load_add_64
/*20123*/       OPC_CheckType, MVT::i64,
/*20125*/       OPC_CheckComplexPat, /*CP*/4, /*#*/1, // selectBDAddr20Only:$ptr #3 #4
/*20128*/       OPC_EmitMergeInputChains1_0,
/*20129*/       OPC_EmitConvertToTarget, 2,
/*20131*/       OPC_EmitNodeXForm, 2, 5, // SIMM16
/*20134*/       OPC_MorphNodeTo, TARGET_VAL(SystemZ::ATOMIC_LOAD_AGHI), 0|OPFL_Chain|OPFL_MemRefs,
                    2/*#VTs*/, MVT::i64, MVT::i32, 3/*#Ops*/, 3, 4, 6, 
                // Src: (atomic_load_add:i64 bdaddr20only:i64:$ptr, (imm:i64)<<P:Predicate_imm64sx16>><<X:SIMM16>>:$src2)<<P:Predicate_atomic_load_add_64>> - Complexity = 17
                // Dst: (ATOMIC_LOAD_AGHI:i64:i32 bdaddr20only:i64:$ptr, (SIMM16:i64 (imm:i64):$src2))
/*20145*/     /*Scope*/ 27, /*->20173*/
/*20146*/       OPC_CheckPredicate, 63, // Predicate_imm64sx32
/*20148*/       OPC_MoveParent,
/*20149*/       OPC_CheckPredicate, 80, // Predicate_atomic_load_add_64
/*20151*/       OPC_CheckType, MVT::i64,
/*20153*/       OPC_CheckComplexPat, /*CP*/4, /*#*/1, // selectBDAddr20Only:$ptr #3 #4
/*20156*/       OPC_EmitMergeInputChains1_0,
/*20157*/       OPC_EmitConvertToTarget, 2,
/*20159*/       OPC_EmitNodeXForm, 11, 5, // SIMM32
/*20162*/       OPC_MorphNodeTo, TARGET_VAL(SystemZ::ATOMIC_LOAD_AGFI), 0|OPFL_Chain|OPFL_MemRefs,
                    2/*#VTs*/, MVT::i64, MVT::i32, 3/*#Ops*/, 3, 4, 6, 
                // Src: (atomic_load_add:i64 bdaddr20only:i64:$ptr, (imm:i64)<<P:Predicate_imm64sx32>><<X:SIMM32>>:$src2)<<P:Predicate_atomic_load_add_64>> - Complexity = 17
                // Dst: (ATOMIC_LOAD_AGFI:i64:i32 bdaddr20only:i64:$ptr, (SIMM32:i64 (imm:i64):$src2))
/*20173*/     /*Scope*/ 25, /*->20199*/
/*20174*/       OPC_MoveParent,
/*20175*/       OPC_CheckPredicate, 79, // Predicate_atomic_load_add_32
/*20177*/       OPC_CheckType, MVT::i32,
/*20179*/       OPC_CheckComplexPat, /*CP*/4, /*#*/1, // selectBDAddr20Only:$ptr #3 #4
/*20182*/       OPC_EmitMergeInputChains1_0,
/*20183*/       OPC_EmitConvertToTarget, 2,
/*20185*/       OPC_EmitNodeXForm, 11, 5, // SIMM32
/*20188*/       OPC_MorphNodeTo, TARGET_VAL(SystemZ::ATOMIC_LOAD_AFI), 0|OPFL_Chain|OPFL_MemRefs,
                    2/*#VTs*/, MVT::i32, MVT::i32, 3/*#Ops*/, 3, 4, 6, 
                // Src: (atomic_load_add:i32 bdaddr20only:i64:$ptr, (imm:i32)<<X:SIMM32>>:$src2)<<P:Predicate_atomic_load_add_32>> - Complexity = 16
                // Dst: (ATOMIC_LOAD_AFI:i32:i32 bdaddr20only:i64:$ptr, (SIMM32:i32 (imm:i32):$src2))
/*20199*/     0, /*End of Scope*/
/*20200*/   /*Scope*/ 19, /*->20220*/
/*20201*/     OPC_CheckPredicate, 79, // Predicate_atomic_load_add_32
/*20203*/     OPC_CheckType, MVT::i32,
/*20205*/     OPC_CheckComplexPat, /*CP*/4, /*#*/1, // selectBDAddr20Only:$ptr #3 #4
/*20208*/     OPC_EmitMergeInputChains1_0,
/*20209*/     OPC_MorphNodeTo, TARGET_VAL(SystemZ::ATOMIC_LOAD_AR), 0|OPFL_Chain|OPFL_MemRefs,
                  2/*#VTs*/, MVT::i32, MVT::i32, 3/*#Ops*/, 3, 4, 2, 
              // Src: (atomic_load_add:i32 bdaddr20only:i64:$ptr, GR32:i32:$src2)<<P:Predicate_atomic_load_add_32>> - Complexity = 13
              // Dst: (ATOMIC_LOAD_AR:i32:i32 bdaddr20only:i64:$ptr, GR32:i32:$src2)
/*20220*/   /*Scope*/ 19, /*->20240*/
/*20221*/     OPC_CheckPredicate, 80, // Predicate_atomic_load_add_64
/*20223*/     OPC_CheckType, MVT::i64,
/*20225*/     OPC_CheckComplexPat, /*CP*/4, /*#*/1, // selectBDAddr20Only:$ptr #3 #4
/*20228*/     OPC_EmitMergeInputChains1_0,
/*20229*/     OPC_MorphNodeTo, TARGET_VAL(SystemZ::ATOMIC_LOAD_AGR), 0|OPFL_Chain|OPFL_MemRefs,
                  2/*#VTs*/, MVT::i64, MVT::i32, 3/*#Ops*/, 3, 4, 2, 
              // Src: (atomic_load_add:i64 bdaddr20only:i64:$ptr, GR64:i64:$src2)<<P:Predicate_atomic_load_add_64>> - Complexity = 13
              // Dst: (ATOMIC_LOAD_AGR:i64:i32 bdaddr20only:i64:$ptr, GR64:i64:$src2)
/*20240*/   0, /*End of Scope*/
/*20241*/ /*SwitchOpcode*/ 51|128,2/*307*/,  TARGET_VAL(ISD::ATOMIC_LOAD_AND),// ->20552
/*20245*/   OPC_RecordMemRef,
/*20246*/   OPC_RecordNode,   // #0 = 'atomic_load_and' chained node
/*20247*/   OPC_RecordChild1, // #1 = $ptr
/*20248*/   OPC_CheckChild1Type, MVT::i64,
/*20250*/   OPC_RecordChild2, // #2 = $src2
/*20251*/   OPC_Scope, 1|128,2/*257*/, /*->20511*/ // 3 children in Scope
/*20254*/     OPC_MoveChild, 2,
/*20256*/     OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*20259*/     OPC_Scope, 27, /*->20288*/ // 9 children in Scope
/*20261*/       OPC_CheckPredicate, 66, // Predicate_imm32ll16c
/*20263*/       OPC_MoveParent,
/*20264*/       OPC_CheckPredicate, 81, // Predicate_atomic_load_and_32
/*20266*/       OPC_CheckType, MVT::i32,
/*20268*/       OPC_CheckComplexPat, /*CP*/4, /*#*/1, // selectBDAddr20Only:$ptr #3 #4
/*20271*/       OPC_EmitMergeInputChains1_0,
/*20272*/       OPC_EmitConvertToTarget, 2,
/*20274*/       OPC_EmitNodeXForm, 6, 5, // LL16
/*20277*/       OPC_MorphNodeTo, TARGET_VAL(SystemZ::ATOMIC_LOAD_NILL), 0|OPFL_Chain|OPFL_MemRefs,
                    2/*#VTs*/, MVT::i32, MVT::i32, 3/*#Ops*/, 3, 4, 6, 
                // Src: (atomic_load_and:i32 bdaddr20only:i64:$ptr, (imm:i32)<<P:Predicate_imm32ll16c>><<X:LL16>>:$src2)<<P:Predicate_atomic_load_and_32>> - Complexity = 17
                // Dst: (ATOMIC_LOAD_NILL:i32:i32 bdaddr20only:i64:$ptr, (LL16:i32 (imm:i32):$src2))
/*20288*/     /*Scope*/ 27, /*->20316*/
/*20289*/       OPC_CheckPredicate, 67, // Predicate_imm32lh16c
/*20291*/       OPC_MoveParent,
/*20292*/       OPC_CheckPredicate, 81, // Predicate_atomic_load_and_32
/*20294*/       OPC_CheckType, MVT::i32,
/*20296*/       OPC_CheckComplexPat, /*CP*/4, /*#*/1, // selectBDAddr20Only:$ptr #3 #4
/*20299*/       OPC_EmitMergeInputChains1_0,
/*20300*/       OPC_EmitConvertToTarget, 2,
/*20302*/       OPC_EmitNodeXForm, 7, 5, // LH16
/*20305*/       OPC_MorphNodeTo, TARGET_VAL(SystemZ::ATOMIC_LOAD_NILH), 0|OPFL_Chain|OPFL_MemRefs,
                    2/*#VTs*/, MVT::i32, MVT::i32, 3/*#Ops*/, 3, 4, 6, 
                // Src: (atomic_load_and:i32 bdaddr20only:i64:$ptr, (imm:i32)<<P:Predicate_imm32lh16c>><<X:LH16>>:$src2)<<P:Predicate_atomic_load_and_32>> - Complexity = 17
                // Dst: (ATOMIC_LOAD_NILH:i32:i32 bdaddr20only:i64:$ptr, (LH16:i32 (imm:i32):$src2))
/*20316*/     /*Scope*/ 27, /*->20344*/
/*20317*/       OPC_CheckPredicate, 68, // Predicate_imm64ll16c
/*20319*/       OPC_MoveParent,
/*20320*/       OPC_CheckPredicate, 82, // Predicate_atomic_load_and_64
/*20322*/       OPC_CheckType, MVT::i64,
/*20324*/       OPC_CheckComplexPat, /*CP*/4, /*#*/1, // selectBDAddr20Only:$ptr #3 #4
/*20327*/       OPC_EmitMergeInputChains1_0,
/*20328*/       OPC_EmitConvertToTarget, 2,
/*20330*/       OPC_EmitNodeXForm, 6, 5, // LL16
/*20333*/       OPC_MorphNodeTo, TARGET_VAL(SystemZ::ATOMIC_LOAD_NILL64), 0|OPFL_Chain|OPFL_MemRefs,
                    2/*#VTs*/, MVT::i64, MVT::i32, 3/*#Ops*/, 3, 4, 6, 
                // Src: (atomic_load_and:i64 bdaddr20only:i64:$ptr, (imm:i64)<<P:Predicate_imm64ll16c>><<X:LL16>>:$src2)<<P:Predicate_atomic_load_and_64>> - Complexity = 17
                // Dst: (ATOMIC_LOAD_NILL64:i64:i32 bdaddr20only:i64:$ptr, (LL16:i64 (imm:i64):$src2))
/*20344*/     /*Scope*/ 27, /*->20372*/
/*20345*/       OPC_CheckPredicate, 69, // Predicate_imm64lh16c
/*20347*/       OPC_MoveParent,
/*20348*/       OPC_CheckPredicate, 82, // Predicate_atomic_load_and_64
/*20350*/       OPC_CheckType, MVT::i64,
/*20352*/       OPC_CheckComplexPat, /*CP*/4, /*#*/1, // selectBDAddr20Only:$ptr #3 #4
/*20355*/       OPC_EmitMergeInputChains1_0,
/*20356*/       OPC_EmitConvertToTarget, 2,
/*20358*/       OPC_EmitNodeXForm, 7, 5, // LH16
/*20361*/       OPC_MorphNodeTo, TARGET_VAL(SystemZ::ATOMIC_LOAD_NILH64), 0|OPFL_Chain|OPFL_MemRefs,
                    2/*#VTs*/, MVT::i64, MVT::i32, 3/*#Ops*/, 3, 4, 6, 
                // Src: (atomic_load_and:i64 bdaddr20only:i64:$ptr, (imm:i64)<<P:Predicate_imm64lh16c>><<X:LH16>>:$src2)<<P:Predicate_atomic_load_and_64>> - Complexity = 17
                // Dst: (ATOMIC_LOAD_NILH64:i64:i32 bdaddr20only:i64:$ptr, (LH16:i64 (imm:i64):$src2))
/*20372*/     /*Scope*/ 27, /*->20400*/
/*20373*/       OPC_CheckPredicate, 70, // Predicate_imm64hl16c
/*20375*/       OPC_MoveParent,
/*20376*/       OPC_CheckPredicate, 82, // Predicate_atomic_load_and_64
/*20378*/       OPC_CheckType, MVT::i64,
/*20380*/       OPC_CheckComplexPat, /*CP*/4, /*#*/1, // selectBDAddr20Only:$ptr #3 #4
/*20383*/       OPC_EmitMergeInputChains1_0,
/*20384*/       OPC_EmitConvertToTarget, 2,
/*20386*/       OPC_EmitNodeXForm, 8, 5, // HL16
/*20389*/       OPC_MorphNodeTo, TARGET_VAL(SystemZ::ATOMIC_LOAD_NIHL64), 0|OPFL_Chain|OPFL_MemRefs,
                    2/*#VTs*/, MVT::i64, MVT::i32, 3/*#Ops*/, 3, 4, 6, 
                // Src: (atomic_load_and:i64 bdaddr20only:i64:$ptr, (imm:i64)<<P:Predicate_imm64hl16c>><<X:HL16>>:$src2)<<P:Predicate_atomic_load_and_64>> - Complexity = 17
                // Dst: (ATOMIC_LOAD_NIHL64:i64:i32 bdaddr20only:i64:$ptr, (HL16:i64 (imm:i64):$src2))
/*20400*/     /*Scope*/ 27, /*->20428*/
/*20401*/       OPC_CheckPredicate, 71, // Predicate_imm64hh16c
/*20403*/       OPC_MoveParent,
/*20404*/       OPC_CheckPredicate, 82, // Predicate_atomic_load_and_64
/*20406*/       OPC_CheckType, MVT::i64,
/*20408*/       OPC_CheckComplexPat, /*CP*/4, /*#*/1, // selectBDAddr20Only:$ptr #3 #4
/*20411*/       OPC_EmitMergeInputChains1_0,
/*20412*/       OPC_EmitConvertToTarget, 2,
/*20414*/       OPC_EmitNodeXForm, 9, 5, // HH16
/*20417*/       OPC_MorphNodeTo, TARGET_VAL(SystemZ::ATOMIC_LOAD_NIHH64), 0|OPFL_Chain|OPFL_MemRefs,
                    2/*#VTs*/, MVT::i64, MVT::i32, 3/*#Ops*/, 3, 4, 6, 
                // Src: (atomic_load_and:i64 bdaddr20only:i64:$ptr, (imm:i64)<<P:Predicate_imm64hh16c>><<X:HH16>>:$src2)<<P:Predicate_atomic_load_and_64>> - Complexity = 17
                // Dst: (ATOMIC_LOAD_NIHH64:i64:i32 bdaddr20only:i64:$ptr, (HH16:i64 (imm:i64):$src2))
/*20428*/     /*Scope*/ 27, /*->20456*/
/*20429*/       OPC_CheckPredicate, 72, // Predicate_imm64lf32c
/*20431*/       OPC_MoveParent,
/*20432*/       OPC_CheckPredicate, 82, // Predicate_atomic_load_and_64
/*20434*/       OPC_CheckType, MVT::i64,
/*20436*/       OPC_CheckComplexPat, /*CP*/4, /*#*/1, // selectBDAddr20Only:$ptr #3 #4
/*20439*/       OPC_EmitMergeInputChains1_0,
/*20440*/       OPC_EmitConvertToTarget, 2,
/*20442*/       OPC_EmitNodeXForm, 3, 5, // LF32
/*20445*/       OPC_MorphNodeTo, TARGET_VAL(SystemZ::ATOMIC_LOAD_NILF64), 0|OPFL_Chain|OPFL_MemRefs,
                    2/*#VTs*/, MVT::i64, MVT::i32, 3/*#Ops*/, 3, 4, 6, 
                // Src: (atomic_load_and:i64 bdaddr20only:i64:$ptr, (imm:i64)<<P:Predicate_imm64lf32c>><<X:LF32>>:$src2)<<P:Predicate_atomic_load_and_64>> - Complexity = 17
                // Dst: (ATOMIC_LOAD_NILF64:i64:i32 bdaddr20only:i64:$ptr, (LF32:i64 (imm:i64):$src2))
/*20456*/     /*Scope*/ 27, /*->20484*/
/*20457*/       OPC_CheckPredicate, 73, // Predicate_imm64hf32c
/*20459*/       OPC_MoveParent,
/*20460*/       OPC_CheckPredicate, 82, // Predicate_atomic_load_and_64
/*20462*/       OPC_CheckType, MVT::i64,
/*20464*/       OPC_CheckComplexPat, /*CP*/4, /*#*/1, // selectBDAddr20Only:$ptr #3 #4
/*20467*/       OPC_EmitMergeInputChains1_0,
/*20468*/       OPC_EmitConvertToTarget, 2,
/*20470*/       OPC_EmitNodeXForm, 4, 5, // HF32
/*20473*/       OPC_MorphNodeTo, TARGET_VAL(SystemZ::ATOMIC_LOAD_NIHF64), 0|OPFL_Chain|OPFL_MemRefs,
                    2/*#VTs*/, MVT::i64, MVT::i32, 3/*#Ops*/, 3, 4, 6, 
                // Src: (atomic_load_and:i64 bdaddr20only:i64:$ptr, (imm:i64)<<P:Predicate_imm64hf32c>><<X:HF32>>:$src2)<<P:Predicate_atomic_load_and_64>> - Complexity = 17
                // Dst: (ATOMIC_LOAD_NIHF64:i64:i32 bdaddr20only:i64:$ptr, (HF32:i64 (imm:i64):$src2))
/*20484*/     /*Scope*/ 25, /*->20510*/
/*20485*/       OPC_MoveParent,
/*20486*/       OPC_CheckPredicate, 81, // Predicate_atomic_load_and_32
/*20488*/       OPC_CheckType, MVT::i32,
/*20490*/       OPC_CheckComplexPat, /*CP*/4, /*#*/1, // selectBDAddr20Only:$ptr #3 #4
/*20493*/       OPC_EmitMergeInputChains1_0,
/*20494*/       OPC_EmitConvertToTarget, 2,
/*20496*/       OPC_EmitNodeXForm, 5, 5, // UIMM32
/*20499*/       OPC_MorphNodeTo, TARGET_VAL(SystemZ::ATOMIC_LOAD_NILF), 0|OPFL_Chain|OPFL_MemRefs,
                    2/*#VTs*/, MVT::i32, MVT::i32, 3/*#Ops*/, 3, 4, 6, 
                // Src: (atomic_load_and:i32 bdaddr20only:i64:$ptr, (imm:i32)<<X:UIMM32>>:$src2)<<P:Predicate_atomic_load_and_32>> - Complexity = 16
                // Dst: (ATOMIC_LOAD_NILF:i32:i32 bdaddr20only:i64:$ptr, (UIMM32:i32 (imm:i32):$src2))
/*20510*/     0, /*End of Scope*/
/*20511*/   /*Scope*/ 19, /*->20531*/
/*20512*/     OPC_CheckPredicate, 81, // Predicate_atomic_load_and_32
/*20514*/     OPC_CheckType, MVT::i32,
/*20516*/     OPC_CheckComplexPat, /*CP*/4, /*#*/1, // selectBDAddr20Only:$ptr #3 #4
/*20519*/     OPC_EmitMergeInputChains1_0,
/*20520*/     OPC_MorphNodeTo, TARGET_VAL(SystemZ::ATOMIC_LOAD_NR), 0|OPFL_Chain|OPFL_MemRefs,
                  2/*#VTs*/, MVT::i32, MVT::i32, 3/*#Ops*/, 3, 4, 2, 
              // Src: (atomic_load_and:i32 bdaddr20only:i64:$ptr, GR32:i32:$src2)<<P:Predicate_atomic_load_and_32>> - Complexity = 13
              // Dst: (ATOMIC_LOAD_NR:i32:i32 bdaddr20only:i64:$ptr, GR32:i32:$src2)
/*20531*/   /*Scope*/ 19, /*->20551*/
/*20532*/     OPC_CheckPredicate, 82, // Predicate_atomic_load_and_64
/*20534*/     OPC_CheckType, MVT::i64,
/*20536*/     OPC_CheckComplexPat, /*CP*/4, /*#*/1, // selectBDAddr20Only:$ptr #3 #4
/*20539*/     OPC_EmitMergeInputChains1_0,
/*20540*/     OPC_MorphNodeTo, TARGET_VAL(SystemZ::ATOMIC_LOAD_NGR), 0|OPFL_Chain|OPFL_MemRefs,
                  2/*#VTs*/, MVT::i64, MVT::i32, 3/*#Ops*/, 3, 4, 2, 
              // Src: (atomic_load_and:i64 bdaddr20only:i64:$ptr, GR64:i64:$src2)<<P:Predicate_atomic_load_and_64>> - Complexity = 13
              // Dst: (ATOMIC_LOAD_NGR:i64:i32 bdaddr20only:i64:$ptr, GR64:i64:$src2)
/*20551*/   0, /*End of Scope*/
/*20552*/ /*SwitchOpcode*/ 51|128,2/*307*/,  TARGET_VAL(ISD::ATOMIC_LOAD_OR),// ->20863
/*20556*/   OPC_RecordMemRef,
/*20557*/   OPC_RecordNode,   // #0 = 'atomic_load_or' chained node
/*20558*/   OPC_RecordChild1, // #1 = $ptr
/*20559*/   OPC_CheckChild1Type, MVT::i64,
/*20561*/   OPC_RecordChild2, // #2 = $src2
/*20562*/   OPC_Scope, 1|128,2/*257*/, /*->20822*/ // 3 children in Scope
/*20565*/     OPC_MoveChild, 2,
/*20567*/     OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*20570*/     OPC_Scope, 27, /*->20599*/ // 9 children in Scope
/*20572*/       OPC_CheckPredicate, 45, // Predicate_imm32ll16
/*20574*/       OPC_MoveParent,
/*20575*/       OPC_CheckPredicate, 83, // Predicate_atomic_load_or_32
/*20577*/       OPC_CheckType, MVT::i32,
/*20579*/       OPC_CheckComplexPat, /*CP*/4, /*#*/1, // selectBDAddr20Only:$ptr #3 #4
/*20582*/       OPC_EmitMergeInputChains1_0,
/*20583*/       OPC_EmitConvertToTarget, 2,
/*20585*/       OPC_EmitNodeXForm, 6, 5, // LL16
/*20588*/       OPC_MorphNodeTo, TARGET_VAL(SystemZ::ATOMIC_LOAD_OILL), 0|OPFL_Chain|OPFL_MemRefs,
                    2/*#VTs*/, MVT::i32, MVT::i32, 3/*#Ops*/, 3, 4, 6, 
                // Src: (atomic_load_or:i32 bdaddr20only:i64:$ptr, (imm:i32)<<P:Predicate_imm32ll16>><<X:LL16>>:$src2)<<P:Predicate_atomic_load_or_32>> - Complexity = 17
                // Dst: (ATOMIC_LOAD_OILL:i32:i32 bdaddr20only:i64:$ptr, (LL16:i32 (imm:i32):$src2))
/*20599*/     /*Scope*/ 27, /*->20627*/
/*20600*/       OPC_CheckPredicate, 46, // Predicate_imm32lh16
/*20602*/       OPC_MoveParent,
/*20603*/       OPC_CheckPredicate, 83, // Predicate_atomic_load_or_32
/*20605*/       OPC_CheckType, MVT::i32,
/*20607*/       OPC_CheckComplexPat, /*CP*/4, /*#*/1, // selectBDAddr20Only:$ptr #3 #4
/*20610*/       OPC_EmitMergeInputChains1_0,
/*20611*/       OPC_EmitConvertToTarget, 2,
/*20613*/       OPC_EmitNodeXForm, 7, 5, // LH16
/*20616*/       OPC_MorphNodeTo, TARGET_VAL(SystemZ::ATOMIC_LOAD_OILH), 0|OPFL_Chain|OPFL_MemRefs,
                    2/*#VTs*/, MVT::i32, MVT::i32, 3/*#Ops*/, 3, 4, 6, 
                // Src: (atomic_load_or:i32 bdaddr20only:i64:$ptr, (imm:i32)<<P:Predicate_imm32lh16>><<X:LH16>>:$src2)<<P:Predicate_atomic_load_or_32>> - Complexity = 17
                // Dst: (ATOMIC_LOAD_OILH:i32:i32 bdaddr20only:i64:$ptr, (LH16:i32 (imm:i32):$src2))
/*20627*/     /*Scope*/ 27, /*->20655*/
/*20628*/       OPC_CheckPredicate, 47, // Predicate_imm64ll16
/*20630*/       OPC_MoveParent,
/*20631*/       OPC_CheckPredicate, 84, // Predicate_atomic_load_or_64
/*20633*/       OPC_CheckType, MVT::i64,
/*20635*/       OPC_CheckComplexPat, /*CP*/4, /*#*/1, // selectBDAddr20Only:$ptr #3 #4
/*20638*/       OPC_EmitMergeInputChains1_0,
/*20639*/       OPC_EmitConvertToTarget, 2,
/*20641*/       OPC_EmitNodeXForm, 6, 5, // LL16
/*20644*/       OPC_MorphNodeTo, TARGET_VAL(SystemZ::ATOMIC_LOAD_OILL64), 0|OPFL_Chain|OPFL_MemRefs,
                    2/*#VTs*/, MVT::i64, MVT::i32, 3/*#Ops*/, 3, 4, 6, 
                // Src: (atomic_load_or:i64 bdaddr20only:i64:$ptr, (imm:i64)<<P:Predicate_imm64ll16>><<X:LL16>>:$src2)<<P:Predicate_atomic_load_or_64>> - Complexity = 17
                // Dst: (ATOMIC_LOAD_OILL64:i64:i32 bdaddr20only:i64:$ptr, (LL16:i64 (imm:i64):$src2))
/*20655*/     /*Scope*/ 27, /*->20683*/
/*20656*/       OPC_CheckPredicate, 48, // Predicate_imm64lh16
/*20658*/       OPC_MoveParent,
/*20659*/       OPC_CheckPredicate, 84, // Predicate_atomic_load_or_64
/*20661*/       OPC_CheckType, MVT::i64,
/*20663*/       OPC_CheckComplexPat, /*CP*/4, /*#*/1, // selectBDAddr20Only:$ptr #3 #4
/*20666*/       OPC_EmitMergeInputChains1_0,
/*20667*/       OPC_EmitConvertToTarget, 2,
/*20669*/       OPC_EmitNodeXForm, 7, 5, // LH16
/*20672*/       OPC_MorphNodeTo, TARGET_VAL(SystemZ::ATOMIC_LOAD_OILH64), 0|OPFL_Chain|OPFL_MemRefs,
                    2/*#VTs*/, MVT::i64, MVT::i32, 3/*#Ops*/, 3, 4, 6, 
                // Src: (atomic_load_or:i64 bdaddr20only:i64:$ptr, (imm:i64)<<P:Predicate_imm64lh16>><<X:LH16>>:$src2)<<P:Predicate_atomic_load_or_64>> - Complexity = 17
                // Dst: (ATOMIC_LOAD_OILH64:i64:i32 bdaddr20only:i64:$ptr, (LH16:i64 (imm:i64):$src2))
/*20683*/     /*Scope*/ 27, /*->20711*/
/*20684*/       OPC_CheckPredicate, 49, // Predicate_imm64hl16
/*20686*/       OPC_MoveParent,
/*20687*/       OPC_CheckPredicate, 84, // Predicate_atomic_load_or_64
/*20689*/       OPC_CheckType, MVT::i64,
/*20691*/       OPC_CheckComplexPat, /*CP*/4, /*#*/1, // selectBDAddr20Only:$ptr #3 #4
/*20694*/       OPC_EmitMergeInputChains1_0,
/*20695*/       OPC_EmitConvertToTarget, 2,
/*20697*/       OPC_EmitNodeXForm, 8, 5, // HL16
/*20700*/       OPC_MorphNodeTo, TARGET_VAL(SystemZ::ATOMIC_LOAD_OIHL64), 0|OPFL_Chain|OPFL_MemRefs,
                    2/*#VTs*/, MVT::i64, MVT::i32, 3/*#Ops*/, 3, 4, 6, 
                // Src: (atomic_load_or:i64 bdaddr20only:i64:$ptr, (imm:i64)<<P:Predicate_imm64hl16>><<X:HL16>>:$src2)<<P:Predicate_atomic_load_or_64>> - Complexity = 17
                // Dst: (ATOMIC_LOAD_OIHL64:i64:i32 bdaddr20only:i64:$ptr, (HL16:i64 (imm:i64):$src2))
/*20711*/     /*Scope*/ 27, /*->20739*/
/*20712*/       OPC_CheckPredicate, 50, // Predicate_imm64hh16
/*20714*/       OPC_MoveParent,
/*20715*/       OPC_CheckPredicate, 84, // Predicate_atomic_load_or_64
/*20717*/       OPC_CheckType, MVT::i64,
/*20719*/       OPC_CheckComplexPat, /*CP*/4, /*#*/1, // selectBDAddr20Only:$ptr #3 #4
/*20722*/       OPC_EmitMergeInputChains1_0,
/*20723*/       OPC_EmitConvertToTarget, 2,
/*20725*/       OPC_EmitNodeXForm, 9, 5, // HH16
/*20728*/       OPC_MorphNodeTo, TARGET_VAL(SystemZ::ATOMIC_LOAD_OIHH64), 0|OPFL_Chain|OPFL_MemRefs,
                    2/*#VTs*/, MVT::i64, MVT::i32, 3/*#Ops*/, 3, 4, 6, 
                // Src: (atomic_load_or:i64 bdaddr20only:i64:$ptr, (imm:i64)<<P:Predicate_imm64hh16>><<X:HH16>>:$src2)<<P:Predicate_atomic_load_or_64>> - Complexity = 17
                // Dst: (ATOMIC_LOAD_OIHH64:i64:i32 bdaddr20only:i64:$ptr, (HH16:i64 (imm:i64):$src2))
/*20739*/     /*Scope*/ 27, /*->20767*/
/*20740*/       OPC_CheckPredicate, 40, // Predicate_imm64lf32
/*20742*/       OPC_MoveParent,
/*20743*/       OPC_CheckPredicate, 84, // Predicate_atomic_load_or_64
/*20745*/       OPC_CheckType, MVT::i64,
/*20747*/       OPC_CheckComplexPat, /*CP*/4, /*#*/1, // selectBDAddr20Only:$ptr #3 #4
/*20750*/       OPC_EmitMergeInputChains1_0,
/*20751*/       OPC_EmitConvertToTarget, 2,
/*20753*/       OPC_EmitNodeXForm, 3, 5, // LF32
/*20756*/       OPC_MorphNodeTo, TARGET_VAL(SystemZ::ATOMIC_LOAD_OILF64), 0|OPFL_Chain|OPFL_MemRefs,
                    2/*#VTs*/, MVT::i64, MVT::i32, 3/*#Ops*/, 3, 4, 6, 
                // Src: (atomic_load_or:i64 bdaddr20only:i64:$ptr, (imm:i64)<<P:Predicate_imm64lf32>><<X:LF32>>:$src2)<<P:Predicate_atomic_load_or_64>> - Complexity = 17
                // Dst: (ATOMIC_LOAD_OILF64:i64:i32 bdaddr20only:i64:$ptr, (LF32:i64 (imm:i64):$src2))
/*20767*/     /*Scope*/ 27, /*->20795*/
/*20768*/       OPC_CheckPredicate, 41, // Predicate_imm64hf32
/*20770*/       OPC_MoveParent,
/*20771*/       OPC_CheckPredicate, 84, // Predicate_atomic_load_or_64
/*20773*/       OPC_CheckType, MVT::i64,
/*20775*/       OPC_CheckComplexPat, /*CP*/4, /*#*/1, // selectBDAddr20Only:$ptr #3 #4
/*20778*/       OPC_EmitMergeInputChains1_0,
/*20779*/       OPC_EmitConvertToTarget, 2,
/*20781*/       OPC_EmitNodeXForm, 4, 5, // HF32
/*20784*/       OPC_MorphNodeTo, TARGET_VAL(SystemZ::ATOMIC_LOAD_OIHF64), 0|OPFL_Chain|OPFL_MemRefs,
                    2/*#VTs*/, MVT::i64, MVT::i32, 3/*#Ops*/, 3, 4, 6, 
                // Src: (atomic_load_or:i64 bdaddr20only:i64:$ptr, (imm:i64)<<P:Predicate_imm64hf32>><<X:HF32>>:$src2)<<P:Predicate_atomic_load_or_64>> - Complexity = 17
                // Dst: (ATOMIC_LOAD_OIHF64:i64:i32 bdaddr20only:i64:$ptr, (HF32:i64 (imm:i64):$src2))
/*20795*/     /*Scope*/ 25, /*->20821*/
/*20796*/       OPC_MoveParent,
/*20797*/       OPC_CheckPredicate, 83, // Predicate_atomic_load_or_32
/*20799*/       OPC_CheckType, MVT::i32,
/*20801*/       OPC_CheckComplexPat, /*CP*/4, /*#*/1, // selectBDAddr20Only:$ptr #3 #4
/*20804*/       OPC_EmitMergeInputChains1_0,
/*20805*/       OPC_EmitConvertToTarget, 2,
/*20807*/       OPC_EmitNodeXForm, 5, 5, // UIMM32
/*20810*/       OPC_MorphNodeTo, TARGET_VAL(SystemZ::ATOMIC_LOAD_OILF), 0|OPFL_Chain|OPFL_MemRefs,
                    2/*#VTs*/, MVT::i32, MVT::i32, 3/*#Ops*/, 3, 4, 6, 
                // Src: (atomic_load_or:i32 bdaddr20only:i64:$ptr, (imm:i32)<<X:UIMM32>>:$src2)<<P:Predicate_atomic_load_or_32>> - Complexity = 16
                // Dst: (ATOMIC_LOAD_OILF:i32:i32 bdaddr20only:i64:$ptr, (UIMM32:i32 (imm:i32):$src2))
/*20821*/     0, /*End of Scope*/
/*20822*/   /*Scope*/ 19, /*->20842*/
/*20823*/     OPC_CheckPredicate, 83, // Predicate_atomic_load_or_32
/*20825*/     OPC_CheckType, MVT::i32,
/*20827*/     OPC_CheckComplexPat, /*CP*/4, /*#*/1, // selectBDAddr20Only:$ptr #3 #4
/*20830*/     OPC_EmitMergeInputChains1_0,
/*20831*/     OPC_MorphNodeTo, TARGET_VAL(SystemZ::ATOMIC_LOAD_OR), 0|OPFL_Chain|OPFL_MemRefs,
                  2/*#VTs*/, MVT::i32, MVT::i32, 3/*#Ops*/, 3, 4, 2, 
              // Src: (atomic_load_or:i32 bdaddr20only:i64:$ptr, GR32:i32:$src2)<<P:Predicate_atomic_load_or_32>> - Complexity = 13
              // Dst: (ATOMIC_LOAD_OR:i32:i32 bdaddr20only:i64:$ptr, GR32:i32:$src2)
/*20842*/   /*Scope*/ 19, /*->20862*/
/*20843*/     OPC_CheckPredicate, 84, // Predicate_atomic_load_or_64
/*20845*/     OPC_CheckType, MVT::i64,
/*20847*/     OPC_CheckComplexPat, /*CP*/4, /*#*/1, // selectBDAddr20Only:$ptr #3 #4
/*20850*/     OPC_EmitMergeInputChains1_0,
/*20851*/     OPC_MorphNodeTo, TARGET_VAL(SystemZ::ATOMIC_LOAD_OGR), 0|OPFL_Chain|OPFL_MemRefs,
                  2/*#VTs*/, MVT::i64, MVT::i32, 3/*#Ops*/, 3, 4, 2, 
              // Src: (atomic_load_or:i64 bdaddr20only:i64:$ptr, GR64:i64:$src2)<<P:Predicate_atomic_load_or_64>> - Complexity = 13
              // Dst: (ATOMIC_LOAD_OGR:i64:i32 bdaddr20only:i64:$ptr, GR64:i64:$src2)
/*20862*/   0, /*End of Scope*/
/*20863*/ /*SwitchOpcode*/ 10|128,1/*138*/,  TARGET_VAL(ISD::ATOMIC_LOAD_XOR),// ->21005
/*20867*/   OPC_RecordMemRef,
/*20868*/   OPC_RecordNode,   // #0 = 'atomic_load_xor' chained node
/*20869*/   OPC_RecordChild1, // #1 = $ptr
/*20870*/   OPC_CheckChild1Type, MVT::i64,
/*20872*/   OPC_RecordChild2, // #2 = $src2
/*20873*/   OPC_Scope, 89, /*->20964*/ // 3 children in Scope
/*20875*/     OPC_MoveChild, 2,
/*20877*/     OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*20880*/     OPC_Scope, 27, /*->20909*/ // 3 children in Scope
/*20882*/       OPC_CheckPredicate, 40, // Predicate_imm64lf32
/*20884*/       OPC_MoveParent,
/*20885*/       OPC_CheckPredicate, 85, // Predicate_atomic_load_xor_64
/*20887*/       OPC_CheckType, MVT::i64,
/*20889*/       OPC_CheckComplexPat, /*CP*/4, /*#*/1, // selectBDAddr20Only:$ptr #3 #4
/*20892*/       OPC_EmitMergeInputChains1_0,
/*20893*/       OPC_EmitConvertToTarget, 2,
/*20895*/       OPC_EmitNodeXForm, 3, 5, // LF32
/*20898*/       OPC_MorphNodeTo, TARGET_VAL(SystemZ::ATOMIC_LOAD_XILF64), 0|OPFL_Chain|OPFL_MemRefs,
                    2/*#VTs*/, MVT::i64, MVT::i32, 3/*#Ops*/, 3, 4, 6, 
                // Src: (atomic_load_xor:i64 bdaddr20only:i64:$ptr, (imm:i64)<<P:Predicate_imm64lf32>><<X:LF32>>:$src2)<<P:Predicate_atomic_load_xor_64>> - Complexity = 17
                // Dst: (ATOMIC_LOAD_XILF64:i64:i32 bdaddr20only:i64:$ptr, (LF32:i64 (imm:i64):$src2))
/*20909*/     /*Scope*/ 27, /*->20937*/
/*20910*/       OPC_CheckPredicate, 41, // Predicate_imm64hf32
/*20912*/       OPC_MoveParent,
/*20913*/       OPC_CheckPredicate, 85, // Predicate_atomic_load_xor_64
/*20915*/       OPC_CheckType, MVT::i64,
/*20917*/       OPC_CheckComplexPat, /*CP*/4, /*#*/1, // selectBDAddr20Only:$ptr #3 #4
/*20920*/       OPC_EmitMergeInputChains1_0,
/*20921*/       OPC_EmitConvertToTarget, 2,
/*20923*/       OPC_EmitNodeXForm, 4, 5, // HF32
/*20926*/       OPC_MorphNodeTo, TARGET_VAL(SystemZ::ATOMIC_LOAD_XIHF64), 0|OPFL_Chain|OPFL_MemRefs,
                    2/*#VTs*/, MVT::i64, MVT::i32, 3/*#Ops*/, 3, 4, 6, 
                // Src: (atomic_load_xor:i64 bdaddr20only:i64:$ptr, (imm:i64)<<P:Predicate_imm64hf32>><<X:HF32>>:$src2)<<P:Predicate_atomic_load_xor_64>> - Complexity = 17
                // Dst: (ATOMIC_LOAD_XIHF64:i64:i32 bdaddr20only:i64:$ptr, (HF32:i64 (imm:i64):$src2))
/*20937*/     /*Scope*/ 25, /*->20963*/
/*20938*/       OPC_MoveParent,
/*20939*/       OPC_CheckPredicate, 86, // Predicate_atomic_load_xor_32
/*20941*/       OPC_CheckType, MVT::i32,
/*20943*/       OPC_CheckComplexPat, /*CP*/4, /*#*/1, // selectBDAddr20Only:$ptr #3 #4
/*20946*/       OPC_EmitMergeInputChains1_0,
/*20947*/       OPC_EmitConvertToTarget, 2,
/*20949*/       OPC_EmitNodeXForm, 5, 5, // UIMM32
/*20952*/       OPC_MorphNodeTo, TARGET_VAL(SystemZ::ATOMIC_LOAD_XILF), 0|OPFL_Chain|OPFL_MemRefs,
                    2/*#VTs*/, MVT::i32, MVT::i32, 3/*#Ops*/, 3, 4, 6, 
                // Src: (atomic_load_xor:i32 bdaddr20only:i64:$ptr, (imm:i32)<<X:UIMM32>>:$src2)<<P:Predicate_atomic_load_xor_32>> - Complexity = 16
                // Dst: (ATOMIC_LOAD_XILF:i32:i32 bdaddr20only:i64:$ptr, (UIMM32:i32 (imm:i32):$src2))
/*20963*/     0, /*End of Scope*/
/*20964*/   /*Scope*/ 19, /*->20984*/
/*20965*/     OPC_CheckPredicate, 86, // Predicate_atomic_load_xor_32
/*20967*/     OPC_CheckType, MVT::i32,
/*20969*/     OPC_CheckComplexPat, /*CP*/4, /*#*/1, // selectBDAddr20Only:$ptr #3 #4
/*20972*/     OPC_EmitMergeInputChains1_0,
/*20973*/     OPC_MorphNodeTo, TARGET_VAL(SystemZ::ATOMIC_LOAD_XR), 0|OPFL_Chain|OPFL_MemRefs,
                  2/*#VTs*/, MVT::i32, MVT::i32, 3/*#Ops*/, 3, 4, 2, 
              // Src: (atomic_load_xor:i32 bdaddr20only:i64:$ptr, GR32:i32:$src2)<<P:Predicate_atomic_load_xor_32>> - Complexity = 13
              // Dst: (ATOMIC_LOAD_XR:i32:i32 bdaddr20only:i64:$ptr, GR32:i32:$src2)
/*20984*/   /*Scope*/ 19, /*->21004*/
/*20985*/     OPC_CheckPredicate, 85, // Predicate_atomic_load_xor_64
/*20987*/     OPC_CheckType, MVT::i64,
/*20989*/     OPC_CheckComplexPat, /*CP*/4, /*#*/1, // selectBDAddr20Only:$ptr #3 #4
/*20992*/     OPC_EmitMergeInputChains1_0,
/*20993*/     OPC_MorphNodeTo, TARGET_VAL(SystemZ::ATOMIC_LOAD_XGR), 0|OPFL_Chain|OPFL_MemRefs,
                  2/*#VTs*/, MVT::i64, MVT::i32, 3/*#Ops*/, 3, 4, 2, 
              // Src: (atomic_load_xor:i64 bdaddr20only:i64:$ptr, GR64:i64:$src2)<<P:Predicate_atomic_load_xor_64>> - Complexity = 13
              // Dst: (ATOMIC_LOAD_XGR:i64:i32 bdaddr20only:i64:$ptr, GR64:i64:$src2)
/*21004*/   0, /*End of Scope*/
/*21005*/ /*SwitchOpcode*/ 51|128,2/*307*/,  TARGET_VAL(ISD::ATOMIC_LOAD_NAND),// ->21316
/*21009*/   OPC_RecordMemRef,
/*21010*/   OPC_RecordNode,   // #0 = 'atomic_load_nand' chained node
/*21011*/   OPC_RecordChild1, // #1 = $ptr
/*21012*/   OPC_CheckChild1Type, MVT::i64,
/*21014*/   OPC_RecordChild2, // #2 = $src2
/*21015*/   OPC_Scope, 1|128,2/*257*/, /*->21275*/ // 3 children in Scope
/*21018*/     OPC_MoveChild, 2,
/*21020*/     OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*21023*/     OPC_Scope, 27, /*->21052*/ // 9 children in Scope
/*21025*/       OPC_CheckPredicate, 66, // Predicate_imm32ll16c
/*21027*/       OPC_MoveParent,
/*21028*/       OPC_CheckPredicate, 87, // Predicate_atomic_load_nand_32
/*21030*/       OPC_CheckType, MVT::i32,
/*21032*/       OPC_CheckComplexPat, /*CP*/4, /*#*/1, // selectBDAddr20Only:$ptr #3 #4
/*21035*/       OPC_EmitMergeInputChains1_0,
/*21036*/       OPC_EmitConvertToTarget, 2,
/*21038*/       OPC_EmitNodeXForm, 6, 5, // LL16
/*21041*/       OPC_MorphNodeTo, TARGET_VAL(SystemZ::ATOMIC_LOAD_NILLi), 0|OPFL_Chain|OPFL_MemRefs,
                    2/*#VTs*/, MVT::i32, MVT::i32, 3/*#Ops*/, 3, 4, 6, 
                // Src: (atomic_load_nand:i32 bdaddr20only:i64:$ptr, (imm:i32)<<P:Predicate_imm32ll16c>><<X:LL16>>:$src2)<<P:Predicate_atomic_load_nand_32>> - Complexity = 17
                // Dst: (ATOMIC_LOAD_NILLi:i32:i32 bdaddr20only:i64:$ptr, (LL16:i32 (imm:i32):$src2))
/*21052*/     /*Scope*/ 27, /*->21080*/
/*21053*/       OPC_CheckPredicate, 67, // Predicate_imm32lh16c
/*21055*/       OPC_MoveParent,
/*21056*/       OPC_CheckPredicate, 87, // Predicate_atomic_load_nand_32
/*21058*/       OPC_CheckType, MVT::i32,
/*21060*/       OPC_CheckComplexPat, /*CP*/4, /*#*/1, // selectBDAddr20Only:$ptr #3 #4
/*21063*/       OPC_EmitMergeInputChains1_0,
/*21064*/       OPC_EmitConvertToTarget, 2,
/*21066*/       OPC_EmitNodeXForm, 7, 5, // LH16
/*21069*/       OPC_MorphNodeTo, TARGET_VAL(SystemZ::ATOMIC_LOAD_NILHi), 0|OPFL_Chain|OPFL_MemRefs,
                    2/*#VTs*/, MVT::i32, MVT::i32, 3/*#Ops*/, 3, 4, 6, 
                // Src: (atomic_load_nand:i32 bdaddr20only:i64:$ptr, (imm:i32)<<P:Predicate_imm32lh16c>><<X:LH16>>:$src2)<<P:Predicate_atomic_load_nand_32>> - Complexity = 17
                // Dst: (ATOMIC_LOAD_NILHi:i32:i32 bdaddr20only:i64:$ptr, (LH16:i32 (imm:i32):$src2))
/*21080*/     /*Scope*/ 27, /*->21108*/
/*21081*/       OPC_CheckPredicate, 68, // Predicate_imm64ll16c
/*21083*/       OPC_MoveParent,
/*21084*/       OPC_CheckPredicate, 88, // Predicate_atomic_load_nand_64
/*21086*/       OPC_CheckType, MVT::i64,
/*21088*/       OPC_CheckComplexPat, /*CP*/4, /*#*/1, // selectBDAddr20Only:$ptr #3 #4
/*21091*/       OPC_EmitMergeInputChains1_0,
/*21092*/       OPC_EmitConvertToTarget, 2,
/*21094*/       OPC_EmitNodeXForm, 6, 5, // LL16
/*21097*/       OPC_MorphNodeTo, TARGET_VAL(SystemZ::ATOMIC_LOAD_NILL64i), 0|OPFL_Chain|OPFL_MemRefs,
                    2/*#VTs*/, MVT::i64, MVT::i32, 3/*#Ops*/, 3, 4, 6, 
                // Src: (atomic_load_nand:i64 bdaddr20only:i64:$ptr, (imm:i64)<<P:Predicate_imm64ll16c>><<X:LL16>>:$src2)<<P:Predicate_atomic_load_nand_64>> - Complexity = 17
                // Dst: (ATOMIC_LOAD_NILL64i:i64:i32 bdaddr20only:i64:$ptr, (LL16:i64 (imm:i64):$src2))
/*21108*/     /*Scope*/ 27, /*->21136*/
/*21109*/       OPC_CheckPredicate, 69, // Predicate_imm64lh16c
/*21111*/       OPC_MoveParent,
/*21112*/       OPC_CheckPredicate, 88, // Predicate_atomic_load_nand_64
/*21114*/       OPC_CheckType, MVT::i64,
/*21116*/       OPC_CheckComplexPat, /*CP*/4, /*#*/1, // selectBDAddr20Only:$ptr #3 #4
/*21119*/       OPC_EmitMergeInputChains1_0,
/*21120*/       OPC_EmitConvertToTarget, 2,
/*21122*/       OPC_EmitNodeXForm, 7, 5, // LH16
/*21125*/       OPC_MorphNodeTo, TARGET_VAL(SystemZ::ATOMIC_LOAD_NILH64i), 0|OPFL_Chain|OPFL_MemRefs,
                    2/*#VTs*/, MVT::i64, MVT::i32, 3/*#Ops*/, 3, 4, 6, 
                // Src: (atomic_load_nand:i64 bdaddr20only:i64:$ptr, (imm:i64)<<P:Predicate_imm64lh16c>><<X:LH16>>:$src2)<<P:Predicate_atomic_load_nand_64>> - Complexity = 17
                // Dst: (ATOMIC_LOAD_NILH64i:i64:i32 bdaddr20only:i64:$ptr, (LH16:i64 (imm:i64):$src2))
/*21136*/     /*Scope*/ 27, /*->21164*/
/*21137*/       OPC_CheckPredicate, 70, // Predicate_imm64hl16c
/*21139*/       OPC_MoveParent,
/*21140*/       OPC_CheckPredicate, 88, // Predicate_atomic_load_nand_64
/*21142*/       OPC_CheckType, MVT::i64,
/*21144*/       OPC_CheckComplexPat, /*CP*/4, /*#*/1, // selectBDAddr20Only:$ptr #3 #4
/*21147*/       OPC_EmitMergeInputChains1_0,
/*21148*/       OPC_EmitConvertToTarget, 2,
/*21150*/       OPC_EmitNodeXForm, 8, 5, // HL16
/*21153*/       OPC_MorphNodeTo, TARGET_VAL(SystemZ::ATOMIC_LOAD_NIHL64i), 0|OPFL_Chain|OPFL_MemRefs,
                    2/*#VTs*/, MVT::i64, MVT::i32, 3/*#Ops*/, 3, 4, 6, 
                // Src: (atomic_load_nand:i64 bdaddr20only:i64:$ptr, (imm:i64)<<P:Predicate_imm64hl16c>><<X:HL16>>:$src2)<<P:Predicate_atomic_load_nand_64>> - Complexity = 17
                // Dst: (ATOMIC_LOAD_NIHL64i:i64:i32 bdaddr20only:i64:$ptr, (HL16:i64 (imm:i64):$src2))
/*21164*/     /*Scope*/ 27, /*->21192*/
/*21165*/       OPC_CheckPredicate, 71, // Predicate_imm64hh16c
/*21167*/       OPC_MoveParent,
/*21168*/       OPC_CheckPredicate, 88, // Predicate_atomic_load_nand_64
/*21170*/       OPC_CheckType, MVT::i64,
/*21172*/       OPC_CheckComplexPat, /*CP*/4, /*#*/1, // selectBDAddr20Only:$ptr #3 #4
/*21175*/       OPC_EmitMergeInputChains1_0,
/*21176*/       OPC_EmitConvertToTarget, 2,
/*21178*/       OPC_EmitNodeXForm, 9, 5, // HH16
/*21181*/       OPC_MorphNodeTo, TARGET_VAL(SystemZ::ATOMIC_LOAD_NIHH64i), 0|OPFL_Chain|OPFL_MemRefs,
                    2/*#VTs*/, MVT::i64, MVT::i32, 3/*#Ops*/, 3, 4, 6, 
                // Src: (atomic_load_nand:i64 bdaddr20only:i64:$ptr, (imm:i64)<<P:Predicate_imm64hh16c>><<X:HH16>>:$src2)<<P:Predicate_atomic_load_nand_64>> - Complexity = 17
                // Dst: (ATOMIC_LOAD_NIHH64i:i64:i32 bdaddr20only:i64:$ptr, (HH16:i64 (imm:i64):$src2))
/*21192*/     /*Scope*/ 27, /*->21220*/
/*21193*/       OPC_CheckPredicate, 72, // Predicate_imm64lf32c
/*21195*/       OPC_MoveParent,
/*21196*/       OPC_CheckPredicate, 88, // Predicate_atomic_load_nand_64
/*21198*/       OPC_CheckType, MVT::i64,
/*21200*/       OPC_CheckComplexPat, /*CP*/4, /*#*/1, // selectBDAddr20Only:$ptr #3 #4
/*21203*/       OPC_EmitMergeInputChains1_0,
/*21204*/       OPC_EmitConvertToTarget, 2,
/*21206*/       OPC_EmitNodeXForm, 3, 5, // LF32
/*21209*/       OPC_MorphNodeTo, TARGET_VAL(SystemZ::ATOMIC_LOAD_NILF64i), 0|OPFL_Chain|OPFL_MemRefs,
                    2/*#VTs*/, MVT::i64, MVT::i32, 3/*#Ops*/, 3, 4, 6, 
                // Src: (atomic_load_nand:i64 bdaddr20only:i64:$ptr, (imm:i64)<<P:Predicate_imm64lf32c>><<X:LF32>>:$src2)<<P:Predicate_atomic_load_nand_64>> - Complexity = 17
                // Dst: (ATOMIC_LOAD_NILF64i:i64:i32 bdaddr20only:i64:$ptr, (LF32:i64 (imm:i64):$src2))
/*21220*/     /*Scope*/ 27, /*->21248*/
/*21221*/       OPC_CheckPredicate, 73, // Predicate_imm64hf32c
/*21223*/       OPC_MoveParent,
/*21224*/       OPC_CheckPredicate, 88, // Predicate_atomic_load_nand_64
/*21226*/       OPC_CheckType, MVT::i64,
/*21228*/       OPC_CheckComplexPat, /*CP*/4, /*#*/1, // selectBDAddr20Only:$ptr #3 #4
/*21231*/       OPC_EmitMergeInputChains1_0,
/*21232*/       OPC_EmitConvertToTarget, 2,
/*21234*/       OPC_EmitNodeXForm, 4, 5, // HF32
/*21237*/       OPC_MorphNodeTo, TARGET_VAL(SystemZ::ATOMIC_LOAD_NIHF64i), 0|OPFL_Chain|OPFL_MemRefs,
                    2/*#VTs*/, MVT::i64, MVT::i32, 3/*#Ops*/, 3, 4, 6, 
                // Src: (atomic_load_nand:i64 bdaddr20only:i64:$ptr, (imm:i64)<<P:Predicate_imm64hf32c>><<X:HF32>>:$src2)<<P:Predicate_atomic_load_nand_64>> - Complexity = 17
                // Dst: (ATOMIC_LOAD_NIHF64i:i64:i32 bdaddr20only:i64:$ptr, (HF32:i64 (imm:i64):$src2))
/*21248*/     /*Scope*/ 25, /*->21274*/
/*21249*/       OPC_MoveParent,
/*21250*/       OPC_CheckPredicate, 87, // Predicate_atomic_load_nand_32
/*21252*/       OPC_CheckType, MVT::i32,
/*21254*/       OPC_CheckComplexPat, /*CP*/4, /*#*/1, // selectBDAddr20Only:$ptr #3 #4
/*21257*/       OPC_EmitMergeInputChains1_0,
/*21258*/       OPC_EmitConvertToTarget, 2,
/*21260*/       OPC_EmitNodeXForm, 5, 5, // UIMM32
/*21263*/       OPC_MorphNodeTo, TARGET_VAL(SystemZ::ATOMIC_LOAD_NILFi), 0|OPFL_Chain|OPFL_MemRefs,
                    2/*#VTs*/, MVT::i32, MVT::i32, 3/*#Ops*/, 3, 4, 6, 
                // Src: (atomic_load_nand:i32 bdaddr20only:i64:$ptr, (imm:i32)<<X:UIMM32>>:$src2)<<P:Predicate_atomic_load_nand_32>> - Complexity = 16
                // Dst: (ATOMIC_LOAD_NILFi:i32:i32 bdaddr20only:i64:$ptr, (UIMM32:i32 (imm:i32):$src2))
/*21274*/     0, /*End of Scope*/
/*21275*/   /*Scope*/ 19, /*->21295*/
/*21276*/     OPC_CheckPredicate, 87, // Predicate_atomic_load_nand_32
/*21278*/     OPC_CheckType, MVT::i32,
/*21280*/     OPC_CheckComplexPat, /*CP*/4, /*#*/1, // selectBDAddr20Only:$ptr #3 #4
/*21283*/     OPC_EmitMergeInputChains1_0,
/*21284*/     OPC_MorphNodeTo, TARGET_VAL(SystemZ::ATOMIC_LOAD_NRi), 0|OPFL_Chain|OPFL_MemRefs,
                  2/*#VTs*/, MVT::i32, MVT::i32, 3/*#Ops*/, 3, 4, 2, 
              // Src: (atomic_load_nand:i32 bdaddr20only:i64:$ptr, GR32:i32:$src2)<<P:Predicate_atomic_load_nand_32>> - Complexity = 13
              // Dst: (ATOMIC_LOAD_NRi:i32:i32 bdaddr20only:i64:$ptr, GR32:i32:$src2)
/*21295*/   /*Scope*/ 19, /*->21315*/
/*21296*/     OPC_CheckPredicate, 88, // Predicate_atomic_load_nand_64
/*21298*/     OPC_CheckType, MVT::i64,
/*21300*/     OPC_CheckComplexPat, /*CP*/4, /*#*/1, // selectBDAddr20Only:$ptr #3 #4
/*21303*/     OPC_EmitMergeInputChains1_0,
/*21304*/     OPC_MorphNodeTo, TARGET_VAL(SystemZ::ATOMIC_LOAD_NGRi), 0|OPFL_Chain|OPFL_MemRefs,
                  2/*#VTs*/, MVT::i64, MVT::i32, 3/*#Ops*/, 3, 4, 2, 
              // Src: (atomic_load_nand:i64 bdaddr20only:i64:$ptr, GR64:i64:$src2)<<P:Predicate_atomic_load_nand_64>> - Complexity = 13
              // Dst: (ATOMIC_LOAD_NGRi:i64:i32 bdaddr20only:i64:$ptr, GR64:i64:$src2)
/*21315*/   0, /*End of Scope*/
/*21316*/ /*SwitchOpcode*/ 38,  TARGET_VAL(SystemZISD::ATOMIC_SWAPW),// ->21357
/*21319*/   OPC_RecordMemRef,
/*21320*/   OPC_RecordNode,   // #0 = 'z_atomic_swapw' chained node
/*21321*/   OPC_RecordChild1, // #1 = $ptr
/*21322*/   OPC_CheckChild1Type, MVT::i64,
/*21324*/   OPC_RecordChild2, // #2 = $src2
/*21325*/   OPC_RecordChild3, // #3 = $bitshift
/*21326*/   OPC_RecordChild4, // #4 = $negbitshift
/*21327*/   OPC_RecordChild5, // #5 = $bitsize
/*21328*/   OPC_MoveChild, 5,
/*21330*/   OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*21333*/   OPC_MoveParent,
/*21334*/   OPC_CheckComplexPat, /*CP*/4, /*#*/1, // selectBDAddr20Only:$ptr #6 #7
/*21337*/   OPC_EmitMergeInputChains1_0,
/*21338*/   OPC_EmitConvertToTarget, 5,
/*21340*/   OPC_EmitNodeXForm, 5, 8, // UIMM32
/*21343*/   OPC_MorphNodeTo, TARGET_VAL(SystemZ::ATOMIC_SWAPW), 0|OPFL_Chain|OPFL_MemRefs,
                2/*#VTs*/, MVT::i32, MVT::i32, 6/*#Ops*/, 6, 7, 2, 3, 4, 9, 
            // Src: (z_atomic_swapw:i32 bdaddr20only:i64:$ptr, GR32:i32:$src2, ADDR32:i32:$bitshift, ADDR32:i32:$negbitshift, (imm:i32)<<X:UIMM32>>:$bitsize) - Complexity = 15
            // Dst: (ATOMIC_SWAPW:i32:i32 bdaddr20only:i64:$ptr, GR32:i32:$src2, ADDR32:i32:$bitshift, ADDR32:i32:$negbitshift, (UIMM32:i32 (imm:i32):$bitsize))
/*21357*/ /*SwitchOpcode*/ 38,  TARGET_VAL(SystemZISD::ATOMIC_LOADW_SUB),// ->21398
/*21360*/   OPC_RecordMemRef,
/*21361*/   OPC_RecordNode,   // #0 = 'z_atomic_loadw_sub' chained node
/*21362*/   OPC_RecordChild1, // #1 = $ptr
/*21363*/   OPC_CheckChild1Type, MVT::i64,
/*21365*/   OPC_RecordChild2, // #2 = $src2
/*21366*/   OPC_RecordChild3, // #3 = $bitshift
/*21367*/   OPC_RecordChild4, // #4 = $negbitshift
/*21368*/   OPC_RecordChild5, // #5 = $bitsize
/*21369*/   OPC_MoveChild, 5,
/*21371*/   OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*21374*/   OPC_MoveParent,
/*21375*/   OPC_CheckComplexPat, /*CP*/4, /*#*/1, // selectBDAddr20Only:$ptr #6 #7
/*21378*/   OPC_EmitMergeInputChains1_0,
/*21379*/   OPC_EmitConvertToTarget, 5,
/*21381*/   OPC_EmitNodeXForm, 5, 8, // UIMM32
/*21384*/   OPC_MorphNodeTo, TARGET_VAL(SystemZ::ATOMIC_LOADW_SR), 0|OPFL_Chain|OPFL_MemRefs,
                2/*#VTs*/, MVT::i32, MVT::i32, 6/*#Ops*/, 6, 7, 2, 3, 4, 9, 
            // Src: (z_atomic_loadw_sub:i32 bdaddr20only:i64:$ptr, GR32:i32:$src2, ADDR32:i32:$bitshift, ADDR32:i32:$negbitshift, (imm:i32)<<X:UIMM32>>:$bitsize) - Complexity = 15
            // Dst: (ATOMIC_LOADW_SR:i32:i32 bdaddr20only:i64:$ptr, GR32:i32:$src2, ADDR32:i32:$bitshift, ADDR32:i32:$negbitshift, (UIMM32:i32 (imm:i32):$bitsize))
/*21398*/ /*SwitchOpcode*/ 38,  TARGET_VAL(SystemZISD::ATOMIC_LOADW_MIN),// ->21439
/*21401*/   OPC_RecordMemRef,
/*21402*/   OPC_RecordNode,   // #0 = 'z_atomic_loadw_min' chained node
/*21403*/   OPC_RecordChild1, // #1 = $ptr
/*21404*/   OPC_CheckChild1Type, MVT::i64,
/*21406*/   OPC_RecordChild2, // #2 = $src2
/*21407*/   OPC_RecordChild3, // #3 = $bitshift
/*21408*/   OPC_RecordChild4, // #4 = $negbitshift
/*21409*/   OPC_RecordChild5, // #5 = $bitsize
/*21410*/   OPC_MoveChild, 5,
/*21412*/   OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*21415*/   OPC_MoveParent,
/*21416*/   OPC_CheckComplexPat, /*CP*/4, /*#*/1, // selectBDAddr20Only:$ptr #6 #7
/*21419*/   OPC_EmitMergeInputChains1_0,
/*21420*/   OPC_EmitConvertToTarget, 5,
/*21422*/   OPC_EmitNodeXForm, 5, 8, // UIMM32
/*21425*/   OPC_MorphNodeTo, TARGET_VAL(SystemZ::ATOMIC_LOADW_MIN), 0|OPFL_Chain|OPFL_MemRefs,
                2/*#VTs*/, MVT::i32, MVT::i32, 6/*#Ops*/, 6, 7, 2, 3, 4, 9, 
            // Src: (z_atomic_loadw_min:i32 bdaddr20only:i64:$ptr, GR32:i32:$src2, ADDR32:i32:$bitshift, ADDR32:i32:$negbitshift, (imm:i32)<<X:UIMM32>>:$bitsize) - Complexity = 15
            // Dst: (ATOMIC_LOADW_MIN:i32:i32 bdaddr20only:i64:$ptr, GR32:i32:$src2, ADDR32:i32:$bitshift, ADDR32:i32:$negbitshift, (UIMM32:i32 (imm:i32):$bitsize))
/*21439*/ /*SwitchOpcode*/ 38,  TARGET_VAL(SystemZISD::ATOMIC_LOADW_MAX),// ->21480
/*21442*/   OPC_RecordMemRef,
/*21443*/   OPC_RecordNode,   // #0 = 'z_atomic_loadw_max' chained node
/*21444*/   OPC_RecordChild1, // #1 = $ptr
/*21445*/   OPC_CheckChild1Type, MVT::i64,
/*21447*/   OPC_RecordChild2, // #2 = $src2
/*21448*/   OPC_RecordChild3, // #3 = $bitshift
/*21449*/   OPC_RecordChild4, // #4 = $negbitshift
/*21450*/   OPC_RecordChild5, // #5 = $bitsize
/*21451*/   OPC_MoveChild, 5,
/*21453*/   OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*21456*/   OPC_MoveParent,
/*21457*/   OPC_CheckComplexPat, /*CP*/4, /*#*/1, // selectBDAddr20Only:$ptr #6 #7
/*21460*/   OPC_EmitMergeInputChains1_0,
/*21461*/   OPC_EmitConvertToTarget, 5,
/*21463*/   OPC_EmitNodeXForm, 5, 8, // UIMM32
/*21466*/   OPC_MorphNodeTo, TARGET_VAL(SystemZ::ATOMIC_LOADW_MAX), 0|OPFL_Chain|OPFL_MemRefs,
                2/*#VTs*/, MVT::i32, MVT::i32, 6/*#Ops*/, 6, 7, 2, 3, 4, 9, 
            // Src: (z_atomic_loadw_max:i32 bdaddr20only:i64:$ptr, GR32:i32:$src2, ADDR32:i32:$bitshift, ADDR32:i32:$negbitshift, (imm:i32)<<X:UIMM32>>:$bitsize) - Complexity = 15
            // Dst: (ATOMIC_LOADW_MAX:i32:i32 bdaddr20only:i64:$ptr, GR32:i32:$src2, ADDR32:i32:$bitshift, ADDR32:i32:$negbitshift, (UIMM32:i32 (imm:i32):$bitsize))
/*21480*/ /*SwitchOpcode*/ 38,  TARGET_VAL(SystemZISD::ATOMIC_LOADW_UMIN),// ->21521
/*21483*/   OPC_RecordMemRef,
/*21484*/   OPC_RecordNode,   // #0 = 'z_atomic_loadw_umin' chained node
/*21485*/   OPC_RecordChild1, // #1 = $ptr
/*21486*/   OPC_CheckChild1Type, MVT::i64,
/*21488*/   OPC_RecordChild2, // #2 = $src2
/*21489*/   OPC_RecordChild3, // #3 = $bitshift
/*21490*/   OPC_RecordChild4, // #4 = $negbitshift
/*21491*/   OPC_RecordChild5, // #5 = $bitsize
/*21492*/   OPC_MoveChild, 5,
/*21494*/   OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*21497*/   OPC_MoveParent,
/*21498*/   OPC_CheckComplexPat, /*CP*/4, /*#*/1, // selectBDAddr20Only:$ptr #6 #7
/*21501*/   OPC_EmitMergeInputChains1_0,
/*21502*/   OPC_EmitConvertToTarget, 5,
/*21504*/   OPC_EmitNodeXForm, 5, 8, // UIMM32
/*21507*/   OPC_MorphNodeTo, TARGET_VAL(SystemZ::ATOMIC_LOADW_UMIN), 0|OPFL_Chain|OPFL_MemRefs,
                2/*#VTs*/, MVT::i32, MVT::i32, 6/*#Ops*/, 6, 7, 2, 3, 4, 9, 
            // Src: (z_atomic_loadw_umin:i32 bdaddr20only:i64:$ptr, GR32:i32:$src2, ADDR32:i32:$bitshift, ADDR32:i32:$negbitshift, (imm:i32)<<X:UIMM32>>:$bitsize) - Complexity = 15
            // Dst: (ATOMIC_LOADW_UMIN:i32:i32 bdaddr20only:i64:$ptr, GR32:i32:$src2, ADDR32:i32:$bitshift, ADDR32:i32:$negbitshift, (UIMM32:i32 (imm:i32):$bitsize))
/*21521*/ /*SwitchOpcode*/ 38,  TARGET_VAL(SystemZISD::ATOMIC_LOADW_UMAX),// ->21562
/*21524*/   OPC_RecordMemRef,
/*21525*/   OPC_RecordNode,   // #0 = 'z_atomic_loadw_umax' chained node
/*21526*/   OPC_RecordChild1, // #1 = $ptr
/*21527*/   OPC_CheckChild1Type, MVT::i64,
/*21529*/   OPC_RecordChild2, // #2 = $src2
/*21530*/   OPC_RecordChild3, // #3 = $bitshift
/*21531*/   OPC_RecordChild4, // #4 = $negbitshift
/*21532*/   OPC_RecordChild5, // #5 = $bitsize
/*21533*/   OPC_MoveChild, 5,
/*21535*/   OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*21538*/   OPC_MoveParent,
/*21539*/   OPC_CheckComplexPat, /*CP*/4, /*#*/1, // selectBDAddr20Only:$ptr #6 #7
/*21542*/   OPC_EmitMergeInputChains1_0,
/*21543*/   OPC_EmitConvertToTarget, 5,
/*21545*/   OPC_EmitNodeXForm, 5, 8, // UIMM32
/*21548*/   OPC_MorphNodeTo, TARGET_VAL(SystemZ::ATOMIC_LOADW_UMAX), 0|OPFL_Chain|OPFL_MemRefs,
                2/*#VTs*/, MVT::i32, MVT::i32, 6/*#Ops*/, 6, 7, 2, 3, 4, 9, 
            // Src: (z_atomic_loadw_umax:i32 bdaddr20only:i64:$ptr, GR32:i32:$src2, ADDR32:i32:$bitshift, ADDR32:i32:$negbitshift, (imm:i32)<<X:UIMM32>>:$bitsize) - Complexity = 15
            // Dst: (ATOMIC_LOADW_UMAX:i32:i32 bdaddr20only:i64:$ptr, GR32:i32:$src2, ADDR32:i32:$bitshift, ADDR32:i32:$negbitshift, (UIMM32:i32 (imm:i32):$bitsize))
/*21562*/ /*SwitchOpcode*/ 40,  TARGET_VAL(SystemZISD::ATOMIC_CMP_SWAPW),// ->21605
/*21565*/   OPC_RecordMemRef,
/*21566*/   OPC_RecordNode,   // #0 = 'z_atomic_cmp_swapw' chained node
/*21567*/   OPC_RecordChild1, // #1 = $addr
/*21568*/   OPC_CheckChild1Type, MVT::i64,
/*21570*/   OPC_RecordChild2, // #2 = $cmp
/*21571*/   OPC_RecordChild3, // #3 = $swap
/*21572*/   OPC_RecordChild4, // #4 = $bitshift
/*21573*/   OPC_RecordChild5, // #5 = $negbitshift
/*21574*/   OPC_RecordChild6, // #6 = $bitsize
/*21575*/   OPC_MoveChild, 6,
/*21577*/   OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*21580*/   OPC_MoveParent,
/*21581*/   OPC_CheckComplexPat, /*CP*/4, /*#*/1, // selectBDAddr20Only:$addr #7 #8
/*21584*/   OPC_EmitMergeInputChains1_0,
/*21585*/   OPC_EmitConvertToTarget, 6,
/*21587*/   OPC_EmitNodeXForm, 5, 9, // UIMM32
/*21590*/   OPC_MorphNodeTo, TARGET_VAL(SystemZ::ATOMIC_CMP_SWAPW), 0|OPFL_Chain|OPFL_MemRefs,
                2/*#VTs*/, MVT::i32, MVT::i32, 7/*#Ops*/, 7, 8, 2, 3, 4, 5, 10, 
            // Src: (z_atomic_cmp_swapw:i32 bdaddr20only:i64:$addr, GR32:i32:$cmp, GR32:i32:$swap, ADDR32:i32:$bitshift, ADDR32:i32:$negbitshift, (imm:i32)<<X:UIMM32>>:$bitsize) - Complexity = 15
            // Dst: (ATOMIC_CMP_SWAPW:i32:i32 bdaddr20only:i64:$addr, GR32:i32:$cmp, GR32:i32:$swap, ADDR32:i32:$bitshift, ADDR32:i32:$negbitshift, (UIMM32:i32 (imm:i32):$bitsize))
/*21605*/ /*SwitchOpcode*/ 69,  TARGET_VAL(ISD::ATOMIC_CMP_SWAP),// ->21677
/*21608*/   OPC_RecordMemRef,
/*21609*/   OPC_RecordNode,   // #0 = 'atomic_cmp_swap' chained node
/*21610*/   OPC_RecordChild1, // #1 = $BD2
/*21611*/   OPC_CheckChild1Type, MVT::i64,
/*21613*/   OPC_RecordChild2, // #2 = $R1src
/*21614*/   OPC_RecordChild3, // #3 = $R3
/*21615*/   OPC_SwitchType /*2 cases */, 38,  MVT::i32,// ->21656
/*21618*/     OPC_CheckPredicate, 89, // Predicate_atomic_cmp_swap_32
/*21620*/     OPC_Scope, 16, /*->21638*/ // 2 children in Scope
/*21622*/       OPC_CheckComplexPat, /*CP*/2, /*#*/1, // selectBDAddr12Pair:$BD2 #4 #5
/*21625*/       OPC_EmitMergeInputChains1_0,
/*21626*/       OPC_MorphNodeTo, TARGET_VAL(SystemZ::CS), 0|OPFL_Chain|OPFL_MemRefs,
                    2/*#VTs*/, MVT::i32, MVT::i32, 4/*#Ops*/, 2, 3, 4, 5, 
                // Src: (atomic_cmp_swap:i32 bdaddr12pair:i64:$BD2, GR32:i32:$R1src, GR32:i32:$R3)<<P:Predicate_atomic_cmp_swap_32>> - Complexity = 13
                // Dst: (CS:i32:i32 GR32:i32:$R1src, GR32:i32:$R3, bdaddr12pair:i64:$BD2)
/*21638*/     /*Scope*/ 16, /*->21655*/
/*21639*/       OPC_CheckComplexPat, /*CP*/3, /*#*/1, // selectBDAddr20Pair:$BD2 #4 #5
/*21642*/       OPC_EmitMergeInputChains1_0,
/*21643*/       OPC_MorphNodeTo, TARGET_VAL(SystemZ::CSY), 0|OPFL_Chain|OPFL_MemRefs,
                    2/*#VTs*/, MVT::i32, MVT::i32, 4/*#Ops*/, 2, 3, 4, 5, 
                // Src: (atomic_cmp_swap:i32 bdaddr20pair:i64:$BD2, GR32:i32:$R1src, GR32:i32:$R3)<<P:Predicate_atomic_cmp_swap_32>> - Complexity = 13
                // Dst: (CSY:i32:i32 GR32:i32:$R1src, GR32:i32:$R3, bdaddr20pair:i64:$BD2)
/*21655*/     0, /*End of Scope*/
/*21656*/   /*SwitchType*/ 18,  MVT::i64,// ->21676
/*21658*/     OPC_CheckPredicate, 90, // Predicate_atomic_cmp_swap_64
/*21660*/     OPC_CheckComplexPat, /*CP*/4, /*#*/1, // selectBDAddr20Only:$BD2 #4 #5
/*21663*/     OPC_EmitMergeInputChains1_0,
/*21664*/     OPC_MorphNodeTo, TARGET_VAL(SystemZ::CSG), 0|OPFL_Chain|OPFL_MemRefs,
                  2/*#VTs*/, MVT::i64, MVT::i32, 4/*#Ops*/, 2, 3, 4, 5, 
              // Src: (atomic_cmp_swap:i64 bdaddr20only:i64:$BD2, GR64:i64:$R1src, GR64:i64:$R3)<<P:Predicate_atomic_cmp_swap_64>> - Complexity = 13
              // Dst: (CSG:i64:i32 GR64:i64:$R1src, GR64:i64:$R3, bdaddr20only:i64:$BD2)
/*21676*/   0, // EndSwitchType
/*21677*/ /*SwitchOpcode*/ 46,  TARGET_VAL(ISD::ATOMIC_SWAP),// ->21726
/*21680*/   OPC_RecordMemRef,
/*21681*/   OPC_RecordNode,   // #0 = 'atomic_swap' chained node
/*21682*/   OPC_RecordChild1, // #1 = $ptr
/*21683*/   OPC_CheckChild1Type, MVT::i64,
/*21685*/   OPC_RecordChild2, // #2 = $src2
/*21686*/   OPC_SwitchType /*2 cases */, 17,  MVT::i32,// ->21706
/*21689*/     OPC_CheckPredicate, 91, // Predicate_atomic_swap_32
/*21691*/     OPC_CheckComplexPat, /*CP*/4, /*#*/1, // selectBDAddr20Only:$ptr #3 #4
/*21694*/     OPC_EmitMergeInputChains1_0,
/*21695*/     OPC_MorphNodeTo, TARGET_VAL(SystemZ::ATOMIC_SWAP_32), 0|OPFL_Chain|OPFL_MemRefs,
                  2/*#VTs*/, MVT::i32, MVT::i32, 3/*#Ops*/, 3, 4, 2, 
              // Src: (atomic_swap:i32 bdaddr20only:i64:$ptr, GR32:i32:$src2)<<P:Predicate_atomic_swap_32>> - Complexity = 13
              // Dst: (ATOMIC_SWAP_32:i32:i32 bdaddr20only:i64:$ptr, GR32:i32:$src2)
/*21706*/   /*SwitchType*/ 17,  MVT::i64,// ->21725
/*21708*/     OPC_CheckPredicate, 92, // Predicate_atomic_swap_64
/*21710*/     OPC_CheckComplexPat, /*CP*/4, /*#*/1, // selectBDAddr20Only:$ptr #3 #4
/*21713*/     OPC_EmitMergeInputChains1_0,
/*21714*/     OPC_MorphNodeTo, TARGET_VAL(SystemZ::ATOMIC_SWAP_64), 0|OPFL_Chain|OPFL_MemRefs,
                  2/*#VTs*/, MVT::i64, MVT::i32, 3/*#Ops*/, 3, 4, 2, 
              // Src: (atomic_swap:i64 bdaddr20only:i64:$ptr, GR64:i64:$src2)<<P:Predicate_atomic_swap_64>> - Complexity = 13
              // Dst: (ATOMIC_SWAP_64:i64:i32 bdaddr20only:i64:$ptr, GR64:i64:$src2)
/*21725*/   0, // EndSwitchType
/*21726*/ /*SwitchOpcode*/ 46,  TARGET_VAL(ISD::ATOMIC_LOAD_SUB),// ->21775
/*21729*/   OPC_RecordMemRef,
/*21730*/   OPC_RecordNode,   // #0 = 'atomic_load_sub' chained node
/*21731*/   OPC_RecordChild1, // #1 = $ptr
/*21732*/   OPC_CheckChild1Type, MVT::i64,
/*21734*/   OPC_RecordChild2, // #2 = $src2
/*21735*/   OPC_SwitchType /*2 cases */, 17,  MVT::i32,// ->21755
/*21738*/     OPC_CheckPredicate, 93, // Predicate_atomic_load_sub_32
/*21740*/     OPC_CheckComplexPat, /*CP*/4, /*#*/1, // selectBDAddr20Only:$ptr #3 #4
/*21743*/     OPC_EmitMergeInputChains1_0,
/*21744*/     OPC_MorphNodeTo, TARGET_VAL(SystemZ::ATOMIC_LOAD_SR), 0|OPFL_Chain|OPFL_MemRefs,
                  2/*#VTs*/, MVT::i32, MVT::i32, 3/*#Ops*/, 3, 4, 2, 
              // Src: (atomic_load_sub:i32 bdaddr20only:i64:$ptr, GR32:i32:$src2)<<P:Predicate_atomic_load_sub_32>> - Complexity = 13
              // Dst: (ATOMIC_LOAD_SR:i32:i32 bdaddr20only:i64:$ptr, GR32:i32:$src2)
/*21755*/   /*SwitchType*/ 17,  MVT::i64,// ->21774
/*21757*/     OPC_CheckPredicate, 94, // Predicate_atomic_load_sub_64
/*21759*/     OPC_CheckComplexPat, /*CP*/4, /*#*/1, // selectBDAddr20Only:$ptr #3 #4
/*21762*/     OPC_EmitMergeInputChains1_0,
/*21763*/     OPC_MorphNodeTo, TARGET_VAL(SystemZ::ATOMIC_LOAD_SGR), 0|OPFL_Chain|OPFL_MemRefs,
                  2/*#VTs*/, MVT::i64, MVT::i32, 3/*#Ops*/, 3, 4, 2, 
              // Src: (atomic_load_sub:i64 bdaddr20only:i64:$ptr, GR64:i64:$src2)<<P:Predicate_atomic_load_sub_64>> - Complexity = 13
              // Dst: (ATOMIC_LOAD_SGR:i64:i32 bdaddr20only:i64:$ptr, GR64:i64:$src2)
/*21774*/   0, // EndSwitchType
/*21775*/ /*SwitchOpcode*/ 46,  TARGET_VAL(ISD::ATOMIC_LOAD_MIN),// ->21824
/*21778*/   OPC_RecordMemRef,
/*21779*/   OPC_RecordNode,   // #0 = 'atomic_load_min' chained node
/*21780*/   OPC_RecordChild1, // #1 = $ptr
/*21781*/   OPC_CheckChild1Type, MVT::i64,
/*21783*/   OPC_RecordChild2, // #2 = $src2
/*21784*/   OPC_SwitchType /*2 cases */, 17,  MVT::i32,// ->21804
/*21787*/     OPC_CheckPredicate, 95, // Predicate_atomic_load_min_32
/*21789*/     OPC_CheckComplexPat, /*CP*/4, /*#*/1, // selectBDAddr20Only:$ptr #3 #4
/*21792*/     OPC_EmitMergeInputChains1_0,
/*21793*/     OPC_MorphNodeTo, TARGET_VAL(SystemZ::ATOMIC_LOAD_MIN_32), 0|OPFL_Chain|OPFL_MemRefs,
                  2/*#VTs*/, MVT::i32, MVT::i32, 3/*#Ops*/, 3, 4, 2, 
              // Src: (atomic_load_min:i32 bdaddr20only:i64:$ptr, GR32:i32:$src2)<<P:Predicate_atomic_load_min_32>> - Complexity = 13
              // Dst: (ATOMIC_LOAD_MIN_32:i32:i32 bdaddr20only:i64:$ptr, GR32:i32:$src2)
/*21804*/   /*SwitchType*/ 17,  MVT::i64,// ->21823
/*21806*/     OPC_CheckPredicate, 96, // Predicate_atomic_load_min_64
/*21808*/     OPC_CheckComplexPat, /*CP*/4, /*#*/1, // selectBDAddr20Only:$ptr #3 #4
/*21811*/     OPC_EmitMergeInputChains1_0,
/*21812*/     OPC_MorphNodeTo, TARGET_VAL(SystemZ::ATOMIC_LOAD_MIN_64), 0|OPFL_Chain|OPFL_MemRefs,
                  2/*#VTs*/, MVT::i64, MVT::i32, 3/*#Ops*/, 3, 4, 2, 
              // Src: (atomic_load_min:i64 bdaddr20only:i64:$ptr, GR64:i64:$src2)<<P:Predicate_atomic_load_min_64>> - Complexity = 13
              // Dst: (ATOMIC_LOAD_MIN_64:i64:i32 bdaddr20only:i64:$ptr, GR64:i64:$src2)
/*21823*/   0, // EndSwitchType
/*21824*/ /*SwitchOpcode*/ 46,  TARGET_VAL(ISD::ATOMIC_LOAD_MAX),// ->21873
/*21827*/   OPC_RecordMemRef,
/*21828*/   OPC_RecordNode,   // #0 = 'atomic_load_max' chained node
/*21829*/   OPC_RecordChild1, // #1 = $ptr
/*21830*/   OPC_CheckChild1Type, MVT::i64,
/*21832*/   OPC_RecordChild2, // #2 = $src2
/*21833*/   OPC_SwitchType /*2 cases */, 17,  MVT::i32,// ->21853
/*21836*/     OPC_CheckPredicate, 97, // Predicate_atomic_load_max_32
/*21838*/     OPC_CheckComplexPat, /*CP*/4, /*#*/1, // selectBDAddr20Only:$ptr #3 #4
/*21841*/     OPC_EmitMergeInputChains1_0,
/*21842*/     OPC_MorphNodeTo, TARGET_VAL(SystemZ::ATOMIC_LOAD_MAX_32), 0|OPFL_Chain|OPFL_MemRefs,
                  2/*#VTs*/, MVT::i32, MVT::i32, 3/*#Ops*/, 3, 4, 2, 
              // Src: (atomic_load_max:i32 bdaddr20only:i64:$ptr, GR32:i32:$src2)<<P:Predicate_atomic_load_max_32>> - Complexity = 13
              // Dst: (ATOMIC_LOAD_MAX_32:i32:i32 bdaddr20only:i64:$ptr, GR32:i32:$src2)
/*21853*/   /*SwitchType*/ 17,  MVT::i64,// ->21872
/*21855*/     OPC_CheckPredicate, 98, // Predicate_atomic_load_max_64
/*21857*/     OPC_CheckComplexPat, /*CP*/4, /*#*/1, // selectBDAddr20Only:$ptr #3 #4
/*21860*/     OPC_EmitMergeInputChains1_0,
/*21861*/     OPC_MorphNodeTo, TARGET_VAL(SystemZ::ATOMIC_LOAD_MAX_64), 0|OPFL_Chain|OPFL_MemRefs,
                  2/*#VTs*/, MVT::i64, MVT::i32, 3/*#Ops*/, 3, 4, 2, 
              // Src: (atomic_load_max:i64 bdaddr20only:i64:$ptr, GR64:i64:$src2)<<P:Predicate_atomic_load_max_64>> - Complexity = 13
              // Dst: (ATOMIC_LOAD_MAX_64:i64:i32 bdaddr20only:i64:$ptr, GR64:i64:$src2)
/*21872*/   0, // EndSwitchType
/*21873*/ /*SwitchOpcode*/ 46,  TARGET_VAL(ISD::ATOMIC_LOAD_UMIN),// ->21922
/*21876*/   OPC_RecordMemRef,
/*21877*/   OPC_RecordNode,   // #0 = 'atomic_load_umin' chained node
/*21878*/   OPC_RecordChild1, // #1 = $ptr
/*21879*/   OPC_CheckChild1Type, MVT::i64,
/*21881*/   OPC_RecordChild2, // #2 = $src2
/*21882*/   OPC_SwitchType /*2 cases */, 17,  MVT::i32,// ->21902
/*21885*/     OPC_CheckPredicate, 99, // Predicate_atomic_load_umin_32
/*21887*/     OPC_CheckComplexPat, /*CP*/4, /*#*/1, // selectBDAddr20Only:$ptr #3 #4
/*21890*/     OPC_EmitMergeInputChains1_0,
/*21891*/     OPC_MorphNodeTo, TARGET_VAL(SystemZ::ATOMIC_LOAD_UMIN_32), 0|OPFL_Chain|OPFL_MemRefs,
                  2/*#VTs*/, MVT::i32, MVT::i32, 3/*#Ops*/, 3, 4, 2, 
              // Src: (atomic_load_umin:i32 bdaddr20only:i64:$ptr, GR32:i32:$src2)<<P:Predicate_atomic_load_umin_32>> - Complexity = 13
              // Dst: (ATOMIC_LOAD_UMIN_32:i32:i32 bdaddr20only:i64:$ptr, GR32:i32:$src2)
/*21902*/   /*SwitchType*/ 17,  MVT::i64,// ->21921
/*21904*/     OPC_CheckPredicate, 100, // Predicate_atomic_load_umin_64
/*21906*/     OPC_CheckComplexPat, /*CP*/4, /*#*/1, // selectBDAddr20Only:$ptr #3 #4
/*21909*/     OPC_EmitMergeInputChains1_0,
/*21910*/     OPC_MorphNodeTo, TARGET_VAL(SystemZ::ATOMIC_LOAD_UMIN_64), 0|OPFL_Chain|OPFL_MemRefs,
                  2/*#VTs*/, MVT::i64, MVT::i32, 3/*#Ops*/, 3, 4, 2, 
              // Src: (atomic_load_umin:i64 bdaddr20only:i64:$ptr, GR64:i64:$src2)<<P:Predicate_atomic_load_umin_64>> - Complexity = 13
              // Dst: (ATOMIC_LOAD_UMIN_64:i64:i32 bdaddr20only:i64:$ptr, GR64:i64:$src2)
/*21921*/   0, // EndSwitchType
/*21922*/ /*SwitchOpcode*/ 46,  TARGET_VAL(ISD::ATOMIC_LOAD_UMAX),// ->21971
/*21925*/   OPC_RecordMemRef,
/*21926*/   OPC_RecordNode,   // #0 = 'atomic_load_umax' chained node
/*21927*/   OPC_RecordChild1, // #1 = $ptr
/*21928*/   OPC_CheckChild1Type, MVT::i64,
/*21930*/   OPC_RecordChild2, // #2 = $src2
/*21931*/   OPC_SwitchType /*2 cases */, 17,  MVT::i32,// ->21951
/*21934*/     OPC_CheckPredicate, 101, // Predicate_atomic_load_umax_32
/*21936*/     OPC_CheckComplexPat, /*CP*/4, /*#*/1, // selectBDAddr20Only:$ptr #3 #4
/*21939*/     OPC_EmitMergeInputChains1_0,
/*21940*/     OPC_MorphNodeTo, TARGET_VAL(SystemZ::ATOMIC_LOAD_UMAX_32), 0|OPFL_Chain|OPFL_MemRefs,
                  2/*#VTs*/, MVT::i32, MVT::i32, 3/*#Ops*/, 3, 4, 2, 
              // Src: (atomic_load_umax:i32 bdaddr20only:i64:$ptr, GR32:i32:$src2)<<P:Predicate_atomic_load_umax_32>> - Complexity = 13
              // Dst: (ATOMIC_LOAD_UMAX_32:i32:i32 bdaddr20only:i64:$ptr, GR32:i32:$src2)
/*21951*/   /*SwitchType*/ 17,  MVT::i64,// ->21970
/*21953*/     OPC_CheckPredicate, 102, // Predicate_atomic_load_umax_64
/*21955*/     OPC_CheckComplexPat, /*CP*/4, /*#*/1, // selectBDAddr20Only:$ptr #3 #4
/*21958*/     OPC_EmitMergeInputChains1_0,
/*21959*/     OPC_MorphNodeTo, TARGET_VAL(SystemZ::ATOMIC_LOAD_UMAX_64), 0|OPFL_Chain|OPFL_MemRefs,
                  2/*#VTs*/, MVT::i64, MVT::i32, 3/*#Ops*/, 3, 4, 2, 
              // Src: (atomic_load_umax:i64 bdaddr20only:i64:$ptr, GR64:i64:$src2)<<P:Predicate_atomic_load_umax_64>> - Complexity = 13
              // Dst: (ATOMIC_LOAD_UMAX_64:i64:i32 bdaddr20only:i64:$ptr, GR64:i64:$src2)
/*21970*/   0, // EndSwitchType
/*21971*/ /*SwitchOpcode*/ 47,  TARGET_VAL(ISD::FrameIndex),// ->22021
/*21974*/   OPC_RecordNode,   // #0 = $src
/*21975*/   OPC_CheckType, MVT::i64,
/*21977*/   OPC_Scope, 13, /*->21992*/ // 3 children in Scope
/*21979*/     OPC_CheckComplexPat, /*CP*/13, /*#*/0, // selectDynAlloc12Only:$src #1 #2 #3
/*21982*/     OPC_MorphNodeTo, TARGET_VAL(SystemZ::ADJDYNALLOC), 0,
                  1/*#VTs*/, MVT::i64, 3/*#Ops*/, 1, 2, 3, 
              // Src: dynalloc12only:i64:$src - Complexity = 12
              // Dst: (ADJDYNALLOC:i64 dynalloc12only:i64:$src)
/*21992*/   /*Scope*/ 13, /*->22006*/
/*21993*/     OPC_CheckComplexPat, /*CP*/14, /*#*/0, // selectLAAddr12Pair:$XBD2 #1 #2 #3
/*21996*/     OPC_MorphNodeTo, TARGET_VAL(SystemZ::LA), 0,
                  1/*#VTs*/, MVT::i64, 3/*#Ops*/, 1, 2, 3, 
              // Src: laaddr12pair:i64:$XBD2 - Complexity = 12
              // Dst: (LA:i64 laaddr12pair:i64:$XBD2)
/*22006*/   /*Scope*/ 13, /*->22020*/
/*22007*/     OPC_CheckComplexPat, /*CP*/15, /*#*/0, // selectLAAddr20Pair:$XBD2 #1 #2 #3
/*22010*/     OPC_MorphNodeTo, TARGET_VAL(SystemZ::LAY), 0,
                  1/*#VTs*/, MVT::i64, 3/*#Ops*/, 1, 2, 3, 
              // Src: laaddr20pair:i64:$XBD2 - Complexity = 12
              // Dst: (LAY:i64 laaddr20pair:i64:$XBD2)
/*22020*/   0, /*End of Scope*/
/*22021*/ /*SwitchOpcode*/ 47,  TARGET_VAL(SystemZISD::ADJDYNALLOC),// ->22071
/*22024*/   OPC_RecordNode,   // #0 = $src
/*22025*/   OPC_CheckType, MVT::i64,
/*22027*/   OPC_Scope, 13, /*->22042*/ // 3 children in Scope
/*22029*/     OPC_CheckComplexPat, /*CP*/13, /*#*/0, // selectDynAlloc12Only:$src #1 #2 #3
/*22032*/     OPC_MorphNodeTo, TARGET_VAL(SystemZ::ADJDYNALLOC), 0,
                  1/*#VTs*/, MVT::i64, 3/*#Ops*/, 1, 2, 3, 
              // Src: dynalloc12only:i64:$src - Complexity = 12
              // Dst: (ADJDYNALLOC:i64 dynalloc12only:i64:$src)
/*22042*/   /*Scope*/ 13, /*->22056*/
/*22043*/     OPC_CheckComplexPat, /*CP*/14, /*#*/0, // selectLAAddr12Pair:$XBD2 #1 #2 #3
/*22046*/     OPC_MorphNodeTo, TARGET_VAL(SystemZ::LA), 0,
                  1/*#VTs*/, MVT::i64, 3/*#Ops*/, 1, 2, 3, 
              // Src: laaddr12pair:i64:$XBD2 - Complexity = 12
              // Dst: (LA:i64 laaddr12pair:i64:$XBD2)
/*22056*/   /*Scope*/ 13, /*->22070*/
/*22057*/     OPC_CheckComplexPat, /*CP*/15, /*#*/0, // selectLAAddr20Pair:$XBD2 #1 #2 #3
/*22060*/     OPC_MorphNodeTo, TARGET_VAL(SystemZ::LAY), 0,
                  1/*#VTs*/, MVT::i64, 3/*#Ops*/, 1, 2, 3, 
              // Src: laaddr20pair:i64:$XBD2 - Complexity = 12
              // Dst: (LAY:i64 laaddr20pair:i64:$XBD2)
/*22070*/   0, /*End of Scope*/
/*22071*/ /*SwitchOpcode*/ 36,  TARGET_VAL(ISD::SHL),// ->22110
/*22074*/   OPC_RecordChild0, // #0 = $R1src
/*22075*/   OPC_RecordChild1, // #1 = $BD2
/*22076*/   OPC_CheckChild1Type, MVT::i32,
/*22078*/   OPC_SwitchType /*2 cases */, 13,  MVT::i32,// ->22094
/*22081*/     OPC_CheckComplexPat, /*CP*/11, /*#*/1, // selectBDAddr12Only:$BD2 #2 #3
/*22084*/     OPC_MorphNodeTo, TARGET_VAL(SystemZ::SLL), 0,
                  1/*#VTs*/, MVT::i32, 3/*#Ops*/, 0, 2, 3, 
              // Src: (shl:i32 GR32:i32:$R1src, shift12only:i32:$BD2) - Complexity = 12
              // Dst: (SLL:i32 GR32:i32:$R1src, shift12only:i32:$BD2)
/*22094*/   /*SwitchType*/ 13,  MVT::i64,// ->22109
/*22096*/     OPC_CheckComplexPat, /*CP*/12, /*#*/1, // selectBDAddr20Only:$BD2 #2 #3
/*22099*/     OPC_MorphNodeTo, TARGET_VAL(SystemZ::SLLG), 0,
                  1/*#VTs*/, MVT::i64, 3/*#Ops*/, 0, 2, 3, 
              // Src: (shl:i64 GR64:i64:$R3, shift20only:i32:$BD2) - Complexity = 12
              // Dst: (SLLG:i64 GR64:i64:$R3, shift20only:i32:$BD2)
/*22109*/   0, // EndSwitchType
/*22110*/ /*SwitchOpcode*/ 36,  TARGET_VAL(ISD::SRL),// ->22149
/*22113*/   OPC_RecordChild0, // #0 = $R1src
/*22114*/   OPC_RecordChild1, // #1 = $BD2
/*22115*/   OPC_CheckChild1Type, MVT::i32,
/*22117*/   OPC_SwitchType /*2 cases */, 13,  MVT::i32,// ->22133
/*22120*/     OPC_CheckComplexPat, /*CP*/11, /*#*/1, // selectBDAddr12Only:$BD2 #2 #3
/*22123*/     OPC_MorphNodeTo, TARGET_VAL(SystemZ::SRL), 0,
                  1/*#VTs*/, MVT::i32, 3/*#Ops*/, 0, 2, 3, 
              // Src: (srl:i32 GR32:i32:$R1src, shift12only:i32:$BD2) - Complexity = 12
              // Dst: (SRL:i32 GR32:i32:$R1src, shift12only:i32:$BD2)
/*22133*/   /*SwitchType*/ 13,  MVT::i64,// ->22148
/*22135*/     OPC_CheckComplexPat, /*CP*/12, /*#*/1, // selectBDAddr20Only:$BD2 #2 #3
/*22138*/     OPC_MorphNodeTo, TARGET_VAL(SystemZ::SRLG), 0,
                  1/*#VTs*/, MVT::i64, 3/*#Ops*/, 0, 2, 3, 
              // Src: (srl:i64 GR64:i64:$R3, shift20only:i32:$BD2) - Complexity = 12
              // Dst: (SRLG:i64 GR64:i64:$R3, shift20only:i32:$BD2)
/*22148*/   0, // EndSwitchType
/*22149*/ /*SwitchOpcode*/ 36,  TARGET_VAL(ISD::ROTL),// ->22188
/*22152*/   OPC_RecordChild0, // #0 = $R3
/*22153*/   OPC_RecordChild1, // #1 = $BD2
/*22154*/   OPC_CheckChild1Type, MVT::i32,
/*22156*/   OPC_SwitchType /*2 cases */, 13,  MVT::i32,// ->22172
/*22159*/     OPC_CheckComplexPat, /*CP*/12, /*#*/1, // selectBDAddr20Only:$BD2 #2 #3
/*22162*/     OPC_MorphNodeTo, TARGET_VAL(SystemZ::RLL), 0,
                  1/*#VTs*/, MVT::i32, 3/*#Ops*/, 0, 2, 3, 
              // Src: (rotl:i32 GR32:i32:$R3, shift20only:i32:$BD2) - Complexity = 12
              // Dst: (RLL:i32 GR32:i32:$R3, shift20only:i32:$BD2)
/*22172*/   /*SwitchType*/ 13,  MVT::i64,// ->22187
/*22174*/     OPC_CheckComplexPat, /*CP*/12, /*#*/1, // selectBDAddr20Only:$BD2 #2 #3
/*22177*/     OPC_MorphNodeTo, TARGET_VAL(SystemZ::RLLG), 0,
                  1/*#VTs*/, MVT::i64, 3/*#Ops*/, 0, 2, 3, 
              // Src: (rotl:i64 GR64:i64:$R3, shift20only:i32:$BD2) - Complexity = 12
              // Dst: (RLLG:i64 GR64:i64:$R3, shift20only:i32:$BD2)
/*22187*/   0, // EndSwitchType
/*22188*/ /*SwitchOpcode*/ 41,  TARGET_VAL(SystemZISD::BR_CCMASK),// ->22232
/*22191*/   OPC_RecordNode,   // #0 = 'z_br_ccmask' chained node
/*22192*/   OPC_CaptureGlueInput,
/*22193*/   OPC_RecordChild1, // #1 = $valid
/*22194*/   OPC_MoveChild, 1,
/*22196*/   OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*22199*/   OPC_CheckPredicate, 52, // Predicate_cond4
/*22201*/   OPC_MoveParent,
/*22202*/   OPC_RecordChild2, // #2 = $R1
/*22203*/   OPC_MoveChild, 2,
/*22205*/   OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*22208*/   OPC_CheckPredicate, 52, // Predicate_cond4
/*22210*/   OPC_MoveParent,
/*22211*/   OPC_RecordChild3, // #3 = $I2
/*22212*/   OPC_MoveChild, 3,
/*22214*/   OPC_CheckOpcode, TARGET_VAL(ISD::BasicBlock),
/*22217*/   OPC_MoveParent,
/*22218*/   OPC_EmitMergeInputChains1_0,
/*22219*/   OPC_EmitConvertToTarget, 1,
/*22221*/   OPC_EmitConvertToTarget, 2,
/*22223*/   OPC_MorphNodeTo, TARGET_VAL(SystemZ::BRC), 0|OPFL_Chain|OPFL_GlueInput,
                0/*#VTs*/, 3/*#Ops*/, 4, 5, 3, 
            // Src: (z_br_ccmask (imm:i8)<<P:Predicate_cond4>>:$valid, (imm:i8)<<P:Predicate_cond4>>:$R1, (bb:Other):$I2) - Complexity = 11
            // Dst: (BRC (imm:i8):$valid, (imm:i8):$R1, (bb:Other):$I2)
/*22232*/ /*SwitchOpcode*/ 25,  TARGET_VAL(ISD::CALLSEQ_END),// ->22260
/*22235*/   OPC_RecordNode,   // #0 = 'callseq_end' chained node
/*22236*/   OPC_CaptureGlueInput,
/*22237*/   OPC_RecordChild1, // #1 = $amt1
/*22238*/   OPC_MoveChild, 1,
/*22240*/   OPC_CheckOpcode, TARGET_VAL(ISD::TargetConstant),
/*22243*/   OPC_MoveParent,
/*22244*/   OPC_RecordChild2, // #2 = $amt2
/*22245*/   OPC_MoveChild, 2,
/*22247*/   OPC_CheckOpcode, TARGET_VAL(ISD::TargetConstant),
/*22250*/   OPC_MoveParent,
/*22251*/   OPC_EmitMergeInputChains1_0,
/*22252*/   OPC_MorphNodeTo, TARGET_VAL(SystemZ::ADJCALLSTACKUP), 0|OPFL_Chain|OPFL_GlueInput|OPFL_GlueOutput,
                0/*#VTs*/, 2/*#Ops*/, 1, 2, 
            // Src: (callseq_end (timm:i64):$amt1, (timm:i64):$amt2) - Complexity = 9
            // Dst: (ADJCALLSTACKUP (timm:i64):$amt1, (timm:i64):$amt2)
/*22260*/ /*SwitchOpcode*/ 30,  TARGET_VAL(SystemZISD::CALL),// ->22293
/*22263*/   OPC_RecordNode,   // #0 = 'z_call' chained node
/*22264*/   OPC_CaptureGlueInput,
/*22265*/   OPC_RecordChild1, // #1 = $I2
/*22266*/   OPC_CheckChild1Type, MVT::i64,
/*22268*/   OPC_Scope, 12, /*->22282*/ // 2 children in Scope
/*22270*/     OPC_CheckComplexPat, /*CP*/5, /*#*/1, // selectPCRelAddress:$I2 #2
/*22273*/     OPC_EmitMergeInputChains1_0,
/*22274*/     OPC_MorphNodeTo, TARGET_VAL(SystemZ::CallBRASL), 0|OPFL_Chain|OPFL_GlueInput|OPFL_GlueOutput|OPFL_Variadic1,
                  1/*#VTs*/, MVT::i64, 1/*#Ops*/, 2, 
              // Src: (z_call pcrel32:i64:$I2) - Complexity = 9
              // Dst: (CallBRASL:i64 pcrel32:i64:$I2)
/*22282*/   /*Scope*/ 9, /*->22292*/
/*22283*/     OPC_EmitMergeInputChains1_0,
/*22284*/     OPC_MorphNodeTo, TARGET_VAL(SystemZ::CallBASR), 0|OPFL_Chain|OPFL_GlueInput|OPFL_GlueOutput|OPFL_Variadic1,
                  1/*#VTs*/, MVT::i64, 1/*#Ops*/, 1, 
              // Src: (z_call ADDR64:i64:$R2) - Complexity = 3
              // Dst: (CallBASR:i64 ADDR64:i64:$R2)
/*22292*/   0, /*End of Scope*/
/*22293*/ /*SwitchOpcode*/ 30,  TARGET_VAL(SystemZISD::SIBCALL),// ->22326
/*22296*/   OPC_RecordNode,   // #0 = 'z_sibcall' chained node
/*22297*/   OPC_CaptureGlueInput,
/*22298*/   OPC_RecordChild1, // #1 = $I2
/*22299*/   OPC_CheckChild1Type, MVT::i64,
/*22301*/   OPC_Scope, 11, /*->22314*/ // 2 children in Scope
/*22303*/     OPC_CheckComplexPat, /*CP*/5, /*#*/1, // selectPCRelAddress:$I2 #2
/*22306*/     OPC_EmitMergeInputChains1_0,
/*22307*/     OPC_MorphNodeTo, TARGET_VAL(SystemZ::CallJG), 0|OPFL_Chain|OPFL_GlueInput|OPFL_GlueOutput|OPFL_Variadic1,
                  0/*#VTs*/, 1/*#Ops*/, 2, 
              // Src: (z_sibcall pcrel32:i64:$I2) - Complexity = 9
              // Dst: (CallJG pcrel32:i64:$I2)
/*22314*/   /*Scope*/ 10, /*->22325*/
/*22315*/     OPC_EmitMergeInputChains1_0,
/*22316*/     OPC_EmitCopyToReg, 1, SystemZ::R1D,
/*22319*/     OPC_MorphNodeTo, TARGET_VAL(SystemZ::CallBR), 0|OPFL_Chain|OPFL_GlueInput|OPFL_GlueOutput|OPFL_Variadic1,
                  0/*#VTs*/, 0/*#Ops*/, 
              // Src: (z_sibcall R1D:i64) - Complexity = 3
              // Dst: (CallBR)
/*22325*/   0, /*End of Scope*/
/*22326*/ /*SwitchOpcode*/ 19,  TARGET_VAL(SystemZISD::EXTRACT_ACCESS),// ->22348
/*22329*/   OPC_RecordChild0, // #0 = $R2
/*22330*/   OPC_MoveChild, 0,
/*22332*/   OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*22335*/   OPC_CheckPredicate, 103, // Predicate_access_reg
/*22337*/   OPC_MoveParent,
/*22338*/   OPC_EmitConvertToTarget, 0,
/*22340*/   OPC_MorphNodeTo, TARGET_VAL(SystemZ::EAR), 0,
                1/*#VTs*/, MVT::i32, 1/*#Ops*/, 1, 
            // Src: (z_extract_access:i32 (imm:i8)<<P:Predicate_access_reg>>:$R2) - Complexity = 7
            // Dst: (EAR:i32 (imm:i8):$R2)
/*22348*/ /*SwitchOpcode*/ 16,  TARGET_VAL(ISD::CALLSEQ_START),// ->22367
/*22351*/   OPC_RecordNode,   // #0 = 'callseq_start' chained node
/*22352*/   OPC_RecordChild1, // #1 = $amt
/*22353*/   OPC_MoveChild, 1,
/*22355*/   OPC_CheckOpcode, TARGET_VAL(ISD::TargetConstant),
/*22358*/   OPC_MoveParent,
/*22359*/   OPC_EmitMergeInputChains1_0,
/*22360*/   OPC_MorphNodeTo, TARGET_VAL(SystemZ::ADJCALLSTACKDOWN), 0|OPFL_Chain|OPFL_GlueOutput,
                0/*#VTs*/, 1/*#Ops*/, 1, 
            // Src: (callseq_start (timm:i64):$amt) - Complexity = 6
            // Dst: (ADJCALLSTACKDOWN (timm:i64):$amt)
/*22367*/ /*SwitchOpcode*/ 14,  TARGET_VAL(SystemZISD::PCREL_WRAPPER),// ->22384
/*22370*/   OPC_RecordNode,   // #0 = $I2
/*22371*/   OPC_CheckType, MVT::i64,
/*22373*/   OPC_CheckComplexPat, /*CP*/5, /*#*/0, // selectPCRelAddress:$I2 #1
/*22376*/   OPC_MorphNodeTo, TARGET_VAL(SystemZ::LARL), 0,
                1/*#VTs*/, MVT::i64, 1/*#Ops*/, 1, 
            // Src: pcrel32:i64:$I2 - Complexity = 6
            // Dst: (LARL:i64 pcrel32:i64:$I2)
/*22384*/ /*SwitchOpcode*/ 14,  TARGET_VAL(SystemZISD::PCREL_OFFSET),// ->22401
/*22387*/   OPC_RecordNode,   // #0 = $I2
/*22388*/   OPC_CheckType, MVT::i64,
/*22390*/   OPC_CheckComplexPat, /*CP*/5, /*#*/0, // selectPCRelAddress:$I2 #1
/*22393*/   OPC_MorphNodeTo, TARGET_VAL(SystemZ::LARL), 0,
                1/*#VTs*/, MVT::i64, 1/*#Ops*/, 1, 
            // Src: pcrel32:i64:$I2 - Complexity = 6
            // Dst: (LARL:i64 pcrel32:i64:$I2)
/*22401*/ /*SwitchOpcode*/ 92|128,1/*220*/,  TARGET_VAL(ISD::Constant),// ->22625
/*22405*/   OPC_RecordNode,   // #0 = $I2
/*22406*/   OPC_SwitchType /*2 cases */, 82,  MVT::i32,// ->22491
/*22409*/     OPC_Scope, 34, /*->22445*/ // 2 children in Scope
/*22411*/       OPC_CheckPredicate, 31, // Predicate_imm32sx16
/*22413*/       OPC_Scope, 15, /*->22430*/ // 2 children in Scope
/*22415*/         OPC_CheckPatternPredicate, 0, // (Subtarget.hasHighWord())
/*22417*/         OPC_EmitConvertToTarget, 0,
/*22419*/         OPC_EmitNodeXForm, 2, 1, // SIMM16
/*22422*/         OPC_MorphNodeTo, TARGET_VAL(SystemZ::LHIMux), 0,
                      1/*#VTs*/, MVT::i32, 1/*#Ops*/, 2, 
                  // Src: (imm:i32)<<P:Predicate_imm32sx16>><<X:SIMM16>>:$I2 - Complexity = 4
                  // Dst: (LHIMux:i32 (SIMM16:i32 (imm:i32):$I2))
/*22430*/       /*Scope*/ 13, /*->22444*/
/*22431*/         OPC_EmitConvertToTarget, 0,
/*22433*/         OPC_EmitNodeXForm, 2, 1, // SIMM16
/*22436*/         OPC_MorphNodeTo, TARGET_VAL(SystemZ::LHI), 0,
                      1/*#VTs*/, MVT::i32, 1/*#Ops*/, 2, 
                  // Src: (imm:i32)<<P:Predicate_imm32sx16>><<X:SIMM16>>:$I2 - Complexity = 4
                  // Dst: (LHI:i32 (SIMM16:i32 (imm:i32):$I2))
/*22444*/       0, /*End of Scope*/
/*22445*/     /*Scope*/ 44, /*->22490*/
/*22446*/       OPC_Scope, 15, /*->22463*/ // 2 children in Scope
/*22448*/         OPC_CheckPatternPredicate, 0, // (Subtarget.hasHighWord())
/*22450*/         OPC_EmitConvertToTarget, 0,
/*22452*/         OPC_EmitNodeXForm, 5, 1, // UIMM32
/*22455*/         OPC_MorphNodeTo, TARGET_VAL(SystemZ::IIFMux), 0,
                      1/*#VTs*/, MVT::i32, 1/*#Ops*/, 2, 
                  // Src: (imm:i32)<<X:UIMM32>>:$I2 - Complexity = 3
                  // Dst: (IIFMux:i32 (UIMM32:i32 (imm:i32):$I2))
/*22463*/       /*Scope*/ 25, /*->22489*/
/*22464*/         OPC_EmitConvertToTarget, 0,
/*22466*/         OPC_EmitNodeXForm, 5, 1, // UIMM32
/*22469*/         OPC_Scope, 8, /*->22479*/ // 2 children in Scope
/*22471*/           OPC_MorphNodeTo, TARGET_VAL(SystemZ::IILF), 0,
                        1/*#VTs*/, MVT::i32, 1/*#Ops*/, 2, 
                    // Src: (imm:i32)<<X:UIMM32>>:$I2 - Complexity = 3
                    // Dst: (IILF:i32 (UIMM32:i32 (imm:i32):$I2))
/*22479*/         /*Scope*/ 8, /*->22488*/
/*22480*/           OPC_MorphNodeTo, TARGET_VAL(SystemZ::IIHF), 0,
                        1/*#VTs*/, MVT::i32, 1/*#Ops*/, 2, 
                    // Src: (imm:i32)<<X:UIMM32>>:$I2 - Complexity = 3
                    // Dst: (IIHF:i32 (UIMM32:i32 (imm:i32):$I2))
/*22488*/         0, /*End of Scope*/
/*22489*/       0, /*End of Scope*/
/*22490*/     0, /*End of Scope*/
/*22491*/   /*SwitchType*/ 2|128,1/*130*/,  MVT::i64,// ->22624
/*22494*/     OPC_Scope, 15, /*->22511*/ // 8 children in Scope
/*22496*/       OPC_CheckPredicate, 32, // Predicate_imm64sx16
/*22498*/       OPC_EmitConvertToTarget, 0,
/*22500*/       OPC_EmitNodeXForm, 2, 1, // SIMM16
/*22503*/       OPC_MorphNodeTo, TARGET_VAL(SystemZ::LGHI), 0,
                    1/*#VTs*/, MVT::i64, 1/*#Ops*/, 2, 
                // Src: (imm:i64)<<P:Predicate_imm64sx16>><<X:SIMM16>>:$I2 - Complexity = 4
                // Dst: (LGHI:i64 (SIMM16:i64 (imm:i64):$I2))
/*22511*/     /*Scope*/ 15, /*->22527*/
/*22512*/       OPC_CheckPredicate, 47, // Predicate_imm64ll16
/*22514*/       OPC_EmitConvertToTarget, 0,
/*22516*/       OPC_EmitNodeXForm, 6, 1, // LL16
/*22519*/       OPC_MorphNodeTo, TARGET_VAL(SystemZ::LLILL), 0,
                    1/*#VTs*/, MVT::i64, 1/*#Ops*/, 2, 
                // Src: (imm:i64)<<P:Predicate_imm64ll16>><<X:LL16>>:$I2 - Complexity = 4
                // Dst: (LLILL:i64 (LL16:i64 (imm:i64):$I2))
/*22527*/     /*Scope*/ 15, /*->22543*/
/*22528*/       OPC_CheckPredicate, 48, // Predicate_imm64lh16
/*22530*/       OPC_EmitConvertToTarget, 0,
/*22532*/       OPC_EmitNodeXForm, 7, 1, // LH16
/*22535*/       OPC_MorphNodeTo, TARGET_VAL(SystemZ::LLILH), 0,
                    1/*#VTs*/, MVT::i64, 1/*#Ops*/, 2, 
                // Src: (imm:i64)<<P:Predicate_imm64lh16>><<X:LH16>>:$I2 - Complexity = 4
                // Dst: (LLILH:i64 (LH16:i64 (imm:i64):$I2))
/*22543*/     /*Scope*/ 15, /*->22559*/
/*22544*/       OPC_CheckPredicate, 49, // Predicate_imm64hl16
/*22546*/       OPC_EmitConvertToTarget, 0,
/*22548*/       OPC_EmitNodeXForm, 8, 1, // HL16
/*22551*/       OPC_MorphNodeTo, TARGET_VAL(SystemZ::LLIHL), 0,
                    1/*#VTs*/, MVT::i64, 1/*#Ops*/, 2, 
                // Src: (imm:i64)<<P:Predicate_imm64hl16>><<X:HL16>>:$I2 - Complexity = 4
                // Dst: (LLIHL:i64 (HL16:i64 (imm:i64):$I2))
/*22559*/     /*Scope*/ 15, /*->22575*/
/*22560*/       OPC_CheckPredicate, 50, // Predicate_imm64hh16
/*22562*/       OPC_EmitConvertToTarget, 0,
/*22564*/       OPC_EmitNodeXForm, 9, 1, // HH16
/*22567*/       OPC_MorphNodeTo, TARGET_VAL(SystemZ::LLIHH), 0,
                    1/*#VTs*/, MVT::i64, 1/*#Ops*/, 2, 
                // Src: (imm:i64)<<P:Predicate_imm64hh16>><<X:HH16>>:$I2 - Complexity = 4
                // Dst: (LLIHH:i64 (HH16:i64 (imm:i64):$I2))
/*22575*/     /*Scope*/ 15, /*->22591*/
/*22576*/       OPC_CheckPredicate, 63, // Predicate_imm64sx32
/*22578*/       OPC_EmitConvertToTarget, 0,
/*22580*/       OPC_EmitNodeXForm, 11, 1, // SIMM32
/*22583*/       OPC_MorphNodeTo, TARGET_VAL(SystemZ::LGFI), 0,
                    1/*#VTs*/, MVT::i64, 1/*#Ops*/, 2, 
                // Src: (imm:i64)<<P:Predicate_imm64sx32>><<X:SIMM32>>:$I2 - Complexity = 4
                // Dst: (LGFI:i64 (SIMM32:i64 (imm:i64):$I2))
/*22591*/     /*Scope*/ 15, /*->22607*/
/*22592*/       OPC_CheckPredicate, 40, // Predicate_imm64lf32
/*22594*/       OPC_EmitConvertToTarget, 0,
/*22596*/       OPC_EmitNodeXForm, 3, 1, // LF32
/*22599*/       OPC_MorphNodeTo, TARGET_VAL(SystemZ::LLILF), 0,
                    1/*#VTs*/, MVT::i64, 1/*#Ops*/, 2, 
                // Src: (imm:i64)<<P:Predicate_imm64lf32>><<X:LF32>>:$I2 - Complexity = 4
                // Dst: (LLILF:i64 (LF32:i64 (imm:i64):$I2))
/*22607*/     /*Scope*/ 15, /*->22623*/
/*22608*/       OPC_CheckPredicate, 41, // Predicate_imm64hf32
/*22610*/       OPC_EmitConvertToTarget, 0,
/*22612*/       OPC_EmitNodeXForm, 4, 1, // HF32
/*22615*/       OPC_MorphNodeTo, TARGET_VAL(SystemZ::LLIHF), 0,
                    1/*#VTs*/, MVT::i64, 1/*#Ops*/, 2, 
                // Src: (imm:i64)<<P:Predicate_imm64hf32>><<X:HF32>>:$I2 - Complexity = 4
                // Dst: (LLIHF:i64 (HF32:i64 (imm:i64):$I2))
/*22623*/     0, /*End of Scope*/
/*22624*/   0, // EndSwitchType
/*22625*/ /*SwitchOpcode*/ 9,  TARGET_VAL(SystemZISD::RET_FLAG),// ->22637
/*22628*/   OPC_RecordNode,   // #0 = 'z_retflag' chained node
/*22629*/   OPC_CaptureGlueInput,
/*22630*/   OPC_EmitMergeInputChains1_0,
/*22631*/   OPC_MorphNodeTo, TARGET_VAL(SystemZ::Return), 0|OPFL_Chain|OPFL_GlueInput|OPFL_Variadic0,
                0/*#VTs*/, 0/*#Ops*/, 
            // Src: (z_retflag) - Complexity = 3
            // Dst: (Return)
/*22637*/ /*SwitchOpcode*/ 12,  TARGET_VAL(ISD::BRIND),// ->22652
/*22640*/   OPC_RecordNode,   // #0 = 'brind' chained node
/*22641*/   OPC_RecordChild1, // #1 = $R2
/*22642*/   OPC_CheckChild1Type, MVT::i64,
/*22644*/   OPC_EmitMergeInputChains1_0,
/*22645*/   OPC_MorphNodeTo, TARGET_VAL(SystemZ::BR), 0|OPFL_Chain,
                0/*#VTs*/, 1/*#Ops*/, 1, 
            // Src: (brind ADDR64:i64:$R2) - Complexity = 3
            // Dst: (BR ADDR64:i64:$R2)
/*22652*/ /*SwitchOpcode*/ 16,  TARGET_VAL(ISD::BR),// ->22671
/*22655*/   OPC_RecordNode,   // #0 = 'br' chained node
/*22656*/   OPC_RecordChild1, // #1 = $I2
/*22657*/   OPC_MoveChild, 1,
/*22659*/   OPC_CheckOpcode, TARGET_VAL(ISD::BasicBlock),
/*22662*/   OPC_MoveParent,
/*22663*/   OPC_EmitMergeInputChains1_0,
/*22664*/   OPC_MorphNodeTo, TARGET_VAL(SystemZ::J), 0|OPFL_Chain,
                0/*#VTs*/, 1/*#Ops*/, 1, 
            // Src: (br (bb:Other):$I2) - Complexity = 3
            // Dst: (J (bb:Other):$I2)
/*22671*/ /*SwitchOpcode*/ 81,  TARGET_VAL(ISD::SIGN_EXTEND_INREG),// ->22755
/*22674*/   OPC_RecordChild0, // #0 = $R2
/*22675*/   OPC_MoveChild, 1,
/*22677*/   OPC_Scope, 25, /*->22704*/ // 3 children in Scope
/*22679*/     OPC_CheckValueType, MVT::i8,
/*22681*/     OPC_MoveParent,
/*22682*/     OPC_SwitchType /*2 cases */, 8,  MVT::i32,// ->22693
/*22685*/       OPC_MorphNodeTo, TARGET_VAL(SystemZ::LBR), 0,
                    1/*#VTs*/, MVT::i32, 1/*#Ops*/, 0, 
                // Src: (sext_inreg:i32 GR32:i32:$R2, i8:Other) - Complexity = 3
                // Dst: (LBR:i32 GR32:i32:$R2)
/*22693*/     /*SwitchType*/ 8,  MVT::i64,// ->22703
/*22695*/       OPC_MorphNodeTo, TARGET_VAL(SystemZ::LGBR), 0,
                    1/*#VTs*/, MVT::i64, 1/*#Ops*/, 0, 
                // Src: (sext_inreg:i64 GR64:i64:$R2, i8:Other) - Complexity = 3
                // Dst: (LGBR:i64 GR64:i64:$R2)
/*22703*/     0, // EndSwitchType
/*22704*/   /*Scope*/ 25, /*->22730*/
/*22705*/     OPC_CheckValueType, MVT::i16,
/*22707*/     OPC_MoveParent,
/*22708*/     OPC_SwitchType /*2 cases */, 8,  MVT::i32,// ->22719
/*22711*/       OPC_MorphNodeTo, TARGET_VAL(SystemZ::LHR), 0,
                    1/*#VTs*/, MVT::i32, 1/*#Ops*/, 0, 
                // Src: (sext_inreg:i32 GR32:i32:$R2, i16:Other) - Complexity = 3
                // Dst: (LHR:i32 GR32:i32:$R2)
/*22719*/     /*SwitchType*/ 8,  MVT::i64,// ->22729
/*22721*/       OPC_MorphNodeTo, TARGET_VAL(SystemZ::LGHR), 0,
                    1/*#VTs*/, MVT::i64, 1/*#Ops*/, 0, 
                // Src: (sext_inreg:i64 GR64:i64:$R2, i16:Other) - Complexity = 3
                // Dst: (LGHR:i64 GR64:i64:$R2)
/*22729*/     0, // EndSwitchType
/*22730*/   /*Scope*/ 23, /*->22754*/
/*22731*/     OPC_CheckValueType, MVT::i32,
/*22733*/     OPC_MoveParent,
/*22734*/     OPC_EmitInteger, MVT::i32, SystemZ::subreg_l32,
/*22737*/     OPC_EmitNode, TARGET_VAL(TargetOpcode::EXTRACT_SUBREG), 0,
                  1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1,  // Results = #2
/*22746*/     OPC_MorphNodeTo, TARGET_VAL(SystemZ::LGFR), 0,
                  1/*#VTs*/, MVT::i64, 1/*#Ops*/, 2, 
              // Src: (sext_inreg:i64 GR64:i64:$src, i32:Other) - Complexity = 3
              // Dst: (LGFR:i64 (EXTRACT_SUBREG:i32 GR64:i64:$src, subreg_l32:i32))
/*22754*/   0, /*End of Scope*/
/*22755*/ /*SwitchOpcode*/ 9,  TARGET_VAL(ISD::SIGN_EXTEND),// ->22767
/*22758*/   OPC_RecordChild0, // #0 = $R2
/*22759*/   OPC_MorphNodeTo, TARGET_VAL(SystemZ::LGFR), 0,
                1/*#VTs*/, MVT::i64, 1/*#Ops*/, 0, 
            // Src: (sext:i64 GR32:i32:$R2) - Complexity = 3
            // Dst: (LGFR:i64 GR32:i32:$R2)
/*22767*/ /*SwitchOpcode*/ 9,  TARGET_VAL(ISD::ZERO_EXTEND),// ->22779
/*22770*/   OPC_RecordChild0, // #0 = $R2
/*22771*/   OPC_MorphNodeTo, TARGET_VAL(SystemZ::LLGFR), 0,
                1/*#VTs*/, MVT::i64, 1/*#Ops*/, 0, 
            // Src: (zext:i64 GR32:i32:$R2) - Complexity = 3
            // Dst: (LLGFR:i64 GR32:i32:$R2)
/*22779*/ /*SwitchOpcode*/ 13,  TARGET_VAL(ISD::TRUNCATE),// ->22795
/*22782*/   OPC_RecordChild0, // #0 = $src
/*22783*/   OPC_EmitInteger, MVT::i32, SystemZ::subreg_l32,
/*22786*/   OPC_MorphNodeTo, TARGET_VAL(TargetOpcode::EXTRACT_SUBREG), 0,
                1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1, 
            // Src: (trunc:i32 GR64:i64:$src) - Complexity = 3
            // Dst: (EXTRACT_SUBREG:i32 GR64:i64:$src, subreg_l32:i32)
/*22795*/ /*SwitchOpcode*/ 8,  TARGET_VAL(SystemZISD::IPM),// ->22806
/*22798*/   OPC_CaptureGlueInput,
/*22799*/   OPC_MorphNodeTo, TARGET_VAL(SystemZ::IPM), 0|OPFL_GlueInput,
                1/*#VTs*/, MVT::i32, 0/*#Ops*/, 
            // Src: (z_ipm:i32) - Complexity = 3
            // Dst: (IPM:i32)
/*22806*/ /*SwitchOpcode*/ 27,  TARGET_VAL(ISD::BITCAST),// ->22836
/*22809*/   OPC_RecordChild0, // #0 = $R2
/*22810*/   OPC_SwitchType /*2 cases */, 10,  MVT::i64,// ->22823
/*22813*/     OPC_CheckChild0Type, MVT::f64,
/*22815*/     OPC_MorphNodeTo, TARGET_VAL(SystemZ::LGDR), 0,
                  1/*#VTs*/, MVT::i64, 1/*#Ops*/, 0, 
              // Src: (bitconvert:i64 FP64:f64:$R2) - Complexity = 3
              // Dst: (LGDR:i64 FP64:f64:$R2)
/*22823*/   /*SwitchType*/ 10,  MVT::f64,// ->22835
/*22825*/     OPC_CheckChild0Type, MVT::i64,
/*22827*/     OPC_MorphNodeTo, TARGET_VAL(SystemZ::LDGR), 0,
                  1/*#VTs*/, MVT::f64, 1/*#Ops*/, 0, 
              // Src: (bitconvert:f64 GR64:i64:$R2) - Complexity = 3
              // Dst: (LDGR:f64 GR64:i64:$R2)
/*22835*/   0, // EndSwitchType
/*22836*/ /*SwitchOpcode*/ 108,  TARGET_VAL(ISD::FP_TO_SINT),// ->22947
/*22839*/   OPC_RecordChild0, // #0 = $src
/*22840*/   OPC_Scope, 34, /*->22876*/ // 3 children in Scope
/*22842*/     OPC_CheckChild0Type, MVT::f32,
/*22844*/     OPC_SwitchType /*2 cases */, 13,  MVT::i32,// ->22860
/*22847*/       OPC_EmitInteger, MVT::i8, 5, 
/*22850*/       OPC_MorphNodeTo, TARGET_VAL(SystemZ::CFEBR), 0,
                    2/*#VTs*/, MVT::i32, MVT::i32, 2/*#Ops*/, 1, 0, 
                // Src: (fp_to_sint:i32 FP32:f32:$src) - Complexity = 3
                // Dst: (CFEBR:i32:i32 5:i8, FP32:f32:$src)
/*22860*/     /*SwitchType*/ 13,  MVT::i64,// ->22875
/*22862*/       OPC_EmitInteger, MVT::i8, 5, 
/*22865*/       OPC_MorphNodeTo, TARGET_VAL(SystemZ::CGEBR), 0,
                    2/*#VTs*/, MVT::i64, MVT::i32, 2/*#Ops*/, 1, 0, 
                // Src: (fp_to_sint:i64 FP32:f32:$src) - Complexity = 3
                // Dst: (CGEBR:i64:i32 5:i8, FP32:f32:$src)
/*22875*/     0, // EndSwitchType
/*22876*/   /*Scope*/ 34, /*->22911*/
/*22877*/     OPC_CheckChild0Type, MVT::f64,
/*22879*/     OPC_SwitchType /*2 cases */, 13,  MVT::i32,// ->22895
/*22882*/       OPC_EmitInteger, MVT::i8, 5, 
/*22885*/       OPC_MorphNodeTo, TARGET_VAL(SystemZ::CFDBR), 0,
                    2/*#VTs*/, MVT::i32, MVT::i32, 2/*#Ops*/, 1, 0, 
                // Src: (fp_to_sint:i32 FP64:f64:$src) - Complexity = 3
                // Dst: (CFDBR:i32:i32 5:i8, FP64:f64:$src)
/*22895*/     /*SwitchType*/ 13,  MVT::i64,// ->22910
/*22897*/       OPC_EmitInteger, MVT::i8, 5, 
/*22900*/       OPC_MorphNodeTo, TARGET_VAL(SystemZ::CGDBR), 0,
                    2/*#VTs*/, MVT::i64, MVT::i32, 2/*#Ops*/, 1, 0, 
                // Src: (fp_to_sint:i64 FP64:f64:$src) - Complexity = 3
                // Dst: (CGDBR:i64:i32 5:i8, FP64:f64:$src)
/*22910*/     0, // EndSwitchType
/*22911*/   /*Scope*/ 34, /*->22946*/
/*22912*/     OPC_CheckChild0Type, MVT::f128,
/*22914*/     OPC_SwitchType /*2 cases */, 13,  MVT::i32,// ->22930
/*22917*/       OPC_EmitInteger, MVT::i8, 5, 
/*22920*/       OPC_MorphNodeTo, TARGET_VAL(SystemZ::CFXBR), 0,
                    2/*#VTs*/, MVT::i32, MVT::i32, 2/*#Ops*/, 1, 0, 
                // Src: (fp_to_sint:i32 FP128:f128:$src) - Complexity = 3
                // Dst: (CFXBR:i32:i32 5:i8, FP128:f128:$src)
/*22930*/     /*SwitchType*/ 13,  MVT::i64,// ->22945
/*22932*/       OPC_EmitInteger, MVT::i8, 5, 
/*22935*/       OPC_MorphNodeTo, TARGET_VAL(SystemZ::CGXBR), 0,
                    2/*#VTs*/, MVT::i64, MVT::i32, 2/*#Ops*/, 1, 0, 
                // Src: (fp_to_sint:i64 FP128:f128:$src) - Complexity = 3
                // Dst: (CGXBR:i64:i32 5:i8, FP128:f128:$src)
/*22945*/     0, // EndSwitchType
/*22946*/   0, /*End of Scope*/
/*22947*/ /*SwitchOpcode*/ 24,  TARGET_VAL(ISD::CTLZ),// ->22974
/*22950*/   OPC_RecordChild0, // #0 = $src
/*22951*/   OPC_CheckType, MVT::i64,
/*22953*/   OPC_EmitNode, TARGET_VAL(SystemZ::FLOGR), 0,
                2/*#VTs*/, MVT::Untyped, MVT::i32, 1/*#Ops*/, 0,  // Results = #1 #2
/*22962*/   OPC_EmitInteger, MVT::i32, SystemZ::subreg_h64,
/*22965*/   OPC_MorphNodeTo, TARGET_VAL(TargetOpcode::EXTRACT_SUBREG), 0,
                1/*#VTs*/, MVT::i64, 2/*#Ops*/, 1, 3, 
            // Src: (ctlz:i64 GR64:i64:$src) - Complexity = 3
            // Dst: (EXTRACT_SUBREG:i64 (FLOGR:Untyped:i32 GR64:i64:$src), subreg_h64:i32)
/*22974*/ /*SwitchOpcode*/ 21,  TARGET_VAL(ISD::ANY_EXTEND),// ->22998
/*22977*/   OPC_RecordChild0, // #0 = $src
/*22978*/   OPC_EmitNode, TARGET_VAL(TargetOpcode::IMPLICIT_DEF), 0,
                1/*#VTs*/, MVT::i64, 0/*#Ops*/,  // Results = #1
/*22985*/   OPC_EmitInteger, MVT::i32, SystemZ::subreg_l32,
/*22988*/   OPC_MorphNodeTo, TARGET_VAL(TargetOpcode::INSERT_SUBREG), 0,
                1/*#VTs*/, MVT::i64, 3/*#Ops*/, 1, 0, 2, 
            // Src: (anyext:i64 GR32:i32:$src) - Complexity = 3
            // Dst: (INSERT_SUBREG:i64 (IMPLICIT_DEF:i64), GR32:i32:$src, subreg_l32:i32)
/*22998*/ /*SwitchOpcode*/ 22,  TARGET_VAL(SystemZISD::STPCPY),// ->23023
/*23001*/   OPC_RecordNode,   // #0 = 'z_stpcpy' chained node
/*23002*/   OPC_RecordChild1, // #1 = $start1
/*23003*/   OPC_CheckChild1Type, MVT::i64,
/*23005*/   OPC_RecordChild2, // #2 = $start2
/*23006*/   OPC_CheckChild2Type, MVT::i64,
/*23008*/   OPC_RecordChild3, // #3 = $char
/*23009*/   OPC_CheckType, MVT::i64,
/*23011*/   OPC_EmitMergeInputChains1_0,
/*23012*/   OPC_MorphNodeTo, TARGET_VAL(SystemZ::MVSTLoop), 0|OPFL_Chain,
                2/*#VTs*/, MVT::i64, MVT::i32, 3/*#Ops*/, 1, 2, 3, 
            // Src: (z_stpcpy:i64 GR64:i64:$start1, GR64:i64:$start2, GR32:i32:$char) - Complexity = 3
            // Dst: (MVSTLoop:i64:i32 GR64:i64:$start1, GR64:i64:$start2, GR32:i32:$char)
/*23023*/ /*SwitchOpcode*/ 22,  TARGET_VAL(SystemZISD::STRCMP),// ->23048
/*23026*/   OPC_RecordNode,   // #0 = 'z_strcmp' chained node
/*23027*/   OPC_RecordChild1, // #1 = $start1
/*23028*/   OPC_CheckChild1Type, MVT::i64,
/*23030*/   OPC_RecordChild2, // #2 = $start2
/*23031*/   OPC_CheckChild2Type, MVT::i64,
/*23033*/   OPC_RecordChild3, // #3 = $char
/*23034*/   OPC_CheckType, MVT::i64,
/*23036*/   OPC_EmitMergeInputChains1_0,
/*23037*/   OPC_MorphNodeTo, TARGET_VAL(SystemZ::CLSTLoop), 0|OPFL_Chain|OPFL_GlueOutput,
                2/*#VTs*/, MVT::i64, MVT::i32, 3/*#Ops*/, 1, 2, 3, 
            // Src: (z_strcmp:i64 GR64:i64:$start1, GR64:i64:$start2, GR32:i32:$char) - Complexity = 3
            // Dst: (CLSTLoop:i64:i32 GR64:i64:$start1, GR64:i64:$start2, GR32:i32:$char)
/*23048*/ /*SwitchOpcode*/ 22,  TARGET_VAL(SystemZISD::SEARCH_STRING),// ->23073
/*23051*/   OPC_RecordNode,   // #0 = 'z_search_string' chained node
/*23052*/   OPC_RecordChild1, // #1 = $start1
/*23053*/   OPC_CheckChild1Type, MVT::i64,
/*23055*/   OPC_RecordChild2, // #2 = $start2
/*23056*/   OPC_CheckChild2Type, MVT::i64,
/*23058*/   OPC_RecordChild3, // #3 = $char
/*23059*/   OPC_CheckType, MVT::i64,
/*23061*/   OPC_EmitMergeInputChains1_0,
/*23062*/   OPC_MorphNodeTo, TARGET_VAL(SystemZ::SRSTLoop), 0|OPFL_Chain|OPFL_GlueOutput,
                2/*#VTs*/, MVT::i64, MVT::i32, 3/*#Ops*/, 1, 2, 3, 
            // Src: (z_search_string:i64 GR64:i64:$start1, GR64:i64:$start2, GR32:i32:$char) - Complexity = 3
            // Dst: (SRSTLoop:i64:i32 GR64:i64:$start1, GR64:i64:$start2, GR32:i32:$char)
/*23073*/ /*SwitchOpcode*/ 46|128,1/*174*/,  TARGET_VAL(ISD::FMA),// ->23251
/*23077*/   OPC_RecordChild0, // #0 = $R3
/*23078*/   OPC_Scope, 104, /*->23184*/ // 2 children in Scope
/*23080*/     OPC_MoveChild, 1,
/*23082*/     OPC_CheckOpcode, TARGET_VAL(ISD::LOAD),
/*23085*/     OPC_RecordMemRef,
/*23086*/     OPC_RecordNode, // #1 = 'ld' chained node
/*23087*/     OPC_CheckFoldableChainNode,
/*23088*/     OPC_RecordChild1, // #2 = $XBD2
/*23089*/     OPC_CheckChild1Type, MVT::i64,
/*23091*/     OPC_CheckPredicate, 0, // Predicate_unindexedload
/*23093*/     OPC_CheckPredicate, 13, // Predicate_load
/*23095*/     OPC_MoveParent,
/*23096*/     OPC_Scope, 45, /*->23143*/ // 2 children in Scope
/*23098*/       OPC_MoveChild, 2,
/*23100*/       OPC_CheckOpcode, TARGET_VAL(ISD::FNEG),
/*23103*/       OPC_RecordChild0, // #3 = $R1src
/*23104*/       OPC_MoveParent,
/*23105*/       OPC_SwitchType /*2 cases */, 16,  MVT::f32,// ->23124
/*23108*/         OPC_CheckComplexPat, /*CP*/16, /*#*/2, // selectBDXAddr12Only:$XBD2 #4 #5 #6
/*23111*/         OPC_EmitMergeInputChains1_1,
/*23112*/         OPC_MorphNodeTo, TARGET_VAL(SystemZ::MSEB), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::f32, 5/*#Ops*/, 3, 0, 4, 5, 6, 
                  // Src: (fma:f32 FP32:f32:$R3, (ld:f32 bdxaddr12only:i64:$XBD2)<<P:Predicate_unindexedload>><<P:Predicate_load>>, (fneg:f32 FP32:f32:$R1src)) - Complexity = 22
                  // Dst: (MSEB:f32 FP32:f32:$R1src, FP32:f32:$R3, bdxaddr12only:i64:$XBD2)
/*23124*/       /*SwitchType*/ 16,  MVT::f64,// ->23142
/*23126*/         OPC_CheckComplexPat, /*CP*/16, /*#*/2, // selectBDXAddr12Only:$XBD2 #4 #5 #6
/*23129*/         OPC_EmitMergeInputChains1_1,
/*23130*/         OPC_MorphNodeTo, TARGET_VAL(SystemZ::MSDB), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::f64, 5/*#Ops*/, 3, 0, 4, 5, 6, 
                  // Src: (fma:f64 FP64:f64:$R3, (ld:f64 bdxaddr12only:i64:$XBD2)<<P:Predicate_unindexedload>><<P:Predicate_load>>, (fneg:f64 FP64:f64:$R1src)) - Complexity = 22
                  // Dst: (MSDB:f64 FP64:f64:$R1src, FP64:f64:$R3, bdxaddr12only:i64:$XBD2)
/*23142*/       0, // EndSwitchType
/*23143*/     /*Scope*/ 39, /*->23183*/
/*23144*/       OPC_RecordChild2, // #3 = $R1src
/*23145*/       OPC_SwitchType /*2 cases */, 16,  MVT::f32,// ->23164
/*23148*/         OPC_CheckComplexPat, /*CP*/16, /*#*/2, // selectBDXAddr12Only:$XBD2 #4 #5 #6
/*23151*/         OPC_EmitMergeInputChains1_1,
/*23152*/         OPC_MorphNodeTo, TARGET_VAL(SystemZ::MAEB), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::f32, 5/*#Ops*/, 3, 0, 4, 5, 6, 
                  // Src: (fma:f32 FP32:f32:$R3, (ld:f32 bdxaddr12only:i64:$XBD2)<<P:Predicate_unindexedload>><<P:Predicate_load>>, FP32:f32:$R1src) - Complexity = 19
                  // Dst: (MAEB:f32 FP32:f32:$R1src, FP32:f32:$R3, bdxaddr12only:i64:$XBD2)
/*23164*/       /*SwitchType*/ 16,  MVT::f64,// ->23182
/*23166*/         OPC_CheckComplexPat, /*CP*/16, /*#*/2, // selectBDXAddr12Only:$XBD2 #4 #5 #6
/*23169*/         OPC_EmitMergeInputChains1_1,
/*23170*/         OPC_MorphNodeTo, TARGET_VAL(SystemZ::MADB), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::f64, 5/*#Ops*/, 3, 0, 4, 5, 6, 
                  // Src: (fma:f64 FP64:f64:$R3, (ld:f64 bdxaddr12only:i64:$XBD2)<<P:Predicate_unindexedload>><<P:Predicate_load>>, FP64:f64:$R1src) - Complexity = 19
                  // Dst: (MADB:f64 FP64:f64:$R1src, FP64:f64:$R3, bdxaddr12only:i64:$XBD2)
/*23182*/       0, // EndSwitchType
/*23183*/     0, /*End of Scope*/
/*23184*/   /*Scope*/ 65, /*->23250*/
/*23185*/     OPC_RecordChild1, // #1 = $R2
/*23186*/     OPC_Scope, 33, /*->23221*/ // 2 children in Scope
/*23188*/       OPC_MoveChild, 2,
/*23190*/       OPC_CheckOpcode, TARGET_VAL(ISD::FNEG),
/*23193*/       OPC_RecordChild0, // #2 = $R1src
/*23194*/       OPC_MoveParent,
/*23195*/       OPC_SwitchType /*2 cases */, 10,  MVT::f32,// ->23208
/*23198*/         OPC_MorphNodeTo, TARGET_VAL(SystemZ::MSEBR), 0,
                      1/*#VTs*/, MVT::f32, 3/*#Ops*/, 2, 0, 1, 
                  // Src: (fma:f32 FP32:f32:$R3, FP32:f32:$R2, (fneg:f32 FP32:f32:$R1src)) - Complexity = 6
                  // Dst: (MSEBR:f32 FP32:f32:$R1src, FP32:f32:$R3, FP32:f32:$R2)
/*23208*/       /*SwitchType*/ 10,  MVT::f64,// ->23220
/*23210*/         OPC_MorphNodeTo, TARGET_VAL(SystemZ::MSDBR), 0,
                      1/*#VTs*/, MVT::f64, 3/*#Ops*/, 2, 0, 1, 
                  // Src: (fma:f64 FP64:f64:$R3, FP64:f64:$R2, (fneg:f64 FP64:f64:$R1src)) - Complexity = 6
                  // Dst: (MSDBR:f64 FP64:f64:$R1src, FP64:f64:$R3, FP64:f64:$R2)
/*23220*/       0, // EndSwitchType
/*23221*/     /*Scope*/ 27, /*->23249*/
/*23222*/       OPC_RecordChild2, // #2 = $R1src
/*23223*/       OPC_SwitchType /*2 cases */, 10,  MVT::f32,// ->23236
/*23226*/         OPC_MorphNodeTo, TARGET_VAL(SystemZ::MAEBR), 0,
                      1/*#VTs*/, MVT::f32, 3/*#Ops*/, 2, 0, 1, 
                  // Src: (fma:f32 FP32:f32:$R3, FP32:f32:$R2, FP32:f32:$R1src) - Complexity = 3
                  // Dst: (MAEBR:f32 FP32:f32:$R1src, FP32:f32:$R3, FP32:f32:$R2)
/*23236*/       /*SwitchType*/ 10,  MVT::f64,// ->23248
/*23238*/         OPC_MorphNodeTo, TARGET_VAL(SystemZ::MADBR), 0,
                      1/*#VTs*/, MVT::f64, 3/*#Ops*/, 2, 0, 1, 
                  // Src: (fma:f64 FP64:f64:$R3, FP64:f64:$R2, FP64:f64:$R1src) - Complexity = 3
                  // Dst: (MADBR:f64 FP64:f64:$R1src, FP64:f64:$R3, FP64:f64:$R2)
/*23248*/       0, // EndSwitchType
/*23249*/     0, /*End of Scope*/
/*23250*/   0, /*End of Scope*/
/*23251*/ /*SwitchOpcode*/ 98|128,3/*482*/,  TARGET_VAL(ISD::FMUL),// ->23737
/*23255*/   OPC_Scope, 111|128,1/*239*/, /*->23497*/ // 4 children in Scope
/*23258*/     OPC_MoveChild, 0,
/*23260*/     OPC_SwitchOpcode /*2 cases */, 119,  TARGET_VAL(ISD::FP_EXTEND),// ->23383
/*23264*/       OPC_RecordChild0, // #0 = $src1
/*23265*/       OPC_Scope, 56, /*->23323*/ // 2 children in Scope
/*23267*/         OPC_MoveParent,
/*23268*/         OPC_MoveChild, 1,
/*23270*/         OPC_CheckOpcode, TARGET_VAL(ISD::LOAD),
/*23273*/         OPC_RecordMemRef,
/*23274*/         OPC_RecordNode, // #1 = 'ld' chained node
/*23275*/         OPC_CheckFoldableChainNode,
/*23276*/         OPC_RecordChild1, // #2 = $addr
/*23277*/         OPC_CheckChild1Type, MVT::i64,
/*23279*/         OPC_CheckPredicate, 0, // Predicate_unindexedload
/*23281*/         OPC_CheckPredicate, 76, // Predicate_extload
/*23283*/         OPC_CheckPredicate, 77, // Predicate_extloadf32
/*23285*/         OPC_MoveParent,
/*23286*/         OPC_CheckType, MVT::f64,
/*23288*/         OPC_CheckComplexPat, /*CP*/16, /*#*/2, // selectBDXAddr12Only:$addr #3 #4 #5
/*23291*/         OPC_EmitMergeInputChains1_1,
/*23292*/         OPC_EmitNode, TARGET_VAL(TargetOpcode::IMPLICIT_DEF), 0,
                      1/*#VTs*/, MVT::f64, 0/*#Ops*/,  // Results = #6
/*23299*/         OPC_EmitInteger, MVT::i32, SystemZ::subreg_h32,
/*23302*/         OPC_EmitNode, TARGET_VAL(TargetOpcode::INSERT_SUBREG), 0,
                      1/*#VTs*/, MVT::f64, 3/*#Ops*/, 6, 0, 7,  // Results = #8
/*23312*/         OPC_MorphNodeTo, TARGET_VAL(SystemZ::MDEB), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::f64, 4/*#Ops*/, 8, 3, 4, 5, 
                  // Src: (fmul:f64 (fextend:f64 FP32:f32:$src1), (ld:f64 bdxaddr12only:i64:$addr)<<P:Predicate_unindexedload>><<P:Predicate_extload>><<P:Predicate_extloadf32>>) - Complexity = 22
                  // Dst: (MDEB:f64 (INSERT_SUBREG:f64 (IMPLICIT_DEF:f64), FP32:f32:$src1, subreg_h32:i32), bdxaddr12only:i64:$addr)
/*23323*/       /*Scope*/ 58, /*->23382*/
/*23324*/         OPC_CheckChild0Type, MVT::f64,
/*23326*/         OPC_MoveParent,
/*23327*/         OPC_MoveChild, 1,
/*23329*/         OPC_CheckOpcode, TARGET_VAL(ISD::LOAD),
/*23332*/         OPC_RecordMemRef,
/*23333*/         OPC_RecordNode, // #1 = 'ld' chained node
/*23334*/         OPC_CheckFoldableChainNode,
/*23335*/         OPC_RecordChild1, // #2 = $addr
/*23336*/         OPC_CheckChild1Type, MVT::i64,
/*23338*/         OPC_CheckPredicate, 0, // Predicate_unindexedload
/*23340*/         OPC_CheckPredicate, 76, // Predicate_extload
/*23342*/         OPC_CheckPredicate, 78, // Predicate_extloadf64
/*23344*/         OPC_MoveParent,
/*23345*/         OPC_CheckType, MVT::f128,
/*23347*/         OPC_CheckComplexPat, /*CP*/16, /*#*/2, // selectBDXAddr12Only:$addr #3 #4 #5
/*23350*/         OPC_EmitMergeInputChains1_1,
/*23351*/         OPC_EmitNode, TARGET_VAL(TargetOpcode::IMPLICIT_DEF), 0,
                      1/*#VTs*/, MVT::f128, 0/*#Ops*/,  // Results = #6
/*23358*/         OPC_EmitInteger, MVT::i32, SystemZ::subreg_h64,
/*23361*/         OPC_EmitNode, TARGET_VAL(TargetOpcode::INSERT_SUBREG), 0,
                      1/*#VTs*/, MVT::f128, 3/*#Ops*/, 6, 0, 7,  // Results = #8
/*23371*/         OPC_MorphNodeTo, TARGET_VAL(SystemZ::MXDB), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::f128, 4/*#Ops*/, 8, 3, 4, 5, 
                  // Src: (fmul:f128 (fextend:f128 FP64:f64:$src1), (ld:f128 bdxaddr12only:i64:$addr)<<P:Predicate_unindexedload>><<P:Predicate_extload>><<P:Predicate_extloadf64>>) - Complexity = 22
                  // Dst: (MXDB:f128 (INSERT_SUBREG:f128 (IMPLICIT_DEF:f128), FP64:f64:$src1, subreg_h64:i32), bdxaddr12only:i64:$addr)
/*23382*/       0, /*End of Scope*/
/*23383*/     /*SwitchOpcode*/ 110,  TARGET_VAL(ISD::LOAD),// ->23496
/*23386*/       OPC_RecordMemRef,
/*23387*/       OPC_RecordNode, // #0 = 'ld' chained node
/*23388*/       OPC_CheckFoldableChainNode,
/*23389*/       OPC_RecordChild1, // #1 = $addr
/*23390*/       OPC_CheckChild1Type, MVT::i64,
/*23392*/       OPC_CheckPredicate, 0, // Predicate_unindexedload
/*23394*/       OPC_CheckPredicate, 76, // Predicate_extload
/*23396*/       OPC_Scope, 47, /*->23445*/ // 2 children in Scope
/*23398*/         OPC_CheckPredicate, 77, // Predicate_extloadf32
/*23400*/         OPC_MoveParent,
/*23401*/         OPC_MoveChild, 1,
/*23403*/         OPC_CheckOpcode, TARGET_VAL(ISD::FP_EXTEND),
/*23406*/         OPC_RecordChild0, // #2 = $src1
/*23407*/         OPC_MoveParent,
/*23408*/         OPC_CheckType, MVT::f64,
/*23410*/         OPC_CheckComplexPat, /*CP*/16, /*#*/1, // selectBDXAddr12Only:$addr #3 #4 #5
/*23413*/         OPC_EmitMergeInputChains1_0,
/*23414*/         OPC_EmitNode, TARGET_VAL(TargetOpcode::IMPLICIT_DEF), 0,
                      1/*#VTs*/, MVT::f64, 0/*#Ops*/,  // Results = #6
/*23421*/         OPC_EmitInteger, MVT::i32, SystemZ::subreg_h32,
/*23424*/         OPC_EmitNode, TARGET_VAL(TargetOpcode::INSERT_SUBREG), 0,
                      1/*#VTs*/, MVT::f64, 3/*#Ops*/, 6, 2, 7,  // Results = #8
/*23434*/         OPC_MorphNodeTo, TARGET_VAL(SystemZ::MDEB), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::f64, 4/*#Ops*/, 8, 3, 4, 5, 
                  // Src: (fmul:f64 (ld:f64 bdxaddr12only:i64:$addr)<<P:Predicate_unindexedload>><<P:Predicate_extload>><<P:Predicate_extloadf32>>, (fextend:f64 FP32:f32:$src1)) - Complexity = 22
                  // Dst: (MDEB:f64 (INSERT_SUBREG:f64 (IMPLICIT_DEF:f64), FP32:f32:$src1, subreg_h32:i32), bdxaddr12only:i64:$addr)
/*23445*/       /*Scope*/ 49, /*->23495*/
/*23446*/         OPC_CheckPredicate, 78, // Predicate_extloadf64
/*23448*/         OPC_MoveParent,
/*23449*/         OPC_MoveChild, 1,
/*23451*/         OPC_CheckOpcode, TARGET_VAL(ISD::FP_EXTEND),
/*23454*/         OPC_RecordChild0, // #2 = $src1
/*23455*/         OPC_CheckChild0Type, MVT::f64,
/*23457*/         OPC_MoveParent,
/*23458*/         OPC_CheckType, MVT::f128,
/*23460*/         OPC_CheckComplexPat, /*CP*/16, /*#*/1, // selectBDXAddr12Only:$addr #3 #4 #5
/*23463*/         OPC_EmitMergeInputChains1_0,
/*23464*/         OPC_EmitNode, TARGET_VAL(TargetOpcode::IMPLICIT_DEF), 0,
                      1/*#VTs*/, MVT::f128, 0/*#Ops*/,  // Results = #6
/*23471*/         OPC_EmitInteger, MVT::i32, SystemZ::subreg_h64,
/*23474*/         OPC_EmitNode, TARGET_VAL(TargetOpcode::INSERT_SUBREG), 0,
                      1/*#VTs*/, MVT::f128, 3/*#Ops*/, 6, 2, 7,  // Results = #8
/*23484*/         OPC_MorphNodeTo, TARGET_VAL(SystemZ::MXDB), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::f128, 4/*#Ops*/, 8, 3, 4, 5, 
                  // Src: (fmul:f128 (ld:f128 bdxaddr12only:i64:$addr)<<P:Predicate_unindexedload>><<P:Predicate_extload>><<P:Predicate_extloadf64>>, (fextend:f128 FP64:f64:$src1)) - Complexity = 22
                  // Dst: (MXDB:f128 (INSERT_SUBREG:f128 (IMPLICIT_DEF:f128), FP64:f64:$src1, subreg_h64:i32), bdxaddr12only:i64:$addr)
/*23495*/       0, /*End of Scope*/
/*23496*/     0, // EndSwitchOpcode
/*23497*/   /*Scope*/ 53, /*->23551*/
/*23498*/     OPC_RecordChild0, // #0 = $R1src
/*23499*/     OPC_MoveChild, 1,
/*23501*/     OPC_CheckOpcode, TARGET_VAL(ISD::LOAD),
/*23504*/     OPC_RecordMemRef,
/*23505*/     OPC_RecordNode, // #1 = 'ld' chained node
/*23506*/     OPC_CheckFoldableChainNode,
/*23507*/     OPC_RecordChild1, // #2 = $XBD2
/*23508*/     OPC_CheckChild1Type, MVT::i64,
/*23510*/     OPC_CheckPredicate, 0, // Predicate_unindexedload
/*23512*/     OPC_CheckPredicate, 13, // Predicate_load
/*23514*/     OPC_MoveParent,
/*23515*/     OPC_SwitchType /*2 cases */, 15,  MVT::f32,// ->23533
/*23518*/       OPC_CheckComplexPat, /*CP*/16, /*#*/2, // selectBDXAddr12Only:$XBD2 #3 #4 #5
/*23521*/       OPC_EmitMergeInputChains1_1,
/*23522*/       OPC_MorphNodeTo, TARGET_VAL(SystemZ::MEEB), 0|OPFL_Chain|OPFL_MemRefs,
                    1/*#VTs*/, MVT::f32, 4/*#Ops*/, 0, 3, 4, 5, 
                // Src: (fmul:f32 FP32:f32:$R1src, (ld:f32 bdxaddr12only:i64:$XBD2)<<P:Predicate_unindexedload>><<P:Predicate_load>>) - Complexity = 19
                // Dst: (MEEB:f32 FP32:f32:$R1src, bdxaddr12only:i64:$XBD2)
/*23533*/     /*SwitchType*/ 15,  MVT::f64,// ->23550
/*23535*/       OPC_CheckComplexPat, /*CP*/16, /*#*/2, // selectBDXAddr12Only:$XBD2 #3 #4 #5
/*23538*/       OPC_EmitMergeInputChains1_1,
/*23539*/       OPC_MorphNodeTo, TARGET_VAL(SystemZ::MDB), 0|OPFL_Chain|OPFL_MemRefs,
                    1/*#VTs*/, MVT::f64, 4/*#Ops*/, 0, 3, 4, 5, 
                // Src: (fmul:f64 FP64:f64:$R1src, (ld:f64 bdxaddr12only:i64:$XBD2)<<P:Predicate_unindexedload>><<P:Predicate_load>>) - Complexity = 19
                // Dst: (MDB:f64 FP64:f64:$R1src, bdxaddr12only:i64:$XBD2)
/*23550*/     0, // EndSwitchType
/*23551*/   /*Scope*/ 17|128,1/*145*/, /*->23698*/
/*23553*/     OPC_MoveChild, 0,
/*23555*/     OPC_SwitchOpcode /*2 cases */, 48,  TARGET_VAL(ISD::LOAD),// ->23607
/*23559*/       OPC_RecordMemRef,
/*23560*/       OPC_RecordNode, // #0 = 'ld' chained node
/*23561*/       OPC_CheckFoldableChainNode,
/*23562*/       OPC_RecordChild1, // #1 = $XBD2
/*23563*/       OPC_CheckChild1Type, MVT::i64,
/*23565*/       OPC_CheckPredicate, 0, // Predicate_unindexedload
/*23567*/       OPC_CheckPredicate, 13, // Predicate_load
/*23569*/       OPC_MoveParent,
/*23570*/       OPC_RecordChild1, // #2 = $R1src
/*23571*/       OPC_SwitchType /*2 cases */, 15,  MVT::f32,// ->23589
/*23574*/         OPC_CheckComplexPat, /*CP*/16, /*#*/1, // selectBDXAddr12Only:$XBD2 #3 #4 #5
/*23577*/         OPC_EmitMergeInputChains1_0,
/*23578*/         OPC_MorphNodeTo, TARGET_VAL(SystemZ::MEEB), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::f32, 4/*#Ops*/, 2, 3, 4, 5, 
                  // Src: (fmul:f32 (ld:f32 bdxaddr12only:i64:$XBD2)<<P:Predicate_unindexedload>><<P:Predicate_load>>, FP32:f32:$R1src) - Complexity = 19
                  // Dst: (MEEB:f32 FP32:f32:$R1src, bdxaddr12only:i64:$XBD2)
/*23589*/       /*SwitchType*/ 15,  MVT::f64,// ->23606
/*23591*/         OPC_CheckComplexPat, /*CP*/16, /*#*/1, // selectBDXAddr12Only:$XBD2 #3 #4 #5
/*23594*/         OPC_EmitMergeInputChains1_0,
/*23595*/         OPC_MorphNodeTo, TARGET_VAL(SystemZ::MDB), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::f64, 4/*#Ops*/, 2, 3, 4, 5, 
                  // Src: (fmul:f64 (ld:f64 bdxaddr12only:i64:$XBD2)<<P:Predicate_unindexedload>><<P:Predicate_load>>, FP64:f64:$R1src) - Complexity = 19
                  // Dst: (MDB:f64 FP64:f64:$R1src, bdxaddr12only:i64:$XBD2)
/*23606*/       0, // EndSwitchType
/*23607*/     /*SwitchOpcode*/ 87,  TARGET_VAL(ISD::FP_EXTEND),// ->23697
/*23610*/       OPC_RecordChild0, // #0 = $src1
/*23611*/       OPC_Scope, 39, /*->23652*/ // 2 children in Scope
/*23613*/         OPC_MoveParent,
/*23614*/         OPC_MoveChild, 1,
/*23616*/         OPC_CheckOpcode, TARGET_VAL(ISD::FP_EXTEND),
/*23619*/         OPC_RecordChild0, // #1 = $src2
/*23620*/         OPC_MoveParent,
/*23621*/         OPC_CheckType, MVT::f64,
/*23623*/         OPC_EmitNode, TARGET_VAL(TargetOpcode::IMPLICIT_DEF), 0,
                      1/*#VTs*/, MVT::f64, 0/*#Ops*/,  // Results = #2
/*23630*/         OPC_EmitInteger, MVT::i32, SystemZ::subreg_h32,
/*23633*/         OPC_EmitNode, TARGET_VAL(TargetOpcode::INSERT_SUBREG), 0,
                      1/*#VTs*/, MVT::f64, 3/*#Ops*/, 2, 0, 3,  // Results = #4
/*23643*/         OPC_MorphNodeTo, TARGET_VAL(SystemZ::MDEBR), 0,
                      1/*#VTs*/, MVT::f64, 2/*#Ops*/, 4, 1, 
                  // Src: (fmul:f64 (fextend:f64 FP32:f32:$src1), (fextend:f64 FP32:f32:$src2)) - Complexity = 9
                  // Dst: (MDEBR:f64 (INSERT_SUBREG:f64 (IMPLICIT_DEF:f64), FP32:f32:$src1, subreg_h32:i32), FP32:f32:$src2)
/*23652*/       /*Scope*/ 43, /*->23696*/
/*23653*/         OPC_CheckChild0Type, MVT::f64,
/*23655*/         OPC_MoveParent,
/*23656*/         OPC_MoveChild, 1,
/*23658*/         OPC_CheckOpcode, TARGET_VAL(ISD::FP_EXTEND),
/*23661*/         OPC_RecordChild0, // #1 = $src2
/*23662*/         OPC_CheckChild0Type, MVT::f64,
/*23664*/         OPC_MoveParent,
/*23665*/         OPC_CheckType, MVT::f128,
/*23667*/         OPC_EmitNode, TARGET_VAL(TargetOpcode::IMPLICIT_DEF), 0,
                      1/*#VTs*/, MVT::f128, 0/*#Ops*/,  // Results = #2
/*23674*/         OPC_EmitInteger, MVT::i32, SystemZ::subreg_h64,
/*23677*/         OPC_EmitNode, TARGET_VAL(TargetOpcode::INSERT_SUBREG), 0,
                      1/*#VTs*/, MVT::f128, 3/*#Ops*/, 2, 0, 3,  // Results = #4
/*23687*/         OPC_MorphNodeTo, TARGET_VAL(SystemZ::MXDBR), 0,
                      1/*#VTs*/, MVT::f128, 2/*#Ops*/, 4, 1, 
                  // Src: (fmul:f128 (fextend:f128 FP64:f64:$src1), (fextend:f128 FP64:f64:$src2)) - Complexity = 9
                  // Dst: (MXDBR:f128 (INSERT_SUBREG:f128 (IMPLICIT_DEF:f128), FP64:f64:$src1, subreg_h64:i32), FP64:f64:$src2)
/*23696*/       0, /*End of Scope*/
/*23697*/     0, // EndSwitchOpcode
/*23698*/   /*Scope*/ 37, /*->23736*/
/*23699*/     OPC_RecordChild0, // #0 = $R1src
/*23700*/     OPC_RecordChild1, // #1 = $R2
/*23701*/     OPC_SwitchType /*3 cases */, 9,  MVT::f32,// ->23713
/*23704*/       OPC_MorphNodeTo, TARGET_VAL(SystemZ::MEEBR), 0,
                    1/*#VTs*/, MVT::f32, 2/*#Ops*/, 0, 1, 
                // Src: (fmul:f32 FP32:f32:$R1src, FP32:f32:$R2) - Complexity = 3
                // Dst: (MEEBR:f32 FP32:f32:$R1src, FP32:f32:$R2)
/*23713*/     /*SwitchType*/ 9,  MVT::f64,// ->23724
/*23715*/       OPC_MorphNodeTo, TARGET_VAL(SystemZ::MDBR), 0,
                    1/*#VTs*/, MVT::f64, 2/*#Ops*/, 0, 1, 
                // Src: (fmul:f64 FP64:f64:$R1src, FP64:f64:$R2) - Complexity = 3
                // Dst: (MDBR:f64 FP64:f64:$R1src, FP64:f64:$R2)
/*23724*/     /*SwitchType*/ 9,  MVT::f128,// ->23735
/*23726*/       OPC_MorphNodeTo, TARGET_VAL(SystemZ::MXBR), 0,
                    1/*#VTs*/, MVT::f128, 2/*#Ops*/, 0, 1, 
                // Src: (fmul:f128 FP128:f128:$R1src, FP128:f128:$R2) - Complexity = 3
                // Dst: (MXBR:f128 FP128:f128:$R1src, FP128:f128:$R2)
/*23735*/     0, // EndSwitchType
/*23736*/   0, /*End of Scope*/
/*23737*/ /*SwitchOpcode*/ 86,  TARGET_VAL(ISD::FSQRT),// ->23826
/*23740*/   OPC_Scope, 49, /*->23791*/ // 2 children in Scope
/*23742*/     OPC_MoveChild, 0,
/*23744*/     OPC_CheckOpcode, TARGET_VAL(ISD::LOAD),
/*23747*/     OPC_RecordMemRef,
/*23748*/     OPC_RecordNode, // #0 = 'ld' chained node
/*23749*/     OPC_RecordChild1, // #1 = $XBD2
/*23750*/     OPC_CheckChild1Type, MVT::i64,
/*23752*/     OPC_CheckPredicate, 0, // Predicate_unindexedload
/*23754*/     OPC_CheckPredicate, 13, // Predicate_load
/*23756*/     OPC_MoveParent,
/*23757*/     OPC_SwitchType /*2 cases */, 14,  MVT::f32,// ->23774
/*23760*/       OPC_CheckComplexPat, /*CP*/16, /*#*/1, // selectBDXAddr12Only:$XBD2 #2 #3 #4
/*23763*/       OPC_EmitMergeInputChains1_0,
/*23764*/       OPC_MorphNodeTo, TARGET_VAL(SystemZ::SQEB), 0|OPFL_Chain|OPFL_MemRefs,
                    1/*#VTs*/, MVT::f32, 3/*#Ops*/, 2, 3, 4, 
                // Src: (fsqrt:f32 (ld:f32 bdxaddr12only:i64:$XBD2)<<P:Predicate_unindexedload>><<P:Predicate_load>>) - Complexity = 19
                // Dst: (SQEB:f32 bdxaddr12only:i64:$XBD2)
/*23774*/     /*SwitchType*/ 14,  MVT::f64,// ->23790
/*23776*/       OPC_CheckComplexPat, /*CP*/16, /*#*/1, // selectBDXAddr12Only:$XBD2 #2 #3 #4
/*23779*/       OPC_EmitMergeInputChains1_0,
/*23780*/       OPC_MorphNodeTo, TARGET_VAL(SystemZ::SQDB), 0|OPFL_Chain|OPFL_MemRefs,
                    1/*#VTs*/, MVT::f64, 3/*#Ops*/, 2, 3, 4, 
                // Src: (fsqrt:f64 (ld:f64 bdxaddr12only:i64:$XBD2)<<P:Predicate_unindexedload>><<P:Predicate_load>>) - Complexity = 19
                // Dst: (SQDB:f64 bdxaddr12only:i64:$XBD2)
/*23790*/     0, // EndSwitchType
/*23791*/   /*Scope*/ 33, /*->23825*/
/*23792*/     OPC_RecordChild0, // #0 = $R2
/*23793*/     OPC_SwitchType /*3 cases */, 8,  MVT::f32,// ->23804
/*23796*/       OPC_MorphNodeTo, TARGET_VAL(SystemZ::SQEBR), 0,
                    1/*#VTs*/, MVT::f32, 1/*#Ops*/, 0, 
                // Src: (fsqrt:f32 FP32:f32:$R2) - Complexity = 3
                // Dst: (SQEBR:f32 FP32:f32:$R2)
/*23804*/     /*SwitchType*/ 8,  MVT::f64,// ->23814
/*23806*/       OPC_MorphNodeTo, TARGET_VAL(SystemZ::SQDBR), 0,
                    1/*#VTs*/, MVT::f64, 1/*#Ops*/, 0, 
                // Src: (fsqrt:f64 FP64:f64:$R2) - Complexity = 3
                // Dst: (SQDBR:f64 FP64:f64:$R2)
/*23814*/     /*SwitchType*/ 8,  MVT::f128,// ->23824
/*23816*/       OPC_MorphNodeTo, TARGET_VAL(SystemZ::SQXBR), 0,
                    1/*#VTs*/, MVT::f128, 1/*#Ops*/, 0, 
                // Src: (fsqrt:f128 FP128:f128:$R2) - Complexity = 3
                // Dst: (SQXBR:f128 FP128:f128:$R2)
/*23824*/     0, // EndSwitchType
/*23825*/   0, /*End of Scope*/
/*23826*/ /*SwitchOpcode*/ 27|128,1/*155*/,  TARGET_VAL(ISD::FADD),// ->23985
/*23830*/   OPC_Scope, 55, /*->23887*/ // 3 children in Scope
/*23832*/     OPC_RecordChild0, // #0 = $R1src
/*23833*/     OPC_MoveChild, 1,
/*23835*/     OPC_CheckOpcode, TARGET_VAL(ISD::LOAD),
/*23838*/     OPC_RecordMemRef,
/*23839*/     OPC_RecordNode, // #1 = 'ld' chained node
/*23840*/     OPC_CheckFoldableChainNode,
/*23841*/     OPC_RecordChild1, // #2 = $XBD2
/*23842*/     OPC_CheckChild1Type, MVT::i64,
/*23844*/     OPC_CheckPredicate, 0, // Predicate_unindexedload
/*23846*/     OPC_CheckPredicate, 13, // Predicate_load
/*23848*/     OPC_MoveParent,
/*23849*/     OPC_SwitchType /*2 cases */, 16,  MVT::f32,// ->23868
/*23852*/       OPC_CheckComplexPat, /*CP*/16, /*#*/2, // selectBDXAddr12Only:$XBD2 #3 #4 #5
/*23855*/       OPC_EmitMergeInputChains1_1,
/*23856*/       OPC_MorphNodeTo, TARGET_VAL(SystemZ::AEB), 0|OPFL_Chain|OPFL_MemRefs,
                    2/*#VTs*/, MVT::f32, MVT::i32, 4/*#Ops*/, 0, 3, 4, 5, 
                // Src: (fadd:f32 FP32:f32:$R1src, (ld:f32 bdxaddr12only:i64:$XBD2)<<P:Predicate_unindexedload>><<P:Predicate_load>>) - Complexity = 19
                // Dst: (AEB:f32:i32 FP32:f32:$R1src, bdxaddr12only:i64:$XBD2)
/*23868*/     /*SwitchType*/ 16,  MVT::f64,// ->23886
/*23870*/       OPC_CheckComplexPat, /*CP*/16, /*#*/2, // selectBDXAddr12Only:$XBD2 #3 #4 #5
/*23873*/       OPC_EmitMergeInputChains1_1,
/*23874*/       OPC_MorphNodeTo, TARGET_VAL(SystemZ::ADB), 0|OPFL_Chain|OPFL_MemRefs,
                    2/*#VTs*/, MVT::f64, MVT::i32, 4/*#Ops*/, 0, 3, 4, 5, 
                // Src: (fadd:f64 FP64:f64:$R1src, (ld:f64 bdxaddr12only:i64:$XBD2)<<P:Predicate_unindexedload>><<P:Predicate_load>>) - Complexity = 19
                // Dst: (ADB:f64:i32 FP64:f64:$R1src, bdxaddr12only:i64:$XBD2)
/*23886*/     0, // EndSwitchType
/*23887*/   /*Scope*/ 55, /*->23943*/
/*23888*/     OPC_MoveChild, 0,
/*23890*/     OPC_CheckOpcode, TARGET_VAL(ISD::LOAD),
/*23893*/     OPC_RecordMemRef,
/*23894*/     OPC_RecordNode, // #0 = 'ld' chained node
/*23895*/     OPC_CheckFoldableChainNode,
/*23896*/     OPC_RecordChild1, // #1 = $XBD2
/*23897*/     OPC_CheckChild1Type, MVT::i64,
/*23899*/     OPC_CheckPredicate, 0, // Predicate_unindexedload
/*23901*/     OPC_CheckPredicate, 13, // Predicate_load
/*23903*/     OPC_MoveParent,
/*23904*/     OPC_RecordChild1, // #2 = $R1src
/*23905*/     OPC_SwitchType /*2 cases */, 16,  MVT::f32,// ->23924
/*23908*/       OPC_CheckComplexPat, /*CP*/16, /*#*/1, // selectBDXAddr12Only:$XBD2 #3 #4 #5
/*23911*/       OPC_EmitMergeInputChains1_0,
/*23912*/       OPC_MorphNodeTo, TARGET_VAL(SystemZ::AEB), 0|OPFL_Chain|OPFL_MemRefs,
                    2/*#VTs*/, MVT::f32, MVT::i32, 4/*#Ops*/, 2, 3, 4, 5, 
                // Src: (fadd:f32 (ld:f32 bdxaddr12only:i64:$XBD2)<<P:Predicate_unindexedload>><<P:Predicate_load>>, FP32:f32:$R1src) - Complexity = 19
                // Dst: (AEB:f32:i32 FP32:f32:$R1src, bdxaddr12only:i64:$XBD2)
/*23924*/     /*SwitchType*/ 16,  MVT::f64,// ->23942
/*23926*/       OPC_CheckComplexPat, /*CP*/16, /*#*/1, // selectBDXAddr12Only:$XBD2 #3 #4 #5
/*23929*/       OPC_EmitMergeInputChains1_0,
/*23930*/       OPC_MorphNodeTo, TARGET_VAL(SystemZ::ADB), 0|OPFL_Chain|OPFL_MemRefs,
                    2/*#VTs*/, MVT::f64, MVT::i32, 4/*#Ops*/, 2, 3, 4, 5, 
                // Src: (fadd:f64 (ld:f64 bdxaddr12only:i64:$XBD2)<<P:Predicate_unindexedload>><<P:Predicate_load>>, FP64:f64:$R1src) - Complexity = 19
                // Dst: (ADB:f64:i32 FP64:f64:$R1src, bdxaddr12only:i64:$XBD2)
/*23942*/     0, // EndSwitchType
/*23943*/   /*Scope*/ 40, /*->23984*/
/*23944*/     OPC_RecordChild0, // #0 = $R1src
/*23945*/     OPC_RecordChild1, // #1 = $R2
/*23946*/     OPC_SwitchType /*3 cases */, 10,  MVT::f32,// ->23959
/*23949*/       OPC_MorphNodeTo, TARGET_VAL(SystemZ::AEBR), 0,
                    2/*#VTs*/, MVT::f32, MVT::i32, 2/*#Ops*/, 0, 1, 
                // Src: (fadd:f32 FP32:f32:$R1src, FP32:f32:$R2) - Complexity = 3
                // Dst: (AEBR:f32:i32 FP32:f32:$R1src, FP32:f32:$R2)
/*23959*/     /*SwitchType*/ 10,  MVT::f64,// ->23971
/*23961*/       OPC_MorphNodeTo, TARGET_VAL(SystemZ::ADBR), 0,
                    2/*#VTs*/, MVT::f64, MVT::i32, 2/*#Ops*/, 0, 1, 
                // Src: (fadd:f64 FP64:f64:$R1src, FP64:f64:$R2) - Complexity = 3
                // Dst: (ADBR:f64:i32 FP64:f64:$R1src, FP64:f64:$R2)
/*23971*/     /*SwitchType*/ 10,  MVT::f128,// ->23983
/*23973*/       OPC_MorphNodeTo, TARGET_VAL(SystemZ::AXBR), 0,
                    2/*#VTs*/, MVT::f128, MVT::i32, 2/*#Ops*/, 0, 1, 
                // Src: (fadd:f128 FP128:f128:$R1src, FP128:f128:$R2) - Complexity = 3
                // Dst: (AXBR:f128:i32 FP128:f128:$R1src, FP128:f128:$R2)
/*23983*/     0, // EndSwitchType
/*23984*/   0, /*End of Scope*/
/*23985*/ /*SwitchOpcode*/ 98,  TARGET_VAL(ISD::FSUB),// ->24086
/*23988*/   OPC_RecordChild0, // #0 = $R1src
/*23989*/   OPC_Scope, 54, /*->24045*/ // 2 children in Scope
/*23991*/     OPC_MoveChild, 1,
/*23993*/     OPC_CheckOpcode, TARGET_VAL(ISD::LOAD),
/*23996*/     OPC_RecordMemRef,
/*23997*/     OPC_RecordNode, // #1 = 'ld' chained node
/*23998*/     OPC_CheckFoldableChainNode,
/*23999*/     OPC_RecordChild1, // #2 = $XBD2
/*24000*/     OPC_CheckChild1Type, MVT::i64,
/*24002*/     OPC_CheckPredicate, 0, // Predicate_unindexedload
/*24004*/     OPC_CheckPredicate, 13, // Predicate_load
/*24006*/     OPC_MoveParent,
/*24007*/     OPC_SwitchType /*2 cases */, 16,  MVT::f32,// ->24026
/*24010*/       OPC_CheckComplexPat, /*CP*/16, /*#*/2, // selectBDXAddr12Only:$XBD2 #3 #4 #5
/*24013*/       OPC_EmitMergeInputChains1_1,
/*24014*/       OPC_MorphNodeTo, TARGET_VAL(SystemZ::SEB), 0|OPFL_Chain|OPFL_MemRefs,
                    2/*#VTs*/, MVT::f32, MVT::i32, 4/*#Ops*/, 0, 3, 4, 5, 
                // Src: (fsub:f32 FP32:f32:$R1src, (ld:f32 bdxaddr12only:i64:$XBD2)<<P:Predicate_unindexedload>><<P:Predicate_load>>) - Complexity = 19
                // Dst: (SEB:f32:i32 FP32:f32:$R1src, bdxaddr12only:i64:$XBD2)
/*24026*/     /*SwitchType*/ 16,  MVT::f64,// ->24044
/*24028*/       OPC_CheckComplexPat, /*CP*/16, /*#*/2, // selectBDXAddr12Only:$XBD2 #3 #4 #5
/*24031*/       OPC_EmitMergeInputChains1_1,
/*24032*/       OPC_MorphNodeTo, TARGET_VAL(SystemZ::SDB), 0|OPFL_Chain|OPFL_MemRefs,
                    2/*#VTs*/, MVT::f64, MVT::i32, 4/*#Ops*/, 0, 3, 4, 5, 
                // Src: (fsub:f64 FP64:f64:$R1src, (ld:f64 bdxaddr12only:i64:$XBD2)<<P:Predicate_unindexedload>><<P:Predicate_load>>) - Complexity = 19
                // Dst: (SDB:f64:i32 FP64:f64:$R1src, bdxaddr12only:i64:$XBD2)
/*24044*/     0, // EndSwitchType
/*24045*/   /*Scope*/ 39, /*->24085*/
/*24046*/     OPC_RecordChild1, // #1 = $R2
/*24047*/     OPC_SwitchType /*3 cases */, 10,  MVT::f32,// ->24060
/*24050*/       OPC_MorphNodeTo, TARGET_VAL(SystemZ::SEBR), 0,
                    2/*#VTs*/, MVT::f32, MVT::i32, 2/*#Ops*/, 0, 1, 
                // Src: (fsub:f32 FP32:f32:$R1src, FP32:f32:$R2) - Complexity = 3
                // Dst: (SEBR:f32:i32 FP32:f32:$R1src, FP32:f32:$R2)
/*24060*/     /*SwitchType*/ 10,  MVT::f64,// ->24072
/*24062*/       OPC_MorphNodeTo, TARGET_VAL(SystemZ::SDBR), 0,
                    2/*#VTs*/, MVT::f64, MVT::i32, 2/*#Ops*/, 0, 1, 
                // Src: (fsub:f64 FP64:f64:$R1src, FP64:f64:$R2) - Complexity = 3
                // Dst: (SDBR:f64:i32 FP64:f64:$R1src, FP64:f64:$R2)
/*24072*/     /*SwitchType*/ 10,  MVT::f128,// ->24084
/*24074*/       OPC_MorphNodeTo, TARGET_VAL(SystemZ::SXBR), 0,
                    2/*#VTs*/, MVT::f128, MVT::i32, 2/*#Ops*/, 0, 1, 
                // Src: (fsub:f128 FP128:f128:$R1src, FP128:f128:$R2) - Complexity = 3
                // Dst: (SXBR:f128:i32 FP128:f128:$R1src, FP128:f128:$R2)
/*24084*/     0, // EndSwitchType
/*24085*/   0, /*End of Scope*/
/*24086*/ /*SwitchOpcode*/ 93,  TARGET_VAL(ISD::FDIV),// ->24182
/*24089*/   OPC_RecordChild0, // #0 = $R1src
/*24090*/   OPC_Scope, 52, /*->24144*/ // 2 children in Scope
/*24092*/     OPC_MoveChild, 1,
/*24094*/     OPC_CheckOpcode, TARGET_VAL(ISD::LOAD),
/*24097*/     OPC_RecordMemRef,
/*24098*/     OPC_RecordNode, // #1 = 'ld' chained node
/*24099*/     OPC_CheckFoldableChainNode,
/*24100*/     OPC_RecordChild1, // #2 = $XBD2
/*24101*/     OPC_CheckChild1Type, MVT::i64,
/*24103*/     OPC_CheckPredicate, 0, // Predicate_unindexedload
/*24105*/     OPC_CheckPredicate, 13, // Predicate_load
/*24107*/     OPC_MoveParent,
/*24108*/     OPC_SwitchType /*2 cases */, 15,  MVT::f32,// ->24126
/*24111*/       OPC_CheckComplexPat, /*CP*/16, /*#*/2, // selectBDXAddr12Only:$XBD2 #3 #4 #5
/*24114*/       OPC_EmitMergeInputChains1_1,
/*24115*/       OPC_MorphNodeTo, TARGET_VAL(SystemZ::DEB), 0|OPFL_Chain|OPFL_MemRefs,
                    1/*#VTs*/, MVT::f32, 4/*#Ops*/, 0, 3, 4, 5, 
                // Src: (fdiv:f32 FP32:f32:$R1src, (ld:f32 bdxaddr12only:i64:$XBD2)<<P:Predicate_unindexedload>><<P:Predicate_load>>) - Complexity = 19
                // Dst: (DEB:f32 FP32:f32:$R1src, bdxaddr12only:i64:$XBD2)
/*24126*/     /*SwitchType*/ 15,  MVT::f64,// ->24143
/*24128*/       OPC_CheckComplexPat, /*CP*/16, /*#*/2, // selectBDXAddr12Only:$XBD2 #3 #4 #5
/*24131*/       OPC_EmitMergeInputChains1_1,
/*24132*/       OPC_MorphNodeTo, TARGET_VAL(SystemZ::DDB), 0|OPFL_Chain|OPFL_MemRefs,
                    1/*#VTs*/, MVT::f64, 4/*#Ops*/, 0, 3, 4, 5, 
                // Src: (fdiv:f64 FP64:f64:$R1src, (ld:f64 bdxaddr12only:i64:$XBD2)<<P:Predicate_unindexedload>><<P:Predicate_load>>) - Complexity = 19
                // Dst: (DDB:f64 FP64:f64:$R1src, bdxaddr12only:i64:$XBD2)
/*24143*/     0, // EndSwitchType
/*24144*/   /*Scope*/ 36, /*->24181*/
/*24145*/     OPC_RecordChild1, // #1 = $R2
/*24146*/     OPC_SwitchType /*3 cases */, 9,  MVT::f32,// ->24158
/*24149*/       OPC_MorphNodeTo, TARGET_VAL(SystemZ::DEBR), 0,
                    1/*#VTs*/, MVT::f32, 2/*#Ops*/, 0, 1, 
                // Src: (fdiv:f32 FP32:f32:$R1src, FP32:f32:$R2) - Complexity = 3
                // Dst: (DEBR:f32 FP32:f32:$R1src, FP32:f32:$R2)
/*24158*/     /*SwitchType*/ 9,  MVT::f64,// ->24169
/*24160*/       OPC_MorphNodeTo, TARGET_VAL(SystemZ::DDBR), 0,
                    1/*#VTs*/, MVT::f64, 2/*#Ops*/, 0, 1, 
                // Src: (fdiv:f64 FP64:f64:$R1src, FP64:f64:$R2) - Complexity = 3
                // Dst: (DDBR:f64 FP64:f64:$R1src, FP64:f64:$R2)
/*24169*/     /*SwitchType*/ 9,  MVT::f128,// ->24180
/*24171*/       OPC_MorphNodeTo, TARGET_VAL(SystemZ::DXBR), 0,
                    1/*#VTs*/, MVT::f128, 2/*#Ops*/, 0, 1, 
                // Src: (fdiv:f128 FP128:f128:$R1src, FP128:f128:$R2) - Complexity = 3
                // Dst: (DXBR:f128 FP128:f128:$R1src, FP128:f128:$R2)
/*24180*/     0, // EndSwitchType
/*24181*/   0, /*End of Scope*/
/*24182*/ /*SwitchOpcode*/ 82,  TARGET_VAL(ISD::FNEG),// ->24267
/*24185*/   OPC_Scope, 42, /*->24229*/ // 2 children in Scope
/*24187*/     OPC_MoveChild, 0,
/*24189*/     OPC_CheckOpcode, TARGET_VAL(ISD::FABS),
/*24192*/     OPC_RecordChild0, // #0 = $R2
/*24193*/     OPC_MoveParent,
/*24194*/     OPC_SwitchType /*3 cases */, 9,  MVT::f32,// ->24206
/*24197*/       OPC_MorphNodeTo, TARGET_VAL(SystemZ::LNEBR), 0,
                    2/*#VTs*/, MVT::f32, MVT::i32, 1/*#Ops*/, 0, 
                // Src: (fneg:f32 (fabs:f32 FP32:f32:$R2)) - Complexity = 6
                // Dst: (LNEBR:f32:i32 FP32:f32:$R2)
/*24206*/     /*SwitchType*/ 9,  MVT::f64,// ->24217
/*24208*/       OPC_MorphNodeTo, TARGET_VAL(SystemZ::LNDBR), 0,
                    2/*#VTs*/, MVT::f64, MVT::i32, 1/*#Ops*/, 0, 
                // Src: (fneg:f64 (fabs:f64 FP64:f64:$R2)) - Complexity = 6
                // Dst: (LNDBR:f64:i32 FP64:f64:$R2)
/*24217*/     /*SwitchType*/ 9,  MVT::f128,// ->24228
/*24219*/       OPC_MorphNodeTo, TARGET_VAL(SystemZ::LNXBR), 0,
                    2/*#VTs*/, MVT::f128, MVT::i32, 1/*#Ops*/, 0, 
                // Src: (fneg:f128 (fabs:f128 FP128:f128:$R2)) - Complexity = 6
                // Dst: (LNXBR:f128:i32 FP128:f128:$R2)
/*24228*/     0, // EndSwitchType
/*24229*/   /*Scope*/ 36, /*->24266*/
/*24230*/     OPC_RecordChild0, // #0 = $R2
/*24231*/     OPC_SwitchType /*3 cases */, 9,  MVT::f32,// ->24243
/*24234*/       OPC_MorphNodeTo, TARGET_VAL(SystemZ::LCEBR), 0,
                    2/*#VTs*/, MVT::f32, MVT::i32, 1/*#Ops*/, 0, 
                // Src: (fneg:f32 FP32:f32:$R2) - Complexity = 3
                // Dst: (LCEBR:f32:i32 FP32:f32:$R2)
/*24243*/     /*SwitchType*/ 9,  MVT::f64,// ->24254
/*24245*/       OPC_MorphNodeTo, TARGET_VAL(SystemZ::LCDBR), 0,
                    2/*#VTs*/, MVT::f64, MVT::i32, 1/*#Ops*/, 0, 
                // Src: (fneg:f64 FP64:f64:$R2) - Complexity = 3
                // Dst: (LCDBR:f64:i32 FP64:f64:$R2)
/*24254*/     /*SwitchType*/ 9,  MVT::f128,// ->24265
/*24256*/       OPC_MorphNodeTo, TARGET_VAL(SystemZ::LCXBR), 0,
                    2/*#VTs*/, MVT::f128, MVT::i32, 1/*#Ops*/, 0, 
                // Src: (fneg:f128 FP128:f128:$R2) - Complexity = 3
                // Dst: (LCXBR:f128:i32 FP128:f128:$R2)
/*24265*/     0, // EndSwitchType
/*24266*/   0, /*End of Scope*/
/*24267*/ /*SwitchOpcode*/ 93,  TARGET_VAL(ISD::ConstantFP),// ->24363
/*24270*/   OPC_Scope, 31, /*->24303*/ // 2 children in Scope
/*24272*/     OPC_CheckPredicate, 74, // Predicate_fpimm0
/*24274*/     OPC_SwitchType /*3 cases */, 7,  MVT::f32,// ->24284
/*24277*/       OPC_MorphNodeTo, TARGET_VAL(SystemZ::LZER), 0,
                    1/*#VTs*/, MVT::f32, 0/*#Ops*/, 
                // Src: (fpimm:f32)<<P:Predicate_fpimm0>> - Complexity = 4
                // Dst: (LZER:f32)
/*24284*/     /*SwitchType*/ 7,  MVT::f64,// ->24293
/*24286*/       OPC_MorphNodeTo, TARGET_VAL(SystemZ::LZDR), 0,
                    1/*#VTs*/, MVT::f64, 0/*#Ops*/, 
                // Src: (fpimm:f64)<<P:Predicate_fpimm0>> - Complexity = 4
                // Dst: (LZDR:f64)
/*24293*/     /*SwitchType*/ 7,  MVT::f128,// ->24302
/*24295*/       OPC_MorphNodeTo, TARGET_VAL(SystemZ::LZXR), 0,
                    1/*#VTs*/, MVT::f128, 0/*#Ops*/, 
                // Src: (fpimm:f128)<<P:Predicate_fpimm0>> - Complexity = 4
                // Dst: (LZXR:f128)
/*24302*/     0, // EndSwitchType
/*24303*/   /*Scope*/ 58, /*->24362*/
/*24304*/     OPC_CheckPredicate, 104, // Predicate_fpimmneg0
/*24306*/     OPC_SwitchType /*3 cases */, 16,  MVT::f32,// ->24325
/*24309*/       OPC_EmitNode, TARGET_VAL(SystemZ::LZER), 0,
                    1/*#VTs*/, MVT::f32, 0/*#Ops*/,  // Results = #0
/*24316*/       OPC_MorphNodeTo, TARGET_VAL(SystemZ::LCEBR), 0,
                    2/*#VTs*/, MVT::f32, MVT::i32, 1/*#Ops*/, 0, 
                // Src: (fpimm:f32)<<P:Predicate_fpimmneg0>> - Complexity = 4
                // Dst: (LCEBR:f32:i32 (LZER:f32))
/*24325*/     /*SwitchType*/ 16,  MVT::f64,// ->24343
/*24327*/       OPC_EmitNode, TARGET_VAL(SystemZ::LZDR), 0,
                    1/*#VTs*/, MVT::f64, 0/*#Ops*/,  // Results = #0
/*24334*/       OPC_MorphNodeTo, TARGET_VAL(SystemZ::LCDBR), 0,
                    2/*#VTs*/, MVT::f64, MVT::i32, 1/*#Ops*/, 0, 
                // Src: (fpimm:f64)<<P:Predicate_fpimmneg0>> - Complexity = 4
                // Dst: (LCDBR:f64:i32 (LZDR:f64))
/*24343*/     /*SwitchType*/ 16,  MVT::f128,// ->24361
/*24345*/       OPC_EmitNode, TARGET_VAL(SystemZ::LZXR), 0,
                    1/*#VTs*/, MVT::f128, 0/*#Ops*/,  // Results = #0
/*24352*/       OPC_MorphNodeTo, TARGET_VAL(SystemZ::LCXBR), 0,
                    2/*#VTs*/, MVT::f128, MVT::i32, 1/*#Ops*/, 0, 
                // Src: (fpimm:f128)<<P:Predicate_fpimmneg0>> - Complexity = 4
                // Dst: (LCXBR:f128:i32 (LZXR:f128))
/*24361*/     0, // EndSwitchType
/*24362*/   0, /*End of Scope*/
/*24363*/ /*SwitchOpcode*/ 101|128,1/*229*/,  TARGET_VAL(ISD::FCOPYSIGN),// ->24596
/*24367*/   OPC_RecordChild0, // #0 = $R3
/*24368*/   OPC_RecordChild1, // #1 = $R2
/*24369*/   OPC_Scope, 62, /*->24433*/ // 3 children in Scope
/*24371*/     OPC_CheckChild1Type, MVT::f32,
/*24373*/     OPC_SwitchType /*3 cases */, 9,  MVT::f32,// ->24385
/*24376*/       OPC_MorphNodeTo, TARGET_VAL(SystemZ::CPSDRss), 0,
                    1/*#VTs*/, MVT::f32, 2/*#Ops*/, 0, 1, 
                // Src: (fcopysign:f32 FP32:f32:$R3, FP32:f32:$R2) - Complexity = 3
                // Dst: (CPSDRss:f32 FP32:f32:$R3, FP32:f32:$R2)
/*24385*/     /*SwitchType*/ 9,  MVT::f64,// ->24396
/*24387*/       OPC_MorphNodeTo, TARGET_VAL(SystemZ::CPSDRds), 0,
                    1/*#VTs*/, MVT::f64, 2/*#Ops*/, 0, 1, 
                // Src: (fcopysign:f64 FP64:f64:$R3, FP32:f32:$R2) - Complexity = 3
                // Dst: (CPSDRds:f64 FP64:f64:$R3, FP32:f32:$R2)
/*24396*/     /*SwitchType*/ 34,  MVT::f128,// ->24432
/*24398*/       OPC_EmitInteger, MVT::i32, SystemZ::subreg_h64,
/*24401*/       OPC_EmitNode, TARGET_VAL(TargetOpcode::EXTRACT_SUBREG), 0,
                    1/*#VTs*/, MVT::f64, 2/*#Ops*/, 0, 2,  // Results = #3
/*24410*/       OPC_EmitNode, TARGET_VAL(SystemZ::CPSDRds), 0,
                    1/*#VTs*/, MVT::f64, 2/*#Ops*/, 3, 1,  // Results = #4
/*24419*/       OPC_EmitInteger, MVT::i32, SystemZ::subreg_h64,
/*24422*/       OPC_MorphNodeTo, TARGET_VAL(TargetOpcode::INSERT_SUBREG), 0,
                    1/*#VTs*/, MVT::f128, 3/*#Ops*/, 0, 4, 5, 
                // Src: (fcopysign:f128 FP128:f128:$src1, FP32:f32:$src2) - Complexity = 3
                // Dst: (INSERT_SUBREG:f128 FP128:f128:$src1, (CPSDRds:f64 (EXTRACT_SUBREG:f64 FP128:f128:$src1, subreg_h64:i32), FP32:f32:$src2), subreg_h64:i32)
/*24432*/     0, // EndSwitchType
/*24433*/   /*Scope*/ 62, /*->24496*/
/*24434*/     OPC_CheckChild1Type, MVT::f64,
/*24436*/     OPC_SwitchType /*3 cases */, 9,  MVT::f32,// ->24448
/*24439*/       OPC_MorphNodeTo, TARGET_VAL(SystemZ::CPSDRsd), 0,
                    1/*#VTs*/, MVT::f32, 2/*#Ops*/, 0, 1, 
                // Src: (fcopysign:f32 FP32:f32:$R3, FP64:f64:$R2) - Complexity = 3
                // Dst: (CPSDRsd:f32 FP32:f32:$R3, FP64:f64:$R2)
/*24448*/     /*SwitchType*/ 9,  MVT::f64,// ->24459
/*24450*/       OPC_MorphNodeTo, TARGET_VAL(SystemZ::CPSDRdd), 0,
                    1/*#VTs*/, MVT::f64, 2/*#Ops*/, 0, 1, 
                // Src: (fcopysign:f64 FP64:f64:$R3, FP64:f64:$R2) - Complexity = 3
                // Dst: (CPSDRdd:f64 FP64:f64:$R3, FP64:f64:$R2)
/*24459*/     /*SwitchType*/ 34,  MVT::f128,// ->24495
/*24461*/       OPC_EmitInteger, MVT::i32, SystemZ::subreg_h64,
/*24464*/       OPC_EmitNode, TARGET_VAL(TargetOpcode::EXTRACT_SUBREG), 0,
                    1/*#VTs*/, MVT::f64, 2/*#Ops*/, 0, 2,  // Results = #3
/*24473*/       OPC_EmitNode, TARGET_VAL(SystemZ::CPSDRdd), 0,
                    1/*#VTs*/, MVT::f64, 2/*#Ops*/, 3, 1,  // Results = #4
/*24482*/       OPC_EmitInteger, MVT::i32, SystemZ::subreg_h64,
/*24485*/       OPC_MorphNodeTo, TARGET_VAL(TargetOpcode::INSERT_SUBREG), 0,
                    1/*#VTs*/, MVT::f128, 3/*#Ops*/, 0, 4, 5, 
                // Src: (fcopysign:f128 FP128:f128:$src1, FP64:f64:$src2) - Complexity = 3
                // Dst: (INSERT_SUBREG:f128 FP128:f128:$src1, (CPSDRdd:f64 (EXTRACT_SUBREG:f64 FP128:f128:$src1, subreg_h64:i32), FP64:f64:$src2), subreg_h64:i32)
/*24495*/     0, // EndSwitchType
/*24496*/   /*Scope*/ 98, /*->24595*/
/*24497*/     OPC_CheckChild1Type, MVT::f128,
/*24499*/     OPC_SwitchType /*3 cases */, 21,  MVT::f32,// ->24523
/*24502*/       OPC_EmitInteger, MVT::i32, SystemZ::subreg_h64,
/*24505*/       OPC_EmitNode, TARGET_VAL(TargetOpcode::EXTRACT_SUBREG), 0,
                    1/*#VTs*/, MVT::f64, 2/*#Ops*/, 1, 2,  // Results = #3
/*24514*/       OPC_MorphNodeTo, TARGET_VAL(SystemZ::CPSDRsd), 0,
                    1/*#VTs*/, MVT::f32, 2/*#Ops*/, 0, 3, 
                // Src: (fcopysign:f32 FP32:f32:$src1, FP128:f128:$src2) - Complexity = 3
                // Dst: (CPSDRsd:f32 FP32:f32:$src1, (EXTRACT_SUBREG:f64 FP128:f128:$src2, subreg_h64:i32))
/*24523*/     /*SwitchType*/ 21,  MVT::f64,// ->24546
/*24525*/       OPC_EmitInteger, MVT::i32, SystemZ::subreg_h64,
/*24528*/       OPC_EmitNode, TARGET_VAL(TargetOpcode::EXTRACT_SUBREG), 0,
                    1/*#VTs*/, MVT::f64, 2/*#Ops*/, 1, 2,  // Results = #3
/*24537*/       OPC_MorphNodeTo, TARGET_VAL(SystemZ::CPSDRdd), 0,
                    1/*#VTs*/, MVT::f64, 2/*#Ops*/, 0, 3, 
                // Src: (fcopysign:f64 FP64:f64:$src1, FP128:f128:$src2) - Complexity = 3
                // Dst: (CPSDRdd:f64 FP64:f64:$src1, (EXTRACT_SUBREG:f64 FP128:f128:$src2, subreg_h64:i32))
/*24546*/     /*SwitchType*/ 46,  MVT::f128,// ->24594
/*24548*/       OPC_EmitInteger, MVT::i32, SystemZ::subreg_h64,
/*24551*/       OPC_EmitNode, TARGET_VAL(TargetOpcode::EXTRACT_SUBREG), 0,
                    1/*#VTs*/, MVT::f64, 2/*#Ops*/, 0, 2,  // Results = #3
/*24560*/       OPC_EmitInteger, MVT::i32, SystemZ::subreg_h64,
/*24563*/       OPC_EmitNode, TARGET_VAL(TargetOpcode::EXTRACT_SUBREG), 0,
                    1/*#VTs*/, MVT::f64, 2/*#Ops*/, 1, 4,  // Results = #5
/*24572*/       OPC_EmitNode, TARGET_VAL(SystemZ::CPSDRdd), 0,
                    1/*#VTs*/, MVT::f64, 2/*#Ops*/, 3, 5,  // Results = #6
/*24581*/       OPC_EmitInteger, MVT::i32, SystemZ::subreg_h64,
/*24584*/       OPC_MorphNodeTo, TARGET_VAL(TargetOpcode::INSERT_SUBREG), 0,
                    1/*#VTs*/, MVT::f128, 3/*#Ops*/, 0, 6, 7, 
                // Src: (fcopysign:f128 FP128:f128:$src1, FP128:f128:$src2) - Complexity = 3
                // Dst: (INSERT_SUBREG:f128 FP128:f128:$src1, (CPSDRdd:f64 (EXTRACT_SUBREG:f64 FP128:f128:$src1, subreg_h64:i32), (EXTRACT_SUBREG:f64 FP128:f128:$src2, subreg_h64:i32)), subreg_h64:i32)
/*24594*/     0, // EndSwitchType
/*24595*/   0, /*End of Scope*/
/*24596*/ /*SwitchOpcode*/ 63,  TARGET_VAL(ISD::FP_ROUND),// ->24662
/*24599*/   OPC_RecordChild0, // #0 = $R2
/*24600*/   OPC_SwitchType /*2 cases */, 36,  MVT::f32,// ->24639
/*24603*/     OPC_Scope, 10, /*->24615*/ // 2 children in Scope
/*24605*/       OPC_CheckChild0Type, MVT::f64,
/*24607*/       OPC_MorphNodeTo, TARGET_VAL(SystemZ::LEDBR), 0,
                    1/*#VTs*/, MVT::f32, 1/*#Ops*/, 0, 
                // Src: (fround:f32 FP64:f64:$R2) - Complexity = 3
                // Dst: (LEDBR:f32 FP64:f64:$R2)
/*24615*/     /*Scope*/ 22, /*->24638*/
/*24616*/       OPC_CheckChild0Type, MVT::f128,
/*24618*/       OPC_EmitNode, TARGET_VAL(SystemZ::LEXBR), 0,
                    1/*#VTs*/, MVT::f128, 1/*#Ops*/, 0,  // Results = #1
/*24626*/       OPC_EmitInteger, MVT::i32, SystemZ::subreg_hh32,
/*24629*/       OPC_MorphNodeTo, TARGET_VAL(TargetOpcode::EXTRACT_SUBREG), 0,
                    1/*#VTs*/, MVT::f32, 2/*#Ops*/, 1, 2, 
                // Src: (fround:f32 FP128:f128:$src) - Complexity = 3
                // Dst: (EXTRACT_SUBREG:f32 (LEXBR:f128 FP128:f128:$src), subreg_hh32:i32)
/*24638*/     0, /*End of Scope*/
/*24639*/   /*SwitchType*/ 20,  MVT::f64,// ->24661
/*24641*/     OPC_EmitNode, TARGET_VAL(SystemZ::LDXBR), 0,
                  1/*#VTs*/, MVT::f128, 1/*#Ops*/, 0,  // Results = #1
/*24649*/     OPC_EmitInteger, MVT::i32, SystemZ::subreg_h64,
/*24652*/     OPC_MorphNodeTo, TARGET_VAL(TargetOpcode::EXTRACT_SUBREG), 0,
                  1/*#VTs*/, MVT::f64, 2/*#Ops*/, 1, 2, 
              // Src: (fround:f64 FP128:f128:$src) - Complexity = 3
              // Dst: (EXTRACT_SUBREG:f64 (LDXBR:f128 FP128:f128:$src), subreg_h64:i32)
/*24661*/   0, // EndSwitchType
/*24662*/ /*SwitchOpcode*/ 39,  TARGET_VAL(ISD::FP_EXTEND),// ->24704
/*24665*/   OPC_RecordChild0, // #0 = $R2
/*24666*/   OPC_SwitchType /*2 cases */, 8,  MVT::f64,// ->24677
/*24669*/     OPC_MorphNodeTo, TARGET_VAL(SystemZ::LDEBR), 0,
                  1/*#VTs*/, MVT::f64, 1/*#Ops*/, 0, 
              // Src: (fextend:f64 FP32:f32:$R2) - Complexity = 3
              // Dst: (LDEBR:f64 FP32:f32:$R2)
/*24677*/   /*SwitchType*/ 24,  MVT::f128,// ->24703
/*24679*/     OPC_Scope, 10, /*->24691*/ // 2 children in Scope
/*24681*/       OPC_CheckChild0Type, MVT::f32,
/*24683*/       OPC_MorphNodeTo, TARGET_VAL(SystemZ::LXEBR), 0,
                    1/*#VTs*/, MVT::f128, 1/*#Ops*/, 0, 
                // Src: (fextend:f128 FP32:f32:$R2) - Complexity = 3
                // Dst: (LXEBR:f128 FP32:f32:$R2)
/*24691*/     /*Scope*/ 10, /*->24702*/
/*24692*/       OPC_CheckChild0Type, MVT::f64,
/*24694*/       OPC_MorphNodeTo, TARGET_VAL(SystemZ::LXDBR), 0,
                    1/*#VTs*/, MVT::f128, 1/*#Ops*/, 0, 
                // Src: (fextend:f128 FP64:f64:$R2) - Complexity = 3
                // Dst: (LXDBR:f128 FP64:f64:$R2)
/*24702*/     0, /*End of Scope*/
/*24703*/   0, // EndSwitchType
/*24704*/ /*SwitchOpcode*/ 73,  TARGET_VAL(ISD::SINT_TO_FP),// ->24780
/*24707*/   OPC_RecordChild0, // #0 = $R2
/*24708*/   OPC_Scope, 34, /*->24744*/ // 2 children in Scope
/*24710*/     OPC_CheckChild0Type, MVT::i32,
/*24712*/     OPC_SwitchType /*3 cases */, 8,  MVT::f32,// ->24723
/*24715*/       OPC_MorphNodeTo, TARGET_VAL(SystemZ::CEFBR), 0,
                    1/*#VTs*/, MVT::f32, 1/*#Ops*/, 0, 
                // Src: (sint_to_fp:f32 GR32:i32:$R2) - Complexity = 3
                // Dst: (CEFBR:f32 GR32:i32:$R2)
/*24723*/     /*SwitchType*/ 8,  MVT::f64,// ->24733
/*24725*/       OPC_MorphNodeTo, TARGET_VAL(SystemZ::CDFBR), 0,
                    1/*#VTs*/, MVT::f64, 1/*#Ops*/, 0, 
                // Src: (sint_to_fp:f64 GR32:i32:$R2) - Complexity = 3
                // Dst: (CDFBR:f64 GR32:i32:$R2)
/*24733*/     /*SwitchType*/ 8,  MVT::f128,// ->24743
/*24735*/       OPC_MorphNodeTo, TARGET_VAL(SystemZ::CXFBR), 0,
                    1/*#VTs*/, MVT::f128, 1/*#Ops*/, 0, 
                // Src: (sint_to_fp:f128 GR32:i32:$R2) - Complexity = 3
                // Dst: (CXFBR:f128 GR32:i32:$R2)
/*24743*/     0, // EndSwitchType
/*24744*/   /*Scope*/ 34, /*->24779*/
/*24745*/     OPC_CheckChild0Type, MVT::i64,
/*24747*/     OPC_SwitchType /*3 cases */, 8,  MVT::f32,// ->24758
/*24750*/       OPC_MorphNodeTo, TARGET_VAL(SystemZ::CEGBR), 0,
                    1/*#VTs*/, MVT::f32, 1/*#Ops*/, 0, 
                // Src: (sint_to_fp:f32 GR64:i64:$R2) - Complexity = 3
                // Dst: (CEGBR:f32 GR64:i64:$R2)
/*24758*/     /*SwitchType*/ 8,  MVT::f64,// ->24768
/*24760*/       OPC_MorphNodeTo, TARGET_VAL(SystemZ::CDGBR), 0,
                    1/*#VTs*/, MVT::f64, 1/*#Ops*/, 0, 
                // Src: (sint_to_fp:f64 GR64:i64:$R2) - Complexity = 3
                // Dst: (CDGBR:f64 GR64:i64:$R2)
/*24768*/     /*SwitchType*/ 8,  MVT::f128,// ->24778
/*24770*/       OPC_MorphNodeTo, TARGET_VAL(SystemZ::CXGBR), 0,
                    1/*#VTs*/, MVT::f128, 1/*#Ops*/, 0, 
                // Src: (sint_to_fp:f128 GR64:i64:$R2) - Complexity = 3
                // Dst: (CXGBR:f128 GR64:i64:$R2)
/*24778*/     0, // EndSwitchType
/*24779*/   0, /*End of Scope*/
/*24780*/ /*SwitchOpcode*/ 36,  TARGET_VAL(ISD::FABS),// ->24819
/*24783*/   OPC_RecordChild0, // #0 = $R2
/*24784*/   OPC_SwitchType /*3 cases */, 9,  MVT::f32,// ->24796
/*24787*/     OPC_MorphNodeTo, TARGET_VAL(SystemZ::LPEBR), 0,
                  2/*#VTs*/, MVT::f32, MVT::i32, 1/*#Ops*/, 0, 
              // Src: (fabs:f32 FP32:f32:$R2) - Complexity = 3
              // Dst: (LPEBR:f32:i32 FP32:f32:$R2)
/*24796*/   /*SwitchType*/ 9,  MVT::f64,// ->24807
/*24798*/     OPC_MorphNodeTo, TARGET_VAL(SystemZ::LPDBR), 0,
                  2/*#VTs*/, MVT::f64, MVT::i32, 1/*#Ops*/, 0, 
              // Src: (fabs:f64 FP64:f64:$R2) - Complexity = 3
              // Dst: (LPDBR:f64:i32 FP64:f64:$R2)
/*24807*/   /*SwitchType*/ 9,  MVT::f128,// ->24818
/*24809*/     OPC_MorphNodeTo, TARGET_VAL(SystemZ::LPXBR), 0,
                  2/*#VTs*/, MVT::f128, MVT::i32, 1/*#Ops*/, 0, 
              // Src: (fabs:f128 FP128:f128:$R2) - Complexity = 3
              // Dst: (LPXBR:f128:i32 FP128:f128:$R2)
/*24818*/   0, // EndSwitchType
/*24819*/ /*SwitchOpcode*/ 45,  TARGET_VAL(ISD::FRINT),// ->24867
/*24822*/   OPC_RecordChild0, // #0 = $src
/*24823*/   OPC_SwitchType /*3 cases */, 12,  MVT::f32,// ->24838
/*24826*/     OPC_EmitInteger, MVT::i8, 0, 
/*24829*/     OPC_MorphNodeTo, TARGET_VAL(SystemZ::FIEBR), 0,
                  1/*#VTs*/, MVT::f32, 2/*#Ops*/, 1, 0, 
              // Src: (frint:f32 FP32:f32:$src) - Complexity = 3
              // Dst: (FIEBR:f32 0:i8, FP32:f32:$src)
/*24838*/   /*SwitchType*/ 12,  MVT::f64,// ->24852
/*24840*/     OPC_EmitInteger, MVT::i8, 0, 
/*24843*/     OPC_MorphNodeTo, TARGET_VAL(SystemZ::FIDBR), 0,
                  1/*#VTs*/, MVT::f64, 2/*#Ops*/, 1, 0, 
              // Src: (frint:f64 FP64:f64:$src) - Complexity = 3
              // Dst: (FIDBR:f64 0:i8, FP64:f64:$src)
/*24852*/   /*SwitchType*/ 12,  MVT::f128,// ->24866
/*24854*/     OPC_EmitInteger, MVT::i8, 0, 
/*24857*/     OPC_MorphNodeTo, TARGET_VAL(SystemZ::FIXBR), 0,
                  1/*#VTs*/, MVT::f128, 2/*#Ops*/, 1, 0, 
              // Src: (frint:f128 FP128:f128:$src) - Complexity = 3
              // Dst: (FIXBR:f128 0:i8, FP128:f128:$src)
/*24866*/   0, // EndSwitchType
/*24867*/ /*SwitchOpcode*/ 63,  TARGET_VAL(ISD::FNEARBYINT),// ->24933
/*24870*/   OPC_RecordChild0, // #0 = $src
/*24871*/   OPC_SwitchType /*3 cases */, 18,  MVT::f32,// ->24892
/*24874*/     OPC_CheckPatternPredicate, 3, // (Subtarget.hasFPExtension())
/*24876*/     OPC_EmitInteger, MVT::i8, 0, 
/*24879*/     OPC_EmitInteger, MVT::i8, 4, 
/*24882*/     OPC_MorphNodeTo, TARGET_VAL(SystemZ::FIEBRA), 0,
                  1/*#VTs*/, MVT::f32, 3/*#Ops*/, 1, 0, 2, 
              // Src: (fnearbyint:f32 FP32:f32:$src) - Complexity = 3
              // Dst: (FIEBRA:f32 0:i8, FP32:f32:$src, 4:i8)
/*24892*/   /*SwitchType*/ 18,  MVT::f64,// ->24912
/*24894*/     OPC_CheckPatternPredicate, 3, // (Subtarget.hasFPExtension())
/*24896*/     OPC_EmitInteger, MVT::i8, 0, 
/*24899*/     OPC_EmitInteger, MVT::i8, 4, 
/*24902*/     OPC_MorphNodeTo, TARGET_VAL(SystemZ::FIDBRA), 0,
                  1/*#VTs*/, MVT::f64, 3/*#Ops*/, 1, 0, 2, 
              // Src: (fnearbyint:f64 FP64:f64:$src) - Complexity = 3
              // Dst: (FIDBRA:f64 0:i8, FP64:f64:$src, 4:i8)
/*24912*/   /*SwitchType*/ 18,  MVT::f128,// ->24932
/*24914*/     OPC_CheckPatternPredicate, 3, // (Subtarget.hasFPExtension())
/*24916*/     OPC_EmitInteger, MVT::i8, 0, 
/*24919*/     OPC_EmitInteger, MVT::i8, 4, 
/*24922*/     OPC_MorphNodeTo, TARGET_VAL(SystemZ::FIXBRA), 0,
                  1/*#VTs*/, MVT::f128, 3/*#Ops*/, 1, 0, 2, 
              // Src: (fnearbyint:f128 FP128:f128:$src) - Complexity = 3
              // Dst: (FIXBRA:f128 0:i8, FP128:f128:$src, 4:i8)
/*24932*/   0, // EndSwitchType
/*24933*/ /*SwitchOpcode*/ 63,  TARGET_VAL(ISD::FFLOOR),// ->24999
/*24936*/   OPC_RecordChild0, // #0 = $src
/*24937*/   OPC_SwitchType /*3 cases */, 18,  MVT::f32,// ->24958
/*24940*/     OPC_CheckPatternPredicate, 3, // (Subtarget.hasFPExtension())
/*24942*/     OPC_EmitInteger, MVT::i8, 7, 
/*24945*/     OPC_EmitInteger, MVT::i8, 4, 
/*24948*/     OPC_MorphNodeTo, TARGET_VAL(SystemZ::FIEBRA), 0,
                  1/*#VTs*/, MVT::f32, 3/*#Ops*/, 1, 0, 2, 
              // Src: (ffloor:f32 FP32:f32:$src) - Complexity = 3
              // Dst: (FIEBRA:f32 7:i8, FP32:f32:$src, 4:i8)
/*24958*/   /*SwitchType*/ 18,  MVT::f64,// ->24978
/*24960*/     OPC_CheckPatternPredicate, 3, // (Subtarget.hasFPExtension())
/*24962*/     OPC_EmitInteger, MVT::i8, 7, 
/*24965*/     OPC_EmitInteger, MVT::i8, 4, 
/*24968*/     OPC_MorphNodeTo, TARGET_VAL(SystemZ::FIDBRA), 0,
                  1/*#VTs*/, MVT::f64, 3/*#Ops*/, 1, 0, 2, 
              // Src: (ffloor:f64 FP64:f64:$src) - Complexity = 3
              // Dst: (FIDBRA:f64 7:i8, FP64:f64:$src, 4:i8)
/*24978*/   /*SwitchType*/ 18,  MVT::f128,// ->24998
/*24980*/     OPC_CheckPatternPredicate, 3, // (Subtarget.hasFPExtension())
/*24982*/     OPC_EmitInteger, MVT::i8, 7, 
/*24985*/     OPC_EmitInteger, MVT::i8, 4, 
/*24988*/     OPC_MorphNodeTo, TARGET_VAL(SystemZ::FIXBRA), 0,
                  1/*#VTs*/, MVT::f128, 3/*#Ops*/, 1, 0, 2, 
              // Src: (ffloor:f128 FP128:f128:$src) - Complexity = 3
              // Dst: (FIXBRA:f128 7:i8, FP128:f128:$src, 4:i8)
/*24998*/   0, // EndSwitchType
/*24999*/ /*SwitchOpcode*/ 63,  TARGET_VAL(ISD::FCEIL),// ->25065
/*25002*/   OPC_RecordChild0, // #0 = $src
/*25003*/   OPC_SwitchType /*3 cases */, 18,  MVT::f32,// ->25024
/*25006*/     OPC_CheckPatternPredicate, 3, // (Subtarget.hasFPExtension())
/*25008*/     OPC_EmitInteger, MVT::i8, 6, 
/*25011*/     OPC_EmitInteger, MVT::i8, 4, 
/*25014*/     OPC_MorphNodeTo, TARGET_VAL(SystemZ::FIEBRA), 0,
                  1/*#VTs*/, MVT::f32, 3/*#Ops*/, 1, 0, 2, 
              // Src: (fceil:f32 FP32:f32:$src) - Complexity = 3
              // Dst: (FIEBRA:f32 6:i8, FP32:f32:$src, 4:i8)
/*25024*/   /*SwitchType*/ 18,  MVT::f64,// ->25044
/*25026*/     OPC_CheckPatternPredicate, 3, // (Subtarget.hasFPExtension())
/*25028*/     OPC_EmitInteger, MVT::i8, 6, 
/*25031*/     OPC_EmitInteger, MVT::i8, 4, 
/*25034*/     OPC_MorphNodeTo, TARGET_VAL(SystemZ::FIDBRA), 0,
                  1/*#VTs*/, MVT::f64, 3/*#Ops*/, 1, 0, 2, 
              // Src: (fceil:f64 FP64:f64:$src) - Complexity = 3
              // Dst: (FIDBRA:f64 6:i8, FP64:f64:$src, 4:i8)
/*25044*/   /*SwitchType*/ 18,  MVT::f128,// ->25064
/*25046*/     OPC_CheckPatternPredicate, 3, // (Subtarget.hasFPExtension())
/*25048*/     OPC_EmitInteger, MVT::i8, 6, 
/*25051*/     OPC_EmitInteger, MVT::i8, 4, 
/*25054*/     OPC_MorphNodeTo, TARGET_VAL(SystemZ::FIXBRA), 0,
                  1/*#VTs*/, MVT::f128, 3/*#Ops*/, 1, 0, 2, 
              // Src: (fceil:f128 FP128:f128:$src) - Complexity = 3
              // Dst: (FIXBRA:f128 6:i8, FP128:f128:$src, 4:i8)
/*25064*/   0, // EndSwitchType
/*25065*/ /*SwitchOpcode*/ 63,  TARGET_VAL(ISD::FTRUNC),// ->25131
/*25068*/   OPC_RecordChild0, // #0 = $src
/*25069*/   OPC_SwitchType /*3 cases */, 18,  MVT::f32,// ->25090
/*25072*/     OPC_CheckPatternPredicate, 3, // (Subtarget.hasFPExtension())
/*25074*/     OPC_EmitInteger, MVT::i8, 5, 
/*25077*/     OPC_EmitInteger, MVT::i8, 4, 
/*25080*/     OPC_MorphNodeTo, TARGET_VAL(SystemZ::FIEBRA), 0,
                  1/*#VTs*/, MVT::f32, 3/*#Ops*/, 1, 0, 2, 
              // Src: (ftrunc:f32 FP32:f32:$src) - Complexity = 3
              // Dst: (FIEBRA:f32 5:i8, FP32:f32:$src, 4:i8)
/*25090*/   /*SwitchType*/ 18,  MVT::f64,// ->25110
/*25092*/     OPC_CheckPatternPredicate, 3, // (Subtarget.hasFPExtension())
/*25094*/     OPC_EmitInteger, MVT::i8, 5, 
/*25097*/     OPC_EmitInteger, MVT::i8, 4, 
/*25100*/     OPC_MorphNodeTo, TARGET_VAL(SystemZ::FIDBRA), 0,
                  1/*#VTs*/, MVT::f64, 3/*#Ops*/, 1, 0, 2, 
              // Src: (ftrunc:f64 FP64:f64:$src) - Complexity = 3
              // Dst: (FIDBRA:f64 5:i8, FP64:f64:$src, 4:i8)
/*25110*/   /*SwitchType*/ 18,  MVT::f128,// ->25130
/*25112*/     OPC_CheckPatternPredicate, 3, // (Subtarget.hasFPExtension())
/*25114*/     OPC_EmitInteger, MVT::i8, 5, 
/*25117*/     OPC_EmitInteger, MVT::i8, 4, 
/*25120*/     OPC_MorphNodeTo, TARGET_VAL(SystemZ::FIXBRA), 0,
                  1/*#VTs*/, MVT::f128, 3/*#Ops*/, 1, 0, 2, 
              // Src: (ftrunc:f128 FP128:f128:$src) - Complexity = 3
              // Dst: (FIXBRA:f128 5:i8, FP128:f128:$src, 4:i8)
/*25130*/   0, // EndSwitchType
/*25131*/ /*SwitchOpcode*/ 63,  TARGET_VAL(ISD::FROUND),// ->25197
/*25134*/   OPC_RecordChild0, // #0 = $src
/*25135*/   OPC_SwitchType /*3 cases */, 18,  MVT::f32,// ->25156
/*25138*/     OPC_CheckPatternPredicate, 3, // (Subtarget.hasFPExtension())
/*25140*/     OPC_EmitInteger, MVT::i8, 1, 
/*25143*/     OPC_EmitInteger, MVT::i8, 4, 
/*25146*/     OPC_MorphNodeTo, TARGET_VAL(SystemZ::FIEBRA), 0,
                  1/*#VTs*/, MVT::f32, 3/*#Ops*/, 1, 0, 2, 
              // Src: (frnd:f32 FP32:f32:$src) - Complexity = 3
              // Dst: (FIEBRA:f32 1:i8, FP32:f32:$src, 4:i8)
/*25156*/   /*SwitchType*/ 18,  MVT::f64,// ->25176
/*25158*/     OPC_CheckPatternPredicate, 3, // (Subtarget.hasFPExtension())
/*25160*/     OPC_EmitInteger, MVT::i8, 1, 
/*25163*/     OPC_EmitInteger, MVT::i8, 4, 
/*25166*/     OPC_MorphNodeTo, TARGET_VAL(SystemZ::FIDBRA), 0,
                  1/*#VTs*/, MVT::f64, 3/*#Ops*/, 1, 0, 2, 
              // Src: (frnd:f64 FP64:f64:$src) - Complexity = 3
              // Dst: (FIDBRA:f64 1:i8, FP64:f64:$src, 4:i8)
/*25176*/   /*SwitchType*/ 18,  MVT::f128,// ->25196
/*25178*/     OPC_CheckPatternPredicate, 3, // (Subtarget.hasFPExtension())
/*25180*/     OPC_EmitInteger, MVT::i8, 1, 
/*25183*/     OPC_EmitInteger, MVT::i8, 4, 
/*25186*/     OPC_MorphNodeTo, TARGET_VAL(SystemZ::FIXBRA), 0,
                  1/*#VTs*/, MVT::f128, 3/*#Ops*/, 1, 0, 2, 
              // Src: (frnd:f128 FP128:f128:$src) - Complexity = 3
              // Dst: (FIXBRA:f128 1:i8, FP128:f128:$src, 4:i8)
/*25196*/   0, // EndSwitchType
/*25197*/ 0, // EndSwitchOpcode
    0
  }; // Total Array size is 25199 bytes

  // Opcode Histogram:
  // #OPC_Scope                          = 230
  // #OPC_RecordNode                     = 226
  // #OPC_RecordChild                    = 684
  // #OPC_RecordMemRef                   = 197
  // #OPC_CaptureGlueInput               = 12
  // #OPC_MoveChild                      = 562
  // #OPC_MoveParent                     = 991
  // #OPC_CheckSame                      = 0
  // #OPC_CheckChildSame                 = 176
  // #OPC_CheckPatternPredicate          = 66
  // #OPC_CheckPredicate                 = 1205
  // #OPC_CheckOpcode                    = 442
  // #OPC_SwitchOpcode                   = 24
  // #OPC_CheckType                      = 368
  // #OPC_SwitchType                     = 92
  // #OPC_CheckChildType                 = 296
  // #OPC_CheckInteger                   = 68
  // #OPC_CheckCondCode                  = 0
  // #OPC_CheckValueType                 = 32
  // #OPC_CheckComplexPat                = 589
  // #OPC_CheckAndImm                    = 26
  // #OPC_CheckOrImm                     = 0
  // #OPC_CheckFoldableChainNode         = 168
  // #OPC_EmitInteger                    = 137
  // #OPC_EmitStringInteger              = 59
  // #OPC_EmitRegister                   = 0
  // #OPC_EmitConvertToTarget            = 258
  // #OPC_EmitMergeInputChains           = 471
  // #OPC_EmitCopyToReg                  = 1
  // #OPC_EmitNode                       = 72
  // #OPC_EmitNodeXForm                  = 179
  // #OPC_MarkGlueResults                = 0
  // #OPC_CompleteMatch                  = 0
  // #OPC_MorphNodeTo                    = 805

  #undef TARGET_VAL
  return SelectCodeCommon(N, MatcherTable,sizeof(MatcherTable));
}

virtual bool CheckPatternPredicate(unsigned PredNo) const {
  switch (PredNo) {
  default: llvm_unreachable("Invalid predicate in table?");
  case 0: return (Subtarget.hasHighWord());
  case 1: return (Subtarget.hasLoadStoreOnCond());
  case 2: return (Subtarget.hasDistinctOps());
  case 3: return (Subtarget.hasFPExtension());
  }
}

virtual bool CheckNodePredicate(SDNode *Node,
                                unsigned PredNo) const {
  switch (PredNo) {
  default: llvm_unreachable("Invalid predicate in table?");
  case 0: { // Predicate_unindexedload
    SDNode *N = Node;

  return cast<LoadSDNode>(N)->getAddressingMode() == ISD::UNINDEXED;

  }
  case 1: { // Predicate_anyextload
    SDNode *N = Node;

  return cast<LoadSDNode>(N)->getExtensionType() != ISD::NON_EXTLOAD;

  }
  case 2: { // Predicate_anyextloadi8
    SDNode *N = Node;

  return cast<LoadSDNode>(N)->getMemoryVT() == MVT::i8;

  }
  case 3: { // Predicate_nonvolatile_anyextloadi8
    SDNode *N = Node;

  LoadSDNode *Load = cast<LoadSDNode>(N);
  return !Load->isVolatile();

  }
  case 4: { // Predicate_uimm8zx4
    ConstantSDNode*N = cast<ConstantSDNode>(Node);

  return isUInt<4>(N->getZExtValue());

  }
  case 5: { // Predicate_unindexedstore
    SDNode *N = Node;

  return cast<StoreSDNode>(N)->getAddressingMode() == ISD::UNINDEXED;

  }
  case 6: { // Predicate_truncstore
    SDNode *N = Node;

  return cast<StoreSDNode>(N)->isTruncatingStore();

  }
  case 7: { // Predicate_truncstorei8
    SDNode *N = Node;

  return cast<StoreSDNode>(N)->getMemoryVT() == MVT::i8;

  }
  case 8: { // Predicate_nonvolatile_truncstorei8
    SDNode *N = Node;

  StoreSDNode *Store = cast<StoreSDNode>(N);
  return !Store->isVolatile();

  }
  case 9: { // Predicate_anyextloadi16
    SDNode *N = Node;

  return cast<LoadSDNode>(N)->getMemoryVT() == MVT::i16;

  }
  case 10: { // Predicate_nonvolatile_anyextloadi16
    SDNode *N = Node;

  LoadSDNode *Load = cast<LoadSDNode>(N);
  return !Load->isVolatile();

  }
  case 11: { // Predicate_truncstorei16
    SDNode *N = Node;

  return cast<StoreSDNode>(N)->getMemoryVT() == MVT::i16;

  }
  case 12: { // Predicate_nonvolatile_truncstorei16
    SDNode *N = Node;

  StoreSDNode *Store = cast<StoreSDNode>(N);
  return !Store->isVolatile();

  }
  case 13: { // Predicate_load
    SDNode *N = Node;

  return cast<LoadSDNode>(N)->getExtensionType() == ISD::NON_EXTLOAD;

  }
  case 14: { // Predicate_nonvolatile_load
    SDNode *N = Node;

  LoadSDNode *Load = cast<LoadSDNode>(N);
  return !Load->isVolatile();

  }
  case 15: { // Predicate_store
    SDNode *N = Node;

  return !cast<StoreSDNode>(N)->isTruncatingStore();

  }
  case 16: { // Predicate_nonvolatile_store
    SDNode *N = Node;

  StoreSDNode *Store = cast<StoreSDNode>(N);
  return !Store->isVolatile();

  }
  case 17: { // Predicate_anyextloadi32
    SDNode *N = Node;

  return cast<LoadSDNode>(N)->getMemoryVT() == MVT::i32;

  }
  case 18: { // Predicate_nonvolatile_anyextloadi32
    SDNode *N = Node;

  LoadSDNode *Load = cast<LoadSDNode>(N);
  return !Load->isVolatile();

  }
  case 19: { // Predicate_truncstorei32
    SDNode *N = Node;

  return cast<StoreSDNode>(N)->getMemoryVT() == MVT::i32;

  }
  case 20: { // Predicate_nonvolatile_truncstorei32
    SDNode *N = Node;

  StoreSDNode *Store = cast<StoreSDNode>(N);
  return !Store->isVolatile();

  }
  case 21: { // Predicate_block_and1
    SDNode *N = Node;
 return storeLoadCanUseBlockBinary(N, 0); 
  }
  case 22: { // Predicate_block_and2
    SDNode *N = Node;
 return storeLoadCanUseBlockBinary(N, 1); 
  }
  case 23: { // Predicate_block_or1
    SDNode *N = Node;
 return storeLoadCanUseBlockBinary(N, 0); 
  }
  case 24: { // Predicate_block_or2
    SDNode *N = Node;
 return storeLoadCanUseBlockBinary(N, 1); 
  }
  case 25: { // Predicate_block_xor1
    SDNode *N = Node;
 return storeLoadCanUseBlockBinary(N, 0); 
  }
  case 26: { // Predicate_block_xor2
    SDNode *N = Node;
 return storeLoadCanUseBlockBinary(N, 1); 
  }
  case 27: { // Predicate_imm32sx8
    ConstantSDNode*N = cast<ConstantSDNode>(Node);

  return isInt<8>(N->getSExtValue());

  }
  case 28: { // Predicate_imm64sx8
    ConstantSDNode*N = cast<ConstantSDNode>(Node);

  return isInt<8>(N->getSExtValue());

  }
  case 29: { // Predicate_mvc_store
    SDNode *N = Node;
 return storeLoadCanUseMVC(N); 
  }
  case 30: { // Predicate_aligned_store
    SDNode *N = Node;

  StoreSDNode *Store = cast<StoreSDNode>(N);
  return Store->getAlignment() >= Store->getMemoryVT().getStoreSize();

  }
  case 31: { // Predicate_imm32sx16
    ConstantSDNode*N = cast<ConstantSDNode>(Node);

  return isInt<16>(N->getSExtValue());

  }
  case 32: { // Predicate_imm64sx16
    ConstantSDNode*N = cast<ConstantSDNode>(Node);

  return isInt<16>(N->getSExtValue());

  }
  case 33: { // Predicate_aligned_truncstorei16
    SDNode *N = Node;

  StoreSDNode *Store = cast<StoreSDNode>(N);
  return Store->getAlignment() >= Store->getMemoryVT().getStoreSize();

  }
  case 34: { // Predicate_aligned_truncstorei32
    SDNode *N = Node;

  StoreSDNode *Store = cast<StoreSDNode>(N);
  return Store->getAlignment() >= Store->getMemoryVT().getStoreSize();

  }
  case 35: { // Predicate_asextload
    SDNode *N = Node;

  unsigned Type = cast<LoadSDNode>(N)->getExtensionType();
  return Type == ISD::EXTLOAD || Type == ISD::SEXTLOAD;

  }
  case 36: { // Predicate_asextloadi16
    SDNode *N = Node;

  return cast<LoadSDNode>(N)->getMemoryVT() == MVT::i16;

  }
  case 37: { // Predicate_asextloadi32
    SDNode *N = Node;

  return cast<LoadSDNode>(N)->getMemoryVT() == MVT::i32;

  }
  case 38: { // Predicate_azextload
    SDNode *N = Node;

  unsigned Type = cast<LoadSDNode>(N)->getExtensionType();
  return Type == ISD::EXTLOAD || Type == ISD::ZEXTLOAD;

  }
  case 39: { // Predicate_azextloadi32
    SDNode *N = Node;

  return cast<LoadSDNode>(N)->getMemoryVT() == MVT::i32;

  }
  case 40: { // Predicate_imm64lf32
    ConstantSDNode*N = cast<ConstantSDNode>(Node);

  return SystemZ::isImmLF(N->getZExtValue());

  }
  case 41: { // Predicate_imm64hf32
    ConstantSDNode*N = cast<ConstantSDNode>(Node);

  return SystemZ::isImmHF(N->getZExtValue());

  }
  case 42: { // Predicate_azextloadi8
    SDNode *N = Node;

  return cast<LoadSDNode>(N)->getMemoryVT() == MVT::i8;

  }
  case 43: { // Predicate_or_as_inserti8
    SDNode *N = Node;

  unsigned BitWidth = N->getValueType(0).getScalarType().getSizeInBits();
  return CurDAG->MaskedValueIsZero(N->getOperand(0),
                                   APInt::getLowBitsSet(BitWidth, 8));

  }
  case 44: { // Predicate_or_as_revinserti8
    SDNode *N = Node;

  unsigned BitWidth = N->getValueType(0).getScalarType().getSizeInBits();
  return CurDAG->MaskedValueIsZero(N->getOperand(1),
                                   APInt::getLowBitsSet(BitWidth, 8));

  }
  case 45: { // Predicate_imm32ll16
    ConstantSDNode*N = cast<ConstantSDNode>(Node);

  return SystemZ::isImmLL(N->getZExtValue());

  }
  case 46: { // Predicate_imm32lh16
    ConstantSDNode*N = cast<ConstantSDNode>(Node);

  return SystemZ::isImmLH(N->getZExtValue());

  }
  case 47: { // Predicate_imm64ll16
    ConstantSDNode*N = cast<ConstantSDNode>(Node);

  return SystemZ::isImmLL(N->getZExtValue());

  }
  case 48: { // Predicate_imm64lh16
    ConstantSDNode*N = cast<ConstantSDNode>(Node);

  return SystemZ::isImmLH(N->getZExtValue());

  }
  case 49: { // Predicate_imm64hl16
    ConstantSDNode*N = cast<ConstantSDNode>(Node);

  return SystemZ::isImmHL(N->getZExtValue());

  }
  case 50: { // Predicate_imm64hh16
    ConstantSDNode*N = cast<ConstantSDNode>(Node);

  return SystemZ::isImmHH(N->getZExtValue());

  }
  case 51: { // Predicate_imm32zx8
    ConstantSDNode*N = cast<ConstantSDNode>(Node);

  return isUInt<8>(N->getZExtValue());

  }
  case 52: { // Predicate_cond4
    ConstantSDNode*N = cast<ConstantSDNode>(Node);
 return (N->getZExtValue() < 16); 
  }
  case 53: { // Predicate_aligned_asextloadi16
    SDNode *N = Node;

  LoadSDNode *Load = cast<LoadSDNode>(N);
  return Load->getAlignment() >= Load->getMemoryVT().getStoreSize();

  }
  case 54: { // Predicate_z_scmp
    SDNode *N = Node;

  unsigned Type = cast<ConstantSDNode>(N->getOperand(2))->getZExtValue();
  return Type != SystemZICMP::UnsignedOnly;

  }
  case 55: { // Predicate_aligned_load
    SDNode *N = Node;

  LoadSDNode *Load = cast<LoadSDNode>(N);
  return Load->getAlignment() >= Load->getMemoryVT().getStoreSize();

  }
  case 56: { // Predicate_aligned_asextloadi32
    SDNode *N = Node;

  LoadSDNode *Load = cast<LoadSDNode>(N);
  return Load->getAlignment() >= Load->getMemoryVT().getStoreSize();

  }
  case 57: { // Predicate_azextloadi16
    SDNode *N = Node;

  return cast<LoadSDNode>(N)->getMemoryVT() == MVT::i16;

  }
  case 58: { // Predicate_aligned_azextloadi16
    SDNode *N = Node;

  LoadSDNode *Load = cast<LoadSDNode>(N);
  return Load->getAlignment() >= Load->getMemoryVT().getStoreSize();

  }
  case 59: { // Predicate_z_ucmp
    SDNode *N = Node;

  unsigned Type = cast<ConstantSDNode>(N->getOperand(2))->getZExtValue();
  return Type != SystemZICMP::SignedOnly;

  }
  case 60: { // Predicate_aligned_azextloadi32
    SDNode *N = Node;

  LoadSDNode *Load = cast<LoadSDNode>(N);
  return Load->getAlignment() >= Load->getMemoryVT().getStoreSize();

  }
  case 61: { // Predicate_imm32zx16
    ConstantSDNode*N = cast<ConstantSDNode>(Node);

  return isUInt<16>(N->getZExtValue());

  }
  case 62: { // Predicate_imm64zx16
    ConstantSDNode*N = cast<ConstantSDNode>(Node);

  return isUInt<16>(N->getZExtValue());

  }
  case 63: { // Predicate_imm64sx32
    ConstantSDNode*N = cast<ConstantSDNode>(Node);

  return isInt<32>(N->getSExtValue());

  }
  case 64: { // Predicate_imm64zx32
    ConstantSDNode*N = cast<ConstantSDNode>(Node);

  return isUInt<32>(N->getZExtValue());

  }
  case 65: { // Predicate_imm64zx32n
    ConstantSDNode*N = cast<ConstantSDNode>(Node);

  return isUInt<32>(-N->getSExtValue());

  }
  case 66: { // Predicate_imm32ll16c
    ConstantSDNode*N = cast<ConstantSDNode>(Node);

  return SystemZ::isImmLL(uint32_t(~N->getZExtValue()));

  }
  case 67: { // Predicate_imm32lh16c
    ConstantSDNode*N = cast<ConstantSDNode>(Node);

  return SystemZ::isImmLH(uint32_t(~N->getZExtValue()));

  }
  case 68: { // Predicate_imm64ll16c
    ConstantSDNode*N = cast<ConstantSDNode>(Node);

  return SystemZ::isImmLL(uint64_t(~N->getZExtValue()));

  }
  case 69: { // Predicate_imm64lh16c
    ConstantSDNode*N = cast<ConstantSDNode>(Node);

  return SystemZ::isImmLH(uint64_t(~N->getZExtValue()));

  }
  case 70: { // Predicate_imm64hl16c
    ConstantSDNode*N = cast<ConstantSDNode>(Node);

  return SystemZ::isImmHL(uint64_t(~N->getZExtValue()));

  }
  case 71: { // Predicate_imm64hh16c
    ConstantSDNode*N = cast<ConstantSDNode>(Node);

  return SystemZ::isImmHH(uint64_t(~N->getZExtValue()));

  }
  case 72: { // Predicate_imm64lf32c
    ConstantSDNode*N = cast<ConstantSDNode>(Node);

  return SystemZ::isImmLF(uint64_t(~N->getZExtValue()));

  }
  case 73: { // Predicate_imm64hf32c
    ConstantSDNode*N = cast<ConstantSDNode>(Node);

  return SystemZ::isImmHF(uint64_t(~N->getZExtValue()));

  }
  case 74: { // Predicate_fpimm0
    ConstantFPSDNode*N = cast<ConstantFPSDNode>(Node);
 return N->isExactlyValue(+0.0); 
  }
  case 75: { // Predicate_asextloadi8
    SDNode *N = Node;

  return cast<LoadSDNode>(N)->getMemoryVT() == MVT::i8;

  }
  case 76: { // Predicate_extload
    SDNode *N = Node;

  return cast<LoadSDNode>(N)->getExtensionType() == ISD::EXTLOAD;

  }
  case 77: { // Predicate_extloadf32
    SDNode *N = Node;

  return cast<LoadSDNode>(N)->getMemoryVT() == MVT::f32;

  }
  case 78: { // Predicate_extloadf64
    SDNode *N = Node;

  return cast<LoadSDNode>(N)->getMemoryVT() == MVT::f64;

  }
  case 79: { // Predicate_atomic_load_add_32
    SDNode *N = Node;

    return cast<AtomicSDNode>(N)->getMemoryVT() == MVT::i32;
  
  }
  case 80: { // Predicate_atomic_load_add_64
    SDNode *N = Node;

    return cast<AtomicSDNode>(N)->getMemoryVT() == MVT::i64;
  
  }
  case 81: { // Predicate_atomic_load_and_32
    SDNode *N = Node;

    return cast<AtomicSDNode>(N)->getMemoryVT() == MVT::i32;
  
  }
  case 82: { // Predicate_atomic_load_and_64
    SDNode *N = Node;

    return cast<AtomicSDNode>(N)->getMemoryVT() == MVT::i64;
  
  }
  case 83: { // Predicate_atomic_load_or_32
    SDNode *N = Node;

    return cast<AtomicSDNode>(N)->getMemoryVT() == MVT::i32;
  
  }
  case 84: { // Predicate_atomic_load_or_64
    SDNode *N = Node;

    return cast<AtomicSDNode>(N)->getMemoryVT() == MVT::i64;
  
  }
  case 85: { // Predicate_atomic_load_xor_64
    SDNode *N = Node;

    return cast<AtomicSDNode>(N)->getMemoryVT() == MVT::i64;
  
  }
  case 86: { // Predicate_atomic_load_xor_32
    SDNode *N = Node;

    return cast<AtomicSDNode>(N)->getMemoryVT() == MVT::i32;
  
  }
  case 87: { // Predicate_atomic_load_nand_32
    SDNode *N = Node;

    return cast<AtomicSDNode>(N)->getMemoryVT() == MVT::i32;
  
  }
  case 88: { // Predicate_atomic_load_nand_64
    SDNode *N = Node;

    return cast<AtomicSDNode>(N)->getMemoryVT() == MVT::i64;
  
  }
  case 89: { // Predicate_atomic_cmp_swap_32
    SDNode *N = Node;

  return cast<AtomicSDNode>(N)->getMemoryVT() == MVT::i32;

  }
  case 90: { // Predicate_atomic_cmp_swap_64
    SDNode *N = Node;

  return cast<AtomicSDNode>(N)->getMemoryVT() == MVT::i64;

  }
  case 91: { // Predicate_atomic_swap_32
    SDNode *N = Node;

    return cast<AtomicSDNode>(N)->getMemoryVT() == MVT::i32;
  
  }
  case 92: { // Predicate_atomic_swap_64
    SDNode *N = Node;

    return cast<AtomicSDNode>(N)->getMemoryVT() == MVT::i64;
  
  }
  case 93: { // Predicate_atomic_load_sub_32
    SDNode *N = Node;

    return cast<AtomicSDNode>(N)->getMemoryVT() == MVT::i32;
  
  }
  case 94: { // Predicate_atomic_load_sub_64
    SDNode *N = Node;

    return cast<AtomicSDNode>(N)->getMemoryVT() == MVT::i64;
  
  }
  case 95: { // Predicate_atomic_load_min_32
    SDNode *N = Node;

    return cast<AtomicSDNode>(N)->getMemoryVT() == MVT::i32;
  
  }
  case 96: { // Predicate_atomic_load_min_64
    SDNode *N = Node;

    return cast<AtomicSDNode>(N)->getMemoryVT() == MVT::i64;
  
  }
  case 97: { // Predicate_atomic_load_max_32
    SDNode *N = Node;

    return cast<AtomicSDNode>(N)->getMemoryVT() == MVT::i32;
  
  }
  case 98: { // Predicate_atomic_load_max_64
    SDNode *N = Node;

    return cast<AtomicSDNode>(N)->getMemoryVT() == MVT::i64;
  
  }
  case 99: { // Predicate_atomic_load_umin_32
    SDNode *N = Node;

    return cast<AtomicSDNode>(N)->getMemoryVT() == MVT::i32;
  
  }
  case 100: { // Predicate_atomic_load_umin_64
    SDNode *N = Node;

    return cast<AtomicSDNode>(N)->getMemoryVT() == MVT::i64;
  
  }
  case 101: { // Predicate_atomic_load_umax_32
    SDNode *N = Node;

    return cast<AtomicSDNode>(N)->getMemoryVT() == MVT::i32;
  
  }
  case 102: { // Predicate_atomic_load_umax_64
    SDNode *N = Node;

    return cast<AtomicSDNode>(N)->getMemoryVT() == MVT::i64;
  
  }
  case 103: { // Predicate_access_reg
    ConstantSDNode*N = cast<ConstantSDNode>(Node);
 return N->getZExtValue() < 16; 
  }
  case 104: { // Predicate_fpimmneg0
    ConstantFPSDNode*N = cast<ConstantFPSDNode>(Node);
 return N->isExactlyValue(-0.0); 
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
    Result.resize(NextRes+3);
    return selectBDXAddr20Only(N, Result[NextRes+0].first, Result[NextRes+1].first, Result[NextRes+2].first);
  case 1:
    Result.resize(NextRes+2);
    return selectBDAddr12Only(N, Result[NextRes+0].first, Result[NextRes+1].first);
  case 2:
    Result.resize(NextRes+2);
    return selectBDAddr12Pair(N, Result[NextRes+0].first, Result[NextRes+1].first);
  case 3:
    Result.resize(NextRes+2);
    return selectBDAddr20Pair(N, Result[NextRes+0].first, Result[NextRes+1].first);
  case 4:
    Result.resize(NextRes+2);
    return selectBDAddr20Only(N, Result[NextRes+0].first, Result[NextRes+1].first);
  case 5:
    Result.resize(NextRes+1);
    return selectPCRelAddress(N, Result[NextRes+0].first);
  case 6:
    Result.resize(NextRes+2);
    return selectMVIAddr12Pair(N, Result[NextRes+0].first, Result[NextRes+1].first);
  case 7:
    Result.resize(NextRes+3);
    return selectBDXAddr12Pair(N, Result[NextRes+0].first, Result[NextRes+1].first, Result[NextRes+2].first);
  case 8:
    Result.resize(NextRes+3);
    return selectBDXAddr20Pair(N, Result[NextRes+0].first, Result[NextRes+1].first, Result[NextRes+2].first);
  case 9:
    Result.resize(NextRes+3);
    return selectBDXAddr20Only128(N, Result[NextRes+0].first, Result[NextRes+1].first, Result[NextRes+2].first);
  case 10:
    Result.resize(NextRes+2);
    return selectMVIAddr20Pair(N, Result[NextRes+0].first, Result[NextRes+1].first);
  case 11:
    Result.resize(NextRes+2);
    return selectBDAddr12Only(N, Result[NextRes+0].first, Result[NextRes+1].first);
  case 12:
    Result.resize(NextRes+2);
    return selectBDAddr20Only(N, Result[NextRes+0].first, Result[NextRes+1].first);
  case 13:
    Result.resize(NextRes+3);
    return selectDynAlloc12Only(N, Result[NextRes+0].first, Result[NextRes+1].first, Result[NextRes+2].first);
  case 14:
    Result.resize(NextRes+3);
    return selectLAAddr12Pair(N, Result[NextRes+0].first, Result[NextRes+1].first, Result[NextRes+2].first);
  case 15:
    Result.resize(NextRes+3);
    return selectLAAddr20Pair(N, Result[NextRes+0].first, Result[NextRes+1].first, Result[NextRes+2].first);
  case 16:
    Result.resize(NextRes+3);
    return selectBDXAddr12Only(N, Result[NextRes+0].first, Result[NextRes+1].first, Result[NextRes+2].first);
  }
}

virtual SDValue RunSDNodeXForm(SDValue V, unsigned XFormNo) {
  switch (XFormNo) {
  default: llvm_unreachable("Invalid xform # in table?");
  case 0: {  // UIMM8
    ConstantSDNode *N = cast<ConstantSDNode>(V.getNode());

  return CurDAG->getTargetConstant(uint8_t(N->getZExtValue()), MVT::i64);

  }
  case 1: {  // SIMM8
    ConstantSDNode *N = cast<ConstantSDNode>(V.getNode());

  return CurDAG->getTargetConstant(int8_t(N->getZExtValue()), MVT::i64);

  }
  case 2: {  // SIMM16
    ConstantSDNode *N = cast<ConstantSDNode>(V.getNode());

  return CurDAG->getTargetConstant(int16_t(N->getZExtValue()), MVT::i64);

  }
  case 3: {  // LF32
    ConstantSDNode *N = cast<ConstantSDNode>(V.getNode());

  uint64_t Value = N->getZExtValue() & 0x00000000FFFFFFFFULL;
  return CurDAG->getTargetConstant(Value, MVT::i64);

  }
  case 4: {  // HF32
    ConstantSDNode *N = cast<ConstantSDNode>(V.getNode());

  uint64_t Value = N->getZExtValue() >> 32;
  return CurDAG->getTargetConstant(Value, MVT::i64);

  }
  case 5: {  // UIMM32
    ConstantSDNode *N = cast<ConstantSDNode>(V.getNode());

  return CurDAG->getTargetConstant(uint32_t(N->getZExtValue()), MVT::i64);

  }
  case 6: {  // LL16
    ConstantSDNode *N = cast<ConstantSDNode>(V.getNode());

  uint64_t Value = N->getZExtValue() & 0x000000000000FFFFULL;
  return CurDAG->getTargetConstant(Value, MVT::i64);

  }
  case 7: {  // LH16
    ConstantSDNode *N = cast<ConstantSDNode>(V.getNode());

  uint64_t Value = (N->getZExtValue() & 0x00000000FFFF0000ULL) >> 16;
  return CurDAG->getTargetConstant(Value, MVT::i64);

  }
  case 8: {  // HL16
    ConstantSDNode *N = cast<ConstantSDNode>(V.getNode());

  uint64_t Value = (N->getZExtValue() & 0x0000FFFF00000000ULL) >> 32;
  return CurDAG->getTargetConstant(Value, MVT::i64);

  }
  case 9: {  // HH16
    ConstantSDNode *N = cast<ConstantSDNode>(V.getNode());

  uint64_t Value = (N->getZExtValue() & 0xFFFF000000000000ULL) >> 48;
  return CurDAG->getTargetConstant(Value, MVT::i64);

  }
  case 10: {  // UIMM16
    ConstantSDNode *N = cast<ConstantSDNode>(V.getNode());

  return CurDAG->getTargetConstant(uint16_t(N->getZExtValue()), MVT::i64);

  }
  case 11: {  // SIMM32
    ConstantSDNode *N = cast<ConstantSDNode>(V.getNode());

  return CurDAG->getTargetConstant(int32_t(N->getZExtValue()), MVT::i64);

  }
  case 12: {  // NEGIMM32
    ConstantSDNode *N = cast<ConstantSDNode>(V.getNode());

  return CurDAG->getTargetConstant(uint32_t(-N->getZExtValue()), MVT::i64);

  }
  }
}


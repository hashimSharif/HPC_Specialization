/*===- TableGen'erated file -------------------------------------*- C++ -*-===*\
|*                                                                            *|
|*DAG Instruction Selector for the Sparc target                               *|
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
/*0*/     OPC_SwitchOpcode /*58 cases */, 104|128,3/*488*/,  TARGET_VAL(ISD::STORE),// ->493
/*5*/       OPC_RecordMemRef,
/*6*/       OPC_RecordNode,   // #0 = 'st' chained node
/*7*/       OPC_Scope, 96, /*->105*/ // 2 children in Scope
/*9*/         OPC_MoveChild, 1,
/*11*/        OPC_CheckInteger, 0, 
/*13*/        OPC_SwitchType /*2 cases */, 42,  MVT::i32,// ->58
/*16*/          OPC_MoveParent,
/*17*/          OPC_RecordChild2, // #1 = $dst
/*18*/          OPC_CheckPredicate, 0, // Predicate_unindexedstore
/*20*/          OPC_CheckPredicate, 1, // Predicate_store
/*22*/          OPC_Scope, 16, /*->40*/ // 2 children in Scope
/*24*/            OPC_CheckComplexPat, /*CP*/0, /*#*/1, // SelectADDRrr:$dst #2 #3
/*27*/            OPC_EmitMergeInputChains1_0,
/*28*/            OPC_EmitRegister, MVT::i32, SP::G0,
/*31*/            OPC_MorphNodeTo, TARGET_VAL(SP::STrr), 0|OPFL_Chain|OPFL_MemRefs,
                      0/*#VTs*/, 3/*#Ops*/, 2, 3, 4, 
                  // Src: (st 0:i32, ADDRrr:iPTR:$dst)<<P:Predicate_unindexedstore>><<P:Predicate_store>> - Complexity = 18
                  // Dst: (STrr ADDRrr:iPTR:$dst, G0:i32)
/*40*/          /*Scope*/ 16, /*->57*/
/*41*/            OPC_CheckComplexPat, /*CP*/1, /*#*/1, // SelectADDRri:$dst #2 #3
/*44*/            OPC_EmitMergeInputChains1_0,
/*45*/            OPC_EmitRegister, MVT::i32, SP::G0,
/*48*/            OPC_MorphNodeTo, TARGET_VAL(SP::STri), 0|OPFL_Chain|OPFL_MemRefs,
                      0/*#VTs*/, 3/*#Ops*/, 2, 3, 4, 
                  // Src: (st 0:i32, ADDRri:iPTR:$dst)<<P:Predicate_unindexedstore>><<P:Predicate_store>> - Complexity = 18
                  // Dst: (STri ADDRri:iPTR:$dst, G0:i32)
/*57*/          0, /*End of Scope*/
/*58*/        /*SwitchType*/ 44,  MVT::i64,// ->104
/*60*/          OPC_MoveParent,
/*61*/          OPC_RecordChild2, // #1 = $dst
/*62*/          OPC_CheckPredicate, 0, // Predicate_unindexedstore
/*64*/          OPC_CheckPredicate, 1, // Predicate_store
/*66*/          OPC_CheckPatternPredicate, 0, // (Subtarget.is64Bit())
/*68*/          OPC_Scope, 16, /*->86*/ // 2 children in Scope
/*70*/            OPC_CheckComplexPat, /*CP*/0, /*#*/1, // SelectADDRrr:$dst #2 #3
/*73*/            OPC_EmitMergeInputChains1_0,
/*74*/            OPC_EmitRegister, MVT::i64, SP::G0,
/*77*/            OPC_MorphNodeTo, TARGET_VAL(SP::STXrr), 0|OPFL_Chain|OPFL_MemRefs,
                      0/*#VTs*/, 3/*#Ops*/, 2, 3, 4, 
                  // Src: (st 0:i64, ADDRrr:iPTR:$dst)<<P:Predicate_unindexedstore>><<P:Predicate_store>> - Complexity = 18
                  // Dst: (STXrr ADDRrr:iPTR:$dst, G0:i64)
/*86*/          /*Scope*/ 16, /*->103*/
/*87*/            OPC_CheckComplexPat, /*CP*/1, /*#*/1, // SelectADDRri:$dst #2 #3
/*90*/            OPC_EmitMergeInputChains1_0,
/*91*/            OPC_EmitRegister, MVT::i64, SP::G0,
/*94*/            OPC_MorphNodeTo, TARGET_VAL(SP::STXri), 0|OPFL_Chain|OPFL_MemRefs,
                      0/*#VTs*/, 3/*#Ops*/, 2, 3, 4, 
                  // Src: (st 0:i64, ADDRri:iPTR:$dst)<<P:Predicate_unindexedstore>><<P:Predicate_store>> - Complexity = 18
                  // Dst: (STXri ADDRri:iPTR:$dst, G0:i64)
/*103*/         0, /*End of Scope*/
/*104*/       0, // EndSwitchType
/*105*/     /*Scope*/ 1|128,3/*385*/, /*->492*/
/*107*/       OPC_RecordChild1, // #1 = $rd
/*108*/       OPC_Scope, 111, /*->221*/ // 5 children in Scope
/*110*/         OPC_CheckChild1Type, MVT::i32,
/*112*/         OPC_RecordChild2, // #2 = $addr
/*113*/         OPC_CheckPredicate, 0, // Predicate_unindexedstore
/*115*/         OPC_Scope, 70, /*->187*/ // 2 children in Scope
/*117*/           OPC_CheckPredicate, 2, // Predicate_truncstore
/*119*/           OPC_Scope, 32, /*->153*/ // 2 children in Scope
/*121*/             OPC_CheckPredicate, 3, // Predicate_truncstorei8
/*123*/             OPC_Scope, 13, /*->138*/ // 2 children in Scope
/*125*/               OPC_CheckComplexPat, /*CP*/0, /*#*/2, // SelectADDRrr:$addr #3 #4
/*128*/               OPC_EmitMergeInputChains1_0,
/*129*/               OPC_MorphNodeTo, TARGET_VAL(SP::STBrr), 0|OPFL_Chain|OPFL_MemRefs,
                          0/*#VTs*/, 3/*#Ops*/, 3, 4, 1, 
                      // Src: (st i32:i32:$rd, ADDRrr:iPTR:$addr)<<P:Predicate_unindexedstore>><<P:Predicate_truncstore>><<P:Predicate_truncstorei8>> - Complexity = 13
                      // Dst: (STBrr ADDRrr:iPTR:$addr, i32:i32:$rd)
/*138*/             /*Scope*/ 13, /*->152*/
/*139*/               OPC_CheckComplexPat, /*CP*/1, /*#*/2, // SelectADDRri:$addr #3 #4
/*142*/               OPC_EmitMergeInputChains1_0,
/*143*/               OPC_MorphNodeTo, TARGET_VAL(SP::STBri), 0|OPFL_Chain|OPFL_MemRefs,
                          0/*#VTs*/, 3/*#Ops*/, 3, 4, 1, 
                      // Src: (st i32:i32:$rd, ADDRri:iPTR:$addr)<<P:Predicate_unindexedstore>><<P:Predicate_truncstore>><<P:Predicate_truncstorei8>> - Complexity = 13
                      // Dst: (STBri ADDRri:iPTR:$addr, i32:i32:$rd)
/*152*/             0, /*End of Scope*/
/*153*/           /*Scope*/ 32, /*->186*/
/*154*/             OPC_CheckPredicate, 4, // Predicate_truncstorei16
/*156*/             OPC_Scope, 13, /*->171*/ // 2 children in Scope
/*158*/               OPC_CheckComplexPat, /*CP*/0, /*#*/2, // SelectADDRrr:$addr #3 #4
/*161*/               OPC_EmitMergeInputChains1_0,
/*162*/               OPC_MorphNodeTo, TARGET_VAL(SP::STHrr), 0|OPFL_Chain|OPFL_MemRefs,
                          0/*#VTs*/, 3/*#Ops*/, 3, 4, 1, 
                      // Src: (st i32:i32:$rd, ADDRrr:iPTR:$addr)<<P:Predicate_unindexedstore>><<P:Predicate_truncstore>><<P:Predicate_truncstorei16>> - Complexity = 13
                      // Dst: (STHrr ADDRrr:iPTR:$addr, i32:i32:$rd)
/*171*/             /*Scope*/ 13, /*->185*/
/*172*/               OPC_CheckComplexPat, /*CP*/1, /*#*/2, // SelectADDRri:$addr #3 #4
/*175*/               OPC_EmitMergeInputChains1_0,
/*176*/               OPC_MorphNodeTo, TARGET_VAL(SP::STHri), 0|OPFL_Chain|OPFL_MemRefs,
                          0/*#VTs*/, 3/*#Ops*/, 3, 4, 1, 
                      // Src: (st i32:i32:$rd, ADDRri:iPTR:$addr)<<P:Predicate_unindexedstore>><<P:Predicate_truncstore>><<P:Predicate_truncstorei16>> - Complexity = 13
                      // Dst: (STHri ADDRri:iPTR:$addr, i32:i32:$rd)
/*185*/             0, /*End of Scope*/
/*186*/           0, /*End of Scope*/
/*187*/         /*Scope*/ 32, /*->220*/
/*188*/           OPC_CheckPredicate, 1, // Predicate_store
/*190*/           OPC_Scope, 13, /*->205*/ // 2 children in Scope
/*192*/             OPC_CheckComplexPat, /*CP*/0, /*#*/2, // SelectADDRrr:$addr #3 #4
/*195*/             OPC_EmitMergeInputChains1_0,
/*196*/             OPC_MorphNodeTo, TARGET_VAL(SP::STrr), 0|OPFL_Chain|OPFL_MemRefs,
                        0/*#VTs*/, 3/*#Ops*/, 3, 4, 1, 
                    // Src: (st i32:i32:$rd, ADDRrr:iPTR:$addr)<<P:Predicate_unindexedstore>><<P:Predicate_store>> - Complexity = 13
                    // Dst: (STrr ADDRrr:iPTR:$addr, i32:i32:$rd)
/*205*/           /*Scope*/ 13, /*->219*/
/*206*/             OPC_CheckComplexPat, /*CP*/1, /*#*/2, // SelectADDRri:$addr #3 #4
/*209*/             OPC_EmitMergeInputChains1_0,
/*210*/             OPC_MorphNodeTo, TARGET_VAL(SP::STri), 0|OPFL_Chain|OPFL_MemRefs,
                        0/*#VTs*/, 3/*#Ops*/, 3, 4, 1, 
                    // Src: (st i32:i32:$rd, ADDRri:iPTR:$addr)<<P:Predicate_unindexedstore>><<P:Predicate_store>> - Complexity = 13
                    // Dst: (STri ADDRri:iPTR:$addr, i32:i32:$rd)
/*219*/           0, /*End of Scope*/
/*220*/         0, /*End of Scope*/
/*221*/       /*Scope*/ 37, /*->259*/
/*222*/         OPC_CheckChild1Type, MVT::f32,
/*224*/         OPC_RecordChild2, // #2 = $addr
/*225*/         OPC_CheckPredicate, 0, // Predicate_unindexedstore
/*227*/         OPC_CheckPredicate, 1, // Predicate_store
/*229*/         OPC_Scope, 13, /*->244*/ // 2 children in Scope
/*231*/           OPC_CheckComplexPat, /*CP*/0, /*#*/2, // SelectADDRrr:$addr #3 #4
/*234*/           OPC_EmitMergeInputChains1_0,
/*235*/           OPC_MorphNodeTo, TARGET_VAL(SP::STFrr), 0|OPFL_Chain|OPFL_MemRefs,
                      0/*#VTs*/, 3/*#Ops*/, 3, 4, 1, 
                  // Src: (st f32:f32:$rd, ADDRrr:iPTR:$addr)<<P:Predicate_unindexedstore>><<P:Predicate_store>> - Complexity = 13
                  // Dst: (STFrr ADDRrr:iPTR:$addr, f32:f32:$rd)
/*244*/         /*Scope*/ 13, /*->258*/
/*245*/           OPC_CheckComplexPat, /*CP*/1, /*#*/2, // SelectADDRri:$addr #3 #4
/*248*/           OPC_EmitMergeInputChains1_0,
/*249*/           OPC_MorphNodeTo, TARGET_VAL(SP::STFri), 0|OPFL_Chain|OPFL_MemRefs,
                      0/*#VTs*/, 3/*#Ops*/, 3, 4, 1, 
                  // Src: (st f32:f32:$rd, ADDRri:iPTR:$addr)<<P:Predicate_unindexedstore>><<P:Predicate_store>> - Complexity = 13
                  // Dst: (STFri ADDRri:iPTR:$addr, f32:f32:$rd)
/*258*/         0, /*End of Scope*/
/*259*/       /*Scope*/ 37, /*->297*/
/*260*/         OPC_CheckChild1Type, MVT::f64,
/*262*/         OPC_RecordChild2, // #2 = $addr
/*263*/         OPC_CheckPredicate, 0, // Predicate_unindexedstore
/*265*/         OPC_CheckPredicate, 1, // Predicate_store
/*267*/         OPC_Scope, 13, /*->282*/ // 2 children in Scope
/*269*/           OPC_CheckComplexPat, /*CP*/0, /*#*/2, // SelectADDRrr:$addr #3 #4
/*272*/           OPC_EmitMergeInputChains1_0,
/*273*/           OPC_MorphNodeTo, TARGET_VAL(SP::STDFrr), 0|OPFL_Chain|OPFL_MemRefs,
                      0/*#VTs*/, 3/*#Ops*/, 3, 4, 1, 
                  // Src: (st f64:f64:$rd, ADDRrr:iPTR:$addr)<<P:Predicate_unindexedstore>><<P:Predicate_store>> - Complexity = 13
                  // Dst: (STDFrr ADDRrr:iPTR:$addr, f64:f64:$rd)
/*282*/         /*Scope*/ 13, /*->296*/
/*283*/           OPC_CheckComplexPat, /*CP*/1, /*#*/2, // SelectADDRri:$addr #3 #4
/*286*/           OPC_EmitMergeInputChains1_0,
/*287*/           OPC_MorphNodeTo, TARGET_VAL(SP::STDFri), 0|OPFL_Chain|OPFL_MemRefs,
                      0/*#VTs*/, 3/*#Ops*/, 3, 4, 1, 
                  // Src: (st f64:f64:$rd, ADDRri:iPTR:$addr)<<P:Predicate_unindexedstore>><<P:Predicate_store>> - Complexity = 13
                  // Dst: (STDFri ADDRri:iPTR:$addr, f64:f64:$rd)
/*296*/         0, /*End of Scope*/
/*297*/       /*Scope*/ 39, /*->337*/
/*298*/         OPC_CheckChild1Type, MVT::f128,
/*300*/         OPC_RecordChild2, // #2 = $addr
/*301*/         OPC_CheckPredicate, 0, // Predicate_unindexedstore
/*303*/         OPC_CheckPredicate, 1, // Predicate_store
/*305*/         OPC_CheckPatternPredicate, 1, // (Subtarget.isV9()) && (Subtarget.hasHardQuad())
/*307*/         OPC_Scope, 13, /*->322*/ // 2 children in Scope
/*309*/           OPC_CheckComplexPat, /*CP*/0, /*#*/2, // SelectADDRrr:$addr #3 #4
/*312*/           OPC_EmitMergeInputChains1_0,
/*313*/           OPC_MorphNodeTo, TARGET_VAL(SP::STQFrr), 0|OPFL_Chain|OPFL_MemRefs,
                      0/*#VTs*/, 3/*#Ops*/, 3, 4, 1, 
                  // Src: (st f128:f128:$rd, ADDRrr:iPTR:$addr)<<P:Predicate_unindexedstore>><<P:Predicate_store>> - Complexity = 13
                  // Dst: (STQFrr ADDRrr:iPTR:$addr, f128:f128:$rd)
/*322*/         /*Scope*/ 13, /*->336*/
/*323*/           OPC_CheckComplexPat, /*CP*/1, /*#*/2, // SelectADDRri:$addr #3 #4
/*326*/           OPC_EmitMergeInputChains1_0,
/*327*/           OPC_MorphNodeTo, TARGET_VAL(SP::STQFri), 0|OPFL_Chain|OPFL_MemRefs,
                      0/*#VTs*/, 3/*#Ops*/, 3, 4, 1, 
                  // Src: (st f128:f128:$rd, ADDRri:iPTR:$addr)<<P:Predicate_unindexedstore>><<P:Predicate_store>> - Complexity = 13
                  // Dst: (STQFri ADDRri:iPTR:$addr, f128:f128:$rd)
/*336*/         0, /*End of Scope*/
/*337*/       /*Scope*/ 24|128,1/*152*/, /*->491*/
/*339*/         OPC_CheckChild1Type, MVT::i64,
/*341*/         OPC_RecordChild2, // #2 = $addr
/*342*/         OPC_CheckPredicate, 0, // Predicate_unindexedstore
/*344*/         OPC_Scope, 34, /*->380*/ // 2 children in Scope
/*346*/           OPC_CheckPredicate, 1, // Predicate_store
/*348*/           OPC_CheckPatternPredicate, 0, // (Subtarget.is64Bit())
/*350*/           OPC_Scope, 13, /*->365*/ // 2 children in Scope
/*352*/             OPC_CheckComplexPat, /*CP*/0, /*#*/2, // SelectADDRrr:$addr #3 #4
/*355*/             OPC_EmitMergeInputChains1_0,
/*356*/             OPC_MorphNodeTo, TARGET_VAL(SP::STXrr), 0|OPFL_Chain|OPFL_MemRefs,
                        0/*#VTs*/, 3/*#Ops*/, 3, 4, 1, 
                    // Src: (st i64:i64:$src, ADDRrr:iPTR:$addr)<<P:Predicate_unindexedstore>><<P:Predicate_store>> - Complexity = 13
                    // Dst: (STXrr ADDRrr:iPTR:$addr, i64:i64:$src)
/*365*/           /*Scope*/ 13, /*->379*/
/*366*/             OPC_CheckComplexPat, /*CP*/1, /*#*/2, // SelectADDRri:$addr #3 #4
/*369*/             OPC_EmitMergeInputChains1_0,
/*370*/             OPC_MorphNodeTo, TARGET_VAL(SP::STXri), 0|OPFL_Chain|OPFL_MemRefs,
                        0/*#VTs*/, 3/*#Ops*/, 3, 4, 1, 
                    // Src: (st i64:i64:$src, ADDRri:iPTR:$addr)<<P:Predicate_unindexedstore>><<P:Predicate_store>> - Complexity = 13
                    // Dst: (STXri ADDRri:iPTR:$addr, i64:i64:$src)
/*379*/           0, /*End of Scope*/
/*380*/         /*Scope*/ 109, /*->490*/
/*381*/           OPC_CheckPredicate, 2, // Predicate_truncstore
/*383*/           OPC_Scope, 34, /*->419*/ // 3 children in Scope
/*385*/             OPC_CheckPredicate, 3, // Predicate_truncstorei8
/*387*/             OPC_CheckPatternPredicate, 0, // (Subtarget.is64Bit())
/*389*/             OPC_Scope, 13, /*->404*/ // 2 children in Scope
/*391*/               OPC_CheckComplexPat, /*CP*/0, /*#*/2, // SelectADDRrr:$addr #3 #4
/*394*/               OPC_EmitMergeInputChains1_0,
/*395*/               OPC_MorphNodeTo, TARGET_VAL(SP::STBrr), 0|OPFL_Chain|OPFL_MemRefs,
                          0/*#VTs*/, 3/*#Ops*/, 3, 4, 1, 
                      // Src: (st i64:i64:$src, ADDRrr:iPTR:$addr)<<P:Predicate_unindexedstore>><<P:Predicate_truncstore>><<P:Predicate_truncstorei8>> - Complexity = 13
                      // Dst: (STBrr ADDRrr:iPTR:$addr, ?:i64:$src)
/*404*/             /*Scope*/ 13, /*->418*/
/*405*/               OPC_CheckComplexPat, /*CP*/1, /*#*/2, // SelectADDRri:$addr #3 #4
/*408*/               OPC_EmitMergeInputChains1_0,
/*409*/               OPC_MorphNodeTo, TARGET_VAL(SP::STBri), 0|OPFL_Chain|OPFL_MemRefs,
                          0/*#VTs*/, 3/*#Ops*/, 3, 4, 1, 
                      // Src: (st i64:i64:$src, ADDRri:iPTR:$addr)<<P:Predicate_unindexedstore>><<P:Predicate_truncstore>><<P:Predicate_truncstorei8>> - Complexity = 13
                      // Dst: (STBri ADDRri:iPTR:$addr, ?:i64:$src)
/*418*/             0, /*End of Scope*/
/*419*/           /*Scope*/ 34, /*->454*/
/*420*/             OPC_CheckPredicate, 4, // Predicate_truncstorei16
/*422*/             OPC_CheckPatternPredicate, 0, // (Subtarget.is64Bit())
/*424*/             OPC_Scope, 13, /*->439*/ // 2 children in Scope
/*426*/               OPC_CheckComplexPat, /*CP*/0, /*#*/2, // SelectADDRrr:$addr #3 #4
/*429*/               OPC_EmitMergeInputChains1_0,
/*430*/               OPC_MorphNodeTo, TARGET_VAL(SP::STHrr), 0|OPFL_Chain|OPFL_MemRefs,
                          0/*#VTs*/, 3/*#Ops*/, 3, 4, 1, 
                      // Src: (st i64:i64:$src, ADDRrr:iPTR:$addr)<<P:Predicate_unindexedstore>><<P:Predicate_truncstore>><<P:Predicate_truncstorei16>> - Complexity = 13
                      // Dst: (STHrr ADDRrr:iPTR:$addr, ?:i64:$src)
/*439*/             /*Scope*/ 13, /*->453*/
/*440*/               OPC_CheckComplexPat, /*CP*/1, /*#*/2, // SelectADDRri:$addr #3 #4
/*443*/               OPC_EmitMergeInputChains1_0,
/*444*/               OPC_MorphNodeTo, TARGET_VAL(SP::STHri), 0|OPFL_Chain|OPFL_MemRefs,
                          0/*#VTs*/, 3/*#Ops*/, 3, 4, 1, 
                      // Src: (st i64:i64:$src, ADDRri:iPTR:$addr)<<P:Predicate_unindexedstore>><<P:Predicate_truncstore>><<P:Predicate_truncstorei16>> - Complexity = 13
                      // Dst: (STHri ADDRri:iPTR:$addr, ?:i64:$src)
/*453*/             0, /*End of Scope*/
/*454*/           /*Scope*/ 34, /*->489*/
/*455*/             OPC_CheckPredicate, 5, // Predicate_truncstorei32
/*457*/             OPC_CheckPatternPredicate, 0, // (Subtarget.is64Bit())
/*459*/             OPC_Scope, 13, /*->474*/ // 2 children in Scope
/*461*/               OPC_CheckComplexPat, /*CP*/0, /*#*/2, // SelectADDRrr:$addr #3 #4
/*464*/               OPC_EmitMergeInputChains1_0,
/*465*/               OPC_MorphNodeTo, TARGET_VAL(SP::STrr), 0|OPFL_Chain|OPFL_MemRefs,
                          0/*#VTs*/, 3/*#Ops*/, 3, 4, 1, 
                      // Src: (st i64:i64:$src, ADDRrr:iPTR:$addr)<<P:Predicate_unindexedstore>><<P:Predicate_truncstore>><<P:Predicate_truncstorei32>> - Complexity = 13
                      // Dst: (STrr ADDRrr:iPTR:$addr, ?:i64:$src)
/*474*/             /*Scope*/ 13, /*->488*/
/*475*/               OPC_CheckComplexPat, /*CP*/1, /*#*/2, // SelectADDRri:$addr #3 #4
/*478*/               OPC_EmitMergeInputChains1_0,
/*479*/               OPC_MorphNodeTo, TARGET_VAL(SP::STri), 0|OPFL_Chain|OPFL_MemRefs,
                          0/*#VTs*/, 3/*#Ops*/, 3, 4, 1, 
                      // Src: (st i64:i64:$src, ADDRri:iPTR:$addr)<<P:Predicate_unindexedstore>><<P:Predicate_truncstore>><<P:Predicate_truncstorei32>> - Complexity = 13
                      // Dst: (STri ADDRri:iPTR:$addr, ?:i64:$src)
/*488*/             0, /*End of Scope*/
/*489*/           0, /*End of Scope*/
/*490*/         0, /*End of Scope*/
/*491*/       0, /*End of Scope*/
/*492*/     0, /*End of Scope*/
/*493*/   /*SwitchOpcode*/ 42,  TARGET_VAL(SPISD::TLS_LD),// ->538
/*496*/     OPC_RecordChild0, // #0 = $addr
/*497*/     OPC_RecordChild1, // #1 = $sym
/*498*/     OPC_MoveChild, 1,
/*500*/     OPC_CheckOpcode, TARGET_VAL(ISD::TargetGlobalTLSAddress),
/*503*/     OPC_MoveParent,
/*504*/     OPC_SwitchType /*2 cases */, 13,  MVT::i32,// ->520
/*507*/       OPC_CheckComplexPat, /*CP*/0, /*#*/0, // SelectADDRrr:$addr #2 #3
/*510*/       OPC_MorphNodeTo, TARGET_VAL(SP::TLS_LDrr), 0,
                  1/*#VTs*/, MVT::i32, 3/*#Ops*/, 2, 3, 1, 
              // Src: (tlsld:i32 ADDRrr:iPTR:$addr, (tglobaltlsaddr:iPTR):$sym) - Complexity = 15
              // Dst: (TLS_LDrr:i32 ADDRrr:iPTR:$addr, (tglobaltlsaddr:iPTR):$sym)
/*520*/     /*SwitchType*/ 15,  MVT::i64,// ->537
/*522*/       OPC_CheckPatternPredicate, 0, // (Subtarget.is64Bit())
/*524*/       OPC_CheckComplexPat, /*CP*/0, /*#*/0, // SelectADDRrr:$addr #2 #3
/*527*/       OPC_MorphNodeTo, TARGET_VAL(SP::TLS_LDXrr), 0,
                  1/*#VTs*/, MVT::i64, 3/*#Ops*/, 2, 3, 1, 
              // Src: (tlsld:i64 ADDRrr:iPTR:$addr, (tglobaltlsaddr:iPTR):$sym) - Complexity = 15
              // Dst: (TLS_LDXrr:i64 ADDRrr:iPTR:$addr, (tglobaltlsaddr:iPTR):$sym)
/*537*/     0, // EndSwitchType
/*538*/   /*SwitchOpcode*/ 14|128,2/*270*/,  TARGET_VAL(ISD::ADD),// ->812
/*542*/     OPC_Scope, 86, /*->630*/ // 4 children in Scope
/*544*/       OPC_MoveChild, 0,
/*546*/       OPC_SwitchOpcode /*2 cases */, 38,  TARGET_VAL(SPISD::Hi),// ->588
/*550*/         OPC_RecordChild0, // #0 = $in1
/*551*/         OPC_MoveChild, 0,
/*553*/         OPC_CheckOpcode, TARGET_VAL(ISD::TargetGlobalTLSAddress),
/*556*/         OPC_MoveParent,
/*557*/         OPC_MoveParent,
/*558*/         OPC_MoveChild, 1,
/*560*/         OPC_CheckOpcode, TARGET_VAL(SPISD::Lo),
/*563*/         OPC_RecordChild0, // #1 = $in2
/*564*/         OPC_MoveChild, 0,
/*566*/         OPC_CheckOpcode, TARGET_VAL(ISD::TargetGlobalTLSAddress),
/*569*/         OPC_MoveParent,
/*570*/         OPC_MoveParent,
/*571*/         OPC_EmitNode, TARGET_VAL(SP::SETHIi), 0,
                    1/*#VTs*/, MVT::i32, 1/*#Ops*/, 0,  // Results = #2
/*579*/         OPC_MorphNodeTo, TARGET_VAL(SP::ADDri), 0,
                    1/*#VTs*/, MVT::iPTR, 2/*#Ops*/, 2, 1, 
                // Src: (add:iPTR (SPhi:iPTR (tglobaltlsaddr:iPTR):$in1), (SPlo:iPTR (tglobaltlsaddr:iPTR):$in2)) - Complexity = 15
                // Dst: (ADDri:iPTR (SETHIi:i32 (tglobaltlsaddr:i32):$in1), (tglobaltlsaddr:i32):$in2)
/*588*/       /*SwitchOpcode*/ 38,  TARGET_VAL(SPISD::Lo),// ->629
/*591*/         OPC_RecordChild0, // #0 = $in2
/*592*/         OPC_MoveChild, 0,
/*594*/         OPC_CheckOpcode, TARGET_VAL(ISD::TargetGlobalTLSAddress),
/*597*/         OPC_MoveParent,
/*598*/         OPC_MoveParent,
/*599*/         OPC_MoveChild, 1,
/*601*/         OPC_CheckOpcode, TARGET_VAL(SPISD::Hi),
/*604*/         OPC_RecordChild0, // #1 = $in1
/*605*/         OPC_MoveChild, 0,
/*607*/         OPC_CheckOpcode, TARGET_VAL(ISD::TargetGlobalTLSAddress),
/*610*/         OPC_MoveParent,
/*611*/         OPC_MoveParent,
/*612*/         OPC_EmitNode, TARGET_VAL(SP::SETHIi), 0,
                    1/*#VTs*/, MVT::i32, 1/*#Ops*/, 1,  // Results = #2
/*620*/         OPC_MorphNodeTo, TARGET_VAL(SP::ADDri), 0,
                    1/*#VTs*/, MVT::iPTR, 2/*#Ops*/, 2, 0, 
                // Src: (add:iPTR (SPlo:iPTR (tglobaltlsaddr:iPTR):$in2), (SPhi:iPTR (tglobaltlsaddr:iPTR):$in1)) - Complexity = 15
                // Dst: (ADDri:iPTR (SETHIi:i32 (tglobaltlsaddr:i32):$in1), (tglobaltlsaddr:i32):$in2)
/*629*/       0, // EndSwitchOpcode
/*630*/     /*Scope*/ 53, /*->684*/
/*631*/       OPC_RecordChild0, // #0 = $r
/*632*/       OPC_MoveChild, 1,
/*634*/       OPC_CheckOpcode, TARGET_VAL(SPISD::Lo),
/*637*/       OPC_RecordChild0, // #1 = $in
/*638*/       OPC_MoveChild, 0,
/*640*/       OPC_SwitchOpcode /*3 cases */, 11,  TARGET_VAL(ISD::TargetGlobalAddress),// ->655
/*644*/         OPC_MoveParent,
/*645*/         OPC_MoveParent,
/*646*/         OPC_MorphNodeTo, TARGET_VAL(SP::ADDri), 0,
                    1/*#VTs*/, MVT::iPTR, 2/*#Ops*/, 0, 1, 
                // Src: (add:iPTR iPTR:iPTR:$r, (SPlo:iPTR (tglobaladdr:iPTR):$in)) - Complexity = 9
                // Dst: (ADDri:iPTR ?:iPTR:$r, (tglobaladdr:i32):$in)
/*655*/       /*SwitchOpcode*/ 11,  TARGET_VAL(ISD::TargetConstantPool),// ->669
/*658*/         OPC_MoveParent,
/*659*/         OPC_MoveParent,
/*660*/         OPC_MorphNodeTo, TARGET_VAL(SP::ADDri), 0,
                    1/*#VTs*/, MVT::iPTR, 2/*#Ops*/, 0, 1, 
                // Src: (add:iPTR iPTR:iPTR:$r, (SPlo:iPTR (tconstpool:iPTR):$in)) - Complexity = 9
                // Dst: (ADDri:iPTR ?:iPTR:$r, (tconstpool:i32):$in)
/*669*/       /*SwitchOpcode*/ 11,  TARGET_VAL(ISD::TargetBlockAddress),// ->683
/*672*/         OPC_MoveParent,
/*673*/         OPC_MoveParent,
/*674*/         OPC_MorphNodeTo, TARGET_VAL(SP::ADDri), 0,
                    1/*#VTs*/, MVT::iPTR, 2/*#Ops*/, 0, 1, 
                // Src: (add:iPTR iPTR:iPTR:$r, (SPlo:iPTR (tblockaddress:iPTR):$in)) - Complexity = 9
                // Dst: (ADDri:iPTR ?:iPTR:$r, (tblockaddress:i32):$in)
/*683*/       0, // EndSwitchOpcode
/*684*/     /*Scope*/ 55, /*->740*/
/*685*/       OPC_MoveChild, 0,
/*687*/       OPC_CheckOpcode, TARGET_VAL(SPISD::Lo),
/*690*/       OPC_RecordChild0, // #0 = $in
/*691*/       OPC_MoveChild, 0,
/*693*/       OPC_SwitchOpcode /*3 cases */, 12,  TARGET_VAL(ISD::TargetGlobalAddress),// ->709
/*697*/         OPC_MoveParent,
/*698*/         OPC_MoveParent,
/*699*/         OPC_RecordChild1, // #1 = $r
/*700*/         OPC_MorphNodeTo, TARGET_VAL(SP::ADDri), 0,
                    1/*#VTs*/, MVT::iPTR, 2/*#Ops*/, 1, 0, 
                // Src: (add:iPTR (SPlo:iPTR (tglobaladdr:iPTR):$in), iPTR:iPTR:$r) - Complexity = 9
                // Dst: (ADDri:iPTR ?:iPTR:$r, (tglobaladdr:i32):$in)
/*709*/       /*SwitchOpcode*/ 12,  TARGET_VAL(ISD::TargetConstantPool),// ->724
/*712*/         OPC_MoveParent,
/*713*/         OPC_MoveParent,
/*714*/         OPC_RecordChild1, // #1 = $r
/*715*/         OPC_MorphNodeTo, TARGET_VAL(SP::ADDri), 0,
                    1/*#VTs*/, MVT::iPTR, 2/*#Ops*/, 1, 0, 
                // Src: (add:iPTR (SPlo:iPTR (tconstpool:iPTR):$in), iPTR:iPTR:$r) - Complexity = 9
                // Dst: (ADDri:iPTR ?:iPTR:$r, (tconstpool:i32):$in)
/*724*/       /*SwitchOpcode*/ 12,  TARGET_VAL(ISD::TargetBlockAddress),// ->739
/*727*/         OPC_MoveParent,
/*728*/         OPC_MoveParent,
/*729*/         OPC_RecordChild1, // #1 = $r
/*730*/         OPC_MorphNodeTo, TARGET_VAL(SP::ADDri), 0,
                    1/*#VTs*/, MVT::iPTR, 2/*#Ops*/, 1, 0, 
                // Src: (add:iPTR (SPlo:iPTR (tblockaddress:iPTR):$in), iPTR:iPTR:$r) - Complexity = 9
                // Dst: (ADDri:iPTR ?:iPTR:$r, (tblockaddress:i32):$in)
/*739*/       0, // EndSwitchOpcode
/*740*/     /*Scope*/ 70, /*->811*/
/*741*/       OPC_RecordChild0, // #0 = $b
/*742*/       OPC_RecordChild1, // #1 = $c
/*743*/       OPC_Scope, 39, /*->784*/ // 3 children in Scope
/*745*/         OPC_MoveChild, 1,
/*747*/         OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*750*/         OPC_CheckPredicate, 6, // Predicate_simm13
/*752*/         OPC_MoveParent,
/*753*/         OPC_SwitchType /*2 cases */, 11,  MVT::i32,// ->767
/*756*/           OPC_EmitConvertToTarget, 1,
/*758*/           OPC_MorphNodeTo, TARGET_VAL(SP::ADDri), 0,
                      1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 2, 
                  // Src: (add:i32 i32:i32:$b, (imm:i32)<<P:Predicate_simm13>>:$c) - Complexity = 7
                  // Dst: (ADDri:i32 i32:i32:$b, (imm:i32):$c)
/*767*/         /*SwitchType*/ 14,  MVT::i64,// ->783
/*769*/           OPC_CheckPatternPredicate, 0, // (Subtarget.is64Bit())
/*771*/           OPC_EmitNodeXForm, 0, 1, // as_i32imm
/*774*/           OPC_MorphNodeTo, TARGET_VAL(SP::ADDri), 0,
                      1/*#VTs*/, MVT::i64, 2/*#Ops*/, 0, 2, 
                  // Src: (add:i64 i64:i64:$a, (imm:i64)<<P:Predicate_simm13>>:$b) - Complexity = 7
                  // Dst: (ADDri:i64 ?:i64:$a, (as_i32imm:i32 ?:i64:$b))
/*783*/         0, // EndSwitchType
/*784*/       /*Scope*/ 11, /*->796*/
/*785*/         OPC_CheckType, MVT::i32,
/*787*/         OPC_MorphNodeTo, TARGET_VAL(SP::ADDrr), 0,
                    1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1, 
                // Src: (add:i32 i32:i32:$b, i32:i32:$c) - Complexity = 3
                // Dst: (ADDrr:i32 i32:i32:$b, i32:i32:$c)
/*796*/       /*Scope*/ 13, /*->810*/
/*797*/         OPC_CheckType, MVT::i64,
/*799*/         OPC_CheckPatternPredicate, 0, // (Subtarget.is64Bit())
/*801*/         OPC_MorphNodeTo, TARGET_VAL(SP::ADDrr), 0,
                    1/*#VTs*/, MVT::i64, 2/*#Ops*/, 0, 1, 
                // Src: (add:i64 i64:i64:$a, i64:i64:$b) - Complexity = 3
                // Dst: (ADDrr:i64 ?:i64:$a, ?:i64:$b)
/*810*/       0, /*End of Scope*/
/*811*/     0, /*End of Scope*/
/*812*/   /*SwitchOpcode*/ 75|128,2/*331*/,  TARGET_VAL(ISD::XOR),// ->1147
/*816*/     OPC_Scope, 117, /*->935*/ // 6 children in Scope
/*818*/       OPC_MoveChild, 0,
/*820*/       OPC_SwitchOpcode /*3 cases */, 38,  TARGET_VAL(SPISD::Hi),// ->862
/*824*/         OPC_RecordChild0, // #0 = $in1
/*825*/         OPC_MoveChild, 0,
/*827*/         OPC_CheckOpcode, TARGET_VAL(ISD::TargetGlobalTLSAddress),
/*830*/         OPC_MoveParent,
/*831*/         OPC_MoveParent,
/*832*/         OPC_MoveChild, 1,
/*834*/         OPC_CheckOpcode, TARGET_VAL(SPISD::Lo),
/*837*/         OPC_RecordChild0, // #1 = $in2
/*838*/         OPC_MoveChild, 0,
/*840*/         OPC_CheckOpcode, TARGET_VAL(ISD::TargetGlobalTLSAddress),
/*843*/         OPC_MoveParent,
/*844*/         OPC_MoveParent,
/*845*/         OPC_EmitNode, TARGET_VAL(SP::SETHIi), 0,
                    1/*#VTs*/, MVT::i32, 1/*#Ops*/, 0,  // Results = #2
/*853*/         OPC_MorphNodeTo, TARGET_VAL(SP::XORri), 0,
                    1/*#VTs*/, MVT::iPTR, 2/*#Ops*/, 2, 1, 
                // Src: (xor:iPTR (SPhi:iPTR (tglobaltlsaddr:iPTR):$in1), (SPlo:iPTR (tglobaltlsaddr:iPTR):$in2)) - Complexity = 15
                // Dst: (XORri:iPTR (SETHIi:i32 (tglobaltlsaddr:i32):$in1), (tglobaltlsaddr:i32):$in2)
/*862*/       /*SwitchOpcode*/ 38,  TARGET_VAL(SPISD::Lo),// ->903
/*865*/         OPC_RecordChild0, // #0 = $in2
/*866*/         OPC_MoveChild, 0,
/*868*/         OPC_CheckOpcode, TARGET_VAL(ISD::TargetGlobalTLSAddress),
/*871*/         OPC_MoveParent,
/*872*/         OPC_MoveParent,
/*873*/         OPC_MoveChild, 1,
/*875*/         OPC_CheckOpcode, TARGET_VAL(SPISD::Hi),
/*878*/         OPC_RecordChild0, // #1 = $in1
/*879*/         OPC_MoveChild, 0,
/*881*/         OPC_CheckOpcode, TARGET_VAL(ISD::TargetGlobalTLSAddress),
/*884*/         OPC_MoveParent,
/*885*/         OPC_MoveParent,
/*886*/         OPC_EmitNode, TARGET_VAL(SP::SETHIi), 0,
                    1/*#VTs*/, MVT::i32, 1/*#Ops*/, 1,  // Results = #2
/*894*/         OPC_MorphNodeTo, TARGET_VAL(SP::XORri), 0,
                    1/*#VTs*/, MVT::iPTR, 2/*#Ops*/, 2, 0, 
                // Src: (xor:iPTR (SPlo:iPTR (tglobaltlsaddr:iPTR):$in2), (SPhi:iPTR (tglobaltlsaddr:iPTR):$in1)) - Complexity = 15
                // Dst: (XORri:iPTR (SETHIi:i32 (tglobaltlsaddr:i32):$in1), (tglobaltlsaddr:i32):$in2)
/*903*/       /*SwitchOpcode*/ 28,  TARGET_VAL(ISD::XOR),// ->934
/*906*/         OPC_RecordChild0, // #0 = $b
/*907*/         OPC_RecordChild1, // #1 = $c
/*908*/         OPC_MoveParent,
/*909*/         OPC_MoveChild, 1,
/*911*/         OPC_CheckInteger, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*922*/         OPC_MoveParent,
/*923*/         OPC_CheckType, MVT::i32,
/*925*/         OPC_MorphNodeTo, TARGET_VAL(SP::XNORrr), 0,
                    1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1, 
                // Src: (xor:i32 (xor:i32 i32:i32:$b, i32:i32:$c), -1:i32) - Complexity = 11
                // Dst: (XNORrr:i32 i32:i32:$b, i32:i32:$c)
/*934*/       0, // EndSwitchOpcode
/*935*/     /*Scope*/ 35, /*->971*/
/*936*/       OPC_RecordChild0, // #0 = $a
/*937*/       OPC_MoveChild, 1,
/*939*/       OPC_CheckOpcode, TARGET_VAL(ISD::XOR),
/*942*/       OPC_RecordChild0, // #1 = $b
/*943*/       OPC_MoveChild, 1,
/*945*/       OPC_CheckInteger, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*956*/       OPC_MoveParent,
/*957*/       OPC_MoveParent,
/*958*/       OPC_CheckType, MVT::i64,
/*960*/       OPC_CheckPatternPredicate, 0, // (Subtarget.is64Bit())
/*962*/       OPC_MorphNodeTo, TARGET_VAL(SP::XNORrr), 0,
                  1/*#VTs*/, MVT::i64, 2/*#Ops*/, 0, 1, 
              // Src: (xor:i64 i64:i64:$a, (xor:i64 i64:i64:$b, -1:i64)) - Complexity = 11
              // Dst: (XNORrr:i64 ?:i64:$a, ?:i64:$b)
/*971*/     /*Scope*/ 33, /*->1005*/
/*972*/       OPC_MoveChild, 0,
/*974*/       OPC_CheckOpcode, TARGET_VAL(ISD::XOR),
/*977*/       OPC_RecordChild0, // #0 = $b
/*978*/       OPC_MoveChild, 1,
/*980*/       OPC_CheckInteger, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*991*/       OPC_MoveParent,
/*992*/       OPC_MoveParent,
/*993*/       OPC_RecordChild1, // #1 = $c
/*994*/       OPC_CheckType, MVT::i32,
/*996*/       OPC_MorphNodeTo, TARGET_VAL(SP::XNORrr), 0,
                  1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1, 
              // Src: (xor:i32 (xor:i32 i32:i32:$b, -1:i32), i32:i32:$c) - Complexity = 11
              // Dst: (XNORrr:i32 i32:i32:$b, i32:i32:$c)
/*1005*/    /*Scope*/ 33, /*->1039*/
/*1006*/      OPC_RecordChild0, // #0 = $c
/*1007*/      OPC_MoveChild, 1,
/*1009*/      OPC_CheckOpcode, TARGET_VAL(ISD::XOR),
/*1012*/      OPC_RecordChild0, // #1 = $b
/*1013*/      OPC_MoveChild, 1,
/*1015*/      OPC_CheckInteger, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*1026*/      OPC_MoveParent,
/*1027*/      OPC_MoveParent,
/*1028*/      OPC_CheckType, MVT::i32,
/*1030*/      OPC_MorphNodeTo, TARGET_VAL(SP::XNORrr), 0,
                  1/*#VTs*/, MVT::i32, 2/*#Ops*/, 1, 0, 
              // Src: (xor:i32 i32:i32:$c, (xor:i32 i32:i32:$b, -1:i32)) - Complexity = 11
              // Dst: (XNORrr:i32 i32:i32:$b, i32:i32:$c)
/*1039*/    /*Scope*/ 35, /*->1075*/
/*1040*/      OPC_MoveChild, 0,
/*1042*/      OPC_CheckOpcode, TARGET_VAL(ISD::XOR),
/*1045*/      OPC_RecordChild0, // #0 = $a
/*1046*/      OPC_MoveChild, 1,
/*1048*/      OPC_CheckInteger, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*1059*/      OPC_MoveParent,
/*1060*/      OPC_MoveParent,
/*1061*/      OPC_RecordChild1, // #1 = $b
/*1062*/      OPC_CheckType, MVT::i64,
/*1064*/      OPC_CheckPatternPredicate, 0, // (Subtarget.is64Bit())
/*1066*/      OPC_MorphNodeTo, TARGET_VAL(SP::XNORrr), 0,
                  1/*#VTs*/, MVT::i64, 2/*#Ops*/, 0, 1, 
              // Src: (xor:i64 (xor:i64 i64:i64:$a, -1:i64), i64:i64:$b) - Complexity = 11
              // Dst: (XNORrr:i64 ?:i64:$a, ?:i64:$b)
/*1075*/    /*Scope*/ 70, /*->1146*/
/*1076*/      OPC_RecordChild0, // #0 = $b
/*1077*/      OPC_RecordChild1, // #1 = $c
/*1078*/      OPC_Scope, 39, /*->1119*/ // 3 children in Scope
/*1080*/        OPC_MoveChild, 1,
/*1082*/        OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*1085*/        OPC_CheckPredicate, 6, // Predicate_simm13
/*1087*/        OPC_MoveParent,
/*1088*/        OPC_SwitchType /*2 cases */, 11,  MVT::i32,// ->1102
/*1091*/          OPC_EmitConvertToTarget, 1,
/*1093*/          OPC_MorphNodeTo, TARGET_VAL(SP::XORri), 0,
                      1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 2, 
                  // Src: (xor:i32 i32:i32:$b, (imm:i32)<<P:Predicate_simm13>>:$c) - Complexity = 7
                  // Dst: (XORri:i32 i32:i32:$b, (imm:i32):$c)
/*1102*/        /*SwitchType*/ 14,  MVT::i64,// ->1118
/*1104*/          OPC_CheckPatternPredicate, 0, // (Subtarget.is64Bit())
/*1106*/          OPC_EmitNodeXForm, 0, 1, // as_i32imm
/*1109*/          OPC_MorphNodeTo, TARGET_VAL(SP::XORri), 0,
                      1/*#VTs*/, MVT::i64, 2/*#Ops*/, 0, 2, 
                  // Src: (xor:i64 i64:i64:$a, (imm:i64)<<P:Predicate_simm13>>:$b) - Complexity = 7
                  // Dst: (XORri:i64 ?:i64:$a, (as_i32imm:i32 ?:i64:$b))
/*1118*/        0, // EndSwitchType
/*1119*/      /*Scope*/ 11, /*->1131*/
/*1120*/        OPC_CheckType, MVT::i32,
/*1122*/        OPC_MorphNodeTo, TARGET_VAL(SP::XORrr), 0,
                    1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1, 
                // Src: (xor:i32 i32:i32:$b, i32:i32:$c) - Complexity = 3
                // Dst: (XORrr:i32 i32:i32:$b, i32:i32:$c)
/*1131*/      /*Scope*/ 13, /*->1145*/
/*1132*/        OPC_CheckType, MVT::i64,
/*1134*/        OPC_CheckPatternPredicate, 0, // (Subtarget.is64Bit())
/*1136*/        OPC_MorphNodeTo, TARGET_VAL(SP::XORrr), 0,
                    1/*#VTs*/, MVT::i64, 2/*#Ops*/, 0, 1, 
                // Src: (xor:i64 i64:i64:$a, i64:i64:$b) - Complexity = 3
                // Dst: (XORrr:i64 ?:i64:$a, ?:i64:$b)
/*1145*/      0, /*End of Scope*/
/*1146*/    0, /*End of Scope*/
/*1147*/  /*SwitchOpcode*/ 4|128,7/*900*/,  TARGET_VAL(ISD::LOAD),// ->2051
/*1151*/    OPC_RecordMemRef,
/*1152*/    OPC_RecordNode,   // #0 = 'ld' chained node
/*1153*/    OPC_RecordChild1, // #1 = $addr
/*1154*/    OPC_CheckPredicate, 7, // Predicate_unindexedload
/*1156*/    OPC_Scope, 72, /*->1230*/ // 18 children in Scope
/*1158*/      OPC_CheckPredicate, 8, // Predicate_sextload
/*1160*/      OPC_CheckType, MVT::i32,
/*1162*/      OPC_Scope, 32, /*->1196*/ // 2 children in Scope
/*1164*/        OPC_CheckPredicate, 9, // Predicate_sextloadi8
/*1166*/        OPC_Scope, 13, /*->1181*/ // 2 children in Scope
/*1168*/          OPC_CheckComplexPat, /*CP*/0, /*#*/1, // SelectADDRrr:$addr #2 #3
/*1171*/          OPC_EmitMergeInputChains1_0,
/*1172*/          OPC_MorphNodeTo, TARGET_VAL(SP::LDSBrr), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i32, 2/*#Ops*/, 2, 3, 
                  // Src: (ld:i32 ADDRrr:iPTR:$addr)<<P:Predicate_unindexedload>><<P:Predicate_sextload>><<P:Predicate_sextloadi8>> - Complexity = 13
                  // Dst: (LDSBrr:i32 ADDRrr:iPTR:$addr)
/*1181*/        /*Scope*/ 13, /*->1195*/
/*1182*/          OPC_CheckComplexPat, /*CP*/1, /*#*/1, // SelectADDRri:$addr #2 #3
/*1185*/          OPC_EmitMergeInputChains1_0,
/*1186*/          OPC_MorphNodeTo, TARGET_VAL(SP::LDSBri), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i32, 2/*#Ops*/, 2, 3, 
                  // Src: (ld:i32 ADDRri:iPTR:$addr)<<P:Predicate_unindexedload>><<P:Predicate_sextload>><<P:Predicate_sextloadi8>> - Complexity = 13
                  // Dst: (LDSBri:i32 ADDRri:iPTR:$addr)
/*1195*/        0, /*End of Scope*/
/*1196*/      /*Scope*/ 32, /*->1229*/
/*1197*/        OPC_CheckPredicate, 10, // Predicate_sextloadi16
/*1199*/        OPC_Scope, 13, /*->1214*/ // 2 children in Scope
/*1201*/          OPC_CheckComplexPat, /*CP*/0, /*#*/1, // SelectADDRrr:$addr #2 #3
/*1204*/          OPC_EmitMergeInputChains1_0,
/*1205*/          OPC_MorphNodeTo, TARGET_VAL(SP::LDSHrr), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i32, 2/*#Ops*/, 2, 3, 
                  // Src: (ld:i32 ADDRrr:iPTR:$addr)<<P:Predicate_unindexedload>><<P:Predicate_sextload>><<P:Predicate_sextloadi16>> - Complexity = 13
                  // Dst: (LDSHrr:i32 ADDRrr:iPTR:$addr)
/*1214*/        /*Scope*/ 13, /*->1228*/
/*1215*/          OPC_CheckComplexPat, /*CP*/1, /*#*/1, // SelectADDRri:$addr #2 #3
/*1218*/          OPC_EmitMergeInputChains1_0,
/*1219*/          OPC_MorphNodeTo, TARGET_VAL(SP::LDSHri), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i32, 2/*#Ops*/, 2, 3, 
                  // Src: (ld:i32 ADDRri:iPTR:$addr)<<P:Predicate_unindexedload>><<P:Predicate_sextload>><<P:Predicate_sextloadi16>> - Complexity = 13
                  // Dst: (LDSHri:i32 ADDRri:iPTR:$addr)
/*1228*/        0, /*End of Scope*/
/*1229*/      0, /*End of Scope*/
/*1230*/    /*Scope*/ 72, /*->1303*/
/*1231*/      OPC_CheckPredicate, 11, // Predicate_zextload
/*1233*/      OPC_CheckType, MVT::i32,
/*1235*/      OPC_Scope, 32, /*->1269*/ // 2 children in Scope
/*1237*/        OPC_CheckPredicate, 12, // Predicate_zextloadi8
/*1239*/        OPC_Scope, 13, /*->1254*/ // 2 children in Scope
/*1241*/          OPC_CheckComplexPat, /*CP*/0, /*#*/1, // SelectADDRrr:$addr #2 #3
/*1244*/          OPC_EmitMergeInputChains1_0,
/*1245*/          OPC_MorphNodeTo, TARGET_VAL(SP::LDUBrr), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i32, 2/*#Ops*/, 2, 3, 
                  // Src: (ld:i32 ADDRrr:iPTR:$addr)<<P:Predicate_unindexedload>><<P:Predicate_zextload>><<P:Predicate_zextloadi8>> - Complexity = 13
                  // Dst: (LDUBrr:i32 ADDRrr:iPTR:$addr)
/*1254*/        /*Scope*/ 13, /*->1268*/
/*1255*/          OPC_CheckComplexPat, /*CP*/1, /*#*/1, // SelectADDRri:$addr #2 #3
/*1258*/          OPC_EmitMergeInputChains1_0,
/*1259*/          OPC_MorphNodeTo, TARGET_VAL(SP::LDUBri), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i32, 2/*#Ops*/, 2, 3, 
                  // Src: (ld:i32 ADDRri:iPTR:$addr)<<P:Predicate_unindexedload>><<P:Predicate_zextload>><<P:Predicate_zextloadi8>> - Complexity = 13
                  // Dst: (LDUBri:i32 ADDRri:iPTR:$addr)
/*1268*/        0, /*End of Scope*/
/*1269*/      /*Scope*/ 32, /*->1302*/
/*1270*/        OPC_CheckPredicate, 13, // Predicate_zextloadi16
/*1272*/        OPC_Scope, 13, /*->1287*/ // 2 children in Scope
/*1274*/          OPC_CheckComplexPat, /*CP*/0, /*#*/1, // SelectADDRrr:$addr #2 #3
/*1277*/          OPC_EmitMergeInputChains1_0,
/*1278*/          OPC_MorphNodeTo, TARGET_VAL(SP::LDUHrr), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i32, 2/*#Ops*/, 2, 3, 
                  // Src: (ld:i32 ADDRrr:iPTR:$addr)<<P:Predicate_unindexedload>><<P:Predicate_zextload>><<P:Predicate_zextloadi16>> - Complexity = 13
                  // Dst: (LDUHrr:i32 ADDRrr:iPTR:$addr)
/*1287*/        /*Scope*/ 13, /*->1301*/
/*1288*/          OPC_CheckComplexPat, /*CP*/1, /*#*/1, // SelectADDRri:$addr #2 #3
/*1291*/          OPC_EmitMergeInputChains1_0,
/*1292*/          OPC_MorphNodeTo, TARGET_VAL(SP::LDUHri), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i32, 2/*#Ops*/, 2, 3, 
                  // Src: (ld:i32 ADDRri:iPTR:$addr)<<P:Predicate_unindexedload>><<P:Predicate_zextload>><<P:Predicate_zextloadi16>> - Complexity = 13
                  // Dst: (LDUHri:i32 ADDRri:iPTR:$addr)
/*1301*/        0, /*End of Scope*/
/*1302*/      0, /*End of Scope*/
/*1303*/    /*Scope*/ 34, /*->1338*/
/*1304*/      OPC_CheckPredicate, 14, // Predicate_load
/*1306*/      OPC_CheckType, MVT::i32,
/*1308*/      OPC_Scope, 13, /*->1323*/ // 2 children in Scope
/*1310*/        OPC_CheckComplexPat, /*CP*/0, /*#*/1, // SelectADDRrr:$addr #2 #3
/*1313*/        OPC_EmitMergeInputChains1_0,
/*1314*/        OPC_MorphNodeTo, TARGET_VAL(SP::LDrr), 0|OPFL_Chain|OPFL_MemRefs,
                    1/*#VTs*/, MVT::i32, 2/*#Ops*/, 2, 3, 
                // Src: (ld:i32 ADDRrr:iPTR:$addr)<<P:Predicate_unindexedload>><<P:Predicate_load>> - Complexity = 13
                // Dst: (LDrr:i32 ADDRrr:iPTR:$addr)
/*1323*/      /*Scope*/ 13, /*->1337*/
/*1324*/        OPC_CheckComplexPat, /*CP*/1, /*#*/1, // SelectADDRri:$addr #2 #3
/*1327*/        OPC_EmitMergeInputChains1_0,
/*1328*/        OPC_MorphNodeTo, TARGET_VAL(SP::LDri), 0|OPFL_Chain|OPFL_MemRefs,
                    1/*#VTs*/, MVT::i32, 2/*#Ops*/, 2, 3, 
                // Src: (ld:i32 ADDRri:iPTR:$addr)<<P:Predicate_unindexedload>><<P:Predicate_load>> - Complexity = 13
                // Dst: (LDri:i32 ADDRri:iPTR:$addr)
/*1337*/      0, /*End of Scope*/
/*1338*/    /*Scope*/ 105, /*->1444*/
/*1339*/      OPC_CheckPredicate, 15, // Predicate_extload
/*1341*/      OPC_CheckType, MVT::i32,
/*1343*/      OPC_Scope, 32, /*->1377*/ // 3 children in Scope
/*1345*/        OPC_CheckPredicate, 16, // Predicate_extloadi1
/*1347*/        OPC_Scope, 13, /*->1362*/ // 2 children in Scope
/*1349*/          OPC_CheckComplexPat, /*CP*/0, /*#*/1, // SelectADDRrr:$src #2 #3
/*1352*/          OPC_EmitMergeInputChains1_0,
/*1353*/          OPC_MorphNodeTo, TARGET_VAL(SP::LDUBrr), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i32, 2/*#Ops*/, 2, 3, 
                  // Src: (ld:i32 ADDRrr:iPTR:$src)<<P:Predicate_unindexedload>><<P:Predicate_extload>><<P:Predicate_extloadi1>> - Complexity = 13
                  // Dst: (LDUBrr:i32 ADDRrr:iPTR:$src)
/*1362*/        /*Scope*/ 13, /*->1376*/
/*1363*/          OPC_CheckComplexPat, /*CP*/1, /*#*/1, // SelectADDRri:$src #2 #3
/*1366*/          OPC_EmitMergeInputChains1_0,
/*1367*/          OPC_MorphNodeTo, TARGET_VAL(SP::LDUBri), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i32, 2/*#Ops*/, 2, 3, 
                  // Src: (ld:i32 ADDRri:iPTR:$src)<<P:Predicate_unindexedload>><<P:Predicate_extload>><<P:Predicate_extloadi1>> - Complexity = 13
                  // Dst: (LDUBri:i32 ADDRri:iPTR:$src)
/*1376*/        0, /*End of Scope*/
/*1377*/      /*Scope*/ 32, /*->1410*/
/*1378*/        OPC_CheckPredicate, 17, // Predicate_extloadi8
/*1380*/        OPC_Scope, 13, /*->1395*/ // 2 children in Scope
/*1382*/          OPC_CheckComplexPat, /*CP*/0, /*#*/1, // SelectADDRrr:$src #2 #3
/*1385*/          OPC_EmitMergeInputChains1_0,
/*1386*/          OPC_MorphNodeTo, TARGET_VAL(SP::LDUBrr), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i32, 2/*#Ops*/, 2, 3, 
                  // Src: (ld:i32 ADDRrr:iPTR:$src)<<P:Predicate_unindexedload>><<P:Predicate_extload>><<P:Predicate_extloadi8>> - Complexity = 13
                  // Dst: (LDUBrr:i32 ADDRrr:iPTR:$src)
/*1395*/        /*Scope*/ 13, /*->1409*/
/*1396*/          OPC_CheckComplexPat, /*CP*/1, /*#*/1, // SelectADDRri:$src #2 #3
/*1399*/          OPC_EmitMergeInputChains1_0,
/*1400*/          OPC_MorphNodeTo, TARGET_VAL(SP::LDUBri), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i32, 2/*#Ops*/, 2, 3, 
                  // Src: (ld:i32 ADDRri:iPTR:$src)<<P:Predicate_unindexedload>><<P:Predicate_extload>><<P:Predicate_extloadi8>> - Complexity = 13
                  // Dst: (LDUBri:i32 ADDRri:iPTR:$src)
/*1409*/        0, /*End of Scope*/
/*1410*/      /*Scope*/ 32, /*->1443*/
/*1411*/        OPC_CheckPredicate, 18, // Predicate_extloadi16
/*1413*/        OPC_Scope, 13, /*->1428*/ // 2 children in Scope
/*1415*/          OPC_CheckComplexPat, /*CP*/0, /*#*/1, // SelectADDRrr:$src #2 #3
/*1418*/          OPC_EmitMergeInputChains1_0,
/*1419*/          OPC_MorphNodeTo, TARGET_VAL(SP::LDUHrr), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i32, 2/*#Ops*/, 2, 3, 
                  // Src: (ld:i32 ADDRrr:iPTR:$src)<<P:Predicate_unindexedload>><<P:Predicate_extload>><<P:Predicate_extloadi16>> - Complexity = 13
                  // Dst: (LDUHrr:i32 ADDRrr:iPTR:$src)
/*1428*/        /*Scope*/ 13, /*->1442*/
/*1429*/          OPC_CheckComplexPat, /*CP*/1, /*#*/1, // SelectADDRri:$src #2 #3
/*1432*/          OPC_EmitMergeInputChains1_0,
/*1433*/          OPC_MorphNodeTo, TARGET_VAL(SP::LDUHri), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i32, 2/*#Ops*/, 2, 3, 
                  // Src: (ld:i32 ADDRri:iPTR:$src)<<P:Predicate_unindexedload>><<P:Predicate_extload>><<P:Predicate_extloadi16>> - Complexity = 13
                  // Dst: (LDUHri:i32 ADDRri:iPTR:$src)
/*1442*/        0, /*End of Scope*/
/*1443*/      0, /*End of Scope*/
/*1444*/    /*Scope*/ 36, /*->1481*/
/*1445*/      OPC_CheckPredicate, 11, // Predicate_zextload
/*1447*/      OPC_CheckPredicate, 19, // Predicate_zextloadi1
/*1449*/      OPC_CheckType, MVT::i32,
/*1451*/      OPC_Scope, 13, /*->1466*/ // 2 children in Scope
/*1453*/        OPC_CheckComplexPat, /*CP*/0, /*#*/1, // SelectADDRrr:$src #2 #3
/*1456*/        OPC_EmitMergeInputChains1_0,
/*1457*/        OPC_MorphNodeTo, TARGET_VAL(SP::LDUBrr), 0|OPFL_Chain|OPFL_MemRefs,
                    1/*#VTs*/, MVT::i32, 2/*#Ops*/, 2, 3, 
                // Src: (ld:i32 ADDRrr:iPTR:$src)<<P:Predicate_unindexedload>><<P:Predicate_zextload>><<P:Predicate_zextloadi1>> - Complexity = 13
                // Dst: (LDUBrr:i32 ADDRrr:iPTR:$src)
/*1466*/      /*Scope*/ 13, /*->1480*/
/*1467*/        OPC_CheckComplexPat, /*CP*/1, /*#*/1, // SelectADDRri:$src #2 #3
/*1470*/        OPC_EmitMergeInputChains1_0,
/*1471*/        OPC_MorphNodeTo, TARGET_VAL(SP::LDUBri), 0|OPFL_Chain|OPFL_MemRefs,
                    1/*#VTs*/, MVT::i32, 2/*#Ops*/, 2, 3, 
                // Src: (ld:i32 ADDRri:iPTR:$src)<<P:Predicate_unindexedload>><<P:Predicate_zextload>><<P:Predicate_zextloadi1>> - Complexity = 13
                // Dst: (LDUBri:i32 ADDRri:iPTR:$src)
/*1480*/      0, /*End of Scope*/
/*1481*/    /*Scope*/ 36, /*->1518*/
/*1482*/      OPC_CheckPredicate, 14, // Predicate_load
/*1484*/      OPC_CheckType, MVT::i64,
/*1486*/      OPC_CheckPatternPredicate, 0, // (Subtarget.is64Bit())
/*1488*/      OPC_Scope, 13, /*->1503*/ // 2 children in Scope
/*1490*/        OPC_CheckComplexPat, /*CP*/0, /*#*/1, // SelectADDRrr:$addr #2 #3
/*1493*/        OPC_EmitMergeInputChains1_0,
/*1494*/        OPC_MorphNodeTo, TARGET_VAL(SP::LDXrr), 0|OPFL_Chain|OPFL_MemRefs,
                    1/*#VTs*/, MVT::i64, 2/*#Ops*/, 2, 3, 
                // Src: (ld:i64 ADDRrr:iPTR:$addr)<<P:Predicate_unindexedload>><<P:Predicate_load>> - Complexity = 13
                // Dst: (LDXrr:i64 ADDRrr:iPTR:$addr)
/*1503*/      /*Scope*/ 13, /*->1517*/
/*1504*/        OPC_CheckComplexPat, /*CP*/1, /*#*/1, // SelectADDRri:$addr #2 #3
/*1507*/        OPC_EmitMergeInputChains1_0,
/*1508*/        OPC_MorphNodeTo, TARGET_VAL(SP::LDXri), 0|OPFL_Chain|OPFL_MemRefs,
                    1/*#VTs*/, MVT::i64, 2/*#Ops*/, 2, 3, 
                // Src: (ld:i64 ADDRri:iPTR:$addr)<<P:Predicate_unindexedload>><<P:Predicate_load>> - Complexity = 13
                // Dst: (LDXri:i64 ADDRri:iPTR:$addr)
/*1517*/      0, /*End of Scope*/
/*1518*/    /*Scope*/ 38, /*->1557*/
/*1519*/      OPC_CheckPredicate, 11, // Predicate_zextload
/*1521*/      OPC_CheckPredicate, 19, // Predicate_zextloadi1
/*1523*/      OPC_CheckType, MVT::i64,
/*1525*/      OPC_CheckPatternPredicate, 0, // (Subtarget.is64Bit())
/*1527*/      OPC_Scope, 13, /*->1542*/ // 2 children in Scope
/*1529*/        OPC_CheckComplexPat, /*CP*/0, /*#*/1, // SelectADDRrr:$addr #2 #3
/*1532*/        OPC_EmitMergeInputChains1_0,
/*1533*/        OPC_MorphNodeTo, TARGET_VAL(SP::LDUBrr), 0|OPFL_Chain|OPFL_MemRefs,
                    1/*#VTs*/, MVT::i64, 2/*#Ops*/, 2, 3, 
                // Src: (ld:i64 ADDRrr:iPTR:$addr)<<P:Predicate_unindexedload>><<P:Predicate_zextload>><<P:Predicate_zextloadi1>> - Complexity = 13
                // Dst: (LDUBrr:i64 ADDRrr:iPTR:$addr)
/*1542*/      /*Scope*/ 13, /*->1556*/
/*1543*/        OPC_CheckComplexPat, /*CP*/1, /*#*/1, // SelectADDRri:$addr #2 #3
/*1546*/        OPC_EmitMergeInputChains1_0,
/*1547*/        OPC_MorphNodeTo, TARGET_VAL(SP::LDUBri), 0|OPFL_Chain|OPFL_MemRefs,
                    1/*#VTs*/, MVT::i64, 2/*#Ops*/, 2, 3, 
                // Src: (ld:i64 ADDRri:iPTR:$addr)<<P:Predicate_unindexedload>><<P:Predicate_zextload>><<P:Predicate_zextloadi1>> - Complexity = 13
                // Dst: (LDUBri:i64 ADDRri:iPTR:$addr)
/*1556*/      0, /*End of Scope*/
/*1557*/    /*Scope*/ 38, /*->1596*/
/*1558*/      OPC_CheckPredicate, 15, // Predicate_extload
/*1560*/      OPC_CheckPredicate, 16, // Predicate_extloadi1
/*1562*/      OPC_CheckType, MVT::i64,
/*1564*/      OPC_CheckPatternPredicate, 0, // (Subtarget.is64Bit())
/*1566*/      OPC_Scope, 13, /*->1581*/ // 2 children in Scope
/*1568*/        OPC_CheckComplexPat, /*CP*/0, /*#*/1, // SelectADDRrr:$addr #2 #3
/*1571*/        OPC_EmitMergeInputChains1_0,
/*1572*/        OPC_MorphNodeTo, TARGET_VAL(SP::LDUBrr), 0|OPFL_Chain|OPFL_MemRefs,
                    1/*#VTs*/, MVT::i64, 2/*#Ops*/, 2, 3, 
                // Src: (ld:i64 ADDRrr:iPTR:$addr)<<P:Predicate_unindexedload>><<P:Predicate_extload>><<P:Predicate_extloadi1>> - Complexity = 13
                // Dst: (LDUBrr:i64 ADDRrr:iPTR:$addr)
/*1581*/      /*Scope*/ 13, /*->1595*/
/*1582*/        OPC_CheckComplexPat, /*CP*/1, /*#*/1, // SelectADDRri:$addr #2 #3
/*1585*/        OPC_EmitMergeInputChains1_0,
/*1586*/        OPC_MorphNodeTo, TARGET_VAL(SP::LDUBri), 0|OPFL_Chain|OPFL_MemRefs,
                    1/*#VTs*/, MVT::i64, 2/*#Ops*/, 2, 3, 
                // Src: (ld:i64 ADDRri:iPTR:$addr)<<P:Predicate_unindexedload>><<P:Predicate_extload>><<P:Predicate_extloadi1>> - Complexity = 13
                // Dst: (LDUBri:i64 ADDRri:iPTR:$addr)
/*1595*/      0, /*End of Scope*/
/*1596*/    /*Scope*/ 38, /*->1635*/
/*1597*/      OPC_CheckPredicate, 11, // Predicate_zextload
/*1599*/      OPC_CheckPredicate, 12, // Predicate_zextloadi8
/*1601*/      OPC_CheckType, MVT::i64,
/*1603*/      OPC_CheckPatternPredicate, 0, // (Subtarget.is64Bit())
/*1605*/      OPC_Scope, 13, /*->1620*/ // 2 children in Scope
/*1607*/        OPC_CheckComplexPat, /*CP*/0, /*#*/1, // SelectADDRrr:$addr #2 #3
/*1610*/        OPC_EmitMergeInputChains1_0,
/*1611*/        OPC_MorphNodeTo, TARGET_VAL(SP::LDUBrr), 0|OPFL_Chain|OPFL_MemRefs,
                    1/*#VTs*/, MVT::i64, 2/*#Ops*/, 2, 3, 
                // Src: (ld:i64 ADDRrr:iPTR:$addr)<<P:Predicate_unindexedload>><<P:Predicate_zextload>><<P:Predicate_zextloadi8>> - Complexity = 13
                // Dst: (LDUBrr:i64 ADDRrr:iPTR:$addr)
/*1620*/      /*Scope*/ 13, /*->1634*/
/*1621*/        OPC_CheckComplexPat, /*CP*/1, /*#*/1, // SelectADDRri:$addr #2 #3
/*1624*/        OPC_EmitMergeInputChains1_0,
/*1625*/        OPC_MorphNodeTo, TARGET_VAL(SP::LDUBri), 0|OPFL_Chain|OPFL_MemRefs,
                    1/*#VTs*/, MVT::i64, 2/*#Ops*/, 2, 3, 
                // Src: (ld:i64 ADDRri:iPTR:$addr)<<P:Predicate_unindexedload>><<P:Predicate_zextload>><<P:Predicate_zextloadi8>> - Complexity = 13
                // Dst: (LDUBri:i64 ADDRri:iPTR:$addr)
/*1634*/      0, /*End of Scope*/
/*1635*/    /*Scope*/ 38, /*->1674*/
/*1636*/      OPC_CheckPredicate, 15, // Predicate_extload
/*1638*/      OPC_CheckPredicate, 17, // Predicate_extloadi8
/*1640*/      OPC_CheckType, MVT::i64,
/*1642*/      OPC_CheckPatternPredicate, 0, // (Subtarget.is64Bit())
/*1644*/      OPC_Scope, 13, /*->1659*/ // 2 children in Scope
/*1646*/        OPC_CheckComplexPat, /*CP*/0, /*#*/1, // SelectADDRrr:$addr #2 #3
/*1649*/        OPC_EmitMergeInputChains1_0,
/*1650*/        OPC_MorphNodeTo, TARGET_VAL(SP::LDUBrr), 0|OPFL_Chain|OPFL_MemRefs,
                    1/*#VTs*/, MVT::i64, 2/*#Ops*/, 2, 3, 
                // Src: (ld:i64 ADDRrr:iPTR:$addr)<<P:Predicate_unindexedload>><<P:Predicate_extload>><<P:Predicate_extloadi8>> - Complexity = 13
                // Dst: (LDUBrr:i64 ADDRrr:iPTR:$addr)
/*1659*/      /*Scope*/ 13, /*->1673*/
/*1660*/        OPC_CheckComplexPat, /*CP*/1, /*#*/1, // SelectADDRri:$addr #2 #3
/*1663*/        OPC_EmitMergeInputChains1_0,
/*1664*/        OPC_MorphNodeTo, TARGET_VAL(SP::LDUBri), 0|OPFL_Chain|OPFL_MemRefs,
                    1/*#VTs*/, MVT::i64, 2/*#Ops*/, 2, 3, 
                // Src: (ld:i64 ADDRri:iPTR:$addr)<<P:Predicate_unindexedload>><<P:Predicate_extload>><<P:Predicate_extloadi8>> - Complexity = 13
                // Dst: (LDUBri:i64 ADDRri:iPTR:$addr)
/*1673*/      0, /*End of Scope*/
/*1674*/    /*Scope*/ 38, /*->1713*/
/*1675*/      OPC_CheckPredicate, 8, // Predicate_sextload
/*1677*/      OPC_CheckPredicate, 9, // Predicate_sextloadi8
/*1679*/      OPC_CheckType, MVT::i64,
/*1681*/      OPC_CheckPatternPredicate, 0, // (Subtarget.is64Bit())
/*1683*/      OPC_Scope, 13, /*->1698*/ // 2 children in Scope
/*1685*/        OPC_CheckComplexPat, /*CP*/0, /*#*/1, // SelectADDRrr:$addr #2 #3
/*1688*/        OPC_EmitMergeInputChains1_0,
/*1689*/        OPC_MorphNodeTo, TARGET_VAL(SP::LDSBrr), 0|OPFL_Chain|OPFL_MemRefs,
                    1/*#VTs*/, MVT::i64, 2/*#Ops*/, 2, 3, 
                // Src: (ld:i64 ADDRrr:iPTR:$addr)<<P:Predicate_unindexedload>><<P:Predicate_sextload>><<P:Predicate_sextloadi8>> - Complexity = 13
                // Dst: (LDSBrr:i64 ADDRrr:iPTR:$addr)
/*1698*/      /*Scope*/ 13, /*->1712*/
/*1699*/        OPC_CheckComplexPat, /*CP*/1, /*#*/1, // SelectADDRri:$addr #2 #3
/*1702*/        OPC_EmitMergeInputChains1_0,
/*1703*/        OPC_MorphNodeTo, TARGET_VAL(SP::LDSBri), 0|OPFL_Chain|OPFL_MemRefs,
                    1/*#VTs*/, MVT::i64, 2/*#Ops*/, 2, 3, 
                // Src: (ld:i64 ADDRri:iPTR:$addr)<<P:Predicate_unindexedload>><<P:Predicate_sextload>><<P:Predicate_sextloadi8>> - Complexity = 13
                // Dst: (LDSBri:i64 ADDRri:iPTR:$addr)
/*1712*/      0, /*End of Scope*/
/*1713*/    /*Scope*/ 38, /*->1752*/
/*1714*/      OPC_CheckPredicate, 11, // Predicate_zextload
/*1716*/      OPC_CheckPredicate, 13, // Predicate_zextloadi16
/*1718*/      OPC_CheckType, MVT::i64,
/*1720*/      OPC_CheckPatternPredicate, 0, // (Subtarget.is64Bit())
/*1722*/      OPC_Scope, 13, /*->1737*/ // 2 children in Scope
/*1724*/        OPC_CheckComplexPat, /*CP*/0, /*#*/1, // SelectADDRrr:$addr #2 #3
/*1727*/        OPC_EmitMergeInputChains1_0,
/*1728*/        OPC_MorphNodeTo, TARGET_VAL(SP::LDUHrr), 0|OPFL_Chain|OPFL_MemRefs,
                    1/*#VTs*/, MVT::i64, 2/*#Ops*/, 2, 3, 
                // Src: (ld:i64 ADDRrr:iPTR:$addr)<<P:Predicate_unindexedload>><<P:Predicate_zextload>><<P:Predicate_zextloadi16>> - Complexity = 13
                // Dst: (LDUHrr:i64 ADDRrr:iPTR:$addr)
/*1737*/      /*Scope*/ 13, /*->1751*/
/*1738*/        OPC_CheckComplexPat, /*CP*/1, /*#*/1, // SelectADDRri:$addr #2 #3
/*1741*/        OPC_EmitMergeInputChains1_0,
/*1742*/        OPC_MorphNodeTo, TARGET_VAL(SP::LDUHri), 0|OPFL_Chain|OPFL_MemRefs,
                    1/*#VTs*/, MVT::i64, 2/*#Ops*/, 2, 3, 
                // Src: (ld:i64 ADDRri:iPTR:$addr)<<P:Predicate_unindexedload>><<P:Predicate_zextload>><<P:Predicate_zextloadi16>> - Complexity = 13
                // Dst: (LDUHri:i64 ADDRri:iPTR:$addr)
/*1751*/      0, /*End of Scope*/
/*1752*/    /*Scope*/ 38, /*->1791*/
/*1753*/      OPC_CheckPredicate, 15, // Predicate_extload
/*1755*/      OPC_CheckPredicate, 18, // Predicate_extloadi16
/*1757*/      OPC_CheckType, MVT::i64,
/*1759*/      OPC_CheckPatternPredicate, 0, // (Subtarget.is64Bit())
/*1761*/      OPC_Scope, 13, /*->1776*/ // 2 children in Scope
/*1763*/        OPC_CheckComplexPat, /*CP*/0, /*#*/1, // SelectADDRrr:$addr #2 #3
/*1766*/        OPC_EmitMergeInputChains1_0,
/*1767*/        OPC_MorphNodeTo, TARGET_VAL(SP::LDUHrr), 0|OPFL_Chain|OPFL_MemRefs,
                    1/*#VTs*/, MVT::i64, 2/*#Ops*/, 2, 3, 
                // Src: (ld:i64 ADDRrr:iPTR:$addr)<<P:Predicate_unindexedload>><<P:Predicate_extload>><<P:Predicate_extloadi16>> - Complexity = 13
                // Dst: (LDUHrr:i64 ADDRrr:iPTR:$addr)
/*1776*/      /*Scope*/ 13, /*->1790*/
/*1777*/        OPC_CheckComplexPat, /*CP*/1, /*#*/1, // SelectADDRri:$addr #2 #3
/*1780*/        OPC_EmitMergeInputChains1_0,
/*1781*/        OPC_MorphNodeTo, TARGET_VAL(SP::LDUHri), 0|OPFL_Chain|OPFL_MemRefs,
                    1/*#VTs*/, MVT::i64, 2/*#Ops*/, 2, 3, 
                // Src: (ld:i64 ADDRri:iPTR:$addr)<<P:Predicate_unindexedload>><<P:Predicate_extload>><<P:Predicate_extloadi16>> - Complexity = 13
                // Dst: (LDUHri:i64 ADDRri:iPTR:$addr)
/*1790*/      0, /*End of Scope*/
/*1791*/    /*Scope*/ 38, /*->1830*/
/*1792*/      OPC_CheckPredicate, 8, // Predicate_sextload
/*1794*/      OPC_CheckPredicate, 10, // Predicate_sextloadi16
/*1796*/      OPC_CheckType, MVT::i64,
/*1798*/      OPC_CheckPatternPredicate, 0, // (Subtarget.is64Bit())
/*1800*/      OPC_Scope, 13, /*->1815*/ // 2 children in Scope
/*1802*/        OPC_CheckComplexPat, /*CP*/0, /*#*/1, // SelectADDRrr:$addr #2 #3
/*1805*/        OPC_EmitMergeInputChains1_0,
/*1806*/        OPC_MorphNodeTo, TARGET_VAL(SP::LDSHrr), 0|OPFL_Chain|OPFL_MemRefs,
                    1/*#VTs*/, MVT::i64, 2/*#Ops*/, 2, 3, 
                // Src: (ld:i64 ADDRrr:iPTR:$addr)<<P:Predicate_unindexedload>><<P:Predicate_sextload>><<P:Predicate_sextloadi16>> - Complexity = 13
                // Dst: (LDSHrr:i64 ADDRrr:iPTR:$addr)
/*1815*/      /*Scope*/ 13, /*->1829*/
/*1816*/        OPC_CheckComplexPat, /*CP*/1, /*#*/1, // SelectADDRri:$addr #2 #3
/*1819*/        OPC_EmitMergeInputChains1_0,
/*1820*/        OPC_MorphNodeTo, TARGET_VAL(SP::LDSHri), 0|OPFL_Chain|OPFL_MemRefs,
                    1/*#VTs*/, MVT::i64, 2/*#Ops*/, 2, 3, 
                // Src: (ld:i64 ADDRri:iPTR:$addr)<<P:Predicate_unindexedload>><<P:Predicate_sextload>><<P:Predicate_sextloadi16>> - Complexity = 13
                // Dst: (LDSHri:i64 ADDRri:iPTR:$addr)
/*1829*/      0, /*End of Scope*/
/*1830*/    /*Scope*/ 38, /*->1869*/
/*1831*/      OPC_CheckPredicate, 11, // Predicate_zextload
/*1833*/      OPC_CheckPredicate, 20, // Predicate_zextloadi32
/*1835*/      OPC_CheckType, MVT::i64,
/*1837*/      OPC_CheckPatternPredicate, 0, // (Subtarget.is64Bit())
/*1839*/      OPC_Scope, 13, /*->1854*/ // 2 children in Scope
/*1841*/        OPC_CheckComplexPat, /*CP*/0, /*#*/1, // SelectADDRrr:$addr #2 #3
/*1844*/        OPC_EmitMergeInputChains1_0,
/*1845*/        OPC_MorphNodeTo, TARGET_VAL(SP::LDrr), 0|OPFL_Chain|OPFL_MemRefs,
                    1/*#VTs*/, MVT::i64, 2/*#Ops*/, 2, 3, 
                // Src: (ld:i64 ADDRrr:iPTR:$addr)<<P:Predicate_unindexedload>><<P:Predicate_zextload>><<P:Predicate_zextloadi32>> - Complexity = 13
                // Dst: (LDrr:i64 ADDRrr:iPTR:$addr)
/*1854*/      /*Scope*/ 13, /*->1868*/
/*1855*/        OPC_CheckComplexPat, /*CP*/1, /*#*/1, // SelectADDRri:$addr #2 #3
/*1858*/        OPC_EmitMergeInputChains1_0,
/*1859*/        OPC_MorphNodeTo, TARGET_VAL(SP::LDri), 0|OPFL_Chain|OPFL_MemRefs,
                    1/*#VTs*/, MVT::i64, 2/*#Ops*/, 2, 3, 
                // Src: (ld:i64 ADDRri:iPTR:$addr)<<P:Predicate_unindexedload>><<P:Predicate_zextload>><<P:Predicate_zextloadi32>> - Complexity = 13
                // Dst: (LDri:i64 ADDRri:iPTR:$addr)
/*1868*/      0, /*End of Scope*/
/*1869*/    /*Scope*/ 38, /*->1908*/
/*1870*/      OPC_CheckPredicate, 15, // Predicate_extload
/*1872*/      OPC_CheckPredicate, 21, // Predicate_extloadi32
/*1874*/      OPC_CheckType, MVT::i64,
/*1876*/      OPC_CheckPatternPredicate, 0, // (Subtarget.is64Bit())
/*1878*/      OPC_Scope, 13, /*->1893*/ // 2 children in Scope
/*1880*/        OPC_CheckComplexPat, /*CP*/0, /*#*/1, // SelectADDRrr:$addr #2 #3
/*1883*/        OPC_EmitMergeInputChains1_0,
/*1884*/        OPC_MorphNodeTo, TARGET_VAL(SP::LDrr), 0|OPFL_Chain|OPFL_MemRefs,
                    1/*#VTs*/, MVT::i64, 2/*#Ops*/, 2, 3, 
                // Src: (ld:i64 ADDRrr:iPTR:$addr)<<P:Predicate_unindexedload>><<P:Predicate_extload>><<P:Predicate_extloadi32>> - Complexity = 13
                // Dst: (LDrr:i64 ADDRrr:iPTR:$addr)
/*1893*/      /*Scope*/ 13, /*->1907*/
/*1894*/        OPC_CheckComplexPat, /*CP*/1, /*#*/1, // SelectADDRri:$addr #2 #3
/*1897*/        OPC_EmitMergeInputChains1_0,
/*1898*/        OPC_MorphNodeTo, TARGET_VAL(SP::LDri), 0|OPFL_Chain|OPFL_MemRefs,
                    1/*#VTs*/, MVT::i64, 2/*#Ops*/, 2, 3, 
                // Src: (ld:i64 ADDRri:iPTR:$addr)<<P:Predicate_unindexedload>><<P:Predicate_extload>><<P:Predicate_extloadi32>> - Complexity = 13
                // Dst: (LDri:i64 ADDRri:iPTR:$addr)
/*1907*/      0, /*End of Scope*/
/*1908*/    /*Scope*/ 38, /*->1947*/
/*1909*/      OPC_CheckPredicate, 8, // Predicate_sextload
/*1911*/      OPC_CheckPredicate, 22, // Predicate_sextloadi32
/*1913*/      OPC_CheckType, MVT::i64,
/*1915*/      OPC_CheckPatternPredicate, 0, // (Subtarget.is64Bit())
/*1917*/      OPC_Scope, 13, /*->1932*/ // 2 children in Scope
/*1919*/        OPC_CheckComplexPat, /*CP*/0, /*#*/1, // SelectADDRrr:$addr #2 #3
/*1922*/        OPC_EmitMergeInputChains1_0,
/*1923*/        OPC_MorphNodeTo, TARGET_VAL(SP::LDSWrr), 0|OPFL_Chain|OPFL_MemRefs,
                    1/*#VTs*/, MVT::i64, 2/*#Ops*/, 2, 3, 
                // Src: (ld:i64 ADDRrr:iPTR:$addr)<<P:Predicate_unindexedload>><<P:Predicate_sextload>><<P:Predicate_sextloadi32>> - Complexity = 13
                // Dst: (LDSWrr:i64 ADDRrr:iPTR:$addr)
/*1932*/      /*Scope*/ 13, /*->1946*/
/*1933*/        OPC_CheckComplexPat, /*CP*/1, /*#*/1, // SelectADDRri:$addr #2 #3
/*1936*/        OPC_EmitMergeInputChains1_0,
/*1937*/        OPC_MorphNodeTo, TARGET_VAL(SP::LDSWri), 0|OPFL_Chain|OPFL_MemRefs,
                    1/*#VTs*/, MVT::i64, 2/*#Ops*/, 2, 3, 
                // Src: (ld:i64 ADDRri:iPTR:$addr)<<P:Predicate_unindexedload>><<P:Predicate_sextload>><<P:Predicate_sextloadi32>> - Complexity = 13
                // Dst: (LDSWri:i64 ADDRri:iPTR:$addr)
/*1946*/      0, /*End of Scope*/
/*1947*/    /*Scope*/ 102, /*->2050*/
/*1948*/      OPC_CheckPredicate, 14, // Predicate_load
/*1950*/      OPC_SwitchType /*3 cases */, 30,  MVT::f32,// ->1983
/*1953*/        OPC_Scope, 13, /*->1968*/ // 2 children in Scope
/*1955*/          OPC_CheckComplexPat, /*CP*/0, /*#*/1, // SelectADDRrr:$addr #2 #3
/*1958*/          OPC_EmitMergeInputChains1_0,
/*1959*/          OPC_MorphNodeTo, TARGET_VAL(SP::LDFrr), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::f32, 2/*#Ops*/, 2, 3, 
                  // Src: (ld:f32 ADDRrr:iPTR:$addr)<<P:Predicate_unindexedload>><<P:Predicate_load>> - Complexity = 13
                  // Dst: (LDFrr:f32 ADDRrr:iPTR:$addr)
/*1968*/        /*Scope*/ 13, /*->1982*/
/*1969*/          OPC_CheckComplexPat, /*CP*/1, /*#*/1, // SelectADDRri:$addr #2 #3
/*1972*/          OPC_EmitMergeInputChains1_0,
/*1973*/          OPC_MorphNodeTo, TARGET_VAL(SP::LDFri), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::f32, 2/*#Ops*/, 2, 3, 
                  // Src: (ld:f32 ADDRri:iPTR:$addr)<<P:Predicate_unindexedload>><<P:Predicate_load>> - Complexity = 13
                  // Dst: (LDFri:f32 ADDRri:iPTR:$addr)
/*1982*/        0, /*End of Scope*/
/*1983*/      /*SwitchType*/ 30,  MVT::f64,// ->2015
/*1985*/        OPC_Scope, 13, /*->2000*/ // 2 children in Scope
/*1987*/          OPC_CheckComplexPat, /*CP*/0, /*#*/1, // SelectADDRrr:$addr #2 #3
/*1990*/          OPC_EmitMergeInputChains1_0,
/*1991*/          OPC_MorphNodeTo, TARGET_VAL(SP::LDDFrr), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::f64, 2/*#Ops*/, 2, 3, 
                  // Src: (ld:f64 ADDRrr:iPTR:$addr)<<P:Predicate_unindexedload>><<P:Predicate_load>> - Complexity = 13
                  // Dst: (LDDFrr:f64 ADDRrr:iPTR:$addr)
/*2000*/        /*Scope*/ 13, /*->2014*/
/*2001*/          OPC_CheckComplexPat, /*CP*/1, /*#*/1, // SelectADDRri:$addr #2 #3
/*2004*/          OPC_EmitMergeInputChains1_0,
/*2005*/          OPC_MorphNodeTo, TARGET_VAL(SP::LDDFri), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::f64, 2/*#Ops*/, 2, 3, 
                  // Src: (ld:f64 ADDRri:iPTR:$addr)<<P:Predicate_unindexedload>><<P:Predicate_load>> - Complexity = 13
                  // Dst: (LDDFri:f64 ADDRri:iPTR:$addr)
/*2014*/        0, /*End of Scope*/
/*2015*/      /*SwitchType*/ 32,  MVT::f128,// ->2049
/*2017*/        OPC_CheckPatternPredicate, 1, // (Subtarget.isV9()) && (Subtarget.hasHardQuad())
/*2019*/        OPC_Scope, 13, /*->2034*/ // 2 children in Scope
/*2021*/          OPC_CheckComplexPat, /*CP*/0, /*#*/1, // SelectADDRrr:$addr #2 #3
/*2024*/          OPC_EmitMergeInputChains1_0,
/*2025*/          OPC_MorphNodeTo, TARGET_VAL(SP::LDQFrr), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::f128, 2/*#Ops*/, 2, 3, 
                  // Src: (ld:f128 ADDRrr:iPTR:$addr)<<P:Predicate_unindexedload>><<P:Predicate_load>> - Complexity = 13
                  // Dst: (LDQFrr:f128 ADDRrr:iPTR:$addr)
/*2034*/        /*Scope*/ 13, /*->2048*/
/*2035*/          OPC_CheckComplexPat, /*CP*/1, /*#*/1, // SelectADDRri:$addr #2 #3
/*2038*/          OPC_EmitMergeInputChains1_0,
/*2039*/          OPC_MorphNodeTo, TARGET_VAL(SP::LDQFri), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::f128, 2/*#Ops*/, 2, 3, 
                  // Src: (ld:f128 ADDRri:iPTR:$addr)<<P:Predicate_unindexedload>><<P:Predicate_load>> - Complexity = 13
                  // Dst: (LDQFri:f128 ADDRri:iPTR:$addr)
/*2048*/        0, /*End of Scope*/
/*2049*/      0, // EndSwitchType
/*2050*/    0, /*End of Scope*/
/*2051*/  /*SwitchOpcode*/ 30,  TARGET_VAL(ISD::BRIND),// ->2084
/*2054*/    OPC_RecordNode,   // #0 = 'brind' chained node
/*2055*/    OPC_RecordChild1, // #1 = $ptr
/*2056*/    OPC_Scope, 12, /*->2070*/ // 2 children in Scope
/*2058*/      OPC_CheckComplexPat, /*CP*/0, /*#*/1, // SelectADDRrr:$ptr #2 #3
/*2061*/      OPC_EmitMergeInputChains1_0,
/*2062*/      OPC_MorphNodeTo, TARGET_VAL(SP::BINDrr), 0|OPFL_Chain,
                  0/*#VTs*/, 2/*#Ops*/, 2, 3, 
              // Src: (brind ADDRrr:iPTR:$ptr) - Complexity = 12
              // Dst: (BINDrr ADDRrr:iPTR:$ptr)
/*2070*/    /*Scope*/ 12, /*->2083*/
/*2071*/      OPC_CheckComplexPat, /*CP*/1, /*#*/1, // SelectADDRri:$ptr #2 #3
/*2074*/      OPC_EmitMergeInputChains1_0,
/*2075*/      OPC_MorphNodeTo, TARGET_VAL(SP::BINDri), 0|OPFL_Chain,
                  0/*#VTs*/, 2/*#Ops*/, 2, 3, 
              // Src: (brind ADDRri:iPTR:$ptr) - Complexity = 12
              // Dst: (BINDri ADDRri:iPTR:$ptr)
/*2083*/    0, /*End of Scope*/
/*2084*/  /*SwitchOpcode*/ 60,  TARGET_VAL(SPISD::CALL),// ->2147
/*2087*/    OPC_RecordNode,   // #0 = 'call' chained node
/*2088*/    OPC_CaptureGlueInput,
/*2089*/    OPC_RecordChild1, // #1 = $ptr
/*2090*/    OPC_Scope, 12, /*->2104*/ // 3 children in Scope
/*2092*/      OPC_CheckComplexPat, /*CP*/0, /*#*/1, // SelectADDRrr:$ptr #2 #3
/*2095*/      OPC_EmitMergeInputChains1_0,
/*2096*/      OPC_MorphNodeTo, TARGET_VAL(SP::JMPLrr), 0|OPFL_Chain|OPFL_GlueInput|OPFL_GlueOutput|OPFL_Variadic1,
                  0/*#VTs*/, 2/*#Ops*/, 2, 3, 
              // Src: (call ADDRrr:i32:$ptr) - Complexity = 12
              // Dst: (JMPLrr ADDRrr:i32:$ptr)
/*2104*/    /*Scope*/ 12, /*->2117*/
/*2105*/      OPC_CheckComplexPat, /*CP*/1, /*#*/1, // SelectADDRri:$ptr #2 #3
/*2108*/      OPC_EmitMergeInputChains1_0,
/*2109*/      OPC_MorphNodeTo, TARGET_VAL(SP::JMPLri), 0|OPFL_Chain|OPFL_GlueInput|OPFL_GlueOutput|OPFL_Variadic1,
                  0/*#VTs*/, 2/*#Ops*/, 2, 3, 
              // Src: (call ADDRri:i32:$ptr) - Complexity = 12
              // Dst: (JMPLri ADDRri:i32:$ptr)
/*2117*/    /*Scope*/ 28, /*->2146*/
/*2118*/      OPC_MoveChild, 1,
/*2120*/      OPC_SwitchOpcode /*2 cases */, 9,  TARGET_VAL(ISD::TargetGlobalAddress),// ->2133
/*2124*/        OPC_MoveParent,
/*2125*/        OPC_EmitMergeInputChains1_0,
/*2126*/        OPC_MorphNodeTo, TARGET_VAL(SP::CALL), 0|OPFL_Chain|OPFL_GlueInput|OPFL_GlueOutput|OPFL_Variadic1,
                    0/*#VTs*/, 1/*#Ops*/, 1, 
                // Src: (call (tglobaladdr:i32):$dst) - Complexity = 6
                // Dst: (CALL (tglobaladdr:i32):$dst)
/*2133*/      /*SwitchOpcode*/ 9,  TARGET_VAL(ISD::TargetExternalSymbol),// ->2145
/*2136*/        OPC_MoveParent,
/*2137*/        OPC_EmitMergeInputChains1_0,
/*2138*/        OPC_MorphNodeTo, TARGET_VAL(SP::CALL), 0|OPFL_Chain|OPFL_GlueInput|OPFL_GlueOutput|OPFL_Variadic1,
                    0/*#VTs*/, 1/*#Ops*/, 1, 
                // Src: (call (texternalsym:i32):$dst) - Complexity = 6
                // Dst: (CALL (texternalsym:i32):$dst)
/*2145*/      0, // EndSwitchOpcode
/*2146*/    0, /*End of Scope*/
/*2147*/  /*SwitchOpcode*/ 67|128,1/*195*/,  TARGET_VAL(ISD::AND),// ->2346
/*2151*/    OPC_Scope, 48, /*->2201*/ // 4 children in Scope
/*2153*/      OPC_RecordChild0, // #0 = $b
/*2154*/      OPC_MoveChild, 1,
/*2156*/      OPC_CheckOpcode, TARGET_VAL(ISD::XOR),
/*2159*/      OPC_RecordChild0, // #1 = $c
/*2160*/      OPC_MoveChild, 1,
/*2162*/      OPC_CheckInteger, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*2173*/      OPC_MoveParent,
/*2174*/      OPC_MoveParent,
/*2175*/      OPC_SwitchType /*2 cases */, 9,  MVT::i32,// ->2187
/*2178*/        OPC_MorphNodeTo, TARGET_VAL(SP::ANDNrr), 0,
                    1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1, 
                // Src: (and:i32 i32:i32:$b, (xor:i32 i32:i32:$c, -1:i32)) - Complexity = 11
                // Dst: (ANDNrr:i32 i32:i32:$b, i32:i32:$c)
/*2187*/      /*SwitchType*/ 11,  MVT::i64,// ->2200
/*2189*/        OPC_CheckPatternPredicate, 0, // (Subtarget.is64Bit())
/*2191*/        OPC_MorphNodeTo, TARGET_VAL(SP::ANDNrr), 0,
                    1/*#VTs*/, MVT::i64, 2/*#Ops*/, 0, 1, 
                // Src: (and:i64 i64:i64:$a, (xor:i64 i64:i64:$b, -1:i64)) - Complexity = 11
                // Dst: (ANDNrr:i64 ?:i64:$a, ?:i64:$b)
/*2200*/      0, // EndSwitchType
/*2201*/    /*Scope*/ 48, /*->2250*/
/*2202*/      OPC_MoveChild, 0,
/*2204*/      OPC_CheckOpcode, TARGET_VAL(ISD::XOR),
/*2207*/      OPC_RecordChild0, // #0 = $c
/*2208*/      OPC_MoveChild, 1,
/*2210*/      OPC_CheckInteger, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*2221*/      OPC_MoveParent,
/*2222*/      OPC_MoveParent,
/*2223*/      OPC_RecordChild1, // #1 = $b
/*2224*/      OPC_SwitchType /*2 cases */, 9,  MVT::i32,// ->2236
/*2227*/        OPC_MorphNodeTo, TARGET_VAL(SP::ANDNrr), 0,
                    1/*#VTs*/, MVT::i32, 2/*#Ops*/, 1, 0, 
                // Src: (and:i32 (xor:i32 i32:i32:$c, -1:i32), i32:i32:$b) - Complexity = 11
                // Dst: (ANDNrr:i32 i32:i32:$b, i32:i32:$c)
/*2236*/      /*SwitchType*/ 11,  MVT::i64,// ->2249
/*2238*/        OPC_CheckPatternPredicate, 0, // (Subtarget.is64Bit())
/*2240*/        OPC_MorphNodeTo, TARGET_VAL(SP::ANDNrr), 0,
                    1/*#VTs*/, MVT::i64, 2/*#Ops*/, 1, 0, 
                // Src: (and:i64 (xor:i64 i64:i64:$b, -1:i64), i64:i64:$a) - Complexity = 11
                // Dst: (ANDNrr:i64 ?:i64:$a, ?:i64:$b)
/*2249*/      0, // EndSwitchType
/*2250*/    /*Scope*/ 23, /*->2274*/
/*2251*/      OPC_CheckAndImm, 127|128,127|128,127|128,127|128,15/*4294967295*/, 
/*2257*/      OPC_RecordChild0, // #0 = $val
/*2258*/      OPC_CheckType, MVT::i64,
/*2260*/      OPC_CheckPatternPredicate, 0, // (Subtarget.is64Bit())
/*2262*/      OPC_EmitInteger, MVT::i32, 0, 
/*2265*/      OPC_MorphNodeTo, TARGET_VAL(SP::SRLri), 0,
                  1/*#VTs*/, MVT::i64, 2/*#Ops*/, 0, 1, 
              // Src: (and:i64 i64:i64:$val, 4294967295:i64) - Complexity = 8
              // Dst: (SRLri:i64 ?:i64:$val, 0:i32)
/*2274*/    /*Scope*/ 70, /*->2345*/
/*2275*/      OPC_RecordChild0, // #0 = $b
/*2276*/      OPC_RecordChild1, // #1 = $c
/*2277*/      OPC_Scope, 39, /*->2318*/ // 3 children in Scope
/*2279*/        OPC_MoveChild, 1,
/*2281*/        OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*2284*/        OPC_CheckPredicate, 6, // Predicate_simm13
/*2286*/        OPC_MoveParent,
/*2287*/        OPC_SwitchType /*2 cases */, 11,  MVT::i32,// ->2301
/*2290*/          OPC_EmitConvertToTarget, 1,
/*2292*/          OPC_MorphNodeTo, TARGET_VAL(SP::ANDri), 0,
                      1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 2, 
                  // Src: (and:i32 i32:i32:$b, (imm:i32)<<P:Predicate_simm13>>:$c) - Complexity = 7
                  // Dst: (ANDri:i32 i32:i32:$b, (imm:i32):$c)
/*2301*/        /*SwitchType*/ 14,  MVT::i64,// ->2317
/*2303*/          OPC_CheckPatternPredicate, 0, // (Subtarget.is64Bit())
/*2305*/          OPC_EmitNodeXForm, 0, 1, // as_i32imm
/*2308*/          OPC_MorphNodeTo, TARGET_VAL(SP::ANDri), 0,
                      1/*#VTs*/, MVT::i64, 2/*#Ops*/, 0, 2, 
                  // Src: (and:i64 i64:i64:$a, (imm:i64)<<P:Predicate_simm13>>:$b) - Complexity = 7
                  // Dst: (ANDri:i64 ?:i64:$a, (as_i32imm:i32 ?:i64:$b))
/*2317*/        0, // EndSwitchType
/*2318*/      /*Scope*/ 11, /*->2330*/
/*2319*/        OPC_CheckType, MVT::i32,
/*2321*/        OPC_MorphNodeTo, TARGET_VAL(SP::ANDrr), 0,
                    1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1, 
                // Src: (and:i32 i32:i32:$b, i32:i32:$c) - Complexity = 3
                // Dst: (ANDrr:i32 i32:i32:$b, i32:i32:$c)
/*2330*/      /*Scope*/ 13, /*->2344*/
/*2331*/        OPC_CheckType, MVT::i64,
/*2333*/        OPC_CheckPatternPredicate, 0, // (Subtarget.is64Bit())
/*2335*/        OPC_MorphNodeTo, TARGET_VAL(SP::ANDrr), 0,
                    1/*#VTs*/, MVT::i64, 2/*#Ops*/, 0, 1, 
                // Src: (and:i64 i64:i64:$a, i64:i64:$b) - Complexity = 3
                // Dst: (ANDrr:i64 ?:i64:$a, ?:i64:$b)
/*2344*/      0, /*End of Scope*/
/*2345*/    0, /*End of Scope*/
/*2346*/  /*SwitchOpcode*/ 43|128,1/*171*/,  TARGET_VAL(ISD::OR),// ->2521
/*2350*/    OPC_Scope, 48, /*->2400*/ // 3 children in Scope
/*2352*/      OPC_RecordChild0, // #0 = $b
/*2353*/      OPC_MoveChild, 1,
/*2355*/      OPC_CheckOpcode, TARGET_VAL(ISD::XOR),
/*2358*/      OPC_RecordChild0, // #1 = $c
/*2359*/      OPC_MoveChild, 1,
/*2361*/      OPC_CheckInteger, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*2372*/      OPC_MoveParent,
/*2373*/      OPC_MoveParent,
/*2374*/      OPC_SwitchType /*2 cases */, 9,  MVT::i32,// ->2386
/*2377*/        OPC_MorphNodeTo, TARGET_VAL(SP::ORNrr), 0,
                    1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1, 
                // Src: (or:i32 i32:i32:$b, (xor:i32 i32:i32:$c, -1:i32)) - Complexity = 11
                // Dst: (ORNrr:i32 i32:i32:$b, i32:i32:$c)
/*2386*/      /*SwitchType*/ 11,  MVT::i64,// ->2399
/*2388*/        OPC_CheckPatternPredicate, 0, // (Subtarget.is64Bit())
/*2390*/        OPC_MorphNodeTo, TARGET_VAL(SP::ORNrr), 0,
                    1/*#VTs*/, MVT::i64, 2/*#Ops*/, 0, 1, 
                // Src: (or:i64 i64:i64:$a, (xor:i64 i64:i64:$b, -1:i64)) - Complexity = 11
                // Dst: (ORNrr:i64 ?:i64:$a, ?:i64:$b)
/*2399*/      0, // EndSwitchType
/*2400*/    /*Scope*/ 48, /*->2449*/
/*2401*/      OPC_MoveChild, 0,
/*2403*/      OPC_CheckOpcode, TARGET_VAL(ISD::XOR),
/*2406*/      OPC_RecordChild0, // #0 = $c
/*2407*/      OPC_MoveChild, 1,
/*2409*/      OPC_CheckInteger, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*2420*/      OPC_MoveParent,
/*2421*/      OPC_MoveParent,
/*2422*/      OPC_RecordChild1, // #1 = $b
/*2423*/      OPC_SwitchType /*2 cases */, 9,  MVT::i32,// ->2435
/*2426*/        OPC_MorphNodeTo, TARGET_VAL(SP::ORNrr), 0,
                    1/*#VTs*/, MVT::i32, 2/*#Ops*/, 1, 0, 
                // Src: (or:i32 (xor:i32 i32:i32:$c, -1:i32), i32:i32:$b) - Complexity = 11
                // Dst: (ORNrr:i32 i32:i32:$b, i32:i32:$c)
/*2435*/      /*SwitchType*/ 11,  MVT::i64,// ->2448
/*2437*/        OPC_CheckPatternPredicate, 0, // (Subtarget.is64Bit())
/*2439*/        OPC_MorphNodeTo, TARGET_VAL(SP::ORNrr), 0,
                    1/*#VTs*/, MVT::i64, 2/*#Ops*/, 1, 0, 
                // Src: (or:i64 (xor:i64 i64:i64:$b, -1:i64), i64:i64:$a) - Complexity = 11
                // Dst: (ORNrr:i64 ?:i64:$a, ?:i64:$b)
/*2448*/      0, // EndSwitchType
/*2449*/    /*Scope*/ 70, /*->2520*/
/*2450*/      OPC_RecordChild0, // #0 = $b
/*2451*/      OPC_RecordChild1, // #1 = $c
/*2452*/      OPC_Scope, 39, /*->2493*/ // 3 children in Scope
/*2454*/        OPC_MoveChild, 1,
/*2456*/        OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*2459*/        OPC_CheckPredicate, 6, // Predicate_simm13
/*2461*/        OPC_MoveParent,
/*2462*/        OPC_SwitchType /*2 cases */, 11,  MVT::i32,// ->2476
/*2465*/          OPC_EmitConvertToTarget, 1,
/*2467*/          OPC_MorphNodeTo, TARGET_VAL(SP::ORri), 0,
                      1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 2, 
                  // Src: (or:i32 i32:i32:$b, (imm:i32)<<P:Predicate_simm13>>:$c) - Complexity = 7
                  // Dst: (ORri:i32 i32:i32:$b, (imm:i32):$c)
/*2476*/        /*SwitchType*/ 14,  MVT::i64,// ->2492
/*2478*/          OPC_CheckPatternPredicate, 0, // (Subtarget.is64Bit())
/*2480*/          OPC_EmitNodeXForm, 0, 1, // as_i32imm
/*2483*/          OPC_MorphNodeTo, TARGET_VAL(SP::ORri), 0,
                      1/*#VTs*/, MVT::i64, 2/*#Ops*/, 0, 2, 
                  // Src: (or:i64 i64:i64:$a, (imm:i64)<<P:Predicate_simm13>>:$b) - Complexity = 7
                  // Dst: (ORri:i64 ?:i64:$a, (as_i32imm:i32 ?:i64:$b))
/*2492*/        0, // EndSwitchType
/*2493*/      /*Scope*/ 11, /*->2505*/
/*2494*/        OPC_CheckType, MVT::i32,
/*2496*/        OPC_MorphNodeTo, TARGET_VAL(SP::ORrr), 0,
                    1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1, 
                // Src: (or:i32 i32:i32:$b, i32:i32:$c) - Complexity = 3
                // Dst: (ORrr:i32 i32:i32:$b, i32:i32:$c)
/*2505*/      /*Scope*/ 13, /*->2519*/
/*2506*/        OPC_CheckType, MVT::i64,
/*2508*/        OPC_CheckPatternPredicate, 0, // (Subtarget.is64Bit())
/*2510*/        OPC_MorphNodeTo, TARGET_VAL(SP::ORrr), 0,
                    1/*#VTs*/, MVT::i64, 2/*#Ops*/, 0, 1, 
                // Src: (or:i64 i64:i64:$a, i64:i64:$b) - Complexity = 3
                // Dst: (ORrr:i64 ?:i64:$a, ?:i64:$b)
/*2519*/      0, /*End of Scope*/
/*2520*/    0, /*End of Scope*/
/*2521*/  /*SwitchOpcode*/ 88|128,1/*216*/,  TARGET_VAL(SPISD::SELECT_ICC),// ->2741
/*2525*/    OPC_CaptureGlueInput,
/*2526*/    OPC_RecordChild0, // #0 = $simm11
/*2527*/    OPC_Scope, 55, /*->2584*/ // 2 children in Scope
/*2529*/      OPC_MoveChild, 0,
/*2531*/      OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*2534*/      OPC_CheckPredicate, 23, // Predicate_simm11
/*2536*/      OPC_MoveParent,
/*2537*/      OPC_RecordChild1, // #1 = $f
/*2538*/      OPC_RecordChild2, // #2 = $cond
/*2539*/      OPC_MoveChild, 2,
/*2541*/      OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*2544*/      OPC_MoveParent,
/*2545*/      OPC_SwitchType /*2 cases */, 16,  MVT::i32,// ->2564
/*2548*/        OPC_CheckPatternPredicate, 2, // (Subtarget.isV9())
/*2550*/        OPC_EmitConvertToTarget, 0,
/*2552*/        OPC_EmitConvertToTarget, 2,
/*2554*/        OPC_MorphNodeTo, TARGET_VAL(SP::MOVICCri), 0|OPFL_GlueInput,
                    1/*#VTs*/, MVT::i32, 3/*#Ops*/, 3, 1, 4, 
                // Src: (SPselecticc:i32 (imm:i32)<<P:Predicate_simm11>>:$simm11, i32:i32:$f, (imm:i32):$cond) - Complexity = 10
                // Dst: (MOVICCri:i32 (imm:i32):$simm11, i32:i32:$f, (imm:i32):$cond)
/*2564*/      /*SwitchType*/ 17,  MVT::i64,// ->2583
/*2566*/        OPC_CheckPatternPredicate, 0, // (Subtarget.is64Bit())
/*2568*/        OPC_EmitNodeXForm, 0, 0, // as_i32imm
/*2571*/        OPC_EmitConvertToTarget, 2,
/*2573*/        OPC_MorphNodeTo, TARGET_VAL(SP::MOVICCri), 0|OPFL_GlueInput,
                    1/*#VTs*/, MVT::i64, 3/*#Ops*/, 3, 1, 4, 
                // Src: (SPselecticc:i64 (imm:i64)<<P:Predicate_simm11>>:$t, i64:i64:$f, (imm:i32):$cond) - Complexity = 10
                // Dst: (MOVICCri:i64 (as_i32imm:i32 ?:i64:$t), ?:i64:$f, (imm:i32):$cond)
/*2583*/      0, // EndSwitchType
/*2584*/    /*Scope*/ 26|128,1/*154*/, /*->2740*/
/*2586*/      OPC_RecordChild1, // #1 = $f
/*2587*/      OPC_RecordChild2, // #2 = $cond
/*2588*/      OPC_MoveChild, 2,
/*2590*/      OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*2593*/      OPC_MoveParent,
/*2594*/      OPC_SwitchType /*5 cases */, 30,  MVT::i32,// ->2627
/*2597*/        OPC_Scope, 14, /*->2613*/ // 2 children in Scope
/*2599*/          OPC_CheckPatternPredicate, 2, // (Subtarget.isV9())
/*2601*/          OPC_EmitConvertToTarget, 2,
/*2603*/          OPC_MorphNodeTo, TARGET_VAL(SP::MOVICCrr), 0|OPFL_GlueInput,
                      1/*#VTs*/, MVT::i32, 3/*#Ops*/, 0, 1, 3, 
                  // Src: (SPselecticc:i32 i32:i32:$rs2, i32:i32:$f, (imm:i32):$cond) - Complexity = 6
                  // Dst: (MOVICCrr:i32 i32:i32:$rs2, i32:i32:$f, (imm:i32):$cond)
/*2613*/        /*Scope*/ 12, /*->2626*/
/*2614*/          OPC_EmitConvertToTarget, 2,
/*2616*/          OPC_MorphNodeTo, TARGET_VAL(SP::SELECT_CC_Int_ICC), 0|OPFL_GlueInput,
                      1/*#VTs*/, MVT::i32, 3/*#Ops*/, 0, 1, 3, 
                  // Src: (SPselecticc:i32 i32:i32:$T, i32:i32:$F, (imm:i32):$Cond) - Complexity = 6
                  // Dst: (SELECT_CC_Int_ICC:i32 i32:i32:$T, i32:i32:$F, (imm:i32):$Cond)
/*2626*/        0, /*End of Scope*/
/*2627*/      /*SwitchType*/ 14,  MVT::i64,// ->2643
/*2629*/        OPC_CheckPatternPredicate, 0, // (Subtarget.is64Bit())
/*2631*/        OPC_EmitConvertToTarget, 2,
/*2633*/        OPC_MorphNodeTo, TARGET_VAL(SP::MOVICCrr), 0|OPFL_GlueInput,
                    1/*#VTs*/, MVT::i64, 3/*#Ops*/, 0, 1, 3, 
                // Src: (SPselecticc:i64 i64:i64:$t, i64:i64:$f, (imm:i32):$cond) - Complexity = 6
                // Dst: (MOVICCrr:i64 ?:i64:$t, ?:i64:$f, (imm:i32):$cond)
/*2643*/      /*SwitchType*/ 30,  MVT::f32,// ->2675
/*2645*/        OPC_Scope, 14, /*->2661*/ // 2 children in Scope
/*2647*/          OPC_CheckPatternPredicate, 2, // (Subtarget.isV9())
/*2649*/          OPC_EmitConvertToTarget, 2,
/*2651*/          OPC_MorphNodeTo, TARGET_VAL(SP::FMOVS_ICC), 0|OPFL_GlueInput,
                      1/*#VTs*/, MVT::f32, 3/*#Ops*/, 0, 1, 3, 
                  // Src: (SPselecticc:f32 f32:f32:$rs2, f32:f32:$f, (imm:i32):$cond) - Complexity = 6
                  // Dst: (FMOVS_ICC:f32 f32:f32:$rs2, f32:f32:$f, (imm:i32):$cond)
/*2661*/        /*Scope*/ 12, /*->2674*/
/*2662*/          OPC_EmitConvertToTarget, 2,
/*2664*/          OPC_MorphNodeTo, TARGET_VAL(SP::SELECT_CC_FP_ICC), 0|OPFL_GlueInput,
                      1/*#VTs*/, MVT::f32, 3/*#Ops*/, 0, 1, 3, 
                  // Src: (SPselecticc:f32 f32:f32:$T, f32:f32:$F, (imm:i32):$Cond) - Complexity = 6
                  // Dst: (SELECT_CC_FP_ICC:f32 f32:f32:$T, f32:f32:$F, (imm:i32):$Cond)
/*2674*/        0, /*End of Scope*/
/*2675*/      /*SwitchType*/ 30,  MVT::f64,// ->2707
/*2677*/        OPC_Scope, 14, /*->2693*/ // 2 children in Scope
/*2679*/          OPC_CheckPatternPredicate, 2, // (Subtarget.isV9())
/*2681*/          OPC_EmitConvertToTarget, 2,
/*2683*/          OPC_MorphNodeTo, TARGET_VAL(SP::FMOVD_ICC), 0|OPFL_GlueInput,
                      1/*#VTs*/, MVT::f64, 3/*#Ops*/, 0, 1, 3, 
                  // Src: (SPselecticc:f64 f64:f64:$rs2, f64:f64:$f, (imm:i32):$cond) - Complexity = 6
                  // Dst: (FMOVD_ICC:f64 f64:f64:$rs2, f64:f64:$f, (imm:i32):$cond)
/*2693*/        /*Scope*/ 12, /*->2706*/
/*2694*/          OPC_EmitConvertToTarget, 2,
/*2696*/          OPC_MorphNodeTo, TARGET_VAL(SP::SELECT_CC_DFP_ICC), 0|OPFL_GlueInput,
                      1/*#VTs*/, MVT::f64, 3/*#Ops*/, 0, 1, 3, 
                  // Src: (SPselecticc:f64 f64:f64:$T, f64:f64:$F, (imm:i32):$Cond) - Complexity = 6
                  // Dst: (SELECT_CC_DFP_ICC:f64 f64:f64:$T, f64:f64:$F, (imm:i32):$Cond)
/*2706*/        0, /*End of Scope*/
/*2707*/      /*SwitchType*/ 30,  MVT::f128,// ->2739
/*2709*/        OPC_Scope, 14, /*->2725*/ // 2 children in Scope
/*2711*/          OPC_CheckPatternPredicate, 2, // (Subtarget.isV9())
/*2713*/          OPC_EmitConvertToTarget, 2,
/*2715*/          OPC_MorphNodeTo, TARGET_VAL(SP::FMOVQ_ICC), 0|OPFL_GlueInput,
                      1/*#VTs*/, MVT::f128, 3/*#Ops*/, 0, 1, 3, 
                  // Src: (SPselecticc:f128 f128:f128:$rs2, f128:f128:$f, (imm:i32):$cond) - Complexity = 6
                  // Dst: (FMOVQ_ICC:f128 f128:f128:$rs2, f128:f128:$f, (imm:i32):$cond)
/*2725*/        /*Scope*/ 12, /*->2738*/
/*2726*/          OPC_EmitConvertToTarget, 2,
/*2728*/          OPC_MorphNodeTo, TARGET_VAL(SP::SELECT_CC_QFP_ICC), 0|OPFL_GlueInput,
                      1/*#VTs*/, MVT::f128, 3/*#Ops*/, 0, 1, 3, 
                  // Src: (SPselecticc:f128 f128:f128:$T, f128:f128:$F, (imm:i32):$Cond) - Complexity = 6
                  // Dst: (SELECT_CC_QFP_ICC:f128 f128:f128:$T, f128:f128:$F, (imm:i32):$Cond)
/*2738*/        0, /*End of Scope*/
/*2739*/      0, // EndSwitchType
/*2740*/    0, /*End of Scope*/
/*2741*/  /*SwitchOpcode*/ 88|128,1/*216*/,  TARGET_VAL(SPISD::SELECT_FCC),// ->2961
/*2745*/    OPC_CaptureGlueInput,
/*2746*/    OPC_RecordChild0, // #0 = $simm11
/*2747*/    OPC_Scope, 55, /*->2804*/ // 2 children in Scope
/*2749*/      OPC_MoveChild, 0,
/*2751*/      OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*2754*/      OPC_CheckPredicate, 23, // Predicate_simm11
/*2756*/      OPC_MoveParent,
/*2757*/      OPC_RecordChild1, // #1 = $f
/*2758*/      OPC_RecordChild2, // #2 = $cond
/*2759*/      OPC_MoveChild, 2,
/*2761*/      OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*2764*/      OPC_MoveParent,
/*2765*/      OPC_SwitchType /*2 cases */, 16,  MVT::i32,// ->2784
/*2768*/        OPC_CheckPatternPredicate, 2, // (Subtarget.isV9())
/*2770*/        OPC_EmitConvertToTarget, 0,
/*2772*/        OPC_EmitConvertToTarget, 2,
/*2774*/        OPC_MorphNodeTo, TARGET_VAL(SP::MOVFCCri), 0|OPFL_GlueInput,
                    1/*#VTs*/, MVT::i32, 3/*#Ops*/, 3, 1, 4, 
                // Src: (SPselectfcc:i32 (imm:i32)<<P:Predicate_simm11>>:$simm11, i32:i32:$f, (imm:i32):$cond) - Complexity = 10
                // Dst: (MOVFCCri:i32 (imm:i32):$simm11, i32:i32:$f, (imm:i32):$cond)
/*2784*/      /*SwitchType*/ 17,  MVT::i64,// ->2803
/*2786*/        OPC_CheckPatternPredicate, 0, // (Subtarget.is64Bit())
/*2788*/        OPC_EmitNodeXForm, 0, 0, // as_i32imm
/*2791*/        OPC_EmitConvertToTarget, 2,
/*2793*/        OPC_MorphNodeTo, TARGET_VAL(SP::MOVFCCri), 0|OPFL_GlueInput,
                    1/*#VTs*/, MVT::i64, 3/*#Ops*/, 3, 1, 4, 
                // Src: (SPselectfcc:i64 (imm:i64)<<P:Predicate_simm11>>:$t, i64:i64:$f, (imm:i32):$cond) - Complexity = 10
                // Dst: (MOVFCCri:i64 (as_i32imm:i32 ?:i64:$t), ?:i64:$f, (imm:i32):$cond)
/*2803*/      0, // EndSwitchType
/*2804*/    /*Scope*/ 26|128,1/*154*/, /*->2960*/
/*2806*/      OPC_RecordChild1, // #1 = $f
/*2807*/      OPC_RecordChild2, // #2 = $cond
/*2808*/      OPC_MoveChild, 2,
/*2810*/      OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*2813*/      OPC_MoveParent,
/*2814*/      OPC_SwitchType /*5 cases */, 30,  MVT::i32,// ->2847
/*2817*/        OPC_Scope, 14, /*->2833*/ // 2 children in Scope
/*2819*/          OPC_CheckPatternPredicate, 2, // (Subtarget.isV9())
/*2821*/          OPC_EmitConvertToTarget, 2,
/*2823*/          OPC_MorphNodeTo, TARGET_VAL(SP::MOVFCCrr), 0|OPFL_GlueInput,
                      1/*#VTs*/, MVT::i32, 3/*#Ops*/, 0, 1, 3, 
                  // Src: (SPselectfcc:i32 i32:i32:$rs2, i32:i32:$f, (imm:i32):$cond) - Complexity = 6
                  // Dst: (MOVFCCrr:i32 i32:i32:$rs2, i32:i32:$f, (imm:i32):$cond)
/*2833*/        /*Scope*/ 12, /*->2846*/
/*2834*/          OPC_EmitConvertToTarget, 2,
/*2836*/          OPC_MorphNodeTo, TARGET_VAL(SP::SELECT_CC_Int_FCC), 0|OPFL_GlueInput,
                      1/*#VTs*/, MVT::i32, 3/*#Ops*/, 0, 1, 3, 
                  // Src: (SPselectfcc:i32 i32:i32:$T, i32:i32:$F, (imm:i32):$Cond) - Complexity = 6
                  // Dst: (SELECT_CC_Int_FCC:i32 i32:i32:$T, i32:i32:$F, (imm:i32):$Cond)
/*2846*/        0, /*End of Scope*/
/*2847*/      /*SwitchType*/ 14,  MVT::i64,// ->2863
/*2849*/        OPC_CheckPatternPredicate, 0, // (Subtarget.is64Bit())
/*2851*/        OPC_EmitConvertToTarget, 2,
/*2853*/        OPC_MorphNodeTo, TARGET_VAL(SP::MOVFCCrr), 0|OPFL_GlueInput,
                    1/*#VTs*/, MVT::i64, 3/*#Ops*/, 0, 1, 3, 
                // Src: (SPselectfcc:i64 i64:i64:$t, i64:i64:$f, (imm:i32):$cond) - Complexity = 6
                // Dst: (MOVFCCrr:i64 ?:i64:$t, ?:i64:$f, (imm:i32):$cond)
/*2863*/      /*SwitchType*/ 30,  MVT::f32,// ->2895
/*2865*/        OPC_Scope, 14, /*->2881*/ // 2 children in Scope
/*2867*/          OPC_CheckPatternPredicate, 2, // (Subtarget.isV9())
/*2869*/          OPC_EmitConvertToTarget, 2,
/*2871*/          OPC_MorphNodeTo, TARGET_VAL(SP::FMOVS_FCC), 0|OPFL_GlueInput,
                      1/*#VTs*/, MVT::f32, 3/*#Ops*/, 0, 1, 3, 
                  // Src: (SPselectfcc:f32 f32:f32:$rs2, f32:f32:$f, (imm:i32):$cond) - Complexity = 6
                  // Dst: (FMOVS_FCC:f32 f32:f32:$rs2, f32:f32:$f, (imm:i32):$cond)
/*2881*/        /*Scope*/ 12, /*->2894*/
/*2882*/          OPC_EmitConvertToTarget, 2,
/*2884*/          OPC_MorphNodeTo, TARGET_VAL(SP::SELECT_CC_FP_FCC), 0|OPFL_GlueInput,
                      1/*#VTs*/, MVT::f32, 3/*#Ops*/, 0, 1, 3, 
                  // Src: (SPselectfcc:f32 f32:f32:$T, f32:f32:$F, (imm:i32):$Cond) - Complexity = 6
                  // Dst: (SELECT_CC_FP_FCC:f32 f32:f32:$T, f32:f32:$F, (imm:i32):$Cond)
/*2894*/        0, /*End of Scope*/
/*2895*/      /*SwitchType*/ 30,  MVT::f64,// ->2927
/*2897*/        OPC_Scope, 14, /*->2913*/ // 2 children in Scope
/*2899*/          OPC_CheckPatternPredicate, 2, // (Subtarget.isV9())
/*2901*/          OPC_EmitConvertToTarget, 2,
/*2903*/          OPC_MorphNodeTo, TARGET_VAL(SP::FMOVD_FCC), 0|OPFL_GlueInput,
                      1/*#VTs*/, MVT::f64, 3/*#Ops*/, 0, 1, 3, 
                  // Src: (SPselectfcc:f64 f64:f64:$rs2, f64:f64:$f, (imm:i32):$cond) - Complexity = 6
                  // Dst: (FMOVD_FCC:f64 f64:f64:$rs2, f64:f64:$f, (imm:i32):$cond)
/*2913*/        /*Scope*/ 12, /*->2926*/
/*2914*/          OPC_EmitConvertToTarget, 2,
/*2916*/          OPC_MorphNodeTo, TARGET_VAL(SP::SELECT_CC_DFP_FCC), 0|OPFL_GlueInput,
                      1/*#VTs*/, MVT::f64, 3/*#Ops*/, 0, 1, 3, 
                  // Src: (SPselectfcc:f64 f64:f64:$T, f64:f64:$F, (imm:i32):$Cond) - Complexity = 6
                  // Dst: (SELECT_CC_DFP_FCC:f64 f64:f64:$T, f64:f64:$F, (imm:i32):$Cond)
/*2926*/        0, /*End of Scope*/
/*2927*/      /*SwitchType*/ 30,  MVT::f128,// ->2959
/*2929*/        OPC_Scope, 14, /*->2945*/ // 2 children in Scope
/*2931*/          OPC_CheckPatternPredicate, 2, // (Subtarget.isV9())
/*2933*/          OPC_EmitConvertToTarget, 2,
/*2935*/          OPC_MorphNodeTo, TARGET_VAL(SP::FMOVQ_FCC), 0|OPFL_GlueInput,
                      1/*#VTs*/, MVT::f128, 3/*#Ops*/, 0, 1, 3, 
                  // Src: (SPselectfcc:f128 f128:f128:$rs2, f128:f128:$f, (imm:i32):$cond) - Complexity = 6
                  // Dst: (FMOVQ_FCC:f128 f128:f128:$rs2, f128:f128:$f, (imm:i32):$cond)
/*2945*/        /*Scope*/ 12, /*->2958*/
/*2946*/          OPC_EmitConvertToTarget, 2,
/*2948*/          OPC_MorphNodeTo, TARGET_VAL(SP::SELECT_CC_QFP_FCC), 0|OPFL_GlueInput,
                      1/*#VTs*/, MVT::f128, 3/*#Ops*/, 0, 1, 3, 
                  // Src: (SPselectfcc:f128 f128:f128:$T, f128:f128:$F, (imm:i32):$Cond) - Complexity = 6
                  // Dst: (SELECT_CC_QFP_FCC:f128 f128:f128:$T, f128:f128:$F, (imm:i32):$Cond)
/*2958*/        0, /*End of Scope*/
/*2959*/      0, // EndSwitchType
/*2960*/    0, /*End of Scope*/
/*2961*/  /*SwitchOpcode*/ 7|128,1/*135*/,  TARGET_VAL(SPISD::SELECT_XCC),// ->3100
/*2965*/    OPC_CaptureGlueInput,
/*2966*/    OPC_RecordChild0, // #0 = $i
/*2967*/    OPC_Scope, 55, /*->3024*/ // 2 children in Scope
/*2969*/      OPC_MoveChild, 0,
/*2971*/      OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*2974*/      OPC_CheckPredicate, 23, // Predicate_simm11
/*2976*/      OPC_MoveParent,
/*2977*/      OPC_RecordChild1, // #1 = $f
/*2978*/      OPC_RecordChild2, // #2 = $cond
/*2979*/      OPC_MoveChild, 2,
/*2981*/      OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*2984*/      OPC_MoveParent,
/*2985*/      OPC_SwitchType /*2 cases */, 16,  MVT::i32,// ->3004
/*2988*/        OPC_CheckPatternPredicate, 0, // (Subtarget.is64Bit())
/*2990*/        OPC_EmitConvertToTarget, 0,
/*2992*/        OPC_EmitConvertToTarget, 2,
/*2994*/        OPC_MorphNodeTo, TARGET_VAL(SP::MOVXCCri), 0|OPFL_GlueInput,
                    1/*#VTs*/, MVT::i32, 3/*#Ops*/, 3, 1, 4, 
                // Src: (SPselectxcc:i32 (imm:i32)<<P:Predicate_simm11>>:$i, i32:i32:$f, (imm:i32):$cond) - Complexity = 10
                // Dst: (MOVXCCri:i32 (imm:i32):$i, i32:i32:$f, (imm:i32):$cond)
/*3004*/      /*SwitchType*/ 17,  MVT::i64,// ->3023
/*3006*/        OPC_CheckPatternPredicate, 0, // (Subtarget.is64Bit())
/*3008*/        OPC_EmitNodeXForm, 0, 0, // as_i32imm
/*3011*/        OPC_EmitConvertToTarget, 2,
/*3013*/        OPC_MorphNodeTo, TARGET_VAL(SP::MOVXCCri), 0|OPFL_GlueInput,
                    1/*#VTs*/, MVT::i64, 3/*#Ops*/, 3, 1, 4, 
                // Src: (SPselectxcc:i64 (imm:i64)<<P:Predicate_simm11>>:$t, i64:i64:$f, (imm:i32):$cond) - Complexity = 10
                // Dst: (MOVXCCri:i64 (as_i32imm:i32 ?:i64:$t), ?:i64:$f, (imm:i32):$cond)
/*3023*/      0, // EndSwitchType
/*3024*/    /*Scope*/ 74, /*->3099*/
/*3025*/      OPC_RecordChild1, // #1 = $f
/*3026*/      OPC_RecordChild2, // #2 = $cond
/*3027*/      OPC_MoveChild, 2,
/*3029*/      OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*3032*/      OPC_MoveParent,
/*3033*/      OPC_SwitchType /*4 cases */, 14,  MVT::i32,// ->3050
/*3036*/        OPC_CheckPatternPredicate, 0, // (Subtarget.is64Bit())
/*3038*/        OPC_EmitConvertToTarget, 2,
/*3040*/        OPC_MorphNodeTo, TARGET_VAL(SP::MOVXCCrr), 0|OPFL_GlueInput,
                    1/*#VTs*/, MVT::i32, 3/*#Ops*/, 0, 1, 3, 
                // Src: (SPselectxcc:i32 i32:i32:$rs2, i32:i32:$f, (imm:i32):$cond) - Complexity = 6
                // Dst: (MOVXCCrr:i32 i32:i32:$rs2, i32:i32:$f, (imm:i32):$cond)
/*3050*/      /*SwitchType*/ 14,  MVT::i64,// ->3066
/*3052*/        OPC_CheckPatternPredicate, 0, // (Subtarget.is64Bit())
/*3054*/        OPC_EmitConvertToTarget, 2,
/*3056*/        OPC_MorphNodeTo, TARGET_VAL(SP::MOVXCCrr), 0|OPFL_GlueInput,
                    1/*#VTs*/, MVT::i64, 3/*#Ops*/, 0, 1, 3, 
                // Src: (SPselectxcc:i64 i64:i64:$t, i64:i64:$f, (imm:i32):$cond) - Complexity = 6
                // Dst: (MOVXCCrr:i64 ?:i64:$t, ?:i64:$f, (imm:i32):$cond)
/*3066*/      /*SwitchType*/ 14,  MVT::f32,// ->3082
/*3068*/        OPC_CheckPatternPredicate, 0, // (Subtarget.is64Bit())
/*3070*/        OPC_EmitConvertToTarget, 2,
/*3072*/        OPC_MorphNodeTo, TARGET_VAL(SP::FMOVS_XCC), 0|OPFL_GlueInput,
                    1/*#VTs*/, MVT::f32, 3/*#Ops*/, 0, 1, 3, 
                // Src: (SPselectxcc:f32 f32:f32:$rs2, f32:f32:$f, (imm:i32):$cond) - Complexity = 6
                // Dst: (FMOVS_XCC:f32 f32:f32:$rs2, f32:f32:$f, (imm:i32):$cond)
/*3082*/      /*SwitchType*/ 14,  MVT::f64,// ->3098
/*3084*/        OPC_CheckPatternPredicate, 0, // (Subtarget.is64Bit())
/*3086*/        OPC_EmitConvertToTarget, 2,
/*3088*/        OPC_MorphNodeTo, TARGET_VAL(SP::FMOVD_XCC), 0|OPFL_GlueInput,
                    1/*#VTs*/, MVT::f64, 3/*#Ops*/, 0, 1, 3, 
                // Src: (SPselectxcc:f64 f64:f64:$rs2, f64:f64:$f, (imm:i32):$cond) - Complexity = 6
                // Dst: (FMOVD_XCC:f64 f64:f64:$rs2, f64:f64:$f, (imm:i32):$cond)
/*3098*/      0, // EndSwitchType
/*3099*/    0, /*End of Scope*/
/*3100*/  /*SwitchOpcode*/ 25,  TARGET_VAL(ISD::CALLSEQ_END),// ->3128
/*3103*/    OPC_RecordNode,   // #0 = 'callseq_end' chained node
/*3104*/    OPC_CaptureGlueInput,
/*3105*/    OPC_RecordChild1, // #1 = $amt1
/*3106*/    OPC_MoveChild, 1,
/*3108*/    OPC_CheckOpcode, TARGET_VAL(ISD::TargetConstant),
/*3111*/    OPC_MoveParent,
/*3112*/    OPC_RecordChild2, // #2 = $amt2
/*3113*/    OPC_MoveChild, 2,
/*3115*/    OPC_CheckOpcode, TARGET_VAL(ISD::TargetConstant),
/*3118*/    OPC_MoveParent,
/*3119*/    OPC_EmitMergeInputChains1_0,
/*3120*/    OPC_MorphNodeTo, TARGET_VAL(SP::ADJCALLSTACKUP), 0|OPFL_Chain|OPFL_GlueInput|OPFL_GlueOutput,
                0/*#VTs*/, 2/*#Ops*/, 1, 2, 
            // Src: (callseq_end (timm:i32):$amt1, (timm:i32):$amt2) - Complexity = 9
            // Dst: (ADJCALLSTACKUP (timm:i32):$amt1, (timm:i32):$amt2)
/*3128*/  /*SwitchOpcode*/ 35,  TARGET_VAL(ISD::FrameIndex),// ->3166
/*3131*/    OPC_RecordNode,   // #0 = $addr
/*3132*/    OPC_CheckType, MVT::iPTR,
/*3134*/    OPC_Scope, 14, /*->3150*/ // 2 children in Scope
/*3136*/      OPC_CheckPatternPredicate, 3, // (!Subtarget.is64Bit())
/*3138*/      OPC_CheckComplexPat, /*CP*/1, /*#*/0, // SelectADDRri:$addr #1 #2
/*3141*/      OPC_MorphNodeTo, TARGET_VAL(SP::LEA_ADDri), 0,
                  1/*#VTs*/, MVT::iPTR, 2/*#Ops*/, 1, 2, 
              // Src: ADDRri:iPTR:$addr - Complexity = 9
              // Dst: (LEA_ADDri:iPTR ADDRri:iPTR:$addr)
/*3150*/    /*Scope*/ 14, /*->3165*/
/*3151*/      OPC_CheckPatternPredicate, 0, // (Subtarget.is64Bit())
/*3153*/      OPC_CheckComplexPat, /*CP*/1, /*#*/0, // SelectADDRri:$addr #1 #2
/*3156*/      OPC_MorphNodeTo, TARGET_VAL(SP::LEAX_ADDri), 0,
                  1/*#VTs*/, MVT::i64, 2/*#Ops*/, 1, 2, 
              // Src: ADDRri:iPTR:$addr - Complexity = 9
              // Dst: (LEAX_ADDri:i64 ADDRri:iPTR:$addr)
/*3165*/    0, /*End of Scope*/
/*3166*/  /*SwitchOpcode*/ 25,  TARGET_VAL(SPISD::TLS_CALL),// ->3194
/*3169*/    OPC_RecordNode,   // #0 = 'tlscall' chained node
/*3170*/    OPC_CaptureGlueInput,
/*3171*/    OPC_RecordChild1, // #1 = $disp
/*3172*/    OPC_MoveChild, 1,
/*3174*/    OPC_CheckOpcode, TARGET_VAL(ISD::TargetExternalSymbol),
/*3177*/    OPC_MoveParent,
/*3178*/    OPC_RecordChild2, // #2 = $sym
/*3179*/    OPC_MoveChild, 2,
/*3181*/    OPC_CheckOpcode, TARGET_VAL(ISD::TargetGlobalTLSAddress),
/*3184*/    OPC_MoveParent,
/*3185*/    OPC_EmitMergeInputChains1_0,
/*3186*/    OPC_MorphNodeTo, TARGET_VAL(SP::TLS_CALL), 0|OPFL_Chain|OPFL_GlueInput|OPFL_GlueOutput|OPFL_Variadic2,
                0/*#VTs*/, 2/*#Ops*/, 1, 2, 
            // Src: (tlscall (texternalsym:i32):$disp, (tglobaltlsaddr:iPTR):$sym) - Complexity = 9
            // Dst: (TLS_CALL (texternalsym:i32):$disp, (tglobaltlsaddr:iPTR):$sym)
/*3194*/  /*SwitchOpcode*/ 21,  TARGET_VAL(SPISD::RET_FLAG),// ->3218
/*3197*/    OPC_RecordNode,   // #0 = 'retflag' chained node
/*3198*/    OPC_CaptureGlueInput,
/*3199*/    OPC_RecordChild1, // #1 = $val
/*3200*/    OPC_MoveChild, 1,
/*3202*/    OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*3205*/    OPC_CheckPredicate, 6, // Predicate_simm13
/*3207*/    OPC_MoveParent,
/*3208*/    OPC_EmitMergeInputChains1_0,
/*3209*/    OPC_EmitConvertToTarget, 1,
/*3211*/    OPC_MorphNodeTo, TARGET_VAL(SP::RETL), 0|OPFL_Chain|OPFL_GlueInput|OPFL_Variadic1,
                0/*#VTs*/, 1/*#Ops*/, 2, 
            // Src: (retflag (imm:i32)<<P:Predicate_simm13>>:$val) - Complexity = 7
            // Dst: (RETL (imm:i32):$val)
/*3218*/  /*SwitchOpcode*/ 77,  TARGET_VAL(ISD::SHL),// ->3298
/*3221*/    OPC_RecordChild0, // #0 = $b
/*3222*/    OPC_RecordChild1, // #1 = $c
/*3223*/    OPC_Scope, 43, /*->3268*/ // 2 children in Scope
/*3225*/      OPC_MoveChild, 1,
/*3227*/      OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*3230*/      OPC_CheckType, MVT::i32,
/*3232*/      OPC_Scope, 16, /*->3250*/ // 2 children in Scope
/*3234*/        OPC_CheckPredicate, 6, // Predicate_simm13
/*3236*/        OPC_MoveParent,
/*3237*/        OPC_CheckType, MVT::i32,
/*3239*/        OPC_EmitConvertToTarget, 1,
/*3241*/        OPC_MorphNodeTo, TARGET_VAL(SP::SLLri), 0,
                    1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 2, 
                // Src: (shl:i32 i32:i32:$b, (imm:i32)<<P:Predicate_simm13>>:$c) - Complexity = 7
                // Dst: (SLLri:i32 i32:i32:$b, (imm:i32):$c)
/*3250*/      /*Scope*/ 16, /*->3267*/
/*3251*/        OPC_MoveParent,
/*3252*/        OPC_CheckType, MVT::i64,
/*3254*/        OPC_CheckPatternPredicate, 0, // (Subtarget.is64Bit())
/*3256*/        OPC_EmitConvertToTarget, 1,
/*3258*/        OPC_MorphNodeTo, TARGET_VAL(SP::SLLXri), 0,
                    1/*#VTs*/, MVT::i64, 2/*#Ops*/, 0, 2, 
                // Src: (shl:i64 i64:i64:$rs, (imm:i32):$shcnt) - Complexity = 6
                // Dst: (SLLXri:i64 i64:i64:$rs, (imm:i32):$shcnt)
/*3267*/      0, /*End of Scope*/
/*3268*/    /*Scope*/ 28, /*->3297*/
/*3269*/      OPC_CheckChild1Type, MVT::i32,
/*3271*/      OPC_SwitchType /*2 cases */, 9,  MVT::i32,// ->3283
/*3274*/        OPC_MorphNodeTo, TARGET_VAL(SP::SLLrr), 0,
                    1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1, 
                // Src: (shl:i32 i32:i32:$b, i32:i32:$c) - Complexity = 3
                // Dst: (SLLrr:i32 i32:i32:$b, i32:i32:$c)
/*3283*/      /*SwitchType*/ 11,  MVT::i64,// ->3296
/*3285*/        OPC_CheckPatternPredicate, 0, // (Subtarget.is64Bit())
/*3287*/        OPC_MorphNodeTo, TARGET_VAL(SP::SLLXrr), 0,
                    1/*#VTs*/, MVT::i64, 2/*#Ops*/, 0, 1, 
                // Src: (shl:i64 i64:i64:$rs, i32:i32:$rs2) - Complexity = 3
                // Dst: (SLLXrr:i64 i64:i64:$rs, i32:i32:$rs2)
/*3296*/      0, // EndSwitchType
/*3297*/    0, /*End of Scope*/
/*3298*/  /*SwitchOpcode*/ 77,  TARGET_VAL(ISD::SRL),// ->3378
/*3301*/    OPC_RecordChild0, // #0 = $b
/*3302*/    OPC_RecordChild1, // #1 = $c
/*3303*/    OPC_Scope, 43, /*->3348*/ // 2 children in Scope
/*3305*/      OPC_MoveChild, 1,
/*3307*/      OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*3310*/      OPC_CheckType, MVT::i32,
/*3312*/      OPC_Scope, 16, /*->3330*/ // 2 children in Scope
/*3314*/        OPC_CheckPredicate, 6, // Predicate_simm13
/*3316*/        OPC_MoveParent,
/*3317*/        OPC_CheckType, MVT::i32,
/*3319*/        OPC_EmitConvertToTarget, 1,
/*3321*/        OPC_MorphNodeTo, TARGET_VAL(SP::SRLri), 0,
                    1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 2, 
                // Src: (srl:i32 i32:i32:$b, (imm:i32)<<P:Predicate_simm13>>:$c) - Complexity = 7
                // Dst: (SRLri:i32 i32:i32:$b, (imm:i32):$c)
/*3330*/      /*Scope*/ 16, /*->3347*/
/*3331*/        OPC_MoveParent,
/*3332*/        OPC_CheckType, MVT::i64,
/*3334*/        OPC_CheckPatternPredicate, 0, // (Subtarget.is64Bit())
/*3336*/        OPC_EmitConvertToTarget, 1,
/*3338*/        OPC_MorphNodeTo, TARGET_VAL(SP::SRLXri), 0,
                    1/*#VTs*/, MVT::i64, 2/*#Ops*/, 0, 2, 
                // Src: (srl:i64 i64:i64:$rs, (imm:i32):$shcnt) - Complexity = 6
                // Dst: (SRLXri:i64 i64:i64:$rs, (imm:i32):$shcnt)
/*3347*/      0, /*End of Scope*/
/*3348*/    /*Scope*/ 28, /*->3377*/
/*3349*/      OPC_CheckChild1Type, MVT::i32,
/*3351*/      OPC_SwitchType /*2 cases */, 9,  MVT::i32,// ->3363
/*3354*/        OPC_MorphNodeTo, TARGET_VAL(SP::SRLrr), 0,
                    1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1, 
                // Src: (srl:i32 i32:i32:$b, i32:i32:$c) - Complexity = 3
                // Dst: (SRLrr:i32 i32:i32:$b, i32:i32:$c)
/*3363*/      /*SwitchType*/ 11,  MVT::i64,// ->3376
/*3365*/        OPC_CheckPatternPredicate, 0, // (Subtarget.is64Bit())
/*3367*/        OPC_MorphNodeTo, TARGET_VAL(SP::SRLXrr), 0,
                    1/*#VTs*/, MVT::i64, 2/*#Ops*/, 0, 1, 
                // Src: (srl:i64 i64:i64:$rs, i32:i32:$rs2) - Complexity = 3
                // Dst: (SRLXrr:i64 i64:i64:$rs, i32:i32:$rs2)
/*3376*/      0, // EndSwitchType
/*3377*/    0, /*End of Scope*/
/*3378*/  /*SwitchOpcode*/ 77,  TARGET_VAL(ISD::SRA),// ->3458
/*3381*/    OPC_RecordChild0, // #0 = $b
/*3382*/    OPC_RecordChild1, // #1 = $c
/*3383*/    OPC_Scope, 43, /*->3428*/ // 2 children in Scope
/*3385*/      OPC_MoveChild, 1,
/*3387*/      OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*3390*/      OPC_CheckType, MVT::i32,
/*3392*/      OPC_Scope, 16, /*->3410*/ // 2 children in Scope
/*3394*/        OPC_CheckPredicate, 6, // Predicate_simm13
/*3396*/        OPC_MoveParent,
/*3397*/        OPC_CheckType, MVT::i32,
/*3399*/        OPC_EmitConvertToTarget, 1,
/*3401*/        OPC_MorphNodeTo, TARGET_VAL(SP::SRAri), 0,
                    1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 2, 
                // Src: (sra:i32 i32:i32:$b, (imm:i32)<<P:Predicate_simm13>>:$c) - Complexity = 7
                // Dst: (SRAri:i32 i32:i32:$b, (imm:i32):$c)
/*3410*/      /*Scope*/ 16, /*->3427*/
/*3411*/        OPC_MoveParent,
/*3412*/        OPC_CheckType, MVT::i64,
/*3414*/        OPC_CheckPatternPredicate, 0, // (Subtarget.is64Bit())
/*3416*/        OPC_EmitConvertToTarget, 1,
/*3418*/        OPC_MorphNodeTo, TARGET_VAL(SP::SRAXri), 0,
                    1/*#VTs*/, MVT::i64, 2/*#Ops*/, 0, 2, 
                // Src: (sra:i64 i64:i64:$rs, (imm:i32):$shcnt) - Complexity = 6
                // Dst: (SRAXri:i64 i64:i64:$rs, (imm:i32):$shcnt)
/*3427*/      0, /*End of Scope*/
/*3428*/    /*Scope*/ 28, /*->3457*/
/*3429*/      OPC_CheckChild1Type, MVT::i32,
/*3431*/      OPC_SwitchType /*2 cases */, 9,  MVT::i32,// ->3443
/*3434*/        OPC_MorphNodeTo, TARGET_VAL(SP::SRArr), 0,
                    1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1, 
                // Src: (sra:i32 i32:i32:$b, i32:i32:$c) - Complexity = 3
                // Dst: (SRArr:i32 i32:i32:$b, i32:i32:$c)
/*3443*/      /*SwitchType*/ 11,  MVT::i64,// ->3456
/*3445*/        OPC_CheckPatternPredicate, 0, // (Subtarget.is64Bit())
/*3447*/        OPC_MorphNodeTo, TARGET_VAL(SP::SRAXrr), 0,
                    1/*#VTs*/, MVT::i64, 2/*#Ops*/, 0, 1, 
                // Src: (sra:i64 i64:i64:$rs, i32:i32:$rs2) - Complexity = 3
                // Dst: (SRAXrr:i64 i64:i64:$rs, i32:i32:$rs2)
/*3456*/      0, // EndSwitchType
/*3457*/    0, /*End of Scope*/
/*3458*/  /*SwitchOpcode*/ 38,  TARGET_VAL(ISD::ADDC),// ->3499
/*3461*/    OPC_RecordChild0, // #0 = $b
/*3462*/    OPC_RecordChild1, // #1 = $c
/*3463*/    OPC_Scope, 21, /*->3486*/ // 2 children in Scope
/*3465*/      OPC_MoveChild, 1,
/*3467*/      OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*3470*/      OPC_CheckPredicate, 6, // Predicate_simm13
/*3472*/      OPC_MoveParent,
/*3473*/      OPC_CheckType, MVT::i32,
/*3475*/      OPC_EmitConvertToTarget, 1,
/*3477*/      OPC_MorphNodeTo, TARGET_VAL(SP::ADDCCri), 0|OPFL_GlueOutput,
                  1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 2, 
              // Src: (addc:i32 i32:i32:$b, (imm:i32)<<P:Predicate_simm13>>:$c) - Complexity = 7
              // Dst: (ADDCCri:i32 i32:i32:$b, (imm:i32):$c)
/*3486*/    /*Scope*/ 11, /*->3498*/
/*3487*/      OPC_CheckType, MVT::i32,
/*3489*/      OPC_MorphNodeTo, TARGET_VAL(SP::ADDCCrr), 0|OPFL_GlueOutput,
                  1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1, 
              // Src: (addc:i32 i32:i32:$b, i32:i32:$c) - Complexity = 3
              // Dst: (ADDCCrr:i32 i32:i32:$b, i32:i32:$c)
/*3498*/    0, /*End of Scope*/
/*3499*/  /*SwitchOpcode*/ 39,  TARGET_VAL(ISD::ADDE),// ->3541
/*3502*/    OPC_CaptureGlueInput,
/*3503*/    OPC_RecordChild0, // #0 = $b
/*3504*/    OPC_RecordChild1, // #1 = $c
/*3505*/    OPC_Scope, 21, /*->3528*/ // 2 children in Scope
/*3507*/      OPC_MoveChild, 1,
/*3509*/      OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*3512*/      OPC_CheckPredicate, 6, // Predicate_simm13
/*3514*/      OPC_MoveParent,
/*3515*/      OPC_CheckType, MVT::i32,
/*3517*/      OPC_EmitConvertToTarget, 1,
/*3519*/      OPC_MorphNodeTo, TARGET_VAL(SP::ADDXri), 0|OPFL_GlueInput|OPFL_GlueOutput,
                  1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 2, 
              // Src: (adde:i32 i32:i32:$b, (imm:i32)<<P:Predicate_simm13>>:$c) - Complexity = 7
              // Dst: (ADDXri:i32 i32:i32:$b, (imm:i32):$c)
/*3528*/    /*Scope*/ 11, /*->3540*/
/*3529*/      OPC_CheckType, MVT::i32,
/*3531*/      OPC_MorphNodeTo, TARGET_VAL(SP::ADDXrr), 0|OPFL_GlueInput|OPFL_GlueOutput,
                  1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1, 
              // Src: (adde:i32 i32:i32:$b, i32:i32:$c) - Complexity = 3
              // Dst: (ADDXrr:i32 i32:i32:$b, i32:i32:$c)
/*3540*/    0, /*End of Scope*/
/*3541*/  /*SwitchOpcode*/ 70,  TARGET_VAL(ISD::SUB),// ->3614
/*3544*/    OPC_RecordChild0, // #0 = $b
/*3545*/    OPC_RecordChild1, // #1 = $c
/*3546*/    OPC_Scope, 39, /*->3587*/ // 3 children in Scope
/*3548*/      OPC_MoveChild, 1,
/*3550*/      OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*3553*/      OPC_CheckPredicate, 6, // Predicate_simm13
/*3555*/      OPC_MoveParent,
/*3556*/      OPC_SwitchType /*2 cases */, 11,  MVT::i32,// ->3570
/*3559*/        OPC_EmitConvertToTarget, 1,
/*3561*/        OPC_MorphNodeTo, TARGET_VAL(SP::SUBri), 0,
                    1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 2, 
                // Src: (sub:i32 i32:i32:$b, (imm:i32)<<P:Predicate_simm13>>:$c) - Complexity = 7
                // Dst: (SUBri:i32 i32:i32:$b, (imm:i32):$c)
/*3570*/      /*SwitchType*/ 14,  MVT::i64,// ->3586
/*3572*/        OPC_CheckPatternPredicate, 0, // (Subtarget.is64Bit())
/*3574*/        OPC_EmitNodeXForm, 0, 1, // as_i32imm
/*3577*/        OPC_MorphNodeTo, TARGET_VAL(SP::SUBri), 0,
                    1/*#VTs*/, MVT::i64, 2/*#Ops*/, 0, 2, 
                // Src: (sub:i64 i64:i64:$a, (imm:i64)<<P:Predicate_simm13>>:$b) - Complexity = 7
                // Dst: (SUBri:i64 ?:i64:$a, (as_i32imm:i32 ?:i64:$b))
/*3586*/      0, // EndSwitchType
/*3587*/    /*Scope*/ 11, /*->3599*/
/*3588*/      OPC_CheckType, MVT::i32,
/*3590*/      OPC_MorphNodeTo, TARGET_VAL(SP::SUBrr), 0,
                  1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1, 
              // Src: (sub:i32 i32:i32:$b, i32:i32:$c) - Complexity = 3
              // Dst: (SUBrr:i32 i32:i32:$b, i32:i32:$c)
/*3599*/    /*Scope*/ 13, /*->3613*/
/*3600*/      OPC_CheckType, MVT::i64,
/*3602*/      OPC_CheckPatternPredicate, 0, // (Subtarget.is64Bit())
/*3604*/      OPC_MorphNodeTo, TARGET_VAL(SP::SUBrr), 0,
                  1/*#VTs*/, MVT::i64, 2/*#Ops*/, 0, 1, 
              // Src: (sub:i64 i64:i64:$a, i64:i64:$b) - Complexity = 3
              // Dst: (SUBrr:i64 ?:i64:$a, ?:i64:$b)
/*3613*/    0, /*End of Scope*/
/*3614*/  /*SwitchOpcode*/ 39,  TARGET_VAL(ISD::SUBE),// ->3656
/*3617*/    OPC_CaptureGlueInput,
/*3618*/    OPC_RecordChild0, // #0 = $b
/*3619*/    OPC_RecordChild1, // #1 = $c
/*3620*/    OPC_Scope, 21, /*->3643*/ // 2 children in Scope
/*3622*/      OPC_MoveChild, 1,
/*3624*/      OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*3627*/      OPC_CheckPredicate, 6, // Predicate_simm13
/*3629*/      OPC_MoveParent,
/*3630*/      OPC_CheckType, MVT::i32,
/*3632*/      OPC_EmitConvertToTarget, 1,
/*3634*/      OPC_MorphNodeTo, TARGET_VAL(SP::SUBXri), 0|OPFL_GlueInput|OPFL_GlueOutput,
                  1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 2, 
              // Src: (sube:i32 i32:i32:$b, (imm:i32)<<P:Predicate_simm13>>:$c) - Complexity = 7
              // Dst: (SUBXri:i32 i32:i32:$b, (imm:i32):$c)
/*3643*/    /*Scope*/ 11, /*->3655*/
/*3644*/      OPC_CheckType, MVT::i32,
/*3646*/      OPC_MorphNodeTo, TARGET_VAL(SP::SUBXrr), 0|OPFL_GlueInput|OPFL_GlueOutput,
                  1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1, 
              // Src: (sube:i32 i32:i32:$b, i32:i32:$c) - Complexity = 3
              // Dst: (SUBXrr:i32 i32:i32:$b, i32:i32:$c)
/*3655*/    0, /*End of Scope*/
/*3656*/  /*SwitchOpcode*/ 38,  TARGET_VAL(ISD::SUBC),// ->3697
/*3659*/    OPC_RecordChild0, // #0 = $b
/*3660*/    OPC_RecordChild1, // #1 = $c
/*3661*/    OPC_Scope, 21, /*->3684*/ // 2 children in Scope
/*3663*/      OPC_MoveChild, 1,
/*3665*/      OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*3668*/      OPC_CheckPredicate, 6, // Predicate_simm13
/*3670*/      OPC_MoveParent,
/*3671*/      OPC_CheckType, MVT::i32,
/*3673*/      OPC_EmitConvertToTarget, 1,
/*3675*/      OPC_MorphNodeTo, TARGET_VAL(SP::SUBCCri), 0|OPFL_GlueOutput,
                  1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 2, 
              // Src: (subc:i32 i32:i32:$b, (imm:i32)<<P:Predicate_simm13>>:$c) - Complexity = 7
              // Dst: (SUBCCri:i32 i32:i32:$b, (imm:i32):$c)
/*3684*/    /*Scope*/ 11, /*->3696*/
/*3685*/      OPC_CheckType, MVT::i32,
/*3687*/      OPC_MorphNodeTo, TARGET_VAL(SP::SUBCCrr), 0|OPFL_GlueOutput,
                  1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1, 
              // Src: (subc:i32 i32:i32:$b, i32:i32:$c) - Complexity = 3
              // Dst: (SUBCCrr:i32 i32:i32:$b, i32:i32:$c)
/*3696*/    0, /*End of Scope*/
/*3697*/  /*SwitchOpcode*/ 76,  TARGET_VAL(SPISD::CMPICC),// ->3776
/*3700*/    OPC_RecordChild0, // #0 = $b
/*3701*/    OPC_Scope, 33, /*->3736*/ // 2 children in Scope
/*3703*/      OPC_CheckChild0Type, MVT::i32,
/*3705*/      OPC_RecordChild1, // #1 = $c
/*3706*/      OPC_Scope, 18, /*->3726*/ // 2 children in Scope
/*3708*/        OPC_MoveChild, 1,
/*3710*/        OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*3713*/        OPC_CheckPredicate, 6, // Predicate_simm13
/*3715*/        OPC_MoveParent,
/*3716*/        OPC_EmitConvertToTarget, 1,
/*3718*/        OPC_MorphNodeTo, TARGET_VAL(SP::CMPri), 0|OPFL_GlueOutput,
                    0/*#VTs*/, 2/*#Ops*/, 0, 2, 
                // Src: (SPcmpicc i32:i32:$b, (imm:i32)<<P:Predicate_simm13>>:$c) - Complexity = 7
                // Dst: (CMPri i32:i32:$b, (imm:i32):$c)
/*3726*/      /*Scope*/ 8, /*->3735*/
/*3727*/        OPC_MorphNodeTo, TARGET_VAL(SP::CMPrr), 0|OPFL_GlueOutput,
                    0/*#VTs*/, 2/*#Ops*/, 0, 1, 
                // Src: (SPcmpicc i32:i32:$b, i32:i32:$c) - Complexity = 3
                // Dst: (CMPrr i32:i32:$b, i32:i32:$c)
/*3735*/      0, /*End of Scope*/
/*3736*/    /*Scope*/ 38, /*->3775*/
/*3737*/      OPC_CheckChild0Type, MVT::i64,
/*3739*/      OPC_RecordChild1, // #1 = $b
/*3740*/      OPC_Scope, 21, /*->3763*/ // 2 children in Scope
/*3742*/        OPC_MoveChild, 1,
/*3744*/        OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*3747*/        OPC_CheckPredicate, 6, // Predicate_simm13
/*3749*/        OPC_MoveParent,
/*3750*/        OPC_CheckPatternPredicate, 0, // (Subtarget.is64Bit())
/*3752*/        OPC_EmitNodeXForm, 0, 1, // as_i32imm
/*3755*/        OPC_MorphNodeTo, TARGET_VAL(SP::CMPri), 0|OPFL_GlueOutput,
                    0/*#VTs*/, 2/*#Ops*/, 0, 2, 
                // Src: (SPcmpicc i64:i64:$a, (imm:i64)<<P:Predicate_simm13>>:$b) - Complexity = 7
                // Dst: (CMPri ?:i64:$a, (as_i32imm:i32 ?:i64:$b))
/*3763*/      /*Scope*/ 10, /*->3774*/
/*3764*/        OPC_CheckPatternPredicate, 0, // (Subtarget.is64Bit())
/*3766*/        OPC_MorphNodeTo, TARGET_VAL(SP::CMPrr), 0|OPFL_GlueOutput,
                    0/*#VTs*/, 2/*#Ops*/, 0, 1, 
                // Src: (SPcmpicc i64:i64:$a, i64:i64:$b) - Complexity = 3
                // Dst: (CMPrr ?:i64:$a, ?:i64:$b)
/*3774*/      0, /*End of Scope*/
/*3775*/    0, /*End of Scope*/
/*3776*/  /*SwitchOpcode*/ 69,  TARGET_VAL(ISD::MUL),// ->3848
/*3779*/    OPC_RecordChild0, // #0 = $b
/*3780*/    OPC_RecordChild1, // #1 = $c
/*3781*/    OPC_Scope, 38, /*->3821*/ // 3 children in Scope
/*3783*/      OPC_MoveChild, 1,
/*3785*/      OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*3788*/      OPC_CheckPredicate, 6, // Predicate_simm13
/*3790*/      OPC_MoveParent,
/*3791*/      OPC_SwitchType /*2 cases */, 11,  MVT::i32,// ->3805
/*3794*/        OPC_EmitConvertToTarget, 1,
/*3796*/        OPC_MorphNodeTo, TARGET_VAL(SP::SMULri), 0,
                    1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 2, 
                // Src: (mul:i32 i32:i32:$b, (imm:i32)<<P:Predicate_simm13>>:$c) - Complexity = 7
                // Dst: (SMULri:i32 i32:i32:$b, (imm:i32):$c)
/*3805*/      /*SwitchType*/ 13,  MVT::i64,// ->3820
/*3807*/        OPC_CheckPatternPredicate, 0, // (Subtarget.is64Bit())
/*3809*/        OPC_EmitConvertToTarget, 1,
/*3811*/        OPC_MorphNodeTo, TARGET_VAL(SP::MULXri), 0,
                    1/*#VTs*/, MVT::i64, 2/*#Ops*/, 0, 2, 
                // Src: (mul:i64 i64:i64:$rs1, (imm:i64)<<P:Predicate_simm13>>:$i) - Complexity = 7
                // Dst: (MULXri:i64 i64:i64:$rs1, (imm:i64):$i)
/*3820*/      0, // EndSwitchType
/*3821*/    /*Scope*/ 11, /*->3833*/
/*3822*/      OPC_CheckType, MVT::i32,
/*3824*/      OPC_MorphNodeTo, TARGET_VAL(SP::SMULrr), 0,
                  1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1, 
              // Src: (mul:i32 i32:i32:$b, i32:i32:$c) - Complexity = 3
              // Dst: (SMULrr:i32 i32:i32:$b, i32:i32:$c)
/*3833*/    /*Scope*/ 13, /*->3847*/
/*3834*/      OPC_CheckType, MVT::i64,
/*3836*/      OPC_CheckPatternPredicate, 0, // (Subtarget.is64Bit())
/*3838*/      OPC_MorphNodeTo, TARGET_VAL(SP::MULXrr), 0,
                  1/*#VTs*/, MVT::i64, 2/*#Ops*/, 0, 1, 
              // Src: (mul:i64 i64:i64:$rs1, i64:i64:$rs2) - Complexity = 3
              // Dst: (MULXrr:i64 i64:i64:$rs1, i64:i64:$rs2)
/*3847*/    0, /*End of Scope*/
/*3848*/  /*SwitchOpcode*/ 42,  TARGET_VAL(ISD::SDIV),// ->3893
/*3851*/    OPC_RecordChild0, // #0 = $rs1
/*3852*/    OPC_RecordChild1, // #1 = $i
/*3853*/    OPC_Scope, 23, /*->3878*/ // 2 children in Scope
/*3855*/      OPC_MoveChild, 1,
/*3857*/      OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*3860*/      OPC_CheckPredicate, 6, // Predicate_simm13
/*3862*/      OPC_MoveParent,
/*3863*/      OPC_CheckType, MVT::i64,
/*3865*/      OPC_CheckPatternPredicate, 0, // (Subtarget.is64Bit())
/*3867*/      OPC_EmitConvertToTarget, 1,
/*3869*/      OPC_MorphNodeTo, TARGET_VAL(SP::SDIVXri), 0,
                  1/*#VTs*/, MVT::i64, 2/*#Ops*/, 0, 2, 
              // Src: (sdiv:i64 i64:i64:$rs1, (imm:i64)<<P:Predicate_simm13>>:$i) - Complexity = 7
              // Dst: (SDIVXri:i64 i64:i64:$rs1, (imm:i64):$i)
/*3878*/    /*Scope*/ 13, /*->3892*/
/*3879*/      OPC_CheckType, MVT::i64,
/*3881*/      OPC_CheckPatternPredicate, 0, // (Subtarget.is64Bit())
/*3883*/      OPC_MorphNodeTo, TARGET_VAL(SP::SDIVXrr), 0,
                  1/*#VTs*/, MVT::i64, 2/*#Ops*/, 0, 1, 
              // Src: (sdiv:i64 i64:i64:$rs1, i64:i64:$rs2) - Complexity = 3
              // Dst: (SDIVXrr:i64 i64:i64:$rs1, i64:i64:$rs2)
/*3892*/    0, /*End of Scope*/
/*3893*/  /*SwitchOpcode*/ 42,  TARGET_VAL(ISD::UDIV),// ->3938
/*3896*/    OPC_RecordChild0, // #0 = $rs1
/*3897*/    OPC_RecordChild1, // #1 = $i
/*3898*/    OPC_Scope, 23, /*->3923*/ // 2 children in Scope
/*3900*/      OPC_MoveChild, 1,
/*3902*/      OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*3905*/      OPC_CheckPredicate, 6, // Predicate_simm13
/*3907*/      OPC_MoveParent,
/*3908*/      OPC_CheckType, MVT::i64,
/*3910*/      OPC_CheckPatternPredicate, 0, // (Subtarget.is64Bit())
/*3912*/      OPC_EmitConvertToTarget, 1,
/*3914*/      OPC_MorphNodeTo, TARGET_VAL(SP::UDIVXri), 0,
                  1/*#VTs*/, MVT::i64, 2/*#Ops*/, 0, 2, 
              // Src: (udiv:i64 i64:i64:$rs1, (imm:i64)<<P:Predicate_simm13>>:$i) - Complexity = 7
              // Dst: (UDIVXri:i64 i64:i64:$rs1, (imm:i64):$i)
/*3923*/    /*Scope*/ 13, /*->3937*/
/*3924*/      OPC_CheckType, MVT::i64,
/*3926*/      OPC_CheckPatternPredicate, 0, // (Subtarget.is64Bit())
/*3928*/      OPC_MorphNodeTo, TARGET_VAL(SP::UDIVXrr), 0,
                  1/*#VTs*/, MVT::i64, 2/*#Ops*/, 0, 1, 
              // Src: (udiv:i64 i64:i64:$rs1, i64:i64:$rs2) - Complexity = 3
              // Dst: (UDIVXrr:i64 i64:i64:$rs1, i64:i64:$rs2)
/*3937*/    0, /*End of Scope*/
/*3938*/  /*SwitchOpcode*/ 16,  TARGET_VAL(ISD::CALLSEQ_START),// ->3957
/*3941*/    OPC_RecordNode,   // #0 = 'callseq_start' chained node
/*3942*/    OPC_RecordChild1, // #1 = $amt
/*3943*/    OPC_MoveChild, 1,
/*3945*/    OPC_CheckOpcode, TARGET_VAL(ISD::TargetConstant),
/*3948*/    OPC_MoveParent,
/*3949*/    OPC_EmitMergeInputChains1_0,
/*3950*/    OPC_MorphNodeTo, TARGET_VAL(SP::ADJCALLSTACKDOWN), 0|OPFL_Chain|OPFL_GlueOutput,
                0/*#VTs*/, 1/*#Ops*/, 1, 
            // Src: (callseq_start (timm:i32):$amt) - Complexity = 6
            // Dst: (ADJCALLSTACKDOWN (timm:i32):$amt)
/*3957*/  /*SwitchOpcode*/ 27,  TARGET_VAL(SPISD::BRICC),// ->3987
/*3960*/    OPC_RecordNode,   // #0 = 'SPbricc' chained node
/*3961*/    OPC_CaptureGlueInput,
/*3962*/    OPC_RecordChild1, // #1 = $imm22
/*3963*/    OPC_MoveChild, 1,
/*3965*/    OPC_CheckOpcode, TARGET_VAL(ISD::BasicBlock),
/*3968*/    OPC_MoveParent,
/*3969*/    OPC_RecordChild2, // #2 = $cond
/*3970*/    OPC_MoveChild, 2,
/*3972*/    OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*3975*/    OPC_MoveParent,
/*3976*/    OPC_EmitMergeInputChains1_0,
/*3977*/    OPC_EmitConvertToTarget, 2,
/*3979*/    OPC_MorphNodeTo, TARGET_VAL(SP::BCOND), 0|OPFL_Chain|OPFL_GlueInput,
                0/*#VTs*/, 2/*#Ops*/, 1, 3, 
            // Src: (SPbricc (bb:Other):$imm22, (imm:i32):$cond) - Complexity = 6
            // Dst: (BCOND (bb:Other):$imm22, (imm:i32):$cond)
/*3987*/  /*SwitchOpcode*/ 27,  TARGET_VAL(SPISD::BRFCC),// ->4017
/*3990*/    OPC_RecordNode,   // #0 = 'SPbrfcc' chained node
/*3991*/    OPC_CaptureGlueInput,
/*3992*/    OPC_RecordChild1, // #1 = $imm22
/*3993*/    OPC_MoveChild, 1,
/*3995*/    OPC_CheckOpcode, TARGET_VAL(ISD::BasicBlock),
/*3998*/    OPC_MoveParent,
/*3999*/    OPC_RecordChild2, // #2 = $cond
/*4000*/    OPC_MoveChild, 2,
/*4002*/    OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*4005*/    OPC_MoveParent,
/*4006*/    OPC_EmitMergeInputChains1_0,
/*4007*/    OPC_EmitConvertToTarget, 2,
/*4009*/    OPC_MorphNodeTo, TARGET_VAL(SP::FBCOND), 0|OPFL_Chain|OPFL_GlueInput,
                0/*#VTs*/, 2/*#Ops*/, 1, 3, 
            // Src: (SPbrfcc (bb:Other):$imm22, (imm:i32):$cond) - Complexity = 6
            // Dst: (FBCOND (bb:Other):$imm22, (imm:i32):$cond)
/*4017*/  /*SwitchOpcode*/ 50,  TARGET_VAL(SPISD::TLS_ADD),// ->4070
/*4020*/    OPC_RecordChild0, // #0 = $rs1
/*4021*/    OPC_RecordChild1, // #1 = $rs2
/*4022*/    OPC_Scope, 21, /*->4045*/ // 2 children in Scope
/*4024*/      OPC_CheckChild1Type, MVT::i32,
/*4026*/      OPC_RecordChild2, // #2 = $sym
/*4027*/      OPC_MoveChild, 2,
/*4029*/      OPC_CheckOpcode, TARGET_VAL(ISD::TargetGlobalTLSAddress),
/*4032*/      OPC_MoveParent,
/*4033*/      OPC_CheckType, MVT::i32,
/*4035*/      OPC_MorphNodeTo, TARGET_VAL(SP::TLS_ADDrr), 0,
                  1/*#VTs*/, MVT::i32, 3/*#Ops*/, 0, 1, 2, 
              // Src: (tlsadd:i32 i32:i32:$rs1, i32:i32:$rs2, (tglobaltlsaddr:iPTR):$sym) - Complexity = 6
              // Dst: (TLS_ADDrr:i32 i32:i32:$rs1, i32:i32:$rs2, (tglobaltlsaddr:iPTR):$sym)
/*4045*/    /*Scope*/ 23, /*->4069*/
/*4046*/      OPC_CheckChild1Type, MVT::i64,
/*4048*/      OPC_RecordChild2, // #2 = $sym
/*4049*/      OPC_MoveChild, 2,
/*4051*/      OPC_CheckOpcode, TARGET_VAL(ISD::TargetGlobalTLSAddress),
/*4054*/      OPC_MoveParent,
/*4055*/      OPC_CheckType, MVT::i64,
/*4057*/      OPC_CheckPatternPredicate, 0, // (Subtarget.is64Bit())
/*4059*/      OPC_MorphNodeTo, TARGET_VAL(SP::TLS_ADDrr), 0,
                  1/*#VTs*/, MVT::i64, 3/*#Ops*/, 0, 1, 2, 
              // Src: (tlsadd:i64 i64:i64:$a, i64:i64:$b, (tglobaltlsaddr:iPTR):$sym) - Complexity = 6
              // Dst: (TLS_ADDrr:i64 ?:i64:$a, ?:i64:$b, ?:iPTR:$sym)
/*4069*/    0, /*End of Scope*/
/*4070*/  /*SwitchOpcode*/ 53,  TARGET_VAL(SPISD::Hi),// ->4126
/*4073*/    OPC_RecordChild0, // #0 = $in
/*4074*/    OPC_MoveChild, 0,
/*4076*/    OPC_SwitchOpcode /*4 cases */, 9,  TARGET_VAL(ISD::TargetGlobalAddress),// ->4089
/*4080*/      OPC_MoveParent,
/*4081*/      OPC_MorphNodeTo, TARGET_VAL(SP::SETHIi), 0,
                  1/*#VTs*/, MVT::iPTR, 1/*#Ops*/, 0, 
              // Src: (SPhi:iPTR (tglobaladdr:iPTR):$in) - Complexity = 6
              // Dst: (SETHIi:iPTR (tglobaladdr:i32):$in)
/*4089*/    /*SwitchOpcode*/ 9,  TARGET_VAL(ISD::TargetConstantPool),// ->4101
/*4092*/      OPC_MoveParent,
/*4093*/      OPC_MorphNodeTo, TARGET_VAL(SP::SETHIi), 0,
                  1/*#VTs*/, MVT::iPTR, 1/*#Ops*/, 0, 
              // Src: (SPhi:iPTR (tconstpool:iPTR):$in) - Complexity = 6
              // Dst: (SETHIi:iPTR (tconstpool:i32):$in)
/*4101*/    /*SwitchOpcode*/ 9,  TARGET_VAL(ISD::TargetGlobalTLSAddress),// ->4113
/*4104*/      OPC_MoveParent,
/*4105*/      OPC_MorphNodeTo, TARGET_VAL(SP::SETHIi), 0,
                  1/*#VTs*/, MVT::iPTR, 1/*#Ops*/, 0, 
              // Src: (SPhi:iPTR (tglobaltlsaddr:iPTR):$in) - Complexity = 6
              // Dst: (SETHIi:iPTR (tglobaltlsaddr:i32):$in)
/*4113*/    /*SwitchOpcode*/ 9,  TARGET_VAL(ISD::TargetBlockAddress),// ->4125
/*4116*/      OPC_MoveParent,
/*4117*/      OPC_MorphNodeTo, TARGET_VAL(SP::SETHIi), 0,
                  1/*#VTs*/, MVT::iPTR, 1/*#Ops*/, 0, 
              // Src: (SPhi:iPTR (tblockaddress:iPTR):$in) - Complexity = 6
              // Dst: (SETHIi:iPTR (tblockaddress:i32):$in)
/*4125*/    0, // EndSwitchOpcode
/*4126*/  /*SwitchOpcode*/ 69,  TARGET_VAL(SPISD::Lo),// ->4198
/*4129*/    OPC_RecordChild0, // #0 = $in
/*4130*/    OPC_MoveChild, 0,
/*4132*/    OPC_SwitchOpcode /*4 cases */, 13,  TARGET_VAL(ISD::TargetGlobalAddress),// ->4149
/*4136*/      OPC_MoveParent,
/*4137*/      OPC_EmitRegister, MVT::i32, SP::G0,
/*4140*/      OPC_MorphNodeTo, TARGET_VAL(SP::ORri), 0,
                  1/*#VTs*/, MVT::iPTR, 2/*#Ops*/, 1, 0, 
              // Src: (SPlo:iPTR (tglobaladdr:iPTR):$in) - Complexity = 6
              // Dst: (ORri:iPTR G0:i32, (tglobaladdr:i32):$in)
/*4149*/    /*SwitchOpcode*/ 13,  TARGET_VAL(ISD::TargetConstantPool),// ->4165
/*4152*/      OPC_MoveParent,
/*4153*/      OPC_EmitRegister, MVT::i32, SP::G0,
/*4156*/      OPC_MorphNodeTo, TARGET_VAL(SP::ORri), 0,
                  1/*#VTs*/, MVT::iPTR, 2/*#Ops*/, 1, 0, 
              // Src: (SPlo:iPTR (tconstpool:iPTR):$in) - Complexity = 6
              // Dst: (ORri:iPTR G0:i32, (tconstpool:i32):$in)
/*4165*/    /*SwitchOpcode*/ 13,  TARGET_VAL(ISD::TargetGlobalTLSAddress),// ->4181
/*4168*/      OPC_MoveParent,
/*4169*/      OPC_EmitRegister, MVT::i32, SP::G0,
/*4172*/      OPC_MorphNodeTo, TARGET_VAL(SP::ORri), 0,
                  1/*#VTs*/, MVT::iPTR, 2/*#Ops*/, 1, 0, 
              // Src: (SPlo:iPTR (tglobaltlsaddr:iPTR):$in) - Complexity = 6
              // Dst: (ORri:iPTR G0:i32, (tglobaltlsaddr:i32):$in)
/*4181*/    /*SwitchOpcode*/ 13,  TARGET_VAL(ISD::TargetBlockAddress),// ->4197
/*4184*/      OPC_MoveParent,
/*4185*/      OPC_EmitRegister, MVT::i32, SP::G0,
/*4188*/      OPC_MorphNodeTo, TARGET_VAL(SP::ORri), 0,
                  1/*#VTs*/, MVT::iPTR, 2/*#Ops*/, 1, 0, 
              // Src: (SPlo:iPTR (tblockaddress:iPTR):$in) - Complexity = 6
              // Dst: (ORri:iPTR G0:i32, (tblockaddress:i32):$in)
/*4197*/    0, // EndSwitchOpcode
/*4198*/  /*SwitchOpcode*/ 29,  TARGET_VAL(SPISD::BRXCC),// ->4230
/*4201*/    OPC_RecordNode,   // #0 = 'SPbrxcc' chained node
/*4202*/    OPC_CaptureGlueInput,
/*4203*/    OPC_RecordChild1, // #1 = $imm22
/*4204*/    OPC_MoveChild, 1,
/*4206*/    OPC_CheckOpcode, TARGET_VAL(ISD::BasicBlock),
/*4209*/    OPC_MoveParent,
/*4210*/    OPC_RecordChild2, // #2 = $cond
/*4211*/    OPC_MoveChild, 2,
/*4213*/    OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*4216*/    OPC_MoveParent,
/*4217*/    OPC_CheckPatternPredicate, 0, // (Subtarget.is64Bit())
/*4219*/    OPC_EmitMergeInputChains1_0,
/*4220*/    OPC_EmitConvertToTarget, 2,
/*4222*/    OPC_MorphNodeTo, TARGET_VAL(SP::BPXCC), 0|OPFL_Chain|OPFL_GlueInput,
                0/*#VTs*/, 2/*#Ops*/, 1, 3, 
            // Src: (SPbrxcc (bb:Other):$imm22, (imm:i32):$cond) - Complexity = 6
            // Dst: (BPXCC (bb:Other):$imm22, (imm:i32):$cond)
/*4230*/  /*SwitchOpcode*/ 109|128,1/*237*/,  TARGET_VAL(ISD::Constant),// ->4471
/*4234*/    OPC_RecordNode,   // #0 = $imm22
/*4235*/    OPC_Scope, 17, /*->4254*/ // 7 children in Scope
/*4237*/      OPC_CheckPredicate, 24, // Predicate_SETHIimm
/*4239*/      OPC_CheckType, MVT::i32,
/*4241*/      OPC_EmitConvertToTarget, 0,
/*4243*/      OPC_EmitNodeXForm, 1, 1, // HI22
/*4246*/      OPC_MorphNodeTo, TARGET_VAL(SP::SETHIi), 0,
                  1/*#VTs*/, MVT::i32, 1/*#Ops*/, 2, 
              // Src: (imm:i32)<<P:Predicate_SETHIimm>><<X:HI22>>:$imm22 - Complexity = 4
              // Dst: (SETHIi:i32 (HI22:i32 (imm:i32):$imm22))
/*4254*/    /*Scope*/ 37, /*->4292*/
/*4255*/      OPC_CheckPredicate, 6, // Predicate_simm13
/*4257*/      OPC_SwitchType /*2 cases */, 14,  MVT::i32,// ->4274
/*4260*/        OPC_EmitRegister, MVT::i32, SP::G0,
/*4263*/        OPC_EmitConvertToTarget, 0,
/*4265*/        OPC_MorphNodeTo, TARGET_VAL(SP::ORri), 0,
                    1/*#VTs*/, MVT::i32, 2/*#Ops*/, 1, 2, 
                // Src: (imm:i32)<<P:Predicate_simm13>>:$val - Complexity = 4
                // Dst: (ORri:i32 G0:i32, (imm:i32):$val)
/*4274*/      /*SwitchType*/ 15,  MVT::i64,// ->4291
/*4276*/        OPC_EmitRegister, MVT::i64, SP::G0,
/*4279*/        OPC_EmitNodeXForm, 0, 0, // as_i32imm
/*4282*/        OPC_MorphNodeTo, TARGET_VAL(SP::ORri), 0,
                    1/*#VTs*/, MVT::i64, 2/*#Ops*/, 1, 2, 
                // Src: (imm:i64)<<P:Predicate_simm13>>:$val - Complexity = 4
                // Dst: (ORri:i64 G0:i64, (as_i32imm:i32 ?:i64:$val))
/*4291*/      0, // EndSwitchType
/*4292*/    /*Scope*/ 15, /*->4308*/
/*4293*/      OPC_CheckPredicate, 24, // Predicate_SETHIimm
/*4295*/      OPC_CheckType, MVT::i64,
/*4297*/      OPC_EmitNodeXForm, 1, 0, // HI22
/*4300*/      OPC_MorphNodeTo, TARGET_VAL(SP::SETHIi), 0,
                  1/*#VTs*/, MVT::i64, 1/*#Ops*/, 1, 
              // Src: (imm:i64)<<P:Predicate_SETHIimm>><<X:HI22>>:$val - Complexity = 4
              // Dst: (SETHIi:i64 (HI22:i32 ?:i64:$val))
/*4308*/    /*Scope*/ 29, /*->4338*/
/*4309*/      OPC_CheckPredicate, 25, // Predicate_uimm32
/*4311*/      OPC_CheckType, MVT::i64,
/*4313*/      OPC_CheckPatternPredicate, 0, // (Subtarget.is64Bit())
/*4315*/      OPC_EmitNodeXForm, 1, 0, // HI22
/*4318*/      OPC_EmitNode, TARGET_VAL(SP::SETHIi), 0,
                  1/*#VTs*/, MVT::i32, 1/*#Ops*/, 1,  // Results = #2
/*4326*/      OPC_EmitNodeXForm, 2, 0, // LO10
/*4329*/      OPC_MorphNodeTo, TARGET_VAL(SP::ORri), 0,
                  1/*#VTs*/, MVT::i64, 2/*#Ops*/, 2, 3, 
              // Src: (imm:i64)<<P:Predicate_uimm32>>:$val - Complexity = 4
              // Dst: (ORri:i64 (SETHIi:i32 (HI22:i32 ?:i64:$val)), (LO10:i32 ?:i64:$val))
/*4338*/    /*Scope*/ 29, /*->4368*/
/*4339*/      OPC_CheckPredicate, 26, // Predicate_nimm33
/*4341*/      OPC_CheckType, MVT::i64,
/*4343*/      OPC_CheckPatternPredicate, 0, // (Subtarget.is64Bit())
/*4345*/      OPC_EmitNodeXForm, 3, 0, // HIX22
/*4348*/      OPC_EmitNode, TARGET_VAL(SP::SETHIi), 0,
                  1/*#VTs*/, MVT::i32, 1/*#Ops*/, 1,  // Results = #2
/*4356*/      OPC_EmitNodeXForm, 4, 0, // LOX10
/*4359*/      OPC_MorphNodeTo, TARGET_VAL(SP::XORri), 0,
                  1/*#VTs*/, MVT::i64, 2/*#Ops*/, 2, 3, 
              // Src: (imm:i64)<<P:Predicate_nimm33>>:$val - Complexity = 4
              // Dst: (XORri:i64 (SETHIi:i32 (HIX22:i32 ?:i64:$val)), (LOX10:i32 ?:i64:$val))
/*4368*/    /*Scope*/ 29, /*->4398*/
/*4369*/      OPC_CheckType, MVT::i32,
/*4371*/      OPC_EmitConvertToTarget, 0,
/*4373*/      OPC_EmitNodeXForm, 1, 1, // HI22
/*4376*/      OPC_EmitNode, TARGET_VAL(SP::SETHIi), 0,
                  1/*#VTs*/, MVT::i32, 1/*#Ops*/, 2,  // Results = #3
/*4384*/      OPC_EmitConvertToTarget, 0,
/*4386*/      OPC_EmitNodeXForm, 2, 4, // LO10
/*4389*/      OPC_MorphNodeTo, TARGET_VAL(SP::ORri), 0,
                  1/*#VTs*/, MVT::i32, 2/*#Ops*/, 3, 5, 
              // Src: (imm:i32):$val - Complexity = 3
              // Dst: (ORri:i32 (SETHIi:i32 (HI22:i32 (imm:i32):$val)), (LO10:i32 (imm:i32):$val))
/*4398*/    /*Scope*/ 71, /*->4470*/
/*4399*/      OPC_CheckType, MVT::i64,
/*4401*/      OPC_CheckPatternPredicate, 0, // (Subtarget.is64Bit())
/*4403*/      OPC_EmitNodeXForm, 5, 0, // HH22
/*4406*/      OPC_EmitNode, TARGET_VAL(SP::SETHIi), 0,
                  1/*#VTs*/, MVT::i32, 1/*#Ops*/, 1,  // Results = #2
/*4414*/      OPC_EmitNodeXForm, 6, 0, // HM10
/*4417*/      OPC_EmitNode, TARGET_VAL(SP::ORri), 0,
                  1/*#VTs*/, MVT::i64, 2/*#Ops*/, 2, 3,  // Results = #4
/*4426*/      OPC_EmitInteger, MVT::i32, 32, 
/*4429*/      OPC_EmitNode, TARGET_VAL(SP::SLLXri), 0,
                  1/*#VTs*/, MVT::i64, 2/*#Ops*/, 4, 5,  // Results = #6
/*4438*/      OPC_EmitNodeXForm, 1, 0, // HI22
/*4441*/      OPC_EmitNode, TARGET_VAL(SP::SETHIi), 0,
                  1/*#VTs*/, MVT::i32, 1/*#Ops*/, 7,  // Results = #8
/*4449*/      OPC_EmitNodeXForm, 2, 0, // LO10
/*4452*/      OPC_EmitNode, TARGET_VAL(SP::ORri), 0,
                  1/*#VTs*/, MVT::i32, 2/*#Ops*/, 8, 9,  // Results = #10
/*4461*/      OPC_MorphNodeTo, TARGET_VAL(SP::ORrr), 0,
                  1/*#VTs*/, MVT::i64, 2/*#Ops*/, 6, 10, 
              // Src: (imm:i64):$val - Complexity = 3
              // Dst: (ORrr:i64 (SLLXri:i64 (ORri:i64 (SETHIi:i32 (HH22:i32 ?:i64:$val)), (HM10:i32 ?:i64:$val)), 32:i32), (ORri:i32 (SETHIi:i32 (HI22:i32 ?:i64:$val)), (LO10:i32 ?:i64:$val)))
/*4470*/    0, /*End of Scope*/
/*4471*/  /*SwitchOpcode*/ 21,  TARGET_VAL(SPISD::FLUSHW),// ->4495
/*4474*/    OPC_RecordNode,   // #0 = 'flushw' chained node
/*4475*/    OPC_Scope, 9, /*->4486*/ // 2 children in Scope
/*4477*/      OPC_CheckPatternPredicate, 2, // (Subtarget.isV9())
/*4479*/      OPC_EmitMergeInputChains1_0,
/*4480*/      OPC_MorphNodeTo, TARGET_VAL(SP::FLUSHW), 0|OPFL_Chain,
                  0/*#VTs*/, 0/*#Ops*/, 
              // Src: (flushw) - Complexity = 3
              // Dst: (FLUSHW)
/*4486*/    /*Scope*/ 7, /*->4494*/
/*4487*/      OPC_EmitMergeInputChains1_0,
/*4488*/      OPC_MorphNodeTo, TARGET_VAL(SP::TA3), 0|OPFL_Chain,
                  0/*#VTs*/, 0/*#Ops*/, 
              // Src: (flushw) - Complexity = 3
              // Dst: (TA3)
/*4494*/    0, /*End of Scope*/
/*4495*/  /*SwitchOpcode*/ 16,  TARGET_VAL(ISD::BR),// ->4514
/*4498*/    OPC_RecordNode,   // #0 = 'br' chained node
/*4499*/    OPC_RecordChild1, // #1 = $imm22
/*4500*/    OPC_MoveChild, 1,
/*4502*/    OPC_CheckOpcode, TARGET_VAL(ISD::BasicBlock),
/*4505*/    OPC_MoveParent,
/*4506*/    OPC_EmitMergeInputChains1_0,
/*4507*/    OPC_MorphNodeTo, TARGET_VAL(SP::BA), 0|OPFL_Chain,
                0/*#VTs*/, 1/*#Ops*/, 1, 
            // Src: (br (bb:Other):$imm22) - Complexity = 3
            // Dst: (BA (bb:Other):$imm22)
/*4514*/  /*SwitchOpcode*/ 41,  TARGET_VAL(SPISD::CMPFCC),// ->4558
/*4517*/    OPC_RecordChild0, // #0 = $src1
/*4518*/    OPC_Scope, 11, /*->4531*/ // 3 children in Scope
/*4520*/      OPC_CheckChild0Type, MVT::f32,
/*4522*/      OPC_RecordChild1, // #1 = $src2
/*4523*/      OPC_MorphNodeTo, TARGET_VAL(SP::FCMPS), 0|OPFL_GlueOutput,
                  0/*#VTs*/, 2/*#Ops*/, 0, 1, 
              // Src: (SPcmpfcc f32:f32:$src1, f32:f32:$src2) - Complexity = 3
              // Dst: (FCMPS f32:f32:$src1, f32:f32:$src2)
/*4531*/    /*Scope*/ 11, /*->4543*/
/*4532*/      OPC_CheckChild0Type, MVT::f64,
/*4534*/      OPC_RecordChild1, // #1 = $src2
/*4535*/      OPC_MorphNodeTo, TARGET_VAL(SP::FCMPD), 0|OPFL_GlueOutput,
                  0/*#VTs*/, 2/*#Ops*/, 0, 1, 
              // Src: (SPcmpfcc f64:f64:$src1, f64:f64:$src2) - Complexity = 3
              // Dst: (FCMPD f64:f64:$src1, f64:f64:$src2)
/*4543*/    /*Scope*/ 13, /*->4557*/
/*4544*/      OPC_CheckChild0Type, MVT::f128,
/*4546*/      OPC_RecordChild1, // #1 = $src2
/*4547*/      OPC_CheckPatternPredicate, 4, // (Subtarget.hasHardQuad())
/*4549*/      OPC_MorphNodeTo, TARGET_VAL(SP::FCMPQ), 0|OPFL_GlueOutput,
                  0/*#VTs*/, 2/*#Ops*/, 0, 1, 
              // Src: (SPcmpfcc f128:f128:$src1, f128:f128:$src2) - Complexity = 3
              // Dst: (FCMPQ f128:f128:$src1, f128:f128:$src2)
/*4557*/    0, /*End of Scope*/
/*4558*/  /*SwitchOpcode*/ 15,  TARGET_VAL(ISD::ANY_EXTEND),// ->4576
/*4561*/    OPC_RecordChild0, // #0 = $val
/*4562*/    OPC_CheckPatternPredicate, 0, // (Subtarget.is64Bit())
/*4564*/    OPC_EmitInteger, MVT::i32, SP::I64RegsRegClassID,
/*4567*/    OPC_MorphNodeTo, TARGET_VAL(TargetOpcode::COPY_TO_REGCLASS), 0,
                1/*#VTs*/, MVT::i64, 2/*#Ops*/, 0, 1, 
            // Src: (anyext:i64 i32:i32:$val) - Complexity = 3
            // Dst: (COPY_TO_REGCLASS:i64 ?:i32:$val, I64Regs:i32)
/*4576*/  /*SwitchOpcode*/ 15,  TARGET_VAL(ISD::TRUNCATE),// ->4594
/*4579*/    OPC_RecordChild0, // #0 = $val
/*4580*/    OPC_CheckPatternPredicate, 0, // (Subtarget.is64Bit())
/*4582*/    OPC_EmitInteger, MVT::i32, SP::IntRegsRegClassID,
/*4585*/    OPC_MorphNodeTo, TARGET_VAL(TargetOpcode::COPY_TO_REGCLASS), 0,
                1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1, 
            // Src: (trunc:i32 i64:i64:$val) - Complexity = 3
            // Dst: (COPY_TO_REGCLASS:i32 ?:i64:$val, IntRegs:i32)
/*4594*/  /*SwitchOpcode*/ 15,  TARGET_VAL(ISD::ZERO_EXTEND),// ->4612
/*4597*/    OPC_RecordChild0, // #0 = $val
/*4598*/    OPC_CheckPatternPredicate, 0, // (Subtarget.is64Bit())
/*4600*/    OPC_EmitInteger, MVT::i32, 0, 
/*4603*/    OPC_MorphNodeTo, TARGET_VAL(SP::SRLri), 0,
                1/*#VTs*/, MVT::i64, 2/*#Ops*/, 0, 1, 
            // Src: (zext:i64 i32:i32:$val) - Complexity = 3
            // Dst: (SRLri:i64 ?:i32:$val, 0:i32)
/*4612*/  /*SwitchOpcode*/ 15,  TARGET_VAL(ISD::SIGN_EXTEND),// ->4630
/*4615*/    OPC_RecordChild0, // #0 = $val
/*4616*/    OPC_CheckPatternPredicate, 0, // (Subtarget.is64Bit())
/*4618*/    OPC_EmitInteger, MVT::i32, 0, 
/*4621*/    OPC_MorphNodeTo, TARGET_VAL(SP::SRAri), 0,
                1/*#VTs*/, MVT::i64, 2/*#Ops*/, 0, 1, 
            // Src: (sext:i64 i32:i32:$val) - Complexity = 3
            // Dst: (SRAri:i64 ?:i32:$val, 0:i32)
/*4630*/  /*SwitchOpcode*/ 20,  TARGET_VAL(ISD::SIGN_EXTEND_INREG),// ->4653
/*4633*/    OPC_RecordChild0, // #0 = $val
/*4634*/    OPC_MoveChild, 1,
/*4636*/    OPC_CheckValueType, MVT::i32,
/*4638*/    OPC_MoveParent,
/*4639*/    OPC_CheckPatternPredicate, 0, // (Subtarget.is64Bit())
/*4641*/    OPC_EmitInteger, MVT::i32, 0, 
/*4644*/    OPC_MorphNodeTo, TARGET_VAL(SP::SRAri), 0,
                1/*#VTs*/, MVT::i64, 2/*#Ops*/, 0, 1, 
            // Src: (sext_inreg:i64 i64:i64:$val, i32:Other) - Complexity = 3
            // Dst: (SRAri:i64 ?:i64:$val, 0:i32)
/*4653*/  /*SwitchOpcode*/ 37,  TARGET_VAL(ISD::CTPOP),// ->4693
/*4656*/    OPC_RecordChild0, // #0 = $src
/*4657*/    OPC_SwitchType /*2 cases */, 10,  MVT::i64,// ->4670
/*4660*/      OPC_CheckPatternPredicate, 0, // (Subtarget.is64Bit())
/*4662*/      OPC_MorphNodeTo, TARGET_VAL(SP::POPCrr), 0,
                  1/*#VTs*/, MVT::i64, 1/*#Ops*/, 0, 
              // Src: (ctpop:i64 i64:i64:$src) - Complexity = 3
              // Dst: (POPCrr:i64 ?:i64:$src)
/*4670*/    /*SwitchType*/ 20,  MVT::i32,// ->4692
/*4672*/      OPC_EmitInteger, MVT::i32, 0, 
/*4675*/      OPC_EmitNode, TARGET_VAL(SP::SLLri), 0,
                  1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1,  // Results = #2
/*4684*/      OPC_MorphNodeTo, TARGET_VAL(SP::POPCrr), 0,
                  1/*#VTs*/, MVT::i32, 1/*#Ops*/, 2, 
              // Src: (ctpop:i32 i32:i32:$src) - Complexity = 3
              // Dst: (POPCrr:i32 (SLLri:i32 ?:i32:$src, 0:i32))
/*4692*/    0, // EndSwitchType
/*4693*/  /*SwitchOpcode*/ 97,  TARGET_VAL(ISD::FMUL),// ->4793
/*4696*/    OPC_Scope, 54, /*->4752*/ // 2 children in Scope
/*4698*/      OPC_MoveChild, 0,
/*4700*/      OPC_CheckOpcode, TARGET_VAL(ISD::FP_EXTEND),
/*4703*/      OPC_RecordChild0, // #0 = $src1
/*4704*/      OPC_Scope, 19, /*->4725*/ // 2 children in Scope
/*4706*/        OPC_MoveParent,
/*4707*/        OPC_MoveChild, 1,
/*4709*/        OPC_CheckOpcode, TARGET_VAL(ISD::FP_EXTEND),
/*4712*/        OPC_RecordChild0, // #1 = $src2
/*4713*/        OPC_MoveParent,
/*4714*/        OPC_CheckType, MVT::f64,
/*4716*/        OPC_MorphNodeTo, TARGET_VAL(SP::FSMULD), 0,
                    1/*#VTs*/, MVT::f64, 2/*#Ops*/, 0, 1, 
                // Src: (fmul:f64 (fextend:f64 f32:f32:$src1), (fextend:f64 f32:f32:$src2)) - Complexity = 9
                // Dst: (FSMULD:f64 f32:f32:$src1, f32:f32:$src2)
/*4725*/      /*Scope*/ 25, /*->4751*/
/*4726*/        OPC_CheckChild0Type, MVT::f64,
/*4728*/        OPC_MoveParent,
/*4729*/        OPC_MoveChild, 1,
/*4731*/        OPC_CheckOpcode, TARGET_VAL(ISD::FP_EXTEND),
/*4734*/        OPC_RecordChild0, // #1 = $src2
/*4735*/        OPC_CheckChild0Type, MVT::f64,
/*4737*/        OPC_MoveParent,
/*4738*/        OPC_CheckType, MVT::f128,
/*4740*/        OPC_CheckPatternPredicate, 4, // (Subtarget.hasHardQuad())
/*4742*/        OPC_MorphNodeTo, TARGET_VAL(SP::FDMULQ), 0,
                    1/*#VTs*/, MVT::f128, 2/*#Ops*/, 0, 1, 
                // Src: (fmul:f128 (fextend:f128 f64:f64:$src1), (fextend:f128 f64:f64:$src2)) - Complexity = 9
                // Dst: (FDMULQ:f128 f64:f64:$src1, f64:f64:$src2)
/*4751*/      0, /*End of Scope*/
/*4752*/    /*Scope*/ 39, /*->4792*/
/*4753*/      OPC_RecordChild0, // #0 = $src1
/*4754*/      OPC_RecordChild1, // #1 = $src2
/*4755*/      OPC_SwitchType /*3 cases */, 9,  MVT::f32,// ->4767
/*4758*/        OPC_MorphNodeTo, TARGET_VAL(SP::FMULS), 0,
                    1/*#VTs*/, MVT::f32, 2/*#Ops*/, 0, 1, 
                // Src: (fmul:f32 f32:f32:$src1, f32:f32:$src2) - Complexity = 3
                // Dst: (FMULS:f32 f32:f32:$src1, f32:f32:$src2)
/*4767*/      /*SwitchType*/ 9,  MVT::f64,// ->4778
/*4769*/        OPC_MorphNodeTo, TARGET_VAL(SP::FMULD), 0,
                    1/*#VTs*/, MVT::f64, 2/*#Ops*/, 0, 1, 
                // Src: (fmul:f64 f64:f64:$src1, f64:f64:$src2) - Complexity = 3
                // Dst: (FMULD:f64 f64:f64:$src1, f64:f64:$src2)
/*4778*/      /*SwitchType*/ 11,  MVT::f128,// ->4791
/*4780*/        OPC_CheckPatternPredicate, 4, // (Subtarget.hasHardQuad())
/*4782*/        OPC_MorphNodeTo, TARGET_VAL(SP::FMULQ), 0,
                    1/*#VTs*/, MVT::f128, 2/*#Ops*/, 0, 1, 
                // Src: (fmul:f128 f128:f128:$src1, f128:f128:$src2) - Complexity = 3
                // Dst: (FMULQ:f128 f128:f128:$src1, f128:f128:$src2)
/*4791*/      0, // EndSwitchType
/*4792*/    0, /*End of Scope*/
/*4793*/  /*SwitchOpcode*/ 35,  TARGET_VAL(SPISD::ITOF),// ->4831
/*4796*/    OPC_RecordChild0, // #0 = $src
/*4797*/    OPC_SwitchType /*3 cases */, 8,  MVT::f32,// ->4808
/*4800*/      OPC_MorphNodeTo, TARGET_VAL(SP::FITOS), 0,
                  1/*#VTs*/, MVT::f32, 1/*#Ops*/, 0, 
              // Src: (SPitof:f32 FPRegs:f32:$src) - Complexity = 3
              // Dst: (FITOS:f32 FPRegs:f32:$src)
/*4808*/    /*SwitchType*/ 8,  MVT::f64,// ->4818
/*4810*/      OPC_MorphNodeTo, TARGET_VAL(SP::FITOD), 0,
                  1/*#VTs*/, MVT::f64, 1/*#Ops*/, 0, 
              // Src: (SPitof:f64 FPRegs:f32:$src) - Complexity = 3
              // Dst: (FITOD:f64 FPRegs:f32:$src)
/*4818*/    /*SwitchType*/ 10,  MVT::f128,// ->4830
/*4820*/      OPC_CheckPatternPredicate, 4, // (Subtarget.hasHardQuad())
/*4822*/      OPC_MorphNodeTo, TARGET_VAL(SP::FITOQ), 0,
                  1/*#VTs*/, MVT::f128, 1/*#Ops*/, 0, 
              // Src: (SPitof:f128 FPRegs:f32:$src) - Complexity = 3
              // Dst: (FITOQ:f128 FPRegs:f32:$src)
/*4830*/    0, // EndSwitchType
/*4831*/  /*SwitchOpcode*/ 38,  TARGET_VAL(SPISD::FTOI),// ->4872
/*4834*/    OPC_RecordChild0, // #0 = $src
/*4835*/    OPC_Scope, 10, /*->4847*/ // 3 children in Scope
/*4837*/      OPC_CheckChild0Type, MVT::f32,
/*4839*/      OPC_MorphNodeTo, TARGET_VAL(SP::FSTOI), 0,
                  1/*#VTs*/, MVT::f32, 1/*#Ops*/, 0, 
              // Src: (SPftoi:f32 FPRegs:f32:$src) - Complexity = 3
              // Dst: (FSTOI:f32 FPRegs:f32:$src)
/*4847*/    /*Scope*/ 10, /*->4858*/
/*4848*/      OPC_CheckChild0Type, MVT::f64,
/*4850*/      OPC_MorphNodeTo, TARGET_VAL(SP::FDTOI), 0,
                  1/*#VTs*/, MVT::f32, 1/*#Ops*/, 0, 
              // Src: (SPftoi:f32 DFPRegs:f64:$src) - Complexity = 3
              // Dst: (FDTOI:f32 DFPRegs:f64:$src)
/*4858*/    /*Scope*/ 12, /*->4871*/
/*4859*/      OPC_CheckChild0Type, MVT::f128,
/*4861*/      OPC_CheckPatternPredicate, 4, // (Subtarget.hasHardQuad())
/*4863*/      OPC_MorphNodeTo, TARGET_VAL(SP::FQTOI), 0,
                  1/*#VTs*/, MVT::f32, 1/*#Ops*/, 0, 
              // Src: (SPftoi:f32 QFPRegs:f128:$src) - Complexity = 3
              // Dst: (FQTOI:f32 QFPRegs:f128:$src)
/*4871*/    0, /*End of Scope*/
/*4872*/  /*SwitchOpcode*/ 43,  TARGET_VAL(ISD::FP_EXTEND),// ->4918
/*4875*/    OPC_RecordChild0, // #0 = $src
/*4876*/    OPC_SwitchType /*2 cases */, 8,  MVT::f64,// ->4887
/*4879*/      OPC_MorphNodeTo, TARGET_VAL(SP::FSTOD), 0,
                  1/*#VTs*/, MVT::f64, 1/*#Ops*/, 0, 
              // Src: (fextend:f64 f32:f32:$src) - Complexity = 3
              // Dst: (FSTOD:f64 f32:f32:$src)
/*4887*/    /*SwitchType*/ 28,  MVT::f128,// ->4917
/*4889*/      OPC_Scope, 12, /*->4903*/ // 2 children in Scope
/*4891*/        OPC_CheckChild0Type, MVT::f32,
/*4893*/        OPC_CheckPatternPredicate, 4, // (Subtarget.hasHardQuad())
/*4895*/        OPC_MorphNodeTo, TARGET_VAL(SP::FSTOQ), 0,
                    1/*#VTs*/, MVT::f128, 1/*#Ops*/, 0, 
                // Src: (fextend:f128 f32:f32:$src) - Complexity = 3
                // Dst: (FSTOQ:f128 f32:f32:$src)
/*4903*/      /*Scope*/ 12, /*->4916*/
/*4904*/        OPC_CheckChild0Type, MVT::f64,
/*4906*/        OPC_CheckPatternPredicate, 4, // (Subtarget.hasHardQuad())
/*4908*/        OPC_MorphNodeTo, TARGET_VAL(SP::FDTOQ), 0,
                    1/*#VTs*/, MVT::f128, 1/*#Ops*/, 0, 
                // Src: (fextend:f128 f64:f64:$src) - Complexity = 3
                // Dst: (FDTOQ:f128 f64:f64:$src)
/*4916*/      0, /*End of Scope*/
/*4917*/    0, // EndSwitchType
/*4918*/  /*SwitchOpcode*/ 43,  TARGET_VAL(ISD::FP_ROUND),// ->4964
/*4921*/    OPC_RecordChild0, // #0 = $src
/*4922*/    OPC_SwitchType /*2 cases */, 26,  MVT::f32,// ->4951
/*4925*/      OPC_Scope, 10, /*->4937*/ // 2 children in Scope
/*4927*/        OPC_CheckChild0Type, MVT::f64,
/*4929*/        OPC_MorphNodeTo, TARGET_VAL(SP::FDTOS), 0,
                    1/*#VTs*/, MVT::f32, 1/*#Ops*/, 0, 
                // Src: (fround:f32 f64:f64:$src) - Complexity = 3
                // Dst: (FDTOS:f32 f64:f64:$src)
/*4937*/      /*Scope*/ 12, /*->4950*/
/*4938*/        OPC_CheckChild0Type, MVT::f128,
/*4940*/        OPC_CheckPatternPredicate, 4, // (Subtarget.hasHardQuad())
/*4942*/        OPC_MorphNodeTo, TARGET_VAL(SP::FQTOS), 0,
                    1/*#VTs*/, MVT::f32, 1/*#Ops*/, 0, 
                // Src: (fround:f32 f128:f128:$src) - Complexity = 3
                // Dst: (FQTOS:f32 f128:f128:$src)
/*4950*/      0, /*End of Scope*/
/*4951*/    /*SwitchType*/ 10,  MVT::f64,// ->4963
/*4953*/      OPC_CheckPatternPredicate, 4, // (Subtarget.hasHardQuad())
/*4955*/      OPC_MorphNodeTo, TARGET_VAL(SP::FQTOD), 0,
                  1/*#VTs*/, MVT::f64, 1/*#Ops*/, 0, 
              // Src: (fround:f64 f128:f128:$src) - Complexity = 3
              // Dst: (FQTOD:f64 f128:f128:$src)
/*4963*/    0, // EndSwitchType
/*4964*/  /*SwitchOpcode*/ 37,  TARGET_VAL(ISD::FNEG),// ->5004
/*4967*/    OPC_RecordChild0, // #0 = $src
/*4968*/    OPC_SwitchType /*3 cases */, 8,  MVT::f32,// ->4979
/*4971*/      OPC_MorphNodeTo, TARGET_VAL(SP::FNEGS), 0,
                  1/*#VTs*/, MVT::f32, 1/*#Ops*/, 0, 
              // Src: (fneg:f32 f32:f32:$src) - Complexity = 3
              // Dst: (FNEGS:f32 f32:f32:$src)
/*4979*/    /*SwitchType*/ 10,  MVT::f64,// ->4991
/*4981*/      OPC_CheckPatternPredicate, 2, // (Subtarget.isV9())
/*4983*/      OPC_MorphNodeTo, TARGET_VAL(SP::FNEGD), 0,
                  1/*#VTs*/, MVT::f64, 1/*#Ops*/, 0, 
              // Src: (fneg:f64 f64:f64:$src) - Complexity = 3
              // Dst: (FNEGD:f64 f64:f64:$src)
/*4991*/    /*SwitchType*/ 10,  MVT::f128,// ->5003
/*4993*/      OPC_CheckPatternPredicate, 2, // (Subtarget.isV9())
/*4995*/      OPC_MorphNodeTo, TARGET_VAL(SP::FNEGQ), 0,
                  1/*#VTs*/, MVT::f128, 1/*#Ops*/, 0, 
              // Src: (fneg:f128 f128:f128:$src) - Complexity = 3
              // Dst: (FNEGQ:f128 f128:f128:$src)
/*5003*/    0, // EndSwitchType
/*5004*/  /*SwitchOpcode*/ 37,  TARGET_VAL(ISD::FABS),// ->5044
/*5007*/    OPC_RecordChild0, // #0 = $src
/*5008*/    OPC_SwitchType /*3 cases */, 8,  MVT::f32,// ->5019
/*5011*/      OPC_MorphNodeTo, TARGET_VAL(SP::FABSS), 0,
                  1/*#VTs*/, MVT::f32, 1/*#Ops*/, 0, 
              // Src: (fabs:f32 f32:f32:$src) - Complexity = 3
              // Dst: (FABSS:f32 f32:f32:$src)
/*5019*/    /*SwitchType*/ 10,  MVT::f64,// ->5031
/*5021*/      OPC_CheckPatternPredicate, 2, // (Subtarget.isV9())
/*5023*/      OPC_MorphNodeTo, TARGET_VAL(SP::FABSD), 0,
                  1/*#VTs*/, MVT::f64, 1/*#Ops*/, 0, 
              // Src: (fabs:f64 f64:f64:$src) - Complexity = 3
              // Dst: (FABSD:f64 f64:f64:$src)
/*5031*/    /*SwitchType*/ 10,  MVT::f128,// ->5043
/*5033*/      OPC_CheckPatternPredicate, 2, // (Subtarget.isV9())
/*5035*/      OPC_MorphNodeTo, TARGET_VAL(SP::FABSQ), 0,
                  1/*#VTs*/, MVT::f128, 1/*#Ops*/, 0, 
              // Src: (fabs:f128 f128:f128:$src) - Complexity = 3
              // Dst: (FABSQ:f128 f128:f128:$src)
/*5043*/    0, // EndSwitchType
/*5044*/  /*SwitchOpcode*/ 35,  TARGET_VAL(ISD::FSQRT),// ->5082
/*5047*/    OPC_RecordChild0, // #0 = $src
/*5048*/    OPC_SwitchType /*3 cases */, 8,  MVT::f32,// ->5059
/*5051*/      OPC_MorphNodeTo, TARGET_VAL(SP::FSQRTS), 0,
                  1/*#VTs*/, MVT::f32, 1/*#Ops*/, 0, 
              // Src: (fsqrt:f32 f32:f32:$src) - Complexity = 3
              // Dst: (FSQRTS:f32 f32:f32:$src)
/*5059*/    /*SwitchType*/ 8,  MVT::f64,// ->5069
/*5061*/      OPC_MorphNodeTo, TARGET_VAL(SP::FSQRTD), 0,
                  1/*#VTs*/, MVT::f64, 1/*#Ops*/, 0, 
              // Src: (fsqrt:f64 f64:f64:$src) - Complexity = 3
              // Dst: (FSQRTD:f64 f64:f64:$src)
/*5069*/    /*SwitchType*/ 10,  MVT::f128,// ->5081
/*5071*/      OPC_CheckPatternPredicate, 4, // (Subtarget.hasHardQuad())
/*5073*/      OPC_MorphNodeTo, TARGET_VAL(SP::FSQRTQ), 0,
                  1/*#VTs*/, MVT::f128, 1/*#Ops*/, 0, 
              // Src: (fsqrt:f128 f128:f128:$src) - Complexity = 3
              // Dst: (FSQRTQ:f128 f128:f128:$src)
/*5081*/    0, // EndSwitchType
/*5082*/  /*SwitchOpcode*/ 39,  TARGET_VAL(ISD::FADD),// ->5124
/*5085*/    OPC_RecordChild0, // #0 = $src1
/*5086*/    OPC_RecordChild1, // #1 = $src2
/*5087*/    OPC_SwitchType /*3 cases */, 9,  MVT::f32,// ->5099
/*5090*/      OPC_MorphNodeTo, TARGET_VAL(SP::FADDS), 0,
                  1/*#VTs*/, MVT::f32, 2/*#Ops*/, 0, 1, 
              // Src: (fadd:f32 f32:f32:$src1, f32:f32:$src2) - Complexity = 3
              // Dst: (FADDS:f32 f32:f32:$src1, f32:f32:$src2)
/*5099*/    /*SwitchType*/ 9,  MVT::f64,// ->5110
/*5101*/      OPC_MorphNodeTo, TARGET_VAL(SP::FADDD), 0,
                  1/*#VTs*/, MVT::f64, 2/*#Ops*/, 0, 1, 
              // Src: (fadd:f64 f64:f64:$src1, f64:f64:$src2) - Complexity = 3
              // Dst: (FADDD:f64 f64:f64:$src1, f64:f64:$src2)
/*5110*/    /*SwitchType*/ 11,  MVT::f128,// ->5123
/*5112*/      OPC_CheckPatternPredicate, 4, // (Subtarget.hasHardQuad())
/*5114*/      OPC_MorphNodeTo, TARGET_VAL(SP::FADDQ), 0,
                  1/*#VTs*/, MVT::f128, 2/*#Ops*/, 0, 1, 
              // Src: (fadd:f128 f128:f128:$src1, f128:f128:$src2) - Complexity = 3
              // Dst: (FADDQ:f128 f128:f128:$src1, f128:f128:$src2)
/*5123*/    0, // EndSwitchType
/*5124*/  /*SwitchOpcode*/ 39,  TARGET_VAL(ISD::FSUB),// ->5166
/*5127*/    OPC_RecordChild0, // #0 = $src1
/*5128*/    OPC_RecordChild1, // #1 = $src2
/*5129*/    OPC_SwitchType /*3 cases */, 9,  MVT::f32,// ->5141
/*5132*/      OPC_MorphNodeTo, TARGET_VAL(SP::FSUBS), 0,
                  1/*#VTs*/, MVT::f32, 2/*#Ops*/, 0, 1, 
              // Src: (fsub:f32 f32:f32:$src1, f32:f32:$src2) - Complexity = 3
              // Dst: (FSUBS:f32 f32:f32:$src1, f32:f32:$src2)
/*5141*/    /*SwitchType*/ 9,  MVT::f64,// ->5152
/*5143*/      OPC_MorphNodeTo, TARGET_VAL(SP::FSUBD), 0,
                  1/*#VTs*/, MVT::f64, 2/*#Ops*/, 0, 1, 
              // Src: (fsub:f64 f64:f64:$src1, f64:f64:$src2) - Complexity = 3
              // Dst: (FSUBD:f64 f64:f64:$src1, f64:f64:$src2)
/*5152*/    /*SwitchType*/ 11,  MVT::f128,// ->5165
/*5154*/      OPC_CheckPatternPredicate, 4, // (Subtarget.hasHardQuad())
/*5156*/      OPC_MorphNodeTo, TARGET_VAL(SP::FSUBQ), 0,
                  1/*#VTs*/, MVT::f128, 2/*#Ops*/, 0, 1, 
              // Src: (fsub:f128 f128:f128:$src1, f128:f128:$src2) - Complexity = 3
              // Dst: (FSUBQ:f128 f128:f128:$src1, f128:f128:$src2)
/*5165*/    0, // EndSwitchType
/*5166*/  /*SwitchOpcode*/ 39,  TARGET_VAL(ISD::FDIV),// ->5208
/*5169*/    OPC_RecordChild0, // #0 = $src1
/*5170*/    OPC_RecordChild1, // #1 = $src2
/*5171*/    OPC_SwitchType /*3 cases */, 9,  MVT::f32,// ->5183
/*5174*/      OPC_MorphNodeTo, TARGET_VAL(SP::FDIVS), 0,
                  1/*#VTs*/, MVT::f32, 2/*#Ops*/, 0, 1, 
              // Src: (fdiv:f32 f32:f32:$src1, f32:f32:$src2) - Complexity = 3
              // Dst: (FDIVS:f32 f32:f32:$src1, f32:f32:$src2)
/*5183*/    /*SwitchType*/ 9,  MVT::f64,// ->5194
/*5185*/      OPC_MorphNodeTo, TARGET_VAL(SP::FDIVD), 0,
                  1/*#VTs*/, MVT::f64, 2/*#Ops*/, 0, 1, 
              // Src: (fdiv:f64 f64:f64:$src1, f64:f64:$src2) - Complexity = 3
              // Dst: (FDIVD:f64 f64:f64:$src1, f64:f64:$src2)
/*5194*/    /*SwitchType*/ 11,  MVT::f128,// ->5207
/*5196*/      OPC_CheckPatternPredicate, 4, // (Subtarget.hasHardQuad())
/*5198*/      OPC_MorphNodeTo, TARGET_VAL(SP::FDIVQ), 0,
                  1/*#VTs*/, MVT::f128, 2/*#Ops*/, 0, 1, 
              // Src: (fdiv:f128 f128:f128:$src1, f128:f128:$src2) - Complexity = 3
              // Dst: (FDIVQ:f128 f128:f128:$src1, f128:f128:$src2)
/*5207*/    0, // EndSwitchType
/*5208*/  /*SwitchOpcode*/ 39,  TARGET_VAL(SPISD::XTOF),// ->5250
/*5211*/    OPC_RecordChild0, // #0 = $src
/*5212*/    OPC_SwitchType /*3 cases */, 10,  MVT::f32,// ->5225
/*5215*/      OPC_CheckPatternPredicate, 0, // (Subtarget.is64Bit())
/*5217*/      OPC_MorphNodeTo, TARGET_VAL(SP::FXTOS), 0,
                  1/*#VTs*/, MVT::f32, 1/*#Ops*/, 0, 
              // Src: (SPxtof:f32 DFPRegs:f64:$src) - Complexity = 3
              // Dst: (FXTOS:f32 DFPRegs:f64:$src)
/*5225*/    /*SwitchType*/ 10,  MVT::f64,// ->5237
/*5227*/      OPC_CheckPatternPredicate, 0, // (Subtarget.is64Bit())
/*5229*/      OPC_MorphNodeTo, TARGET_VAL(SP::FXTOD), 0,
                  1/*#VTs*/, MVT::f64, 1/*#Ops*/, 0, 
              // Src: (SPxtof:f64 DFPRegs:f64:$src) - Complexity = 3
              // Dst: (FXTOD:f64 DFPRegs:f64:$src)
/*5237*/    /*SwitchType*/ 10,  MVT::f128,// ->5249
/*5239*/      OPC_CheckPatternPredicate, 0, // (Subtarget.is64Bit())
/*5241*/      OPC_MorphNodeTo, TARGET_VAL(SP::FXTOQ), 0,
                  1/*#VTs*/, MVT::f128, 1/*#Ops*/, 0, 
              // Src: (SPxtof:f128 DFPRegs:f64:$src) - Complexity = 3
              // Dst: (FXTOQ:f128 DFPRegs:f64:$src)
/*5249*/    0, // EndSwitchType
/*5250*/  /*SwitchOpcode*/ 42,  TARGET_VAL(SPISD::FTOX),// ->5295
/*5253*/    OPC_RecordChild0, // #0 = $src
/*5254*/    OPC_Scope, 12, /*->5268*/ // 3 children in Scope
/*5256*/      OPC_CheckChild0Type, MVT::f32,
/*5258*/      OPC_CheckPatternPredicate, 0, // (Subtarget.is64Bit())
/*5260*/      OPC_MorphNodeTo, TARGET_VAL(SP::FSTOX), 0,
                  1/*#VTs*/, MVT::f64, 1/*#Ops*/, 0, 
              // Src: (SPftox:f64 FPRegs:f32:$src) - Complexity = 3
              // Dst: (FSTOX:f64 FPRegs:f32:$src)
/*5268*/    /*Scope*/ 12, /*->5281*/
/*5269*/      OPC_CheckChild0Type, MVT::f64,
/*5271*/      OPC_CheckPatternPredicate, 0, // (Subtarget.is64Bit())
/*5273*/      OPC_MorphNodeTo, TARGET_VAL(SP::FDTOX), 0,
                  1/*#VTs*/, MVT::f64, 1/*#Ops*/, 0, 
              // Src: (SPftox:f64 DFPRegs:f64:$src) - Complexity = 3
              // Dst: (FDTOX:f64 DFPRegs:f64:$src)
/*5281*/    /*Scope*/ 12, /*->5294*/
/*5282*/      OPC_CheckChild0Type, MVT::f128,
/*5284*/      OPC_CheckPatternPredicate, 0, // (Subtarget.is64Bit())
/*5286*/      OPC_MorphNodeTo, TARGET_VAL(SP::FQTOX), 0,
                  1/*#VTs*/, MVT::f64, 1/*#Ops*/, 0, 
              // Src: (SPftox:f64 QFPRegs:f128:$src) - Complexity = 3
              // Dst: (FQTOX:f64 QFPRegs:f128:$src)
/*5294*/    0, /*End of Scope*/
/*5295*/  0, // EndSwitchOpcode
    0
  }; // Total Array size is 5297 bytes

  // Opcode Histogram:
  // #OPC_Scope                          = 95
  // #OPC_RecordNode                     = 15
  // #OPC_RecordChild                    = 143
  // #OPC_RecordMemRef                   = 2
  // #OPC_CaptureGlueInput               = 12
  // #OPC_MoveChild                      = 85
  // #OPC_MoveParent                     = 108
  // #OPC_CheckSame                      = 0
  // #OPC_CheckChildSame                 = 0
  // #OPC_CheckPatternPredicate          = 108
  // #OPC_CheckPredicate                 = 85
  // #OPC_CheckOpcode                    = 67
  // #OPC_SwitchOpcode                   = 8
  // #OPC_CheckType                      = 67
  // #OPC_SwitchType                     = 35
  // #OPC_CheckChildType                 = 27
  // #OPC_CheckInteger                   = 10
  // #OPC_CheckCondCode                  = 0
  // #OPC_CheckValueType                 = 1
  // #OPC_CheckComplexPat                = 80
  // #OPC_CheckAndImm                    = 1
  // #OPC_CheckOrImm                     = 0
  // #OPC_CheckFoldableChainNode         = 0
  // #OPC_EmitInteger                    = 6
  // #OPC_EmitStringInteger              = 2
  // #OPC_EmitRegister                   = 10
  // #OPC_EmitConvertToTarget            = 59
  // #OPC_EmitMergeInputChains           = 88
  // #OPC_EmitCopyToReg                  = 0
  // #OPC_EmitNode                       = 13
  // #OPC_EmitNodeXForm                  = 22
  // #OPC_MarkGlueResults                = 0
  // #OPC_CompleteMatch                  = 0
  // #OPC_MorphNodeTo                    = 265

  #undef TARGET_VAL
  return SelectCodeCommon(N, MatcherTable,sizeof(MatcherTable));
}

virtual bool CheckPatternPredicate(unsigned PredNo) const {
  switch (PredNo) {
  default: llvm_unreachable("Invalid predicate in table?");
  case 0: return (Subtarget.is64Bit());
  case 1: return (Subtarget.isV9()) && (Subtarget.hasHardQuad());
  case 2: return (Subtarget.isV9());
  case 3: return (!Subtarget.is64Bit());
  case 4: return (Subtarget.hasHardQuad());
  }
}

virtual bool CheckNodePredicate(SDNode *Node,
                                unsigned PredNo) const {
  switch (PredNo) {
  default: llvm_unreachable("Invalid predicate in table?");
  case 0: { // Predicate_unindexedstore
    SDNode *N = Node;

  return cast<StoreSDNode>(N)->getAddressingMode() == ISD::UNINDEXED;

  }
  case 1: { // Predicate_store
    SDNode *N = Node;

  return !cast<StoreSDNode>(N)->isTruncatingStore();

  }
  case 2: { // Predicate_truncstore
    SDNode *N = Node;

  return cast<StoreSDNode>(N)->isTruncatingStore();

  }
  case 3: { // Predicate_truncstorei8
    SDNode *N = Node;

  return cast<StoreSDNode>(N)->getMemoryVT() == MVT::i8;

  }
  case 4: { // Predicate_truncstorei16
    SDNode *N = Node;

  return cast<StoreSDNode>(N)->getMemoryVT() == MVT::i16;

  }
  case 5: { // Predicate_truncstorei32
    SDNode *N = Node;

  return cast<StoreSDNode>(N)->getMemoryVT() == MVT::i32;

  }
  case 6: { // Predicate_simm13
    ConstantSDNode*N = cast<ConstantSDNode>(Node);
 return isInt<13>(N->getSExtValue()); 
  }
  case 7: { // Predicate_unindexedload
    SDNode *N = Node;

  return cast<LoadSDNode>(N)->getAddressingMode() == ISD::UNINDEXED;

  }
  case 8: { // Predicate_sextload
    SDNode *N = Node;

  return cast<LoadSDNode>(N)->getExtensionType() == ISD::SEXTLOAD;

  }
  case 9: { // Predicate_sextloadi8
    SDNode *N = Node;

  return cast<LoadSDNode>(N)->getMemoryVT() == MVT::i8;

  }
  case 10: { // Predicate_sextloadi16
    SDNode *N = Node;

  return cast<LoadSDNode>(N)->getMemoryVT() == MVT::i16;

  }
  case 11: { // Predicate_zextload
    SDNode *N = Node;

  return cast<LoadSDNode>(N)->getExtensionType() == ISD::ZEXTLOAD;

  }
  case 12: { // Predicate_zextloadi8
    SDNode *N = Node;

  return cast<LoadSDNode>(N)->getMemoryVT() == MVT::i8;

  }
  case 13: { // Predicate_zextloadi16
    SDNode *N = Node;

  return cast<LoadSDNode>(N)->getMemoryVT() == MVT::i16;

  }
  case 14: { // Predicate_load
    SDNode *N = Node;

  return cast<LoadSDNode>(N)->getExtensionType() == ISD::NON_EXTLOAD;

  }
  case 15: { // Predicate_extload
    SDNode *N = Node;

  return cast<LoadSDNode>(N)->getExtensionType() == ISD::EXTLOAD;

  }
  case 16: { // Predicate_extloadi1
    SDNode *N = Node;

  return cast<LoadSDNode>(N)->getMemoryVT() == MVT::i1;

  }
  case 17: { // Predicate_extloadi8
    SDNode *N = Node;

  return cast<LoadSDNode>(N)->getMemoryVT() == MVT::i8;

  }
  case 18: { // Predicate_extloadi16
    SDNode *N = Node;

  return cast<LoadSDNode>(N)->getMemoryVT() == MVT::i16;

  }
  case 19: { // Predicate_zextloadi1
    SDNode *N = Node;

  return cast<LoadSDNode>(N)->getMemoryVT() == MVT::i1;

  }
  case 20: { // Predicate_zextloadi32
    SDNode *N = Node;

  return cast<LoadSDNode>(N)->getMemoryVT() == MVT::i32;

  }
  case 21: { // Predicate_extloadi32
    SDNode *N = Node;

  return cast<LoadSDNode>(N)->getMemoryVT() == MVT::i32;

  }
  case 22: { // Predicate_sextloadi32
    SDNode *N = Node;

  return cast<LoadSDNode>(N)->getMemoryVT() == MVT::i32;

  }
  case 23: { // Predicate_simm11
    ConstantSDNode*N = cast<ConstantSDNode>(Node);
 return isInt<11>(N->getSExtValue()); 
  }
  case 24: { // Predicate_SETHIimm
    ConstantSDNode*N = cast<ConstantSDNode>(Node);

  return isShiftedUInt<22, 10>(N->getZExtValue());

  }
  case 25: { // Predicate_uimm32
    ConstantSDNode*N = cast<ConstantSDNode>(Node);
 return isUInt<32>(N->getZExtValue()); 
  }
  case 26: { // Predicate_nimm33
    ConstantSDNode*N = cast<ConstantSDNode>(Node);

  int64_t Imm = N->getSExtValue();
  return Imm < 0 && isInt<33>(Imm);

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
    return SelectADDRrr(N, Result[NextRes+0].first, Result[NextRes+1].first);
  case 1:
    Result.resize(NextRes+2);
    return SelectADDRri(N, Result[NextRes+0].first, Result[NextRes+1].first);
  }
}

virtual SDValue RunSDNodeXForm(SDValue V, unsigned XFormNo) {
  switch (XFormNo) {
  default: llvm_unreachable("Invalid xform # in table?");
  case 0: {  // as_i32imm
    ConstantSDNode *N = cast<ConstantSDNode>(V.getNode());

  return CurDAG->getTargetConstant(N->getSExtValue(), MVT::i32);

  }
  case 1: {  // HI22
    ConstantSDNode *N = cast<ConstantSDNode>(V.getNode());

  // Transformation function: shift the immediate value down into the low bits.
  return CurDAG->getTargetConstant((unsigned)N->getZExtValue() >> 10, MVT::i32);

  }
  case 2: {  // LO10
    ConstantSDNode *N = cast<ConstantSDNode>(V.getNode());

  return CurDAG->getTargetConstant((unsigned)N->getZExtValue() & 1023,
                                   MVT::i32);

  }
  case 3: {  // HIX22
    ConstantSDNode *N = cast<ConstantSDNode>(V.getNode());

  uint64_t Val = (~N->getZExtValue() >> 10) & ((1u << 22) - 1);
  return CurDAG->getTargetConstant(Val, MVT::i32);

  }
  case 4: {  // LOX10
    ConstantSDNode *N = cast<ConstantSDNode>(V.getNode());

  return CurDAG->getTargetConstant(~(~N->getZExtValue() & 0x3ff), MVT::i32);

  }
  case 5: {  // HH22
    ConstantSDNode *N = cast<ConstantSDNode>(V.getNode());

  uint64_t Val = (N->getZExtValue() >> 42) & ((1u << 22) - 1);
  return CurDAG->getTargetConstant(Val, MVT::i32);

  }
  case 6: {  // HM10
    ConstantSDNode *N = cast<ConstantSDNode>(V.getNode());

  uint64_t Val = (N->getZExtValue() >> 32) & ((1u << 10) - 1);
  return CurDAG->getTargetConstant(Val, MVT::i32);

  }
  }
}


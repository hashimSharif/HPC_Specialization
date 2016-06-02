/*===- TableGen'erated file -------------------------------------*- C++ -*-===*\
|*                                                                            *|
|*DAG Instruction Selector for the XCore target                               *|
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
/*0*/     OPC_SwitchOpcode /*41 cases */, 98|128,1/*226*/,  TARGET_VAL(ISD::ADD),// ->231
/*5*/       OPC_Scope, 34, /*->41*/ // 5 children in Scope
/*7*/         OPC_MoveChild, 0,
/*9*/         OPC_CheckOpcode, TARGET_VAL(ISD::SHL),
/*12*/        OPC_MoveChild, 0,
/*14*/        OPC_CheckInteger, 1, 
/*16*/        OPC_MoveParent,
/*17*/        OPC_RecordChild1, // #0 = $size
/*18*/        OPC_MoveParent,
/*19*/        OPC_MoveChild, 1,
/*21*/        OPC_CheckInteger, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*32*/        OPC_MoveParent,
/*33*/        OPC_MorphNodeTo, TARGET_VAL(XCore::MKMSK_2r), 0,
                  1/*#VTs*/, MVT::i32, 1/*#Ops*/, 0, 
              // Src: (add:i32 (shl:i32 1:i32, GRRegs:i32:$size), -1:i32) - Complexity = 16
              // Dst: (MKMSK_2r:i32 GRRegs:i32:$size)
/*41*/      /*Scope*/ 39, /*->81*/
/*42*/        OPC_RecordChild0, // #0 = $addr
/*43*/        OPC_MoveChild, 1,
/*45*/        OPC_CheckOpcode, TARGET_VAL(ISD::SHL),
/*48*/        OPC_RecordChild0, // #1 = $offset
/*49*/        OPC_MoveChild, 1,
/*51*/        OPC_Scope, 13, /*->66*/ // 2 children in Scope
/*53*/          OPC_CheckInteger, 2, 
/*55*/          OPC_MoveParent,
/*56*/          OPC_MoveParent,
/*57*/          OPC_MorphNodeTo, TARGET_VAL(XCore::LDAWF_l3r), 0,
                    1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1, 
                // Src: (add:i32 GRRegs:i32:$addr, (shl:i32 GRRegs:i32:$offset, 2:i32)) - Complexity = 11
                // Dst: (LDAWF_l3r:i32 GRRegs:i32:$addr, GRRegs:i32:$offset)
/*66*/        /*Scope*/ 13, /*->80*/
/*67*/          OPC_CheckInteger, 1, 
/*69*/          OPC_MoveParent,
/*70*/          OPC_MoveParent,
/*71*/          OPC_MorphNodeTo, TARGET_VAL(XCore::LDA16F_l3r), 0,
                    1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1, 
                // Src: (add:i32 GRRegs:i32:$addr, (shl:i32 GRRegs:i32:$offset, 1:i32)) - Complexity = 11
                // Dst: (LDA16F_l3r:i32 GRRegs:i32:$addr, GRRegs:i32:$offset)
/*80*/        0, /*End of Scope*/
/*81*/      /*Scope*/ 40, /*->122*/
/*82*/        OPC_MoveChild, 0,
/*84*/        OPC_CheckOpcode, TARGET_VAL(ISD::SHL),
/*87*/        OPC_RecordChild0, // #0 = $offset
/*88*/        OPC_MoveChild, 1,
/*90*/        OPC_Scope, 14, /*->106*/ // 2 children in Scope
/*92*/          OPC_CheckInteger, 2, 
/*94*/          OPC_MoveParent,
/*95*/          OPC_MoveParent,
/*96*/          OPC_RecordChild1, // #1 = $addr
/*97*/          OPC_MorphNodeTo, TARGET_VAL(XCore::LDAWF_l3r), 0,
                    1/*#VTs*/, MVT::i32, 2/*#Ops*/, 1, 0, 
                // Src: (add:i32 (shl:i32 GRRegs:i32:$offset, 2:i32), GRRegs:i32:$addr) - Complexity = 11
                // Dst: (LDAWF_l3r:i32 GRRegs:i32:$addr, GRRegs:i32:$offset)
/*106*/       /*Scope*/ 14, /*->121*/
/*107*/         OPC_CheckInteger, 1, 
/*109*/         OPC_MoveParent,
/*110*/         OPC_MoveParent,
/*111*/         OPC_RecordChild1, // #1 = $addr
/*112*/         OPC_MorphNodeTo, TARGET_VAL(XCore::LDA16F_l3r), 0,
                    1/*#VTs*/, MVT::i32, 2/*#Ops*/, 1, 0, 
                // Src: (add:i32 (shl:i32 GRRegs:i32:$offset, 1:i32), GRRegs:i32:$addr) - Complexity = 11
                // Dst: (LDA16F_l3r:i32 GRRegs:i32:$addr, GRRegs:i32:$offset)
/*121*/       0, /*End of Scope*/
/*122*/     /*Scope*/ 15, /*->138*/
/*123*/       OPC_RecordNode, // #0 = $addr
/*124*/       OPC_CheckType, MVT::i32,
/*126*/       OPC_CheckComplexPat, /*CP*/0, /*#*/0, // SelectADDRspii:$addr #1 #2
/*129*/       OPC_MorphNodeTo, TARGET_VAL(XCore::LDAWFI), 0,
                  1/*#VTs*/, MVT::i32, 2/*#Ops*/, 1, 2, 
              // Src: ADDRspii:i32:$addr - Complexity = 9
              // Dst: (LDAWFI:i32 ADDRspii:i32:$addr)
/*138*/     /*Scope*/ 91, /*->230*/
/*139*/       OPC_RecordChild0, // #0 = $b
/*140*/       OPC_RecordChild1, // #1 = $c
/*141*/       OPC_Scope, 76, /*->219*/ // 2 children in Scope
/*143*/         OPC_MoveChild, 1,
/*145*/         OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*148*/         OPC_Scope, 14, /*->164*/ // 4 children in Scope
/*150*/           OPC_CheckPredicate, 0, // Predicate_immUs
/*152*/           OPC_MoveParent,
/*153*/           OPC_EmitConvertToTarget, 1,
/*155*/           OPC_MorphNodeTo, TARGET_VAL(XCore::ADD_2rus), 0,
                      1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 2, 
                  // Src: (add:i32 GRRegs:i32:$b, (imm:i32)<<P:Predicate_immUs>>:$c) - Complexity = 7
                  // Dst: (ADD_2rus:i32 GRRegs:i32:$b, (imm:i32):$c)
/*164*/         /*Scope*/ 17, /*->182*/
/*165*/           OPC_CheckPredicate, 1, // Predicate_immUs4
/*167*/           OPC_MoveParent,
/*168*/           OPC_EmitConvertToTarget, 1,
/*170*/           OPC_EmitNodeXForm, 0, 2, // div4_xform
/*173*/           OPC_MorphNodeTo, TARGET_VAL(XCore::LDAWF_l2rus), 0,
                      1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 3, 
                  // Src: (add:i32 GRRegs:i32:$addr, (imm:i32)<<P:Predicate_immUs4>>:$offset) - Complexity = 7
                  // Dst: (LDAWF_l2rus:i32 GRRegs:i32:$addr, (div4_xform:i32 (imm:i32)<<P:Predicate_immUs4>>:$offset))
/*182*/         /*Scope*/ 17, /*->200*/
/*183*/           OPC_CheckPredicate, 2, // Predicate_immUsNeg
/*185*/           OPC_MoveParent,
/*186*/           OPC_EmitConvertToTarget, 1,
/*188*/           OPC_EmitNodeXForm, 1, 2, // neg_xform
/*191*/           OPC_MorphNodeTo, TARGET_VAL(XCore::SUB_2rus), 0,
                      1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 3, 
                  // Src: (add:i32 GRRegs:i32:$src1, (imm:i32)<<P:Predicate_immUsNeg>>:$src2) - Complexity = 7
                  // Dst: (SUB_2rus:i32 GRRegs:i32:$src1, (neg_xform:i32 (imm:i32)<<P:Predicate_immUsNeg>>:$src2))
/*200*/         /*Scope*/ 17, /*->218*/
/*201*/           OPC_CheckPredicate, 3, // Predicate_immUs4Neg
/*203*/           OPC_MoveParent,
/*204*/           OPC_EmitConvertToTarget, 1,
/*206*/           OPC_EmitNodeXForm, 2, 2, // div4neg_xform
/*209*/           OPC_MorphNodeTo, TARGET_VAL(XCore::LDAWB_l2rus), 0,
                      1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 3, 
                  // Src: (add:i32 GRRegs:i32:$src1, (imm:i32)<<P:Predicate_immUs4Neg>>:$src2) - Complexity = 7
                  // Dst: (LDAWB_l2rus:i32 GRRegs:i32:$src1, (div4neg_xform:i32 (imm:i32)<<P:Predicate_immUs4Neg>>:$src2))
/*218*/         0, /*End of Scope*/
/*219*/       /*Scope*/ 9, /*->229*/
/*220*/         OPC_MorphNodeTo, TARGET_VAL(XCore::ADD_3r), 0,
                    1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1, 
                // Src: (add:i32 GRRegs:i32:$b, GRRegs:i32:$c) - Complexity = 3
                // Dst: (ADD_3r:i32 GRRegs:i32:$b, GRRegs:i32:$c)
/*229*/       0, /*End of Scope*/
/*230*/     0, /*End of Scope*/
/*231*/   /*SwitchOpcode*/ 83|128,3/*467*/,  TARGET_VAL(ISD::LOAD),// ->702
/*235*/     OPC_RecordMemRef,
/*236*/     OPC_RecordNode,   // #0 = 'ld' chained node
/*237*/     OPC_Scope, 40|128,1/*168*/, /*->408*/ // 4 children in Scope
/*240*/       OPC_MoveChild, 1,
/*242*/       OPC_CheckOpcode, TARGET_VAL(ISD::ADD),
/*245*/       OPC_Scope, 79, /*->326*/ // 2 children in Scope
/*247*/         OPC_RecordChild0, // #1 = $addr
/*248*/         OPC_MoveChild, 1,
/*250*/         OPC_CheckOpcode, TARGET_VAL(ISD::SHL),
/*253*/         OPC_RecordChild0, // #2 = $offset
/*254*/         OPC_MoveChild, 1,
/*256*/         OPC_Scope, 43, /*->301*/ // 2 children in Scope
/*258*/           OPC_CheckInteger, 1, 
/*260*/           OPC_MoveParent,
/*261*/           OPC_MoveParent,
/*262*/           OPC_CheckType, MVT::i32,
/*264*/           OPC_MoveParent,
/*265*/           OPC_CheckPredicate, 4, // Predicate_unindexedload
/*267*/           OPC_CheckType, MVT::i32,
/*269*/           OPC_Scope, 14, /*->285*/ // 2 children in Scope
/*271*/             OPC_CheckPredicate, 5, // Predicate_sextload
/*273*/             OPC_CheckPredicate, 6, // Predicate_sextloadi16
/*275*/             OPC_EmitMergeInputChains1_0,
/*276*/             OPC_MorphNodeTo, TARGET_VAL(XCore::LD16S_3r), 0|OPFL_Chain|OPFL_MemRefs,
                        1/*#VTs*/, MVT::i32, 2/*#Ops*/, 1, 2, 
                    // Src: (ld:i32 (add:i32 GRRegs:i32:$addr, (shl:i32 GRRegs:i32:$offset, 1:i32)))<<P:Predicate_unindexedload>><<P:Predicate_sextload>><<P:Predicate_sextloadi16>> - Complexity = 15
                    // Dst: (LD16S_3r:i32 GRRegs:i32:$addr, GRRegs:i32:$offset)
/*285*/           /*Scope*/ 14, /*->300*/
/*286*/             OPC_CheckPredicate, 7, // Predicate_extload
/*288*/             OPC_CheckPredicate, 8, // Predicate_extloadi16
/*290*/             OPC_EmitMergeInputChains1_0,
/*291*/             OPC_MorphNodeTo, TARGET_VAL(XCore::LD16S_3r), 0|OPFL_Chain|OPFL_MemRefs,
                        1/*#VTs*/, MVT::i32, 2/*#Ops*/, 1, 2, 
                    // Src: (ld:i32 (add:i32 GRRegs:i32:$addr, (shl:i32 GRRegs:i32:$offset, 1:i32)))<<P:Predicate_unindexedload>><<P:Predicate_extload>><<P:Predicate_extloadi16>> - Complexity = 15
                    // Dst: (LD16S_3r:i32 GRRegs:i32:$addr, GRRegs:i32:$offset)
/*300*/           0, /*End of Scope*/
/*301*/         /*Scope*/ 23, /*->325*/
/*302*/           OPC_CheckInteger, 2, 
/*304*/           OPC_MoveParent,
/*305*/           OPC_MoveParent,
/*306*/           OPC_CheckType, MVT::i32,
/*308*/           OPC_MoveParent,
/*309*/           OPC_CheckPredicate, 4, // Predicate_unindexedload
/*311*/           OPC_CheckPredicate, 9, // Predicate_load
/*313*/           OPC_CheckType, MVT::i32,
/*315*/           OPC_EmitMergeInputChains1_0,
/*316*/           OPC_MorphNodeTo, TARGET_VAL(XCore::LDW_3r), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i32, 2/*#Ops*/, 1, 2, 
                  // Src: (ld:i32 (add:i32 GRRegs:i32:$addr, (shl:i32 GRRegs:i32:$offset, 2:i32)))<<P:Predicate_unindexedload>><<P:Predicate_load>> - Complexity = 15
                  // Dst: (LDW_3r:i32 GRRegs:i32:$addr, GRRegs:i32:$offset)
/*325*/         0, /*End of Scope*/
/*326*/       /*Scope*/ 80, /*->407*/
/*327*/         OPC_MoveChild, 0,
/*329*/         OPC_CheckOpcode, TARGET_VAL(ISD::SHL),
/*332*/         OPC_RecordChild0, // #1 = $offset
/*333*/         OPC_MoveChild, 1,
/*335*/         OPC_Scope, 44, /*->381*/ // 2 children in Scope
/*337*/           OPC_CheckInteger, 1, 
/*339*/           OPC_MoveParent,
/*340*/           OPC_MoveParent,
/*341*/           OPC_RecordChild1, // #2 = $addr
/*342*/           OPC_CheckType, MVT::i32,
/*344*/           OPC_MoveParent,
/*345*/           OPC_CheckPredicate, 4, // Predicate_unindexedload
/*347*/           OPC_CheckType, MVT::i32,
/*349*/           OPC_Scope, 14, /*->365*/ // 2 children in Scope
/*351*/             OPC_CheckPredicate, 7, // Predicate_extload
/*353*/             OPC_CheckPredicate, 8, // Predicate_extloadi16
/*355*/             OPC_EmitMergeInputChains1_0,
/*356*/             OPC_MorphNodeTo, TARGET_VAL(XCore::LD16S_3r), 0|OPFL_Chain|OPFL_MemRefs,
                        1/*#VTs*/, MVT::i32, 2/*#Ops*/, 2, 1, 
                    // Src: (ld:i32 (add:i32 (shl:i32 GRRegs:i32:$offset, 1:i32), GRRegs:i32:$addr))<<P:Predicate_unindexedload>><<P:Predicate_extload>><<P:Predicate_extloadi16>> - Complexity = 15
                    // Dst: (LD16S_3r:i32 GRRegs:i32:$addr, GRRegs:i32:$offset)
/*365*/           /*Scope*/ 14, /*->380*/
/*366*/             OPC_CheckPredicate, 5, // Predicate_sextload
/*368*/             OPC_CheckPredicate, 6, // Predicate_sextloadi16
/*370*/             OPC_EmitMergeInputChains1_0,
/*371*/             OPC_MorphNodeTo, TARGET_VAL(XCore::LD16S_3r), 0|OPFL_Chain|OPFL_MemRefs,
                        1/*#VTs*/, MVT::i32, 2/*#Ops*/, 2, 1, 
                    // Src: (ld:i32 (add:i32 (shl:i32 GRRegs:i32:$offset, 1:i32), GRRegs:i32:$addr))<<P:Predicate_unindexedload>><<P:Predicate_sextload>><<P:Predicate_sextloadi16>> - Complexity = 15
                    // Dst: (LD16S_3r:i32 GRRegs:i32:$addr, GRRegs:i32:$offset)
/*380*/           0, /*End of Scope*/
/*381*/         /*Scope*/ 24, /*->406*/
/*382*/           OPC_CheckInteger, 2, 
/*384*/           OPC_MoveParent,
/*385*/           OPC_MoveParent,
/*386*/           OPC_RecordChild1, // #2 = $addr
/*387*/           OPC_CheckType, MVT::i32,
/*389*/           OPC_MoveParent,
/*390*/           OPC_CheckPredicate, 4, // Predicate_unindexedload
/*392*/           OPC_CheckPredicate, 9, // Predicate_load
/*394*/           OPC_CheckType, MVT::i32,
/*396*/           OPC_EmitMergeInputChains1_0,
/*397*/           OPC_MorphNodeTo, TARGET_VAL(XCore::LDW_3r), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i32, 2/*#Ops*/, 2, 1, 
                  // Src: (ld:i32 (add:i32 (shl:i32 GRRegs:i32:$offset, 2:i32), GRRegs:i32:$addr))<<P:Predicate_unindexedload>><<P:Predicate_load>> - Complexity = 15
                  // Dst: (LDW_3r:i32 GRRegs:i32:$addr, GRRegs:i32:$offset)
/*406*/         0, /*End of Scope*/
/*407*/       0, /*End of Scope*/
/*408*/     /*Scope*/ 22, /*->431*/
/*409*/       OPC_RecordChild1, // #1 = $addr
/*410*/       OPC_CheckChild1Type, MVT::i32,
/*412*/       OPC_CheckPredicate, 4, // Predicate_unindexedload
/*414*/       OPC_CheckPredicate, 9, // Predicate_load
/*416*/       OPC_CheckType, MVT::i32,
/*418*/       OPC_CheckComplexPat, /*CP*/0, /*#*/1, // SelectADDRspii:$addr #2 #3
/*421*/       OPC_EmitMergeInputChains1_0,
/*422*/       OPC_MorphNodeTo, TARGET_VAL(XCore::LDWFI), 0|OPFL_Chain|OPFL_MemRefs,
                  1/*#VTs*/, MVT::i32, 2/*#Ops*/, 2, 3, 
              // Src: (ld:i32 ADDRspii:i32:$addr)<<P:Predicate_unindexedload>><<P:Predicate_load>> - Complexity = 13
              // Dst: (LDWFI:i32 ADDRspii:i32:$addr)
/*431*/     /*Scope*/ 8|128,1/*136*/, /*->569*/
/*433*/       OPC_MoveChild, 1,
/*435*/       OPC_SwitchOpcode /*3 cases */, 77,  TARGET_VAL(ISD::ADD),// ->516
/*439*/         OPC_RecordChild0, // #1 = $addr
/*440*/         OPC_RecordChild1, // #2 = $offset
/*441*/         OPC_Scope, 32, /*->475*/ // 2 children in Scope
/*443*/           OPC_MoveChild, 1,
/*445*/           OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*448*/           OPC_CheckPredicate, 1, // Predicate_immUs4
/*450*/           OPC_MoveParent,
/*451*/           OPC_CheckType, MVT::i32,
/*453*/           OPC_MoveParent,
/*454*/           OPC_CheckPredicate, 4, // Predicate_unindexedload
/*456*/           OPC_CheckPredicate, 9, // Predicate_load
/*458*/           OPC_CheckType, MVT::i32,
/*460*/           OPC_EmitMergeInputChains1_0,
/*461*/           OPC_EmitConvertToTarget, 2,
/*463*/           OPC_EmitNodeXForm, 0, 3, // div4_xform
/*466*/           OPC_MorphNodeTo, TARGET_VAL(XCore::LDW_2rus), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i32, 2/*#Ops*/, 1, 4, 
                  // Src: (ld:i32 (add:i32 GRRegs:i32:$addr, (imm:i32)<<P:Predicate_immUs4>>:$offset))<<P:Predicate_unindexedload>><<P:Predicate_load>> - Complexity = 11
                  // Dst: (LDW_2rus:i32 GRRegs:i32:$addr, (div4_xform:i32 (imm:i32)<<P:Predicate_immUs4>>:$offset))
/*475*/         /*Scope*/ 39, /*->515*/
/*476*/           OPC_CheckType, MVT::i32,
/*478*/           OPC_MoveParent,
/*479*/           OPC_CheckPredicate, 4, // Predicate_unindexedload
/*481*/           OPC_CheckType, MVT::i32,
/*483*/           OPC_Scope, 14, /*->499*/ // 2 children in Scope
/*485*/             OPC_CheckPredicate, 10, // Predicate_zextload
/*487*/             OPC_CheckPredicate, 11, // Predicate_zextloadi8
/*489*/             OPC_EmitMergeInputChains1_0,
/*490*/             OPC_MorphNodeTo, TARGET_VAL(XCore::LD8U_3r), 0|OPFL_Chain|OPFL_MemRefs,
                        1/*#VTs*/, MVT::i32, 2/*#Ops*/, 1, 2, 
                    // Src: (ld:i32 (add:i32 GRRegs:i32:$addr, GRRegs:i32:$offset))<<P:Predicate_unindexedload>><<P:Predicate_zextload>><<P:Predicate_zextloadi8>> - Complexity = 7
                    // Dst: (LD8U_3r:i32 GRRegs:i32:$addr, GRRegs:i32:$offset)
/*499*/           /*Scope*/ 14, /*->514*/
/*500*/             OPC_CheckPredicate, 7, // Predicate_extload
/*502*/             OPC_CheckPredicate, 12, // Predicate_extloadi8
/*504*/             OPC_EmitMergeInputChains1_0,
/*505*/             OPC_MorphNodeTo, TARGET_VAL(XCore::LD8U_3r), 0|OPFL_Chain|OPFL_MemRefs,
                        1/*#VTs*/, MVT::i32, 2/*#Ops*/, 1, 2, 
                    // Src: (ld:i32 (add:i32 GRRegs:i32:$addr, GRRegs:i32:$offset))<<P:Predicate_unindexedload>><<P:Predicate_extload>><<P:Predicate_extloadi8>> - Complexity = 7
                    // Dst: (LD8U_3r:i32 GRRegs:i32:$addr, GRRegs:i32:$offset)
/*514*/           0, /*End of Scope*/
/*515*/         0, /*End of Scope*/
/*516*/       /*SwitchOpcode*/ 23,  TARGET_VAL(XCoreISD::DPRelativeWrapper),// ->542
/*519*/         OPC_RecordChild0, // #1 = $b
/*520*/         OPC_MoveChild, 0,
/*522*/         OPC_CheckOpcode, TARGET_VAL(ISD::TargetGlobalAddress),
/*525*/         OPC_MoveParent,
/*526*/         OPC_MoveParent,
/*527*/         OPC_CheckPredicate, 4, // Predicate_unindexedload
/*529*/         OPC_CheckPredicate, 9, // Predicate_load
/*531*/         OPC_CheckType, MVT::i32,
/*533*/         OPC_EmitMergeInputChains1_0,
/*534*/         OPC_MorphNodeTo, TARGET_VAL(XCore::LDWDP_lru6), 0|OPFL_Chain|OPFL_MemRefs,
                    1/*#VTs*/, MVT::i32, 1/*#Ops*/, 1, 
                // Src: (ld:i32 (dprelwrapper:iPTR (tglobaladdr:iPTR):$b))<<P:Predicate_unindexedload>><<P:Predicate_load>> - Complexity = 10
                // Dst: (LDWDP_lru6:i32 (tglobaladdr:i32):$b)
/*542*/       /*SwitchOpcode*/ 23,  TARGET_VAL(XCoreISD::CPRelativeWrapper),// ->568
/*545*/         OPC_RecordChild0, // #1 = $b
/*546*/         OPC_MoveChild, 0,
/*548*/         OPC_CheckOpcode, TARGET_VAL(ISD::TargetGlobalAddress),
/*551*/         OPC_MoveParent,
/*552*/         OPC_MoveParent,
/*553*/         OPC_CheckPredicate, 4, // Predicate_unindexedload
/*555*/         OPC_CheckPredicate, 9, // Predicate_load
/*557*/         OPC_CheckType, MVT::i32,
/*559*/         OPC_EmitMergeInputChains1_0,
/*560*/         OPC_MorphNodeTo, TARGET_VAL(XCore::LDWCP_lru6), 0|OPFL_Chain|OPFL_MemRefs,
                    1/*#VTs*/, MVT::i32, 1/*#Ops*/, 1, 
                // Src: (ld:i32 (cprelwrapper:iPTR (tglobaladdr:iPTR):$b))<<P:Predicate_unindexedload>><<P:Predicate_load>> - Complexity = 10
                // Dst: (LDWCP_lru6:i32 (tglobaladdr:i32):$b)
/*568*/       0, // EndSwitchOpcode
/*569*/     /*Scope*/ 2|128,1/*130*/, /*->701*/
/*571*/       OPC_RecordChild1, // #1 = $addr
/*572*/       OPC_CheckChild1Type, MVT::i32,
/*574*/       OPC_CheckPredicate, 4, // Predicate_unindexedload
/*576*/       OPC_CheckType, MVT::i32,
/*578*/       OPC_Scope, 15, /*->595*/ // 4 children in Scope
/*580*/         OPC_CheckPredicate, 9, // Predicate_load
/*582*/         OPC_EmitMergeInputChains1_0,
/*583*/         OPC_EmitInteger, MVT::i32, 0, 
/*586*/         OPC_MorphNodeTo, TARGET_VAL(XCore::LDW_2rus), 0|OPFL_Chain|OPFL_MemRefs,
                    1/*#VTs*/, MVT::i32, 2/*#Ops*/, 1, 2, 
                // Src: (ld:i32 GRRegs:i32:$addr)<<P:Predicate_unindexedload>><<P:Predicate_load>> - Complexity = 4
                // Dst: (LDW_2rus:i32 GRRegs:i32:$addr, 0:i32)
/*595*/       /*Scope*/ 25, /*->621*/
/*596*/         OPC_CheckPredicate, 10, // Predicate_zextload
/*598*/         OPC_CheckPredicate, 11, // Predicate_zextloadi8
/*600*/         OPC_EmitMergeInputChains1_0,
/*601*/         OPC_EmitInteger, MVT::i32, 0, 
/*604*/         OPC_EmitNode, TARGET_VAL(XCore::LDC_ru6), 0,
                    1/*#VTs*/, MVT::i32, 1/*#Ops*/, 2,  // Results = #3
/*612*/         OPC_MorphNodeTo, TARGET_VAL(XCore::LD8U_3r), 0|OPFL_Chain|OPFL_MemRefs,
                    1/*#VTs*/, MVT::i32, 2/*#Ops*/, 1, 3, 
                // Src: (ld:i32 GRRegs:i32:$addr)<<P:Predicate_unindexedload>><<P:Predicate_zextload>><<P:Predicate_zextloadi8>> - Complexity = 4
                // Dst: (LD8U_3r:i32 GRRegs:i32:$addr, (LDC_ru6:i32 0:i32))
/*621*/       /*Scope*/ 25, /*->647*/
/*622*/         OPC_CheckPredicate, 5, // Predicate_sextload
/*624*/         OPC_CheckPredicate, 6, // Predicate_sextloadi16
/*626*/         OPC_EmitMergeInputChains1_0,
/*627*/         OPC_EmitInteger, MVT::i32, 0, 
/*630*/         OPC_EmitNode, TARGET_VAL(XCore::LDC_ru6), 0,
                    1/*#VTs*/, MVT::i32, 1/*#Ops*/, 2,  // Results = #3
/*638*/         OPC_MorphNodeTo, TARGET_VAL(XCore::LD16S_3r), 0|OPFL_Chain|OPFL_MemRefs,
                    1/*#VTs*/, MVT::i32, 2/*#Ops*/, 1, 3, 
                // Src: (ld:i32 GRRegs:i32:$addr)<<P:Predicate_unindexedload>><<P:Predicate_sextload>><<P:Predicate_sextloadi16>> - Complexity = 4
                // Dst: (LD16S_3r:i32 GRRegs:i32:$addr, (LDC_ru6:i32 0:i32))
/*647*/       /*Scope*/ 52, /*->700*/
/*648*/         OPC_CheckPredicate, 7, // Predicate_extload
/*650*/         OPC_Scope, 23, /*->675*/ // 2 children in Scope
/*652*/           OPC_CheckPredicate, 12, // Predicate_extloadi8
/*654*/           OPC_EmitMergeInputChains1_0,
/*655*/           OPC_EmitInteger, MVT::i32, 0, 
/*658*/           OPC_EmitNode, TARGET_VAL(XCore::LDC_ru6), 0,
                      1/*#VTs*/, MVT::i32, 1/*#Ops*/, 2,  // Results = #3
/*666*/           OPC_MorphNodeTo, TARGET_VAL(XCore::LD8U_3r), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i32, 2/*#Ops*/, 1, 3, 
                  // Src: (ld:i32 GRRegs:i32:$addr)<<P:Predicate_unindexedload>><<P:Predicate_extload>><<P:Predicate_extloadi8>> - Complexity = 4
                  // Dst: (LD8U_3r:i32 GRRegs:i32:$addr, (LDC_ru6:i32 0:i32))
/*675*/         /*Scope*/ 23, /*->699*/
/*676*/           OPC_CheckPredicate, 8, // Predicate_extloadi16
/*678*/           OPC_EmitMergeInputChains1_0,
/*679*/           OPC_EmitInteger, MVT::i32, 0, 
/*682*/           OPC_EmitNode, TARGET_VAL(XCore::LDC_ru6), 0,
                      1/*#VTs*/, MVT::i32, 1/*#Ops*/, 2,  // Results = #3
/*690*/           OPC_MorphNodeTo, TARGET_VAL(XCore::LD16S_3r), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i32, 2/*#Ops*/, 1, 3, 
                  // Src: (ld:i32 GRRegs:i32:$addr)<<P:Predicate_unindexedload>><<P:Predicate_extload>><<P:Predicate_extloadi16>> - Complexity = 4
                  // Dst: (LD16S_3r:i32 GRRegs:i32:$addr, (LDC_ru6:i32 0:i32))
/*699*/         0, /*End of Scope*/
/*700*/       0, /*End of Scope*/
/*701*/     0, /*End of Scope*/
/*702*/   /*SwitchOpcode*/ 61|128,2/*317*/,  TARGET_VAL(ISD::STORE),// ->1023
/*706*/     OPC_RecordMemRef,
/*707*/     OPC_RecordNode,   // #0 = 'st' chained node
/*708*/     OPC_RecordChild1, // #1 = $val
/*709*/     OPC_CheckChild1Type, MVT::i32,
/*711*/     OPC_Scope, 124, /*->837*/ // 4 children in Scope
/*713*/       OPC_MoveChild, 2,
/*715*/       OPC_CheckOpcode, TARGET_VAL(ISD::ADD),
/*718*/       OPC_Scope, 57, /*->777*/ // 2 children in Scope
/*720*/         OPC_RecordChild0, // #2 = $addr
/*721*/         OPC_MoveChild, 1,
/*723*/         OPC_CheckOpcode, TARGET_VAL(ISD::SHL),
/*726*/         OPC_RecordChild0, // #3 = $offset
/*727*/         OPC_MoveChild, 1,
/*729*/         OPC_Scope, 23, /*->754*/ // 2 children in Scope
/*731*/           OPC_CheckInteger, 1, 
/*733*/           OPC_MoveParent,
/*734*/           OPC_MoveParent,
/*735*/           OPC_CheckType, MVT::i32,
/*737*/           OPC_MoveParent,
/*738*/           OPC_CheckPredicate, 13, // Predicate_unindexedstore
/*740*/           OPC_CheckPredicate, 14, // Predicate_truncstore
/*742*/           OPC_CheckPredicate, 15, // Predicate_truncstorei16
/*744*/           OPC_EmitMergeInputChains1_0,
/*745*/           OPC_MorphNodeTo, TARGET_VAL(XCore::ST16_l3r), 0|OPFL_Chain|OPFL_MemRefs,
                      0/*#VTs*/, 3/*#Ops*/, 1, 2, 3, 
                  // Src: (st GRRegs:i32:$val, (add:i32 GRRegs:i32:$addr, (shl:i32 GRRegs:i32:$offset, 1:i32)))<<P:Predicate_unindexedstore>><<P:Predicate_truncstore>><<P:Predicate_truncstorei16>> - Complexity = 15
                  // Dst: (ST16_l3r GRRegs:i32:$val, GRRegs:i32:$addr, GRRegs:i32:$offset)
/*754*/         /*Scope*/ 21, /*->776*/
/*755*/           OPC_CheckInteger, 2, 
/*757*/           OPC_MoveParent,
/*758*/           OPC_MoveParent,
/*759*/           OPC_CheckType, MVT::i32,
/*761*/           OPC_MoveParent,
/*762*/           OPC_CheckPredicate, 13, // Predicate_unindexedstore
/*764*/           OPC_CheckPredicate, 16, // Predicate_store
/*766*/           OPC_EmitMergeInputChains1_0,
/*767*/           OPC_MorphNodeTo, TARGET_VAL(XCore::STW_l3r), 0|OPFL_Chain|OPFL_MemRefs,
                      0/*#VTs*/, 3/*#Ops*/, 1, 2, 3, 
                  // Src: (st GRRegs:i32:$val, (add:i32 GRRegs:i32:$addr, (shl:i32 GRRegs:i32:$offset, 2:i32)))<<P:Predicate_unindexedstore>><<P:Predicate_store>> - Complexity = 15
                  // Dst: (STW_l3r GRRegs:i32:$val, GRRegs:i32:$addr, GRRegs:i32:$offset)
/*776*/         0, /*End of Scope*/
/*777*/       /*Scope*/ 58, /*->836*/
/*778*/         OPC_MoveChild, 0,
/*780*/         OPC_CheckOpcode, TARGET_VAL(ISD::SHL),
/*783*/         OPC_RecordChild0, // #2 = $offset
/*784*/         OPC_MoveChild, 1,
/*786*/         OPC_Scope, 24, /*->812*/ // 2 children in Scope
/*788*/           OPC_CheckInteger, 1, 
/*790*/           OPC_MoveParent,
/*791*/           OPC_MoveParent,
/*792*/           OPC_RecordChild1, // #3 = $addr
/*793*/           OPC_CheckType, MVT::i32,
/*795*/           OPC_MoveParent,
/*796*/           OPC_CheckPredicate, 13, // Predicate_unindexedstore
/*798*/           OPC_CheckPredicate, 14, // Predicate_truncstore
/*800*/           OPC_CheckPredicate, 15, // Predicate_truncstorei16
/*802*/           OPC_EmitMergeInputChains1_0,
/*803*/           OPC_MorphNodeTo, TARGET_VAL(XCore::ST16_l3r), 0|OPFL_Chain|OPFL_MemRefs,
                      0/*#VTs*/, 3/*#Ops*/, 1, 3, 2, 
                  // Src: (st GRRegs:i32:$val, (add:i32 (shl:i32 GRRegs:i32:$offset, 1:i32), GRRegs:i32:$addr))<<P:Predicate_unindexedstore>><<P:Predicate_truncstore>><<P:Predicate_truncstorei16>> - Complexity = 15
                  // Dst: (ST16_l3r GRRegs:i32:$val, GRRegs:i32:$addr, GRRegs:i32:$offset)
/*812*/         /*Scope*/ 22, /*->835*/
/*813*/           OPC_CheckInteger, 2, 
/*815*/           OPC_MoveParent,
/*816*/           OPC_MoveParent,
/*817*/           OPC_RecordChild1, // #3 = $addr
/*818*/           OPC_CheckType, MVT::i32,
/*820*/           OPC_MoveParent,
/*821*/           OPC_CheckPredicate, 13, // Predicate_unindexedstore
/*823*/           OPC_CheckPredicate, 16, // Predicate_store
/*825*/           OPC_EmitMergeInputChains1_0,
/*826*/           OPC_MorphNodeTo, TARGET_VAL(XCore::STW_l3r), 0|OPFL_Chain|OPFL_MemRefs,
                      0/*#VTs*/, 3/*#Ops*/, 1, 3, 2, 
                  // Src: (st GRRegs:i32:$val, (add:i32 (shl:i32 GRRegs:i32:$offset, 2:i32), GRRegs:i32:$addr))<<P:Predicate_unindexedstore>><<P:Predicate_store>> - Complexity = 15
                  // Dst: (STW_l3r GRRegs:i32:$val, GRRegs:i32:$addr, GRRegs:i32:$offset)
/*835*/         0, /*End of Scope*/
/*836*/       0, /*End of Scope*/
/*837*/     /*Scope*/ 20, /*->858*/
/*838*/       OPC_RecordChild2, // #2 = $addr
/*839*/       OPC_CheckChild2Type, MVT::i32,
/*841*/       OPC_CheckPredicate, 13, // Predicate_unindexedstore
/*843*/       OPC_CheckPredicate, 16, // Predicate_store
/*845*/       OPC_CheckComplexPat, /*CP*/0, /*#*/2, // SelectADDRspii:$addr #3 #4
/*848*/       OPC_EmitMergeInputChains1_0,
/*849*/       OPC_MorphNodeTo, TARGET_VAL(XCore::STWFI), 0|OPFL_Chain|OPFL_MemRefs,
                  0/*#VTs*/, 3/*#Ops*/, 1, 3, 4, 
              // Src: (st GRRegs:i32:$src, ADDRspii:i32:$addr)<<P:Predicate_unindexedstore>><<P:Predicate_store>> - Complexity = 13
              // Dst: (STWFI GRRegs:i32:$src, ADDRspii:i32:$addr)
/*858*/     /*Scope*/ 86, /*->945*/
/*859*/       OPC_MoveChild, 2,
/*861*/       OPC_SwitchOpcode /*2 cases */, 55,  TARGET_VAL(ISD::ADD),// ->920
/*865*/         OPC_RecordChild0, // #2 = $addr
/*866*/         OPC_RecordChild1, // #3 = $offset
/*867*/         OPC_Scope, 30, /*->899*/ // 2 children in Scope
/*869*/           OPC_MoveChild, 1,
/*871*/           OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*874*/           OPC_CheckPredicate, 1, // Predicate_immUs4
/*876*/           OPC_MoveParent,
/*877*/           OPC_CheckType, MVT::i32,
/*879*/           OPC_MoveParent,
/*880*/           OPC_CheckPredicate, 13, // Predicate_unindexedstore
/*882*/           OPC_CheckPredicate, 16, // Predicate_store
/*884*/           OPC_EmitMergeInputChains1_0,
/*885*/           OPC_EmitConvertToTarget, 3,
/*887*/           OPC_EmitNodeXForm, 0, 4, // div4_xform
/*890*/           OPC_MorphNodeTo, TARGET_VAL(XCore::STW_2rus), 0|OPFL_Chain|OPFL_MemRefs,
                      0/*#VTs*/, 3/*#Ops*/, 1, 2, 5, 
                  // Src: (st GRRegs:i32:$val, (add:i32 GRRegs:i32:$addr, (imm:i32)<<P:Predicate_immUs4>>:$offset))<<P:Predicate_unindexedstore>><<P:Predicate_store>> - Complexity = 11
                  // Dst: (STW_2rus GRRegs:i32:$val, GRRegs:i32:$addr, (div4_xform:i32 (imm:i32)<<P:Predicate_immUs4>>:$offset))
/*899*/         /*Scope*/ 19, /*->919*/
/*900*/           OPC_CheckType, MVT::i32,
/*902*/           OPC_MoveParent,
/*903*/           OPC_CheckPredicate, 13, // Predicate_unindexedstore
/*905*/           OPC_CheckPredicate, 14, // Predicate_truncstore
/*907*/           OPC_CheckPredicate, 17, // Predicate_truncstorei8
/*909*/           OPC_EmitMergeInputChains1_0,
/*910*/           OPC_MorphNodeTo, TARGET_VAL(XCore::ST8_l3r), 0|OPFL_Chain|OPFL_MemRefs,
                      0/*#VTs*/, 3/*#Ops*/, 1, 2, 3, 
                  // Src: (st GRRegs:i32:$val, (add:i32 GRRegs:i32:$addr, GRRegs:i32:$offset))<<P:Predicate_unindexedstore>><<P:Predicate_truncstore>><<P:Predicate_truncstorei8>> - Complexity = 7
                  // Dst: (ST8_l3r GRRegs:i32:$val, GRRegs:i32:$addr, GRRegs:i32:$offset)
/*919*/         0, /*End of Scope*/
/*920*/       /*SwitchOpcode*/ 21,  TARGET_VAL(XCoreISD::DPRelativeWrapper),// ->944
/*923*/         OPC_RecordChild0, // #2 = $b
/*924*/         OPC_MoveChild, 0,
/*926*/         OPC_CheckOpcode, TARGET_VAL(ISD::TargetGlobalAddress),
/*929*/         OPC_MoveParent,
/*930*/         OPC_MoveParent,
/*931*/         OPC_CheckPredicate, 13, // Predicate_unindexedstore
/*933*/         OPC_CheckPredicate, 16, // Predicate_store
/*935*/         OPC_EmitMergeInputChains1_0,
/*936*/         OPC_MorphNodeTo, TARGET_VAL(XCore::STWDP_lru6), 0|OPFL_Chain|OPFL_MemRefs,
                    0/*#VTs*/, 2/*#Ops*/, 1, 2, 
                // Src: (st RRegs:i32:$a, (dprelwrapper:iPTR (tglobaladdr:iPTR):$b))<<P:Predicate_unindexedstore>><<P:Predicate_store>> - Complexity = 10
                // Dst: (STWDP_lru6 RRegs:i32:$a, (tglobaladdr:i32):$b)
/*944*/       0, // EndSwitchOpcode
/*945*/     /*Scope*/ 76, /*->1022*/
/*946*/       OPC_RecordChild2, // #2 = $addr
/*947*/       OPC_CheckChild2Type, MVT::i32,
/*949*/       OPC_CheckPredicate, 13, // Predicate_unindexedstore
/*951*/       OPC_Scope, 15, /*->968*/ // 2 children in Scope
/*953*/         OPC_CheckPredicate, 16, // Predicate_store
/*955*/         OPC_EmitMergeInputChains1_0,
/*956*/         OPC_EmitInteger, MVT::i32, 0, 
/*959*/         OPC_MorphNodeTo, TARGET_VAL(XCore::STW_2rus), 0|OPFL_Chain|OPFL_MemRefs,
                    0/*#VTs*/, 3/*#Ops*/, 1, 2, 3, 
                // Src: (st GRRegs:i32:$val, GRRegs:i32:$addr)<<P:Predicate_unindexedstore>><<P:Predicate_store>> - Complexity = 4
                // Dst: (STW_2rus GRRegs:i32:$val, GRRegs:i32:$addr, 0:i32)
/*968*/       /*Scope*/ 52, /*->1021*/
/*969*/         OPC_CheckPredicate, 14, // Predicate_truncstore
/*971*/         OPC_Scope, 23, /*->996*/ // 2 children in Scope
/*973*/           OPC_CheckPredicate, 17, // Predicate_truncstorei8
/*975*/           OPC_EmitMergeInputChains1_0,
/*976*/           OPC_EmitInteger, MVT::i32, 0, 
/*979*/           OPC_EmitNode, TARGET_VAL(XCore::LDC_ru6), 0,
                      1/*#VTs*/, MVT::i32, 1/*#Ops*/, 3,  // Results = #4
/*987*/           OPC_MorphNodeTo, TARGET_VAL(XCore::ST8_l3r), 0|OPFL_Chain|OPFL_MemRefs,
                      0/*#VTs*/, 3/*#Ops*/, 1, 2, 4, 
                  // Src: (st GRRegs:i32:$val, GRRegs:i32:$addr)<<P:Predicate_unindexedstore>><<P:Predicate_truncstore>><<P:Predicate_truncstorei8>> - Complexity = 4
                  // Dst: (ST8_l3r GRRegs:i32:$val, GRRegs:i32:$addr, (LDC_ru6:i32 0:i32))
/*996*/         /*Scope*/ 23, /*->1020*/
/*997*/           OPC_CheckPredicate, 15, // Predicate_truncstorei16
/*999*/           OPC_EmitMergeInputChains1_0,
/*1000*/          OPC_EmitInteger, MVT::i32, 0, 
/*1003*/          OPC_EmitNode, TARGET_VAL(XCore::LDC_ru6), 0,
                      1/*#VTs*/, MVT::i32, 1/*#Ops*/, 3,  // Results = #4
/*1011*/          OPC_MorphNodeTo, TARGET_VAL(XCore::ST16_l3r), 0|OPFL_Chain|OPFL_MemRefs,
                      0/*#VTs*/, 3/*#Ops*/, 1, 2, 4, 
                  // Src: (st GRRegs:i32:$val, GRRegs:i32:$addr)<<P:Predicate_unindexedstore>><<P:Predicate_truncstore>><<P:Predicate_truncstorei16>> - Complexity = 4
                  // Dst: (ST16_l3r GRRegs:i32:$val, GRRegs:i32:$addr, (LDC_ru6:i32 0:i32))
/*1020*/        0, /*End of Scope*/
/*1021*/      0, /*End of Scope*/
/*1022*/    0, /*End of Scope*/
/*1023*/  /*SwitchOpcode*/ 91,  TARGET_VAL(ISD::SRA),// ->1117
/*1026*/    OPC_Scope, 32, /*->1060*/ // 2 children in Scope
/*1028*/      OPC_MoveChild, 0,
/*1030*/      OPC_CheckOpcode, TARGET_VAL(ISD::SHL),
/*1033*/      OPC_RecordChild0, // #0 = $src
/*1034*/      OPC_RecordChild1, // #1 = $imm
/*1035*/      OPC_MoveChild, 1,
/*1037*/      OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*1040*/      OPC_CheckPredicate, 18, // Predicate_immBpwSubBitp
/*1042*/      OPC_MoveParent,
/*1043*/      OPC_MoveParent,
/*1044*/      OPC_CheckChild1Same, 1,
/*1046*/      OPC_EmitConvertToTarget, 1,
/*1048*/      OPC_EmitNodeXForm, 3, 2, // bpwsub_xform
/*1051*/      OPC_MorphNodeTo, TARGET_VAL(XCore::SEXT_rus), 0,
                  1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 3, 
              // Src: (sra:i32 (shl:i32 GRRegs:i32:$src, (imm:i32)<<P:Predicate_immBpwSubBitp>>:$imm), (imm:i32)<<P:Predicate_immBpwSubBitp>>:$imm) - Complexity = 14
              // Dst: (SEXT_rus:i32 GRRegs:i32:$src, (bpwsub_xform:i32 (imm:i32)<<P:Predicate_immBpwSubBitp>>:$imm))
/*1060*/    /*Scope*/ 55, /*->1116*/
/*1061*/      OPC_RecordChild0, // #0 = $src
/*1062*/      OPC_Scope, 17, /*->1081*/ // 2 children in Scope
/*1064*/        OPC_MoveChild, 1,
/*1066*/        OPC_CheckInteger, 31, 
/*1068*/        OPC_MoveParent,
/*1069*/        OPC_EmitInteger, MVT::i32, 32, 
/*1072*/        OPC_MorphNodeTo, TARGET_VAL(XCore::ASHR_l2rus), 0,
                    1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1, 
                // Src: (sra:i32 GRRegs:i32:$src, 31:i32) - Complexity = 8
                // Dst: (ASHR_l2rus:i32 GRRegs:i32:$src, 32:i32)
/*1081*/      /*Scope*/ 33, /*->1115*/
/*1082*/        OPC_RecordChild1, // #1 = $c
/*1083*/        OPC_Scope, 19, /*->1104*/ // 2 children in Scope
/*1085*/          OPC_MoveChild, 1,
/*1087*/          OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*1090*/          OPC_CheckPredicate, 19, // Predicate_immBitp
/*1092*/          OPC_MoveParent,
/*1093*/          OPC_EmitConvertToTarget, 1,
/*1095*/          OPC_MorphNodeTo, TARGET_VAL(XCore::ASHR_l2rus), 0,
                      1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 2, 
                  // Src: (sra:i32 GRRegs:i32:$b, (imm:i32)<<P:Predicate_immBitp>>:$c) - Complexity = 7
                  // Dst: (ASHR_l2rus:i32 GRRegs:i32:$b, (imm:i32):$c)
/*1104*/        /*Scope*/ 9, /*->1114*/
/*1105*/          OPC_MorphNodeTo, TARGET_VAL(XCore::ASHR_l3r), 0,
                      1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1, 
                  // Src: (sra:i32 GRRegs:i32:$b, GRRegs:i32:$c) - Complexity = 3
                  // Dst: (ASHR_l3r:i32 GRRegs:i32:$b, GRRegs:i32:$c)
/*1114*/        0, /*End of Scope*/
/*1115*/      0, /*End of Scope*/
/*1116*/    0, /*End of Scope*/
/*1117*/  /*SwitchOpcode*/ 0|128,5/*640*/,  TARGET_VAL(ISD::INTRINSIC_VOID),// ->1761
/*1121*/    OPC_RecordNode,   // #0 = 'intrinsic_void' chained node
/*1122*/    OPC_MoveChild, 1,
/*1124*/    OPC_Scope, 58, /*->1184*/ // 28 children in Scope
/*1126*/      OPC_CheckInteger, 63|128,25/*3263*/, 
/*1129*/      OPC_MoveParent,
/*1130*/      OPC_RecordChild2, // #1 = $a
/*1131*/      OPC_CheckChild2Type, MVT::i32,
/*1133*/      OPC_RecordChild3, // #2 = $b
/*1134*/      OPC_Scope, 37, /*->1173*/ // 2 children in Scope
/*1136*/        OPC_MoveChild, 3,
/*1138*/        OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*1141*/        OPC_Scope, 14, /*->1157*/ // 2 children in Scope
/*1143*/          OPC_CheckPredicate, 20, // Predicate_immU6
/*1145*/          OPC_MoveParent,
/*1146*/          OPC_EmitMergeInputChains1_0,
/*1147*/          OPC_EmitConvertToTarget, 2,
/*1149*/          OPC_MorphNodeTo, TARGET_VAL(XCore::SETC_ru6), 0|OPFL_Chain,
                      0/*#VTs*/, 2/*#Ops*/, 1, 3, 
                  // Src: (intrinsic_void 3263:iPTR, GRRegs:i32:$a, (imm:i32)<<P:Predicate_immU6>>:$b) - Complexity = 12
                  // Dst: (SETC_ru6 GRRegs:i32:$a, (imm:i32):$b)
/*1157*/        /*Scope*/ 14, /*->1172*/
/*1158*/          OPC_CheckPredicate, 21, // Predicate_immU16
/*1160*/          OPC_MoveParent,
/*1161*/          OPC_EmitMergeInputChains1_0,
/*1162*/          OPC_EmitConvertToTarget, 2,
/*1164*/          OPC_MorphNodeTo, TARGET_VAL(XCore::SETC_lru6), 0|OPFL_Chain,
                      0/*#VTs*/, 2/*#Ops*/, 1, 3, 
                  // Src: (intrinsic_void 3263:iPTR, GRRegs:i32:$a, (imm:i32)<<P:Predicate_immU16>>:$b) - Complexity = 12
                  // Dst: (SETC_lru6 GRRegs:i32:$a, (imm:i32):$b)
/*1172*/        0, /*End of Scope*/
/*1173*/      /*Scope*/ 9, /*->1183*/
/*1174*/        OPC_EmitMergeInputChains1_0,
/*1175*/        OPC_MorphNodeTo, TARGET_VAL(XCore::SETC_l2r), 0|OPFL_Chain,
                    0/*#VTs*/, 2/*#Ops*/, 1, 2, 
                // Src: (intrinsic_void 3263:iPTR, GRRegs:i32:$r, GRRegs:i32:$val) - Complexity = 8
                // Dst: (SETC_l2r GRRegs:i32:$r, GRRegs:i32:$val)
/*1183*/      0, /*End of Scope*/
/*1184*/    /*Scope*/ 40, /*->1225*/
/*1185*/      OPC_CheckInteger, 71|128,25/*3271*/, 
/*1188*/      OPC_MoveParent,
/*1189*/      OPC_RecordChild2, // #1 = $a
/*1190*/      OPC_MoveChild, 2,
/*1192*/      OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*1195*/      OPC_Scope, 13, /*->1210*/ // 2 children in Scope
/*1197*/        OPC_CheckPredicate, 20, // Predicate_immU6
/*1199*/        OPC_MoveParent,
/*1200*/        OPC_EmitMergeInputChains1_0,
/*1201*/        OPC_EmitConvertToTarget, 1,
/*1203*/        OPC_MorphNodeTo, TARGET_VAL(XCore::SETSR_u6), 0|OPFL_Chain,
                    0/*#VTs*/, 1/*#Ops*/, 2, 
                // Src: (intrinsic_void 3271:iPTR, (imm:i32)<<P:Predicate_immU6>>:$a) - Complexity = 12
                // Dst: (SETSR_u6 (imm:i32):$a)
/*1210*/      /*Scope*/ 13, /*->1224*/
/*1211*/        OPC_CheckPredicate, 21, // Predicate_immU16
/*1213*/        OPC_MoveParent,
/*1214*/        OPC_EmitMergeInputChains1_0,
/*1215*/        OPC_EmitConvertToTarget, 1,
/*1217*/        OPC_MorphNodeTo, TARGET_VAL(XCore::SETSR_lu6), 0|OPFL_Chain,
                    0/*#VTs*/, 1/*#Ops*/, 2, 
                // Src: (intrinsic_void 3271:iPTR, (imm:i32)<<P:Predicate_immU16>>:$a) - Complexity = 12
                // Dst: (SETSR_lu6 (imm:i32):$a)
/*1224*/      0, /*End of Scope*/
/*1225*/    /*Scope*/ 40, /*->1266*/
/*1226*/      OPC_CheckInteger, 34|128,25/*3234*/, 
/*1229*/      OPC_MoveParent,
/*1230*/      OPC_RecordChild2, // #1 = $a
/*1231*/      OPC_MoveChild, 2,
/*1233*/      OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*1236*/      OPC_Scope, 13, /*->1251*/ // 2 children in Scope
/*1238*/        OPC_CheckPredicate, 20, // Predicate_immU6
/*1240*/        OPC_MoveParent,
/*1241*/        OPC_EmitMergeInputChains1_0,
/*1242*/        OPC_EmitConvertToTarget, 1,
/*1244*/        OPC_MorphNodeTo, TARGET_VAL(XCore::CLRSR_u6), 0|OPFL_Chain,
                    0/*#VTs*/, 1/*#Ops*/, 2, 
                // Src: (intrinsic_void 3234:iPTR, (imm:i32)<<P:Predicate_immU6>>:$a) - Complexity = 12
                // Dst: (CLRSR_u6 (imm:i32):$a)
/*1251*/      /*Scope*/ 13, /*->1265*/
/*1252*/        OPC_CheckPredicate, 21, // Predicate_immU16
/*1254*/        OPC_MoveParent,
/*1255*/        OPC_EmitMergeInputChains1_0,
/*1256*/        OPC_EmitConvertToTarget, 1,
/*1258*/        OPC_MorphNodeTo, TARGET_VAL(XCore::CLRSR_lu6), 0|OPFL_Chain,
                    0/*#VTs*/, 1/*#Ops*/, 2, 
                // Src: (intrinsic_void 3234:iPTR, (imm:i32)<<P:Predicate_immU16>>:$a) - Complexity = 12
                // Dst: (CLRSR_lu6 (imm:i32):$a)
/*1265*/      0, /*End of Scope*/
/*1266*/    /*Scope*/ 40, /*->1307*/
/*1267*/      OPC_CheckInteger, 59|128,25/*3259*/, 
/*1270*/      OPC_MoveParent,
/*1271*/      OPC_RecordChild2, // #1 = $r
/*1272*/      OPC_CheckChild2Type, MVT::i32,
/*1274*/      OPC_RecordChild3, // #2 = $val
/*1275*/      OPC_Scope, 19, /*->1296*/ // 2 children in Scope
/*1277*/        OPC_MoveChild, 3,
/*1279*/        OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*1282*/        OPC_CheckPredicate, 0, // Predicate_immUs
/*1284*/        OPC_MoveParent,
/*1285*/        OPC_EmitMergeInputChains1_0,
/*1286*/        OPC_EmitConvertToTarget, 2,
/*1288*/        OPC_MorphNodeTo, TARGET_VAL(XCore::OUTCT_rus), 0|OPFL_Chain,
                    0/*#VTs*/, 2/*#Ops*/, 1, 3, 
                // Src: (intrinsic_void 3259:iPTR, GRRegs:i32:$r, (imm:i32)<<P:Predicate_immUs>>:$val) - Complexity = 12
                // Dst: (OUTCT_rus GRRegs:i32:$r, (imm:i32):$val)
/*1296*/      /*Scope*/ 9, /*->1306*/
/*1297*/        OPC_EmitMergeInputChains1_0,
/*1298*/        OPC_MorphNodeTo, TARGET_VAL(XCore::OUTCT_2r), 0|OPFL_Chain,
                    0/*#VTs*/, 2/*#Ops*/, 1, 2, 
                // Src: (intrinsic_void 3259:iPTR, GRRegs:i32:$r, GRRegs:i32:$val) - Complexity = 8
                // Dst: (OUTCT_2r GRRegs:i32:$r, GRRegs:i32:$val)
/*1306*/      0, /*End of Scope*/
/*1307*/    /*Scope*/ 40, /*->1348*/
/*1308*/      OPC_CheckInteger, 32|128,25/*3232*/, 
/*1311*/      OPC_MoveParent,
/*1312*/      OPC_RecordChild2, // #1 = $r
/*1313*/      OPC_CheckChild2Type, MVT::i32,
/*1315*/      OPC_RecordChild3, // #2 = $val
/*1316*/      OPC_Scope, 19, /*->1337*/ // 2 children in Scope
/*1318*/        OPC_MoveChild, 3,
/*1320*/        OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*1323*/        OPC_CheckPredicate, 0, // Predicate_immUs
/*1325*/        OPC_MoveParent,
/*1326*/        OPC_EmitMergeInputChains1_0,
/*1327*/        OPC_EmitConvertToTarget, 2,
/*1329*/        OPC_MorphNodeTo, TARGET_VAL(XCore::CHKCT_rus), 0|OPFL_Chain,
                    0/*#VTs*/, 2/*#Ops*/, 1, 3, 
                // Src: (intrinsic_void 3232:iPTR, GRRegs:i32:$r, (imm:i32)<<P:Predicate_immUs>>:$val) - Complexity = 12
                // Dst: (CHKCT_rus GRRegs:i32:$r, (imm:i32):$val)
/*1337*/      /*Scope*/ 9, /*->1347*/
/*1338*/        OPC_EmitMergeInputChains1_0,
/*1339*/        OPC_MorphNodeTo, TARGET_VAL(XCore::CHKCT_2r), 0|OPFL_Chain,
                    0/*#VTs*/, 2/*#Ops*/, 1, 2, 
                // Src: (intrinsic_void 3232:iPTR, GRRegs:i32:$r, GRRegs:i32:$val) - Complexity = 8
                // Dst: (CHKCT_2r GRRegs:i32:$r, GRRegs:i32:$val)
/*1347*/      0, /*End of Scope*/
/*1348*/    /*Scope*/ 17, /*->1366*/
/*1349*/      OPC_CheckInteger, 69|128,25/*3269*/, 
/*1352*/      OPC_MoveParent,
/*1353*/      OPC_RecordChild2, // #1 = $r
/*1354*/      OPC_CheckChild2Type, MVT::i32,
/*1356*/      OPC_RecordChild3, // #2 = $val
/*1357*/      OPC_EmitMergeInputChains1_0,
/*1358*/      OPC_MorphNodeTo, TARGET_VAL(XCore::SETPT_2r), 0|OPFL_Chain,
                  0/*#VTs*/, 2/*#Ops*/, 1, 2, 
              // Src: (intrinsic_void 3269:iPTR, GRRegs:i32:$r, GRRegs:i32:$val) - Complexity = 8
              // Dst: (SETPT_2r GRRegs:i32:$r, GRRegs:i32:$val)
/*1366*/    /*Scope*/ 17, /*->1384*/
/*1367*/      OPC_CheckInteger, 61|128,25/*3261*/, 
/*1370*/      OPC_MoveParent,
/*1371*/      OPC_RecordChild2, // #1 = $r
/*1372*/      OPC_CheckChild2Type, MVT::i32,
/*1374*/      OPC_RecordChild3, // #2 = $val
/*1375*/      OPC_EmitMergeInputChains1_0,
/*1376*/      OPC_MorphNodeTo, TARGET_VAL(XCore::OUTT_2r), 0|OPFL_Chain,
                  0/*#VTs*/, 2/*#Ops*/, 1, 2, 
              // Src: (intrinsic_void 3261:iPTR, GRRegs:i32:$r, GRRegs:i32:$val) - Complexity = 8
              // Dst: (OUTT_2r GRRegs:i32:$r, GRRegs:i32:$val)
/*1384*/    /*Scope*/ 17, /*->1402*/
/*1385*/      OPC_CheckInteger, 58|128,25/*3258*/, 
/*1388*/      OPC_MoveParent,
/*1389*/      OPC_RecordChild2, // #1 = $r
/*1390*/      OPC_CheckChild2Type, MVT::i32,
/*1392*/      OPC_RecordChild3, // #2 = $val
/*1393*/      OPC_EmitMergeInputChains1_0,
/*1394*/      OPC_MorphNodeTo, TARGET_VAL(XCore::OUT_2r), 0|OPFL_Chain,
                  0/*#VTs*/, 2/*#Ops*/, 1, 2, 
              // Src: (intrinsic_void 3258:iPTR, GRRegs:i32:$r, GRRegs:i32:$val) - Complexity = 8
              // Dst: (OUT_2r GRRegs:i32:$r, GRRegs:i32:$val)
/*1402*/    /*Scope*/ 17, /*->1420*/
/*1403*/      OPC_CheckInteger, 65|128,25/*3265*/, 
/*1406*/      OPC_MoveParent,
/*1407*/      OPC_RecordChild2, // #1 = $r
/*1408*/      OPC_CheckChild2Type, MVT::i32,
/*1410*/      OPC_RecordChild3, // #2 = $val
/*1411*/      OPC_EmitMergeInputChains1_0,
/*1412*/      OPC_MorphNodeTo, TARGET_VAL(XCore::SETD_2r), 0|OPFL_Chain,
                  0/*#VTs*/, 2/*#Ops*/, 1, 2, 
              // Src: (intrinsic_void 3265:iPTR, GRRegs:i32:$r, GRRegs:i32:$val) - Complexity = 8
              // Dst: (SETD_2r GRRegs:i32:$r, GRRegs:i32:$val)
/*1420*/    /*Scope*/ 17, /*->1438*/
/*1421*/      OPC_CheckInteger, 68|128,25/*3268*/, 
/*1424*/      OPC_MoveParent,
/*1425*/      OPC_RecordChild2, // #1 = $src1
/*1426*/      OPC_CheckChild2Type, MVT::i32,
/*1428*/      OPC_RecordChild3, // #2 = $src2
/*1429*/      OPC_EmitMergeInputChains1_0,
/*1430*/      OPC_MorphNodeTo, TARGET_VAL(XCore::SETPSC_2r), 0|OPFL_Chain,
                  0/*#VTs*/, 2/*#Ops*/, 1, 2, 
              // Src: (intrinsic_void 3268:iPTR, GRRegs:i32:$src1, GRRegs:i32:$src2) - Complexity = 8
              // Dst: (SETPSC_2r GRRegs:i32:$src1, GRRegs:i32:$src2)
/*1438*/    /*Scope*/ 19, /*->1458*/
/*1439*/      OPC_CheckInteger, 53|128,25/*3253*/, 
/*1442*/      OPC_MoveParent,
/*1443*/      OPC_RecordChild2, // #1 = $t
/*1444*/      OPC_CheckChild2Type, MVT::i32,
/*1446*/      OPC_RecordChild3, // #2 = $src
/*1447*/      OPC_CheckChild3Type, MVT::i32,
/*1449*/      OPC_EmitMergeInputChains1_0,
/*1450*/      OPC_MorphNodeTo, TARGET_VAL(XCore::INITSP_2r), 0|OPFL_Chain,
                  0/*#VTs*/, 2/*#Ops*/, 2, 1, 
              // Src: (intrinsic_void 3253:iPTR, GRRegs:i32:$t, GRRegs:i32:$src) - Complexity = 8
              // Dst: (INITSP_2r GRRegs:i32:$src, GRRegs:i32:$t)
/*1458*/    /*Scope*/ 19, /*->1478*/
/*1459*/      OPC_CheckInteger, 52|128,25/*3252*/, 
/*1462*/      OPC_MoveParent,
/*1463*/      OPC_RecordChild2, // #1 = $t
/*1464*/      OPC_CheckChild2Type, MVT::i32,
/*1466*/      OPC_RecordChild3, // #2 = $src
/*1467*/      OPC_CheckChild3Type, MVT::i32,
/*1469*/      OPC_EmitMergeInputChains1_0,
/*1470*/      OPC_MorphNodeTo, TARGET_VAL(XCore::INITPC_2r), 0|OPFL_Chain,
                  0/*#VTs*/, 2/*#Ops*/, 2, 1, 
              // Src: (intrinsic_void 3252:iPTR, GRRegs:i32:$t, GRRegs:i32:$src) - Complexity = 8
              // Dst: (INITPC_2r GRRegs:i32:$src, GRRegs:i32:$t)
/*1478*/    /*Scope*/ 19, /*->1498*/
/*1479*/      OPC_CheckInteger, 49|128,25/*3249*/, 
/*1482*/      OPC_MoveParent,
/*1483*/      OPC_RecordChild2, // #1 = $t
/*1484*/      OPC_CheckChild2Type, MVT::i32,
/*1486*/      OPC_RecordChild3, // #2 = $src
/*1487*/      OPC_CheckChild3Type, MVT::i32,
/*1489*/      OPC_EmitMergeInputChains1_0,
/*1490*/      OPC_MorphNodeTo, TARGET_VAL(XCore::INITCP_2r), 0|OPFL_Chain,
                  0/*#VTs*/, 2/*#Ops*/, 2, 1, 
              // Src: (intrinsic_void 3249:iPTR, GRRegs:i32:$t, GRRegs:i32:$src) - Complexity = 8
              // Dst: (INITCP_2r GRRegs:i32:$src, GRRegs:i32:$t)
/*1498*/    /*Scope*/ 19, /*->1518*/
/*1499*/      OPC_CheckInteger, 50|128,25/*3250*/, 
/*1502*/      OPC_MoveParent,
/*1503*/      OPC_RecordChild2, // #1 = $t
/*1504*/      OPC_CheckChild2Type, MVT::i32,
/*1506*/      OPC_RecordChild3, // #2 = $src
/*1507*/      OPC_CheckChild3Type, MVT::i32,
/*1509*/      OPC_EmitMergeInputChains1_0,
/*1510*/      OPC_MorphNodeTo, TARGET_VAL(XCore::INITDP_2r), 0|OPFL_Chain,
                  0/*#VTs*/, 2/*#Ops*/, 2, 1, 
              // Src: (intrinsic_void 3250:iPTR, GRRegs:i32:$t, GRRegs:i32:$src) - Complexity = 8
              // Dst: (INITDP_2r GRRegs:i32:$src, GRRegs:i32:$t)
/*1518*/    /*Scope*/ 17, /*->1536*/
/*1519*/      OPC_CheckInteger, 72|128,25/*3272*/, 
/*1522*/      OPC_MoveParent,
/*1523*/      OPC_RecordChild2, // #1 = $r
/*1524*/      OPC_CheckChild2Type, MVT::i32,
/*1526*/      OPC_RecordChild3, // #2 = $val
/*1527*/      OPC_EmitMergeInputChains1_0,
/*1528*/      OPC_MorphNodeTo, TARGET_VAL(XCore::SETTW_l2r), 0|OPFL_Chain,
                  0/*#VTs*/, 2/*#Ops*/, 1, 2, 
              // Src: (intrinsic_void 3272:iPTR, GRRegs:i32:$r, GRRegs:i32:$val) - Complexity = 8
              // Dst: (SETTW_l2r GRRegs:i32:$r, GRRegs:i32:$val)
/*1536*/    /*Scope*/ 15, /*->1552*/
/*1537*/      OPC_CheckInteger, 67|128,25/*3267*/, 
/*1540*/      OPC_MoveParent,
/*1541*/      OPC_RecordChild2, // #1 = $src1
/*1542*/      OPC_RecordChild3, // #2 = $src2
/*1543*/      OPC_EmitMergeInputChains1_0,
/*1544*/      OPC_MorphNodeTo, TARGET_VAL(XCore::SETPS_l2r), 0|OPFL_Chain,
                  0/*#VTs*/, 2/*#Ops*/, 1, 2, 
              // Src: (intrinsic_void 3267:iPTR, GRRegs:i32:$src1, GRRegs:i32:$src2) - Complexity = 8
              // Dst: (SETPS_l2r GRRegs:i32:$src1, GRRegs:i32:$src2)
/*1552*/    /*Scope*/ 19, /*->1572*/
/*1553*/      OPC_CheckInteger, 51|128,25/*3251*/, 
/*1556*/      OPC_MoveParent,
/*1557*/      OPC_RecordChild2, // #1 = $t
/*1558*/      OPC_CheckChild2Type, MVT::i32,
/*1560*/      OPC_RecordChild3, // #2 = $src
/*1561*/      OPC_CheckChild3Type, MVT::i32,
/*1563*/      OPC_EmitMergeInputChains1_0,
/*1564*/      OPC_MorphNodeTo, TARGET_VAL(XCore::INITLR_l2r), 0|OPFL_Chain,
                  0/*#VTs*/, 2/*#Ops*/, 2, 1, 
              // Src: (intrinsic_void 3251:iPTR, GRRegs:i32:$t, GRRegs:i32:$src) - Complexity = 8
              // Dst: (INITLR_l2r GRRegs:i32:$src, GRRegs:i32:$t)
/*1572*/    /*Scope*/ 19, /*->1592*/
/*1573*/      OPC_CheckInteger, 64|128,25/*3264*/, 
/*1576*/      OPC_MoveParent,
/*1577*/      OPC_RecordChild2, // #1 = $src1
/*1578*/      OPC_CheckChild2Type, MVT::i32,
/*1580*/      OPC_RecordChild3, // #2 = $src2
/*1581*/      OPC_CheckChild3Type, MVT::i32,
/*1583*/      OPC_EmitMergeInputChains1_0,
/*1584*/      OPC_MorphNodeTo, TARGET_VAL(XCore::SETCLK_l2r), 0|OPFL_Chain,
                  0/*#VTs*/, 2/*#Ops*/, 1, 2, 
              // Src: (intrinsic_void 3264:iPTR, GRRegs:i32:$src1, GRRegs:i32:$src2) - Complexity = 8
              // Dst: (SETCLK_l2r GRRegs:i32:$src1, GRRegs:i32:$src2)
/*1592*/    /*Scope*/ 19, /*->1612*/
/*1593*/      OPC_CheckInteger, 70|128,25/*3270*/, 
/*1596*/      OPC_MoveParent,
/*1597*/      OPC_RecordChild2, // #1 = $src1
/*1598*/      OPC_CheckChild2Type, MVT::i32,
/*1600*/      OPC_RecordChild3, // #2 = $src2
/*1601*/      OPC_CheckChild3Type, MVT::i32,
/*1603*/      OPC_EmitMergeInputChains1_0,
/*1604*/      OPC_MorphNodeTo, TARGET_VAL(XCore::SETRDY_l2r), 0|OPFL_Chain,
                  0/*#VTs*/, 2/*#Ops*/, 1, 2, 
              // Src: (intrinsic_void 3270:iPTR, GRRegs:i32:$src1, GRRegs:i32:$src2) - Complexity = 8
              // Dst: (SETRDY_l2r GRRegs:i32:$src1, GRRegs:i32:$src2)
/*1612*/    /*Scope*/ 15, /*->1628*/
/*1613*/      OPC_CheckInteger, 57|128,25/*3257*/, 
/*1616*/      OPC_MoveParent,
/*1617*/      OPC_RecordChild2, // #1 = $a
/*1618*/      OPC_CheckChild2Type, MVT::i32,
/*1620*/      OPC_EmitMergeInputChains1_0,
/*1621*/      OPC_MorphNodeTo, TARGET_VAL(XCore::MSYNC_1r), 0|OPFL_Chain,
                  0/*#VTs*/, 1/*#Ops*/, 1, 
              // Src: (intrinsic_void 3257:iPTR, GRRegs:i32:$a) - Complexity = 8
              // Dst: (MSYNC_1r GRRegs:i32:$a)
/*1628*/    /*Scope*/ 15, /*->1644*/
/*1629*/      OPC_CheckInteger, 56|128,25/*3256*/, 
/*1632*/      OPC_MoveParent,
/*1633*/      OPC_RecordChild2, // #1 = $a
/*1634*/      OPC_CheckChild2Type, MVT::i32,
/*1636*/      OPC_EmitMergeInputChains1_0,
/*1637*/      OPC_MorphNodeTo, TARGET_VAL(XCore::MJOIN_1r), 0|OPFL_Chain,
                  0/*#VTs*/, 1/*#Ops*/, 1, 
              // Src: (intrinsic_void 3256:iPTR, GRRegs:i32:$a) - Complexity = 8
              // Dst: (MJOIN_1r GRRegs:i32:$a)
/*1644*/    /*Scope*/ 15, /*->1660*/
/*1645*/      OPC_CheckInteger, 76|128,25/*3276*/, 
/*1648*/      OPC_MoveParent,
/*1649*/      OPC_RecordChild2, // #1 = $a
/*1650*/      OPC_CheckChild2Type, MVT::i32,
/*1652*/      OPC_EmitMergeInputChains1_0,
/*1653*/      OPC_MorphNodeTo, TARGET_VAL(XCore::SYNCR_1r), 0|OPFL_Chain,
                  0/*#VTs*/, 1/*#Ops*/, 1, 
              // Src: (intrinsic_void 3276:iPTR, GRRegs:i32:$a) - Complexity = 8
              // Dst: (SYNCR_1r GRRegs:i32:$a)
/*1660*/    /*Scope*/ 15, /*->1676*/
/*1661*/      OPC_CheckInteger, 39|128,25/*3239*/, 
/*1664*/      OPC_MoveParent,
/*1665*/      OPC_RecordChild2, // #1 = $a
/*1666*/      OPC_CheckChild2Type, MVT::i32,
/*1668*/      OPC_EmitMergeInputChains1_0,
/*1669*/      OPC_MorphNodeTo, TARGET_VAL(XCore::FREER_1r), 0|OPFL_Chain,
                  0/*#VTs*/, 1/*#Ops*/, 1, 
              // Src: (intrinsic_void 3239:iPTR, GRRegs:i32:$a) - Complexity = 8
              // Dst: (FREER_1r GRRegs:i32:$a)
/*1676*/    /*Scope*/ 21, /*->1698*/
/*1677*/      OPC_CheckInteger, 73|128,25/*3273*/, 
/*1680*/      OPC_MoveParent,
/*1681*/      OPC_RecordChild2, // #1 = $a
/*1682*/      OPC_CheckChild2Type, MVT::i32,
/*1684*/      OPC_RecordChild3, // #2 = physreg input R11
/*1685*/      OPC_CheckChild3Type, MVT::i32,
/*1687*/      OPC_EmitMergeInputChains1_0,
/*1688*/      OPC_EmitCopyToReg, 2, XCore::R11,
/*1691*/      OPC_MorphNodeTo, TARGET_VAL(XCore::SETV_1r), 0|OPFL_Chain|OPFL_GlueInput,
                  0/*#VTs*/, 1/*#Ops*/, 1, 
              // Src: (intrinsic_void 3273:iPTR, GRRegs:i32:$a, R11:i32) - Complexity = 8
              // Dst: (SETV_1r GRRegs:i32:$a)
/*1698*/    /*Scope*/ 21, /*->1720*/
/*1699*/      OPC_CheckInteger, 66|128,25/*3266*/, 
/*1702*/      OPC_MoveParent,
/*1703*/      OPC_RecordChild2, // #1 = $a
/*1704*/      OPC_CheckChild2Type, MVT::i32,
/*1706*/      OPC_RecordChild3, // #2 = physreg input R11
/*1707*/      OPC_CheckChild3Type, MVT::i32,
/*1709*/      OPC_EmitMergeInputChains1_0,
/*1710*/      OPC_EmitCopyToReg, 2, XCore::R11,
/*1713*/      OPC_MorphNodeTo, TARGET_VAL(XCore::SETEV_1r), 0|OPFL_Chain|OPFL_GlueInput,
                  0/*#VTs*/, 1/*#Ops*/, 1, 
              // Src: (intrinsic_void 3266:iPTR, GRRegs:i32:$a, R11:i32) - Complexity = 8
              // Dst: (SETEV_1r GRRegs:i32:$a)
/*1720*/    /*Scope*/ 15, /*->1736*/
/*1721*/      OPC_CheckInteger, 37|128,25/*3237*/, 
/*1724*/      OPC_MoveParent,
/*1725*/      OPC_RecordChild2, // #1 = $a
/*1726*/      OPC_CheckChild2Type, MVT::i32,
/*1728*/      OPC_EmitMergeInputChains1_0,
/*1729*/      OPC_MorphNodeTo, TARGET_VAL(XCore::EEU_1r), 0|OPFL_Chain,
                  0/*#VTs*/, 1/*#Ops*/, 1, 
              // Src: (intrinsic_void 3237:iPTR, GRRegs:i32:$a) - Complexity = 8
              // Dst: (EEU_1r GRRegs:i32:$a)
/*1736*/    /*Scope*/ 11, /*->1748*/
/*1737*/      OPC_CheckInteger, 33|128,25/*3233*/, 
/*1740*/      OPC_MoveParent,
/*1741*/      OPC_EmitMergeInputChains1_0,
/*1742*/      OPC_MorphNodeTo, TARGET_VAL(XCore::CLRE_0R), 0|OPFL_Chain,
                  0/*#VTs*/, 0/*#Ops*/, 
              // Src: (intrinsic_void 3233:iPTR) - Complexity = 8
              // Dst: (CLRE_0R)
/*1748*/    /*Scope*/ 11, /*->1760*/
/*1749*/      OPC_CheckInteger, 75|128,25/*3275*/, 
/*1752*/      OPC_MoveParent,
/*1753*/      OPC_EmitMergeInputChains1_0,
/*1754*/      OPC_MorphNodeTo, TARGET_VAL(XCore::SSYNC_0r), 0|OPFL_Chain,
                  0/*#VTs*/, 0/*#Ops*/, 
              // Src: (intrinsic_void 3275:iPTR) - Complexity = 8
              // Dst: (SSYNC_0r)
/*1760*/    0, /*End of Scope*/
/*1761*/  /*SwitchOpcode*/ 126,  TARGET_VAL(ISD::INTRINSIC_WO_CHAIN),// ->1890
/*1764*/    OPC_MoveChild, 0,
/*1766*/    OPC_Scope, 38, /*->1806*/ // 5 children in Scope
/*1768*/      OPC_CheckInteger, 74|128,25/*3274*/, 
/*1771*/      OPC_MoveParent,
/*1772*/      OPC_RecordChild1, // #0 = $src1
/*1773*/      OPC_RecordChild2, // #1 = $src2
/*1774*/      OPC_Scope, 19, /*->1795*/ // 2 children in Scope
/*1776*/        OPC_MoveChild, 2,
/*1778*/        OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*1781*/        OPC_CheckPredicate, 19, // Predicate_immBitp
/*1783*/        OPC_MoveParent,
/*1784*/        OPC_EmitConvertToTarget, 1,
/*1786*/        OPC_MorphNodeTo, TARGET_VAL(XCore::SEXT_rus), 0,
                    1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 2, 
                // Src: (intrinsic_wo_chain:i32 3274:iPTR, GRRegs:i32:$src1, (imm:i32)<<P:Predicate_immBitp>>:$src2) - Complexity = 12
                // Dst: (SEXT_rus:i32 GRRegs:i32:$src1, (imm:i32):$src2)
/*1795*/      /*Scope*/ 9, /*->1805*/
/*1796*/        OPC_MorphNodeTo, TARGET_VAL(XCore::SEXT_2r), 0,
                    1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1, 
                // Src: (intrinsic_wo_chain:i32 3274:iPTR, GRRegs:i32:$src1, GRRegs:i32:$src2) - Complexity = 8
                // Dst: (SEXT_2r:i32 GRRegs:i32:$src1, GRRegs:i32:$src2)
/*1805*/      0, /*End of Scope*/
/*1806*/    /*Scope*/ 38, /*->1845*/
/*1807*/      OPC_CheckInteger, 80|128,25/*3280*/, 
/*1810*/      OPC_MoveParent,
/*1811*/      OPC_RecordChild1, // #0 = $src1
/*1812*/      OPC_RecordChild2, // #1 = $src2
/*1813*/      OPC_Scope, 19, /*->1834*/ // 2 children in Scope
/*1815*/        OPC_MoveChild, 2,
/*1817*/        OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*1820*/        OPC_CheckPredicate, 19, // Predicate_immBitp
/*1822*/        OPC_MoveParent,
/*1823*/        OPC_EmitConvertToTarget, 1,
/*1825*/        OPC_MorphNodeTo, TARGET_VAL(XCore::ZEXT_rus), 0,
                    1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 2, 
                // Src: (intrinsic_wo_chain:i32 3280:iPTR, GRRegs:i32:$src1, (imm:i32)<<P:Predicate_immBitp>>:$src2) - Complexity = 12
                // Dst: (ZEXT_rus:i32 GRRegs:i32:$src1, (imm:i32):$src2)
/*1834*/      /*Scope*/ 9, /*->1844*/
/*1835*/        OPC_MorphNodeTo, TARGET_VAL(XCore::ZEXT_2r), 0,
                    1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1, 
                // Src: (intrinsic_wo_chain:i32 3280:iPTR, GRRegs:i32:$src1, GRRegs:i32:$src2) - Complexity = 8
                // Dst: (ZEXT_2r:i32 GRRegs:i32:$src1, GRRegs:i32:$src2)
/*1844*/      0, /*End of Scope*/
/*1845*/    /*Scope*/ 17, /*->1863*/
/*1846*/      OPC_CheckInteger, 35|128,25/*3235*/, 
/*1849*/      OPC_MoveParent,
/*1850*/      OPC_RecordChild1, // #0 = $src1
/*1851*/      OPC_RecordChild2, // #1 = $src2
/*1852*/      OPC_RecordChild3, // #2 = $src3
/*1853*/      OPC_MorphNodeTo, TARGET_VAL(XCore::CRC_l3r), 0,
                  1/*#VTs*/, MVT::i32, 3/*#Ops*/, 0, 1, 2, 
              // Src: (intrinsic_wo_chain:i32 3235:iPTR, GRRegs:i32:$src1, GRRegs:i32:$src2, GRRegs:i32:$src3) - Complexity = 8
              // Dst: (CRC_l3r:i32 GRRegs:i32:$src1, GRRegs:i32:$src2, GRRegs:i32:$src3)
/*1863*/    /*Scope*/ 13, /*->1877*/
/*1864*/      OPC_CheckInteger, 30|128,25/*3230*/, 
/*1867*/      OPC_MoveParent,
/*1868*/      OPC_RecordChild1, // #0 = $src
/*1869*/      OPC_MorphNodeTo, TARGET_VAL(XCore::BITREV_l2r), 0,
                  1/*#VTs*/, MVT::i32, 1/*#Ops*/, 0, 
              // Src: (intrinsic_wo_chain:i32 3230:iPTR, GRRegs:i32:$src) - Complexity = 8
              // Dst: (BITREV_l2r:i32 GRRegs:i32:$src)
/*1877*/    /*Scope*/ 11, /*->1889*/
/*1878*/      OPC_CheckInteger, 42|128,25/*3242*/, 
/*1881*/      OPC_MoveParent,
/*1882*/      OPC_MorphNodeTo, TARGET_VAL(XCore::GETID_0R), 0,
                  1/*#VTs*/, MVT::i32, 0/*#Ops*/, 
              // Src: (intrinsic_wo_chain:i32 3242:iPTR) - Complexity = 8
              // Dst: (GETID_0R:i32)
/*1889*/    0, /*End of Scope*/
/*1890*/  /*SwitchOpcode*/ 10|128,2/*266*/,  TARGET_VAL(ISD::INTRINSIC_W_CHAIN),// ->2160
/*1894*/    OPC_RecordNode,   // #0 = 'intrinsic_w_chain' chained node
/*1895*/    OPC_MoveChild, 1,
/*1897*/    OPC_Scope, 26, /*->1925*/ // 15 children in Scope
/*1899*/      OPC_CheckInteger, 44|128,25/*3244*/, 
/*1902*/      OPC_MoveParent,
/*1903*/      OPC_RecordChild2, // #1 = $type
/*1904*/      OPC_MoveChild, 2,
/*1906*/      OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*1909*/      OPC_CheckPredicate, 0, // Predicate_immUs
/*1911*/      OPC_MoveParent,
/*1912*/      OPC_CheckType, MVT::i32,
/*1914*/      OPC_EmitMergeInputChains1_0,
/*1915*/      OPC_EmitConvertToTarget, 1,
/*1917*/      OPC_MorphNodeTo, TARGET_VAL(XCore::GETR_rus), 0|OPFL_Chain,
                  1/*#VTs*/, MVT::i32, 1/*#Ops*/, 2, 
              // Src: (intrinsic_w_chain:i32 3244:iPTR, (imm:i32)<<P:Predicate_immUs>>:$type) - Complexity = 12
              // Dst: (GETR_rus:i32 (imm:i32):$type)
/*1925*/    /*Scope*/ 16, /*->1942*/
/*1926*/      OPC_CheckInteger, 46|128,25/*3246*/, 
/*1929*/      OPC_MoveParent,
/*1930*/      OPC_RecordChild2, // #1 = $r
/*1931*/      OPC_CheckChild2Type, MVT::i32,
/*1933*/      OPC_EmitMergeInputChains1_0,
/*1934*/      OPC_MorphNodeTo, TARGET_VAL(XCore::GETTS_2r), 0|OPFL_Chain,
                  1/*#VTs*/, MVT::i32, 1/*#Ops*/, 1, 
              // Src: (intrinsic_w_chain:i32 3246:iPTR, GRRegs:i32:$r) - Complexity = 8
              // Dst: (GETTS_2r:i32 GRRegs:i32:$r)
/*1942*/    /*Scope*/ 18, /*->1961*/
/*1943*/      OPC_CheckInteger, 60|128,25/*3260*/, 
/*1946*/      OPC_MoveParent,
/*1947*/      OPC_RecordChild2, // #1 = $r
/*1948*/      OPC_CheckChild2Type, MVT::i32,
/*1950*/      OPC_RecordChild3, // #2 = $src
/*1951*/      OPC_EmitMergeInputChains1_0,
/*1952*/      OPC_MorphNodeTo, TARGET_VAL(XCore::OUTSHR_2r), 0|OPFL_Chain,
                  1/*#VTs*/, MVT::i32, 2/*#Ops*/, 2, 1, 
              // Src: (intrinsic_w_chain:i32 3260:iPTR, GRRegs:i32:$r, GRRegs:i32:$src) - Complexity = 8
              // Dst: (OUTSHR_2r:i32 GRRegs:i32:$src, GRRegs:i32:$r)
/*1961*/    /*Scope*/ 16, /*->1978*/
/*1962*/      OPC_CheckInteger, 48|128,25/*3248*/, 
/*1965*/      OPC_MoveParent,
/*1966*/      OPC_RecordChild2, // #1 = $r
/*1967*/      OPC_CheckChild2Type, MVT::i32,
/*1969*/      OPC_EmitMergeInputChains1_0,
/*1970*/      OPC_MorphNodeTo, TARGET_VAL(XCore::INCT_2r), 0|OPFL_Chain,
                  1/*#VTs*/, MVT::i32, 1/*#Ops*/, 1, 
              // Src: (intrinsic_w_chain:i32 3248:iPTR, GRRegs:i32:$r) - Complexity = 8
              // Dst: (INCT_2r:i32 GRRegs:i32:$r)
/*1978*/    /*Scope*/ 16, /*->1995*/
/*1979*/      OPC_CheckInteger, 55|128,25/*3255*/, 
/*1982*/      OPC_MoveParent,
/*1983*/      OPC_RecordChild2, // #1 = $r
/*1984*/      OPC_CheckChild2Type, MVT::i32,
/*1986*/      OPC_EmitMergeInputChains1_0,
/*1987*/      OPC_MorphNodeTo, TARGET_VAL(XCore::INT_2r), 0|OPFL_Chain,
                  1/*#VTs*/, MVT::i32, 1/*#Ops*/, 1, 
              // Src: (intrinsic_w_chain:i32 3255:iPTR, GRRegs:i32:$r) - Complexity = 8
              // Dst: (INT_2r:i32 GRRegs:i32:$r)
/*1995*/    /*Scope*/ 16, /*->2012*/
/*1996*/      OPC_CheckInteger, 47|128,25/*3247*/, 
/*1999*/      OPC_MoveParent,
/*2000*/      OPC_RecordChild2, // #1 = $r
/*2001*/      OPC_CheckChild2Type, MVT::i32,
/*2003*/      OPC_EmitMergeInputChains1_0,
/*2004*/      OPC_MorphNodeTo, TARGET_VAL(XCore::IN_2r), 0|OPFL_Chain,
                  1/*#VTs*/, MVT::i32, 1/*#Ops*/, 1, 
              // Src: (intrinsic_w_chain:i32 3247:iPTR, GRRegs:i32:$r) - Complexity = 8
              // Dst: (IN_2r:i32 GRRegs:i32:$r)
/*2012*/    /*Scope*/ 18, /*->2031*/
/*2013*/      OPC_CheckInteger, 54|128,25/*3254*/, 
/*2016*/      OPC_MoveParent,
/*2017*/      OPC_RecordChild2, // #1 = $r
/*2018*/      OPC_CheckChild2Type, MVT::i32,
/*2020*/      OPC_RecordChild3, // #2 = $src
/*2021*/      OPC_EmitMergeInputChains1_0,
/*2022*/      OPC_MorphNodeTo, TARGET_VAL(XCore::INSHR_2r), 0|OPFL_Chain,
                  1/*#VTs*/, MVT::i32, 2/*#Ops*/, 2, 1, 
              // Src: (intrinsic_w_chain:i32 3254:iPTR, GRRegs:i32:$r, GRRegs:i32:$src) - Complexity = 8
              // Dst: (INSHR_2r:i32 GRRegs:i32:$src, GRRegs:i32:$r)
/*2031*/    /*Scope*/ 16, /*->2048*/
/*2032*/      OPC_CheckInteger, 77|128,25/*3277*/, 
/*2035*/      OPC_MoveParent,
/*2036*/      OPC_RecordChild2, // #1 = $src
/*2037*/      OPC_CheckChild2Type, MVT::i32,
/*2039*/      OPC_EmitMergeInputChains1_0,
/*2040*/      OPC_MorphNodeTo, TARGET_VAL(XCore::TESTCT_2r), 0|OPFL_Chain,
                  1/*#VTs*/, MVT::i32, 1/*#Ops*/, 1, 
              // Src: (intrinsic_w_chain:i32 3277:iPTR, GRRegs:i32:$src) - Complexity = 8
              // Dst: (TESTCT_2r:i32 GRRegs:i32:$src)
/*2048*/    /*Scope*/ 16, /*->2065*/
/*2049*/      OPC_CheckInteger, 78|128,25/*3278*/, 
/*2052*/      OPC_MoveParent,
/*2053*/      OPC_RecordChild2, // #1 = $src
/*2054*/      OPC_CheckChild2Type, MVT::i32,
/*2056*/      OPC_EmitMergeInputChains1_0,
/*2057*/      OPC_MorphNodeTo, TARGET_VAL(XCore::TESTWCT_2r), 0|OPFL_Chain,
                  1/*#VTs*/, MVT::i32, 1/*#Ops*/, 1, 
              // Src: (intrinsic_w_chain:i32 3278:iPTR, GRRegs:i32:$src) - Complexity = 8
              // Dst: (TESTWCT_2r:i32 GRRegs:i32:$src)
/*2065*/    /*Scope*/ 18, /*->2084*/
/*2066*/      OPC_CheckInteger, 45|128,25/*3245*/, 
/*2069*/      OPC_MoveParent,
/*2070*/      OPC_RecordChild2, // #1 = $r
/*2071*/      OPC_CheckChild2Type, MVT::i32,
/*2073*/      OPC_CheckType, MVT::i32,
/*2075*/      OPC_EmitMergeInputChains1_0,
/*2076*/      OPC_MorphNodeTo, TARGET_VAL(XCore::GETST_2r), 0|OPFL_Chain,
                  1/*#VTs*/, MVT::i32, 1/*#Ops*/, 1, 
              // Src: (intrinsic_w_chain:i32 3245:iPTR, GRRegs:i32:$r) - Complexity = 8
              // Dst: (GETST_2r:i32 GRRegs:i32:$r)
/*2084*/    /*Scope*/ 16, /*->2101*/
/*2085*/      OPC_CheckInteger, 62|128,25/*3262*/, 
/*2088*/      OPC_MoveParent,
/*2089*/      OPC_RecordChild2, // #1 = $src
/*2090*/      OPC_CheckChild2Type, MVT::i32,
/*2092*/      OPC_EmitMergeInputChains1_0,
/*2093*/      OPC_MorphNodeTo, TARGET_VAL(XCore::PEEK_2r), 0|OPFL_Chain,
                  1/*#VTs*/, MVT::i32, 1/*#Ops*/, 1, 
              // Src: (intrinsic_w_chain:i32 3262:iPTR, GRRegs:i32:$src) - Complexity = 8
              // Dst: (PEEK_2r:i32 GRRegs:i32:$src)
/*2101*/    /*Scope*/ 16, /*->2118*/
/*2102*/      OPC_CheckInteger, 38|128,25/*3238*/, 
/*2105*/      OPC_MoveParent,
/*2106*/      OPC_RecordChild2, // #1 = $src
/*2107*/      OPC_CheckChild2Type, MVT::i32,
/*2109*/      OPC_EmitMergeInputChains1_0,
/*2110*/      OPC_MorphNodeTo, TARGET_VAL(XCore::ENDIN_2r), 0|OPFL_Chain,
                  1/*#VTs*/, MVT::i32, 1/*#Ops*/, 1, 
              // Src: (intrinsic_w_chain:i32 3238:iPTR, GRRegs:i32:$src) - Complexity = 8
              // Dst: (ENDIN_2r:i32 GRRegs:i32:$src)
/*2118*/    /*Scope*/ 14, /*->2133*/
/*2119*/      OPC_CheckInteger, 43|128,25/*3243*/, 
/*2122*/      OPC_MoveParent,
/*2123*/      OPC_RecordChild2, // #1 = $src
/*2124*/      OPC_EmitMergeInputChains1_0,
/*2125*/      OPC_MorphNodeTo, TARGET_VAL(XCore::GETPS_l2r), 0|OPFL_Chain,
                  1/*#VTs*/, MVT::i32, 1/*#Ops*/, 1, 
              // Src: (intrinsic_w_chain:i32 3243:iPTR, GRRegs:i32:$src) - Complexity = 8
              // Dst: (GETPS_l2r:i32 GRRegs:i32:$src)
/*2133*/    /*Scope*/ 12, /*->2146*/
/*2134*/      OPC_CheckInteger, 40|128,25/*3240*/, 
/*2137*/      OPC_MoveParent,
/*2138*/      OPC_EmitMergeInputChains1_0,
/*2139*/      OPC_MorphNodeTo, TARGET_VAL(XCore::GETED_0R), 0|OPFL_Chain,
                  1/*#VTs*/, MVT::i32, 0/*#Ops*/, 
              // Src: (intrinsic_w_chain:i32 3240:iPTR) - Complexity = 8
              // Dst: (GETED_0R:i32)
/*2146*/    /*Scope*/ 12, /*->2159*/
/*2147*/      OPC_CheckInteger, 41|128,25/*3241*/, 
/*2150*/      OPC_MoveParent,
/*2151*/      OPC_EmitMergeInputChains1_0,
/*2152*/      OPC_MorphNodeTo, TARGET_VAL(XCore::GETET_0R), 0|OPFL_Chain,
                  1/*#VTs*/, MVT::i32, 0/*#Ops*/, 
              // Src: (intrinsic_w_chain:i32 3241:iPTR) - Complexity = 8
              // Dst: (GETET_0R:i32)
/*2159*/    0, /*End of Scope*/
/*2160*/  /*SwitchOpcode*/ 113,  TARGET_VAL(ISD::SUB),// ->2276
/*2163*/    OPC_Scope, 39, /*->2204*/ // 3 children in Scope
/*2165*/      OPC_RecordChild0, // #0 = $addr
/*2166*/      OPC_MoveChild, 1,
/*2168*/      OPC_CheckOpcode, TARGET_VAL(ISD::SHL),
/*2171*/      OPC_RecordChild0, // #1 = $offset
/*2172*/      OPC_MoveChild, 1,
/*2174*/      OPC_Scope, 13, /*->2189*/ // 2 children in Scope
/*2176*/        OPC_CheckInteger, 2, 
/*2178*/        OPC_MoveParent,
/*2179*/        OPC_MoveParent,
/*2180*/        OPC_MorphNodeTo, TARGET_VAL(XCore::LDAWB_l3r), 0,
                    1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1, 
                // Src: (sub:i32 GRRegs:i32:$addr, (shl:i32 GRRegs:i32:$offset, 2:i32)) - Complexity = 11
                // Dst: (LDAWB_l3r:i32 GRRegs:i32:$addr, GRRegs:i32:$offset)
/*2189*/      /*Scope*/ 13, /*->2203*/
/*2190*/        OPC_CheckInteger, 1, 
/*2192*/        OPC_MoveParent,
/*2193*/        OPC_MoveParent,
/*2194*/        OPC_MorphNodeTo, TARGET_VAL(XCore::LDA16B_l3r), 0,
                    1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1, 
                // Src: (sub:i32 GRRegs:i32:$addr, (shl:i32 GRRegs:i32:$offset, 1:i32)) - Complexity = 11
                // Dst: (LDA16B_l3r:i32 GRRegs:i32:$addr, GRRegs:i32:$offset)
/*2203*/      0, /*End of Scope*/
/*2204*/    /*Scope*/ 14, /*->2219*/
/*2205*/      OPC_MoveChild, 0,
/*2207*/      OPC_CheckInteger, 0, 
/*2209*/      OPC_MoveParent,
/*2210*/      OPC_RecordChild1, // #0 = $b
/*2211*/      OPC_MorphNodeTo, TARGET_VAL(XCore::NEG), 0,
                  1/*#VTs*/, MVT::i32, 1/*#Ops*/, 0, 
              // Src: (sub:i32 0:i32, GRRegs:i32:$b) - Complexity = 8
              // Dst: (NEG:i32 GRRegs:i32:$b)
/*2219*/    /*Scope*/ 55, /*->2275*/
/*2220*/      OPC_RecordChild0, // #0 = $b
/*2221*/      OPC_RecordChild1, // #1 = $c
/*2222*/      OPC_Scope, 40, /*->2264*/ // 2 children in Scope
/*2224*/        OPC_MoveChild, 1,
/*2226*/        OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*2229*/        OPC_Scope, 14, /*->2245*/ // 2 children in Scope
/*2231*/          OPC_CheckPredicate, 0, // Predicate_immUs
/*2233*/          OPC_MoveParent,
/*2234*/          OPC_EmitConvertToTarget, 1,
/*2236*/          OPC_MorphNodeTo, TARGET_VAL(XCore::SUB_2rus), 0,
                      1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 2, 
                  // Src: (sub:i32 GRRegs:i32:$b, (imm:i32)<<P:Predicate_immUs>>:$c) - Complexity = 7
                  // Dst: (SUB_2rus:i32 GRRegs:i32:$b, (imm:i32):$c)
/*2245*/        /*Scope*/ 17, /*->2263*/
/*2246*/          OPC_CheckPredicate, 1, // Predicate_immUs4
/*2248*/          OPC_MoveParent,
/*2249*/          OPC_EmitConvertToTarget, 1,
/*2251*/          OPC_EmitNodeXForm, 0, 2, // div4_xform
/*2254*/          OPC_MorphNodeTo, TARGET_VAL(XCore::LDAWB_l2rus), 0,
                      1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 3, 
                  // Src: (sub:i32 GRRegs:i32:$addr, (imm:i32)<<P:Predicate_immUs4>>:$offset) - Complexity = 7
                  // Dst: (LDAWB_l2rus:i32 GRRegs:i32:$addr, (div4_xform:i32 (imm:i32)<<P:Predicate_immUs4>>:$offset))
/*2263*/        0, /*End of Scope*/
/*2264*/      /*Scope*/ 9, /*->2274*/
/*2265*/        OPC_MorphNodeTo, TARGET_VAL(XCore::SUB_3r), 0,
                    1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1, 
                // Src: (sub:i32 GRRegs:i32:$b, GRRegs:i32:$c) - Complexity = 3
                // Dst: (SUB_3r:i32 GRRegs:i32:$b, GRRegs:i32:$c)
/*2274*/      0, /*End of Scope*/
/*2275*/    0, /*End of Scope*/
/*2276*/  /*SwitchOpcode*/ 104,  TARGET_VAL(ISD::AND),// ->2383
/*2279*/    OPC_Scope, 31, /*->2312*/ // 3 children in Scope
/*2281*/      OPC_RecordChild0, // #0 = $src1
/*2282*/      OPC_MoveChild, 1,
/*2284*/      OPC_CheckOpcode, TARGET_VAL(ISD::XOR),
/*2287*/      OPC_RecordChild0, // #1 = $src2
/*2288*/      OPC_MoveChild, 1,
/*2290*/      OPC_CheckInteger, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*2301*/      OPC_MoveParent,
/*2302*/      OPC_MoveParent,
/*2303*/      OPC_MorphNodeTo, TARGET_VAL(XCore::ANDNOT_2r), 0,
                  1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1, 
              // Src: (and:i32 GRRegs:i32:$src1, (xor:i32 GRRegs:i32:$src2, -1:i32)) - Complexity = 11
              // Dst: (ANDNOT_2r:i32 GRRegs:i32:$src1, GRRegs:i32:$src2)
/*2312*/    /*Scope*/ 31, /*->2344*/
/*2313*/      OPC_MoveChild, 0,
/*2315*/      OPC_CheckOpcode, TARGET_VAL(ISD::XOR),
/*2318*/      OPC_RecordChild0, // #0 = $src2
/*2319*/      OPC_MoveChild, 1,
/*2321*/      OPC_CheckInteger, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*2332*/      OPC_MoveParent,
/*2333*/      OPC_MoveParent,
/*2334*/      OPC_RecordChild1, // #1 = $src1
/*2335*/      OPC_MorphNodeTo, TARGET_VAL(XCore::ANDNOT_2r), 0,
                  1/*#VTs*/, MVT::i32, 2/*#Ops*/, 1, 0, 
              // Src: (and:i32 (xor:i32 GRRegs:i32:$src2, -1:i32), GRRegs:i32:$src1) - Complexity = 11
              // Dst: (ANDNOT_2r:i32 GRRegs:i32:$src1, GRRegs:i32:$src2)
/*2344*/    /*Scope*/ 37, /*->2382*/
/*2345*/      OPC_RecordChild0, // #0 = $val
/*2346*/      OPC_RecordChild1, // #1 = $mask
/*2347*/      OPC_Scope, 22, /*->2371*/ // 2 children in Scope
/*2349*/        OPC_MoveChild, 1,
/*2351*/        OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*2354*/        OPC_CheckPredicate, 22, // Predicate_immMskBitp
/*2356*/        OPC_MoveParent,
/*2357*/        OPC_EmitConvertToTarget, 1,
/*2359*/        OPC_EmitNodeXForm, 4, 2, // msksize_xform
/*2362*/        OPC_MorphNodeTo, TARGET_VAL(XCore::ZEXT_rus), 0,
                    1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 3, 
                // Src: (and:i32 GRRegs:i32:$val, (imm:i32)<<P:Predicate_immMskBitp>>:$mask) - Complexity = 7
                // Dst: (ZEXT_rus:i32 GRRegs:i32:$val, (msksize_xform:i32 (imm:i32)<<P:Predicate_immMskBitp>>:$mask))
/*2371*/      /*Scope*/ 9, /*->2381*/
/*2372*/        OPC_MorphNodeTo, TARGET_VAL(XCore::AND_3r), 0,
                    1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1, 
                // Src: (and:i32 GRRegs:i32:$b, GRRegs:i32:$c) - Complexity = 3
                // Dst: (AND_3r:i32 GRRegs:i32:$b, GRRegs:i32:$c)
/*2381*/      0, /*End of Scope*/
/*2382*/    0, /*End of Scope*/
/*2383*/  /*SwitchOpcode*/ 40,  TARGET_VAL(ISD::BRIND),// ->2426
/*2386*/    OPC_RecordNode,   // #0 = 'brind' chained node
/*2387*/    OPC_Scope, 24, /*->2413*/ // 2 children in Scope
/*2389*/      OPC_MoveChild, 1,
/*2391*/      OPC_CheckOpcode, TARGET_VAL(ISD::INTRINSIC_W_CHAIN),
/*2394*/      OPC_RecordNode, // #1 = 'intrinsic_w_chain' chained node
/*2395*/      OPC_CheckFoldableChainNode,
/*2396*/      OPC_MoveChild, 1,
/*2398*/      OPC_CheckInteger, 79|128,25/*3279*/, 
/*2401*/      OPC_MoveParent,
/*2402*/      OPC_MoveParent,
/*2403*/      OPC_EmitMergeInputChains, 2, 0, 1, 
/*2407*/      OPC_MorphNodeTo, TARGET_VAL(XCore::WAITEU_0R), 0|OPFL_Chain,
                  0/*#VTs*/, 0/*#Ops*/, 
              // Src: (brind (intrinsic_w_chain:iPTR 3279:iPTR)) - Complexity = 11
              // Dst: (WAITEU_0R)
/*2413*/    /*Scope*/ 11, /*->2425*/
/*2414*/      OPC_RecordChild1, // #1 = $a
/*2415*/      OPC_CheckChild1Type, MVT::i32,
/*2417*/      OPC_EmitMergeInputChains1_0,
/*2418*/      OPC_MorphNodeTo, TARGET_VAL(XCore::BAU_1r), 0|OPFL_Chain,
                  0/*#VTs*/, 1/*#Ops*/, 1, 
              // Src: (brind GRRegs:i32:$a) - Complexity = 3
              // Dst: (BAU_1r GRRegs:i32:$a)
/*2425*/    0, /*End of Scope*/
/*2426*/  /*SwitchOpcode*/ 113|128,2/*369*/,  TARGET_VAL(ISD::BRCOND),// ->2799
/*2430*/    OPC_RecordNode,   // #0 = 'brcond' chained node
/*2431*/    OPC_Scope, 90|128,2/*346*/, /*->2780*/ // 2 children in Scope
/*2434*/      OPC_MoveChild, 1,
/*2436*/      OPC_CheckOpcode, TARGET_VAL(ISD::SETCC),
/*2439*/      OPC_RecordChild0, // #1 = $lhs
/*2440*/      OPC_Scope, 6|128,1/*134*/, /*->2577*/ // 3 children in Scope
/*2443*/        OPC_MoveChild, 1,
/*2445*/        OPC_Scope, 82, /*->2529*/ // 2 children in Scope
/*2447*/          OPC_CheckInteger, 0, 
/*2449*/          OPC_MoveParent,
/*2450*/          OPC_MoveChild, 2,
/*2452*/          OPC_Scope, 20, /*->2474*/ // 3 children in Scope
/*2454*/            OPC_CheckCondCode, ISD::SETNE,
/*2456*/            OPC_MoveParent,
/*2457*/            OPC_MoveParent,
/*2458*/            OPC_RecordChild2, // #2 = $dst
/*2459*/            OPC_MoveChild, 2,
/*2461*/            OPC_CheckOpcode, TARGET_VAL(ISD::BasicBlock),
/*2464*/            OPC_MoveParent,
/*2465*/            OPC_EmitMergeInputChains1_0,
/*2466*/            OPC_MorphNodeTo, TARGET_VAL(XCore::BRFT_lru6), 0|OPFL_Chain,
                        0/*#VTs*/, 2/*#Ops*/, 1, 2, 
                    // Src: (brcond (setcc:i32 GRRegs:i32:$lhs, 0:i32, SETNE:Other), (bb:Other):$dst) - Complexity = 11
                    // Dst: (BRFT_lru6 GRRegs:i32:$lhs, (bb:Other):$dst)
/*2474*/          /*Scope*/ 20, /*->2495*/
/*2475*/            OPC_CheckCondCode, ISD::SETEQ,
/*2477*/            OPC_MoveParent,
/*2478*/            OPC_MoveParent,
/*2479*/            OPC_RecordChild2, // #2 = $dst
/*2480*/            OPC_MoveChild, 2,
/*2482*/            OPC_CheckOpcode, TARGET_VAL(ISD::BasicBlock),
/*2485*/            OPC_MoveParent,
/*2486*/            OPC_EmitMergeInputChains1_0,
/*2487*/            OPC_MorphNodeTo, TARGET_VAL(XCore::BRFF_lru6), 0|OPFL_Chain,
                        0/*#VTs*/, 2/*#Ops*/, 1, 2, 
                    // Src: (brcond (setcc:i32 GRRegs:i32:$lhs, 0:i32, SETEQ:Other), (bb:Other):$dst) - Complexity = 11
                    // Dst: (BRFF_lru6 GRRegs:i32:$lhs, (bb:Other):$dst)
/*2495*/          /*Scope*/ 32, /*->2528*/
/*2496*/            OPC_CheckCondCode, ISD::SETLT,
/*2498*/            OPC_MoveParent,
/*2499*/            OPC_MoveParent,
/*2500*/            OPC_RecordChild2, // #2 = $dst
/*2501*/            OPC_MoveChild, 2,
/*2503*/            OPC_CheckOpcode, TARGET_VAL(ISD::BasicBlock),
/*2506*/            OPC_MoveParent,
/*2507*/            OPC_EmitMergeInputChains1_0,
/*2508*/            OPC_EmitInteger, MVT::i32, 32, 
/*2511*/            OPC_EmitNode, TARGET_VAL(XCore::ASHR_l2rus), 0,
                        1/*#VTs*/, MVT::i32, 2/*#Ops*/, 1, 3,  // Results = #4
/*2520*/            OPC_MorphNodeTo, TARGET_VAL(XCore::BRFT_lru6), 0|OPFL_Chain,
                        0/*#VTs*/, 2/*#Ops*/, 4, 2, 
                    // Src: (brcond (setcc:i32 GRRegs:i32:$lhs, 0:i32, SETLT:Other), (bb:Other):$dst) - Complexity = 11
                    // Dst: (BRFT_lru6 (ASHR_l2rus:i32 GRRegs:i32:$lhs, 32:i32), (bb:Other):$dst)
/*2528*/          0, /*End of Scope*/
/*2529*/        /*Scope*/ 46, /*->2576*/
/*2530*/          OPC_CheckInteger, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*2541*/          OPC_MoveParent,
/*2542*/          OPC_MoveChild, 2,
/*2544*/          OPC_CheckCondCode, ISD::SETGT,
/*2546*/          OPC_MoveParent,
/*2547*/          OPC_MoveParent,
/*2548*/          OPC_RecordChild2, // #2 = $dst
/*2549*/          OPC_MoveChild, 2,
/*2551*/          OPC_CheckOpcode, TARGET_VAL(ISD::BasicBlock),
/*2554*/          OPC_MoveParent,
/*2555*/          OPC_EmitMergeInputChains1_0,
/*2556*/          OPC_EmitInteger, MVT::i32, 32, 
/*2559*/          OPC_EmitNode, TARGET_VAL(XCore::ASHR_l2rus), 0,
                      1/*#VTs*/, MVT::i32, 2/*#Ops*/, 1, 3,  // Results = #4
/*2568*/          OPC_MorphNodeTo, TARGET_VAL(XCore::BRFF_lru6), 0|OPFL_Chain,
                      0/*#VTs*/, 2/*#Ops*/, 4, 2, 
                  // Src: (brcond (setcc:i32 GRRegs:i32:$lhs, -1:i32, SETGT:Other), (bb:Other):$dst) - Complexity = 11
                  // Dst: (BRFF_lru6 (ASHR_l2rus:i32 GRRegs:i32:$lhs, 32:i32), (bb:Other):$dst)
/*2576*/        0, /*End of Scope*/
/*2577*/      /*Scope*/ 42, /*->2620*/
/*2578*/        OPC_RecordChild1, // #2 = $rhs
/*2579*/        OPC_MoveChild, 1,
/*2581*/        OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*2584*/        OPC_CheckPredicate, 0, // Predicate_immUs
/*2586*/        OPC_MoveParent,
/*2587*/        OPC_MoveChild, 2,
/*2589*/        OPC_CheckCondCode, ISD::SETNE,
/*2591*/        OPC_MoveParent,
/*2592*/        OPC_MoveParent,
/*2593*/        OPC_RecordChild2, // #3 = $dst
/*2594*/        OPC_MoveChild, 2,
/*2596*/        OPC_CheckOpcode, TARGET_VAL(ISD::BasicBlock),
/*2599*/        OPC_MoveParent,
/*2600*/        OPC_EmitMergeInputChains1_0,
/*2601*/        OPC_EmitConvertToTarget, 2,
/*2603*/        OPC_EmitNode, TARGET_VAL(XCore::EQ_2rus), 0,
                    1/*#VTs*/, MVT::i32, 2/*#Ops*/, 1, 4,  // Results = #5
/*2612*/        OPC_MorphNodeTo, TARGET_VAL(XCore::BRFF_lru6), 0|OPFL_Chain,
                    0/*#VTs*/, 2/*#Ops*/, 5, 3, 
                // Src: (brcond (setcc:i32 GRRegs:i32:$lhs, (imm:i32)<<P:Predicate_immUs>>:$rhs, SETNE:Other), (bb:Other):$dst) - Complexity = 10
                // Dst: (BRFF_lru6 (EQ_2rus:i32 GRRegs:i32:$lhs, (imm:i32)<<P:Predicate_immUs>>:$rhs), (bb:Other):$dst)
/*2620*/      /*Scope*/ 29|128,1/*157*/, /*->2779*/
/*2622*/        OPC_CheckChild0Type, MVT::i32,
/*2624*/        OPC_RecordChild1, // #2 = $rhs
/*2625*/        OPC_MoveChild, 2,
/*2627*/        OPC_Scope, 29, /*->2658*/ // 5 children in Scope
/*2629*/          OPC_CheckCondCode, ISD::SETLE,
/*2631*/          OPC_MoveParent,
/*2632*/          OPC_MoveParent,
/*2633*/          OPC_RecordChild2, // #3 = $dst
/*2634*/          OPC_MoveChild, 2,
/*2636*/          OPC_CheckOpcode, TARGET_VAL(ISD::BasicBlock),
/*2639*/          OPC_MoveParent,
/*2640*/          OPC_EmitMergeInputChains1_0,
/*2641*/          OPC_EmitNode, TARGET_VAL(XCore::LSS_3r), 0,
                      1/*#VTs*/, MVT::i32, 2/*#Ops*/, 2, 1,  // Results = #4
/*2650*/          OPC_MorphNodeTo, TARGET_VAL(XCore::BRFF_lru6), 0|OPFL_Chain,
                      0/*#VTs*/, 2/*#Ops*/, 4, 3, 
                  // Src: (brcond (setcc:i32 GRRegs:i32:$lhs, GRRegs:i32:$rhs, SETLE:Other), (bb:Other):$dst) - Complexity = 6
                  // Dst: (BRFF_lru6 (LSS_3r:i32 GRRegs:i32:$rhs, GRRegs:i32:$lhs), (bb:Other):$dst)
/*2658*/        /*Scope*/ 29, /*->2688*/
/*2659*/          OPC_CheckCondCode, ISD::SETULE,
/*2661*/          OPC_MoveParent,
/*2662*/          OPC_MoveParent,
/*2663*/          OPC_RecordChild2, // #3 = $dst
/*2664*/          OPC_MoveChild, 2,
/*2666*/          OPC_CheckOpcode, TARGET_VAL(ISD::BasicBlock),
/*2669*/          OPC_MoveParent,
/*2670*/          OPC_EmitMergeInputChains1_0,
/*2671*/          OPC_EmitNode, TARGET_VAL(XCore::LSU_3r), 0,
                      1/*#VTs*/, MVT::i32, 2/*#Ops*/, 2, 1,  // Results = #4
/*2680*/          OPC_MorphNodeTo, TARGET_VAL(XCore::BRFF_lru6), 0|OPFL_Chain,
                      0/*#VTs*/, 2/*#Ops*/, 4, 3, 
                  // Src: (brcond (setcc:i32 GRRegs:i32:$lhs, GRRegs:i32:$rhs, SETULE:Other), (bb:Other):$dst) - Complexity = 6
                  // Dst: (BRFF_lru6 (LSU_3r:i32 GRRegs:i32:$rhs, GRRegs:i32:$lhs), (bb:Other):$dst)
/*2688*/        /*Scope*/ 29, /*->2718*/
/*2689*/          OPC_CheckCondCode, ISD::SETGE,
/*2691*/          OPC_MoveParent,
/*2692*/          OPC_MoveParent,
/*2693*/          OPC_RecordChild2, // #3 = $dst
/*2694*/          OPC_MoveChild, 2,
/*2696*/          OPC_CheckOpcode, TARGET_VAL(ISD::BasicBlock),
/*2699*/          OPC_MoveParent,
/*2700*/          OPC_EmitMergeInputChains1_0,
/*2701*/          OPC_EmitNode, TARGET_VAL(XCore::LSS_3r), 0,
                      1/*#VTs*/, MVT::i32, 2/*#Ops*/, 1, 2,  // Results = #4
/*2710*/          OPC_MorphNodeTo, TARGET_VAL(XCore::BRFF_lru6), 0|OPFL_Chain,
                      0/*#VTs*/, 2/*#Ops*/, 4, 3, 
                  // Src: (brcond (setcc:i32 GRRegs:i32:$lhs, GRRegs:i32:$rhs, SETGE:Other), (bb:Other):$dst) - Complexity = 6
                  // Dst: (BRFF_lru6 (LSS_3r:i32 GRRegs:i32:$lhs, GRRegs:i32:$rhs), (bb:Other):$dst)
/*2718*/        /*Scope*/ 29, /*->2748*/
/*2719*/          OPC_CheckCondCode, ISD::SETUGE,
/*2721*/          OPC_MoveParent,
/*2722*/          OPC_MoveParent,
/*2723*/          OPC_RecordChild2, // #3 = $dst
/*2724*/          OPC_MoveChild, 2,
/*2726*/          OPC_CheckOpcode, TARGET_VAL(ISD::BasicBlock),
/*2729*/          OPC_MoveParent,
/*2730*/          OPC_EmitMergeInputChains1_0,
/*2731*/          OPC_EmitNode, TARGET_VAL(XCore::LSU_3r), 0,
                      1/*#VTs*/, MVT::i32, 2/*#Ops*/, 1, 2,  // Results = #4
/*2740*/          OPC_MorphNodeTo, TARGET_VAL(XCore::BRFF_lru6), 0|OPFL_Chain,
                      0/*#VTs*/, 2/*#Ops*/, 4, 3, 
                  // Src: (brcond (setcc:i32 GRRegs:i32:$lhs, GRRegs:i32:$rhs, SETUGE:Other), (bb:Other):$dst) - Complexity = 6
                  // Dst: (BRFF_lru6 (LSU_3r:i32 GRRegs:i32:$lhs, GRRegs:i32:$rhs), (bb:Other):$dst)
/*2748*/        /*Scope*/ 29, /*->2778*/
/*2749*/          OPC_CheckCondCode, ISD::SETNE,
/*2751*/          OPC_MoveParent,
/*2752*/          OPC_MoveParent,
/*2753*/          OPC_RecordChild2, // #3 = $dst
/*2754*/          OPC_MoveChild, 2,
/*2756*/          OPC_CheckOpcode, TARGET_VAL(ISD::BasicBlock),
/*2759*/          OPC_MoveParent,
/*2760*/          OPC_EmitMergeInputChains1_0,
/*2761*/          OPC_EmitNode, TARGET_VAL(XCore::EQ_3r), 0,
                      1/*#VTs*/, MVT::i32, 2/*#Ops*/, 1, 2,  // Results = #4
/*2770*/          OPC_MorphNodeTo, TARGET_VAL(XCore::BRFF_lru6), 0|OPFL_Chain,
                      0/*#VTs*/, 2/*#Ops*/, 4, 3, 
                  // Src: (brcond (setcc:i32 GRRegs:i32:$lhs, GRRegs:i32:$rhs, SETNE:Other), (bb:Other):$dst) - Complexity = 6
                  // Dst: (BRFF_lru6 (EQ_3r:i32 GRRegs:i32:$lhs, GRRegs:i32:$rhs), (bb:Other):$dst)
/*2778*/        0, /*End of Scope*/
/*2779*/      0, /*End of Scope*/
/*2780*/    /*Scope*/ 17, /*->2798*/
/*2781*/      OPC_RecordChild1, // #1 = $cond
/*2782*/      OPC_RecordChild2, // #2 = $addr
/*2783*/      OPC_MoveChild, 2,
/*2785*/      OPC_CheckOpcode, TARGET_VAL(ISD::BasicBlock),
/*2788*/      OPC_MoveParent,
/*2789*/      OPC_EmitMergeInputChains1_0,
/*2790*/      OPC_MorphNodeTo, TARGET_VAL(XCore::BRFT_lru6), 0|OPFL_Chain,
                  0/*#VTs*/, 2/*#Ops*/, 1, 2, 
              // Src: (brcond GRRegs:i32:$cond, (bb:Other):$addr) - Complexity = 3
              // Dst: (BRFT_lru6 GRRegs:i32:$cond, (bb:Other):$addr)
/*2798*/    0, /*End of Scope*/
/*2799*/  /*SwitchOpcode*/ 89|128,2/*345*/,  TARGET_VAL(ISD::SELECT),// ->3148
/*2803*/    OPC_Scope, 69|128,2/*325*/, /*->3131*/ // 2 children in Scope
/*2806*/      OPC_MoveChild, 0,
/*2808*/      OPC_CheckOpcode, TARGET_VAL(ISD::SETCC),
/*2811*/      OPC_RecordChild0, // #0 = $lhs
/*2812*/      OPC_Scope, 126, /*->2940*/ // 3 children in Scope
/*2814*/        OPC_MoveChild, 1,
/*2816*/        OPC_Scope, 76, /*->2894*/ // 2 children in Scope
/*2818*/          OPC_CheckInteger, 0, 
/*2820*/          OPC_MoveParent,
/*2821*/          OPC_MoveChild, 2,
/*2823*/          OPC_Scope, 18, /*->2843*/ // 3 children in Scope
/*2825*/            OPC_CheckCondCode, ISD::SETNE,
/*2827*/            OPC_MoveParent,
/*2828*/            OPC_MoveParent,
/*2829*/            OPC_RecordChild1, // #1 = $T
/*2830*/            OPC_RecordChild2, // #2 = $F
/*2831*/            OPC_CheckType, MVT::i32,
/*2833*/            OPC_MorphNodeTo, TARGET_VAL(XCore::SELECT_CC), 0,
                        1/*#VTs*/, MVT::i32, 3/*#Ops*/, 0, 1, 2, 
                    // Src: (select:i32 (setcc:i32 GRRegs:i32:$lhs, 0:i32, SETNE:Other), GRRegs:i32:$T, GRRegs:i32:$F) - Complexity = 11
                    // Dst: (SELECT_CC:i32 GRRegs:i32:$lhs, GRRegs:i32:$T, GRRegs:i32:$F)
/*2843*/          /*Scope*/ 18, /*->2862*/
/*2844*/            OPC_CheckCondCode, ISD::SETEQ,
/*2846*/            OPC_MoveParent,
/*2847*/            OPC_MoveParent,
/*2848*/            OPC_RecordChild1, // #1 = $T
/*2849*/            OPC_RecordChild2, // #2 = $F
/*2850*/            OPC_CheckType, MVT::i32,
/*2852*/            OPC_MorphNodeTo, TARGET_VAL(XCore::SELECT_CC), 0,
                        1/*#VTs*/, MVT::i32, 3/*#Ops*/, 0, 2, 1, 
                    // Src: (select:i32 (setcc:i32 GRRegs:i32:$lhs, 0:i32, SETEQ:Other), GRRegs:i32:$T, GRRegs:i32:$F) - Complexity = 11
                    // Dst: (SELECT_CC:i32 GRRegs:i32:$lhs, GRRegs:i32:$F, GRRegs:i32:$T)
/*2862*/          /*Scope*/ 30, /*->2893*/
/*2863*/            OPC_CheckCondCode, ISD::SETLT,
/*2865*/            OPC_MoveParent,
/*2866*/            OPC_MoveParent,
/*2867*/            OPC_RecordChild1, // #1 = $T
/*2868*/            OPC_RecordChild2, // #2 = $F
/*2869*/            OPC_CheckType, MVT::i32,
/*2871*/            OPC_EmitInteger, MVT::i32, 32, 
/*2874*/            OPC_EmitNode, TARGET_VAL(XCore::ASHR_l2rus), 0,
                        1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 3,  // Results = #4
/*2883*/            OPC_MorphNodeTo, TARGET_VAL(XCore::SELECT_CC), 0,
                        1/*#VTs*/, MVT::i32, 3/*#Ops*/, 4, 1, 2, 
                    // Src: (select:i32 (setcc:i32 GRRegs:i32:$lhs, 0:i32, SETLT:Other), GRRegs:i32:$T, GRRegs:i32:$F) - Complexity = 11
                    // Dst: (SELECT_CC:i32 (ASHR_l2rus:i32 GRRegs:i32:$lhs, 32:i32), GRRegs:i32:$T, GRRegs:i32:$F)
/*2893*/          0, /*End of Scope*/
/*2894*/        /*Scope*/ 44, /*->2939*/
/*2895*/          OPC_CheckInteger, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*2906*/          OPC_MoveParent,
/*2907*/          OPC_MoveChild, 2,
/*2909*/          OPC_CheckCondCode, ISD::SETGT,
/*2911*/          OPC_MoveParent,
/*2912*/          OPC_MoveParent,
/*2913*/          OPC_RecordChild1, // #1 = $T
/*2914*/          OPC_RecordChild2, // #2 = $F
/*2915*/          OPC_CheckType, MVT::i32,
/*2917*/          OPC_EmitInteger, MVT::i32, 32, 
/*2920*/          OPC_EmitNode, TARGET_VAL(XCore::ASHR_l2rus), 0,
                      1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 3,  // Results = #4
/*2929*/          OPC_MorphNodeTo, TARGET_VAL(XCore::SELECT_CC), 0,
                      1/*#VTs*/, MVT::i32, 3/*#Ops*/, 4, 2, 1, 
                  // Src: (select:i32 (setcc:i32 GRRegs:i32:$lhs, -1:i32, SETGT:Other), GRRegs:i32:$T, GRRegs:i32:$F) - Complexity = 11
                  // Dst: (SELECT_CC:i32 (ASHR_l2rus:i32 GRRegs:i32:$lhs, 32:i32), GRRegs:i32:$F, GRRegs:i32:$T)
/*2939*/        0, /*End of Scope*/
/*2940*/      /*Scope*/ 40, /*->2981*/
/*2941*/        OPC_RecordChild1, // #1 = $rhs
/*2942*/        OPC_MoveChild, 1,
/*2944*/        OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*2947*/        OPC_CheckPredicate, 0, // Predicate_immUs
/*2949*/        OPC_MoveParent,
/*2950*/        OPC_MoveChild, 2,
/*2952*/        OPC_CheckCondCode, ISD::SETNE,
/*2954*/        OPC_MoveParent,
/*2955*/        OPC_MoveParent,
/*2956*/        OPC_RecordChild1, // #2 = $T
/*2957*/        OPC_RecordChild2, // #3 = $F
/*2958*/        OPC_CheckType, MVT::i32,
/*2960*/        OPC_EmitConvertToTarget, 1,
/*2962*/        OPC_EmitNode, TARGET_VAL(XCore::EQ_2rus), 0,
                    1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 4,  // Results = #5
/*2971*/        OPC_MorphNodeTo, TARGET_VAL(XCore::SELECT_CC), 0,
                    1/*#VTs*/, MVT::i32, 3/*#Ops*/, 5, 3, 2, 
                // Src: (select:i32 (setcc:i32 GRRegs:i32:$lhs, (imm:i32)<<P:Predicate_immUs>>:$rhs, SETNE:Other), GRRegs:i32:$T, GRRegs:i32:$F) - Complexity = 10
                // Dst: (SELECT_CC:i32 (EQ_2rus:i32 GRRegs:i32:$lhs, (imm:i32)<<P:Predicate_immUs>>:$rhs), GRRegs:i32:$F, GRRegs:i32:$T)
/*2981*/      /*Scope*/ 19|128,1/*147*/, /*->3130*/
/*2983*/        OPC_CheckChild0Type, MVT::i32,
/*2985*/        OPC_RecordChild1, // #1 = $rhs
/*2986*/        OPC_MoveChild, 2,
/*2988*/        OPC_Scope, 27, /*->3017*/ // 5 children in Scope
/*2990*/          OPC_CheckCondCode, ISD::SETLE,
/*2992*/          OPC_MoveParent,
/*2993*/          OPC_MoveParent,
/*2994*/          OPC_RecordChild1, // #2 = $T
/*2995*/          OPC_RecordChild2, // #3 = $F
/*2996*/          OPC_CheckType, MVT::i32,
/*2998*/          OPC_EmitNode, TARGET_VAL(XCore::LSS_3r), 0,
                      1/*#VTs*/, MVT::i32, 2/*#Ops*/, 1, 0,  // Results = #4
/*3007*/          OPC_MorphNodeTo, TARGET_VAL(XCore::SELECT_CC), 0,
                      1/*#VTs*/, MVT::i32, 3/*#Ops*/, 4, 3, 2, 
                  // Src: (select:i32 (setcc:i32 GRRegs:i32:$lhs, GRRegs:i32:$rhs, SETLE:Other), GRRegs:i32:$T, GRRegs:i32:$F) - Complexity = 6
                  // Dst: (SELECT_CC:i32 (LSS_3r:i32 GRRegs:i32:$rhs, GRRegs:i32:$lhs), GRRegs:i32:$F, GRRegs:i32:$T)
/*3017*/        /*Scope*/ 27, /*->3045*/
/*3018*/          OPC_CheckCondCode, ISD::SETULE,
/*3020*/          OPC_MoveParent,
/*3021*/          OPC_MoveParent,
/*3022*/          OPC_RecordChild1, // #2 = $T
/*3023*/          OPC_RecordChild2, // #3 = $F
/*3024*/          OPC_CheckType, MVT::i32,
/*3026*/          OPC_EmitNode, TARGET_VAL(XCore::LSU_3r), 0,
                      1/*#VTs*/, MVT::i32, 2/*#Ops*/, 1, 0,  // Results = #4
/*3035*/          OPC_MorphNodeTo, TARGET_VAL(XCore::SELECT_CC), 0,
                      1/*#VTs*/, MVT::i32, 3/*#Ops*/, 4, 3, 2, 
                  // Src: (select:i32 (setcc:i32 GRRegs:i32:$lhs, GRRegs:i32:$rhs, SETULE:Other), GRRegs:i32:$T, GRRegs:i32:$F) - Complexity = 6
                  // Dst: (SELECT_CC:i32 (LSU_3r:i32 GRRegs:i32:$rhs, GRRegs:i32:$lhs), GRRegs:i32:$F, GRRegs:i32:$T)
/*3045*/        /*Scope*/ 27, /*->3073*/
/*3046*/          OPC_CheckCondCode, ISD::SETGE,
/*3048*/          OPC_MoveParent,
/*3049*/          OPC_MoveParent,
/*3050*/          OPC_RecordChild1, // #2 = $T
/*3051*/          OPC_RecordChild2, // #3 = $F
/*3052*/          OPC_CheckType, MVT::i32,
/*3054*/          OPC_EmitNode, TARGET_VAL(XCore::LSS_3r), 0,
                      1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1,  // Results = #4
/*3063*/          OPC_MorphNodeTo, TARGET_VAL(XCore::SELECT_CC), 0,
                      1/*#VTs*/, MVT::i32, 3/*#Ops*/, 4, 3, 2, 
                  // Src: (select:i32 (setcc:i32 GRRegs:i32:$lhs, GRRegs:i32:$rhs, SETGE:Other), GRRegs:i32:$T, GRRegs:i32:$F) - Complexity = 6
                  // Dst: (SELECT_CC:i32 (LSS_3r:i32 GRRegs:i32:$lhs, GRRegs:i32:$rhs), GRRegs:i32:$F, GRRegs:i32:$T)
/*3073*/        /*Scope*/ 27, /*->3101*/
/*3074*/          OPC_CheckCondCode, ISD::SETUGE,
/*3076*/          OPC_MoveParent,
/*3077*/          OPC_MoveParent,
/*3078*/          OPC_RecordChild1, // #2 = $T
/*3079*/          OPC_RecordChild2, // #3 = $F
/*3080*/          OPC_CheckType, MVT::i32,
/*3082*/          OPC_EmitNode, TARGET_VAL(XCore::LSU_3r), 0,
                      1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1,  // Results = #4
/*3091*/          OPC_MorphNodeTo, TARGET_VAL(XCore::SELECT_CC), 0,
                      1/*#VTs*/, MVT::i32, 3/*#Ops*/, 4, 3, 2, 
                  // Src: (select:i32 (setcc:i32 GRRegs:i32:$lhs, GRRegs:i32:$rhs, SETUGE:Other), GRRegs:i32:$T, GRRegs:i32:$F) - Complexity = 6
                  // Dst: (SELECT_CC:i32 (LSU_3r:i32 GRRegs:i32:$lhs, GRRegs:i32:$rhs), GRRegs:i32:$F, GRRegs:i32:$T)
/*3101*/        /*Scope*/ 27, /*->3129*/
/*3102*/          OPC_CheckCondCode, ISD::SETNE,
/*3104*/          OPC_MoveParent,
/*3105*/          OPC_MoveParent,
/*3106*/          OPC_RecordChild1, // #2 = $T
/*3107*/          OPC_RecordChild2, // #3 = $F
/*3108*/          OPC_CheckType, MVT::i32,
/*3110*/          OPC_EmitNode, TARGET_VAL(XCore::EQ_3r), 0,
                      1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1,  // Results = #4
/*3119*/          OPC_MorphNodeTo, TARGET_VAL(XCore::SELECT_CC), 0,
                      1/*#VTs*/, MVT::i32, 3/*#Ops*/, 4, 3, 2, 
                  // Src: (select:i32 (setcc:i32 GRRegs:i32:$lhs, GRRegs:i32:$rhs, SETNE:Other), GRRegs:i32:$T, GRRegs:i32:$F) - Complexity = 6
                  // Dst: (SELECT_CC:i32 (EQ_3r:i32 GRRegs:i32:$lhs, GRRegs:i32:$rhs), GRRegs:i32:$F, GRRegs:i32:$T)
/*3129*/        0, /*End of Scope*/
/*3130*/      0, /*End of Scope*/
/*3131*/    /*Scope*/ 15, /*->3147*/
/*3132*/      OPC_RecordChild0, // #0 = $cond
/*3133*/      OPC_RecordChild1, // #1 = $T
/*3134*/      OPC_RecordChild2, // #2 = $F
/*3135*/      OPC_CheckType, MVT::i32,
/*3137*/      OPC_MorphNodeTo, TARGET_VAL(XCore::SELECT_CC), 0,
                  1/*#VTs*/, MVT::i32, 3/*#Ops*/, 0, 1, 2, 
              // Src: (select:i32 GRRegs:i32:$cond, GRRegs:i32:$T, GRRegs:i32:$F) - Complexity = 3
              // Dst: (SELECT_CC:i32 GRRegs:i32:$cond, GRRegs:i32:$T, GRRegs:i32:$F)
/*3147*/    0, /*End of Scope*/
/*3148*/  /*SwitchOpcode*/ 26,  TARGET_VAL(ISD::CALLSEQ_END),// ->3177
/*3151*/    OPC_RecordNode,   // #0 = 'callseq_end' chained node
/*3152*/    OPC_CaptureGlueInput,
/*3153*/    OPC_RecordChild1, // #1 = $amt1
/*3154*/    OPC_MoveChild, 1,
/*3156*/    OPC_CheckOpcode, TARGET_VAL(ISD::TargetConstant),
/*3159*/    OPC_MoveParent,
/*3160*/    OPC_RecordChild2, // #2 = $amt2
/*3161*/    OPC_MoveChild, 2,
/*3163*/    OPC_CheckOpcode, TARGET_VAL(ISD::TargetConstant),
/*3166*/    OPC_MoveParent,
/*3167*/    OPC_EmitMergeInputChains1_0,
/*3168*/    OPC_MorphNodeTo, TARGET_VAL(XCore::ADJCALLSTACKUP), 0|OPFL_Chain|OPFL_GlueInput|OPFL_GlueOutput,
                1/*#VTs*/, MVT::i32, 2/*#Ops*/, 1, 2, 
            // Src: (callseq_end (timm:i32):$amt1, (timm:i32):$amt2) - Complexity = 9
            // Dst: (ADJCALLSTACKUP:i32 (timm:i32):$amt1, (timm:i32):$amt2)
/*3177*/  /*SwitchOpcode*/ 15,  TARGET_VAL(ISD::FrameIndex),// ->3195
/*3180*/    OPC_RecordNode,   // #0 = $addr
/*3181*/    OPC_CheckType, MVT::i32,
/*3183*/    OPC_CheckComplexPat, /*CP*/0, /*#*/0, // SelectADDRspii:$addr #1 #2
/*3186*/    OPC_MorphNodeTo, TARGET_VAL(XCore::LDAWFI), 0,
                1/*#VTs*/, MVT::i32, 2/*#Ops*/, 1, 2, 
            // Src: ADDRspii:i32:$addr - Complexity = 9
            // Dst: (LDAWFI:i32 ADDRspii:i32:$addr)
/*3195*/  /*SwitchOpcode*/ 37,  TARGET_VAL(ISD::XOR),// ->3235
/*3198*/    OPC_RecordChild0, // #0 = $b
/*3199*/    OPC_Scope, 22, /*->3223*/ // 2 children in Scope
/*3201*/      OPC_MoveChild, 1,
/*3203*/      OPC_CheckInteger, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*3214*/      OPC_MoveParent,
/*3215*/      OPC_MorphNodeTo, TARGET_VAL(XCore::NOT), 0,
                  1/*#VTs*/, MVT::i32, 1/*#Ops*/, 0, 
              // Src: (xor:i32 GRRegs:i32:$b, -1:i32) - Complexity = 8
              // Dst: (NOT:i32 GRRegs:i32:$b)
/*3223*/    /*Scope*/ 10, /*->3234*/
/*3224*/      OPC_RecordChild1, // #1 = $c
/*3225*/      OPC_MorphNodeTo, TARGET_VAL(XCore::XOR_l3r), 0,
                  1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1, 
              // Src: (xor:i32 GRRegs:i32:$b, GRRegs:i32:$c) - Complexity = 3
              // Dst: (XOR_l3r:i32 GRRegs:i32:$b, GRRegs:i32:$c)
/*3234*/    0, /*End of Scope*/
/*3235*/  /*SwitchOpcode*/ 67,  TARGET_VAL(ISD::MUL),// ->3305
/*3238*/    OPC_RecordChild0, // #0 = $src
/*3239*/    OPC_Scope, 52, /*->3293*/ // 2 children in Scope
/*3241*/      OPC_MoveChild, 1,
/*3243*/      OPC_Scope, 12, /*->3257*/ // 3 children in Scope
/*3245*/        OPC_CheckInteger, 3, 
/*3247*/        OPC_MoveParent,
/*3248*/        OPC_MorphNodeTo, TARGET_VAL(XCore::LDA16F_l3r), 0,
                    1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 0, 
                // Src: (mul:i32 GRRegs:i32:$src, 3:i32) - Complexity = 8
                // Dst: (LDA16F_l3r:i32 GRRegs:i32:$src, GRRegs:i32:$src)
/*3257*/      /*Scope*/ 12, /*->3270*/
/*3258*/        OPC_CheckInteger, 5, 
/*3260*/        OPC_MoveParent,
/*3261*/        OPC_MorphNodeTo, TARGET_VAL(XCore::LDAWF_l3r), 0,
                    1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 0, 
                // Src: (mul:i32 GRRegs:i32:$src, 5:i32) - Complexity = 8
                // Dst: (LDAWF_l3r:i32 GRRegs:i32:$src, GRRegs:i32:$src)
/*3270*/      /*Scope*/ 21, /*->3292*/
/*3271*/        OPC_CheckInteger, 125|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551613*/, 
/*3282*/        OPC_MoveParent,
/*3283*/        OPC_MorphNodeTo, TARGET_VAL(XCore::LDAWB_l3r), 0,
                    1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 0, 
                // Src: (mul:i32 GRRegs:i32:$src, -3:i32) - Complexity = 8
                // Dst: (LDAWB_l3r:i32 GRRegs:i32:$src, GRRegs:i32:$src)
/*3292*/      0, /*End of Scope*/
/*3293*/    /*Scope*/ 10, /*->3304*/
/*3294*/      OPC_RecordChild1, // #1 = $c
/*3295*/      OPC_MorphNodeTo, TARGET_VAL(XCore::MUL_l3r), 0,
                  1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1, 
              // Src: (mul:i32 GRRegs:i32:$b, GRRegs:i32:$c) - Complexity = 3
              // Dst: (MUL_l3r:i32 GRRegs:i32:$b, GRRegs:i32:$c)
/*3304*/    0, /*End of Scope*/
/*3305*/  /*SwitchOpcode*/ 46|128,2/*302*/,  TARGET_VAL(ISD::SETCC),// ->3611
/*3309*/    OPC_RecordChild0, // #0 = $lhs
/*3310*/    OPC_Scope, 43, /*->3355*/ // 3 children in Scope
/*3312*/      OPC_MoveChild, 1,
/*3314*/      OPC_CheckInteger, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*3325*/      OPC_MoveParent,
/*3326*/      OPC_MoveChild, 2,
/*3328*/      OPC_CheckCondCode, ISD::SETGT,
/*3330*/      OPC_MoveParent,
/*3331*/      OPC_EmitInteger, MVT::i32, 32, 
/*3334*/      OPC_EmitNode, TARGET_VAL(XCore::ASHR_l2rus), 0,
                  1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1,  // Results = #2
/*3343*/      OPC_EmitInteger, MVT::i32, 0, 
/*3346*/      OPC_MorphNodeTo, TARGET_VAL(XCore::EQ_2rus), 0,
                  1/*#VTs*/, MVT::i32, 2/*#Ops*/, 2, 3, 
              // Src: (setcc:i32 GRRegs:i32:$lhs, -1:i32, SETGT:Other) - Complexity = 8
              // Dst: (EQ_2rus:i32 (ASHR_l2rus:i32 GRRegs:i32:$lhs, 32:i32), 0:i32)
/*3355*/    /*Scope*/ 55, /*->3411*/
/*3356*/      OPC_RecordChild1, // #1 = $rhs
/*3357*/      OPC_MoveChild, 1,
/*3359*/      OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*3362*/      OPC_CheckPredicate, 0, // Predicate_immUs
/*3364*/      OPC_MoveParent,
/*3365*/      OPC_MoveChild, 2,
/*3367*/      OPC_Scope, 14, /*->3383*/ // 2 children in Scope
/*3369*/        OPC_CheckCondCode, ISD::SETEQ,
/*3371*/        OPC_MoveParent,
/*3372*/        OPC_EmitConvertToTarget, 1,
/*3374*/        OPC_MorphNodeTo, TARGET_VAL(XCore::EQ_2rus), 0,
                    1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 2, 
                // Src: (setcc:i32 GRRegs:i32:$lhs, (imm:i32)<<P:Predicate_immUs>>:$rhs, SETEQ:Other) - Complexity = 7
                // Dst: (EQ_2rus:i32 GRRegs:i32:$lhs, (imm:i32)<<P:Predicate_immUs>>:$rhs)
/*3383*/      /*Scope*/ 26, /*->3410*/
/*3384*/        OPC_CheckCondCode, ISD::SETNE,
/*3386*/        OPC_MoveParent,
/*3387*/        OPC_EmitConvertToTarget, 1,
/*3389*/        OPC_EmitNode, TARGET_VAL(XCore::EQ_2rus), 0,
                    1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 2,  // Results = #3
/*3398*/        OPC_EmitInteger, MVT::i32, 0, 
/*3401*/        OPC_MorphNodeTo, TARGET_VAL(XCore::EQ_2rus), 0,
                    1/*#VTs*/, MVT::i32, 2/*#Ops*/, 3, 4, 
                // Src: (setcc:i32 GRRegs:i32:$lhs, (imm:i32)<<P:Predicate_immUs>>:$rhs, SETNE:Other) - Complexity = 7
                // Dst: (EQ_2rus:i32 (EQ_2rus:i32 GRRegs:i32:$lhs, (imm:i32)<<P:Predicate_immUs>>:$rhs), 0:i32)
/*3410*/      0, /*End of Scope*/
/*3411*/    /*Scope*/ 69|128,1/*197*/, /*->3610*/
/*3413*/      OPC_CheckChild0Type, MVT::i32,
/*3415*/      OPC_RecordChild1, // #1 = $rhs
/*3416*/      OPC_MoveChild, 2,
/*3418*/      OPC_Scope, 12, /*->3432*/ // 10 children in Scope
/*3420*/        OPC_CheckCondCode, ISD::SETGT,
/*3422*/        OPC_MoveParent,
/*3423*/        OPC_MorphNodeTo, TARGET_VAL(XCore::LSS_3r), 0,
                    1/*#VTs*/, MVT::i32, 2/*#Ops*/, 1, 0, 
                // Src: (setcc:i32 GRRegs:i32:$lhs, GRRegs:i32:$rhs, SETGT:Other) - Complexity = 3
                // Dst: (LSS_3r:i32 GRRegs:i32:$rhs, GRRegs:i32:$lhs)
/*3432*/      /*Scope*/ 12, /*->3445*/
/*3433*/        OPC_CheckCondCode, ISD::SETUGT,
/*3435*/        OPC_MoveParent,
/*3436*/        OPC_MorphNodeTo, TARGET_VAL(XCore::LSU_3r), 0,
                    1/*#VTs*/, MVT::i32, 2/*#Ops*/, 1, 0, 
                // Src: (setcc:i32 GRRegs:i32:$lhs, GRRegs:i32:$rhs, SETUGT:Other) - Complexity = 3
                // Dst: (LSU_3r:i32 GRRegs:i32:$rhs, GRRegs:i32:$lhs)
/*3445*/      /*Scope*/ 12, /*->3458*/
/*3446*/        OPC_CheckCondCode, ISD::SETLT,
/*3448*/        OPC_MoveParent,
/*3449*/        OPC_MorphNodeTo, TARGET_VAL(XCore::LSS_3r), 0,
                    1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1, 
                // Src: (setcc:i32 GRRegs:i32:$lhs, GRRegs:i32:$rhs, SETLT:Other) - Complexity = 3
                // Dst: (LSS_3r:i32 GRRegs:i32:$lhs, GRRegs:i32:$rhs)
/*3458*/      /*Scope*/ 12, /*->3471*/
/*3459*/        OPC_CheckCondCode, ISD::SETULT,
/*3461*/        OPC_MoveParent,
/*3462*/        OPC_MorphNodeTo, TARGET_VAL(XCore::LSU_3r), 0,
                    1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1, 
                // Src: (setcc:i32 GRRegs:i32:$lhs, GRRegs:i32:$rhs, SETULT:Other) - Complexity = 3
                // Dst: (LSU_3r:i32 GRRegs:i32:$lhs, GRRegs:i32:$rhs)
/*3471*/      /*Scope*/ 12, /*->3484*/
/*3472*/        OPC_CheckCondCode, ISD::SETEQ,
/*3474*/        OPC_MoveParent,
/*3475*/        OPC_MorphNodeTo, TARGET_VAL(XCore::EQ_3r), 0,
                    1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1, 
                // Src: (setcc:i32 GRRegs:i32:$lhs, GRRegs:i32:$rhs, SETEQ:Other) - Complexity = 3
                // Dst: (EQ_3r:i32 GRRegs:i32:$lhs, GRRegs:i32:$rhs)
/*3484*/      /*Scope*/ 24, /*->3509*/
/*3485*/        OPC_CheckCondCode, ISD::SETLE,
/*3487*/        OPC_MoveParent,
/*3488*/        OPC_EmitNode, TARGET_VAL(XCore::LSS_3r), 0,
                    1/*#VTs*/, MVT::i32, 2/*#Ops*/, 1, 0,  // Results = #2
/*3497*/        OPC_EmitInteger, MVT::i32, 0, 
/*3500*/        OPC_MorphNodeTo, TARGET_VAL(XCore::EQ_2rus), 0,
                    1/*#VTs*/, MVT::i32, 2/*#Ops*/, 2, 3, 
                // Src: (setcc:i32 GRRegs:i32:$lhs, GRRegs:i32:$rhs, SETLE:Other) - Complexity = 3
                // Dst: (EQ_2rus:i32 (LSS_3r:i32 GRRegs:i32:$rhs, GRRegs:i32:$lhs), 0:i32)
/*3509*/      /*Scope*/ 24, /*->3534*/
/*3510*/        OPC_CheckCondCode, ISD::SETULE,
/*3512*/        OPC_MoveParent,
/*3513*/        OPC_EmitNode, TARGET_VAL(XCore::LSU_3r), 0,
                    1/*#VTs*/, MVT::i32, 2/*#Ops*/, 1, 0,  // Results = #2
/*3522*/        OPC_EmitInteger, MVT::i32, 0, 
/*3525*/        OPC_MorphNodeTo, TARGET_VAL(XCore::EQ_2rus), 0,
                    1/*#VTs*/, MVT::i32, 2/*#Ops*/, 2, 3, 
                // Src: (setcc:i32 GRRegs:i32:$lhs, GRRegs:i32:$rhs, SETULE:Other) - Complexity = 3
                // Dst: (EQ_2rus:i32 (LSU_3r:i32 GRRegs:i32:$rhs, GRRegs:i32:$lhs), 0:i32)
/*3534*/      /*Scope*/ 24, /*->3559*/
/*3535*/        OPC_CheckCondCode, ISD::SETGE,
/*3537*/        OPC_MoveParent,
/*3538*/        OPC_EmitNode, TARGET_VAL(XCore::LSS_3r), 0,
                    1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1,  // Results = #2
/*3547*/        OPC_EmitInteger, MVT::i32, 0, 
/*3550*/        OPC_MorphNodeTo, TARGET_VAL(XCore::EQ_2rus), 0,
                    1/*#VTs*/, MVT::i32, 2/*#Ops*/, 2, 3, 
                // Src: (setcc:i32 GRRegs:i32:$lhs, GRRegs:i32:$rhs, SETGE:Other) - Complexity = 3
                // Dst: (EQ_2rus:i32 (LSS_3r:i32 GRRegs:i32:$lhs, GRRegs:i32:$rhs), 0:i32)
/*3559*/      /*Scope*/ 24, /*->3584*/
/*3560*/        OPC_CheckCondCode, ISD::SETUGE,
/*3562*/        OPC_MoveParent,
/*3563*/        OPC_EmitNode, TARGET_VAL(XCore::LSU_3r), 0,
                    1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1,  // Results = #2
/*3572*/        OPC_EmitInteger, MVT::i32, 0, 
/*3575*/        OPC_MorphNodeTo, TARGET_VAL(XCore::EQ_2rus), 0,
                    1/*#VTs*/, MVT::i32, 2/*#Ops*/, 2, 3, 
                // Src: (setcc:i32 GRRegs:i32:$lhs, GRRegs:i32:$rhs, SETUGE:Other) - Complexity = 3
                // Dst: (EQ_2rus:i32 (LSU_3r:i32 GRRegs:i32:$lhs, GRRegs:i32:$rhs), 0:i32)
/*3584*/      /*Scope*/ 24, /*->3609*/
/*3585*/        OPC_CheckCondCode, ISD::SETNE,
/*3587*/        OPC_MoveParent,
/*3588*/        OPC_EmitNode, TARGET_VAL(XCore::EQ_3r), 0,
                    1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1,  // Results = #2
/*3597*/        OPC_EmitInteger, MVT::i32, 0, 
/*3600*/        OPC_MorphNodeTo, TARGET_VAL(XCore::EQ_2rus), 0,
                    1/*#VTs*/, MVT::i32, 2/*#Ops*/, 2, 3, 
                // Src: (setcc:i32 GRRegs:i32:$lhs, GRRegs:i32:$rhs, SETNE:Other) - Complexity = 3
                // Dst: (EQ_2rus:i32 (EQ_3r:i32 GRRegs:i32:$lhs, GRRegs:i32:$rhs), 0:i32)
/*3609*/      0, /*End of Scope*/
/*3610*/    0, /*End of Scope*/
/*3611*/  /*SwitchOpcode*/ 34,  TARGET_VAL(ISD::SHL),// ->3648
/*3614*/    OPC_RecordChild0, // #0 = $b
/*3615*/    OPC_RecordChild1, // #1 = $c
/*3616*/    OPC_Scope, 19, /*->3637*/ // 2 children in Scope
/*3618*/      OPC_MoveChild, 1,
/*3620*/      OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*3623*/      OPC_CheckPredicate, 19, // Predicate_immBitp
/*3625*/      OPC_MoveParent,
/*3626*/      OPC_EmitConvertToTarget, 1,
/*3628*/      OPC_MorphNodeTo, TARGET_VAL(XCore::SHL_2rus), 0,
                  1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 2, 
              // Src: (shl:i32 GRRegs:i32:$b, (imm:i32)<<P:Predicate_immBitp>>:$c) - Complexity = 7
              // Dst: (SHL_2rus:i32 GRRegs:i32:$b, (imm:i32):$c)
/*3637*/    /*Scope*/ 9, /*->3647*/
/*3638*/      OPC_MorphNodeTo, TARGET_VAL(XCore::SHL_3r), 0,
                  1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1, 
              // Src: (shl:i32 GRRegs:i32:$b, GRRegs:i32:$c) - Complexity = 3
              // Dst: (SHL_3r:i32 GRRegs:i32:$b, GRRegs:i32:$c)
/*3647*/    0, /*End of Scope*/
/*3648*/  /*SwitchOpcode*/ 34,  TARGET_VAL(ISD::SRL),// ->3685
/*3651*/    OPC_RecordChild0, // #0 = $b
/*3652*/    OPC_RecordChild1, // #1 = $c
/*3653*/    OPC_Scope, 19, /*->3674*/ // 2 children in Scope
/*3655*/      OPC_MoveChild, 1,
/*3657*/      OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*3660*/      OPC_CheckPredicate, 19, // Predicate_immBitp
/*3662*/      OPC_MoveParent,
/*3663*/      OPC_EmitConvertToTarget, 1,
/*3665*/      OPC_MorphNodeTo, TARGET_VAL(XCore::SHR_2rus), 0,
                  1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 2, 
              // Src: (srl:i32 GRRegs:i32:$b, (imm:i32)<<P:Predicate_immBitp>>:$c) - Complexity = 7
              // Dst: (SHR_2rus:i32 GRRegs:i32:$b, (imm:i32):$c)
/*3674*/    /*Scope*/ 9, /*->3684*/
/*3675*/      OPC_MorphNodeTo, TARGET_VAL(XCore::SHR_3r), 0,
                  1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1, 
              // Src: (srl:i32 GRRegs:i32:$b, GRRegs:i32:$c) - Complexity = 3
              // Dst: (SHR_3r:i32 GRRegs:i32:$b, GRRegs:i32:$c)
/*3684*/    0, /*End of Scope*/
/*3685*/  /*SwitchOpcode*/ 42,  TARGET_VAL(XCoreISD::STWSP),// ->3730
/*3688*/    OPC_RecordNode,   // #0 = 'XCoreStwsp' chained node
/*3689*/    OPC_RecordChild1, // #1 = $a
/*3690*/    OPC_CheckChild1Type, MVT::i32,
/*3692*/    OPC_RecordChild2, // #2 = $b
/*3693*/    OPC_MoveChild, 2,
/*3695*/    OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*3698*/    OPC_Scope, 14, /*->3714*/ // 2 children in Scope
/*3700*/      OPC_CheckPredicate, 20, // Predicate_immU6
/*3702*/      OPC_MoveParent,
/*3703*/      OPC_EmitMergeInputChains1_0,
/*3704*/      OPC_EmitConvertToTarget, 2,
/*3706*/      OPC_MorphNodeTo, TARGET_VAL(XCore::STWSP_ru6), 0|OPFL_Chain,
                  0/*#VTs*/, 2/*#Ops*/, 1, 3, 
              // Src: (XCoreStwsp RRegs:i32:$a, (imm:i32)<<P:Predicate_immU6>>:$b) - Complexity = 7
              // Dst: (STWSP_ru6 RRegs:i32:$a, (imm:i32):$b)
/*3714*/    /*Scope*/ 14, /*->3729*/
/*3715*/      OPC_CheckPredicate, 21, // Predicate_immU16
/*3717*/      OPC_MoveParent,
/*3718*/      OPC_EmitMergeInputChains1_0,
/*3719*/      OPC_EmitConvertToTarget, 2,
/*3721*/      OPC_MorphNodeTo, TARGET_VAL(XCore::STWSP_lru6), 0|OPFL_Chain,
                  0/*#VTs*/, 2/*#Ops*/, 1, 3, 
              // Src: (XCoreStwsp RRegs:i32:$a, (imm:i32)<<P:Predicate_immU16>>:$b) - Complexity = 7
              // Dst: (STWSP_lru6 RRegs:i32:$a, (imm:i32):$b)
/*3729*/    0, /*End of Scope*/
/*3730*/  /*SwitchOpcode*/ 42,  TARGET_VAL(XCoreISD::RETSP),// ->3775
/*3733*/    OPC_RecordNode,   // #0 = 'XCoreRetsp' chained node
/*3734*/    OPC_CaptureGlueInput,
/*3735*/    OPC_RecordChild1, // #1 = $a
/*3736*/    OPC_MoveChild, 1,
/*3738*/    OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*3741*/    OPC_CheckType, MVT::i32,
/*3743*/    OPC_Scope, 14, /*->3759*/ // 2 children in Scope
/*3745*/      OPC_CheckPredicate, 20, // Predicate_immU6
/*3747*/      OPC_MoveParent,
/*3748*/      OPC_EmitMergeInputChains1_0,
/*3749*/      OPC_EmitConvertToTarget, 1,
/*3751*/      OPC_MorphNodeTo, TARGET_VAL(XCore::RETSP_u6), 0|OPFL_Chain|OPFL_GlueInput|OPFL_Variadic1,
                  1/*#VTs*/, MVT::i32, 1/*#Ops*/, 2, 
              // Src: (XCoreRetsp (imm:i32)<<P:Predicate_immU6>>:$a) - Complexity = 7
              // Dst: (RETSP_u6:i32 (imm:i32):$a)
/*3759*/    /*Scope*/ 14, /*->3774*/
/*3760*/      OPC_CheckPredicate, 21, // Predicate_immU16
/*3762*/      OPC_MoveParent,
/*3763*/      OPC_EmitMergeInputChains1_0,
/*3764*/      OPC_EmitConvertToTarget, 1,
/*3766*/      OPC_MorphNodeTo, TARGET_VAL(XCore::RETSP_lu6), 0|OPFL_Chain|OPFL_GlueInput|OPFL_Variadic1,
                  1/*#VTs*/, MVT::i32, 1/*#Ops*/, 2, 
              // Src: (XCoreRetsp (imm:i32)<<P:Predicate_immU16>>:$a) - Complexity = 7
              // Dst: (RETSP_lu6:i32 (imm:i32):$a)
/*3774*/    0, /*End of Scope*/
/*3775*/  /*SwitchOpcode*/ 85,  TARGET_VAL(XCoreISD::BL),// ->3863
/*3778*/    OPC_RecordNode,   // #0 = 'XCoreBranchLink' chained node
/*3779*/    OPC_CaptureGlueInput,
/*3780*/    OPC_RecordChild1, // #1 = $a
/*3781*/    OPC_Scope, 67, /*->3850*/ // 2 children in Scope
/*3783*/      OPC_MoveChild, 1,
/*3785*/      OPC_SwitchOpcode /*3 cases */, 34,  TARGET_VAL(ISD::Constant),// ->3823
/*3789*/        OPC_CheckType, MVT::i32,
/*3791*/        OPC_Scope, 14, /*->3807*/ // 2 children in Scope
/*3793*/          OPC_CheckPredicate, 23, // Predicate_immU10
/*3795*/          OPC_MoveParent,
/*3796*/          OPC_EmitMergeInputChains1_0,
/*3797*/          OPC_EmitConvertToTarget, 1,
/*3799*/          OPC_MorphNodeTo, TARGET_VAL(XCore::BLRF_u10), 0|OPFL_Chain|OPFL_GlueInput|OPFL_GlueOutput|OPFL_Variadic1,
                      1/*#VTs*/, MVT::i32, 1/*#Ops*/, 2, 
                  // Src: (XCoreBranchLink (imm:i32)<<P:Predicate_immU10>>:$a) - Complexity = 7
                  // Dst: (BLRF_u10:i32 (imm:i32):$a)
/*3807*/        /*Scope*/ 14, /*->3822*/
/*3808*/          OPC_CheckPredicate, 24, // Predicate_immU20
/*3810*/          OPC_MoveParent,
/*3811*/          OPC_EmitMergeInputChains1_0,
/*3812*/          OPC_EmitConvertToTarget, 1,
/*3814*/          OPC_MorphNodeTo, TARGET_VAL(XCore::BLRF_lu10), 0|OPFL_Chain|OPFL_GlueInput|OPFL_GlueOutput|OPFL_Variadic1,
                      1/*#VTs*/, MVT::i32, 1/*#Ops*/, 2, 
                  // Src: (XCoreBranchLink (imm:i32)<<P:Predicate_immU20>>:$a) - Complexity = 7
                  // Dst: (BLRF_lu10:i32 (imm:i32):$a)
/*3822*/        0, /*End of Scope*/
/*3823*/      /*SwitchOpcode*/ 10,  TARGET_VAL(ISD::TargetGlobalAddress),// ->3836
/*3826*/        OPC_MoveParent,
/*3827*/        OPC_EmitMergeInputChains1_0,
/*3828*/        OPC_MorphNodeTo, TARGET_VAL(XCore::BLRF_lu10), 0|OPFL_Chain|OPFL_GlueInput|OPFL_GlueOutput|OPFL_Variadic1,
                    1/*#VTs*/, MVT::i32, 1/*#Ops*/, 1, 
                // Src: (XCoreBranchLink (tglobaladdr:iPTR):$addr) - Complexity = 6
                // Dst: (BLRF_lu10:i32 (tglobaladdr:i32):$addr)
/*3836*/      /*SwitchOpcode*/ 10,  TARGET_VAL(ISD::TargetExternalSymbol),// ->3849
/*3839*/        OPC_MoveParent,
/*3840*/        OPC_EmitMergeInputChains1_0,
/*3841*/        OPC_MorphNodeTo, TARGET_VAL(XCore::BLRF_lu10), 0|OPFL_Chain|OPFL_GlueInput|OPFL_GlueOutput|OPFL_Variadic1,
                    1/*#VTs*/, MVT::i32, 1/*#Ops*/, 1, 
                // Src: (XCoreBranchLink (texternalsym:iPTR):$addr) - Complexity = 6
                // Dst: (BLRF_lu10:i32 (texternalsym:i32):$addr)
/*3849*/      0, // EndSwitchOpcode
/*3850*/    /*Scope*/ 11, /*->3862*/
/*3851*/      OPC_CheckChild1Type, MVT::i32,
/*3853*/      OPC_EmitMergeInputChains1_0,
/*3854*/      OPC_MorphNodeTo, TARGET_VAL(XCore::BLA_1r), 0|OPFL_Chain|OPFL_GlueInput|OPFL_GlueOutput|OPFL_Variadic1,
                  1/*#VTs*/, MVT::i32, 1/*#Ops*/, 1, 
              // Src: (XCoreBranchLink GRRegs:i32:$a) - Complexity = 3
              // Dst: (BLA_1r:i32 GRRegs:i32:$a)
/*3862*/    0, /*End of Scope*/
/*3863*/  /*SwitchOpcode*/ 17,  TARGET_VAL(ISD::CALLSEQ_START),// ->3883
/*3866*/    OPC_RecordNode,   // #0 = 'callseq_start' chained node
/*3867*/    OPC_RecordChild1, // #1 = $amt
/*3868*/    OPC_MoveChild, 1,
/*3870*/    OPC_CheckOpcode, TARGET_VAL(ISD::TargetConstant),
/*3873*/    OPC_MoveParent,
/*3874*/    OPC_EmitMergeInputChains1_0,
/*3875*/    OPC_MorphNodeTo, TARGET_VAL(XCore::ADJCALLSTACKDOWN), 0|OPFL_Chain|OPFL_GlueOutput,
                1/*#VTs*/, MVT::i32, 1/*#Ops*/, 1, 
            // Src: (callseq_start (timm:i32):$amt) - Complexity = 6
            // Dst: (ADJCALLSTACKDOWN:i32 (timm:i32):$amt)
/*3883*/  /*SwitchOpcode*/ 17,  TARGET_VAL(XCoreISD::DPRelativeWrapper),// ->3903
/*3886*/    OPC_RecordChild0, // #0 = $b
/*3887*/    OPC_MoveChild, 0,
/*3889*/    OPC_CheckOpcode, TARGET_VAL(ISD::TargetGlobalAddress),
/*3892*/    OPC_MoveParent,
/*3893*/    OPC_CheckType, MVT::i32,
/*3895*/    OPC_MorphNodeTo, TARGET_VAL(XCore::LDAWDP_lru6), 0,
                1/*#VTs*/, MVT::i32, 1/*#Ops*/, 0, 
            // Src: (dprelwrapper:i32 (tglobaladdr:i32):$b) - Complexity = 6
            // Dst: (LDAWDP_lru6:i32 (tglobaladdr:i32):$b)
/*3903*/  /*SwitchOpcode*/ 17,  TARGET_VAL(XCoreISD::CPRelativeWrapper),// ->3923
/*3906*/    OPC_RecordChild0, // #0 = $a
/*3907*/    OPC_MoveChild, 0,
/*3909*/    OPC_CheckOpcode, TARGET_VAL(ISD::TargetGlobalAddress),
/*3912*/    OPC_MoveParent,
/*3913*/    OPC_CheckType, MVT::i32,
/*3915*/    OPC_MorphNodeTo, TARGET_VAL(XCore::LDAWCP_lu6), 0,
                1/*#VTs*/, MVT::i32, 1/*#Ops*/, 0, 
            // Src: (cprelwrapper:i32 (tglobaladdr:i32):$a) - Complexity = 6
            // Dst: (LDAWCP_lu6:i32 (tglobaladdr:i32):$a)
/*3923*/  /*SwitchOpcode*/ 45,  TARGET_VAL(XCoreISD::PCRelativeWrapper),// ->3971
/*3926*/    OPC_RecordChild0, // #0 = $a
/*3927*/    OPC_MoveChild, 0,
/*3929*/    OPC_SwitchOpcode /*2 cases */, 23,  TARGET_VAL(ISD::TargetGlobalAddress),// ->3956
/*3933*/      OPC_MoveParent,
/*3934*/      OPC_CheckType, MVT::i32,
/*3936*/      OPC_Scope, 8, /*->3946*/ // 2 children in Scope
/*3938*/        OPC_MorphNodeTo, TARGET_VAL(XCore::LDAPF_lu10), 0,
                    1/*#VTs*/, MVT::i32, 1/*#Ops*/, 0, 
                // Src: (pcrelwrapper:i32 (tglobaladdr:i32):$a) - Complexity = 6
                // Dst: (LDAPF_lu10:i32 (tglobaladdr:i32):$a)
/*3946*/      /*Scope*/ 8, /*->3955*/
/*3947*/        OPC_MorphNodeTo, TARGET_VAL(XCore::LDAPB_lu10), 0,
                    1/*#VTs*/, MVT::i32, 1/*#Ops*/, 0, 
                // Src: (pcrelwrapper:i32 (tglobaladdr:i32):$a) - Complexity = 6
                // Dst: (LDAPB_lu10:i32 (tglobaladdr:i32):$a)
/*3955*/      0, /*End of Scope*/
/*3956*/    /*SwitchOpcode*/ 11,  TARGET_VAL(ISD::TargetBlockAddress),// ->3970
/*3959*/      OPC_MoveParent,
/*3960*/      OPC_CheckType, MVT::i32,
/*3962*/      OPC_MorphNodeTo, TARGET_VAL(XCore::LDAPF_lu10_ba), 0,
                  1/*#VTs*/, MVT::i32, 1/*#Ops*/, 0, 
              // Src: (pcrelwrapper:i32 (tblockaddress:i32):$a) - Complexity = 6
              // Dst: (LDAPF_lu10_ba:i32 (tblockaddress:i32):$a)
/*3970*/    0, // EndSwitchOpcode
/*3971*/  /*SwitchOpcode*/ 18,  TARGET_VAL(XCoreISD::BR_JT),// ->3992
/*3974*/    OPC_RecordNode,   // #0 = 'XCoreBR_JT' chained node
/*3975*/    OPC_RecordChild1, // #1 = $t
/*3976*/    OPC_MoveChild, 1,
/*3978*/    OPC_CheckOpcode, TARGET_VAL(ISD::TargetJumpTable),
/*3981*/    OPC_MoveParent,
/*3982*/    OPC_RecordChild2, // #2 = $i
/*3983*/    OPC_EmitMergeInputChains1_0,
/*3984*/    OPC_MorphNodeTo, TARGET_VAL(XCore::BR_JT), 0|OPFL_Chain,
                0/*#VTs*/, 2/*#Ops*/, 1, 2, 
            // Src: (XCoreBR_JT (tjumptable:i32):$t, GRRegs:i32:$i) - Complexity = 6
            // Dst: (BR_JT (tjumptable:i32):$t, GRRegs:i32:$i)
/*3992*/  /*SwitchOpcode*/ 18,  TARGET_VAL(XCoreISD::BR_JT32),// ->4013
/*3995*/    OPC_RecordNode,   // #0 = 'XCoreBR_JT32' chained node
/*3996*/    OPC_RecordChild1, // #1 = $t
/*3997*/    OPC_MoveChild, 1,
/*3999*/    OPC_CheckOpcode, TARGET_VAL(ISD::TargetJumpTable),
/*4002*/    OPC_MoveParent,
/*4003*/    OPC_RecordChild2, // #2 = $i
/*4004*/    OPC_EmitMergeInputChains1_0,
/*4005*/    OPC_MorphNodeTo, TARGET_VAL(XCore::BR_JT32), 0|OPFL_Chain,
                0/*#VTs*/, 2/*#Ops*/, 1, 2, 
            // Src: (XCoreBR_JT32 (tjumptable:i32):$t, GRRegs:i32:$i) - Complexity = 6
            // Dst: (BR_JT32 (tjumptable:i32):$t, GRRegs:i32:$i)
/*4013*/  /*SwitchOpcode*/ 29,  TARGET_VAL(ISD::Constant),// ->4045
/*4016*/    OPC_RecordNode,   // #0 = $b
/*4017*/    OPC_Scope, 12, /*->4031*/ // 2 children in Scope
/*4019*/      OPC_CheckPredicate, 20, // Predicate_immU6
/*4021*/      OPC_EmitConvertToTarget, 0,
/*4023*/      OPC_MorphNodeTo, TARGET_VAL(XCore::LDC_ru6), 0,
                  1/*#VTs*/, MVT::i32, 1/*#Ops*/, 1, 
              // Src: (imm:i32)<<P:Predicate_immU6>>:$b - Complexity = 4
              // Dst: (LDC_ru6:i32 (imm:i32):$b)
/*4031*/    /*Scope*/ 12, /*->4044*/
/*4032*/      OPC_CheckPredicate, 21, // Predicate_immU16
/*4034*/      OPC_EmitConvertToTarget, 0,
/*4036*/      OPC_MorphNodeTo, TARGET_VAL(XCore::LDC_lru6), 0,
                  1/*#VTs*/, MVT::i32, 1/*#Ops*/, 1, 
              // Src: (imm:i32)<<P:Predicate_immU16>>:$b - Complexity = 4
              // Dst: (LDC_lru6:i32 (imm:i32):$b)
/*4044*/    0, /*End of Scope*/
/*4045*/  /*SwitchOpcode*/ 8,  TARGET_VAL(XCoreISD::MEMBARRIER),// ->4056
/*4048*/    OPC_RecordNode,   // #0 = 'XCoreMemBarrier' chained node
/*4049*/    OPC_EmitMergeInputChains1_0,
/*4050*/    OPC_MorphNodeTo, TARGET_VAL(XCore::Int_MemBarrier), 0|OPFL_Chain,
                0/*#VTs*/, 0/*#Ops*/, 
            // Src: (XCoreMemBarrier) - Complexity = 3
            // Dst: (Int_MemBarrier)
/*4056*/  /*SwitchOpcode*/ 11,  TARGET_VAL(ISD::OR),// ->4070
/*4059*/    OPC_RecordChild0, // #0 = $b
/*4060*/    OPC_RecordChild1, // #1 = $c
/*4061*/    OPC_MorphNodeTo, TARGET_VAL(XCore::OR_3r), 0,
                1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1, 
            // Src: (or:i32 GRRegs:i32:$b, GRRegs:i32:$c) - Complexity = 3
            // Dst: (OR_3r:i32 GRRegs:i32:$b, GRRegs:i32:$c)
/*4070*/  /*SwitchOpcode*/ 11,  TARGET_VAL(ISD::SDIV),// ->4084
/*4073*/    OPC_RecordChild0, // #0 = $b
/*4074*/    OPC_RecordChild1, // #1 = $c
/*4075*/    OPC_MorphNodeTo, TARGET_VAL(XCore::DIVS_l3r), 0,
                1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1, 
            // Src: (sdiv:i32 GRRegs:i32:$b, GRRegs:i32:$c) - Complexity = 3
            // Dst: (DIVS_l3r:i32 GRRegs:i32:$b, GRRegs:i32:$c)
/*4084*/  /*SwitchOpcode*/ 11,  TARGET_VAL(ISD::UDIV),// ->4098
/*4087*/    OPC_RecordChild0, // #0 = $b
/*4088*/    OPC_RecordChild1, // #1 = $c
/*4089*/    OPC_MorphNodeTo, TARGET_VAL(XCore::DIVU_l3r), 0,
                1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1, 
            // Src: (udiv:i32 GRRegs:i32:$b, GRRegs:i32:$c) - Complexity = 3
            // Dst: (DIVU_l3r:i32 GRRegs:i32:$b, GRRegs:i32:$c)
/*4098*/  /*SwitchOpcode*/ 11,  TARGET_VAL(ISD::SREM),// ->4112
/*4101*/    OPC_RecordChild0, // #0 = $b
/*4102*/    OPC_RecordChild1, // #1 = $c
/*4103*/    OPC_MorphNodeTo, TARGET_VAL(XCore::REMS_l3r), 0,
                1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1, 
            // Src: (srem:i32 GRRegs:i32:$b, GRRegs:i32:$c) - Complexity = 3
            // Dst: (REMS_l3r:i32 GRRegs:i32:$b, GRRegs:i32:$c)
/*4112*/  /*SwitchOpcode*/ 11,  TARGET_VAL(ISD::UREM),// ->4126
/*4115*/    OPC_RecordChild0, // #0 = $b
/*4116*/    OPC_RecordChild1, // #1 = $c
/*4117*/    OPC_MorphNodeTo, TARGET_VAL(XCore::REMU_l3r), 0,
                1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1, 
            // Src: (urem:i32 GRRegs:i32:$b, GRRegs:i32:$c) - Complexity = 3
            // Dst: (REMU_l3r:i32 GRRegs:i32:$b, GRRegs:i32:$c)
/*4126*/  /*SwitchOpcode*/ 9,  TARGET_VAL(ISD::BSWAP),// ->4138
/*4129*/    OPC_RecordChild0, // #0 = $src
/*4130*/    OPC_MorphNodeTo, TARGET_VAL(XCore::BYTEREV_l2r), 0,
                1/*#VTs*/, MVT::i32, 1/*#Ops*/, 0, 
            // Src: (bswap:i32 GRRegs:i32:$src) - Complexity = 3
            // Dst: (BYTEREV_l2r:i32 GRRegs:i32:$src)
/*4138*/  /*SwitchOpcode*/ 9,  TARGET_VAL(ISD::CTLZ),// ->4150
/*4141*/    OPC_RecordChild0, // #0 = $src
/*4142*/    OPC_MorphNodeTo, TARGET_VAL(XCore::CLZ_l2r), 0,
                1/*#VTs*/, MVT::i32, 1/*#Ops*/, 0, 
            // Src: (ctlz:i32 GRRegs:i32:$src) - Complexity = 3
            // Dst: (CLZ_l2r:i32 GRRegs:i32:$src)
/*4150*/  /*SwitchOpcode*/ 53,  TARGET_VAL(ISD::SIGN_EXTEND_INREG),// ->4206
/*4153*/    OPC_RecordChild0, // #0 = $b
/*4154*/    OPC_MoveChild, 1,
/*4156*/    OPC_Scope, 15, /*->4173*/ // 3 children in Scope
/*4158*/      OPC_CheckValueType, MVT::i1,
/*4160*/      OPC_MoveParent,
/*4161*/      OPC_EmitInteger, MVT::i32, 1, 
/*4164*/      OPC_MorphNodeTo, TARGET_VAL(XCore::SEXT_rus), 0,
                  1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1, 
              // Src: (sext_inreg:i32 GRRegs:i32:$b, i1:Other) - Complexity = 3
              // Dst: (SEXT_rus:i32 GRRegs:i32:$b, 1:i32)
/*4173*/    /*Scope*/ 15, /*->4189*/
/*4174*/      OPC_CheckValueType, MVT::i8,
/*4176*/      OPC_MoveParent,
/*4177*/      OPC_EmitInteger, MVT::i32, 8, 
/*4180*/      OPC_MorphNodeTo, TARGET_VAL(XCore::SEXT_rus), 0,
                  1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1, 
              // Src: (sext_inreg:i32 GRRegs:i32:$b, i8:Other) - Complexity = 3
              // Dst: (SEXT_rus:i32 GRRegs:i32:$b, 8:i32)
/*4189*/    /*Scope*/ 15, /*->4205*/
/*4190*/      OPC_CheckValueType, MVT::i16,
/*4192*/      OPC_MoveParent,
/*4193*/      OPC_EmitInteger, MVT::i32, 16, 
/*4196*/      OPC_MorphNodeTo, TARGET_VAL(XCore::SEXT_rus), 0,
                  1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1, 
              // Src: (sext_inreg:i32 GRRegs:i32:$b, i16:Other) - Complexity = 3
              // Dst: (SEXT_rus:i32 GRRegs:i32:$b, 16:i32)
/*4205*/    0, /*End of Scope*/
/*4206*/  /*SwitchOpcode*/ 16,  TARGET_VAL(ISD::BR),// ->4225
/*4209*/    OPC_RecordNode,   // #0 = 'br' chained node
/*4210*/    OPC_RecordChild1, // #1 = $addr
/*4211*/    OPC_MoveChild, 1,
/*4213*/    OPC_CheckOpcode, TARGET_VAL(ISD::BasicBlock),
/*4216*/    OPC_MoveParent,
/*4217*/    OPC_EmitMergeInputChains1_0,
/*4218*/    OPC_MorphNodeTo, TARGET_VAL(XCore::BRFU_lu6), 0|OPFL_Chain,
                0/*#VTs*/, 1/*#Ops*/, 1, 
            // Src: (br (bb:Other):$addr) - Complexity = 3
            // Dst: (BRFU_lu6 (bb:Other):$addr)
/*4225*/  /*SwitchOpcode*/ 17,  TARGET_VAL(ISD::CTTZ),// ->4245
/*4228*/    OPC_RecordChild0, // #0 = $src
/*4229*/    OPC_EmitNode, TARGET_VAL(XCore::BITREV_l2r), 0,
                1/*#VTs*/, MVT::i32, 1/*#Ops*/, 0,  // Results = #1
/*4237*/    OPC_MorphNodeTo, TARGET_VAL(XCore::CLZ_l2r), 0,
                1/*#VTs*/, MVT::i32, 1/*#Ops*/, 1, 
            // Src: (cttz:i32 GRRegs:i32:$src) - Complexity = 3
            // Dst: (CLZ_l2r:i32 (BITREV_l2r:i32 GRRegs:i32:$src))
/*4245*/  /*SwitchOpcode*/ 20,  TARGET_VAL(ISD::TRAP),// ->4268
/*4248*/    OPC_RecordNode,   // #0 = 'trap' chained node
/*4249*/    OPC_EmitMergeInputChains1_0,
/*4250*/    OPC_EmitInteger, MVT::i32, 0, 
/*4253*/    OPC_EmitNode, TARGET_VAL(XCore::LDC_ru6), 0,
                1/*#VTs*/, MVT::i32, 1/*#Ops*/, 1,  // Results = #2
/*4261*/    OPC_MorphNodeTo, TARGET_VAL(XCore::ECALLF_1r), 0|OPFL_Chain,
                0/*#VTs*/, 1/*#Ops*/, 2, 
            // Src: (trap) - Complexity = 3
            // Dst: (ECALLF_1r (LDC_ru6:i32 0:i32))
/*4268*/  0, // EndSwitchOpcode
    0
  }; // Total Array size is 4270 bytes

  // Opcode Histogram:
  // #OPC_Scope                          = 68
  // #OPC_RecordNode                     = 20
  // #OPC_RecordChild                    = 195
  // #OPC_RecordMemRef                   = 2
  // #OPC_CaptureGlueInput               = 3
  // #OPC_MoveChild                      = 98
  // #OPC_MoveParent                     = 227
  // #OPC_CheckSame                      = 0
  // #OPC_CheckChildSame                 = 1
  // #OPC_CheckPatternPredicate          = 0
  // #OPC_CheckPredicate                 = 95
  // #OPC_CheckOpcode                    = 60
  // #OPC_SwitchOpcode                   = 5
  // #OPC_CheckType                      = 43
  // #OPC_SwitchType                     = 0
  // #OPC_CheckChildType                 = 54
  // #OPC_CheckInteger                   = 78
  // #OPC_CheckCondCode                  = 33
  // #OPC_CheckValueType                 = 3
  // #OPC_CheckComplexPat                = 4
  // #OPC_CheckAndImm                    = 0
  // #OPC_CheckOrImm                     = 0
  // #OPC_CheckFoldableChainNode         = 1
  // #OPC_EmitInteger                    = 25
  // #OPC_EmitStringInteger              = 0
  // #OPC_EmitRegister                   = 0
  // #OPC_EmitConvertToTarget            = 36
  // #OPC_EmitMergeInputChains           = 106
  // #OPC_EmitCopyToReg                  = 2
  // #OPC_EmitNode                       = 31
  // #OPC_EmitNodeXForm                  = 8
  // #OPC_MarkGlueResults                = 0
  // #OPC_CompleteMatch                  = 0
  // #OPC_MorphNodeTo                    = 191

  #undef TARGET_VAL
  return SelectCodeCommon(N, MatcherTable,sizeof(MatcherTable));
}

virtual bool CheckNodePredicate(SDNode *Node,
                                unsigned PredNo) const {
  switch (PredNo) {
  default: llvm_unreachable("Invalid predicate in table?");
  case 0: { // Predicate_immUs
    ConstantSDNode*N = cast<ConstantSDNode>(Node);

  return (uint32_t)N->getZExtValue() <= 11;

  }
  case 1: { // Predicate_immUs4
    ConstantSDNode*N = cast<ConstantSDNode>(Node);

  uint32_t value = (uint32_t)N->getZExtValue();
  return value%4 == 0 && value/4 <= 11;

  }
  case 2: { // Predicate_immUsNeg
    ConstantSDNode*N = cast<ConstantSDNode>(Node);

  return -((uint32_t)N->getZExtValue()) <= 11;

  }
  case 3: { // Predicate_immUs4Neg
    ConstantSDNode*N = cast<ConstantSDNode>(Node);

  uint32_t value = (uint32_t)N->getZExtValue();
  return (-value)%4 == 0 && (-value)/4 <= 11;

  }
  case 4: { // Predicate_unindexedload
    SDNode *N = Node;

  return cast<LoadSDNode>(N)->getAddressingMode() == ISD::UNINDEXED;

  }
  case 5: { // Predicate_sextload
    SDNode *N = Node;

  return cast<LoadSDNode>(N)->getExtensionType() == ISD::SEXTLOAD;

  }
  case 6: { // Predicate_sextloadi16
    SDNode *N = Node;

  return cast<LoadSDNode>(N)->getMemoryVT() == MVT::i16;

  }
  case 7: { // Predicate_extload
    SDNode *N = Node;

  return cast<LoadSDNode>(N)->getExtensionType() == ISD::EXTLOAD;

  }
  case 8: { // Predicate_extloadi16
    SDNode *N = Node;

  return cast<LoadSDNode>(N)->getMemoryVT() == MVT::i16;

  }
  case 9: { // Predicate_load
    SDNode *N = Node;

  return cast<LoadSDNode>(N)->getExtensionType() == ISD::NON_EXTLOAD;

  }
  case 10: { // Predicate_zextload
    SDNode *N = Node;

  return cast<LoadSDNode>(N)->getExtensionType() == ISD::ZEXTLOAD;

  }
  case 11: { // Predicate_zextloadi8
    SDNode *N = Node;

  return cast<LoadSDNode>(N)->getMemoryVT() == MVT::i8;

  }
  case 12: { // Predicate_extloadi8
    SDNode *N = Node;

  return cast<LoadSDNode>(N)->getMemoryVT() == MVT::i8;

  }
  case 13: { // Predicate_unindexedstore
    SDNode *N = Node;

  return cast<StoreSDNode>(N)->getAddressingMode() == ISD::UNINDEXED;

  }
  case 14: { // Predicate_truncstore
    SDNode *N = Node;

  return cast<StoreSDNode>(N)->isTruncatingStore();

  }
  case 15: { // Predicate_truncstorei16
    SDNode *N = Node;

  return cast<StoreSDNode>(N)->getMemoryVT() == MVT::i16;

  }
  case 16: { // Predicate_store
    SDNode *N = Node;

  return !cast<StoreSDNode>(N)->isTruncatingStore();

  }
  case 17: { // Predicate_truncstorei8
    SDNode *N = Node;

  return cast<StoreSDNode>(N)->getMemoryVT() == MVT::i8;

  }
  case 18: { // Predicate_immBpwSubBitp
    ConstantSDNode*N = cast<ConstantSDNode>(Node);

  uint32_t value = (uint32_t)N->getZExtValue();
  return (value >= 24 && value <= 31)
          || value == 16
          || value == 8
          || value == 0;

  }
  case 19: { // Predicate_immBitp
    ConstantSDNode*N = cast<ConstantSDNode>(Node);

  uint32_t value = (uint32_t)N->getZExtValue();
  return (value >= 1 && value <= 8)
          || value == 16
          || value == 24
          || value == 32;

  }
  case 20: { // Predicate_immU6
    ConstantSDNode*N = cast<ConstantSDNode>(Node);

  return (uint32_t)N->getZExtValue() < (1 << 6);

  }
  case 21: { // Predicate_immU16
    ConstantSDNode*N = cast<ConstantSDNode>(Node);

  return (uint32_t)N->getZExtValue() < (1 << 16);

  }
  case 22: { // Predicate_immMskBitp
    ConstantSDNode*N = cast<ConstantSDNode>(Node);
 return immMskBitp(N); 
  }
  case 23: { // Predicate_immU10
    ConstantSDNode*N = cast<ConstantSDNode>(Node);

  return (uint32_t)N->getZExtValue() < (1 << 10);

  }
  case 24: { // Predicate_immU20
    ConstantSDNode*N = cast<ConstantSDNode>(Node);

  return (uint32_t)N->getZExtValue() < (1 << 20);

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
    return SelectADDRspii(N, Result[NextRes+0].first, Result[NextRes+1].first);
  }
}

virtual SDValue RunSDNodeXForm(SDValue V, unsigned XFormNo) {
  switch (XFormNo) {
  default: llvm_unreachable("Invalid xform # in table?");
  case 0: {  // div4_xform
    ConstantSDNode *N = cast<ConstantSDNode>(V.getNode());

  // Transformation function: imm/4
  assert(N->getZExtValue() % 4 == 0);
  return getI32Imm(N->getZExtValue()/4);

  }
  case 1: {  // neg_xform
    ConstantSDNode *N = cast<ConstantSDNode>(V.getNode());

  // Transformation function: -imm
  uint32_t value = N->getZExtValue();
  return getI32Imm(-value);

  }
  case 2: {  // div4neg_xform
    ConstantSDNode *N = cast<ConstantSDNode>(V.getNode());

  // Transformation function: -imm/4
  uint32_t value = N->getZExtValue();
  assert(-value % 4 == 0);
  return getI32Imm(-value/4);

  }
  case 3: {  // bpwsub_xform
    ConstantSDNode *N = cast<ConstantSDNode>(V.getNode());

  // Transformation function: 32-imm
  uint32_t value = N->getZExtValue();
  return getI32Imm(32-value);

  }
  case 4: {  // msksize_xform
    ConstantSDNode *N = cast<ConstantSDNode>(V.getNode());

  // Transformation function: get the size of a mask
  assert(isMask_32(N->getZExtValue()));
  // look for the first non-zero bit
  return getI32Imm(32 - countLeadingZeros((uint32_t)N->getZExtValue()));

  }
  }
}


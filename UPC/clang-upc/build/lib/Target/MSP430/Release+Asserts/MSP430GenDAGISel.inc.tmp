/*===- TableGen'erated file -------------------------------------*- C++ -*-===*\
|*                                                                            *|
|*DAG Instruction Selector for the MSP430 target                              *|
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
/*0*/     OPC_SwitchOpcode /*34 cases */, 100|128,26/*3428*/,  TARGET_VAL(ISD::STORE),// ->3433
/*5*/       OPC_RecordMemRef,
/*6*/       OPC_RecordNode,   // #0 = 'st' chained node
/*7*/       OPC_Scope, 122|128,25/*3322*/, /*->3332*/ // 2 children in Scope
/*10*/        OPC_MoveChild, 1,
/*12*/        OPC_SwitchOpcode /*11 cases */, 93|128,5/*733*/,  TARGET_VAL(ISD::AND),// ->750
/*17*/          OPC_Scope, 19|128,5/*659*/, /*->679*/ // 2 children in Scope
/*20*/            OPC_MoveChild, 0,
/*22*/            OPC_SwitchOpcode /*2 cases */, 68|128,3/*452*/,  TARGET_VAL(ISD::LOAD),// ->479
/*27*/              OPC_RecordMemRef,
/*28*/              OPC_RecordNode, // #1 = 'ld' chained node
/*29*/              OPC_CheckFoldableChainNode,
/*30*/              OPC_RecordChild1, // #2 = $dst
/*31*/              OPC_CheckPredicate, 0, // Predicate_unindexedload
/*33*/              OPC_CheckPredicate, 1, // Predicate_load
/*35*/              OPC_MoveParent,
/*36*/              OPC_Scope, 60|128,2/*316*/, /*->355*/ // 2 children in Scope
/*39*/                OPC_MoveChild, 1,
/*41*/                OPC_SwitchOpcode /*2 cases */, 39|128,1/*167*/,  TARGET_VAL(ISD::XOR),// ->213
/*46*/                  OPC_Scope, 93, /*->141*/ // 2 children in Scope
/*48*/                    OPC_MoveChild, 0,
/*50*/                    OPC_CheckOpcode, TARGET_VAL(ISD::LOAD),
/*53*/                    OPC_RecordMemRef,
/*54*/                    OPC_RecordNode, // #3 = 'ld' chained node
/*55*/                    OPC_CheckFoldableChainNode,
/*56*/                    OPC_RecordChild1, // #4 = $src
/*57*/                    OPC_CheckPredicate, 0, // Predicate_unindexedload
/*59*/                    OPC_CheckPredicate, 1, // Predicate_load
/*61*/                    OPC_MoveParent,
/*62*/                    OPC_MoveChild, 1,
/*64*/                    OPC_CheckInteger, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*75*/                    OPC_MoveParent,
/*76*/                    OPC_MoveParent,
/*77*/                    OPC_SwitchType /*2 cases */, 29,  MVT::i8,// ->109
/*80*/                      OPC_MoveParent,
/*81*/                      OPC_CheckChild2Same, 2,
/*83*/                      OPC_CheckPredicate, 2, // Predicate_unindexedstore
/*85*/                      OPC_CheckPredicate, 3, // Predicate_store
/*87*/                      OPC_CheckComplexPat, /*CP*/0, /*#*/2, // SelectAddr:$dst #5 #6
/*90*/                      OPC_CheckComplexPat, /*CP*/0, /*#*/4, // SelectAddr:$src #7 #8
/*93*/                      OPC_EmitMergeInputChains, 3, 0, 1, 3, 
/*98*/                      OPC_MorphNodeTo, TARGET_VAL(MSP430::BIC8mm), 0|OPFL_Chain|OPFL_MemRefs,
                                1/*#VTs*/, MVT::i16, 4/*#Ops*/, 5, 6, 7, 8, 
                            // Src: (st (and:i8 (ld:i8 addr:iPTR:$dst)<<P:Predicate_unindexedload>><<P:Predicate_load>>, (xor:i8 (ld:i8 addr:iPTR:$src)<<P:Predicate_unindexedload>><<P:Predicate_load>>, -1:i8)), addr:iPTR:$dst)<<P:Predicate_unindexedstore>><<P:Predicate_store>> - Complexity = 50
                            // Dst: (BIC8mm:i16 addr:i16:$dst, addr:i16:$src)
/*109*/                   /*SwitchType*/ 29,  MVT::i16,// ->140
/*111*/                     OPC_MoveParent,
/*112*/                     OPC_CheckChild2Same, 2,
/*114*/                     OPC_CheckPredicate, 2, // Predicate_unindexedstore
/*116*/                     OPC_CheckPredicate, 3, // Predicate_store
/*118*/                     OPC_CheckComplexPat, /*CP*/0, /*#*/2, // SelectAddr:$dst #5 #6
/*121*/                     OPC_CheckComplexPat, /*CP*/0, /*#*/4, // SelectAddr:$src #7 #8
/*124*/                     OPC_EmitMergeInputChains, 3, 0, 1, 3, 
/*129*/                     OPC_MorphNodeTo, TARGET_VAL(MSP430::BIC16mm), 0|OPFL_Chain|OPFL_MemRefs,
                                1/*#VTs*/, MVT::i16, 4/*#Ops*/, 5, 6, 7, 8, 
                            // Src: (st (and:i16 (ld:i16 addr:iPTR:$dst)<<P:Predicate_unindexedload>><<P:Predicate_load>>, (xor:i16 (ld:i16 addr:iPTR:$src)<<P:Predicate_unindexedload>><<P:Predicate_load>>, -1:i16)), addr:iPTR:$dst)<<P:Predicate_unindexedstore>><<P:Predicate_store>> - Complexity = 50
                            // Dst: (BIC16mm:i16 addr:i16:$dst, addr:i16:$src)
/*140*/                   0, // EndSwitchType
/*141*/                 /*Scope*/ 70, /*->212*/
/*142*/                   OPC_RecordChild0, // #3 = $src
/*143*/                   OPC_MoveChild, 1,
/*145*/                   OPC_CheckInteger, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*156*/                   OPC_MoveParent,
/*157*/                   OPC_MoveParent,
/*158*/                   OPC_SwitchType /*2 cases */, 24,  MVT::i8,// ->185
/*161*/                     OPC_MoveParent,
/*162*/                     OPC_CheckChild2Same, 2,
/*164*/                     OPC_CheckPredicate, 2, // Predicate_unindexedstore
/*166*/                     OPC_CheckPredicate, 3, // Predicate_store
/*168*/                     OPC_CheckComplexPat, /*CP*/0, /*#*/2, // SelectAddr:$dst #4 #5
/*171*/                     OPC_EmitMergeInputChains, 2, 0, 1, 
/*175*/                     OPC_MorphNodeTo, TARGET_VAL(MSP430::BIC8mr), 0|OPFL_Chain|OPFL_MemRefs,
                                1/*#VTs*/, MVT::i16, 3/*#Ops*/, 4, 5, 3, 
                            // Src: (st (and:i8 (ld:i8 addr:iPTR:$dst)<<P:Predicate_unindexedload>><<P:Predicate_load>>, (xor:i8 GR8:i8:$src, -1:i8)), addr:iPTR:$dst)<<P:Predicate_unindexedstore>><<P:Predicate_store>> - Complexity = 37
                            // Dst: (BIC8mr:i16 addr:i16:$dst, GR8:i8:$src)
/*185*/                   /*SwitchType*/ 24,  MVT::i16,// ->211
/*187*/                     OPC_MoveParent,
/*188*/                     OPC_CheckChild2Same, 2,
/*190*/                     OPC_CheckPredicate, 2, // Predicate_unindexedstore
/*192*/                     OPC_CheckPredicate, 3, // Predicate_store
/*194*/                     OPC_CheckComplexPat, /*CP*/0, /*#*/2, // SelectAddr:$dst #4 #5
/*197*/                     OPC_EmitMergeInputChains, 2, 0, 1, 
/*201*/                     OPC_MorphNodeTo, TARGET_VAL(MSP430::BIC16mr), 0|OPFL_Chain|OPFL_MemRefs,
                                1/*#VTs*/, MVT::i16, 3/*#Ops*/, 4, 5, 3, 
                            // Src: (st (and:i16 (ld:i16 addr:iPTR:$dst)<<P:Predicate_unindexedload>><<P:Predicate_load>>, (xor:i16 GR16:i16:$src, -1:i16)), addr:iPTR:$dst)<<P:Predicate_unindexedstore>><<P:Predicate_store>> - Complexity = 37
                            // Dst: (BIC16mr:i16 addr:i16:$dst, GR16:i16:$src)
/*211*/                   0, // EndSwitchType
/*212*/                 0, /*End of Scope*/
/*213*/               /*SwitchOpcode*/ 9|128,1/*137*/,  TARGET_VAL(ISD::LOAD),// ->354
/*217*/                 OPC_RecordMemRef,
/*218*/                 OPC_RecordNode, // #3 = 'ld' chained node
/*219*/                 OPC_CheckFoldableChainNode,
/*220*/                 OPC_RecordChild1, // #4 = $src
/*221*/                 OPC_CheckPredicate, 0, // Predicate_unindexedload
/*223*/                 OPC_CheckPredicate, 1, // Predicate_load
/*225*/                 OPC_MoveParent,
/*226*/                 OPC_SwitchType /*2 cases */, 61,  MVT::i8,// ->290
/*229*/                   OPC_MoveParent,
/*230*/                   OPC_Scope, 28, /*->260*/ // 2 children in Scope
/*232*/                     OPC_CheckChild2Same, 2,
/*234*/                     OPC_CheckPredicate, 2, // Predicate_unindexedstore
/*236*/                     OPC_CheckPredicate, 3, // Predicate_store
/*238*/                     OPC_CheckComplexPat, /*CP*/0, /*#*/2, // SelectAddr:$dst #5 #6
/*241*/                     OPC_CheckComplexPat, /*CP*/0, /*#*/4, // SelectAddr:$src #7 #8
/*244*/                     OPC_EmitMergeInputChains, 3, 0, 1, 3, 
/*249*/                     OPC_MorphNodeTo, TARGET_VAL(MSP430::AND8mm), 0|OPFL_Chain|OPFL_MemRefs,
                                1/*#VTs*/, MVT::i16, 4/*#Ops*/, 5, 6, 7, 8, 
                            // Src: (st (and:i8 (ld:i8 addr:iPTR:$dst)<<P:Predicate_unindexedload>><<P:Predicate_load>>, (ld:i8 addr:iPTR:$src)<<P:Predicate_unindexedload>><<P:Predicate_load>>), addr:iPTR:$dst)<<P:Predicate_unindexedstore>><<P:Predicate_store>> - Complexity = 42
                            // Dst: (AND8mm:i16 addr:i16:$dst, addr:i16:$src)
/*260*/                   /*Scope*/ 28, /*->289*/
/*261*/                     OPC_CheckChild2Same, 4,
/*263*/                     OPC_CheckPredicate, 2, // Predicate_unindexedstore
/*265*/                     OPC_CheckPredicate, 3, // Predicate_store
/*267*/                     OPC_CheckComplexPat, /*CP*/0, /*#*/2, // SelectAddr:$src #5 #6
/*270*/                     OPC_CheckComplexPat, /*CP*/0, /*#*/4, // SelectAddr:$dst #7 #8
/*273*/                     OPC_EmitMergeInputChains, 3, 0, 1, 3, 
/*278*/                     OPC_MorphNodeTo, TARGET_VAL(MSP430::AND8mm), 0|OPFL_Chain|OPFL_MemRefs,
                                1/*#VTs*/, MVT::i16, 4/*#Ops*/, 7, 8, 5, 6, 
                            // Src: (st (and:i8 (ld:i8 addr:iPTR:$src)<<P:Predicate_unindexedload>><<P:Predicate_load>>, (ld:i8 addr:iPTR:$dst)<<P:Predicate_unindexedload>><<P:Predicate_load>>), addr:iPTR:$dst)<<P:Predicate_unindexedstore>><<P:Predicate_store>> - Complexity = 42
                            // Dst: (AND8mm:i16 addr:i16:$dst, addr:i16:$src)
/*289*/                   0, /*End of Scope*/
/*290*/                 /*SwitchType*/ 61,  MVT::i16,// ->353
/*292*/                   OPC_MoveParent,
/*293*/                   OPC_Scope, 28, /*->323*/ // 2 children in Scope
/*295*/                     OPC_CheckChild2Same, 2,
/*297*/                     OPC_CheckPredicate, 2, // Predicate_unindexedstore
/*299*/                     OPC_CheckPredicate, 3, // Predicate_store
/*301*/                     OPC_CheckComplexPat, /*CP*/0, /*#*/2, // SelectAddr:$dst #5 #6
/*304*/                     OPC_CheckComplexPat, /*CP*/0, /*#*/4, // SelectAddr:$src #7 #8
/*307*/                     OPC_EmitMergeInputChains, 3, 0, 1, 3, 
/*312*/                     OPC_MorphNodeTo, TARGET_VAL(MSP430::AND16mm), 0|OPFL_Chain|OPFL_MemRefs,
                                1/*#VTs*/, MVT::i16, 4/*#Ops*/, 5, 6, 7, 8, 
                            // Src: (st (and:i16 (ld:i16 addr:iPTR:$dst)<<P:Predicate_unindexedload>><<P:Predicate_load>>, (ld:i16 addr:iPTR:$src)<<P:Predicate_unindexedload>><<P:Predicate_load>>), addr:iPTR:$dst)<<P:Predicate_unindexedstore>><<P:Predicate_store>> - Complexity = 42
                            // Dst: (AND16mm:i16 addr:i16:$dst, addr:i16:$src)
/*323*/                   /*Scope*/ 28, /*->352*/
/*324*/                     OPC_CheckChild2Same, 4,
/*326*/                     OPC_CheckPredicate, 2, // Predicate_unindexedstore
/*328*/                     OPC_CheckPredicate, 3, // Predicate_store
/*330*/                     OPC_CheckComplexPat, /*CP*/0, /*#*/2, // SelectAddr:$src #5 #6
/*333*/                     OPC_CheckComplexPat, /*CP*/0, /*#*/4, // SelectAddr:$dst #7 #8
/*336*/                     OPC_EmitMergeInputChains, 3, 0, 1, 3, 
/*341*/                     OPC_MorphNodeTo, TARGET_VAL(MSP430::AND16mm), 0|OPFL_Chain|OPFL_MemRefs,
                                1/*#VTs*/, MVT::i16, 4/*#Ops*/, 7, 8, 5, 6, 
                            // Src: (st (and:i16 (ld:i16 addr:iPTR:$src)<<P:Predicate_unindexedload>><<P:Predicate_load>>, (ld:i16 addr:iPTR:$dst)<<P:Predicate_unindexedload>><<P:Predicate_load>>), addr:iPTR:$dst)<<P:Predicate_unindexedstore>><<P:Predicate_store>> - Complexity = 42
                            // Dst: (AND16mm:i16 addr:i16:$dst, addr:i16:$src)
/*352*/                   0, /*End of Scope*/
/*353*/                 0, // EndSwitchType
/*354*/               0, // EndSwitchOpcode
/*355*/             /*Scope*/ 122, /*->478*/
/*356*/               OPC_RecordChild1, // #3 = $src
/*357*/               OPC_Scope, 64, /*->423*/ // 3 children in Scope
/*359*/                 OPC_MoveChild, 1,
/*361*/                 OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*364*/                 OPC_MoveParent,
/*365*/                 OPC_SwitchType /*2 cases */, 26,  MVT::i8,// ->394
/*368*/                   OPC_MoveParent,
/*369*/                   OPC_CheckChild2Same, 2,
/*371*/                   OPC_CheckPredicate, 2, // Predicate_unindexedstore
/*373*/                   OPC_CheckPredicate, 3, // Predicate_store
/*375*/                   OPC_CheckComplexPat, /*CP*/0, /*#*/2, // SelectAddr:$dst #4 #5
/*378*/                   OPC_EmitMergeInputChains, 2, 0, 1, 
/*382*/                   OPC_EmitConvertToTarget, 3,
/*384*/                   OPC_MorphNodeTo, TARGET_VAL(MSP430::AND8mi), 0|OPFL_Chain|OPFL_MemRefs,
                              1/*#VTs*/, MVT::i16, 3/*#Ops*/, 4, 5, 6, 
                          // Src: (st (and:i8 (ld:i8 addr:iPTR:$dst)<<P:Predicate_unindexedload>><<P:Predicate_load>>, (imm:i8):$src), addr:iPTR:$dst)<<P:Predicate_unindexedstore>><<P:Predicate_store>> - Complexity = 32
                          // Dst: (AND8mi:i16 addr:i16:$dst, (imm:i8):$src)
/*394*/                 /*SwitchType*/ 26,  MVT::i16,// ->422
/*396*/                   OPC_MoveParent,
/*397*/                   OPC_CheckChild2Same, 2,
/*399*/                   OPC_CheckPredicate, 2, // Predicate_unindexedstore
/*401*/                   OPC_CheckPredicate, 3, // Predicate_store
/*403*/                   OPC_CheckComplexPat, /*CP*/0, /*#*/2, // SelectAddr:$dst #4 #5
/*406*/                   OPC_EmitMergeInputChains, 2, 0, 1, 
/*410*/                   OPC_EmitConvertToTarget, 3,
/*412*/                   OPC_MorphNodeTo, TARGET_VAL(MSP430::AND16mi), 0|OPFL_Chain|OPFL_MemRefs,
                              1/*#VTs*/, MVT::i16, 3/*#Ops*/, 4, 5, 6, 
                          // Src: (st (and:i16 (ld:i16 addr:iPTR:$dst)<<P:Predicate_unindexedload>><<P:Predicate_load>>, (imm:i16):$src), addr:iPTR:$dst)<<P:Predicate_unindexedstore>><<P:Predicate_store>> - Complexity = 32
                          // Dst: (AND16mi:i16 addr:i16:$dst, (imm:i16):$src)
/*422*/                 0, // EndSwitchType
/*423*/               /*Scope*/ 26, /*->450*/
/*424*/                 OPC_CheckType, MVT::i8,
/*426*/                 OPC_MoveParent,
/*427*/                 OPC_CheckChild2Same, 2,
/*429*/                 OPC_CheckPredicate, 2, // Predicate_unindexedstore
/*431*/                 OPC_CheckPredicate, 3, // Predicate_store
/*433*/                 OPC_CheckComplexPat, /*CP*/0, /*#*/2, // SelectAddr:$dst #4 #5
/*436*/                 OPC_EmitMergeInputChains, 2, 0, 1, 
/*440*/                 OPC_MorphNodeTo, TARGET_VAL(MSP430::AND8mr), 0|OPFL_Chain|OPFL_MemRefs,
                            1/*#VTs*/, MVT::i16, 3/*#Ops*/, 4, 5, 3, 
                        // Src: (st (and:i8 (ld:i8 addr:iPTR:$dst)<<P:Predicate_unindexedload>><<P:Predicate_load>>, GR8:i8:$src), addr:iPTR:$dst)<<P:Predicate_unindexedstore>><<P:Predicate_store>> - Complexity = 29
                        // Dst: (AND8mr:i16 addr:i16:$dst, GR8:i8:$src)
/*450*/               /*Scope*/ 26, /*->477*/
/*451*/                 OPC_CheckType, MVT::i16,
/*453*/                 OPC_MoveParent,
/*454*/                 OPC_CheckChild2Same, 2,
/*456*/                 OPC_CheckPredicate, 2, // Predicate_unindexedstore
/*458*/                 OPC_CheckPredicate, 3, // Predicate_store
/*460*/                 OPC_CheckComplexPat, /*CP*/0, /*#*/2, // SelectAddr:$dst #4 #5
/*463*/                 OPC_EmitMergeInputChains, 2, 0, 1, 
/*467*/                 OPC_MorphNodeTo, TARGET_VAL(MSP430::AND16mr), 0|OPFL_Chain|OPFL_MemRefs,
                            1/*#VTs*/, MVT::i16, 3/*#Ops*/, 4, 5, 3, 
                        // Src: (st (and:i16 (ld:i16 addr:iPTR:$dst)<<P:Predicate_unindexedload>><<P:Predicate_load>>, GR16:i16:$src), addr:iPTR:$dst)<<P:Predicate_unindexedstore>><<P:Predicate_store>> - Complexity = 29
                        // Dst: (AND16mr:i16 addr:i16:$dst, GR16:i16:$src)
/*477*/               0, /*End of Scope*/
/*478*/             0, /*End of Scope*/
/*479*/           /*SwitchOpcode*/ 67|128,1/*195*/,  TARGET_VAL(ISD::XOR),// ->678
/*483*/             OPC_Scope, 107, /*->592*/ // 2 children in Scope
/*485*/               OPC_MoveChild, 0,
/*487*/               OPC_CheckOpcode, TARGET_VAL(ISD::LOAD),
/*490*/               OPC_RecordMemRef,
/*491*/               OPC_RecordNode, // #1 = 'ld' chained node
/*492*/               OPC_CheckFoldableChainNode,
/*493*/               OPC_RecordChild1, // #2 = $src
/*494*/               OPC_CheckPredicate, 0, // Predicate_unindexedload
/*496*/               OPC_CheckPredicate, 1, // Predicate_load
/*498*/               OPC_MoveParent,
/*499*/               OPC_MoveChild, 1,
/*501*/               OPC_CheckInteger, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*512*/               OPC_MoveParent,
/*513*/               OPC_MoveParent,
/*514*/               OPC_MoveChild, 1,
/*516*/               OPC_CheckOpcode, TARGET_VAL(ISD::LOAD),
/*519*/               OPC_RecordMemRef,
/*520*/               OPC_RecordNode, // #3 = 'ld' chained node
/*521*/               OPC_CheckFoldableChainNode,
/*522*/               OPC_RecordChild1, // #4 = $dst
/*523*/               OPC_CheckPredicate, 0, // Predicate_unindexedload
/*525*/               OPC_CheckPredicate, 1, // Predicate_load
/*527*/               OPC_MoveParent,
/*528*/               OPC_SwitchType /*2 cases */, 29,  MVT::i8,// ->560
/*531*/                 OPC_MoveParent,
/*532*/                 OPC_CheckChild2Same, 4,
/*534*/                 OPC_CheckPredicate, 2, // Predicate_unindexedstore
/*536*/                 OPC_CheckPredicate, 3, // Predicate_store
/*538*/                 OPC_CheckComplexPat, /*CP*/0, /*#*/2, // SelectAddr:$src #5 #6
/*541*/                 OPC_CheckComplexPat, /*CP*/0, /*#*/4, // SelectAddr:$dst #7 #8
/*544*/                 OPC_EmitMergeInputChains, 3, 0, 1, 3, 
/*549*/                 OPC_MorphNodeTo, TARGET_VAL(MSP430::BIC8mm), 0|OPFL_Chain|OPFL_MemRefs,
                            1/*#VTs*/, MVT::i16, 4/*#Ops*/, 7, 8, 5, 6, 
                        // Src: (st (and:i8 (xor:i8 (ld:i8 addr:iPTR:$src)<<P:Predicate_unindexedload>><<P:Predicate_load>>, -1:i8), (ld:i8 addr:iPTR:$dst)<<P:Predicate_unindexedload>><<P:Predicate_load>>), addr:iPTR:$dst)<<P:Predicate_unindexedstore>><<P:Predicate_store>> - Complexity = 50
                        // Dst: (BIC8mm:i16 addr:i16:$dst, addr:i16:$src)
/*560*/               /*SwitchType*/ 29,  MVT::i16,// ->591
/*562*/                 OPC_MoveParent,
/*563*/                 OPC_CheckChild2Same, 4,
/*565*/                 OPC_CheckPredicate, 2, // Predicate_unindexedstore
/*567*/                 OPC_CheckPredicate, 3, // Predicate_store
/*569*/                 OPC_CheckComplexPat, /*CP*/0, /*#*/2, // SelectAddr:$src #5 #6
/*572*/                 OPC_CheckComplexPat, /*CP*/0, /*#*/4, // SelectAddr:$dst #7 #8
/*575*/                 OPC_EmitMergeInputChains, 3, 0, 1, 3, 
/*580*/                 OPC_MorphNodeTo, TARGET_VAL(MSP430::BIC16mm), 0|OPFL_Chain|OPFL_MemRefs,
                            1/*#VTs*/, MVT::i16, 4/*#Ops*/, 7, 8, 5, 6, 
                        // Src: (st (and:i16 (xor:i16 (ld:i16 addr:iPTR:$src)<<P:Predicate_unindexedload>><<P:Predicate_load>>, -1:i16), (ld:i16 addr:iPTR:$dst)<<P:Predicate_unindexedload>><<P:Predicate_load>>), addr:iPTR:$dst)<<P:Predicate_unindexedstore>><<P:Predicate_store>> - Complexity = 50
                        // Dst: (BIC16mm:i16 addr:i16:$dst, addr:i16:$src)
/*591*/               0, // EndSwitchType
/*592*/             /*Scope*/ 84, /*->677*/
/*593*/               OPC_RecordChild0, // #1 = $src
/*594*/               OPC_MoveChild, 1,
/*596*/               OPC_CheckInteger, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*607*/               OPC_MoveParent,
/*608*/               OPC_MoveParent,
/*609*/               OPC_MoveChild, 1,
/*611*/               OPC_CheckOpcode, TARGET_VAL(ISD::LOAD),
/*614*/               OPC_RecordMemRef,
/*615*/               OPC_RecordNode, // #2 = 'ld' chained node
/*616*/               OPC_CheckFoldableChainNode,
/*617*/               OPC_RecordChild1, // #3 = $dst
/*618*/               OPC_CheckPredicate, 0, // Predicate_unindexedload
/*620*/               OPC_CheckPredicate, 1, // Predicate_load
/*622*/               OPC_MoveParent,
/*623*/               OPC_SwitchType /*2 cases */, 24,  MVT::i8,// ->650
/*626*/                 OPC_MoveParent,
/*627*/                 OPC_CheckChild2Same, 3,
/*629*/                 OPC_CheckPredicate, 2, // Predicate_unindexedstore
/*631*/                 OPC_CheckPredicate, 3, // Predicate_store
/*633*/                 OPC_CheckComplexPat, /*CP*/0, /*#*/3, // SelectAddr:$dst #4 #5
/*636*/                 OPC_EmitMergeInputChains, 2, 0, 2, 
/*640*/                 OPC_MorphNodeTo, TARGET_VAL(MSP430::BIC8mr), 0|OPFL_Chain|OPFL_MemRefs,
                            1/*#VTs*/, MVT::i16, 3/*#Ops*/, 4, 5, 1, 
                        // Src: (st (and:i8 (xor:i8 GR8:i8:$src, -1:i8), (ld:i8 addr:iPTR:$dst)<<P:Predicate_unindexedload>><<P:Predicate_load>>), addr:iPTR:$dst)<<P:Predicate_unindexedstore>><<P:Predicate_store>> - Complexity = 37
                        // Dst: (BIC8mr:i16 addr:i16:$dst, GR8:i8:$src)
/*650*/               /*SwitchType*/ 24,  MVT::i16,// ->676
/*652*/                 OPC_MoveParent,
/*653*/                 OPC_CheckChild2Same, 3,
/*655*/                 OPC_CheckPredicate, 2, // Predicate_unindexedstore
/*657*/                 OPC_CheckPredicate, 3, // Predicate_store
/*659*/                 OPC_CheckComplexPat, /*CP*/0, /*#*/3, // SelectAddr:$dst #4 #5
/*662*/                 OPC_EmitMergeInputChains, 2, 0, 2, 
/*666*/                 OPC_MorphNodeTo, TARGET_VAL(MSP430::BIC16mr), 0|OPFL_Chain|OPFL_MemRefs,
                            1/*#VTs*/, MVT::i16, 3/*#Ops*/, 4, 5, 1, 
                        // Src: (st (and:i16 (xor:i16 GR16:i16:$src, -1:i16), (ld:i16 addr:iPTR:$dst)<<P:Predicate_unindexedload>><<P:Predicate_load>>), addr:iPTR:$dst)<<P:Predicate_unindexedstore>><<P:Predicate_store>> - Complexity = 37
                        // Dst: (BIC16mr:i16 addr:i16:$dst, GR16:i16:$src)
/*676*/               0, // EndSwitchType
/*677*/             0, /*End of Scope*/
/*678*/           0, // EndSwitchOpcode
/*679*/         /*Scope*/ 69, /*->749*/
/*680*/           OPC_RecordChild0, // #1 = $src
/*681*/           OPC_MoveChild, 1,
/*683*/           OPC_CheckOpcode, TARGET_VAL(ISD::LOAD),
/*686*/           OPC_RecordMemRef,
/*687*/           OPC_RecordNode, // #2 = 'ld' chained node
/*688*/           OPC_CheckFoldableChainNode,
/*689*/           OPC_RecordChild1, // #3 = $dst
/*690*/           OPC_CheckPredicate, 0, // Predicate_unindexedload
/*692*/           OPC_CheckPredicate, 1, // Predicate_load
/*694*/           OPC_MoveParent,
/*695*/           OPC_SwitchType /*2 cases */, 24,  MVT::i8,// ->722
/*698*/             OPC_MoveParent,
/*699*/             OPC_CheckChild2Same, 3,
/*701*/             OPC_CheckPredicate, 2, // Predicate_unindexedstore
/*703*/             OPC_CheckPredicate, 3, // Predicate_store
/*705*/             OPC_CheckComplexPat, /*CP*/0, /*#*/3, // SelectAddr:$dst #4 #5
/*708*/             OPC_EmitMergeInputChains, 2, 0, 2, 
/*712*/             OPC_MorphNodeTo, TARGET_VAL(MSP430::AND8mr), 0|OPFL_Chain|OPFL_MemRefs,
                        1/*#VTs*/, MVT::i16, 3/*#Ops*/, 4, 5, 1, 
                    // Src: (st (and:i8 GR8:i8:$src, (ld:i8 addr:iPTR:$dst)<<P:Predicate_unindexedload>><<P:Predicate_load>>), addr:iPTR:$dst)<<P:Predicate_unindexedstore>><<P:Predicate_store>> - Complexity = 29
                    // Dst: (AND8mr:i16 addr:i16:$dst, GR8:i8:$src)
/*722*/           /*SwitchType*/ 24,  MVT::i16,// ->748
/*724*/             OPC_MoveParent,
/*725*/             OPC_CheckChild2Same, 3,
/*727*/             OPC_CheckPredicate, 2, // Predicate_unindexedstore
/*729*/             OPC_CheckPredicate, 3, // Predicate_store
/*731*/             OPC_CheckComplexPat, /*CP*/0, /*#*/3, // SelectAddr:$dst #4 #5
/*734*/             OPC_EmitMergeInputChains, 2, 0, 2, 
/*738*/             OPC_MorphNodeTo, TARGET_VAL(MSP430::AND16mr), 0|OPFL_Chain|OPFL_MemRefs,
                        1/*#VTs*/, MVT::i16, 3/*#Ops*/, 4, 5, 1, 
                    // Src: (st (and:i16 GR16:i16:$src, (ld:i16 addr:iPTR:$dst)<<P:Predicate_unindexedload>><<P:Predicate_load>>), addr:iPTR:$dst)<<P:Predicate_unindexedstore>><<P:Predicate_store>> - Complexity = 29
                    // Dst: (AND16mr:i16 addr:i16:$dst, GR16:i16:$src)
/*748*/           0, // EndSwitchType
/*749*/         0, /*End of Scope*/
/*750*/       /*SwitchOpcode*/ 101|128,2/*357*/,  TARGET_VAL(ISD::ADD),// ->1111
/*754*/         OPC_Scope, 27|128,2/*283*/, /*->1040*/ // 2 children in Scope
/*757*/           OPC_MoveChild, 0,
/*759*/           OPC_CheckOpcode, TARGET_VAL(ISD::LOAD),
/*762*/           OPC_RecordMemRef,
/*763*/           OPC_RecordNode, // #1 = 'ld' chained node
/*764*/           OPC_CheckFoldableChainNode,
/*765*/           OPC_RecordChild1, // #2 = $dst
/*766*/           OPC_CheckPredicate, 0, // Predicate_unindexedload
/*768*/           OPC_CheckPredicate, 1, // Predicate_load
/*770*/           OPC_MoveParent,
/*771*/           OPC_Scope, 14|128,1/*142*/, /*->916*/ // 2 children in Scope
/*774*/             OPC_MoveChild, 1,
/*776*/             OPC_CheckOpcode, TARGET_VAL(ISD::LOAD),
/*779*/             OPC_RecordMemRef,
/*780*/             OPC_RecordNode, // #3 = 'ld' chained node
/*781*/             OPC_CheckFoldableChainNode,
/*782*/             OPC_RecordChild1, // #4 = $src
/*783*/             OPC_CheckPredicate, 0, // Predicate_unindexedload
/*785*/             OPC_CheckPredicate, 1, // Predicate_load
/*787*/             OPC_MoveParent,
/*788*/             OPC_SwitchType /*2 cases */, 61,  MVT::i8,// ->852
/*791*/               OPC_MoveParent,
/*792*/               OPC_Scope, 28, /*->822*/ // 2 children in Scope
/*794*/                 OPC_CheckChild2Same, 2,
/*796*/                 OPC_CheckPredicate, 2, // Predicate_unindexedstore
/*798*/                 OPC_CheckPredicate, 3, // Predicate_store
/*800*/                 OPC_CheckComplexPat, /*CP*/0, /*#*/2, // SelectAddr:$dst #5 #6
/*803*/                 OPC_CheckComplexPat, /*CP*/0, /*#*/4, // SelectAddr:$src #7 #8
/*806*/                 OPC_EmitMergeInputChains, 3, 0, 1, 3, 
/*811*/                 OPC_MorphNodeTo, TARGET_VAL(MSP430::ADD8mm), 0|OPFL_Chain|OPFL_MemRefs,
                            1/*#VTs*/, MVT::i16, 4/*#Ops*/, 5, 6, 7, 8, 
                        // Src: (st (add:i8 (ld:i8 addr:iPTR:$dst)<<P:Predicate_unindexedload>><<P:Predicate_load>>, (ld:i8 addr:iPTR:$src)<<P:Predicate_unindexedload>><<P:Predicate_load>>), addr:iPTR:$dst)<<P:Predicate_unindexedstore>><<P:Predicate_store>> - Complexity = 42
                        // Dst: (ADD8mm:i16 addr:i16:$dst, addr:i16:$src)
/*822*/               /*Scope*/ 28, /*->851*/
/*823*/                 OPC_CheckChild2Same, 4,
/*825*/                 OPC_CheckPredicate, 2, // Predicate_unindexedstore
/*827*/                 OPC_CheckPredicate, 3, // Predicate_store
/*829*/                 OPC_CheckComplexPat, /*CP*/0, /*#*/2, // SelectAddr:$src #5 #6
/*832*/                 OPC_CheckComplexPat, /*CP*/0, /*#*/4, // SelectAddr:$dst #7 #8
/*835*/                 OPC_EmitMergeInputChains, 3, 0, 1, 3, 
/*840*/                 OPC_MorphNodeTo, TARGET_VAL(MSP430::ADD8mm), 0|OPFL_Chain|OPFL_MemRefs,
                            1/*#VTs*/, MVT::i16, 4/*#Ops*/, 7, 8, 5, 6, 
                        // Src: (st (add:i8 (ld:i8 addr:iPTR:$src)<<P:Predicate_unindexedload>><<P:Predicate_load>>, (ld:i8 addr:iPTR:$dst)<<P:Predicate_unindexedload>><<P:Predicate_load>>), addr:iPTR:$dst)<<P:Predicate_unindexedstore>><<P:Predicate_store>> - Complexity = 42
                        // Dst: (ADD8mm:i16 addr:i16:$dst, addr:i16:$src)
/*851*/               0, /*End of Scope*/
/*852*/             /*SwitchType*/ 61,  MVT::i16,// ->915
/*854*/               OPC_MoveParent,
/*855*/               OPC_Scope, 28, /*->885*/ // 2 children in Scope
/*857*/                 OPC_CheckChild2Same, 2,
/*859*/                 OPC_CheckPredicate, 2, // Predicate_unindexedstore
/*861*/                 OPC_CheckPredicate, 3, // Predicate_store
/*863*/                 OPC_CheckComplexPat, /*CP*/0, /*#*/2, // SelectAddr:$dst #5 #6
/*866*/                 OPC_CheckComplexPat, /*CP*/0, /*#*/4, // SelectAddr:$src #7 #8
/*869*/                 OPC_EmitMergeInputChains, 3, 0, 1, 3, 
/*874*/                 OPC_MorphNodeTo, TARGET_VAL(MSP430::ADD16mm), 0|OPFL_Chain|OPFL_MemRefs,
                            1/*#VTs*/, MVT::i16, 4/*#Ops*/, 5, 6, 7, 8, 
                        // Src: (st (add:i16 (ld:i16 addr:iPTR:$dst)<<P:Predicate_unindexedload>><<P:Predicate_load>>, (ld:i16 addr:iPTR:$src)<<P:Predicate_unindexedload>><<P:Predicate_load>>), addr:iPTR:$dst)<<P:Predicate_unindexedstore>><<P:Predicate_store>> - Complexity = 42
                        // Dst: (ADD16mm:i16 addr:i16:$dst, addr:i16:$src)
/*885*/               /*Scope*/ 28, /*->914*/
/*886*/                 OPC_CheckChild2Same, 4,
/*888*/                 OPC_CheckPredicate, 2, // Predicate_unindexedstore
/*890*/                 OPC_CheckPredicate, 3, // Predicate_store
/*892*/                 OPC_CheckComplexPat, /*CP*/0, /*#*/2, // SelectAddr:$src #5 #6
/*895*/                 OPC_CheckComplexPat, /*CP*/0, /*#*/4, // SelectAddr:$dst #7 #8
/*898*/                 OPC_EmitMergeInputChains, 3, 0, 1, 3, 
/*903*/                 OPC_MorphNodeTo, TARGET_VAL(MSP430::ADD16mm), 0|OPFL_Chain|OPFL_MemRefs,
                            1/*#VTs*/, MVT::i16, 4/*#Ops*/, 7, 8, 5, 6, 
                        // Src: (st (add:i16 (ld:i16 addr:iPTR:$src)<<P:Predicate_unindexedload>><<P:Predicate_load>>, (ld:i16 addr:iPTR:$dst)<<P:Predicate_unindexedload>><<P:Predicate_load>>), addr:iPTR:$dst)<<P:Predicate_unindexedstore>><<P:Predicate_store>> - Complexity = 42
                        // Dst: (ADD16mm:i16 addr:i16:$dst, addr:i16:$src)
/*914*/               0, /*End of Scope*/
/*915*/             0, // EndSwitchType
/*916*/           /*Scope*/ 122, /*->1039*/
/*917*/             OPC_RecordChild1, // #3 = $src
/*918*/             OPC_Scope, 64, /*->984*/ // 3 children in Scope
/*920*/               OPC_MoveChild, 1,
/*922*/               OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*925*/               OPC_MoveParent,
/*926*/               OPC_SwitchType /*2 cases */, 26,  MVT::i8,// ->955
/*929*/                 OPC_MoveParent,
/*930*/                 OPC_CheckChild2Same, 2,
/*932*/                 OPC_CheckPredicate, 2, // Predicate_unindexedstore
/*934*/                 OPC_CheckPredicate, 3, // Predicate_store
/*936*/                 OPC_CheckComplexPat, /*CP*/0, /*#*/2, // SelectAddr:$dst #4 #5
/*939*/                 OPC_EmitMergeInputChains, 2, 0, 1, 
/*943*/                 OPC_EmitConvertToTarget, 3,
/*945*/                 OPC_MorphNodeTo, TARGET_VAL(MSP430::ADD8mi), 0|OPFL_Chain|OPFL_MemRefs,
                            1/*#VTs*/, MVT::i16, 3/*#Ops*/, 4, 5, 6, 
                        // Src: (st (add:i8 (ld:i8 addr:iPTR:$dst)<<P:Predicate_unindexedload>><<P:Predicate_load>>, (imm:i8):$src), addr:iPTR:$dst)<<P:Predicate_unindexedstore>><<P:Predicate_store>> - Complexity = 32
                        // Dst: (ADD8mi:i16 addr:i16:$dst, (imm:i8):$src)
/*955*/               /*SwitchType*/ 26,  MVT::i16,// ->983
/*957*/                 OPC_MoveParent,
/*958*/                 OPC_CheckChild2Same, 2,
/*960*/                 OPC_CheckPredicate, 2, // Predicate_unindexedstore
/*962*/                 OPC_CheckPredicate, 3, // Predicate_store
/*964*/                 OPC_CheckComplexPat, /*CP*/0, /*#*/2, // SelectAddr:$dst #4 #5
/*967*/                 OPC_EmitMergeInputChains, 2, 0, 1, 
/*971*/                 OPC_EmitConvertToTarget, 3,
/*973*/                 OPC_MorphNodeTo, TARGET_VAL(MSP430::ADD16mi), 0|OPFL_Chain|OPFL_MemRefs,
                            1/*#VTs*/, MVT::i16, 3/*#Ops*/, 4, 5, 6, 
                        // Src: (st (add:i16 (ld:i16 addr:iPTR:$dst)<<P:Predicate_unindexedload>><<P:Predicate_load>>, (imm:i16):$src), addr:iPTR:$dst)<<P:Predicate_unindexedstore>><<P:Predicate_store>> - Complexity = 32
                        // Dst: (ADD16mi:i16 addr:i16:$dst, (imm:i16):$src)
/*983*/               0, // EndSwitchType
/*984*/             /*Scope*/ 26, /*->1011*/
/*985*/               OPC_CheckType, MVT::i8,
/*987*/               OPC_MoveParent,
/*988*/               OPC_CheckChild2Same, 2,
/*990*/               OPC_CheckPredicate, 2, // Predicate_unindexedstore
/*992*/               OPC_CheckPredicate, 3, // Predicate_store
/*994*/               OPC_CheckComplexPat, /*CP*/0, /*#*/2, // SelectAddr:$dst #4 #5
/*997*/               OPC_EmitMergeInputChains, 2, 0, 1, 
/*1001*/              OPC_MorphNodeTo, TARGET_VAL(MSP430::ADD8mr), 0|OPFL_Chain|OPFL_MemRefs,
                          1/*#VTs*/, MVT::i16, 3/*#Ops*/, 4, 5, 3, 
                      // Src: (st (add:i8 (ld:i8 addr:iPTR:$dst)<<P:Predicate_unindexedload>><<P:Predicate_load>>, GR8:i8:$src), addr:iPTR:$dst)<<P:Predicate_unindexedstore>><<P:Predicate_store>> - Complexity = 29
                      // Dst: (ADD8mr:i16 addr:i16:$dst, GR8:i8:$src)
/*1011*/            /*Scope*/ 26, /*->1038*/
/*1012*/              OPC_CheckType, MVT::i16,
/*1014*/              OPC_MoveParent,
/*1015*/              OPC_CheckChild2Same, 2,
/*1017*/              OPC_CheckPredicate, 2, // Predicate_unindexedstore
/*1019*/              OPC_CheckPredicate, 3, // Predicate_store
/*1021*/              OPC_CheckComplexPat, /*CP*/0, /*#*/2, // SelectAddr:$dst #4 #5
/*1024*/              OPC_EmitMergeInputChains, 2, 0, 1, 
/*1028*/              OPC_MorphNodeTo, TARGET_VAL(MSP430::ADD16mr), 0|OPFL_Chain|OPFL_MemRefs,
                          1/*#VTs*/, MVT::i16, 3/*#Ops*/, 4, 5, 3, 
                      // Src: (st (add:i16 (ld:i16 addr:iPTR:$dst)<<P:Predicate_unindexedload>><<P:Predicate_load>>, GR16:i16:$src), addr:iPTR:$dst)<<P:Predicate_unindexedstore>><<P:Predicate_store>> - Complexity = 29
                      // Dst: (ADD16mr:i16 addr:i16:$dst, GR16:i16:$src)
/*1038*/            0, /*End of Scope*/
/*1039*/          0, /*End of Scope*/
/*1040*/        /*Scope*/ 69, /*->1110*/
/*1041*/          OPC_RecordChild0, // #1 = $src
/*1042*/          OPC_MoveChild, 1,
/*1044*/          OPC_CheckOpcode, TARGET_VAL(ISD::LOAD),
/*1047*/          OPC_RecordMemRef,
/*1048*/          OPC_RecordNode, // #2 = 'ld' chained node
/*1049*/          OPC_CheckFoldableChainNode,
/*1050*/          OPC_RecordChild1, // #3 = $dst
/*1051*/          OPC_CheckPredicate, 0, // Predicate_unindexedload
/*1053*/          OPC_CheckPredicate, 1, // Predicate_load
/*1055*/          OPC_MoveParent,
/*1056*/          OPC_SwitchType /*2 cases */, 24,  MVT::i8,// ->1083
/*1059*/            OPC_MoveParent,
/*1060*/            OPC_CheckChild2Same, 3,
/*1062*/            OPC_CheckPredicate, 2, // Predicate_unindexedstore
/*1064*/            OPC_CheckPredicate, 3, // Predicate_store
/*1066*/            OPC_CheckComplexPat, /*CP*/0, /*#*/3, // SelectAddr:$dst #4 #5
/*1069*/            OPC_EmitMergeInputChains, 2, 0, 2, 
/*1073*/            OPC_MorphNodeTo, TARGET_VAL(MSP430::ADD8mr), 0|OPFL_Chain|OPFL_MemRefs,
                        1/*#VTs*/, MVT::i16, 3/*#Ops*/, 4, 5, 1, 
                    // Src: (st (add:i8 GR8:i8:$src, (ld:i8 addr:iPTR:$dst)<<P:Predicate_unindexedload>><<P:Predicate_load>>), addr:iPTR:$dst)<<P:Predicate_unindexedstore>><<P:Predicate_store>> - Complexity = 29
                    // Dst: (ADD8mr:i16 addr:i16:$dst, GR8:i8:$src)
/*1083*/          /*SwitchType*/ 24,  MVT::i16,// ->1109
/*1085*/            OPC_MoveParent,
/*1086*/            OPC_CheckChild2Same, 3,
/*1088*/            OPC_CheckPredicate, 2, // Predicate_unindexedstore
/*1090*/            OPC_CheckPredicate, 3, // Predicate_store
/*1092*/            OPC_CheckComplexPat, /*CP*/0, /*#*/3, // SelectAddr:$dst #4 #5
/*1095*/            OPC_EmitMergeInputChains, 2, 0, 2, 
/*1099*/            OPC_MorphNodeTo, TARGET_VAL(MSP430::ADD16mr), 0|OPFL_Chain|OPFL_MemRefs,
                        1/*#VTs*/, MVT::i16, 3/*#Ops*/, 4, 5, 1, 
                    // Src: (st (add:i16 GR16:i16:$src, (ld:i16 addr:iPTR:$dst)<<P:Predicate_unindexedload>><<P:Predicate_load>>), addr:iPTR:$dst)<<P:Predicate_unindexedstore>><<P:Predicate_store>> - Complexity = 29
                    // Dst: (ADD16mr:i16 addr:i16:$dst, GR16:i16:$src)
/*1109*/          0, // EndSwitchType
/*1110*/        0, /*End of Scope*/
/*1111*/      /*SwitchOpcode*/ 6|128,3/*390*/,  TARGET_VAL(ISD::ADDE),// ->1505
/*1115*/        OPC_RecordNode, // #1 = 'adde' glue output node
/*1116*/        OPC_CaptureGlueInput,
/*1117*/        OPC_Scope, 52|128,2/*308*/, /*->1428*/ // 2 children in Scope
/*1120*/          OPC_MoveChild, 0,
/*1122*/          OPC_CheckOpcode, TARGET_VAL(ISD::LOAD),
/*1125*/          OPC_RecordMemRef,
/*1126*/          OPC_RecordNode, // #2 = 'ld' chained node
/*1127*/          OPC_CheckFoldableChainNode,
/*1128*/          OPC_RecordChild1, // #3 = $dst
/*1129*/          OPC_CheckPredicate, 0, // Predicate_unindexedload
/*1131*/          OPC_CheckPredicate, 1, // Predicate_load
/*1133*/          OPC_MoveParent,
/*1134*/          OPC_Scope, 26|128,1/*154*/, /*->1291*/ // 2 children in Scope
/*1137*/            OPC_MoveChild, 1,
/*1139*/            OPC_CheckOpcode, TARGET_VAL(ISD::LOAD),
/*1142*/            OPC_RecordMemRef,
/*1143*/            OPC_RecordNode, // #4 = 'ld' chained node
/*1144*/            OPC_CheckFoldableChainNode,
/*1145*/            OPC_RecordChild1, // #5 = $src
/*1146*/            OPC_CheckPredicate, 0, // Predicate_unindexedload
/*1148*/            OPC_CheckPredicate, 1, // Predicate_load
/*1150*/            OPC_MoveParent,
/*1151*/            OPC_SwitchType /*2 cases */, 67,  MVT::i8,// ->1221
/*1154*/              OPC_MoveParent,
/*1155*/              OPC_Scope, 31, /*->1188*/ // 2 children in Scope
/*1157*/                OPC_CheckChild2Same, 3,
/*1159*/                OPC_CheckPredicate, 2, // Predicate_unindexedstore
/*1161*/                OPC_CheckPredicate, 3, // Predicate_store
/*1163*/                OPC_CheckComplexPat, /*CP*/0, /*#*/3, // SelectAddr:$dst #6 #7
/*1166*/                OPC_CheckComplexPat, /*CP*/0, /*#*/5, // SelectAddr:$src #8 #9
/*1169*/                OPC_EmitMergeInputChains, 3, 0, 2, 4, 
/*1174*/                OPC_MarkGlueResults, 1, 1, 
/*1177*/                OPC_MorphNodeTo, TARGET_VAL(MSP430::ADC8mm), 0|OPFL_Chain|OPFL_GlueInput|OPFL_GlueOutput|OPFL_MemRefs,
                            1/*#VTs*/, MVT::i16, 4/*#Ops*/, 6, 7, 8, 9, 
                        // Src: (st (adde:i8 (ld:i8 addr:iPTR:$dst)<<P:Predicate_unindexedload>><<P:Predicate_load>>, (ld:i8 addr:iPTR:$src)<<P:Predicate_unindexedload>><<P:Predicate_load>>), addr:iPTR:$dst)<<P:Predicate_unindexedstore>><<P:Predicate_store>> - Complexity = 42
                        // Dst: (ADC8mm:i16 addr:i16:$dst, addr:i16:$src)
/*1188*/              /*Scope*/ 31, /*->1220*/
/*1189*/                OPC_CheckChild2Same, 5,
/*1191*/                OPC_CheckPredicate, 2, // Predicate_unindexedstore
/*1193*/                OPC_CheckPredicate, 3, // Predicate_store
/*1195*/                OPC_CheckComplexPat, /*CP*/0, /*#*/3, // SelectAddr:$src #6 #7
/*1198*/                OPC_CheckComplexPat, /*CP*/0, /*#*/5, // SelectAddr:$dst #8 #9
/*1201*/                OPC_EmitMergeInputChains, 3, 0, 2, 4, 
/*1206*/                OPC_MarkGlueResults, 1, 1, 
/*1209*/                OPC_MorphNodeTo, TARGET_VAL(MSP430::ADC8mm), 0|OPFL_Chain|OPFL_GlueInput|OPFL_GlueOutput|OPFL_MemRefs,
                            1/*#VTs*/, MVT::i16, 4/*#Ops*/, 8, 9, 6, 7, 
                        // Src: (st (adde:i8 (ld:i8 addr:iPTR:$src)<<P:Predicate_unindexedload>><<P:Predicate_load>>, (ld:i8 addr:iPTR:$dst)<<P:Predicate_unindexedload>><<P:Predicate_load>>), addr:iPTR:$dst)<<P:Predicate_unindexedstore>><<P:Predicate_store>> - Complexity = 42
                        // Dst: (ADC8mm:i16 addr:i16:$dst, addr:i16:$src)
/*1220*/              0, /*End of Scope*/
/*1221*/            /*SwitchType*/ 67,  MVT::i16,// ->1290
/*1223*/              OPC_MoveParent,
/*1224*/              OPC_Scope, 31, /*->1257*/ // 2 children in Scope
/*1226*/                OPC_CheckChild2Same, 3,
/*1228*/                OPC_CheckPredicate, 2, // Predicate_unindexedstore
/*1230*/                OPC_CheckPredicate, 3, // Predicate_store
/*1232*/                OPC_CheckComplexPat, /*CP*/0, /*#*/3, // SelectAddr:$dst #6 #7
/*1235*/                OPC_CheckComplexPat, /*CP*/0, /*#*/5, // SelectAddr:$src #8 #9
/*1238*/                OPC_EmitMergeInputChains, 3, 0, 2, 4, 
/*1243*/                OPC_MarkGlueResults, 1, 1, 
/*1246*/                OPC_MorphNodeTo, TARGET_VAL(MSP430::ADC16mm), 0|OPFL_Chain|OPFL_GlueInput|OPFL_GlueOutput|OPFL_MemRefs,
                            1/*#VTs*/, MVT::i16, 4/*#Ops*/, 6, 7, 8, 9, 
                        // Src: (st (adde:i16 (ld:i16 addr:iPTR:$dst)<<P:Predicate_unindexedload>><<P:Predicate_load>>, (ld:i16 addr:iPTR:$src)<<P:Predicate_unindexedload>><<P:Predicate_load>>), addr:iPTR:$dst)<<P:Predicate_unindexedstore>><<P:Predicate_store>> - Complexity = 42
                        // Dst: (ADC16mm:i16 addr:i16:$dst, addr:i16:$src)
/*1257*/              /*Scope*/ 31, /*->1289*/
/*1258*/                OPC_CheckChild2Same, 5,
/*1260*/                OPC_CheckPredicate, 2, // Predicate_unindexedstore
/*1262*/                OPC_CheckPredicate, 3, // Predicate_store
/*1264*/                OPC_CheckComplexPat, /*CP*/0, /*#*/3, // SelectAddr:$src #6 #7
/*1267*/                OPC_CheckComplexPat, /*CP*/0, /*#*/5, // SelectAddr:$dst #8 #9
/*1270*/                OPC_EmitMergeInputChains, 3, 0, 2, 4, 
/*1275*/                OPC_MarkGlueResults, 1, 1, 
/*1278*/                OPC_MorphNodeTo, TARGET_VAL(MSP430::ADC16mm), 0|OPFL_Chain|OPFL_GlueInput|OPFL_GlueOutput|OPFL_MemRefs,
                            1/*#VTs*/, MVT::i16, 4/*#Ops*/, 8, 9, 6, 7, 
                        // Src: (st (adde:i16 (ld:i16 addr:iPTR:$src)<<P:Predicate_unindexedload>><<P:Predicate_load>>, (ld:i16 addr:iPTR:$dst)<<P:Predicate_unindexedload>><<P:Predicate_load>>), addr:iPTR:$dst)<<P:Predicate_unindexedstore>><<P:Predicate_store>> - Complexity = 42
                        // Dst: (ADC16mm:i16 addr:i16:$dst, addr:i16:$src)
/*1289*/              0, /*End of Scope*/
/*1290*/            0, // EndSwitchType
/*1291*/          /*Scope*/ 6|128,1/*134*/, /*->1427*/
/*1293*/            OPC_RecordChild1, // #4 = $src
/*1294*/            OPC_Scope, 70, /*->1366*/ // 3 children in Scope
/*1296*/              OPC_MoveChild, 1,
/*1298*/              OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*1301*/              OPC_MoveParent,
/*1302*/              OPC_SwitchType /*2 cases */, 29,  MVT::i8,// ->1334
/*1305*/                OPC_MoveParent,
/*1306*/                OPC_CheckChild2Same, 3,
/*1308*/                OPC_CheckPredicate, 2, // Predicate_unindexedstore
/*1310*/                OPC_CheckPredicate, 3, // Predicate_store
/*1312*/                OPC_CheckComplexPat, /*CP*/0, /*#*/3, // SelectAddr:$dst #5 #6
/*1315*/                OPC_EmitMergeInputChains, 2, 0, 2, 
/*1319*/                OPC_EmitConvertToTarget, 4,
/*1321*/                OPC_MarkGlueResults, 1, 1, 
/*1324*/                OPC_MorphNodeTo, TARGET_VAL(MSP430::ADC8mi), 0|OPFL_Chain|OPFL_GlueInput|OPFL_GlueOutput|OPFL_MemRefs,
                            1/*#VTs*/, MVT::i16, 3/*#Ops*/, 5, 6, 7, 
                        // Src: (st (adde:i8 (ld:i8 addr:iPTR:$dst)<<P:Predicate_unindexedload>><<P:Predicate_load>>, (imm:i8):$src), addr:iPTR:$dst)<<P:Predicate_unindexedstore>><<P:Predicate_store>> - Complexity = 32
                        // Dst: (ADC8mi:i16 addr:i16:$dst, (imm:i8):$src)
/*1334*/              /*SwitchType*/ 29,  MVT::i16,// ->1365
/*1336*/                OPC_MoveParent,
/*1337*/                OPC_CheckChild2Same, 3,
/*1339*/                OPC_CheckPredicate, 2, // Predicate_unindexedstore
/*1341*/                OPC_CheckPredicate, 3, // Predicate_store
/*1343*/                OPC_CheckComplexPat, /*CP*/0, /*#*/3, // SelectAddr:$dst #5 #6
/*1346*/                OPC_EmitMergeInputChains, 2, 0, 2, 
/*1350*/                OPC_EmitConvertToTarget, 4,
/*1352*/                OPC_MarkGlueResults, 1, 1, 
/*1355*/                OPC_MorphNodeTo, TARGET_VAL(MSP430::ADC16mi), 0|OPFL_Chain|OPFL_GlueInput|OPFL_GlueOutput|OPFL_MemRefs,
                            1/*#VTs*/, MVT::i16, 3/*#Ops*/, 5, 6, 7, 
                        // Src: (st (adde:i16 (ld:i16 addr:iPTR:$dst)<<P:Predicate_unindexedload>><<P:Predicate_load>>, (imm:i16):$src), addr:iPTR:$dst)<<P:Predicate_unindexedstore>><<P:Predicate_store>> - Complexity = 32
                        // Dst: (ADC16mi:i16 addr:i16:$dst, (imm:i16):$src)
/*1365*/              0, // EndSwitchType
/*1366*/            /*Scope*/ 29, /*->1396*/
/*1367*/              OPC_CheckType, MVT::i8,
/*1369*/              OPC_MoveParent,
/*1370*/              OPC_CheckChild2Same, 3,
/*1372*/              OPC_CheckPredicate, 2, // Predicate_unindexedstore
/*1374*/              OPC_CheckPredicate, 3, // Predicate_store
/*1376*/              OPC_CheckComplexPat, /*CP*/0, /*#*/3, // SelectAddr:$dst #5 #6
/*1379*/              OPC_EmitMergeInputChains, 2, 0, 2, 
/*1383*/              OPC_MarkGlueResults, 1, 1, 
/*1386*/              OPC_MorphNodeTo, TARGET_VAL(MSP430::ADC8mr), 0|OPFL_Chain|OPFL_GlueInput|OPFL_GlueOutput|OPFL_MemRefs,
                          1/*#VTs*/, MVT::i16, 3/*#Ops*/, 5, 6, 4, 
                      // Src: (st (adde:i8 (ld:i8 addr:iPTR:$dst)<<P:Predicate_unindexedload>><<P:Predicate_load>>, GR8:i8:$src), addr:iPTR:$dst)<<P:Predicate_unindexedstore>><<P:Predicate_store>> - Complexity = 29
                      // Dst: (ADC8mr:i16 addr:i16:$dst, GR8:i8:$src)
/*1396*/            /*Scope*/ 29, /*->1426*/
/*1397*/              OPC_CheckType, MVT::i16,
/*1399*/              OPC_MoveParent,
/*1400*/              OPC_CheckChild2Same, 3,
/*1402*/              OPC_CheckPredicate, 2, // Predicate_unindexedstore
/*1404*/              OPC_CheckPredicate, 3, // Predicate_store
/*1406*/              OPC_CheckComplexPat, /*CP*/0, /*#*/3, // SelectAddr:$dst #5 #6
/*1409*/              OPC_EmitMergeInputChains, 2, 0, 2, 
/*1413*/              OPC_MarkGlueResults, 1, 1, 
/*1416*/              OPC_MorphNodeTo, TARGET_VAL(MSP430::ADC16mr), 0|OPFL_Chain|OPFL_GlueInput|OPFL_GlueOutput|OPFL_MemRefs,
                          1/*#VTs*/, MVT::i16, 3/*#Ops*/, 5, 6, 4, 
                      // Src: (st (adde:i16 (ld:i16 addr:iPTR:$dst)<<P:Predicate_unindexedload>><<P:Predicate_load>>, GR16:i16:$src), addr:iPTR:$dst)<<P:Predicate_unindexedstore>><<P:Predicate_store>> - Complexity = 29
                      // Dst: (ADC16mr:i16 addr:i16:$dst, GR16:i16:$src)
/*1426*/            0, /*End of Scope*/
/*1427*/          0, /*End of Scope*/
/*1428*/        /*Scope*/ 75, /*->1504*/
/*1429*/          OPC_RecordChild0, // #2 = $src
/*1430*/          OPC_MoveChild, 1,
/*1432*/          OPC_CheckOpcode, TARGET_VAL(ISD::LOAD),
/*1435*/          OPC_RecordMemRef,
/*1436*/          OPC_RecordNode, // #3 = 'ld' chained node
/*1437*/          OPC_CheckFoldableChainNode,
/*1438*/          OPC_RecordChild1, // #4 = $dst
/*1439*/          OPC_CheckPredicate, 0, // Predicate_unindexedload
/*1441*/          OPC_CheckPredicate, 1, // Predicate_load
/*1443*/          OPC_MoveParent,
/*1444*/          OPC_SwitchType /*2 cases */, 27,  MVT::i8,// ->1474
/*1447*/            OPC_MoveParent,
/*1448*/            OPC_CheckChild2Same, 4,
/*1450*/            OPC_CheckPredicate, 2, // Predicate_unindexedstore
/*1452*/            OPC_CheckPredicate, 3, // Predicate_store
/*1454*/            OPC_CheckComplexPat, /*CP*/0, /*#*/4, // SelectAddr:$dst #5 #6
/*1457*/            OPC_EmitMergeInputChains, 2, 0, 3, 
/*1461*/            OPC_MarkGlueResults, 1, 1, 
/*1464*/            OPC_MorphNodeTo, TARGET_VAL(MSP430::ADC8mr), 0|OPFL_Chain|OPFL_GlueInput|OPFL_GlueOutput|OPFL_MemRefs,
                        1/*#VTs*/, MVT::i16, 3/*#Ops*/, 5, 6, 2, 
                    // Src: (st (adde:i8 GR8:i8:$src, (ld:i8 addr:iPTR:$dst)<<P:Predicate_unindexedload>><<P:Predicate_load>>), addr:iPTR:$dst)<<P:Predicate_unindexedstore>><<P:Predicate_store>> - Complexity = 29
                    // Dst: (ADC8mr:i16 addr:i16:$dst, GR8:i8:$src)
/*1474*/          /*SwitchType*/ 27,  MVT::i16,// ->1503
/*1476*/            OPC_MoveParent,
/*1477*/            OPC_CheckChild2Same, 4,
/*1479*/            OPC_CheckPredicate, 2, // Predicate_unindexedstore
/*1481*/            OPC_CheckPredicate, 3, // Predicate_store
/*1483*/            OPC_CheckComplexPat, /*CP*/0, /*#*/4, // SelectAddr:$dst #5 #6
/*1486*/            OPC_EmitMergeInputChains, 2, 0, 3, 
/*1490*/            OPC_MarkGlueResults, 1, 1, 
/*1493*/            OPC_MorphNodeTo, TARGET_VAL(MSP430::ADC16mr), 0|OPFL_Chain|OPFL_GlueInput|OPFL_GlueOutput|OPFL_MemRefs,
                        1/*#VTs*/, MVT::i16, 3/*#Ops*/, 5, 6, 2, 
                    // Src: (st (adde:i16 GR16:i16:$src, (ld:i16 addr:iPTR:$dst)<<P:Predicate_unindexedload>><<P:Predicate_load>>), addr:iPTR:$dst)<<P:Predicate_unindexedstore>><<P:Predicate_store>> - Complexity = 29
                    // Dst: (ADC16mr:i16 addr:i16:$dst, GR16:i16:$src)
/*1503*/          0, // EndSwitchType
/*1504*/        0, /*End of Scope*/
/*1505*/      /*SwitchOpcode*/ 101|128,2/*357*/,  TARGET_VAL(ISD::OR),// ->1866
/*1509*/        OPC_Scope, 27|128,2/*283*/, /*->1795*/ // 2 children in Scope
/*1512*/          OPC_MoveChild, 0,
/*1514*/          OPC_CheckOpcode, TARGET_VAL(ISD::LOAD),
/*1517*/          OPC_RecordMemRef,
/*1518*/          OPC_RecordNode, // #1 = 'ld' chained node
/*1519*/          OPC_CheckFoldableChainNode,
/*1520*/          OPC_RecordChild1, // #2 = $dst
/*1521*/          OPC_CheckPredicate, 0, // Predicate_unindexedload
/*1523*/          OPC_CheckPredicate, 1, // Predicate_load
/*1525*/          OPC_MoveParent,
/*1526*/          OPC_Scope, 14|128,1/*142*/, /*->1671*/ // 2 children in Scope
/*1529*/            OPC_MoveChild, 1,
/*1531*/            OPC_CheckOpcode, TARGET_VAL(ISD::LOAD),
/*1534*/            OPC_RecordMemRef,
/*1535*/            OPC_RecordNode, // #3 = 'ld' chained node
/*1536*/            OPC_CheckFoldableChainNode,
/*1537*/            OPC_RecordChild1, // #4 = $src
/*1538*/            OPC_CheckPredicate, 0, // Predicate_unindexedload
/*1540*/            OPC_CheckPredicate, 1, // Predicate_load
/*1542*/            OPC_MoveParent,
/*1543*/            OPC_SwitchType /*2 cases */, 61,  MVT::i8,// ->1607
/*1546*/              OPC_MoveParent,
/*1547*/              OPC_Scope, 28, /*->1577*/ // 2 children in Scope
/*1549*/                OPC_CheckChild2Same, 2,
/*1551*/                OPC_CheckPredicate, 2, // Predicate_unindexedstore
/*1553*/                OPC_CheckPredicate, 3, // Predicate_store
/*1555*/                OPC_CheckComplexPat, /*CP*/0, /*#*/2, // SelectAddr:$dst #5 #6
/*1558*/                OPC_CheckComplexPat, /*CP*/0, /*#*/4, // SelectAddr:$src #7 #8
/*1561*/                OPC_EmitMergeInputChains, 3, 0, 1, 3, 
/*1566*/                OPC_MorphNodeTo, TARGET_VAL(MSP430::OR8mm), 0|OPFL_Chain|OPFL_MemRefs,
                            1/*#VTs*/, MVT::i16, 4/*#Ops*/, 5, 6, 7, 8, 
                        // Src: (st (or:i8 (ld:i8 addr:iPTR:$dst)<<P:Predicate_unindexedload>><<P:Predicate_load>>, (ld:i8 addr:iPTR:$src)<<P:Predicate_unindexedload>><<P:Predicate_load>>), addr:iPTR:$dst)<<P:Predicate_unindexedstore>><<P:Predicate_store>> - Complexity = 42
                        // Dst: (OR8mm:i16 addr:i16:$dst, addr:i16:$src)
/*1577*/              /*Scope*/ 28, /*->1606*/
/*1578*/                OPC_CheckChild2Same, 4,
/*1580*/                OPC_CheckPredicate, 2, // Predicate_unindexedstore
/*1582*/                OPC_CheckPredicate, 3, // Predicate_store
/*1584*/                OPC_CheckComplexPat, /*CP*/0, /*#*/2, // SelectAddr:$src #5 #6
/*1587*/                OPC_CheckComplexPat, /*CP*/0, /*#*/4, // SelectAddr:$dst #7 #8
/*1590*/                OPC_EmitMergeInputChains, 3, 0, 1, 3, 
/*1595*/                OPC_MorphNodeTo, TARGET_VAL(MSP430::OR8mm), 0|OPFL_Chain|OPFL_MemRefs,
                            1/*#VTs*/, MVT::i16, 4/*#Ops*/, 7, 8, 5, 6, 
                        // Src: (st (or:i8 (ld:i8 addr:iPTR:$src)<<P:Predicate_unindexedload>><<P:Predicate_load>>, (ld:i8 addr:iPTR:$dst)<<P:Predicate_unindexedload>><<P:Predicate_load>>), addr:iPTR:$dst)<<P:Predicate_unindexedstore>><<P:Predicate_store>> - Complexity = 42
                        // Dst: (OR8mm:i16 addr:i16:$dst, addr:i16:$src)
/*1606*/              0, /*End of Scope*/
/*1607*/            /*SwitchType*/ 61,  MVT::i16,// ->1670
/*1609*/              OPC_MoveParent,
/*1610*/              OPC_Scope, 28, /*->1640*/ // 2 children in Scope
/*1612*/                OPC_CheckChild2Same, 2,
/*1614*/                OPC_CheckPredicate, 2, // Predicate_unindexedstore
/*1616*/                OPC_CheckPredicate, 3, // Predicate_store
/*1618*/                OPC_CheckComplexPat, /*CP*/0, /*#*/2, // SelectAddr:$dst #5 #6
/*1621*/                OPC_CheckComplexPat, /*CP*/0, /*#*/4, // SelectAddr:$src #7 #8
/*1624*/                OPC_EmitMergeInputChains, 3, 0, 1, 3, 
/*1629*/                OPC_MorphNodeTo, TARGET_VAL(MSP430::OR16mm), 0|OPFL_Chain|OPFL_MemRefs,
                            1/*#VTs*/, MVT::i16, 4/*#Ops*/, 5, 6, 7, 8, 
                        // Src: (st (or:i16 (ld:i16 addr:iPTR:$dst)<<P:Predicate_unindexedload>><<P:Predicate_load>>, (ld:i16 addr:iPTR:$src)<<P:Predicate_unindexedload>><<P:Predicate_load>>), addr:iPTR:$dst)<<P:Predicate_unindexedstore>><<P:Predicate_store>> - Complexity = 42
                        // Dst: (OR16mm:i16 addr:i16:$dst, addr:i16:$src)
/*1640*/              /*Scope*/ 28, /*->1669*/
/*1641*/                OPC_CheckChild2Same, 4,
/*1643*/                OPC_CheckPredicate, 2, // Predicate_unindexedstore
/*1645*/                OPC_CheckPredicate, 3, // Predicate_store
/*1647*/                OPC_CheckComplexPat, /*CP*/0, /*#*/2, // SelectAddr:$src #5 #6
/*1650*/                OPC_CheckComplexPat, /*CP*/0, /*#*/4, // SelectAddr:$dst #7 #8
/*1653*/                OPC_EmitMergeInputChains, 3, 0, 1, 3, 
/*1658*/                OPC_MorphNodeTo, TARGET_VAL(MSP430::OR16mm), 0|OPFL_Chain|OPFL_MemRefs,
                            1/*#VTs*/, MVT::i16, 4/*#Ops*/, 7, 8, 5, 6, 
                        // Src: (st (or:i16 (ld:i16 addr:iPTR:$src)<<P:Predicate_unindexedload>><<P:Predicate_load>>, (ld:i16 addr:iPTR:$dst)<<P:Predicate_unindexedload>><<P:Predicate_load>>), addr:iPTR:$dst)<<P:Predicate_unindexedstore>><<P:Predicate_store>> - Complexity = 42
                        // Dst: (OR16mm:i16 addr:i16:$dst, addr:i16:$src)
/*1669*/              0, /*End of Scope*/
/*1670*/            0, // EndSwitchType
/*1671*/          /*Scope*/ 122, /*->1794*/
/*1672*/            OPC_RecordChild1, // #3 = $src
/*1673*/            OPC_Scope, 64, /*->1739*/ // 3 children in Scope
/*1675*/              OPC_MoveChild, 1,
/*1677*/              OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*1680*/              OPC_MoveParent,
/*1681*/              OPC_SwitchType /*2 cases */, 26,  MVT::i8,// ->1710
/*1684*/                OPC_MoveParent,
/*1685*/                OPC_CheckChild2Same, 2,
/*1687*/                OPC_CheckPredicate, 2, // Predicate_unindexedstore
/*1689*/                OPC_CheckPredicate, 3, // Predicate_store
/*1691*/                OPC_CheckComplexPat, /*CP*/0, /*#*/2, // SelectAddr:$dst #4 #5
/*1694*/                OPC_EmitMergeInputChains, 2, 0, 1, 
/*1698*/                OPC_EmitConvertToTarget, 3,
/*1700*/                OPC_MorphNodeTo, TARGET_VAL(MSP430::OR8mi), 0|OPFL_Chain|OPFL_MemRefs,
                            1/*#VTs*/, MVT::i16, 3/*#Ops*/, 4, 5, 6, 
                        // Src: (st (or:i8 (ld:i8 addr:iPTR:$dst)<<P:Predicate_unindexedload>><<P:Predicate_load>>, (imm:i8):$src), addr:iPTR:$dst)<<P:Predicate_unindexedstore>><<P:Predicate_store>> - Complexity = 32
                        // Dst: (OR8mi:i16 addr:i16:$dst, (imm:i8):$src)
/*1710*/              /*SwitchType*/ 26,  MVT::i16,// ->1738
/*1712*/                OPC_MoveParent,
/*1713*/                OPC_CheckChild2Same, 2,
/*1715*/                OPC_CheckPredicate, 2, // Predicate_unindexedstore
/*1717*/                OPC_CheckPredicate, 3, // Predicate_store
/*1719*/                OPC_CheckComplexPat, /*CP*/0, /*#*/2, // SelectAddr:$dst #4 #5
/*1722*/                OPC_EmitMergeInputChains, 2, 0, 1, 
/*1726*/                OPC_EmitConvertToTarget, 3,
/*1728*/                OPC_MorphNodeTo, TARGET_VAL(MSP430::OR16mi), 0|OPFL_Chain|OPFL_MemRefs,
                            1/*#VTs*/, MVT::i16, 3/*#Ops*/, 4, 5, 6, 
                        // Src: (st (or:i16 (ld:i16 addr:iPTR:$dst)<<P:Predicate_unindexedload>><<P:Predicate_load>>, (imm:i16):$src), addr:iPTR:$dst)<<P:Predicate_unindexedstore>><<P:Predicate_store>> - Complexity = 32
                        // Dst: (OR16mi:i16 addr:i16:$dst, (imm:i16):$src)
/*1738*/              0, // EndSwitchType
/*1739*/            /*Scope*/ 26, /*->1766*/
/*1740*/              OPC_CheckType, MVT::i8,
/*1742*/              OPC_MoveParent,
/*1743*/              OPC_CheckChild2Same, 2,
/*1745*/              OPC_CheckPredicate, 2, // Predicate_unindexedstore
/*1747*/              OPC_CheckPredicate, 3, // Predicate_store
/*1749*/              OPC_CheckComplexPat, /*CP*/0, /*#*/2, // SelectAddr:$dst #4 #5
/*1752*/              OPC_EmitMergeInputChains, 2, 0, 1, 
/*1756*/              OPC_MorphNodeTo, TARGET_VAL(MSP430::OR8mr), 0|OPFL_Chain|OPFL_MemRefs,
                          1/*#VTs*/, MVT::i16, 3/*#Ops*/, 4, 5, 3, 
                      // Src: (st (or:i8 (ld:i8 addr:iPTR:$dst)<<P:Predicate_unindexedload>><<P:Predicate_load>>, GR8:i8:$src), addr:iPTR:$dst)<<P:Predicate_unindexedstore>><<P:Predicate_store>> - Complexity = 29
                      // Dst: (OR8mr:i16 addr:i16:$dst, GR8:i8:$src)
/*1766*/            /*Scope*/ 26, /*->1793*/
/*1767*/              OPC_CheckType, MVT::i16,
/*1769*/              OPC_MoveParent,
/*1770*/              OPC_CheckChild2Same, 2,
/*1772*/              OPC_CheckPredicate, 2, // Predicate_unindexedstore
/*1774*/              OPC_CheckPredicate, 3, // Predicate_store
/*1776*/              OPC_CheckComplexPat, /*CP*/0, /*#*/2, // SelectAddr:$dst #4 #5
/*1779*/              OPC_EmitMergeInputChains, 2, 0, 1, 
/*1783*/              OPC_MorphNodeTo, TARGET_VAL(MSP430::OR16mr), 0|OPFL_Chain|OPFL_MemRefs,
                          1/*#VTs*/, MVT::i16, 3/*#Ops*/, 4, 5, 3, 
                      // Src: (st (or:i16 (ld:i16 addr:iPTR:$dst)<<P:Predicate_unindexedload>><<P:Predicate_load>>, GR16:i16:$src), addr:iPTR:$dst)<<P:Predicate_unindexedstore>><<P:Predicate_store>> - Complexity = 29
                      // Dst: (OR16mr:i16 addr:i16:$dst, GR16:i16:$src)
/*1793*/            0, /*End of Scope*/
/*1794*/          0, /*End of Scope*/
/*1795*/        /*Scope*/ 69, /*->1865*/
/*1796*/          OPC_RecordChild0, // #1 = $src
/*1797*/          OPC_MoveChild, 1,
/*1799*/          OPC_CheckOpcode, TARGET_VAL(ISD::LOAD),
/*1802*/          OPC_RecordMemRef,
/*1803*/          OPC_RecordNode, // #2 = 'ld' chained node
/*1804*/          OPC_CheckFoldableChainNode,
/*1805*/          OPC_RecordChild1, // #3 = $dst
/*1806*/          OPC_CheckPredicate, 0, // Predicate_unindexedload
/*1808*/          OPC_CheckPredicate, 1, // Predicate_load
/*1810*/          OPC_MoveParent,
/*1811*/          OPC_SwitchType /*2 cases */, 24,  MVT::i8,// ->1838
/*1814*/            OPC_MoveParent,
/*1815*/            OPC_CheckChild2Same, 3,
/*1817*/            OPC_CheckPredicate, 2, // Predicate_unindexedstore
/*1819*/            OPC_CheckPredicate, 3, // Predicate_store
/*1821*/            OPC_CheckComplexPat, /*CP*/0, /*#*/3, // SelectAddr:$dst #4 #5
/*1824*/            OPC_EmitMergeInputChains, 2, 0, 2, 
/*1828*/            OPC_MorphNodeTo, TARGET_VAL(MSP430::OR8mr), 0|OPFL_Chain|OPFL_MemRefs,
                        1/*#VTs*/, MVT::i16, 3/*#Ops*/, 4, 5, 1, 
                    // Src: (st (or:i8 GR8:i8:$src, (ld:i8 addr:iPTR:$dst)<<P:Predicate_unindexedload>><<P:Predicate_load>>), addr:iPTR:$dst)<<P:Predicate_unindexedstore>><<P:Predicate_store>> - Complexity = 29
                    // Dst: (OR8mr:i16 addr:i16:$dst, GR8:i8:$src)
/*1838*/          /*SwitchType*/ 24,  MVT::i16,// ->1864
/*1840*/            OPC_MoveParent,
/*1841*/            OPC_CheckChild2Same, 3,
/*1843*/            OPC_CheckPredicate, 2, // Predicate_unindexedstore
/*1845*/            OPC_CheckPredicate, 3, // Predicate_store
/*1847*/            OPC_CheckComplexPat, /*CP*/0, /*#*/3, // SelectAddr:$dst #4 #5
/*1850*/            OPC_EmitMergeInputChains, 2, 0, 2, 
/*1854*/            OPC_MorphNodeTo, TARGET_VAL(MSP430::OR16mr), 0|OPFL_Chain|OPFL_MemRefs,
                        1/*#VTs*/, MVT::i16, 3/*#Ops*/, 4, 5, 1, 
                    // Src: (st (or:i16 GR16:i16:$src, (ld:i16 addr:iPTR:$dst)<<P:Predicate_unindexedload>><<P:Predicate_load>>), addr:iPTR:$dst)<<P:Predicate_unindexedstore>><<P:Predicate_store>> - Complexity = 29
                    // Dst: (OR16mr:i16 addr:i16:$dst, GR16:i16:$src)
/*1864*/          0, // EndSwitchType
/*1865*/        0, /*End of Scope*/
/*1866*/      /*SwitchOpcode*/ 101|128,2/*357*/,  TARGET_VAL(ISD::XOR),// ->2227
/*1870*/        OPC_Scope, 27|128,2/*283*/, /*->2156*/ // 2 children in Scope
/*1873*/          OPC_MoveChild, 0,
/*1875*/          OPC_CheckOpcode, TARGET_VAL(ISD::LOAD),
/*1878*/          OPC_RecordMemRef,
/*1879*/          OPC_RecordNode, // #1 = 'ld' chained node
/*1880*/          OPC_CheckFoldableChainNode,
/*1881*/          OPC_RecordChild1, // #2 = $dst
/*1882*/          OPC_CheckPredicate, 0, // Predicate_unindexedload
/*1884*/          OPC_CheckPredicate, 1, // Predicate_load
/*1886*/          OPC_MoveParent,
/*1887*/          OPC_Scope, 14|128,1/*142*/, /*->2032*/ // 2 children in Scope
/*1890*/            OPC_MoveChild, 1,
/*1892*/            OPC_CheckOpcode, TARGET_VAL(ISD::LOAD),
/*1895*/            OPC_RecordMemRef,
/*1896*/            OPC_RecordNode, // #3 = 'ld' chained node
/*1897*/            OPC_CheckFoldableChainNode,
/*1898*/            OPC_RecordChild1, // #4 = $src
/*1899*/            OPC_CheckPredicate, 0, // Predicate_unindexedload
/*1901*/            OPC_CheckPredicate, 1, // Predicate_load
/*1903*/            OPC_MoveParent,
/*1904*/            OPC_SwitchType /*2 cases */, 61,  MVT::i8,// ->1968
/*1907*/              OPC_MoveParent,
/*1908*/              OPC_Scope, 28, /*->1938*/ // 2 children in Scope
/*1910*/                OPC_CheckChild2Same, 2,
/*1912*/                OPC_CheckPredicate, 2, // Predicate_unindexedstore
/*1914*/                OPC_CheckPredicate, 3, // Predicate_store
/*1916*/                OPC_CheckComplexPat, /*CP*/0, /*#*/2, // SelectAddr:$dst #5 #6
/*1919*/                OPC_CheckComplexPat, /*CP*/0, /*#*/4, // SelectAddr:$src #7 #8
/*1922*/                OPC_EmitMergeInputChains, 3, 0, 1, 3, 
/*1927*/                OPC_MorphNodeTo, TARGET_VAL(MSP430::XOR8mm), 0|OPFL_Chain|OPFL_MemRefs,
                            1/*#VTs*/, MVT::i16, 4/*#Ops*/, 5, 6, 7, 8, 
                        // Src: (st (xor:i8 (ld:i8 addr:iPTR:$dst)<<P:Predicate_unindexedload>><<P:Predicate_load>>, (ld:i8 addr:iPTR:$src)<<P:Predicate_unindexedload>><<P:Predicate_load>>), addr:iPTR:$dst)<<P:Predicate_unindexedstore>><<P:Predicate_store>> - Complexity = 42
                        // Dst: (XOR8mm:i16 addr:i16:$dst, addr:i16:$src)
/*1938*/              /*Scope*/ 28, /*->1967*/
/*1939*/                OPC_CheckChild2Same, 4,
/*1941*/                OPC_CheckPredicate, 2, // Predicate_unindexedstore
/*1943*/                OPC_CheckPredicate, 3, // Predicate_store
/*1945*/                OPC_CheckComplexPat, /*CP*/0, /*#*/2, // SelectAddr:$src #5 #6
/*1948*/                OPC_CheckComplexPat, /*CP*/0, /*#*/4, // SelectAddr:$dst #7 #8
/*1951*/                OPC_EmitMergeInputChains, 3, 0, 1, 3, 
/*1956*/                OPC_MorphNodeTo, TARGET_VAL(MSP430::XOR8mm), 0|OPFL_Chain|OPFL_MemRefs,
                            1/*#VTs*/, MVT::i16, 4/*#Ops*/, 7, 8, 5, 6, 
                        // Src: (st (xor:i8 (ld:i8 addr:iPTR:$src)<<P:Predicate_unindexedload>><<P:Predicate_load>>, (ld:i8 addr:iPTR:$dst)<<P:Predicate_unindexedload>><<P:Predicate_load>>), addr:iPTR:$dst)<<P:Predicate_unindexedstore>><<P:Predicate_store>> - Complexity = 42
                        // Dst: (XOR8mm:i16 addr:i16:$dst, addr:i16:$src)
/*1967*/              0, /*End of Scope*/
/*1968*/            /*SwitchType*/ 61,  MVT::i16,// ->2031
/*1970*/              OPC_MoveParent,
/*1971*/              OPC_Scope, 28, /*->2001*/ // 2 children in Scope
/*1973*/                OPC_CheckChild2Same, 2,
/*1975*/                OPC_CheckPredicate, 2, // Predicate_unindexedstore
/*1977*/                OPC_CheckPredicate, 3, // Predicate_store
/*1979*/                OPC_CheckComplexPat, /*CP*/0, /*#*/2, // SelectAddr:$dst #5 #6
/*1982*/                OPC_CheckComplexPat, /*CP*/0, /*#*/4, // SelectAddr:$src #7 #8
/*1985*/                OPC_EmitMergeInputChains, 3, 0, 1, 3, 
/*1990*/                OPC_MorphNodeTo, TARGET_VAL(MSP430::XOR16mm), 0|OPFL_Chain|OPFL_MemRefs,
                            1/*#VTs*/, MVT::i16, 4/*#Ops*/, 5, 6, 7, 8, 
                        // Src: (st (xor:i16 (ld:i16 addr:iPTR:$dst)<<P:Predicate_unindexedload>><<P:Predicate_load>>, (ld:i16 addr:iPTR:$src)<<P:Predicate_unindexedload>><<P:Predicate_load>>), addr:iPTR:$dst)<<P:Predicate_unindexedstore>><<P:Predicate_store>> - Complexity = 42
                        // Dst: (XOR16mm:i16 addr:i16:$dst, addr:i16:$src)
/*2001*/              /*Scope*/ 28, /*->2030*/
/*2002*/                OPC_CheckChild2Same, 4,
/*2004*/                OPC_CheckPredicate, 2, // Predicate_unindexedstore
/*2006*/                OPC_CheckPredicate, 3, // Predicate_store
/*2008*/                OPC_CheckComplexPat, /*CP*/0, /*#*/2, // SelectAddr:$src #5 #6
/*2011*/                OPC_CheckComplexPat, /*CP*/0, /*#*/4, // SelectAddr:$dst #7 #8
/*2014*/                OPC_EmitMergeInputChains, 3, 0, 1, 3, 
/*2019*/                OPC_MorphNodeTo, TARGET_VAL(MSP430::XOR16mm), 0|OPFL_Chain|OPFL_MemRefs,
                            1/*#VTs*/, MVT::i16, 4/*#Ops*/, 7, 8, 5, 6, 
                        // Src: (st (xor:i16 (ld:i16 addr:iPTR:$src)<<P:Predicate_unindexedload>><<P:Predicate_load>>, (ld:i16 addr:iPTR:$dst)<<P:Predicate_unindexedload>><<P:Predicate_load>>), addr:iPTR:$dst)<<P:Predicate_unindexedstore>><<P:Predicate_store>> - Complexity = 42
                        // Dst: (XOR16mm:i16 addr:i16:$dst, addr:i16:$src)
/*2030*/              0, /*End of Scope*/
/*2031*/            0, // EndSwitchType
/*2032*/          /*Scope*/ 122, /*->2155*/
/*2033*/            OPC_RecordChild1, // #3 = $src
/*2034*/            OPC_Scope, 64, /*->2100*/ // 3 children in Scope
/*2036*/              OPC_MoveChild, 1,
/*2038*/              OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*2041*/              OPC_MoveParent,
/*2042*/              OPC_SwitchType /*2 cases */, 26,  MVT::i8,// ->2071
/*2045*/                OPC_MoveParent,
/*2046*/                OPC_CheckChild2Same, 2,
/*2048*/                OPC_CheckPredicate, 2, // Predicate_unindexedstore
/*2050*/                OPC_CheckPredicate, 3, // Predicate_store
/*2052*/                OPC_CheckComplexPat, /*CP*/0, /*#*/2, // SelectAddr:$dst #4 #5
/*2055*/                OPC_EmitMergeInputChains, 2, 0, 1, 
/*2059*/                OPC_EmitConvertToTarget, 3,
/*2061*/                OPC_MorphNodeTo, TARGET_VAL(MSP430::XOR8mi), 0|OPFL_Chain|OPFL_MemRefs,
                            1/*#VTs*/, MVT::i16, 3/*#Ops*/, 4, 5, 6, 
                        // Src: (st (xor:i8 (ld:i8 addr:iPTR:$dst)<<P:Predicate_unindexedload>><<P:Predicate_load>>, (imm:i8):$src), addr:iPTR:$dst)<<P:Predicate_unindexedstore>><<P:Predicate_store>> - Complexity = 32
                        // Dst: (XOR8mi:i16 addr:i16:$dst, (imm:i8):$src)
/*2071*/              /*SwitchType*/ 26,  MVT::i16,// ->2099
/*2073*/                OPC_MoveParent,
/*2074*/                OPC_CheckChild2Same, 2,
/*2076*/                OPC_CheckPredicate, 2, // Predicate_unindexedstore
/*2078*/                OPC_CheckPredicate, 3, // Predicate_store
/*2080*/                OPC_CheckComplexPat, /*CP*/0, /*#*/2, // SelectAddr:$dst #4 #5
/*2083*/                OPC_EmitMergeInputChains, 2, 0, 1, 
/*2087*/                OPC_EmitConvertToTarget, 3,
/*2089*/                OPC_MorphNodeTo, TARGET_VAL(MSP430::XOR16mi), 0|OPFL_Chain|OPFL_MemRefs,
                            1/*#VTs*/, MVT::i16, 3/*#Ops*/, 4, 5, 6, 
                        // Src: (st (xor:i16 (ld:i16 addr:iPTR:$dst)<<P:Predicate_unindexedload>><<P:Predicate_load>>, (imm:i16):$src), addr:iPTR:$dst)<<P:Predicate_unindexedstore>><<P:Predicate_store>> - Complexity = 32
                        // Dst: (XOR16mi:i16 addr:i16:$dst, (imm:i16):$src)
/*2099*/              0, // EndSwitchType
/*2100*/            /*Scope*/ 26, /*->2127*/
/*2101*/              OPC_CheckType, MVT::i8,
/*2103*/              OPC_MoveParent,
/*2104*/              OPC_CheckChild2Same, 2,
/*2106*/              OPC_CheckPredicate, 2, // Predicate_unindexedstore
/*2108*/              OPC_CheckPredicate, 3, // Predicate_store
/*2110*/              OPC_CheckComplexPat, /*CP*/0, /*#*/2, // SelectAddr:$dst #4 #5
/*2113*/              OPC_EmitMergeInputChains, 2, 0, 1, 
/*2117*/              OPC_MorphNodeTo, TARGET_VAL(MSP430::XOR8mr), 0|OPFL_Chain|OPFL_MemRefs,
                          1/*#VTs*/, MVT::i16, 3/*#Ops*/, 4, 5, 3, 
                      // Src: (st (xor:i8 (ld:i8 addr:iPTR:$dst)<<P:Predicate_unindexedload>><<P:Predicate_load>>, GR8:i8:$src), addr:iPTR:$dst)<<P:Predicate_unindexedstore>><<P:Predicate_store>> - Complexity = 29
                      // Dst: (XOR8mr:i16 addr:i16:$dst, GR8:i8:$src)
/*2127*/            /*Scope*/ 26, /*->2154*/
/*2128*/              OPC_CheckType, MVT::i16,
/*2130*/              OPC_MoveParent,
/*2131*/              OPC_CheckChild2Same, 2,
/*2133*/              OPC_CheckPredicate, 2, // Predicate_unindexedstore
/*2135*/              OPC_CheckPredicate, 3, // Predicate_store
/*2137*/              OPC_CheckComplexPat, /*CP*/0, /*#*/2, // SelectAddr:$dst #4 #5
/*2140*/              OPC_EmitMergeInputChains, 2, 0, 1, 
/*2144*/              OPC_MorphNodeTo, TARGET_VAL(MSP430::XOR16mr), 0|OPFL_Chain|OPFL_MemRefs,
                          1/*#VTs*/, MVT::i16, 3/*#Ops*/, 4, 5, 3, 
                      // Src: (st (xor:i16 (ld:i16 addr:iPTR:$dst)<<P:Predicate_unindexedload>><<P:Predicate_load>>, GR16:i16:$src), addr:iPTR:$dst)<<P:Predicate_unindexedstore>><<P:Predicate_store>> - Complexity = 29
                      // Dst: (XOR16mr:i16 addr:i16:$dst, GR16:i16:$src)
/*2154*/            0, /*End of Scope*/
/*2155*/          0, /*End of Scope*/
/*2156*/        /*Scope*/ 69, /*->2226*/
/*2157*/          OPC_RecordChild0, // #1 = $src
/*2158*/          OPC_MoveChild, 1,
/*2160*/          OPC_CheckOpcode, TARGET_VAL(ISD::LOAD),
/*2163*/          OPC_RecordMemRef,
/*2164*/          OPC_RecordNode, // #2 = 'ld' chained node
/*2165*/          OPC_CheckFoldableChainNode,
/*2166*/          OPC_RecordChild1, // #3 = $dst
/*2167*/          OPC_CheckPredicate, 0, // Predicate_unindexedload
/*2169*/          OPC_CheckPredicate, 1, // Predicate_load
/*2171*/          OPC_MoveParent,
/*2172*/          OPC_SwitchType /*2 cases */, 24,  MVT::i8,// ->2199
/*2175*/            OPC_MoveParent,
/*2176*/            OPC_CheckChild2Same, 3,
/*2178*/            OPC_CheckPredicate, 2, // Predicate_unindexedstore
/*2180*/            OPC_CheckPredicate, 3, // Predicate_store
/*2182*/            OPC_CheckComplexPat, /*CP*/0, /*#*/3, // SelectAddr:$dst #4 #5
/*2185*/            OPC_EmitMergeInputChains, 2, 0, 2, 
/*2189*/            OPC_MorphNodeTo, TARGET_VAL(MSP430::XOR8mr), 0|OPFL_Chain|OPFL_MemRefs,
                        1/*#VTs*/, MVT::i16, 3/*#Ops*/, 4, 5, 1, 
                    // Src: (st (xor:i8 GR8:i8:$src, (ld:i8 addr:iPTR:$dst)<<P:Predicate_unindexedload>><<P:Predicate_load>>), addr:iPTR:$dst)<<P:Predicate_unindexedstore>><<P:Predicate_store>> - Complexity = 29
                    // Dst: (XOR8mr:i16 addr:i16:$dst, GR8:i8:$src)
/*2199*/          /*SwitchType*/ 24,  MVT::i16,// ->2225
/*2201*/            OPC_MoveParent,
/*2202*/            OPC_CheckChild2Same, 3,
/*2204*/            OPC_CheckPredicate, 2, // Predicate_unindexedstore
/*2206*/            OPC_CheckPredicate, 3, // Predicate_store
/*2208*/            OPC_CheckComplexPat, /*CP*/0, /*#*/3, // SelectAddr:$dst #4 #5
/*2211*/            OPC_EmitMergeInputChains, 2, 0, 2, 
/*2215*/            OPC_MorphNodeTo, TARGET_VAL(MSP430::XOR16mr), 0|OPFL_Chain|OPFL_MemRefs,
                        1/*#VTs*/, MVT::i16, 3/*#Ops*/, 4, 5, 1, 
                    // Src: (st (xor:i16 GR16:i16:$src, (ld:i16 addr:iPTR:$dst)<<P:Predicate_unindexedload>><<P:Predicate_load>>), addr:iPTR:$dst)<<P:Predicate_unindexedstore>><<P:Predicate_store>> - Complexity = 29
                    // Dst: (XOR16mr:i16 addr:i16:$dst, GR16:i16:$src)
/*2225*/          0, // EndSwitchType
/*2226*/        0, /*End of Scope*/
/*2227*/      /*SwitchOpcode*/ 90|128,1/*218*/,  TARGET_VAL(ISD::SUB),// ->2449
/*2231*/        OPC_MoveChild, 0,
/*2233*/        OPC_CheckOpcode, TARGET_VAL(ISD::LOAD),
/*2236*/        OPC_RecordMemRef,
/*2237*/        OPC_RecordNode, // #1 = 'ld' chained node
/*2238*/        OPC_CheckFoldableChainNode,
/*2239*/        OPC_RecordChild1, // #2 = $dst
/*2240*/        OPC_CheckPredicate, 0, // Predicate_unindexedload
/*2242*/        OPC_CheckPredicate, 1, // Predicate_load
/*2244*/        OPC_MoveParent,
/*2245*/        OPC_Scope, 78, /*->2325*/ // 2 children in Scope
/*2247*/          OPC_MoveChild, 1,
/*2249*/          OPC_CheckOpcode, TARGET_VAL(ISD::LOAD),
/*2252*/          OPC_RecordMemRef,
/*2253*/          OPC_RecordNode, // #3 = 'ld' chained node
/*2254*/          OPC_CheckFoldableChainNode,
/*2255*/          OPC_RecordChild1, // #4 = $src
/*2256*/          OPC_CheckPredicate, 0, // Predicate_unindexedload
/*2258*/          OPC_CheckPredicate, 1, // Predicate_load
/*2260*/          OPC_MoveParent,
/*2261*/          OPC_SwitchType /*2 cases */, 29,  MVT::i8,// ->2293
/*2264*/            OPC_MoveParent,
/*2265*/            OPC_CheckChild2Same, 2,
/*2267*/            OPC_CheckPredicate, 2, // Predicate_unindexedstore
/*2269*/            OPC_CheckPredicate, 3, // Predicate_store
/*2271*/            OPC_CheckComplexPat, /*CP*/0, /*#*/2, // SelectAddr:$dst #5 #6
/*2274*/            OPC_CheckComplexPat, /*CP*/0, /*#*/4, // SelectAddr:$src #7 #8
/*2277*/            OPC_EmitMergeInputChains, 3, 0, 1, 3, 
/*2282*/            OPC_MorphNodeTo, TARGET_VAL(MSP430::SUB8mm), 0|OPFL_Chain|OPFL_MemRefs,
                        1/*#VTs*/, MVT::i16, 4/*#Ops*/, 5, 6, 7, 8, 
                    // Src: (st (sub:i8 (ld:i8 addr:iPTR:$dst)<<P:Predicate_unindexedload>><<P:Predicate_load>>, (ld:i8 addr:iPTR:$src)<<P:Predicate_unindexedload>><<P:Predicate_load>>), addr:iPTR:$dst)<<P:Predicate_unindexedstore>><<P:Predicate_store>> - Complexity = 42
                    // Dst: (SUB8mm:i16 addr:i16:$dst, addr:i16:$src)
/*2293*/          /*SwitchType*/ 29,  MVT::i16,// ->2324
/*2295*/            OPC_MoveParent,
/*2296*/            OPC_CheckChild2Same, 2,
/*2298*/            OPC_CheckPredicate, 2, // Predicate_unindexedstore
/*2300*/            OPC_CheckPredicate, 3, // Predicate_store
/*2302*/            OPC_CheckComplexPat, /*CP*/0, /*#*/2, // SelectAddr:$dst #5 #6
/*2305*/            OPC_CheckComplexPat, /*CP*/0, /*#*/4, // SelectAddr:$src #7 #8
/*2308*/            OPC_EmitMergeInputChains, 3, 0, 1, 3, 
/*2313*/            OPC_MorphNodeTo, TARGET_VAL(MSP430::SUB16mm), 0|OPFL_Chain|OPFL_MemRefs,
                        1/*#VTs*/, MVT::i16, 4/*#Ops*/, 5, 6, 7, 8, 
                    // Src: (st (sub:i16 (ld:i16 addr:iPTR:$dst)<<P:Predicate_unindexedload>><<P:Predicate_load>>, (ld:i16 addr:iPTR:$src)<<P:Predicate_unindexedload>><<P:Predicate_load>>), addr:iPTR:$dst)<<P:Predicate_unindexedstore>><<P:Predicate_store>> - Complexity = 42
                    // Dst: (SUB16mm:i16 addr:i16:$dst, addr:i16:$src)
/*2324*/          0, // EndSwitchType
/*2325*/        /*Scope*/ 122, /*->2448*/
/*2326*/          OPC_RecordChild1, // #3 = $src
/*2327*/          OPC_Scope, 64, /*->2393*/ // 3 children in Scope
/*2329*/            OPC_MoveChild, 1,
/*2331*/            OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*2334*/            OPC_MoveParent,
/*2335*/            OPC_SwitchType /*2 cases */, 26,  MVT::i8,// ->2364
/*2338*/              OPC_MoveParent,
/*2339*/              OPC_CheckChild2Same, 2,
/*2341*/              OPC_CheckPredicate, 2, // Predicate_unindexedstore
/*2343*/              OPC_CheckPredicate, 3, // Predicate_store
/*2345*/              OPC_CheckComplexPat, /*CP*/0, /*#*/2, // SelectAddr:$dst #4 #5
/*2348*/              OPC_EmitMergeInputChains, 2, 0, 1, 
/*2352*/              OPC_EmitConvertToTarget, 3,
/*2354*/              OPC_MorphNodeTo, TARGET_VAL(MSP430::SUB8mi), 0|OPFL_Chain|OPFL_MemRefs,
                          1/*#VTs*/, MVT::i16, 3/*#Ops*/, 4, 5, 6, 
                      // Src: (st (sub:i8 (ld:i8 addr:iPTR:$dst)<<P:Predicate_unindexedload>><<P:Predicate_load>>, (imm:i8):$src), addr:iPTR:$dst)<<P:Predicate_unindexedstore>><<P:Predicate_store>> - Complexity = 32
                      // Dst: (SUB8mi:i16 addr:i16:$dst, (imm:i8):$src)
/*2364*/            /*SwitchType*/ 26,  MVT::i16,// ->2392
/*2366*/              OPC_MoveParent,
/*2367*/              OPC_CheckChild2Same, 2,
/*2369*/              OPC_CheckPredicate, 2, // Predicate_unindexedstore
/*2371*/              OPC_CheckPredicate, 3, // Predicate_store
/*2373*/              OPC_CheckComplexPat, /*CP*/0, /*#*/2, // SelectAddr:$dst #4 #5
/*2376*/              OPC_EmitMergeInputChains, 2, 0, 1, 
/*2380*/              OPC_EmitConvertToTarget, 3,
/*2382*/              OPC_MorphNodeTo, TARGET_VAL(MSP430::SUB16mi), 0|OPFL_Chain|OPFL_MemRefs,
                          1/*#VTs*/, MVT::i16, 3/*#Ops*/, 4, 5, 6, 
                      // Src: (st (sub:i16 (ld:i16 addr:iPTR:$dst)<<P:Predicate_unindexedload>><<P:Predicate_load>>, (imm:i16):$src), addr:iPTR:$dst)<<P:Predicate_unindexedstore>><<P:Predicate_store>> - Complexity = 32
                      // Dst: (SUB16mi:i16 addr:i16:$dst, (imm:i16):$src)
/*2392*/            0, // EndSwitchType
/*2393*/          /*Scope*/ 26, /*->2420*/
/*2394*/            OPC_CheckType, MVT::i8,
/*2396*/            OPC_MoveParent,
/*2397*/            OPC_CheckChild2Same, 2,
/*2399*/            OPC_CheckPredicate, 2, // Predicate_unindexedstore
/*2401*/            OPC_CheckPredicate, 3, // Predicate_store
/*2403*/            OPC_CheckComplexPat, /*CP*/0, /*#*/2, // SelectAddr:$dst #4 #5
/*2406*/            OPC_EmitMergeInputChains, 2, 0, 1, 
/*2410*/            OPC_MorphNodeTo, TARGET_VAL(MSP430::SUB8mr), 0|OPFL_Chain|OPFL_MemRefs,
                        1/*#VTs*/, MVT::i16, 3/*#Ops*/, 4, 5, 3, 
                    // Src: (st (sub:i8 (ld:i8 addr:iPTR:$dst)<<P:Predicate_unindexedload>><<P:Predicate_load>>, GR8:i8:$src), addr:iPTR:$dst)<<P:Predicate_unindexedstore>><<P:Predicate_store>> - Complexity = 29
                    // Dst: (SUB8mr:i16 addr:i16:$dst, GR8:i8:$src)
/*2420*/          /*Scope*/ 26, /*->2447*/
/*2421*/            OPC_CheckType, MVT::i16,
/*2423*/            OPC_MoveParent,
/*2424*/            OPC_CheckChild2Same, 2,
/*2426*/            OPC_CheckPredicate, 2, // Predicate_unindexedstore
/*2428*/            OPC_CheckPredicate, 3, // Predicate_store
/*2430*/            OPC_CheckComplexPat, /*CP*/0, /*#*/2, // SelectAddr:$dst #4 #5
/*2433*/            OPC_EmitMergeInputChains, 2, 0, 1, 
/*2437*/            OPC_MorphNodeTo, TARGET_VAL(MSP430::SUB16mr), 0|OPFL_Chain|OPFL_MemRefs,
                        1/*#VTs*/, MVT::i16, 3/*#Ops*/, 4, 5, 3, 
                    // Src: (st (sub:i16 (ld:i16 addr:iPTR:$dst)<<P:Predicate_unindexedload>><<P:Predicate_load>>, GR16:i16:$src), addr:iPTR:$dst)<<P:Predicate_unindexedstore>><<P:Predicate_store>> - Complexity = 29
                    // Dst: (SUB16mr:i16 addr:i16:$dst, GR16:i16:$src)
/*2447*/          0, /*End of Scope*/
/*2448*/        0, /*End of Scope*/
/*2449*/      /*SwitchOpcode*/ 111|128,1/*239*/,  TARGET_VAL(ISD::SUBE),// ->2692
/*2453*/        OPC_RecordNode, // #1 = 'sube' glue output node
/*2454*/        OPC_CaptureGlueInput,
/*2455*/        OPC_MoveChild, 0,
/*2457*/        OPC_CheckOpcode, TARGET_VAL(ISD::LOAD),
/*2460*/        OPC_RecordMemRef,
/*2461*/        OPC_RecordNode, // #2 = 'ld' chained node
/*2462*/        OPC_CheckFoldableChainNode,
/*2463*/        OPC_RecordChild1, // #3 = $dst
/*2464*/        OPC_CheckPredicate, 0, // Predicate_unindexedload
/*2466*/        OPC_CheckPredicate, 1, // Predicate_load
/*2468*/        OPC_MoveParent,
/*2469*/        OPC_Scope, 84, /*->2555*/ // 2 children in Scope
/*2471*/          OPC_MoveChild, 1,
/*2473*/          OPC_CheckOpcode, TARGET_VAL(ISD::LOAD),
/*2476*/          OPC_RecordMemRef,
/*2477*/          OPC_RecordNode, // #4 = 'ld' chained node
/*2478*/          OPC_CheckFoldableChainNode,
/*2479*/          OPC_RecordChild1, // #5 = $src
/*2480*/          OPC_CheckPredicate, 0, // Predicate_unindexedload
/*2482*/          OPC_CheckPredicate, 1, // Predicate_load
/*2484*/          OPC_MoveParent,
/*2485*/          OPC_SwitchType /*2 cases */, 32,  MVT::i8,// ->2520
/*2488*/            OPC_MoveParent,
/*2489*/            OPC_CheckChild2Same, 3,
/*2491*/            OPC_CheckPredicate, 2, // Predicate_unindexedstore
/*2493*/            OPC_CheckPredicate, 3, // Predicate_store
/*2495*/            OPC_CheckComplexPat, /*CP*/0, /*#*/3, // SelectAddr:$dst #6 #7
/*2498*/            OPC_CheckComplexPat, /*CP*/0, /*#*/5, // SelectAddr:$src #8 #9
/*2501*/            OPC_EmitMergeInputChains, 3, 0, 2, 4, 
/*2506*/            OPC_MarkGlueResults, 1, 1, 
/*2509*/            OPC_MorphNodeTo, TARGET_VAL(MSP430::SBC8mm), 0|OPFL_Chain|OPFL_GlueInput|OPFL_GlueOutput|OPFL_MemRefs,
                        1/*#VTs*/, MVT::i16, 4/*#Ops*/, 6, 7, 8, 9, 
                    // Src: (st (sube:i8 (ld:i8 addr:iPTR:$dst)<<P:Predicate_unindexedload>><<P:Predicate_load>>, (ld:i8 addr:iPTR:$src)<<P:Predicate_unindexedload>><<P:Predicate_load>>), addr:iPTR:$dst)<<P:Predicate_unindexedstore>><<P:Predicate_store>> - Complexity = 42
                    // Dst: (SBC8mm:i16 addr:i16:$dst, addr:i16:$src)
/*2520*/          /*SwitchType*/ 32,  MVT::i16,// ->2554
/*2522*/            OPC_MoveParent,
/*2523*/            OPC_CheckChild2Same, 3,
/*2525*/            OPC_CheckPredicate, 2, // Predicate_unindexedstore
/*2527*/            OPC_CheckPredicate, 3, // Predicate_store
/*2529*/            OPC_CheckComplexPat, /*CP*/0, /*#*/3, // SelectAddr:$dst #6 #7
/*2532*/            OPC_CheckComplexPat, /*CP*/0, /*#*/5, // SelectAddr:$src #8 #9
/*2535*/            OPC_EmitMergeInputChains, 3, 0, 2, 4, 
/*2540*/            OPC_MarkGlueResults, 1, 1, 
/*2543*/            OPC_MorphNodeTo, TARGET_VAL(MSP430::SBC16mm), 0|OPFL_Chain|OPFL_GlueInput|OPFL_GlueOutput|OPFL_MemRefs,
                        1/*#VTs*/, MVT::i16, 4/*#Ops*/, 6, 7, 8, 9, 
                    // Src: (st (sube:i16 (ld:i16 addr:iPTR:$dst)<<P:Predicate_unindexedload>><<P:Predicate_load>>, (ld:i16 addr:iPTR:$src)<<P:Predicate_unindexedload>><<P:Predicate_load>>), addr:iPTR:$dst)<<P:Predicate_unindexedstore>><<P:Predicate_store>> - Complexity = 42
                    // Dst: (SBC16mm:i16 addr:i16:$dst, addr:i16:$src)
/*2554*/          0, // EndSwitchType
/*2555*/        /*Scope*/ 6|128,1/*134*/, /*->2691*/
/*2557*/          OPC_RecordChild1, // #4 = $src
/*2558*/          OPC_Scope, 70, /*->2630*/ // 3 children in Scope
/*2560*/            OPC_MoveChild, 1,
/*2562*/            OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*2565*/            OPC_MoveParent,
/*2566*/            OPC_SwitchType /*2 cases */, 29,  MVT::i8,// ->2598
/*2569*/              OPC_MoveParent,
/*2570*/              OPC_CheckChild2Same, 3,
/*2572*/              OPC_CheckPredicate, 2, // Predicate_unindexedstore
/*2574*/              OPC_CheckPredicate, 3, // Predicate_store
/*2576*/              OPC_CheckComplexPat, /*CP*/0, /*#*/3, // SelectAddr:$dst #5 #6
/*2579*/              OPC_EmitMergeInputChains, 2, 0, 2, 
/*2583*/              OPC_EmitConvertToTarget, 4,
/*2585*/              OPC_MarkGlueResults, 1, 1, 
/*2588*/              OPC_MorphNodeTo, TARGET_VAL(MSP430::SBC8mi), 0|OPFL_Chain|OPFL_GlueInput|OPFL_GlueOutput|OPFL_MemRefs,
                          1/*#VTs*/, MVT::i16, 3/*#Ops*/, 5, 6, 7, 
                      // Src: (st (sube:i8 (ld:i8 addr:iPTR:$dst)<<P:Predicate_unindexedload>><<P:Predicate_load>>, (imm:i8):$src), addr:iPTR:$dst)<<P:Predicate_unindexedstore>><<P:Predicate_store>> - Complexity = 32
                      // Dst: (SBC8mi:i16 addr:i16:$dst, (imm:i8):$src)
/*2598*/            /*SwitchType*/ 29,  MVT::i16,// ->2629
/*2600*/              OPC_MoveParent,
/*2601*/              OPC_CheckChild2Same, 3,
/*2603*/              OPC_CheckPredicate, 2, // Predicate_unindexedstore
/*2605*/              OPC_CheckPredicate, 3, // Predicate_store
/*2607*/              OPC_CheckComplexPat, /*CP*/0, /*#*/3, // SelectAddr:$dst #5 #6
/*2610*/              OPC_EmitMergeInputChains, 2, 0, 2, 
/*2614*/              OPC_EmitConvertToTarget, 4,
/*2616*/              OPC_MarkGlueResults, 1, 1, 
/*2619*/              OPC_MorphNodeTo, TARGET_VAL(MSP430::SBC16mi), 0|OPFL_Chain|OPFL_GlueInput|OPFL_GlueOutput|OPFL_MemRefs,
                          1/*#VTs*/, MVT::i16, 3/*#Ops*/, 5, 6, 7, 
                      // Src: (st (sube:i16 (ld:i16 addr:iPTR:$dst)<<P:Predicate_unindexedload>><<P:Predicate_load>>, (imm:i16):$src), addr:iPTR:$dst)<<P:Predicate_unindexedstore>><<P:Predicate_store>> - Complexity = 32
                      // Dst: (SBC16mi:i16 addr:i16:$dst, (imm:i16):$src)
/*2629*/            0, // EndSwitchType
/*2630*/          /*Scope*/ 29, /*->2660*/
/*2631*/            OPC_CheckType, MVT::i8,
/*2633*/            OPC_MoveParent,
/*2634*/            OPC_CheckChild2Same, 3,
/*2636*/            OPC_CheckPredicate, 2, // Predicate_unindexedstore
/*2638*/            OPC_CheckPredicate, 3, // Predicate_store
/*2640*/            OPC_CheckComplexPat, /*CP*/0, /*#*/3, // SelectAddr:$dst #5 #6
/*2643*/            OPC_EmitMergeInputChains, 2, 0, 2, 
/*2647*/            OPC_MarkGlueResults, 1, 1, 
/*2650*/            OPC_MorphNodeTo, TARGET_VAL(MSP430::SBC8mr), 0|OPFL_Chain|OPFL_GlueInput|OPFL_GlueOutput|OPFL_MemRefs,
                        1/*#VTs*/, MVT::i16, 3/*#Ops*/, 5, 6, 4, 
                    // Src: (st (sube:i8 (ld:i8 addr:iPTR:$dst)<<P:Predicate_unindexedload>><<P:Predicate_load>>, GR8:i8:$src), addr:iPTR:$dst)<<P:Predicate_unindexedstore>><<P:Predicate_store>> - Complexity = 29
                    // Dst: (SBC8mr:i16 addr:i16:$dst, GR8:i8:$src)
/*2660*/          /*Scope*/ 29, /*->2690*/
/*2661*/            OPC_CheckType, MVT::i16,
/*2663*/            OPC_MoveParent,
/*2664*/            OPC_CheckChild2Same, 3,
/*2666*/            OPC_CheckPredicate, 2, // Predicate_unindexedstore
/*2668*/            OPC_CheckPredicate, 3, // Predicate_store
/*2670*/            OPC_CheckComplexPat, /*CP*/0, /*#*/3, // SelectAddr:$dst #5 #6
/*2673*/            OPC_EmitMergeInputChains, 2, 0, 2, 
/*2677*/            OPC_MarkGlueResults, 1, 1, 
/*2680*/            OPC_MorphNodeTo, TARGET_VAL(MSP430::SBC16mr), 0|OPFL_Chain|OPFL_GlueInput|OPFL_GlueOutput|OPFL_MemRefs,
                        1/*#VTs*/, MVT::i16, 3/*#Ops*/, 5, 6, 4, 
                    // Src: (st (sube:i16 (ld:i16 addr:iPTR:$dst)<<P:Predicate_unindexedload>><<P:Predicate_load>>, GR16:i16:$src), addr:iPTR:$dst)<<P:Predicate_unindexedstore>><<P:Predicate_store>> - Complexity = 29
                    // Dst: (SBC16mr:i16 addr:i16:$dst, GR16:i16:$src)
/*2690*/          0, /*End of Scope*/
/*2691*/        0, /*End of Scope*/
/*2692*/      /*SwitchOpcode*/ 59|128,2/*315*/,  TARGET_VAL(ISD::ADDC),// ->3011
/*2696*/        OPC_RecordNode, // #1 = 'addc' glue output node
/*2697*/        OPC_Scope, 106|128,1/*234*/, /*->2934*/ // 2 children in Scope
/*2700*/          OPC_MoveChild, 0,
/*2702*/          OPC_CheckOpcode, TARGET_VAL(ISD::LOAD),
/*2705*/          OPC_RecordMemRef,
/*2706*/          OPC_RecordNode, // #2 = 'ld' chained node
/*2707*/          OPC_CheckFoldableChainNode,
/*2708*/          OPC_RecordChild1, // #3 = $dst
/*2709*/          OPC_CheckPredicate, 0, // Predicate_unindexedload
/*2711*/          OPC_CheckPredicate, 1, // Predicate_load
/*2713*/          OPC_MoveParent,
/*2714*/          OPC_Scope, 26|128,1/*154*/, /*->2871*/ // 2 children in Scope
/*2717*/            OPC_MoveChild, 1,
/*2719*/            OPC_CheckOpcode, TARGET_VAL(ISD::LOAD),
/*2722*/            OPC_RecordMemRef,
/*2723*/            OPC_RecordNode, // #4 = 'ld' chained node
/*2724*/            OPC_CheckFoldableChainNode,
/*2725*/            OPC_RecordChild1, // #5 = $src
/*2726*/            OPC_CheckPredicate, 0, // Predicate_unindexedload
/*2728*/            OPC_CheckPredicate, 1, // Predicate_load
/*2730*/            OPC_MoveParent,
/*2731*/            OPC_SwitchType /*2 cases */, 67,  MVT::i16,// ->2801
/*2734*/              OPC_MoveParent,
/*2735*/              OPC_Scope, 31, /*->2768*/ // 2 children in Scope
/*2737*/                OPC_CheckChild2Same, 3,
/*2739*/                OPC_CheckPredicate, 2, // Predicate_unindexedstore
/*2741*/                OPC_CheckPredicate, 3, // Predicate_store
/*2743*/                OPC_CheckComplexPat, /*CP*/0, /*#*/3, // SelectAddr:$dst #6 #7
/*2746*/                OPC_CheckComplexPat, /*CP*/0, /*#*/5, // SelectAddr:$src #8 #9
/*2749*/                OPC_EmitMergeInputChains, 3, 0, 2, 4, 
/*2754*/                OPC_MarkGlueResults, 1, 1, 
/*2757*/                OPC_MorphNodeTo, TARGET_VAL(MSP430::ADD16mm), 0|OPFL_Chain|OPFL_GlueOutput|OPFL_MemRefs,
                            1/*#VTs*/, MVT::i16, 4/*#Ops*/, 6, 7, 8, 9, 
                        // Src: (st (addc:i16 (ld:i16 addr:iPTR:$dst)<<P:Predicate_unindexedload>><<P:Predicate_load>>, (ld:i16 addr:iPTR:$src)<<P:Predicate_unindexedload>><<P:Predicate_load>>), addr:iPTR:$dst)<<P:Predicate_unindexedstore>><<P:Predicate_store>> - Complexity = 42
                        // Dst: (ADD16mm:i16 addr:i16:$dst, addr:i16:$src)
/*2768*/              /*Scope*/ 31, /*->2800*/
/*2769*/                OPC_CheckChild2Same, 5,
/*2771*/                OPC_CheckPredicate, 2, // Predicate_unindexedstore
/*2773*/                OPC_CheckPredicate, 3, // Predicate_store
/*2775*/                OPC_CheckComplexPat, /*CP*/0, /*#*/3, // SelectAddr:$src #6 #7
/*2778*/                OPC_CheckComplexPat, /*CP*/0, /*#*/5, // SelectAddr:$dst #8 #9
/*2781*/                OPC_EmitMergeInputChains, 3, 0, 2, 4, 
/*2786*/                OPC_MarkGlueResults, 1, 1, 
/*2789*/                OPC_MorphNodeTo, TARGET_VAL(MSP430::ADD16mm), 0|OPFL_Chain|OPFL_GlueOutput|OPFL_MemRefs,
                            1/*#VTs*/, MVT::i16, 4/*#Ops*/, 8, 9, 6, 7, 
                        // Src: (st (addc:i16 (ld:i16 addr:iPTR:$src)<<P:Predicate_unindexedload>><<P:Predicate_load>>, (ld:i16 addr:iPTR:$dst)<<P:Predicate_unindexedload>><<P:Predicate_load>>), addr:iPTR:$dst)<<P:Predicate_unindexedstore>><<P:Predicate_store>> - Complexity = 42
                        // Dst: (ADD16mm:i16 addr:i16:$dst, addr:i16:$src)
/*2800*/              0, /*End of Scope*/
/*2801*/            /*SwitchType*/ 67,  MVT::i8,// ->2870
/*2803*/              OPC_MoveParent,
/*2804*/              OPC_Scope, 31, /*->2837*/ // 2 children in Scope
/*2806*/                OPC_CheckChild2Same, 3,
/*2808*/                OPC_CheckPredicate, 2, // Predicate_unindexedstore
/*2810*/                OPC_CheckPredicate, 3, // Predicate_store
/*2812*/                OPC_CheckComplexPat, /*CP*/0, /*#*/3, // SelectAddr:$dst #6 #7
/*2815*/                OPC_CheckComplexPat, /*CP*/0, /*#*/5, // SelectAddr:$src #8 #9
/*2818*/                OPC_EmitMergeInputChains, 3, 0, 2, 4, 
/*2823*/                OPC_MarkGlueResults, 1, 1, 
/*2826*/                OPC_MorphNodeTo, TARGET_VAL(MSP430::ADD8mm), 0|OPFL_Chain|OPFL_GlueOutput|OPFL_MemRefs,
                            1/*#VTs*/, MVT::i16, 4/*#Ops*/, 6, 7, 8, 9, 
                        // Src: (st (addc:i8 (ld:i8 addr:iPTR:$dst)<<P:Predicate_unindexedload>><<P:Predicate_load>>, (ld:i8 addr:iPTR:$src)<<P:Predicate_unindexedload>><<P:Predicate_load>>), addr:iPTR:$dst)<<P:Predicate_unindexedstore>><<P:Predicate_store>> - Complexity = 42
                        // Dst: (ADD8mm:i16 addr:i16:$dst, addr:i16:$src)
/*2837*/              /*Scope*/ 31, /*->2869*/
/*2838*/                OPC_CheckChild2Same, 5,
/*2840*/                OPC_CheckPredicate, 2, // Predicate_unindexedstore
/*2842*/                OPC_CheckPredicate, 3, // Predicate_store
/*2844*/                OPC_CheckComplexPat, /*CP*/0, /*#*/3, // SelectAddr:$src #6 #7
/*2847*/                OPC_CheckComplexPat, /*CP*/0, /*#*/5, // SelectAddr:$dst #8 #9
/*2850*/                OPC_EmitMergeInputChains, 3, 0, 2, 4, 
/*2855*/                OPC_MarkGlueResults, 1, 1, 
/*2858*/                OPC_MorphNodeTo, TARGET_VAL(MSP430::ADD8mm), 0|OPFL_Chain|OPFL_GlueOutput|OPFL_MemRefs,
                            1/*#VTs*/, MVT::i16, 4/*#Ops*/, 8, 9, 6, 7, 
                        // Src: (st (addc:i8 (ld:i8 addr:iPTR:$src)<<P:Predicate_unindexedload>><<P:Predicate_load>>, (ld:i8 addr:iPTR:$dst)<<P:Predicate_unindexedload>><<P:Predicate_load>>), addr:iPTR:$dst)<<P:Predicate_unindexedstore>><<P:Predicate_store>> - Complexity = 42
                        // Dst: (ADD8mm:i16 addr:i16:$dst, addr:i16:$src)
/*2869*/              0, /*End of Scope*/
/*2870*/            0, // EndSwitchType
/*2871*/          /*Scope*/ 61, /*->2933*/
/*2872*/            OPC_RecordChild1, // #4 = $src
/*2873*/            OPC_SwitchType /*2 cases */, 27,  MVT::i16,// ->2903
/*2876*/              OPC_MoveParent,
/*2877*/              OPC_CheckChild2Same, 3,
/*2879*/              OPC_CheckPredicate, 2, // Predicate_unindexedstore
/*2881*/              OPC_CheckPredicate, 3, // Predicate_store
/*2883*/              OPC_CheckComplexPat, /*CP*/0, /*#*/3, // SelectAddr:$dst #5 #6
/*2886*/              OPC_EmitMergeInputChains, 2, 0, 2, 
/*2890*/              OPC_MarkGlueResults, 1, 1, 
/*2893*/              OPC_MorphNodeTo, TARGET_VAL(MSP430::ADD16mr), 0|OPFL_Chain|OPFL_GlueOutput|OPFL_MemRefs,
                          1/*#VTs*/, MVT::i16, 3/*#Ops*/, 5, 6, 4, 
                      // Src: (st (addc:i16 (ld:i16 addr:iPTR:$dst)<<P:Predicate_unindexedload>><<P:Predicate_load>>, GR16:i16:$src), addr:iPTR:$dst)<<P:Predicate_unindexedstore>><<P:Predicate_store>> - Complexity = 29
                      // Dst: (ADD16mr:i16 addr:i16:$dst, GR16:i16:$src)
/*2903*/            /*SwitchType*/ 27,  MVT::i8,// ->2932
/*2905*/              OPC_MoveParent,
/*2906*/              OPC_CheckChild2Same, 3,
/*2908*/              OPC_CheckPredicate, 2, // Predicate_unindexedstore
/*2910*/              OPC_CheckPredicate, 3, // Predicate_store
/*2912*/              OPC_CheckComplexPat, /*CP*/0, /*#*/3, // SelectAddr:$dst #5 #6
/*2915*/              OPC_EmitMergeInputChains, 2, 0, 2, 
/*2919*/              OPC_MarkGlueResults, 1, 1, 
/*2922*/              OPC_MorphNodeTo, TARGET_VAL(MSP430::ADD8mr), 0|OPFL_Chain|OPFL_GlueOutput|OPFL_MemRefs,
                          1/*#VTs*/, MVT::i16, 3/*#Ops*/, 5, 6, 4, 
                      // Src: (st (addc:i8 (ld:i8 addr:iPTR:$dst)<<P:Predicate_unindexedload>><<P:Predicate_load>>, GR8:i8:$src), addr:iPTR:$dst)<<P:Predicate_unindexedstore>><<P:Predicate_store>> - Complexity = 29
                      // Dst: (ADD8mr:i16 addr:i16:$dst, GR8:i8:$src)
/*2932*/            0, // EndSwitchType
/*2933*/          0, /*End of Scope*/
/*2934*/        /*Scope*/ 75, /*->3010*/
/*2935*/          OPC_RecordChild0, // #2 = $src
/*2936*/          OPC_MoveChild, 1,
/*2938*/          OPC_CheckOpcode, TARGET_VAL(ISD::LOAD),
/*2941*/          OPC_RecordMemRef,
/*2942*/          OPC_RecordNode, // #3 = 'ld' chained node
/*2943*/          OPC_CheckFoldableChainNode,
/*2944*/          OPC_RecordChild1, // #4 = $dst
/*2945*/          OPC_CheckPredicate, 0, // Predicate_unindexedload
/*2947*/          OPC_CheckPredicate, 1, // Predicate_load
/*2949*/          OPC_MoveParent,
/*2950*/          OPC_SwitchType /*2 cases */, 27,  MVT::i16,// ->2980
/*2953*/            OPC_MoveParent,
/*2954*/            OPC_CheckChild2Same, 4,
/*2956*/            OPC_CheckPredicate, 2, // Predicate_unindexedstore
/*2958*/            OPC_CheckPredicate, 3, // Predicate_store
/*2960*/            OPC_CheckComplexPat, /*CP*/0, /*#*/4, // SelectAddr:$dst #5 #6
/*2963*/            OPC_EmitMergeInputChains, 2, 0, 3, 
/*2967*/            OPC_MarkGlueResults, 1, 1, 
/*2970*/            OPC_MorphNodeTo, TARGET_VAL(MSP430::ADD16mr), 0|OPFL_Chain|OPFL_GlueOutput|OPFL_MemRefs,
                        1/*#VTs*/, MVT::i16, 3/*#Ops*/, 5, 6, 2, 
                    // Src: (st (addc:i16 GR16:i16:$src, (ld:i16 addr:iPTR:$dst)<<P:Predicate_unindexedload>><<P:Predicate_load>>), addr:iPTR:$dst)<<P:Predicate_unindexedstore>><<P:Predicate_store>> - Complexity = 29
                    // Dst: (ADD16mr:i16 addr:i16:$dst, GR16:i16:$src)
/*2980*/          /*SwitchType*/ 27,  MVT::i8,// ->3009
/*2982*/            OPC_MoveParent,
/*2983*/            OPC_CheckChild2Same, 4,
/*2985*/            OPC_CheckPredicate, 2, // Predicate_unindexedstore
/*2987*/            OPC_CheckPredicate, 3, // Predicate_store
/*2989*/            OPC_CheckComplexPat, /*CP*/0, /*#*/4, // SelectAddr:$dst #5 #6
/*2992*/            OPC_EmitMergeInputChains, 2, 0, 3, 
/*2996*/            OPC_MarkGlueResults, 1, 1, 
/*2999*/            OPC_MorphNodeTo, TARGET_VAL(MSP430::ADD8mr), 0|OPFL_Chain|OPFL_GlueOutput|OPFL_MemRefs,
                        1/*#VTs*/, MVT::i16, 3/*#Ops*/, 5, 6, 2, 
                    // Src: (st (addc:i8 GR8:i8:$src, (ld:i8 addr:iPTR:$dst)<<P:Predicate_unindexedload>><<P:Predicate_load>>), addr:iPTR:$dst)<<P:Predicate_unindexedstore>><<P:Predicate_store>> - Complexity = 29
                    // Dst: (ADD8mr:i16 addr:i16:$dst, GR8:i8:$src)
/*3009*/          0, // EndSwitchType
/*3010*/        0, /*End of Scope*/
/*3011*/      /*SwitchOpcode*/ 36|128,1/*164*/,  TARGET_VAL(ISD::SUBC),// ->3179
/*3015*/        OPC_RecordNode, // #1 = 'subc' glue output node
/*3016*/        OPC_MoveChild, 0,
/*3018*/        OPC_CheckOpcode, TARGET_VAL(ISD::LOAD),
/*3021*/        OPC_RecordMemRef,
/*3022*/        OPC_RecordNode, // #2 = 'ld' chained node
/*3023*/        OPC_CheckFoldableChainNode,
/*3024*/        OPC_RecordChild1, // #3 = $dst
/*3025*/        OPC_CheckPredicate, 0, // Predicate_unindexedload
/*3027*/        OPC_CheckPredicate, 1, // Predicate_load
/*3029*/        OPC_MoveParent,
/*3030*/        OPC_Scope, 84, /*->3116*/ // 2 children in Scope
/*3032*/          OPC_MoveChild, 1,
/*3034*/          OPC_CheckOpcode, TARGET_VAL(ISD::LOAD),
/*3037*/          OPC_RecordMemRef,
/*3038*/          OPC_RecordNode, // #4 = 'ld' chained node
/*3039*/          OPC_CheckFoldableChainNode,
/*3040*/          OPC_RecordChild1, // #5 = $src
/*3041*/          OPC_CheckPredicate, 0, // Predicate_unindexedload
/*3043*/          OPC_CheckPredicate, 1, // Predicate_load
/*3045*/          OPC_MoveParent,
/*3046*/          OPC_SwitchType /*2 cases */, 32,  MVT::i16,// ->3081
/*3049*/            OPC_MoveParent,
/*3050*/            OPC_CheckChild2Same, 3,
/*3052*/            OPC_CheckPredicate, 2, // Predicate_unindexedstore
/*3054*/            OPC_CheckPredicate, 3, // Predicate_store
/*3056*/            OPC_CheckComplexPat, /*CP*/0, /*#*/3, // SelectAddr:$dst #6 #7
/*3059*/            OPC_CheckComplexPat, /*CP*/0, /*#*/5, // SelectAddr:$src #8 #9
/*3062*/            OPC_EmitMergeInputChains, 3, 0, 2, 4, 
/*3067*/            OPC_MarkGlueResults, 1, 1, 
/*3070*/            OPC_MorphNodeTo, TARGET_VAL(MSP430::SUB16mm), 0|OPFL_Chain|OPFL_GlueOutput|OPFL_MemRefs,
                        1/*#VTs*/, MVT::i16, 4/*#Ops*/, 6, 7, 8, 9, 
                    // Src: (st (subc:i16 (ld:i16 addr:iPTR:$dst)<<P:Predicate_unindexedload>><<P:Predicate_load>>, (ld:i16 addr:iPTR:$src)<<P:Predicate_unindexedload>><<P:Predicate_load>>), addr:iPTR:$dst)<<P:Predicate_unindexedstore>><<P:Predicate_store>> - Complexity = 42
                    // Dst: (SUB16mm:i16 addr:i16:$dst, addr:i16:$src)
/*3081*/          /*SwitchType*/ 32,  MVT::i8,// ->3115
/*3083*/            OPC_MoveParent,
/*3084*/            OPC_CheckChild2Same, 3,
/*3086*/            OPC_CheckPredicate, 2, // Predicate_unindexedstore
/*3088*/            OPC_CheckPredicate, 3, // Predicate_store
/*3090*/            OPC_CheckComplexPat, /*CP*/0, /*#*/3, // SelectAddr:$dst #6 #7
/*3093*/            OPC_CheckComplexPat, /*CP*/0, /*#*/5, // SelectAddr:$src #8 #9
/*3096*/            OPC_EmitMergeInputChains, 3, 0, 2, 4, 
/*3101*/            OPC_MarkGlueResults, 1, 1, 
/*3104*/            OPC_MorphNodeTo, TARGET_VAL(MSP430::SUB8mm), 0|OPFL_Chain|OPFL_GlueOutput|OPFL_MemRefs,
                        1/*#VTs*/, MVT::i16, 4/*#Ops*/, 6, 7, 8, 9, 
                    // Src: (st (subc:i8 (ld:i8 addr:iPTR:$dst)<<P:Predicate_unindexedload>><<P:Predicate_load>>, (ld:i8 addr:iPTR:$src)<<P:Predicate_unindexedload>><<P:Predicate_load>>), addr:iPTR:$dst)<<P:Predicate_unindexedstore>><<P:Predicate_store>> - Complexity = 42
                    // Dst: (SUB8mm:i16 addr:i16:$dst, addr:i16:$src)
/*3115*/          0, // EndSwitchType
/*3116*/        /*Scope*/ 61, /*->3178*/
/*3117*/          OPC_RecordChild1, // #4 = $src
/*3118*/          OPC_SwitchType /*2 cases */, 27,  MVT::i16,// ->3148
/*3121*/            OPC_MoveParent,
/*3122*/            OPC_CheckChild2Same, 3,
/*3124*/            OPC_CheckPredicate, 2, // Predicate_unindexedstore
/*3126*/            OPC_CheckPredicate, 3, // Predicate_store
/*3128*/            OPC_CheckComplexPat, /*CP*/0, /*#*/3, // SelectAddr:$dst #5 #6
/*3131*/            OPC_EmitMergeInputChains, 2, 0, 2, 
/*3135*/            OPC_MarkGlueResults, 1, 1, 
/*3138*/            OPC_MorphNodeTo, TARGET_VAL(MSP430::SUB16mr), 0|OPFL_Chain|OPFL_GlueOutput|OPFL_MemRefs,
                        1/*#VTs*/, MVT::i16, 3/*#Ops*/, 5, 6, 4, 
                    // Src: (st (subc:i16 (ld:i16 addr:iPTR:$dst)<<P:Predicate_unindexedload>><<P:Predicate_load>>, GR16:i16:$src), addr:iPTR:$dst)<<P:Predicate_unindexedstore>><<P:Predicate_store>> - Complexity = 29
                    // Dst: (SUB16mr:i16 addr:i16:$dst, GR16:i16:$src)
/*3148*/          /*SwitchType*/ 27,  MVT::i8,// ->3177
/*3150*/            OPC_MoveParent,
/*3151*/            OPC_CheckChild2Same, 3,
/*3153*/            OPC_CheckPredicate, 2, // Predicate_unindexedstore
/*3155*/            OPC_CheckPredicate, 3, // Predicate_store
/*3157*/            OPC_CheckComplexPat, /*CP*/0, /*#*/3, // SelectAddr:$dst #5 #6
/*3160*/            OPC_EmitMergeInputChains, 2, 0, 2, 
/*3164*/            OPC_MarkGlueResults, 1, 1, 
/*3167*/            OPC_MorphNodeTo, TARGET_VAL(MSP430::SUB8mr), 0|OPFL_Chain|OPFL_GlueOutput|OPFL_MemRefs,
                        1/*#VTs*/, MVT::i16, 3/*#Ops*/, 5, 6, 4, 
                    // Src: (st (subc:i8 (ld:i8 addr:iPTR:$dst)<<P:Predicate_unindexedload>><<P:Predicate_load>>, GR8:i8:$src), addr:iPTR:$dst)<<P:Predicate_unindexedstore>><<P:Predicate_store>> - Complexity = 29
                    // Dst: (SUB8mr:i16 addr:i16:$dst, GR8:i8:$src)
/*3177*/          0, // EndSwitchType
/*3178*/        0, /*End of Scope*/
/*3179*/      /*SwitchOpcode*/ 66,  TARGET_VAL(ISD::LOAD),// ->3248
/*3182*/        OPC_RecordMemRef,
/*3183*/        OPC_RecordNode, // #1 = 'ld' chained node
/*3184*/        OPC_CheckFoldableChainNode,
/*3185*/        OPC_RecordChild1, // #2 = $src
/*3186*/        OPC_CheckPredicate, 0, // Predicate_unindexedload
/*3188*/        OPC_CheckPredicate, 1, // Predicate_load
/*3190*/        OPC_SwitchType /*2 cases */, 26,  MVT::i8,// ->3219
/*3193*/          OPC_MoveParent,
/*3194*/          OPC_RecordChild2, // #3 = $dst
/*3195*/          OPC_CheckPredicate, 2, // Predicate_unindexedstore
/*3197*/          OPC_CheckPredicate, 3, // Predicate_store
/*3199*/          OPC_CheckComplexPat, /*CP*/0, /*#*/2, // SelectAddr:$src #4 #5
/*3202*/          OPC_CheckComplexPat, /*CP*/0, /*#*/3, // SelectAddr:$dst #6 #7
/*3205*/          OPC_EmitMergeInputChains, 2, 0, 1, 
/*3209*/          OPC_MorphNodeTo, TARGET_VAL(MSP430::MOV8mm), 0|OPFL_Chain|OPFL_MemRefs,
                      0/*#VTs*/, 4/*#Ops*/, 6, 7, 4, 5, 
                  // Src: (st (ld:i8 addr:iPTR:$src)<<P:Predicate_unindexedload>><<P:Predicate_load>>, addr:iPTR:$dst)<<P:Predicate_unindexedstore>><<P:Predicate_store>> - Complexity = 26
                  // Dst: (MOV8mm addr:i16:$dst, addr:i16:$src)
/*3219*/        /*SwitchType*/ 26,  MVT::i16,// ->3247
/*3221*/          OPC_MoveParent,
/*3222*/          OPC_RecordChild2, // #3 = $dst
/*3223*/          OPC_CheckPredicate, 2, // Predicate_unindexedstore
/*3225*/          OPC_CheckPredicate, 3, // Predicate_store
/*3227*/          OPC_CheckComplexPat, /*CP*/0, /*#*/2, // SelectAddr:$src #4 #5
/*3230*/          OPC_CheckComplexPat, /*CP*/0, /*#*/3, // SelectAddr:$dst #6 #7
/*3233*/          OPC_EmitMergeInputChains, 2, 0, 1, 
/*3237*/          OPC_MorphNodeTo, TARGET_VAL(MSP430::MOV16mm), 0|OPFL_Chain|OPFL_MemRefs,
                      0/*#VTs*/, 4/*#Ops*/, 6, 7, 4, 5, 
                  // Src: (st (ld:i16 addr:iPTR:$src)<<P:Predicate_unindexedload>><<P:Predicate_load>>, addr:iPTR:$dst)<<P:Predicate_unindexedstore>><<P:Predicate_store>> - Complexity = 26
                  // Dst: (MOV16mm addr:i16:$dst, addr:i16:$src)
/*3247*/        0, // EndSwitchType
/*3248*/      /*SwitchOpcode*/ 80,  TARGET_VAL(MSP430ISD::Wrapper),// ->3331
/*3251*/        OPC_RecordChild0, // #1 = $src
/*3252*/        OPC_MoveChild, 0,
/*3254*/        OPC_SwitchOpcode /*3 cases */, 22,  TARGET_VAL(ISD::TargetGlobalAddress),// ->3280
/*3258*/          OPC_MoveParent,
/*3259*/          OPC_CheckType, MVT::i16,
/*3261*/          OPC_MoveParent,
/*3262*/          OPC_RecordChild2, // #2 = $dst
/*3263*/          OPC_CheckPredicate, 2, // Predicate_unindexedstore
/*3265*/          OPC_CheckPredicate, 3, // Predicate_store
/*3267*/          OPC_CheckComplexPat, /*CP*/0, /*#*/2, // SelectAddr:$dst #3 #4
/*3270*/          OPC_EmitMergeInputChains1_0,
/*3271*/          OPC_MorphNodeTo, TARGET_VAL(MSP430::MOV16mi), 0|OPFL_Chain|OPFL_MemRefs,
                      0/*#VTs*/, 3/*#Ops*/, 3, 4, 1, 
                  // Src: (st (MSP430Wrapper:i16 (tglobaladdr:i16):$src), addr:iPTR:$dst)<<P:Predicate_unindexedstore>><<P:Predicate_store>> - Complexity = 19
                  // Dst: (MOV16mi addr:i16:$dst, (tglobaladdr:i16):$src)
/*3280*/        /*SwitchOpcode*/ 22,  TARGET_VAL(ISD::TargetExternalSymbol),// ->3305
/*3283*/          OPC_MoveParent,
/*3284*/          OPC_CheckType, MVT::i16,
/*3286*/          OPC_MoveParent,
/*3287*/          OPC_RecordChild2, // #2 = $dst
/*3288*/          OPC_CheckPredicate, 2, // Predicate_unindexedstore
/*3290*/          OPC_CheckPredicate, 3, // Predicate_store
/*3292*/          OPC_CheckComplexPat, /*CP*/0, /*#*/2, // SelectAddr:$dst #3 #4
/*3295*/          OPC_EmitMergeInputChains1_0,
/*3296*/          OPC_MorphNodeTo, TARGET_VAL(MSP430::MOV16mi), 0|OPFL_Chain|OPFL_MemRefs,
                      0/*#VTs*/, 3/*#Ops*/, 3, 4, 1, 
                  // Src: (st (MSP430Wrapper:i16 (texternalsym:i16):$src), addr:iPTR:$dst)<<P:Predicate_unindexedstore>><<P:Predicate_store>> - Complexity = 19
                  // Dst: (MOV16mi addr:i16:$dst, (texternalsym:i16):$src)
/*3305*/        /*SwitchOpcode*/ 22,  TARGET_VAL(ISD::TargetBlockAddress),// ->3330
/*3308*/          OPC_MoveParent,
/*3309*/          OPC_CheckType, MVT::i16,
/*3311*/          OPC_MoveParent,
/*3312*/          OPC_RecordChild2, // #2 = $dst
/*3313*/          OPC_CheckPredicate, 2, // Predicate_unindexedstore
/*3315*/          OPC_CheckPredicate, 3, // Predicate_store
/*3317*/          OPC_CheckComplexPat, /*CP*/0, /*#*/2, // SelectAddr:$dst #3 #4
/*3320*/          OPC_EmitMergeInputChains1_0,
/*3321*/          OPC_MorphNodeTo, TARGET_VAL(MSP430::MOV16mi), 0|OPFL_Chain|OPFL_MemRefs,
                      0/*#VTs*/, 3/*#Ops*/, 3, 4, 1, 
                  // Src: (st (MSP430Wrapper:i16 (tblockaddress:i16):$src), addr:iPTR:$dst)<<P:Predicate_unindexedstore>><<P:Predicate_store>> - Complexity = 19
                  // Dst: (MOV16mi addr:i16:$dst, (tblockaddress:i16):$src)
/*3330*/        0, // EndSwitchOpcode
/*3331*/      0, // EndSwitchOpcode
/*3332*/    /*Scope*/ 99, /*->3432*/
/*3333*/      OPC_RecordChild1, // #1 = $src
/*3334*/      OPC_Scope, 53, /*->3389*/ // 3 children in Scope
/*3336*/        OPC_MoveChild, 1,
/*3338*/        OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*3341*/        OPC_SwitchType /*2 cases */, 21,  MVT::i8,// ->3365
/*3344*/          OPC_MoveParent,
/*3345*/          OPC_RecordChild2, // #2 = $dst
/*3346*/          OPC_CheckPredicate, 2, // Predicate_unindexedstore
/*3348*/          OPC_CheckPredicate, 3, // Predicate_store
/*3350*/          OPC_CheckComplexPat, /*CP*/0, /*#*/2, // SelectAddr:$dst #3 #4
/*3353*/          OPC_EmitMergeInputChains1_0,
/*3354*/          OPC_EmitConvertToTarget, 1,
/*3356*/          OPC_MorphNodeTo, TARGET_VAL(MSP430::MOV8mi), 0|OPFL_Chain|OPFL_MemRefs,
                      0/*#VTs*/, 3/*#Ops*/, 3, 4, 5, 
                  // Src: (st (imm:i8):$src, addr:iPTR:$dst)<<P:Predicate_unindexedstore>><<P:Predicate_store>> - Complexity = 16
                  // Dst: (MOV8mi addr:i16:$dst, (imm:i8):$src)
/*3365*/        /*SwitchType*/ 21,  MVT::i16,// ->3388
/*3367*/          OPC_MoveParent,
/*3368*/          OPC_RecordChild2, // #2 = $dst
/*3369*/          OPC_CheckPredicate, 2, // Predicate_unindexedstore
/*3371*/          OPC_CheckPredicate, 3, // Predicate_store
/*3373*/          OPC_CheckComplexPat, /*CP*/0, /*#*/2, // SelectAddr:$dst #3 #4
/*3376*/          OPC_EmitMergeInputChains1_0,
/*3377*/          OPC_EmitConvertToTarget, 1,
/*3379*/          OPC_MorphNodeTo, TARGET_VAL(MSP430::MOV16mi), 0|OPFL_Chain|OPFL_MemRefs,
                      0/*#VTs*/, 3/*#Ops*/, 3, 4, 5, 
                  // Src: (st (imm:i16):$src, addr:iPTR:$dst)<<P:Predicate_unindexedstore>><<P:Predicate_store>> - Complexity = 16
                  // Dst: (MOV16mi addr:i16:$dst, (imm:i16):$src)
/*3388*/        0, // EndSwitchType
/*3389*/      /*Scope*/ 20, /*->3410*/
/*3390*/        OPC_CheckChild1Type, MVT::i8,
/*3392*/        OPC_RecordChild2, // #2 = $dst
/*3393*/        OPC_CheckPredicate, 2, // Predicate_unindexedstore
/*3395*/        OPC_CheckPredicate, 3, // Predicate_store
/*3397*/        OPC_CheckComplexPat, /*CP*/0, /*#*/2, // SelectAddr:$dst #3 #4
/*3400*/        OPC_EmitMergeInputChains1_0,
/*3401*/        OPC_MorphNodeTo, TARGET_VAL(MSP430::MOV8mr), 0|OPFL_Chain|OPFL_MemRefs,
                    0/*#VTs*/, 3/*#Ops*/, 3, 4, 1, 
                // Src: (st GR8:i8:$src, addr:iPTR:$dst)<<P:Predicate_unindexedstore>><<P:Predicate_store>> - Complexity = 13
                // Dst: (MOV8mr addr:i16:$dst, GR8:i8:$src)
/*3410*/      /*Scope*/ 20, /*->3431*/
/*3411*/        OPC_CheckChild1Type, MVT::i16,
/*3413*/        OPC_RecordChild2, // #2 = $dst
/*3414*/        OPC_CheckPredicate, 2, // Predicate_unindexedstore
/*3416*/        OPC_CheckPredicate, 3, // Predicate_store
/*3418*/        OPC_CheckComplexPat, /*CP*/0, /*#*/2, // SelectAddr:$dst #3 #4
/*3421*/        OPC_EmitMergeInputChains1_0,
/*3422*/        OPC_MorphNodeTo, TARGET_VAL(MSP430::MOV16mr), 0|OPFL_Chain|OPFL_MemRefs,
                    0/*#VTs*/, 3/*#Ops*/, 3, 4, 1, 
                // Src: (st GR16:i16:$src, addr:iPTR:$dst)<<P:Predicate_unindexedstore>><<P:Predicate_store>> - Complexity = 13
                // Dst: (MOV16mr addr:i16:$dst, GR16:i16:$src)
/*3431*/      0, /*End of Scope*/
/*3432*/    0, /*End of Scope*/
/*3433*/  /*SwitchOpcode*/ 62|128,5/*702*/,  TARGET_VAL(MSP430ISD::CMP),// ->4139
/*3437*/    OPC_Scope, 102|128,2/*358*/, /*->3798*/ // 4 children in Scope
/*3440*/      OPC_MoveChild, 0,
/*3442*/      OPC_SwitchOpcode /*2 cases */, 29|128,2/*285*/,  TARGET_VAL(ISD::AND),// ->3732
/*3447*/        OPC_Scope, 25|128,1/*153*/, /*->3603*/ // 3 children in Scope
/*3450*/          OPC_MoveChild, 0,
/*3452*/          OPC_CheckOpcode, TARGET_VAL(ISD::LOAD),
/*3455*/          OPC_RecordMemRef,
/*3456*/          OPC_RecordNode, // #0 = 'ld' chained node
/*3457*/          OPC_CheckFoldableChainNode,
/*3458*/          OPC_RecordChild1, // #1 = $src
/*3459*/          OPC_CheckPredicate, 0, // Predicate_unindexedload
/*3461*/          OPC_CheckPredicate, 1, // Predicate_load
/*3463*/          OPC_MoveParent,
/*3464*/          OPC_Scope, 76, /*->3542*/ // 2 children in Scope
/*3466*/            OPC_MoveChild, 1,
/*3468*/            OPC_CheckOpcode, TARGET_VAL(ISD::LOAD),
/*3471*/            OPC_RecordMemRef,
/*3472*/            OPC_RecordNode, // #2 = 'ld' chained node
/*3473*/            OPC_CheckFoldableChainNode,
/*3474*/            OPC_RecordChild1, // #3 = $src2
/*3475*/            OPC_CheckPredicate, 0, // Predicate_unindexedload
/*3477*/            OPC_CheckPredicate, 1, // Predicate_load
/*3479*/            OPC_MoveParent,
/*3480*/            OPC_CheckPredicate, 4, // Predicate_and_su
/*3482*/            OPC_SwitchType /*2 cases */, 27,  MVT::i8,// ->3512
/*3485*/              OPC_MoveParent,
/*3486*/              OPC_MoveChild, 1,
/*3488*/              OPC_CheckInteger, 0, 
/*3490*/              OPC_MoveParent,
/*3491*/              OPC_CheckComplexPat, /*CP*/0, /*#*/1, // SelectAddr:$src #4 #5
/*3494*/              OPC_CheckComplexPat, /*CP*/0, /*#*/3, // SelectAddr:$src2 #6 #7
/*3497*/              OPC_EmitMergeInputChains, 2, 0, 2, 
/*3501*/              OPC_MorphNodeTo, TARGET_VAL(MSP430::BIT8mm), 0|OPFL_Chain|OPFL_GlueOutput|OPFL_MemRefs,
                          1/*#VTs*/, MVT::i16, 4/*#Ops*/, 4, 5, 6, 7, 
                      // Src: (MSP430cmp (and:i8 (ld:i8 addr:iPTR:$src)<<P:Predicate_unindexedload>><<P:Predicate_load>>, (ld:i8 addr:iPTR:$src2)<<P:Predicate_unindexedload>><<P:Predicate_load>>)<<P:Predicate_and_su>>, 0:i8) - Complexity = 38
                      // Dst: (BIT8mm:i16 addr:i16:$src, addr:i16:$src2)
/*3512*/            /*SwitchType*/ 27,  MVT::i16,// ->3541
/*3514*/              OPC_MoveParent,
/*3515*/              OPC_MoveChild, 1,
/*3517*/              OPC_CheckInteger, 0, 
/*3519*/              OPC_MoveParent,
/*3520*/              OPC_CheckComplexPat, /*CP*/0, /*#*/1, // SelectAddr:$src #4 #5
/*3523*/              OPC_CheckComplexPat, /*CP*/0, /*#*/3, // SelectAddr:$src2 #6 #7
/*3526*/              OPC_EmitMergeInputChains, 2, 0, 2, 
/*3530*/              OPC_MorphNodeTo, TARGET_VAL(MSP430::BIT16mm), 0|OPFL_Chain|OPFL_GlueOutput|OPFL_MemRefs,
                          1/*#VTs*/, MVT::i16, 4/*#Ops*/, 4, 5, 6, 7, 
                      // Src: (MSP430cmp (and:i16 (ld:i16 addr:iPTR:$src)<<P:Predicate_unindexedload>><<P:Predicate_load>>, (ld:i16 addr:iPTR:$src2)<<P:Predicate_unindexedload>><<P:Predicate_load>>)<<P:Predicate_and_su>>, 0:i16) - Complexity = 38
                      // Dst: (BIT16mm:i16 addr:i16:$src, addr:i16:$src2)
/*3541*/            0, // EndSwitchType
/*3542*/          /*Scope*/ 59, /*->3602*/
/*3543*/            OPC_RecordChild1, // #2 = $src2
/*3544*/            OPC_MoveChild, 1,
/*3546*/            OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*3549*/            OPC_MoveParent,
/*3550*/            OPC_CheckPredicate, 4, // Predicate_and_su
/*3552*/            OPC_SwitchType /*2 cases */, 22,  MVT::i8,// ->3577
/*3555*/              OPC_MoveParent,
/*3556*/              OPC_MoveChild, 1,
/*3558*/              OPC_CheckInteger, 0, 
/*3560*/              OPC_MoveParent,
/*3561*/              OPC_CheckComplexPat, /*CP*/0, /*#*/1, // SelectAddr:$src #3 #4
/*3564*/              OPC_EmitMergeInputChains1_0,
/*3565*/              OPC_EmitConvertToTarget, 2,
/*3567*/              OPC_MorphNodeTo, TARGET_VAL(MSP430::BIT8mi), 0|OPFL_Chain|OPFL_GlueOutput|OPFL_MemRefs,
                          1/*#VTs*/, MVT::i16, 3/*#Ops*/, 3, 4, 5, 
                      // Src: (MSP430cmp (and:i8 (ld:i8 addr:iPTR:$src)<<P:Predicate_unindexedload>><<P:Predicate_load>>, (imm:i8):$src2)<<P:Predicate_and_su>>, 0:i8) - Complexity = 28
                      // Dst: (BIT8mi:i16 addr:i16:$src, (imm:i8):$src2)
/*3577*/            /*SwitchType*/ 22,  MVT::i16,// ->3601
/*3579*/              OPC_MoveParent,
/*3580*/              OPC_MoveChild, 1,
/*3582*/              OPC_CheckInteger, 0, 
/*3584*/              OPC_MoveParent,
/*3585*/              OPC_CheckComplexPat, /*CP*/0, /*#*/1, // SelectAddr:$src #3 #4
/*3588*/              OPC_EmitMergeInputChains1_0,
/*3589*/              OPC_EmitConvertToTarget, 2,
/*3591*/              OPC_MorphNodeTo, TARGET_VAL(MSP430::BIT16mi), 0|OPFL_Chain|OPFL_GlueOutput|OPFL_MemRefs,
                          1/*#VTs*/, MVT::i16, 3/*#Ops*/, 3, 4, 5, 
                      // Src: (MSP430cmp (and:i16 (ld:i16 addr:iPTR:$src)<<P:Predicate_unindexedload>><<P:Predicate_load>>, (imm:i16):$src2)<<P:Predicate_and_su>>, 0:i16) - Complexity = 28
                      // Dst: (BIT16mi:i16 addr:i16:$src, (imm:i16):$src2)
/*3601*/            0, // EndSwitchType
/*3602*/          0, /*End of Scope*/
/*3603*/        /*Scope*/ 63, /*->3667*/
/*3604*/          OPC_RecordChild0, // #0 = $src
/*3605*/          OPC_MoveChild, 1,
/*3607*/          OPC_CheckOpcode, TARGET_VAL(ISD::LOAD),
/*3610*/          OPC_RecordMemRef,
/*3611*/          OPC_RecordNode, // #1 = 'ld' chained node
/*3612*/          OPC_CheckFoldableChainNode,
/*3613*/          OPC_RecordChild1, // #2 = $src2
/*3614*/          OPC_CheckPredicate, 0, // Predicate_unindexedload
/*3616*/          OPC_CheckPredicate, 1, // Predicate_load
/*3618*/          OPC_MoveParent,
/*3619*/          OPC_CheckPredicate, 4, // Predicate_and_su
/*3621*/          OPC_SwitchType /*2 cases */, 20,  MVT::i8,// ->3644
/*3624*/            OPC_MoveParent,
/*3625*/            OPC_MoveChild, 1,
/*3627*/            OPC_CheckInteger, 0, 
/*3629*/            OPC_MoveParent,
/*3630*/            OPC_CheckComplexPat, /*CP*/0, /*#*/2, // SelectAddr:$src2 #3 #4
/*3633*/            OPC_EmitMergeInputChains1_1,
/*3634*/            OPC_MorphNodeTo, TARGET_VAL(MSP430::BIT8rm), 0|OPFL_Chain|OPFL_GlueOutput|OPFL_MemRefs,
                        1/*#VTs*/, MVT::i16, 3/*#Ops*/, 0, 3, 4, 
                    // Src: (MSP430cmp (and:i8 GR8:i8:$src, (ld:i8 addr:iPTR:$src2)<<P:Predicate_unindexedload>><<P:Predicate_load>>)<<P:Predicate_and_su>>, 0:i8) - Complexity = 25
                    // Dst: (BIT8rm:i16 GR8:i8:$src, addr:i16:$src2)
/*3644*/          /*SwitchType*/ 20,  MVT::i16,// ->3666
/*3646*/            OPC_MoveParent,
/*3647*/            OPC_MoveChild, 1,
/*3649*/            OPC_CheckInteger, 0, 
/*3651*/            OPC_MoveParent,
/*3652*/            OPC_CheckComplexPat, /*CP*/0, /*#*/2, // SelectAddr:$src2 #3 #4
/*3655*/            OPC_EmitMergeInputChains1_1,
/*3656*/            OPC_MorphNodeTo, TARGET_VAL(MSP430::BIT16rm), 0|OPFL_Chain|OPFL_GlueOutput|OPFL_MemRefs,
                        1/*#VTs*/, MVT::i16, 3/*#Ops*/, 0, 3, 4, 
                    // Src: (MSP430cmp (and:i16 GR16:i16:$src, (ld:i16 addr:iPTR:$src2)<<P:Predicate_unindexedload>><<P:Predicate_load>>)<<P:Predicate_and_su>>, 0:i16) - Complexity = 25
                    // Dst: (BIT16rm:i16 GR16:i16:$src, addr:i16:$src2)
/*3666*/          0, // EndSwitchType
/*3667*/        /*Scope*/ 63, /*->3731*/
/*3668*/          OPC_MoveChild, 0,
/*3670*/          OPC_CheckOpcode, TARGET_VAL(ISD::LOAD),
/*3673*/          OPC_RecordMemRef,
/*3674*/          OPC_RecordNode, // #0 = 'ld' chained node
/*3675*/          OPC_CheckFoldableChainNode,
/*3676*/          OPC_RecordChild1, // #1 = $src
/*3677*/          OPC_CheckPredicate, 0, // Predicate_unindexedload
/*3679*/          OPC_CheckPredicate, 1, // Predicate_load
/*3681*/          OPC_MoveParent,
/*3682*/          OPC_RecordChild1, // #2 = $src2
/*3683*/          OPC_CheckPredicate, 4, // Predicate_and_su
/*3685*/          OPC_SwitchType /*2 cases */, 20,  MVT::i8,// ->3708
/*3688*/            OPC_MoveParent,
/*3689*/            OPC_MoveChild, 1,
/*3691*/            OPC_CheckInteger, 0, 
/*3693*/            OPC_MoveParent,
/*3694*/            OPC_CheckComplexPat, /*CP*/0, /*#*/1, // SelectAddr:$src #3 #4
/*3697*/            OPC_EmitMergeInputChains1_0,
/*3698*/            OPC_MorphNodeTo, TARGET_VAL(MSP430::BIT8mr), 0|OPFL_Chain|OPFL_GlueOutput|OPFL_MemRefs,
                        1/*#VTs*/, MVT::i16, 3/*#Ops*/, 3, 4, 2, 
                    // Src: (MSP430cmp (and:i8 (ld:i8 addr:iPTR:$src)<<P:Predicate_unindexedload>><<P:Predicate_load>>, GR8:i8:$src2)<<P:Predicate_and_su>>, 0:i8) - Complexity = 25
                    // Dst: (BIT8mr:i16 addr:i16:$src, GR8:i8:$src2)
/*3708*/          /*SwitchType*/ 20,  MVT::i16,// ->3730
/*3710*/            OPC_MoveParent,
/*3711*/            OPC_MoveChild, 1,
/*3713*/            OPC_CheckInteger, 0, 
/*3715*/            OPC_MoveParent,
/*3716*/            OPC_CheckComplexPat, /*CP*/0, /*#*/1, // SelectAddr:$src #3 #4
/*3719*/            OPC_EmitMergeInputChains1_0,
/*3720*/            OPC_MorphNodeTo, TARGET_VAL(MSP430::BIT16mr), 0|OPFL_Chain|OPFL_GlueOutput|OPFL_MemRefs,
                        1/*#VTs*/, MVT::i16, 3/*#Ops*/, 3, 4, 2, 
                    // Src: (MSP430cmp (and:i16 (ld:i16 addr:iPTR:$src)<<P:Predicate_unindexedload>><<P:Predicate_load>>, GR16:i16:$src2)<<P:Predicate_and_su>>, 0:i16) - Complexity = 25
                    // Dst: (BIT16mr:i16 addr:i16:$src, GR16:i16:$src2)
/*3730*/          0, // EndSwitchType
/*3731*/        0, /*End of Scope*/
/*3732*/      /*SwitchOpcode*/ 62,  TARGET_VAL(ISD::LOAD),// ->3797
/*3735*/        OPC_RecordMemRef,
/*3736*/        OPC_RecordNode, // #0 = 'ld' chained node
/*3737*/        OPC_CheckFoldableChainNode,
/*3738*/        OPC_RecordChild1, // #1 = $src
/*3739*/        OPC_CheckPredicate, 0, // Predicate_unindexedload
/*3741*/        OPC_CheckPredicate, 1, // Predicate_load
/*3743*/        OPC_SwitchType /*2 cases */, 24,  MVT::i8,// ->3770
/*3746*/          OPC_MoveParent,
/*3747*/          OPC_RecordChild1, // #2 = $src2
/*3748*/          OPC_MoveChild, 1,
/*3750*/          OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*3753*/          OPC_MoveParent,
/*3754*/          OPC_CheckComplexPat, /*CP*/0, /*#*/1, // SelectAddr:$src #3 #4
/*3757*/          OPC_EmitMergeInputChains1_0,
/*3758*/          OPC_EmitConvertToTarget, 2,
/*3760*/          OPC_MorphNodeTo, TARGET_VAL(MSP430::CMP8mi), 0|OPFL_Chain|OPFL_GlueOutput|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i16, 3/*#Ops*/, 3, 4, 5, 
                  // Src: (MSP430cmp (ld:i8 addr:iPTR:$src)<<P:Predicate_unindexedload>><<P:Predicate_load>>, (imm:i8):$src2) - Complexity = 19
                  // Dst: (CMP8mi:i16 addr:i16:$src, (imm:i8):$src2)
/*3770*/        /*SwitchType*/ 24,  MVT::i16,// ->3796
/*3772*/          OPC_MoveParent,
/*3773*/          OPC_RecordChild1, // #2 = $src2
/*3774*/          OPC_MoveChild, 1,
/*3776*/          OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*3779*/          OPC_MoveParent,
/*3780*/          OPC_CheckComplexPat, /*CP*/0, /*#*/1, // SelectAddr:$src #3 #4
/*3783*/          OPC_EmitMergeInputChains1_0,
/*3784*/          OPC_EmitConvertToTarget, 2,
/*3786*/          OPC_MorphNodeTo, TARGET_VAL(MSP430::CMP16mi), 0|OPFL_Chain|OPFL_GlueOutput|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i16, 3/*#Ops*/, 3, 4, 5, 
                  // Src: (MSP430cmp (ld:i16 addr:iPTR:$src)<<P:Predicate_unindexedload>><<P:Predicate_load>>, (imm:i16):$src2) - Complexity = 19
                  // Dst: (CMP16mi:i16 addr:i16:$src, (imm:i16):$src2)
/*3796*/        0, // EndSwitchType
/*3797*/      0, // EndSwitchOpcode
/*3798*/    /*Scope*/ 65, /*->3864*/
/*3799*/      OPC_RecordChild0, // #0 = $src
/*3800*/      OPC_Scope, 30, /*->3832*/ // 2 children in Scope
/*3802*/        OPC_CheckChild0Type, MVT::i8,
/*3804*/        OPC_MoveChild, 1,
/*3806*/        OPC_CheckOpcode, TARGET_VAL(ISD::LOAD),
/*3809*/        OPC_RecordMemRef,
/*3810*/        OPC_RecordNode, // #1 = 'ld' chained node
/*3811*/        OPC_CheckFoldableChainNode,
/*3812*/        OPC_RecordChild1, // #2 = $src2
/*3813*/        OPC_CheckPredicate, 0, // Predicate_unindexedload
/*3815*/        OPC_CheckPredicate, 1, // Predicate_load
/*3817*/        OPC_MoveParent,
/*3818*/        OPC_CheckComplexPat, /*CP*/0, /*#*/2, // SelectAddr:$src2 #3 #4
/*3821*/        OPC_EmitMergeInputChains1_1,
/*3822*/        OPC_MorphNodeTo, TARGET_VAL(MSP430::CMP8rm), 0|OPFL_Chain|OPFL_GlueOutput|OPFL_MemRefs,
                    1/*#VTs*/, MVT::i16, 3/*#Ops*/, 0, 3, 4, 
                // Src: (MSP430cmp GR8:i8:$src, (ld:i8 addr:iPTR:$src2)<<P:Predicate_unindexedload>><<P:Predicate_load>>) - Complexity = 16
                // Dst: (CMP8rm:i16 GR8:i8:$src, addr:i16:$src2)
/*3832*/      /*Scope*/ 30, /*->3863*/
/*3833*/        OPC_CheckChild0Type, MVT::i16,
/*3835*/        OPC_MoveChild, 1,
/*3837*/        OPC_CheckOpcode, TARGET_VAL(ISD::LOAD),
/*3840*/        OPC_RecordMemRef,
/*3841*/        OPC_RecordNode, // #1 = 'ld' chained node
/*3842*/        OPC_CheckFoldableChainNode,
/*3843*/        OPC_RecordChild1, // #2 = $src2
/*3844*/        OPC_CheckPredicate, 0, // Predicate_unindexedload
/*3846*/        OPC_CheckPredicate, 1, // Predicate_load
/*3848*/        OPC_MoveParent,
/*3849*/        OPC_CheckComplexPat, /*CP*/0, /*#*/2, // SelectAddr:$src2 #3 #4
/*3852*/        OPC_EmitMergeInputChains1_1,
/*3853*/        OPC_MorphNodeTo, TARGET_VAL(MSP430::CMP16rm), 0|OPFL_Chain|OPFL_GlueOutput|OPFL_MemRefs,
                    1/*#VTs*/, MVT::i16, 3/*#Ops*/, 0, 3, 4, 
                // Src: (MSP430cmp GR16:i16:$src, (ld:i16 addr:iPTR:$src2)<<P:Predicate_unindexedload>><<P:Predicate_load>>) - Complexity = 16
                // Dst: (CMP16rm:i16 GR16:i16:$src, addr:i16:$src2)
/*3863*/      0, /*End of Scope*/
/*3864*/    /*Scope*/ 72|128,1/*200*/, /*->4066*/
/*3866*/      OPC_MoveChild, 0,
/*3868*/      OPC_SwitchOpcode /*3 cases */, 46,  TARGET_VAL(ISD::LOAD),// ->3918
/*3872*/        OPC_RecordMemRef,
/*3873*/        OPC_RecordNode, // #0 = 'ld' chained node
/*3874*/        OPC_CheckFoldableChainNode,
/*3875*/        OPC_RecordChild1, // #1 = $src
/*3876*/        OPC_CheckPredicate, 0, // Predicate_unindexedload
/*3878*/        OPC_CheckPredicate, 1, // Predicate_load
/*3880*/        OPC_SwitchType /*2 cases */, 16,  MVT::i8,// ->3899
/*3883*/          OPC_MoveParent,
/*3884*/          OPC_RecordChild1, // #2 = $src2
/*3885*/          OPC_CheckComplexPat, /*CP*/0, /*#*/1, // SelectAddr:$src #3 #4
/*3888*/          OPC_EmitMergeInputChains1_0,
/*3889*/          OPC_MorphNodeTo, TARGET_VAL(MSP430::CMP8mr), 0|OPFL_Chain|OPFL_GlueOutput|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i16, 3/*#Ops*/, 3, 4, 2, 
                  // Src: (MSP430cmp (ld:i8 addr:iPTR:$src)<<P:Predicate_unindexedload>><<P:Predicate_load>>, GR8:i8:$src2) - Complexity = 16
                  // Dst: (CMP8mr:i16 addr:i16:$src, GR8:i8:$src2)
/*3899*/        /*SwitchType*/ 16,  MVT::i16,// ->3917
/*3901*/          OPC_MoveParent,
/*3902*/          OPC_RecordChild1, // #2 = $src2
/*3903*/          OPC_CheckComplexPat, /*CP*/0, /*#*/1, // SelectAddr:$src #3 #4
/*3906*/          OPC_EmitMergeInputChains1_0,
/*3907*/          OPC_MorphNodeTo, TARGET_VAL(MSP430::CMP16mr), 0|OPFL_Chain|OPFL_GlueOutput|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i16, 3/*#Ops*/, 3, 4, 2, 
                  // Src: (MSP430cmp (ld:i16 addr:iPTR:$src)<<P:Predicate_unindexedload>><<P:Predicate_load>>, GR16:i16:$src2) - Complexity = 16
                  // Dst: (CMP16mr:i16 addr:i16:$src, GR16:i16:$src2)
/*3917*/        0, // EndSwitchType
/*3918*/      /*SwitchOpcode*/ 92,  TARGET_VAL(ISD::AND),// ->4013
/*3921*/        OPC_RecordChild0, // #0 = $src
/*3922*/        OPC_RecordChild1, // #1 = $src2
/*3923*/        OPC_Scope, 48, /*->3973*/ // 2 children in Scope
/*3925*/          OPC_MoveChild, 1,
/*3927*/          OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*3930*/          OPC_MoveParent,
/*3931*/          OPC_CheckPredicate, 4, // Predicate_and_su
/*3933*/          OPC_SwitchType /*2 cases */, 17,  MVT::i8,// ->3953
/*3936*/            OPC_MoveParent,
/*3937*/            OPC_MoveChild, 1,
/*3939*/            OPC_CheckInteger, 0, 
/*3941*/            OPC_MoveParent,
/*3942*/            OPC_EmitConvertToTarget, 1,
/*3944*/            OPC_MorphNodeTo, TARGET_VAL(MSP430::BIT8ri), 0|OPFL_GlueOutput,
                        1/*#VTs*/, MVT::i16, 2/*#Ops*/, 0, 2, 
                    // Src: (MSP430cmp (and:i8 GR8:i8:$src, (imm:i8):$src2)<<P:Predicate_and_su>>, 0:i8) - Complexity = 15
                    // Dst: (BIT8ri:i16 GR8:i8:$src, (imm:i8):$src2)
/*3953*/          /*SwitchType*/ 17,  MVT::i16,// ->3972
/*3955*/            OPC_MoveParent,
/*3956*/            OPC_MoveChild, 1,
/*3958*/            OPC_CheckInteger, 0, 
/*3960*/            OPC_MoveParent,
/*3961*/            OPC_EmitConvertToTarget, 1,
/*3963*/            OPC_MorphNodeTo, TARGET_VAL(MSP430::BIT16ri), 0|OPFL_GlueOutput,
                        1/*#VTs*/, MVT::i16, 2/*#Ops*/, 0, 2, 
                    // Src: (MSP430cmp (and:i16 GR16:i16:$src, (imm:i16):$src2)<<P:Predicate_and_su>>, 0:i16) - Complexity = 15
                    // Dst: (BIT16ri:i16 GR16:i16:$src, (imm:i16):$src2)
/*3972*/          0, // EndSwitchType
/*3973*/        /*Scope*/ 38, /*->4012*/
/*3974*/          OPC_CheckPredicate, 4, // Predicate_and_su
/*3976*/          OPC_SwitchType /*2 cases */, 15,  MVT::i8,// ->3994
/*3979*/            OPC_MoveParent,
/*3980*/            OPC_MoveChild, 1,
/*3982*/            OPC_CheckInteger, 0, 
/*3984*/            OPC_MoveParent,
/*3985*/            OPC_MorphNodeTo, TARGET_VAL(MSP430::BIT8rr), 0|OPFL_GlueOutput,
                        1/*#VTs*/, MVT::i16, 2/*#Ops*/, 0, 1, 
                    // Src: (MSP430cmp (and:i8 GR8:i8:$src, GR8:i8:$src2)<<P:Predicate_and_su>>, 0:i8) - Complexity = 12
                    // Dst: (BIT8rr:i16 GR8:i8:$src, GR8:i8:$src2)
/*3994*/          /*SwitchType*/ 15,  MVT::i16,// ->4011
/*3996*/            OPC_MoveParent,
/*3997*/            OPC_MoveChild, 1,
/*3999*/            OPC_CheckInteger, 0, 
/*4001*/            OPC_MoveParent,
/*4002*/            OPC_MorphNodeTo, TARGET_VAL(MSP430::BIT16rr), 0|OPFL_GlueOutput,
                        1/*#VTs*/, MVT::i16, 2/*#Ops*/, 0, 1, 
                    // Src: (MSP430cmp (and:i16 GR16:i16:$src, GR16:i16:$src2)<<P:Predicate_and_su>>, 0:i16) - Complexity = 12
                    // Dst: (BIT16rr:i16 GR16:i16:$src, GR16:i16:$src2)
/*4011*/          0, // EndSwitchType
/*4012*/        0, /*End of Scope*/
/*4013*/      /*SwitchOpcode*/ 49,  TARGET_VAL(ISD::TRUNCATE),// ->4065
/*4016*/        OPC_MoveChild, 0,
/*4018*/        OPC_CheckOpcode, TARGET_VAL(ISD::AND),
/*4021*/        OPC_RecordChild0, // #0 = $src
/*4022*/        OPC_RecordChild1, // #1 = $src2
/*4023*/        OPC_CheckPredicate, 4, // Predicate_and_su
/*4025*/        OPC_MoveParent,
/*4026*/        OPC_MoveParent,
/*4027*/        OPC_MoveChild, 1,
/*4029*/        OPC_CheckInteger, 0, 
/*4031*/        OPC_MoveParent,
/*4032*/        OPC_EmitInteger, MVT::i32, MSP430::subreg_8bit,
/*4035*/        OPC_EmitNode, TARGET_VAL(TargetOpcode::EXTRACT_SUBREG), 0,
                    1/*#VTs*/, MVT::i8, 2/*#Ops*/, 0, 2,  // Results = #3
/*4044*/        OPC_EmitInteger, MVT::i32, MSP430::subreg_8bit,
/*4047*/        OPC_EmitNode, TARGET_VAL(TargetOpcode::EXTRACT_SUBREG), 0,
                    1/*#VTs*/, MVT::i8, 2/*#Ops*/, 1, 4,  // Results = #5
/*4056*/        OPC_MorphNodeTo, TARGET_VAL(MSP430::BIT8rr), 0|OPFL_GlueOutput,
                    1/*#VTs*/, MVT::i16, 2/*#Ops*/, 3, 5, 
                // Src: (MSP430cmp (trunc:i8 (and:i16 GR16:i16:$src, GR16:i16:$src2)<<P:Predicate_and_su>>), 0:i8) - Complexity = 15
                // Dst: (BIT8rr:i16 (EXTRACT_SUBREG:i8 GR16:i16:$src, subreg_8bit:i32), (EXTRACT_SUBREG:i8 GR16:i16:$src2, subreg_8bit:i32))
/*4065*/      0, // EndSwitchOpcode
/*4066*/    /*Scope*/ 71, /*->4138*/
/*4067*/      OPC_RecordChild0, // #0 = $src
/*4068*/      OPC_Scope, 33, /*->4103*/ // 2 children in Scope
/*4070*/        OPC_CheckChild0Type, MVT::i8,
/*4072*/        OPC_RecordChild1, // #1 = $src2
/*4073*/        OPC_Scope, 17, /*->4092*/ // 2 children in Scope
/*4075*/          OPC_MoveChild, 1,
/*4077*/          OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*4080*/          OPC_MoveParent,
/*4081*/          OPC_EmitConvertToTarget, 1,
/*4083*/          OPC_MorphNodeTo, TARGET_VAL(MSP430::CMP8ri), 0|OPFL_GlueOutput,
                      1/*#VTs*/, MVT::i16, 2/*#Ops*/, 0, 2, 
                  // Src: (MSP430cmp GR8:i8:$src, (imm:i8):$src2) - Complexity = 6
                  // Dst: (CMP8ri:i16 GR8:i8:$src, (imm:i8):$src2)
/*4092*/        /*Scope*/ 9, /*->4102*/
/*4093*/          OPC_MorphNodeTo, TARGET_VAL(MSP430::CMP8rr), 0|OPFL_GlueOutput,
                      1/*#VTs*/, MVT::i16, 2/*#Ops*/, 0, 1, 
                  // Src: (MSP430cmp GR8:i8:$src, GR8:i8:$src2) - Complexity = 3
                  // Dst: (CMP8rr:i16 GR8:i8:$src, GR8:i8:$src2)
/*4102*/        0, /*End of Scope*/
/*4103*/      /*Scope*/ 33, /*->4137*/
/*4104*/        OPC_CheckChild0Type, MVT::i16,
/*4106*/        OPC_RecordChild1, // #1 = $src2
/*4107*/        OPC_Scope, 17, /*->4126*/ // 2 children in Scope
/*4109*/          OPC_MoveChild, 1,
/*4111*/          OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*4114*/          OPC_MoveParent,
/*4115*/          OPC_EmitConvertToTarget, 1,
/*4117*/          OPC_MorphNodeTo, TARGET_VAL(MSP430::CMP16ri), 0|OPFL_GlueOutput,
                      1/*#VTs*/, MVT::i16, 2/*#Ops*/, 0, 2, 
                  // Src: (MSP430cmp GR16:i16:$src, (imm:i16):$src2) - Complexity = 6
                  // Dst: (CMP16ri:i16 GR16:i16:$src, (imm:i16):$src2)
/*4126*/        /*Scope*/ 9, /*->4136*/
/*4127*/          OPC_MorphNodeTo, TARGET_VAL(MSP430::CMP16rr), 0|OPFL_GlueOutput,
                      1/*#VTs*/, MVT::i16, 2/*#Ops*/, 0, 1, 
                  // Src: (MSP430cmp GR16:i16:$src, GR16:i16:$src2) - Complexity = 3
                  // Dst: (CMP16rr:i16 GR16:i16:$src, GR16:i16:$src2)
/*4136*/        0, /*End of Scope*/
/*4137*/      0, /*End of Scope*/
/*4138*/    0, /*End of Scope*/
/*4139*/  /*SwitchOpcode*/ 47|128,3/*431*/,  TARGET_VAL(ISD::AND),// ->4574
/*4143*/    OPC_Scope, 71, /*->4216*/ // 8 children in Scope
/*4145*/      OPC_RecordChild0, // #0 = $src
/*4146*/      OPC_MoveChild, 1,
/*4148*/      OPC_CheckOpcode, TARGET_VAL(ISD::XOR),
/*4151*/      OPC_MoveChild, 0,
/*4153*/      OPC_CheckOpcode, TARGET_VAL(ISD::LOAD),
/*4156*/      OPC_RecordMemRef,
/*4157*/      OPC_RecordNode, // #1 = 'ld' chained node
/*4158*/      OPC_CheckFoldableChainNode,
/*4159*/      OPC_RecordChild1, // #2 = $src2
/*4160*/      OPC_CheckPredicate, 0, // Predicate_unindexedload
/*4162*/      OPC_CheckPredicate, 1, // Predicate_load
/*4164*/      OPC_MoveParent,
/*4165*/      OPC_MoveChild, 1,
/*4167*/      OPC_CheckInteger, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*4178*/      OPC_MoveParent,
/*4179*/      OPC_MoveParent,
/*4180*/      OPC_SwitchType /*2 cases */, 15,  MVT::i8,// ->4198
/*4183*/        OPC_CheckComplexPat, /*CP*/0, /*#*/2, // SelectAddr:$src2 #3 #4
/*4186*/        OPC_EmitMergeInputChains1_1,
/*4187*/        OPC_MorphNodeTo, TARGET_VAL(MSP430::BIC8rm), 0|OPFL_Chain|OPFL_MemRefs,
                    2/*#VTs*/, MVT::i8, MVT::i16, 3/*#Ops*/, 0, 3, 4, 
                // Src: (and:i8 GR8:i8:$src, (xor:i8 (ld:i8 addr:iPTR:$src2)<<P:Predicate_unindexedload>><<P:Predicate_load>>, -1:i8)) - Complexity = 24
                // Dst: (BIC8rm:i8:i16 GR8:i8:$src, addr:i16:$src2)
/*4198*/      /*SwitchType*/ 15,  MVT::i16,// ->4215
/*4200*/        OPC_CheckComplexPat, /*CP*/0, /*#*/2, // SelectAddr:$src2 #3 #4
/*4203*/        OPC_EmitMergeInputChains1_1,
/*4204*/        OPC_MorphNodeTo, TARGET_VAL(MSP430::BIC16rm), 0|OPFL_Chain|OPFL_MemRefs,
                    2/*#VTs*/, MVT::i16, MVT::i16, 3/*#Ops*/, 0, 3, 4, 
                // Src: (and:i16 GR16:i16:$src, (xor:i16 (ld:i16 addr:iPTR:$src2)<<P:Predicate_unindexedload>><<P:Predicate_load>>, -1:i16)) - Complexity = 24
                // Dst: (BIC16rm:i16:i16 GR16:i16:$src, addr:i16:$src2)
/*4215*/      0, // EndSwitchType
/*4216*/    /*Scope*/ 71, /*->4288*/
/*4217*/      OPC_MoveChild, 0,
/*4219*/      OPC_CheckOpcode, TARGET_VAL(ISD::XOR),
/*4222*/      OPC_MoveChild, 0,
/*4224*/      OPC_CheckOpcode, TARGET_VAL(ISD::LOAD),
/*4227*/      OPC_RecordMemRef,
/*4228*/      OPC_RecordNode, // #0 = 'ld' chained node
/*4229*/      OPC_CheckFoldableChainNode,
/*4230*/      OPC_RecordChild1, // #1 = $src2
/*4231*/      OPC_CheckPredicate, 0, // Predicate_unindexedload
/*4233*/      OPC_CheckPredicate, 1, // Predicate_load
/*4235*/      OPC_MoveParent,
/*4236*/      OPC_MoveChild, 1,
/*4238*/      OPC_CheckInteger, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*4249*/      OPC_MoveParent,
/*4250*/      OPC_MoveParent,
/*4251*/      OPC_RecordChild1, // #2 = $src
/*4252*/      OPC_SwitchType /*2 cases */, 15,  MVT::i8,// ->4270
/*4255*/        OPC_CheckComplexPat, /*CP*/0, /*#*/1, // SelectAddr:$src2 #3 #4
/*4258*/        OPC_EmitMergeInputChains1_0,
/*4259*/        OPC_MorphNodeTo, TARGET_VAL(MSP430::BIC8rm), 0|OPFL_Chain|OPFL_MemRefs,
                    2/*#VTs*/, MVT::i8, MVT::i16, 3/*#Ops*/, 2, 3, 4, 
                // Src: (and:i8 (xor:i8 (ld:i8 addr:iPTR:$src2)<<P:Predicate_unindexedload>><<P:Predicate_load>>, -1:i8), GR8:i8:$src) - Complexity = 24
                // Dst: (BIC8rm:i8:i16 GR8:i8:$src, addr:i16:$src2)
/*4270*/      /*SwitchType*/ 15,  MVT::i16,// ->4287
/*4272*/        OPC_CheckComplexPat, /*CP*/0, /*#*/1, // SelectAddr:$src2 #3 #4
/*4275*/        OPC_EmitMergeInputChains1_0,
/*4276*/        OPC_MorphNodeTo, TARGET_VAL(MSP430::BIC16rm), 0|OPFL_Chain|OPFL_MemRefs,
                    2/*#VTs*/, MVT::i16, MVT::i16, 3/*#Ops*/, 2, 3, 4, 
                // Src: (and:i16 (xor:i16 (ld:i16 addr:iPTR:$src2)<<P:Predicate_unindexedload>><<P:Predicate_load>>, -1:i16), GR16:i16:$src) - Complexity = 24
                // Dst: (BIC16rm:i16:i16 GR16:i16:$src, addr:i16:$src2)
/*4287*/      0, // EndSwitchType
/*4288*/    /*Scope*/ 51, /*->4340*/
/*4289*/      OPC_RecordChild0, // #0 = $src
/*4290*/      OPC_MoveChild, 1,
/*4292*/      OPC_CheckOpcode, TARGET_VAL(ISD::LOAD),
/*4295*/      OPC_RecordMemRef,
/*4296*/      OPC_RecordNode, // #1 = 'ld' chained node
/*4297*/      OPC_CheckFoldableChainNode,
/*4298*/      OPC_RecordChild1, // #2 = $src2
/*4299*/      OPC_CheckPredicate, 0, // Predicate_unindexedload
/*4301*/      OPC_CheckPredicate, 1, // Predicate_load
/*4303*/      OPC_MoveParent,
/*4304*/      OPC_SwitchType /*2 cases */, 15,  MVT::i8,// ->4322
/*4307*/        OPC_CheckComplexPat, /*CP*/0, /*#*/2, // SelectAddr:$src2 #3 #4
/*4310*/        OPC_EmitMergeInputChains1_1,
/*4311*/        OPC_MorphNodeTo, TARGET_VAL(MSP430::AND8rm), 0|OPFL_Chain|OPFL_MemRefs,
                    2/*#VTs*/, MVT::i8, MVT::i16, 3/*#Ops*/, 0, 3, 4, 
                // Src: (and:i8 GR8:i8:$src, (ld:i8 addr:iPTR:$src2)<<P:Predicate_unindexedload>><<P:Predicate_load>>) - Complexity = 16
                // Dst: (AND8rm:i8:i16 GR8:i8:$src, addr:i16:$src2)
/*4322*/      /*SwitchType*/ 15,  MVT::i16,// ->4339
/*4324*/        OPC_CheckComplexPat, /*CP*/0, /*#*/2, // SelectAddr:$src2 #3 #4
/*4327*/        OPC_EmitMergeInputChains1_1,
/*4328*/        OPC_MorphNodeTo, TARGET_VAL(MSP430::AND16rm), 0|OPFL_Chain|OPFL_MemRefs,
                    2/*#VTs*/, MVT::i16, MVT::i16, 3/*#Ops*/, 0, 3, 4, 
                // Src: (and:i16 GR16:i16:$src, (ld:i16 addr:iPTR:$src2)<<P:Predicate_unindexedload>><<P:Predicate_load>>) - Complexity = 16
                // Dst: (AND16rm:i16:i16 GR16:i16:$src, addr:i16:$src2)
/*4339*/      0, // EndSwitchType
/*4340*/    /*Scope*/ 51, /*->4392*/
/*4341*/      OPC_MoveChild, 0,
/*4343*/      OPC_CheckOpcode, TARGET_VAL(ISD::LOAD),
/*4346*/      OPC_RecordMemRef,
/*4347*/      OPC_RecordNode, // #0 = 'ld' chained node
/*4348*/      OPC_CheckFoldableChainNode,
/*4349*/      OPC_RecordChild1, // #1 = $src2
/*4350*/      OPC_CheckPredicate, 0, // Predicate_unindexedload
/*4352*/      OPC_CheckPredicate, 1, // Predicate_load
/*4354*/      OPC_MoveParent,
/*4355*/      OPC_RecordChild1, // #2 = $src
/*4356*/      OPC_SwitchType /*2 cases */, 15,  MVT::i8,// ->4374
/*4359*/        OPC_CheckComplexPat, /*CP*/0, /*#*/1, // SelectAddr:$src2 #3 #4
/*4362*/        OPC_EmitMergeInputChains1_0,
/*4363*/        OPC_MorphNodeTo, TARGET_VAL(MSP430::AND8rm), 0|OPFL_Chain|OPFL_MemRefs,
                    2/*#VTs*/, MVT::i8, MVT::i16, 3/*#Ops*/, 2, 3, 4, 
                // Src: (and:i8 (ld:i8 addr:iPTR:$src2)<<P:Predicate_unindexedload>><<P:Predicate_load>>, GR8:i8:$src) - Complexity = 16
                // Dst: (AND8rm:i8:i16 GR8:i8:$src, addr:i16:$src2)
/*4374*/      /*SwitchType*/ 15,  MVT::i16,// ->4391
/*4376*/        OPC_CheckComplexPat, /*CP*/0, /*#*/1, // SelectAddr:$src2 #3 #4
/*4379*/        OPC_EmitMergeInputChains1_0,
/*4380*/        OPC_MorphNodeTo, TARGET_VAL(MSP430::AND16rm), 0|OPFL_Chain|OPFL_MemRefs,
                    2/*#VTs*/, MVT::i16, MVT::i16, 3/*#Ops*/, 2, 3, 4, 
                // Src: (and:i16 (ld:i16 addr:iPTR:$src2)<<P:Predicate_unindexedload>><<P:Predicate_load>>, GR16:i16:$src) - Complexity = 16
                // Dst: (AND16rm:i16:i16 GR16:i16:$src, addr:i16:$src2)
/*4391*/      0, // EndSwitchType
/*4392*/    /*Scope*/ 48, /*->4441*/
/*4393*/      OPC_RecordChild0, // #0 = $src
/*4394*/      OPC_MoveChild, 1,
/*4396*/      OPC_CheckOpcode, TARGET_VAL(ISD::XOR),
/*4399*/      OPC_RecordChild0, // #1 = $src2
/*4400*/      OPC_MoveChild, 1,
/*4402*/      OPC_CheckInteger, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*4413*/      OPC_MoveParent,
/*4414*/      OPC_MoveParent,
/*4415*/      OPC_SwitchType /*2 cases */, 10,  MVT::i8,// ->4428
/*4418*/        OPC_MorphNodeTo, TARGET_VAL(MSP430::BIC8rr), 0,
                    2/*#VTs*/, MVT::i8, MVT::i16, 2/*#Ops*/, 0, 1, 
                // Src: (and:i8 GR8:i8:$src, (xor:i8 GR8:i8:$src2, -1:i8)) - Complexity = 11
                // Dst: (BIC8rr:i8:i16 GR8:i8:$src, GR8:i8:$src2)
/*4428*/      /*SwitchType*/ 10,  MVT::i16,// ->4440
/*4430*/        OPC_MorphNodeTo, TARGET_VAL(MSP430::BIC16rr), 0,
                    2/*#VTs*/, MVT::i16, MVT::i16, 2/*#Ops*/, 0, 1, 
                // Src: (and:i16 GR16:i16:$src, (xor:i16 GR16:i16:$src2, -1:i16)) - Complexity = 11
                // Dst: (BIC16rr:i16:i16 GR16:i16:$src, GR16:i16:$src2)
/*4440*/      0, // EndSwitchType
/*4441*/    /*Scope*/ 48, /*->4490*/
/*4442*/      OPC_MoveChild, 0,
/*4444*/      OPC_CheckOpcode, TARGET_VAL(ISD::XOR),
/*4447*/      OPC_RecordChild0, // #0 = $src2
/*4448*/      OPC_MoveChild, 1,
/*4450*/      OPC_CheckInteger, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*4461*/      OPC_MoveParent,
/*4462*/      OPC_MoveParent,
/*4463*/      OPC_RecordChild1, // #1 = $src
/*4464*/      OPC_SwitchType /*2 cases */, 10,  MVT::i8,// ->4477
/*4467*/        OPC_MorphNodeTo, TARGET_VAL(MSP430::BIC8rr), 0,
                    2/*#VTs*/, MVT::i8, MVT::i16, 2/*#Ops*/, 1, 0, 
                // Src: (and:i8 (xor:i8 GR8:i8:$src2, -1:i8), GR8:i8:$src) - Complexity = 11
                // Dst: (BIC8rr:i8:i16 GR8:i8:$src, GR8:i8:$src2)
/*4477*/      /*SwitchType*/ 10,  MVT::i16,// ->4489
/*4479*/        OPC_MorphNodeTo, TARGET_VAL(MSP430::BIC16rr), 0,
                    2/*#VTs*/, MVT::i16, MVT::i16, 2/*#Ops*/, 1, 0, 
                // Src: (and:i16 (xor:i16 GR16:i16:$src2, -1:i16), GR16:i16:$src) - Complexity = 11
                // Dst: (BIC16rr:i16:i16 GR16:i16:$src, GR16:i16:$src2)
/*4489*/      0, // EndSwitchType
/*4490*/    /*Scope*/ 14, /*->4505*/
/*4491*/      OPC_CheckAndImm, 127|128,1/*255*/, 
/*4494*/      OPC_RecordChild0, // #0 = $src
/*4495*/      OPC_CheckType, MVT::i16,
/*4497*/      OPC_MorphNodeTo, TARGET_VAL(MSP430::ZEXT16r), 0,
                  1/*#VTs*/, MVT::i16, 1/*#Ops*/, 0, 
              // Src: (and:i16 GR16:i16:$src, 255:i16) - Complexity = 8
              // Dst: (ZEXT16r:i16 GR16:i16:$src)
/*4505*/    /*Scope*/ 67, /*->4573*/
/*4506*/      OPC_RecordChild0, // #0 = $src
/*4507*/      OPC_RecordChild1, // #1 = $src2
/*4508*/      OPC_Scope, 36, /*->4546*/ // 3 children in Scope
/*4510*/        OPC_MoveChild, 1,
/*4512*/        OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*4515*/        OPC_MoveParent,
/*4516*/        OPC_SwitchType /*2 cases */, 12,  MVT::i8,// ->4531
/*4519*/          OPC_EmitConvertToTarget, 1,
/*4521*/          OPC_MorphNodeTo, TARGET_VAL(MSP430::AND8ri), 0,
                      2/*#VTs*/, MVT::i8, MVT::i16, 2/*#Ops*/, 0, 2, 
                  // Src: (and:i8 GR8:i8:$src, (imm:i8):$src2) - Complexity = 6
                  // Dst: (AND8ri:i8:i16 GR8:i8:$src, (imm:i8):$src2)
/*4531*/        /*SwitchType*/ 12,  MVT::i16,// ->4545
/*4533*/          OPC_EmitConvertToTarget, 1,
/*4535*/          OPC_MorphNodeTo, TARGET_VAL(MSP430::AND16ri), 0,
                      2/*#VTs*/, MVT::i16, MVT::i16, 2/*#Ops*/, 0, 2, 
                  // Src: (and:i16 GR16:i16:$src, (imm:i16):$src2) - Complexity = 6
                  // Dst: (AND16ri:i16:i16 GR16:i16:$src, (imm:i16):$src2)
/*4545*/        0, // EndSwitchType
/*4546*/      /*Scope*/ 12, /*->4559*/
/*4547*/        OPC_CheckType, MVT::i8,
/*4549*/        OPC_MorphNodeTo, TARGET_VAL(MSP430::AND8rr), 0,
                    2/*#VTs*/, MVT::i8, MVT::i16, 2/*#Ops*/, 0, 1, 
                // Src: (and:i8 GR8:i8:$src, GR8:i8:$src2) - Complexity = 3
                // Dst: (AND8rr:i8:i16 GR8:i8:$src, GR8:i8:$src2)
/*4559*/      /*Scope*/ 12, /*->4572*/
/*4560*/        OPC_CheckType, MVT::i16,
/*4562*/        OPC_MorphNodeTo, TARGET_VAL(MSP430::AND16rr), 0,
                    2/*#VTs*/, MVT::i16, MVT::i16, 2/*#Ops*/, 0, 1, 
                // Src: (and:i16 GR16:i16:$src, GR16:i16:$src2) - Complexity = 3
                // Dst: (AND16rr:i16:i16 GR16:i16:$src, GR16:i16:$src2)
/*4572*/      0, /*End of Scope*/
/*4573*/    0, /*End of Scope*/
/*4574*/  /*SwitchOpcode*/ 63,  TARGET_VAL(ISD::BRIND),// ->4640
/*4577*/    OPC_RecordNode,   // #0 = 'brind' chained node
/*4578*/    OPC_Scope, 29, /*->4609*/ // 2 children in Scope
/*4580*/      OPC_MoveChild, 1,
/*4582*/      OPC_CheckOpcode, TARGET_VAL(ISD::LOAD),
/*4585*/      OPC_RecordMemRef,
/*4586*/      OPC_RecordNode, // #1 = 'ld' chained node
/*4587*/      OPC_CheckFoldableChainNode,
/*4588*/      OPC_RecordChild1, // #2 = $brdst
/*4589*/      OPC_CheckPredicate, 0, // Predicate_unindexedload
/*4591*/      OPC_CheckPredicate, 1, // Predicate_load
/*4593*/      OPC_MoveParent,
/*4594*/      OPC_CheckComplexPat, /*CP*/0, /*#*/2, // SelectAddr:$brdst #3 #4
/*4597*/      OPC_EmitMergeInputChains, 2, 0, 1, 
/*4601*/      OPC_MorphNodeTo, TARGET_VAL(MSP430::Bm), 0|OPFL_Chain|OPFL_MemRefs,
                  0/*#VTs*/, 2/*#Ops*/, 3, 4, 
              // Src: (brind (ld:iPTR addr:iPTR:$brdst)<<P:Predicate_unindexedload>><<P:Predicate_load>>) - Complexity = 16
              // Dst: (Bm addr:i16:$brdst)
/*4609*/    /*Scope*/ 29, /*->4639*/
/*4610*/      OPC_RecordChild1, // #1 = $brdst
/*4611*/      OPC_Scope, 14, /*->4627*/ // 2 children in Scope
/*4613*/        OPC_MoveChild, 1,
/*4615*/        OPC_CheckOpcode, TARGET_VAL(ISD::TargetBlockAddress),
/*4618*/        OPC_MoveParent,
/*4619*/        OPC_EmitMergeInputChains1_0,
/*4620*/        OPC_MorphNodeTo, TARGET_VAL(MSP430::Bi), 0|OPFL_Chain,
                    0/*#VTs*/, 1/*#Ops*/, 1, 
                // Src: (brind (tblockaddress:iPTR):$brdst) - Complexity = 6
                // Dst: (Bi (tblockaddress:i16):$brdst)
/*4627*/      /*Scope*/ 10, /*->4638*/
/*4628*/        OPC_CheckChild1Type, MVT::i16,
/*4630*/        OPC_EmitMergeInputChains1_0,
/*4631*/        OPC_MorphNodeTo, TARGET_VAL(MSP430::Br), 0|OPFL_Chain,
                    0/*#VTs*/, 1/*#Ops*/, 1, 
                // Src: (brind GR16:i16:$brdst) - Complexity = 3
                // Dst: (Br GR16:i16:$brdst)
/*4638*/      0, /*End of Scope*/
/*4639*/    0, /*End of Scope*/
/*4640*/  /*SwitchOpcode*/ 101,  TARGET_VAL(MSP430ISD::CALL),// ->4744
/*4643*/    OPC_RecordNode,   // #0 = 'MSP430call' chained node
/*4644*/    OPC_CaptureGlueInput,
/*4645*/    OPC_Scope, 30, /*->4677*/ // 2 children in Scope
/*4647*/      OPC_MoveChild, 1,
/*4649*/      OPC_CheckOpcode, TARGET_VAL(ISD::LOAD),
/*4652*/      OPC_RecordMemRef,
/*4653*/      OPC_RecordNode, // #1 = 'ld' chained node
/*4654*/      OPC_CheckFoldableChainNode,
/*4655*/      OPC_RecordChild1, // #2 = $dst
/*4656*/      OPC_CheckPredicate, 0, // Predicate_unindexedload
/*4658*/      OPC_CheckPredicate, 1, // Predicate_load
/*4660*/      OPC_MoveParent,
/*4661*/      OPC_CheckComplexPat, /*CP*/0, /*#*/2, // SelectAddr:$dst #3 #4
/*4664*/      OPC_EmitMergeInputChains, 2, 0, 1, 
/*4668*/      OPC_MorphNodeTo, TARGET_VAL(MSP430::CALLm), 0|OPFL_Chain|OPFL_GlueInput|OPFL_GlueOutput|OPFL_MemRefs|OPFL_Variadic1,
                  1/*#VTs*/, MVT::i16, 2/*#Ops*/, 3, 4, 
              // Src: (MSP430call (ld:iPTR addr:iPTR:$dst)<<P:Predicate_unindexedload>><<P:Predicate_load>>) - Complexity = 16
              // Dst: (CALLm:i16 addr:i16:$dst)
/*4677*/    /*Scope*/ 65, /*->4743*/
/*4678*/      OPC_RecordChild1, // #1 = $dst
/*4679*/      OPC_Scope, 49, /*->4730*/ // 2 children in Scope
/*4681*/        OPC_MoveChild, 1,
/*4683*/        OPC_SwitchOpcode /*3 cases */, 12,  TARGET_VAL(ISD::Constant),// ->4699
/*4687*/          OPC_MoveParent,
/*4688*/          OPC_EmitMergeInputChains1_0,
/*4689*/          OPC_EmitConvertToTarget, 1,
/*4691*/          OPC_MorphNodeTo, TARGET_VAL(MSP430::CALLi), 0|OPFL_Chain|OPFL_GlueInput|OPFL_GlueOutput|OPFL_Variadic1,
                      1/*#VTs*/, MVT::i16, 1/*#Ops*/, 2, 
                  // Src: (MSP430call (imm:iPTR):$dst) - Complexity = 6
                  // Dst: (CALLi:i16 (imm:i16):$dst)
/*4699*/        /*SwitchOpcode*/ 12,  TARGET_VAL(ISD::TargetGlobalAddress),// ->4714
/*4702*/          OPC_CheckType, MVT::i16,
/*4704*/          OPC_MoveParent,
/*4705*/          OPC_EmitMergeInputChains1_0,
/*4706*/          OPC_MorphNodeTo, TARGET_VAL(MSP430::CALLi), 0|OPFL_Chain|OPFL_GlueInput|OPFL_GlueOutput|OPFL_Variadic1,
                      1/*#VTs*/, MVT::i16, 1/*#Ops*/, 1, 
                  // Src: (MSP430call (tglobaladdr:i16):$dst) - Complexity = 6
                  // Dst: (CALLi:i16 (tglobaladdr:i16):$dst)
/*4714*/        /*SwitchOpcode*/ 12,  TARGET_VAL(ISD::TargetExternalSymbol),// ->4729
/*4717*/          OPC_CheckType, MVT::i16,
/*4719*/          OPC_MoveParent,
/*4720*/          OPC_EmitMergeInputChains1_0,
/*4721*/          OPC_MorphNodeTo, TARGET_VAL(MSP430::CALLi), 0|OPFL_Chain|OPFL_GlueInput|OPFL_GlueOutput|OPFL_Variadic1,
                      1/*#VTs*/, MVT::i16, 1/*#Ops*/, 1, 
                  // Src: (MSP430call (texternalsym:i16):$dst) - Complexity = 6
                  // Dst: (CALLi:i16 (texternalsym:i16):$dst)
/*4729*/        0, // EndSwitchOpcode
/*4730*/      /*Scope*/ 11, /*->4742*/
/*4731*/        OPC_CheckChild1Type, MVT::i16,
/*4733*/        OPC_EmitMergeInputChains1_0,
/*4734*/        OPC_MorphNodeTo, TARGET_VAL(MSP430::CALLr), 0|OPFL_Chain|OPFL_GlueInput|OPFL_GlueOutput|OPFL_Variadic1,
                    1/*#VTs*/, MVT::i16, 1/*#Ops*/, 1, 
                // Src: (MSP430call GR16:i16:$dst) - Complexity = 3
                // Dst: (CALLr:i16 GR16:i16:$dst)
/*4742*/      0, /*End of Scope*/
/*4743*/    0, /*End of Scope*/
/*4744*/  /*SwitchOpcode*/ 46|128,2/*302*/,  TARGET_VAL(ISD::ADD),// ->5050
/*4748*/    OPC_Scope, 51, /*->4801*/ // 5 children in Scope
/*4750*/      OPC_RecordChild0, // #0 = $src
/*4751*/      OPC_MoveChild, 1,
/*4753*/      OPC_CheckOpcode, TARGET_VAL(ISD::LOAD),
/*4756*/      OPC_RecordMemRef,
/*4757*/      OPC_RecordNode, // #1 = 'ld' chained node
/*4758*/      OPC_CheckFoldableChainNode,
/*4759*/      OPC_RecordChild1, // #2 = $src2
/*4760*/      OPC_CheckPredicate, 0, // Predicate_unindexedload
/*4762*/      OPC_CheckPredicate, 1, // Predicate_load
/*4764*/      OPC_MoveParent,
/*4765*/      OPC_SwitchType /*2 cases */, 15,  MVT::i8,// ->4783
/*4768*/        OPC_CheckComplexPat, /*CP*/0, /*#*/2, // SelectAddr:$src2 #3 #4
/*4771*/        OPC_EmitMergeInputChains1_1,
/*4772*/        OPC_MorphNodeTo, TARGET_VAL(MSP430::ADD8rm), 0|OPFL_Chain|OPFL_MemRefs,
                    2/*#VTs*/, MVT::i8, MVT::i16, 3/*#Ops*/, 0, 3, 4, 
                // Src: (add:i8 GR8:i8:$src, (ld:i8 addr:iPTR:$src2)<<P:Predicate_unindexedload>><<P:Predicate_load>>) - Complexity = 16
                // Dst: (ADD8rm:i8:i16 GR8:i8:$src, addr:i16:$src2)
/*4783*/      /*SwitchType*/ 15,  MVT::i16,// ->4800
/*4785*/        OPC_CheckComplexPat, /*CP*/0, /*#*/2, // SelectAddr:$src2 #3 #4
/*4788*/        OPC_EmitMergeInputChains1_1,
/*4789*/        OPC_MorphNodeTo, TARGET_VAL(MSP430::ADD16rm), 0|OPFL_Chain|OPFL_MemRefs,
                    2/*#VTs*/, MVT::i16, MVT::i16, 3/*#Ops*/, 0, 3, 4, 
                // Src: (add:i16 GR16:i16:$src, (ld:i16 addr:iPTR:$src2)<<P:Predicate_unindexedload>><<P:Predicate_load>>) - Complexity = 16
                // Dst: (ADD16rm:i16:i16 GR16:i16:$src, addr:i16:$src2)
/*4800*/      0, // EndSwitchType
/*4801*/    /*Scope*/ 51, /*->4853*/
/*4802*/      OPC_MoveChild, 0,
/*4804*/      OPC_CheckOpcode, TARGET_VAL(ISD::LOAD),
/*4807*/      OPC_RecordMemRef,
/*4808*/      OPC_RecordNode, // #0 = 'ld' chained node
/*4809*/      OPC_CheckFoldableChainNode,
/*4810*/      OPC_RecordChild1, // #1 = $src2
/*4811*/      OPC_CheckPredicate, 0, // Predicate_unindexedload
/*4813*/      OPC_CheckPredicate, 1, // Predicate_load
/*4815*/      OPC_MoveParent,
/*4816*/      OPC_RecordChild1, // #2 = $src
/*4817*/      OPC_SwitchType /*2 cases */, 15,  MVT::i8,// ->4835
/*4820*/        OPC_CheckComplexPat, /*CP*/0, /*#*/1, // SelectAddr:$src2 #3 #4
/*4823*/        OPC_EmitMergeInputChains1_0,
/*4824*/        OPC_MorphNodeTo, TARGET_VAL(MSP430::ADD8rm), 0|OPFL_Chain|OPFL_MemRefs,
                    2/*#VTs*/, MVT::i8, MVT::i16, 3/*#Ops*/, 2, 3, 4, 
                // Src: (add:i8 (ld:i8 addr:iPTR:$src2)<<P:Predicate_unindexedload>><<P:Predicate_load>>, GR8:i8:$src) - Complexity = 16
                // Dst: (ADD8rm:i8:i16 GR8:i8:$src, addr:i16:$src2)
/*4835*/      /*SwitchType*/ 15,  MVT::i16,// ->4852
/*4837*/        OPC_CheckComplexPat, /*CP*/0, /*#*/1, // SelectAddr:$src2 #3 #4
/*4840*/        OPC_EmitMergeInputChains1_0,
/*4841*/        OPC_MorphNodeTo, TARGET_VAL(MSP430::ADD16rm), 0|OPFL_Chain|OPFL_MemRefs,
                    2/*#VTs*/, MVT::i16, MVT::i16, 3/*#Ops*/, 2, 3, 4, 
                // Src: (add:i16 (ld:i16 addr:iPTR:$src2)<<P:Predicate_unindexedload>><<P:Predicate_load>>, GR16:i16:$src) - Complexity = 16
                // Dst: (ADD16rm:i16:i16 GR16:i16:$src, addr:i16:$src2)
/*4852*/      0, // EndSwitchType
/*4853*/    /*Scope*/ 62, /*->4916*/
/*4854*/      OPC_RecordChild0, // #0 = $src
/*4855*/      OPC_MoveChild, 1,
/*4857*/      OPC_CheckOpcode, TARGET_VAL(MSP430ISD::Wrapper),
/*4860*/      OPC_RecordChild0, // #1 = $src2
/*4861*/      OPC_MoveChild, 0,
/*4863*/      OPC_SwitchOpcode /*3 cases */, 14,  TARGET_VAL(ISD::TargetGlobalAddress),// ->4881
/*4867*/        OPC_MoveParent,
/*4868*/        OPC_MoveParent,
/*4869*/        OPC_CheckType, MVT::i16,
/*4871*/        OPC_MorphNodeTo, TARGET_VAL(MSP430::ADD16ri), 0,
                    2/*#VTs*/, MVT::i16, MVT::i16, 2/*#Ops*/, 0, 1, 
                // Src: (add:i16 GR16:i16:$src, (MSP430Wrapper:i16 (tglobaladdr:i16):$src2)) - Complexity = 9
                // Dst: (ADD16ri:i16:i16 GR16:i16:$src, (tglobaladdr:i16):$src2)
/*4881*/      /*SwitchOpcode*/ 14,  TARGET_VAL(ISD::TargetExternalSymbol),// ->4898
/*4884*/        OPC_MoveParent,
/*4885*/        OPC_MoveParent,
/*4886*/        OPC_CheckType, MVT::i16,
/*4888*/        OPC_MorphNodeTo, TARGET_VAL(MSP430::ADD16ri), 0,
                    2/*#VTs*/, MVT::i16, MVT::i16, 2/*#Ops*/, 0, 1, 
                // Src: (add:i16 GR16:i16:$src, (MSP430Wrapper:i16 (texternalsym:i16):$src2)) - Complexity = 9
                // Dst: (ADD16ri:i16:i16 GR16:i16:$src, (texternalsym:i16):$src2)
/*4898*/      /*SwitchOpcode*/ 14,  TARGET_VAL(ISD::TargetBlockAddress),// ->4915
/*4901*/        OPC_MoveParent,
/*4902*/        OPC_MoveParent,
/*4903*/        OPC_CheckType, MVT::i16,
/*4905*/        OPC_MorphNodeTo, TARGET_VAL(MSP430::ADD16ri), 0,
                    2/*#VTs*/, MVT::i16, MVT::i16, 2/*#Ops*/, 0, 1, 
                // Src: (add:i16 GR16:i16:$src, (MSP430Wrapper:i16 (tblockaddress:i16):$src2)) - Complexity = 9
                // Dst: (ADD16ri:i16:i16 GR16:i16:$src, (tblockaddress:i16):$src2)
/*4915*/      0, // EndSwitchOpcode
/*4916*/    /*Scope*/ 64, /*->4981*/
/*4917*/      OPC_MoveChild, 0,
/*4919*/      OPC_CheckOpcode, TARGET_VAL(MSP430ISD::Wrapper),
/*4922*/      OPC_RecordChild0, // #0 = $src2
/*4923*/      OPC_MoveChild, 0,
/*4925*/      OPC_SwitchOpcode /*3 cases */, 15,  TARGET_VAL(ISD::TargetBlockAddress),// ->4944
/*4929*/        OPC_MoveParent,
/*4930*/        OPC_MoveParent,
/*4931*/        OPC_RecordChild1, // #1 = $src
/*4932*/        OPC_CheckType, MVT::i16,
/*4934*/        OPC_MorphNodeTo, TARGET_VAL(MSP430::ADD16ri), 0,
                    2/*#VTs*/, MVT::i16, MVT::i16, 2/*#Ops*/, 1, 0, 
                // Src: (add:i16 (MSP430Wrapper:i16 (tblockaddress:i16):$src2), GR16:i16:$src) - Complexity = 9
                // Dst: (ADD16ri:i16:i16 GR16:i16:$src, (tblockaddress:i16):$src2)
/*4944*/      /*SwitchOpcode*/ 15,  TARGET_VAL(ISD::TargetGlobalAddress),// ->4962
/*4947*/        OPC_MoveParent,
/*4948*/        OPC_MoveParent,
/*4949*/        OPC_RecordChild1, // #1 = $src
/*4950*/        OPC_CheckType, MVT::i16,
/*4952*/        OPC_MorphNodeTo, TARGET_VAL(MSP430::ADD16ri), 0,
                    2/*#VTs*/, MVT::i16, MVT::i16, 2/*#Ops*/, 1, 0, 
                // Src: (add:i16 (MSP430Wrapper:i16 (tglobaladdr:i16):$src2), GR16:i16:$src) - Complexity = 9
                // Dst: (ADD16ri:i16:i16 GR16:i16:$src, (tglobaladdr:i16):$src2)
/*4962*/      /*SwitchOpcode*/ 15,  TARGET_VAL(ISD::TargetExternalSymbol),// ->4980
/*4965*/        OPC_MoveParent,
/*4966*/        OPC_MoveParent,
/*4967*/        OPC_RecordChild1, // #1 = $src
/*4968*/        OPC_CheckType, MVT::i16,
/*4970*/        OPC_MorphNodeTo, TARGET_VAL(MSP430::ADD16ri), 0,
                    2/*#VTs*/, MVT::i16, MVT::i16, 2/*#Ops*/, 1, 0, 
                // Src: (add:i16 (MSP430Wrapper:i16 (texternalsym:i16):$src2), GR16:i16:$src) - Complexity = 9
                // Dst: (ADD16ri:i16:i16 GR16:i16:$src, (texternalsym:i16):$src2)
/*4980*/      0, // EndSwitchOpcode
/*4981*/    /*Scope*/ 67, /*->5049*/
/*4982*/      OPC_RecordChild0, // #0 = $src
/*4983*/      OPC_RecordChild1, // #1 = $src2
/*4984*/      OPC_Scope, 36, /*->5022*/ // 3 children in Scope
/*4986*/        OPC_MoveChild, 1,
/*4988*/        OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*4991*/        OPC_MoveParent,
/*4992*/        OPC_SwitchType /*2 cases */, 12,  MVT::i8,// ->5007
/*4995*/          OPC_EmitConvertToTarget, 1,
/*4997*/          OPC_MorphNodeTo, TARGET_VAL(MSP430::ADD8ri), 0,
                      2/*#VTs*/, MVT::i8, MVT::i16, 2/*#Ops*/, 0, 2, 
                  // Src: (add:i8 GR8:i8:$src, (imm:i8):$src2) - Complexity = 6
                  // Dst: (ADD8ri:i8:i16 GR8:i8:$src, (imm:i8):$src2)
/*5007*/        /*SwitchType*/ 12,  MVT::i16,// ->5021
/*5009*/          OPC_EmitConvertToTarget, 1,
/*5011*/          OPC_MorphNodeTo, TARGET_VAL(MSP430::ADD16ri), 0,
                      2/*#VTs*/, MVT::i16, MVT::i16, 2/*#Ops*/, 0, 2, 
                  // Src: (add:i16 GR16:i16:$src, (imm:i16):$src2) - Complexity = 6
                  // Dst: (ADD16ri:i16:i16 GR16:i16:$src, (imm:i16):$src2)
/*5021*/        0, // EndSwitchType
/*5022*/      /*Scope*/ 12, /*->5035*/
/*5023*/        OPC_CheckType, MVT::i8,
/*5025*/        OPC_MorphNodeTo, TARGET_VAL(MSP430::ADD8rr), 0,
                    2/*#VTs*/, MVT::i8, MVT::i16, 2/*#Ops*/, 0, 1, 
                // Src: (add:i8 GR8:i8:$src, GR8:i8:$src2) - Complexity = 3
                // Dst: (ADD8rr:i8:i16 GR8:i8:$src, GR8:i8:$src2)
/*5035*/      /*Scope*/ 12, /*->5048*/
/*5036*/        OPC_CheckType, MVT::i16,
/*5038*/        OPC_MorphNodeTo, TARGET_VAL(MSP430::ADD16rr), 0,
                    2/*#VTs*/, MVT::i16, MVT::i16, 2/*#Ops*/, 0, 1, 
                // Src: (add:i16 GR16:i16:$src, GR16:i16:$src2) - Complexity = 3
                // Dst: (ADD16rr:i16:i16 GR16:i16:$src, GR16:i16:$src2)
/*5048*/      0, /*End of Scope*/
/*5049*/    0, /*End of Scope*/
/*5050*/  /*SwitchOpcode*/ 47|128,1/*175*/,  TARGET_VAL(ISD::ADDE),// ->5229
/*5054*/    OPC_CaptureGlueInput,
/*5055*/    OPC_Scope, 51, /*->5108*/ // 3 children in Scope
/*5057*/      OPC_RecordChild0, // #0 = $src
/*5058*/      OPC_MoveChild, 1,
/*5060*/      OPC_CheckOpcode, TARGET_VAL(ISD::LOAD),
/*5063*/      OPC_RecordMemRef,
/*5064*/      OPC_RecordNode, // #1 = 'ld' chained node
/*5065*/      OPC_CheckFoldableChainNode,
/*5066*/      OPC_RecordChild1, // #2 = $src2
/*5067*/      OPC_CheckPredicate, 0, // Predicate_unindexedload
/*5069*/      OPC_CheckPredicate, 1, // Predicate_load
/*5071*/      OPC_MoveParent,
/*5072*/      OPC_SwitchType /*2 cases */, 15,  MVT::i8,// ->5090
/*5075*/        OPC_CheckComplexPat, /*CP*/0, /*#*/2, // SelectAddr:$src2 #3 #4
/*5078*/        OPC_EmitMergeInputChains1_1,
/*5079*/        OPC_MorphNodeTo, TARGET_VAL(MSP430::ADC8rm), 0|OPFL_Chain|OPFL_GlueInput|OPFL_GlueOutput|OPFL_MemRefs,
                    2/*#VTs*/, MVT::i8, MVT::i16, 3/*#Ops*/, 0, 3, 4, 
                // Src: (adde:i8 GR8:i8:$src, (ld:i8 addr:iPTR:$src2)<<P:Predicate_unindexedload>><<P:Predicate_load>>) - Complexity = 16
                // Dst: (ADC8rm:i8:i16 GR8:i8:$src, addr:i16:$src2)
/*5090*/      /*SwitchType*/ 15,  MVT::i16,// ->5107
/*5092*/        OPC_CheckComplexPat, /*CP*/0, /*#*/2, // SelectAddr:$src2 #3 #4
/*5095*/        OPC_EmitMergeInputChains1_1,
/*5096*/        OPC_MorphNodeTo, TARGET_VAL(MSP430::ADC16rm), 0|OPFL_Chain|OPFL_GlueInput|OPFL_GlueOutput|OPFL_MemRefs,
                    2/*#VTs*/, MVT::i16, MVT::i16, 3/*#Ops*/, 0, 3, 4, 
                // Src: (adde:i16 GR16:i16:$src, (ld:i16 addr:iPTR:$src2)<<P:Predicate_unindexedload>><<P:Predicate_load>>) - Complexity = 16
                // Dst: (ADC16rm:i16:i16 GR16:i16:$src, addr:i16:$src2)
/*5107*/      0, // EndSwitchType
/*5108*/    /*Scope*/ 51, /*->5160*/
/*5109*/      OPC_MoveChild, 0,
/*5111*/      OPC_CheckOpcode, TARGET_VAL(ISD::LOAD),
/*5114*/      OPC_RecordMemRef,
/*5115*/      OPC_RecordNode, // #0 = 'ld' chained node
/*5116*/      OPC_CheckFoldableChainNode,
/*5117*/      OPC_RecordChild1, // #1 = $src2
/*5118*/      OPC_CheckPredicate, 0, // Predicate_unindexedload
/*5120*/      OPC_CheckPredicate, 1, // Predicate_load
/*5122*/      OPC_MoveParent,
/*5123*/      OPC_RecordChild1, // #2 = $src
/*5124*/      OPC_SwitchType /*2 cases */, 15,  MVT::i8,// ->5142
/*5127*/        OPC_CheckComplexPat, /*CP*/0, /*#*/1, // SelectAddr:$src2 #3 #4
/*5130*/        OPC_EmitMergeInputChains1_0,
/*5131*/        OPC_MorphNodeTo, TARGET_VAL(MSP430::ADC8rm), 0|OPFL_Chain|OPFL_GlueInput|OPFL_GlueOutput|OPFL_MemRefs,
                    2/*#VTs*/, MVT::i8, MVT::i16, 3/*#Ops*/, 2, 3, 4, 
                // Src: (adde:i8 (ld:i8 addr:iPTR:$src2)<<P:Predicate_unindexedload>><<P:Predicate_load>>, GR8:i8:$src) - Complexity = 16
                // Dst: (ADC8rm:i8:i16 GR8:i8:$src, addr:i16:$src2)
/*5142*/      /*SwitchType*/ 15,  MVT::i16,// ->5159
/*5144*/        OPC_CheckComplexPat, /*CP*/0, /*#*/1, // SelectAddr:$src2 #3 #4
/*5147*/        OPC_EmitMergeInputChains1_0,
/*5148*/        OPC_MorphNodeTo, TARGET_VAL(MSP430::ADC16rm), 0|OPFL_Chain|OPFL_GlueInput|OPFL_GlueOutput|OPFL_MemRefs,
                    2/*#VTs*/, MVT::i16, MVT::i16, 3/*#Ops*/, 2, 3, 4, 
                // Src: (adde:i16 (ld:i16 addr:iPTR:$src2)<<P:Predicate_unindexedload>><<P:Predicate_load>>, GR16:i16:$src) - Complexity = 16
                // Dst: (ADC16rm:i16:i16 GR16:i16:$src, addr:i16:$src2)
/*5159*/      0, // EndSwitchType
/*5160*/    /*Scope*/ 67, /*->5228*/
/*5161*/      OPC_RecordChild0, // #0 = $src
/*5162*/      OPC_RecordChild1, // #1 = $src2
/*5163*/      OPC_Scope, 36, /*->5201*/ // 3 children in Scope
/*5165*/        OPC_MoveChild, 1,
/*5167*/        OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*5170*/        OPC_MoveParent,
/*5171*/        OPC_SwitchType /*2 cases */, 12,  MVT::i8,// ->5186
/*5174*/          OPC_EmitConvertToTarget, 1,
/*5176*/          OPC_MorphNodeTo, TARGET_VAL(MSP430::ADC8ri), 0|OPFL_GlueInput|OPFL_GlueOutput,
                      2/*#VTs*/, MVT::i8, MVT::i16, 2/*#Ops*/, 0, 2, 
                  // Src: (adde:i8 GR8:i8:$src, (imm:i8):$src2) - Complexity = 6
                  // Dst: (ADC8ri:i8:i16 GR8:i8:$src, (imm:i8):$src2)
/*5186*/        /*SwitchType*/ 12,  MVT::i16,// ->5200
/*5188*/          OPC_EmitConvertToTarget, 1,
/*5190*/          OPC_MorphNodeTo, TARGET_VAL(MSP430::ADC16ri), 0|OPFL_GlueInput|OPFL_GlueOutput,
                      2/*#VTs*/, MVT::i16, MVT::i16, 2/*#Ops*/, 0, 2, 
                  // Src: (adde:i16 GR16:i16:$src, (imm:i16):$src2) - Complexity = 6
                  // Dst: (ADC16ri:i16:i16 GR16:i16:$src, (imm:i16):$src2)
/*5200*/        0, // EndSwitchType
/*5201*/      /*Scope*/ 12, /*->5214*/
/*5202*/        OPC_CheckType, MVT::i8,
/*5204*/        OPC_MorphNodeTo, TARGET_VAL(MSP430::ADC8rr), 0|OPFL_GlueInput|OPFL_GlueOutput,
                    2/*#VTs*/, MVT::i8, MVT::i16, 2/*#Ops*/, 0, 1, 
                // Src: (adde:i8 GR8:i8:$src, GR8:i8:$src2) - Complexity = 3
                // Dst: (ADC8rr:i8:i16 GR8:i8:$src, GR8:i8:$src2)
/*5214*/      /*Scope*/ 12, /*->5227*/
/*5215*/        OPC_CheckType, MVT::i16,
/*5217*/        OPC_MorphNodeTo, TARGET_VAL(MSP430::ADC16rr), 0|OPFL_GlueInput|OPFL_GlueOutput,
                    2/*#VTs*/, MVT::i16, MVT::i16, 2/*#Ops*/, 0, 1, 
                // Src: (adde:i16 GR16:i16:$src, GR16:i16:$src2) - Complexity = 3
                // Dst: (ADC16rr:i16:i16 GR16:i16:$src, GR16:i16:$src2)
/*5227*/      0, /*End of Scope*/
/*5228*/    0, /*End of Scope*/
/*5229*/  /*SwitchOpcode*/ 46|128,1/*174*/,  TARGET_VAL(ISD::OR),// ->5407
/*5233*/    OPC_Scope, 51, /*->5286*/ // 3 children in Scope
/*5235*/      OPC_RecordChild0, // #0 = $src
/*5236*/      OPC_MoveChild, 1,
/*5238*/      OPC_CheckOpcode, TARGET_VAL(ISD::LOAD),
/*5241*/      OPC_RecordMemRef,
/*5242*/      OPC_RecordNode, // #1 = 'ld' chained node
/*5243*/      OPC_CheckFoldableChainNode,
/*5244*/      OPC_RecordChild1, // #2 = $src2
/*5245*/      OPC_CheckPredicate, 0, // Predicate_unindexedload
/*5247*/      OPC_CheckPredicate, 1, // Predicate_load
/*5249*/      OPC_MoveParent,
/*5250*/      OPC_SwitchType /*2 cases */, 15,  MVT::i8,// ->5268
/*5253*/        OPC_CheckComplexPat, /*CP*/0, /*#*/2, // SelectAddr:$src2 #3 #4
/*5256*/        OPC_EmitMergeInputChains1_1,
/*5257*/        OPC_MorphNodeTo, TARGET_VAL(MSP430::OR8rm), 0|OPFL_Chain|OPFL_MemRefs,
                    2/*#VTs*/, MVT::i8, MVT::i16, 3/*#Ops*/, 0, 3, 4, 
                // Src: (or:i8 GR8:i8:$src, (ld:i8 addr:iPTR:$src2)<<P:Predicate_unindexedload>><<P:Predicate_load>>) - Complexity = 16
                // Dst: (OR8rm:i8:i16 GR8:i8:$src, addr:i16:$src2)
/*5268*/      /*SwitchType*/ 15,  MVT::i16,// ->5285
/*5270*/        OPC_CheckComplexPat, /*CP*/0, /*#*/2, // SelectAddr:$src2 #3 #4
/*5273*/        OPC_EmitMergeInputChains1_1,
/*5274*/        OPC_MorphNodeTo, TARGET_VAL(MSP430::OR16rm), 0|OPFL_Chain|OPFL_MemRefs,
                    2/*#VTs*/, MVT::i16, MVT::i16, 3/*#Ops*/, 0, 3, 4, 
                // Src: (or:i16 GR16:i16:$src, (ld:i16 addr:iPTR:$src2)<<P:Predicate_unindexedload>><<P:Predicate_load>>) - Complexity = 16
                // Dst: (OR16rm:i16:i16 GR16:i16:$src, addr:i16:$src2)
/*5285*/      0, // EndSwitchType
/*5286*/    /*Scope*/ 51, /*->5338*/
/*5287*/      OPC_MoveChild, 0,
/*5289*/      OPC_CheckOpcode, TARGET_VAL(ISD::LOAD),
/*5292*/      OPC_RecordMemRef,
/*5293*/      OPC_RecordNode, // #0 = 'ld' chained node
/*5294*/      OPC_CheckFoldableChainNode,
/*5295*/      OPC_RecordChild1, // #1 = $src2
/*5296*/      OPC_CheckPredicate, 0, // Predicate_unindexedload
/*5298*/      OPC_CheckPredicate, 1, // Predicate_load
/*5300*/      OPC_MoveParent,
/*5301*/      OPC_RecordChild1, // #2 = $src
/*5302*/      OPC_SwitchType /*2 cases */, 15,  MVT::i8,// ->5320
/*5305*/        OPC_CheckComplexPat, /*CP*/0, /*#*/1, // SelectAddr:$src2 #3 #4
/*5308*/        OPC_EmitMergeInputChains1_0,
/*5309*/        OPC_MorphNodeTo, TARGET_VAL(MSP430::OR8rm), 0|OPFL_Chain|OPFL_MemRefs,
                    2/*#VTs*/, MVT::i8, MVT::i16, 3/*#Ops*/, 2, 3, 4, 
                // Src: (or:i8 (ld:i8 addr:iPTR:$src2)<<P:Predicate_unindexedload>><<P:Predicate_load>>, GR8:i8:$src) - Complexity = 16
                // Dst: (OR8rm:i8:i16 GR8:i8:$src, addr:i16:$src2)
/*5320*/      /*SwitchType*/ 15,  MVT::i16,// ->5337
/*5322*/        OPC_CheckComplexPat, /*CP*/0, /*#*/1, // SelectAddr:$src2 #3 #4
/*5325*/        OPC_EmitMergeInputChains1_0,
/*5326*/        OPC_MorphNodeTo, TARGET_VAL(MSP430::OR16rm), 0|OPFL_Chain|OPFL_MemRefs,
                    2/*#VTs*/, MVT::i16, MVT::i16, 3/*#Ops*/, 2, 3, 4, 
                // Src: (or:i16 (ld:i16 addr:iPTR:$src2)<<P:Predicate_unindexedload>><<P:Predicate_load>>, GR16:i16:$src) - Complexity = 16
                // Dst: (OR16rm:i16:i16 GR16:i16:$src, addr:i16:$src2)
/*5337*/      0, // EndSwitchType
/*5338*/    /*Scope*/ 67, /*->5406*/
/*5339*/      OPC_RecordChild0, // #0 = $src
/*5340*/      OPC_RecordChild1, // #1 = $src2
/*5341*/      OPC_Scope, 36, /*->5379*/ // 3 children in Scope
/*5343*/        OPC_MoveChild, 1,
/*5345*/        OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*5348*/        OPC_MoveParent,
/*5349*/        OPC_SwitchType /*2 cases */, 12,  MVT::i8,// ->5364
/*5352*/          OPC_EmitConvertToTarget, 1,
/*5354*/          OPC_MorphNodeTo, TARGET_VAL(MSP430::OR8ri), 0,
                      2/*#VTs*/, MVT::i8, MVT::i16, 2/*#Ops*/, 0, 2, 
                  // Src: (or:i8 GR8:i8:$src, (imm:i8):$src2) - Complexity = 6
                  // Dst: (OR8ri:i8:i16 GR8:i8:$src, (imm:i8):$src2)
/*5364*/        /*SwitchType*/ 12,  MVT::i16,// ->5378
/*5366*/          OPC_EmitConvertToTarget, 1,
/*5368*/          OPC_MorphNodeTo, TARGET_VAL(MSP430::OR16ri), 0,
                      2/*#VTs*/, MVT::i16, MVT::i16, 2/*#Ops*/, 0, 2, 
                  // Src: (or:i16 GR16:i16:$src, (imm:i16):$src2) - Complexity = 6
                  // Dst: (OR16ri:i16:i16 GR16:i16:$src, (imm:i16):$src2)
/*5378*/        0, // EndSwitchType
/*5379*/      /*Scope*/ 12, /*->5392*/
/*5380*/        OPC_CheckType, MVT::i8,
/*5382*/        OPC_MorphNodeTo, TARGET_VAL(MSP430::OR8rr), 0,
                    2/*#VTs*/, MVT::i8, MVT::i16, 2/*#Ops*/, 0, 1, 
                // Src: (or:i8 GR8:i8:$src, GR8:i8:$src2) - Complexity = 3
                // Dst: (OR8rr:i8:i16 GR8:i8:$src, GR8:i8:$src2)
/*5392*/      /*Scope*/ 12, /*->5405*/
/*5393*/        OPC_CheckType, MVT::i16,
/*5395*/        OPC_MorphNodeTo, TARGET_VAL(MSP430::OR16rr), 0,
                    2/*#VTs*/, MVT::i16, MVT::i16, 2/*#Ops*/, 0, 1, 
                // Src: (or:i16 GR16:i16:$src, GR16:i16:$src2) - Complexity = 3
                // Dst: (OR16rr:i16:i16 GR16:i16:$src, GR16:i16:$src2)
/*5405*/      0, /*End of Scope*/
/*5406*/    0, /*End of Scope*/
/*5407*/  /*SwitchOpcode*/ 46|128,1/*174*/,  TARGET_VAL(ISD::XOR),// ->5585
/*5411*/    OPC_Scope, 51, /*->5464*/ // 3 children in Scope
/*5413*/      OPC_RecordChild0, // #0 = $src
/*5414*/      OPC_MoveChild, 1,
/*5416*/      OPC_CheckOpcode, TARGET_VAL(ISD::LOAD),
/*5419*/      OPC_RecordMemRef,
/*5420*/      OPC_RecordNode, // #1 = 'ld' chained node
/*5421*/      OPC_CheckFoldableChainNode,
/*5422*/      OPC_RecordChild1, // #2 = $src2
/*5423*/      OPC_CheckPredicate, 0, // Predicate_unindexedload
/*5425*/      OPC_CheckPredicate, 1, // Predicate_load
/*5427*/      OPC_MoveParent,
/*5428*/      OPC_SwitchType /*2 cases */, 15,  MVT::i8,// ->5446
/*5431*/        OPC_CheckComplexPat, /*CP*/0, /*#*/2, // SelectAddr:$src2 #3 #4
/*5434*/        OPC_EmitMergeInputChains1_1,
/*5435*/        OPC_MorphNodeTo, TARGET_VAL(MSP430::XOR8rm), 0|OPFL_Chain|OPFL_MemRefs,
                    2/*#VTs*/, MVT::i8, MVT::i16, 3/*#Ops*/, 0, 3, 4, 
                // Src: (xor:i8 GR8:i8:$src, (ld:i8 addr:iPTR:$src2)<<P:Predicate_unindexedload>><<P:Predicate_load>>) - Complexity = 16
                // Dst: (XOR8rm:i8:i16 GR8:i8:$src, addr:i16:$src2)
/*5446*/      /*SwitchType*/ 15,  MVT::i16,// ->5463
/*5448*/        OPC_CheckComplexPat, /*CP*/0, /*#*/2, // SelectAddr:$src2 #3 #4
/*5451*/        OPC_EmitMergeInputChains1_1,
/*5452*/        OPC_MorphNodeTo, TARGET_VAL(MSP430::XOR16rm), 0|OPFL_Chain|OPFL_MemRefs,
                    2/*#VTs*/, MVT::i16, MVT::i16, 3/*#Ops*/, 0, 3, 4, 
                // Src: (xor:i16 GR16:i16:$src, (ld:i16 addr:iPTR:$src2)<<P:Predicate_unindexedload>><<P:Predicate_load>>) - Complexity = 16
                // Dst: (XOR16rm:i16:i16 GR16:i16:$src, addr:i16:$src2)
/*5463*/      0, // EndSwitchType
/*5464*/    /*Scope*/ 51, /*->5516*/
/*5465*/      OPC_MoveChild, 0,
/*5467*/      OPC_CheckOpcode, TARGET_VAL(ISD::LOAD),
/*5470*/      OPC_RecordMemRef,
/*5471*/      OPC_RecordNode, // #0 = 'ld' chained node
/*5472*/      OPC_CheckFoldableChainNode,
/*5473*/      OPC_RecordChild1, // #1 = $src2
/*5474*/      OPC_CheckPredicate, 0, // Predicate_unindexedload
/*5476*/      OPC_CheckPredicate, 1, // Predicate_load
/*5478*/      OPC_MoveParent,
/*5479*/      OPC_RecordChild1, // #2 = $src
/*5480*/      OPC_SwitchType /*2 cases */, 15,  MVT::i8,// ->5498
/*5483*/        OPC_CheckComplexPat, /*CP*/0, /*#*/1, // SelectAddr:$src2 #3 #4
/*5486*/        OPC_EmitMergeInputChains1_0,
/*5487*/        OPC_MorphNodeTo, TARGET_VAL(MSP430::XOR8rm), 0|OPFL_Chain|OPFL_MemRefs,
                    2/*#VTs*/, MVT::i8, MVT::i16, 3/*#Ops*/, 2, 3, 4, 
                // Src: (xor:i8 (ld:i8 addr:iPTR:$src2)<<P:Predicate_unindexedload>><<P:Predicate_load>>, GR8:i8:$src) - Complexity = 16
                // Dst: (XOR8rm:i8:i16 GR8:i8:$src, addr:i16:$src2)
/*5498*/      /*SwitchType*/ 15,  MVT::i16,// ->5515
/*5500*/        OPC_CheckComplexPat, /*CP*/0, /*#*/1, // SelectAddr:$src2 #3 #4
/*5503*/        OPC_EmitMergeInputChains1_0,
/*5504*/        OPC_MorphNodeTo, TARGET_VAL(MSP430::XOR16rm), 0|OPFL_Chain|OPFL_MemRefs,
                    2/*#VTs*/, MVT::i16, MVT::i16, 3/*#Ops*/, 2, 3, 4, 
                // Src: (xor:i16 (ld:i16 addr:iPTR:$src2)<<P:Predicate_unindexedload>><<P:Predicate_load>>, GR16:i16:$src) - Complexity = 16
                // Dst: (XOR16rm:i16:i16 GR16:i16:$src, addr:i16:$src2)
/*5515*/      0, // EndSwitchType
/*5516*/    /*Scope*/ 67, /*->5584*/
/*5517*/      OPC_RecordChild0, // #0 = $src
/*5518*/      OPC_RecordChild1, // #1 = $src2
/*5519*/      OPC_Scope, 36, /*->5557*/ // 3 children in Scope
/*5521*/        OPC_MoveChild, 1,
/*5523*/        OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*5526*/        OPC_MoveParent,
/*5527*/        OPC_SwitchType /*2 cases */, 12,  MVT::i8,// ->5542
/*5530*/          OPC_EmitConvertToTarget, 1,
/*5532*/          OPC_MorphNodeTo, TARGET_VAL(MSP430::XOR8ri), 0,
                      2/*#VTs*/, MVT::i8, MVT::i16, 2/*#Ops*/, 0, 2, 
                  // Src: (xor:i8 GR8:i8:$src, (imm:i8):$src2) - Complexity = 6
                  // Dst: (XOR8ri:i8:i16 GR8:i8:$src, (imm:i8):$src2)
/*5542*/        /*SwitchType*/ 12,  MVT::i16,// ->5556
/*5544*/          OPC_EmitConvertToTarget, 1,
/*5546*/          OPC_MorphNodeTo, TARGET_VAL(MSP430::XOR16ri), 0,
                      2/*#VTs*/, MVT::i16, MVT::i16, 2/*#Ops*/, 0, 2, 
                  // Src: (xor:i16 GR16:i16:$src, (imm:i16):$src2) - Complexity = 6
                  // Dst: (XOR16ri:i16:i16 GR16:i16:$src, (imm:i16):$src2)
/*5556*/        0, // EndSwitchType
/*5557*/      /*Scope*/ 12, /*->5570*/
/*5558*/        OPC_CheckType, MVT::i8,
/*5560*/        OPC_MorphNodeTo, TARGET_VAL(MSP430::XOR8rr), 0,
                    2/*#VTs*/, MVT::i8, MVT::i16, 2/*#Ops*/, 0, 1, 
                // Src: (xor:i8 GR8:i8:$src, GR8:i8:$src2) - Complexity = 3
                // Dst: (XOR8rr:i8:i16 GR8:i8:$src, GR8:i8:$src2)
/*5570*/      /*Scope*/ 12, /*->5583*/
/*5571*/        OPC_CheckType, MVT::i16,
/*5573*/        OPC_MorphNodeTo, TARGET_VAL(MSP430::XOR16rr), 0,
                    2/*#VTs*/, MVT::i16, MVT::i16, 2/*#Ops*/, 0, 1, 
                // Src: (xor:i16 GR16:i16:$src, GR16:i16:$src2) - Complexity = 3
                // Dst: (XOR16rr:i16:i16 GR16:i16:$src, GR16:i16:$src2)
/*5583*/      0, /*End of Scope*/
/*5584*/    0, /*End of Scope*/
/*5585*/  /*SwitchOpcode*/ 121,  TARGET_VAL(ISD::SUB),// ->5709
/*5588*/    OPC_RecordChild0, // #0 = $src
/*5589*/    OPC_Scope, 50, /*->5641*/ // 2 children in Scope
/*5591*/      OPC_MoveChild, 1,
/*5593*/      OPC_CheckOpcode, TARGET_VAL(ISD::LOAD),
/*5596*/      OPC_RecordMemRef,
/*5597*/      OPC_RecordNode, // #1 = 'ld' chained node
/*5598*/      OPC_CheckFoldableChainNode,
/*5599*/      OPC_RecordChild1, // #2 = $src2
/*5600*/      OPC_CheckPredicate, 0, // Predicate_unindexedload
/*5602*/      OPC_CheckPredicate, 1, // Predicate_load
/*5604*/      OPC_MoveParent,
/*5605*/      OPC_SwitchType /*2 cases */, 15,  MVT::i8,// ->5623
/*5608*/        OPC_CheckComplexPat, /*CP*/0, /*#*/2, // SelectAddr:$src2 #3 #4
/*5611*/        OPC_EmitMergeInputChains1_1,
/*5612*/        OPC_MorphNodeTo, TARGET_VAL(MSP430::SUB8rm), 0|OPFL_Chain|OPFL_MemRefs,
                    2/*#VTs*/, MVT::i8, MVT::i16, 3/*#Ops*/, 0, 3, 4, 
                // Src: (sub:i8 GR8:i8:$src, (ld:i8 addr:iPTR:$src2)<<P:Predicate_unindexedload>><<P:Predicate_load>>) - Complexity = 16
                // Dst: (SUB8rm:i8:i16 GR8:i8:$src, addr:i16:$src2)
/*5623*/      /*SwitchType*/ 15,  MVT::i16,// ->5640
/*5625*/        OPC_CheckComplexPat, /*CP*/0, /*#*/2, // SelectAddr:$src2 #3 #4
/*5628*/        OPC_EmitMergeInputChains1_1,
/*5629*/        OPC_MorphNodeTo, TARGET_VAL(MSP430::SUB16rm), 0|OPFL_Chain|OPFL_MemRefs,
                    2/*#VTs*/, MVT::i16, MVT::i16, 3/*#Ops*/, 0, 3, 4, 
                // Src: (sub:i16 GR16:i16:$src, (ld:i16 addr:iPTR:$src2)<<P:Predicate_unindexedload>><<P:Predicate_load>>) - Complexity = 16
                // Dst: (SUB16rm:i16:i16 GR16:i16:$src, addr:i16:$src2)
/*5640*/      0, // EndSwitchType
/*5641*/    /*Scope*/ 66, /*->5708*/
/*5642*/      OPC_RecordChild1, // #1 = $src2
/*5643*/      OPC_Scope, 36, /*->5681*/ // 3 children in Scope
/*5645*/        OPC_MoveChild, 1,
/*5647*/        OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*5650*/        OPC_MoveParent,
/*5651*/        OPC_SwitchType /*2 cases */, 12,  MVT::i8,// ->5666
/*5654*/          OPC_EmitConvertToTarget, 1,
/*5656*/          OPC_MorphNodeTo, TARGET_VAL(MSP430::SUB8ri), 0,
                      2/*#VTs*/, MVT::i8, MVT::i16, 2/*#Ops*/, 0, 2, 
                  // Src: (sub:i8 GR8:i8:$src, (imm:i8):$src2) - Complexity = 6
                  // Dst: (SUB8ri:i8:i16 GR8:i8:$src, (imm:i8):$src2)
/*5666*/        /*SwitchType*/ 12,  MVT::i16,// ->5680
/*5668*/          OPC_EmitConvertToTarget, 1,
/*5670*/          OPC_MorphNodeTo, TARGET_VAL(MSP430::SUB16ri), 0,
                      2/*#VTs*/, MVT::i16, MVT::i16, 2/*#Ops*/, 0, 2, 
                  // Src: (sub:i16 GR16:i16:$src, (imm:i16):$src2) - Complexity = 6
                  // Dst: (SUB16ri:i16:i16 GR16:i16:$src, (imm:i16):$src2)
/*5680*/        0, // EndSwitchType
/*5681*/      /*Scope*/ 12, /*->5694*/
/*5682*/        OPC_CheckType, MVT::i8,
/*5684*/        OPC_MorphNodeTo, TARGET_VAL(MSP430::SUB8rr), 0,
                    2/*#VTs*/, MVT::i8, MVT::i16, 2/*#Ops*/, 0, 1, 
                // Src: (sub:i8 GR8:i8:$src, GR8:i8:$src2) - Complexity = 3
                // Dst: (SUB8rr:i8:i16 GR8:i8:$src, GR8:i8:$src2)
/*5694*/      /*Scope*/ 12, /*->5707*/
/*5695*/        OPC_CheckType, MVT::i16,
/*5697*/        OPC_MorphNodeTo, TARGET_VAL(MSP430::SUB16rr), 0,
                    2/*#VTs*/, MVT::i16, MVT::i16, 2/*#Ops*/, 0, 1, 
                // Src: (sub:i16 GR16:i16:$src, GR16:i16:$src2) - Complexity = 3
                // Dst: (SUB16rr:i16:i16 GR16:i16:$src, GR16:i16:$src2)
/*5707*/      0, /*End of Scope*/
/*5708*/    0, /*End of Scope*/
/*5709*/  /*SwitchOpcode*/ 122,  TARGET_VAL(ISD::SUBE),// ->5834
/*5712*/    OPC_CaptureGlueInput,
/*5713*/    OPC_RecordChild0, // #0 = $src
/*5714*/    OPC_Scope, 50, /*->5766*/ // 2 children in Scope
/*5716*/      OPC_MoveChild, 1,
/*5718*/      OPC_CheckOpcode, TARGET_VAL(ISD::LOAD),
/*5721*/      OPC_RecordMemRef,
/*5722*/      OPC_RecordNode, // #1 = 'ld' chained node
/*5723*/      OPC_CheckFoldableChainNode,
/*5724*/      OPC_RecordChild1, // #2 = $src2
/*5725*/      OPC_CheckPredicate, 0, // Predicate_unindexedload
/*5727*/      OPC_CheckPredicate, 1, // Predicate_load
/*5729*/      OPC_MoveParent,
/*5730*/      OPC_SwitchType /*2 cases */, 15,  MVT::i8,// ->5748
/*5733*/        OPC_CheckComplexPat, /*CP*/0, /*#*/2, // SelectAddr:$src2 #3 #4
/*5736*/        OPC_EmitMergeInputChains1_1,
/*5737*/        OPC_MorphNodeTo, TARGET_VAL(MSP430::SBC8rm), 0|OPFL_Chain|OPFL_GlueInput|OPFL_GlueOutput|OPFL_MemRefs,
                    2/*#VTs*/, MVT::i8, MVT::i16, 3/*#Ops*/, 0, 3, 4, 
                // Src: (sube:i8 GR8:i8:$src, (ld:i8 addr:iPTR:$src2)<<P:Predicate_unindexedload>><<P:Predicate_load>>) - Complexity = 16
                // Dst: (SBC8rm:i8:i16 GR8:i8:$src, addr:i16:$src2)
/*5748*/      /*SwitchType*/ 15,  MVT::i16,// ->5765
/*5750*/        OPC_CheckComplexPat, /*CP*/0, /*#*/2, // SelectAddr:$src2 #3 #4
/*5753*/        OPC_EmitMergeInputChains1_1,
/*5754*/        OPC_MorphNodeTo, TARGET_VAL(MSP430::SBC16rm), 0|OPFL_Chain|OPFL_GlueInput|OPFL_GlueOutput|OPFL_MemRefs,
                    2/*#VTs*/, MVT::i16, MVT::i16, 3/*#Ops*/, 0, 3, 4, 
                // Src: (sube:i16 GR16:i16:$src, (ld:i16 addr:iPTR:$src2)<<P:Predicate_unindexedload>><<P:Predicate_load>>) - Complexity = 16
                // Dst: (SBC16rm:i16:i16 GR16:i16:$src, addr:i16:$src2)
/*5765*/      0, // EndSwitchType
/*5766*/    /*Scope*/ 66, /*->5833*/
/*5767*/      OPC_RecordChild1, // #1 = $src2
/*5768*/      OPC_Scope, 36, /*->5806*/ // 3 children in Scope
/*5770*/        OPC_MoveChild, 1,
/*5772*/        OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*5775*/        OPC_MoveParent,
/*5776*/        OPC_SwitchType /*2 cases */, 12,  MVT::i8,// ->5791
/*5779*/          OPC_EmitConvertToTarget, 1,
/*5781*/          OPC_MorphNodeTo, TARGET_VAL(MSP430::SBC8ri), 0|OPFL_GlueInput|OPFL_GlueOutput,
                      2/*#VTs*/, MVT::i8, MVT::i16, 2/*#Ops*/, 0, 2, 
                  // Src: (sube:i8 GR8:i8:$src, (imm:i8):$src2) - Complexity = 6
                  // Dst: (SBC8ri:i8:i16 GR8:i8:$src, (imm:i8):$src2)
/*5791*/        /*SwitchType*/ 12,  MVT::i16,// ->5805
/*5793*/          OPC_EmitConvertToTarget, 1,
/*5795*/          OPC_MorphNodeTo, TARGET_VAL(MSP430::SBC16ri), 0|OPFL_GlueInput|OPFL_GlueOutput,
                      2/*#VTs*/, MVT::i16, MVT::i16, 2/*#Ops*/, 0, 2, 
                  // Src: (sube:i16 GR16:i16:$src, (imm:i16):$src2) - Complexity = 6
                  // Dst: (SBC16ri:i16:i16 GR16:i16:$src, (imm:i16):$src2)
/*5805*/        0, // EndSwitchType
/*5806*/      /*Scope*/ 12, /*->5819*/
/*5807*/        OPC_CheckType, MVT::i8,
/*5809*/        OPC_MorphNodeTo, TARGET_VAL(MSP430::SBC8rr), 0|OPFL_GlueInput|OPFL_GlueOutput,
                    2/*#VTs*/, MVT::i8, MVT::i16, 2/*#Ops*/, 0, 1, 
                // Src: (sube:i8 GR8:i8:$src, GR8:i8:$src2) - Complexity = 3
                // Dst: (SBC8rr:i8:i16 GR8:i8:$src, GR8:i8:$src2)
/*5819*/      /*Scope*/ 12, /*->5832*/
/*5820*/        OPC_CheckType, MVT::i16,
/*5822*/        OPC_MorphNodeTo, TARGET_VAL(MSP430::SBC16rr), 0|OPFL_GlueInput|OPFL_GlueOutput,
                    2/*#VTs*/, MVT::i16, MVT::i16, 2/*#Ops*/, 0, 1, 
                // Src: (sube:i16 GR16:i16:$src, GR16:i16:$src2) - Complexity = 3
                // Dst: (SBC16rr:i16:i16 GR16:i16:$src, GR16:i16:$src2)
/*5832*/      0, /*End of Scope*/
/*5833*/    0, /*End of Scope*/
/*5834*/  /*SwitchOpcode*/ 46|128,1/*174*/,  TARGET_VAL(ISD::ADDC),// ->6012
/*5838*/    OPC_Scope, 51, /*->5891*/ // 3 children in Scope
/*5840*/      OPC_RecordChild0, // #0 = $src
/*5841*/      OPC_MoveChild, 1,
/*5843*/      OPC_CheckOpcode, TARGET_VAL(ISD::LOAD),
/*5846*/      OPC_RecordMemRef,
/*5847*/      OPC_RecordNode, // #1 = 'ld' chained node
/*5848*/      OPC_CheckFoldableChainNode,
/*5849*/      OPC_RecordChild1, // #2 = $src2
/*5850*/      OPC_CheckPredicate, 0, // Predicate_unindexedload
/*5852*/      OPC_CheckPredicate, 1, // Predicate_load
/*5854*/      OPC_MoveParent,
/*5855*/      OPC_SwitchType /*2 cases */, 15,  MVT::i16,// ->5873
/*5858*/        OPC_CheckComplexPat, /*CP*/0, /*#*/2, // SelectAddr:$src2 #3 #4
/*5861*/        OPC_EmitMergeInputChains1_1,
/*5862*/        OPC_MorphNodeTo, TARGET_VAL(MSP430::ADD16rm), 0|OPFL_Chain|OPFL_GlueOutput|OPFL_MemRefs,
                    2/*#VTs*/, MVT::i16, MVT::i16, 3/*#Ops*/, 0, 3, 4, 
                // Src: (addc:i16 GR16:i16:$src, (ld:i16 addr:iPTR:$src2)<<P:Predicate_unindexedload>><<P:Predicate_load>>) - Complexity = 16
                // Dst: (ADD16rm:i16:i16 GR16:i16:$src, addr:i16:$src2)
/*5873*/      /*SwitchType*/ 15,  MVT::i8,// ->5890
/*5875*/        OPC_CheckComplexPat, /*CP*/0, /*#*/2, // SelectAddr:$src2 #3 #4
/*5878*/        OPC_EmitMergeInputChains1_1,
/*5879*/        OPC_MorphNodeTo, TARGET_VAL(MSP430::ADD8rm), 0|OPFL_Chain|OPFL_GlueOutput|OPFL_MemRefs,
                    2/*#VTs*/, MVT::i8, MVT::i16, 3/*#Ops*/, 0, 3, 4, 
                // Src: (addc:i8 GR8:i8:$src, (ld:i8 addr:iPTR:$src2)<<P:Predicate_unindexedload>><<P:Predicate_load>>) - Complexity = 16
                // Dst: (ADD8rm:i8:i16 GR8:i8:$src, addr:i16:$src2)
/*5890*/      0, // EndSwitchType
/*5891*/    /*Scope*/ 51, /*->5943*/
/*5892*/      OPC_MoveChild, 0,
/*5894*/      OPC_CheckOpcode, TARGET_VAL(ISD::LOAD),
/*5897*/      OPC_RecordMemRef,
/*5898*/      OPC_RecordNode, // #0 = 'ld' chained node
/*5899*/      OPC_CheckFoldableChainNode,
/*5900*/      OPC_RecordChild1, // #1 = $src2
/*5901*/      OPC_CheckPredicate, 0, // Predicate_unindexedload
/*5903*/      OPC_CheckPredicate, 1, // Predicate_load
/*5905*/      OPC_MoveParent,
/*5906*/      OPC_RecordChild1, // #2 = $src
/*5907*/      OPC_SwitchType /*2 cases */, 15,  MVT::i16,// ->5925
/*5910*/        OPC_CheckComplexPat, /*CP*/0, /*#*/1, // SelectAddr:$src2 #3 #4
/*5913*/        OPC_EmitMergeInputChains1_0,
/*5914*/        OPC_MorphNodeTo, TARGET_VAL(MSP430::ADD16rm), 0|OPFL_Chain|OPFL_GlueOutput|OPFL_MemRefs,
                    2/*#VTs*/, MVT::i16, MVT::i16, 3/*#Ops*/, 2, 3, 4, 
                // Src: (addc:i16 (ld:i16 addr:iPTR:$src2)<<P:Predicate_unindexedload>><<P:Predicate_load>>, GR16:i16:$src) - Complexity = 16
                // Dst: (ADD16rm:i16:i16 GR16:i16:$src, addr:i16:$src2)
/*5925*/      /*SwitchType*/ 15,  MVT::i8,// ->5942
/*5927*/        OPC_CheckComplexPat, /*CP*/0, /*#*/1, // SelectAddr:$src2 #3 #4
/*5930*/        OPC_EmitMergeInputChains1_0,
/*5931*/        OPC_MorphNodeTo, TARGET_VAL(MSP430::ADD8rm), 0|OPFL_Chain|OPFL_GlueOutput|OPFL_MemRefs,
                    2/*#VTs*/, MVT::i8, MVT::i16, 3/*#Ops*/, 2, 3, 4, 
                // Src: (addc:i8 (ld:i8 addr:iPTR:$src2)<<P:Predicate_unindexedload>><<P:Predicate_load>>, GR8:i8:$src) - Complexity = 16
                // Dst: (ADD8rm:i8:i16 GR8:i8:$src, addr:i16:$src2)
/*5942*/      0, // EndSwitchType
/*5943*/    /*Scope*/ 67, /*->6011*/
/*5944*/      OPC_RecordChild0, // #0 = $src
/*5945*/      OPC_RecordChild1, // #1 = $src2
/*5946*/      OPC_Scope, 36, /*->5984*/ // 3 children in Scope
/*5948*/        OPC_MoveChild, 1,
/*5950*/        OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*5953*/        OPC_MoveParent,
/*5954*/        OPC_SwitchType /*2 cases */, 12,  MVT::i16,// ->5969
/*5957*/          OPC_EmitConvertToTarget, 1,
/*5959*/          OPC_MorphNodeTo, TARGET_VAL(MSP430::ADD16ri), 0|OPFL_GlueOutput,
                      2/*#VTs*/, MVT::i16, MVT::i16, 2/*#Ops*/, 0, 2, 
                  // Src: (addc:i16 GR16:i16:$src, (imm:i16):$src2) - Complexity = 6
                  // Dst: (ADD16ri:i16:i16 GR16:i16:$src, (imm:i16):$src2)
/*5969*/        /*SwitchType*/ 12,  MVT::i8,// ->5983
/*5971*/          OPC_EmitConvertToTarget, 1,
/*5973*/          OPC_MorphNodeTo, TARGET_VAL(MSP430::ADD8ri), 0|OPFL_GlueOutput,
                      2/*#VTs*/, MVT::i8, MVT::i16, 2/*#Ops*/, 0, 2, 
                  // Src: (addc:i8 GR8:i8:$src, (imm:i8):$src2) - Complexity = 6
                  // Dst: (ADD8ri:i8:i16 GR8:i8:$src, (imm:i8):$src2)
/*5983*/        0, // EndSwitchType
/*5984*/      /*Scope*/ 12, /*->5997*/
/*5985*/        OPC_CheckType, MVT::i16,
/*5987*/        OPC_MorphNodeTo, TARGET_VAL(MSP430::ADD16rr), 0|OPFL_GlueOutput,
                    2/*#VTs*/, MVT::i16, MVT::i16, 2/*#Ops*/, 0, 1, 
                // Src: (addc:i16 GR16:i16:$src, GR16:i16:$src2) - Complexity = 3
                // Dst: (ADD16rr:i16:i16 GR16:i16:$src, GR16:i16:$src2)
/*5997*/      /*Scope*/ 12, /*->6010*/
/*5998*/        OPC_CheckType, MVT::i8,
/*6000*/        OPC_MorphNodeTo, TARGET_VAL(MSP430::ADD8rr), 0|OPFL_GlueOutput,
                    2/*#VTs*/, MVT::i8, MVT::i16, 2/*#Ops*/, 0, 1, 
                // Src: (addc:i8 GR8:i8:$src, GR8:i8:$src2) - Complexity = 3
                // Dst: (ADD8rr:i8:i16 GR8:i8:$src, GR8:i8:$src2)
/*6010*/      0, /*End of Scope*/
/*6011*/    0, /*End of Scope*/
/*6012*/  /*SwitchOpcode*/ 121,  TARGET_VAL(ISD::SUBC),// ->6136
/*6015*/    OPC_RecordChild0, // #0 = $src
/*6016*/    OPC_Scope, 50, /*->6068*/ // 2 children in Scope
/*6018*/      OPC_MoveChild, 1,
/*6020*/      OPC_CheckOpcode, TARGET_VAL(ISD::LOAD),
/*6023*/      OPC_RecordMemRef,
/*6024*/      OPC_RecordNode, // #1 = 'ld' chained node
/*6025*/      OPC_CheckFoldableChainNode,
/*6026*/      OPC_RecordChild1, // #2 = $src2
/*6027*/      OPC_CheckPredicate, 0, // Predicate_unindexedload
/*6029*/      OPC_CheckPredicate, 1, // Predicate_load
/*6031*/      OPC_MoveParent,
/*6032*/      OPC_SwitchType /*2 cases */, 15,  MVT::i16,// ->6050
/*6035*/        OPC_CheckComplexPat, /*CP*/0, /*#*/2, // SelectAddr:$src2 #3 #4
/*6038*/        OPC_EmitMergeInputChains1_1,
/*6039*/        OPC_MorphNodeTo, TARGET_VAL(MSP430::SUB16rm), 0|OPFL_Chain|OPFL_GlueOutput|OPFL_MemRefs,
                    2/*#VTs*/, MVT::i16, MVT::i16, 3/*#Ops*/, 0, 3, 4, 
                // Src: (subc:i16 GR16:i16:$src, (ld:i16 addr:iPTR:$src2)<<P:Predicate_unindexedload>><<P:Predicate_load>>) - Complexity = 16
                // Dst: (SUB16rm:i16:i16 GR16:i16:$src, addr:i16:$src2)
/*6050*/      /*SwitchType*/ 15,  MVT::i8,// ->6067
/*6052*/        OPC_CheckComplexPat, /*CP*/0, /*#*/2, // SelectAddr:$src2 #3 #4
/*6055*/        OPC_EmitMergeInputChains1_1,
/*6056*/        OPC_MorphNodeTo, TARGET_VAL(MSP430::SUB8rm), 0|OPFL_Chain|OPFL_GlueOutput|OPFL_MemRefs,
                    2/*#VTs*/, MVT::i8, MVT::i16, 3/*#Ops*/, 0, 3, 4, 
                // Src: (subc:i8 GR8:i8:$src, (ld:i8 addr:iPTR:$src2)<<P:Predicate_unindexedload>><<P:Predicate_load>>) - Complexity = 16
                // Dst: (SUB8rm:i8:i16 GR8:i8:$src, addr:i16:$src2)
/*6067*/      0, // EndSwitchType
/*6068*/    /*Scope*/ 66, /*->6135*/
/*6069*/      OPC_RecordChild1, // #1 = $src2
/*6070*/      OPC_Scope, 36, /*->6108*/ // 3 children in Scope
/*6072*/        OPC_MoveChild, 1,
/*6074*/        OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*6077*/        OPC_MoveParent,
/*6078*/        OPC_SwitchType /*2 cases */, 12,  MVT::i16,// ->6093
/*6081*/          OPC_EmitConvertToTarget, 1,
/*6083*/          OPC_MorphNodeTo, TARGET_VAL(MSP430::SUB16ri), 0|OPFL_GlueOutput,
                      2/*#VTs*/, MVT::i16, MVT::i16, 2/*#Ops*/, 0, 2, 
                  // Src: (subc:i16 GR16:i16:$src, (imm:i16):$src2) - Complexity = 6
                  // Dst: (SUB16ri:i16:i16 GR16:i16:$src, (imm:i16):$src2)
/*6093*/        /*SwitchType*/ 12,  MVT::i8,// ->6107
/*6095*/          OPC_EmitConvertToTarget, 1,
/*6097*/          OPC_MorphNodeTo, TARGET_VAL(MSP430::SUB8ri), 0|OPFL_GlueOutput,
                      2/*#VTs*/, MVT::i8, MVT::i16, 2/*#Ops*/, 0, 2, 
                  // Src: (subc:i8 GR8:i8:$src, (imm:i8):$src2) - Complexity = 6
                  // Dst: (SUB8ri:i8:i16 GR8:i8:$src, (imm:i8):$src2)
/*6107*/        0, // EndSwitchType
/*6108*/      /*Scope*/ 12, /*->6121*/
/*6109*/        OPC_CheckType, MVT::i16,
/*6111*/        OPC_MorphNodeTo, TARGET_VAL(MSP430::SUB16rr), 0|OPFL_GlueOutput,
                    2/*#VTs*/, MVT::i16, MVT::i16, 2/*#Ops*/, 0, 1, 
                // Src: (subc:i16 GR16:i16:$src, GR16:i16:$src2) - Complexity = 3
                // Dst: (SUB16rr:i16:i16 GR16:i16:$src, GR16:i16:$src2)
/*6121*/      /*Scope*/ 12, /*->6134*/
/*6122*/        OPC_CheckType, MVT::i8,
/*6124*/        OPC_MorphNodeTo, TARGET_VAL(MSP430::SUB8rr), 0|OPFL_GlueOutput,
                    2/*#VTs*/, MVT::i8, MVT::i16, 2/*#Ops*/, 0, 1, 
                // Src: (subc:i8 GR8:i8:$src, GR8:i8:$src2) - Complexity = 3
                // Dst: (SUB8rr:i8:i16 GR8:i8:$src, GR8:i8:$src2)
/*6134*/      0, /*End of Scope*/
/*6135*/    0, /*End of Scope*/
/*6136*/  /*SwitchOpcode*/ 82,  TARGET_VAL(ISD::LOAD),// ->6221
/*6139*/    OPC_RecordMemRef,
/*6140*/    OPC_RecordNode,   // #0 = 'ld' chained node
/*6141*/    OPC_RecordChild1, // #1 = $src
/*6142*/    OPC_CheckPredicate, 0, // Predicate_unindexedload
/*6144*/    OPC_Scope, 34, /*->6180*/ // 3 children in Scope
/*6146*/      OPC_CheckPredicate, 1, // Predicate_load
/*6148*/      OPC_SwitchType /*2 cases */, 13,  MVT::i8,// ->6164
/*6151*/        OPC_CheckComplexPat, /*CP*/0, /*#*/1, // SelectAddr:$src #2 #3
/*6154*/        OPC_EmitMergeInputChains1_0,
/*6155*/        OPC_MorphNodeTo, TARGET_VAL(MSP430::MOV8rm), 0|OPFL_Chain|OPFL_MemRefs,
                    1/*#VTs*/, MVT::i8, 2/*#Ops*/, 2, 3, 
                // Src: (ld:i8 addr:iPTR:$src)<<P:Predicate_unindexedload>><<P:Predicate_load>> - Complexity = 13
                // Dst: (MOV8rm:i8 addr:i16:$src)
/*6164*/      /*SwitchType*/ 13,  MVT::i16,// ->6179
/*6166*/        OPC_CheckComplexPat, /*CP*/0, /*#*/1, // SelectAddr:$src #2 #3
/*6169*/        OPC_EmitMergeInputChains1_0,
/*6170*/        OPC_MorphNodeTo, TARGET_VAL(MSP430::MOV16rm), 0|OPFL_Chain|OPFL_MemRefs,
                    1/*#VTs*/, MVT::i16, 2/*#Ops*/, 2, 3, 
                // Src: (ld:i16 addr:iPTR:$src)<<P:Predicate_unindexedload>><<P:Predicate_load>> - Complexity = 13
                // Dst: (MOV16rm:i16 addr:i16:$src)
/*6179*/      0, // EndSwitchType
/*6180*/    /*Scope*/ 19, /*->6200*/
/*6181*/      OPC_CheckPredicate, 5, // Predicate_zextload
/*6183*/      OPC_CheckPredicate, 6, // Predicate_zextloadi8
/*6185*/      OPC_CheckType, MVT::i16,
/*6187*/      OPC_CheckComplexPat, /*CP*/0, /*#*/1, // SelectAddr:$src #2 #3
/*6190*/      OPC_EmitMergeInputChains1_0,
/*6191*/      OPC_MorphNodeTo, TARGET_VAL(MSP430::MOVZX16rm8), 0|OPFL_Chain|OPFL_MemRefs,
                  1/*#VTs*/, MVT::i16, 2/*#Ops*/, 2, 3, 
              // Src: (ld:i16 addr:iPTR:$src)<<P:Predicate_unindexedload>><<P:Predicate_zextload>><<P:Predicate_zextloadi8>> - Complexity = 13
              // Dst: (MOVZX16rm8:i16 addr:i16:$src)
/*6200*/    /*Scope*/ 19, /*->6220*/
/*6201*/      OPC_CheckPredicate, 7, // Predicate_extload
/*6203*/      OPC_CheckPredicate, 8, // Predicate_extloadi8
/*6205*/      OPC_CheckType, MVT::i16,
/*6207*/      OPC_CheckComplexPat, /*CP*/0, /*#*/1, // SelectAddr:$src #2 #3
/*6210*/      OPC_EmitMergeInputChains1_0,
/*6211*/      OPC_MorphNodeTo, TARGET_VAL(MSP430::MOVZX16rm8), 0|OPFL_Chain|OPFL_MemRefs,
                  1/*#VTs*/, MVT::i16, 2/*#Ops*/, 2, 3, 
              // Src: (ld:i16 addr:iPTR:$src)<<P:Predicate_unindexedload>><<P:Predicate_extload>><<P:Predicate_extloadi8>> - Complexity = 13
              // Dst: (MOVZX16rm8:i16 addr:i16:$src)
/*6220*/    0, /*End of Scope*/
/*6221*/  /*SwitchOpcode*/ 26,  TARGET_VAL(ISD::CALLSEQ_END),// ->6250
/*6224*/    OPC_RecordNode,   // #0 = 'MSP430callseq_end' chained node
/*6225*/    OPC_CaptureGlueInput,
/*6226*/    OPC_RecordChild1, // #1 = $amt1
/*6227*/    OPC_MoveChild, 1,
/*6229*/    OPC_CheckOpcode, TARGET_VAL(ISD::TargetConstant),
/*6232*/    OPC_MoveParent,
/*6233*/    OPC_RecordChild2, // #2 = $amt2
/*6234*/    OPC_MoveChild, 2,
/*6236*/    OPC_CheckOpcode, TARGET_VAL(ISD::TargetConstant),
/*6239*/    OPC_MoveParent,
/*6240*/    OPC_EmitMergeInputChains1_0,
/*6241*/    OPC_MorphNodeTo, TARGET_VAL(MSP430::ADJCALLSTACKUP), 0|OPFL_Chain|OPFL_GlueInput|OPFL_GlueOutput,
                1/*#VTs*/, MVT::i16, 2/*#Ops*/, 1, 2, 
            // Src: (MSP430callseq_end (timm:i16):$amt1, (timm:i16):$amt2) - Complexity = 9
            // Dst: (ADJCALLSTACKUP:i16 (timm:i16):$amt1, (timm:i16):$amt2)
/*6250*/  /*SwitchOpcode*/ 17,  TARGET_VAL(ISD::CALLSEQ_START),// ->6270
/*6253*/    OPC_RecordNode,   // #0 = 'MSP430callseq_start' chained node
/*6254*/    OPC_RecordChild1, // #1 = $amt
/*6255*/    OPC_MoveChild, 1,
/*6257*/    OPC_CheckOpcode, TARGET_VAL(ISD::TargetConstant),
/*6260*/    OPC_MoveParent,
/*6261*/    OPC_EmitMergeInputChains1_0,
/*6262*/    OPC_MorphNodeTo, TARGET_VAL(MSP430::ADJCALLSTACKDOWN), 0|OPFL_Chain|OPFL_GlueOutput,
                1/*#VTs*/, MVT::i16, 1/*#Ops*/, 1, 
            // Src: (MSP430callseq_start (timm:i16):$amt) - Complexity = 6
            // Dst: (ADJCALLSTACKDOWN:i16 (timm:i16):$amt)
/*6270*/  /*SwitchOpcode*/ 27,  TARGET_VAL(MSP430ISD::BR_CC),// ->6300
/*6273*/    OPC_RecordNode,   // #0 = 'MSP430brcc' chained node
/*6274*/    OPC_CaptureGlueInput,
/*6275*/    OPC_RecordChild1, // #1 = $dst
/*6276*/    OPC_MoveChild, 1,
/*6278*/    OPC_CheckOpcode, TARGET_VAL(ISD::BasicBlock),
/*6281*/    OPC_MoveParent,
/*6282*/    OPC_RecordChild2, // #2 = $cc
/*6283*/    OPC_MoveChild, 2,
/*6285*/    OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*6288*/    OPC_MoveParent,
/*6289*/    OPC_EmitMergeInputChains1_0,
/*6290*/    OPC_EmitConvertToTarget, 2,
/*6292*/    OPC_MorphNodeTo, TARGET_VAL(MSP430::JCC), 0|OPFL_Chain|OPFL_GlueInput,
                0/*#VTs*/, 2/*#Ops*/, 1, 3, 
            // Src: (MSP430brcc (bb:Other):$dst, (imm:i8):$cc) - Complexity = 6
            // Dst: (JCC (bb:Other):$dst, (imm:i8):$cc)
/*6300*/  /*SwitchOpcode*/ 53,  TARGET_VAL(ISD::ZERO_EXTEND),// ->6356
/*6303*/    OPC_Scope, 15, /*->6320*/ // 2 children in Scope
/*6305*/      OPC_MoveChild, 0,
/*6307*/      OPC_CheckOpcode, TARGET_VAL(ISD::TRUNCATE),
/*6310*/      OPC_RecordChild0, // #0 = $src
/*6311*/      OPC_MoveParent,
/*6312*/      OPC_MorphNodeTo, TARGET_VAL(MSP430::ZEXT16r), 0,
                  1/*#VTs*/, MVT::i16, 1/*#Ops*/, 0, 
              // Src: (zext:i16 (trunc:i8 GR16:i16:$src)) - Complexity = 6
              // Dst: (ZEXT16r:i16 GR16:i16:$src)
/*6320*/    /*Scope*/ 34, /*->6355*/
/*6321*/      OPC_RecordChild0, // #0 = $src
/*6322*/      OPC_Scope, 21, /*->6345*/ // 2 children in Scope
/*6324*/        OPC_MoveChild, 0,
/*6326*/        OPC_CheckPredicate, 9, // Predicate_def8
/*6328*/        OPC_MoveParent,
/*6329*/        OPC_EmitInteger, MVT::i16, 0, 
/*6332*/        OPC_EmitInteger, MVT::i32, MSP430::subreg_8bit,
/*6335*/        OPC_MorphNodeTo, TARGET_VAL(TargetOpcode::SUBREG_TO_REG), 0,
                    1/*#VTs*/, MVT::i16, 3/*#Ops*/, 1, 0, 2, 
                // Src: (zext:i16 GR8:i8<<P:Predicate_def8>>:$src) - Complexity = 4
                // Dst: (SUBREG_TO_REG:i16 0:i16, GR8:i8:$src, subreg_8bit:i32)
/*6345*/      /*Scope*/ 8, /*->6354*/
/*6346*/        OPC_MorphNodeTo, TARGET_VAL(MSP430::MOVZX16rr8), 0,
                    1/*#VTs*/, MVT::i16, 1/*#Ops*/, 0, 
                // Src: (zext:i16 GR8:i8:$src) - Complexity = 3
                // Dst: (MOVZX16rr8:i16 GR8:i8:$src)
/*6354*/      0, /*End of Scope*/
/*6355*/    0, /*End of Scope*/
/*6356*/  /*SwitchOpcode*/ 47,  TARGET_VAL(MSP430ISD::Wrapper),// ->6406
/*6359*/    OPC_RecordChild0, // #0 = $dst
/*6360*/    OPC_MoveChild, 0,
/*6362*/    OPC_SwitchOpcode /*3 cases */, 11,  TARGET_VAL(ISD::TargetGlobalAddress),// ->6377
/*6366*/      OPC_MoveParent,
/*6367*/      OPC_CheckType, MVT::i16,
/*6369*/      OPC_MorphNodeTo, TARGET_VAL(MSP430::MOV16ri), 0,
                  1/*#VTs*/, MVT::i16, 1/*#Ops*/, 0, 
              // Src: (MSP430Wrapper:i16 (tglobaladdr:i16):$dst) - Complexity = 6
              // Dst: (MOV16ri:i16 (tglobaladdr:i16):$dst)
/*6377*/    /*SwitchOpcode*/ 11,  TARGET_VAL(ISD::TargetExternalSymbol),// ->6391
/*6380*/      OPC_MoveParent,
/*6381*/      OPC_CheckType, MVT::i16,
/*6383*/      OPC_MorphNodeTo, TARGET_VAL(MSP430::MOV16ri), 0,
                  1/*#VTs*/, MVT::i16, 1/*#Ops*/, 0, 
              // Src: (MSP430Wrapper:i16 (texternalsym:i16):$dst) - Complexity = 6
              // Dst: (MOV16ri:i16 (texternalsym:i16):$dst)
/*6391*/    /*SwitchOpcode*/ 11,  TARGET_VAL(ISD::TargetBlockAddress),// ->6405
/*6394*/      OPC_MoveParent,
/*6395*/      OPC_CheckType, MVT::i16,
/*6397*/      OPC_MorphNodeTo, TARGET_VAL(MSP430::MOV16ri), 0,
                  1/*#VTs*/, MVT::i16, 1/*#Ops*/, 0, 
              // Src: (MSP430Wrapper:i16 (tblockaddress:i16):$dst) - Complexity = 6
              // Dst: (MOV16ri:i16 (tblockaddress:i16):$dst)
/*6405*/    0, // EndSwitchOpcode
/*6406*/  /*SwitchOpcode*/ 40,  TARGET_VAL(MSP430ISD::SELECT_CC),// ->6449
/*6409*/    OPC_CaptureGlueInput,
/*6410*/    OPC_RecordChild0, // #0 = $src
/*6411*/    OPC_RecordChild1, // #1 = $src2
/*6412*/    OPC_RecordChild2, // #2 = $cc
/*6413*/    OPC_MoveChild, 2,
/*6415*/    OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*6418*/    OPC_MoveParent,
/*6419*/    OPC_SwitchType /*2 cases */, 12,  MVT::i8,// ->6434
/*6422*/      OPC_EmitConvertToTarget, 2,
/*6424*/      OPC_MorphNodeTo, TARGET_VAL(MSP430::Select8), 0|OPFL_GlueInput,
                  1/*#VTs*/, MVT::i8, 3/*#Ops*/, 0, 1, 3, 
              // Src: (MSP430selectcc:i8 GR8:i8:$src, GR8:i8:$src2, (imm:i8):$cc) - Complexity = 6
              // Dst: (Select8:i8 GR8:i8:$src, GR8:i8:$src2, (imm:i8):$cc)
/*6434*/    /*SwitchType*/ 12,  MVT::i16,// ->6448
/*6436*/      OPC_EmitConvertToTarget, 2,
/*6438*/      OPC_MorphNodeTo, TARGET_VAL(MSP430::Select16), 0|OPFL_GlueInput,
                  1/*#VTs*/, MVT::i16, 3/*#Ops*/, 0, 1, 3, 
              // Src: (MSP430selectcc:i16 GR16:i16:$src, GR16:i16:$src2, (imm:i8):$cc) - Complexity = 6
              // Dst: (Select16:i16 GR16:i16:$src, GR16:i16:$src2, (imm:i8):$cc)
/*6448*/    0, // EndSwitchType
/*6449*/  /*SwitchOpcode*/ 9,  TARGET_VAL(MSP430ISD::RET_FLAG),// ->6461
/*6452*/    OPC_RecordNode,   // #0 = 'MSP430retflag' chained node
/*6453*/    OPC_CaptureGlueInput,
/*6454*/    OPC_EmitMergeInputChains1_0,
/*6455*/    OPC_MorphNodeTo, TARGET_VAL(MSP430::RET), 0|OPFL_Chain|OPFL_GlueInput|OPFL_Variadic0,
                0/*#VTs*/, 0/*#Ops*/, 
            // Src: (MSP430retflag) - Complexity = 3
            // Dst: (RET)
/*6461*/  /*SwitchOpcode*/ 9,  TARGET_VAL(MSP430ISD::RETI_FLAG),// ->6473
/*6464*/    OPC_RecordNode,   // #0 = 'MSP430retiflag' chained node
/*6465*/    OPC_CaptureGlueInput,
/*6466*/    OPC_EmitMergeInputChains1_0,
/*6467*/    OPC_MorphNodeTo, TARGET_VAL(MSP430::RETI), 0|OPFL_Chain|OPFL_GlueInput|OPFL_Variadic0,
                0/*#VTs*/, 0/*#Ops*/, 
            // Src: (MSP430retiflag) - Complexity = 3
            // Dst: (RETI)
/*6473*/  /*SwitchOpcode*/ 16,  TARGET_VAL(ISD::BR),// ->6492
/*6476*/    OPC_RecordNode,   // #0 = 'br' chained node
/*6477*/    OPC_RecordChild1, // #1 = $dst
/*6478*/    OPC_MoveChild, 1,
/*6480*/    OPC_CheckOpcode, TARGET_VAL(ISD::BasicBlock),
/*6483*/    OPC_MoveParent,
/*6484*/    OPC_EmitMergeInputChains1_0,
/*6485*/    OPC_MorphNodeTo, TARGET_VAL(MSP430::JMP), 0|OPFL_Chain,
                0/*#VTs*/, 1/*#Ops*/, 1, 
            // Src: (br (bb:Other):$dst) - Complexity = 3
            // Dst: (JMP (bb:Other):$dst)
/*6492*/  /*SwitchOpcode*/ 27,  TARGET_VAL(ISD::Constant),// ->6522
/*6495*/    OPC_RecordNode,   // #0 = $src
/*6496*/    OPC_SwitchType /*2 cases */, 10,  MVT::i8,// ->6509
/*6499*/      OPC_EmitConvertToTarget, 0,
/*6501*/      OPC_MorphNodeTo, TARGET_VAL(MSP430::MOV8ri), 0,
                  1/*#VTs*/, MVT::i8, 1/*#Ops*/, 1, 
              // Src: (imm:i8):$src - Complexity = 3
              // Dst: (MOV8ri:i8 (imm:i8):$src)
/*6509*/    /*SwitchType*/ 10,  MVT::i16,// ->6521
/*6511*/      OPC_EmitConvertToTarget, 0,
/*6513*/      OPC_MorphNodeTo, TARGET_VAL(MSP430::MOV16ri), 0,
                  1/*#VTs*/, MVT::i16, 1/*#Ops*/, 1, 
              // Src: (imm:i16):$src - Complexity = 3
              // Dst: (MOV16ri:i16 (imm:i16):$src)
/*6521*/    0, // EndSwitchType
/*6522*/  /*SwitchOpcode*/ 25,  TARGET_VAL(MSP430ISD::RRA),// ->6550
/*6525*/    OPC_RecordChild0, // #0 = $src
/*6526*/    OPC_SwitchType /*2 cases */, 9,  MVT::i8,// ->6538
/*6529*/      OPC_MorphNodeTo, TARGET_VAL(MSP430::SAR8r1), 0,
                  2/*#VTs*/, MVT::i8, MVT::i16, 1/*#Ops*/, 0, 
              // Src: (MSP430rra:i8 GR8:i8:$src) - Complexity = 3
              // Dst: (SAR8r1:i8:i16 GR8:i8:$src)
/*6538*/    /*SwitchType*/ 9,  MVT::i16,// ->6549
/*6540*/      OPC_MorphNodeTo, TARGET_VAL(MSP430::SAR16r1), 0,
                  2/*#VTs*/, MVT::i16, MVT::i16, 1/*#Ops*/, 0, 
              // Src: (MSP430rra:i16 GR16:i16:$src) - Complexity = 3
              // Dst: (SAR16r1:i16:i16 GR16:i16:$src)
/*6549*/    0, // EndSwitchType
/*6550*/  /*SwitchOpcode*/ 25,  TARGET_VAL(MSP430ISD::RLA),// ->6578
/*6553*/    OPC_RecordChild0, // #0 = $src
/*6554*/    OPC_SwitchType /*2 cases */, 9,  MVT::i8,// ->6566
/*6557*/      OPC_MorphNodeTo, TARGET_VAL(MSP430::SHL8r1), 0,
                  2/*#VTs*/, MVT::i8, MVT::i16, 1/*#Ops*/, 0, 
              // Src: (MSP430rla:i8 GR8:i8:$src) - Complexity = 3
              // Dst: (SHL8r1:i8:i16 GR8:i8:$src)
/*6566*/    /*SwitchType*/ 9,  MVT::i16,// ->6577
/*6568*/      OPC_MorphNodeTo, TARGET_VAL(MSP430::SHL16r1), 0,
                  2/*#VTs*/, MVT::i16, MVT::i16, 1/*#Ops*/, 0, 
              // Src: (MSP430rla:i16 GR16:i16:$src) - Complexity = 3
              // Dst: (SHL16r1:i16:i16 GR16:i16:$src)
/*6577*/    0, // EndSwitchType
/*6578*/  /*SwitchOpcode*/ 25,  TARGET_VAL(MSP430ISD::RRC),// ->6606
/*6581*/    OPC_RecordChild0, // #0 = $src
/*6582*/    OPC_SwitchType /*2 cases */, 9,  MVT::i8,// ->6594
/*6585*/      OPC_MorphNodeTo, TARGET_VAL(MSP430::SAR8r1c), 0,
                  2/*#VTs*/, MVT::i8, MVT::i16, 1/*#Ops*/, 0, 
              // Src: (MSP430rrc:i8 GR8:i8:$src) - Complexity = 3
              // Dst: (SAR8r1c:i8:i16 GR8:i8:$src)
/*6594*/    /*SwitchType*/ 9,  MVT::i16,// ->6605
/*6596*/      OPC_MorphNodeTo, TARGET_VAL(MSP430::SAR16r1c), 0,
                  2/*#VTs*/, MVT::i16, MVT::i16, 1/*#Ops*/, 0, 
              // Src: (MSP430rrc:i16 GR16:i16:$src) - Complexity = 3
              // Dst: (SAR16r1c:i16:i16 GR16:i16:$src)
/*6605*/    0, // EndSwitchType
/*6606*/  /*SwitchOpcode*/ 15,  TARGET_VAL(ISD::SIGN_EXTEND_INREG),// ->6624
/*6609*/    OPC_RecordChild0, // #0 = $src
/*6610*/    OPC_MoveChild, 1,
/*6612*/    OPC_CheckValueType, MVT::i8,
/*6614*/    OPC_MoveParent,
/*6615*/    OPC_MorphNodeTo, TARGET_VAL(MSP430::SEXT16r), 0,
                2/*#VTs*/, MVT::i16, MVT::i16, 1/*#Ops*/, 0, 
            // Src: (sext_inreg:i16 GR16:i16:$src, i8:Other) - Complexity = 3
            // Dst: (SEXT16r:i16:i16 GR16:i16:$src)
/*6624*/  /*SwitchOpcode*/ 11,  TARGET_VAL(ISD::BSWAP),// ->6638
/*6627*/    OPC_RecordChild0, // #0 = $src
/*6628*/    OPC_CheckType, MVT::i16,
/*6630*/    OPC_MorphNodeTo, TARGET_VAL(MSP430::SWPB16r), 0,
                1/*#VTs*/, MVT::i16, 1/*#Ops*/, 0, 
            // Src: (bswap:i16 GR16:i16:$src) - Complexity = 3
            // Dst: (SWPB16r:i16 GR16:i16:$src)
/*6638*/  /*SwitchOpcode*/ 17,  TARGET_VAL(ISD::ANY_EXTEND),// ->6658
/*6641*/    OPC_RecordChild0, // #0 = $src
/*6642*/    OPC_EmitInteger, MVT::i16, 0, 
/*6645*/    OPC_EmitInteger, MVT::i32, MSP430::subreg_8bit,
/*6648*/    OPC_MorphNodeTo, TARGET_VAL(TargetOpcode::SUBREG_TO_REG), 0,
                1/*#VTs*/, MVT::i16, 3/*#Ops*/, 1, 0, 2, 
            // Src: (anyext:i16 GR8:i8:$src) - Complexity = 3
            // Dst: (SUBREG_TO_REG:i16 0:i16, GR8:i8:$src, subreg_8bit:i32)
/*6658*/  /*SwitchOpcode*/ 13,  TARGET_VAL(ISD::TRUNCATE),// ->6674
/*6661*/    OPC_RecordChild0, // #0 = $src
/*6662*/    OPC_EmitInteger, MVT::i32, MSP430::subreg_8bit,
/*6665*/    OPC_MorphNodeTo, TARGET_VAL(TargetOpcode::EXTRACT_SUBREG), 0,
                1/*#VTs*/, MVT::i8, 2/*#Ops*/, 0, 1, 
            // Src: (trunc:i8 GR16:i16:$src) - Complexity = 3
            // Dst: (EXTRACT_SUBREG:i8 GR16:i16:$src, subreg_8bit:i32)
/*6674*/  /*SwitchOpcode*/ 28,  TARGET_VAL(MSP430ISD::SHL),// ->6705
/*6677*/    OPC_RecordChild0, // #0 = $src
/*6678*/    OPC_RecordChild1, // #1 = $cnt
/*6679*/    OPC_SwitchType /*2 cases */, 10,  MVT::i8,// ->6692
/*6682*/      OPC_MorphNodeTo, TARGET_VAL(MSP430::Shl8), 0,
                  2/*#VTs*/, MVT::i8, MVT::i16, 2/*#Ops*/, 0, 1, 
              // Src: (MSP430shl:i8 GR8:i8:$src, GR8:i8:$cnt) - Complexity = 3
              // Dst: (Shl8:i8:i16 GR8:i8:$src, GR8:i8:$cnt)
/*6692*/    /*SwitchType*/ 10,  MVT::i16,// ->6704
/*6694*/      OPC_MorphNodeTo, TARGET_VAL(MSP430::Shl16), 0,
                  2/*#VTs*/, MVT::i16, MVT::i16, 2/*#Ops*/, 0, 1, 
              // Src: (MSP430shl:i16 GR16:i16:$src, GR8:i8:$cnt) - Complexity = 3
              // Dst: (Shl16:i16:i16 GR16:i16:$src, GR8:i8:$cnt)
/*6704*/    0, // EndSwitchType
/*6705*/  /*SwitchOpcode*/ 28,  TARGET_VAL(MSP430ISD::SRA),// ->6736
/*6708*/    OPC_RecordChild0, // #0 = $src
/*6709*/    OPC_RecordChild1, // #1 = $cnt
/*6710*/    OPC_SwitchType /*2 cases */, 10,  MVT::i8,// ->6723
/*6713*/      OPC_MorphNodeTo, TARGET_VAL(MSP430::Sra8), 0,
                  2/*#VTs*/, MVT::i8, MVT::i16, 2/*#Ops*/, 0, 1, 
              // Src: (MSP430sra:i8 GR8:i8:$src, GR8:i8:$cnt) - Complexity = 3
              // Dst: (Sra8:i8:i16 GR8:i8:$src, GR8:i8:$cnt)
/*6723*/    /*SwitchType*/ 10,  MVT::i16,// ->6735
/*6725*/      OPC_MorphNodeTo, TARGET_VAL(MSP430::Sra16), 0,
                  2/*#VTs*/, MVT::i16, MVT::i16, 2/*#Ops*/, 0, 1, 
              // Src: (MSP430sra:i16 GR16:i16:$src, GR8:i8:$cnt) - Complexity = 3
              // Dst: (Sra16:i16:i16 GR16:i16:$src, GR8:i8:$cnt)
/*6735*/    0, // EndSwitchType
/*6736*/  /*SwitchOpcode*/ 28,  TARGET_VAL(MSP430ISD::SRL),// ->6767
/*6739*/    OPC_RecordChild0, // #0 = $src
/*6740*/    OPC_RecordChild1, // #1 = $cnt
/*6741*/    OPC_SwitchType /*2 cases */, 10,  MVT::i8,// ->6754
/*6744*/      OPC_MorphNodeTo, TARGET_VAL(MSP430::Srl8), 0,
                  2/*#VTs*/, MVT::i8, MVT::i16, 2/*#Ops*/, 0, 1, 
              // Src: (MSP430srl:i8 GR8:i8:$src, GR8:i8:$cnt) - Complexity = 3
              // Dst: (Srl8:i8:i16 GR8:i8:$src, GR8:i8:$cnt)
/*6754*/    /*SwitchType*/ 10,  MVT::i16,// ->6766
/*6756*/      OPC_MorphNodeTo, TARGET_VAL(MSP430::Srl16), 0,
                  2/*#VTs*/, MVT::i16, MVT::i16, 2/*#Ops*/, 0, 1, 
              // Src: (MSP430srl:i16 GR16:i16:$src, GR8:i8:$cnt) - Complexity = 3
              // Dst: (Srl16:i16:i16 GR16:i16:$src, GR8:i8:$cnt)
/*6766*/    0, // EndSwitchType
/*6767*/  0, // EndSwitchOpcode
    0
  }; // Total Array size is 6769 bytes

  // Opcode Histogram:
  // #OPC_Scope                          = 71
  // #OPC_RecordNode                     = 71
  // #OPC_RecordChild                    = 170
  // #OPC_RecordMemRef                   = 58
  // #OPC_CaptureGlueInput               = 10
  // #OPC_MoveChild                      = 123
  // #OPC_MoveParent                     = 231
  // #OPC_CheckSame                      = 0
  // #OPC_CheckChildSame                 = 82
  // #OPC_CheckPatternPredicate          = 0
  // #OPC_CheckPredicate                 = 308
  // #OPC_CheckOpcode                    = 90
  // #OPC_SwitchOpcode                   = 11
  // #OPC_CheckType                      = 50
  // #OPC_SwitchType                     = 75
  // #OPC_CheckChildType                 = 8
  // #OPC_CheckInteger                   = 21
  // #OPC_CheckCondCode                  = 0
  // #OPC_CheckValueType                 = 1
  // #OPC_CheckComplexPat                = 183
  // #OPC_CheckAndImm                    = 1
  // #OPC_CheckOrImm                     = 0
  // #OPC_CheckFoldableChainNode         = 56
  // #OPC_EmitInteger                    = 2
  // #OPC_EmitStringInteger              = 5
  // #OPC_EmitRegister                   = 0
  // #OPC_EmitConvertToTarget            = 48
  // #OPC_EmitMergeInputChains           = 157
  // #OPC_EmitCopyToReg                  = 0
  // #OPC_EmitNode                       = 2
  // #OPC_EmitNodeXForm                  = 0
  // #OPC_MarkGlueResults                = 28
  // #OPC_CompleteMatch                  = 0
  // #OPC_MorphNodeTo                    = 239

  #undef TARGET_VAL
  return SelectCodeCommon(N, MatcherTable,sizeof(MatcherTable));
}

virtual bool CheckNodePredicate(SDNode *Node,
                                unsigned PredNo) const {
  switch (PredNo) {
  default: llvm_unreachable("Invalid predicate in table?");
  case 0: { // Predicate_unindexedload
    SDNode *N = Node;

  return cast<LoadSDNode>(N)->getAddressingMode() == ISD::UNINDEXED;

  }
  case 1: { // Predicate_load
    SDNode *N = Node;

  return cast<LoadSDNode>(N)->getExtensionType() == ISD::NON_EXTLOAD;

  }
  case 2: { // Predicate_unindexedstore
    SDNode *N = Node;

  return cast<StoreSDNode>(N)->getAddressingMode() == ISD::UNINDEXED;

  }
  case 3: { // Predicate_store
    SDNode *N = Node;

  return !cast<StoreSDNode>(N)->isTruncatingStore();

  }
  case 4: { // Predicate_and_su
    SDNode *N = Node;

  return N->hasOneUse();

  }
  case 5: { // Predicate_zextload
    SDNode *N = Node;

  return cast<LoadSDNode>(N)->getExtensionType() == ISD::ZEXTLOAD;

  }
  case 6: { // Predicate_zextloadi8
    SDNode *N = Node;

  return cast<LoadSDNode>(N)->getMemoryVT() == MVT::i8;

  }
  case 7: { // Predicate_extload
    SDNode *N = Node;

  return cast<LoadSDNode>(N)->getExtensionType() == ISD::EXTLOAD;

  }
  case 8: { // Predicate_extloadi8
    SDNode *N = Node;

  return cast<LoadSDNode>(N)->getMemoryVT() == MVT::i8;

  }
  case 9: { // Predicate_def8
    SDNode *N = Node;

  return N->getOpcode() != ISD::TRUNCATE &&
         N->getOpcode() != TargetOpcode::EXTRACT_SUBREG &&
         N->getOpcode() != ISD::CopyFromReg;

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
    return SelectAddr(N, Result[NextRes+0].first, Result[NextRes+1].first);
  }
}


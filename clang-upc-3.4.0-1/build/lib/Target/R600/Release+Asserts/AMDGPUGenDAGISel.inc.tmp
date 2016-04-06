/*===- TableGen'erated file -------------------------------------*- C++ -*-===*\
|*                                                                            *|
|*DAG Instruction Selector for the AMDGPU target                              *|
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
/*0*/     OPC_SwitchOpcode /*84 cases */, 82|128,3/*466*/,  TARGET_VAL(AMDGPUISD::TBUFFER_STORE_FORMAT),// ->471
/*5*/       OPC_RecordMemRef,
/*6*/       OPC_RecordNode,   // #0 = 'SItbuffer_store' chained node
/*7*/       OPC_RecordChild1, // #1 = $rsrc
/*8*/       OPC_RecordChild2, // #2 = $vdata
/*9*/       OPC_Scope, 114, /*->125*/ // 3 children in Scope
/*11*/        OPC_CheckChild2Type, MVT::i32,
/*13*/        OPC_MoveChild, 3,
/*15*/        OPC_CheckInteger, 1, 
/*17*/        OPC_MoveParent,
/*18*/        OPC_RecordChild4, // #3 = $vaddr
/*19*/        OPC_RecordChild5, // #4 = $soffset
/*20*/        OPC_RecordChild6, // #5 = $inst_offset
/*21*/        OPC_MoveChild, 6,
/*23*/        OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*26*/        OPC_MoveParent,
/*27*/        OPC_RecordChild7, // #6 = $dfmt
/*28*/        OPC_MoveChild, 7,
/*30*/        OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*33*/        OPC_MoveParent,
/*34*/        OPC_MoveChild, 8,
/*36*/        OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*39*/        OPC_RecordNode, // #7 = $nfmt
/*40*/        OPC_MoveParent,
/*41*/        OPC_MoveChild, 9,
/*43*/        OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*46*/        OPC_RecordNode, // #8 = $offen
/*47*/        OPC_MoveParent,
/*48*/        OPC_MoveChild, 10,
/*50*/        OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*53*/        OPC_RecordNode, // #9 = $idxen
/*54*/        OPC_MoveParent,
/*55*/        OPC_MoveChild, 11,
/*57*/        OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*60*/        OPC_RecordNode, // #10 = $glc
/*61*/        OPC_MoveParent,
/*62*/        OPC_MoveChild, 12,
/*64*/        OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*67*/        OPC_RecordNode, // #11 = $slc
/*68*/        OPC_MoveParent,
/*69*/        OPC_MoveChild, 13,
/*71*/        OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*74*/        OPC_RecordNode, // #12 = $tfe
/*75*/        OPC_MoveParent,
/*76*/        OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*78*/        OPC_EmitMergeInputChains1_0,
/*79*/        OPC_EmitNodeXForm, 0, 5, // as_i16imm
/*82*/        OPC_EmitNodeXForm, 1, 8, // as_i1imm
/*85*/        OPC_EmitNodeXForm, 1, 9, // as_i1imm
/*88*/        OPC_EmitNodeXForm, 1, 10, // as_i1imm
/*91*/        OPC_EmitInteger, MVT::i1, 0, 
/*94*/        OPC_EmitNodeXForm, 2, 6, // as_i8imm
/*97*/        OPC_EmitNodeXForm, 2, 7, // as_i8imm
/*100*/       OPC_EmitNodeXForm, 1, 11, // as_i1imm
/*103*/       OPC_EmitNodeXForm, 1, 12, // as_i1imm
/*106*/       OPC_MorphNodeTo, TARGET_VAL(AMDGPU::TBUFFER_STORE_FORMAT_X), 0|OPFL_Chain|OPFL_MemRefs,
                  0/*#VTs*/, 13/*#Ops*/, 2, 13, 14, 15, 16, 17, 18, 19, 3, 1, 20, 21, 4, 
              // Src: (SItbuffer_store i128:i128:$rsrc, i32:i32:$vdata, 1:i32, i32:i32:$vaddr, i32:i32:$soffset, (imm:i32):$inst_offset, (imm:i32):$dfmt, (imm:i32):$nfmt, (imm:i32):$offen, (imm:i32):$idxen, (imm:i32):$glc, (imm:i32):$slc, (imm:i32):$tfe) - Complexity = 32
              // Dst: (TBUFFER_STORE_FORMAT_X ?:i32:$vdata, (as_i16imm:i16 ?:i32:$inst_offset), (as_i1imm:i1 ?:i32:$offen), (as_i1imm:i1 ?:i32:$idxen), (as_i1imm:i1 ?:i32:$glc), 0:i1, (as_i8imm:i8 ?:i32:$dfmt), (as_i8imm:i8 ?:i32:$nfmt), ?:i32:$vaddr, ?:i128:$rsrc, (as_i1imm:i1 ?:i32:$slc), (as_i1imm:i1 ?:i32:$tfe), ?:i32:$soffset)
/*125*/     /*Scope*/ 114, /*->240*/
/*126*/       OPC_CheckChild2Type, MVT::v2i32,
/*128*/       OPC_MoveChild, 3,
/*130*/       OPC_CheckInteger, 2, 
/*132*/       OPC_MoveParent,
/*133*/       OPC_RecordChild4, // #3 = $vaddr
/*134*/       OPC_RecordChild5, // #4 = $soffset
/*135*/       OPC_RecordChild6, // #5 = $inst_offset
/*136*/       OPC_MoveChild, 6,
/*138*/       OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*141*/       OPC_MoveParent,
/*142*/       OPC_RecordChild7, // #6 = $dfmt
/*143*/       OPC_MoveChild, 7,
/*145*/       OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*148*/       OPC_MoveParent,
/*149*/       OPC_MoveChild, 8,
/*151*/       OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*154*/       OPC_RecordNode, // #7 = $nfmt
/*155*/       OPC_MoveParent,
/*156*/       OPC_MoveChild, 9,
/*158*/       OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*161*/       OPC_RecordNode, // #8 = $offen
/*162*/       OPC_MoveParent,
/*163*/       OPC_MoveChild, 10,
/*165*/       OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*168*/       OPC_RecordNode, // #9 = $idxen
/*169*/       OPC_MoveParent,
/*170*/       OPC_MoveChild, 11,
/*172*/       OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*175*/       OPC_RecordNode, // #10 = $glc
/*176*/       OPC_MoveParent,
/*177*/       OPC_MoveChild, 12,
/*179*/       OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*182*/       OPC_RecordNode, // #11 = $slc
/*183*/       OPC_MoveParent,
/*184*/       OPC_MoveChild, 13,
/*186*/       OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*189*/       OPC_RecordNode, // #12 = $tfe
/*190*/       OPC_MoveParent,
/*191*/       OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*193*/       OPC_EmitMergeInputChains1_0,
/*194*/       OPC_EmitNodeXForm, 0, 5, // as_i16imm
/*197*/       OPC_EmitNodeXForm, 1, 8, // as_i1imm
/*200*/       OPC_EmitNodeXForm, 1, 9, // as_i1imm
/*203*/       OPC_EmitNodeXForm, 1, 10, // as_i1imm
/*206*/       OPC_EmitInteger, MVT::i1, 0, 
/*209*/       OPC_EmitNodeXForm, 2, 6, // as_i8imm
/*212*/       OPC_EmitNodeXForm, 2, 7, // as_i8imm
/*215*/       OPC_EmitNodeXForm, 1, 11, // as_i1imm
/*218*/       OPC_EmitNodeXForm, 1, 12, // as_i1imm
/*221*/       OPC_MorphNodeTo, TARGET_VAL(AMDGPU::TBUFFER_STORE_FORMAT_XY), 0|OPFL_Chain|OPFL_MemRefs,
                  0/*#VTs*/, 13/*#Ops*/, 2, 13, 14, 15, 16, 17, 18, 19, 3, 1, 20, 21, 4, 
              // Src: (SItbuffer_store i128:i128:$rsrc, v2i32:v2i32:$vdata, 2:i32, i32:i32:$vaddr, i32:i32:$soffset, (imm:i32):$inst_offset, (imm:i32):$dfmt, (imm:i32):$nfmt, (imm:i32):$offen, (imm:i32):$idxen, (imm:i32):$glc, (imm:i32):$slc, (imm:i32):$tfe) - Complexity = 32
              // Dst: (TBUFFER_STORE_FORMAT_XY ?:v2i32:$vdata, (as_i16imm:i16 ?:i32:$inst_offset), (as_i1imm:i1 ?:i32:$offen), (as_i1imm:i1 ?:i32:$idxen), (as_i1imm:i1 ?:i32:$glc), 0:i1, (as_i8imm:i8 ?:i32:$dfmt), (as_i8imm:i8 ?:i32:$nfmt), ?:i32:$vaddr, ?:i128:$rsrc, (as_i1imm:i1 ?:i32:$slc), (as_i1imm:i1 ?:i32:$tfe), ?:i32:$soffset)
/*240*/     /*Scope*/ 100|128,1/*228*/, /*->470*/
/*242*/       OPC_CheckChild2Type, MVT::v4i32,
/*244*/       OPC_MoveChild, 3,
/*246*/       OPC_Scope, 110, /*->358*/ // 2 children in Scope
/*248*/         OPC_CheckInteger, 3, 
/*250*/         OPC_MoveParent,
/*251*/         OPC_RecordChild4, // #3 = $vaddr
/*252*/         OPC_RecordChild5, // #4 = $soffset
/*253*/         OPC_RecordChild6, // #5 = $inst_offset
/*254*/         OPC_MoveChild, 6,
/*256*/         OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*259*/         OPC_MoveParent,
/*260*/         OPC_RecordChild7, // #6 = $dfmt
/*261*/         OPC_MoveChild, 7,
/*263*/         OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*266*/         OPC_MoveParent,
/*267*/         OPC_MoveChild, 8,
/*269*/         OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*272*/         OPC_RecordNode, // #7 = $nfmt
/*273*/         OPC_MoveParent,
/*274*/         OPC_MoveChild, 9,
/*276*/         OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*279*/         OPC_RecordNode, // #8 = $offen
/*280*/         OPC_MoveParent,
/*281*/         OPC_MoveChild, 10,
/*283*/         OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*286*/         OPC_RecordNode, // #9 = $idxen
/*287*/         OPC_MoveParent,
/*288*/         OPC_MoveChild, 11,
/*290*/         OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*293*/         OPC_RecordNode, // #10 = $glc
/*294*/         OPC_MoveParent,
/*295*/         OPC_MoveChild, 12,
/*297*/         OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*300*/         OPC_RecordNode, // #11 = $slc
/*301*/         OPC_MoveParent,
/*302*/         OPC_MoveChild, 13,
/*304*/         OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*307*/         OPC_RecordNode, // #12 = $tfe
/*308*/         OPC_MoveParent,
/*309*/         OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*311*/         OPC_EmitMergeInputChains1_0,
/*312*/         OPC_EmitNodeXForm, 0, 5, // as_i16imm
/*315*/         OPC_EmitNodeXForm, 1, 8, // as_i1imm
/*318*/         OPC_EmitNodeXForm, 1, 9, // as_i1imm
/*321*/         OPC_EmitNodeXForm, 1, 10, // as_i1imm
/*324*/         OPC_EmitInteger, MVT::i1, 0, 
/*327*/         OPC_EmitNodeXForm, 2, 6, // as_i8imm
/*330*/         OPC_EmitNodeXForm, 2, 7, // as_i8imm
/*333*/         OPC_EmitNodeXForm, 1, 11, // as_i1imm
/*336*/         OPC_EmitNodeXForm, 1, 12, // as_i1imm
/*339*/         OPC_MorphNodeTo, TARGET_VAL(AMDGPU::TBUFFER_STORE_FORMAT_XYZ), 0|OPFL_Chain|OPFL_MemRefs,
                    0/*#VTs*/, 13/*#Ops*/, 2, 13, 14, 15, 16, 17, 18, 19, 3, 1, 20, 21, 4, 
                // Src: (SItbuffer_store i128:i128:$rsrc, v4i32:v4i32:$vdata, 3:i32, i32:i32:$vaddr, i32:i32:$soffset, (imm:i32):$inst_offset, (imm:i32):$dfmt, (imm:i32):$nfmt, (imm:i32):$offen, (imm:i32):$idxen, (imm:i32):$glc, (imm:i32):$slc, (imm:i32):$tfe) - Complexity = 32
                // Dst: (TBUFFER_STORE_FORMAT_XYZ ?:v4i32:$vdata, (as_i16imm:i16 ?:i32:$inst_offset), (as_i1imm:i1 ?:i32:$offen), (as_i1imm:i1 ?:i32:$idxen), (as_i1imm:i1 ?:i32:$glc), 0:i1, (as_i8imm:i8 ?:i32:$dfmt), (as_i8imm:i8 ?:i32:$nfmt), ?:i32:$vaddr, ?:i128:$rsrc, (as_i1imm:i1 ?:i32:$slc), (as_i1imm:i1 ?:i32:$tfe), ?:i32:$soffset)
/*358*/       /*Scope*/ 110, /*->469*/
/*359*/         OPC_CheckInteger, 4, 
/*361*/         OPC_MoveParent,
/*362*/         OPC_RecordChild4, // #3 = $vaddr
/*363*/         OPC_RecordChild5, // #4 = $soffset
/*364*/         OPC_RecordChild6, // #5 = $inst_offset
/*365*/         OPC_MoveChild, 6,
/*367*/         OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*370*/         OPC_MoveParent,
/*371*/         OPC_RecordChild7, // #6 = $dfmt
/*372*/         OPC_MoveChild, 7,
/*374*/         OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*377*/         OPC_MoveParent,
/*378*/         OPC_MoveChild, 8,
/*380*/         OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*383*/         OPC_RecordNode, // #7 = $nfmt
/*384*/         OPC_MoveParent,
/*385*/         OPC_MoveChild, 9,
/*387*/         OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*390*/         OPC_RecordNode, // #8 = $offen
/*391*/         OPC_MoveParent,
/*392*/         OPC_MoveChild, 10,
/*394*/         OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*397*/         OPC_RecordNode, // #9 = $idxen
/*398*/         OPC_MoveParent,
/*399*/         OPC_MoveChild, 11,
/*401*/         OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*404*/         OPC_RecordNode, // #10 = $glc
/*405*/         OPC_MoveParent,
/*406*/         OPC_MoveChild, 12,
/*408*/         OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*411*/         OPC_RecordNode, // #11 = $slc
/*412*/         OPC_MoveParent,
/*413*/         OPC_MoveChild, 13,
/*415*/         OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*418*/         OPC_RecordNode, // #12 = $tfe
/*419*/         OPC_MoveParent,
/*420*/         OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*422*/         OPC_EmitMergeInputChains1_0,
/*423*/         OPC_EmitNodeXForm, 0, 5, // as_i16imm
/*426*/         OPC_EmitNodeXForm, 1, 8, // as_i1imm
/*429*/         OPC_EmitNodeXForm, 1, 9, // as_i1imm
/*432*/         OPC_EmitNodeXForm, 1, 10, // as_i1imm
/*435*/         OPC_EmitInteger, MVT::i1, 0, 
/*438*/         OPC_EmitNodeXForm, 2, 6, // as_i8imm
/*441*/         OPC_EmitNodeXForm, 2, 7, // as_i8imm
/*444*/         OPC_EmitNodeXForm, 1, 11, // as_i1imm
/*447*/         OPC_EmitNodeXForm, 1, 12, // as_i1imm
/*450*/         OPC_MorphNodeTo, TARGET_VAL(AMDGPU::TBUFFER_STORE_FORMAT_XYZW), 0|OPFL_Chain|OPFL_MemRefs,
                    0/*#VTs*/, 13/*#Ops*/, 2, 13, 14, 15, 16, 17, 18, 19, 3, 1, 20, 21, 4, 
                // Src: (SItbuffer_store i128:i128:$rsrc, v4i32:v4i32:$vdata, 4:i32, i32:i32:$vaddr, i32:i32:$soffset, (imm:i32):$inst_offset, (imm:i32):$dfmt, (imm:i32):$nfmt, (imm:i32):$offen, (imm:i32):$idxen, (imm:i32):$glc, (imm:i32):$slc, (imm:i32):$tfe) - Complexity = 32
                // Dst: (TBUFFER_STORE_FORMAT_XYZW ?:v4i32:$vdata, (as_i16imm:i16 ?:i32:$inst_offset), (as_i1imm:i1 ?:i32:$offen), (as_i1imm:i1 ?:i32:$idxen), (as_i1imm:i1 ?:i32:$glc), 0:i1, (as_i8imm:i8 ?:i32:$dfmt), (as_i8imm:i8 ?:i32:$nfmt), ?:i32:$vaddr, ?:i128:$rsrc, (as_i1imm:i1 ?:i32:$slc), (as_i1imm:i1 ?:i32:$tfe), ?:i32:$soffset)
/*469*/       0, /*End of Scope*/
/*470*/     0, /*End of Scope*/
/*471*/   /*SwitchOpcode*/ 120|128,9/*1272*/,  TARGET_VAL(ISD::INTRINSIC_VOID),// ->1747
/*475*/     OPC_RecordNode,   // #0 = 'intrinsic_void' chained node
/*476*/     OPC_MoveChild, 1,
/*478*/     OPC_Scope, 80, /*->560*/ // 10 children in Scope
/*480*/       OPC_CheckInteger, 96|128,26/*3424*/, 
/*483*/       OPC_MoveParent,
/*484*/       OPC_RecordChild2, // #1 = $en
/*485*/       OPC_MoveChild, 2,
/*487*/       OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*490*/       OPC_MoveParent,
/*491*/       OPC_RecordChild3, // #2 = $vm
/*492*/       OPC_MoveChild, 3,
/*494*/       OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*497*/       OPC_MoveParent,
/*498*/       OPC_RecordChild4, // #3 = $done
/*499*/       OPC_MoveChild, 4,
/*501*/       OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*504*/       OPC_MoveParent,
/*505*/       OPC_RecordChild5, // #4 = $tgt
/*506*/       OPC_MoveChild, 5,
/*508*/       OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*511*/       OPC_MoveParent,
/*512*/       OPC_RecordChild6, // #5 = $compr
/*513*/       OPC_MoveChild, 6,
/*515*/       OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*518*/       OPC_MoveParent,
/*519*/       OPC_RecordChild7, // #6 = $src0
/*520*/       OPC_MoveChild, 8,
/*522*/       OPC_RecordNode, // #7 = $src1
/*523*/       OPC_MoveParent,
/*524*/       OPC_MoveChild, 9,
/*526*/       OPC_RecordNode, // #8 = $src2
/*527*/       OPC_MoveParent,
/*528*/       OPC_MoveChild, 10,
/*530*/       OPC_RecordNode, // #9 = $src3
/*531*/       OPC_MoveParent,
/*532*/       OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*534*/       OPC_EmitMergeInputChains1_0,
/*535*/       OPC_EmitConvertToTarget, 1,
/*537*/       OPC_EmitConvertToTarget, 4,
/*539*/       OPC_EmitConvertToTarget, 5,
/*541*/       OPC_EmitConvertToTarget, 3,
/*543*/       OPC_EmitConvertToTarget, 2,
/*545*/       OPC_MorphNodeTo, TARGET_VAL(AMDGPU::EXP), 0|OPFL_Chain,
                  0/*#VTs*/, 9/*#Ops*/, 10, 11, 12, 13, 14, 6, 7, 8, 9, 
              // Src: (intrinsic_void 3424:iPTR, (imm:i32):$en, (imm:i32):$vm, (imm:i32):$done, (imm:i32):$tgt, (imm:i32):$compr, f32:f32:$src0, f32:f32:$src1, f32:f32:$src2, f32:f32:$src3) - Complexity = 23
              // Dst: (EXP (imm:i32):$en, (imm:i32):$tgt, (imm:i32):$compr, (imm:i32):$done, (imm:i32):$vm, ?:f32:$src0, ?:f32:$src1, ?:f32:$src2, ?:f32:$src3)
/*560*/     /*Scope*/ 84|128,2/*340*/, /*->902*/
/*562*/       OPC_CheckInteger, 82|128,26/*3410*/, 
/*565*/       OPC_MoveParent,
/*566*/       OPC_RecordChild2, // #1 = $src
/*567*/       OPC_RecordChild3, // #2 = $arraybase
/*568*/       OPC_MoveChild, 3,
/*570*/       OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*573*/       OPC_MoveParent,
/*574*/       OPC_MoveChild, 4,
/*576*/       OPC_Scope, 80, /*->658*/ // 4 children in Scope
/*578*/         OPC_CheckInteger, 0, 
/*580*/         OPC_MoveParent,
/*581*/         OPC_RecordChild5, // #3 = $mask
/*582*/         OPC_MoveChild, 5,
/*584*/         OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*587*/         OPC_MoveParent,
/*588*/         OPC_Scope, 33, /*->623*/ // 2 children in Scope
/*590*/           OPC_CheckPatternPredicate, 1, // (Subtarget.getGeneration() <= AMDGPUSubtarget::R700)
/*592*/           OPC_EmitMergeInputChains1_0,
/*593*/           OPC_EmitInteger, MVT::i32, 0, 
/*596*/           OPC_EmitConvertToTarget, 2,
/*598*/           OPC_EmitInteger, MVT::i32, 127|128,31/*4095*/, 
/*602*/           OPC_EmitConvertToTarget, 3,
/*604*/           OPC_EmitInteger, MVT::i32, 32, 
/*607*/           OPC_EmitInteger, MVT::i32, 0, 
/*610*/           OPC_MorphNodeTo, TARGET_VAL(AMDGPU::R600_ExportBuf), 0|OPFL_Chain,
                      0/*#VTs*/, 7/*#Ops*/, 1, 4, 5, 6, 7, 8, 9, 
                  // Src: (intrinsic_void 3410:iPTR, R600_Reg128:v4f32:$src, (imm:i32):$arraybase, 0:i32, (imm:i32):$mask) - Complexity = 19
                  // Dst: (R600_ExportBuf R600_Reg128:v4f32:$src, 0:i32, (imm:i32):$arraybase, 4095:i32, (imm:i32):$mask, 32:i32, 0:i32)
/*623*/         /*Scope*/ 33, /*->657*/
/*624*/           OPC_CheckPatternPredicate, 2, // (Subtarget.getGeneration() == AMDGPUSubtarget::EVERGREEN|| Subtarget.getGeneration() ==AMDGPUSubtarget::NORTHERN_ISLANDS)
/*626*/           OPC_EmitMergeInputChains1_0,
/*627*/           OPC_EmitInteger, MVT::i32, 0, 
/*630*/           OPC_EmitConvertToTarget, 2,
/*632*/           OPC_EmitInteger, MVT::i32, 127|128,31/*4095*/, 
/*636*/           OPC_EmitConvertToTarget, 3,
/*638*/           OPC_EmitInteger, MVT::i32, 64, 
/*641*/           OPC_EmitInteger, MVT::i32, 0, 
/*644*/           OPC_MorphNodeTo, TARGET_VAL(AMDGPU::EG_ExportBuf), 0|OPFL_Chain,
                      0/*#VTs*/, 7/*#Ops*/, 1, 4, 5, 6, 7, 8, 9, 
                  // Src: (intrinsic_void 3410:iPTR, R600_Reg128:v4f32:$src, (imm:i32):$arraybase, 0:i32, (imm:i32):$mask) - Complexity = 19
                  // Dst: (EG_ExportBuf R600_Reg128:v4f32:$src, 0:i32, (imm:i32):$arraybase, 4095:i32, (imm:i32):$mask, 64:i32, 0:i32)
/*657*/         0, /*End of Scope*/
/*658*/       /*Scope*/ 80, /*->739*/
/*659*/         OPC_CheckInteger, 1, 
/*661*/         OPC_MoveParent,
/*662*/         OPC_RecordChild5, // #3 = $mask
/*663*/         OPC_MoveChild, 5,
/*665*/         OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*668*/         OPC_MoveParent,
/*669*/         OPC_Scope, 33, /*->704*/ // 2 children in Scope
/*671*/           OPC_CheckPatternPredicate, 1, // (Subtarget.getGeneration() <= AMDGPUSubtarget::R700)
/*673*/           OPC_EmitMergeInputChains1_0,
/*674*/           OPC_EmitInteger, MVT::i32, 0, 
/*677*/           OPC_EmitConvertToTarget, 2,
/*679*/           OPC_EmitInteger, MVT::i32, 127|128,31/*4095*/, 
/*683*/           OPC_EmitConvertToTarget, 3,
/*685*/           OPC_EmitInteger, MVT::i32, 33, 
/*688*/           OPC_EmitInteger, MVT::i32, 0, 
/*691*/           OPC_MorphNodeTo, TARGET_VAL(AMDGPU::R600_ExportBuf), 0|OPFL_Chain,
                      0/*#VTs*/, 7/*#Ops*/, 1, 4, 5, 6, 7, 8, 9, 
                  // Src: (intrinsic_void 3410:iPTR, R600_Reg128:v4f32:$src, (imm:i32):$arraybase, 1:i32, (imm:i32):$mask) - Complexity = 19
                  // Dst: (R600_ExportBuf R600_Reg128:v4f32:$src, 0:i32, (imm:i32):$arraybase, 4095:i32, (imm:i32):$mask, 33:i32, 0:i32)
/*704*/         /*Scope*/ 33, /*->738*/
/*705*/           OPC_CheckPatternPredicate, 2, // (Subtarget.getGeneration() == AMDGPUSubtarget::EVERGREEN|| Subtarget.getGeneration() ==AMDGPUSubtarget::NORTHERN_ISLANDS)
/*707*/           OPC_EmitMergeInputChains1_0,
/*708*/           OPC_EmitInteger, MVT::i32, 0, 
/*711*/           OPC_EmitConvertToTarget, 2,
/*713*/           OPC_EmitInteger, MVT::i32, 127|128,31/*4095*/, 
/*717*/           OPC_EmitConvertToTarget, 3,
/*719*/           OPC_EmitInteger, MVT::i32, 65, 
/*722*/           OPC_EmitInteger, MVT::i32, 0, 
/*725*/           OPC_MorphNodeTo, TARGET_VAL(AMDGPU::EG_ExportBuf), 0|OPFL_Chain,
                      0/*#VTs*/, 7/*#Ops*/, 1, 4, 5, 6, 7, 8, 9, 
                  // Src: (intrinsic_void 3410:iPTR, R600_Reg128:v4f32:$src, (imm:i32):$arraybase, 1:i32, (imm:i32):$mask) - Complexity = 19
                  // Dst: (EG_ExportBuf R600_Reg128:v4f32:$src, 0:i32, (imm:i32):$arraybase, 4095:i32, (imm:i32):$mask, 65:i32, 0:i32)
/*738*/         0, /*End of Scope*/
/*739*/       /*Scope*/ 80, /*->820*/
/*740*/         OPC_CheckInteger, 2, 
/*742*/         OPC_MoveParent,
/*743*/         OPC_RecordChild5, // #3 = $mask
/*744*/         OPC_MoveChild, 5,
/*746*/         OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*749*/         OPC_MoveParent,
/*750*/         OPC_Scope, 33, /*->785*/ // 2 children in Scope
/*752*/           OPC_CheckPatternPredicate, 1, // (Subtarget.getGeneration() <= AMDGPUSubtarget::R700)
/*754*/           OPC_EmitMergeInputChains1_0,
/*755*/           OPC_EmitInteger, MVT::i32, 0, 
/*758*/           OPC_EmitConvertToTarget, 2,
/*760*/           OPC_EmitInteger, MVT::i32, 127|128,31/*4095*/, 
/*764*/           OPC_EmitConvertToTarget, 3,
/*766*/           OPC_EmitInteger, MVT::i32, 34, 
/*769*/           OPC_EmitInteger, MVT::i32, 0, 
/*772*/           OPC_MorphNodeTo, TARGET_VAL(AMDGPU::R600_ExportBuf), 0|OPFL_Chain,
                      0/*#VTs*/, 7/*#Ops*/, 1, 4, 5, 6, 7, 8, 9, 
                  // Src: (intrinsic_void 3410:iPTR, R600_Reg128:v4f32:$src, (imm:i32):$arraybase, 2:i32, (imm:i32):$mask) - Complexity = 19
                  // Dst: (R600_ExportBuf R600_Reg128:v4f32:$src, 0:i32, (imm:i32):$arraybase, 4095:i32, (imm:i32):$mask, 34:i32, 0:i32)
/*785*/         /*Scope*/ 33, /*->819*/
/*786*/           OPC_CheckPatternPredicate, 2, // (Subtarget.getGeneration() == AMDGPUSubtarget::EVERGREEN|| Subtarget.getGeneration() ==AMDGPUSubtarget::NORTHERN_ISLANDS)
/*788*/           OPC_EmitMergeInputChains1_0,
/*789*/           OPC_EmitInteger, MVT::i32, 0, 
/*792*/           OPC_EmitConvertToTarget, 2,
/*794*/           OPC_EmitInteger, MVT::i32, 127|128,31/*4095*/, 
/*798*/           OPC_EmitConvertToTarget, 3,
/*800*/           OPC_EmitInteger, MVT::i32, 66, 
/*803*/           OPC_EmitInteger, MVT::i32, 0, 
/*806*/           OPC_MorphNodeTo, TARGET_VAL(AMDGPU::EG_ExportBuf), 0|OPFL_Chain,
                      0/*#VTs*/, 7/*#Ops*/, 1, 4, 5, 6, 7, 8, 9, 
                  // Src: (intrinsic_void 3410:iPTR, R600_Reg128:v4f32:$src, (imm:i32):$arraybase, 2:i32, (imm:i32):$mask) - Complexity = 19
                  // Dst: (EG_ExportBuf R600_Reg128:v4f32:$src, 0:i32, (imm:i32):$arraybase, 4095:i32, (imm:i32):$mask, 66:i32, 0:i32)
/*819*/         0, /*End of Scope*/
/*820*/       /*Scope*/ 80, /*->901*/
/*821*/         OPC_CheckInteger, 3, 
/*823*/         OPC_MoveParent,
/*824*/         OPC_RecordChild5, // #3 = $mask
/*825*/         OPC_MoveChild, 5,
/*827*/         OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*830*/         OPC_MoveParent,
/*831*/         OPC_Scope, 33, /*->866*/ // 2 children in Scope
/*833*/           OPC_CheckPatternPredicate, 1, // (Subtarget.getGeneration() <= AMDGPUSubtarget::R700)
/*835*/           OPC_EmitMergeInputChains1_0,
/*836*/           OPC_EmitInteger, MVT::i32, 0, 
/*839*/           OPC_EmitConvertToTarget, 2,
/*841*/           OPC_EmitInteger, MVT::i32, 127|128,31/*4095*/, 
/*845*/           OPC_EmitConvertToTarget, 3,
/*847*/           OPC_EmitInteger, MVT::i32, 35, 
/*850*/           OPC_EmitInteger, MVT::i32, 0, 
/*853*/           OPC_MorphNodeTo, TARGET_VAL(AMDGPU::R600_ExportBuf), 0|OPFL_Chain,
                      0/*#VTs*/, 7/*#Ops*/, 1, 4, 5, 6, 7, 8, 9, 
                  // Src: (intrinsic_void 3410:iPTR, R600_Reg128:v4f32:$src, (imm:i32):$arraybase, 3:i32, (imm:i32):$mask) - Complexity = 19
                  // Dst: (R600_ExportBuf R600_Reg128:v4f32:$src, 0:i32, (imm:i32):$arraybase, 4095:i32, (imm:i32):$mask, 35:i32, 0:i32)
/*866*/         /*Scope*/ 33, /*->900*/
/*867*/           OPC_CheckPatternPredicate, 2, // (Subtarget.getGeneration() == AMDGPUSubtarget::EVERGREEN|| Subtarget.getGeneration() ==AMDGPUSubtarget::NORTHERN_ISLANDS)
/*869*/           OPC_EmitMergeInputChains1_0,
/*870*/           OPC_EmitInteger, MVT::i32, 0, 
/*873*/           OPC_EmitConvertToTarget, 2,
/*875*/           OPC_EmitInteger, MVT::i32, 127|128,31/*4095*/, 
/*879*/           OPC_EmitConvertToTarget, 3,
/*881*/           OPC_EmitInteger, MVT::i32, 67, 
/*884*/           OPC_EmitInteger, MVT::i32, 0, 
/*887*/           OPC_MorphNodeTo, TARGET_VAL(AMDGPU::EG_ExportBuf), 0|OPFL_Chain,
                      0/*#VTs*/, 7/*#Ops*/, 1, 4, 5, 6, 7, 8, 9, 
                  // Src: (intrinsic_void 3410:iPTR, R600_Reg128:v4f32:$src, (imm:i32):$arraybase, 3:i32, (imm:i32):$mask) - Complexity = 19
                  // Dst: (EG_ExportBuf R600_Reg128:v4f32:$src, 0:i32, (imm:i32):$arraybase, 4095:i32, (imm:i32):$mask, 67:i32, 0:i32)
/*900*/         0, /*End of Scope*/
/*901*/       0, /*End of Scope*/
/*902*/     /*Scope*/ 94|128,1/*222*/, /*->1126*/
/*904*/       OPC_CheckInteger, 79|128,26/*3407*/, 
/*907*/       OPC_MoveParent,
/*908*/       OPC_Scope, 107, /*->1017*/ // 2 children in Scope
/*910*/         OPC_MoveChild, 2,
/*912*/         OPC_CheckInteger, 1, 
/*914*/         OPC_MoveParent,
/*915*/         OPC_Scope, 49, /*->966*/ // 2 children in Scope
/*917*/           OPC_CheckPatternPredicate, 1, // (Subtarget.getGeneration() <= AMDGPUSubtarget::R700)
/*919*/           OPC_EmitMergeInputChains1_0,
/*920*/           OPC_EmitNode, TARGET_VAL(TargetOpcode::IMPLICIT_DEF), 0,
                      1/*#VTs*/, MVT::v4f32, 0/*#Ops*/,  // Results = #1
/*927*/           OPC_EmitInteger, MVT::i32, 1, 
/*930*/           OPC_EmitInteger, MVT::i32, 60, 
/*933*/           OPC_EmitInteger, MVT::i32, 7, 
/*936*/           OPC_EmitInteger, MVT::i32, 7, 
/*939*/           OPC_EmitInteger, MVT::i32, 7, 
/*942*/           OPC_EmitInteger, MVT::i32, 7, 
/*945*/           OPC_EmitInteger, MVT::i32, 39, 
/*948*/           OPC_EmitInteger, MVT::i32, 0, 
/*951*/           OPC_MorphNodeTo, TARGET_VAL(AMDGPU::R600_ExportSwz), 0|OPFL_Chain,
                      0/*#VTs*/, 9/*#Ops*/, 1, 2, 3, 4, 5, 6, 7, 8, 9, 
                  // Src: (intrinsic_void 3407:iPTR, 1:i32) - Complexity = 13
                  // Dst: (R600_ExportSwz (IMPLICIT_DEF:v4f32), 1:i32, 60:i32, 7:i32, 7:i32, 7:i32, 7:i32, 39:i32, 0:i32)
/*966*/         /*Scope*/ 49, /*->1016*/
/*967*/           OPC_CheckPatternPredicate, 2, // (Subtarget.getGeneration() == AMDGPUSubtarget::EVERGREEN|| Subtarget.getGeneration() ==AMDGPUSubtarget::NORTHERN_ISLANDS)
/*969*/           OPC_EmitMergeInputChains1_0,
/*970*/           OPC_EmitNode, TARGET_VAL(TargetOpcode::IMPLICIT_DEF), 0,
                      1/*#VTs*/, MVT::v4f32, 0/*#Ops*/,  // Results = #1
/*977*/           OPC_EmitInteger, MVT::i32, 1, 
/*980*/           OPC_EmitInteger, MVT::i32, 60, 
/*983*/           OPC_EmitInteger, MVT::i32, 7, 
/*986*/           OPC_EmitInteger, MVT::i32, 7, 
/*989*/           OPC_EmitInteger, MVT::i32, 7, 
/*992*/           OPC_EmitInteger, MVT::i32, 7, 
/*995*/           OPC_EmitInteger, MVT::i32, 83, 
/*998*/           OPC_EmitInteger, MVT::i32, 0, 
/*1001*/          OPC_MorphNodeTo, TARGET_VAL(AMDGPU::EG_ExportSwz), 0|OPFL_Chain,
                      0/*#VTs*/, 9/*#Ops*/, 1, 2, 3, 4, 5, 6, 7, 8, 9, 
                  // Src: (intrinsic_void 3407:iPTR, 1:i32) - Complexity = 13
                  // Dst: (EG_ExportSwz (IMPLICIT_DEF:v4f32), 1:i32, 60:i32, 7:i32, 7:i32, 7:i32, 7:i32, 83:i32, 0:i32)
/*1016*/        0, /*End of Scope*/
/*1017*/      /*Scope*/ 107, /*->1125*/
/*1018*/        OPC_RecordChild2, // #1 = $type
/*1019*/        OPC_MoveChild, 2,
/*1021*/        OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*1024*/        OPC_MoveParent,
/*1025*/        OPC_Scope, 48, /*->1075*/ // 2 children in Scope
/*1027*/          OPC_CheckPatternPredicate, 1, // (Subtarget.getGeneration() <= AMDGPUSubtarget::R700)
/*1029*/          OPC_EmitMergeInputChains1_0,
/*1030*/          OPC_EmitNode, TARGET_VAL(TargetOpcode::IMPLICIT_DEF), 0,
                      1/*#VTs*/, MVT::v4f32, 0/*#Ops*/,  // Results = #2
/*1037*/          OPC_EmitConvertToTarget, 1,
/*1039*/          OPC_EmitInteger, MVT::i32, 0, 
/*1042*/          OPC_EmitInteger, MVT::i32, 7, 
/*1045*/          OPC_EmitInteger, MVT::i32, 7, 
/*1048*/          OPC_EmitInteger, MVT::i32, 7, 
/*1051*/          OPC_EmitInteger, MVT::i32, 7, 
/*1054*/          OPC_EmitInteger, MVT::i32, 39, 
/*1057*/          OPC_EmitInteger, MVT::i32, 0, 
/*1060*/          OPC_MorphNodeTo, TARGET_VAL(AMDGPU::R600_ExportSwz), 0|OPFL_Chain,
                      0/*#VTs*/, 9/*#Ops*/, 2, 3, 4, 5, 6, 7, 8, 9, 10, 
                  // Src: (intrinsic_void 3407:iPTR, (imm:i32):$type) - Complexity = 11
                  // Dst: (R600_ExportSwz (IMPLICIT_DEF:v4f32), (imm:i32):$type, 0:i32, 7:i32, 7:i32, 7:i32, 7:i32, 39:i32, 0:i32)
/*1075*/        /*Scope*/ 48, /*->1124*/
/*1076*/          OPC_CheckPatternPredicate, 2, // (Subtarget.getGeneration() == AMDGPUSubtarget::EVERGREEN|| Subtarget.getGeneration() ==AMDGPUSubtarget::NORTHERN_ISLANDS)
/*1078*/          OPC_EmitMergeInputChains1_0,
/*1079*/          OPC_EmitNode, TARGET_VAL(TargetOpcode::IMPLICIT_DEF), 0,
                      1/*#VTs*/, MVT::v4f32, 0/*#Ops*/,  // Results = #2
/*1086*/          OPC_EmitConvertToTarget, 1,
/*1088*/          OPC_EmitInteger, MVT::i32, 0, 
/*1091*/          OPC_EmitInteger, MVT::i32, 7, 
/*1094*/          OPC_EmitInteger, MVT::i32, 7, 
/*1097*/          OPC_EmitInteger, MVT::i32, 7, 
/*1100*/          OPC_EmitInteger, MVT::i32, 7, 
/*1103*/          OPC_EmitInteger, MVT::i32, 83, 
/*1106*/          OPC_EmitInteger, MVT::i32, 0, 
/*1109*/          OPC_MorphNodeTo, TARGET_VAL(AMDGPU::EG_ExportSwz), 0|OPFL_Chain,
                      0/*#VTs*/, 9/*#Ops*/, 2, 3, 4, 5, 6, 7, 8, 9, 10, 
                  // Src: (intrinsic_void 3407:iPTR, (imm:i32):$type) - Complexity = 11
                  // Dst: (EG_ExportSwz (IMPLICIT_DEF:v4f32), (imm:i32):$type, 0:i32, 7:i32, 7:i32, 7:i32, 7:i32, 83:i32, 0:i32)
/*1124*/        0, /*End of Scope*/
/*1125*/      0, /*End of Scope*/
/*1126*/    /*Scope*/ 26, /*->1153*/
/*1127*/      OPC_CheckInteger, 82|128,25/*3282*/, 
/*1130*/      OPC_MoveParent,
/*1131*/      OPC_Scope, 9, /*->1142*/ // 2 children in Scope
/*1133*/        OPC_CheckPatternPredicate, 2, // (Subtarget.getGeneration() == AMDGPUSubtarget::EVERGREEN|| Subtarget.getGeneration() ==AMDGPUSubtarget::NORTHERN_ISLANDS)
/*1135*/        OPC_EmitMergeInputChains1_0,
/*1136*/        OPC_MorphNodeTo, TARGET_VAL(AMDGPU::GROUP_BARRIER), 0|OPFL_Chain,
                    0/*#VTs*/, 0/*#Ops*/, 
                // Src: (intrinsic_void 3282:iPTR) - Complexity = 8
                // Dst: (GROUP_BARRIER)
/*1142*/      /*Scope*/ 9, /*->1152*/
/*1143*/        OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*1145*/        OPC_EmitMergeInputChains1_0,
/*1146*/        OPC_MorphNodeTo, TARGET_VAL(AMDGPU::S_BARRIER), 0|OPFL_Chain,
                    0/*#VTs*/, 0/*#Ops*/, 
                // Src: (intrinsic_void 3282:iPTR) - Complexity = 8
                // Dst: (S_BARRIER)
/*1152*/      0, /*End of Scope*/
/*1153*/    /*Scope*/ 23, /*->1177*/
/*1154*/      OPC_CheckInteger, 103|128,26/*3431*/, 
/*1157*/      OPC_MoveParent,
/*1158*/      OPC_RecordChild2, // #1 = $saved
/*1159*/      OPC_RecordChild3, // #2 = $target
/*1160*/      OPC_MoveChild, 3,
/*1162*/      OPC_CheckOpcode, TARGET_VAL(ISD::BasicBlock),
/*1165*/      OPC_MoveParent,
/*1166*/      OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*1168*/      OPC_EmitMergeInputChains1_0,
/*1169*/      OPC_MorphNodeTo, TARGET_VAL(AMDGPU::SI_LOOP), 0|OPFL_Chain,
                  0/*#VTs*/, 2/*#Ops*/, 1, 2, 
              // Src: (intrinsic_void 3431:iPTR, i64:i64:$saved, (bb:Other):$target) - Complexity = 8
              // Dst: (SI_LOOP i64:i64:$saved, (bb:Other):$target)
/*1177*/    /*Scope*/ 15, /*->1193*/
/*1178*/      OPC_CheckInteger, 95|128,26/*3423*/, 
/*1181*/      OPC_MoveParent,
/*1182*/      OPC_RecordChild2, // #1 = $saved
/*1183*/      OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*1185*/      OPC_EmitMergeInputChains1_0,
/*1186*/      OPC_MorphNodeTo, TARGET_VAL(AMDGPU::SI_END_CF), 0|OPFL_Chain,
                  0/*#VTs*/, 1/*#Ops*/, 1, 
              // Src: (intrinsic_void 3423:iPTR, i64:i64:$saved) - Complexity = 8
              // Dst: (SI_END_CF i64:i64:$saved)
/*1193*/    /*Scope*/ 3|128,1/*131*/, /*->1326*/
/*1195*/      OPC_CheckInteger, 91|128,25/*3291*/, 
/*1198*/      OPC_MoveParent,
/*1199*/      OPC_RecordChild2, // #1 = $src
/*1200*/      OPC_Scope, 10, /*->1212*/ // 2 children in Scope
/*1202*/        OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*1204*/        OPC_EmitMergeInputChains1_0,
/*1205*/        OPC_MorphNodeTo, TARGET_VAL(AMDGPU::SI_KILL), 0|OPFL_Chain,
                    0/*#VTs*/, 1/*#Ops*/, 1, 
                // Src: (intrinsic_void 3291:iPTR, f32:f32:$src) - Complexity = 8
                // Dst: (SI_KILL f32:f32:$src)
/*1212*/      /*Scope*/ 112, /*->1325*/
/*1213*/        OPC_CheckPatternPredicate, 3, // (Subtarget.getGeneration() <= AMDGPUSubtarget::NORTHERN_ISLANDS)
/*1215*/        OPC_EmitMergeInputChains1_0,
/*1216*/        OPC_EmitInteger, MVT::i32, 0, 
/*1219*/        OPC_EmitInteger, MVT::i32, 0, 
/*1222*/        OPC_EmitInteger, MVT::i32, 1, 
/*1225*/        OPC_EmitInteger, MVT::i32, 0, 
/*1228*/        OPC_EmitInteger, MVT::i32, 0, 
/*1231*/        OPC_EmitInteger, MVT::i32, 0, 
/*1234*/        OPC_EmitRegister, MVT::f32, AMDGPU::ZERO,
/*1237*/        OPC_EmitInteger, MVT::i32, 0, 
/*1240*/        OPC_EmitInteger, MVT::i32, 0, 
/*1243*/        OPC_EmitInteger, MVT::i32, 0, 
/*1246*/        OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*1258*/        OPC_EmitInteger, MVT::i32, 0, 
/*1261*/        OPC_EmitInteger, MVT::i32, 0, 
/*1264*/        OPC_EmitInteger, MVT::i32, 0, 
/*1267*/        OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*1279*/        OPC_EmitInteger, MVT::i32, 1, 
/*1282*/        OPC_EmitRegister, MVT::i32, AMDGPU::PRED_SEL_OFF,
/*1285*/        OPC_EmitInteger, MVT::i32, 0, 
/*1288*/        OPC_EmitInteger, MVT::i32, 0, 
/*1291*/        OPC_EmitNode, TARGET_VAL(AMDGPU::KILLGT), 0|OPFL_Chain,
                    1/*#VTs*/, MVT::i32, 20/*#Ops*/, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 1, 13, 14, 15, 16, 17, 18, 19, 20,  // Results = #21
/*1318*/        OPC_MorphNodeTo, TARGET_VAL(AMDGPU::MASK_WRITE), 0|OPFL_Chain,
                    0/*#VTs*/, 1/*#Ops*/, 21, 
                // Src: (intrinsic_void 3291:iPTR, f32:f32:$src0) - Complexity = 8
                // Dst: (MASK_WRITE (KILLGT:i32 ZERO:f32, ?:f32:$src0))
/*1325*/      0, /*End of Scope*/
/*1326*/    /*Scope*/ 20|128,1/*148*/, /*->1476*/
/*1328*/      OPC_CheckInteger, 92|128,25/*3292*/, 
/*1331*/      OPC_MoveParent,
/*1332*/      OPC_Scope, 25, /*->1359*/ // 2 children in Scope
/*1334*/        OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*1336*/        OPC_EmitMergeInputChains1_0,
/*1337*/        OPC_EmitInteger, MVT::i32, 0|128,0|128,0|128,124|128,11/*3212836864*/, 
/*1344*/        OPC_EmitNode, TARGET_VAL(AMDGPU::V_MOV_B32_e32), 0,
                    1/*#VTs*/, MVT::i32, 1/*#Ops*/, 1,  // Results = #2
/*1352*/        OPC_MorphNodeTo, TARGET_VAL(AMDGPU::SI_KILL), 0|OPFL_Chain,
                    0/*#VTs*/, 1/*#Ops*/, 2, 
                // Src: (intrinsic_void 3292:iPTR) - Complexity = 8
                // Dst: (SI_KILL (V_MOV_B32_e32:i32 3212836864:i32))
/*1359*/      /*Scope*/ 115, /*->1475*/
/*1360*/        OPC_CheckPatternPredicate, 3, // (Subtarget.getGeneration() <= AMDGPUSubtarget::NORTHERN_ISLANDS)
/*1362*/        OPC_EmitMergeInputChains1_0,
/*1363*/        OPC_EmitInteger, MVT::i32, 0, 
/*1366*/        OPC_EmitInteger, MVT::i32, 0, 
/*1369*/        OPC_EmitInteger, MVT::i32, 1, 
/*1372*/        OPC_EmitInteger, MVT::i32, 0, 
/*1375*/        OPC_EmitInteger, MVT::i32, 0, 
/*1378*/        OPC_EmitInteger, MVT::i32, 0, 
/*1381*/        OPC_EmitRegister, MVT::f32, AMDGPU::ONE,
/*1384*/        OPC_EmitInteger, MVT::i32, 0, 
/*1387*/        OPC_EmitInteger, MVT::i32, 0, 
/*1390*/        OPC_EmitInteger, MVT::i32, 0, 
/*1393*/        OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*1405*/        OPC_EmitRegister, MVT::f32, AMDGPU::ZERO,
/*1408*/        OPC_EmitInteger, MVT::i32, 0, 
/*1411*/        OPC_EmitInteger, MVT::i32, 0, 
/*1414*/        OPC_EmitInteger, MVT::i32, 0, 
/*1417*/        OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*1429*/        OPC_EmitInteger, MVT::i32, 1, 
/*1432*/        OPC_EmitRegister, MVT::i32, AMDGPU::PRED_SEL_OFF,
/*1435*/        OPC_EmitInteger, MVT::i32, 0, 
/*1438*/        OPC_EmitInteger, MVT::i32, 0, 
/*1441*/        OPC_EmitNode, TARGET_VAL(AMDGPU::KILLGT), 0|OPFL_Chain,
                    1/*#VTs*/, MVT::i32, 20/*#Ops*/, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20,  // Results = #21
/*1468*/        OPC_MorphNodeTo, TARGET_VAL(AMDGPU::MASK_WRITE), 0|OPFL_Chain,
                    0/*#VTs*/, 1/*#Ops*/, 21, 
                // Src: (intrinsic_void 3292:iPTR) - Complexity = 8
                // Dst: (MASK_WRITE (KILLGT:i32 ONE:f32, ZERO:f32))
/*1475*/      0, /*End of Scope*/
/*1476*/    /*Scope*/ 5|128,1/*133*/, /*->1611*/
/*1478*/      OPC_CheckInteger, 80|128,26/*3408*/, 
/*1481*/      OPC_MoveParent,
/*1482*/      OPC_RecordChild2, // #1 = $reg
/*1483*/      OPC_Scope, 62, /*->1547*/ // 2 children in Scope
/*1485*/        OPC_CheckPatternPredicate, 1, // (Subtarget.getGeneration() <= AMDGPUSubtarget::R700)
/*1487*/        OPC_EmitMergeInputChains1_0,
/*1488*/        OPC_EmitNode, TARGET_VAL(TargetOpcode::IMPLICIT_DEF), 0,
                    1/*#VTs*/, MVT::v4f32, 0/*#Ops*/,  // Results = #2
/*1495*/        OPC_EmitInteger, MVT::i32, AMDGPU::sub0,
/*1498*/        OPC_EmitNode, TARGET_VAL(TargetOpcode::INSERT_SUBREG), 0,
                    1/*#VTs*/, MVT::v4f32, 3/*#Ops*/, 2, 1, 3,  // Results = #4
/*1508*/        OPC_EmitInteger, MVT::i32, 0, 
/*1511*/        OPC_EmitInteger, MVT::i32, 61, 
/*1514*/        OPC_EmitInteger, MVT::i32, 0, 
/*1517*/        OPC_EmitInteger, MVT::i32, 7, 
/*1520*/        OPC_EmitInteger, MVT::i32, 7, 
/*1523*/        OPC_EmitInteger, MVT::i32, 7, 
/*1526*/        OPC_EmitInteger, MVT::i32, 39, 
/*1529*/        OPC_EmitInteger, MVT::i32, 0, 
/*1532*/        OPC_MorphNodeTo, TARGET_VAL(AMDGPU::R600_ExportSwz), 0|OPFL_Chain,
                    0/*#VTs*/, 9/*#Ops*/, 4, 5, 6, 7, 8, 9, 10, 11, 12, 
                // Src: (intrinsic_void 3408:iPTR, R600_Reg32:f32:$reg) - Complexity = 8
                // Dst: (R600_ExportSwz (INSERT_SUBREG:v4f32 (IMPLICIT_DEF:v4f32), R600_Reg32:f32:$reg, sub0:i32), 0:i32, 61:i32, 0:i32, 7:i32, 7:i32, 7:i32, 39:i32, 0:i32)
/*1547*/      /*Scope*/ 62, /*->1610*/
/*1548*/        OPC_CheckPatternPredicate, 2, // (Subtarget.getGeneration() == AMDGPUSubtarget::EVERGREEN|| Subtarget.getGeneration() ==AMDGPUSubtarget::NORTHERN_ISLANDS)
/*1550*/        OPC_EmitMergeInputChains1_0,
/*1551*/        OPC_EmitNode, TARGET_VAL(TargetOpcode::IMPLICIT_DEF), 0,
                    1/*#VTs*/, MVT::v4f32, 0/*#Ops*/,  // Results = #2
/*1558*/        OPC_EmitInteger, MVT::i32, AMDGPU::sub0,
/*1561*/        OPC_EmitNode, TARGET_VAL(TargetOpcode::INSERT_SUBREG), 0,
                    1/*#VTs*/, MVT::v4f32, 3/*#Ops*/, 2, 1, 3,  // Results = #4
/*1571*/        OPC_EmitInteger, MVT::i32, 0, 
/*1574*/        OPC_EmitInteger, MVT::i32, 61, 
/*1577*/        OPC_EmitInteger, MVT::i32, 0, 
/*1580*/        OPC_EmitInteger, MVT::i32, 7, 
/*1583*/        OPC_EmitInteger, MVT::i32, 7, 
/*1586*/        OPC_EmitInteger, MVT::i32, 7, 
/*1589*/        OPC_EmitInteger, MVT::i32, 83, 
/*1592*/        OPC_EmitInteger, MVT::i32, 0, 
/*1595*/        OPC_MorphNodeTo, TARGET_VAL(AMDGPU::EG_ExportSwz), 0|OPFL_Chain,
                    0/*#VTs*/, 9/*#Ops*/, 4, 5, 6, 7, 8, 9, 10, 11, 12, 
                // Src: (intrinsic_void 3408:iPTR, R600_Reg32:f32:$reg) - Complexity = 8
                // Dst: (EG_ExportSwz (INSERT_SUBREG:v4f32 (IMPLICIT_DEF:v4f32), R600_Reg32:f32:$reg, sub0:i32), 0:i32, 61:i32, 0:i32, 7:i32, 7:i32, 7:i32, 83:i32, 0:i32)
/*1610*/      0, /*End of Scope*/
/*1611*/    /*Scope*/ 5|128,1/*133*/, /*->1746*/
/*1613*/      OPC_CheckInteger, 81|128,26/*3409*/, 
/*1616*/      OPC_MoveParent,
/*1617*/      OPC_RecordChild2, // #1 = $reg
/*1618*/      OPC_Scope, 62, /*->1682*/ // 2 children in Scope
/*1620*/        OPC_CheckPatternPredicate, 1, // (Subtarget.getGeneration() <= AMDGPUSubtarget::R700)
/*1622*/        OPC_EmitMergeInputChains1_0,
/*1623*/        OPC_EmitNode, TARGET_VAL(TargetOpcode::IMPLICIT_DEF), 0,
                    1/*#VTs*/, MVT::v4f32, 0/*#Ops*/,  // Results = #2
/*1630*/        OPC_EmitInteger, MVT::i32, AMDGPU::sub0,
/*1633*/        OPC_EmitNode, TARGET_VAL(TargetOpcode::INSERT_SUBREG), 0,
                    1/*#VTs*/, MVT::v4f32, 3/*#Ops*/, 2, 1, 3,  // Results = #4
/*1643*/        OPC_EmitInteger, MVT::i32, 0, 
/*1646*/        OPC_EmitInteger, MVT::i32, 61, 
/*1649*/        OPC_EmitInteger, MVT::i32, 7, 
/*1652*/        OPC_EmitInteger, MVT::i32, 0, 
/*1655*/        OPC_EmitInteger, MVT::i32, 7, 
/*1658*/        OPC_EmitInteger, MVT::i32, 7, 
/*1661*/        OPC_EmitInteger, MVT::i32, 39, 
/*1664*/        OPC_EmitInteger, MVT::i32, 0, 
/*1667*/        OPC_MorphNodeTo, TARGET_VAL(AMDGPU::R600_ExportSwz), 0|OPFL_Chain,
                    0/*#VTs*/, 9/*#Ops*/, 4, 5, 6, 7, 8, 9, 10, 11, 12, 
                // Src: (intrinsic_void 3409:iPTR, R600_Reg32:f32:$reg) - Complexity = 8
                // Dst: (R600_ExportSwz (INSERT_SUBREG:v4f32 (IMPLICIT_DEF:v4f32), R600_Reg32:f32:$reg, sub0:i32), 0:i32, 61:i32, 7:i32, 0:i32, 7:i32, 7:i32, 39:i32, 0:i32)
/*1682*/      /*Scope*/ 62, /*->1745*/
/*1683*/        OPC_CheckPatternPredicate, 2, // (Subtarget.getGeneration() == AMDGPUSubtarget::EVERGREEN|| Subtarget.getGeneration() ==AMDGPUSubtarget::NORTHERN_ISLANDS)
/*1685*/        OPC_EmitMergeInputChains1_0,
/*1686*/        OPC_EmitNode, TARGET_VAL(TargetOpcode::IMPLICIT_DEF), 0,
                    1/*#VTs*/, MVT::v4f32, 0/*#Ops*/,  // Results = #2
/*1693*/        OPC_EmitInteger, MVT::i32, AMDGPU::sub0,
/*1696*/        OPC_EmitNode, TARGET_VAL(TargetOpcode::INSERT_SUBREG), 0,
                    1/*#VTs*/, MVT::v4f32, 3/*#Ops*/, 2, 1, 3,  // Results = #4
/*1706*/        OPC_EmitInteger, MVT::i32, 0, 
/*1709*/        OPC_EmitInteger, MVT::i32, 61, 
/*1712*/        OPC_EmitInteger, MVT::i32, 7, 
/*1715*/        OPC_EmitInteger, MVT::i32, 0, 
/*1718*/        OPC_EmitInteger, MVT::i32, 7, 
/*1721*/        OPC_EmitInteger, MVT::i32, 7, 
/*1724*/        OPC_EmitInteger, MVT::i32, 83, 
/*1727*/        OPC_EmitInteger, MVT::i32, 0, 
/*1730*/        OPC_MorphNodeTo, TARGET_VAL(AMDGPU::EG_ExportSwz), 0|OPFL_Chain,
                    0/*#VTs*/, 9/*#Ops*/, 4, 5, 6, 7, 8, 9, 10, 11, 12, 
                // Src: (intrinsic_void 3409:iPTR, R600_Reg32:f32:$reg) - Complexity = 8
                // Dst: (EG_ExportSwz (INSERT_SUBREG:v4f32 (IMPLICIT_DEF:v4f32), R600_Reg32:f32:$reg, sub0:i32), 0:i32, 61:i32, 7:i32, 0:i32, 7:i32, 7:i32, 83:i32, 0:i32)
/*1745*/      0, /*End of Scope*/
/*1746*/    0, /*End of Scope*/
/*1747*/  /*SwitchOpcode*/ 6|128,1/*134*/,  TARGET_VAL(AMDGPUISD::EXPORT),// ->1885
/*1751*/    OPC_RecordNode,   // #0 = 'EXPORT' chained node
/*1752*/    OPC_RecordChild1, // #1 = $src
/*1753*/    OPC_CheckChild1Type, MVT::v4f32,
/*1755*/    OPC_RecordChild2, // #2 = $base
/*1756*/    OPC_MoveChild, 2,
/*1758*/    OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*1761*/    OPC_CheckType, MVT::i32,
/*1763*/    OPC_MoveParent,
/*1764*/    OPC_RecordChild3, // #3 = $type
/*1765*/    OPC_MoveChild, 3,
/*1767*/    OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*1770*/    OPC_CheckType, MVT::i32,
/*1772*/    OPC_MoveParent,
/*1773*/    OPC_RecordChild4, // #4 = $swz_x
/*1774*/    OPC_MoveChild, 4,
/*1776*/    OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*1779*/    OPC_CheckType, MVT::i32,
/*1781*/    OPC_MoveParent,
/*1782*/    OPC_RecordChild5, // #5 = $swz_y
/*1783*/    OPC_MoveChild, 5,
/*1785*/    OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*1788*/    OPC_CheckType, MVT::i32,
/*1790*/    OPC_MoveParent,
/*1791*/    OPC_RecordChild6, // #6 = $swz_z
/*1792*/    OPC_MoveChild, 6,
/*1794*/    OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*1797*/    OPC_CheckType, MVT::i32,
/*1799*/    OPC_MoveParent,
/*1800*/    OPC_RecordChild7, // #7 = $swz_w
/*1801*/    OPC_MoveChild, 7,
/*1803*/    OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*1806*/    OPC_CheckType, MVT::i32,
/*1808*/    OPC_MoveParent,
/*1809*/    OPC_Scope, 36, /*->1847*/ // 2 children in Scope
/*1811*/      OPC_CheckPatternPredicate, 1, // (Subtarget.getGeneration() <= AMDGPUSubtarget::R700)
/*1813*/      OPC_EmitMergeInputChains1_0,
/*1814*/      OPC_EmitConvertToTarget, 3,
/*1816*/      OPC_EmitConvertToTarget, 2,
/*1818*/      OPC_EmitConvertToTarget, 4,
/*1820*/      OPC_EmitConvertToTarget, 5,
/*1822*/      OPC_EmitConvertToTarget, 6,
/*1824*/      OPC_EmitConvertToTarget, 7,
/*1826*/      OPC_EmitInteger, MVT::i32, 39, 
/*1829*/      OPC_EmitInteger, MVT::i32, 0, 
/*1832*/      OPC_MorphNodeTo, TARGET_VAL(AMDGPU::R600_ExportSwz), 0|OPFL_Chain,
                  0/*#VTs*/, 9/*#Ops*/, 1, 8, 9, 10, 11, 12, 13, 14, 15, 
              // Src: (EXPORT R600_Reg128:v4f32:$src, (imm:i32):$base, (imm:i32):$type, (imm:i32):$swz_x, (imm:i32):$swz_y, (imm:i32):$swz_z, (imm:i32):$swz_w) - Complexity = 21
              // Dst: (R600_ExportSwz R600_Reg128:v4f32:$src, (imm:i32):$type, (imm:i32):$base, (imm:i32):$swz_x, (imm:i32):$swz_y, (imm:i32):$swz_z, (imm:i32):$swz_w, 39:i32, 0:i32)
/*1847*/    /*Scope*/ 36, /*->1884*/
/*1848*/      OPC_CheckPatternPredicate, 2, // (Subtarget.getGeneration() == AMDGPUSubtarget::EVERGREEN|| Subtarget.getGeneration() ==AMDGPUSubtarget::NORTHERN_ISLANDS)
/*1850*/      OPC_EmitMergeInputChains1_0,
/*1851*/      OPC_EmitConvertToTarget, 3,
/*1853*/      OPC_EmitConvertToTarget, 2,
/*1855*/      OPC_EmitConvertToTarget, 4,
/*1857*/      OPC_EmitConvertToTarget, 5,
/*1859*/      OPC_EmitConvertToTarget, 6,
/*1861*/      OPC_EmitConvertToTarget, 7,
/*1863*/      OPC_EmitInteger, MVT::i32, 83, 
/*1866*/      OPC_EmitInteger, MVT::i32, 0, 
/*1869*/      OPC_MorphNodeTo, TARGET_VAL(AMDGPU::EG_ExportSwz), 0|OPFL_Chain,
                  0/*#VTs*/, 9/*#Ops*/, 1, 8, 9, 10, 11, 12, 13, 14, 15, 
              // Src: (EXPORT R600_Reg128:v4f32:$src, (imm:i32):$base, (imm:i32):$type, (imm:i32):$swz_x, (imm:i32):$swz_y, (imm:i32):$swz_z, (imm:i32):$swz_w) - Complexity = 21
              // Dst: (EG_ExportSwz R600_Reg128:v4f32:$src, (imm:i32):$type, (imm:i32):$base, (imm:i32):$swz_x, (imm:i32):$swz_y, (imm:i32):$swz_z, (imm:i32):$swz_w, 83:i32, 0:i32)
/*1884*/    0, /*End of Scope*/
/*1885*/  /*SwitchOpcode*/ 82|128,5/*722*/,  TARGET_VAL(ISD::ADD),// ->2611
/*1889*/    OPC_Scope, 40|128,2/*296*/, /*->2188*/ // 2 children in Scope
/*1892*/      OPC_MoveChild, 0,
/*1894*/      OPC_CheckOpcode, TARGET_VAL(ISD::MUL),
/*1897*/      OPC_RecordChild0, // #0 = $src0
/*1898*/      OPC_RecordChild1, // #1 = $src1
/*1899*/      OPC_MoveParent,
/*1900*/      OPC_RecordChild1, // #2 = $src2
/*1901*/      OPC_CheckType, MVT::i32,
/*1903*/      OPC_Scope, 105, /*->2010*/ // 3 children in Scope
/*1905*/        OPC_CheckPatternPredicate, 2, // (Subtarget.getGeneration() == AMDGPUSubtarget::EVERGREEN|| Subtarget.getGeneration() ==AMDGPUSubtarget::NORTHERN_ISLANDS)
/*1907*/        OPC_CheckComplexPat, /*CP*/0, /*#*/0, // SelectU24:$src0 #3
/*1910*/        OPC_CheckComplexPat, /*CP*/0, /*#*/1, // SelectU24:$src1 #4
/*1913*/        OPC_EmitInteger, MVT::i32, 0, 
/*1916*/        OPC_EmitInteger, MVT::i32, 0, 
/*1919*/        OPC_EmitInteger, MVT::i32, 0, 
/*1922*/        OPC_EmitInteger, MVT::i32, 0, 
/*1925*/        OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*1937*/        OPC_EmitInteger, MVT::i32, 0, 
/*1940*/        OPC_EmitInteger, MVT::i32, 0, 
/*1943*/        OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*1955*/        OPC_EmitInteger, MVT::i32, 0, 
/*1958*/        OPC_EmitInteger, MVT::i32, 0, 
/*1961*/        OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*1973*/        OPC_EmitInteger, MVT::i32, 1, 
/*1976*/        OPC_EmitRegister, MVT::i32, AMDGPU::PRED_SEL_OFF,
/*1979*/        OPC_EmitInteger, MVT::i32, 0, 
/*1982*/        OPC_EmitInteger, MVT::i32, 0, 
/*1985*/        OPC_MorphNodeTo, TARGET_VAL(AMDGPU::MULADD_UINT24_eg), 0,
                    1/*#VTs*/, MVT::i32, 18/*#Ops*/, 5, 6, 3, 7, 8, 9, 4, 10, 11, 12, 2, 13, 14, 15, 16, 17, 18, 19, 
                // Src: (add:i32 (mul:i32 U24:i32:$src0, U24:i32:$src1), i32:i32:$src2) - Complexity = 18
                // Dst: (MULADD_UINT24_eg:i32 U24:i32:$src0, U24:i32:$src1, i32:i32:$src2)
/*2010*/      /*Scope*/ 105, /*->2116*/
/*2011*/        OPC_CheckPatternPredicate, 4, // (Subtarget.hasCaymanISA())
/*2013*/        OPC_CheckComplexPat, /*CP*/1, /*#*/0, // SelectI24:$src0 #3
/*2016*/        OPC_CheckComplexPat, /*CP*/1, /*#*/1, // SelectI24:$src1 #4
/*2019*/        OPC_EmitInteger, MVT::i32, 0, 
/*2022*/        OPC_EmitInteger, MVT::i32, 0, 
/*2025*/        OPC_EmitInteger, MVT::i32, 0, 
/*2028*/        OPC_EmitInteger, MVT::i32, 0, 
/*2031*/        OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*2043*/        OPC_EmitInteger, MVT::i32, 0, 
/*2046*/        OPC_EmitInteger, MVT::i32, 0, 
/*2049*/        OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*2061*/        OPC_EmitInteger, MVT::i32, 0, 
/*2064*/        OPC_EmitInteger, MVT::i32, 0, 
/*2067*/        OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*2079*/        OPC_EmitInteger, MVT::i32, 1, 
/*2082*/        OPC_EmitRegister, MVT::i32, AMDGPU::PRED_SEL_OFF,
/*2085*/        OPC_EmitInteger, MVT::i32, 0, 
/*2088*/        OPC_EmitInteger, MVT::i32, 0, 
/*2091*/        OPC_MorphNodeTo, TARGET_VAL(AMDGPU::MULADD_INT24_cm), 0,
                    1/*#VTs*/, MVT::i32, 18/*#Ops*/, 5, 6, 3, 7, 8, 9, 4, 10, 11, 12, 2, 13, 14, 15, 16, 17, 18, 19, 
                // Src: (add:i32 (mul:i32 I24:i32:$src0, I24:i32:$src1), i32:i32:$src2) - Complexity = 18
                // Dst: (MULADD_INT24_cm:i32 I24:i32:$src0, I24:i32:$src1, i32:i32:$src2)
/*2116*/      /*Scope*/ 70, /*->2187*/
/*2117*/        OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*2119*/        OPC_Scope, 32, /*->2153*/ // 2 children in Scope
/*2121*/          OPC_CheckComplexPat, /*CP*/1, /*#*/0, // SelectI24:$src0 #3
/*2124*/          OPC_CheckComplexPat, /*CP*/1, /*#*/1, // SelectI24:$src1 #4
/*2127*/          OPC_EmitInteger, MVT::i32, 0, 
/*2130*/          OPC_EmitInteger, MVT::i32, 0, 
/*2133*/          OPC_EmitInteger, MVT::i32, 0, 
/*2136*/          OPC_EmitInteger, MVT::i32, 0, 
/*2139*/          OPC_MorphNodeTo, TARGET_VAL(AMDGPU::V_MAD_I32_I24), 0,
                      1/*#VTs*/, MVT::i32, 7/*#Ops*/, 3, 4, 2, 5, 6, 7, 8, 
                  // Src: (add:i32 (mul:i32 I24:i32:$src0, I24:i32:$src1), i32:i32:$src2) - Complexity = 18
                  // Dst: (V_MAD_I32_I24:i32 I24:i32:$src0, I24:i32:$src1, i32:i32:$src2)
/*2153*/        /*Scope*/ 32, /*->2186*/
/*2154*/          OPC_CheckComplexPat, /*CP*/0, /*#*/0, // SelectU24:$src0 #3
/*2157*/          OPC_CheckComplexPat, /*CP*/0, /*#*/1, // SelectU24:$src1 #4
/*2160*/          OPC_EmitInteger, MVT::i32, 0, 
/*2163*/          OPC_EmitInteger, MVT::i32, 0, 
/*2166*/          OPC_EmitInteger, MVT::i32, 0, 
/*2169*/          OPC_EmitInteger, MVT::i32, 0, 
/*2172*/          OPC_MorphNodeTo, TARGET_VAL(AMDGPU::V_MAD_U32_U24), 0,
                      1/*#VTs*/, MVT::i32, 7/*#Ops*/, 3, 4, 2, 5, 6, 7, 8, 
                  // Src: (add:i32 (mul:i32 U24:i32:$src0, U24:i32:$src1), i32:i32:$src2) - Complexity = 18
                  // Dst: (V_MAD_U32_U24:i32 U24:i32:$src0, U24:i32:$src1, i32:i32:$src2)
/*2186*/        0, /*End of Scope*/
/*2187*/      0, /*End of Scope*/
/*2188*/    /*Scope*/ 36|128,3/*420*/, /*->2610*/
/*2190*/      OPC_RecordChild0, // #0 = $src2
/*2191*/      OPC_Scope, 39|128,2/*295*/, /*->2489*/ // 2 children in Scope
/*2194*/        OPC_MoveChild, 1,
/*2196*/        OPC_CheckOpcode, TARGET_VAL(ISD::MUL),
/*2199*/        OPC_RecordChild0, // #1 = $src0
/*2200*/        OPC_RecordChild1, // #2 = $src1
/*2201*/        OPC_MoveParent,
/*2202*/        OPC_CheckType, MVT::i32,
/*2204*/        OPC_Scope, 105, /*->2311*/ // 3 children in Scope
/*2206*/          OPC_CheckPatternPredicate, 2, // (Subtarget.getGeneration() == AMDGPUSubtarget::EVERGREEN|| Subtarget.getGeneration() ==AMDGPUSubtarget::NORTHERN_ISLANDS)
/*2208*/          OPC_CheckComplexPat, /*CP*/0, /*#*/1, // SelectU24:$src0 #3
/*2211*/          OPC_CheckComplexPat, /*CP*/0, /*#*/2, // SelectU24:$src1 #4
/*2214*/          OPC_EmitInteger, MVT::i32, 0, 
/*2217*/          OPC_EmitInteger, MVT::i32, 0, 
/*2220*/          OPC_EmitInteger, MVT::i32, 0, 
/*2223*/          OPC_EmitInteger, MVT::i32, 0, 
/*2226*/          OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*2238*/          OPC_EmitInteger, MVT::i32, 0, 
/*2241*/          OPC_EmitInteger, MVT::i32, 0, 
/*2244*/          OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*2256*/          OPC_EmitInteger, MVT::i32, 0, 
/*2259*/          OPC_EmitInteger, MVT::i32, 0, 
/*2262*/          OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*2274*/          OPC_EmitInteger, MVT::i32, 1, 
/*2277*/          OPC_EmitRegister, MVT::i32, AMDGPU::PRED_SEL_OFF,
/*2280*/          OPC_EmitInteger, MVT::i32, 0, 
/*2283*/          OPC_EmitInteger, MVT::i32, 0, 
/*2286*/          OPC_MorphNodeTo, TARGET_VAL(AMDGPU::MULADD_UINT24_eg), 0,
                      1/*#VTs*/, MVT::i32, 18/*#Ops*/, 5, 6, 3, 7, 8, 9, 4, 10, 11, 12, 0, 13, 14, 15, 16, 17, 18, 19, 
                  // Src: (add:i32 i32:i32:$src2, (mul:i32 U24:i32:$src0, U24:i32:$src1)) - Complexity = 18
                  // Dst: (MULADD_UINT24_eg:i32 U24:i32:$src0, U24:i32:$src1, i32:i32:$src2)
/*2311*/        /*Scope*/ 105, /*->2417*/
/*2312*/          OPC_CheckPatternPredicate, 4, // (Subtarget.hasCaymanISA())
/*2314*/          OPC_CheckComplexPat, /*CP*/1, /*#*/1, // SelectI24:$src0 #3
/*2317*/          OPC_CheckComplexPat, /*CP*/1, /*#*/2, // SelectI24:$src1 #4
/*2320*/          OPC_EmitInteger, MVT::i32, 0, 
/*2323*/          OPC_EmitInteger, MVT::i32, 0, 
/*2326*/          OPC_EmitInteger, MVT::i32, 0, 
/*2329*/          OPC_EmitInteger, MVT::i32, 0, 
/*2332*/          OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*2344*/          OPC_EmitInteger, MVT::i32, 0, 
/*2347*/          OPC_EmitInteger, MVT::i32, 0, 
/*2350*/          OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*2362*/          OPC_EmitInteger, MVT::i32, 0, 
/*2365*/          OPC_EmitInteger, MVT::i32, 0, 
/*2368*/          OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*2380*/          OPC_EmitInteger, MVT::i32, 1, 
/*2383*/          OPC_EmitRegister, MVT::i32, AMDGPU::PRED_SEL_OFF,
/*2386*/          OPC_EmitInteger, MVT::i32, 0, 
/*2389*/          OPC_EmitInteger, MVT::i32, 0, 
/*2392*/          OPC_MorphNodeTo, TARGET_VAL(AMDGPU::MULADD_INT24_cm), 0,
                      1/*#VTs*/, MVT::i32, 18/*#Ops*/, 5, 6, 3, 7, 8, 9, 4, 10, 11, 12, 0, 13, 14, 15, 16, 17, 18, 19, 
                  // Src: (add:i32 i32:i32:$src2, (mul:i32 I24:i32:$src0, I24:i32:$src1)) - Complexity = 18
                  // Dst: (MULADD_INT24_cm:i32 I24:i32:$src0, I24:i32:$src1, i32:i32:$src2)
/*2417*/        /*Scope*/ 70, /*->2488*/
/*2418*/          OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*2420*/          OPC_Scope, 32, /*->2454*/ // 2 children in Scope
/*2422*/            OPC_CheckComplexPat, /*CP*/1, /*#*/1, // SelectI24:$src0 #3
/*2425*/            OPC_CheckComplexPat, /*CP*/1, /*#*/2, // SelectI24:$src1 #4
/*2428*/            OPC_EmitInteger, MVT::i32, 0, 
/*2431*/            OPC_EmitInteger, MVT::i32, 0, 
/*2434*/            OPC_EmitInteger, MVT::i32, 0, 
/*2437*/            OPC_EmitInteger, MVT::i32, 0, 
/*2440*/            OPC_MorphNodeTo, TARGET_VAL(AMDGPU::V_MAD_I32_I24), 0,
                        1/*#VTs*/, MVT::i32, 7/*#Ops*/, 3, 4, 0, 5, 6, 7, 8, 
                    // Src: (add:i32 i32:i32:$src2, (mul:i32 I24:i32:$src0, I24:i32:$src1)) - Complexity = 18
                    // Dst: (V_MAD_I32_I24:i32 I24:i32:$src0, I24:i32:$src1, i32:i32:$src2)
/*2454*/          /*Scope*/ 32, /*->2487*/
/*2455*/            OPC_CheckComplexPat, /*CP*/0, /*#*/1, // SelectU24:$src0 #3
/*2458*/            OPC_CheckComplexPat, /*CP*/0, /*#*/2, // SelectU24:$src1 #4
/*2461*/            OPC_EmitInteger, MVT::i32, 0, 
/*2464*/            OPC_EmitInteger, MVT::i32, 0, 
/*2467*/            OPC_EmitInteger, MVT::i32, 0, 
/*2470*/            OPC_EmitInteger, MVT::i32, 0, 
/*2473*/            OPC_MorphNodeTo, TARGET_VAL(AMDGPU::V_MAD_U32_U24), 0,
                        1/*#VTs*/, MVT::i32, 7/*#Ops*/, 3, 4, 0, 5, 6, 7, 8, 
                    // Src: (add:i32 i32:i32:$src2, (mul:i32 U24:i32:$src0, U24:i32:$src1)) - Complexity = 18
                    // Dst: (V_MAD_U32_U24:i32 U24:i32:$src0, U24:i32:$src1, i32:i32:$src2)
/*2487*/          0, /*End of Scope*/
/*2488*/        0, /*End of Scope*/
/*2489*/      /*Scope*/ 119, /*->2609*/
/*2490*/        OPC_RecordChild1, // #1 = $src1
/*2491*/        OPC_CheckType, MVT::i32,
/*2493*/        OPC_Scope, 101, /*->2596*/ // 2 children in Scope
/*2495*/          OPC_CheckPatternPredicate, 3, // (Subtarget.getGeneration() <= AMDGPUSubtarget::NORTHERN_ISLANDS)
/*2497*/          OPC_EmitInteger, MVT::i32, 0, 
/*2500*/          OPC_EmitInteger, MVT::i32, 0, 
/*2503*/          OPC_EmitInteger, MVT::i32, 1, 
/*2506*/          OPC_EmitInteger, MVT::i32, 0, 
/*2509*/          OPC_EmitInteger, MVT::i32, 0, 
/*2512*/          OPC_EmitInteger, MVT::i32, 0, 
/*2515*/          OPC_EmitInteger, MVT::i32, 0, 
/*2518*/          OPC_EmitInteger, MVT::i32, 0, 
/*2521*/          OPC_EmitInteger, MVT::i32, 0, 
/*2524*/          OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*2536*/          OPC_EmitInteger, MVT::i32, 0, 
/*2539*/          OPC_EmitInteger, MVT::i32, 0, 
/*2542*/          OPC_EmitInteger, MVT::i32, 0, 
/*2545*/          OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*2557*/          OPC_EmitInteger, MVT::i32, 1, 
/*2560*/          OPC_EmitRegister, MVT::i32, AMDGPU::PRED_SEL_OFF,
/*2563*/          OPC_EmitInteger, MVT::i32, 0, 
/*2566*/          OPC_EmitInteger, MVT::i32, 0, 
/*2569*/          OPC_MorphNodeTo, TARGET_VAL(AMDGPU::ADD_INT), 0,
                      1/*#VTs*/, MVT::i32, 20/*#Ops*/, 2, 3, 4, 5, 6, 7, 0, 8, 9, 10, 11, 1, 12, 13, 14, 15, 16, 17, 18, 19, 
                  // Src: (add:i32 R600_Reg32:i32:$src0, R600_Reg32:i32:$src1) - Complexity = 3
                  // Dst: (ADD_INT:i32 R600_Reg32:i32:$src0, R600_Reg32:i32:$src1)
/*2596*/        /*Scope*/ 11, /*->2608*/
/*2597*/          OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*2599*/          OPC_MorphNodeTo, TARGET_VAL(AMDGPU::S_ADD_I32), 0,
                      1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1, 
                  // Src: (add:i32 SSrc_32:i32:$src0, SSrc_32:i32:$src1) - Complexity = 3
                  // Dst: (S_ADD_I32:i32 SSrc_32:i32:$src0, SSrc_32:i32:$src1)
/*2608*/        0, /*End of Scope*/
/*2609*/      0, /*End of Scope*/
/*2610*/    0, /*End of Scope*/
/*2611*/  /*SwitchOpcode*/ 86|128,44/*5718*/,  TARGET_VAL(ISD::OR),// ->8333
/*2615*/    OPC_Scope, 98|128,42/*5474*/, /*->8092*/ // 2 children in Scope
/*2618*/      OPC_MoveChild, 0,
/*2620*/      OPC_CheckOpcode, TARGET_VAL(ISD::AND),
/*2623*/      OPC_Scope, 54|128,3/*438*/, /*->3064*/ // 8 children in Scope
/*2626*/        OPC_RecordChild0, // #0 = $y
/*2627*/        OPC_Scope, 77|128,2/*333*/, /*->2963*/ // 2 children in Scope
/*2630*/          OPC_RecordChild1, // #1 = $x
/*2631*/          OPC_MoveParent,
/*2632*/          OPC_MoveChild, 1,
/*2634*/          OPC_CheckOpcode, TARGET_VAL(ISD::AND),
/*2637*/          OPC_Scope, 29|128,1/*157*/, /*->2797*/ // 4 children in Scope
/*2640*/            OPC_RecordChild0, // #2 = $z
/*2641*/            OPC_MoveChild, 1,
/*2643*/            OPC_CheckOpcode, TARGET_VAL(ISD::XOR),
/*2646*/            OPC_CheckChild0Same, 1,
/*2648*/            OPC_MoveChild, 1,
/*2650*/            OPC_CheckInteger, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*2661*/            OPC_MoveParent,
/*2662*/            OPC_MoveParent,
/*2663*/            OPC_MoveParent,
/*2664*/            OPC_CheckType, MVT::i32,
/*2666*/            OPC_Scope, 99, /*->2767*/ // 2 children in Scope
/*2668*/              OPC_CheckPatternPredicate, 2, // (Subtarget.getGeneration() == AMDGPUSubtarget::EVERGREEN|| Subtarget.getGeneration() ==AMDGPUSubtarget::NORTHERN_ISLANDS)
/*2670*/              OPC_EmitInteger, MVT::i32, 0, 
/*2673*/              OPC_EmitInteger, MVT::i32, 0, 
/*2676*/              OPC_EmitInteger, MVT::i32, 0, 
/*2679*/              OPC_EmitInteger, MVT::i32, 0, 
/*2682*/              OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*2694*/              OPC_EmitInteger, MVT::i32, 0, 
/*2697*/              OPC_EmitInteger, MVT::i32, 0, 
/*2700*/              OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*2712*/              OPC_EmitInteger, MVT::i32, 0, 
/*2715*/              OPC_EmitInteger, MVT::i32, 0, 
/*2718*/              OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*2730*/              OPC_EmitInteger, MVT::i32, 1, 
/*2733*/              OPC_EmitRegister, MVT::i32, AMDGPU::PRED_SEL_OFF,
/*2736*/              OPC_EmitInteger, MVT::i32, 0, 
/*2739*/              OPC_EmitInteger, MVT::i32, 0, 
/*2742*/              OPC_MorphNodeTo, TARGET_VAL(AMDGPU::BFI_INT_eg), 0,
                          1/*#VTs*/, MVT::i32, 18/*#Ops*/, 3, 4, 1, 5, 6, 7, 0, 8, 9, 10, 2, 11, 12, 13, 14, 15, 16, 17, 
                      // Src: (or:i32 (and:i32 i32:i32:$y, i32:i32:$x), (and:i32 i32:i32:$z, (xor:i32 i32:i32:$x, -1:i32))) - Complexity = 17
                      // Dst: (BFI_INT_eg:i32 ?:i32:$x, ?:i32:$y, ?:i32:$z)
/*2767*/            /*Scope*/ 28, /*->2796*/
/*2768*/              OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*2770*/              OPC_EmitInteger, MVT::i32, 0, 
/*2773*/              OPC_EmitInteger, MVT::i32, 0, 
/*2776*/              OPC_EmitInteger, MVT::i32, 0, 
/*2779*/              OPC_EmitInteger, MVT::i32, 0, 
/*2782*/              OPC_MorphNodeTo, TARGET_VAL(AMDGPU::V_BFI_B32), 0,
                          1/*#VTs*/, MVT::i32, 7/*#Ops*/, 1, 0, 2, 3, 4, 5, 6, 
                      // Src: (or:i32 (and:i32 i32:i32:$y, i32:i32:$x), (and:i32 i32:i32:$z, (xor:i32 i32:i32:$x, -1:i32))) - Complexity = 17
                      // Dst: (V_BFI_B32:i32 ?:i32:$x, ?:i32:$y, ?:i32:$z)
/*2796*/            0, /*End of Scope*/
/*2797*/          /*Scope*/ 54, /*->2852*/
/*2798*/            OPC_MoveChild, 0,
/*2800*/            OPC_CheckOpcode, TARGET_VAL(ISD::XOR),
/*2803*/            OPC_CheckChild0Same, 1,
/*2805*/            OPC_MoveChild, 1,
/*2807*/            OPC_CheckInteger, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*2818*/            OPC_MoveParent,
/*2819*/            OPC_MoveParent,
/*2820*/            OPC_RecordChild1, // #2 = $z
/*2821*/            OPC_MoveParent,
/*2822*/            OPC_CheckType, MVT::i32,
/*2824*/            OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*2826*/            OPC_EmitInteger, MVT::i32, 0, 
/*2829*/            OPC_EmitInteger, MVT::i32, 0, 
/*2832*/            OPC_EmitInteger, MVT::i32, 0, 
/*2835*/            OPC_EmitInteger, MVT::i32, 0, 
/*2838*/            OPC_MorphNodeTo, TARGET_VAL(AMDGPU::V_BFI_B32), 0,
                        1/*#VTs*/, MVT::i32, 7/*#Ops*/, 1, 0, 2, 3, 4, 5, 6, 
                    // Src: (or:i32 (and:i32 i32:i32:$y, i32:i32:$x), (and:i32 (xor:i32 i32:i32:$x, -1:i32), i32:i32:$z)) - Complexity = 17
                    // Dst: (V_BFI_B32:i32 ?:i32:$x, ?:i32:$y, ?:i32:$z)
/*2852*/          /*Scope*/ 54, /*->2907*/
/*2853*/            OPC_RecordChild0, // #2 = $z
/*2854*/            OPC_MoveChild, 1,
/*2856*/            OPC_CheckOpcode, TARGET_VAL(ISD::XOR),
/*2859*/            OPC_CheckChild0Same, 0,
/*2861*/            OPC_MoveChild, 1,
/*2863*/            OPC_CheckInteger, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*2874*/            OPC_MoveParent,
/*2875*/            OPC_MoveParent,
/*2876*/            OPC_MoveParent,
/*2877*/            OPC_CheckType, MVT::i32,
/*2879*/            OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*2881*/            OPC_EmitInteger, MVT::i32, 0, 
/*2884*/            OPC_EmitInteger, MVT::i32, 0, 
/*2887*/            OPC_EmitInteger, MVT::i32, 0, 
/*2890*/            OPC_EmitInteger, MVT::i32, 0, 
/*2893*/            OPC_MorphNodeTo, TARGET_VAL(AMDGPU::V_BFI_B32), 0,
                        1/*#VTs*/, MVT::i32, 7/*#Ops*/, 0, 1, 2, 3, 4, 5, 6, 
                    // Src: (or:i32 (and:i32 i32:i32:$x, i32:i32:$y), (and:i32 i32:i32:$z, (xor:i32 i32:i32:$x, -1:i32))) - Complexity = 17
                    // Dst: (V_BFI_B32:i32 ?:i32:$x, ?:i32:$y, ?:i32:$z)
/*2907*/          /*Scope*/ 54, /*->2962*/
/*2908*/            OPC_MoveChild, 0,
/*2910*/            OPC_CheckOpcode, TARGET_VAL(ISD::XOR),
/*2913*/            OPC_CheckChild0Same, 0,
/*2915*/            OPC_MoveChild, 1,
/*2917*/            OPC_CheckInteger, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*2928*/            OPC_MoveParent,
/*2929*/            OPC_MoveParent,
/*2930*/            OPC_RecordChild1, // #2 = $z
/*2931*/            OPC_MoveParent,
/*2932*/            OPC_CheckType, MVT::i32,
/*2934*/            OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*2936*/            OPC_EmitInteger, MVT::i32, 0, 
/*2939*/            OPC_EmitInteger, MVT::i32, 0, 
/*2942*/            OPC_EmitInteger, MVT::i32, 0, 
/*2945*/            OPC_EmitInteger, MVT::i32, 0, 
/*2948*/            OPC_MorphNodeTo, TARGET_VAL(AMDGPU::V_BFI_B32), 0,
                        1/*#VTs*/, MVT::i32, 7/*#Ops*/, 0, 1, 2, 3, 4, 5, 6, 
                    // Src: (or:i32 (and:i32 i32:i32:$x, i32:i32:$y), (and:i32 (xor:i32 i32:i32:$x, -1:i32), i32:i32:$z)) - Complexity = 17
                    // Dst: (V_BFI_B32:i32 ?:i32:$x, ?:i32:$y, ?:i32:$z)
/*2962*/          0, /*End of Scope*/
/*2963*/        /*Scope*/ 99, /*->3063*/
/*2964*/          OPC_MoveChild, 1,
/*2966*/          OPC_CheckOpcode, TARGET_VAL(ISD::XOR),
/*2969*/          OPC_RecordChild0, // #1 = $x
/*2970*/          OPC_MoveChild, 1,
/*2972*/          OPC_CheckInteger, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*2983*/          OPC_MoveParent,
/*2984*/          OPC_MoveParent,
/*2985*/          OPC_MoveParent,
/*2986*/          OPC_MoveChild, 1,
/*2988*/          OPC_CheckOpcode, TARGET_VAL(ISD::AND),
/*2991*/          OPC_Scope, 34, /*->3027*/ // 2 children in Scope
/*2993*/            OPC_RecordChild0, // #2 = $y
/*2994*/            OPC_CheckChild1Same, 1,
/*2996*/            OPC_MoveParent,
/*2997*/            OPC_CheckType, MVT::i32,
/*2999*/            OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*3001*/            OPC_EmitInteger, MVT::i32, 0, 
/*3004*/            OPC_EmitInteger, MVT::i32, 0, 
/*3007*/            OPC_EmitInteger, MVT::i32, 0, 
/*3010*/            OPC_EmitInteger, MVT::i32, 0, 
/*3013*/            OPC_MorphNodeTo, TARGET_VAL(AMDGPU::V_BFI_B32), 0,
                        1/*#VTs*/, MVT::i32, 7/*#Ops*/, 1, 2, 0, 3, 4, 5, 6, 
                    // Src: (or:i32 (and:i32 i32:i32:$z, (xor:i32 i32:i32:$x, -1:i32)), (and:i32 i32:i32:$y, i32:i32:$x)) - Complexity = 17
                    // Dst: (V_BFI_B32:i32 ?:i32:$x, ?:i32:$y, ?:i32:$z)
/*3027*/          /*Scope*/ 34, /*->3062*/
/*3028*/            OPC_CheckChild0Same, 1,
/*3030*/            OPC_RecordChild1, // #2 = $y
/*3031*/            OPC_MoveParent,
/*3032*/            OPC_CheckType, MVT::i32,
/*3034*/            OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*3036*/            OPC_EmitInteger, MVT::i32, 0, 
/*3039*/            OPC_EmitInteger, MVT::i32, 0, 
/*3042*/            OPC_EmitInteger, MVT::i32, 0, 
/*3045*/            OPC_EmitInteger, MVT::i32, 0, 
/*3048*/            OPC_MorphNodeTo, TARGET_VAL(AMDGPU::V_BFI_B32), 0,
                        1/*#VTs*/, MVT::i32, 7/*#Ops*/, 1, 2, 0, 3, 4, 5, 6, 
                    // Src: (or:i32 (and:i32 i32:i32:$z, (xor:i32 i32:i32:$x, -1:i32)), (and:i32 i32:i32:$x, i32:i32:$y)) - Complexity = 17
                    // Dst: (V_BFI_B32:i32 ?:i32:$x, ?:i32:$y, ?:i32:$z)
/*3062*/          0, /*End of Scope*/
/*3063*/        0, /*End of Scope*/
/*3064*/      /*Scope*/ 100, /*->3165*/
/*3065*/        OPC_MoveChild, 0,
/*3067*/        OPC_CheckOpcode, TARGET_VAL(ISD::XOR),
/*3070*/        OPC_RecordChild0, // #0 = $x
/*3071*/        OPC_MoveChild, 1,
/*3073*/        OPC_CheckInteger, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*3084*/        OPC_MoveParent,
/*3085*/        OPC_MoveParent,
/*3086*/        OPC_RecordChild1, // #1 = $z
/*3087*/        OPC_MoveParent,
/*3088*/        OPC_MoveChild, 1,
/*3090*/        OPC_CheckOpcode, TARGET_VAL(ISD::AND),
/*3093*/        OPC_Scope, 34, /*->3129*/ // 2 children in Scope
/*3095*/          OPC_RecordChild0, // #2 = $y
/*3096*/          OPC_CheckChild1Same, 0,
/*3098*/          OPC_MoveParent,
/*3099*/          OPC_CheckType, MVT::i32,
/*3101*/          OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*3103*/          OPC_EmitInteger, MVT::i32, 0, 
/*3106*/          OPC_EmitInteger, MVT::i32, 0, 
/*3109*/          OPC_EmitInteger, MVT::i32, 0, 
/*3112*/          OPC_EmitInteger, MVT::i32, 0, 
/*3115*/          OPC_MorphNodeTo, TARGET_VAL(AMDGPU::V_BFI_B32), 0,
                      1/*#VTs*/, MVT::i32, 7/*#Ops*/, 0, 2, 1, 3, 4, 5, 6, 
                  // Src: (or:i32 (and:i32 (xor:i32 i32:i32:$x, -1:i32), i32:i32:$z), (and:i32 i32:i32:$y, i32:i32:$x)) - Complexity = 17
                  // Dst: (V_BFI_B32:i32 ?:i32:$x, ?:i32:$y, ?:i32:$z)
/*3129*/        /*Scope*/ 34, /*->3164*/
/*3130*/          OPC_CheckChild0Same, 0,
/*3132*/          OPC_RecordChild1, // #2 = $y
/*3133*/          OPC_MoveParent,
/*3134*/          OPC_CheckType, MVT::i32,
/*3136*/          OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*3138*/          OPC_EmitInteger, MVT::i32, 0, 
/*3141*/          OPC_EmitInteger, MVT::i32, 0, 
/*3144*/          OPC_EmitInteger, MVT::i32, 0, 
/*3147*/          OPC_EmitInteger, MVT::i32, 0, 
/*3150*/          OPC_MorphNodeTo, TARGET_VAL(AMDGPU::V_BFI_B32), 0,
                      1/*#VTs*/, MVT::i32, 7/*#Ops*/, 0, 2, 1, 3, 4, 5, 6, 
                  // Src: (or:i32 (and:i32 (xor:i32 i32:i32:$x, -1:i32), i32:i32:$z), (and:i32 i32:i32:$x, i32:i32:$y)) - Complexity = 17
                  // Dst: (V_BFI_B32:i32 ?:i32:$x, ?:i32:$y, ?:i32:$z)
/*3164*/        0, /*End of Scope*/
/*3165*/      /*Scope*/ 123|128,4/*635*/, /*->3802*/
/*3167*/        OPC_RecordChild0, // #0 = $y
/*3168*/        OPC_Scope, 3|128,3/*387*/, /*->3558*/ // 2 children in Scope
/*3171*/          OPC_RecordChild1, // #1 = $x
/*3172*/          OPC_MoveParent,
/*3173*/          OPC_MoveChild, 1,
/*3175*/          OPC_CheckOpcode, TARGET_VAL(ISD::AND),
/*3178*/          OPC_Scope, 125, /*->3305*/ // 3 children in Scope
/*3180*/            OPC_MoveChild, 0,
/*3182*/            OPC_CheckOpcode, TARGET_VAL(ISD::XOR),
/*3185*/            OPC_CheckChild0Same, 1,
/*3187*/            OPC_MoveChild, 1,
/*3189*/            OPC_CheckInteger, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*3200*/            OPC_MoveParent,
/*3201*/            OPC_MoveParent,
/*3202*/            OPC_RecordChild1, // #2 = $z
/*3203*/            OPC_MoveParent,
/*3204*/            OPC_CheckType, MVT::i32,
/*3206*/            OPC_CheckPatternPredicate, 2, // (Subtarget.getGeneration() == AMDGPUSubtarget::EVERGREEN|| Subtarget.getGeneration() ==AMDGPUSubtarget::NORTHERN_ISLANDS)
/*3208*/            OPC_EmitInteger, MVT::i32, 0, 
/*3211*/            OPC_EmitInteger, MVT::i32, 0, 
/*3214*/            OPC_EmitInteger, MVT::i32, 0, 
/*3217*/            OPC_EmitInteger, MVT::i32, 0, 
/*3220*/            OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*3232*/            OPC_EmitInteger, MVT::i32, 0, 
/*3235*/            OPC_EmitInteger, MVT::i32, 0, 
/*3238*/            OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*3250*/            OPC_EmitInteger, MVT::i32, 0, 
/*3253*/            OPC_EmitInteger, MVT::i32, 0, 
/*3256*/            OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*3268*/            OPC_EmitInteger, MVT::i32, 1, 
/*3271*/            OPC_EmitRegister, MVT::i32, AMDGPU::PRED_SEL_OFF,
/*3274*/            OPC_EmitInteger, MVT::i32, 0, 
/*3277*/            OPC_EmitInteger, MVT::i32, 0, 
/*3280*/            OPC_MorphNodeTo, TARGET_VAL(AMDGPU::BFI_INT_eg), 0,
                        1/*#VTs*/, MVT::i32, 18/*#Ops*/, 3, 4, 1, 5, 6, 7, 0, 8, 9, 10, 2, 11, 12, 13, 14, 15, 16, 17, 
                    // Src: (or:i32 (and:i32 i32:i32:$y, i32:i32:$x), (and:i32 (xor:i32 i32:i32:$x, -1:i32), i32:i32:$z)) - Complexity = 17
                    // Dst: (BFI_INT_eg:i32 ?:i32:$x, ?:i32:$y, ?:i32:$z)
/*3305*/          /*Scope*/ 125, /*->3431*/
/*3306*/            OPC_RecordChild0, // #2 = $z
/*3307*/            OPC_MoveChild, 1,
/*3309*/            OPC_CheckOpcode, TARGET_VAL(ISD::XOR),
/*3312*/            OPC_CheckChild0Same, 0,
/*3314*/            OPC_MoveChild, 1,
/*3316*/            OPC_CheckInteger, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*3327*/            OPC_MoveParent,
/*3328*/            OPC_MoveParent,
/*3329*/            OPC_MoveParent,
/*3330*/            OPC_CheckType, MVT::i32,
/*3332*/            OPC_CheckPatternPredicate, 2, // (Subtarget.getGeneration() == AMDGPUSubtarget::EVERGREEN|| Subtarget.getGeneration() ==AMDGPUSubtarget::NORTHERN_ISLANDS)
/*3334*/            OPC_EmitInteger, MVT::i32, 0, 
/*3337*/            OPC_EmitInteger, MVT::i32, 0, 
/*3340*/            OPC_EmitInteger, MVT::i32, 0, 
/*3343*/            OPC_EmitInteger, MVT::i32, 0, 
/*3346*/            OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*3358*/            OPC_EmitInteger, MVT::i32, 0, 
/*3361*/            OPC_EmitInteger, MVT::i32, 0, 
/*3364*/            OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*3376*/            OPC_EmitInteger, MVT::i32, 0, 
/*3379*/            OPC_EmitInteger, MVT::i32, 0, 
/*3382*/            OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*3394*/            OPC_EmitInteger, MVT::i32, 1, 
/*3397*/            OPC_EmitRegister, MVT::i32, AMDGPU::PRED_SEL_OFF,
/*3400*/            OPC_EmitInteger, MVT::i32, 0, 
/*3403*/            OPC_EmitInteger, MVT::i32, 0, 
/*3406*/            OPC_MorphNodeTo, TARGET_VAL(AMDGPU::BFI_INT_eg), 0,
                        1/*#VTs*/, MVT::i32, 18/*#Ops*/, 3, 4, 0, 5, 6, 7, 1, 8, 9, 10, 2, 11, 12, 13, 14, 15, 16, 17, 
                    // Src: (or:i32 (and:i32 i32:i32:$x, i32:i32:$y), (and:i32 i32:i32:$z, (xor:i32 i32:i32:$x, -1:i32))) - Complexity = 17
                    // Dst: (BFI_INT_eg:i32 ?:i32:$x, ?:i32:$y, ?:i32:$z)
/*3431*/          /*Scope*/ 125, /*->3557*/
/*3432*/            OPC_MoveChild, 0,
/*3434*/            OPC_CheckOpcode, TARGET_VAL(ISD::XOR),
/*3437*/            OPC_CheckChild0Same, 0,
/*3439*/            OPC_MoveChild, 1,
/*3441*/            OPC_CheckInteger, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*3452*/            OPC_MoveParent,
/*3453*/            OPC_MoveParent,
/*3454*/            OPC_RecordChild1, // #2 = $z
/*3455*/            OPC_MoveParent,
/*3456*/            OPC_CheckType, MVT::i32,
/*3458*/            OPC_CheckPatternPredicate, 2, // (Subtarget.getGeneration() == AMDGPUSubtarget::EVERGREEN|| Subtarget.getGeneration() ==AMDGPUSubtarget::NORTHERN_ISLANDS)
/*3460*/            OPC_EmitInteger, MVT::i32, 0, 
/*3463*/            OPC_EmitInteger, MVT::i32, 0, 
/*3466*/            OPC_EmitInteger, MVT::i32, 0, 
/*3469*/            OPC_EmitInteger, MVT::i32, 0, 
/*3472*/            OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*3484*/            OPC_EmitInteger, MVT::i32, 0, 
/*3487*/            OPC_EmitInteger, MVT::i32, 0, 
/*3490*/            OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*3502*/            OPC_EmitInteger, MVT::i32, 0, 
/*3505*/            OPC_EmitInteger, MVT::i32, 0, 
/*3508*/            OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*3520*/            OPC_EmitInteger, MVT::i32, 1, 
/*3523*/            OPC_EmitRegister, MVT::i32, AMDGPU::PRED_SEL_OFF,
/*3526*/            OPC_EmitInteger, MVT::i32, 0, 
/*3529*/            OPC_EmitInteger, MVT::i32, 0, 
/*3532*/            OPC_MorphNodeTo, TARGET_VAL(AMDGPU::BFI_INT_eg), 0,
                        1/*#VTs*/, MVT::i32, 18/*#Ops*/, 3, 4, 0, 5, 6, 7, 1, 8, 9, 10, 2, 11, 12, 13, 14, 15, 16, 17, 
                    // Src: (or:i32 (and:i32 i32:i32:$x, i32:i32:$y), (and:i32 (xor:i32 i32:i32:$x, -1:i32), i32:i32:$z)) - Complexity = 17
                    // Dst: (BFI_INT_eg:i32 ?:i32:$x, ?:i32:$y, ?:i32:$z)
/*3557*/          0, /*End of Scope*/
/*3558*/        /*Scope*/ 113|128,1/*241*/, /*->3801*/
/*3560*/          OPC_MoveChild, 1,
/*3562*/          OPC_CheckOpcode, TARGET_VAL(ISD::XOR),
/*3565*/          OPC_RecordChild0, // #1 = $x
/*3566*/          OPC_MoveChild, 1,
/*3568*/          OPC_CheckInteger, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*3579*/          OPC_MoveParent,
/*3580*/          OPC_MoveParent,
/*3581*/          OPC_MoveParent,
/*3582*/          OPC_MoveChild, 1,
/*3584*/          OPC_CheckOpcode, TARGET_VAL(ISD::AND),
/*3587*/          OPC_Scope, 105, /*->3694*/ // 2 children in Scope
/*3589*/            OPC_RecordChild0, // #2 = $y
/*3590*/            OPC_CheckChild1Same, 1,
/*3592*/            OPC_MoveParent,
/*3593*/            OPC_CheckType, MVT::i32,
/*3595*/            OPC_CheckPatternPredicate, 2, // (Subtarget.getGeneration() == AMDGPUSubtarget::EVERGREEN|| Subtarget.getGeneration() ==AMDGPUSubtarget::NORTHERN_ISLANDS)
/*3597*/            OPC_EmitInteger, MVT::i32, 0, 
/*3600*/            OPC_EmitInteger, MVT::i32, 0, 
/*3603*/            OPC_EmitInteger, MVT::i32, 0, 
/*3606*/            OPC_EmitInteger, MVT::i32, 0, 
/*3609*/            OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*3621*/            OPC_EmitInteger, MVT::i32, 0, 
/*3624*/            OPC_EmitInteger, MVT::i32, 0, 
/*3627*/            OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*3639*/            OPC_EmitInteger, MVT::i32, 0, 
/*3642*/            OPC_EmitInteger, MVT::i32, 0, 
/*3645*/            OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*3657*/            OPC_EmitInteger, MVT::i32, 1, 
/*3660*/            OPC_EmitRegister, MVT::i32, AMDGPU::PRED_SEL_OFF,
/*3663*/            OPC_EmitInteger, MVT::i32, 0, 
/*3666*/            OPC_EmitInteger, MVT::i32, 0, 
/*3669*/            OPC_MorphNodeTo, TARGET_VAL(AMDGPU::BFI_INT_eg), 0,
                        1/*#VTs*/, MVT::i32, 18/*#Ops*/, 3, 4, 1, 5, 6, 7, 2, 8, 9, 10, 0, 11, 12, 13, 14, 15, 16, 17, 
                    // Src: (or:i32 (and:i32 i32:i32:$z, (xor:i32 i32:i32:$x, -1:i32)), (and:i32 i32:i32:$y, i32:i32:$x)) - Complexity = 17
                    // Dst: (BFI_INT_eg:i32 ?:i32:$x, ?:i32:$y, ?:i32:$z)
/*3694*/          /*Scope*/ 105, /*->3800*/
/*3695*/            OPC_CheckChild0Same, 1,
/*3697*/            OPC_RecordChild1, // #2 = $y
/*3698*/            OPC_MoveParent,
/*3699*/            OPC_CheckType, MVT::i32,
/*3701*/            OPC_CheckPatternPredicate, 2, // (Subtarget.getGeneration() == AMDGPUSubtarget::EVERGREEN|| Subtarget.getGeneration() ==AMDGPUSubtarget::NORTHERN_ISLANDS)
/*3703*/            OPC_EmitInteger, MVT::i32, 0, 
/*3706*/            OPC_EmitInteger, MVT::i32, 0, 
/*3709*/            OPC_EmitInteger, MVT::i32, 0, 
/*3712*/            OPC_EmitInteger, MVT::i32, 0, 
/*3715*/            OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*3727*/            OPC_EmitInteger, MVT::i32, 0, 
/*3730*/            OPC_EmitInteger, MVT::i32, 0, 
/*3733*/            OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*3745*/            OPC_EmitInteger, MVT::i32, 0, 
/*3748*/            OPC_EmitInteger, MVT::i32, 0, 
/*3751*/            OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*3763*/            OPC_EmitInteger, MVT::i32, 1, 
/*3766*/            OPC_EmitRegister, MVT::i32, AMDGPU::PRED_SEL_OFF,
/*3769*/            OPC_EmitInteger, MVT::i32, 0, 
/*3772*/            OPC_EmitInteger, MVT::i32, 0, 
/*3775*/            OPC_MorphNodeTo, TARGET_VAL(AMDGPU::BFI_INT_eg), 0,
                        1/*#VTs*/, MVT::i32, 18/*#Ops*/, 3, 4, 1, 5, 6, 7, 2, 8, 9, 10, 0, 11, 12, 13, 14, 15, 16, 17, 
                    // Src: (or:i32 (and:i32 i32:i32:$z, (xor:i32 i32:i32:$x, -1:i32)), (and:i32 i32:i32:$x, i32:i32:$y)) - Complexity = 17
                    // Dst: (BFI_INT_eg:i32 ?:i32:$x, ?:i32:$y, ?:i32:$z)
/*3800*/          0, /*End of Scope*/
/*3801*/        0, /*End of Scope*/
/*3802*/      /*Scope*/ 114|128,1/*242*/, /*->4046*/
/*3804*/        OPC_MoveChild, 0,
/*3806*/        OPC_CheckOpcode, TARGET_VAL(ISD::XOR),
/*3809*/        OPC_RecordChild0, // #0 = $x
/*3810*/        OPC_MoveChild, 1,
/*3812*/        OPC_CheckInteger, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*3823*/        OPC_MoveParent,
/*3824*/        OPC_MoveParent,
/*3825*/        OPC_RecordChild1, // #1 = $z
/*3826*/        OPC_MoveParent,
/*3827*/        OPC_MoveChild, 1,
/*3829*/        OPC_CheckOpcode, TARGET_VAL(ISD::AND),
/*3832*/        OPC_Scope, 105, /*->3939*/ // 2 children in Scope
/*3834*/          OPC_RecordChild0, // #2 = $y
/*3835*/          OPC_CheckChild1Same, 0,
/*3837*/          OPC_MoveParent,
/*3838*/          OPC_CheckType, MVT::i32,
/*3840*/          OPC_CheckPatternPredicate, 2, // (Subtarget.getGeneration() == AMDGPUSubtarget::EVERGREEN|| Subtarget.getGeneration() ==AMDGPUSubtarget::NORTHERN_ISLANDS)
/*3842*/          OPC_EmitInteger, MVT::i32, 0, 
/*3845*/          OPC_EmitInteger, MVT::i32, 0, 
/*3848*/          OPC_EmitInteger, MVT::i32, 0, 
/*3851*/          OPC_EmitInteger, MVT::i32, 0, 
/*3854*/          OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*3866*/          OPC_EmitInteger, MVT::i32, 0, 
/*3869*/          OPC_EmitInteger, MVT::i32, 0, 
/*3872*/          OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*3884*/          OPC_EmitInteger, MVT::i32, 0, 
/*3887*/          OPC_EmitInteger, MVT::i32, 0, 
/*3890*/          OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*3902*/          OPC_EmitInteger, MVT::i32, 1, 
/*3905*/          OPC_EmitRegister, MVT::i32, AMDGPU::PRED_SEL_OFF,
/*3908*/          OPC_EmitInteger, MVT::i32, 0, 
/*3911*/          OPC_EmitInteger, MVT::i32, 0, 
/*3914*/          OPC_MorphNodeTo, TARGET_VAL(AMDGPU::BFI_INT_eg), 0,
                      1/*#VTs*/, MVT::i32, 18/*#Ops*/, 3, 4, 0, 5, 6, 7, 2, 8, 9, 10, 1, 11, 12, 13, 14, 15, 16, 17, 
                  // Src: (or:i32 (and:i32 (xor:i32 i32:i32:$x, -1:i32), i32:i32:$z), (and:i32 i32:i32:$y, i32:i32:$x)) - Complexity = 17
                  // Dst: (BFI_INT_eg:i32 ?:i32:$x, ?:i32:$y, ?:i32:$z)
/*3939*/        /*Scope*/ 105, /*->4045*/
/*3940*/          OPC_CheckChild0Same, 0,
/*3942*/          OPC_RecordChild1, // #2 = $y
/*3943*/          OPC_MoveParent,
/*3944*/          OPC_CheckType, MVT::i32,
/*3946*/          OPC_CheckPatternPredicate, 2, // (Subtarget.getGeneration() == AMDGPUSubtarget::EVERGREEN|| Subtarget.getGeneration() ==AMDGPUSubtarget::NORTHERN_ISLANDS)
/*3948*/          OPC_EmitInteger, MVT::i32, 0, 
/*3951*/          OPC_EmitInteger, MVT::i32, 0, 
/*3954*/          OPC_EmitInteger, MVT::i32, 0, 
/*3957*/          OPC_EmitInteger, MVT::i32, 0, 
/*3960*/          OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*3972*/          OPC_EmitInteger, MVT::i32, 0, 
/*3975*/          OPC_EmitInteger, MVT::i32, 0, 
/*3978*/          OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*3990*/          OPC_EmitInteger, MVT::i32, 0, 
/*3993*/          OPC_EmitInteger, MVT::i32, 0, 
/*3996*/          OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*4008*/          OPC_EmitInteger, MVT::i32, 1, 
/*4011*/          OPC_EmitRegister, MVT::i32, AMDGPU::PRED_SEL_OFF,
/*4014*/          OPC_EmitInteger, MVT::i32, 0, 
/*4017*/          OPC_EmitInteger, MVT::i32, 0, 
/*4020*/          OPC_MorphNodeTo, TARGET_VAL(AMDGPU::BFI_INT_eg), 0,
                      1/*#VTs*/, MVT::i32, 18/*#Ops*/, 3, 4, 0, 5, 6, 7, 2, 8, 9, 10, 1, 11, 12, 13, 14, 15, 16, 17, 
                  // Src: (or:i32 (and:i32 (xor:i32 i32:i32:$x, -1:i32), i32:i32:$z), (and:i32 i32:i32:$x, i32:i32:$y)) - Complexity = 17
                  // Dst: (BFI_INT_eg:i32 ?:i32:$x, ?:i32:$y, ?:i32:$z)
/*4045*/        0, /*End of Scope*/
/*4046*/      /*Scope*/ 49|128,6/*817*/, /*->4865*/
/*4048*/        OPC_RecordChild0, // #0 = $x
/*4049*/        OPC_Scope, 108|128,4/*620*/, /*->4672*/ // 2 children in Scope
/*4052*/          OPC_RecordChild1, // #1 = $z
/*4053*/          OPC_MoveParent,
/*4054*/          OPC_MoveChild, 1,
/*4056*/          OPC_CheckOpcode, TARGET_VAL(ISD::AND),
/*4059*/          OPC_Scope, 48|128,2/*304*/, /*->4366*/ // 4 children in Scope
/*4062*/            OPC_RecordChild0, // #2 = $y
/*4063*/            OPC_MoveChild, 1,
/*4065*/            OPC_CheckOpcode, TARGET_VAL(ISD::OR),
/*4068*/            OPC_Scope, 120|128,1/*248*/, /*->4319*/ // 2 children in Scope
/*4071*/              OPC_CheckChild0Same, 0,
/*4073*/              OPC_CheckChild1Same, 1,
/*4075*/              OPC_MoveParent,
/*4076*/              OPC_MoveParent,
/*4077*/              OPC_CheckType, MVT::i32,
/*4079*/              OPC_Scope, 70|128,1/*198*/, /*->4280*/ // 2 children in Scope
/*4082*/                OPC_CheckPatternPredicate, 2, // (Subtarget.getGeneration() == AMDGPUSubtarget::EVERGREEN|| Subtarget.getGeneration() ==AMDGPUSubtarget::NORTHERN_ISLANDS)
/*4084*/                OPC_EmitInteger, MVT::i32, 0, 
/*4087*/                OPC_EmitInteger, MVT::i32, 0, 
/*4090*/                OPC_EmitInteger, MVT::i32, 0, 
/*4093*/                OPC_EmitInteger, MVT::i32, 0, 
/*4096*/                OPC_EmitInteger, MVT::i32, 1, 
/*4099*/                OPC_EmitInteger, MVT::i32, 0, 
/*4102*/                OPC_EmitInteger, MVT::i32, 0, 
/*4105*/                OPC_EmitInteger, MVT::i32, 0, 
/*4108*/                OPC_EmitInteger, MVT::i32, 0, 
/*4111*/                OPC_EmitInteger, MVT::i32, 0, 
/*4114*/                OPC_EmitInteger, MVT::i32, 0, 
/*4117*/                OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*4129*/                OPC_EmitInteger, MVT::i32, 0, 
/*4132*/                OPC_EmitInteger, MVT::i32, 0, 
/*4135*/                OPC_EmitInteger, MVT::i32, 0, 
/*4138*/                OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*4150*/                OPC_EmitInteger, MVT::i32, 1, 
/*4153*/                OPC_EmitRegister, MVT::i32, AMDGPU::PRED_SEL_OFF,
/*4156*/                OPC_EmitInteger, MVT::i32, 0, 
/*4159*/                OPC_EmitInteger, MVT::i32, 0, 
/*4162*/                OPC_EmitNode, TARGET_VAL(AMDGPU::XOR_INT), 0,
                            1/*#VTs*/, MVT::i32, 20/*#Ops*/, 5, 6, 7, 8, 9, 10, 0, 11, 12, 13, 14, 2, 15, 16, 17, 18, 19, 20, 21, 22,  // Results = #23
/*4189*/                OPC_EmitInteger, MVT::i32, 0, 
/*4192*/                OPC_EmitInteger, MVT::i32, 0, 
/*4195*/                OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*4207*/                OPC_EmitInteger, MVT::i32, 0, 
/*4210*/                OPC_EmitInteger, MVT::i32, 0, 
/*4213*/                OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*4225*/                OPC_EmitInteger, MVT::i32, 0, 
/*4228*/                OPC_EmitInteger, MVT::i32, 0, 
/*4231*/                OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*4243*/                OPC_EmitInteger, MVT::i32, 1, 
/*4246*/                OPC_EmitRegister, MVT::i32, AMDGPU::PRED_SEL_OFF,
/*4249*/                OPC_EmitInteger, MVT::i32, 0, 
/*4252*/                OPC_EmitInteger, MVT::i32, 0, 
/*4255*/                OPC_MorphNodeTo, TARGET_VAL(AMDGPU::BFI_INT_eg), 0,
                            1/*#VTs*/, MVT::i32, 18/*#Ops*/, 3, 4, 23, 24, 25, 26, 1, 27, 28, 29, 2, 30, 31, 32, 33, 34, 35, 36, 
                        // Src: (or:i32 (and:i32 i32:i32:$x, i32:i32:$z), (and:i32 i32:i32:$y, (or:i32 i32:i32:$x, i32:i32:$z))) - Complexity = 12
                        // Dst: (BFI_INT_eg:i32 (XOR_INT:i32 i32:i32:$x, i32:i32:$y), i32:i32:$z, i32:i32:$y)
/*4280*/              /*Scope*/ 37, /*->4318*/
/*4281*/                OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*4283*/                OPC_EmitNode, TARGET_VAL(AMDGPU::V_XOR_B32_e32), 0,
                            1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 2,  // Results = #3
/*4292*/                OPC_EmitInteger, MVT::i32, 0, 
/*4295*/                OPC_EmitInteger, MVT::i32, 0, 
/*4298*/                OPC_EmitInteger, MVT::i32, 0, 
/*4301*/                OPC_EmitInteger, MVT::i32, 0, 
/*4304*/                OPC_MorphNodeTo, TARGET_VAL(AMDGPU::V_BFI_B32), 0,
                            1/*#VTs*/, MVT::i32, 7/*#Ops*/, 3, 1, 2, 4, 5, 6, 7, 
                        // Src: (or:i32 (and:i32 i32:i32:$x, i32:i32:$z), (and:i32 i32:i32:$y, (or:i32 i32:i32:$x, i32:i32:$z))) - Complexity = 12
                        // Dst: (V_BFI_B32:i32 (V_XOR_B32_e32:i32 i32:i32:$x, i32:i32:$y), i32:i32:$z, i32:i32:$y)
/*4318*/              0, /*End of Scope*/
/*4319*/            /*Scope*/ 45, /*->4365*/
/*4320*/              OPC_CheckChild0Same, 1,
/*4322*/              OPC_CheckChild1Same, 0,
/*4324*/              OPC_MoveParent,
/*4325*/              OPC_MoveParent,
/*4326*/              OPC_CheckType, MVT::i32,
/*4328*/              OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*4330*/              OPC_EmitNode, TARGET_VAL(AMDGPU::V_XOR_B32_e32), 0,
                          1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 2,  // Results = #3
/*4339*/              OPC_EmitInteger, MVT::i32, 0, 
/*4342*/              OPC_EmitInteger, MVT::i32, 0, 
/*4345*/              OPC_EmitInteger, MVT::i32, 0, 
/*4348*/              OPC_EmitInteger, MVT::i32, 0, 
/*4351*/              OPC_MorphNodeTo, TARGET_VAL(AMDGPU::V_BFI_B32), 0,
                          1/*#VTs*/, MVT::i32, 7/*#Ops*/, 3, 1, 2, 4, 5, 6, 7, 
                      // Src: (or:i32 (and:i32 i32:i32:$x, i32:i32:$z), (and:i32 i32:i32:$y, (or:i32 i32:i32:$z, i32:i32:$x))) - Complexity = 12
                      // Dst: (V_BFI_B32:i32 (V_XOR_B32_e32:i32 i32:i32:$x, i32:i32:$y), i32:i32:$z, i32:i32:$y)
/*4365*/            0, /*End of Scope*/
/*4366*/          /*Scope*/ 101, /*->4468*/
/*4367*/            OPC_MoveChild, 0,
/*4369*/            OPC_CheckOpcode, TARGET_VAL(ISD::OR),
/*4372*/            OPC_Scope, 46, /*->4420*/ // 2 children in Scope
/*4374*/              OPC_CheckChild0Same, 0,
/*4376*/              OPC_CheckChild1Same, 1,
/*4378*/              OPC_MoveParent,
/*4379*/              OPC_RecordChild1, // #2 = $y
/*4380*/              OPC_MoveParent,
/*4381*/              OPC_CheckType, MVT::i32,
/*4383*/              OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*4385*/              OPC_EmitNode, TARGET_VAL(AMDGPU::V_XOR_B32_e32), 0,
                          1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 2,  // Results = #3
/*4394*/              OPC_EmitInteger, MVT::i32, 0, 
/*4397*/              OPC_EmitInteger, MVT::i32, 0, 
/*4400*/              OPC_EmitInteger, MVT::i32, 0, 
/*4403*/              OPC_EmitInteger, MVT::i32, 0, 
/*4406*/              OPC_MorphNodeTo, TARGET_VAL(AMDGPU::V_BFI_B32), 0,
                          1/*#VTs*/, MVT::i32, 7/*#Ops*/, 3, 1, 2, 4, 5, 6, 7, 
                      // Src: (or:i32 (and:i32 i32:i32:$x, i32:i32:$z), (and:i32 (or:i32 i32:i32:$x, i32:i32:$z), i32:i32:$y)) - Complexity = 12
                      // Dst: (V_BFI_B32:i32 (V_XOR_B32_e32:i32 i32:i32:$x, i32:i32:$y), i32:i32:$z, i32:i32:$y)
/*4420*/            /*Scope*/ 46, /*->4467*/
/*4421*/              OPC_CheckChild0Same, 1,
/*4423*/              OPC_CheckChild1Same, 0,
/*4425*/              OPC_MoveParent,
/*4426*/              OPC_RecordChild1, // #2 = $y
/*4427*/              OPC_MoveParent,
/*4428*/              OPC_CheckType, MVT::i32,
/*4430*/              OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*4432*/              OPC_EmitNode, TARGET_VAL(AMDGPU::V_XOR_B32_e32), 0,
                          1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 2,  // Results = #3
/*4441*/              OPC_EmitInteger, MVT::i32, 0, 
/*4444*/              OPC_EmitInteger, MVT::i32, 0, 
/*4447*/              OPC_EmitInteger, MVT::i32, 0, 
/*4450*/              OPC_EmitInteger, MVT::i32, 0, 
/*4453*/              OPC_MorphNodeTo, TARGET_VAL(AMDGPU::V_BFI_B32), 0,
                          1/*#VTs*/, MVT::i32, 7/*#Ops*/, 3, 1, 2, 4, 5, 6, 7, 
                      // Src: (or:i32 (and:i32 i32:i32:$x, i32:i32:$z), (and:i32 (or:i32 i32:i32:$z, i32:i32:$x), i32:i32:$y)) - Complexity = 12
                      // Dst: (V_BFI_B32:i32 (V_XOR_B32_e32:i32 i32:i32:$x, i32:i32:$y), i32:i32:$z, i32:i32:$y)
/*4467*/            0, /*End of Scope*/
/*4468*/          /*Scope*/ 100, /*->4569*/
/*4469*/            OPC_RecordChild0, // #2 = $y
/*4470*/            OPC_MoveChild, 1,
/*4472*/            OPC_CheckOpcode, TARGET_VAL(ISD::OR),
/*4475*/            OPC_Scope, 45, /*->4522*/ // 2 children in Scope
/*4477*/              OPC_CheckChild0Same, 1,
/*4479*/              OPC_CheckChild1Same, 0,
/*4481*/              OPC_MoveParent,
/*4482*/              OPC_MoveParent,
/*4483*/              OPC_CheckType, MVT::i32,
/*4485*/              OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*4487*/              OPC_EmitNode, TARGET_VAL(AMDGPU::V_XOR_B32_e32), 0,
                          1/*#VTs*/, MVT::i32, 2/*#Ops*/, 1, 2,  // Results = #3
/*4496*/              OPC_EmitInteger, MVT::i32, 0, 
/*4499*/              OPC_EmitInteger, MVT::i32, 0, 
/*4502*/              OPC_EmitInteger, MVT::i32, 0, 
/*4505*/              OPC_EmitInteger, MVT::i32, 0, 
/*4508*/              OPC_MorphNodeTo, TARGET_VAL(AMDGPU::V_BFI_B32), 0,
                          1/*#VTs*/, MVT::i32, 7/*#Ops*/, 3, 0, 2, 4, 5, 6, 7, 
                      // Src: (or:i32 (and:i32 i32:i32:$z, i32:i32:$x), (and:i32 i32:i32:$y, (or:i32 i32:i32:$x, i32:i32:$z))) - Complexity = 12
                      // Dst: (V_BFI_B32:i32 (V_XOR_B32_e32:i32 i32:i32:$x, i32:i32:$y), i32:i32:$z, i32:i32:$y)
/*4522*/            /*Scope*/ 45, /*->4568*/
/*4523*/              OPC_CheckChild0Same, 0,
/*4525*/              OPC_CheckChild1Same, 1,
/*4527*/              OPC_MoveParent,
/*4528*/              OPC_MoveParent,
/*4529*/              OPC_CheckType, MVT::i32,
/*4531*/              OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*4533*/              OPC_EmitNode, TARGET_VAL(AMDGPU::V_XOR_B32_e32), 0,
                          1/*#VTs*/, MVT::i32, 2/*#Ops*/, 1, 2,  // Results = #3
/*4542*/              OPC_EmitInteger, MVT::i32, 0, 
/*4545*/              OPC_EmitInteger, MVT::i32, 0, 
/*4548*/              OPC_EmitInteger, MVT::i32, 0, 
/*4551*/              OPC_EmitInteger, MVT::i32, 0, 
/*4554*/              OPC_MorphNodeTo, TARGET_VAL(AMDGPU::V_BFI_B32), 0,
                          1/*#VTs*/, MVT::i32, 7/*#Ops*/, 3, 0, 2, 4, 5, 6, 7, 
                      // Src: (or:i32 (and:i32 i32:i32:$z, i32:i32:$x), (and:i32 i32:i32:$y, (or:i32 i32:i32:$z, i32:i32:$x))) - Complexity = 12
                      // Dst: (V_BFI_B32:i32 (V_XOR_B32_e32:i32 i32:i32:$x, i32:i32:$y), i32:i32:$z, i32:i32:$y)
/*4568*/            0, /*End of Scope*/
/*4569*/          /*Scope*/ 101, /*->4671*/
/*4570*/            OPC_MoveChild, 0,
/*4572*/            OPC_CheckOpcode, TARGET_VAL(ISD::OR),
/*4575*/            OPC_Scope, 46, /*->4623*/ // 2 children in Scope
/*4577*/              OPC_CheckChild0Same, 1,
/*4579*/              OPC_CheckChild1Same, 0,
/*4581*/              OPC_MoveParent,
/*4582*/              OPC_RecordChild1, // #2 = $y
/*4583*/              OPC_MoveParent,
/*4584*/              OPC_CheckType, MVT::i32,
/*4586*/              OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*4588*/              OPC_EmitNode, TARGET_VAL(AMDGPU::V_XOR_B32_e32), 0,
                          1/*#VTs*/, MVT::i32, 2/*#Ops*/, 1, 2,  // Results = #3
/*4597*/              OPC_EmitInteger, MVT::i32, 0, 
/*4600*/              OPC_EmitInteger, MVT::i32, 0, 
/*4603*/              OPC_EmitInteger, MVT::i32, 0, 
/*4606*/              OPC_EmitInteger, MVT::i32, 0, 
/*4609*/              OPC_MorphNodeTo, TARGET_VAL(AMDGPU::V_BFI_B32), 0,
                          1/*#VTs*/, MVT::i32, 7/*#Ops*/, 3, 0, 2, 4, 5, 6, 7, 
                      // Src: (or:i32 (and:i32 i32:i32:$z, i32:i32:$x), (and:i32 (or:i32 i32:i32:$x, i32:i32:$z), i32:i32:$y)) - Complexity = 12
                      // Dst: (V_BFI_B32:i32 (V_XOR_B32_e32:i32 i32:i32:$x, i32:i32:$y), i32:i32:$z, i32:i32:$y)
/*4623*/            /*Scope*/ 46, /*->4670*/
/*4624*/              OPC_CheckChild0Same, 0,
/*4626*/              OPC_CheckChild1Same, 1,
/*4628*/              OPC_MoveParent,
/*4629*/              OPC_RecordChild1, // #2 = $y
/*4630*/              OPC_MoveParent,
/*4631*/              OPC_CheckType, MVT::i32,
/*4633*/              OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*4635*/              OPC_EmitNode, TARGET_VAL(AMDGPU::V_XOR_B32_e32), 0,
                          1/*#VTs*/, MVT::i32, 2/*#Ops*/, 1, 2,  // Results = #3
/*4644*/              OPC_EmitInteger, MVT::i32, 0, 
/*4647*/              OPC_EmitInteger, MVT::i32, 0, 
/*4650*/              OPC_EmitInteger, MVT::i32, 0, 
/*4653*/              OPC_EmitInteger, MVT::i32, 0, 
/*4656*/              OPC_MorphNodeTo, TARGET_VAL(AMDGPU::V_BFI_B32), 0,
                          1/*#VTs*/, MVT::i32, 7/*#Ops*/, 3, 0, 2, 4, 5, 6, 7, 
                      // Src: (or:i32 (and:i32 i32:i32:$z, i32:i32:$x), (and:i32 (or:i32 i32:i32:$z, i32:i32:$x), i32:i32:$y)) - Complexity = 12
                      // Dst: (V_BFI_B32:i32 (V_XOR_B32_e32:i32 i32:i32:$x, i32:i32:$y), i32:i32:$z, i32:i32:$y)
/*4670*/            0, /*End of Scope*/
/*4671*/          0, /*End of Scope*/
/*4672*/        /*Scope*/ 62|128,1/*190*/, /*->4864*/
/*4674*/          OPC_MoveChild, 1,
/*4676*/          OPC_CheckOpcode, TARGET_VAL(ISD::OR),
/*4679*/          OPC_RecordChild0, // #1 = $x
/*4680*/          OPC_RecordChild1, // #2 = $z
/*4681*/          OPC_MoveParent,
/*4682*/          OPC_MoveParent,
/*4683*/          OPC_MoveChild, 1,
/*4685*/          OPC_CheckOpcode, TARGET_VAL(ISD::AND),
/*4688*/          OPC_Scope, 44, /*->4734*/ // 3 children in Scope
/*4690*/            OPC_CheckChild0Same, 1,
/*4692*/            OPC_CheckChild1Same, 2,
/*4694*/            OPC_MoveParent,
/*4695*/            OPC_CheckType, MVT::i32,
/*4697*/            OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*4699*/            OPC_EmitNode, TARGET_VAL(AMDGPU::V_XOR_B32_e32), 0,
                        1/*#VTs*/, MVT::i32, 2/*#Ops*/, 1, 0,  // Results = #3
/*4708*/            OPC_EmitInteger, MVT::i32, 0, 
/*4711*/            OPC_EmitInteger, MVT::i32, 0, 
/*4714*/            OPC_EmitInteger, MVT::i32, 0, 
/*4717*/            OPC_EmitInteger, MVT::i32, 0, 
/*4720*/            OPC_MorphNodeTo, TARGET_VAL(AMDGPU::V_BFI_B32), 0,
                        1/*#VTs*/, MVT::i32, 7/*#Ops*/, 3, 2, 0, 4, 5, 6, 7, 
                    // Src: (or:i32 (and:i32 i32:i32:$y, (or:i32 i32:i32:$x, i32:i32:$z)), (and:i32 i32:i32:$x, i32:i32:$z)) - Complexity = 12
                    // Dst: (V_BFI_B32:i32 (V_XOR_B32_e32:i32 i32:i32:$x, i32:i32:$y), i32:i32:$z, i32:i32:$y)
/*4734*/          /*Scope*/ 83, /*->4818*/
/*4735*/            OPC_CheckChild0Same, 2,
/*4737*/            OPC_CheckChild1Same, 1,
/*4739*/            OPC_MoveParent,
/*4740*/            OPC_CheckType, MVT::i32,
/*4742*/            OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*4744*/            OPC_Scope, 35, /*->4781*/ // 2 children in Scope
/*4746*/              OPC_EmitNode, TARGET_VAL(AMDGPU::V_XOR_B32_e32), 0,
                          1/*#VTs*/, MVT::i32, 2/*#Ops*/, 1, 0,  // Results = #3
/*4755*/              OPC_EmitInteger, MVT::i32, 0, 
/*4758*/              OPC_EmitInteger, MVT::i32, 0, 
/*4761*/              OPC_EmitInteger, MVT::i32, 0, 
/*4764*/              OPC_EmitInteger, MVT::i32, 0, 
/*4767*/              OPC_MorphNodeTo, TARGET_VAL(AMDGPU::V_BFI_B32), 0,
                          1/*#VTs*/, MVT::i32, 7/*#Ops*/, 3, 2, 0, 4, 5, 6, 7, 
                      // Src: (or:i32 (and:i32 i32:i32:$y, (or:i32 i32:i32:$x, i32:i32:$z)), (and:i32 i32:i32:$z, i32:i32:$x)) - Complexity = 12
                      // Dst: (V_BFI_B32:i32 (V_XOR_B32_e32:i32 i32:i32:$x, i32:i32:$y), i32:i32:$z, i32:i32:$y)
/*4781*/            /*Scope*/ 35, /*->4817*/
/*4782*/              OPC_EmitNode, TARGET_VAL(AMDGPU::V_XOR_B32_e32), 0,
                          1/*#VTs*/, MVT::i32, 2/*#Ops*/, 2, 0,  // Results = #3
/*4791*/              OPC_EmitInteger, MVT::i32, 0, 
/*4794*/              OPC_EmitInteger, MVT::i32, 0, 
/*4797*/              OPC_EmitInteger, MVT::i32, 0, 
/*4800*/              OPC_EmitInteger, MVT::i32, 0, 
/*4803*/              OPC_MorphNodeTo, TARGET_VAL(AMDGPU::V_BFI_B32), 0,
                          1/*#VTs*/, MVT::i32, 7/*#Ops*/, 3, 1, 0, 4, 5, 6, 7, 
                      // Src: (or:i32 (and:i32 i32:i32:$y, (or:i32 i32:i32:$z, i32:i32:$x)), (and:i32 i32:i32:$x, i32:i32:$z)) - Complexity = 12
                      // Dst: (V_BFI_B32:i32 (V_XOR_B32_e32:i32 i32:i32:$x, i32:i32:$y), i32:i32:$z, i32:i32:$y)
/*4817*/            0, /*End of Scope*/
/*4818*/          /*Scope*/ 44, /*->4863*/
/*4819*/            OPC_CheckChild0Same, 1,
/*4821*/            OPC_CheckChild1Same, 2,
/*4823*/            OPC_MoveParent,
/*4824*/            OPC_CheckType, MVT::i32,
/*4826*/            OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*4828*/            OPC_EmitNode, TARGET_VAL(AMDGPU::V_XOR_B32_e32), 0,
                        1/*#VTs*/, MVT::i32, 2/*#Ops*/, 2, 0,  // Results = #3
/*4837*/            OPC_EmitInteger, MVT::i32, 0, 
/*4840*/            OPC_EmitInteger, MVT::i32, 0, 
/*4843*/            OPC_EmitInteger, MVT::i32, 0, 
/*4846*/            OPC_EmitInteger, MVT::i32, 0, 
/*4849*/            OPC_MorphNodeTo, TARGET_VAL(AMDGPU::V_BFI_B32), 0,
                        1/*#VTs*/, MVT::i32, 7/*#Ops*/, 3, 1, 0, 4, 5, 6, 7, 
                    // Src: (or:i32 (and:i32 i32:i32:$y, (or:i32 i32:i32:$z, i32:i32:$x)), (and:i32 i32:i32:$z, i32:i32:$x)) - Complexity = 12
                    // Dst: (V_BFI_B32:i32 (V_XOR_B32_e32:i32 i32:i32:$x, i32:i32:$y), i32:i32:$z, i32:i32:$y)
/*4863*/          0, /*End of Scope*/
/*4864*/        0, /*End of Scope*/
/*4865*/      /*Scope*/ 63|128,1/*191*/, /*->5058*/
/*4867*/        OPC_MoveChild, 0,
/*4869*/        OPC_CheckOpcode, TARGET_VAL(ISD::OR),
/*4872*/        OPC_RecordChild0, // #0 = $x
/*4873*/        OPC_RecordChild1, // #1 = $z
/*4874*/        OPC_MoveParent,
/*4875*/        OPC_RecordChild1, // #2 = $y
/*4876*/        OPC_MoveParent,
/*4877*/        OPC_MoveChild, 1,
/*4879*/        OPC_CheckOpcode, TARGET_VAL(ISD::AND),
/*4882*/        OPC_Scope, 44, /*->4928*/ // 3 children in Scope
/*4884*/          OPC_CheckChild0Same, 0,
/*4886*/          OPC_CheckChild1Same, 1,
/*4888*/          OPC_MoveParent,
/*4889*/          OPC_CheckType, MVT::i32,
/*4891*/          OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*4893*/          OPC_EmitNode, TARGET_VAL(AMDGPU::V_XOR_B32_e32), 0,
                      1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 2,  // Results = #3
/*4902*/          OPC_EmitInteger, MVT::i32, 0, 
/*4905*/          OPC_EmitInteger, MVT::i32, 0, 
/*4908*/          OPC_EmitInteger, MVT::i32, 0, 
/*4911*/          OPC_EmitInteger, MVT::i32, 0, 
/*4914*/          OPC_MorphNodeTo, TARGET_VAL(AMDGPU::V_BFI_B32), 0,
                      1/*#VTs*/, MVT::i32, 7/*#Ops*/, 3, 1, 2, 4, 5, 6, 7, 
                  // Src: (or:i32 (and:i32 (or:i32 i32:i32:$x, i32:i32:$z), i32:i32:$y), (and:i32 i32:i32:$x, i32:i32:$z)) - Complexity = 12
                  // Dst: (V_BFI_B32:i32 (V_XOR_B32_e32:i32 i32:i32:$x, i32:i32:$y), i32:i32:$z, i32:i32:$y)
/*4928*/        /*Scope*/ 83, /*->5012*/
/*4929*/          OPC_CheckChild0Same, 1,
/*4931*/          OPC_CheckChild1Same, 0,
/*4933*/          OPC_MoveParent,
/*4934*/          OPC_CheckType, MVT::i32,
/*4936*/          OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*4938*/          OPC_Scope, 35, /*->4975*/ // 2 children in Scope
/*4940*/            OPC_EmitNode, TARGET_VAL(AMDGPU::V_XOR_B32_e32), 0,
                        1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 2,  // Results = #3
/*4949*/            OPC_EmitInteger, MVT::i32, 0, 
/*4952*/            OPC_EmitInteger, MVT::i32, 0, 
/*4955*/            OPC_EmitInteger, MVT::i32, 0, 
/*4958*/            OPC_EmitInteger, MVT::i32, 0, 
/*4961*/            OPC_MorphNodeTo, TARGET_VAL(AMDGPU::V_BFI_B32), 0,
                        1/*#VTs*/, MVT::i32, 7/*#Ops*/, 3, 1, 2, 4, 5, 6, 7, 
                    // Src: (or:i32 (and:i32 (or:i32 i32:i32:$x, i32:i32:$z), i32:i32:$y), (and:i32 i32:i32:$z, i32:i32:$x)) - Complexity = 12
                    // Dst: (V_BFI_B32:i32 (V_XOR_B32_e32:i32 i32:i32:$x, i32:i32:$y), i32:i32:$z, i32:i32:$y)
/*4975*/          /*Scope*/ 35, /*->5011*/
/*4976*/            OPC_EmitNode, TARGET_VAL(AMDGPU::V_XOR_B32_e32), 0,
                        1/*#VTs*/, MVT::i32, 2/*#Ops*/, 1, 2,  // Results = #3
/*4985*/            OPC_EmitInteger, MVT::i32, 0, 
/*4988*/            OPC_EmitInteger, MVT::i32, 0, 
/*4991*/            OPC_EmitInteger, MVT::i32, 0, 
/*4994*/            OPC_EmitInteger, MVT::i32, 0, 
/*4997*/            OPC_MorphNodeTo, TARGET_VAL(AMDGPU::V_BFI_B32), 0,
                        1/*#VTs*/, MVT::i32, 7/*#Ops*/, 3, 0, 2, 4, 5, 6, 7, 
                    // Src: (or:i32 (and:i32 (or:i32 i32:i32:$z, i32:i32:$x), i32:i32:$y), (and:i32 i32:i32:$x, i32:i32:$z)) - Complexity = 12
                    // Dst: (V_BFI_B32:i32 (V_XOR_B32_e32:i32 i32:i32:$x, i32:i32:$y), i32:i32:$z, i32:i32:$y)
/*5011*/          0, /*End of Scope*/
/*5012*/        /*Scope*/ 44, /*->5057*/
/*5013*/          OPC_CheckChild0Same, 0,
/*5015*/          OPC_CheckChild1Same, 1,
/*5017*/          OPC_MoveParent,
/*5018*/          OPC_CheckType, MVT::i32,
/*5020*/          OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*5022*/          OPC_EmitNode, TARGET_VAL(AMDGPU::V_XOR_B32_e32), 0,
                      1/*#VTs*/, MVT::i32, 2/*#Ops*/, 1, 2,  // Results = #3
/*5031*/          OPC_EmitInteger, MVT::i32, 0, 
/*5034*/          OPC_EmitInteger, MVT::i32, 0, 
/*5037*/          OPC_EmitInteger, MVT::i32, 0, 
/*5040*/          OPC_EmitInteger, MVT::i32, 0, 
/*5043*/          OPC_MorphNodeTo, TARGET_VAL(AMDGPU::V_BFI_B32), 0,
                      1/*#VTs*/, MVT::i32, 7/*#Ops*/, 3, 0, 2, 4, 5, 6, 7, 
                  // Src: (or:i32 (and:i32 (or:i32 i32:i32:$z, i32:i32:$x), i32:i32:$y), (and:i32 i32:i32:$z, i32:i32:$x)) - Complexity = 12
                  // Dst: (V_BFI_B32:i32 (V_XOR_B32_e32:i32 i32:i32:$x, i32:i32:$y), i32:i32:$z, i32:i32:$y)
/*5057*/        0, /*End of Scope*/
/*5058*/      /*Scope*/ 93|128,17/*2269*/, /*->7329*/
/*5060*/        OPC_RecordChild0, // #0 = $x
/*5061*/        OPC_Scope, 95|128,11/*1503*/, /*->6567*/ // 2 children in Scope
/*5064*/          OPC_RecordChild1, // #1 = $z
/*5065*/          OPC_MoveParent,
/*5066*/          OPC_MoveChild, 1,
/*5068*/          OPC_CheckOpcode, TARGET_VAL(ISD::AND),
/*5071*/          OPC_Scope, 84|128,1/*212*/, /*->5286*/ // 4 children in Scope
/*5074*/            OPC_RecordChild0, // #2 = $y
/*5075*/            OPC_MoveChild, 1,
/*5077*/            OPC_CheckOpcode, TARGET_VAL(ISD::OR),
/*5080*/            OPC_CheckChild0Same, 1,
/*5082*/            OPC_CheckChild1Same, 0,
/*5084*/            OPC_MoveParent,
/*5085*/            OPC_MoveParent,
/*5086*/            OPC_CheckType, MVT::i32,
/*5088*/            OPC_CheckPatternPredicate, 2, // (Subtarget.getGeneration() == AMDGPUSubtarget::EVERGREEN|| Subtarget.getGeneration() ==AMDGPUSubtarget::NORTHERN_ISLANDS)
/*5090*/            OPC_EmitInteger, MVT::i32, 0, 
/*5093*/            OPC_EmitInteger, MVT::i32, 0, 
/*5096*/            OPC_EmitInteger, MVT::i32, 0, 
/*5099*/            OPC_EmitInteger, MVT::i32, 0, 
/*5102*/            OPC_EmitInteger, MVT::i32, 1, 
/*5105*/            OPC_EmitInteger, MVT::i32, 0, 
/*5108*/            OPC_EmitInteger, MVT::i32, 0, 
/*5111*/            OPC_EmitInteger, MVT::i32, 0, 
/*5114*/            OPC_EmitInteger, MVT::i32, 0, 
/*5117*/            OPC_EmitInteger, MVT::i32, 0, 
/*5120*/            OPC_EmitInteger, MVT::i32, 0, 
/*5123*/            OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*5135*/            OPC_EmitInteger, MVT::i32, 0, 
/*5138*/            OPC_EmitInteger, MVT::i32, 0, 
/*5141*/            OPC_EmitInteger, MVT::i32, 0, 
/*5144*/            OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*5156*/            OPC_EmitInteger, MVT::i32, 1, 
/*5159*/            OPC_EmitRegister, MVT::i32, AMDGPU::PRED_SEL_OFF,
/*5162*/            OPC_EmitInteger, MVT::i32, 0, 
/*5165*/            OPC_EmitInteger, MVT::i32, 0, 
/*5168*/            OPC_EmitNode, TARGET_VAL(AMDGPU::XOR_INT), 0,
                        1/*#VTs*/, MVT::i32, 20/*#Ops*/, 5, 6, 7, 8, 9, 10, 0, 11, 12, 13, 14, 2, 15, 16, 17, 18, 19, 20, 21, 22,  // Results = #23
/*5195*/            OPC_EmitInteger, MVT::i32, 0, 
/*5198*/            OPC_EmitInteger, MVT::i32, 0, 
/*5201*/            OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*5213*/            OPC_EmitInteger, MVT::i32, 0, 
/*5216*/            OPC_EmitInteger, MVT::i32, 0, 
/*5219*/            OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*5231*/            OPC_EmitInteger, MVT::i32, 0, 
/*5234*/            OPC_EmitInteger, MVT::i32, 0, 
/*5237*/            OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*5249*/            OPC_EmitInteger, MVT::i32, 1, 
/*5252*/            OPC_EmitRegister, MVT::i32, AMDGPU::PRED_SEL_OFF,
/*5255*/            OPC_EmitInteger, MVT::i32, 0, 
/*5258*/            OPC_EmitInteger, MVT::i32, 0, 
/*5261*/            OPC_MorphNodeTo, TARGET_VAL(AMDGPU::BFI_INT_eg), 0,
                        1/*#VTs*/, MVT::i32, 18/*#Ops*/, 3, 4, 23, 24, 25, 26, 1, 27, 28, 29, 2, 30, 31, 32, 33, 34, 35, 36, 
                    // Src: (or:i32 (and:i32 i32:i32:$x, i32:i32:$z), (and:i32 i32:i32:$y, (or:i32 i32:i32:$z, i32:i32:$x))) - Complexity = 12
                    // Dst: (BFI_INT_eg:i32 (XOR_INT:i32 i32:i32:$x, i32:i32:$y), i32:i32:$z, i32:i32:$y)
/*5286*/          /*Scope*/ 41|128,3/*425*/, /*->5713*/
/*5288*/            OPC_MoveChild, 0,
/*5290*/            OPC_CheckOpcode, TARGET_VAL(ISD::OR),
/*5293*/            OPC_Scope, 79|128,1/*207*/, /*->5503*/ // 2 children in Scope
/*5296*/              OPC_CheckChild0Same, 0,
/*5298*/              OPC_CheckChild1Same, 1,
/*5300*/              OPC_MoveParent,
/*5301*/              OPC_RecordChild1, // #2 = $y
/*5302*/              OPC_MoveParent,
/*5303*/              OPC_CheckType, MVT::i32,
/*5305*/              OPC_CheckPatternPredicate, 2, // (Subtarget.getGeneration() == AMDGPUSubtarget::EVERGREEN|| Subtarget.getGeneration() ==AMDGPUSubtarget::NORTHERN_ISLANDS)
/*5307*/              OPC_EmitInteger, MVT::i32, 0, 
/*5310*/              OPC_EmitInteger, MVT::i32, 0, 
/*5313*/              OPC_EmitInteger, MVT::i32, 0, 
/*5316*/              OPC_EmitInteger, MVT::i32, 0, 
/*5319*/              OPC_EmitInteger, MVT::i32, 1, 
/*5322*/              OPC_EmitInteger, MVT::i32, 0, 
/*5325*/              OPC_EmitInteger, MVT::i32, 0, 
/*5328*/              OPC_EmitInteger, MVT::i32, 0, 
/*5331*/              OPC_EmitInteger, MVT::i32, 0, 
/*5334*/              OPC_EmitInteger, MVT::i32, 0, 
/*5337*/              OPC_EmitInteger, MVT::i32, 0, 
/*5340*/              OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*5352*/              OPC_EmitInteger, MVT::i32, 0, 
/*5355*/              OPC_EmitInteger, MVT::i32, 0, 
/*5358*/              OPC_EmitInteger, MVT::i32, 0, 
/*5361*/              OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*5373*/              OPC_EmitInteger, MVT::i32, 1, 
/*5376*/              OPC_EmitRegister, MVT::i32, AMDGPU::PRED_SEL_OFF,
/*5379*/              OPC_EmitInteger, MVT::i32, 0, 
/*5382*/              OPC_EmitInteger, MVT::i32, 0, 
/*5385*/              OPC_EmitNode, TARGET_VAL(AMDGPU::XOR_INT), 0,
                          1/*#VTs*/, MVT::i32, 20/*#Ops*/, 5, 6, 7, 8, 9, 10, 0, 11, 12, 13, 14, 2, 15, 16, 17, 18, 19, 20, 21, 22,  // Results = #23
/*5412*/              OPC_EmitInteger, MVT::i32, 0, 
/*5415*/              OPC_EmitInteger, MVT::i32, 0, 
/*5418*/              OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*5430*/              OPC_EmitInteger, MVT::i32, 0, 
/*5433*/              OPC_EmitInteger, MVT::i32, 0, 
/*5436*/              OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*5448*/              OPC_EmitInteger, MVT::i32, 0, 
/*5451*/              OPC_EmitInteger, MVT::i32, 0, 
/*5454*/              OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*5466*/              OPC_EmitInteger, MVT::i32, 1, 
/*5469*/              OPC_EmitRegister, MVT::i32, AMDGPU::PRED_SEL_OFF,
/*5472*/              OPC_EmitInteger, MVT::i32, 0, 
/*5475*/              OPC_EmitInteger, MVT::i32, 0, 
/*5478*/              OPC_MorphNodeTo, TARGET_VAL(AMDGPU::BFI_INT_eg), 0,
                          1/*#VTs*/, MVT::i32, 18/*#Ops*/, 3, 4, 23, 24, 25, 26, 1, 27, 28, 29, 2, 30, 31, 32, 33, 34, 35, 36, 
                      // Src: (or:i32 (and:i32 i32:i32:$x, i32:i32:$z), (and:i32 (or:i32 i32:i32:$x, i32:i32:$z), i32:i32:$y)) - Complexity = 12
                      // Dst: (BFI_INT_eg:i32 (XOR_INT:i32 i32:i32:$x, i32:i32:$y), i32:i32:$z, i32:i32:$y)
/*5503*/            /*Scope*/ 79|128,1/*207*/, /*->5712*/
/*5505*/              OPC_CheckChild0Same, 1,
/*5507*/              OPC_CheckChild1Same, 0,
/*5509*/              OPC_MoveParent,
/*5510*/              OPC_RecordChild1, // #2 = $y
/*5511*/              OPC_MoveParent,
/*5512*/              OPC_CheckType, MVT::i32,
/*5514*/              OPC_CheckPatternPredicate, 2, // (Subtarget.getGeneration() == AMDGPUSubtarget::EVERGREEN|| Subtarget.getGeneration() ==AMDGPUSubtarget::NORTHERN_ISLANDS)
/*5516*/              OPC_EmitInteger, MVT::i32, 0, 
/*5519*/              OPC_EmitInteger, MVT::i32, 0, 
/*5522*/              OPC_EmitInteger, MVT::i32, 0, 
/*5525*/              OPC_EmitInteger, MVT::i32, 0, 
/*5528*/              OPC_EmitInteger, MVT::i32, 1, 
/*5531*/              OPC_EmitInteger, MVT::i32, 0, 
/*5534*/              OPC_EmitInteger, MVT::i32, 0, 
/*5537*/              OPC_EmitInteger, MVT::i32, 0, 
/*5540*/              OPC_EmitInteger, MVT::i32, 0, 
/*5543*/              OPC_EmitInteger, MVT::i32, 0, 
/*5546*/              OPC_EmitInteger, MVT::i32, 0, 
/*5549*/              OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*5561*/              OPC_EmitInteger, MVT::i32, 0, 
/*5564*/              OPC_EmitInteger, MVT::i32, 0, 
/*5567*/              OPC_EmitInteger, MVT::i32, 0, 
/*5570*/              OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*5582*/              OPC_EmitInteger, MVT::i32, 1, 
/*5585*/              OPC_EmitRegister, MVT::i32, AMDGPU::PRED_SEL_OFF,
/*5588*/              OPC_EmitInteger, MVT::i32, 0, 
/*5591*/              OPC_EmitInteger, MVT::i32, 0, 
/*5594*/              OPC_EmitNode, TARGET_VAL(AMDGPU::XOR_INT), 0,
                          1/*#VTs*/, MVT::i32, 20/*#Ops*/, 5, 6, 7, 8, 9, 10, 0, 11, 12, 13, 14, 2, 15, 16, 17, 18, 19, 20, 21, 22,  // Results = #23
/*5621*/              OPC_EmitInteger, MVT::i32, 0, 
/*5624*/              OPC_EmitInteger, MVT::i32, 0, 
/*5627*/              OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*5639*/              OPC_EmitInteger, MVT::i32, 0, 
/*5642*/              OPC_EmitInteger, MVT::i32, 0, 
/*5645*/              OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*5657*/              OPC_EmitInteger, MVT::i32, 0, 
/*5660*/              OPC_EmitInteger, MVT::i32, 0, 
/*5663*/              OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*5675*/              OPC_EmitInteger, MVT::i32, 1, 
/*5678*/              OPC_EmitRegister, MVT::i32, AMDGPU::PRED_SEL_OFF,
/*5681*/              OPC_EmitInteger, MVT::i32, 0, 
/*5684*/              OPC_EmitInteger, MVT::i32, 0, 
/*5687*/              OPC_MorphNodeTo, TARGET_VAL(AMDGPU::BFI_INT_eg), 0,
                          1/*#VTs*/, MVT::i32, 18/*#Ops*/, 3, 4, 23, 24, 25, 26, 1, 27, 28, 29, 2, 30, 31, 32, 33, 34, 35, 36, 
                      // Src: (or:i32 (and:i32 i32:i32:$x, i32:i32:$z), (and:i32 (or:i32 i32:i32:$z, i32:i32:$x), i32:i32:$y)) - Complexity = 12
                      // Dst: (BFI_INT_eg:i32 (XOR_INT:i32 i32:i32:$x, i32:i32:$y), i32:i32:$z, i32:i32:$y)
/*5712*/            0, /*End of Scope*/
/*5713*/          /*Scope*/ 40|128,3/*424*/, /*->6139*/
/*5715*/            OPC_RecordChild0, // #2 = $y
/*5716*/            OPC_MoveChild, 1,
/*5718*/            OPC_CheckOpcode, TARGET_VAL(ISD::OR),
/*5721*/            OPC_Scope, 78|128,1/*206*/, /*->5930*/ // 2 children in Scope
/*5724*/              OPC_CheckChild0Same, 1,
/*5726*/              OPC_CheckChild1Same, 0,
/*5728*/              OPC_MoveParent,
/*5729*/              OPC_MoveParent,
/*5730*/              OPC_CheckType, MVT::i32,
/*5732*/              OPC_CheckPatternPredicate, 2, // (Subtarget.getGeneration() == AMDGPUSubtarget::EVERGREEN|| Subtarget.getGeneration() ==AMDGPUSubtarget::NORTHERN_ISLANDS)
/*5734*/              OPC_EmitInteger, MVT::i32, 0, 
/*5737*/              OPC_EmitInteger, MVT::i32, 0, 
/*5740*/              OPC_EmitInteger, MVT::i32, 0, 
/*5743*/              OPC_EmitInteger, MVT::i32, 0, 
/*5746*/              OPC_EmitInteger, MVT::i32, 1, 
/*5749*/              OPC_EmitInteger, MVT::i32, 0, 
/*5752*/              OPC_EmitInteger, MVT::i32, 0, 
/*5755*/              OPC_EmitInteger, MVT::i32, 0, 
/*5758*/              OPC_EmitInteger, MVT::i32, 0, 
/*5761*/              OPC_EmitInteger, MVT::i32, 0, 
/*5764*/              OPC_EmitInteger, MVT::i32, 0, 
/*5767*/              OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*5779*/              OPC_EmitInteger, MVT::i32, 0, 
/*5782*/              OPC_EmitInteger, MVT::i32, 0, 
/*5785*/              OPC_EmitInteger, MVT::i32, 0, 
/*5788*/              OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*5800*/              OPC_EmitInteger, MVT::i32, 1, 
/*5803*/              OPC_EmitRegister, MVT::i32, AMDGPU::PRED_SEL_OFF,
/*5806*/              OPC_EmitInteger, MVT::i32, 0, 
/*5809*/              OPC_EmitInteger, MVT::i32, 0, 
/*5812*/              OPC_EmitNode, TARGET_VAL(AMDGPU::XOR_INT), 0,
                          1/*#VTs*/, MVT::i32, 20/*#Ops*/, 5, 6, 7, 8, 9, 10, 1, 11, 12, 13, 14, 2, 15, 16, 17, 18, 19, 20, 21, 22,  // Results = #23
/*5839*/              OPC_EmitInteger, MVT::i32, 0, 
/*5842*/              OPC_EmitInteger, MVT::i32, 0, 
/*5845*/              OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*5857*/              OPC_EmitInteger, MVT::i32, 0, 
/*5860*/              OPC_EmitInteger, MVT::i32, 0, 
/*5863*/              OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*5875*/              OPC_EmitInteger, MVT::i32, 0, 
/*5878*/              OPC_EmitInteger, MVT::i32, 0, 
/*5881*/              OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*5893*/              OPC_EmitInteger, MVT::i32, 1, 
/*5896*/              OPC_EmitRegister, MVT::i32, AMDGPU::PRED_SEL_OFF,
/*5899*/              OPC_EmitInteger, MVT::i32, 0, 
/*5902*/              OPC_EmitInteger, MVT::i32, 0, 
/*5905*/              OPC_MorphNodeTo, TARGET_VAL(AMDGPU::BFI_INT_eg), 0,
                          1/*#VTs*/, MVT::i32, 18/*#Ops*/, 3, 4, 23, 24, 25, 26, 0, 27, 28, 29, 2, 30, 31, 32, 33, 34, 35, 36, 
                      // Src: (or:i32 (and:i32 i32:i32:$z, i32:i32:$x), (and:i32 i32:i32:$y, (or:i32 i32:i32:$x, i32:i32:$z))) - Complexity = 12
                      // Dst: (BFI_INT_eg:i32 (XOR_INT:i32 i32:i32:$x, i32:i32:$y), i32:i32:$z, i32:i32:$y)
/*5930*/            /*Scope*/ 78|128,1/*206*/, /*->6138*/
/*5932*/              OPC_CheckChild0Same, 0,
/*5934*/              OPC_CheckChild1Same, 1,
/*5936*/              OPC_MoveParent,
/*5937*/              OPC_MoveParent,
/*5938*/              OPC_CheckType, MVT::i32,
/*5940*/              OPC_CheckPatternPredicate, 2, // (Subtarget.getGeneration() == AMDGPUSubtarget::EVERGREEN|| Subtarget.getGeneration() ==AMDGPUSubtarget::NORTHERN_ISLANDS)
/*5942*/              OPC_EmitInteger, MVT::i32, 0, 
/*5945*/              OPC_EmitInteger, MVT::i32, 0, 
/*5948*/              OPC_EmitInteger, MVT::i32, 0, 
/*5951*/              OPC_EmitInteger, MVT::i32, 0, 
/*5954*/              OPC_EmitInteger, MVT::i32, 1, 
/*5957*/              OPC_EmitInteger, MVT::i32, 0, 
/*5960*/              OPC_EmitInteger, MVT::i32, 0, 
/*5963*/              OPC_EmitInteger, MVT::i32, 0, 
/*5966*/              OPC_EmitInteger, MVT::i32, 0, 
/*5969*/              OPC_EmitInteger, MVT::i32, 0, 
/*5972*/              OPC_EmitInteger, MVT::i32, 0, 
/*5975*/              OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*5987*/              OPC_EmitInteger, MVT::i32, 0, 
/*5990*/              OPC_EmitInteger, MVT::i32, 0, 
/*5993*/              OPC_EmitInteger, MVT::i32, 0, 
/*5996*/              OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*6008*/              OPC_EmitInteger, MVT::i32, 1, 
/*6011*/              OPC_EmitRegister, MVT::i32, AMDGPU::PRED_SEL_OFF,
/*6014*/              OPC_EmitInteger, MVT::i32, 0, 
/*6017*/              OPC_EmitInteger, MVT::i32, 0, 
/*6020*/              OPC_EmitNode, TARGET_VAL(AMDGPU::XOR_INT), 0,
                          1/*#VTs*/, MVT::i32, 20/*#Ops*/, 5, 6, 7, 8, 9, 10, 1, 11, 12, 13, 14, 2, 15, 16, 17, 18, 19, 20, 21, 22,  // Results = #23
/*6047*/              OPC_EmitInteger, MVT::i32, 0, 
/*6050*/              OPC_EmitInteger, MVT::i32, 0, 
/*6053*/              OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*6065*/              OPC_EmitInteger, MVT::i32, 0, 
/*6068*/              OPC_EmitInteger, MVT::i32, 0, 
/*6071*/              OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*6083*/              OPC_EmitInteger, MVT::i32, 0, 
/*6086*/              OPC_EmitInteger, MVT::i32, 0, 
/*6089*/              OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*6101*/              OPC_EmitInteger, MVT::i32, 1, 
/*6104*/              OPC_EmitRegister, MVT::i32, AMDGPU::PRED_SEL_OFF,
/*6107*/              OPC_EmitInteger, MVT::i32, 0, 
/*6110*/              OPC_EmitInteger, MVT::i32, 0, 
/*6113*/              OPC_MorphNodeTo, TARGET_VAL(AMDGPU::BFI_INT_eg), 0,
                          1/*#VTs*/, MVT::i32, 18/*#Ops*/, 3, 4, 23, 24, 25, 26, 0, 27, 28, 29, 2, 30, 31, 32, 33, 34, 35, 36, 
                      // Src: (or:i32 (and:i32 i32:i32:$z, i32:i32:$x), (and:i32 i32:i32:$y, (or:i32 i32:i32:$z, i32:i32:$x))) - Complexity = 12
                      // Dst: (BFI_INT_eg:i32 (XOR_INT:i32 i32:i32:$x, i32:i32:$y), i32:i32:$z, i32:i32:$y)
/*6138*/            0, /*End of Scope*/
/*6139*/          /*Scope*/ 41|128,3/*425*/, /*->6566*/
/*6141*/            OPC_MoveChild, 0,
/*6143*/            OPC_CheckOpcode, TARGET_VAL(ISD::OR),
/*6146*/            OPC_Scope, 79|128,1/*207*/, /*->6356*/ // 2 children in Scope
/*6149*/              OPC_CheckChild0Same, 1,
/*6151*/              OPC_CheckChild1Same, 0,
/*6153*/              OPC_MoveParent,
/*6154*/              OPC_RecordChild1, // #2 = $y
/*6155*/              OPC_MoveParent,
/*6156*/              OPC_CheckType, MVT::i32,
/*6158*/              OPC_CheckPatternPredicate, 2, // (Subtarget.getGeneration() == AMDGPUSubtarget::EVERGREEN|| Subtarget.getGeneration() ==AMDGPUSubtarget::NORTHERN_ISLANDS)
/*6160*/              OPC_EmitInteger, MVT::i32, 0, 
/*6163*/              OPC_EmitInteger, MVT::i32, 0, 
/*6166*/              OPC_EmitInteger, MVT::i32, 0, 
/*6169*/              OPC_EmitInteger, MVT::i32, 0, 
/*6172*/              OPC_EmitInteger, MVT::i32, 1, 
/*6175*/              OPC_EmitInteger, MVT::i32, 0, 
/*6178*/              OPC_EmitInteger, MVT::i32, 0, 
/*6181*/              OPC_EmitInteger, MVT::i32, 0, 
/*6184*/              OPC_EmitInteger, MVT::i32, 0, 
/*6187*/              OPC_EmitInteger, MVT::i32, 0, 
/*6190*/              OPC_EmitInteger, MVT::i32, 0, 
/*6193*/              OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*6205*/              OPC_EmitInteger, MVT::i32, 0, 
/*6208*/              OPC_EmitInteger, MVT::i32, 0, 
/*6211*/              OPC_EmitInteger, MVT::i32, 0, 
/*6214*/              OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*6226*/              OPC_EmitInteger, MVT::i32, 1, 
/*6229*/              OPC_EmitRegister, MVT::i32, AMDGPU::PRED_SEL_OFF,
/*6232*/              OPC_EmitInteger, MVT::i32, 0, 
/*6235*/              OPC_EmitInteger, MVT::i32, 0, 
/*6238*/              OPC_EmitNode, TARGET_VAL(AMDGPU::XOR_INT), 0,
                          1/*#VTs*/, MVT::i32, 20/*#Ops*/, 5, 6, 7, 8, 9, 10, 1, 11, 12, 13, 14, 2, 15, 16, 17, 18, 19, 20, 21, 22,  // Results = #23
/*6265*/              OPC_EmitInteger, MVT::i32, 0, 
/*6268*/              OPC_EmitInteger, MVT::i32, 0, 
/*6271*/              OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*6283*/              OPC_EmitInteger, MVT::i32, 0, 
/*6286*/              OPC_EmitInteger, MVT::i32, 0, 
/*6289*/              OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*6301*/              OPC_EmitInteger, MVT::i32, 0, 
/*6304*/              OPC_EmitInteger, MVT::i32, 0, 
/*6307*/              OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*6319*/              OPC_EmitInteger, MVT::i32, 1, 
/*6322*/              OPC_EmitRegister, MVT::i32, AMDGPU::PRED_SEL_OFF,
/*6325*/              OPC_EmitInteger, MVT::i32, 0, 
/*6328*/              OPC_EmitInteger, MVT::i32, 0, 
/*6331*/              OPC_MorphNodeTo, TARGET_VAL(AMDGPU::BFI_INT_eg), 0,
                          1/*#VTs*/, MVT::i32, 18/*#Ops*/, 3, 4, 23, 24, 25, 26, 0, 27, 28, 29, 2, 30, 31, 32, 33, 34, 35, 36, 
                      // Src: (or:i32 (and:i32 i32:i32:$z, i32:i32:$x), (and:i32 (or:i32 i32:i32:$x, i32:i32:$z), i32:i32:$y)) - Complexity = 12
                      // Dst: (BFI_INT_eg:i32 (XOR_INT:i32 i32:i32:$x, i32:i32:$y), i32:i32:$z, i32:i32:$y)
/*6356*/            /*Scope*/ 79|128,1/*207*/, /*->6565*/
/*6358*/              OPC_CheckChild0Same, 0,
/*6360*/              OPC_CheckChild1Same, 1,
/*6362*/              OPC_MoveParent,
/*6363*/              OPC_RecordChild1, // #2 = $y
/*6364*/              OPC_MoveParent,
/*6365*/              OPC_CheckType, MVT::i32,
/*6367*/              OPC_CheckPatternPredicate, 2, // (Subtarget.getGeneration() == AMDGPUSubtarget::EVERGREEN|| Subtarget.getGeneration() ==AMDGPUSubtarget::NORTHERN_ISLANDS)
/*6369*/              OPC_EmitInteger, MVT::i32, 0, 
/*6372*/              OPC_EmitInteger, MVT::i32, 0, 
/*6375*/              OPC_EmitInteger, MVT::i32, 0, 
/*6378*/              OPC_EmitInteger, MVT::i32, 0, 
/*6381*/              OPC_EmitInteger, MVT::i32, 1, 
/*6384*/              OPC_EmitInteger, MVT::i32, 0, 
/*6387*/              OPC_EmitInteger, MVT::i32, 0, 
/*6390*/              OPC_EmitInteger, MVT::i32, 0, 
/*6393*/              OPC_EmitInteger, MVT::i32, 0, 
/*6396*/              OPC_EmitInteger, MVT::i32, 0, 
/*6399*/              OPC_EmitInteger, MVT::i32, 0, 
/*6402*/              OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*6414*/              OPC_EmitInteger, MVT::i32, 0, 
/*6417*/              OPC_EmitInteger, MVT::i32, 0, 
/*6420*/              OPC_EmitInteger, MVT::i32, 0, 
/*6423*/              OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*6435*/              OPC_EmitInteger, MVT::i32, 1, 
/*6438*/              OPC_EmitRegister, MVT::i32, AMDGPU::PRED_SEL_OFF,
/*6441*/              OPC_EmitInteger, MVT::i32, 0, 
/*6444*/              OPC_EmitInteger, MVT::i32, 0, 
/*6447*/              OPC_EmitNode, TARGET_VAL(AMDGPU::XOR_INT), 0,
                          1/*#VTs*/, MVT::i32, 20/*#Ops*/, 5, 6, 7, 8, 9, 10, 1, 11, 12, 13, 14, 2, 15, 16, 17, 18, 19, 20, 21, 22,  // Results = #23
/*6474*/              OPC_EmitInteger, MVT::i32, 0, 
/*6477*/              OPC_EmitInteger, MVT::i32, 0, 
/*6480*/              OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*6492*/              OPC_EmitInteger, MVT::i32, 0, 
/*6495*/              OPC_EmitInteger, MVT::i32, 0, 
/*6498*/              OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*6510*/              OPC_EmitInteger, MVT::i32, 0, 
/*6513*/              OPC_EmitInteger, MVT::i32, 0, 
/*6516*/              OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*6528*/              OPC_EmitInteger, MVT::i32, 1, 
/*6531*/              OPC_EmitRegister, MVT::i32, AMDGPU::PRED_SEL_OFF,
/*6534*/              OPC_EmitInteger, MVT::i32, 0, 
/*6537*/              OPC_EmitInteger, MVT::i32, 0, 
/*6540*/              OPC_MorphNodeTo, TARGET_VAL(AMDGPU::BFI_INT_eg), 0,
                          1/*#VTs*/, MVT::i32, 18/*#Ops*/, 3, 4, 23, 24, 25, 26, 0, 27, 28, 29, 2, 30, 31, 32, 33, 34, 35, 36, 
                      // Src: (or:i32 (and:i32 i32:i32:$z, i32:i32:$x), (and:i32 (or:i32 i32:i32:$z, i32:i32:$x), i32:i32:$y)) - Complexity = 12
                      // Dst: (BFI_INT_eg:i32 (XOR_INT:i32 i32:i32:$x, i32:i32:$y), i32:i32:$z, i32:i32:$y)
/*6565*/            0, /*End of Scope*/
/*6566*/          0, /*End of Scope*/
/*6567*/        /*Scope*/ 119|128,5/*759*/, /*->7328*/
/*6569*/          OPC_MoveChild, 1,
/*6571*/          OPC_CheckOpcode, TARGET_VAL(ISD::OR),
/*6574*/          OPC_RecordChild0, // #1 = $x
/*6575*/          OPC_RecordChild1, // #2 = $z
/*6576*/          OPC_MoveParent,
/*6577*/          OPC_MoveParent,
/*6578*/          OPC_MoveChild, 1,
/*6580*/          OPC_CheckOpcode, TARGET_VAL(ISD::AND),
/*6583*/          OPC_Scope, 77|128,1/*205*/, /*->6791*/ // 3 children in Scope
/*6586*/            OPC_CheckChild0Same, 1,
/*6588*/            OPC_CheckChild1Same, 2,
/*6590*/            OPC_MoveParent,
/*6591*/            OPC_CheckType, MVT::i32,
/*6593*/            OPC_CheckPatternPredicate, 2, // (Subtarget.getGeneration() == AMDGPUSubtarget::EVERGREEN|| Subtarget.getGeneration() ==AMDGPUSubtarget::NORTHERN_ISLANDS)
/*6595*/            OPC_EmitInteger, MVT::i32, 0, 
/*6598*/            OPC_EmitInteger, MVT::i32, 0, 
/*6601*/            OPC_EmitInteger, MVT::i32, 0, 
/*6604*/            OPC_EmitInteger, MVT::i32, 0, 
/*6607*/            OPC_EmitInteger, MVT::i32, 1, 
/*6610*/            OPC_EmitInteger, MVT::i32, 0, 
/*6613*/            OPC_EmitInteger, MVT::i32, 0, 
/*6616*/            OPC_EmitInteger, MVT::i32, 0, 
/*6619*/            OPC_EmitInteger, MVT::i32, 0, 
/*6622*/            OPC_EmitInteger, MVT::i32, 0, 
/*6625*/            OPC_EmitInteger, MVT::i32, 0, 
/*6628*/            OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*6640*/            OPC_EmitInteger, MVT::i32, 0, 
/*6643*/            OPC_EmitInteger, MVT::i32, 0, 
/*6646*/            OPC_EmitInteger, MVT::i32, 0, 
/*6649*/            OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*6661*/            OPC_EmitInteger, MVT::i32, 1, 
/*6664*/            OPC_EmitRegister, MVT::i32, AMDGPU::PRED_SEL_OFF,
/*6667*/            OPC_EmitInteger, MVT::i32, 0, 
/*6670*/            OPC_EmitInteger, MVT::i32, 0, 
/*6673*/            OPC_EmitNode, TARGET_VAL(AMDGPU::XOR_INT), 0,
                        1/*#VTs*/, MVT::i32, 20/*#Ops*/, 5, 6, 7, 8, 9, 10, 1, 11, 12, 13, 14, 0, 15, 16, 17, 18, 19, 20, 21, 22,  // Results = #23
/*6700*/            OPC_EmitInteger, MVT::i32, 0, 
/*6703*/            OPC_EmitInteger, MVT::i32, 0, 
/*6706*/            OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*6718*/            OPC_EmitInteger, MVT::i32, 0, 
/*6721*/            OPC_EmitInteger, MVT::i32, 0, 
/*6724*/            OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*6736*/            OPC_EmitInteger, MVT::i32, 0, 
/*6739*/            OPC_EmitInteger, MVT::i32, 0, 
/*6742*/            OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*6754*/            OPC_EmitInteger, MVT::i32, 1, 
/*6757*/            OPC_EmitRegister, MVT::i32, AMDGPU::PRED_SEL_OFF,
/*6760*/            OPC_EmitInteger, MVT::i32, 0, 
/*6763*/            OPC_EmitInteger, MVT::i32, 0, 
/*6766*/            OPC_MorphNodeTo, TARGET_VAL(AMDGPU::BFI_INT_eg), 0,
                        1/*#VTs*/, MVT::i32, 18/*#Ops*/, 3, 4, 23, 24, 25, 26, 2, 27, 28, 29, 0, 30, 31, 32, 33, 34, 35, 36, 
                    // Src: (or:i32 (and:i32 i32:i32:$y, (or:i32 i32:i32:$x, i32:i32:$z)), (and:i32 i32:i32:$x, i32:i32:$z)) - Complexity = 12
                    // Dst: (BFI_INT_eg:i32 (XOR_INT:i32 i32:i32:$x, i32:i32:$y), i32:i32:$z, i32:i32:$y)
/*6791*/          /*Scope*/ 71|128,2/*327*/, /*->7120*/
/*6793*/            OPC_CheckChild0Same, 2,
/*6795*/            OPC_CheckChild1Same, 1,
/*6797*/            OPC_MoveParent,
/*6798*/            OPC_CheckType, MVT::i32,
/*6800*/            OPC_CheckPatternPredicate, 2, // (Subtarget.getGeneration() == AMDGPUSubtarget::EVERGREEN|| Subtarget.getGeneration() ==AMDGPUSubtarget::NORTHERN_ISLANDS)
/*6802*/            OPC_EmitInteger, MVT::i32, 0, 
/*6805*/            OPC_EmitInteger, MVT::i32, 0, 
/*6808*/            OPC_EmitInteger, MVT::i32, 0, 
/*6811*/            OPC_EmitInteger, MVT::i32, 0, 
/*6814*/            OPC_EmitInteger, MVT::i32, 1, 
/*6817*/            OPC_EmitInteger, MVT::i32, 0, 
/*6820*/            OPC_EmitInteger, MVT::i32, 0, 
/*6823*/            OPC_EmitInteger, MVT::i32, 0, 
/*6826*/            OPC_EmitInteger, MVT::i32, 0, 
/*6829*/            OPC_EmitInteger, MVT::i32, 0, 
/*6832*/            OPC_EmitInteger, MVT::i32, 0, 
/*6835*/            OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*6847*/            OPC_EmitInteger, MVT::i32, 0, 
/*6850*/            OPC_EmitInteger, MVT::i32, 0, 
/*6853*/            OPC_EmitInteger, MVT::i32, 0, 
/*6856*/            OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*6868*/            OPC_EmitInteger, MVT::i32, 1, 
/*6871*/            OPC_EmitRegister, MVT::i32, AMDGPU::PRED_SEL_OFF,
/*6874*/            OPC_EmitInteger, MVT::i32, 0, 
/*6877*/            OPC_EmitInteger, MVT::i32, 0, 
/*6880*/            OPC_Scope, 118, /*->7000*/ // 2 children in Scope
/*6882*/              OPC_EmitNode, TARGET_VAL(AMDGPU::XOR_INT), 0,
                          1/*#VTs*/, MVT::i32, 20/*#Ops*/, 5, 6, 7, 8, 9, 10, 1, 11, 12, 13, 14, 0, 15, 16, 17, 18, 19, 20, 21, 22,  // Results = #23
/*6909*/              OPC_EmitInteger, MVT::i32, 0, 
/*6912*/              OPC_EmitInteger, MVT::i32, 0, 
/*6915*/              OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*6927*/              OPC_EmitInteger, MVT::i32, 0, 
/*6930*/              OPC_EmitInteger, MVT::i32, 0, 
/*6933*/              OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*6945*/              OPC_EmitInteger, MVT::i32, 0, 
/*6948*/              OPC_EmitInteger, MVT::i32, 0, 
/*6951*/              OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*6963*/              OPC_EmitInteger, MVT::i32, 1, 
/*6966*/              OPC_EmitRegister, MVT::i32, AMDGPU::PRED_SEL_OFF,
/*6969*/              OPC_EmitInteger, MVT::i32, 0, 
/*6972*/              OPC_EmitInteger, MVT::i32, 0, 
/*6975*/              OPC_MorphNodeTo, TARGET_VAL(AMDGPU::BFI_INT_eg), 0,
                          1/*#VTs*/, MVT::i32, 18/*#Ops*/, 3, 4, 23, 24, 25, 26, 2, 27, 28, 29, 0, 30, 31, 32, 33, 34, 35, 36, 
                      // Src: (or:i32 (and:i32 i32:i32:$y, (or:i32 i32:i32:$x, i32:i32:$z)), (and:i32 i32:i32:$z, i32:i32:$x)) - Complexity = 12
                      // Dst: (BFI_INT_eg:i32 (XOR_INT:i32 i32:i32:$x, i32:i32:$y), i32:i32:$z, i32:i32:$y)
/*7000*/            /*Scope*/ 118, /*->7119*/
/*7001*/              OPC_EmitNode, TARGET_VAL(AMDGPU::XOR_INT), 0,
                          1/*#VTs*/, MVT::i32, 20/*#Ops*/, 5, 6, 7, 8, 9, 10, 2, 11, 12, 13, 14, 0, 15, 16, 17, 18, 19, 20, 21, 22,  // Results = #23
/*7028*/              OPC_EmitInteger, MVT::i32, 0, 
/*7031*/              OPC_EmitInteger, MVT::i32, 0, 
/*7034*/              OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*7046*/              OPC_EmitInteger, MVT::i32, 0, 
/*7049*/              OPC_EmitInteger, MVT::i32, 0, 
/*7052*/              OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*7064*/              OPC_EmitInteger, MVT::i32, 0, 
/*7067*/              OPC_EmitInteger, MVT::i32, 0, 
/*7070*/              OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*7082*/              OPC_EmitInteger, MVT::i32, 1, 
/*7085*/              OPC_EmitRegister, MVT::i32, AMDGPU::PRED_SEL_OFF,
/*7088*/              OPC_EmitInteger, MVT::i32, 0, 
/*7091*/              OPC_EmitInteger, MVT::i32, 0, 
/*7094*/              OPC_MorphNodeTo, TARGET_VAL(AMDGPU::BFI_INT_eg), 0,
                          1/*#VTs*/, MVT::i32, 18/*#Ops*/, 3, 4, 23, 24, 25, 26, 1, 27, 28, 29, 0, 30, 31, 32, 33, 34, 35, 36, 
                      // Src: (or:i32 (and:i32 i32:i32:$y, (or:i32 i32:i32:$z, i32:i32:$x)), (and:i32 i32:i32:$x, i32:i32:$z)) - Complexity = 12
                      // Dst: (BFI_INT_eg:i32 (XOR_INT:i32 i32:i32:$x, i32:i32:$y), i32:i32:$z, i32:i32:$y)
/*7119*/            0, /*End of Scope*/
/*7120*/          /*Scope*/ 77|128,1/*205*/, /*->7327*/
/*7122*/            OPC_CheckChild0Same, 1,
/*7124*/            OPC_CheckChild1Same, 2,
/*7126*/            OPC_MoveParent,
/*7127*/            OPC_CheckType, MVT::i32,
/*7129*/            OPC_CheckPatternPredicate, 2, // (Subtarget.getGeneration() == AMDGPUSubtarget::EVERGREEN|| Subtarget.getGeneration() ==AMDGPUSubtarget::NORTHERN_ISLANDS)
/*7131*/            OPC_EmitInteger, MVT::i32, 0, 
/*7134*/            OPC_EmitInteger, MVT::i32, 0, 
/*7137*/            OPC_EmitInteger, MVT::i32, 0, 
/*7140*/            OPC_EmitInteger, MVT::i32, 0, 
/*7143*/            OPC_EmitInteger, MVT::i32, 1, 
/*7146*/            OPC_EmitInteger, MVT::i32, 0, 
/*7149*/            OPC_EmitInteger, MVT::i32, 0, 
/*7152*/            OPC_EmitInteger, MVT::i32, 0, 
/*7155*/            OPC_EmitInteger, MVT::i32, 0, 
/*7158*/            OPC_EmitInteger, MVT::i32, 0, 
/*7161*/            OPC_EmitInteger, MVT::i32, 0, 
/*7164*/            OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*7176*/            OPC_EmitInteger, MVT::i32, 0, 
/*7179*/            OPC_EmitInteger, MVT::i32, 0, 
/*7182*/            OPC_EmitInteger, MVT::i32, 0, 
/*7185*/            OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*7197*/            OPC_EmitInteger, MVT::i32, 1, 
/*7200*/            OPC_EmitRegister, MVT::i32, AMDGPU::PRED_SEL_OFF,
/*7203*/            OPC_EmitInteger, MVT::i32, 0, 
/*7206*/            OPC_EmitInteger, MVT::i32, 0, 
/*7209*/            OPC_EmitNode, TARGET_VAL(AMDGPU::XOR_INT), 0,
                        1/*#VTs*/, MVT::i32, 20/*#Ops*/, 5, 6, 7, 8, 9, 10, 2, 11, 12, 13, 14, 0, 15, 16, 17, 18, 19, 20, 21, 22,  // Results = #23
/*7236*/            OPC_EmitInteger, MVT::i32, 0, 
/*7239*/            OPC_EmitInteger, MVT::i32, 0, 
/*7242*/            OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*7254*/            OPC_EmitInteger, MVT::i32, 0, 
/*7257*/            OPC_EmitInteger, MVT::i32, 0, 
/*7260*/            OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*7272*/            OPC_EmitInteger, MVT::i32, 0, 
/*7275*/            OPC_EmitInteger, MVT::i32, 0, 
/*7278*/            OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*7290*/            OPC_EmitInteger, MVT::i32, 1, 
/*7293*/            OPC_EmitRegister, MVT::i32, AMDGPU::PRED_SEL_OFF,
/*7296*/            OPC_EmitInteger, MVT::i32, 0, 
/*7299*/            OPC_EmitInteger, MVT::i32, 0, 
/*7302*/            OPC_MorphNodeTo, TARGET_VAL(AMDGPU::BFI_INT_eg), 0,
                        1/*#VTs*/, MVT::i32, 18/*#Ops*/, 3, 4, 23, 24, 25, 26, 1, 27, 28, 29, 0, 30, 31, 32, 33, 34, 35, 36, 
                    // Src: (or:i32 (and:i32 i32:i32:$y, (or:i32 i32:i32:$z, i32:i32:$x)), (and:i32 i32:i32:$z, i32:i32:$x)) - Complexity = 12
                    // Dst: (BFI_INT_eg:i32 (XOR_INT:i32 i32:i32:$x, i32:i32:$y), i32:i32:$z, i32:i32:$y)
/*7327*/          0, /*End of Scope*/
/*7328*/        0, /*End of Scope*/
/*7329*/      /*Scope*/ 120|128,5/*760*/, /*->8091*/
/*7331*/        OPC_MoveChild, 0,
/*7333*/        OPC_CheckOpcode, TARGET_VAL(ISD::OR),
/*7336*/        OPC_RecordChild0, // #0 = $x
/*7337*/        OPC_RecordChild1, // #1 = $z
/*7338*/        OPC_MoveParent,
/*7339*/        OPC_RecordChild1, // #2 = $y
/*7340*/        OPC_MoveParent,
/*7341*/        OPC_MoveChild, 1,
/*7343*/        OPC_CheckOpcode, TARGET_VAL(ISD::AND),
/*7346*/        OPC_Scope, 77|128,1/*205*/, /*->7554*/ // 3 children in Scope
/*7349*/          OPC_CheckChild0Same, 0,
/*7351*/          OPC_CheckChild1Same, 1,
/*7353*/          OPC_MoveParent,
/*7354*/          OPC_CheckType, MVT::i32,
/*7356*/          OPC_CheckPatternPredicate, 2, // (Subtarget.getGeneration() == AMDGPUSubtarget::EVERGREEN|| Subtarget.getGeneration() ==AMDGPUSubtarget::NORTHERN_ISLANDS)
/*7358*/          OPC_EmitInteger, MVT::i32, 0, 
/*7361*/          OPC_EmitInteger, MVT::i32, 0, 
/*7364*/          OPC_EmitInteger, MVT::i32, 0, 
/*7367*/          OPC_EmitInteger, MVT::i32, 0, 
/*7370*/          OPC_EmitInteger, MVT::i32, 1, 
/*7373*/          OPC_EmitInteger, MVT::i32, 0, 
/*7376*/          OPC_EmitInteger, MVT::i32, 0, 
/*7379*/          OPC_EmitInteger, MVT::i32, 0, 
/*7382*/          OPC_EmitInteger, MVT::i32, 0, 
/*7385*/          OPC_EmitInteger, MVT::i32, 0, 
/*7388*/          OPC_EmitInteger, MVT::i32, 0, 
/*7391*/          OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*7403*/          OPC_EmitInteger, MVT::i32, 0, 
/*7406*/          OPC_EmitInteger, MVT::i32, 0, 
/*7409*/          OPC_EmitInteger, MVT::i32, 0, 
/*7412*/          OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*7424*/          OPC_EmitInteger, MVT::i32, 1, 
/*7427*/          OPC_EmitRegister, MVT::i32, AMDGPU::PRED_SEL_OFF,
/*7430*/          OPC_EmitInteger, MVT::i32, 0, 
/*7433*/          OPC_EmitInteger, MVT::i32, 0, 
/*7436*/          OPC_EmitNode, TARGET_VAL(AMDGPU::XOR_INT), 0,
                      1/*#VTs*/, MVT::i32, 20/*#Ops*/, 5, 6, 7, 8, 9, 10, 0, 11, 12, 13, 14, 2, 15, 16, 17, 18, 19, 20, 21, 22,  // Results = #23
/*7463*/          OPC_EmitInteger, MVT::i32, 0, 
/*7466*/          OPC_EmitInteger, MVT::i32, 0, 
/*7469*/          OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*7481*/          OPC_EmitInteger, MVT::i32, 0, 
/*7484*/          OPC_EmitInteger, MVT::i32, 0, 
/*7487*/          OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*7499*/          OPC_EmitInteger, MVT::i32, 0, 
/*7502*/          OPC_EmitInteger, MVT::i32, 0, 
/*7505*/          OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*7517*/          OPC_EmitInteger, MVT::i32, 1, 
/*7520*/          OPC_EmitRegister, MVT::i32, AMDGPU::PRED_SEL_OFF,
/*7523*/          OPC_EmitInteger, MVT::i32, 0, 
/*7526*/          OPC_EmitInteger, MVT::i32, 0, 
/*7529*/          OPC_MorphNodeTo, TARGET_VAL(AMDGPU::BFI_INT_eg), 0,
                      1/*#VTs*/, MVT::i32, 18/*#Ops*/, 3, 4, 23, 24, 25, 26, 1, 27, 28, 29, 2, 30, 31, 32, 33, 34, 35, 36, 
                  // Src: (or:i32 (and:i32 (or:i32 i32:i32:$x, i32:i32:$z), i32:i32:$y), (and:i32 i32:i32:$x, i32:i32:$z)) - Complexity = 12
                  // Dst: (BFI_INT_eg:i32 (XOR_INT:i32 i32:i32:$x, i32:i32:$y), i32:i32:$z, i32:i32:$y)
/*7554*/        /*Scope*/ 71|128,2/*327*/, /*->7883*/
/*7556*/          OPC_CheckChild0Same, 1,
/*7558*/          OPC_CheckChild1Same, 0,
/*7560*/          OPC_MoveParent,
/*7561*/          OPC_CheckType, MVT::i32,
/*7563*/          OPC_CheckPatternPredicate, 2, // (Subtarget.getGeneration() == AMDGPUSubtarget::EVERGREEN|| Subtarget.getGeneration() ==AMDGPUSubtarget::NORTHERN_ISLANDS)
/*7565*/          OPC_EmitInteger, MVT::i32, 0, 
/*7568*/          OPC_EmitInteger, MVT::i32, 0, 
/*7571*/          OPC_EmitInteger, MVT::i32, 0, 
/*7574*/          OPC_EmitInteger, MVT::i32, 0, 
/*7577*/          OPC_EmitInteger, MVT::i32, 1, 
/*7580*/          OPC_EmitInteger, MVT::i32, 0, 
/*7583*/          OPC_EmitInteger, MVT::i32, 0, 
/*7586*/          OPC_EmitInteger, MVT::i32, 0, 
/*7589*/          OPC_EmitInteger, MVT::i32, 0, 
/*7592*/          OPC_EmitInteger, MVT::i32, 0, 
/*7595*/          OPC_EmitInteger, MVT::i32, 0, 
/*7598*/          OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*7610*/          OPC_EmitInteger, MVT::i32, 0, 
/*7613*/          OPC_EmitInteger, MVT::i32, 0, 
/*7616*/          OPC_EmitInteger, MVT::i32, 0, 
/*7619*/          OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*7631*/          OPC_EmitInteger, MVT::i32, 1, 
/*7634*/          OPC_EmitRegister, MVT::i32, AMDGPU::PRED_SEL_OFF,
/*7637*/          OPC_EmitInteger, MVT::i32, 0, 
/*7640*/          OPC_EmitInteger, MVT::i32, 0, 
/*7643*/          OPC_Scope, 118, /*->7763*/ // 2 children in Scope
/*7645*/            OPC_EmitNode, TARGET_VAL(AMDGPU::XOR_INT), 0,
                        1/*#VTs*/, MVT::i32, 20/*#Ops*/, 5, 6, 7, 8, 9, 10, 0, 11, 12, 13, 14, 2, 15, 16, 17, 18, 19, 20, 21, 22,  // Results = #23
/*7672*/            OPC_EmitInteger, MVT::i32, 0, 
/*7675*/            OPC_EmitInteger, MVT::i32, 0, 
/*7678*/            OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*7690*/            OPC_EmitInteger, MVT::i32, 0, 
/*7693*/            OPC_EmitInteger, MVT::i32, 0, 
/*7696*/            OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*7708*/            OPC_EmitInteger, MVT::i32, 0, 
/*7711*/            OPC_EmitInteger, MVT::i32, 0, 
/*7714*/            OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*7726*/            OPC_EmitInteger, MVT::i32, 1, 
/*7729*/            OPC_EmitRegister, MVT::i32, AMDGPU::PRED_SEL_OFF,
/*7732*/            OPC_EmitInteger, MVT::i32, 0, 
/*7735*/            OPC_EmitInteger, MVT::i32, 0, 
/*7738*/            OPC_MorphNodeTo, TARGET_VAL(AMDGPU::BFI_INT_eg), 0,
                        1/*#VTs*/, MVT::i32, 18/*#Ops*/, 3, 4, 23, 24, 25, 26, 1, 27, 28, 29, 2, 30, 31, 32, 33, 34, 35, 36, 
                    // Src: (or:i32 (and:i32 (or:i32 i32:i32:$x, i32:i32:$z), i32:i32:$y), (and:i32 i32:i32:$z, i32:i32:$x)) - Complexity = 12
                    // Dst: (BFI_INT_eg:i32 (XOR_INT:i32 i32:i32:$x, i32:i32:$y), i32:i32:$z, i32:i32:$y)
/*7763*/          /*Scope*/ 118, /*->7882*/
/*7764*/            OPC_EmitNode, TARGET_VAL(AMDGPU::XOR_INT), 0,
                        1/*#VTs*/, MVT::i32, 20/*#Ops*/, 5, 6, 7, 8, 9, 10, 1, 11, 12, 13, 14, 2, 15, 16, 17, 18, 19, 20, 21, 22,  // Results = #23
/*7791*/            OPC_EmitInteger, MVT::i32, 0, 
/*7794*/            OPC_EmitInteger, MVT::i32, 0, 
/*7797*/            OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*7809*/            OPC_EmitInteger, MVT::i32, 0, 
/*7812*/            OPC_EmitInteger, MVT::i32, 0, 
/*7815*/            OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*7827*/            OPC_EmitInteger, MVT::i32, 0, 
/*7830*/            OPC_EmitInteger, MVT::i32, 0, 
/*7833*/            OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*7845*/            OPC_EmitInteger, MVT::i32, 1, 
/*7848*/            OPC_EmitRegister, MVT::i32, AMDGPU::PRED_SEL_OFF,
/*7851*/            OPC_EmitInteger, MVT::i32, 0, 
/*7854*/            OPC_EmitInteger, MVT::i32, 0, 
/*7857*/            OPC_MorphNodeTo, TARGET_VAL(AMDGPU::BFI_INT_eg), 0,
                        1/*#VTs*/, MVT::i32, 18/*#Ops*/, 3, 4, 23, 24, 25, 26, 0, 27, 28, 29, 2, 30, 31, 32, 33, 34, 35, 36, 
                    // Src: (or:i32 (and:i32 (or:i32 i32:i32:$z, i32:i32:$x), i32:i32:$y), (and:i32 i32:i32:$x, i32:i32:$z)) - Complexity = 12
                    // Dst: (BFI_INT_eg:i32 (XOR_INT:i32 i32:i32:$x, i32:i32:$y), i32:i32:$z, i32:i32:$y)
/*7882*/          0, /*End of Scope*/
/*7883*/        /*Scope*/ 77|128,1/*205*/, /*->8090*/
/*7885*/          OPC_CheckChild0Same, 0,
/*7887*/          OPC_CheckChild1Same, 1,
/*7889*/          OPC_MoveParent,
/*7890*/          OPC_CheckType, MVT::i32,
/*7892*/          OPC_CheckPatternPredicate, 2, // (Subtarget.getGeneration() == AMDGPUSubtarget::EVERGREEN|| Subtarget.getGeneration() ==AMDGPUSubtarget::NORTHERN_ISLANDS)
/*7894*/          OPC_EmitInteger, MVT::i32, 0, 
/*7897*/          OPC_EmitInteger, MVT::i32, 0, 
/*7900*/          OPC_EmitInteger, MVT::i32, 0, 
/*7903*/          OPC_EmitInteger, MVT::i32, 0, 
/*7906*/          OPC_EmitInteger, MVT::i32, 1, 
/*7909*/          OPC_EmitInteger, MVT::i32, 0, 
/*7912*/          OPC_EmitInteger, MVT::i32, 0, 
/*7915*/          OPC_EmitInteger, MVT::i32, 0, 
/*7918*/          OPC_EmitInteger, MVT::i32, 0, 
/*7921*/          OPC_EmitInteger, MVT::i32, 0, 
/*7924*/          OPC_EmitInteger, MVT::i32, 0, 
/*7927*/          OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*7939*/          OPC_EmitInteger, MVT::i32, 0, 
/*7942*/          OPC_EmitInteger, MVT::i32, 0, 
/*7945*/          OPC_EmitInteger, MVT::i32, 0, 
/*7948*/          OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*7960*/          OPC_EmitInteger, MVT::i32, 1, 
/*7963*/          OPC_EmitRegister, MVT::i32, AMDGPU::PRED_SEL_OFF,
/*7966*/          OPC_EmitInteger, MVT::i32, 0, 
/*7969*/          OPC_EmitInteger, MVT::i32, 0, 
/*7972*/          OPC_EmitNode, TARGET_VAL(AMDGPU::XOR_INT), 0,
                      1/*#VTs*/, MVT::i32, 20/*#Ops*/, 5, 6, 7, 8, 9, 10, 1, 11, 12, 13, 14, 2, 15, 16, 17, 18, 19, 20, 21, 22,  // Results = #23
/*7999*/          OPC_EmitInteger, MVT::i32, 0, 
/*8002*/          OPC_EmitInteger, MVT::i32, 0, 
/*8005*/          OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*8017*/          OPC_EmitInteger, MVT::i32, 0, 
/*8020*/          OPC_EmitInteger, MVT::i32, 0, 
/*8023*/          OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*8035*/          OPC_EmitInteger, MVT::i32, 0, 
/*8038*/          OPC_EmitInteger, MVT::i32, 0, 
/*8041*/          OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*8053*/          OPC_EmitInteger, MVT::i32, 1, 
/*8056*/          OPC_EmitRegister, MVT::i32, AMDGPU::PRED_SEL_OFF,
/*8059*/          OPC_EmitInteger, MVT::i32, 0, 
/*8062*/          OPC_EmitInteger, MVT::i32, 0, 
/*8065*/          OPC_MorphNodeTo, TARGET_VAL(AMDGPU::BFI_INT_eg), 0,
                      1/*#VTs*/, MVT::i32, 18/*#Ops*/, 3, 4, 23, 24, 25, 26, 0, 27, 28, 29, 2, 30, 31, 32, 33, 34, 35, 36, 
                  // Src: (or:i32 (and:i32 (or:i32 i32:i32:$z, i32:i32:$x), i32:i32:$y), (and:i32 i32:i32:$z, i32:i32:$x)) - Complexity = 12
                  // Dst: (BFI_INT_eg:i32 (XOR_INT:i32 i32:i32:$x, i32:i32:$y), i32:i32:$z, i32:i32:$y)
/*8090*/        0, /*End of Scope*/
/*8091*/      0, /*End of Scope*/
/*8092*/    /*Scope*/ 110|128,1/*238*/, /*->8332*/
/*8094*/      OPC_RecordChild0, // #0 = $src0
/*8095*/      OPC_RecordChild1, // #1 = $src1
/*8096*/      OPC_SwitchType /*3 cases */, 116,  MVT::i32,// ->8215
/*8099*/        OPC_Scope, 101, /*->8202*/ // 2 children in Scope
/*8101*/          OPC_CheckPatternPredicate, 3, // (Subtarget.getGeneration() <= AMDGPUSubtarget::NORTHERN_ISLANDS)
/*8103*/          OPC_EmitInteger, MVT::i32, 0, 
/*8106*/          OPC_EmitInteger, MVT::i32, 0, 
/*8109*/          OPC_EmitInteger, MVT::i32, 1, 
/*8112*/          OPC_EmitInteger, MVT::i32, 0, 
/*8115*/          OPC_EmitInteger, MVT::i32, 0, 
/*8118*/          OPC_EmitInteger, MVT::i32, 0, 
/*8121*/          OPC_EmitInteger, MVT::i32, 0, 
/*8124*/          OPC_EmitInteger, MVT::i32, 0, 
/*8127*/          OPC_EmitInteger, MVT::i32, 0, 
/*8130*/          OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*8142*/          OPC_EmitInteger, MVT::i32, 0, 
/*8145*/          OPC_EmitInteger, MVT::i32, 0, 
/*8148*/          OPC_EmitInteger, MVT::i32, 0, 
/*8151*/          OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*8163*/          OPC_EmitInteger, MVT::i32, 1, 
/*8166*/          OPC_EmitRegister, MVT::i32, AMDGPU::PRED_SEL_OFF,
/*8169*/          OPC_EmitInteger, MVT::i32, 0, 
/*8172*/          OPC_EmitInteger, MVT::i32, 0, 
/*8175*/          OPC_MorphNodeTo, TARGET_VAL(AMDGPU::OR_INT), 0,
                      1/*#VTs*/, MVT::i32, 20/*#Ops*/, 2, 3, 4, 5, 6, 7, 0, 8, 9, 10, 11, 1, 12, 13, 14, 15, 16, 17, 18, 19, 
                  // Src: (or:i32 R600_Reg32:i32:$src0, R600_Reg32:i32:$src1) - Complexity = 3
                  // Dst: (OR_INT:i32 R600_Reg32:i32:$src0, R600_Reg32:i32:$src1)
/*8202*/        /*Scope*/ 11, /*->8214*/
/*8203*/          OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*8205*/          OPC_MorphNodeTo, TARGET_VAL(AMDGPU::V_OR_B32_e32), 0,
                      1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1, 
                  // Src: (or:i32 i32:i32:$src0, i32:i32:$src1) - Complexity = 3
                  // Dst: (V_OR_B32_e32:i32 i32:i32:$src0, i32:i32:$src1)
/*8214*/        0, /*End of Scope*/
/*8215*/      /*SwitchType*/ 11,  MVT::i1,// ->8228
/*8217*/        OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*8219*/        OPC_MorphNodeTo, TARGET_VAL(AMDGPU::S_OR_B64), 0,
                    1/*#VTs*/, MVT::i1, 2/*#Ops*/, 0, 1, 
                // Src: (or:i1 i1:i1:$src0, i1:i1:$src1) - Complexity = 3
                // Dst: (S_OR_B64:i1 ?:i1:$src0, ?:i1:$src1)
/*8228*/      /*SwitchType*/ 101,  MVT::i64,// ->8331
/*8230*/        OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*8232*/        OPC_EmitNode, TARGET_VAL(TargetOpcode::IMPLICIT_DEF), 0,
                    1/*#VTs*/, MVT::i64, 0/*#Ops*/,  // Results = #2
/*8239*/        OPC_EmitInteger, MVT::i32, AMDGPU::sub0,
/*8242*/        OPC_EmitNode, TARGET_VAL(TargetOpcode::EXTRACT_SUBREG), 0,
                    1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 3,  // Results = #4
/*8251*/        OPC_EmitInteger, MVT::i32, AMDGPU::sub0,
/*8254*/        OPC_EmitNode, TARGET_VAL(TargetOpcode::EXTRACT_SUBREG), 0,
                    1/*#VTs*/, MVT::i32, 2/*#Ops*/, 1, 5,  // Results = #6
/*8263*/        OPC_EmitNode, TARGET_VAL(AMDGPU::V_OR_B32_e32), 0,
                    1/*#VTs*/, MVT::i32, 2/*#Ops*/, 4, 6,  // Results = #7
/*8272*/        OPC_EmitInteger, MVT::i32, AMDGPU::sub0,
/*8275*/        OPC_EmitNode, TARGET_VAL(TargetOpcode::INSERT_SUBREG), 0,
                    1/*#VTs*/, MVT::i64, 3/*#Ops*/, 2, 7, 8,  // Results = #9
/*8285*/        OPC_EmitInteger, MVT::i32, AMDGPU::sub1,
/*8288*/        OPC_EmitNode, TARGET_VAL(TargetOpcode::EXTRACT_SUBREG), 0,
                    1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 10,  // Results = #11
/*8297*/        OPC_EmitInteger, MVT::i32, AMDGPU::sub1,
/*8300*/        OPC_EmitNode, TARGET_VAL(TargetOpcode::EXTRACT_SUBREG), 0,
                    1/*#VTs*/, MVT::i32, 2/*#Ops*/, 1, 12,  // Results = #13
/*8309*/        OPC_EmitNode, TARGET_VAL(AMDGPU::V_OR_B32_e32), 0,
                    1/*#VTs*/, MVT::i32, 2/*#Ops*/, 11, 13,  // Results = #14
/*8318*/        OPC_EmitInteger, MVT::i32, AMDGPU::sub1,
/*8321*/        OPC_MorphNodeTo, TARGET_VAL(TargetOpcode::INSERT_SUBREG), 0,
                    1/*#VTs*/, MVT::i64, 3/*#Ops*/, 9, 14, 15, 
                // Src: (or:i64 i64:i64:$a, i64:i64:$b) - Complexity = 3
                // Dst: (INSERT_SUBREG:i64 (INSERT_SUBREG:i64 (IMPLICIT_DEF:i64), (V_OR_B32_e32:i32 (EXTRACT_SUBREG:i32 ?:i64:$a, sub0:i32), (EXTRACT_SUBREG:i32 ?:i64:$b, sub0:i32)), sub0:i32), (V_OR_B32_e32:i32 (EXTRACT_SUBREG:i32 ?:i64:$a, sub1:i32), (EXTRACT_SUBREG:i32 ?:i64:$b, sub1:i32)), sub1:i32)
/*8331*/      0, // EndSwitchType
/*8332*/    0, /*End of Scope*/
/*8333*/  /*SwitchOpcode*/ 85|128,4/*597*/,  TARGET_VAL(ISD::MUL),// ->8934
/*8337*/    OPC_RecordChild0, // #0 = $src0
/*8338*/    OPC_RecordChild1, // #1 = $src1
/*8339*/    OPC_CheckType, MVT::i32,
/*8341*/    OPC_Scope, 107, /*->8450*/ // 7 children in Scope
/*8343*/      OPC_CheckPatternPredicate, 2, // (Subtarget.getGeneration() == AMDGPUSubtarget::EVERGREEN|| Subtarget.getGeneration() ==AMDGPUSubtarget::NORTHERN_ISLANDS)
/*8345*/      OPC_CheckComplexPat, /*CP*/0, /*#*/0, // SelectU24:$src0 #2
/*8348*/      OPC_CheckComplexPat, /*CP*/0, /*#*/1, // SelectU24:$src1 #3
/*8351*/      OPC_EmitInteger, MVT::i32, 0, 
/*8354*/      OPC_EmitInteger, MVT::i32, 0, 
/*8357*/      OPC_EmitInteger, MVT::i32, 1, 
/*8360*/      OPC_EmitInteger, MVT::i32, 0, 
/*8363*/      OPC_EmitInteger, MVT::i32, 0, 
/*8366*/      OPC_EmitInteger, MVT::i32, 0, 
/*8369*/      OPC_EmitInteger, MVT::i32, 0, 
/*8372*/      OPC_EmitInteger, MVT::i32, 0, 
/*8375*/      OPC_EmitInteger, MVT::i32, 0, 
/*8378*/      OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*8390*/      OPC_EmitInteger, MVT::i32, 0, 
/*8393*/      OPC_EmitInteger, MVT::i32, 0, 
/*8396*/      OPC_EmitInteger, MVT::i32, 0, 
/*8399*/      OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*8411*/      OPC_EmitInteger, MVT::i32, 1, 
/*8414*/      OPC_EmitRegister, MVT::i32, AMDGPU::PRED_SEL_OFF,
/*8417*/      OPC_EmitInteger, MVT::i32, 0, 
/*8420*/      OPC_EmitInteger, MVT::i32, 0, 
/*8423*/      OPC_MorphNodeTo, TARGET_VAL(AMDGPU::MUL_UINT24_eg), 0,
                  1/*#VTs*/, MVT::i32, 20/*#Ops*/, 4, 5, 6, 7, 8, 9, 2, 10, 11, 12, 13, 3, 14, 15, 16, 17, 18, 19, 20, 21, 
              // Src: (mul:i32 U24:i32:$src0, U24:i32:$src1) - Complexity = 15
              // Dst: (MUL_UINT24_eg:i32 U24:i32:$src0, U24:i32:$src1)
/*8450*/    /*Scope*/ 107, /*->8558*/
/*8451*/      OPC_CheckPatternPredicate, 4, // (Subtarget.hasCaymanISA())
/*8453*/      OPC_CheckComplexPat, /*CP*/1, /*#*/0, // SelectI24:$src0 #2
/*8456*/      OPC_CheckComplexPat, /*CP*/1, /*#*/1, // SelectI24:$src1 #3
/*8459*/      OPC_EmitInteger, MVT::i32, 0, 
/*8462*/      OPC_EmitInteger, MVT::i32, 0, 
/*8465*/      OPC_EmitInteger, MVT::i32, 1, 
/*8468*/      OPC_EmitInteger, MVT::i32, 0, 
/*8471*/      OPC_EmitInteger, MVT::i32, 0, 
/*8474*/      OPC_EmitInteger, MVT::i32, 0, 
/*8477*/      OPC_EmitInteger, MVT::i32, 0, 
/*8480*/      OPC_EmitInteger, MVT::i32, 0, 
/*8483*/      OPC_EmitInteger, MVT::i32, 0, 
/*8486*/      OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*8498*/      OPC_EmitInteger, MVT::i32, 0, 
/*8501*/      OPC_EmitInteger, MVT::i32, 0, 
/*8504*/      OPC_EmitInteger, MVT::i32, 0, 
/*8507*/      OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*8519*/      OPC_EmitInteger, MVT::i32, 1, 
/*8522*/      OPC_EmitRegister, MVT::i32, AMDGPU::PRED_SEL_OFF,
/*8525*/      OPC_EmitInteger, MVT::i32, 0, 
/*8528*/      OPC_EmitInteger, MVT::i32, 0, 
/*8531*/      OPC_MorphNodeTo, TARGET_VAL(AMDGPU::MUL_INT24_cm), 0,
                  1/*#VTs*/, MVT::i32, 20/*#Ops*/, 4, 5, 6, 7, 8, 9, 2, 10, 11, 12, 13, 3, 14, 15, 16, 17, 18, 19, 20, 21, 
              // Src: (mul:i32 I24:i32:$src0, I24:i32:$src1) - Complexity = 15
              // Dst: (MUL_INT24_cm:i32 I24:i32:$src0, I24:i32:$src1)
/*8558*/    /*Scope*/ 36, /*->8595*/
/*8559*/      OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*8561*/      OPC_Scope, 15, /*->8578*/ // 2 children in Scope
/*8563*/        OPC_CheckComplexPat, /*CP*/1, /*#*/0, // SelectI24:$src0 #2
/*8566*/        OPC_CheckComplexPat, /*CP*/1, /*#*/1, // SelectI24:$src1 #3
/*8569*/        OPC_MorphNodeTo, TARGET_VAL(AMDGPU::V_MUL_I32_I24_e32), 0,
                    1/*#VTs*/, MVT::i32, 2/*#Ops*/, 2, 3, 
                // Src: (mul:i32 I24:i32:$src0, I24:i32:$src1) - Complexity = 15
                // Dst: (V_MUL_I32_I24_e32:i32 I24:i32:$src0, I24:i32:$src1)
/*8578*/      /*Scope*/ 15, /*->8594*/
/*8579*/        OPC_CheckComplexPat, /*CP*/0, /*#*/0, // SelectU24:$src0 #2
/*8582*/        OPC_CheckComplexPat, /*CP*/0, /*#*/1, // SelectU24:$src1 #3
/*8585*/        OPC_MorphNodeTo, TARGET_VAL(AMDGPU::V_MUL_U32_U24_e32), 0,
                    1/*#VTs*/, MVT::i32, 2/*#Ops*/, 2, 3, 
                // Src: (mul:i32 U24:i32:$src0, U24:i32:$src1) - Complexity = 15
                // Dst: (V_MUL_U32_U24_e32:i32 U24:i32:$src0, U24:i32:$src1)
/*8594*/      0, /*End of Scope*/
/*8595*/    /*Scope*/ 101, /*->8697*/
/*8596*/      OPC_CheckPatternPredicate, 1, // (Subtarget.getGeneration() <= AMDGPUSubtarget::R700)
/*8598*/      OPC_EmitInteger, MVT::i32, 0, 
/*8601*/      OPC_EmitInteger, MVT::i32, 0, 
/*8604*/      OPC_EmitInteger, MVT::i32, 1, 
/*8607*/      OPC_EmitInteger, MVT::i32, 0, 
/*8610*/      OPC_EmitInteger, MVT::i32, 0, 
/*8613*/      OPC_EmitInteger, MVT::i32, 0, 
/*8616*/      OPC_EmitInteger, MVT::i32, 0, 
/*8619*/      OPC_EmitInteger, MVT::i32, 0, 
/*8622*/      OPC_EmitInteger, MVT::i32, 0, 
/*8625*/      OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*8637*/      OPC_EmitInteger, MVT::i32, 0, 
/*8640*/      OPC_EmitInteger, MVT::i32, 0, 
/*8643*/      OPC_EmitInteger, MVT::i32, 0, 
/*8646*/      OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*8658*/      OPC_EmitInteger, MVT::i32, 1, 
/*8661*/      OPC_EmitRegister, MVT::i32, AMDGPU::PRED_SEL_OFF,
/*8664*/      OPC_EmitInteger, MVT::i32, 0, 
/*8667*/      OPC_EmitInteger, MVT::i32, 0, 
/*8670*/      OPC_MorphNodeTo, TARGET_VAL(AMDGPU::MULLO_INT_r600), 0,
                  1/*#VTs*/, MVT::i32, 20/*#Ops*/, 2, 3, 4, 5, 6, 7, 0, 8, 9, 10, 11, 1, 12, 13, 14, 15, 16, 17, 18, 19, 
              // Src: (mul:i32 R600_Reg32:i32:$src0, R600_Reg32:i32:$src1) - Complexity = 3
              // Dst: (MULLO_INT_r600:i32 R600_Reg32:i32:$src0, R600_Reg32:i32:$src1)
/*8697*/    /*Scope*/ 101, /*->8799*/
/*8698*/      OPC_CheckPatternPredicate, 5, // (Subtarget.getGeneration() >= AMDGPUSubtarget::EVERGREEN && Subtarget.getGeneration() < AMDGPUSubtarget::SOUTHERN_ISLANDS && !Subtarget.hasCaymanISA())
/*8700*/      OPC_EmitInteger, MVT::i32, 0, 
/*8703*/      OPC_EmitInteger, MVT::i32, 0, 
/*8706*/      OPC_EmitInteger, MVT::i32, 1, 
/*8709*/      OPC_EmitInteger, MVT::i32, 0, 
/*8712*/      OPC_EmitInteger, MVT::i32, 0, 
/*8715*/      OPC_EmitInteger, MVT::i32, 0, 
/*8718*/      OPC_EmitInteger, MVT::i32, 0, 
/*8721*/      OPC_EmitInteger, MVT::i32, 0, 
/*8724*/      OPC_EmitInteger, MVT::i32, 0, 
/*8727*/      OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*8739*/      OPC_EmitInteger, MVT::i32, 0, 
/*8742*/      OPC_EmitInteger, MVT::i32, 0, 
/*8745*/      OPC_EmitInteger, MVT::i32, 0, 
/*8748*/      OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*8760*/      OPC_EmitInteger, MVT::i32, 1, 
/*8763*/      OPC_EmitRegister, MVT::i32, AMDGPU::PRED_SEL_OFF,
/*8766*/      OPC_EmitInteger, MVT::i32, 0, 
/*8769*/      OPC_EmitInteger, MVT::i32, 0, 
/*8772*/      OPC_MorphNodeTo, TARGET_VAL(AMDGPU::MULLO_INT_eg), 0,
                  1/*#VTs*/, MVT::i32, 20/*#Ops*/, 2, 3, 4, 5, 6, 7, 0, 8, 9, 10, 11, 1, 12, 13, 14, 15, 16, 17, 18, 19, 
              // Src: (mul:i32 R600_Reg32:i32:$src0, R600_Reg32:i32:$src1) - Complexity = 3
              // Dst: (MULLO_INT_eg:i32 R600_Reg32:i32:$src0, R600_Reg32:i32:$src1)
/*8799*/    /*Scope*/ 101, /*->8901*/
/*8800*/      OPC_CheckPatternPredicate, 4, // (Subtarget.hasCaymanISA())
/*8802*/      OPC_EmitInteger, MVT::i32, 0, 
/*8805*/      OPC_EmitInteger, MVT::i32, 0, 
/*8808*/      OPC_EmitInteger, MVT::i32, 1, 
/*8811*/      OPC_EmitInteger, MVT::i32, 0, 
/*8814*/      OPC_EmitInteger, MVT::i32, 0, 
/*8817*/      OPC_EmitInteger, MVT::i32, 0, 
/*8820*/      OPC_EmitInteger, MVT::i32, 0, 
/*8823*/      OPC_EmitInteger, MVT::i32, 0, 
/*8826*/      OPC_EmitInteger, MVT::i32, 0, 
/*8829*/      OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*8841*/      OPC_EmitInteger, MVT::i32, 0, 
/*8844*/      OPC_EmitInteger, MVT::i32, 0, 
/*8847*/      OPC_EmitInteger, MVT::i32, 0, 
/*8850*/      OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*8862*/      OPC_EmitInteger, MVT::i32, 1, 
/*8865*/      OPC_EmitRegister, MVT::i32, AMDGPU::PRED_SEL_OFF,
/*8868*/      OPC_EmitInteger, MVT::i32, 0, 
/*8871*/      OPC_EmitInteger, MVT::i32, 0, 
/*8874*/      OPC_MorphNodeTo, TARGET_VAL(AMDGPU::MULLO_INT_cm), 0,
                  1/*#VTs*/, MVT::i32, 20/*#Ops*/, 2, 3, 4, 5, 6, 7, 0, 8, 9, 10, 11, 1, 12, 13, 14, 15, 16, 17, 18, 19, 
              // Src: (mul:i32 R600_Reg32:i32:$src0, R600_Reg32:i32:$src1) - Complexity = 3
              // Dst: (MULLO_INT_cm:i32 R600_Reg32:i32:$src0, R600_Reg32:i32:$src1)
/*8901*/    /*Scope*/ 31, /*->8933*/
/*8902*/      OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*8904*/      OPC_EmitInteger, MVT::i32, 0, 
/*8907*/      OPC_EmitInteger, MVT::i32, 0, 
/*8910*/      OPC_EmitInteger, MVT::i32, 0, 
/*8913*/      OPC_EmitInteger, MVT::i32, 0, 
/*8916*/      OPC_EmitInteger, MVT::i32, 0, 
/*8919*/      OPC_MorphNodeTo, TARGET_VAL(AMDGPU::V_MUL_LO_I32), 0,
                  1/*#VTs*/, MVT::i32, 7/*#Ops*/, 0, 1, 2, 3, 4, 5, 6, 
              // Src: (mul:i32 i32:i32:$src0, i32:i32:$src1) - Complexity = 3
              // Dst: (V_MUL_LO_I32:i32 ?:i32:$src0, ?:i32:$src1, 0:i32)
/*8933*/    0, /*End of Scope*/
/*8934*/  /*SwitchOpcode*/ 29,  TARGET_VAL(AMDGPUISD::REGISTER_LOAD),// ->8966
/*8937*/    OPC_RecordNode,   // #0 = 'AMDGPUregister_load' chained node
/*8938*/    OPC_RecordChild1, // #1 = $addr
/*8939*/    OPC_RecordChild2, // #2 = $chan
/*8940*/    OPC_MoveChild, 2,
/*8942*/    OPC_CheckOpcode, TARGET_VAL(ISD::TargetConstant),
/*8945*/    OPC_CheckType, MVT::i32,
/*8947*/    OPC_MoveParent,
/*8948*/    OPC_CheckType, MVT::i32,
/*8950*/    OPC_CheckPatternPredicate, 3, // (Subtarget.getGeneration() <= AMDGPUSubtarget::NORTHERN_ISLANDS)
/*8952*/    OPC_CheckComplexPat, /*CP*/2, /*#*/1, // SelectADDRIndirect:$addr #3 #4
/*8955*/    OPC_EmitMergeInputChains1_0,
/*8956*/    OPC_MorphNodeTo, TARGET_VAL(AMDGPU::R600_RegisterLoad), 0|OPFL_Chain,
                1/*#VTs*/, MVT::i32, 3/*#Ops*/, 3, 4, 2, 
            // Src: (AMDGPUregister_load:i32 ADDRIndirect:iPTR:$addr, (timm:i32):$chan) - Complexity = 15
            // Dst: (R600_RegisterLoad:i32 ADDRIndirect:iPTR:$addr, (timm:i32):$chan)
/*8966*/  /*SwitchOpcode*/ 30,  TARGET_VAL(AMDGPUISD::REGISTER_STORE),// ->8999
/*8969*/    OPC_RecordNode,   // #0 = 'AMDGPUregister_store' chained node
/*8970*/    OPC_RecordChild1, // #1 = $val
/*8971*/    OPC_CheckChild1Type, MVT::i32,
/*8973*/    OPC_RecordChild2, // #2 = $addr
/*8974*/    OPC_RecordChild3, // #3 = $chan
/*8975*/    OPC_MoveChild, 3,
/*8977*/    OPC_CheckOpcode, TARGET_VAL(ISD::TargetConstant),
/*8980*/    OPC_CheckType, MVT::i32,
/*8982*/    OPC_MoveParent,
/*8983*/    OPC_CheckPatternPredicate, 3, // (Subtarget.getGeneration() <= AMDGPUSubtarget::NORTHERN_ISLANDS)
/*8985*/    OPC_CheckComplexPat, /*CP*/2, /*#*/2, // SelectADDRIndirect:$addr #4 #5
/*8988*/    OPC_EmitMergeInputChains1_0,
/*8989*/    OPC_MorphNodeTo, TARGET_VAL(AMDGPU::R600_RegisterStore), 0|OPFL_Chain,
                0/*#VTs*/, 4/*#Ops*/, 1, 4, 5, 3, 
            // Src: (AMDGPUregister_store i32:i32:$val, ADDRIndirect:iPTR:$addr, (timm:i32):$chan) - Complexity = 15
            // Dst: (R600_RegisterStore i32:i32:$val, ADDRIndirect:iPTR:$addr, (timm:i32):$chan)
/*8999*/  /*SwitchOpcode*/ 26|128,2/*282*/,  TARGET_VAL(ISD::AND),// ->9285
/*9003*/    OPC_Scope, 0|128,1/*128*/, /*->9134*/ // 2 children in Scope
/*9006*/      OPC_MoveChild, 0,
/*9008*/      OPC_CheckOpcode, TARGET_VAL(ISD::SRL),
/*9011*/      OPC_RecordChild0, // #0 = $x
/*9012*/      OPC_RecordChild1, // #1 = $y
/*9013*/      OPC_MoveChild, 1,
/*9015*/      OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*9018*/      OPC_CheckPredicate, 0, // Predicate_legalshift32
/*9020*/      OPC_CheckType, MVT::i32,
/*9022*/      OPC_MoveParent,
/*9023*/      OPC_MoveParent,
/*9024*/      OPC_RecordChild1, // #2 = $z
/*9025*/      OPC_MoveChild, 1,
/*9027*/      OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*9030*/      OPC_CheckPredicate, 1, // Predicate_bfemask
/*9032*/      OPC_MoveParent,
/*9033*/      OPC_CheckType, MVT::i32,
/*9035*/      OPC_CheckPatternPredicate, 2, // (Subtarget.getGeneration() == AMDGPUSubtarget::EVERGREEN|| Subtarget.getGeneration() ==AMDGPUSubtarget::NORTHERN_ISLANDS)
/*9037*/      OPC_EmitInteger, MVT::i32, 0, 
/*9040*/      OPC_EmitInteger, MVT::i32, 0, 
/*9043*/      OPC_EmitInteger, MVT::i32, 0, 
/*9046*/      OPC_EmitInteger, MVT::i32, 0, 
/*9049*/      OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*9061*/      OPC_EmitInteger, MVT::i32, 0, 
/*9064*/      OPC_EmitInteger, MVT::i32, 0, 
/*9067*/      OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*9079*/      OPC_EmitInteger, MVT::i32, 0, 
/*9082*/      OPC_EmitInteger, MVT::i32, 0, 
/*9085*/      OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*9097*/      OPC_EmitInteger, MVT::i32, 1, 
/*9100*/      OPC_EmitRegister, MVT::i32, AMDGPU::PRED_SEL_OFF,
/*9103*/      OPC_EmitInteger, MVT::i32, 0, 
/*9106*/      OPC_EmitInteger, MVT::i32, 0, 
/*9109*/      OPC_MorphNodeTo, TARGET_VAL(AMDGPU::BFE_UINT_eg), 0,
                  1/*#VTs*/, MVT::i32, 18/*#Ops*/, 3, 4, 0, 5, 6, 7, 1, 8, 9, 10, 2, 11, 12, 13, 14, 15, 16, 17, 
              // Src: (and:i32 (srl:i32 i32:i32:$x, (imm:i32)<<P:Predicate_legalshift32>>:$y), (imm:i32)<<P:Predicate_bfemask>><<X:anonymous.val.404>>:$z) - Complexity = 14
              // Dst: (BFE_UINT_eg:i32 ?:i32:$x, ?:i32:$y, ?:i32:$z)
/*9134*/    /*Scope*/ 20|128,1/*148*/, /*->9284*/
/*9136*/      OPC_RecordChild0, // #0 = $src0
/*9137*/      OPC_RecordChild1, // #1 = $src1
/*9138*/      OPC_SwitchType /*3 cases */, 116,  MVT::i32,// ->9257
/*9141*/        OPC_Scope, 101, /*->9244*/ // 2 children in Scope
/*9143*/          OPC_CheckPatternPredicate, 3, // (Subtarget.getGeneration() <= AMDGPUSubtarget::NORTHERN_ISLANDS)
/*9145*/          OPC_EmitInteger, MVT::i32, 0, 
/*9148*/          OPC_EmitInteger, MVT::i32, 0, 
/*9151*/          OPC_EmitInteger, MVT::i32, 1, 
/*9154*/          OPC_EmitInteger, MVT::i32, 0, 
/*9157*/          OPC_EmitInteger, MVT::i32, 0, 
/*9160*/          OPC_EmitInteger, MVT::i32, 0, 
/*9163*/          OPC_EmitInteger, MVT::i32, 0, 
/*9166*/          OPC_EmitInteger, MVT::i32, 0, 
/*9169*/          OPC_EmitInteger, MVT::i32, 0, 
/*9172*/          OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*9184*/          OPC_EmitInteger, MVT::i32, 0, 
/*9187*/          OPC_EmitInteger, MVT::i32, 0, 
/*9190*/          OPC_EmitInteger, MVT::i32, 0, 
/*9193*/          OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*9205*/          OPC_EmitInteger, MVT::i32, 1, 
/*9208*/          OPC_EmitRegister, MVT::i32, AMDGPU::PRED_SEL_OFF,
/*9211*/          OPC_EmitInteger, MVT::i32, 0, 
/*9214*/          OPC_EmitInteger, MVT::i32, 0, 
/*9217*/          OPC_MorphNodeTo, TARGET_VAL(AMDGPU::AND_INT), 0,
                      1/*#VTs*/, MVT::i32, 20/*#Ops*/, 2, 3, 4, 5, 6, 7, 0, 8, 9, 10, 11, 1, 12, 13, 14, 15, 16, 17, 18, 19, 
                  // Src: (and:i32 R600_Reg32:i32:$src0, R600_Reg32:i32:$src1) - Complexity = 3
                  // Dst: (AND_INT:i32 R600_Reg32:i32:$src0, R600_Reg32:i32:$src1)
/*9244*/        /*Scope*/ 11, /*->9256*/
/*9245*/          OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*9247*/          OPC_MorphNodeTo, TARGET_VAL(AMDGPU::V_AND_B32_e32), 0,
                      1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1, 
                  // Src: (and:i32 i32:i32:$src0, i32:i32:$src1) - Complexity = 3
                  // Dst: (V_AND_B32_e32:i32 i32:i32:$src0, i32:i32:$src1)
/*9256*/        0, /*End of Scope*/
/*9257*/      /*SwitchType*/ 11,  MVT::i64,// ->9270
/*9259*/        OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*9261*/        OPC_MorphNodeTo, TARGET_VAL(AMDGPU::S_AND_B64), 0,
                    1/*#VTs*/, MVT::i64, 2/*#Ops*/, 0, 1, 
                // Src: (and:i64 i64:i64:$src0, i64:i64:$src1) - Complexity = 3
                // Dst: (S_AND_B64:i64 i64:i64:$src0, i64:i64:$src1)
/*9270*/      /*SwitchType*/ 11,  MVT::i1,// ->9283
/*9272*/        OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*9274*/        OPC_MorphNodeTo, TARGET_VAL(AMDGPU::S_AND_B64), 0,
                    1/*#VTs*/, MVT::i1, 2/*#Ops*/, 0, 1, 
                // Src: (and:i1 i1:i1:$src0, i1:i1:$src1) - Complexity = 3
                // Dst: (S_AND_B64:i1 ?:i1:$src0, ?:i1:$src1)
/*9283*/      0, // EndSwitchType
/*9284*/    0, /*End of Scope*/
/*9285*/  /*SwitchOpcode*/ 78|128,23/*3022*/,  TARGET_VAL(ISD::SELECT_CC),// ->12311
/*9289*/    OPC_RecordChild0, // #0 = $src0
/*9290*/    OPC_Scope, 29|128,12/*1565*/, /*->10858*/ // 2 children in Scope
/*9293*/      OPC_CheckChild0Type, MVT::f32,
/*9295*/      OPC_Scope, 14|128,7/*910*/, /*->10208*/ // 2 children in Scope
/*9298*/        OPC_RecordChild1, // #1 = $src1
/*9299*/        OPC_MoveChild, 2,
/*9301*/        OPC_Scope, 68|128,3/*452*/, /*->9756*/ // 2 children in Scope
/*9304*/          OPC_CheckInteger, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*9315*/          OPC_MoveParent,
/*9316*/          OPC_MoveChild, 3,
/*9318*/          OPC_CheckInteger, 0, 
/*9320*/          OPC_MoveParent,
/*9321*/          OPC_MoveChild, 4,
/*9323*/          OPC_CheckOpcode, TARGET_VAL(ISD::CONDCODE),
/*9326*/          OPC_Scope, 106, /*->9434*/ // 4 children in Scope
/*9328*/            OPC_CheckPredicate, 2, // Predicate_COND_OEQ
/*9330*/            OPC_MoveParent,
/*9331*/            OPC_CheckType, MVT::i32,
/*9333*/            OPC_CheckPatternPredicate, 3, // (Subtarget.getGeneration() <= AMDGPUSubtarget::NORTHERN_ISLANDS)
/*9335*/            OPC_EmitInteger, MVT::i32, 0, 
/*9338*/            OPC_EmitInteger, MVT::i32, 0, 
/*9341*/            OPC_EmitInteger, MVT::i32, 1, 
/*9344*/            OPC_EmitInteger, MVT::i32, 0, 
/*9347*/            OPC_EmitInteger, MVT::i32, 0, 
/*9350*/            OPC_EmitInteger, MVT::i32, 0, 
/*9353*/            OPC_EmitInteger, MVT::i32, 0, 
/*9356*/            OPC_EmitInteger, MVT::i32, 0, 
/*9359*/            OPC_EmitInteger, MVT::i32, 0, 
/*9362*/            OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*9374*/            OPC_EmitInteger, MVT::i32, 0, 
/*9377*/            OPC_EmitInteger, MVT::i32, 0, 
/*9380*/            OPC_EmitInteger, MVT::i32, 0, 
/*9383*/            OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*9395*/            OPC_EmitInteger, MVT::i32, 1, 
/*9398*/            OPC_EmitRegister, MVT::i32, AMDGPU::PRED_SEL_OFF,
/*9401*/            OPC_EmitInteger, MVT::i32, 0, 
/*9404*/            OPC_EmitInteger, MVT::i32, 0, 
/*9407*/            OPC_MorphNodeTo, TARGET_VAL(AMDGPU::SETE_DX10), 0,
                        1/*#VTs*/, MVT::i32, 20/*#Ops*/, 2, 3, 4, 5, 6, 7, 0, 8, 9, 10, 11, 1, 12, 13, 14, 15, 16, 17, 18, 19, 
                    // Src: (selectcc:i32 f32:f32:$src0, f32:f32:$src1, -1:i32, 0:i32, (cond:Other)<<P:Predicate_COND_OEQ>>) - Complexity = 13
                    // Dst: (SETE_DX10:i32 f32:f32:$src0, f32:f32:$src1)
/*9434*/          /*Scope*/ 106, /*->9541*/
/*9435*/            OPC_CheckPredicate, 3, // Predicate_COND_OGT
/*9437*/            OPC_MoveParent,
/*9438*/            OPC_CheckType, MVT::i32,
/*9440*/            OPC_CheckPatternPredicate, 3, // (Subtarget.getGeneration() <= AMDGPUSubtarget::NORTHERN_ISLANDS)
/*9442*/            OPC_EmitInteger, MVT::i32, 0, 
/*9445*/            OPC_EmitInteger, MVT::i32, 0, 
/*9448*/            OPC_EmitInteger, MVT::i32, 1, 
/*9451*/            OPC_EmitInteger, MVT::i32, 0, 
/*9454*/            OPC_EmitInteger, MVT::i32, 0, 
/*9457*/            OPC_EmitInteger, MVT::i32, 0, 
/*9460*/            OPC_EmitInteger, MVT::i32, 0, 
/*9463*/            OPC_EmitInteger, MVT::i32, 0, 
/*9466*/            OPC_EmitInteger, MVT::i32, 0, 
/*9469*/            OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*9481*/            OPC_EmitInteger, MVT::i32, 0, 
/*9484*/            OPC_EmitInteger, MVT::i32, 0, 
/*9487*/            OPC_EmitInteger, MVT::i32, 0, 
/*9490*/            OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*9502*/            OPC_EmitInteger, MVT::i32, 1, 
/*9505*/            OPC_EmitRegister, MVT::i32, AMDGPU::PRED_SEL_OFF,
/*9508*/            OPC_EmitInteger, MVT::i32, 0, 
/*9511*/            OPC_EmitInteger, MVT::i32, 0, 
/*9514*/            OPC_MorphNodeTo, TARGET_VAL(AMDGPU::SETGT_DX10), 0,
                        1/*#VTs*/, MVT::i32, 20/*#Ops*/, 2, 3, 4, 5, 6, 7, 0, 8, 9, 10, 11, 1, 12, 13, 14, 15, 16, 17, 18, 19, 
                    // Src: (selectcc:i32 f32:f32:$src0, f32:f32:$src1, -1:i32, 0:i32, (cond:Other)<<P:Predicate_COND_OGT>>) - Complexity = 13
                    // Dst: (SETGT_DX10:i32 f32:f32:$src0, f32:f32:$src1)
/*9541*/          /*Scope*/ 106, /*->9648*/
/*9542*/            OPC_CheckPredicate, 4, // Predicate_COND_OGE
/*9544*/            OPC_MoveParent,
/*9545*/            OPC_CheckType, MVT::i32,
/*9547*/            OPC_CheckPatternPredicate, 3, // (Subtarget.getGeneration() <= AMDGPUSubtarget::NORTHERN_ISLANDS)
/*9549*/            OPC_EmitInteger, MVT::i32, 0, 
/*9552*/            OPC_EmitInteger, MVT::i32, 0, 
/*9555*/            OPC_EmitInteger, MVT::i32, 1, 
/*9558*/            OPC_EmitInteger, MVT::i32, 0, 
/*9561*/            OPC_EmitInteger, MVT::i32, 0, 
/*9564*/            OPC_EmitInteger, MVT::i32, 0, 
/*9567*/            OPC_EmitInteger, MVT::i32, 0, 
/*9570*/            OPC_EmitInteger, MVT::i32, 0, 
/*9573*/            OPC_EmitInteger, MVT::i32, 0, 
/*9576*/            OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*9588*/            OPC_EmitInteger, MVT::i32, 0, 
/*9591*/            OPC_EmitInteger, MVT::i32, 0, 
/*9594*/            OPC_EmitInteger, MVT::i32, 0, 
/*9597*/            OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*9609*/            OPC_EmitInteger, MVT::i32, 1, 
/*9612*/            OPC_EmitRegister, MVT::i32, AMDGPU::PRED_SEL_OFF,
/*9615*/            OPC_EmitInteger, MVT::i32, 0, 
/*9618*/            OPC_EmitInteger, MVT::i32, 0, 
/*9621*/            OPC_MorphNodeTo, TARGET_VAL(AMDGPU::SETGE_DX10), 0,
                        1/*#VTs*/, MVT::i32, 20/*#Ops*/, 2, 3, 4, 5, 6, 7, 0, 8, 9, 10, 11, 1, 12, 13, 14, 15, 16, 17, 18, 19, 
                    // Src: (selectcc:i32 f32:f32:$src0, f32:f32:$src1, -1:i32, 0:i32, (cond:Other)<<P:Predicate_COND_OGE>>) - Complexity = 13
                    // Dst: (SETGE_DX10:i32 f32:f32:$src0, f32:f32:$src1)
/*9648*/          /*Scope*/ 106, /*->9755*/
/*9649*/            OPC_CheckPredicate, 5, // Predicate_COND_UNE
/*9651*/            OPC_MoveParent,
/*9652*/            OPC_CheckType, MVT::i32,
/*9654*/            OPC_CheckPatternPredicate, 3, // (Subtarget.getGeneration() <= AMDGPUSubtarget::NORTHERN_ISLANDS)
/*9656*/            OPC_EmitInteger, MVT::i32, 0, 
/*9659*/            OPC_EmitInteger, MVT::i32, 0, 
/*9662*/            OPC_EmitInteger, MVT::i32, 1, 
/*9665*/            OPC_EmitInteger, MVT::i32, 0, 
/*9668*/            OPC_EmitInteger, MVT::i32, 0, 
/*9671*/            OPC_EmitInteger, MVT::i32, 0, 
/*9674*/            OPC_EmitInteger, MVT::i32, 0, 
/*9677*/            OPC_EmitInteger, MVT::i32, 0, 
/*9680*/            OPC_EmitInteger, MVT::i32, 0, 
/*9683*/            OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*9695*/            OPC_EmitInteger, MVT::i32, 0, 
/*9698*/            OPC_EmitInteger, MVT::i32, 0, 
/*9701*/            OPC_EmitInteger, MVT::i32, 0, 
/*9704*/            OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*9716*/            OPC_EmitInteger, MVT::i32, 1, 
/*9719*/            OPC_EmitRegister, MVT::i32, AMDGPU::PRED_SEL_OFF,
/*9722*/            OPC_EmitInteger, MVT::i32, 0, 
/*9725*/            OPC_EmitInteger, MVT::i32, 0, 
/*9728*/            OPC_MorphNodeTo, TARGET_VAL(AMDGPU::SETNE_DX10), 0,
                        1/*#VTs*/, MVT::i32, 20/*#Ops*/, 2, 3, 4, 5, 6, 7, 0, 8, 9, 10, 11, 1, 12, 13, 14, 15, 16, 17, 18, 19, 
                    // Src: (selectcc:i32 f32:f32:$src0, f32:f32:$src1, -1:i32, 0:i32, (cond:Other)<<P:Predicate_COND_UNE>>) - Complexity = 13
                    // Dst: (SETNE_DX10:i32 f32:f32:$src0, f32:f32:$src1)
/*9755*/          0, /*End of Scope*/
/*9756*/        /*Scope*/ 65|128,3/*449*/, /*->10207*/
/*9758*/          OPC_CheckOpcode, TARGET_VAL(ISD::ConstantFP),
/*9761*/          OPC_CheckPredicate, 6, // Predicate_FP_ONE
/*9763*/          OPC_MoveParent,
/*9764*/          OPC_MoveChild, 3,
/*9766*/          OPC_CheckOpcode, TARGET_VAL(ISD::ConstantFP),
/*9769*/          OPC_CheckPredicate, 7, // Predicate_FP_ZERO
/*9771*/          OPC_MoveParent,
/*9772*/          OPC_MoveChild, 4,
/*9774*/          OPC_CheckOpcode, TARGET_VAL(ISD::CONDCODE),
/*9777*/          OPC_Scope, 106, /*->9885*/ // 4 children in Scope
/*9779*/            OPC_CheckPredicate, 2, // Predicate_COND_OEQ
/*9781*/            OPC_MoveParent,
/*9782*/            OPC_CheckType, MVT::f32,
/*9784*/            OPC_CheckPatternPredicate, 3, // (Subtarget.getGeneration() <= AMDGPUSubtarget::NORTHERN_ISLANDS)
/*9786*/            OPC_EmitInteger, MVT::i32, 0, 
/*9789*/            OPC_EmitInteger, MVT::i32, 0, 
/*9792*/            OPC_EmitInteger, MVT::i32, 1, 
/*9795*/            OPC_EmitInteger, MVT::i32, 0, 
/*9798*/            OPC_EmitInteger, MVT::i32, 0, 
/*9801*/            OPC_EmitInteger, MVT::i32, 0, 
/*9804*/            OPC_EmitInteger, MVT::i32, 0, 
/*9807*/            OPC_EmitInteger, MVT::i32, 0, 
/*9810*/            OPC_EmitInteger, MVT::i32, 0, 
/*9813*/            OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*9825*/            OPC_EmitInteger, MVT::i32, 0, 
/*9828*/            OPC_EmitInteger, MVT::i32, 0, 
/*9831*/            OPC_EmitInteger, MVT::i32, 0, 
/*9834*/            OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*9846*/            OPC_EmitInteger, MVT::i32, 1, 
/*9849*/            OPC_EmitRegister, MVT::i32, AMDGPU::PRED_SEL_OFF,
/*9852*/            OPC_EmitInteger, MVT::i32, 0, 
/*9855*/            OPC_EmitInteger, MVT::i32, 0, 
/*9858*/            OPC_MorphNodeTo, TARGET_VAL(AMDGPU::SETE), 0,
                        1/*#VTs*/, MVT::f32, 20/*#Ops*/, 2, 3, 4, 5, 6, 7, 0, 8, 9, 10, 11, 1, 12, 13, 14, 15, 16, 17, 18, 19, 
                    // Src: (selectcc:f32 f32:f32:$src0, f32:f32:$src1, (fpimm:f32)<<P:Predicate_FP_ONE>>, (fpimm:f32)<<P:Predicate_FP_ZERO>>, (cond:Other)<<P:Predicate_COND_OEQ>>) - Complexity = 11
                    // Dst: (SETE:f32 f32:f32:$src0, f32:f32:$src1)
/*9885*/          /*Scope*/ 106, /*->9992*/
/*9886*/            OPC_CheckPredicate, 3, // Predicate_COND_OGT
/*9888*/            OPC_MoveParent,
/*9889*/            OPC_CheckType, MVT::f32,
/*9891*/            OPC_CheckPatternPredicate, 3, // (Subtarget.getGeneration() <= AMDGPUSubtarget::NORTHERN_ISLANDS)
/*9893*/            OPC_EmitInteger, MVT::i32, 0, 
/*9896*/            OPC_EmitInteger, MVT::i32, 0, 
/*9899*/            OPC_EmitInteger, MVT::i32, 1, 
/*9902*/            OPC_EmitInteger, MVT::i32, 0, 
/*9905*/            OPC_EmitInteger, MVT::i32, 0, 
/*9908*/            OPC_EmitInteger, MVT::i32, 0, 
/*9911*/            OPC_EmitInteger, MVT::i32, 0, 
/*9914*/            OPC_EmitInteger, MVT::i32, 0, 
/*9917*/            OPC_EmitInteger, MVT::i32, 0, 
/*9920*/            OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*9932*/            OPC_EmitInteger, MVT::i32, 0, 
/*9935*/            OPC_EmitInteger, MVT::i32, 0, 
/*9938*/            OPC_EmitInteger, MVT::i32, 0, 
/*9941*/            OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*9953*/            OPC_EmitInteger, MVT::i32, 1, 
/*9956*/            OPC_EmitRegister, MVT::i32, AMDGPU::PRED_SEL_OFF,
/*9959*/            OPC_EmitInteger, MVT::i32, 0, 
/*9962*/            OPC_EmitInteger, MVT::i32, 0, 
/*9965*/            OPC_MorphNodeTo, TARGET_VAL(AMDGPU::SGT), 0,
                        1/*#VTs*/, MVT::f32, 20/*#Ops*/, 2, 3, 4, 5, 6, 7, 0, 8, 9, 10, 11, 1, 12, 13, 14, 15, 16, 17, 18, 19, 
                    // Src: (selectcc:f32 f32:f32:$src0, f32:f32:$src1, (fpimm:f32)<<P:Predicate_FP_ONE>>, (fpimm:f32)<<P:Predicate_FP_ZERO>>, (cond:Other)<<P:Predicate_COND_OGT>>) - Complexity = 11
                    // Dst: (SGT:f32 f32:f32:$src0, f32:f32:$src1)
/*9992*/          /*Scope*/ 106, /*->10099*/
/*9993*/            OPC_CheckPredicate, 4, // Predicate_COND_OGE
/*9995*/            OPC_MoveParent,
/*9996*/            OPC_CheckType, MVT::f32,
/*9998*/            OPC_CheckPatternPredicate, 3, // (Subtarget.getGeneration() <= AMDGPUSubtarget::NORTHERN_ISLANDS)
/*10000*/           OPC_EmitInteger, MVT::i32, 0, 
/*10003*/           OPC_EmitInteger, MVT::i32, 0, 
/*10006*/           OPC_EmitInteger, MVT::i32, 1, 
/*10009*/           OPC_EmitInteger, MVT::i32, 0, 
/*10012*/           OPC_EmitInteger, MVT::i32, 0, 
/*10015*/           OPC_EmitInteger, MVT::i32, 0, 
/*10018*/           OPC_EmitInteger, MVT::i32, 0, 
/*10021*/           OPC_EmitInteger, MVT::i32, 0, 
/*10024*/           OPC_EmitInteger, MVT::i32, 0, 
/*10027*/           OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*10039*/           OPC_EmitInteger, MVT::i32, 0, 
/*10042*/           OPC_EmitInteger, MVT::i32, 0, 
/*10045*/           OPC_EmitInteger, MVT::i32, 0, 
/*10048*/           OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*10060*/           OPC_EmitInteger, MVT::i32, 1, 
/*10063*/           OPC_EmitRegister, MVT::i32, AMDGPU::PRED_SEL_OFF,
/*10066*/           OPC_EmitInteger, MVT::i32, 0, 
/*10069*/           OPC_EmitInteger, MVT::i32, 0, 
/*10072*/           OPC_MorphNodeTo, TARGET_VAL(AMDGPU::SGE), 0,
                        1/*#VTs*/, MVT::f32, 20/*#Ops*/, 2, 3, 4, 5, 6, 7, 0, 8, 9, 10, 11, 1, 12, 13, 14, 15, 16, 17, 18, 19, 
                    // Src: (selectcc:f32 f32:f32:$src0, f32:f32:$src1, (fpimm:f32)<<P:Predicate_FP_ONE>>, (fpimm:f32)<<P:Predicate_FP_ZERO>>, (cond:Other)<<P:Predicate_COND_OGE>>) - Complexity = 11
                    // Dst: (SGE:f32 f32:f32:$src0, f32:f32:$src1)
/*10099*/         /*Scope*/ 106, /*->10206*/
/*10100*/           OPC_CheckPredicate, 5, // Predicate_COND_UNE
/*10102*/           OPC_MoveParent,
/*10103*/           OPC_CheckType, MVT::f32,
/*10105*/           OPC_CheckPatternPredicate, 3, // (Subtarget.getGeneration() <= AMDGPUSubtarget::NORTHERN_ISLANDS)
/*10107*/           OPC_EmitInteger, MVT::i32, 0, 
/*10110*/           OPC_EmitInteger, MVT::i32, 0, 
/*10113*/           OPC_EmitInteger, MVT::i32, 1, 
/*10116*/           OPC_EmitInteger, MVT::i32, 0, 
/*10119*/           OPC_EmitInteger, MVT::i32, 0, 
/*10122*/           OPC_EmitInteger, MVT::i32, 0, 
/*10125*/           OPC_EmitInteger, MVT::i32, 0, 
/*10128*/           OPC_EmitInteger, MVT::i32, 0, 
/*10131*/           OPC_EmitInteger, MVT::i32, 0, 
/*10134*/           OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*10146*/           OPC_EmitInteger, MVT::i32, 0, 
/*10149*/           OPC_EmitInteger, MVT::i32, 0, 
/*10152*/           OPC_EmitInteger, MVT::i32, 0, 
/*10155*/           OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*10167*/           OPC_EmitInteger, MVT::i32, 1, 
/*10170*/           OPC_EmitRegister, MVT::i32, AMDGPU::PRED_SEL_OFF,
/*10173*/           OPC_EmitInteger, MVT::i32, 0, 
/*10176*/           OPC_EmitInteger, MVT::i32, 0, 
/*10179*/           OPC_MorphNodeTo, TARGET_VAL(AMDGPU::SNE), 0,
                        1/*#VTs*/, MVT::f32, 20/*#Ops*/, 2, 3, 4, 5, 6, 7, 0, 8, 9, 10, 11, 1, 12, 13, 14, 15, 16, 17, 18, 19, 
                    // Src: (selectcc:f32 f32:f32:$src0, f32:f32:$src1, (fpimm:f32)<<P:Predicate_FP_ONE>>, (fpimm:f32)<<P:Predicate_FP_ZERO>>, (cond:Other)<<P:Predicate_COND_UNE>>) - Complexity = 11
                    // Dst: (SNE:f32 f32:f32:$src0, f32:f32:$src1)
/*10206*/         0, /*End of Scope*/
/*10207*/       0, /*End of Scope*/
/*10208*/     /*Scope*/ 7|128,5/*647*/, /*->10857*/
/*10210*/       OPC_MoveChild, 1,
/*10212*/       OPC_CheckOpcode, TARGET_VAL(ISD::ConstantFP),
/*10215*/       OPC_CheckPredicate, 7, // Predicate_FP_ZERO
/*10217*/       OPC_MoveParent,
/*10218*/       OPC_RecordChild2, // #1 = $src1
/*10219*/       OPC_RecordChild3, // #2 = $src2
/*10220*/       OPC_MoveChild, 4,
/*10222*/       OPC_CheckOpcode, TARGET_VAL(ISD::CONDCODE),
/*10225*/       OPC_Scope, 104, /*->10331*/ // 6 children in Scope
/*10227*/         OPC_CheckPredicate, 2, // Predicate_COND_OEQ
/*10229*/         OPC_MoveParent,
/*10230*/         OPC_CheckType, MVT::f32,
/*10232*/         OPC_CheckPatternPredicate, 1, // (Subtarget.getGeneration() <= AMDGPUSubtarget::R700)
/*10234*/         OPC_EmitInteger, MVT::i32, 0, 
/*10237*/         OPC_EmitInteger, MVT::i32, 0, 
/*10240*/         OPC_EmitInteger, MVT::i32, 0, 
/*10243*/         OPC_EmitInteger, MVT::i32, 0, 
/*10246*/         OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*10258*/         OPC_EmitInteger, MVT::i32, 0, 
/*10261*/         OPC_EmitInteger, MVT::i32, 0, 
/*10264*/         OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*10276*/         OPC_EmitInteger, MVT::i32, 0, 
/*10279*/         OPC_EmitInteger, MVT::i32, 0, 
/*10282*/         OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*10294*/         OPC_EmitInteger, MVT::i32, 1, 
/*10297*/         OPC_EmitRegister, MVT::i32, AMDGPU::PRED_SEL_OFF,
/*10300*/         OPC_EmitInteger, MVT::i32, 0, 
/*10303*/         OPC_EmitInteger, MVT::i32, 0, 
/*10306*/         OPC_MorphNodeTo, TARGET_VAL(AMDGPU::CNDE_r600), 0,
                      1/*#VTs*/, MVT::f32, 18/*#Ops*/, 3, 4, 0, 5, 6, 7, 1, 8, 9, 10, 2, 11, 12, 13, 14, 15, 16, 17, 
                  // Src: (selectcc:f32 f32:f32:$src0, (fpimm:f32)<<P:Predicate_FP_ZERO>>, f32:f32:$src1, f32:f32:$src2, (cond:Other)<<P:Predicate_COND_OEQ>>) - Complexity = 7
                  // Dst: (CNDE_r600:f32 f32:f32:$src0, f32:f32:$src1, f32:f32:$src2)
/*10331*/       /*Scope*/ 104, /*->10436*/
/*10332*/         OPC_CheckPredicate, 3, // Predicate_COND_OGT
/*10334*/         OPC_MoveParent,
/*10335*/         OPC_CheckType, MVT::f32,
/*10337*/         OPC_CheckPatternPredicate, 1, // (Subtarget.getGeneration() <= AMDGPUSubtarget::R700)
/*10339*/         OPC_EmitInteger, MVT::i32, 0, 
/*10342*/         OPC_EmitInteger, MVT::i32, 0, 
/*10345*/         OPC_EmitInteger, MVT::i32, 0, 
/*10348*/         OPC_EmitInteger, MVT::i32, 0, 
/*10351*/         OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*10363*/         OPC_EmitInteger, MVT::i32, 0, 
/*10366*/         OPC_EmitInteger, MVT::i32, 0, 
/*10369*/         OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*10381*/         OPC_EmitInteger, MVT::i32, 0, 
/*10384*/         OPC_EmitInteger, MVT::i32, 0, 
/*10387*/         OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*10399*/         OPC_EmitInteger, MVT::i32, 1, 
/*10402*/         OPC_EmitRegister, MVT::i32, AMDGPU::PRED_SEL_OFF,
/*10405*/         OPC_EmitInteger, MVT::i32, 0, 
/*10408*/         OPC_EmitInteger, MVT::i32, 0, 
/*10411*/         OPC_MorphNodeTo, TARGET_VAL(AMDGPU::CNDGT_r600), 0,
                      1/*#VTs*/, MVT::f32, 18/*#Ops*/, 3, 4, 0, 5, 6, 7, 1, 8, 9, 10, 2, 11, 12, 13, 14, 15, 16, 17, 
                  // Src: (selectcc:f32 f32:f32:$src0, (fpimm:f32)<<P:Predicate_FP_ZERO>>, f32:f32:$src1, f32:f32:$src2, (cond:Other)<<P:Predicate_COND_OGT>>) - Complexity = 7
                  // Dst: (CNDGT_r600:f32 f32:f32:$src0, f32:f32:$src1, f32:f32:$src2)
/*10436*/       /*Scope*/ 104, /*->10541*/
/*10437*/         OPC_CheckPredicate, 4, // Predicate_COND_OGE
/*10439*/         OPC_MoveParent,
/*10440*/         OPC_CheckType, MVT::f32,
/*10442*/         OPC_CheckPatternPredicate, 1, // (Subtarget.getGeneration() <= AMDGPUSubtarget::R700)
/*10444*/         OPC_EmitInteger, MVT::i32, 0, 
/*10447*/         OPC_EmitInteger, MVT::i32, 0, 
/*10450*/         OPC_EmitInteger, MVT::i32, 0, 
/*10453*/         OPC_EmitInteger, MVT::i32, 0, 
/*10456*/         OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*10468*/         OPC_EmitInteger, MVT::i32, 0, 
/*10471*/         OPC_EmitInteger, MVT::i32, 0, 
/*10474*/         OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*10486*/         OPC_EmitInteger, MVT::i32, 0, 
/*10489*/         OPC_EmitInteger, MVT::i32, 0, 
/*10492*/         OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*10504*/         OPC_EmitInteger, MVT::i32, 1, 
/*10507*/         OPC_EmitRegister, MVT::i32, AMDGPU::PRED_SEL_OFF,
/*10510*/         OPC_EmitInteger, MVT::i32, 0, 
/*10513*/         OPC_EmitInteger, MVT::i32, 0, 
/*10516*/         OPC_MorphNodeTo, TARGET_VAL(AMDGPU::CNDGE_r600), 0,
                      1/*#VTs*/, MVT::f32, 18/*#Ops*/, 3, 4, 0, 5, 6, 7, 1, 8, 9, 10, 2, 11, 12, 13, 14, 15, 16, 17, 
                  // Src: (selectcc:f32 f32:f32:$src0, (fpimm:f32)<<P:Predicate_FP_ZERO>>, f32:f32:$src1, f32:f32:$src2, (cond:Other)<<P:Predicate_COND_OGE>>) - Complexity = 7
                  // Dst: (CNDGE_r600:f32 f32:f32:$src0, f32:f32:$src1, f32:f32:$src2)
/*10541*/       /*Scope*/ 104, /*->10646*/
/*10542*/         OPC_CheckPredicate, 2, // Predicate_COND_OEQ
/*10544*/         OPC_MoveParent,
/*10545*/         OPC_CheckType, MVT::f32,
/*10547*/         OPC_CheckPatternPredicate, 2, // (Subtarget.getGeneration() == AMDGPUSubtarget::EVERGREEN|| Subtarget.getGeneration() ==AMDGPUSubtarget::NORTHERN_ISLANDS)
/*10549*/         OPC_EmitInteger, MVT::i32, 0, 
/*10552*/         OPC_EmitInteger, MVT::i32, 0, 
/*10555*/         OPC_EmitInteger, MVT::i32, 0, 
/*10558*/         OPC_EmitInteger, MVT::i32, 0, 
/*10561*/         OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*10573*/         OPC_EmitInteger, MVT::i32, 0, 
/*10576*/         OPC_EmitInteger, MVT::i32, 0, 
/*10579*/         OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*10591*/         OPC_EmitInteger, MVT::i32, 0, 
/*10594*/         OPC_EmitInteger, MVT::i32, 0, 
/*10597*/         OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*10609*/         OPC_EmitInteger, MVT::i32, 1, 
/*10612*/         OPC_EmitRegister, MVT::i32, AMDGPU::PRED_SEL_OFF,
/*10615*/         OPC_EmitInteger, MVT::i32, 0, 
/*10618*/         OPC_EmitInteger, MVT::i32, 0, 
/*10621*/         OPC_MorphNodeTo, TARGET_VAL(AMDGPU::CNDE_eg), 0,
                      1/*#VTs*/, MVT::f32, 18/*#Ops*/, 3, 4, 0, 5, 6, 7, 1, 8, 9, 10, 2, 11, 12, 13, 14, 15, 16, 17, 
                  // Src: (selectcc:f32 f32:f32:$src0, (fpimm:f32)<<P:Predicate_FP_ZERO>>, f32:f32:$src1, f32:f32:$src2, (cond:Other)<<P:Predicate_COND_OEQ>>) - Complexity = 7
                  // Dst: (CNDE_eg:f32 f32:f32:$src0, f32:f32:$src1, f32:f32:$src2)
/*10646*/       /*Scope*/ 104, /*->10751*/
/*10647*/         OPC_CheckPredicate, 3, // Predicate_COND_OGT
/*10649*/         OPC_MoveParent,
/*10650*/         OPC_CheckType, MVT::f32,
/*10652*/         OPC_CheckPatternPredicate, 2, // (Subtarget.getGeneration() == AMDGPUSubtarget::EVERGREEN|| Subtarget.getGeneration() ==AMDGPUSubtarget::NORTHERN_ISLANDS)
/*10654*/         OPC_EmitInteger, MVT::i32, 0, 
/*10657*/         OPC_EmitInteger, MVT::i32, 0, 
/*10660*/         OPC_EmitInteger, MVT::i32, 0, 
/*10663*/         OPC_EmitInteger, MVT::i32, 0, 
/*10666*/         OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*10678*/         OPC_EmitInteger, MVT::i32, 0, 
/*10681*/         OPC_EmitInteger, MVT::i32, 0, 
/*10684*/         OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*10696*/         OPC_EmitInteger, MVT::i32, 0, 
/*10699*/         OPC_EmitInteger, MVT::i32, 0, 
/*10702*/         OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*10714*/         OPC_EmitInteger, MVT::i32, 1, 
/*10717*/         OPC_EmitRegister, MVT::i32, AMDGPU::PRED_SEL_OFF,
/*10720*/         OPC_EmitInteger, MVT::i32, 0, 
/*10723*/         OPC_EmitInteger, MVT::i32, 0, 
/*10726*/         OPC_MorphNodeTo, TARGET_VAL(AMDGPU::CNDGT_eg), 0,
                      1/*#VTs*/, MVT::f32, 18/*#Ops*/, 3, 4, 0, 5, 6, 7, 1, 8, 9, 10, 2, 11, 12, 13, 14, 15, 16, 17, 
                  // Src: (selectcc:f32 f32:f32:$src0, (fpimm:f32)<<P:Predicate_FP_ZERO>>, f32:f32:$src1, f32:f32:$src2, (cond:Other)<<P:Predicate_COND_OGT>>) - Complexity = 7
                  // Dst: (CNDGT_eg:f32 f32:f32:$src0, f32:f32:$src1, f32:f32:$src2)
/*10751*/       /*Scope*/ 104, /*->10856*/
/*10752*/         OPC_CheckPredicate, 4, // Predicate_COND_OGE
/*10754*/         OPC_MoveParent,
/*10755*/         OPC_CheckType, MVT::f32,
/*10757*/         OPC_CheckPatternPredicate, 2, // (Subtarget.getGeneration() == AMDGPUSubtarget::EVERGREEN|| Subtarget.getGeneration() ==AMDGPUSubtarget::NORTHERN_ISLANDS)
/*10759*/         OPC_EmitInteger, MVT::i32, 0, 
/*10762*/         OPC_EmitInteger, MVT::i32, 0, 
/*10765*/         OPC_EmitInteger, MVT::i32, 0, 
/*10768*/         OPC_EmitInteger, MVT::i32, 0, 
/*10771*/         OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*10783*/         OPC_EmitInteger, MVT::i32, 0, 
/*10786*/         OPC_EmitInteger, MVT::i32, 0, 
/*10789*/         OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*10801*/         OPC_EmitInteger, MVT::i32, 0, 
/*10804*/         OPC_EmitInteger, MVT::i32, 0, 
/*10807*/         OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*10819*/         OPC_EmitInteger, MVT::i32, 1, 
/*10822*/         OPC_EmitRegister, MVT::i32, AMDGPU::PRED_SEL_OFF,
/*10825*/         OPC_EmitInteger, MVT::i32, 0, 
/*10828*/         OPC_EmitInteger, MVT::i32, 0, 
/*10831*/         OPC_MorphNodeTo, TARGET_VAL(AMDGPU::CNDGE_eg), 0,
                      1/*#VTs*/, MVT::f32, 18/*#Ops*/, 3, 4, 0, 5, 6, 7, 1, 8, 9, 10, 2, 11, 12, 13, 14, 15, 16, 17, 
                  // Src: (selectcc:f32 f32:f32:$src0, (fpimm:f32)<<P:Predicate_FP_ZERO>>, f32:f32:$src1, f32:f32:$src2, (cond:Other)<<P:Predicate_COND_OGE>>) - Complexity = 7
                  // Dst: (CNDGE_eg:f32 f32:f32:$src0, f32:f32:$src1, f32:f32:$src2)
/*10856*/       0, /*End of Scope*/
/*10857*/     0, /*End of Scope*/
/*10858*/   /*Scope*/ 42|128,11/*1450*/, /*->12310*/
/*10860*/     OPC_CheckChild0Type, MVT::i32,
/*10862*/     OPC_Scope, 26|128,5/*666*/, /*->11531*/ // 2 children in Scope
/*10865*/       OPC_RecordChild1, // #1 = $src1
/*10866*/       OPC_MoveChild, 2,
/*10868*/       OPC_CheckInteger, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*10879*/       OPC_MoveParent,
/*10880*/       OPC_MoveChild, 3,
/*10882*/       OPC_CheckInteger, 0, 
/*10884*/       OPC_MoveParent,
/*10885*/       OPC_MoveChild, 4,
/*10887*/       OPC_Scope, 106, /*->10995*/ // 6 children in Scope
/*10889*/         OPC_CheckCondCode, ISD::SETEQ,
/*10891*/         OPC_MoveParent,
/*10892*/         OPC_CheckType, MVT::i32,
/*10894*/         OPC_CheckPatternPredicate, 3, // (Subtarget.getGeneration() <= AMDGPUSubtarget::NORTHERN_ISLANDS)
/*10896*/         OPC_EmitInteger, MVT::i32, 0, 
/*10899*/         OPC_EmitInteger, MVT::i32, 0, 
/*10902*/         OPC_EmitInteger, MVT::i32, 1, 
/*10905*/         OPC_EmitInteger, MVT::i32, 0, 
/*10908*/         OPC_EmitInteger, MVT::i32, 0, 
/*10911*/         OPC_EmitInteger, MVT::i32, 0, 
/*10914*/         OPC_EmitInteger, MVT::i32, 0, 
/*10917*/         OPC_EmitInteger, MVT::i32, 0, 
/*10920*/         OPC_EmitInteger, MVT::i32, 0, 
/*10923*/         OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*10935*/         OPC_EmitInteger, MVT::i32, 0, 
/*10938*/         OPC_EmitInteger, MVT::i32, 0, 
/*10941*/         OPC_EmitInteger, MVT::i32, 0, 
/*10944*/         OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*10956*/         OPC_EmitInteger, MVT::i32, 1, 
/*10959*/         OPC_EmitRegister, MVT::i32, AMDGPU::PRED_SEL_OFF,
/*10962*/         OPC_EmitInteger, MVT::i32, 0, 
/*10965*/         OPC_EmitInteger, MVT::i32, 0, 
/*10968*/         OPC_MorphNodeTo, TARGET_VAL(AMDGPU::SETE_INT), 0,
                      1/*#VTs*/, MVT::i32, 20/*#Ops*/, 2, 3, 4, 5, 6, 7, 0, 8, 9, 10, 11, 1, 12, 13, 14, 15, 16, 17, 18, 19, 
                  // Src: (selectcc:i32 i32:i32:$src0, i32:i32:$src1, -1:i32, 0:i32, SETEQ:Other) - Complexity = 13
                  // Dst: (SETE_INT:i32 i32:i32:$src0, i32:i32:$src1)
/*10995*/       /*Scope*/ 106, /*->11102*/
/*10996*/         OPC_CheckCondCode, ISD::SETGT,
/*10998*/         OPC_MoveParent,
/*10999*/         OPC_CheckType, MVT::i32,
/*11001*/         OPC_CheckPatternPredicate, 3, // (Subtarget.getGeneration() <= AMDGPUSubtarget::NORTHERN_ISLANDS)
/*11003*/         OPC_EmitInteger, MVT::i32, 0, 
/*11006*/         OPC_EmitInteger, MVT::i32, 0, 
/*11009*/         OPC_EmitInteger, MVT::i32, 1, 
/*11012*/         OPC_EmitInteger, MVT::i32, 0, 
/*11015*/         OPC_EmitInteger, MVT::i32, 0, 
/*11018*/         OPC_EmitInteger, MVT::i32, 0, 
/*11021*/         OPC_EmitInteger, MVT::i32, 0, 
/*11024*/         OPC_EmitInteger, MVT::i32, 0, 
/*11027*/         OPC_EmitInteger, MVT::i32, 0, 
/*11030*/         OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*11042*/         OPC_EmitInteger, MVT::i32, 0, 
/*11045*/         OPC_EmitInteger, MVT::i32, 0, 
/*11048*/         OPC_EmitInteger, MVT::i32, 0, 
/*11051*/         OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*11063*/         OPC_EmitInteger, MVT::i32, 1, 
/*11066*/         OPC_EmitRegister, MVT::i32, AMDGPU::PRED_SEL_OFF,
/*11069*/         OPC_EmitInteger, MVT::i32, 0, 
/*11072*/         OPC_EmitInteger, MVT::i32, 0, 
/*11075*/         OPC_MorphNodeTo, TARGET_VAL(AMDGPU::SETGT_INT), 0,
                      1/*#VTs*/, MVT::i32, 20/*#Ops*/, 2, 3, 4, 5, 6, 7, 0, 8, 9, 10, 11, 1, 12, 13, 14, 15, 16, 17, 18, 19, 
                  // Src: (selectcc:i32 i32:i32:$src0, i32:i32:$src1, -1:i32, 0:i32, SETGT:Other) - Complexity = 13
                  // Dst: (SETGT_INT:i32 i32:i32:$src0, i32:i32:$src1)
/*11102*/       /*Scope*/ 106, /*->11209*/
/*11103*/         OPC_CheckCondCode, ISD::SETGE,
/*11105*/         OPC_MoveParent,
/*11106*/         OPC_CheckType, MVT::i32,
/*11108*/         OPC_CheckPatternPredicate, 3, // (Subtarget.getGeneration() <= AMDGPUSubtarget::NORTHERN_ISLANDS)
/*11110*/         OPC_EmitInteger, MVT::i32, 0, 
/*11113*/         OPC_EmitInteger, MVT::i32, 0, 
/*11116*/         OPC_EmitInteger, MVT::i32, 1, 
/*11119*/         OPC_EmitInteger, MVT::i32, 0, 
/*11122*/         OPC_EmitInteger, MVT::i32, 0, 
/*11125*/         OPC_EmitInteger, MVT::i32, 0, 
/*11128*/         OPC_EmitInteger, MVT::i32, 0, 
/*11131*/         OPC_EmitInteger, MVT::i32, 0, 
/*11134*/         OPC_EmitInteger, MVT::i32, 0, 
/*11137*/         OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*11149*/         OPC_EmitInteger, MVT::i32, 0, 
/*11152*/         OPC_EmitInteger, MVT::i32, 0, 
/*11155*/         OPC_EmitInteger, MVT::i32, 0, 
/*11158*/         OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*11170*/         OPC_EmitInteger, MVT::i32, 1, 
/*11173*/         OPC_EmitRegister, MVT::i32, AMDGPU::PRED_SEL_OFF,
/*11176*/         OPC_EmitInteger, MVT::i32, 0, 
/*11179*/         OPC_EmitInteger, MVT::i32, 0, 
/*11182*/         OPC_MorphNodeTo, TARGET_VAL(AMDGPU::SETGE_INT), 0,
                      1/*#VTs*/, MVT::i32, 20/*#Ops*/, 2, 3, 4, 5, 6, 7, 0, 8, 9, 10, 11, 1, 12, 13, 14, 15, 16, 17, 18, 19, 
                  // Src: (selectcc:i32 i32:i32:$src0, i32:i32:$src1, -1:i32, 0:i32, SETGE:Other) - Complexity = 13
                  // Dst: (SETGE_INT:i32 i32:i32:$src0, i32:i32:$src1)
/*11209*/       /*Scope*/ 106, /*->11316*/
/*11210*/         OPC_CheckCondCode, ISD::SETNE,
/*11212*/         OPC_MoveParent,
/*11213*/         OPC_CheckType, MVT::i32,
/*11215*/         OPC_CheckPatternPredicate, 3, // (Subtarget.getGeneration() <= AMDGPUSubtarget::NORTHERN_ISLANDS)
/*11217*/         OPC_EmitInteger, MVT::i32, 0, 
/*11220*/         OPC_EmitInteger, MVT::i32, 0, 
/*11223*/         OPC_EmitInteger, MVT::i32, 1, 
/*11226*/         OPC_EmitInteger, MVT::i32, 0, 
/*11229*/         OPC_EmitInteger, MVT::i32, 0, 
/*11232*/         OPC_EmitInteger, MVT::i32, 0, 
/*11235*/         OPC_EmitInteger, MVT::i32, 0, 
/*11238*/         OPC_EmitInteger, MVT::i32, 0, 
/*11241*/         OPC_EmitInteger, MVT::i32, 0, 
/*11244*/         OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*11256*/         OPC_EmitInteger, MVT::i32, 0, 
/*11259*/         OPC_EmitInteger, MVT::i32, 0, 
/*11262*/         OPC_EmitInteger, MVT::i32, 0, 
/*11265*/         OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*11277*/         OPC_EmitInteger, MVT::i32, 1, 
/*11280*/         OPC_EmitRegister, MVT::i32, AMDGPU::PRED_SEL_OFF,
/*11283*/         OPC_EmitInteger, MVT::i32, 0, 
/*11286*/         OPC_EmitInteger, MVT::i32, 0, 
/*11289*/         OPC_MorphNodeTo, TARGET_VAL(AMDGPU::SETNE_INT), 0,
                      1/*#VTs*/, MVT::i32, 20/*#Ops*/, 2, 3, 4, 5, 6, 7, 0, 8, 9, 10, 11, 1, 12, 13, 14, 15, 16, 17, 18, 19, 
                  // Src: (selectcc:i32 i32:i32:$src0, i32:i32:$src1, -1:i32, 0:i32, SETNE:Other) - Complexity = 13
                  // Dst: (SETNE_INT:i32 i32:i32:$src0, i32:i32:$src1)
/*11316*/       /*Scope*/ 106, /*->11423*/
/*11317*/         OPC_CheckCondCode, ISD::SETUGT,
/*11319*/         OPC_MoveParent,
/*11320*/         OPC_CheckType, MVT::i32,
/*11322*/         OPC_CheckPatternPredicate, 3, // (Subtarget.getGeneration() <= AMDGPUSubtarget::NORTHERN_ISLANDS)
/*11324*/         OPC_EmitInteger, MVT::i32, 0, 
/*11327*/         OPC_EmitInteger, MVT::i32, 0, 
/*11330*/         OPC_EmitInteger, MVT::i32, 1, 
/*11333*/         OPC_EmitInteger, MVT::i32, 0, 
/*11336*/         OPC_EmitInteger, MVT::i32, 0, 
/*11339*/         OPC_EmitInteger, MVT::i32, 0, 
/*11342*/         OPC_EmitInteger, MVT::i32, 0, 
/*11345*/         OPC_EmitInteger, MVT::i32, 0, 
/*11348*/         OPC_EmitInteger, MVT::i32, 0, 
/*11351*/         OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*11363*/         OPC_EmitInteger, MVT::i32, 0, 
/*11366*/         OPC_EmitInteger, MVT::i32, 0, 
/*11369*/         OPC_EmitInteger, MVT::i32, 0, 
/*11372*/         OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*11384*/         OPC_EmitInteger, MVT::i32, 1, 
/*11387*/         OPC_EmitRegister, MVT::i32, AMDGPU::PRED_SEL_OFF,
/*11390*/         OPC_EmitInteger, MVT::i32, 0, 
/*11393*/         OPC_EmitInteger, MVT::i32, 0, 
/*11396*/         OPC_MorphNodeTo, TARGET_VAL(AMDGPU::SETGT_UINT), 0,
                      1/*#VTs*/, MVT::i32, 20/*#Ops*/, 2, 3, 4, 5, 6, 7, 0, 8, 9, 10, 11, 1, 12, 13, 14, 15, 16, 17, 18, 19, 
                  // Src: (selectcc:i32 i32:i32:$src0, i32:i32:$src1, -1:i32, 0:i32, SETUGT:Other) - Complexity = 13
                  // Dst: (SETGT_UINT:i32 i32:i32:$src0, i32:i32:$src1)
/*11423*/       /*Scope*/ 106, /*->11530*/
/*11424*/         OPC_CheckCondCode, ISD::SETUGE,
/*11426*/         OPC_MoveParent,
/*11427*/         OPC_CheckType, MVT::i32,
/*11429*/         OPC_CheckPatternPredicate, 3, // (Subtarget.getGeneration() <= AMDGPUSubtarget::NORTHERN_ISLANDS)
/*11431*/         OPC_EmitInteger, MVT::i32, 0, 
/*11434*/         OPC_EmitInteger, MVT::i32, 0, 
/*11437*/         OPC_EmitInteger, MVT::i32, 1, 
/*11440*/         OPC_EmitInteger, MVT::i32, 0, 
/*11443*/         OPC_EmitInteger, MVT::i32, 0, 
/*11446*/         OPC_EmitInteger, MVT::i32, 0, 
/*11449*/         OPC_EmitInteger, MVT::i32, 0, 
/*11452*/         OPC_EmitInteger, MVT::i32, 0, 
/*11455*/         OPC_EmitInteger, MVT::i32, 0, 
/*11458*/         OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*11470*/         OPC_EmitInteger, MVT::i32, 0, 
/*11473*/         OPC_EmitInteger, MVT::i32, 0, 
/*11476*/         OPC_EmitInteger, MVT::i32, 0, 
/*11479*/         OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*11491*/         OPC_EmitInteger, MVT::i32, 1, 
/*11494*/         OPC_EmitRegister, MVT::i32, AMDGPU::PRED_SEL_OFF,
/*11497*/         OPC_EmitInteger, MVT::i32, 0, 
/*11500*/         OPC_EmitInteger, MVT::i32, 0, 
/*11503*/         OPC_MorphNodeTo, TARGET_VAL(AMDGPU::SETGE_UINT), 0,
                      1/*#VTs*/, MVT::i32, 20/*#Ops*/, 2, 3, 4, 5, 6, 7, 0, 8, 9, 10, 11, 1, 12, 13, 14, 15, 16, 17, 18, 19, 
                  // Src: (selectcc:i32 i32:i32:$src0, i32:i32:$src1, -1:i32, 0:i32, SETUGE:Other) - Complexity = 13
                  // Dst: (SETGE_UINT:i32 i32:i32:$src0, i32:i32:$src1)
/*11530*/       0, /*End of Scope*/
/*11531*/     /*Scope*/ 8|128,6/*776*/, /*->12309*/
/*11533*/       OPC_MoveChild, 1,
/*11535*/       OPC_Scope, 6|128,5/*646*/, /*->12184*/ // 2 children in Scope
/*11538*/         OPC_CheckInteger, 0, 
/*11540*/         OPC_MoveParent,
/*11541*/         OPC_RecordChild2, // #1 = $src1
/*11542*/         OPC_RecordChild3, // #2 = $src2
/*11543*/         OPC_MoveChild, 4,
/*11545*/         OPC_Scope, 64|128,2/*320*/, /*->11868*/ // 4 children in Scope
/*11548*/           OPC_CheckOpcode, TARGET_VAL(ISD::CONDCODE),
/*11551*/           OPC_Scope, 104, /*->11657*/ // 3 children in Scope
/*11553*/             OPC_CheckPredicate, 8, // Predicate_COND_EQ
/*11555*/             OPC_MoveParent,
/*11556*/             OPC_CheckType, MVT::i32,
/*11558*/             OPC_CheckPatternPredicate, 3, // (Subtarget.getGeneration() <= AMDGPUSubtarget::NORTHERN_ISLANDS)
/*11560*/             OPC_EmitInteger, MVT::i32, 0, 
/*11563*/             OPC_EmitInteger, MVT::i32, 0, 
/*11566*/             OPC_EmitInteger, MVT::i32, 0, 
/*11569*/             OPC_EmitInteger, MVT::i32, 0, 
/*11572*/             OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*11584*/             OPC_EmitInteger, MVT::i32, 0, 
/*11587*/             OPC_EmitInteger, MVT::i32, 0, 
/*11590*/             OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*11602*/             OPC_EmitInteger, MVT::i32, 0, 
/*11605*/             OPC_EmitInteger, MVT::i32, 0, 
/*11608*/             OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*11620*/             OPC_EmitInteger, MVT::i32, 1, 
/*11623*/             OPC_EmitRegister, MVT::i32, AMDGPU::PRED_SEL_OFF,
/*11626*/             OPC_EmitInteger, MVT::i32, 0, 
/*11629*/             OPC_EmitInteger, MVT::i32, 0, 
/*11632*/             OPC_MorphNodeTo, TARGET_VAL(AMDGPU::CNDE_INT), 0,
                          1/*#VTs*/, MVT::i32, 18/*#Ops*/, 3, 4, 0, 5, 6, 7, 1, 8, 9, 10, 2, 11, 12, 13, 14, 15, 16, 17, 
                      // Src: (selectcc:i32 i32:i32:$src0, 0:i32, i32:i32:$src1, i32:i32:$src2, (cond:Other)<<P:Predicate_COND_EQ>>) - Complexity = 8
                      // Dst: (CNDE_INT:i32 i32:i32:$src0, i32:i32:$src1, i32:i32:$src2)
/*11657*/           /*Scope*/ 104, /*->11762*/
/*11658*/             OPC_CheckPredicate, 9, // Predicate_COND_SGE
/*11660*/             OPC_MoveParent,
/*11661*/             OPC_CheckType, MVT::i32,
/*11663*/             OPC_CheckPatternPredicate, 3, // (Subtarget.getGeneration() <= AMDGPUSubtarget::NORTHERN_ISLANDS)
/*11665*/             OPC_EmitInteger, MVT::i32, 0, 
/*11668*/             OPC_EmitInteger, MVT::i32, 0, 
/*11671*/             OPC_EmitInteger, MVT::i32, 0, 
/*11674*/             OPC_EmitInteger, MVT::i32, 0, 
/*11677*/             OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*11689*/             OPC_EmitInteger, MVT::i32, 0, 
/*11692*/             OPC_EmitInteger, MVT::i32, 0, 
/*11695*/             OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*11707*/             OPC_EmitInteger, MVT::i32, 0, 
/*11710*/             OPC_EmitInteger, MVT::i32, 0, 
/*11713*/             OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*11725*/             OPC_EmitInteger, MVT::i32, 1, 
/*11728*/             OPC_EmitRegister, MVT::i32, AMDGPU::PRED_SEL_OFF,
/*11731*/             OPC_EmitInteger, MVT::i32, 0, 
/*11734*/             OPC_EmitInteger, MVT::i32, 0, 
/*11737*/             OPC_MorphNodeTo, TARGET_VAL(AMDGPU::CNDGE_INT), 0,
                          1/*#VTs*/, MVT::i32, 18/*#Ops*/, 3, 4, 0, 5, 6, 7, 1, 8, 9, 10, 2, 11, 12, 13, 14, 15, 16, 17, 
                      // Src: (selectcc:i32 i32:i32:$src0, 0:i32, i32:i32:$src1, i32:i32:$src2, (cond:Other)<<P:Predicate_COND_SGE>>) - Complexity = 8
                      // Dst: (CNDGE_INT:i32 i32:i32:$src0, i32:i32:$src1, i32:i32:$src2)
/*11762*/           /*Scope*/ 104, /*->11867*/
/*11763*/             OPC_CheckPredicate, 10, // Predicate_COND_SGT
/*11765*/             OPC_MoveParent,
/*11766*/             OPC_CheckType, MVT::i32,
/*11768*/             OPC_CheckPatternPredicate, 3, // (Subtarget.getGeneration() <= AMDGPUSubtarget::NORTHERN_ISLANDS)
/*11770*/             OPC_EmitInteger, MVT::i32, 0, 
/*11773*/             OPC_EmitInteger, MVT::i32, 0, 
/*11776*/             OPC_EmitInteger, MVT::i32, 0, 
/*11779*/             OPC_EmitInteger, MVT::i32, 0, 
/*11782*/             OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*11794*/             OPC_EmitInteger, MVT::i32, 0, 
/*11797*/             OPC_EmitInteger, MVT::i32, 0, 
/*11800*/             OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*11812*/             OPC_EmitInteger, MVT::i32, 0, 
/*11815*/             OPC_EmitInteger, MVT::i32, 0, 
/*11818*/             OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*11830*/             OPC_EmitInteger, MVT::i32, 1, 
/*11833*/             OPC_EmitRegister, MVT::i32, AMDGPU::PRED_SEL_OFF,
/*11836*/             OPC_EmitInteger, MVT::i32, 0, 
/*11839*/             OPC_EmitInteger, MVT::i32, 0, 
/*11842*/             OPC_MorphNodeTo, TARGET_VAL(AMDGPU::CNDGT_INT), 0,
                          1/*#VTs*/, MVT::i32, 18/*#Ops*/, 3, 4, 0, 5, 6, 7, 1, 8, 9, 10, 2, 11, 12, 13, 14, 15, 16, 17, 
                      // Src: (selectcc:i32 i32:i32:$src0, 0:i32, i32:i32:$src1, i32:i32:$src2, (cond:Other)<<P:Predicate_COND_SGT>>) - Complexity = 8
                      // Dst: (CNDGT_INT:i32 i32:i32:$src0, i32:i32:$src1, i32:i32:$src2)
/*11867*/           0, /*End of Scope*/
/*11868*/         /*Scope*/ 104, /*->11973*/
/*11869*/           OPC_CheckCondCode, ISD::SETEQ,
/*11871*/           OPC_MoveParent,
/*11872*/           OPC_CheckType, MVT::f32,
/*11874*/           OPC_CheckPatternPredicate, 3, // (Subtarget.getGeneration() <= AMDGPUSubtarget::NORTHERN_ISLANDS)
/*11876*/           OPC_EmitInteger, MVT::i32, 0, 
/*11879*/           OPC_EmitInteger, MVT::i32, 0, 
/*11882*/           OPC_EmitInteger, MVT::i32, 0, 
/*11885*/           OPC_EmitInteger, MVT::i32, 0, 
/*11888*/           OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*11900*/           OPC_EmitInteger, MVT::i32, 0, 
/*11903*/           OPC_EmitInteger, MVT::i32, 0, 
/*11906*/           OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*11918*/           OPC_EmitInteger, MVT::i32, 0, 
/*11921*/           OPC_EmitInteger, MVT::i32, 0, 
/*11924*/           OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*11936*/           OPC_EmitInteger, MVT::i32, 1, 
/*11939*/           OPC_EmitRegister, MVT::i32, AMDGPU::PRED_SEL_OFF,
/*11942*/           OPC_EmitInteger, MVT::i32, 0, 
/*11945*/           OPC_EmitInteger, MVT::i32, 0, 
/*11948*/           OPC_MorphNodeTo, TARGET_VAL(AMDGPU::CNDE_INT), 0,
                        1/*#VTs*/, MVT::f32, 18/*#Ops*/, 3, 4, 0, 5, 6, 7, 1, 8, 9, 10, 2, 11, 12, 13, 14, 15, 16, 17, 
                    // Src: (selectcc:f32 i32:i32:$src0, 0:i32, f32:f32:$src1, f32:f32:$src2, SETEQ:Other) - Complexity = 8
                    // Dst: (CNDE_INT:f32 ?:i32:$src0, ?:f32:$src1, ?:f32:$src2)
/*11973*/         /*Scope*/ 104, /*->12078*/
/*11974*/           OPC_CheckCondCode, ISD::SETGT,
/*11976*/           OPC_MoveParent,
/*11977*/           OPC_CheckType, MVT::f32,
/*11979*/           OPC_CheckPatternPredicate, 3, // (Subtarget.getGeneration() <= AMDGPUSubtarget::NORTHERN_ISLANDS)
/*11981*/           OPC_EmitInteger, MVT::i32, 0, 
/*11984*/           OPC_EmitInteger, MVT::i32, 0, 
/*11987*/           OPC_EmitInteger, MVT::i32, 0, 
/*11990*/           OPC_EmitInteger, MVT::i32, 0, 
/*11993*/           OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*12005*/           OPC_EmitInteger, MVT::i32, 0, 
/*12008*/           OPC_EmitInteger, MVT::i32, 0, 
/*12011*/           OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*12023*/           OPC_EmitInteger, MVT::i32, 0, 
/*12026*/           OPC_EmitInteger, MVT::i32, 0, 
/*12029*/           OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*12041*/           OPC_EmitInteger, MVT::i32, 1, 
/*12044*/           OPC_EmitRegister, MVT::i32, AMDGPU::PRED_SEL_OFF,
/*12047*/           OPC_EmitInteger, MVT::i32, 0, 
/*12050*/           OPC_EmitInteger, MVT::i32, 0, 
/*12053*/           OPC_MorphNodeTo, TARGET_VAL(AMDGPU::CNDGT_INT), 0,
                        1/*#VTs*/, MVT::f32, 18/*#Ops*/, 3, 4, 0, 5, 6, 7, 1, 8, 9, 10, 2, 11, 12, 13, 14, 15, 16, 17, 
                    // Src: (selectcc:f32 i32:i32:$src0, 0:i32, f32:f32:$src1, f32:f32:$src2, SETGT:Other) - Complexity = 8
                    // Dst: (CNDGT_INT:f32 ?:i32:$src0, ?:f32:$src1, ?:f32:$src2)
/*12078*/         /*Scope*/ 104, /*->12183*/
/*12079*/           OPC_CheckCondCode, ISD::SETGE,
/*12081*/           OPC_MoveParent,
/*12082*/           OPC_CheckType, MVT::f32,
/*12084*/           OPC_CheckPatternPredicate, 3, // (Subtarget.getGeneration() <= AMDGPUSubtarget::NORTHERN_ISLANDS)
/*12086*/           OPC_EmitInteger, MVT::i32, 0, 
/*12089*/           OPC_EmitInteger, MVT::i32, 0, 
/*12092*/           OPC_EmitInteger, MVT::i32, 0, 
/*12095*/           OPC_EmitInteger, MVT::i32, 0, 
/*12098*/           OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*12110*/           OPC_EmitInteger, MVT::i32, 0, 
/*12113*/           OPC_EmitInteger, MVT::i32, 0, 
/*12116*/           OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*12128*/           OPC_EmitInteger, MVT::i32, 0, 
/*12131*/           OPC_EmitInteger, MVT::i32, 0, 
/*12134*/           OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*12146*/           OPC_EmitInteger, MVT::i32, 1, 
/*12149*/           OPC_EmitRegister, MVT::i32, AMDGPU::PRED_SEL_OFF,
/*12152*/           OPC_EmitInteger, MVT::i32, 0, 
/*12155*/           OPC_EmitInteger, MVT::i32, 0, 
/*12158*/           OPC_MorphNodeTo, TARGET_VAL(AMDGPU::CNDGE_INT), 0,
                        1/*#VTs*/, MVT::f32, 18/*#Ops*/, 3, 4, 0, 5, 6, 7, 1, 8, 9, 10, 2, 11, 12, 13, 14, 15, 16, 17, 
                    // Src: (selectcc:f32 i32:i32:$src0, 0:i32, f32:f32:$src1, f32:f32:$src2, SETGE:Other) - Complexity = 8
                    // Dst: (CNDGE_INT:f32 ?:i32:$src0, ?:f32:$src1, ?:f32:$src2)
/*12183*/         0, /*End of Scope*/
/*12184*/       /*Scope*/ 123, /*->12308*/
/*12185*/         OPC_CheckInteger, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*12196*/         OPC_MoveParent,
/*12197*/         OPC_RecordChild2, // #1 = $src1
/*12198*/         OPC_RecordChild3, // #2 = $src2
/*12199*/         OPC_MoveChild, 4,
/*12201*/         OPC_CheckOpcode, TARGET_VAL(ISD::CONDCODE),
/*12204*/         OPC_CheckPredicate, 10, // Predicate_COND_SGT
/*12206*/         OPC_MoveParent,
/*12207*/         OPC_CheckType, MVT::i32,
/*12209*/         OPC_CheckPatternPredicate, 3, // (Subtarget.getGeneration() <= AMDGPUSubtarget::NORTHERN_ISLANDS)
/*12211*/         OPC_EmitInteger, MVT::i32, 0, 
/*12214*/         OPC_EmitInteger, MVT::i32, 0, 
/*12217*/         OPC_EmitInteger, MVT::i32, 0, 
/*12220*/         OPC_EmitInteger, MVT::i32, 0, 
/*12223*/         OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*12235*/         OPC_EmitInteger, MVT::i32, 0, 
/*12238*/         OPC_EmitInteger, MVT::i32, 0, 
/*12241*/         OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*12253*/         OPC_EmitInteger, MVT::i32, 0, 
/*12256*/         OPC_EmitInteger, MVT::i32, 0, 
/*12259*/         OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*12271*/         OPC_EmitInteger, MVT::i32, 1, 
/*12274*/         OPC_EmitRegister, MVT::i32, AMDGPU::PRED_SEL_OFF,
/*12277*/         OPC_EmitInteger, MVT::i32, 0, 
/*12280*/         OPC_EmitInteger, MVT::i32, 0, 
/*12283*/         OPC_MorphNodeTo, TARGET_VAL(AMDGPU::CNDGE_INT), 0,
                      1/*#VTs*/, MVT::i32, 18/*#Ops*/, 3, 4, 0, 5, 6, 7, 1, 8, 9, 10, 2, 11, 12, 13, 14, 15, 16, 17, 
                  // Src: (selectcc:i32 i32:i32:$src0, -1:i32, i32:i32:$src1, i32:i32:$src2, (cond:Other)<<P:Predicate_COND_SGT>>) - Complexity = 8
                  // Dst: (CNDGE_INT:i32 ?:i32:$src0, ?:i32:$src1, ?:i32:$src2)
/*12308*/       0, /*End of Scope*/
/*12309*/     0, /*End of Scope*/
/*12310*/   0, /*End of Scope*/
/*12311*/ /*SwitchOpcode*/ 76|128,21/*2764*/,  TARGET_VAL(ISD::LOAD),// ->15079
/*12315*/   OPC_RecordMemRef,
/*12316*/   OPC_RecordNode,   // #0 = 'ld' chained node
/*12317*/   OPC_Scope, 13|128,2/*269*/, /*->12589*/ // 7 children in Scope
/*12320*/     OPC_RecordChild1, // #1 = $src_gpr
/*12321*/     OPC_CheckChild1Type, MVT::i32,
/*12323*/     OPC_CheckPredicate, 11, // Predicate_unindexedload
/*12325*/     OPC_CheckType, MVT::i32,
/*12327*/     OPC_Scope, 44, /*->12373*/ // 8 children in Scope
/*12329*/       OPC_CheckPredicate, 12, // Predicate_az_extload
/*12331*/       OPC_Scope, 19, /*->12352*/ // 2 children in Scope
/*12333*/         OPC_CheckPredicate, 13, // Predicate_az_extloadi8
/*12335*/         OPC_CheckPredicate, 14, // Predicate_load_param_exti8
/*12337*/         OPC_CheckPatternPredicate, 5, // (Subtarget.getGeneration() >= AMDGPUSubtarget::EVERGREEN && Subtarget.getGeneration() < AMDGPUSubtarget::SOUTHERN_ISLANDS && !Subtarget.hasCaymanISA())
/*12339*/         OPC_CheckComplexPat, /*CP*/3, /*#*/1, // SelectADDRVTX_READ:$src_gpr #2 #3
/*12342*/         OPC_EmitMergeInputChains1_0,
/*12343*/         OPC_MorphNodeTo, TARGET_VAL(AMDGPU::VTX_READ_PARAM_8_eg), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i32, 2/*#Ops*/, 2, 3, 
                  // Src: (ld:i32 ADDRVTX_READ:i32:$src_gpr)<<P:Predicate_unindexedload>><<P:Predicate_az_extload>><<P:Predicate_az_extloadi8>><<P:Predicate_load_param_exti8>> - Complexity = 13
                  // Dst: (VTX_READ_PARAM_8_eg:i32 ADDRVTX_READ:i32:$src_gpr)
/*12352*/       /*Scope*/ 19, /*->12372*/
/*12353*/         OPC_CheckPredicate, 15, // Predicate_az_extloadi16
/*12355*/         OPC_CheckPredicate, 16, // Predicate_load_param_exti16
/*12357*/         OPC_CheckPatternPredicate, 5, // (Subtarget.getGeneration() >= AMDGPUSubtarget::EVERGREEN && Subtarget.getGeneration() < AMDGPUSubtarget::SOUTHERN_ISLANDS && !Subtarget.hasCaymanISA())
/*12359*/         OPC_CheckComplexPat, /*CP*/3, /*#*/1, // SelectADDRVTX_READ:$src_gpr #2 #3
/*12362*/         OPC_EmitMergeInputChains1_0,
/*12363*/         OPC_MorphNodeTo, TARGET_VAL(AMDGPU::VTX_READ_PARAM_16_eg), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i32, 2/*#Ops*/, 2, 3, 
                  // Src: (ld:i32 ADDRVTX_READ:i32:$src_gpr)<<P:Predicate_unindexedload>><<P:Predicate_az_extload>><<P:Predicate_az_extloadi16>><<P:Predicate_load_param_exti16>> - Complexity = 13
                  // Dst: (VTX_READ_PARAM_16_eg:i32 ADDRVTX_READ:i32:$src_gpr)
/*12372*/       0, /*End of Scope*/
/*12373*/     /*Scope*/ 19, /*->12393*/
/*12374*/       OPC_CheckPredicate, 17, // Predicate_load
/*12376*/       OPC_CheckPredicate, 18, // Predicate_load_param
/*12378*/       OPC_CheckPatternPredicate, 5, // (Subtarget.getGeneration() >= AMDGPUSubtarget::EVERGREEN && Subtarget.getGeneration() < AMDGPUSubtarget::SOUTHERN_ISLANDS && !Subtarget.hasCaymanISA())
/*12380*/       OPC_CheckComplexPat, /*CP*/3, /*#*/1, // SelectADDRVTX_READ:$src_gpr #2 #3
/*12383*/       OPC_EmitMergeInputChains1_0,
/*12384*/       OPC_MorphNodeTo, TARGET_VAL(AMDGPU::VTX_READ_PARAM_32_eg), 0|OPFL_Chain|OPFL_MemRefs,
                    1/*#VTs*/, MVT::i32, 2/*#Ops*/, 2, 3, 
                // Src: (ld:i32 ADDRVTX_READ:i32:$src_gpr)<<P:Predicate_unindexedload>><<P:Predicate_load>><<P:Predicate_load_param>> - Complexity = 13
                // Dst: (VTX_READ_PARAM_32_eg:i32 ADDRVTX_READ:i32:$src_gpr)
/*12393*/     /*Scope*/ 44, /*->12438*/
/*12394*/       OPC_CheckPredicate, 12, // Predicate_az_extload
/*12396*/       OPC_Scope, 19, /*->12417*/ // 2 children in Scope
/*12398*/         OPC_CheckPredicate, 13, // Predicate_az_extloadi8
/*12400*/         OPC_CheckPredicate, 19, // Predicate_az_extloadi8_global
/*12402*/         OPC_CheckPatternPredicate, 5, // (Subtarget.getGeneration() >= AMDGPUSubtarget::EVERGREEN && Subtarget.getGeneration() < AMDGPUSubtarget::SOUTHERN_ISLANDS && !Subtarget.hasCaymanISA())
/*12404*/         OPC_CheckComplexPat, /*CP*/3, /*#*/1, // SelectADDRVTX_READ:$src_gpr #2 #3
/*12407*/         OPC_EmitMergeInputChains1_0,
/*12408*/         OPC_MorphNodeTo, TARGET_VAL(AMDGPU::VTX_READ_GLOBAL_8_eg), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i32, 2/*#Ops*/, 2, 3, 
                  // Src: (ld:i32 ADDRVTX_READ:i32:$src_gpr)<<P:Predicate_unindexedload>><<P:Predicate_az_extload>><<P:Predicate_az_extloadi8>><<P:Predicate_az_extloadi8_global>> - Complexity = 13
                  // Dst: (VTX_READ_GLOBAL_8_eg:i32 ADDRVTX_READ:i32:$src_gpr)
/*12417*/       /*Scope*/ 19, /*->12437*/
/*12418*/         OPC_CheckPredicate, 15, // Predicate_az_extloadi16
/*12420*/         OPC_CheckPredicate, 20, // Predicate_az_extloadi16_global
/*12422*/         OPC_CheckPatternPredicate, 5, // (Subtarget.getGeneration() >= AMDGPUSubtarget::EVERGREEN && Subtarget.getGeneration() < AMDGPUSubtarget::SOUTHERN_ISLANDS && !Subtarget.hasCaymanISA())
/*12424*/         OPC_CheckComplexPat, /*CP*/3, /*#*/1, // SelectADDRVTX_READ:$src_gpr #2 #3
/*12427*/         OPC_EmitMergeInputChains1_0,
/*12428*/         OPC_MorphNodeTo, TARGET_VAL(AMDGPU::VTX_READ_GLOBAL_16_eg), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i32, 2/*#Ops*/, 2, 3, 
                  // Src: (ld:i32 ADDRVTX_READ:i32:$src_gpr)<<P:Predicate_unindexedload>><<P:Predicate_az_extload>><<P:Predicate_az_extloadi16>><<P:Predicate_az_extloadi16_global>> - Complexity = 13
                  // Dst: (VTX_READ_GLOBAL_16_eg:i32 ADDRVTX_READ:i32:$src_gpr)
/*12437*/       0, /*End of Scope*/
/*12438*/     /*Scope*/ 19, /*->12458*/
/*12439*/       OPC_CheckPredicate, 17, // Predicate_load
/*12441*/       OPC_CheckPredicate, 21, // Predicate_global_load
/*12443*/       OPC_CheckPatternPredicate, 5, // (Subtarget.getGeneration() >= AMDGPUSubtarget::EVERGREEN && Subtarget.getGeneration() < AMDGPUSubtarget::SOUTHERN_ISLANDS && !Subtarget.hasCaymanISA())
/*12445*/       OPC_CheckComplexPat, /*CP*/3, /*#*/1, // SelectADDRVTX_READ:$src_gpr #2 #3
/*12448*/       OPC_EmitMergeInputChains1_0,
/*12449*/       OPC_MorphNodeTo, TARGET_VAL(AMDGPU::VTX_READ_GLOBAL_32_eg), 0|OPFL_Chain|OPFL_MemRefs,
                    1/*#VTs*/, MVT::i32, 2/*#Ops*/, 2, 3, 
                // Src: (ld:i32 ADDRVTX_READ:i32:$src_gpr)<<P:Predicate_unindexedload>><<P:Predicate_load>><<P:Predicate_global_load>> - Complexity = 13
                // Dst: (VTX_READ_GLOBAL_32_eg:i32 ADDRVTX_READ:i32:$src_gpr)
/*12458*/     /*Scope*/ 44, /*->12503*/
/*12459*/       OPC_CheckPredicate, 12, // Predicate_az_extload
/*12461*/       OPC_Scope, 19, /*->12482*/ // 2 children in Scope
/*12463*/         OPC_CheckPredicate, 13, // Predicate_az_extloadi8
/*12465*/         OPC_CheckPredicate, 14, // Predicate_load_param_exti8
/*12467*/         OPC_CheckPatternPredicate, 4, // (Subtarget.hasCaymanISA())
/*12469*/         OPC_CheckComplexPat, /*CP*/3, /*#*/1, // SelectADDRVTX_READ:$src_gpr #2 #3
/*12472*/         OPC_EmitMergeInputChains1_0,
/*12473*/         OPC_MorphNodeTo, TARGET_VAL(AMDGPU::VTX_READ_PARAM_8_cm), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i32, 2/*#Ops*/, 2, 3, 
                  // Src: (ld:i32 ADDRVTX_READ:i32:$src_gpr)<<P:Predicate_unindexedload>><<P:Predicate_az_extload>><<P:Predicate_az_extloadi8>><<P:Predicate_load_param_exti8>> - Complexity = 13
                  // Dst: (VTX_READ_PARAM_8_cm:i32 ADDRVTX_READ:i32:$src_gpr)
/*12482*/       /*Scope*/ 19, /*->12502*/
/*12483*/         OPC_CheckPredicate, 15, // Predicate_az_extloadi16
/*12485*/         OPC_CheckPredicate, 16, // Predicate_load_param_exti16
/*12487*/         OPC_CheckPatternPredicate, 4, // (Subtarget.hasCaymanISA())
/*12489*/         OPC_CheckComplexPat, /*CP*/3, /*#*/1, // SelectADDRVTX_READ:$src_gpr #2 #3
/*12492*/         OPC_EmitMergeInputChains1_0,
/*12493*/         OPC_MorphNodeTo, TARGET_VAL(AMDGPU::VTX_READ_PARAM_16_cm), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i32, 2/*#Ops*/, 2, 3, 
                  // Src: (ld:i32 ADDRVTX_READ:i32:$src_gpr)<<P:Predicate_unindexedload>><<P:Predicate_az_extload>><<P:Predicate_az_extloadi16>><<P:Predicate_load_param_exti16>> - Complexity = 13
                  // Dst: (VTX_READ_PARAM_16_cm:i32 ADDRVTX_READ:i32:$src_gpr)
/*12502*/       0, /*End of Scope*/
/*12503*/     /*Scope*/ 19, /*->12523*/
/*12504*/       OPC_CheckPredicate, 17, // Predicate_load
/*12506*/       OPC_CheckPredicate, 18, // Predicate_load_param
/*12508*/       OPC_CheckPatternPredicate, 4, // (Subtarget.hasCaymanISA())
/*12510*/       OPC_CheckComplexPat, /*CP*/3, /*#*/1, // SelectADDRVTX_READ:$src_gpr #2 #3
/*12513*/       OPC_EmitMergeInputChains1_0,
/*12514*/       OPC_MorphNodeTo, TARGET_VAL(AMDGPU::VTX_READ_PARAM_32_cm), 0|OPFL_Chain|OPFL_MemRefs,
                    1/*#VTs*/, MVT::i32, 2/*#Ops*/, 2, 3, 
                // Src: (ld:i32 ADDRVTX_READ:i32:$src_gpr)<<P:Predicate_unindexedload>><<P:Predicate_load>><<P:Predicate_load_param>> - Complexity = 13
                // Dst: (VTX_READ_PARAM_32_cm:i32 ADDRVTX_READ:i32:$src_gpr)
/*12523*/     /*Scope*/ 44, /*->12568*/
/*12524*/       OPC_CheckPredicate, 12, // Predicate_az_extload
/*12526*/       OPC_Scope, 19, /*->12547*/ // 2 children in Scope
/*12528*/         OPC_CheckPredicate, 13, // Predicate_az_extloadi8
/*12530*/         OPC_CheckPredicate, 19, // Predicate_az_extloadi8_global
/*12532*/         OPC_CheckPatternPredicate, 4, // (Subtarget.hasCaymanISA())
/*12534*/         OPC_CheckComplexPat, /*CP*/3, /*#*/1, // SelectADDRVTX_READ:$src_gpr #2 #3
/*12537*/         OPC_EmitMergeInputChains1_0,
/*12538*/         OPC_MorphNodeTo, TARGET_VAL(AMDGPU::VTX_READ_GLOBAL_8_cm), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i32, 2/*#Ops*/, 2, 3, 
                  // Src: (ld:i32 ADDRVTX_READ:i32:$src_gpr)<<P:Predicate_unindexedload>><<P:Predicate_az_extload>><<P:Predicate_az_extloadi8>><<P:Predicate_az_extloadi8_global>> - Complexity = 13
                  // Dst: (VTX_READ_GLOBAL_8_cm:i32 ADDRVTX_READ:i32:$src_gpr)
/*12547*/       /*Scope*/ 19, /*->12567*/
/*12548*/         OPC_CheckPredicate, 15, // Predicate_az_extloadi16
/*12550*/         OPC_CheckPredicate, 20, // Predicate_az_extloadi16_global
/*12552*/         OPC_CheckPatternPredicate, 4, // (Subtarget.hasCaymanISA())
/*12554*/         OPC_CheckComplexPat, /*CP*/3, /*#*/1, // SelectADDRVTX_READ:$src_gpr #2 #3
/*12557*/         OPC_EmitMergeInputChains1_0,
/*12558*/         OPC_MorphNodeTo, TARGET_VAL(AMDGPU::VTX_READ_GLOBAL_16_cm), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i32, 2/*#Ops*/, 2, 3, 
                  // Src: (ld:i32 ADDRVTX_READ:i32:$src_gpr)<<P:Predicate_unindexedload>><<P:Predicate_az_extload>><<P:Predicate_az_extloadi16>><<P:Predicate_az_extloadi16_global>> - Complexity = 13
                  // Dst: (VTX_READ_GLOBAL_16_cm:i32 ADDRVTX_READ:i32:$src_gpr)
/*12567*/       0, /*End of Scope*/
/*12568*/     /*Scope*/ 19, /*->12588*/
/*12569*/       OPC_CheckPredicate, 17, // Predicate_load
/*12571*/       OPC_CheckPredicate, 21, // Predicate_global_load
/*12573*/       OPC_CheckPatternPredicate, 4, // (Subtarget.hasCaymanISA())
/*12575*/       OPC_CheckComplexPat, /*CP*/3, /*#*/1, // SelectADDRVTX_READ:$src_gpr #2 #3
/*12578*/       OPC_EmitMergeInputChains1_0,
/*12579*/       OPC_MorphNodeTo, TARGET_VAL(AMDGPU::VTX_READ_GLOBAL_32_cm), 0|OPFL_Chain|OPFL_MemRefs,
                    1/*#VTs*/, MVT::i32, 2/*#Ops*/, 2, 3, 
                // Src: (ld:i32 ADDRVTX_READ:i32:$src_gpr)<<P:Predicate_unindexedload>><<P:Predicate_load>><<P:Predicate_global_load>> - Complexity = 13
                // Dst: (VTX_READ_GLOBAL_32_cm:i32 ADDRVTX_READ:i32:$src_gpr)
/*12588*/     0, /*End of Scope*/
/*12589*/   /*Scope*/ 105|128,6/*873*/, /*->13464*/
/*12591*/     OPC_MoveChild, 1,
/*12593*/     OPC_CheckOpcode, TARGET_VAL(ISD::ADD),
/*12596*/     OPC_RecordChild0, // #1 = $sbase
/*12597*/     OPC_RecordChild1, // #2 = $offset
/*12598*/     OPC_Scope, 33|128,3/*417*/, /*->13018*/ // 2 children in Scope
/*12601*/       OPC_MoveChild, 1,
/*12603*/       OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*12606*/       OPC_Scope, 69, /*->12677*/ // 3 children in Scope
/*12608*/         OPC_CheckPredicate, 22, // Predicate_IMM8bitDWORD
/*12610*/         OPC_MoveParent,
/*12611*/         OPC_MoveParent,
/*12612*/         OPC_CheckPredicate, 11, // Predicate_unindexedload
/*12614*/         OPC_CheckPredicate, 17, // Predicate_load
/*12616*/         OPC_CheckPredicate, 23, // Predicate_constant_load
/*12618*/         OPC_SwitchType /*3 cases */, 17,  MVT::i32,// ->12638
/*12621*/           OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*12623*/           OPC_EmitMergeInputChains1_0,
/*12624*/           OPC_EmitConvertToTarget, 2,
/*12626*/           OPC_EmitNodeXForm, 3, 3, // anonymous.val.459
/*12629*/           OPC_MorphNodeTo, TARGET_VAL(AMDGPU::S_LOAD_DWORD_IMM), 0|OPFL_Chain|OPFL_MemRefs,
                        1/*#VTs*/, MVT::i32, 2/*#Ops*/, 1, 4, 
                    // Src: (ld:i32 (SIadd64bit32bit:i64 i64:i64:$sbase, (imm:i32)<<P:Predicate_IMM8bitDWORD>><<X:anonymous.val.459>>:$offset))<<P:Predicate_unindexedload>><<P:Predicate_load>><<P:Predicate_constant_load>> - Complexity = 11
                    // Dst: (S_LOAD_DWORD_IMM:i32 ?:i64:$sbase, (anonymous.val.459:i32 (imm:i32)<<P:Predicate_IMM8bitDWORD>>:$offset))
/*12638*/         /*SwitchType*/ 17,  MVT::i64,// ->12657
/*12640*/           OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*12642*/           OPC_EmitMergeInputChains1_0,
/*12643*/           OPC_EmitConvertToTarget, 2,
/*12645*/           OPC_EmitNodeXForm, 3, 3, // anonymous.val.459
/*12648*/           OPC_MorphNodeTo, TARGET_VAL(AMDGPU::S_LOAD_DWORDX2_IMM), 0|OPFL_Chain|OPFL_MemRefs,
                        1/*#VTs*/, MVT::i64, 2/*#Ops*/, 1, 4, 
                    // Src: (ld:i64 (SIadd64bit32bit:i64 i64:i64:$sbase, (imm:i32)<<P:Predicate_IMM8bitDWORD>><<X:anonymous.val.459>>:$offset))<<P:Predicate_unindexedload>><<P:Predicate_load>><<P:Predicate_constant_load>> - Complexity = 11
                    // Dst: (S_LOAD_DWORDX2_IMM:i64 ?:i64:$sbase, (anonymous.val.459:i32 (imm:i32)<<P:Predicate_IMM8bitDWORD>>:$offset))
/*12657*/         /*SwitchType*/ 17,  MVT::i128,// ->12676
/*12659*/           OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*12661*/           OPC_EmitMergeInputChains1_0,
/*12662*/           OPC_EmitConvertToTarget, 2,
/*12664*/           OPC_EmitNodeXForm, 3, 3, // anonymous.val.459
/*12667*/           OPC_MorphNodeTo, TARGET_VAL(AMDGPU::S_LOAD_DWORDX4_IMM), 0|OPFL_Chain|OPFL_MemRefs,
                        1/*#VTs*/, MVT::i128, 2/*#Ops*/, 1, 4, 
                    // Src: (ld:i128 (SIadd64bit32bit:i64 i64:i64:$sbase, (imm:i32)<<P:Predicate_IMM8bitDWORD>><<X:anonymous.val.459>>:$offset))<<P:Predicate_unindexedload>><<P:Predicate_load>><<P:Predicate_constant_load>> - Complexity = 11
                    // Dst: (S_LOAD_DWORDX4_IMM:i128 ?:i64:$sbase, (anonymous.val.459:i32 (imm:i32)<<P:Predicate_IMM8bitDWORD>>:$offset))
/*12676*/         0, // EndSwitchType
/*12677*/       /*Scope*/ 127|128,1/*255*/, /*->12934*/
/*12679*/         OPC_CheckPredicate, 24, // Predicate_IMM12bit
/*12681*/         OPC_MoveParent,
/*12682*/         OPC_CheckType, MVT::i64,
/*12684*/         OPC_MoveParent,
/*12685*/         OPC_CheckPredicate, 11, // Predicate_unindexedload
/*12687*/         OPC_Scope, 35, /*->12724*/ // 6 children in Scope
/*12689*/           OPC_CheckPredicate, 25, // Predicate_sextload
/*12691*/           OPC_CheckPredicate, 26, // Predicate_sextloadi8
/*12693*/           OPC_CheckPredicate, 27, // Predicate_sextloadi8_global
/*12695*/           OPC_CheckType, MVT::i32,
/*12697*/           OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*12699*/           OPC_EmitMergeInputChains1_0,
/*12700*/           OPC_EmitInteger, MVT::i64, 0, 
/*12703*/           OPC_EmitNode, TARGET_VAL(AMDGPU::SI_ADDR64_RSRC), 0|OPFL_Chain,
                        1/*#VTs*/, MVT::i128, 1/*#Ops*/, 3,  // Results = #4
/*12711*/           OPC_EmitNodeXForm, 0, 2, // as_i16imm
/*12714*/           OPC_MorphNodeTo, TARGET_VAL(AMDGPU::BUFFER_LOAD_SBYTE_ADDR64), 0|OPFL_Chain|OPFL_MemRefs,
                        1/*#VTs*/, MVT::i32, 3/*#Ops*/, 4, 1, 5, 
                    // Src: (ld:i32 (add:i64 i64:i64:$ptr, (imm:i64)<<P:Predicate_IMM12bit>>:$offset))<<P:Predicate_unindexedload>><<P:Predicate_sextload>><<P:Predicate_sextloadi8>><<P:Predicate_sextloadi8_global>> - Complexity = 11
                    // Dst: (BUFFER_LOAD_SBYTE_ADDR64:i32 (SI_ADDR64_RSRC:i128 0:i64), ?:i64:$ptr, (as_i16imm:i16 ?:i64:$offset))
/*12724*/         /*Scope*/ 35, /*->12760*/
/*12725*/           OPC_CheckPredicate, 12, // Predicate_az_extload
/*12727*/           OPC_CheckPredicate, 13, // Predicate_az_extloadi8
/*12729*/           OPC_CheckPredicate, 19, // Predicate_az_extloadi8_global
/*12731*/           OPC_CheckType, MVT::i32,
/*12733*/           OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*12735*/           OPC_EmitMergeInputChains1_0,
/*12736*/           OPC_EmitInteger, MVT::i64, 0, 
/*12739*/           OPC_EmitNode, TARGET_VAL(AMDGPU::SI_ADDR64_RSRC), 0|OPFL_Chain,
                        1/*#VTs*/, MVT::i128, 1/*#Ops*/, 3,  // Results = #4
/*12747*/           OPC_EmitNodeXForm, 0, 2, // as_i16imm
/*12750*/           OPC_MorphNodeTo, TARGET_VAL(AMDGPU::BUFFER_LOAD_UBYTE_ADDR64), 0|OPFL_Chain|OPFL_MemRefs,
                        1/*#VTs*/, MVT::i32, 3/*#Ops*/, 4, 1, 5, 
                    // Src: (ld:i32 (add:i64 i64:i64:$ptr, (imm:i64)<<P:Predicate_IMM12bit>>:$offset))<<P:Predicate_unindexedload>><<P:Predicate_az_extload>><<P:Predicate_az_extloadi8>><<P:Predicate_az_extloadi8_global>> - Complexity = 11
                    // Dst: (BUFFER_LOAD_UBYTE_ADDR64:i32 (SI_ADDR64_RSRC:i128 0:i64), ?:i64:$ptr, (as_i16imm:i16 ?:i64:$offset))
/*12760*/         /*Scope*/ 35, /*->12796*/
/*12761*/           OPC_CheckPredicate, 25, // Predicate_sextload
/*12763*/           OPC_CheckPredicate, 28, // Predicate_sextloadi16
/*12765*/           OPC_CheckPredicate, 29, // Predicate_sextloadi16_global
/*12767*/           OPC_CheckType, MVT::i32,
/*12769*/           OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*12771*/           OPC_EmitMergeInputChains1_0,
/*12772*/           OPC_EmitInteger, MVT::i64, 0, 
/*12775*/           OPC_EmitNode, TARGET_VAL(AMDGPU::SI_ADDR64_RSRC), 0|OPFL_Chain,
                        1/*#VTs*/, MVT::i128, 1/*#Ops*/, 3,  // Results = #4
/*12783*/           OPC_EmitNodeXForm, 0, 2, // as_i16imm
/*12786*/           OPC_MorphNodeTo, TARGET_VAL(AMDGPU::BUFFER_LOAD_SSHORT_ADDR64), 0|OPFL_Chain|OPFL_MemRefs,
                        1/*#VTs*/, MVT::i32, 3/*#Ops*/, 4, 1, 5, 
                    // Src: (ld:i32 (add:i64 i64:i64:$ptr, (imm:i64)<<P:Predicate_IMM12bit>>:$offset))<<P:Predicate_unindexedload>><<P:Predicate_sextload>><<P:Predicate_sextloadi16>><<P:Predicate_sextloadi16_global>> - Complexity = 11
                    // Dst: (BUFFER_LOAD_SSHORT_ADDR64:i32 (SI_ADDR64_RSRC:i128 0:i64), ?:i64:$ptr, (as_i16imm:i16 ?:i64:$offset))
/*12796*/         /*Scope*/ 35, /*->12832*/
/*12797*/           OPC_CheckPredicate, 12, // Predicate_az_extload
/*12799*/           OPC_CheckPredicate, 15, // Predicate_az_extloadi16
/*12801*/           OPC_CheckPredicate, 20, // Predicate_az_extloadi16_global
/*12803*/           OPC_CheckType, MVT::i32,
/*12805*/           OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*12807*/           OPC_EmitMergeInputChains1_0,
/*12808*/           OPC_EmitInteger, MVT::i64, 0, 
/*12811*/           OPC_EmitNode, TARGET_VAL(AMDGPU::SI_ADDR64_RSRC), 0|OPFL_Chain,
                        1/*#VTs*/, MVT::i128, 1/*#Ops*/, 3,  // Results = #4
/*12819*/           OPC_EmitNodeXForm, 0, 2, // as_i16imm
/*12822*/           OPC_MorphNodeTo, TARGET_VAL(AMDGPU::BUFFER_LOAD_USHORT_ADDR64), 0|OPFL_Chain|OPFL_MemRefs,
                        1/*#VTs*/, MVT::i32, 3/*#Ops*/, 4, 1, 5, 
                    // Src: (ld:i32 (add:i64 i64:i64:$ptr, (imm:i64)<<P:Predicate_IMM12bit>>:$offset))<<P:Predicate_unindexedload>><<P:Predicate_az_extload>><<P:Predicate_az_extloadi16>><<P:Predicate_az_extloadi16_global>> - Complexity = 11
                    // Dst: (BUFFER_LOAD_USHORT_ADDR64:i32 (SI_ADDR64_RSRC:i128 0:i64), ?:i64:$ptr, (as_i16imm:i16 ?:i64:$offset))
/*12832*/         /*Scope*/ 64, /*->12897*/
/*12833*/           OPC_CheckPredicate, 17, // Predicate_load
/*12835*/           OPC_CheckPredicate, 21, // Predicate_global_load
/*12837*/           OPC_SwitchType /*2 cases */, 27,  MVT::i32,// ->12867
/*12840*/             OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*12842*/             OPC_EmitMergeInputChains1_0,
/*12843*/             OPC_EmitInteger, MVT::i64, 0, 
/*12846*/             OPC_EmitNode, TARGET_VAL(AMDGPU::SI_ADDR64_RSRC), 0|OPFL_Chain,
                          1/*#VTs*/, MVT::i128, 1/*#Ops*/, 3,  // Results = #4
/*12854*/             OPC_EmitNodeXForm, 0, 2, // as_i16imm
/*12857*/             OPC_MorphNodeTo, TARGET_VAL(AMDGPU::BUFFER_LOAD_DWORD_ADDR64), 0|OPFL_Chain|OPFL_MemRefs,
                          1/*#VTs*/, MVT::i32, 3/*#Ops*/, 4, 1, 5, 
                      // Src: (ld:i32 (add:i64 i64:i64:$ptr, (imm:i64)<<P:Predicate_IMM12bit>>:$offset))<<P:Predicate_unindexedload>><<P:Predicate_load>><<P:Predicate_global_load>> - Complexity = 11
                      // Dst: (BUFFER_LOAD_DWORD_ADDR64:i32 (SI_ADDR64_RSRC:i128 0:i64), ?:i64:$ptr, (as_i16imm:i16 ?:i64:$offset))
/*12867*/           /*SwitchType*/ 27,  MVT::i64,// ->12896
/*12869*/             OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*12871*/             OPC_EmitMergeInputChains1_0,
/*12872*/             OPC_EmitInteger, MVT::i64, 0, 
/*12875*/             OPC_EmitNode, TARGET_VAL(AMDGPU::SI_ADDR64_RSRC), 0|OPFL_Chain,
                          1/*#VTs*/, MVT::i128, 1/*#Ops*/, 3,  // Results = #4
/*12883*/             OPC_EmitNodeXForm, 0, 2, // as_i16imm
/*12886*/             OPC_MorphNodeTo, TARGET_VAL(AMDGPU::BUFFER_LOAD_DWORDX2_ADDR64), 0|OPFL_Chain|OPFL_MemRefs,
                          1/*#VTs*/, MVT::i64, 3/*#Ops*/, 4, 1, 5, 
                      // Src: (ld:i64 (add:i64 i64:i64:$ptr, (imm:i64)<<P:Predicate_IMM12bit>>:$offset))<<P:Predicate_unindexedload>><<P:Predicate_load>><<P:Predicate_global_load>> - Complexity = 11
                      // Dst: (BUFFER_LOAD_DWORDX2_ADDR64:i64 (SI_ADDR64_RSRC:i128 0:i64), ?:i64:$ptr, (as_i16imm:i16 ?:i64:$offset))
/*12896*/           0, // EndSwitchType
/*12897*/         /*Scope*/ 35, /*->12933*/
/*12898*/           OPC_CheckPredicate, 12, // Predicate_az_extload
/*12900*/           OPC_CheckPredicate, 30, // Predicate_az_extloadi32
/*12902*/           OPC_CheckPredicate, 31, // Predicate_az_extloadi32_global
/*12904*/           OPC_CheckType, MVT::i64,
/*12906*/           OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*12908*/           OPC_EmitMergeInputChains1_0,
/*12909*/           OPC_EmitInteger, MVT::i64, 0, 
/*12912*/           OPC_EmitNode, TARGET_VAL(AMDGPU::SI_ADDR64_RSRC), 0|OPFL_Chain,
                        1/*#VTs*/, MVT::i128, 1/*#Ops*/, 3,  // Results = #4
/*12920*/           OPC_EmitNodeXForm, 0, 2, // as_i16imm
/*12923*/           OPC_MorphNodeTo, TARGET_VAL(AMDGPU::BUFFER_LOAD_DWORDX2_ADDR64), 0|OPFL_Chain|OPFL_MemRefs,
                        1/*#VTs*/, MVT::i64, 3/*#Ops*/, 4, 1, 5, 
                    // Src: (ld:i64 (add:i64 i64:i64:$ptr, (imm:i64)<<P:Predicate_IMM12bit>>:$offset))<<P:Predicate_unindexedload>><<P:Predicate_az_extload>><<P:Predicate_az_extloadi32>><<P:Predicate_az_extloadi32_global>> - Complexity = 11
                    // Dst: (BUFFER_LOAD_DWORDX2_ADDR64:i64 (SI_ADDR64_RSRC:i128 0:i64), ?:i64:$ptr, (as_i16imm:i16 ?:i64:$offset))
/*12933*/         0, /*End of Scope*/
/*12934*/       /*Scope*/ 82, /*->13017*/
/*12935*/         OPC_MoveParent,
/*12936*/         OPC_MoveParent,
/*12937*/         OPC_CheckPredicate, 11, // Predicate_unindexedload
/*12939*/         OPC_CheckPredicate, 17, // Predicate_load
/*12941*/         OPC_CheckPredicate, 23, // Predicate_constant_load
/*12943*/         OPC_SwitchType /*3 cases */, 22,  MVT::i32,// ->12968
/*12946*/           OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*12948*/           OPC_EmitMergeInputChains1_0,
/*12949*/           OPC_EmitConvertToTarget, 2,
/*12951*/           OPC_EmitNode, TARGET_VAL(AMDGPU::S_MOV_B32), 0,
                        1/*#VTs*/, MVT::i32, 1/*#Ops*/, 3,  // Results = #4
/*12959*/           OPC_MorphNodeTo, TARGET_VAL(AMDGPU::S_LOAD_DWORD_SGPR), 0|OPFL_Chain|OPFL_MemRefs,
                        1/*#VTs*/, MVT::i32, 2/*#Ops*/, 1, 4, 
                    // Src: (ld:i32 (SIadd64bit32bit:i64 i64:i64:$sbase, (imm:i32):$offset))<<P:Predicate_unindexedload>><<P:Predicate_load>><<P:Predicate_constant_load>> - Complexity = 10
                    // Dst: (S_LOAD_DWORD_SGPR:i32 ?:i64:$sbase, (S_MOV_B32:i32 (imm:i32):$offset))
/*12968*/         /*SwitchType*/ 22,  MVT::i64,// ->12992
/*12970*/           OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*12972*/           OPC_EmitMergeInputChains1_0,
/*12973*/           OPC_EmitConvertToTarget, 2,
/*12975*/           OPC_EmitNode, TARGET_VAL(AMDGPU::S_MOV_B32), 0,
                        1/*#VTs*/, MVT::i32, 1/*#Ops*/, 3,  // Results = #4
/*12983*/           OPC_MorphNodeTo, TARGET_VAL(AMDGPU::S_LOAD_DWORDX2_SGPR), 0|OPFL_Chain|OPFL_MemRefs,
                        1/*#VTs*/, MVT::i64, 2/*#Ops*/, 1, 4, 
                    // Src: (ld:i64 (SIadd64bit32bit:i64 i64:i64:$sbase, (imm:i32):$offset))<<P:Predicate_unindexedload>><<P:Predicate_load>><<P:Predicate_constant_load>> - Complexity = 10
                    // Dst: (S_LOAD_DWORDX2_SGPR:i64 ?:i64:$sbase, (S_MOV_B32:i32 (imm:i32):$offset))
/*12992*/         /*SwitchType*/ 22,  MVT::i128,// ->13016
/*12994*/           OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*12996*/           OPC_EmitMergeInputChains1_0,
/*12997*/           OPC_EmitConvertToTarget, 2,
/*12999*/           OPC_EmitNode, TARGET_VAL(AMDGPU::S_MOV_B32), 0,
                        1/*#VTs*/, MVT::i32, 1/*#Ops*/, 3,  // Results = #4
/*13007*/           OPC_MorphNodeTo, TARGET_VAL(AMDGPU::S_LOAD_DWORDX4_SGPR), 0|OPFL_Chain|OPFL_MemRefs,
                        1/*#VTs*/, MVT::i128, 2/*#Ops*/, 1, 4, 
                    // Src: (ld:i128 (SIadd64bit32bit:i64 i64:i64:$sbase, (imm:i32):$offset))<<P:Predicate_unindexedload>><<P:Predicate_load>><<P:Predicate_constant_load>> - Complexity = 10
                    // Dst: (S_LOAD_DWORDX4_SGPR:i128 ?:i64:$sbase, (S_MOV_B32:i32 (imm:i32):$offset))
/*13016*/         0, // EndSwitchType
/*13017*/       0, /*End of Scope*/
/*13018*/     /*Scope*/ 59|128,3/*443*/, /*->13463*/
/*13020*/       OPC_CheckType, MVT::i64,
/*13022*/       OPC_MoveParent,
/*13023*/       OPC_CheckPredicate, 11, // Predicate_unindexedload
/*13025*/       OPC_Scope, 62, /*->13089*/ // 6 children in Scope
/*13027*/         OPC_CheckPredicate, 25, // Predicate_sextload
/*13029*/         OPC_CheckPredicate, 26, // Predicate_sextloadi8
/*13031*/         OPC_CheckType, MVT::i32,
/*13033*/         OPC_Scope, 26, /*->13061*/ // 2 children in Scope
/*13035*/           OPC_CheckPredicate, 27, // Predicate_sextloadi8_global
/*13037*/           OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*13039*/           OPC_EmitMergeInputChains1_0,
/*13040*/           OPC_EmitNode, TARGET_VAL(AMDGPU::SI_ADDR64_RSRC), 0|OPFL_Chain,
                        1/*#VTs*/, MVT::i128, 1/*#Ops*/, 1,  // Results = #3
/*13048*/           OPC_EmitInteger, MVT::i16, 0, 
/*13051*/           OPC_MorphNodeTo, TARGET_VAL(AMDGPU::BUFFER_LOAD_SBYTE_ADDR64), 0|OPFL_Chain|OPFL_MemRefs,
                        1/*#VTs*/, MVT::i32, 3/*#Ops*/, 3, 2, 4, 
                    // Src: (ld:i32 (add:i64 i64:i64:$ptr, i64:i64:$offset))<<P:Predicate_unindexedload>><<P:Predicate_sextload>><<P:Predicate_sextloadi8>><<P:Predicate_sextloadi8_global>> - Complexity = 7
                    // Dst: (BUFFER_LOAD_SBYTE_ADDR64:i32 (SI_ADDR64_RSRC:i128 ?:i64:$ptr), ?:i64:$offset, 0:i16)
/*13061*/         /*Scope*/ 26, /*->13088*/
/*13062*/           OPC_CheckPredicate, 32, // Predicate_sextloadi8_constant
/*13064*/           OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*13066*/           OPC_EmitMergeInputChains1_0,
/*13067*/           OPC_EmitNode, TARGET_VAL(AMDGPU::SI_ADDR64_RSRC), 0|OPFL_Chain,
                        1/*#VTs*/, MVT::i128, 1/*#Ops*/, 1,  // Results = #3
/*13075*/           OPC_EmitInteger, MVT::i16, 0, 
/*13078*/           OPC_MorphNodeTo, TARGET_VAL(AMDGPU::BUFFER_LOAD_SBYTE_ADDR64), 0|OPFL_Chain|OPFL_MemRefs,
                        1/*#VTs*/, MVT::i32, 3/*#Ops*/, 3, 2, 4, 
                    // Src: (ld:i32 (add:i64 i64:i64:$ptr, i64:i64:$offset))<<P:Predicate_unindexedload>><<P:Predicate_sextload>><<P:Predicate_sextloadi8>><<P:Predicate_sextloadi8_constant>> - Complexity = 7
                    // Dst: (BUFFER_LOAD_SBYTE_ADDR64:i32 (SI_ADDR64_RSRC:i128 ?:i64:$ptr), ?:i64:$offset, 0:i16)
/*13088*/         0, /*End of Scope*/
/*13089*/       /*Scope*/ 62, /*->13152*/
/*13090*/         OPC_CheckPredicate, 12, // Predicate_az_extload
/*13092*/         OPC_CheckPredicate, 13, // Predicate_az_extloadi8
/*13094*/         OPC_CheckType, MVT::i32,
/*13096*/         OPC_Scope, 26, /*->13124*/ // 2 children in Scope
/*13098*/           OPC_CheckPredicate, 19, // Predicate_az_extloadi8_global
/*13100*/           OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*13102*/           OPC_EmitMergeInputChains1_0,
/*13103*/           OPC_EmitNode, TARGET_VAL(AMDGPU::SI_ADDR64_RSRC), 0|OPFL_Chain,
                        1/*#VTs*/, MVT::i128, 1/*#Ops*/, 1,  // Results = #3
/*13111*/           OPC_EmitInteger, MVT::i16, 0, 
/*13114*/           OPC_MorphNodeTo, TARGET_VAL(AMDGPU::BUFFER_LOAD_UBYTE_ADDR64), 0|OPFL_Chain|OPFL_MemRefs,
                        1/*#VTs*/, MVT::i32, 3/*#Ops*/, 3, 2, 4, 
                    // Src: (ld:i32 (add:i64 i64:i64:$ptr, i64:i64:$offset))<<P:Predicate_unindexedload>><<P:Predicate_az_extload>><<P:Predicate_az_extloadi8>><<P:Predicate_az_extloadi8_global>> - Complexity = 7
                    // Dst: (BUFFER_LOAD_UBYTE_ADDR64:i32 (SI_ADDR64_RSRC:i128 ?:i64:$ptr), ?:i64:$offset, 0:i16)
/*13124*/         /*Scope*/ 26, /*->13151*/
/*13125*/           OPC_CheckPredicate, 33, // Predicate_az_extloadi8_constant
/*13127*/           OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*13129*/           OPC_EmitMergeInputChains1_0,
/*13130*/           OPC_EmitNode, TARGET_VAL(AMDGPU::SI_ADDR64_RSRC), 0|OPFL_Chain,
                        1/*#VTs*/, MVT::i128, 1/*#Ops*/, 1,  // Results = #3
/*13138*/           OPC_EmitInteger, MVT::i16, 0, 
/*13141*/           OPC_MorphNodeTo, TARGET_VAL(AMDGPU::BUFFER_LOAD_UBYTE_ADDR64), 0|OPFL_Chain|OPFL_MemRefs,
                        1/*#VTs*/, MVT::i32, 3/*#Ops*/, 3, 2, 4, 
                    // Src: (ld:i32 (add:i64 i64:i64:$ptr, i64:i64:$offset))<<P:Predicate_unindexedload>><<P:Predicate_az_extload>><<P:Predicate_az_extloadi8>><<P:Predicate_az_extloadi8_constant>> - Complexity = 7
                    // Dst: (BUFFER_LOAD_UBYTE_ADDR64:i32 (SI_ADDR64_RSRC:i128 ?:i64:$ptr), ?:i64:$offset, 0:i16)
/*13151*/         0, /*End of Scope*/
/*13152*/       /*Scope*/ 62, /*->13215*/
/*13153*/         OPC_CheckPredicate, 25, // Predicate_sextload
/*13155*/         OPC_CheckPredicate, 28, // Predicate_sextloadi16
/*13157*/         OPC_CheckType, MVT::i32,
/*13159*/         OPC_Scope, 26, /*->13187*/ // 2 children in Scope
/*13161*/           OPC_CheckPredicate, 29, // Predicate_sextloadi16_global
/*13163*/           OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*13165*/           OPC_EmitMergeInputChains1_0,
/*13166*/           OPC_EmitNode, TARGET_VAL(AMDGPU::SI_ADDR64_RSRC), 0|OPFL_Chain,
                        1/*#VTs*/, MVT::i128, 1/*#Ops*/, 1,  // Results = #3
/*13174*/           OPC_EmitInteger, MVT::i16, 0, 
/*13177*/           OPC_MorphNodeTo, TARGET_VAL(AMDGPU::BUFFER_LOAD_SSHORT_ADDR64), 0|OPFL_Chain|OPFL_MemRefs,
                        1/*#VTs*/, MVT::i32, 3/*#Ops*/, 3, 2, 4, 
                    // Src: (ld:i32 (add:i64 i64:i64:$ptr, i64:i64:$offset))<<P:Predicate_unindexedload>><<P:Predicate_sextload>><<P:Predicate_sextloadi16>><<P:Predicate_sextloadi16_global>> - Complexity = 7
                    // Dst: (BUFFER_LOAD_SSHORT_ADDR64:i32 (SI_ADDR64_RSRC:i128 ?:i64:$ptr), ?:i64:$offset, 0:i16)
/*13187*/         /*Scope*/ 26, /*->13214*/
/*13188*/           OPC_CheckPredicate, 34, // Predicate_sextloadi16_constant
/*13190*/           OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*13192*/           OPC_EmitMergeInputChains1_0,
/*13193*/           OPC_EmitNode, TARGET_VAL(AMDGPU::SI_ADDR64_RSRC), 0|OPFL_Chain,
                        1/*#VTs*/, MVT::i128, 1/*#Ops*/, 1,  // Results = #3
/*13201*/           OPC_EmitInteger, MVT::i16, 0, 
/*13204*/           OPC_MorphNodeTo, TARGET_VAL(AMDGPU::BUFFER_LOAD_SSHORT_ADDR64), 0|OPFL_Chain|OPFL_MemRefs,
                        1/*#VTs*/, MVT::i32, 3/*#Ops*/, 3, 2, 4, 
                    // Src: (ld:i32 (add:i64 i64:i64:$ptr, i64:i64:$offset))<<P:Predicate_unindexedload>><<P:Predicate_sextload>><<P:Predicate_sextloadi16>><<P:Predicate_sextloadi16_constant>> - Complexity = 7
                    // Dst: (BUFFER_LOAD_SSHORT_ADDR64:i32 (SI_ADDR64_RSRC:i128 ?:i64:$ptr), ?:i64:$offset, 0:i16)
/*13214*/         0, /*End of Scope*/
/*13215*/       /*Scope*/ 62, /*->13278*/
/*13216*/         OPC_CheckPredicate, 12, // Predicate_az_extload
/*13218*/         OPC_CheckPredicate, 15, // Predicate_az_extloadi16
/*13220*/         OPC_CheckType, MVT::i32,
/*13222*/         OPC_Scope, 26, /*->13250*/ // 2 children in Scope
/*13224*/           OPC_CheckPredicate, 20, // Predicate_az_extloadi16_global
/*13226*/           OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*13228*/           OPC_EmitMergeInputChains1_0,
/*13229*/           OPC_EmitNode, TARGET_VAL(AMDGPU::SI_ADDR64_RSRC), 0|OPFL_Chain,
                        1/*#VTs*/, MVT::i128, 1/*#Ops*/, 1,  // Results = #3
/*13237*/           OPC_EmitInteger, MVT::i16, 0, 
/*13240*/           OPC_MorphNodeTo, TARGET_VAL(AMDGPU::BUFFER_LOAD_USHORT_ADDR64), 0|OPFL_Chain|OPFL_MemRefs,
                        1/*#VTs*/, MVT::i32, 3/*#Ops*/, 3, 2, 4, 
                    // Src: (ld:i32 (add:i64 i64:i64:$ptr, i64:i64:$offset))<<P:Predicate_unindexedload>><<P:Predicate_az_extload>><<P:Predicate_az_extloadi16>><<P:Predicate_az_extloadi16_global>> - Complexity = 7
                    // Dst: (BUFFER_LOAD_USHORT_ADDR64:i32 (SI_ADDR64_RSRC:i128 ?:i64:$ptr), ?:i64:$offset, 0:i16)
/*13250*/         /*Scope*/ 26, /*->13277*/
/*13251*/           OPC_CheckPredicate, 35, // Predicate_az_extloadi16_constant
/*13253*/           OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*13255*/           OPC_EmitMergeInputChains1_0,
/*13256*/           OPC_EmitNode, TARGET_VAL(AMDGPU::SI_ADDR64_RSRC), 0|OPFL_Chain,
                        1/*#VTs*/, MVT::i128, 1/*#Ops*/, 1,  // Results = #3
/*13264*/           OPC_EmitInteger, MVT::i16, 0, 
/*13267*/           OPC_MorphNodeTo, TARGET_VAL(AMDGPU::BUFFER_LOAD_USHORT_ADDR64), 0|OPFL_Chain|OPFL_MemRefs,
                        1/*#VTs*/, MVT::i32, 3/*#Ops*/, 3, 2, 4, 
                    // Src: (ld:i32 (add:i64 i64:i64:$ptr, i64:i64:$offset))<<P:Predicate_unindexedload>><<P:Predicate_az_extload>><<P:Predicate_az_extloadi16>><<P:Predicate_az_extloadi16_constant>> - Complexity = 7
                    // Dst: (BUFFER_LOAD_USHORT_ADDR64:i32 (SI_ADDR64_RSRC:i128 ?:i64:$ptr), ?:i64:$offset, 0:i16)
/*13277*/         0, /*End of Scope*/
/*13278*/       /*Scope*/ 120, /*->13399*/
/*13279*/         OPC_CheckPredicate, 17, // Predicate_load
/*13281*/         OPC_SwitchType /*2 cases */, 56,  MVT::i32,// ->13340
/*13284*/           OPC_Scope, 26, /*->13312*/ // 2 children in Scope
/*13286*/             OPC_CheckPredicate, 21, // Predicate_global_load
/*13288*/             OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*13290*/             OPC_EmitMergeInputChains1_0,
/*13291*/             OPC_EmitNode, TARGET_VAL(AMDGPU::SI_ADDR64_RSRC), 0|OPFL_Chain,
                          1/*#VTs*/, MVT::i128, 1/*#Ops*/, 1,  // Results = #3
/*13299*/             OPC_EmitInteger, MVT::i16, 0, 
/*13302*/             OPC_MorphNodeTo, TARGET_VAL(AMDGPU::BUFFER_LOAD_DWORD_ADDR64), 0|OPFL_Chain|OPFL_MemRefs,
                          1/*#VTs*/, MVT::i32, 3/*#Ops*/, 3, 2, 4, 
                      // Src: (ld:i32 (add:i64 i64:i64:$ptr, i64:i64:$offset))<<P:Predicate_unindexedload>><<P:Predicate_load>><<P:Predicate_global_load>> - Complexity = 7
                      // Dst: (BUFFER_LOAD_DWORD_ADDR64:i32 (SI_ADDR64_RSRC:i128 ?:i64:$ptr), ?:i64:$offset, 0:i16)
/*13312*/           /*Scope*/ 26, /*->13339*/
/*13313*/             OPC_CheckPredicate, 23, // Predicate_constant_load
/*13315*/             OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*13317*/             OPC_EmitMergeInputChains1_0,
/*13318*/             OPC_EmitNode, TARGET_VAL(AMDGPU::SI_ADDR64_RSRC), 0|OPFL_Chain,
                          1/*#VTs*/, MVT::i128, 1/*#Ops*/, 1,  // Results = #3
/*13326*/             OPC_EmitInteger, MVT::i16, 0, 
/*13329*/             OPC_MorphNodeTo, TARGET_VAL(AMDGPU::BUFFER_LOAD_DWORD_ADDR64), 0|OPFL_Chain|OPFL_MemRefs,
                          1/*#VTs*/, MVT::i32, 3/*#Ops*/, 3, 2, 4, 
                      // Src: (ld:i32 (add:i64 i64:i64:$ptr, i64:i64:$offset))<<P:Predicate_unindexedload>><<P:Predicate_load>><<P:Predicate_constant_load>> - Complexity = 7
                      // Dst: (BUFFER_LOAD_DWORD_ADDR64:i32 (SI_ADDR64_RSRC:i128 ?:i64:$ptr), ?:i64:$offset, 0:i16)
/*13339*/           0, /*End of Scope*/
/*13340*/         /*SwitchType*/ 56,  MVT::i64,// ->13398
/*13342*/           OPC_Scope, 26, /*->13370*/ // 2 children in Scope
/*13344*/             OPC_CheckPredicate, 21, // Predicate_global_load
/*13346*/             OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*13348*/             OPC_EmitMergeInputChains1_0,
/*13349*/             OPC_EmitNode, TARGET_VAL(AMDGPU::SI_ADDR64_RSRC), 0|OPFL_Chain,
                          1/*#VTs*/, MVT::i128, 1/*#Ops*/, 1,  // Results = #3
/*13357*/             OPC_EmitInteger, MVT::i16, 0, 
/*13360*/             OPC_MorphNodeTo, TARGET_VAL(AMDGPU::BUFFER_LOAD_DWORDX2_ADDR64), 0|OPFL_Chain|OPFL_MemRefs,
                          1/*#VTs*/, MVT::i64, 3/*#Ops*/, 3, 2, 4, 
                      // Src: (ld:i64 (add:i64 i64:i64:$ptr, i64:i64:$offset))<<P:Predicate_unindexedload>><<P:Predicate_load>><<P:Predicate_global_load>> - Complexity = 7
                      // Dst: (BUFFER_LOAD_DWORDX2_ADDR64:i64 (SI_ADDR64_RSRC:i128 ?:i64:$ptr), ?:i64:$offset, 0:i16)
/*13370*/           /*Scope*/ 26, /*->13397*/
/*13371*/             OPC_CheckPredicate, 23, // Predicate_constant_load
/*13373*/             OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*13375*/             OPC_EmitMergeInputChains1_0,
/*13376*/             OPC_EmitNode, TARGET_VAL(AMDGPU::SI_ADDR64_RSRC), 0|OPFL_Chain,
                          1/*#VTs*/, MVT::i128, 1/*#Ops*/, 1,  // Results = #3
/*13384*/             OPC_EmitInteger, MVT::i16, 0, 
/*13387*/             OPC_MorphNodeTo, TARGET_VAL(AMDGPU::BUFFER_LOAD_DWORDX2_ADDR64), 0|OPFL_Chain|OPFL_MemRefs,
                          1/*#VTs*/, MVT::i64, 3/*#Ops*/, 3, 2, 4, 
                      // Src: (ld:i64 (add:i64 i64:i64:$ptr, i64:i64:$offset))<<P:Predicate_unindexedload>><<P:Predicate_load>><<P:Predicate_constant_load>> - Complexity = 7
                      // Dst: (BUFFER_LOAD_DWORDX2_ADDR64:i64 (SI_ADDR64_RSRC:i128 ?:i64:$ptr), ?:i64:$offset, 0:i16)
/*13397*/           0, /*End of Scope*/
/*13398*/         0, // EndSwitchType
/*13399*/       /*Scope*/ 62, /*->13462*/
/*13400*/         OPC_CheckPredicate, 12, // Predicate_az_extload
/*13402*/         OPC_CheckPredicate, 30, // Predicate_az_extloadi32
/*13404*/         OPC_CheckType, MVT::i64,
/*13406*/         OPC_Scope, 26, /*->13434*/ // 2 children in Scope
/*13408*/           OPC_CheckPredicate, 31, // Predicate_az_extloadi32_global
/*13410*/           OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*13412*/           OPC_EmitMergeInputChains1_0,
/*13413*/           OPC_EmitNode, TARGET_VAL(AMDGPU::SI_ADDR64_RSRC), 0|OPFL_Chain,
                        1/*#VTs*/, MVT::i128, 1/*#Ops*/, 1,  // Results = #3
/*13421*/           OPC_EmitInteger, MVT::i16, 0, 
/*13424*/           OPC_MorphNodeTo, TARGET_VAL(AMDGPU::BUFFER_LOAD_DWORDX2_ADDR64), 0|OPFL_Chain|OPFL_MemRefs,
                        1/*#VTs*/, MVT::i64, 3/*#Ops*/, 3, 2, 4, 
                    // Src: (ld:i64 (add:i64 i64:i64:$ptr, i64:i64:$offset))<<P:Predicate_unindexedload>><<P:Predicate_az_extload>><<P:Predicate_az_extloadi32>><<P:Predicate_az_extloadi32_global>> - Complexity = 7
                    // Dst: (BUFFER_LOAD_DWORDX2_ADDR64:i64 (SI_ADDR64_RSRC:i128 ?:i64:$ptr), ?:i64:$offset, 0:i16)
/*13434*/         /*Scope*/ 26, /*->13461*/
/*13435*/           OPC_CheckPredicate, 36, // Predicate_az_extloadi32_constant
/*13437*/           OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*13439*/           OPC_EmitMergeInputChains1_0,
/*13440*/           OPC_EmitNode, TARGET_VAL(AMDGPU::SI_ADDR64_RSRC), 0|OPFL_Chain,
                        1/*#VTs*/, MVT::i128, 1/*#Ops*/, 1,  // Results = #3
/*13448*/           OPC_EmitInteger, MVT::i16, 0, 
/*13451*/           OPC_MorphNodeTo, TARGET_VAL(AMDGPU::BUFFER_LOAD_DWORDX2_ADDR64), 0|OPFL_Chain|OPFL_MemRefs,
                        1/*#VTs*/, MVT::i64, 3/*#Ops*/, 3, 2, 4, 
                    // Src: (ld:i64 (add:i64 i64:i64:$ptr, i64:i64:$offset))<<P:Predicate_unindexedload>><<P:Predicate_az_extload>><<P:Predicate_az_extloadi32>><<P:Predicate_az_extloadi32_constant>> - Complexity = 7
                    // Dst: (BUFFER_LOAD_DWORDX2_ADDR64:i64 (SI_ADDR64_RSRC:i128 ?:i64:$ptr), ?:i64:$offset, 0:i16)
/*13461*/         0, /*End of Scope*/
/*13462*/       0, /*End of Scope*/
/*13463*/     0, /*End of Scope*/
/*13464*/   /*Scope*/ 74|128,5/*714*/, /*->14180*/
/*13466*/     OPC_RecordChild1, // #1 = $src0
/*13467*/     OPC_Scope, 14|128,3/*398*/, /*->13868*/ // 2 children in Scope
/*13470*/       OPC_CheckChild1Type, MVT::i32,
/*13472*/       OPC_CheckPredicate, 11, // Predicate_unindexedload
/*13474*/       OPC_CheckType, MVT::i32,
/*13476*/       OPC_Scope, 31, /*->13509*/ // 9 children in Scope
/*13478*/         OPC_CheckPredicate, 25, // Predicate_sextload
/*13480*/         OPC_CheckPredicate, 26, // Predicate_sextloadi8
/*13482*/         OPC_CheckPredicate, 37, // Predicate_sextloadi8_local
/*13484*/         OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*13486*/         OPC_EmitMergeInputChains1_0,
/*13487*/         OPC_EmitInteger, MVT::i1, 0, 
/*13490*/         OPC_EmitInteger, MVT::i8, 0, 
/*13493*/         OPC_EmitInteger, MVT::i8, 0, 
/*13496*/         OPC_MorphNodeTo, TARGET_VAL(AMDGPU::DS_READ_I8), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i32, 6/*#Ops*/, 2, 1, 1, 1, 3, 4, 
                  // Src: (ld:i32 i32:i32:$src0)<<P:Predicate_unindexedload>><<P:Predicate_sextload>><<P:Predicate_sextloadi8>><<P:Predicate_sextloadi8_local>> - Complexity = 4
                  // Dst: (DS_READ_I8:i32 0:i1, ?:i32:$src0, ?:i32:$src0, ?:i32:$src0, 0:i8, 0:i8)
/*13509*/       /*Scope*/ 31, /*->13541*/
/*13510*/         OPC_CheckPredicate, 12, // Predicate_az_extload
/*13512*/         OPC_CheckPredicate, 13, // Predicate_az_extloadi8
/*13514*/         OPC_CheckPredicate, 38, // Predicate_az_extloadi8_local
/*13516*/         OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*13518*/         OPC_EmitMergeInputChains1_0,
/*13519*/         OPC_EmitInteger, MVT::i1, 0, 
/*13522*/         OPC_EmitInteger, MVT::i8, 0, 
/*13525*/         OPC_EmitInteger, MVT::i8, 0, 
/*13528*/         OPC_MorphNodeTo, TARGET_VAL(AMDGPU::DS_READ_U8), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i32, 6/*#Ops*/, 2, 1, 1, 1, 3, 4, 
                  // Src: (ld:i32 i32:i32:$src0)<<P:Predicate_unindexedload>><<P:Predicate_az_extload>><<P:Predicate_az_extloadi8>><<P:Predicate_az_extloadi8_local>> - Complexity = 4
                  // Dst: (DS_READ_U8:i32 0:i1, ?:i32:$src0, ?:i32:$src0, ?:i32:$src0, 0:i8, 0:i8)
/*13541*/       /*Scope*/ 31, /*->13573*/
/*13542*/         OPC_CheckPredicate, 25, // Predicate_sextload
/*13544*/         OPC_CheckPredicate, 28, // Predicate_sextloadi16
/*13546*/         OPC_CheckPredicate, 39, // Predicate_sextloadi16_local
/*13548*/         OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*13550*/         OPC_EmitMergeInputChains1_0,
/*13551*/         OPC_EmitInteger, MVT::i1, 0, 
/*13554*/         OPC_EmitInteger, MVT::i8, 0, 
/*13557*/         OPC_EmitInteger, MVT::i8, 0, 
/*13560*/         OPC_MorphNodeTo, TARGET_VAL(AMDGPU::DS_READ_I16), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i32, 6/*#Ops*/, 2, 1, 1, 1, 3, 4, 
                  // Src: (ld:i32 i32:i32:$src0)<<P:Predicate_unindexedload>><<P:Predicate_sextload>><<P:Predicate_sextloadi16>><<P:Predicate_sextloadi16_local>> - Complexity = 4
                  // Dst: (DS_READ_I16:i32 0:i1, ?:i32:$src0, ?:i32:$src0, ?:i32:$src0, 0:i8, 0:i8)
/*13573*/       /*Scope*/ 31, /*->13605*/
/*13574*/         OPC_CheckPredicate, 12, // Predicate_az_extload
/*13576*/         OPC_CheckPredicate, 15, // Predicate_az_extloadi16
/*13578*/         OPC_CheckPredicate, 40, // Predicate_az_extloadi16_local
/*13580*/         OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*13582*/         OPC_EmitMergeInputChains1_0,
/*13583*/         OPC_EmitInteger, MVT::i1, 0, 
/*13586*/         OPC_EmitInteger, MVT::i8, 0, 
/*13589*/         OPC_EmitInteger, MVT::i8, 0, 
/*13592*/         OPC_MorphNodeTo, TARGET_VAL(AMDGPU::DS_READ_U16), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i32, 6/*#Ops*/, 2, 1, 1, 1, 3, 4, 
                  // Src: (ld:i32 i32:i32:$src0)<<P:Predicate_unindexedload>><<P:Predicate_az_extload>><<P:Predicate_az_extloadi16>><<P:Predicate_az_extloadi16_local>> - Complexity = 4
                  // Dst: (DS_READ_U16:i32 0:i1, ?:i32:$src0, ?:i32:$src0, ?:i32:$src0, 0:i8, 0:i8)
/*13605*/       /*Scope*/ 73, /*->13679*/
/*13606*/         OPC_CheckPredicate, 17, // Predicate_load
/*13608*/         OPC_CheckPredicate, 41, // Predicate_local_load
/*13610*/         OPC_Scope, 25, /*->13637*/ // 2 children in Scope
/*13612*/           OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*13614*/           OPC_EmitMergeInputChains1_0,
/*13615*/           OPC_EmitInteger, MVT::i1, 0, 
/*13618*/           OPC_EmitInteger, MVT::i8, 0, 
/*13621*/           OPC_EmitInteger, MVT::i8, 0, 
/*13624*/           OPC_MorphNodeTo, TARGET_VAL(AMDGPU::DS_READ_B32), 0|OPFL_Chain|OPFL_MemRefs,
                        1/*#VTs*/, MVT::i32, 6/*#Ops*/, 2, 1, 1, 1, 3, 4, 
                    // Src: (ld:i32 i32:i32:$src0)<<P:Predicate_unindexedload>><<P:Predicate_load>><<P:Predicate_local_load>> - Complexity = 4
                    // Dst: (DS_READ_B32:i32 0:i1, ?:i32:$src0, ?:i32:$src0, ?:i32:$src0, 0:i8, 0:i8)
/*13637*/         /*Scope*/ 40, /*->13678*/
/*13638*/           OPC_CheckPatternPredicate, 2, // (Subtarget.getGeneration() == AMDGPUSubtarget::EVERGREEN|| Subtarget.getGeneration() ==AMDGPUSubtarget::NORTHERN_ISLANDS)
/*13640*/           OPC_EmitMergeInputChains1_0,
/*13641*/           OPC_EmitInteger, MVT::i32, 0, 
/*13644*/           OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*13656*/           OPC_EmitInteger, MVT::i32, 1, 
/*13659*/           OPC_EmitRegister, MVT::i32, AMDGPU::PRED_SEL_OFF,
/*13662*/           OPC_EmitInteger, MVT::i32, 0, 
/*13665*/           OPC_MorphNodeTo, TARGET_VAL(AMDGPU::LDS_READ_RET), 0|OPFL_Chain|OPFL_MemRefs,
                        1/*#VTs*/, MVT::i32, 6/*#Ops*/, 1, 2, 3, 4, 5, 6, 
                    // Src: (ld:i32 R600_Reg32:i32:$src0)<<P:Predicate_unindexedload>><<P:Predicate_load>><<P:Predicate_local_load>> - Complexity = 4
                    // Dst: (LDS_READ_RET:i32 R600_Reg32:i32:$src0)
/*13678*/         0, /*End of Scope*/
/*13679*/       /*Scope*/ 46, /*->13726*/
/*13680*/         OPC_CheckPredicate, 25, // Predicate_sextload
/*13682*/         OPC_CheckPredicate, 26, // Predicate_sextloadi8
/*13684*/         OPC_CheckPredicate, 37, // Predicate_sextloadi8_local
/*13686*/         OPC_CheckPatternPredicate, 2, // (Subtarget.getGeneration() == AMDGPUSubtarget::EVERGREEN|| Subtarget.getGeneration() ==AMDGPUSubtarget::NORTHERN_ISLANDS)
/*13688*/         OPC_EmitMergeInputChains1_0,
/*13689*/         OPC_EmitInteger, MVT::i32, 0, 
/*13692*/         OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*13704*/         OPC_EmitInteger, MVT::i32, 1, 
/*13707*/         OPC_EmitRegister, MVT::i32, AMDGPU::PRED_SEL_OFF,
/*13710*/         OPC_EmitInteger, MVT::i32, 0, 
/*13713*/         OPC_MorphNodeTo, TARGET_VAL(AMDGPU::LDS_BYTE_READ_RET), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i32, 6/*#Ops*/, 1, 2, 3, 4, 5, 6, 
                  // Src: (ld:i32 i32:i32:$src0)<<P:Predicate_unindexedload>><<P:Predicate_sextload>><<P:Predicate_sextloadi8>><<P:Predicate_sextloadi8_local>> - Complexity = 4
                  // Dst: (LDS_BYTE_READ_RET:i32 i32:i32:$src0)
/*13726*/       /*Scope*/ 46, /*->13773*/
/*13727*/         OPC_CheckPredicate, 12, // Predicate_az_extload
/*13729*/         OPC_CheckPredicate, 13, // Predicate_az_extloadi8
/*13731*/         OPC_CheckPredicate, 38, // Predicate_az_extloadi8_local
/*13733*/         OPC_CheckPatternPredicate, 2, // (Subtarget.getGeneration() == AMDGPUSubtarget::EVERGREEN|| Subtarget.getGeneration() ==AMDGPUSubtarget::NORTHERN_ISLANDS)
/*13735*/         OPC_EmitMergeInputChains1_0,
/*13736*/         OPC_EmitInteger, MVT::i32, 0, 
/*13739*/         OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*13751*/         OPC_EmitInteger, MVT::i32, 1, 
/*13754*/         OPC_EmitRegister, MVT::i32, AMDGPU::PRED_SEL_OFF,
/*13757*/         OPC_EmitInteger, MVT::i32, 0, 
/*13760*/         OPC_MorphNodeTo, TARGET_VAL(AMDGPU::LDS_UBYTE_READ_RET), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i32, 6/*#Ops*/, 1, 2, 3, 4, 5, 6, 
                  // Src: (ld:i32 i32:i32:$src0)<<P:Predicate_unindexedload>><<P:Predicate_az_extload>><<P:Predicate_az_extloadi8>><<P:Predicate_az_extloadi8_local>> - Complexity = 4
                  // Dst: (LDS_UBYTE_READ_RET:i32 i32:i32:$src0)
/*13773*/       /*Scope*/ 46, /*->13820*/
/*13774*/         OPC_CheckPredicate, 25, // Predicate_sextload
/*13776*/         OPC_CheckPredicate, 28, // Predicate_sextloadi16
/*13778*/         OPC_CheckPredicate, 39, // Predicate_sextloadi16_local
/*13780*/         OPC_CheckPatternPredicate, 2, // (Subtarget.getGeneration() == AMDGPUSubtarget::EVERGREEN|| Subtarget.getGeneration() ==AMDGPUSubtarget::NORTHERN_ISLANDS)
/*13782*/         OPC_EmitMergeInputChains1_0,
/*13783*/         OPC_EmitInteger, MVT::i32, 0, 
/*13786*/         OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*13798*/         OPC_EmitInteger, MVT::i32, 1, 
/*13801*/         OPC_EmitRegister, MVT::i32, AMDGPU::PRED_SEL_OFF,
/*13804*/         OPC_EmitInteger, MVT::i32, 0, 
/*13807*/         OPC_MorphNodeTo, TARGET_VAL(AMDGPU::LDS_SHORT_READ_RET), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i32, 6/*#Ops*/, 1, 2, 3, 4, 5, 6, 
                  // Src: (ld:i32 i32:i32:$src0)<<P:Predicate_unindexedload>><<P:Predicate_sextload>><<P:Predicate_sextloadi16>><<P:Predicate_sextloadi16_local>> - Complexity = 4
                  // Dst: (LDS_SHORT_READ_RET:i32 i32:i32:$src0)
/*13820*/       /*Scope*/ 46, /*->13867*/
/*13821*/         OPC_CheckPredicate, 12, // Predicate_az_extload
/*13823*/         OPC_CheckPredicate, 15, // Predicate_az_extloadi16
/*13825*/         OPC_CheckPredicate, 40, // Predicate_az_extloadi16_local
/*13827*/         OPC_CheckPatternPredicate, 2, // (Subtarget.getGeneration() == AMDGPUSubtarget::EVERGREEN|| Subtarget.getGeneration() ==AMDGPUSubtarget::NORTHERN_ISLANDS)
/*13829*/         OPC_EmitMergeInputChains1_0,
/*13830*/         OPC_EmitInteger, MVT::i32, 0, 
/*13833*/         OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*13845*/         OPC_EmitInteger, MVT::i32, 1, 
/*13848*/         OPC_EmitRegister, MVT::i32, AMDGPU::PRED_SEL_OFF,
/*13851*/         OPC_EmitInteger, MVT::i32, 0, 
/*13854*/         OPC_MorphNodeTo, TARGET_VAL(AMDGPU::LDS_USHORT_READ_RET), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i32, 6/*#Ops*/, 1, 2, 3, 4, 5, 6, 
                  // Src: (ld:i32 i32:i32:$src0)<<P:Predicate_unindexedload>><<P:Predicate_az_extload>><<P:Predicate_az_extloadi16>><<P:Predicate_az_extloadi16_local>> - Complexity = 4
                  // Dst: (LDS_USHORT_READ_RET:i32 i32:i32:$src0)
/*13867*/       0, /*End of Scope*/
/*13868*/     /*Scope*/ 53|128,2/*309*/, /*->14179*/
/*13870*/       OPC_CheckChild1Type, MVT::i64,
/*13872*/       OPC_CheckPredicate, 11, // Predicate_unindexedload
/*13874*/       OPC_Scope, 57, /*->13933*/ // 7 children in Scope
/*13876*/         OPC_CheckPredicate, 17, // Predicate_load
/*13878*/         OPC_CheckPredicate, 23, // Predicate_constant_load
/*13880*/         OPC_SwitchType /*3 cases */, 15,  MVT::i32,// ->13898
/*13883*/           OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*13885*/           OPC_EmitMergeInputChains1_0,
/*13886*/           OPC_EmitInteger, MVT::i32, 0, 
/*13889*/           OPC_MorphNodeTo, TARGET_VAL(AMDGPU::S_LOAD_DWORD_IMM), 0|OPFL_Chain|OPFL_MemRefs,
                        1/*#VTs*/, MVT::i32, 2/*#Ops*/, 1, 2, 
                    // Src: (ld:i32 i64:i64:$sbase)<<P:Predicate_unindexedload>><<P:Predicate_load>><<P:Predicate_constant_load>> - Complexity = 4
                    // Dst: (S_LOAD_DWORD_IMM:i32 ?:i64:$sbase, 0:i32)
/*13898*/         /*SwitchType*/ 15,  MVT::i64,// ->13915
/*13900*/           OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*13902*/           OPC_EmitMergeInputChains1_0,
/*13903*/           OPC_EmitInteger, MVT::i32, 0, 
/*13906*/           OPC_MorphNodeTo, TARGET_VAL(AMDGPU::S_LOAD_DWORDX2_IMM), 0|OPFL_Chain|OPFL_MemRefs,
                        1/*#VTs*/, MVT::i64, 2/*#Ops*/, 1, 2, 
                    // Src: (ld:i64 i64:i64:$sbase)<<P:Predicate_unindexedload>><<P:Predicate_load>><<P:Predicate_constant_load>> - Complexity = 4
                    // Dst: (S_LOAD_DWORDX2_IMM:i64 ?:i64:$sbase, 0:i32)
/*13915*/         /*SwitchType*/ 15,  MVT::i128,// ->13932
/*13917*/           OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*13919*/           OPC_EmitMergeInputChains1_0,
/*13920*/           OPC_EmitInteger, MVT::i32, 0, 
/*13923*/           OPC_MorphNodeTo, TARGET_VAL(AMDGPU::S_LOAD_DWORDX4_IMM), 0|OPFL_Chain|OPFL_MemRefs,
                        1/*#VTs*/, MVT::i128, 2/*#Ops*/, 1, 2, 
                    // Src: (ld:i128 i64:i64:$sbase)<<P:Predicate_unindexedload>><<P:Predicate_load>><<P:Predicate_constant_load>> - Complexity = 4
                    // Dst: (S_LOAD_DWORDX4_IMM:i128 ?:i64:$sbase, 0:i32)
/*13932*/         0, // EndSwitchType
/*13933*/       /*Scope*/ 35, /*->13969*/
/*13934*/         OPC_CheckPredicate, 25, // Predicate_sextload
/*13936*/         OPC_CheckPredicate, 26, // Predicate_sextloadi8
/*13938*/         OPC_CheckPredicate, 27, // Predicate_sextloadi8_global
/*13940*/         OPC_CheckType, MVT::i32,
/*13942*/         OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*13944*/         OPC_EmitMergeInputChains1_0,
/*13945*/         OPC_EmitInteger, MVT::i64, 0, 
/*13948*/         OPC_EmitNode, TARGET_VAL(AMDGPU::SI_ADDR64_RSRC), 0|OPFL_Chain,
                      1/*#VTs*/, MVT::i128, 1/*#Ops*/, 2,  // Results = #3
/*13956*/         OPC_EmitInteger, MVT::i16, 0, 
/*13959*/         OPC_MorphNodeTo, TARGET_VAL(AMDGPU::BUFFER_LOAD_SBYTE_ADDR64), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i32, 3/*#Ops*/, 3, 1, 4, 
                  // Src: (ld:i32 i64:i64:$ptr)<<P:Predicate_unindexedload>><<P:Predicate_sextload>><<P:Predicate_sextloadi8>><<P:Predicate_sextloadi8_global>> - Complexity = 4
                  // Dst: (BUFFER_LOAD_SBYTE_ADDR64:i32 (SI_ADDR64_RSRC:i128 0:i64), ?:i64:$ptr, 0:i16)
/*13969*/       /*Scope*/ 35, /*->14005*/
/*13970*/         OPC_CheckPredicate, 12, // Predicate_az_extload
/*13972*/         OPC_CheckPredicate, 13, // Predicate_az_extloadi8
/*13974*/         OPC_CheckPredicate, 19, // Predicate_az_extloadi8_global
/*13976*/         OPC_CheckType, MVT::i32,
/*13978*/         OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*13980*/         OPC_EmitMergeInputChains1_0,
/*13981*/         OPC_EmitInteger, MVT::i64, 0, 
/*13984*/         OPC_EmitNode, TARGET_VAL(AMDGPU::SI_ADDR64_RSRC), 0|OPFL_Chain,
                      1/*#VTs*/, MVT::i128, 1/*#Ops*/, 2,  // Results = #3
/*13992*/         OPC_EmitInteger, MVT::i16, 0, 
/*13995*/         OPC_MorphNodeTo, TARGET_VAL(AMDGPU::BUFFER_LOAD_UBYTE_ADDR64), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i32, 3/*#Ops*/, 3, 1, 4, 
                  // Src: (ld:i32 i64:i64:$ptr)<<P:Predicate_unindexedload>><<P:Predicate_az_extload>><<P:Predicate_az_extloadi8>><<P:Predicate_az_extloadi8_global>> - Complexity = 4
                  // Dst: (BUFFER_LOAD_UBYTE_ADDR64:i32 (SI_ADDR64_RSRC:i128 0:i64), ?:i64:$ptr, 0:i16)
/*14005*/       /*Scope*/ 35, /*->14041*/
/*14006*/         OPC_CheckPredicate, 25, // Predicate_sextload
/*14008*/         OPC_CheckPredicate, 28, // Predicate_sextloadi16
/*14010*/         OPC_CheckPredicate, 29, // Predicate_sextloadi16_global
/*14012*/         OPC_CheckType, MVT::i32,
/*14014*/         OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*14016*/         OPC_EmitMergeInputChains1_0,
/*14017*/         OPC_EmitInteger, MVT::i64, 0, 
/*14020*/         OPC_EmitNode, TARGET_VAL(AMDGPU::SI_ADDR64_RSRC), 0|OPFL_Chain,
                      1/*#VTs*/, MVT::i128, 1/*#Ops*/, 2,  // Results = #3
/*14028*/         OPC_EmitInteger, MVT::i16, 0, 
/*14031*/         OPC_MorphNodeTo, TARGET_VAL(AMDGPU::BUFFER_LOAD_SSHORT_ADDR64), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i32, 3/*#Ops*/, 3, 1, 4, 
                  // Src: (ld:i32 i64:i64:$ptr)<<P:Predicate_unindexedload>><<P:Predicate_sextload>><<P:Predicate_sextloadi16>><<P:Predicate_sextloadi16_global>> - Complexity = 4
                  // Dst: (BUFFER_LOAD_SSHORT_ADDR64:i32 (SI_ADDR64_RSRC:i128 0:i64), ?:i64:$ptr, 0:i16)
/*14041*/       /*Scope*/ 35, /*->14077*/
/*14042*/         OPC_CheckPredicate, 12, // Predicate_az_extload
/*14044*/         OPC_CheckPredicate, 15, // Predicate_az_extloadi16
/*14046*/         OPC_CheckPredicate, 20, // Predicate_az_extloadi16_global
/*14048*/         OPC_CheckType, MVT::i32,
/*14050*/         OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*14052*/         OPC_EmitMergeInputChains1_0,
/*14053*/         OPC_EmitInteger, MVT::i64, 0, 
/*14056*/         OPC_EmitNode, TARGET_VAL(AMDGPU::SI_ADDR64_RSRC), 0|OPFL_Chain,
                      1/*#VTs*/, MVT::i128, 1/*#Ops*/, 2,  // Results = #3
/*14064*/         OPC_EmitInteger, MVT::i16, 0, 
/*14067*/         OPC_MorphNodeTo, TARGET_VAL(AMDGPU::BUFFER_LOAD_USHORT_ADDR64), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i32, 3/*#Ops*/, 3, 1, 4, 
                  // Src: (ld:i32 i64:i64:$ptr)<<P:Predicate_unindexedload>><<P:Predicate_az_extload>><<P:Predicate_az_extloadi16>><<P:Predicate_az_extloadi16_global>> - Complexity = 4
                  // Dst: (BUFFER_LOAD_USHORT_ADDR64:i32 (SI_ADDR64_RSRC:i128 0:i64), ?:i64:$ptr, 0:i16)
/*14077*/       /*Scope*/ 64, /*->14142*/
/*14078*/         OPC_CheckPredicate, 17, // Predicate_load
/*14080*/         OPC_CheckPredicate, 21, // Predicate_global_load
/*14082*/         OPC_SwitchType /*2 cases */, 27,  MVT::i32,// ->14112
/*14085*/           OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*14087*/           OPC_EmitMergeInputChains1_0,
/*14088*/           OPC_EmitInteger, MVT::i64, 0, 
/*14091*/           OPC_EmitNode, TARGET_VAL(AMDGPU::SI_ADDR64_RSRC), 0|OPFL_Chain,
                        1/*#VTs*/, MVT::i128, 1/*#Ops*/, 2,  // Results = #3
/*14099*/           OPC_EmitInteger, MVT::i16, 0, 
/*14102*/           OPC_MorphNodeTo, TARGET_VAL(AMDGPU::BUFFER_LOAD_DWORD_ADDR64), 0|OPFL_Chain|OPFL_MemRefs,
                        1/*#VTs*/, MVT::i32, 3/*#Ops*/, 3, 1, 4, 
                    // Src: (ld:i32 i64:i64:$ptr)<<P:Predicate_unindexedload>><<P:Predicate_load>><<P:Predicate_global_load>> - Complexity = 4
                    // Dst: (BUFFER_LOAD_DWORD_ADDR64:i32 (SI_ADDR64_RSRC:i128 0:i64), ?:i64:$ptr, 0:i16)
/*14112*/         /*SwitchType*/ 27,  MVT::i64,// ->14141
/*14114*/           OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*14116*/           OPC_EmitMergeInputChains1_0,
/*14117*/           OPC_EmitInteger, MVT::i64, 0, 
/*14120*/           OPC_EmitNode, TARGET_VAL(AMDGPU::SI_ADDR64_RSRC), 0|OPFL_Chain,
                        1/*#VTs*/, MVT::i128, 1/*#Ops*/, 2,  // Results = #3
/*14128*/           OPC_EmitInteger, MVT::i16, 0, 
/*14131*/           OPC_MorphNodeTo, TARGET_VAL(AMDGPU::BUFFER_LOAD_DWORDX2_ADDR64), 0|OPFL_Chain|OPFL_MemRefs,
                        1/*#VTs*/, MVT::i64, 3/*#Ops*/, 3, 1, 4, 
                    // Src: (ld:i64 i64:i64:$ptr)<<P:Predicate_unindexedload>><<P:Predicate_load>><<P:Predicate_global_load>> - Complexity = 4
                    // Dst: (BUFFER_LOAD_DWORDX2_ADDR64:i64 (SI_ADDR64_RSRC:i128 0:i64), ?:i64:$ptr, 0:i16)
/*14141*/         0, // EndSwitchType
/*14142*/       /*Scope*/ 35, /*->14178*/
/*14143*/         OPC_CheckPredicate, 12, // Predicate_az_extload
/*14145*/         OPC_CheckPredicate, 30, // Predicate_az_extloadi32
/*14147*/         OPC_CheckPredicate, 31, // Predicate_az_extloadi32_global
/*14149*/         OPC_CheckType, MVT::i64,
/*14151*/         OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*14153*/         OPC_EmitMergeInputChains1_0,
/*14154*/         OPC_EmitInteger, MVT::i64, 0, 
/*14157*/         OPC_EmitNode, TARGET_VAL(AMDGPU::SI_ADDR64_RSRC), 0|OPFL_Chain,
                      1/*#VTs*/, MVT::i128, 1/*#Ops*/, 2,  // Results = #3
/*14165*/         OPC_EmitInteger, MVT::i16, 0, 
/*14168*/         OPC_MorphNodeTo, TARGET_VAL(AMDGPU::BUFFER_LOAD_DWORDX2_ADDR64), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i64, 3/*#Ops*/, 3, 1, 4, 
                  // Src: (ld:i64 i64:i64:$ptr)<<P:Predicate_unindexedload>><<P:Predicate_az_extload>><<P:Predicate_az_extloadi32>><<P:Predicate_az_extloadi32_global>> - Complexity = 4
                  // Dst: (BUFFER_LOAD_DWORDX2_ADDR64:i64 (SI_ADDR64_RSRC:i128 0:i64), ?:i64:$ptr, 0:i16)
/*14178*/       0, /*End of Scope*/
/*14179*/     0, /*End of Scope*/
/*14180*/   /*Scope*/ 77, /*->14258*/
/*14181*/     OPC_MoveChild, 1,
/*14183*/     OPC_CheckOpcode, TARGET_VAL(ISD::ADD),
/*14186*/     OPC_RecordChild0, // #1 = $sbase
/*14187*/     OPC_RecordChild1, // #2 = $offset
/*14188*/     OPC_MoveChild, 1,
/*14190*/     OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*14193*/     OPC_Scope, 29, /*->14224*/ // 2 children in Scope
/*14195*/       OPC_CheckPredicate, 22, // Predicate_IMM8bitDWORD
/*14197*/       OPC_MoveParent,
/*14198*/       OPC_MoveParent,
/*14199*/       OPC_CheckPredicate, 11, // Predicate_unindexedload
/*14201*/       OPC_CheckPredicate, 17, // Predicate_load
/*14203*/       OPC_CheckPredicate, 23, // Predicate_constant_load
/*14205*/       OPC_CheckType, MVT::f32,
/*14207*/       OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*14209*/       OPC_EmitMergeInputChains1_0,
/*14210*/       OPC_EmitConvertToTarget, 2,
/*14212*/       OPC_EmitNodeXForm, 3, 3, // anonymous.val.459
/*14215*/       OPC_MorphNodeTo, TARGET_VAL(AMDGPU::S_LOAD_DWORD_IMM), 0|OPFL_Chain|OPFL_MemRefs,
                    1/*#VTs*/, MVT::f32, 2/*#Ops*/, 1, 4, 
                // Src: (ld:f32 (SIadd64bit32bit:i64 i64:i64:$sbase, (imm:i32)<<P:Predicate_IMM8bitDWORD>><<X:anonymous.val.459>>:$offset))<<P:Predicate_unindexedload>><<P:Predicate_load>><<P:Predicate_constant_load>> - Complexity = 11
                // Dst: (S_LOAD_DWORD_IMM:f32 ?:i64:$sbase, (anonymous.val.459:i32 (imm:i32)<<P:Predicate_IMM8bitDWORD>>:$offset))
/*14224*/     /*Scope*/ 32, /*->14257*/
/*14225*/       OPC_MoveParent,
/*14226*/       OPC_MoveParent,
/*14227*/       OPC_CheckPredicate, 11, // Predicate_unindexedload
/*14229*/       OPC_CheckPredicate, 17, // Predicate_load
/*14231*/       OPC_CheckPredicate, 23, // Predicate_constant_load
/*14233*/       OPC_CheckType, MVT::f32,
/*14235*/       OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*14237*/       OPC_EmitMergeInputChains1_0,
/*14238*/       OPC_EmitConvertToTarget, 2,
/*14240*/       OPC_EmitNode, TARGET_VAL(AMDGPU::S_MOV_B32), 0,
                    1/*#VTs*/, MVT::i32, 1/*#Ops*/, 3,  // Results = #4
/*14248*/       OPC_MorphNodeTo, TARGET_VAL(AMDGPU::S_LOAD_DWORD_SGPR), 0|OPFL_Chain|OPFL_MemRefs,
                    1/*#VTs*/, MVT::f32, 2/*#Ops*/, 1, 4, 
                // Src: (ld:f32 (SIadd64bit32bit:i64 i64:i64:$sbase, (imm:i32):$offset))<<P:Predicate_unindexedload>><<P:Predicate_load>><<P:Predicate_constant_load>> - Complexity = 10
                // Dst: (S_LOAD_DWORD_SGPR:f32 ?:i64:$sbase, (S_MOV_B32:i32 (imm:i32):$offset))
/*14257*/     0, /*End of Scope*/
/*14258*/   /*Scope*/ 67|128,1/*195*/, /*->14455*/
/*14260*/     OPC_RecordChild1, // #1 = $sbase
/*14261*/     OPC_Scope, 25, /*->14288*/ // 2 children in Scope
/*14263*/       OPC_CheckChild1Type, MVT::i64,
/*14265*/       OPC_CheckPredicate, 11, // Predicate_unindexedload
/*14267*/       OPC_CheckPredicate, 17, // Predicate_load
/*14269*/       OPC_CheckPredicate, 23, // Predicate_constant_load
/*14271*/       OPC_CheckType, MVT::f32,
/*14273*/       OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*14275*/       OPC_EmitMergeInputChains1_0,
/*14276*/       OPC_EmitInteger, MVT::i32, 0, 
/*14279*/       OPC_MorphNodeTo, TARGET_VAL(AMDGPU::S_LOAD_DWORD_IMM), 0|OPFL_Chain|OPFL_MemRefs,
                    1/*#VTs*/, MVT::f32, 2/*#Ops*/, 1, 2, 
                // Src: (ld:f32 i64:i64:$sbase)<<P:Predicate_unindexedload>><<P:Predicate_load>><<P:Predicate_constant_load>> - Complexity = 4
                // Dst: (S_LOAD_DWORD_IMM:f32 ?:i64:$sbase, 0:i32)
/*14288*/     /*Scope*/ 36|128,1/*164*/, /*->14454*/
/*14290*/       OPC_CheckChild1Type, MVT::i32,
/*14292*/       OPC_CheckPredicate, 11, // Predicate_unindexedload
/*14294*/       OPC_CheckPredicate, 17, // Predicate_load
/*14296*/       OPC_Scope, 38, /*->14336*/ // 4 children in Scope
/*14298*/         OPC_CheckPredicate, 18, // Predicate_load_param
/*14300*/         OPC_SwitchType /*2 cases */, 15,  MVT::v2i32,// ->14318
/*14303*/           OPC_CheckPatternPredicate, 5, // (Subtarget.getGeneration() >= AMDGPUSubtarget::EVERGREEN && Subtarget.getGeneration() < AMDGPUSubtarget::SOUTHERN_ISLANDS && !Subtarget.hasCaymanISA())
/*14305*/           OPC_CheckComplexPat, /*CP*/3, /*#*/1, // SelectADDRVTX_READ:$src_gpr #2 #3
/*14308*/           OPC_EmitMergeInputChains1_0,
/*14309*/           OPC_MorphNodeTo, TARGET_VAL(AMDGPU::VTX_READ_PARAM_64_eg), 0|OPFL_Chain|OPFL_MemRefs,
                        1/*#VTs*/, MVT::v2i32, 2/*#Ops*/, 2, 3, 
                    // Src: (ld:v2i32 ADDRVTX_READ:i32:$src_gpr)<<P:Predicate_unindexedload>><<P:Predicate_load>><<P:Predicate_load_param>> - Complexity = 13
                    // Dst: (VTX_READ_PARAM_64_eg:v2i32 ADDRVTX_READ:i32:$src_gpr)
/*14318*/         /*SwitchType*/ 15,  MVT::v4i32,// ->14335
/*14320*/           OPC_CheckPatternPredicate, 5, // (Subtarget.getGeneration() >= AMDGPUSubtarget::EVERGREEN && Subtarget.getGeneration() < AMDGPUSubtarget::SOUTHERN_ISLANDS && !Subtarget.hasCaymanISA())
/*14322*/           OPC_CheckComplexPat, /*CP*/3, /*#*/1, // SelectADDRVTX_READ:$src_gpr #2 #3
/*14325*/           OPC_EmitMergeInputChains1_0,
/*14326*/           OPC_MorphNodeTo, TARGET_VAL(AMDGPU::VTX_READ_PARAM_128_eg), 0|OPFL_Chain|OPFL_MemRefs,
                        1/*#VTs*/, MVT::v4i32, 2/*#Ops*/, 2, 3, 
                    // Src: (ld:v4i32 ADDRVTX_READ:i32:$src_gpr)<<P:Predicate_unindexedload>><<P:Predicate_load>><<P:Predicate_load_param>> - Complexity = 13
                    // Dst: (VTX_READ_PARAM_128_eg:v4i32 ADDRVTX_READ:i32:$src_gpr)
/*14335*/         0, // EndSwitchType
/*14336*/       /*Scope*/ 38, /*->14375*/
/*14337*/         OPC_CheckPredicate, 21, // Predicate_global_load
/*14339*/         OPC_SwitchType /*2 cases */, 15,  MVT::v2i32,// ->14357
/*14342*/           OPC_CheckPatternPredicate, 5, // (Subtarget.getGeneration() >= AMDGPUSubtarget::EVERGREEN && Subtarget.getGeneration() < AMDGPUSubtarget::SOUTHERN_ISLANDS && !Subtarget.hasCaymanISA())
/*14344*/           OPC_CheckComplexPat, /*CP*/3, /*#*/1, // SelectADDRVTX_READ:$src_gpr #2 #3
/*14347*/           OPC_EmitMergeInputChains1_0,
/*14348*/           OPC_MorphNodeTo, TARGET_VAL(AMDGPU::VTX_READ_GLOBAL_64_eg), 0|OPFL_Chain|OPFL_MemRefs,
                        1/*#VTs*/, MVT::v2i32, 2/*#Ops*/, 2, 3, 
                    // Src: (ld:v2i32 ADDRVTX_READ:i32:$src_gpr)<<P:Predicate_unindexedload>><<P:Predicate_load>><<P:Predicate_global_load>> - Complexity = 13
                    // Dst: (VTX_READ_GLOBAL_64_eg:v2i32 ADDRVTX_READ:i32:$src_gpr)
/*14357*/         /*SwitchType*/ 15,  MVT::v4i32,// ->14374
/*14359*/           OPC_CheckPatternPredicate, 5, // (Subtarget.getGeneration() >= AMDGPUSubtarget::EVERGREEN && Subtarget.getGeneration() < AMDGPUSubtarget::SOUTHERN_ISLANDS && !Subtarget.hasCaymanISA())
/*14361*/           OPC_CheckComplexPat, /*CP*/3, /*#*/1, // SelectADDRVTX_READ:$src_gpr #2 #3
/*14364*/           OPC_EmitMergeInputChains1_0,
/*14365*/           OPC_MorphNodeTo, TARGET_VAL(AMDGPU::VTX_READ_GLOBAL_128_eg), 0|OPFL_Chain|OPFL_MemRefs,
                        1/*#VTs*/, MVT::v4i32, 2/*#Ops*/, 2, 3, 
                    // Src: (ld:v4i32 ADDRVTX_READ:i32:$src_gpr)<<P:Predicate_unindexedload>><<P:Predicate_load>><<P:Predicate_global_load>> - Complexity = 13
                    // Dst: (VTX_READ_GLOBAL_128_eg:v4i32 ADDRVTX_READ:i32:$src_gpr)
/*14374*/         0, // EndSwitchType
/*14375*/       /*Scope*/ 38, /*->14414*/
/*14376*/         OPC_CheckPredicate, 18, // Predicate_load_param
/*14378*/         OPC_SwitchType /*2 cases */, 15,  MVT::v2i32,// ->14396
/*14381*/           OPC_CheckPatternPredicate, 4, // (Subtarget.hasCaymanISA())
/*14383*/           OPC_CheckComplexPat, /*CP*/3, /*#*/1, // SelectADDRVTX_READ:$src_gpr #2 #3
/*14386*/           OPC_EmitMergeInputChains1_0,
/*14387*/           OPC_MorphNodeTo, TARGET_VAL(AMDGPU::VTX_READ_PARAM_64_cm), 0|OPFL_Chain|OPFL_MemRefs,
                        1/*#VTs*/, MVT::v2i32, 2/*#Ops*/, 2, 3, 
                    // Src: (ld:v2i32 ADDRVTX_READ:i32:$src_gpr)<<P:Predicate_unindexedload>><<P:Predicate_load>><<P:Predicate_load_param>> - Complexity = 13
                    // Dst: (VTX_READ_PARAM_64_cm:v2i32 ADDRVTX_READ:i32:$src_gpr)
/*14396*/         /*SwitchType*/ 15,  MVT::v4i32,// ->14413
/*14398*/           OPC_CheckPatternPredicate, 4, // (Subtarget.hasCaymanISA())
/*14400*/           OPC_CheckComplexPat, /*CP*/3, /*#*/1, // SelectADDRVTX_READ:$src_gpr #2 #3
/*14403*/           OPC_EmitMergeInputChains1_0,
/*14404*/           OPC_MorphNodeTo, TARGET_VAL(AMDGPU::VTX_READ_PARAM_128_cm), 0|OPFL_Chain|OPFL_MemRefs,
                        1/*#VTs*/, MVT::v4i32, 2/*#Ops*/, 2, 3, 
                    // Src: (ld:v4i32 ADDRVTX_READ:i32:$src_gpr)<<P:Predicate_unindexedload>><<P:Predicate_load>><<P:Predicate_load_param>> - Complexity = 13
                    // Dst: (VTX_READ_PARAM_128_cm:v4i32 ADDRVTX_READ:i32:$src_gpr)
/*14413*/         0, // EndSwitchType
/*14414*/       /*Scope*/ 38, /*->14453*/
/*14415*/         OPC_CheckPredicate, 21, // Predicate_global_load
/*14417*/         OPC_SwitchType /*2 cases */, 15,  MVT::v2i32,// ->14435
/*14420*/           OPC_CheckPatternPredicate, 4, // (Subtarget.hasCaymanISA())
/*14422*/           OPC_CheckComplexPat, /*CP*/3, /*#*/1, // SelectADDRVTX_READ:$src_gpr #2 #3
/*14425*/           OPC_EmitMergeInputChains1_0,
/*14426*/           OPC_MorphNodeTo, TARGET_VAL(AMDGPU::VTX_READ_GLOBAL_64_cm), 0|OPFL_Chain|OPFL_MemRefs,
                        1/*#VTs*/, MVT::v2i32, 2/*#Ops*/, 2, 3, 
                    // Src: (ld:v2i32 ADDRVTX_READ:i32:$src_gpr)<<P:Predicate_unindexedload>><<P:Predicate_load>><<P:Predicate_global_load>> - Complexity = 13
                    // Dst: (VTX_READ_GLOBAL_64_cm:v2i32 ADDRVTX_READ:i32:$src_gpr)
/*14435*/         /*SwitchType*/ 15,  MVT::v4i32,// ->14452
/*14437*/           OPC_CheckPatternPredicate, 4, // (Subtarget.hasCaymanISA())
/*14439*/           OPC_CheckComplexPat, /*CP*/3, /*#*/1, // SelectADDRVTX_READ:$src_gpr #2 #3
/*14442*/           OPC_EmitMergeInputChains1_0,
/*14443*/           OPC_MorphNodeTo, TARGET_VAL(AMDGPU::VTX_READ_GLOBAL_128_cm), 0|OPFL_Chain|OPFL_MemRefs,
                        1/*#VTs*/, MVT::v4i32, 2/*#Ops*/, 2, 3, 
                    // Src: (ld:v4i32 ADDRVTX_READ:i32:$src_gpr)<<P:Predicate_unindexedload>><<P:Predicate_load>><<P:Predicate_global_load>> - Complexity = 13
                    // Dst: (VTX_READ_GLOBAL_128_cm:v4i32 ADDRVTX_READ:i32:$src_gpr)
/*14452*/         0, // EndSwitchType
/*14453*/       0, /*End of Scope*/
/*14454*/     0, /*End of Scope*/
/*14455*/   /*Scope*/ 73|128,3/*457*/, /*->14914*/
/*14457*/     OPC_MoveChild, 1,
/*14459*/     OPC_CheckOpcode, TARGET_VAL(ISD::ADD),
/*14462*/     OPC_RecordChild0, // #1 = $sbase
/*14463*/     OPC_RecordChild1, // #2 = $offset
/*14464*/     OPC_Scope, 64|128,2/*320*/, /*->14787*/ // 2 children in Scope
/*14467*/       OPC_MoveChild, 1,
/*14469*/       OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*14472*/       OPC_Scope, 107, /*->14581*/ // 3 children in Scope
/*14474*/         OPC_CheckPredicate, 22, // Predicate_IMM8bitDWORD
/*14476*/         OPC_MoveParent,
/*14477*/         OPC_MoveParent,
/*14478*/         OPC_CheckPredicate, 11, // Predicate_unindexedload
/*14480*/         OPC_CheckPredicate, 17, // Predicate_load
/*14482*/         OPC_CheckPredicate, 23, // Predicate_constant_load
/*14484*/         OPC_SwitchType /*5 cases */, 17,  MVT::v2i32,// ->14504
/*14487*/           OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*14489*/           OPC_EmitMergeInputChains1_0,
/*14490*/           OPC_EmitConvertToTarget, 2,
/*14492*/           OPC_EmitNodeXForm, 3, 3, // anonymous.val.459
/*14495*/           OPC_MorphNodeTo, TARGET_VAL(AMDGPU::S_LOAD_DWORDX2_IMM), 0|OPFL_Chain|OPFL_MemRefs,
                        1/*#VTs*/, MVT::v2i32, 2/*#Ops*/, 1, 4, 
                    // Src: (ld:v2i32 (SIadd64bit32bit:i64 i64:i64:$sbase, (imm:i32)<<P:Predicate_IMM8bitDWORD>><<X:anonymous.val.459>>:$offset))<<P:Predicate_unindexedload>><<P:Predicate_load>><<P:Predicate_constant_load>> - Complexity = 11
                    // Dst: (S_LOAD_DWORDX2_IMM:v2i32 ?:i64:$sbase, (anonymous.val.459:i32 (imm:i32)<<P:Predicate_IMM8bitDWORD>>:$offset))
/*14504*/         /*SwitchType*/ 17,  MVT::v4i32,// ->14523
/*14506*/           OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*14508*/           OPC_EmitMergeInputChains1_0,
/*14509*/           OPC_EmitConvertToTarget, 2,
/*14511*/           OPC_EmitNodeXForm, 3, 3, // anonymous.val.459
/*14514*/           OPC_MorphNodeTo, TARGET_VAL(AMDGPU::S_LOAD_DWORDX4_IMM), 0|OPFL_Chain|OPFL_MemRefs,
                        1/*#VTs*/, MVT::v4i32, 2/*#Ops*/, 1, 4, 
                    // Src: (ld:v4i32 (SIadd64bit32bit:i64 i64:i64:$sbase, (imm:i32)<<P:Predicate_IMM8bitDWORD>><<X:anonymous.val.459>>:$offset))<<P:Predicate_unindexedload>><<P:Predicate_load>><<P:Predicate_constant_load>> - Complexity = 11
                    // Dst: (S_LOAD_DWORDX4_IMM:v4i32 ?:i64:$sbase, (anonymous.val.459:i32 (imm:i32)<<P:Predicate_IMM8bitDWORD>>:$offset))
/*14523*/         /*SwitchType*/ 17,  MVT::v32i8,// ->14542
/*14525*/           OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*14527*/           OPC_EmitMergeInputChains1_0,
/*14528*/           OPC_EmitConvertToTarget, 2,
/*14530*/           OPC_EmitNodeXForm, 3, 3, // anonymous.val.459
/*14533*/           OPC_MorphNodeTo, TARGET_VAL(AMDGPU::S_LOAD_DWORDX8_IMM), 0|OPFL_Chain|OPFL_MemRefs,
                        1/*#VTs*/, MVT::v32i8, 2/*#Ops*/, 1, 4, 
                    // Src: (ld:v32i8 (SIadd64bit32bit:i64 i64:i64:$sbase, (imm:i32)<<P:Predicate_IMM8bitDWORD>><<X:anonymous.val.459>>:$offset))<<P:Predicate_unindexedload>><<P:Predicate_load>><<P:Predicate_constant_load>> - Complexity = 11
                    // Dst: (S_LOAD_DWORDX8_IMM:v32i8 ?:i64:$sbase, (anonymous.val.459:i32 (imm:i32)<<P:Predicate_IMM8bitDWORD>>:$offset))
/*14542*/         /*SwitchType*/ 17,  MVT::v8i32,// ->14561
/*14544*/           OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*14546*/           OPC_EmitMergeInputChains1_0,
/*14547*/           OPC_EmitConvertToTarget, 2,
/*14549*/           OPC_EmitNodeXForm, 3, 3, // anonymous.val.459
/*14552*/           OPC_MorphNodeTo, TARGET_VAL(AMDGPU::S_LOAD_DWORDX8_IMM), 0|OPFL_Chain|OPFL_MemRefs,
                        1/*#VTs*/, MVT::v8i32, 2/*#Ops*/, 1, 4, 
                    // Src: (ld:v8i32 (SIadd64bit32bit:i64 i64:i64:$sbase, (imm:i32)<<P:Predicate_IMM8bitDWORD>><<X:anonymous.val.459>>:$offset))<<P:Predicate_unindexedload>><<P:Predicate_load>><<P:Predicate_constant_load>> - Complexity = 11
                    // Dst: (S_LOAD_DWORDX8_IMM:v8i32 ?:i64:$sbase, (anonymous.val.459:i32 (imm:i32)<<P:Predicate_IMM8bitDWORD>>:$offset))
/*14561*/         /*SwitchType*/ 17,  MVT::v16i32,// ->14580
/*14563*/           OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*14565*/           OPC_EmitMergeInputChains1_0,
/*14566*/           OPC_EmitConvertToTarget, 2,
/*14568*/           OPC_EmitNodeXForm, 3, 3, // anonymous.val.459
/*14571*/           OPC_MorphNodeTo, TARGET_VAL(AMDGPU::S_LOAD_DWORDX16_IMM), 0|OPFL_Chain|OPFL_MemRefs,
                        1/*#VTs*/, MVT::v16i32, 2/*#Ops*/, 1, 4, 
                    // Src: (ld:v16i32 (SIadd64bit32bit:i64 i64:i64:$sbase, (imm:i32)<<P:Predicate_IMM8bitDWORD>><<X:anonymous.val.459>>:$offset))<<P:Predicate_unindexedload>><<P:Predicate_load>><<P:Predicate_constant_load>> - Complexity = 11
                    // Dst: (S_LOAD_DWORDX16_IMM:v16i32 ?:i64:$sbase, (anonymous.val.459:i32 (imm:i32)<<P:Predicate_IMM8bitDWORD>>:$offset))
/*14580*/         0, // EndSwitchType
/*14581*/       /*Scope*/ 72, /*->14654*/
/*14582*/         OPC_CheckPredicate, 24, // Predicate_IMM12bit
/*14584*/         OPC_MoveParent,
/*14585*/         OPC_CheckType, MVT::i64,
/*14587*/         OPC_MoveParent,
/*14588*/         OPC_CheckPredicate, 11, // Predicate_unindexedload
/*14590*/         OPC_CheckPredicate, 17, // Predicate_load
/*14592*/         OPC_CheckPredicate, 21, // Predicate_global_load
/*14594*/         OPC_SwitchType /*2 cases */, 27,  MVT::v2i32,// ->14624
/*14597*/           OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*14599*/           OPC_EmitMergeInputChains1_0,
/*14600*/           OPC_EmitInteger, MVT::i64, 0, 
/*14603*/           OPC_EmitNode, TARGET_VAL(AMDGPU::SI_ADDR64_RSRC), 0|OPFL_Chain,
                        1/*#VTs*/, MVT::i128, 1/*#Ops*/, 3,  // Results = #4
/*14611*/           OPC_EmitNodeXForm, 0, 2, // as_i16imm
/*14614*/           OPC_MorphNodeTo, TARGET_VAL(AMDGPU::BUFFER_LOAD_DWORDX2_ADDR64), 0|OPFL_Chain|OPFL_MemRefs,
                        1/*#VTs*/, MVT::v2i32, 3/*#Ops*/, 4, 1, 5, 
                    // Src: (ld:v2i32 (add:i64 i64:i64:$ptr, (imm:i64)<<P:Predicate_IMM12bit>>:$offset))<<P:Predicate_unindexedload>><<P:Predicate_load>><<P:Predicate_global_load>> - Complexity = 11
                    // Dst: (BUFFER_LOAD_DWORDX2_ADDR64:v2i32 (SI_ADDR64_RSRC:i128 0:i64), ?:i64:$ptr, (as_i16imm:i16 ?:i64:$offset))
/*14624*/         /*SwitchType*/ 27,  MVT::v4i32,// ->14653
/*14626*/           OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*14628*/           OPC_EmitMergeInputChains1_0,
/*14629*/           OPC_EmitInteger, MVT::i64, 0, 
/*14632*/           OPC_EmitNode, TARGET_VAL(AMDGPU::SI_ADDR64_RSRC), 0|OPFL_Chain,
                        1/*#VTs*/, MVT::i128, 1/*#Ops*/, 3,  // Results = #4
/*14640*/           OPC_EmitNodeXForm, 0, 2, // as_i16imm
/*14643*/           OPC_MorphNodeTo, TARGET_VAL(AMDGPU::BUFFER_LOAD_DWORDX4_ADDR64), 0|OPFL_Chain|OPFL_MemRefs,
                        1/*#VTs*/, MVT::v4i32, 3/*#Ops*/, 4, 1, 5, 
                    // Src: (ld:v4i32 (add:i64 i64:i64:$ptr, (imm:i64)<<P:Predicate_IMM12bit>>:$offset))<<P:Predicate_unindexedload>><<P:Predicate_load>><<P:Predicate_global_load>> - Complexity = 11
                    // Dst: (BUFFER_LOAD_DWORDX4_ADDR64:v4i32 (SI_ADDR64_RSRC:i128 0:i64), ?:i64:$ptr, (as_i16imm:i16 ?:i64:$offset))
/*14653*/         0, // EndSwitchType
/*14654*/       /*Scope*/ 2|128,1/*130*/, /*->14786*/
/*14656*/         OPC_MoveParent,
/*14657*/         OPC_MoveParent,
/*14658*/         OPC_CheckPredicate, 11, // Predicate_unindexedload
/*14660*/         OPC_CheckPredicate, 17, // Predicate_load
/*14662*/         OPC_CheckPredicate, 23, // Predicate_constant_load
/*14664*/         OPC_SwitchType /*5 cases */, 22,  MVT::v2i32,// ->14689
/*14667*/           OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*14669*/           OPC_EmitMergeInputChains1_0,
/*14670*/           OPC_EmitConvertToTarget, 2,
/*14672*/           OPC_EmitNode, TARGET_VAL(AMDGPU::S_MOV_B32), 0,
                        1/*#VTs*/, MVT::i32, 1/*#Ops*/, 3,  // Results = #4
/*14680*/           OPC_MorphNodeTo, TARGET_VAL(AMDGPU::S_LOAD_DWORDX2_SGPR), 0|OPFL_Chain|OPFL_MemRefs,
                        1/*#VTs*/, MVT::v2i32, 2/*#Ops*/, 1, 4, 
                    // Src: (ld:v2i32 (SIadd64bit32bit:i64 i64:i64:$sbase, (imm:i32):$offset))<<P:Predicate_unindexedload>><<P:Predicate_load>><<P:Predicate_constant_load>> - Complexity = 10
                    // Dst: (S_LOAD_DWORDX2_SGPR:v2i32 ?:i64:$sbase, (S_MOV_B32:i32 (imm:i32):$offset))
/*14689*/         /*SwitchType*/ 22,  MVT::v4i32,// ->14713
/*14691*/           OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*14693*/           OPC_EmitMergeInputChains1_0,
/*14694*/           OPC_EmitConvertToTarget, 2,
/*14696*/           OPC_EmitNode, TARGET_VAL(AMDGPU::S_MOV_B32), 0,
                        1/*#VTs*/, MVT::i32, 1/*#Ops*/, 3,  // Results = #4
/*14704*/           OPC_MorphNodeTo, TARGET_VAL(AMDGPU::S_LOAD_DWORDX4_SGPR), 0|OPFL_Chain|OPFL_MemRefs,
                        1/*#VTs*/, MVT::v4i32, 2/*#Ops*/, 1, 4, 
                    // Src: (ld:v4i32 (SIadd64bit32bit:i64 i64:i64:$sbase, (imm:i32):$offset))<<P:Predicate_unindexedload>><<P:Predicate_load>><<P:Predicate_constant_load>> - Complexity = 10
                    // Dst: (S_LOAD_DWORDX4_SGPR:v4i32 ?:i64:$sbase, (S_MOV_B32:i32 (imm:i32):$offset))
/*14713*/         /*SwitchType*/ 22,  MVT::v32i8,// ->14737
/*14715*/           OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*14717*/           OPC_EmitMergeInputChains1_0,
/*14718*/           OPC_EmitConvertToTarget, 2,
/*14720*/           OPC_EmitNode, TARGET_VAL(AMDGPU::S_MOV_B32), 0,
                        1/*#VTs*/, MVT::i32, 1/*#Ops*/, 3,  // Results = #4
/*14728*/           OPC_MorphNodeTo, TARGET_VAL(AMDGPU::S_LOAD_DWORDX8_SGPR), 0|OPFL_Chain|OPFL_MemRefs,
                        1/*#VTs*/, MVT::v32i8, 2/*#Ops*/, 1, 4, 
                    // Src: (ld:v32i8 (SIadd64bit32bit:i64 i64:i64:$sbase, (imm:i32):$offset))<<P:Predicate_unindexedload>><<P:Predicate_load>><<P:Predicate_constant_load>> - Complexity = 10
                    // Dst: (S_LOAD_DWORDX8_SGPR:v32i8 ?:i64:$sbase, (S_MOV_B32:i32 (imm:i32):$offset))
/*14737*/         /*SwitchType*/ 22,  MVT::v8i32,// ->14761
/*14739*/           OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*14741*/           OPC_EmitMergeInputChains1_0,
/*14742*/           OPC_EmitConvertToTarget, 2,
/*14744*/           OPC_EmitNode, TARGET_VAL(AMDGPU::S_MOV_B32), 0,
                        1/*#VTs*/, MVT::i32, 1/*#Ops*/, 3,  // Results = #4
/*14752*/           OPC_MorphNodeTo, TARGET_VAL(AMDGPU::S_LOAD_DWORDX8_SGPR), 0|OPFL_Chain|OPFL_MemRefs,
                        1/*#VTs*/, MVT::v8i32, 2/*#Ops*/, 1, 4, 
                    // Src: (ld:v8i32 (SIadd64bit32bit:i64 i64:i64:$sbase, (imm:i32):$offset))<<P:Predicate_unindexedload>><<P:Predicate_load>><<P:Predicate_constant_load>> - Complexity = 10
                    // Dst: (S_LOAD_DWORDX8_SGPR:v8i32 ?:i64:$sbase, (S_MOV_B32:i32 (imm:i32):$offset))
/*14761*/         /*SwitchType*/ 22,  MVT::v16i32,// ->14785
/*14763*/           OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*14765*/           OPC_EmitMergeInputChains1_0,
/*14766*/           OPC_EmitConvertToTarget, 2,
/*14768*/           OPC_EmitNode, TARGET_VAL(AMDGPU::S_MOV_B32), 0,
                        1/*#VTs*/, MVT::i32, 1/*#Ops*/, 3,  // Results = #4
/*14776*/           OPC_MorphNodeTo, TARGET_VAL(AMDGPU::S_LOAD_DWORDX16_SGPR), 0|OPFL_Chain|OPFL_MemRefs,
                        1/*#VTs*/, MVT::v16i32, 2/*#Ops*/, 1, 4, 
                    // Src: (ld:v16i32 (SIadd64bit32bit:i64 i64:i64:$sbase, (imm:i32):$offset))<<P:Predicate_unindexedload>><<P:Predicate_load>><<P:Predicate_constant_load>> - Complexity = 10
                    // Dst: (S_LOAD_DWORDX16_SGPR:v16i32 ?:i64:$sbase, (S_MOV_B32:i32 (imm:i32):$offset))
/*14785*/         0, // EndSwitchType
/*14786*/       0, /*End of Scope*/
/*14787*/     /*Scope*/ 125, /*->14913*/
/*14788*/       OPC_CheckType, MVT::i64,
/*14790*/       OPC_MoveParent,
/*14791*/       OPC_CheckPredicate, 11, // Predicate_unindexedload
/*14793*/       OPC_CheckPredicate, 17, // Predicate_load
/*14795*/       OPC_SwitchType /*2 cases */, 56,  MVT::v2i32,// ->14854
/*14798*/         OPC_Scope, 26, /*->14826*/ // 2 children in Scope
/*14800*/           OPC_CheckPredicate, 21, // Predicate_global_load
/*14802*/           OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*14804*/           OPC_EmitMergeInputChains1_0,
/*14805*/           OPC_EmitNode, TARGET_VAL(AMDGPU::SI_ADDR64_RSRC), 0|OPFL_Chain,
                        1/*#VTs*/, MVT::i128, 1/*#Ops*/, 1,  // Results = #3
/*14813*/           OPC_EmitInteger, MVT::i16, 0, 
/*14816*/           OPC_MorphNodeTo, TARGET_VAL(AMDGPU::BUFFER_LOAD_DWORDX2_ADDR64), 0|OPFL_Chain|OPFL_MemRefs,
                        1/*#VTs*/, MVT::v2i32, 3/*#Ops*/, 3, 2, 4, 
                    // Src: (ld:v2i32 (add:i64 i64:i64:$ptr, i64:i64:$offset))<<P:Predicate_unindexedload>><<P:Predicate_load>><<P:Predicate_global_load>> - Complexity = 7
                    // Dst: (BUFFER_LOAD_DWORDX2_ADDR64:v2i32 (SI_ADDR64_RSRC:i128 ?:i64:$ptr), ?:i64:$offset, 0:i16)
/*14826*/         /*Scope*/ 26, /*->14853*/
/*14827*/           OPC_CheckPredicate, 23, // Predicate_constant_load
/*14829*/           OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*14831*/           OPC_EmitMergeInputChains1_0,
/*14832*/           OPC_EmitNode, TARGET_VAL(AMDGPU::SI_ADDR64_RSRC), 0|OPFL_Chain,
                        1/*#VTs*/, MVT::i128, 1/*#Ops*/, 1,  // Results = #3
/*14840*/           OPC_EmitInteger, MVT::i16, 0, 
/*14843*/           OPC_MorphNodeTo, TARGET_VAL(AMDGPU::BUFFER_LOAD_DWORDX2_ADDR64), 0|OPFL_Chain|OPFL_MemRefs,
                        1/*#VTs*/, MVT::v2i32, 3/*#Ops*/, 3, 2, 4, 
                    // Src: (ld:v2i32 (add:i64 i64:i64:$ptr, i64:i64:$offset))<<P:Predicate_unindexedload>><<P:Predicate_load>><<P:Predicate_constant_load>> - Complexity = 7
                    // Dst: (BUFFER_LOAD_DWORDX2_ADDR64:v2i32 (SI_ADDR64_RSRC:i128 ?:i64:$ptr), ?:i64:$offset, 0:i16)
/*14853*/         0, /*End of Scope*/
/*14854*/       /*SwitchType*/ 56,  MVT::v4i32,// ->14912
/*14856*/         OPC_Scope, 26, /*->14884*/ // 2 children in Scope
/*14858*/           OPC_CheckPredicate, 21, // Predicate_global_load
/*14860*/           OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*14862*/           OPC_EmitMergeInputChains1_0,
/*14863*/           OPC_EmitNode, TARGET_VAL(AMDGPU::SI_ADDR64_RSRC), 0|OPFL_Chain,
                        1/*#VTs*/, MVT::i128, 1/*#Ops*/, 1,  // Results = #3
/*14871*/           OPC_EmitInteger, MVT::i16, 0, 
/*14874*/           OPC_MorphNodeTo, TARGET_VAL(AMDGPU::BUFFER_LOAD_DWORDX4_ADDR64), 0|OPFL_Chain|OPFL_MemRefs,
                        1/*#VTs*/, MVT::v4i32, 3/*#Ops*/, 3, 2, 4, 
                    // Src: (ld:v4i32 (add:i64 i64:i64:$ptr, i64:i64:$offset))<<P:Predicate_unindexedload>><<P:Predicate_load>><<P:Predicate_global_load>> - Complexity = 7
                    // Dst: (BUFFER_LOAD_DWORDX4_ADDR64:v4i32 (SI_ADDR64_RSRC:i128 ?:i64:$ptr), ?:i64:$offset, 0:i16)
/*14884*/         /*Scope*/ 26, /*->14911*/
/*14885*/           OPC_CheckPredicate, 23, // Predicate_constant_load
/*14887*/           OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*14889*/           OPC_EmitMergeInputChains1_0,
/*14890*/           OPC_EmitNode, TARGET_VAL(AMDGPU::SI_ADDR64_RSRC), 0|OPFL_Chain,
                        1/*#VTs*/, MVT::i128, 1/*#Ops*/, 1,  // Results = #3
/*14898*/           OPC_EmitInteger, MVT::i16, 0, 
/*14901*/           OPC_MorphNodeTo, TARGET_VAL(AMDGPU::BUFFER_LOAD_DWORDX4_ADDR64), 0|OPFL_Chain|OPFL_MemRefs,
                        1/*#VTs*/, MVT::v4i32, 3/*#Ops*/, 3, 2, 4, 
                    // Src: (ld:v4i32 (add:i64 i64:i64:$ptr, i64:i64:$offset))<<P:Predicate_unindexedload>><<P:Predicate_load>><<P:Predicate_constant_load>> - Complexity = 7
                    // Dst: (BUFFER_LOAD_DWORDX4_ADDR64:v4i32 (SI_ADDR64_RSRC:i128 ?:i64:$ptr), ?:i64:$offset, 0:i16)
/*14911*/         0, /*End of Scope*/
/*14912*/       0, // EndSwitchType
/*14913*/     0, /*End of Scope*/
/*14914*/   /*Scope*/ 34|128,1/*162*/, /*->15078*/
/*14916*/     OPC_RecordChild1, // #1 = $sbase
/*14917*/     OPC_CheckChild1Type, MVT::i64,
/*14919*/     OPC_CheckPredicate, 11, // Predicate_unindexedload
/*14921*/     OPC_CheckPredicate, 17, // Predicate_load
/*14923*/     OPC_Scope, 89, /*->15014*/ // 2 children in Scope
/*14925*/       OPC_CheckPredicate, 23, // Predicate_constant_load
/*14927*/       OPC_SwitchType /*5 cases */, 15,  MVT::v2i32,// ->14945
/*14930*/         OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*14932*/         OPC_EmitMergeInputChains1_0,
/*14933*/         OPC_EmitInteger, MVT::i32, 0, 
/*14936*/         OPC_MorphNodeTo, TARGET_VAL(AMDGPU::S_LOAD_DWORDX2_IMM), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::v2i32, 2/*#Ops*/, 1, 2, 
                  // Src: (ld:v2i32 i64:i64:$sbase)<<P:Predicate_unindexedload>><<P:Predicate_load>><<P:Predicate_constant_load>> - Complexity = 4
                  // Dst: (S_LOAD_DWORDX2_IMM:v2i32 ?:i64:$sbase, 0:i32)
/*14945*/       /*SwitchType*/ 15,  MVT::v4i32,// ->14962
/*14947*/         OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*14949*/         OPC_EmitMergeInputChains1_0,
/*14950*/         OPC_EmitInteger, MVT::i32, 0, 
/*14953*/         OPC_MorphNodeTo, TARGET_VAL(AMDGPU::S_LOAD_DWORDX4_IMM), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::v4i32, 2/*#Ops*/, 1, 2, 
                  // Src: (ld:v4i32 i64:i64:$sbase)<<P:Predicate_unindexedload>><<P:Predicate_load>><<P:Predicate_constant_load>> - Complexity = 4
                  // Dst: (S_LOAD_DWORDX4_IMM:v4i32 ?:i64:$sbase, 0:i32)
/*14962*/       /*SwitchType*/ 15,  MVT::v32i8,// ->14979
/*14964*/         OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*14966*/         OPC_EmitMergeInputChains1_0,
/*14967*/         OPC_EmitInteger, MVT::i32, 0, 
/*14970*/         OPC_MorphNodeTo, TARGET_VAL(AMDGPU::S_LOAD_DWORDX8_IMM), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::v32i8, 2/*#Ops*/, 1, 2, 
                  // Src: (ld:v32i8 i64:i64:$sbase)<<P:Predicate_unindexedload>><<P:Predicate_load>><<P:Predicate_constant_load>> - Complexity = 4
                  // Dst: (S_LOAD_DWORDX8_IMM:v32i8 ?:i64:$sbase, 0:i32)
/*14979*/       /*SwitchType*/ 15,  MVT::v8i32,// ->14996
/*14981*/         OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*14983*/         OPC_EmitMergeInputChains1_0,
/*14984*/         OPC_EmitInteger, MVT::i32, 0, 
/*14987*/         OPC_MorphNodeTo, TARGET_VAL(AMDGPU::S_LOAD_DWORDX8_IMM), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::v8i32, 2/*#Ops*/, 1, 2, 
                  // Src: (ld:v8i32 i64:i64:$sbase)<<P:Predicate_unindexedload>><<P:Predicate_load>><<P:Predicate_constant_load>> - Complexity = 4
                  // Dst: (S_LOAD_DWORDX8_IMM:v8i32 ?:i64:$sbase, 0:i32)
/*14996*/       /*SwitchType*/ 15,  MVT::v16i32,// ->15013
/*14998*/         OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*15000*/         OPC_EmitMergeInputChains1_0,
/*15001*/         OPC_EmitInteger, MVT::i32, 0, 
/*15004*/         OPC_MorphNodeTo, TARGET_VAL(AMDGPU::S_LOAD_DWORDX16_IMM), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::v16i32, 2/*#Ops*/, 1, 2, 
                  // Src: (ld:v16i32 i64:i64:$sbase)<<P:Predicate_unindexedload>><<P:Predicate_load>><<P:Predicate_constant_load>> - Complexity = 4
                  // Dst: (S_LOAD_DWORDX16_IMM:v16i32 ?:i64:$sbase, 0:i32)
/*15013*/       0, // EndSwitchType
/*15014*/     /*Scope*/ 62, /*->15077*/
/*15015*/       OPC_CheckPredicate, 21, // Predicate_global_load
/*15017*/       OPC_SwitchType /*2 cases */, 27,  MVT::v2i32,// ->15047
/*15020*/         OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*15022*/         OPC_EmitMergeInputChains1_0,
/*15023*/         OPC_EmitInteger, MVT::i64, 0, 
/*15026*/         OPC_EmitNode, TARGET_VAL(AMDGPU::SI_ADDR64_RSRC), 0|OPFL_Chain,
                      1/*#VTs*/, MVT::i128, 1/*#Ops*/, 2,  // Results = #3
/*15034*/         OPC_EmitInteger, MVT::i16, 0, 
/*15037*/         OPC_MorphNodeTo, TARGET_VAL(AMDGPU::BUFFER_LOAD_DWORDX2_ADDR64), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::v2i32, 3/*#Ops*/, 3, 1, 4, 
                  // Src: (ld:v2i32 i64:i64:$ptr)<<P:Predicate_unindexedload>><<P:Predicate_load>><<P:Predicate_global_load>> - Complexity = 4
                  // Dst: (BUFFER_LOAD_DWORDX2_ADDR64:v2i32 (SI_ADDR64_RSRC:i128 0:i64), ?:i64:$ptr, 0:i16)
/*15047*/       /*SwitchType*/ 27,  MVT::v4i32,// ->15076
/*15049*/         OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*15051*/         OPC_EmitMergeInputChains1_0,
/*15052*/         OPC_EmitInteger, MVT::i64, 0, 
/*15055*/         OPC_EmitNode, TARGET_VAL(AMDGPU::SI_ADDR64_RSRC), 0|OPFL_Chain,
                      1/*#VTs*/, MVT::i128, 1/*#Ops*/, 2,  // Results = #3
/*15063*/         OPC_EmitInteger, MVT::i16, 0, 
/*15066*/         OPC_MorphNodeTo, TARGET_VAL(AMDGPU::BUFFER_LOAD_DWORDX4_ADDR64), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::v4i32, 3/*#Ops*/, 3, 1, 4, 
                  // Src: (ld:v4i32 i64:i64:$ptr)<<P:Predicate_unindexedload>><<P:Predicate_load>><<P:Predicate_global_load>> - Complexity = 4
                  // Dst: (BUFFER_LOAD_DWORDX4_ADDR64:v4i32 (SI_ADDR64_RSRC:i128 0:i64), ?:i64:$ptr, 0:i16)
/*15076*/       0, // EndSwitchType
/*15077*/     0, /*End of Scope*/
/*15078*/   0, /*End of Scope*/
/*15079*/ /*SwitchOpcode*/ 57|128,11/*1465*/,  TARGET_VAL(ISD::XOR),// ->16548
/*15083*/   OPC_Scope, 20|128,2/*276*/, /*->15362*/ // 5 children in Scope
/*15086*/     OPC_RecordChild0, // #0 = $z
/*15087*/     OPC_MoveChild, 1,
/*15089*/     OPC_CheckOpcode, TARGET_VAL(ISD::AND),
/*15092*/     OPC_Scope, 56|128,1/*184*/, /*->15279*/ // 2 children in Scope
/*15095*/       OPC_RecordChild0, // #1 = $x
/*15096*/       OPC_MoveChild, 1,
/*15098*/       OPC_CheckOpcode, TARGET_VAL(ISD::XOR),
/*15101*/       OPC_Scope, 10|128,1/*138*/, /*->15242*/ // 2 children in Scope
/*15104*/         OPC_RecordChild0, // #2 = $y
/*15105*/         OPC_CheckChild1Same, 0,
/*15107*/         OPC_MoveParent,
/*15108*/         OPC_MoveParent,
/*15109*/         OPC_CheckType, MVT::i32,
/*15111*/         OPC_Scope, 99, /*->15212*/ // 2 children in Scope
/*15113*/           OPC_CheckPatternPredicate, 2, // (Subtarget.getGeneration() == AMDGPUSubtarget::EVERGREEN|| Subtarget.getGeneration() ==AMDGPUSubtarget::NORTHERN_ISLANDS)
/*15115*/           OPC_EmitInteger, MVT::i32, 0, 
/*15118*/           OPC_EmitInteger, MVT::i32, 0, 
/*15121*/           OPC_EmitInteger, MVT::i32, 0, 
/*15124*/           OPC_EmitInteger, MVT::i32, 0, 
/*15127*/           OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*15139*/           OPC_EmitInteger, MVT::i32, 0, 
/*15142*/           OPC_EmitInteger, MVT::i32, 0, 
/*15145*/           OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*15157*/           OPC_EmitInteger, MVT::i32, 0, 
/*15160*/           OPC_EmitInteger, MVT::i32, 0, 
/*15163*/           OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*15175*/           OPC_EmitInteger, MVT::i32, 1, 
/*15178*/           OPC_EmitRegister, MVT::i32, AMDGPU::PRED_SEL_OFF,
/*15181*/           OPC_EmitInteger, MVT::i32, 0, 
/*15184*/           OPC_EmitInteger, MVT::i32, 0, 
/*15187*/           OPC_MorphNodeTo, TARGET_VAL(AMDGPU::BFI_INT_eg), 0,
                        1/*#VTs*/, MVT::i32, 18/*#Ops*/, 3, 4, 1, 5, 6, 7, 2, 8, 9, 10, 0, 11, 12, 13, 14, 15, 16, 17, 
                    // Src: (xor:i32 i32:i32:$z, (and:i32 i32:i32:$x, (xor:i32 i32:i32:$y, i32:i32:$z))) - Complexity = 9
                    // Dst: (BFI_INT_eg:i32 ?:i32:$x, ?:i32:$y, ?:i32:$z)
/*15212*/         /*Scope*/ 28, /*->15241*/
/*15213*/           OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*15215*/           OPC_EmitInteger, MVT::i32, 0, 
/*15218*/           OPC_EmitInteger, MVT::i32, 0, 
/*15221*/           OPC_EmitInteger, MVT::i32, 0, 
/*15224*/           OPC_EmitInteger, MVT::i32, 0, 
/*15227*/           OPC_MorphNodeTo, TARGET_VAL(AMDGPU::V_BFI_B32), 0,
                        1/*#VTs*/, MVT::i32, 7/*#Ops*/, 1, 2, 0, 3, 4, 5, 6, 
                    // Src: (xor:i32 i32:i32:$z, (and:i32 i32:i32:$x, (xor:i32 i32:i32:$y, i32:i32:$z))) - Complexity = 9
                    // Dst: (V_BFI_B32:i32 ?:i32:$x, ?:i32:$y, ?:i32:$z)
/*15241*/         0, /*End of Scope*/
/*15242*/       /*Scope*/ 35, /*->15278*/
/*15243*/         OPC_CheckChild0Same, 0,
/*15245*/         OPC_RecordChild1, // #2 = $y
/*15246*/         OPC_MoveParent,
/*15247*/         OPC_MoveParent,
/*15248*/         OPC_CheckType, MVT::i32,
/*15250*/         OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*15252*/         OPC_EmitInteger, MVT::i32, 0, 
/*15255*/         OPC_EmitInteger, MVT::i32, 0, 
/*15258*/         OPC_EmitInteger, MVT::i32, 0, 
/*15261*/         OPC_EmitInteger, MVT::i32, 0, 
/*15264*/         OPC_MorphNodeTo, TARGET_VAL(AMDGPU::V_BFI_B32), 0,
                      1/*#VTs*/, MVT::i32, 7/*#Ops*/, 1, 2, 0, 3, 4, 5, 6, 
                  // Src: (xor:i32 i32:i32:$z, (and:i32 i32:i32:$x, (xor:i32 i32:i32:$z, i32:i32:$y))) - Complexity = 9
                  // Dst: (V_BFI_B32:i32 ?:i32:$x, ?:i32:$y, ?:i32:$z)
/*15278*/       0, /*End of Scope*/
/*15279*/     /*Scope*/ 81, /*->15361*/
/*15280*/       OPC_MoveChild, 0,
/*15282*/       OPC_CheckOpcode, TARGET_VAL(ISD::XOR),
/*15285*/       OPC_Scope, 36, /*->15323*/ // 2 children in Scope
/*15287*/         OPC_RecordChild0, // #1 = $y
/*15288*/         OPC_CheckChild1Same, 0,
/*15290*/         OPC_MoveParent,
/*15291*/         OPC_RecordChild1, // #2 = $x
/*15292*/         OPC_MoveParent,
/*15293*/         OPC_CheckType, MVT::i32,
/*15295*/         OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*15297*/         OPC_EmitInteger, MVT::i32, 0, 
/*15300*/         OPC_EmitInteger, MVT::i32, 0, 
/*15303*/         OPC_EmitInteger, MVT::i32, 0, 
/*15306*/         OPC_EmitInteger, MVT::i32, 0, 
/*15309*/         OPC_MorphNodeTo, TARGET_VAL(AMDGPU::V_BFI_B32), 0,
                      1/*#VTs*/, MVT::i32, 7/*#Ops*/, 2, 1, 0, 3, 4, 5, 6, 
                  // Src: (xor:i32 i32:i32:$z, (and:i32 (xor:i32 i32:i32:$y, i32:i32:$z), i32:i32:$x)) - Complexity = 9
                  // Dst: (V_BFI_B32:i32 ?:i32:$x, ?:i32:$y, ?:i32:$z)
/*15323*/       /*Scope*/ 36, /*->15360*/
/*15324*/         OPC_CheckChild0Same, 0,
/*15326*/         OPC_RecordChild1, // #1 = $y
/*15327*/         OPC_MoveParent,
/*15328*/         OPC_RecordChild1, // #2 = $x
/*15329*/         OPC_MoveParent,
/*15330*/         OPC_CheckType, MVT::i32,
/*15332*/         OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*15334*/         OPC_EmitInteger, MVT::i32, 0, 
/*15337*/         OPC_EmitInteger, MVT::i32, 0, 
/*15340*/         OPC_EmitInteger, MVT::i32, 0, 
/*15343*/         OPC_EmitInteger, MVT::i32, 0, 
/*15346*/         OPC_MorphNodeTo, TARGET_VAL(AMDGPU::V_BFI_B32), 0,
                      1/*#VTs*/, MVT::i32, 7/*#Ops*/, 2, 1, 0, 3, 4, 5, 6, 
                  // Src: (xor:i32 i32:i32:$z, (and:i32 (xor:i32 i32:i32:$z, i32:i32:$y), i32:i32:$x)) - Complexity = 9
                  // Dst: (V_BFI_B32:i32 ?:i32:$x, ?:i32:$y, ?:i32:$z)
/*15360*/       0, /*End of Scope*/
/*15361*/     0, /*End of Scope*/
/*15362*/   /*Scope*/ 33|128,1/*161*/, /*->15525*/
/*15364*/     OPC_MoveChild, 0,
/*15366*/     OPC_CheckOpcode, TARGET_VAL(ISD::AND),
/*15369*/     OPC_Scope, 76, /*->15447*/ // 2 children in Scope
/*15371*/       OPC_RecordChild0, // #0 = $x
/*15372*/       OPC_MoveChild, 1,
/*15374*/       OPC_CheckOpcode, TARGET_VAL(ISD::XOR),
/*15377*/       OPC_RecordChild0, // #1 = $y
/*15378*/       OPC_RecordChild1, // #2 = $z
/*15379*/       OPC_MoveParent,
/*15380*/       OPC_MoveParent,
/*15381*/       OPC_CheckType, MVT::i32,
/*15383*/       OPC_Scope, 30, /*->15415*/ // 2 children in Scope
/*15385*/         OPC_CheckChild1Same, 2,
/*15387*/         OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*15389*/         OPC_EmitInteger, MVT::i32, 0, 
/*15392*/         OPC_EmitInteger, MVT::i32, 0, 
/*15395*/         OPC_EmitInteger, MVT::i32, 0, 
/*15398*/         OPC_EmitInteger, MVT::i32, 0, 
/*15401*/         OPC_MorphNodeTo, TARGET_VAL(AMDGPU::V_BFI_B32), 0,
                      1/*#VTs*/, MVT::i32, 7/*#Ops*/, 0, 1, 2, 3, 4, 5, 6, 
                  // Src: (xor:i32 (and:i32 i32:i32:$x, (xor:i32 i32:i32:$y, i32:i32:$z)), i32:i32:$z) - Complexity = 9
                  // Dst: (V_BFI_B32:i32 ?:i32:$x, ?:i32:$y, ?:i32:$z)
/*15415*/       /*Scope*/ 30, /*->15446*/
/*15416*/         OPC_CheckChild1Same, 1,
/*15418*/         OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*15420*/         OPC_EmitInteger, MVT::i32, 0, 
/*15423*/         OPC_EmitInteger, MVT::i32, 0, 
/*15426*/         OPC_EmitInteger, MVT::i32, 0, 
/*15429*/         OPC_EmitInteger, MVT::i32, 0, 
/*15432*/         OPC_MorphNodeTo, TARGET_VAL(AMDGPU::V_BFI_B32), 0,
                      1/*#VTs*/, MVT::i32, 7/*#Ops*/, 0, 2, 1, 3, 4, 5, 6, 
                  // Src: (xor:i32 (and:i32 i32:i32:$x, (xor:i32 i32:i32:$z, i32:i32:$y)), i32:i32:$z) - Complexity = 9
                  // Dst: (V_BFI_B32:i32 ?:i32:$x, ?:i32:$y, ?:i32:$z)
/*15446*/       0, /*End of Scope*/
/*15447*/     /*Scope*/ 76, /*->15524*/
/*15448*/       OPC_MoveChild, 0,
/*15450*/       OPC_CheckOpcode, TARGET_VAL(ISD::XOR),
/*15453*/       OPC_RecordChild0, // #0 = $y
/*15454*/       OPC_RecordChild1, // #1 = $z
/*15455*/       OPC_MoveParent,
/*15456*/       OPC_RecordChild1, // #2 = $x
/*15457*/       OPC_MoveParent,
/*15458*/       OPC_CheckType, MVT::i32,
/*15460*/       OPC_Scope, 30, /*->15492*/ // 2 children in Scope
/*15462*/         OPC_CheckChild1Same, 1,
/*15464*/         OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*15466*/         OPC_EmitInteger, MVT::i32, 0, 
/*15469*/         OPC_EmitInteger, MVT::i32, 0, 
/*15472*/         OPC_EmitInteger, MVT::i32, 0, 
/*15475*/         OPC_EmitInteger, MVT::i32, 0, 
/*15478*/         OPC_MorphNodeTo, TARGET_VAL(AMDGPU::V_BFI_B32), 0,
                      1/*#VTs*/, MVT::i32, 7/*#Ops*/, 2, 0, 1, 3, 4, 5, 6, 
                  // Src: (xor:i32 (and:i32 (xor:i32 i32:i32:$y, i32:i32:$z), i32:i32:$x), i32:i32:$z) - Complexity = 9
                  // Dst: (V_BFI_B32:i32 ?:i32:$x, ?:i32:$y, ?:i32:$z)
/*15492*/       /*Scope*/ 30, /*->15523*/
/*15493*/         OPC_CheckChild1Same, 0,
/*15495*/         OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*15497*/         OPC_EmitInteger, MVT::i32, 0, 
/*15500*/         OPC_EmitInteger, MVT::i32, 0, 
/*15503*/         OPC_EmitInteger, MVT::i32, 0, 
/*15506*/         OPC_EmitInteger, MVT::i32, 0, 
/*15509*/         OPC_MorphNodeTo, TARGET_VAL(AMDGPU::V_BFI_B32), 0,
                      1/*#VTs*/, MVT::i32, 7/*#Ops*/, 2, 1, 0, 3, 4, 5, 6, 
                  // Src: (xor:i32 (and:i32 (xor:i32 i32:i32:$z, i32:i32:$y), i32:i32:$x), i32:i32:$z) - Complexity = 9
                  // Dst: (V_BFI_B32:i32 ?:i32:$x, ?:i32:$y, ?:i32:$z)
/*15523*/       0, /*End of Scope*/
/*15524*/     0, /*End of Scope*/
/*15525*/   /*Scope*/ 90|128,2/*346*/, /*->15873*/
/*15527*/     OPC_RecordChild0, // #0 = $z
/*15528*/     OPC_MoveChild, 1,
/*15530*/     OPC_CheckOpcode, TARGET_VAL(ISD::AND),
/*15533*/     OPC_Scope, 112, /*->15647*/ // 2 children in Scope
/*15535*/       OPC_RecordChild0, // #1 = $x
/*15536*/       OPC_MoveChild, 1,
/*15538*/       OPC_CheckOpcode, TARGET_VAL(ISD::XOR),
/*15541*/       OPC_CheckChild0Same, 0,
/*15543*/       OPC_RecordChild1, // #2 = $y
/*15544*/       OPC_MoveParent,
/*15545*/       OPC_MoveParent,
/*15546*/       OPC_CheckType, MVT::i32,
/*15548*/       OPC_CheckPatternPredicate, 2, // (Subtarget.getGeneration() == AMDGPUSubtarget::EVERGREEN|| Subtarget.getGeneration() ==AMDGPUSubtarget::NORTHERN_ISLANDS)
/*15550*/       OPC_EmitInteger, MVT::i32, 0, 
/*15553*/       OPC_EmitInteger, MVT::i32, 0, 
/*15556*/       OPC_EmitInteger, MVT::i32, 0, 
/*15559*/       OPC_EmitInteger, MVT::i32, 0, 
/*15562*/       OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*15574*/       OPC_EmitInteger, MVT::i32, 0, 
/*15577*/       OPC_EmitInteger, MVT::i32, 0, 
/*15580*/       OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*15592*/       OPC_EmitInteger, MVT::i32, 0, 
/*15595*/       OPC_EmitInteger, MVT::i32, 0, 
/*15598*/       OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*15610*/       OPC_EmitInteger, MVT::i32, 1, 
/*15613*/       OPC_EmitRegister, MVT::i32, AMDGPU::PRED_SEL_OFF,
/*15616*/       OPC_EmitInteger, MVT::i32, 0, 
/*15619*/       OPC_EmitInteger, MVT::i32, 0, 
/*15622*/       OPC_MorphNodeTo, TARGET_VAL(AMDGPU::BFI_INT_eg), 0,
                    1/*#VTs*/, MVT::i32, 18/*#Ops*/, 3, 4, 1, 5, 6, 7, 2, 8, 9, 10, 0, 11, 12, 13, 14, 15, 16, 17, 
                // Src: (xor:i32 i32:i32:$z, (and:i32 i32:i32:$x, (xor:i32 i32:i32:$z, i32:i32:$y))) - Complexity = 9
                // Dst: (BFI_INT_eg:i32 ?:i32:$x, ?:i32:$y, ?:i32:$z)
/*15647*/     /*Scope*/ 95|128,1/*223*/, /*->15872*/
/*15649*/       OPC_MoveChild, 0,
/*15651*/       OPC_CheckOpcode, TARGET_VAL(ISD::XOR),
/*15654*/       OPC_Scope, 107, /*->15763*/ // 2 children in Scope
/*15656*/         OPC_RecordChild0, // #1 = $y
/*15657*/         OPC_CheckChild1Same, 0,
/*15659*/         OPC_MoveParent,
/*15660*/         OPC_RecordChild1, // #2 = $x
/*15661*/         OPC_MoveParent,
/*15662*/         OPC_CheckType, MVT::i32,
/*15664*/         OPC_CheckPatternPredicate, 2, // (Subtarget.getGeneration() == AMDGPUSubtarget::EVERGREEN|| Subtarget.getGeneration() ==AMDGPUSubtarget::NORTHERN_ISLANDS)
/*15666*/         OPC_EmitInteger, MVT::i32, 0, 
/*15669*/         OPC_EmitInteger, MVT::i32, 0, 
/*15672*/         OPC_EmitInteger, MVT::i32, 0, 
/*15675*/         OPC_EmitInteger, MVT::i32, 0, 
/*15678*/         OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*15690*/         OPC_EmitInteger, MVT::i32, 0, 
/*15693*/         OPC_EmitInteger, MVT::i32, 0, 
/*15696*/         OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*15708*/         OPC_EmitInteger, MVT::i32, 0, 
/*15711*/         OPC_EmitInteger, MVT::i32, 0, 
/*15714*/         OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*15726*/         OPC_EmitInteger, MVT::i32, 1, 
/*15729*/         OPC_EmitRegister, MVT::i32, AMDGPU::PRED_SEL_OFF,
/*15732*/         OPC_EmitInteger, MVT::i32, 0, 
/*15735*/         OPC_EmitInteger, MVT::i32, 0, 
/*15738*/         OPC_MorphNodeTo, TARGET_VAL(AMDGPU::BFI_INT_eg), 0,
                      1/*#VTs*/, MVT::i32, 18/*#Ops*/, 3, 4, 2, 5, 6, 7, 1, 8, 9, 10, 0, 11, 12, 13, 14, 15, 16, 17, 
                  // Src: (xor:i32 i32:i32:$z, (and:i32 (xor:i32 i32:i32:$y, i32:i32:$z), i32:i32:$x)) - Complexity = 9
                  // Dst: (BFI_INT_eg:i32 ?:i32:$x, ?:i32:$y, ?:i32:$z)
/*15763*/       /*Scope*/ 107, /*->15871*/
/*15764*/         OPC_CheckChild0Same, 0,
/*15766*/         OPC_RecordChild1, // #1 = $y
/*15767*/         OPC_MoveParent,
/*15768*/         OPC_RecordChild1, // #2 = $x
/*15769*/         OPC_MoveParent,
/*15770*/         OPC_CheckType, MVT::i32,
/*15772*/         OPC_CheckPatternPredicate, 2, // (Subtarget.getGeneration() == AMDGPUSubtarget::EVERGREEN|| Subtarget.getGeneration() ==AMDGPUSubtarget::NORTHERN_ISLANDS)
/*15774*/         OPC_EmitInteger, MVT::i32, 0, 
/*15777*/         OPC_EmitInteger, MVT::i32, 0, 
/*15780*/         OPC_EmitInteger, MVT::i32, 0, 
/*15783*/         OPC_EmitInteger, MVT::i32, 0, 
/*15786*/         OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*15798*/         OPC_EmitInteger, MVT::i32, 0, 
/*15801*/         OPC_EmitInteger, MVT::i32, 0, 
/*15804*/         OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*15816*/         OPC_EmitInteger, MVT::i32, 0, 
/*15819*/         OPC_EmitInteger, MVT::i32, 0, 
/*15822*/         OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*15834*/         OPC_EmitInteger, MVT::i32, 1, 
/*15837*/         OPC_EmitRegister, MVT::i32, AMDGPU::PRED_SEL_OFF,
/*15840*/         OPC_EmitInteger, MVT::i32, 0, 
/*15843*/         OPC_EmitInteger, MVT::i32, 0, 
/*15846*/         OPC_MorphNodeTo, TARGET_VAL(AMDGPU::BFI_INT_eg), 0,
                      1/*#VTs*/, MVT::i32, 18/*#Ops*/, 3, 4, 2, 5, 6, 7, 1, 8, 9, 10, 0, 11, 12, 13, 14, 15, 16, 17, 
                  // Src: (xor:i32 i32:i32:$z, (and:i32 (xor:i32 i32:i32:$z, i32:i32:$y), i32:i32:$x)) - Complexity = 9
                  // Dst: (BFI_INT_eg:i32 ?:i32:$x, ?:i32:$y, ?:i32:$z)
/*15871*/       0, /*End of Scope*/
/*15872*/     0, /*End of Scope*/
/*15873*/   /*Scope*/ 63|128,3/*447*/, /*->16322*/
/*15875*/     OPC_MoveChild, 0,
/*15877*/     OPC_CheckOpcode, TARGET_VAL(ISD::AND),
/*15880*/     OPC_Scope, 90|128,1/*218*/, /*->16101*/ // 2 children in Scope
/*15883*/       OPC_RecordChild0, // #0 = $x
/*15884*/       OPC_MoveChild, 1,
/*15886*/       OPC_CheckOpcode, TARGET_VAL(ISD::XOR),
/*15889*/       OPC_RecordChild0, // #1 = $y
/*15890*/       OPC_RecordChild1, // #2 = $z
/*15891*/       OPC_MoveParent,
/*15892*/       OPC_MoveParent,
/*15893*/       OPC_CheckType, MVT::i32,
/*15895*/       OPC_Scope, 101, /*->15998*/ // 2 children in Scope
/*15897*/         OPC_CheckChild1Same, 2,
/*15899*/         OPC_CheckPatternPredicate, 2, // (Subtarget.getGeneration() == AMDGPUSubtarget::EVERGREEN|| Subtarget.getGeneration() ==AMDGPUSubtarget::NORTHERN_ISLANDS)
/*15901*/         OPC_EmitInteger, MVT::i32, 0, 
/*15904*/         OPC_EmitInteger, MVT::i32, 0, 
/*15907*/         OPC_EmitInteger, MVT::i32, 0, 
/*15910*/         OPC_EmitInteger, MVT::i32, 0, 
/*15913*/         OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*15925*/         OPC_EmitInteger, MVT::i32, 0, 
/*15928*/         OPC_EmitInteger, MVT::i32, 0, 
/*15931*/         OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*15943*/         OPC_EmitInteger, MVT::i32, 0, 
/*15946*/         OPC_EmitInteger, MVT::i32, 0, 
/*15949*/         OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*15961*/         OPC_EmitInteger, MVT::i32, 1, 
/*15964*/         OPC_EmitRegister, MVT::i32, AMDGPU::PRED_SEL_OFF,
/*15967*/         OPC_EmitInteger, MVT::i32, 0, 
/*15970*/         OPC_EmitInteger, MVT::i32, 0, 
/*15973*/         OPC_MorphNodeTo, TARGET_VAL(AMDGPU::BFI_INT_eg), 0,
                      1/*#VTs*/, MVT::i32, 18/*#Ops*/, 3, 4, 0, 5, 6, 7, 1, 8, 9, 10, 2, 11, 12, 13, 14, 15, 16, 17, 
                  // Src: (xor:i32 (and:i32 i32:i32:$x, (xor:i32 i32:i32:$y, i32:i32:$z)), i32:i32:$z) - Complexity = 9
                  // Dst: (BFI_INT_eg:i32 ?:i32:$x, ?:i32:$y, ?:i32:$z)
/*15998*/       /*Scope*/ 101, /*->16100*/
/*15999*/         OPC_CheckChild1Same, 1,
/*16001*/         OPC_CheckPatternPredicate, 2, // (Subtarget.getGeneration() == AMDGPUSubtarget::EVERGREEN|| Subtarget.getGeneration() ==AMDGPUSubtarget::NORTHERN_ISLANDS)
/*16003*/         OPC_EmitInteger, MVT::i32, 0, 
/*16006*/         OPC_EmitInteger, MVT::i32, 0, 
/*16009*/         OPC_EmitInteger, MVT::i32, 0, 
/*16012*/         OPC_EmitInteger, MVT::i32, 0, 
/*16015*/         OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*16027*/         OPC_EmitInteger, MVT::i32, 0, 
/*16030*/         OPC_EmitInteger, MVT::i32, 0, 
/*16033*/         OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*16045*/         OPC_EmitInteger, MVT::i32, 0, 
/*16048*/         OPC_EmitInteger, MVT::i32, 0, 
/*16051*/         OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*16063*/         OPC_EmitInteger, MVT::i32, 1, 
/*16066*/         OPC_EmitRegister, MVT::i32, AMDGPU::PRED_SEL_OFF,
/*16069*/         OPC_EmitInteger, MVT::i32, 0, 
/*16072*/         OPC_EmitInteger, MVT::i32, 0, 
/*16075*/         OPC_MorphNodeTo, TARGET_VAL(AMDGPU::BFI_INT_eg), 0,
                      1/*#VTs*/, MVT::i32, 18/*#Ops*/, 3, 4, 0, 5, 6, 7, 2, 8, 9, 10, 1, 11, 12, 13, 14, 15, 16, 17, 
                  // Src: (xor:i32 (and:i32 i32:i32:$x, (xor:i32 i32:i32:$z, i32:i32:$y)), i32:i32:$z) - Complexity = 9
                  // Dst: (BFI_INT_eg:i32 ?:i32:$x, ?:i32:$y, ?:i32:$z)
/*16100*/       0, /*End of Scope*/
/*16101*/     /*Scope*/ 90|128,1/*218*/, /*->16321*/
/*16103*/       OPC_MoveChild, 0,
/*16105*/       OPC_CheckOpcode, TARGET_VAL(ISD::XOR),
/*16108*/       OPC_RecordChild0, // #0 = $y
/*16109*/       OPC_RecordChild1, // #1 = $z
/*16110*/       OPC_MoveParent,
/*16111*/       OPC_RecordChild1, // #2 = $x
/*16112*/       OPC_MoveParent,
/*16113*/       OPC_CheckType, MVT::i32,
/*16115*/       OPC_Scope, 101, /*->16218*/ // 2 children in Scope
/*16117*/         OPC_CheckChild1Same, 1,
/*16119*/         OPC_CheckPatternPredicate, 2, // (Subtarget.getGeneration() == AMDGPUSubtarget::EVERGREEN|| Subtarget.getGeneration() ==AMDGPUSubtarget::NORTHERN_ISLANDS)
/*16121*/         OPC_EmitInteger, MVT::i32, 0, 
/*16124*/         OPC_EmitInteger, MVT::i32, 0, 
/*16127*/         OPC_EmitInteger, MVT::i32, 0, 
/*16130*/         OPC_EmitInteger, MVT::i32, 0, 
/*16133*/         OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*16145*/         OPC_EmitInteger, MVT::i32, 0, 
/*16148*/         OPC_EmitInteger, MVT::i32, 0, 
/*16151*/         OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*16163*/         OPC_EmitInteger, MVT::i32, 0, 
/*16166*/         OPC_EmitInteger, MVT::i32, 0, 
/*16169*/         OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*16181*/         OPC_EmitInteger, MVT::i32, 1, 
/*16184*/         OPC_EmitRegister, MVT::i32, AMDGPU::PRED_SEL_OFF,
/*16187*/         OPC_EmitInteger, MVT::i32, 0, 
/*16190*/         OPC_EmitInteger, MVT::i32, 0, 
/*16193*/         OPC_MorphNodeTo, TARGET_VAL(AMDGPU::BFI_INT_eg), 0,
                      1/*#VTs*/, MVT::i32, 18/*#Ops*/, 3, 4, 2, 5, 6, 7, 0, 8, 9, 10, 1, 11, 12, 13, 14, 15, 16, 17, 
                  // Src: (xor:i32 (and:i32 (xor:i32 i32:i32:$y, i32:i32:$z), i32:i32:$x), i32:i32:$z) - Complexity = 9
                  // Dst: (BFI_INT_eg:i32 ?:i32:$x, ?:i32:$y, ?:i32:$z)
/*16218*/       /*Scope*/ 101, /*->16320*/
/*16219*/         OPC_CheckChild1Same, 0,
/*16221*/         OPC_CheckPatternPredicate, 2, // (Subtarget.getGeneration() == AMDGPUSubtarget::EVERGREEN|| Subtarget.getGeneration() ==AMDGPUSubtarget::NORTHERN_ISLANDS)
/*16223*/         OPC_EmitInteger, MVT::i32, 0, 
/*16226*/         OPC_EmitInteger, MVT::i32, 0, 
/*16229*/         OPC_EmitInteger, MVT::i32, 0, 
/*16232*/         OPC_EmitInteger, MVT::i32, 0, 
/*16235*/         OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*16247*/         OPC_EmitInteger, MVT::i32, 0, 
/*16250*/         OPC_EmitInteger, MVT::i32, 0, 
/*16253*/         OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*16265*/         OPC_EmitInteger, MVT::i32, 0, 
/*16268*/         OPC_EmitInteger, MVT::i32, 0, 
/*16271*/         OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*16283*/         OPC_EmitInteger, MVT::i32, 1, 
/*16286*/         OPC_EmitRegister, MVT::i32, AMDGPU::PRED_SEL_OFF,
/*16289*/         OPC_EmitInteger, MVT::i32, 0, 
/*16292*/         OPC_EmitInteger, MVT::i32, 0, 
/*16295*/         OPC_MorphNodeTo, TARGET_VAL(AMDGPU::BFI_INT_eg), 0,
                      1/*#VTs*/, MVT::i32, 18/*#Ops*/, 3, 4, 2, 5, 6, 7, 1, 8, 9, 10, 0, 11, 12, 13, 14, 15, 16, 17, 
                  // Src: (xor:i32 (and:i32 (xor:i32 i32:i32:$z, i32:i32:$y), i32:i32:$x), i32:i32:$z) - Complexity = 9
                  // Dst: (BFI_INT_eg:i32 ?:i32:$x, ?:i32:$y, ?:i32:$z)
/*16320*/       0, /*End of Scope*/
/*16321*/     0, /*End of Scope*/
/*16322*/   /*Scope*/ 95|128,1/*223*/, /*->16547*/
/*16324*/     OPC_RecordChild0, // #0 = $src0
/*16325*/     OPC_Scope, 83, /*->16410*/ // 2 children in Scope
/*16327*/       OPC_MoveChild, 1,
/*16329*/       OPC_CheckInteger, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*16340*/       OPC_MoveParent,
/*16341*/       OPC_CheckType, MVT::i32,
/*16343*/       OPC_CheckPatternPredicate, 3, // (Subtarget.getGeneration() <= AMDGPUSubtarget::NORTHERN_ISLANDS)
/*16345*/       OPC_EmitInteger, MVT::i32, 1, 
/*16348*/       OPC_EmitInteger, MVT::i32, 0, 
/*16351*/       OPC_EmitInteger, MVT::i32, 0, 
/*16354*/       OPC_EmitInteger, MVT::i32, 0, 
/*16357*/       OPC_EmitInteger, MVT::i32, 0, 
/*16360*/       OPC_EmitInteger, MVT::i32, 0, 
/*16363*/       OPC_EmitInteger, MVT::i32, 0, 
/*16366*/       OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*16378*/       OPC_EmitInteger, MVT::i32, 1, 
/*16381*/       OPC_EmitRegister, MVT::i32, AMDGPU::PRED_SEL_OFF,
/*16384*/       OPC_EmitInteger, MVT::i32, 0, 
/*16387*/       OPC_EmitInteger, MVT::i32, 0, 
/*16390*/       OPC_MorphNodeTo, TARGET_VAL(AMDGPU::NOT_INT), 0,
                    1/*#VTs*/, MVT::i32, 13/*#Ops*/, 1, 2, 3, 4, 0, 5, 6, 7, 8, 9, 10, 11, 12, 
                // Src: (xor:i32 R600_Reg32:i32:$src0, -1:i32) - Complexity = 8
                // Dst: (NOT_INT:i32 R600_Reg32:i32:$src0)
/*16410*/     /*Scope*/ 6|128,1/*134*/, /*->16546*/
/*16412*/       OPC_RecordChild1, // #1 = $src1
/*16413*/       OPC_SwitchType /*2 cases */, 116,  MVT::i32,// ->16532
/*16416*/         OPC_Scope, 101, /*->16519*/ // 2 children in Scope
/*16418*/           OPC_CheckPatternPredicate, 3, // (Subtarget.getGeneration() <= AMDGPUSubtarget::NORTHERN_ISLANDS)
/*16420*/           OPC_EmitInteger, MVT::i32, 0, 
/*16423*/           OPC_EmitInteger, MVT::i32, 0, 
/*16426*/           OPC_EmitInteger, MVT::i32, 1, 
/*16429*/           OPC_EmitInteger, MVT::i32, 0, 
/*16432*/           OPC_EmitInteger, MVT::i32, 0, 
/*16435*/           OPC_EmitInteger, MVT::i32, 0, 
/*16438*/           OPC_EmitInteger, MVT::i32, 0, 
/*16441*/           OPC_EmitInteger, MVT::i32, 0, 
/*16444*/           OPC_EmitInteger, MVT::i32, 0, 
/*16447*/           OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*16459*/           OPC_EmitInteger, MVT::i32, 0, 
/*16462*/           OPC_EmitInteger, MVT::i32, 0, 
/*16465*/           OPC_EmitInteger, MVT::i32, 0, 
/*16468*/           OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*16480*/           OPC_EmitInteger, MVT::i32, 1, 
/*16483*/           OPC_EmitRegister, MVT::i32, AMDGPU::PRED_SEL_OFF,
/*16486*/           OPC_EmitInteger, MVT::i32, 0, 
/*16489*/           OPC_EmitInteger, MVT::i32, 0, 
/*16492*/           OPC_MorphNodeTo, TARGET_VAL(AMDGPU::XOR_INT), 0,
                        1/*#VTs*/, MVT::i32, 20/*#Ops*/, 2, 3, 4, 5, 6, 7, 0, 8, 9, 10, 11, 1, 12, 13, 14, 15, 16, 17, 18, 19, 
                    // Src: (xor:i32 R600_Reg32:i32:$src0, R600_Reg32:i32:$src1) - Complexity = 3
                    // Dst: (XOR_INT:i32 R600_Reg32:i32:$src0, R600_Reg32:i32:$src1)
/*16519*/         /*Scope*/ 11, /*->16531*/
/*16520*/           OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*16522*/           OPC_MorphNodeTo, TARGET_VAL(AMDGPU::V_XOR_B32_e32), 0,
                        1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1, 
                    // Src: (xor:i32 i32:i32:$src0, i32:i32:$src1) - Complexity = 3
                    // Dst: (V_XOR_B32_e32:i32 i32:i32:$src0, i32:i32:$src1)
/*16531*/         0, /*End of Scope*/
/*16532*/       /*SwitchType*/ 11,  MVT::i1,// ->16545
/*16534*/         OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*16536*/         OPC_MorphNodeTo, TARGET_VAL(AMDGPU::S_XOR_B64), 0,
                      1/*#VTs*/, MVT::i1, 2/*#Ops*/, 0, 1, 
                  // Src: (xor:i1 i1:i1:$src0, i1:i1:$src1) - Complexity = 3
                  // Dst: (S_XOR_B64:i1 i1:i1:$src0, i1:i1:$src1)
/*16545*/       0, // EndSwitchType
/*16546*/     0, /*End of Scope*/
/*16547*/   0, /*End of Scope*/
/*16548*/ /*SwitchOpcode*/ 50,  TARGET_VAL(AMDGPUISD::CONST_ADDRESS),// ->16601
/*16551*/   OPC_RecordChild0, // #0 = $src
/*16552*/   OPC_CheckChild0Type, MVT::i32,
/*16554*/   OPC_Scope, 15, /*->16571*/ // 2 children in Scope
/*16556*/     OPC_CheckType, MVT::i32,
/*16558*/     OPC_CheckPatternPredicate, 3, // (Subtarget.getGeneration() <= AMDGPUSubtarget::NORTHERN_ISLANDS)
/*16560*/     OPC_CheckComplexPat, /*CP*/4, /*#*/0, // SelectGlobalValueConstantOffset:$src #1
/*16563*/     OPC_MorphNodeTo, TARGET_VAL(AMDGPU::CONST_COPY), 0|OPFL_Variadic1,
                  1/*#VTs*/, MVT::i32, 1/*#Ops*/, 1, 
              // Src: (CONST_ADDRESS:i32 ADDRGA_CONST_OFFSET:i32:$src) - Complexity = 9
              // Dst: (CONST_COPY:i32 ADDRGA_CONST_OFFSET:i32:$src)
/*16571*/   /*Scope*/ 28, /*->16600*/
/*16572*/     OPC_RecordChild1, // #1 = $BUFFER_ID
/*16573*/     OPC_MoveChild, 1,
/*16575*/     OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*16578*/     OPC_CheckType, MVT::i32,
/*16580*/     OPC_MoveParent,
/*16581*/     OPC_CheckType, MVT::v4i32,
/*16583*/     OPC_CheckPatternPredicate, 3, // (Subtarget.getGeneration() <= AMDGPUSubtarget::NORTHERN_ISLANDS)
/*16585*/     OPC_CheckComplexPat, /*CP*/5, /*#*/0, // SelectGlobalValueVariableOffset:$ptr #2 #3
/*16588*/     OPC_EmitConvertToTarget, 1,
/*16590*/     OPC_MorphNodeTo, TARGET_VAL(AMDGPU::TEX_VTX_CONSTBUF), 0|OPFL_Variadic2,
                  1/*#VTs*/, MVT::v4i32, 3/*#Ops*/, 2, 3, 4, 
              // Src: (CONST_ADDRESS:v4i32 ADDRGA_VAR_OFFSET:i32:$ptr, (imm:i32):$BUFFER_ID) - Complexity = 15
              // Dst: (TEX_VTX_CONSTBUF:v4i32 ADDRGA_VAR_OFFSET:i32:$ptr, (imm:i32):$BUFFER_ID)
/*16600*/   0, /*End of Scope*/
/*16601*/ /*SwitchOpcode*/ 103|128,24/*3175*/,  TARGET_VAL(ISD::INTRINSIC_WO_CHAIN),// ->19780
/*16605*/   OPC_MoveChild, 0,
/*16607*/   OPC_Scope, 114, /*->16723*/ // 19 children in Scope
/*16609*/     OPC_CheckInteger, 126|128,25/*3326*/, 
/*16612*/     OPC_MoveParent,
/*16613*/     OPC_RecordChild1, // #0 = $src0
/*16614*/     OPC_CheckChild1Type, MVT::i32,
/*16616*/     OPC_RecordChild2, // #1 = $src1
/*16617*/     OPC_CheckChild2Type, MVT::i32,
/*16619*/     OPC_RecordChild3, // #2 = $src2
/*16620*/     OPC_CheckChild3Type, MVT::i32,
/*16622*/     OPC_CheckType, MVT::i32,
/*16624*/     OPC_CheckPatternPredicate, 2, // (Subtarget.getGeneration() == AMDGPUSubtarget::EVERGREEN|| Subtarget.getGeneration() ==AMDGPUSubtarget::NORTHERN_ISLANDS)
/*16626*/     OPC_EmitInteger, MVT::i32, 0, 
/*16629*/     OPC_EmitInteger, MVT::i32, 0, 
/*16632*/     OPC_EmitInteger, MVT::i32, 0, 
/*16635*/     OPC_EmitInteger, MVT::i32, 0, 
/*16638*/     OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*16650*/     OPC_EmitInteger, MVT::i32, 0, 
/*16653*/     OPC_EmitInteger, MVT::i32, 0, 
/*16656*/     OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*16668*/     OPC_EmitInteger, MVT::i32, 0, 
/*16671*/     OPC_EmitInteger, MVT::i32, 0, 
/*16674*/     OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*16686*/     OPC_EmitInteger, MVT::i32, 1, 
/*16689*/     OPC_EmitRegister, MVT::i32, AMDGPU::PRED_SEL_OFF,
/*16692*/     OPC_EmitInteger, MVT::i32, 0, 
/*16695*/     OPC_EmitInteger, MVT::i32, 0, 
/*16698*/     OPC_MorphNodeTo, TARGET_VAL(AMDGPU::BFE_UINT_eg), 0,
                  1/*#VTs*/, MVT::i32, 18/*#Ops*/, 3, 4, 0, 5, 6, 7, 1, 8, 9, 10, 2, 11, 12, 13, 14, 15, 16, 17, 
              // Src: (intrinsic_wo_chain:i32 3326:iPTR, i32:i32:$src0, i32:i32:$src1, i32:i32:$src2) - Complexity = 8
              // Dst: (BFE_UINT_eg:i32 i32:i32:$src0, i32:i32:$src1, i32:i32:$src2)
/*16723*/   /*Scope*/ 17, /*->16741*/
/*16724*/     OPC_CheckInteger, 104|128,26/*3432*/, 
/*16727*/     OPC_MoveParent,
/*16728*/     OPC_RecordChild1, // #0 = $src0
/*16729*/     OPC_RecordChild2, // #1 = $src1
/*16730*/     OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*16732*/     OPC_MorphNodeTo, TARGET_VAL(AMDGPU::V_CVT_PKRTZ_F16_F32_e32), 0,
                  1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1, 
              // Src: (intrinsic_wo_chain:i32 3432:iPTR, f32:f32:$src0, f32:f32:$src1) - Complexity = 8
              // Dst: (V_CVT_PKRTZ_F16_F32_e32:i32 f32:f32:$src0, f32:f32:$src1)
/*16741*/   /*Scope*/ 57, /*->16799*/
/*16742*/     OPC_CheckInteger, 111|128,26/*3439*/, 
/*16745*/     OPC_MoveParent,
/*16746*/     OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*16748*/     OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,15/*4294967295*/, 
/*16755*/     OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,15/*4294967295*/, 
/*16762*/     OPC_EmitInteger, MVT::i32, 0, 
/*16765*/     OPC_EmitInteger, MVT::i32, 0, 
/*16768*/     OPC_EmitInteger, MVT::i32, 0, 
/*16771*/     OPC_EmitInteger, MVT::i32, 0, 
/*16774*/     OPC_EmitInteger, MVT::i32, 0, 
/*16777*/     OPC_EmitNode, TARGET_VAL(AMDGPU::V_MBCNT_LO_U32_B32_e64), 0,
                  1/*#VTs*/, MVT::i32, 6/*#Ops*/, 1, 2, 3, 4, 5, 6,  // Results = #7
/*16790*/     OPC_MorphNodeTo, TARGET_VAL(AMDGPU::V_MBCNT_HI_U32_B32_e32), 0,
                  1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 7, 
              // Src: (intrinsic_wo_chain:i32 3439:iPTR) - Complexity = 8
              // Dst: (V_MBCNT_HI_U32_B32_e32:i32 4294967295:i32, (V_MBCNT_LO_U32_B32_e64:i32 4294967295:i32, 0:i32, 0:i32, 0:i32, 0:i32, 0:i32))
/*16799*/   /*Scope*/ 73, /*->16873*/
/*16800*/     OPC_CheckInteger, 6|128,26/*3334*/, 
/*16803*/     OPC_MoveParent,
/*16804*/     OPC_RecordChild1, // #0 = $src
/*16805*/     OPC_CheckChild1Type, MVT::f32,
/*16807*/     OPC_MoveChild, 2,
/*16809*/     OPC_CheckOpcode, TARGET_VAL(ISD::ConstantFP),
/*16812*/     OPC_CheckPredicate, 7, // Predicate_FP_ZERO
/*16814*/     OPC_CheckType, MVT::f32,
/*16816*/     OPC_MoveParent,
/*16817*/     OPC_MoveChild, 3,
/*16819*/     OPC_CheckOpcode, TARGET_VAL(ISD::ConstantFP),
/*16822*/     OPC_CheckPredicate, 6, // Predicate_FP_ONE
/*16824*/     OPC_CheckType, MVT::f32,
/*16826*/     OPC_MoveParent,
/*16827*/     OPC_CheckType, MVT::f32,
/*16829*/     OPC_Scope, 30, /*->16861*/ // 2 children in Scope
/*16831*/       OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*16833*/       OPC_EmitInteger, MVT::i32, 0, 
/*16836*/       OPC_EmitInteger, MVT::i32, 0, 
/*16839*/       OPC_EmitInteger, MVT::i32, 1, 
/*16842*/       OPC_EmitInteger, MVT::i32, 0, 
/*16845*/       OPC_EmitInteger, MVT::i32, 0, 
/*16848*/       OPC_MorphNodeTo, TARGET_VAL(AMDGPU::V_ADD_F32_e64), 0,
                    1/*#VTs*/, MVT::f32, 6/*#Ops*/, 0, 1, 2, 3, 4, 5, 
                // Src: (intrinsic_wo_chain:f32 3334:iPTR, f32:f32:$src, (fpimm:f32)<<P:Predicate_FP_ZERO>>, (fpimm:f32)<<P:Predicate_FP_ONE>>) - Complexity = 16
                // Dst: (V_ADD_F32_e64:f32 ?:f32:$src, 0:i32, 0:i32, 1:i32, 0:i32, 0:i32)
/*16861*/     /*Scope*/ 10, /*->16872*/
/*16862*/       OPC_CheckPatternPredicate, 3, // (Subtarget.getGeneration() <= AMDGPUSubtarget::NORTHERN_ISLANDS)
/*16864*/       OPC_MorphNodeTo, TARGET_VAL(AMDGPU::CLAMP_R600), 0,
                    1/*#VTs*/, MVT::f32, 1/*#Ops*/, 0, 
                // Src: (intrinsic_wo_chain:f32 3334:iPTR, f32:f32:$src0, (fpimm:f32)<<P:Predicate_FP_ZERO>>, (fpimm:f32)<<P:Predicate_FP_ONE>>) - Complexity = 16
                // Dst: (CLAMP_R600:f32 f32:f32:$src0)
/*16872*/     0, /*End of Scope*/
/*16873*/   /*Scope*/ 39, /*->16913*/
/*16874*/     OPC_CheckInteger, 97|128,26/*3425*/, 
/*16877*/     OPC_MoveParent,
/*16878*/     OPC_RecordChild1, // #0 = $attr_chan
/*16879*/     OPC_MoveChild, 1,
/*16881*/     OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*16884*/     OPC_MoveParent,
/*16885*/     OPC_RecordChild2, // #1 = $attr
/*16886*/     OPC_MoveChild, 2,
/*16888*/     OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*16891*/     OPC_MoveParent,
/*16892*/     OPC_RecordChild3, // #2 = $params
/*16893*/     OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*16895*/     OPC_EmitInteger, MVT::i32, 2, 
/*16898*/     OPC_EmitConvertToTarget, 0,
/*16900*/     OPC_EmitConvertToTarget, 1,
/*16902*/     OPC_MorphNodeTo, TARGET_VAL(AMDGPU::V_INTERP_MOV_F32), 0,
                  1/*#VTs*/, MVT::f32, 4/*#Ops*/, 3, 4, 5, 2, 
              // Src: (intrinsic_wo_chain:f32 3425:iPTR, (imm:i32):$attr_chan, (imm:i32):$attr, i32:i32:$params) - Complexity = 14
              // Dst: (V_INTERP_MOV_F32:f32 2:i32, (imm:i32):$attr_chan, (imm:i32):$attr, ?:i32:$params)
/*16913*/   /*Scope*/ 77, /*->16991*/
/*16914*/     OPC_CheckInteger, 98|128,26/*3426*/, 
/*16917*/     OPC_MoveParent,
/*16918*/     OPC_RecordChild1, // #0 = $attr_chan
/*16919*/     OPC_MoveChild, 1,
/*16921*/     OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*16924*/     OPC_MoveParent,
/*16925*/     OPC_RecordChild2, // #1 = $attr
/*16926*/     OPC_MoveChild, 2,
/*16928*/     OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*16931*/     OPC_MoveParent,
/*16932*/     OPC_RecordChild3, // #2 = $params
/*16933*/     OPC_RecordChild4, // #3 = $ij
/*16934*/     OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*16936*/     OPC_EmitInteger, MVT::i32, AMDGPU::sub0,
/*16939*/     OPC_EmitNode, TARGET_VAL(TargetOpcode::EXTRACT_SUBREG), 0,
                  1/*#VTs*/, MVT::i32, 2/*#Ops*/, 3, 4,  // Results = #5
/*16948*/     OPC_EmitConvertToTarget, 0,
/*16950*/     OPC_EmitConvertToTarget, 1,
/*16952*/     OPC_EmitNode, TARGET_VAL(AMDGPU::V_INTERP_P1_F32), 0,
                  1/*#VTs*/, MVT::i32, 4/*#Ops*/, 5, 6, 7, 2,  // Results = #8
/*16963*/     OPC_EmitInteger, MVT::i32, AMDGPU::sub1,
/*16966*/     OPC_EmitNode, TARGET_VAL(TargetOpcode::EXTRACT_SUBREG), 0,
                  1/*#VTs*/, MVT::i32, 2/*#Ops*/, 3, 9,  // Results = #10
/*16975*/     OPC_EmitConvertToTarget, 0,
/*16977*/     OPC_EmitConvertToTarget, 1,
/*16979*/     OPC_MorphNodeTo, TARGET_VAL(AMDGPU::V_INTERP_P2_F32), 0,
                  1/*#VTs*/, MVT::f32, 5/*#Ops*/, 8, 10, 11, 12, 2, 
              // Src: (intrinsic_wo_chain:f32 3426:iPTR, (imm:i32):$attr_chan, (imm:i32):$attr, M0Reg:i32:$params, v2i32:v2i32:$ij) - Complexity = 14
              // Dst: (V_INTERP_P2_F32:f32 (V_INTERP_P1_F32:i32 (EXTRACT_SUBREG:i32 v2i32:v2i32:$ij, sub0:i32), (imm:i32):$attr_chan, (imm:i32):$attr, i32:i32:$params), (EXTRACT_SUBREG:i32 ?:v2i32:$ij, sub1:i32), (imm:i32):$attr_chan, (imm:i32):$attr, ?:i32:$params)
/*16991*/   /*Scope*/ 23, /*->17015*/
/*16992*/     OPC_CheckInteger, 93|128,25/*3293*/, 
/*16995*/     OPC_MoveParent,
/*16996*/     OPC_RecordChild1, // #0 = $src
/*16997*/     OPC_MoveChild, 1,
/*16999*/     OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*17002*/     OPC_MoveParent,
/*17003*/     OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*17005*/     OPC_EmitConvertToTarget, 0,
/*17007*/     OPC_MorphNodeTo, TARGET_VAL(AMDGPU::LOAD_CONST), 0,
                  1/*#VTs*/, MVT::f32, 1/*#Ops*/, 1, 
              // Src: (intrinsic_wo_chain:f32 3293:iPTR, (imm:i32):$src) - Complexity = 11
              // Dst: (LOAD_CONST:f32 (imm:i32):$src)
/*17015*/   /*Scope*/ 122, /*->17138*/
/*17016*/     OPC_CheckInteger, 96|128,25/*3296*/, 
/*17019*/     OPC_MoveParent,
/*17020*/     OPC_RecordChild1, // #0 = $src0
/*17021*/     OPC_RecordChild2, // #1 = $src1
/*17022*/     OPC_Scope, 101, /*->17125*/ // 2 children in Scope
/*17024*/       OPC_CheckPatternPredicate, 3, // (Subtarget.getGeneration() <= AMDGPUSubtarget::NORTHERN_ISLANDS)
/*17026*/       OPC_EmitInteger, MVT::i32, 0, 
/*17029*/       OPC_EmitInteger, MVT::i32, 0, 
/*17032*/       OPC_EmitInteger, MVT::i32, 1, 
/*17035*/       OPC_EmitInteger, MVT::i32, 0, 
/*17038*/       OPC_EmitInteger, MVT::i32, 0, 
/*17041*/       OPC_EmitInteger, MVT::i32, 0, 
/*17044*/       OPC_EmitInteger, MVT::i32, 0, 
/*17047*/       OPC_EmitInteger, MVT::i32, 0, 
/*17050*/       OPC_EmitInteger, MVT::i32, 0, 
/*17053*/       OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*17065*/       OPC_EmitInteger, MVT::i32, 0, 
/*17068*/       OPC_EmitInteger, MVT::i32, 0, 
/*17071*/       OPC_EmitInteger, MVT::i32, 0, 
/*17074*/       OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*17086*/       OPC_EmitInteger, MVT::i32, 1, 
/*17089*/       OPC_EmitRegister, MVT::i32, AMDGPU::PRED_SEL_OFF,
/*17092*/       OPC_EmitInteger, MVT::i32, 0, 
/*17095*/       OPC_EmitInteger, MVT::i32, 0, 
/*17098*/       OPC_MorphNodeTo, TARGET_VAL(AMDGPU::MUL), 0,
                    1/*#VTs*/, MVT::f32, 20/*#Ops*/, 2, 3, 4, 5, 6, 7, 0, 8, 9, 10, 11, 1, 12, 13, 14, 15, 16, 17, 18, 19, 
                // Src: (intrinsic_wo_chain:f32 3296:iPTR, R600_Reg32:f32:$src0, R600_Reg32:f32:$src1) - Complexity = 8
                // Dst: (MUL:f32 R600_Reg32:f32:$src0, R600_Reg32:f32:$src1)
/*17125*/     /*Scope*/ 11, /*->17137*/
/*17126*/       OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*17128*/       OPC_MorphNodeTo, TARGET_VAL(AMDGPU::V_MUL_LEGACY_F32_e32), 0,
                    1/*#VTs*/, MVT::f32, 2/*#Ops*/, 0, 1, 
                // Src: (intrinsic_wo_chain:f32 3296:iPTR, f32:f32:$src0, f32:f32:$src1) - Complexity = 8
                // Dst: (V_MUL_LEGACY_F32_e32:f32 f32:f32:$src0, f32:f32:$src1)
/*17137*/     0, /*End of Scope*/
/*17138*/   /*Scope*/ 86, /*->17225*/
/*17139*/     OPC_CheckInteger, 110|128,25/*3310*/, 
/*17142*/     OPC_MoveParent,
/*17143*/     OPC_RecordChild1, // #0 = $src0
/*17144*/     OPC_Scope, 67, /*->17213*/ // 2 children in Scope
/*17146*/       OPC_CheckPatternPredicate, 3, // (Subtarget.getGeneration() <= AMDGPUSubtarget::NORTHERN_ISLANDS)
/*17148*/       OPC_EmitInteger, MVT::i32, 1, 
/*17151*/       OPC_EmitInteger, MVT::i32, 0, 
/*17154*/       OPC_EmitInteger, MVT::i32, 0, 
/*17157*/       OPC_EmitInteger, MVT::i32, 0, 
/*17160*/       OPC_EmitInteger, MVT::i32, 0, 
/*17163*/       OPC_EmitInteger, MVT::i32, 0, 
/*17166*/       OPC_EmitInteger, MVT::i32, 0, 
/*17169*/       OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*17181*/       OPC_EmitInteger, MVT::i32, 1, 
/*17184*/       OPC_EmitRegister, MVT::i32, AMDGPU::PRED_SEL_OFF,
/*17187*/       OPC_EmitInteger, MVT::i32, 0, 
/*17190*/       OPC_EmitInteger, MVT::i32, 0, 
/*17193*/       OPC_MorphNodeTo, TARGET_VAL(AMDGPU::TRUNC), 0,
                    1/*#VTs*/, MVT::f32, 13/*#Ops*/, 1, 2, 3, 4, 0, 5, 6, 7, 8, 9, 10, 11, 12, 
                // Src: (intrinsic_wo_chain:f32 3310:iPTR, R600_Reg32:f32:$src0) - Complexity = 8
                // Dst: (TRUNC:f32 R600_Reg32:f32:$src0)
/*17213*/     /*Scope*/ 10, /*->17224*/
/*17214*/       OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*17216*/       OPC_MorphNodeTo, TARGET_VAL(AMDGPU::V_TRUNC_F32_e32), 0,
                    1/*#VTs*/, MVT::f32, 1/*#Ops*/, 0, 
                // Src: (intrinsic_wo_chain:f32 3310:iPTR, f32:f32:$src0) - Complexity = 8
                // Dst: (V_TRUNC_F32_e32:f32 f32:f32:$src0)
/*17224*/     0, /*End of Scope*/
/*17225*/   /*Scope*/ 94|128,1/*222*/, /*->17449*/
/*17227*/     OPC_CheckInteger, 101|128,25/*3301*/, 
/*17230*/     OPC_MoveParent,
/*17231*/     OPC_RecordChild1, // #0 = $src0
/*17232*/     OPC_Scope, 67, /*->17301*/ // 4 children in Scope
/*17234*/       OPC_CheckPatternPredicate, 1, // (Subtarget.getGeneration() <= AMDGPUSubtarget::R700)
/*17236*/       OPC_EmitInteger, MVT::i32, 1, 
/*17239*/       OPC_EmitInteger, MVT::i32, 0, 
/*17242*/       OPC_EmitInteger, MVT::i32, 0, 
/*17245*/       OPC_EmitInteger, MVT::i32, 0, 
/*17248*/       OPC_EmitInteger, MVT::i32, 0, 
/*17251*/       OPC_EmitInteger, MVT::i32, 0, 
/*17254*/       OPC_EmitInteger, MVT::i32, 0, 
/*17257*/       OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*17269*/       OPC_EmitInteger, MVT::i32, 1, 
/*17272*/       OPC_EmitRegister, MVT::i32, AMDGPU::PRED_SEL_OFF,
/*17275*/       OPC_EmitInteger, MVT::i32, 0, 
/*17278*/       OPC_EmitInteger, MVT::i32, 0, 
/*17281*/       OPC_MorphNodeTo, TARGET_VAL(AMDGPU::RECIPSQRT_CLAMPED_r600), 0,
                    1/*#VTs*/, MVT::f32, 13/*#Ops*/, 1, 2, 3, 4, 0, 5, 6, 7, 8, 9, 10, 11, 12, 
                // Src: (intrinsic_wo_chain:f32 3301:iPTR, R600_Reg32:f32:$src0) - Complexity = 8
                // Dst: (RECIPSQRT_CLAMPED_r600:f32 R600_Reg32:f32:$src0)
/*17301*/     /*Scope*/ 67, /*->17369*/
/*17302*/       OPC_CheckPatternPredicate, 5, // (Subtarget.getGeneration() >= AMDGPUSubtarget::EVERGREEN && Subtarget.getGeneration() < AMDGPUSubtarget::SOUTHERN_ISLANDS && !Subtarget.hasCaymanISA())
/*17304*/       OPC_EmitInteger, MVT::i32, 1, 
/*17307*/       OPC_EmitInteger, MVT::i32, 0, 
/*17310*/       OPC_EmitInteger, MVT::i32, 0, 
/*17313*/       OPC_EmitInteger, MVT::i32, 0, 
/*17316*/       OPC_EmitInteger, MVT::i32, 0, 
/*17319*/       OPC_EmitInteger, MVT::i32, 0, 
/*17322*/       OPC_EmitInteger, MVT::i32, 0, 
/*17325*/       OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*17337*/       OPC_EmitInteger, MVT::i32, 1, 
/*17340*/       OPC_EmitRegister, MVT::i32, AMDGPU::PRED_SEL_OFF,
/*17343*/       OPC_EmitInteger, MVT::i32, 0, 
/*17346*/       OPC_EmitInteger, MVT::i32, 0, 
/*17349*/       OPC_MorphNodeTo, TARGET_VAL(AMDGPU::RECIPSQRT_CLAMPED_eg), 0,
                    1/*#VTs*/, MVT::f32, 13/*#Ops*/, 1, 2, 3, 4, 0, 5, 6, 7, 8, 9, 10, 11, 12, 
                // Src: (intrinsic_wo_chain:f32 3301:iPTR, R600_Reg32:f32:$src0) - Complexity = 8
                // Dst: (RECIPSQRT_CLAMPED_eg:f32 R600_Reg32:f32:$src0)
/*17369*/     /*Scope*/ 67, /*->17437*/
/*17370*/       OPC_CheckPatternPredicate, 4, // (Subtarget.hasCaymanISA())
/*17372*/       OPC_EmitInteger, MVT::i32, 1, 
/*17375*/       OPC_EmitInteger, MVT::i32, 0, 
/*17378*/       OPC_EmitInteger, MVT::i32, 0, 
/*17381*/       OPC_EmitInteger, MVT::i32, 0, 
/*17384*/       OPC_EmitInteger, MVT::i32, 0, 
/*17387*/       OPC_EmitInteger, MVT::i32, 0, 
/*17390*/       OPC_EmitInteger, MVT::i32, 0, 
/*17393*/       OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*17405*/       OPC_EmitInteger, MVT::i32, 1, 
/*17408*/       OPC_EmitRegister, MVT::i32, AMDGPU::PRED_SEL_OFF,
/*17411*/       OPC_EmitInteger, MVT::i32, 0, 
/*17414*/       OPC_EmitInteger, MVT::i32, 0, 
/*17417*/       OPC_MorphNodeTo, TARGET_VAL(AMDGPU::RECIPSQRT_CLAMPED_cm), 0,
                    1/*#VTs*/, MVT::f32, 13/*#Ops*/, 1, 2, 3, 4, 0, 5, 6, 7, 8, 9, 10, 11, 12, 
                // Src: (intrinsic_wo_chain:f32 3301:iPTR, R600_Reg32:f32:$src0) - Complexity = 8
                // Dst: (RECIPSQRT_CLAMPED_cm:f32 R600_Reg32:f32:$src0)
/*17437*/     /*Scope*/ 10, /*->17448*/
/*17438*/       OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*17440*/       OPC_MorphNodeTo, TARGET_VAL(AMDGPU::V_RSQ_LEGACY_F32_e32), 0,
                    1/*#VTs*/, MVT::f32, 1/*#Ops*/, 0, 
                // Src: (intrinsic_wo_chain:f32 3301:iPTR, f32:f32:$src0) - Complexity = 8
                // Dst: (V_RSQ_LEGACY_F32_e32:f32 f32:f32:$src0)
/*17448*/     0, /*End of Scope*/
/*17449*/   /*Scope*/ 20|128,4/*532*/, /*->17983*/
/*17451*/     OPC_CheckInteger, 87|128,25/*3287*/, 
/*17454*/     OPC_MoveParent,
/*17455*/     OPC_RecordChild1, // #0 = $src0
/*17456*/     OPC_RecordChild2, // #1 = $src1
/*17457*/     OPC_Scope, 38|128,1/*166*/, /*->17626*/ // 4 children in Scope
/*17460*/       OPC_CheckPatternPredicate, 1, // (Subtarget.getGeneration() <= AMDGPUSubtarget::R700)
/*17462*/       OPC_EmitInteger, MVT::i32, 0, 
/*17465*/       OPC_EmitInteger, MVT::i32, 0, 
/*17468*/       OPC_EmitInteger, MVT::i32, 1, 
/*17471*/       OPC_EmitInteger, MVT::i32, 0, 
/*17474*/       OPC_EmitInteger, MVT::i32, 0, 
/*17477*/       OPC_EmitInteger, MVT::i32, 0, 
/*17480*/       OPC_EmitInteger, MVT::i32, 0, 
/*17483*/       OPC_EmitInteger, MVT::i32, 0, 
/*17486*/       OPC_EmitInteger, MVT::i32, 0, 
/*17489*/       OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*17501*/       OPC_EmitInteger, MVT::i32, 1, 
/*17504*/       OPC_EmitInteger, MVT::i32, 0, 
/*17507*/       OPC_EmitInteger, MVT::i32, 0, 
/*17510*/       OPC_EmitInteger, MVT::i32, 0, 
/*17513*/       OPC_EmitInteger, MVT::i32, 0, 
/*17516*/       OPC_EmitInteger, MVT::i32, 0, 
/*17519*/       OPC_EmitInteger, MVT::i32, 0, 
/*17522*/       OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*17534*/       OPC_EmitInteger, MVT::i32, 1, 
/*17537*/       OPC_EmitRegister, MVT::i32, AMDGPU::PRED_SEL_OFF,
/*17540*/       OPC_EmitInteger, MVT::i32, 0, 
/*17543*/       OPC_EmitInteger, MVT::i32, 0, 
/*17546*/       OPC_EmitNode, TARGET_VAL(AMDGPU::RECIP_IEEE_r600), 0,
                    1/*#VTs*/, MVT::i32, 13/*#Ops*/, 12, 13, 14, 15, 1, 16, 17, 18, 19, 20, 21, 22, 23,  // Results = #24
/*17566*/       OPC_EmitInteger, MVT::i32, 0, 
/*17569*/       OPC_EmitInteger, MVT::i32, 0, 
/*17572*/       OPC_EmitInteger, MVT::i32, 0, 
/*17575*/       OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*17587*/       OPC_EmitInteger, MVT::i32, 1, 
/*17590*/       OPC_EmitRegister, MVT::i32, AMDGPU::PRED_SEL_OFF,
/*17593*/       OPC_EmitInteger, MVT::i32, 0, 
/*17596*/       OPC_EmitInteger, MVT::i32, 0, 
/*17599*/       OPC_MorphNodeTo, TARGET_VAL(AMDGPU::MUL_IEEE), 0,
                    1/*#VTs*/, MVT::f32, 20/*#Ops*/, 2, 3, 4, 5, 6, 7, 0, 8, 9, 10, 11, 24, 25, 26, 27, 28, 29, 30, 31, 32, 
                // Src: (intrinsic_wo_chain:f32 3287:iPTR, f32:f32:$src0, f32:f32:$src1) - Complexity = 8
                // Dst: (MUL_IEEE:f32 ?:f32:$src0, (RECIP_IEEE_r600:i32 ?:f32:$src1))
/*17626*/     /*Scope*/ 38|128,1/*166*/, /*->17794*/
/*17628*/       OPC_CheckPatternPredicate, 5, // (Subtarget.getGeneration() >= AMDGPUSubtarget::EVERGREEN && Subtarget.getGeneration() < AMDGPUSubtarget::SOUTHERN_ISLANDS && !Subtarget.hasCaymanISA())
/*17630*/       OPC_EmitInteger, MVT::i32, 0, 
/*17633*/       OPC_EmitInteger, MVT::i32, 0, 
/*17636*/       OPC_EmitInteger, MVT::i32, 1, 
/*17639*/       OPC_EmitInteger, MVT::i32, 0, 
/*17642*/       OPC_EmitInteger, MVT::i32, 0, 
/*17645*/       OPC_EmitInteger, MVT::i32, 0, 
/*17648*/       OPC_EmitInteger, MVT::i32, 0, 
/*17651*/       OPC_EmitInteger, MVT::i32, 0, 
/*17654*/       OPC_EmitInteger, MVT::i32, 0, 
/*17657*/       OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*17669*/       OPC_EmitInteger, MVT::i32, 1, 
/*17672*/       OPC_EmitInteger, MVT::i32, 0, 
/*17675*/       OPC_EmitInteger, MVT::i32, 0, 
/*17678*/       OPC_EmitInteger, MVT::i32, 0, 
/*17681*/       OPC_EmitInteger, MVT::i32, 0, 
/*17684*/       OPC_EmitInteger, MVT::i32, 0, 
/*17687*/       OPC_EmitInteger, MVT::i32, 0, 
/*17690*/       OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*17702*/       OPC_EmitInteger, MVT::i32, 1, 
/*17705*/       OPC_EmitRegister, MVT::i32, AMDGPU::PRED_SEL_OFF,
/*17708*/       OPC_EmitInteger, MVT::i32, 0, 
/*17711*/       OPC_EmitInteger, MVT::i32, 0, 
/*17714*/       OPC_EmitNode, TARGET_VAL(AMDGPU::RECIP_IEEE_eg), 0,
                    1/*#VTs*/, MVT::i32, 13/*#Ops*/, 12, 13, 14, 15, 1, 16, 17, 18, 19, 20, 21, 22, 23,  // Results = #24
/*17734*/       OPC_EmitInteger, MVT::i32, 0, 
/*17737*/       OPC_EmitInteger, MVT::i32, 0, 
/*17740*/       OPC_EmitInteger, MVT::i32, 0, 
/*17743*/       OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*17755*/       OPC_EmitInteger, MVT::i32, 1, 
/*17758*/       OPC_EmitRegister, MVT::i32, AMDGPU::PRED_SEL_OFF,
/*17761*/       OPC_EmitInteger, MVT::i32, 0, 
/*17764*/       OPC_EmitInteger, MVT::i32, 0, 
/*17767*/       OPC_MorphNodeTo, TARGET_VAL(AMDGPU::MUL_IEEE), 0,
                    1/*#VTs*/, MVT::f32, 20/*#Ops*/, 2, 3, 4, 5, 6, 7, 0, 8, 9, 10, 11, 24, 25, 26, 27, 28, 29, 30, 31, 32, 
                // Src: (intrinsic_wo_chain:f32 3287:iPTR, f32:f32:$src0, f32:f32:$src1) - Complexity = 8
                // Dst: (MUL_IEEE:f32 ?:f32:$src0, (RECIP_IEEE_eg:i32 ?:f32:$src1))
/*17794*/     /*Scope*/ 38|128,1/*166*/, /*->17962*/
/*17796*/       OPC_CheckPatternPredicate, 4, // (Subtarget.hasCaymanISA())
/*17798*/       OPC_EmitInteger, MVT::i32, 0, 
/*17801*/       OPC_EmitInteger, MVT::i32, 0, 
/*17804*/       OPC_EmitInteger, MVT::i32, 1, 
/*17807*/       OPC_EmitInteger, MVT::i32, 0, 
/*17810*/       OPC_EmitInteger, MVT::i32, 0, 
/*17813*/       OPC_EmitInteger, MVT::i32, 0, 
/*17816*/       OPC_EmitInteger, MVT::i32, 0, 
/*17819*/       OPC_EmitInteger, MVT::i32, 0, 
/*17822*/       OPC_EmitInteger, MVT::i32, 0, 
/*17825*/       OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*17837*/       OPC_EmitInteger, MVT::i32, 1, 
/*17840*/       OPC_EmitInteger, MVT::i32, 0, 
/*17843*/       OPC_EmitInteger, MVT::i32, 0, 
/*17846*/       OPC_EmitInteger, MVT::i32, 0, 
/*17849*/       OPC_EmitInteger, MVT::i32, 0, 
/*17852*/       OPC_EmitInteger, MVT::i32, 0, 
/*17855*/       OPC_EmitInteger, MVT::i32, 0, 
/*17858*/       OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*17870*/       OPC_EmitInteger, MVT::i32, 1, 
/*17873*/       OPC_EmitRegister, MVT::i32, AMDGPU::PRED_SEL_OFF,
/*17876*/       OPC_EmitInteger, MVT::i32, 0, 
/*17879*/       OPC_EmitInteger, MVT::i32, 0, 
/*17882*/       OPC_EmitNode, TARGET_VAL(AMDGPU::RECIP_IEEE_cm), 0,
                    1/*#VTs*/, MVT::i32, 13/*#Ops*/, 12, 13, 14, 15, 1, 16, 17, 18, 19, 20, 21, 22, 23,  // Results = #24
/*17902*/       OPC_EmitInteger, MVT::i32, 0, 
/*17905*/       OPC_EmitInteger, MVT::i32, 0, 
/*17908*/       OPC_EmitInteger, MVT::i32, 0, 
/*17911*/       OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*17923*/       OPC_EmitInteger, MVT::i32, 1, 
/*17926*/       OPC_EmitRegister, MVT::i32, AMDGPU::PRED_SEL_OFF,
/*17929*/       OPC_EmitInteger, MVT::i32, 0, 
/*17932*/       OPC_EmitInteger, MVT::i32, 0, 
/*17935*/       OPC_MorphNodeTo, TARGET_VAL(AMDGPU::MUL_IEEE), 0,
                    1/*#VTs*/, MVT::f32, 20/*#Ops*/, 2, 3, 4, 5, 6, 7, 0, 8, 9, 10, 11, 24, 25, 26, 27, 28, 29, 30, 31, 32, 
                // Src: (intrinsic_wo_chain:f32 3287:iPTR, f32:f32:$src0, f32:f32:$src1) - Complexity = 8
                // Dst: (MUL_IEEE:f32 ?:f32:$src0, (RECIP_IEEE_cm:i32 ?:f32:$src1))
/*17962*/     /*Scope*/ 19, /*->17982*/
/*17963*/       OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*17965*/       OPC_EmitNode, TARGET_VAL(AMDGPU::V_RCP_LEGACY_F32_e32), 0,
                    1/*#VTs*/, MVT::i32, 1/*#Ops*/, 1,  // Results = #2
/*17973*/       OPC_MorphNodeTo, TARGET_VAL(AMDGPU::V_MUL_LEGACY_F32_e32), 0,
                    1/*#VTs*/, MVT::f32, 2/*#Ops*/, 0, 2, 
                // Src: (intrinsic_wo_chain:f32 3287:iPTR, f32:f32:$src0, f32:f32:$src1) - Complexity = 8
                // Dst: (V_MUL_LEGACY_F32_e32:f32 ?:f32:$src0, (V_RCP_LEGACY_F32_e32:i32 ?:f32:$src1))
/*17982*/     0, /*End of Scope*/
/*17983*/   /*Scope*/ 63, /*->18047*/
/*17984*/     OPC_CheckInteger, 83|128,25/*3283*/, 
/*17987*/     OPC_MoveParent,
/*17988*/     OPC_RecordChild1, // #0 = $src0
/*17989*/     OPC_RecordChild2, // #1 = $src1
/*17990*/     OPC_RecordChild3, // #2 = $src2
/*17991*/     OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*17993*/     OPC_EmitInteger, MVT::i32, 0, 
/*17996*/     OPC_EmitInteger, MVT::i32, 0, 
/*17999*/     OPC_EmitInteger, MVT::i32, 0, 
/*18002*/     OPC_EmitInteger, MVT::i32, 0, 
/*18005*/     OPC_EmitInteger, MVT::i32, 0, 
/*18008*/     OPC_EmitNode, TARGET_VAL(AMDGPU::V_CMP_GT_F32_e64), 0,
                  1/*#VTs*/, MVT::i1, 6/*#Ops*/, 3, 0, 4, 5, 6, 7,  // Results = #8
/*18021*/     OPC_EmitInteger, MVT::i32, 0, 
/*18024*/     OPC_EmitInteger, MVT::i32, 0, 
/*18027*/     OPC_EmitInteger, MVT::i32, 0, 
/*18030*/     OPC_EmitInteger, MVT::i32, 0, 
/*18033*/     OPC_MorphNodeTo, TARGET_VAL(AMDGPU::V_CNDMASK_B32_e64), 0,
                  1/*#VTs*/, MVT::f32, 7/*#Ops*/, 2, 1, 8, 9, 10, 11, 12, 
              // Src: (intrinsic_wo_chain:f32 3283:iPTR, f32:f32:$src0, f32:f32:$src1, f32:f32:$src2) - Complexity = 8
              // Dst: (V_CNDMASK_B32_e64:f32 ?:f32:$src2, ?:f32:$src1, (V_CMP_GT_F32_e64:i1 0:i32, ?:f32:$src0))
/*18047*/   /*Scope*/ 35|128,5/*675*/, /*->18724*/
/*18049*/     OPC_CheckInteger, 113|128,26/*3441*/, 
/*18052*/     OPC_MoveParent,
/*18053*/     OPC_RecordChild1, // #0 = $src_x
/*18054*/     OPC_RecordChild2, // #1 = $src_y
/*18055*/     OPC_RecordChild3, // #2 = $src_w
/*18056*/     OPC_Scope, 75|128,2/*331*/, /*->18390*/ // 2 children in Scope
/*18059*/       OPC_CheckPatternPredicate, 1, // (Subtarget.getGeneration() <= AMDGPUSubtarget::R700)
/*18061*/       OPC_EmitInteger, MVT::i32, 1, 
/*18064*/       OPC_EmitInteger, MVT::i32, 0, 
/*18067*/       OPC_EmitInteger, MVT::i32, 0, 
/*18070*/       OPC_EmitInteger, MVT::i32, 0, 
/*18073*/       OPC_EmitInteger, MVT::i32, 0, 
/*18076*/       OPC_EmitInteger, MVT::i32, 0, 
/*18079*/       OPC_EmitInteger, MVT::i32, 1, 
/*18082*/       OPC_EmitInteger, MVT::i32, 0, 
/*18085*/       OPC_EmitInteger, MVT::i32, 0, 
/*18088*/       OPC_EmitInteger, MVT::i32, 0, 
/*18091*/       OPC_EmitInteger, MVT::i32, 0, 
/*18094*/       OPC_EmitInteger, MVT::i32, 0, 
/*18097*/       OPC_EmitInteger, MVT::i32, 1, 
/*18100*/       OPC_EmitInteger, MVT::i32, 0, 
/*18103*/       OPC_EmitInteger, MVT::i32, 0, 
/*18106*/       OPC_EmitInteger, MVT::i32, 0, 
/*18109*/       OPC_EmitInteger, MVT::i32, 0, 
/*18112*/       OPC_EmitInteger, MVT::i32, 0, 
/*18115*/       OPC_EmitInteger, MVT::i32, 0, 
/*18118*/       OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*18130*/       OPC_EmitRegister, MVT::f32, AMDGPU::ZERO,
/*18133*/       OPC_EmitInteger, MVT::i32, 0, 
/*18136*/       OPC_EmitInteger, MVT::i32, 0, 
/*18139*/       OPC_EmitInteger, MVT::i32, 0, 
/*18142*/       OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*18154*/       OPC_EmitInteger, MVT::i32, 1, 
/*18157*/       OPC_EmitRegister, MVT::i32, AMDGPU::PRED_SEL_OFF,
/*18160*/       OPC_EmitInteger, MVT::i32, 0, 
/*18163*/       OPC_EmitInteger, MVT::i32, 0, 
/*18166*/       OPC_EmitNode, TARGET_VAL(AMDGPU::MAX), 0,
                    1/*#VTs*/, MVT::i32, 20/*#Ops*/, 13, 14, 15, 16, 17, 18, 1, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31,  // Results = #32
/*18193*/       OPC_EmitInteger, MVT::i32, 0, 
/*18196*/       OPC_EmitInteger, MVT::i32, 0, 
/*18199*/       OPC_EmitInteger, MVT::i32, 0, 
/*18202*/       OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*18214*/       OPC_EmitInteger, MVT::i32, 1, 
/*18217*/       OPC_EmitRegister, MVT::i32, AMDGPU::PRED_SEL_OFF,
/*18220*/       OPC_EmitInteger, MVT::i32, 0, 
/*18223*/       OPC_EmitInteger, MVT::i32, 0, 
/*18226*/       OPC_EmitNode, TARGET_VAL(AMDGPU::LOG_CLAMPED_r600), 0,
                    1/*#VTs*/, MVT::i32, 13/*#Ops*/, 9, 10, 11, 12, 32, 33, 34, 35, 36, 37, 38, 39, 40,  // Results = #41
/*18246*/       OPC_EmitInteger, MVT::i32, 0, 
/*18249*/       OPC_EmitInteger, MVT::i32, 0, 
/*18252*/       OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*18264*/       OPC_EmitInteger, MVT::i32, 0, 
/*18267*/       OPC_EmitInteger, MVT::i32, 0, 
/*18270*/       OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*18282*/       OPC_EmitInteger, MVT::i32, 0, 
/*18285*/       OPC_EmitInteger, MVT::i32, 0, 
/*18288*/       OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*18300*/       OPC_EmitInteger, MVT::i32, 1, 
/*18303*/       OPC_EmitRegister, MVT::i32, AMDGPU::PRED_SEL_OFF,
/*18306*/       OPC_EmitInteger, MVT::i32, 0, 
/*18309*/       OPC_EmitInteger, MVT::i32, 0, 
/*18312*/       OPC_EmitNode, TARGET_VAL(AMDGPU::MUL_LIT_r600), 0,
                    1/*#VTs*/, MVT::i32, 18/*#Ops*/, 7, 8, 41, 42, 43, 44, 2, 45, 46, 47, 0, 48, 49, 50, 51, 52, 53, 54,  // Results = #55
/*18337*/       OPC_EmitInteger, MVT::i32, 0, 
/*18340*/       OPC_EmitInteger, MVT::i32, 0, 
/*18343*/       OPC_EmitInteger, MVT::i32, 0, 
/*18346*/       OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*18358*/       OPC_EmitInteger, MVT::i32, 1, 
/*18361*/       OPC_EmitRegister, MVT::i32, AMDGPU::PRED_SEL_OFF,
/*18364*/       OPC_EmitInteger, MVT::i32, 0, 
/*18367*/       OPC_EmitInteger, MVT::i32, 0, 
/*18370*/       OPC_MorphNodeTo, TARGET_VAL(AMDGPU::EXP_IEEE_r600), 0,
                    1/*#VTs*/, MVT::f32, 13/*#Ops*/, 3, 4, 5, 6, 55, 56, 57, 58, 59, 60, 61, 62, 63, 
                // Src: (intrinsic_wo_chain:f32 3441:iPTR, f32:f32:$src_x, f32:f32:$src_y, f32:f32:$src_w) - Complexity = 8
                // Dst: (EXP_IEEE_r600:f32 (MUL_LIT_r600:i32 (LOG_CLAMPED_r600:i32 (MAX:i32 ?:f32:$src_y, ZERO:f32)), ?:f32:$src_w, ?:f32:$src_x))
/*18390*/     /*Scope*/ 75|128,2/*331*/, /*->18723*/
/*18392*/       OPC_CheckPatternPredicate, 2, // (Subtarget.getGeneration() == AMDGPUSubtarget::EVERGREEN|| Subtarget.getGeneration() ==AMDGPUSubtarget::NORTHERN_ISLANDS)
/*18394*/       OPC_EmitInteger, MVT::i32, 1, 
/*18397*/       OPC_EmitInteger, MVT::i32, 0, 
/*18400*/       OPC_EmitInteger, MVT::i32, 0, 
/*18403*/       OPC_EmitInteger, MVT::i32, 0, 
/*18406*/       OPC_EmitInteger, MVT::i32, 0, 
/*18409*/       OPC_EmitInteger, MVT::i32, 0, 
/*18412*/       OPC_EmitInteger, MVT::i32, 1, 
/*18415*/       OPC_EmitInteger, MVT::i32, 0, 
/*18418*/       OPC_EmitInteger, MVT::i32, 0, 
/*18421*/       OPC_EmitInteger, MVT::i32, 0, 
/*18424*/       OPC_EmitInteger, MVT::i32, 0, 
/*18427*/       OPC_EmitInteger, MVT::i32, 0, 
/*18430*/       OPC_EmitInteger, MVT::i32, 1, 
/*18433*/       OPC_EmitInteger, MVT::i32, 0, 
/*18436*/       OPC_EmitInteger, MVT::i32, 0, 
/*18439*/       OPC_EmitInteger, MVT::i32, 0, 
/*18442*/       OPC_EmitInteger, MVT::i32, 0, 
/*18445*/       OPC_EmitInteger, MVT::i32, 0, 
/*18448*/       OPC_EmitInteger, MVT::i32, 0, 
/*18451*/       OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*18463*/       OPC_EmitRegister, MVT::f32, AMDGPU::ZERO,
/*18466*/       OPC_EmitInteger, MVT::i32, 0, 
/*18469*/       OPC_EmitInteger, MVT::i32, 0, 
/*18472*/       OPC_EmitInteger, MVT::i32, 0, 
/*18475*/       OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*18487*/       OPC_EmitInteger, MVT::i32, 1, 
/*18490*/       OPC_EmitRegister, MVT::i32, AMDGPU::PRED_SEL_OFF,
/*18493*/       OPC_EmitInteger, MVT::i32, 0, 
/*18496*/       OPC_EmitInteger, MVT::i32, 0, 
/*18499*/       OPC_EmitNode, TARGET_VAL(AMDGPU::MAX), 0,
                    1/*#VTs*/, MVT::i32, 20/*#Ops*/, 13, 14, 15, 16, 17, 18, 1, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31,  // Results = #32
/*18526*/       OPC_EmitInteger, MVT::i32, 0, 
/*18529*/       OPC_EmitInteger, MVT::i32, 0, 
/*18532*/       OPC_EmitInteger, MVT::i32, 0, 
/*18535*/       OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*18547*/       OPC_EmitInteger, MVT::i32, 1, 
/*18550*/       OPC_EmitRegister, MVT::i32, AMDGPU::PRED_SEL_OFF,
/*18553*/       OPC_EmitInteger, MVT::i32, 0, 
/*18556*/       OPC_EmitInteger, MVT::i32, 0, 
/*18559*/       OPC_EmitNode, TARGET_VAL(AMDGPU::LOG_CLAMPED_eg), 0,
                    1/*#VTs*/, MVT::i32, 13/*#Ops*/, 9, 10, 11, 12, 32, 33, 34, 35, 36, 37, 38, 39, 40,  // Results = #41
/*18579*/       OPC_EmitInteger, MVT::i32, 0, 
/*18582*/       OPC_EmitInteger, MVT::i32, 0, 
/*18585*/       OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*18597*/       OPC_EmitInteger, MVT::i32, 0, 
/*18600*/       OPC_EmitInteger, MVT::i32, 0, 
/*18603*/       OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*18615*/       OPC_EmitInteger, MVT::i32, 0, 
/*18618*/       OPC_EmitInteger, MVT::i32, 0, 
/*18621*/       OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*18633*/       OPC_EmitInteger, MVT::i32, 1, 
/*18636*/       OPC_EmitRegister, MVT::i32, AMDGPU::PRED_SEL_OFF,
/*18639*/       OPC_EmitInteger, MVT::i32, 0, 
/*18642*/       OPC_EmitInteger, MVT::i32, 0, 
/*18645*/       OPC_EmitNode, TARGET_VAL(AMDGPU::MUL_LIT_eg), 0,
                    1/*#VTs*/, MVT::i32, 18/*#Ops*/, 7, 8, 41, 42, 43, 44, 2, 45, 46, 47, 0, 48, 49, 50, 51, 52, 53, 54,  // Results = #55
/*18670*/       OPC_EmitInteger, MVT::i32, 0, 
/*18673*/       OPC_EmitInteger, MVT::i32, 0, 
/*18676*/       OPC_EmitInteger, MVT::i32, 0, 
/*18679*/       OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*18691*/       OPC_EmitInteger, MVT::i32, 1, 
/*18694*/       OPC_EmitRegister, MVT::i32, AMDGPU::PRED_SEL_OFF,
/*18697*/       OPC_EmitInteger, MVT::i32, 0, 
/*18700*/       OPC_EmitInteger, MVT::i32, 0, 
/*18703*/       OPC_MorphNodeTo, TARGET_VAL(AMDGPU::EXP_IEEE_eg), 0,
                    1/*#VTs*/, MVT::f32, 13/*#Ops*/, 3, 4, 5, 6, 55, 56, 57, 58, 59, 60, 61, 62, 63, 
                // Src: (intrinsic_wo_chain:f32 3441:iPTR, f32:f32:$src_x, f32:f32:$src_y, f32:f32:$src_w) - Complexity = 8
                // Dst: (EXP_IEEE_eg:f32 (MUL_LIT_eg:i32 (LOG_CLAMPED_eg:i32 (MAX:i32 ?:f32:$src_y, ZERO:f32)), ?:f32:$src_w, ?:f32:$src_x))
/*18723*/     0, /*End of Scope*/
/*18724*/   /*Scope*/ 19|128,3/*403*/, /*->19129*/
/*18726*/     OPC_CheckInteger, 101|128,26/*3429*/, 
/*18729*/     OPC_MoveParent,
/*18730*/     OPC_RecordChild1, // #0 = $addr
/*18731*/     OPC_Scope, 68|128,1/*196*/, /*->18930*/ // 2 children in Scope
/*18734*/       OPC_CheckChild1Type, MVT::v2i32,
/*18736*/       OPC_RecordChild2, // #1 = $rsrc
/*18737*/       OPC_MoveChild, 3,
/*18739*/       OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*18742*/       OPC_Scope, 46, /*->18790*/ // 4 children in Scope
/*18744*/         OPC_CheckPredicate, 42, // Predicate_TEX_ARRAY
/*18746*/         OPC_MoveParent,
/*18747*/         OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*18749*/         OPC_EmitInteger, MVT::i32, 15, 
/*18752*/         OPC_EmitInteger, MVT::i1, 0, 
/*18755*/         OPC_EmitInteger, MVT::i1, 0, 
/*18758*/         OPC_EmitInteger, MVT::i1, 1, 
/*18761*/         OPC_EmitInteger, MVT::i1, 0, 
/*18764*/         OPC_EmitInteger, MVT::i1, 0, 
/*18767*/         OPC_EmitInteger, MVT::i1, 0, 
/*18770*/         OPC_EmitInteger, MVT::i1, 0, 
/*18773*/         OPC_MorphNodeTo, TARGET_VAL(AMDGPU::IMAGE_LOAD_MIP_V4_V2), 0,
                      1/*#VTs*/, MVT::v4i32, 10/*#Ops*/, 2, 3, 4, 5, 6, 7, 8, 9, 0, 1, 
                  // Src: (intrinsic_wo_chain:v4i32 3429:iPTR, v2i32:v2i32:$addr, v32i8:v32i8:$rsrc, (imm:i32)<<P:Predicate_TEX_ARRAY>>) - Complexity = 12
                  // Dst: (IMAGE_LOAD_MIP_V4_V2:v4i32 15:i32, 0:i1, 0:i1, 1:i1, 0:i1, 0:i1, 0:i1, 0:i1, ?:v2i32:$addr, ?:v32i8:$rsrc)
/*18790*/       /*Scope*/ 46, /*->18837*/
/*18791*/         OPC_CheckPredicate, 43, // Predicate_TEX_MSAA
/*18793*/         OPC_MoveParent,
/*18794*/         OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*18796*/         OPC_EmitInteger, MVT::i32, 15, 
/*18799*/         OPC_EmitInteger, MVT::i1, 0, 
/*18802*/         OPC_EmitInteger, MVT::i1, 0, 
/*18805*/         OPC_EmitInteger, MVT::i1, 0, 
/*18808*/         OPC_EmitInteger, MVT::i1, 0, 
/*18811*/         OPC_EmitInteger, MVT::i1, 0, 
/*18814*/         OPC_EmitInteger, MVT::i1, 0, 
/*18817*/         OPC_EmitInteger, MVT::i1, 0, 
/*18820*/         OPC_MorphNodeTo, TARGET_VAL(AMDGPU::IMAGE_LOAD_V4_V2), 0,
                      1/*#VTs*/, MVT::v4i32, 10/*#Ops*/, 2, 3, 4, 5, 6, 7, 8, 9, 0, 1, 
                  // Src: (intrinsic_wo_chain:v4i32 3429:iPTR, v2i32:v2i32:$addr, v32i8:v32i8:$rsrc, (imm:i32)<<P:Predicate_TEX_MSAA>>) - Complexity = 12
                  // Dst: (IMAGE_LOAD_V4_V2:v4i32 15:i32, 0:i1, 0:i1, 0:i1, 0:i1, 0:i1, 0:i1, 0:i1, ?:v2i32:$addr, ?:v32i8:$rsrc)
/*18837*/       /*Scope*/ 46, /*->18884*/
/*18838*/         OPC_CheckPredicate, 44, // Predicate_TEX_ARRAY_MSAA
/*18840*/         OPC_MoveParent,
/*18841*/         OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*18843*/         OPC_EmitInteger, MVT::i32, 15, 
/*18846*/         OPC_EmitInteger, MVT::i1, 0, 
/*18849*/         OPC_EmitInteger, MVT::i1, 0, 
/*18852*/         OPC_EmitInteger, MVT::i1, 1, 
/*18855*/         OPC_EmitInteger, MVT::i1, 0, 
/*18858*/         OPC_EmitInteger, MVT::i1, 0, 
/*18861*/         OPC_EmitInteger, MVT::i1, 0, 
/*18864*/         OPC_EmitInteger, MVT::i1, 0, 
/*18867*/         OPC_MorphNodeTo, TARGET_VAL(AMDGPU::IMAGE_LOAD_V4_V2), 0,
                      1/*#VTs*/, MVT::v4i32, 10/*#Ops*/, 2, 3, 4, 5, 6, 7, 8, 9, 0, 1, 
                  // Src: (intrinsic_wo_chain:v4i32 3429:iPTR, v2i32:v2i32:$addr, v32i8:v32i8:$rsrc, (imm:i32)<<P:Predicate_TEX_ARRAY_MSAA>>) - Complexity = 12
                  // Dst: (IMAGE_LOAD_V4_V2:v4i32 15:i32, 0:i1, 0:i1, 1:i1, 0:i1, 0:i1, 0:i1, 0:i1, ?:v2i32:$addr, ?:v32i8:$rsrc)
/*18884*/       /*Scope*/ 44, /*->18929*/
/*18885*/         OPC_MoveParent,
/*18886*/         OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*18888*/         OPC_EmitInteger, MVT::i32, 15, 
/*18891*/         OPC_EmitInteger, MVT::i1, 0, 
/*18894*/         OPC_EmitInteger, MVT::i1, 0, 
/*18897*/         OPC_EmitInteger, MVT::i1, 0, 
/*18900*/         OPC_EmitInteger, MVT::i1, 0, 
/*18903*/         OPC_EmitInteger, MVT::i1, 0, 
/*18906*/         OPC_EmitInteger, MVT::i1, 0, 
/*18909*/         OPC_EmitInteger, MVT::i1, 0, 
/*18912*/         OPC_MorphNodeTo, TARGET_VAL(AMDGPU::IMAGE_LOAD_MIP_V4_V2), 0,
                      1/*#VTs*/, MVT::v4i32, 10/*#Ops*/, 2, 3, 4, 5, 6, 7, 8, 9, 0, 1, 
                  // Src: (intrinsic_wo_chain:v4i32 3429:iPTR, v2i32:v2i32:$addr, v32i8:v32i8:$rsrc, (imm:i32)) - Complexity = 11
                  // Dst: (IMAGE_LOAD_MIP_V4_V2:v4i32 15:i32, 0:i1, 0:i1, 0:i1, 0:i1, 0:i1, 0:i1, 0:i1, ?:v2i32:$addr, ?:v32i8:$rsrc)
/*18929*/       0, /*End of Scope*/
/*18930*/     /*Scope*/ 68|128,1/*196*/, /*->19128*/
/*18932*/       OPC_CheckChild1Type, MVT::v4i32,
/*18934*/       OPC_RecordChild2, // #1 = $rsrc
/*18935*/       OPC_MoveChild, 3,
/*18937*/       OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*18940*/       OPC_Scope, 46, /*->18988*/ // 4 children in Scope
/*18942*/         OPC_CheckPredicate, 42, // Predicate_TEX_ARRAY
/*18944*/         OPC_MoveParent,
/*18945*/         OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*18947*/         OPC_EmitInteger, MVT::i32, 15, 
/*18950*/         OPC_EmitInteger, MVT::i1, 0, 
/*18953*/         OPC_EmitInteger, MVT::i1, 0, 
/*18956*/         OPC_EmitInteger, MVT::i1, 1, 
/*18959*/         OPC_EmitInteger, MVT::i1, 0, 
/*18962*/         OPC_EmitInteger, MVT::i1, 0, 
/*18965*/         OPC_EmitInteger, MVT::i1, 0, 
/*18968*/         OPC_EmitInteger, MVT::i1, 0, 
/*18971*/         OPC_MorphNodeTo, TARGET_VAL(AMDGPU::IMAGE_LOAD_MIP_V4_V4), 0,
                      1/*#VTs*/, MVT::v4i32, 10/*#Ops*/, 2, 3, 4, 5, 6, 7, 8, 9, 0, 1, 
                  // Src: (intrinsic_wo_chain:v4i32 3429:iPTR, v4i32:v4i32:$addr, v32i8:v32i8:$rsrc, (imm:i32)<<P:Predicate_TEX_ARRAY>>) - Complexity = 12
                  // Dst: (IMAGE_LOAD_MIP_V4_V4:v4i32 15:i32, 0:i1, 0:i1, 1:i1, 0:i1, 0:i1, 0:i1, 0:i1, ?:v4i32:$addr, ?:v32i8:$rsrc)
/*18988*/       /*Scope*/ 46, /*->19035*/
/*18989*/         OPC_CheckPredicate, 43, // Predicate_TEX_MSAA
/*18991*/         OPC_MoveParent,
/*18992*/         OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*18994*/         OPC_EmitInteger, MVT::i32, 15, 
/*18997*/         OPC_EmitInteger, MVT::i1, 0, 
/*19000*/         OPC_EmitInteger, MVT::i1, 0, 
/*19003*/         OPC_EmitInteger, MVT::i1, 0, 
/*19006*/         OPC_EmitInteger, MVT::i1, 0, 
/*19009*/         OPC_EmitInteger, MVT::i1, 0, 
/*19012*/         OPC_EmitInteger, MVT::i1, 0, 
/*19015*/         OPC_EmitInteger, MVT::i1, 0, 
/*19018*/         OPC_MorphNodeTo, TARGET_VAL(AMDGPU::IMAGE_LOAD_V4_V4), 0,
                      1/*#VTs*/, MVT::v4i32, 10/*#Ops*/, 2, 3, 4, 5, 6, 7, 8, 9, 0, 1, 
                  // Src: (intrinsic_wo_chain:v4i32 3429:iPTR, v4i32:v4i32:$addr, v32i8:v32i8:$rsrc, (imm:i32)<<P:Predicate_TEX_MSAA>>) - Complexity = 12
                  // Dst: (IMAGE_LOAD_V4_V4:v4i32 15:i32, 0:i1, 0:i1, 0:i1, 0:i1, 0:i1, 0:i1, 0:i1, ?:v4i32:$addr, ?:v32i8:$rsrc)
/*19035*/       /*Scope*/ 46, /*->19082*/
/*19036*/         OPC_CheckPredicate, 44, // Predicate_TEX_ARRAY_MSAA
/*19038*/         OPC_MoveParent,
/*19039*/         OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*19041*/         OPC_EmitInteger, MVT::i32, 15, 
/*19044*/         OPC_EmitInteger, MVT::i1, 0, 
/*19047*/         OPC_EmitInteger, MVT::i1, 0, 
/*19050*/         OPC_EmitInteger, MVT::i1, 1, 
/*19053*/         OPC_EmitInteger, MVT::i1, 0, 
/*19056*/         OPC_EmitInteger, MVT::i1, 0, 
/*19059*/         OPC_EmitInteger, MVT::i1, 0, 
/*19062*/         OPC_EmitInteger, MVT::i1, 0, 
/*19065*/         OPC_MorphNodeTo, TARGET_VAL(AMDGPU::IMAGE_LOAD_V4_V4), 0,
                      1/*#VTs*/, MVT::v4i32, 10/*#Ops*/, 2, 3, 4, 5, 6, 7, 8, 9, 0, 1, 
                  // Src: (intrinsic_wo_chain:v4i32 3429:iPTR, v4i32:v4i32:$addr, v32i8:v32i8:$rsrc, (imm:i32)<<P:Predicate_TEX_ARRAY_MSAA>>) - Complexity = 12
                  // Dst: (IMAGE_LOAD_V4_V4:v4i32 15:i32, 0:i1, 0:i1, 1:i1, 0:i1, 0:i1, 0:i1, 0:i1, ?:v4i32:$addr, ?:v32i8:$rsrc)
/*19082*/       /*Scope*/ 44, /*->19127*/
/*19083*/         OPC_MoveParent,
/*19084*/         OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*19086*/         OPC_EmitInteger, MVT::i32, 15, 
/*19089*/         OPC_EmitInteger, MVT::i1, 0, 
/*19092*/         OPC_EmitInteger, MVT::i1, 0, 
/*19095*/         OPC_EmitInteger, MVT::i1, 0, 
/*19098*/         OPC_EmitInteger, MVT::i1, 0, 
/*19101*/         OPC_EmitInteger, MVT::i1, 0, 
/*19104*/         OPC_EmitInteger, MVT::i1, 0, 
/*19107*/         OPC_EmitInteger, MVT::i1, 0, 
/*19110*/         OPC_MorphNodeTo, TARGET_VAL(AMDGPU::IMAGE_LOAD_MIP_V4_V4), 0,
                      1/*#VTs*/, MVT::v4i32, 10/*#Ops*/, 2, 3, 4, 5, 6, 7, 8, 9, 0, 1, 
                  // Src: (intrinsic_wo_chain:v4i32 3429:iPTR, v4i32:v4i32:$addr, v32i8:v32i8:$rsrc, (imm:i32)) - Complexity = 11
                  // Dst: (IMAGE_LOAD_MIP_V4_V4:v4i32 15:i32, 0:i1, 0:i1, 0:i1, 0:i1, 0:i1, 0:i1, 0:i1, ?:v4i32:$addr, ?:v32i8:$rsrc)
/*19127*/       0, /*End of Scope*/
/*19128*/     0, /*End of Scope*/
/*19129*/   /*Scope*/ 48|128,1/*176*/, /*->19307*/
/*19131*/     OPC_CheckInteger, 105|128,26/*3433*/, 
/*19134*/     OPC_MoveParent,
/*19135*/     OPC_RecordChild1, // #0 = $mipid
/*19136*/     OPC_RecordChild2, // #1 = $rsrc
/*19137*/     OPC_MoveChild, 3,
/*19139*/     OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*19142*/     OPC_Scope, 54, /*->19198*/ // 3 children in Scope
/*19144*/       OPC_CheckPredicate, 42, // Predicate_TEX_ARRAY
/*19146*/       OPC_MoveParent,
/*19147*/       OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*19149*/       OPC_EmitInteger, MVT::i32, 15, 
/*19152*/       OPC_EmitInteger, MVT::i1, 0, 
/*19155*/       OPC_EmitInteger, MVT::i1, 0, 
/*19158*/       OPC_EmitInteger, MVT::i1, 1, 
/*19161*/       OPC_EmitInteger, MVT::i1, 0, 
/*19164*/       OPC_EmitInteger, MVT::i1, 0, 
/*19167*/       OPC_EmitInteger, MVT::i1, 0, 
/*19170*/       OPC_EmitInteger, MVT::i1, 0, 
/*19173*/       OPC_EmitNode, TARGET_VAL(AMDGPU::V_MOV_B32_e32), 0,
                    1/*#VTs*/, MVT::i32, 1/*#Ops*/, 0,  // Results = #10
/*19181*/       OPC_MorphNodeTo, TARGET_VAL(AMDGPU::IMAGE_GET_RESINFO_V4_V1), 0,
                    1/*#VTs*/, MVT::v4i32, 10/*#Ops*/, 2, 3, 4, 5, 6, 7, 8, 9, 10, 1, 
                // Src: (intrinsic_wo_chain:v4i32 3433:iPTR, i32:i32:$mipid, v32i8:v32i8:$rsrc, (imm:i32)<<P:Predicate_TEX_ARRAY>>) - Complexity = 12
                // Dst: (IMAGE_GET_RESINFO_V4_V1:v4i32 15:i32, 0:i1, 0:i1, 1:i1, 0:i1, 0:i1, 0:i1, 0:i1, (V_MOV_B32_e32:i32 ?:i32:$mipid), ?:v32i8:$rsrc)
/*19198*/     /*Scope*/ 54, /*->19253*/
/*19199*/       OPC_CheckPredicate, 44, // Predicate_TEX_ARRAY_MSAA
/*19201*/       OPC_MoveParent,
/*19202*/       OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*19204*/       OPC_EmitInteger, MVT::i32, 15, 
/*19207*/       OPC_EmitInteger, MVT::i1, 0, 
/*19210*/       OPC_EmitInteger, MVT::i1, 0, 
/*19213*/       OPC_EmitInteger, MVT::i1, 1, 
/*19216*/       OPC_EmitInteger, MVT::i1, 0, 
/*19219*/       OPC_EmitInteger, MVT::i1, 0, 
/*19222*/       OPC_EmitInteger, MVT::i1, 0, 
/*19225*/       OPC_EmitInteger, MVT::i1, 0, 
/*19228*/       OPC_EmitNode, TARGET_VAL(AMDGPU::V_MOV_B32_e32), 0,
                    1/*#VTs*/, MVT::i32, 1/*#Ops*/, 0,  // Results = #10
/*19236*/       OPC_MorphNodeTo, TARGET_VAL(AMDGPU::IMAGE_GET_RESINFO_V4_V1), 0,
                    1/*#VTs*/, MVT::v4i32, 10/*#Ops*/, 2, 3, 4, 5, 6, 7, 8, 9, 10, 1, 
                // Src: (intrinsic_wo_chain:v4i32 3433:iPTR, i32:i32:$mipid, v32i8:v32i8:$rsrc, (imm:i32)<<P:Predicate_TEX_ARRAY_MSAA>>) - Complexity = 12
                // Dst: (IMAGE_GET_RESINFO_V4_V1:v4i32 15:i32, 0:i1, 0:i1, 1:i1, 0:i1, 0:i1, 0:i1, 0:i1, (V_MOV_B32_e32:i32 ?:i32:$mipid), ?:v32i8:$rsrc)
/*19253*/     /*Scope*/ 52, /*->19306*/
/*19254*/       OPC_MoveParent,
/*19255*/       OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*19257*/       OPC_EmitInteger, MVT::i32, 15, 
/*19260*/       OPC_EmitInteger, MVT::i1, 0, 
/*19263*/       OPC_EmitInteger, MVT::i1, 0, 
/*19266*/       OPC_EmitInteger, MVT::i1, 0, 
/*19269*/       OPC_EmitInteger, MVT::i1, 0, 
/*19272*/       OPC_EmitInteger, MVT::i1, 0, 
/*19275*/       OPC_EmitInteger, MVT::i1, 0, 
/*19278*/       OPC_EmitInteger, MVT::i1, 0, 
/*19281*/       OPC_EmitNode, TARGET_VAL(AMDGPU::V_MOV_B32_e32), 0,
                    1/*#VTs*/, MVT::i32, 1/*#Ops*/, 0,  // Results = #10
/*19289*/       OPC_MorphNodeTo, TARGET_VAL(AMDGPU::IMAGE_GET_RESINFO_V4_V1), 0,
                    1/*#VTs*/, MVT::v4i32, 10/*#Ops*/, 2, 3, 4, 5, 6, 7, 8, 9, 10, 1, 
                // Src: (intrinsic_wo_chain:v4i32 3433:iPTR, i32:i32:$mipid, v32i8:v32i8:$rsrc, (imm:i32)) - Complexity = 11
                // Dst: (IMAGE_GET_RESINFO_V4_V1:v4i32 15:i32, 0:i1, 0:i1, 0:i1, 0:i1, 0:i1, 0:i1, 0:i1, (V_MOV_B32_e32:i32 ?:i32:$mipid), ?:v32i8:$rsrc)
/*19306*/     0, /*End of Scope*/
/*19307*/   /*Scope*/ 29, /*->19337*/
/*19308*/     OPC_CheckInteger, 78|128,26/*3406*/, 
/*19311*/     OPC_MoveParent,
/*19312*/     OPC_RecordChild1, // #0 = $ptr
/*19313*/     OPC_RecordChild2, // #1 = $BUFFER_ID
/*19314*/     OPC_MoveChild, 2,
/*19316*/     OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*19319*/     OPC_MoveParent,
/*19320*/     OPC_CheckPatternPredicate, 3, // (Subtarget.getGeneration() <= AMDGPUSubtarget::NORTHERN_ISLANDS)
/*19322*/     OPC_CheckComplexPat, /*CP*/5, /*#*/0, // SelectGlobalValueVariableOffset:$ptr #2 #3
/*19325*/     OPC_EmitConvertToTarget, 1,
/*19327*/     OPC_MorphNodeTo, TARGET_VAL(AMDGPU::TEX_VTX_TEXBUF), 0,
                  1/*#VTs*/, MVT::v4f32, 3/*#Ops*/, 2, 3, 4, 
              // Src: (intrinsic_wo_chain:v4f32 3406:iPTR, ADDRGA_VAR_OFFSET:i32:$ptr, (imm:i32):$BUFFER_ID) - Complexity = 20
              // Dst: (TEX_VTX_TEXBUF:v4f32 ADDRGA_VAR_OFFSET:i32:$ptr, (imm:i32):$BUFFER_ID)
/*19337*/   /*Scope*/ 77, /*->19415*/
/*19338*/     OPC_CheckInteger, 112|128,25/*3312*/, 
/*19341*/     OPC_MoveParent,
/*19342*/     OPC_RecordChild1, // #0 = $src0
/*19343*/     OPC_RecordChild2, // #1 = $src1
/*19344*/     OPC_RecordChild3, // #2 = $src2
/*19345*/     OPC_RecordChild4, // #3 = $resourceId
/*19346*/     OPC_MoveChild, 4,
/*19348*/     OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*19351*/     OPC_MoveParent,
/*19352*/     OPC_RecordChild5, // #4 = $samplerId
/*19353*/     OPC_MoveChild, 5,
/*19355*/     OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*19358*/     OPC_MoveParent,
/*19359*/     OPC_RecordChild6, // #5 = $textureTarget
/*19360*/     OPC_MoveChild, 6,
/*19362*/     OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*19365*/     OPC_Scope, 24, /*->19391*/ // 2 children in Scope
/*19367*/       OPC_CheckPredicate, 45, // Predicate_TEX_SHADOW
/*19369*/       OPC_MoveParent,
/*19370*/       OPC_CheckPatternPredicate, 3, // (Subtarget.getGeneration() <= AMDGPUSubtarget::NORTHERN_ISLANDS)
/*19372*/       OPC_EmitConvertToTarget, 3,
/*19374*/       OPC_EmitConvertToTarget, 4,
/*19376*/       OPC_EmitConvertToTarget, 5,
/*19378*/       OPC_MorphNodeTo, TARGET_VAL(AMDGPU::TXD_SHADOW), 0,
                    1/*#VTs*/, MVT::v4f32, 6/*#Ops*/, 0, 1, 2, 6, 7, 8, 
                // Src: (intrinsic_wo_chain:v4f32 3312:iPTR, v4f32:v4f32:$src0, v4f32:v4f32:$src1, v4f32:v4f32:$src2, (imm:i32):$resourceId, (imm:i32):$samplerId, (imm:i32)<<P:Predicate_TEX_SHADOW>>:$textureTarget) - Complexity = 18
                // Dst: (TXD_SHADOW:v4f32 v4f32:v4f32:$src0, v4f32:v4f32:$src1, v4f32:v4f32:$src2, (imm:i32):$resourceId, (imm:i32):$samplerId, (imm:i32):$textureTarget)
/*19391*/     /*Scope*/ 22, /*->19414*/
/*19392*/       OPC_MoveParent,
/*19393*/       OPC_CheckPatternPredicate, 3, // (Subtarget.getGeneration() <= AMDGPUSubtarget::NORTHERN_ISLANDS)
/*19395*/       OPC_EmitConvertToTarget, 3,
/*19397*/       OPC_EmitConvertToTarget, 4,
/*19399*/       OPC_EmitConvertToTarget, 5,
/*19401*/       OPC_MorphNodeTo, TARGET_VAL(AMDGPU::TXD), 0,
                    1/*#VTs*/, MVT::v4f32, 6/*#Ops*/, 0, 1, 2, 6, 7, 8, 
                // Src: (intrinsic_wo_chain:v4f32 3312:iPTR, v4f32:v4f32:$src0, v4f32:v4f32:$src1, v4f32:v4f32:$src2, (imm:i32):$resourceId, (imm:i32):$samplerId, (imm:i32):$textureTarget) - Complexity = 17
                // Dst: (TXD:v4f32 v4f32:v4f32:$src0, v4f32:v4f32:$src1, v4f32:v4f32:$src2, (imm:i32):$resourceId, (imm:i32):$samplerId, (imm:i32):$textureTarget)
/*19414*/     0, /*End of Scope*/
/*19415*/   /*Scope*/ 21, /*->19437*/
/*19416*/     OPC_CheckInteger, 72|128,26/*3400*/, 
/*19419*/     OPC_MoveParent,
/*19420*/     OPC_RecordChild1, // #0 = $src0
/*19421*/     OPC_MoveChild, 1,
/*19423*/     OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*19426*/     OPC_MoveParent,
/*19427*/     OPC_EmitConvertToTarget, 0,
/*19429*/     OPC_MorphNodeTo, TARGET_VAL(AMDGPU::INTERP_VEC_LOAD), 0,
                  1/*#VTs*/, MVT::v4f32, 1/*#Ops*/, 1, 
              // Src: (intrinsic_wo_chain:v4f32 3400:iPTR, (imm:i32):$src0) - Complexity = 11
              // Dst: (INTERP_VEC_LOAD:v4f32 (imm:i32):$src0)
/*19437*/   /*Scope*/ 84|128,2/*340*/, /*->19779*/
/*19439*/     OPC_CheckInteger, 84|128,25/*3284*/, 
/*19442*/     OPC_MoveParent,
/*19443*/     OPC_RecordChild1, // #0 = $src0
/*19444*/     OPC_Scope, 10, /*->19456*/ // 3 children in Scope
/*19446*/       OPC_CheckPatternPredicate, 1, // (Subtarget.getGeneration() <= AMDGPUSubtarget::R700)
/*19448*/       OPC_MorphNodeTo, TARGET_VAL(AMDGPU::CUBE_r600_pseudo), 0,
                    1/*#VTs*/, MVT::v4f32, 1/*#Ops*/, 0, 
                // Src: (intrinsic_wo_chain:v4f32 3284:iPTR, v4f32:v4f32:$src0) - Complexity = 8
                // Dst: (CUBE_r600_pseudo:v4f32 v4f32:v4f32:$src0)
/*19456*/     /*Scope*/ 10, /*->19467*/
/*19457*/       OPC_CheckPatternPredicate, 2, // (Subtarget.getGeneration() == AMDGPUSubtarget::EVERGREEN|| Subtarget.getGeneration() ==AMDGPUSubtarget::NORTHERN_ISLANDS)
/*19459*/       OPC_MorphNodeTo, TARGET_VAL(AMDGPU::CUBE_eg_pseudo), 0,
                    1/*#VTs*/, MVT::v4f32, 1/*#Ops*/, 0, 
                // Src: (intrinsic_wo_chain:v4f32 3284:iPTR, v4f32:v4f32:$src0) - Complexity = 8
                // Dst: (CUBE_eg_pseudo:v4f32 v4f32:v4f32:$src0)
/*19467*/     /*Scope*/ 53|128,2/*309*/, /*->19778*/
/*19469*/       OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*19471*/       OPC_EmitNode, TARGET_VAL(TargetOpcode::IMPLICIT_DEF), 0,
                    1/*#VTs*/, MVT::v4f32, 0/*#Ops*/,  // Results = #1
/*19478*/       OPC_EmitInteger, MVT::i32, AMDGPU::sub0,
/*19481*/       OPC_EmitNode, TARGET_VAL(TargetOpcode::EXTRACT_SUBREG), 0,
                    1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 2,  // Results = #3
/*19490*/       OPC_EmitInteger, MVT::i32, AMDGPU::sub1,
/*19493*/       OPC_EmitNode, TARGET_VAL(TargetOpcode::EXTRACT_SUBREG), 0,
                    1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 4,  // Results = #5
/*19502*/       OPC_EmitInteger, MVT::i32, AMDGPU::sub2,
/*19505*/       OPC_EmitNode, TARGET_VAL(TargetOpcode::EXTRACT_SUBREG), 0,
                    1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 6,  // Results = #7
/*19514*/       OPC_EmitInteger, MVT::i32, 0, 
/*19517*/       OPC_EmitInteger, MVT::i32, 0, 
/*19520*/       OPC_EmitInteger, MVT::i32, 0, 
/*19523*/       OPC_EmitInteger, MVT::i32, 0, 
/*19526*/       OPC_EmitNode, TARGET_VAL(AMDGPU::V_CUBETC_F32), 0,
                    1/*#VTs*/, MVT::i32, 7/*#Ops*/, 3, 5, 7, 8, 9, 10, 11,  // Results = #12
/*19540*/       OPC_EmitInteger, MVT::i32, AMDGPU::sub0,
/*19543*/       OPC_EmitNode, TARGET_VAL(TargetOpcode::INSERT_SUBREG), 0,
                    1/*#VTs*/, MVT::v4f32, 3/*#Ops*/, 1, 12, 13,  // Results = #14
/*19553*/       OPC_EmitInteger, MVT::i32, AMDGPU::sub0,
/*19556*/       OPC_EmitNode, TARGET_VAL(TargetOpcode::EXTRACT_SUBREG), 0,
                    1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 15,  // Results = #16
/*19565*/       OPC_EmitInteger, MVT::i32, AMDGPU::sub1,
/*19568*/       OPC_EmitNode, TARGET_VAL(TargetOpcode::EXTRACT_SUBREG), 0,
                    1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 17,  // Results = #18
/*19577*/       OPC_EmitInteger, MVT::i32, AMDGPU::sub2,
/*19580*/       OPC_EmitNode, TARGET_VAL(TargetOpcode::EXTRACT_SUBREG), 0,
                    1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 19,  // Results = #20
/*19589*/       OPC_EmitInteger, MVT::i32, 0, 
/*19592*/       OPC_EmitInteger, MVT::i32, 0, 
/*19595*/       OPC_EmitInteger, MVT::i32, 0, 
/*19598*/       OPC_EmitInteger, MVT::i32, 0, 
/*19601*/       OPC_EmitNode, TARGET_VAL(AMDGPU::V_CUBESC_F32), 0,
                    1/*#VTs*/, MVT::i32, 7/*#Ops*/, 16, 18, 20, 21, 22, 23, 24,  // Results = #25
/*19615*/       OPC_EmitInteger, MVT::i32, AMDGPU::sub1,
/*19618*/       OPC_EmitNode, TARGET_VAL(TargetOpcode::INSERT_SUBREG), 0,
                    1/*#VTs*/, MVT::v4f32, 3/*#Ops*/, 14, 25, 26,  // Results = #27
/*19628*/       OPC_EmitInteger, MVT::i32, AMDGPU::sub0,
/*19631*/       OPC_EmitNode, TARGET_VAL(TargetOpcode::EXTRACT_SUBREG), 0,
                    1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 28,  // Results = #29
/*19640*/       OPC_EmitInteger, MVT::i32, AMDGPU::sub1,
/*19643*/       OPC_EmitNode, TARGET_VAL(TargetOpcode::EXTRACT_SUBREG), 0,
                    1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 30,  // Results = #31
/*19652*/       OPC_EmitInteger, MVT::i32, AMDGPU::sub2,
/*19655*/       OPC_EmitNode, TARGET_VAL(TargetOpcode::EXTRACT_SUBREG), 0,
                    1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 32,  // Results = #33
/*19664*/       OPC_EmitInteger, MVT::i32, 0, 
/*19667*/       OPC_EmitInteger, MVT::i32, 0, 
/*19670*/       OPC_EmitInteger, MVT::i32, 0, 
/*19673*/       OPC_EmitInteger, MVT::i32, 0, 
/*19676*/       OPC_EmitNode, TARGET_VAL(AMDGPU::V_CUBEMA_F32), 0,
                    1/*#VTs*/, MVT::i32, 7/*#Ops*/, 29, 31, 33, 34, 35, 36, 37,  // Results = #38
/*19690*/       OPC_EmitInteger, MVT::i32, AMDGPU::sub2,
/*19693*/       OPC_EmitNode, TARGET_VAL(TargetOpcode::INSERT_SUBREG), 0,
                    1/*#VTs*/, MVT::v4f32, 3/*#Ops*/, 27, 38, 39,  // Results = #40
/*19703*/       OPC_EmitInteger, MVT::i32, AMDGPU::sub0,
/*19706*/       OPC_EmitNode, TARGET_VAL(TargetOpcode::EXTRACT_SUBREG), 0,
                    1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 41,  // Results = #42
/*19715*/       OPC_EmitInteger, MVT::i32, AMDGPU::sub1,
/*19718*/       OPC_EmitNode, TARGET_VAL(TargetOpcode::EXTRACT_SUBREG), 0,
                    1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 43,  // Results = #44
/*19727*/       OPC_EmitInteger, MVT::i32, AMDGPU::sub2,
/*19730*/       OPC_EmitNode, TARGET_VAL(TargetOpcode::EXTRACT_SUBREG), 0,
                    1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 45,  // Results = #46
/*19739*/       OPC_EmitInteger, MVT::i32, 0, 
/*19742*/       OPC_EmitInteger, MVT::i32, 0, 
/*19745*/       OPC_EmitInteger, MVT::i32, 0, 
/*19748*/       OPC_EmitInteger, MVT::i32, 0, 
/*19751*/       OPC_EmitNode, TARGET_VAL(AMDGPU::V_CUBEID_F32), 0,
                    1/*#VTs*/, MVT::i32, 7/*#Ops*/, 42, 44, 46, 47, 48, 49, 50,  // Results = #51
/*19765*/       OPC_EmitInteger, MVT::i32, AMDGPU::sub3,
/*19768*/       OPC_MorphNodeTo, TARGET_VAL(TargetOpcode::INSERT_SUBREG), 0,
                    1/*#VTs*/, MVT::v4f32, 3/*#Ops*/, 40, 51, 52, 
                // Src: (intrinsic_wo_chain:v4f32 3284:iPTR, v4f32:v4f32:$src) - Complexity = 8
                // Dst: (INSERT_SUBREG:v4f32 (INSERT_SUBREG:v4f32 (INSERT_SUBREG:v4f32 (INSERT_SUBREG:v4f32 (IMPLICIT_DEF:v4f32), (V_CUBETC_F32:i32 (EXTRACT_SUBREG:i32 ?:v4f32:$src, sub0:i32), (EXTRACT_SUBREG:i32 ?:v4f32:$src, sub1:i32), (EXTRACT_SUBREG:i32 ?:v4f32:$src, sub2:i32)), sub0:i32), (V_CUBESC_F32:i32 (EXTRACT_SUBREG:i32 ?:v4f32:$src, sub0:i32), (EXTRACT_SUBREG:i32 ?:v4f32:$src, sub1:i32), (EXTRACT_SUBREG:i32 ?:v4f32:$src, sub2:i32)), sub1:i32), (V_CUBEMA_F32:i32 (EXTRACT_SUBREG:i32 ?:v4f32:$src, sub0:i32), (EXTRACT_SUBREG:i32 ?:v4f32:$src, sub1:i32), (EXTRACT_SUBREG:i32 ?:v4f32:$src, sub2:i32)), sub2:i32), (V_CUBEID_F32:i32 (EXTRACT_SUBREG:i32 ?:v4f32:$src, sub0:i32), (EXTRACT_SUBREG:i32 ?:v4f32:$src, sub1:i32), (EXTRACT_SUBREG:i32 ?:v4f32:$src, sub2:i32)), sub3:i32)
/*19778*/     0, /*End of Scope*/
/*19779*/   0, /*End of Scope*/
/*19780*/ /*SwitchOpcode*/ 18|128,14/*1810*/,  TARGET_VAL(ISD::EXTRACT_VECTOR_ELT),// ->21594
/*19784*/   OPC_RecordChild0, // #0 = $src
/*19785*/   OPC_Scope, 30|128,1/*158*/, /*->19946*/ // 8 children in Scope
/*19788*/     OPC_CheckChild0Type, MVT::v4i32,
/*19790*/     OPC_MoveChild, 1,
/*19792*/     OPC_Scope, 37, /*->19831*/ // 4 children in Scope
/*19794*/       OPC_CheckInteger, 0, 
/*19796*/       OPC_MoveParent,
/*19797*/       OPC_CheckType, MVT::i32,
/*19799*/       OPC_Scope, 14, /*->19815*/ // 2 children in Scope
/*19801*/         OPC_CheckPatternPredicate, 3, // (Subtarget.getGeneration() <= AMDGPUSubtarget::NORTHERN_ISLANDS)
/*19803*/         OPC_EmitInteger, MVT::i32, AMDGPU::sub0,
/*19806*/         OPC_MorphNodeTo, TARGET_VAL(TargetOpcode::EXTRACT_SUBREG), 0,
                      1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1, 
                  // Src: (vector_extract:i32 v4i32:v4i32:$src, 0:iPTR) - Complexity = 8
                  // Dst: (EXTRACT_SUBREG:i32 ?:v4i32:$src, sub0:i32)
/*19815*/       /*Scope*/ 14, /*->19830*/
/*19816*/         OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*19818*/         OPC_EmitInteger, MVT::i32, AMDGPU::sub0,
/*19821*/         OPC_MorphNodeTo, TARGET_VAL(TargetOpcode::EXTRACT_SUBREG), 0,
                      1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1, 
                  // Src: (vector_extract:i32 v4i32:v4i32:$src, 0:iPTR) - Complexity = 8
                  // Dst: (EXTRACT_SUBREG:i32 ?:v4i32:$src, sub0:i32)
/*19830*/       0, /*End of Scope*/
/*19831*/     /*Scope*/ 37, /*->19869*/
/*19832*/       OPC_CheckInteger, 1, 
/*19834*/       OPC_MoveParent,
/*19835*/       OPC_CheckType, MVT::i32,
/*19837*/       OPC_Scope, 14, /*->19853*/ // 2 children in Scope
/*19839*/         OPC_CheckPatternPredicate, 3, // (Subtarget.getGeneration() <= AMDGPUSubtarget::NORTHERN_ISLANDS)
/*19841*/         OPC_EmitInteger, MVT::i32, AMDGPU::sub1,
/*19844*/         OPC_MorphNodeTo, TARGET_VAL(TargetOpcode::EXTRACT_SUBREG), 0,
                      1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1, 
                  // Src: (vector_extract:i32 v4i32:v4i32:$src, 1:iPTR) - Complexity = 8
                  // Dst: (EXTRACT_SUBREG:i32 ?:v4i32:$src, sub1:i32)
/*19853*/       /*Scope*/ 14, /*->19868*/
/*19854*/         OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*19856*/         OPC_EmitInteger, MVT::i32, AMDGPU::sub1,
/*19859*/         OPC_MorphNodeTo, TARGET_VAL(TargetOpcode::EXTRACT_SUBREG), 0,
                      1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1, 
                  // Src: (vector_extract:i32 v4i32:v4i32:$src, 1:iPTR) - Complexity = 8
                  // Dst: (EXTRACT_SUBREG:i32 ?:v4i32:$src, sub1:i32)
/*19868*/       0, /*End of Scope*/
/*19869*/     /*Scope*/ 37, /*->19907*/
/*19870*/       OPC_CheckInteger, 2, 
/*19872*/       OPC_MoveParent,
/*19873*/       OPC_CheckType, MVT::i32,
/*19875*/       OPC_Scope, 14, /*->19891*/ // 2 children in Scope
/*19877*/         OPC_CheckPatternPredicate, 3, // (Subtarget.getGeneration() <= AMDGPUSubtarget::NORTHERN_ISLANDS)
/*19879*/         OPC_EmitInteger, MVT::i32, AMDGPU::sub2,
/*19882*/         OPC_MorphNodeTo, TARGET_VAL(TargetOpcode::EXTRACT_SUBREG), 0,
                      1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1, 
                  // Src: (vector_extract:i32 v4i32:v4i32:$src, 2:iPTR) - Complexity = 8
                  // Dst: (EXTRACT_SUBREG:i32 ?:v4i32:$src, sub2:i32)
/*19891*/       /*Scope*/ 14, /*->19906*/
/*19892*/         OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*19894*/         OPC_EmitInteger, MVT::i32, AMDGPU::sub2,
/*19897*/         OPC_MorphNodeTo, TARGET_VAL(TargetOpcode::EXTRACT_SUBREG), 0,
                      1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1, 
                  // Src: (vector_extract:i32 v4i32:v4i32:$src, 2:iPTR) - Complexity = 8
                  // Dst: (EXTRACT_SUBREG:i32 ?:v4i32:$src, sub2:i32)
/*19906*/       0, /*End of Scope*/
/*19907*/     /*Scope*/ 37, /*->19945*/
/*19908*/       OPC_CheckInteger, 3, 
/*19910*/       OPC_MoveParent,
/*19911*/       OPC_CheckType, MVT::i32,
/*19913*/       OPC_Scope, 14, /*->19929*/ // 2 children in Scope
/*19915*/         OPC_CheckPatternPredicate, 3, // (Subtarget.getGeneration() <= AMDGPUSubtarget::NORTHERN_ISLANDS)
/*19917*/         OPC_EmitInteger, MVT::i32, AMDGPU::sub3,
/*19920*/         OPC_MorphNodeTo, TARGET_VAL(TargetOpcode::EXTRACT_SUBREG), 0,
                      1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1, 
                  // Src: (vector_extract:i32 v4i32:v4i32:$src, 3:iPTR) - Complexity = 8
                  // Dst: (EXTRACT_SUBREG:i32 ?:v4i32:$src, sub3:i32)
/*19929*/       /*Scope*/ 14, /*->19944*/
/*19930*/         OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*19932*/         OPC_EmitInteger, MVT::i32, AMDGPU::sub3,
/*19935*/         OPC_MorphNodeTo, TARGET_VAL(TargetOpcode::EXTRACT_SUBREG), 0,
                      1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1, 
                  // Src: (vector_extract:i32 v4i32:v4i32:$src, 3:iPTR) - Complexity = 8
                  // Dst: (EXTRACT_SUBREG:i32 ?:v4i32:$src, sub3:i32)
/*19944*/       0, /*End of Scope*/
/*19945*/     0, /*End of Scope*/
/*19946*/   /*Scope*/ 102, /*->20049*/
/*19947*/     OPC_CheckChild0Type, MVT::v2i32,
/*19949*/     OPC_MoveChild, 1,
/*19951*/     OPC_Scope, 37, /*->19990*/ // 3 children in Scope
/*19953*/       OPC_CheckInteger, 0, 
/*19955*/       OPC_MoveParent,
/*19956*/       OPC_CheckType, MVT::i32,
/*19958*/       OPC_Scope, 14, /*->19974*/ // 2 children in Scope
/*19960*/         OPC_CheckPatternPredicate, 3, // (Subtarget.getGeneration() <= AMDGPUSubtarget::NORTHERN_ISLANDS)
/*19962*/         OPC_EmitInteger, MVT::i32, AMDGPU::sub0,
/*19965*/         OPC_MorphNodeTo, TARGET_VAL(TargetOpcode::EXTRACT_SUBREG), 0,
                      1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1, 
                  // Src: (vector_extract:i32 v2i32:v2i32:$src, 0:iPTR) - Complexity = 8
                  // Dst: (EXTRACT_SUBREG:i32 ?:v2i32:$src, sub0:i32)
/*19974*/       /*Scope*/ 14, /*->19989*/
/*19975*/         OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*19977*/         OPC_EmitInteger, MVT::i32, AMDGPU::sub0,
/*19980*/         OPC_MorphNodeTo, TARGET_VAL(TargetOpcode::EXTRACT_SUBREG), 0,
                      1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1, 
                  // Src: (vector_extract:i32 v2i32:v2i32:$src, 0:iPTR) - Complexity = 8
                  // Dst: (EXTRACT_SUBREG:i32 ?:v2i32:$src, sub0:i32)
/*19989*/       0, /*End of Scope*/
/*19990*/     /*Scope*/ 37, /*->20028*/
/*19991*/       OPC_CheckInteger, 1, 
/*19993*/       OPC_MoveParent,
/*19994*/       OPC_CheckType, MVT::i32,
/*19996*/       OPC_Scope, 14, /*->20012*/ // 2 children in Scope
/*19998*/         OPC_CheckPatternPredicate, 3, // (Subtarget.getGeneration() <= AMDGPUSubtarget::NORTHERN_ISLANDS)
/*20000*/         OPC_EmitInteger, MVT::i32, AMDGPU::sub1,
/*20003*/         OPC_MorphNodeTo, TARGET_VAL(TargetOpcode::EXTRACT_SUBREG), 0,
                      1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1, 
                  // Src: (vector_extract:i32 v2i32:v2i32:$src, 1:iPTR) - Complexity = 8
                  // Dst: (EXTRACT_SUBREG:i32 ?:v2i32:$src, sub1:i32)
/*20012*/       /*Scope*/ 14, /*->20027*/
/*20013*/         OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*20015*/         OPC_EmitInteger, MVT::i32, AMDGPU::sub1,
/*20018*/         OPC_MorphNodeTo, TARGET_VAL(TargetOpcode::EXTRACT_SUBREG), 0,
                      1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1, 
                  // Src: (vector_extract:i32 v2i32:v2i32:$src, 1:iPTR) - Complexity = 8
                  // Dst: (EXTRACT_SUBREG:i32 ?:v2i32:$src, sub1:i32)
/*20027*/       0, /*End of Scope*/
/*20028*/     /*Scope*/ 19, /*->20048*/
/*20029*/       OPC_CheckInteger, 2, 
/*20031*/       OPC_MoveParent,
/*20032*/       OPC_CheckType, MVT::i32,
/*20034*/       OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*20036*/       OPC_EmitInteger, MVT::i32, AMDGPU::sub2,
/*20039*/       OPC_MorphNodeTo, TARGET_VAL(TargetOpcode::EXTRACT_SUBREG), 0,
                    1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1, 
                // Src: (vector_extract:i32 v2i32:v2i32:$src, 2:iPTR) - Complexity = 8
                // Dst: (EXTRACT_SUBREG:i32 ?:v2i32:$src, sub2:i32)
/*20048*/     0, /*End of Scope*/
/*20049*/   /*Scope*/ 38|128,1/*166*/, /*->20217*/
/*20051*/     OPC_CheckChild0Type, MVT::v8i32,
/*20053*/     OPC_MoveChild, 1,
/*20055*/     OPC_Scope, 19, /*->20076*/ // 8 children in Scope
/*20057*/       OPC_CheckInteger, 0, 
/*20059*/       OPC_MoveParent,
/*20060*/       OPC_CheckType, MVT::i32,
/*20062*/       OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*20064*/       OPC_EmitInteger, MVT::i32, AMDGPU::sub0,
/*20067*/       OPC_MorphNodeTo, TARGET_VAL(TargetOpcode::EXTRACT_SUBREG), 0,
                    1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1, 
                // Src: (vector_extract:i32 v8i32:v8i32:$src, 0:iPTR) - Complexity = 8
                // Dst: (EXTRACT_SUBREG:i32 ?:v8i32:$src, sub0:i32)
/*20076*/     /*Scope*/ 19, /*->20096*/
/*20077*/       OPC_CheckInteger, 1, 
/*20079*/       OPC_MoveParent,
/*20080*/       OPC_CheckType, MVT::i32,
/*20082*/       OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*20084*/       OPC_EmitInteger, MVT::i32, AMDGPU::sub1,
/*20087*/       OPC_MorphNodeTo, TARGET_VAL(TargetOpcode::EXTRACT_SUBREG), 0,
                    1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1, 
                // Src: (vector_extract:i32 v8i32:v8i32:$src, 1:iPTR) - Complexity = 8
                // Dst: (EXTRACT_SUBREG:i32 ?:v8i32:$src, sub1:i32)
/*20096*/     /*Scope*/ 19, /*->20116*/
/*20097*/       OPC_CheckInteger, 2, 
/*20099*/       OPC_MoveParent,
/*20100*/       OPC_CheckType, MVT::i32,
/*20102*/       OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*20104*/       OPC_EmitInteger, MVT::i32, AMDGPU::sub2,
/*20107*/       OPC_MorphNodeTo, TARGET_VAL(TargetOpcode::EXTRACT_SUBREG), 0,
                    1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1, 
                // Src: (vector_extract:i32 v8i32:v8i32:$src, 2:iPTR) - Complexity = 8
                // Dst: (EXTRACT_SUBREG:i32 ?:v8i32:$src, sub2:i32)
/*20116*/     /*Scope*/ 19, /*->20136*/
/*20117*/       OPC_CheckInteger, 3, 
/*20119*/       OPC_MoveParent,
/*20120*/       OPC_CheckType, MVT::i32,
/*20122*/       OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*20124*/       OPC_EmitInteger, MVT::i32, AMDGPU::sub3,
/*20127*/       OPC_MorphNodeTo, TARGET_VAL(TargetOpcode::EXTRACT_SUBREG), 0,
                    1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1, 
                // Src: (vector_extract:i32 v8i32:v8i32:$src, 3:iPTR) - Complexity = 8
                // Dst: (EXTRACT_SUBREG:i32 ?:v8i32:$src, sub3:i32)
/*20136*/     /*Scope*/ 19, /*->20156*/
/*20137*/       OPC_CheckInteger, 4, 
/*20139*/       OPC_MoveParent,
/*20140*/       OPC_CheckType, MVT::i32,
/*20142*/       OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*20144*/       OPC_EmitInteger, MVT::i32, AMDGPU::sub4,
/*20147*/       OPC_MorphNodeTo, TARGET_VAL(TargetOpcode::EXTRACT_SUBREG), 0,
                    1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1, 
                // Src: (vector_extract:i32 v8i32:v8i32:$src, 4:iPTR) - Complexity = 8
                // Dst: (EXTRACT_SUBREG:i32 ?:v8i32:$src, sub4:i32)
/*20156*/     /*Scope*/ 19, /*->20176*/
/*20157*/       OPC_CheckInteger, 5, 
/*20159*/       OPC_MoveParent,
/*20160*/       OPC_CheckType, MVT::i32,
/*20162*/       OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*20164*/       OPC_EmitInteger, MVT::i32, AMDGPU::sub5,
/*20167*/       OPC_MorphNodeTo, TARGET_VAL(TargetOpcode::EXTRACT_SUBREG), 0,
                    1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1, 
                // Src: (vector_extract:i32 v8i32:v8i32:$src, 5:iPTR) - Complexity = 8
                // Dst: (EXTRACT_SUBREG:i32 ?:v8i32:$src, sub5:i32)
/*20176*/     /*Scope*/ 19, /*->20196*/
/*20177*/       OPC_CheckInteger, 6, 
/*20179*/       OPC_MoveParent,
/*20180*/       OPC_CheckType, MVT::i32,
/*20182*/       OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*20184*/       OPC_EmitInteger, MVT::i32, AMDGPU::sub6,
/*20187*/       OPC_MorphNodeTo, TARGET_VAL(TargetOpcode::EXTRACT_SUBREG), 0,
                    1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1, 
                // Src: (vector_extract:i32 v8i32:v8i32:$src, 6:iPTR) - Complexity = 8
                // Dst: (EXTRACT_SUBREG:i32 ?:v8i32:$src, sub6:i32)
/*20196*/     /*Scope*/ 19, /*->20216*/
/*20197*/       OPC_CheckInteger, 7, 
/*20199*/       OPC_MoveParent,
/*20200*/       OPC_CheckType, MVT::i32,
/*20202*/       OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*20204*/       OPC_EmitInteger, MVT::i32, AMDGPU::sub7,
/*20207*/       OPC_MorphNodeTo, TARGET_VAL(TargetOpcode::EXTRACT_SUBREG), 0,
                    1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1, 
                // Src: (vector_extract:i32 v8i32:v8i32:$src, 7:iPTR) - Complexity = 8
                // Dst: (EXTRACT_SUBREG:i32 ?:v8i32:$src, sub7:i32)
/*20216*/     0, /*End of Scope*/
/*20217*/   /*Scope*/ 70|128,2/*326*/, /*->20545*/
/*20219*/     OPC_CheckChild0Type, MVT::v16i32,
/*20221*/     OPC_MoveChild, 1,
/*20223*/     OPC_Scope, 19, /*->20244*/ // 16 children in Scope
/*20225*/       OPC_CheckInteger, 0, 
/*20227*/       OPC_MoveParent,
/*20228*/       OPC_CheckType, MVT::i32,
/*20230*/       OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*20232*/       OPC_EmitInteger, MVT::i32, AMDGPU::sub0,
/*20235*/       OPC_MorphNodeTo, TARGET_VAL(TargetOpcode::EXTRACT_SUBREG), 0,
                    1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1, 
                // Src: (vector_extract:i32 v16i32:v16i32:$src, 0:iPTR) - Complexity = 8
                // Dst: (EXTRACT_SUBREG:i32 ?:v16i32:$src, sub0:i32)
/*20244*/     /*Scope*/ 19, /*->20264*/
/*20245*/       OPC_CheckInteger, 1, 
/*20247*/       OPC_MoveParent,
/*20248*/       OPC_CheckType, MVT::i32,
/*20250*/       OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*20252*/       OPC_EmitInteger, MVT::i32, AMDGPU::sub1,
/*20255*/       OPC_MorphNodeTo, TARGET_VAL(TargetOpcode::EXTRACT_SUBREG), 0,
                    1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1, 
                // Src: (vector_extract:i32 v16i32:v16i32:$src, 1:iPTR) - Complexity = 8
                // Dst: (EXTRACT_SUBREG:i32 ?:v16i32:$src, sub1:i32)
/*20264*/     /*Scope*/ 19, /*->20284*/
/*20265*/       OPC_CheckInteger, 2, 
/*20267*/       OPC_MoveParent,
/*20268*/       OPC_CheckType, MVT::i32,
/*20270*/       OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*20272*/       OPC_EmitInteger, MVT::i32, AMDGPU::sub2,
/*20275*/       OPC_MorphNodeTo, TARGET_VAL(TargetOpcode::EXTRACT_SUBREG), 0,
                    1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1, 
                // Src: (vector_extract:i32 v16i32:v16i32:$src, 2:iPTR) - Complexity = 8
                // Dst: (EXTRACT_SUBREG:i32 ?:v16i32:$src, sub2:i32)
/*20284*/     /*Scope*/ 19, /*->20304*/
/*20285*/       OPC_CheckInteger, 3, 
/*20287*/       OPC_MoveParent,
/*20288*/       OPC_CheckType, MVT::i32,
/*20290*/       OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*20292*/       OPC_EmitInteger, MVT::i32, AMDGPU::sub3,
/*20295*/       OPC_MorphNodeTo, TARGET_VAL(TargetOpcode::EXTRACT_SUBREG), 0,
                    1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1, 
                // Src: (vector_extract:i32 v16i32:v16i32:$src, 3:iPTR) - Complexity = 8
                // Dst: (EXTRACT_SUBREG:i32 ?:v16i32:$src, sub3:i32)
/*20304*/     /*Scope*/ 19, /*->20324*/
/*20305*/       OPC_CheckInteger, 4, 
/*20307*/       OPC_MoveParent,
/*20308*/       OPC_CheckType, MVT::i32,
/*20310*/       OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*20312*/       OPC_EmitInteger, MVT::i32, AMDGPU::sub4,
/*20315*/       OPC_MorphNodeTo, TARGET_VAL(TargetOpcode::EXTRACT_SUBREG), 0,
                    1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1, 
                // Src: (vector_extract:i32 v16i32:v16i32:$src, 4:iPTR) - Complexity = 8
                // Dst: (EXTRACT_SUBREG:i32 ?:v16i32:$src, sub4:i32)
/*20324*/     /*Scope*/ 19, /*->20344*/
/*20325*/       OPC_CheckInteger, 5, 
/*20327*/       OPC_MoveParent,
/*20328*/       OPC_CheckType, MVT::i32,
/*20330*/       OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*20332*/       OPC_EmitInteger, MVT::i32, AMDGPU::sub5,
/*20335*/       OPC_MorphNodeTo, TARGET_VAL(TargetOpcode::EXTRACT_SUBREG), 0,
                    1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1, 
                // Src: (vector_extract:i32 v16i32:v16i32:$src, 5:iPTR) - Complexity = 8
                // Dst: (EXTRACT_SUBREG:i32 ?:v16i32:$src, sub5:i32)
/*20344*/     /*Scope*/ 19, /*->20364*/
/*20345*/       OPC_CheckInteger, 6, 
/*20347*/       OPC_MoveParent,
/*20348*/       OPC_CheckType, MVT::i32,
/*20350*/       OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*20352*/       OPC_EmitInteger, MVT::i32, AMDGPU::sub6,
/*20355*/       OPC_MorphNodeTo, TARGET_VAL(TargetOpcode::EXTRACT_SUBREG), 0,
                    1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1, 
                // Src: (vector_extract:i32 v16i32:v16i32:$src, 6:iPTR) - Complexity = 8
                // Dst: (EXTRACT_SUBREG:i32 ?:v16i32:$src, sub6:i32)
/*20364*/     /*Scope*/ 19, /*->20384*/
/*20365*/       OPC_CheckInteger, 7, 
/*20367*/       OPC_MoveParent,
/*20368*/       OPC_CheckType, MVT::i32,
/*20370*/       OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*20372*/       OPC_EmitInteger, MVT::i32, AMDGPU::sub7,
/*20375*/       OPC_MorphNodeTo, TARGET_VAL(TargetOpcode::EXTRACT_SUBREG), 0,
                    1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1, 
                // Src: (vector_extract:i32 v16i32:v16i32:$src, 7:iPTR) - Complexity = 8
                // Dst: (EXTRACT_SUBREG:i32 ?:v16i32:$src, sub7:i32)
/*20384*/     /*Scope*/ 19, /*->20404*/
/*20385*/       OPC_CheckInteger, 8, 
/*20387*/       OPC_MoveParent,
/*20388*/       OPC_CheckType, MVT::i32,
/*20390*/       OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*20392*/       OPC_EmitInteger, MVT::i32, AMDGPU::sub8,
/*20395*/       OPC_MorphNodeTo, TARGET_VAL(TargetOpcode::EXTRACT_SUBREG), 0,
                    1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1, 
                // Src: (vector_extract:i32 v16i32:v16i32:$src, 8:iPTR) - Complexity = 8
                // Dst: (EXTRACT_SUBREG:i32 ?:v16i32:$src, sub8:i32)
/*20404*/     /*Scope*/ 19, /*->20424*/
/*20405*/       OPC_CheckInteger, 9, 
/*20407*/       OPC_MoveParent,
/*20408*/       OPC_CheckType, MVT::i32,
/*20410*/       OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*20412*/       OPC_EmitInteger, MVT::i32, AMDGPU::sub9,
/*20415*/       OPC_MorphNodeTo, TARGET_VAL(TargetOpcode::EXTRACT_SUBREG), 0,
                    1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1, 
                // Src: (vector_extract:i32 v16i32:v16i32:$src, 9:iPTR) - Complexity = 8
                // Dst: (EXTRACT_SUBREG:i32 ?:v16i32:$src, sub9:i32)
/*20424*/     /*Scope*/ 19, /*->20444*/
/*20425*/       OPC_CheckInteger, 10, 
/*20427*/       OPC_MoveParent,
/*20428*/       OPC_CheckType, MVT::i32,
/*20430*/       OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*20432*/       OPC_EmitInteger, MVT::i32, AMDGPU::sub10,
/*20435*/       OPC_MorphNodeTo, TARGET_VAL(TargetOpcode::EXTRACT_SUBREG), 0,
                    1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1, 
                // Src: (vector_extract:i32 v16i32:v16i32:$src, 10:iPTR) - Complexity = 8
                // Dst: (EXTRACT_SUBREG:i32 ?:v16i32:$src, sub10:i32)
/*20444*/     /*Scope*/ 19, /*->20464*/
/*20445*/       OPC_CheckInteger, 11, 
/*20447*/       OPC_MoveParent,
/*20448*/       OPC_CheckType, MVT::i32,
/*20450*/       OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*20452*/       OPC_EmitInteger, MVT::i32, AMDGPU::sub11,
/*20455*/       OPC_MorphNodeTo, TARGET_VAL(TargetOpcode::EXTRACT_SUBREG), 0,
                    1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1, 
                // Src: (vector_extract:i32 v16i32:v16i32:$src, 11:iPTR) - Complexity = 8
                // Dst: (EXTRACT_SUBREG:i32 ?:v16i32:$src, sub11:i32)
/*20464*/     /*Scope*/ 19, /*->20484*/
/*20465*/       OPC_CheckInteger, 12, 
/*20467*/       OPC_MoveParent,
/*20468*/       OPC_CheckType, MVT::i32,
/*20470*/       OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*20472*/       OPC_EmitInteger, MVT::i32, AMDGPU::sub12,
/*20475*/       OPC_MorphNodeTo, TARGET_VAL(TargetOpcode::EXTRACT_SUBREG), 0,
                    1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1, 
                // Src: (vector_extract:i32 v16i32:v16i32:$src, 12:iPTR) - Complexity = 8
                // Dst: (EXTRACT_SUBREG:i32 ?:v16i32:$src, sub12:i32)
/*20484*/     /*Scope*/ 19, /*->20504*/
/*20485*/       OPC_CheckInteger, 13, 
/*20487*/       OPC_MoveParent,
/*20488*/       OPC_CheckType, MVT::i32,
/*20490*/       OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*20492*/       OPC_EmitInteger, MVT::i32, AMDGPU::sub13,
/*20495*/       OPC_MorphNodeTo, TARGET_VAL(TargetOpcode::EXTRACT_SUBREG), 0,
                    1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1, 
                // Src: (vector_extract:i32 v16i32:v16i32:$src, 13:iPTR) - Complexity = 8
                // Dst: (EXTRACT_SUBREG:i32 ?:v16i32:$src, sub13:i32)
/*20504*/     /*Scope*/ 19, /*->20524*/
/*20505*/       OPC_CheckInteger, 14, 
/*20507*/       OPC_MoveParent,
/*20508*/       OPC_CheckType, MVT::i32,
/*20510*/       OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*20512*/       OPC_EmitInteger, MVT::i32, AMDGPU::sub14,
/*20515*/       OPC_MorphNodeTo, TARGET_VAL(TargetOpcode::EXTRACT_SUBREG), 0,
                    1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1, 
                // Src: (vector_extract:i32 v16i32:v16i32:$src, 14:iPTR) - Complexity = 8
                // Dst: (EXTRACT_SUBREG:i32 ?:v16i32:$src, sub14:i32)
/*20524*/     /*Scope*/ 19, /*->20544*/
/*20525*/       OPC_CheckInteger, 15, 
/*20527*/       OPC_MoveParent,
/*20528*/       OPC_CheckType, MVT::i32,
/*20530*/       OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*20532*/       OPC_EmitInteger, MVT::i32, AMDGPU::sub15,
/*20535*/       OPC_MorphNodeTo, TARGET_VAL(TargetOpcode::EXTRACT_SUBREG), 0,
                    1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1, 
                // Src: (vector_extract:i32 v16i32:v16i32:$src, 15:iPTR) - Complexity = 8
                // Dst: (EXTRACT_SUBREG:i32 ?:v16i32:$src, sub15:i32)
/*20544*/     0, /*End of Scope*/
/*20545*/   /*Scope*/ 46|128,1/*174*/, /*->20721*/
/*20547*/     OPC_CheckChild0Type, MVT::v2f32,
/*20549*/     OPC_Scope, 11|128,1/*139*/, /*->20691*/ // 2 children in Scope
/*20552*/       OPC_MoveChild, 1,
/*20554*/       OPC_Scope, 38, /*->20594*/ // 4 children in Scope
/*20556*/         OPC_CheckOpcode, TARGET_VAL(ISD::ADD),
/*20559*/         OPC_RecordChild0, // #1 = $idx
/*20560*/         OPC_RecordChild1, // #2 = $off
/*20561*/         OPC_MoveChild, 1,
/*20563*/         OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*20566*/         OPC_MoveParent,
/*20567*/         OPC_CheckType, MVT::i32,
/*20569*/         OPC_MoveParent,
/*20570*/         OPC_CheckType, MVT::f32,
/*20572*/         OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*20574*/         OPC_EmitNode, TARGET_VAL(TargetOpcode::IMPLICIT_DEF), 0,
                      1/*#VTs*/, MVT::i1, 0/*#Ops*/,  // Results = #3
/*20581*/         OPC_EmitConvertToTarget, 2,
/*20583*/         OPC_MorphNodeTo, TARGET_VAL(AMDGPU::SI_INDIRECT_SRC), 0,
                      1/*#VTs*/, MVT::f32, 4/*#Ops*/, 3, 0, 1, 4, 
                  // Src: (vector_extract:f32 v2f32:v2f32:$vec, (add:i32 i32:i32:$idx, (imm:i32):$off)) - Complexity = 9
                  // Dst: (SI_INDIRECT_SRC:f32 (IMPLICIT_DEF:i1), ?:v2f32:$vec, ?:i32:$idx, (imm:i32):$off)
/*20594*/       /*Scope*/ 37, /*->20632*/
/*20595*/         OPC_CheckInteger, 0, 
/*20597*/         OPC_MoveParent,
/*20598*/         OPC_CheckType, MVT::f32,
/*20600*/         OPC_Scope, 14, /*->20616*/ // 2 children in Scope
/*20602*/           OPC_CheckPatternPredicate, 3, // (Subtarget.getGeneration() <= AMDGPUSubtarget::NORTHERN_ISLANDS)
/*20604*/           OPC_EmitInteger, MVT::i32, AMDGPU::sub0,
/*20607*/           OPC_MorphNodeTo, TARGET_VAL(TargetOpcode::EXTRACT_SUBREG), 0,
                        1/*#VTs*/, MVT::f32, 2/*#Ops*/, 0, 1, 
                    // Src: (vector_extract:f32 v2f32:v2f32:$src, 0:iPTR) - Complexity = 8
                    // Dst: (EXTRACT_SUBREG:f32 ?:v2f32:$src, sub0:i32)
/*20616*/         /*Scope*/ 14, /*->20631*/
/*20617*/           OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*20619*/           OPC_EmitInteger, MVT::i32, AMDGPU::sub0,
/*20622*/           OPC_MorphNodeTo, TARGET_VAL(TargetOpcode::EXTRACT_SUBREG), 0,
                        1/*#VTs*/, MVT::f32, 2/*#Ops*/, 0, 1, 
                    // Src: (vector_extract:f32 v2f32:v2f32:$src, 0:iPTR) - Complexity = 8
                    // Dst: (EXTRACT_SUBREG:f32 ?:v2f32:$src, sub0:i32)
/*20631*/         0, /*End of Scope*/
/*20632*/       /*Scope*/ 37, /*->20670*/
/*20633*/         OPC_CheckInteger, 1, 
/*20635*/         OPC_MoveParent,
/*20636*/         OPC_CheckType, MVT::f32,
/*20638*/         OPC_Scope, 14, /*->20654*/ // 2 children in Scope
/*20640*/           OPC_CheckPatternPredicate, 3, // (Subtarget.getGeneration() <= AMDGPUSubtarget::NORTHERN_ISLANDS)
/*20642*/           OPC_EmitInteger, MVT::i32, AMDGPU::sub1,
/*20645*/           OPC_MorphNodeTo, TARGET_VAL(TargetOpcode::EXTRACT_SUBREG), 0,
                        1/*#VTs*/, MVT::f32, 2/*#Ops*/, 0, 1, 
                    // Src: (vector_extract:f32 v2f32:v2f32:$src, 1:iPTR) - Complexity = 8
                    // Dst: (EXTRACT_SUBREG:f32 ?:v2f32:$src, sub1:i32)
/*20654*/         /*Scope*/ 14, /*->20669*/
/*20655*/           OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*20657*/           OPC_EmitInteger, MVT::i32, AMDGPU::sub1,
/*20660*/           OPC_MorphNodeTo, TARGET_VAL(TargetOpcode::EXTRACT_SUBREG), 0,
                        1/*#VTs*/, MVT::f32, 2/*#Ops*/, 0, 1, 
                    // Src: (vector_extract:f32 v2f32:v2f32:$src, 1:iPTR) - Complexity = 8
                    // Dst: (EXTRACT_SUBREG:f32 ?:v2f32:$src, sub1:i32)
/*20669*/         0, /*End of Scope*/
/*20670*/       /*Scope*/ 19, /*->20690*/
/*20671*/         OPC_CheckInteger, 2, 
/*20673*/         OPC_MoveParent,
/*20674*/         OPC_CheckType, MVT::f32,
/*20676*/         OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*20678*/         OPC_EmitInteger, MVT::i32, AMDGPU::sub2,
/*20681*/         OPC_MorphNodeTo, TARGET_VAL(TargetOpcode::EXTRACT_SUBREG), 0,
                      1/*#VTs*/, MVT::f32, 2/*#Ops*/, 0, 1, 
                  // Src: (vector_extract:f32 v2f32:v2f32:$src, 2:iPTR) - Complexity = 8
                  // Dst: (EXTRACT_SUBREG:f32 ?:v2f32:$src, sub2:i32)
/*20690*/       0, /*End of Scope*/
/*20691*/     /*Scope*/ 28, /*->20720*/
/*20692*/       OPC_RecordChild1, // #1 = $idx
/*20693*/       OPC_CheckChild1Type, MVT::i32,
/*20695*/       OPC_CheckType, MVT::f32,
/*20697*/       OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*20699*/       OPC_EmitNode, TARGET_VAL(TargetOpcode::IMPLICIT_DEF), 0,
                    1/*#VTs*/, MVT::i1, 0/*#Ops*/,  // Results = #2
/*20706*/       OPC_EmitInteger, MVT::i32, 0, 
/*20709*/       OPC_MorphNodeTo, TARGET_VAL(AMDGPU::SI_INDIRECT_SRC), 0,
                    1/*#VTs*/, MVT::f32, 4/*#Ops*/, 2, 0, 1, 3, 
                // Src: (vector_extract:f32 v2f32:v2f32:$vec, i32:i32:$idx) - Complexity = 3
                // Dst: (SI_INDIRECT_SRC:f32 (IMPLICIT_DEF:i1), ?:v2f32:$vec, ?:i32:$idx, 0:i32)
/*20720*/     0, /*End of Scope*/
/*20721*/   /*Scope*/ 102|128,1/*230*/, /*->20953*/
/*20723*/     OPC_CheckChild0Type, MVT::v4f32,
/*20725*/     OPC_Scope, 67|128,1/*195*/, /*->20923*/ // 2 children in Scope
/*20728*/       OPC_MoveChild, 1,
/*20730*/       OPC_Scope, 38, /*->20770*/ // 5 children in Scope
/*20732*/         OPC_CheckOpcode, TARGET_VAL(ISD::ADD),
/*20735*/         OPC_RecordChild0, // #1 = $idx
/*20736*/         OPC_RecordChild1, // #2 = $off
/*20737*/         OPC_MoveChild, 1,
/*20739*/         OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*20742*/         OPC_MoveParent,
/*20743*/         OPC_CheckType, MVT::i32,
/*20745*/         OPC_MoveParent,
/*20746*/         OPC_CheckType, MVT::f32,
/*20748*/         OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*20750*/         OPC_EmitNode, TARGET_VAL(TargetOpcode::IMPLICIT_DEF), 0,
                      1/*#VTs*/, MVT::i1, 0/*#Ops*/,  // Results = #3
/*20757*/         OPC_EmitConvertToTarget, 2,
/*20759*/         OPC_MorphNodeTo, TARGET_VAL(AMDGPU::SI_INDIRECT_SRC), 0,
                      1/*#VTs*/, MVT::f32, 4/*#Ops*/, 3, 0, 1, 4, 
                  // Src: (vector_extract:f32 v4f32:v4f32:$vec, (add:i32 i32:i32:$idx, (imm:i32):$off)) - Complexity = 9
                  // Dst: (SI_INDIRECT_SRC:f32 (IMPLICIT_DEF:i1), ?:v4f32:$vec, ?:i32:$idx, (imm:i32):$off)
/*20770*/       /*Scope*/ 37, /*->20808*/
/*20771*/         OPC_CheckInteger, 0, 
/*20773*/         OPC_MoveParent,
/*20774*/         OPC_CheckType, MVT::f32,
/*20776*/         OPC_Scope, 14, /*->20792*/ // 2 children in Scope
/*20778*/           OPC_CheckPatternPredicate, 3, // (Subtarget.getGeneration() <= AMDGPUSubtarget::NORTHERN_ISLANDS)
/*20780*/           OPC_EmitInteger, MVT::i32, AMDGPU::sub0,
/*20783*/           OPC_MorphNodeTo, TARGET_VAL(TargetOpcode::EXTRACT_SUBREG), 0,
                        1/*#VTs*/, MVT::f32, 2/*#Ops*/, 0, 1, 
                    // Src: (vector_extract:f32 v4f32:v4f32:$src, 0:iPTR) - Complexity = 8
                    // Dst: (EXTRACT_SUBREG:f32 ?:v4f32:$src, sub0:i32)
/*20792*/         /*Scope*/ 14, /*->20807*/
/*20793*/           OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*20795*/           OPC_EmitInteger, MVT::i32, AMDGPU::sub0,
/*20798*/           OPC_MorphNodeTo, TARGET_VAL(TargetOpcode::EXTRACT_SUBREG), 0,
                        1/*#VTs*/, MVT::f32, 2/*#Ops*/, 0, 1, 
                    // Src: (vector_extract:f32 v4f32:v4f32:$src, 0:iPTR) - Complexity = 8
                    // Dst: (EXTRACT_SUBREG:f32 ?:v4f32:$src, sub0:i32)
/*20807*/         0, /*End of Scope*/
/*20808*/       /*Scope*/ 37, /*->20846*/
/*20809*/         OPC_CheckInteger, 1, 
/*20811*/         OPC_MoveParent,
/*20812*/         OPC_CheckType, MVT::f32,
/*20814*/         OPC_Scope, 14, /*->20830*/ // 2 children in Scope
/*20816*/           OPC_CheckPatternPredicate, 3, // (Subtarget.getGeneration() <= AMDGPUSubtarget::NORTHERN_ISLANDS)
/*20818*/           OPC_EmitInteger, MVT::i32, AMDGPU::sub1,
/*20821*/           OPC_MorphNodeTo, TARGET_VAL(TargetOpcode::EXTRACT_SUBREG), 0,
                        1/*#VTs*/, MVT::f32, 2/*#Ops*/, 0, 1, 
                    // Src: (vector_extract:f32 v4f32:v4f32:$src, 1:iPTR) - Complexity = 8
                    // Dst: (EXTRACT_SUBREG:f32 ?:v4f32:$src, sub1:i32)
/*20830*/         /*Scope*/ 14, /*->20845*/
/*20831*/           OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*20833*/           OPC_EmitInteger, MVT::i32, AMDGPU::sub1,
/*20836*/           OPC_MorphNodeTo, TARGET_VAL(TargetOpcode::EXTRACT_SUBREG), 0,
                        1/*#VTs*/, MVT::f32, 2/*#Ops*/, 0, 1, 
                    // Src: (vector_extract:f32 v4f32:v4f32:$src, 1:iPTR) - Complexity = 8
                    // Dst: (EXTRACT_SUBREG:f32 ?:v4f32:$src, sub1:i32)
/*20845*/         0, /*End of Scope*/
/*20846*/       /*Scope*/ 37, /*->20884*/
/*20847*/         OPC_CheckInteger, 2, 
/*20849*/         OPC_MoveParent,
/*20850*/         OPC_CheckType, MVT::f32,
/*20852*/         OPC_Scope, 14, /*->20868*/ // 2 children in Scope
/*20854*/           OPC_CheckPatternPredicate, 3, // (Subtarget.getGeneration() <= AMDGPUSubtarget::NORTHERN_ISLANDS)
/*20856*/           OPC_EmitInteger, MVT::i32, AMDGPU::sub2,
/*20859*/           OPC_MorphNodeTo, TARGET_VAL(TargetOpcode::EXTRACT_SUBREG), 0,
                        1/*#VTs*/, MVT::f32, 2/*#Ops*/, 0, 1, 
                    // Src: (vector_extract:f32 v4f32:v4f32:$src, 2:iPTR) - Complexity = 8
                    // Dst: (EXTRACT_SUBREG:f32 ?:v4f32:$src, sub2:i32)
/*20868*/         /*Scope*/ 14, /*->20883*/
/*20869*/           OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*20871*/           OPC_EmitInteger, MVT::i32, AMDGPU::sub2,
/*20874*/           OPC_MorphNodeTo, TARGET_VAL(TargetOpcode::EXTRACT_SUBREG), 0,
                        1/*#VTs*/, MVT::f32, 2/*#Ops*/, 0, 1, 
                    // Src: (vector_extract:f32 v4f32:v4f32:$src, 2:iPTR) - Complexity = 8
                    // Dst: (EXTRACT_SUBREG:f32 ?:v4f32:$src, sub2:i32)
/*20883*/         0, /*End of Scope*/
/*20884*/       /*Scope*/ 37, /*->20922*/
/*20885*/         OPC_CheckInteger, 3, 
/*20887*/         OPC_MoveParent,
/*20888*/         OPC_CheckType, MVT::f32,
/*20890*/         OPC_Scope, 14, /*->20906*/ // 2 children in Scope
/*20892*/           OPC_CheckPatternPredicate, 3, // (Subtarget.getGeneration() <= AMDGPUSubtarget::NORTHERN_ISLANDS)
/*20894*/           OPC_EmitInteger, MVT::i32, AMDGPU::sub3,
/*20897*/           OPC_MorphNodeTo, TARGET_VAL(TargetOpcode::EXTRACT_SUBREG), 0,
                        1/*#VTs*/, MVT::f32, 2/*#Ops*/, 0, 1, 
                    // Src: (vector_extract:f32 v4f32:v4f32:$src, 3:iPTR) - Complexity = 8
                    // Dst: (EXTRACT_SUBREG:f32 ?:v4f32:$src, sub3:i32)
/*20906*/         /*Scope*/ 14, /*->20921*/
/*20907*/           OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*20909*/           OPC_EmitInteger, MVT::i32, AMDGPU::sub3,
/*20912*/           OPC_MorphNodeTo, TARGET_VAL(TargetOpcode::EXTRACT_SUBREG), 0,
                        1/*#VTs*/, MVT::f32, 2/*#Ops*/, 0, 1, 
                    // Src: (vector_extract:f32 v4f32:v4f32:$src, 3:iPTR) - Complexity = 8
                    // Dst: (EXTRACT_SUBREG:f32 ?:v4f32:$src, sub3:i32)
/*20921*/         0, /*End of Scope*/
/*20922*/       0, /*End of Scope*/
/*20923*/     /*Scope*/ 28, /*->20952*/
/*20924*/       OPC_RecordChild1, // #1 = $idx
/*20925*/       OPC_CheckChild1Type, MVT::i32,
/*20927*/       OPC_CheckType, MVT::f32,
/*20929*/       OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*20931*/       OPC_EmitNode, TARGET_VAL(TargetOpcode::IMPLICIT_DEF), 0,
                    1/*#VTs*/, MVT::i1, 0/*#Ops*/,  // Results = #2
/*20938*/       OPC_EmitInteger, MVT::i32, 0, 
/*20941*/       OPC_MorphNodeTo, TARGET_VAL(AMDGPU::SI_INDIRECT_SRC), 0,
                    1/*#VTs*/, MVT::f32, 4/*#Ops*/, 2, 0, 1, 3, 
                // Src: (vector_extract:f32 v4f32:v4f32:$vec, i32:i32:$idx) - Complexity = 3
                // Dst: (SI_INDIRECT_SRC:f32 (IMPLICIT_DEF:i1), ?:v4f32:$vec, ?:i32:$idx, 0:i32)
/*20952*/     0, /*End of Scope*/
/*20953*/   /*Scope*/ 110|128,1/*238*/, /*->21193*/
/*20955*/     OPC_CheckChild0Type, MVT::v8f32,
/*20957*/     OPC_Scope, 75|128,1/*203*/, /*->21163*/ // 2 children in Scope
/*20960*/       OPC_MoveChild, 1,
/*20962*/       OPC_Scope, 38, /*->21002*/ // 9 children in Scope
/*20964*/         OPC_CheckOpcode, TARGET_VAL(ISD::ADD),
/*20967*/         OPC_RecordChild0, // #1 = $idx
/*20968*/         OPC_RecordChild1, // #2 = $off
/*20969*/         OPC_MoveChild, 1,
/*20971*/         OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*20974*/         OPC_MoveParent,
/*20975*/         OPC_CheckType, MVT::i32,
/*20977*/         OPC_MoveParent,
/*20978*/         OPC_CheckType, MVT::f32,
/*20980*/         OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*20982*/         OPC_EmitNode, TARGET_VAL(TargetOpcode::IMPLICIT_DEF), 0,
                      1/*#VTs*/, MVT::i1, 0/*#Ops*/,  // Results = #3
/*20989*/         OPC_EmitConvertToTarget, 2,
/*20991*/         OPC_MorphNodeTo, TARGET_VAL(AMDGPU::SI_INDIRECT_SRC), 0,
                      1/*#VTs*/, MVT::f32, 4/*#Ops*/, 3, 0, 1, 4, 
                  // Src: (vector_extract:f32 v8f32:v8f32:$vec, (add:i32 i32:i32:$idx, (imm:i32):$off)) - Complexity = 9
                  // Dst: (SI_INDIRECT_SRC:f32 (IMPLICIT_DEF:i1), ?:v8f32:$vec, ?:i32:$idx, (imm:i32):$off)
/*21002*/       /*Scope*/ 19, /*->21022*/
/*21003*/         OPC_CheckInteger, 0, 
/*21005*/         OPC_MoveParent,
/*21006*/         OPC_CheckType, MVT::f32,
/*21008*/         OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*21010*/         OPC_EmitInteger, MVT::i32, AMDGPU::sub0,
/*21013*/         OPC_MorphNodeTo, TARGET_VAL(TargetOpcode::EXTRACT_SUBREG), 0,
                      1/*#VTs*/, MVT::f32, 2/*#Ops*/, 0, 1, 
                  // Src: (vector_extract:f32 v8f32:v8f32:$src, 0:iPTR) - Complexity = 8
                  // Dst: (EXTRACT_SUBREG:f32 ?:v8f32:$src, sub0:i32)
/*21022*/       /*Scope*/ 19, /*->21042*/
/*21023*/         OPC_CheckInteger, 1, 
/*21025*/         OPC_MoveParent,
/*21026*/         OPC_CheckType, MVT::f32,
/*21028*/         OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*21030*/         OPC_EmitInteger, MVT::i32, AMDGPU::sub1,
/*21033*/         OPC_MorphNodeTo, TARGET_VAL(TargetOpcode::EXTRACT_SUBREG), 0,
                      1/*#VTs*/, MVT::f32, 2/*#Ops*/, 0, 1, 
                  // Src: (vector_extract:f32 v8f32:v8f32:$src, 1:iPTR) - Complexity = 8
                  // Dst: (EXTRACT_SUBREG:f32 ?:v8f32:$src, sub1:i32)
/*21042*/       /*Scope*/ 19, /*->21062*/
/*21043*/         OPC_CheckInteger, 2, 
/*21045*/         OPC_MoveParent,
/*21046*/         OPC_CheckType, MVT::f32,
/*21048*/         OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*21050*/         OPC_EmitInteger, MVT::i32, AMDGPU::sub2,
/*21053*/         OPC_MorphNodeTo, TARGET_VAL(TargetOpcode::EXTRACT_SUBREG), 0,
                      1/*#VTs*/, MVT::f32, 2/*#Ops*/, 0, 1, 
                  // Src: (vector_extract:f32 v8f32:v8f32:$src, 2:iPTR) - Complexity = 8
                  // Dst: (EXTRACT_SUBREG:f32 ?:v8f32:$src, sub2:i32)
/*21062*/       /*Scope*/ 19, /*->21082*/
/*21063*/         OPC_CheckInteger, 3, 
/*21065*/         OPC_MoveParent,
/*21066*/         OPC_CheckType, MVT::f32,
/*21068*/         OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*21070*/         OPC_EmitInteger, MVT::i32, AMDGPU::sub3,
/*21073*/         OPC_MorphNodeTo, TARGET_VAL(TargetOpcode::EXTRACT_SUBREG), 0,
                      1/*#VTs*/, MVT::f32, 2/*#Ops*/, 0, 1, 
                  // Src: (vector_extract:f32 v8f32:v8f32:$src, 3:iPTR) - Complexity = 8
                  // Dst: (EXTRACT_SUBREG:f32 ?:v8f32:$src, sub3:i32)
/*21082*/       /*Scope*/ 19, /*->21102*/
/*21083*/         OPC_CheckInteger, 4, 
/*21085*/         OPC_MoveParent,
/*21086*/         OPC_CheckType, MVT::f32,
/*21088*/         OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*21090*/         OPC_EmitInteger, MVT::i32, AMDGPU::sub4,
/*21093*/         OPC_MorphNodeTo, TARGET_VAL(TargetOpcode::EXTRACT_SUBREG), 0,
                      1/*#VTs*/, MVT::f32, 2/*#Ops*/, 0, 1, 
                  // Src: (vector_extract:f32 v8f32:v8f32:$src, 4:iPTR) - Complexity = 8
                  // Dst: (EXTRACT_SUBREG:f32 ?:v8f32:$src, sub4:i32)
/*21102*/       /*Scope*/ 19, /*->21122*/
/*21103*/         OPC_CheckInteger, 5, 
/*21105*/         OPC_MoveParent,
/*21106*/         OPC_CheckType, MVT::f32,
/*21108*/         OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*21110*/         OPC_EmitInteger, MVT::i32, AMDGPU::sub5,
/*21113*/         OPC_MorphNodeTo, TARGET_VAL(TargetOpcode::EXTRACT_SUBREG), 0,
                      1/*#VTs*/, MVT::f32, 2/*#Ops*/, 0, 1, 
                  // Src: (vector_extract:f32 v8f32:v8f32:$src, 5:iPTR) - Complexity = 8
                  // Dst: (EXTRACT_SUBREG:f32 ?:v8f32:$src, sub5:i32)
/*21122*/       /*Scope*/ 19, /*->21142*/
/*21123*/         OPC_CheckInteger, 6, 
/*21125*/         OPC_MoveParent,
/*21126*/         OPC_CheckType, MVT::f32,
/*21128*/         OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*21130*/         OPC_EmitInteger, MVT::i32, AMDGPU::sub6,
/*21133*/         OPC_MorphNodeTo, TARGET_VAL(TargetOpcode::EXTRACT_SUBREG), 0,
                      1/*#VTs*/, MVT::f32, 2/*#Ops*/, 0, 1, 
                  // Src: (vector_extract:f32 v8f32:v8f32:$src, 6:iPTR) - Complexity = 8
                  // Dst: (EXTRACT_SUBREG:f32 ?:v8f32:$src, sub6:i32)
/*21142*/       /*Scope*/ 19, /*->21162*/
/*21143*/         OPC_CheckInteger, 7, 
/*21145*/         OPC_MoveParent,
/*21146*/         OPC_CheckType, MVT::f32,
/*21148*/         OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*21150*/         OPC_EmitInteger, MVT::i32, AMDGPU::sub7,
/*21153*/         OPC_MorphNodeTo, TARGET_VAL(TargetOpcode::EXTRACT_SUBREG), 0,
                      1/*#VTs*/, MVT::f32, 2/*#Ops*/, 0, 1, 
                  // Src: (vector_extract:f32 v8f32:v8f32:$src, 7:iPTR) - Complexity = 8
                  // Dst: (EXTRACT_SUBREG:f32 ?:v8f32:$src, sub7:i32)
/*21162*/       0, /*End of Scope*/
/*21163*/     /*Scope*/ 28, /*->21192*/
/*21164*/       OPC_RecordChild1, // #1 = $idx
/*21165*/       OPC_CheckChild1Type, MVT::i32,
/*21167*/       OPC_CheckType, MVT::f32,
/*21169*/       OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*21171*/       OPC_EmitNode, TARGET_VAL(TargetOpcode::IMPLICIT_DEF), 0,
                    1/*#VTs*/, MVT::i1, 0/*#Ops*/,  // Results = #2
/*21178*/       OPC_EmitInteger, MVT::i32, 0, 
/*21181*/       OPC_MorphNodeTo, TARGET_VAL(AMDGPU::SI_INDIRECT_SRC), 0,
                    1/*#VTs*/, MVT::f32, 4/*#Ops*/, 2, 0, 1, 3, 
                // Src: (vector_extract:f32 v8f32:v8f32:$vec, i32:i32:$idx) - Complexity = 3
                // Dst: (SI_INDIRECT_SRC:f32 (IMPLICIT_DEF:i1), ?:v8f32:$vec, ?:i32:$idx, 0:i32)
/*21192*/     0, /*End of Scope*/
/*21193*/   /*Scope*/ 14|128,3/*398*/, /*->21593*/
/*21195*/     OPC_CheckChild0Type, MVT::v16f32,
/*21197*/     OPC_Scope, 107|128,2/*363*/, /*->21563*/ // 2 children in Scope
/*21200*/       OPC_MoveChild, 1,
/*21202*/       OPC_Scope, 38, /*->21242*/ // 17 children in Scope
/*21204*/         OPC_CheckOpcode, TARGET_VAL(ISD::ADD),
/*21207*/         OPC_RecordChild0, // #1 = $idx
/*21208*/         OPC_RecordChild1, // #2 = $off
/*21209*/         OPC_MoveChild, 1,
/*21211*/         OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*21214*/         OPC_MoveParent,
/*21215*/         OPC_CheckType, MVT::i32,
/*21217*/         OPC_MoveParent,
/*21218*/         OPC_CheckType, MVT::f32,
/*21220*/         OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*21222*/         OPC_EmitNode, TARGET_VAL(TargetOpcode::IMPLICIT_DEF), 0,
                      1/*#VTs*/, MVT::i1, 0/*#Ops*/,  // Results = #3
/*21229*/         OPC_EmitConvertToTarget, 2,
/*21231*/         OPC_MorphNodeTo, TARGET_VAL(AMDGPU::SI_INDIRECT_SRC), 0,
                      1/*#VTs*/, MVT::f32, 4/*#Ops*/, 3, 0, 1, 4, 
                  // Src: (vector_extract:f32 v16f32:v16f32:$vec, (add:i32 i32:i32:$idx, (imm:i32):$off)) - Complexity = 9
                  // Dst: (SI_INDIRECT_SRC:f32 (IMPLICIT_DEF:i1), ?:v16f32:$vec, ?:i32:$idx, (imm:i32):$off)
/*21242*/       /*Scope*/ 19, /*->21262*/
/*21243*/         OPC_CheckInteger, 0, 
/*21245*/         OPC_MoveParent,
/*21246*/         OPC_CheckType, MVT::f32,
/*21248*/         OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*21250*/         OPC_EmitInteger, MVT::i32, AMDGPU::sub0,
/*21253*/         OPC_MorphNodeTo, TARGET_VAL(TargetOpcode::EXTRACT_SUBREG), 0,
                      1/*#VTs*/, MVT::f32, 2/*#Ops*/, 0, 1, 
                  // Src: (vector_extract:f32 v16f32:v16f32:$src, 0:iPTR) - Complexity = 8
                  // Dst: (EXTRACT_SUBREG:f32 ?:v16f32:$src, sub0:i32)
/*21262*/       /*Scope*/ 19, /*->21282*/
/*21263*/         OPC_CheckInteger, 1, 
/*21265*/         OPC_MoveParent,
/*21266*/         OPC_CheckType, MVT::f32,
/*21268*/         OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*21270*/         OPC_EmitInteger, MVT::i32, AMDGPU::sub1,
/*21273*/         OPC_MorphNodeTo, TARGET_VAL(TargetOpcode::EXTRACT_SUBREG), 0,
                      1/*#VTs*/, MVT::f32, 2/*#Ops*/, 0, 1, 
                  // Src: (vector_extract:f32 v16f32:v16f32:$src, 1:iPTR) - Complexity = 8
                  // Dst: (EXTRACT_SUBREG:f32 ?:v16f32:$src, sub1:i32)
/*21282*/       /*Scope*/ 19, /*->21302*/
/*21283*/         OPC_CheckInteger, 2, 
/*21285*/         OPC_MoveParent,
/*21286*/         OPC_CheckType, MVT::f32,
/*21288*/         OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*21290*/         OPC_EmitInteger, MVT::i32, AMDGPU::sub2,
/*21293*/         OPC_MorphNodeTo, TARGET_VAL(TargetOpcode::EXTRACT_SUBREG), 0,
                      1/*#VTs*/, MVT::f32, 2/*#Ops*/, 0, 1, 
                  // Src: (vector_extract:f32 v16f32:v16f32:$src, 2:iPTR) - Complexity = 8
                  // Dst: (EXTRACT_SUBREG:f32 ?:v16f32:$src, sub2:i32)
/*21302*/       /*Scope*/ 19, /*->21322*/
/*21303*/         OPC_CheckInteger, 3, 
/*21305*/         OPC_MoveParent,
/*21306*/         OPC_CheckType, MVT::f32,
/*21308*/         OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*21310*/         OPC_EmitInteger, MVT::i32, AMDGPU::sub3,
/*21313*/         OPC_MorphNodeTo, TARGET_VAL(TargetOpcode::EXTRACT_SUBREG), 0,
                      1/*#VTs*/, MVT::f32, 2/*#Ops*/, 0, 1, 
                  // Src: (vector_extract:f32 v16f32:v16f32:$src, 3:iPTR) - Complexity = 8
                  // Dst: (EXTRACT_SUBREG:f32 ?:v16f32:$src, sub3:i32)
/*21322*/       /*Scope*/ 19, /*->21342*/
/*21323*/         OPC_CheckInteger, 4, 
/*21325*/         OPC_MoveParent,
/*21326*/         OPC_CheckType, MVT::f32,
/*21328*/         OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*21330*/         OPC_EmitInteger, MVT::i32, AMDGPU::sub4,
/*21333*/         OPC_MorphNodeTo, TARGET_VAL(TargetOpcode::EXTRACT_SUBREG), 0,
                      1/*#VTs*/, MVT::f32, 2/*#Ops*/, 0, 1, 
                  // Src: (vector_extract:f32 v16f32:v16f32:$src, 4:iPTR) - Complexity = 8
                  // Dst: (EXTRACT_SUBREG:f32 ?:v16f32:$src, sub4:i32)
/*21342*/       /*Scope*/ 19, /*->21362*/
/*21343*/         OPC_CheckInteger, 5, 
/*21345*/         OPC_MoveParent,
/*21346*/         OPC_CheckType, MVT::f32,
/*21348*/         OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*21350*/         OPC_EmitInteger, MVT::i32, AMDGPU::sub5,
/*21353*/         OPC_MorphNodeTo, TARGET_VAL(TargetOpcode::EXTRACT_SUBREG), 0,
                      1/*#VTs*/, MVT::f32, 2/*#Ops*/, 0, 1, 
                  // Src: (vector_extract:f32 v16f32:v16f32:$src, 5:iPTR) - Complexity = 8
                  // Dst: (EXTRACT_SUBREG:f32 ?:v16f32:$src, sub5:i32)
/*21362*/       /*Scope*/ 19, /*->21382*/
/*21363*/         OPC_CheckInteger, 6, 
/*21365*/         OPC_MoveParent,
/*21366*/         OPC_CheckType, MVT::f32,
/*21368*/         OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*21370*/         OPC_EmitInteger, MVT::i32, AMDGPU::sub6,
/*21373*/         OPC_MorphNodeTo, TARGET_VAL(TargetOpcode::EXTRACT_SUBREG), 0,
                      1/*#VTs*/, MVT::f32, 2/*#Ops*/, 0, 1, 
                  // Src: (vector_extract:f32 v16f32:v16f32:$src, 6:iPTR) - Complexity = 8
                  // Dst: (EXTRACT_SUBREG:f32 ?:v16f32:$src, sub6:i32)
/*21382*/       /*Scope*/ 19, /*->21402*/
/*21383*/         OPC_CheckInteger, 7, 
/*21385*/         OPC_MoveParent,
/*21386*/         OPC_CheckType, MVT::f32,
/*21388*/         OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*21390*/         OPC_EmitInteger, MVT::i32, AMDGPU::sub7,
/*21393*/         OPC_MorphNodeTo, TARGET_VAL(TargetOpcode::EXTRACT_SUBREG), 0,
                      1/*#VTs*/, MVT::f32, 2/*#Ops*/, 0, 1, 
                  // Src: (vector_extract:f32 v16f32:v16f32:$src, 7:iPTR) - Complexity = 8
                  // Dst: (EXTRACT_SUBREG:f32 ?:v16f32:$src, sub7:i32)
/*21402*/       /*Scope*/ 19, /*->21422*/
/*21403*/         OPC_CheckInteger, 8, 
/*21405*/         OPC_MoveParent,
/*21406*/         OPC_CheckType, MVT::f32,
/*21408*/         OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*21410*/         OPC_EmitInteger, MVT::i32, AMDGPU::sub8,
/*21413*/         OPC_MorphNodeTo, TARGET_VAL(TargetOpcode::EXTRACT_SUBREG), 0,
                      1/*#VTs*/, MVT::f32, 2/*#Ops*/, 0, 1, 
                  // Src: (vector_extract:f32 v16f32:v16f32:$src, 8:iPTR) - Complexity = 8
                  // Dst: (EXTRACT_SUBREG:f32 ?:v16f32:$src, sub8:i32)
/*21422*/       /*Scope*/ 19, /*->21442*/
/*21423*/         OPC_CheckInteger, 9, 
/*21425*/         OPC_MoveParent,
/*21426*/         OPC_CheckType, MVT::f32,
/*21428*/         OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*21430*/         OPC_EmitInteger, MVT::i32, AMDGPU::sub9,
/*21433*/         OPC_MorphNodeTo, TARGET_VAL(TargetOpcode::EXTRACT_SUBREG), 0,
                      1/*#VTs*/, MVT::f32, 2/*#Ops*/, 0, 1, 
                  // Src: (vector_extract:f32 v16f32:v16f32:$src, 9:iPTR) - Complexity = 8
                  // Dst: (EXTRACT_SUBREG:f32 ?:v16f32:$src, sub9:i32)
/*21442*/       /*Scope*/ 19, /*->21462*/
/*21443*/         OPC_CheckInteger, 10, 
/*21445*/         OPC_MoveParent,
/*21446*/         OPC_CheckType, MVT::f32,
/*21448*/         OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*21450*/         OPC_EmitInteger, MVT::i32, AMDGPU::sub10,
/*21453*/         OPC_MorphNodeTo, TARGET_VAL(TargetOpcode::EXTRACT_SUBREG), 0,
                      1/*#VTs*/, MVT::f32, 2/*#Ops*/, 0, 1, 
                  // Src: (vector_extract:f32 v16f32:v16f32:$src, 10:iPTR) - Complexity = 8
                  // Dst: (EXTRACT_SUBREG:f32 ?:v16f32:$src, sub10:i32)
/*21462*/       /*Scope*/ 19, /*->21482*/
/*21463*/         OPC_CheckInteger, 11, 
/*21465*/         OPC_MoveParent,
/*21466*/         OPC_CheckType, MVT::f32,
/*21468*/         OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*21470*/         OPC_EmitInteger, MVT::i32, AMDGPU::sub11,
/*21473*/         OPC_MorphNodeTo, TARGET_VAL(TargetOpcode::EXTRACT_SUBREG), 0,
                      1/*#VTs*/, MVT::f32, 2/*#Ops*/, 0, 1, 
                  // Src: (vector_extract:f32 v16f32:v16f32:$src, 11:iPTR) - Complexity = 8
                  // Dst: (EXTRACT_SUBREG:f32 ?:v16f32:$src, sub11:i32)
/*21482*/       /*Scope*/ 19, /*->21502*/
/*21483*/         OPC_CheckInteger, 12, 
/*21485*/         OPC_MoveParent,
/*21486*/         OPC_CheckType, MVT::f32,
/*21488*/         OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*21490*/         OPC_EmitInteger, MVT::i32, AMDGPU::sub12,
/*21493*/         OPC_MorphNodeTo, TARGET_VAL(TargetOpcode::EXTRACT_SUBREG), 0,
                      1/*#VTs*/, MVT::f32, 2/*#Ops*/, 0, 1, 
                  // Src: (vector_extract:f32 v16f32:v16f32:$src, 12:iPTR) - Complexity = 8
                  // Dst: (EXTRACT_SUBREG:f32 ?:v16f32:$src, sub12:i32)
/*21502*/       /*Scope*/ 19, /*->21522*/
/*21503*/         OPC_CheckInteger, 13, 
/*21505*/         OPC_MoveParent,
/*21506*/         OPC_CheckType, MVT::f32,
/*21508*/         OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*21510*/         OPC_EmitInteger, MVT::i32, AMDGPU::sub13,
/*21513*/         OPC_MorphNodeTo, TARGET_VAL(TargetOpcode::EXTRACT_SUBREG), 0,
                      1/*#VTs*/, MVT::f32, 2/*#Ops*/, 0, 1, 
                  // Src: (vector_extract:f32 v16f32:v16f32:$src, 13:iPTR) - Complexity = 8
                  // Dst: (EXTRACT_SUBREG:f32 ?:v16f32:$src, sub13:i32)
/*21522*/       /*Scope*/ 19, /*->21542*/
/*21523*/         OPC_CheckInteger, 14, 
/*21525*/         OPC_MoveParent,
/*21526*/         OPC_CheckType, MVT::f32,
/*21528*/         OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*21530*/         OPC_EmitInteger, MVT::i32, AMDGPU::sub14,
/*21533*/         OPC_MorphNodeTo, TARGET_VAL(TargetOpcode::EXTRACT_SUBREG), 0,
                      1/*#VTs*/, MVT::f32, 2/*#Ops*/, 0, 1, 
                  // Src: (vector_extract:f32 v16f32:v16f32:$src, 14:iPTR) - Complexity = 8
                  // Dst: (EXTRACT_SUBREG:f32 ?:v16f32:$src, sub14:i32)
/*21542*/       /*Scope*/ 19, /*->21562*/
/*21543*/         OPC_CheckInteger, 15, 
/*21545*/         OPC_MoveParent,
/*21546*/         OPC_CheckType, MVT::f32,
/*21548*/         OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*21550*/         OPC_EmitInteger, MVT::i32, AMDGPU::sub15,
/*21553*/         OPC_MorphNodeTo, TARGET_VAL(TargetOpcode::EXTRACT_SUBREG), 0,
                      1/*#VTs*/, MVT::f32, 2/*#Ops*/, 0, 1, 
                  // Src: (vector_extract:f32 v16f32:v16f32:$src, 15:iPTR) - Complexity = 8
                  // Dst: (EXTRACT_SUBREG:f32 ?:v16f32:$src, sub15:i32)
/*21562*/       0, /*End of Scope*/
/*21563*/     /*Scope*/ 28, /*->21592*/
/*21564*/       OPC_RecordChild1, // #1 = $idx
/*21565*/       OPC_CheckChild1Type, MVT::i32,
/*21567*/       OPC_CheckType, MVT::f32,
/*21569*/       OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*21571*/       OPC_EmitNode, TARGET_VAL(TargetOpcode::IMPLICIT_DEF), 0,
                    1/*#VTs*/, MVT::i1, 0/*#Ops*/,  // Results = #2
/*21578*/       OPC_EmitInteger, MVT::i32, 0, 
/*21581*/       OPC_MorphNodeTo, TARGET_VAL(AMDGPU::SI_INDIRECT_SRC), 0,
                    1/*#VTs*/, MVT::f32, 4/*#Ops*/, 2, 0, 1, 3, 
                // Src: (vector_extract:f32 v16f32:v16f32:$vec, i32:i32:$idx) - Complexity = 3
                // Dst: (SI_INDIRECT_SRC:f32 (IMPLICIT_DEF:i1), ?:v16f32:$vec, ?:i32:$idx, 0:i32)
/*21592*/     0, /*End of Scope*/
/*21593*/   0, /*End of Scope*/
/*21594*/ /*SwitchOpcode*/ 110,  TARGET_VAL(ISD::INTRINSIC_W_CHAIN),// ->21707
/*21597*/   OPC_RecordNode,   // #0 = 'intrinsic_w_chain' chained node
/*21598*/   OPC_MoveChild, 1,
/*21600*/   OPC_Scope, 24, /*->21626*/ // 5 children in Scope
/*21602*/     OPC_CheckInteger, 99|128,26/*3427*/, 
/*21605*/     OPC_MoveParent,
/*21606*/     OPC_RecordChild2, // #1 = $vcc
/*21607*/     OPC_RecordChild3, // #2 = $target
/*21608*/     OPC_MoveChild, 3,
/*21610*/     OPC_CheckOpcode, TARGET_VAL(ISD::BasicBlock),
/*21613*/     OPC_MoveParent,
/*21614*/     OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*21616*/     OPC_EmitMergeInputChains1_0,
/*21617*/     OPC_MorphNodeTo, TARGET_VAL(AMDGPU::SI_IF), 0|OPFL_Chain,
                  1/*#VTs*/, MVT::i64, 2/*#Ops*/, 1, 2, 
              // Src: (intrinsic_w_chain:i64 3427:iPTR, i1:i1:$vcc, (bb:Other):$target) - Complexity = 8
              // Dst: (SI_IF:i64 i1:i1:$vcc, (bb:Other):$target)
/*21626*/   /*Scope*/ 24, /*->21651*/
/*21627*/     OPC_CheckInteger, 93|128,26/*3421*/, 
/*21630*/     OPC_MoveParent,
/*21631*/     OPC_RecordChild2, // #1 = $src
/*21632*/     OPC_RecordChild3, // #2 = $target
/*21633*/     OPC_MoveChild, 3,
/*21635*/     OPC_CheckOpcode, TARGET_VAL(ISD::BasicBlock),
/*21638*/     OPC_MoveParent,
/*21639*/     OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*21641*/     OPC_EmitMergeInputChains1_0,
/*21642*/     OPC_MorphNodeTo, TARGET_VAL(AMDGPU::SI_ELSE), 0|OPFL_Chain,
                  1/*#VTs*/, MVT::i64, 2/*#Ops*/, 1, 2, 
              // Src: (intrinsic_w_chain:i64 3421:iPTR, i64:i64:$src, (bb:Other):$target) - Complexity = 8
              // Dst: (SI_ELSE:i64 i64:i64:$src, (bb:Other):$target)
/*21651*/   /*Scope*/ 16, /*->21668*/
/*21652*/     OPC_CheckInteger, 92|128,26/*3420*/, 
/*21655*/     OPC_MoveParent,
/*21656*/     OPC_RecordChild2, // #1 = $src
/*21657*/     OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*21659*/     OPC_EmitMergeInputChains1_0,
/*21660*/     OPC_MorphNodeTo, TARGET_VAL(AMDGPU::SI_BREAK), 0|OPFL_Chain,
                  1/*#VTs*/, MVT::i64, 1/*#Ops*/, 1, 
              // Src: (intrinsic_w_chain:i64 3420:iPTR, i64:i64:$src) - Complexity = 8
              // Dst: (SI_BREAK:i64 i64:i64:$src)
/*21668*/   /*Scope*/ 18, /*->21687*/
/*21669*/     OPC_CheckInteger, 100|128,26/*3428*/, 
/*21672*/     OPC_MoveParent,
/*21673*/     OPC_RecordChild2, // #1 = $vcc
/*21674*/     OPC_RecordChild3, // #2 = $src
/*21675*/     OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*21677*/     OPC_EmitMergeInputChains1_0,
/*21678*/     OPC_MorphNodeTo, TARGET_VAL(AMDGPU::SI_IF_BREAK), 0|OPFL_Chain,
                  1/*#VTs*/, MVT::i64, 2/*#Ops*/, 1, 2, 
              // Src: (intrinsic_w_chain:i64 3428:iPTR, i1:i1:$vcc, i64:i64:$src) - Complexity = 8
              // Dst: (SI_IF_BREAK:i64 i1:i1:$vcc, i64:i64:$src)
/*21687*/   /*Scope*/ 18, /*->21706*/
/*21688*/     OPC_CheckInteger, 94|128,26/*3422*/, 
/*21691*/     OPC_MoveParent,
/*21692*/     OPC_RecordChild2, // #1 = $src0
/*21693*/     OPC_RecordChild3, // #2 = $src1
/*21694*/     OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*21696*/     OPC_EmitMergeInputChains1_0,
/*21697*/     OPC_MorphNodeTo, TARGET_VAL(AMDGPU::SI_ELSE_BREAK), 0|OPFL_Chain,
                  1/*#VTs*/, MVT::i64, 2/*#Ops*/, 1, 2, 
              // Src: (intrinsic_w_chain:i64 3422:iPTR, i64:i64:$src0, i64:i64:$src1) - Complexity = 8
              // Dst: (SI_ELSE_BREAK:i64 i64:i64:$src0, i64:i64:$src1)
/*21706*/   0, /*End of Scope*/
/*21707*/ /*SwitchOpcode*/ 125|128,6/*893*/,  TARGET_VAL(ISD::STORE),// ->22604
/*21711*/   OPC_RecordMemRef,
/*21712*/   OPC_RecordNode,   // #0 = 'st' chained node
/*21713*/   OPC_RecordChild1, // #1 = $value
/*21714*/   OPC_Scope, 41|128,4/*553*/, /*->22270*/ // 4 children in Scope
/*21717*/     OPC_CheckChild1Type, MVT::i32,
/*21719*/     OPC_Scope, 106, /*->21827*/ // 2 children in Scope
/*21721*/       OPC_MoveChild, 2,
/*21723*/       OPC_CheckOpcode, TARGET_VAL(ISD::ADD),
/*21726*/       OPC_RecordChild0, // #2 = $ptr
/*21727*/       OPC_RecordChild1, // #3 = $offset
/*21728*/       OPC_CheckType, MVT::i64,
/*21730*/       OPC_MoveParent,
/*21731*/       OPC_CheckPredicate, 46, // Predicate_unindexedstore
/*21733*/       OPC_Scope, 62, /*->21797*/ // 2 children in Scope
/*21735*/         OPC_CheckPredicate, 47, // Predicate_truncstore
/*21737*/         OPC_Scope, 28, /*->21767*/ // 2 children in Scope
/*21739*/           OPC_CheckPredicate, 48, // Predicate_truncstorei8
/*21741*/           OPC_CheckPredicate, 49, // Predicate_truncstorei8_global
/*21743*/           OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*21745*/           OPC_EmitMergeInputChains1_0,
/*21746*/           OPC_EmitNode, TARGET_VAL(AMDGPU::SI_ADDR64_RSRC), 0|OPFL_Chain,
                        1/*#VTs*/, MVT::i128, 1/*#Ops*/, 2,  // Results = #4
/*21754*/           OPC_EmitInteger, MVT::i16, 0, 
/*21757*/           OPC_MorphNodeTo, TARGET_VAL(AMDGPU::BUFFER_STORE_BYTE), 0|OPFL_Chain|OPFL_MemRefs,
                        0/*#VTs*/, 4/*#Ops*/, 1, 4, 3, 5, 
                    // Src: (st i32:i32:$value, (add:i64 i64:i64:$ptr, i64:i64:$offset))<<P:Predicate_unindexedstore>><<P:Predicate_truncstore>><<P:Predicate_truncstorei8>><<P:Predicate_truncstorei8_global>> - Complexity = 7
                    // Dst: (BUFFER_STORE_BYTE ?:i32:$value, (SI_ADDR64_RSRC:i128 ?:i64:$ptr), ?:i64:$offset, 0:i16)
/*21767*/         /*Scope*/ 28, /*->21796*/
/*21768*/           OPC_CheckPredicate, 50, // Predicate_truncstorei16
/*21770*/           OPC_CheckPredicate, 51, // Predicate_truncstorei16_global
/*21772*/           OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*21774*/           OPC_EmitMergeInputChains1_0,
/*21775*/           OPC_EmitNode, TARGET_VAL(AMDGPU::SI_ADDR64_RSRC), 0|OPFL_Chain,
                        1/*#VTs*/, MVT::i128, 1/*#Ops*/, 2,  // Results = #4
/*21783*/           OPC_EmitInteger, MVT::i16, 0, 
/*21786*/           OPC_MorphNodeTo, TARGET_VAL(AMDGPU::BUFFER_STORE_SHORT), 0|OPFL_Chain|OPFL_MemRefs,
                        0/*#VTs*/, 4/*#Ops*/, 1, 4, 3, 5, 
                    // Src: (st i32:i32:$value, (add:i64 i64:i64:$ptr, i64:i64:$offset))<<P:Predicate_unindexedstore>><<P:Predicate_truncstore>><<P:Predicate_truncstorei16>><<P:Predicate_truncstorei16_global>> - Complexity = 7
                    // Dst: (BUFFER_STORE_SHORT ?:i32:$value, (SI_ADDR64_RSRC:i128 ?:i64:$ptr), ?:i64:$offset, 0:i16)
/*21796*/         0, /*End of Scope*/
/*21797*/       /*Scope*/ 28, /*->21826*/
/*21798*/         OPC_CheckPredicate, 52, // Predicate_store
/*21800*/         OPC_CheckPredicate, 53, // Predicate_global_store
/*21802*/         OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*21804*/         OPC_EmitMergeInputChains1_0,
/*21805*/         OPC_EmitNode, TARGET_VAL(AMDGPU::SI_ADDR64_RSRC), 0|OPFL_Chain,
                      1/*#VTs*/, MVT::i128, 1/*#Ops*/, 2,  // Results = #4
/*21813*/         OPC_EmitInteger, MVT::i16, 0, 
/*21816*/         OPC_MorphNodeTo, TARGET_VAL(AMDGPU::BUFFER_STORE_DWORD), 0|OPFL_Chain|OPFL_MemRefs,
                      0/*#VTs*/, 4/*#Ops*/, 1, 4, 3, 5, 
                  // Src: (st i32:i32:$value, (add:i64 i64:i64:$ptr, i64:i64:$offset))<<P:Predicate_unindexedstore>><<P:Predicate_store>><<P:Predicate_global_store>> - Complexity = 7
                  // Dst: (BUFFER_STORE_DWORD ?:i32:$value, (SI_ADDR64_RSRC:i128 ?:i64:$ptr), ?:i64:$offset, 0:i16)
/*21826*/       0, /*End of Scope*/
/*21827*/     /*Scope*/ 56|128,3/*440*/, /*->22269*/
/*21829*/       OPC_RecordChild2, // #2 = $src0
/*21830*/       OPC_Scope, 71|128,2/*327*/, /*->22160*/ // 2 children in Scope
/*21833*/         OPC_CheckChild2Type, MVT::i32,
/*21835*/         OPC_CheckPredicate, 46, // Predicate_unindexedstore
/*21837*/         OPC_Scope, 61, /*->21900*/ // 5 children in Scope
/*21839*/           OPC_CheckPredicate, 52, // Predicate_store
/*21841*/           OPC_CheckPredicate, 54, // Predicate_local_store
/*21843*/           OPC_CheckPatternPredicate, 2, // (Subtarget.getGeneration() == AMDGPUSubtarget::EVERGREEN|| Subtarget.getGeneration() ==AMDGPUSubtarget::NORTHERN_ISLANDS)
/*21845*/           OPC_EmitMergeInputChains1_0,
/*21846*/           OPC_EmitInteger, MVT::i32, 0, 
/*21849*/           OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*21861*/           OPC_EmitInteger, MVT::i32, 0, 
/*21864*/           OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*21876*/           OPC_EmitInteger, MVT::i32, 1, 
/*21879*/           OPC_EmitRegister, MVT::i32, AMDGPU::PRED_SEL_OFF,
/*21882*/           OPC_EmitInteger, MVT::i32, 0, 
/*21885*/           OPC_MorphNodeTo, TARGET_VAL(AMDGPU::LDS_WRITE), 0|OPFL_Chain|OPFL_MemRefs,
                        0/*#VTs*/, 9/*#Ops*/, 2, 3, 4, 1, 5, 6, 7, 8, 9, 
                    // Src: (st R600_Reg32:i32:$src1, R600_Reg32:i32:$src0)<<P:Predicate_unindexedstore>><<P:Predicate_store>><<P:Predicate_local_store>> - Complexity = 4
                    // Dst: (LDS_WRITE R600_Reg32:i32:$src0, R600_Reg32:i32:$src1)
/*21900*/         /*Scope*/ 0|128,1/*128*/, /*->22030*/
/*21902*/           OPC_CheckPredicate, 47, // Predicate_truncstore
/*21904*/           OPC_Scope, 61, /*->21967*/ // 2 children in Scope
/*21906*/             OPC_CheckPredicate, 48, // Predicate_truncstorei8
/*21908*/             OPC_CheckPredicate, 55, // Predicate_truncstorei8_local
/*21910*/             OPC_CheckPatternPredicate, 2, // (Subtarget.getGeneration() == AMDGPUSubtarget::EVERGREEN|| Subtarget.getGeneration() ==AMDGPUSubtarget::NORTHERN_ISLANDS)
/*21912*/             OPC_EmitMergeInputChains1_0,
/*21913*/             OPC_EmitInteger, MVT::i32, 0, 
/*21916*/             OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*21928*/             OPC_EmitInteger, MVT::i32, 0, 
/*21931*/             OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*21943*/             OPC_EmitInteger, MVT::i32, 1, 
/*21946*/             OPC_EmitRegister, MVT::i32, AMDGPU::PRED_SEL_OFF,
/*21949*/             OPC_EmitInteger, MVT::i32, 0, 
/*21952*/             OPC_MorphNodeTo, TARGET_VAL(AMDGPU::LDS_BYTE_WRITE), 0|OPFL_Chain|OPFL_MemRefs,
                          0/*#VTs*/, 9/*#Ops*/, 2, 3, 4, 1, 5, 6, 7, 8, 9, 
                      // Src: (st i32:i32:$src1, i32:i32:$src0)<<P:Predicate_unindexedstore>><<P:Predicate_truncstore>><<P:Predicate_truncstorei8>><<P:Predicate_truncstorei8_local>> - Complexity = 4
                      // Dst: (LDS_BYTE_WRITE i32:i32:$src0, i32:i32:$src1)
/*21967*/           /*Scope*/ 61, /*->22029*/
/*21968*/             OPC_CheckPredicate, 50, // Predicate_truncstorei16
/*21970*/             OPC_CheckPredicate, 56, // Predicate_truncstorei16_local
/*21972*/             OPC_CheckPatternPredicate, 2, // (Subtarget.getGeneration() == AMDGPUSubtarget::EVERGREEN|| Subtarget.getGeneration() ==AMDGPUSubtarget::NORTHERN_ISLANDS)
/*21974*/             OPC_EmitMergeInputChains1_0,
/*21975*/             OPC_EmitInteger, MVT::i32, 0, 
/*21978*/             OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*21990*/             OPC_EmitInteger, MVT::i32, 0, 
/*21993*/             OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*22005*/             OPC_EmitInteger, MVT::i32, 1, 
/*22008*/             OPC_EmitRegister, MVT::i32, AMDGPU::PRED_SEL_OFF,
/*22011*/             OPC_EmitInteger, MVT::i32, 0, 
/*22014*/             OPC_MorphNodeTo, TARGET_VAL(AMDGPU::LDS_SHORT_WRITE), 0|OPFL_Chain|OPFL_MemRefs,
                          0/*#VTs*/, 9/*#Ops*/, 2, 3, 4, 1, 5, 6, 7, 8, 9, 
                      // Src: (st i32:i32:$src1, i32:i32:$src0)<<P:Predicate_unindexedstore>><<P:Predicate_truncstore>><<P:Predicate_truncstorei16>><<P:Predicate_truncstorei16_local>> - Complexity = 4
                      // Dst: (LDS_SHORT_WRITE i32:i32:$src0, i32:i32:$src1)
/*22029*/           0, /*End of Scope*/
/*22030*/         /*Scope*/ 15, /*->22046*/
/*22031*/           OPC_CheckPredicate, 52, // Predicate_store
/*22033*/           OPC_CheckPredicate, 53, // Predicate_global_store
/*22035*/           OPC_CheckPatternPredicate, 4, // (Subtarget.hasCaymanISA())
/*22037*/           OPC_EmitMergeInputChains1_0,
/*22038*/           OPC_MorphNodeTo, TARGET_VAL(AMDGPU::RAT_STORE_DWORD32), 0|OPFL_Chain|OPFL_MemRefs,
                        0/*#VTs*/, 2/*#Ops*/, 1, 2, 
                    // Src: (st i32:i32:$rw_gpr, i32:i32:$index_gpr)<<P:Predicate_unindexedstore>><<P:Predicate_store>><<P:Predicate_global_store>> - Complexity = 4
                    // Dst: (RAT_STORE_DWORD32 i32:i32:$rw_gpr, i32:i32:$index_gpr)
/*22046*/         /*Scope*/ 62, /*->22109*/
/*22047*/           OPC_CheckPredicate, 47, // Predicate_truncstore
/*22049*/           OPC_Scope, 28, /*->22079*/ // 2 children in Scope
/*22051*/             OPC_CheckPredicate, 48, // Predicate_truncstorei8
/*22053*/             OPC_CheckPredicate, 55, // Predicate_truncstorei8_local
/*22055*/             OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*22057*/             OPC_EmitMergeInputChains1_0,
/*22058*/             OPC_EmitInteger, MVT::i1, 0, 
/*22061*/             OPC_EmitInteger, MVT::i8, 0, 
/*22064*/             OPC_EmitInteger, MVT::i8, 0, 
/*22067*/             OPC_MorphNodeTo, TARGET_VAL(AMDGPU::DS_WRITE_B8), 0|OPFL_Chain|OPFL_MemRefs,
                          0/*#VTs*/, 6/*#Ops*/, 3, 2, 1, 1, 4, 5, 
                      // Src: (st i32:i32:$src1, i32:i32:$src0)<<P:Predicate_unindexedstore>><<P:Predicate_truncstore>><<P:Predicate_truncstorei8>><<P:Predicate_truncstorei8_local>> - Complexity = 4
                      // Dst: (DS_WRITE_B8 0:i1, ?:i32:$src0, ?:i32:$src1, ?:i32:$src1, 0:i8, 0:i8)
/*22079*/           /*Scope*/ 28, /*->22108*/
/*22080*/             OPC_CheckPredicate, 50, // Predicate_truncstorei16
/*22082*/             OPC_CheckPredicate, 56, // Predicate_truncstorei16_local
/*22084*/             OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*22086*/             OPC_EmitMergeInputChains1_0,
/*22087*/             OPC_EmitInteger, MVT::i1, 0, 
/*22090*/             OPC_EmitInteger, MVT::i8, 0, 
/*22093*/             OPC_EmitInteger, MVT::i8, 0, 
/*22096*/             OPC_MorphNodeTo, TARGET_VAL(AMDGPU::DS_WRITE_B16), 0|OPFL_Chain|OPFL_MemRefs,
                          0/*#VTs*/, 6/*#Ops*/, 3, 2, 1, 1, 4, 5, 
                      // Src: (st i32:i32:$src1, i32:i32:$src0)<<P:Predicate_unindexedstore>><<P:Predicate_truncstore>><<P:Predicate_truncstorei16>><<P:Predicate_truncstorei16_local>> - Complexity = 4
                      // Dst: (DS_WRITE_B16 0:i1, ?:i32:$src0, ?:i32:$src1, ?:i32:$src1, 0:i8, 0:i8)
/*22108*/           0, /*End of Scope*/
/*22109*/         /*Scope*/ 49, /*->22159*/
/*22110*/           OPC_CheckPredicate, 52, // Predicate_store
/*22112*/           OPC_Scope, 26, /*->22140*/ // 2 children in Scope
/*22114*/             OPC_CheckPredicate, 54, // Predicate_local_store
/*22116*/             OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*22118*/             OPC_EmitMergeInputChains1_0,
/*22119*/             OPC_EmitInteger, MVT::i1, 0, 
/*22122*/             OPC_EmitInteger, MVT::i8, 0, 
/*22125*/             OPC_EmitInteger, MVT::i8, 0, 
/*22128*/             OPC_MorphNodeTo, TARGET_VAL(AMDGPU::DS_WRITE_B32), 0|OPFL_Chain|OPFL_MemRefs,
                          0/*#VTs*/, 6/*#Ops*/, 3, 2, 1, 1, 4, 5, 
                      // Src: (st i32:i32:$src1, i32:i32:$src0)<<P:Predicate_unindexedstore>><<P:Predicate_store>><<P:Predicate_local_store>> - Complexity = 4
                      // Dst: (DS_WRITE_B32 0:i1, ?:i32:$src0, ?:i32:$src1, ?:i32:$src1, 0:i8, 0:i8)
/*22140*/           /*Scope*/ 17, /*->22158*/
/*22141*/             OPC_CheckPredicate, 53, // Predicate_global_store
/*22143*/             OPC_CheckPatternPredicate, 5, // (Subtarget.getGeneration() >= AMDGPUSubtarget::EVERGREEN && Subtarget.getGeneration() < AMDGPUSubtarget::SOUTHERN_ISLANDS && !Subtarget.hasCaymanISA())
/*22145*/             OPC_EmitMergeInputChains1_0,
/*22146*/             OPC_EmitInteger, MVT::i32, 0, 
/*22149*/             OPC_MorphNodeTo, TARGET_VAL(AMDGPU::RAT_WRITE_CACHELESS_32_eg), 0|OPFL_Chain|OPFL_MemRefs,
                          0/*#VTs*/, 3/*#Ops*/, 1, 2, 3, 
                      // Src: (st i32:i32:$rw_gpr, i32:i32:$index_gpr)<<P:Predicate_unindexedstore>><<P:Predicate_store>><<P:Predicate_global_store>> - Complexity = 4
                      // Dst: (RAT_WRITE_CACHELESS_32_eg i32:i32:$rw_gpr, i32:i32:$index_gpr)
/*22158*/           0, /*End of Scope*/
/*22159*/         0, /*End of Scope*/
/*22160*/       /*Scope*/ 107, /*->22268*/
/*22161*/         OPC_CheckChild2Type, MVT::i64,
/*22163*/         OPC_CheckPredicate, 46, // Predicate_unindexedstore
/*22165*/         OPC_Scope, 68, /*->22235*/ // 2 children in Scope
/*22167*/           OPC_CheckPredicate, 47, // Predicate_truncstore
/*22169*/           OPC_Scope, 31, /*->22202*/ // 2 children in Scope
/*22171*/             OPC_CheckPredicate, 48, // Predicate_truncstorei8
/*22173*/             OPC_CheckPredicate, 49, // Predicate_truncstorei8_global
/*22175*/             OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*22177*/             OPC_EmitMergeInputChains1_0,
/*22178*/             OPC_EmitInteger, MVT::i64, 0, 
/*22181*/             OPC_EmitNode, TARGET_VAL(AMDGPU::SI_ADDR64_RSRC), 0|OPFL_Chain,
                          1/*#VTs*/, MVT::i128, 1/*#Ops*/, 3,  // Results = #4
/*22189*/             OPC_EmitInteger, MVT::i16, 0, 
/*22192*/             OPC_MorphNodeTo, TARGET_VAL(AMDGPU::BUFFER_STORE_BYTE), 0|OPFL_Chain|OPFL_MemRefs,
                          0/*#VTs*/, 4/*#Ops*/, 1, 4, 2, 5, 
                      // Src: (st i32:i32:$value, i64:i64:$ptr)<<P:Predicate_unindexedstore>><<P:Predicate_truncstore>><<P:Predicate_truncstorei8>><<P:Predicate_truncstorei8_global>> - Complexity = 4
                      // Dst: (BUFFER_STORE_BYTE ?:i32:$value, (SI_ADDR64_RSRC:i128 0:i64), ?:i64:$ptr, 0:i16)
/*22202*/           /*Scope*/ 31, /*->22234*/
/*22203*/             OPC_CheckPredicate, 50, // Predicate_truncstorei16
/*22205*/             OPC_CheckPredicate, 51, // Predicate_truncstorei16_global
/*22207*/             OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*22209*/             OPC_EmitMergeInputChains1_0,
/*22210*/             OPC_EmitInteger, MVT::i64, 0, 
/*22213*/             OPC_EmitNode, TARGET_VAL(AMDGPU::SI_ADDR64_RSRC), 0|OPFL_Chain,
                          1/*#VTs*/, MVT::i128, 1/*#Ops*/, 3,  // Results = #4
/*22221*/             OPC_EmitInteger, MVT::i16, 0, 
/*22224*/             OPC_MorphNodeTo, TARGET_VAL(AMDGPU::BUFFER_STORE_SHORT), 0|OPFL_Chain|OPFL_MemRefs,
                          0/*#VTs*/, 4/*#Ops*/, 1, 4, 2, 5, 
                      // Src: (st i32:i32:$value, i64:i64:$ptr)<<P:Predicate_unindexedstore>><<P:Predicate_truncstore>><<P:Predicate_truncstorei16>><<P:Predicate_truncstorei16_global>> - Complexity = 4
                      // Dst: (BUFFER_STORE_SHORT ?:i32:$value, (SI_ADDR64_RSRC:i128 0:i64), ?:i64:$ptr, 0:i16)
/*22234*/           0, /*End of Scope*/
/*22235*/         /*Scope*/ 31, /*->22267*/
/*22236*/           OPC_CheckPredicate, 52, // Predicate_store
/*22238*/           OPC_CheckPredicate, 53, // Predicate_global_store
/*22240*/           OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*22242*/           OPC_EmitMergeInputChains1_0,
/*22243*/           OPC_EmitInteger, MVT::i64, 0, 
/*22246*/           OPC_EmitNode, TARGET_VAL(AMDGPU::SI_ADDR64_RSRC), 0|OPFL_Chain,
                        1/*#VTs*/, MVT::i128, 1/*#Ops*/, 3,  // Results = #4
/*22254*/           OPC_EmitInteger, MVT::i16, 0, 
/*22257*/           OPC_MorphNodeTo, TARGET_VAL(AMDGPU::BUFFER_STORE_DWORD), 0|OPFL_Chain|OPFL_MemRefs,
                        0/*#VTs*/, 4/*#Ops*/, 1, 4, 2, 5, 
                    // Src: (st i32:i32:$value, i64:i64:$ptr)<<P:Predicate_unindexedstore>><<P:Predicate_store>><<P:Predicate_global_store>> - Complexity = 4
                    // Dst: (BUFFER_STORE_DWORD ?:i32:$value, (SI_ADDR64_RSRC:i128 0:i64), ?:i64:$ptr, 0:i16)
/*22267*/         0, /*End of Scope*/
/*22268*/       0, /*End of Scope*/
/*22269*/     0, /*End of Scope*/
/*22270*/   /*Scope*/ 82, /*->22353*/
/*22271*/     OPC_CheckChild1Type, MVT::i64,
/*22273*/     OPC_Scope, 40, /*->22315*/ // 2 children in Scope
/*22275*/       OPC_MoveChild, 2,
/*22277*/       OPC_CheckOpcode, TARGET_VAL(ISD::ADD),
/*22280*/       OPC_RecordChild0, // #2 = $ptr
/*22281*/       OPC_RecordChild1, // #3 = $offset
/*22282*/       OPC_CheckType, MVT::i64,
/*22284*/       OPC_MoveParent,
/*22285*/       OPC_CheckPredicate, 46, // Predicate_unindexedstore
/*22287*/       OPC_CheckPredicate, 52, // Predicate_store
/*22289*/       OPC_CheckPredicate, 53, // Predicate_global_store
/*22291*/       OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*22293*/       OPC_EmitMergeInputChains1_0,
/*22294*/       OPC_EmitNode, TARGET_VAL(AMDGPU::SI_ADDR64_RSRC), 0|OPFL_Chain,
                    1/*#VTs*/, MVT::i128, 1/*#Ops*/, 2,  // Results = #4
/*22302*/       OPC_EmitInteger, MVT::i16, 0, 
/*22305*/       OPC_MorphNodeTo, TARGET_VAL(AMDGPU::BUFFER_STORE_DWORDX2), 0|OPFL_Chain|OPFL_MemRefs,
                    0/*#VTs*/, 4/*#Ops*/, 1, 4, 3, 5, 
                // Src: (st i64:i64:$value, (add:i64 i64:i64:$ptr, i64:i64:$offset))<<P:Predicate_unindexedstore>><<P:Predicate_store>><<P:Predicate_global_store>> - Complexity = 7
                // Dst: (BUFFER_STORE_DWORDX2 ?:i64:$value, (SI_ADDR64_RSRC:i128 ?:i64:$ptr), ?:i64:$offset, 0:i16)
/*22315*/     /*Scope*/ 36, /*->22352*/
/*22316*/       OPC_RecordChild2, // #2 = $ptr
/*22317*/       OPC_CheckChild2Type, MVT::i64,
/*22319*/       OPC_CheckPredicate, 46, // Predicate_unindexedstore
/*22321*/       OPC_CheckPredicate, 52, // Predicate_store
/*22323*/       OPC_CheckPredicate, 53, // Predicate_global_store
/*22325*/       OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*22327*/       OPC_EmitMergeInputChains1_0,
/*22328*/       OPC_EmitInteger, MVT::i64, 0, 
/*22331*/       OPC_EmitNode, TARGET_VAL(AMDGPU::SI_ADDR64_RSRC), 0|OPFL_Chain,
                    1/*#VTs*/, MVT::i128, 1/*#Ops*/, 3,  // Results = #4
/*22339*/       OPC_EmitInteger, MVT::i16, 0, 
/*22342*/       OPC_MorphNodeTo, TARGET_VAL(AMDGPU::BUFFER_STORE_DWORDX2), 0|OPFL_Chain|OPFL_MemRefs,
                    0/*#VTs*/, 4/*#Ops*/, 1, 4, 2, 5, 
                // Src: (st i64:i64:$value, i64:i64:$ptr)<<P:Predicate_unindexedstore>><<P:Predicate_store>><<P:Predicate_global_store>> - Complexity = 4
                // Dst: (BUFFER_STORE_DWORDX2 ?:i64:$value, (SI_ADDR64_RSRC:i128 0:i64), ?:i64:$ptr, 0:i16)
/*22352*/     0, /*End of Scope*/
/*22353*/   /*Scope*/ 124, /*->22478*/
/*22354*/     OPC_CheckChild1Type, MVT::v2i32,
/*22356*/     OPC_Scope, 40, /*->22398*/ // 2 children in Scope
/*22358*/       OPC_MoveChild, 2,
/*22360*/       OPC_CheckOpcode, TARGET_VAL(ISD::ADD),
/*22363*/       OPC_RecordChild0, // #2 = $ptr
/*22364*/       OPC_RecordChild1, // #3 = $offset
/*22365*/       OPC_CheckType, MVT::i64,
/*22367*/       OPC_MoveParent,
/*22368*/       OPC_CheckPredicate, 46, // Predicate_unindexedstore
/*22370*/       OPC_CheckPredicate, 52, // Predicate_store
/*22372*/       OPC_CheckPredicate, 53, // Predicate_global_store
/*22374*/       OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*22376*/       OPC_EmitMergeInputChains1_0,
/*22377*/       OPC_EmitNode, TARGET_VAL(AMDGPU::SI_ADDR64_RSRC), 0|OPFL_Chain,
                    1/*#VTs*/, MVT::i128, 1/*#Ops*/, 2,  // Results = #4
/*22385*/       OPC_EmitInteger, MVT::i16, 0, 
/*22388*/       OPC_MorphNodeTo, TARGET_VAL(AMDGPU::BUFFER_STORE_DWORDX2), 0|OPFL_Chain|OPFL_MemRefs,
                    0/*#VTs*/, 4/*#Ops*/, 1, 4, 3, 5, 
                // Src: (st v2i32:v2i32:$value, (add:i64 i64:i64:$ptr, i64:i64:$offset))<<P:Predicate_unindexedstore>><<P:Predicate_store>><<P:Predicate_global_store>> - Complexity = 7
                // Dst: (BUFFER_STORE_DWORDX2 ?:v2i32:$value, (SI_ADDR64_RSRC:i128 ?:i64:$ptr), ?:i64:$offset, 0:i16)
/*22398*/     /*Scope*/ 78, /*->22477*/
/*22399*/       OPC_RecordChild2, // #2 = $index_gpr
/*22400*/       OPC_Scope, 38, /*->22440*/ // 2 children in Scope
/*22402*/         OPC_CheckChild2Type, MVT::i32,
/*22404*/         OPC_CheckPredicate, 46, // Predicate_unindexedstore
/*22406*/         OPC_CheckPredicate, 52, // Predicate_store
/*22408*/         OPC_CheckPredicate, 53, // Predicate_global_store
/*22410*/         OPC_Scope, 11, /*->22423*/ // 2 children in Scope
/*22412*/           OPC_CheckPatternPredicate, 4, // (Subtarget.hasCaymanISA())
/*22414*/           OPC_EmitMergeInputChains1_0,
/*22415*/           OPC_MorphNodeTo, TARGET_VAL(AMDGPU::RAT_STORE_DWORD64), 0|OPFL_Chain|OPFL_MemRefs,
                        0/*#VTs*/, 2/*#Ops*/, 1, 2, 
                    // Src: (st v2i32:v2i32:$rw_gpr, i32:i32:$index_gpr)<<P:Predicate_unindexedstore>><<P:Predicate_store>><<P:Predicate_global_store>> - Complexity = 4
                    // Dst: (RAT_STORE_DWORD64 v2i32:v2i32:$rw_gpr, i32:i32:$index_gpr)
/*22423*/         /*Scope*/ 15, /*->22439*/
/*22424*/           OPC_CheckPatternPredicate, 5, // (Subtarget.getGeneration() >= AMDGPUSubtarget::EVERGREEN && Subtarget.getGeneration() < AMDGPUSubtarget::SOUTHERN_ISLANDS && !Subtarget.hasCaymanISA())
/*22426*/           OPC_EmitMergeInputChains1_0,
/*22427*/           OPC_EmitInteger, MVT::i32, 0, 
/*22430*/           OPC_MorphNodeTo, TARGET_VAL(AMDGPU::RAT_WRITE_CACHELESS_64_eg), 0|OPFL_Chain|OPFL_MemRefs,
                        0/*#VTs*/, 3/*#Ops*/, 1, 2, 3, 
                    // Src: (st v2i32:v2i32:$rw_gpr, i32:i32:$index_gpr)<<P:Predicate_unindexedstore>><<P:Predicate_store>><<P:Predicate_global_store>> - Complexity = 4
                    // Dst: (RAT_WRITE_CACHELESS_64_eg v2i32:v2i32:$rw_gpr, i32:i32:$index_gpr)
/*22439*/         0, /*End of Scope*/
/*22440*/       /*Scope*/ 35, /*->22476*/
/*22441*/         OPC_CheckChild2Type, MVT::i64,
/*22443*/         OPC_CheckPredicate, 46, // Predicate_unindexedstore
/*22445*/         OPC_CheckPredicate, 52, // Predicate_store
/*22447*/         OPC_CheckPredicate, 53, // Predicate_global_store
/*22449*/         OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*22451*/         OPC_EmitMergeInputChains1_0,
/*22452*/         OPC_EmitInteger, MVT::i64, 0, 
/*22455*/         OPC_EmitNode, TARGET_VAL(AMDGPU::SI_ADDR64_RSRC), 0|OPFL_Chain,
                      1/*#VTs*/, MVT::i128, 1/*#Ops*/, 3,  // Results = #4
/*22463*/         OPC_EmitInteger, MVT::i16, 0, 
/*22466*/         OPC_MorphNodeTo, TARGET_VAL(AMDGPU::BUFFER_STORE_DWORDX2), 0|OPFL_Chain|OPFL_MemRefs,
                      0/*#VTs*/, 4/*#Ops*/, 1, 4, 2, 5, 
                  // Src: (st v2i32:v2i32:$value, i64:i64:$ptr)<<P:Predicate_unindexedstore>><<P:Predicate_store>><<P:Predicate_global_store>> - Complexity = 4
                  // Dst: (BUFFER_STORE_DWORDX2 ?:v2i32:$value, (SI_ADDR64_RSRC:i128 0:i64), ?:i64:$ptr, 0:i16)
/*22476*/       0, /*End of Scope*/
/*22477*/     0, /*End of Scope*/
/*22478*/   /*Scope*/ 124, /*->22603*/
/*22479*/     OPC_CheckChild1Type, MVT::v4i32,
/*22481*/     OPC_Scope, 40, /*->22523*/ // 2 children in Scope
/*22483*/       OPC_MoveChild, 2,
/*22485*/       OPC_CheckOpcode, TARGET_VAL(ISD::ADD),
/*22488*/       OPC_RecordChild0, // #2 = $ptr
/*22489*/       OPC_RecordChild1, // #3 = $offset
/*22490*/       OPC_CheckType, MVT::i64,
/*22492*/       OPC_MoveParent,
/*22493*/       OPC_CheckPredicate, 46, // Predicate_unindexedstore
/*22495*/       OPC_CheckPredicate, 52, // Predicate_store
/*22497*/       OPC_CheckPredicate, 53, // Predicate_global_store
/*22499*/       OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*22501*/       OPC_EmitMergeInputChains1_0,
/*22502*/       OPC_EmitNode, TARGET_VAL(AMDGPU::SI_ADDR64_RSRC), 0|OPFL_Chain,
                    1/*#VTs*/, MVT::i128, 1/*#Ops*/, 2,  // Results = #4
/*22510*/       OPC_EmitInteger, MVT::i16, 0, 
/*22513*/       OPC_MorphNodeTo, TARGET_VAL(AMDGPU::BUFFER_STORE_DWORDX4), 0|OPFL_Chain|OPFL_MemRefs,
                    0/*#VTs*/, 4/*#Ops*/, 1, 4, 3, 5, 
                // Src: (st v4i32:v4i32:$value, (add:i64 i64:i64:$ptr, i64:i64:$offset))<<P:Predicate_unindexedstore>><<P:Predicate_store>><<P:Predicate_global_store>> - Complexity = 7
                // Dst: (BUFFER_STORE_DWORDX4 ?:v4i32:$value, (SI_ADDR64_RSRC:i128 ?:i64:$ptr), ?:i64:$offset, 0:i16)
/*22523*/     /*Scope*/ 78, /*->22602*/
/*22524*/       OPC_RecordChild2, // #2 = $index_gpr
/*22525*/       OPC_Scope, 38, /*->22565*/ // 2 children in Scope
/*22527*/         OPC_CheckChild2Type, MVT::i32,
/*22529*/         OPC_CheckPredicate, 46, // Predicate_unindexedstore
/*22531*/         OPC_CheckPredicate, 52, // Predicate_store
/*22533*/         OPC_CheckPredicate, 53, // Predicate_global_store
/*22535*/         OPC_Scope, 11, /*->22548*/ // 2 children in Scope
/*22537*/           OPC_CheckPatternPredicate, 4, // (Subtarget.hasCaymanISA())
/*22539*/           OPC_EmitMergeInputChains1_0,
/*22540*/           OPC_MorphNodeTo, TARGET_VAL(AMDGPU::RAT_STORE_DWORD128), 0|OPFL_Chain|OPFL_MemRefs,
                        0/*#VTs*/, 2/*#Ops*/, 1, 2, 
                    // Src: (st v4i32:v4i32:$rw_gpr, i32:i32:$index_gpr)<<P:Predicate_unindexedstore>><<P:Predicate_store>><<P:Predicate_global_store>> - Complexity = 4
                    // Dst: (RAT_STORE_DWORD128 v4i32:v4i32:$rw_gpr, i32:i32:$index_gpr)
/*22548*/         /*Scope*/ 15, /*->22564*/
/*22549*/           OPC_CheckPatternPredicate, 5, // (Subtarget.getGeneration() >= AMDGPUSubtarget::EVERGREEN && Subtarget.getGeneration() < AMDGPUSubtarget::SOUTHERN_ISLANDS && !Subtarget.hasCaymanISA())
/*22551*/           OPC_EmitMergeInputChains1_0,
/*22552*/           OPC_EmitInteger, MVT::i32, 0, 
/*22555*/           OPC_MorphNodeTo, TARGET_VAL(AMDGPU::RAT_WRITE_CACHELESS_128_eg), 0|OPFL_Chain|OPFL_MemRefs,
                        0/*#VTs*/, 3/*#Ops*/, 1, 2, 3, 
                    // Src: (st v4i32:v4i32:$rw_gpr, i32:i32:$index_gpr)<<P:Predicate_unindexedstore>><<P:Predicate_store>><<P:Predicate_global_store>> - Complexity = 4
                    // Dst: (RAT_WRITE_CACHELESS_128_eg v4i32:v4i32:$rw_gpr, i32:i32:$index_gpr)
/*22564*/         0, /*End of Scope*/
/*22565*/       /*Scope*/ 35, /*->22601*/
/*22566*/         OPC_CheckChild2Type, MVT::i64,
/*22568*/         OPC_CheckPredicate, 46, // Predicate_unindexedstore
/*22570*/         OPC_CheckPredicate, 52, // Predicate_store
/*22572*/         OPC_CheckPredicate, 53, // Predicate_global_store
/*22574*/         OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*22576*/         OPC_EmitMergeInputChains1_0,
/*22577*/         OPC_EmitInteger, MVT::i64, 0, 
/*22580*/         OPC_EmitNode, TARGET_VAL(AMDGPU::SI_ADDR64_RSRC), 0|OPFL_Chain,
                      1/*#VTs*/, MVT::i128, 1/*#Ops*/, 3,  // Results = #4
/*22588*/         OPC_EmitInteger, MVT::i16, 0, 
/*22591*/         OPC_MorphNodeTo, TARGET_VAL(AMDGPU::BUFFER_STORE_DWORDX4), 0|OPFL_Chain|OPFL_MemRefs,
                      0/*#VTs*/, 4/*#Ops*/, 1, 4, 2, 5, 
                  // Src: (st v4i32:v4i32:$value, i64:i64:$ptr)<<P:Predicate_unindexedstore>><<P:Predicate_store>><<P:Predicate_global_store>> - Complexity = 4
                  // Dst: (BUFFER_STORE_DWORDX4 ?:v4i32:$value, (SI_ADDR64_RSRC:i128 0:i64), ?:i64:$ptr, 0:i16)
/*22601*/       0, /*End of Scope*/
/*22602*/     0, /*End of Scope*/
/*22603*/   0, /*End of Scope*/
/*22604*/ /*SwitchOpcode*/ 21,  TARGET_VAL(AMDGPUISD::STORE_MSKOR),// ->22628
/*22607*/   OPC_RecordMemRef,
/*22608*/   OPC_RecordNode,   // #0 = 'AMDGPUstore_mskor' chained node
/*22609*/   OPC_RecordChild1, // #1 = $rw_gpr
/*22610*/   OPC_CheckChild1Type, MVT::v4i32,
/*22612*/   OPC_RecordChild2, // #2 = $index_gpr
/*22613*/   OPC_CheckChild2Type, MVT::i32,
/*22615*/   OPC_CheckPredicate, 57, // Predicate_mskor_global
/*22617*/   OPC_CheckPatternPredicate, 2, // (Subtarget.getGeneration() == AMDGPUSubtarget::EVERGREEN|| Subtarget.getGeneration() ==AMDGPUSubtarget::NORTHERN_ISLANDS)
/*22619*/   OPC_EmitMergeInputChains1_0,
/*22620*/   OPC_MorphNodeTo, TARGET_VAL(AMDGPU::RAT_MSKOR), 0|OPFL_Chain|OPFL_MemRefs,
                0/*#VTs*/, 2/*#Ops*/, 1, 2, 
            // Src: (AMDGPUstore_mskor v4i32:v4i32:$rw_gpr, i32:i32:$index_gpr)<<P:Predicate_mskor_global>> - Complexity = 4
            // Dst: (RAT_MSKOR v4i32:v4i32:$rw_gpr, i32:i32:$index_gpr)
/*22628*/ /*SwitchOpcode*/ 9|128,2/*265*/,  TARGET_VAL(ISD::SHL),// ->22897
/*22632*/   OPC_RecordChild0, // #0 = $src0
/*22633*/   OPC_RecordChild1, // #1 = $src1
/*22634*/   OPC_CheckChild1Type, MVT::i32,
/*22636*/   OPC_SwitchType /*2 cases */, 102|128,1/*230*/,  MVT::i32,// ->22870
/*22640*/     OPC_Scope, 11, /*->22653*/ // 4 children in Scope
/*22642*/       OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*22644*/       OPC_MorphNodeTo, TARGET_VAL(AMDGPU::S_LSHL_B32), 0,
                    1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1, 
                // Src: (shl:i32 i32:i32:$src0, i32:i32:$src1) - Complexity = 4
                // Dst: (S_LSHL_B32:i32 i32:i32:$src0, i32:i32:$src1)
/*22653*/     /*Scope*/ 101, /*->22755*/
/*22654*/       OPC_CheckPatternPredicate, 1, // (Subtarget.getGeneration() <= AMDGPUSubtarget::R700)
/*22656*/       OPC_EmitInteger, MVT::i32, 0, 
/*22659*/       OPC_EmitInteger, MVT::i32, 0, 
/*22662*/       OPC_EmitInteger, MVT::i32, 1, 
/*22665*/       OPC_EmitInteger, MVT::i32, 0, 
/*22668*/       OPC_EmitInteger, MVT::i32, 0, 
/*22671*/       OPC_EmitInteger, MVT::i32, 0, 
/*22674*/       OPC_EmitInteger, MVT::i32, 0, 
/*22677*/       OPC_EmitInteger, MVT::i32, 0, 
/*22680*/       OPC_EmitInteger, MVT::i32, 0, 
/*22683*/       OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*22695*/       OPC_EmitInteger, MVT::i32, 0, 
/*22698*/       OPC_EmitInteger, MVT::i32, 0, 
/*22701*/       OPC_EmitInteger, MVT::i32, 0, 
/*22704*/       OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*22716*/       OPC_EmitInteger, MVT::i32, 1, 
/*22719*/       OPC_EmitRegister, MVT::i32, AMDGPU::PRED_SEL_OFF,
/*22722*/       OPC_EmitInteger, MVT::i32, 0, 
/*22725*/       OPC_EmitInteger, MVT::i32, 0, 
/*22728*/       OPC_MorphNodeTo, TARGET_VAL(AMDGPU::LSHL_r600), 0,
                    1/*#VTs*/, MVT::i32, 20/*#Ops*/, 2, 3, 4, 5, 6, 7, 0, 8, 9, 10, 11, 1, 12, 13, 14, 15, 16, 17, 18, 19, 
                // Src: (shl:i32 R600_Reg32:i32:$src0, R600_Reg32:i32:$src1) - Complexity = 3
                // Dst: (LSHL_r600:i32 R600_Reg32:i32:$src0, R600_Reg32:i32:$src1)
/*22755*/     /*Scope*/ 101, /*->22857*/
/*22756*/       OPC_CheckPatternPredicate, 2, // (Subtarget.getGeneration() == AMDGPUSubtarget::EVERGREEN|| Subtarget.getGeneration() ==AMDGPUSubtarget::NORTHERN_ISLANDS)
/*22758*/       OPC_EmitInteger, MVT::i32, 0, 
/*22761*/       OPC_EmitInteger, MVT::i32, 0, 
/*22764*/       OPC_EmitInteger, MVT::i32, 1, 
/*22767*/       OPC_EmitInteger, MVT::i32, 0, 
/*22770*/       OPC_EmitInteger, MVT::i32, 0, 
/*22773*/       OPC_EmitInteger, MVT::i32, 0, 
/*22776*/       OPC_EmitInteger, MVT::i32, 0, 
/*22779*/       OPC_EmitInteger, MVT::i32, 0, 
/*22782*/       OPC_EmitInteger, MVT::i32, 0, 
/*22785*/       OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*22797*/       OPC_EmitInteger, MVT::i32, 0, 
/*22800*/       OPC_EmitInteger, MVT::i32, 0, 
/*22803*/       OPC_EmitInteger, MVT::i32, 0, 
/*22806*/       OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*22818*/       OPC_EmitInteger, MVT::i32, 1, 
/*22821*/       OPC_EmitRegister, MVT::i32, AMDGPU::PRED_SEL_OFF,
/*22824*/       OPC_EmitInteger, MVT::i32, 0, 
/*22827*/       OPC_EmitInteger, MVT::i32, 0, 
/*22830*/       OPC_MorphNodeTo, TARGET_VAL(AMDGPU::LSHL_eg), 0,
                    1/*#VTs*/, MVT::i32, 20/*#Ops*/, 2, 3, 4, 5, 6, 7, 0, 8, 9, 10, 11, 1, 12, 13, 14, 15, 16, 17, 18, 19, 
                // Src: (shl:i32 R600_Reg32:i32:$src0, R600_Reg32:i32:$src1) - Complexity = 3
                // Dst: (LSHL_eg:i32 R600_Reg32:i32:$src0, R600_Reg32:i32:$src1)
/*22857*/     /*Scope*/ 11, /*->22869*/
/*22858*/       OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*22860*/       OPC_MorphNodeTo, TARGET_VAL(AMDGPU::V_LSHL_B32_e32), 0,
                    1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1, 
                // Src: (shl:i32 i32:i32:$src0, i32:i32:$src1) - Complexity = 3
                // Dst: (V_LSHL_B32_e32:i32 i32:i32:$src0, i32:i32:$src1)
/*22869*/     0, /*End of Scope*/
/*22870*/   /*SwitchType*/ 24,  MVT::i64,// ->22896
/*22872*/     OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*22874*/     OPC_Scope, 9, /*->22885*/ // 2 children in Scope
/*22876*/       OPC_MorphNodeTo, TARGET_VAL(AMDGPU::S_LSHL_B64), 0,
                    1/*#VTs*/, MVT::i64, 2/*#Ops*/, 0, 1, 
                // Src: (shl:i64 i64:i64:$src0, i32:i32:$src1) - Complexity = 4
                // Dst: (S_LSHL_B64:i64 i64:i64:$src0, i32:i32:$src1)
/*22885*/     /*Scope*/ 9, /*->22895*/
/*22886*/       OPC_MorphNodeTo, TARGET_VAL(AMDGPU::V_LSHL_B64), 0,
                    1/*#VTs*/, MVT::i64, 2/*#Ops*/, 0, 1, 
                // Src: (shl:i64 i64:i64:$src0, i32:i32:$src1) - Complexity = 3
                // Dst: (V_LSHL_B64:i64 i64:i64:$src0, i32:i32:$src1)
/*22895*/     0, /*End of Scope*/
/*22896*/   0, // EndSwitchType
/*22897*/ /*SwitchOpcode*/ 9|128,2/*265*/,  TARGET_VAL(ISD::SRL),// ->23166
/*22901*/   OPC_RecordChild0, // #0 = $src0
/*22902*/   OPC_RecordChild1, // #1 = $src1
/*22903*/   OPC_CheckChild1Type, MVT::i32,
/*22905*/   OPC_SwitchType /*2 cases */, 102|128,1/*230*/,  MVT::i32,// ->23139
/*22909*/     OPC_Scope, 11, /*->22922*/ // 4 children in Scope
/*22911*/       OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*22913*/       OPC_MorphNodeTo, TARGET_VAL(AMDGPU::S_LSHR_B32), 0,
                    1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1, 
                // Src: (srl:i32 i32:i32:$src0, i32:i32:$src1) - Complexity = 4
                // Dst: (S_LSHR_B32:i32 i32:i32:$src0, i32:i32:$src1)
/*22922*/     /*Scope*/ 101, /*->23024*/
/*22923*/       OPC_CheckPatternPredicate, 1, // (Subtarget.getGeneration() <= AMDGPUSubtarget::R700)
/*22925*/       OPC_EmitInteger, MVT::i32, 0, 
/*22928*/       OPC_EmitInteger, MVT::i32, 0, 
/*22931*/       OPC_EmitInteger, MVT::i32, 1, 
/*22934*/       OPC_EmitInteger, MVT::i32, 0, 
/*22937*/       OPC_EmitInteger, MVT::i32, 0, 
/*22940*/       OPC_EmitInteger, MVT::i32, 0, 
/*22943*/       OPC_EmitInteger, MVT::i32, 0, 
/*22946*/       OPC_EmitInteger, MVT::i32, 0, 
/*22949*/       OPC_EmitInteger, MVT::i32, 0, 
/*22952*/       OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*22964*/       OPC_EmitInteger, MVT::i32, 0, 
/*22967*/       OPC_EmitInteger, MVT::i32, 0, 
/*22970*/       OPC_EmitInteger, MVT::i32, 0, 
/*22973*/       OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*22985*/       OPC_EmitInteger, MVT::i32, 1, 
/*22988*/       OPC_EmitRegister, MVT::i32, AMDGPU::PRED_SEL_OFF,
/*22991*/       OPC_EmitInteger, MVT::i32, 0, 
/*22994*/       OPC_EmitInteger, MVT::i32, 0, 
/*22997*/       OPC_MorphNodeTo, TARGET_VAL(AMDGPU::LSHR_r600), 0,
                    1/*#VTs*/, MVT::i32, 20/*#Ops*/, 2, 3, 4, 5, 6, 7, 0, 8, 9, 10, 11, 1, 12, 13, 14, 15, 16, 17, 18, 19, 
                // Src: (srl:i32 R600_Reg32:i32:$src0, R600_Reg32:i32:$src1) - Complexity = 3
                // Dst: (LSHR_r600:i32 R600_Reg32:i32:$src0, R600_Reg32:i32:$src1)
/*23024*/     /*Scope*/ 101, /*->23126*/
/*23025*/       OPC_CheckPatternPredicate, 2, // (Subtarget.getGeneration() == AMDGPUSubtarget::EVERGREEN|| Subtarget.getGeneration() ==AMDGPUSubtarget::NORTHERN_ISLANDS)
/*23027*/       OPC_EmitInteger, MVT::i32, 0, 
/*23030*/       OPC_EmitInteger, MVT::i32, 0, 
/*23033*/       OPC_EmitInteger, MVT::i32, 1, 
/*23036*/       OPC_EmitInteger, MVT::i32, 0, 
/*23039*/       OPC_EmitInteger, MVT::i32, 0, 
/*23042*/       OPC_EmitInteger, MVT::i32, 0, 
/*23045*/       OPC_EmitInteger, MVT::i32, 0, 
/*23048*/       OPC_EmitInteger, MVT::i32, 0, 
/*23051*/       OPC_EmitInteger, MVT::i32, 0, 
/*23054*/       OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*23066*/       OPC_EmitInteger, MVT::i32, 0, 
/*23069*/       OPC_EmitInteger, MVT::i32, 0, 
/*23072*/       OPC_EmitInteger, MVT::i32, 0, 
/*23075*/       OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*23087*/       OPC_EmitInteger, MVT::i32, 1, 
/*23090*/       OPC_EmitRegister, MVT::i32, AMDGPU::PRED_SEL_OFF,
/*23093*/       OPC_EmitInteger, MVT::i32, 0, 
/*23096*/       OPC_EmitInteger, MVT::i32, 0, 
/*23099*/       OPC_MorphNodeTo, TARGET_VAL(AMDGPU::LSHR_eg), 0,
                    1/*#VTs*/, MVT::i32, 20/*#Ops*/, 2, 3, 4, 5, 6, 7, 0, 8, 9, 10, 11, 1, 12, 13, 14, 15, 16, 17, 18, 19, 
                // Src: (srl:i32 R600_Reg32:i32:$src0, R600_Reg32:i32:$src1) - Complexity = 3
                // Dst: (LSHR_eg:i32 R600_Reg32:i32:$src0, R600_Reg32:i32:$src1)
/*23126*/     /*Scope*/ 11, /*->23138*/
/*23127*/       OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*23129*/       OPC_MorphNodeTo, TARGET_VAL(AMDGPU::V_LSHR_B32_e32), 0,
                    1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1, 
                // Src: (srl:i32 i32:i32:$src0, i32:i32:$src1) - Complexity = 3
                // Dst: (V_LSHR_B32_e32:i32 i32:i32:$src0, i32:i32:$src1)
/*23138*/     0, /*End of Scope*/
/*23139*/   /*SwitchType*/ 24,  MVT::i64,// ->23165
/*23141*/     OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*23143*/     OPC_Scope, 9, /*->23154*/ // 2 children in Scope
/*23145*/       OPC_MorphNodeTo, TARGET_VAL(AMDGPU::S_LSHR_B64), 0,
                    1/*#VTs*/, MVT::i64, 2/*#Ops*/, 0, 1, 
                // Src: (srl:i64 i64:i64:$src0, i32:i32:$src1) - Complexity = 4
                // Dst: (S_LSHR_B64:i64 i64:i64:$src0, i32:i32:$src1)
/*23154*/     /*Scope*/ 9, /*->23164*/
/*23155*/       OPC_MorphNodeTo, TARGET_VAL(AMDGPU::V_LSHR_B64), 0,
                    1/*#VTs*/, MVT::i64, 2/*#Ops*/, 0, 1, 
                // Src: (srl:i64 i64:i64:$src0, i32:i32:$src1) - Complexity = 3
                // Dst: (V_LSHR_B64:i64 i64:i64:$src0, i32:i32:$src1)
/*23164*/     0, /*End of Scope*/
/*23165*/   0, // EndSwitchType
/*23166*/ /*SwitchOpcode*/ 9|128,2/*265*/,  TARGET_VAL(ISD::SRA),// ->23435
/*23170*/   OPC_RecordChild0, // #0 = $src0
/*23171*/   OPC_RecordChild1, // #1 = $src1
/*23172*/   OPC_CheckChild1Type, MVT::i32,
/*23174*/   OPC_SwitchType /*2 cases */, 102|128,1/*230*/,  MVT::i32,// ->23408
/*23178*/     OPC_Scope, 11, /*->23191*/ // 4 children in Scope
/*23180*/       OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*23182*/       OPC_MorphNodeTo, TARGET_VAL(AMDGPU::S_ASHR_I32), 0,
                    1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1, 
                // Src: (sra:i32 i32:i32:$src0, i32:i32:$src1) - Complexity = 4
                // Dst: (S_ASHR_I32:i32 i32:i32:$src0, i32:i32:$src1)
/*23191*/     /*Scope*/ 101, /*->23293*/
/*23192*/       OPC_CheckPatternPredicate, 1, // (Subtarget.getGeneration() <= AMDGPUSubtarget::R700)
/*23194*/       OPC_EmitInteger, MVT::i32, 0, 
/*23197*/       OPC_EmitInteger, MVT::i32, 0, 
/*23200*/       OPC_EmitInteger, MVT::i32, 1, 
/*23203*/       OPC_EmitInteger, MVT::i32, 0, 
/*23206*/       OPC_EmitInteger, MVT::i32, 0, 
/*23209*/       OPC_EmitInteger, MVT::i32, 0, 
/*23212*/       OPC_EmitInteger, MVT::i32, 0, 
/*23215*/       OPC_EmitInteger, MVT::i32, 0, 
/*23218*/       OPC_EmitInteger, MVT::i32, 0, 
/*23221*/       OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*23233*/       OPC_EmitInteger, MVT::i32, 0, 
/*23236*/       OPC_EmitInteger, MVT::i32, 0, 
/*23239*/       OPC_EmitInteger, MVT::i32, 0, 
/*23242*/       OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*23254*/       OPC_EmitInteger, MVT::i32, 1, 
/*23257*/       OPC_EmitRegister, MVT::i32, AMDGPU::PRED_SEL_OFF,
/*23260*/       OPC_EmitInteger, MVT::i32, 0, 
/*23263*/       OPC_EmitInteger, MVT::i32, 0, 
/*23266*/       OPC_MorphNodeTo, TARGET_VAL(AMDGPU::ASHR_r600), 0,
                    1/*#VTs*/, MVT::i32, 20/*#Ops*/, 2, 3, 4, 5, 6, 7, 0, 8, 9, 10, 11, 1, 12, 13, 14, 15, 16, 17, 18, 19, 
                // Src: (sra:i32 R600_Reg32:i32:$src0, R600_Reg32:i32:$src1) - Complexity = 3
                // Dst: (ASHR_r600:i32 R600_Reg32:i32:$src0, R600_Reg32:i32:$src1)
/*23293*/     /*Scope*/ 101, /*->23395*/
/*23294*/       OPC_CheckPatternPredicate, 2, // (Subtarget.getGeneration() == AMDGPUSubtarget::EVERGREEN|| Subtarget.getGeneration() ==AMDGPUSubtarget::NORTHERN_ISLANDS)
/*23296*/       OPC_EmitInteger, MVT::i32, 0, 
/*23299*/       OPC_EmitInteger, MVT::i32, 0, 
/*23302*/       OPC_EmitInteger, MVT::i32, 1, 
/*23305*/       OPC_EmitInteger, MVT::i32, 0, 
/*23308*/       OPC_EmitInteger, MVT::i32, 0, 
/*23311*/       OPC_EmitInteger, MVT::i32, 0, 
/*23314*/       OPC_EmitInteger, MVT::i32, 0, 
/*23317*/       OPC_EmitInteger, MVT::i32, 0, 
/*23320*/       OPC_EmitInteger, MVT::i32, 0, 
/*23323*/       OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*23335*/       OPC_EmitInteger, MVT::i32, 0, 
/*23338*/       OPC_EmitInteger, MVT::i32, 0, 
/*23341*/       OPC_EmitInteger, MVT::i32, 0, 
/*23344*/       OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*23356*/       OPC_EmitInteger, MVT::i32, 1, 
/*23359*/       OPC_EmitRegister, MVT::i32, AMDGPU::PRED_SEL_OFF,
/*23362*/       OPC_EmitInteger, MVT::i32, 0, 
/*23365*/       OPC_EmitInteger, MVT::i32, 0, 
/*23368*/       OPC_MorphNodeTo, TARGET_VAL(AMDGPU::ASHR_eg), 0,
                    1/*#VTs*/, MVT::i32, 20/*#Ops*/, 2, 3, 4, 5, 6, 7, 0, 8, 9, 10, 11, 1, 12, 13, 14, 15, 16, 17, 18, 19, 
                // Src: (sra:i32 R600_Reg32:i32:$src0, R600_Reg32:i32:$src1) - Complexity = 3
                // Dst: (ASHR_eg:i32 R600_Reg32:i32:$src0, R600_Reg32:i32:$src1)
/*23395*/     /*Scope*/ 11, /*->23407*/
/*23396*/       OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*23398*/       OPC_MorphNodeTo, TARGET_VAL(AMDGPU::V_ASHR_I32_e32), 0,
                    1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1, 
                // Src: (sra:i32 i32:i32:$src0, i32:i32:$src1) - Complexity = 3
                // Dst: (V_ASHR_I32_e32:i32 i32:i32:$src0, i32:i32:$src1)
/*23407*/     0, /*End of Scope*/
/*23408*/   /*SwitchType*/ 24,  MVT::i64,// ->23434
/*23410*/     OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*23412*/     OPC_Scope, 9, /*->23423*/ // 2 children in Scope
/*23414*/       OPC_MorphNodeTo, TARGET_VAL(AMDGPU::S_ASHR_I64), 0,
                    1/*#VTs*/, MVT::i64, 2/*#Ops*/, 0, 1, 
                // Src: (sra:i64 i64:i64:$src0, i32:i32:$src1) - Complexity = 4
                // Dst: (S_ASHR_I64:i64 i64:i64:$src0, i32:i32:$src1)
/*23423*/     /*Scope*/ 9, /*->23433*/
/*23424*/       OPC_MorphNodeTo, TARGET_VAL(AMDGPU::V_ASHR_I64), 0,
                    1/*#VTs*/, MVT::i64, 2/*#Ops*/, 0, 1, 
                // Src: (sra:i64 i64:i64:$src0, i32:i32:$src1) - Complexity = 3
                // Dst: (V_ASHR_I64:i64 i64:i64:$src0, i32:i32:$src1)
/*23433*/     0, /*End of Scope*/
/*23434*/   0, // EndSwitchType
/*23435*/ /*SwitchOpcode*/ 18|128,1/*146*/,  TARGET_VAL(ISD::Constant),// ->23585
/*23439*/   OPC_RecordNode,   // #0 = $imm
/*23440*/   OPC_SwitchType /*3 cases */, 46,  MVT::i32,// ->23489
/*23443*/     OPC_Scope, 14, /*->23459*/ // 2 children in Scope
/*23445*/       OPC_CheckPredicate, 58, // Predicate_anonymous.val.460
/*23447*/       OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*23449*/       OPC_EmitConvertToTarget, 0,
/*23451*/       OPC_MorphNodeTo, TARGET_VAL(AMDGPU::S_MOV_B32), 0,
                    1/*#VTs*/, MVT::i32, 1/*#Ops*/, 1, 
                // Src: (imm:i32)<<P:Predicate_anonymous.val.460>>:$imm - Complexity = 4
                // Dst: (S_MOV_B32:i32 (imm:i32):$imm)
/*23459*/     /*Scope*/ 28, /*->23488*/
/*23460*/       OPC_Scope, 12, /*->23474*/ // 2 children in Scope
/*23462*/         OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*23464*/         OPC_EmitConvertToTarget, 0,
/*23466*/         OPC_MorphNodeTo, TARGET_VAL(AMDGPU::V_MOV_B32_e32), 0,
                      1/*#VTs*/, MVT::i32, 1/*#Ops*/, 1, 
                  // Src: (imm:i32):$imm - Complexity = 3
                  // Dst: (V_MOV_B32_e32:i32 (imm:i32):$imm)
/*23474*/       /*Scope*/ 12, /*->23487*/
/*23475*/         OPC_CheckPatternPredicate, 3, // (Subtarget.getGeneration() <= AMDGPUSubtarget::NORTHERN_ISLANDS)
/*23477*/         OPC_EmitConvertToTarget, 0,
/*23479*/         OPC_MorphNodeTo, TARGET_VAL(AMDGPU::MOV_IMM_I32), 0,
                      1/*#VTs*/, MVT::i32, 1/*#Ops*/, 1, 
                  // Src: (imm:i32):$val - Complexity = 3
                  // Dst: (MOV_IMM_I32:i32 (imm:i32):$val)
/*23487*/       0, /*End of Scope*/
/*23488*/     0, /*End of Scope*/
/*23489*/   /*SwitchType*/ 79,  MVT::i64,// ->23570
/*23491*/     OPC_Scope, 14, /*->23507*/ // 2 children in Scope
/*23493*/       OPC_CheckPredicate, 59, // Predicate_anonymous.val.462
/*23495*/       OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*23497*/       OPC_EmitConvertToTarget, 0,
/*23499*/       OPC_MorphNodeTo, TARGET_VAL(AMDGPU::S_MOV_B64), 0,
                    1/*#VTs*/, MVT::i64, 1/*#Ops*/, 1, 
                // Src: (imm:i64)<<P:Predicate_anonymous.val.462>>:$imm - Complexity = 4
                // Dst: (S_MOV_B64:i64 (imm:i64)<<P:Predicate_anonymous.val.463>>:$imm)
/*23507*/     /*Scope*/ 61, /*->23569*/
/*23508*/       OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*23510*/       OPC_EmitNode, TARGET_VAL(TargetOpcode::IMPLICIT_DEF), 0,
                    1/*#VTs*/, MVT::i64, 0/*#Ops*/,  // Results = #1
/*23517*/       OPC_EmitConvertToTarget, 0,
/*23519*/       OPC_EmitNodeXForm, 4, 2, // LO32
/*23522*/       OPC_EmitNode, TARGET_VAL(AMDGPU::S_MOV_B32), 0,
                    1/*#VTs*/, MVT::i32, 1/*#Ops*/, 3,  // Results = #4
/*23530*/       OPC_EmitInteger, MVT::i32, AMDGPU::sub0,
/*23533*/       OPC_EmitNode, TARGET_VAL(TargetOpcode::INSERT_SUBREG), 0,
                    1/*#VTs*/, MVT::i64, 3/*#Ops*/, 1, 4, 5,  // Results = #6
/*23543*/       OPC_EmitConvertToTarget, 0,
/*23545*/       OPC_EmitNodeXForm, 5, 7, // HI32
/*23548*/       OPC_EmitNode, TARGET_VAL(AMDGPU::S_MOV_B32), 0,
                    1/*#VTs*/, MVT::i32, 1/*#Ops*/, 8,  // Results = #9
/*23556*/       OPC_EmitInteger, MVT::i32, AMDGPU::sub1,
/*23559*/       OPC_MorphNodeTo, TARGET_VAL(TargetOpcode::INSERT_SUBREG), 0,
                    1/*#VTs*/, MVT::i64, 3/*#Ops*/, 6, 9, 10, 
                // Src: (imm:i64):$imm - Complexity = 3
                // Dst: (INSERT_SUBREG:i64 (INSERT_SUBREG:i64 (IMPLICIT_DEF:i64), (S_MOV_B32:i32 (LO32:i32 (imm:i64):$imm)), sub0:i32), (S_MOV_B32:i32 (HI32:i32 (imm:i64):$imm)), sub1:i32)
/*23569*/     0, /*End of Scope*/
/*23570*/   /*SwitchType*/ 12,  MVT::i1,// ->23584
/*23572*/     OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*23574*/     OPC_EmitConvertToTarget, 0,
/*23576*/     OPC_MorphNodeTo, TARGET_VAL(AMDGPU::S_MOV_B64), 0,
                  1/*#VTs*/, MVT::i1, 1/*#Ops*/, 1, 
              // Src: (imm:i1):$imm - Complexity = 3
              // Dst: (S_MOV_B64:i1 (imm:i1):$imm)
/*23584*/   0, // EndSwitchType
/*23585*/ /*SwitchOpcode*/ 96,  TARGET_VAL(ISD::ATOMIC_LOAD_ADD),// ->23684
/*23588*/   OPC_RecordMemRef,
/*23589*/   OPC_RecordNode,   // #0 = 'atomic_load_add' chained node
/*23590*/   OPC_RecordChild1, // #1 = $ptr
/*23591*/   OPC_CheckChild1Type, MVT::i32,
/*23593*/   OPC_RecordChild2, // #2 = $val
/*23594*/   OPC_CheckPredicate, 60, // Predicate_atomic_load_add_local
/*23596*/   OPC_CheckType, MVT::i32,
/*23598*/   OPC_Scope, 24, /*->23624*/ // 2 children in Scope
/*23600*/     OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*23602*/     OPC_EmitMergeInputChains1_0,
/*23603*/     OPC_EmitInteger, MVT::i1, 0, 
/*23606*/     OPC_EmitInteger, MVT::i8, 0, 
/*23609*/     OPC_EmitInteger, MVT::i8, 0, 
/*23612*/     OPC_MorphNodeTo, TARGET_VAL(AMDGPU::DS_ADD_U32_RTN), 0|OPFL_Chain|OPFL_MemRefs,
                  1/*#VTs*/, MVT::i32, 5/*#Ops*/, 3, 1, 2, 4, 5, 
              // Src: (atomic_load_add:i32 i32:i32:$ptr, i32:i32:$val)<<P:Predicate_atomic_load_add_local>> - Complexity = 4
              // Dst: (DS_ADD_U32_RTN:i32 0:i1, ?:i32:$ptr, ?:i32:$val, 0:i8, 0:i8)
/*23624*/   /*Scope*/ 58, /*->23683*/
/*23625*/     OPC_CheckPatternPredicate, 2, // (Subtarget.getGeneration() == AMDGPUSubtarget::EVERGREEN|| Subtarget.getGeneration() ==AMDGPUSubtarget::NORTHERN_ISLANDS)
/*23627*/     OPC_EmitMergeInputChains1_0,
/*23628*/     OPC_EmitInteger, MVT::i32, 0, 
/*23631*/     OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*23643*/     OPC_EmitInteger, MVT::i32, 0, 
/*23646*/     OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*23658*/     OPC_EmitInteger, MVT::i32, 1, 
/*23661*/     OPC_EmitRegister, MVT::i32, AMDGPU::PRED_SEL_OFF,
/*23664*/     OPC_EmitInteger, MVT::i32, 0, 
/*23667*/     OPC_MorphNodeTo, TARGET_VAL(AMDGPU::LDS_ADD_RET), 0|OPFL_Chain|OPFL_MemRefs,
                  1/*#VTs*/, MVT::i32, 9/*#Ops*/, 1, 3, 4, 2, 5, 6, 7, 8, 9, 
              // Src: (atomic_load_add:i32 i32:i32:$src0, i32:i32:$src1)<<P:Predicate_atomic_load_add_local>> - Complexity = 4
              // Dst: (LDS_ADD_RET:i32 i32:i32:$src0, i32:i32:$src1)
/*23683*/   0, /*End of Scope*/
/*23684*/ /*SwitchOpcode*/ 96,  TARGET_VAL(ISD::ATOMIC_LOAD_SUB),// ->23783
/*23687*/   OPC_RecordMemRef,
/*23688*/   OPC_RecordNode,   // #0 = 'atomic_load_sub' chained node
/*23689*/   OPC_RecordChild1, // #1 = $ptr
/*23690*/   OPC_CheckChild1Type, MVT::i32,
/*23692*/   OPC_RecordChild2, // #2 = $val
/*23693*/   OPC_CheckPredicate, 61, // Predicate_atomic_load_sub_local
/*23695*/   OPC_CheckType, MVT::i32,
/*23697*/   OPC_Scope, 24, /*->23723*/ // 2 children in Scope
/*23699*/     OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*23701*/     OPC_EmitMergeInputChains1_0,
/*23702*/     OPC_EmitInteger, MVT::i1, 0, 
/*23705*/     OPC_EmitInteger, MVT::i8, 0, 
/*23708*/     OPC_EmitInteger, MVT::i8, 0, 
/*23711*/     OPC_MorphNodeTo, TARGET_VAL(AMDGPU::DS_SUB_U32_RTN), 0|OPFL_Chain|OPFL_MemRefs,
                  1/*#VTs*/, MVT::i32, 5/*#Ops*/, 3, 1, 2, 4, 5, 
              // Src: (atomic_load_sub:i32 i32:i32:$ptr, i32:i32:$val)<<P:Predicate_atomic_load_sub_local>> - Complexity = 4
              // Dst: (DS_SUB_U32_RTN:i32 0:i1, ?:i32:$ptr, ?:i32:$val, 0:i8, 0:i8)
/*23723*/   /*Scope*/ 58, /*->23782*/
/*23724*/     OPC_CheckPatternPredicate, 2, // (Subtarget.getGeneration() == AMDGPUSubtarget::EVERGREEN|| Subtarget.getGeneration() ==AMDGPUSubtarget::NORTHERN_ISLANDS)
/*23726*/     OPC_EmitMergeInputChains1_0,
/*23727*/     OPC_EmitInteger, MVT::i32, 0, 
/*23730*/     OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*23742*/     OPC_EmitInteger, MVT::i32, 0, 
/*23745*/     OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*23757*/     OPC_EmitInteger, MVT::i32, 1, 
/*23760*/     OPC_EmitRegister, MVT::i32, AMDGPU::PRED_SEL_OFF,
/*23763*/     OPC_EmitInteger, MVT::i32, 0, 
/*23766*/     OPC_MorphNodeTo, TARGET_VAL(AMDGPU::LDS_SUB_RET), 0|OPFL_Chain|OPFL_MemRefs,
                  1/*#VTs*/, MVT::i32, 9/*#Ops*/, 1, 3, 4, 2, 5, 6, 7, 8, 9, 
              // Src: (atomic_load_sub:i32 i32:i32:$src0, i32:i32:$src1)<<P:Predicate_atomic_load_sub_local>> - Complexity = 4
              // Dst: (LDS_SUB_RET:i32 i32:i32:$src0, i32:i32:$src1)
/*23782*/   0, /*End of Scope*/
/*23783*/ /*SwitchOpcode*/ 85|128,1/*213*/,  TARGET_VAL(ISD::BITCAST),// ->24000
/*23787*/   OPC_RecordChild0, // #0 = $src0
/*23788*/   OPC_Scope, 25, /*->23815*/ // 11 children in Scope
/*23790*/     OPC_CheckChild0Type, MVT::f32,
/*23792*/     OPC_CheckType, MVT::i32,
/*23794*/     OPC_Scope, 5, /*->23801*/ // 2 children in Scope
/*23796*/       OPC_CheckPatternPredicate, 3, // (Subtarget.getGeneration() <= AMDGPUSubtarget::NORTHERN_ISLANDS)
/*23798*/       OPC_CompleteMatch, 1, 0, 
                // Src: (bitconvert:i32 R600_Reg32:f32:$src0) - Complexity = 3
                // Dst: R600_Reg32:i32:$src0
/*23801*/     /*Scope*/ 12, /*->23814*/
/*23802*/       OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*23804*/       OPC_Scope, 3, /*->23809*/ // 2 children in Scope
/*23806*/         OPC_CompleteMatch, 1, 0, 
                  // Src: (bitconvert:i32 SReg_32:f32:$src0) - Complexity = 3
                  // Dst: SReg_32:i32:$src0
/*23809*/       /*Scope*/ 3, /*->23813*/
/*23810*/         OPC_CompleteMatch, 1, 0, 
                  // Src: (bitconvert:i32 VReg_32:f32:$src0) - Complexity = 3
                  // Dst: VReg_32:i32:$src0
/*23813*/       0, /*End of Scope*/
/*23814*/     0, /*End of Scope*/
/*23815*/   /*Scope*/ 9, /*->23825*/
/*23816*/     OPC_CheckChild0Type, MVT::f64,
/*23818*/     OPC_CheckType, MVT::i64,
/*23820*/     OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*23822*/     OPC_CompleteMatch, 1, 0, 
              // Src: (bitconvert:i64 VReg_64:f64:$src0) - Complexity = 3
              // Dst: VReg_64:i64:$src0
/*23825*/   /*Scope*/ 27, /*->23853*/
/*23826*/     OPC_CheckChild0Type, MVT::v4i32,
/*23828*/     OPC_SwitchType /*2 cases */, 5,  MVT::i128,// ->23836
/*23831*/       OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*23833*/       OPC_CompleteMatch, 1, 0, 
                // Src: (bitconvert:i128 VReg_128:v4i32:$src0) - Complexity = 3
                // Dst: VReg_128:i128:$src0
/*23836*/     /*SwitchType*/ 14,  MVT::v4f32,// ->23852
/*23838*/       OPC_Scope, 5, /*->23845*/ // 2 children in Scope
/*23840*/         OPC_CheckPatternPredicate, 3, // (Subtarget.getGeneration() <= AMDGPUSubtarget::NORTHERN_ISLANDS)
/*23842*/         OPC_CompleteMatch, 1, 0, 
                  // Src: (bitconvert:v4f32 R600_Reg128:v4i32:$src0) - Complexity = 3
                  // Dst: R600_Reg128:v4f32:$src0
/*23845*/       /*Scope*/ 5, /*->23851*/
/*23846*/         OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*23848*/         OPC_CompleteMatch, 1, 0, 
                  // Src: (bitconvert:v4f32 VReg_128:v4i32:$src0) - Complexity = 3
                  // Dst: VReg_128:v4f32:$src0
/*23851*/       0, /*End of Scope*/
/*23852*/     0, // EndSwitchType
/*23853*/   /*Scope*/ 25, /*->23879*/
/*23854*/     OPC_CheckChild0Type, MVT::i32,
/*23856*/     OPC_CheckType, MVT::f32,
/*23858*/     OPC_Scope, 5, /*->23865*/ // 2 children in Scope
/*23860*/       OPC_CheckPatternPredicate, 3, // (Subtarget.getGeneration() <= AMDGPUSubtarget::NORTHERN_ISLANDS)
/*23862*/       OPC_CompleteMatch, 1, 0, 
                // Src: (bitconvert:f32 R600_Reg32:i32:$src0) - Complexity = 3
                // Dst: R600_Reg32:f32:$src0
/*23865*/     /*Scope*/ 12, /*->23878*/
/*23866*/       OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*23868*/       OPC_Scope, 3, /*->23873*/ // 2 children in Scope
/*23870*/         OPC_CompleteMatch, 1, 0, 
                  // Src: (bitconvert:f32 SReg_32:i32:$src0) - Complexity = 3
                  // Dst: SReg_32:f32:$src0
/*23873*/       /*Scope*/ 3, /*->23877*/
/*23874*/         OPC_CompleteMatch, 1, 0, 
                  // Src: (bitconvert:f32 VReg_32:i32:$src0) - Complexity = 3
                  // Dst: VReg_32:f32:$src0
/*23877*/       0, /*End of Scope*/
/*23878*/     0, /*End of Scope*/
/*23879*/   /*Scope*/ 18, /*->23898*/
/*23880*/     OPC_CheckChild0Type, MVT::i64,
/*23882*/     OPC_SwitchType /*2 cases */, 5,  MVT::f64,// ->23890
/*23885*/       OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*23887*/       OPC_CompleteMatch, 1, 0, 
                // Src: (bitconvert:f64 VReg_64:i64:$src0) - Complexity = 3
                // Dst: VReg_64:f64:$src0
/*23890*/     /*SwitchType*/ 5,  MVT::v2i32,// ->23897
/*23892*/       OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*23894*/       OPC_CompleteMatch, 1, 0, 
                // Src: (bitconvert:v2i32 VReg_64:i64:$src0) - Complexity = 3
                // Dst: VReg_64:v2i32:$src0
/*23897*/     0, // EndSwitchType
/*23898*/   /*Scope*/ 18, /*->23917*/
/*23899*/     OPC_CheckChild0Type, MVT::v2f32,
/*23901*/     OPC_CheckType, MVT::v2i32,
/*23903*/     OPC_Scope, 5, /*->23910*/ // 2 children in Scope
/*23905*/       OPC_CheckPatternPredicate, 3, // (Subtarget.getGeneration() <= AMDGPUSubtarget::NORTHERN_ISLANDS)
/*23907*/       OPC_CompleteMatch, 1, 0, 
                // Src: (bitconvert:v2i32 R600_Reg64:v2f32:$src0) - Complexity = 3
                // Dst: R600_Reg64:v2i32:$src0
/*23910*/     /*Scope*/ 5, /*->23916*/
/*23911*/       OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*23913*/       OPC_CompleteMatch, 1, 0, 
                // Src: (bitconvert:v2i32 VReg_64:v2f32:$src0) - Complexity = 3
                // Dst: VReg_64:v2i32:$src0
/*23916*/     0, /*End of Scope*/
/*23917*/   /*Scope*/ 18, /*->23936*/
/*23918*/     OPC_CheckChild0Type, MVT::v4f32,
/*23920*/     OPC_CheckType, MVT::v4i32,
/*23922*/     OPC_Scope, 5, /*->23929*/ // 2 children in Scope
/*23924*/       OPC_CheckPatternPredicate, 3, // (Subtarget.getGeneration() <= AMDGPUSubtarget::NORTHERN_ISLANDS)
/*23926*/       OPC_CompleteMatch, 1, 0, 
                // Src: (bitconvert:v4i32 R600_Reg128:v4f32:$src0) - Complexity = 3
                // Dst: R600_Reg128:v4i32:$src0
/*23929*/     /*Scope*/ 5, /*->23935*/
/*23930*/       OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*23932*/       OPC_CompleteMatch, 1, 0, 
                // Src: (bitconvert:v4i32 VReg_128:v4f32:$src0) - Complexity = 3
                // Dst: VReg_128:v4i32:$src0
/*23935*/     0, /*End of Scope*/
/*23936*/   /*Scope*/ 9, /*->23946*/
/*23937*/     OPC_CheckChild0Type, MVT::i128,
/*23939*/     OPC_CheckType, MVT::v4i32,
/*23941*/     OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*23943*/     OPC_CompleteMatch, 1, 0, 
              // Src: (bitconvert:v4i32 VReg_128:i128:$src0) - Complexity = 3
              // Dst: VReg_128:v4i32:$src0
/*23946*/   /*Scope*/ 16, /*->23963*/
/*23947*/     OPC_CheckChild0Type, MVT::v32i8,
/*23949*/     OPC_CheckType, MVT::v8i32,
/*23951*/     OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*23953*/     OPC_Scope, 3, /*->23958*/ // 2 children in Scope
/*23955*/       OPC_CompleteMatch, 1, 0, 
                // Src: (bitconvert:v8i32 SReg_256:v32i8:$src0) - Complexity = 3
                // Dst: SReg_256:v8i32:$src0
/*23958*/     /*Scope*/ 3, /*->23962*/
/*23959*/       OPC_CompleteMatch, 1, 0, 
                // Src: (bitconvert:v8i32 VReg_256:v32i8:$src0) - Complexity = 3
                // Dst: VReg_256:v8i32:$src0
/*23962*/     0, /*End of Scope*/
/*23963*/   /*Scope*/ 16, /*->23980*/
/*23964*/     OPC_CheckChild0Type, MVT::v8i32,
/*23966*/     OPC_CheckType, MVT::v32i8,
/*23968*/     OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*23970*/     OPC_Scope, 3, /*->23975*/ // 2 children in Scope
/*23972*/       OPC_CompleteMatch, 1, 0, 
                // Src: (bitconvert:v32i8 SReg_256:v8i32:$src0) - Complexity = 3
                // Dst: SReg_256:v32i8:$src0
/*23975*/     /*Scope*/ 3, /*->23979*/
/*23976*/       OPC_CompleteMatch, 1, 0, 
                // Src: (bitconvert:v32i8 VReg_256:v8i32:$src0) - Complexity = 3
                // Dst: VReg_256:v32i8:$src0
/*23979*/     0, /*End of Scope*/
/*23980*/   /*Scope*/ 18, /*->23999*/
/*23981*/     OPC_CheckChild0Type, MVT::v2i32,
/*23983*/     OPC_CheckType, MVT::v2f32,
/*23985*/     OPC_Scope, 5, /*->23992*/ // 2 children in Scope
/*23987*/       OPC_CheckPatternPredicate, 3, // (Subtarget.getGeneration() <= AMDGPUSubtarget::NORTHERN_ISLANDS)
/*23989*/       OPC_CompleteMatch, 1, 0, 
                // Src: (bitconvert:v2f32 R600_Reg64:v2i32:$src0) - Complexity = 3
                // Dst: R600_Reg64:v2f32:$src0
/*23992*/     /*Scope*/ 5, /*->23998*/
/*23993*/       OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*23995*/       OPC_CompleteMatch, 1, 0, 
                // Src: (bitconvert:v2f32 VReg_64:v2i32:$src0) - Complexity = 3
                // Dst: VReg_64:v2f32:$src0
/*23998*/     0, /*End of Scope*/
/*23999*/   0, /*End of Scope*/
/*24000*/ /*SwitchOpcode*/ 8,  TARGET_VAL(AMDGPUISD::DWORDADDR),// ->24011
/*24003*/   OPC_RecordChild0, // #0 = $addr
/*24004*/   OPC_CheckType, MVT::i32,
/*24006*/   OPC_CheckPatternPredicate, 3, // (Subtarget.getGeneration() <= AMDGPUSubtarget::NORTHERN_ISLANDS)
/*24008*/   OPC_CompleteMatch, 1, 0, 
            // Src: (AMDGPUdwordaddr:i32 R600_Reg32:i32:$addr) - Complexity = 3
            // Dst: R600_Reg32:i32:$addr
/*24011*/ /*SwitchOpcode*/ 120,  TARGET_VAL(ISD::SUB),// ->24134
/*24014*/   OPC_RecordChild0, // #0 = $src0
/*24015*/   OPC_RecordChild1, // #1 = $src1
/*24016*/   OPC_CheckType, MVT::i32,
/*24018*/   OPC_Scope, 101, /*->24121*/ // 2 children in Scope
/*24020*/     OPC_CheckPatternPredicate, 3, // (Subtarget.getGeneration() <= AMDGPUSubtarget::NORTHERN_ISLANDS)
/*24022*/     OPC_EmitInteger, MVT::i32, 0, 
/*24025*/     OPC_EmitInteger, MVT::i32, 0, 
/*24028*/     OPC_EmitInteger, MVT::i32, 1, 
/*24031*/     OPC_EmitInteger, MVT::i32, 0, 
/*24034*/     OPC_EmitInteger, MVT::i32, 0, 
/*24037*/     OPC_EmitInteger, MVT::i32, 0, 
/*24040*/     OPC_EmitInteger, MVT::i32, 0, 
/*24043*/     OPC_EmitInteger, MVT::i32, 0, 
/*24046*/     OPC_EmitInteger, MVT::i32, 0, 
/*24049*/     OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*24061*/     OPC_EmitInteger, MVT::i32, 0, 
/*24064*/     OPC_EmitInteger, MVT::i32, 0, 
/*24067*/     OPC_EmitInteger, MVT::i32, 0, 
/*24070*/     OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*24082*/     OPC_EmitInteger, MVT::i32, 1, 
/*24085*/     OPC_EmitRegister, MVT::i32, AMDGPU::PRED_SEL_OFF,
/*24088*/     OPC_EmitInteger, MVT::i32, 0, 
/*24091*/     OPC_EmitInteger, MVT::i32, 0, 
/*24094*/     OPC_MorphNodeTo, TARGET_VAL(AMDGPU::SUB_INT), 0,
                  1/*#VTs*/, MVT::i32, 20/*#Ops*/, 2, 3, 4, 5, 6, 7, 0, 8, 9, 10, 11, 1, 12, 13, 14, 15, 16, 17, 18, 19, 
              // Src: (sub:i32 R600_Reg32:i32:$src0, R600_Reg32:i32:$src1) - Complexity = 3
              // Dst: (SUB_INT:i32 R600_Reg32:i32:$src0, R600_Reg32:i32:$src1)
/*24121*/   /*Scope*/ 11, /*->24133*/
/*24122*/     OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*24124*/     OPC_MorphNodeTo, TARGET_VAL(AMDGPU::S_SUB_I32), 0,
                  1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1, 
              // Src: (sub:i32 SSrc_32:i32:$src0, SSrc_32:i32:$src1) - Complexity = 3
              // Dst: (S_SUB_I32:i32 SSrc_32:i32:$src0, SSrc_32:i32:$src1)
/*24133*/   0, /*End of Scope*/
/*24134*/ /*SwitchOpcode*/ 120,  TARGET_VAL(AMDGPUISD::SMAX),// ->24257
/*24137*/   OPC_RecordChild0, // #0 = $src0
/*24138*/   OPC_RecordChild1, // #1 = $src1
/*24139*/   OPC_CheckType, MVT::i32,
/*24141*/   OPC_Scope, 101, /*->24244*/ // 2 children in Scope
/*24143*/     OPC_CheckPatternPredicate, 3, // (Subtarget.getGeneration() <= AMDGPUSubtarget::NORTHERN_ISLANDS)
/*24145*/     OPC_EmitInteger, MVT::i32, 0, 
/*24148*/     OPC_EmitInteger, MVT::i32, 0, 
/*24151*/     OPC_EmitInteger, MVT::i32, 1, 
/*24154*/     OPC_EmitInteger, MVT::i32, 0, 
/*24157*/     OPC_EmitInteger, MVT::i32, 0, 
/*24160*/     OPC_EmitInteger, MVT::i32, 0, 
/*24163*/     OPC_EmitInteger, MVT::i32, 0, 
/*24166*/     OPC_EmitInteger, MVT::i32, 0, 
/*24169*/     OPC_EmitInteger, MVT::i32, 0, 
/*24172*/     OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*24184*/     OPC_EmitInteger, MVT::i32, 0, 
/*24187*/     OPC_EmitInteger, MVT::i32, 0, 
/*24190*/     OPC_EmitInteger, MVT::i32, 0, 
/*24193*/     OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*24205*/     OPC_EmitInteger, MVT::i32, 1, 
/*24208*/     OPC_EmitRegister, MVT::i32, AMDGPU::PRED_SEL_OFF,
/*24211*/     OPC_EmitInteger, MVT::i32, 0, 
/*24214*/     OPC_EmitInteger, MVT::i32, 0, 
/*24217*/     OPC_MorphNodeTo, TARGET_VAL(AMDGPU::MAX_INT), 0,
                  1/*#VTs*/, MVT::i32, 20/*#Ops*/, 2, 3, 4, 5, 6, 7, 0, 8, 9, 10, 11, 1, 12, 13, 14, 15, 16, 17, 18, 19, 
              // Src: (AMDGPUsmax:i32 R600_Reg32:i32:$src0, R600_Reg32:i32:$src1) - Complexity = 3
              // Dst: (MAX_INT:i32 R600_Reg32:i32:$src0, R600_Reg32:i32:$src1)
/*24244*/   /*Scope*/ 11, /*->24256*/
/*24245*/     OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*24247*/     OPC_MorphNodeTo, TARGET_VAL(AMDGPU::V_MAX_I32_e32), 0,
                  1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1, 
              // Src: (AMDGPUsmax:i32 i32:i32:$src0, i32:i32:$src1) - Complexity = 3
              // Dst: (V_MAX_I32_e32:i32 i32:i32:$src0, i32:i32:$src1)
/*24256*/   0, /*End of Scope*/
/*24257*/ /*SwitchOpcode*/ 120,  TARGET_VAL(AMDGPUISD::SMIN),// ->24380
/*24260*/   OPC_RecordChild0, // #0 = $src0
/*24261*/   OPC_RecordChild1, // #1 = $src1
/*24262*/   OPC_CheckType, MVT::i32,
/*24264*/   OPC_Scope, 101, /*->24367*/ // 2 children in Scope
/*24266*/     OPC_CheckPatternPredicate, 3, // (Subtarget.getGeneration() <= AMDGPUSubtarget::NORTHERN_ISLANDS)
/*24268*/     OPC_EmitInteger, MVT::i32, 0, 
/*24271*/     OPC_EmitInteger, MVT::i32, 0, 
/*24274*/     OPC_EmitInteger, MVT::i32, 1, 
/*24277*/     OPC_EmitInteger, MVT::i32, 0, 
/*24280*/     OPC_EmitInteger, MVT::i32, 0, 
/*24283*/     OPC_EmitInteger, MVT::i32, 0, 
/*24286*/     OPC_EmitInteger, MVT::i32, 0, 
/*24289*/     OPC_EmitInteger, MVT::i32, 0, 
/*24292*/     OPC_EmitInteger, MVT::i32, 0, 
/*24295*/     OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*24307*/     OPC_EmitInteger, MVT::i32, 0, 
/*24310*/     OPC_EmitInteger, MVT::i32, 0, 
/*24313*/     OPC_EmitInteger, MVT::i32, 0, 
/*24316*/     OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*24328*/     OPC_EmitInteger, MVT::i32, 1, 
/*24331*/     OPC_EmitRegister, MVT::i32, AMDGPU::PRED_SEL_OFF,
/*24334*/     OPC_EmitInteger, MVT::i32, 0, 
/*24337*/     OPC_EmitInteger, MVT::i32, 0, 
/*24340*/     OPC_MorphNodeTo, TARGET_VAL(AMDGPU::MIN_INT), 0,
                  1/*#VTs*/, MVT::i32, 20/*#Ops*/, 2, 3, 4, 5, 6, 7, 0, 8, 9, 10, 11, 1, 12, 13, 14, 15, 16, 17, 18, 19, 
              // Src: (AMDGPUsmin:i32 R600_Reg32:i32:$src0, R600_Reg32:i32:$src1) - Complexity = 3
              // Dst: (MIN_INT:i32 R600_Reg32:i32:$src0, R600_Reg32:i32:$src1)
/*24367*/   /*Scope*/ 11, /*->24379*/
/*24368*/     OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*24370*/     OPC_MorphNodeTo, TARGET_VAL(AMDGPU::V_MIN_I32_e32), 0,
                  1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1, 
              // Src: (AMDGPUsmin:i32 i32:i32:$src0, i32:i32:$src1) - Complexity = 3
              // Dst: (V_MIN_I32_e32:i32 i32:i32:$src0, i32:i32:$src1)
/*24379*/   0, /*End of Scope*/
/*24380*/ /*SwitchOpcode*/ 120,  TARGET_VAL(AMDGPUISD::UMAX),// ->24503
/*24383*/   OPC_RecordChild0, // #0 = $src0
/*24384*/   OPC_RecordChild1, // #1 = $src1
/*24385*/   OPC_CheckType, MVT::i32,
/*24387*/   OPC_Scope, 101, /*->24490*/ // 2 children in Scope
/*24389*/     OPC_CheckPatternPredicate, 3, // (Subtarget.getGeneration() <= AMDGPUSubtarget::NORTHERN_ISLANDS)
/*24391*/     OPC_EmitInteger, MVT::i32, 0, 
/*24394*/     OPC_EmitInteger, MVT::i32, 0, 
/*24397*/     OPC_EmitInteger, MVT::i32, 1, 
/*24400*/     OPC_EmitInteger, MVT::i32, 0, 
/*24403*/     OPC_EmitInteger, MVT::i32, 0, 
/*24406*/     OPC_EmitInteger, MVT::i32, 0, 
/*24409*/     OPC_EmitInteger, MVT::i32, 0, 
/*24412*/     OPC_EmitInteger, MVT::i32, 0, 
/*24415*/     OPC_EmitInteger, MVT::i32, 0, 
/*24418*/     OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*24430*/     OPC_EmitInteger, MVT::i32, 0, 
/*24433*/     OPC_EmitInteger, MVT::i32, 0, 
/*24436*/     OPC_EmitInteger, MVT::i32, 0, 
/*24439*/     OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*24451*/     OPC_EmitInteger, MVT::i32, 1, 
/*24454*/     OPC_EmitRegister, MVT::i32, AMDGPU::PRED_SEL_OFF,
/*24457*/     OPC_EmitInteger, MVT::i32, 0, 
/*24460*/     OPC_EmitInteger, MVT::i32, 0, 
/*24463*/     OPC_MorphNodeTo, TARGET_VAL(AMDGPU::MAX_UINT), 0,
                  1/*#VTs*/, MVT::i32, 20/*#Ops*/, 2, 3, 4, 5, 6, 7, 0, 8, 9, 10, 11, 1, 12, 13, 14, 15, 16, 17, 18, 19, 
              // Src: (AMDGPUumax:i32 R600_Reg32:i32:$src0, R600_Reg32:i32:$src1) - Complexity = 3
              // Dst: (MAX_UINT:i32 R600_Reg32:i32:$src0, R600_Reg32:i32:$src1)
/*24490*/   /*Scope*/ 11, /*->24502*/
/*24491*/     OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*24493*/     OPC_MorphNodeTo, TARGET_VAL(AMDGPU::V_MAX_U32_e32), 0,
                  1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1, 
              // Src: (AMDGPUumax:i32 i32:i32:$src0, i32:i32:$src1) - Complexity = 3
              // Dst: (V_MAX_U32_e32:i32 i32:i32:$src0, i32:i32:$src1)
/*24502*/   0, /*End of Scope*/
/*24503*/ /*SwitchOpcode*/ 120,  TARGET_VAL(AMDGPUISD::UMIN),// ->24626
/*24506*/   OPC_RecordChild0, // #0 = $src0
/*24507*/   OPC_RecordChild1, // #1 = $src1
/*24508*/   OPC_CheckType, MVT::i32,
/*24510*/   OPC_Scope, 101, /*->24613*/ // 2 children in Scope
/*24512*/     OPC_CheckPatternPredicate, 3, // (Subtarget.getGeneration() <= AMDGPUSubtarget::NORTHERN_ISLANDS)
/*24514*/     OPC_EmitInteger, MVT::i32, 0, 
/*24517*/     OPC_EmitInteger, MVT::i32, 0, 
/*24520*/     OPC_EmitInteger, MVT::i32, 1, 
/*24523*/     OPC_EmitInteger, MVT::i32, 0, 
/*24526*/     OPC_EmitInteger, MVT::i32, 0, 
/*24529*/     OPC_EmitInteger, MVT::i32, 0, 
/*24532*/     OPC_EmitInteger, MVT::i32, 0, 
/*24535*/     OPC_EmitInteger, MVT::i32, 0, 
/*24538*/     OPC_EmitInteger, MVT::i32, 0, 
/*24541*/     OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*24553*/     OPC_EmitInteger, MVT::i32, 0, 
/*24556*/     OPC_EmitInteger, MVT::i32, 0, 
/*24559*/     OPC_EmitInteger, MVT::i32, 0, 
/*24562*/     OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*24574*/     OPC_EmitInteger, MVT::i32, 1, 
/*24577*/     OPC_EmitRegister, MVT::i32, AMDGPU::PRED_SEL_OFF,
/*24580*/     OPC_EmitInteger, MVT::i32, 0, 
/*24583*/     OPC_EmitInteger, MVT::i32, 0, 
/*24586*/     OPC_MorphNodeTo, TARGET_VAL(AMDGPU::MIN_UINT), 0,
                  1/*#VTs*/, MVT::i32, 20/*#Ops*/, 2, 3, 4, 5, 6, 7, 0, 8, 9, 10, 11, 1, 12, 13, 14, 15, 16, 17, 18, 19, 
              // Src: (AMDGPUumin:i32 R600_Reg32:i32:$src0, R600_Reg32:i32:$src1) - Complexity = 3
              // Dst: (MIN_UINT:i32 R600_Reg32:i32:$src0, R600_Reg32:i32:$src1)
/*24613*/   /*Scope*/ 11, /*->24625*/
/*24614*/     OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*24616*/     OPC_MorphNodeTo, TARGET_VAL(AMDGPU::V_MIN_U32_e32), 0,
                  1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1, 
              // Src: (AMDGPUumin:i32 i32:i32:$src0, i32:i32:$src1) - Complexity = 3
              // Dst: (V_MIN_U32_e32:i32 i32:i32:$src0, i32:i32:$src1)
/*24625*/   0, /*End of Scope*/
/*24626*/ /*SwitchOpcode*/ 109|128,1/*237*/,  TARGET_VAL(ISD::FP_TO_SINT),// ->24867
/*24630*/   OPC_RecordChild0, // #0 = $src0
/*24631*/   OPC_CheckType, MVT::i32,
/*24633*/   OPC_Scope, 89|128,1/*217*/, /*->24853*/ // 2 children in Scope
/*24636*/     OPC_CheckChild0Type, MVT::f32,
/*24638*/     OPC_Scope, 67, /*->24707*/ // 3 children in Scope
/*24640*/       OPC_CheckPatternPredicate, 1, // (Subtarget.getGeneration() <= AMDGPUSubtarget::R700)
/*24642*/       OPC_EmitInteger, MVT::i32, 1, 
/*24645*/       OPC_EmitInteger, MVT::i32, 0, 
/*24648*/       OPC_EmitInteger, MVT::i32, 0, 
/*24651*/       OPC_EmitInteger, MVT::i32, 0, 
/*24654*/       OPC_EmitInteger, MVT::i32, 0, 
/*24657*/       OPC_EmitInteger, MVT::i32, 0, 
/*24660*/       OPC_EmitInteger, MVT::i32, 0, 
/*24663*/       OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*24675*/       OPC_EmitInteger, MVT::i32, 1, 
/*24678*/       OPC_EmitRegister, MVT::i32, AMDGPU::PRED_SEL_OFF,
/*24681*/       OPC_EmitInteger, MVT::i32, 0, 
/*24684*/       OPC_EmitInteger, MVT::i32, 0, 
/*24687*/       OPC_MorphNodeTo, TARGET_VAL(AMDGPU::FLT_TO_INT_r600), 0,
                    1/*#VTs*/, MVT::i32, 13/*#Ops*/, 1, 2, 3, 4, 0, 5, 6, 7, 8, 9, 10, 11, 12, 
                // Src: (fp_to_sint:i32 R600_Reg32:f32:$src0) - Complexity = 3
                // Dst: (FLT_TO_INT_r600:i32 R600_Reg32:f32:$src0)
/*24707*/     /*Scope*/ 10, /*->24718*/
/*24708*/       OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*24710*/       OPC_MorphNodeTo, TARGET_VAL(AMDGPU::V_CVT_I32_F32_e32), 0,
                    1/*#VTs*/, MVT::i32, 1/*#Ops*/, 0, 
                // Src: (fp_to_sint:i32 f32:f32:$src0) - Complexity = 3
                // Dst: (V_CVT_I32_F32_e32:i32 f32:f32:$src0)
/*24718*/     /*Scope*/ 4|128,1/*132*/, /*->24852*/
/*24720*/       OPC_CheckPatternPredicate, 2, // (Subtarget.getGeneration() == AMDGPUSubtarget::EVERGREEN|| Subtarget.getGeneration() ==AMDGPUSubtarget::NORTHERN_ISLANDS)
/*24722*/       OPC_EmitInteger, MVT::i32, 1, 
/*24725*/       OPC_EmitInteger, MVT::i32, 0, 
/*24728*/       OPC_EmitInteger, MVT::i32, 0, 
/*24731*/       OPC_EmitInteger, MVT::i32, 0, 
/*24734*/       OPC_EmitInteger, MVT::i32, 1, 
/*24737*/       OPC_EmitInteger, MVT::i32, 0, 
/*24740*/       OPC_EmitInteger, MVT::i32, 0, 
/*24743*/       OPC_EmitInteger, MVT::i32, 0, 
/*24746*/       OPC_EmitInteger, MVT::i32, 0, 
/*24749*/       OPC_EmitInteger, MVT::i32, 0, 
/*24752*/       OPC_EmitInteger, MVT::i32, 0, 
/*24755*/       OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*24767*/       OPC_EmitInteger, MVT::i32, 1, 
/*24770*/       OPC_EmitRegister, MVT::i32, AMDGPU::PRED_SEL_OFF,
/*24773*/       OPC_EmitInteger, MVT::i32, 0, 
/*24776*/       OPC_EmitInteger, MVT::i32, 0, 
/*24779*/       OPC_EmitNode, TARGET_VAL(AMDGPU::TRUNC), 0,
                    1/*#VTs*/, MVT::i32, 13/*#Ops*/, 5, 6, 7, 8, 0, 9, 10, 11, 12, 13, 14, 15, 16,  // Results = #17
/*24799*/       OPC_EmitInteger, MVT::i32, 0, 
/*24802*/       OPC_EmitInteger, MVT::i32, 0, 
/*24805*/       OPC_EmitInteger, MVT::i32, 0, 
/*24808*/       OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*24820*/       OPC_EmitInteger, MVT::i32, 1, 
/*24823*/       OPC_EmitRegister, MVT::i32, AMDGPU::PRED_SEL_OFF,
/*24826*/       OPC_EmitInteger, MVT::i32, 0, 
/*24829*/       OPC_EmitInteger, MVT::i32, 0, 
/*24832*/       OPC_MorphNodeTo, TARGET_VAL(AMDGPU::FLT_TO_INT_eg), 0,
                    1/*#VTs*/, MVT::i32, 13/*#Ops*/, 1, 2, 3, 4, 17, 18, 19, 20, 21, 22, 23, 24, 25, 
                // Src: (fp_to_sint:i32 f32:f32:$src0) - Complexity = 3
                // Dst: (FLT_TO_INT_eg:i32 (TRUNC:i32 ?:f32:$src0))
/*24852*/     0, /*End of Scope*/
/*24853*/   /*Scope*/ 12, /*->24866*/
/*24854*/     OPC_CheckChild0Type, MVT::f64,
/*24856*/     OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*24858*/     OPC_MorphNodeTo, TARGET_VAL(AMDGPU::V_CVT_I32_F64_e32), 0,
                  1/*#VTs*/, MVT::i32, 1/*#Ops*/, 0, 
              // Src: (fp_to_sint:i32 f64:f64:$src0) - Complexity = 3
              // Dst: (V_CVT_I32_F64_e32:i32 f64:f64:$src0)
/*24866*/   0, /*End of Scope*/
/*24867*/ /*SwitchOpcode*/ 92|128,1/*220*/,  TARGET_VAL(ISD::FP_TO_UINT),// ->25091
/*24871*/   OPC_RecordChild0, // #0 = $src0
/*24872*/   OPC_CheckChild0Type, MVT::f32,
/*24874*/   OPC_CheckType, MVT::i32,
/*24876*/   OPC_Scope, 67, /*->24945*/ // 3 children in Scope
/*24878*/     OPC_CheckPatternPredicate, 1, // (Subtarget.getGeneration() <= AMDGPUSubtarget::R700)
/*24880*/     OPC_EmitInteger, MVT::i32, 1, 
/*24883*/     OPC_EmitInteger, MVT::i32, 0, 
/*24886*/     OPC_EmitInteger, MVT::i32, 0, 
/*24889*/     OPC_EmitInteger, MVT::i32, 0, 
/*24892*/     OPC_EmitInteger, MVT::i32, 0, 
/*24895*/     OPC_EmitInteger, MVT::i32, 0, 
/*24898*/     OPC_EmitInteger, MVT::i32, 0, 
/*24901*/     OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*24913*/     OPC_EmitInteger, MVT::i32, 1, 
/*24916*/     OPC_EmitRegister, MVT::i32, AMDGPU::PRED_SEL_OFF,
/*24919*/     OPC_EmitInteger, MVT::i32, 0, 
/*24922*/     OPC_EmitInteger, MVT::i32, 0, 
/*24925*/     OPC_MorphNodeTo, TARGET_VAL(AMDGPU::FLT_TO_UINT_r600), 0,
                  1/*#VTs*/, MVT::i32, 13/*#Ops*/, 1, 2, 3, 4, 0, 5, 6, 7, 8, 9, 10, 11, 12, 
              // Src: (fp_to_uint:i32 R600_Reg32:f32:$src0) - Complexity = 3
              // Dst: (FLT_TO_UINT_r600:i32 R600_Reg32:f32:$src0)
/*24945*/   /*Scope*/ 10, /*->24956*/
/*24946*/     OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*24948*/     OPC_MorphNodeTo, TARGET_VAL(AMDGPU::V_CVT_U32_F32_e32), 0,
                  1/*#VTs*/, MVT::i32, 1/*#Ops*/, 0, 
              // Src: (fp_to_uint:i32 f32:f32:$src0) - Complexity = 3
              // Dst: (V_CVT_U32_F32_e32:i32 f32:f32:$src0)
/*24956*/   /*Scope*/ 4|128,1/*132*/, /*->25090*/
/*24958*/     OPC_CheckPatternPredicate, 2, // (Subtarget.getGeneration() == AMDGPUSubtarget::EVERGREEN|| Subtarget.getGeneration() ==AMDGPUSubtarget::NORTHERN_ISLANDS)
/*24960*/     OPC_EmitInteger, MVT::i32, 1, 
/*24963*/     OPC_EmitInteger, MVT::i32, 0, 
/*24966*/     OPC_EmitInteger, MVT::i32, 0, 
/*24969*/     OPC_EmitInteger, MVT::i32, 0, 
/*24972*/     OPC_EmitInteger, MVT::i32, 1, 
/*24975*/     OPC_EmitInteger, MVT::i32, 0, 
/*24978*/     OPC_EmitInteger, MVT::i32, 0, 
/*24981*/     OPC_EmitInteger, MVT::i32, 0, 
/*24984*/     OPC_EmitInteger, MVT::i32, 0, 
/*24987*/     OPC_EmitInteger, MVT::i32, 0, 
/*24990*/     OPC_EmitInteger, MVT::i32, 0, 
/*24993*/     OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*25005*/     OPC_EmitInteger, MVT::i32, 1, 
/*25008*/     OPC_EmitRegister, MVT::i32, AMDGPU::PRED_SEL_OFF,
/*25011*/     OPC_EmitInteger, MVT::i32, 0, 
/*25014*/     OPC_EmitInteger, MVT::i32, 0, 
/*25017*/     OPC_EmitNode, TARGET_VAL(AMDGPU::TRUNC), 0,
                  1/*#VTs*/, MVT::i32, 13/*#Ops*/, 5, 6, 7, 8, 0, 9, 10, 11, 12, 13, 14, 15, 16,  // Results = #17
/*25037*/     OPC_EmitInteger, MVT::i32, 0, 
/*25040*/     OPC_EmitInteger, MVT::i32, 0, 
/*25043*/     OPC_EmitInteger, MVT::i32, 0, 
/*25046*/     OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*25058*/     OPC_EmitInteger, MVT::i32, 1, 
/*25061*/     OPC_EmitRegister, MVT::i32, AMDGPU::PRED_SEL_OFF,
/*25064*/     OPC_EmitInteger, MVT::i32, 0, 
/*25067*/     OPC_EmitInteger, MVT::i32, 0, 
/*25070*/     OPC_MorphNodeTo, TARGET_VAL(AMDGPU::FLT_TO_UINT_eg), 0,
                  1/*#VTs*/, MVT::i32, 13/*#Ops*/, 1, 2, 3, 4, 17, 18, 19, 20, 21, 22, 23, 24, 25, 
              // Src: (fp_to_uint:i32 f32:f32:$src0) - Complexity = 3
              // Dst: (FLT_TO_UINT_eg:i32 (TRUNC:i32 ?:f32:$src0))
/*25090*/   0, /*End of Scope*/
/*25091*/ /*SwitchOpcode*/ 88|128,2/*344*/,  TARGET_VAL(ISD::MULHS),// ->25439
/*25095*/   OPC_RecordChild0, // #0 = $src0
/*25096*/   OPC_RecordChild1, // #1 = $src1
/*25097*/   OPC_CheckType, MVT::i32,
/*25099*/   OPC_Scope, 101, /*->25202*/ // 4 children in Scope
/*25101*/     OPC_CheckPatternPredicate, 1, // (Subtarget.getGeneration() <= AMDGPUSubtarget::R700)
/*25103*/     OPC_EmitInteger, MVT::i32, 0, 
/*25106*/     OPC_EmitInteger, MVT::i32, 0, 
/*25109*/     OPC_EmitInteger, MVT::i32, 1, 
/*25112*/     OPC_EmitInteger, MVT::i32, 0, 
/*25115*/     OPC_EmitInteger, MVT::i32, 0, 
/*25118*/     OPC_EmitInteger, MVT::i32, 0, 
/*25121*/     OPC_EmitInteger, MVT::i32, 0, 
/*25124*/     OPC_EmitInteger, MVT::i32, 0, 
/*25127*/     OPC_EmitInteger, MVT::i32, 0, 
/*25130*/     OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*25142*/     OPC_EmitInteger, MVT::i32, 0, 
/*25145*/     OPC_EmitInteger, MVT::i32, 0, 
/*25148*/     OPC_EmitInteger, MVT::i32, 0, 
/*25151*/     OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*25163*/     OPC_EmitInteger, MVT::i32, 1, 
/*25166*/     OPC_EmitRegister, MVT::i32, AMDGPU::PRED_SEL_OFF,
/*25169*/     OPC_EmitInteger, MVT::i32, 0, 
/*25172*/     OPC_EmitInteger, MVT::i32, 0, 
/*25175*/     OPC_MorphNodeTo, TARGET_VAL(AMDGPU::MULHI_INT_r600), 0,
                  1/*#VTs*/, MVT::i32, 20/*#Ops*/, 2, 3, 4, 5, 6, 7, 0, 8, 9, 10, 11, 1, 12, 13, 14, 15, 16, 17, 18, 19, 
              // Src: (mulhs:i32 R600_Reg32:i32:$src0, R600_Reg32:i32:$src1) - Complexity = 3
              // Dst: (MULHI_INT_r600:i32 R600_Reg32:i32:$src0, R600_Reg32:i32:$src1)
/*25202*/   /*Scope*/ 101, /*->25304*/
/*25203*/     OPC_CheckPatternPredicate, 5, // (Subtarget.getGeneration() >= AMDGPUSubtarget::EVERGREEN && Subtarget.getGeneration() < AMDGPUSubtarget::SOUTHERN_ISLANDS && !Subtarget.hasCaymanISA())
/*25205*/     OPC_EmitInteger, MVT::i32, 0, 
/*25208*/     OPC_EmitInteger, MVT::i32, 0, 
/*25211*/     OPC_EmitInteger, MVT::i32, 1, 
/*25214*/     OPC_EmitInteger, MVT::i32, 0, 
/*25217*/     OPC_EmitInteger, MVT::i32, 0, 
/*25220*/     OPC_EmitInteger, MVT::i32, 0, 
/*25223*/     OPC_EmitInteger, MVT::i32, 0, 
/*25226*/     OPC_EmitInteger, MVT::i32, 0, 
/*25229*/     OPC_EmitInteger, MVT::i32, 0, 
/*25232*/     OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*25244*/     OPC_EmitInteger, MVT::i32, 0, 
/*25247*/     OPC_EmitInteger, MVT::i32, 0, 
/*25250*/     OPC_EmitInteger, MVT::i32, 0, 
/*25253*/     OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*25265*/     OPC_EmitInteger, MVT::i32, 1, 
/*25268*/     OPC_EmitRegister, MVT::i32, AMDGPU::PRED_SEL_OFF,
/*25271*/     OPC_EmitInteger, MVT::i32, 0, 
/*25274*/     OPC_EmitInteger, MVT::i32, 0, 
/*25277*/     OPC_MorphNodeTo, TARGET_VAL(AMDGPU::MULHI_INT_eg), 0,
                  1/*#VTs*/, MVT::i32, 20/*#Ops*/, 2, 3, 4, 5, 6, 7, 0, 8, 9, 10, 11, 1, 12, 13, 14, 15, 16, 17, 18, 19, 
              // Src: (mulhs:i32 R600_Reg32:i32:$src0, R600_Reg32:i32:$src1) - Complexity = 3
              // Dst: (MULHI_INT_eg:i32 R600_Reg32:i32:$src0, R600_Reg32:i32:$src1)
/*25304*/   /*Scope*/ 101, /*->25406*/
/*25305*/     OPC_CheckPatternPredicate, 4, // (Subtarget.hasCaymanISA())
/*25307*/     OPC_EmitInteger, MVT::i32, 0, 
/*25310*/     OPC_EmitInteger, MVT::i32, 0, 
/*25313*/     OPC_EmitInteger, MVT::i32, 1, 
/*25316*/     OPC_EmitInteger, MVT::i32, 0, 
/*25319*/     OPC_EmitInteger, MVT::i32, 0, 
/*25322*/     OPC_EmitInteger, MVT::i32, 0, 
/*25325*/     OPC_EmitInteger, MVT::i32, 0, 
/*25328*/     OPC_EmitInteger, MVT::i32, 0, 
/*25331*/     OPC_EmitInteger, MVT::i32, 0, 
/*25334*/     OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*25346*/     OPC_EmitInteger, MVT::i32, 0, 
/*25349*/     OPC_EmitInteger, MVT::i32, 0, 
/*25352*/     OPC_EmitInteger, MVT::i32, 0, 
/*25355*/     OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*25367*/     OPC_EmitInteger, MVT::i32, 1, 
/*25370*/     OPC_EmitRegister, MVT::i32, AMDGPU::PRED_SEL_OFF,
/*25373*/     OPC_EmitInteger, MVT::i32, 0, 
/*25376*/     OPC_EmitInteger, MVT::i32, 0, 
/*25379*/     OPC_MorphNodeTo, TARGET_VAL(AMDGPU::MULHI_INT_cm), 0,
                  1/*#VTs*/, MVT::i32, 20/*#Ops*/, 2, 3, 4, 5, 6, 7, 0, 8, 9, 10, 11, 1, 12, 13, 14, 15, 16, 17, 18, 19, 
              // Src: (mulhs:i32 R600_Reg32:i32:$src0, R600_Reg32:i32:$src1) - Complexity = 3
              // Dst: (MULHI_INT_cm:i32 R600_Reg32:i32:$src0, R600_Reg32:i32:$src1)
/*25406*/   /*Scope*/ 31, /*->25438*/
/*25407*/     OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*25409*/     OPC_EmitInteger, MVT::i32, 0, 
/*25412*/     OPC_EmitInteger, MVT::i32, 0, 
/*25415*/     OPC_EmitInteger, MVT::i32, 0, 
/*25418*/     OPC_EmitInteger, MVT::i32, 0, 
/*25421*/     OPC_EmitInteger, MVT::i32, 0, 
/*25424*/     OPC_MorphNodeTo, TARGET_VAL(AMDGPU::V_MUL_HI_I32), 0,
                  1/*#VTs*/, MVT::i32, 7/*#Ops*/, 0, 1, 2, 3, 4, 5, 6, 
              // Src: (mulhs:i32 i32:i32:$src0, i32:i32:$src1) - Complexity = 3
              // Dst: (V_MUL_HI_I32:i32 ?:i32:$src0, ?:i32:$src1, 0:i32)
/*25438*/   0, /*End of Scope*/
/*25439*/ /*SwitchOpcode*/ 88|128,2/*344*/,  TARGET_VAL(ISD::MULHU),// ->25787
/*25443*/   OPC_RecordChild0, // #0 = $src0
/*25444*/   OPC_RecordChild1, // #1 = $src1
/*25445*/   OPC_CheckType, MVT::i32,
/*25447*/   OPC_Scope, 101, /*->25550*/ // 4 children in Scope
/*25449*/     OPC_CheckPatternPredicate, 1, // (Subtarget.getGeneration() <= AMDGPUSubtarget::R700)
/*25451*/     OPC_EmitInteger, MVT::i32, 0, 
/*25454*/     OPC_EmitInteger, MVT::i32, 0, 
/*25457*/     OPC_EmitInteger, MVT::i32, 1, 
/*25460*/     OPC_EmitInteger, MVT::i32, 0, 
/*25463*/     OPC_EmitInteger, MVT::i32, 0, 
/*25466*/     OPC_EmitInteger, MVT::i32, 0, 
/*25469*/     OPC_EmitInteger, MVT::i32, 0, 
/*25472*/     OPC_EmitInteger, MVT::i32, 0, 
/*25475*/     OPC_EmitInteger, MVT::i32, 0, 
/*25478*/     OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*25490*/     OPC_EmitInteger, MVT::i32, 0, 
/*25493*/     OPC_EmitInteger, MVT::i32, 0, 
/*25496*/     OPC_EmitInteger, MVT::i32, 0, 
/*25499*/     OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*25511*/     OPC_EmitInteger, MVT::i32, 1, 
/*25514*/     OPC_EmitRegister, MVT::i32, AMDGPU::PRED_SEL_OFF,
/*25517*/     OPC_EmitInteger, MVT::i32, 0, 
/*25520*/     OPC_EmitInteger, MVT::i32, 0, 
/*25523*/     OPC_MorphNodeTo, TARGET_VAL(AMDGPU::MULHI_UINT_r600), 0,
                  1/*#VTs*/, MVT::i32, 20/*#Ops*/, 2, 3, 4, 5, 6, 7, 0, 8, 9, 10, 11, 1, 12, 13, 14, 15, 16, 17, 18, 19, 
              // Src: (mulhu:i32 R600_Reg32:i32:$src0, R600_Reg32:i32:$src1) - Complexity = 3
              // Dst: (MULHI_UINT_r600:i32 R600_Reg32:i32:$src0, R600_Reg32:i32:$src1)
/*25550*/   /*Scope*/ 101, /*->25652*/
/*25551*/     OPC_CheckPatternPredicate, 5, // (Subtarget.getGeneration() >= AMDGPUSubtarget::EVERGREEN && Subtarget.getGeneration() < AMDGPUSubtarget::SOUTHERN_ISLANDS && !Subtarget.hasCaymanISA())
/*25553*/     OPC_EmitInteger, MVT::i32, 0, 
/*25556*/     OPC_EmitInteger, MVT::i32, 0, 
/*25559*/     OPC_EmitInteger, MVT::i32, 1, 
/*25562*/     OPC_EmitInteger, MVT::i32, 0, 
/*25565*/     OPC_EmitInteger, MVT::i32, 0, 
/*25568*/     OPC_EmitInteger, MVT::i32, 0, 
/*25571*/     OPC_EmitInteger, MVT::i32, 0, 
/*25574*/     OPC_EmitInteger, MVT::i32, 0, 
/*25577*/     OPC_EmitInteger, MVT::i32, 0, 
/*25580*/     OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*25592*/     OPC_EmitInteger, MVT::i32, 0, 
/*25595*/     OPC_EmitInteger, MVT::i32, 0, 
/*25598*/     OPC_EmitInteger, MVT::i32, 0, 
/*25601*/     OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*25613*/     OPC_EmitInteger, MVT::i32, 1, 
/*25616*/     OPC_EmitRegister, MVT::i32, AMDGPU::PRED_SEL_OFF,
/*25619*/     OPC_EmitInteger, MVT::i32, 0, 
/*25622*/     OPC_EmitInteger, MVT::i32, 0, 
/*25625*/     OPC_MorphNodeTo, TARGET_VAL(AMDGPU::MULHI_UINT_eg), 0,
                  1/*#VTs*/, MVT::i32, 20/*#Ops*/, 2, 3, 4, 5, 6, 7, 0, 8, 9, 10, 11, 1, 12, 13, 14, 15, 16, 17, 18, 19, 
              // Src: (mulhu:i32 R600_Reg32:i32:$src0, R600_Reg32:i32:$src1) - Complexity = 3
              // Dst: (MULHI_UINT_eg:i32 R600_Reg32:i32:$src0, R600_Reg32:i32:$src1)
/*25652*/   /*Scope*/ 101, /*->25754*/
/*25653*/     OPC_CheckPatternPredicate, 4, // (Subtarget.hasCaymanISA())
/*25655*/     OPC_EmitInteger, MVT::i32, 0, 
/*25658*/     OPC_EmitInteger, MVT::i32, 0, 
/*25661*/     OPC_EmitInteger, MVT::i32, 1, 
/*25664*/     OPC_EmitInteger, MVT::i32, 0, 
/*25667*/     OPC_EmitInteger, MVT::i32, 0, 
/*25670*/     OPC_EmitInteger, MVT::i32, 0, 
/*25673*/     OPC_EmitInteger, MVT::i32, 0, 
/*25676*/     OPC_EmitInteger, MVT::i32, 0, 
/*25679*/     OPC_EmitInteger, MVT::i32, 0, 
/*25682*/     OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*25694*/     OPC_EmitInteger, MVT::i32, 0, 
/*25697*/     OPC_EmitInteger, MVT::i32, 0, 
/*25700*/     OPC_EmitInteger, MVT::i32, 0, 
/*25703*/     OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*25715*/     OPC_EmitInteger, MVT::i32, 1, 
/*25718*/     OPC_EmitRegister, MVT::i32, AMDGPU::PRED_SEL_OFF,
/*25721*/     OPC_EmitInteger, MVT::i32, 0, 
/*25724*/     OPC_EmitInteger, MVT::i32, 0, 
/*25727*/     OPC_MorphNodeTo, TARGET_VAL(AMDGPU::MULHI_UINT_cm), 0,
                  1/*#VTs*/, MVT::i32, 20/*#Ops*/, 2, 3, 4, 5, 6, 7, 0, 8, 9, 10, 11, 1, 12, 13, 14, 15, 16, 17, 18, 19, 
              // Src: (mulhu:i32 R600_Reg32:i32:$src0, R600_Reg32:i32:$src1) - Complexity = 3
              // Dst: (MULHI_UINT_cm:i32 R600_Reg32:i32:$src0, R600_Reg32:i32:$src1)
/*25754*/   /*Scope*/ 31, /*->25786*/
/*25755*/     OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*25757*/     OPC_EmitInteger, MVT::i32, 0, 
/*25760*/     OPC_EmitInteger, MVT::i32, 0, 
/*25763*/     OPC_EmitInteger, MVT::i32, 0, 
/*25766*/     OPC_EmitInteger, MVT::i32, 0, 
/*25769*/     OPC_EmitInteger, MVT::i32, 0, 
/*25772*/     OPC_MorphNodeTo, TARGET_VAL(AMDGPU::V_MUL_HI_U32), 0,
                  1/*#VTs*/, MVT::i32, 7/*#Ops*/, 0, 1, 2, 3, 4, 5, 6, 
              // Src: (mulhu:i32 i32:i32:$src0, i32:i32:$src1) - Complexity = 3
              // Dst: (V_MUL_HI_U32:i32 ?:i32:$src0, ?:i32:$src1, 0:i32)
/*25786*/   0, /*End of Scope*/
/*25787*/ /*SwitchOpcode*/ 113|128,3/*497*/,  TARGET_VAL(AMDGPUISD::URECIP),// ->26288
/*25791*/   OPC_RecordChild0, // #0 = $src0
/*25792*/   OPC_CheckType, MVT::i32,
/*25794*/   OPC_Scope, 67, /*->25863*/ // 4 children in Scope
/*25796*/     OPC_CheckPatternPredicate, 1, // (Subtarget.getGeneration() <= AMDGPUSubtarget::R700)
/*25798*/     OPC_EmitInteger, MVT::i32, 1, 
/*25801*/     OPC_EmitInteger, MVT::i32, 0, 
/*25804*/     OPC_EmitInteger, MVT::i32, 0, 
/*25807*/     OPC_EmitInteger, MVT::i32, 0, 
/*25810*/     OPC_EmitInteger, MVT::i32, 0, 
/*25813*/     OPC_EmitInteger, MVT::i32, 0, 
/*25816*/     OPC_EmitInteger, MVT::i32, 0, 
/*25819*/     OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*25831*/     OPC_EmitInteger, MVT::i32, 1, 
/*25834*/     OPC_EmitRegister, MVT::i32, AMDGPU::PRED_SEL_OFF,
/*25837*/     OPC_EmitInteger, MVT::i32, 0, 
/*25840*/     OPC_EmitInteger, MVT::i32, 0, 
/*25843*/     OPC_MorphNodeTo, TARGET_VAL(AMDGPU::RECIP_UINT_r600), 0,
                  1/*#VTs*/, MVT::i32, 13/*#Ops*/, 1, 2, 3, 4, 0, 5, 6, 7, 8, 9, 10, 11, 12, 
              // Src: (AMDGPUurecip:i32 R600_Reg32:i32:$src0) - Complexity = 3
              // Dst: (RECIP_UINT_r600:i32 R600_Reg32:i32:$src0)
/*25863*/   /*Scope*/ 67, /*->25931*/
/*25864*/     OPC_CheckPatternPredicate, 5, // (Subtarget.getGeneration() >= AMDGPUSubtarget::EVERGREEN && Subtarget.getGeneration() < AMDGPUSubtarget::SOUTHERN_ISLANDS && !Subtarget.hasCaymanISA())
/*25866*/     OPC_EmitInteger, MVT::i32, 1, 
/*25869*/     OPC_EmitInteger, MVT::i32, 0, 
/*25872*/     OPC_EmitInteger, MVT::i32, 0, 
/*25875*/     OPC_EmitInteger, MVT::i32, 0, 
/*25878*/     OPC_EmitInteger, MVT::i32, 0, 
/*25881*/     OPC_EmitInteger, MVT::i32, 0, 
/*25884*/     OPC_EmitInteger, MVT::i32, 0, 
/*25887*/     OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*25899*/     OPC_EmitInteger, MVT::i32, 1, 
/*25902*/     OPC_EmitRegister, MVT::i32, AMDGPU::PRED_SEL_OFF,
/*25905*/     OPC_EmitInteger, MVT::i32, 0, 
/*25908*/     OPC_EmitInteger, MVT::i32, 0, 
/*25911*/     OPC_MorphNodeTo, TARGET_VAL(AMDGPU::RECIP_UINT_eg), 0,
                  1/*#VTs*/, MVT::i32, 13/*#Ops*/, 1, 2, 3, 4, 0, 5, 6, 7, 8, 9, 10, 11, 12, 
              // Src: (AMDGPUurecip:i32 R600_Reg32:i32:$src0) - Complexity = 3
              // Dst: (RECIP_UINT_eg:i32 R600_Reg32:i32:$src0)
/*25931*/   /*Scope*/ 42, /*->25974*/
/*25932*/     OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*25934*/     OPC_EmitInteger, MVT::i32, 0|128,0|128,0|128,124|128,4/*1333788672*/, 
/*25941*/     OPC_EmitNode, TARGET_VAL(AMDGPU::V_CVT_F32_U32_e32), 0,
                  1/*#VTs*/, MVT::i32, 1/*#Ops*/, 0,  // Results = #2
/*25949*/     OPC_EmitNode, TARGET_VAL(AMDGPU::V_RCP_IFLAG_F32_e32), 0,
                  1/*#VTs*/, MVT::i32, 1/*#Ops*/, 2,  // Results = #3
/*25957*/     OPC_EmitNode, TARGET_VAL(AMDGPU::V_MUL_F32_e32), 0,
                  1/*#VTs*/, MVT::i32, 2/*#Ops*/, 1, 3,  // Results = #4
/*25966*/     OPC_MorphNodeTo, TARGET_VAL(AMDGPU::V_CVT_U32_F32_e32), 0,
                  1/*#VTs*/, MVT::i32, 1/*#Ops*/, 4, 
              // Src: (AMDGPUurecip:i32 i32:i32:$src0) - Complexity = 3
              // Dst: (V_CVT_U32_F32_e32:i32 (V_MUL_F32_e32:i32 1333788672:i32, (V_RCP_IFLAG_F32_e32:i32 (V_CVT_F32_U32_e32:i32 ?:i32:$src0))))
/*25974*/   /*Scope*/ 55|128,2/*311*/, /*->26287*/
/*25976*/     OPC_CheckPatternPredicate, 4, // (Subtarget.hasCaymanISA())
/*25978*/     OPC_EmitInteger, MVT::i32, 1, 
/*25981*/     OPC_EmitInteger, MVT::i32, 0, 
/*25984*/     OPC_EmitInteger, MVT::i32, 0, 
/*25987*/     OPC_EmitInteger, MVT::i32, 0, 
/*25990*/     OPC_EmitInteger, MVT::i32, 0, 
/*25993*/     OPC_EmitInteger, MVT::i32, 0, 
/*25996*/     OPC_EmitInteger, MVT::i32, 1, 
/*25999*/     OPC_EmitInteger, MVT::i32, 0, 
/*26002*/     OPC_EmitInteger, MVT::i32, 0, 
/*26005*/     OPC_EmitInteger, MVT::i32, 0, 
/*26008*/     OPC_EmitInteger, MVT::i32, 1, 
/*26011*/     OPC_EmitInteger, MVT::i32, 0, 
/*26014*/     OPC_EmitInteger, MVT::i32, 0, 
/*26017*/     OPC_EmitInteger, MVT::i32, 0, 
/*26020*/     OPC_EmitInteger, MVT::i32, 1, 
/*26023*/     OPC_EmitInteger, MVT::i32, 0, 
/*26026*/     OPC_EmitInteger, MVT::i32, 0, 
/*26029*/     OPC_EmitInteger, MVT::i32, 0, 
/*26032*/     OPC_EmitInteger, MVT::i32, 0, 
/*26035*/     OPC_EmitInteger, MVT::i32, 0, 
/*26038*/     OPC_EmitInteger, MVT::i32, 0, 
/*26041*/     OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*26053*/     OPC_EmitInteger, MVT::i32, 1, 
/*26056*/     OPC_EmitRegister, MVT::i32, AMDGPU::PRED_SEL_OFF,
/*26059*/     OPC_EmitInteger, MVT::i32, 0, 
/*26062*/     OPC_EmitInteger, MVT::i32, 0, 
/*26065*/     OPC_EmitNode, TARGET_VAL(AMDGPU::UINT_TO_FLT_eg), 0,
                  1/*#VTs*/, MVT::i32, 13/*#Ops*/, 15, 16, 17, 18, 0, 19, 20, 21, 22, 23, 24, 25, 26,  // Results = #27
/*26085*/     OPC_EmitInteger, MVT::i32, 0, 
/*26088*/     OPC_EmitInteger, MVT::i32, 0, 
/*26091*/     OPC_EmitInteger, MVT::i32, 0, 
/*26094*/     OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*26106*/     OPC_EmitInteger, MVT::i32, 1, 
/*26109*/     OPC_EmitRegister, MVT::i32, AMDGPU::PRED_SEL_OFF,
/*26112*/     OPC_EmitInteger, MVT::i32, 0, 
/*26115*/     OPC_EmitInteger, MVT::i32, 0, 
/*26118*/     OPC_EmitNode, TARGET_VAL(AMDGPU::RECIP_IEEE_cm), 0,
                  1/*#VTs*/, MVT::i32, 13/*#Ops*/, 11, 12, 13, 14, 27, 28, 29, 30, 31, 32, 33, 34, 35,  // Results = #36
/*26138*/     OPC_EmitInteger, MVT::i32, 0, 
/*26141*/     OPC_EmitInteger, MVT::i32, 0, 
/*26144*/     OPC_EmitInteger, MVT::i32, 0, 
/*26147*/     OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*26159*/     OPC_EmitInteger, MVT::i32, 0|128,0|128,0|128,124|128,4/*1333788672*/, 
/*26166*/     OPC_EmitNode, TARGET_VAL(AMDGPU::MOV_IMM_I32), 0,
                  1/*#VTs*/, MVT::i32, 1/*#Ops*/, 41,  // Results = #42
/*26174*/     OPC_EmitInteger, MVT::i32, 0, 
/*26177*/     OPC_EmitInteger, MVT::i32, 0, 
/*26180*/     OPC_EmitInteger, MVT::i32, 0, 
/*26183*/     OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*26195*/     OPC_EmitInteger, MVT::i32, 1, 
/*26198*/     OPC_EmitRegister, MVT::i32, AMDGPU::PRED_SEL_OFF,
/*26201*/     OPC_EmitInteger, MVT::i32, 0, 
/*26204*/     OPC_EmitInteger, MVT::i32, 0, 
/*26207*/     OPC_EmitNode, TARGET_VAL(AMDGPU::MUL_IEEE), 0,
                  1/*#VTs*/, MVT::i32, 20/*#Ops*/, 5, 6, 7, 8, 9, 10, 36, 37, 38, 39, 40, 42, 43, 44, 45, 46, 47, 48, 49, 50,  // Results = #51
/*26234*/     OPC_EmitInteger, MVT::i32, 0, 
/*26237*/     OPC_EmitInteger, MVT::i32, 0, 
/*26240*/     OPC_EmitInteger, MVT::i32, 0, 
/*26243*/     OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*26255*/     OPC_EmitInteger, MVT::i32, 1, 
/*26258*/     OPC_EmitRegister, MVT::i32, AMDGPU::PRED_SEL_OFF,
/*26261*/     OPC_EmitInteger, MVT::i32, 0, 
/*26264*/     OPC_EmitInteger, MVT::i32, 0, 
/*26267*/     OPC_MorphNodeTo, TARGET_VAL(AMDGPU::FLT_TO_UINT_eg), 0,
                  1/*#VTs*/, MVT::i32, 13/*#Ops*/, 1, 2, 3, 4, 51, 52, 53, 54, 55, 56, 57, 58, 59, 
              // Src: (AMDGPUurecip:i32 i32:i32:$src0) - Complexity = 3
              // Dst: (FLT_TO_UINT_eg:i32 (MUL_IEEE:i32 (RECIP_IEEE_cm:i32 (UINT_TO_FLT_eg:i32 ?:i32:$src0)), (MOV_IMM_I32:i32 1333788672:i32)))
/*26287*/   0, /*End of Scope*/
/*26288*/ /*SwitchOpcode*/ 9|128,1/*137*/,  TARGET_VAL(ISD::ROTR),// ->26429
/*26292*/   OPC_RecordChild0, // #0 = $src0
/*26293*/   OPC_RecordChild1, // #1 = $src1
/*26294*/   OPC_CheckChild1Type, MVT::i32,
/*26296*/   OPC_CheckType, MVT::i32,
/*26298*/   OPC_Scope, 99, /*->26399*/ // 2 children in Scope
/*26300*/     OPC_CheckPatternPredicate, 2, // (Subtarget.getGeneration() == AMDGPUSubtarget::EVERGREEN|| Subtarget.getGeneration() ==AMDGPUSubtarget::NORTHERN_ISLANDS)
/*26302*/     OPC_EmitInteger, MVT::i32, 0, 
/*26305*/     OPC_EmitInteger, MVT::i32, 0, 
/*26308*/     OPC_EmitInteger, MVT::i32, 0, 
/*26311*/     OPC_EmitInteger, MVT::i32, 0, 
/*26314*/     OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*26326*/     OPC_EmitInteger, MVT::i32, 0, 
/*26329*/     OPC_EmitInteger, MVT::i32, 0, 
/*26332*/     OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*26344*/     OPC_EmitInteger, MVT::i32, 0, 
/*26347*/     OPC_EmitInteger, MVT::i32, 0, 
/*26350*/     OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*26362*/     OPC_EmitInteger, MVT::i32, 1, 
/*26365*/     OPC_EmitRegister, MVT::i32, AMDGPU::PRED_SEL_OFF,
/*26368*/     OPC_EmitInteger, MVT::i32, 0, 
/*26371*/     OPC_EmitInteger, MVT::i32, 0, 
/*26374*/     OPC_MorphNodeTo, TARGET_VAL(AMDGPU::BIT_ALIGN_INT_eg), 0,
                  1/*#VTs*/, MVT::i32, 18/*#Ops*/, 2, 3, 0, 4, 5, 6, 0, 7, 8, 9, 1, 10, 11, 12, 13, 14, 15, 16, 
              // Src: (rotr:i32 i32:i32:$src0, i32:i32:$src1) - Complexity = 3
              // Dst: (BIT_ALIGN_INT_eg:i32 ?:i32:$src0, ?:i32:$src0, ?:i32:$src1)
/*26399*/   /*Scope*/ 28, /*->26428*/
/*26400*/     OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*26402*/     OPC_EmitInteger, MVT::i32, 0, 
/*26405*/     OPC_EmitInteger, MVT::i32, 0, 
/*26408*/     OPC_EmitInteger, MVT::i32, 0, 
/*26411*/     OPC_EmitInteger, MVT::i32, 0, 
/*26414*/     OPC_MorphNodeTo, TARGET_VAL(AMDGPU::V_ALIGNBIT_B32), 0,
                  1/*#VTs*/, MVT::i32, 7/*#Ops*/, 0, 0, 1, 2, 3, 4, 5, 
              // Src: (rotr:i32 i32:i32:$src0, i32:i32:$src1) - Complexity = 3
              // Dst: (V_ALIGNBIT_B32:i32 ?:i32:$src0, ?:i32:$src0, ?:i32:$src1)
/*26428*/   0, /*End of Scope*/
/*26429*/ /*SwitchOpcode*/ 33|128,11/*1441*/,  TARGET_VAL(ISD::SETCC),// ->27874
/*26433*/   OPC_RecordChild0, // #0 = $src0
/*26434*/   OPC_Scope, 88|128,2/*344*/, /*->26781*/ // 4 children in Scope
/*26437*/     OPC_CheckChild0Type, MVT::f32,
/*26439*/     OPC_RecordChild1, // #1 = $src1
/*26440*/     OPC_MoveChild, 2,
/*26442*/     OPC_Scope, 13|128,2/*269*/, /*->26714*/ // 3 children in Scope
/*26445*/       OPC_CheckOpcode, TARGET_VAL(ISD::CONDCODE),
/*26448*/       OPC_Scope, 32, /*->26482*/ // 8 children in Scope
/*26450*/         OPC_CheckPredicate, 62, // Predicate_COND_OLT
/*26452*/         OPC_MoveParent,
/*26453*/         OPC_CheckType, MVT::i1,
/*26455*/         OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*26457*/         OPC_EmitInteger, MVT::i32, 0, 
/*26460*/         OPC_EmitInteger, MVT::i32, 0, 
/*26463*/         OPC_EmitInteger, MVT::i32, 0, 
/*26466*/         OPC_EmitInteger, MVT::i32, 0, 
/*26469*/         OPC_MorphNodeTo, TARGET_VAL(AMDGPU::V_CMP_LT_F32_e64), 0,
                      1/*#VTs*/, MVT::i1, 6/*#Ops*/, 0, 1, 2, 3, 4, 5, 
                  // Src: (setcc:i1 VSrc_32:f32:$src0, VSrc_32:f32:$src1, (cond:Other)<<P:Predicate_COND_OLT>>) - Complexity = 3
                  // Dst: (V_CMP_LT_F32_e64:i1 VSrc_32:f32:$src0, VSrc_32:f32:$src1)
/*26482*/       /*Scope*/ 32, /*->26515*/
/*26483*/         OPC_CheckPredicate, 2, // Predicate_COND_OEQ
/*26485*/         OPC_MoveParent,
/*26486*/         OPC_CheckType, MVT::i1,
/*26488*/         OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*26490*/         OPC_EmitInteger, MVT::i32, 0, 
/*26493*/         OPC_EmitInteger, MVT::i32, 0, 
/*26496*/         OPC_EmitInteger, MVT::i32, 0, 
/*26499*/         OPC_EmitInteger, MVT::i32, 0, 
/*26502*/         OPC_MorphNodeTo, TARGET_VAL(AMDGPU::V_CMP_EQ_F32_e64), 0,
                      1/*#VTs*/, MVT::i1, 6/*#Ops*/, 0, 1, 2, 3, 4, 5, 
                  // Src: (setcc:i1 VSrc_32:f32:$src0, VSrc_32:f32:$src1, (cond:Other)<<P:Predicate_COND_OEQ>>) - Complexity = 3
                  // Dst: (V_CMP_EQ_F32_e64:i1 VSrc_32:f32:$src0, VSrc_32:f32:$src1)
/*26515*/       /*Scope*/ 32, /*->26548*/
/*26516*/         OPC_CheckPredicate, 63, // Predicate_COND_OLE
/*26518*/         OPC_MoveParent,
/*26519*/         OPC_CheckType, MVT::i1,
/*26521*/         OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*26523*/         OPC_EmitInteger, MVT::i32, 0, 
/*26526*/         OPC_EmitInteger, MVT::i32, 0, 
/*26529*/         OPC_EmitInteger, MVT::i32, 0, 
/*26532*/         OPC_EmitInteger, MVT::i32, 0, 
/*26535*/         OPC_MorphNodeTo, TARGET_VAL(AMDGPU::V_CMP_LE_F32_e64), 0,
                      1/*#VTs*/, MVT::i1, 6/*#Ops*/, 0, 1, 2, 3, 4, 5, 
                  // Src: (setcc:i1 VSrc_32:f32:$src0, VSrc_32:f32:$src1, (cond:Other)<<P:Predicate_COND_OLE>>) - Complexity = 3
                  // Dst: (V_CMP_LE_F32_e64:i1 VSrc_32:f32:$src0, VSrc_32:f32:$src1)
/*26548*/       /*Scope*/ 32, /*->26581*/
/*26549*/         OPC_CheckPredicate, 3, // Predicate_COND_OGT
/*26551*/         OPC_MoveParent,
/*26552*/         OPC_CheckType, MVT::i1,
/*26554*/         OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*26556*/         OPC_EmitInteger, MVT::i32, 0, 
/*26559*/         OPC_EmitInteger, MVT::i32, 0, 
/*26562*/         OPC_EmitInteger, MVT::i32, 0, 
/*26565*/         OPC_EmitInteger, MVT::i32, 0, 
/*26568*/         OPC_MorphNodeTo, TARGET_VAL(AMDGPU::V_CMP_GT_F32_e64), 0,
                      1/*#VTs*/, MVT::i1, 6/*#Ops*/, 0, 1, 2, 3, 4, 5, 
                  // Src: (setcc:i1 VSrc_32:f32:$src0, VSrc_32:f32:$src1, (cond:Other)<<P:Predicate_COND_OGT>>) - Complexity = 3
                  // Dst: (V_CMP_GT_F32_e64:i1 VSrc_32:f32:$src0, VSrc_32:f32:$src1)
/*26581*/       /*Scope*/ 32, /*->26614*/
/*26582*/         OPC_CheckPredicate, 4, // Predicate_COND_OGE
/*26584*/         OPC_MoveParent,
/*26585*/         OPC_CheckType, MVT::i1,
/*26587*/         OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*26589*/         OPC_EmitInteger, MVT::i32, 0, 
/*26592*/         OPC_EmitInteger, MVT::i32, 0, 
/*26595*/         OPC_EmitInteger, MVT::i32, 0, 
/*26598*/         OPC_EmitInteger, MVT::i32, 0, 
/*26601*/         OPC_MorphNodeTo, TARGET_VAL(AMDGPU::V_CMP_GE_F32_e64), 0,
                      1/*#VTs*/, MVT::i1, 6/*#Ops*/, 0, 1, 2, 3, 4, 5, 
                  // Src: (setcc:i1 VSrc_32:f32:$src0, VSrc_32:f32:$src1, (cond:Other)<<P:Predicate_COND_OGE>>) - Complexity = 3
                  // Dst: (V_CMP_GE_F32_e64:i1 VSrc_32:f32:$src0, VSrc_32:f32:$src1)
/*26614*/       /*Scope*/ 32, /*->26647*/
/*26615*/         OPC_CheckPredicate, 64, // Predicate_COND_O
/*26617*/         OPC_MoveParent,
/*26618*/         OPC_CheckType, MVT::i1,
/*26620*/         OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*26622*/         OPC_EmitInteger, MVT::i32, 0, 
/*26625*/         OPC_EmitInteger, MVT::i32, 0, 
/*26628*/         OPC_EmitInteger, MVT::i32, 0, 
/*26631*/         OPC_EmitInteger, MVT::i32, 0, 
/*26634*/         OPC_MorphNodeTo, TARGET_VAL(AMDGPU::V_CMP_O_F32_e64), 0,
                      1/*#VTs*/, MVT::i1, 6/*#Ops*/, 0, 1, 2, 3, 4, 5, 
                  // Src: (setcc:i1 VSrc_32:f32:$src0, VSrc_32:f32:$src1, (cond:Other)<<P:Predicate_COND_O>>) - Complexity = 3
                  // Dst: (V_CMP_O_F32_e64:i1 VSrc_32:f32:$src0, VSrc_32:f32:$src1)
/*26647*/       /*Scope*/ 32, /*->26680*/
/*26648*/         OPC_CheckPredicate, 65, // Predicate_COND_UO
/*26650*/         OPC_MoveParent,
/*26651*/         OPC_CheckType, MVT::i1,
/*26653*/         OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*26655*/         OPC_EmitInteger, MVT::i32, 0, 
/*26658*/         OPC_EmitInteger, MVT::i32, 0, 
/*26661*/         OPC_EmitInteger, MVT::i32, 0, 
/*26664*/         OPC_EmitInteger, MVT::i32, 0, 
/*26667*/         OPC_MorphNodeTo, TARGET_VAL(AMDGPU::V_CMP_U_F32_e64), 0,
                      1/*#VTs*/, MVT::i1, 6/*#Ops*/, 0, 1, 2, 3, 4, 5, 
                  // Src: (setcc:i1 VSrc_32:f32:$src0, VSrc_32:f32:$src1, (cond:Other)<<P:Predicate_COND_UO>>) - Complexity = 3
                  // Dst: (V_CMP_U_F32_e64:i1 VSrc_32:f32:$src0, VSrc_32:f32:$src1)
/*26680*/       /*Scope*/ 32, /*->26713*/
/*26681*/         OPC_CheckPredicate, 5, // Predicate_COND_UNE
/*26683*/         OPC_MoveParent,
/*26684*/         OPC_CheckType, MVT::i1,
/*26686*/         OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*26688*/         OPC_EmitInteger, MVT::i32, 0, 
/*26691*/         OPC_EmitInteger, MVT::i32, 0, 
/*26694*/         OPC_EmitInteger, MVT::i32, 0, 
/*26697*/         OPC_EmitInteger, MVT::i32, 0, 
/*26700*/         OPC_MorphNodeTo, TARGET_VAL(AMDGPU::V_CMP_NEQ_F32_e64), 0,
                      1/*#VTs*/, MVT::i1, 6/*#Ops*/, 0, 1, 2, 3, 4, 5, 
                  // Src: (setcc:i1 VSrc_32:f32:$src0, VSrc_32:f32:$src1, (cond:Other)<<P:Predicate_COND_UNE>>) - Complexity = 3
                  // Dst: (V_CMP_NEQ_F32_e64:i1 VSrc_32:f32:$src0, VSrc_32:f32:$src1)
/*26713*/       0, /*End of Scope*/
/*26714*/     /*Scope*/ 32, /*->26747*/
/*26715*/       OPC_CheckCondCode, ISD::SETO,
/*26717*/       OPC_MoveParent,
/*26718*/       OPC_CheckType, MVT::i1,
/*26720*/       OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*26722*/       OPC_EmitInteger, MVT::i32, 0, 
/*26725*/       OPC_EmitInteger, MVT::i32, 0, 
/*26728*/       OPC_EmitInteger, MVT::i32, 0, 
/*26731*/       OPC_EmitInteger, MVT::i32, 0, 
/*26734*/       OPC_MorphNodeTo, TARGET_VAL(AMDGPU::V_CMP_O_F32_e64), 0,
                    1/*#VTs*/, MVT::i1, 6/*#Ops*/, 0, 1, 2, 3, 4, 5, 
                // Src: (setcc:i1 f32:f32:$src0, f32:f32:$src1, SETO:Other) - Complexity = 3
                // Dst: (V_CMP_O_F32_e64:i1 ?:f32:$src0, ?:f32:$src1)
/*26747*/     /*Scope*/ 32, /*->26780*/
/*26748*/       OPC_CheckCondCode, ISD::SETUO,
/*26750*/       OPC_MoveParent,
/*26751*/       OPC_CheckType, MVT::i1,
/*26753*/       OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*26755*/       OPC_EmitInteger, MVT::i32, 0, 
/*26758*/       OPC_EmitInteger, MVT::i32, 0, 
/*26761*/       OPC_EmitInteger, MVT::i32, 0, 
/*26764*/       OPC_EmitInteger, MVT::i32, 0, 
/*26767*/       OPC_MorphNodeTo, TARGET_VAL(AMDGPU::V_CMP_U_F32_e64), 0,
                    1/*#VTs*/, MVT::i1, 6/*#Ops*/, 0, 1, 2, 3, 4, 5, 
                // Src: (setcc:i1 f32:f32:$src0, f32:f32:$src1, SETUO:Other) - Complexity = 3
                // Dst: (V_CMP_U_F32_e64:i1 ?:f32:$src0, ?:f32:$src1)
/*26780*/     0, /*End of Scope*/
/*26781*/   /*Scope*/ 18|128,2/*274*/, /*->27057*/
/*26783*/     OPC_CheckChild0Type, MVT::f64,
/*26785*/     OPC_RecordChild1, // #1 = $src1
/*26786*/     OPC_MoveChild, 2,
/*26788*/     OPC_CheckOpcode, TARGET_VAL(ISD::CONDCODE),
/*26791*/     OPC_Scope, 32, /*->26825*/ // 8 children in Scope
/*26793*/       OPC_CheckPredicate, 62, // Predicate_COND_OLT
/*26795*/       OPC_MoveParent,
/*26796*/       OPC_CheckType, MVT::i1,
/*26798*/       OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*26800*/       OPC_EmitInteger, MVT::i32, 0, 
/*26803*/       OPC_EmitInteger, MVT::i32, 0, 
/*26806*/       OPC_EmitInteger, MVT::i32, 0, 
/*26809*/       OPC_EmitInteger, MVT::i32, 0, 
/*26812*/       OPC_MorphNodeTo, TARGET_VAL(AMDGPU::V_CMP_LT_F64_e64), 0,
                    1/*#VTs*/, MVT::i1, 6/*#Ops*/, 0, 1, 2, 3, 4, 5, 
                // Src: (setcc:i1 VSrc_64:f64:$src0, VSrc_64:f64:$src1, (cond:Other)<<P:Predicate_COND_OLT>>) - Complexity = 3
                // Dst: (V_CMP_LT_F64_e64:i1 VSrc_64:f64:$src0, VSrc_64:f64:$src1)
/*26825*/     /*Scope*/ 32, /*->26858*/
/*26826*/       OPC_CheckPredicate, 2, // Predicate_COND_OEQ
/*26828*/       OPC_MoveParent,
/*26829*/       OPC_CheckType, MVT::i1,
/*26831*/       OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*26833*/       OPC_EmitInteger, MVT::i32, 0, 
/*26836*/       OPC_EmitInteger, MVT::i32, 0, 
/*26839*/       OPC_EmitInteger, MVT::i32, 0, 
/*26842*/       OPC_EmitInteger, MVT::i32, 0, 
/*26845*/       OPC_MorphNodeTo, TARGET_VAL(AMDGPU::V_CMP_EQ_F64_e64), 0,
                    1/*#VTs*/, MVT::i1, 6/*#Ops*/, 0, 1, 2, 3, 4, 5, 
                // Src: (setcc:i1 VSrc_64:f64:$src0, VSrc_64:f64:$src1, (cond:Other)<<P:Predicate_COND_OEQ>>) - Complexity = 3
                // Dst: (V_CMP_EQ_F64_e64:i1 VSrc_64:f64:$src0, VSrc_64:f64:$src1)
/*26858*/     /*Scope*/ 32, /*->26891*/
/*26859*/       OPC_CheckPredicate, 63, // Predicate_COND_OLE
/*26861*/       OPC_MoveParent,
/*26862*/       OPC_CheckType, MVT::i1,
/*26864*/       OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*26866*/       OPC_EmitInteger, MVT::i32, 0, 
/*26869*/       OPC_EmitInteger, MVT::i32, 0, 
/*26872*/       OPC_EmitInteger, MVT::i32, 0, 
/*26875*/       OPC_EmitInteger, MVT::i32, 0, 
/*26878*/       OPC_MorphNodeTo, TARGET_VAL(AMDGPU::V_CMP_LE_F64_e64), 0,
                    1/*#VTs*/, MVT::i1, 6/*#Ops*/, 0, 1, 2, 3, 4, 5, 
                // Src: (setcc:i1 VSrc_64:f64:$src0, VSrc_64:f64:$src1, (cond:Other)<<P:Predicate_COND_OLE>>) - Complexity = 3
                // Dst: (V_CMP_LE_F64_e64:i1 VSrc_64:f64:$src0, VSrc_64:f64:$src1)
/*26891*/     /*Scope*/ 32, /*->26924*/
/*26892*/       OPC_CheckPredicate, 3, // Predicate_COND_OGT
/*26894*/       OPC_MoveParent,
/*26895*/       OPC_CheckType, MVT::i1,
/*26897*/       OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*26899*/       OPC_EmitInteger, MVT::i32, 0, 
/*26902*/       OPC_EmitInteger, MVT::i32, 0, 
/*26905*/       OPC_EmitInteger, MVT::i32, 0, 
/*26908*/       OPC_EmitInteger, MVT::i32, 0, 
/*26911*/       OPC_MorphNodeTo, TARGET_VAL(AMDGPU::V_CMP_GT_F64_e64), 0,
                    1/*#VTs*/, MVT::i1, 6/*#Ops*/, 0, 1, 2, 3, 4, 5, 
                // Src: (setcc:i1 VSrc_64:f64:$src0, VSrc_64:f64:$src1, (cond:Other)<<P:Predicate_COND_OGT>>) - Complexity = 3
                // Dst: (V_CMP_GT_F64_e64:i1 VSrc_64:f64:$src0, VSrc_64:f64:$src1)
/*26924*/     /*Scope*/ 32, /*->26957*/
/*26925*/       OPC_CheckPredicate, 4, // Predicate_COND_OGE
/*26927*/       OPC_MoveParent,
/*26928*/       OPC_CheckType, MVT::i1,
/*26930*/       OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*26932*/       OPC_EmitInteger, MVT::i32, 0, 
/*26935*/       OPC_EmitInteger, MVT::i32, 0, 
/*26938*/       OPC_EmitInteger, MVT::i32, 0, 
/*26941*/       OPC_EmitInteger, MVT::i32, 0, 
/*26944*/       OPC_MorphNodeTo, TARGET_VAL(AMDGPU::V_CMP_GE_F64_e64), 0,
                    1/*#VTs*/, MVT::i1, 6/*#Ops*/, 0, 1, 2, 3, 4, 5, 
                // Src: (setcc:i1 VSrc_64:f64:$src0, VSrc_64:f64:$src1, (cond:Other)<<P:Predicate_COND_OGE>>) - Complexity = 3
                // Dst: (V_CMP_GE_F64_e64:i1 VSrc_64:f64:$src0, VSrc_64:f64:$src1)
/*26957*/     /*Scope*/ 32, /*->26990*/
/*26958*/       OPC_CheckPredicate, 64, // Predicate_COND_O
/*26960*/       OPC_MoveParent,
/*26961*/       OPC_CheckType, MVT::i1,
/*26963*/       OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*26965*/       OPC_EmitInteger, MVT::i32, 0, 
/*26968*/       OPC_EmitInteger, MVT::i32, 0, 
/*26971*/       OPC_EmitInteger, MVT::i32, 0, 
/*26974*/       OPC_EmitInteger, MVT::i32, 0, 
/*26977*/       OPC_MorphNodeTo, TARGET_VAL(AMDGPU::V_CMP_O_F64_e64), 0,
                    1/*#VTs*/, MVT::i1, 6/*#Ops*/, 0, 1, 2, 3, 4, 5, 
                // Src: (setcc:i1 VSrc_64:f64:$src0, VSrc_64:f64:$src1, (cond:Other)<<P:Predicate_COND_O>>) - Complexity = 3
                // Dst: (V_CMP_O_F64_e64:i1 VSrc_64:f64:$src0, VSrc_64:f64:$src1)
/*26990*/     /*Scope*/ 32, /*->27023*/
/*26991*/       OPC_CheckPredicate, 65, // Predicate_COND_UO
/*26993*/       OPC_MoveParent,
/*26994*/       OPC_CheckType, MVT::i1,
/*26996*/       OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*26998*/       OPC_EmitInteger, MVT::i32, 0, 
/*27001*/       OPC_EmitInteger, MVT::i32, 0, 
/*27004*/       OPC_EmitInteger, MVT::i32, 0, 
/*27007*/       OPC_EmitInteger, MVT::i32, 0, 
/*27010*/       OPC_MorphNodeTo, TARGET_VAL(AMDGPU::V_CMP_U_F64_e64), 0,
                    1/*#VTs*/, MVT::i1, 6/*#Ops*/, 0, 1, 2, 3, 4, 5, 
                // Src: (setcc:i1 VSrc_64:f64:$src0, VSrc_64:f64:$src1, (cond:Other)<<P:Predicate_COND_UO>>) - Complexity = 3
                // Dst: (V_CMP_U_F64_e64:i1 VSrc_64:f64:$src0, VSrc_64:f64:$src1)
/*27023*/     /*Scope*/ 32, /*->27056*/
/*27024*/       OPC_CheckPredicate, 5, // Predicate_COND_UNE
/*27026*/       OPC_MoveParent,
/*27027*/       OPC_CheckType, MVT::i1,
/*27029*/       OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*27031*/       OPC_EmitInteger, MVT::i32, 0, 
/*27034*/       OPC_EmitInteger, MVT::i32, 0, 
/*27037*/       OPC_EmitInteger, MVT::i32, 0, 
/*27040*/       OPC_EmitInteger, MVT::i32, 0, 
/*27043*/       OPC_MorphNodeTo, TARGET_VAL(AMDGPU::V_CMP_NEQ_F64_e64), 0,
                    1/*#VTs*/, MVT::i1, 6/*#Ops*/, 0, 1, 2, 3, 4, 5, 
                // Src: (setcc:i1 VSrc_64:f64:$src0, VSrc_64:f64:$src1, (cond:Other)<<P:Predicate_COND_UNE>>) - Complexity = 3
                // Dst: (V_CMP_NEQ_F64_e64:i1 VSrc_64:f64:$src0, VSrc_64:f64:$src1)
/*27056*/     0, /*End of Scope*/
/*27057*/   /*Scope*/ 22|128,3/*406*/, /*->27465*/
/*27059*/     OPC_CheckChild0Type, MVT::i32,
/*27061*/     OPC_RecordChild1, // #1 = $src1
/*27062*/     OPC_MoveChild, 2,
/*27064*/     OPC_CheckOpcode, TARGET_VAL(ISD::CONDCODE),
/*27067*/     OPC_Scope, 32, /*->27101*/ // 12 children in Scope
/*27069*/       OPC_CheckPredicate, 66, // Predicate_COND_SLT
/*27071*/       OPC_MoveParent,
/*27072*/       OPC_CheckType, MVT::i1,
/*27074*/       OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*27076*/       OPC_EmitInteger, MVT::i32, 0, 
/*27079*/       OPC_EmitInteger, MVT::i32, 0, 
/*27082*/       OPC_EmitInteger, MVT::i32, 0, 
/*27085*/       OPC_EmitInteger, MVT::i32, 0, 
/*27088*/       OPC_MorphNodeTo, TARGET_VAL(AMDGPU::V_CMP_LT_I32_e64), 0,
                    1/*#VTs*/, MVT::i1, 6/*#Ops*/, 0, 1, 2, 3, 4, 5, 
                // Src: (setcc:i1 VSrc_32:i32:$src0, VSrc_32:i32:$src1, (cond:Other)<<P:Predicate_COND_SLT>>) - Complexity = 3
                // Dst: (V_CMP_LT_I32_e64:i1 VSrc_32:i32:$src0, VSrc_32:i32:$src1)
/*27101*/     /*Scope*/ 32, /*->27134*/
/*27102*/       OPC_CheckPredicate, 8, // Predicate_COND_EQ
/*27104*/       OPC_MoveParent,
/*27105*/       OPC_CheckType, MVT::i1,
/*27107*/       OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*27109*/       OPC_EmitInteger, MVT::i32, 0, 
/*27112*/       OPC_EmitInteger, MVT::i32, 0, 
/*27115*/       OPC_EmitInteger, MVT::i32, 0, 
/*27118*/       OPC_EmitInteger, MVT::i32, 0, 
/*27121*/       OPC_MorphNodeTo, TARGET_VAL(AMDGPU::V_CMP_EQ_I32_e64), 0,
                    1/*#VTs*/, MVT::i1, 6/*#Ops*/, 0, 1, 2, 3, 4, 5, 
                // Src: (setcc:i1 VSrc_32:i32:$src0, VSrc_32:i32:$src1, (cond:Other)<<P:Predicate_COND_EQ>>) - Complexity = 3
                // Dst: (V_CMP_EQ_I32_e64:i1 VSrc_32:i32:$src0, VSrc_32:i32:$src1)
/*27134*/     /*Scope*/ 32, /*->27167*/
/*27135*/       OPC_CheckPredicate, 67, // Predicate_COND_SLE
/*27137*/       OPC_MoveParent,
/*27138*/       OPC_CheckType, MVT::i1,
/*27140*/       OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*27142*/       OPC_EmitInteger, MVT::i32, 0, 
/*27145*/       OPC_EmitInteger, MVT::i32, 0, 
/*27148*/       OPC_EmitInteger, MVT::i32, 0, 
/*27151*/       OPC_EmitInteger, MVT::i32, 0, 
/*27154*/       OPC_MorphNodeTo, TARGET_VAL(AMDGPU::V_CMP_LE_I32_e64), 0,
                    1/*#VTs*/, MVT::i1, 6/*#Ops*/, 0, 1, 2, 3, 4, 5, 
                // Src: (setcc:i1 VSrc_32:i32:$src0, VSrc_32:i32:$src1, (cond:Other)<<P:Predicate_COND_SLE>>) - Complexity = 3
                // Dst: (V_CMP_LE_I32_e64:i1 VSrc_32:i32:$src0, VSrc_32:i32:$src1)
/*27167*/     /*Scope*/ 32, /*->27200*/
/*27168*/       OPC_CheckPredicate, 10, // Predicate_COND_SGT
/*27170*/       OPC_MoveParent,
/*27171*/       OPC_CheckType, MVT::i1,
/*27173*/       OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*27175*/       OPC_EmitInteger, MVT::i32, 0, 
/*27178*/       OPC_EmitInteger, MVT::i32, 0, 
/*27181*/       OPC_EmitInteger, MVT::i32, 0, 
/*27184*/       OPC_EmitInteger, MVT::i32, 0, 
/*27187*/       OPC_MorphNodeTo, TARGET_VAL(AMDGPU::V_CMP_GT_I32_e64), 0,
                    1/*#VTs*/, MVT::i1, 6/*#Ops*/, 0, 1, 2, 3, 4, 5, 
                // Src: (setcc:i1 VSrc_32:i32:$src0, VSrc_32:i32:$src1, (cond:Other)<<P:Predicate_COND_SGT>>) - Complexity = 3
                // Dst: (V_CMP_GT_I32_e64:i1 VSrc_32:i32:$src0, VSrc_32:i32:$src1)
/*27200*/     /*Scope*/ 32, /*->27233*/
/*27201*/       OPC_CheckPredicate, 68, // Predicate_COND_NE
/*27203*/       OPC_MoveParent,
/*27204*/       OPC_CheckType, MVT::i1,
/*27206*/       OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*27208*/       OPC_EmitInteger, MVT::i32, 0, 
/*27211*/       OPC_EmitInteger, MVT::i32, 0, 
/*27214*/       OPC_EmitInteger, MVT::i32, 0, 
/*27217*/       OPC_EmitInteger, MVT::i32, 0, 
/*27220*/       OPC_MorphNodeTo, TARGET_VAL(AMDGPU::V_CMP_NE_I32_e64), 0,
                    1/*#VTs*/, MVT::i1, 6/*#Ops*/, 0, 1, 2, 3, 4, 5, 
                // Src: (setcc:i1 VSrc_32:i32:$src0, VSrc_32:i32:$src1, (cond:Other)<<P:Predicate_COND_NE>>) - Complexity = 3
                // Dst: (V_CMP_NE_I32_e64:i1 VSrc_32:i32:$src0, VSrc_32:i32:$src1)
/*27233*/     /*Scope*/ 32, /*->27266*/
/*27234*/       OPC_CheckPredicate, 9, // Predicate_COND_SGE
/*27236*/       OPC_MoveParent,
/*27237*/       OPC_CheckType, MVT::i1,
/*27239*/       OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*27241*/       OPC_EmitInteger, MVT::i32, 0, 
/*27244*/       OPC_EmitInteger, MVT::i32, 0, 
/*27247*/       OPC_EmitInteger, MVT::i32, 0, 
/*27250*/       OPC_EmitInteger, MVT::i32, 0, 
/*27253*/       OPC_MorphNodeTo, TARGET_VAL(AMDGPU::V_CMP_GE_I32_e64), 0,
                    1/*#VTs*/, MVT::i1, 6/*#Ops*/, 0, 1, 2, 3, 4, 5, 
                // Src: (setcc:i1 VSrc_32:i32:$src0, VSrc_32:i32:$src1, (cond:Other)<<P:Predicate_COND_SGE>>) - Complexity = 3
                // Dst: (V_CMP_GE_I32_e64:i1 VSrc_32:i32:$src0, VSrc_32:i32:$src1)
/*27266*/     /*Scope*/ 32, /*->27299*/
/*27267*/       OPC_CheckPredicate, 69, // Predicate_COND_ULT
/*27269*/       OPC_MoveParent,
/*27270*/       OPC_CheckType, MVT::i1,
/*27272*/       OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*27274*/       OPC_EmitInteger, MVT::i32, 0, 
/*27277*/       OPC_EmitInteger, MVT::i32, 0, 
/*27280*/       OPC_EmitInteger, MVT::i32, 0, 
/*27283*/       OPC_EmitInteger, MVT::i32, 0, 
/*27286*/       OPC_MorphNodeTo, TARGET_VAL(AMDGPU::V_CMP_LT_U32_e64), 0,
                    1/*#VTs*/, MVT::i1, 6/*#Ops*/, 0, 1, 2, 3, 4, 5, 
                // Src: (setcc:i1 VSrc_32:i32:$src0, VSrc_32:i32:$src1, (cond:Other)<<P:Predicate_COND_ULT>>) - Complexity = 3
                // Dst: (V_CMP_LT_U32_e64:i1 VSrc_32:i32:$src0, VSrc_32:i32:$src1)
/*27299*/     /*Scope*/ 32, /*->27332*/
/*27300*/       OPC_CheckPredicate, 8, // Predicate_COND_EQ
/*27302*/       OPC_MoveParent,
/*27303*/       OPC_CheckType, MVT::i1,
/*27305*/       OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*27307*/       OPC_EmitInteger, MVT::i32, 0, 
/*27310*/       OPC_EmitInteger, MVT::i32, 0, 
/*27313*/       OPC_EmitInteger, MVT::i32, 0, 
/*27316*/       OPC_EmitInteger, MVT::i32, 0, 
/*27319*/       OPC_MorphNodeTo, TARGET_VAL(AMDGPU::V_CMP_EQ_U32_e64), 0,
                    1/*#VTs*/, MVT::i1, 6/*#Ops*/, 0, 1, 2, 3, 4, 5, 
                // Src: (setcc:i1 VSrc_32:i32:$src0, VSrc_32:i32:$src1, (cond:Other)<<P:Predicate_COND_EQ>>) - Complexity = 3
                // Dst: (V_CMP_EQ_U32_e64:i1 VSrc_32:i32:$src0, VSrc_32:i32:$src1)
/*27332*/     /*Scope*/ 32, /*->27365*/
/*27333*/       OPC_CheckPredicate, 70, // Predicate_COND_ULE
/*27335*/       OPC_MoveParent,
/*27336*/       OPC_CheckType, MVT::i1,
/*27338*/       OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*27340*/       OPC_EmitInteger, MVT::i32, 0, 
/*27343*/       OPC_EmitInteger, MVT::i32, 0, 
/*27346*/       OPC_EmitInteger, MVT::i32, 0, 
/*27349*/       OPC_EmitInteger, MVT::i32, 0, 
/*27352*/       OPC_MorphNodeTo, TARGET_VAL(AMDGPU::V_CMP_LE_U32_e64), 0,
                    1/*#VTs*/, MVT::i1, 6/*#Ops*/, 0, 1, 2, 3, 4, 5, 
                // Src: (setcc:i1 VSrc_32:i32:$src0, VSrc_32:i32:$src1, (cond:Other)<<P:Predicate_COND_ULE>>) - Complexity = 3
                // Dst: (V_CMP_LE_U32_e64:i1 VSrc_32:i32:$src0, VSrc_32:i32:$src1)
/*27365*/     /*Scope*/ 32, /*->27398*/
/*27366*/       OPC_CheckPredicate, 71, // Predicate_COND_UGT
/*27368*/       OPC_MoveParent,
/*27369*/       OPC_CheckType, MVT::i1,
/*27371*/       OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*27373*/       OPC_EmitInteger, MVT::i32, 0, 
/*27376*/       OPC_EmitInteger, MVT::i32, 0, 
/*27379*/       OPC_EmitInteger, MVT::i32, 0, 
/*27382*/       OPC_EmitInteger, MVT::i32, 0, 
/*27385*/       OPC_MorphNodeTo, TARGET_VAL(AMDGPU::V_CMP_GT_U32_e64), 0,
                    1/*#VTs*/, MVT::i1, 6/*#Ops*/, 0, 1, 2, 3, 4, 5, 
                // Src: (setcc:i1 VSrc_32:i32:$src0, VSrc_32:i32:$src1, (cond:Other)<<P:Predicate_COND_UGT>>) - Complexity = 3
                // Dst: (V_CMP_GT_U32_e64:i1 VSrc_32:i32:$src0, VSrc_32:i32:$src1)
/*27398*/     /*Scope*/ 32, /*->27431*/
/*27399*/       OPC_CheckPredicate, 68, // Predicate_COND_NE
/*27401*/       OPC_MoveParent,
/*27402*/       OPC_CheckType, MVT::i1,
/*27404*/       OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*27406*/       OPC_EmitInteger, MVT::i32, 0, 
/*27409*/       OPC_EmitInteger, MVT::i32, 0, 
/*27412*/       OPC_EmitInteger, MVT::i32, 0, 
/*27415*/       OPC_EmitInteger, MVT::i32, 0, 
/*27418*/       OPC_MorphNodeTo, TARGET_VAL(AMDGPU::V_CMP_NE_U32_e64), 0,
                    1/*#VTs*/, MVT::i1, 6/*#Ops*/, 0, 1, 2, 3, 4, 5, 
                // Src: (setcc:i1 VSrc_32:i32:$src0, VSrc_32:i32:$src1, (cond:Other)<<P:Predicate_COND_NE>>) - Complexity = 3
                // Dst: (V_CMP_NE_U32_e64:i1 VSrc_32:i32:$src0, VSrc_32:i32:$src1)
/*27431*/     /*Scope*/ 32, /*->27464*/
/*27432*/       OPC_CheckPredicate, 72, // Predicate_COND_UGE
/*27434*/       OPC_MoveParent,
/*27435*/       OPC_CheckType, MVT::i1,
/*27437*/       OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*27439*/       OPC_EmitInteger, MVT::i32, 0, 
/*27442*/       OPC_EmitInteger, MVT::i32, 0, 
/*27445*/       OPC_EmitInteger, MVT::i32, 0, 
/*27448*/       OPC_EmitInteger, MVT::i32, 0, 
/*27451*/       OPC_MorphNodeTo, TARGET_VAL(AMDGPU::V_CMP_GE_U32_e64), 0,
                    1/*#VTs*/, MVT::i1, 6/*#Ops*/, 0, 1, 2, 3, 4, 5, 
                // Src: (setcc:i1 VSrc_32:i32:$src0, VSrc_32:i32:$src1, (cond:Other)<<P:Predicate_COND_UGE>>) - Complexity = 3
                // Dst: (V_CMP_GE_U32_e64:i1 VSrc_32:i32:$src0, VSrc_32:i32:$src1)
/*27464*/     0, /*End of Scope*/
/*27465*/   /*Scope*/ 22|128,3/*406*/, /*->27873*/
/*27467*/     OPC_CheckChild0Type, MVT::i64,
/*27469*/     OPC_RecordChild1, // #1 = $src1
/*27470*/     OPC_MoveChild, 2,
/*27472*/     OPC_CheckOpcode, TARGET_VAL(ISD::CONDCODE),
/*27475*/     OPC_Scope, 32, /*->27509*/ // 12 children in Scope
/*27477*/       OPC_CheckPredicate, 66, // Predicate_COND_SLT
/*27479*/       OPC_MoveParent,
/*27480*/       OPC_CheckType, MVT::i1,
/*27482*/       OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*27484*/       OPC_EmitInteger, MVT::i32, 0, 
/*27487*/       OPC_EmitInteger, MVT::i32, 0, 
/*27490*/       OPC_EmitInteger, MVT::i32, 0, 
/*27493*/       OPC_EmitInteger, MVT::i32, 0, 
/*27496*/       OPC_MorphNodeTo, TARGET_VAL(AMDGPU::V_CMP_LT_I64_e64), 0,
                    1/*#VTs*/, MVT::i1, 6/*#Ops*/, 0, 1, 2, 3, 4, 5, 
                // Src: (setcc:i1 VSrc_64:i64:$src0, VSrc_64:i64:$src1, (cond:Other)<<P:Predicate_COND_SLT>>) - Complexity = 3
                // Dst: (V_CMP_LT_I64_e64:i1 VSrc_64:i64:$src0, VSrc_64:i64:$src1)
/*27509*/     /*Scope*/ 32, /*->27542*/
/*27510*/       OPC_CheckPredicate, 8, // Predicate_COND_EQ
/*27512*/       OPC_MoveParent,
/*27513*/       OPC_CheckType, MVT::i1,
/*27515*/       OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*27517*/       OPC_EmitInteger, MVT::i32, 0, 
/*27520*/       OPC_EmitInteger, MVT::i32, 0, 
/*27523*/       OPC_EmitInteger, MVT::i32, 0, 
/*27526*/       OPC_EmitInteger, MVT::i32, 0, 
/*27529*/       OPC_MorphNodeTo, TARGET_VAL(AMDGPU::V_CMP_EQ_I64_e64), 0,
                    1/*#VTs*/, MVT::i1, 6/*#Ops*/, 0, 1, 2, 3, 4, 5, 
                // Src: (setcc:i1 VSrc_64:i64:$src0, VSrc_64:i64:$src1, (cond:Other)<<P:Predicate_COND_EQ>>) - Complexity = 3
                // Dst: (V_CMP_EQ_I64_e64:i1 VSrc_64:i64:$src0, VSrc_64:i64:$src1)
/*27542*/     /*Scope*/ 32, /*->27575*/
/*27543*/       OPC_CheckPredicate, 67, // Predicate_COND_SLE
/*27545*/       OPC_MoveParent,
/*27546*/       OPC_CheckType, MVT::i1,
/*27548*/       OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*27550*/       OPC_EmitInteger, MVT::i32, 0, 
/*27553*/       OPC_EmitInteger, MVT::i32, 0, 
/*27556*/       OPC_EmitInteger, MVT::i32, 0, 
/*27559*/       OPC_EmitInteger, MVT::i32, 0, 
/*27562*/       OPC_MorphNodeTo, TARGET_VAL(AMDGPU::V_CMP_LE_I64_e64), 0,
                    1/*#VTs*/, MVT::i1, 6/*#Ops*/, 0, 1, 2, 3, 4, 5, 
                // Src: (setcc:i1 VSrc_64:i64:$src0, VSrc_64:i64:$src1, (cond:Other)<<P:Predicate_COND_SLE>>) - Complexity = 3
                // Dst: (V_CMP_LE_I64_e64:i1 VSrc_64:i64:$src0, VSrc_64:i64:$src1)
/*27575*/     /*Scope*/ 32, /*->27608*/
/*27576*/       OPC_CheckPredicate, 10, // Predicate_COND_SGT
/*27578*/       OPC_MoveParent,
/*27579*/       OPC_CheckType, MVT::i1,
/*27581*/       OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*27583*/       OPC_EmitInteger, MVT::i32, 0, 
/*27586*/       OPC_EmitInteger, MVT::i32, 0, 
/*27589*/       OPC_EmitInteger, MVT::i32, 0, 
/*27592*/       OPC_EmitInteger, MVT::i32, 0, 
/*27595*/       OPC_MorphNodeTo, TARGET_VAL(AMDGPU::V_CMP_GT_I64_e64), 0,
                    1/*#VTs*/, MVT::i1, 6/*#Ops*/, 0, 1, 2, 3, 4, 5, 
                // Src: (setcc:i1 VSrc_64:i64:$src0, VSrc_64:i64:$src1, (cond:Other)<<P:Predicate_COND_SGT>>) - Complexity = 3
                // Dst: (V_CMP_GT_I64_e64:i1 VSrc_64:i64:$src0, VSrc_64:i64:$src1)
/*27608*/     /*Scope*/ 32, /*->27641*/
/*27609*/       OPC_CheckPredicate, 68, // Predicate_COND_NE
/*27611*/       OPC_MoveParent,
/*27612*/       OPC_CheckType, MVT::i1,
/*27614*/       OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*27616*/       OPC_EmitInteger, MVT::i32, 0, 
/*27619*/       OPC_EmitInteger, MVT::i32, 0, 
/*27622*/       OPC_EmitInteger, MVT::i32, 0, 
/*27625*/       OPC_EmitInteger, MVT::i32, 0, 
/*27628*/       OPC_MorphNodeTo, TARGET_VAL(AMDGPU::V_CMP_NE_I64_e64), 0,
                    1/*#VTs*/, MVT::i1, 6/*#Ops*/, 0, 1, 2, 3, 4, 5, 
                // Src: (setcc:i1 VSrc_64:i64:$src0, VSrc_64:i64:$src1, (cond:Other)<<P:Predicate_COND_NE>>) - Complexity = 3
                // Dst: (V_CMP_NE_I64_e64:i1 VSrc_64:i64:$src0, VSrc_64:i64:$src1)
/*27641*/     /*Scope*/ 32, /*->27674*/
/*27642*/       OPC_CheckPredicate, 9, // Predicate_COND_SGE
/*27644*/       OPC_MoveParent,
/*27645*/       OPC_CheckType, MVT::i1,
/*27647*/       OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*27649*/       OPC_EmitInteger, MVT::i32, 0, 
/*27652*/       OPC_EmitInteger, MVT::i32, 0, 
/*27655*/       OPC_EmitInteger, MVT::i32, 0, 
/*27658*/       OPC_EmitInteger, MVT::i32, 0, 
/*27661*/       OPC_MorphNodeTo, TARGET_VAL(AMDGPU::V_CMP_GE_I64_e64), 0,
                    1/*#VTs*/, MVT::i1, 6/*#Ops*/, 0, 1, 2, 3, 4, 5, 
                // Src: (setcc:i1 VSrc_64:i64:$src0, VSrc_64:i64:$src1, (cond:Other)<<P:Predicate_COND_SGE>>) - Complexity = 3
                // Dst: (V_CMP_GE_I64_e64:i1 VSrc_64:i64:$src0, VSrc_64:i64:$src1)
/*27674*/     /*Scope*/ 32, /*->27707*/
/*27675*/       OPC_CheckPredicate, 69, // Predicate_COND_ULT
/*27677*/       OPC_MoveParent,
/*27678*/       OPC_CheckType, MVT::i1,
/*27680*/       OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*27682*/       OPC_EmitInteger, MVT::i32, 0, 
/*27685*/       OPC_EmitInteger, MVT::i32, 0, 
/*27688*/       OPC_EmitInteger, MVT::i32, 0, 
/*27691*/       OPC_EmitInteger, MVT::i32, 0, 
/*27694*/       OPC_MorphNodeTo, TARGET_VAL(AMDGPU::V_CMP_LT_U64_e64), 0,
                    1/*#VTs*/, MVT::i1, 6/*#Ops*/, 0, 1, 2, 3, 4, 5, 
                // Src: (setcc:i1 VSrc_64:i64:$src0, VSrc_64:i64:$src1, (cond:Other)<<P:Predicate_COND_ULT>>) - Complexity = 3
                // Dst: (V_CMP_LT_U64_e64:i1 VSrc_64:i64:$src0, VSrc_64:i64:$src1)
/*27707*/     /*Scope*/ 32, /*->27740*/
/*27708*/       OPC_CheckPredicate, 8, // Predicate_COND_EQ
/*27710*/       OPC_MoveParent,
/*27711*/       OPC_CheckType, MVT::i1,
/*27713*/       OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*27715*/       OPC_EmitInteger, MVT::i32, 0, 
/*27718*/       OPC_EmitInteger, MVT::i32, 0, 
/*27721*/       OPC_EmitInteger, MVT::i32, 0, 
/*27724*/       OPC_EmitInteger, MVT::i32, 0, 
/*27727*/       OPC_MorphNodeTo, TARGET_VAL(AMDGPU::V_CMP_EQ_U64_e64), 0,
                    1/*#VTs*/, MVT::i1, 6/*#Ops*/, 0, 1, 2, 3, 4, 5, 
                // Src: (setcc:i1 VSrc_64:i64:$src0, VSrc_64:i64:$src1, (cond:Other)<<P:Predicate_COND_EQ>>) - Complexity = 3
                // Dst: (V_CMP_EQ_U64_e64:i1 VSrc_64:i64:$src0, VSrc_64:i64:$src1)
/*27740*/     /*Scope*/ 32, /*->27773*/
/*27741*/       OPC_CheckPredicate, 70, // Predicate_COND_ULE
/*27743*/       OPC_MoveParent,
/*27744*/       OPC_CheckType, MVT::i1,
/*27746*/       OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*27748*/       OPC_EmitInteger, MVT::i32, 0, 
/*27751*/       OPC_EmitInteger, MVT::i32, 0, 
/*27754*/       OPC_EmitInteger, MVT::i32, 0, 
/*27757*/       OPC_EmitInteger, MVT::i32, 0, 
/*27760*/       OPC_MorphNodeTo, TARGET_VAL(AMDGPU::V_CMP_LE_U64_e64), 0,
                    1/*#VTs*/, MVT::i1, 6/*#Ops*/, 0, 1, 2, 3, 4, 5, 
                // Src: (setcc:i1 VSrc_64:i64:$src0, VSrc_64:i64:$src1, (cond:Other)<<P:Predicate_COND_ULE>>) - Complexity = 3
                // Dst: (V_CMP_LE_U64_e64:i1 VSrc_64:i64:$src0, VSrc_64:i64:$src1)
/*27773*/     /*Scope*/ 32, /*->27806*/
/*27774*/       OPC_CheckPredicate, 71, // Predicate_COND_UGT
/*27776*/       OPC_MoveParent,
/*27777*/       OPC_CheckType, MVT::i1,
/*27779*/       OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*27781*/       OPC_EmitInteger, MVT::i32, 0, 
/*27784*/       OPC_EmitInteger, MVT::i32, 0, 
/*27787*/       OPC_EmitInteger, MVT::i32, 0, 
/*27790*/       OPC_EmitInteger, MVT::i32, 0, 
/*27793*/       OPC_MorphNodeTo, TARGET_VAL(AMDGPU::V_CMP_GT_U64_e64), 0,
                    1/*#VTs*/, MVT::i1, 6/*#Ops*/, 0, 1, 2, 3, 4, 5, 
                // Src: (setcc:i1 VSrc_64:i64:$src0, VSrc_64:i64:$src1, (cond:Other)<<P:Predicate_COND_UGT>>) - Complexity = 3
                // Dst: (V_CMP_GT_U64_e64:i1 VSrc_64:i64:$src0, VSrc_64:i64:$src1)
/*27806*/     /*Scope*/ 32, /*->27839*/
/*27807*/       OPC_CheckPredicate, 68, // Predicate_COND_NE
/*27809*/       OPC_MoveParent,
/*27810*/       OPC_CheckType, MVT::i1,
/*27812*/       OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*27814*/       OPC_EmitInteger, MVT::i32, 0, 
/*27817*/       OPC_EmitInteger, MVT::i32, 0, 
/*27820*/       OPC_EmitInteger, MVT::i32, 0, 
/*27823*/       OPC_EmitInteger, MVT::i32, 0, 
/*27826*/       OPC_MorphNodeTo, TARGET_VAL(AMDGPU::V_CMP_NE_U64_e64), 0,
                    1/*#VTs*/, MVT::i1, 6/*#Ops*/, 0, 1, 2, 3, 4, 5, 
                // Src: (setcc:i1 VSrc_64:i64:$src0, VSrc_64:i64:$src1, (cond:Other)<<P:Predicate_COND_NE>>) - Complexity = 3
                // Dst: (V_CMP_NE_U64_e64:i1 VSrc_64:i64:$src0, VSrc_64:i64:$src1)
/*27839*/     /*Scope*/ 32, /*->27872*/
/*27840*/       OPC_CheckPredicate, 72, // Predicate_COND_UGE
/*27842*/       OPC_MoveParent,
/*27843*/       OPC_CheckType, MVT::i1,
/*27845*/       OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*27847*/       OPC_EmitInteger, MVT::i32, 0, 
/*27850*/       OPC_EmitInteger, MVT::i32, 0, 
/*27853*/       OPC_EmitInteger, MVT::i32, 0, 
/*27856*/       OPC_EmitInteger, MVT::i32, 0, 
/*27859*/       OPC_MorphNodeTo, TARGET_VAL(AMDGPU::V_CMP_GE_U64_e64), 0,
                    1/*#VTs*/, MVT::i1, 6/*#Ops*/, 0, 1, 2, 3, 4, 5, 
                // Src: (setcc:i1 VSrc_64:i64:$src0, VSrc_64:i64:$src1, (cond:Other)<<P:Predicate_COND_UGE>>) - Complexity = 3
                // Dst: (V_CMP_GE_U64_e64:i1 VSrc_64:i64:$src0, VSrc_64:i64:$src1)
/*27872*/     0, /*End of Scope*/
/*27873*/   0, /*End of Scope*/
/*27874*/ /*SwitchOpcode*/ 24,  TARGET_VAL(AMDGPUISD::RET_FLAG),// ->27901
/*27877*/   OPC_RecordNode,   // #0 = 'IL_retflag' chained node
/*27878*/   OPC_CaptureGlueInput,
/*27879*/   OPC_Scope, 9, /*->27890*/ // 2 children in Scope
/*27881*/     OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*27883*/     OPC_EmitMergeInputChains1_0,
/*27884*/     OPC_MorphNodeTo, TARGET_VAL(AMDGPU::S_ENDPGM), 0|OPFL_Chain|OPFL_GlueInput,
                  0/*#VTs*/, 0/*#Ops*/, 
              // Src: (IL_retflag) - Complexity = 3
              // Dst: (S_ENDPGM)
/*27890*/   /*Scope*/ 9, /*->27900*/
/*27891*/     OPC_CheckPatternPredicate, 3, // (Subtarget.getGeneration() <= AMDGPUSubtarget::NORTHERN_ISLANDS)
/*27893*/     OPC_EmitMergeInputChains1_0,
/*27894*/     OPC_MorphNodeTo, TARGET_VAL(AMDGPU::RETURN), 0|OPFL_Chain|OPFL_GlueInput,
                  0/*#VTs*/, 0/*#Ops*/, 
              // Src: (IL_retflag) - Complexity = 3
              // Dst: (RETURN)
/*27900*/   0, /*End of Scope*/
/*27901*/ /*SwitchOpcode*/ 32,  TARGET_VAL(ISD::BR),// ->27936
/*27904*/   OPC_RecordNode,   // #0 = 'br' chained node
/*27905*/   OPC_RecordChild1, // #1 = $target
/*27906*/   OPC_MoveChild, 1,
/*27908*/   OPC_CheckOpcode, TARGET_VAL(ISD::BasicBlock),
/*27911*/   OPC_MoveParent,
/*27912*/   OPC_Scope, 10, /*->27924*/ // 2 children in Scope
/*27914*/     OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*27916*/     OPC_EmitMergeInputChains1_0,
/*27917*/     OPC_MorphNodeTo, TARGET_VAL(AMDGPU::S_BRANCH), 0|OPFL_Chain,
                  0/*#VTs*/, 1/*#Ops*/, 1, 
              // Src: (br (bb:Other):$target) - Complexity = 3
              // Dst: (S_BRANCH (bb:Other):$target)
/*27924*/   /*Scope*/ 10, /*->27935*/
/*27925*/     OPC_CheckPatternPredicate, 3, // (Subtarget.getGeneration() <= AMDGPUSubtarget::NORTHERN_ISLANDS)
/*27927*/     OPC_EmitMergeInputChains1_0,
/*27928*/     OPC_MorphNodeTo, TARGET_VAL(AMDGPU::BRANCH), 0|OPFL_Chain,
                  0/*#VTs*/, 1/*#Ops*/, 1, 
              // Src: (br (bb:Other):$target) - Complexity = 3
              // Dst: (BRANCH (bb:Other):$target)
/*27935*/   0, /*End of Scope*/
/*27936*/ /*SwitchOpcode*/ 77|128,1/*205*/,  TARGET_VAL(ISD::SELECT),// ->28145
/*27940*/   OPC_RecordChild0, // #0 = $src2
/*27941*/   OPC_CheckChild0Type, MVT::i1,
/*27943*/   OPC_RecordChild1, // #1 = $src1
/*27944*/   OPC_RecordChild2, // #2 = $src0
/*27945*/   OPC_SwitchType /*3 cases */, 28,  MVT::i32,// ->27976
/*27948*/     OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*27950*/     OPC_EmitInteger, MVT::i32, 0, 
/*27953*/     OPC_EmitInteger, MVT::i32, 0, 
/*27956*/     OPC_EmitInteger, MVT::i32, 0, 
/*27959*/     OPC_EmitInteger, MVT::i32, 0, 
/*27962*/     OPC_MorphNodeTo, TARGET_VAL(AMDGPU::V_CNDMASK_B32_e64), 0,
                  1/*#VTs*/, MVT::i32, 7/*#Ops*/, 2, 1, 0, 3, 4, 5, 6, 
              // Src: (select:i32 i1:i1:$src2, i32:i32:$src1, i32:i32:$src0) - Complexity = 3
              // Dst: (V_CNDMASK_B32_e64:i32 i32:i32:$src0, i32:i32:$src1, i1:i1:$src2)
/*27976*/   /*SwitchType*/ 28,  MVT::f32,// ->28006
/*27978*/     OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*27980*/     OPC_EmitInteger, MVT::i32, 0, 
/*27983*/     OPC_EmitInteger, MVT::i32, 0, 
/*27986*/     OPC_EmitInteger, MVT::i32, 0, 
/*27989*/     OPC_EmitInteger, MVT::i32, 0, 
/*27992*/     OPC_MorphNodeTo, TARGET_VAL(AMDGPU::V_CNDMASK_B32_e64), 0,
                  1/*#VTs*/, MVT::f32, 7/*#Ops*/, 2, 1, 0, 3, 4, 5, 6, 
              // Src: (select:f32 i1:i1:$src2, f32:f32:$src1, f32:f32:$src0) - Complexity = 3
              // Dst: (V_CNDMASK_B32_e64:f32 ?:f32:$src0, ?:f32:$src1, ?:i1:$src2)
/*28006*/   /*SwitchType*/ 7|128,1/*135*/,  MVT::f64,// ->28144
/*28009*/     OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*28011*/     OPC_EmitNode, TARGET_VAL(TargetOpcode::IMPLICIT_DEF), 0,
                  1/*#VTs*/, MVT::f64, 0/*#Ops*/,  // Results = #3
/*28018*/     OPC_EmitInteger, MVT::i32, AMDGPU::sub0,
/*28021*/     OPC_EmitNode, TARGET_VAL(TargetOpcode::EXTRACT_SUBREG), 0,
                  1/*#VTs*/, MVT::i32, 2/*#Ops*/, 2, 4,  // Results = #5
/*28030*/     OPC_EmitInteger, MVT::i32, AMDGPU::sub0,
/*28033*/     OPC_EmitNode, TARGET_VAL(TargetOpcode::EXTRACT_SUBREG), 0,
                  1/*#VTs*/, MVT::i32, 2/*#Ops*/, 1, 6,  // Results = #7
/*28042*/     OPC_EmitInteger, MVT::i32, 0, 
/*28045*/     OPC_EmitInteger, MVT::i32, 0, 
/*28048*/     OPC_EmitInteger, MVT::i32, 0, 
/*28051*/     OPC_EmitInteger, MVT::i32, 0, 
/*28054*/     OPC_EmitNode, TARGET_VAL(AMDGPU::V_CNDMASK_B32_e64), 0,
                  1/*#VTs*/, MVT::i32, 7/*#Ops*/, 5, 7, 0, 8, 9, 10, 11,  // Results = #12
/*28068*/     OPC_EmitInteger, MVT::i32, AMDGPU::sub0,
/*28071*/     OPC_EmitNode, TARGET_VAL(TargetOpcode::INSERT_SUBREG), 0,
                  1/*#VTs*/, MVT::f64, 3/*#Ops*/, 3, 12, 13,  // Results = #14
/*28081*/     OPC_EmitInteger, MVT::i32, AMDGPU::sub1,
/*28084*/     OPC_EmitNode, TARGET_VAL(TargetOpcode::EXTRACT_SUBREG), 0,
                  1/*#VTs*/, MVT::i32, 2/*#Ops*/, 2, 15,  // Results = #16
/*28093*/     OPC_EmitInteger, MVT::i32, AMDGPU::sub1,
/*28096*/     OPC_EmitNode, TARGET_VAL(TargetOpcode::EXTRACT_SUBREG), 0,
                  1/*#VTs*/, MVT::i32, 2/*#Ops*/, 1, 17,  // Results = #18
/*28105*/     OPC_EmitInteger, MVT::i32, 0, 
/*28108*/     OPC_EmitInteger, MVT::i32, 0, 
/*28111*/     OPC_EmitInteger, MVT::i32, 0, 
/*28114*/     OPC_EmitInteger, MVT::i32, 0, 
/*28117*/     OPC_EmitNode, TARGET_VAL(AMDGPU::V_CNDMASK_B32_e64), 0,
                  1/*#VTs*/, MVT::i32, 7/*#Ops*/, 16, 18, 0, 19, 20, 21, 22,  // Results = #23
/*28131*/     OPC_EmitInteger, MVT::i32, AMDGPU::sub1,
/*28134*/     OPC_MorphNodeTo, TARGET_VAL(TargetOpcode::INSERT_SUBREG), 0,
                  1/*#VTs*/, MVT::f64, 3/*#Ops*/, 14, 23, 24, 
              // Src: (select:f64 i1:i1:$src2, f64:f64:$src1, f64:f64:$src0) - Complexity = 3
              // Dst: (INSERT_SUBREG:f64 (INSERT_SUBREG:f64 (IMPLICIT_DEF:f64), (V_CNDMASK_B32_e64:i32 (EXTRACT_SUBREG:i32 ?:f64:$src0, sub0:i32), (EXTRACT_SUBREG:i32 ?:f64:$src1, sub0:i32), ?:i1:$src2), sub0:i32), (V_CNDMASK_B32_e64:i32 (EXTRACT_SUBREG:i32 ?:f64:$src0, sub1:i32), (EXTRACT_SUBREG:i32 ?:f64:$src1, sub1:i32), ?:i1:$src2), sub1:i32)
/*28144*/   0, // EndSwitchType
/*28145*/ /*SwitchOpcode*/ 84,  TARGET_VAL(ISD::TRUNCATE),// ->28232
/*28148*/   OPC_RecordChild0, // #0 = $val
/*28149*/   OPC_SwitchType /*2 cases */, 16,  MVT::i32,// ->28168
/*28152*/     OPC_CheckChild0Type, MVT::i64,
/*28154*/     OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*28156*/     OPC_EmitInteger, MVT::i32, AMDGPU::sub0,
/*28159*/     OPC_MorphNodeTo, TARGET_VAL(TargetOpcode::EXTRACT_SUBREG), 0,
                  1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1, 
              // Src: (trunc:i32 i64:i64:$val) - Complexity = 3
              // Dst: (EXTRACT_SUBREG:i32 ?:i64:$val, sub0:i32)
/*28168*/   /*SwitchType*/ 61,  MVT::i64,// ->28231
/*28170*/     OPC_CheckChild0Type, MVT::i128,
/*28172*/     OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*28174*/     OPC_EmitNode, TARGET_VAL(TargetOpcode::IMPLICIT_DEF), 0,
                  1/*#VTs*/, MVT::i64, 0/*#Ops*/,  // Results = #1
/*28181*/     OPC_EmitInteger, MVT::i32, AMDGPU::sub0,
/*28184*/     OPC_EmitNode, TARGET_VAL(TargetOpcode::EXTRACT_SUBREG), 0,
                  1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 2,  // Results = #3
/*28193*/     OPC_EmitInteger, MVT::i32, AMDGPU::sub0,
/*28196*/     OPC_EmitNode, TARGET_VAL(TargetOpcode::INSERT_SUBREG), 0,
                  1/*#VTs*/, MVT::i64, 3/*#Ops*/, 1, 3, 4,  // Results = #5
/*28206*/     OPC_EmitInteger, MVT::i32, AMDGPU::sub1,
/*28209*/     OPC_EmitNode, TARGET_VAL(TargetOpcode::EXTRACT_SUBREG), 0,
                  1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 6,  // Results = #7
/*28218*/     OPC_EmitInteger, MVT::i32, AMDGPU::sub1,
/*28221*/     OPC_MorphNodeTo, TARGET_VAL(TargetOpcode::INSERT_SUBREG), 0,
                  1/*#VTs*/, MVT::i64, 3/*#Ops*/, 5, 7, 8, 
              // Src: (trunc:i64 i128:i128:$x) - Complexity = 3
              // Dst: (INSERT_SUBREG:i64 (INSERT_SUBREG:i64 (IMPLICIT_DEF:i64), (EXTRACT_SUBREG:i32 ?:i128:$x, sub0:i32), sub0:i32), (EXTRACT_SUBREG:i32 ?:i128:$x, sub1:i32), sub1:i32)
/*28231*/   0, // EndSwitchType
/*28232*/ /*SwitchOpcode*/ 16,  TARGET_VAL(ISD::ADDE),// ->28251
/*28235*/   OPC_CaptureGlueInput,
/*28236*/   OPC_RecordChild0, // #0 = $src0
/*28237*/   OPC_RecordChild1, // #1 = $src1
/*28238*/   OPC_CheckType, MVT::i32,
/*28240*/   OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*28242*/   OPC_MorphNodeTo, TARGET_VAL(AMDGPU::S_ADDC_U32), 0|OPFL_GlueInput|OPFL_GlueOutput,
                1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1, 
            // Src: (adde:i32 SSrc_32:i32:$src0, SSrc_32:i32:$src1) - Complexity = 3
            // Dst: (S_ADDC_U32:i32 SSrc_32:i32:$src0, SSrc_32:i32:$src1)
/*28251*/ /*SwitchOpcode*/ 16,  TARGET_VAL(ISD::SUBE),// ->28270
/*28254*/   OPC_CaptureGlueInput,
/*28255*/   OPC_RecordChild0, // #0 = $src0
/*28256*/   OPC_RecordChild1, // #1 = $src1
/*28257*/   OPC_CheckType, MVT::i32,
/*28259*/   OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*28261*/   OPC_MorphNodeTo, TARGET_VAL(AMDGPU::S_SUBB_U32), 0|OPFL_GlueInput|OPFL_GlueOutput,
                1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1, 
            // Src: (sube:i32 SSrc_32:i32:$src0, SSrc_32:i32:$src1) - Complexity = 3
            // Dst: (S_SUBB_U32:i32 SSrc_32:i32:$src0, SSrc_32:i32:$src1)
/*28270*/ /*SwitchOpcode*/ 48,  TARGET_VAL(ISD::SIGN_EXTEND),// ->28321
/*28273*/   OPC_RecordChild0, // #0 = $src0
/*28274*/   OPC_CheckChild0Type, MVT::i1,
/*28276*/   OPC_CheckType, MVT::i32,
/*28278*/   OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*28280*/   OPC_EmitInteger, MVT::i32, 0, 
/*28283*/   OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*28295*/   OPC_EmitInteger, MVT::i32, 0, 
/*28298*/   OPC_EmitInteger, MVT::i32, 0, 
/*28301*/   OPC_EmitInteger, MVT::i32, 0, 
/*28304*/   OPC_EmitInteger, MVT::i32, 0, 
/*28307*/   OPC_MorphNodeTo, TARGET_VAL(AMDGPU::V_CNDMASK_B32_e64), 0,
                1/*#VTs*/, MVT::i32, 7/*#Ops*/, 1, 2, 0, 3, 4, 5, 6, 
            // Src: (sext:i32 i1:i1:$src0) - Complexity = 3
            // Dst: (V_CNDMASK_B32_e64:i32 0:i32, -1:i32, ?:i1:$src0)
/*28321*/ /*SwitchOpcode*/ 15,  TARGET_VAL(ISD::ADDC),// ->28339
/*28324*/   OPC_RecordChild0, // #0 = $src0
/*28325*/   OPC_RecordChild1, // #1 = $src1
/*28326*/   OPC_CheckType, MVT::i32,
/*28328*/   OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*28330*/   OPC_MorphNodeTo, TARGET_VAL(AMDGPU::S_ADD_I32), 0|OPFL_GlueOutput,
                1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1, 
            // Src: (addc:i32 i32:i32:$src0, i32:i32:$src1) - Complexity = 3
            // Dst: (S_ADD_I32:i32 ?:i32:$src0, ?:i32:$src1)
/*28339*/ /*SwitchOpcode*/ 39,  TARGET_VAL(AMDGPUISD::BRANCH_COND),// ->28381
/*28342*/   OPC_RecordNode,   // #0 = 'IL_brcond' chained node
/*28343*/   OPC_RecordChild1, // #1 = $target
/*28344*/   OPC_MoveChild, 1,
/*28346*/   OPC_CheckOpcode, TARGET_VAL(ISD::BasicBlock),
/*28349*/   OPC_MoveParent,
/*28350*/   OPC_RecordChild2, // #2 = $src0
/*28351*/   OPC_Scope, 13, /*->28366*/ // 2 children in Scope
/*28353*/     OPC_CheckChild2Type, MVT::i32,
/*28355*/     OPC_CheckPatternPredicate, 3, // (Subtarget.getGeneration() <= AMDGPUSubtarget::NORTHERN_ISLANDS)
/*28357*/     OPC_EmitMergeInputChains1_0,
/*28358*/     OPC_MorphNodeTo, TARGET_VAL(AMDGPU::BRANCH_COND_i32), 0|OPFL_Chain,
                  0/*#VTs*/, 2/*#Ops*/, 1, 2, 
              // Src: (IL_brcond (bb:Other):$target, R600_Reg32:i32:$src0) - Complexity = 3
              // Dst: (BRANCH_COND_i32 (bb:Other):$target, R600_Reg32:i32:$src0)
/*28366*/   /*Scope*/ 13, /*->28380*/
/*28367*/     OPC_CheckChild2Type, MVT::f32,
/*28369*/     OPC_CheckPatternPredicate, 3, // (Subtarget.getGeneration() <= AMDGPUSubtarget::NORTHERN_ISLANDS)
/*28371*/     OPC_EmitMergeInputChains1_0,
/*28372*/     OPC_MorphNodeTo, TARGET_VAL(AMDGPU::BRANCH_COND_f32), 0|OPFL_Chain,
                  0/*#VTs*/, 2/*#Ops*/, 1, 2, 
              // Src: (IL_brcond (bb:Other):$target, R600_Reg32:f32:$src0) - Complexity = 3
              // Dst: (BRANCH_COND_f32 (bb:Other):$target, R600_Reg32:f32:$src0)
/*28380*/   0, /*End of Scope*/
/*28381*/ /*SwitchOpcode*/ 55|128,6/*823*/,  TARGET_VAL(ISD::FDIV),// ->29208
/*28385*/   OPC_Scope, 115|128,1/*243*/, /*->28631*/ // 2 children in Scope
/*28388*/     OPC_MoveChild, 0,
/*28390*/     OPC_CheckOpcode, TARGET_VAL(ISD::ConstantFP),
/*28393*/     OPC_CheckPredicate, 6, // Predicate_FP_ONE
/*28395*/     OPC_MoveParent,
/*28396*/     OPC_RecordChild1, // #0 = $src0
/*28397*/     OPC_SwitchType /*2 cases */, 89|128,1/*217*/,  MVT::f32,// ->28618
/*28401*/       OPC_Scope, 67, /*->28470*/ // 4 children in Scope
/*28403*/         OPC_CheckPatternPredicate, 1, // (Subtarget.getGeneration() <= AMDGPUSubtarget::R700)
/*28405*/         OPC_EmitInteger, MVT::i32, 1, 
/*28408*/         OPC_EmitInteger, MVT::i32, 0, 
/*28411*/         OPC_EmitInteger, MVT::i32, 0, 
/*28414*/         OPC_EmitInteger, MVT::i32, 0, 
/*28417*/         OPC_EmitInteger, MVT::i32, 0, 
/*28420*/         OPC_EmitInteger, MVT::i32, 0, 
/*28423*/         OPC_EmitInteger, MVT::i32, 0, 
/*28426*/         OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*28438*/         OPC_EmitInteger, MVT::i32, 1, 
/*28441*/         OPC_EmitRegister, MVT::i32, AMDGPU::PRED_SEL_OFF,
/*28444*/         OPC_EmitInteger, MVT::i32, 0, 
/*28447*/         OPC_EmitInteger, MVT::i32, 0, 
/*28450*/         OPC_MorphNodeTo, TARGET_VAL(AMDGPU::RECIP_IEEE_r600), 0,
                      1/*#VTs*/, MVT::f32, 13/*#Ops*/, 1, 2, 3, 4, 0, 5, 6, 7, 8, 9, 10, 11, 12, 
                  // Src: (fdiv:f32 (fpimm:f32)<<P:Predicate_FP_ONE>>, f32:f32:$src0) - Complexity = 7
                  // Dst: (RECIP_IEEE_r600:f32 f32:f32:$src0)
/*28470*/       /*Scope*/ 67, /*->28538*/
/*28471*/         OPC_CheckPatternPredicate, 5, // (Subtarget.getGeneration() >= AMDGPUSubtarget::EVERGREEN && Subtarget.getGeneration() < AMDGPUSubtarget::SOUTHERN_ISLANDS && !Subtarget.hasCaymanISA())
/*28473*/         OPC_EmitInteger, MVT::i32, 1, 
/*28476*/         OPC_EmitInteger, MVT::i32, 0, 
/*28479*/         OPC_EmitInteger, MVT::i32, 0, 
/*28482*/         OPC_EmitInteger, MVT::i32, 0, 
/*28485*/         OPC_EmitInteger, MVT::i32, 0, 
/*28488*/         OPC_EmitInteger, MVT::i32, 0, 
/*28491*/         OPC_EmitInteger, MVT::i32, 0, 
/*28494*/         OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*28506*/         OPC_EmitInteger, MVT::i32, 1, 
/*28509*/         OPC_EmitRegister, MVT::i32, AMDGPU::PRED_SEL_OFF,
/*28512*/         OPC_EmitInteger, MVT::i32, 0, 
/*28515*/         OPC_EmitInteger, MVT::i32, 0, 
/*28518*/         OPC_MorphNodeTo, TARGET_VAL(AMDGPU::RECIP_IEEE_eg), 0,
                      1/*#VTs*/, MVT::f32, 13/*#Ops*/, 1, 2, 3, 4, 0, 5, 6, 7, 8, 9, 10, 11, 12, 
                  // Src: (fdiv:f32 (fpimm:f32)<<P:Predicate_FP_ONE>>, f32:f32:$src0) - Complexity = 7
                  // Dst: (RECIP_IEEE_eg:f32 f32:f32:$src0)
/*28538*/       /*Scope*/ 67, /*->28606*/
/*28539*/         OPC_CheckPatternPredicate, 4, // (Subtarget.hasCaymanISA())
/*28541*/         OPC_EmitInteger, MVT::i32, 1, 
/*28544*/         OPC_EmitInteger, MVT::i32, 0, 
/*28547*/         OPC_EmitInteger, MVT::i32, 0, 
/*28550*/         OPC_EmitInteger, MVT::i32, 0, 
/*28553*/         OPC_EmitInteger, MVT::i32, 0, 
/*28556*/         OPC_EmitInteger, MVT::i32, 0, 
/*28559*/         OPC_EmitInteger, MVT::i32, 0, 
/*28562*/         OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*28574*/         OPC_EmitInteger, MVT::i32, 1, 
/*28577*/         OPC_EmitRegister, MVT::i32, AMDGPU::PRED_SEL_OFF,
/*28580*/         OPC_EmitInteger, MVT::i32, 0, 
/*28583*/         OPC_EmitInteger, MVT::i32, 0, 
/*28586*/         OPC_MorphNodeTo, TARGET_VAL(AMDGPU::RECIP_IEEE_cm), 0,
                      1/*#VTs*/, MVT::f32, 13/*#Ops*/, 1, 2, 3, 4, 0, 5, 6, 7, 8, 9, 10, 11, 12, 
                  // Src: (fdiv:f32 (fpimm:f32)<<P:Predicate_FP_ONE>>, f32:f32:$src0) - Complexity = 7
                  // Dst: (RECIP_IEEE_cm:f32 f32:f32:$src0)
/*28606*/       /*Scope*/ 10, /*->28617*/
/*28607*/         OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*28609*/         OPC_MorphNodeTo, TARGET_VAL(AMDGPU::V_RCP_F32_e32), 0,
                      1/*#VTs*/, MVT::f32, 1/*#Ops*/, 0, 
                  // Src: (fdiv:f32 (fpimm:f32)<<P:Predicate_FP_ONE>>, f32:f32:$src0) - Complexity = 7
                  // Dst: (V_RCP_F32_e32:f32 f32:f32:$src0)
/*28617*/       0, /*End of Scope*/
/*28618*/     /*SwitchType*/ 10,  MVT::f64,// ->28630
/*28620*/       OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*28622*/       OPC_MorphNodeTo, TARGET_VAL(AMDGPU::V_RCP_F64_e32), 0,
                    1/*#VTs*/, MVT::f64, 1/*#Ops*/, 0, 
                // Src: (fdiv:f64 (fpimm:f64)<<P:Predicate_FP_ONE>>, f64:f64:$src0) - Complexity = 7
                // Dst: (V_RCP_F64_e32:f64 f64:f64:$src0)
/*28630*/     0, // EndSwitchType
/*28631*/   /*Scope*/ 62|128,4/*574*/, /*->29207*/
/*28633*/     OPC_RecordChild0, // #0 = $src0
/*28634*/     OPC_RecordChild1, // #1 = $src1
/*28635*/     OPC_SwitchType /*2 cases */, 14|128,4/*526*/,  MVT::f32,// ->29165
/*28639*/       OPC_Scope, 38|128,1/*166*/, /*->28808*/ // 4 children in Scope
/*28642*/         OPC_CheckPatternPredicate, 1, // (Subtarget.getGeneration() <= AMDGPUSubtarget::R700)
/*28644*/         OPC_EmitInteger, MVT::i32, 0, 
/*28647*/         OPC_EmitInteger, MVT::i32, 0, 
/*28650*/         OPC_EmitInteger, MVT::i32, 1, 
/*28653*/         OPC_EmitInteger, MVT::i32, 0, 
/*28656*/         OPC_EmitInteger, MVT::i32, 0, 
/*28659*/         OPC_EmitInteger, MVT::i32, 0, 
/*28662*/         OPC_EmitInteger, MVT::i32, 0, 
/*28665*/         OPC_EmitInteger, MVT::i32, 0, 
/*28668*/         OPC_EmitInteger, MVT::i32, 0, 
/*28671*/         OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*28683*/         OPC_EmitInteger, MVT::i32, 1, 
/*28686*/         OPC_EmitInteger, MVT::i32, 0, 
/*28689*/         OPC_EmitInteger, MVT::i32, 0, 
/*28692*/         OPC_EmitInteger, MVT::i32, 0, 
/*28695*/         OPC_EmitInteger, MVT::i32, 0, 
/*28698*/         OPC_EmitInteger, MVT::i32, 0, 
/*28701*/         OPC_EmitInteger, MVT::i32, 0, 
/*28704*/         OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*28716*/         OPC_EmitInteger, MVT::i32, 1, 
/*28719*/         OPC_EmitRegister, MVT::i32, AMDGPU::PRED_SEL_OFF,
/*28722*/         OPC_EmitInteger, MVT::i32, 0, 
/*28725*/         OPC_EmitInteger, MVT::i32, 0, 
/*28728*/         OPC_EmitNode, TARGET_VAL(AMDGPU::RECIP_IEEE_r600), 0,
                      1/*#VTs*/, MVT::i32, 13/*#Ops*/, 12, 13, 14, 15, 1, 16, 17, 18, 19, 20, 21, 22, 23,  // Results = #24
/*28748*/         OPC_EmitInteger, MVT::i32, 0, 
/*28751*/         OPC_EmitInteger, MVT::i32, 0, 
/*28754*/         OPC_EmitInteger, MVT::i32, 0, 
/*28757*/         OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*28769*/         OPC_EmitInteger, MVT::i32, 1, 
/*28772*/         OPC_EmitRegister, MVT::i32, AMDGPU::PRED_SEL_OFF,
/*28775*/         OPC_EmitInteger, MVT::i32, 0, 
/*28778*/         OPC_EmitInteger, MVT::i32, 0, 
/*28781*/         OPC_MorphNodeTo, TARGET_VAL(AMDGPU::MUL_IEEE), 0,
                      1/*#VTs*/, MVT::f32, 20/*#Ops*/, 2, 3, 4, 5, 6, 7, 0, 8, 9, 10, 11, 24, 25, 26, 27, 28, 29, 30, 31, 32, 
                  // Src: (fdiv:f32 f32:f32:$src0, f32:f32:$src1) - Complexity = 3
                  // Dst: (MUL_IEEE:f32 ?:f32:$src0, (RECIP_IEEE_r600:i32 ?:f32:$src1))
/*28808*/       /*Scope*/ 38|128,1/*166*/, /*->28976*/
/*28810*/         OPC_CheckPatternPredicate, 5, // (Subtarget.getGeneration() >= AMDGPUSubtarget::EVERGREEN && Subtarget.getGeneration() < AMDGPUSubtarget::SOUTHERN_ISLANDS && !Subtarget.hasCaymanISA())
/*28812*/         OPC_EmitInteger, MVT::i32, 0, 
/*28815*/         OPC_EmitInteger, MVT::i32, 0, 
/*28818*/         OPC_EmitInteger, MVT::i32, 1, 
/*28821*/         OPC_EmitInteger, MVT::i32, 0, 
/*28824*/         OPC_EmitInteger, MVT::i32, 0, 
/*28827*/         OPC_EmitInteger, MVT::i32, 0, 
/*28830*/         OPC_EmitInteger, MVT::i32, 0, 
/*28833*/         OPC_EmitInteger, MVT::i32, 0, 
/*28836*/         OPC_EmitInteger, MVT::i32, 0, 
/*28839*/         OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*28851*/         OPC_EmitInteger, MVT::i32, 1, 
/*28854*/         OPC_EmitInteger, MVT::i32, 0, 
/*28857*/         OPC_EmitInteger, MVT::i32, 0, 
/*28860*/         OPC_EmitInteger, MVT::i32, 0, 
/*28863*/         OPC_EmitInteger, MVT::i32, 0, 
/*28866*/         OPC_EmitInteger, MVT::i32, 0, 
/*28869*/         OPC_EmitInteger, MVT::i32, 0, 
/*28872*/         OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*28884*/         OPC_EmitInteger, MVT::i32, 1, 
/*28887*/         OPC_EmitRegister, MVT::i32, AMDGPU::PRED_SEL_OFF,
/*28890*/         OPC_EmitInteger, MVT::i32, 0, 
/*28893*/         OPC_EmitInteger, MVT::i32, 0, 
/*28896*/         OPC_EmitNode, TARGET_VAL(AMDGPU::RECIP_IEEE_eg), 0,
                      1/*#VTs*/, MVT::i32, 13/*#Ops*/, 12, 13, 14, 15, 1, 16, 17, 18, 19, 20, 21, 22, 23,  // Results = #24
/*28916*/         OPC_EmitInteger, MVT::i32, 0, 
/*28919*/         OPC_EmitInteger, MVT::i32, 0, 
/*28922*/         OPC_EmitInteger, MVT::i32, 0, 
/*28925*/         OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*28937*/         OPC_EmitInteger, MVT::i32, 1, 
/*28940*/         OPC_EmitRegister, MVT::i32, AMDGPU::PRED_SEL_OFF,
/*28943*/         OPC_EmitInteger, MVT::i32, 0, 
/*28946*/         OPC_EmitInteger, MVT::i32, 0, 
/*28949*/         OPC_MorphNodeTo, TARGET_VAL(AMDGPU::MUL_IEEE), 0,
                      1/*#VTs*/, MVT::f32, 20/*#Ops*/, 2, 3, 4, 5, 6, 7, 0, 8, 9, 10, 11, 24, 25, 26, 27, 28, 29, 30, 31, 32, 
                  // Src: (fdiv:f32 f32:f32:$src0, f32:f32:$src1) - Complexity = 3
                  // Dst: (MUL_IEEE:f32 ?:f32:$src0, (RECIP_IEEE_eg:i32 ?:f32:$src1))
/*28976*/       /*Scope*/ 38|128,1/*166*/, /*->29144*/
/*28978*/         OPC_CheckPatternPredicate, 4, // (Subtarget.hasCaymanISA())
/*28980*/         OPC_EmitInteger, MVT::i32, 0, 
/*28983*/         OPC_EmitInteger, MVT::i32, 0, 
/*28986*/         OPC_EmitInteger, MVT::i32, 1, 
/*28989*/         OPC_EmitInteger, MVT::i32, 0, 
/*28992*/         OPC_EmitInteger, MVT::i32, 0, 
/*28995*/         OPC_EmitInteger, MVT::i32, 0, 
/*28998*/         OPC_EmitInteger, MVT::i32, 0, 
/*29001*/         OPC_EmitInteger, MVT::i32, 0, 
/*29004*/         OPC_EmitInteger, MVT::i32, 0, 
/*29007*/         OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*29019*/         OPC_EmitInteger, MVT::i32, 1, 
/*29022*/         OPC_EmitInteger, MVT::i32, 0, 
/*29025*/         OPC_EmitInteger, MVT::i32, 0, 
/*29028*/         OPC_EmitInteger, MVT::i32, 0, 
/*29031*/         OPC_EmitInteger, MVT::i32, 0, 
/*29034*/         OPC_EmitInteger, MVT::i32, 0, 
/*29037*/         OPC_EmitInteger, MVT::i32, 0, 
/*29040*/         OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*29052*/         OPC_EmitInteger, MVT::i32, 1, 
/*29055*/         OPC_EmitRegister, MVT::i32, AMDGPU::PRED_SEL_OFF,
/*29058*/         OPC_EmitInteger, MVT::i32, 0, 
/*29061*/         OPC_EmitInteger, MVT::i32, 0, 
/*29064*/         OPC_EmitNode, TARGET_VAL(AMDGPU::RECIP_IEEE_cm), 0,
                      1/*#VTs*/, MVT::i32, 13/*#Ops*/, 12, 13, 14, 15, 1, 16, 17, 18, 19, 20, 21, 22, 23,  // Results = #24
/*29084*/         OPC_EmitInteger, MVT::i32, 0, 
/*29087*/         OPC_EmitInteger, MVT::i32, 0, 
/*29090*/         OPC_EmitInteger, MVT::i32, 0, 
/*29093*/         OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*29105*/         OPC_EmitInteger, MVT::i32, 1, 
/*29108*/         OPC_EmitRegister, MVT::i32, AMDGPU::PRED_SEL_OFF,
/*29111*/         OPC_EmitInteger, MVT::i32, 0, 
/*29114*/         OPC_EmitInteger, MVT::i32, 0, 
/*29117*/         OPC_MorphNodeTo, TARGET_VAL(AMDGPU::MUL_IEEE), 0,
                      1/*#VTs*/, MVT::f32, 20/*#Ops*/, 2, 3, 4, 5, 6, 7, 0, 8, 9, 10, 11, 24, 25, 26, 27, 28, 29, 30, 31, 32, 
                  // Src: (fdiv:f32 f32:f32:$src0, f32:f32:$src1) - Complexity = 3
                  // Dst: (MUL_IEEE:f32 ?:f32:$src0, (RECIP_IEEE_cm:i32 ?:f32:$src1))
/*29144*/       /*Scope*/ 19, /*->29164*/
/*29145*/         OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*29147*/         OPC_EmitNode, TARGET_VAL(AMDGPU::V_RCP_F32_e32), 0,
                      1/*#VTs*/, MVT::i32, 1/*#Ops*/, 1,  // Results = #2
/*29155*/         OPC_MorphNodeTo, TARGET_VAL(AMDGPU::V_MUL_F32_e32), 0,
                      1/*#VTs*/, MVT::f32, 2/*#Ops*/, 0, 2, 
                  // Src: (fdiv:f32 f32:f32:$src0, f32:f32:$src1) - Complexity = 3
                  // Dst: (V_MUL_F32_e32:f32 ?:f32:$src0, (V_RCP_F32_e32:i32 ?:f32:$src1))
/*29164*/       0, /*End of Scope*/
/*29165*/     /*SwitchType*/ 39,  MVT::f64,// ->29206
/*29167*/       OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*29169*/       OPC_EmitNode, TARGET_VAL(AMDGPU::V_RCP_F64_e32), 0,
                    1/*#VTs*/, MVT::i64, 1/*#Ops*/, 1,  // Results = #2
/*29177*/       OPC_EmitInteger, MVT::i64, 0, 
/*29180*/       OPC_EmitInteger, MVT::i32, 0, 
/*29183*/       OPC_EmitInteger, MVT::i32, 0, 
/*29186*/       OPC_EmitInteger, MVT::i32, 0, 
/*29189*/       OPC_EmitInteger, MVT::i32, 0, 
/*29192*/       OPC_MorphNodeTo, TARGET_VAL(AMDGPU::V_MUL_F64), 0,
                    1/*#VTs*/, MVT::f64, 7/*#Ops*/, 0, 2, 3, 4, 5, 6, 7, 
                // Src: (fdiv:f64 f64:f64:$src0, f64:f64:$src1) - Complexity = 3
                // Dst: (V_MUL_F64:f64 ?:f64:$src0, (V_RCP_F64_e32:i64 ?:f64:$src1), 0:i64)
/*29206*/     0, // EndSwitchType
/*29207*/   0, /*End of Scope*/
/*29208*/ /*SwitchOpcode*/ 68,  TARGET_VAL(AMDGPUISD::LOAD_CONSTANT),// ->29279
/*29211*/   OPC_RecordMemRef,
/*29212*/   OPC_RecordChild0, // #0 = $sbase
/*29213*/   OPC_RecordChild1, // #1 = $offset
/*29214*/   OPC_Scope, 50, /*->29266*/ // 2 children in Scope
/*29216*/     OPC_MoveChild, 1,
/*29218*/     OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*29221*/     OPC_Scope, 19, /*->29242*/ // 2 children in Scope
/*29223*/       OPC_CheckPredicate, 22, // Predicate_IMM8bitDWORD
/*29225*/       OPC_MoveParent,
/*29226*/       OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*29228*/       OPC_EmitConvertToTarget, 1,
/*29230*/       OPC_EmitNodeXForm, 3, 2, // anonymous.val.459
/*29233*/       OPC_MorphNodeTo, TARGET_VAL(AMDGPU::S_BUFFER_LOAD_DWORD_IMM), 0|OPFL_MemRefs,
                    1/*#VTs*/, MVT::f32, 2/*#Ops*/, 0, 3, 
                // Src: (SIload_constant:f32 i128:i128:$sbase, (imm:i32)<<P:Predicate_IMM8bitDWORD>><<X:anonymous.val.459>>:$offset) - Complexity = 7
                // Dst: (S_BUFFER_LOAD_DWORD_IMM:f32 ?:i128:$sbase, (anonymous.val.459:i32 (imm:i32)<<P:Predicate_IMM8bitDWORD>>:$offset))
/*29242*/     /*Scope*/ 22, /*->29265*/
/*29243*/       OPC_MoveParent,
/*29244*/       OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*29246*/       OPC_EmitConvertToTarget, 1,
/*29248*/       OPC_EmitNode, TARGET_VAL(AMDGPU::S_MOV_B32), 0,
                    1/*#VTs*/, MVT::i32, 1/*#Ops*/, 2,  // Results = #3
/*29256*/       OPC_MorphNodeTo, TARGET_VAL(AMDGPU::S_BUFFER_LOAD_DWORD_SGPR), 0|OPFL_MemRefs,
                    1/*#VTs*/, MVT::f32, 2/*#Ops*/, 0, 3, 
                // Src: (SIload_constant:f32 i128:i128:$sbase, (imm:i32):$offset) - Complexity = 6
                // Dst: (S_BUFFER_LOAD_DWORD_SGPR:f32 ?:i128:$sbase, (S_MOV_B32:i32 (imm:i32):$offset))
/*29265*/     0, /*End of Scope*/
/*29266*/   /*Scope*/ 11, /*->29278*/
/*29267*/     OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*29269*/     OPC_MorphNodeTo, TARGET_VAL(AMDGPU::BUFFER_LOAD_DWORD_OFFEN), 0|OPFL_MemRefs,
                  1/*#VTs*/, MVT::f32, 2/*#Ops*/, 0, 1, 
              // Src: (SIload_constant:f32 i128:i128:$sbase, i32:i32:$voff) - Complexity = 3
              // Dst: (BUFFER_LOAD_DWORD_OFFEN:f32 ?:i128:$sbase, ?:i32:$voff)
/*29278*/   0, /*End of Scope*/
/*29279*/ /*SwitchOpcode*/ 10|128,5/*650*/,  TARGET_VAL(ISD::FADD),// ->29933
/*29283*/   OPC_Scope, 114|128,1/*242*/, /*->29528*/ // 2 children in Scope
/*29286*/     OPC_MoveChild, 0,
/*29288*/     OPC_CheckOpcode, TARGET_VAL(ISD::FMUL),
/*29291*/     OPC_RecordChild0, // #0 = $src0
/*29292*/     OPC_RecordChild1, // #1 = $src1
/*29293*/     OPC_MoveParent,
/*29294*/     OPC_RecordChild1, // #2 = $src2
/*29295*/     OPC_CheckType, MVT::f32,
/*29297*/     OPC_Scope, 99, /*->29398*/ // 3 children in Scope
/*29299*/       OPC_CheckPatternPredicate, 1, // (Subtarget.getGeneration() <= AMDGPUSubtarget::R700)
/*29301*/       OPC_EmitInteger, MVT::i32, 0, 
/*29304*/       OPC_EmitInteger, MVT::i32, 0, 
/*29307*/       OPC_EmitInteger, MVT::i32, 0, 
/*29310*/       OPC_EmitInteger, MVT::i32, 0, 
/*29313*/       OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*29325*/       OPC_EmitInteger, MVT::i32, 0, 
/*29328*/       OPC_EmitInteger, MVT::i32, 0, 
/*29331*/       OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*29343*/       OPC_EmitInteger, MVT::i32, 0, 
/*29346*/       OPC_EmitInteger, MVT::i32, 0, 
/*29349*/       OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*29361*/       OPC_EmitInteger, MVT::i32, 1, 
/*29364*/       OPC_EmitRegister, MVT::i32, AMDGPU::PRED_SEL_OFF,
/*29367*/       OPC_EmitInteger, MVT::i32, 0, 
/*29370*/       OPC_EmitInteger, MVT::i32, 0, 
/*29373*/       OPC_MorphNodeTo, TARGET_VAL(AMDGPU::MULADD_IEEE_r600), 0,
                    1/*#VTs*/, MVT::f32, 18/*#Ops*/, 3, 4, 0, 5, 6, 7, 1, 8, 9, 10, 2, 11, 12, 13, 14, 15, 16, 17, 
                // Src: (fadd:f32 (fmul:f32 f32:f32:$src0, f32:f32:$src1), f32:f32:$src2) - Complexity = 6
                // Dst: (MULADD_IEEE_r600:f32 f32:f32:$src0, f32:f32:$src1, f32:f32:$src2)
/*29398*/     /*Scope*/ 99, /*->29498*/
/*29399*/       OPC_CheckPatternPredicate, 2, // (Subtarget.getGeneration() == AMDGPUSubtarget::EVERGREEN|| Subtarget.getGeneration() ==AMDGPUSubtarget::NORTHERN_ISLANDS)
/*29401*/       OPC_EmitInteger, MVT::i32, 0, 
/*29404*/       OPC_EmitInteger, MVT::i32, 0, 
/*29407*/       OPC_EmitInteger, MVT::i32, 0, 
/*29410*/       OPC_EmitInteger, MVT::i32, 0, 
/*29413*/       OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*29425*/       OPC_EmitInteger, MVT::i32, 0, 
/*29428*/       OPC_EmitInteger, MVT::i32, 0, 
/*29431*/       OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*29443*/       OPC_EmitInteger, MVT::i32, 0, 
/*29446*/       OPC_EmitInteger, MVT::i32, 0, 
/*29449*/       OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*29461*/       OPC_EmitInteger, MVT::i32, 1, 
/*29464*/       OPC_EmitRegister, MVT::i32, AMDGPU::PRED_SEL_OFF,
/*29467*/       OPC_EmitInteger, MVT::i32, 0, 
/*29470*/       OPC_EmitInteger, MVT::i32, 0, 
/*29473*/       OPC_MorphNodeTo, TARGET_VAL(AMDGPU::MULADD_IEEE_eg), 0,
                    1/*#VTs*/, MVT::f32, 18/*#Ops*/, 3, 4, 0, 5, 6, 7, 1, 8, 9, 10, 2, 11, 12, 13, 14, 15, 16, 17, 
                // Src: (fadd:f32 (fmul:f32 f32:f32:$src0, f32:f32:$src1), f32:f32:$src2) - Complexity = 6
                // Dst: (MULADD_IEEE_eg:f32 f32:f32:$src0, f32:f32:$src1, f32:f32:$src2)
/*29498*/     /*Scope*/ 28, /*->29527*/
/*29499*/       OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*29501*/       OPC_EmitInteger, MVT::i32, 0, 
/*29504*/       OPC_EmitInteger, MVT::i32, 0, 
/*29507*/       OPC_EmitInteger, MVT::i32, 0, 
/*29510*/       OPC_EmitInteger, MVT::i32, 0, 
/*29513*/       OPC_MorphNodeTo, TARGET_VAL(AMDGPU::V_MAD_F32), 0,
                    1/*#VTs*/, MVT::f32, 7/*#Ops*/, 0, 1, 2, 3, 4, 5, 6, 
                // Src: (fadd:f32 (fmul:f32 f32:f32:$src0, f32:f32:$src1), f32:f32:$src2) - Complexity = 6
                // Dst: (V_MAD_F32:f32 ?:f32:$src0, ?:f32:$src1, ?:f32:$src2)
/*29527*/     0, /*End of Scope*/
/*29528*/   /*Scope*/ 18|128,3/*402*/, /*->29932*/
/*29530*/     OPC_RecordChild0, // #0 = $src2
/*29531*/     OPC_Scope, 113|128,1/*241*/, /*->29775*/ // 2 children in Scope
/*29534*/       OPC_MoveChild, 1,
/*29536*/       OPC_CheckOpcode, TARGET_VAL(ISD::FMUL),
/*29539*/       OPC_RecordChild0, // #1 = $src0
/*29540*/       OPC_RecordChild1, // #2 = $src1
/*29541*/       OPC_MoveParent,
/*29542*/       OPC_CheckType, MVT::f32,
/*29544*/       OPC_Scope, 99, /*->29645*/ // 3 children in Scope
/*29546*/         OPC_CheckPatternPredicate, 1, // (Subtarget.getGeneration() <= AMDGPUSubtarget::R700)
/*29548*/         OPC_EmitInteger, MVT::i32, 0, 
/*29551*/         OPC_EmitInteger, MVT::i32, 0, 
/*29554*/         OPC_EmitInteger, MVT::i32, 0, 
/*29557*/         OPC_EmitInteger, MVT::i32, 0, 
/*29560*/         OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*29572*/         OPC_EmitInteger, MVT::i32, 0, 
/*29575*/         OPC_EmitInteger, MVT::i32, 0, 
/*29578*/         OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*29590*/         OPC_EmitInteger, MVT::i32, 0, 
/*29593*/         OPC_EmitInteger, MVT::i32, 0, 
/*29596*/         OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*29608*/         OPC_EmitInteger, MVT::i32, 1, 
/*29611*/         OPC_EmitRegister, MVT::i32, AMDGPU::PRED_SEL_OFF,
/*29614*/         OPC_EmitInteger, MVT::i32, 0, 
/*29617*/         OPC_EmitInteger, MVT::i32, 0, 
/*29620*/         OPC_MorphNodeTo, TARGET_VAL(AMDGPU::MULADD_IEEE_r600), 0,
                      1/*#VTs*/, MVT::f32, 18/*#Ops*/, 3, 4, 1, 5, 6, 7, 2, 8, 9, 10, 0, 11, 12, 13, 14, 15, 16, 17, 
                  // Src: (fadd:f32 f32:f32:$src2, (fmul:f32 f32:f32:$src0, f32:f32:$src1)) - Complexity = 6
                  // Dst: (MULADD_IEEE_r600:f32 f32:f32:$src0, f32:f32:$src1, f32:f32:$src2)
/*29645*/       /*Scope*/ 99, /*->29745*/
/*29646*/         OPC_CheckPatternPredicate, 2, // (Subtarget.getGeneration() == AMDGPUSubtarget::EVERGREEN|| Subtarget.getGeneration() ==AMDGPUSubtarget::NORTHERN_ISLANDS)
/*29648*/         OPC_EmitInteger, MVT::i32, 0, 
/*29651*/         OPC_EmitInteger, MVT::i32, 0, 
/*29654*/         OPC_EmitInteger, MVT::i32, 0, 
/*29657*/         OPC_EmitInteger, MVT::i32, 0, 
/*29660*/         OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*29672*/         OPC_EmitInteger, MVT::i32, 0, 
/*29675*/         OPC_EmitInteger, MVT::i32, 0, 
/*29678*/         OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*29690*/         OPC_EmitInteger, MVT::i32, 0, 
/*29693*/         OPC_EmitInteger, MVT::i32, 0, 
/*29696*/         OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*29708*/         OPC_EmitInteger, MVT::i32, 1, 
/*29711*/         OPC_EmitRegister, MVT::i32, AMDGPU::PRED_SEL_OFF,
/*29714*/         OPC_EmitInteger, MVT::i32, 0, 
/*29717*/         OPC_EmitInteger, MVT::i32, 0, 
/*29720*/         OPC_MorphNodeTo, TARGET_VAL(AMDGPU::MULADD_IEEE_eg), 0,
                      1/*#VTs*/, MVT::f32, 18/*#Ops*/, 3, 4, 1, 5, 6, 7, 2, 8, 9, 10, 0, 11, 12, 13, 14, 15, 16, 17, 
                  // Src: (fadd:f32 f32:f32:$src2, (fmul:f32 f32:f32:$src0, f32:f32:$src1)) - Complexity = 6
                  // Dst: (MULADD_IEEE_eg:f32 f32:f32:$src0, f32:f32:$src1, f32:f32:$src2)
/*29745*/       /*Scope*/ 28, /*->29774*/
/*29746*/         OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*29748*/         OPC_EmitInteger, MVT::i32, 0, 
/*29751*/         OPC_EmitInteger, MVT::i32, 0, 
/*29754*/         OPC_EmitInteger, MVT::i32, 0, 
/*29757*/         OPC_EmitInteger, MVT::i32, 0, 
/*29760*/         OPC_MorphNodeTo, TARGET_VAL(AMDGPU::V_MAD_F32), 0,
                      1/*#VTs*/, MVT::f32, 7/*#Ops*/, 1, 2, 0, 3, 4, 5, 6, 
                  // Src: (fadd:f32 f32:f32:$src2, (fmul:f32 f32:f32:$src0, f32:f32:$src1)) - Complexity = 6
                  // Dst: (V_MAD_F32:f32 ?:f32:$src0, ?:f32:$src1, ?:f32:$src2)
/*29774*/       0, /*End of Scope*/
/*29775*/     /*Scope*/ 26|128,1/*154*/, /*->29931*/
/*29777*/       OPC_RecordChild1, // #1 = $src1
/*29778*/       OPC_SwitchType /*2 cases */, 116,  MVT::f32,// ->29897
/*29781*/         OPC_Scope, 101, /*->29884*/ // 2 children in Scope
/*29783*/           OPC_CheckPatternPredicate, 3, // (Subtarget.getGeneration() <= AMDGPUSubtarget::NORTHERN_ISLANDS)
/*29785*/           OPC_EmitInteger, MVT::i32, 0, 
/*29788*/           OPC_EmitInteger, MVT::i32, 0, 
/*29791*/           OPC_EmitInteger, MVT::i32, 1, 
/*29794*/           OPC_EmitInteger, MVT::i32, 0, 
/*29797*/           OPC_EmitInteger, MVT::i32, 0, 
/*29800*/           OPC_EmitInteger, MVT::i32, 0, 
/*29803*/           OPC_EmitInteger, MVT::i32, 0, 
/*29806*/           OPC_EmitInteger, MVT::i32, 0, 
/*29809*/           OPC_EmitInteger, MVT::i32, 0, 
/*29812*/           OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*29824*/           OPC_EmitInteger, MVT::i32, 0, 
/*29827*/           OPC_EmitInteger, MVT::i32, 0, 
/*29830*/           OPC_EmitInteger, MVT::i32, 0, 
/*29833*/           OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*29845*/           OPC_EmitInteger, MVT::i32, 1, 
/*29848*/           OPC_EmitRegister, MVT::i32, AMDGPU::PRED_SEL_OFF,
/*29851*/           OPC_EmitInteger, MVT::i32, 0, 
/*29854*/           OPC_EmitInteger, MVT::i32, 0, 
/*29857*/           OPC_MorphNodeTo, TARGET_VAL(AMDGPU::ADD), 0,
                        1/*#VTs*/, MVT::f32, 20/*#Ops*/, 2, 3, 4, 5, 6, 7, 0, 8, 9, 10, 11, 1, 12, 13, 14, 15, 16, 17, 18, 19, 
                    // Src: (fadd:f32 R600_Reg32:f32:$src0, R600_Reg32:f32:$src1) - Complexity = 3
                    // Dst: (ADD:f32 R600_Reg32:f32:$src0, R600_Reg32:f32:$src1)
/*29884*/         /*Scope*/ 11, /*->29896*/
/*29885*/           OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*29887*/           OPC_MorphNodeTo, TARGET_VAL(AMDGPU::V_ADD_F32_e32), 0,
                        1/*#VTs*/, MVT::f32, 2/*#Ops*/, 0, 1, 
                    // Src: (fadd:f32 f32:f32:$src0, f32:f32:$src1) - Complexity = 3
                    // Dst: (V_ADD_F32_e32:f32 f32:f32:$src0, f32:f32:$src1)
/*29896*/         0, /*End of Scope*/
/*29897*/       /*SwitchType*/ 31,  MVT::f64,// ->29930
/*29899*/         OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*29901*/         OPC_EmitInteger, MVT::i64, 0, 
/*29904*/         OPC_EmitInteger, MVT::i32, 0, 
/*29907*/         OPC_EmitInteger, MVT::i32, 0, 
/*29910*/         OPC_EmitInteger, MVT::i32, 0, 
/*29913*/         OPC_EmitInteger, MVT::i32, 0, 
/*29916*/         OPC_MorphNodeTo, TARGET_VAL(AMDGPU::V_ADD_F64), 0,
                      1/*#VTs*/, MVT::f64, 7/*#Ops*/, 0, 1, 2, 3, 4, 5, 6, 
                  // Src: (fadd:f64 f64:f64:$src0, f64:f64:$src1) - Complexity = 3
                  // Dst: (V_ADD_F64:f64 ?:f64:$src0, ?:f64:$src1, 0:i64)
/*29930*/       0, // EndSwitchType
/*29931*/     0, /*End of Scope*/
/*29932*/   0, /*End of Scope*/
/*29933*/ /*SwitchOpcode*/ 114,  TARGET_VAL(ISD::ConstantFP),// ->30050
/*29936*/   OPC_RecordNode,   // #0 = $imm
/*29937*/   OPC_SwitchType /*2 cases */, 46,  MVT::f32,// ->29986
/*29940*/     OPC_Scope, 14, /*->29956*/ // 2 children in Scope
/*29942*/       OPC_CheckPredicate, 73, // Predicate_anonymous.val.461
/*29944*/       OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*29946*/       OPC_EmitConvertToTarget, 0,
/*29948*/       OPC_MorphNodeTo, TARGET_VAL(AMDGPU::S_MOV_B32), 0,
                    1/*#VTs*/, MVT::f32, 1/*#Ops*/, 1, 
                // Src: (fpimm:f32)<<P:Predicate_anonymous.val.461>>:$imm - Complexity = 4
                // Dst: (S_MOV_B32:f32 (fpimm:f32):$imm)
/*29956*/     /*Scope*/ 28, /*->29985*/
/*29957*/       OPC_Scope, 12, /*->29971*/ // 2 children in Scope
/*29959*/         OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*29961*/         OPC_EmitConvertToTarget, 0,
/*29963*/         OPC_MorphNodeTo, TARGET_VAL(AMDGPU::V_MOV_B32_e32), 0,
                      1/*#VTs*/, MVT::f32, 1/*#Ops*/, 1, 
                  // Src: (fpimm:f32):$imm - Complexity = 3
                  // Dst: (V_MOV_B32_e32:f32 (fpimm:f32):$imm)
/*29971*/       /*Scope*/ 12, /*->29984*/
/*29972*/         OPC_CheckPatternPredicate, 3, // (Subtarget.getGeneration() <= AMDGPUSubtarget::NORTHERN_ISLANDS)
/*29974*/         OPC_EmitConvertToTarget, 0,
/*29976*/         OPC_MorphNodeTo, TARGET_VAL(AMDGPU::MOV_IMM_F32), 0,
                      1/*#VTs*/, MVT::f32, 1/*#Ops*/, 1, 
                  // Src: (fpimm:f32):$val - Complexity = 3
                  // Dst: (MOV_IMM_F32:f32 (fpimm:f32):$val)
/*29984*/       0, /*End of Scope*/
/*29985*/     0, /*End of Scope*/
/*29986*/   /*SwitchType*/ 61,  MVT::f64,// ->30049
/*29988*/     OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*29990*/     OPC_EmitNode, TARGET_VAL(TargetOpcode::IMPLICIT_DEF), 0,
                  1/*#VTs*/, MVT::f64, 0/*#Ops*/,  // Results = #1
/*29997*/     OPC_EmitConvertToTarget, 0,
/*29999*/     OPC_EmitNodeXForm, 6, 2, // LO32f
/*30002*/     OPC_EmitNode, TARGET_VAL(AMDGPU::V_MOV_B32_e32), 0,
                  1/*#VTs*/, MVT::i32, 1/*#Ops*/, 3,  // Results = #4
/*30010*/     OPC_EmitInteger, MVT::i32, AMDGPU::sub0,
/*30013*/     OPC_EmitNode, TARGET_VAL(TargetOpcode::INSERT_SUBREG), 0,
                  1/*#VTs*/, MVT::f64, 3/*#Ops*/, 1, 4, 5,  // Results = #6
/*30023*/     OPC_EmitConvertToTarget, 0,
/*30025*/     OPC_EmitNodeXForm, 7, 7, // HI32f
/*30028*/     OPC_EmitNode, TARGET_VAL(AMDGPU::V_MOV_B32_e32), 0,
                  1/*#VTs*/, MVT::i32, 1/*#Ops*/, 8,  // Results = #9
/*30036*/     OPC_EmitInteger, MVT::i32, AMDGPU::sub1,
/*30039*/     OPC_MorphNodeTo, TARGET_VAL(TargetOpcode::INSERT_SUBREG), 0,
                  1/*#VTs*/, MVT::f64, 3/*#Ops*/, 6, 9, 10, 
              // Src: (fpimm:f64):$imm - Complexity = 3
              // Dst: (INSERT_SUBREG:f64 (INSERT_SUBREG:f64 (IMPLICIT_DEF:f64), (V_MOV_B32_e32:i32 (LO32f:f32 (fpimm:f64):$imm)), sub0:i32), (V_MOV_B32_e32:i32 (HI32f:f32 (fpimm:f64):$imm)), sub1:i32)
/*30049*/   0, // EndSwitchType
/*30050*/ /*SwitchOpcode*/ 27|128,1/*155*/,  TARGET_VAL(ISD::FMUL),// ->30209
/*30054*/   OPC_RecordChild0, // #0 = $src0
/*30055*/   OPC_RecordChild1, // #1 = $src1
/*30056*/   OPC_SwitchType /*2 cases */, 116,  MVT::f32,// ->30175
/*30059*/     OPC_Scope, 101, /*->30162*/ // 2 children in Scope
/*30061*/       OPC_CheckPatternPredicate, 3, // (Subtarget.getGeneration() <= AMDGPUSubtarget::NORTHERN_ISLANDS)
/*30063*/       OPC_EmitInteger, MVT::i32, 0, 
/*30066*/       OPC_EmitInteger, MVT::i32, 0, 
/*30069*/       OPC_EmitInteger, MVT::i32, 1, 
/*30072*/       OPC_EmitInteger, MVT::i32, 0, 
/*30075*/       OPC_EmitInteger, MVT::i32, 0, 
/*30078*/       OPC_EmitInteger, MVT::i32, 0, 
/*30081*/       OPC_EmitInteger, MVT::i32, 0, 
/*30084*/       OPC_EmitInteger, MVT::i32, 0, 
/*30087*/       OPC_EmitInteger, MVT::i32, 0, 
/*30090*/       OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*30102*/       OPC_EmitInteger, MVT::i32, 0, 
/*30105*/       OPC_EmitInteger, MVT::i32, 0, 
/*30108*/       OPC_EmitInteger, MVT::i32, 0, 
/*30111*/       OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*30123*/       OPC_EmitInteger, MVT::i32, 1, 
/*30126*/       OPC_EmitRegister, MVT::i32, AMDGPU::PRED_SEL_OFF,
/*30129*/       OPC_EmitInteger, MVT::i32, 0, 
/*30132*/       OPC_EmitInteger, MVT::i32, 0, 
/*30135*/       OPC_MorphNodeTo, TARGET_VAL(AMDGPU::MUL_IEEE), 0,
                    1/*#VTs*/, MVT::f32, 20/*#Ops*/, 2, 3, 4, 5, 6, 7, 0, 8, 9, 10, 11, 1, 12, 13, 14, 15, 16, 17, 18, 19, 
                // Src: (fmul:f32 R600_Reg32:f32:$src0, R600_Reg32:f32:$src1) - Complexity = 3
                // Dst: (MUL_IEEE:f32 R600_Reg32:f32:$src0, R600_Reg32:f32:$src1)
/*30162*/     /*Scope*/ 11, /*->30174*/
/*30163*/       OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*30165*/       OPC_MorphNodeTo, TARGET_VAL(AMDGPU::V_MUL_F32_e32), 0,
                    1/*#VTs*/, MVT::f32, 2/*#Ops*/, 0, 1, 
                // Src: (fmul:f32 f32:f32:$src0, f32:f32:$src1) - Complexity = 3
                // Dst: (V_MUL_F32_e32:f32 f32:f32:$src0, f32:f32:$src1)
/*30174*/     0, /*End of Scope*/
/*30175*/   /*SwitchType*/ 31,  MVT::f64,// ->30208
/*30177*/     OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*30179*/     OPC_EmitInteger, MVT::i64, 0, 
/*30182*/     OPC_EmitInteger, MVT::i32, 0, 
/*30185*/     OPC_EmitInteger, MVT::i32, 0, 
/*30188*/     OPC_EmitInteger, MVT::i32, 0, 
/*30191*/     OPC_EmitInteger, MVT::i32, 0, 
/*30194*/     OPC_MorphNodeTo, TARGET_VAL(AMDGPU::V_MUL_F64), 0,
                  1/*#VTs*/, MVT::f64, 7/*#Ops*/, 0, 1, 2, 3, 4, 5, 6, 
              // Src: (fmul:f64 f64:f64:$src0, f64:f64:$src1) - Complexity = 3
              // Dst: (V_MUL_F64:f64 ?:f64:$src0, ?:f64:$src1, 0:i64)
/*30208*/   0, // EndSwitchType
/*30209*/ /*SwitchOpcode*/ 120,  TARGET_VAL(AMDGPUISD::FMAX),// ->30332
/*30212*/   OPC_RecordChild0, // #0 = $src0
/*30213*/   OPC_RecordChild1, // #1 = $src1
/*30214*/   OPC_CheckType, MVT::f32,
/*30216*/   OPC_Scope, 101, /*->30319*/ // 2 children in Scope
/*30218*/     OPC_CheckPatternPredicate, 3, // (Subtarget.getGeneration() <= AMDGPUSubtarget::NORTHERN_ISLANDS)
/*30220*/     OPC_EmitInteger, MVT::i32, 0, 
/*30223*/     OPC_EmitInteger, MVT::i32, 0, 
/*30226*/     OPC_EmitInteger, MVT::i32, 1, 
/*30229*/     OPC_EmitInteger, MVT::i32, 0, 
/*30232*/     OPC_EmitInteger, MVT::i32, 0, 
/*30235*/     OPC_EmitInteger, MVT::i32, 0, 
/*30238*/     OPC_EmitInteger, MVT::i32, 0, 
/*30241*/     OPC_EmitInteger, MVT::i32, 0, 
/*30244*/     OPC_EmitInteger, MVT::i32, 0, 
/*30247*/     OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*30259*/     OPC_EmitInteger, MVT::i32, 0, 
/*30262*/     OPC_EmitInteger, MVT::i32, 0, 
/*30265*/     OPC_EmitInteger, MVT::i32, 0, 
/*30268*/     OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*30280*/     OPC_EmitInteger, MVT::i32, 1, 
/*30283*/     OPC_EmitRegister, MVT::i32, AMDGPU::PRED_SEL_OFF,
/*30286*/     OPC_EmitInteger, MVT::i32, 0, 
/*30289*/     OPC_EmitInteger, MVT::i32, 0, 
/*30292*/     OPC_MorphNodeTo, TARGET_VAL(AMDGPU::MAX), 0,
                  1/*#VTs*/, MVT::f32, 20/*#Ops*/, 2, 3, 4, 5, 6, 7, 0, 8, 9, 10, 11, 1, 12, 13, 14, 15, 16, 17, 18, 19, 
              // Src: (AMDGPUfmax:f32 R600_Reg32:f32:$src0, R600_Reg32:f32:$src1) - Complexity = 3
              // Dst: (MAX:f32 R600_Reg32:f32:$src0, R600_Reg32:f32:$src1)
/*30319*/   /*Scope*/ 11, /*->30331*/
/*30320*/     OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*30322*/     OPC_MorphNodeTo, TARGET_VAL(AMDGPU::V_MAX_LEGACY_F32_e32), 0,
                  1/*#VTs*/, MVT::f32, 2/*#Ops*/, 0, 1, 
              // Src: (AMDGPUfmax:f32 f32:f32:$src0, f32:f32:$src1) - Complexity = 3
              // Dst: (V_MAX_LEGACY_F32_e32:f32 f32:f32:$src0, f32:f32:$src1)
/*30331*/   0, /*End of Scope*/
/*30332*/ /*SwitchOpcode*/ 120,  TARGET_VAL(AMDGPUISD::FMIN),// ->30455
/*30335*/   OPC_RecordChild0, // #0 = $src0
/*30336*/   OPC_RecordChild1, // #1 = $src1
/*30337*/   OPC_CheckType, MVT::f32,
/*30339*/   OPC_Scope, 101, /*->30442*/ // 2 children in Scope
/*30341*/     OPC_CheckPatternPredicate, 3, // (Subtarget.getGeneration() <= AMDGPUSubtarget::NORTHERN_ISLANDS)
/*30343*/     OPC_EmitInteger, MVT::i32, 0, 
/*30346*/     OPC_EmitInteger, MVT::i32, 0, 
/*30349*/     OPC_EmitInteger, MVT::i32, 1, 
/*30352*/     OPC_EmitInteger, MVT::i32, 0, 
/*30355*/     OPC_EmitInteger, MVT::i32, 0, 
/*30358*/     OPC_EmitInteger, MVT::i32, 0, 
/*30361*/     OPC_EmitInteger, MVT::i32, 0, 
/*30364*/     OPC_EmitInteger, MVT::i32, 0, 
/*30367*/     OPC_EmitInteger, MVT::i32, 0, 
/*30370*/     OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*30382*/     OPC_EmitInteger, MVT::i32, 0, 
/*30385*/     OPC_EmitInteger, MVT::i32, 0, 
/*30388*/     OPC_EmitInteger, MVT::i32, 0, 
/*30391*/     OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*30403*/     OPC_EmitInteger, MVT::i32, 1, 
/*30406*/     OPC_EmitRegister, MVT::i32, AMDGPU::PRED_SEL_OFF,
/*30409*/     OPC_EmitInteger, MVT::i32, 0, 
/*30412*/     OPC_EmitInteger, MVT::i32, 0, 
/*30415*/     OPC_MorphNodeTo, TARGET_VAL(AMDGPU::MIN), 0,
                  1/*#VTs*/, MVT::f32, 20/*#Ops*/, 2, 3, 4, 5, 6, 7, 0, 8, 9, 10, 11, 1, 12, 13, 14, 15, 16, 17, 18, 19, 
              // Src: (AMDGPUfmin:f32 R600_Reg32:f32:$src0, R600_Reg32:f32:$src1) - Complexity = 3
              // Dst: (MIN:f32 R600_Reg32:f32:$src0, R600_Reg32:f32:$src1)
/*30442*/   /*Scope*/ 11, /*->30454*/
/*30443*/     OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*30445*/     OPC_MorphNodeTo, TARGET_VAL(AMDGPU::V_MIN_LEGACY_F32_e32), 0,
                  1/*#VTs*/, MVT::f32, 2/*#Ops*/, 0, 1, 
              // Src: (AMDGPUfmin:f32 f32:f32:$src0, f32:f32:$src1) - Complexity = 3
              // Dst: (V_MIN_LEGACY_F32_e32:f32 f32:f32:$src0, f32:f32:$src1)
/*30454*/   0, /*End of Scope*/
/*30455*/ /*SwitchOpcode*/ 84,  TARGET_VAL(AMDGPUISD::FRACT),// ->30542
/*30458*/   OPC_RecordChild0, // #0 = $src0
/*30459*/   OPC_CheckType, MVT::f32,
/*30461*/   OPC_Scope, 67, /*->30530*/ // 2 children in Scope
/*30463*/     OPC_CheckPatternPredicate, 3, // (Subtarget.getGeneration() <= AMDGPUSubtarget::NORTHERN_ISLANDS)
/*30465*/     OPC_EmitInteger, MVT::i32, 1, 
/*30468*/     OPC_EmitInteger, MVT::i32, 0, 
/*30471*/     OPC_EmitInteger, MVT::i32, 0, 
/*30474*/     OPC_EmitInteger, MVT::i32, 0, 
/*30477*/     OPC_EmitInteger, MVT::i32, 0, 
/*30480*/     OPC_EmitInteger, MVT::i32, 0, 
/*30483*/     OPC_EmitInteger, MVT::i32, 0, 
/*30486*/     OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*30498*/     OPC_EmitInteger, MVT::i32, 1, 
/*30501*/     OPC_EmitRegister, MVT::i32, AMDGPU::PRED_SEL_OFF,
/*30504*/     OPC_EmitInteger, MVT::i32, 0, 
/*30507*/     OPC_EmitInteger, MVT::i32, 0, 
/*30510*/     OPC_MorphNodeTo, TARGET_VAL(AMDGPU::FRACT), 0,
                  1/*#VTs*/, MVT::f32, 13/*#Ops*/, 1, 2, 3, 4, 0, 5, 6, 7, 8, 9, 10, 11, 12, 
              // Src: (AMDGPUfract:f32 R600_Reg32:f32:$src0) - Complexity = 3
              // Dst: (FRACT:f32 R600_Reg32:f32:$src0)
/*30530*/   /*Scope*/ 10, /*->30541*/
/*30531*/     OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*30533*/     OPC_MorphNodeTo, TARGET_VAL(AMDGPU::V_FRACT_F32_e32), 0,
                  1/*#VTs*/, MVT::f32, 1/*#Ops*/, 0, 
              // Src: (AMDGPUfract:f32 f32:f32:$src0) - Complexity = 3
              // Dst: (V_FRACT_F32_e32:f32 f32:f32:$src0)
/*30541*/   0, /*End of Scope*/
/*30542*/ /*SwitchOpcode*/ 84,  TARGET_VAL(ISD::FCEIL),// ->30629
/*30545*/   OPC_RecordChild0, // #0 = $src0
/*30546*/   OPC_CheckType, MVT::f32,
/*30548*/   OPC_Scope, 67, /*->30617*/ // 2 children in Scope
/*30550*/     OPC_CheckPatternPredicate, 3, // (Subtarget.getGeneration() <= AMDGPUSubtarget::NORTHERN_ISLANDS)
/*30552*/     OPC_EmitInteger, MVT::i32, 1, 
/*30555*/     OPC_EmitInteger, MVT::i32, 0, 
/*30558*/     OPC_EmitInteger, MVT::i32, 0, 
/*30561*/     OPC_EmitInteger, MVT::i32, 0, 
/*30564*/     OPC_EmitInteger, MVT::i32, 0, 
/*30567*/     OPC_EmitInteger, MVT::i32, 0, 
/*30570*/     OPC_EmitInteger, MVT::i32, 0, 
/*30573*/     OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*30585*/     OPC_EmitInteger, MVT::i32, 1, 
/*30588*/     OPC_EmitRegister, MVT::i32, AMDGPU::PRED_SEL_OFF,
/*30591*/     OPC_EmitInteger, MVT::i32, 0, 
/*30594*/     OPC_EmitInteger, MVT::i32, 0, 
/*30597*/     OPC_MorphNodeTo, TARGET_VAL(AMDGPU::CEIL), 0,
                  1/*#VTs*/, MVT::f32, 13/*#Ops*/, 1, 2, 3, 4, 0, 5, 6, 7, 8, 9, 10, 11, 12, 
              // Src: (fceil:f32 R600_Reg32:f32:$src0) - Complexity = 3
              // Dst: (CEIL:f32 R600_Reg32:f32:$src0)
/*30617*/   /*Scope*/ 10, /*->30628*/
/*30618*/     OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*30620*/     OPC_MorphNodeTo, TARGET_VAL(AMDGPU::V_CEIL_F32_e32), 0,
                  1/*#VTs*/, MVT::f32, 1/*#Ops*/, 0, 
              // Src: (fceil:f32 f32:f32:$src0) - Complexity = 3
              // Dst: (V_CEIL_F32_e32:f32 f32:f32:$src0)
/*30628*/   0, /*End of Scope*/
/*30629*/ /*SwitchOpcode*/ 84,  TARGET_VAL(ISD::FRINT),// ->30716
/*30632*/   OPC_RecordChild0, // #0 = $src0
/*30633*/   OPC_CheckType, MVT::f32,
/*30635*/   OPC_Scope, 67, /*->30704*/ // 2 children in Scope
/*30637*/     OPC_CheckPatternPredicate, 3, // (Subtarget.getGeneration() <= AMDGPUSubtarget::NORTHERN_ISLANDS)
/*30639*/     OPC_EmitInteger, MVT::i32, 1, 
/*30642*/     OPC_EmitInteger, MVT::i32, 0, 
/*30645*/     OPC_EmitInteger, MVT::i32, 0, 
/*30648*/     OPC_EmitInteger, MVT::i32, 0, 
/*30651*/     OPC_EmitInteger, MVT::i32, 0, 
/*30654*/     OPC_EmitInteger, MVT::i32, 0, 
/*30657*/     OPC_EmitInteger, MVT::i32, 0, 
/*30660*/     OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*30672*/     OPC_EmitInteger, MVT::i32, 1, 
/*30675*/     OPC_EmitRegister, MVT::i32, AMDGPU::PRED_SEL_OFF,
/*30678*/     OPC_EmitInteger, MVT::i32, 0, 
/*30681*/     OPC_EmitInteger, MVT::i32, 0, 
/*30684*/     OPC_MorphNodeTo, TARGET_VAL(AMDGPU::RNDNE), 0,
                  1/*#VTs*/, MVT::f32, 13/*#Ops*/, 1, 2, 3, 4, 0, 5, 6, 7, 8, 9, 10, 11, 12, 
              // Src: (frint:f32 R600_Reg32:f32:$src0) - Complexity = 3
              // Dst: (RNDNE:f32 R600_Reg32:f32:$src0)
/*30704*/   /*Scope*/ 10, /*->30715*/
/*30705*/     OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*30707*/     OPC_MorphNodeTo, TARGET_VAL(AMDGPU::V_RNDNE_F32_e32), 0,
                  1/*#VTs*/, MVT::f32, 1/*#Ops*/, 0, 
              // Src: (frint:f32 f32:f32:$src0) - Complexity = 3
              // Dst: (V_RNDNE_F32_e32:f32 f32:f32:$src0)
/*30715*/   0, /*End of Scope*/
/*30716*/ /*SwitchOpcode*/ 84,  TARGET_VAL(ISD::FFLOOR),// ->30803
/*30719*/   OPC_RecordChild0, // #0 = $src0
/*30720*/   OPC_CheckType, MVT::f32,
/*30722*/   OPC_Scope, 67, /*->30791*/ // 2 children in Scope
/*30724*/     OPC_CheckPatternPredicate, 3, // (Subtarget.getGeneration() <= AMDGPUSubtarget::NORTHERN_ISLANDS)
/*30726*/     OPC_EmitInteger, MVT::i32, 1, 
/*30729*/     OPC_EmitInteger, MVT::i32, 0, 
/*30732*/     OPC_EmitInteger, MVT::i32, 0, 
/*30735*/     OPC_EmitInteger, MVT::i32, 0, 
/*30738*/     OPC_EmitInteger, MVT::i32, 0, 
/*30741*/     OPC_EmitInteger, MVT::i32, 0, 
/*30744*/     OPC_EmitInteger, MVT::i32, 0, 
/*30747*/     OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*30759*/     OPC_EmitInteger, MVT::i32, 1, 
/*30762*/     OPC_EmitRegister, MVT::i32, AMDGPU::PRED_SEL_OFF,
/*30765*/     OPC_EmitInteger, MVT::i32, 0, 
/*30768*/     OPC_EmitInteger, MVT::i32, 0, 
/*30771*/     OPC_MorphNodeTo, TARGET_VAL(AMDGPU::FLOOR), 0,
                  1/*#VTs*/, MVT::f32, 13/*#Ops*/, 1, 2, 3, 4, 0, 5, 6, 7, 8, 9, 10, 11, 12, 
              // Src: (ffloor:f32 R600_Reg32:f32:$src0) - Complexity = 3
              // Dst: (FLOOR:f32 R600_Reg32:f32:$src0)
/*30791*/   /*Scope*/ 10, /*->30802*/
/*30792*/     OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*30794*/     OPC_MorphNodeTo, TARGET_VAL(AMDGPU::V_FLOOR_F32_e32), 0,
                  1/*#VTs*/, MVT::f32, 1/*#Ops*/, 0, 
              // Src: (ffloor:f32 f32:f32:$src0) - Complexity = 3
              // Dst: (V_FLOOR_F32_e32:f32 f32:f32:$src0)
/*30802*/   0, /*End of Scope*/
/*30803*/ /*SwitchOpcode*/ 91|128,2/*347*/,  TARGET_VAL(AMDGPUISD::DOT4),// ->31154
/*30807*/   OPC_RecordChild0, // #0 = $src0_X
/*30808*/   OPC_RecordChild1, // #1 = $src1_X
/*30809*/   OPC_RecordChild2, // #2 = $src0_Y
/*30810*/   OPC_RecordChild3, // #3 = $src1_Y
/*30811*/   OPC_RecordChild4, // #4 = $src0_Z
/*30812*/   OPC_RecordChild5, // #5 = $src1_Z
/*30813*/   OPC_RecordChild6, // #6 = $src0_W
/*30814*/   OPC_RecordChild7, // #7 = $src1_W
/*30815*/   OPC_CheckType, MVT::f32,
/*30817*/   OPC_CheckPatternPredicate, 3, // (Subtarget.getGeneration() <= AMDGPUSubtarget::NORTHERN_ISLANDS)
/*30819*/   OPC_EmitInteger, MVT::i32, 0, 
/*30822*/   OPC_EmitInteger, MVT::i32, 0, 
/*30825*/   OPC_EmitInteger, MVT::i32, 1, 
/*30828*/   OPC_EmitInteger, MVT::i32, 0, 
/*30831*/   OPC_EmitInteger, MVT::i32, 0, 
/*30834*/   OPC_EmitInteger, MVT::i32, 0, 
/*30837*/   OPC_EmitInteger, MVT::i32, 0, 
/*30840*/   OPC_EmitInteger, MVT::i32, 0, 
/*30843*/   OPC_EmitInteger, MVT::i32, 0, 
/*30846*/   OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*30858*/   OPC_EmitInteger, MVT::i32, 0, 
/*30861*/   OPC_EmitInteger, MVT::i32, 0, 
/*30864*/   OPC_EmitInteger, MVT::i32, 0, 
/*30867*/   OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*30879*/   OPC_EmitRegister, MVT::i32, AMDGPU::PRED_SEL_OFF,
/*30882*/   OPC_EmitInteger, MVT::i32, 0, 
/*30885*/   OPC_EmitInteger, MVT::i32, 0, 
/*30888*/   OPC_EmitInteger, MVT::i32, 1, 
/*30891*/   OPC_EmitInteger, MVT::i32, 0, 
/*30894*/   OPC_EmitInteger, MVT::i32, 0, 
/*30897*/   OPC_EmitInteger, MVT::i32, 0, 
/*30900*/   OPC_EmitInteger, MVT::i32, 0, 
/*30903*/   OPC_EmitInteger, MVT::i32, 0, 
/*30906*/   OPC_EmitInteger, MVT::i32, 0, 
/*30909*/   OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*30921*/   OPC_EmitInteger, MVT::i32, 0, 
/*30924*/   OPC_EmitInteger, MVT::i32, 0, 
/*30927*/   OPC_EmitInteger, MVT::i32, 0, 
/*30930*/   OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*30942*/   OPC_EmitRegister, MVT::i32, AMDGPU::PRED_SEL_OFF,
/*30945*/   OPC_EmitInteger, MVT::i32, 0, 
/*30948*/   OPC_EmitInteger, MVT::i32, 0, 
/*30951*/   OPC_EmitInteger, MVT::i32, 1, 
/*30954*/   OPC_EmitInteger, MVT::i32, 0, 
/*30957*/   OPC_EmitInteger, MVT::i32, 0, 
/*30960*/   OPC_EmitInteger, MVT::i32, 0, 
/*30963*/   OPC_EmitInteger, MVT::i32, 0, 
/*30966*/   OPC_EmitInteger, MVT::i32, 0, 
/*30969*/   OPC_EmitInteger, MVT::i32, 0, 
/*30972*/   OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*30984*/   OPC_EmitInteger, MVT::i32, 0, 
/*30987*/   OPC_EmitInteger, MVT::i32, 0, 
/*30990*/   OPC_EmitInteger, MVT::i32, 0, 
/*30993*/   OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*31005*/   OPC_EmitRegister, MVT::i32, AMDGPU::PRED_SEL_OFF,
/*31008*/   OPC_EmitInteger, MVT::i32, 0, 
/*31011*/   OPC_EmitInteger, MVT::i32, 0, 
/*31014*/   OPC_EmitInteger, MVT::i32, 1, 
/*31017*/   OPC_EmitInteger, MVT::i32, 0, 
/*31020*/   OPC_EmitInteger, MVT::i32, 0, 
/*31023*/   OPC_EmitInteger, MVT::i32, 0, 
/*31026*/   OPC_EmitInteger, MVT::i32, 0, 
/*31029*/   OPC_EmitInteger, MVT::i32, 0, 
/*31032*/   OPC_EmitInteger, MVT::i32, 0, 
/*31035*/   OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*31047*/   OPC_EmitInteger, MVT::i32, 0, 
/*31050*/   OPC_EmitInteger, MVT::i32, 0, 
/*31053*/   OPC_EmitInteger, MVT::i32, 0, 
/*31056*/   OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*31068*/   OPC_EmitRegister, MVT::i32, AMDGPU::PRED_SEL_OFF,
/*31071*/   OPC_EmitInteger, MVT::i32, 0, 
/*31074*/   OPC_EmitInteger, MVT::i32, 0, 
/*31077*/   OPC_MorphNodeTo, TARGET_VAL(AMDGPU::DOT_4), 0,
                1/*#VTs*/, MVT::f32, 70/*#Ops*/, 8, 9, 10, 11, 12, 13, 0, 14, 15, 16, 17, 1, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 2, 29, 30, 31, 32, 3, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 4, 44, 45, 46, 47, 5, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 6, 59, 60, 61, 62, 7, 63, 64, 65, 66, 67, 68, 69, 
            // Src: (DOT4:f32 R600_TReg32_X:f32:$src0_X, R600_TReg32_X:f32:$src1_X, R600_TReg32_Y:f32:$src0_Y, R600_TReg32_Y:f32:$src1_Y, R600_TReg32_Z:f32:$src0_Z, R600_TReg32_Z:f32:$src1_Z, R600_TReg32_W:f32:$src0_W, R600_TReg32_W:f32:$src1_W) - Complexity = 3
            // Dst: (DOT_4:f32 R600_TReg32_X:f32:$src0_X, R600_TReg32_X:f32:$src1_X, R600_TReg32_Y:f32:$src0_Y, R600_TReg32_Y:f32:$src1_Y, R600_TReg32_Z:f32:$src0_Z, R600_TReg32_Z:f32:$src1_Z, R600_TReg32_W:f32:$src0_W, R600_TReg32_W:f32:$src1_W)
/*31154*/ /*SwitchOpcode*/ 92|128,1/*220*/,  TARGET_VAL(ISD::FEXP2),// ->31378
/*31158*/   OPC_RecordChild0, // #0 = $src0
/*31159*/   OPC_CheckType, MVT::f32,
/*31161*/   OPC_Scope, 67, /*->31230*/ // 4 children in Scope
/*31163*/     OPC_CheckPatternPredicate, 1, // (Subtarget.getGeneration() <= AMDGPUSubtarget::R700)
/*31165*/     OPC_EmitInteger, MVT::i32, 1, 
/*31168*/     OPC_EmitInteger, MVT::i32, 0, 
/*31171*/     OPC_EmitInteger, MVT::i32, 0, 
/*31174*/     OPC_EmitInteger, MVT::i32, 0, 
/*31177*/     OPC_EmitInteger, MVT::i32, 0, 
/*31180*/     OPC_EmitInteger, MVT::i32, 0, 
/*31183*/     OPC_EmitInteger, MVT::i32, 0, 
/*31186*/     OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*31198*/     OPC_EmitInteger, MVT::i32, 1, 
/*31201*/     OPC_EmitRegister, MVT::i32, AMDGPU::PRED_SEL_OFF,
/*31204*/     OPC_EmitInteger, MVT::i32, 0, 
/*31207*/     OPC_EmitInteger, MVT::i32, 0, 
/*31210*/     OPC_MorphNodeTo, TARGET_VAL(AMDGPU::EXP_IEEE_r600), 0,
                  1/*#VTs*/, MVT::f32, 13/*#Ops*/, 1, 2, 3, 4, 0, 5, 6, 7, 8, 9, 10, 11, 12, 
              // Src: (fexp2:f32 R600_Reg32:f32:$src0) - Complexity = 3
              // Dst: (EXP_IEEE_r600:f32 R600_Reg32:f32:$src0)
/*31230*/   /*Scope*/ 67, /*->31298*/
/*31231*/     OPC_CheckPatternPredicate, 5, // (Subtarget.getGeneration() >= AMDGPUSubtarget::EVERGREEN && Subtarget.getGeneration() < AMDGPUSubtarget::SOUTHERN_ISLANDS && !Subtarget.hasCaymanISA())
/*31233*/     OPC_EmitInteger, MVT::i32, 1, 
/*31236*/     OPC_EmitInteger, MVT::i32, 0, 
/*31239*/     OPC_EmitInteger, MVT::i32, 0, 
/*31242*/     OPC_EmitInteger, MVT::i32, 0, 
/*31245*/     OPC_EmitInteger, MVT::i32, 0, 
/*31248*/     OPC_EmitInteger, MVT::i32, 0, 
/*31251*/     OPC_EmitInteger, MVT::i32, 0, 
/*31254*/     OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*31266*/     OPC_EmitInteger, MVT::i32, 1, 
/*31269*/     OPC_EmitRegister, MVT::i32, AMDGPU::PRED_SEL_OFF,
/*31272*/     OPC_EmitInteger, MVT::i32, 0, 
/*31275*/     OPC_EmitInteger, MVT::i32, 0, 
/*31278*/     OPC_MorphNodeTo, TARGET_VAL(AMDGPU::EXP_IEEE_eg), 0,
                  1/*#VTs*/, MVT::f32, 13/*#Ops*/, 1, 2, 3, 4, 0, 5, 6, 7, 8, 9, 10, 11, 12, 
              // Src: (fexp2:f32 R600_Reg32:f32:$src0) - Complexity = 3
              // Dst: (EXP_IEEE_eg:f32 R600_Reg32:f32:$src0)
/*31298*/   /*Scope*/ 67, /*->31366*/
/*31299*/     OPC_CheckPatternPredicate, 4, // (Subtarget.hasCaymanISA())
/*31301*/     OPC_EmitInteger, MVT::i32, 1, 
/*31304*/     OPC_EmitInteger, MVT::i32, 0, 
/*31307*/     OPC_EmitInteger, MVT::i32, 0, 
/*31310*/     OPC_EmitInteger, MVT::i32, 0, 
/*31313*/     OPC_EmitInteger, MVT::i32, 0, 
/*31316*/     OPC_EmitInteger, MVT::i32, 0, 
/*31319*/     OPC_EmitInteger, MVT::i32, 0, 
/*31322*/     OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*31334*/     OPC_EmitInteger, MVT::i32, 1, 
/*31337*/     OPC_EmitRegister, MVT::i32, AMDGPU::PRED_SEL_OFF,
/*31340*/     OPC_EmitInteger, MVT::i32, 0, 
/*31343*/     OPC_EmitInteger, MVT::i32, 0, 
/*31346*/     OPC_MorphNodeTo, TARGET_VAL(AMDGPU::EXP_IEEE_cm), 0,
                  1/*#VTs*/, MVT::f32, 13/*#Ops*/, 1, 2, 3, 4, 0, 5, 6, 7, 8, 9, 10, 11, 12, 
              // Src: (fexp2:f32 R600_Reg32:f32:$src0) - Complexity = 3
              // Dst: (EXP_IEEE_cm:f32 R600_Reg32:f32:$src0)
/*31366*/   /*Scope*/ 10, /*->31377*/
/*31367*/     OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*31369*/     OPC_MorphNodeTo, TARGET_VAL(AMDGPU::V_EXP_F32_e32), 0,
                  1/*#VTs*/, MVT::f32, 1/*#Ops*/, 0, 
              // Src: (fexp2:f32 f32:f32:$src0) - Complexity = 3
              // Dst: (V_EXP_F32_e32:f32 f32:f32:$src0)
/*31377*/   0, /*End of Scope*/
/*31378*/ /*SwitchOpcode*/ 92|128,1/*220*/,  TARGET_VAL(ISD::FLOG2),// ->31602
/*31382*/   OPC_RecordChild0, // #0 = $src0
/*31383*/   OPC_CheckType, MVT::f32,
/*31385*/   OPC_Scope, 67, /*->31454*/ // 4 children in Scope
/*31387*/     OPC_CheckPatternPredicate, 1, // (Subtarget.getGeneration() <= AMDGPUSubtarget::R700)
/*31389*/     OPC_EmitInteger, MVT::i32, 1, 
/*31392*/     OPC_EmitInteger, MVT::i32, 0, 
/*31395*/     OPC_EmitInteger, MVT::i32, 0, 
/*31398*/     OPC_EmitInteger, MVT::i32, 0, 
/*31401*/     OPC_EmitInteger, MVT::i32, 0, 
/*31404*/     OPC_EmitInteger, MVT::i32, 0, 
/*31407*/     OPC_EmitInteger, MVT::i32, 0, 
/*31410*/     OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*31422*/     OPC_EmitInteger, MVT::i32, 1, 
/*31425*/     OPC_EmitRegister, MVT::i32, AMDGPU::PRED_SEL_OFF,
/*31428*/     OPC_EmitInteger, MVT::i32, 0, 
/*31431*/     OPC_EmitInteger, MVT::i32, 0, 
/*31434*/     OPC_MorphNodeTo, TARGET_VAL(AMDGPU::LOG_IEEE_r600), 0,
                  1/*#VTs*/, MVT::f32, 13/*#Ops*/, 1, 2, 3, 4, 0, 5, 6, 7, 8, 9, 10, 11, 12, 
              // Src: (flog2:f32 R600_Reg32:f32:$src0) - Complexity = 3
              // Dst: (LOG_IEEE_r600:f32 R600_Reg32:f32:$src0)
/*31454*/   /*Scope*/ 67, /*->31522*/
/*31455*/     OPC_CheckPatternPredicate, 5, // (Subtarget.getGeneration() >= AMDGPUSubtarget::EVERGREEN && Subtarget.getGeneration() < AMDGPUSubtarget::SOUTHERN_ISLANDS && !Subtarget.hasCaymanISA())
/*31457*/     OPC_EmitInteger, MVT::i32, 1, 
/*31460*/     OPC_EmitInteger, MVT::i32, 0, 
/*31463*/     OPC_EmitInteger, MVT::i32, 0, 
/*31466*/     OPC_EmitInteger, MVT::i32, 0, 
/*31469*/     OPC_EmitInteger, MVT::i32, 0, 
/*31472*/     OPC_EmitInteger, MVT::i32, 0, 
/*31475*/     OPC_EmitInteger, MVT::i32, 0, 
/*31478*/     OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*31490*/     OPC_EmitInteger, MVT::i32, 1, 
/*31493*/     OPC_EmitRegister, MVT::i32, AMDGPU::PRED_SEL_OFF,
/*31496*/     OPC_EmitInteger, MVT::i32, 0, 
/*31499*/     OPC_EmitInteger, MVT::i32, 0, 
/*31502*/     OPC_MorphNodeTo, TARGET_VAL(AMDGPU::LOG_IEEE_eg), 0,
                  1/*#VTs*/, MVT::f32, 13/*#Ops*/, 1, 2, 3, 4, 0, 5, 6, 7, 8, 9, 10, 11, 12, 
              // Src: (flog2:f32 R600_Reg32:f32:$src0) - Complexity = 3
              // Dst: (LOG_IEEE_eg:f32 R600_Reg32:f32:$src0)
/*31522*/   /*Scope*/ 67, /*->31590*/
/*31523*/     OPC_CheckPatternPredicate, 4, // (Subtarget.hasCaymanISA())
/*31525*/     OPC_EmitInteger, MVT::i32, 1, 
/*31528*/     OPC_EmitInteger, MVT::i32, 0, 
/*31531*/     OPC_EmitInteger, MVT::i32, 0, 
/*31534*/     OPC_EmitInteger, MVT::i32, 0, 
/*31537*/     OPC_EmitInteger, MVT::i32, 0, 
/*31540*/     OPC_EmitInteger, MVT::i32, 0, 
/*31543*/     OPC_EmitInteger, MVT::i32, 0, 
/*31546*/     OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*31558*/     OPC_EmitInteger, MVT::i32, 1, 
/*31561*/     OPC_EmitRegister, MVT::i32, AMDGPU::PRED_SEL_OFF,
/*31564*/     OPC_EmitInteger, MVT::i32, 0, 
/*31567*/     OPC_EmitInteger, MVT::i32, 0, 
/*31570*/     OPC_MorphNodeTo, TARGET_VAL(AMDGPU::LOG_IEEE_cm), 0,
                  1/*#VTs*/, MVT::f32, 13/*#Ops*/, 1, 2, 3, 4, 0, 5, 6, 7, 8, 9, 10, 11, 12, 
              // Src: (flog2:f32 R600_Reg32:f32:$src0) - Complexity = 3
              // Dst: (LOG_IEEE_cm:f32 R600_Reg32:f32:$src0)
/*31590*/   /*Scope*/ 10, /*->31601*/
/*31591*/     OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*31593*/     OPC_MorphNodeTo, TARGET_VAL(AMDGPU::V_LOG_F32_e32), 0,
                  1/*#VTs*/, MVT::f32, 1/*#Ops*/, 0, 
              // Src: (flog2:f32 f32:f32:$src0) - Complexity = 3
              // Dst: (V_LOG_F32_e32:f32 f32:f32:$src0)
/*31601*/   0, /*End of Scope*/
/*31602*/ /*SwitchOpcode*/ 41|128,1/*169*/,  TARGET_VAL(ISD::SINT_TO_FP),// ->31775
/*31606*/   OPC_RecordChild0, // #0 = $src0
/*31607*/   OPC_CheckChild0Type, MVT::i32,
/*31609*/   OPC_SwitchType /*2 cases */, 21|128,1/*149*/,  MVT::f32,// ->31762
/*31613*/     OPC_Scope, 67, /*->31682*/ // 3 children in Scope
/*31615*/       OPC_CheckPatternPredicate, 1, // (Subtarget.getGeneration() <= AMDGPUSubtarget::R700)
/*31617*/       OPC_EmitInteger, MVT::i32, 1, 
/*31620*/       OPC_EmitInteger, MVT::i32, 0, 
/*31623*/       OPC_EmitInteger, MVT::i32, 0, 
/*31626*/       OPC_EmitInteger, MVT::i32, 0, 
/*31629*/       OPC_EmitInteger, MVT::i32, 0, 
/*31632*/       OPC_EmitInteger, MVT::i32, 0, 
/*31635*/       OPC_EmitInteger, MVT::i32, 0, 
/*31638*/       OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*31650*/       OPC_EmitInteger, MVT::i32, 1, 
/*31653*/       OPC_EmitRegister, MVT::i32, AMDGPU::PRED_SEL_OFF,
/*31656*/       OPC_EmitInteger, MVT::i32, 0, 
/*31659*/       OPC_EmitInteger, MVT::i32, 0, 
/*31662*/       OPC_MorphNodeTo, TARGET_VAL(AMDGPU::INT_TO_FLT_r600), 0,
                    1/*#VTs*/, MVT::f32, 13/*#Ops*/, 1, 2, 3, 4, 0, 5, 6, 7, 8, 9, 10, 11, 12, 
                // Src: (sint_to_fp:f32 R600_Reg32:i32:$src0) - Complexity = 3
                // Dst: (INT_TO_FLT_r600:f32 R600_Reg32:i32:$src0)
/*31682*/     /*Scope*/ 67, /*->31750*/
/*31683*/       OPC_CheckPatternPredicate, 2, // (Subtarget.getGeneration() == AMDGPUSubtarget::EVERGREEN|| Subtarget.getGeneration() ==AMDGPUSubtarget::NORTHERN_ISLANDS)
/*31685*/       OPC_EmitInteger, MVT::i32, 1, 
/*31688*/       OPC_EmitInteger, MVT::i32, 0, 
/*31691*/       OPC_EmitInteger, MVT::i32, 0, 
/*31694*/       OPC_EmitInteger, MVT::i32, 0, 
/*31697*/       OPC_EmitInteger, MVT::i32, 0, 
/*31700*/       OPC_EmitInteger, MVT::i32, 0, 
/*31703*/       OPC_EmitInteger, MVT::i32, 0, 
/*31706*/       OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*31718*/       OPC_EmitInteger, MVT::i32, 1, 
/*31721*/       OPC_EmitRegister, MVT::i32, AMDGPU::PRED_SEL_OFF,
/*31724*/       OPC_EmitInteger, MVT::i32, 0, 
/*31727*/       OPC_EmitInteger, MVT::i32, 0, 
/*31730*/       OPC_MorphNodeTo, TARGET_VAL(AMDGPU::INT_TO_FLT_eg), 0,
                    1/*#VTs*/, MVT::f32, 13/*#Ops*/, 1, 2, 3, 4, 0, 5, 6, 7, 8, 9, 10, 11, 12, 
                // Src: (sint_to_fp:f32 R600_Reg32:i32:$src0) - Complexity = 3
                // Dst: (INT_TO_FLT_eg:f32 R600_Reg32:i32:$src0)
/*31750*/     /*Scope*/ 10, /*->31761*/
/*31751*/       OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*31753*/       OPC_MorphNodeTo, TARGET_VAL(AMDGPU::V_CVT_F32_I32_e32), 0,
                    1/*#VTs*/, MVT::f32, 1/*#Ops*/, 0, 
                // Src: (sint_to_fp:f32 i32:i32:$src0) - Complexity = 3
                // Dst: (V_CVT_F32_I32_e32:f32 i32:i32:$src0)
/*31761*/     0, /*End of Scope*/
/*31762*/   /*SwitchType*/ 10,  MVT::f64,// ->31774
/*31764*/     OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*31766*/     OPC_MorphNodeTo, TARGET_VAL(AMDGPU::V_CVT_F64_I32_e32), 0,
                  1/*#VTs*/, MVT::f64, 1/*#Ops*/, 0, 
              // Src: (sint_to_fp:f64 i32:i32:$src0) - Complexity = 3
              // Dst: (V_CVT_F64_I32_e32:f64 i32:i32:$src0)
/*31774*/   0, // EndSwitchType
/*31775*/ /*SwitchOpcode*/ 26|128,1/*154*/,  TARGET_VAL(ISD::UINT_TO_FP),// ->31933
/*31779*/   OPC_RecordChild0, // #0 = $src0
/*31780*/   OPC_CheckChild0Type, MVT::i32,
/*31782*/   OPC_CheckType, MVT::f32,
/*31784*/   OPC_Scope, 67, /*->31853*/ // 3 children in Scope
/*31786*/     OPC_CheckPatternPredicate, 1, // (Subtarget.getGeneration() <= AMDGPUSubtarget::R700)
/*31788*/     OPC_EmitInteger, MVT::i32, 1, 
/*31791*/     OPC_EmitInteger, MVT::i32, 0, 
/*31794*/     OPC_EmitInteger, MVT::i32, 0, 
/*31797*/     OPC_EmitInteger, MVT::i32, 0, 
/*31800*/     OPC_EmitInteger, MVT::i32, 0, 
/*31803*/     OPC_EmitInteger, MVT::i32, 0, 
/*31806*/     OPC_EmitInteger, MVT::i32, 0, 
/*31809*/     OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*31821*/     OPC_EmitInteger, MVT::i32, 1, 
/*31824*/     OPC_EmitRegister, MVT::i32, AMDGPU::PRED_SEL_OFF,
/*31827*/     OPC_EmitInteger, MVT::i32, 0, 
/*31830*/     OPC_EmitInteger, MVT::i32, 0, 
/*31833*/     OPC_MorphNodeTo, TARGET_VAL(AMDGPU::UINT_TO_FLT_r600), 0,
                  1/*#VTs*/, MVT::f32, 13/*#Ops*/, 1, 2, 3, 4, 0, 5, 6, 7, 8, 9, 10, 11, 12, 
              // Src: (uint_to_fp:f32 R600_Reg32:i32:$src0) - Complexity = 3
              // Dst: (UINT_TO_FLT_r600:f32 R600_Reg32:i32:$src0)
/*31853*/   /*Scope*/ 67, /*->31921*/
/*31854*/     OPC_CheckPatternPredicate, 2, // (Subtarget.getGeneration() == AMDGPUSubtarget::EVERGREEN|| Subtarget.getGeneration() ==AMDGPUSubtarget::NORTHERN_ISLANDS)
/*31856*/     OPC_EmitInteger, MVT::i32, 1, 
/*31859*/     OPC_EmitInteger, MVT::i32, 0, 
/*31862*/     OPC_EmitInteger, MVT::i32, 0, 
/*31865*/     OPC_EmitInteger, MVT::i32, 0, 
/*31868*/     OPC_EmitInteger, MVT::i32, 0, 
/*31871*/     OPC_EmitInteger, MVT::i32, 0, 
/*31874*/     OPC_EmitInteger, MVT::i32, 0, 
/*31877*/     OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*31889*/     OPC_EmitInteger, MVT::i32, 1, 
/*31892*/     OPC_EmitRegister, MVT::i32, AMDGPU::PRED_SEL_OFF,
/*31895*/     OPC_EmitInteger, MVT::i32, 0, 
/*31898*/     OPC_EmitInteger, MVT::i32, 0, 
/*31901*/     OPC_MorphNodeTo, TARGET_VAL(AMDGPU::UINT_TO_FLT_eg), 0,
                  1/*#VTs*/, MVT::f32, 13/*#Ops*/, 1, 2, 3, 4, 0, 5, 6, 7, 8, 9, 10, 11, 12, 
              // Src: (uint_to_fp:f32 R600_Reg32:i32:$src0) - Complexity = 3
              // Dst: (UINT_TO_FLT_eg:f32 R600_Reg32:i32:$src0)
/*31921*/   /*Scope*/ 10, /*->31932*/
/*31922*/     OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*31924*/     OPC_MorphNodeTo, TARGET_VAL(AMDGPU::V_CVT_F32_U32_e32), 0,
                  1/*#VTs*/, MVT::f32, 1/*#Ops*/, 0, 
              // Src: (uint_to_fp:f32 i32:i32:$src0) - Complexity = 3
              // Dst: (V_CVT_F32_U32_e32:f32 i32:i32:$src0)
/*31932*/   0, /*End of Scope*/
/*31933*/ /*SwitchOpcode*/ 23|128,2/*279*/,  TARGET_VAL(AMDGPUISD::SIN_HW),// ->32216
/*31937*/   OPC_RecordChild0, // #0 = $src0
/*31938*/   OPC_CheckChild0Type, MVT::f32,
/*31940*/   OPC_CheckType, MVT::f32,
/*31942*/   OPC_Scope, 67, /*->32011*/ // 4 children in Scope
/*31944*/     OPC_CheckPatternPredicate, 1, // (Subtarget.getGeneration() <= AMDGPUSubtarget::R700)
/*31946*/     OPC_EmitInteger, MVT::i32, 1, 
/*31949*/     OPC_EmitInteger, MVT::i32, 0, 
/*31952*/     OPC_EmitInteger, MVT::i32, 0, 
/*31955*/     OPC_EmitInteger, MVT::i32, 0, 
/*31958*/     OPC_EmitInteger, MVT::i32, 0, 
/*31961*/     OPC_EmitInteger, MVT::i32, 0, 
/*31964*/     OPC_EmitInteger, MVT::i32, 0, 
/*31967*/     OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*31979*/     OPC_EmitInteger, MVT::i32, 1, 
/*31982*/     OPC_EmitRegister, MVT::i32, AMDGPU::PRED_SEL_OFF,
/*31985*/     OPC_EmitInteger, MVT::i32, 0, 
/*31988*/     OPC_EmitInteger, MVT::i32, 0, 
/*31991*/     OPC_MorphNodeTo, TARGET_VAL(AMDGPU::SIN_r600), 0,
                  1/*#VTs*/, MVT::f32, 13/*#Ops*/, 1, 2, 3, 4, 0, 5, 6, 7, 8, 9, 10, 11, 12, 
              // Src: (SIN_HW:f32 f32:f32:$src0) - Complexity = 3
              // Dst: (SIN_r600:f32 f32:f32:$src0)
/*32011*/   /*Scope*/ 67, /*->32079*/
/*32012*/     OPC_CheckPatternPredicate, 6, // (Subtarget.getGeneration() == AMDGPUSubtarget::R700)
/*32014*/     OPC_EmitInteger, MVT::i32, 1, 
/*32017*/     OPC_EmitInteger, MVT::i32, 0, 
/*32020*/     OPC_EmitInteger, MVT::i32, 0, 
/*32023*/     OPC_EmitInteger, MVT::i32, 0, 
/*32026*/     OPC_EmitInteger, MVT::i32, 0, 
/*32029*/     OPC_EmitInteger, MVT::i32, 0, 
/*32032*/     OPC_EmitInteger, MVT::i32, 0, 
/*32035*/     OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*32047*/     OPC_EmitInteger, MVT::i32, 1, 
/*32050*/     OPC_EmitRegister, MVT::i32, AMDGPU::PRED_SEL_OFF,
/*32053*/     OPC_EmitInteger, MVT::i32, 0, 
/*32056*/     OPC_EmitInteger, MVT::i32, 0, 
/*32059*/     OPC_MorphNodeTo, TARGET_VAL(AMDGPU::SIN_r700), 0,
                  1/*#VTs*/, MVT::f32, 13/*#Ops*/, 1, 2, 3, 4, 0, 5, 6, 7, 8, 9, 10, 11, 12, 
              // Src: (SIN_HW:f32 f32:f32:$src0) - Complexity = 3
              // Dst: (SIN_r700:f32 f32:f32:$src0)
/*32079*/   /*Scope*/ 67, /*->32147*/
/*32080*/     OPC_CheckPatternPredicate, 5, // (Subtarget.getGeneration() >= AMDGPUSubtarget::EVERGREEN && Subtarget.getGeneration() < AMDGPUSubtarget::SOUTHERN_ISLANDS && !Subtarget.hasCaymanISA())
/*32082*/     OPC_EmitInteger, MVT::i32, 1, 
/*32085*/     OPC_EmitInteger, MVT::i32, 0, 
/*32088*/     OPC_EmitInteger, MVT::i32, 0, 
/*32091*/     OPC_EmitInteger, MVT::i32, 0, 
/*32094*/     OPC_EmitInteger, MVT::i32, 0, 
/*32097*/     OPC_EmitInteger, MVT::i32, 0, 
/*32100*/     OPC_EmitInteger, MVT::i32, 0, 
/*32103*/     OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*32115*/     OPC_EmitInteger, MVT::i32, 1, 
/*32118*/     OPC_EmitRegister, MVT::i32, AMDGPU::PRED_SEL_OFF,
/*32121*/     OPC_EmitInteger, MVT::i32, 0, 
/*32124*/     OPC_EmitInteger, MVT::i32, 0, 
/*32127*/     OPC_MorphNodeTo, TARGET_VAL(AMDGPU::SIN_eg), 0,
                  1/*#VTs*/, MVT::f32, 13/*#Ops*/, 1, 2, 3, 4, 0, 5, 6, 7, 8, 9, 10, 11, 12, 
              // Src: (SIN_HW:f32 f32:f32:$src0) - Complexity = 3
              // Dst: (SIN_eg:f32 f32:f32:$src0)
/*32147*/   /*Scope*/ 67, /*->32215*/
/*32148*/     OPC_CheckPatternPredicate, 4, // (Subtarget.hasCaymanISA())
/*32150*/     OPC_EmitInteger, MVT::i32, 1, 
/*32153*/     OPC_EmitInteger, MVT::i32, 0, 
/*32156*/     OPC_EmitInteger, MVT::i32, 0, 
/*32159*/     OPC_EmitInteger, MVT::i32, 0, 
/*32162*/     OPC_EmitInteger, MVT::i32, 0, 
/*32165*/     OPC_EmitInteger, MVT::i32, 0, 
/*32168*/     OPC_EmitInteger, MVT::i32, 0, 
/*32171*/     OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*32183*/     OPC_EmitInteger, MVT::i32, 1, 
/*32186*/     OPC_EmitRegister, MVT::i32, AMDGPU::PRED_SEL_OFF,
/*32189*/     OPC_EmitInteger, MVT::i32, 0, 
/*32192*/     OPC_EmitInteger, MVT::i32, 0, 
/*32195*/     OPC_MorphNodeTo, TARGET_VAL(AMDGPU::SIN_cm), 0,
                  1/*#VTs*/, MVT::f32, 13/*#Ops*/, 1, 2, 3, 4, 0, 5, 6, 7, 8, 9, 10, 11, 12, 
              // Src: (SIN_HW:f32 f32:f32:$src0) - Complexity = 3
              // Dst: (SIN_cm:f32 f32:f32:$src0)
/*32215*/   0, /*End of Scope*/
/*32216*/ /*SwitchOpcode*/ 23|128,2/*279*/,  TARGET_VAL(AMDGPUISD::COS_HW),// ->32499
/*32220*/   OPC_RecordChild0, // #0 = $src0
/*32221*/   OPC_CheckChild0Type, MVT::f32,
/*32223*/   OPC_CheckType, MVT::f32,
/*32225*/   OPC_Scope, 67, /*->32294*/ // 4 children in Scope
/*32227*/     OPC_CheckPatternPredicate, 1, // (Subtarget.getGeneration() <= AMDGPUSubtarget::R700)
/*32229*/     OPC_EmitInteger, MVT::i32, 1, 
/*32232*/     OPC_EmitInteger, MVT::i32, 0, 
/*32235*/     OPC_EmitInteger, MVT::i32, 0, 
/*32238*/     OPC_EmitInteger, MVT::i32, 0, 
/*32241*/     OPC_EmitInteger, MVT::i32, 0, 
/*32244*/     OPC_EmitInteger, MVT::i32, 0, 
/*32247*/     OPC_EmitInteger, MVT::i32, 0, 
/*32250*/     OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*32262*/     OPC_EmitInteger, MVT::i32, 1, 
/*32265*/     OPC_EmitRegister, MVT::i32, AMDGPU::PRED_SEL_OFF,
/*32268*/     OPC_EmitInteger, MVT::i32, 0, 
/*32271*/     OPC_EmitInteger, MVT::i32, 0, 
/*32274*/     OPC_MorphNodeTo, TARGET_VAL(AMDGPU::COS_r600), 0,
                  1/*#VTs*/, MVT::f32, 13/*#Ops*/, 1, 2, 3, 4, 0, 5, 6, 7, 8, 9, 10, 11, 12, 
              // Src: (COS_HW:f32 f32:f32:$src0) - Complexity = 3
              // Dst: (COS_r600:f32 f32:f32:$src0)
/*32294*/   /*Scope*/ 67, /*->32362*/
/*32295*/     OPC_CheckPatternPredicate, 6, // (Subtarget.getGeneration() == AMDGPUSubtarget::R700)
/*32297*/     OPC_EmitInteger, MVT::i32, 1, 
/*32300*/     OPC_EmitInteger, MVT::i32, 0, 
/*32303*/     OPC_EmitInteger, MVT::i32, 0, 
/*32306*/     OPC_EmitInteger, MVT::i32, 0, 
/*32309*/     OPC_EmitInteger, MVT::i32, 0, 
/*32312*/     OPC_EmitInteger, MVT::i32, 0, 
/*32315*/     OPC_EmitInteger, MVT::i32, 0, 
/*32318*/     OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*32330*/     OPC_EmitInteger, MVT::i32, 1, 
/*32333*/     OPC_EmitRegister, MVT::i32, AMDGPU::PRED_SEL_OFF,
/*32336*/     OPC_EmitInteger, MVT::i32, 0, 
/*32339*/     OPC_EmitInteger, MVT::i32, 0, 
/*32342*/     OPC_MorphNodeTo, TARGET_VAL(AMDGPU::COS_r700), 0,
                  1/*#VTs*/, MVT::f32, 13/*#Ops*/, 1, 2, 3, 4, 0, 5, 6, 7, 8, 9, 10, 11, 12, 
              // Src: (COS_HW:f32 f32:f32:$src0) - Complexity = 3
              // Dst: (COS_r700:f32 f32:f32:$src0)
/*32362*/   /*Scope*/ 67, /*->32430*/
/*32363*/     OPC_CheckPatternPredicate, 5, // (Subtarget.getGeneration() >= AMDGPUSubtarget::EVERGREEN && Subtarget.getGeneration() < AMDGPUSubtarget::SOUTHERN_ISLANDS && !Subtarget.hasCaymanISA())
/*32365*/     OPC_EmitInteger, MVT::i32, 1, 
/*32368*/     OPC_EmitInteger, MVT::i32, 0, 
/*32371*/     OPC_EmitInteger, MVT::i32, 0, 
/*32374*/     OPC_EmitInteger, MVT::i32, 0, 
/*32377*/     OPC_EmitInteger, MVT::i32, 0, 
/*32380*/     OPC_EmitInteger, MVT::i32, 0, 
/*32383*/     OPC_EmitInteger, MVT::i32, 0, 
/*32386*/     OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*32398*/     OPC_EmitInteger, MVT::i32, 1, 
/*32401*/     OPC_EmitRegister, MVT::i32, AMDGPU::PRED_SEL_OFF,
/*32404*/     OPC_EmitInteger, MVT::i32, 0, 
/*32407*/     OPC_EmitInteger, MVT::i32, 0, 
/*32410*/     OPC_MorphNodeTo, TARGET_VAL(AMDGPU::COS_eg), 0,
                  1/*#VTs*/, MVT::f32, 13/*#Ops*/, 1, 2, 3, 4, 0, 5, 6, 7, 8, 9, 10, 11, 12, 
              // Src: (COS_HW:f32 f32:f32:$src0) - Complexity = 3
              // Dst: (COS_eg:f32 f32:f32:$src0)
/*32430*/   /*Scope*/ 67, /*->32498*/
/*32431*/     OPC_CheckPatternPredicate, 4, // (Subtarget.hasCaymanISA())
/*32433*/     OPC_EmitInteger, MVT::i32, 1, 
/*32436*/     OPC_EmitInteger, MVT::i32, 0, 
/*32439*/     OPC_EmitInteger, MVT::i32, 0, 
/*32442*/     OPC_EmitInteger, MVT::i32, 0, 
/*32445*/     OPC_EmitInteger, MVT::i32, 0, 
/*32448*/     OPC_EmitInteger, MVT::i32, 0, 
/*32451*/     OPC_EmitInteger, MVT::i32, 0, 
/*32454*/     OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*32466*/     OPC_EmitInteger, MVT::i32, 1, 
/*32469*/     OPC_EmitRegister, MVT::i32, AMDGPU::PRED_SEL_OFF,
/*32472*/     OPC_EmitInteger, MVT::i32, 0, 
/*32475*/     OPC_EmitInteger, MVT::i32, 0, 
/*32478*/     OPC_MorphNodeTo, TARGET_VAL(AMDGPU::COS_cm), 0,
                  1/*#VTs*/, MVT::f32, 13/*#Ops*/, 1, 2, 3, 4, 0, 5, 6, 7, 8, 9, 10, 11, 12, 
              // Src: (COS_HW:f32 f32:f32:$src0) - Complexity = 3
              // Dst: (COS_cm:f32 f32:f32:$src0)
/*32498*/   0, /*End of Scope*/
/*32499*/ /*SwitchOpcode*/ 13,  TARGET_VAL(ISD::FP_ROUND),// ->32515
/*32502*/   OPC_RecordChild0, // #0 = $src0
/*32503*/   OPC_CheckType, MVT::f32,
/*32505*/   OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*32507*/   OPC_MorphNodeTo, TARGET_VAL(AMDGPU::V_CVT_F32_F64_e32), 0,
                1/*#VTs*/, MVT::f32, 1/*#Ops*/, 0, 
            // Src: (fround:f32 f64:f64:$src0) - Complexity = 3
            // Dst: (V_CVT_F32_F64_e32:f32 f64:f64:$src0)
/*32515*/ /*SwitchOpcode*/ 15,  TARGET_VAL(ISD::FP_EXTEND),// ->32533
/*32518*/   OPC_RecordChild0, // #0 = $src0
/*32519*/   OPC_CheckChild0Type, MVT::f32,
/*32521*/   OPC_CheckType, MVT::f64,
/*32523*/   OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*32525*/   OPC_MorphNodeTo, TARGET_VAL(AMDGPU::V_CVT_F64_F32_e32), 0,
                1/*#VTs*/, MVT::f64, 1/*#Ops*/, 0, 
            // Src: (fextend:f64 f32:f32:$src0) - Complexity = 3
            // Dst: (V_CVT_F64_F32_e32:f64 f32:f32:$src0)
/*32533*/ /*SwitchOpcode*/ 23|128,4/*535*/,  TARGET_VAL(ISD::FSQRT),// ->33072
/*32537*/   OPC_RecordChild0, // #0 = $src0
/*32538*/   OPC_SwitchType /*2 cases */, 5|128,4/*517*/,  MVT::f32,// ->33059
/*32542*/     OPC_Scope, 10, /*->32554*/ // 4 children in Scope
/*32544*/       OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*32546*/       OPC_MorphNodeTo, TARGET_VAL(AMDGPU::V_SQRT_F32_e32), 0,
                    1/*#VTs*/, MVT::f32, 1/*#Ops*/, 0, 
                // Src: (fsqrt:f32 f32:f32:$src0) - Complexity = 3
                // Dst: (V_SQRT_F32_e32:f32 f32:f32:$src0)
/*32554*/     /*Scope*/ 38|128,1/*166*/, /*->32722*/
/*32556*/       OPC_CheckPatternPredicate, 1, // (Subtarget.getGeneration() <= AMDGPUSubtarget::R700)
/*32558*/       OPC_EmitInteger, MVT::i32, 0, 
/*32561*/       OPC_EmitInteger, MVT::i32, 0, 
/*32564*/       OPC_EmitInteger, MVT::i32, 1, 
/*32567*/       OPC_EmitInteger, MVT::i32, 0, 
/*32570*/       OPC_EmitInteger, MVT::i32, 0, 
/*32573*/       OPC_EmitInteger, MVT::i32, 0, 
/*32576*/       OPC_EmitInteger, MVT::i32, 0, 
/*32579*/       OPC_EmitInteger, MVT::i32, 0, 
/*32582*/       OPC_EmitInteger, MVT::i32, 0, 
/*32585*/       OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*32597*/       OPC_EmitInteger, MVT::i32, 1, 
/*32600*/       OPC_EmitInteger, MVT::i32, 0, 
/*32603*/       OPC_EmitInteger, MVT::i32, 0, 
/*32606*/       OPC_EmitInteger, MVT::i32, 0, 
/*32609*/       OPC_EmitInteger, MVT::i32, 0, 
/*32612*/       OPC_EmitInteger, MVT::i32, 0, 
/*32615*/       OPC_EmitInteger, MVT::i32, 0, 
/*32618*/       OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*32630*/       OPC_EmitInteger, MVT::i32, 1, 
/*32633*/       OPC_EmitRegister, MVT::i32, AMDGPU::PRED_SEL_OFF,
/*32636*/       OPC_EmitInteger, MVT::i32, 0, 
/*32639*/       OPC_EmitInteger, MVT::i32, 0, 
/*32642*/       OPC_EmitNode, TARGET_VAL(AMDGPU::RECIPSQRT_CLAMPED_r600), 0,
                    1/*#VTs*/, MVT::i32, 13/*#Ops*/, 11, 12, 13, 14, 0, 15, 16, 17, 18, 19, 20, 21, 22,  // Results = #23
/*32662*/       OPC_EmitInteger, MVT::i32, 0, 
/*32665*/       OPC_EmitInteger, MVT::i32, 0, 
/*32668*/       OPC_EmitInteger, MVT::i32, 0, 
/*32671*/       OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*32683*/       OPC_EmitInteger, MVT::i32, 1, 
/*32686*/       OPC_EmitRegister, MVT::i32, AMDGPU::PRED_SEL_OFF,
/*32689*/       OPC_EmitInteger, MVT::i32, 0, 
/*32692*/       OPC_EmitInteger, MVT::i32, 0, 
/*32695*/       OPC_MorphNodeTo, TARGET_VAL(AMDGPU::MUL), 0,
                    1/*#VTs*/, MVT::f32, 20/*#Ops*/, 1, 2, 3, 4, 5, 6, 0, 7, 8, 9, 10, 23, 24, 25, 26, 27, 28, 29, 30, 31, 
                // Src: (fsqrt:f32 f32:f32:$src) - Complexity = 3
                // Dst: (MUL:f32 ?:f32:$src, (RECIPSQRT_CLAMPED_r600:i32 ?:f32:$src))
/*32722*/     /*Scope*/ 38|128,1/*166*/, /*->32890*/
/*32724*/       OPC_CheckPatternPredicate, 5, // (Subtarget.getGeneration() >= AMDGPUSubtarget::EVERGREEN && Subtarget.getGeneration() < AMDGPUSubtarget::SOUTHERN_ISLANDS && !Subtarget.hasCaymanISA())
/*32726*/       OPC_EmitInteger, MVT::i32, 0, 
/*32729*/       OPC_EmitInteger, MVT::i32, 0, 
/*32732*/       OPC_EmitInteger, MVT::i32, 1, 
/*32735*/       OPC_EmitInteger, MVT::i32, 0, 
/*32738*/       OPC_EmitInteger, MVT::i32, 0, 
/*32741*/       OPC_EmitInteger, MVT::i32, 0, 
/*32744*/       OPC_EmitInteger, MVT::i32, 0, 
/*32747*/       OPC_EmitInteger, MVT::i32, 0, 
/*32750*/       OPC_EmitInteger, MVT::i32, 0, 
/*32753*/       OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*32765*/       OPC_EmitInteger, MVT::i32, 1, 
/*32768*/       OPC_EmitInteger, MVT::i32, 0, 
/*32771*/       OPC_EmitInteger, MVT::i32, 0, 
/*32774*/       OPC_EmitInteger, MVT::i32, 0, 
/*32777*/       OPC_EmitInteger, MVT::i32, 0, 
/*32780*/       OPC_EmitInteger, MVT::i32, 0, 
/*32783*/       OPC_EmitInteger, MVT::i32, 0, 
/*32786*/       OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*32798*/       OPC_EmitInteger, MVT::i32, 1, 
/*32801*/       OPC_EmitRegister, MVT::i32, AMDGPU::PRED_SEL_OFF,
/*32804*/       OPC_EmitInteger, MVT::i32, 0, 
/*32807*/       OPC_EmitInteger, MVT::i32, 0, 
/*32810*/       OPC_EmitNode, TARGET_VAL(AMDGPU::RECIPSQRT_CLAMPED_eg), 0,
                    1/*#VTs*/, MVT::i32, 13/*#Ops*/, 11, 12, 13, 14, 0, 15, 16, 17, 18, 19, 20, 21, 22,  // Results = #23
/*32830*/       OPC_EmitInteger, MVT::i32, 0, 
/*32833*/       OPC_EmitInteger, MVT::i32, 0, 
/*32836*/       OPC_EmitInteger, MVT::i32, 0, 
/*32839*/       OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*32851*/       OPC_EmitInteger, MVT::i32, 1, 
/*32854*/       OPC_EmitRegister, MVT::i32, AMDGPU::PRED_SEL_OFF,
/*32857*/       OPC_EmitInteger, MVT::i32, 0, 
/*32860*/       OPC_EmitInteger, MVT::i32, 0, 
/*32863*/       OPC_MorphNodeTo, TARGET_VAL(AMDGPU::MUL), 0,
                    1/*#VTs*/, MVT::f32, 20/*#Ops*/, 1, 2, 3, 4, 5, 6, 0, 7, 8, 9, 10, 23, 24, 25, 26, 27, 28, 29, 30, 31, 
                // Src: (fsqrt:f32 f32:f32:$src) - Complexity = 3
                // Dst: (MUL:f32 ?:f32:$src, (RECIPSQRT_CLAMPED_eg:i32 ?:f32:$src))
/*32890*/     /*Scope*/ 38|128,1/*166*/, /*->33058*/
/*32892*/       OPC_CheckPatternPredicate, 4, // (Subtarget.hasCaymanISA())
/*32894*/       OPC_EmitInteger, MVT::i32, 0, 
/*32897*/       OPC_EmitInteger, MVT::i32, 0, 
/*32900*/       OPC_EmitInteger, MVT::i32, 1, 
/*32903*/       OPC_EmitInteger, MVT::i32, 0, 
/*32906*/       OPC_EmitInteger, MVT::i32, 0, 
/*32909*/       OPC_EmitInteger, MVT::i32, 0, 
/*32912*/       OPC_EmitInteger, MVT::i32, 0, 
/*32915*/       OPC_EmitInteger, MVT::i32, 0, 
/*32918*/       OPC_EmitInteger, MVT::i32, 0, 
/*32921*/       OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*32933*/       OPC_EmitInteger, MVT::i32, 1, 
/*32936*/       OPC_EmitInteger, MVT::i32, 0, 
/*32939*/       OPC_EmitInteger, MVT::i32, 0, 
/*32942*/       OPC_EmitInteger, MVT::i32, 0, 
/*32945*/       OPC_EmitInteger, MVT::i32, 0, 
/*32948*/       OPC_EmitInteger, MVT::i32, 0, 
/*32951*/       OPC_EmitInteger, MVT::i32, 0, 
/*32954*/       OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*32966*/       OPC_EmitInteger, MVT::i32, 1, 
/*32969*/       OPC_EmitRegister, MVT::i32, AMDGPU::PRED_SEL_OFF,
/*32972*/       OPC_EmitInteger, MVT::i32, 0, 
/*32975*/       OPC_EmitInteger, MVT::i32, 0, 
/*32978*/       OPC_EmitNode, TARGET_VAL(AMDGPU::RECIPSQRT_CLAMPED_cm), 0,
                    1/*#VTs*/, MVT::i32, 13/*#Ops*/, 11, 12, 13, 14, 0, 15, 16, 17, 18, 19, 20, 21, 22,  // Results = #23
/*32998*/       OPC_EmitInteger, MVT::i32, 0, 
/*33001*/       OPC_EmitInteger, MVT::i32, 0, 
/*33004*/       OPC_EmitInteger, MVT::i32, 0, 
/*33007*/       OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*33019*/       OPC_EmitInteger, MVT::i32, 1, 
/*33022*/       OPC_EmitRegister, MVT::i32, AMDGPU::PRED_SEL_OFF,
/*33025*/       OPC_EmitInteger, MVT::i32, 0, 
/*33028*/       OPC_EmitInteger, MVT::i32, 0, 
/*33031*/       OPC_MorphNodeTo, TARGET_VAL(AMDGPU::MUL), 0,
                    1/*#VTs*/, MVT::f32, 20/*#Ops*/, 1, 2, 3, 4, 5, 6, 0, 7, 8, 9, 10, 23, 24, 25, 26, 27, 28, 29, 30, 31, 
                // Src: (fsqrt:f32 f32:f32:$src) - Complexity = 3
                // Dst: (MUL:f32 R600_Reg32:f32:$src, (RECIPSQRT_CLAMPED_cm:i32 ?:f32:$src))
/*33058*/     0, /*End of Scope*/
/*33059*/   /*SwitchType*/ 10,  MVT::f64,// ->33071
/*33061*/     OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*33063*/     OPC_MorphNodeTo, TARGET_VAL(AMDGPU::V_SQRT_F64_e32), 0,
                  1/*#VTs*/, MVT::f64, 1/*#Ops*/, 0, 
              // Src: (fsqrt:f64 f64:f64:$src0) - Complexity = 3
              // Dst: (V_SQRT_F64_e32:f64 f64:f64:$src0)
/*33071*/   0, // EndSwitchType
/*33072*/ /*SwitchOpcode*/ 30,  TARGET_VAL(ISD::FSUB),// ->33105
/*33075*/   OPC_RecordChild0, // #0 = $src0
/*33076*/   OPC_RecordChild1, // #1 = $src1
/*33077*/   OPC_SwitchType /*2 cases */, 11,  MVT::f32,// ->33091
/*33080*/     OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*33082*/     OPC_MorphNodeTo, TARGET_VAL(AMDGPU::V_SUB_F32_e32), 0,
                  1/*#VTs*/, MVT::f32, 2/*#Ops*/, 0, 1, 
              // Src: (fsub:f32 f32:f32:$src0, f32:f32:$src1) - Complexity = 3
              // Dst: (V_SUB_F32_e32:f32 f32:f32:$src0, f32:f32:$src1)
/*33091*/   /*SwitchType*/ 11,  MVT::f64,// ->33104
/*33093*/     OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*33095*/     OPC_MorphNodeTo, TARGET_VAL(AMDGPU::V_SUB_F64), 0,
                  1/*#VTs*/, MVT::f64, 2/*#Ops*/, 0, 1, 
              // Src: (fsub:f64 f64:f64:$src0, f64:f64:$src1) - Complexity = 3
              // Dst: (V_SUB_F64:f64 ?:f64:$src0, ?:f64:$src1)
/*33104*/   0, // EndSwitchType
/*33105*/ /*SwitchOpcode*/ 65,  TARGET_VAL(ISD::FMA),// ->33173
/*33108*/   OPC_RecordChild0, // #0 = $src0
/*33109*/   OPC_RecordChild1, // #1 = $src1
/*33110*/   OPC_RecordChild2, // #2 = $src2
/*33111*/   OPC_SwitchType /*2 cases */, 28,  MVT::f32,// ->33142
/*33114*/     OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*33116*/     OPC_EmitInteger, MVT::i32, 0, 
/*33119*/     OPC_EmitInteger, MVT::i32, 0, 
/*33122*/     OPC_EmitInteger, MVT::i32, 0, 
/*33125*/     OPC_EmitInteger, MVT::i32, 0, 
/*33128*/     OPC_MorphNodeTo, TARGET_VAL(AMDGPU::V_FMA_F32), 0,
                  1/*#VTs*/, MVT::f32, 7/*#Ops*/, 0, 1, 2, 3, 4, 5, 6, 
              // Src: (fma:f32 f32:f32:$src0, f32:f32:$src1, f32:f32:$src2) - Complexity = 3
              // Dst: (V_FMA_F32:f32 f32:f32:$src0, f32:f32:$src1, f32:f32:$src2)
/*33142*/   /*SwitchType*/ 28,  MVT::f64,// ->33172
/*33144*/     OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*33146*/     OPC_EmitInteger, MVT::i32, 0, 
/*33149*/     OPC_EmitInteger, MVT::i32, 0, 
/*33152*/     OPC_EmitInteger, MVT::i32, 0, 
/*33155*/     OPC_EmitInteger, MVT::i32, 0, 
/*33158*/     OPC_MorphNodeTo, TARGET_VAL(AMDGPU::V_FMA_F64), 0,
                  1/*#VTs*/, MVT::f64, 7/*#Ops*/, 0, 1, 2, 3, 4, 5, 6, 
              // Src: (fma:f64 f64:f64:$src0, f64:f64:$src1, f64:f64:$src2) - Complexity = 3
              // Dst: (V_FMA_F64:f64 f64:f64:$src0, f64:f64:$src1, f64:f64:$src2)
/*33172*/   0, // EndSwitchType
/*33173*/ /*SwitchOpcode*/ 47,  TARGET_VAL(ISD::FABS),// ->33223
/*33176*/   OPC_RecordChild0, // #0 = $src
/*33177*/   OPC_CheckType, MVT::f32,
/*33179*/   OPC_Scope, 30, /*->33211*/ // 2 children in Scope
/*33181*/     OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*33183*/     OPC_EmitInteger, MVT::i32, 0, 
/*33186*/     OPC_EmitInteger, MVT::i32, 1, 
/*33189*/     OPC_EmitInteger, MVT::i32, 0, 
/*33192*/     OPC_EmitInteger, MVT::i32, 0, 
/*33195*/     OPC_EmitInteger, MVT::i32, 0, 
/*33198*/     OPC_MorphNodeTo, TARGET_VAL(AMDGPU::V_ADD_F32_e64), 0,
                  1/*#VTs*/, MVT::f32, 6/*#Ops*/, 0, 1, 2, 3, 4, 5, 
              // Src: (fabs:f32 f32:f32:$src) - Complexity = 3
              // Dst: (V_ADD_F32_e64:f32 ?:f32:$src, 0:i32, 1:i32, 0:i32, 0:i32, 0:i32)
/*33211*/   /*Scope*/ 10, /*->33222*/
/*33212*/     OPC_CheckPatternPredicate, 3, // (Subtarget.getGeneration() <= AMDGPUSubtarget::NORTHERN_ISLANDS)
/*33214*/     OPC_MorphNodeTo, TARGET_VAL(AMDGPU::FABS_R600), 0,
                  1/*#VTs*/, MVT::f32, 1/*#Ops*/, 0, 
              // Src: (fabs:f32 f32:f32:$src0) - Complexity = 3
              // Dst: (FABS_R600:f32 f32:f32:$src0)
/*33222*/   0, /*End of Scope*/
/*33223*/ /*SwitchOpcode*/ 47,  TARGET_VAL(ISD::FNEG),// ->33273
/*33226*/   OPC_RecordChild0, // #0 = $src
/*33227*/   OPC_CheckType, MVT::f32,
/*33229*/   OPC_Scope, 30, /*->33261*/ // 2 children in Scope
/*33231*/     OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*33233*/     OPC_EmitInteger, MVT::i32, 0, 
/*33236*/     OPC_EmitInteger, MVT::i32, 0, 
/*33239*/     OPC_EmitInteger, MVT::i32, 0, 
/*33242*/     OPC_EmitInteger, MVT::i32, 0, 
/*33245*/     OPC_EmitInteger, MVT::i32, 1, 
/*33248*/     OPC_MorphNodeTo, TARGET_VAL(AMDGPU::V_ADD_F32_e64), 0,
                  1/*#VTs*/, MVT::f32, 6/*#Ops*/, 0, 1, 2, 3, 4, 5, 
              // Src: (fneg:f32 f32:f32:$src) - Complexity = 3
              // Dst: (V_ADD_F32_e64:f32 ?:f32:$src, 0:i32, 0:i32, 0:i32, 0:i32, 1:i32)
/*33261*/   /*Scope*/ 10, /*->33272*/
/*33262*/     OPC_CheckPatternPredicate, 3, // (Subtarget.getGeneration() <= AMDGPUSubtarget::NORTHERN_ISLANDS)
/*33264*/     OPC_MorphNodeTo, TARGET_VAL(AMDGPU::FNEG_R600), 0,
                  1/*#VTs*/, MVT::f32, 1/*#Ops*/, 0, 
              // Src: (fneg:f32 f32:f32:$src0) - Complexity = 3
              // Dst: (FNEG_R600:f32 f32:f32:$src0)
/*33272*/   0, /*End of Scope*/
/*33273*/ /*SwitchOpcode*/ 93|128,5/*733*/,  TARGET_VAL(ISD::FPOW),// ->34010
/*33277*/   OPC_RecordChild0, // #0 = $src0
/*33278*/   OPC_RecordChild1, // #1 = $src1
/*33279*/   OPC_CheckType, MVT::f32,
/*33281*/   OPC_Scope, 103|128,1/*231*/, /*->33515*/ // 4 children in Scope
/*33284*/     OPC_CheckPatternPredicate, 1, // (Subtarget.getGeneration() <= AMDGPUSubtarget::R700)
/*33286*/     OPC_EmitInteger, MVT::i32, 1, 
/*33289*/     OPC_EmitInteger, MVT::i32, 0, 
/*33292*/     OPC_EmitInteger, MVT::i32, 0, 
/*33295*/     OPC_EmitInteger, MVT::i32, 0, 
/*33298*/     OPC_EmitInteger, MVT::i32, 0, 
/*33301*/     OPC_EmitInteger, MVT::i32, 0, 
/*33304*/     OPC_EmitInteger, MVT::i32, 1, 
/*33307*/     OPC_EmitInteger, MVT::i32, 0, 
/*33310*/     OPC_EmitInteger, MVT::i32, 0, 
/*33313*/     OPC_EmitInteger, MVT::i32, 0, 
/*33316*/     OPC_EmitInteger, MVT::i32, 0, 
/*33319*/     OPC_EmitInteger, MVT::i32, 0, 
/*33322*/     OPC_EmitInteger, MVT::i32, 0, 
/*33325*/     OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*33337*/     OPC_EmitInteger, MVT::i32, 1, 
/*33340*/     OPC_EmitInteger, MVT::i32, 0, 
/*33343*/     OPC_EmitInteger, MVT::i32, 0, 
/*33346*/     OPC_EmitInteger, MVT::i32, 0, 
/*33349*/     OPC_EmitInteger, MVT::i32, 0, 
/*33352*/     OPC_EmitInteger, MVT::i32, 0, 
/*33355*/     OPC_EmitInteger, MVT::i32, 0, 
/*33358*/     OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*33370*/     OPC_EmitInteger, MVT::i32, 1, 
/*33373*/     OPC_EmitRegister, MVT::i32, AMDGPU::PRED_SEL_OFF,
/*33376*/     OPC_EmitInteger, MVT::i32, 0, 
/*33379*/     OPC_EmitInteger, MVT::i32, 0, 
/*33382*/     OPC_EmitNode, TARGET_VAL(AMDGPU::LOG_IEEE_r600), 0,
                  1/*#VTs*/, MVT::i32, 13/*#Ops*/, 16, 17, 18, 19, 0, 20, 21, 22, 23, 24, 25, 26, 27,  // Results = #28
/*33402*/     OPC_EmitInteger, MVT::i32, 0, 
/*33405*/     OPC_EmitInteger, MVT::i32, 0, 
/*33408*/     OPC_EmitInteger, MVT::i32, 0, 
/*33411*/     OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*33423*/     OPC_EmitInteger, MVT::i32, 1, 
/*33426*/     OPC_EmitRegister, MVT::i32, AMDGPU::PRED_SEL_OFF,
/*33429*/     OPC_EmitInteger, MVT::i32, 0, 
/*33432*/     OPC_EmitInteger, MVT::i32, 0, 
/*33435*/     OPC_EmitNode, TARGET_VAL(AMDGPU::MUL), 0,
                  1/*#VTs*/, MVT::i32, 20/*#Ops*/, 6, 7, 8, 9, 10, 11, 1, 12, 13, 14, 15, 28, 29, 30, 31, 32, 33, 34, 35, 36,  // Results = #37
/*33462*/     OPC_EmitInteger, MVT::i32, 0, 
/*33465*/     OPC_EmitInteger, MVT::i32, 0, 
/*33468*/     OPC_EmitInteger, MVT::i32, 0, 
/*33471*/     OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*33483*/     OPC_EmitInteger, MVT::i32, 1, 
/*33486*/     OPC_EmitRegister, MVT::i32, AMDGPU::PRED_SEL_OFF,
/*33489*/     OPC_EmitInteger, MVT::i32, 0, 
/*33492*/     OPC_EmitInteger, MVT::i32, 0, 
/*33495*/     OPC_MorphNodeTo, TARGET_VAL(AMDGPU::EXP_IEEE_r600), 0,
                  1/*#VTs*/, MVT::f32, 13/*#Ops*/, 2, 3, 4, 5, 37, 38, 39, 40, 41, 42, 43, 44, 45, 
              // Src: (fpow:f32 f32:f32:$src0, f32:f32:$src1) - Complexity = 3
              // Dst: (EXP_IEEE_r600:f32 (MUL:i32 f32:f32:$src1, (LOG_IEEE_r600:i32 f32:f32:$src0)))
/*33515*/   /*Scope*/ 103|128,1/*231*/, /*->33748*/
/*33517*/     OPC_CheckPatternPredicate, 5, // (Subtarget.getGeneration() >= AMDGPUSubtarget::EVERGREEN && Subtarget.getGeneration() < AMDGPUSubtarget::SOUTHERN_ISLANDS && !Subtarget.hasCaymanISA())
/*33519*/     OPC_EmitInteger, MVT::i32, 1, 
/*33522*/     OPC_EmitInteger, MVT::i32, 0, 
/*33525*/     OPC_EmitInteger, MVT::i32, 0, 
/*33528*/     OPC_EmitInteger, MVT::i32, 0, 
/*33531*/     OPC_EmitInteger, MVT::i32, 0, 
/*33534*/     OPC_EmitInteger, MVT::i32, 0, 
/*33537*/     OPC_EmitInteger, MVT::i32, 1, 
/*33540*/     OPC_EmitInteger, MVT::i32, 0, 
/*33543*/     OPC_EmitInteger, MVT::i32, 0, 
/*33546*/     OPC_EmitInteger, MVT::i32, 0, 
/*33549*/     OPC_EmitInteger, MVT::i32, 0, 
/*33552*/     OPC_EmitInteger, MVT::i32, 0, 
/*33555*/     OPC_EmitInteger, MVT::i32, 0, 
/*33558*/     OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*33570*/     OPC_EmitInteger, MVT::i32, 1, 
/*33573*/     OPC_EmitInteger, MVT::i32, 0, 
/*33576*/     OPC_EmitInteger, MVT::i32, 0, 
/*33579*/     OPC_EmitInteger, MVT::i32, 0, 
/*33582*/     OPC_EmitInteger, MVT::i32, 0, 
/*33585*/     OPC_EmitInteger, MVT::i32, 0, 
/*33588*/     OPC_EmitInteger, MVT::i32, 0, 
/*33591*/     OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*33603*/     OPC_EmitInteger, MVT::i32, 1, 
/*33606*/     OPC_EmitRegister, MVT::i32, AMDGPU::PRED_SEL_OFF,
/*33609*/     OPC_EmitInteger, MVT::i32, 0, 
/*33612*/     OPC_EmitInteger, MVT::i32, 0, 
/*33615*/     OPC_EmitNode, TARGET_VAL(AMDGPU::LOG_IEEE_eg), 0,
                  1/*#VTs*/, MVT::i32, 13/*#Ops*/, 16, 17, 18, 19, 0, 20, 21, 22, 23, 24, 25, 26, 27,  // Results = #28
/*33635*/     OPC_EmitInteger, MVT::i32, 0, 
/*33638*/     OPC_EmitInteger, MVT::i32, 0, 
/*33641*/     OPC_EmitInteger, MVT::i32, 0, 
/*33644*/     OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*33656*/     OPC_EmitInteger, MVT::i32, 1, 
/*33659*/     OPC_EmitRegister, MVT::i32, AMDGPU::PRED_SEL_OFF,
/*33662*/     OPC_EmitInteger, MVT::i32, 0, 
/*33665*/     OPC_EmitInteger, MVT::i32, 0, 
/*33668*/     OPC_EmitNode, TARGET_VAL(AMDGPU::MUL), 0,
                  1/*#VTs*/, MVT::i32, 20/*#Ops*/, 6, 7, 8, 9, 10, 11, 1, 12, 13, 14, 15, 28, 29, 30, 31, 32, 33, 34, 35, 36,  // Results = #37
/*33695*/     OPC_EmitInteger, MVT::i32, 0, 
/*33698*/     OPC_EmitInteger, MVT::i32, 0, 
/*33701*/     OPC_EmitInteger, MVT::i32, 0, 
/*33704*/     OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*33716*/     OPC_EmitInteger, MVT::i32, 1, 
/*33719*/     OPC_EmitRegister, MVT::i32, AMDGPU::PRED_SEL_OFF,
/*33722*/     OPC_EmitInteger, MVT::i32, 0, 
/*33725*/     OPC_EmitInteger, MVT::i32, 0, 
/*33728*/     OPC_MorphNodeTo, TARGET_VAL(AMDGPU::EXP_IEEE_eg), 0,
                  1/*#VTs*/, MVT::f32, 13/*#Ops*/, 2, 3, 4, 5, 37, 38, 39, 40, 41, 42, 43, 44, 45, 
              // Src: (fpow:f32 f32:f32:$src0, f32:f32:$src1) - Complexity = 3
              // Dst: (EXP_IEEE_eg:f32 (MUL:i32 f32:f32:$src1, (LOG_IEEE_eg:i32 f32:f32:$src0)))
/*33748*/   /*Scope*/ 103|128,1/*231*/, /*->33981*/
/*33750*/     OPC_CheckPatternPredicate, 4, // (Subtarget.hasCaymanISA())
/*33752*/     OPC_EmitInteger, MVT::i32, 1, 
/*33755*/     OPC_EmitInteger, MVT::i32, 0, 
/*33758*/     OPC_EmitInteger, MVT::i32, 0, 
/*33761*/     OPC_EmitInteger, MVT::i32, 0, 
/*33764*/     OPC_EmitInteger, MVT::i32, 0, 
/*33767*/     OPC_EmitInteger, MVT::i32, 0, 
/*33770*/     OPC_EmitInteger, MVT::i32, 1, 
/*33773*/     OPC_EmitInteger, MVT::i32, 0, 
/*33776*/     OPC_EmitInteger, MVT::i32, 0, 
/*33779*/     OPC_EmitInteger, MVT::i32, 0, 
/*33782*/     OPC_EmitInteger, MVT::i32, 0, 
/*33785*/     OPC_EmitInteger, MVT::i32, 0, 
/*33788*/     OPC_EmitInteger, MVT::i32, 0, 
/*33791*/     OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*33803*/     OPC_EmitInteger, MVT::i32, 1, 
/*33806*/     OPC_EmitInteger, MVT::i32, 0, 
/*33809*/     OPC_EmitInteger, MVT::i32, 0, 
/*33812*/     OPC_EmitInteger, MVT::i32, 0, 
/*33815*/     OPC_EmitInteger, MVT::i32, 0, 
/*33818*/     OPC_EmitInteger, MVT::i32, 0, 
/*33821*/     OPC_EmitInteger, MVT::i32, 0, 
/*33824*/     OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*33836*/     OPC_EmitInteger, MVT::i32, 1, 
/*33839*/     OPC_EmitRegister, MVT::i32, AMDGPU::PRED_SEL_OFF,
/*33842*/     OPC_EmitInteger, MVT::i32, 0, 
/*33845*/     OPC_EmitInteger, MVT::i32, 0, 
/*33848*/     OPC_EmitNode, TARGET_VAL(AMDGPU::LOG_IEEE_cm), 0,
                  1/*#VTs*/, MVT::i32, 13/*#Ops*/, 16, 17, 18, 19, 0, 20, 21, 22, 23, 24, 25, 26, 27,  // Results = #28
/*33868*/     OPC_EmitInteger, MVT::i32, 0, 
/*33871*/     OPC_EmitInteger, MVT::i32, 0, 
/*33874*/     OPC_EmitInteger, MVT::i32, 0, 
/*33877*/     OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*33889*/     OPC_EmitInteger, MVT::i32, 1, 
/*33892*/     OPC_EmitRegister, MVT::i32, AMDGPU::PRED_SEL_OFF,
/*33895*/     OPC_EmitInteger, MVT::i32, 0, 
/*33898*/     OPC_EmitInteger, MVT::i32, 0, 
/*33901*/     OPC_EmitNode, TARGET_VAL(AMDGPU::MUL), 0,
                  1/*#VTs*/, MVT::i32, 20/*#Ops*/, 6, 7, 8, 9, 10, 11, 1, 12, 13, 14, 15, 28, 29, 30, 31, 32, 33, 34, 35, 36,  // Results = #37
/*33928*/     OPC_EmitInteger, MVT::i32, 0, 
/*33931*/     OPC_EmitInteger, MVT::i32, 0, 
/*33934*/     OPC_EmitInteger, MVT::i32, 0, 
/*33937*/     OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*33949*/     OPC_EmitInteger, MVT::i32, 1, 
/*33952*/     OPC_EmitRegister, MVT::i32, AMDGPU::PRED_SEL_OFF,
/*33955*/     OPC_EmitInteger, MVT::i32, 0, 
/*33958*/     OPC_EmitInteger, MVT::i32, 0, 
/*33961*/     OPC_MorphNodeTo, TARGET_VAL(AMDGPU::EXP_IEEE_cm), 0,
                  1/*#VTs*/, MVT::f32, 13/*#Ops*/, 2, 3, 4, 5, 37, 38, 39, 40, 41, 42, 43, 44, 45, 
              // Src: (fpow:f32 f32:f32:$src0, f32:f32:$src1) - Complexity = 3
              // Dst: (EXP_IEEE_cm:f32 (MUL:i32 f32:f32:$src1, (LOG_IEEE_cm:i32 f32:f32:$src0)))
/*33981*/   /*Scope*/ 27, /*->34009*/
/*33982*/     OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*33984*/     OPC_EmitNode, TARGET_VAL(AMDGPU::V_LOG_F32_e32), 0,
                  1/*#VTs*/, MVT::i32, 1/*#Ops*/, 0,  // Results = #2
/*33992*/     OPC_EmitNode, TARGET_VAL(AMDGPU::V_MUL_LEGACY_F32_e32), 0,
                  1/*#VTs*/, MVT::i32, 2/*#Ops*/, 1, 2,  // Results = #3
/*34001*/     OPC_MorphNodeTo, TARGET_VAL(AMDGPU::V_EXP_F32_e32), 0,
                  1/*#VTs*/, MVT::f32, 1/*#Ops*/, 3, 
              // Src: (fpow:f32 f32:f32:$src0, f32:f32:$src1) - Complexity = 3
              // Dst: (V_EXP_F32_e32:f32 (V_MUL_LEGACY_F32_e32:i32 f32:f32:$src1, (V_LOG_F32_e32:i32 f32:f32:$src0)))
/*34009*/   0, /*End of Scope*/
/*34010*/ /*SwitchOpcode*/ 37,  TARGET_VAL(ISD::FCOS),// ->34050
/*34013*/   OPC_RecordChild0, // #0 = $src0
/*34014*/   OPC_CheckType, MVT::f32,
/*34016*/   OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*34018*/   OPC_EmitInteger, MVT::i32, 3|128,115|128,11|128,113|128,3/*1042479491*/, 
/*34025*/   OPC_EmitNode, TARGET_VAL(AMDGPU::V_MOV_B32_e32), 0,
                1/*#VTs*/, MVT::i32, 1/*#Ops*/, 1,  // Results = #2
/*34033*/   OPC_EmitNode, TARGET_VAL(AMDGPU::V_MUL_F32_e32), 0,
                1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 2,  // Results = #3
/*34042*/   OPC_MorphNodeTo, TARGET_VAL(AMDGPU::V_COS_F32_e32), 0,
                1/*#VTs*/, MVT::f32, 1/*#Ops*/, 3, 
            // Src: (fcos:f32 f32:f32:$src0) - Complexity = 3
            // Dst: (V_COS_F32_e32:f32 (V_MUL_F32_e32:i32 ?:f32:$src0, (V_MOV_B32_e32:i32 1042479491:i32)))
/*34050*/ /*SwitchOpcode*/ 37,  TARGET_VAL(ISD::FSIN),// ->34090
/*34053*/   OPC_RecordChild0, // #0 = $src0
/*34054*/   OPC_CheckType, MVT::f32,
/*34056*/   OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*34058*/   OPC_EmitInteger, MVT::i32, 3|128,115|128,11|128,113|128,3/*1042479491*/, 
/*34065*/   OPC_EmitNode, TARGET_VAL(AMDGPU::V_MOV_B32_e32), 0,
                1/*#VTs*/, MVT::i32, 1/*#Ops*/, 1,  // Results = #2
/*34073*/   OPC_EmitNode, TARGET_VAL(AMDGPU::V_MUL_F32_e32), 0,
                1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 2,  // Results = #3
/*34082*/   OPC_MorphNodeTo, TARGET_VAL(AMDGPU::V_SIN_F32_e32), 0,
                1/*#VTs*/, MVT::f32, 1/*#Ops*/, 3, 
            // Src: (fsin:f32 f32:f32:$src0) - Complexity = 3
            // Dst: (V_SIN_F32_e32:f32 (V_MUL_F32_e32:i32 ?:f32:$src0, (V_MOV_B32_e32:i32 1042479491:i32)))
/*34090*/ /*SwitchOpcode*/ 49|128,6/*817*/,  TARGET_VAL(ISD::FROUND),// ->34911
/*34094*/   OPC_RecordChild0, // #0 = $x
/*34095*/   OPC_CheckType, MVT::f32,
/*34097*/   OPC_Scope, 20|128,3/*404*/, /*->34504*/ // 2 children in Scope
/*34100*/     OPC_CheckPatternPredicate, 1, // (Subtarget.getGeneration() <= AMDGPUSubtarget::R700)
/*34102*/     OPC_EmitInteger, MVT::i32, 0, 
/*34105*/     OPC_EmitInteger, MVT::i32, 0, 
/*34108*/     OPC_EmitInteger, MVT::i32, 0, 
/*34111*/     OPC_EmitInteger, MVT::i32, 0, 
/*34114*/     OPC_EmitInteger, MVT::i32, 1, 
/*34117*/     OPC_EmitInteger, MVT::i32, 0, 
/*34120*/     OPC_EmitInteger, MVT::i32, 0, 
/*34123*/     OPC_EmitInteger, MVT::i32, 0, 
/*34126*/     OPC_EmitRegister, MVT::f32, AMDGPU::HALF,
/*34129*/     OPC_EmitNode, TARGET_VAL(AMDGPU::FNEG_R600), 0,
                  1/*#VTs*/, MVT::i32, 1/*#Ops*/, 9,  // Results = #10
/*34137*/     OPC_EmitInteger, MVT::i32, 0, 
/*34140*/     OPC_EmitInteger, MVT::i32, 0, 
/*34143*/     OPC_EmitInteger, MVT::i32, 0, 
/*34146*/     OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*34158*/     OPC_EmitInteger, MVT::i32, 1, 
/*34161*/     OPC_EmitInteger, MVT::i32, 0, 
/*34164*/     OPC_EmitInteger, MVT::i32, 0, 
/*34167*/     OPC_EmitInteger, MVT::i32, 0, 
/*34170*/     OPC_EmitInteger, MVT::i32, 0, 
/*34173*/     OPC_EmitInteger, MVT::i32, 0, 
/*34176*/     OPC_EmitInteger, MVT::i32, 0, 
/*34179*/     OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*34191*/     OPC_EmitInteger, MVT::i32, 1, 
/*34194*/     OPC_EmitRegister, MVT::i32, AMDGPU::PRED_SEL_OFF,
/*34197*/     OPC_EmitInteger, MVT::i32, 0, 
/*34200*/     OPC_EmitInteger, MVT::i32, 0, 
/*34203*/     OPC_EmitNode, TARGET_VAL(AMDGPU::FRACT), 0,
                  1/*#VTs*/, MVT::i32, 13/*#Ops*/, 15, 16, 17, 18, 0, 19, 20, 21, 22, 23, 24, 25, 26,  // Results = #27
/*34223*/     OPC_EmitInteger, MVT::i32, 0, 
/*34226*/     OPC_EmitInteger, MVT::i32, 0, 
/*34229*/     OPC_EmitInteger, MVT::i32, 0, 
/*34232*/     OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*34244*/     OPC_EmitInteger, MVT::i32, 1, 
/*34247*/     OPC_EmitRegister, MVT::i32, AMDGPU::PRED_SEL_OFF,
/*34250*/     OPC_EmitInteger, MVT::i32, 0, 
/*34253*/     OPC_EmitInteger, MVT::i32, 0, 
/*34256*/     OPC_EmitNode, TARGET_VAL(AMDGPU::ADD), 0,
                  1/*#VTs*/, MVT::i32, 20/*#Ops*/, 3, 4, 5, 6, 7, 8, 10, 11, 12, 13, 14, 27, 28, 29, 30, 31, 32, 33, 34, 35,  // Results = #36
/*34283*/     OPC_EmitInteger, MVT::i32, 0, 
/*34286*/     OPC_EmitInteger, MVT::i32, 0, 
/*34289*/     OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*34301*/     OPC_EmitInteger, MVT::i32, 1, 
/*34304*/     OPC_EmitInteger, MVT::i32, 0, 
/*34307*/     OPC_EmitInteger, MVT::i32, 0, 
/*34310*/     OPC_EmitInteger, MVT::i32, 0, 
/*34313*/     OPC_EmitInteger, MVT::i32, 0, 
/*34316*/     OPC_EmitInteger, MVT::i32, 0, 
/*34319*/     OPC_EmitInteger, MVT::i32, 0, 
/*34322*/     OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*34334*/     OPC_EmitInteger, MVT::i32, 1, 
/*34337*/     OPC_EmitRegister, MVT::i32, AMDGPU::PRED_SEL_OFF,
/*34340*/     OPC_EmitInteger, MVT::i32, 0, 
/*34343*/     OPC_EmitInteger, MVT::i32, 0, 
/*34346*/     OPC_EmitNode, TARGET_VAL(AMDGPU::CEIL), 0,
                  1/*#VTs*/, MVT::i32, 13/*#Ops*/, 40, 41, 42, 43, 0, 44, 45, 46, 47, 48, 49, 50, 51,  // Results = #52
/*34366*/     OPC_EmitInteger, MVT::i32, 0, 
/*34369*/     OPC_EmitInteger, MVT::i32, 0, 
/*34372*/     OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*34384*/     OPC_EmitInteger, MVT::i32, 1, 
/*34387*/     OPC_EmitInteger, MVT::i32, 0, 
/*34390*/     OPC_EmitInteger, MVT::i32, 0, 
/*34393*/     OPC_EmitInteger, MVT::i32, 0, 
/*34396*/     OPC_EmitInteger, MVT::i32, 0, 
/*34399*/     OPC_EmitInteger, MVT::i32, 0, 
/*34402*/     OPC_EmitInteger, MVT::i32, 0, 
/*34405*/     OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*34417*/     OPC_EmitInteger, MVT::i32, 1, 
/*34420*/     OPC_EmitRegister, MVT::i32, AMDGPU::PRED_SEL_OFF,
/*34423*/     OPC_EmitInteger, MVT::i32, 0, 
/*34426*/     OPC_EmitInteger, MVT::i32, 0, 
/*34429*/     OPC_EmitNode, TARGET_VAL(AMDGPU::FLOOR), 0,
                  1/*#VTs*/, MVT::i32, 13/*#Ops*/, 56, 57, 58, 59, 0, 60, 61, 62, 63, 64, 65, 66, 67,  // Results = #68
/*34449*/     OPC_EmitInteger, MVT::i32, 0, 
/*34452*/     OPC_EmitInteger, MVT::i32, 0, 
/*34455*/     OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*34467*/     OPC_EmitInteger, MVT::i32, 1, 
/*34470*/     OPC_EmitRegister, MVT::i32, AMDGPU::PRED_SEL_OFF,
/*34473*/     OPC_EmitInteger, MVT::i32, 0, 
/*34476*/     OPC_EmitInteger, MVT::i32, 0, 
/*34479*/     OPC_MorphNodeTo, TARGET_VAL(AMDGPU::CNDGE_r600), 0,
                  1/*#VTs*/, MVT::f32, 18/*#Ops*/, 1, 2, 36, 37, 38, 39, 52, 53, 54, 55, 68, 69, 70, 71, 72, 73, 74, 75, 
              // Src: (AMDGPUround:f32 f32:f32:$x) - Complexity = 3
              // Dst: (CNDGE_r600:f32 (ADD:i32 (FNEG_R600:i32 HALF:f32), (FRACT:i32 ?:f32:$x)), (CEIL:i32 ?:f32:$x), (FLOOR:i32 ?:f32:$x))
/*34504*/   /*Scope*/ 20|128,3/*404*/, /*->34910*/
/*34506*/     OPC_CheckPatternPredicate, 2, // (Subtarget.getGeneration() == AMDGPUSubtarget::EVERGREEN|| Subtarget.getGeneration() ==AMDGPUSubtarget::NORTHERN_ISLANDS)
/*34508*/     OPC_EmitInteger, MVT::i32, 0, 
/*34511*/     OPC_EmitInteger, MVT::i32, 0, 
/*34514*/     OPC_EmitInteger, MVT::i32, 0, 
/*34517*/     OPC_EmitInteger, MVT::i32, 0, 
/*34520*/     OPC_EmitInteger, MVT::i32, 1, 
/*34523*/     OPC_EmitInteger, MVT::i32, 0, 
/*34526*/     OPC_EmitInteger, MVT::i32, 0, 
/*34529*/     OPC_EmitInteger, MVT::i32, 0, 
/*34532*/     OPC_EmitRegister, MVT::f32, AMDGPU::HALF,
/*34535*/     OPC_EmitNode, TARGET_VAL(AMDGPU::FNEG_R600), 0,
                  1/*#VTs*/, MVT::i32, 1/*#Ops*/, 9,  // Results = #10
/*34543*/     OPC_EmitInteger, MVT::i32, 0, 
/*34546*/     OPC_EmitInteger, MVT::i32, 0, 
/*34549*/     OPC_EmitInteger, MVT::i32, 0, 
/*34552*/     OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*34564*/     OPC_EmitInteger, MVT::i32, 1, 
/*34567*/     OPC_EmitInteger, MVT::i32, 0, 
/*34570*/     OPC_EmitInteger, MVT::i32, 0, 
/*34573*/     OPC_EmitInteger, MVT::i32, 0, 
/*34576*/     OPC_EmitInteger, MVT::i32, 0, 
/*34579*/     OPC_EmitInteger, MVT::i32, 0, 
/*34582*/     OPC_EmitInteger, MVT::i32, 0, 
/*34585*/     OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*34597*/     OPC_EmitInteger, MVT::i32, 1, 
/*34600*/     OPC_EmitRegister, MVT::i32, AMDGPU::PRED_SEL_OFF,
/*34603*/     OPC_EmitInteger, MVT::i32, 0, 
/*34606*/     OPC_EmitInteger, MVT::i32, 0, 
/*34609*/     OPC_EmitNode, TARGET_VAL(AMDGPU::FRACT), 0,
                  1/*#VTs*/, MVT::i32, 13/*#Ops*/, 15, 16, 17, 18, 0, 19, 20, 21, 22, 23, 24, 25, 26,  // Results = #27
/*34629*/     OPC_EmitInteger, MVT::i32, 0, 
/*34632*/     OPC_EmitInteger, MVT::i32, 0, 
/*34635*/     OPC_EmitInteger, MVT::i32, 0, 
/*34638*/     OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*34650*/     OPC_EmitInteger, MVT::i32, 1, 
/*34653*/     OPC_EmitRegister, MVT::i32, AMDGPU::PRED_SEL_OFF,
/*34656*/     OPC_EmitInteger, MVT::i32, 0, 
/*34659*/     OPC_EmitInteger, MVT::i32, 0, 
/*34662*/     OPC_EmitNode, TARGET_VAL(AMDGPU::ADD), 0,
                  1/*#VTs*/, MVT::i32, 20/*#Ops*/, 3, 4, 5, 6, 7, 8, 10, 11, 12, 13, 14, 27, 28, 29, 30, 31, 32, 33, 34, 35,  // Results = #36
/*34689*/     OPC_EmitInteger, MVT::i32, 0, 
/*34692*/     OPC_EmitInteger, MVT::i32, 0, 
/*34695*/     OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*34707*/     OPC_EmitInteger, MVT::i32, 1, 
/*34710*/     OPC_EmitInteger, MVT::i32, 0, 
/*34713*/     OPC_EmitInteger, MVT::i32, 0, 
/*34716*/     OPC_EmitInteger, MVT::i32, 0, 
/*34719*/     OPC_EmitInteger, MVT::i32, 0, 
/*34722*/     OPC_EmitInteger, MVT::i32, 0, 
/*34725*/     OPC_EmitInteger, MVT::i32, 0, 
/*34728*/     OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*34740*/     OPC_EmitInteger, MVT::i32, 1, 
/*34743*/     OPC_EmitRegister, MVT::i32, AMDGPU::PRED_SEL_OFF,
/*34746*/     OPC_EmitInteger, MVT::i32, 0, 
/*34749*/     OPC_EmitInteger, MVT::i32, 0, 
/*34752*/     OPC_EmitNode, TARGET_VAL(AMDGPU::CEIL), 0,
                  1/*#VTs*/, MVT::i32, 13/*#Ops*/, 40, 41, 42, 43, 0, 44, 45, 46, 47, 48, 49, 50, 51,  // Results = #52
/*34772*/     OPC_EmitInteger, MVT::i32, 0, 
/*34775*/     OPC_EmitInteger, MVT::i32, 0, 
/*34778*/     OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*34790*/     OPC_EmitInteger, MVT::i32, 1, 
/*34793*/     OPC_EmitInteger, MVT::i32, 0, 
/*34796*/     OPC_EmitInteger, MVT::i32, 0, 
/*34799*/     OPC_EmitInteger, MVT::i32, 0, 
/*34802*/     OPC_EmitInteger, MVT::i32, 0, 
/*34805*/     OPC_EmitInteger, MVT::i32, 0, 
/*34808*/     OPC_EmitInteger, MVT::i32, 0, 
/*34811*/     OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*34823*/     OPC_EmitInteger, MVT::i32, 1, 
/*34826*/     OPC_EmitRegister, MVT::i32, AMDGPU::PRED_SEL_OFF,
/*34829*/     OPC_EmitInteger, MVT::i32, 0, 
/*34832*/     OPC_EmitInteger, MVT::i32, 0, 
/*34835*/     OPC_EmitNode, TARGET_VAL(AMDGPU::FLOOR), 0,
                  1/*#VTs*/, MVT::i32, 13/*#Ops*/, 56, 57, 58, 59, 0, 60, 61, 62, 63, 64, 65, 66, 67,  // Results = #68
/*34855*/     OPC_EmitInteger, MVT::i32, 0, 
/*34858*/     OPC_EmitInteger, MVT::i32, 0, 
/*34861*/     OPC_EmitInteger, MVT::i32, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*34873*/     OPC_EmitInteger, MVT::i32, 1, 
/*34876*/     OPC_EmitRegister, MVT::i32, AMDGPU::PRED_SEL_OFF,
/*34879*/     OPC_EmitInteger, MVT::i32, 0, 
/*34882*/     OPC_EmitInteger, MVT::i32, 0, 
/*34885*/     OPC_MorphNodeTo, TARGET_VAL(AMDGPU::CNDGE_eg), 0,
                  1/*#VTs*/, MVT::f32, 18/*#Ops*/, 1, 2, 36, 37, 38, 39, 52, 53, 54, 55, 68, 69, 70, 71, 72, 73, 74, 75, 
              // Src: (AMDGPUround:f32 f32:f32:$x) - Complexity = 3
              // Dst: (CNDGE_eg:f32 (ADD:i32 (FNEG_R600:i32 HALF:f32), (FRACT:i32 ?:f32:$x)), (CEIL:i32 ?:f32:$x), (FLOOR:i32 ?:f32:$x))
/*34910*/   0, /*End of Scope*/
/*34911*/ /*SwitchOpcode*/ 29|128,13/*1693*/,  TARGET_VAL(ISD::INSERT_VECTOR_ELT),// ->36608
/*34915*/   OPC_RecordChild0, // #0 = $vec
/*34916*/   OPC_RecordChild1, // #1 = $elem
/*34917*/   OPC_Scope, 87|128,5/*727*/, /*->35647*/ // 2 children in Scope
/*34920*/     OPC_CheckChild1Type, MVT::i32,
/*34922*/     OPC_MoveChild, 2,
/*34924*/     OPC_Scope, 111, /*->35037*/ // 16 children in Scope
/*34926*/       OPC_CheckInteger, 0, 
/*34928*/       OPC_MoveParent,
/*34929*/       OPC_SwitchType /*4 cases */, 34,  MVT::v4i32,// ->34966
/*34932*/         OPC_Scope, 15, /*->34949*/ // 2 children in Scope
/*34934*/           OPC_CheckPatternPredicate, 3, // (Subtarget.getGeneration() <= AMDGPUSubtarget::NORTHERN_ISLANDS)
/*34936*/           OPC_EmitInteger, MVT::i32, AMDGPU::sub0,
/*34939*/           OPC_MorphNodeTo, TARGET_VAL(TargetOpcode::INSERT_SUBREG), 0,
                        1/*#VTs*/, MVT::v4i32, 3/*#Ops*/, 0, 1, 2, 
                    // Src: (vector_insert:v4i32 v4i32:v4i32:$vec, i32:i32:$elem, 0:iPTR) - Complexity = 8
                    // Dst: (INSERT_SUBREG:v4i32 ?:v4i32:$vec, ?:i32:$elem, sub0:i32)
/*34949*/         /*Scope*/ 15, /*->34965*/
/*34950*/           OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*34952*/           OPC_EmitInteger, MVT::i32, AMDGPU::sub0,
/*34955*/           OPC_MorphNodeTo, TARGET_VAL(TargetOpcode::INSERT_SUBREG), 0,
                        1/*#VTs*/, MVT::v4i32, 3/*#Ops*/, 0, 1, 2, 
                    // Src: (vector_insert:v4i32 v4i32:v4i32:$vec, i32:i32:$elem, 0:iPTR) - Complexity = 8
                    // Dst: (INSERT_SUBREG:v4i32 ?:v4i32:$vec, ?:i32:$elem, sub0:i32)
/*34965*/         0, /*End of Scope*/
/*34966*/       /*SwitchType*/ 34,  MVT::v2i32,// ->35002
/*34968*/         OPC_Scope, 15, /*->34985*/ // 2 children in Scope
/*34970*/           OPC_CheckPatternPredicate, 3, // (Subtarget.getGeneration() <= AMDGPUSubtarget::NORTHERN_ISLANDS)
/*34972*/           OPC_EmitInteger, MVT::i32, AMDGPU::sub0,
/*34975*/           OPC_MorphNodeTo, TARGET_VAL(TargetOpcode::INSERT_SUBREG), 0,
                        1/*#VTs*/, MVT::v2i32, 3/*#Ops*/, 0, 1, 2, 
                    // Src: (vector_insert:v2i32 v2i32:v2i32:$vec, i32:i32:$elem, 0:iPTR) - Complexity = 8
                    // Dst: (INSERT_SUBREG:v2i32 ?:v2i32:$vec, ?:i32:$elem, sub0:i32)
/*34985*/         /*Scope*/ 15, /*->35001*/
/*34986*/           OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*34988*/           OPC_EmitInteger, MVT::i32, AMDGPU::sub0,
/*34991*/           OPC_MorphNodeTo, TARGET_VAL(TargetOpcode::INSERT_SUBREG), 0,
                        1/*#VTs*/, MVT::v2i32, 3/*#Ops*/, 0, 1, 2, 
                    // Src: (vector_insert:v2i32 v2i32:v2i32:$vec, i32:i32:$elem, 0:iPTR) - Complexity = 8
                    // Dst: (INSERT_SUBREG:v2i32 ?:v2i32:$vec, ?:i32:$elem, sub0:i32)
/*35001*/         0, /*End of Scope*/
/*35002*/       /*SwitchType*/ 15,  MVT::v8i32,// ->35019
/*35004*/         OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*35006*/         OPC_EmitInteger, MVT::i32, AMDGPU::sub0,
/*35009*/         OPC_MorphNodeTo, TARGET_VAL(TargetOpcode::INSERT_SUBREG), 0,
                      1/*#VTs*/, MVT::v8i32, 3/*#Ops*/, 0, 1, 2, 
                  // Src: (vector_insert:v8i32 v8i32:v8i32:$vec, i32:i32:$elem, 0:iPTR) - Complexity = 8
                  // Dst: (INSERT_SUBREG:v8i32 ?:v8i32:$vec, ?:i32:$elem, sub0:i32)
/*35019*/       /*SwitchType*/ 15,  MVT::v16i32,// ->35036
/*35021*/         OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*35023*/         OPC_EmitInteger, MVT::i32, AMDGPU::sub0,
/*35026*/         OPC_MorphNodeTo, TARGET_VAL(TargetOpcode::INSERT_SUBREG), 0,
                      1/*#VTs*/, MVT::v16i32, 3/*#Ops*/, 0, 1, 2, 
                  // Src: (vector_insert:v16i32 v16i32:v16i32:$vec, i32:i32:$elem, 0:iPTR) - Complexity = 8
                  // Dst: (INSERT_SUBREG:v16i32 ?:v16i32:$vec, ?:i32:$elem, sub0:i32)
/*35036*/       0, // EndSwitchType
/*35037*/     /*Scope*/ 111, /*->35149*/
/*35038*/       OPC_CheckInteger, 1, 
/*35040*/       OPC_MoveParent,
/*35041*/       OPC_SwitchType /*4 cases */, 34,  MVT::v4i32,// ->35078
/*35044*/         OPC_Scope, 15, /*->35061*/ // 2 children in Scope
/*35046*/           OPC_CheckPatternPredicate, 3, // (Subtarget.getGeneration() <= AMDGPUSubtarget::NORTHERN_ISLANDS)
/*35048*/           OPC_EmitInteger, MVT::i32, AMDGPU::sub1,
/*35051*/           OPC_MorphNodeTo, TARGET_VAL(TargetOpcode::INSERT_SUBREG), 0,
                        1/*#VTs*/, MVT::v4i32, 3/*#Ops*/, 0, 1, 2, 
                    // Src: (vector_insert:v4i32 v4i32:v4i32:$vec, i32:i32:$elem, 1:iPTR) - Complexity = 8
                    // Dst: (INSERT_SUBREG:v4i32 ?:v4i32:$vec, ?:i32:$elem, sub1:i32)
/*35061*/         /*Scope*/ 15, /*->35077*/
/*35062*/           OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*35064*/           OPC_EmitInteger, MVT::i32, AMDGPU::sub1,
/*35067*/           OPC_MorphNodeTo, TARGET_VAL(TargetOpcode::INSERT_SUBREG), 0,
                        1/*#VTs*/, MVT::v4i32, 3/*#Ops*/, 0, 1, 2, 
                    // Src: (vector_insert:v4i32 v4i32:v4i32:$vec, i32:i32:$elem, 1:iPTR) - Complexity = 8
                    // Dst: (INSERT_SUBREG:v4i32 ?:v4i32:$vec, ?:i32:$elem, sub1:i32)
/*35077*/         0, /*End of Scope*/
/*35078*/       /*SwitchType*/ 34,  MVT::v2i32,// ->35114
/*35080*/         OPC_Scope, 15, /*->35097*/ // 2 children in Scope
/*35082*/           OPC_CheckPatternPredicate, 3, // (Subtarget.getGeneration() <= AMDGPUSubtarget::NORTHERN_ISLANDS)
/*35084*/           OPC_EmitInteger, MVT::i32, AMDGPU::sub1,
/*35087*/           OPC_MorphNodeTo, TARGET_VAL(TargetOpcode::INSERT_SUBREG), 0,
                        1/*#VTs*/, MVT::v2i32, 3/*#Ops*/, 0, 1, 2, 
                    // Src: (vector_insert:v2i32 v2i32:v2i32:$vec, i32:i32:$elem, 1:iPTR) - Complexity = 8
                    // Dst: (INSERT_SUBREG:v2i32 ?:v2i32:$vec, ?:i32:$elem, sub1:i32)
/*35097*/         /*Scope*/ 15, /*->35113*/
/*35098*/           OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*35100*/           OPC_EmitInteger, MVT::i32, AMDGPU::sub1,
/*35103*/           OPC_MorphNodeTo, TARGET_VAL(TargetOpcode::INSERT_SUBREG), 0,
                        1/*#VTs*/, MVT::v2i32, 3/*#Ops*/, 0, 1, 2, 
                    // Src: (vector_insert:v2i32 v2i32:v2i32:$vec, i32:i32:$elem, 1:iPTR) - Complexity = 8
                    // Dst: (INSERT_SUBREG:v2i32 ?:v2i32:$vec, ?:i32:$elem, sub1:i32)
/*35113*/         0, /*End of Scope*/
/*35114*/       /*SwitchType*/ 15,  MVT::v8i32,// ->35131
/*35116*/         OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*35118*/         OPC_EmitInteger, MVT::i32, AMDGPU::sub1,
/*35121*/         OPC_MorphNodeTo, TARGET_VAL(TargetOpcode::INSERT_SUBREG), 0,
                      1/*#VTs*/, MVT::v8i32, 3/*#Ops*/, 0, 1, 2, 
                  // Src: (vector_insert:v8i32 v8i32:v8i32:$vec, i32:i32:$elem, 1:iPTR) - Complexity = 8
                  // Dst: (INSERT_SUBREG:v8i32 ?:v8i32:$vec, ?:i32:$elem, sub1:i32)
/*35131*/       /*SwitchType*/ 15,  MVT::v16i32,// ->35148
/*35133*/         OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*35135*/         OPC_EmitInteger, MVT::i32, AMDGPU::sub1,
/*35138*/         OPC_MorphNodeTo, TARGET_VAL(TargetOpcode::INSERT_SUBREG), 0,
                      1/*#VTs*/, MVT::v16i32, 3/*#Ops*/, 0, 1, 2, 
                  // Src: (vector_insert:v16i32 v16i32:v16i32:$vec, i32:i32:$elem, 1:iPTR) - Complexity = 8
                  // Dst: (INSERT_SUBREG:v16i32 ?:v16i32:$vec, ?:i32:$elem, sub1:i32)
/*35148*/       0, // EndSwitchType
/*35149*/     /*Scope*/ 92, /*->35242*/
/*35150*/       OPC_CheckInteger, 2, 
/*35152*/       OPC_MoveParent,
/*35153*/       OPC_SwitchType /*4 cases */, 34,  MVT::v4i32,// ->35190
/*35156*/         OPC_Scope, 15, /*->35173*/ // 2 children in Scope
/*35158*/           OPC_CheckPatternPredicate, 3, // (Subtarget.getGeneration() <= AMDGPUSubtarget::NORTHERN_ISLANDS)
/*35160*/           OPC_EmitInteger, MVT::i32, AMDGPU::sub2,
/*35163*/           OPC_MorphNodeTo, TARGET_VAL(TargetOpcode::INSERT_SUBREG), 0,
                        1/*#VTs*/, MVT::v4i32, 3/*#Ops*/, 0, 1, 2, 
                    // Src: (vector_insert:v4i32 v4i32:v4i32:$vec, i32:i32:$elem, 2:iPTR) - Complexity = 8
                    // Dst: (INSERT_SUBREG:v4i32 ?:v4i32:$vec, ?:i32:$elem, sub2:i32)
/*35173*/         /*Scope*/ 15, /*->35189*/
/*35174*/           OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*35176*/           OPC_EmitInteger, MVT::i32, AMDGPU::sub2,
/*35179*/           OPC_MorphNodeTo, TARGET_VAL(TargetOpcode::INSERT_SUBREG), 0,
                        1/*#VTs*/, MVT::v4i32, 3/*#Ops*/, 0, 1, 2, 
                    // Src: (vector_insert:v4i32 v4i32:v4i32:$vec, i32:i32:$elem, 2:iPTR) - Complexity = 8
                    // Dst: (INSERT_SUBREG:v4i32 ?:v4i32:$vec, ?:i32:$elem, sub2:i32)
/*35189*/         0, /*End of Scope*/
/*35190*/       /*SwitchType*/ 15,  MVT::v2i32,// ->35207
/*35192*/         OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*35194*/         OPC_EmitInteger, MVT::i32, AMDGPU::sub2,
/*35197*/         OPC_MorphNodeTo, TARGET_VAL(TargetOpcode::INSERT_SUBREG), 0,
                      1/*#VTs*/, MVT::v2i32, 3/*#Ops*/, 0, 1, 2, 
                  // Src: (vector_insert:v2i32 v2i32:v2i32:$vec, i32:i32:$elem, 2:iPTR) - Complexity = 8
                  // Dst: (INSERT_SUBREG:v2i32 ?:v2i32:$vec, ?:i32:$elem, sub2:i32)
/*35207*/       /*SwitchType*/ 15,  MVT::v8i32,// ->35224
/*35209*/         OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*35211*/         OPC_EmitInteger, MVT::i32, AMDGPU::sub2,
/*35214*/         OPC_MorphNodeTo, TARGET_VAL(TargetOpcode::INSERT_SUBREG), 0,
                      1/*#VTs*/, MVT::v8i32, 3/*#Ops*/, 0, 1, 2, 
                  // Src: (vector_insert:v8i32 v8i32:v8i32:$vec, i32:i32:$elem, 2:iPTR) - Complexity = 8
                  // Dst: (INSERT_SUBREG:v8i32 ?:v8i32:$vec, ?:i32:$elem, sub2:i32)
/*35224*/       /*SwitchType*/ 15,  MVT::v16i32,// ->35241
/*35226*/         OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*35228*/         OPC_EmitInteger, MVT::i32, AMDGPU::sub2,
/*35231*/         OPC_MorphNodeTo, TARGET_VAL(TargetOpcode::INSERT_SUBREG), 0,
                      1/*#VTs*/, MVT::v16i32, 3/*#Ops*/, 0, 1, 2, 
                  // Src: (vector_insert:v16i32 v16i32:v16i32:$vec, i32:i32:$elem, 2:iPTR) - Complexity = 8
                  // Dst: (INSERT_SUBREG:v16i32 ?:v16i32:$vec, ?:i32:$elem, sub2:i32)
/*35241*/       0, // EndSwitchType
/*35242*/     /*Scope*/ 75, /*->35318*/
/*35243*/       OPC_CheckInteger, 3, 
/*35245*/       OPC_MoveParent,
/*35246*/       OPC_SwitchType /*3 cases */, 34,  MVT::v4i32,// ->35283
/*35249*/         OPC_Scope, 15, /*->35266*/ // 2 children in Scope
/*35251*/           OPC_CheckPatternPredicate, 3, // (Subtarget.getGeneration() <= AMDGPUSubtarget::NORTHERN_ISLANDS)
/*35253*/           OPC_EmitInteger, MVT::i32, AMDGPU::sub3,
/*35256*/           OPC_MorphNodeTo, TARGET_VAL(TargetOpcode::INSERT_SUBREG), 0,
                        1/*#VTs*/, MVT::v4i32, 3/*#Ops*/, 0, 1, 2, 
                    // Src: (vector_insert:v4i32 v4i32:v4i32:$vec, i32:i32:$elem, 3:iPTR) - Complexity = 8
                    // Dst: (INSERT_SUBREG:v4i32 ?:v4i32:$vec, ?:i32:$elem, sub3:i32)
/*35266*/         /*Scope*/ 15, /*->35282*/
/*35267*/           OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*35269*/           OPC_EmitInteger, MVT::i32, AMDGPU::sub3,
/*35272*/           OPC_MorphNodeTo, TARGET_VAL(TargetOpcode::INSERT_SUBREG), 0,
                        1/*#VTs*/, MVT::v4i32, 3/*#Ops*/, 0, 1, 2, 
                    // Src: (vector_insert:v4i32 v4i32:v4i32:$vec, i32:i32:$elem, 3:iPTR) - Complexity = 8
                    // Dst: (INSERT_SUBREG:v4i32 ?:v4i32:$vec, ?:i32:$elem, sub3:i32)
/*35282*/         0, /*End of Scope*/
/*35283*/       /*SwitchType*/ 15,  MVT::v8i32,// ->35300
/*35285*/         OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*35287*/         OPC_EmitInteger, MVT::i32, AMDGPU::sub3,
/*35290*/         OPC_MorphNodeTo, TARGET_VAL(TargetOpcode::INSERT_SUBREG), 0,
                      1/*#VTs*/, MVT::v8i32, 3/*#Ops*/, 0, 1, 2, 
                  // Src: (vector_insert:v8i32 v8i32:v8i32:$vec, i32:i32:$elem, 3:iPTR) - Complexity = 8
                  // Dst: (INSERT_SUBREG:v8i32 ?:v8i32:$vec, ?:i32:$elem, sub3:i32)
/*35300*/       /*SwitchType*/ 15,  MVT::v16i32,// ->35317
/*35302*/         OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*35304*/         OPC_EmitInteger, MVT::i32, AMDGPU::sub3,
/*35307*/         OPC_MorphNodeTo, TARGET_VAL(TargetOpcode::INSERT_SUBREG), 0,
                      1/*#VTs*/, MVT::v16i32, 3/*#Ops*/, 0, 1, 2, 
                  // Src: (vector_insert:v16i32 v16i32:v16i32:$vec, i32:i32:$elem, 3:iPTR) - Complexity = 8
                  // Dst: (INSERT_SUBREG:v16i32 ?:v16i32:$vec, ?:i32:$elem, sub3:i32)
/*35317*/       0, // EndSwitchType
/*35318*/     /*Scope*/ 39, /*->35358*/
/*35319*/       OPC_CheckInteger, 4, 
/*35321*/       OPC_MoveParent,
/*35322*/       OPC_SwitchType /*2 cases */, 15,  MVT::v8i32,// ->35340
/*35325*/         OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*35327*/         OPC_EmitInteger, MVT::i32, AMDGPU::sub4,
/*35330*/         OPC_MorphNodeTo, TARGET_VAL(TargetOpcode::INSERT_SUBREG), 0,
                      1/*#VTs*/, MVT::v8i32, 3/*#Ops*/, 0, 1, 2, 
                  // Src: (vector_insert:v8i32 v8i32:v8i32:$vec, i32:i32:$elem, 4:iPTR) - Complexity = 8
                  // Dst: (INSERT_SUBREG:v8i32 ?:v8i32:$vec, ?:i32:$elem, sub4:i32)
/*35340*/       /*SwitchType*/ 15,  MVT::v16i32,// ->35357
/*35342*/         OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*35344*/         OPC_EmitInteger, MVT::i32, AMDGPU::sub4,
/*35347*/         OPC_MorphNodeTo, TARGET_VAL(TargetOpcode::INSERT_SUBREG), 0,
                      1/*#VTs*/, MVT::v16i32, 3/*#Ops*/, 0, 1, 2, 
                  // Src: (vector_insert:v16i32 v16i32:v16i32:$vec, i32:i32:$elem, 4:iPTR) - Complexity = 8
                  // Dst: (INSERT_SUBREG:v16i32 ?:v16i32:$vec, ?:i32:$elem, sub4:i32)
/*35357*/       0, // EndSwitchType
/*35358*/     /*Scope*/ 39, /*->35398*/
/*35359*/       OPC_CheckInteger, 5, 
/*35361*/       OPC_MoveParent,
/*35362*/       OPC_SwitchType /*2 cases */, 15,  MVT::v8i32,// ->35380
/*35365*/         OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*35367*/         OPC_EmitInteger, MVT::i32, AMDGPU::sub5,
/*35370*/         OPC_MorphNodeTo, TARGET_VAL(TargetOpcode::INSERT_SUBREG), 0,
                      1/*#VTs*/, MVT::v8i32, 3/*#Ops*/, 0, 1, 2, 
                  // Src: (vector_insert:v8i32 v8i32:v8i32:$vec, i32:i32:$elem, 5:iPTR) - Complexity = 8
                  // Dst: (INSERT_SUBREG:v8i32 ?:v8i32:$vec, ?:i32:$elem, sub5:i32)
/*35380*/       /*SwitchType*/ 15,  MVT::v16i32,// ->35397
/*35382*/         OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*35384*/         OPC_EmitInteger, MVT::i32, AMDGPU::sub5,
/*35387*/         OPC_MorphNodeTo, TARGET_VAL(TargetOpcode::INSERT_SUBREG), 0,
                      1/*#VTs*/, MVT::v16i32, 3/*#Ops*/, 0, 1, 2, 
                  // Src: (vector_insert:v16i32 v16i32:v16i32:$vec, i32:i32:$elem, 5:iPTR) - Complexity = 8
                  // Dst: (INSERT_SUBREG:v16i32 ?:v16i32:$vec, ?:i32:$elem, sub5:i32)
/*35397*/       0, // EndSwitchType
/*35398*/     /*Scope*/ 39, /*->35438*/
/*35399*/       OPC_CheckInteger, 6, 
/*35401*/       OPC_MoveParent,
/*35402*/       OPC_SwitchType /*2 cases */, 15,  MVT::v8i32,// ->35420
/*35405*/         OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*35407*/         OPC_EmitInteger, MVT::i32, AMDGPU::sub6,
/*35410*/         OPC_MorphNodeTo, TARGET_VAL(TargetOpcode::INSERT_SUBREG), 0,
                      1/*#VTs*/, MVT::v8i32, 3/*#Ops*/, 0, 1, 2, 
                  // Src: (vector_insert:v8i32 v8i32:v8i32:$vec, i32:i32:$elem, 6:iPTR) - Complexity = 8
                  // Dst: (INSERT_SUBREG:v8i32 ?:v8i32:$vec, ?:i32:$elem, sub6:i32)
/*35420*/       /*SwitchType*/ 15,  MVT::v16i32,// ->35437
/*35422*/         OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*35424*/         OPC_EmitInteger, MVT::i32, AMDGPU::sub6,
/*35427*/         OPC_MorphNodeTo, TARGET_VAL(TargetOpcode::INSERT_SUBREG), 0,
                      1/*#VTs*/, MVT::v16i32, 3/*#Ops*/, 0, 1, 2, 
                  // Src: (vector_insert:v16i32 v16i32:v16i32:$vec, i32:i32:$elem, 6:iPTR) - Complexity = 8
                  // Dst: (INSERT_SUBREG:v16i32 ?:v16i32:$vec, ?:i32:$elem, sub6:i32)
/*35437*/       0, // EndSwitchType
/*35438*/     /*Scope*/ 39, /*->35478*/
/*35439*/       OPC_CheckInteger, 7, 
/*35441*/       OPC_MoveParent,
/*35442*/       OPC_SwitchType /*2 cases */, 15,  MVT::v8i32,// ->35460
/*35445*/         OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*35447*/         OPC_EmitInteger, MVT::i32, AMDGPU::sub7,
/*35450*/         OPC_MorphNodeTo, TARGET_VAL(TargetOpcode::INSERT_SUBREG), 0,
                      1/*#VTs*/, MVT::v8i32, 3/*#Ops*/, 0, 1, 2, 
                  // Src: (vector_insert:v8i32 v8i32:v8i32:$vec, i32:i32:$elem, 7:iPTR) - Complexity = 8
                  // Dst: (INSERT_SUBREG:v8i32 ?:v8i32:$vec, ?:i32:$elem, sub7:i32)
/*35460*/       /*SwitchType*/ 15,  MVT::v16i32,// ->35477
/*35462*/         OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*35464*/         OPC_EmitInteger, MVT::i32, AMDGPU::sub7,
/*35467*/         OPC_MorphNodeTo, TARGET_VAL(TargetOpcode::INSERT_SUBREG), 0,
                      1/*#VTs*/, MVT::v16i32, 3/*#Ops*/, 0, 1, 2, 
                  // Src: (vector_insert:v16i32 v16i32:v16i32:$vec, i32:i32:$elem, 7:iPTR) - Complexity = 8
                  // Dst: (INSERT_SUBREG:v16i32 ?:v16i32:$vec, ?:i32:$elem, sub7:i32)
/*35477*/       0, // EndSwitchType
/*35478*/     /*Scope*/ 20, /*->35499*/
/*35479*/       OPC_CheckInteger, 8, 
/*35481*/       OPC_MoveParent,
/*35482*/       OPC_CheckType, MVT::v16i32,
/*35484*/       OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*35486*/       OPC_EmitInteger, MVT::i32, AMDGPU::sub8,
/*35489*/       OPC_MorphNodeTo, TARGET_VAL(TargetOpcode::INSERT_SUBREG), 0,
                    1/*#VTs*/, MVT::v16i32, 3/*#Ops*/, 0, 1, 2, 
                // Src: (vector_insert:v16i32 v16i32:v16i32:$vec, i32:i32:$elem, 8:iPTR) - Complexity = 8
                // Dst: (INSERT_SUBREG:v16i32 ?:v16i32:$vec, ?:i32:$elem, sub8:i32)
/*35499*/     /*Scope*/ 20, /*->35520*/
/*35500*/       OPC_CheckInteger, 9, 
/*35502*/       OPC_MoveParent,
/*35503*/       OPC_CheckType, MVT::v16i32,
/*35505*/       OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*35507*/       OPC_EmitInteger, MVT::i32, AMDGPU::sub9,
/*35510*/       OPC_MorphNodeTo, TARGET_VAL(TargetOpcode::INSERT_SUBREG), 0,
                    1/*#VTs*/, MVT::v16i32, 3/*#Ops*/, 0, 1, 2, 
                // Src: (vector_insert:v16i32 v16i32:v16i32:$vec, i32:i32:$elem, 9:iPTR) - Complexity = 8
                // Dst: (INSERT_SUBREG:v16i32 ?:v16i32:$vec, ?:i32:$elem, sub9:i32)
/*35520*/     /*Scope*/ 20, /*->35541*/
/*35521*/       OPC_CheckInteger, 10, 
/*35523*/       OPC_MoveParent,
/*35524*/       OPC_CheckType, MVT::v16i32,
/*35526*/       OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*35528*/       OPC_EmitInteger, MVT::i32, AMDGPU::sub10,
/*35531*/       OPC_MorphNodeTo, TARGET_VAL(TargetOpcode::INSERT_SUBREG), 0,
                    1/*#VTs*/, MVT::v16i32, 3/*#Ops*/, 0, 1, 2, 
                // Src: (vector_insert:v16i32 v16i32:v16i32:$vec, i32:i32:$elem, 10:iPTR) - Complexity = 8
                // Dst: (INSERT_SUBREG:v16i32 ?:v16i32:$vec, ?:i32:$elem, sub10:i32)
/*35541*/     /*Scope*/ 20, /*->35562*/
/*35542*/       OPC_CheckInteger, 11, 
/*35544*/       OPC_MoveParent,
/*35545*/       OPC_CheckType, MVT::v16i32,
/*35547*/       OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*35549*/       OPC_EmitInteger, MVT::i32, AMDGPU::sub11,
/*35552*/       OPC_MorphNodeTo, TARGET_VAL(TargetOpcode::INSERT_SUBREG), 0,
                    1/*#VTs*/, MVT::v16i32, 3/*#Ops*/, 0, 1, 2, 
                // Src: (vector_insert:v16i32 v16i32:v16i32:$vec, i32:i32:$elem, 11:iPTR) - Complexity = 8
                // Dst: (INSERT_SUBREG:v16i32 ?:v16i32:$vec, ?:i32:$elem, sub11:i32)
/*35562*/     /*Scope*/ 20, /*->35583*/
/*35563*/       OPC_CheckInteger, 12, 
/*35565*/       OPC_MoveParent,
/*35566*/       OPC_CheckType, MVT::v16i32,
/*35568*/       OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*35570*/       OPC_EmitInteger, MVT::i32, AMDGPU::sub12,
/*35573*/       OPC_MorphNodeTo, TARGET_VAL(TargetOpcode::INSERT_SUBREG), 0,
                    1/*#VTs*/, MVT::v16i32, 3/*#Ops*/, 0, 1, 2, 
                // Src: (vector_insert:v16i32 v16i32:v16i32:$vec, i32:i32:$elem, 12:iPTR) - Complexity = 8
                // Dst: (INSERT_SUBREG:v16i32 ?:v16i32:$vec, ?:i32:$elem, sub12:i32)
/*35583*/     /*Scope*/ 20, /*->35604*/
/*35584*/       OPC_CheckInteger, 13, 
/*35586*/       OPC_MoveParent,
/*35587*/       OPC_CheckType, MVT::v16i32,
/*35589*/       OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*35591*/       OPC_EmitInteger, MVT::i32, AMDGPU::sub13,
/*35594*/       OPC_MorphNodeTo, TARGET_VAL(TargetOpcode::INSERT_SUBREG), 0,
                    1/*#VTs*/, MVT::v16i32, 3/*#Ops*/, 0, 1, 2, 
                // Src: (vector_insert:v16i32 v16i32:v16i32:$vec, i32:i32:$elem, 13:iPTR) - Complexity = 8
                // Dst: (INSERT_SUBREG:v16i32 ?:v16i32:$vec, ?:i32:$elem, sub13:i32)
/*35604*/     /*Scope*/ 20, /*->35625*/
/*35605*/       OPC_CheckInteger, 14, 
/*35607*/       OPC_MoveParent,
/*35608*/       OPC_CheckType, MVT::v16i32,
/*35610*/       OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*35612*/       OPC_EmitInteger, MVT::i32, AMDGPU::sub14,
/*35615*/       OPC_MorphNodeTo, TARGET_VAL(TargetOpcode::INSERT_SUBREG), 0,
                    1/*#VTs*/, MVT::v16i32, 3/*#Ops*/, 0, 1, 2, 
                // Src: (vector_insert:v16i32 v16i32:v16i32:$vec, i32:i32:$elem, 14:iPTR) - Complexity = 8
                // Dst: (INSERT_SUBREG:v16i32 ?:v16i32:$vec, ?:i32:$elem, sub14:i32)
/*35625*/     /*Scope*/ 20, /*->35646*/
/*35626*/       OPC_CheckInteger, 15, 
/*35628*/       OPC_MoveParent,
/*35629*/       OPC_CheckType, MVT::v16i32,
/*35631*/       OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*35633*/       OPC_EmitInteger, MVT::i32, AMDGPU::sub15,
/*35636*/       OPC_MorphNodeTo, TARGET_VAL(TargetOpcode::INSERT_SUBREG), 0,
                    1/*#VTs*/, MVT::v16i32, 3/*#Ops*/, 0, 1, 2, 
                // Src: (vector_insert:v16i32 v16i32:v16i32:$vec, i32:i32:$elem, 15:iPTR) - Complexity = 8
                // Dst: (INSERT_SUBREG:v16i32 ?:v16i32:$vec, ?:i32:$elem, sub15:i32)
/*35646*/     0, /*End of Scope*/
/*35647*/   /*Scope*/ 62|128,7/*958*/, /*->36607*/
/*35649*/     OPC_CheckChild1Type, MVT::f32,
/*35651*/     OPC_Scope, 74|128,6/*842*/, /*->36496*/ // 2 children in Scope
/*35654*/       OPC_MoveChild, 2,
/*35656*/       OPC_Scope, 116, /*->35774*/ // 17 children in Scope
/*35658*/         OPC_CheckOpcode, TARGET_VAL(ISD::ADD),
/*35661*/         OPC_RecordChild0, // #2 = $idx
/*35662*/         OPC_RecordChild1, // #3 = $off
/*35663*/         OPC_MoveChild, 1,
/*35665*/         OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*35668*/         OPC_MoveParent,
/*35669*/         OPC_CheckType, MVT::i32,
/*35671*/         OPC_MoveParent,
/*35672*/         OPC_SwitchType /*4 cases */, 23,  MVT::v2f32,// ->35698
/*35675*/           OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*35677*/           OPC_EmitNode, TARGET_VAL(TargetOpcode::IMPLICIT_DEF), 0,
                        1/*#VTs*/, MVT::i1, 0/*#Ops*/,  // Results = #4
/*35684*/           OPC_EmitConvertToTarget, 3,
/*35686*/           OPC_MorphNodeTo, TARGET_VAL(AMDGPU::SI_INDIRECT_DST_V2), 0,
                        1/*#VTs*/, MVT::v2f32, 5/*#Ops*/, 4, 0, 2, 5, 1, 
                    // Src: (vector_insert:v2f32 v2f32:v2f32:$vec, f32:f32:$val, (add:i32 i32:i32:$idx, (imm:i32):$off)) - Complexity = 9
                    // Dst: (SI_INDIRECT_DST_V2:v2f32 (IMPLICIT_DEF:i1), ?:v2f32:$vec, ?:i32:$idx, (imm:i32):$off, ?:f32:$val)
/*35698*/         /*SwitchType*/ 23,  MVT::v4f32,// ->35723
/*35700*/           OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*35702*/           OPC_EmitNode, TARGET_VAL(TargetOpcode::IMPLICIT_DEF), 0,
                        1/*#VTs*/, MVT::i1, 0/*#Ops*/,  // Results = #4
/*35709*/           OPC_EmitConvertToTarget, 3,
/*35711*/           OPC_MorphNodeTo, TARGET_VAL(AMDGPU::SI_INDIRECT_DST_V4), 0,
                        1/*#VTs*/, MVT::v4f32, 5/*#Ops*/, 4, 0, 2, 5, 1, 
                    // Src: (vector_insert:v4f32 v4f32:v4f32:$vec, f32:f32:$val, (add:i32 i32:i32:$idx, (imm:i32):$off)) - Complexity = 9
                    // Dst: (SI_INDIRECT_DST_V4:v4f32 (IMPLICIT_DEF:i1), ?:v4f32:$vec, ?:i32:$idx, (imm:i32):$off, ?:f32:$val)
/*35723*/         /*SwitchType*/ 23,  MVT::v8f32,// ->35748
/*35725*/           OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*35727*/           OPC_EmitNode, TARGET_VAL(TargetOpcode::IMPLICIT_DEF), 0,
                        1/*#VTs*/, MVT::i1, 0/*#Ops*/,  // Results = #4
/*35734*/           OPC_EmitConvertToTarget, 3,
/*35736*/           OPC_MorphNodeTo, TARGET_VAL(AMDGPU::SI_INDIRECT_DST_V8), 0,
                        1/*#VTs*/, MVT::v8f32, 5/*#Ops*/, 4, 0, 2, 5, 1, 
                    // Src: (vector_insert:v8f32 v8f32:v8f32:$vec, f32:f32:$val, (add:i32 i32:i32:$idx, (imm:i32):$off)) - Complexity = 9
                    // Dst: (SI_INDIRECT_DST_V8:v8f32 (IMPLICIT_DEF:i1), ?:v8f32:$vec, ?:i32:$idx, (imm:i32):$off, ?:f32:$val)
/*35748*/         /*SwitchType*/ 23,  MVT::v16f32,// ->35773
/*35750*/           OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*35752*/           OPC_EmitNode, TARGET_VAL(TargetOpcode::IMPLICIT_DEF), 0,
                        1/*#VTs*/, MVT::i1, 0/*#Ops*/,  // Results = #4
/*35759*/           OPC_EmitConvertToTarget, 3,
/*35761*/           OPC_MorphNodeTo, TARGET_VAL(AMDGPU::SI_INDIRECT_DST_V16), 0,
                        1/*#VTs*/, MVT::v16f32, 5/*#Ops*/, 4, 0, 2, 5, 1, 
                    // Src: (vector_insert:v16f32 v16f32:v16f32:$vec, f32:f32:$val, (add:i32 i32:i32:$idx, (imm:i32):$off)) - Complexity = 9
                    // Dst: (SI_INDIRECT_DST_V16:v16f32 (IMPLICIT_DEF:i1), ?:v16f32:$vec, ?:i32:$idx, (imm:i32):$off, ?:f32:$val)
/*35773*/         0, // EndSwitchType
/*35774*/       /*Scope*/ 111, /*->35886*/
/*35775*/         OPC_CheckInteger, 0, 
/*35777*/         OPC_MoveParent,
/*35778*/         OPC_SwitchType /*4 cases */, 34,  MVT::v4f32,// ->35815
/*35781*/           OPC_Scope, 15, /*->35798*/ // 2 children in Scope
/*35783*/             OPC_CheckPatternPredicate, 3, // (Subtarget.getGeneration() <= AMDGPUSubtarget::NORTHERN_ISLANDS)
/*35785*/             OPC_EmitInteger, MVT::i32, AMDGPU::sub0,
/*35788*/             OPC_MorphNodeTo, TARGET_VAL(TargetOpcode::INSERT_SUBREG), 0,
                          1/*#VTs*/, MVT::v4f32, 3/*#Ops*/, 0, 1, 2, 
                      // Src: (vector_insert:v4f32 v4f32:v4f32:$vec, f32:f32:$elem, 0:iPTR) - Complexity = 8
                      // Dst: (INSERT_SUBREG:v4f32 ?:v4f32:$vec, ?:f32:$elem, sub0:i32)
/*35798*/           /*Scope*/ 15, /*->35814*/
/*35799*/             OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*35801*/             OPC_EmitInteger, MVT::i32, AMDGPU::sub0,
/*35804*/             OPC_MorphNodeTo, TARGET_VAL(TargetOpcode::INSERT_SUBREG), 0,
                          1/*#VTs*/, MVT::v4f32, 3/*#Ops*/, 0, 1, 2, 
                      // Src: (vector_insert:v4f32 v4f32:v4f32:$vec, f32:f32:$elem, 0:iPTR) - Complexity = 8
                      // Dst: (INSERT_SUBREG:v4f32 ?:v4f32:$vec, ?:f32:$elem, sub0:i32)
/*35814*/           0, /*End of Scope*/
/*35815*/         /*SwitchType*/ 34,  MVT::v2f32,// ->35851
/*35817*/           OPC_Scope, 15, /*->35834*/ // 2 children in Scope
/*35819*/             OPC_CheckPatternPredicate, 3, // (Subtarget.getGeneration() <= AMDGPUSubtarget::NORTHERN_ISLANDS)
/*35821*/             OPC_EmitInteger, MVT::i32, AMDGPU::sub0,
/*35824*/             OPC_MorphNodeTo, TARGET_VAL(TargetOpcode::INSERT_SUBREG), 0,
                          1/*#VTs*/, MVT::v2f32, 3/*#Ops*/, 0, 1, 2, 
                      // Src: (vector_insert:v2f32 v2f32:v2f32:$vec, f32:f32:$elem, 0:iPTR) - Complexity = 8
                      // Dst: (INSERT_SUBREG:v2f32 ?:v2f32:$vec, ?:f32:$elem, sub0:i32)
/*35834*/           /*Scope*/ 15, /*->35850*/
/*35835*/             OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*35837*/             OPC_EmitInteger, MVT::i32, AMDGPU::sub0,
/*35840*/             OPC_MorphNodeTo, TARGET_VAL(TargetOpcode::INSERT_SUBREG), 0,
                          1/*#VTs*/, MVT::v2f32, 3/*#Ops*/, 0, 1, 2, 
                      // Src: (vector_insert:v2f32 v2f32:v2f32:$vec, f32:f32:$elem, 0:iPTR) - Complexity = 8
                      // Dst: (INSERT_SUBREG:v2f32 ?:v2f32:$vec, ?:f32:$elem, sub0:i32)
/*35850*/           0, /*End of Scope*/
/*35851*/         /*SwitchType*/ 15,  MVT::v8f32,// ->35868
/*35853*/           OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*35855*/           OPC_EmitInteger, MVT::i32, AMDGPU::sub0,
/*35858*/           OPC_MorphNodeTo, TARGET_VAL(TargetOpcode::INSERT_SUBREG), 0,
                        1/*#VTs*/, MVT::v8f32, 3/*#Ops*/, 0, 1, 2, 
                    // Src: (vector_insert:v8f32 v8f32:v8f32:$vec, f32:f32:$elem, 0:iPTR) - Complexity = 8
                    // Dst: (INSERT_SUBREG:v8f32 ?:v8f32:$vec, ?:f32:$elem, sub0:i32)
/*35868*/         /*SwitchType*/ 15,  MVT::v16f32,// ->35885
/*35870*/           OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*35872*/           OPC_EmitInteger, MVT::i32, AMDGPU::sub0,
/*35875*/           OPC_MorphNodeTo, TARGET_VAL(TargetOpcode::INSERT_SUBREG), 0,
                        1/*#VTs*/, MVT::v16f32, 3/*#Ops*/, 0, 1, 2, 
                    // Src: (vector_insert:v16f32 v16f32:v16f32:$vec, f32:f32:$elem, 0:iPTR) - Complexity = 8
                    // Dst: (INSERT_SUBREG:v16f32 ?:v16f32:$vec, ?:f32:$elem, sub0:i32)
/*35885*/         0, // EndSwitchType
/*35886*/       /*Scope*/ 111, /*->35998*/
/*35887*/         OPC_CheckInteger, 1, 
/*35889*/         OPC_MoveParent,
/*35890*/         OPC_SwitchType /*4 cases */, 34,  MVT::v4f32,// ->35927
/*35893*/           OPC_Scope, 15, /*->35910*/ // 2 children in Scope
/*35895*/             OPC_CheckPatternPredicate, 3, // (Subtarget.getGeneration() <= AMDGPUSubtarget::NORTHERN_ISLANDS)
/*35897*/             OPC_EmitInteger, MVT::i32, AMDGPU::sub1,
/*35900*/             OPC_MorphNodeTo, TARGET_VAL(TargetOpcode::INSERT_SUBREG), 0,
                          1/*#VTs*/, MVT::v4f32, 3/*#Ops*/, 0, 1, 2, 
                      // Src: (vector_insert:v4f32 v4f32:v4f32:$vec, f32:f32:$elem, 1:iPTR) - Complexity = 8
                      // Dst: (INSERT_SUBREG:v4f32 ?:v4f32:$vec, ?:f32:$elem, sub1:i32)
/*35910*/           /*Scope*/ 15, /*->35926*/
/*35911*/             OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*35913*/             OPC_EmitInteger, MVT::i32, AMDGPU::sub1,
/*35916*/             OPC_MorphNodeTo, TARGET_VAL(TargetOpcode::INSERT_SUBREG), 0,
                          1/*#VTs*/, MVT::v4f32, 3/*#Ops*/, 0, 1, 2, 
                      // Src: (vector_insert:v4f32 v4f32:v4f32:$vec, f32:f32:$elem, 1:iPTR) - Complexity = 8
                      // Dst: (INSERT_SUBREG:v4f32 ?:v4f32:$vec, ?:f32:$elem, sub1:i32)
/*35926*/           0, /*End of Scope*/
/*35927*/         /*SwitchType*/ 34,  MVT::v2f32,// ->35963
/*35929*/           OPC_Scope, 15, /*->35946*/ // 2 children in Scope
/*35931*/             OPC_CheckPatternPredicate, 3, // (Subtarget.getGeneration() <= AMDGPUSubtarget::NORTHERN_ISLANDS)
/*35933*/             OPC_EmitInteger, MVT::i32, AMDGPU::sub1,
/*35936*/             OPC_MorphNodeTo, TARGET_VAL(TargetOpcode::INSERT_SUBREG), 0,
                          1/*#VTs*/, MVT::v2f32, 3/*#Ops*/, 0, 1, 2, 
                      // Src: (vector_insert:v2f32 v2f32:v2f32:$vec, f32:f32:$elem, 1:iPTR) - Complexity = 8
                      // Dst: (INSERT_SUBREG:v2f32 ?:v2f32:$vec, ?:f32:$elem, sub1:i32)
/*35946*/           /*Scope*/ 15, /*->35962*/
/*35947*/             OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*35949*/             OPC_EmitInteger, MVT::i32, AMDGPU::sub1,
/*35952*/             OPC_MorphNodeTo, TARGET_VAL(TargetOpcode::INSERT_SUBREG), 0,
                          1/*#VTs*/, MVT::v2f32, 3/*#Ops*/, 0, 1, 2, 
                      // Src: (vector_insert:v2f32 v2f32:v2f32:$vec, f32:f32:$elem, 1:iPTR) - Complexity = 8
                      // Dst: (INSERT_SUBREG:v2f32 ?:v2f32:$vec, ?:f32:$elem, sub1:i32)
/*35962*/           0, /*End of Scope*/
/*35963*/         /*SwitchType*/ 15,  MVT::v8f32,// ->35980
/*35965*/           OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*35967*/           OPC_EmitInteger, MVT::i32, AMDGPU::sub1,
/*35970*/           OPC_MorphNodeTo, TARGET_VAL(TargetOpcode::INSERT_SUBREG), 0,
                        1/*#VTs*/, MVT::v8f32, 3/*#Ops*/, 0, 1, 2, 
                    // Src: (vector_insert:v8f32 v8f32:v8f32:$vec, f32:f32:$elem, 1:iPTR) - Complexity = 8
                    // Dst: (INSERT_SUBREG:v8f32 ?:v8f32:$vec, ?:f32:$elem, sub1:i32)
/*35980*/         /*SwitchType*/ 15,  MVT::v16f32,// ->35997
/*35982*/           OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*35984*/           OPC_EmitInteger, MVT::i32, AMDGPU::sub1,
/*35987*/           OPC_MorphNodeTo, TARGET_VAL(TargetOpcode::INSERT_SUBREG), 0,
                        1/*#VTs*/, MVT::v16f32, 3/*#Ops*/, 0, 1, 2, 
                    // Src: (vector_insert:v16f32 v16f32:v16f32:$vec, f32:f32:$elem, 1:iPTR) - Complexity = 8
                    // Dst: (INSERT_SUBREG:v16f32 ?:v16f32:$vec, ?:f32:$elem, sub1:i32)
/*35997*/         0, // EndSwitchType
/*35998*/       /*Scope*/ 92, /*->36091*/
/*35999*/         OPC_CheckInteger, 2, 
/*36001*/         OPC_MoveParent,
/*36002*/         OPC_SwitchType /*4 cases */, 34,  MVT::v4f32,// ->36039
/*36005*/           OPC_Scope, 15, /*->36022*/ // 2 children in Scope
/*36007*/             OPC_CheckPatternPredicate, 3, // (Subtarget.getGeneration() <= AMDGPUSubtarget::NORTHERN_ISLANDS)
/*36009*/             OPC_EmitInteger, MVT::i32, AMDGPU::sub2,
/*36012*/             OPC_MorphNodeTo, TARGET_VAL(TargetOpcode::INSERT_SUBREG), 0,
                          1/*#VTs*/, MVT::v4f32, 3/*#Ops*/, 0, 1, 2, 
                      // Src: (vector_insert:v4f32 v4f32:v4f32:$vec, f32:f32:$elem, 2:iPTR) - Complexity = 8
                      // Dst: (INSERT_SUBREG:v4f32 ?:v4f32:$vec, ?:f32:$elem, sub2:i32)
/*36022*/           /*Scope*/ 15, /*->36038*/
/*36023*/             OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*36025*/             OPC_EmitInteger, MVT::i32, AMDGPU::sub2,
/*36028*/             OPC_MorphNodeTo, TARGET_VAL(TargetOpcode::INSERT_SUBREG), 0,
                          1/*#VTs*/, MVT::v4f32, 3/*#Ops*/, 0, 1, 2, 
                      // Src: (vector_insert:v4f32 v4f32:v4f32:$vec, f32:f32:$elem, 2:iPTR) - Complexity = 8
                      // Dst: (INSERT_SUBREG:v4f32 ?:v4f32:$vec, ?:f32:$elem, sub2:i32)
/*36038*/           0, /*End of Scope*/
/*36039*/         /*SwitchType*/ 15,  MVT::v2f32,// ->36056
/*36041*/           OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*36043*/           OPC_EmitInteger, MVT::i32, AMDGPU::sub2,
/*36046*/           OPC_MorphNodeTo, TARGET_VAL(TargetOpcode::INSERT_SUBREG), 0,
                        1/*#VTs*/, MVT::v2f32, 3/*#Ops*/, 0, 1, 2, 
                    // Src: (vector_insert:v2f32 v2f32:v2f32:$vec, f32:f32:$elem, 2:iPTR) - Complexity = 8
                    // Dst: (INSERT_SUBREG:v2f32 ?:v2f32:$vec, ?:f32:$elem, sub2:i32)
/*36056*/         /*SwitchType*/ 15,  MVT::v8f32,// ->36073
/*36058*/           OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*36060*/           OPC_EmitInteger, MVT::i32, AMDGPU::sub2,
/*36063*/           OPC_MorphNodeTo, TARGET_VAL(TargetOpcode::INSERT_SUBREG), 0,
                        1/*#VTs*/, MVT::v8f32, 3/*#Ops*/, 0, 1, 2, 
                    // Src: (vector_insert:v8f32 v8f32:v8f32:$vec, f32:f32:$elem, 2:iPTR) - Complexity = 8
                    // Dst: (INSERT_SUBREG:v8f32 ?:v8f32:$vec, ?:f32:$elem, sub2:i32)
/*36073*/         /*SwitchType*/ 15,  MVT::v16f32,// ->36090
/*36075*/           OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*36077*/           OPC_EmitInteger, MVT::i32, AMDGPU::sub2,
/*36080*/           OPC_MorphNodeTo, TARGET_VAL(TargetOpcode::INSERT_SUBREG), 0,
                        1/*#VTs*/, MVT::v16f32, 3/*#Ops*/, 0, 1, 2, 
                    // Src: (vector_insert:v16f32 v16f32:v16f32:$vec, f32:f32:$elem, 2:iPTR) - Complexity = 8
                    // Dst: (INSERT_SUBREG:v16f32 ?:v16f32:$vec, ?:f32:$elem, sub2:i32)
/*36090*/         0, // EndSwitchType
/*36091*/       /*Scope*/ 75, /*->36167*/
/*36092*/         OPC_CheckInteger, 3, 
/*36094*/         OPC_MoveParent,
/*36095*/         OPC_SwitchType /*3 cases */, 34,  MVT::v4f32,// ->36132
/*36098*/           OPC_Scope, 15, /*->36115*/ // 2 children in Scope
/*36100*/             OPC_CheckPatternPredicate, 3, // (Subtarget.getGeneration() <= AMDGPUSubtarget::NORTHERN_ISLANDS)
/*36102*/             OPC_EmitInteger, MVT::i32, AMDGPU::sub3,
/*36105*/             OPC_MorphNodeTo, TARGET_VAL(TargetOpcode::INSERT_SUBREG), 0,
                          1/*#VTs*/, MVT::v4f32, 3/*#Ops*/, 0, 1, 2, 
                      // Src: (vector_insert:v4f32 v4f32:v4f32:$vec, f32:f32:$elem, 3:iPTR) - Complexity = 8
                      // Dst: (INSERT_SUBREG:v4f32 ?:v4f32:$vec, ?:f32:$elem, sub3:i32)
/*36115*/           /*Scope*/ 15, /*->36131*/
/*36116*/             OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*36118*/             OPC_EmitInteger, MVT::i32, AMDGPU::sub3,
/*36121*/             OPC_MorphNodeTo, TARGET_VAL(TargetOpcode::INSERT_SUBREG), 0,
                          1/*#VTs*/, MVT::v4f32, 3/*#Ops*/, 0, 1, 2, 
                      // Src: (vector_insert:v4f32 v4f32:v4f32:$vec, f32:f32:$elem, 3:iPTR) - Complexity = 8
                      // Dst: (INSERT_SUBREG:v4f32 ?:v4f32:$vec, ?:f32:$elem, sub3:i32)
/*36131*/           0, /*End of Scope*/
/*36132*/         /*SwitchType*/ 15,  MVT::v8f32,// ->36149
/*36134*/           OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*36136*/           OPC_EmitInteger, MVT::i32, AMDGPU::sub3,
/*36139*/           OPC_MorphNodeTo, TARGET_VAL(TargetOpcode::INSERT_SUBREG), 0,
                        1/*#VTs*/, MVT::v8f32, 3/*#Ops*/, 0, 1, 2, 
                    // Src: (vector_insert:v8f32 v8f32:v8f32:$vec, f32:f32:$elem, 3:iPTR) - Complexity = 8
                    // Dst: (INSERT_SUBREG:v8f32 ?:v8f32:$vec, ?:f32:$elem, sub3:i32)
/*36149*/         /*SwitchType*/ 15,  MVT::v16f32,// ->36166
/*36151*/           OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*36153*/           OPC_EmitInteger, MVT::i32, AMDGPU::sub3,
/*36156*/           OPC_MorphNodeTo, TARGET_VAL(TargetOpcode::INSERT_SUBREG), 0,
                        1/*#VTs*/, MVT::v16f32, 3/*#Ops*/, 0, 1, 2, 
                    // Src: (vector_insert:v16f32 v16f32:v16f32:$vec, f32:f32:$elem, 3:iPTR) - Complexity = 8
                    // Dst: (INSERT_SUBREG:v16f32 ?:v16f32:$vec, ?:f32:$elem, sub3:i32)
/*36166*/         0, // EndSwitchType
/*36167*/       /*Scope*/ 39, /*->36207*/
/*36168*/         OPC_CheckInteger, 4, 
/*36170*/         OPC_MoveParent,
/*36171*/         OPC_SwitchType /*2 cases */, 15,  MVT::v8f32,// ->36189
/*36174*/           OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*36176*/           OPC_EmitInteger, MVT::i32, AMDGPU::sub4,
/*36179*/           OPC_MorphNodeTo, TARGET_VAL(TargetOpcode::INSERT_SUBREG), 0,
                        1/*#VTs*/, MVT::v8f32, 3/*#Ops*/, 0, 1, 2, 
                    // Src: (vector_insert:v8f32 v8f32:v8f32:$vec, f32:f32:$elem, 4:iPTR) - Complexity = 8
                    // Dst: (INSERT_SUBREG:v8f32 ?:v8f32:$vec, ?:f32:$elem, sub4:i32)
/*36189*/         /*SwitchType*/ 15,  MVT::v16f32,// ->36206
/*36191*/           OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*36193*/           OPC_EmitInteger, MVT::i32, AMDGPU::sub4,
/*36196*/           OPC_MorphNodeTo, TARGET_VAL(TargetOpcode::INSERT_SUBREG), 0,
                        1/*#VTs*/, MVT::v16f32, 3/*#Ops*/, 0, 1, 2, 
                    // Src: (vector_insert:v16f32 v16f32:v16f32:$vec, f32:f32:$elem, 4:iPTR) - Complexity = 8
                    // Dst: (INSERT_SUBREG:v16f32 ?:v16f32:$vec, ?:f32:$elem, sub4:i32)
/*36206*/         0, // EndSwitchType
/*36207*/       /*Scope*/ 39, /*->36247*/
/*36208*/         OPC_CheckInteger, 5, 
/*36210*/         OPC_MoveParent,
/*36211*/         OPC_SwitchType /*2 cases */, 15,  MVT::v8f32,// ->36229
/*36214*/           OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*36216*/           OPC_EmitInteger, MVT::i32, AMDGPU::sub5,
/*36219*/           OPC_MorphNodeTo, TARGET_VAL(TargetOpcode::INSERT_SUBREG), 0,
                        1/*#VTs*/, MVT::v8f32, 3/*#Ops*/, 0, 1, 2, 
                    // Src: (vector_insert:v8f32 v8f32:v8f32:$vec, f32:f32:$elem, 5:iPTR) - Complexity = 8
                    // Dst: (INSERT_SUBREG:v8f32 ?:v8f32:$vec, ?:f32:$elem, sub5:i32)
/*36229*/         /*SwitchType*/ 15,  MVT::v16f32,// ->36246
/*36231*/           OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*36233*/           OPC_EmitInteger, MVT::i32, AMDGPU::sub5,
/*36236*/           OPC_MorphNodeTo, TARGET_VAL(TargetOpcode::INSERT_SUBREG), 0,
                        1/*#VTs*/, MVT::v16f32, 3/*#Ops*/, 0, 1, 2, 
                    // Src: (vector_insert:v16f32 v16f32:v16f32:$vec, f32:f32:$elem, 5:iPTR) - Complexity = 8
                    // Dst: (INSERT_SUBREG:v16f32 ?:v16f32:$vec, ?:f32:$elem, sub5:i32)
/*36246*/         0, // EndSwitchType
/*36247*/       /*Scope*/ 39, /*->36287*/
/*36248*/         OPC_CheckInteger, 6, 
/*36250*/         OPC_MoveParent,
/*36251*/         OPC_SwitchType /*2 cases */, 15,  MVT::v8f32,// ->36269
/*36254*/           OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*36256*/           OPC_EmitInteger, MVT::i32, AMDGPU::sub6,
/*36259*/           OPC_MorphNodeTo, TARGET_VAL(TargetOpcode::INSERT_SUBREG), 0,
                        1/*#VTs*/, MVT::v8f32, 3/*#Ops*/, 0, 1, 2, 
                    // Src: (vector_insert:v8f32 v8f32:v8f32:$vec, f32:f32:$elem, 6:iPTR) - Complexity = 8
                    // Dst: (INSERT_SUBREG:v8f32 ?:v8f32:$vec, ?:f32:$elem, sub6:i32)
/*36269*/         /*SwitchType*/ 15,  MVT::v16f32,// ->36286
/*36271*/           OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*36273*/           OPC_EmitInteger, MVT::i32, AMDGPU::sub6,
/*36276*/           OPC_MorphNodeTo, TARGET_VAL(TargetOpcode::INSERT_SUBREG), 0,
                        1/*#VTs*/, MVT::v16f32, 3/*#Ops*/, 0, 1, 2, 
                    // Src: (vector_insert:v16f32 v16f32:v16f32:$vec, f32:f32:$elem, 6:iPTR) - Complexity = 8
                    // Dst: (INSERT_SUBREG:v16f32 ?:v16f32:$vec, ?:f32:$elem, sub6:i32)
/*36286*/         0, // EndSwitchType
/*36287*/       /*Scope*/ 39, /*->36327*/
/*36288*/         OPC_CheckInteger, 7, 
/*36290*/         OPC_MoveParent,
/*36291*/         OPC_SwitchType /*2 cases */, 15,  MVT::v8f32,// ->36309
/*36294*/           OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*36296*/           OPC_EmitInteger, MVT::i32, AMDGPU::sub7,
/*36299*/           OPC_MorphNodeTo, TARGET_VAL(TargetOpcode::INSERT_SUBREG), 0,
                        1/*#VTs*/, MVT::v8f32, 3/*#Ops*/, 0, 1, 2, 
                    // Src: (vector_insert:v8f32 v8f32:v8f32:$vec, f32:f32:$elem, 7:iPTR) - Complexity = 8
                    // Dst: (INSERT_SUBREG:v8f32 ?:v8f32:$vec, ?:f32:$elem, sub7:i32)
/*36309*/         /*SwitchType*/ 15,  MVT::v16f32,// ->36326
/*36311*/           OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*36313*/           OPC_EmitInteger, MVT::i32, AMDGPU::sub7,
/*36316*/           OPC_MorphNodeTo, TARGET_VAL(TargetOpcode::INSERT_SUBREG), 0,
                        1/*#VTs*/, MVT::v16f32, 3/*#Ops*/, 0, 1, 2, 
                    // Src: (vector_insert:v16f32 v16f32:v16f32:$vec, f32:f32:$elem, 7:iPTR) - Complexity = 8
                    // Dst: (INSERT_SUBREG:v16f32 ?:v16f32:$vec, ?:f32:$elem, sub7:i32)
/*36326*/         0, // EndSwitchType
/*36327*/       /*Scope*/ 20, /*->36348*/
/*36328*/         OPC_CheckInteger, 8, 
/*36330*/         OPC_MoveParent,
/*36331*/         OPC_CheckType, MVT::v16f32,
/*36333*/         OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*36335*/         OPC_EmitInteger, MVT::i32, AMDGPU::sub8,
/*36338*/         OPC_MorphNodeTo, TARGET_VAL(TargetOpcode::INSERT_SUBREG), 0,
                      1/*#VTs*/, MVT::v16f32, 3/*#Ops*/, 0, 1, 2, 
                  // Src: (vector_insert:v16f32 v16f32:v16f32:$vec, f32:f32:$elem, 8:iPTR) - Complexity = 8
                  // Dst: (INSERT_SUBREG:v16f32 ?:v16f32:$vec, ?:f32:$elem, sub8:i32)
/*36348*/       /*Scope*/ 20, /*->36369*/
/*36349*/         OPC_CheckInteger, 9, 
/*36351*/         OPC_MoveParent,
/*36352*/         OPC_CheckType, MVT::v16f32,
/*36354*/         OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*36356*/         OPC_EmitInteger, MVT::i32, AMDGPU::sub9,
/*36359*/         OPC_MorphNodeTo, TARGET_VAL(TargetOpcode::INSERT_SUBREG), 0,
                      1/*#VTs*/, MVT::v16f32, 3/*#Ops*/, 0, 1, 2, 
                  // Src: (vector_insert:v16f32 v16f32:v16f32:$vec, f32:f32:$elem, 9:iPTR) - Complexity = 8
                  // Dst: (INSERT_SUBREG:v16f32 ?:v16f32:$vec, ?:f32:$elem, sub9:i32)
/*36369*/       /*Scope*/ 20, /*->36390*/
/*36370*/         OPC_CheckInteger, 10, 
/*36372*/         OPC_MoveParent,
/*36373*/         OPC_CheckType, MVT::v16f32,
/*36375*/         OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*36377*/         OPC_EmitInteger, MVT::i32, AMDGPU::sub10,
/*36380*/         OPC_MorphNodeTo, TARGET_VAL(TargetOpcode::INSERT_SUBREG), 0,
                      1/*#VTs*/, MVT::v16f32, 3/*#Ops*/, 0, 1, 2, 
                  // Src: (vector_insert:v16f32 v16f32:v16f32:$vec, f32:f32:$elem, 10:iPTR) - Complexity = 8
                  // Dst: (INSERT_SUBREG:v16f32 ?:v16f32:$vec, ?:f32:$elem, sub10:i32)
/*36390*/       /*Scope*/ 20, /*->36411*/
/*36391*/         OPC_CheckInteger, 11, 
/*36393*/         OPC_MoveParent,
/*36394*/         OPC_CheckType, MVT::v16f32,
/*36396*/         OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*36398*/         OPC_EmitInteger, MVT::i32, AMDGPU::sub11,
/*36401*/         OPC_MorphNodeTo, TARGET_VAL(TargetOpcode::INSERT_SUBREG), 0,
                      1/*#VTs*/, MVT::v16f32, 3/*#Ops*/, 0, 1, 2, 
                  // Src: (vector_insert:v16f32 v16f32:v16f32:$vec, f32:f32:$elem, 11:iPTR) - Complexity = 8
                  // Dst: (INSERT_SUBREG:v16f32 ?:v16f32:$vec, ?:f32:$elem, sub11:i32)
/*36411*/       /*Scope*/ 20, /*->36432*/
/*36412*/         OPC_CheckInteger, 12, 
/*36414*/         OPC_MoveParent,
/*36415*/         OPC_CheckType, MVT::v16f32,
/*36417*/         OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*36419*/         OPC_EmitInteger, MVT::i32, AMDGPU::sub12,
/*36422*/         OPC_MorphNodeTo, TARGET_VAL(TargetOpcode::INSERT_SUBREG), 0,
                      1/*#VTs*/, MVT::v16f32, 3/*#Ops*/, 0, 1, 2, 
                  // Src: (vector_insert:v16f32 v16f32:v16f32:$vec, f32:f32:$elem, 12:iPTR) - Complexity = 8
                  // Dst: (INSERT_SUBREG:v16f32 ?:v16f32:$vec, ?:f32:$elem, sub12:i32)
/*36432*/       /*Scope*/ 20, /*->36453*/
/*36433*/         OPC_CheckInteger, 13, 
/*36435*/         OPC_MoveParent,
/*36436*/         OPC_CheckType, MVT::v16f32,
/*36438*/         OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*36440*/         OPC_EmitInteger, MVT::i32, AMDGPU::sub13,
/*36443*/         OPC_MorphNodeTo, TARGET_VAL(TargetOpcode::INSERT_SUBREG), 0,
                      1/*#VTs*/, MVT::v16f32, 3/*#Ops*/, 0, 1, 2, 
                  // Src: (vector_insert:v16f32 v16f32:v16f32:$vec, f32:f32:$elem, 13:iPTR) - Complexity = 8
                  // Dst: (INSERT_SUBREG:v16f32 ?:v16f32:$vec, ?:f32:$elem, sub13:i32)
/*36453*/       /*Scope*/ 20, /*->36474*/
/*36454*/         OPC_CheckInteger, 14, 
/*36456*/         OPC_MoveParent,
/*36457*/         OPC_CheckType, MVT::v16f32,
/*36459*/         OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*36461*/         OPC_EmitInteger, MVT::i32, AMDGPU::sub14,
/*36464*/         OPC_MorphNodeTo, TARGET_VAL(TargetOpcode::INSERT_SUBREG), 0,
                      1/*#VTs*/, MVT::v16f32, 3/*#Ops*/, 0, 1, 2, 
                  // Src: (vector_insert:v16f32 v16f32:v16f32:$vec, f32:f32:$elem, 14:iPTR) - Complexity = 8
                  // Dst: (INSERT_SUBREG:v16f32 ?:v16f32:$vec, ?:f32:$elem, sub14:i32)
/*36474*/       /*Scope*/ 20, /*->36495*/
/*36475*/         OPC_CheckInteger, 15, 
/*36477*/         OPC_MoveParent,
/*36478*/         OPC_CheckType, MVT::v16f32,
/*36480*/         OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*36482*/         OPC_EmitInteger, MVT::i32, AMDGPU::sub15,
/*36485*/         OPC_MorphNodeTo, TARGET_VAL(TargetOpcode::INSERT_SUBREG), 0,
                      1/*#VTs*/, MVT::v16f32, 3/*#Ops*/, 0, 1, 2, 
                  // Src: (vector_insert:v16f32 v16f32:v16f32:$vec, f32:f32:$elem, 15:iPTR) - Complexity = 8
                  // Dst: (INSERT_SUBREG:v16f32 ?:v16f32:$vec, ?:f32:$elem, sub15:i32)
/*36495*/       0, /*End of Scope*/
/*36496*/     /*Scope*/ 109, /*->36606*/
/*36497*/       OPC_RecordChild2, // #2 = $idx
/*36498*/       OPC_CheckChild2Type, MVT::i32,
/*36500*/       OPC_SwitchType /*4 cases */, 24,  MVT::v2f32,// ->36527
/*36503*/         OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*36505*/         OPC_EmitNode, TARGET_VAL(TargetOpcode::IMPLICIT_DEF), 0,
                      1/*#VTs*/, MVT::i1, 0/*#Ops*/,  // Results = #3
/*36512*/         OPC_EmitInteger, MVT::i32, 0, 
/*36515*/         OPC_MorphNodeTo, TARGET_VAL(AMDGPU::SI_INDIRECT_DST_V2), 0,
                      1/*#VTs*/, MVT::v2f32, 5/*#Ops*/, 3, 0, 2, 4, 1, 
                  // Src: (vector_insert:v2f32 v2f32:v2f32:$vec, f32:f32:$val, i32:i32:$idx) - Complexity = 3
                  // Dst: (SI_INDIRECT_DST_V2:v2f32 (IMPLICIT_DEF:i1), ?:v2f32:$vec, ?:i32:$idx, 0:i32, ?:f32:$val)
/*36527*/       /*SwitchType*/ 24,  MVT::v4f32,// ->36553
/*36529*/         OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*36531*/         OPC_EmitNode, TARGET_VAL(TargetOpcode::IMPLICIT_DEF), 0,
                      1/*#VTs*/, MVT::i1, 0/*#Ops*/,  // Results = #3
/*36538*/         OPC_EmitInteger, MVT::i32, 0, 
/*36541*/         OPC_MorphNodeTo, TARGET_VAL(AMDGPU::SI_INDIRECT_DST_V4), 0,
                      1/*#VTs*/, MVT::v4f32, 5/*#Ops*/, 3, 0, 2, 4, 1, 
                  // Src: (vector_insert:v4f32 v4f32:v4f32:$vec, f32:f32:$val, i32:i32:$idx) - Complexity = 3
                  // Dst: (SI_INDIRECT_DST_V4:v4f32 (IMPLICIT_DEF:i1), ?:v4f32:$vec, ?:i32:$idx, 0:i32, ?:f32:$val)
/*36553*/       /*SwitchType*/ 24,  MVT::v8f32,// ->36579
/*36555*/         OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*36557*/         OPC_EmitNode, TARGET_VAL(TargetOpcode::IMPLICIT_DEF), 0,
                      1/*#VTs*/, MVT::i1, 0/*#Ops*/,  // Results = #3
/*36564*/         OPC_EmitInteger, MVT::i32, 0, 
/*36567*/         OPC_MorphNodeTo, TARGET_VAL(AMDGPU::SI_INDIRECT_DST_V8), 0,
                      1/*#VTs*/, MVT::v8f32, 5/*#Ops*/, 3, 0, 2, 4, 1, 
                  // Src: (vector_insert:v8f32 v8f32:v8f32:$vec, f32:f32:$val, i32:i32:$idx) - Complexity = 3
                  // Dst: (SI_INDIRECT_DST_V8:v8f32 (IMPLICIT_DEF:i1), ?:v8f32:$vec, ?:i32:$idx, 0:i32, ?:f32:$val)
/*36579*/       /*SwitchType*/ 24,  MVT::v16f32,// ->36605
/*36581*/         OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*36583*/         OPC_EmitNode, TARGET_VAL(TargetOpcode::IMPLICIT_DEF), 0,
                      1/*#VTs*/, MVT::i1, 0/*#Ops*/,  // Results = #3
/*36590*/         OPC_EmitInteger, MVT::i32, 0, 
/*36593*/         OPC_MorphNodeTo, TARGET_VAL(AMDGPU::SI_INDIRECT_DST_V16), 0,
                      1/*#VTs*/, MVT::v16f32, 5/*#Ops*/, 3, 0, 2, 4, 1, 
                  // Src: (vector_insert:v16f32 v16f32:v16f32:$vec, f32:f32:$val, i32:i32:$idx) - Complexity = 3
                  // Dst: (SI_INDIRECT_DST_V16:v16f32 (IMPLICIT_DEF:i1), ?:v16f32:$vec, ?:i32:$idx, 0:i32, ?:f32:$val)
/*36605*/       0, // EndSwitchType
/*36606*/     0, /*End of Scope*/
/*36607*/   0, /*End of Scope*/
/*36608*/ /*SwitchOpcode*/ 23|128,1/*151*/,  TARGET_VAL(ISD::BUILD_VECTOR),// ->36763
/*36612*/   OPC_RecordChild0, // #0 = $x
/*36613*/   OPC_SwitchType /*2 cases */, 72,  MVT::v4i32,// ->36688
/*36616*/     OPC_CheckChild0Type, MVT::i32,
/*36618*/     OPC_RecordChild1, // #1 = $y
/*36619*/     OPC_CheckChild1Type, MVT::i32,
/*36621*/     OPC_RecordChild2, // #2 = $z
/*36622*/     OPC_CheckChild2Type, MVT::i32,
/*36624*/     OPC_RecordChild3, // #3 = $w
/*36625*/     OPC_CheckChild3Type, MVT::i32,
/*36627*/     OPC_CheckPatternPredicate, 3, // (Subtarget.getGeneration() <= AMDGPUSubtarget::NORTHERN_ISLANDS)
/*36629*/     OPC_EmitNode, TARGET_VAL(TargetOpcode::IMPLICIT_DEF), 0,
                  1/*#VTs*/, MVT::v4i32, 0/*#Ops*/,  // Results = #4
/*36636*/     OPC_EmitInteger, MVT::i32, AMDGPU::sub0,
/*36639*/     OPC_EmitNode, TARGET_VAL(TargetOpcode::INSERT_SUBREG), 0,
                  1/*#VTs*/, MVT::v4i32, 3/*#Ops*/, 4, 0, 5,  // Results = #6
/*36649*/     OPC_EmitInteger, MVT::i32, AMDGPU::sub1,
/*36652*/     OPC_EmitNode, TARGET_VAL(TargetOpcode::INSERT_SUBREG), 0,
                  1/*#VTs*/, MVT::v4i32, 3/*#Ops*/, 6, 1, 7,  // Results = #8
/*36662*/     OPC_EmitInteger, MVT::i32, AMDGPU::sub2,
/*36665*/     OPC_EmitNode, TARGET_VAL(TargetOpcode::INSERT_SUBREG), 0,
                  1/*#VTs*/, MVT::v4i32, 3/*#Ops*/, 8, 2, 9,  // Results = #10
/*36675*/     OPC_EmitInteger, MVT::i32, AMDGPU::sub3,
/*36678*/     OPC_MorphNodeTo, TARGET_VAL(TargetOpcode::INSERT_SUBREG), 0,
                  1/*#VTs*/, MVT::v4i32, 3/*#Ops*/, 10, 3, 11, 
              // Src: (build_vector:v4i32 i32:i32:$x, i32:i32:$y, i32:i32:$z, i32:i32:$w) - Complexity = 3
              // Dst: (INSERT_SUBREG:v4i32 (INSERT_SUBREG:v4i32 (INSERT_SUBREG:v4i32 (INSERT_SUBREG:v4i32 (IMPLICIT_DEF:v4i32), ?:i32:$x, sub0:i32), ?:i32:$y, sub1:i32), ?:i32:$z, sub2:i32), ?:i32:$w, sub3:i32)
/*36688*/   /*SwitchType*/ 72,  MVT::v4f32,// ->36762
/*36690*/     OPC_CheckChild0Type, MVT::f32,
/*36692*/     OPC_RecordChild1, // #1 = $y
/*36693*/     OPC_CheckChild1Type, MVT::f32,
/*36695*/     OPC_RecordChild2, // #2 = $z
/*36696*/     OPC_CheckChild2Type, MVT::f32,
/*36698*/     OPC_RecordChild3, // #3 = $w
/*36699*/     OPC_CheckChild3Type, MVT::f32,
/*36701*/     OPC_CheckPatternPredicate, 3, // (Subtarget.getGeneration() <= AMDGPUSubtarget::NORTHERN_ISLANDS)
/*36703*/     OPC_EmitNode, TARGET_VAL(TargetOpcode::IMPLICIT_DEF), 0,
                  1/*#VTs*/, MVT::v4f32, 0/*#Ops*/,  // Results = #4
/*36710*/     OPC_EmitInteger, MVT::i32, AMDGPU::sub0,
/*36713*/     OPC_EmitNode, TARGET_VAL(TargetOpcode::INSERT_SUBREG), 0,
                  1/*#VTs*/, MVT::v4f32, 3/*#Ops*/, 4, 0, 5,  // Results = #6
/*36723*/     OPC_EmitInteger, MVT::i32, AMDGPU::sub1,
/*36726*/     OPC_EmitNode, TARGET_VAL(TargetOpcode::INSERT_SUBREG), 0,
                  1/*#VTs*/, MVT::v4f32, 3/*#Ops*/, 6, 1, 7,  // Results = #8
/*36736*/     OPC_EmitInteger, MVT::i32, AMDGPU::sub2,
/*36739*/     OPC_EmitNode, TARGET_VAL(TargetOpcode::INSERT_SUBREG), 0,
                  1/*#VTs*/, MVT::v4f32, 3/*#Ops*/, 8, 2, 9,  // Results = #10
/*36749*/     OPC_EmitInteger, MVT::i32, AMDGPU::sub3,
/*36752*/     OPC_MorphNodeTo, TARGET_VAL(TargetOpcode::INSERT_SUBREG), 0,
                  1/*#VTs*/, MVT::v4f32, 3/*#Ops*/, 10, 3, 11, 
              // Src: (build_vector:v4f32 f32:f32:$x, f32:f32:$y, f32:f32:$z, f32:f32:$w) - Complexity = 3
              // Dst: (INSERT_SUBREG:v4f32 (INSERT_SUBREG:v4f32 (INSERT_SUBREG:v4f32 (INSERT_SUBREG:v4f32 (IMPLICIT_DEF:v4f32), ?:f32:$x, sub0:i32), ?:f32:$y, sub1:i32), ?:f32:$z, sub2:i32), ?:f32:$w, sub3:i32)
/*36762*/   0, // EndSwitchType
/*36763*/ /*SwitchOpcode*/ 38|128,19/*2470*/,  TARGET_VAL(AMDGPUISD::TEXTURE_FETCH),// ->39237
/*36767*/   OPC_MoveChild, 0,
/*36769*/   OPC_CheckType, MVT::i32,
/*36771*/   OPC_Scope, 94|128,1/*222*/, /*->36996*/ // 11 children in Scope
/*36774*/     OPC_CheckInteger, 0, 
/*36776*/     OPC_MoveParent,
/*36777*/     OPC_RecordChild1, // #0 = $SRC_GPR
/*36778*/     OPC_CheckChild1Type, MVT::v4f32,
/*36780*/     OPC_RecordChild2, // #1 = $srcx
/*36781*/     OPC_MoveChild, 2,
/*36783*/     OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*36786*/     OPC_CheckType, MVT::i32,
/*36788*/     OPC_MoveParent,
/*36789*/     OPC_RecordChild3, // #2 = $srcy
/*36790*/     OPC_MoveChild, 3,
/*36792*/     OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*36795*/     OPC_CheckType, MVT::i32,
/*36797*/     OPC_MoveParent,
/*36798*/     OPC_RecordChild4, // #3 = $srcz
/*36799*/     OPC_MoveChild, 4,
/*36801*/     OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*36804*/     OPC_CheckType, MVT::i32,
/*36806*/     OPC_MoveParent,
/*36807*/     OPC_RecordChild5, // #4 = $srcw
/*36808*/     OPC_MoveChild, 5,
/*36810*/     OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*36813*/     OPC_CheckType, MVT::i32,
/*36815*/     OPC_MoveParent,
/*36816*/     OPC_RecordChild6, // #5 = $offsetx
/*36817*/     OPC_MoveChild, 6,
/*36819*/     OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*36822*/     OPC_CheckType, MVT::i32,
/*36824*/     OPC_MoveParent,
/*36825*/     OPC_RecordChild7, // #6 = $offsety
/*36826*/     OPC_MoveChild, 7,
/*36828*/     OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*36831*/     OPC_CheckType, MVT::i32,
/*36833*/     OPC_MoveParent,
/*36834*/     OPC_MoveChild, 8,
/*36836*/     OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*36839*/     OPC_RecordNode, // #7 = $offsetz
/*36840*/     OPC_CheckType, MVT::i32,
/*36842*/     OPC_MoveParent,
/*36843*/     OPC_MoveChild, 9,
/*36845*/     OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*36848*/     OPC_RecordNode, // #8 = $DST_SEL_X
/*36849*/     OPC_CheckType, MVT::i32,
/*36851*/     OPC_MoveParent,
/*36852*/     OPC_MoveChild, 10,
/*36854*/     OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*36857*/     OPC_RecordNode, // #9 = $DST_SEL_Y
/*36858*/     OPC_CheckType, MVT::i32,
/*36860*/     OPC_MoveParent,
/*36861*/     OPC_MoveChild, 11,
/*36863*/     OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*36866*/     OPC_RecordNode, // #10 = $DST_SEL_Z
/*36867*/     OPC_CheckType, MVT::i32,
/*36869*/     OPC_MoveParent,
/*36870*/     OPC_MoveChild, 12,
/*36872*/     OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*36875*/     OPC_RecordNode, // #11 = $DST_SEL_W
/*36876*/     OPC_CheckType, MVT::i32,
/*36878*/     OPC_MoveParent,
/*36879*/     OPC_MoveChild, 13,
/*36881*/     OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*36884*/     OPC_RecordNode, // #12 = $RESOURCE_ID
/*36885*/     OPC_CheckType, MVT::i32,
/*36887*/     OPC_MoveParent,
/*36888*/     OPC_MoveChild, 14,
/*36890*/     OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*36893*/     OPC_RecordNode, // #13 = $SAMPLER_ID
/*36894*/     OPC_CheckType, MVT::i32,
/*36896*/     OPC_MoveParent,
/*36897*/     OPC_MoveChild, 15,
/*36899*/     OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*36902*/     OPC_RecordNode, // #14 = $COORD_TYPE_X
/*36903*/     OPC_CheckType, MVT::i32,
/*36905*/     OPC_MoveParent,
/*36906*/     OPC_MoveChild, 16,
/*36908*/     OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*36911*/     OPC_RecordNode, // #15 = $COORD_TYPE_Y
/*36912*/     OPC_CheckType, MVT::i32,
/*36914*/     OPC_MoveParent,
/*36915*/     OPC_MoveChild, 17,
/*36917*/     OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*36920*/     OPC_RecordNode, // #16 = $COORD_TYPE_Z
/*36921*/     OPC_CheckType, MVT::i32,
/*36923*/     OPC_MoveParent,
/*36924*/     OPC_MoveChild, 18,
/*36926*/     OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*36929*/     OPC_RecordNode, // #17 = $COORD_TYPE_W
/*36930*/     OPC_CheckType, MVT::i32,
/*36932*/     OPC_MoveParent,
/*36933*/     OPC_CheckType, MVT::v4f32,
/*36935*/     OPC_CheckPatternPredicate, 3, // (Subtarget.getGeneration() <= AMDGPUSubtarget::NORTHERN_ISLANDS)
/*36937*/     OPC_EmitConvertToTarget, 1,
/*36939*/     OPC_EmitConvertToTarget, 2,
/*36941*/     OPC_EmitConvertToTarget, 3,
/*36943*/     OPC_EmitConvertToTarget, 4,
/*36945*/     OPC_EmitConvertToTarget, 5,
/*36947*/     OPC_EmitConvertToTarget, 6,
/*36949*/     OPC_EmitConvertToTarget, 7,
/*36951*/     OPC_EmitConvertToTarget, 8,
/*36953*/     OPC_EmitConvertToTarget, 9,
/*36955*/     OPC_EmitConvertToTarget, 10,
/*36957*/     OPC_EmitConvertToTarget, 11,
/*36959*/     OPC_EmitConvertToTarget, 12,
/*36961*/     OPC_EmitConvertToTarget, 13,
/*36963*/     OPC_EmitConvertToTarget, 14,
/*36965*/     OPC_EmitConvertToTarget, 15,
/*36967*/     OPC_EmitConvertToTarget, 16,
/*36969*/     OPC_EmitConvertToTarget, 17,
/*36971*/     OPC_MorphNodeTo, TARGET_VAL(AMDGPU::TEX_SAMPLE), 0,
                  1/*#VTs*/, MVT::v4f32, 18/*#Ops*/, 0, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 
              // Src: (TEXTURE_FETCH:v4f32 0:i32, v4f32:v4f32:$SRC_GPR, (imm:i32):$srcx, (imm:i32):$srcy, (imm:i32):$srcz, (imm:i32):$srcw, (imm:i32):$offsetx, (imm:i32):$offsety, (imm:i32):$offsetz, (imm:i32):$DST_SEL_X, (imm:i32):$DST_SEL_Y, (imm:i32):$DST_SEL_Z, (imm:i32):$DST_SEL_W, (imm:i32):$RESOURCE_ID, (imm:i32):$SAMPLER_ID, (imm:i32):$COORD_TYPE_X, (imm:i32):$COORD_TYPE_Y, (imm:i32):$COORD_TYPE_Z, (imm:i32):$COORD_TYPE_W) - Complexity = 59
              // Dst: (TEX_SAMPLE:v4f32 R600_Reg128:v4f32:$SRC_GPR, (imm:i32):$srcx, (imm:i32):$srcy, (imm:i32):$srcz, (imm:i32):$srcw, (imm:i32):$offsetx, (imm:i32):$offsety, (imm:i32):$offsetz, (imm:i32):$DST_SEL_X, (imm:i32):$DST_SEL_Y, (imm:i32):$DST_SEL_Z, (imm:i32):$DST_SEL_W, (imm:i32):$RESOURCE_ID, (imm:i32):$SAMPLER_ID, (imm:i32):$COORD_TYPE_X, (imm:i32):$COORD_TYPE_Y, (imm:i32):$COORD_TYPE_Z, (imm:i32):$COORD_TYPE_W)
/*36996*/   /*Scope*/ 94|128,1/*222*/, /*->37220*/
/*36998*/     OPC_CheckInteger, 1, 
/*37000*/     OPC_MoveParent,
/*37001*/     OPC_RecordChild1, // #0 = $SRC_GPR
/*37002*/     OPC_CheckChild1Type, MVT::v4f32,
/*37004*/     OPC_RecordChild2, // #1 = $srcx
/*37005*/     OPC_MoveChild, 2,
/*37007*/     OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*37010*/     OPC_CheckType, MVT::i32,
/*37012*/     OPC_MoveParent,
/*37013*/     OPC_RecordChild3, // #2 = $srcy
/*37014*/     OPC_MoveChild, 3,
/*37016*/     OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*37019*/     OPC_CheckType, MVT::i32,
/*37021*/     OPC_MoveParent,
/*37022*/     OPC_RecordChild4, // #3 = $srcz
/*37023*/     OPC_MoveChild, 4,
/*37025*/     OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*37028*/     OPC_CheckType, MVT::i32,
/*37030*/     OPC_MoveParent,
/*37031*/     OPC_RecordChild5, // #4 = $srcw
/*37032*/     OPC_MoveChild, 5,
/*37034*/     OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*37037*/     OPC_CheckType, MVT::i32,
/*37039*/     OPC_MoveParent,
/*37040*/     OPC_RecordChild6, // #5 = $offsetx
/*37041*/     OPC_MoveChild, 6,
/*37043*/     OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*37046*/     OPC_CheckType, MVT::i32,
/*37048*/     OPC_MoveParent,
/*37049*/     OPC_RecordChild7, // #6 = $offsety
/*37050*/     OPC_MoveChild, 7,
/*37052*/     OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*37055*/     OPC_CheckType, MVT::i32,
/*37057*/     OPC_MoveParent,
/*37058*/     OPC_MoveChild, 8,
/*37060*/     OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*37063*/     OPC_RecordNode, // #7 = $offsetz
/*37064*/     OPC_CheckType, MVT::i32,
/*37066*/     OPC_MoveParent,
/*37067*/     OPC_MoveChild, 9,
/*37069*/     OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*37072*/     OPC_RecordNode, // #8 = $DST_SEL_X
/*37073*/     OPC_CheckType, MVT::i32,
/*37075*/     OPC_MoveParent,
/*37076*/     OPC_MoveChild, 10,
/*37078*/     OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*37081*/     OPC_RecordNode, // #9 = $DST_SEL_Y
/*37082*/     OPC_CheckType, MVT::i32,
/*37084*/     OPC_MoveParent,
/*37085*/     OPC_MoveChild, 11,
/*37087*/     OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*37090*/     OPC_RecordNode, // #10 = $DST_SEL_Z
/*37091*/     OPC_CheckType, MVT::i32,
/*37093*/     OPC_MoveParent,
/*37094*/     OPC_MoveChild, 12,
/*37096*/     OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*37099*/     OPC_RecordNode, // #11 = $DST_SEL_W
/*37100*/     OPC_CheckType, MVT::i32,
/*37102*/     OPC_MoveParent,
/*37103*/     OPC_MoveChild, 13,
/*37105*/     OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*37108*/     OPC_RecordNode, // #12 = $RESOURCE_ID
/*37109*/     OPC_CheckType, MVT::i32,
/*37111*/     OPC_MoveParent,
/*37112*/     OPC_MoveChild, 14,
/*37114*/     OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*37117*/     OPC_RecordNode, // #13 = $SAMPLER_ID
/*37118*/     OPC_CheckType, MVT::i32,
/*37120*/     OPC_MoveParent,
/*37121*/     OPC_MoveChild, 15,
/*37123*/     OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*37126*/     OPC_RecordNode, // #14 = $COORD_TYPE_X
/*37127*/     OPC_CheckType, MVT::i32,
/*37129*/     OPC_MoveParent,
/*37130*/     OPC_MoveChild, 16,
/*37132*/     OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*37135*/     OPC_RecordNode, // #15 = $COORD_TYPE_Y
/*37136*/     OPC_CheckType, MVT::i32,
/*37138*/     OPC_MoveParent,
/*37139*/     OPC_MoveChild, 17,
/*37141*/     OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*37144*/     OPC_RecordNode, // #16 = $COORD_TYPE_Z
/*37145*/     OPC_CheckType, MVT::i32,
/*37147*/     OPC_MoveParent,
/*37148*/     OPC_MoveChild, 18,
/*37150*/     OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*37153*/     OPC_RecordNode, // #17 = $COORD_TYPE_W
/*37154*/     OPC_CheckType, MVT::i32,
/*37156*/     OPC_MoveParent,
/*37157*/     OPC_CheckType, MVT::v4f32,
/*37159*/     OPC_CheckPatternPredicate, 3, // (Subtarget.getGeneration() <= AMDGPUSubtarget::NORTHERN_ISLANDS)
/*37161*/     OPC_EmitConvertToTarget, 1,
/*37163*/     OPC_EmitConvertToTarget, 2,
/*37165*/     OPC_EmitConvertToTarget, 3,
/*37167*/     OPC_EmitConvertToTarget, 4,
/*37169*/     OPC_EmitConvertToTarget, 5,
/*37171*/     OPC_EmitConvertToTarget, 6,
/*37173*/     OPC_EmitConvertToTarget, 7,
/*37175*/     OPC_EmitConvertToTarget, 8,
/*37177*/     OPC_EmitConvertToTarget, 9,
/*37179*/     OPC_EmitConvertToTarget, 10,
/*37181*/     OPC_EmitConvertToTarget, 11,
/*37183*/     OPC_EmitConvertToTarget, 12,
/*37185*/     OPC_EmitConvertToTarget, 13,
/*37187*/     OPC_EmitConvertToTarget, 14,
/*37189*/     OPC_EmitConvertToTarget, 15,
/*37191*/     OPC_EmitConvertToTarget, 16,
/*37193*/     OPC_EmitConvertToTarget, 17,
/*37195*/     OPC_MorphNodeTo, TARGET_VAL(AMDGPU::TEX_SAMPLE_C), 0,
                  1/*#VTs*/, MVT::v4f32, 18/*#Ops*/, 0, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 
              // Src: (TEXTURE_FETCH:v4f32 1:i32, v4f32:v4f32:$SRC_GPR, (imm:i32):$srcx, (imm:i32):$srcy, (imm:i32):$srcz, (imm:i32):$srcw, (imm:i32):$offsetx, (imm:i32):$offsety, (imm:i32):$offsetz, (imm:i32):$DST_SEL_X, (imm:i32):$DST_SEL_Y, (imm:i32):$DST_SEL_Z, (imm:i32):$DST_SEL_W, (imm:i32):$RESOURCE_ID, (imm:i32):$SAMPLER_ID, (imm:i32):$COORD_TYPE_X, (imm:i32):$COORD_TYPE_Y, (imm:i32):$COORD_TYPE_Z, (imm:i32):$COORD_TYPE_W) - Complexity = 59
              // Dst: (TEX_SAMPLE_C:v4f32 R600_Reg128:v4f32:$SRC_GPR, (imm:i32):$srcx, (imm:i32):$srcy, (imm:i32):$srcz, (imm:i32):$srcw, (imm:i32):$offsetx, (imm:i32):$offsety, (imm:i32):$offsetz, (imm:i32):$DST_SEL_X, (imm:i32):$DST_SEL_Y, (imm:i32):$DST_SEL_Z, (imm:i32):$DST_SEL_W, (imm:i32):$RESOURCE_ID, (imm:i32):$SAMPLER_ID, (imm:i32):$COORD_TYPE_X, (imm:i32):$COORD_TYPE_Y, (imm:i32):$COORD_TYPE_Z, (imm:i32):$COORD_TYPE_W)
/*37220*/   /*Scope*/ 94|128,1/*222*/, /*->37444*/
/*37222*/     OPC_CheckInteger, 2, 
/*37224*/     OPC_MoveParent,
/*37225*/     OPC_RecordChild1, // #0 = $SRC_GPR
/*37226*/     OPC_CheckChild1Type, MVT::v4f32,
/*37228*/     OPC_RecordChild2, // #1 = $srcx
/*37229*/     OPC_MoveChild, 2,
/*37231*/     OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*37234*/     OPC_CheckType, MVT::i32,
/*37236*/     OPC_MoveParent,
/*37237*/     OPC_RecordChild3, // #2 = $srcy
/*37238*/     OPC_MoveChild, 3,
/*37240*/     OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*37243*/     OPC_CheckType, MVT::i32,
/*37245*/     OPC_MoveParent,
/*37246*/     OPC_RecordChild4, // #3 = $srcz
/*37247*/     OPC_MoveChild, 4,
/*37249*/     OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*37252*/     OPC_CheckType, MVT::i32,
/*37254*/     OPC_MoveParent,
/*37255*/     OPC_RecordChild5, // #4 = $srcw
/*37256*/     OPC_MoveChild, 5,
/*37258*/     OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*37261*/     OPC_CheckType, MVT::i32,
/*37263*/     OPC_MoveParent,
/*37264*/     OPC_RecordChild6, // #5 = $offsetx
/*37265*/     OPC_MoveChild, 6,
/*37267*/     OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*37270*/     OPC_CheckType, MVT::i32,
/*37272*/     OPC_MoveParent,
/*37273*/     OPC_RecordChild7, // #6 = $offsety
/*37274*/     OPC_MoveChild, 7,
/*37276*/     OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*37279*/     OPC_CheckType, MVT::i32,
/*37281*/     OPC_MoveParent,
/*37282*/     OPC_MoveChild, 8,
/*37284*/     OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*37287*/     OPC_RecordNode, // #7 = $offsetz
/*37288*/     OPC_CheckType, MVT::i32,
/*37290*/     OPC_MoveParent,
/*37291*/     OPC_MoveChild, 9,
/*37293*/     OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*37296*/     OPC_RecordNode, // #8 = $DST_SEL_X
/*37297*/     OPC_CheckType, MVT::i32,
/*37299*/     OPC_MoveParent,
/*37300*/     OPC_MoveChild, 10,
/*37302*/     OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*37305*/     OPC_RecordNode, // #9 = $DST_SEL_Y
/*37306*/     OPC_CheckType, MVT::i32,
/*37308*/     OPC_MoveParent,
/*37309*/     OPC_MoveChild, 11,
/*37311*/     OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*37314*/     OPC_RecordNode, // #10 = $DST_SEL_Z
/*37315*/     OPC_CheckType, MVT::i32,
/*37317*/     OPC_MoveParent,
/*37318*/     OPC_MoveChild, 12,
/*37320*/     OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*37323*/     OPC_RecordNode, // #11 = $DST_SEL_W
/*37324*/     OPC_CheckType, MVT::i32,
/*37326*/     OPC_MoveParent,
/*37327*/     OPC_MoveChild, 13,
/*37329*/     OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*37332*/     OPC_RecordNode, // #12 = $RESOURCE_ID
/*37333*/     OPC_CheckType, MVT::i32,
/*37335*/     OPC_MoveParent,
/*37336*/     OPC_MoveChild, 14,
/*37338*/     OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*37341*/     OPC_RecordNode, // #13 = $SAMPLER_ID
/*37342*/     OPC_CheckType, MVT::i32,
/*37344*/     OPC_MoveParent,
/*37345*/     OPC_MoveChild, 15,
/*37347*/     OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*37350*/     OPC_RecordNode, // #14 = $COORD_TYPE_X
/*37351*/     OPC_CheckType, MVT::i32,
/*37353*/     OPC_MoveParent,
/*37354*/     OPC_MoveChild, 16,
/*37356*/     OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*37359*/     OPC_RecordNode, // #15 = $COORD_TYPE_Y
/*37360*/     OPC_CheckType, MVT::i32,
/*37362*/     OPC_MoveParent,
/*37363*/     OPC_MoveChild, 17,
/*37365*/     OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*37368*/     OPC_RecordNode, // #16 = $COORD_TYPE_Z
/*37369*/     OPC_CheckType, MVT::i32,
/*37371*/     OPC_MoveParent,
/*37372*/     OPC_MoveChild, 18,
/*37374*/     OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*37377*/     OPC_RecordNode, // #17 = $COORD_TYPE_W
/*37378*/     OPC_CheckType, MVT::i32,
/*37380*/     OPC_MoveParent,
/*37381*/     OPC_CheckType, MVT::v4f32,
/*37383*/     OPC_CheckPatternPredicate, 3, // (Subtarget.getGeneration() <= AMDGPUSubtarget::NORTHERN_ISLANDS)
/*37385*/     OPC_EmitConvertToTarget, 1,
/*37387*/     OPC_EmitConvertToTarget, 2,
/*37389*/     OPC_EmitConvertToTarget, 3,
/*37391*/     OPC_EmitConvertToTarget, 4,
/*37393*/     OPC_EmitConvertToTarget, 5,
/*37395*/     OPC_EmitConvertToTarget, 6,
/*37397*/     OPC_EmitConvertToTarget, 7,
/*37399*/     OPC_EmitConvertToTarget, 8,
/*37401*/     OPC_EmitConvertToTarget, 9,
/*37403*/     OPC_EmitConvertToTarget, 10,
/*37405*/     OPC_EmitConvertToTarget, 11,
/*37407*/     OPC_EmitConvertToTarget, 12,
/*37409*/     OPC_EmitConvertToTarget, 13,
/*37411*/     OPC_EmitConvertToTarget, 14,
/*37413*/     OPC_EmitConvertToTarget, 15,
/*37415*/     OPC_EmitConvertToTarget, 16,
/*37417*/     OPC_EmitConvertToTarget, 17,
/*37419*/     OPC_MorphNodeTo, TARGET_VAL(AMDGPU::TEX_SAMPLE_L), 0,
                  1/*#VTs*/, MVT::v4f32, 18/*#Ops*/, 0, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 
              // Src: (TEXTURE_FETCH:v4f32 2:i32, v4f32:v4f32:$SRC_GPR, (imm:i32):$srcx, (imm:i32):$srcy, (imm:i32):$srcz, (imm:i32):$srcw, (imm:i32):$offsetx, (imm:i32):$offsety, (imm:i32):$offsetz, (imm:i32):$DST_SEL_X, (imm:i32):$DST_SEL_Y, (imm:i32):$DST_SEL_Z, (imm:i32):$DST_SEL_W, (imm:i32):$RESOURCE_ID, (imm:i32):$SAMPLER_ID, (imm:i32):$COORD_TYPE_X, (imm:i32):$COORD_TYPE_Y, (imm:i32):$COORD_TYPE_Z, (imm:i32):$COORD_TYPE_W) - Complexity = 59
              // Dst: (TEX_SAMPLE_L:v4f32 R600_Reg128:v4f32:$SRC_GPR, (imm:i32):$srcx, (imm:i32):$srcy, (imm:i32):$srcz, (imm:i32):$srcw, (imm:i32):$offsetx, (imm:i32):$offsety, (imm:i32):$offsetz, (imm:i32):$DST_SEL_X, (imm:i32):$DST_SEL_Y, (imm:i32):$DST_SEL_Z, (imm:i32):$DST_SEL_W, (imm:i32):$RESOURCE_ID, (imm:i32):$SAMPLER_ID, (imm:i32):$COORD_TYPE_X, (imm:i32):$COORD_TYPE_Y, (imm:i32):$COORD_TYPE_Z, (imm:i32):$COORD_TYPE_W)
/*37444*/   /*Scope*/ 94|128,1/*222*/, /*->37668*/
/*37446*/     OPC_CheckInteger, 3, 
/*37448*/     OPC_MoveParent,
/*37449*/     OPC_RecordChild1, // #0 = $SRC_GPR
/*37450*/     OPC_CheckChild1Type, MVT::v4f32,
/*37452*/     OPC_RecordChild2, // #1 = $srcx
/*37453*/     OPC_MoveChild, 2,
/*37455*/     OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*37458*/     OPC_CheckType, MVT::i32,
/*37460*/     OPC_MoveParent,
/*37461*/     OPC_RecordChild3, // #2 = $srcy
/*37462*/     OPC_MoveChild, 3,
/*37464*/     OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*37467*/     OPC_CheckType, MVT::i32,
/*37469*/     OPC_MoveParent,
/*37470*/     OPC_RecordChild4, // #3 = $srcz
/*37471*/     OPC_MoveChild, 4,
/*37473*/     OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*37476*/     OPC_CheckType, MVT::i32,
/*37478*/     OPC_MoveParent,
/*37479*/     OPC_RecordChild5, // #4 = $srcw
/*37480*/     OPC_MoveChild, 5,
/*37482*/     OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*37485*/     OPC_CheckType, MVT::i32,
/*37487*/     OPC_MoveParent,
/*37488*/     OPC_RecordChild6, // #5 = $offsetx
/*37489*/     OPC_MoveChild, 6,
/*37491*/     OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*37494*/     OPC_CheckType, MVT::i32,
/*37496*/     OPC_MoveParent,
/*37497*/     OPC_RecordChild7, // #6 = $offsety
/*37498*/     OPC_MoveChild, 7,
/*37500*/     OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*37503*/     OPC_CheckType, MVT::i32,
/*37505*/     OPC_MoveParent,
/*37506*/     OPC_MoveChild, 8,
/*37508*/     OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*37511*/     OPC_RecordNode, // #7 = $offsetz
/*37512*/     OPC_CheckType, MVT::i32,
/*37514*/     OPC_MoveParent,
/*37515*/     OPC_MoveChild, 9,
/*37517*/     OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*37520*/     OPC_RecordNode, // #8 = $DST_SEL_X
/*37521*/     OPC_CheckType, MVT::i32,
/*37523*/     OPC_MoveParent,
/*37524*/     OPC_MoveChild, 10,
/*37526*/     OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*37529*/     OPC_RecordNode, // #9 = $DST_SEL_Y
/*37530*/     OPC_CheckType, MVT::i32,
/*37532*/     OPC_MoveParent,
/*37533*/     OPC_MoveChild, 11,
/*37535*/     OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*37538*/     OPC_RecordNode, // #10 = $DST_SEL_Z
/*37539*/     OPC_CheckType, MVT::i32,
/*37541*/     OPC_MoveParent,
/*37542*/     OPC_MoveChild, 12,
/*37544*/     OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*37547*/     OPC_RecordNode, // #11 = $DST_SEL_W
/*37548*/     OPC_CheckType, MVT::i32,
/*37550*/     OPC_MoveParent,
/*37551*/     OPC_MoveChild, 13,
/*37553*/     OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*37556*/     OPC_RecordNode, // #12 = $RESOURCE_ID
/*37557*/     OPC_CheckType, MVT::i32,
/*37559*/     OPC_MoveParent,
/*37560*/     OPC_MoveChild, 14,
/*37562*/     OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*37565*/     OPC_RecordNode, // #13 = $SAMPLER_ID
/*37566*/     OPC_CheckType, MVT::i32,
/*37568*/     OPC_MoveParent,
/*37569*/     OPC_MoveChild, 15,
/*37571*/     OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*37574*/     OPC_RecordNode, // #14 = $COORD_TYPE_X
/*37575*/     OPC_CheckType, MVT::i32,
/*37577*/     OPC_MoveParent,
/*37578*/     OPC_MoveChild, 16,
/*37580*/     OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*37583*/     OPC_RecordNode, // #15 = $COORD_TYPE_Y
/*37584*/     OPC_CheckType, MVT::i32,
/*37586*/     OPC_MoveParent,
/*37587*/     OPC_MoveChild, 17,
/*37589*/     OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*37592*/     OPC_RecordNode, // #16 = $COORD_TYPE_Z
/*37593*/     OPC_CheckType, MVT::i32,
/*37595*/     OPC_MoveParent,
/*37596*/     OPC_MoveChild, 18,
/*37598*/     OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*37601*/     OPC_RecordNode, // #17 = $COORD_TYPE_W
/*37602*/     OPC_CheckType, MVT::i32,
/*37604*/     OPC_MoveParent,
/*37605*/     OPC_CheckType, MVT::v4f32,
/*37607*/     OPC_CheckPatternPredicate, 3, // (Subtarget.getGeneration() <= AMDGPUSubtarget::NORTHERN_ISLANDS)
/*37609*/     OPC_EmitConvertToTarget, 1,
/*37611*/     OPC_EmitConvertToTarget, 2,
/*37613*/     OPC_EmitConvertToTarget, 3,
/*37615*/     OPC_EmitConvertToTarget, 4,
/*37617*/     OPC_EmitConvertToTarget, 5,
/*37619*/     OPC_EmitConvertToTarget, 6,
/*37621*/     OPC_EmitConvertToTarget, 7,
/*37623*/     OPC_EmitConvertToTarget, 8,
/*37625*/     OPC_EmitConvertToTarget, 9,
/*37627*/     OPC_EmitConvertToTarget, 10,
/*37629*/     OPC_EmitConvertToTarget, 11,
/*37631*/     OPC_EmitConvertToTarget, 12,
/*37633*/     OPC_EmitConvertToTarget, 13,
/*37635*/     OPC_EmitConvertToTarget, 14,
/*37637*/     OPC_EmitConvertToTarget, 15,
/*37639*/     OPC_EmitConvertToTarget, 16,
/*37641*/     OPC_EmitConvertToTarget, 17,
/*37643*/     OPC_MorphNodeTo, TARGET_VAL(AMDGPU::TEX_SAMPLE_C_L), 0,
                  1/*#VTs*/, MVT::v4f32, 18/*#Ops*/, 0, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 
              // Src: (TEXTURE_FETCH:v4f32 3:i32, v4f32:v4f32:$SRC_GPR, (imm:i32):$srcx, (imm:i32):$srcy, (imm:i32):$srcz, (imm:i32):$srcw, (imm:i32):$offsetx, (imm:i32):$offsety, (imm:i32):$offsetz, (imm:i32):$DST_SEL_X, (imm:i32):$DST_SEL_Y, (imm:i32):$DST_SEL_Z, (imm:i32):$DST_SEL_W, (imm:i32):$RESOURCE_ID, (imm:i32):$SAMPLER_ID, (imm:i32):$COORD_TYPE_X, (imm:i32):$COORD_TYPE_Y, (imm:i32):$COORD_TYPE_Z, (imm:i32):$COORD_TYPE_W) - Complexity = 59
              // Dst: (TEX_SAMPLE_C_L:v4f32 R600_Reg128:v4f32:$SRC_GPR, (imm:i32):$srcx, (imm:i32):$srcy, (imm:i32):$srcz, (imm:i32):$srcw, (imm:i32):$offsetx, (imm:i32):$offsety, (imm:i32):$offsetz, (imm:i32):$DST_SEL_X, (imm:i32):$DST_SEL_Y, (imm:i32):$DST_SEL_Z, (imm:i32):$DST_SEL_W, (imm:i32):$RESOURCE_ID, (imm:i32):$SAMPLER_ID, (imm:i32):$COORD_TYPE_X, (imm:i32):$COORD_TYPE_Y, (imm:i32):$COORD_TYPE_Z, (imm:i32):$COORD_TYPE_W)
/*37668*/   /*Scope*/ 94|128,1/*222*/, /*->37892*/
/*37670*/     OPC_CheckInteger, 4, 
/*37672*/     OPC_MoveParent,
/*37673*/     OPC_RecordChild1, // #0 = $SRC_GPR
/*37674*/     OPC_CheckChild1Type, MVT::v4f32,
/*37676*/     OPC_RecordChild2, // #1 = $srcx
/*37677*/     OPC_MoveChild, 2,
/*37679*/     OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*37682*/     OPC_CheckType, MVT::i32,
/*37684*/     OPC_MoveParent,
/*37685*/     OPC_RecordChild3, // #2 = $srcy
/*37686*/     OPC_MoveChild, 3,
/*37688*/     OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*37691*/     OPC_CheckType, MVT::i32,
/*37693*/     OPC_MoveParent,
/*37694*/     OPC_RecordChild4, // #3 = $srcz
/*37695*/     OPC_MoveChild, 4,
/*37697*/     OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*37700*/     OPC_CheckType, MVT::i32,
/*37702*/     OPC_MoveParent,
/*37703*/     OPC_RecordChild5, // #4 = $srcw
/*37704*/     OPC_MoveChild, 5,
/*37706*/     OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*37709*/     OPC_CheckType, MVT::i32,
/*37711*/     OPC_MoveParent,
/*37712*/     OPC_RecordChild6, // #5 = $offsetx
/*37713*/     OPC_MoveChild, 6,
/*37715*/     OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*37718*/     OPC_CheckType, MVT::i32,
/*37720*/     OPC_MoveParent,
/*37721*/     OPC_RecordChild7, // #6 = $offsety
/*37722*/     OPC_MoveChild, 7,
/*37724*/     OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*37727*/     OPC_CheckType, MVT::i32,
/*37729*/     OPC_MoveParent,
/*37730*/     OPC_MoveChild, 8,
/*37732*/     OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*37735*/     OPC_RecordNode, // #7 = $offsetz
/*37736*/     OPC_CheckType, MVT::i32,
/*37738*/     OPC_MoveParent,
/*37739*/     OPC_MoveChild, 9,
/*37741*/     OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*37744*/     OPC_RecordNode, // #8 = $DST_SEL_X
/*37745*/     OPC_CheckType, MVT::i32,
/*37747*/     OPC_MoveParent,
/*37748*/     OPC_MoveChild, 10,
/*37750*/     OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*37753*/     OPC_RecordNode, // #9 = $DST_SEL_Y
/*37754*/     OPC_CheckType, MVT::i32,
/*37756*/     OPC_MoveParent,
/*37757*/     OPC_MoveChild, 11,
/*37759*/     OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*37762*/     OPC_RecordNode, // #10 = $DST_SEL_Z
/*37763*/     OPC_CheckType, MVT::i32,
/*37765*/     OPC_MoveParent,
/*37766*/     OPC_MoveChild, 12,
/*37768*/     OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*37771*/     OPC_RecordNode, // #11 = $DST_SEL_W
/*37772*/     OPC_CheckType, MVT::i32,
/*37774*/     OPC_MoveParent,
/*37775*/     OPC_MoveChild, 13,
/*37777*/     OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*37780*/     OPC_RecordNode, // #12 = $RESOURCE_ID
/*37781*/     OPC_CheckType, MVT::i32,
/*37783*/     OPC_MoveParent,
/*37784*/     OPC_MoveChild, 14,
/*37786*/     OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*37789*/     OPC_RecordNode, // #13 = $SAMPLER_ID
/*37790*/     OPC_CheckType, MVT::i32,
/*37792*/     OPC_MoveParent,
/*37793*/     OPC_MoveChild, 15,
/*37795*/     OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*37798*/     OPC_RecordNode, // #14 = $COORD_TYPE_X
/*37799*/     OPC_CheckType, MVT::i32,
/*37801*/     OPC_MoveParent,
/*37802*/     OPC_MoveChild, 16,
/*37804*/     OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*37807*/     OPC_RecordNode, // #15 = $COORD_TYPE_Y
/*37808*/     OPC_CheckType, MVT::i32,
/*37810*/     OPC_MoveParent,
/*37811*/     OPC_MoveChild, 17,
/*37813*/     OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*37816*/     OPC_RecordNode, // #16 = $COORD_TYPE_Z
/*37817*/     OPC_CheckType, MVT::i32,
/*37819*/     OPC_MoveParent,
/*37820*/     OPC_MoveChild, 18,
/*37822*/     OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*37825*/     OPC_RecordNode, // #17 = $COORD_TYPE_W
/*37826*/     OPC_CheckType, MVT::i32,
/*37828*/     OPC_MoveParent,
/*37829*/     OPC_CheckType, MVT::v4f32,
/*37831*/     OPC_CheckPatternPredicate, 3, // (Subtarget.getGeneration() <= AMDGPUSubtarget::NORTHERN_ISLANDS)
/*37833*/     OPC_EmitConvertToTarget, 1,
/*37835*/     OPC_EmitConvertToTarget, 2,
/*37837*/     OPC_EmitConvertToTarget, 3,
/*37839*/     OPC_EmitConvertToTarget, 4,
/*37841*/     OPC_EmitConvertToTarget, 5,
/*37843*/     OPC_EmitConvertToTarget, 6,
/*37845*/     OPC_EmitConvertToTarget, 7,
/*37847*/     OPC_EmitConvertToTarget, 8,
/*37849*/     OPC_EmitConvertToTarget, 9,
/*37851*/     OPC_EmitConvertToTarget, 10,
/*37853*/     OPC_EmitConvertToTarget, 11,
/*37855*/     OPC_EmitConvertToTarget, 12,
/*37857*/     OPC_EmitConvertToTarget, 13,
/*37859*/     OPC_EmitConvertToTarget, 14,
/*37861*/     OPC_EmitConvertToTarget, 15,
/*37863*/     OPC_EmitConvertToTarget, 16,
/*37865*/     OPC_EmitConvertToTarget, 17,
/*37867*/     OPC_MorphNodeTo, TARGET_VAL(AMDGPU::TEX_SAMPLE_LB), 0,
                  1/*#VTs*/, MVT::v4f32, 18/*#Ops*/, 0, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 
              // Src: (TEXTURE_FETCH:v4f32 4:i32, v4f32:v4f32:$SRC_GPR, (imm:i32):$srcx, (imm:i32):$srcy, (imm:i32):$srcz, (imm:i32):$srcw, (imm:i32):$offsetx, (imm:i32):$offsety, (imm:i32):$offsetz, (imm:i32):$DST_SEL_X, (imm:i32):$DST_SEL_Y, (imm:i32):$DST_SEL_Z, (imm:i32):$DST_SEL_W, (imm:i32):$RESOURCE_ID, (imm:i32):$SAMPLER_ID, (imm:i32):$COORD_TYPE_X, (imm:i32):$COORD_TYPE_Y, (imm:i32):$COORD_TYPE_Z, (imm:i32):$COORD_TYPE_W) - Complexity = 59
              // Dst: (TEX_SAMPLE_LB:v4f32 R600_Reg128:v4f32:$SRC_GPR, (imm:i32):$srcx, (imm:i32):$srcy, (imm:i32):$srcz, (imm:i32):$srcw, (imm:i32):$offsetx, (imm:i32):$offsety, (imm:i32):$offsetz, (imm:i32):$DST_SEL_X, (imm:i32):$DST_SEL_Y, (imm:i32):$DST_SEL_Z, (imm:i32):$DST_SEL_W, (imm:i32):$RESOURCE_ID, (imm:i32):$SAMPLER_ID, (imm:i32):$COORD_TYPE_X, (imm:i32):$COORD_TYPE_Y, (imm:i32):$COORD_TYPE_Z, (imm:i32):$COORD_TYPE_W)
/*37892*/   /*Scope*/ 94|128,1/*222*/, /*->38116*/
/*37894*/     OPC_CheckInteger, 5, 
/*37896*/     OPC_MoveParent,
/*37897*/     OPC_RecordChild1, // #0 = $SRC_GPR
/*37898*/     OPC_CheckChild1Type, MVT::v4f32,
/*37900*/     OPC_RecordChild2, // #1 = $srcx
/*37901*/     OPC_MoveChild, 2,
/*37903*/     OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*37906*/     OPC_CheckType, MVT::i32,
/*37908*/     OPC_MoveParent,
/*37909*/     OPC_RecordChild3, // #2 = $srcy
/*37910*/     OPC_MoveChild, 3,
/*37912*/     OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*37915*/     OPC_CheckType, MVT::i32,
/*37917*/     OPC_MoveParent,
/*37918*/     OPC_RecordChild4, // #3 = $srcz
/*37919*/     OPC_MoveChild, 4,
/*37921*/     OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*37924*/     OPC_CheckType, MVT::i32,
/*37926*/     OPC_MoveParent,
/*37927*/     OPC_RecordChild5, // #4 = $srcw
/*37928*/     OPC_MoveChild, 5,
/*37930*/     OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*37933*/     OPC_CheckType, MVT::i32,
/*37935*/     OPC_MoveParent,
/*37936*/     OPC_RecordChild6, // #5 = $offsetx
/*37937*/     OPC_MoveChild, 6,
/*37939*/     OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*37942*/     OPC_CheckType, MVT::i32,
/*37944*/     OPC_MoveParent,
/*37945*/     OPC_RecordChild7, // #6 = $offsety
/*37946*/     OPC_MoveChild, 7,
/*37948*/     OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*37951*/     OPC_CheckType, MVT::i32,
/*37953*/     OPC_MoveParent,
/*37954*/     OPC_MoveChild, 8,
/*37956*/     OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*37959*/     OPC_RecordNode, // #7 = $offsetz
/*37960*/     OPC_CheckType, MVT::i32,
/*37962*/     OPC_MoveParent,
/*37963*/     OPC_MoveChild, 9,
/*37965*/     OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*37968*/     OPC_RecordNode, // #8 = $DST_SEL_X
/*37969*/     OPC_CheckType, MVT::i32,
/*37971*/     OPC_MoveParent,
/*37972*/     OPC_MoveChild, 10,
/*37974*/     OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*37977*/     OPC_RecordNode, // #9 = $DST_SEL_Y
/*37978*/     OPC_CheckType, MVT::i32,
/*37980*/     OPC_MoveParent,
/*37981*/     OPC_MoveChild, 11,
/*37983*/     OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*37986*/     OPC_RecordNode, // #10 = $DST_SEL_Z
/*37987*/     OPC_CheckType, MVT::i32,
/*37989*/     OPC_MoveParent,
/*37990*/     OPC_MoveChild, 12,
/*37992*/     OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*37995*/     OPC_RecordNode, // #11 = $DST_SEL_W
/*37996*/     OPC_CheckType, MVT::i32,
/*37998*/     OPC_MoveParent,
/*37999*/     OPC_MoveChild, 13,
/*38001*/     OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*38004*/     OPC_RecordNode, // #12 = $RESOURCE_ID
/*38005*/     OPC_CheckType, MVT::i32,
/*38007*/     OPC_MoveParent,
/*38008*/     OPC_MoveChild, 14,
/*38010*/     OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*38013*/     OPC_RecordNode, // #13 = $SAMPLER_ID
/*38014*/     OPC_CheckType, MVT::i32,
/*38016*/     OPC_MoveParent,
/*38017*/     OPC_MoveChild, 15,
/*38019*/     OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*38022*/     OPC_RecordNode, // #14 = $COORD_TYPE_X
/*38023*/     OPC_CheckType, MVT::i32,
/*38025*/     OPC_MoveParent,
/*38026*/     OPC_MoveChild, 16,
/*38028*/     OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*38031*/     OPC_RecordNode, // #15 = $COORD_TYPE_Y
/*38032*/     OPC_CheckType, MVT::i32,
/*38034*/     OPC_MoveParent,
/*38035*/     OPC_MoveChild, 17,
/*38037*/     OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*38040*/     OPC_RecordNode, // #16 = $COORD_TYPE_Z
/*38041*/     OPC_CheckType, MVT::i32,
/*38043*/     OPC_MoveParent,
/*38044*/     OPC_MoveChild, 18,
/*38046*/     OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*38049*/     OPC_RecordNode, // #17 = $COORD_TYPE_W
/*38050*/     OPC_CheckType, MVT::i32,
/*38052*/     OPC_MoveParent,
/*38053*/     OPC_CheckType, MVT::v4f32,
/*38055*/     OPC_CheckPatternPredicate, 3, // (Subtarget.getGeneration() <= AMDGPUSubtarget::NORTHERN_ISLANDS)
/*38057*/     OPC_EmitConvertToTarget, 1,
/*38059*/     OPC_EmitConvertToTarget, 2,
/*38061*/     OPC_EmitConvertToTarget, 3,
/*38063*/     OPC_EmitConvertToTarget, 4,
/*38065*/     OPC_EmitConvertToTarget, 5,
/*38067*/     OPC_EmitConvertToTarget, 6,
/*38069*/     OPC_EmitConvertToTarget, 7,
/*38071*/     OPC_EmitConvertToTarget, 8,
/*38073*/     OPC_EmitConvertToTarget, 9,
/*38075*/     OPC_EmitConvertToTarget, 10,
/*38077*/     OPC_EmitConvertToTarget, 11,
/*38079*/     OPC_EmitConvertToTarget, 12,
/*38081*/     OPC_EmitConvertToTarget, 13,
/*38083*/     OPC_EmitConvertToTarget, 14,
/*38085*/     OPC_EmitConvertToTarget, 15,
/*38087*/     OPC_EmitConvertToTarget, 16,
/*38089*/     OPC_EmitConvertToTarget, 17,
/*38091*/     OPC_MorphNodeTo, TARGET_VAL(AMDGPU::TEX_SAMPLE_C_LB), 0,
                  1/*#VTs*/, MVT::v4f32, 18/*#Ops*/, 0, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 
              // Src: (TEXTURE_FETCH:v4f32 5:i32, v4f32:v4f32:$SRC_GPR, (imm:i32):$srcx, (imm:i32):$srcy, (imm:i32):$srcz, (imm:i32):$srcw, (imm:i32):$offsetx, (imm:i32):$offsety, (imm:i32):$offsetz, (imm:i32):$DST_SEL_X, (imm:i32):$DST_SEL_Y, (imm:i32):$DST_SEL_Z, (imm:i32):$DST_SEL_W, (imm:i32):$RESOURCE_ID, (imm:i32):$SAMPLER_ID, (imm:i32):$COORD_TYPE_X, (imm:i32):$COORD_TYPE_Y, (imm:i32):$COORD_TYPE_Z, (imm:i32):$COORD_TYPE_W) - Complexity = 59
              // Dst: (TEX_SAMPLE_C_LB:v4f32 R600_Reg128:v4f32:$SRC_GPR, (imm:i32):$srcx, (imm:i32):$srcy, (imm:i32):$srcz, (imm:i32):$srcw, (imm:i32):$offsetx, (imm:i32):$offsety, (imm:i32):$offsetz, (imm:i32):$DST_SEL_X, (imm:i32):$DST_SEL_Y, (imm:i32):$DST_SEL_Z, (imm:i32):$DST_SEL_W, (imm:i32):$RESOURCE_ID, (imm:i32):$SAMPLER_ID, (imm:i32):$COORD_TYPE_X, (imm:i32):$COORD_TYPE_Y, (imm:i32):$COORD_TYPE_Z, (imm:i32):$COORD_TYPE_W)
/*38116*/   /*Scope*/ 94|128,1/*222*/, /*->38340*/
/*38118*/     OPC_CheckInteger, 6, 
/*38120*/     OPC_MoveParent,
/*38121*/     OPC_RecordChild1, // #0 = $SRC_GPR
/*38122*/     OPC_CheckChild1Type, MVT::v4i32,
/*38124*/     OPC_RecordChild2, // #1 = $srcx
/*38125*/     OPC_MoveChild, 2,
/*38127*/     OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*38130*/     OPC_CheckType, MVT::i32,
/*38132*/     OPC_MoveParent,
/*38133*/     OPC_RecordChild3, // #2 = $srcy
/*38134*/     OPC_MoveChild, 3,
/*38136*/     OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*38139*/     OPC_CheckType, MVT::i32,
/*38141*/     OPC_MoveParent,
/*38142*/     OPC_RecordChild4, // #3 = $srcz
/*38143*/     OPC_MoveChild, 4,
/*38145*/     OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*38148*/     OPC_CheckType, MVT::i32,
/*38150*/     OPC_MoveParent,
/*38151*/     OPC_RecordChild5, // #4 = $srcw
/*38152*/     OPC_MoveChild, 5,
/*38154*/     OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*38157*/     OPC_CheckType, MVT::i32,
/*38159*/     OPC_MoveParent,
/*38160*/     OPC_RecordChild6, // #5 = $offsetx
/*38161*/     OPC_MoveChild, 6,
/*38163*/     OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*38166*/     OPC_CheckType, MVT::i32,
/*38168*/     OPC_MoveParent,
/*38169*/     OPC_RecordChild7, // #6 = $offsety
/*38170*/     OPC_MoveChild, 7,
/*38172*/     OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*38175*/     OPC_CheckType, MVT::i32,
/*38177*/     OPC_MoveParent,
/*38178*/     OPC_MoveChild, 8,
/*38180*/     OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*38183*/     OPC_RecordNode, // #7 = $offsetz
/*38184*/     OPC_CheckType, MVT::i32,
/*38186*/     OPC_MoveParent,
/*38187*/     OPC_MoveChild, 9,
/*38189*/     OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*38192*/     OPC_RecordNode, // #8 = $DST_SEL_X
/*38193*/     OPC_CheckType, MVT::i32,
/*38195*/     OPC_MoveParent,
/*38196*/     OPC_MoveChild, 10,
/*38198*/     OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*38201*/     OPC_RecordNode, // #9 = $DST_SEL_Y
/*38202*/     OPC_CheckType, MVT::i32,
/*38204*/     OPC_MoveParent,
/*38205*/     OPC_MoveChild, 11,
/*38207*/     OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*38210*/     OPC_RecordNode, // #10 = $DST_SEL_Z
/*38211*/     OPC_CheckType, MVT::i32,
/*38213*/     OPC_MoveParent,
/*38214*/     OPC_MoveChild, 12,
/*38216*/     OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*38219*/     OPC_RecordNode, // #11 = $DST_SEL_W
/*38220*/     OPC_CheckType, MVT::i32,
/*38222*/     OPC_MoveParent,
/*38223*/     OPC_MoveChild, 13,
/*38225*/     OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*38228*/     OPC_RecordNode, // #12 = $RESOURCE_ID
/*38229*/     OPC_CheckType, MVT::i32,
/*38231*/     OPC_MoveParent,
/*38232*/     OPC_MoveChild, 14,
/*38234*/     OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*38237*/     OPC_RecordNode, // #13 = $SAMPLER_ID
/*38238*/     OPC_CheckType, MVT::i32,
/*38240*/     OPC_MoveParent,
/*38241*/     OPC_MoveChild, 15,
/*38243*/     OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*38246*/     OPC_RecordNode, // #14 = $COORD_TYPE_X
/*38247*/     OPC_CheckType, MVT::i32,
/*38249*/     OPC_MoveParent,
/*38250*/     OPC_MoveChild, 16,
/*38252*/     OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*38255*/     OPC_RecordNode, // #15 = $COORD_TYPE_Y
/*38256*/     OPC_CheckType, MVT::i32,
/*38258*/     OPC_MoveParent,
/*38259*/     OPC_MoveChild, 17,
/*38261*/     OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*38264*/     OPC_RecordNode, // #16 = $COORD_TYPE_Z
/*38265*/     OPC_CheckType, MVT::i32,
/*38267*/     OPC_MoveParent,
/*38268*/     OPC_MoveChild, 18,
/*38270*/     OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*38273*/     OPC_RecordNode, // #17 = $COORD_TYPE_W
/*38274*/     OPC_CheckType, MVT::i32,
/*38276*/     OPC_MoveParent,
/*38277*/     OPC_CheckType, MVT::v4f32,
/*38279*/     OPC_CheckPatternPredicate, 3, // (Subtarget.getGeneration() <= AMDGPUSubtarget::NORTHERN_ISLANDS)
/*38281*/     OPC_EmitConvertToTarget, 1,
/*38283*/     OPC_EmitConvertToTarget, 2,
/*38285*/     OPC_EmitConvertToTarget, 3,
/*38287*/     OPC_EmitConvertToTarget, 4,
/*38289*/     OPC_EmitConvertToTarget, 5,
/*38291*/     OPC_EmitConvertToTarget, 6,
/*38293*/     OPC_EmitConvertToTarget, 7,
/*38295*/     OPC_EmitConvertToTarget, 8,
/*38297*/     OPC_EmitConvertToTarget, 9,
/*38299*/     OPC_EmitConvertToTarget, 10,
/*38301*/     OPC_EmitConvertToTarget, 11,
/*38303*/     OPC_EmitConvertToTarget, 12,
/*38305*/     OPC_EmitConvertToTarget, 13,
/*38307*/     OPC_EmitConvertToTarget, 14,
/*38309*/     OPC_EmitConvertToTarget, 15,
/*38311*/     OPC_EmitConvertToTarget, 16,
/*38313*/     OPC_EmitConvertToTarget, 17,
/*38315*/     OPC_MorphNodeTo, TARGET_VAL(AMDGPU::TEX_LD), 0,
                  1/*#VTs*/, MVT::v4f32, 18/*#Ops*/, 0, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 
              // Src: (TEXTURE_FETCH:v4f32 6:i32, v4i32:v4i32:$SRC_GPR, (imm:i32):$srcx, (imm:i32):$srcy, (imm:i32):$srcz, (imm:i32):$srcw, (imm:i32):$offsetx, (imm:i32):$offsety, (imm:i32):$offsetz, (imm:i32):$DST_SEL_X, (imm:i32):$DST_SEL_Y, (imm:i32):$DST_SEL_Z, (imm:i32):$DST_SEL_W, (imm:i32):$RESOURCE_ID, (imm:i32):$SAMPLER_ID, (imm:i32):$COORD_TYPE_X, (imm:i32):$COORD_TYPE_Y, (imm:i32):$COORD_TYPE_Z, (imm:i32):$COORD_TYPE_W) - Complexity = 59
              // Dst: (TEX_LD:v4f32 R600_Reg128:v4i32:$SRC_GPR, (imm:i32):$srcx, (imm:i32):$srcy, (imm:i32):$srcz, (imm:i32):$srcw, (imm:i32):$offsetx, (imm:i32):$offsety, (imm:i32):$offsetz, (imm:i32):$DST_SEL_X, (imm:i32):$DST_SEL_Y, (imm:i32):$DST_SEL_Z, (imm:i32):$DST_SEL_W, (imm:i32):$RESOURCE_ID, (imm:i32):$SAMPLER_ID, (imm:i32):$COORD_TYPE_X, (imm:i32):$COORD_TYPE_Y, (imm:i32):$COORD_TYPE_Z, (imm:i32):$COORD_TYPE_W)
/*38340*/   /*Scope*/ 94|128,1/*222*/, /*->38564*/
/*38342*/     OPC_CheckInteger, 7, 
/*38344*/     OPC_MoveParent,
/*38345*/     OPC_RecordChild1, // #0 = $SRC_GPR
/*38346*/     OPC_CheckChild1Type, MVT::v4i32,
/*38348*/     OPC_RecordChild2, // #1 = $srcx
/*38349*/     OPC_MoveChild, 2,
/*38351*/     OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*38354*/     OPC_CheckType, MVT::i32,
/*38356*/     OPC_MoveParent,
/*38357*/     OPC_RecordChild3, // #2 = $srcy
/*38358*/     OPC_MoveChild, 3,
/*38360*/     OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*38363*/     OPC_CheckType, MVT::i32,
/*38365*/     OPC_MoveParent,
/*38366*/     OPC_RecordChild4, // #3 = $srcz
/*38367*/     OPC_MoveChild, 4,
/*38369*/     OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*38372*/     OPC_CheckType, MVT::i32,
/*38374*/     OPC_MoveParent,
/*38375*/     OPC_RecordChild5, // #4 = $srcw
/*38376*/     OPC_MoveChild, 5,
/*38378*/     OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*38381*/     OPC_CheckType, MVT::i32,
/*38383*/     OPC_MoveParent,
/*38384*/     OPC_RecordChild6, // #5 = $offsetx
/*38385*/     OPC_MoveChild, 6,
/*38387*/     OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*38390*/     OPC_CheckType, MVT::i32,
/*38392*/     OPC_MoveParent,
/*38393*/     OPC_RecordChild7, // #6 = $offsety
/*38394*/     OPC_MoveChild, 7,
/*38396*/     OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*38399*/     OPC_CheckType, MVT::i32,
/*38401*/     OPC_MoveParent,
/*38402*/     OPC_MoveChild, 8,
/*38404*/     OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*38407*/     OPC_RecordNode, // #7 = $offsetz
/*38408*/     OPC_CheckType, MVT::i32,
/*38410*/     OPC_MoveParent,
/*38411*/     OPC_MoveChild, 9,
/*38413*/     OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*38416*/     OPC_RecordNode, // #8 = $DST_SEL_X
/*38417*/     OPC_CheckType, MVT::i32,
/*38419*/     OPC_MoveParent,
/*38420*/     OPC_MoveChild, 10,
/*38422*/     OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*38425*/     OPC_RecordNode, // #9 = $DST_SEL_Y
/*38426*/     OPC_CheckType, MVT::i32,
/*38428*/     OPC_MoveParent,
/*38429*/     OPC_MoveChild, 11,
/*38431*/     OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*38434*/     OPC_RecordNode, // #10 = $DST_SEL_Z
/*38435*/     OPC_CheckType, MVT::i32,
/*38437*/     OPC_MoveParent,
/*38438*/     OPC_MoveChild, 12,
/*38440*/     OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*38443*/     OPC_RecordNode, // #11 = $DST_SEL_W
/*38444*/     OPC_CheckType, MVT::i32,
/*38446*/     OPC_MoveParent,
/*38447*/     OPC_MoveChild, 13,
/*38449*/     OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*38452*/     OPC_RecordNode, // #12 = $RESOURCE_ID
/*38453*/     OPC_CheckType, MVT::i32,
/*38455*/     OPC_MoveParent,
/*38456*/     OPC_MoveChild, 14,
/*38458*/     OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*38461*/     OPC_RecordNode, // #13 = $SAMPLER_ID
/*38462*/     OPC_CheckType, MVT::i32,
/*38464*/     OPC_MoveParent,
/*38465*/     OPC_MoveChild, 15,
/*38467*/     OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*38470*/     OPC_RecordNode, // #14 = $COORD_TYPE_X
/*38471*/     OPC_CheckType, MVT::i32,
/*38473*/     OPC_MoveParent,
/*38474*/     OPC_MoveChild, 16,
/*38476*/     OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*38479*/     OPC_RecordNode, // #15 = $COORD_TYPE_Y
/*38480*/     OPC_CheckType, MVT::i32,
/*38482*/     OPC_MoveParent,
/*38483*/     OPC_MoveChild, 17,
/*38485*/     OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*38488*/     OPC_RecordNode, // #16 = $COORD_TYPE_Z
/*38489*/     OPC_CheckType, MVT::i32,
/*38491*/     OPC_MoveParent,
/*38492*/     OPC_MoveChild, 18,
/*38494*/     OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*38497*/     OPC_RecordNode, // #17 = $COORD_TYPE_W
/*38498*/     OPC_CheckType, MVT::i32,
/*38500*/     OPC_MoveParent,
/*38501*/     OPC_CheckType, MVT::v4f32,
/*38503*/     OPC_CheckPatternPredicate, 3, // (Subtarget.getGeneration() <= AMDGPUSubtarget::NORTHERN_ISLANDS)
/*38505*/     OPC_EmitConvertToTarget, 1,
/*38507*/     OPC_EmitConvertToTarget, 2,
/*38509*/     OPC_EmitConvertToTarget, 3,
/*38511*/     OPC_EmitConvertToTarget, 4,
/*38513*/     OPC_EmitConvertToTarget, 5,
/*38515*/     OPC_EmitConvertToTarget, 6,
/*38517*/     OPC_EmitConvertToTarget, 7,
/*38519*/     OPC_EmitConvertToTarget, 8,
/*38521*/     OPC_EmitConvertToTarget, 9,
/*38523*/     OPC_EmitConvertToTarget, 10,
/*38525*/     OPC_EmitConvertToTarget, 11,
/*38527*/     OPC_EmitConvertToTarget, 12,
/*38529*/     OPC_EmitConvertToTarget, 13,
/*38531*/     OPC_EmitConvertToTarget, 14,
/*38533*/     OPC_EmitConvertToTarget, 15,
/*38535*/     OPC_EmitConvertToTarget, 16,
/*38537*/     OPC_EmitConvertToTarget, 17,
/*38539*/     OPC_MorphNodeTo, TARGET_VAL(AMDGPU::TEX_GET_TEXTURE_RESINFO), 0,
                  1/*#VTs*/, MVT::v4f32, 18/*#Ops*/, 0, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 
              // Src: (TEXTURE_FETCH:v4f32 7:i32, v4i32:v4i32:$SRC_GPR, (imm:i32):$srcx, (imm:i32):$srcy, (imm:i32):$srcz, (imm:i32):$srcw, (imm:i32):$offsetx, (imm:i32):$offsety, (imm:i32):$offsetz, (imm:i32):$DST_SEL_X, (imm:i32):$DST_SEL_Y, (imm:i32):$DST_SEL_Z, (imm:i32):$DST_SEL_W, (imm:i32):$RESOURCE_ID, (imm:i32):$SAMPLER_ID, (imm:i32):$COORD_TYPE_X, (imm:i32):$COORD_TYPE_Y, (imm:i32):$COORD_TYPE_Z, (imm:i32):$COORD_TYPE_W) - Complexity = 59
              // Dst: (TEX_GET_TEXTURE_RESINFO:v4f32 R600_Reg128:v4i32:$SRC_GPR, (imm:i32):$srcx, (imm:i32):$srcy, (imm:i32):$srcz, (imm:i32):$srcw, (imm:i32):$offsetx, (imm:i32):$offsety, (imm:i32):$offsetz, (imm:i32):$DST_SEL_X, (imm:i32):$DST_SEL_Y, (imm:i32):$DST_SEL_Z, (imm:i32):$DST_SEL_W, (imm:i32):$RESOURCE_ID, (imm:i32):$SAMPLER_ID, (imm:i32):$COORD_TYPE_X, (imm:i32):$COORD_TYPE_Y, (imm:i32):$COORD_TYPE_Z, (imm:i32):$COORD_TYPE_W)
/*38564*/   /*Scope*/ 94|128,1/*222*/, /*->38788*/
/*38566*/     OPC_CheckInteger, 8, 
/*38568*/     OPC_MoveParent,
/*38569*/     OPC_RecordChild1, // #0 = $SRC_GPR
/*38570*/     OPC_CheckChild1Type, MVT::v4f32,
/*38572*/     OPC_RecordChild2, // #1 = $srcx
/*38573*/     OPC_MoveChild, 2,
/*38575*/     OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*38578*/     OPC_CheckType, MVT::i32,
/*38580*/     OPC_MoveParent,
/*38581*/     OPC_RecordChild3, // #2 = $srcy
/*38582*/     OPC_MoveChild, 3,
/*38584*/     OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*38587*/     OPC_CheckType, MVT::i32,
/*38589*/     OPC_MoveParent,
/*38590*/     OPC_RecordChild4, // #3 = $srcz
/*38591*/     OPC_MoveChild, 4,
/*38593*/     OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*38596*/     OPC_CheckType, MVT::i32,
/*38598*/     OPC_MoveParent,
/*38599*/     OPC_RecordChild5, // #4 = $srcw
/*38600*/     OPC_MoveChild, 5,
/*38602*/     OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*38605*/     OPC_CheckType, MVT::i32,
/*38607*/     OPC_MoveParent,
/*38608*/     OPC_RecordChild6, // #5 = $offsetx
/*38609*/     OPC_MoveChild, 6,
/*38611*/     OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*38614*/     OPC_CheckType, MVT::i32,
/*38616*/     OPC_MoveParent,
/*38617*/     OPC_RecordChild7, // #6 = $offsety
/*38618*/     OPC_MoveChild, 7,
/*38620*/     OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*38623*/     OPC_CheckType, MVT::i32,
/*38625*/     OPC_MoveParent,
/*38626*/     OPC_MoveChild, 8,
/*38628*/     OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*38631*/     OPC_RecordNode, // #7 = $offsetz
/*38632*/     OPC_CheckType, MVT::i32,
/*38634*/     OPC_MoveParent,
/*38635*/     OPC_MoveChild, 9,
/*38637*/     OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*38640*/     OPC_RecordNode, // #8 = $DST_SEL_X
/*38641*/     OPC_CheckType, MVT::i32,
/*38643*/     OPC_MoveParent,
/*38644*/     OPC_MoveChild, 10,
/*38646*/     OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*38649*/     OPC_RecordNode, // #9 = $DST_SEL_Y
/*38650*/     OPC_CheckType, MVT::i32,
/*38652*/     OPC_MoveParent,
/*38653*/     OPC_MoveChild, 11,
/*38655*/     OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*38658*/     OPC_RecordNode, // #10 = $DST_SEL_Z
/*38659*/     OPC_CheckType, MVT::i32,
/*38661*/     OPC_MoveParent,
/*38662*/     OPC_MoveChild, 12,
/*38664*/     OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*38667*/     OPC_RecordNode, // #11 = $DST_SEL_W
/*38668*/     OPC_CheckType, MVT::i32,
/*38670*/     OPC_MoveParent,
/*38671*/     OPC_MoveChild, 13,
/*38673*/     OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*38676*/     OPC_RecordNode, // #12 = $RESOURCE_ID
/*38677*/     OPC_CheckType, MVT::i32,
/*38679*/     OPC_MoveParent,
/*38680*/     OPC_MoveChild, 14,
/*38682*/     OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*38685*/     OPC_RecordNode, // #13 = $SAMPLER_ID
/*38686*/     OPC_CheckType, MVT::i32,
/*38688*/     OPC_MoveParent,
/*38689*/     OPC_MoveChild, 15,
/*38691*/     OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*38694*/     OPC_RecordNode, // #14 = $COORD_TYPE_X
/*38695*/     OPC_CheckType, MVT::i32,
/*38697*/     OPC_MoveParent,
/*38698*/     OPC_MoveChild, 16,
/*38700*/     OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*38703*/     OPC_RecordNode, // #15 = $COORD_TYPE_Y
/*38704*/     OPC_CheckType, MVT::i32,
/*38706*/     OPC_MoveParent,
/*38707*/     OPC_MoveChild, 17,
/*38709*/     OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*38712*/     OPC_RecordNode, // #16 = $COORD_TYPE_Z
/*38713*/     OPC_CheckType, MVT::i32,
/*38715*/     OPC_MoveParent,
/*38716*/     OPC_MoveChild, 18,
/*38718*/     OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*38721*/     OPC_RecordNode, // #17 = $COORD_TYPE_W
/*38722*/     OPC_CheckType, MVT::i32,
/*38724*/     OPC_MoveParent,
/*38725*/     OPC_CheckType, MVT::v4f32,
/*38727*/     OPC_CheckPatternPredicate, 3, // (Subtarget.getGeneration() <= AMDGPUSubtarget::NORTHERN_ISLANDS)
/*38729*/     OPC_EmitConvertToTarget, 1,
/*38731*/     OPC_EmitConvertToTarget, 2,
/*38733*/     OPC_EmitConvertToTarget, 3,
/*38735*/     OPC_EmitConvertToTarget, 4,
/*38737*/     OPC_EmitConvertToTarget, 5,
/*38739*/     OPC_EmitConvertToTarget, 6,
/*38741*/     OPC_EmitConvertToTarget, 7,
/*38743*/     OPC_EmitConvertToTarget, 8,
/*38745*/     OPC_EmitConvertToTarget, 9,
/*38747*/     OPC_EmitConvertToTarget, 10,
/*38749*/     OPC_EmitConvertToTarget, 11,
/*38751*/     OPC_EmitConvertToTarget, 12,
/*38753*/     OPC_EmitConvertToTarget, 13,
/*38755*/     OPC_EmitConvertToTarget, 14,
/*38757*/     OPC_EmitConvertToTarget, 15,
/*38759*/     OPC_EmitConvertToTarget, 16,
/*38761*/     OPC_EmitConvertToTarget, 17,
/*38763*/     OPC_MorphNodeTo, TARGET_VAL(AMDGPU::TEX_GET_GRADIENTS_H), 0,
                  1/*#VTs*/, MVT::v4f32, 18/*#Ops*/, 0, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 
              // Src: (TEXTURE_FETCH:v4f32 8:i32, v4f32:v4f32:$SRC_GPR, (imm:i32):$srcx, (imm:i32):$srcy, (imm:i32):$srcz, (imm:i32):$srcw, (imm:i32):$offsetx, (imm:i32):$offsety, (imm:i32):$offsetz, (imm:i32):$DST_SEL_X, (imm:i32):$DST_SEL_Y, (imm:i32):$DST_SEL_Z, (imm:i32):$DST_SEL_W, (imm:i32):$RESOURCE_ID, (imm:i32):$SAMPLER_ID, (imm:i32):$COORD_TYPE_X, (imm:i32):$COORD_TYPE_Y, (imm:i32):$COORD_TYPE_Z, (imm:i32):$COORD_TYPE_W) - Complexity = 59
              // Dst: (TEX_GET_GRADIENTS_H:v4f32 R600_Reg128:v4f32:$SRC_GPR, (imm:i32):$srcx, (imm:i32):$srcy, (imm:i32):$srcz, (imm:i32):$srcw, (imm:i32):$offsetx, (imm:i32):$offsety, (imm:i32):$offsetz, (imm:i32):$DST_SEL_X, (imm:i32):$DST_SEL_Y, (imm:i32):$DST_SEL_Z, (imm:i32):$DST_SEL_W, (imm:i32):$RESOURCE_ID, (imm:i32):$SAMPLER_ID, (imm:i32):$COORD_TYPE_X, (imm:i32):$COORD_TYPE_Y, (imm:i32):$COORD_TYPE_Z, (imm:i32):$COORD_TYPE_W)
/*38788*/   /*Scope*/ 94|128,1/*222*/, /*->39012*/
/*38790*/     OPC_CheckInteger, 9, 
/*38792*/     OPC_MoveParent,
/*38793*/     OPC_RecordChild1, // #0 = $SRC_GPR
/*38794*/     OPC_CheckChild1Type, MVT::v4f32,
/*38796*/     OPC_RecordChild2, // #1 = $srcx
/*38797*/     OPC_MoveChild, 2,
/*38799*/     OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*38802*/     OPC_CheckType, MVT::i32,
/*38804*/     OPC_MoveParent,
/*38805*/     OPC_RecordChild3, // #2 = $srcy
/*38806*/     OPC_MoveChild, 3,
/*38808*/     OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*38811*/     OPC_CheckType, MVT::i32,
/*38813*/     OPC_MoveParent,
/*38814*/     OPC_RecordChild4, // #3 = $srcz
/*38815*/     OPC_MoveChild, 4,
/*38817*/     OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*38820*/     OPC_CheckType, MVT::i32,
/*38822*/     OPC_MoveParent,
/*38823*/     OPC_RecordChild5, // #4 = $srcw
/*38824*/     OPC_MoveChild, 5,
/*38826*/     OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*38829*/     OPC_CheckType, MVT::i32,
/*38831*/     OPC_MoveParent,
/*38832*/     OPC_RecordChild6, // #5 = $offsetx
/*38833*/     OPC_MoveChild, 6,
/*38835*/     OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*38838*/     OPC_CheckType, MVT::i32,
/*38840*/     OPC_MoveParent,
/*38841*/     OPC_RecordChild7, // #6 = $offsety
/*38842*/     OPC_MoveChild, 7,
/*38844*/     OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*38847*/     OPC_CheckType, MVT::i32,
/*38849*/     OPC_MoveParent,
/*38850*/     OPC_MoveChild, 8,
/*38852*/     OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*38855*/     OPC_RecordNode, // #7 = $offsetz
/*38856*/     OPC_CheckType, MVT::i32,
/*38858*/     OPC_MoveParent,
/*38859*/     OPC_MoveChild, 9,
/*38861*/     OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*38864*/     OPC_RecordNode, // #8 = $DST_SEL_X
/*38865*/     OPC_CheckType, MVT::i32,
/*38867*/     OPC_MoveParent,
/*38868*/     OPC_MoveChild, 10,
/*38870*/     OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*38873*/     OPC_RecordNode, // #9 = $DST_SEL_Y
/*38874*/     OPC_CheckType, MVT::i32,
/*38876*/     OPC_MoveParent,
/*38877*/     OPC_MoveChild, 11,
/*38879*/     OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*38882*/     OPC_RecordNode, // #10 = $DST_SEL_Z
/*38883*/     OPC_CheckType, MVT::i32,
/*38885*/     OPC_MoveParent,
/*38886*/     OPC_MoveChild, 12,
/*38888*/     OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*38891*/     OPC_RecordNode, // #11 = $DST_SEL_W
/*38892*/     OPC_CheckType, MVT::i32,
/*38894*/     OPC_MoveParent,
/*38895*/     OPC_MoveChild, 13,
/*38897*/     OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*38900*/     OPC_RecordNode, // #12 = $RESOURCE_ID
/*38901*/     OPC_CheckType, MVT::i32,
/*38903*/     OPC_MoveParent,
/*38904*/     OPC_MoveChild, 14,
/*38906*/     OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*38909*/     OPC_RecordNode, // #13 = $SAMPLER_ID
/*38910*/     OPC_CheckType, MVT::i32,
/*38912*/     OPC_MoveParent,
/*38913*/     OPC_MoveChild, 15,
/*38915*/     OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*38918*/     OPC_RecordNode, // #14 = $COORD_TYPE_X
/*38919*/     OPC_CheckType, MVT::i32,
/*38921*/     OPC_MoveParent,
/*38922*/     OPC_MoveChild, 16,
/*38924*/     OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*38927*/     OPC_RecordNode, // #15 = $COORD_TYPE_Y
/*38928*/     OPC_CheckType, MVT::i32,
/*38930*/     OPC_MoveParent,
/*38931*/     OPC_MoveChild, 17,
/*38933*/     OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*38936*/     OPC_RecordNode, // #16 = $COORD_TYPE_Z
/*38937*/     OPC_CheckType, MVT::i32,
/*38939*/     OPC_MoveParent,
/*38940*/     OPC_MoveChild, 18,
/*38942*/     OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*38945*/     OPC_RecordNode, // #17 = $COORD_TYPE_W
/*38946*/     OPC_CheckType, MVT::i32,
/*38948*/     OPC_MoveParent,
/*38949*/     OPC_CheckType, MVT::v4f32,
/*38951*/     OPC_CheckPatternPredicate, 3, // (Subtarget.getGeneration() <= AMDGPUSubtarget::NORTHERN_ISLANDS)
/*38953*/     OPC_EmitConvertToTarget, 1,
/*38955*/     OPC_EmitConvertToTarget, 2,
/*38957*/     OPC_EmitConvertToTarget, 3,
/*38959*/     OPC_EmitConvertToTarget, 4,
/*38961*/     OPC_EmitConvertToTarget, 5,
/*38963*/     OPC_EmitConvertToTarget, 6,
/*38965*/     OPC_EmitConvertToTarget, 7,
/*38967*/     OPC_EmitConvertToTarget, 8,
/*38969*/     OPC_EmitConvertToTarget, 9,
/*38971*/     OPC_EmitConvertToTarget, 10,
/*38973*/     OPC_EmitConvertToTarget, 11,
/*38975*/     OPC_EmitConvertToTarget, 12,
/*38977*/     OPC_EmitConvertToTarget, 13,
/*38979*/     OPC_EmitConvertToTarget, 14,
/*38981*/     OPC_EmitConvertToTarget, 15,
/*38983*/     OPC_EmitConvertToTarget, 16,
/*38985*/     OPC_EmitConvertToTarget, 17,
/*38987*/     OPC_MorphNodeTo, TARGET_VAL(AMDGPU::TEX_GET_GRADIENTS_V), 0,
                  1/*#VTs*/, MVT::v4f32, 18/*#Ops*/, 0, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 
              // Src: (TEXTURE_FETCH:v4f32 9:i32, v4f32:v4f32:$SRC_GPR, (imm:i32):$srcx, (imm:i32):$srcy, (imm:i32):$srcz, (imm:i32):$srcw, (imm:i32):$offsetx, (imm:i32):$offsety, (imm:i32):$offsetz, (imm:i32):$DST_SEL_X, (imm:i32):$DST_SEL_Y, (imm:i32):$DST_SEL_Z, (imm:i32):$DST_SEL_W, (imm:i32):$RESOURCE_ID, (imm:i32):$SAMPLER_ID, (imm:i32):$COORD_TYPE_X, (imm:i32):$COORD_TYPE_Y, (imm:i32):$COORD_TYPE_Z, (imm:i32):$COORD_TYPE_W) - Complexity = 59
              // Dst: (TEX_GET_GRADIENTS_V:v4f32 R600_Reg128:v4f32:$SRC_GPR, (imm:i32):$srcx, (imm:i32):$srcy, (imm:i32):$srcz, (imm:i32):$srcw, (imm:i32):$offsetx, (imm:i32):$offsety, (imm:i32):$offsetz, (imm:i32):$DST_SEL_X, (imm:i32):$DST_SEL_Y, (imm:i32):$DST_SEL_Z, (imm:i32):$DST_SEL_W, (imm:i32):$RESOURCE_ID, (imm:i32):$SAMPLER_ID, (imm:i32):$COORD_TYPE_X, (imm:i32):$COORD_TYPE_Y, (imm:i32):$COORD_TYPE_Z, (imm:i32):$COORD_TYPE_W)
/*39012*/   /*Scope*/ 94|128,1/*222*/, /*->39236*/
/*39014*/     OPC_CheckInteger, 10, 
/*39016*/     OPC_MoveParent,
/*39017*/     OPC_RecordChild1, // #0 = $SRC_GPR
/*39018*/     OPC_CheckChild1Type, MVT::v4i32,
/*39020*/     OPC_RecordChild2, // #1 = $srcx
/*39021*/     OPC_MoveChild, 2,
/*39023*/     OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*39026*/     OPC_CheckType, MVT::i32,
/*39028*/     OPC_MoveParent,
/*39029*/     OPC_RecordChild3, // #2 = $srcy
/*39030*/     OPC_MoveChild, 3,
/*39032*/     OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*39035*/     OPC_CheckType, MVT::i32,
/*39037*/     OPC_MoveParent,
/*39038*/     OPC_RecordChild4, // #3 = $srcz
/*39039*/     OPC_MoveChild, 4,
/*39041*/     OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*39044*/     OPC_CheckType, MVT::i32,
/*39046*/     OPC_MoveParent,
/*39047*/     OPC_RecordChild5, // #4 = $srcw
/*39048*/     OPC_MoveChild, 5,
/*39050*/     OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*39053*/     OPC_CheckType, MVT::i32,
/*39055*/     OPC_MoveParent,
/*39056*/     OPC_RecordChild6, // #5 = $offsetx
/*39057*/     OPC_MoveChild, 6,
/*39059*/     OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*39062*/     OPC_CheckType, MVT::i32,
/*39064*/     OPC_MoveParent,
/*39065*/     OPC_RecordChild7, // #6 = $offsety
/*39066*/     OPC_MoveChild, 7,
/*39068*/     OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*39071*/     OPC_CheckType, MVT::i32,
/*39073*/     OPC_MoveParent,
/*39074*/     OPC_MoveChild, 8,
/*39076*/     OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*39079*/     OPC_RecordNode, // #7 = $offsetz
/*39080*/     OPC_CheckType, MVT::i32,
/*39082*/     OPC_MoveParent,
/*39083*/     OPC_MoveChild, 9,
/*39085*/     OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*39088*/     OPC_RecordNode, // #8 = $DST_SEL_X
/*39089*/     OPC_CheckType, MVT::i32,
/*39091*/     OPC_MoveParent,
/*39092*/     OPC_MoveChild, 10,
/*39094*/     OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*39097*/     OPC_RecordNode, // #9 = $DST_SEL_Y
/*39098*/     OPC_CheckType, MVT::i32,
/*39100*/     OPC_MoveParent,
/*39101*/     OPC_MoveChild, 11,
/*39103*/     OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*39106*/     OPC_RecordNode, // #10 = $DST_SEL_Z
/*39107*/     OPC_CheckType, MVT::i32,
/*39109*/     OPC_MoveParent,
/*39110*/     OPC_MoveChild, 12,
/*39112*/     OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*39115*/     OPC_RecordNode, // #11 = $DST_SEL_W
/*39116*/     OPC_CheckType, MVT::i32,
/*39118*/     OPC_MoveParent,
/*39119*/     OPC_MoveChild, 13,
/*39121*/     OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*39124*/     OPC_RecordNode, // #12 = $RESOURCE_ID
/*39125*/     OPC_CheckType, MVT::i32,
/*39127*/     OPC_MoveParent,
/*39128*/     OPC_MoveChild, 14,
/*39130*/     OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*39133*/     OPC_RecordNode, // #13 = $SAMPLER_ID
/*39134*/     OPC_CheckType, MVT::i32,
/*39136*/     OPC_MoveParent,
/*39137*/     OPC_MoveChild, 15,
/*39139*/     OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*39142*/     OPC_RecordNode, // #14 = $COORD_TYPE_X
/*39143*/     OPC_CheckType, MVT::i32,
/*39145*/     OPC_MoveParent,
/*39146*/     OPC_MoveChild, 16,
/*39148*/     OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*39151*/     OPC_RecordNode, // #15 = $COORD_TYPE_Y
/*39152*/     OPC_CheckType, MVT::i32,
/*39154*/     OPC_MoveParent,
/*39155*/     OPC_MoveChild, 17,
/*39157*/     OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*39160*/     OPC_RecordNode, // #16 = $COORD_TYPE_Z
/*39161*/     OPC_CheckType, MVT::i32,
/*39163*/     OPC_MoveParent,
/*39164*/     OPC_MoveChild, 18,
/*39166*/     OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*39169*/     OPC_RecordNode, // #17 = $COORD_TYPE_W
/*39170*/     OPC_CheckType, MVT::i32,
/*39172*/     OPC_MoveParent,
/*39173*/     OPC_CheckType, MVT::v4f32,
/*39175*/     OPC_CheckPatternPredicate, 3, // (Subtarget.getGeneration() <= AMDGPUSubtarget::NORTHERN_ISLANDS)
/*39177*/     OPC_EmitConvertToTarget, 1,
/*39179*/     OPC_EmitConvertToTarget, 2,
/*39181*/     OPC_EmitConvertToTarget, 3,
/*39183*/     OPC_EmitConvertToTarget, 4,
/*39185*/     OPC_EmitConvertToTarget, 5,
/*39187*/     OPC_EmitConvertToTarget, 6,
/*39189*/     OPC_EmitConvertToTarget, 7,
/*39191*/     OPC_EmitConvertToTarget, 8,
/*39193*/     OPC_EmitConvertToTarget, 9,
/*39195*/     OPC_EmitConvertToTarget, 10,
/*39197*/     OPC_EmitConvertToTarget, 11,
/*39199*/     OPC_EmitConvertToTarget, 12,
/*39201*/     OPC_EmitConvertToTarget, 13,
/*39203*/     OPC_EmitConvertToTarget, 14,
/*39205*/     OPC_EmitConvertToTarget, 15,
/*39207*/     OPC_EmitConvertToTarget, 16,
/*39209*/     OPC_EmitConvertToTarget, 17,
/*39211*/     OPC_MorphNodeTo, TARGET_VAL(AMDGPU::TEX_LDPTR), 0,
                  1/*#VTs*/, MVT::v4f32, 18/*#Ops*/, 0, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 
              // Src: (TEXTURE_FETCH:v4f32 10:i32, v4i32:v4i32:$SRC_GPR, (imm:i32):$srcx, (imm:i32):$srcy, (imm:i32):$srcz, (imm:i32):$srcw, (imm:i32):$offsetx, (imm:i32):$offsety, (imm:i32):$offsetz, (imm:i32):$DST_SEL_X, (imm:i32):$DST_SEL_Y, (imm:i32):$DST_SEL_Z, (imm:i32):$DST_SEL_W, (imm:i32):$RESOURCE_ID, (imm:i32):$SAMPLER_ID, (imm:i32):$COORD_TYPE_X, (imm:i32):$COORD_TYPE_Y, (imm:i32):$COORD_TYPE_Z, (imm:i32):$COORD_TYPE_W) - Complexity = 59
              // Dst: (TEX_LDPTR:v4f32 R600_Reg128:v4i32:$SRC_GPR, (imm:i32):$srcx, (imm:i32):$srcy, (imm:i32):$srcz, (imm:i32):$srcw, (imm:i32):$offsetx, (imm:i32):$offsety, (imm:i32):$offsetz, (imm:i32):$DST_SEL_X, (imm:i32):$DST_SEL_Y, (imm:i32):$DST_SEL_Z, (imm:i32):$DST_SEL_W, (imm:i32):$RESOURCE_ID, (imm:i32):$SAMPLER_ID, (imm:i32):$COORD_TYPE_X, (imm:i32):$COORD_TYPE_Y, (imm:i32):$COORD_TYPE_Z, (imm:i32):$COORD_TYPE_W)
/*39236*/   0, /*End of Scope*/
/*39237*/ /*SwitchOpcode*/ 25,  TARGET_VAL(AMDGPUISD::LOAD_INPUT),// ->39265
/*39240*/   OPC_RecordChild0, // #0 = $tlst
/*39241*/   OPC_RecordChild1, // #1 = $attr_offset
/*39242*/   OPC_MoveChild, 1,
/*39244*/   OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*39247*/   OPC_CheckPredicate, 24, // Predicate_IMM12bit
/*39249*/   OPC_MoveParent,
/*39250*/   OPC_RecordChild2, // #2 = $buf_idx_vgpr
/*39251*/   OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*39253*/   OPC_EmitConvertToTarget, 1,
/*39255*/   OPC_MorphNodeTo, TARGET_VAL(AMDGPU::BUFFER_LOAD_FORMAT_XYZW_IDXEN), 0,
                1/*#VTs*/, MVT::v4f32, 3/*#Ops*/, 0, 2, 3, 
            // Src: (SIload_input:v4f32 i128:i128:$tlst, (imm:i16)<<P:Predicate_IMM12bit>>:$attr_offset, i32:i32:$buf_idx_vgpr) - Complexity = 7
            // Dst: (BUFFER_LOAD_FORMAT_XYZW_IDXEN:v4f32 ?:i128:$tlst, ?:i32:$buf_idx_vgpr, (imm:i16):$attr_offset)
/*39265*/ /*SwitchOpcode*/ 38|128,8/*1062*/,  TARGET_VAL(AMDGPUISD::SAMPLE),// ->40331
/*39269*/   OPC_RecordChild0, // #0 = $addr
/*39270*/   OPC_Scope, 121|128,1/*249*/, /*->39522*/ // 5 children in Scope
/*39273*/     OPC_CheckChild0Type, MVT::v2i32,
/*39275*/     OPC_RecordChild1, // #1 = $rsrc
/*39276*/     OPC_RecordChild2, // #2 = $sampler
/*39277*/     OPC_MoveChild, 3,
/*39279*/     OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*39282*/     OPC_Scope, 47, /*->39331*/ // 5 children in Scope
/*39284*/       OPC_CheckPredicate, 74, // Predicate_TEX_RECT
/*39286*/       OPC_MoveParent,
/*39287*/       OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*39289*/       OPC_EmitInteger, MVT::i32, 15, 
/*39292*/       OPC_EmitInteger, MVT::i1, 1, 
/*39295*/       OPC_EmitInteger, MVT::i1, 0, 
/*39298*/       OPC_EmitInteger, MVT::i1, 0, 
/*39301*/       OPC_EmitInteger, MVT::i1, 0, 
/*39304*/       OPC_EmitInteger, MVT::i1, 0, 
/*39307*/       OPC_EmitInteger, MVT::i1, 0, 
/*39310*/       OPC_EmitInteger, MVT::i1, 0, 
/*39313*/       OPC_MorphNodeTo, TARGET_VAL(AMDGPU::IMAGE_SAMPLE_V4_V2), 0,
                    1/*#VTs*/, MVT::v4f32, 11/*#Ops*/, 3, 4, 5, 6, 7, 8, 9, 10, 0, 1, 2, 
                // Src: (SIsample:v4f32 v2i32:v2i32:$addr, v32i8:v32i8:$rsrc, i128:i128:$sampler, (imm:i32)<<P:Predicate_TEX_RECT>>) - Complexity = 7
                // Dst: (IMAGE_SAMPLE_V4_V2:v4f32 15:i32, 1:i1, 0:i1, 0:i1, 0:i1, 0:i1, 0:i1, 0:i1, ?:v2i32:$addr, ?:v32i8:$rsrc, ?:i128:$sampler)
/*39331*/     /*Scope*/ 47, /*->39379*/
/*39332*/       OPC_CheckPredicate, 42, // Predicate_TEX_ARRAY
/*39334*/       OPC_MoveParent,
/*39335*/       OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*39337*/       OPC_EmitInteger, MVT::i32, 15, 
/*39340*/       OPC_EmitInteger, MVT::i1, 0, 
/*39343*/       OPC_EmitInteger, MVT::i1, 0, 
/*39346*/       OPC_EmitInteger, MVT::i1, 1, 
/*39349*/       OPC_EmitInteger, MVT::i1, 0, 
/*39352*/       OPC_EmitInteger, MVT::i1, 0, 
/*39355*/       OPC_EmitInteger, MVT::i1, 0, 
/*39358*/       OPC_EmitInteger, MVT::i1, 0, 
/*39361*/       OPC_MorphNodeTo, TARGET_VAL(AMDGPU::IMAGE_SAMPLE_V4_V2), 0,
                    1/*#VTs*/, MVT::v4f32, 11/*#Ops*/, 3, 4, 5, 6, 7, 8, 9, 10, 0, 1, 2, 
                // Src: (SIsample:v4f32 v2i32:v2i32:$addr, v32i8:v32i8:$rsrc, i128:i128:$sampler, (imm:i32)<<P:Predicate_TEX_ARRAY>>) - Complexity = 7
                // Dst: (IMAGE_SAMPLE_V4_V2:v4f32 15:i32, 0:i1, 0:i1, 1:i1, 0:i1, 0:i1, 0:i1, 0:i1, ?:v2i32:$addr, ?:v32i8:$rsrc, ?:i128:$sampler)
/*39379*/     /*Scope*/ 47, /*->39427*/
/*39380*/       OPC_CheckPredicate, 45, // Predicate_TEX_SHADOW
/*39382*/       OPC_MoveParent,
/*39383*/       OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*39385*/       OPC_EmitInteger, MVT::i32, 15, 
/*39388*/       OPC_EmitInteger, MVT::i1, 0, 
/*39391*/       OPC_EmitInteger, MVT::i1, 0, 
/*39394*/       OPC_EmitInteger, MVT::i1, 0, 
/*39397*/       OPC_EmitInteger, MVT::i1, 0, 
/*39400*/       OPC_EmitInteger, MVT::i1, 0, 
/*39403*/       OPC_EmitInteger, MVT::i1, 0, 
/*39406*/       OPC_EmitInteger, MVT::i1, 0, 
/*39409*/       OPC_MorphNodeTo, TARGET_VAL(AMDGPU::IMAGE_SAMPLE_C_V4_V2), 0,
                    1/*#VTs*/, MVT::v4f32, 11/*#Ops*/, 3, 4, 5, 6, 7, 8, 9, 10, 0, 1, 2, 
                // Src: (SIsample:v4f32 v2i32:v2i32:$addr, v32i8:v32i8:$rsrc, i128:i128:$sampler, (imm:i32)<<P:Predicate_TEX_SHADOW>>) - Complexity = 7
                // Dst: (IMAGE_SAMPLE_C_V4_V2:v4f32 15:i32, 0:i1, 0:i1, 0:i1, 0:i1, 0:i1, 0:i1, 0:i1, ?:v2i32:$addr, ?:v32i8:$rsrc, ?:i128:$sampler)
/*39427*/     /*Scope*/ 47, /*->39475*/
/*39428*/       OPC_CheckPredicate, 75, // Predicate_TEX_SHADOW_ARRAY
/*39430*/       OPC_MoveParent,
/*39431*/       OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*39433*/       OPC_EmitInteger, MVT::i32, 15, 
/*39436*/       OPC_EmitInteger, MVT::i1, 0, 
/*39439*/       OPC_EmitInteger, MVT::i1, 0, 
/*39442*/       OPC_EmitInteger, MVT::i1, 1, 
/*39445*/       OPC_EmitInteger, MVT::i1, 0, 
/*39448*/       OPC_EmitInteger, MVT::i1, 0, 
/*39451*/       OPC_EmitInteger, MVT::i1, 0, 
/*39454*/       OPC_EmitInteger, MVT::i1, 0, 
/*39457*/       OPC_MorphNodeTo, TARGET_VAL(AMDGPU::IMAGE_SAMPLE_C_V4_V2), 0,
                    1/*#VTs*/, MVT::v4f32, 11/*#Ops*/, 3, 4, 5, 6, 7, 8, 9, 10, 0, 1, 2, 
                // Src: (SIsample:v4f32 v2i32:v2i32:$addr, v32i8:v32i8:$rsrc, i128:i128:$sampler, (imm:i32)<<P:Predicate_TEX_SHADOW_ARRAY>>) - Complexity = 7
                // Dst: (IMAGE_SAMPLE_C_V4_V2:v4f32 15:i32, 0:i1, 0:i1, 1:i1, 0:i1, 0:i1, 0:i1, 0:i1, ?:v2i32:$addr, ?:v32i8:$rsrc, ?:i128:$sampler)
/*39475*/     /*Scope*/ 45, /*->39521*/
/*39476*/       OPC_MoveParent,
/*39477*/       OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*39479*/       OPC_EmitInteger, MVT::i32, 15, 
/*39482*/       OPC_EmitInteger, MVT::i1, 0, 
/*39485*/       OPC_EmitInteger, MVT::i1, 0, 
/*39488*/       OPC_EmitInteger, MVT::i1, 0, 
/*39491*/       OPC_EmitInteger, MVT::i1, 0, 
/*39494*/       OPC_EmitInteger, MVT::i1, 0, 
/*39497*/       OPC_EmitInteger, MVT::i1, 0, 
/*39500*/       OPC_EmitInteger, MVT::i1, 0, 
/*39503*/       OPC_MorphNodeTo, TARGET_VAL(AMDGPU::IMAGE_SAMPLE_V4_V2), 0,
                    1/*#VTs*/, MVT::v4f32, 11/*#Ops*/, 3, 4, 5, 6, 7, 8, 9, 10, 0, 1, 2, 
                // Src: (SIsample:v4f32 v2i32:v2i32:$addr, v32i8:v32i8:$rsrc, i128:i128:$sampler, (imm:i32)) - Complexity = 6
                // Dst: (IMAGE_SAMPLE_V4_V2:v4f32 15:i32, 0:i1, 0:i1, 0:i1, 0:i1, 0:i1, 0:i1, 0:i1, ?:v2i32:$addr, ?:v32i8:$rsrc, ?:i128:$sampler)
/*39521*/     0, /*End of Scope*/
/*39522*/   /*Scope*/ 121|128,1/*249*/, /*->39773*/
/*39524*/     OPC_CheckChild0Type, MVT::v4i32,
/*39526*/     OPC_RecordChild1, // #1 = $rsrc
/*39527*/     OPC_RecordChild2, // #2 = $sampler
/*39528*/     OPC_MoveChild, 3,
/*39530*/     OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*39533*/     OPC_Scope, 47, /*->39582*/ // 5 children in Scope
/*39535*/       OPC_CheckPredicate, 74, // Predicate_TEX_RECT
/*39537*/       OPC_MoveParent,
/*39538*/       OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*39540*/       OPC_EmitInteger, MVT::i32, 15, 
/*39543*/       OPC_EmitInteger, MVT::i1, 1, 
/*39546*/       OPC_EmitInteger, MVT::i1, 0, 
/*39549*/       OPC_EmitInteger, MVT::i1, 0, 
/*39552*/       OPC_EmitInteger, MVT::i1, 0, 
/*39555*/       OPC_EmitInteger, MVT::i1, 0, 
/*39558*/       OPC_EmitInteger, MVT::i1, 0, 
/*39561*/       OPC_EmitInteger, MVT::i1, 0, 
/*39564*/       OPC_MorphNodeTo, TARGET_VAL(AMDGPU::IMAGE_SAMPLE_V4_V4), 0,
                    1/*#VTs*/, MVT::v4f32, 11/*#Ops*/, 3, 4, 5, 6, 7, 8, 9, 10, 0, 1, 2, 
                // Src: (SIsample:v4f32 v4i32:v4i32:$addr, v32i8:v32i8:$rsrc, i128:i128:$sampler, (imm:i32)<<P:Predicate_TEX_RECT>>) - Complexity = 7
                // Dst: (IMAGE_SAMPLE_V4_V4:v4f32 15:i32, 1:i1, 0:i1, 0:i1, 0:i1, 0:i1, 0:i1, 0:i1, ?:v4i32:$addr, ?:v32i8:$rsrc, ?:i128:$sampler)
/*39582*/     /*Scope*/ 47, /*->39630*/
/*39583*/       OPC_CheckPredicate, 42, // Predicate_TEX_ARRAY
/*39585*/       OPC_MoveParent,
/*39586*/       OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*39588*/       OPC_EmitInteger, MVT::i32, 15, 
/*39591*/       OPC_EmitInteger, MVT::i1, 0, 
/*39594*/       OPC_EmitInteger, MVT::i1, 0, 
/*39597*/       OPC_EmitInteger, MVT::i1, 1, 
/*39600*/       OPC_EmitInteger, MVT::i1, 0, 
/*39603*/       OPC_EmitInteger, MVT::i1, 0, 
/*39606*/       OPC_EmitInteger, MVT::i1, 0, 
/*39609*/       OPC_EmitInteger, MVT::i1, 0, 
/*39612*/       OPC_MorphNodeTo, TARGET_VAL(AMDGPU::IMAGE_SAMPLE_V4_V4), 0,
                    1/*#VTs*/, MVT::v4f32, 11/*#Ops*/, 3, 4, 5, 6, 7, 8, 9, 10, 0, 1, 2, 
                // Src: (SIsample:v4f32 v4i32:v4i32:$addr, v32i8:v32i8:$rsrc, i128:i128:$sampler, (imm:i32)<<P:Predicate_TEX_ARRAY>>) - Complexity = 7
                // Dst: (IMAGE_SAMPLE_V4_V4:v4f32 15:i32, 0:i1, 0:i1, 1:i1, 0:i1, 0:i1, 0:i1, 0:i1, ?:v4i32:$addr, ?:v32i8:$rsrc, ?:i128:$sampler)
/*39630*/     /*Scope*/ 47, /*->39678*/
/*39631*/       OPC_CheckPredicate, 45, // Predicate_TEX_SHADOW
/*39633*/       OPC_MoveParent,
/*39634*/       OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*39636*/       OPC_EmitInteger, MVT::i32, 15, 
/*39639*/       OPC_EmitInteger, MVT::i1, 0, 
/*39642*/       OPC_EmitInteger, MVT::i1, 0, 
/*39645*/       OPC_EmitInteger, MVT::i1, 0, 
/*39648*/       OPC_EmitInteger, MVT::i1, 0, 
/*39651*/       OPC_EmitInteger, MVT::i1, 0, 
/*39654*/       OPC_EmitInteger, MVT::i1, 0, 
/*39657*/       OPC_EmitInteger, MVT::i1, 0, 
/*39660*/       OPC_MorphNodeTo, TARGET_VAL(AMDGPU::IMAGE_SAMPLE_C_V4_V4), 0,
                    1/*#VTs*/, MVT::v4f32, 11/*#Ops*/, 3, 4, 5, 6, 7, 8, 9, 10, 0, 1, 2, 
                // Src: (SIsample:v4f32 v4i32:v4i32:$addr, v32i8:v32i8:$rsrc, i128:i128:$sampler, (imm:i32)<<P:Predicate_TEX_SHADOW>>) - Complexity = 7
                // Dst: (IMAGE_SAMPLE_C_V4_V4:v4f32 15:i32, 0:i1, 0:i1, 0:i1, 0:i1, 0:i1, 0:i1, 0:i1, ?:v4i32:$addr, ?:v32i8:$rsrc, ?:i128:$sampler)
/*39678*/     /*Scope*/ 47, /*->39726*/
/*39679*/       OPC_CheckPredicate, 75, // Predicate_TEX_SHADOW_ARRAY
/*39681*/       OPC_MoveParent,
/*39682*/       OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*39684*/       OPC_EmitInteger, MVT::i32, 15, 
/*39687*/       OPC_EmitInteger, MVT::i1, 0, 
/*39690*/       OPC_EmitInteger, MVT::i1, 0, 
/*39693*/       OPC_EmitInteger, MVT::i1, 1, 
/*39696*/       OPC_EmitInteger, MVT::i1, 0, 
/*39699*/       OPC_EmitInteger, MVT::i1, 0, 
/*39702*/       OPC_EmitInteger, MVT::i1, 0, 
/*39705*/       OPC_EmitInteger, MVT::i1, 0, 
/*39708*/       OPC_MorphNodeTo, TARGET_VAL(AMDGPU::IMAGE_SAMPLE_C_V4_V4), 0,
                    1/*#VTs*/, MVT::v4f32, 11/*#Ops*/, 3, 4, 5, 6, 7, 8, 9, 10, 0, 1, 2, 
                // Src: (SIsample:v4f32 v4i32:v4i32:$addr, v32i8:v32i8:$rsrc, i128:i128:$sampler, (imm:i32)<<P:Predicate_TEX_SHADOW_ARRAY>>) - Complexity = 7
                // Dst: (IMAGE_SAMPLE_C_V4_V4:v4f32 15:i32, 0:i1, 0:i1, 1:i1, 0:i1, 0:i1, 0:i1, 0:i1, ?:v4i32:$addr, ?:v32i8:$rsrc, ?:i128:$sampler)
/*39726*/     /*Scope*/ 45, /*->39772*/
/*39727*/       OPC_MoveParent,
/*39728*/       OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*39730*/       OPC_EmitInteger, MVT::i32, 15, 
/*39733*/       OPC_EmitInteger, MVT::i1, 0, 
/*39736*/       OPC_EmitInteger, MVT::i1, 0, 
/*39739*/       OPC_EmitInteger, MVT::i1, 0, 
/*39742*/       OPC_EmitInteger, MVT::i1, 0, 
/*39745*/       OPC_EmitInteger, MVT::i1, 0, 
/*39748*/       OPC_EmitInteger, MVT::i1, 0, 
/*39751*/       OPC_EmitInteger, MVT::i1, 0, 
/*39754*/       OPC_MorphNodeTo, TARGET_VAL(AMDGPU::IMAGE_SAMPLE_V4_V4), 0,
                    1/*#VTs*/, MVT::v4f32, 11/*#Ops*/, 3, 4, 5, 6, 7, 8, 9, 10, 0, 1, 2, 
                // Src: (SIsample:v4f32 v4i32:v4i32:$addr, v32i8:v32i8:$rsrc, i128:i128:$sampler, (imm:i32)) - Complexity = 6
                // Dst: (IMAGE_SAMPLE_V4_V4:v4f32 15:i32, 0:i1, 0:i1, 0:i1, 0:i1, 0:i1, 0:i1, 0:i1, ?:v4i32:$addr, ?:v32i8:$rsrc, ?:i128:$sampler)
/*39772*/     0, /*End of Scope*/
/*39773*/   /*Scope*/ 121|128,1/*249*/, /*->40024*/
/*39775*/     OPC_CheckChild0Type, MVT::v8i32,
/*39777*/     OPC_RecordChild1, // #1 = $rsrc
/*39778*/     OPC_RecordChild2, // #2 = $sampler
/*39779*/     OPC_MoveChild, 3,
/*39781*/     OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*39784*/     OPC_Scope, 47, /*->39833*/ // 5 children in Scope
/*39786*/       OPC_CheckPredicate, 74, // Predicate_TEX_RECT
/*39788*/       OPC_MoveParent,
/*39789*/       OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*39791*/       OPC_EmitInteger, MVT::i32, 15, 
/*39794*/       OPC_EmitInteger, MVT::i1, 1, 
/*39797*/       OPC_EmitInteger, MVT::i1, 0, 
/*39800*/       OPC_EmitInteger, MVT::i1, 0, 
/*39803*/       OPC_EmitInteger, MVT::i1, 0, 
/*39806*/       OPC_EmitInteger, MVT::i1, 0, 
/*39809*/       OPC_EmitInteger, MVT::i1, 0, 
/*39812*/       OPC_EmitInteger, MVT::i1, 0, 
/*39815*/       OPC_MorphNodeTo, TARGET_VAL(AMDGPU::IMAGE_SAMPLE_V4_V8), 0,
                    1/*#VTs*/, MVT::v4f32, 11/*#Ops*/, 3, 4, 5, 6, 7, 8, 9, 10, 0, 1, 2, 
                // Src: (SIsample:v4f32 v8i32:v8i32:$addr, v32i8:v32i8:$rsrc, i128:i128:$sampler, (imm:i32)<<P:Predicate_TEX_RECT>>) - Complexity = 7
                // Dst: (IMAGE_SAMPLE_V4_V8:v4f32 15:i32, 1:i1, 0:i1, 0:i1, 0:i1, 0:i1, 0:i1, 0:i1, ?:v8i32:$addr, ?:v32i8:$rsrc, ?:i128:$sampler)
/*39833*/     /*Scope*/ 47, /*->39881*/
/*39834*/       OPC_CheckPredicate, 42, // Predicate_TEX_ARRAY
/*39836*/       OPC_MoveParent,
/*39837*/       OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*39839*/       OPC_EmitInteger, MVT::i32, 15, 
/*39842*/       OPC_EmitInteger, MVT::i1, 0, 
/*39845*/       OPC_EmitInteger, MVT::i1, 0, 
/*39848*/       OPC_EmitInteger, MVT::i1, 1, 
/*39851*/       OPC_EmitInteger, MVT::i1, 0, 
/*39854*/       OPC_EmitInteger, MVT::i1, 0, 
/*39857*/       OPC_EmitInteger, MVT::i1, 0, 
/*39860*/       OPC_EmitInteger, MVT::i1, 0, 
/*39863*/       OPC_MorphNodeTo, TARGET_VAL(AMDGPU::IMAGE_SAMPLE_V4_V8), 0,
                    1/*#VTs*/, MVT::v4f32, 11/*#Ops*/, 3, 4, 5, 6, 7, 8, 9, 10, 0, 1, 2, 
                // Src: (SIsample:v4f32 v8i32:v8i32:$addr, v32i8:v32i8:$rsrc, i128:i128:$sampler, (imm:i32)<<P:Predicate_TEX_ARRAY>>) - Complexity = 7
                // Dst: (IMAGE_SAMPLE_V4_V8:v4f32 15:i32, 0:i1, 0:i1, 1:i1, 0:i1, 0:i1, 0:i1, 0:i1, ?:v8i32:$addr, ?:v32i8:$rsrc, ?:i128:$sampler)
/*39881*/     /*Scope*/ 47, /*->39929*/
/*39882*/       OPC_CheckPredicate, 45, // Predicate_TEX_SHADOW
/*39884*/       OPC_MoveParent,
/*39885*/       OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*39887*/       OPC_EmitInteger, MVT::i32, 15, 
/*39890*/       OPC_EmitInteger, MVT::i1, 0, 
/*39893*/       OPC_EmitInteger, MVT::i1, 0, 
/*39896*/       OPC_EmitInteger, MVT::i1, 0, 
/*39899*/       OPC_EmitInteger, MVT::i1, 0, 
/*39902*/       OPC_EmitInteger, MVT::i1, 0, 
/*39905*/       OPC_EmitInteger, MVT::i1, 0, 
/*39908*/       OPC_EmitInteger, MVT::i1, 0, 
/*39911*/       OPC_MorphNodeTo, TARGET_VAL(AMDGPU::IMAGE_SAMPLE_C_V4_V8), 0,
                    1/*#VTs*/, MVT::v4f32, 11/*#Ops*/, 3, 4, 5, 6, 7, 8, 9, 10, 0, 1, 2, 
                // Src: (SIsample:v4f32 v8i32:v8i32:$addr, v32i8:v32i8:$rsrc, i128:i128:$sampler, (imm:i32)<<P:Predicate_TEX_SHADOW>>) - Complexity = 7
                // Dst: (IMAGE_SAMPLE_C_V4_V8:v4f32 15:i32, 0:i1, 0:i1, 0:i1, 0:i1, 0:i1, 0:i1, 0:i1, ?:v8i32:$addr, ?:v32i8:$rsrc, ?:i128:$sampler)
/*39929*/     /*Scope*/ 47, /*->39977*/
/*39930*/       OPC_CheckPredicate, 75, // Predicate_TEX_SHADOW_ARRAY
/*39932*/       OPC_MoveParent,
/*39933*/       OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*39935*/       OPC_EmitInteger, MVT::i32, 15, 
/*39938*/       OPC_EmitInteger, MVT::i1, 0, 
/*39941*/       OPC_EmitInteger, MVT::i1, 0, 
/*39944*/       OPC_EmitInteger, MVT::i1, 1, 
/*39947*/       OPC_EmitInteger, MVT::i1, 0, 
/*39950*/       OPC_EmitInteger, MVT::i1, 0, 
/*39953*/       OPC_EmitInteger, MVT::i1, 0, 
/*39956*/       OPC_EmitInteger, MVT::i1, 0, 
/*39959*/       OPC_MorphNodeTo, TARGET_VAL(AMDGPU::IMAGE_SAMPLE_C_V4_V8), 0,
                    1/*#VTs*/, MVT::v4f32, 11/*#Ops*/, 3, 4, 5, 6, 7, 8, 9, 10, 0, 1, 2, 
                // Src: (SIsample:v4f32 v8i32:v8i32:$addr, v32i8:v32i8:$rsrc, i128:i128:$sampler, (imm:i32)<<P:Predicate_TEX_SHADOW_ARRAY>>) - Complexity = 7
                // Dst: (IMAGE_SAMPLE_C_V4_V8:v4f32 15:i32, 0:i1, 0:i1, 1:i1, 0:i1, 0:i1, 0:i1, 0:i1, ?:v8i32:$addr, ?:v32i8:$rsrc, ?:i128:$sampler)
/*39977*/     /*Scope*/ 45, /*->40023*/
/*39978*/       OPC_MoveParent,
/*39979*/       OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*39981*/       OPC_EmitInteger, MVT::i32, 15, 
/*39984*/       OPC_EmitInteger, MVT::i1, 0, 
/*39987*/       OPC_EmitInteger, MVT::i1, 0, 
/*39990*/       OPC_EmitInteger, MVT::i1, 0, 
/*39993*/       OPC_EmitInteger, MVT::i1, 0, 
/*39996*/       OPC_EmitInteger, MVT::i1, 0, 
/*39999*/       OPC_EmitInteger, MVT::i1, 0, 
/*40002*/       OPC_EmitInteger, MVT::i1, 0, 
/*40005*/       OPC_MorphNodeTo, TARGET_VAL(AMDGPU::IMAGE_SAMPLE_V4_V8), 0,
                    1/*#VTs*/, MVT::v4f32, 11/*#Ops*/, 3, 4, 5, 6, 7, 8, 9, 10, 0, 1, 2, 
                // Src: (SIsample:v4f32 v8i32:v8i32:$addr, v32i8:v32i8:$rsrc, i128:i128:$sampler, (imm:i32)) - Complexity = 6
                // Dst: (IMAGE_SAMPLE_V4_V8:v4f32 15:i32, 0:i1, 0:i1, 0:i1, 0:i1, 0:i1, 0:i1, 0:i1, ?:v8i32:$addr, ?:v32i8:$rsrc, ?:i128:$sampler)
/*40023*/     0, /*End of Scope*/
/*40024*/   /*Scope*/ 121|128,1/*249*/, /*->40275*/
/*40026*/     OPC_CheckChild0Type, MVT::v16i32,
/*40028*/     OPC_RecordChild1, // #1 = $rsrc
/*40029*/     OPC_RecordChild2, // #2 = $sampler
/*40030*/     OPC_MoveChild, 3,
/*40032*/     OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*40035*/     OPC_Scope, 47, /*->40084*/ // 5 children in Scope
/*40037*/       OPC_CheckPredicate, 74, // Predicate_TEX_RECT
/*40039*/       OPC_MoveParent,
/*40040*/       OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*40042*/       OPC_EmitInteger, MVT::i32, 15, 
/*40045*/       OPC_EmitInteger, MVT::i1, 1, 
/*40048*/       OPC_EmitInteger, MVT::i1, 0, 
/*40051*/       OPC_EmitInteger, MVT::i1, 0, 
/*40054*/       OPC_EmitInteger, MVT::i1, 0, 
/*40057*/       OPC_EmitInteger, MVT::i1, 0, 
/*40060*/       OPC_EmitInteger, MVT::i1, 0, 
/*40063*/       OPC_EmitInteger, MVT::i1, 0, 
/*40066*/       OPC_MorphNodeTo, TARGET_VAL(AMDGPU::IMAGE_SAMPLE_V4_V16), 0,
                    1/*#VTs*/, MVT::v4f32, 11/*#Ops*/, 3, 4, 5, 6, 7, 8, 9, 10, 0, 1, 2, 
                // Src: (SIsample:v4f32 v16i32:v16i32:$addr, v32i8:v32i8:$rsrc, i128:i128:$sampler, (imm:i32)<<P:Predicate_TEX_RECT>>) - Complexity = 7
                // Dst: (IMAGE_SAMPLE_V4_V16:v4f32 15:i32, 1:i1, 0:i1, 0:i1, 0:i1, 0:i1, 0:i1, 0:i1, ?:v16i32:$addr, ?:v32i8:$rsrc, ?:i128:$sampler)
/*40084*/     /*Scope*/ 47, /*->40132*/
/*40085*/       OPC_CheckPredicate, 42, // Predicate_TEX_ARRAY
/*40087*/       OPC_MoveParent,
/*40088*/       OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*40090*/       OPC_EmitInteger, MVT::i32, 15, 
/*40093*/       OPC_EmitInteger, MVT::i1, 0, 
/*40096*/       OPC_EmitInteger, MVT::i1, 0, 
/*40099*/       OPC_EmitInteger, MVT::i1, 1, 
/*40102*/       OPC_EmitInteger, MVT::i1, 0, 
/*40105*/       OPC_EmitInteger, MVT::i1, 0, 
/*40108*/       OPC_EmitInteger, MVT::i1, 0, 
/*40111*/       OPC_EmitInteger, MVT::i1, 0, 
/*40114*/       OPC_MorphNodeTo, TARGET_VAL(AMDGPU::IMAGE_SAMPLE_V4_V16), 0,
                    1/*#VTs*/, MVT::v4f32, 11/*#Ops*/, 3, 4, 5, 6, 7, 8, 9, 10, 0, 1, 2, 
                // Src: (SIsample:v4f32 v16i32:v16i32:$addr, v32i8:v32i8:$rsrc, i128:i128:$sampler, (imm:i32)<<P:Predicate_TEX_ARRAY>>) - Complexity = 7
                // Dst: (IMAGE_SAMPLE_V4_V16:v4f32 15:i32, 0:i1, 0:i1, 1:i1, 0:i1, 0:i1, 0:i1, 0:i1, ?:v16i32:$addr, ?:v32i8:$rsrc, ?:i128:$sampler)
/*40132*/     /*Scope*/ 47, /*->40180*/
/*40133*/       OPC_CheckPredicate, 45, // Predicate_TEX_SHADOW
/*40135*/       OPC_MoveParent,
/*40136*/       OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*40138*/       OPC_EmitInteger, MVT::i32, 15, 
/*40141*/       OPC_EmitInteger, MVT::i1, 0, 
/*40144*/       OPC_EmitInteger, MVT::i1, 0, 
/*40147*/       OPC_EmitInteger, MVT::i1, 0, 
/*40150*/       OPC_EmitInteger, MVT::i1, 0, 
/*40153*/       OPC_EmitInteger, MVT::i1, 0, 
/*40156*/       OPC_EmitInteger, MVT::i1, 0, 
/*40159*/       OPC_EmitInteger, MVT::i1, 0, 
/*40162*/       OPC_MorphNodeTo, TARGET_VAL(AMDGPU::IMAGE_SAMPLE_C_V4_V16), 0,
                    1/*#VTs*/, MVT::v4f32, 11/*#Ops*/, 3, 4, 5, 6, 7, 8, 9, 10, 0, 1, 2, 
                // Src: (SIsample:v4f32 v16i32:v16i32:$addr, v32i8:v32i8:$rsrc, i128:i128:$sampler, (imm:i32)<<P:Predicate_TEX_SHADOW>>) - Complexity = 7
                // Dst: (IMAGE_SAMPLE_C_V4_V16:v4f32 15:i32, 0:i1, 0:i1, 0:i1, 0:i1, 0:i1, 0:i1, 0:i1, ?:v16i32:$addr, ?:v32i8:$rsrc, ?:i128:$sampler)
/*40180*/     /*Scope*/ 47, /*->40228*/
/*40181*/       OPC_CheckPredicate, 75, // Predicate_TEX_SHADOW_ARRAY
/*40183*/       OPC_MoveParent,
/*40184*/       OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*40186*/       OPC_EmitInteger, MVT::i32, 15, 
/*40189*/       OPC_EmitInteger, MVT::i1, 0, 
/*40192*/       OPC_EmitInteger, MVT::i1, 0, 
/*40195*/       OPC_EmitInteger, MVT::i1, 1, 
/*40198*/       OPC_EmitInteger, MVT::i1, 0, 
/*40201*/       OPC_EmitInteger, MVT::i1, 0, 
/*40204*/       OPC_EmitInteger, MVT::i1, 0, 
/*40207*/       OPC_EmitInteger, MVT::i1, 0, 
/*40210*/       OPC_MorphNodeTo, TARGET_VAL(AMDGPU::IMAGE_SAMPLE_C_V4_V16), 0,
                    1/*#VTs*/, MVT::v4f32, 11/*#Ops*/, 3, 4, 5, 6, 7, 8, 9, 10, 0, 1, 2, 
                // Src: (SIsample:v4f32 v16i32:v16i32:$addr, v32i8:v32i8:$rsrc, i128:i128:$sampler, (imm:i32)<<P:Predicate_TEX_SHADOW_ARRAY>>) - Complexity = 7
                // Dst: (IMAGE_SAMPLE_C_V4_V16:v4f32 15:i32, 0:i1, 0:i1, 1:i1, 0:i1, 0:i1, 0:i1, 0:i1, ?:v16i32:$addr, ?:v32i8:$rsrc, ?:i128:$sampler)
/*40228*/     /*Scope*/ 45, /*->40274*/
/*40229*/       OPC_MoveParent,
/*40230*/       OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*40232*/       OPC_EmitInteger, MVT::i32, 15, 
/*40235*/       OPC_EmitInteger, MVT::i1, 0, 
/*40238*/       OPC_EmitInteger, MVT::i1, 0, 
/*40241*/       OPC_EmitInteger, MVT::i1, 0, 
/*40244*/       OPC_EmitInteger, MVT::i1, 0, 
/*40247*/       OPC_EmitInteger, MVT::i1, 0, 
/*40250*/       OPC_EmitInteger, MVT::i1, 0, 
/*40253*/       OPC_EmitInteger, MVT::i1, 0, 
/*40256*/       OPC_MorphNodeTo, TARGET_VAL(AMDGPU::IMAGE_SAMPLE_V4_V16), 0,
                    1/*#VTs*/, MVT::v4f32, 11/*#Ops*/, 3, 4, 5, 6, 7, 8, 9, 10, 0, 1, 2, 
                // Src: (SIsample:v4f32 v16i32:v16i32:$addr, v32i8:v32i8:$rsrc, i128:i128:$sampler, (imm:i32)) - Complexity = 6
                // Dst: (IMAGE_SAMPLE_V4_V16:v4f32 15:i32, 0:i1, 0:i1, 0:i1, 0:i1, 0:i1, 0:i1, 0:i1, ?:v16i32:$addr, ?:v32i8:$rsrc, ?:i128:$sampler)
/*40274*/     0, /*End of Scope*/
/*40275*/   /*Scope*/ 54, /*->40330*/
/*40276*/     OPC_CheckChild0Type, MVT::i32,
/*40278*/     OPC_RecordChild1, // #1 = $rsrc
/*40279*/     OPC_RecordChild2, // #2 = $sampler
/*40280*/     OPC_MoveChild, 3,
/*40282*/     OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*40285*/     OPC_MoveParent,
/*40286*/     OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*40288*/     OPC_EmitInteger, MVT::i32, 15, 
/*40291*/     OPC_EmitInteger, MVT::i1, 0, 
/*40294*/     OPC_EmitInteger, MVT::i1, 0, 
/*40297*/     OPC_EmitInteger, MVT::i1, 0, 
/*40300*/     OPC_EmitInteger, MVT::i1, 0, 
/*40303*/     OPC_EmitInteger, MVT::i1, 0, 
/*40306*/     OPC_EmitInteger, MVT::i1, 0, 
/*40309*/     OPC_EmitInteger, MVT::i1, 0, 
/*40312*/     OPC_MorphNodeTo, TARGET_VAL(AMDGPU::IMAGE_SAMPLE_V4_V1), 0,
                  1/*#VTs*/, MVT::v4f32, 11/*#Ops*/, 3, 4, 5, 6, 7, 8, 9, 10, 0, 1, 2, 
              // Src: (SIsample:v4f32 i32:i32:$addr, v32i8:v32i8:$rsrc, i128:i128:$sampler, (imm:i32)) - Complexity = 6
              // Dst: (IMAGE_SAMPLE_V4_V1:v4f32 15:i32, 0:i1, 0:i1, 0:i1, 0:i1, 0:i1, 0:i1, 0:i1, ?:i32:$addr, ?:v32i8:$rsrc, ?:i128:$sampler)
/*40330*/   0, /*End of Scope*/
/*40331*/ /*SwitchOpcode*/ 47|128,6/*815*/,  TARGET_VAL(AMDGPUISD::SAMPLEL),// ->41150
/*40335*/   OPC_RecordChild0, // #0 = $addr
/*40336*/   OPC_Scope, 73|128,1/*201*/, /*->40540*/ // 4 children in Scope
/*40339*/     OPC_CheckChild0Type, MVT::v2i32,
/*40341*/     OPC_RecordChild1, // #1 = $rsrc
/*40342*/     OPC_RecordChild2, // #2 = $sampler
/*40343*/     OPC_MoveChild, 3,
/*40345*/     OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*40348*/     OPC_Scope, 47, /*->40397*/ // 4 children in Scope
/*40350*/       OPC_CheckPredicate, 42, // Predicate_TEX_ARRAY
/*40352*/       OPC_MoveParent,
/*40353*/       OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*40355*/       OPC_EmitInteger, MVT::i32, 15, 
/*40358*/       OPC_EmitInteger, MVT::i1, 0, 
/*40361*/       OPC_EmitInteger, MVT::i1, 0, 
/*40364*/       OPC_EmitInteger, MVT::i1, 1, 
/*40367*/       OPC_EmitInteger, MVT::i1, 0, 
/*40370*/       OPC_EmitInteger, MVT::i1, 0, 
/*40373*/       OPC_EmitInteger, MVT::i1, 0, 
/*40376*/       OPC_EmitInteger, MVT::i1, 0, 
/*40379*/       OPC_MorphNodeTo, TARGET_VAL(AMDGPU::IMAGE_SAMPLE_L_V4_V2), 0,
                    1/*#VTs*/, MVT::v4f32, 11/*#Ops*/, 3, 4, 5, 6, 7, 8, 9, 10, 0, 1, 2, 
                // Src: (SIsamplel:v4f32 v2i32:v2i32:$addr, v32i8:v32i8:$rsrc, i128:i128:$sampler, (imm:i32)<<P:Predicate_TEX_ARRAY>>) - Complexity = 7
                // Dst: (IMAGE_SAMPLE_L_V4_V2:v4f32 15:i32, 0:i1, 0:i1, 1:i1, 0:i1, 0:i1, 0:i1, 0:i1, ?:v2i32:$addr, ?:v32i8:$rsrc, ?:i128:$sampler)
/*40397*/     /*Scope*/ 47, /*->40445*/
/*40398*/       OPC_CheckPredicate, 45, // Predicate_TEX_SHADOW
/*40400*/       OPC_MoveParent,
/*40401*/       OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*40403*/       OPC_EmitInteger, MVT::i32, 15, 
/*40406*/       OPC_EmitInteger, MVT::i1, 0, 
/*40409*/       OPC_EmitInteger, MVT::i1, 0, 
/*40412*/       OPC_EmitInteger, MVT::i1, 0, 
/*40415*/       OPC_EmitInteger, MVT::i1, 0, 
/*40418*/       OPC_EmitInteger, MVT::i1, 0, 
/*40421*/       OPC_EmitInteger, MVT::i1, 0, 
/*40424*/       OPC_EmitInteger, MVT::i1, 0, 
/*40427*/       OPC_MorphNodeTo, TARGET_VAL(AMDGPU::IMAGE_SAMPLE_C_L_V4_V2), 0,
                    1/*#VTs*/, MVT::v4f32, 11/*#Ops*/, 3, 4, 5, 6, 7, 8, 9, 10, 0, 1, 2, 
                // Src: (SIsamplel:v4f32 v2i32:v2i32:$addr, v32i8:v32i8:$rsrc, i128:i128:$sampler, (imm:i32)<<P:Predicate_TEX_SHADOW>>) - Complexity = 7
                // Dst: (IMAGE_SAMPLE_C_L_V4_V2:v4f32 15:i32, 0:i1, 0:i1, 0:i1, 0:i1, 0:i1, 0:i1, 0:i1, ?:v2i32:$addr, ?:v32i8:$rsrc, ?:i128:$sampler)
/*40445*/     /*Scope*/ 47, /*->40493*/
/*40446*/       OPC_CheckPredicate, 75, // Predicate_TEX_SHADOW_ARRAY
/*40448*/       OPC_MoveParent,
/*40449*/       OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*40451*/       OPC_EmitInteger, MVT::i32, 15, 
/*40454*/       OPC_EmitInteger, MVT::i1, 0, 
/*40457*/       OPC_EmitInteger, MVT::i1, 0, 
/*40460*/       OPC_EmitInteger, MVT::i1, 1, 
/*40463*/       OPC_EmitInteger, MVT::i1, 0, 
/*40466*/       OPC_EmitInteger, MVT::i1, 0, 
/*40469*/       OPC_EmitInteger, MVT::i1, 0, 
/*40472*/       OPC_EmitInteger, MVT::i1, 0, 
/*40475*/       OPC_MorphNodeTo, TARGET_VAL(AMDGPU::IMAGE_SAMPLE_C_L_V4_V2), 0,
                    1/*#VTs*/, MVT::v4f32, 11/*#Ops*/, 3, 4, 5, 6, 7, 8, 9, 10, 0, 1, 2, 
                // Src: (SIsamplel:v4f32 v2i32:v2i32:$addr, v32i8:v32i8:$rsrc, i128:i128:$sampler, (imm:i32)<<P:Predicate_TEX_SHADOW_ARRAY>>) - Complexity = 7
                // Dst: (IMAGE_SAMPLE_C_L_V4_V2:v4f32 15:i32, 0:i1, 0:i1, 1:i1, 0:i1, 0:i1, 0:i1, 0:i1, ?:v2i32:$addr, ?:v32i8:$rsrc, ?:i128:$sampler)
/*40493*/     /*Scope*/ 45, /*->40539*/
/*40494*/       OPC_MoveParent,
/*40495*/       OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*40497*/       OPC_EmitInteger, MVT::i32, 15, 
/*40500*/       OPC_EmitInteger, MVT::i1, 0, 
/*40503*/       OPC_EmitInteger, MVT::i1, 0, 
/*40506*/       OPC_EmitInteger, MVT::i1, 0, 
/*40509*/       OPC_EmitInteger, MVT::i1, 0, 
/*40512*/       OPC_EmitInteger, MVT::i1, 0, 
/*40515*/       OPC_EmitInteger, MVT::i1, 0, 
/*40518*/       OPC_EmitInteger, MVT::i1, 0, 
/*40521*/       OPC_MorphNodeTo, TARGET_VAL(AMDGPU::IMAGE_SAMPLE_L_V4_V2), 0,
                    1/*#VTs*/, MVT::v4f32, 11/*#Ops*/, 3, 4, 5, 6, 7, 8, 9, 10, 0, 1, 2, 
                // Src: (SIsamplel:v4f32 v2i32:v2i32:$addr, v32i8:v32i8:$rsrc, i128:i128:$sampler, (imm:i32)) - Complexity = 6
                // Dst: (IMAGE_SAMPLE_L_V4_V2:v4f32 15:i32, 0:i1, 0:i1, 0:i1, 0:i1, 0:i1, 0:i1, 0:i1, ?:v2i32:$addr, ?:v32i8:$rsrc, ?:i128:$sampler)
/*40539*/     0, /*End of Scope*/
/*40540*/   /*Scope*/ 73|128,1/*201*/, /*->40743*/
/*40542*/     OPC_CheckChild0Type, MVT::v4i32,
/*40544*/     OPC_RecordChild1, // #1 = $rsrc
/*40545*/     OPC_RecordChild2, // #2 = $sampler
/*40546*/     OPC_MoveChild, 3,
/*40548*/     OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*40551*/     OPC_Scope, 47, /*->40600*/ // 4 children in Scope
/*40553*/       OPC_CheckPredicate, 42, // Predicate_TEX_ARRAY
/*40555*/       OPC_MoveParent,
/*40556*/       OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*40558*/       OPC_EmitInteger, MVT::i32, 15, 
/*40561*/       OPC_EmitInteger, MVT::i1, 0, 
/*40564*/       OPC_EmitInteger, MVT::i1, 0, 
/*40567*/       OPC_EmitInteger, MVT::i1, 1, 
/*40570*/       OPC_EmitInteger, MVT::i1, 0, 
/*40573*/       OPC_EmitInteger, MVT::i1, 0, 
/*40576*/       OPC_EmitInteger, MVT::i1, 0, 
/*40579*/       OPC_EmitInteger, MVT::i1, 0, 
/*40582*/       OPC_MorphNodeTo, TARGET_VAL(AMDGPU::IMAGE_SAMPLE_L_V4_V4), 0,
                    1/*#VTs*/, MVT::v4f32, 11/*#Ops*/, 3, 4, 5, 6, 7, 8, 9, 10, 0, 1, 2, 
                // Src: (SIsamplel:v4f32 v4i32:v4i32:$addr, v32i8:v32i8:$rsrc, i128:i128:$sampler, (imm:i32)<<P:Predicate_TEX_ARRAY>>) - Complexity = 7
                // Dst: (IMAGE_SAMPLE_L_V4_V4:v4f32 15:i32, 0:i1, 0:i1, 1:i1, 0:i1, 0:i1, 0:i1, 0:i1, ?:v4i32:$addr, ?:v32i8:$rsrc, ?:i128:$sampler)
/*40600*/     /*Scope*/ 47, /*->40648*/
/*40601*/       OPC_CheckPredicate, 45, // Predicate_TEX_SHADOW
/*40603*/       OPC_MoveParent,
/*40604*/       OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*40606*/       OPC_EmitInteger, MVT::i32, 15, 
/*40609*/       OPC_EmitInteger, MVT::i1, 0, 
/*40612*/       OPC_EmitInteger, MVT::i1, 0, 
/*40615*/       OPC_EmitInteger, MVT::i1, 0, 
/*40618*/       OPC_EmitInteger, MVT::i1, 0, 
/*40621*/       OPC_EmitInteger, MVT::i1, 0, 
/*40624*/       OPC_EmitInteger, MVT::i1, 0, 
/*40627*/       OPC_EmitInteger, MVT::i1, 0, 
/*40630*/       OPC_MorphNodeTo, TARGET_VAL(AMDGPU::IMAGE_SAMPLE_C_L_V4_V4), 0,
                    1/*#VTs*/, MVT::v4f32, 11/*#Ops*/, 3, 4, 5, 6, 7, 8, 9, 10, 0, 1, 2, 
                // Src: (SIsamplel:v4f32 v4i32:v4i32:$addr, v32i8:v32i8:$rsrc, i128:i128:$sampler, (imm:i32)<<P:Predicate_TEX_SHADOW>>) - Complexity = 7
                // Dst: (IMAGE_SAMPLE_C_L_V4_V4:v4f32 15:i32, 0:i1, 0:i1, 0:i1, 0:i1, 0:i1, 0:i1, 0:i1, ?:v4i32:$addr, ?:v32i8:$rsrc, ?:i128:$sampler)
/*40648*/     /*Scope*/ 47, /*->40696*/
/*40649*/       OPC_CheckPredicate, 75, // Predicate_TEX_SHADOW_ARRAY
/*40651*/       OPC_MoveParent,
/*40652*/       OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*40654*/       OPC_EmitInteger, MVT::i32, 15, 
/*40657*/       OPC_EmitInteger, MVT::i1, 0, 
/*40660*/       OPC_EmitInteger, MVT::i1, 0, 
/*40663*/       OPC_EmitInteger, MVT::i1, 1, 
/*40666*/       OPC_EmitInteger, MVT::i1, 0, 
/*40669*/       OPC_EmitInteger, MVT::i1, 0, 
/*40672*/       OPC_EmitInteger, MVT::i1, 0, 
/*40675*/       OPC_EmitInteger, MVT::i1, 0, 
/*40678*/       OPC_MorphNodeTo, TARGET_VAL(AMDGPU::IMAGE_SAMPLE_C_L_V4_V4), 0,
                    1/*#VTs*/, MVT::v4f32, 11/*#Ops*/, 3, 4, 5, 6, 7, 8, 9, 10, 0, 1, 2, 
                // Src: (SIsamplel:v4f32 v4i32:v4i32:$addr, v32i8:v32i8:$rsrc, i128:i128:$sampler, (imm:i32)<<P:Predicate_TEX_SHADOW_ARRAY>>) - Complexity = 7
                // Dst: (IMAGE_SAMPLE_C_L_V4_V4:v4f32 15:i32, 0:i1, 0:i1, 1:i1, 0:i1, 0:i1, 0:i1, 0:i1, ?:v4i32:$addr, ?:v32i8:$rsrc, ?:i128:$sampler)
/*40696*/     /*Scope*/ 45, /*->40742*/
/*40697*/       OPC_MoveParent,
/*40698*/       OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*40700*/       OPC_EmitInteger, MVT::i32, 15, 
/*40703*/       OPC_EmitInteger, MVT::i1, 0, 
/*40706*/       OPC_EmitInteger, MVT::i1, 0, 
/*40709*/       OPC_EmitInteger, MVT::i1, 0, 
/*40712*/       OPC_EmitInteger, MVT::i1, 0, 
/*40715*/       OPC_EmitInteger, MVT::i1, 0, 
/*40718*/       OPC_EmitInteger, MVT::i1, 0, 
/*40721*/       OPC_EmitInteger, MVT::i1, 0, 
/*40724*/       OPC_MorphNodeTo, TARGET_VAL(AMDGPU::IMAGE_SAMPLE_L_V4_V4), 0,
                    1/*#VTs*/, MVT::v4f32, 11/*#Ops*/, 3, 4, 5, 6, 7, 8, 9, 10, 0, 1, 2, 
                // Src: (SIsamplel:v4f32 v4i32:v4i32:$addr, v32i8:v32i8:$rsrc, i128:i128:$sampler, (imm:i32)) - Complexity = 6
                // Dst: (IMAGE_SAMPLE_L_V4_V4:v4f32 15:i32, 0:i1, 0:i1, 0:i1, 0:i1, 0:i1, 0:i1, 0:i1, ?:v4i32:$addr, ?:v32i8:$rsrc, ?:i128:$sampler)
/*40742*/     0, /*End of Scope*/
/*40743*/   /*Scope*/ 73|128,1/*201*/, /*->40946*/
/*40745*/     OPC_CheckChild0Type, MVT::v8i32,
/*40747*/     OPC_RecordChild1, // #1 = $rsrc
/*40748*/     OPC_RecordChild2, // #2 = $sampler
/*40749*/     OPC_MoveChild, 3,
/*40751*/     OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*40754*/     OPC_Scope, 47, /*->40803*/ // 4 children in Scope
/*40756*/       OPC_CheckPredicate, 42, // Predicate_TEX_ARRAY
/*40758*/       OPC_MoveParent,
/*40759*/       OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*40761*/       OPC_EmitInteger, MVT::i32, 15, 
/*40764*/       OPC_EmitInteger, MVT::i1, 0, 
/*40767*/       OPC_EmitInteger, MVT::i1, 0, 
/*40770*/       OPC_EmitInteger, MVT::i1, 1, 
/*40773*/       OPC_EmitInteger, MVT::i1, 0, 
/*40776*/       OPC_EmitInteger, MVT::i1, 0, 
/*40779*/       OPC_EmitInteger, MVT::i1, 0, 
/*40782*/       OPC_EmitInteger, MVT::i1, 0, 
/*40785*/       OPC_MorphNodeTo, TARGET_VAL(AMDGPU::IMAGE_SAMPLE_L_V4_V8), 0,
                    1/*#VTs*/, MVT::v4f32, 11/*#Ops*/, 3, 4, 5, 6, 7, 8, 9, 10, 0, 1, 2, 
                // Src: (SIsamplel:v4f32 v8i32:v8i32:$addr, v32i8:v32i8:$rsrc, i128:i128:$sampler, (imm:i32)<<P:Predicate_TEX_ARRAY>>) - Complexity = 7
                // Dst: (IMAGE_SAMPLE_L_V4_V8:v4f32 15:i32, 0:i1, 0:i1, 1:i1, 0:i1, 0:i1, 0:i1, 0:i1, ?:v8i32:$addr, ?:v32i8:$rsrc, ?:i128:$sampler)
/*40803*/     /*Scope*/ 47, /*->40851*/
/*40804*/       OPC_CheckPredicate, 45, // Predicate_TEX_SHADOW
/*40806*/       OPC_MoveParent,
/*40807*/       OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*40809*/       OPC_EmitInteger, MVT::i32, 15, 
/*40812*/       OPC_EmitInteger, MVT::i1, 0, 
/*40815*/       OPC_EmitInteger, MVT::i1, 0, 
/*40818*/       OPC_EmitInteger, MVT::i1, 0, 
/*40821*/       OPC_EmitInteger, MVT::i1, 0, 
/*40824*/       OPC_EmitInteger, MVT::i1, 0, 
/*40827*/       OPC_EmitInteger, MVT::i1, 0, 
/*40830*/       OPC_EmitInteger, MVT::i1, 0, 
/*40833*/       OPC_MorphNodeTo, TARGET_VAL(AMDGPU::IMAGE_SAMPLE_C_L_V4_V8), 0,
                    1/*#VTs*/, MVT::v4f32, 11/*#Ops*/, 3, 4, 5, 6, 7, 8, 9, 10, 0, 1, 2, 
                // Src: (SIsamplel:v4f32 v8i32:v8i32:$addr, v32i8:v32i8:$rsrc, i128:i128:$sampler, (imm:i32)<<P:Predicate_TEX_SHADOW>>) - Complexity = 7
                // Dst: (IMAGE_SAMPLE_C_L_V4_V8:v4f32 15:i32, 0:i1, 0:i1, 0:i1, 0:i1, 0:i1, 0:i1, 0:i1, ?:v8i32:$addr, ?:v32i8:$rsrc, ?:i128:$sampler)
/*40851*/     /*Scope*/ 47, /*->40899*/
/*40852*/       OPC_CheckPredicate, 75, // Predicate_TEX_SHADOW_ARRAY
/*40854*/       OPC_MoveParent,
/*40855*/       OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*40857*/       OPC_EmitInteger, MVT::i32, 15, 
/*40860*/       OPC_EmitInteger, MVT::i1, 0, 
/*40863*/       OPC_EmitInteger, MVT::i1, 0, 
/*40866*/       OPC_EmitInteger, MVT::i1, 1, 
/*40869*/       OPC_EmitInteger, MVT::i1, 0, 
/*40872*/       OPC_EmitInteger, MVT::i1, 0, 
/*40875*/       OPC_EmitInteger, MVT::i1, 0, 
/*40878*/       OPC_EmitInteger, MVT::i1, 0, 
/*40881*/       OPC_MorphNodeTo, TARGET_VAL(AMDGPU::IMAGE_SAMPLE_C_L_V4_V8), 0,
                    1/*#VTs*/, MVT::v4f32, 11/*#Ops*/, 3, 4, 5, 6, 7, 8, 9, 10, 0, 1, 2, 
                // Src: (SIsamplel:v4f32 v8i32:v8i32:$addr, v32i8:v32i8:$rsrc, i128:i128:$sampler, (imm:i32)<<P:Predicate_TEX_SHADOW_ARRAY>>) - Complexity = 7
                // Dst: (IMAGE_SAMPLE_C_L_V4_V8:v4f32 15:i32, 0:i1, 0:i1, 1:i1, 0:i1, 0:i1, 0:i1, 0:i1, ?:v8i32:$addr, ?:v32i8:$rsrc, ?:i128:$sampler)
/*40899*/     /*Scope*/ 45, /*->40945*/
/*40900*/       OPC_MoveParent,
/*40901*/       OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*40903*/       OPC_EmitInteger, MVT::i32, 15, 
/*40906*/       OPC_EmitInteger, MVT::i1, 0, 
/*40909*/       OPC_EmitInteger, MVT::i1, 0, 
/*40912*/       OPC_EmitInteger, MVT::i1, 0, 
/*40915*/       OPC_EmitInteger, MVT::i1, 0, 
/*40918*/       OPC_EmitInteger, MVT::i1, 0, 
/*40921*/       OPC_EmitInteger, MVT::i1, 0, 
/*40924*/       OPC_EmitInteger, MVT::i1, 0, 
/*40927*/       OPC_MorphNodeTo, TARGET_VAL(AMDGPU::IMAGE_SAMPLE_L_V4_V8), 0,
                    1/*#VTs*/, MVT::v4f32, 11/*#Ops*/, 3, 4, 5, 6, 7, 8, 9, 10, 0, 1, 2, 
                // Src: (SIsamplel:v4f32 v8i32:v8i32:$addr, v32i8:v32i8:$rsrc, i128:i128:$sampler, (imm:i32)) - Complexity = 6
                // Dst: (IMAGE_SAMPLE_L_V4_V8:v4f32 15:i32, 0:i1, 0:i1, 0:i1, 0:i1, 0:i1, 0:i1, 0:i1, ?:v8i32:$addr, ?:v32i8:$rsrc, ?:i128:$sampler)
/*40945*/     0, /*End of Scope*/
/*40946*/   /*Scope*/ 73|128,1/*201*/, /*->41149*/
/*40948*/     OPC_CheckChild0Type, MVT::v16i32,
/*40950*/     OPC_RecordChild1, // #1 = $rsrc
/*40951*/     OPC_RecordChild2, // #2 = $sampler
/*40952*/     OPC_MoveChild, 3,
/*40954*/     OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*40957*/     OPC_Scope, 47, /*->41006*/ // 4 children in Scope
/*40959*/       OPC_CheckPredicate, 42, // Predicate_TEX_ARRAY
/*40961*/       OPC_MoveParent,
/*40962*/       OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*40964*/       OPC_EmitInteger, MVT::i32, 15, 
/*40967*/       OPC_EmitInteger, MVT::i1, 0, 
/*40970*/       OPC_EmitInteger, MVT::i1, 0, 
/*40973*/       OPC_EmitInteger, MVT::i1, 1, 
/*40976*/       OPC_EmitInteger, MVT::i1, 0, 
/*40979*/       OPC_EmitInteger, MVT::i1, 0, 
/*40982*/       OPC_EmitInteger, MVT::i1, 0, 
/*40985*/       OPC_EmitInteger, MVT::i1, 0, 
/*40988*/       OPC_MorphNodeTo, TARGET_VAL(AMDGPU::IMAGE_SAMPLE_L_V4_V16), 0,
                    1/*#VTs*/, MVT::v4f32, 11/*#Ops*/, 3, 4, 5, 6, 7, 8, 9, 10, 0, 1, 2, 
                // Src: (SIsamplel:v4f32 v16i32:v16i32:$addr, v32i8:v32i8:$rsrc, i128:i128:$sampler, (imm:i32)<<P:Predicate_TEX_ARRAY>>) - Complexity = 7
                // Dst: (IMAGE_SAMPLE_L_V4_V16:v4f32 15:i32, 0:i1, 0:i1, 1:i1, 0:i1, 0:i1, 0:i1, 0:i1, ?:v16i32:$addr, ?:v32i8:$rsrc, ?:i128:$sampler)
/*41006*/     /*Scope*/ 47, /*->41054*/
/*41007*/       OPC_CheckPredicate, 45, // Predicate_TEX_SHADOW
/*41009*/       OPC_MoveParent,
/*41010*/       OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*41012*/       OPC_EmitInteger, MVT::i32, 15, 
/*41015*/       OPC_EmitInteger, MVT::i1, 0, 
/*41018*/       OPC_EmitInteger, MVT::i1, 0, 
/*41021*/       OPC_EmitInteger, MVT::i1, 0, 
/*41024*/       OPC_EmitInteger, MVT::i1, 0, 
/*41027*/       OPC_EmitInteger, MVT::i1, 0, 
/*41030*/       OPC_EmitInteger, MVT::i1, 0, 
/*41033*/       OPC_EmitInteger, MVT::i1, 0, 
/*41036*/       OPC_MorphNodeTo, TARGET_VAL(AMDGPU::IMAGE_SAMPLE_C_L_V4_V16), 0,
                    1/*#VTs*/, MVT::v4f32, 11/*#Ops*/, 3, 4, 5, 6, 7, 8, 9, 10, 0, 1, 2, 
                // Src: (SIsamplel:v4f32 v16i32:v16i32:$addr, v32i8:v32i8:$rsrc, i128:i128:$sampler, (imm:i32)<<P:Predicate_TEX_SHADOW>>) - Complexity = 7
                // Dst: (IMAGE_SAMPLE_C_L_V4_V16:v4f32 15:i32, 0:i1, 0:i1, 0:i1, 0:i1, 0:i1, 0:i1, 0:i1, ?:v16i32:$addr, ?:v32i8:$rsrc, ?:i128:$sampler)
/*41054*/     /*Scope*/ 47, /*->41102*/
/*41055*/       OPC_CheckPredicate, 75, // Predicate_TEX_SHADOW_ARRAY
/*41057*/       OPC_MoveParent,
/*41058*/       OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*41060*/       OPC_EmitInteger, MVT::i32, 15, 
/*41063*/       OPC_EmitInteger, MVT::i1, 0, 
/*41066*/       OPC_EmitInteger, MVT::i1, 0, 
/*41069*/       OPC_EmitInteger, MVT::i1, 1, 
/*41072*/       OPC_EmitInteger, MVT::i1, 0, 
/*41075*/       OPC_EmitInteger, MVT::i1, 0, 
/*41078*/       OPC_EmitInteger, MVT::i1, 0, 
/*41081*/       OPC_EmitInteger, MVT::i1, 0, 
/*41084*/       OPC_MorphNodeTo, TARGET_VAL(AMDGPU::IMAGE_SAMPLE_C_L_V4_V16), 0,
                    1/*#VTs*/, MVT::v4f32, 11/*#Ops*/, 3, 4, 5, 6, 7, 8, 9, 10, 0, 1, 2, 
                // Src: (SIsamplel:v4f32 v16i32:v16i32:$addr, v32i8:v32i8:$rsrc, i128:i128:$sampler, (imm:i32)<<P:Predicate_TEX_SHADOW_ARRAY>>) - Complexity = 7
                // Dst: (IMAGE_SAMPLE_C_L_V4_V16:v4f32 15:i32, 0:i1, 0:i1, 1:i1, 0:i1, 0:i1, 0:i1, 0:i1, ?:v16i32:$addr, ?:v32i8:$rsrc, ?:i128:$sampler)
/*41102*/     /*Scope*/ 45, /*->41148*/
/*41103*/       OPC_MoveParent,
/*41104*/       OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*41106*/       OPC_EmitInteger, MVT::i32, 15, 
/*41109*/       OPC_EmitInteger, MVT::i1, 0, 
/*41112*/       OPC_EmitInteger, MVT::i1, 0, 
/*41115*/       OPC_EmitInteger, MVT::i1, 0, 
/*41118*/       OPC_EmitInteger, MVT::i1, 0, 
/*41121*/       OPC_EmitInteger, MVT::i1, 0, 
/*41124*/       OPC_EmitInteger, MVT::i1, 0, 
/*41127*/       OPC_EmitInteger, MVT::i1, 0, 
/*41130*/       OPC_MorphNodeTo, TARGET_VAL(AMDGPU::IMAGE_SAMPLE_L_V4_V16), 0,
                    1/*#VTs*/, MVT::v4f32, 11/*#Ops*/, 3, 4, 5, 6, 7, 8, 9, 10, 0, 1, 2, 
                // Src: (SIsamplel:v4f32 v16i32:v16i32:$addr, v32i8:v32i8:$rsrc, i128:i128:$sampler, (imm:i32)) - Complexity = 6
                // Dst: (IMAGE_SAMPLE_L_V4_V16:v4f32 15:i32, 0:i1, 0:i1, 0:i1, 0:i1, 0:i1, 0:i1, 0:i1, ?:v16i32:$addr, ?:v32i8:$rsrc, ?:i128:$sampler)
/*41148*/     0, /*End of Scope*/
/*41149*/   0, /*End of Scope*/
/*41150*/ /*SwitchOpcode*/ 47|128,6/*815*/,  TARGET_VAL(AMDGPUISD::SAMPLEB),// ->41969
/*41154*/   OPC_RecordChild0, // #0 = $addr
/*41155*/   OPC_Scope, 73|128,1/*201*/, /*->41359*/ // 4 children in Scope
/*41158*/     OPC_CheckChild0Type, MVT::v2i32,
/*41160*/     OPC_RecordChild1, // #1 = $rsrc
/*41161*/     OPC_RecordChild2, // #2 = $sampler
/*41162*/     OPC_MoveChild, 3,
/*41164*/     OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*41167*/     OPC_Scope, 47, /*->41216*/ // 4 children in Scope
/*41169*/       OPC_CheckPredicate, 42, // Predicate_TEX_ARRAY
/*41171*/       OPC_MoveParent,
/*41172*/       OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*41174*/       OPC_EmitInteger, MVT::i32, 15, 
/*41177*/       OPC_EmitInteger, MVT::i1, 0, 
/*41180*/       OPC_EmitInteger, MVT::i1, 0, 
/*41183*/       OPC_EmitInteger, MVT::i1, 1, 
/*41186*/       OPC_EmitInteger, MVT::i1, 0, 
/*41189*/       OPC_EmitInteger, MVT::i1, 0, 
/*41192*/       OPC_EmitInteger, MVT::i1, 0, 
/*41195*/       OPC_EmitInteger, MVT::i1, 0, 
/*41198*/       OPC_MorphNodeTo, TARGET_VAL(AMDGPU::IMAGE_SAMPLE_B_V4_V2), 0,
                    1/*#VTs*/, MVT::v4f32, 11/*#Ops*/, 3, 4, 5, 6, 7, 8, 9, 10, 0, 1, 2, 
                // Src: (SIsampleb:v4f32 v2i32:v2i32:$addr, v32i8:v32i8:$rsrc, i128:i128:$sampler, (imm:i32)<<P:Predicate_TEX_ARRAY>>) - Complexity = 7
                // Dst: (IMAGE_SAMPLE_B_V4_V2:v4f32 15:i32, 0:i1, 0:i1, 1:i1, 0:i1, 0:i1, 0:i1, 0:i1, ?:v2i32:$addr, ?:v32i8:$rsrc, ?:i128:$sampler)
/*41216*/     /*Scope*/ 47, /*->41264*/
/*41217*/       OPC_CheckPredicate, 45, // Predicate_TEX_SHADOW
/*41219*/       OPC_MoveParent,
/*41220*/       OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*41222*/       OPC_EmitInteger, MVT::i32, 15, 
/*41225*/       OPC_EmitInteger, MVT::i1, 0, 
/*41228*/       OPC_EmitInteger, MVT::i1, 0, 
/*41231*/       OPC_EmitInteger, MVT::i1, 0, 
/*41234*/       OPC_EmitInteger, MVT::i1, 0, 
/*41237*/       OPC_EmitInteger, MVT::i1, 0, 
/*41240*/       OPC_EmitInteger, MVT::i1, 0, 
/*41243*/       OPC_EmitInteger, MVT::i1, 0, 
/*41246*/       OPC_MorphNodeTo, TARGET_VAL(AMDGPU::IMAGE_SAMPLE_C_B_V4_V2), 0,
                    1/*#VTs*/, MVT::v4f32, 11/*#Ops*/, 3, 4, 5, 6, 7, 8, 9, 10, 0, 1, 2, 
                // Src: (SIsampleb:v4f32 v2i32:v2i32:$addr, v32i8:v32i8:$rsrc, i128:i128:$sampler, (imm:i32)<<P:Predicate_TEX_SHADOW>>) - Complexity = 7
                // Dst: (IMAGE_SAMPLE_C_B_V4_V2:v4f32 15:i32, 0:i1, 0:i1, 0:i1, 0:i1, 0:i1, 0:i1, 0:i1, ?:v2i32:$addr, ?:v32i8:$rsrc, ?:i128:$sampler)
/*41264*/     /*Scope*/ 47, /*->41312*/
/*41265*/       OPC_CheckPredicate, 75, // Predicate_TEX_SHADOW_ARRAY
/*41267*/       OPC_MoveParent,
/*41268*/       OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*41270*/       OPC_EmitInteger, MVT::i32, 15, 
/*41273*/       OPC_EmitInteger, MVT::i1, 0, 
/*41276*/       OPC_EmitInteger, MVT::i1, 0, 
/*41279*/       OPC_EmitInteger, MVT::i1, 1, 
/*41282*/       OPC_EmitInteger, MVT::i1, 0, 
/*41285*/       OPC_EmitInteger, MVT::i1, 0, 
/*41288*/       OPC_EmitInteger, MVT::i1, 0, 
/*41291*/       OPC_EmitInteger, MVT::i1, 0, 
/*41294*/       OPC_MorphNodeTo, TARGET_VAL(AMDGPU::IMAGE_SAMPLE_C_B_V4_V2), 0,
                    1/*#VTs*/, MVT::v4f32, 11/*#Ops*/, 3, 4, 5, 6, 7, 8, 9, 10, 0, 1, 2, 
                // Src: (SIsampleb:v4f32 v2i32:v2i32:$addr, v32i8:v32i8:$rsrc, i128:i128:$sampler, (imm:i32)<<P:Predicate_TEX_SHADOW_ARRAY>>) - Complexity = 7
                // Dst: (IMAGE_SAMPLE_C_B_V4_V2:v4f32 15:i32, 0:i1, 0:i1, 1:i1, 0:i1, 0:i1, 0:i1, 0:i1, ?:v2i32:$addr, ?:v32i8:$rsrc, ?:i128:$sampler)
/*41312*/     /*Scope*/ 45, /*->41358*/
/*41313*/       OPC_MoveParent,
/*41314*/       OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*41316*/       OPC_EmitInteger, MVT::i32, 15, 
/*41319*/       OPC_EmitInteger, MVT::i1, 0, 
/*41322*/       OPC_EmitInteger, MVT::i1, 0, 
/*41325*/       OPC_EmitInteger, MVT::i1, 0, 
/*41328*/       OPC_EmitInteger, MVT::i1, 0, 
/*41331*/       OPC_EmitInteger, MVT::i1, 0, 
/*41334*/       OPC_EmitInteger, MVT::i1, 0, 
/*41337*/       OPC_EmitInteger, MVT::i1, 0, 
/*41340*/       OPC_MorphNodeTo, TARGET_VAL(AMDGPU::IMAGE_SAMPLE_B_V4_V2), 0,
                    1/*#VTs*/, MVT::v4f32, 11/*#Ops*/, 3, 4, 5, 6, 7, 8, 9, 10, 0, 1, 2, 
                // Src: (SIsampleb:v4f32 v2i32:v2i32:$addr, v32i8:v32i8:$rsrc, i128:i128:$sampler, (imm:i32)) - Complexity = 6
                // Dst: (IMAGE_SAMPLE_B_V4_V2:v4f32 15:i32, 0:i1, 0:i1, 0:i1, 0:i1, 0:i1, 0:i1, 0:i1, ?:v2i32:$addr, ?:v32i8:$rsrc, ?:i128:$sampler)
/*41358*/     0, /*End of Scope*/
/*41359*/   /*Scope*/ 73|128,1/*201*/, /*->41562*/
/*41361*/     OPC_CheckChild0Type, MVT::v4i32,
/*41363*/     OPC_RecordChild1, // #1 = $rsrc
/*41364*/     OPC_RecordChild2, // #2 = $sampler
/*41365*/     OPC_MoveChild, 3,
/*41367*/     OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*41370*/     OPC_Scope, 47, /*->41419*/ // 4 children in Scope
/*41372*/       OPC_CheckPredicate, 42, // Predicate_TEX_ARRAY
/*41374*/       OPC_MoveParent,
/*41375*/       OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*41377*/       OPC_EmitInteger, MVT::i32, 15, 
/*41380*/       OPC_EmitInteger, MVT::i1, 0, 
/*41383*/       OPC_EmitInteger, MVT::i1, 0, 
/*41386*/       OPC_EmitInteger, MVT::i1, 1, 
/*41389*/       OPC_EmitInteger, MVT::i1, 0, 
/*41392*/       OPC_EmitInteger, MVT::i1, 0, 
/*41395*/       OPC_EmitInteger, MVT::i1, 0, 
/*41398*/       OPC_EmitInteger, MVT::i1, 0, 
/*41401*/       OPC_MorphNodeTo, TARGET_VAL(AMDGPU::IMAGE_SAMPLE_B_V4_V4), 0,
                    1/*#VTs*/, MVT::v4f32, 11/*#Ops*/, 3, 4, 5, 6, 7, 8, 9, 10, 0, 1, 2, 
                // Src: (SIsampleb:v4f32 v4i32:v4i32:$addr, v32i8:v32i8:$rsrc, i128:i128:$sampler, (imm:i32)<<P:Predicate_TEX_ARRAY>>) - Complexity = 7
                // Dst: (IMAGE_SAMPLE_B_V4_V4:v4f32 15:i32, 0:i1, 0:i1, 1:i1, 0:i1, 0:i1, 0:i1, 0:i1, ?:v4i32:$addr, ?:v32i8:$rsrc, ?:i128:$sampler)
/*41419*/     /*Scope*/ 47, /*->41467*/
/*41420*/       OPC_CheckPredicate, 45, // Predicate_TEX_SHADOW
/*41422*/       OPC_MoveParent,
/*41423*/       OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*41425*/       OPC_EmitInteger, MVT::i32, 15, 
/*41428*/       OPC_EmitInteger, MVT::i1, 0, 
/*41431*/       OPC_EmitInteger, MVT::i1, 0, 
/*41434*/       OPC_EmitInteger, MVT::i1, 0, 
/*41437*/       OPC_EmitInteger, MVT::i1, 0, 
/*41440*/       OPC_EmitInteger, MVT::i1, 0, 
/*41443*/       OPC_EmitInteger, MVT::i1, 0, 
/*41446*/       OPC_EmitInteger, MVT::i1, 0, 
/*41449*/       OPC_MorphNodeTo, TARGET_VAL(AMDGPU::IMAGE_SAMPLE_C_B_V4_V4), 0,
                    1/*#VTs*/, MVT::v4f32, 11/*#Ops*/, 3, 4, 5, 6, 7, 8, 9, 10, 0, 1, 2, 
                // Src: (SIsampleb:v4f32 v4i32:v4i32:$addr, v32i8:v32i8:$rsrc, i128:i128:$sampler, (imm:i32)<<P:Predicate_TEX_SHADOW>>) - Complexity = 7
                // Dst: (IMAGE_SAMPLE_C_B_V4_V4:v4f32 15:i32, 0:i1, 0:i1, 0:i1, 0:i1, 0:i1, 0:i1, 0:i1, ?:v4i32:$addr, ?:v32i8:$rsrc, ?:i128:$sampler)
/*41467*/     /*Scope*/ 47, /*->41515*/
/*41468*/       OPC_CheckPredicate, 75, // Predicate_TEX_SHADOW_ARRAY
/*41470*/       OPC_MoveParent,
/*41471*/       OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*41473*/       OPC_EmitInteger, MVT::i32, 15, 
/*41476*/       OPC_EmitInteger, MVT::i1, 0, 
/*41479*/       OPC_EmitInteger, MVT::i1, 0, 
/*41482*/       OPC_EmitInteger, MVT::i1, 1, 
/*41485*/       OPC_EmitInteger, MVT::i1, 0, 
/*41488*/       OPC_EmitInteger, MVT::i1, 0, 
/*41491*/       OPC_EmitInteger, MVT::i1, 0, 
/*41494*/       OPC_EmitInteger, MVT::i1, 0, 
/*41497*/       OPC_MorphNodeTo, TARGET_VAL(AMDGPU::IMAGE_SAMPLE_C_B_V4_V4), 0,
                    1/*#VTs*/, MVT::v4f32, 11/*#Ops*/, 3, 4, 5, 6, 7, 8, 9, 10, 0, 1, 2, 
                // Src: (SIsampleb:v4f32 v4i32:v4i32:$addr, v32i8:v32i8:$rsrc, i128:i128:$sampler, (imm:i32)<<P:Predicate_TEX_SHADOW_ARRAY>>) - Complexity = 7
                // Dst: (IMAGE_SAMPLE_C_B_V4_V4:v4f32 15:i32, 0:i1, 0:i1, 1:i1, 0:i1, 0:i1, 0:i1, 0:i1, ?:v4i32:$addr, ?:v32i8:$rsrc, ?:i128:$sampler)
/*41515*/     /*Scope*/ 45, /*->41561*/
/*41516*/       OPC_MoveParent,
/*41517*/       OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*41519*/       OPC_EmitInteger, MVT::i32, 15, 
/*41522*/       OPC_EmitInteger, MVT::i1, 0, 
/*41525*/       OPC_EmitInteger, MVT::i1, 0, 
/*41528*/       OPC_EmitInteger, MVT::i1, 0, 
/*41531*/       OPC_EmitInteger, MVT::i1, 0, 
/*41534*/       OPC_EmitInteger, MVT::i1, 0, 
/*41537*/       OPC_EmitInteger, MVT::i1, 0, 
/*41540*/       OPC_EmitInteger, MVT::i1, 0, 
/*41543*/       OPC_MorphNodeTo, TARGET_VAL(AMDGPU::IMAGE_SAMPLE_B_V4_V4), 0,
                    1/*#VTs*/, MVT::v4f32, 11/*#Ops*/, 3, 4, 5, 6, 7, 8, 9, 10, 0, 1, 2, 
                // Src: (SIsampleb:v4f32 v4i32:v4i32:$addr, v32i8:v32i8:$rsrc, i128:i128:$sampler, (imm:i32)) - Complexity = 6
                // Dst: (IMAGE_SAMPLE_B_V4_V4:v4f32 15:i32, 0:i1, 0:i1, 0:i1, 0:i1, 0:i1, 0:i1, 0:i1, ?:v4i32:$addr, ?:v32i8:$rsrc, ?:i128:$sampler)
/*41561*/     0, /*End of Scope*/
/*41562*/   /*Scope*/ 73|128,1/*201*/, /*->41765*/
/*41564*/     OPC_CheckChild0Type, MVT::v8i32,
/*41566*/     OPC_RecordChild1, // #1 = $rsrc
/*41567*/     OPC_RecordChild2, // #2 = $sampler
/*41568*/     OPC_MoveChild, 3,
/*41570*/     OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*41573*/     OPC_Scope, 47, /*->41622*/ // 4 children in Scope
/*41575*/       OPC_CheckPredicate, 42, // Predicate_TEX_ARRAY
/*41577*/       OPC_MoveParent,
/*41578*/       OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*41580*/       OPC_EmitInteger, MVT::i32, 15, 
/*41583*/       OPC_EmitInteger, MVT::i1, 0, 
/*41586*/       OPC_EmitInteger, MVT::i1, 0, 
/*41589*/       OPC_EmitInteger, MVT::i1, 1, 
/*41592*/       OPC_EmitInteger, MVT::i1, 0, 
/*41595*/       OPC_EmitInteger, MVT::i1, 0, 
/*41598*/       OPC_EmitInteger, MVT::i1, 0, 
/*41601*/       OPC_EmitInteger, MVT::i1, 0, 
/*41604*/       OPC_MorphNodeTo, TARGET_VAL(AMDGPU::IMAGE_SAMPLE_B_V4_V8), 0,
                    1/*#VTs*/, MVT::v4f32, 11/*#Ops*/, 3, 4, 5, 6, 7, 8, 9, 10, 0, 1, 2, 
                // Src: (SIsampleb:v4f32 v8i32:v8i32:$addr, v32i8:v32i8:$rsrc, i128:i128:$sampler, (imm:i32)<<P:Predicate_TEX_ARRAY>>) - Complexity = 7
                // Dst: (IMAGE_SAMPLE_B_V4_V8:v4f32 15:i32, 0:i1, 0:i1, 1:i1, 0:i1, 0:i1, 0:i1, 0:i1, ?:v8i32:$addr, ?:v32i8:$rsrc, ?:i128:$sampler)
/*41622*/     /*Scope*/ 47, /*->41670*/
/*41623*/       OPC_CheckPredicate, 45, // Predicate_TEX_SHADOW
/*41625*/       OPC_MoveParent,
/*41626*/       OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*41628*/       OPC_EmitInteger, MVT::i32, 15, 
/*41631*/       OPC_EmitInteger, MVT::i1, 0, 
/*41634*/       OPC_EmitInteger, MVT::i1, 0, 
/*41637*/       OPC_EmitInteger, MVT::i1, 0, 
/*41640*/       OPC_EmitInteger, MVT::i1, 0, 
/*41643*/       OPC_EmitInteger, MVT::i1, 0, 
/*41646*/       OPC_EmitInteger, MVT::i1, 0, 
/*41649*/       OPC_EmitInteger, MVT::i1, 0, 
/*41652*/       OPC_MorphNodeTo, TARGET_VAL(AMDGPU::IMAGE_SAMPLE_C_B_V4_V8), 0,
                    1/*#VTs*/, MVT::v4f32, 11/*#Ops*/, 3, 4, 5, 6, 7, 8, 9, 10, 0, 1, 2, 
                // Src: (SIsampleb:v4f32 v8i32:v8i32:$addr, v32i8:v32i8:$rsrc, i128:i128:$sampler, (imm:i32)<<P:Predicate_TEX_SHADOW>>) - Complexity = 7
                // Dst: (IMAGE_SAMPLE_C_B_V4_V8:v4f32 15:i32, 0:i1, 0:i1, 0:i1, 0:i1, 0:i1, 0:i1, 0:i1, ?:v8i32:$addr, ?:v32i8:$rsrc, ?:i128:$sampler)
/*41670*/     /*Scope*/ 47, /*->41718*/
/*41671*/       OPC_CheckPredicate, 75, // Predicate_TEX_SHADOW_ARRAY
/*41673*/       OPC_MoveParent,
/*41674*/       OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*41676*/       OPC_EmitInteger, MVT::i32, 15, 
/*41679*/       OPC_EmitInteger, MVT::i1, 0, 
/*41682*/       OPC_EmitInteger, MVT::i1, 0, 
/*41685*/       OPC_EmitInteger, MVT::i1, 1, 
/*41688*/       OPC_EmitInteger, MVT::i1, 0, 
/*41691*/       OPC_EmitInteger, MVT::i1, 0, 
/*41694*/       OPC_EmitInteger, MVT::i1, 0, 
/*41697*/       OPC_EmitInteger, MVT::i1, 0, 
/*41700*/       OPC_MorphNodeTo, TARGET_VAL(AMDGPU::IMAGE_SAMPLE_C_B_V4_V8), 0,
                    1/*#VTs*/, MVT::v4f32, 11/*#Ops*/, 3, 4, 5, 6, 7, 8, 9, 10, 0, 1, 2, 
                // Src: (SIsampleb:v4f32 v8i32:v8i32:$addr, v32i8:v32i8:$rsrc, i128:i128:$sampler, (imm:i32)<<P:Predicate_TEX_SHADOW_ARRAY>>) - Complexity = 7
                // Dst: (IMAGE_SAMPLE_C_B_V4_V8:v4f32 15:i32, 0:i1, 0:i1, 1:i1, 0:i1, 0:i1, 0:i1, 0:i1, ?:v8i32:$addr, ?:v32i8:$rsrc, ?:i128:$sampler)
/*41718*/     /*Scope*/ 45, /*->41764*/
/*41719*/       OPC_MoveParent,
/*41720*/       OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*41722*/       OPC_EmitInteger, MVT::i32, 15, 
/*41725*/       OPC_EmitInteger, MVT::i1, 0, 
/*41728*/       OPC_EmitInteger, MVT::i1, 0, 
/*41731*/       OPC_EmitInteger, MVT::i1, 0, 
/*41734*/       OPC_EmitInteger, MVT::i1, 0, 
/*41737*/       OPC_EmitInteger, MVT::i1, 0, 
/*41740*/       OPC_EmitInteger, MVT::i1, 0, 
/*41743*/       OPC_EmitInteger, MVT::i1, 0, 
/*41746*/       OPC_MorphNodeTo, TARGET_VAL(AMDGPU::IMAGE_SAMPLE_B_V4_V8), 0,
                    1/*#VTs*/, MVT::v4f32, 11/*#Ops*/, 3, 4, 5, 6, 7, 8, 9, 10, 0, 1, 2, 
                // Src: (SIsampleb:v4f32 v8i32:v8i32:$addr, v32i8:v32i8:$rsrc, i128:i128:$sampler, (imm:i32)) - Complexity = 6
                // Dst: (IMAGE_SAMPLE_B_V4_V8:v4f32 15:i32, 0:i1, 0:i1, 0:i1, 0:i1, 0:i1, 0:i1, 0:i1, ?:v8i32:$addr, ?:v32i8:$rsrc, ?:i128:$sampler)
/*41764*/     0, /*End of Scope*/
/*41765*/   /*Scope*/ 73|128,1/*201*/, /*->41968*/
/*41767*/     OPC_CheckChild0Type, MVT::v16i32,
/*41769*/     OPC_RecordChild1, // #1 = $rsrc
/*41770*/     OPC_RecordChild2, // #2 = $sampler
/*41771*/     OPC_MoveChild, 3,
/*41773*/     OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*41776*/     OPC_Scope, 47, /*->41825*/ // 4 children in Scope
/*41778*/       OPC_CheckPredicate, 42, // Predicate_TEX_ARRAY
/*41780*/       OPC_MoveParent,
/*41781*/       OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*41783*/       OPC_EmitInteger, MVT::i32, 15, 
/*41786*/       OPC_EmitInteger, MVT::i1, 0, 
/*41789*/       OPC_EmitInteger, MVT::i1, 0, 
/*41792*/       OPC_EmitInteger, MVT::i1, 1, 
/*41795*/       OPC_EmitInteger, MVT::i1, 0, 
/*41798*/       OPC_EmitInteger, MVT::i1, 0, 
/*41801*/       OPC_EmitInteger, MVT::i1, 0, 
/*41804*/       OPC_EmitInteger, MVT::i1, 0, 
/*41807*/       OPC_MorphNodeTo, TARGET_VAL(AMDGPU::IMAGE_SAMPLE_B_V4_V16), 0,
                    1/*#VTs*/, MVT::v4f32, 11/*#Ops*/, 3, 4, 5, 6, 7, 8, 9, 10, 0, 1, 2, 
                // Src: (SIsampleb:v4f32 v16i32:v16i32:$addr, v32i8:v32i8:$rsrc, i128:i128:$sampler, (imm:i32)<<P:Predicate_TEX_ARRAY>>) - Complexity = 7
                // Dst: (IMAGE_SAMPLE_B_V4_V16:v4f32 15:i32, 0:i1, 0:i1, 1:i1, 0:i1, 0:i1, 0:i1, 0:i1, ?:v16i32:$addr, ?:v32i8:$rsrc, ?:i128:$sampler)
/*41825*/     /*Scope*/ 47, /*->41873*/
/*41826*/       OPC_CheckPredicate, 45, // Predicate_TEX_SHADOW
/*41828*/       OPC_MoveParent,
/*41829*/       OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*41831*/       OPC_EmitInteger, MVT::i32, 15, 
/*41834*/       OPC_EmitInteger, MVT::i1, 0, 
/*41837*/       OPC_EmitInteger, MVT::i1, 0, 
/*41840*/       OPC_EmitInteger, MVT::i1, 0, 
/*41843*/       OPC_EmitInteger, MVT::i1, 0, 
/*41846*/       OPC_EmitInteger, MVT::i1, 0, 
/*41849*/       OPC_EmitInteger, MVT::i1, 0, 
/*41852*/       OPC_EmitInteger, MVT::i1, 0, 
/*41855*/       OPC_MorphNodeTo, TARGET_VAL(AMDGPU::IMAGE_SAMPLE_C_B_V4_V16), 0,
                    1/*#VTs*/, MVT::v4f32, 11/*#Ops*/, 3, 4, 5, 6, 7, 8, 9, 10, 0, 1, 2, 
                // Src: (SIsampleb:v4f32 v16i32:v16i32:$addr, v32i8:v32i8:$rsrc, i128:i128:$sampler, (imm:i32)<<P:Predicate_TEX_SHADOW>>) - Complexity = 7
                // Dst: (IMAGE_SAMPLE_C_B_V4_V16:v4f32 15:i32, 0:i1, 0:i1, 0:i1, 0:i1, 0:i1, 0:i1, 0:i1, ?:v16i32:$addr, ?:v32i8:$rsrc, ?:i128:$sampler)
/*41873*/     /*Scope*/ 47, /*->41921*/
/*41874*/       OPC_CheckPredicate, 75, // Predicate_TEX_SHADOW_ARRAY
/*41876*/       OPC_MoveParent,
/*41877*/       OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*41879*/       OPC_EmitInteger, MVT::i32, 15, 
/*41882*/       OPC_EmitInteger, MVT::i1, 0, 
/*41885*/       OPC_EmitInteger, MVT::i1, 0, 
/*41888*/       OPC_EmitInteger, MVT::i1, 1, 
/*41891*/       OPC_EmitInteger, MVT::i1, 0, 
/*41894*/       OPC_EmitInteger, MVT::i1, 0, 
/*41897*/       OPC_EmitInteger, MVT::i1, 0, 
/*41900*/       OPC_EmitInteger, MVT::i1, 0, 
/*41903*/       OPC_MorphNodeTo, TARGET_VAL(AMDGPU::IMAGE_SAMPLE_C_B_V4_V16), 0,
                    1/*#VTs*/, MVT::v4f32, 11/*#Ops*/, 3, 4, 5, 6, 7, 8, 9, 10, 0, 1, 2, 
                // Src: (SIsampleb:v4f32 v16i32:v16i32:$addr, v32i8:v32i8:$rsrc, i128:i128:$sampler, (imm:i32)<<P:Predicate_TEX_SHADOW_ARRAY>>) - Complexity = 7
                // Dst: (IMAGE_SAMPLE_C_B_V4_V16:v4f32 15:i32, 0:i1, 0:i1, 1:i1, 0:i1, 0:i1, 0:i1, 0:i1, ?:v16i32:$addr, ?:v32i8:$rsrc, ?:i128:$sampler)
/*41921*/     /*Scope*/ 45, /*->41967*/
/*41922*/       OPC_MoveParent,
/*41923*/       OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*41925*/       OPC_EmitInteger, MVT::i32, 15, 
/*41928*/       OPC_EmitInteger, MVT::i1, 0, 
/*41931*/       OPC_EmitInteger, MVT::i1, 0, 
/*41934*/       OPC_EmitInteger, MVT::i1, 0, 
/*41937*/       OPC_EmitInteger, MVT::i1, 0, 
/*41940*/       OPC_EmitInteger, MVT::i1, 0, 
/*41943*/       OPC_EmitInteger, MVT::i1, 0, 
/*41946*/       OPC_EmitInteger, MVT::i1, 0, 
/*41949*/       OPC_MorphNodeTo, TARGET_VAL(AMDGPU::IMAGE_SAMPLE_B_V4_V16), 0,
                    1/*#VTs*/, MVT::v4f32, 11/*#Ops*/, 3, 4, 5, 6, 7, 8, 9, 10, 0, 1, 2, 
                // Src: (SIsampleb:v4f32 v16i32:v16i32:$addr, v32i8:v32i8:$rsrc, i128:i128:$sampler, (imm:i32)) - Complexity = 6
                // Dst: (IMAGE_SAMPLE_B_V4_V16:v4f32 15:i32, 0:i1, 0:i1, 0:i1, 0:i1, 0:i1, 0:i1, 0:i1, ?:v16i32:$addr, ?:v32i8:$rsrc, ?:i128:$sampler)
/*41967*/     0, /*End of Scope*/
/*41968*/   0, /*End of Scope*/
/*41969*/ /*SwitchOpcode*/ 47|128,6/*815*/,  TARGET_VAL(AMDGPUISD::SAMPLED),// ->42788
/*41973*/   OPC_RecordChild0, // #0 = $addr
/*41974*/   OPC_Scope, 73|128,1/*201*/, /*->42178*/ // 4 children in Scope
/*41977*/     OPC_CheckChild0Type, MVT::v2i32,
/*41979*/     OPC_RecordChild1, // #1 = $rsrc
/*41980*/     OPC_RecordChild2, // #2 = $sampler
/*41981*/     OPC_MoveChild, 3,
/*41983*/     OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*41986*/     OPC_Scope, 47, /*->42035*/ // 4 children in Scope
/*41988*/       OPC_CheckPredicate, 42, // Predicate_TEX_ARRAY
/*41990*/       OPC_MoveParent,
/*41991*/       OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*41993*/       OPC_EmitInteger, MVT::i32, 15, 
/*41996*/       OPC_EmitInteger, MVT::i1, 0, 
/*41999*/       OPC_EmitInteger, MVT::i1, 0, 
/*42002*/       OPC_EmitInteger, MVT::i1, 1, 
/*42005*/       OPC_EmitInteger, MVT::i1, 0, 
/*42008*/       OPC_EmitInteger, MVT::i1, 0, 
/*42011*/       OPC_EmitInteger, MVT::i1, 0, 
/*42014*/       OPC_EmitInteger, MVT::i1, 0, 
/*42017*/       OPC_MorphNodeTo, TARGET_VAL(AMDGPU::IMAGE_SAMPLE_D_V4_V2), 0,
                    1/*#VTs*/, MVT::v4f32, 11/*#Ops*/, 3, 4, 5, 6, 7, 8, 9, 10, 0, 1, 2, 
                // Src: (SIsampled:v4f32 v2i32:v2i32:$addr, v32i8:v32i8:$rsrc, i128:i128:$sampler, (imm:i32)<<P:Predicate_TEX_ARRAY>>) - Complexity = 7
                // Dst: (IMAGE_SAMPLE_D_V4_V2:v4f32 15:i32, 0:i1, 0:i1, 1:i1, 0:i1, 0:i1, 0:i1, 0:i1, ?:v2i32:$addr, ?:v32i8:$rsrc, ?:i128:$sampler)
/*42035*/     /*Scope*/ 47, /*->42083*/
/*42036*/       OPC_CheckPredicate, 45, // Predicate_TEX_SHADOW
/*42038*/       OPC_MoveParent,
/*42039*/       OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*42041*/       OPC_EmitInteger, MVT::i32, 15, 
/*42044*/       OPC_EmitInteger, MVT::i1, 0, 
/*42047*/       OPC_EmitInteger, MVT::i1, 0, 
/*42050*/       OPC_EmitInteger, MVT::i1, 0, 
/*42053*/       OPC_EmitInteger, MVT::i1, 0, 
/*42056*/       OPC_EmitInteger, MVT::i1, 0, 
/*42059*/       OPC_EmitInteger, MVT::i1, 0, 
/*42062*/       OPC_EmitInteger, MVT::i1, 0, 
/*42065*/       OPC_MorphNodeTo, TARGET_VAL(AMDGPU::IMAGE_SAMPLE_C_D_V4_V2), 0,
                    1/*#VTs*/, MVT::v4f32, 11/*#Ops*/, 3, 4, 5, 6, 7, 8, 9, 10, 0, 1, 2, 
                // Src: (SIsampled:v4f32 v2i32:v2i32:$addr, v32i8:v32i8:$rsrc, i128:i128:$sampler, (imm:i32)<<P:Predicate_TEX_SHADOW>>) - Complexity = 7
                // Dst: (IMAGE_SAMPLE_C_D_V4_V2:v4f32 15:i32, 0:i1, 0:i1, 0:i1, 0:i1, 0:i1, 0:i1, 0:i1, ?:v2i32:$addr, ?:v32i8:$rsrc, ?:i128:$sampler)
/*42083*/     /*Scope*/ 47, /*->42131*/
/*42084*/       OPC_CheckPredicate, 75, // Predicate_TEX_SHADOW_ARRAY
/*42086*/       OPC_MoveParent,
/*42087*/       OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*42089*/       OPC_EmitInteger, MVT::i32, 15, 
/*42092*/       OPC_EmitInteger, MVT::i1, 0, 
/*42095*/       OPC_EmitInteger, MVT::i1, 0, 
/*42098*/       OPC_EmitInteger, MVT::i1, 1, 
/*42101*/       OPC_EmitInteger, MVT::i1, 0, 
/*42104*/       OPC_EmitInteger, MVT::i1, 0, 
/*42107*/       OPC_EmitInteger, MVT::i1, 0, 
/*42110*/       OPC_EmitInteger, MVT::i1, 0, 
/*42113*/       OPC_MorphNodeTo, TARGET_VAL(AMDGPU::IMAGE_SAMPLE_C_D_V4_V2), 0,
                    1/*#VTs*/, MVT::v4f32, 11/*#Ops*/, 3, 4, 5, 6, 7, 8, 9, 10, 0, 1, 2, 
                // Src: (SIsampled:v4f32 v2i32:v2i32:$addr, v32i8:v32i8:$rsrc, i128:i128:$sampler, (imm:i32)<<P:Predicate_TEX_SHADOW_ARRAY>>) - Complexity = 7
                // Dst: (IMAGE_SAMPLE_C_D_V4_V2:v4f32 15:i32, 0:i1, 0:i1, 1:i1, 0:i1, 0:i1, 0:i1, 0:i1, ?:v2i32:$addr, ?:v32i8:$rsrc, ?:i128:$sampler)
/*42131*/     /*Scope*/ 45, /*->42177*/
/*42132*/       OPC_MoveParent,
/*42133*/       OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*42135*/       OPC_EmitInteger, MVT::i32, 15, 
/*42138*/       OPC_EmitInteger, MVT::i1, 0, 
/*42141*/       OPC_EmitInteger, MVT::i1, 0, 
/*42144*/       OPC_EmitInteger, MVT::i1, 0, 
/*42147*/       OPC_EmitInteger, MVT::i1, 0, 
/*42150*/       OPC_EmitInteger, MVT::i1, 0, 
/*42153*/       OPC_EmitInteger, MVT::i1, 0, 
/*42156*/       OPC_EmitInteger, MVT::i1, 0, 
/*42159*/       OPC_MorphNodeTo, TARGET_VAL(AMDGPU::IMAGE_SAMPLE_D_V4_V2), 0,
                    1/*#VTs*/, MVT::v4f32, 11/*#Ops*/, 3, 4, 5, 6, 7, 8, 9, 10, 0, 1, 2, 
                // Src: (SIsampled:v4f32 v2i32:v2i32:$addr, v32i8:v32i8:$rsrc, i128:i128:$sampler, (imm:i32)) - Complexity = 6
                // Dst: (IMAGE_SAMPLE_D_V4_V2:v4f32 15:i32, 0:i1, 0:i1, 0:i1, 0:i1, 0:i1, 0:i1, 0:i1, ?:v2i32:$addr, ?:v32i8:$rsrc, ?:i128:$sampler)
/*42177*/     0, /*End of Scope*/
/*42178*/   /*Scope*/ 73|128,1/*201*/, /*->42381*/
/*42180*/     OPC_CheckChild0Type, MVT::v4i32,
/*42182*/     OPC_RecordChild1, // #1 = $rsrc
/*42183*/     OPC_RecordChild2, // #2 = $sampler
/*42184*/     OPC_MoveChild, 3,
/*42186*/     OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*42189*/     OPC_Scope, 47, /*->42238*/ // 4 children in Scope
/*42191*/       OPC_CheckPredicate, 42, // Predicate_TEX_ARRAY
/*42193*/       OPC_MoveParent,
/*42194*/       OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*42196*/       OPC_EmitInteger, MVT::i32, 15, 
/*42199*/       OPC_EmitInteger, MVT::i1, 0, 
/*42202*/       OPC_EmitInteger, MVT::i1, 0, 
/*42205*/       OPC_EmitInteger, MVT::i1, 1, 
/*42208*/       OPC_EmitInteger, MVT::i1, 0, 
/*42211*/       OPC_EmitInteger, MVT::i1, 0, 
/*42214*/       OPC_EmitInteger, MVT::i1, 0, 
/*42217*/       OPC_EmitInteger, MVT::i1, 0, 
/*42220*/       OPC_MorphNodeTo, TARGET_VAL(AMDGPU::IMAGE_SAMPLE_D_V4_V4), 0,
                    1/*#VTs*/, MVT::v4f32, 11/*#Ops*/, 3, 4, 5, 6, 7, 8, 9, 10, 0, 1, 2, 
                // Src: (SIsampled:v4f32 v4i32:v4i32:$addr, v32i8:v32i8:$rsrc, i128:i128:$sampler, (imm:i32)<<P:Predicate_TEX_ARRAY>>) - Complexity = 7
                // Dst: (IMAGE_SAMPLE_D_V4_V4:v4f32 15:i32, 0:i1, 0:i1, 1:i1, 0:i1, 0:i1, 0:i1, 0:i1, ?:v4i32:$addr, ?:v32i8:$rsrc, ?:i128:$sampler)
/*42238*/     /*Scope*/ 47, /*->42286*/
/*42239*/       OPC_CheckPredicate, 45, // Predicate_TEX_SHADOW
/*42241*/       OPC_MoveParent,
/*42242*/       OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*42244*/       OPC_EmitInteger, MVT::i32, 15, 
/*42247*/       OPC_EmitInteger, MVT::i1, 0, 
/*42250*/       OPC_EmitInteger, MVT::i1, 0, 
/*42253*/       OPC_EmitInteger, MVT::i1, 0, 
/*42256*/       OPC_EmitInteger, MVT::i1, 0, 
/*42259*/       OPC_EmitInteger, MVT::i1, 0, 
/*42262*/       OPC_EmitInteger, MVT::i1, 0, 
/*42265*/       OPC_EmitInteger, MVT::i1, 0, 
/*42268*/       OPC_MorphNodeTo, TARGET_VAL(AMDGPU::IMAGE_SAMPLE_C_D_V4_V4), 0,
                    1/*#VTs*/, MVT::v4f32, 11/*#Ops*/, 3, 4, 5, 6, 7, 8, 9, 10, 0, 1, 2, 
                // Src: (SIsampled:v4f32 v4i32:v4i32:$addr, v32i8:v32i8:$rsrc, i128:i128:$sampler, (imm:i32)<<P:Predicate_TEX_SHADOW>>) - Complexity = 7
                // Dst: (IMAGE_SAMPLE_C_D_V4_V4:v4f32 15:i32, 0:i1, 0:i1, 0:i1, 0:i1, 0:i1, 0:i1, 0:i1, ?:v4i32:$addr, ?:v32i8:$rsrc, ?:i128:$sampler)
/*42286*/     /*Scope*/ 47, /*->42334*/
/*42287*/       OPC_CheckPredicate, 75, // Predicate_TEX_SHADOW_ARRAY
/*42289*/       OPC_MoveParent,
/*42290*/       OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*42292*/       OPC_EmitInteger, MVT::i32, 15, 
/*42295*/       OPC_EmitInteger, MVT::i1, 0, 
/*42298*/       OPC_EmitInteger, MVT::i1, 0, 
/*42301*/       OPC_EmitInteger, MVT::i1, 1, 
/*42304*/       OPC_EmitInteger, MVT::i1, 0, 
/*42307*/       OPC_EmitInteger, MVT::i1, 0, 
/*42310*/       OPC_EmitInteger, MVT::i1, 0, 
/*42313*/       OPC_EmitInteger, MVT::i1, 0, 
/*42316*/       OPC_MorphNodeTo, TARGET_VAL(AMDGPU::IMAGE_SAMPLE_C_D_V4_V4), 0,
                    1/*#VTs*/, MVT::v4f32, 11/*#Ops*/, 3, 4, 5, 6, 7, 8, 9, 10, 0, 1, 2, 
                // Src: (SIsampled:v4f32 v4i32:v4i32:$addr, v32i8:v32i8:$rsrc, i128:i128:$sampler, (imm:i32)<<P:Predicate_TEX_SHADOW_ARRAY>>) - Complexity = 7
                // Dst: (IMAGE_SAMPLE_C_D_V4_V4:v4f32 15:i32, 0:i1, 0:i1, 1:i1, 0:i1, 0:i1, 0:i1, 0:i1, ?:v4i32:$addr, ?:v32i8:$rsrc, ?:i128:$sampler)
/*42334*/     /*Scope*/ 45, /*->42380*/
/*42335*/       OPC_MoveParent,
/*42336*/       OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*42338*/       OPC_EmitInteger, MVT::i32, 15, 
/*42341*/       OPC_EmitInteger, MVT::i1, 0, 
/*42344*/       OPC_EmitInteger, MVT::i1, 0, 
/*42347*/       OPC_EmitInteger, MVT::i1, 0, 
/*42350*/       OPC_EmitInteger, MVT::i1, 0, 
/*42353*/       OPC_EmitInteger, MVT::i1, 0, 
/*42356*/       OPC_EmitInteger, MVT::i1, 0, 
/*42359*/       OPC_EmitInteger, MVT::i1, 0, 
/*42362*/       OPC_MorphNodeTo, TARGET_VAL(AMDGPU::IMAGE_SAMPLE_D_V4_V4), 0,
                    1/*#VTs*/, MVT::v4f32, 11/*#Ops*/, 3, 4, 5, 6, 7, 8, 9, 10, 0, 1, 2, 
                // Src: (SIsampled:v4f32 v4i32:v4i32:$addr, v32i8:v32i8:$rsrc, i128:i128:$sampler, (imm:i32)) - Complexity = 6
                // Dst: (IMAGE_SAMPLE_D_V4_V4:v4f32 15:i32, 0:i1, 0:i1, 0:i1, 0:i1, 0:i1, 0:i1, 0:i1, ?:v4i32:$addr, ?:v32i8:$rsrc, ?:i128:$sampler)
/*42380*/     0, /*End of Scope*/
/*42381*/   /*Scope*/ 73|128,1/*201*/, /*->42584*/
/*42383*/     OPC_CheckChild0Type, MVT::v8i32,
/*42385*/     OPC_RecordChild1, // #1 = $rsrc
/*42386*/     OPC_RecordChild2, // #2 = $sampler
/*42387*/     OPC_MoveChild, 3,
/*42389*/     OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*42392*/     OPC_Scope, 47, /*->42441*/ // 4 children in Scope
/*42394*/       OPC_CheckPredicate, 42, // Predicate_TEX_ARRAY
/*42396*/       OPC_MoveParent,
/*42397*/       OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*42399*/       OPC_EmitInteger, MVT::i32, 15, 
/*42402*/       OPC_EmitInteger, MVT::i1, 0, 
/*42405*/       OPC_EmitInteger, MVT::i1, 0, 
/*42408*/       OPC_EmitInteger, MVT::i1, 1, 
/*42411*/       OPC_EmitInteger, MVT::i1, 0, 
/*42414*/       OPC_EmitInteger, MVT::i1, 0, 
/*42417*/       OPC_EmitInteger, MVT::i1, 0, 
/*42420*/       OPC_EmitInteger, MVT::i1, 0, 
/*42423*/       OPC_MorphNodeTo, TARGET_VAL(AMDGPU::IMAGE_SAMPLE_D_V4_V8), 0,
                    1/*#VTs*/, MVT::v4f32, 11/*#Ops*/, 3, 4, 5, 6, 7, 8, 9, 10, 0, 1, 2, 
                // Src: (SIsampled:v4f32 v8i32:v8i32:$addr, v32i8:v32i8:$rsrc, i128:i128:$sampler, (imm:i32)<<P:Predicate_TEX_ARRAY>>) - Complexity = 7
                // Dst: (IMAGE_SAMPLE_D_V4_V8:v4f32 15:i32, 0:i1, 0:i1, 1:i1, 0:i1, 0:i1, 0:i1, 0:i1, ?:v8i32:$addr, ?:v32i8:$rsrc, ?:i128:$sampler)
/*42441*/     /*Scope*/ 47, /*->42489*/
/*42442*/       OPC_CheckPredicate, 45, // Predicate_TEX_SHADOW
/*42444*/       OPC_MoveParent,
/*42445*/       OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*42447*/       OPC_EmitInteger, MVT::i32, 15, 
/*42450*/       OPC_EmitInteger, MVT::i1, 0, 
/*42453*/       OPC_EmitInteger, MVT::i1, 0, 
/*42456*/       OPC_EmitInteger, MVT::i1, 0, 
/*42459*/       OPC_EmitInteger, MVT::i1, 0, 
/*42462*/       OPC_EmitInteger, MVT::i1, 0, 
/*42465*/       OPC_EmitInteger, MVT::i1, 0, 
/*42468*/       OPC_EmitInteger, MVT::i1, 0, 
/*42471*/       OPC_MorphNodeTo, TARGET_VAL(AMDGPU::IMAGE_SAMPLE_C_D_V4_V8), 0,
                    1/*#VTs*/, MVT::v4f32, 11/*#Ops*/, 3, 4, 5, 6, 7, 8, 9, 10, 0, 1, 2, 
                // Src: (SIsampled:v4f32 v8i32:v8i32:$addr, v32i8:v32i8:$rsrc, i128:i128:$sampler, (imm:i32)<<P:Predicate_TEX_SHADOW>>) - Complexity = 7
                // Dst: (IMAGE_SAMPLE_C_D_V4_V8:v4f32 15:i32, 0:i1, 0:i1, 0:i1, 0:i1, 0:i1, 0:i1, 0:i1, ?:v8i32:$addr, ?:v32i8:$rsrc, ?:i128:$sampler)
/*42489*/     /*Scope*/ 47, /*->42537*/
/*42490*/       OPC_CheckPredicate, 75, // Predicate_TEX_SHADOW_ARRAY
/*42492*/       OPC_MoveParent,
/*42493*/       OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*42495*/       OPC_EmitInteger, MVT::i32, 15, 
/*42498*/       OPC_EmitInteger, MVT::i1, 0, 
/*42501*/       OPC_EmitInteger, MVT::i1, 0, 
/*42504*/       OPC_EmitInteger, MVT::i1, 1, 
/*42507*/       OPC_EmitInteger, MVT::i1, 0, 
/*42510*/       OPC_EmitInteger, MVT::i1, 0, 
/*42513*/       OPC_EmitInteger, MVT::i1, 0, 
/*42516*/       OPC_EmitInteger, MVT::i1, 0, 
/*42519*/       OPC_MorphNodeTo, TARGET_VAL(AMDGPU::IMAGE_SAMPLE_C_D_V4_V8), 0,
                    1/*#VTs*/, MVT::v4f32, 11/*#Ops*/, 3, 4, 5, 6, 7, 8, 9, 10, 0, 1, 2, 
                // Src: (SIsampled:v4f32 v8i32:v8i32:$addr, v32i8:v32i8:$rsrc, i128:i128:$sampler, (imm:i32)<<P:Predicate_TEX_SHADOW_ARRAY>>) - Complexity = 7
                // Dst: (IMAGE_SAMPLE_C_D_V4_V8:v4f32 15:i32, 0:i1, 0:i1, 1:i1, 0:i1, 0:i1, 0:i1, 0:i1, ?:v8i32:$addr, ?:v32i8:$rsrc, ?:i128:$sampler)
/*42537*/     /*Scope*/ 45, /*->42583*/
/*42538*/       OPC_MoveParent,
/*42539*/       OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*42541*/       OPC_EmitInteger, MVT::i32, 15, 
/*42544*/       OPC_EmitInteger, MVT::i1, 0, 
/*42547*/       OPC_EmitInteger, MVT::i1, 0, 
/*42550*/       OPC_EmitInteger, MVT::i1, 0, 
/*42553*/       OPC_EmitInteger, MVT::i1, 0, 
/*42556*/       OPC_EmitInteger, MVT::i1, 0, 
/*42559*/       OPC_EmitInteger, MVT::i1, 0, 
/*42562*/       OPC_EmitInteger, MVT::i1, 0, 
/*42565*/       OPC_MorphNodeTo, TARGET_VAL(AMDGPU::IMAGE_SAMPLE_D_V4_V8), 0,
                    1/*#VTs*/, MVT::v4f32, 11/*#Ops*/, 3, 4, 5, 6, 7, 8, 9, 10, 0, 1, 2, 
                // Src: (SIsampled:v4f32 v8i32:v8i32:$addr, v32i8:v32i8:$rsrc, i128:i128:$sampler, (imm:i32)) - Complexity = 6
                // Dst: (IMAGE_SAMPLE_D_V4_V8:v4f32 15:i32, 0:i1, 0:i1, 0:i1, 0:i1, 0:i1, 0:i1, 0:i1, ?:v8i32:$addr, ?:v32i8:$rsrc, ?:i128:$sampler)
/*42583*/     0, /*End of Scope*/
/*42584*/   /*Scope*/ 73|128,1/*201*/, /*->42787*/
/*42586*/     OPC_CheckChild0Type, MVT::v16i32,
/*42588*/     OPC_RecordChild1, // #1 = $rsrc
/*42589*/     OPC_RecordChild2, // #2 = $sampler
/*42590*/     OPC_MoveChild, 3,
/*42592*/     OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*42595*/     OPC_Scope, 47, /*->42644*/ // 4 children in Scope
/*42597*/       OPC_CheckPredicate, 42, // Predicate_TEX_ARRAY
/*42599*/       OPC_MoveParent,
/*42600*/       OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*42602*/       OPC_EmitInteger, MVT::i32, 15, 
/*42605*/       OPC_EmitInteger, MVT::i1, 0, 
/*42608*/       OPC_EmitInteger, MVT::i1, 0, 
/*42611*/       OPC_EmitInteger, MVT::i1, 1, 
/*42614*/       OPC_EmitInteger, MVT::i1, 0, 
/*42617*/       OPC_EmitInteger, MVT::i1, 0, 
/*42620*/       OPC_EmitInteger, MVT::i1, 0, 
/*42623*/       OPC_EmitInteger, MVT::i1, 0, 
/*42626*/       OPC_MorphNodeTo, TARGET_VAL(AMDGPU::IMAGE_SAMPLE_D_V4_V16), 0,
                    1/*#VTs*/, MVT::v4f32, 11/*#Ops*/, 3, 4, 5, 6, 7, 8, 9, 10, 0, 1, 2, 
                // Src: (SIsampled:v4f32 v16i32:v16i32:$addr, v32i8:v32i8:$rsrc, i128:i128:$sampler, (imm:i32)<<P:Predicate_TEX_ARRAY>>) - Complexity = 7
                // Dst: (IMAGE_SAMPLE_D_V4_V16:v4f32 15:i32, 0:i1, 0:i1, 1:i1, 0:i1, 0:i1, 0:i1, 0:i1, ?:v16i32:$addr, ?:v32i8:$rsrc, ?:i128:$sampler)
/*42644*/     /*Scope*/ 47, /*->42692*/
/*42645*/       OPC_CheckPredicate, 45, // Predicate_TEX_SHADOW
/*42647*/       OPC_MoveParent,
/*42648*/       OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*42650*/       OPC_EmitInteger, MVT::i32, 15, 
/*42653*/       OPC_EmitInteger, MVT::i1, 0, 
/*42656*/       OPC_EmitInteger, MVT::i1, 0, 
/*42659*/       OPC_EmitInteger, MVT::i1, 0, 
/*42662*/       OPC_EmitInteger, MVT::i1, 0, 
/*42665*/       OPC_EmitInteger, MVT::i1, 0, 
/*42668*/       OPC_EmitInteger, MVT::i1, 0, 
/*42671*/       OPC_EmitInteger, MVT::i1, 0, 
/*42674*/       OPC_MorphNodeTo, TARGET_VAL(AMDGPU::IMAGE_SAMPLE_C_D_V4_V16), 0,
                    1/*#VTs*/, MVT::v4f32, 11/*#Ops*/, 3, 4, 5, 6, 7, 8, 9, 10, 0, 1, 2, 
                // Src: (SIsampled:v4f32 v16i32:v16i32:$addr, v32i8:v32i8:$rsrc, i128:i128:$sampler, (imm:i32)<<P:Predicate_TEX_SHADOW>>) - Complexity = 7
                // Dst: (IMAGE_SAMPLE_C_D_V4_V16:v4f32 15:i32, 0:i1, 0:i1, 0:i1, 0:i1, 0:i1, 0:i1, 0:i1, ?:v16i32:$addr, ?:v32i8:$rsrc, ?:i128:$sampler)
/*42692*/     /*Scope*/ 47, /*->42740*/
/*42693*/       OPC_CheckPredicate, 75, // Predicate_TEX_SHADOW_ARRAY
/*42695*/       OPC_MoveParent,
/*42696*/       OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*42698*/       OPC_EmitInteger, MVT::i32, 15, 
/*42701*/       OPC_EmitInteger, MVT::i1, 0, 
/*42704*/       OPC_EmitInteger, MVT::i1, 0, 
/*42707*/       OPC_EmitInteger, MVT::i1, 1, 
/*42710*/       OPC_EmitInteger, MVT::i1, 0, 
/*42713*/       OPC_EmitInteger, MVT::i1, 0, 
/*42716*/       OPC_EmitInteger, MVT::i1, 0, 
/*42719*/       OPC_EmitInteger, MVT::i1, 0, 
/*42722*/       OPC_MorphNodeTo, TARGET_VAL(AMDGPU::IMAGE_SAMPLE_C_D_V4_V16), 0,
                    1/*#VTs*/, MVT::v4f32, 11/*#Ops*/, 3, 4, 5, 6, 7, 8, 9, 10, 0, 1, 2, 
                // Src: (SIsampled:v4f32 v16i32:v16i32:$addr, v32i8:v32i8:$rsrc, i128:i128:$sampler, (imm:i32)<<P:Predicate_TEX_SHADOW_ARRAY>>) - Complexity = 7
                // Dst: (IMAGE_SAMPLE_C_D_V4_V16:v4f32 15:i32, 0:i1, 0:i1, 1:i1, 0:i1, 0:i1, 0:i1, 0:i1, ?:v16i32:$addr, ?:v32i8:$rsrc, ?:i128:$sampler)
/*42740*/     /*Scope*/ 45, /*->42786*/
/*42741*/       OPC_MoveParent,
/*42742*/       OPC_CheckPatternPredicate, 0, // (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS)
/*42744*/       OPC_EmitInteger, MVT::i32, 15, 
/*42747*/       OPC_EmitInteger, MVT::i1, 0, 
/*42750*/       OPC_EmitInteger, MVT::i1, 0, 
/*42753*/       OPC_EmitInteger, MVT::i1, 0, 
/*42756*/       OPC_EmitInteger, MVT::i1, 0, 
/*42759*/       OPC_EmitInteger, MVT::i1, 0, 
/*42762*/       OPC_EmitInteger, MVT::i1, 0, 
/*42765*/       OPC_EmitInteger, MVT::i1, 0, 
/*42768*/       OPC_MorphNodeTo, TARGET_VAL(AMDGPU::IMAGE_SAMPLE_D_V4_V16), 0,
                    1/*#VTs*/, MVT::v4f32, 11/*#Ops*/, 3, 4, 5, 6, 7, 8, 9, 10, 0, 1, 2, 
                // Src: (SIsampled:v4f32 v16i32:v16i32:$addr, v32i8:v32i8:$rsrc, i128:i128:$sampler, (imm:i32)) - Complexity = 6
                // Dst: (IMAGE_SAMPLE_D_V4_V16:v4f32 15:i32, 0:i1, 0:i1, 0:i1, 0:i1, 0:i1, 0:i1, 0:i1, ?:v16i32:$addr, ?:v32i8:$rsrc, ?:i128:$sampler)
/*42786*/     0, /*End of Scope*/
/*42787*/   0, /*End of Scope*/
/*42788*/ 0, // EndSwitchOpcode
    0
  }; // Total Array size is 42790 bytes

  // Opcode Histogram:
  // #OPC_Scope                          = 283
  // #OPC_RecordNode                     = 164
  // #OPC_RecordChild                    = 475
  // #OPC_RecordMemRef                   = 7
  // #OPC_CaptureGlueInput               = 3
  // #OPC_MoveChild                      = 400
  // #OPC_MoveParent                     = 727
  // #OPC_CheckSame                      = 0
  // #OPC_CheckChildSame                 = 84
  // #OPC_CheckPatternPredicate          = 781
  // #OPC_CheckPredicate                 = 358
  // #OPC_CheckOpcode                    = 366
  // #OPC_SwitchOpcode                   = 1
  // #OPC_CheckType                      = 512
  // #OPC_SwitchType                     = 55
  // #OPC_CheckChildType                 = 119
  // #OPC_CheckInteger                   = 166
  // #OPC_CheckCondCode                  = 11
  // #OPC_CheckValueType                 = 0
  // #OPC_CheckComplexPat                = 49
  // #OPC_CheckAndImm                    = 0
  // #OPC_CheckOrImm                     = 0
  // #OPC_CheckFoldableChainNode         = 0
  // #OPC_EmitInteger                    = 4288
  // #OPC_EmitStringInteger              = 199
  // #OPC_EmitRegister                   = 225
  // #OPC_EmitConvertToTarget            = 279
  // #OPC_EmitMergeInputChains           = 166
  // #OPC_EmitCopyToReg                  = 0
  // #OPC_EmitNode                       = 234
  // #OPC_EmitNodeXForm                  = 55
  // #OPC_MarkGlueResults                = 0
  // #OPC_CompleteMatch                  = 24
  // #OPC_MorphNodeTo                    = 772

  #undef TARGET_VAL
  return SelectCodeCommon(N, MatcherTable,sizeof(MatcherTable));
}

virtual bool CheckPatternPredicate(unsigned PredNo) const {
  switch (PredNo) {
  default: llvm_unreachable("Invalid predicate in table?");
  case 0: return (Subtarget.getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS);
  case 1: return (Subtarget.getGeneration() <= AMDGPUSubtarget::R700);
  case 2: return (Subtarget.getGeneration() == AMDGPUSubtarget::EVERGREEN|| Subtarget.getGeneration() ==AMDGPUSubtarget::NORTHERN_ISLANDS);
  case 3: return (Subtarget.getGeneration() <= AMDGPUSubtarget::NORTHERN_ISLANDS);
  case 4: return (Subtarget.hasCaymanISA());
  case 5: return (Subtarget.getGeneration() >= AMDGPUSubtarget::EVERGREEN && Subtarget.getGeneration() < AMDGPUSubtarget::SOUTHERN_ISLANDS && !Subtarget.hasCaymanISA());
  case 6: return (Subtarget.getGeneration() == AMDGPUSubtarget::R700);
  }
}

virtual bool CheckNodePredicate(SDNode *Node,
                                unsigned PredNo) const {
  switch (PredNo) {
  default: llvm_unreachable("Invalid predicate in table?");
  case 0: { // Predicate_legalshift32
    int64_t Imm = cast<ConstantSDNode>(Node)->getSExtValue();
return Imm >=0 && Imm < 32;
  }
  case 1: { // Predicate_bfemask
    ConstantSDNode*N = cast<ConstantSDNode>(Node);
return isMask_32(N->getZExtValue());
  }
  case 2: { // Predicate_COND_OEQ
    CondCodeSDNode*N = cast<CondCodeSDNode>(Node);
return N->get() == ISD::SETOEQ || N->get() == ISD::SETEQ;
  }
  case 3: { // Predicate_COND_OGT
    CondCodeSDNode*N = cast<CondCodeSDNode>(Node);
return N->get() == ISD::SETOGT || N->get() == ISD::SETGT;
  }
  case 4: { // Predicate_COND_OGE
    CondCodeSDNode*N = cast<CondCodeSDNode>(Node);
return N->get() == ISD::SETOGE || N->get() == ISD::SETGE;
  }
  case 5: { // Predicate_COND_UNE
    CondCodeSDNode*N = cast<CondCodeSDNode>(Node);
return N->get() == ISD::SETUNE || N->get() == ISD::SETNE;
  }
  case 6: { // Predicate_FP_ONE
    ConstantFPSDNode*N = cast<ConstantFPSDNode>(Node);
return N->isExactlyValue(1.0);
  }
  case 7: { // Predicate_FP_ZERO
    ConstantFPSDNode*N = cast<ConstantFPSDNode>(Node);
return N->getValueAPF().isZero();
  }
  case 8: { // Predicate_COND_EQ
    CondCodeSDNode*N = cast<CondCodeSDNode>(Node);
return N->get() == ISD::SETEQ || N->get() == ISD::SETUEQ;
  }
  case 9: { // Predicate_COND_SGE
    CondCodeSDNode*N = cast<CondCodeSDNode>(Node);
return N->get() == ISD::SETGE;
  }
  case 10: { // Predicate_COND_SGT
    CondCodeSDNode*N = cast<CondCodeSDNode>(Node);
return N->get() == ISD::SETGT;
  }
  case 11: { // Predicate_unindexedload
    SDNode *N = Node;

  return cast<LoadSDNode>(N)->getAddressingMode() == ISD::UNINDEXED;

  }
  case 12: { // Predicate_az_extload
    SDNode *N = Node;

  LoadSDNode *L = cast<LoadSDNode>(N);
  return L->getExtensionType() == ISD::ZEXTLOAD ||
         L->getExtensionType() == ISD::EXTLOAD;

  }
  case 13: { // Predicate_az_extloadi8
    SDNode *N = Node;

  return cast<LoadSDNode>(N)->getMemoryVT() == MVT::i8;

  }
  case 14: { // Predicate_load_param_exti8
    SDNode *N = Node;
 return isConstantLoad(dyn_cast<LoadSDNode>(N), 0); 
  }
  case 15: { // Predicate_az_extloadi16
    SDNode *N = Node;

  return cast<LoadSDNode>(N)->getMemoryVT() == MVT::i16;

  }
  case 16: { // Predicate_load_param_exti16
    SDNode *N = Node;
 return isConstantLoad(dyn_cast<LoadSDNode>(N), 0); 
  }
  case 17: { // Predicate_load
    SDNode *N = Node;

  return cast<LoadSDNode>(N)->getExtensionType() == ISD::NON_EXTLOAD;

  }
  case 18: { // Predicate_load_param
    SDNode *N = Node;
 return isConstantLoad(dyn_cast<LoadSDNode>(N), 0); 
  }
  case 19: { // Predicate_az_extloadi8_global
    SDNode *N = Node;

    return isGlobalLoad(dyn_cast<LoadSDNode>(N));

  }
  case 20: { // Predicate_az_extloadi16_global
    SDNode *N = Node;

    return isGlobalLoad(dyn_cast<LoadSDNode>(N));

  }
  case 21: { // Predicate_global_load
    SDNode *N = Node;

    return isGlobalLoad(dyn_cast<LoadSDNode>(N));

  }
  case 22: { // Predicate_IMM8bitDWORD
    int64_t Imm = cast<ConstantSDNode>(Node)->getSExtValue();

    return (Imm & ~0x3FC) == 0;
  
  }
  case 23: { // Predicate_constant_load
    SDNode *N = Node;

    return isConstantLoad(dyn_cast<LoadSDNode>(N), -1);

  }
  case 24: { // Predicate_IMM12bit
    ConstantSDNode*N = cast<ConstantSDNode>(Node);
return isUInt<12>(N->getZExtValue());
  }
  case 25: { // Predicate_sextload
    SDNode *N = Node;

  return cast<LoadSDNode>(N)->getExtensionType() == ISD::SEXTLOAD;

  }
  case 26: { // Predicate_sextloadi8
    SDNode *N = Node;

  return cast<LoadSDNode>(N)->getMemoryVT() == MVT::i8;

  }
  case 27: { // Predicate_sextloadi8_global
    SDNode *N = Node;

    return isGlobalLoad(dyn_cast<LoadSDNode>(N));

  }
  case 28: { // Predicate_sextloadi16
    SDNode *N = Node;

  return cast<LoadSDNode>(N)->getMemoryVT() == MVT::i16;

  }
  case 29: { // Predicate_sextloadi16_global
    SDNode *N = Node;

    return isGlobalLoad(dyn_cast<LoadSDNode>(N));

  }
  case 30: { // Predicate_az_extloadi32
    SDNode *N = Node;

  return cast<LoadSDNode>(N)->getMemoryVT() == MVT::i32;

  }
  case 31: { // Predicate_az_extloadi32_global
    SDNode *N = Node;

  return isGlobalLoad(dyn_cast<LoadSDNode>(N));

  }
  case 32: { // Predicate_sextloadi8_constant
    SDNode *N = Node;

    return isConstantLoad(dyn_cast<LoadSDNode>(N), -1);

  }
  case 33: { // Predicate_az_extloadi8_constant
    SDNode *N = Node;

    return isConstantLoad(dyn_cast<LoadSDNode>(N), -1);

  }
  case 34: { // Predicate_sextloadi16_constant
    SDNode *N = Node;

    return isConstantLoad(dyn_cast<LoadSDNode>(N), -1);

  }
  case 35: { // Predicate_az_extloadi16_constant
    SDNode *N = Node;

    return isConstantLoad(dyn_cast<LoadSDNode>(N), -1);

  }
  case 36: { // Predicate_az_extloadi32_constant
    SDNode *N = Node;

  return isConstantLoad(dyn_cast<LoadSDNode>(N), -1);

  }
  case 37: { // Predicate_sextloadi8_local
    SDNode *N = Node;

    return isLocalLoad(dyn_cast<LoadSDNode>(N));

  }
  case 38: { // Predicate_az_extloadi8_local
    SDNode *N = Node;

    return isLocalLoad(dyn_cast<LoadSDNode>(N));

  }
  case 39: { // Predicate_sextloadi16_local
    SDNode *N = Node;

    return isLocalLoad(dyn_cast<LoadSDNode>(N));

  }
  case 40: { // Predicate_az_extloadi16_local
    SDNode *N = Node;

    return isLocalLoad(dyn_cast<LoadSDNode>(N));

  }
  case 41: { // Predicate_local_load
    SDNode *N = Node;

    return isLocalLoad(dyn_cast<LoadSDNode>(N));

  }
  case 42: { // Predicate_TEX_ARRAY
    ConstantSDNode*N = cast<ConstantSDNode>(Node);
uint32_t TType = (uint32_t)N->getZExtValue();
    return TType == 9 || TType == 10 || TType == 16;
  
  }
  case 43: { // Predicate_TEX_MSAA
    ConstantSDNode*N = cast<ConstantSDNode>(Node);
uint32_t TType = (uint32_t)N->getZExtValue();
    return TType == 14;
  
  }
  case 44: { // Predicate_TEX_ARRAY_MSAA
    ConstantSDNode*N = cast<ConstantSDNode>(Node);
uint32_t TType = (uint32_t)N->getZExtValue();
    return TType == 15;
  
  }
  case 45: { // Predicate_TEX_SHADOW
    ConstantSDNode*N = cast<ConstantSDNode>(Node);
uint32_t TType = (uint32_t)N->getZExtValue();
    return (TType >= 6 && TType <= 8) || (TType >= 11 && TType <= 13);
  
  }
  case 46: { // Predicate_unindexedstore
    SDNode *N = Node;

  return cast<StoreSDNode>(N)->getAddressingMode() == ISD::UNINDEXED;

  }
  case 47: { // Predicate_truncstore
    SDNode *N = Node;

  return cast<StoreSDNode>(N)->isTruncatingStore();

  }
  case 48: { // Predicate_truncstorei8
    SDNode *N = Node;

  return cast<StoreSDNode>(N)->getMemoryVT() == MVT::i8;

  }
  case 49: { // Predicate_truncstorei8_global
    SDNode *N = Node;

  return isGlobalStore(dyn_cast<StoreSDNode>(N));

  }
  case 50: { // Predicate_truncstorei16
    SDNode *N = Node;

  return cast<StoreSDNode>(N)->getMemoryVT() == MVT::i16;

  }
  case 51: { // Predicate_truncstorei16_global
    SDNode *N = Node;

  return isGlobalStore(dyn_cast<StoreSDNode>(N));

  }
  case 52: { // Predicate_store
    SDNode *N = Node;

  return !cast<StoreSDNode>(N)->isTruncatingStore();

  }
  case 53: { // Predicate_global_store
    SDNode *N = Node;

        return isGlobalStore(dyn_cast<StoreSDNode>(N));

  }
  case 54: { // Predicate_local_store
    SDNode *N = Node;

  return isLocalStore(dyn_cast<StoreSDNode>(N));

  }
  case 55: { // Predicate_truncstorei8_local
    SDNode *N = Node;

  return isLocalStore(dyn_cast<StoreSDNode>(N));

  }
  case 56: { // Predicate_truncstorei16_local
    SDNode *N = Node;

  return isLocalStore(dyn_cast<StoreSDNode>(N));

  }
  case 57: { // Predicate_mskor_global
    SDNode *N = Node;

  return dyn_cast<MemSDNode>(N)->getAddressSpace() == AMDGPUAS::GLOBAL_ADDRESS;

  }
  case 58: { // Predicate_anonymous.val.460
    ConstantSDNode*N = cast<ConstantSDNode>(Node);

  if (TM.getSubtarget<AMDGPUSubtarget>().getGeneration() <
      AMDGPUSubtarget::SOUTHERN_ISLANDS) {
    return false;
  }
  const SIRegisterInfo *SIRI =
                       static_cast<const SIRegisterInfo*>(TM.getRegisterInfo());
  for (SDNode::use_iterator U = N->use_begin(), E = SDNode::use_end();
                                                U != E; ++U) {
    if (SIRI->isSGPRClass(getOperandRegClass(*U, U.getOperandNo()))) {
      return true;
    }
  }
  return false;

  }
  case 59: { // Predicate_anonymous.val.462
    ConstantSDNode*N = cast<ConstantSDNode>(Node);

  return
    (*(const SITargetLowering *)getTargetLowering()).analyzeImmediate(N) == 0;

  }
  case 60: { // Predicate_atomic_load_add_local
    SDNode *N = Node;

  return dyn_cast<MemSDNode>(N)->getAddressSpace() == AMDGPUAS::LOCAL_ADDRESS;

  }
  case 61: { // Predicate_atomic_load_sub_local
    SDNode *N = Node;

  return dyn_cast<MemSDNode>(N)->getAddressSpace() == AMDGPUAS::LOCAL_ADDRESS;

  }
  case 62: { // Predicate_COND_OLT
    CondCodeSDNode*N = cast<CondCodeSDNode>(Node);
return N->get() == ISD::SETOLT || N->get() == ISD::SETLT;
  }
  case 63: { // Predicate_COND_OLE
    CondCodeSDNode*N = cast<CondCodeSDNode>(Node);
return N->get() == ISD::SETOLE || N->get() == ISD::SETLE;
  }
  case 64: { // Predicate_COND_O
    CondCodeSDNode*N = cast<CondCodeSDNode>(Node);
return N->get() == ISD::SETO;
  }
  case 65: { // Predicate_COND_UO
    CondCodeSDNode*N = cast<CondCodeSDNode>(Node);
return N->get() == ISD::SETUO;
  }
  case 66: { // Predicate_COND_SLT
    CondCodeSDNode*N = cast<CondCodeSDNode>(Node);
return N->get() == ISD::SETLT;
  }
  case 67: { // Predicate_COND_SLE
    CondCodeSDNode*N = cast<CondCodeSDNode>(Node);
return N->get() == ISD::SETLE;
  }
  case 68: { // Predicate_COND_NE
    CondCodeSDNode*N = cast<CondCodeSDNode>(Node);
return N->get() == ISD::SETNE || N->get() == ISD::SETUNE;
  }
  case 69: { // Predicate_COND_ULT
    CondCodeSDNode*N = cast<CondCodeSDNode>(Node);
return N->get() == ISD::SETULT;
  }
  case 70: { // Predicate_COND_ULE
    CondCodeSDNode*N = cast<CondCodeSDNode>(Node);
return N->get() == ISD::SETULE;
  }
  case 71: { // Predicate_COND_UGT
    CondCodeSDNode*N = cast<CondCodeSDNode>(Node);
return N->get() == ISD::SETUGT;
  }
  case 72: { // Predicate_COND_UGE
    CondCodeSDNode*N = cast<CondCodeSDNode>(Node);
return N->get() == ISD::SETUGE;
  }
  case 73: { // Predicate_anonymous.val.461
    ConstantFPSDNode*N = cast<ConstantFPSDNode>(Node);

  if (TM.getSubtarget<AMDGPUSubtarget>().getGeneration() <
      AMDGPUSubtarget::SOUTHERN_ISLANDS) {
    return false;
  }
  const SIRegisterInfo *SIRI =
                       static_cast<const SIRegisterInfo*>(TM.getRegisterInfo());
  for (SDNode::use_iterator U = N->use_begin(), E = SDNode::use_end();
                                                U != E; ++U) {
    if (SIRI->isSGPRClass(getOperandRegClass(*U, U.getOperandNo()))) {
      return true;
    }
  }
  return false;

  }
  case 74: { // Predicate_TEX_RECT
    ConstantSDNode*N = cast<ConstantSDNode>(Node);
uint32_t TType = (uint32_t)N->getZExtValue();
    return TType == 5;
  
  }
  case 75: { // Predicate_TEX_SHADOW_ARRAY
    ConstantSDNode*N = cast<ConstantSDNode>(Node);
uint32_t TType = (uint32_t)N->getZExtValue();
    return TType == 11 || TType == 12 || TType == 17;
  
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
    Result.resize(NextRes+1);
    return SelectU24(N, Result[NextRes+0].first);
  case 1:
    Result.resize(NextRes+1);
    return SelectI24(N, Result[NextRes+0].first);
  case 2:
    Result.resize(NextRes+2);
    return SelectADDRIndirect(N, Result[NextRes+0].first, Result[NextRes+1].first);
  case 3:
    Result.resize(NextRes+2);
    return SelectADDRVTX_READ(N, Result[NextRes+0].first, Result[NextRes+1].first);
  case 4:
    Result.resize(NextRes+1);
    return SelectGlobalValueConstantOffset(N, Result[NextRes+0].first);
  case 5:
    Result.resize(NextRes+2);
    return SelectGlobalValueVariableOffset(N, Result[NextRes+0].first, Result[NextRes+1].first);
  }
}

virtual SDValue RunSDNodeXForm(SDValue V, unsigned XFormNo) {
  switch (XFormNo) {
  default: llvm_unreachable("Invalid xform # in table?");
  case 0: {  // as_i16imm
    ConstantSDNode *N = cast<ConstantSDNode>(V.getNode());

  return CurDAG->getTargetConstant(N->getSExtValue(), MVT::i16);

  }
  case 1: {  // as_i1imm
    ConstantSDNode *N = cast<ConstantSDNode>(V.getNode());

  return CurDAG->getTargetConstant(N->getZExtValue(), MVT::i1);

  }
  case 2: {  // as_i8imm
    ConstantSDNode *N = cast<ConstantSDNode>(V.getNode());

  return CurDAG->getTargetConstant(N->getZExtValue(), MVT::i8);

  }
  case 3: {  // anonymous.val.459
    ConstantSDNode *N = cast<ConstantSDNode>(V.getNode());

    return CurDAG->getTargetConstant(
      N->getZExtValue() >> 2, MVT::i32);
  
  }
  case 4: {  // LO32
    ConstantSDNode *N = cast<ConstantSDNode>(V.getNode());

  return CurDAG->getTargetConstant(N->getZExtValue() & 0xffffffff, MVT::i32);

  }
  case 5: {  // HI32
    ConstantSDNode *N = cast<ConstantSDNode>(V.getNode());

  return CurDAG->getTargetConstant(N->getZExtValue() >> 32, MVT::i32);

  }
  case 6: {  // LO32f
    ConstantFPSDNode *N = cast<ConstantFPSDNode>(V.getNode());

  APInt V = N->getValueAPF().bitcastToAPInt().trunc(32);
  return CurDAG->getTargetConstantFP(APFloat(APFloat::IEEEsingle, V), MVT::f32);

  }
  case 7: {  // HI32f
    ConstantFPSDNode *N = cast<ConstantFPSDNode>(V.getNode());

  APInt V = N->getValueAPF().bitcastToAPInt().lshr(32).trunc(32);
  return CurDAG->getTargetConstantFP(APFloat(APFloat::IEEEsingle, V), MVT::f32);

  }
  }
}


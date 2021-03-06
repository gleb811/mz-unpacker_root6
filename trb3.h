//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Tue Jul 25 09:07:08 2017 by ROOT version 5.34/37
// from TTree T/UMainz TRBv3 HLD Data (Calibrated)
// found on file: /home/onl/Panda/xx17200131616.hld.root_calibrated.root
//////////////////////////////////////////////////////////

#ifndef trb3_h
#define trb3_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <TSelector.h>

// Header file for the classes stored in the TTree if any.
#include "TTrbEventData.h"
#include <TObject.h>
#include "TTrbHit.h"

// Fixed size dimensions of array or collections stored in the TTree if any.
   const Int_t kMaxHits = 1000;

class trb3 : public TSelector {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain

   // Declaration of leaf types
 //TTrbEventData   *event;
   UInt_t          fUniqueID;
   UInt_t          fBits;
   UInt_t          nEvtSize;
   UInt_t          nEvtDecoding;
   UInt_t          nEvtId;
   UInt_t          nEvtSeqNr;
   UInt_t          nEvtDate;
   UInt_t          nEvtTime;
   UInt_t          nEvtRun;
   UInt_t          nEvtPad;
   UInt_t          nSubEvtSize;
   UInt_t          nSubEvtDecoding;
   UInt_t          nSubEvtId;
   UInt_t          nSubEvtTrigger;
   UInt_t          nSebErrCode;
   UInt_t          nTrbs;
   UInt_t          nTdcs;
   UInt_t          nCTSExtTrigger;
   UInt_t          nCTSExtTriggerStatus;
   UInt_t          nSubEvtDecError;
   Int_t           Hits_;
   UInt_t          Hits_fUniqueID[kMaxHits];   //[Hits_]
   UInt_t          Hits_fBits[kMaxHits];   //[Hits_]
   UInt_t          Hits_nTrbAddress[kMaxHits];   //[Hits_]
   UInt_t          Hits_nTdcChannel[kMaxHits];   //[Hits_]
   UInt_t          Hits_nSubEvtId[kMaxHits];   //[Hits_]
   UInt_t          Hits_nTdcErrCode[kMaxHits];   //[Hits_]
   UInt_t          Hits_nSignalEdge[kMaxHits];   //[Hits_]
   UInt_t          Hits_nEpochCounter[kMaxHits];   //[Hits_]
   UInt_t          Hits_nCoarseTime[kMaxHits];   //[Hits_]
   UInt_t          Hits_nFineTime[kMaxHits];   //[Hits_]
   Double_t        Hits_fTime[kMaxHits];   //[Hits_]
   Bool_t          Hits_bIsCalibrated[kMaxHits];   //[Hits_]
   Bool_t          Hits_bIsRefChannel[kMaxHits];   //[Hits_]
   Bool_t          Hits_bVerboseMode[kMaxHits];   //[Hits_]

   // List of branches
   TBranch        *b_event_fUniqueID;   //!
   TBranch        *b_event_fBits;   //!
   TBranch        *b_event_nEvtSize;   //!
   TBranch        *b_event_nEvtDecoding;   //!
   TBranch        *b_event_nEvtId;   //!
   TBranch        *b_event_nEvtSeqNr;   //!
   TBranch        *b_event_nEvtDate;   //!
   TBranch        *b_event_nEvtTime;   //!
   TBranch        *b_event_nEvtRun;   //!
   TBranch        *b_event_nEvtPad;   //!
   TBranch        *b_event_nSubEvtSize;   //!
   TBranch        *b_event_nSubEvtDecoding;   //!
   TBranch        *b_event_nSubEvtId;   //!
   TBranch        *b_event_nSubEvtTrigger;   //!
   TBranch        *b_event_nSebErrCode;   //!
   TBranch        *b_event_nTrbs;   //!
   TBranch        *b_event_nTdcs;   //!
   TBranch        *b_event_nCTSExtTrigger;   //!
   TBranch        *b_event_nCTSExtTriggerStatus;   //!
   TBranch        *b_event_nSubEvtDecError;   //!
   TBranch        *b_event_Hits_;   //!
   TBranch        *b_Hits_fUniqueID;   //!
   TBranch        *b_Hits_fBits;   //!
   TBranch        *b_Hits_nTrbAddress;   //!
   TBranch        *b_Hits_nTdcChannel;   //!
   TBranch        *b_Hits_nSubEvtId;   //!
   TBranch        *b_Hits_nTdcErrCode;   //!
   TBranch        *b_Hits_nSignalEdge;   //!
   TBranch        *b_Hits_nEpochCounter;   //!
   TBranch        *b_Hits_nCoarseTime;   //!
   TBranch        *b_Hits_nFineTime;   //!
   TBranch        *b_Hits_fTime;   //!
   TBranch        *b_Hits_bIsCalibrated;   //!
   TBranch        *b_Hits_bIsRefChannel;   //!
   TBranch        *b_Hits_bVerboseMode;   //!

   trb3(TTree * /*tree*/ =0) : fChain(0) { }
   virtual ~trb3() { }
   virtual Int_t   Version() const { return 2; }
   virtual void    Begin(TTree *tree);
   virtual void    SlaveBegin(TTree *tree);
   virtual void    Init(TTree *tree);
   virtual Bool_t  Notify();
   virtual Bool_t  Process(Long64_t entry);
   virtual Int_t   GetEntry(Long64_t entry, Int_t getall = 0) { return fChain ? fChain->GetTree()->GetEntry(entry, getall) : 0; }
   virtual void    SetOption(const char *option) { fOption = option; }
   virtual void    SetObject(TObject *obj) { fObject = obj; }
   virtual void    SetInputList(TList *input) { fInput = input; }
   virtual TList  *GetOutputList() const { return fOutput; }
   virtual void    SlaveTerminate();
   virtual void    Terminate();

   ClassDef(trb3,0);
};

#endif

#ifdef trb3_cxx
void trb3::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("fUniqueID", &fUniqueID, &b_event_fUniqueID);
   fChain->SetBranchAddress("fBits", &fBits, &b_event_fBits);
   fChain->SetBranchAddress("nEvtSize", &nEvtSize, &b_event_nEvtSize);
   fChain->SetBranchAddress("nEvtDecoding", &nEvtDecoding, &b_event_nEvtDecoding);
   fChain->SetBranchAddress("nEvtId", &nEvtId, &b_event_nEvtId);
   fChain->SetBranchAddress("nEvtSeqNr", &nEvtSeqNr, &b_event_nEvtSeqNr);
   fChain->SetBranchAddress("nEvtDate", &nEvtDate, &b_event_nEvtDate);
   fChain->SetBranchAddress("nEvtTime", &nEvtTime, &b_event_nEvtTime);
   fChain->SetBranchAddress("nEvtRun", &nEvtRun, &b_event_nEvtRun);
   fChain->SetBranchAddress("nEvtPad", &nEvtPad, &b_event_nEvtPad);
   fChain->SetBranchAddress("nSubEvtSize", &nSubEvtSize, &b_event_nSubEvtSize);
   fChain->SetBranchAddress("nSubEvtDecoding", &nSubEvtDecoding, &b_event_nSubEvtDecoding);
   fChain->SetBranchAddress("nSubEvtId", &nSubEvtId, &b_event_nSubEvtId);
   fChain->SetBranchAddress("nSubEvtTrigger", &nSubEvtTrigger, &b_event_nSubEvtTrigger);
   fChain->SetBranchAddress("nSebErrCode", &nSebErrCode, &b_event_nSebErrCode);
   fChain->SetBranchAddress("nTrbs", &nTrbs, &b_event_nTrbs);
   fChain->SetBranchAddress("nTdcs", &nTdcs, &b_event_nTdcs);
   fChain->SetBranchAddress("nCTSExtTrigger", &nCTSExtTrigger, &b_event_nCTSExtTrigger);
   fChain->SetBranchAddress("nCTSExtTriggerStatus", &nCTSExtTriggerStatus, &b_event_nCTSExtTriggerStatus);
   fChain->SetBranchAddress("nSubEvtDecError", &nSubEvtDecError, &b_event_nSubEvtDecError);
   fChain->SetBranchAddress("Hits", &Hits_, &b_event_Hits_);
   fChain->SetBranchAddress("Hits.fUniqueID", Hits_fUniqueID, &b_Hits_fUniqueID);
   fChain->SetBranchAddress("Hits.fBits", Hits_fBits, &b_Hits_fBits);
   fChain->SetBranchAddress("Hits.nTrbAddress", Hits_nTrbAddress, &b_Hits_nTrbAddress);
   fChain->SetBranchAddress("Hits.nTdcChannel", Hits_nTdcChannel, &b_Hits_nTdcChannel);
   fChain->SetBranchAddress("Hits.nSubEvtId", Hits_nSubEvtId, &b_Hits_nSubEvtId);
   fChain->SetBranchAddress("Hits.nTdcErrCode", Hits_nTdcErrCode, &b_Hits_nTdcErrCode);
   fChain->SetBranchAddress("Hits.nSignalEdge", Hits_nSignalEdge, &b_Hits_nSignalEdge);
   fChain->SetBranchAddress("Hits.nEpochCounter", Hits_nEpochCounter, &b_Hits_nEpochCounter);
   fChain->SetBranchAddress("Hits.nCoarseTime", Hits_nCoarseTime, &b_Hits_nCoarseTime);
   fChain->SetBranchAddress("Hits.nFineTime", Hits_nFineTime, &b_Hits_nFineTime);
   fChain->SetBranchAddress("Hits.fTime", Hits_fTime, &b_Hits_fTime);
   fChain->SetBranchAddress("Hits.bIsCalibrated", Hits_bIsCalibrated, &b_Hits_bIsCalibrated);
   fChain->SetBranchAddress("Hits.bIsRefChannel", Hits_bIsRefChannel, &b_Hits_bIsRefChannel);
   fChain->SetBranchAddress("Hits.bVerboseMode", Hits_bVerboseMode, &b_Hits_bVerboseMode);
}

Bool_t trb3::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

#endif // #ifdef trb3_cxx

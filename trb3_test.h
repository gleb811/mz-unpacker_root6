//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Fri Apr 12 12:24:27 2019 by ROOT version 6.16/00
// from TTree T/UMainz TRBv3 HLD Data (Calibrated)
// found on file: /home/onl/Panda/xx19101112908.hld.root_calibrated.root
//////////////////////////////////////////////////////////

#ifndef trb3_test_h
#define trb3_test_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <TSelector.h>
#include <TTreeReader.h>
#include <TTreeReaderValue.h>
#include <TTreeReaderArray.h>

// Headers needed by this particular selector
#include "TTrbEventData.h"



class trb3_test : public TSelector {
public :
   TTreeReader     fReader;  //!the tree reader
   TTree          *fChain = 0;   //!pointer to the analyzed TTree or TChain

   // Readers to access the data (delete the ones you do not need).
   TTreeReaderValue<unsigned int> fUniqueID = {fReader, "fUniqueID"};
   TTreeReaderValue<unsigned int> fBits = {fReader, "fBits"};
   TTreeReaderValue<unsigned int> nEvtSize = {fReader, "nEvtSize"};
   TTreeReaderValue<unsigned int> nEvtDecoding = {fReader, "nEvtDecoding"};
   TTreeReaderValue<unsigned int> nEvtId = {fReader, "nEvtId"};
   TTreeReaderValue<unsigned int> nEvtSeqNr = {fReader, "nEvtSeqNr"};
   TTreeReaderValue<unsigned int> nEvtDate = {fReader, "nEvtDate"};
   TTreeReaderValue<unsigned int> nEvtTime = {fReader, "nEvtTime"};
   TTreeReaderValue<unsigned int> nEvtRun = {fReader, "nEvtRun"};
   TTreeReaderValue<unsigned int> nEvtPad = {fReader, "nEvtPad"};
   TTreeReaderValue<unsigned int> nSubEvtSize = {fReader, "nSubEvtSize"};
   TTreeReaderValue<unsigned int> nSubEvtDecoding = {fReader, "nSubEvtDecoding"};
   TTreeReaderValue<unsigned int> nSubEvtId = {fReader, "nSubEvtId"};
   TTreeReaderValue<unsigned int> nSubEvtTrigger = {fReader, "nSubEvtTrigger"};
   TTreeReaderValue<unsigned int> nSebErrCode = {fReader, "nSebErrCode"};
   TTreeReaderValue<unsigned int> nTrbs = {fReader, "nTrbs"};
   TTreeReaderValue<unsigned int> nTdcs = {fReader, "nTdcs"};
   TTreeReaderValue<unsigned int> nCTSExtTrigger = {fReader, "nCTSExtTrigger"};
   TTreeReaderValue<unsigned int> nCTSExtTriggerStatus = {fReader, "nCTSExtTriggerStatus"};
   TTreeReaderValue<unsigned int> nSubEvtDecError = {fReader, "nSubEvtDecError"};
   TTreeReaderArray<unsigned int> Hits_fUniqueID = {fReader, "Hits.fUniqueID"};
   TTreeReaderArray<unsigned int> Hits_fBits = {fReader, "Hits.fBits"};
   TTreeReaderArray<unsigned int> Hits_nTrbAddress = {fReader, "Hits.nTrbAddress"};
   TTreeReaderArray<unsigned int> Hits_nTdcChannel = {fReader, "Hits.nTdcChannel"};
   TTreeReaderArray<unsigned int> Hits_nSubEvtId = {fReader, "Hits.nSubEvtId"};
   TTreeReaderArray<unsigned int> Hits_nTdcErrCode = {fReader, "Hits.nTdcErrCode"};
   TTreeReaderArray<unsigned int> Hits_nSignalEdge = {fReader, "Hits.nSignalEdge"};
   TTreeReaderArray<unsigned int> Hits_nEpochCounter = {fReader, "Hits.nEpochCounter"};
   TTreeReaderArray<unsigned int> Hits_nCoarseTime = {fReader, "Hits.nCoarseTime"};
   TTreeReaderArray<unsigned int> Hits_nFineTime = {fReader, "Hits.nFineTime"};
   TTreeReaderArray<Double_t> Hits_fTime = {fReader, "Hits.fTime"};
   TTreeReaderArray<Bool_t> Hits_bIsCalibrated = {fReader, "Hits.bIsCalibrated"};
   TTreeReaderArray<Bool_t> Hits_bIsRefChannel = {fReader, "Hits.bIsRefChannel"};
   TTreeReaderArray<Bool_t> Hits_bVerboseMode = {fReader, "Hits.bVerboseMode"};


   trb3_test(TTree * /*tree*/ =0) { }
   virtual ~trb3_test() { }
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

   ClassDef(trb3_test,0);

};

#endif

#ifdef trb3_test_cxx
void trb3_test::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the reader is initialized.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   fReader.SetTree(tree);
}

Bool_t trb3_test::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}


#endif // #ifdef trb3_test_cxx

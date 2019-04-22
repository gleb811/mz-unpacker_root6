Double_t sigma1,sigma2,sigma1_2,sigma122,sigma1_corr,sigma2_corr,sigma_synch;

TCanvas *c1,*c2;

void analyzer(string file_name) {

#include <iostream>
#include <string>

    //gROOT->ProcessLine(".x BuildTrbCalibration.cpp");
//ostringstream file_name_hld;
//file_name_hld << "../../trb_data/" << file_name << ".hld";
//TTrbUnpacker a(file_name.c_str(), 0x8000, 0x8000, " ","TDC_Addresses_test.txt",0,kFALSE);
//a.Decode(0);
//ostringstream file_name_hld_root;
//file_name_hld_root << file_name << ".root";
//TTrbCalibration b(file_name_hld_root.str().c_str(), Calibration_type=0, Min_Statistics=0,VerboseMode=kFALSE);
//b.DoTdcCalibration();
TFile *ftrb = new TFile(file_name.c_str());
TTree *T = (TTree*)ftrb->Get("T");
T->Process("/home/onl/Panda/laser_test.C");
ostringstream qqq1,qqq2;
qqq1 << file_name.erase (file_name.length()-25,file_name.length()) << "_1.png";
qqq2 << qqq1.str().erase (qqq1.str().length()-6,qqq1.str().length()) << ".png";
//cout << qqq1.str() << endl;
//cout << qqq2.str() << endl;
c1->SaveAs(qqq1.str().c_str());
c2->SaveAs(qqq2.str().c_str());
}

Double_t sigma1,sigma2,sigma1_2,sigma122,sigma1_corr,sigma2_corr,sigma_synch;

TCanvas *c1,*c2;

void convert_analyze(string file_name) {

    
//gROOT->ProcessLine(".x BuildTrbCalibration.cpp");
//ostringstream file_name_hld;
//file_name_hld << "../../trb_data/" << file_name << ".hld";
TTrbUnpacker a(file_name.c_str(), 0x8000, 0x8000, " ","TDC_Addresses_test.txt",0,kFALSE);
a.Decode(0);
ostringstream file_name_hld_root;
file_name_hld_root << file_name << ".root";
Bool_t VerboseMode=kFALSE;
TTrbCalibration b(file_name_hld_root.str().c_str(), 0, 0, kFALSE);
b.DoTdcCalibration();
ostringstream file_name_hld_root_calibrated;
file_name_hld_root_calibrated << file_name_hld_root.str() << "_calibrated.root";
//cout << file_name_hld_root_calibrated.str() << endl;
TFile *ftrb = new TFile(file_name_hld_root_calibrated.str().c_str());
TTree *T = (TTree*)ftrb->Get("T");

T->Process("/home/onl/Panda/laser.C");
ostringstream qqq1,qqq2;
qqq1 << file_name.erase (file_name.length()-4,file_name.length()) << "_1.png";
qqq2 << qqq1.str().erase (qqq1.str().length()-6,qqq1.str().length()) << ".png";
//cout << qqq1.str() << endl;
//cout << qqq2.str() << endl;
c1->SaveAs(qqq1.str().c_str());
c2->SaveAs(qqq2.str().c_str());

ostringstream qqq4;
//cout << sigma1_2 << endl;
qqq4 << "sed -e 's$sigma;<sub>N1-synch</sub> =$sigma;<sub>N1-synch</sub> = " << ceil(sigma1*10000)/10. << "$' -e 's$sigma;<sub>N2-synch</sub> =$sigma;<sub>N2-synch</sub> = " << ceil(sigma2*10000)/10. << "$' -e 's$sigma;<sub>N1-N2</sub> =$sigma;<sub>N1-N2</sub> = " << ceil(sigma1_2*10000)/10. << "$' -e 's$sigma;<sub>((N1-synch)+(N2-synch))/2</sub> =$sigma;<sub>((N1-synch)+(N2-synch))/2</sub> = " << ceil(sigma122*10000)/10. << "$' -e 's$sigma;<sub>N1</sub><sup>corr</sup> =$sigma;<sub>N1</sub><sup>corr</sup> = " << ceil(sigma1_corr*10000)/10.  << "$' -e 's$sigma;<sub>N2</sub><sup>corr</sup> =$sigma;<sub>N2</sub><sup>corr</sup> = " << ceil(sigma2_corr*10000)/10. << "$' -e 's$sigma;<sub>synch</sub> =$sigma;<sub>synch</sub> = " << ceil(sigma_synch*10000)/10. << "$' -e 's$hld file name:$hld file name: " << file_name.erase(0,file_name.length()-13) << "$' /home/onl/Panda/panda_log/panda.html > /tmp/qqq5";
system(qqq4.str().c_str());

ostringstream qqq3;
qqq3 << "elog -h localhost -p 8080 -l panda -a author='G. Fedotov, O. Mikluho' -a Type=Other -m /tmp/qqq5 -n 2 -f " << qqq2.str() << " -f " << qqq1.str();
system(qqq3.str().c_str());

}

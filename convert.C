void convert(string file_name) {

//gROOT->ProcessLine(".x BuildTrbCalibration.cpp");
//ostringstream file_name_hld;
//file_name_hld << "../../trb_data/" << file_name << ".hld";
TTrbUnpacker a(file_name.c_str(), 0x8000, 0x8000, " ","TDC_Addresses_test.txt",0,kFALSE);
a.Decode(0);
ostringstream file_name_hld_root;
file_name_hld_root << file_name << ".root";
Bool_t VerboseMode=kFALSE;
TTrbCalibration b(file_name_hld_root.str().c_str(), 0, 0,VerboseMode);
b.DoTdcCalibration();
}

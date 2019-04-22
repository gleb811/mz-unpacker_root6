#define trb_cxx

#include "trb.h"
#include <TH2.h>
#include <TStyle.h>
#include <cstring>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

TH1F*htdc[4];
TH2F*cor;
double cut[3][2]={{-6.5,-5.7},{18.2,19},{16.8,17.8}};
//double cut[3][2]={{-100,100},{1,100},{1,100}};
double X=0,X2=0,Y=0,XY=0;
unsigned long K=0;
Double_t buf[4][10000000];

void trb::Begin(TTree * /*tree*/)
{
  char cdt[4][10]={"tdc","tot1","tot2","fin"};
  char CDT[4][10]={"TDC","ToT1","ToT2","TDC Final"};

TString option = GetOption();

gStyle->SetOptFit(111);
gStyle->SetPalette(10);
gStyle->SetLabelSize(.05,"x");
gStyle->SetLabelSize(.05,"y");

for(int i=0;i<4;i++)
   {
   htdc[i] = new TH1F(cdt[i],CDT[i], 2000, 0, 0);
   htdc[i]->GetXaxis()->SetTitle("ns");
   htdc[i]->GetXaxis()->SetTitleSize(.05);
   }
cor = new TH2F("cor", "TDC-QDC correlation ", 1000,-.02,.15,1000,-7.5,-5.3);
cor->GetXaxis()->SetTitle("1/#sqrt{ns}");
cor->GetYaxis()->SetTitle("ns");
cor->GetXaxis()->SetTitleSize(.05);
cor->GetYaxis()->SetTitleSize(.05);
}

void trb::SlaveBegin(TTree * /*tree*/)
{
   // The SlaveBegin() function is called after the Begin() function.
   // When running with PROOF SlaveBegin() is called on each slave server.
   // The tree argument is deprecated (on PROOF 0 is passed).

   TString option = GetOption();

}

Bool_t trb::Process(Long64_t entry)
{
  int N=0;
  Double_t tdc[4][100];
  int i=0;

fChain->GetTree()->GetEntry(entry);

if(entry%100000==0) printf("%lu\n",(unsigned long)entry);

for(i=0;i<Hits_;i++) printf("%d ",Hits_nTdcChannel[i]);
printf("\n");

if(Hits_nTdcChannel[0]!=0||Hits_nTdcChannel[1]!=27) return kFALSE;

for(i=1;Hits_nTdcChannel[i]!=0;i++);
N=i-1;
// printf("%d %lld\n",N,entry);
if(N%4!=0) return kFALSE; 

for(i=0;i<N/4;i++)
   {
   tdc[0][i]=Hits_fTime[i+1+N/2]-Hits_fTime[i+1];
   tdc[1][i]=Hits_fTime[i+1+N/4]-Hits_fTime[i+1];
   tdc[2][i]=Hits_fTime[i+1+3*N/4]-Hits_fTime[i+1+N/2];

   if(tdc[0][i]<cut[0][0]||tdc[0][i]>cut[0][1]) continue;
   if(tdc[1][i]<cut[1][0]||tdc[1][i]>cut[1][1]) continue;
   if(tdc[2][i]<cut[2][0]||tdc[2][i]>cut[2][1]) continue;

   tdc[3][i]=1/sqrt(tdc[2][i])-1/sqrt(tdc[1][i]);
   htdc[0]->Fill(tdc[0][i]);
   htdc[1]->Fill(tdc[1][i]);
   htdc[2]->Fill(tdc[2][i]);
   cor->Fill(tdc[3][i],tdc[0][i]);

   X+=tdc[3][i];
   X2+=tdc[3][i]*tdc[3][i];
   Y+=tdc[0][i];
   XY+=tdc[0][i]*tdc[3][i];

   for(j=0;j<4;j++) buf[j][K]=tdc[j][i];
   K++;
   }
return kTRUE;
}

void trb::SlaveTerminate()
{
   // The SlaveTerminate() function is called after all entries or objects
   // have been processed. When running with PROOF SlaveTerminate() is called
   // on each slave server.

}

void trb::Terminate()
{

printf("Statistics: %lu\n",K);

printf("%lu %f %f %f %f\n",K,X,Y,X2,XY); 
double A=(K*XY-X*Y)/(K*X2-X*X);
double B=(Y-A*X)/K;
printf("N = %lu\tA= %f.0\tB= %f\n",K, (float)-A,(float)-B);
for(int i=0;i<K;i++) htdc[3]->Fill(buf[0][i]-A*buf[3][i]-B);

TCanvas *c1 = new TCanvas("c1", "Raw Spectra", 0, 0, 1000, 1000);
c1->Divide(2,2);

c1->cd(1);
htdc[0]->Draw();
c1->cd(3);
htdc[1]->Draw();
c1->cd(4);
htdc[2]->Draw();
c1->cd(2);
cor->Draw();

TCanvas *c2 = new TCanvas("c2", "TDC", 0, 0, 700, 700);
htdc[3]->Fit("gaus");
htdc[3]->Draw();
 
}

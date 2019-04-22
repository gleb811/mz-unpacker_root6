#define trb3_cxx

#include "trb3.h"
#include <TH2.h>
#include <TStyle.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

TH1F*htdc[4];
TH2F*cor;
int ch[2]={24,26};
double hits[2][100];
//double cut[3][2]={{1.6,1.7},{42.5,43.2},{39,39.75}};
double cut[3][2]={{-100.,100.},{0.,100.},{0.,100.}};
//double cut[3][2]={{-5.,-1.},{47.,60.},{46.,53.}};
//double cut[3][2]={{-20,20},{40.5,46},{44.5,46}};
//double cut[3][2]={{-0.5,0},{37,38},{40,41}};
double X=0,X2=0,Y=0,XY=0;
unsigned long N=0;
Double_t buf[4][10000000];
FILE*out;

void trb3::Begin(TTree * /*tree*/)
{
  char *cdt[4]={"tdc","tot1","tot2","fin"};
  char *CDT[4]={"TDC","ToT1","ToT2","TDC Final"};

TString option = GetOption();
out=fopen("out","w");
gStyle->SetOptFit(111);
gStyle->SetPalette(10);
gStyle->SetLabelSize(.05,"x");
gStyle->SetLabelSize(.05,"y");

for(int i=0;i<4;i++)
   {
   htdc[i] = new TH1F(cdt[i],CDT[i], 200, 0, 0);
   htdc[i]->GetXaxis()->SetTitle("ns");
   htdc[i]->GetXaxis()->SetTitleSize(.05);
   }

cor = new TH2F("cor", "TDC-QDC correlation ", 1000,-1000,-20,20,-20,-20);
//cor = new TH2F("cor", "TDC-QDC correlation ", 1000,-1000,-20,20,-20,-20);
cor->GetXaxis()->SetTitle("1/#sqrt{ns}");
cor->GetYaxis()->SetTitle("ns");
cor->GetXaxis()->SetTitleSize(.03);
cor->GetYaxis()->SetTitleSize(.05);
}

void trb3::SlaveBegin(TTree * /*tree*/)
{
TString option = GetOption();

}

Bool_t trb3::Process(Long64_t entry)
{
  Double_t temp[3],q;
  
fChain->GetTree()->GetEntry(entry);

if(entry%10000==0)
   printf("+%ld %d\n",entry,Hits_);
 
/*
if((Hits_-1)%4)
   { 
   //    printf("-%ld %d\n",entry,Hits_);
     return kFALSE;
       }
*/
       
       // printf("=%ld %d %d\n",entry,Hits_, (Hits_-1)%4);

int K=(Hits_-1)/2;
for(int j=1;j<K;j++) 
   {
//         cout << " ch1 = " << Hits_nTdcChannel[1+j] << " ch11 = " << Hits_nTdcChannel[2+j] << " ch2 = " << Hits_nEpochCounter[1+K+j] << " ch22 = " << Hits_nTdcChannel[2+K+j] << endl;
        if ((Hits_nEpochCounter[1+j] == Hits_nEpochCounter[2+j])&&(Hits_nEpochCounter[1+j] == Hits_nEpochCounter[1+K+j])&&(Hits_nEpochCounter[1+j] == Hits_nEpochCounter[2+K+j])) 
      
         {
          
      if ((Hits_nTdcChannel[1+j] == Hits_nTdcChannel[2+j])&&(Hits_nTdcChannel[1+K+j] == Hits_nTdcChannel[2+K+j]))
         {         
         
       
   temp[0]=Hits_fTime[1+K+j]-Hits_fTime[1+j];
   temp[1]=Hits_fTime[2+j]-Hits_fTime[1+j]-(57.45-30.);
   temp[2]=Hits_fTime[2+K+j]-Hits_fTime[1+K+j]-(57.92-30.);
  // printf ("+%f\t%f\t%f\n",temp[0],temp[1],temp[2]);
 //  for(int i=0;i<3;i++) 
 //     {
      //      printf("*** %d\t%f\t%f\n",i,cut[i][0],cut[i][1]);
//      if(temp[i]<cut[i][0]||temp[i]>cut[i][1]) return kFALSE;
//      }
// if(temp[2]<7||temp[2]>8.5) return kFALSE;
//printf("%lf\n",temp[0]);
//   printf ("%f\t%f\t%f\n",temp[1],temp[2],q);
     if(temp[0]>cut[0][0]&&temp[0]<cut[0][1]) {
      if(temp[1]>cut[1][0]&&temp[1]<cut[1][1]) {      
      if(temp[2]>cut[2][0]&&temp[2]<cut[2][1]) {
         

   for(int i=0;i<3;i++)
      {
      htdc[i]->Fill(temp[i]);
      buf[i][N]=temp[i];
      }

  // printf ("%f\t%f\t%f\n",temp[1],temp[2],q);
  
   if((temp[2]!=(Double_t)0)&&(temp[1]!=(Double_t)0)) {        
  
   q=1/sqrt(temp[2])-1/sqrt(temp[1]);
  // printf ("%f\t%f\t%f\n",temp[1],temp[2],q);

    if((q!=(Double_t)0)) {    

   buf[3][N]=q;

//cor->Fill(Hits_fTime[4],Hits_fTime[2]);
   cor->Fill(q,temp[0]);
/*
   X+=q;
   X2+=q*q;
  // fprintf(out,"%ld %lf %lf% lf %lf\n",entry,q,X,q*q,X2);
   Y+=temp[0];
   XY+=temp[0]*q;
*/
 
   N++;

   /*
   printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%lf\n",Hits_nTdcChannel[1],
                                          Hits_nSignalEdge[1],
                                          Hits_nTdcChannel[2],
                                          Hits_nSignalEdge[2],
                                          Hits_nTdcChannel[3],
                                          Hits_nSignalEdge[3],
                                          Hits_nTdcChannel[4],
                                          Hits_nSignalEdge[4],
                                          buf[0][entry]);
*/

          }; // end of q non-zero cut if

         }; // end of temp[2] and temp[1] non-zero cut if
	 
	 }; // end of ToT 2 cut if
	 }; // end of ToT 1 cut if
	 }; // end of TDC diff  cut if

	 
      
         }; // end of channels match if
         }; // end of EpochCounters match if  
   
   
   }
return kTRUE;
}

void trb3::SlaveTerminate()
{
}

void trb3::Terminate()
{

printf("Statistics: %lu\n",N);

// printf("%lu %f %f %f %f\n",N,X,Y,X2,XY); 
/*
double A=(N*XY-X*Y)/(N*X2-X*X);
double B=(Y-A*X)/N;
//A=B=0; 
printf("N = %lu\tA= %f.0\tB= %f\n",N, (float)-A,(float)-B);
*/

TProfile *prof = cor->ProfileX();
prof->Fit("pol1");
TF1 *f1 = prof->GetFunction("pol1");
B = f1->GetParameter(0);
A = f1->GetParameter(1);
//A=B=0; 

for(int i=0;i<N;i++) htdc[3]->Fill(buf[0][i]-A*buf[3][i]-B);

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



TCanvas *c2 = new TCanvas("c2", "Final TDC", 0, 0, 1000, 1000);
c2->cd(1);
htdc[3]->Fit("gaus","Q");
htdc[3]->Draw();
}
 

#include "TFile.h"
#include "AtlasStyle.C"
#include "AtlasUtils.C"

void draw()
{
  TH1F *m = new TH1F("","",55,105,160);
  TH1F *mjj = new TH1F("","",55,105,160);
  TFile *f = new TFile("hist-sample.root");
  TTree *t = f->Get("tree");
  
  Double_t myy;

  t->SetBranchAddress("m_yy", &myy);
  int n_entries = t->GetEntries(); 
  
  for (int i = 0; i<n_entries; ++i )
      {
      t->GetEntry(i);
      m->Fill(myy/1000);
      }

  TCanvas *c1 = new TCanvas( "mass of yy", "mass_yy", 600 , 400 );
  //c1->SetLogy();
  m->SetStats( false );
  m->SetLineColor( kRed );
  m->GetXaxis()->SetTitle("m_{#gamma#gamma}");
  m->Draw("e");
  
  //ATLAS_LABEL(0.55, 0.75 );
  //myText( 0.7, 0.75 , 1, "Internal");
  //myText( 0.45, 0.6 , 1, "#sqrt{s} = 13 TeV");
  //myText( 0.65, 0.6 , 1, "#int L dt = 2.3 fb^{-1}");

  TLegend *lg =new TLegend(0.9,0.9,0.8,0.8);
  lg->SetFillColor(10);
  lg->AddEntry(m,"m_{#gamma#gamma}");
  lg->AddEntry(mjj,"m_{jj}");
  lg->Draw();

}

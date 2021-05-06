void TAC_cali(){

  gStyle->SetTitleSize(0.04,"XY");
  const int N=10;

  //cavi non calibrati
  /*
  float cent[N]={1508,1604,7146,7052,6244,5844,5645,3397};
  float ns[N]={28,30,130+5,128+5,112+5,104+5,100+5,62.5};
  */
  
  //cavi calibrati
  float cent[N]={1506,1601,3392,3296,2496,9127,8312,6132,6058,6461};
  float ns[N]={28,30,62.5+3.5,60.5+3.5,44.5+3.5,170.5+4+3.5,154.5+4+3.5,114.5+3.5,113.5+3.5,121.5+3.5};
  
  
  // +0 1 caen, +3.5 2 caen, +4 bobina cavo extra
  /* 110.5 ns
  1st: 6132 (+4)
  2nd: 6058 (+3)
  3rd: 6461 (+11)
  4th: 6464 (+11)
  5th: 6134 (+5)
  */
  
  TGraph *g=new TGraph(N,cent,ns);
  TCanvas *c=new TCanvas("c","calibration");
  
  TF1 *f=new TF1("f","pol1",0,10000);
  f->SetParNames("q","m");
  TFitResultPtr fitres=g->Fit(f,"S");
  
  float m=f->GetParameter(1), q=f->GetParameter(0),
  	ms=f->GetParError(1), qs=f->GetParError(0);
  TMatrixDSym cov=fitres->GetCovarianceMatrix();
  	
  float res[N]={0};
  float res_s[N]={0};
  for(int i=0; i<N; i++){
    res[i]=ns[i]-f->Eval(cent[i]);
    res_s[i]=sqrt(pow(cent[i]*ms,2)+pow(qs,2)+2*cov(0,1)*cent[i]);
  }
  
  g->SetMarkerStyle(3);
  g->SetTitle("TAC; Channel [-]; Time [ns]");
  g->Draw("AP");
  
  gStyle->SetOptFit(1111);
  TPaveStats *st = (TPaveStats*)g->FindObject("stats");
  st->SetX1NDC(0.62);
  st->SetX2NDC(0.87);
  st->SetY1NDC(0.15);
  st->SetY2NDC(0.35);
  
  TGraphErrors *gr=new TGraphErrors(N,cent,res,NULL,res_s);
  gr->SetMarkerStyle(3);
  gr->SetTitle("Residues TAC; Channel [-]; Time [ns]");
  TCanvas *cs=new TCanvas("cs","residues");
  gr->Draw("AP");
  
  TF1 *ref=new TF1("ref","0",0,10000);
  ref->SetLineColor(2);
  ref->Draw("same");
  
 

 


}

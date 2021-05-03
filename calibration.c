void calibration(){
  const int N=5;

  gStyle->SetTitleSize(0.04,"XY");
  
  float keV[N]={661, 1173, 1332, 511, 1275};
  
  float cent_6[N]={1.30674e+03, 2.33897e+03, 2.66751e+03,
  	9.16602e+02, 2.31459e+03};
  float cent_6s[N]={1.24407e-01, 3.75724e-01, 3.26413e-01,
  	2.01574e-01, 5.40194e-01};
  	
  float cent_3[N]={6.33071e+02, 1.12400e+03, 1.28851e+03,
  	4.84336e+02, 1.23192e+03};
  float cent_3s[N]={1.99144e-01, 1.02983e+00, 1.07870e+00,
  	2.29006e-01, 1.01715e+00};
  
  	
  TGraph *g6=new TGraph(N,cent_6,keV);
  TCanvas *c=new TCanvas;
  g6->SetTitle("Energy Calibration - ch6; Channel [-]; Energy [keV]");
  g6->SetMarkerStyle(3);
  g6->SetMarkerColor(1);
  
  TF1 *f6=new TF1("f6","pol1",800,2800);
  g6->Fit(f6);
  g6->Draw("AP");
  
  float res_6[N]={0};
  float res_6s[N]={0};
  float m=f6->GetParameter(1), q=f6->GetParameter(0),
  	ms=f6->GetParError(1), qs=f6->GetParError(0);
  for(int i=0; i<N; i++){
    res_6[i]=keV[i]-f6->Eval(cent_6[i]);
    res_6s[i]=sqrt(pow(m*res_6s[i],2)+pow(cent_6[i]*ms,2)+pow(qs,2));
  }
  TGraphErrors *g6r=new TGraphErrors(N,cent_6,res_6,NULL,res_6s);
  TCanvas *c6r=new TCanvas;
  g6r->SetMarkerStyle(3);
  g6r->SetTitle("Residues Energy Calibration - ch6; Channel [-]; Energy [keV]");
  g6r->Draw("AP");
  


  TGraph *g3=new TGraph(N,cent_3,keV);
  TCanvas *c3=new TCanvas;
  g3->SetTitle("Energy Calibration - ch3; Channel [-]; Energy [keV]");
  g3->SetMarkerStyle(3);
  g3->SetMarkerColor(1);
  
  TF1 *f3=new TF1("f3","pol1",800,2800);
  g3->Fit(f3);
  g3->Draw("AP");
  
  float res_3[N]={0};
  float res_3s[N]={0};
        m=f3->GetParameter(1); q=f3->GetParameter(0);
  	ms=f3->GetParError(1); qs=f3->GetParError(0);
  for(int i=0; i<N; i++){
    res_3[i]=keV[i]-f3->Eval(cent_3[i]);
    res_3s[i]=sqrt(pow(m*res_3s[i],2)+pow(cent_3[i]*ms,2)+pow(qs,2));
  }
  TGraphErrors *g3r=new TGraphErrors(N,cent_3,res_3,NULL,res_3s);
  TCanvas *c3r=new TCanvas;
  g3r->SetMarkerStyle(3);
  g3r->SetTitle("Residues Energy Calibration - ch3; Channel [-]; Energy [keV]");
  g3r->Draw("AP");

}

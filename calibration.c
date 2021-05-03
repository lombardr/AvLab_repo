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
  
  	
  TGraphErrors *g6=new TGraphErrors(N,keV,cent_6,NULL,cent_6s);
  TCanvas *c=new TCanvas;
  g6->SetTitle("Calibration ch6; Energy [keV]; ADC counts [-]");
  g6->SetMarkerStyle(3);
  g6->SetMarkerColor(1);
  
  TF1 *f6=new TF1("f6","pol1",500,1300);
  g6->Fit(f6);
  g6->Draw("AP");
  
  float res_6[N]={0};
  for(int i=0; i<N; i++) res_6[i]=f6->Eval(keV[i])-cent_6[i];
  TGraphErrors *g6r=new TGraphErrors(N,keV,res_6,NULL,cent_6s);
  TCanvas *c6r=new TCanvas;
  g6r->SetMarkerStyle(3);
  g6r->SetTitle("Residues ch6; Energy [keV]; Distance [keV]");
  g6r->Draw("AP");
  


  TGraphErrors *g3=new TGraphErrors(N,keV,cent_3,NULL,cent_3s);
  TCanvas *c3=new TCanvas;
  g3->SetTitle("Calibration ch3; Energy [keV]; ADC counts [-]");
  g3->SetMarkerStyle(3);
  g3->SetMarkerColor(1);
  g3->Draw("AP");

}

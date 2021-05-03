void getHist(){

  TFile *file=new TFile("compassF_88Y_22Na_BaF_1050V_500M_1.root");
  //TTree *t=(TTree*)file->Get("Data");
  TTree *t=(TTree*)file->Get("Data_F");
  TBranch *b=t->GetBranch("Energy");
  TBranch *ch=t->GetBranch("Channel");
  
  short s,c;
  
  b->SetAddress(&s);
  ch->SetAddress(&c);
  
  TH1F *h6=new TH1F("h6","h6",200,0,3500);
  TH1F *h3=new TH1F("h3","h3",200,0,2000);
  
  for(int i=0; i<b->GetEntries(); i++){
    ch->GetEntry(i);
    b->GetEntry(i);
    
    if(c==3) h3->Fill(s);
    else if(c==6) h6->Fill(s);
    else continue;    
  }
  
  TCanvas *c3=new TCanvas();
  h3->Draw();
  
  TCanvas *c6=new TCanvas();
  h6->Draw();




}

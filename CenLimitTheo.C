/////////////////////////
//Central Limit Theorem//
/////////////////////////
#include<iostream>
using namespace std;




int CenLimitTheo(const int nmSample, const int nmExp){



         TRandom3 *rn = new TRandom3();//for rndom numbers 
         TTimeStamp *tm = new TTimeStamp();//generate independent rndom numbers

	

	 //histogram 
	 TH1D *hs = new TH1D("hs", "Histo for Central Limit Theorem", 50000, 0, 3);

	 double numAvg=0;
         //loop for n-exp
	 for(int ex=1; ex<=nmExp; ex++ ){

		double num=0; 
		//loop for n-samples
	          for(int sam=0; sam<nmSample; sam++){

	  
	         	 double nb = rn->Rndm(tm->GetNanoSec());

		         double  xx= 2*TMath::Power(TMath::Cos(nb), 2);
		         num+=xx; 
	         }

	 numAvg = num/nmSample;
         cout<<"The average number would be:   "<<numAvg<<endl;
	hs->Fill(numAvg);



	 }//exp loop closed


	 //creat canvas
	 gStyle->SetGridStyle(16);
	 gStyle->SetHistFillColor(3);

	 auto *c = new TCanvas();
	 hs->GetXaxis()->SetTitle("Average numbers");
	 hs->GetYaxis()->SetTitle(" Experiments");
	 hs->SetLineColor(7);
	 hs->Draw();
	 c->SaveAs("hist.pdf");
	 c->Update();

return 0;
}

//Our headers
#include "randomGen.h"

//ROOT headers
#include <TH1D.h>
#include <TF1.h>
#include <TFile.h>
#include <TCanvas.h>

//C++ std library headers
#include <vector>

int main(){
    
    TFile * outputFile = new TFile("outputHistograms.root","recreate");
    TH1D * allRandomsHisto = new TH1D("All_Random_Numbers","All Random Numbers generated",100,0.0,1.0);
    TH1D * meanRandomsHisto = new TH1D("Random_Numbers_Meaned_100","All Random Numbers generated mean value calculated in groups of 100",100,0.0,1.0);
    std::vector<double> meanRandoms;
    randomGen generator = randomGen(1234);
    double meanRandom;

    for(int i=0; i<10000000; i++){

        if( i % 100 == 0 && i>0){
            meanRandoms.push_back(meanRandom/100);
            meanRandom = 0.0;
        }
        double randNum = generator.getRandom(0.0,1.0);
        allRandomsHisto->Fill(randNum);
        meanRandom += randNum;
    }

    for(int i=0; i<meanRandoms.size(); i++){
        meanRandomsHisto->Fill(meanRandoms[i]);
    }

    allRandomsHisto->Write();

    meanRandomsHisto->Write();


    TCanvas * fitCanvas = new TCanvas("fitToMeanOfRandoms","fitToMeanOfRandoms",900,600);
    meanRandomsHisto->Draw();
    meanRandomsHisto->Fit("gaus");
    TF1 * fittedGaus = meanRandomsHisto->GetFunction("gaus");
    fittedGaus->Draw("same");
    fitCanvas->Write();


    outputFile->Close();


    return 0;
}


#include "runAction.hh"

MyRunAction::MyRunAction()
{
	auto analysisManager = G4AnalysisManager::Instance(); 


    // Create directories
    //analysisManager->SetHistoDirectoryName("histograms");
    //analysisManager->SetNtupleDirectoryName("ntuple");
    analysisManager->SetVerboseLevel(1);
    analysisManager->SetNtupleMerging(true);
    // Note: merging ntuples is available only with Root output


    //Book a N-tuple for event-by-event anaylsis
    G4int cNumDetectors = 4;
    analysisManager->CreateNtuple("EST", "eDep");
    //analysisManager->CreateNtupleDColumn("EventID");
    analysisManager->CreateNtupleDColumn("InitErg");
    for (G4int i = 0; i < cNumDetectors; i++) {
        analysisManager->CreateNtupleDColumn("Detector_" + std::to_string(i));
    }
    analysisManager->FinishNtuple();

    //Bin for the energy spectrum (16k ADC channels)
    G4int N_ADCchannel = 16384;
    G4double cSpectrumErgMin = 0.0 * MeV;
    G4double cSpectrumErgMax = 10. * MeV;

    //Bin for the response matrix 
    G4int N_bin = 100;
    G4double cSourceErgMin = 0.01 * MeV;
    G4double cSourceErgMax = 10. * MeV;
   
    //create histograms 
    G4int Det0_Measured = analysisManager->CreateH1("Si Det0 - Measured Spectrum", "Detector Measured Spectrum", N_ADCchannel, cSpectrumErgMin, cSpectrumErgMax, "none", "none", "linear");
    analysisManager->SetH1XAxisTitle(Det0_Measured, "Measured Energy (MeV)");
    analysisManager->SetH1YAxisTitle(Det0_Measured, "# of Events");
    analysisManager->SetH1Activation(Det0_Measured, true);

    //
    G4int Det1_Measured = analysisManager->CreateH1("Si Det1 - Measured Spectrum", "Detector Measured Spectrum", N_ADCchannel, cSpectrumErgMin, cSpectrumErgMax, "none", "none", "linear");
    analysisManager->SetH1XAxisTitle(Det1_Measured, "Measured Energy (MeV)");
    analysisManager->SetH1YAxisTitle(Det1_Measured, "# of Events");
    analysisManager->SetH1Activation(Det1_Measured, true);

    //
    G4int Det2_Measured = analysisManager->CreateH1("Si Det2 - Measured Spectrum", "Detector Measured Spectrum", N_ADCchannel, cSpectrumErgMin, cSpectrumErgMax, "none", "none", "linear");
    analysisManager->SetH1XAxisTitle(Det2_Measured, "Measured Energy (MeV)");
    analysisManager->SetH1YAxisTitle(Det2_Measured, "# of Events");
    analysisManager->SetH1Activation(Det2_Measured, true);
    
    //
    G4int Det3_Measured = analysisManager->CreateH1("Si Det3 - Measured Spectrum", "Detector Measured Spectrum", N_ADCchannel, cSpectrumErgMin, cSpectrumErgMax, "none", "none", "linear");
    analysisManager->SetH1XAxisTitle(Det3_Measured, "Measured Energy (MeV)");
    analysisManager->SetH1YAxisTitle(Det3_Measured, "# of Events");
    analysisManager->SetH1Activation(Det3_Measured, true);
    
    //
    G4int Det0_Mig_Electron = analysisManager->CreateH2("Det0 Energy Migration Matrix", "Energy Migration Matrix for Electrons", N_bin, cSourceErgMin, cSourceErgMax, N_bin, cSourceErgMin, cSourceErgMax, "none", "none","none", "none", "log", "log");
    analysisManager->SetH2XAxisTitle(Det0_Mig_Electron, "True Energy (MeV)");
    analysisManager->SetH2YAxisTitle(Det0_Mig_Electron, "Measured Energy (MeV)");
    analysisManager->SetH2ZAxisTitle(Det0_Mig_Electron, "# of Events");
    analysisManager->SetH2Activation(Det0_Mig_Electron, true);

    //
    G4int Det1_Mig_Electron = analysisManager->CreateH2("Det1 Energy Migration Matrix", "Energy Migration Matrix for Electrons", N_bin, cSourceErgMin, cSourceErgMax, N_bin, cSourceErgMin, cSourceErgMax, "none", "none", "none", "none", "log", "log");
    analysisManager->SetH2XAxisTitle(Det1_Mig_Electron, "True Energy (MeV)");
    analysisManager->SetH2YAxisTitle(Det1_Mig_Electron, "Measured Energy (MeV)");
    analysisManager->SetH2ZAxisTitle(Det1_Mig_Electron, "# of Events");
    analysisManager->SetH2Activation(Det1_Mig_Electron, true);

    //
    G4int Det2_Mig_Electron = analysisManager->CreateH2("Det2 Energy Migration Matrix", "Energy Migration Matrix for Electrons", N_bin, cSourceErgMin, cSourceErgMax, N_bin, cSourceErgMin, cSourceErgMax, "none", "none", "none", "none", "log", "log");
    analysisManager->SetH2XAxisTitle(Det2_Mig_Electron, "True Energy (MeV)");
    analysisManager->SetH2YAxisTitle(Det2_Mig_Electron, "Measured Energy (MeV)");
    analysisManager->SetH2ZAxisTitle(Det2_Mig_Electron, "# of Events");
    analysisManager->SetH2Activation(Det1_Mig_Electron, true);

    //
    G4int Det3_Mig_Electron = analysisManager->CreateH2("Det3 Energy Migration Matrix", "Energy Migration Matrix for Electrons", N_bin, cSourceErgMin, cSourceErgMax, N_bin, cSourceErgMin, cSourceErgMax, "none", "none", "none", "none", "log", "log");
    analysisManager->SetH2XAxisTitle(Det3_Mig_Electron, "True Energy (MeV)");
    analysisManager->SetH2YAxisTitle(Det3_Mig_Electron, "Measured Energy (MeV)");
    analysisManager->SetH2ZAxisTitle(Det3_Mig_Electron, "# of Events");
    analysisManager->SetH2Activation(Det3_Mig_Electron, true);
    
    //source spectrum
    G4int Source_generation = analysisManager->CreateH1("Generated Source Spectrum", "Source spectrum", N_bin, cSourceErgMin, cSourceErgMax, "none", "none", "log");
    analysisManager->SetH1XAxisTitle(Source_generation, "Source Energy (MeV)");
    analysisManager->SetH1YAxisTitle(Source_generation, "# of Events");
    analysisManager->SetH1Activation(Source_generation, true);
}

MyRunAction::~MyRunAction()
{}

void MyRunAction::BeginOfRunAction(const G4Run*)
{

	auto analysisManager = G4AnalysisManager::Instance();

    G4String fileMame = analysisManager->GetFileName() + ".root";
	//G4String fileMame = "VIS_test_output.root";
	analysisManager->OpenFile(fileMame);

}


void MyRunAction::EndOfRunAction(const G4Run*)
{

	auto analysisManager = G4AnalysisManager::Instance();
	analysisManager->Write();
	analysisManager->CloseFile();
}
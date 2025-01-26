#include "eventAction.hh"

MyEventAction::MyEventAction(MyRunAction*) {

}

MyEventAction::~MyEventAction() {}

void MyEventAction::BeginOfEventAction(const G4Event*) {
    // Get hits collections IDs (only once)
    if (fSiDetHCID == -1) {
        fSiDetHCID
            = G4SDManager::GetSDMpointer()->GetCollectionID("SiDetHitsCollection");
    }
}

void MyEventAction::EndOfEventAction(const G4Event* event) {

    G4int eventIdentifier = event->GetEventID();

    //G4cout << "Event_ID = " << eventIdentifier << G4endl;

    auto* collection = event->GetHCofThisEvent();
    SDHitsCollection* trackerCollection{ nullptr };

    G4double Det_0_depositedEnergytotal{ 0 };
    G4double Det_1_depositedEnergytotal{ 0 };
    G4double Det_2_depositedEnergytotal{ 0 };
    G4double Det_3_depositedEnergytotal{ 0 };
    G4double E_dep_total{ 0 };

    if (collection != nullptr) {


        trackerCollection = (SDHitsCollection*)(collection->GetHC(fSiDetHCID));



        if (trackerCollection != nullptr) {
            G4int numberOfHits = trackerCollection->entries();
            //G4cout << "Number of tracker hits in this event: " << numberOfHits << G4endl;

            G4double depositedEnergy{ 0 };
            G4int DetNumber = 0;


            // This is a cycle on all the tracker hits of this event

            for (auto i = 0; i < numberOfHits; i++) {
                // Here we put the hit data in an ASCII file for later analysis
                depositedEnergy = (*trackerCollection)[i]->GetEdep();
                DetNumber = (*trackerCollection)[i]->GetDetNumber();


                /*G4cout << std::setw(7) << eventIdentifier/
                *G4cout << " " << DetNumber
                    << " " << depositedEnergy / keV
                    << " " << G4endl;*/
                //G4cout << "detnumber =" << DetNumber << G4endl;

                if (DetNumber == 0) {
                    Det_0_depositedEnergytotal += depositedEnergy;

                    //G4cout << "Det0 E=" << Det_0_depositedEnergytotal << G4endl;
                }

                if (DetNumber == 1) {
                    Det_1_depositedEnergytotal += depositedEnergy;
                    //G4cout << "Det1 E=" << Det_1_depositedEnergytotal << G4endl;
                }


                if (DetNumber == 2) {
                    Det_2_depositedEnergytotal += depositedEnergy;
                    //G4cout << "Det2 E=" << Det_2_depositedEnergytotal << G4endl;

                }

                if (DetNumber == 3) {
                    Det_3_depositedEnergytotal += depositedEnergy;
                    //G4cout << "Det2 E=" << Det_2_depositedEnergytotal << G4endl;

                }



            }

            /*G4cout << "Det0 Edep=" << Det_0_depositedEnergytotal << G4endl;
            G4cout << "Det1 Edep=" << Det_1_depositedEnergytotal << G4endl;
            G4cout << "Det2 Edep=" << Det_2_depositedEnergytotal << G4endl;
            G4cout << "Det3 Edep=" << Det_3_depositedEnergytotal << G4endl;


            E_dep_total = Det_0_depositedEnergytotal + Det_1_depositedEnergytotal + Det_2_depositedEnergytotal + Det_3_depositedEnergytotal;
            G4cout << "Total E_dep in Silicon = " << E_dep_total << G4endl;*/

            G4double einit = event->GetPrimaryVertex()->GetPrimary()->GetKineticEnergy();
            //G4cout << "init E=" << einit << G4endl;


            G4AnalysisManager* man = G4AnalysisManager::Instance();


            // fill ntuple and fill histograms 
            //man->FillNtupleDColumn(0, eventIdentifier);
            man->FillNtupleDColumn(0, einit);

            man->FillH1(man->GetH1Id("Generated Source Spectrum"), einit / MeV);

            //define a minimal energy threshold 
            const G4double eThreshold = 1. * keV;
            
            if (Det_0_depositedEnergytotal > eThreshold) {

                man->FillNtupleDColumn(1, Det_0_depositedEnergytotal);
                man->FillH1(man->GetH1Id("Si Det0 - Measured Spectrum"), Det_0_depositedEnergytotal / MeV);
                man->FillH2(man->GetH2Id("Det0 Energy Migration Matrix"), einit / MeV, Det_0_depositedEnergytotal / MeV);
            }

            //store raw spectrum data 
            if (Det_1_depositedEnergytotal > eThreshold){

                man->FillH1(man->GetH1Id("Si Det1 - Measured Spectrum"), Det_1_depositedEnergytotal / MeV);
                man->FillH2(man->GetH2Id("Det1 Energy Migration Matrix"), einit / MeV, Det_1_depositedEnergytotal / MeV);
            }

            if (Det_2_depositedEnergytotal > eThreshold) {
                
                man->FillH1(man->GetH1Id("Si Det2 - Measured Spectrum"), Det_2_depositedEnergytotal / MeV);
                man->FillH2(man->GetH2Id("Det2 Energy Migration Matrix"), einit / MeV, Det_2_depositedEnergytotal / MeV);
            }

            if (Det_3_depositedEnergytotal > eThreshold) {
                
                man->FillH1(man->GetH1Id("Si Det3 - Measured Spectrum"), Det_3_depositedEnergytotal / MeV);
                man->FillH2(man->GetH2Id("Det3 Energy Migration Matrix"), einit / MeV, Det_3_depositedEnergytotal / MeV);
            }

            
            //only record event that triggered Det0 first in the Ntuple book for Det1,2,3 in order to reduce the size of the output file 
            
            if (Det_0_depositedEnergytotal > eThreshold && Det_1_depositedEnergytotal > eThreshold) {

                man->FillNtupleDColumn(2, Det_1_depositedEnergytotal);
                
            }

            
            if (Det_0_depositedEnergytotal > eThreshold && Det_2_depositedEnergytotal > eThreshold) {

                man->FillNtupleDColumn(3, Det_2_depositedEnergytotal);
                
            }

            
            if (Det_0_depositedEnergytotal > eThreshold && Det_3_depositedEnergytotal > eThreshold) {

                man->FillNtupleDColumn(4, Det_3_depositedEnergytotal);
            
            }


            man->AddNtupleRow();


        }


    }
}
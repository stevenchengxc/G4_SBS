#include "SensitiveDetector.hh"




//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

SensitiveDetector::SensitiveDetector(const G4String& name,
    const G4String& hitsCollectionName)
    : G4VSensitiveDetector(name)
{
    collectionName.insert(hitsCollectionName);


    tkrHitID = new G4int[numberOfTKRChannels];
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

SensitiveDetector::~SensitiveDetector()
{
    delete[] tkrHitID;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void SensitiveDetector::Initialize(G4HCofThisEvent* hce)
{
    //G4cout<<"Initialize SD" << G4endl;
    // Create hits collection
    fHitsCollection
        = new SDHitsCollection(SensitiveDetectorName, collectionName[0]);

    // Add this collection in hce
    auto hcID
        = G4SDManager::GetSDMpointer()->GetCollectionID(collectionName[0]);
    hce->AddHitsCollection(hcID, fHitsCollection);

    // Create hits
    // fNofCells for cells + one more for total sums
    /*for (G4int i = 0; i < fNofCells + 1; i++) {
        fHitsCollection->insert(new SDHit());
    }*/

    //4 Si detectors
    numberOfTKRChannels = 4;

    //set tkrHitID inital value to -1 as default 
    for (auto i = 0; i < numberOfTKRChannels; i++) {
        tkrHitID[i] = -1;

    };


}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

G4bool SensitiveDetector::ProcessHits(G4Step* step,
    G4TouchableHistory*)
{

    G4double edep = 0.;
    edep = step->GetTotalEnergyDeposit();
    if (edep == 0.) {
        return false;
    }

    G4StepPoint* preStep = step->GetPreStepPoint();
    G4double kineticEnergy = preStep->GetKineticEnergy();

    // This TouchableHistory is used to obtain the physical volume of the hit
    auto* touchable = (G4TouchableHistory*)(step->GetPreStepPoint()->GetTouchable());

    // Get detector id
    auto* detVol = touchable->GetVolume();

    auto detName = detVol->GetName();
    //G4cout << "det volume = " << detName <<G4endl;
    //G4cout << "KE per det volume = " << kineticEnergy << G4endl;
    //G4cout << "edep det volume = " << edep << G4endl;


    auto detNumber = detVol->GetCopyNo();
    //G4cout << "det number = " << detNumber << G4endl;

 
    if (tkrHitID[detNumber] == -1) { //new hit
        auto* trackerHit = new SDHit;
        trackerHit->AddDepositedEnergy(edep);
        //trackerHit->GetPosition(step->GetPreStepPoint()->GetPosition());
        trackerHit->findDetNumber(detNumber);
        tkrHitID[detNumber] = fHitsCollection->insert(trackerHit) - 1;

    }
    else { // This is not new
        (*fHitsCollection)[tkrHitID[detNumber]]->AddDepositedEnergy(edep);

    }
    //tkrHitXID[channelNumber] = fHitsCollection->insert(trackerHit) - 1;

    // Get hit accounting data for this cell
    //auto Dethit = (*fHitsCollection)[detNumber];

    //if (!Dethit) {
    //    G4ExceptionDescription msg;
    //    msg << "Cannot access hit " << detNumber;
    //    G4Exception("CalorimeterSD::ProcessHits()",
    //        "MyCode0004", FatalException, msg);
    //}

    //// Get hit for total accounting
    //auto hitTotal
    //    = (*fHitsCollection)[fHitsCollection->entries() - 1];

    //// Add values
    //Dethit->AddDepositedEnergy(edep);
    //hitTotal->AddDepositedEnergy(edep);

    return true;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void SensitiveDetector::EndOfEvent(G4HCofThisEvent*)
{
    if (verboseLevel > 1) {
        auto nofHits = fHitsCollection->entries();
        G4cout
            << G4endl
            << "-------->Hits Collection: in this event they are " << nofHits
            << " hits in the tracker chambers: " << G4endl;
        for (std::size_t i = 0; i < nofHits; ++i) (*fHitsCollection)[i]->Print();
    }

    for (auto i = 0; i < numberOfTKRChannels; i++) {
        tkrHitID[i] = -1;

    };

}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......



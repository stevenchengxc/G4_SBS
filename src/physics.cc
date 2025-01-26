#include "physics.hh"

MyPhysicsList::MyPhysicsList() : G4VModularPhysicsList(),
fEmPhysicsList(0),
fDecayPhysicsList(0),
fRadioactiveDecayPhysicsList(0)
{
    // Default cut value 100 um
    SetDefaultCutValue(100 * um);

    // Verbosity level
    SetVerboseLevel(2);

    // Decay Physics is always defined
    fDecayPhysicsList = new G4DecayPhysics();

    // Radioactive Decay Physics
    fRadioactiveDecayPhysicsList = new G4RadioactiveDecayPhysics();

    // EM physics
    //default EM physics G4EmStandardPhysics_option4 - most accruate
    fEmPhysicsList = new G4EmStandardPhysics_option4();

    //additional physics lists
    // EM physics in thin material and gas cavity (Photoabsorption Ionization Model)
    // fEmName = G4String("pai_photon");
    fEmName = G4String("pai");

    //step limit for all particles 
    G4StepLimiterPhysics* stepLimitPhys = new G4StepLimiterPhysics();
    stepLimitPhys->SetApplyToAll(true); // activates step limit for ALL particles
    RegisterPhysics(stepLimitPhys);

}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

MyPhysicsList::~MyPhysicsList()
{
    delete fDecayPhysicsList;
    delete fRadioactiveDecayPhysicsList;
    delete fEmPhysicsList;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void MyPhysicsList::ConstructParticle()
{
    fDecayPhysicsList->ConstructParticle();
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void MyPhysicsList::ConstructProcess()
{
    // Transportation Physics
    AddTransportation();

    // Electromagnetic Physics
    fEmPhysicsList->ConstructProcess();
    AddPhysicsList(fEmName);
    SetCuts();

    // Decay Physics
    fDecayPhysicsList->ConstructProcess();

    // Radioactive Decay Physics
    fRadioactiveDecayPhysicsList->ConstructProcess();
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void MyPhysicsList::AddPhysicsList(const G4String& name)
{
    if (verboseLevel > 1) {
        G4cout << "PhysicsList::AddPhysicsList: <" << name << ">" << G4endl;
    }

    if (name == fEmName) {
        return;

    }
    else if (name == "emstandard_opt1") {

        fEmName = name;
        delete fEmPhysicsList;
        fEmPhysicsList = new G4EmStandardPhysics_option1();

    }
    else if (name == "emstandard_opt2") {

        fEmName = name;
        delete fEmPhysicsList;
        fEmPhysicsList = new G4EmStandardPhysics_option2();

    }
    else if (name == "emstandard_opt3") {

        fEmName = name;
        delete fEmPhysicsList;
        fEmPhysicsList = new G4EmStandardPhysics_option3();

    }
    else if (name == "emstandard_opt4") {

        fEmName = name;
        delete fEmPhysicsList;
        fEmPhysicsList = new G4EmStandardPhysics_option4();

    }
    else if (name == "emlivermore") {

        fEmName = name;
        delete fEmPhysicsList;
        fEmPhysicsList = new G4EmLivermorePhysics();

    }
    else if (name == "empenelope") {

        fEmName = name;
        delete fEmPhysicsList;
        fEmPhysicsList = new G4EmPenelopePhysics();

    }
    else if (name == "pai") {

        fEmName = name;
        G4EmParameters::Instance()->AddPAIModel("all", "thinRegion", "pai");

    }
    else if (name == "pai_photon") {

        fEmName = name;
        G4EmParameters::Instance()->AddPAIModel("all", "thinRegion", "pai_photon");

    }
    else {

        G4cout << "PhysicsList::AddPhysicsList: <" << name << ">"
            << " is not defined"
            << G4endl;
    }
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void MyPhysicsList::SetCuts()
{

    // Special threshold for low energy physics
    G4ProductionCutsTable::GetProductionCutsTable()->SetEnergyRange(990 * eV, 1 * GeV);

    // Default production thresholds for the world volume
    SetCutsWithDefault();

    // Production cuts for the thin region including mylar window and Si detector electrodes
    G4String regName1 = "thinRegion";
    G4Region* region_thinRegion = G4RegionStore::GetInstance()->GetRegion(regName1);
    G4ProductionCuts* cuts_thinRegion = new G4ProductionCuts;
    cuts_thinRegion->SetProductionCut(0.01 * um); // same cuts for gamma, e- and e+
    region_thinRegion->SetProductionCuts(cuts_thinRegion);

    // Production cuts for the Si Sensitive Volume region
    G4String regName2 = "SiSensitiveVolume";
    G4Region* region_SiSensitiveVolume = G4RegionStore::GetInstance()->GetRegion(regName2);
    G4ProductionCuts* cuts_SiSensitiveVolume = new G4ProductionCuts;
    cuts_SiSensitiveVolume->SetProductionCut(1 * um); // same cuts for gamma, e- and e+
    region_SiSensitiveVolume->SetProductionCuts(cuts_SiSensitiveVolume);

    //when verboselevel>0, display cut table
    if (verboseLevel > 0) { DumpCutValuesTable(); }
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

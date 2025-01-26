#include <iostream>

#include "G4RunManager.hh"
#include "G4MTRunManager.hh"
#include "G4UImanager.hh"
#include "G4VisManager.hh"
#include "G4VisExecutive.hh"
#include "G4UIExecutive.hh"

#include "DetectorConstruction.hh"
#include "physics.hh"
#include "action.hh"
#include "generator.hh"

int main(int argc, char** argv){

    G4UIExecutive* ui = nullptr;

    //initialize random number geneator
    CLHEP::HepRandom::setTheSeed((long)time(NULL));

    if (argc == 1)
    {

        ui = new G4UIExecutive(argc, argv);
    }

    G4VisManager* visManager = new G4VisExecutive();
    visManager->Initialize();


    if (ui)
    {   
        //single-thread for UI mode. multi-thread may lead to memory issues
        G4RunManager* runManager = new G4RunManager();

        runManager->SetUserInitialization(new MyDetectorConstruction());
        runManager->SetUserInitialization(new MyPhysicsList());
        runManager->SetUserInitialization(new MyActionInitialization());

        G4UImanager* UImanager = G4UImanager::GetUIpointer();
        //if vis.mac marco exist and no other marco input at run, by default it run in GUI mode
        
        runManager->Initialize();
        UImanager->ApplyCommand("/control/execute vis.mac");

        ui->SessionStart();

        delete ui;
    }
    else
    {
       //multi-thread for batch mode
        #ifdef G4MULTITHREADED
                G4MTRunManager* runManager = new G4MTRunManager();
        #else
                G4RunManager* runManager = new G4RunManager();
        #endif



        runManager->SetUserInitialization(new MyDetectorConstruction());
        runManager->SetUserInitialization(new MyPhysicsList());
        runManager->SetUserInitialization(new MyActionInitialization());

        G4UImanager* UImanager = G4UImanager::GetUIpointer();
        //batch mode, run macro file user specified 


        //runManager->Initialize();

        G4String command = "/control/execute ";
        G4String fileName = argv[1];
        UImanager->ApplyCommand(command + fileName);

        //start a run and time it, with progress
        /*
        auto start = std::chrono::high_resolution_clock::now();
        UImanager->ApplyCommand("/run/printProgress " + std::to_string(cNumEventsPerPrint));
        UImanager->ApplyCommand("/run/beamOn " + std::to_string(cNumEvents));
        auto stop = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::seconds>(stop - start);
        G4cout << "Run Time: " << duration.count() << " s" << G4endl;
        */
        delete visManager;
        delete runManager;

    }


    return 0;
}
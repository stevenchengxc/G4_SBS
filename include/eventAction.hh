#ifndef EVENTACTION_HH
#define EVENTACTION_H

#include "runAction.hh"
#include "SDHit.hh"

#include "G4UserEventAction.hh"
#include "G4Event.hh"
#include "G4PrimaryVertex.hh"
#include "G4RunManager.hh"
#include "G4SDManager.hh"
#include "G4HCofThisEvent.hh"
#include "G4UnitsTable.hh"
#include "G4AnalysisManager.hh"

#include "SensitiveDetector.hh"

class MyEventAction :public G4UserEventAction
{
    public:
        MyEventAction(MyRunAction*);
        ~MyEventAction();

        virtual void BeginOfEventAction(const G4Event*);
        virtual void EndOfEventAction(const G4Event*);


    private:
        G4int fSiDetHCID= -1;
};

#endif

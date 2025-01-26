//
// ********************************************************************
// * License and Disclaimer                                           *
// *                                                                  *
// * The  Geant4 software  is  copyright of the Copyright Holders  of *
// * the Geant4 Collaboration.  It is provided  under  the terms  and *
// * conditions of the Geant4 Software License,  included in the file *
// * LICENSE and available at  http://cern.ch/geant4/license .  These *
// * include a list of copyright holders.                             *
// *                                                                  *
// * Neither the authors of this software system, nor their employing *
// * institutes,nor the agencies providing financial support for this *
// * work  make  any representation or  warranty, express or implied, *
// * regarding  this  software system or assume any liability for its *
// * use.  Please see the license in the file  LICENSE  and URL above *
// * for the full disclaimer and the limitation of liability.         *
// *                                                                  *
// * This  code  implementation is the result of  the  scientific and *
// * technical work of the GEANT4 collaboration.                      *
// * By using,  copying,  modifying or  distributing the software (or *
// * any work based  on the software)  you  agree  to acknowledge its *
// * use  in  resulting  scientific  publications,  and indicate your *
// * acceptance of all terms of the Geant4 Software license.          *
// ********************************************************************
//
//
/// based on B4 and G4 gamma telescope example 

#ifndef SDHit_hh
#define SDHit_hh

#include "G4VHit.hh"
#include "G4THitsCollection.hh"
#include "G4Allocator.hh"
#include "G4ThreeVector.hh"
#include "G4Threading.hh"



class SDHit : public G4VHit
{
  public:
    SDHit() = default;
    SDHit(const SDHit&) = default;
    ~SDHit() override = default;

    // operators
    SDHit& operator=(const SDHit&) = default;
    G4bool operator==(const SDHit&) const;

    inline void* operator new(size_t);
    inline void  operator delete(void*);

    // methods from base class
    void Draw()  override{}
    void Print() override;

    // methods to add deposited energy de
    void AddDepositedEnergy(G4double de);

    void findDetNumber(const G4int& value);

    // methods of get Edep
    G4double GetEdep() const;
    //G4double GetTrackLength() const;

    //methods to get detector number
    G4int GetDetNumber() const;
    

  private:
    G4int  SiDetNum = 0;           //silicon detector number 
    G4double fEdep = 0.;        ///< Energy deposit in the sensitive volume
    //G4double fTrackLength = 0.; ///< Track length in the  sensitive volume
};

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

using SDHitsCollection = G4THitsCollection<SDHit>;

extern G4ThreadLocal G4Allocator<SDHit>* SDHitAllocator;

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

inline void* SDHit::operator new(size_t)
{
  if (!SDHitAllocator) {
    SDHitAllocator = new G4Allocator<SDHit>;
  }
  void *hit;
  hit = (void *) SDHitAllocator->MallocSingle();
  return hit;
}

inline void SDHit::operator delete(void *hit)
{
  if (!SDHitAllocator) {
    SDHitAllocator = new G4Allocator<SDHit>;
  }
  SDHitAllocator->FreeSingle((SDHit*) hit);
}
inline void SDHit:: findDetNumber(const G4int & value){
    SiDetNum = value;
}

inline G4int SDHit::GetDetNumber() const {
  
    return SiDetNum;
}

//inline void SDHit::Add(G4double de, G4double dl) {
inline void SDHit::AddDepositedEnergy(G4double de) {
    fEdep += de;
  //fTrackLength += dl;
}

inline G4double SDHit::GetEdep() const {
    return fEdep;
}



//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#endif

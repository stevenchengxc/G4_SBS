#include "generator.hh"

MyPrimaryGenerator::MyPrimaryGenerator()
{
    //fParticleGun = new G4ParticleGun(1); //number of particles per event=1
    gps = new G4GeneralParticleSource();
}
MyPrimaryGenerator::~MyPrimaryGenerator()
{
    //delete fParticleGun;
    delete gps;
}

void MyPrimaryGenerator::GeneratePrimaries(G4Event* anEvent)
{   
    gps->GeneratePrimaryVertex(anEvent);
    /*G4ParticleTable* particleTable = G4ParticleTable::GetParticleTable();
    G4String particleName = "electron";
    G4ParticleDefinition* particle = particleTable->FindParticle(particleName);

    G4ThreeVector pos(0., 0., 0.);
    G4ThreeVector mom(0., 0., -1.);

    fParticleGun->SetParticlePosition(pos);
    fParticleGun->SetParticleMomentumDirection(mom);
    fParticleGun->SetParticleMomentum(1.0 * MeV);
    fParticleGun->SetParticleDefinition(particle);

    fParticleGun->GeneratePrimaryVertex(anEvent);*/
}
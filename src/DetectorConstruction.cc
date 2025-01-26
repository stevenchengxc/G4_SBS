#include "DetectorConstruction.hh"

MyDetectorConstruction::MyDetectorConstruction()
{}

MyDetectorConstruction::~MyDetectorConstruction()
{}

G4VPhysicalVolume* MyDetectorConstruction::Construct()
{   
    // NIST Manager
    G4NistManager* nist = G4NistManager::Instance();
    
    //....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo.....
    // NIST materials
    //G4Material* galactic = nist->FindOrBuildMaterial("G4_Galactic");
    G4Material* Air = nist->FindOrBuildMaterial("G4_AIR");
    G4Material* Vacuum = nist->FindOrBuildMaterial("G4_Galactic");
    G4Material* Si = nist->FindOrBuildMaterial("G4_Si");
    G4Material* Polyethylene = nist->FindOrBuildMaterial("G4_POLYETHYLENE");
    G4Material* Ceramic = nist->FindOrBuildMaterial("G4_ALUMINUM_OXIDE");
    G4Material* Al = nist->FindOrBuildMaterial("G4_Al");
    G4Material* Cu = nist->FindOrBuildMaterial("G4_Cu");
    G4Material* Mg = nist->FindOrBuildMaterial("G4_Mg");
    G4Material* Fe = nist->FindOrBuildMaterial("G4_Fe");
    G4Material* Mylar = nist->FindOrBuildMaterial("G4_MYLAR");


    //Aluminium alloy 6061-T6
    G4Material* Al6061 = new G4Material("Al6061", 2.70 * g / cm3, 4);
    Al6061->AddMaterial(Al, 98.0 * perCent);
    Al6061->AddMaterial(Mg, 1.0 * perCent);
    Al6061->AddMaterial(Si, 0.6 * perCent);
    Al6061->AddMaterial(Fe, 0.4 * perCent);

    //FR4-G10 - from here: http://personalpages.to.infn.it/~tosello/EngMeet/ITSmat/SDD/SDD_G10FR4.html
    //It is in general agreement with other sources on the web so seems reasonable
    G4Material* SiO2 = new G4Material("Si02", 2.201 * g / cm3, 2);
    SiO2->AddElement(nist->FindOrBuildElement("Si"), 1);
    SiO2->AddElement(nist->FindOrBuildElement("O"), 2);
    G4Material* CaO = new G4Material("CaO", 3.340 * g / cm3, 2);
    CaO->AddElement(nist->FindOrBuildElement("Ca"), 1);
    CaO->AddElement(nist->FindOrBuildElement("O"), 1);
    G4Material* Al2O3 = new G4Material("Al2O3", 3.97 * g / cm3, 2);
    Al2O3->AddElement(nist->FindOrBuildElement("Al"), 2);
    Al2O3->AddElement(nist->FindOrBuildElement("O"), 3);
    G4Material* MgO = new G4Material("MgO", 3.600 * g / cm3, 2);
    MgO->AddElement(nist->FindOrBuildElement("O"), 1);
    MgO->AddElement(nist->FindOrBuildElement("Mg"), 1);
    G4Material* B2O3 = new G4Material("B2O3", 2.550 * g / cm3, 2);
    B2O3->AddElement(nist->FindOrBuildElement("O"), 3);
    B2O3->AddElement(nist->FindOrBuildElement("B"), 2);
    G4Material* TiO2 = new G4Material("TiO2", 4.230 * g / cm3, 2);
    TiO2->AddElement(nist->FindOrBuildElement("O"), 2);
    TiO2->AddElement(nist->FindOrBuildElement("Ti"), 1);
    G4Material* Na2O = new G4Material("Na2O", 2.270 * g / cm3, 2);
    Na2O->AddElement(nist->FindOrBuildElement("O"), 1);
    Na2O->AddElement(nist->FindOrBuildElement("Na"), 2);
    G4Material* K2O = new G4Material("K2O", 2.350 * g / cm3, 2);
    K2O->AddElement(nist->FindOrBuildElement("O"), 1);
    K2O->AddElement(nist->FindOrBuildElement("K"), 2);
    G4Material* Fe2O3 = new G4Material("Fe2O3", 5.250 * g / cm3, 2);
    Fe2O3->AddElement(nist->FindOrBuildElement("O"), 2);
    Fe2O3->AddElement(nist->FindOrBuildElement("Fe"), 3);
    G4Material* F2 = new G4Material("F2", 5.250 * g / cm3, 1);
    F2->AddElement(nist->FindOrBuildElement("F"), 2);
    G4Material* FR4 = new G4Material("FR4", 2.61 * g / cm3, 10);
    FR4->AddMaterial(SiO2, 54.0 * perCent);
    FR4->AddMaterial(CaO, 19.0 * perCent);
    FR4->AddMaterial(Al2O3, 13.0 * perCent);
    FR4->AddMaterial(MgO, 2.5 * perCent);
    FR4->AddMaterial(B2O3, 7.5 * perCent);
    FR4->AddMaterial(TiO2, 0.8 * perCent);
    FR4->AddMaterial(Na2O, 1.0 * perCent);
    FR4->AddMaterial(K2O, 1.0 * perCent);
    FR4->AddMaterial(Fe2O3, 0.5 * perCent);
    FR4->AddMaterial(F2, 0.7 * perCent);
    G4Material* C19H20O4 = new G4Material("C19H20O4", 1.16 * g / cm3, 3);
    C19H20O4->AddElement(nist->FindOrBuildElement("C"), 19);
    C19H20O4->AddElement(nist->FindOrBuildElement("H"), 20);
    C19H20O4->AddElement(nist->FindOrBuildElement("O"), 4);
    G4Material* C10H18O4 = new G4Material("C10H18O4", 1.10 * g / cm3, 3);
    C10H18O4->AddElement(nist->FindOrBuildElement("C"), 10);
    C10H18O4->AddElement(nist->FindOrBuildElement("H"), 18);
    C10H18O4->AddElement(nist->FindOrBuildElement("O"), 4);
    G4Material* C9H22N2 = new G4Material("C9H22N2", 0.865 * g / cm3, 3);
    C9H22N2->AddElement(nist->FindOrBuildElement("N"), 2);
    C9H22N2->AddElement(nist->FindOrBuildElement("C"), 9);
    C9H22N2->AddElement(nist->FindOrBuildElement("H"), 22);
    G4Material* Epotek301_1 = new G4Material("Epotek301_1", 1.19 * g / cm3, 3);
    Epotek301_1->AddMaterial(C19H20O4, 56 * perCent);
    Epotek301_1->AddMaterial(C10H18O4, 24 * perCent);
    Epotek301_1->AddMaterial(C9H22N2, 20 * perCent);
    G4Material* FR4G10 = new G4Material("FR4G10", 1.80 * g / cm3, 2);
    FR4G10->AddMaterial(Epotek301_1, 40 * perCent);
    FR4G10->AddMaterial(FR4, 60 * perCent);

    //PEEK
    G4Material* PEEK = new G4Material("PEEK", 1.320 * g / cm3, 3);
    PEEK->AddElement(nist->FindOrBuildElement("C"), 19);
    PEEK->AddElement(nist->FindOrBuildElement("H"), 14);
    PEEK->AddElement(nist->FindOrBuildElement("O"), 3);

    //Aluminized mylar
    //2% aluminum and the rest mylar; is that true??
    G4Material * AlMylar = new G4Material("AlMylar",  1.40 * g / cm3, 2);
    AlMylar->AddMaterial(Mylar, 98 * perCent);
    AlMylar->AddMaterial(Al, 2 * perCent);

    //....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo.....
    
    //World definition
    G4Box* solidWorld = new G4Box("solidWorld", 0.5 * m, 0.5 * m, 0.5 * m); //a 1x1x1 m^3 box named solidword 
    G4LogicalVolume* logicWorld = new G4LogicalVolume(solidWorld, Air, "logicWorld");
    G4VPhysicalVolume* physWorld = new G4PVPlacement(0, G4ThreeVector(0., 0., 0.), logicWorld, "physWorld", 0, false, 0, true); 

    //Source hemisphere
    G4Sphere* sourceCap = new G4Sphere("sourceCap", 7.999 * cm, 8.001 * cm, 0 * degree, 360 * degree, 0 * degree, 360 * degree); //default full sphere. if only use the cap of a large sphere is needed, change the angles
    G4LogicalVolume* logicSourceCap = new G4LogicalVolume(sourceCap, Air, "logicSourceCap"); //no source material
    G4VPhysicalVolume* physSourceCap = new G4PVPlacement(0, G4ThreeVector(0., 0., 0 * cm), logicSourceCap, "physSourceCap", logicWorld, false, 0, true); 

    //Geometry parameters and constants

    G4double collimatortub_outR = 45 * mm;
    G4double collimatortub_inR = 35 * mm;
    G4double collimatortub_Z = 36.0 * mm;


    G4double collimatorBaffle_outR = 69 / 2. * mm;
    G4double collimatorBaffle_inR1 = 27 / 2. * mm;
    G4double collimatorBaffle_inR2 = 19 / 2. * mm;
    G4double collimatorBaffle_Z = 3 * mm;
    
    G4double collimatorSpacer_outR = 69 / 2. * mm;
    G4double collimatorSpacer_inR = 33 / 2. * mm;
    G4double collimatorSpacer_Z = 3.6 * mm;
    
    G4double plateX = 96.8 * mm;
    G4double plateY = 96.8 * mm;
    G4double plateZ = 7.4 * mm;
    G4double WindowR = 15 * mm;
    G4double indentZ = 0.4 * mm;

    G4double filmwindow_carrier_Z = 3 * um; // 3 um mylar carrier thickness 
    G4double filmwindow_metalayer_Z = 90 * nm; //600-1200 A aluminum layer on both side. Take 900 A =90 nm as the nominal thickness 

    G4double frame_Z = 2.5 * mm;
    G4double frame_R = 59 / 2. * mm;
    G4double windowframe_R = 35 / 2. * mm;
    

    G4double layer_Z = collimatorBaffle_Z + collimatorSpacer_Z; 
    G4int fNoflayers = 5;

    G4double CollimatorCylinder_Z = layer_Z * fNoflayers; 

    G4double collimatorlid_outR = 90 / 2. * mm;
    G4double collimatorlid_inR = 30 / 2. * mm;
    G4double collimatorlid_Z = 3. * mm;

    G4double topplate_X = 96.8 * mm;
    G4double topplate_Y = 96.8 * mm;
    G4double topplate_Z = 7.5 * mm;
    G4double topplate_opening_R = 70 / 2. * mm;


    //collimator tub
 
    G4Tubs* CollimatorTub = new G4Tubs("CollimatorTub", collimatortub_inR, collimatortub_outR, collimatortub_Z / 2., 0., 2 * PI);
    G4LogicalVolume* logicCollimatorTub = new G4LogicalVolume(CollimatorTub, Al6061, "logicCollimatorTub");
    G4PVPlacement* physCollimatorTub = new G4PVPlacement(0, G4ThreeVector(0., 0., collimatortub_Z / 2. + plateZ / 2. - indentZ * mm), logicCollimatorTub, "physCollimatorTub", logicWorld, false, 0, true);

    //collimatorCylinder is a mother volume used for replication of the layer
    G4Tubs* CollimatorCylinder = new G4Tubs("CollimatorCylinder", 0, collimatortub_inR, CollimatorCylinder_Z /2., 0., 2 * PI);
    G4LogicalVolume* logicCollimatorCylinder = new G4LogicalVolume(CollimatorCylinder, Air, "logicCollimatorCylinder");
    G4PVPlacement* physCollimatorCylinder = new G4PVPlacement(0, G4ThreeVector(0., 0., CollimatorCylinder_Z / 2. + plateZ / 2.  - indentZ * mm), logicCollimatorCylinder, "physCollimatorCylinder", logicWorld, false, 0, true);

    //layer Note: the logical volume layer consists of a baffle and a spacer, refers to example B4 
    G4Tubs* layer = new G4Tubs("layer", 0, collimatortub_inR, layer_Z/2, 0., 2 * PI);
    auto logicLayer = new G4LogicalVolume(layer, Air, "logicLayer");

    new G4PVReplica(
        "layer",          // its name
        logicLayer,          // its logical volume
        logicCollimatorCylinder,          // its mother
        kZAxis,           // axis of replication
        fNoflayers,        // number of replica
        layer_Z);  // witdth of replica


    //collimator baffle
    G4Tubs* bafflebody = new G4Tubs("bafflebody", 0, collimatorBaffle_outR, collimatorBaffle_Z/2, 0., 2 * PI);
    //45 degree knife edge cutout
    G4Cons* knifeEdge_cutout = new G4Cons("knifeEdge_cutout", 0, collimatorBaffle_inR1, 0, collimatorBaffle_inR2, collimatorBaffle_Z/2, 0., 2*PI);
    G4SubtractionSolid* CollimatorBaffle = new G4SubtractionSolid("CollimatorBaffle", bafflebody, knifeEdge_cutout);

    G4LogicalVolume* logicCollimatorBaffle = new G4LogicalVolume(CollimatorBaffle, Cu, "logicCollimatorBaffle");
    G4PVPlacement* physCollimatorBaffle = new G4PVPlacement(0, G4ThreeVector(0., 0., -collimatorSpacer_Z/2), logicCollimatorBaffle, "physCollimatorBaffle", logicLayer, false, 0, true);


    //collimator spacer
    G4Tubs* CollimatorSpacer = new G4Tubs("CollimatorSpacer", collimatorSpacer_inR, collimatorSpacer_outR, collimatorSpacer_Z/2, 0., 2*PI);

    G4LogicalVolume* logicCollimatorSpacer = new G4LogicalVolume(CollimatorSpacer, PEEK, "logicCollimatorSpacer");
    G4PVPlacement* physCollimatorSpacer = new G4PVPlacement(0, G4ThreeVector(0., 0., collimatorBaffle_Z / 2), logicCollimatorSpacer, "physCollimatorSpacer", logicLayer, false, 0, true);

    //due to uneven number of collimator baffles (6) and spacers (5), there is one more baffle at the entrance of the colimator tube
    G4LogicalVolume* logicCollimatorBaffle1st = new G4LogicalVolume(CollimatorBaffle, Cu, "logicCollimatorBaffle1st");
    G4PVPlacement* physCollimatorBaffle1st = new G4PVPlacement(0, G4ThreeVector(0., 0., CollimatorCylinder_Z+ plateZ / 2.+ collimatorBaffle_Z / 2.  - indentZ * mm), logicCollimatorBaffle1st, "physCollimatorBaffle1st", logicWorld, false, 0, true);

    //collimator lid
    G4Tubs* CollimatorLid = new G4Tubs("CollimatorLid", collimatorlid_inR, collimatorlid_outR, collimatorlid_Z / 2., 0., 2 * PI);
    G4LogicalVolume* logicCollimatorLid = new G4LogicalVolume(CollimatorLid, Al6061, "logicCollimatorLid");
    G4PVPlacement* physCollimatorLid = new G4PVPlacement(0, G4ThreeVector(0., 0., collimatortub_Z + plateZ / 2.+ collimatorlid_Z / 2. - indentZ * mm), logicCollimatorLid, "physCollimatorLid", logicWorld, false, 0, true);

    //Top plate
    G4Box* topPlatebody = new G4Box("topPlatebody", topplate_X / 2., topplate_Y / 2., topplate_Z / 2.);
    G4Tubs* topPlateOpening = new G4Tubs("topPlateOpening", 0, topplate_opening_R, topplate_Z / 2., 0., 2 * PI);
    G4SubtractionSolid* topPlate = new G4SubtractionSolid("topPlate", topPlatebody, topPlateOpening);
    G4LogicalVolume* logicTopplate = new G4LogicalVolume(topPlate, Al6061, "logicTopplate");

    G4PVPlacement* physTopplate = new G4PVPlacement(0, G4ThreeVector(0., 0., collimatortub_Z + plateZ / 2. + collimatorlid_Z + topplate_Z / 2. - indentZ * mm), logicTopplate, "physTopplate", logicWorld, false, 0, true);
    

    //central window plate (centre of the plate is at (0,0,0)
    G4Box* centerPlate = new G4Box("centerPlate", plateX / 2., plateY / 2., plateZ / 2.);
    G4Tubs* windowhole = new G4Tubs("windowhole", 0, WindowR, plateZ / 2, 0., 2 * PI);
    G4Tubs* indent = new G4Tubs("indent", 0, collimatortub_outR, indentZ / 2, 0., 2 * PI);
    G4SubtractionSolid* indentplate = new G4SubtractionSolid("indentplate", centerPlate, indent, 0, G4ThreeVector(0., 0., plateZ/2.- indentZ / 2. * mm));
    G4SubtractionSolid* Windowplate = new G4SubtractionSolid("windowplate", indentplate, windowhole);
    G4LogicalVolume* logicWindowplate = new G4LogicalVolume(Windowplate, Al6061, "logicCenterPlate");
    G4PVPlacement* physWindowplate = new G4PVPlacement(0, G4ThreeVector(0., 0., 0 * mm), logicWindowplate, "physWindowplate", logicWorld, false, 0, true);

    
    //thin film window
    G4Tubs* windowfilm_carrier = new G4Tubs("windowfilm_carrier", 0, windowframe_R, filmwindow_carrier_Z/2., 0., 2*PI);
    G4Tubs* windowfilm_metalayer = new G4Tubs("windowfilm_metalayer", 0, windowframe_R, filmwindow_metalayer_Z / 2., 0., 2 * PI);
    G4LogicalVolume* logicWindowfilm_carrier = new G4LogicalVolume(windowfilm_carrier, Mylar, "logicWindowfilm_carrier");
    G4LogicalVolume* logicWindowfilm_metalayer = new G4LogicalVolume(windowfilm_metalayer, Al, "logicWindowfilm_matelayer");

    G4PVPlacement* physWindowfilm_metalayer_top = new G4PVPlacement(0, G4ThreeVector(0., 0., -plateZ / 2 - filmwindow_metalayer_Z/2. * mm), logicWindowfilm_metalayer, "physWindowfilm_metalayer_top", logicWorld, false, 0, true);
    G4PVPlacement* physWindowfilm_carrier = new G4PVPlacement(0, G4ThreeVector(0., 0., -plateZ / 2. - filmwindow_metalayer_Z - filmwindow_carrier_Z / 2. * mm), logicWindowfilm_carrier, "physWindowfilm_carrier", logicWorld, false, 0, true);
    G4PVPlacement* physWindowfilm_metalayer_bottom = new G4PVPlacement(0, G4ThreeVector(0., 0., -plateZ / 2. - filmwindow_metalayer_Z - filmwindow_carrier_Z - filmwindow_metalayer_Z / 2. * mm), logicWindowfilm_metalayer, "physWindowfilm_metalayer_bottom", logicWorld, false, 0, true);

    //window frame (spacer between the detector stack and the central plate)
    G4Tubs* windowframe = new G4Tubs("windowframe", windowframe_R, frame_R, frame_Z / 2., 0, 2 * PI);
    G4LogicalVolume* logicwindowframe = new G4LogicalVolume(windowframe, Al6061, "logicwindowframe");
    G4PVPlacement* physwindowframe = new G4PVPlacement(0, G4ThreeVector(0., 0., -plateZ / 2. - 2*filmwindow_metalayer_Z - filmwindow_carrier_Z - frame_Z / 2. * mm), logicwindowframe, "physlogicwindowframe", logicWorld, false, 0, true);
    
    //construct Si detectors stack
    G4String cDetType[4] = {"Si500", "Si1500_1", "Si1500_2",  "Si1500_3"};
    G4int cNumDetectors = 4;
    G4double cDetActiveR = 20. *mm;
    //the true thickness of the MSD040 detectors used in the EST prototype 
    G4double cDetActiveZ_500 = 478. * um; 
    G4double cDetActiveZ_1500_1 = 1514. * um; 
    G4double cDetActiveZ_1500_2 = 1503. * um;
    G4double cDetActiveZ_1500_3 = 1499. * um;
 
    G4double cDetElectrodeZ = 0.3 * um;  //MSD040 electrode thickness 
    G4double cDetDeadlayerZ = 0.5 * um; //MSD040 dead layer thickness
    G4double cDetSupportR = 29.3 * mm; //MSD040 supporting PCB radius
    G4double cDetSupportZ = 2.37 * mm; //MSD040 supporting PCB thickness
    G4double cDetSpacing = cDetSupportZ * mm;
    G4double cDetTopoffset = -plateZ / 2. - 2*filmwindow_metalayer_Z - filmwindow_carrier_Z - frame_Z * mm;

    //MSD040-500: diameter=40 mm, thickness=478 um
    G4Tubs* detActiveArea500 = new G4Tubs("detActiveArea500", 0., cDetActiveR, cDetActiveZ_500 / 2., 0., 2 * PI);

    //MSD040-1500_1: diameter=40 mm, thickness=1514 um
    G4Tubs* detActiveArea1500_1 = new G4Tubs("detActiveArea1500_1", 0., cDetActiveR, cDetActiveZ_1500_1 / 2., 0., 2 * PI);

    //MSD040-1500_2: diameter=40 mm, thickness=1503 um
    G4Tubs* detActiveArea1500_2 = new G4Tubs("detActiveArea1500_2", 0., cDetActiveR, cDetActiveZ_1500_2 / 2., 0., 2 * PI);

    //MSD040-1500_3: diameter=40 mm, thickness=1499 um
    G4Tubs* detActiveArea1500_3 = new G4Tubs("detActiveArea1500_3", 0., cDetActiveR, cDetActiveZ_1500_3 / 2., 0., 2 * PI);


    //place active area
    logicDet500 = new G4LogicalVolume(detActiveArea500, Si, "logicDet500");
    logicDet1500_1 = new G4LogicalVolume(detActiveArea1500_1, Si, "logicDet1500_1");
    logicDet1500_2 = new G4LogicalVolume(detActiveArea1500_2, Si, "logicDet1500_2");
    logicDet1500_3 = new G4LogicalVolume(detActiveArea1500_3, Si, "logicDet1500_3");

    //eletrode of MSD040, cover the whole active area, layer thickness 0.30 um 
    G4Tubs* detElectrode = new G4Tubs("detElectrode", 0, cDetActiveR, cDetElectrodeZ / 2., 0., 2 * PI);

    //deadlayer of MSD040 silicon cover the whole active area, layer thickness 0.50 um
    G4Tubs* detDeadlayer = new G4Tubs("detDeadlayer", 0, cDetActiveR, cDetDeadlayerZ / 2., 0., 2 * PI);


    //place electrode
    G4LogicalVolume* logicDetElectrode = new G4LogicalVolume(detElectrode, Al, "logicDetElectrode");

    //place deadlayer
    G4LogicalVolume* logicDetDeadlayer = new G4LogicalVolume(detDeadlayer, Si, "logicDetDeadlayer");

    //MSD040 PCB structure
    G4Tubs* detSupport = new G4Tubs("detSupportBase", cDetActiveR, cDetSupportR, cDetSupportZ / 2., 0, 2 * PI);

    G4LogicalVolume* logicDetSupport = new G4LogicalVolume(detSupport, FR4G10, "logicDetSupport");

    //Silicon Detectors
    for (int i = 0; i < cNumDetectors; i++)
    {   

        G4double ztrans = 0;
        for (int j = 0; j < i; j++) {
            ztrans -= cDetSpacing;
        }
        ztrans = ztrans + (-cDetSupportZ / 2.) + cDetTopoffset; 

        //choose which detector to place
        if (cDetType[i] == "Si500")
        {

            G4VPhysicalVolume* physActiveArea = new G4PVPlacement(0,
                G4ThreeVector(0., 0., ztrans),
                logicDet500,
                "physDetActiveArea_" + std::to_string(i),
                logicWorld,
                false, i, true);

            G4VPhysicalVolume* physActiveAreaElectrodeUp = new G4PVPlacement(0,
                G4ThreeVector(0., 0., ztrans + cDetActiveZ_500 / 2. + cDetElectrodeZ / 2.),
                logicDetElectrode,
                "physDetActiveAreaElectrodeUp_" + std::to_string(i),
                logicWorld,
                false, i, true);

            G4VPhysicalVolume* physActiveAreaElectrodeBottom = new G4PVPlacement(0,
                G4ThreeVector(0., 0., ztrans - cDetActiveZ_500 / 2. - cDetDeadlayerZ / 2. - cDetElectrodeZ / 2.),
                logicDetElectrode,
                "physDetActiveAreaElectrodeBottom_" + std::to_string(i),
                logicWorld,
                false, i, true);

            G4VPhysicalVolume* physActiveAreaDeadlayer = new G4PVPlacement(0,
                G4ThreeVector(0., 0., ztrans - cDetActiveZ_500 / 2. - cDetDeadlayerZ / 2.),
                logicDetDeadlayer,
                "physDetActiveAreaDeadlayer_" + std::to_string(i),
                logicWorld,
                false, i, true);

        }

        else if (cDetType[i] == "Si1500_1")
        {   

            G4VPhysicalVolume* physActiveArea = new G4PVPlacement(0,
                G4ThreeVector(0., 0., ztrans),
                logicDet1500_1,
                "physDetActiveArea_" + std::to_string(i),
                logicWorld,
                false, i, true);

            G4VPhysicalVolume* physActiveAreaElectrodeUp = new G4PVPlacement(0,
                G4ThreeVector(0., 0., ztrans + cDetActiveZ_1500_1 / 2. + cDetElectrodeZ / 2.),
                logicDetElectrode,
                "physDetActiveAreaElectrodeUp_" + std::to_string(i),
                logicWorld,
                false, i, true);

            G4VPhysicalVolume* physActiveAreaElectrodeBottom = new G4PVPlacement(0,
                G4ThreeVector(0., 0., ztrans - cDetActiveZ_1500_1 / 2. - cDetDeadlayerZ / 2. - cDetElectrodeZ / 2.),
                logicDetElectrode,
                "physDetActiveAreaElectrodeBottom_" + std::to_string(i),
                logicWorld,
                false, i, true);

            G4VPhysicalVolume* physActiveAreaDeadlayer = new G4PVPlacement(0,
                G4ThreeVector(0., 0., ztrans - cDetActiveZ_1500_1 / 2. - cDetDeadlayerZ / 2.),
                logicDetDeadlayer,
                "physDetActiveAreaDeadlayer_" + std::to_string(i),
                logicWorld,
                false, i, true);


        }

        else if (cDetType[i] == "Si1500_2")
        {

            G4VPhysicalVolume* physActiveArea = new G4PVPlacement(0,
                G4ThreeVector(0., 0., ztrans),
                logicDet1500_2,
                "physDetActiveArea_" + std::to_string(i),
                logicWorld,
                false, i, true);

            G4VPhysicalVolume* physActiveAreaElectrodeUp = new G4PVPlacement(0,
                G4ThreeVector(0., 0., ztrans + cDetActiveZ_1500_2 / 2. + cDetElectrodeZ / 2.),
                logicDetElectrode,
                "physDetActiveAreaElectrodeUp_" + std::to_string(i),
                logicWorld,
                false, i, true);

            G4VPhysicalVolume* physActiveAreaElectrodeBottom = new G4PVPlacement(0,
                G4ThreeVector(0., 0., ztrans - cDetActiveZ_1500_2 / 2. - cDetDeadlayerZ / 2. - cDetElectrodeZ / 2.),
                logicDetElectrode,
                "physDetActiveAreaElectrodeBottom_" + std::to_string(i),
                logicWorld,
                false, i, true);

            G4VPhysicalVolume* physActiveAreaDeadlayer = new G4PVPlacement(0,
                G4ThreeVector(0., 0., ztrans - cDetActiveZ_1500_2 / 2. - cDetDeadlayerZ / 2.),
                logicDetDeadlayer,
                "physDetActiveAreaDeadlayer_" + std::to_string(i),
                logicWorld,
                false, i, true);


        }

        else if (cDetType[i] == "Si1500_3")
        {

            G4VPhysicalVolume* physActiveArea = new G4PVPlacement(0,
                G4ThreeVector(0., 0., ztrans),
                logicDet1500_3,
                "physDetActiveArea_" + std::to_string(i),
                logicWorld,
                false, i, true);

            G4VPhysicalVolume* physActiveAreaElectrodeUp = new G4PVPlacement(0,
                G4ThreeVector(0., 0., ztrans + cDetActiveZ_1500_3 / 2. + cDetElectrodeZ / 2.),
                logicDetElectrode,
                "physDetActiveAreaElectrodeUp_" + std::to_string(i),
                logicWorld,
                false, i, true);

            G4VPhysicalVolume* physActiveAreaElectrodeBottom = new G4PVPlacement(0,
                G4ThreeVector(0., 0., ztrans - cDetActiveZ_1500_3 / 2. - cDetDeadlayerZ / 2. - cDetElectrodeZ / 2.),
                logicDetElectrode,
                "physDetActiveAreaElectrodeBottom_" + std::to_string(i),
                logicWorld,
                false, i, true);

            G4VPhysicalVolume* physActiveAreaDeadlayer = new G4PVPlacement(0,
                G4ThreeVector(0., 0., ztrans - cDetActiveZ_1500_3 / 2. - cDetDeadlayerZ / 2.),
                logicDetDeadlayer,
                "physDetActiveAreaDeadlayer_" + std::to_string(i),
                logicWorld,
                false, i, true);


        }

         G4VPhysicalVolume* physDetSupport = new G4PVPlacement(0,
                G4ThreeVector(0., 0., ztrans),
                logicDetSupport,
                "physDetSupport_" + std::to_string(i),
                logicWorld,
                false, 0, true);

        }


    //create a region that contains the window mylar film and detector electrodes
    G4Region* thinRegion = new G4Region("thinRegion");
    thinRegion->AddRootLogicalVolume(logicWindowfilm_carrier);
    thinRegion->AddRootLogicalVolume(logicWindowfilm_metalayer);
    thinRegion->AddRootLogicalVolume(logicDetElectrode);
    thinRegion->AddRootLogicalVolume(logicDetDeadlayer);

    //create a region that contains the silicon detector sesnitive volume
    G4Region* SiSensitiveVolume = new G4Region("SiSensitiveVolume");
    SiSensitiveVolume->AddRootLogicalVolume(logicDet500);
    SiSensitiveVolume->AddRootLogicalVolume(logicDet1500_1);
    SiSensitiveVolume->AddRootLogicalVolume(logicDet1500_2);
    SiSensitiveVolume->AddRootLogicalVolume(logicDet1500_3);
 
    //ste limit for particles in the thin components like the window film 
    G4double maxStep = 0.05 * um;
    G4UserLimits* fStepLimit = new G4UserLimits(maxStep);
    logicWindowfilm_carrier->SetUserLimits(fStepLimit);
    logicWindowfilm_metalayer->SetUserLimits(fStepLimit);
  
    //Detector stack surrouding tub
    G4double DetStackTub_inR = 30 * mm;
    G4double DetStackTub_outR = 40 * mm;
    G4double DetStackTub_Z = 12.50 * mm;

    G4Tubs* DetStackTub = new G4Tubs("DetStackTub", DetStackTub_inR, DetStackTub_outR, DetStackTub_Z /2.,0, 2 * PI);
    G4LogicalVolume* logicDetStackTub = new G4LogicalVolume(DetStackTub, Al6061, "logicDetStackTub");
    G4PVPlacement* physDetStackTub = new G4PVPlacement(0, G4ThreeVector(0., 0., -DetStackTub_Z/2 -plateZ/2 * mm), logicDetStackTub, "physDetStackTub", logicWorld, false, 0, true);

    //Detector stack compartment lid
    G4double DetEndlid_R = 40 * mm;
    G4double DetEndlid_Z = 10 * mm;

    G4Tubs* DetEndlid = new G4Tubs("DetEndlid", 0, DetEndlid_R, DetEndlid_Z / 2., 0, 2 * PI);
    G4LogicalVolume* logicDetEndlid = new G4LogicalVolume(DetEndlid, Al6061, "logicDetEndlid");
    G4PVPlacement* physDetEndlid = new G4PVPlacement(0, G4ThreeVector(0., 0., -DetStackTub_Z- plateZ / 2 - DetEndlid_Z/2* mm), logicDetEndlid, "physDetEndlid", logicWorld, false, 0, true);


    //vis color attributes
    
    logicWorld->SetVisAttributes(G4VisAttributes::GetInvisible());
    logicCollimatorCylinder->SetVisAttributes(G4VisAttributes::GetInvisible());
    logicLayer->SetVisAttributes(G4VisAttributes::GetInvisible());

    G4VisAttributes* src_cap = new G4VisAttributes(G4Colour(0.5, 0.5, 0.5, .1));
    src_cap->SetForceWireframe(false);
    logicSourceCap->SetVisAttributes(src_cap);

    // Housing Volume (Gray)
    G4VisAttributes* Vis_housing = new G4VisAttributes(G4Colour(0.5, 0.5, 0.5, .2));
    Vis_housing->SetForceWireframe(false);

    logicDetStackTub->SetVisAttributes(Vis_housing);
    logicWindowplate->SetVisAttributes(Vis_housing);
    logicCollimatorTub->SetVisAttributes(Vis_housing);
    logicDetEndlid->SetVisAttributes(Vis_housing);
    logicCollimatorLid->SetVisAttributes(Vis_housing);
    logicTopplate->SetVisAttributes(Vis_housing);
    logicwindowframe->SetVisAttributes(Vis_housing);
    
    // collimator baffle Volume (brown)
    G4VisAttributes* Vis_baffle = new G4VisAttributes(G4Colour(0.45, 0.25, 0.0, .2));
    Vis_baffle->SetForceWireframe(false);
    logicCollimatorBaffle->SetVisAttributes(Vis_baffle);
    logicCollimatorBaffle1st->SetVisAttributes(Vis_baffle);

    // collimator spacer Volume (White)
    G4VisAttributes* Vis_spacer = new G4VisAttributes(G4Colour(0., 0., 0., .2));
    Vis_spacer->SetForceWireframe(false);
    logicCollimatorSpacer->SetVisAttributes(Vis_spacer);

    // Silicon PCB Volume (Orange)
    G4VisAttributes* Vis_SiPCB = new G4VisAttributes(G4Colour(1., 1., 0., .2));
    Vis_SiPCB->SetForceWireframe(false);
    logicDetSupport->SetVisAttributes(Vis_SiPCB);
    
    // Silicon chip Volume (Blue)
    G4VisAttributes* Vis_chip = new G4VisAttributes(G4Colour(0., 0., 1., 1));
    Vis_chip->SetForceWireframe(false);
    logicDet500->SetVisAttributes(Vis_chip);
    logicDet1500_1->SetVisAttributes(Vis_chip);
    logicDet1500_2->SetVisAttributes(Vis_chip);
    logicDet1500_3->SetVisAttributes(Vis_chip);
    logicDetElectrode->SetVisAttributes(Vis_chip);
    logicDetDeadlayer->SetVisAttributes(Vis_chip);

    // windowfilm Volume (dark gray)
    G4VisAttributes* Vis_film = new G4VisAttributes(G4Colour(0.1, 0.1, 0.1, 0.2));
    Vis_film->SetForceWireframe(false);
    logicWindowfilm_carrier->SetVisAttributes(Vis_film);
    logicWindowfilm_metalayer->SetVisAttributes(Vis_film);
 

    return physWorld;

}

void MyDetectorConstruction::ConstructSDandField(){

    SensitiveDetector* sensDet = new SensitiveDetector("SiDet", "SiDetHitsCollection");
    G4SDManager::GetSDMpointer()->AddNewDetector(sensDet);
    logicDet500->SetSensitiveDetector(sensDet);
    logicDet1500_1->SetSensitiveDetector(sensDet);
    logicDet1500_2->SetSensitiveDetector(sensDet);
    logicDet1500_3->SetSensitiveDetector(sensDet);
    
    
}
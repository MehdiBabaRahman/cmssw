#ifndef EcalEndcapRecHitsValidation_H
#define EcalEndcapRecHitsValidation_H

/*
 * \file EcalEndcapRecHitsValidation.h
 *
 * $Date: 2006/06/29 11:07:41 $
 * \author C. Rovelli
 *
*/

#include "FWCore/Framework/interface/Frameworkfwd.h"
#include "FWCore/Framework/interface/EDAnalyzer.h"

#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/EventSetup.h"
#include "FWCore/Framework/interface/ESHandle.h"
#include "FWCore/Framework/interface/MakerMacros.h"
#include "FWCore/ParameterSet/interface/ParameterSet.h"
#include "FWCore/MessageLogger/interface/MessageLogger.h"

#include "DQMServices/Core/interface/DaqMonitorBEInterface.h"
#include "DQMServices/Daemon/interface/MonitorDaemon.h"
#include "FWCore/ServiceRegistry/interface/Service.h"

#include "DataFormats/EcalDigi/interface/EEDataFrame.h"
#include "DataFormats/EcalRecHit/interface/EcalRecHitCollections.h"
#include "DataFormats/EcalDigi/interface/EcalDigiCollections.h"

#include "CondFormats/EcalObjects/interface/EcalPedestals.h"
#include "CondFormats/DataRecord/interface/EcalPedestalsRcd.h"

#include <iostream>
#include <fstream>
#include <vector>
#include <map>

using namespace cms;
using namespace edm;
using namespace std;

class EcalEndcapRecHitsValidation: public EDAnalyzer{

public:

/// Constructor
EcalEndcapRecHitsValidation(const ParameterSet& ps);

/// Destructor
~EcalEndcapRecHitsValidation();

protected:

/// Analyze
void analyze(const Event& e, const EventSetup& c);

// BeginJob
void beginJob(const EventSetup& c);

// EndJob
void endJob(void);

private:

 bool verbose_;
 
 DaqMonitorBEInterface* dbe_;

 edm::InputTag EEdigiCollection_;
 edm::InputTag EEuncalibrechitCollection_;

 MonitorElement* meEEUncalibRecHitsOccupancyPlus_;     
 MonitorElement* meEEUncalibRecHitsOccupancyMinus_;     
 MonitorElement* meEEUncalibRecHitsAmplitude_;    
 MonitorElement* meEEUncalibRecHitsPedestal_;      
 MonitorElement* meEEUncalibRecHitsJitter_;        
 MonitorElement* meEEUncalibRecHitsChi2_;          
 MonitorElement* meEEUncalibRecHitMaxSampleRatio_; 
 MonitorElement* meEEUncalibRecHitsOccupancyPlusGt60adc_;     
 MonitorElement* meEEUncalibRecHitsOccupancyMinusGt60adc_;     
 MonitorElement* meEEUncalibRecHitsAmplitudeGt60adc_;    
 MonitorElement* meEEUncalibRecHitsPedestalGt60adc_;      
 MonitorElement* meEEUncalibRecHitsJitterGt60adc_;        
 MonitorElement* meEEUncalibRecHitsChi2Gt60adc_;          
 MonitorElement* meEEUncalibRecHitMaxSampleRatioGt60adc_; 
 MonitorElement* meEEUncalibRecHitsAmpFullMap_;
 MonitorElement* meEEUncalibRecHitsPedFullMap_;
};

#endif

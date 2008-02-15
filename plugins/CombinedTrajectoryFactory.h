#ifndef Alignment_ReferenceTrajectories_CombinedTrajectoryFactory_h
#define Alignment_ReferenceTrajectories_CombinedTrajectoryFactory_h

#include "Alignment/ReferenceTrajectories/interface/TrajectoryFactoryBase.h"

/// A factory that can combine the functionality of several 'trajectory factories'. At construction
/// time, it is given an ordered list of what kinds factories it should use. When called, all the
/// factories are called one after, until one of them gives a result.
///
/// Example: Combine TwoBodyDecayTrajectoryFactory and ReferenceTrajectoryFactory. In case the former
/// can't produce a trajectory from two given tracks, the tracks can still be used for 'ordinary'
/// reference trajectories (see also TrajectoryFactories.cff).


class CombinedTrajectoryFactory : public TrajectoryFactoryBase
{

public:

  CombinedTrajectoryFactory( const edm::ParameterSet & config );
  virtual ~CombinedTrajectoryFactory( void );

  virtual const ReferenceTrajectoryCollection trajectories( const edm::EventSetup & setup,
							    const ConstTrajTrackPairCollection & tracks ) const;

  virtual const ReferenceTrajectoryCollection trajectories( const edm::EventSetup& setup,
							    const ConstTrajTrackPairCollection& tracks,
							    const ExternalPredictionCollection& external ) const;

  virtual CombinedTrajectoryFactory* clone( void ) const { return new CombinedTrajectoryFactory( *this ); }

private:

  std::vector<TrajectoryFactoryBase*> theFactories;
};


#endif
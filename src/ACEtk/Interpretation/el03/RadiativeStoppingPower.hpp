struct RadiativeStoppingPower {
  static auto energyGrid( const Table& table ) {
    return table.data.XSS( table.data.JXS( 2 ), table.data.NXS( 3 ) )
	   | ranges::view::transform( []( const auto& entry )
	            			{ return entry * mega( electronVolt ); } );
  }

  using Energies =
    decltype( RadiativeStoppingPower::energyGrid( std::declval<const Table&>() ) );
  
  static auto bremsstrahlungCorrection( const Table& table ){  
    auto length = table.data.NXS( 3 );
    auto start  = table.data.JXS( 2 ) + 2 * length;
    return table.data.XSS( start, length );
  }

  static auto stoppingPowerGrid( const Table& table, const Energies& energies ){
      const auto atomicNumber = Z( table );

    constexpr Quantity< Mega< ElectronVolt > > massEquivalent =
      constant::electronMass * constant::lightSpeed * constant::lightSpeed;
    
    auto totalEnergy = energies
                       | ranges::view::transform( [ massEquivalent ]( const auto& entry )
		                  		  { return entry + massEquivalent; } );

    constexpr auto multiplier = constant::classicalElectronRadius
                              * constant::classicalElectronRadius
                              * constant::fineStructure ;

    auto modifier = [m=multiplier, z=atomicNumber]( const auto& tup ){
      return m * z * ( z + std::get<0>(tup) ) * std::get<1>(tup) * std::get<2>(tup);
    };

    auto length = table.data.NXS( 3 );
    auto start  = table.data.JXS( 2 ) + length;
    auto radiativeStopping = table.data.XSS( start, length );
    
    return ranges::view::zip( bremsstrahlungCorrection( table ),
			      radiativeStopping,
			      totalEnergy ) 
           | ranges::view::transform( modifier );
    }
  };    

  using StoppingPowers =
    decltype( RadiativeStoppingPower::stoppingPowerGrid
	      ( std::declval< const Table& >(),
		std::declval< const Energies& >() ) );    

public:
  Energies energies;
  StoppingPowers stoppingPowers;
    
  RadiativeStoppingPower( const Table& table ) :
    energies( energyGrid( table ) ),
    stoppingPowers( stoppingPowerGrid( table, energies ) ) {}    
    
};

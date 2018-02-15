#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "ACEtk.hpp"

using namespace njoy::ACEtk;

SCENARIO( "Constructing a CrossSection" ){
  GIVEN( "an energy grid and cross section values" ){
    std::vector< double > eGrid{1.0, 2.0, 3.0};
    std::vector< double > xsValues{2.1, 3.1, 4.1};

    WHEN( "constructing a CrossSection" ){
      interpretation::nc::CrossSection XS( eGrid, xsValues );

      THEN( "I can verify the energy grid and cross section values" ){

        bool equal = ranges::equal( 
            scaleBy( 1.0*mega( electronVolts ) )( eGrid ),
            XS.energyGrid() );
        REQUIRE( equal );

        equal = ranges::equal( scaleBy( barn )( xsValues ), XS.values() );
        REQUIRE( equal );

      }
    }
  } // GIVEN
  GIVEN( "bad values" ){
    std::vector< double > eGrid{1.0, 2.0, 3.0};
    std::vector< double > xsValues{2.1, 3.1, 4.1, 5.0};

    WHEN( "constructing a CrossSection" ){
      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( interpretation::nc::CrossSection( eGrid, xsValues ) );
      }
    }
  }
} // SCENARIO
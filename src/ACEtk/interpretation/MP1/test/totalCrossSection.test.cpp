#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "ACEtk.hpp"

using namespace njoy::ACEtk;

SCENARIO("test interpretation::MP1::totalCrossSection"){  
  auto table = Table( njoy::utility::slurpFileToMemory("1000.mp1") );
  
  GIVEN("An ACE Table for 1000.mp1"){
    
    const auto mp1   = interpretation::MP1( table );

    WHEN("querying for the total xs for order 1"){
      const auto txs = mp1.totalCrossSection(1) | ranges::to_vector;
      REQUIRE( txs.size() == 287 );
      
      auto prev = 1.0 * centi( meter ) * centi( meter );    
      for ( const auto val : txs ) {      
	REQUIRE( val <= 1e-16 * centi( meter ) * centi( meter ) );
	REQUIRE( val >= 0.0 * centi( meter ) * centi( meter ) );
	REQUIRE( prev > val );
	prev = val;
      }
      
    }

    WHEN("querying for the total xs for order 2"){
      const auto txs = mp1.totalCrossSection(2) | ranges::to_vector;
      REQUIRE( txs.size() == 287 );
      
      auto prev = 1.0 * centi( meter ) * centi( meter );    
      for ( const auto val : txs ) {      
	REQUIRE( val <= 1e-16 * centi( meter ) * centi( meter ) );
	REQUIRE( val >= 0.0 * centi( meter ) * centi( meter ) );
	REQUIRE( prev > val );
	prev = val;
      }
      
    }

    WHEN("querying for the total xs for order 4"){
      const auto txs = mp1.totalCrossSection(4) | ranges::to_vector;
      REQUIRE( txs.size() == 287 );
      
      auto prev = 1.0 * centi( meter ) * centi( meter );    
      for ( const auto val : txs ) {      
	REQUIRE( val <= 1e-16 * centi( meter ) * centi( meter ) );
	REQUIRE( val >= 0.0 * centi( meter ) * centi( meter ) );
	REQUIRE( prev > val );
	prev = val;
      }
      
    }    

    WHEN("querying for the total xs for order 8"){
      const auto txs = mp1.totalCrossSection(8) | ranges::to_vector;
      REQUIRE( txs.size() == 287 );
      
      auto prev = 1.0 * centi( meter ) * centi( meter );    
      for ( const auto val : txs ) {      
	REQUIRE( val <= 1e-16 * centi( meter ) * centi( meter ) );
	REQUIRE( val >= 0.0 * centi( meter ) * centi( meter ) );
	REQUIRE( prev > val );
	prev = val;
      }
      
    }

    WHEN("querying for the total xs for order 16"){
      const auto txs = mp1.totalCrossSection(16) | ranges::to_vector;
      REQUIRE( txs.size() == 287 );
      
      auto prev = 1.0 * centi( meter ) * centi( meter );    
      for ( const auto val : txs ) {      
	REQUIRE( val <= 1e-16 * centi( meter ) * centi( meter ) );
	REQUIRE( val >= 0.0 * centi( meter ) * centi( meter ) );
	REQUIRE( prev > val );
	prev = val;
      }
      
    }    
    
  }
}





template< >
class Interpretation< El03 >{

  const Table& table;

  static auto Z( const Table& table ){ return table.data.NXS( 2 ); }

#include "ACEtk/Interpretation/el03/RadiativeStoppingPower.hpp"

public:
  Interpretation( const Table& table ) : table( table ) {}

  auto atomicNumber() const { return Z( this->table ); }

  auto radiativeStoppingPower() const {
    return RadiativeStoppingPower( this->table );
  }
};
  

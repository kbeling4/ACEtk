template< typename Arg,
          utility::Require< true, IsPositive, Arg > = true >
static decltype( auto ) check( Arg&& arg ){
  return std::forward< Arg >( arg );
}

template< typename Arg,
          utility::Require< false, IsPositive, Arg > = true,
          utility::Require< true, IsSorted, Arg > = true >
static decltype( auto ) check( Arg&& arg ){
  if( *( arg.begin() ) < 0.0 ){
    njoy::Log::error( "range is not all positive" );
    njoy::Log::info( "Non-positive element ({}) found at index: {}",
                     *( arg.begin() ), 0 );
    throw NotPositiveException
    { "(sorted) range is not all strictly positive" };
  }
  return std::forward< Arg >( arg );
}

template< typename Arg,
          utility::Require< false, IsPositive, Arg > = true,
          utility::Require< false, IsSorted, Arg > = true,
          utility::Require< true, utility::is_range, Arg > = true >
decltype( auto ) check( Arg&& arg ){
  const auto firstNegative =
    ranges::find_if( arg, [](auto& e ){ return e < 0; } );

  if( firstNegative != arg.end() ){
    njoy::Log::error( "range is not all positive" );
    njoy::Log::info( "First negative element ({}) found at index: {}",
      *firstNegative, std::distance(  arg.begin(), firstNegative ) );
    throw NotPositiveException
    { "range is not all positive" };
  }
  return std::forward< Arg >( arg );
}

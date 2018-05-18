CoupledDensityFunctions( Table::Slice PDF, Table::Slice CDF ):
    PDF_( PDF ),
    CDF_( CDF )
{
  if( PDF_.size() != CDF_.size() ){
    njoy::Log::error( "PDF and CDF must be the same size" );
    njoy::Log::info( "PDF size: {}, CDF size: {}", 
                     PDF_.size(), CDF_.size() );
    throw std::exception();
  }
}

template< typename Range >
CoupledDensityFunctions( Range& PDF, Range& CDF ):
  CoupledDensityFunctions(
    Table::Slice{ PDF.begin(), PDF.end() },
    Table::Slice{ CDF.begin(), CDF.end() } )
{
}

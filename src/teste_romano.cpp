#define CATCH_CONFIG_MAIN   
#include "catch.hpp"
#include "romano.hpp"
 
#define SUCCESS 1
#define FAILURE 0




TEST_CASE("Teste", "teste1") {
    REQUIRE(RomanToDecimal("I") == 1);  
}
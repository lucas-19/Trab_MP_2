#define CATCH_CONFIG_MAIN   
#include "catch.hpp"
#include "romano.hpp"
#include <iostream>
 
#define FAILURE -1




TEST_CASE("Sucesso", "[sucesso]") {
    REQUIRE(RomanToDecimal("M") == 1000);
    REQUIRE(RomanToDecimal("D") == 500);
    REQUIRE(RomanToDecimal("C") == 100);
    REQUIRE(RomanToDecimal("L") == 50);
    REQUIRE(RomanToDecimal("X") == 10);
    REQUIRE(RomanToDecimal("I") == 1);


    REQUIRE(RomanToDecimal("MMM") == 3000);  
    REQUIRE(RomanToDecimal("CM") == 900);
    REQUIRE(RomanToDecimal("MCM") == 1900);  

    REQUIRE(RomanToDecimal("CD") == 400);    

    REQUIRE(RomanToDecimal("CMXC") == 990);  
    REQUIRE(RomanToDecimal("CXC") == 190);
    REQUIRE(RomanToDecimal("CCCXC") == 390);
    REQUIRE(RomanToDecimal("CDXC") == 490);
    REQUIRE(RomanToDecimal("XCIX") == 99);

    REQUIRE(RomanToDecimal("XL") == 40);
    REQUIRE(RomanToDecimal("LX") == 60); 
    REQUIRE(RomanToDecimal("XLIX") == 49);
    REQUIRE(RomanToDecimal("III") == 3);
    
}

TEST_CASE("Falha", "[falha]") {
    REQUIRE(RomanToDecimal("CCM") == FAILURE);
    REQUIRE(RomanToDecimal("CMM") == FAILURE);
    

    REQUIRE(RomanToDecimal("CCD") == FAILURE);
    REQUIRE(RomanToDecimal("DD") == FAILURE);
    REQUIRE(RomanToDecimal("LD") == FAILURE);
    REQUIRE(RomanToDecimal("XD") == FAILURE);
    REQUIRE(RomanToDecimal("VD") == FAILURE);
    REQUIRE(RomanToDecimal("ID") == FAILURE);

    
    REQUIRE(RomanToDecimal("CCCC") == FAILURE);
    REQUIRE(RomanToDecimal("XXC") == FAILURE);
    REQUIRE(RomanToDecimal("XCX") == FAILURE);
    REQUIRE(RomanToDecimal("XCC") == FAILURE);
    REQUIRE(RomanToDecimal("CCXCC") == FAILURE);
    REQUIRE(RomanToDecimal("LC") == FAILURE);
    
    REQUIRE(RomanToDecimal("XXL") == FAILURE);
    REQUIRE(RomanToDecimal("LL") == FAILURE);
    REQUIRE(RomanToDecimal("VL") == FAILURE);
    REQUIRE(RomanToDecimal("IL") == FAILURE);

    REQUIRE(RomanToDecimal("XXXX") == FAILURE);
    REQUIRE(RomanToDecimal("IIX") == FAILURE);
    REQUIRE(RomanToDecimal("VX") == FAILURE);
    REQUIRE(RomanToDecimal("VXV") == FAILURE);

    REQUIRE(RomanToDecimal("IIIV") == FAILURE);

    REQUIRE(RomanToDecimal("IIII") == FAILURE);



    REQUIRE(RomanToDecimal("IIIIIIIIIIIIIIIIIIIIIIIIIIIIIII") == FAILURE);
    REQUIRE(RomanToDecimal("MMMM") == FAILURE);
}
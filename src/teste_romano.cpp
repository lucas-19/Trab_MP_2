// Copyright 2021 Lucas Aquino Costa
#define CATCH_CONFIG_MAIN
// no trabalho nao foi pedido para implementar o teste_romano.hpp,
// entretanto o cpplint aponta o erro da falta do teste_romano.hpp
#include "catch.hpp"
#include "romano.hpp"
#include <iostream>

#define FAILURE -1




TEST_CASE("Sucesso", "[sucesso]") {
    // Teste para todos os casos sozinhos
    REQUIRE(RomanToDecimal("M") == 1000);
    REQUIRE(RomanToDecimal("D") == 500);
    REQUIRE(RomanToDecimal("C") == 100);
    REQUIRE(RomanToDecimal("L") == 50);
    REQUIRE(RomanToDecimal("X") == 10);
    REQUIRE(RomanToDecimal("I") == 1);

    // Alguns testes usando o M
    REQUIRE(RomanToDecimal("MMM") == 3000);
    REQUIRE(RomanToDecimal("CM") == 900);
    REQUIRE(RomanToDecimal("MCM") == 1900);
    // Teste usando para tirar 10 de 500
    REQUIRE(RomanToDecimal("CD") == 400);
    // Testes com C
    REQUIRE(RomanToDecimal("CMXC") == 990);
    REQUIRE(RomanToDecimal("CXC") == 190);
    REQUIRE(RomanToDecimal("CCCXC") == 390);
    REQUIRE(RomanToDecimal("CDXC") == 490);
    REQUIRE(RomanToDecimal("XCIX") == 99);
    // Testes com X
    REQUIRE(RomanToDecimal("XL") == 40);
    REQUIRE(RomanToDecimal("LX") == 60);
    REQUIRE(RomanToDecimal("XLIX") == 49);
    // Teste com I
    REQUIRE(RomanToDecimal("III") == 3);
}

TEST_CASE("Falha", "[falha]") {
    // Testes de falha com M
    REQUIRE(RomanToDecimal("CCM") == FAILURE);
    REQUIRE(RomanToDecimal("CMM") == FAILURE);
    // Testes de falha com D
    REQUIRE(RomanToDecimal("CCD") == FAILURE);
    REQUIRE(RomanToDecimal("DD") == FAILURE);
    REQUIRE(RomanToDecimal("LD") == FAILURE);
    REQUIRE(RomanToDecimal("XD") == FAILURE);
    REQUIRE(RomanToDecimal("VD") == FAILURE);
    REQUIRE(RomanToDecimal("ID") == FAILURE);
    // Testes de falha com C
    REQUIRE(RomanToDecimal("CCCC") == FAILURE);
    REQUIRE(RomanToDecimal("XXC") == FAILURE);
    REQUIRE(RomanToDecimal("XCX") == FAILURE);
    REQUIRE(RomanToDecimal("XCC") == FAILURE);
    REQUIRE(RomanToDecimal("CCXCC") == FAILURE);
    REQUIRE(RomanToDecimal("LC") == FAILURE);
    // Testes de falhas com L
    REQUIRE(RomanToDecimal("XXL") == FAILURE);
    REQUIRE(RomanToDecimal("LL") == FAILURE);
    REQUIRE(RomanToDecimal("VL") == FAILURE);
    REQUIRE(RomanToDecimal("IL") == FAILURE);
    // Testes de falha com X
    REQUIRE(RomanToDecimal("XXXX") == FAILURE);
    REQUIRE(RomanToDecimal("IIX") == FAILURE);
    REQUIRE(RomanToDecimal("VX") == FAILURE);
    REQUIRE(RomanToDecimal("VXV") == FAILURE);
    // Testes de falha com V
    REQUIRE(RomanToDecimal("IIIV") == FAILURE);
    // Testes de falha com I
    REQUIRE(RomanToDecimal("IIII") == FAILURE);


    // Testes com mais de 30 caracteres e mais de 3000
    REQUIRE(RomanToDecimal("IIIIIIIIIIIIIIIIIIIIIIIIIIIIIII") == FAILURE);
    REQUIRE(RomanToDecimal("MMMM") == FAILURE);
}

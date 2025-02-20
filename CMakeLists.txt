cmake_minimum_required(VERSION 3.30)
project(bertiniNonTiTemo)

set(CMAKE_CXX_STANDARD 20)

add_executable(bertiniNonTiTemo main.cpp
        Transazione.cpp
        Transazione.h
        observer.cpp
        observer.h
        SaldoObserver.cpp
        SaldoObserver.h
        ContoCorrente.cpp
        ContoCorrente.h
        Interagisci.cpp
        Interagisci.h)

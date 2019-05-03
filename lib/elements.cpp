/**
 * MuDirac - A muonic atom Dirac equation solver
 * by Simone Sturniolo (2019)
 * 
 * elements.cpp
 * 
 * Atomic mass and spin data extracted by AME2016 and NUBASE databases.
 * Access functions.
 * 
 * References:
 * 
 * AME2016 (masses):
 *      "The Ame2016 atomic mass evaluation (I)"   by W.J.Huang, G.Audi, M.Wang, F.G.Kondev, S.Naimi and X.Xu
 *         Chinese Physics C41 030002, March 2017.
 *      "The Ame2016 atomic mass evaluation (II)"  by M.Wang, G.Audi, F.G.Kondev, W.J.Huang, S.Naimi and X.Xu
 *         Chinese Physics C41 030003, March 2017.
 * 
 * NUBASE (spins):
 *      "The NUBASE2016 evaluation of nuclear properties"   by G.Audi, F.G.Kondev, M.Wang, W.J.Huang and S.Naimi
 *         Chinese Physics C41 030001, March 2017.
 * 
 * @author Simone Sturniolo
 * @version 0.1 04/02/2019
 */

#include "elements.hpp"

double getIsotopeMass(string symbol, int isotope)
{
    if (isotope == -1)
    {
        isotope = getElementMainIsotope(symbol);
    }
    try
    {
        return atomic_data.at(symbol).isotopes.at(isotope).mass;
    }
    catch (out_of_range e)
    {
        throw invalid_argument("Isotope/element does not exist");
    }
}

double getIsotopeMass(int Z, int isotope)
{
    string symbol = getElementSymbol(Z);
    return getIsotopeMass(symbol, isotope);
}

double getIsotopeSpin(string symbol, int isotope)
{
    if (isotope == -1)
    {
        isotope = getElementMainIsotope(symbol);
    }
    try
    {
        return atomic_data.at(symbol).isotopes.at(isotope).spin;
    }
    catch (out_of_range e)
    {
        throw invalid_argument("Isotope/element does not exist");
    }
}

double getIsotopeSpin(int Z, int isotope)
{
    string symbol = getElementSymbol(Z);
    return getIsotopeSpin(symbol, isotope);
}

int getElementZ(string symbol)
{
    try
    {
        return atomic_data.at(symbol).Z;
    }
    catch (out_of_range e)
    {
        throw invalid_argument("Element does not exist");
    }
}

string getElementSymbol(int Z)
{
    try
    {
        return atomic_Z_lookup.at(Z);
    }
    catch (out_of_range e)
    {
        throw invalid_argument("Element does not exist");
    }
}

int getElementMainIsotope(string symbol)
{
    try
    {
        return atomic_data.at(symbol).maxA;
    }
    catch (out_of_range e)
    {
        throw invalid_argument("Element does not exist");
    }
}

int getElementMainIsotope(int Z)
{
    string symbol = getElementSymbol(Z);
    return getElementMainIsotope(symbol);
}
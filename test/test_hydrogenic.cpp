/**
 * Test functions for hydrogenic.cpp (known solutions for hydrogen-like atoms)
 */

#include <iostream>
#include <vector>
#include "../src/hydrogenic.hpp"
#include "../src/utils.hpp"

using namespace std;

int main() {

    double mu;
    double A = 55.85;
    int Z = 1;
    vector<double> rvec, R;
    vector<vector<double>> GF;

    mu = effectiveMass(Physical::m_e, Physical::m_p*A);

    cout << "Hydrogen atom energy: " << hydrogenicSchroEnergy(Z, mu, 1) << "\n";
    cout << "Hydrogen atom Dirac energy: " << hydrogenicDiracEnergy(Z, mu, 1, -1, true) << "\n";

    mu = effectiveMass(Physical::m_mu, Physical::m_p*A);

    cout << "Hydrogen muonic atom energy: " << hydrogenicSchroEnergy(Z, mu, 1) << "\n";
    cout << "Hydrogen muonic atom Dirac energy: " << hydrogenicDiracEnergy(Z, mu, 1, -1, true)<< "\n";

    // Try a line
    cout << "Ka: " << (hydrogenicDiracEnergy(Z, mu, 2, 1) - hydrogenicDiracEnergy(Z, mu, 1, -1))/Physical::eV*1e-3 << " keV\n";

    for (double r = 1e-5; r < 10.0; r *= 1.02) {
        rvec.push_back(r);
        // gf = hydrogenicDiracWavefunction(r);
        // cout << r << " " << hydrogenicSchroWavefunction(r) << " " << gf[0] << " " << gf[1] << "\n";
    }

    mu = effectiveMass(Physical::m_e, Physical::m_p*A);
    R = hydrogenicSchroWavefunction(rvec, Z, mu, 2);
    GF = hydrogenicDiracWavefunction(rvec, Z, mu, 2);

    for (int i = 0; i < GF.size(); ++i) {
        cout << rvec[i] << " " << R[i] << " " << GF[i][0] << " " << GF[i][1] << "\n";
    }
}
#include <cmath>
#include <iostream>
#include <iomanip>

#define _USE_MATH_DEFINES

using namespace std;


int main(void)
{

    // V = cm³, X por m², Y por m²

    float v; 
    float x; // x, y;
    float y;

    std::cout<<"Capacidade (cm³): ";
    std::cin >>v;
    std::cout<<"Custo da Base (R$/m²): ";
    std::cin>>x;
    std::cout<<"Custo Lateral (R$/m²): ";
    std::cin>>y;

    // conversão de cm³ para m³
    float v2 = v/1000000;


    // Cálculo do raio

    float r;
    r = pow((v2 / (2 * M_PI)),(0.33));
    std::cout  <<"Raio da Base : "<< setprecision(2) << r << endl;


    // Cálculo da altura da Lata
    float h;
    h = v2 / (M_PI * pow(r,2));
    std::cout << "Altura da Lata: " << setprecision(3) << h <<endl;


     // Cálculo da area da base
    float area_B;
    area_B =  M_PI * pow(r,2);
 
    
    // Calculo da area Lateral
    float area_L;
    area_L = 2 * M_PI * r * h;
    

    float Atotal;
 
    Atotal = area_L + area_B * 2;
    std::cout << "Área total: " << setprecision(4) <<  Atotal <<endl;

    float Ctotal;

    Ctotal = (area_L * y  + 2 * x * area_B);

    std::cout << "Custo Total: R$ " << setprecision(4)<<Ctotal  <<endl;
     /*printf =  raio da base, altura da lata, área total da superfície da lata e custo total do
    material usado em cada lata, que minimizam o custo da lata */

    return -1;
}
#include <iostream>
using namespace std;

/*forward declaration
*/
float porcentajeVariacion(float, float);
float promedioVariaciones(float*, int);
float pronosticoVentas(int,const float);
int pedirNumeroPeriodos();
int pedirDatosSalida();
void llenarArregloEntrada(float *, const int);
void llenarArregloVariacion(float* , float*, const int);
void llenarPronostico(float*, const float, const int, const int);
void mostrarDatos(float*, const int, const int);
/*
*/

int main()
{
    const int periodosIniciales = pedirNumeroPeriodos();
    const int periodosSolicitados = pedirDatosSalida();
    const int periodosTotales = periodosIniciales + periodosSolicitados;
    float* arregloPeriodos = new float[periodosTotales];
    float* arregloVariacion = new float[periodosTotales];
    llenarArregloEntrada(arregloPeriodos, periodosIniciales);
    llenarArregloVariacion(arregloPeriodos, arregloVariacion, periodosIniciales);
    const float promedioVariacion = promedioVariaciones(arregloVariacion, periodosIniciales);
    delete[] arregloVariacion;
    llenarPronostico(arregloPeriodos, promedioVariacion, periodosIniciales, periodosTotales);
    mostrarDatos(arregloPeriodos, periodosIniciales, periodosTotales);
    delete[] arregloPeriodos;
}

float porcentajeVariacion(float ventasPeriodoActual, float ventasPeriodoAnterior) {
    return (ventasPeriodoActual - ventasPeriodoAnterior) / ventasPeriodoAnterior;
}// OK

float promedioVariaciones(float* array, const int periodos) {
    float sumatoria = 0, promedio = 0;
    for (int i = 1; i < periodos; i++)
    {
        sumatoria += array[i];
    }
    promedio = sumatoria / (periodos - 1);
    return promedio;
}//OK

float pronosticoVentas(float periodoActual,const float promedioValoraciones) {
    return (periodoActual + (promedioValoraciones * periodoActual));
}//OK

int pedirNumeroPeriodos() {
    int numeroPeriodos = 0;
    std::cout << "Ingrese numero de periodos a Digitar" << std::endl;
    std::cin >> numeroPeriodos;

    return numeroPeriodos;
}//OK

int pedirDatosSalida() {
    int datosSalida = 0;
    std::cout << "Digite numero de periodos a pronosticar" << std::endl;
    std::cin >> datosSalida;
    return datosSalida;
}//OK

void llenarArregloEntrada(float* arregloPeriodos, const int periodos) {
    
    for (int i = 0; i < periodos; i++)
    {
        std::cout << "Digite ventas del periodo " << i+1 << std::endl;
        std::cin >> arregloPeriodos[i];
    }
}//OK

void llenarArregloVariacion(float* arrayEntrada, float* arrayVariacion, const int periodos) {
    for (int i = 0; i < periodos; i++) {
        if (i != 0) {
            arrayVariacion[i] = porcentajeVariacion(arrayEntrada[i], arrayEntrada[i - 1]);
        }
        else {
            arrayVariacion[i] = arrayEntrada[i];
        }
    }
}//OK

void llenarPronostico(float* arrayEntrada, const float variacion, 
    const int totalDatosEntrada, const int totalDatosSalida) {
        for (int i = totalDatosEntrada; i < totalDatosSalida; i++)
        {
            arrayEntrada[i] = pronosticoVentas(arrayEntrada[i - 1], variacion);
        }
}

void mostrarDatos(float* array, const int totalDatosEntrada, const int totalDatosSalida) {
    for (int i = totalDatosEntrada; i < totalDatosSalida; i++)
    {
        std::cout << "El pronostico de ventas para el periodo " << i+1 << " Es " << array[i] << std::endl;
    }
}
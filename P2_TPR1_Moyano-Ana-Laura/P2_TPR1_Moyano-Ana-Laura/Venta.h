#pragma once
#include "Cliente.h"
#include "Mercaderia.h"

using namespace System;
using namespace System::Collections::Generic;

[Serializable]
ref class Venta
{
public:
	Venta(Cliente^, int);
	Cliente^ cliente;
	int noVenta;
	double montoTotal;
	double descuento;
	double tasaDolar;
	List<Mercaderia^>^ mercaderias;
};

#pragma once
#include "Proveedor.h"
using namespace System;

[Serializable]
ref class Mercaderia
{
public:
	Mercaderia();
	~Mercaderia();
	String^ descripcion;
	double precio;
	Proveedor^ ultimoProveedor;
};


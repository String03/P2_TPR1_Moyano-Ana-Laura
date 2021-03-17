#pragma once

using namespace System;

[Serializable]
ref class MetodoPago
{
public:
	MetodoPago();
	virtual String^ DescripcionMetodo() = 0;
	virtual bool RealizarCobro(double montoPesos) = 0;
};


#pragma once
#include "MetodoPago.h"

using namespace System;

[Serializable]
ref class TarjetaDebito :
	public MetodoPago
{
public:
	TarjetaDebito(System::String^ numeroTarjeta, double balance);
	bool RealizarCobro(double montoPesos) override;
	virtual String^ DescripcionMetodo() override;
private:
	System::String^ numeroTarjeta;
	double balance;
};


#pragma once
#include "MetodoPago.h"

using namespace System;

[Serializable]
ref class TarjetaCredito :
	public MetodoPago
{
public:
	TarjetaCredito(System::String^ numeroTarjeta, double balance);
	bool RealizarCobro(double montoPesos) override;
	String^ DescripcionMetodo() override;
private:
	System::String^ numeroTarjeta;
	double balance;
};


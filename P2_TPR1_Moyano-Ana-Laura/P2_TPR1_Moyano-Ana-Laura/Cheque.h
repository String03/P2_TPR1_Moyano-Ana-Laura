#pragma once
#include "MetodoPago.h"

using namespace System;

[Serializable]
ref class Cheque :
	public MetodoPago
{
public:
	Cheque();
	System::String^ beneficiario;
	double monto;
	bool RealizarCobro(double montoPesos) override;
	virtual String^ DescripcionMetodo() override;
};

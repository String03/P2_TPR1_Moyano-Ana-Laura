#include "stdafx.h"
#include "TarjetaCredito.h"

TarjetaCredito::TarjetaCredito(System::String^ numeroTarjeta, double balance) 
{
	this->numeroTarjeta = numeroTarjeta;
	this->balance = balance;
}

bool TarjetaCredito::RealizarCobro(double montoPesos)
{
	if (this->balance < montoPesos)
		return false;
	else 
	{
		this->balance -= montoPesos;
		return true;
	}
}

String^ TarjetaCredito::DescripcionMetodo()
{
	return "Tarjeta Crédito";
}

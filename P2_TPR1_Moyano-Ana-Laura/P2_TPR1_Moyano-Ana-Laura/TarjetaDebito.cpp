#include "stdafx.h"
#include "TarjetaDebito.h"

TarjetaDebito::TarjetaDebito(System::String^ numeroTarjeta, double balance)
{
	this->numeroTarjeta = numeroTarjeta;
	this->balance = balance;
}

bool TarjetaDebito::RealizarCobro(double montoPesos)
{
	if (this->balance < montoPesos)
		return false;
	else 
	{
		this->balance -= montoPesos;
		return true;
	}
}

String^ TarjetaDebito::DescripcionMetodo()
{
	return "Tarjeta Débito";
}

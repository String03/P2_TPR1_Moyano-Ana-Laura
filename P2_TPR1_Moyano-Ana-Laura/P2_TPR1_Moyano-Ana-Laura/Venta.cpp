#include "Venta.h"
#include "Mercaderia.h"

using namespace System::Collections::Generic;

Venta::Venta(Cliente^ cliente, int noVenta) 
{
	this->cliente = cliente;
	this->noVenta = noVenta;
	this->mercaderias = gcnew List<Mercaderia^>();
}

#include "stdafx.h"
#include "Persona.h"
#include "Cliente.h"
#include "TarjetaDebito.h"
#include "TarjetaCredito.h"
#include "Cheque.h"
#include "MetodoPago.h"
#include "DataManager.h"

#define ARCHIVO_CLIENTE "clientes.dat"
#define ARCHIVO_PROVEEDOR "proveedores.dat"
#define ARCHIVO_MERCADERIA "mercaderia.dat"
#define ARCHIVO_VENTA "ventas.dat"

using namespace System;
using namespace System::IO;
using namespace System::Runtime::Serialization;
using namespace System::Runtime::Serialization::Formatters::Binary;

int enseniarMenu();
Cliente^ CrearCliente();
Proveedor^ CrearProveedor();
MetodoPago^ CrearMetodoPago(List<Cliente^>^);
Mercaderia^ CrearMercaderia(List<Proveedor^>^);
Venta^ CrearVenta(List<Mercaderia^>^, List<Cliente^>^, int);

int main(array<System::String ^> ^args)
{
	
	int seleccion = -1;

	List <Cliente^>^clientes;
	List <Proveedor^>^proveedores;
	List <Mercaderia^>^mercaderias;
	List <Venta^>^ventas;

	while (seleccion)
	{
		seleccion =enseniarMenu();
		
		switch (seleccion)
		{
		case 1:
			clientes = LeerClientes(ARCHIVO_CLIENTE);
			if(clientes->Count > 0)
			{
				Console::WriteLine("Clientes inscriptos: ");
				for each (Cliente^ c in clientes)
				{
					Console::WriteLine("{0}",c->nombre);
				}
			}
			clientes->Add(CrearCliente());
			GuardarClientes(ARCHIVO_CLIENTE,clientes);
			break;
		case 2:
			
			proveedores = LeerProveedores(ARCHIVO_PROVEEDOR);
			if (proveedores->Count > 0)
			{
				Console::WriteLine("Clientes inscriptos: ");
				for each (Proveedor^ c in proveedores)
				{
					Console::WriteLine("{0}", c->nombre);
				}
			}
			proveedores->Add(CrearProveedor());
			GuardarProveedores(ARCHIVO_PROVEEDOR, proveedores);


			break;
		case 3:
			mercaderias = LeerMercaderias(ARCHIVO_MERCADERIA);
			if (mercaderias->Count > 0)
			{
				Console::WriteLine("Mercadería registrada: ");
				for each (Mercaderia^ m in mercaderias)
				{
					Console::WriteLine("{0} del proveedor {1} ", m->descripcion,m->ultimoProveedor == nullptr?"(sin proveedor )": m->ultimoProveedor->nombre);
				}
			}
			proveedores = LeerProveedores(ARCHIVO_PROVEEDOR);
			if (proveedores->Count == 0) {
				Console::WriteLine("No existen proveedores");
				break;
			}
			mercaderias->Add(CrearMercaderia(proveedores));
			GuardarMercaderias(ARCHIVO_MERCADERIA, mercaderias);
			break;
		case 4:
			mercaderias = LeerMercaderias(ARCHIVO_MERCADERIA);
			clientes = LeerClientes(ARCHIVO_CLIENTE);
			ventas = LeerVentas(ARCHIVO_VENTA);
			ventas->Add(CrearVenta(mercaderias, clientes, ventas->Count + 1));
			GuardarVentas(ARCHIVO_VENTA, ventas);
			break;
		case 5:
			clientes = LeerClientes(ARCHIVO_CLIENTE);
			CrearMetodoPago(clientes);
			GuardarClientes(ARCHIVO_CLIENTE, clientes);
			break;
		default:
			break;
		}
	}
	Console::ReadKey();
    return 0;
}

int enseniarMenu() {
	Console::WriteLine("Elija una opción disponible en el sistema ");
	Console::WriteLine("Seleccionar opción:\n1-Agregar Cliente\n2-Agregar Proveedor\n3-Añadir Mercaderia\n4-Realizar venta\n5-Agregarle método de pago a un cliente");
	return Convert::ToInt32(Console::ReadLine());
}

Cliente^ CrearCliente() {
	Console::Write("Introduzca el nombre del cliente: ");
	System::String^ Nombre = Console::ReadLine();
	Console::Write("Introduzca el apellido del cliente: ");
	System::String^ Apellido = Console::ReadLine();
	Console::Write("Introduzca el documento de identidad del cliente: ");
	System::String^ Documento = Console::ReadLine();
	Cliente^ cliente = gcnew Cliente(Nombre,Apellido,Documento);
	return cliente;
}

Proveedor^ CrearProveedor() {
	Console::Write("Introduzca el nombre del proveedor: ");
	System::String^ Nombre = Console::ReadLine();
	Console::Write("Introduzca el apellido del proveedor: ");
	System::String^ Apellido = Console::ReadLine();
	Console::Write("Introduzca el documento de identidad del proveedor: ");
	System::String^ Documento = Console::ReadLine();
	Proveedor^ proveedor = gcnew Proveedor(Nombre, Apellido, Documento);
	return proveedor;
}

Mercaderia^ CrearMercaderia(List<Proveedor^>^ proveedores) {
	Console::Write("Introduzca la descripción de la mercadería: ");
	System::String^ Descripcion = Console::ReadLine();
	Console::Write("Introduzca el precio en dólares: ");
	double precio = Convert::ToDouble(Console::ReadLine());
	Console::WriteLine("Introduzca el ultimo proveedor: ");
	Mercaderia^ mercaderia = gcnew Mercaderia();
	try {
		int i = 1;
		for each (Proveedor^ p in proveedores)
		{
			Console::WriteLine("{0}.{1}", i,p->nombre);
			i++;
		}
		mercaderia->ultimoProveedor = proveedores->ToArray()[Convert::ToInt32(Console::ReadLine()) - 1];
	}
	catch(Exception ^e){
		Console::WriteLine("Error eligiendo proveedor, poniendo null");
		mercaderia->ultimoProveedor = nullptr;
	}
	mercaderia->descripcion = Descripcion;
	mercaderia->precio = precio;
	return mercaderia;
}

MetodoPago^ CrearMetodoPago(List<Cliente^>^ clientes)
{
	Console::WriteLine("Elija un cliente: ");
	Cliente^ cliente;
	try {
		int i = 1;
		for each (Cliente^ c in clientes)
		{
			Console::WriteLine("{0}.{1}", i, c->nombre);
			i++;
		}
		cliente = clientes->ToArray()[Convert::ToInt32(Console::ReadLine()) - 1];
	}
	catch (Exception ^e) {
		Console::WriteLine("Error eligiendo cliente, poniendo null");
		cliente = nullptr;
	}
	if (cliente == nullptr)
	{
		Console::WriteLine(" No se puede trabajar con cliente null");
		return nullptr;
	}
	Console::WriteLine("Elija el método a crear: \n 1.Tarjeta de crédito\n 2.Tarjeta de débito\n 3. Cheque\n");
	int seleccion = Convert::ToInt32(Console::ReadLine());
	switch (seleccion)
	{
	case 1:
		try
		{
			Console::Write("Inserte no. de tarjeta: ");
			String^ noTarjeta = Console::ReadLine();
			Console::Write("Inserte balance: ");
			double balance = Convert::ToDouble(Console::ReadLine());
			TarjetaCredito^ tarjetadecredito = gcnew TarjetaCredito(noTarjeta, balance);
			cliente->metodosPagos->Add(tarjetadecredito);
			Console::WriteLine("Método de pago agregado.");
		}
		catch (Exception^ e)
		{
			Console::WriteLine("Error, no se pudo agregar este método de pago.");
		}
		break;
	case 2:
		try
		{
			Console::Write("Inserte no. de tarjeta: ");
			String^ noTarjeta = Console::ReadLine();
			Console::Write("Inserte balance: ");
			double balance = Convert::ToDouble(Console::ReadLine());
			TarjetaDebito ^ tarjetadedebito = gcnew TarjetaDebito(noTarjeta, balance);
			cliente->metodosPagos->Add(tarjetadedebito);
			Console::WriteLine("Método de pago agregado.");
		}
		catch (Exception^ e)
		{
			Console::WriteLine("Error, no se pudo agregar este método de pago.");
		}
		break;
	case 3:
		try
		{
			Cheque^ cheque = gcnew Cheque();
			Console::Write("Inserte beneficiario: ");
			cheque->beneficiario = Console::ReadLine();
			Console::Write("Inserte monto: ");
			cheque->monto = Convert::ToDouble(Console::ReadLine());
			Console::WriteLine("Método de pago agregado.");
		}
		catch (Exception^ e)
		{
			Console::WriteLine("Error, no se pudo agregar este método de pago.");
		}
		break;

	default:
		Console::WriteLine("No se pudo agregar el método de pago.");
		break;
	}
}

Venta^ CrearVenta(List<Mercaderia^>^ mercaderias, List<Cliente^>^ clientes, int noVenta)
{
	int i = 1;
	Mercaderia^ mercaderiaSeleccionada;
	Cliente^ clienteSeleccionado;
	int seleccionMercaderia = -1;

	Console::WriteLine("Elija un cliente al cual venderle: ");
	try
	{
		for each (Cliente^ var in clientes)
		{
			Console::WriteLine("{0}.{1} {2}", i, var->nombre, var->apellido);
			i++;
		}
		clienteSeleccionado = clientes->ToArray()[Convert::ToInt32(Console::ReadLine()) - 1];
	}
	catch (Exception^ e)
	{
		Console::WriteLine("Error eligiendo cliente a venderle");
		return nullptr;
	}

	if (clienteSeleccionado->metodosPagos->Count == 0) 
	{
		Console::WriteLine("El cliente no tiene métodos de pago");
		return nullptr;
	}

	Venta^ venta = gcnew Venta(clienteSeleccionado, noVenta);

	Console::WriteLine("Seleccione la mercadería a vender: ");
	while (seleccionMercaderia) 
	{
		i = 1;
		try
		{
			Console::WriteLine("0.Fin mercaderias");
			for each (Mercaderia^ var in mercaderias)
			{
				Console::WriteLine("{0}.{1}\tPrecio: {2}", i, var->descripcion, var->precio);
				i++;
			}
			seleccionMercaderia = Convert::ToInt32(Console::ReadLine());
			if (seleccionMercaderia == 0)
				break;
			mercaderiaSeleccionada = mercaderias->ToArray()[seleccionMercaderia - 1];
			venta->mercaderias->Add(mercaderiaSeleccionada);
		}
		catch (Exception^ e)
		{
			Console::WriteLine("Error eligiendo mercaderia a vender");
			return nullptr;
		}
	}

	if (venta->mercaderias->Count == 0)
	{
		Console::WriteLine("No hay ventas seleccionadas");
		return nullptr;
	}

	try
	{
		double montoTotal = 0.0;
		for each(Mercaderia^ m in venta->mercaderias) 
		{
			montoTotal += m->precio;
		}
		venta->montoTotal = montoTotal;
		Console::Write("Elija el descuento total (de 0 a 1): ");
		venta->descuento = Convert::ToDouble(Console::ReadLine());
		Console::Write("Elija la tasa del dolar: ");
		venta->tasaDolar = Convert::ToDouble(Console::ReadLine());
		venta->montoTotal = montoTotal * venta->tasaDolar * venta->descuento;
		Console::WriteLine("Elija el método de pago: ");
		i = 1;
		for each(MetodoPago^ metodoPago in clienteSeleccionado->metodosPagos)
		{
			Console::WriteLine("{0}.{1}", i, metodoPago->DescripcionMetodo());
			i++;
		}
		MetodoPago^ metodoPagoSeleccionado = clienteSeleccionado->metodosPagos->ToArray()[Convert::ToInt32(Console::ReadLine()) - 1];
		if(metodoPagoSeleccionado->RealizarCobro(venta->montoTotal))
			return venta;
		else
		{
			Console::WriteLine("El cliente no cuenta con balance con este método");
			return nullptr;
		}
	}
	catch (Exception^ e)
	{
		Console::WriteLine("Error creando la venta");
		return nullptr;
	}
}

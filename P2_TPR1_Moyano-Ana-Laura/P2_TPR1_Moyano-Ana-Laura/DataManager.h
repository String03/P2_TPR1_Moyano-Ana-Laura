#pragma once
#include "Cliente.h"
#include "Proveedor.h"
#include "Mercaderia.h"
#include "Venta.h"

using namespace System::Collections::Generic;

void GuardarClientes(System::String^, List<Cliente^>^);
void GuardarProveedores(System::String^, List<Proveedor^>^);
void GuardarMercaderias(System::String^, List<Mercaderia^>^);
void GuardarVentas(System::String^, List<Venta^>^);

List<Cliente^>^ LeerClientes(System::String^);
List<Proveedor^>^ LeerProveedores(System::String^);
List<Mercaderia^>^ LeerMercaderias(System::String^);
List<Venta^>^ LeerVentas(System::String^);

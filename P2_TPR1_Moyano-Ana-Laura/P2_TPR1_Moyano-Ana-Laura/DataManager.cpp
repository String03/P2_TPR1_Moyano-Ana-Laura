#include "DataManager.h"

using namespace System::IO;
using namespace System::Runtime::Serialization;
using namespace System::Runtime::Serialization::Formatters::Binary;

void GuardarClientes(System::String^ nombreArchivo, List<Cliente^>^ clientes) 
{
	FileStream ^ stream;
	try
	{
	    stream = gcnew FileStream(nombreArchivo, FileMode::OpenOrCreate, FileAccess::ReadWrite);
		BinaryFormatter^ formatter = gcnew BinaryFormatter();
		formatter->Serialize(stream, clientes);
		stream->Close();
	}
	catch (Exception^ e) 
	{
		Console::WriteLine(e);
		stream->Close();
	}
}

void GuardarProveedores(System::String^ nombreArchivo, List<Proveedor^>^ proveedores) 
{
	FileStream ^ stream;
	try
	{
		stream = gcnew FileStream(nombreArchivo, FileMode::OpenOrCreate, FileAccess::ReadWrite);
		BinaryFormatter^ formatter = gcnew BinaryFormatter();
		formatter->Serialize(stream, proveedores);
		stream->Close();
	}
	catch (Exception^ e) 
	{
		Console::WriteLine(e);
		stream->Close();
	}
}

void GuardarMercaderias(System::String^ nombreArchivo, List<Mercaderia^>^ mercaderias) 
{
	FileStream ^ stream;
	try
	{
		stream = gcnew FileStream(nombreArchivo, FileMode::OpenOrCreate, FileAccess::ReadWrite);
		BinaryFormatter^ formatter = gcnew BinaryFormatter();
		formatter->Serialize(stream, mercaderias);
		stream->Close();
	}
	catch (Exception^ e) 
	{
		Console::WriteLine(e);
		stream->Close();
	}
}

void GuardarVentas(System::String^ nombreArchivo, List<Venta^>^ ventas) 
{
	FileStream ^ stream;
	try
	{
		stream = gcnew FileStream(nombreArchivo, FileMode::OpenOrCreate, FileAccess::ReadWrite);
		BinaryFormatter^ formatter = gcnew BinaryFormatter();
		formatter->Serialize(stream, ventas);
		stream->Close();
	}
	catch (Exception^ e) 
	{
		Console::WriteLine(e);
		stream->Close();
	}
}


List<Cliente^>^ LeerClientes(System::String^ nombreArchivo) 
{
	FileStream ^ stream;
	try
	{
		stream = gcnew FileStream(nombreArchivo, FileMode::OpenOrCreate, FileAccess::Read);
		BinaryFormatter^ formatter = gcnew BinaryFormatter();
		List<Cliente^> ^ clientes = (List<Cliente^>^)formatter->Deserialize(stream);
		stream->Close();
		return clientes;
		
		
	}
	catch (Exception^ e) 
	{
		stream->Close();
		return gcnew List<Cliente^>();
		
	}
}

List<Proveedor^>^ LeerProveedores(System::String^ nombreArchivo)
{
	FileStream ^ stream;
	try
	{
	
		 stream = gcnew FileStream(nombreArchivo, FileMode::OpenOrCreate, FileAccess::Read);
		BinaryFormatter^ formatter = gcnew BinaryFormatter();
		List<Proveedor^> ^ proveedores = (List<Proveedor^>^)formatter->Deserialize(stream);
		stream->Close();
		return proveedores;
	}
	catch (Exception^ e) 
	{
		stream->Close();
		return gcnew List<Proveedor^>();
	}
}

List<Mercaderia^>^ LeerMercaderias(System::String^ nombreArchivo) 
{
	FileStream ^ stream;
	try
	{
		stream = gcnew FileStream(nombreArchivo, FileMode::OpenOrCreate, FileAccess::Read);
		BinaryFormatter^ formatter = gcnew BinaryFormatter();
		List<Mercaderia^> ^ mercaderias = (List<Mercaderia^>^)formatter->Deserialize(stream);
		stream->Close();
		return mercaderias;
	}
	catch (Exception^ e) 
	{
		stream->Close();
		return gcnew List<Mercaderia^>();
	}
}

List<Venta^>^ LeerVentas(System::String^ nombreArchivo) 
{
	FileStream ^ stream;
	try
	{
		stream = gcnew FileStream(nombreArchivo, FileMode::OpenOrCreate, FileAccess::Read);
		BinaryFormatter^ formatter = gcnew BinaryFormatter();
		List<Venta^> ^ ventas = (List<Venta^>^)formatter->Deserialize(stream);
		stream->Close();
		return ventas;
	}
	catch (Exception^ e) 
	{
		stream->Close();
		return gcnew List<Venta^>();
	}
}

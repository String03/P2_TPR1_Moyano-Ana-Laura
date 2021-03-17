#pragma once
#include "Persona.h"
#include "MetodoPago.h"

using namespace System;
using namespace System::Collections::Generic;

[Serializable]
ref class Cliente :
	public Persona
{
public:
	Cliente(System::String^ nombre, System::String^ apellido, System::String^ identidad) : 
		Persona(nombre, apellido, identidad) {
		this->metodosPagos = gcnew List<MetodoPago^>();
	}
	List<MetodoPago^>^ metodosPagos;
};

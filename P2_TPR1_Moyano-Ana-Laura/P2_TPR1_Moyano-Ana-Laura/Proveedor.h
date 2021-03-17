#pragma once
#include "Persona.h"

using namespace System;

[Serializable]
ref class Proveedor :
	public Persona
{
public:
	Proveedor(System::String^ nombre, System::String^ apellido, System::String^ identidad) 
		: Persona(nombre, apellido, identidad) {}
};

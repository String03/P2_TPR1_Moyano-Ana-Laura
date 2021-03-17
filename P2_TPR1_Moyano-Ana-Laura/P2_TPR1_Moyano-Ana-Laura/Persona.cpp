#include "stdafx.h"
#include "Persona.h"

Persona::Persona(System::String^ nombre, System::String^ apellido, System::String^ identidad)
{
	this->nombre = nombre;
	this->apellido = apellido;
	this->identidad = identidad;
}

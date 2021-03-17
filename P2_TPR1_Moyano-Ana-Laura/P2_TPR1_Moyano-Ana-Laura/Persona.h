#pragma once

using namespace System;

[Serializable]
ref class Persona
{
public:
	Persona(System::String^, System::String^, System::String^);
	System::String^ nombre;
	System::String^ apellido;
	System::String^ identidad;
};

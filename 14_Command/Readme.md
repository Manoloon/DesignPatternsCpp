## Command
#	Motivation
* en c++ cada statement que se llama luego se destruye, no hay manera 
de revertirlo, por esto es necesario tener algun manager que se ocupe
de llevar un listado de estos statements 
Ejemplo clasico : Redo/Undo commands
# Statements as Commands 
Un comando es un objeto que guarda toda informacion relacionada con 
la accion a ser tomada 
Un comando es un pedido de permiso para ejecutar cierta accion o cambio
	ejemplo = set your health to 4 ;
	El comando no obtiene devuelve ningun resultado, solo muta un dato.
	Esta es la principal diferencia con una query.
	Donde query no muta dato sino que lo obtiene.

#Exercise
	*Command Coding Exercise

	Implement the Account::process()  
	function to process different account commands. The rules are obvious:

    success  indicates whether the operation was successful
    You can only withdraw money if you have enough in your account
	

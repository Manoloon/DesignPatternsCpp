## Proxy

&nbsp;	# Proxy Types: 

&nbsp;	\* Property Proxy :

&nbsp;	Template<typename T> struct Property

&nbsp;	{

&nbsp;		T value;

&nbsp;		Property(T value)

&nbsp;		{

&nbsp;			\*this = value;

&nbsp;		}

&nbsp;		T operator=(T new\_value)

&nbsp;		{

&nbsp;			return value = new\_value;

&nbsp;		}

&nbsp;	};



# 


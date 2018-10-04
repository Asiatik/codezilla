
## Singleton

Singleton Pattern is one of the Gangs of Four Design patterns 
and comes in the Creational Design Pattern category. 
From the definition, it seems to be a very simple design pattern but when it comes to implementation, 
it comes with a lot of implementation concerns. 

*Singleton pattern restricts the instantiation of a class and ensures that only one instance of the class exists in the java virtual machine.*
> The singleton class must provide a global access point to get the instance of the class.

> Singleton pattern is used for logging, drivers objects, caching and thread pool.

> Singleton design pattern is also used in other design patterns like Abstract Factory, Builder, Prototype, Facade etc.

> Singleton design pattern is used in core java classes also, for example java.lang.Runtime, java.awt.Desktop.

*To implement Singleton pattern, we have different approaches but all of them have following common concepts.*
>Private constructor to restrict instantiation of the class from other classes.

>Private static variable of the same class that is the only instance of the class.

>Public static method that returns the instance of the class, this is the global access point for outer world to get the instance of the singleton class.

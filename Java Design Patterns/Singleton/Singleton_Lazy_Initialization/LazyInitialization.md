# Singleton Pattern
In software engineering, the singleton pattern is a software design pattern that restricts the instantiation of a class to one object. This is useful when exactly one object is needed to coordinate actions across the system. The concept is sometimes generalized to systems that operate more efficiently when only one object exists, or that restrict the instantiation to a certain number of objects. The term comes from the mathematical concept of a singleton.

To implement it in java, the constructor has to be private and only called indirectly with a getInstance() method, that controls the number of constructor calls (one or zero). The getInstance() function should return the single static declared instance.

An efficient way to implement it, is using the Lazy initialization.

## Lazy initialization
A singleton implementation may use lazy initialization, where the instance is created when the static method is **first invoked**.
The constructor is called only when the getInstance() method is called for the first time. After the instance is created, next time the getInstance() method is called, it will return the same instance.

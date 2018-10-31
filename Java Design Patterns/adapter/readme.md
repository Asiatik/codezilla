##Adapter Pattern
An Adapter pattern acts as a connector between two incompatible interfaces that otherwise cannot be connected directly. An Adapter wraps an existing class with a new interface so that it becomes compatible with client’s interface.

The main motive behind using this pattern is to convert an existing interface into another interface that client expects. It’s usually implemented once the application is designed.

###When to Use Adapter Pattern
 - When an outside component provides captivating functionality that we’d like to reuse, but it’s incompatible with our current application. A suitable Adapter can be developed to make them compatible with each other
 - When our application is not compatible with the interface that our client is expecting
 - When we want to reuse legacy code in our application without making any modification in the original code
 
 [Source: https://www.baeldung.com/java-structural-design-patterns#adapter]
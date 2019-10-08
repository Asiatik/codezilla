## Observer pattern

The Observer design pattern is one of the Gangs of Four Design patterns in which an object, called the subject, maintains a list of its dependents, called observers, and notifies them automatically of any state changes, usually by calling one of their methods.
It is mainly used to implement distributed event handling systems, in "event driven" software.

*The Observer pattern solves the following problems:
> A one-to-many dependency between objects should be defined without making the objects tightly coupled.
> It should be ensured that when one object changes state an open-ended number of dependent objects are updated automatically.
> It should be possible that one object can notify an open-ended number of other objects.
<h3>Intent</h3>
<p>Create new objects by copying a prototypical instance<p>
</br>
<h3>Applicability</h3>
Use the prototype pattern when a system should be independent of how its products are created.
<ul>
<li>Allows adding of any subclass instance of a known superclass at run-time</li>
<li>To avoid building a class hierarchy of factories that parallels the class hierarchy</li>
<li>Reduces need of creating subclasses</li>
<li>When there are numerous class that you might want to only use if needed at run-time</li>
</ul>
</br>
<h3>Approach/Implementation</h3>
<ul>
<li>Using a prototype Manager; When the numer of prototypes in a system isn't fixed consider having a prototype factory.</li>
<li>Implementing the Clone operation; The hardest part of this pattern is implementing the clone operator correctly
<p>We're going to create an interface Animal from which concrete classes Sheep and Animal will inherit. A class named cloneFactory will contain many different clone methods; however, in our case we only have the clone method that pertains to Animal types. NOTE: Prototype and Abstract Factory are very similar; however, Prototype avois unneccesary "new" calls for the objects that are cloned are not created. take this into consideration when choosing between using either design pattern. </p>

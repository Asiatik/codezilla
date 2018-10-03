# Observer pattern
The observer pattern defines a one-to-many relationship between objects so when one object changes his state all of the other objects are notified and updated based on that specific change. 

## Usage scenario
> Let's say we are building a soccer app that notifies all the users about the pieces of information such as the current score, a number of the corner shots, yellow/red cards etc. Suppose we have made three element objects for displaying the { current score }, { corner shots }, and { cards }. 
And we created an object called { match data } which has all the data (corner shots, cards etc.) and whenever data changes the display elements are notified with new data and they displayed the latest data.
In this case, we could use Observer pattern to update our display elements whenever the data inside { match data } changes. 

## Implementation in javascript 

very simplified version of the pattern

```javascript
class MatchData {
    constructor(){
        this.observers = []
        this.cards = 0
        this.cornerShots = 0
    }

    incrementCards() {
       this.cards++
       this.notify()
    }

    incrementCornerShots() {
       this.conerShots++
       this.notify()
    }

    notify(){
        this.observers.forEach(observer => observer.update(this))
    }

    observe(observer) {
        this.observers.push(observer)
    }
}

class Cards {
    constructor() {
        this.cardDisplay = document.getElementById('p')
    }
    
    update(observable){
        this.cardDisplay.innerText = observable.cards
    }
}

class CornerShots {
    ...
}

class App {
    // match is the subject that will be observed
    const match = new MatchData()
    // cards and corners are observers
    const cards = new Cards()
    const corners = new CornerShots()

    // register observers
    match.observe(word)
    match.observe(list)


    // some app logic 
    match.incrementCards()
    match.incrementCornerShots()
    match.incrementCards()

}

```
class WordObservable {
    constructor(){
        this.observers = []
        this.word = ''
    }

    generateRandomWord(length = 10) {
       this.word = [...Array(length)].map( i => (Math.floor(Math.random() * 31)).toString(31)).join('')
       this.notify()
    }

    notify(){
        this.observers.forEach(observer => observer.update(this))
    }

    observe(observer) {
        this.observers.push(observer)
    }

}
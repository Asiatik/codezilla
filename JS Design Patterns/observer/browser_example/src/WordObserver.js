class WordObserver {
    constructor() {
        this.wordElement = document.querySelector('.currentWordContainer h1')
        this.wordCount = 0
        this.wordCountElement = document.querySelector('.currentWordContainer p span')
    }

    addNewWord(word) {
        this.wordCount++
        this.wordElement.innerText = `the word ${word} is generated`
        this.wordCountElement.innerText = this.wordCount
    }
    
    update(observable){
        const { word } = observable
        this.addNewWord(word)
    }
}
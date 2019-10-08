class ListObserver {
    constructor() {
        this.list = document.querySelector('.right')
    }

    addWordToList(word) {
        const wordElement = document.createElement('p')
        wordElement.appendChild(document.createTextNode(`generated word ${word}`))
        this.list.appendChild(wordElement)
        this.scrollListToBottom(wordElement.clientHeight)
    }
    
    scrollListToBottom(elementHeight) {
        const container = document.querySelector('.right')
        container.scrollTop = container.scrollHeight + elementHeight
    }

    update(observable){
        const { word } = observable
        this.addWordToList(word)
    }
}
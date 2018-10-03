const wordService = new WordObservable()
const word = new WordObserver()
const list = new ListObserver()

wordService.observe(word)
wordService.observe(list)

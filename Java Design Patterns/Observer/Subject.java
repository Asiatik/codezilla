package Observer;

/**
 *
 * @author Juan Manuel Gutierrez
 * @param <E> generic parameter used to represent a message object
 */
public interface Subject<E> {
    
    //methods to add or remove observers
    public void addObserver(Observer obj);
    public void removeObserver(Observer obj);

    //method to notify observers
    public void notifyObservers();

    //method to get updates from subject
    public E getUpdate(Observer obj);
}

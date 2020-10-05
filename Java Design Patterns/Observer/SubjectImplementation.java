package Observer;

import java.util.ArrayList;

/**
 *
 * @author Juan Manuel Gutierrez
 * @param <E> generic parameter used to represent a message object
 */
public class SubjectImplementation<E> implements Subject {

    //Variables
    private ArrayList<Observer> observer_list;
    private E message;
    private boolean changed;
        
    /**
     * Constructor
     */
    public SubjectImplementation() {
        this.observer_list = new ArrayList<>();
        this.message = null;
        this.changed = false; 
    }
    
    @Override
    public void addObserver(Observer observer) {
        if (observer != null && !observer_list.contains(observer)) {
            observer_list.add(observer);
        }
    }

    @Override
    public void removeObserver(Observer observer) {
        if (observer != null && observer_list.contains(observer)) {
            observer_list.remove(observer);
        }
    }

    @Override
    public void notifyObservers() {
        if (!changed) {
            return;
        } else {
            this.changed = false;
        }
        
        for (Observer actual_observer : observer_list) {
            actual_observer.update();
        }
    }

    @Override
    public E getUpdate(Observer obj) {
        return this.message;
    }
    
    /**
     * Method to notify observers about a new change
     * @param change_message 
     */
    public void setChange(E change_message){
        System.out.println("New change notification: "+change_message.toString());
        this.changed = true;
        this.message = change_message;
        notifyObservers();
    }
}
